#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_8008E300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E300: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008E304: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008E308: jal         0x8009C990
    // 0x8008E30C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    yaw_getIdeal(rdram, ctx);
        goto after_0;
    // 0x8008E30C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008E310: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8008E314: jal         0x8009C984
    // 0x8008E318: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    yaw_get(rdram, ctx);
        goto after_1;
    // 0x8008E318: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8008E31C: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8008E320: jal         0x800F1DCC
    // 0x8008E324: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    func_800F1DCC(rdram, ctx);
        goto after_2;
    // 0x8008E324: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    after_2:
    // 0x8008E328: jal         0x800F2100
    // 0x8008E32C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_3;
    // 0x8008E32C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_3:
    // 0x8008E330: lui         $at, 0x4307
    ctx->r1 = S32(0X4307 << 16);
    // 0x8008E334: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008E338: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008E33C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008E340: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8008E344: nop

    // 0x8008E348: bc1f        L_8008E354
    if (!c1cs) {
        // 0x8008E34C: nop
    
            goto L_8008E354;
    }
    // 0x8008E34C: nop

    // 0x8008E350: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008E354:
    // 0x8008E354: jr          $ra
    // 0x8008E358: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8008E358: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void susubgame_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000C0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808000C4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808000C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808000CC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808000D0: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x808000D4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808000D8: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
    // 0x808000DC: beq         $t7, $zero, L_80800138
    if (ctx->r15 == 0) {
        // 0x808000E0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800138;
    }
    // 0x808000E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000E4:
    // 0x808000E4: jal         0x808008DC
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008DC_susubgame(rdram, ctx);
        goto after_0;
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x808000EC: beql        $v0, $zero, L_8080010C
    if (ctx->r2 == 0) {
        // 0x808000F0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8080010C;
    }
    goto skip_0;
    // 0x808000F0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x808000F4: jal         0x800A93E4
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A93E4(rdram, ctx);
        goto after_1;
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808000FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800100: jal         0x80089548
    // 0x80800104: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _ncpod_entrypoint_17(rdram, ctx);
        goto after_2;
    // 0x80800104: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800108: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8080010C:
    // 0x8080010C: bne         $s0, $s1, L_808000E4
    if (ctx->r16 != ctx->r17) {
        // 0x80800110: nop
    
            goto L_808000E4;
    }
    // 0x80800110: nop

    // 0x80800114: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80800118: lbu         $t9, 0x1($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X1);
    // 0x8080011C: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
    // 0x80800120: beq         $t9, $zero, L_80800130
    if (ctx->r25 == 0) {
        // 0x80800124: nop
    
            goto L_80800130;
    }
    // 0x80800124: nop

    // 0x80800128: jal         0x80088830
    // 0x8080012C: sb          $zero, 0x1($t8)
    MEM_B(0X1, ctx->r24) = 0;
    _glcutDll_entrypoint_17(rdram, ctx);
        goto after_3;
    // 0x8080012C: sb          $zero, 0x1($t8)
    MEM_B(0X1, ctx->r24) = 0;
    after_3:
L_80800130:
    // 0x80800130: b           L_80800138
    // 0x80800134: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800138;
    // 0x80800134: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800138:
    // 0x80800138: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080013C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800140: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800144: jr          $ra
    // 0x80800148: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800148: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void babackpack_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800440: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800444: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800448: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080044C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800450: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x80800454: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800458: lh          $a1, 0x22($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X22);
    // 0x8080045C: jal         0x800DBEFC
    // 0x80800460: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    func_800DBEFC(rdram, ctx);
        goto after_0;
    // 0x80800460: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    after_0:
    // 0x80800464: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800468: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080046C: jr          $ra
    // 0x80800470: nop

    return;
    // 0x80800470: nop

;}
RECOMP_FUNC void bsfirstp_entrypoint_30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808071C4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808071C8: lui         $v0, 0x8081
    ctx->r2 = S32(RELOC_HI16(439, 0XB570) << 16);
    // 0x808071CC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808071D0: jr          $ra
    // 0x808071D4: lw          $v0, -0x4A90($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(439, 0XB570));
    return;
    // 0x808071D4: lw          $v0, -0x4A90($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(439, 0XB570));
;}
RECOMP_FUNC void func_800A2314(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2314: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A2318: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A231C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800A2320: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800A2324: jal         0x800C87B8
    // 0x800A2328: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800C87B8(rdram, ctx);
        goto after_0;
    // 0x800A2328: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x800A232C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800A2330: jal         0x800A22C8
    // 0x800A2334: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800A22C8(rdram, ctx);
        goto after_1;
    // 0x800A2334: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x800A2338: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800A233C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x800A2340: lw          $t7, 0xB4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XB4);
    // 0x800A2344: jal         0x800B38A8
    // 0x800A2348: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    func_800B38A8(rdram, ctx);
        goto after_2;
    // 0x800A2348: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    after_2:
    // 0x800A234C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A2350: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800A2354: jr          $ra
    // 0x800A2358: nop

    return;
    // 0x800A2358: nop

;}
RECOMP_FUNC void func_808005BC_chclinker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808005C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005C4: jal         0x80106790
    // 0x808005C8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808005C8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x808005CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808005D0: jal         0x80100094
    // 0x808005D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808005D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808005D8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808005DC: jal         0x8010C710
    // 0x808005E0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_8010C710(rdram, ctx);
        goto after_2;
    // 0x808005E0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_2:
    // 0x808005E4: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x808005E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808005EC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808005F0: lw          $a1, 0x18($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X18);
    // 0x808005F4: blez        $a1, L_80800630
    if (SIGNED(ctx->r5) <= 0) {
        // 0x808005F8: nop
    
            goto L_80800630;
    }
    // 0x808005F8: nop

    // 0x808005FC: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80800600: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800604: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
L_80800608:
    // 0x80800608: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8080060C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80800610: nop

    // 0x80800614: bc1fl       L_80800624
    if (!c1cs) {
        // 0x80800618: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80800624;
    }
    goto skip_0;
    // 0x80800618: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x8080061C: addiu       $a2, $v1, 0x1
    ctx->r6 = ADD32(ctx->r3, 0X1);
    // 0x80800620: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80800624:
    // 0x80800624: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80800628: bne         $at, $zero, L_80800608
    if (ctx->r1 != 0) {
        // 0x8080062C: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80800608;
    }
    // 0x8080062C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_80800630:
    // 0x80800630: beq         $a2, $zero, L_80800648
    if (ctx->r6 == 0) {
        // 0x80800634: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80800648;
    }
    // 0x80800634: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800638: beql        $a2, $at, L_8080065C
    if (ctx->r6 == ctx->r1) {
        // 0x8080063C: mtc1        $v0, $f10
        ctx->f10.u32l = ctx->r2;
            goto L_8080065C;
    }
    goto skip_1;
    // 0x8080063C: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    skip_1:
    // 0x80800640: b           L_80800698
    // 0x80800644: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800698;
    // 0x80800644: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800648:
    // 0x80800648: lw          $t6, 0x8($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X8);
    // 0x8080064C: lwc1        $f8, 0x10($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80800650: sw          $t6, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r14;
    // 0x80800654: swc1        $f8, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f8.u32l;
    // 0x80800658: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
L_8080065C:
    // 0x8080065C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80800660: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x80800664: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800668: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8080066C: addu        $v1, $a3, $t7
    ctx->r3 = ADD32(ctx->r7, ctx->r15);
    // 0x80800670: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80800674: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
    // 0x80800678: swc1        $f16, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f16.u32l;
    // 0x8080067C: lw          $t0, 0x18($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X18);
    // 0x80800680: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80800684: slti        $at, $t1, 0x3
    ctx->r1 = SIGNED(ctx->r9) < 0X3 ? 1 : 0;
    // 0x80800688: bne         $at, $zero, L_80800694
    if (ctx->r1 != 0) {
        // 0x8080068C: sw          $t1, 0x18($a3)
        MEM_W(0X18, ctx->r7) = ctx->r9;
            goto L_80800694;
    }
    // 0x8080068C: sw          $t1, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r9;
    // 0x80800690: sw          $t3, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r11;
L_80800694:
    // 0x80800694: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800698:
    // 0x80800698: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080069C: jr          $ra
    // 0x808006A0: nop

    return;
    // 0x808006A0: nop

;}
RECOMP_FUNC void _gczoombox_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087B90: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087B90);
    return;
    // 0x80087B94: addi        $t0, $zero, 0x58
    ctx->r8 = ADD32(0, 0X58);
;}
RECOMP_FUNC void _bsvan_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084148: syscall     105
    recomp_syscall_handler(rdram, ctx, 0x80084148);
    return;
    // 0x8008414C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_808007A8_chflamer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007A8: addiu       $sp, $sp, -0x158
    ctx->r29 = ADD32(ctx->r29, -0X158);
    // 0x808007AC: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x808007B0: or          $fp, $a1, $zero
    ctx->r30 = ctx->r5 | 0;
    // 0x808007B4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x808007B8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x808007BC: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x808007C0: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x808007C4: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x808007C8: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x808007CC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x808007D0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x808007D4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x808007D8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808007DC: jal         0x80100094
    // 0x808007E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808007E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808007E4: lh          $v1, 0x16($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X16);
    // 0x808007E8: lh          $a0, 0x18($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X18);
    // 0x808007EC: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x808007F0: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x808007F4: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x808007F8: bnel        $at, $zero, L_8080080C
    if (ctx->r1 != 0) {
        // 0x808007FC: slt         $at, $v1, $a0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8080080C;
    }
    goto skip_0;
    // 0x808007FC: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    skip_0:
    // 0x80800800: b           L_80800890
    // 0x80800804: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800890;
    // 0x80800804: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800808: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
L_8080080C:
    // 0x8080080C: beq         $at, $zero, L_8080088C
    if (ctx->r1 == 0) {
        // 0x80800810: addiu       $s6, $s4, 0x1AC
        ctx->r22 = ADD32(ctx->r20, 0X1AC);
            goto L_8080088C;
    }
    // 0x80800810: addiu       $s6, $s4, 0x1AC
    ctx->r22 = ADD32(ctx->r20, 0X1AC);
    // 0x80800814: lh          $v0, 0x16($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X16);
    // 0x80800818: lh          $v1, 0x18($s4)
    ctx->r3 = MEM_H(ctx->r20, 0X18);
    // 0x8080081C: addiu       $s7, $sp, 0x68
    ctx->r23 = ADD32(ctx->r29, 0X68);
    // 0x80800820: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
L_80800824:
    // 0x80800824: jal         0x800F1418
    // 0x80800828: subu        $a1, $v1, $v0
    ctx->r5 = SUB32(ctx->r3, ctx->r2);
    func_800F1418(rdram, ctx);
        goto after_1;
    // 0x80800828: subu        $a1, $v1, $v0
    ctx->r5 = SUB32(ctx->r3, ctx->r2);
    after_1:
    // 0x8080082C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80800830: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x80800834: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80800838: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8080083C: jal         0x80089FA8
    // 0x80800840: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    _subaddievolume_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80800840: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    after_2:
    // 0x80800844: bltz        $v0, L_80800850
    if (SIGNED(ctx->r2) < 0) {
        // 0x80800848: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80800850;
    }
    // 0x80800848: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8080084C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
L_80800850:
    // 0x80800850: blez        $v0, L_8080088C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800854: addiu       $s1, $sp, 0x68
        ctx->r17 = ADD32(ctx->r29, 0X68);
            goto L_8080088C;
    }
    // 0x80800854: addiu       $s1, $sp, 0x68
    ctx->r17 = ADD32(ctx->r29, 0X68);
    // 0x80800858: blez        $v0, L_80800878
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8080085C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80800878;
    }
    // 0x8080085C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80800860:
    // 0x80800860: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800864: jal         0x808008C0
    // 0x80800868: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_808008C0_chflamer(rdram, ctx);
        goto after_3;
    // 0x80800868: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x8080086C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800870: bne         $s0, $s2, L_80800860
    if (ctx->r16 != ctx->r18) {
        // 0x80800874: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80800860;
    }
    // 0x80800874: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
L_80800878:
    // 0x80800878: lh          $v0, 0x16($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X16);
    // 0x8080087C: lh          $v1, 0x18($s4)
    ctx->r3 = MEM_H(ctx->r20, 0X18);
    // 0x80800880: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80800884: bnel        $at, $zero, L_80800824
    if (ctx->r1 != 0) {
        // 0x80800888: addiu       $a0, $zero, 0x14
        ctx->r4 = ADD32(0, 0X14);
            goto L_80800824;
    }
    goto skip_1;
    // 0x80800888: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    skip_1:
L_8080088C:
    // 0x8080088C: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
L_80800890:
    // 0x80800890: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80800894: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800898: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8080089C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x808008A0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x808008A4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x808008A8: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x808008AC: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x808008B0: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x808008B4: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x808008B8: jr          $ra
    // 0x808008BC: addiu       $sp, $sp, 0x158
    ctx->r29 = ADD32(ctx->r29, 0X158);
    return;
    // 0x808008BC: addiu       $sp, $sp, 0x158
    ctx->r29 = ADD32(ctx->r29, 0X158);
;}
RECOMP_FUNC void _chbouncycastle_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085EB0: syscall     255
    recomp_syscall_handler(rdram, ctx, 0x80085EB0);
    return;
    // 0x80085EB4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void basub_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006C4: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x808006C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808006CC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808006D0: jal         0x800F53D0
    // 0x808006D4: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    func_800F53D0(rdram, ctx);
        goto after_0;
    // 0x808006D4: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808006D8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808006DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808006E0: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x808006E4: jal         0x80092CDC
    // 0x808006E8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_80092CDC(rdram, ctx);
        goto after_1;
    // 0x808006E8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_1:
    // 0x808006EC: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x808006F0: jal         0x80092EB0
    // 0x808006F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80092EB0(rdram, ctx);
        goto after_2;
    // 0x808006F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808006F8: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x808006FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800700: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x80800704: beq         $t6, $zero, L_8080075C
    if (ctx->r14 == 0) {
        // 0x80800708: nop
    
            goto L_8080075C;
    }
    // 0x80800708: nop

    // 0x8080070C: beq         $v0, $zero, L_8080075C
    if (ctx->r2 == 0) {
        // 0x80800710: addiu       $a2, $sp, 0x5C
        ctx->r6 = ADD32(ctx->r29, 0X5C);
            goto L_8080075C;
    }
    // 0x80800710: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    // 0x80800714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800718: jal         0x800F3BD0
    // 0x8080071C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800F3BD0(rdram, ctx);
        goto after_3;
    // 0x8080071C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_3:
    // 0x80800720: jal         0x8009BFCC
    // 0x80800724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BFCC(rdram, ctx);
        goto after_4;
    // 0x80800724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800728: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8080072C: jal         0x8009C984
    // 0x80800730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_5;
    // 0x80800730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800734: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800738: lw          $t7, 0x130($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X130);
    // 0x8080073C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800740: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80800744: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80800748: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8080074C: jal         0x800EEC30
    // 0x80800750: lw          $a3, 0x68($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X68);
    func_800EEC30(rdram, ctx);
        goto after_6;
    // 0x80800750: lw          $a3, 0x68($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X68);
    after_6:
    // 0x80800754: b           L_8080079C
    // 0x80800758: lw          $v0, 0x130($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X130);
        goto L_8080079C;
    // 0x80800758: lw          $v0, 0x130($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X130);
L_8080075C:
    // 0x8080075C: jal         0x80084B28
    // 0x80800760: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    _baeggfire_entrypoint_3(rdram, ctx);
        goto after_7;
    // 0x80800760: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_7:
    // 0x80800764: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80800768: jal         0x800EF368
    // 0x8080076C: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    func_800EF368(rdram, ctx);
        goto after_8;
    // 0x8080076C: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    after_8:
    // 0x80800770: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80800774: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x80800778: jal         0x800EE780
    // 0x8080077C: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    func_800EE780(rdram, ctx);
        goto after_9;
    // 0x8080077C: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_9:
    // 0x80800780: lw          $t8, 0x130($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X130);
    // 0x80800784: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80800788: jal         0x800EF368
    // 0x8080078C: lw          $a1, 0x68($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X68);
    func_800EF368(rdram, ctx);
        goto after_10;
    // 0x8080078C: lw          $a1, 0x68($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X68);
    after_10:
    // 0x80800790: jal         0x80084AF0
    // 0x80800794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baeggcursor_entrypoint_8(rdram, ctx);
        goto after_11;
    // 0x80800794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800798: lw          $v0, 0x130($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X130);
L_8080079C:
    // 0x8080079C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007A0: lbu         $t9, 0x5E($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X5E);
    // 0x808007A4: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x808007A8: jal         0x800964DC
    // 0x808007AC: sb          $t0, 0x5E($v0)
    MEM_B(0X5E, ctx->r2) = ctx->r8;
    func_800964DC(rdram, ctx);
        goto after_12;
    // 0x808007AC: sb          $t0, 0x5E($v0)
    MEM_B(0X5E, ctx->r2) = ctx->r8;
    after_12:
    // 0x808007B0: lw          $t1, 0x184($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X184);
    // 0x808007B4: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x808007B8: addiu       $a3, $a3, 0x51B0
    ctx->r7 = ADD32(ctx->r7, 0X51B0);
    // 0x808007BC: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x808007C0: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x808007C4: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x808007C8: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    // 0x808007CC: jal         0x800872E0
    // 0x808007D0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    _chtorpedo_entrypoint_0(rdram, ctx);
        goto after_13;
    // 0x808007D0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_13:
    // 0x808007D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007D8: jal         0x80800254
    // 0x808007DC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80800254_basub(rdram, ctx);
        goto after_14;
    // 0x808007DC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_14:
    // 0x808007E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808007E4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808007E8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x808007EC: jr          $ra
    // 0x808007F0: nop

    return;
    // 0x808007F0: nop

;}
RECOMP_FUNC void func_80800060_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800060: jr          $ra
    // 0x80800064: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800064: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80800000_chperspexboxswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800008: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080000C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800010: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800014: bne         $a1, $at, L_80800060
    if (ctx->r5 != ctx->r1) {
        // 0x80800018: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_80800060;
    }
    // 0x80800018: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8080001C: addiu       $a0, $zero, 0x4C0
    ctx->r4 = ADD32(0, 0X4C0);
    // 0x80800020: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800024: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800028: jal         0x80101180
    // 0x8080002C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_80101180(rdram, ctx);
        goto after_0;
    // 0x8080002C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800030: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800038: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x8080003C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x80800040: jal         0x80085708
    // 0x80800044: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x80800044: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_1:
    // 0x80800048: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080004C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800050: jal         0x80085820
    // 0x80800054: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _chswitch_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x80800054: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800058: b           L_80800074
    // 0x8080005C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800074;
    // 0x8080005C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800060:
    // 0x80800060: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800064: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80800068: jal         0x80085820
    // 0x8080006C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _chswitch_entrypoint_10(rdram, ctx);
        goto after_3;
    // 0x8080006C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80800070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800074:
    // 0x80800074: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800078: jr          $ra
    // 0x8080007C: nop

    return;
    // 0x8080007C: nop

;}
RECOMP_FUNC void func_808000F4_chdrawbridgeswitches(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000FC: addiu       $t6, $zero, 0x68
    ctx->r14 = ADD32(0, 0X68);
    // 0x80800100: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800104: jal         0x80800030
    // 0x80800108: addiu       $a3, $zero, 0x69
    ctx->r7 = ADD32(0, 0X69);
    func_80800030_chdrawbridgeswitches(rdram, ctx);
        goto after_0;
    // 0x80800108: addiu       $a3, $zero, 0x69
    ctx->r7 = ADD32(0, 0X69);
    after_0:
    // 0x8080010C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800110: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800114: jr          $ra
    // 0x80800118: nop

    return;
    // 0x80800118: nop

;}
RECOMP_FUNC void chstatuebossbits_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1424, 0X6F0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x6F0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1424, 0X6F0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x6F0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1424, 0X6F0));
;}
RECOMP_FUNC void _bsbtrot_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082BC0: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082BC0);
    return;
    // 0x80082BC4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800774_chtiptup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800774: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800778: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080077C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800780: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800784: jal         0x80088078
    // 0x80800788: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    _gcdialogcamera_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800788: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x8080078C: beq         $v0, $zero, L_808007B8
    if (ctx->r2 == 0) {
        // 0x80800790: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808007B8;
    }
    // 0x80800790: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800794: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x80800798: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080079C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808007A0: beq         $t6, $at, L_808007B0
    if (ctx->r14 == ctx->r1) {
        // 0x808007A4: nop
    
            goto L_808007B0;
    }
    // 0x808007A4: nop

    // 0x808007A8: jal         0x80800808
    // 0x808007AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800808_chtiptup(rdram, ctx);
        goto after_1;
    // 0x808007AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
L_808007B0:
    // 0x808007B0: b           L_808007BC
    // 0x808007B4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_808007BC;
    // 0x808007B4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_808007B8:
    // 0x808007B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808007BC:
    // 0x808007BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007C4: jr          $ra
    // 0x808007C8: nop

    return;
    // 0x808007C8: nop

;}
RECOMP_FUNC void func_8080018C_chboggyfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080018C: lwc1        $f2, 0x2C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x80800190: lwc1        $f4, 0x28($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X28);
    // 0x80800194: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800198: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8080019C: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x808001A0: swc1        $f6, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f6.u32l;
    // 0x808001A4: lwc1        $f0, 0x28($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X28);
    // 0x808001A8: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x808001AC: nop

    // 0x808001B0: bc1fl       L_808001CC
    if (!c1cs) {
        // 0x808001B4: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_808001CC;
    }
    goto skip_0;
    // 0x808001B4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_0:
    // 0x808001B8: sub.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x808001BC: swc1        $f12, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f12.u32l;
    // 0x808001C0: lwc1        $f0, 0x28($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X28);
    // 0x808001C4: swc1        $f8, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f8.u32l;
    // 0x808001C8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_808001CC:
    // 0x808001CC: nop

    // 0x808001D0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x808001D4: nop

    // 0x808001D8: bc1f        L_808001F0
    if (!c1cs) {
        // 0x808001DC: nop
    
            goto L_808001F0;
    }
    // 0x808001DC: nop

    // 0x808001E0: lwc1        $f10, 0x2C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x808001E4: swc1        $f2, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f2.u32l;
    // 0x808001E8: sub.s       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x808001EC: swc1        $f16, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f16.u32l;
L_808001F0:
    // 0x808001F0: jr          $ra
    // 0x808001F4: nop

    return;
    // 0x808001F4: nop

;}
RECOMP_FUNC void _chdoormake_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800868B0: syscall     393
    recomp_syscall_handler(rdram, ctx, 0x800868B0);
    return;
    // 0x800868B4: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_80800300_chswappy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800300: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800304: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800308: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x8080030C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800310: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800314: beq         $a1, $at, L_80800348
    if (ctx->r5 == ctx->r1) {
        // 0x80800318: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80800348;
    }
    // 0x80800318: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080031C: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x80800320: beq         $a1, $at, L_80800378
    if (ctx->r5 == ctx->r1) {
        // 0x80800324: addiu       $at, $zero, 0x3E
        ctx->r1 = ADD32(0, 0X3E);
            goto L_80800378;
    }
    // 0x80800324: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x80800328: beq         $a1, $at, L_808003A8
    if (ctx->r5 == ctx->r1) {
        // 0x8080032C: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_808003A8;
    }
    // 0x8080032C: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800330: bne         $a1, $at, L_808003BC
    if (ctx->r5 != ctx->r1) {
        // 0x80800334: nop
    
            goto L_808003BC;
    }
    // 0x80800334: nop

    // 0x80800338: jal         0x808000B0
    // 0x8080033C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808000B0_chswappy(rdram, ctx);
        goto after_0;
    // 0x8080033C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800340: b           L_808003C8
    // 0x80800344: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003C8;
    // 0x80800344: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800348:
    // 0x80800348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080034C: jal         0x808000B0
    // 0x80800350: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808000B0_chswappy(rdram, ctx);
        goto after_1;
    // 0x80800350: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800358: jal         0x80103110
    // 0x8080035C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_2;
    // 0x8080035C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800360: jal         0x8010A590
    // 0x80800364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_3;
    // 0x80800364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800368: jal         0x80089CA0
    // 0x8080036C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x8080036C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800370: b           L_808003C8
    // 0x80800374: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003C8;
    // 0x80800374: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800378:
    // 0x80800378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080037C: jal         0x808000B0
    // 0x80800380: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808000B0_chswappy(rdram, ctx);
        goto after_5;
    // 0x80800380: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800388: jal         0x80103110
    // 0x8080038C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_6;
    // 0x8080038C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80800390: jal         0x8010A570
    // 0x80800394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_7;
    // 0x80800394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800398: jal         0x80089CB8
    // 0x8080039C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_5(rdram, ctx);
        goto after_8;
    // 0x8080039C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808003A0: b           L_808003C8
    // 0x808003A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003C8;
    // 0x808003A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003A8:
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003AC: jal         0x80800234
    // 0x808003B0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_80800234_chswappy(rdram, ctx);
        goto after_9;
    // 0x808003B0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_9:
    // 0x808003B4: b           L_808003C8
    // 0x808003B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003C8;
    // 0x808003B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003BC:
    // 0x808003BC: b           L_808003C8
    // 0x808003C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808003C8;
    // 0x808003C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808003C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003C8:
    // 0x808003C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003D4: jr          $ra
    // 0x808003D8: nop

    return;
    // 0x808003D8: nop

;}
RECOMP_FUNC void _bafpctrl_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084C80: syscall     133
    recomp_syscall_handler(rdram, ctx, 0x80084C80);
    return;
    // 0x80084C84: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800EE97C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EE97C: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800EE980: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800EE984: lwc1        $f10, 0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800EE988: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800EE98C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800EE990: nop

    // 0x800EE994: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800EE998: sub.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x800EE99C: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x800EE9A0: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800EE9A4: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800EE9A8: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800EE9AC: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800EE9B0: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800EE9B4: nop

    // 0x800EE9B8: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x800EE9BC: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800EE9C0: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x800EE9C4: lwc1        $f8, 0x4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800EE9C8: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800EE9CC: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800EE9D0: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800EE9D4: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800EE9D8: nop

    // 0x800EE9DC: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800EE9E0: sub.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x800EE9E4: jr          $ra
    // 0x800EE9E8: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    return;
    // 0x800EE9E8: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
;}
RECOMP_FUNC void func_80800000_chfantasycannon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: lhu         $a0, 0x76($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X76);
    // 0x8080000C: srl         $t6, $a0, 7
    ctx->r14 = S32(U32(ctx->r4) >> 7);
    // 0x80800010: jal         0x800DA298
    // 0x80800014: addiu       $a0, $t6, 0x55D
    ctx->r4 = ADD32(ctx->r14, 0X55D);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800014: addiu       $a0, $t6, 0x55D
    ctx->r4 = ADD32(ctx->r14, 0X55D);
    after_0:
    // 0x80800018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080001C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800020: jr          $ra
    // 0x80800024: nop

    return;
    // 0x80800024: nop

;}
RECOMP_FUNC void func_808012F8_chnewfreezy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012F8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808012FC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80801300: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80801304: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80801308: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x8080130C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80801310: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80801314: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80801318: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8080131C: jal         0x80100094
    // 0x80801320: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801320: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801324: lw          $t6, 0x6C($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X6C);
    // 0x80801328: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8080132C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80801330: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80801334: beq         $t7, $zero, L_8080139C
    if (ctx->r15 == 0) {
        // 0x80801338: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8080139C;
    }
    // 0x80801338: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8080133C: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80801340: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80801344: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
    // 0x80801348: lb          $t8, 0x5C($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X5C);
L_8080134C:
    // 0x8080134C: addiu       $a0, $s2, 0x28
    ctx->r4 = ADD32(ctx->r18, 0X28);
    // 0x80801350: beql        $s3, $t8, L_80801384
    if (ctx->r19 == ctx->r24) {
        // 0x80801354: lw          $t9, 0x6C($s2)
        ctx->r25 = MEM_W(ctx->r18, 0X6C);
            goto L_80801384;
    }
    goto skip_0;
    // 0x80801354: lw          $t9, 0x6C($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X6C);
    skip_0:
    // 0x80801358: jal         0x800EEAD4
    // 0x8080135C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EEAD4(rdram, ctx);
        goto after_1;
    // 0x8080135C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80801360: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80801364: mul.s       $f6, $f22, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f4.fl);
    // 0x80801368: add.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8080136C: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x80801370: nop

    // 0x80801374: bc1fl       L_80801384
    if (!c1cs) {
        // 0x80801378: lw          $t9, 0x6C($s2)
        ctx->r25 = MEM_W(ctx->r18, 0X6C);
            goto L_80801384;
    }
    goto skip_1;
    // 0x80801378: lw          $t9, 0x6C($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X6C);
    skip_1:
    // 0x8080137C: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
    // 0x80801380: lw          $t9, 0x6C($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X6C);
L_80801384:
    // 0x80801384: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80801388: addiu       $s0, $s0, 0x60
    ctx->r16 = ADD32(ctx->r16, 0X60);
    // 0x8080138C: andi        $t0, $t9, 0x1FF
    ctx->r8 = ctx->r25 & 0X1FF;
    // 0x80801390: sltu        $at, $s1, $t0
    ctx->r1 = ctx->r17 < ctx->r8 ? 1 : 0;
    // 0x80801394: bnel        $at, $zero, L_8080134C
    if (ctx->r1 != 0) {
        // 0x80801398: lb          $t8, 0x5C($s0)
        ctx->r24 = MEM_B(ctx->r16, 0X5C);
            goto L_8080134C;
    }
    goto skip_2;
    // 0x80801398: lb          $t8, 0x5C($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X5C);
    skip_2:
L_8080139C:
    // 0x8080139C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x808013A0: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    // 0x808013A4: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x808013A8: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x808013AC: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x808013B0: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x808013B4: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x808013B8: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x808013BC: jr          $ra
    // 0x808013C0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x808013C0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void bstimeout_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808002B4: jal         0x800852F0
    // 0x808002B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_0;
    // 0x808002B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808002BC: beql        $v0, $zero, L_808002D0
    if (ctx->r2 == 0) {
        // 0x808002C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808002D0;
    }
    goto skip_0;
    // 0x808002C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808002C4: jal         0x800A05DC
    // 0x808002C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A05DC(rdram, ctx);
        goto after_1;
    // 0x808002C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808002CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002D0:
    // 0x808002D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002D4: jr          $ra
    // 0x808002D8: nop

    return;
    // 0x808002D8: nop

;}
RECOMP_FUNC void func_80800000_chfactorydrums(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80800004: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80800008: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8080000C: addiu       $s4, $sp, 0x48
    ctx->r20 = ADD32(ctx->r29, 0X48);
    // 0x80800010: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80800014: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800018: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080001C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800020: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800024: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800028: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8080002C: addiu       $a0, $zero, 0x3FF
    ctx->r4 = ADD32(0, 0X3FF);
    // 0x80800030: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800034: jal         0x80089C40
    // 0x80800038: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    _subaddiefind_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800038: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_0:
    // 0x8080003C: blez        $v0, L_80800088
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800040: addiu       $s0, $sp, 0x48
        ctx->r16 = ADD32(ctx->r29, 0X48);
            goto L_80800088;
    }
    // 0x80800040: addiu       $s0, $sp, 0x48
    ctx->r16 = ADD32(ctx->r29, 0X48);
    // 0x80800044: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80800048: addu        $s3, $t7, $s0
    ctx->r19 = ADD32(ctx->r15, ctx->r16);
    // 0x8080004C: lw          $v0, 0x70($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X70);
L_80800050:
    // 0x80800050: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800054: sll         $a2, $v0, 22
    ctx->r6 = S32(ctx->r2 << 22);
    // 0x80800058: srl         $t8, $a2, 26
    ctx->r24 = S32(U32(ctx->r6) >> 26);
    // 0x8080005C: srl         $a1, $v0, 25
    ctx->r5 = S32(U32(ctx->r2) >> 25);
    // 0x80800060: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80800064: addiu       $a2, $t8, -0x1
    ctx->r6 = ADD32(ctx->r24, -0X1);
    // 0x80800068: jal         0x800CC338
    // 0x8080006C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800CC338(rdram, ctx);
        goto after_1;
    // 0x8080006C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x80800070: beq         $v0, $zero, L_8080007C
    if (ctx->r2 == 0) {
        // 0x80800074: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8080007C;
    }
    // 0x80800074: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800078: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8080007C:
    // 0x8080007C: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x80800080: bnel        $at, $zero, L_80800050
    if (ctx->r1 != 0) {
        // 0x80800084: lw          $v0, 0x70($s5)
        ctx->r2 = MEM_W(ctx->r21, 0X70);
            goto L_80800050;
    }
    goto skip_0;
    // 0x80800084: lw          $v0, 0x70($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X70);
    skip_0:
L_80800088:
    // 0x80800088: addiu       $a0, $zero, 0x3F0
    ctx->r4 = ADD32(0, 0X3F0);
    // 0x8080008C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800090: jal         0x80089C40
    // 0x80800094: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    _subaddiefind_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80800094: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_2:
    // 0x80800098: blez        $v0, L_808000FC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8080009C: addiu       $s0, $sp, 0x48
        ctx->r16 = ADD32(ctx->r29, 0X48);
            goto L_808000FC;
    }
    // 0x8080009C: addiu       $s0, $sp, 0x48
    ctx->r16 = ADD32(ctx->r29, 0X48);
    // 0x808000A0: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x808000A4: addu        $s4, $t0, $s0
    ctx->r20 = ADD32(ctx->r8, ctx->r16);
    // 0x808000A8: addiu       $s3, $zero, 0x5
    ctx->r19 = ADD32(0, 0X5);
    // 0x808000AC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_808000B0:
    // 0x808000B0: lhu         $t1, 0x72($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X72);
    // 0x808000B4: srl         $t2, $t1, 10
    ctx->r10 = S32(U32(ctx->r9) >> 10);
    // 0x808000B8: bnel        $s3, $t2, L_808000F0
    if (ctx->r19 != ctx->r10) {
        // 0x808000BC: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_808000F0;
    }
    goto skip_1;
    // 0x808000BC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_1:
    // 0x808000C0: lw          $v0, 0x70($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X70);
    // 0x808000C4: addiu       $a0, $v1, 0x4
    ctx->r4 = ADD32(ctx->r3, 0X4);
    // 0x808000C8: sll         $a2, $v0, 22
    ctx->r6 = S32(ctx->r2 << 22);
    // 0x808000CC: srl         $t3, $a2, 26
    ctx->r11 = S32(U32(ctx->r6) >> 26);
    // 0x808000D0: srl         $a1, $v0, 25
    ctx->r5 = S32(U32(ctx->r2) >> 25);
    // 0x808000D4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x808000D8: jal         0x800CC338
    // 0x808000DC: addiu       $a2, $t3, -0x1
    ctx->r6 = ADD32(ctx->r11, -0X1);
    func_800CC338(rdram, ctx);
        goto after_3;
    // 0x808000DC: addiu       $a2, $t3, -0x1
    ctx->r6 = ADD32(ctx->r11, -0X1);
    after_3:
    // 0x808000E0: beql        $v0, $zero, L_808000F0
    if (ctx->r2 == 0) {
        // 0x808000E4: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_808000F0;
    }
    goto skip_2;
    // 0x808000E4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_2:
    // 0x808000E8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808000EC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_808000F0:
    // 0x808000F0: sltu        $at, $s0, $s4
    ctx->r1 = ctx->r16 < ctx->r20 ? 1 : 0;
    // 0x808000F4: bnel        $at, $zero, L_808000B0
    if (ctx->r1 != 0) {
        // 0x808000F8: lw          $v1, 0x0($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X0);
            goto L_808000B0;
    }
    goto skip_3;
    // 0x808000F8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    skip_3:
L_808000FC:
    // 0x808000FC: lhu         $t4, 0x76($s5)
    ctx->r12 = MEM_HU(ctx->r21, 0X76);
    // 0x80800100: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800104: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80800108: srl         $t5, $t4, 7
    ctx->r13 = S32(U32(ctx->r12) >> 7);
    // 0x8080010C: addiu       $t7, $t5, -0x32
    ctx->r15 = ADD32(ctx->r13, -0X32);
    // 0x80800110: slt         $v0, $s1, $t7
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80800114: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800118: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080011C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800120: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800124: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80800128: jr          $ra
    // 0x8080012C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8080012C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_8009BC5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BC5C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8009BC60: lw          $t6, 0xC8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC8);
    // 0x8009BC64: jr          $ra
    // 0x8009BC68: swc1        $f12, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x8009BC68: swc1        $f12, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void _bsdronelook_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083120: syscall     45
    recomp_syscall_handler(rdram, ctx, 0x80083120);
    return;
    // 0x80083124: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800A4A4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4A4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A4A50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A4A54: jal         0x800A4190
    // 0x800A4A58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800A4190(rdram, ctx);
        goto after_0;
    // 0x800A4A58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A4A5C: jal         0x800A4878
    // 0x800A4A60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A4878(rdram, ctx);
        goto after_1;
    // 0x800A4A60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800A4A64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A4A68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A4A6C: jr          $ra
    // 0x800A4A70: nop

    return;
    // 0x800A4A70: nop

;}
RECOMP_FUNC void chjollyroger_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1036, 0X13A0) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x13A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1036, 0X13A0));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x13A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1036, 0X13A0));
;}
RECOMP_FUNC void func_80108EDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108EDC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80108EE0: jr          $ra
    // 0x80108EE4: addiu       $v0, $v0, 0x45E4
    ctx->r2 = ADD32(ctx->r2, 0X45E4);
    return;
    // 0x80108EE4: addiu       $v0, $v0, 0x45E4
    ctx->r2 = ADD32(ctx->r2, 0X45E4);
;}
RECOMP_FUNC void func_800E7428(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E7428: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E742C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E7430: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800E7434: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800E7438: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800E743C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x800E7440: or          $a2, $sp, $zero
    ctx->r6 = ctx->r29 | 0;
    // 0x800E7444: addiu       $a2, $a2, 0x2B
    ctx->r6 = ADD32(ctx->r6, 0X2B);
    // 0x800E7448: beq         $t6, $zero, L_800E7460
    if (ctx->r14 == 0) {
        // 0x800E744C: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_800E7460;
    }
    // 0x800E744C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800E7450: lbu         $t7, 0x1($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1);
L_800E7454:
    // 0x800E7454: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800E7458: bnel        $t7, $zero, L_800E7454
    if (ctx->r15 != 0) {
        // 0x800E745C: lbu         $t7, 0x1($a0)
        ctx->r15 = MEM_BU(ctx->r4, 0X1);
            goto L_800E7454;
    }
    goto skip_0;
    // 0x800E745C: lbu         $t7, 0x1($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1);
    skip_0:
L_800E7460:
    // 0x800E7460: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800E7464: and         $t8, $a2, $at
    ctx->r24 = ctx->r6 & ctx->r1;
    // 0x800E7468: jal         0x800E7480
    // 0x800E746C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    func_800E7480(rdram, ctx);
        goto after_0;
    // 0x800E746C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    after_0:
    // 0x800E7470: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E7474: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800E7478: jr          $ra
    // 0x800E747C: nop

    return;
    // 0x800E747C: nop

;}
RECOMP_FUNC void aligned4_memcpy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BBC8: blez        $a2, L_8001BBE8
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8001BBCC: nop
    
            goto L_8001BBE8;
    }
    // 0x8001BBCC: nop

L_8001BBD0:
    // 0x8001BBD0: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8001BBD4: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x8001BBD8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8001BBDC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8001BBE0: bgtz        $a2, L_8001BBD0
    if (SIGNED(ctx->r6) > 0) {
        // 0x8001BBE4: sw          $t6, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = ctx->r14;
            goto L_8001BBD0;
    }
    // 0x8001BBE4: sw          $t6, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->r14;
L_8001BBE8:
    // 0x8001BBE8: jr          $ra
    // 0x8001BBEC: nop

    return;
    // 0x8001BBEC: nop

;}
RECOMP_FUNC void _babackpack_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800844F8: syscall     113
    recomp_syscall_handler(rdram, ctx, 0x800844F8);
    return;
    // 0x800844FC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void subaddiedialog_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010AC: sltu        $v0, $zero, $a0
    ctx->r2 = 0 < ctx->r4 ? 1 : 0;
    // 0x808010B0: beq         $v0, $zero, L_808010C0
    if (ctx->r2 == 0) {
        // 0x808010B4: nop
    
            goto L_808010C0;
    }
    // 0x808010B4: nop

    // 0x808010B8: xori        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 ^ 0X3;
    // 0x808010BC: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
L_808010C0:
    // 0x808010C0: jr          $ra
    // 0x808010C4: nop

    return;
    // 0x808010C4: nop

;}
RECOMP_FUNC void bswasher_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801CD8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801CDC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(443, 0X1ED4) << 16);
    // 0x80801CE0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801CE4: jr          $ra
    // 0x80801CE8: lw          $v0, 0x1ED4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(443, 0X1ED4));
    return;
    // 0x80801CE8: lw          $v0, 0x1ED4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(443, 0X1ED4));
    // 0x80801CEC: nop

;}
RECOMP_FUNC void func_800D06D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D06D4: sltiu       $at, $a1, 0x7
    ctx->r1 = ctx->r5 < 0X7 ? 1 : 0;
    // 0x800D06D8: beq         $at, $zero, L_800D0770
    if (ctx->r1 == 0) {
        // 0x800D06DC: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_800D0770;
    }
    // 0x800D06DC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800D06E0: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x800D06E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D06E8: addu        $at, $at, $t6
    gpr jr_addend_800D06F0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800D06EC: lw          $t6, 0x5A10($at)
    ctx->r14 = ADD32(ctx->r1, 0X5A10);
    // 0x800D06F0: jr          $t6
    // 0x800D06F4: nop

    switch (jr_addend_800D06F0 >> 2) {
        case 0: goto L_800D070C; break;
        case 1: goto L_800D06F8; break;
        case 2: goto L_800D074C; break;
        case 3: goto L_800D0738; break;
        case 4: goto L_800D0724; break;
        case 5: goto L_800D0760; break;
        case 6: goto L_800D0768; break;
        default: switch_error(__func__, 0x800D06F0, 0x80125A10);
    }
    // 0x800D06F4: nop

L_800D06F8:
    // 0x800D06F8: sll         $t7, $a0, 1
    ctx->r15 = S32(ctx->r4 << 1);
    // 0x800D06FC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800D0700: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x800D0704: jr          $ra
    // 0x800D0708: lbu         $v0, -0x543A($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X543A);
    return;
    // 0x800D0708: lbu         $v0, -0x543A($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X543A);
L_800D070C:
    // 0x800D070C: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x800D0710: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x800D0714: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800D0718: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x800D071C: jr          $ra
    // 0x800D0720: lbu         $v0, -0x54C3($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X54C3);
    return;
    // 0x800D0720: lbu         $v0, -0x54C3($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X54C3);
L_800D0724:
    // 0x800D0724: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x800D0728: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800D072C: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x800D0730: jr          $ra
    // 0x800D0734: lbu         $v0, -0x532E($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X532E);
    return;
    // 0x800D0734: lbu         $v0, -0x532E($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X532E);
L_800D0738:
    // 0x800D0738: sll         $t0, $a0, 1
    ctx->r8 = S32(ctx->r4 << 1);
    // 0x800D073C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800D0740: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x800D0744: jr          $ra
    // 0x800D0748: lbu         $v0, -0x5352($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5352);
    return;
    // 0x800D0748: lbu         $v0, -0x5352($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5352);
L_800D074C:
    // 0x800D074C: sll         $t1, $a0, 1
    ctx->r9 = S32(ctx->r4 << 1);
    // 0x800D0750: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800D0754: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x800D0758: jr          $ra
    // 0x800D075C: lbu         $v0, -0x5386($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5386);
    return;
    // 0x800D075C: lbu         $v0, -0x5386($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5386);
L_800D0760:
    // 0x800D0760: jr          $ra
    // 0x800D0764: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    return;
    // 0x800D0764: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_800D0768:
    // 0x800D0768: jr          $ra
    // 0x800D076C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800D076C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800D0770:
    // 0x800D0770: jr          $ra
    // 0x800D0774: nop

    return;
    // 0x800D0774: nop

;}
RECOMP_FUNC void func_80098730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098730: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80098734: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x80098738: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8009873C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80098740: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80098744: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x80098748: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8009874C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80098750: jal         0x80098658
    // 0x80098754: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_80098658(rdram, ctx);
        goto after_0;
    // 0x80098754: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_0:
    // 0x80098758: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8009875C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80098760: lw          $t0, 0xE0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XE0);
    // 0x80098764: sb          $t8, 0x2E($t0)
    MEM_B(0X2E, ctx->r8) = ctx->r24;
    // 0x80098768: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009876C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80098770: jr          $ra
    // 0x80098774: nop

    return;
    // 0x80098774: nop

;}
RECOMP_FUNC void func_80803E98_chintrochar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803E98: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80803E9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803EA0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80803EA4: jal         0x80100094
    // 0x80803EA8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80803EA8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80803EAC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80803EB0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80803EB4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80803EB8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803EBC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_80803EC0:
    // 0x80803EC0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80803EC4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80803EC8: bne         $v1, $a1, L_80803EC0
    if (ctx->r3 != ctx->r5) {
        // 0x80803ECC: swc1        $f0, 0xCC($a0)
        MEM_W(0XCC, ctx->r4) = ctx->f0.u32l;
            goto L_80803EC0;
    }
    // 0x80803ECC: swc1        $f0, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->f0.u32l;
    // 0x80803ED0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80803ED4: addiu       $a0, $a2, 0xF4
    ctx->r4 = ADD32(ctx->r6, 0XF4);
    // 0x80803ED8: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80803EDC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80803EE0: jal         0x800EE7F8
    // 0x80803EE4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80803EE4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x80803EE8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80803EEC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80803EF0: jal         0x800EE7F8
    // 0x80803EF4: addiu       $a0, $a2, 0xE4
    ctx->r4 = ADD32(ctx->r6, 0XE4);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80803EF4: addiu       $a0, $a2, 0xE4
    ctx->r4 = ADD32(ctx->r6, 0XE4);
    after_2:
    // 0x80803EF8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80803EFC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80803F00: lwc1        $f4, 0x48($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X48);
    // 0x80803F04: swc1        $f4, 0x100($a2)
    MEM_W(0X100, ctx->r6) = ctx->f4.u32l;
    // 0x80803F08: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80803F0C: lwc1        $f6, 0x48($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X48);
    // 0x80803F10: swc1        $f6, 0xF0($a2)
    MEM_W(0XF0, ctx->r6) = ctx->f6.u32l;
    // 0x80803F14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803F18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80803F1C: jr          $ra
    // 0x80803F20: nop

    return;
    // 0x80803F20: nop

;}
RECOMP_FUNC void _badialog_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800847D8: syscall     121
    recomp_syscall_handler(rdram, ctx, 0x800847D8);
    return;
    // 0x800847DC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _gspropctrl_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088BF8: syscall     728
    recomp_syscall_handler(rdram, ctx, 0x80088BF8);
    return;
    // 0x80088BFC: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_8080093C_chboggygirl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080093C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800940: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800944: jal         0x80100094
    // 0x80800948: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800948: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080094C: addiu       $a0, $zero, 0x3A1
    ctx->r4 = ADD32(0, 0X3A1);
    // 0x80800950: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80800954: jal         0x80088480
    // 0x80800958: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    _glsplinefind_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800958: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x8080095C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800960: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80800964: jal         0x800EE940
    // 0x80800968: sh          $v0, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r2;
    func_800EE940(rdram, ctx);
        goto after_2;
    // 0x80800968: sh          $v0, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r2;
    after_2:
    // 0x8080096C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800970: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800974: jr          $ra
    // 0x80800978: nop

    return;
    // 0x80800978: nop

;}
RECOMP_FUNC void func_800D3F58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3F58: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800D3F5C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D3F60: addiu       $t7, $t7, -0x4A40
    ctx->r15 = ADD32(ctx->r15, -0X4A40);
    // 0x800D3F64: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800D3F68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D3F6C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800D3F70: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800D3F74: lhu         $a0, -0x4($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X4);
    // 0x800D3F78: jal         0x800DA3B8
    // 0x800D3F7C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_800DA3B8(rdram, ctx);
        goto after_0;
    // 0x800D3F7C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // 0x800D3F80: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x800D3F84: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800D3F88: addiu       $t8, $t8, -0x49F8
    ctx->r24 = ADD32(ctx->r24, -0X49F8);
    // 0x800D3F8C: bne         $v0, $t8, L_800D3FB0
    if (ctx->r2 != ctx->r24) {
        // 0x800D3F90: lw          $t9, 0x24($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X24);
            goto L_800D3FB0;
    }
    // 0x800D3F90: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800D3F94: beql        $t9, $zero, L_800D3FB4
    if (ctx->r25 == 0) {
        // 0x800D3F98: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D3FB4;
    }
    goto skip_0;
    // 0x800D3F98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D3F9C: jal         0x800F54E4
    // 0x800D3FA0: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x800D3FA0: nop

    after_1:
    // 0x800D3FA4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D3FA8: jal         0x800F4924
    // 0x800D3FAC: addiu       $a1, $zero, 0x3E7
    ctx->r5 = ADD32(0, 0X3E7);
    func_800F4924(rdram, ctx);
        goto after_2;
    // 0x800D3FAC: addiu       $a1, $zero, 0x3E7
    ctx->r5 = ADD32(0, 0X3E7);
    after_2:
L_800D3FB0:
    // 0x800D3FB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D3FB4:
    // 0x800D3FB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D3FB8: jr          $ra
    // 0x800D3FBC: nop

    return;
    // 0x800D3FBC: nop

;}
RECOMP_FUNC void _glcutDll_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088838: syscall     705
    recomp_syscall_handler(rdram, ctx, 0x80088838);
    return;
    // 0x8008883C: addi        $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
;}
RECOMP_FUNC void _chping_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800872A8: syscall     544
    recomp_syscall_handler(rdram, ctx, 0x800872A8);
    return;
    // 0x800872AC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void chmadamegrunty_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(916, 0XB98) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0xB98
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(916, 0XB98));
    return;
    // 0x80800014: addiu       $v0, $v0, 0xB98
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(916, 0XB98));
;}
RECOMP_FUNC void chterryegg_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1112, 0X13B8) << 16);
    // 0x80800028: jr          $ra
    // 0x8080002C: addiu       $v0, $v0, 0x13B8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1112, 0X13B8));
    return;
    // 0x8080002C: addiu       $v0, $v0, 0x13B8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1112, 0X13B8));
;}
RECOMP_FUNC void func_800CBB18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CBB18: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800CBB1C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800CBB20: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800CBB24: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800CBB28: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800CBB2C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800CBB30: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800CBB34: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800CBB38: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800CBB3C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800CBB40: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800CBB44: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800CBB48: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800CBB4C: addiu       $a0, $a0, -0x5180
    ctx->r4 = ADD32(ctx->r4, -0X5180);
    // 0x800CBB50: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800CBB54: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800CBB58: jal         0x80087EE0
    // 0x800CBB5C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    _gcboundDll_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x800CBB5C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_0:
    // 0x800CBB60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800CBB64: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800CBB68: jr          $ra
    // 0x800CBB6C: nop

    return;
    // 0x800CBB6C: nop

;}
RECOMP_FUNC void glintrosyncDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080018C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800190: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800194: jal         0x800343B0
    // 0x80800198: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    osGetCount_recomp(rdram, ctx);
        goto after_0;
    // 0x80800198: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080019C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x808001A0: sw          $v0, 0x75D0($at)
    MEM_W(0X75D0, ctx->r1) = ctx->r2;
    // 0x808001A4: jal         0x80800000
    // 0x808001A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800000_glintrosyncDll(rdram, ctx);
        goto after_1;
    // 0x808001A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808001AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x808001B4: sw          $v0, 0x75D4($at)
    MEM_W(0X75D4, ctx->r1) = ctx->r2;
    // 0x808001B8: jr          $ra
    // 0x808001BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x808001BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800A3410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3410: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A3414: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A3418: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A341C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800A3420: lw          $v0, 0xA0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XA0);
    // 0x800A3424: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800A3428: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A342C: lbu         $t6, 0x29($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X29);
    // 0x800A3430: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800A3434: bnel        $t6, $at, L_800A3458
    if (ctx->r14 != ctx->r1) {
        // 0x800A3438: lw          $t7, 0x24($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X24);
            goto L_800A3458;
    }
    goto skip_0;
    // 0x800A3438: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800A343C: jal         0x800947EC
    // 0x800A3440: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800947EC(rdram, ctx);
        goto after_0;
    // 0x800A3440: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800A3444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A3448: jal         0x800A0D68
    // 0x800A344C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0D68(rdram, ctx);
        goto after_1;
    // 0x800A344C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x800A3450: lw          $v0, 0xA0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XA0);
    // 0x800A3454: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
L_800A3458:
    // 0x800A3458: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800A345C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A3460: sb          $t7, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r15;
    // 0x800A3464: lw          $t8, 0xA0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XA0);
    // 0x800A3468: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800A346C: lbu         $t9, 0x29($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X29);
    // 0x800A3470: bnel        $t9, $at, L_800A3490
    if (ctx->r25 != ctx->r1) {
        // 0x800A3474: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A3490;
    }
    goto skip_1;
    // 0x800A3474: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x800A3478: jal         0x800947EC
    // 0x800A347C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800947EC(rdram, ctx);
        goto after_2;
    // 0x800A347C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x800A3480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A3484: jal         0x800A0D68
    // 0x800A3488: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0D68(rdram, ctx);
        goto after_3;
    // 0x800A3488: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x800A348C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A3490:
    // 0x800A3490: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A3494: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A3498: jr          $ra
    // 0x800A349C: nop

    return;
    // 0x800A349C: nop

;}
