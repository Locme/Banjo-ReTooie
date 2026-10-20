#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800FCB54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FCB54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FCB58: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FCB5C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800FCB60: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800FCB64: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800FCB68: jal         0x800FB5F8
    // 0x800FCB6C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800FB5F8(rdram, ctx);
        goto after_0;
    // 0x800FCB6C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800FCB70: addiu       $t6, $v0, 0x3C
    ctx->r14 = ADD32(ctx->r2, 0X3C);
    // 0x800FCB74: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800FCB78: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800FCB7C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800FCB80: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800FCB84: jal         0x800FCB9C
    // 0x800FCB88: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800FCB9C(rdram, ctx);
        goto after_1;
    // 0x800FCB88: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_1:
    // 0x800FCB8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FCB90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800FCB94: jr          $ra
    // 0x800FCB98: nop

    return;
    // 0x800FCB98: nop

;}
RECOMP_FUNC void func_80800074_bsbanshack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800074: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800078: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080007C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800080: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800084: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800088: jal         0x8009EF10
    // 0x8080008C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    bastick_getZone(rdram, ctx);
        goto after_0;
    // 0x8080008C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    after_0:
    // 0x80800090: blez        $v0, L_8080009C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800094: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080009C;
    }
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800098: addiu       $s1, $zero, 0x16D
    ctx->r17 = ADD32(0, 0X16D);
L_8080009C:
    // 0x8080009C: jal         0x80091A58
    // 0x808000A0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_1;
    // 0x808000A0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_1:
    // 0x808000A4: beq         $v0, $zero, L_808000B0
    if (ctx->r2 == 0) {
        // 0x808000A8: nop
    
            goto L_808000B0;
    }
    // 0x808000A8: nop

    // 0x808000AC: addiu       $s1, $zero, 0x16E
    ctx->r17 = ADD32(0, 0X16E);
L_808000B0:
    // 0x808000B0: jal         0x8008E148
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E148(rdram, ctx);
        goto after_2;
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808000B8: beq         $v0, $zero, L_808000C4
    if (ctx->r2 == 0) {
        // 0x808000BC: nop
    
            goto L_808000C4;
    }
    // 0x808000BC: nop

    // 0x808000C0: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_808000C4:
    // 0x808000C4: jal         0x8008E260
    // 0x808000C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E260(rdram, ctx);
        goto after_3;
    // 0x808000C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808000CC: beq         $v0, $zero, L_808000D8
    if (ctx->r2 == 0) {
        // 0x808000D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000D8;
    }
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D4: addiu       $s1, $zero, 0x3D
    ctx->r17 = ADD32(0, 0X3D);
L_808000D8:
    // 0x808000D8: jal         0x80091A30
    // 0x808000DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_released(rdram, ctx);
        goto after_4;
    // 0x808000DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x808000E0: beq         $v0, $zero, L_808000EC
    if (ctx->r2 == 0) {
        // 0x808000E4: lw          $s0, 0x14($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X14);
            goto L_808000EC;
    }
    // 0x808000E4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808000E8: addiu       $s1, $zero, 0x16B
    ctx->r17 = ADD32(0, 0X16B);
L_808000EC:
    // 0x808000EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000F0: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x808000F4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808000F8: jr          $ra
    // 0x808000FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808000FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80800800_chdippy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800800: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800804: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800808: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8080080C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800810: jal         0x80101F24
    // 0x80800814: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    func_80101F24(rdram, ctx);
        goto after_0;
    // 0x80800814: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    after_0:
    // 0x80800818: jal         0x8001211C
    // 0x8080081C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    func_8001211C(rdram, ctx);
        goto after_1;
    // 0x8080081C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80800820: addiu       $s1, $sp, 0x34
    ctx->r17 = ADD32(ctx->r29, 0X34);
    // 0x80800824: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800828: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080082C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80800830: jal         0x8008A0E8
    // 0x80800834: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _subaddieskeleton_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800834: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_2:
    // 0x80800838: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1284, 0X14A0) << 16);
    // 0x8080083C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1284, 0X1688) << 16);
    // 0x80800840: addiu       $a3, $a3, 0x1688
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1284, 0X1688));
    // 0x80800844: addiu       $a2, $a2, 0x14A0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1284, 0X14A0));
    // 0x80800848: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080084C: jal         0x80089D28
    // 0x80800850: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80800850: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80800854: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1284, 0X1480) << 16);
    // 0x80800858: lui         $a3, 0x3EDC
    ctx->r7 = S32(0X3EDC << 16);
    // 0x8080085C: ori         $a3, $a3, 0x28F6
    ctx->r7 = ctx->r7 | 0X28F6;
    // 0x80800860: addiu       $a2, $a2, 0x1480
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1284, 0X1480));
    // 0x80800864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800868: jal         0x80089D20
    // 0x8080086C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x8080086C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x80800870: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1284, 0X164C) << 16);
    // 0x80800874: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1284, 0X1698) << 16);
    // 0x80800878: addiu       $a3, $a3, 0x1698
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1284, 0X1698));
    // 0x8080087C: addiu       $a2, $a2, 0x164C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1284, 0X164C));
    // 0x80800880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800884: jal         0x80089D28
    // 0x80800888: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x80800888: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x8080088C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1284, 0X165C) << 16);
    // 0x80800890: lui         $a3, 0x3F66
    ctx->r7 = S32(0X3F66 << 16);
    // 0x80800894: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80800898: addiu       $a2, $a2, 0x165C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1284, 0X165C));
    // 0x8080089C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008A0: jal         0x80089D20
    // 0x808008A4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x808008A4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x808008A8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1284, 0X166C) << 16);
    // 0x808008AC: lui         $a3, 0x3F1C
    ctx->r7 = S32(0X3F1C << 16);
    // 0x808008B0: ori         $a3, $a3, 0x28F6
    ctx->r7 = ctx->r7 | 0X28F6;
    // 0x808008B4: addiu       $a2, $a2, 0x166C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1284, 0X166C));
    // 0x808008B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008BC: jal         0x80089D20
    // 0x808008C0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_7;
    // 0x808008C0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x808008C4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1284, 0X1450) << 16);
    // 0x808008C8: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808008CC: lwc1        $f4, 0x1450($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1284, 0X1450));
    // 0x808008D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1284, 0X1454) << 16);
    // 0x808008D4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x808008D8: nop

    // 0x808008DC: bc1fl       L_80800938
    if (!c1cs) {
        // 0x808008E0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800938;
    }
    goto skip_0;
    // 0x808008E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808008E4: lwc1        $f6, 0x1454($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1284, 0X1454));
    // 0x808008E8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x808008EC: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x808008F0: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x808008F4: bc1fl       L_80800938
    if (!c1cs) {
        // 0x808008F8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800938;
    }
    goto skip_1;
    // 0x808008F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x808008FC: bne         $t7, $zero, L_80800934
    if (ctx->r15 != 0) {
        // 0x80800900: addiu       $a1, $zero, 0x4
        ctx->r5 = ADD32(0, 0X4);
            goto L_80800934;
    }
    // 0x80800900: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800904: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800908: jal         0x8008A0E0
    // 0x8080090C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x8080090C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_8:
    // 0x80800910: beq         $v0, $zero, L_80800934
    if (ctx->r2 == 0) {
        // 0x80800914: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800934;
    }
    // 0x80800914: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800918: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1284, 0X1620) << 16);
    // 0x8080091C: addiu       $t8, $t8, 0x1620
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1284, 0X1620));
    // 0x80800920: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800924: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800928: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080092C: jal         0x800BBCB8
    // 0x80800930: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_9;
    // 0x80800930: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_9:
L_80800934:
    // 0x80800934: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800938:
    // 0x80800938: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8080093C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800940: jr          $ra
    // 0x80800944: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80800944: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80801948_changlerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801948: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080194C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801950: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80801954: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801958: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080195C: jal         0x80100094
    // 0x80801960: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801960: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801964: jal         0x800D8FF8
    // 0x80801968: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80801968: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    after_1:
    // 0x8080196C: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80801970: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801974: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80801978: lwc1        $f14, 0x98($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X98);
    // 0x8080197C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80801980: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80801984: jal         0x800F15F8
    // 0x80801988: nop

    func_800F15F8(rdram, ctx);
        goto after_2;
    // 0x80801988: nop

    after_2:
    // 0x8080198C: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80801990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801994: jal         0x8010B990
    // 0x80801998: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_8010B990(rdram, ctx);
        goto after_3;
    // 0x80801998: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_3:
    // 0x8080199C: lh          $t6, 0x90($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X90);
    // 0x808019A0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808019A4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x808019A8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x808019AC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x808019B0: addu        $a1, $s1, $t7
    ctx->r5 = ADD32(ctx->r17, ctx->r15);
    // 0x808019B4: jal         0x800EEB40
    // 0x808019B8: addiu       $a1, $a1, 0xA4
    ctx->r5 = ADD32(ctx->r5, 0XA4);
    func_800EEB40(rdram, ctx);
        goto after_4;
    // 0x808019B8: addiu       $a1, $a1, 0xA4
    ctx->r5 = ADD32(ctx->r5, 0XA4);
    after_4:
    // 0x808019BC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1332, 0X2D5C) << 16);
    // 0x808019C0: lwc1        $f8, 0x2D5C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1332, 0X2D5C));
    // 0x808019C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808019C8: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x808019CC: nop

    // 0x808019D0: bc1f        L_808019FC
    if (!c1cs) {
        // 0x808019D4: nop
    
            goto L_808019FC;
    }
    // 0x808019D4: nop

    // 0x808019D8: lbu         $t8, 0x12F($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X12F);
    // 0x808019DC: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x808019E0: beq         $t8, $zero, L_808019F4
    if (ctx->r24 == 0) {
        // 0x808019E4: nop
    
            goto L_808019F4;
    }
    // 0x808019E4: nop

    // 0x808019E8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808019EC: sb          $zero, 0x12F($s1)
    MEM_B(0X12F, ctx->r17) = 0;
    // 0x808019F0: swc1        $f10, 0x98($s1)
    MEM_W(0X98, ctx->r17) = ctx->f10.u32l;
L_808019F4:
    // 0x808019F4: b           L_808019FC
    // 0x808019F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808019FC;
    // 0x808019F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808019FC:
    // 0x808019FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801A00: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801A04: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801A08: jr          $ra
    // 0x80801A0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80801A0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80801550_bskazfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801550: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801554: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801558: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080155C: jal         0x8008CABC
    // 0x80801560: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80801560: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801564: lui         $a1, 0x3EBB
    ctx->r5 = S32(0X3EBB << 16);
    // 0x80801568: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080156C: ori         $a1, $a1, 0x573F
    ctx->r5 = ctx->r5 | 0X573F;
    // 0x80801570: jal         0x8008B348
    // 0x80801574: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_isAt(rdram, ctx);
        goto after_1;
    // 0x80801574: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80801578: beq         $v0, $zero, L_808015A4
    if (ctx->r2 == 0) {
        // 0x8080157C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808015A4;
    }
    // 0x8080157C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801580: addiu       $a1, $zero, 0x417
    ctx->r5 = ADD32(0, 0X417);
    // 0x80801584: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801588: jal         0x8009DF18
    // 0x8080158C: addiu       $a3, $zero, 0x36B0
    ctx->r7 = ADD32(0, 0X36B0);
    func_8009DF18(rdram, ctx);
        goto after_2;
    // 0x8080158C: addiu       $a3, $zero, 0x36B0
    ctx->r7 = ADD32(0, 0X36B0);
    after_2:
    // 0x80801590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801594: addiu       $a1, $zero, 0x4454
    ctx->r5 = ADD32(0, 0X4454);
    // 0x80801598: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080159C: jal         0x8009DF18
    // 0x808015A0: addiu       $a3, $zero, 0x6D60
    ctx->r7 = ADD32(0, 0X6D60);
    func_8009DF18(rdram, ctx);
        goto after_3;
    // 0x808015A0: addiu       $a3, $zero, 0x6D60
    ctx->r7 = ADD32(0, 0X6D60);
    after_3:
L_808015A4:
    // 0x808015A4: lui         $a1, 0x3F2F
    ctx->r5 = S32(0X3F2F << 16);
    // 0x808015A8: ori         $a1, $a1, 0xAACE
    ctx->r5 = ctx->r5 | 0XAACE;
    // 0x808015AC: jal         0x8008B348
    // 0x808015B0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_4;
    // 0x808015B0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x808015B4: beq         $v0, $zero, L_808015E4
    if (ctx->r2 == 0) {
        // 0x808015B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808015E4;
    }
    // 0x808015B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015BC: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x808015C0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808015C4: addiu       $a1, $zero, 0x417
    ctx->r5 = ADD32(0, 0X417);
    // 0x808015C8: jal         0x8009DF18
    // 0x808015CC: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    func_8009DF18(rdram, ctx);
        goto after_5;
    // 0x808015CC: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    after_5:
    // 0x808015D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015D4: addiu       $a1, $zero, 0x4454
    ctx->r5 = ADD32(0, 0X4454);
    // 0x808015D8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808015DC: jal         0x8009DF18
    // 0x808015E0: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    func_8009DF18(rdram, ctx);
        goto after_6;
    // 0x808015E0: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    after_6:
L_808015E4:
    // 0x808015E4: lui         $a1, 0x3F6B
    ctx->r5 = S32(0X3F6B << 16);
    // 0x808015E8: ori         $a1, $a1, 0x851F
    ctx->r5 = ctx->r5 | 0X851F;
    // 0x808015EC: jal         0x8008B348
    // 0x808015F0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_7;
    // 0x808015F0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_7:
    // 0x808015F4: beq         $v0, $zero, L_80801604
    if (ctx->r2 == 0) {
        // 0x808015F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801604;
    }
    // 0x808015F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015FC: jal         0x8009B9B0
    // 0x80801600: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_8;
    // 0x80801600: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_8:
L_80801604:
    // 0x80801604: jal         0x8008B2B4
    // 0x80801608: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_getAnimTimer(rdram, ctx);
        goto after_9;
    // 0x80801608: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_9:
    // 0x8080160C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(236, 0X1C04) << 16);
    // 0x80801610: lwc1        $f4, 0x1C04($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(236, 0X1C04));
    // 0x80801614: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80801618: nop

    // 0x8080161C: bc1fl       L_80801630
    if (!c1cs) {
        // 0x80801620: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801630;
    }
    goto skip_0;
    // 0x80801620: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80801624: jal         0x80084A10
    // 0x80801628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badust_entrypoint_9(rdram, ctx);
        goto after_10;
    // 0x80801628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8080162C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801630:
    // 0x80801630: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801634: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801638: jr          $ra
    // 0x8080163C: nop

    return;
    // 0x8080163C: nop

;}
RECOMP_FUNC void func_800A5790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5790: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A5794: lw          $t6, -0x6AC0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6AC0);
    // 0x800A5798: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A579C: sll         $t8, $a0, 1
    ctx->r24 = S32(ctx->r4 << 1);
    // 0x800A57A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A57A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A57A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800A57AC: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800A57B0: jal         0x8001B798
    // 0x800A57B4: lh          $a0, 0x1E($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X1E);
    func_8001B798(rdram, ctx);
        goto after_0;
    // 0x800A57B4: lh          $a0, 0x1E($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X1E);
    after_0:
    // 0x800A57B8: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800A57BC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800A57C0: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800A57C4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800A57C8: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800A57CC: lw          $t3, -0x6AE4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X6AE4);
    // 0x800A57D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A57D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A57D8: multu       $t0, $t3
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A57DC: mflo        $t4
    ctx->r12 = lo;
    // 0x800A57E0: addu        $v1, $v0, $t4
    ctx->r3 = ADD32(ctx->r2, ctx->r12);
    // 0x800A57E4: jr          $ra
    // 0x800A57E8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800A57E8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void _badialog_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800847C8: syscall     121
    recomp_syscall_handler(rdram, ctx, 0x800847C8);
    return;
    // 0x800847CC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8080000C_chmrsboggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800018: addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    // 0x8080001C: jal         0x800DA980
    // 0x80800020: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DA980(rdram, ctx);
        goto after_0;
    // 0x80800020: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x80800024: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800028: bnel        $v0, $at, L_80800068
    if (ctx->r2 != ctx->r1) {
        // 0x8080002C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800068;
    }
    goto skip_0;
    // 0x8080002C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x80800030: jal         0x800DA298
    // 0x80800034: addiu       $a0, $zero, 0x1CD
    ctx->r4 = ADD32(0, 0X1CD);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800034: addiu       $a0, $zero, 0x1CD
    ctx->r4 = ADD32(0, 0X1CD);
    after_1:
    // 0x80800038: beq         $v0, $zero, L_80800050
    if (ctx->r2 == 0) {
        // 0x8080003C: nop
    
            goto L_80800050;
    }
    // 0x8080003C: nop

    // 0x80800040: jal         0x800FFAB0
    // 0x80800044: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x80800044: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800048: b           L_8080007C
    // 0x8080004C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080007C;
    // 0x8080004C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800050:
    // 0x80800050: jal         0x800DA524
    // 0x80800054: addiu       $a0, $zero, 0x8B
    ctx->r4 = ADD32(0, 0X8B);
    func_800DA524(rdram, ctx);
        goto after_3;
    // 0x80800054: addiu       $a0, $zero, 0x8B
    ctx->r4 = ADD32(0, 0X8B);
    after_3:
    // 0x80800058: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080005C: jal         0x80102424
    // 0x80800060: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_4;
    // 0x80800060: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_4:
    // 0x80800064: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80800068:
    // 0x80800068: jal         0x80105A9C
    // 0x8080006C: lui         $a1, 0x43AF
    ctx->r5 = S32(0X43AF << 16);
    func_80105A9C(rdram, ctx);
        goto after_5;
    // 0x8080006C: lui         $a1, 0x43AF
    ctx->r5 = S32(0X43AF << 16);
    after_5:
    // 0x80800070: jal         0x80105BAC
    // 0x80800074: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80105BAC(rdram, ctx);
        goto after_6;
    // 0x80800074: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_6:
    // 0x80800078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080007C:
    // 0x8080007C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800080: jr          $ra
    // 0x80800084: nop

    return;
    // 0x80800084: nop

;}
RECOMP_FUNC void _chbaddiesetup_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086D38: syscall     449
    recomp_syscall_handler(rdram, ctx, 0x80086D38);
    return;
    // 0x80086D3C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800AE8A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE8A8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800AE8AC: sw          $ra, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r31;
    // 0x800AE8B0: lh          $t9, 0x4($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X4);
    // 0x800AE8B4: lw          $s0, 0x0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X0);
    // 0x800AE8B8: addiu       $s1, $a1, 0x8
    ctx->r17 = ADD32(ctx->r5, 0X8);
    // 0x800AE8BC: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x800AE8C0: addiu       $t7, $zero, 0x0
    ctx->r15 = ADD32(0, 0X0);
    // 0x800AE8C4: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
L_800AE8C8:
    // 0x800AE8C8: lh          $t0, 0xE($s1)
    ctx->r8 = MEM_H(ctx->r17, 0XE);
    // 0x800AE8CC: beql        $t7, $t0, L_800AE934
    if (ctx->r15 == ctx->r8) {
        // 0x800AE8D0: lhu         $t2, 0xC($s1)
        ctx->r10 = MEM_HU(ctx->r17, 0XC);
            goto L_800AE934;
    }
    goto skip_0;
    // 0x800AE8D0: lhu         $t2, 0xC($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0XC);
    skip_0:
    // 0x800AE8D4: or          $t7, $t0, $zero
    ctx->r15 = ctx->r8 | 0;
    // 0x800AE8D8: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800AE8DC: bnel        $t0, $zero, L_800AE910
    if (ctx->r8 != 0) {
        // 0x800AE8E0: sll         $t0, $t7, 6
        ctx->r8 = S32(ctx->r15 << 6);
            goto L_800AE910;
    }
    goto skip_1;
    // 0x800AE8E0: sll         $t0, $t7, 6
    ctx->r8 = S32(ctx->r15 << 6);
    skip_1:
    // 0x800AE8E4: lui         $t0, 0x3F80
    ctx->r8 = S32(0X3F80 << 16);
    // 0x800AE8E8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AE8EC: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x800AE8F0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800AE8F4: mtc1        $t0, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r8;
    // 0x800AE8F8: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800AE8FC: mtc1        $t0, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r8;
    // 0x800AE900: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x800AE904: b           L_800AE934
    // 0x800AE908: lhu         $t2, 0xC($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0XC);
        goto L_800AE934;
    // 0x800AE908: lhu         $t2, 0xC($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0XC);
    // 0x800AE90C: sll         $t0, $t7, 6
    ctx->r8 = S32(ctx->r15 << 6);
L_800AE910:
    // 0x800AE910: addu        $t0, $t0, $a2
    ctx->r8 = ADD32(ctx->r8, ctx->r6);
    // 0x800AE914: lwc1        $f0, 0x0($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800AE918: lwc1        $f1, 0x4($t0)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r8, 0X4);
    // 0x800AE91C: lwc1        $f2, 0x8($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X8);
    // 0x800AE920: lwc1        $f3, 0xC($t0)
    ctx->f_odd[(3 - 1) * 2] = MEM_W(ctx->r8, 0XC);
    // 0x800AE924: lwc1        $f4, 0x10($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X10);
    // 0x800AE928: lwc1        $f5, 0x14($t0)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r8, 0X14);
    // 0x800AE92C: lwc1        $f6, 0x18($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X18);
    // 0x800AE930: lhu         $t2, 0xC($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0XC);
L_800AE934:
    // 0x800AE934: sll         $t0, $t2, 5
    ctx->r8 = S32(ctx->r10 << 5);
    // 0x800AE938: sll         $t1, $t2, 3
    ctx->r9 = S32(ctx->r10 << 3);
    // 0x800AE93C: addu        $t0, $t0, $t1
    ctx->r8 = ADD32(ctx->r8, ctx->r9);
    // 0x800AE940: addu        $v0, $s0, $t0
    ctx->r2 = ADD32(ctx->r16, ctx->r8);
    // 0x800AE944: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800AE948: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x800AE94C: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x800AE950: beq         $a3, $zero, L_800AE96C
    if (ctx->r7 == 0) {
        // 0x800AE954: lw          $t3, 0xC($v0)
        ctx->r11 = MEM_W(ctx->r2, 0XC);
            goto L_800AE96C;
    }
    // 0x800AE954: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x800AE958: lbu         $t4, 0x8($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X8);
    // 0x800AE95C: beql        $t4, $zero, L_800AE970
    if (ctx->r12 == 0) {
        // 0x800AE960: lui         $t4, 0xFF80
        ctx->r12 = S32(0XFF80 << 16);
            goto L_800AE970;
    }
    goto skip_2;
    // 0x800AE960: lui         $t4, 0xFF80
    ctx->r12 = S32(0XFF80 << 16);
    skip_2:
    // 0x800AE964: jal         0x800AEDA0
    // 0x800AE968: nop

    func_800AEDA0(rdram, ctx);
        goto after_0;
    // 0x800AE968: nop

    after_0:
L_800AE96C:
    // 0x800AE96C: lui         $t4, 0xFF80
    ctx->r12 = S32(0XFF80 << 16);
L_800AE970:
    // 0x800AE970: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800AE974: or          $t4, $t4, $t2
    ctx->r12 = ctx->r12 | ctx->r10;
    // 0x800AE978: or          $t4, $t4, $t1
    ctx->r12 = ctx->r12 | ctx->r9;
    // 0x800AE97C: or          $t4, $t4, $t0
    ctx->r12 = ctx->r12 | ctx->r8;
    // 0x800AE980: beql        $t4, $zero, L_800AEA2C
    if (ctx->r12 == 0) {
        // 0x800AE984: lwc1        $f11, 0x10($v0)
        ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r2, 0X10);
            goto L_800AEA2C;
    }
    goto skip_3;
    // 0x800AE984: lwc1        $f11, 0x10($v0)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r2, 0X10);
    skip_3:
    // 0x800AE988: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x800AE98C: mtc1        $t2, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r10;
    // 0x800AE990: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x800AE994: mul.s       $f14, $f0, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800AE998: mtc1        $t0, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r8;
    // 0x800AE99C: mul.s       $f15, $f1, $f9
    CHECK_FR(ctx, 15);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 9);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f9.fl); 
    ctx->f15.fl = MUL_S(ctx->f1.fl, ctx->f9.fl);
    // 0x800AE9A0: nop

    // 0x800AE9A4: mul.s       $f16, $f2, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x800AE9A8: nop

    // 0x800AE9AC: mul.s       $f17, $f3, $f7
    CHECK_FR(ctx, 17);
    CHECK_FR(ctx, 3);
    CHECK_FR(ctx, 7);
    NAN_CHECK(ctx->f3.fl); NAN_CHECK(ctx->f7.fl); 
    ctx->f17.fl = MUL_S(ctx->f3.fl, ctx->f7.fl);
    // 0x800AE9B0: add.s       $f18, $f14, $f15
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 15);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f15.fl); 
    ctx->f18.fl = ctx->f14.fl + ctx->f15.fl;
    // 0x800AE9B4: mul.s       $f14, $f0, $f9
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 9);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f9.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f9.fl);
    // 0x800AE9B8: sub.s       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x800AE9BC: mul.s       $f15, $f1, $f10
    CHECK_FR(ctx, 15);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f15.fl = MUL_S(ctx->f1.fl, ctx->f10.fl);
    // 0x800AE9C0: add.s       $f18, $f18, $f17
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 17);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f17.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f17.fl;
    // 0x800AE9C4: mul.s       $f16, $f2, $f7
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 7);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f7.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f7.fl);
    // 0x800AE9C8: sub.s       $f19, $f15, $f14
    CHECK_FR(ctx, 19);
    CHECK_FR(ctx, 15);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f15.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f19.fl = ctx->f15.fl - ctx->f14.fl;
    // 0x800AE9CC: mul.s       $f17, $f3, $f8
    CHECK_FR(ctx, 17);
    CHECK_FR(ctx, 3);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f3.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f17.fl = MUL_S(ctx->f3.fl, ctx->f8.fl);
    // 0x800AE9D0: nop

    // 0x800AE9D4: mul.s       $f14, $f0, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800AE9D8: add.s       $f19, $f19, $f16
    CHECK_FR(ctx, 19);
    CHECK_FR(ctx, 19);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f19.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f19.fl = ctx->f19.fl + ctx->f16.fl;
    // 0x800AE9DC: mul.s       $f15, $f1, $f7
    CHECK_FR(ctx, 15);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 7);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f7.fl); 
    ctx->f15.fl = MUL_S(ctx->f1.fl, ctx->f7.fl);
    // 0x800AE9E0: add.s       $f19, $f19, $f17
    CHECK_FR(ctx, 19);
    CHECK_FR(ctx, 19);
    CHECK_FR(ctx, 17);
    NAN_CHECK(ctx->f19.fl); NAN_CHECK(ctx->f17.fl); 
    ctx->f19.fl = ctx->f19.fl + ctx->f17.fl;
    // 0x800AE9E4: mul.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x800AE9E8: sub.s       $f20, $f14, $f15
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 15);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f15.fl); 
    ctx->f20.fl = ctx->f14.fl - ctx->f15.fl;
    // 0x800AE9EC: mul.s       $f17, $f3, $f9
    CHECK_FR(ctx, 17);
    CHECK_FR(ctx, 3);
    CHECK_FR(ctx, 9);
    NAN_CHECK(ctx->f3.fl); NAN_CHECK(ctx->f9.fl); 
    ctx->f17.fl = MUL_S(ctx->f3.fl, ctx->f9.fl);
    // 0x800AE9F0: nop

    // 0x800AE9F4: mul.s       $f14, $f0, $f7
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 7);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f7.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f7.fl);
    // 0x800AE9F8: add.s       $f20, $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f16.fl;
    // 0x800AE9FC: mul.s       $f15, $f1, $f8
    CHECK_FR(ctx, 15);
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f1.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f15.fl = MUL_S(ctx->f1.fl, ctx->f8.fl);
    // 0x800AEA00: add.s       $f20, $f20, $f17
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 17);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f17.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f17.fl;
    // 0x800AEA04: mul.s       $f16, $f2, $f9
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 9);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f9.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f9.fl);
    // 0x800AEA08: add.s       $f21, $f14, $f15
    CHECK_FR(ctx, 21);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 15);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f15.fl); 
    ctx->f21.fl = ctx->f14.fl + ctx->f15.fl;
    // 0x800AEA0C: mul.s       $f17, $f3, $f10
    CHECK_FR(ctx, 17);
    CHECK_FR(ctx, 3);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f3.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f17.fl = MUL_S(ctx->f3.fl, ctx->f10.fl);
    // 0x800AEA10: add.s       $f21, $f21, $f16
    CHECK_FR(ctx, 21);
    CHECK_FR(ctx, 21);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f21.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f21.fl = ctx->f21.fl + ctx->f16.fl;
    // 0x800AEA14: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
    // 0x800AEA18: mov.s       $f1, $f19
    CHECK_FR(ctx, 1);
    CHECK_FR(ctx, 19);
    ctx->f1.fl = ctx->f19.fl;
    // 0x800AEA1C: sub.s       $f21, $f17, $f21
    CHECK_FR(ctx, 21);
    CHECK_FR(ctx, 17);
    CHECK_FR(ctx, 21);
    NAN_CHECK(ctx->f17.fl); NAN_CHECK(ctx->f21.fl); 
    ctx->f21.fl = ctx->f17.fl - ctx->f21.fl;
    // 0x800AEA20: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
    // 0x800AEA24: mov.s       $f3, $f21
    CHECK_FR(ctx, 3);
    CHECK_FR(ctx, 21);
    ctx->f3.fl = ctx->f21.fl;
    // 0x800AEA28: lwc1        $f11, 0x10($v0)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r2, 0X10);
L_800AEA2C:
    // 0x800AEA2C: lwc1        $f12, 0x14($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800AEA30: beq         $a3, $zero, L_800AEA4C
    if (ctx->r7 == 0) {
        // 0x800AEA34: lwc1        $f13, 0x18($v0)
        ctx->f_odd[(13 - 1) * 2] = MEM_W(ctx->r2, 0X18);
            goto L_800AEA4C;
    }
    // 0x800AEA34: lwc1        $f13, 0x18($v0)
    ctx->f_odd[(13 - 1) * 2] = MEM_W(ctx->r2, 0X18);
    // 0x800AEA38: lbu         $t0, 0x9($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0X9);
    // 0x800AEA3C: beq         $t0, $zero, L_800AEA4C
    if (ctx->r8 == 0) {
        // 0x800AEA40: nop
    
            goto L_800AEA4C;
    }
    // 0x800AEA40: nop

    // 0x800AEA44: jal         0x800AF04C
    // 0x800AEA48: nop

    func_800AF04C(rdram, ctx);
        goto after_1;
    // 0x800AEA48: nop

    after_1:
L_800AEA4C:
    // 0x800AEA4C: mul.s       $f4, $f4, $f11
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 11);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f11.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f11.fl);
    // 0x800AEA50: or          $t7, $t8, $zero
    ctx->r15 = ctx->r24 | 0;
    // 0x800AEA54: addiu       $t0, $v0, 0x1C
    ctx->r8 = ADD32(ctx->r2, 0X1C);
    // 0x800AEA58: addiu       $t8, $t8, 0x1
    ctx->r24 = ADD32(ctx->r24, 0X1);
    // 0x800AEA5C: swc1        $f0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f0.u32l;
    // 0x800AEA60: swc1        $f1, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f_odd[(1 - 1) * 2];
    // 0x800AEA64: swc1        $f2, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f2.u32l;
    // 0x800AEA68: mul.s       $f5, $f5, $f12
    CHECK_FR(ctx, 5);
    CHECK_FR(ctx, 5);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f5.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f5.fl = MUL_S(ctx->f5.fl, ctx->f12.fl);
    // 0x800AEA6C: swc1        $f3, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f_odd[(3 - 1) * 2];
    // 0x800AEA70: swc1        $f4, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f4.u32l;
    // 0x800AEA74: sw          $t0, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->r8;
    // 0x800AEA78: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x800AEA7C: addiu       $s2, $s2, 0x40
    ctx->r18 = ADD32(ctx->r18, 0X40);
    // 0x800AEA80: mul.s       $f6, $f6, $f13
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 13);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f13.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f13.fl);
    // 0x800AEA84: swc1        $f5, -0x2C($s2)
    MEM_W(-0X2C, ctx->r18) = ctx->f_odd[(5 - 1) * 2];
    // 0x800AEA88: bne         $t8, $t9, L_800AE8C8
    if (ctx->r24 != ctx->r25) {
        // 0x800AEA8C: swc1        $f6, -0x28($s2)
        MEM_W(-0X28, ctx->r18) = ctx->f6.u32l;
            goto L_800AE8C8;
    }
    // 0x800AEA8C: swc1        $f6, -0x28($s2)
    MEM_W(-0X28, ctx->r18) = ctx->f6.u32l;
    // 0x800AEA90: lw          $ra, 0x0($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X0);
    // 0x800AEA94: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x800AEA98: jr          $ra
    // 0x800AEA9C: nop

    return;
    // 0x800AEA9C: nop

;}
RECOMP_FUNC void func_80809740_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80809740: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80809744: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80809748: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080974C: lw          $s0, 0x188($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X188);
    // 0x80809750: jal         0x8008CABC
    // 0x80809754: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80809754: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    after_0:
    // 0x80809758: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8080975C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80809760: jal         0x80806148
    // 0x80809764: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_80806148_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80809764: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_1:
    // 0x80809768: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8080976C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80809770: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80809774: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80809778: nop

    // 0x8080977C: bc1fl       L_80809790
    if (!c1cs) {
        // 0x80809780: sb          $zero, 0x219($s0)
        MEM_B(0X219, ctx->r16) = 0;
            goto L_80809790;
    }
    goto skip_0;
    // 0x80809780: sb          $zero, 0x219($s0)
    MEM_B(0X219, ctx->r16) = 0;
    skip_0:
    // 0x80809784: b           L_80809790
    // 0x80809788: sb          $t6, 0x219($s0)
    MEM_B(0X219, ctx->r16) = ctx->r14;
        goto L_80809790;
    // 0x80809788: sb          $t6, 0x219($s0)
    MEM_B(0X219, ctx->r16) = ctx->r14;
    // 0x8080978C: sb          $zero, 0x219($s0)
    MEM_B(0X219, ctx->r16) = 0;
L_80809790:
    // 0x80809790: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80809794: jal         0x8008B188
    // 0x80809798: lbu         $a1, 0x219($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X219);
    func_8008B188(rdram, ctx);
        goto after_2;
    // 0x80809798: lbu         $a1, 0x219($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X219);
    after_2:
    // 0x8080979C: jal         0x8080613C
    // 0x808097A0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_8080613C_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x808097A0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_3:
    // 0x808097A4: lbu         $v0, 0x218($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X218);
    // 0x808097A8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x808097AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808097B0: beql        $v0, $zero, L_808097E0
    if (ctx->r2 == 0) {
        // 0x808097B4: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_808097E0;
    }
    goto skip_1;
    // 0x808097B4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_1:
    // 0x808097B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808097BC: beq         $v0, $at, L_808097EC
    if (ctx->r2 == ctx->r1) {
        // 0x808097C0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808097EC;
    }
    // 0x808097C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808097C4: beq         $v0, $at, L_80809800
    if (ctx->r2 == ctx->r1) {
        // 0x808097C8: lwc1        $f16, 0x2C($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
            goto L_80809800;
    }
    // 0x808097C8: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808097CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808097D0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808097D4: b           L_80809810
    // 0x808097D8: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
        goto L_80809810;
    // 0x808097D8: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808097DC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_808097E0:
    // 0x808097E0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808097E4: b           L_80809810
    // 0x808097E8: lwc1        $f16, 0x224($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X224);
        goto L_80809810;
    // 0x808097E8: lwc1        $f16, 0x224($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X224);
L_808097EC:
    // 0x808097EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808097F0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808097F4: lwc1        $f0, 0x224($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X224);
    // 0x808097F8: b           L_80809810
    // 0x808097FC: lwc1        $f16, 0x228($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X228);
        goto L_80809810;
    // 0x808097FC: lwc1        $f16, 0x228($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X228);
L_80809800:
    // 0x80809800: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80809804: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80809808: lwc1        $f0, 0x228($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X228);
    // 0x8080980C: mov.s       $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = ctx->f18.fl;
L_80809810:
    // 0x80809810: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x80809814: nop

    // 0x80809818: bc1tl       L_80809844
    if (c1cs) {
        // 0x8080981C: mov.s       $f2, $f18
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    ctx->f2.fl = ctx->f18.fl;
            goto L_80809844;
    }
    goto skip_2;
    // 0x8080981C: mov.s       $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    ctx->f2.fl = ctx->f18.fl;
    skip_2:
    // 0x80809820: sub.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80809824: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80809828: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8080982C: sub.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x80809830: jal         0x800F0D50
    // 0x80809834: div.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    func_800F0D50(rdram, ctx);
        goto after_4;
    // 0x80809834: div.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    after_4:
    // 0x80809838: b           L_80809844
    // 0x8080983C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_80809844;
    // 0x8080983C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80809840: mov.s       $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    ctx->f2.fl = ctx->f18.fl;
L_80809844:
    // 0x80809844: lwc1        $f0, 0x21C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X21C);
    // 0x80809848: lwc1        $f16, 0x220($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X220);
    // 0x8080984C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80809850: sub.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x80809854: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80809858: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8080985C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80809860: jal         0x8008B1BC
    // 0x80809864: nop

    anctrl_setDuration(rdram, ctx);
        goto after_5;
    // 0x80809864: nop

    after_5:
    // 0x80809868: jal         0x800EA068
    // 0x8080986C: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    func_800EA068(rdram, ctx);
        goto after_6;
    // 0x8080986C: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_6:
    // 0x80809870: bnel        $v0, $zero, L_808098F0
    if (ctx->r2 != 0) {
        // 0x80809874: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808098F0;
    }
    goto skip_3;
    // 0x80809874: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80809878: lbu         $v0, 0x218($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X218);
    // 0x8080987C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80809880: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80809884: beq         $v0, $at, L_808098A0
    if (ctx->r2 == ctx->r1) {
        // 0x80809888: lui         $a1, 0x3EE6
        ctx->r5 = S32(0X3EE6 << 16);
            goto L_808098A0;
    }
    // 0x80809888: lui         $a1, 0x3EE6
    ctx->r5 = S32(0X3EE6 << 16);
    // 0x8080988C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80809890: beq         $v0, $at, L_808098C8
    if (ctx->r2 == ctx->r1) {
        // 0x80809894: lw          $a0, 0x50($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X50);
            goto L_808098C8;
    }
    // 0x80809894: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80809898: b           L_808098F0
    // 0x8080989C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808098F0;
    // 0x8080989C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808098A0:
    // 0x808098A0: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x808098A4: jal         0x800A2CE8
    // 0x808098A8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800A2CE8(rdram, ctx);
        goto after_7;
    // 0x808098A8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_7:
    // 0x808098AC: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x808098B0: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x808098B4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x808098B8: jal         0x800A2CE8
    // 0x808098BC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800A2CE8(rdram, ctx);
        goto after_8;
    // 0x808098BC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_8:
    // 0x808098C0: b           L_808098F0
    // 0x808098C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808098F0;
    // 0x808098C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808098C8:
    // 0x808098C8: lui         $a1, 0x3EE6
    ctx->r5 = S32(0X3EE6 << 16);
    // 0x808098CC: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x808098D0: jal         0x800A2CE8
    // 0x808098D4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800A2CE8(rdram, ctx);
        goto after_9;
    // 0x808098D4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_9:
    // 0x808098D8: lui         $a1, 0x3F73
    ctx->r5 = S32(0X3F73 << 16);
    // 0x808098DC: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x808098E0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x808098E4: jal         0x800A2CE8
    // 0x808098E8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800A2CE8(rdram, ctx);
        goto after_10;
    // 0x808098E8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_10:
    // 0x808098EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808098F0:
    // 0x808098F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808098F4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x808098F8: jr          $ra
    // 0x808098FC: nop

    return;
    // 0x808098FC: nop

;}
RECOMP_FUNC void func_801107B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "func_801107B0");
    // 0x801107B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801107B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801107B8: jal         0x800F5A00
    // 0x801107BC: lw          $a0, 0x68($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X68);
    func_800F5A00(rdram, ctx);
        goto after_0;
    // 0x801107BC: lw          $a0, 0x68($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X68);
    after_0:
    // 0x801107C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801107C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801107C8: jr          $ra
    // 0x801107CC: nop

    return;
    // 0x801107CC: nop

;}
RECOMP_FUNC void func_80801638_chpiranha(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801638: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080163C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801640: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x80801644: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80801648: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080164C: beq         $t6, $zero, L_8080167C
    if (ctx->r14 == 0) {
        // 0x80801650: nop
    
            goto L_8080167C;
    }
    // 0x80801650: nop

    // 0x80801654: jal         0x80100094
    // 0x80801658: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801658: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080165C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801660: lw          $t0, 0x18($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X18);
    // 0x80801664: lw          $t7, 0x3C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X3C);
    // 0x80801668: lhu         $t8, 0x12($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X12);
    // 0x8080166C: srl         $t9, $t8, 1
    ctx->r25 = S32(U32(ctx->r24) >> 1);
    // 0x80801670: xor         $v1, $t9, $t0
    ctx->r3 = ctx->r25 ^ ctx->r8;
    // 0x80801674: b           L_8080167C
    // 0x80801678: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
        goto L_8080167C;
    // 0x80801678: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
L_8080167C:
    // 0x8080167C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801680: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801684: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80801688: jr          $ra
    // 0x8080168C: nop

    return;
    // 0x8080168C: nop

;}
RECOMP_FUNC void func_80800904_bsride(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800904: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800908: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080090C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800910: jal         0x8008CABC
    // 0x80800914: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800914: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800918: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8080091C: lw          $v1, 0x160($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X160);
    // 0x80800920: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800924: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800928: beq         $v1, $at, L_80800948
    if (ctx->r3 == ctx->r1) {
        // 0x8080092C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800948;
    }
    // 0x8080092C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800930: bne         $v1, $at, L_80800948
    if (ctx->r3 != ctx->r1) {
        // 0x80800934: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800948;
    }
    // 0x80800934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800938: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    // 0x8080093C: jal         0x80095760
    // 0x80800940: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    baflag_set(rdram, ctx);
        goto after_1;
    // 0x80800940: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800944: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
L_80800948:
    // 0x80800948: lw          $t6, 0x15C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X15C);
    // 0x8080094C: addiu       $t7, $zero, 0x2F
    ctx->r15 = ADD32(0, 0X2F);
    // 0x80800950: beql        $t6, $zero, L_80800978
    if (ctx->r14 == 0) {
        // 0x80800954: sw          $t7, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r15;
            goto L_80800978;
    }
    goto skip_0;
    // 0x80800954: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    skip_0:
    // 0x80800958: jal         0x8008B2B4
    // 0x8080095C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    anctrl_getAnimTimer(rdram, ctx);
        goto after_2;
    // 0x8080095C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x80800960: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800964: jal         0x80086BF8
    // 0x80800968: lw          $a0, 0x15C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X15C);
    _chflysaucer_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80800968: lw          $a0, 0x15C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X15C);
    after_3:
    // 0x8080096C: b           L_8080097C
    // 0x80800970: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080097C;
    // 0x80800970: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800974: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
L_80800978:
    // 0x80800978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080097C:
    // 0x8080097C: jal         0x8009E5C8
    // 0x80800980: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    bs_setState(rdram, ctx);
        goto after_4;
    // 0x80800980: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80800984: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800988: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080098C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800990: jr          $ra
    // 0x80800994: nop

    return;
    // 0x80800994: nop

;}
RECOMP_FUNC void func_80800324_chfactoryprop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "func_80800324_chfactoryprop");
    // 0x80800324: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800328: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080032C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800330: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x80800334: addiu       $at, $zero, 0x3B2
    ctx->r1 = ADD32(0, 0X3B2);
    // 0x80800338: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080033C: sll         $t7, $t6, 11
    ctx->r15 = S32(ctx->r14 << 11);
    // 0x80800340: srl         $t8, $t7, 20
    ctx->r24 = S32(U32(ctx->r15) >> 20);
    // 0x80800344: bnel        $t8, $at, L_80800560
    if (ctx->r24 != ctx->r1) {
        // 0x80800348: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800560;
    }
    goto skip_0;
    // 0x80800348: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8080034C: jal         0x8008FE68
    // 0x80800350: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    func_8008FE68(rdram, ctx);
        goto after_0;
    // 0x80800350: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_0:
    // 0x80800354: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1124, 0XBF0) << 16);
    // 0x80800358: lwc1        $f0, 0x48($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8080035C: lwc1        $f4, 0xBF0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1124, 0XBF0));
    // 0x80800360: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1124, 0XBF4) << 16);
    // 0x80800364: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800368: nop

    // 0x8080036C: bc1tl       L_80800560
    if (c1cs) {
        // 0x80800370: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800560;
    }
    goto skip_1;
    // 0x80800370: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80800374: lwc1        $f6, 0xBF4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1124, 0XBF4));
    // 0x80800378: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8080037C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80800380: nop

    // 0x80800384: bc1tl       L_80800560
    if (c1cs) {
        // 0x80800388: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800560;
    }
    goto skip_2;
    // 0x80800388: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x8080038C: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800390: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x80800394: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800398: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8080039C: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x808003A0: lui         $a2, 0x457A
    ctx->r6 = S32(0X457A << 16);
    // 0x808003A4: lui         $a3, 0x4448
    ctx->r7 = S32(0X4448 << 16);
    // 0x808003A8: c.le.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl <= ctx->f16.fl;
    // 0x808003AC: nop

    // 0x808003B0: bc1fl       L_808003E4
    if (!c1cs) {
        // 0x808003B4: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_808003E4;
    }
    goto skip_3;
    // 0x808003B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_3:
    // 0x808003B8: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
    // 0x808003BC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808003C0: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x808003C4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808003C8: lui         $a2, 0xC2C8
    ctx->r6 = S32(0XC2C8 << 16);
    // 0x808003CC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x808003D0: jal         0x800F10B4
    // 0x808003D4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x808003D4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x808003D8: b           L_808003F4
    // 0x808003DC: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
        goto L_808003F4;
    // 0x808003DC: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x808003E0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_808003E4:
    // 0x808003E4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808003E8: jal         0x800F10B4
    // 0x808003EC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x808003EC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x808003F0: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
L_808003F4:
    // 0x808003F4: jal         0x800D8FF8
    // 0x808003F8: nop

    func_800D8FF8(rdram, ctx);
        goto after_3;
    // 0x808003F8: nop

    after_3:
    // 0x808003FC: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80800400: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800404: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80800408: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080040C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800410: lwc1        $f12, 0x2C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800414: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80800418: jal         0x800F15F8
    // 0x8080041C: nop

    func_800F15F8(rdram, ctx);
        goto after_4;
    // 0x8080041C: nop

    after_4:
    // 0x80800420: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x80800424: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1124, 0XBF8) << 16);
    // 0x80800428: lwc1        $f16, 0xBF8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1124, 0XBF8));
    // 0x8080042C: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800430: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80800434: nop

    // 0x80800438: bc1f        L_8080047C
    if (!c1cs) {
        // 0x8080043C: nop
    
            goto L_8080047C;
    }
    // 0x8080043C: nop

    // 0x80800440: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80800444: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800448: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x8080044C: nop

    // 0x80800450: bc1f        L_8080047C
    if (!c1cs) {
        // 0x80800454: nop
    
            goto L_8080047C;
    }
    // 0x80800454: nop

    // 0x80800458: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8080045C: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80800460: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800464: nop

    // 0x80800468: bc1f        L_8080047C
    if (!c1cs) {
        // 0x8080046C: nop
    
            goto L_8080047C;
    }
    // 0x8080046C: nop

    // 0x80800470: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800474: nop

    // 0x80800478: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
L_8080047C:
    // 0x8080047C: jal         0x80090794
    // 0x80800480: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    func_80090794(rdram, ctx);
        goto after_5;
    // 0x80800480: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_5:
    // 0x80800484: lwc1        $f16, 0x2C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800488: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8080048C: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800490: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80800494: add.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80800498: lui         $a1, 0x42B4
    ctx->r5 = S32(0X42B4 << 16);
    // 0x8080049C: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x808004A0: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x808004A4: jal         0x800EF1B8
    // 0x808004A8: nop

    func_800EF1B8(rdram, ctx);
        goto after_6;
    // 0x808004A8: nop

    after_6:
    // 0x808004AC: jal         0x800907C0
    // 0x808004B0: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    func_800907C0(rdram, ctx);
        goto after_7;
    // 0x808004B0: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_7:
    // 0x808004B4: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x808004B8: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808004BC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1124, 0XBFC) << 16);
    // 0x808004C0: lwc1        $f18, 0xBFC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1124, 0XBFC));
    // 0x808004C4: add.s       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x808004C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808004CC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1124, 0XC00) << 16);
    // 0x808004D0: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    // 0x808004D4: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x808004D8: lui         $a3, 0x45FA
    ctx->r7 = S32(0X45FA << 16);
    // 0x808004DC: bc1f        L_808004E8
    if (!c1cs) {
        // 0x808004E0: nop
    
            goto L_808004E8;
    }
    // 0x808004E0: nop

    // 0x808004E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004E8:
    // 0x808004E8: bne         $v0, $zero, L_80800504
    if (ctx->r2 != 0) {
        // 0x808004EC: nop
    
            goto L_80800504;
    }
    // 0x808004EC: nop

    // 0x808004F0: bnel        $v0, $zero, L_80800560
    if (ctx->r2 != 0) {
        // 0x808004F4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800560;
    }
    goto skip_4;
    // 0x808004F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x808004F8: lbu         $t9, 0x1C($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1C);
    // 0x808004FC: beql        $t9, $zero, L_80800560
    if (ctx->r25 == 0) {
        // 0x80800500: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800560;
    }
    goto skip_5;
    // 0x80800500: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
L_80800504:
    // 0x80800504: lwc1        $f10, 0xC00($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1124, 0XC00));
    // 0x80800508: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080050C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800510: jal         0x800F10B4
    // 0x80800514: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_8;
    // 0x80800514: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_8:
    // 0x80800518: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8080051C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1124, 0XCF8) << 16);
    // 0x80800520: addiu       $a3, $a3, 0xCF8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1124, 0XCF8));
    // 0x80800524: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80800528: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x8080052C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80800530: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80800534: lw          $t2, 0x70($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X70);
    // 0x80800538: lbu         $a0, 0x1C($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1C);
    // 0x8080053C: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80800540: jal         0x80089D68
    // 0x80800544: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    _subaddieaudioloop_entrypoint_7(rdram, ctx);
        goto after_9;
    // 0x80800544: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_9:
    // 0x80800548: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x8080054C: beq         $a0, $zero, L_8080055C
    if (ctx->r4 == 0) {
        // 0x80800550: sb          $v0, 0x1C($s0)
        MEM_B(0X1C, ctx->r16) = ctx->r2;
            goto L_8080055C;
    }
    // 0x80800550: sb          $v0, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = ctx->r2;
    // 0x80800554: jal         0x800C3058
    // 0x80800558: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800C3058(rdram, ctx);
        goto after_10;
    // 0x80800558: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_10:
L_8080055C:
    // 0x8080055C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800560:
    // 0x80800560: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800564: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80800568: jr          $ra
    // 0x8080056C: nop

    return;
    // 0x8080056C: nop

;}
RECOMP_FUNC void func_800C7310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7310: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C7314: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7318: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C731C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C7320: jal         0x80087A90
    // 0x800C7324: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gcgoto_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x800C7324: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800C7328: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C732C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C7330: jr          $ra
    // 0x800C7334: nop

    return;
    // 0x800C7334: nop

;}
RECOMP_FUNC void func_808001D8_bsbflap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001E0: jal         0x8008CABC
    // 0x808001E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808001E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808001E8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808001EC: jal         0x80800168
    // 0x808001F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800168_bsbflap(rdram, ctx);
        goto after_1;
    // 0x808001F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808001F4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808001F8: jal         0x8008B1BC
    // 0x808001FC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    anctrl_setDuration(rdram, ctx);
        goto after_2;
    // 0x808001FC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800204: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800208: jr          $ra
    // 0x8080020C: nop

    return;
    // 0x8080020C: nop

;}
RECOMP_FUNC void func_800D88F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D88F8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800D88FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D8900: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800D8904: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D8908: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800D890C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800D8910: addiu       $a0, $a0, -0x3FE0
    ctx->r4 = ADD32(ctx->r4, -0X3FE0);
    // 0x800D8914: jal         0x800B3044
    // 0x800D8918: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    freelist_next(rdram, ctx);
        goto after_0;
    // 0x800D8918: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x800D891C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800D8920: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
L_800D8924:
    // 0x800D8924: lh          $a0, 0x2E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2E);
    // 0x800D8928: jal         0x800D8988
    // 0x800D892C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800D8988(rdram, ctx);
        goto after_1;
    // 0x800D892C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x800D8930: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800D8934: bne         $s0, $s1, L_800D8924
    if (ctx->r16 != ctx->r17) {
        // 0x800D8938: sb          $zero, 0x1A($v0)
        MEM_B(0X1A, ctx->r2) = 0;
            goto L_800D8924;
    }
    // 0x800D8938: sb          $zero, 0x1A($v0)
    MEM_B(0X1A, ctx->r2) = 0;
    // 0x800D893C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D8940: lh          $v0, 0x2E($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X2E);
    // 0x800D8944: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D8948: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D894C: jr          $ra
    // 0x800D8950: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800D8950: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_808086E8_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808086E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808086EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808086F0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808086F4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808086F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808086FC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80808700: jal         0x80100094
    // 0x80808704: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80808704: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80808708: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8080870C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808710: jal         0x80806F10
    // 0x80808714: lbu         $a1, 0xD8($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0XD8);
    func_80806F10_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x80808714: lbu         $a1, 0xD8($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0XD8);
    after_1:
    // 0x80808718: lw          $t6, 0xD4($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XD4);
    // 0x8080871C: sb          $v0, 0xD8($s1)
    MEM_B(0XD8, ctx->r17) = ctx->r2;
    // 0x80808720: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80808724: beql        $t6, $zero, L_808087E0
    if (ctx->r14 == 0) {
        // 0x80808728: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808087E0;
    }
    goto skip_0;
    // 0x80808728: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080872C: lw          $v0, 0x24($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X24);
    // 0x80808730: addiu       $at, $zero, 0x26C
    ctx->r1 = ADD32(0, 0X26C);
    // 0x80808734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808738: srl         $t8, $v0, 22
    ctx->r24 = S32(U32(ctx->r2) >> 22);
    // 0x8080873C: beq         $t8, $at, L_8080875C
    if (ctx->r24 == ctx->r1) {
        // 0x80808740: addiu       $at, $zero, 0x26D
        ctx->r1 = ADD32(0, 0X26D);
            goto L_8080875C;
    }
    // 0x80808740: addiu       $at, $zero, 0x26D
    ctx->r1 = ADD32(0, 0X26D);
    // 0x80808744: beq         $t8, $at, L_8080875C
    if (ctx->r24 == ctx->r1) {
        // 0x80808748: addiu       $at, $zero, 0x26E
        ctx->r1 = ADD32(0, 0X26E);
            goto L_8080875C;
    }
    // 0x80808748: addiu       $at, $zero, 0x26E
    ctx->r1 = ADD32(0, 0X26E);
    // 0x8080874C: beq         $t8, $at, L_8080875C
    if (ctx->r24 == ctx->r1) {
        // 0x80808750: addiu       $at, $zero, 0x26F
        ctx->r1 = ADD32(0, 0X26F);
            goto L_8080875C;
    }
    // 0x80808750: addiu       $at, $zero, 0x26F
    ctx->r1 = ADD32(0, 0X26F);
    // 0x80808754: bnel        $t8, $at, L_808087E0
    if (ctx->r24 != ctx->r1) {
        // 0x80808758: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808087E0;
    }
    goto skip_1;
    // 0x80808758: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
L_8080875C:
    // 0x8080875C: jal         0x80109FE8
    // 0x80808760: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80109FE8(rdram, ctx);
        goto after_2;
    // 0x80808760: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80808764: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808768: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    // 0x8080876C: jal         0x80803BE8
    // 0x80808770: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    func_80803BE8_chdiggerboss(rdram, ctx);
        goto after_3;
    // 0x80808770: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    after_3:
    // 0x80808774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808778: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8080877C: jal         0x80802878
    // 0x80808780: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80802878_chdiggerboss(rdram, ctx);
        goto after_4;
    // 0x80808780: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80808784: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808788: addiu       $a1, $zero, 0x1735
    ctx->r5 = ADD32(0, 0X1735);
    // 0x8080878C: jal         0x80803660
    // 0x80808790: addiu       $a2, $zero, 0x14C
    ctx->r6 = ADD32(0, 0X14C);
    func_80803660_chdiggerboss(rdram, ctx);
        goto after_5;
    // 0x80808790: addiu       $a2, $zero, 0x14C
    ctx->r6 = ADD32(0, 0X14C);
    after_5:
    // 0x80808794: jal         0x80802248
    // 0x80808798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802248_chdiggerboss(rdram, ctx);
        goto after_6;
    // 0x80808798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080879C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808087A0: jal         0x800F7B9C
    // 0x808087A4: addiu       $a1, $zero, 0x63
    ctx->r5 = ADD32(0, 0X63);
    func_800F7B9C(rdram, ctx);
        goto after_7;
    // 0x808087A4: addiu       $a1, $zero, 0x63
    ctx->r5 = ADD32(0, 0X63);
    after_7:
    // 0x808087A8: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x808087AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808087B0: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808087B4: lw          $a0, 0xD4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XD4);
    // 0x808087B8: addiu       $a1, $zero, 0x9B
    ctx->r5 = ADD32(0, 0X9B);
    // 0x808087BC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808087C0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808087C4: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x808087C8: jal         0x8010114C
    // 0x808087CC: nop

    func_8010114C(rdram, ctx);
        goto after_8;
    // 0x808087CC: nop

    after_8:
    // 0x808087D0: sw          $zero, 0xD4($s1)
    MEM_W(0XD4, ctx->r17) = 0;
    // 0x808087D4: sb          $zero, 0xCC($s1)
    MEM_B(0XCC, ctx->r17) = 0;
    // 0x808087D8: sb          $zero, 0x2($s1)
    MEM_B(0X2, ctx->r17) = 0;
    // 0x808087DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808087E0:
    // 0x808087E0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808087E4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808087E8: jr          $ra
    // 0x808087EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808087EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _glcutDll_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088828: syscall     705
    recomp_syscall_handler(rdram, ctx, 0x80088828);
    return;
    // 0x8008882C: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void chlavaarchgrillswitch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080001C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1928, 0X30) << 16);
    // 0x80800020: jr          $ra
    // 0x80800024: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1928, 0X30));
    return;
    // 0x80800024: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1928, 0X30));
    // 0x80800028: nop

    // 0x8080002C: nop

;}
RECOMP_FUNC void func_80800000_chmayaentrydoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800004: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800008: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080000C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800010: jal         0x80088840
    // 0x80800014: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_0;
    // 0x80800014: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    after_0:
    // 0x80800018: bne         $v0, $zero, L_80800038
    if (ctx->r2 != 0) {
        // 0x8080001C: nop
    
            goto L_80800038;
    }
    // 0x8080001C: nop

    // 0x80800020: jal         0x8008A738
    // 0x80800024: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _sujiggy_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x80800024: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80800028: beq         $v0, $zero, L_80800038
    if (ctx->r2 == 0) {
        // 0x8080002C: nop
    
            goto L_80800038;
    }
    // 0x8080002C: nop

    // 0x80800030: jal         0x800DA544
    // 0x80800034: addiu       $a0, $zero, 0x392
    ctx->r4 = ADD32(0, 0X392);
    func_800DA544(rdram, ctx);
        goto after_2;
    // 0x80800034: addiu       $a0, $zero, 0x392
    ctx->r4 = ADD32(0, 0X392);
    after_2:
L_80800038:
    // 0x80800038: jal         0x800D3E40
    // 0x8080003C: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_800D3E40(rdram, ctx);
        goto after_3;
    // 0x8080003C: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_3:
    // 0x80800040: beql        $v0, $zero, L_80800074
    if (ctx->r2 == 0) {
        // 0x80800044: addiu       $v0, $zero, 0x392
        ctx->r2 = ADD32(0, 0X392);
            goto L_80800074;
    }
    goto skip_0;
    // 0x80800044: addiu       $v0, $zero, 0x392
    ctx->r2 = ADD32(0, 0X392);
    skip_0:
    // 0x80800048: jal         0x80088840
    // 0x8080004C: addiu       $a0, $zero, 0x7A
    ctx->r4 = ADD32(0, 0X7A);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_4;
    // 0x8080004C: addiu       $a0, $zero, 0x7A
    ctx->r4 = ADD32(0, 0X7A);
    after_4:
    // 0x80800050: bne         $v0, $zero, L_80800070
    if (ctx->r2 != 0) {
        // 0x80800054: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800070;
    }
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800058: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8080005C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800060: jal         0x80101FDC
    // 0x80800064: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_5;
    // 0x80800064: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_5:
    // 0x80800068: b           L_80800074
    // 0x8080006C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
        goto L_80800074;
    // 0x8080006C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
L_80800070:
    // 0x80800070: addiu       $v0, $zero, 0x392
    ctx->r2 = ADD32(0, 0X392);
L_80800074:
    // 0x80800074: lui         $at, 0x435C
    ctx->r1 = S32(0X435C << 16);
    // 0x80800078: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080007C: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800080: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800084: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800088: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8080008C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80800090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800094: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800098: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x8080009C: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x808000A0: jal         0x80086898
    // 0x808000A4: nop

    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x808000A4: nop

    after_6:
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000AC: jal         0x800868C0
    // 0x808000B0: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_7;
    // 0x808000B0: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_7:
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B8: jal         0x800868A8
    // 0x808000BC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_8;
    // 0x808000BC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_8:
    // 0x808000C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808000C4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808000C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808000CC: jr          $ra
    // 0x808000D0: nop

    return;
    // 0x808000D0: nop

;}
RECOMP_FUNC void func_80800BA8_chgoldfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BA8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800BAC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800BB0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800BB4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800BB8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80800BBC: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80800BC0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800BC4: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800BC8: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x80800BCC: lw          $a1, 0x0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X0);
    // 0x80800BD0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800BD4: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800BD8: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80800BDC: jal         0x800EFA4C
    // 0x80800BE0: nop

    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x80800BE0: nop

    after_0:
    // 0x80800BE4: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80800BE8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800BEC: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800BF0: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800BF4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800BF8: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80800BFC: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x80800C00: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800C04: jal         0x800BEF00
    // 0x80800C08: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    func_800BEF00(rdram, ctx);
        goto after_1;
    // 0x80800C08: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    after_1:
    // 0x80800C0C: beq         $v0, $zero, L_80800C2C
    if (ctx->r2 == 0) {
        // 0x80800C10: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_80800C2C;
    }
    // 0x80800C10: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800C14: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800C18: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800C1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800C20: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800C24: b           L_80800C30
    // 0x80800C28: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
        goto L_80800C30;
    // 0x80800C28: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
L_80800C2C:
    // 0x80800C2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800C30:
    // 0x80800C30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C34: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800C38: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800C3C: jr          $ra
    // 0x80800C40: nop

    return;
    // 0x80800C40: nop

;}
RECOMP_FUNC void indrv_lights_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80800004: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: sltiu       $at, $t6, 0x7
    ctx->r1 = ctx->r14 < 0X7 ? 1 : 0;
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800014: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800018: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x8080001C: beq         $at, $zero, L_80800294
    if (ctx->r1 == 0) {
        // 0x80800020: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_80800294;
    }
    // 0x80800020: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80800024: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800028: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2962, 0X2B0) << 16);
    // 0x8080002C: addu        $at, $at, $t6
    gpr jr_addend_80800034 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800030: lw          $t6, 0x2B0($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2962, 0X2B0));
    // 0x80800034: jr          $t6
    // 0x80800038: nop

    switch (jr_addend_80800034 >> 2) {
        case 0: goto L_8080003C; break;
        case 1: goto L_808000F0; break;
        case 2: goto L_80800110; break;
        case 3: goto L_80800130; break;
        case 4: goto L_808001B8; break;
        case 5: goto L_808000A4; break;
        case 6: goto L_80800224; break;
        default: switch_error(__func__, 0x80800034, 0x808002B0);
    }
    // 0x80800038: nop

L_8080003C:
    // 0x8080003C: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x80800040: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x80800044: and         $t7, $a3, $at
    ctx->r15 = ctx->r7 & ctx->r1;
    // 0x80800048: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8080004C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80800050: and         $t9, $a3, $at
    ctx->r25 = ctx->r7 & ctx->r1;
    // 0x80800054: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800058: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8080005C: and         $a0, $s0, $at
    ctx->r4 = ctx->r16 & ctx->r1;
    // 0x80800060: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x80800064: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800068: andi        $t1, $a3, 0xFF00
    ctx->r9 = ctx->r7 & 0XFF00;
    // 0x8080006C: srl         $t8, $t7, 24
    ctx->r24 = S32(U32(ctx->r15) >> 24);
    // 0x80800070: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800074: sra         $t0, $t9, 16
    ctx->r8 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80800078: sra         $t2, $t1, 8
    ctx->r10 = S32(SIGNED(ctx->r9) >> 8);
    // 0x8080007C: srl         $t3, $a0, 16
    ctx->r11 = S32(U32(ctx->r4) >> 16);
    // 0x80800080: sw          $t8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r24;
    // 0x80800084: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    // 0x80800088: sw          $t2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r10;
    // 0x8080008C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80800090: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x80800094: jal         0x8008A8A8
    // 0x80800098: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    _sulights_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800098: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_0:
    // 0x8080009C: b           L_80800298
    // 0x808000A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800298;
    // 0x808000A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000A4:
    // 0x808000A4: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x808000A8: and         $t5, $a3, $at
    ctx->r13 = ctx->r7 & ctx->r1;
    // 0x808000AC: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x808000B0: and         $t7, $a3, $at
    ctx->r15 = ctx->r7 & ctx->r1;
    // 0x808000B4: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x808000B8: andi        $t9, $a3, 0xFF00
    ctx->r25 = ctx->r7 & 0XFF00;
    // 0x808000BC: and         $a0, $s0, $at
    ctx->r4 = ctx->r16 & ctx->r1;
    // 0x808000C0: srl         $t6, $t5, 24
    ctx->r14 = S32(U32(ctx->r13) >> 24);
    // 0x808000C4: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x808000C8: sra         $t0, $t9, 8
    ctx->r8 = S32(SIGNED(ctx->r25) >> 8);
    // 0x808000CC: srl         $t1, $a0, 16
    ctx->r9 = S32(U32(ctx->r4) >> 16);
    // 0x808000D0: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    // 0x808000D4: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x808000D8: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x808000DC: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x808000E0: jal         0x800C8E84
    // 0x808000E4: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_800C8E84(rdram, ctx);
        goto after_1;
    // 0x808000E4: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_1:
    // 0x808000E8: b           L_80800298
    // 0x808000EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800298;
    // 0x808000EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000F0:
    // 0x808000F0: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x808000F4: and         $a0, $s0, $at
    ctx->r4 = ctx->r16 & ctx->r1;
    // 0x808000F8: srl         $t2, $a0, 16
    ctx->r10 = S32(U32(ctx->r4) >> 16);
    // 0x808000FC: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x80800100: jal         0x800C8FE0
    // 0x80800104: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C8FE0(rdram, ctx);
        goto after_2;
    // 0x80800104: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800108: b           L_80800298
    // 0x8080010C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800298;
    // 0x8080010C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800110:
    // 0x80800110: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80800114: and         $a0, $s0, $at
    ctx->r4 = ctx->r16 & ctx->r1;
    // 0x80800118: srl         $t3, $a0, 16
    ctx->r11 = S32(U32(ctx->r4) >> 16);
    // 0x8080011C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x80800120: jal         0x800C8FE0
    // 0x80800124: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C8FE0(rdram, ctx);
        goto after_3;
    // 0x80800124: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800128: b           L_80800298
    // 0x8080012C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800298;
    // 0x8080012C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800130:
    // 0x80800130: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x80800134: andi        $t6, $a3, 0xFFFF
    ctx->r14 = ctx->r7 & 0XFFFF;
    // 0x80800138: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8080013C: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x80800140: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x80800144: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800148: bgez        $t5, L_8080015C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8080014C: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8080015C;
    }
    // 0x8080014C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800150: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800154: nop

    // 0x80800158: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_8080015C:
    // 0x8080015C: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    // 0x80800160: bgez        $t6, L_80800178
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80800164: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80800178;
    }
    // 0x80800164: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800168: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8080016C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800170: nop

    // 0x80800174: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_80800178:
    // 0x80800178: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x8080017C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80800180: and         $a0, $s0, $at
    ctx->r4 = ctx->r16 & ctx->r1;
    // 0x80800184: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800188: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x8080018C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800190: srl         $t7, $a0, 16
    ctx->r15 = S32(U32(ctx->r4) >> 16);
    // 0x80800194: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    // 0x80800198: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8080019C: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x808001A0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x808001A4: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x808001A8: jal         0x8008A8B8
    // 0x808001AC: nop

    _sulights_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x808001AC: nop

    after_4:
    // 0x808001B0: b           L_80800298
    // 0x808001B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800298;
    // 0x808001B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001B8:
    // 0x808001B8: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x808001BC: andi        $t0, $a3, 0xFFFF
    ctx->r8 = ctx->r7 & 0XFFFF;
    // 0x808001C0: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x808001C4: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x808001C8: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x808001CC: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x808001D0: bgez        $t9, L_808001E8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808001D4: cvt.s.w     $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
            goto L_808001E8;
    }
    // 0x808001D4: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808001D8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808001DC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808001E0: nop

    // 0x808001E4: add.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f16.fl;
L_808001E8:
    // 0x808001E8: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x808001EC: bgez        $t0, L_80800204
    if (SIGNED(ctx->r8) >= 0) {
        // 0x808001F0: cvt.s.w     $f18, $f4
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80800204;
    }
    // 0x808001F0: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808001F4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808001F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001FC: nop

    // 0x80800200: add.s       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f6.fl;
L_80800204:
    // 0x80800204: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80800208: and         $a0, $s0, $at
    ctx->r4 = ctx->r16 & ctx->r1;
    // 0x8080020C: srl         $t1, $a0, 16
    ctx->r9 = S32(U32(ctx->r4) >> 16);
    // 0x80800210: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x80800214: jal         0x800C8D4C
    // 0x80800218: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    func_800C8D4C(rdram, ctx);
        goto after_5;
    // 0x80800218: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_5:
    // 0x8080021C: b           L_80800298
    // 0x80800220: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800298;
    // 0x80800220: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800224:
    // 0x80800224: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800228: jal         0x80106790
    // 0x8080022C: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    func_80106790(rdram, ctx);
        goto after_6;
    // 0x8080022C: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    after_6:
    // 0x80800230: lw          $t2, 0x7C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X7C);
    // 0x80800234: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x80800238: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x8080023C: sll         $t5, $t2, 19
    ctx->r13 = S32(ctx->r10 << 19);
    // 0x80800240: bgez        $t5, L_80800254
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80800244: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800254;
    }
    // 0x80800244: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800248: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8080024C: bne         $a1, $at, L_80800274
    if (ctx->r5 != ctx->r1) {
        // 0x80800250: addiu       $a2, $sp, 0x24
        ctx->r6 = ADD32(ctx->r29, 0X24);
            goto L_80800274;
    }
    // 0x80800250: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
L_80800254:
    // 0x80800254: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80800258: and         $a0, $s0, $at
    ctx->r4 = ctx->r16 & ctx->r1;
    // 0x8080025C: srl         $t6, $a0, 16
    ctx->r14 = S32(U32(ctx->r4) >> 16);
    // 0x80800260: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80800264: jal         0x800C8CB8
    // 0x80800268: addiu       $a1, $v1, 0x4
    ctx->r5 = ADD32(ctx->r3, 0X4);
    func_800C8CB8(rdram, ctx);
        goto after_7;
    // 0x80800268: addiu       $a1, $v1, 0x4
    ctx->r5 = ADD32(ctx->r3, 0X4);
    after_7:
    // 0x8080026C: b           L_80800298
    // 0x80800270: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800298;
    // 0x80800270: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800274:
    // 0x80800274: jal         0x800DBEFC
    // 0x80800278: lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X4);
    func_800DBEFC(rdram, ctx);
        goto after_8;
    // 0x80800278: lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X4);
    after_8:
    // 0x8080027C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80800280: and         $a0, $s0, $at
    ctx->r4 = ctx->r16 & ctx->r1;
    // 0x80800284: srl         $t7, $a0, 16
    ctx->r15 = S32(U32(ctx->r4) >> 16);
    // 0x80800288: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8080028C: jal         0x800C8CB8
    // 0x80800290: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800C8CB8(rdram, ctx);
        goto after_9;
    // 0x80800290: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_9:
L_80800294:
    // 0x80800294: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800298:
    // 0x80800298: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080029C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x808002A0: jr          $ra
    // 0x808002A4: nop

    return;
    // 0x808002A4: nop

    // 0x808002A8: nop

    // 0x808002AC: nop

;}
RECOMP_FUNC void _chalienkids_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086568: syscall     337
    recomp_syscall_handler(rdram, ctx, 0x80086568);
    return;
    // 0x8008656C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808019C8_chalienkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808019C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808019CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808019D0: lhu         $t6, 0x64($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X64);
    // 0x808019D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808019D8: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x808019DC: beql        $t7, $zero, L_80801A44
    if (ctx->r15 == 0) {
        // 0x808019E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801A44;
    }
    goto skip_0;
    // 0x808019E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808019E4: jal         0x80100094
    // 0x808019E8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808019E8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808019EC: beq         $v0, $zero, L_80801A40
    if (ctx->r2 == 0) {
        // 0x808019F0: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_80801A40;
    }
    // 0x808019F0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808019F4: jal         0x801022E4
    // 0x808019F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_801022E4(rdram, ctx);
        goto after_1;
    // 0x808019F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808019FC: addiu       $t8, $v0, -0x325
    ctx->r24 = ADD32(ctx->r2, -0X325);
    // 0x80801A00: sltiu       $at, $t8, 0xA
    ctx->r1 = ctx->r24 < 0XA ? 1 : 0;
    // 0x80801A04: beq         $at, $zero, L_80801A20
    if (ctx->r1 == 0) {
        // 0x80801A08: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80801A20;
    }
    // 0x80801A08: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80801A0C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1324, 0X1E30) << 16);
    // 0x80801A10: addu        $at, $at, $t8
    gpr jr_addend_80801A18 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80801A14: lw          $t8, 0x1E30($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1324, 0X1E30));
    // 0x80801A18: jr          $t8
    // 0x80801A1C: nop

    switch (jr_addend_80801A18 >> 2) {
        case 0: goto L_80801A2C; break;
        case 1: goto L_80801A2C; break;
        case 2: goto L_80801A20; break;
        case 3: goto L_80801A20; break;
        case 4: goto L_80801A2C; break;
        case 5: goto L_80801A20; break;
        case 6: goto L_80801A20; break;
        case 7: goto L_80801A2C; break;
        case 8: goto L_80801A20; break;
        case 9: goto L_80801A2C; break;
        default: switch_error(__func__, 0x80801A18, 0x80801E30);
    }
    // 0x80801A1C: nop

L_80801A20:
    // 0x80801A20: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80801A24: jal         0x80089818
    // 0x80801A28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_18(rdram, ctx);
        goto after_2;
    // 0x80801A28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_80801A2C:
    // 0x80801A2C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80801A30: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80801A34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801A38: jal         0x800897D8
    // 0x80801A3C: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_3;
    // 0x80801A3C: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    after_3:
L_80801A40:
    // 0x80801A40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801A44:
    // 0x80801A44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801A48: jr          $ra
    // 0x80801A4C: nop

    return;
    // 0x80801A4C: nop

;}
RECOMP_FUNC void chlagoonlockerdoorhits_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080037C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2032, 0X45C) << 16);
    // 0x80800380: jr          $ra
    // 0x80800384: addiu       $v0, $v0, 0x45C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2032, 0X45C));
    return;
    // 0x80800384: addiu       $v0, $v0, 0x45C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2032, 0X45C));
    // 0x80800388: nop

    // 0x8080038C: nop

;}
RECOMP_FUNC void func_800FBF9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FBF9C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800FBFA0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800FBFA4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800FBFA8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800FBFAC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800FBFB0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800FBFB4: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800FBFB8: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800FBFBC: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800FBFC0: lw          $s2, 0x0($a1)
    ctx->r18 = MEM_W(ctx->r5, 0X0);
    // 0x800FBFC4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800FBFC8: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x800FBFCC: lw          $s0, 0x0($a3)
    ctx->r16 = MEM_W(ctx->r7, 0X0);
    // 0x800FBFD0: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x800FBFD4: beq         $s0, $zero, L_800FBFF0
    if (ctx->r16 == 0) {
        // 0x800FBFD8: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_800FBFF0;
    }
    // 0x800FBFD8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800FBFDC: jal         0x800B31B8
    // 0x800FBFE0: lw          $a0, 0x38($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X38);
    freelist_is_element_alive(rdram, ctx);
        goto after_0;
    // 0x800FBFE0: lw          $a0, 0x38($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X38);
    after_0:
    // 0x800FBFE4: bne         $v0, $zero, L_800FBFF0
    if (ctx->r2 != 0) {
        // 0x800FBFE8: nop
    
            goto L_800FBFF0;
    }
    // 0x800FBFE8: nop

    // 0x800FBFEC: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
L_800FBFF0:
    // 0x800FBFF0: bgez        $s2, L_800FC074
    if (SIGNED(ctx->r18) >= 0) {
        // 0x800FBFF4: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_800FC074;
    }
    // 0x800FBFF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800FBFF8: jal         0x800B301C
    // 0x800FBFFC: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    freelist_at(rdram, ctx);
        goto after_1;
    // 0x800FBFFC: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    after_1:
    // 0x800FC000: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800FC004: jal         0x80017764
    // 0x800FC008: lh          $a0, 0x28($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X28);
    func_80017764(rdram, ctx);
        goto after_2;
    // 0x800FC008: lh          $a0, 0x28($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X28);
    after_2:
    // 0x800FC00C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800FC010: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800FC014: beq         $at, $zero, L_800FC02C
    if (ctx->r1 == 0) {
        // 0x800FC018: or          $s2, $v1, $zero
        ctx->r18 = ctx->r3 | 0;
            goto L_800FC02C;
    }
    // 0x800FC018: or          $s2, $v1, $zero
    ctx->r18 = ctx->r3 | 0;
    // 0x800FC01C: jal         0x80017764
    // 0x800FC020: lh          $a0, 0x28($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X28);
    func_80017764(rdram, ctx);
        goto after_3;
    // 0x800FC020: lh          $a0, 0x28($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X28);
    after_3:
    // 0x800FC024: b           L_800FC02C
    // 0x800FC028: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
        goto L_800FC02C;
    // 0x800FC028: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_800FC02C:
    // 0x800FC02C: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x800FC030: beq         $s0, $zero, L_800FC074
    if (ctx->r16 == 0) {
        // 0x800FC034: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_800FC074;
    }
    // 0x800FC034: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800FC038: jal         0x800B301C
    // 0x800FC03C: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    freelist_at(rdram, ctx);
        goto after_4;
    // 0x800FC03C: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    after_4:
    // 0x800FC040: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x800FC044: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x800FC048: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800FC04C: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    // 0x800FC050: jal         0x800B32C0
    // 0x800FC054: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    freelist_erase(rdram, ctx);
        goto after_5;
    // 0x800FC054: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    after_5:
    // 0x800FC058: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
    // 0x800FC05C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800FC060: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800FC064: jal         0x800FBEC8
    // 0x800FC068: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    func_800FBEC8(rdram, ctx);
        goto after_6;
    // 0x800FC068: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_6:
    // 0x800FC06C: b           L_800FC10C
    // 0x800FC070: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800FC10C;
    // 0x800FC070: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800FC074:
    // 0x800FC074: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x800FC078: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800FC07C: bne         $s0, $zero, L_800FC0DC
    if (ctx->r16 != 0) {
        // 0x800FC080: nop
    
            goto L_800FC0DC;
    }
    // 0x800FC080: nop

    // 0x800FC084: jal         0x800B301C
    // 0x800FC088: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    freelist_at(rdram, ctx);
        goto after_7;
    // 0x800FC088: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    after_7:
    // 0x800FC08C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800FC090: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800FC094: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800FC098: slt         $at, $v1, $s2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x800FC09C: bne         $at, $zero, L_800FC0BC
    if (ctx->r1 != 0) {
        // 0x800FC0A0: nop
    
            goto L_800FC0BC;
    }
    // 0x800FC0A0: nop

    // 0x800FC0A4: bne         $s2, $v1, L_800FC0CC
    if (ctx->r18 != ctx->r3) {
        // 0x800FC0A8: lw          $t1, 0x34($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X34);
            goto L_800FC0CC;
    }
    // 0x800FC0A8: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800FC0AC: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x800FC0B0: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800FC0B4: bnel        $at, $zero, L_800FC0D0
    if (ctx->r1 != 0) {
        // 0x800FC0B8: addiu       $a0, $s1, 0x38
        ctx->r4 = ADD32(ctx->r17, 0X38);
            goto L_800FC0D0;
    }
    goto skip_0;
    // 0x800FC0B8: addiu       $a0, $s1, 0x38
    ctx->r4 = ADD32(ctx->r17, 0X38);
    skip_0:
L_800FC0BC:
    // 0x800FC0BC: jal         0x800FB650
    // 0x800FC0C0: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    func_800FB650(rdram, ctx);
        goto after_8;
    // 0x800FC0C0: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    after_8:
    // 0x800FC0C4: b           L_800FC0DC
    // 0x800FC0C8: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
        goto L_800FC0DC;
    // 0x800FC0C8: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
L_800FC0CC:
    // 0x800FC0CC: addiu       $a0, $s1, 0x38
    ctx->r4 = ADD32(ctx->r17, 0X38);
L_800FC0D0:
    // 0x800FC0D0: jal         0x800B3044
    // 0x800FC0D4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    freelist_next(rdram, ctx);
        goto after_9;
    // 0x800FC0D4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_9:
    // 0x800FC0D8: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
L_800FC0DC:
    // 0x800FC0DC: beq         $s0, $zero, L_800FC0F8
    if (ctx->r16 == 0) {
        // 0x800FC0E0: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_800FC0F8;
    }
    // 0x800FC0E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800FC0E4: jal         0x800B301C
    // 0x800FC0E8: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    freelist_at(rdram, ctx);
        goto after_10;
    // 0x800FC0E8: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    after_10:
    // 0x800FC0EC: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x800FC0F0: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800FC0F4: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
L_800FC0F8:
    // 0x800FC0F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800FC0FC: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800FC100: jal         0x800FBEC8
    // 0x800FC104: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    func_800FBEC8(rdram, ctx);
        goto after_11;
    // 0x800FC104: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    after_11:
    // 0x800FC108: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800FC10C:
    // 0x800FC10C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800FC110: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800FC114: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800FC118: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800FC11C: jr          $ra
    // 0x800FC120: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800FC120: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void bsmummove_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800584: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800588: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(320, 0X5C0) << 16);
    // 0x8080058C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800590: jr          $ra
    // 0x80800594: lw          $v0, 0x5C0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(320, 0X5C0));
    return;
    // 0x80800594: lw          $v0, 0x5C0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(320, 0X5C0));
;}
RECOMP_FUNC void func_80105410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105410: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105414: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80105418: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    // 0x8010541C: jal         0x800B3268
    // 0x80105420: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    freelist_new(rdram, ctx);
        goto after_0;
    // 0x80105420: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x80105424: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80105428: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010542C: sw          $v0, 0x6EC0($at)
    MEM_W(0X6EC0, ctx->r1) = ctx->r2;
    // 0x80105430: jr          $ra
    // 0x80105434: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80105434: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8080000C_chlifeforcespell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800010: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1328, 0X4A8) << 16);
    // 0x80800014: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800018: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080001C: addiu       $t7, $t7, 0x4A8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1328, 0X4A8));
    // 0x80800020: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80800024: addiu       $t6, $sp, 0x2C
    ctx->r14 = ADD32(ctx->r29, 0X2C);
    // 0x80800028: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x8080002C: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80800030: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80800034: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800038: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    // 0x8080003C: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x80800040: jal         0x80086C68
    // 0x80800044: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    _chmumbopad_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800044: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    after_0:
    // 0x80800048: sll         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2 << 16);
    // 0x8080004C: sra         $t1, $a3, 16
    ctx->r9 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80800050: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800058: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080005C: jal         0x80089840
    // 0x80800060: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    _sumumbofx_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800060: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_1:
    // 0x80800064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800068: jal         0x80100094
    // 0x8080006C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x8080006C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800070: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800074: jal         0x80089850
    // 0x80800078: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800078: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800080: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    // 0x80800084: jal         0x80089908
    // 0x80800088: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    _sumumbofx_entrypoint_25(rdram, ctx);
        goto after_4;
    // 0x80800088: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_4:
    // 0x8080008C: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x80800090: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80800094: jal         0x80089900
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sumumbofx_entrypoint_24(rdram, ctx);
        goto after_5;
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080009C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A0: jal         0x800898B8
    // 0x808000A4: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    _sumumbofx_entrypoint_15(rdram, ctx);
        goto after_6;
    // 0x808000A4: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_6:
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000AC: jal         0x800898E0
    // 0x808000B0: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    _sumumbofx_entrypoint_20(rdram, ctx);
        goto after_7;
    // 0x808000B0: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_7:
    // 0x808000B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000BC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808000C0: jr          $ra
    // 0x808000C4: nop

    return;
    // 0x808000C4: nop

;}
RECOMP_FUNC void func_80116684(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80116684: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x80116688: mfc1        $t4, $f20
    ctx->r12 = (int32_t)ctx->f20.u32l;
    // 0x8011668C: mfc1        $t5, $f22
    ctx->r13 = (int32_t)ctx->f22.u32l;
    // 0x80116690: mfc1        $t6, $f24
    ctx->r14 = (int32_t)ctx->f24.u32l;
    // 0x80116694: mfc1        $t7, $f26
    ctx->r15 = (int32_t)ctx->f26.u32l;
    // 0x80116698: mfc1        $t8, $f28
    ctx->r24 = (int32_t)ctx->f28.u32l;
    // 0x8011669C: mfc1        $t9, $f30
    ctx->r25 = (int32_t)ctx->f30.u32l;
    // 0x801166A0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801166A4: lui         $t0, 0xFFFF
    ctx->r8 = S32(0XFFFF << 16);
    // 0x801166A8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_801166AC:
    // 0x801166AC: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x801166B0: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x801166B4: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x801166B8: mul.s       $f26, $f0, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f26.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x801166BC: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x801166C0: lwc1        $f10, 0x14($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X14);
    // 0x801166C4: mul.s       $f28, $f0, $f4
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f28.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801166C8: lwc1        $f12, 0x18($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X18);
    // 0x801166CC: lwc1        $f14, 0x20($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X20);
    // 0x801166D0: mul.s       $f30, $f0, $f6
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f30.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x801166D4: lwc1        $f16, 0x24($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X24);
    // 0x801166D8: lwc1        $f18, 0x28($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X28);
    // 0x801166DC: lwc1        $f20, 0x30($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X30);
    // 0x801166E0: lwc1        $f22, 0x34($a0)
    ctx->f22.u32l = MEM_W(ctx->r4, 0X34);
    // 0x801166E4: lwc1        $f24, 0x38($a0)
    ctx->f24.u32l = MEM_W(ctx->r4, 0X38);
    // 0x801166E8: cvt.w.s     $f26, $f26
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    ctx->f26.u32l = CVT_W_S(ctx->f26.fl);
    // 0x801166EC: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x801166F0: sh          $zero, 0x26($a1)
    MEM_H(0X26, ctx->r5) = 0;
    // 0x801166F4: cvt.w.s     $f28, $f28
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    ctx->f28.u32l = CVT_W_S(ctx->f28.fl);
    // 0x801166F8: mfc1        $t1, $f26
    ctx->r9 = (int32_t)ctx->f26.u32l;
    // 0x801166FC: mul.s       $f26, $f0, $f8
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f26.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80116700: cvt.w.s     $f30, $f30
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    ctx->f30.u32l = CVT_W_S(ctx->f30.fl);
    // 0x80116704: sh          $t1, 0x20($a1)
    MEM_H(0X20, ctx->r5) = ctx->r9;
    // 0x80116708: srl         $t1, $t1, 16
    ctx->r9 = S32(U32(ctx->r9) >> 16);
    // 0x8011670C: sh          $t1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r9;
    // 0x80116710: mfc1        $t1, $f28
    ctx->r9 = (int32_t)ctx->f28.u32l;
    // 0x80116714: mul.s       $f28, $f0, $f10
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f28.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80116718: cvt.w.s     $f26, $f26
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    ctx->f26.u32l = CVT_W_S(ctx->f26.fl);
    // 0x8011671C: sh          $t1, 0x22($a1)
    MEM_H(0X22, ctx->r5) = ctx->r9;
    // 0x80116720: srl         $t1, $t1, 16
    ctx->r9 = S32(U32(ctx->r9) >> 16);
    // 0x80116724: sh          $t1, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r9;
    // 0x80116728: mfc1        $t1, $f30
    ctx->r9 = (int32_t)ctx->f30.u32l;
    // 0x8011672C: mul.s       $f30, $f0, $f12
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f30.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80116730: cvt.w.s     $f28, $f28
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    ctx->f28.u32l = CVT_W_S(ctx->f28.fl);
    // 0x80116734: sh          $t1, 0x24($a1)
    MEM_H(0X24, ctx->r5) = ctx->r9;
    // 0x80116738: srl         $t1, $t1, 16
    ctx->r9 = S32(U32(ctx->r9) >> 16);
    // 0x8011673C: sh          $t1, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r9;
    // 0x80116740: mfc1        $t1, $f26
    ctx->r9 = (int32_t)ctx->f26.u32l;
    // 0x80116744: mul.s       $f26, $f0, $f14
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f26.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x80116748: cvt.w.s     $f30, $f30
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    ctx->f30.u32l = CVT_W_S(ctx->f30.fl);
    // 0x8011674C: sh          $t1, 0x28($a1)
    MEM_H(0X28, ctx->r5) = ctx->r9;
    // 0x80116750: srl         $t1, $t1, 16
    ctx->r9 = S32(U32(ctx->r9) >> 16);
    // 0x80116754: sh          $t1, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r9;
    // 0x80116758: mfc1        $t1, $f28
    ctx->r9 = (int32_t)ctx->f28.u32l;
    // 0x8011675C: mul.s       $f28, $f0, $f16
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f28.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80116760: cvt.w.s     $f26, $f26
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    ctx->f26.u32l = CVT_W_S(ctx->f26.fl);
    // 0x80116764: sh          $t1, 0x2A($a1)
    MEM_H(0X2A, ctx->r5) = ctx->r9;
    // 0x80116768: srl         $t1, $t1, 16
    ctx->r9 = S32(U32(ctx->r9) >> 16);
    // 0x8011676C: sh          $t1, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r9;
    // 0x80116770: mfc1        $t1, $f30
    ctx->r9 = (int32_t)ctx->f30.u32l;
    // 0x80116774: mul.s       $f30, $f0, $f18
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f30.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80116778: cvt.w.s     $f28, $f28
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    ctx->f28.u32l = CVT_W_S(ctx->f28.fl);
    // 0x8011677C: sh          $t1, 0x2C($a1)
    MEM_H(0X2C, ctx->r5) = ctx->r9;
    // 0x80116780: srl         $t1, $t1, 16
    ctx->r9 = S32(U32(ctx->r9) >> 16);
    // 0x80116784: sh          $t1, 0xC($a1)
    MEM_H(0XC, ctx->r5) = ctx->r9;
    // 0x80116788: mfc1        $t1, $f26
    ctx->r9 = (int32_t)ctx->f26.u32l;
    // 0x8011678C: mul.s       $f26, $f0, $f20
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f26.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80116790: cvt.w.s     $f30, $f30
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    ctx->f30.u32l = CVT_W_S(ctx->f30.fl);
    // 0x80116794: sh          $t1, 0x30($a1)
    MEM_H(0X30, ctx->r5) = ctx->r9;
    // 0x80116798: srl         $t1, $t1, 16
    ctx->r9 = S32(U32(ctx->r9) >> 16);
    // 0x8011679C: sh          $t1, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r9;
    // 0x801167A0: mfc1        $t1, $f28
    ctx->r9 = (int32_t)ctx->f28.u32l;
    // 0x801167A4: mul.s       $f28, $f0, $f22
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f28.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x801167A8: cvt.w.s     $f26, $f26
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    ctx->f26.u32l = CVT_W_S(ctx->f26.fl);
    // 0x801167AC: sh          $t1, 0x32($a1)
    MEM_H(0X32, ctx->r5) = ctx->r9;
    // 0x801167B0: srl         $t1, $t1, 16
    ctx->r9 = S32(U32(ctx->r9) >> 16);
    // 0x801167B4: sh          $t1, 0x12($a1)
    MEM_H(0X12, ctx->r5) = ctx->r9;
    // 0x801167B8: mfc1        $t1, $f30
    ctx->r9 = (int32_t)ctx->f30.u32l;
    // 0x801167BC: mul.s       $f30, $f0, $f24
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f30.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x801167C0: cvt.w.s     $f28, $f28
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    ctx->f28.u32l = CVT_W_S(ctx->f28.fl);
    // 0x801167C4: sh          $t1, 0x34($a1)
    MEM_H(0X34, ctx->r5) = ctx->r9;
    // 0x801167C8: srl         $t1, $t1, 16
    ctx->r9 = S32(U32(ctx->r9) >> 16);
    // 0x801167CC: sh          $t1, 0x14($a1)
    MEM_H(0X14, ctx->r5) = ctx->r9;
    // 0x801167D0: mfc1        $t1, $f26
    ctx->r9 = (int32_t)ctx->f26.u32l;
    // 0x801167D4: sh          $zero, 0x6($a1)
    MEM_H(0X6, ctx->r5) = 0;
    // 0x801167D8: cvt.w.s     $f30, $f30
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    ctx->f30.u32l = CVT_W_S(ctx->f30.fl);
    // 0x801167DC: sh          $t1, 0x38($a1)
    MEM_H(0X38, ctx->r5) = ctx->r9;
    // 0x801167E0: srl         $t1, $t1, 16
    ctx->r9 = S32(U32(ctx->r9) >> 16);
    // 0x801167E4: sh          $t1, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r9;
    // 0x801167E8: mfc1        $t1, $f28
    ctx->r9 = (int32_t)ctx->f28.u32l;
    // 0x801167EC: sh          $zero, 0x2E($a1)
    MEM_H(0X2E, ctx->r5) = 0;
    // 0x801167F0: sh          $zero, 0xE($a1)
    MEM_H(0XE, ctx->r5) = 0;
    // 0x801167F4: sh          $t1, 0x3A($a1)
    MEM_H(0X3A, ctx->r5) = ctx->r9;
    // 0x801167F8: srl         $t1, $t1, 16
    ctx->r9 = S32(U32(ctx->r9) >> 16);
    // 0x801167FC: sh          $t1, 0x1A($a1)
    MEM_H(0X1A, ctx->r5) = ctx->r9;
    // 0x80116800: mfc1        $t1, $f30
    ctx->r9 = (int32_t)ctx->f30.u32l;
    // 0x80116804: sh          $zero, 0x36($a1)
    MEM_H(0X36, ctx->r5) = 0;
    // 0x80116808: sh          $zero, 0x16($a1)
    MEM_H(0X16, ctx->r5) = 0;
    // 0x8011680C: sh          $t1, 0x3C($a1)
    MEM_H(0X3C, ctx->r5) = ctx->r9;
    // 0x80116810: srl         $t1, $t1, 16
    ctx->r9 = S32(U32(ctx->r9) >> 16);
    // 0x80116814: sh          $t1, 0x1C($a1)
    MEM_H(0X1C, ctx->r5) = ctx->r9;
    // 0x80116818: sh          $zero, 0x3E($a1)
    MEM_H(0X3E, ctx->r5) = 0;
    // 0x8011681C: sh          $t3, 0x1E($a1)
    MEM_H(0X1E, ctx->r5) = ctx->r11;
    // 0x80116820: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    // 0x80116824: bne         $a2, $zero, L_801166AC
    if (ctx->r6 != 0) {
        // 0x80116828: addiu       $a1, $a1, 0x40
        ctx->r5 = ADD32(ctx->r5, 0X40);
            goto L_801166AC;
    }
    // 0x80116828: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    // 0x8011682C: mtc1        $t4, $f20
    ctx->f20.u32l = ctx->r12;
    // 0x80116830: mtc1        $t5, $f22
    ctx->f22.u32l = ctx->r13;
    // 0x80116834: mtc1        $t6, $f24
    ctx->f24.u32l = ctx->r14;
    // 0x80116838: mtc1        $t7, $f26
    ctx->f26.u32l = ctx->r15;
    // 0x8011683C: mtc1        $t8, $f28
    ctx->f28.u32l = ctx->r24;
    // 0x80116840: mtc1        $t9, $f30
    ctx->f30.u32l = ctx->r25;
    // 0x80116844: jr          $ra
    // 0x80116848: nop

    return;
    // 0x80116848: nop

    // 0x8011684C: nop

;}
RECOMP_FUNC void _idworldmake_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088F20: syscall     749
    recomp_syscall_handler(rdram, ctx, 0x80088F20);
    return;
    // 0x80088F24: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808031E4_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808031E4: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x808031E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808031EC: lwc1        $f4, 0x24($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X24);
    // 0x808031F0: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x808031F4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808031F8: div.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808031FC: mul.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80803200: jr          $ra
    // 0x80803204: nop

    return;
    // 0x80803204: nop

;}
RECOMP_FUNC void func_8010A570(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010A570: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010A574: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010A578: jal         0x8010A5B0
    // 0x8010A57C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8010A5B0(rdram, ctx);
        goto after_0;
    // 0x8010A57C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8010A580: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010A584: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010A588: jr          $ra
    // 0x8010A58C: nop

    return;
    // 0x8010A58C: nop

;}
RECOMP_FUNC void glsplineDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CD4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800CD8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800CDC: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800CE0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800CE4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800CE8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800CEC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800CF0: jal         0x8001B798
    // 0x80800CF4: lh          $a0, 0x184($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X184);
    func_8001B798(rdram, ctx);
        goto after_0;
    // 0x80800CF4: lh          $a0, 0x184($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X184);
    after_0:
    // 0x80800CF8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800CFC: jal         0x8001B798
    // 0x80800D00: lh          $a0, 0x186($s3)
    ctx->r4 = MEM_H(ctx->r19, 0X186);
    func_8001B798(rdram, ctx);
        goto after_1;
    // 0x80800D00: lh          $a0, 0x186($s3)
    ctx->r4 = MEM_H(ctx->r19, 0X186);
    after_1:
    // 0x80800D04: lw          $t6, 0x188($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X188);
    // 0x80800D08: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800D0C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800D10: blez        $t6, L_80800D50
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80800D14: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80800D50;
    }
    // 0x80800D14: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_80800D18:
    // 0x80800D18: jal         0x8001B798
    // 0x80800D1C: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    func_8001B798(rdram, ctx);
        goto after_2;
    // 0x80800D1C: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    after_2:
    // 0x80800D20: jal         0x8001B754
    // 0x80800D24: lh          $a0, 0x10($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X10);
    func_8001B754(rdram, ctx);
        goto after_3;
    // 0x80800D24: lh          $a0, 0x10($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X10);
    after_3:
    // 0x80800D28: jal         0x8001B754
    // 0x80800D2C: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    func_8001B754(rdram, ctx);
        goto after_4;
    // 0x80800D2C: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    after_4:
    // 0x80800D30: jal         0x8001B754
    // 0x80800D34: lh          $a0, 0x0($s2)
    ctx->r4 = MEM_H(ctx->r18, 0X0);
    func_8001B754(rdram, ctx);
        goto after_5;
    // 0x80800D34: lh          $a0, 0x0($s2)
    ctx->r4 = MEM_H(ctx->r18, 0X0);
    after_5:
    // 0x80800D38: lw          $t7, 0x188($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X188);
    // 0x80800D3C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800D40: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80800D44: slt         $at, $s1, $t7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80800D48: bne         $at, $zero, L_80800D18
    if (ctx->r1 != 0) {
        // 0x80800D4C: addiu       $s2, $s2, 0x2
        ctx->r18 = ADD32(ctx->r18, 0X2);
            goto L_80800D18;
    }
    // 0x80800D4C: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
L_80800D50:
    // 0x80800D50: jal         0x8001B754
    // 0x80800D54: lh          $a0, 0x184($s3)
    ctx->r4 = MEM_H(ctx->r19, 0X184);
    func_8001B754(rdram, ctx);
        goto after_6;
    // 0x80800D54: lh          $a0, 0x184($s3)
    ctx->r4 = MEM_H(ctx->r19, 0X184);
    after_6:
    // 0x80800D58: jal         0x8001B754
    // 0x80800D5C: lh          $a0, 0x186($s3)
    ctx->r4 = MEM_H(ctx->r19, 0X186);
    func_8001B754(rdram, ctx);
        goto after_7;
    // 0x80800D5C: lh          $a0, 0x186($s3)
    ctx->r4 = MEM_H(ctx->r19, 0X186);
    after_7:
    // 0x80800D60: sh          $zero, 0x184($s3)
    MEM_H(0X184, ctx->r19) = 0;
    // 0x80800D64: sh          $zero, 0x186($s3)
    MEM_H(0X186, ctx->r19) = 0;
    // 0x80800D68: jal         0x8001B084
    // 0x80800D6C: lw          $a0, 0x1A4($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X1A4);
    heap_free(rdram, ctx);
        goto after_8;
    // 0x80800D6C: lw          $a0, 0x1A4($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X1A4);
    after_8:
    // 0x80800D70: sw          $zero, 0x188($s3)
    MEM_W(0X188, ctx->r19) = 0;
    // 0x80800D74: sw          $zero, 0x1A4($s3)
    MEM_W(0X1A4, ctx->r19) = 0;
    // 0x80800D78: sw          $zero, 0x198($s3)
    MEM_W(0X198, ctx->r19) = 0;
    // 0x80800D7C: jal         0x8001B084
    // 0x80800D80: lw          $a0, 0x19C($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X19C);
    heap_free(rdram, ctx);
        goto after_9;
    // 0x80800D80: lw          $a0, 0x19C($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X19C);
    after_9:
    // 0x80800D84: sw          $zero, 0x19C($s3)
    MEM_W(0X19C, ctx->r19) = 0;
    // 0x80800D88: sw          $zero, 0x1A0($s3)
    MEM_W(0X1A0, ctx->r19) = 0;
    // 0x80800D8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800D90: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800D94: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D98: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800D9C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800DA0: jr          $ra
    // 0x80800DA4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800DA4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void gcmapsects_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801AF8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801AFC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801B00: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801B04: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801B08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80801B0C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80801B10: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80801B14: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801B18: sw          $zero, 0x68($a0)
    MEM_W(0X68, ctx->r4) = 0;
    // 0x80801B1C: sb          $zero, 0x77($a0)
    MEM_B(0X77, ctx->r4) = 0;
    // 0x80801B20: sb          $zero, 0x76($a0)
    MEM_B(0X76, ctx->r4) = 0;
    // 0x80801B24: sb          $zero, 0x78($a0)
    MEM_B(0X78, ctx->r4) = 0;
    // 0x80801B28: sb          $zero, 0x7C($a0)
    MEM_B(0X7C, ctx->r4) = 0;
    // 0x80801B2C: sb          $v0, 0x7B($a0)
    MEM_B(0X7B, ctx->r4) = ctx->r2;
    // 0x80801B30: sb          $v0, 0x7E($a0)
    MEM_B(0X7E, ctx->r4) = ctx->r2;
    // 0x80801B34: sb          $v0, 0x7A($a0)
    MEM_B(0X7A, ctx->r4) = ctx->r2;
    // 0x80801B38: sb          $t6, 0x7F($a0)
    MEM_B(0X7F, ctx->r4) = ctx->r14;
    // 0x80801B3C: sh          $t7, 0x74($a0)
    MEM_H(0X74, ctx->r4) = ctx->r15;
    // 0x80801B40: sb          $zero, 0x82($a0)
    MEM_B(0X82, ctx->r4) = 0;
    // 0x80801B44: sw          $zero, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = 0;
    // 0x80801B48: sb          $zero, 0x79($a0)
    MEM_B(0X79, ctx->r4) = 0;
    // 0x80801B4C: sb          $zero, 0x7D($a0)
    MEM_B(0X7D, ctx->r4) = 0;
    // 0x80801B50: sb          $zero, 0x80($a0)
    MEM_B(0X80, ctx->r4) = 0;
    // 0x80801B54: sb          $zero, 0x81($a0)
    MEM_B(0X81, ctx->r4) = 0;
    // 0x80801B58: jal         0x800EA05C
    // 0x80801B5C: swc1        $f4, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f4.u32l;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80801B5C: swc1        $f4, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f4.u32l;
    after_0:
    // 0x80801B60: addiu       $at, $zero, 0x1A7
    ctx->r1 = ADD32(0, 0X1A7);
    // 0x80801B64: beq         $v0, $at, L_80801B84
    if (ctx->r2 == ctx->r1) {
        // 0x80801B68: addiu       $at, $zero, 0x1A8
        ctx->r1 = ADD32(0, 0X1A8);
            goto L_80801B84;
    }
    // 0x80801B68: addiu       $at, $zero, 0x1A8
    ctx->r1 = ADD32(0, 0X1A8);
    // 0x80801B6C: beq         $v0, $at, L_80801B98
    if (ctx->r2 == ctx->r1) {
        // 0x80801B70: addiu       $at, $zero, 0x1A9
        ctx->r1 = ADD32(0, 0X1A9);
            goto L_80801B98;
    }
    // 0x80801B70: addiu       $at, $zero, 0x1A9
    ctx->r1 = ADD32(0, 0X1A9);
    // 0x80801B74: beq         $v0, $at, L_80801BAC
    if (ctx->r2 == ctx->r1) {
        // 0x80801B78: nop
    
            goto L_80801BAC;
    }
    // 0x80801B78: nop

    // 0x80801B7C: b           L_80801BC0
    // 0x80801B80: lbu         $v0, 0x77($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X77);
        goto L_80801BC0;
    // 0x80801B80: lbu         $v0, 0x77($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X77);
L_80801B84:
    // 0x80801B84: jal         0x80087FE0
    // 0x80801B88: nop

    _gcmapsects_lagoontop_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80801B88: nop

    after_1:
    // 0x80801B8C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80801B90: b           L_80801BBC
    // 0x80801B94: sb          $t8, 0x83($s0)
    MEM_B(0X83, ctx->r16) = ctx->r24;
        goto L_80801BBC;
    // 0x80801B94: sb          $t8, 0x83($s0)
    MEM_B(0X83, ctx->r16) = ctx->r24;
L_80801B98:
    // 0x80801B98: jal         0x80087FF0
    // 0x80801B9C: nop

    _gcmapsects_lagoonmid_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80801B9C: nop

    after_2:
    // 0x80801BA0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80801BA4: b           L_80801BBC
    // 0x80801BA8: sb          $t9, 0x83($s0)
    MEM_B(0X83, ctx->r16) = ctx->r25;
        goto L_80801BBC;
    // 0x80801BA8: sb          $t9, 0x83($s0)
    MEM_B(0X83, ctx->r16) = ctx->r25;
L_80801BAC:
    // 0x80801BAC: jal         0x80088000
    // 0x80801BB0: nop

    _gcmapsects_lagoonbot_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80801BB0: nop

    after_3:
    // 0x80801BB4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80801BB8: sb          $t0, 0x83($s0)
    MEM_B(0X83, ctx->r16) = ctx->r8;
L_80801BBC:
    // 0x80801BBC: lbu         $v0, 0x77($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X77);
L_80801BC0:
    // 0x80801BC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801BC4: beq         $v0, $zero, L_80801BD8
    if (ctx->r2 == 0) {
        // 0x80801BC8: nop
    
            goto L_80801BD8;
    }
    // 0x80801BC8: nop

    // 0x80801BCC: jal         0x80801724
    // 0x80801BD0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801724_gcmapsects(rdram, ctx);
        goto after_4;
    // 0x80801BD0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80801BD4: lbu         $v0, 0x77($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X77);
L_80801BD8:
    // 0x80801BD8: blez        $v0, L_80801C74
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80801BDC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80801C74;
    }
    // 0x80801BDC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801BE0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80801BE4: lw          $t1, 0x68($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X68);
L_80801BE8:
    // 0x80801BE8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80801BEC: addu        $v0, $t1, $v1
    ctx->r2 = ADD32(ctx->r9, ctx->r3);
    // 0x80801BF0: lbu         $t2, 0x4C($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X4C);
    // 0x80801BF4: andi        $t3, $t2, 0xFF7F
    ctx->r11 = ctx->r10 & 0XFF7F;
    // 0x80801BF8: sb          $t3, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r11;
    // 0x80801BFC: lw          $t4, 0x68($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X68);
    // 0x80801C00: addu        $v0, $t4, $v1
    ctx->r2 = ADD32(ctx->r12, ctx->r3);
    // 0x80801C04: lbu         $t6, 0x4C($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X4C);
    // 0x80801C08: ori         $t7, $t6, 0x40
    ctx->r15 = ctx->r14 | 0X40;
    // 0x80801C0C: sb          $t7, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r15;
    // 0x80801C10: lw          $t8, 0x68($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X68);
    // 0x80801C14: addu        $v0, $t8, $v1
    ctx->r2 = ADD32(ctx->r24, ctx->r3);
    // 0x80801C18: lw          $t9, 0x4C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4C);
    // 0x80801C1C: lbu         $t4, 0x4C($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X4C);
    // 0x80801C20: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80801C24: srl         $t1, $t0, 31
    ctx->r9 = S32(U32(ctx->r8) >> 31);
    // 0x80801C28: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80801C2C: andi        $t3, $t2, 0x4
    ctx->r11 = ctx->r10 & 0X4;
    // 0x80801C30: andi        $t5, $t4, 0xFFFB
    ctx->r13 = ctx->r12 & 0XFFFB;
    // 0x80801C34: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x80801C38: sb          $t6, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r14;
    // 0x80801C3C: lw          $t7, 0x68($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X68);
    // 0x80801C40: lbu         $t9, 0x83($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X83);
    // 0x80801C44: addu        $v0, $t7, $v1
    ctx->r2 = ADD32(ctx->r15, ctx->r3);
    // 0x80801C48: lbu         $t2, 0x4C($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X4C);
    // 0x80801C4C: sll         $t0, $t9, 5
    ctx->r8 = S32(ctx->r25 << 5);
    // 0x80801C50: andi        $t1, $t0, 0x20
    ctx->r9 = ctx->r8 & 0X20;
    // 0x80801C54: andi        $t4, $t2, 0xFFDF
    ctx->r12 = ctx->r10 & 0XFFDF;
    // 0x80801C58: or          $t3, $t1, $t4
    ctx->r11 = ctx->r9 | ctx->r12;
    // 0x80801C5C: sb          $t3, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r11;
    // 0x80801C60: lbu         $t5, 0x77($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X77);
    // 0x80801C64: addiu       $v1, $v1, 0x58
    ctx->r3 = ADD32(ctx->r3, 0X58);
    // 0x80801C68: slt         $at, $a0, $t5
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80801C6C: bnel        $at, $zero, L_80801BE8
    if (ctx->r1 != 0) {
        // 0x80801C70: lw          $t1, 0x68($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X68);
            goto L_80801BE8;
    }
    goto skip_0;
    // 0x80801C70: lw          $t1, 0x68($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X68);
    skip_0:
L_80801C74:
    // 0x80801C74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C78: jal         0x80800A08
    // 0x80801C7C: lbu         $a1, 0x83($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X83);
    func_80800A08_gcmapsects(rdram, ctx);
        goto after_5;
    // 0x80801C7C: lbu         $a1, 0x83($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X83);
    after_5:
    // 0x80801C80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801C84: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801C88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801C8C: jr          $ra
    // 0x80801C90: nop

    return;
    // 0x80801C90: nop

;}
RECOMP_FUNC void func_800006D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800006D4: addiu       $sp, $sp, -0xA90
    ctx->r29 = ADD32(ctx->r29, -0XA90);
    // 0x800006D8: sw          $s0, 0xA48($sp)
    MEM_W(0XA48, ctx->r29) = ctx->r16;
    // 0x800006DC: sw          $s1, 0xA4C($sp)
    MEM_W(0XA4C, ctx->r29) = ctx->r17;
    // 0x800006E0: sw          $s2, 0xA50($sp)
    MEM_W(0XA50, ctx->r29) = ctx->r18;
    // 0x800006E4: sw          $s3, 0xA54($sp)
    MEM_W(0XA54, ctx->r29) = ctx->r19;
    // 0x800006E8: sw          $s4, 0xA58($sp)
    MEM_W(0XA58, ctx->r29) = ctx->r20;
    // 0x800006EC: sw          $s5, 0xA5C($sp)
    MEM_W(0XA5C, ctx->r29) = ctx->r21;
    // 0x800006F0: sw          $s6, 0xA60($sp)
    MEM_W(0XA60, ctx->r29) = ctx->r22;
    // 0x800006F4: sw          $s7, 0xA64($sp)
    MEM_W(0XA64, ctx->r29) = ctx->r23;
    // 0x800006F8: sw          $fp, 0xA78($sp)
    MEM_W(0XA78, ctx->r29) = ctx->r30;
    // 0x800006FC: sw          $gp, 0xA7C($sp)
    MEM_W(0XA7C, ctx->r29) = ctx->r28;
    // 0x80000700: sw          $ra, 0xA80($sp)
    MEM_W(0XA80, ctx->r29) = ctx->r31;
    // 0x80000704: sw          $zero, 0xA84($sp)
    MEM_W(0XA84, ctx->r29) = 0;
    // 0x80000708: sw          $zero, 0xA88($sp)
    MEM_W(0XA88, ctx->r29) = 0;
    // 0x8000070C: addiu       $s7, $a0, 0x2
    ctx->r23 = ADD32(ctx->r4, 0X2);
    // 0x80000710: mtc1        $a1, $f16
    ctx->f16.u32l = ctx->r5;
    // 0x80000714: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x80000718: mtc1        $zero, $f17
    ctx->f_odd[(17 - 1) * 2] = 0;
    // 0x8000071C: lui         $t2, 0x7000
    ctx->r10 = S32(0X7000 << 16);
    // 0x80000720: subu        $t0, $a0, $a1
    ctx->r8 = SUB32(ctx->r4, ctx->r5);
    // 0x80000724: bgtzl       $t0, L_8000072C
    if (SIGNED(ctx->r8) > 0) {
        // 0x80000728: or          $t2, $t0, $zero
        ctx->r10 = ctx->r8 | 0;
            goto L_8000072C;
    }
    goto skip_0;
    // 0x80000728: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
    skip_0:
L_8000072C:
    // 0x8000072C: subu        $t0, $a2, $a1
    ctx->r8 = SUB32(ctx->r6, ctx->r5);
    // 0x80000730: bltz        $t0, L_80000744
    if (SIGNED(ctx->r8) < 0) {
        // 0x80000734: slt         $at, $t0, $t2
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_80000744;
    }
    // 0x80000734: slt         $at, $t0, $t2
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80000738: beq         $at, $zero, L_80000744
    if (ctx->r1 == 0) {
        // 0x8000073C: nop
    
            goto L_80000744;
    }
    // 0x8000073C: nop

    // 0x80000740: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
L_80000744:
    // 0x80000744: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80000748: jal         0x800007AC
    // 0x8000074C: nop

    boot_inflate(rdram, ctx);
        goto after_0;
    // 0x8000074C: nop

    after_0:
    // 0x80000750: bne         $v0, $zero, L_800007A4
    if (ctx->r2 != 0) {
        // 0x80000754: mfc1        $v0, $f17
        ctx->r2 = (int32_t)ctx->f_odd[(17 - 1) * 2];
            goto L_800007A4;
    }
    // 0x80000754: mfc1        $v0, $f17
    ctx->r2 = (int32_t)ctx->f_odd[(17 - 1) * 2];
L_80000758:
    // 0x80000758: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x8000075C: addiu       $t0, $t0, 0x4240
    ctx->r8 = ADD32(ctx->r8, 0X4240);
    // 0x80000760: lw          $t1, 0xA84($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA84);
    // 0x80000764: lw          $t2, 0xA88($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA88);
    // 0x80000768: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x8000076C: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x80000770: lw          $s0, 0xA48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XA48);
    // 0x80000774: lw          $s1, 0xA4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XA4C);
    // 0x80000778: lw          $s2, 0xA50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA50);
    // 0x8000077C: lw          $s3, 0xA54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XA54);
    // 0x80000780: lw          $s4, 0xA58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XA58);
    // 0x80000784: lw          $s5, 0xA5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XA5C);
    // 0x80000788: lw          $s6, 0xA60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XA60);
    // 0x8000078C: lw          $s7, 0xA64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XA64);
    // 0x80000790: lw          $fp, 0xA78($sp)
    ctx->r30 = MEM_W(ctx->r29, 0XA78);
    // 0x80000794: lw          $gp, 0xA7C($sp)
    ctx->r28 = MEM_W(ctx->r29, 0XA7C);
    // 0x80000798: lw          $ra, 0xA80($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA80);
    // 0x8000079C: jr          $ra
    // 0x800007A0: addiu       $sp, $sp, 0xA90
    ctx->r29 = ADD32(ctx->r29, 0XA90);
    return;
    // 0x800007A0: addiu       $sp, $sp, 0xA90
    ctx->r29 = ADD32(ctx->r29, 0XA90);
L_800007A4:
    // 0x800007A4: j           L_80000758
    // 0x800007A8: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
        goto L_80000758;
    // 0x800007A8: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800C9D38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9D38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C9D3C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800C9D40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9D44: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800C9D48: jal         0x800C9DE4
    // 0x800C9D4C: addiu       $a1, $a1, -0x6550
    ctx->r5 = ADD32(ctx->r5, -0X6550);
    func_800C9DE4(rdram, ctx);
        goto after_0;
    // 0x800C9D4C: addiu       $a1, $a1, -0x6550
    ctx->r5 = ADD32(ctx->r5, -0X6550);
    after_0:
    // 0x800C9D50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C9D54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C9D58: jr          $ra
    // 0x800C9D5C: nop

    return;
    // 0x800C9D5C: nop

;}
RECOMP_FUNC void func_80800EE0_chtransparentfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EE0: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(2232, 0X10E0) << 16);
    // 0x80800EE4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2232, 0X11D0) << 16);
    // 0x80800EE8: addiu       $v0, $v0, 0x11D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2232, 0X11D0));
    // 0x80800EEC: addiu       $v1, $v1, 0x10E0
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(2232, 0X10E0));
    // 0x80800EF0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_80800EF4:
    // 0x80800EF4: bnel        $a0, $t6, L_80800F08
    if (ctx->r4 != ctx->r14) {
        // 0x80800EF8: lw          $t7, 0xC($v1)
        ctx->r15 = MEM_W(ctx->r3, 0XC);
            goto L_80800F08;
    }
    goto skip_0;
    // 0x80800EF8: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    skip_0:
    // 0x80800EFC: jr          $ra
    // 0x80800F00: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    return;
    // 0x80800F00: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x80800F04: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
L_80800F08:
    // 0x80800F08: bnel        $a0, $t7, L_80800F1C
    if (ctx->r4 != ctx->r15) {
        // 0x80800F0C: lw          $t8, 0x18($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X18);
            goto L_80800F1C;
    }
    goto skip_1;
    // 0x80800F0C: lw          $t8, 0x18($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X18);
    skip_1:
    // 0x80800F10: jr          $ra
    // 0x80800F14: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    return;
    // 0x80800F14: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x80800F18: lw          $t8, 0x18($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X18);
L_80800F1C:
    // 0x80800F1C: bnel        $a0, $t8, L_80800F30
    if (ctx->r4 != ctx->r24) {
        // 0x80800F20: lw          $t9, 0x24($v1)
        ctx->r25 = MEM_W(ctx->r3, 0X24);
            goto L_80800F30;
    }
    goto skip_2;
    // 0x80800F20: lw          $t9, 0x24($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X24);
    skip_2:
    // 0x80800F24: jr          $ra
    // 0x80800F28: lw          $v0, 0x20($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X20);
    return;
    // 0x80800F28: lw          $v0, 0x20($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X20);
    // 0x80800F2C: lw          $t9, 0x24($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X24);
L_80800F30:
    // 0x80800F30: bnel        $a0, $t9, L_80800F44
    if (ctx->r4 != ctx->r25) {
        // 0x80800F34: addiu       $v1, $v1, 0x30
        ctx->r3 = ADD32(ctx->r3, 0X30);
            goto L_80800F44;
    }
    goto skip_3;
    // 0x80800F34: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    skip_3:
    // 0x80800F38: jr          $ra
    // 0x80800F3C: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
    return;
    // 0x80800F3C: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
    // 0x80800F40: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
L_80800F44:
    // 0x80800F44: bnel        $v1, $v0, L_80800EF4
    if (ctx->r3 != ctx->r2) {
        // 0x80800F48: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_80800EF4;
    }
    goto skip_4;
    // 0x80800F48: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_4:
    // 0x80800F4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800F50: jr          $ra
    // 0x80800F54: nop

    return;
    // 0x80800F54: nop

    // 0x80800F58: nop

    // 0x80800F5C: nop

;}
RECOMP_FUNC void func_80802FE4_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802FE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802FE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802FEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80802FF0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80802FF4: jal         0x80100074
    // 0x80802FF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80100074(rdram, ctx);
        goto after_0;
    // 0x80802FF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80802FFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80803000: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80803004: lbu         $t6, 0x65($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X65);
    // 0x80803008: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // 0x8080300C: sw          $zero, 0x28($a0)
    MEM_W(0X28, ctx->r4) = 0;
    // 0x80803010: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x80803014: jal         0x80087CC8
    // 0x80803018: sb          $t7, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r15;
    _gcnewoption_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80803018: sb          $t7, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r15;
    after_1:
    // 0x8080301C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80803020: jal         0x80106790
    // 0x80803024: lw          $a0, 0x3C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X3C);
    func_80106790(rdram, ctx);
        goto after_2;
    // 0x80803024: lw          $a0, 0x3C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X3C);
    after_2:
    // 0x80803028: lw          $a0, 0x24($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X24);
    // 0x8080302C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80803030: jal         0x80802640
    // 0x80803034: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80802640_chgameselect(rdram, ctx);
        goto after_3;
    // 0x80803034: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80803038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080303C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803040: jr          $ra
    // 0x80803044: nop

    return;
    // 0x80803044: nop

;}
RECOMP_FUNC void func_80101080(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101080: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80101084: jr          $ra
    // 0x80101088: lw          $v0, 0x5A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5A80);
    return;
    // 0x80101088: lw          $v0, 0x5A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5A80);
;}
RECOMP_FUNC void func_808001D4_chklungoforcefield(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001DC: lw          $a1, 0x18($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X18);
    // 0x808001E0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x808001E4: beq         $a1, $zero, L_808001FC
    if (ctx->r5 == 0) {
        // 0x808001E8: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_808001FC;
    }
    // 0x808001E8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x808001EC: jal         0x800C8B84
    // 0x808001F0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800C8B84(rdram, ctx);
        goto after_0;
    // 0x808001F0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x808001F4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808001F8: sw          $zero, 0x18($a2)
    MEM_W(0X18, ctx->r6) = 0;
L_808001FC:
    // 0x808001FC: lbu         $a0, 0x24($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X24);
    // 0x80800200: beql        $a0, $zero, L_8080021C
    if (ctx->r4 == 0) {
        // 0x80800204: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080021C;
    }
    goto skip_0;
    // 0x80800204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800208: jal         0x800E8C08
    // 0x8080020C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800E8C08(rdram, ctx);
        goto after_1;
    // 0x8080020C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x80800210: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800214: sb          $zero, 0x24($a2)
    MEM_B(0X24, ctx->r6) = 0;
    // 0x80800218: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080021C:
    // 0x8080021C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800220: jr          $ra
    // 0x80800224: nop

    return;
    // 0x80800224: nop

;}
RECOMP_FUNC void func_808007EC_chfireicestorm(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007EC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808007F0: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x808007F4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x808007F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808007FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800800: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800804: jal         0x800EE7F8
    // 0x80800808: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800808: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    after_0:
    // 0x8080080C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80800810: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800814: jal         0x800EE7F8
    // 0x80800818: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800818: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    after_1:
    // 0x8080081C: addiu       $a0, $zero, 0x4FD
    ctx->r4 = ADD32(0, 0X4FD);
    // 0x80800820: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800824: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800828: jal         0x80108528
    // 0x8080082C: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    func_80108528(rdram, ctx);
        goto after_2;
    // 0x8080082C: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    after_2:
    // 0x80800830: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80800834: lbu         $t8, 0x65($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X65);
    // 0x80800838: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080083C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80800840: andi        $t1, $t8, 0xFFEF
    ctx->r9 = ctx->r24 & 0XFFEF;
    // 0x80800844: sb          $t1, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r9;
    // 0x80800848: ori         $t2, $t1, 0x8
    ctx->r10 = ctx->r9 | 0X8;
    // 0x8080084C: sb          $t2, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r10;
    // 0x80800850: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800854: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80800858: jal         0x80102FDC
    // 0x8080085C: sw          $t7, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r15;
    func_80102FDC(rdram, ctx);
        goto after_3;
    // 0x8080085C: sw          $t7, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r15;
    after_3:
    // 0x80800860: jal         0x8010A570
    // 0x80800864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_4;
    // 0x80800864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800868: jal         0x8008A490
    // 0x8080086C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieDll_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x8080086C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800870: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x80800874: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800878: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x8080087C: jal         0x800EFB24
    // 0x80800880: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_800EFB24(rdram, ctx);
        goto after_6;
    // 0x80800880: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_6:
    // 0x80800884: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800888: jal         0x800EF368
    // 0x8080088C: lui         $a1, 0x44FA
    ctx->r5 = S32(0X44FA << 16);
    func_800EF368(rdram, ctx);
        goto after_7;
    // 0x8080088C: lui         $a1, 0x44FA
    ctx->r5 = S32(0X44FA << 16);
    after_7:
    // 0x80800890: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800894: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800898: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8080089C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808008A0: jal         0x800DC178
    // 0x808008A4: nop

    func_800DC178(rdram, ctx);
        goto after_8;
    // 0x808008A4: nop

    after_8:
    // 0x808008A8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808008AC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808008B0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x808008B4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808008B8: jal         0x800DC178
    // 0x808008BC: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_9;
    // 0x808008BC: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_9:
    // 0x808008C0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808008C4: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x808008C8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808008CC: jal         0x800EFA4C
    // 0x808008D0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_800EFA4C(rdram, ctx);
        goto after_10;
    // 0x808008D0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_10:
    // 0x808008D4: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x808008D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008DC: addiu       $a1, $zero, 0x815
    ctx->r5 = ADD32(0, 0X815);
    // 0x808008E0: jal         0x80103140
    // 0x808008E4: lhu         $a2, 0x16($t3)
    ctx->r6 = MEM_HU(ctx->r11, 0X16);
    func_80103140(rdram, ctx);
        goto after_11;
    // 0x808008E4: lhu         $a2, 0x16($t3)
    ctx->r6 = MEM_HU(ctx->r11, 0X16);
    after_11:
    // 0x808008E8: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
    // 0x808008EC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x808008F0: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x808008F4: sll         $t6, $t4, 12
    ctx->r14 = S32(ctx->r12 << 12);
    // 0x808008F8: bltzl       $t6, L_8080091C
    if (SIGNED(ctx->r14) < 0) {
        // 0x808008FC: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_8080091C;
    }
    goto skip_0;
    // 0x808008FC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x80800900: lw          $a1, 0x70($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X70);
    // 0x80800904: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1528, 0XE80) << 16);
    // 0x80800908: addiu       $a3, $a3, 0xE80
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1528, 0XE80));
    // 0x8080090C: andi        $t7, $a1, 0x1
    ctx->r15 = ctx->r5 & 0X1;
    // 0x80800910: jal         0x8010D930
    // 0x80800914: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    func_8010D930(rdram, ctx);
        goto after_12;
    // 0x80800914: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_12:
    // 0x80800918: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_8080091C:
    // 0x8080091C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800920: addiu       $a2, $zero, 0x27
    ctx->r6 = ADD32(0, 0X27);
    // 0x80800924: jal         0x80085708
    // 0x80800928: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    _capod_entrypoint_13(rdram, ctx);
        goto after_13;
    // 0x80800928: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_13:
    // 0x8080092C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800930: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x80800934: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800938: jr          $ra
    // 0x8080093C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8080093C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8010262C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010262C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80102630: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80102634: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80102638: lh          $a3, 0x10($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X10);
    // 0x8010263C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80102640: beql        $a3, $zero, L_801026BC
    if (ctx->r7 == 0) {
        // 0x80102644: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801026BC;
    }
    goto skip_0;
    // 0x80102644: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80102648: beq         $a1, $zero, L_801026B8
    if (ctx->r5 == 0) {
        // 0x8010264C: sll         $a0, $a3, 16
        ctx->r4 = S32(ctx->r7 << 16);
            goto L_801026B8;
    }
    // 0x8010264C: sll         $a0, $a3, 16
    ctx->r4 = S32(ctx->r7 << 16);
    // 0x80102650: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80102654: jal         0x800AE080
    // 0x80102658: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_800AE080(rdram, ctx);
        goto after_0;
    // 0x80102658: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_0:
    // 0x8010265C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80102660: jal         0x800AE6BC
    // 0x80102664: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800AE6BC(rdram, ctx);
        goto after_1;
    // 0x80102664: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80102668: bne         $v0, $zero, L_8010269C
    if (ctx->r2 != 0) {
        // 0x8010266C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8010269C;
    }
    // 0x8010266C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80102670: jal         0x800E09B8
    // 0x80102674: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800E09B8(rdram, ctx);
        goto after_2;
    // 0x80102674: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x80102678: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x8010267C: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80102680: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
    // 0x80102684: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80102688: jal         0x800AE6FC
    // 0x8010268C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800AE6FC(rdram, ctx);
        goto after_3;
    // 0x8010268C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80102690: jal         0x800E0A28
    // 0x80102694: lh          $a0, 0x1E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1E);
    func_800E0A28(rdram, ctx);
        goto after_4;
    // 0x80102694: lh          $a0, 0x1E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1E);
    after_4:
    // 0x80102698: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_8010269C:
    // 0x8010269C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801026A0: jal         0x800E0ACC
    // 0x801026A4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_800E0ACC(rdram, ctx);
        goto after_5;
    // 0x801026A4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_5:
    // 0x801026A8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801026AC: jal         0x800E0AF0
    // 0x801026B0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_800E0AF0(rdram, ctx);
        goto after_6;
    // 0x801026B0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_6:
    // 0x801026B4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
L_801026B8:
    // 0x801026B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801026BC:
    // 0x801026BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801026C0: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x801026C4: jr          $ra
    // 0x801026C8: nop

    return;
    // 0x801026C8: nop

;}
RECOMP_FUNC void func_80800430_bsbwhirl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800430: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800434: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800438: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080043C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800440: jal         0x800D8FF8
    // 0x80800444: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800444: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800448: lwc1        $f4, 0x16C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x8080044C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800450: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800454: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80800458: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x8080045C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80800460: swc1        $f6, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f6.u32l;
    // 0x80800464: lwc1        $f10, 0x16C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x80800468: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8080046C: nop

    // 0x80800470: bc1fl       L_808004CC
    if (!c1cs) {
        // 0x80800474: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808004CC;
    }
    goto skip_0;
    // 0x80800474: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800478: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8080047C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800480: addiu       $a3, $zero, 0x47
    ctx->r7 = ADD32(0, 0X47);
    // 0x80800484: swc1        $f16, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f16.u32l;
    // 0x80800488: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080048C: jal         0x8008A690
    // 0x80800490: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    _suinv_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800490: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80800494: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80800498: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x8080049C: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x808004A0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x808004A4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808004A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004AC: beq         $t8, $at, L_808004C8
    if (ctx->r24 == ctx->r1) {
        // 0x808004B0: addiu       $a1, $zero, 0x3E9
        ctx->r5 = ADD32(0, 0X3E9);
            goto L_808004C8;
    }
    // 0x808004B0: addiu       $a1, $zero, 0x3E9
    ctx->r5 = ADD32(0, 0X3E9);
    // 0x808004B4: jal         0x8009DF18
    // 0x808004B8: addiu       $a3, $zero, 0x6D60
    ctx->r7 = ADD32(0, 0X6D60);
    func_8009DF18(rdram, ctx);
        goto after_2;
    // 0x808004B8: addiu       $a3, $zero, 0x6D60
    ctx->r7 = ADD32(0, 0X6D60);
    after_2:
    // 0x808004BC: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    // 0x808004C0: jal         0x80085948
    // 0x808004C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _chusefeather_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x808004C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
L_808004C8:
    // 0x808004C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808004CC:
    // 0x808004CC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808004D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808004D4: jr          $ra
    // 0x808004D8: nop

    return;
    // 0x808004D8: nop

;}
RECOMP_FUNC void func_800C269C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C269C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C26A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C26A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C26A8: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800C26AC: jal         0x800C1414
    // 0x800C26B0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_800C1414(rdram, ctx);
        goto after_0;
    // 0x800C26B0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x800C26B4: lw          $t7, 0x78($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X78);
    // 0x800C26B8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800C26BC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800C26C0: sll         $t8, $t7, 19
    ctx->r24 = S32(ctx->r15 << 19);
    // 0x800C26C4: srl         $t9, $t8, 29
    ctx->r25 = S32(U32(ctx->r24) >> 29);
    // 0x800C26C8: beql        $t9, $at, L_800C26DC
    if (ctx->r25 == ctx->r1) {
        // 0x800C26CC: lbu         $t0, 0x79($v0)
        ctx->r8 = MEM_BU(ctx->r2, 0X79);
            goto L_800C26DC;
    }
    goto skip_0;
    // 0x800C26CC: lbu         $t0, 0x79($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X79);
    skip_0:
    // 0x800C26D0: b           L_800C2708
    // 0x800C26D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C2708;
    // 0x800C26D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C26D8: lbu         $t0, 0x79($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X79);
L_800C26DC:
    // 0x800C26DC: bne         $t0, $zero, L_800C26EC
    if (ctx->r8 != 0) {
        // 0x800C26E0: nop
    
            goto L_800C26EC;
    }
    // 0x800C26E0: nop

    // 0x800C26E4: b           L_800C2708
    // 0x800C26E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800C2708;
    // 0x800C26E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800C26EC:
    // 0x800C26EC: jal         0x800C1448
    // 0x800C26F0: lbu         $a0, 0x79($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X79);
    func_800C1448(rdram, ctx);
        goto after_1;
    // 0x800C26F0: lbu         $a0, 0x79($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X79);
    after_1:
    // 0x800C26F4: beql        $v0, $zero, L_800C2708
    if (ctx->r2 == 0) {
        // 0x800C26F8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800C2708;
    }
    goto skip_1;
    // 0x800C26F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x800C26FC: b           L_800C2708
    // 0x800C2700: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C2708;
    // 0x800C2700: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C2704: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800C2708:
    // 0x800C2708: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C270C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C2710: jr          $ra
    // 0x800C2714: nop

    return;
    // 0x800C2714: nop

;}
RECOMP_FUNC void subaddiemulti_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800008: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8080000C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800010: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800014: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800018: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080001C: addiu       $s2, $zero, 0x8
    ctx->r18 = ADD32(0, 0X8);
L_80800020:
    // 0x80800020: jal         0x800F6438
    // 0x80800024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6438(rdram, ctx);
        goto after_0;
    // 0x80800024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800028: beq         $v0, $zero, L_80800048
    if (ctx->r2 == 0) {
        // 0x8080002C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800048;
    }
    // 0x8080002C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800030: jal         0x800F82D4
    // 0x80800034: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800F82D4(rdram, ctx);
        goto after_1;
    // 0x80800034: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80800038: beq         $s1, $zero, L_80800048
    if (ctx->r17 == 0) {
        // 0x8080003C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800048;
    }
    // 0x8080003C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800040: jal         0x800F608C
    // 0x80800044: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800F608C(rdram, ctx);
        goto after_2;
    // 0x80800044: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
L_80800048:
    // 0x80800048: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8080004C: bne         $s0, $s2, L_80800020
    if (ctx->r16 != ctx->r18) {
        // 0x80800050: nop
    
            goto L_80800020;
    }
    // 0x80800050: nop

    // 0x80800054: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800058: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080005C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800060: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800064: jr          $ra
    // 0x80800068: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800068: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80803124_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803124: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80803128: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x8080312C: jr          $ra
    // 0x80803130: sh          $zero, 0xE0($v0)
    MEM_H(0XE0, ctx->r2) = 0;
    return;
    // 0x80803130: sh          $zero, 0xE0($v0)
    MEM_H(0XE0, ctx->r2) = 0;
;}
RECOMP_FUNC void func_80112A84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80112A84: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80112A88: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80112A8C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80112A90: lw          $t6, 0x60($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X60);
    // 0x80112A94: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80112A98: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x80112A9C: lh          $t7, 0xC($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XC);
    // 0x80112AA0: beql        $t7, $zero, L_80112C08
    if (ctx->r15 == 0) {
        // 0x80112AA4: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_80112C08;
    }
    goto skip_0;
    // 0x80112AA4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x80112AA8: jal         0x800D8FF8
    // 0x80112AAC: sw          $t8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r24;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80112AAC: sw          $t8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r24;
    after_0:
    // 0x80112AB0: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
    // 0x80112AB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80112AB8: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x80112ABC: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80112AC0: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80112AC4: jal         0x801127A8
    // 0x80112AC8: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
    func_801127A8(rdram, ctx);
        goto after_1;
    // 0x80112AC8: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
    after_1:
    // 0x80112ACC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80112AD0: jal         0x801107F0
    // 0x80112AD4: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_801107F0(rdram, ctx);
        goto after_2;
    // 0x80112AD4: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_2:
    // 0x80112AD8: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80112ADC: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80112AE0: jal         0x800EFB24
    // 0x80112AE4: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    func_800EFB24(rdram, ctx);
        goto after_3;
    // 0x80112AE4: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    after_3:
    // 0x80112AE8: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80112AEC: jal         0x800F1A88
    // 0x80112AF0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800F1A88(rdram, ctx);
        goto after_4;
    // 0x80112AF0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_4:
    // 0x80112AF4: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
    // 0x80112AF8: lwc1        $f8, 0x20($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80112AFC: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80112B00: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80112B04: nop

    // 0x80112B08: bc1fl       L_80112B20
    if (!c1cs) {
        // 0x80112B0C: lwc1        $f18, 0x10($v0)
        ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
            goto L_80112B20;
    }
    goto skip_1;
    // 0x80112B0C: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    skip_1:
    // 0x80112B10: lwc1        $f16, 0x10($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80112B14: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    // 0x80112B18: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
    // 0x80112B1C: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
L_80112B20:
    // 0x80112B20: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80112B24: jal         0x800F2100
    // 0x80112B28: sub.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f4.fl;
    mlAbsF(rdram, ctx);
        goto after_5;
    // 0x80112B28: sub.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f4.fl;
    after_5:
    // 0x80112B2C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80112B30: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80112B34: or          $t9, $zero, $zero
    ctx->r25 = 0 | 0;
    // 0x80112B38: lui         $a3, 0x4448
    ctx->r7 = S32(0X4448 << 16);
    // 0x80112B3C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80112B40: nop

    // 0x80112B44: bc1fl       L_80112B54
    if (!c1cs) {
        // 0x80112B48: sw          $t9, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r25;
            goto L_80112B54;
    }
    goto skip_2;
    // 0x80112B48: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    skip_2:
    // 0x80112B4C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80112B50: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
L_80112B54:
    // 0x80112B54: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
    // 0x80112B58: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80112B5C: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80112B60: addiu       $a1, $v0, 0x14
    ctx->r5 = ADD32(ctx->r2, 0X14);
    // 0x80112B64: addiu       $a2, $v0, 0x18
    ctx->r6 = ADD32(ctx->r2, 0X18);
    // 0x80112B68: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    // 0x80112B6C: lwc1        $f12, 0x10($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80112B70: swc1        $f12, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f12.u32l;
    // 0x80112B74: lh          $t0, 0xC($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XC);
    // 0x80112B78: bne         $t0, $at, L_80112BB4
    if (ctx->r8 != ctx->r1) {
        // 0x80112B7C: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_80112BB4;
    }
    // 0x80112B7C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80112B80: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80112B84: addiu       $a1, $v0, 0x14
    ctx->r5 = ADD32(ctx->r2, 0X14);
    // 0x80112B88: addiu       $a2, $v0, 0x18
    ctx->r6 = ADD32(ctx->r2, 0X18);
    // 0x80112B8C: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    // 0x80112B90: jal         0x801127C8
    // 0x80112B94: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_801127C8(rdram, ctx);
        goto after_6;
    // 0x80112B94: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x80112B98: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80112B9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80112BA0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80112BA4: jal         0x801160DC
    // 0x80112BA8: nop

    func_801160DC(rdram, ctx);
        goto after_7;
    // 0x80112BA8: nop

    after_7:
    // 0x80112BAC: b           L_80112BE8
    // 0x80112BB0: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
        goto L_80112BE8;
    // 0x80112BB0: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
L_80112BB4:
    // 0x80112BB4: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80112BB8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80112BBC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80112BC0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80112BC4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80112BC8: jal         0x801128D4
    // 0x80112BCC: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_801128D4(rdram, ctx);
        goto after_8;
    // 0x80112BCC: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_8:
    // 0x80112BD0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80112BD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80112BD8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80112BDC: jal         0x801160DC
    // 0x80112BE0: nop

    func_801160DC(rdram, ctx);
        goto after_9;
    // 0x80112BE0: nop

    after_9:
    // 0x80112BE4: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
L_80112BE8:
    // 0x80112BE8: beql        $t1, $zero, L_80112C18
    if (ctx->r9 == 0) {
        // 0x80112BEC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80112C18;
    }
    goto skip_3;
    // 0x80112BEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x80112BF0: lw          $t2, 0x60($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X60);
    // 0x80112BF4: sh          $zero, 0xC($t2)
    MEM_H(0XC, ctx->r10) = 0;
    // 0x80112BF8: lw          $t3, 0x60($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X60);
    // 0x80112BFC: b           L_80112C14
    // 0x80112C00: sh          $zero, 0xE($t3)
    MEM_H(0XE, ctx->r11) = 0;
        goto L_80112C14;
    // 0x80112C00: sh          $zero, 0xE($t3)
    MEM_H(0XE, ctx->r11) = 0;
    // 0x80112C04: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80112C08:
    // 0x80112C08: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
    // 0x80112C0C: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x80112C10: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
L_80112C14:
    // 0x80112C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80112C18:
    // 0x80112C18: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x80112C1C: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x80112C20: jal         0x80112D08
    // 0x80112C24: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    func_80112D08(rdram, ctx);
        goto after_10;
    // 0x80112C24: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    after_10:
    // 0x80112C28: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80112C2C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80112C30: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x80112C34: jr          $ra
    // 0x80112C38: nop

    return;
    // 0x80112C38: nop

;}
