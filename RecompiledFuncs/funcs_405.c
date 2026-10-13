#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void badata_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800758: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080075C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80800760: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800764: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800768: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080076C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(473, 0X1B98) << 16);
    // 0x80800770: jal         0x808006AC
    // 0x80800774: addiu       $a1, $a1, 0x1B98
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(473, 0X1B98));
    func_808006AC_badata(rdram, ctx);
        goto after_0;
    // 0x80800774: addiu       $a1, $a1, 0x1B98
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(473, 0X1B98));
    after_0:
    // 0x80800778: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080077C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800780: jr          $ra
    // 0x80800784: nop

    return;
    // 0x80800784: nop

;}
RECOMP_FUNC void func_80800788_chfactoryworkerdirty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800788: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080078C: addiu       $at, $zero, 0x134C
    ctx->r1 = ADD32(0, 0X134C);
    // 0x80800790: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800794: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800798: beq         $a1, $at, L_808007BC
    if (ctx->r5 == ctx->r1) {
        // 0x8080079C: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_808007BC;
    }
    // 0x8080079C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808007A0: addiu       $at, $zero, 0x134D
    ctx->r1 = ADD32(0, 0X134D);
    // 0x808007A4: beq         $a1, $at, L_808007BC
    if (ctx->r5 == ctx->r1) {
        // 0x808007A8: addiu       $at, $zero, 0x1350
        ctx->r1 = ADD32(0, 0X1350);
            goto L_808007BC;
    }
    // 0x808007A8: addiu       $at, $zero, 0x1350
    ctx->r1 = ADD32(0, 0X1350);
    // 0x808007AC: beq         $a1, $at, L_808007DC
    if (ctx->r5 == ctx->r1) {
        // 0x808007B0: nop
    
            goto L_808007DC;
    }
    // 0x808007B0: nop

    // 0x808007B4: b           L_80800810
    // 0x808007B8: nop

        goto L_80800810;
    // 0x808007B8: nop

L_808007BC:
    // 0x808007BC: jal         0x80090708
    // 0x808007C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_0;
    // 0x808007C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x808007C4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808007C8: addiu       $a0, $zero, 0x65
    ctx->r4 = ADD32(0, 0X65);
    // 0x808007CC: jal         0x800904F4
    // 0x808007D0: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    func_800904F4(rdram, ctx);
        goto after_1;
    // 0x808007D0: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    after_1:
    // 0x808007D4: b           L_8080081C
    // 0x808007D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080081C;
    // 0x808007D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808007DC:
    // 0x808007DC: jal         0x80800B40
    // 0x808007E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800B40_chfactoryworkerdirty(rdram, ctx);
        goto after_2;
    // 0x808007E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808007E4: jal         0x80090708
    // 0x808007E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_3;
    // 0x808007E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x808007EC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808007F0: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    // 0x808007F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808007F8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808007FC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800800: jal         0x800D1000
    // 0x80800804: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    func_800D1000(rdram, ctx);
        goto after_4;
    // 0x80800804: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    after_4:
    // 0x80800808: b           L_8080081C
    // 0x8080080C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080081C;
    // 0x8080080C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800810:
    // 0x80800810: jal         0x80090708
    // 0x80800814: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_5;
    // 0x80800814: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x80800818: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080081C:
    // 0x8080081C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800820: jr          $ra
    // 0x80800824: nop

    return;
    // 0x80800824: nop

;}
RECOMP_FUNC void bastatemem_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800058: jr          $ra
    // 0x8080005C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8080005C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void gcmapsects_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080144C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801450: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801454: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80801458: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8080145C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80801460: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80801464: jal         0x800BF704
    // 0x80801468: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_800BF704(rdram, ctx);
        goto after_0;
    // 0x80801468: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x8080146C: lh          $s1, 0x74($v0)
    ctx->r17 = MEM_H(ctx->r2, 0X74);
    // 0x80801470: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80801474: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80801478: beq         $s1, $at, L_808014B8
    if (ctx->r17 == ctx->r1) {
        // 0x8080147C: sll         $t7, $s1, 2
        ctx->r15 = S32(ctx->r17 << 2);
            goto L_808014B8;
    }
    // 0x8080147C: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x80801480: subu        $t7, $t7, $s1
    ctx->r15 = SUB32(ctx->r15, ctx->r17);
    // 0x80801484: lw          $t6, 0x68($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X68);
    // 0x80801488: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8080148C: subu        $t7, $t7, $s1
    ctx->r15 = SUB32(ctx->r15, ctx->r17);
    // 0x80801490: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80801494: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80801498: addiu       $a0, $v0, 0xC
    ctx->r4 = ADD32(ctx->r2, 0XC);
    // 0x8080149C: addiu       $a1, $v0, 0x18
    ctx->r5 = ADD32(ctx->r2, 0X18);
    // 0x808014A0: jal         0x800EFED0
    // 0x808014A4: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_800EFED0(rdram, ctx);
        goto after_1;
    // 0x808014A4: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_1:
    // 0x808014A8: beql        $v0, $zero, L_808014BC
    if (ctx->r2 == 0) {
        // 0x808014AC: lbu         $t8, 0x77($s2)
        ctx->r24 = MEM_BU(ctx->r18, 0X77);
            goto L_808014BC;
    }
    goto skip_0;
    // 0x808014AC: lbu         $t8, 0x77($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X77);
    skip_0:
    // 0x808014B0: b           L_80801530
    // 0x808014B4: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
        goto L_80801530;
    // 0x808014B4: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_808014B8:
    // 0x808014B8: lbu         $t8, 0x77($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X77);
L_808014BC:
    // 0x808014BC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808014C0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808014C4: blezl       $t8, L_80801530
    if (SIGNED(ctx->r24) <= 0) {
        // 0x808014C8: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80801530;
    }
    goto skip_1;
    // 0x808014C8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_1:
    // 0x808014CC: lw          $t9, 0x68($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X68);
L_808014D0:
    // 0x808014D0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x808014D4: addu        $v0, $t9, $s0
    ctx->r2 = ADD32(ctx->r25, ctx->r16);
    // 0x808014D8: addiu       $a0, $v0, 0x24
    ctx->r4 = ADD32(ctx->r2, 0X24);
    // 0x808014DC: jal         0x800EFFB4
    // 0x808014E0: lw          $a1, 0x30($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X30);
    func_800EFFB4(rdram, ctx);
        goto after_2;
    // 0x808014E0: lw          $a1, 0x30($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X30);
    after_2:
    // 0x808014E4: beql        $v0, $zero, L_80801518
    if (ctx->r2 == 0) {
        // 0x808014E8: lbu         $t1, 0x77($s2)
        ctx->r9 = MEM_BU(ctx->r18, 0X77);
            goto L_80801518;
    }
    goto skip_2;
    // 0x808014E8: lbu         $t1, 0x77($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X77);
    skip_2:
    // 0x808014EC: lw          $t0, 0x68($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X68);
    // 0x808014F0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x808014F4: addu        $v0, $t0, $s0
    ctx->r2 = ADD32(ctx->r8, ctx->r16);
    // 0x808014F8: addiu       $a0, $v0, 0xC
    ctx->r4 = ADD32(ctx->r2, 0XC);
    // 0x808014FC: jal         0x800EFED0
    // 0x80801500: addiu       $a1, $v0, 0x18
    ctx->r5 = ADD32(ctx->r2, 0X18);
    func_800EFED0(rdram, ctx);
        goto after_3;
    // 0x80801500: addiu       $a1, $v0, 0x18
    ctx->r5 = ADD32(ctx->r2, 0X18);
    after_3:
    // 0x80801504: beql        $v0, $zero, L_80801518
    if (ctx->r2 == 0) {
        // 0x80801508: lbu         $t1, 0x77($s2)
        ctx->r9 = MEM_BU(ctx->r18, 0X77);
            goto L_80801518;
    }
    goto skip_3;
    // 0x80801508: lbu         $t1, 0x77($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X77);
    skip_3:
    // 0x8080150C: b           L_80801530
    // 0x80801510: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
        goto L_80801530;
    // 0x80801510: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80801514: lbu         $t1, 0x77($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X77);
L_80801518:
    // 0x80801518: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8080151C: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    // 0x80801520: slt         $at, $s1, $t1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80801524: bnel        $at, $zero, L_808014D0
    if (ctx->r1 != 0) {
        // 0x80801528: lw          $t9, 0x68($s2)
        ctx->r25 = MEM_W(ctx->r18, 0X68);
            goto L_808014D0;
    }
    goto skip_4;
    // 0x80801528: lw          $t9, 0x68($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X68);
    skip_4:
    // 0x8080152C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80801530:
    // 0x80801530: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801534: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801538: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080153C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80801540: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80801544: jr          $ra
    // 0x80801548: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80801548: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800F78C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F78C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F78CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F78D0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800F78D4: jal         0x800F7C58
    // 0x800F78D8: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    func_800F7C58(rdram, ctx);
        goto after_0;
    // 0x800F78D8: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_0:
    // 0x800F78DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F78E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F78E4: jr          $ra
    // 0x800F78E8: nop

    return;
    // 0x800F78E8: nop

;}
RECOMP_FUNC void func_808008FC_chbiggafoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008FC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800900: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800904: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800908: lwc1        $f6, 0x58($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X58);
    // 0x8080090C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800910: nop

    // 0x80800914: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800918: nop

    // 0x8080091C: bc1f        L_8080092C
    if (!c1cs) {
        // 0x80800920: nop
    
            goto L_8080092C;
    }
    // 0x80800920: nop

    // 0x80800924: b           L_80800970
    // 0x80800928: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800970;
    // 0x80800928: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080092C:
    // 0x8080092C: jal         0x800F54E4
    // 0x80800930: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800930: nop

    after_0:
    // 0x80800934: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800938: jal         0x800F6478
    // 0x8080093C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6478(rdram, ctx);
        goto after_1;
    // 0x8080093C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800940: bne         $v0, $zero, L_80800950
    if (ctx->r2 != 0) {
        // 0x80800944: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_80800950;
    }
    // 0x80800944: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800948: b           L_80800970
    // 0x8080094C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800970;
    // 0x8080094C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800950:
    // 0x80800950: jal         0x800F5BF0
    // 0x80800954: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800F5BF0(rdram, ctx);
        goto after_2;
    // 0x80800954: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_2:
    // 0x80800958: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8080095C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800960: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800964: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    // 0x80800968: jal         0x800F0008
    // 0x8080096C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    func_800F0008(rdram, ctx);
        goto after_3;
    // 0x8080096C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    after_3:
L_80800970:
    // 0x80800970: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800974: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800978: jr          $ra
    // 0x8080097C: nop

    return;
    // 0x8080097C: nop

;}
RECOMP_FUNC void _gczoombox_entrypoint_33(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087BE8: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087BE8);
    return;
    // 0x80087BEC: addi        $t0, $zero, 0x84
    ctx->r8 = ADD32(0, 0X84);
;}
RECOMP_FUNC void func_80800C90_chbadjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800C94: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800C98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C9C: beq         $a1, $at, L_80800D38
    if (ctx->r5 == ctx->r1) {
        // 0x80800CA0: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80800D38;
    }
    // 0x80800CA0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800CA4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800CA8: beq         $a1, $at, L_80800D48
    if (ctx->r5 == ctx->r1) {
        // 0x80800CAC: addiu       $at, $zero, 0x1F
        ctx->r1 = ADD32(0, 0X1F);
            goto L_80800D48;
    }
    // 0x80800CAC: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80800CB0: beq         $a1, $at, L_80800D8C
    if (ctx->r5 == ctx->r1) {
        // 0x80800CB4: addiu       $at, $zero, 0x38
        ctx->r1 = ADD32(0, 0X38);
            goto L_80800D8C;
    }
    // 0x80800CB4: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x80800CB8: beq         $a1, $at, L_80800DA8
    if (ctx->r5 == ctx->r1) {
        // 0x80800CBC: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_80800DA8;
    }
    // 0x80800CBC: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800CC0: beq         $a1, $at, L_80800D14
    if (ctx->r5 == ctx->r1) {
        // 0x80800CC4: addiu       $at, $zero, 0x4D
        ctx->r1 = ADD32(0, 0X4D);
            goto L_80800D14;
    }
    // 0x80800CC4: addiu       $at, $zero, 0x4D
    ctx->r1 = ADD32(0, 0X4D);
    // 0x80800CC8: beq         $a1, $at, L_80800DBC
    if (ctx->r5 == ctx->r1) {
        // 0x80800CCC: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_80800DBC;
    }
    // 0x80800CCC: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800CD0: bne         $a1, $at, L_80800DD4
    if (ctx->r5 != ctx->r1) {
        // 0x80800CD4: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800DD4;
    }
    // 0x80800CD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800CD8: jal         0x80100094
    // 0x80800CDC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800CDC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800CE0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800CE4: jal         0x80089F60
    // 0x80800CE8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    _subaddierouteDll_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800CE8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800CEC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800CF0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800CF4: addiu       $a1, $zero, 0x643
    ctx->r5 = ADD32(0, 0X643);
    // 0x80800CF8: lbu         $a2, 0x24($t6)
    ctx->r6 = MEM_BU(ctx->r14, 0X24);
    // 0x80800CFC: addiu       $a2, $a2, 0xC31
    ctx->r6 = ADD32(ctx->r6, 0XC31);
    // 0x80800D00: andi        $t7, $a2, 0xFFFF
    ctx->r15 = ctx->r6 & 0XFFFF;
    // 0x80800D04: jal         0x80103140
    // 0x80800D08: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    func_80103140(rdram, ctx);
        goto after_2;
    // 0x80800D08: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    after_2:
    // 0x80800D0C: b           L_80800DE0
    // 0x80800D10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800DE0;
    // 0x80800D10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D14:
    // 0x80800D14: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1576, 0X12E8) << 16);
    // 0x80800D18: addiu       $a1, $a1, 0x12E8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1576, 0X12E8));
    // 0x80800D1C: jal         0x80801090
    // 0x80800D20: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80801090_chbadjinjo(rdram, ctx);
        goto after_3;
    // 0x80800D20: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_3:
    // 0x80800D24: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800D28: jal         0x80800E28
    // 0x80800D2C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800E28_chbadjinjo(rdram, ctx);
        goto after_4;
    // 0x80800D2C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_4:
    // 0x80800D30: b           L_80800DE0
    // 0x80800D34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800DE0;
    // 0x80800D34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D38:
    // 0x80800D38: jal         0x80800E28
    // 0x80800D3C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800E28_chbadjinjo(rdram, ctx);
        goto after_5;
    // 0x80800D3C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_5:
    // 0x80800D40: b           L_80800DE0
    // 0x80800D44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800DE0;
    // 0x80800D44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D48:
    // 0x80800D48: jal         0x8008A4A8
    // 0x80800D4C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _subaddieDll_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x80800D4C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_6:
    // 0x80800D50: bne         $v0, $zero, L_80800D7C
    if (ctx->r2 != 0) {
        // 0x80800D54: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800D7C;
    }
    // 0x80800D54: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800D58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800D5C: jal         0x80107070
    // 0x80800D60: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80107070(rdram, ctx);
        goto after_7;
    // 0x80800D60: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_7:
    // 0x80800D64: bne         $v0, $zero, L_80800DDC
    if (ctx->r2 != 0) {
        // 0x80800D68: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800DDC;
    }
    // 0x80800D68: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800D6C: jal         0x80089CA8
    // 0x80800D70: nop

    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_8;
    // 0x80800D70: nop

    after_8:
    // 0x80800D74: b           L_80800DE0
    // 0x80800D78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800DE0;
    // 0x80800D78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D7C:
    // 0x80800D7C: jal         0x80800E28
    // 0x80800D80: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800E28_chbadjinjo(rdram, ctx);
        goto after_9;
    // 0x80800D80: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_9:
    // 0x80800D84: b           L_80800DE0
    // 0x80800D88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800DE0;
    // 0x80800D88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D8C:
    // 0x80800D8C: jal         0x801015D0
    // 0x80800D90: nop

    func_801015D0(rdram, ctx);
        goto after_10;
    // 0x80800D90: nop

    after_10:
    // 0x80800D94: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800D98: jal         0x800DF744
    // 0x80800D9C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DF744(rdram, ctx);
        goto after_11;
    // 0x80800D9C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_11:
    // 0x80800DA0: b           L_80800DE0
    // 0x80800DA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800DE0;
    // 0x80800DA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800DA8:
    // 0x80800DA8: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1576, 0X124C) << 16);
    // 0x80800DAC: jal         0x80101074
    // 0x80800DB0: addiu       $a0, $a0, 0x124C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1576, 0X124C));
    func_80101074(rdram, ctx);
        goto after_12;
    // 0x80800DB0: addiu       $a0, $a0, 0x124C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1576, 0X124C));
    after_12:
    // 0x80800DB4: b           L_80800DE0
    // 0x80800DB8: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_80800DE0;
    // 0x80800DB8: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_80800DBC:
    // 0x80800DBC: jal         0x80107070
    // 0x80800DC0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80107070(rdram, ctx);
        goto after_13;
    // 0x80800DC0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_13:
    // 0x80800DC4: bnel        $v0, $zero, L_80800DE0
    if (ctx->r2 != 0) {
        // 0x80800DC8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800DE0;
    }
    goto skip_0;
    // 0x80800DC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800DCC: b           L_80800DE0
    // 0x80800DD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800DE0;
    // 0x80800DD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800DD4:
    // 0x80800DD4: b           L_80800DE0
    // 0x80800DD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800DE0;
    // 0x80800DD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800DDC:
    // 0x80800DDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800DE0:
    // 0x80800DE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800DE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800DE8: jr          $ra
    // 0x80800DEC: nop

    return;
    // 0x80800DEC: nop

;}
RECOMP_FUNC void func_800DFAD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DFAD0: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800DFAD4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800DFAD8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800DFADC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800DFAE0: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800DFAE4: addu        $v1, $t7, $v0
    ctx->r3 = ADD32(ctx->r15, ctx->r2);
    // 0x800DFAE8: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800DFAEC: beq         $at, $zero, L_800DFB38
    if (ctx->r1 == 0) {
        // 0x800DFAF0: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800DFB38;
    }
    // 0x800DFAF0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800DFAF4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800DFAF8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800DFAFC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800DFB00: nop

L_800DFB04:
    // 0x800DFB04: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // 0x800DFB08: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800DFB0C: swc1        $f0, -0x20($v0)
    MEM_W(-0X20, ctx->r2) = ctx->f0.u32l;
    // 0x800DFB10: swc1        $f0, -0x24($v0)
    MEM_W(-0X24, ctx->r2) = ctx->f0.u32l;
    // 0x800DFB14: swc1        $f0, -0x28($v0)
    MEM_W(-0X28, ctx->r2) = ctx->f0.u32l;
    // 0x800DFB18: swc1        $f2, -0x1C($v0)
    MEM_W(-0X1C, ctx->r2) = ctx->f2.u32l;
    // 0x800DFB1C: swc1        $f12, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f12.u32l;
    // 0x800DFB20: swc1        $f12, -0x14($v0)
    MEM_W(-0X14, ctx->r2) = ctx->f12.u32l;
    // 0x800DFB24: swc1        $f12, -0x18($v0)
    MEM_W(-0X18, ctx->r2) = ctx->f12.u32l;
    // 0x800DFB28: swc1        $f0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f0.u32l;
    // 0x800DFB2C: swc1        $f0, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f0.u32l;
    // 0x800DFB30: bne         $at, $zero, L_800DFB04
    if (ctx->r1 != 0) {
        // 0x800DFB34: swc1        $f0, -0xC($v0)
        MEM_W(-0XC, ctx->r2) = ctx->f0.u32l;
            goto L_800DFB04;
    }
    // 0x800DFB34: swc1        $f0, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f0.u32l;
L_800DFB38:
    // 0x800DFB38: jr          $ra
    // 0x800DFB3C: nop

    return;
    // 0x800DFB3C: nop

;}
RECOMP_FUNC void _cadbfunc_entrypoint_33(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085688: syscall     169
    recomp_syscall_handler(rdram, ctx, 0x80085688);
    return;
    // 0x8008568C: addi        $t0, $zero, 0x84
    ctx->r8 = ADD32(0, 0X84);
;}
RECOMP_FUNC void func_800A9AF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9AF8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A9AFC: addiu       $v1, $v1, 0x7760
    ctx->r3 = ADD32(ctx->r3, 0X7760);
    // 0x800A9B00: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800A9B04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A9B08: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A9B0C: beq         $v0, $at, L_800A9B28
    if (ctx->r2 == ctx->r1) {
        // 0x800A9B10: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800A9B28;
    }
    // 0x800A9B10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A9B14: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A9B18: beql        $v0, $at, L_800A9B3C
    if (ctx->r2 == ctx->r1) {
        // 0x800A9B1C: lbu         $t6, 0x4($v1)
        ctx->r14 = MEM_BU(ctx->r3, 0X4);
            goto L_800A9B3C;
    }
    goto skip_0;
    // 0x800A9B1C: lbu         $t6, 0x4($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X4);
    skip_0:
    // 0x800A9B20: b           L_800A9B3C
    // 0x800A9B24: lbu         $t6, 0x4($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X4);
        goto L_800A9B3C;
    // 0x800A9B24: lbu         $t6, 0x4($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X4);
L_800A9B28:
    // 0x800A9B28: jal         0x800E8104
    // 0x800A9B2C: nop

    func_800E8104(rdram, ctx);
        goto after_0;
    // 0x800A9B2C: nop

    after_0:
    // 0x800A9B30: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A9B34: addiu       $v1, $v1, 0x7760
    ctx->r3 = ADD32(ctx->r3, 0X7760);
    // 0x800A9B38: lbu         $t6, 0x4($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X4);
L_800A9B3C:
    // 0x800A9B3C: bnel        $t6, $zero, L_800A9B68
    if (ctx->r14 != 0) {
        // 0x800A9B40: sb          $zero, 0x3($v1)
        MEM_B(0X3, ctx->r3) = 0;
            goto L_800A9B68;
    }
    goto skip_1;
    // 0x800A9B40: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    skip_1:
    // 0x800A9B44: jal         0x800D3D58
    // 0x800A9B48: nop

    func_800D3D58(rdram, ctx);
        goto after_1;
    // 0x800A9B48: nop

    after_1:
    // 0x800A9B4C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A9B50: addiu       $v1, $v1, 0x7760
    ctx->r3 = ADD32(ctx->r3, 0X7760);
    // 0x800A9B54: jal         0x800886B8
    // 0x800A9B58: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    _glrecord_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x800A9B58: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    after_2:
    // 0x800A9B5C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A9B60: addiu       $v1, $v1, 0x7760
    ctx->r3 = ADD32(ctx->r3, 0X7760);
    // 0x800A9B64: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
L_800A9B68:
    // 0x800A9B68: sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
    // 0x800A9B6C: jal         0x800A1618
    // 0x800A9B70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800A1618(rdram, ctx);
        goto after_3;
    // 0x800A9B70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x800A9B74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A9B78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A9B7C: jr          $ra
    // 0x800A9B80: nop

    return;
    // 0x800A9B80: nop

;}
RECOMP_FUNC void func_808000A8_bskazhatch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000B4: jal         0x80800000
    // 0x808000B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800000_bskazhatch(rdram, ctx);
        goto after_0;
    // 0x808000B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808000BC: jal         0x800832E8
    // 0x808000C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bskaz_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x808000C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808000C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000CC: jr          $ra
    // 0x808000D0: nop

    return;
    // 0x808000D0: nop

;}
RECOMP_FUNC void func_800E1378(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E1378: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E137C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800E1380: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800E1384: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800E1388: jal         0x800E13F0
    // 0x800E138C: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    func_800E13F0(rdram, ctx);
        goto after_0;
    // 0x800E138C: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    after_0:
    // 0x800E1390: lui         $a1, 0x3F26
    ctx->r5 = S32(0X3F26 << 16);
    // 0x800E1394: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x800E1398: jal         0x800E144C
    // 0x800E139C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E144C(rdram, ctx);
        goto after_1;
    // 0x800E139C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800E13A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E13A4: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x800E13A8: jal         0x800E148C
    // 0x800E13AC: lui         $a2, 0x44FA
    ctx->r6 = S32(0X44FA << 16);
    func_800E148C(rdram, ctx);
        goto after_2;
    // 0x800E13AC: lui         $a2, 0x44FA
    ctx->r6 = S32(0X44FA << 16);
    after_2:
    // 0x800E13B0: jal         0x800EA068
    // 0x800E13B4: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    func_800EA068(rdram, ctx);
        goto after_3;
    // 0x800E13B4: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_3:
    // 0x800E13B8: beq         $v0, $zero, L_800E13D4
    if (ctx->r2 == 0) {
        // 0x800E13BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800E13D4;
    }
    // 0x800E13BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E13C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E13C4: jal         0x800E146C
    // 0x800E13C8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_800E146C(rdram, ctx);
        goto after_4;
    // 0x800E13C8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x800E13CC: b           L_800E13E0
    // 0x800E13D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800E13E0;
    // 0x800E13D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800E13D4:
    // 0x800E13D4: jal         0x800E146C
    // 0x800E13D8: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_800E146C(rdram, ctx);
        goto after_5;
    // 0x800E13D8: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_5:
    // 0x800E13DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800E13E0:
    // 0x800E13E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800E13E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800E13E8: jr          $ra
    // 0x800E13EC: nop

    return;
    // 0x800E13EC: nop

;}
RECOMP_FUNC void idflasha_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800168: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080016C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800170: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800174: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800178: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8080017C: jal         0x800D8FF8
    // 0x80800180: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800180: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800184: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80800188: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x8080018C: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    // 0x80800190: bnel        $t6, $zero, L_808001B4
    if (ctx->r14 != 0) {
        // 0x80800194: lw          $t7, 0xC($s0)
        ctx->r15 = MEM_W(ctx->r16, 0XC);
            goto L_808001B4;
    }
    goto skip_0;
    // 0x80800194: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    skip_0:
    // 0x80800198: jal         0x800F1574
    // 0x8080019C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800F1574(rdram, ctx);
        goto after_1;
    // 0x8080019C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x808001A0: beq         $v0, $zero, L_808001B0
    if (ctx->r2 == 0) {
        // 0x808001A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001B0;
    }
    // 0x808001A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A8: jal         0x80800038
    // 0x808001AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800038_idflasha(rdram, ctx);
        goto after_2;
    // 0x808001AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_808001B0:
    // 0x808001B0: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
L_808001B4:
    // 0x808001B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808001B8: bne         $t7, $at, L_8080026C
    if (ctx->r15 != ctx->r1) {
        // 0x808001BC: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2910, 0X2B0) << 16);
            goto L_8080026C;
    }
    // 0x808001BC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2910, 0X2B0) << 16);
    // 0x808001C0: lwc1        $f12, 0x2B0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2910, 0X2B0));
    // 0x808001C4: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x808001C8: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    // 0x808001CC: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x808001D0: nop

    // 0x808001D4: bc1fl       L_80800208
    if (!c1cs) {
        // 0x808001D8: lwc1        $f2, 0x14($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0X14);
            goto L_80800208;
    }
    goto skip_1;
    // 0x808001D8: lwc1        $f2, 0x14($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X14);
    skip_1:
    // 0x808001DC: div.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
    // 0x808001E0: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    // 0x808001E4: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x808001E8: nop

    // 0x808001EC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808001F0: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x808001F4: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x808001F8: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x808001FC: b           L_80800254
    // 0x80800200: sh          $t0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r8;
        goto L_80800254;
    // 0x80800200: sh          $t0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r8;
    // 0x80800204: lwc1        $f2, 0x14($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X14);
L_80800208:
    // 0x80800208: sub.s       $f18, $f2, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x8080020C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80800210: nop

    // 0x80800214: bc1fl       L_8080022C
    if (!c1cs) {
        // 0x80800218: sub.s       $f6, $f2, $f0
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_8080022C;
    }
    goto skip_2;
    // 0x80800218: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
    skip_2:
    // 0x8080021C: lh          $t1, 0x2($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X2);
    // 0x80800220: b           L_80800254
    // 0x80800224: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
        goto L_80800254;
    // 0x80800224: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
    // 0x80800228: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
L_8080022C:
    // 0x8080022C: lh          $t2, 0x2($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X2);
    // 0x80800230: div.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80800234: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x80800238: nop

    // 0x8080023C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800240: mul.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80800244: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800248: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x8080024C: nop

    // 0x80800250: sh          $t4, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r12;
L_80800254:
    // 0x80800254: jal         0x800F1574
    // 0x80800258: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800F1574(rdram, ctx);
        goto after_3;
    // 0x80800258: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x8080025C: beq         $v0, $zero, L_8080026C
    if (ctx->r2 == 0) {
        // 0x80800260: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080026C;
    }
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800264: jal         0x80800038
    // 0x80800268: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800038_idflasha(rdram, ctx);
        goto after_4;
    // 0x80800268: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
L_8080026C:
    // 0x8080026C: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80800270: addiu       $a2, $a2, -0x72A8
    ctx->r6 = ADD32(ctx->r6, -0X72A8);
    // 0x80800274: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800278: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8080027C: jal         0x80088660
    // 0x80800280: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    _glid_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x80800280: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_5:
    // 0x80800284: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800288: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080028C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800290: jr          $ra
    // 0x80800294: nop

    return;
    // 0x80800294: nop

    // 0x80800298: nop

    // 0x8080029C: nop

;}
RECOMP_FUNC void _sufreezy_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089B70: syscall     804
    recomp_syscall_handler(rdram, ctx, 0x80089B70);
    return;
    // 0x80089B74: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _sueggmove_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A460: syscall     842
    recomp_syscall_handler(rdram, ctx, 0x8008A460);
    return;
    // 0x8008A464: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80809540_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80809540: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80809544: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80809548: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8080954C: lw          $t6, 0x188($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X188);
    // 0x80809550: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80809554: jal         0x808024B0
    // 0x80809558: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    func_808024B0_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80809558: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    after_0:
    // 0x8080955C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80809560: jal         0x8080613C
    // 0x80809564: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_8080613C_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80809564: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x80809568: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8080956C: jal         0x8009BB00
    // 0x80809570: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x80809570: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x80809574: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80809578: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8080957C: lwc1        $f4, 0x1CC($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X1CC);
    // 0x80809580: jal         0x800F2100
    // 0x80809584: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    mlAbsF(rdram, ctx);
        goto after_3;
    // 0x80809584: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80809588: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8080958C: jal         0x800F2100
    // 0x80809590: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    mlAbsF(rdram, ctx);
        goto after_4;
    // 0x80809590: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x80809594: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80809598: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8080959C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808095A0: beq         $v1, $zero, L_808095C0
    if (ctx->r3 == 0) {
        // 0x808095A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808095C0;
    }
    // 0x808095A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808095A8: beq         $v1, $at, L_808095E4
    if (ctx->r3 == ctx->r1) {
        // 0x808095AC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808095E4;
    }
    // 0x808095AC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808095B0: beq         $v1, $at, L_8080964C
    if (ctx->r3 == ctx->r1) {
        // 0x808095B4: lw          $t0, 0x30($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X30);
            goto L_8080964C;
    }
    // 0x808095B4: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x808095B8: b           L_8080967C
    // 0x808095BC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8080967C;
    // 0x808095BC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_808095C0:
    // 0x808095C0: add.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x808095C4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808095C8: nop

    // 0x808095CC: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x808095D0: nop

    // 0x808095D4: bc1fl       L_8080967C
    if (!c1cs) {
        // 0x808095D8: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8080967C;
    }
    goto skip_0;
    // 0x808095D8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_0:
    // 0x808095DC: b           L_8080967C
    // 0x808095E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080967C;
    // 0x808095E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808095E4:
    // 0x808095E4: add.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x808095E8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x808095EC: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x808095F0: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x808095F4: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x808095F8: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA598) << 16);
    // 0x808095FC: bc1fl       L_80809628
    if (!c1cs) {
        // 0x80809600: lwc1        $f6, 0x4($t9)
        ctx->f6.u32l = MEM_W(ctx->r25, 0X4);
            goto L_80809628;
    }
    goto skip_1;
    // 0x80809600: lwc1        $f6, 0x4($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X4);
    skip_1:
    // 0x80809604: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80809608: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8080960C: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80809610: nop

    // 0x80809614: bc1fl       L_80809628
    if (!c1cs) {
        // 0x80809618: lwc1        $f6, 0x4($t9)
        ctx->f6.u32l = MEM_W(ctx->r25, 0X4);
            goto L_80809628;
    }
    goto skip_2;
    // 0x80809618: lwc1        $f6, 0x4($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X4);
    skip_2:
    // 0x8080961C: b           L_8080967C
    // 0x80809620: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080967C;
    // 0x80809620: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80809624: lwc1        $f6, 0x4($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X4);
L_80809628:
    // 0x80809628: lwc1        $f8, -0x5A68($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA598));
    // 0x8080962C: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80809630: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80809634: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80809638: nop

    // 0x8080963C: bc1fl       L_8080967C
    if (!c1cs) {
        // 0x80809640: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8080967C;
    }
    goto skip_3;
    // 0x80809640: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_3:
    // 0x80809644: b           L_8080967C
    // 0x80809648: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8080967C;
    // 0x80809648: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8080964C:
    // 0x8080964C: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA59C) << 16);
    // 0x80809650: lwc1        $f6, -0x5A64($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA59C));
    // 0x80809654: lwc1        $f4, 0x4($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80809658: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8080965C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80809660: c.lt.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
    // 0x80809664: nop

    // 0x80809668: bc1fl       L_8080967C
    if (!c1cs) {
        // 0x8080966C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8080967C;
    }
    goto skip_4;
    // 0x8080966C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_4:
    // 0x80809670: b           L_8080967C
    // 0x80809674: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080967C;
    // 0x80809674: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80809678: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8080967C:
    // 0x8080967C: jr          $ra
    // 0x80809680: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80809680: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void _bswalk_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084270: syscall     107
    recomp_syscall_handler(rdram, ctx, 0x80084270);
    return;
    // 0x80084274: addi        $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
;}
RECOMP_FUNC void func_800822C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
L_800822C0:
    // 0x800822C0: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x800822C4: andi        $t4, $t5, 0x3
    ctx->r12 = ctx->r13 & 0X3;
    // 0x800822C8: xor         $t5, $t5, $t4
    ctx->r13 = ctx->r13 ^ ctx->r12;
    // 0x800822CC: beq         $t4, $zero, L_80082300
    if (ctx->r12 == 0) {
        // 0x800822D0: addu        $t5, $t5, $t0
        ctx->r13 = ADD32(ctx->r13, ctx->r8);
            goto L_80082300;
    }
    // 0x800822D0: addu        $t5, $t5, $t0
    ctx->r13 = ADD32(ctx->r13, ctx->r8);
    // 0x800822D4: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x800822D8: beql        $t4, $zero, L_80082314
    if (ctx->r12 == 0) {
        // 0x800822DC: lw          $t6, 0x0($t5)
        ctx->r14 = MEM_W(ctx->r13, 0X0);
            goto L_80082314;
    }
    goto skip_0;
    // 0x800822DC: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    skip_0:
    // 0x800822E0: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x800822E4: beq         $t4, $zero, L_80082334
    if (ctx->r12 == 0) {
        // 0x800822E8: nop
    
            goto L_80082334;
    }
    // 0x800822E8: nop

    // 0x800822EC: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x800822F0: beql        $t4, $zero, L_80082340
    if (ctx->r12 == 0) {
        // 0x800822F4: lh          $t6, 0x2($t5)
        ctx->r14 = MEM_H(ctx->r13, 0X2);
            goto L_80082340;
    }
    goto skip_1;
    // 0x800822F4: lh          $t6, 0x2($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X2);
    skip_1:
    // 0x800822F8: j           L_8008236C
    // 0x800822FC: nop

        goto L_8008236C;
    // 0x800822FC: nop

L_80082300:
    // 0x80082300: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80082304: addu        $t6, $t6, $t1
    ctx->r14 = ADD32(ctx->r14, ctx->r9);
    // 0x80082308: j           L_8008236C
    // 0x8008230C: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
        goto L_8008236C;
    // 0x8008230C: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x80082310: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
L_80082314:
    // 0x80082314: sra         $t7, $t1, 2
    ctx->r15 = S32(SIGNED(ctx->r9) >> 2);
    // 0x80082318: lui         $t8, 0xFC00
    ctx->r24 = S32(0XFC00 << 16);
    // 0x8008231C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80082320: xor         $t6, $t6, $t7
    ctx->r14 = ctx->r14 ^ ctx->r15;
    // 0x80082324: and         $t6, $t6, $t8
    ctx->r14 = ctx->r14 & ctx->r24;
    // 0x80082328: xor         $t6, $t6, $t7
    ctx->r14 = ctx->r14 ^ ctx->r15;
    // 0x8008232C: j           L_8008236C
    // 0x80082330: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
        goto L_8008236C;
    // 0x80082330: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
L_80082334:
    // 0x80082334: j           L_8008236C
    // 0x80082338: or          $t9, $t5, $zero
    ctx->r25 = ctx->r13 | 0;
        goto L_8008236C;
    // 0x80082338: or          $t9, $t5, $zero
    ctx->r25 = ctx->r13 | 0;
    // 0x8008233C: lh          $t6, 0x2($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X2);
L_80082340:
    // 0x80082340: addu        $t6, $t6, $t1
    ctx->r14 = ADD32(ctx->r14, ctx->r9);
    // 0x80082344: beq         $t9, $zero, L_8008236C
    if (ctx->r25 == 0) {
        // 0x80082348: sh          $t6, 0x2($t5)
        MEM_H(0X2, ctx->r13) = ctx->r14;
            goto L_8008236C;
    }
    // 0x80082348: sh          $t6, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r14;
    // 0x8008234C: lh          $t7, 0x2($t9)
    ctx->r15 = MEM_H(ctx->r25, 0X2);
    // 0x80082350: srl         $t8, $t6, 15
    ctx->r24 = S32(U32(ctx->r14) >> 15);
    // 0x80082354: andi        $t8, $t8, 0x1
    ctx->r24 = ctx->r24 & 0X1;
    // 0x80082358: srl         $t6, $t6, 16
    ctx->r14 = S32(U32(ctx->r14) >> 16);
    // 0x8008235C: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x80082360: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80082364: sh          $t7, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r15;
    // 0x80082368: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
L_8008236C:
    // 0x8008236C: addiu       $t3, $t3, -0x1
    ctx->r11 = ADD32(ctx->r11, -0X1);
    // 0x80082370: bne         $t3, $zero, L_800822C0
    if (ctx->r11 != 0) {
        // 0x80082374: addiu       $t2, $t2, 0x4
        ctx->r10 = ADD32(ctx->r10, 0X4);
            goto L_800822C0;
    }
    // 0x80082374: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x80082378: jr          $ra
    // 0x8008237C: nop

    return;
    // 0x8008237C: nop

;}
RECOMP_FUNC void func_8080024C_chcablespark(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080024C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800250: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800254: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800258: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080025C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800260: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800264: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800268: jal         0x800DC178
    // 0x8080026C: sb          $zero, 0x18($a0)
    MEM_B(0X18, ctx->r4) = 0;
    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x8080026C: sb          $zero, 0x18($a0)
    MEM_B(0X18, ctx->r4) = 0;
    after_0:
    // 0x80800270: lhu         $t6, 0x76($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X76);
    // 0x80800274: addiu       $at, $zero, 0x35
    ctx->r1 = ADD32(0, 0X35);
    // 0x80800278: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x8080027C: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800280: bne         $t7, $at, L_808002A0
    if (ctx->r15 != ctx->r1) {
        // 0x80800284: nop
    
            goto L_808002A0;
    }
    // 0x80800284: nop

    // 0x80800288: jal         0x80800828
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800828_chcablespark(rdram, ctx);
        goto after_1;
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800290: beq         $v0, $zero, L_808002A0
    if (ctx->r2 == 0) {
        // 0x80800294: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002A0;
    }
    // 0x80800294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800298: jal         0x8008A4B0
    // 0x8080029C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x8080029C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_808002A0:
    // 0x808002A0: jal         0x808008BC
    // 0x808002A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008BC_chcablespark(rdram, ctx);
        goto after_3;
    // 0x808002A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808002A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002B4: jr          $ra
    // 0x808002B8: nop

    return;
    // 0x808002B8: nop

;}
RECOMP_FUNC void func_808009FC_chkingjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800A00: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800A04: addiu       $at, $zero, 0x14FD
    ctx->r1 = ADD32(0, 0X14FD);
    // 0x80800A08: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800A0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A10: beq         $a1, $at, L_80800A2C
    if (ctx->r5 == ctx->r1) {
        // 0x80800A14: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80800A2C;
    }
    // 0x80800A14: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800A18: addiu       $at, $zero, 0x1535
    ctx->r1 = ADD32(0, 0X1535);
    // 0x80800A1C: beq         $a1, $at, L_80800A60
    if (ctx->r5 == ctx->r1) {
        // 0x80800A20: nop
    
            goto L_80800A60;
    }
    // 0x80800A20: nop

    // 0x80800A24: b           L_80800A88
    // 0x80800A28: nop

        goto L_80800A88;
    // 0x80800A28: nop

L_80800A2C:
    // 0x80800A2C: jal         0x800DA544
    // 0x80800A30: addiu       $a0, $zero, 0x1A5
    ctx->r4 = ADD32(0, 0X1A5);
    func_800DA544(rdram, ctx);
        goto after_0;
    // 0x80800A30: addiu       $a0, $zero, 0x1A5
    ctx->r4 = ADD32(0, 0X1A5);
    after_0:
    // 0x80800A34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800A3C: jal         0x80800CFC
    // 0x80800A40: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_80800CFC_chkingjinjo(rdram, ctx);
        goto after_1;
    // 0x80800A40: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_1:
    // 0x80800A44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A48: jal         0x80102424
    // 0x80800A4C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x80800A4C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_2:
    // 0x80800A50: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1296, 0X1124) << 16);
    // 0x80800A54: lwc1        $f4, 0x1124($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1296, 0X1124));
    // 0x80800A58: b           L_80800AD0
    // 0x80800A5C: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_80800AD0;
    // 0x80800A5C: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_80800A60:
    // 0x80800A60: jal         0x80800C18
    // 0x80800A64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800C18_chkingjinjo(rdram, ctx);
        goto after_3;
    // 0x80800A64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800A68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A6C: jal         0x80102424
    // 0x80800A70: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_4;
    // 0x80800A70: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x80800A74: addiu       $a0, $zero, 0x143
    ctx->r4 = ADD32(0, 0X143);
    // 0x80800A78: jal         0x800887D8
    // 0x80800A7C: addiu       $a1, $zero, 0x65
    ctx->r5 = ADD32(0, 0X65);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_5;
    // 0x80800A7C: addiu       $a1, $zero, 0x65
    ctx->r5 = ADD32(0, 0X65);
    after_5:
    // 0x80800A80: b           L_80800AD4
    // 0x80800A84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800AD4;
    // 0x80800A84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800A88:
    // 0x80800A88: jal         0x800DA298
    // 0x80800A8C: addiu       $a0, $zero, 0x360
    ctx->r4 = ADD32(0, 0X360);
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x80800A8C: addiu       $a0, $zero, 0x360
    ctx->r4 = ADD32(0, 0X360);
    after_6:
    // 0x80800A90: bnel        $v0, $zero, L_80800AD4
    if (ctx->r2 != 0) {
        // 0x80800A94: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800AD4;
    }
    goto skip_0;
    // 0x80800A94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800A98: lw          $t6, 0x6C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X6C);
    // 0x80800A9C: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80800AA0: beq         $t7, $zero, L_80800AB0
    if (ctx->r15 == 0) {
        // 0x80800AA4: nop
    
            goto L_80800AB0;
    }
    // 0x80800AA4: nop

    // 0x80800AA8: jal         0x80800C18
    // 0x80800AAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800C18_chkingjinjo(rdram, ctx);
        goto after_7;
    // 0x80800AAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
L_80800AB0:
    // 0x80800AB0: jal         0x800DA298
    // 0x80800AB4: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    func_800DA298(rdram, ctx);
        goto after_8;
    // 0x80800AB4: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    after_8:
    // 0x80800AB8: beq         $v0, $zero, L_80800AC8
    if (ctx->r2 == 0) {
        // 0x80800ABC: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_80800AC8;
    }
    // 0x80800ABC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800AC0: b           L_80800AC8
    // 0x80800AC4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
        goto L_80800AC8;
    // 0x80800AC4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
L_80800AC8:
    // 0x80800AC8: jal         0x80102424
    // 0x80800ACC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102424(rdram, ctx);
        goto after_9;
    // 0x80800ACC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
L_80800AD0:
    // 0x80800AD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800AD4:
    // 0x80800AD4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800AD8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800ADC: jr          $ra
    // 0x80800AE0: nop

    return;
    // 0x80800AE0: nop

;}
RECOMP_FUNC void func_80801588_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801588: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080158C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801590: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801594: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x80801598: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080159C: bne         $t6, $zero, L_808015B4
    if (ctx->r14 != 0) {
        // 0x808015A0: nop
    
            goto L_808015B4;
    }
    // 0x808015A0: nop

    // 0x808015A4: jal         0x80800774
    // 0x808015A8: nop

    func_80800774_chclockworkmouse(rdram, ctx);
        goto after_0;
    // 0x808015A8: nop

    after_0:
    // 0x808015AC: b           L_80801838
    // 0x808015B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801838;
    // 0x808015B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808015B4:
    // 0x808015B4: jal         0x800D8FF8
    // 0x808015B8: nop

    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x808015B8: nop

    after_1:
    // 0x808015BC: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x808015C0: jal         0x80106790
    // 0x808015C4: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_2;
    // 0x808015C4: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_2:
    // 0x808015C8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x808015CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015D0: jal         0x80100094
    // 0x808015D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x808015D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808015D8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x808015DC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808015E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808015E4: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808015E8: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808015EC: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x808015F0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808015F4: nop

    // 0x808015F8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x808015FC: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80801600: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80801604: lhu         $t7, 0x72($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X72);
    // 0x80801608: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x8080160C: addiu       $t9, $t8, -0x2
    ctx->r25 = ADD32(ctx->r24, -0X2);
    // 0x80801610: sltiu       $at, $t9, 0x10
    ctx->r1 = ctx->r25 < 0X10 ? 1 : 0;
    // 0x80801614: beq         $at, $zero, L_80801808
    if (ctx->r1 == 0) {
        // 0x80801618: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80801808;
    }
    // 0x80801618: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8080161C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1564, 0X373C) << 16);
    // 0x80801620: addu        $at, $at, $t9
    gpr jr_addend_80801628 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80801624: lw          $t9, 0x373C($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1564, 0X373C));
    // 0x80801628: jr          $t9
    // 0x8080162C: nop

    switch (jr_addend_80801628 >> 2) {
        case 0: goto L_80801630; break;
        case 1: goto L_80801668; break;
        case 2: goto L_808016A0; break;
        case 3: goto L_80801758; break;
        case 4: goto L_80801768; break;
        case 5: goto L_808017E8; break;
        case 6: goto L_808017E8; break;
        case 7: goto L_808017B4; break;
        case 8: goto L_808017B4; break;
        case 9: goto L_808017B4; break;
        case 10: goto L_808017E8; break;
        case 11: goto L_808017E8; break;
        case 12: goto L_808017F8; break;
        case 13: goto L_808017F8; break;
        case 14: goto L_80801808; break;
        case 15: goto L_80801630; break;
        default: switch_error(__func__, 0x80801628, 0x8080373C);
    }
    // 0x8080162C: nop

L_80801630:
    // 0x80801630: jal         0x80800774
    // 0x80801634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800774_chclockworkmouse(rdram, ctx);
        goto after_4;
    // 0x80801634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801638: jal         0x80090178
    // 0x8080163C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80090178(rdram, ctx);
        goto after_5;
    // 0x8080163C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x80801640: beq         $v0, $zero, L_80801808
    if (ctx->r2 == 0) {
        // 0x80801644: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80801808;
    }
    // 0x80801644: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80801648: jal         0x8010C9B0
    // 0x8080164C: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    func_8010C9B0(rdram, ctx);
        goto after_6;
    // 0x8080164C: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    after_6:
    // 0x80801650: beq         $v0, $zero, L_80801808
    if (ctx->r2 == 0) {
        // 0x80801654: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801808;
    }
    // 0x80801654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801658: jal         0x80800E8C
    // 0x8080165C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800E8C_chclockworkmouse(rdram, ctx);
        goto after_7;
    // 0x8080165C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
    // 0x80801660: b           L_8080180C
    // 0x80801664: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
        goto L_8080180C;
    // 0x80801664: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
L_80801668:
    // 0x80801668: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8080166C: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x80801670: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    // 0x80801674: jal         0x8010CB0C
    // 0x80801678: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8010CB0C(rdram, ctx);
        goto after_8;
    // 0x80801678: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x8080167C: beql        $v0, $zero, L_8080180C
    if (ctx->r2 == 0) {
        // 0x80801680: lw          $t4, 0x34($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X34);
            goto L_8080180C;
    }
    goto skip_0;
    // 0x80801680: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x80801684: jal         0x800DA544
    // 0x80801688: addiu       $a0, $zero, 0x42B
    ctx->r4 = ADD32(0, 0X42B);
    func_800DA544(rdram, ctx);
        goto after_9;
    // 0x80801688: addiu       $a0, $zero, 0x42B
    ctx->r4 = ADD32(0, 0X42B);
    after_9:
    // 0x8080168C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801690: jal         0x80800E8C
    // 0x80801694: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800E8C_chclockworkmouse(rdram, ctx);
        goto after_10;
    // 0x80801694: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_10:
    // 0x80801698: b           L_8080180C
    // 0x8080169C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
        goto L_8080180C;
    // 0x8080169C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
L_808016A0:
    // 0x808016A0: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(1564, 0X3E3C) << 16);
    // 0x808016A4: addiu       $t1, $t1, 0x3E3C
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(1564, 0X3E3C));
    // 0x808016A8: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x808016AC: addiu       $t0, $sp, 0x28
    ctx->r8 = ADD32(ctx->r29, 0X28);
    // 0x808016B0: lw          $t3, 0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X4);
    // 0x808016B4: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x808016B8: lw          $at, 0x8($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X8);
    // 0x808016BC: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808016C0: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
    // 0x808016C4: jal         0x800907C0
    // 0x808016C8: sw          $at, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r1;
    func_800907C0(rdram, ctx);
        goto after_11;
    // 0x808016C8: sw          $at, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r1;
    after_11:
    // 0x808016CC: jal         0x80090010
    // 0x808016D0: nop

    func_80090010(rdram, ctx);
        goto after_12;
    // 0x808016D0: nop

    after_12:
    // 0x808016D4: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x808016D8: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808016DC: jal         0x800F1DCC
    // 0x808016E0: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    func_800F1DCC(rdram, ctx);
        goto after_13;
    // 0x808016E0: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    after_13:
    // 0x808016E4: lui         $at, 0xC20C
    ctx->r1 = S32(0XC20C << 16);
    // 0x808016E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808016EC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x808016F0: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x808016F4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x808016F8: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808016FC: bc1t        L_8080171C
    if (c1cs) {
        // 0x80801700: nop
    
            goto L_8080171C;
    }
    // 0x80801700: nop

    // 0x80801704: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801708: nop

    // 0x8080170C: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80801710: nop

    // 0x80801714: bc1f        L_80801748
    if (!c1cs) {
        // 0x80801718: nop
    
            goto L_80801748;
    }
    // 0x80801718: nop

L_8080171C:
    // 0x8080171C: mul.s       $f18, $f2, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80801720: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80801724: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801728: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8080172C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80801730: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80801734: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80801738: jal         0x800906DC
    // 0x8080173C: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    func_800906DC(rdram, ctx);
        goto after_14;
    // 0x8080173C: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    after_14:
    // 0x80801740: b           L_8080180C
    // 0x80801744: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
        goto L_8080180C;
    // 0x80801744: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
L_80801748:
    // 0x80801748: jal         0x8080019C
    // 0x8080174C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    func_8080019C_chclockworkmouse(rdram, ctx);
        goto after_15;
    // 0x8080174C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_15:
    // 0x80801750: b           L_8080180C
    // 0x80801754: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
        goto L_8080180C;
    // 0x80801754: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
L_80801758:
    // 0x80801758: jal         0x80800ED0
    // 0x8080175C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800ED0_chclockworkmouse(rdram, ctx);
        goto after_16;
    // 0x8080175C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80801760: b           L_8080180C
    // 0x80801764: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
        goto L_8080180C;
    // 0x80801764: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
L_80801768:
    // 0x80801768: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8080176C: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    // 0x80801770: jal         0x80800F10
    // 0x80801774: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_80800F10_chclockworkmouse(rdram, ctx);
        goto after_17;
    // 0x80801774: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_17:
    // 0x80801778: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x8080177C: jal         0x8080111C
    // 0x80801780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080111C_chclockworkmouse(rdram, ctx);
        goto after_18;
    // 0x80801780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80801784: jal         0x80800ED0
    // 0x80801788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800ED0_chclockworkmouse(rdram, ctx);
        goto after_19;
    // 0x80801788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x8080178C: jal         0x80801240
    // 0x80801790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801240_chclockworkmouse(rdram, ctx);
        goto after_20;
    // 0x80801790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80801794: jal         0x80105A5C
    // 0x80801798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_21;
    // 0x80801798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x8080179C: beq         $v0, $zero, L_80801808
    if (ctx->r2 == 0) {
        // 0x808017A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801808;
    }
    // 0x808017A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017A4: jal         0x80800E8C
    // 0x808017A8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800E8C_chclockworkmouse(rdram, ctx);
        goto after_22;
    // 0x808017A8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_22:
    // 0x808017AC: b           L_8080180C
    // 0x808017B0: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
        goto L_8080180C;
    // 0x808017B0: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
L_808017B4:
    // 0x808017B4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808017B8: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    // 0x808017BC: jal         0x80800F10
    // 0x808017C0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_80800F10_chclockworkmouse(rdram, ctx);
        goto after_23;
    // 0x808017C0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_23:
    // 0x808017C4: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x808017C8: jal         0x8080111C
    // 0x808017CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080111C_chclockworkmouse(rdram, ctx);
        goto after_24;
    // 0x808017CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x808017D0: jal         0x80800ED0
    // 0x808017D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800ED0_chclockworkmouse(rdram, ctx);
        goto after_25;
    // 0x808017D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x808017D8: jal         0x80801240
    // 0x808017DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801240_chclockworkmouse(rdram, ctx);
        goto after_26;
    // 0x808017DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x808017E0: b           L_8080180C
    // 0x808017E4: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
        goto L_8080180C;
    // 0x808017E4: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
L_808017E8:
    // 0x808017E8: jal         0x80801508
    // 0x808017EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801508_chclockworkmouse(rdram, ctx);
        goto after_27;
    // 0x808017EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x808017F0: b           L_8080180C
    // 0x808017F4: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
        goto L_8080180C;
    // 0x808017F4: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
L_808017F8:
    // 0x808017F8: jal         0x80800774
    // 0x808017FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800774_chclockworkmouse(rdram, ctx);
        goto after_28;
    // 0x808017FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x80801800: jal         0x80801508
    // 0x80801804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801508_chclockworkmouse(rdram, ctx);
        goto after_29;
    // 0x80801804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
L_80801808:
    // 0x80801808: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
L_8080180C:
    // 0x8080180C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801810: lbu         $v0, 0xFB($t4)
    ctx->r2 = MEM_BU(ctx->r12, 0XFB);
    // 0x80801814: beq         $v0, $at, L_80801824
    if (ctx->r2 == ctx->r1) {
        // 0x80801818: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80801824;
    }
    // 0x80801818: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080181C: bnel        $v0, $at, L_80801838
    if (ctx->r2 != ctx->r1) {
        // 0x80801820: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801838;
    }
    goto skip_1;
    // 0x80801820: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
L_80801824:
    // 0x80801824: jal         0x80800A44
    // 0x80801828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800A44_chclockworkmouse(rdram, ctx);
        goto after_30;
    // 0x80801828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x8080182C: jal         0x808004B0
    // 0x80801830: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808004B0_chclockworkmouse(rdram, ctx);
        goto after_31;
    // 0x80801830: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x80801834: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801838:
    // 0x80801838: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080183C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80801840: jr          $ra
    // 0x80801844: nop

    return;
    // 0x80801844: nop

;}
RECOMP_FUNC void chfaircoin_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000C0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808000C4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808000C8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808000CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808000D4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808000D8: jal         0x80108474
    // 0x808000DC: addiu       $a0, $zero, 0x166
    ctx->r4 = ADD32(0, 0X166);
    func_80108474(rdram, ctx);
        goto after_0;
    // 0x808000DC: addiu       $a0, $zero, 0x166
    ctx->r4 = ADD32(0, 0X166);
    after_0:
    // 0x808000E0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808000E4: addiu       $a0, $v0, 0x18
    ctx->r4 = ADD32(ctx->r2, 0X18);
    // 0x808000E8: jal         0x800EE7F8
    // 0x808000EC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x808000EC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x808000F0: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x808000F4: jal         0x800EE7F8
    // 0x808000F8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x808000F8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808000FC: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800100: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2128, 0X150) << 16);
    // 0x80800104: addiu       $a1, $a1, 0x150
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2128, 0X150));
    // 0x80800108: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080010C: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80800110: jal         0x800C4AF0
    // 0x80800114: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    func_800C4AF0(rdram, ctx);
        goto after_3;
    // 0x80800114: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    after_3:
    // 0x80800118: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080011C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80800120: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800124: jr          $ra
    // 0x80800128: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800128: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void bakey_func_80091C14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091C14: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80091C18: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80091C1C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80091C20: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80091C24: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80091C28: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80091C2C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80091C30: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80091C34: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80091C38: addiu       $s3, $zero, 0xE
    ctx->r19 = ADD32(0, 0XE);
    // 0x80091C3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80091C40:
    // 0x80091C40: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80091C44: jal         0x80091C80
    // 0x80091C48: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    bakey_setState(rdram, ctx);
        goto after_0;
    // 0x80091C48: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_0:
    // 0x80091C4C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80091C50: bnel        $s0, $s3, L_80091C40
    if (ctx->r16 != ctx->r19) {
        // 0x80091C54: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80091C40;
    }
    goto skip_0;
    // 0x80091C54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x80091C58: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80091C5C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80091C60: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80091C64: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80091C68: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80091C6C: jr          $ra
    // 0x80091C70: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80091C70: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void vplight_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800114: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800118: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080011C: jal         0x8001B084
    // 0x80800120: nop

    heap_free(rdram, ctx);
        goto after_0;
    // 0x80800120: nop

    after_0:
    // 0x80800124: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800128: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080012C: jr          $ra
    // 0x80800130: nop

    return;
    // 0x80800130: nop

;}
RECOMP_FUNC void func_80804170_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804170: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80804174: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80804178: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8080417C: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x80804180: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80804184: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80804188: jal         0x80100094
    // 0x8080418C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080418C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80804190: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x80804194: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80804198: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8080419C: sltiu       $at, $t7, 0x37
    ctx->r1 = ctx->r15 < 0X37 ? 1 : 0;
    // 0x808041A0: beq         $at, $zero, L_808053A0
    if (ctx->r1 == 0) {
        // 0x808041A4: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_808053A0;
    }
    // 0x808041A4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808041A8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X680C) << 16);
    // 0x808041AC: addu        $at, $at, $t7
    gpr jr_addend_808041B4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808041B0: lw          $t7, 0x680C($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2484, 0X680C));
    // 0x808041B4: jr          $t7
    // 0x808041B8: nop

    switch (jr_addend_808041B4 >> 2) {
        case 0: goto L_808041BC; break;
        case 1: goto L_808041F0; break;
        case 2: goto L_80804208; break;
        case 3: goto L_80804220; break;
        case 4: goto L_80804248; break;
        case 5: goto L_80804270; break;
        case 6: goto L_80804298; break;
        case 7: goto L_8080431C; break;
        case 8: goto L_808043A0; break;
        case 9: goto L_808043DC; break;
        case 10: goto L_80804478; break;
        case 11: goto L_808053A0; break;
        case 12: goto L_80804544; break;
        case 13: goto L_80804794; break;
        case 14: goto L_808045BC; break;
        case 15: goto L_80804818; break;
        case 16: goto L_80804664; break;
        case 17: goto L_808048C0; break;
        case 18: goto L_8080470C; break;
        case 19: goto L_80804968; break;
        case 20: goto L_80804A3C; break;
        case 21: goto L_808049C8; break;
        case 22: goto L_80804A7C; break;
        case 23: goto L_80804AF0; break;
        case 24: goto L_80804B64; break;
        case 25: goto L_80804BDC; break;
        case 26: goto L_80804DA0; break;
        case 27: goto L_80804DB8; break;
        case 28: goto L_80804DE8; break;
        case 29: goto L_80804DF8; break;
        case 30: goto L_808053A0; break;
        case 31: goto L_80804E1C; break;
        case 32: goto L_80804E40; break;
        case 33: goto L_80804E90; break;
        case 34: goto L_80804EE8; break;
        case 35: goto L_80804F3C; break;
        case 36: goto L_80804F90; break;
        case 37: goto L_80804FA8; break;
        case 38: goto L_80804FD8; break;
        case 39: goto L_80805008; break;
        case 40: goto L_80805038; break;
        case 41: goto L_80805068; break;
        case 42: goto L_80805098; break;
        case 43: goto L_808050C8; break;
        case 44: goto L_808050F0; break;
        case 45: goto L_80805118; break;
        case 46: goto L_80805140; break;
        case 47: goto L_80805168; break;
        case 48: goto L_80805190; break;
        case 49: goto L_808051B8; break;
        case 50: goto L_808051E0; break;
        case 51: goto L_80805208; break;
        case 52: goto L_80805268; break;
        case 53: goto L_80805370; break;
        case 54: goto L_80805388; break;
        default: switch_error(__func__, 0x808041B4, 0x8080680C);
    }
    // 0x808041B8: nop

L_808041BC:
    // 0x808041BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808041C0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808041C4: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x808041C8: jal         0x80801408
    // 0x808041CC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80801408_chquiz(rdram, ctx);
        goto after_1;
    // 0x808041CC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x808041D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808041D4: jal         0x80102424
    // 0x808041D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x808041D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x808041DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808041E0: jal         0x808014F8
    // 0x808041E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808014F8_chquiz(rdram, ctx);
        goto after_3;
    // 0x808041E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808041E8: b           L_808053A4
    // 0x808041EC: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x808041EC: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_808041F0:
    // 0x808041F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808041F4: addiu       $a1, $zero, 0x1460
    ctx->r5 = ADD32(0, 0X1460);
    // 0x808041F8: jal         0x80803B54
    // 0x808041FC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80803B54_chquiz(rdram, ctx);
        goto after_4;
    // 0x808041FC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_4:
    // 0x80804200: b           L_808053A4
    // 0x80804204: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x80804204: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80804208:
    // 0x80804208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080420C: addiu       $a1, $zero, 0x1461
    ctx->r5 = ADD32(0, 0X1461);
    // 0x80804210: jal         0x80803B54
    // 0x80804214: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80803B54_chquiz(rdram, ctx);
        goto after_5;
    // 0x80804214: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_5:
    // 0x80804218: b           L_808053A4
    // 0x8080421C: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x8080421C: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80804220:
    // 0x80804220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804224: addiu       $a1, $zero, 0x1463
    ctx->r5 = ADD32(0, 0X1463);
    // 0x80804228: jal         0x80803B54
    // 0x8080422C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80803B54_chquiz(rdram, ctx);
        goto after_6;
    // 0x8080422C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_6:
    // 0x80804230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804234: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80804238: jal         0x8080100C
    // 0x8080423C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8080100C_chquiz(rdram, ctx);
        goto after_7;
    // 0x8080423C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x80804240: b           L_808053A4
    // 0x80804244: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x80804244: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80804248:
    // 0x80804248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080424C: addiu       $a1, $zero, 0x1465
    ctx->r5 = ADD32(0, 0X1465);
    // 0x80804250: jal         0x80803B54
    // 0x80804254: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80803B54_chquiz(rdram, ctx);
        goto after_8;
    // 0x80804254: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_8:
    // 0x80804258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080425C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80804260: jal         0x8080100C
    // 0x80804264: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8080100C_chquiz(rdram, ctx);
        goto after_9;
    // 0x80804264: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x80804268: b           L_808053A4
    // 0x8080426C: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x8080426C: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80804270:
    // 0x80804270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804274: addiu       $a1, $zero, 0x1464
    ctx->r5 = ADD32(0, 0X1464);
    // 0x80804278: jal         0x80803B54
    // 0x8080427C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80803B54_chquiz(rdram, ctx);
        goto after_10;
    // 0x8080427C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_10:
    // 0x80804280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804284: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80804288: jal         0x8080100C
    // 0x8080428C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_8080100C_chquiz(rdram, ctx);
        goto after_11;
    // 0x8080428C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_11:
    // 0x80804290: b           L_808053A4
    // 0x80804294: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x80804294: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80804298:
    // 0x80804298: jal         0x800DA298
    // 0x8080429C: addiu       $a0, $zero, 0x584
    ctx->r4 = ADD32(0, 0X584);
    func_800DA298(rdram, ctx);
        goto after_12;
    // 0x8080429C: addiu       $a0, $zero, 0x584
    ctx->r4 = ADD32(0, 0X584);
    after_12:
    // 0x808042A0: beq         $v0, $zero, L_808042BC
    if (ctx->r2 == 0) {
        // 0x808042A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808042BC;
    }
    // 0x808042A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808042A8: addiu       $a1, $zero, 0x146A
    ctx->r5 = ADD32(0, 0X146A);
    // 0x808042AC: jal         0x80803B54
    // 0x808042B0: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    func_80803B54_chquiz(rdram, ctx);
        goto after_13;
    // 0x808042B0: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    after_13:
    // 0x808042B4: b           L_808042D4
    // 0x808042B8: nop

        goto L_808042D4;
    // 0x808042B8: nop

L_808042BC:
    // 0x808042BC: jal         0x800DA544
    // 0x808042C0: addiu       $a0, $zero, 0x584
    ctx->r4 = ADD32(0, 0X584);
    func_800DA544(rdram, ctx);
        goto after_14;
    // 0x808042C0: addiu       $a0, $zero, 0x584
    ctx->r4 = ADD32(0, 0X584);
    after_14:
    // 0x808042C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808042C8: addiu       $a1, $zero, 0x1466
    ctx->r5 = ADD32(0, 0X1466);
    // 0x808042CC: jal         0x80803B54
    // 0x808042D0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80803B54_chquiz(rdram, ctx);
        goto after_15;
    // 0x808042D0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_15:
L_808042D4:
    // 0x808042D4: jal         0x80801724
    // 0x808042D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80801724_chquiz(rdram, ctx);
        goto after_16;
    // 0x808042D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_16:
    // 0x808042DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808042E0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808042E4: jal         0x8080100C
    // 0x808042E8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_8080100C_chquiz(rdram, ctx);
        goto after_17;
    // 0x808042E8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_17:
    // 0x808042EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808042F0: jal         0x80102424
    // 0x808042F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_18;
    // 0x808042F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_18:
    // 0x808042F8: jal         0x8008A848
    // 0x808042FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _suquiz_entrypoint_18(rdram, ctx);
        goto after_19;
    // 0x808042FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_19:
    // 0x80804300: addiu       $a0, $zero, 0x1A89
    ctx->r4 = ADD32(0, 0X1A89);
    // 0x80804304: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80804308: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080430C: jal         0x800861A0
    // 0x80804310: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    _chintrotext_entrypoint_1(rdram, ctx);
        goto after_20;
    // 0x80804310: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_20:
    // 0x80804314: b           L_808053A4
    // 0x80804318: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x80804318: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_8080431C:
    // 0x8080431C: jal         0x800DA298
    // 0x80804320: addiu       $a0, $zero, 0x585
    ctx->r4 = ADD32(0, 0X585);
    func_800DA298(rdram, ctx);
        goto after_21;
    // 0x80804320: addiu       $a0, $zero, 0x585
    ctx->r4 = ADD32(0, 0X585);
    after_21:
    // 0x80804324: beq         $v0, $zero, L_80804340
    if (ctx->r2 == 0) {
        // 0x80804328: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80804340;
    }
    // 0x80804328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080432C: addiu       $a1, $zero, 0x146B
    ctx->r5 = ADD32(0, 0X146B);
    // 0x80804330: jal         0x80803B54
    // 0x80804334: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    func_80803B54_chquiz(rdram, ctx);
        goto after_22;
    // 0x80804334: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    after_22:
    // 0x80804338: b           L_80804358
    // 0x8080433C: nop

        goto L_80804358;
    // 0x8080433C: nop

L_80804340:
    // 0x80804340: jal         0x800DA544
    // 0x80804344: addiu       $a0, $zero, 0x585
    ctx->r4 = ADD32(0, 0X585);
    func_800DA544(rdram, ctx);
        goto after_23;
    // 0x80804344: addiu       $a0, $zero, 0x585
    ctx->r4 = ADD32(0, 0X585);
    after_23:
    // 0x80804348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080434C: addiu       $a1, $zero, 0x1467
    ctx->r5 = ADD32(0, 0X1467);
    // 0x80804350: jal         0x80803B54
    // 0x80804354: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80803B54_chquiz(rdram, ctx);
        goto after_24;
    // 0x80804354: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_24:
L_80804358:
    // 0x80804358: jal         0x80801724
    // 0x8080435C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80801724_chquiz(rdram, ctx);
        goto after_25;
    // 0x8080435C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_25:
    // 0x80804360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804364: jal         0x80102424
    // 0x80804368: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_26;
    // 0x80804368: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_26:
    // 0x8080436C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804370: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80804374: jal         0x8080100C
    // 0x80804378: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_8080100C_chquiz(rdram, ctx);
        goto after_27;
    // 0x80804378: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_27:
    // 0x8080437C: jal         0x8008A848
    // 0x80804380: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    _suquiz_entrypoint_18(rdram, ctx);
        goto after_28;
    // 0x80804380: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_28:
    // 0x80804384: addiu       $a0, $zero, 0x1A89
    ctx->r4 = ADD32(0, 0X1A89);
    // 0x80804388: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080438C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80804390: jal         0x800861A0
    // 0x80804394: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    _chintrotext_entrypoint_1(rdram, ctx);
        goto after_29;
    // 0x80804394: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_29:
    // 0x80804398: b           L_808053A4
    // 0x8080439C: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x8080439C: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_808043A0:
    // 0x808043A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808043A4: jal         0x80102424
    // 0x808043A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_30;
    // 0x808043A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_30:
    // 0x808043AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808043B0: addiu       $a1, $zero, 0x1462
    ctx->r5 = ADD32(0, 0X1462);
    // 0x808043B4: jal         0x80803B54
    // 0x808043B8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80803B54_chquiz(rdram, ctx);
        goto after_31;
    // 0x808043B8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_31:
    // 0x808043BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808043C0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808043C4: jal         0x8080100C
    // 0x808043C8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_8080100C_chquiz(rdram, ctx);
        goto after_32;
    // 0x808043C8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_32:
    // 0x808043CC: jal         0x8008A848
    // 0x808043D0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    _suquiz_entrypoint_18(rdram, ctx);
        goto after_33;
    // 0x808043D0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_33:
    // 0x808043D4: b           L_808053A4
    // 0x808043D8: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x808043D8: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_808043DC:
    // 0x808043DC: jal         0x800DA298
    // 0x808043E0: addiu       $a0, $zero, 0x586
    ctx->r4 = ADD32(0, 0X586);
    func_800DA298(rdram, ctx);
        goto after_34;
    // 0x808043E0: addiu       $a0, $zero, 0x586
    ctx->r4 = ADD32(0, 0X586);
    after_34:
    // 0x808043E4: beq         $v0, $zero, L_80804400
    if (ctx->r2 == 0) {
        // 0x808043E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80804400;
    }
    // 0x808043E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808043EC: addiu       $a1, $zero, 0x146C
    ctx->r5 = ADD32(0, 0X146C);
    // 0x808043F0: jal         0x80803B54
    // 0x808043F4: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    func_80803B54_chquiz(rdram, ctx);
        goto after_35;
    // 0x808043F4: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    after_35:
    // 0x808043F8: b           L_80804418
    // 0x808043FC: nop

        goto L_80804418;
    // 0x808043FC: nop

L_80804400:
    // 0x80804400: jal         0x800DA544
    // 0x80804404: addiu       $a0, $zero, 0x586
    ctx->r4 = ADD32(0, 0X586);
    func_800DA544(rdram, ctx);
        goto after_36;
    // 0x80804404: addiu       $a0, $zero, 0x586
    ctx->r4 = ADD32(0, 0X586);
    after_36:
    // 0x80804408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080440C: addiu       $a1, $zero, 0x1468
    ctx->r5 = ADD32(0, 0X1468);
    // 0x80804410: jal         0x80803B54
    // 0x80804414: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80803B54_chquiz(rdram, ctx);
        goto after_37;
    // 0x80804414: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_37:
L_80804418:
    // 0x80804418: jal         0x80801724
    // 0x8080441C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80801724_chquiz(rdram, ctx);
        goto after_38;
    // 0x8080441C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_38:
    // 0x80804420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804424: jal         0x80102424
    // 0x80804428: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_39;
    // 0x80804428: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_39:
    // 0x8080442C: lw          $t8, 0x34($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X34);
    // 0x80804430: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80804434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804438: bne         $t8, $at, L_80804448
    if (ctx->r24 != ctx->r1) {
        // 0x8080443C: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_80804448;
    }
    // 0x8080443C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80804440: b           L_8080444C
    // 0x80804444: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
        goto L_8080444C;
    // 0x80804444: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
L_80804448:
    // 0x80804448: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
L_8080444C:
    // 0x8080444C: jal         0x8080100C
    // 0x80804450: andi        $a2, $a3, 0xFF
    ctx->r6 = ctx->r7 & 0XFF;
    func_8080100C_chquiz(rdram, ctx);
        goto after_40;
    // 0x80804450: andi        $a2, $a3, 0xFF
    ctx->r6 = ctx->r7 & 0XFF;
    after_40:
    // 0x80804454: jal         0x8008A848
    // 0x80804458: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    _suquiz_entrypoint_18(rdram, ctx);
        goto after_41;
    // 0x80804458: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_41:
    // 0x8080445C: addiu       $a0, $zero, 0x1A89
    ctx->r4 = ADD32(0, 0X1A89);
    // 0x80804460: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80804464: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80804468: jal         0x800861A0
    // 0x8080446C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    _chintrotext_entrypoint_1(rdram, ctx);
        goto after_42;
    // 0x8080446C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_42:
    // 0x80804470: b           L_808053A4
    // 0x80804474: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x80804474: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80804478:
    // 0x80804478: jal         0x8080154C
    // 0x8080447C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8080154C_chquiz(rdram, ctx);
        goto after_43;
    // 0x8080447C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_43:
    // 0x80804480: beq         $v0, $zero, L_808044BC
    if (ctx->r2 == 0) {
        // 0x80804484: nop
    
            goto L_808044BC;
    }
    // 0x80804484: nop

    // 0x80804488: jal         0x800D3948
    // 0x8080448C: nop

    func_800D3948(rdram, ctx);
        goto after_44;
    // 0x8080448C: nop

    after_44:
    // 0x80804490: beq         $v0, $zero, L_808044AC
    if (ctx->r2 == 0) {
        // 0x80804494: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808044AC;
    }
    // 0x80804494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080449C: jal         0x80804170
    // 0x808044A0: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    func_80804170_chquiz(rdram, ctx);
        goto after_45;
    // 0x808044A0: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    after_45:
    // 0x808044A4: b           L_808053AC
    // 0x808044A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808053AC;
    // 0x808044A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808044AC:
    // 0x808044AC: jal         0x80804170
    // 0x808044B0: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    func_80804170_chquiz(rdram, ctx);
        goto after_46;
    // 0x808044B0: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    after_46:
    // 0x808044B4: b           L_808053AC
    // 0x808044B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808053AC;
    // 0x808044B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808044BC:
    // 0x808044BC: jal         0x808008D4
    // 0x808044C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008D4_chquiz(rdram, ctx);
        goto after_47;
    // 0x808044C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_47:
    // 0x808044C4: jal         0x80800A70
    // 0x808044C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800A70_chquiz(rdram, ctx);
        goto after_48;
    // 0x808044C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_48:
    // 0x808044CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808044D0: jal         0x80102424
    // 0x808044D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_49;
    // 0x808044D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_49:
    // 0x808044D8: jal         0x80800B6C
    // 0x808044DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800B6C_chquiz(rdram, ctx);
        goto after_50;
    // 0x808044DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_50:
    // 0x808044E0: jal         0x80800B90
    // 0x808044E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80800B90_chquiz(rdram, ctx);
        goto after_51;
    // 0x808044E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_51:
    // 0x808044E8: beq         $v0, $zero, L_80804504
    if (ctx->r2 == 0) {
        // 0x808044EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80804504;
    }
    // 0x808044EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808044F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808044F4: beq         $v0, $at, L_80804514
    if (ctx->r2 == ctx->r1) {
        // 0x808044F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80804514;
    }
    // 0x808044F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808044FC: b           L_808053A4
    // 0x80804500: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x80804500: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80804504:
    // 0x80804504: jal         0x80804170
    // 0x80804508: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_80804170_chquiz(rdram, ctx);
        goto after_52;
    // 0x80804508: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_52:
    // 0x8080450C: b           L_808053AC
    // 0x80804510: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808053AC;
    // 0x80804510: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80804514:
    // 0x80804514: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80804518: jal         0x8080100C
    // 0x8080451C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_8080100C_chquiz(rdram, ctx);
        goto after_53;
    // 0x8080451C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_53:
    // 0x80804520: addiu       $a0, $zero, 0x14A1
    ctx->r4 = ADD32(0, 0X14A1);
    // 0x80804524: jal         0x800DC128
    // 0x80804528: addiu       $a1, $zero, 0x14A4
    ctx->r5 = ADD32(0, 0X14A4);
    func_800DC128(rdram, ctx);
        goto after_54;
    // 0x80804528: addiu       $a1, $zero, 0x14A4
    ctx->r5 = ADD32(0, 0X14A4);
    after_54:
    // 0x8080452C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804530: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80804534: jal         0x80803B54
    // 0x80804538: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    func_80803B54_chquiz(rdram, ctx);
        goto after_55;
    // 0x80804538: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    after_55:
    // 0x8080453C: b           L_808053A4
    // 0x80804540: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x80804540: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80804544:
    // 0x80804544: lhu         $t9, 0x72($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X72);
    // 0x80804548: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8080454C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804550: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x80804554: beq         $t0, $at, L_80804568
    if (ctx->r8 == ctx->r1) {
        // 0x80804558: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_80804568;
    }
    // 0x80804558: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8080455C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80804560: b           L_80804570
    // 0x80804564: sw          $t1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r9;
        goto L_80804570;
    // 0x80804564: sw          $t1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r9;
L_80804568:
    // 0x80804568: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8080456C: sw          $t2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r10;
L_80804570:
    // 0x80804570: jal         0x8080100C
    // 0x80804574: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    func_8080100C_chquiz(rdram, ctx);
        goto after_56;
    // 0x80804574: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    after_56:
    // 0x80804578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080457C: jal         0x8080034C
    // 0x80804580: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8080034C_chquiz(rdram, ctx);
        goto after_57;
    // 0x80804580: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_57:
    // 0x80804584: jal         0x8008A850
    // 0x80804588: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    _suquiz_entrypoint_19(rdram, ctx);
        goto after_58;
    // 0x80804588: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    after_58:
    // 0x8080458C: jal         0x8008A7F8
    // 0x80804590: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    _suquiz_entrypoint_8(rdram, ctx);
        goto after_59;
    // 0x80804590: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    after_59:
    // 0x80804594: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80804598: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080459C: jal         0x808016F8
    // 0x808045A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808016F8_chquiz(rdram, ctx);
        goto after_60;
    // 0x808045A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_60:
    // 0x808045A4: addiu       $a0, $zero, 0x529
    ctx->r4 = ADD32(0, 0X529);
    // 0x808045A8: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    // 0x808045AC: jal         0x80101180
    // 0x808045B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_61;
    // 0x808045B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_61:
    // 0x808045B4: b           L_808053A4
    // 0x808045B8: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x808045B8: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_808045BC:
    // 0x808045BC: jal         0x8008A7E8
    // 0x808045C0: nop

    _suquiz_entrypoint_6(rdram, ctx);
        goto after_62;
    // 0x808045C0: nop

    after_62:
    // 0x808045C4: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x808045C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808045CC: jal         0x8080034C
    // 0x808045D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8080034C_chquiz(rdram, ctx);
        goto after_63;
    // 0x808045D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_63:
    // 0x808045D4: jal         0x80801544
    // 0x808045D8: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    func_80801544_chquiz(rdram, ctx);
        goto after_64;
    // 0x808045D8: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    after_64:
    // 0x808045DC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x808045E0: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x808045E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808045E8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808045EC: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x808045F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808045F4: jal         0x80801058
    // 0x808045F8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_80801058_chquiz(rdram, ctx);
        goto after_65;
    // 0x808045F8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_65:
    // 0x808045FC: jal         0x8008A810
    // 0x80804600: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    _suquiz_entrypoint_11(rdram, ctx);
        goto after_66;
    // 0x80804600: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    after_66:
    // 0x80804604: bne         $v0, $zero, L_8080463C
    if (ctx->r2 != 0) {
        // 0x80804608: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8080463C;
    }
    // 0x80804608: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080460C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80804610: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80804614: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80804618: jal         0x800DC178
    // 0x8080461C: nop

    func_800DC178(rdram, ctx);
        goto after_67;
    // 0x8080461C: nop

    after_67:
    // 0x80804620: lbu         $t4, 0x65($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X65);
    // 0x80804624: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80804628: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080462C: andi        $t5, $t4, 0xFFEF
    ctx->r13 = ctx->r12 & 0XFFEF;
    // 0x80804630: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x80804634: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
    // 0x80804638: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
L_8080463C:
    // 0x8080463C: jal         0x8008A850
    // 0x80804640: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    _suquiz_entrypoint_19(rdram, ctx);
        goto after_68;
    // 0x80804640: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_68:
    // 0x80804644: jal         0x8008A7F8
    // 0x80804648: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    _suquiz_entrypoint_8(rdram, ctx);
        goto after_69;
    // 0x80804648: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_69:
    // 0x8080464C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80804650: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80804654: jal         0x808016F8
    // 0x80804658: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808016F8_chquiz(rdram, ctx);
        goto after_70;
    // 0x80804658: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_70:
    // 0x8080465C: b           L_808053A4
    // 0x80804660: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x80804660: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80804664:
    // 0x80804664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804668: jal         0x80102424
    // 0x8080466C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_71;
    // 0x8080466C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_71:
    // 0x80804670: jal         0x800FC660
    // 0x80804674: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_800FC660(rdram, ctx);
        goto after_72;
    // 0x80804674: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_72:
    // 0x80804678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080467C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80804680: jal         0x8080100C
    // 0x80804684: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    func_8080100C_chquiz(rdram, ctx);
        goto after_73;
    // 0x80804684: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    after_73:
    // 0x80804688: jal         0x8008A7D8
    // 0x8080468C: nop

    _suquiz_entrypoint_4(rdram, ctx);
        goto after_74;
    // 0x8080468C: nop

    after_74:
    // 0x80804690: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80804694: bne         $v0, $at, L_808046CC
    if (ctx->r2 != ctx->r1) {
        // 0x80804698: addiu       $a0, $zero, 0x1479
        ctx->r4 = ADD32(0, 0X1479);
            goto L_808046CC;
    }
    // 0x80804698: addiu       $a0, $zero, 0x1479
    ctx->r4 = ADD32(0, 0X1479);
    // 0x8080469C: addiu       $a0, $zero, 0x1485
    ctx->r4 = ADD32(0, 0X1485);
    // 0x808046A0: jal         0x800DC128
    // 0x808046A4: addiu       $a1, $zero, 0x148B
    ctx->r5 = ADD32(0, 0X148B);
    func_800DC128(rdram, ctx);
        goto after_75;
    // 0x808046A4: addiu       $a1, $zero, 0x148B
    ctx->r5 = ADD32(0, 0X148B);
    after_75:
    // 0x808046A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808046AC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808046B0: jal         0x80803B54
    // 0x808046B4: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    func_80803B54_chquiz(rdram, ctx);
        goto after_76;
    // 0x808046B4: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    after_76:
    // 0x808046B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808046BC: jal         0x8080034C
    // 0x808046C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8080034C_chquiz(rdram, ctx);
        goto after_77;
    // 0x808046C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_77:
    // 0x808046C4: b           L_808046E4
    // 0x808046C8: nop

        goto L_808046E4;
    // 0x808046C8: nop

L_808046CC:
    // 0x808046CC: jal         0x800DC128
    // 0x808046D0: addiu       $a1, $zero, 0x147F
    ctx->r5 = ADD32(0, 0X147F);
    func_800DC128(rdram, ctx);
        goto after_78;
    // 0x808046D0: addiu       $a1, $zero, 0x147F
    ctx->r5 = ADD32(0, 0X147F);
    after_78:
    // 0x808046D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808046D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808046DC: jal         0x80803B54
    // 0x808046E0: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    func_80803B54_chquiz(rdram, ctx);
        goto after_79;
    // 0x808046E0: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    after_79:
L_808046E4:
    // 0x808046E4: jal         0x808008B0
    // 0x808046E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008B0_chquiz(rdram, ctx);
        goto after_80;
    // 0x808046E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_80:
    // 0x808046EC: jal         0x8008A7E8
    // 0x808046F0: nop

    _suquiz_entrypoint_6(rdram, ctx);
        goto after_81;
    // 0x808046F0: nop

    after_81:
    // 0x808046F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808046F8: addiu       $a1, $zero, 0x63
    ctx->r5 = ADD32(0, 0X63);
    // 0x808046FC: jal         0x80801760
    // 0x80804700: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80801760_chquiz(rdram, ctx);
        goto after_82;
    // 0x80804700: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_82:
    // 0x80804704: b           L_808053A4
    // 0x80804708: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x80804708: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_8080470C:
    // 0x8080470C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804710: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80804714: jal         0x8080100C
    // 0x80804718: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_8080100C_chquiz(rdram, ctx);
        goto after_83;
    // 0x80804718: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_83:
    // 0x8080471C: jal         0x8008A7D8
    // 0x80804720: nop

    _suquiz_entrypoint_4(rdram, ctx);
        goto after_84;
    // 0x80804720: nop

    after_84:
    // 0x80804724: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80804728: bne         $v0, $at, L_80804754
    if (ctx->r2 != ctx->r1) {
        // 0x8080472C: addiu       $a0, $zero, 0x14AA
        ctx->r4 = ADD32(0, 0X14AA);
            goto L_80804754;
    }
    // 0x8080472C: addiu       $a0, $zero, 0x14AA
    ctx->r4 = ADD32(0, 0X14AA);
    // 0x80804730: addiu       $a0, $zero, 0x14B0
    ctx->r4 = ADD32(0, 0X14B0);
    // 0x80804734: jal         0x800DC128
    // 0x80804738: addiu       $a1, $zero, 0x14B6
    ctx->r5 = ADD32(0, 0X14B6);
    func_800DC128(rdram, ctx);
        goto after_85;
    // 0x80804738: addiu       $a1, $zero, 0x14B6
    ctx->r5 = ADD32(0, 0X14B6);
    after_85:
    // 0x8080473C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804740: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80804744: jal         0x80803B54
    // 0x80804748: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    func_80803B54_chquiz(rdram, ctx);
        goto after_86;
    // 0x80804748: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    after_86:
    // 0x8080474C: b           L_8080476C
    // 0x80804750: nop

        goto L_8080476C;
    // 0x80804750: nop

L_80804754:
    // 0x80804754: jal         0x800DC128
    // 0x80804758: addiu       $a1, $zero, 0x14B0
    ctx->r5 = ADD32(0, 0X14B0);
    func_800DC128(rdram, ctx);
        goto after_87;
    // 0x80804758: addiu       $a1, $zero, 0x14B0
    ctx->r5 = ADD32(0, 0X14B0);
    after_87:
    // 0x8080475C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804760: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80804764: jal         0x80803B54
    // 0x80804768: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    func_80803B54_chquiz(rdram, ctx);
        goto after_88;
    // 0x80804768: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    after_88:
L_8080476C:
    // 0x8080476C: jal         0x808008B0
    // 0x80804770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008B0_chquiz(rdram, ctx);
        goto after_89;
    // 0x80804770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_89:
    // 0x80804774: jal         0x8008A7E8
    // 0x80804778: nop

    _suquiz_entrypoint_6(rdram, ctx);
        goto after_90;
    // 0x80804778: nop

    after_90:
    // 0x8080477C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80804780: addiu       $a1, $zero, 0x67
    ctx->r5 = ADD32(0, 0X67);
    // 0x80804784: jal         0x80801760
    // 0x80804788: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80801760_chquiz(rdram, ctx);
        goto after_91;
    // 0x80804788: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_91:
    // 0x8080478C: b           L_808053A4
    // 0x80804790: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x80804790: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80804794:
    // 0x80804794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804798: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8080479C: jal         0x8080100C
    // 0x808047A0: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_8080100C_chquiz(rdram, ctx);
        goto after_92;
    // 0x808047A0: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_92:
    // 0x808047A4: jal         0x8008A7E8
    // 0x808047A8: nop

    _suquiz_entrypoint_6(rdram, ctx);
        goto after_93;
    // 0x808047A8: nop

    after_93:
    // 0x808047AC: addiu       $a0, $zero, 0x529
    ctx->r4 = ADD32(0, 0X529);
    // 0x808047B0: addiu       $a1, $zero, 0x85
    ctx->r5 = ADD32(0, 0X85);
    // 0x808047B4: jal         0x80101180
    // 0x808047B8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80101180(rdram, ctx);
        goto after_94;
    // 0x808047B8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_94:
    // 0x808047BC: jal         0x8008A850
    // 0x808047C0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    _suquiz_entrypoint_19(rdram, ctx);
        goto after_95;
    // 0x808047C0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_95:
    // 0x808047C4: addiu       $a0, $zero, 0x529
    ctx->r4 = ADD32(0, 0X529);
    // 0x808047C8: addiu       $a1, $zero, 0x86
    ctx->r5 = ADD32(0, 0X86);
    // 0x808047CC: jal         0x80101180
    // 0x808047D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_96;
    // 0x808047D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_96:
    // 0x808047D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808047D8: jal         0x8080034C
    // 0x808047DC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8080034C_chquiz(rdram, ctx);
        goto after_97;
    // 0x808047DC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_97:
    // 0x808047E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808047E4: jal         0x80100094
    // 0x808047E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_98;
    // 0x808047E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_98:
    // 0x808047EC: jal         0x80087E10
    // 0x808047F0: lw          $a0, 0x94($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X94);
    _gcnewoption_entrypoint_47(rdram, ctx);
        goto after_99;
    // 0x808047F0: lw          $a0, 0x94($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X94);
    after_99:
    // 0x808047F4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x808047F8: jal         0x8008A7F8
    // 0x808047FC: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    _suquiz_entrypoint_8(rdram, ctx);
        goto after_100;
    // 0x808047FC: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_100:
    // 0x80804800: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80804804: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80804808: jal         0x808016F8
    // 0x8080480C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_808016F8_chquiz(rdram, ctx);
        goto after_101;
    // 0x8080480C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_101:
    // 0x80804810: b           L_808053A4
    // 0x80804814: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x80804814: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80804818:
    // 0x80804818: jal         0x8008A7E8
    // 0x8080481C: nop

    _suquiz_entrypoint_6(rdram, ctx);
        goto after_102;
    // 0x8080481C: nop

    after_102:
    // 0x80804820: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x80804824: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804828: jal         0x8080034C
    // 0x8080482C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8080034C_chquiz(rdram, ctx);
        goto after_103;
    // 0x8080482C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_103:
    // 0x80804830: jal         0x80801544
    // 0x80804834: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    func_80801544_chquiz(rdram, ctx);
        goto after_104;
    // 0x80804834: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_104:
    // 0x80804838: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080483C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80804840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804844: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80804848: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x8080484C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80804850: jal         0x80801058
    // 0x80804854: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_80801058_chquiz(rdram, ctx);
        goto after_105;
    // 0x80804854: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_105:
    // 0x80804858: jal         0x8008A810
    // 0x8080485C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    _suquiz_entrypoint_11(rdram, ctx);
        goto after_106;
    // 0x8080485C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_106:
    // 0x80804860: bne         $v0, $zero, L_80804898
    if (ctx->r2 != 0) {
        // 0x80804864: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80804898;
    }
    // 0x80804864: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80804868: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080486C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80804870: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80804874: jal         0x800DC178
    // 0x80804878: nop

    func_800DC178(rdram, ctx);
        goto after_107;
    // 0x80804878: nop

    after_107:
    // 0x8080487C: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x80804880: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80804884: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80804888: andi        $t8, $t7, 0xFFEF
    ctx->r24 = ctx->r15 & 0XFFEF;
    // 0x8080488C: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x80804890: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    // 0x80804894: swc1        $f6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f6.u32l;
L_80804898:
    // 0x80804898: jal         0x8008A850
    // 0x8080489C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    _suquiz_entrypoint_19(rdram, ctx);
        goto after_108;
    // 0x8080489C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_108:
    // 0x808048A0: jal         0x8008A7F8
    // 0x808048A4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    _suquiz_entrypoint_8(rdram, ctx);
        goto after_109;
    // 0x808048A4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_109:
    // 0x808048A8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808048AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808048B0: jal         0x808016F8
    // 0x808048B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808016F8_chquiz(rdram, ctx);
        goto after_110;
    // 0x808048B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_110:
    // 0x808048B8: b           L_808053A4
    // 0x808048BC: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x808048BC: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_808048C0:
    // 0x808048C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808048C4: jal         0x80102424
    // 0x808048C8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_111;
    // 0x808048C8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_111:
    // 0x808048CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808048D0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808048D4: jal         0x8080100C
    // 0x808048D8: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_8080100C_chquiz(rdram, ctx);
        goto after_112;
    // 0x808048D8: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_112:
    // 0x808048DC: jal         0x800FC660
    // 0x808048E0: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_800FC660(rdram, ctx);
        goto after_113;
    // 0x808048E0: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_113:
    // 0x808048E4: jal         0x8008A7D8
    // 0x808048E8: nop

    _suquiz_entrypoint_4(rdram, ctx);
        goto after_114;
    // 0x808048E8: nop

    after_114:
    // 0x808048EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808048F0: bne         $v0, $at, L_8080491C
    if (ctx->r2 != ctx->r1) {
        // 0x808048F4: addiu       $a0, $zero, 0x147F
        ctx->r4 = ADD32(0, 0X147F);
            goto L_8080491C;
    }
    // 0x808048F4: addiu       $a0, $zero, 0x147F
    ctx->r4 = ADD32(0, 0X147F);
    // 0x808048F8: addiu       $a0, $zero, 0x14B6
    ctx->r4 = ADD32(0, 0X14B6);
    // 0x808048FC: jal         0x800DC128
    // 0x80804900: addiu       $a1, $zero, 0x14BC
    ctx->r5 = ADD32(0, 0X14BC);
    func_800DC128(rdram, ctx);
        goto after_115;
    // 0x80804900: addiu       $a1, $zero, 0x14BC
    ctx->r5 = ADD32(0, 0X14BC);
    after_115:
    // 0x80804904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804908: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8080490C: jal         0x80803B54
    // 0x80804910: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    func_80803B54_chquiz(rdram, ctx);
        goto after_116;
    // 0x80804910: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    after_116:
    // 0x80804914: b           L_80804934
    // 0x80804918: nop

        goto L_80804934;
    // 0x80804918: nop

L_8080491C:
    // 0x8080491C: jal         0x800DC128
    // 0x80804920: addiu       $a1, $zero, 0x1485
    ctx->r5 = ADD32(0, 0X1485);
    func_800DC128(rdram, ctx);
        goto after_117;
    // 0x80804920: addiu       $a1, $zero, 0x1485
    ctx->r5 = ADD32(0, 0X1485);
    after_117:
    // 0x80804924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804928: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8080492C: jal         0x80803B54
    // 0x80804930: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    func_80803B54_chquiz(rdram, ctx);
        goto after_118;
    // 0x80804930: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    after_118:
L_80804934:
    // 0x80804934: jal         0x808008B0
    // 0x80804938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008B0_chquiz(rdram, ctx);
        goto after_119;
    // 0x80804938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_119:
    // 0x8080493C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804940: jal         0x8080034C
    // 0x80804944: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8080034C_chquiz(rdram, ctx);
        goto after_120;
    // 0x80804944: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_120:
    // 0x80804948: jal         0x8008A7E8
    // 0x8080494C: nop

    _suquiz_entrypoint_6(rdram, ctx);
        goto after_121;
    // 0x8080494C: nop

    after_121:
    // 0x80804950: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80804954: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x80804958: jal         0x80801760
    // 0x8080495C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80801760_chquiz(rdram, ctx);
        goto after_122;
    // 0x8080495C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_122:
    // 0x80804960: b           L_808053A4
    // 0x80804964: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x80804964: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80804968:
    // 0x80804968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080496C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80804970: jal         0x8080100C
    // 0x80804974: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_8080100C_chquiz(rdram, ctx);
        goto after_123;
    // 0x80804974: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_123:
    // 0x80804978: addiu       $a0, $zero, 0x14DA
    ctx->r4 = ADD32(0, 0X14DA);
    // 0x8080497C: jal         0x800DC128
    // 0x80804980: addiu       $a1, $zero, 0x14E0
    ctx->r5 = ADD32(0, 0X14E0);
    func_800DC128(rdram, ctx);
        goto after_124;
    // 0x80804980: addiu       $a1, $zero, 0x14E0
    ctx->r5 = ADD32(0, 0X14E0);
    after_124:
    // 0x80804984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804988: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8080498C: jal         0x80803B54
    // 0x80804990: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    func_80803B54_chquiz(rdram, ctx);
        goto after_125;
    // 0x80804990: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    after_125:
    // 0x80804994: jal         0x808008B0
    // 0x80804998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008B0_chquiz(rdram, ctx);
        goto after_126;
    // 0x80804998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_126:
    // 0x8080499C: jal         0x8008A7E8
    // 0x808049A0: nop

    _suquiz_entrypoint_6(rdram, ctx);
        goto after_127;
    // 0x808049A0: nop

    after_127:
    // 0x808049A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808049A8: addiu       $a1, $zero, 0x68
    ctx->r5 = ADD32(0, 0X68);
    // 0x808049AC: jal         0x80801760
    // 0x808049B0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80801760_chquiz(rdram, ctx);
        goto after_128;
    // 0x808049B0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_128:
    // 0x808049B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808049B8: jal         0x8080034C
    // 0x808049BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8080034C_chquiz(rdram, ctx);
        goto after_129;
    // 0x808049BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_129:
    // 0x808049C0: b           L_808053A4
    // 0x808049C4: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x808049C4: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_808049C8:
    // 0x808049C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808049CC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808049D0: jal         0x8080100C
    // 0x808049D4: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    func_8080100C_chquiz(rdram, ctx);
        goto after_130;
    // 0x808049D4: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_130:
    // 0x808049D8: jal         0x8008A7D8
    // 0x808049DC: nop

    _suquiz_entrypoint_4(rdram, ctx);
        goto after_131;
    // 0x808049DC: nop

    after_131:
    // 0x808049E0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808049E4: bne         $v0, $at, L_80804A10
    if (ctx->r2 != ctx->r1) {
        // 0x808049E8: addiu       $a0, $zero, 0x146D
        ctx->r4 = ADD32(0, 0X146D);
            goto L_80804A10;
    }
    // 0x808049E8: addiu       $a0, $zero, 0x146D
    ctx->r4 = ADD32(0, 0X146D);
    // 0x808049EC: addiu       $a0, $zero, 0x14BC
    ctx->r4 = ADD32(0, 0X14BC);
    // 0x808049F0: jal         0x800DC128
    // 0x808049F4: addiu       $a1, $zero, 0x14C2
    ctx->r5 = ADD32(0, 0X14C2);
    func_800DC128(rdram, ctx);
        goto after_132;
    // 0x808049F4: addiu       $a1, $zero, 0x14C2
    ctx->r5 = ADD32(0, 0X14C2);
    after_132:
    // 0x808049F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808049FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80804A00: jal         0x80803B54
    // 0x80804A04: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    func_80803B54_chquiz(rdram, ctx);
        goto after_133;
    // 0x80804A04: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    after_133:
    // 0x80804A08: b           L_80804A2C
    // 0x80804A0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80804A2C;
    // 0x80804A0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80804A10:
    // 0x80804A10: jal         0x800DC128
    // 0x80804A14: addiu       $a1, $zero, 0x1473
    ctx->r5 = ADD32(0, 0X1473);
    func_800DC128(rdram, ctx);
        goto after_134;
    // 0x80804A14: addiu       $a1, $zero, 0x1473
    ctx->r5 = ADD32(0, 0X1473);
    after_134:
    // 0x80804A18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804A1C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80804A20: jal         0x80803B54
    // 0x80804A24: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    func_80803B54_chquiz(rdram, ctx);
        goto after_135;
    // 0x80804A24: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    after_135:
    // 0x80804A28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80804A2C:
    // 0x80804A2C: jal         0x8080034C
    // 0x80804A30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8080034C_chquiz(rdram, ctx);
        goto after_136;
    // 0x80804A30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_136:
    // 0x80804A34: b           L_808053A4
    // 0x80804A38: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x80804A38: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80804A3C:
    // 0x80804A3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804A40: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80804A44: jal         0x8080100C
    // 0x80804A48: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    func_8080100C_chquiz(rdram, ctx);
        goto after_137;
    // 0x80804A48: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    after_137:
    // 0x80804A4C: addiu       $a0, $zero, 0x149A
    ctx->r4 = ADD32(0, 0X149A);
    // 0x80804A50: jal         0x800DC128
    // 0x80804A54: addiu       $a1, $zero, 0x14A0
    ctx->r5 = ADD32(0, 0X14A0);
    func_800DC128(rdram, ctx);
        goto after_138;
    // 0x80804A54: addiu       $a1, $zero, 0x14A0
    ctx->r5 = ADD32(0, 0X14A0);
    after_138:
    // 0x80804A58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804A5C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80804A60: jal         0x80803B54
    // 0x80804A64: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    func_80803B54_chquiz(rdram, ctx);
        goto after_139;
    // 0x80804A64: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    after_139:
    // 0x80804A68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804A6C: jal         0x8080034C
    // 0x80804A70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8080034C_chquiz(rdram, ctx);
        goto after_140;
    // 0x80804A70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_140:
    // 0x80804A74: b           L_808053A4
    // 0x80804A78: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x80804A78: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80804A7C:
    // 0x80804A7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804A80: jal         0x80102424
    // 0x80804A84: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_141;
    // 0x80804A84: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_141:
    // 0x80804A88: jal         0x800FC660
    // 0x80804A8C: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC660(rdram, ctx);
        goto after_142;
    // 0x80804A8C: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_142:
    // 0x80804A90: jal         0x808008B0
    // 0x80804A94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008B0_chquiz(rdram, ctx);
        goto after_143;
    // 0x80804A94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_143:
    // 0x80804A98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804A9C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80804AA0: jal         0x8080100C
    // 0x80804AA4: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_8080100C_chquiz(rdram, ctx);
        goto after_144;
    // 0x80804AA4: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_144:
    // 0x80804AA8: addiu       $a0, $zero, 0x1473
    ctx->r4 = ADD32(0, 0X1473);
    // 0x80804AAC: jal         0x800DC128
    // 0x80804AB0: addiu       $a1, $zero, 0x1479
    ctx->r5 = ADD32(0, 0X1479);
    func_800DC128(rdram, ctx);
        goto after_145;
    // 0x80804AB0: addiu       $a1, $zero, 0x1479
    ctx->r5 = ADD32(0, 0X1479);
    after_145:
    // 0x80804AB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804AB8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80804ABC: jal         0x80803B54
    // 0x80804AC0: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    func_80803B54_chquiz(rdram, ctx);
        goto after_146;
    // 0x80804AC0: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    after_146:
    // 0x80804AC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804AC8: jal         0x8080034C
    // 0x80804ACC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8080034C_chquiz(rdram, ctx);
        goto after_147;
    // 0x80804ACC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_147:
    // 0x80804AD0: jal         0x8008A7E8
    // 0x80804AD4: nop

    _suquiz_entrypoint_6(rdram, ctx);
        goto after_148;
    // 0x80804AD4: nop

    after_148:
    // 0x80804AD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80804ADC: addiu       $a1, $zero, 0x65
    ctx->r5 = ADD32(0, 0X65);
    // 0x80804AE0: jal         0x80801760
    // 0x80804AE4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80801760_chquiz(rdram, ctx);
        goto after_149;
    // 0x80804AE4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_149:
    // 0x80804AE8: b           L_808053A4
    // 0x80804AEC: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x80804AEC: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80804AF0:
    // 0x80804AF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804AF4: jal         0x80102424
    // 0x80804AF8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_150;
    // 0x80804AF8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_150:
    // 0x80804AFC: jal         0x800FC660
    // 0x80804B00: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC660(rdram, ctx);
        goto after_151;
    // 0x80804B00: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_151:
    // 0x80804B04: jal         0x808008B0
    // 0x80804B08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008B0_chquiz(rdram, ctx);
        goto after_152;
    // 0x80804B08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_152:
    // 0x80804B0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804B10: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80804B14: jal         0x8080100C
    // 0x80804B18: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    func_8080100C_chquiz(rdram, ctx);
        goto after_153;
    // 0x80804B18: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_153:
    // 0x80804B1C: addiu       $a0, $zero, 0x14A4
    ctx->r4 = ADD32(0, 0X14A4);
    // 0x80804B20: jal         0x800DC128
    // 0x80804B24: addiu       $a1, $zero, 0x14AA
    ctx->r5 = ADD32(0, 0X14AA);
    func_800DC128(rdram, ctx);
        goto after_154;
    // 0x80804B24: addiu       $a1, $zero, 0x14AA
    ctx->r5 = ADD32(0, 0X14AA);
    after_154:
    // 0x80804B28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804B2C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80804B30: jal         0x80803B54
    // 0x80804B34: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    func_80803B54_chquiz(rdram, ctx);
        goto after_155;
    // 0x80804B34: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    after_155:
    // 0x80804B38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804B3C: jal         0x8080034C
    // 0x80804B40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8080034C_chquiz(rdram, ctx);
        goto after_156;
    // 0x80804B40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_156:
    // 0x80804B44: jal         0x8008A7E8
    // 0x80804B48: nop

    _suquiz_entrypoint_6(rdram, ctx);
        goto after_157;
    // 0x80804B48: nop

    after_157:
    // 0x80804B4C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80804B50: addiu       $a1, $zero, 0x66
    ctx->r5 = ADD32(0, 0X66);
    // 0x80804B54: jal         0x80801760
    // 0x80804B58: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80801760_chquiz(rdram, ctx);
        goto after_158;
    // 0x80804B58: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_158:
    // 0x80804B5C: b           L_808053A4
    // 0x80804B60: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x80804B60: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80804B64:
    // 0x80804B64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804B68: jal         0x80102424
    // 0x80804B6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_159;
    // 0x80804B6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_159:
    // 0x80804B70: jal         0x8008A7E8
    // 0x80804B74: nop

    _suquiz_entrypoint_6(rdram, ctx);
        goto after_160;
    // 0x80804B74: nop

    after_160:
    // 0x80804B78: addiu       $a0, $zero, 0x529
    ctx->r4 = ADD32(0, 0X529);
    // 0x80804B7C: addiu       $a1, $zero, 0x84
    ctx->r5 = ADD32(0, 0X84);
    // 0x80804B80: jal         0x80101180
    // 0x80804B84: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80101180(rdram, ctx);
        goto after_161;
    // 0x80804B84: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_161:
    // 0x80804B88: jal         0x8008A7E8
    // 0x80804B8C: nop

    _suquiz_entrypoint_6(rdram, ctx);
        goto after_162;
    // 0x80804B8C: nop

    after_162:
    // 0x80804B90: addiu       $a0, $zero, 0x52E
    ctx->r4 = ADD32(0, 0X52E);
    // 0x80804B94: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    // 0x80804B98: jal         0x80101180
    // 0x80804B9C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80101180(rdram, ctx);
        goto after_163;
    // 0x80804B9C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_163:
    // 0x80804BA0: jal         0x8008A7E8
    // 0x80804BA4: nop

    _suquiz_entrypoint_6(rdram, ctx);
        goto after_164;
    // 0x80804BA4: nop

    after_164:
    // 0x80804BA8: jal         0x80801544
    // 0x80804BAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80801544_chquiz(rdram, ctx);
        goto after_165;
    // 0x80804BAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_165:
    // 0x80804BB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804BB4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80804BB8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80804BBC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80804BC0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80804BC4: jal         0x80801058
    // 0x80804BC8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_80801058_chquiz(rdram, ctx);
        goto after_166;
    // 0x80804BC8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_166:
    // 0x80804BCC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80804BD0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80804BD4: b           L_808053A0
    // 0x80804BD8: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
        goto L_808053A0;
    // 0x80804BD8: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
L_80804BDC:
    // 0x80804BDC: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    // 0x80804BE0: addiu       $a0, $zero, 0x529
    ctx->r4 = ADD32(0, 0X529);
    // 0x80804BE4: addiu       $a1, $zero, 0x3B
    ctx->r5 = ADD32(0, 0X3B);
    // 0x80804BE8: jal         0x80101180
    // 0x80804BEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_167;
    // 0x80804BEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_167:
    // 0x80804BF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804BF4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80804BF8: jal         0x8080100C
    // 0x80804BFC: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    func_8080100C_chquiz(rdram, ctx);
        goto after_168;
    // 0x80804BFC: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    after_168:
    // 0x80804C00: jal         0x8008A7D8
    // 0x80804C04: nop

    _suquiz_entrypoint_4(rdram, ctx);
        goto after_169;
    // 0x80804C04: nop

    after_169:
    // 0x80804C08: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80804C0C: bne         $v0, $at, L_80804C78
    if (ctx->r2 != ctx->r1) {
        // 0x80804C10: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80804C78;
    }
    // 0x80804C10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80804C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804C18: jal         0x80804170
    // 0x80804C1C: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    func_80804170_chquiz(rdram, ctx);
        goto after_170;
    // 0x80804C1C: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    after_170:
    // 0x80804C20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80804C24: jal         0x80801784
    // 0x80804C28: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80801784_chquiz(rdram, ctx);
        goto after_171;
    // 0x80804C28: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_171:
    // 0x80804C2C: slti        $at, $v0, 0xF
    ctx->r1 = SIGNED(ctx->r2) < 0XF ? 1 : 0;
    // 0x80804C30: beq         $at, $zero, L_80804C44
    if (ctx->r1 == 0) {
        // 0x80804C34: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80804C44;
    }
    // 0x80804C34: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80804C38: addiu       $t9, $zero, 0x1491
    ctx->r25 = ADD32(0, 0X1491);
    // 0x80804C3C: b           L_80804C54
    // 0x80804C40: sw          $t9, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r25;
        goto L_80804C54;
    // 0x80804C40: sw          $t9, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r25;
L_80804C44:
    // 0x80804C44: jal         0x808014F8
    // 0x80804C48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808014F8_chquiz(rdram, ctx);
        goto after_172;
    // 0x80804C48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_172:
    // 0x80804C4C: addiu       $t0, $zero, 0x1492
    ctx->r8 = ADD32(0, 0X1492);
    // 0x80804C50: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
L_80804C54:
    // 0x80804C54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804C58: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x80804C5C: jal         0x80803B54
    // 0x80804C60: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    func_80803B54_chquiz(rdram, ctx);
        goto after_173;
    // 0x80804C60: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    after_173:
    // 0x80804C64: lhu         $t1, 0x6E($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X6E);
    // 0x80804C68: andi        $t2, $t1, 0xFE00
    ctx->r10 = ctx->r9 & 0XFE00;
    // 0x80804C6C: ori         $t3, $t2, 0x2
    ctx->r11 = ctx->r10 | 0X2;
    // 0x80804C70: b           L_808053A8
    // 0x80804C74: sh          $t3, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r11;
        goto L_808053A8;
    // 0x80804C74: sh          $t3, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r11;
L_80804C78:
    // 0x80804C78: jal         0x80801930
    // 0x80804C7C: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    func_80801930_chquiz(rdram, ctx);
        goto after_174;
    // 0x80804C7C: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_174:
    // 0x80804C80: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80804C84: bne         $v0, $at, L_80804D3C
    if (ctx->r2 != ctx->r1) {
        // 0x80804C88: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80804D3C;
    }
    // 0x80804C88: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80804C8C: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x80804C90: lhu         $t7, 0x6E($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X6E);
    // 0x80804C94: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80804C98: andi        $t6, $t5, 0x1FF
    ctx->r14 = ctx->r13 & 0X1FF;
    // 0x80804C9C: andi        $t8, $t7, 0xFE00
    ctx->r24 = ctx->r15 & 0XFE00;
    // 0x80804CA0: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80804CA4: sh          $t9, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r25;
    // 0x80804CA8: lw          $a3, 0x6C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X6C);
    // 0x80804CAC: andi        $t0, $a3, 0x1FF
    ctx->r8 = ctx->r7 & 0X1FF;
    // 0x80804CB0: beq         $t0, $zero, L_80804CF4
    if (ctx->r8 == 0) {
        // 0x80804CB4: nop
    
            goto L_80804CF4;
    }
    // 0x80804CB4: nop

    // 0x80804CB8: beq         $t0, $at, L_80804CD0
    if (ctx->r8 == ctx->r1) {
        // 0x80804CBC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80804CD0;
    }
    // 0x80804CBC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80804CC0: beq         $t0, $at, L_80804D18
    if (ctx->r8 == ctx->r1) {
        // 0x80804CC4: nop
    
            goto L_80804D18;
    }
    // 0x80804CC4: nop

    // 0x80804CC8: b           L_80804D8C
    // 0x80804CCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80804D8C;
    // 0x80804CCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80804CD0:
    // 0x80804CD0: jal         0x8008A7D8
    // 0x80804CD4: nop

    _suquiz_entrypoint_4(rdram, ctx);
        goto after_175;
    // 0x80804CD4: nop

    after_175:
    // 0x80804CD8: bne         $v0, $zero, L_80804CEC
    if (ctx->r2 != 0) {
        // 0x80804CDC: addiu       $t2, $zero, 0x1490
        ctx->r10 = ADD32(0, 0X1490);
            goto L_80804CEC;
    }
    // 0x80804CDC: addiu       $t2, $zero, 0x1490
    ctx->r10 = ADD32(0, 0X1490);
    // 0x80804CE0: addiu       $t1, $zero, 0x148D
    ctx->r9 = ADD32(0, 0X148D);
    // 0x80804CE4: b           L_80804D88
    // 0x80804CE8: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
        goto L_80804D88;
    // 0x80804CE8: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
L_80804CEC:
    // 0x80804CEC: b           L_80804D88
    // 0x80804CF0: sw          $t2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r10;
        goto L_80804D88;
    // 0x80804CF0: sw          $t2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r10;
L_80804CF4:
    // 0x80804CF4: jal         0x8008A7D8
    // 0x80804CF8: nop

    _suquiz_entrypoint_4(rdram, ctx);
        goto after_176;
    // 0x80804CF8: nop

    after_176:
    // 0x80804CFC: bne         $v0, $zero, L_80804D10
    if (ctx->r2 != 0) {
        // 0x80804D00: addiu       $t4, $zero, 0x148E
        ctx->r12 = ADD32(0, 0X148E);
            goto L_80804D10;
    }
    // 0x80804D00: addiu       $t4, $zero, 0x148E
    ctx->r12 = ADD32(0, 0X148E);
    // 0x80804D04: addiu       $t3, $zero, 0x148B
    ctx->r11 = ADD32(0, 0X148B);
    // 0x80804D08: b           L_80804D88
    // 0x80804D0C: sw          $t3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r11;
        goto L_80804D88;
    // 0x80804D0C: sw          $t3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r11;
L_80804D10:
    // 0x80804D10: b           L_80804D88
    // 0x80804D14: sw          $t4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r12;
        goto L_80804D88;
    // 0x80804D14: sw          $t4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r12;
L_80804D18:
    // 0x80804D18: jal         0x8008A7D8
    // 0x80804D1C: nop

    _suquiz_entrypoint_4(rdram, ctx);
        goto after_177;
    // 0x80804D1C: nop

    after_177:
    // 0x80804D20: bne         $v0, $zero, L_80804D34
    if (ctx->r2 != 0) {
        // 0x80804D24: addiu       $t7, $zero, 0x148F
        ctx->r15 = ADD32(0, 0X148F);
            goto L_80804D34;
    }
    // 0x80804D24: addiu       $t7, $zero, 0x148F
    ctx->r15 = ADD32(0, 0X148F);
    // 0x80804D28: addiu       $t5, $zero, 0x148C
    ctx->r13 = ADD32(0, 0X148C);
    // 0x80804D2C: b           L_80804D88
    // 0x80804D30: sw          $t5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r13;
        goto L_80804D88;
    // 0x80804D30: sw          $t5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r13;
L_80804D34:
    // 0x80804D34: b           L_80804D88
    // 0x80804D38: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
        goto L_80804D88;
    // 0x80804D38: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
L_80804D3C:
    // 0x80804D3C: jal         0x8008A7D8
    // 0x80804D40: nop

    _suquiz_entrypoint_4(rdram, ctx);
        goto after_178;
    // 0x80804D40: nop

    after_178:
    // 0x80804D44: bne         $v0, $zero, L_80804D58
    if (ctx->r2 != 0) {
        // 0x80804D48: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80804D58;
    }
    // 0x80804D48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80804D4C: addiu       $t6, $zero, 0x14C7
    ctx->r14 = ADD32(0, 0X14C7);
    // 0x80804D50: b           L_80804D60
    // 0x80804D54: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
        goto L_80804D60;
    // 0x80804D54: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
L_80804D58:
    // 0x80804D58: addiu       $t8, $zero, 0x14C8
    ctx->r24 = ADD32(0, 0X14C8);
    // 0x80804D5C: sw          $t8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r24;
L_80804D60:
    // 0x80804D60: jal         0x800DC128
    // 0x80804D64: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800DC128(rdram, ctx);
        goto after_179;
    // 0x80804D64: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_179:
    // 0x80804D68: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80804D6C: addu        $t0, $sp, $t9
    ctx->r8 = ADD32(ctx->r29, ctx->r25);
    // 0x80804D70: lw          $t1, 0x50($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X50);
    // 0x80804D74: lhu         $t3, 0x6E($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X6E);
    // 0x80804D78: andi        $t2, $t1, 0x1FF
    ctx->r10 = ctx->r9 & 0X1FF;
    // 0x80804D7C: andi        $t4, $t3, 0xFE00
    ctx->r12 = ctx->r11 & 0XFE00;
    // 0x80804D80: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x80804D84: sh          $t5, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r13;
L_80804D88:
    // 0x80804D88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80804D8C:
    // 0x80804D8C: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x80804D90: jal         0x80803B54
    // 0x80804D94: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    func_80803B54_chquiz(rdram, ctx);
        goto after_180;
    // 0x80804D94: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    after_180:
    // 0x80804D98: b           L_808053A4
    // 0x80804D9C: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x80804D9C: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80804DA0:
    // 0x80804DA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804DA4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80804DA8: jal         0x8080100C
    // 0x80804DAC: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    func_8080100C_chquiz(rdram, ctx);
        goto after_181;
    // 0x80804DAC: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    after_181:
    // 0x80804DB0: b           L_808053A4
    // 0x80804DB4: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x80804DB4: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80804DB8:
    // 0x80804DB8: lw          $a2, 0x6C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X6C);
    // 0x80804DBC: addiu       $a0, $zero, 0x529
    ctx->r4 = ADD32(0, 0X529);
    // 0x80804DC0: addiu       $a1, $zero, 0x87
    ctx->r5 = ADD32(0, 0X87);
    // 0x80804DC4: andi        $t7, $a2, 0x1FF
    ctx->r15 = ctx->r6 & 0X1FF;
    // 0x80804DC8: jal         0x80101180
    // 0x80804DCC: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    func_80101180(rdram, ctx);
        goto after_182;
    // 0x80804DCC: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    after_182:
    // 0x80804DD0: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x80804DD4: andi        $t6, $a0, 0x1FF
    ctx->r14 = ctx->r4 & 0X1FF;
    // 0x80804DD8: jal         0x8008A858
    // 0x80804DDC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    _suquiz_entrypoint_20(rdram, ctx);
        goto after_183;
    // 0x80804DDC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_183:
    // 0x80804DE0: b           L_808053A4
    // 0x80804DE4: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x80804DE4: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80804DE8:
    // 0x80804DE8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80804DEC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80804DF0: b           L_808053A0
    // 0x80804DF4: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
        goto L_808053A0;
    // 0x80804DF4: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
L_80804DF8:
    // 0x80804DF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804DFC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80804E00: jal         0x8080100C
    // 0x80804E04: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    func_8080100C_chquiz(rdram, ctx);
        goto after_184;
    // 0x80804E04: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_184:
    // 0x80804E08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804E0C: jal         0x80102424
    // 0x80804E10: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_185;
    // 0x80804E10: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_185:
    // 0x80804E14: b           L_808053A4
    // 0x80804E18: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x80804E18: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80804E1C:
    // 0x80804E1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804E20: jal         0x80102424
    // 0x80804E24: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_186;
    // 0x80804E24: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_186:
    // 0x80804E28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804E2C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80804E30: jal         0x8080100C
    // 0x80804E34: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    func_8080100C_chquiz(rdram, ctx);
        goto after_187;
    // 0x80804E34: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    after_187:
    // 0x80804E38: b           L_808053A4
    // 0x80804E3C: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x80804E3C: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80804E40:
    // 0x80804E40: jal         0x8008A848
    // 0x80804E44: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    _suquiz_entrypoint_18(rdram, ctx);
        goto after_188;
    // 0x80804E44: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_188:
    // 0x80804E48: jal         0x8008A7C8
    // 0x80804E4C: nop

    _suquiz_entrypoint_2(rdram, ctx);
        goto after_189;
    // 0x80804E4C: nop

    after_189:
    // 0x80804E50: addiu       $a0, $zero, 0x4CD
    ctx->r4 = ADD32(0, 0X4CD);
    // 0x80804E54: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80804E58: jal         0x80101180
    // 0x80804E5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_190;
    // 0x80804E5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_190:
    // 0x80804E60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804E64: jal         0x80100094
    // 0x80804E68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_191;
    // 0x80804E68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_191:
    // 0x80804E6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804E70: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80804E74: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x80804E78: jal         0x80801408
    // 0x80804E7C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    func_80801408_chquiz(rdram, ctx);
        goto after_192;
    // 0x80804E7C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_192:
    // 0x80804E80: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x80804E84: andi        $t9, $t8, 0xFFFE
    ctx->r25 = ctx->r24 & 0XFFFE;
    // 0x80804E88: b           L_808053A0
    // 0x80804E8C: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
        goto L_808053A0;
    // 0x80804E8C: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
L_80804E90:
    // 0x80804E90: addiu       $a0, $zero, 0x529
    ctx->r4 = ADD32(0, 0X529);
    // 0x80804E94: addiu       $a1, $zero, 0x8A
    ctx->r5 = ADD32(0, 0X8A);
    // 0x80804E98: jal         0x80101180
    // 0x80804E9C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80101180(rdram, ctx);
        goto after_193;
    // 0x80804E9C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_193:
    // 0x80804EA0: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    // 0x80804EA4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80804EA8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80804EAC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80804EB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804EB4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80804EB8: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    // 0x80804EBC: jal         0x80801058
    // 0x80804EC0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80801058_chquiz(rdram, ctx);
        goto after_194;
    // 0x80804EC0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_194:
    // 0x80804EC4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80804EC8: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x80804ECC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80804ED0: addiu       $a1, $zero, 0x14A0
    ctx->r5 = ADD32(0, 0X14A0);
    // 0x80804ED4: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x80804ED8: jal         0x8008A208
    // 0x80804EDC: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_195;
    // 0x80804EDC: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_195:
    // 0x80804EE0: b           L_808053A4
    // 0x80804EE4: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x80804EE4: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80804EE8:
    // 0x80804EE8: jal         0x8008F8B0
    // 0x80804EEC: nop

    func_8008F8B0(rdram, ctx);
        goto after_196;
    // 0x80804EEC: nop

    after_196:
    // 0x80804EF0: jal         0x8008F8D8
    // 0x80804EF4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8008F8D8(rdram, ctx);
        goto after_197;
    // 0x80804EF4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_197:
    // 0x80804EF8: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2484, 0X7678) << 16);
    // 0x80804EFC: addiu       $a0, $a0, 0x7678
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2484, 0X7678));
    // 0x80804F00: jal         0x8008F990
    // 0x80804F04: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    func_8008F990(rdram, ctx);
        goto after_198;
    // 0x80804F04: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    after_198:
    // 0x80804F08: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80804F0C: addiu       $a0, $a0, -0x2A24
    ctx->r4 = ADD32(ctx->r4, -0X2A24);
    // 0x80804F10: jal         0x8008F904
    // 0x80804F14: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_8008F904(rdram, ctx);
        goto after_199;
    // 0x80804F14: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_199:
    // 0x80804F18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804F1C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80804F20: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    // 0x80804F24: jal         0x80801408
    // 0x80804F28: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    func_80801408_chquiz(rdram, ctx);
        goto after_200;
    // 0x80804F28: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_200:
    // 0x80804F2C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X68E8) << 16);
    // 0x80804F30: lwc1        $f16, 0x68E8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2484, 0X68E8));
    // 0x80804F34: b           L_808053A0
    // 0x80804F38: swc1        $f16, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f16.u32l;
        goto L_808053A0;
    // 0x80804F38: swc1        $f16, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f16.u32l;
L_80804F3C:
    // 0x80804F3C: jal         0x800886D8
    // 0x80804F40: nop

    _glglobalsettings_entrypoint_3(rdram, ctx);
        goto after_201;
    // 0x80804F40: nop

    after_201:
    // 0x80804F44: beq         $v0, $zero, L_80804F58
    if (ctx->r2 == 0) {
        // 0x80804F48: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80804F58;
    }
    // 0x80804F48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804F4C: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80804F50: b           L_80804F5C
    // 0x80804F54: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
        goto L_80804F5C;
    // 0x80804F54: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
L_80804F58:
    // 0x80804F58: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_80804F5C:
    // 0x80804F5C: addiu       $t4, $zero, 0x7
    ctx->r12 = ADD32(0, 0X7);
    // 0x80804F60: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80804F64: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80804F68: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80804F6C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80804F70: lui         $a2, 0x4020
    ctx->r6 = S32(0X4020 << 16);
    // 0x80804F74: jal         0x80801058
    // 0x80804F78: lb          $a3, 0x33($sp)
    ctx->r7 = MEM_B(ctx->r29, 0X33);
    func_80801058_chquiz(rdram, ctx);
        goto after_202;
    // 0x80804F78: lb          $a3, 0x33($sp)
    ctx->r7 = MEM_B(ctx->r29, 0X33);
    after_202:
    // 0x80804F7C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80804F80: jal         0x808014F8
    // 0x80804F84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808014F8_chquiz(rdram, ctx);
        goto after_203;
    // 0x80804F84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_203:
    // 0x80804F88: b           L_808053A4
    // 0x80804F8C: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x80804F8C: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80804F90:
    // 0x80804F90: addiu       $a0, $zero, 0x19C
    ctx->r4 = ADD32(0, 0X19C);
    // 0x80804F94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80804F98: jal         0x80087A60
    // 0x80804F9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _gcgoto_entrypoint_2(rdram, ctx);
        goto after_204;
    // 0x80804F9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_204:
    // 0x80804FA0: b           L_808053A4
    // 0x80804FA4: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x80804FA4: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80804FA8:
    // 0x80804FA8: jal         0x8008A848
    // 0x80804FAC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _suquiz_entrypoint_18(rdram, ctx);
        goto after_205;
    // 0x80804FAC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_205:
    // 0x80804FB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804FB4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80804FB8: jal         0x8080100C
    // 0x80804FBC: addiu       $a2, $zero, 0x21
    ctx->r6 = ADD32(0, 0X21);
    func_8080100C_chquiz(rdram, ctx);
        goto after_206;
    // 0x80804FBC: addiu       $a2, $zero, 0x21
    ctx->r6 = ADD32(0, 0X21);
    after_206:
    // 0x80804FC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804FC4: addiu       $a1, $zero, 0x14CC
    ctx->r5 = ADD32(0, 0X14CC);
    // 0x80804FC8: jal         0x80803B54
    // 0x80804FCC: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    func_80803B54_chquiz(rdram, ctx);
        goto after_207;
    // 0x80804FCC: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    after_207:
    // 0x80804FD0: b           L_808053A4
    // 0x80804FD4: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x80804FD4: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80804FD8:
    // 0x80804FD8: jal         0x8008A848
    // 0x80804FDC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    _suquiz_entrypoint_18(rdram, ctx);
        goto after_208;
    // 0x80804FDC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_208:
    // 0x80804FE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804FE4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80804FE8: jal         0x8080100C
    // 0x80804FEC: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    func_8080100C_chquiz(rdram, ctx);
        goto after_209;
    // 0x80804FEC: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    after_209:
    // 0x80804FF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804FF4: addiu       $a1, $zero, 0x14CD
    ctx->r5 = ADD32(0, 0X14CD);
    // 0x80804FF8: jal         0x80803B54
    // 0x80804FFC: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    func_80803B54_chquiz(rdram, ctx);
        goto after_210;
    // 0x80804FFC: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    after_210:
    // 0x80805000: b           L_808053A4
    // 0x80805004: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x80805004: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80805008:
    // 0x80805008: jal         0x8008A848
    // 0x8080500C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    _suquiz_entrypoint_18(rdram, ctx);
        goto after_211;
    // 0x8080500C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_211:
    // 0x80805010: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805014: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80805018: jal         0x8080100C
    // 0x8080501C: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    func_8080100C_chquiz(rdram, ctx);
        goto after_212;
    // 0x8080501C: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    after_212:
    // 0x80805020: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805024: addiu       $a1, $zero, 0x14CE
    ctx->r5 = ADD32(0, 0X14CE);
    // 0x80805028: jal         0x80803B54
    // 0x8080502C: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    func_80803B54_chquiz(rdram, ctx);
        goto after_213;
    // 0x8080502C: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    after_213:
    // 0x80805030: b           L_808053A4
    // 0x80805034: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x80805034: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80805038:
    // 0x80805038: jal         0x80801724
    // 0x8080503C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80801724_chquiz(rdram, ctx);
        goto after_214;
    // 0x8080503C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_214:
    // 0x80805040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805044: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80805048: jal         0x8080100C
    // 0x8080504C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_8080100C_chquiz(rdram, ctx);
        goto after_215;
    // 0x8080504C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_215:
    // 0x80805050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805054: addiu       $a1, $zero, 0x14D3
    ctx->r5 = ADD32(0, 0X14D3);
    // 0x80805058: jal         0x80803B54
    // 0x8080505C: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    func_80803B54_chquiz(rdram, ctx);
        goto after_216;
    // 0x8080505C: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    after_216:
    // 0x80805060: b           L_808053A4
    // 0x80805064: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x80805064: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80805068:
    // 0x80805068: jal         0x80801724
    // 0x8080506C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80801724_chquiz(rdram, ctx);
        goto after_217;
    // 0x8080506C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_217:
    // 0x80805070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805074: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80805078: jal         0x8080100C
    // 0x8080507C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_8080100C_chquiz(rdram, ctx);
        goto after_218;
    // 0x8080507C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_218:
    // 0x80805080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805084: addiu       $a1, $zero, 0x14D4
    ctx->r5 = ADD32(0, 0X14D4);
    // 0x80805088: jal         0x80803B54
    // 0x8080508C: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    func_80803B54_chquiz(rdram, ctx);
        goto after_219;
    // 0x8080508C: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    after_219:
    // 0x80805090: b           L_808053A4
    // 0x80805094: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x80805094: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80805098:
    // 0x80805098: jal         0x80801724
    // 0x8080509C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80801724_chquiz(rdram, ctx);
        goto after_220;
    // 0x8080509C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_220:
    // 0x808050A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808050A4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808050A8: jal         0x8080100C
    // 0x808050AC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_8080100C_chquiz(rdram, ctx);
        goto after_221;
    // 0x808050AC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_221:
    // 0x808050B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808050B4: addiu       $a1, $zero, 0x14D5
    ctx->r5 = ADD32(0, 0X14D5);
    // 0x808050B8: jal         0x80803B54
    // 0x808050BC: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    func_80803B54_chquiz(rdram, ctx);
        goto after_222;
    // 0x808050BC: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    after_222:
    // 0x808050C0: b           L_808053A4
    // 0x808050C4: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x808050C4: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_808050C8:
    // 0x808050C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808050CC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808050D0: jal         0x8080100C
    // 0x808050D4: addiu       $a2, $zero, 0x24
    ctx->r6 = ADD32(0, 0X24);
    func_8080100C_chquiz(rdram, ctx);
        goto after_223;
    // 0x808050D4: addiu       $a2, $zero, 0x24
    ctx->r6 = ADD32(0, 0X24);
    after_223:
    // 0x808050D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808050DC: addiu       $a1, $zero, 0x14CF
    ctx->r5 = ADD32(0, 0X14CF);
    // 0x808050E0: jal         0x80803B54
    // 0x808050E4: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    func_80803B54_chquiz(rdram, ctx);
        goto after_224;
    // 0x808050E4: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    after_224:
    // 0x808050E8: b           L_808053A4
    // 0x808050EC: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x808050EC: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_808050F0:
    // 0x808050F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808050F4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808050F8: jal         0x8080100C
    // 0x808050FC: addiu       $a2, $zero, 0x25
    ctx->r6 = ADD32(0, 0X25);
    func_8080100C_chquiz(rdram, ctx);
        goto after_225;
    // 0x808050FC: addiu       $a2, $zero, 0x25
    ctx->r6 = ADD32(0, 0X25);
    after_225:
    // 0x80805100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805104: addiu       $a1, $zero, 0x14D0
    ctx->r5 = ADD32(0, 0X14D0);
    // 0x80805108: jal         0x80803B54
    // 0x8080510C: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    func_80803B54_chquiz(rdram, ctx);
        goto after_226;
    // 0x8080510C: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    after_226:
    // 0x80805110: b           L_808053A4
    // 0x80805114: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x80805114: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80805118:
    // 0x80805118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080511C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80805120: jal         0x8080100C
    // 0x80805124: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    func_8080100C_chquiz(rdram, ctx);
        goto after_227;
    // 0x80805124: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    after_227:
    // 0x80805128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080512C: addiu       $a1, $zero, 0x1469
    ctx->r5 = ADD32(0, 0X1469);
    // 0x80805130: jal         0x80803B54
    // 0x80805134: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    func_80803B54_chquiz(rdram, ctx);
        goto after_228;
    // 0x80805134: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    after_228:
    // 0x80805138: b           L_808053A4
    // 0x8080513C: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x8080513C: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80805140:
    // 0x80805140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805144: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80805148: jal         0x8080100C
    // 0x8080514C: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    func_8080100C_chquiz(rdram, ctx);
        goto after_229;
    // 0x8080514C: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    after_229:
    // 0x80805150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805154: addiu       $a1, $zero, 0x14D6
    ctx->r5 = ADD32(0, 0X14D6);
    // 0x80805158: jal         0x80803B54
    // 0x8080515C: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    func_80803B54_chquiz(rdram, ctx);
        goto after_230;
    // 0x8080515C: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    after_230:
    // 0x80805160: b           L_808053A4
    // 0x80805164: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x80805164: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80805168:
    // 0x80805168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080516C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80805170: jal         0x8080100C
    // 0x80805174: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    func_8080100C_chquiz(rdram, ctx);
        goto after_231;
    // 0x80805174: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    after_231:
    // 0x80805178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080517C: addiu       $a1, $zero, 0x14C2
    ctx->r5 = ADD32(0, 0X14C2);
    // 0x80805180: jal         0x80803B54
    // 0x80805184: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    func_80803B54_chquiz(rdram, ctx);
        goto after_232;
    // 0x80805184: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    after_232:
    // 0x80805188: b           L_808053A4
    // 0x8080518C: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x8080518C: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80805190:
    // 0x80805190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805194: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80805198: jal         0x8080100C
    // 0x8080519C: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    func_8080100C_chquiz(rdram, ctx);
        goto after_233;
    // 0x8080519C: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    after_233:
    // 0x808051A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808051A4: addiu       $a1, $zero, 0x14C3
    ctx->r5 = ADD32(0, 0X14C3);
    // 0x808051A8: jal         0x80803B54
    // 0x808051AC: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    func_80803B54_chquiz(rdram, ctx);
        goto after_234;
    // 0x808051AC: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    after_234:
    // 0x808051B0: b           L_808053A4
    // 0x808051B4: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x808051B4: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_808051B8:
    // 0x808051B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808051BC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808051C0: jal         0x8080100C
    // 0x808051C4: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    func_8080100C_chquiz(rdram, ctx);
        goto after_235;
    // 0x808051C4: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    after_235:
    // 0x808051C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808051CC: addiu       $a1, $zero, 0x14C4
    ctx->r5 = ADD32(0, 0X14C4);
    // 0x808051D0: jal         0x80803B54
    // 0x808051D4: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    func_80803B54_chquiz(rdram, ctx);
        goto after_236;
    // 0x808051D4: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    after_236:
    // 0x808051D8: b           L_808053A4
    // 0x808051DC: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x808051DC: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_808051E0:
    // 0x808051E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808051E4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808051E8: jal         0x8080100C
    // 0x808051EC: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    func_8080100C_chquiz(rdram, ctx);
        goto after_237;
    // 0x808051EC: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    after_237:
    // 0x808051F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808051F4: addiu       $a1, $zero, 0x14C5
    ctx->r5 = ADD32(0, 0X14C5);
    // 0x808051F8: jal         0x80803B54
    // 0x808051FC: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    func_80803B54_chquiz(rdram, ctx);
        goto after_238;
    // 0x808051FC: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    after_238:
    // 0x80805200: b           L_808053A4
    // 0x80805204: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x80805204: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80805208:
    // 0x80805208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080520C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80805210: jal         0x8080100C
    // 0x80805214: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    func_8080100C_chquiz(rdram, ctx);
        goto after_239;
    // 0x80805214: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    after_239:
    // 0x80805218: jal         0x80088398
    // 0x8080521C: nop

    _gcstatusDll_entrypoint_17(rdram, ctx);
        goto after_240;
    // 0x8080521C: nop

    after_240:
    // 0x80805220: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80805224: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80805228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080522C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80805230: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    // 0x80805234: addiu       $t6, $zero, 0x14D9
    ctx->r14 = ADD32(0, 0X14D9);
    // 0x80805238: addiu       $t7, $zero, 0x14C6
    ctx->r15 = ADD32(0, 0X14C6);
    // 0x8080523C: c.eq.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl == ctx->f6.fl;
    // 0x80805240: nop

    // 0x80805244: bc1fl       L_80805258
    if (!c1cs) {
        // 0x80805248: sw          $t6, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r14;
            goto L_80805258;
    }
    goto skip_0;
    // 0x80805248: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    skip_0:
    // 0x8080524C: b           L_80805258
    // 0x80805250: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
        goto L_80805258;
    // 0x80805250: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x80805254: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
L_80805258:
    // 0x80805258: jal         0x80803B54
    // 0x8080525C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80803B54_chquiz(rdram, ctx);
        goto after_241;
    // 0x8080525C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_241:
    // 0x80805260: b           L_808053A4
    // 0x80805264: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x80805264: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80805268:
    // 0x80805268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080526C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80805270: jal         0x8080100C
    // 0x80805274: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    func_8080100C_chquiz(rdram, ctx);
        goto after_242;
    // 0x80805274: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    after_242:
    // 0x80805278: jal         0x80088398
    // 0x8080527C: nop

    _gcstatusDll_entrypoint_17(rdram, ctx);
        goto after_243;
    // 0x8080527C: nop

    after_243:
    // 0x80805280: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80805284: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80805288: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080528C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80805290: c.eq.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl == ctx->f16.fl;
    // 0x80805294: nop

    // 0x80805298: bc1t        L_8080530C
    if (c1cs) {
        // 0x8080529C: nop
    
            goto L_8080530C;
    }
    // 0x8080529C: nop

    // 0x808052A0: jal         0x80801A54
    // 0x808052A4: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_80801A54_chquiz(rdram, ctx);
        goto after_244;
    // 0x808052A4: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_244:
    // 0x808052A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808052AC: bne         $v0, $at, L_808052D4
    if (ctx->r2 != ctx->r1) {
        // 0x808052B0: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_808052D4;
    }
    // 0x808052B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808052B4: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x808052B8: lhu         $t1, 0x6E($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X6E);
    // 0x808052BC: addiu       $a3, $zero, 0x1493
    ctx->r7 = ADD32(0, 0X1493);
    // 0x808052C0: andi        $t0, $t9, 0x1FF
    ctx->r8 = ctx->r25 & 0X1FF;
    // 0x808052C4: andi        $t3, $t1, 0xFE00
    ctx->r11 = ctx->r9 & 0XFE00;
    // 0x808052C8: or          $t2, $t0, $t3
    ctx->r10 = ctx->r8 | ctx->r11;
    // 0x808052CC: b           L_80805338
    // 0x808052D0: sh          $t2, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r10;
        goto L_80805338;
    // 0x808052D0: sh          $t2, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r10;
L_808052D4:
    // 0x808052D4: addiu       $a3, $zero, 0x1495
    ctx->r7 = ADD32(0, 0X1495);
    // 0x808052D8: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    // 0x808052DC: jal         0x800DC128
    // 0x808052E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DC128(rdram, ctx);
        goto after_245;
    // 0x808052E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_245:
    // 0x808052E4: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x808052E8: addu        $t5, $sp, $t4
    ctx->r13 = ADD32(ctx->r29, ctx->r12);
    // 0x808052EC: lw          $t7, 0x38($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X38);
    // 0x808052F0: lhu         $t8, 0x6E($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X6E);
    // 0x808052F4: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x808052F8: andi        $t6, $t7, 0x1FF
    ctx->r14 = ctx->r15 & 0X1FF;
    // 0x808052FC: andi        $t9, $t8, 0xFE00
    ctx->r25 = ctx->r24 & 0XFE00;
    // 0x80805300: or          $t1, $t6, $t9
    ctx->r9 = ctx->r14 | ctx->r25;
    // 0x80805304: b           L_80805338
    // 0x80805308: sh          $t1, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r9;
        goto L_80805338;
    // 0x80805308: sh          $t1, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r9;
L_8080530C:
    // 0x8080530C: jal         0x800883A0
    // 0x80805310: nop

    _gcstatusDll_entrypoint_18(rdram, ctx);
        goto after_246;
    // 0x80805310: nop

    after_246:
    // 0x80805314: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805318: jal         0x80801C08
    // 0x8080531C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80801C08_chquiz(rdram, ctx);
        goto after_247;
    // 0x8080531C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_247:
    // 0x80805320: lhu         $t2, 0x6E($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X6E);
    // 0x80805324: andi        $t3, $v0, 0x1FF
    ctx->r11 = ctx->r2 & 0X1FF;
    // 0x80805328: addiu       $a3, $zero, 0x1494
    ctx->r7 = ADD32(0, 0X1494);
    // 0x8080532C: andi        $t4, $t2, 0xFE00
    ctx->r12 = ctx->r10 & 0XFE00;
    // 0x80805330: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x80805334: sh          $t5, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r13;
L_80805338:
    // 0x80805338: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x8080533C: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    // 0x80805340: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80805344: andi        $t7, $a1, 0x1FF
    ctx->r15 = ctx->r5 & 0X1FF;
    // 0x80805348: jal         0x80801758
    // 0x8080534C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    func_80801758_chquiz(rdram, ctx);
        goto after_248;
    // 0x8080534C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_248:
    // 0x80805350: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80805354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805358: jal         0x80803B54
    // 0x8080535C: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    func_80803B54_chquiz(rdram, ctx);
        goto after_249;
    // 0x8080535C: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    after_249:
    // 0x80805360: jal         0x800FC660
    // 0x80805364: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_800FC660(rdram, ctx);
        goto after_250;
    // 0x80805364: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_250:
    // 0x80805368: b           L_808053A4
    // 0x8080536C: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x8080536C: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80805370:
    // 0x80805370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805374: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80805378: jal         0x8080100C
    // 0x8080537C: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    func_8080100C_chquiz(rdram, ctx);
        goto after_251;
    // 0x8080537C: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    after_251:
    // 0x80805380: b           L_808053A4
    // 0x80805384: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
        goto L_808053A4;
    // 0x80805384: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_80805388:
    // 0x80805388: lw          $a2, 0x6C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X6C);
    // 0x8080538C: addiu       $a0, $zero, 0x529
    ctx->r4 = ADD32(0, 0X529);
    // 0x80805390: addiu       $a1, $zero, 0x87
    ctx->r5 = ADD32(0, 0X87);
    // 0x80805394: andi        $t8, $a2, 0x1FF
    ctx->r24 = ctx->r6 & 0X1FF;
    // 0x80805398: jal         0x80101180
    // 0x8080539C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    func_80101180(rdram, ctx);
        goto after_252;
    // 0x8080539C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    after_252:
L_808053A0:
    // 0x808053A0: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_808053A4:
    // 0x808053A4: sw          $t6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r14;
L_808053A8:
    // 0x808053A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808053AC:
    // 0x808053AC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808053B0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808053B4: jr          $ra
    // 0x808053B8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x808053B8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_80800434_chflamer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800434: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80800438: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8080043C: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x80800440: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80800444: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80800448: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8080044C: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80800450: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80800454: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80800458: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8080045C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80800460: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80800464: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800468: jal         0x80100094
    // 0x8080046C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080046C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800470: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80800474: jal         0x800D674C
    // 0x80800478: addiu       $a0, $zero, 0x9CE
    ctx->r4 = ADD32(0, 0X9CE);
    func_800D674C(rdram, ctx);
        goto after_1;
    // 0x80800478: addiu       $a0, $zero, 0x9CE
    ctx->r4 = ADD32(0, 0X9CE);
    after_1:
    // 0x8080047C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800480: jal         0x800E2588
    // 0x80800484: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800E2588(rdram, ctx);
        goto after_2;
    // 0x80800484: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80800488: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8080048C: jal         0x800E2594
    // 0x80800490: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800E2594(rdram, ctx);
        goto after_3;
    // 0x80800490: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x80800494: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800498: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080049C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1088, 0XB10) << 16);
    // 0x808004A0: lwc1        $f4, 0xB10($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1088, 0XB10));
    // 0x808004A4: lwc1        $f12, 0x1B0($s5)
    ctx->f12.u32l = MEM_W(ctx->r21, 0X1B0);
    // 0x808004A8: lui         $a3, 0x3F19
    ctx->r7 = S32(0X3F19 << 16);
    // 0x808004AC: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x808004B0: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    // 0x808004B4: jal         0x800F10B4
    // 0x808004B8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x808004B8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x808004BC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808004C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808004C4: lh          $t6, 0x16($s5)
    ctx->r14 = MEM_H(ctx->r21, 0X16);
    // 0x808004C8: addiu       $s0, $s5, 0x1C
    ctx->r16 = ADD32(ctx->r21, 0X1C);
    // 0x808004CC: mul.s       $f22, $f0, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808004D0: blez        $t6, L_8080055C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x808004D4: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8080055C;
    }
    // 0x808004D4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x808004D8: addiu       $s4, $s1, 0x4
    ctx->r20 = ADD32(ctx->r17, 0X4);
    // 0x808004DC: addiu       $s1, $sp, 0x68
    ctx->r17 = ADD32(ctx->r29, 0X68);
    // 0x808004E0: addiu       $s3, $sp, 0x5C
    ctx->r19 = ADD32(ctx->r29, 0X5C);
    // 0x808004E4: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
L_808004E8:
    // 0x808004E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808004EC: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    // 0x808004F0: mul.s       $f20, $f8, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x808004F4: jal         0x800EE88C
    // 0x808004F8: nop

    func_800EE88C(rdram, ctx);
        goto after_5;
    // 0x808004F8: nop

    after_5:
    // 0x808004FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800500: jal         0x800EF04C
    // 0x80800504: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800EF04C(rdram, ctx);
        goto after_6;
    // 0x80800504: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_6:
    // 0x80800508: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8080050C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80800510: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800514: jal         0x800EFA4C
    // 0x80800518: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800EFA4C(rdram, ctx);
        goto after_7;
    // 0x80800518: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_7:
    // 0x8080051C: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800520: lh          $a2, 0x6($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X6);
    // 0x80800524: addiu       $t8, $zero, 0xC0
    ctx->r24 = ADD32(0, 0XC0);
    // 0x80800528: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8080052C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80800530: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80800534: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80800538: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8080053C: jal         0x800E2720
    // 0x80800540: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_800E2720(rdram, ctx);
        goto after_8;
    // 0x80800540: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_8:
    // 0x80800544: lh          $t9, 0x16($s5)
    ctx->r25 = MEM_H(ctx->r21, 0X16);
    // 0x80800548: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8080054C: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x80800550: slt         $at, $s2, $t9
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80800554: bnel        $at, $zero, L_808004E8
    if (ctx->r1 != 0) {
        // 0x80800558: lwc1        $f8, 0x10($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
            goto L_808004E8;
    }
    goto skip_0;
    // 0x80800558: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    skip_0:
L_8080055C:
    // 0x8080055C: jal         0x800E2A14
    // 0x80800560: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_800E2A14(rdram, ctx);
        goto after_9;
    // 0x80800560: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_9:
    // 0x80800564: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80800568: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8080056C: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80800570: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80800574: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80800578: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8080057C: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80800580: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80800584: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80800588: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8080058C: jr          $ra
    // 0x80800590: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80800590: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_800DD19C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DD19C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DD1A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DD1A4: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x800DD1A8: jal         0x800DE2A4
    // 0x800DD1AC: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    func_800DE2A4(rdram, ctx);
        goto after_0;
    // 0x800DD1AC: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    after_0:
    // 0x800DD1B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DD1B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DD1B8: jr          $ra
    // 0x800DD1BC: nop

    return;
    // 0x800DD1BC: nop

;}
RECOMP_FUNC void func_808002B4_chstarspinnerctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808002C0: jal         0x800BEA88
    // 0x808002C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BEA88(rdram, ctx);
        goto after_0;
    // 0x808002C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x808002C8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808002CC: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x808002D0: addiu       $a2, $a2, 0x5E10
    ctx->r6 = ADD32(ctx->r6, 0X5E10);
    // 0x808002D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808002DC: jal         0x80088660
    // 0x808002E0: lw          $a3, 0x0($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808002E0: lw          $a3, 0x0($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X0);
    after_1:
    // 0x808002E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002EC: jr          $ra
    // 0x808002F0: nop

    return;
    // 0x808002F0: nop

;}
RECOMP_FUNC void func_808003BC_chmrsicecube(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808003C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808003C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003CC: jal         0x80103FB8
    // 0x808003D0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80103FB8(rdram, ctx);
        goto after_0;
    // 0x808003D0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x808003D4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808003D8: jal         0x800E3E8C
    // 0x808003DC: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    func_800E3E8C(rdram, ctx);
        goto after_1;
    // 0x808003DC: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x808003E0: beq         $v0, $zero, L_80800428
    if (ctx->r2 == 0) {
        // 0x808003E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800428;
    }
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003E8: jal         0x80100094
    // 0x808003EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x808003EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808003F0: jal         0x8008A040
    // 0x808003F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x808003F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x808003F8: beq         $v0, $zero, L_80800408
    if (ctx->r2 == 0) {
        // 0x808003FC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800408;
    }
    // 0x808003FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800400: jal         0x8010A764
    // 0x80800404: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8010A764(rdram, ctx);
        goto after_4;
    // 0x80800404: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_4:
L_80800408:
    // 0x80800408: lw          $a1, 0x64($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X64);
    // 0x8080040C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800410: sll         $t6, $a1, 12
    ctx->r14 = S32(ctx->r5 << 12);
    // 0x80800414: jal         0x800DF744
    // 0x80800418: srl         $a1, $t6, 31
    ctx->r5 = S32(U32(ctx->r14) >> 31);
    func_800DF744(rdram, ctx);
        goto after_5;
    // 0x80800418: srl         $a1, $t6, 31
    ctx->r5 = S32(U32(ctx->r14) >> 31);
    after_5:
    // 0x8080041C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800420: jal         0x80101870
    // 0x80800424: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80101870(rdram, ctx);
        goto after_6;
    // 0x80800424: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_6:
L_80800428:
    // 0x80800428: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080042C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800430: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800434: jr          $ra
    // 0x80800438: nop

    return;
    // 0x80800438: nop

;}
RECOMP_FUNC void func_808008B0_charmouredcaveman(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808008B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008B8: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x808008BC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1116, 0XC08) << 16);
    // 0x808008C0: lui         $a3, 0x3E99
    ctx->r7 = S32(0X3E99 << 16);
    // 0x808008C4: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x808008C8: addiu       $a2, $a2, 0xC08
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1116, 0XC08));
    // 0x808008CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808008D0: jal         0x80089D20
    // 0x808008D4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808008D4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808008D8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1116, 0XC14) << 16);
    // 0x808008DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808008E0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808008E4: addiu       $a2, $a2, 0xC14
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1116, 0XC14));
    // 0x808008E8: jal         0x80089D20
    // 0x808008EC: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808008EC: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    after_1:
    // 0x808008F0: beq         $v0, $zero, L_8080091C
    if (ctx->r2 == 0) {
        // 0x808008F4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8080091C;
    }
    // 0x808008F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808008F8: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x808008FC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800900: jal         0x80018820
    // 0x80800904: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80018820(rdram, ctx);
        goto after_2;
    // 0x80800904: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_2:
    // 0x80800908: lui         $a2, 0x3F59
    ctx->r6 = S32(0X3F59 << 16);
    // 0x8080090C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800910: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800914: jal         0x800E15CC
    // 0x80800918: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    func_800E15CC(rdram, ctx);
        goto after_3;
    // 0x80800918: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    after_3:
L_8080091C:
    // 0x8080091C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800920: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800924: jr          $ra
    // 0x80800928: nop

    return;
    // 0x80800928: nop

;}
RECOMP_FUNC void _gcmapsects_lagoonbot_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088008: syscall     665
    recomp_syscall_handler(rdram, ctx, 0x80088008);
    return;
    // 0x8008800C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808002A8_chdinofoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002AC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x808002B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002B4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808002B8: beq         $a1, $at, L_808002DC
    if (ctx->r5 == ctx->r1) {
        // 0x808002BC: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_808002DC;
    }
    // 0x808002BC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808002C0: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x808002C4: bne         $a1, $at, L_808002F8
    if (ctx->r5 != ctx->r1) {
        // 0x808002C8: nop
    
            goto L_808002F8;
    }
    // 0x808002C8: nop

    // 0x808002CC: jal         0x8080035C
    // 0x808002D0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_8080035C_chdinofoot(rdram, ctx);
        goto after_0;
    // 0x808002D0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x808002D4: b           L_80800300
    // 0x808002D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800300;
    // 0x808002D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002DC:
    // 0x808002DC: lbu         $t6, 0x65($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X65);
    // 0x808002E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808002E4: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x808002E8: jal         0x800FDC28
    // 0x808002EC: sb          $t7, 0x65($a3)
    MEM_B(0X65, ctx->r7) = ctx->r15;
    func_800FDC28(rdram, ctx);
        goto after_1;
    // 0x808002EC: sb          $t7, 0x65($a3)
    MEM_B(0X65, ctx->r7) = ctx->r15;
    after_1:
    // 0x808002F0: b           L_80800300
    // 0x808002F4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800300;
    // 0x808002F4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808002F8:
    // 0x808002F8: b           L_80800300
    // 0x808002FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800300;
    // 0x808002FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800300:
    // 0x80800300: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800304: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800308: jr          $ra
    // 0x8080030C: nop

    return;
    // 0x8080030C: nop

;}
RECOMP_FUNC void _baairbar_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085558: syscall     166
    recomp_syscall_handler(rdram, ctx, 0x80085558);
    return;
    // 0x8008555C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void subaddiejoy_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001DC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808001E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001E4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x808001E8: lw          $a0, 0x64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X64);
    // 0x808001EC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x808001F0: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x808001F4: jal         0x80015F28
    // 0x808001F8: srl         $a0, $t7, 30
    ctx->r4 = S32(U32(ctx->r15) >> 30);
    func_80015F28(rdram, ctx);
        goto after_0;
    // 0x808001F8: srl         $a0, $t7, 30
    ctx->r4 = S32(U32(ctx->r15) >> 30);
    after_0:
    // 0x808001FC: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80800200: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80800204: beql        $t9, $zero, L_80800218
    if (ctx->r25 == 0) {
        // 0x80800208: lw          $a0, 0x64($t0)
        ctx->r4 = MEM_W(ctx->r8, 0X64);
            goto L_80800218;
    }
    goto skip_0;
    // 0x80800208: lw          $a0, 0x64($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X64);
    skip_0:
    // 0x8080020C: b           L_80800248
    // 0x80800210: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800248;
    // 0x80800210: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800214: lw          $a0, 0x64($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X64);
L_80800218:
    // 0x80800218: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8080021C: sll         $t1, $a0, 3
    ctx->r9 = S32(ctx->r4 << 3);
    // 0x80800220: jal         0x80015E80
    // 0x80800224: srl         $a0, $t1, 30
    ctx->r4 = S32(U32(ctx->r9) >> 30);
    func_80015E80(rdram, ctx);
        goto after_1;
    // 0x80800224: srl         $a0, $t1, 30
    ctx->r4 = S32(U32(ctx->r9) >> 30);
    after_1:
    // 0x80800228: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8080022C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80800230: bne         $t3, $zero, L_80800240
    if (ctx->r11 != 0) {
        // 0x80800234: nop
    
            goto L_80800240;
    }
    // 0x80800234: nop

    // 0x80800238: beq         $t4, $zero, L_80800248
    if (ctx->r12 == 0) {
        // 0x8080023C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800248;
    }
    // 0x8080023C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800240:
    // 0x80800240: b           L_80800248
    // 0x80800244: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800248;
    // 0x80800244: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800248:
    // 0x80800248: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080024C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800250: jr          $ra
    // 0x80800254: nop

    return;
    // 0x80800254: nop

;}
RECOMP_FUNC void chbeanstalkseed_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B68: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2356, 0XC54) << 16);
    // 0x80800B6C: jr          $ra
    // 0x80800B70: addiu       $v0, $v0, 0xC54
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2356, 0XC54));
    return;
    // 0x80800B70: addiu       $v0, $v0, 0xC54
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2356, 0XC54));
    // 0x80800B74: nop

    // 0x80800B78: nop

    // 0x80800B7C: nop

;}
RECOMP_FUNC void func_8010C908(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010C908: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010C90C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010C910: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8010C914: jal         0x8010A40C
    // 0x8010C918: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8010A40C(rdram, ctx);
        goto after_0;
    // 0x8010C918: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8010C91C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8010C920: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8010C924: jal         0x8010C878
    // 0x8010C928: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8010C878(rdram, ctx);
        goto after_1;
    // 0x8010C928: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8010C92C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010C930: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010C934: jr          $ra
    // 0x8010C938: nop

    return;
    // 0x8010C938: nop

;}
RECOMP_FUNC void func_8009C000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009C004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009C008: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x8009C00C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8009C010: jal         0x8009BFE4
    // 0x8009C014: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    func_8009BFE4(rdram, ctx);
        goto after_0;
    // 0x8009C014: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    after_0:
    // 0x8009C018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009C01C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009C020: jr          $ra
    // 0x8009C024: nop

    return;
    // 0x8009C024: nop

    // 0x8009C028: nop

    // 0x8009C02C: nop

;}
RECOMP_FUNC void func_8080413C_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080413C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80804140: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80804144: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80804148: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080414C: lbu         $a0, 0x79($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X79);
    // 0x80804150: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80804154: srl         $t6, $a0, 4
    ctx->r14 = S32(U32(ctx->r4) >> 4);
    // 0x80804158: jal         0x8080218C
    // 0x8080415C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_8080218C_chgameselect(rdram, ctx);
        goto after_0;
    // 0x8080415C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x80804160: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x80804164: jal         0x80801658
    // 0x80804168: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801658_chgameselect(rdram, ctx);
        goto after_1;
    // 0x80804168: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8080416C: lbu         $a0, 0x79($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X79);
    // 0x80804170: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80804174: srl         $t7, $a0, 4
    ctx->r15 = S32(U32(ctx->r4) >> 4);
    // 0x80804178: jal         0x80803D00
    // 0x8080417C: addiu       $a0, $t7, 0x8
    ctx->r4 = ADD32(ctx->r15, 0X8);
    func_80803D00_chgameselect(rdram, ctx);
        goto after_2;
    // 0x8080417C: addiu       $a0, $t7, 0x8
    ctx->r4 = ADD32(ctx->r15, 0X8);
    after_2:
    // 0x80804180: jal         0x80803718
    // 0x80804184: nop

    func_80803718_chgameselect(rdram, ctx);
        goto after_3;
    // 0x80804184: nop

    after_3:
    // 0x80804188: addiu       $a0, $zero, 0xD69
    ctx->r4 = ADD32(0, 0XD69);
    // 0x8080418C: jal         0x800DA3B8
    // 0x80804190: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800DA3B8(rdram, ctx);
        goto after_4;
    // 0x80804190: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80804194: lbu         $a0, 0x79($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X79);
    // 0x80804198: srl         $t8, $a0, 4
    ctx->r24 = S32(U32(ctx->r4) >> 4);
    // 0x8080419C: jal         0x808037C0
    // 0x808041A0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_808037C0_chgameselect(rdram, ctx);
        goto after_5;
    // 0x808041A0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_5:
    // 0x808041A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808041A8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808041AC: jal         0x80803888
    // 0x808041B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80803888_chgameselect(rdram, ctx);
        goto after_6;
    // 0x808041B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x808041B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808041B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808041BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808041C0: jr          $ra
    // 0x808041C4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x808041C4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
;}
RECOMP_FUNC void gcboundDll_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800788: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080078C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800790: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80800794: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80800798: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8080079C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x808007A0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x808007A4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x808007A8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808007AC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808007B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808007B4: lw          $fp, 0x0($a0)
    ctx->r30 = MEM_W(ctx->r4, 0X0);
    // 0x808007B8: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x808007BC: lw          $s5, 0x4($a0)
    ctx->r21 = MEM_W(ctx->r4, 0X4);
    // 0x808007C0: blez        $fp, L_80800888
    if (SIGNED(ctx->r30) <= 0) {
        // 0x808007C4: or          $s7, $zero, $zero
        ctx->r23 = 0 | 0;
            goto L_80800888;
    }
    // 0x808007C4: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
L_808007C8:
    // 0x808007C8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x808007CC: jal         0x80800630
    // 0x808007D0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_80800630_gcboundDll(rdram, ctx);
        goto after_0;
    // 0x808007D0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_0:
    // 0x808007D4: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x808007D8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x808007DC: jal         0x80800654
    // 0x808007E0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_80800654_gcboundDll(rdram, ctx);
        goto after_1;
    // 0x808007E0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_1:
    // 0x808007E4: addiu       $s3, $v0, -0x30
    ctx->r19 = ADD32(ctx->r2, -0X30);
    // 0x808007E8: sltu        $at, $s3, $s4
    ctx->r1 = ctx->r19 < ctx->r20 ? 1 : 0;
    // 0x808007EC: bne         $at, $zero, L_80800870
    if (ctx->r1 != 0) {
        // 0x808007F0: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80800870;
    }
    // 0x808007F0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x808007F4: addiu       $v0, $s3, 0x18
    ctx->r2 = ADD32(ctx->r19, 0X18);
L_808007F8:
    // 0x808007F8: sltu        $at, $s3, $s2
    ctx->r1 = ctx->r19 < ctx->r18 ? 1 : 0;
    // 0x808007FC: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
    // 0x80800800: beq         $at, $zero, L_80800860
    if (ctx->r1 == 0) {
        // 0x80800804: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80800860;
    }
    // 0x80800804: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800808: lw          $t6, 0x14($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X14);
    // 0x8080080C: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x80800810: bgezl       $t8, L_80800864
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800814: addiu       $s3, $s3, -0x18
        ctx->r19 = ADD32(ctx->r19, -0X18);
            goto L_80800864;
    }
    goto skip_0;
    // 0x80800814: addiu       $s3, $s3, -0x18
    ctx->r19 = ADD32(ctx->r19, -0X18);
    skip_0:
    // 0x80800818: lw          $t9, 0x14($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14);
    // 0x8080081C: sll         $t1, $t9, 11
    ctx->r9 = S32(ctx->r25 << 11);
    // 0x80800820: bltz        $t1, L_80800860
    if (SIGNED(ctx->r9) < 0) {
        // 0x80800824: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800860;
    }
    // 0x80800824: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800828:
    // 0x80800828: jal         0x80800E6C
    // 0x8080082C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80800E6C_gcboundDll(rdram, ctx);
        goto after_2;
    // 0x8080082C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x80800830: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x80800834: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x80800838: beq         $at, $zero, L_80800860
    if (ctx->r1 == 0) {
        // 0x8080083C: addiu       $s1, $s1, 0x18
        ctx->r17 = ADD32(ctx->r17, 0X18);
            goto L_80800860;
    }
    // 0x8080083C: addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
    // 0x80800840: lw          $t2, 0x14($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X14);
    // 0x80800844: sll         $t4, $t2, 11
    ctx->r12 = S32(ctx->r10 << 11);
    // 0x80800848: bgezl       $t4, L_80800864
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8080084C: addiu       $s3, $s3, -0x18
        ctx->r19 = ADD32(ctx->r19, -0X18);
            goto L_80800864;
    }
    goto skip_1;
    // 0x8080084C: addiu       $s3, $s3, -0x18
    ctx->r19 = ADD32(ctx->r19, -0X18);
    skip_1:
    // 0x80800850: lw          $t5, 0x14($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X14);
    // 0x80800854: sll         $t7, $t5, 11
    ctx->r15 = S32(ctx->r13 << 11);
    // 0x80800858: bgezl       $t7, L_80800828
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8080085C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800828;
    }
    goto skip_2;
    // 0x8080085C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
L_80800860:
    // 0x80800860: addiu       $s3, $s3, -0x18
    ctx->r19 = ADD32(ctx->r19, -0X18);
L_80800864:
    // 0x80800864: sltu        $at, $s3, $s4
    ctx->r1 = ctx->r19 < ctx->r20 ? 1 : 0;
    // 0x80800868: beql        $at, $zero, L_808007F8
    if (ctx->r1 == 0) {
        // 0x8080086C: addiu       $v0, $s3, 0x18
        ctx->r2 = ADD32(ctx->r19, 0X18);
            goto L_808007F8;
    }
    goto skip_3;
    // 0x8080086C: addiu       $v0, $s3, 0x18
    ctx->r2 = ADD32(ctx->r19, 0X18);
    skip_3:
L_80800870:
    // 0x80800870: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80800874: jal         0x80800EBC
    // 0x80800878: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_80800EBC_gcboundDll(rdram, ctx);
        goto after_3;
    // 0x80800878: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_3:
    // 0x8080087C: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80800880: bne         $s7, $fp, L_808007C8
    if (ctx->r23 != ctx->r30) {
        // 0x80800884: addiu       $s5, $s5, 0x1C
        ctx->r21 = ADD32(ctx->r21, 0X1C);
            goto L_808007C8;
    }
    // 0x80800884: addiu       $s5, $s5, 0x1C
    ctx->r21 = ADD32(ctx->r21, 0X1C);
L_80800888:
    // 0x80800888: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8080088C: lw          $a1, 0x8($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X8);
    // 0x80800890: jal         0x80800720
    // 0x80800894: lw          $a2, 0xC($s6)
    ctx->r6 = MEM_W(ctx->r22, 0XC);
    func_80800720_gcboundDll(rdram, ctx);
        goto after_4;
    // 0x80800894: lw          $a2, 0xC($s6)
    ctx->r6 = MEM_W(ctx->r22, 0XC);
    after_4:
    // 0x80800898: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8080089C: lw          $a1, 0x10($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X10);
    // 0x808008A0: jal         0x80800720
    // 0x808008A4: lw          $a2, 0x14($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X14);
    func_80800720_gcboundDll(rdram, ctx);
        goto after_5;
    // 0x808008A4: lw          $a2, 0x14($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X14);
    after_5:
    // 0x808008A8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x808008AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808008B0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808008B4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808008B8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x808008BC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x808008C0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x808008C4: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x808008C8: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x808008CC: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x808008D0: jr          $ra
    // 0x808008D4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x808008D4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80801C9C_chaliendad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C9C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801CA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801CA4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801CA8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80801CAC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80801CB0: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x80801CB4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801CB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801CBC: beq         $v0, $zero, L_80801CE0
    if (ctx->r2 == 0) {
        // 0x80801CC0: addiu       $a1, $zero, 0xD
        ctx->r5 = ADD32(0, 0XD);
            goto L_80801CE0;
    }
    // 0x80801CC0: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x80801CC4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801CC8: beq         $v0, $at, L_80801CE8
    if (ctx->r2 == ctx->r1) {
        // 0x80801CCC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80801CE8;
    }
    // 0x80801CCC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801CD0: beql        $v0, $at, L_80801D24
    if (ctx->r2 == ctx->r1) {
        // 0x80801CD4: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_80801D24;
    }
    goto skip_0;
    // 0x80801CD4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80801CD8: b           L_80801D30
    // 0x80801CDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801D30;
    // 0x80801CDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801CE0:
    // 0x80801CE0: jal         0x800856B0
    // 0x80801CE4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80801CE4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_0:
L_80801CE8:
    // 0x80801CE8: jal         0x800856E0
    // 0x80801CEC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _capod_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80801CEC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80801CF0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80801CF4: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1364, 0X25E4) << 16);
    // 0x80801CF8: sw          $t6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r14;
    // 0x80801CFC: addiu       $a0, $a0, 0x25E4
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1364, 0X25E4));
    // 0x80801D00: jal         0x80088090
    // 0x80801D04: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80801D04: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x80801D08: jal         0x80088098
    // 0x80801D0C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    _gcdialogcamera_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80801D0C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x80801D10: jal         0x800880A0
    // 0x80801D14: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    _gcdialogcamera_entrypoint_5(rdram, ctx);
        goto after_4;
    // 0x80801D14: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    after_4:
    // 0x80801D18: jal         0x800880B8
    // 0x80801D1C: nop

    _gcdialogcamera_entrypoint_8(rdram, ctx);
        goto after_5;
    // 0x80801D1C: nop

    after_5:
    // 0x80801D20: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
L_80801D24:
    // 0x80801D24: jal         0x800856D8
    // 0x80801D28: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _capod_entrypoint_7(rdram, ctx);
        goto after_6;
    // 0x80801D28: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_6:
    // 0x80801D2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801D30:
    // 0x80801D30: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801D34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801D38: jr          $ra
    // 0x80801D3C: nop

    return;
    // 0x80801D3C: nop

;}
RECOMP_FUNC void chboggyfatboy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1540, 0X1120) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x1120
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1540, 0X1120));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x1120
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1540, 0X1120));
;}
RECOMP_FUNC void func_800F57C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F57C0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F57C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F57C8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F57CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F57D0: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F57D4: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F57D8: jal         0x8008E9B8
    // 0x800F57DC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    func_8008E9B8(rdram, ctx);
        goto after_0;
    // 0x800F57DC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x800F57E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F57E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F57E8: jr          $ra
    // 0x800F57EC: nop

    return;
    // 0x800F57EC: nop

;}
RECOMP_FUNC void func_808006D8_chjigsawbitcont(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006D8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808006DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808006E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808006E4: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x808006E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808006EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808006F0: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808006F4: beq         $t6, $at, L_8080071C
    if (ctx->r14 == ctx->r1) {
        // 0x808006F8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080071C;
    }
    // 0x808006F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808006FC: beq         $t6, $at, L_80800768
    if (ctx->r14 == ctx->r1) {
        // 0x80800700: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800768;
    }
    // 0x80800700: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800704: beq         $t6, $at, L_8080084C
    if (ctx->r14 == ctx->r1) {
        // 0x80800708: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8080084C;
    }
    // 0x80800708: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080070C: beq         $t6, $at, L_8080084C
    if (ctx->r14 == ctx->r1) {
        // 0x80800710: nop
    
            goto L_8080084C;
    }
    // 0x80800710: nop

    // 0x80800714: b           L_80800858
    // 0x80800718: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800858;
    // 0x80800718: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080071C:
    // 0x8080071C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800720: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800724: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x80800728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080072C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800730: andi        $t8, $t7, 0xFFFE
    ctx->r24 = ctx->r15 & 0XFFFE;
    // 0x80800734: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    // 0x80800738: bc1f        L_80800758
    if (!c1cs) {
        // 0x8080073C: nop
    
            goto L_80800758;
    }
    // 0x8080073C: nop

    // 0x80800740: jal         0x800D8FF8
    // 0x80800744: nop

    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800744: nop

    after_0:
    // 0x80800748: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8080074C: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80800750: b           L_80800854
    // 0x80800754: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
        goto L_80800854;
    // 0x80800754: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
L_80800758:
    // 0x80800758: jal         0x80800570
    // 0x8080075C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800570_chjigsawbitcont(rdram, ctx);
        goto after_1;
    // 0x8080075C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80800760: b           L_80800858
    // 0x80800764: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800858;
    // 0x80800764: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800768:
    // 0x80800768: jal         0x800D8FF8
    // 0x8080076C: nop

    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x8080076C: nop

    after_2:
    // 0x80800770: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80800774: jal         0x80800634
    // 0x80800778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800634_chjigsawbitcont(rdram, ctx);
        goto after_3;
    // 0x80800778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080077C: lbu         $t9, 0x79($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X79);
    // 0x80800780: srl         $t0, $t9, 4
    ctx->r8 = S32(U32(ctx->r25) >> 4);
    // 0x80800784: slti        $at, $t0, 0x3
    ctx->r1 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
    // 0x80800788: bne         $at, $zero, L_808007EC
    if (ctx->r1 != 0) {
        // 0x8080078C: nop
    
            goto L_808007EC;
    }
    // 0x8080078C: nop

    // 0x80800790: jal         0x80089A88
    // 0x80800794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiebounce_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x80800794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800798: beq         $v0, $zero, L_808007C0
    if (ctx->r2 == 0) {
        // 0x8080079C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007C0;
    }
    // 0x8080079C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007A0: lbu         $t1, 0x79($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X79);
    // 0x808007A4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1644, 0X9A0) << 16);
    // 0x808007A8: addiu       $a2, $a2, 0x9A0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1644, 0X9A0));
    // 0x808007AC: andi        $t2, $t1, 0xFF0F
    ctx->r10 = ctx->r9 & 0XFF0F;
    // 0x808007B0: ori         $t3, $t2, 0x20
    ctx->r11 = ctx->r10 | 0X20;
    // 0x808007B4: sb          $t3, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r11;
    // 0x808007B8: jal         0x80089D18
    // 0x808007BC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x808007BC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_5:
L_808007C0:
    // 0x808007C0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x808007C4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808007C8: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808007CC: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808007D0: lwc1        $f8, 0x44($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X44);
    // 0x808007D4: mul.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x808007D8: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x808007DC: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x808007E0: swc1        $f6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f6.u32l;
    // 0x808007E4: b           L_80800854
    // 0x808007E8: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
        goto L_80800854;
    // 0x808007E8: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
L_808007EC:
    // 0x808007EC: jal         0x80089A90
    // 0x808007F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiebounce_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x808007F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808007F4: beql        $v0, $zero, L_80800858
    if (ctx->r2 == 0) {
        // 0x808007F8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800858;
    }
    goto skip_0;
    // 0x808007F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808007FC: lbu         $v0, 0x79($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X79);
    // 0x80800800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800804: srl         $t4, $v0, 4
    ctx->r12 = S32(U32(ctx->r2) >> 4);
    // 0x80800808: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x8080080C: sll         $t7, $t5, 4
    ctx->r15 = S32(ctx->r13 << 4);
    // 0x80800810: andi        $t8, $v0, 0xFF0F
    ctx->r24 = ctx->r2 & 0XFF0F;
    // 0x80800814: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80800818: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x8080081C: srl         $t1, $t0, 4
    ctx->r9 = S32(U32(ctx->r8) >> 4);
    // 0x80800820: bgtz        $t1, L_80800830
    if (SIGNED(ctx->r9) > 0) {
        // 0x80800824: sb          $t9, 0x79($s0)
        MEM_B(0X79, ctx->r16) = ctx->r25;
            goto L_80800830;
    }
    // 0x80800824: sb          $t9, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r25;
    // 0x80800828: jal         0x80800570
    // 0x8080082C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800570_chjigsawbitcont(rdram, ctx);
        goto after_7;
    // 0x8080082C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
L_80800830:
    // 0x80800830: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1644, 0X9A0) << 16);
    // 0x80800834: addiu       $a2, $a2, 0x9A0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1644, 0X9A0));
    // 0x80800838: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080083C: jal         0x80089D18
    // 0x80800840: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x80800840: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_8:
    // 0x80800844: b           L_80800858
    // 0x80800848: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800858;
    // 0x80800848: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080084C:
    // 0x8080084C: jal         0x80800634
    // 0x80800850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800634_chjigsawbitcont(rdram, ctx);
        goto after_9;
    // 0x80800850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
L_80800854:
    // 0x80800854: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800858:
    // 0x80800858: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080085C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800860: jr          $ra
    // 0x80800864: nop

    return;
    // 0x80800864: nop

;}
RECOMP_FUNC void bashoes_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800798: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080079C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808007A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808007A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808007A8: jal         0x8009E6C4
    // 0x808007AC: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    func_8009E6C4(rdram, ctx);
        goto after_0;
    // 0x808007AC: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_0:
    // 0x808007B0: bnel        $v0, $zero, L_80800854
    if (ctx->r2 != 0) {
        // 0x808007B4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800854;
    }
    goto skip_0;
    // 0x808007B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808007B8: lw          $t6, 0x10C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10C);
    // 0x808007BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007C0: sw          $zero, 0x8($t6)
    MEM_W(0X8, ctx->r14) = 0;
    // 0x808007C4: lw          $t7, 0x10C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X10C);
    // 0x808007C8: jal         0x80800008
    // 0x808007CC: sw          $zero, 0xC($t7)
    MEM_W(0XC, ctx->r15) = 0;
    bashoes_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808007CC: sw          $zero, 0xC($t7)
    MEM_W(0XC, ctx->r15) = 0;
    after_1:
    // 0x808007D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808007D4: bne         $v0, $at, L_80800850
    if (ctx->r2 != ctx->r1) {
        // 0x808007D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800850;
    }
    // 0x808007D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007DC: jal         0x80095738
    // 0x808007E0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    baflag_isTrue(rdram, ctx);
        goto after_2;
    // 0x808007E0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x808007E4: beq         $v0, $zero, L_80800800
    if (ctx->r2 == 0) {
        // 0x808007E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800800;
    }
    // 0x808007E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007F0: jal         0x80800384
    // 0x808007F4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    bashoes_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x808007F4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x808007F8: b           L_80800854
    // 0x808007FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800854;
    // 0x808007FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800800:
    // 0x80800800: jal         0x80095738
    // 0x80800804: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    baflag_isTrue(rdram, ctx);
        goto after_4;
    // 0x80800804: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    after_4:
    // 0x80800808: beq         $v0, $zero, L_80800824
    if (ctx->r2 == 0) {
        // 0x8080080C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800824;
    }
    // 0x8080080C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800814: jal         0x80800384
    // 0x80800818: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    bashoes_entrypoint_6(rdram, ctx);
        goto after_5;
    // 0x80800818: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_5:
    // 0x8080081C: b           L_80800854
    // 0x80800820: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800854;
    // 0x80800820: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800824:
    // 0x80800824: jal         0x80095738
    // 0x80800828: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    baflag_isTrue(rdram, ctx);
        goto after_6;
    // 0x80800828: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    after_6:
    // 0x8080082C: beq         $v0, $zero, L_80800848
    if (ctx->r2 == 0) {
        // 0x80800830: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800848;
    }
    // 0x80800830: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800838: jal         0x80800384
    // 0x8080083C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    bashoes_entrypoint_6(rdram, ctx);
        goto after_7;
    // 0x8080083C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_7:
    // 0x80800840: b           L_80800854
    // 0x80800844: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800854;
    // 0x80800844: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800848:
    // 0x80800848: jal         0x80800384
    // 0x8080084C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    bashoes_entrypoint_6(rdram, ctx);
        goto after_8;
    // 0x8080084C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
L_80800850:
    // 0x80800850: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800854:
    // 0x80800854: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800858: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080085C: jr          $ra
    // 0x80800860: nop

    return;
    // 0x80800860: nop

;}
RECOMP_FUNC void _suegg_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A398: syscall     841
    recomp_syscall_handler(rdram, ctx, 0x8008A398);
    return;
    // 0x8008A39C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _subaddierouteDll_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089F88: syscall     818
    recomp_syscall_handler(rdram, ctx, 0x80089F88);
    return;
    // 0x80089F8C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_80800E80_cadbfunc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800E84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E88: jal         0x800A587C
    // 0x80800E8C: nop

    func_800A587C(rdram, ctx);
        goto after_0;
    // 0x80800E8C: nop

    after_0:
    // 0x80800E90: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800E94: bnel        $v0, $at, L_80800EB0
    if (ctx->r2 != ctx->r1) {
        // 0x80800E98: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800EB0;
    }
    goto skip_0;
    // 0x80800E98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80800E9C: jal         0x800A586C
    // 0x80800EA0: nop

    func_800A586C(rdram, ctx);
        goto after_1;
    // 0x80800EA0: nop

    after_1:
    // 0x80800EA4: b           L_80800EB0
    // 0x80800EA8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
        goto L_80800EB0;
    // 0x80800EA8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80800EAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800EB0:
    // 0x80800EB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800EB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800EB8: jr          $ra
    // 0x80800EBC: nop

    return;
    // 0x80800EBC: nop

;}
RECOMP_FUNC void func_8001662C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001662C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80016630: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80016634: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80016638: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001663C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80016640: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80016644: lui         $s2, 0x8008
    ctx->r18 = S32(0X8008 << 16);
    // 0x80016648: lui         $s3, 0x8008
    ctx->r19 = S32(0X8008 << 16);
    // 0x8001664C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80016650: addiu       $s3, $s3, -0x6488
    ctx->r19 = ADD32(ctx->r19, -0X6488);
    // 0x80016654: addiu       $s2, $s2, -0x6460
    ctx->r18 = ADD32(ctx->r18, -0X6460);
    // 0x80016658: addiu       $s0, $s0, -0x64A0
    ctx->r16 = ADD32(ctx->r16, -0X64A0);
    // 0x8001665C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80016660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80016664:
    // 0x80016664: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80016668: jal         0x8002E1F0
    // 0x8001666C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8001666C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_0:
    // 0x80016670: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80016674: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80016678: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001667C: bne         $s1, $t6, L_80016694
    if (ctx->r17 != ctx->r14) {
        // 0x80016680: nop
    
            goto L_80016694;
    }
    // 0x80016680: nop

    // 0x80016684: jal         0x800165F0
    // 0x80016688: nop

    func_800165F0(rdram, ctx);
        goto after_1;
    // 0x80016688: nop

    after_1:
    // 0x8001668C: b           L_80016664
    // 0x80016690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80016664;
    // 0x80016690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80016694:
    // 0x80016694: jal         0x8002EAD0
    // 0x80016698: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80016698: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8001669C: b           L_80016664
    // 0x800166A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80016664;
    // 0x800166A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800166A4: nop

    // 0x800166A8: nop

    // 0x800166AC: nop

    // 0x800166B0: nop

    // 0x800166B4: nop

    // 0x800166B8: nop

    // 0x800166BC: nop

    // 0x800166C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800166C4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800166C8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800166CC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800166D0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800166D4: jr          $ra
    // 0x800166D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800166D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80800CA0_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800CA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CA8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80800CAC: jal         0x80106790
    // 0x80800CB0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800CB0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80800CB4: lhu         $t7, 0x72($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X72);
    // 0x80800CB8: addiu       $a3, $zero, 0x34
    ctx->r7 = ADD32(0, 0X34);
    // 0x80800CBC: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(804, 0X7DD0) << 16);
    // 0x80800CC0: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80800CC4: multu       $t8, $a3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800CC8: addiu       $v1, $v1, 0x7DD0
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(804, 0X7DD0));
    // 0x80800CCC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800CD0: mflo        $t9
    ctx->r25 = lo;
    // 0x80800CD4: addu        $t0, $v1, $t9
    ctx->r8 = ADD32(ctx->r3, ctx->r25);
    // 0x80800CD8: lw          $t1, 0x28($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X28);
    // 0x80800CDC: beql        $t1, $zero, L_80800D18
    if (ctx->r9 == 0) {
        // 0x80800CE0: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_80800D18;
    }
    goto skip_0;
    // 0x80800CE0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800CE4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80800CE8: lhu         $t2, 0x72($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X72);
    // 0x80800CEC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800CF0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80800CF4: srl         $t3, $t2, 10
    ctx->r11 = S32(U32(ctx->r10) >> 10);
    // 0x80800CF8: multu       $t3, $a3
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800CFC: mflo        $t4
    ctx->r12 = lo;
    // 0x80800D00: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x80800D04: lw          $t9, 0x28($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X28);
    // 0x80800D08: jalr        $t9
    // 0x80800D0C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80800D0C: nop

    after_1:
    // 0x80800D10: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800D14: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
L_80800D18:
    // 0x80800D18: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800D1C: beq         $t6, $at, L_80800D2C
    if (ctx->r14 == ctx->r1) {
        // 0x80800D20: or          $a1, $t6, $zero
        ctx->r5 = ctx->r14 | 0;
            goto L_80800D2C;
    }
    // 0x80800D20: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80800D24: jal         0x808026C8
    // 0x80800D28: lw          $a0, 0x2C($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X2C);
    func_808026C8_chgameselect(rdram, ctx);
        goto after_2;
    // 0x80800D28: lw          $a0, 0x2C($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X2C);
    after_2:
L_80800D2C:
    // 0x80800D2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800D34: jr          $ra
    // 0x80800D38: nop

    return;
    // 0x80800D38: nop

;}
