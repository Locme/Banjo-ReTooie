#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800734_chmricecube(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800734: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800738: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080073C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800740: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800744: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800748: lw          $a1, 0x64($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X64);
    // 0x8080074C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800750: sll         $t7, $a1, 12
    ctx->r15 = S32(ctx->r5 << 12);
    // 0x80800754: jal         0x800DF744
    // 0x80800758: srl         $a1, $t7, 31
    ctx->r5 = S32(U32(ctx->r15) >> 31);
    func_800DF744(rdram, ctx);
        goto after_0;
    // 0x80800758: srl         $a1, $t7, 31
    ctx->r5 = S32(U32(ctx->r15) >> 31);
    after_0:
    // 0x8080075C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800760: jal         0x80101870
    // 0x80800764: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80101870(rdram, ctx);
        goto after_1;
    // 0x80800764: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80800768: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080076C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800770: jr          $ra
    // 0x80800774: nop

    return;
    // 0x80800774: nop

;}
RECOMP_FUNC void bsblongleg_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800620: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800624: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800628: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080062C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800630: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800634: jal         0x808000C8
    // 0x80800638: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    func_808000C8_bsblongleg(rdram, ctx);
        goto after_0;
    // 0x80800638: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_0:
    // 0x8080063C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800640: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800644: jal         0x8009D2F0
    // 0x80800648: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    func_8009D2F0(rdram, ctx);
        goto after_1;
    // 0x80800648: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_1:
    // 0x8080064C: jal         0x80097AD0
    // 0x80800650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_enter_first_person(rdram, ctx);
        goto after_2;
    // 0x80800650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800654: beql        $v0, $zero, L_8080066C
    if (ctx->r2 == 0) {
        // 0x80800658: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080066C;
    }
    goto skip_0;
    // 0x80800658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8080065C: jal         0x800848A8
    // 0x80800660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_24(rdram, ctx);
        goto after_3;
    // 0x80800660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800664: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080066C:
    // 0x8080066C: jal         0x80091A58
    // 0x80800670: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_4;
    // 0x80800670: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_4:
    // 0x80800674: beq         $v0, $zero, L_80800684
    if (ctx->r2 == 0) {
        // 0x80800678: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800684;
    }
    // 0x80800678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080067C: jal         0x80091788
    // 0x80800680: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    bastatetimer_clear(rdram, ctx);
        goto after_5;
    // 0x80800680: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
L_80800684:
    // 0x80800684: jal         0x8009EF10
    // 0x80800688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_6;
    // 0x80800688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080068C: blez        $v0, L_80800698
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800690: nop
    
            goto L_80800698;
    }
    // 0x80800690: nop

    // 0x80800694: addiu       $s1, $zero, 0x27
    ctx->r17 = ADD32(0, 0X27);
L_80800698:
    // 0x80800698: jal         0x8008DF18
    // 0x8080069C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DF18(rdram, ctx);
        goto after_7;
    // 0x8080069C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808006A0: beq         $v0, $zero, L_808006AC
    if (ctx->r2 == 0) {
        // 0x808006A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006AC;
    }
    // 0x808006A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006A8: addiu       $s1, $zero, 0x55
    ctx->r17 = ADD32(0, 0X55);
L_808006AC:
    // 0x808006AC: jal         0x80091A58
    // 0x808006B0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_8;
    // 0x808006B0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_8:
    // 0x808006B4: beql        $v0, $zero, L_808006D4
    if (ctx->r2 == 0) {
        // 0x808006B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006D4;
    }
    goto skip_1;
    // 0x808006B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x808006BC: jal         0x8008E078
    // 0x808006C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_9;
    // 0x808006C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808006C4: beql        $v0, $zero, L_808006D4
    if (ctx->r2 == 0) {
        // 0x808006C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006D4;
    }
    goto skip_2;
    // 0x808006C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x808006CC: addiu       $s1, $zero, 0x28
    ctx->r17 = ADD32(0, 0X28);
    // 0x808006D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808006D4:
    // 0x808006D4: jal         0x800915AC
    // 0x808006D8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    bastatetimer_isDone(rdram, ctx);
        goto after_10;
    // 0x808006D8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_10:
    // 0x808006DC: beq         $v0, $zero, L_808006E8
    if (ctx->r2 == 0) {
        // 0x808006E0: nop
    
            goto L_808006E8;
    }
    // 0x808006E0: nop

    // 0x808006E4: addiu       $s1, $zero, 0x29
    ctx->r17 = ADD32(0, 0X29);
L_808006E8:
    // 0x808006E8: jal         0x80800000
    // 0x808006EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsblongleg(rdram, ctx);
        goto after_11;
    // 0x808006EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808006F0: beq         $v0, $zero, L_808006FC
    if (ctx->r2 == 0) {
        // 0x808006F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006FC;
    }
    // 0x808006F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006F8: addiu       $s1, $zero, 0x4C
    ctx->r17 = ADD32(0, 0X4C);
L_808006FC:
    // 0x808006FC: jal         0x8009E5C8
    // 0x80800700: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    bs_setState(rdram, ctx);
        goto after_12;
    // 0x80800700: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_12:
    // 0x80800704: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800708: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080070C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800710: jr          $ra
    // 0x80800714: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800714: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ncfixposrot_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080030C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800310: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800314: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800318: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080031C: jal         0x800C52F4
    // 0x80800320: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C52F4(rdram, ctx);
        goto after_0;
    // 0x80800320: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800324: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800328: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080032C: sh          $t6, 0x18($t7)
    MEM_H(0X18, ctx->r15) = ctx->r14;
    // 0x80800330: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800334: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800338: jr          $ra
    // 0x8080033C: nop

    return;
    // 0x8080033C: nop

;}
RECOMP_FUNC void func_808016A0_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808016A0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808016A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808016A8: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x808016AC: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x808016B0: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x808016B4: lwc1        $f0, 0x98($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X98);
    // 0x808016B8: lwc1        $f20, 0x9C($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, 0X9C);
    // 0x808016BC: c.eq.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl == ctx->f20.fl;
    // 0x808016C0: nop

    // 0x808016C4: bc1tl       L_8080174C
    if (c1cs) {
        // 0x808016C8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080174C;
    }
    goto skip_0;
    // 0x808016C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808016CC: sub.s       $f12, $f0, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x808016D0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x808016D4: jal         0x800F2108
    // 0x808016D8: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    func_800F2108(rdram, ctx);
        goto after_0;
    // 0x808016D8: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x808016DC: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x808016E0: jal         0x800F2100
    // 0x808016E4: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    mlAbsF(rdram, ctx);
        goto after_1;
    // 0x808016E4: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x808016E8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808016EC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808016F0: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x808016F4: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808016F8: mul.s       $f12, $f0, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x808016FC: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x80801700: nop

    // 0x80801704: bc1f        L_80801728
    if (!c1cs) {
        // 0x80801708: nop
    
            goto L_80801728;
    }
    // 0x80801708: nop

    // 0x8080170C: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x80801710: nop

    // 0x80801714: bc1fl       L_80801728
    if (!c1cs) {
        // 0x80801718: mov.s       $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
            goto L_80801728;
    }
    goto skip_1;
    // 0x80801718: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    skip_1:
    // 0x8080171C: b           L_80801728
    // 0x80801720: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
        goto L_80801728;
    // 0x80801720: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x80801724: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_80801728:
    // 0x80801728: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x8080172C: add.s       $f20, $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f6.fl;
    // 0x80801730: swc1        $f20, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = ctx->f20.u32l;
    // 0x80801734: jal         0x800A4C68
    // 0x80801738: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_800A4C68(rdram, ctx);
        goto after_2;
    // 0x80801738: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_2:
    // 0x8080173C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80801740: jal         0x800C5148
    // 0x80801744: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800C5148(rdram, ctx);
        goto after_3;
    // 0x80801744: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80801748: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080174C:
    // 0x8080174C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80801750: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80801754: jr          $ra
    // 0x80801758: nop

    return;
    // 0x80801758: nop

;}
RECOMP_FUNC void func_80807F24_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80807F24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80807F28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80807F2C: jal         0x800A3404
    // 0x80807F30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800A3404(rdram, ctx);
        goto after_0;
    // 0x80807F30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80807F34: beq         $v0, $zero, L_80807F4C
    if (ctx->r2 == 0) {
        // 0x80807F38: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80807F4C;
    }
    // 0x80807F38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80807F3C: jal         0x800A3544
    // 0x80807F40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A3544(rdram, ctx);
        goto after_1;
    // 0x80807F40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80807F44: jal         0x80807DD4
    // 0x80807F48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80807DD4_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80807F48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
L_80807F4C:
    // 0x80807F4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80807F50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80807F54: jr          $ra
    // 0x80807F58: nop

    return;
    // 0x80807F58: nop

;}
RECOMP_FUNC void _chmumboskullfakearchpanellava_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087050: syscall     498
    recomp_syscall_handler(rdram, ctx, 0x80087050);
    return;
    // 0x80087054: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _gcstatusDll_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088398: syscall     679
    recomp_syscall_handler(rdram, ctx, 0x80088398);
    return;
    // 0x8008839C: addi        $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
;}
RECOMP_FUNC void bsdie_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800670: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800674: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(156, 0X970) << 16);
    // 0x80800678: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080067C: jr          $ra
    // 0x80800680: lw          $v0, 0x970($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(156, 0X970));
    return;
    // 0x80800680: lw          $v0, 0x970($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(156, 0X970));
;}
RECOMP_FUNC void func_80800D84_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D8C: jal         0x800A05DC
    // 0x80800D90: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800A05DC(rdram, ctx);
        goto after_0;
    // 0x80800D90: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800D94: jal         0x8009EBD0
    // 0x80800D98: nop

    func_8009EBD0(rdram, ctx);
        goto after_1;
    // 0x80800D98: nop

    after_1:
    // 0x80800D9C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800DA0: jal         0x80095760
    // 0x80800DA4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    baflag_set(rdram, ctx);
        goto after_2;
    // 0x80800DA4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_2:
    // 0x80800DA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800DAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800DB0: jr          $ra
    // 0x80800DB4: nop

    return;
    // 0x80800DB4: nop

;}
RECOMP_FUNC void idflash_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808000D0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808000D4: jal         0x80088EF8
    // 0x808000D8: addiu       $a0, $a2, -0x64
    ctx->r4 = ADD32(ctx->r6, -0X64);
    _idworld_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808000D8: addiu       $a0, $a2, -0x64
    ctx->r4 = ADD32(ctx->r6, -0X64);
    after_0:
    // 0x808000DC: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x808000E0: beq         $v0, $zero, L_80800110
    if (ctx->r2 == 0) {
        // 0x808000E4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800110;
    }
    // 0x808000E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000E8: jal         0x80088D60
    // 0x808000EC: nop

    _idflasha_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808000EC: nop

    after_1:
    // 0x808000F0: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x808000F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2906, 0X140) << 16);
    // 0x808000F8: lwc1        $f8, 0x140($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2906, 0X140));
    // 0x808000FC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800100: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80800104: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800108: b           L_8080011C
    // 0x8080010C: swc1        $f10, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f10.u32l;
        goto L_8080011C;
    // 0x8080010C: swc1        $f10, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f10.u32l;
L_80800110:
    // 0x80800110: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80800114: nop

    // 0x80800118: swc1        $f16, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f16.u32l;
L_8080011C:
    // 0x8080011C: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80800120: addiu       $a2, $a2, -0x72C8
    ctx->r6 = ADD32(ctx->r6, -0X72C8);
    // 0x80800124: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800128: jal         0x80088660
    // 0x8080012C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _glid_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x8080012C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800134: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800138: jr          $ra
    // 0x8080013C: nop

    return;
    // 0x8080013C: nop

;}
RECOMP_FUNC void func_801100E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801100E4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801100E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801100EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801100F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801100F4: beq         $a0, $a1, L_80110150
    if (ctx->r4 == ctx->r5) {
        // 0x801100F8: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_80110150;
    }
    // 0x801100F8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x801100FC: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80110100: lw          $a1, 0x0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X0);
    // 0x80110104: jal         0x800CA314
    // 0x80110108: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    func_800CA314(rdram, ctx);
        goto after_0;
    // 0x80110108: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8011010C: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x80110110: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80110114: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80110118: beql        $t6, $zero, L_80110154
    if (ctx->r14 == 0) {
        // 0x8011011C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80110154;
    }
    goto skip_0;
    // 0x8011011C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80110120: jal         0x8010FFB0
    // 0x80110124: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_8010FFB0(rdram, ctx);
        goto after_1;
    // 0x80110124: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_1:
    // 0x80110128: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8011012C: jal         0x80110770
    // 0x80110130: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_80110770(rdram, ctx);
        goto after_2;
    // 0x80110130: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_2:
    // 0x80110134: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x80110138: jal         0x80110790
    // 0x8011013C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_80110790(rdram, ctx);
        goto after_3;
    // 0x8011013C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_3:
    // 0x80110140: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80110144: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x80110148: jal         0x80111018
    // 0x8011014C: lw          $a1, 0x4($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X4);
    func_80111018(rdram, ctx);
        goto after_4;
    // 0x8011014C: lw          $a1, 0x4($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X4);
    after_4:
L_80110150:
    // 0x80110150: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80110154:
    // 0x80110154: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80110158: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8011015C: jr          $ra
    // 0x80110160: nop

    return;
    // 0x80110160: nop

;}
RECOMP_FUNC void func_800A10A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A10A0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A10A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A10A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A10AC: lw          $t6, 0x150($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X150);
    // 0x800A10B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A10B4: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800A10B8: jal         0x800964DC
    // 0x800A10BC: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    func_800964DC(rdram, ctx);
        goto after_0;
    // 0x800A10BC: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    after_0:
    // 0x800A10C0: lw          $t8, 0x150($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X150);
    // 0x800A10C4: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800A10C8: lwc1        $f4, 0x4($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X4);
    // 0x800A10CC: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800A10D0: beq         $t9, $zero, L_800A1128
    if (ctx->r25 == 0) {
        // 0x800A10D4: swc1        $f6, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
            goto L_800A1128;
    }
    // 0x800A10D4: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x800A10D8: jal         0x80096524
    // 0x800A10DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80096524(rdram, ctx);
        goto after_1;
    // 0x800A10DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800A10E0: sltu        $a0, $zero, $v0
    ctx->r4 = 0 < ctx->r2 ? 1 : 0;
    // 0x800A10E4: beql        $a0, $zero, L_800A1120
    if (ctx->r4 == 0) {
        // 0x800A10E8: lw          $t0, 0x150($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X150);
            goto L_800A1120;
    }
    goto skip_0;
    // 0x800A10E8: lw          $t0, 0x150($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X150);
    skip_0:
    // 0x800A10EC: jal         0x8009C150
    // 0x800A10F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009C150(rdram, ctx);
        goto after_2;
    // 0x800A10F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800A10F4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800A10F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A10FC: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800A1100: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A1104: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800A1108: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x800A110C: nop

    // 0x800A1110: bc1fl       L_800A1120
    if (!c1cs) {
        // 0x800A1114: lw          $t0, 0x150($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X150);
            goto L_800A1120;
    }
    goto skip_1;
    // 0x800A1114: lw          $t0, 0x150($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X150);
    skip_1:
    // 0x800A1118: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A111C: lw          $t0, 0x150($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X150);
L_800A1120:
    // 0x800A1120: b           L_800A1174
    // 0x800A1124: sb          $a0, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r4;
        goto L_800A1174;
    // 0x800A1124: sb          $a0, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r4;
L_800A1128:
    // 0x800A1128: jal         0x80096524
    // 0x800A112C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80096524(rdram, ctx);
        goto after_3;
    // 0x800A112C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800A1130: sltu        $a0, $zero, $v0
    ctx->r4 = 0 < ctx->r2 ? 1 : 0;
    // 0x800A1134: beql        $a0, $zero, L_800A1170
    if (ctx->r4 == 0) {
        // 0x800A1138: lw          $t1, 0x150($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X150);
            goto L_800A1170;
    }
    goto skip_2;
    // 0x800A1138: lw          $t1, 0x150($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X150);
    skip_2:
    // 0x800A113C: jal         0x8009C150
    // 0x800A1140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009C150(rdram, ctx);
        goto after_4;
    // 0x800A1140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800A1144: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800A1148: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A114C: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800A1150: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A1154: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800A1158: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800A115C: nop

    // 0x800A1160: bc1fl       L_800A1170
    if (!c1cs) {
        // 0x800A1164: lw          $t1, 0x150($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X150);
            goto L_800A1170;
    }
    goto skip_3;
    // 0x800A1164: lw          $t1, 0x150($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X150);
    skip_3:
    // 0x800A1168: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A116C: lw          $t1, 0x150($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X150);
L_800A1170:
    // 0x800A1170: sb          $a0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r4;
L_800A1174:
    // 0x800A1174: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800A1178: bne         $t2, $zero, L_800A11BC
    if (ctx->r10 != 0) {
        // 0x800A117C: nop
    
            goto L_800A11BC;
    }
    // 0x800A117C: nop

    // 0x800A1180: lw          $t3, 0x150($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X150);
    // 0x800A1184: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x800A1188: beq         $t4, $zero, L_800A11BC
    if (ctx->r12 == 0) {
        // 0x800A118C: nop
    
            goto L_800A11BC;
    }
    // 0x800A118C: nop

    // 0x800A1190: jal         0x8009BB50
    // 0x800A1194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_5;
    // 0x800A1194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800A1198: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x800A119C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A11A0: nop

    // 0x800A11A4: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x800A11A8: nop

    // 0x800A11AC: bc1f        L_800A11BC
    if (!c1cs) {
        // 0x800A11B0: nop
    
            goto L_800A11BC;
    }
    // 0x800A11B0: nop

    // 0x800A11B4: jal         0x800A0E64
    // 0x800A11B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A0E64(rdram, ctx);
        goto after_6;
    // 0x800A11B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_800A11BC:
    // 0x800A11BC: jal         0x800F3ED0
    // 0x800A11C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F3ED0(rdram, ctx);
        goto after_7;
    // 0x800A11C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x800A11C4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800A11C8: jal         0x800A0FD8
    // 0x800A11CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A0FD8(rdram, ctx);
        goto after_8;
    // 0x800A11CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x800A11D0: beq         $v0, $zero, L_800A11E8
    if (ctx->r2 == 0) {
        // 0x800A11D4: nop
    
            goto L_800A11E8;
    }
    // 0x800A11D4: nop

    // 0x800A11D8: lw          $t6, 0x150($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X150);
    // 0x800A11DC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800A11E0: b           L_800A1218
    // 0x800A11E4: sb          $t5, 0x1($t6)
    MEM_B(0X1, ctx->r14) = ctx->r13;
        goto L_800A1218;
    // 0x800A11E4: sb          $t5, 0x1($t6)
    MEM_B(0X1, ctx->r14) = ctx->r13;
L_800A11E8:
    // 0x800A11E8: jal         0x8008E078
    // 0x800A11EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_9;
    // 0x800A11EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x800A11F0: bnel        $v0, $zero, L_800A1214
    if (ctx->r2 != 0) {
        // 0x800A11F4: lw          $t7, 0x150($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X150);
            goto L_800A1214;
    }
    goto skip_4;
    // 0x800A11F4: lw          $t7, 0x150($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X150);
    skip_4:
    // 0x800A11F8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x800A11FC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800A1200: beq         $v0, $at, L_800A1210
    if (ctx->r2 == ctx->r1) {
        // 0x800A1204: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_800A1210;
    }
    // 0x800A1204: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800A1208: bne         $v0, $at, L_800A1218
    if (ctx->r2 != ctx->r1) {
        // 0x800A120C: nop
    
            goto L_800A1218;
    }
    // 0x800A120C: nop

L_800A1210:
    // 0x800A1210: lw          $t7, 0x150($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X150);
L_800A1214:
    // 0x800A1214: sb          $zero, 0x1($t7)
    MEM_B(0X1, ctx->r15) = 0;
L_800A1218:
    // 0x800A1218: jal         0x80096518
    // 0x800A121C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80096518(rdram, ctx);
        goto after_10;
    // 0x800A121C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x800A1220: lw          $t8, 0x150($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X150);
    // 0x800A1224: sb          $v0, 0x2($t8)
    MEM_B(0X2, ctx->r24) = ctx->r2;
    // 0x800A1228: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A122C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A1230: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800A1234: jr          $ra
    // 0x800A1238: nop

    return;
    // 0x800A1238: nop

    // 0x800A123C: nop

;}
RECOMP_FUNC void _bashoes_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085030: syscall     148
    recomp_syscall_handler(rdram, ctx, 0x80085030);
    return;
    // 0x80085034: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void chdragonbrothers_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804CC4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1852, 0X5A08) << 16);
    // 0x80804CC8: jr          $ra
    // 0x80804CCC: addiu       $v0, $v0, 0x5A08
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1852, 0X5A08));
    return;
    // 0x80804CCC: addiu       $v0, $v0, 0x5A08
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1852, 0X5A08));
;}
RECOMP_FUNC void func_808000B4_chmusicmenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B4: slti        $at, $a0, 0x9
    ctx->r1 = SIGNED(ctx->r4) < 0X9 ? 1 : 0;
    // 0x808000B8: beq         $at, $zero, L_808000C8
    if (ctx->r1 == 0) {
        // 0x808000BC: addiu       $v0, $a0, 0x1860
        ctx->r2 = ADD32(ctx->r4, 0X1860);
            goto L_808000C8;
    }
    // 0x808000BC: addiu       $v0, $a0, 0x1860
    ctx->r2 = ADD32(ctx->r4, 0X1860);
    // 0x808000C0: jr          $ra
    // 0x808000C4: addiu       $v0, $a0, 0x1851
    ctx->r2 = ADD32(ctx->r4, 0X1851);
    return;
    // 0x808000C4: addiu       $v0, $a0, 0x1851
    ctx->r2 = ADD32(ctx->r4, 0X1851);
L_808000C8:
    // 0x808000C8: jr          $ra
    // 0x808000CC: nop

    return;
    // 0x808000CC: nop

;}
RECOMP_FUNC void _bsstand_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083B68: syscall     90
    recomp_syscall_handler(rdram, ctx, 0x80083B68);
    return;
    // 0x80083B6C: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_80115118(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115118: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8011511C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80115120: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80115124: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80115128: jal         0x8001ACCC
    // 0x8011512C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x8011512C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_0:
    // 0x80115130: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80115134: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80115138: jal         0x800EA05C
    // 0x8011513C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    func_800EA05C(rdram, ctx);
        goto after_1;
    // 0x8011513C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    after_1:
    // 0x80115140: jal         0x80114E80
    // 0x80115144: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80114E80(rdram, ctx);
        goto after_2;
    // 0x80115144: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80115148: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8011514C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80115150: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x80115154: sb          $zero, 0xC($s0)
    MEM_B(0XC, ctx->r16) = 0;
    // 0x80115158: sb          $zero, 0xD($s0)
    MEM_B(0XD, ctx->r16) = 0;
    // 0x8011515C: sb          $t7, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r15;
    // 0x80115160: jal         0x800EA05C
    // 0x80115164: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    func_800EA05C(rdram, ctx);
        goto after_3;
    // 0x80115164: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    after_3:
    // 0x80115168: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8011516C: addiu       $v1, $a0, 0x4A58
    ctx->r3 = ADD32(ctx->r4, 0X4A58);
    // 0x80115170: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x80115174: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80115178: addiu       $t9, $t9, 0x4A58
    ctx->r25 = ADD32(ctx->r25, 0X4A58);
    // 0x8011517C: beq         $t8, $zero, L_801151B0
    if (ctx->r24 == 0) {
        // 0x80115180: sll         $a1, $v0, 16
        ctx->r5 = S32(ctx->r2 << 16);
            goto L_801151B0;
    }
    // 0x80115180: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x80115184: sra         $t0, $a1, 16
    ctx->r8 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80115188: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x8011518C: lh          $a0, 0x0($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X0);
L_80115190:
    // 0x80115190: bnel        $a1, $a0, L_801151A4
    if (ctx->r5 != ctx->r4) {
        // 0x80115194: lh          $a0, 0x2($v1)
        ctx->r4 = MEM_H(ctx->r3, 0X2);
            goto L_801151A4;
    }
    goto skip_0;
    // 0x80115194: lh          $a0, 0x2($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2);
    skip_0:
    // 0x80115198: b           L_801151B0
    // 0x8011519C: sb          $zero, 0xE($s0)
    MEM_B(0XE, ctx->r16) = 0;
        goto L_801151B0;
    // 0x8011519C: sb          $zero, 0xE($s0)
    MEM_B(0XE, ctx->r16) = 0;
    // 0x801151A0: lh          $a0, 0x2($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2);
L_801151A4:
    // 0x801151A4: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x801151A8: bne         $a0, $zero, L_80115190
    if (ctx->r4 != 0) {
        // 0x801151AC: nop
    
            goto L_80115190;
    }
    // 0x801151AC: nop

L_801151B0:
    // 0x801151B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801151B4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x801151B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801151BC: jr          $ra
    // 0x801151C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801151C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80800578_chtiptup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800578: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080057C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800580: addiu       $at, $zero, 0xFFA
    ctx->r1 = ADD32(0, 0XFFA);
    // 0x80800584: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800588: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080058C: bne         $a1, $at, L_808005CC
    if (ctx->r5 != ctx->r1) {
        // 0x80800590: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_808005CC;
    }
    // 0x80800590: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800594: jal         0x800F54E4
    // 0x80800598: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800598: nop

    after_0:
    // 0x8080059C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808005A0: jal         0x800F82D4
    // 0x808005A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_1;
    // 0x808005A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808005A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005AC: jal         0x80102424
    // 0x808005B0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x808005B0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x808005B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005B8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808005BC: jal         0x808008B4
    // 0x808005C0: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_808008B4_chtiptup(rdram, ctx);
        goto after_3;
    // 0x808005C0: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_3:
    // 0x808005C4: b           L_80800604
    // 0x808005C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800604;
    // 0x808005C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808005CC:
    // 0x808005CC: lw          $t6, 0x2C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2C);
    // 0x808005D0: beq         $t6, $zero, L_808005E0
    if (ctx->r14 == 0) {
        // 0x808005D4: nop
    
            goto L_808005E0;
    }
    // 0x808005D4: nop

    // 0x808005D8: jal         0x808007CC
    // 0x808005DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808007CC_chtiptup(rdram, ctx);
        goto after_4;
    // 0x808005DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_808005E0:
    // 0x808005E0: jal         0x800DA298
    // 0x808005E4: addiu       $a0, $zero, 0xBE
    ctx->r4 = ADD32(0, 0XBE);
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x808005E4: addiu       $a0, $zero, 0xBE
    ctx->r4 = ADD32(0, 0XBE);
    after_5:
    // 0x808005E8: beq         $v0, $zero, L_808005F8
    if (ctx->r2 == 0) {
        // 0x808005EC: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_808005F8;
    }
    // 0x808005EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808005F0: b           L_808005F8
    // 0x808005F4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
        goto L_808005F8;
    // 0x808005F4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_808005F8:
    // 0x808005F8: jal         0x80102424
    // 0x808005FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x808005FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800600: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800604:
    // 0x80800604: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800608: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080060C: jr          $ra
    // 0x80800610: nop

    return;
    // 0x80800610: nop

;}
RECOMP_FUNC void chegggrenade_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000FC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800100: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800104: jal         0x80106790
    // 0x80800108: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800108: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080010C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800110: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800114: jal         0x80100094
    // 0x80800118: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800118: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8080011C: lh          $t6, 0x3A($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X3A);
    // 0x80800120: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80800124: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80800128: lw          $a0, 0x24($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X24);
    // 0x8080012C: srl         $t8, $a0, 22
    ctx->r24 = S32(U32(ctx->r4) >> 22);
    // 0x80800130: jal         0x800883B8
    // 0x80800134: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    _gcegg_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80800134: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_2:
    // 0x80800138: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8080013C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800140: jal         0x80087340
    // 0x80800144: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    _cheggsplode_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80800144: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_3:
    // 0x80800148: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080014C: jal         0x8008A398
    // 0x80800150: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _suegg_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x80800150: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800158: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080015C: jr          $ra
    // 0x80800160: nop

    return;
    // 0x80800160: nop

;}
RECOMP_FUNC void func_808016D4_chalienkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808016D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808016D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808016DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808016E0: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x808016E4: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x808016E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808016EC: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808016F0: beq         $t6, $at, L_80801718
    if (ctx->r14 == ctx->r1) {
        // 0x808016F4: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_80801718;
    }
    // 0x808016F4: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x808016F8: beq         $t6, $at, L_80801738
    if (ctx->r14 == ctx->r1) {
        // 0x808016FC: addiu       $at, $zero, 0x14
        ctx->r1 = ADD32(0, 0X14);
            goto L_80801738;
    }
    // 0x808016FC: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80801700: beq         $t6, $at, L_80801774
    if (ctx->r14 == ctx->r1) {
        // 0x80801704: addiu       $at, $zero, 0x15
        ctx->r1 = ADD32(0, 0X15);
            goto L_80801774;
    }
    // 0x80801704: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x80801708: beq         $t6, $at, L_808017B4
    if (ctx->r14 == ctx->r1) {
        // 0x8080170C: nop
    
            goto L_808017B4;
    }
    // 0x8080170C: nop

    // 0x80801710: b           L_8080183C
    // 0x80801714: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080183C;
    // 0x80801714: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801718:
    // 0x80801718: jal         0x800D9078
    // 0x8080171C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x8080171C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_0:
    // 0x80801720: beq         $v0, $zero, L_80801838
    if (ctx->r2 == 0) {
        // 0x80801724: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801838;
    }
    // 0x80801724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801728: jal         0x80102424
    // 0x8080172C: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x8080172C: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_1:
    // 0x80801730: b           L_8080183C
    // 0x80801734: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080183C;
    // 0x80801734: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801738:
    // 0x80801738: jal         0x80101DDC
    // 0x8080173C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_2;
    // 0x8080173C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801740: beq         $v0, $zero, L_80801838
    if (ctx->r2 == 0) {
        // 0x80801744: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801838;
    }
    // 0x80801744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801748: jal         0x80102424
    // 0x8080174C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x8080174C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_3:
    // 0x80801750: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
    // 0x80801754: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1324, 0XD68) << 16);
    // 0x80801758: sll         $t8, $t7, 11
    ctx->r24 = S32(ctx->r15 << 11);
    // 0x8080175C: srl         $t9, $t8, 20
    ctx->r25 = S32(U32(ctx->r24) >> 20);
    // 0x80801760: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80801764: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80801768: lwc1        $f4, 0xD68($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1324, 0XD68));
    // 0x8080176C: b           L_80801838
    // 0x80801770: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_80801838;
    // 0x80801770: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_80801774:
    // 0x80801774: jal         0x800D9078
    // 0x80801778: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_4;
    // 0x80801778: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_4:
    // 0x8080177C: beq         $v0, $zero, L_80801838
    if (ctx->r2 == 0) {
        // 0x80801780: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801838;
    }
    // 0x80801780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801784: jal         0x80102424
    // 0x80801788: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    func_80102424(rdram, ctx);
        goto after_5;
    // 0x80801788: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_5:
    // 0x8080178C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80801790: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801794: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80801798: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080179C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808017A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808017A4: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
    // 0x808017A8: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    // 0x808017AC: b           L_80801838
    // 0x808017B0: swc1        $f10, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f10.u32l;
        goto L_80801838;
    // 0x808017B0: swc1        $f10, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f10.u32l;
L_808017B4:
    // 0x808017B4: jal         0x800D9078
    // 0x808017B8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_6;
    // 0x808017B8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_6:
    // 0x808017BC: jal         0x800D8FF8
    // 0x808017C0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_7;
    // 0x808017C0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_7:
    // 0x808017C4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808017C8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808017CC: lwc1        $f16, 0x34($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X34);
    // 0x808017D0: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x808017D4: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x808017D8: jal         0x800D8FF8
    // 0x808017DC: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_8;
    // 0x808017DC: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
    after_8:
    // 0x808017E0: lwc1        $f8, 0x34($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X34);
    // 0x808017E4: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808017E8: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x808017EC: mul.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x808017F0: add.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x808017F4: jal         0x800D9078
    // 0x808017F8: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    func_800D9078(rdram, ctx);
        goto after_9;
    // 0x808017F8: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    after_9:
    // 0x808017FC: beq         $v0, $zero, L_80801814
    if (ctx->r2 == 0) {
        // 0x80801800: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801814;
    }
    // 0x80801800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801804: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1324, 0X2260) << 16);
    // 0x80801808: addiu       $a2, $a2, 0x2260
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1324, 0X2260));
    // 0x8080180C: jal         0x80089D18
    // 0x80801810: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_10;
    // 0x80801810: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_10:
L_80801814:
    // 0x80801814: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80801818: addiu       $a1, $zero, 0x4F
    ctx->r5 = ADD32(0, 0X4F);
    // 0x8080181C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801820: beql        $t1, $zero, L_8080183C
    if (ctx->r9 == 0) {
        // 0x80801824: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080183C;
    }
    goto skip_0;
    // 0x80801824: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80801828: jal         0x8010114C
    // 0x8080182C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_8010114C(rdram, ctx);
        goto after_11;
    // 0x8080182C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_11:
    // 0x80801830: jal         0x800FFAB0
    // 0x80801834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_12;
    // 0x80801834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
L_80801838:
    // 0x80801838: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080183C:
    // 0x8080183C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801840: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801844: jr          $ra
    // 0x80801848: nop

    return;
    // 0x80801848: nop

;}
RECOMP_FUNC void func_80104780(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104780: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80104784: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80104788: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010478C: jal         0x801043D8
    // 0x80104790: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_801043D8(rdram, ctx);
        goto after_0;
    // 0x80104790: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80104794: lw          $t6, 0x78($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X78);
    // 0x80104798: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8010479C: sll         $t8, $t6, 30
    ctx->r24 = S32(ctx->r14 << 30);
    // 0x801047A0: bgezl       $t8, L_8010485C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801047A4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8010485C;
    }
    goto skip_0;
    // 0x801047A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x801047A8: lw          $t9, 0x74($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X74);
    // 0x801047AC: sll         $t1, $t9, 26
    ctx->r9 = S32(ctx->r25 << 26);
    // 0x801047B0: bltzl       $t1, L_8010485C
    if (SIGNED(ctx->r9) < 0) {
        // 0x801047B4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8010485C;
    }
    goto skip_1;
    // 0x801047B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x801047B8: lbu         $t2, 0x3($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X3);
    // 0x801047BC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x801047C0: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x801047C4: beql        $t2, $zero, L_8010485C
    if (ctx->r10 == 0) {
        // 0x801047C8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8010485C;
    }
    goto skip_2;
    // 0x801047C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x801047CC: jal         0x801049B4
    // 0x801047D0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    func_801049B4(rdram, ctx);
        goto after_1;
    // 0x801047D0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_1:
    // 0x801047D4: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x801047D8: jal         0x80104D80
    // 0x801047DC: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    func_80104D80(rdram, ctx);
        goto after_2;
    // 0x801047DC: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_2:
    // 0x801047E0: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x801047E4: jal         0x80104E24
    // 0x801047E8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_80104E24(rdram, ctx);
        goto after_3;
    // 0x801047E8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x801047EC: lw          $t3, 0x70($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X70);
    // 0x801047F0: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x801047F4: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x801047F8: sll         $t5, $t3, 29
    ctx->r13 = S32(ctx->r11 << 29);
    // 0x801047FC: bgezl       $t5, L_80104824
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80104800: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_80104824;
    }
    goto skip_3;
    // 0x80104800: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    skip_3:
    // 0x80104804: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x80104808: lui         $at, 0x420
    ctx->r1 = S32(0X420 << 16);
    // 0x8010480C: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80104810: bnel        $t8, $zero, L_80104824
    if (ctx->r24 != 0) {
        // 0x80104814: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_80104824;
    }
    goto skip_4;
    // 0x80104814: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    skip_4:
    // 0x80104818: jal         0x80105390
    // 0x8010481C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_80105390(rdram, ctx);
        goto after_4;
    // 0x8010481C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_4:
    // 0x80104820: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80104824:
    // 0x80104824: addiu       $v1, $sp, 0x2C
    ctx->r3 = ADD32(ctx->r29, 0X2C);
    // 0x80104828: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x8010482C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
L_80104830:
    // 0x80104830: lbu         $t0, 0x98($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X98);
    // 0x80104834: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80104838: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8010483C: multu       $t0, $a0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80104840: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80104844: mflo        $t1
    ctx->r9 = lo;
    // 0x80104848: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8010484C: sra         $t3, $t2, 2
    ctx->r11 = S32(SIGNED(ctx->r10) >> 2);
    // 0x80104850: bne         $v1, $a1, L_80104830
    if (ctx->r3 != ctx->r5) {
        // 0x80104854: sb          $t3, 0x97($v0)
        MEM_B(0X97, ctx->r2) = ctx->r11;
            goto L_80104830;
    }
    // 0x80104854: sb          $t3, 0x97($v0)
    MEM_B(0X97, ctx->r2) = ctx->r11;
    // 0x80104858: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8010485C:
    // 0x8010485C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80104860: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80104864: jr          $ra
    // 0x80104868: nop

    return;
    // 0x80104868: nop

;}
RECOMP_FUNC void func_808008F4_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808008F8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808008FC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800900: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800904: jal         0x808001A8
    // 0x80800908: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    func_808001A8_bswasher(rdram, ctx);
        goto after_0;
    // 0x80800908: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x8080090C: jal         0x8008CABC
    // 0x80800910: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_1;
    // 0x80800910: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80800914: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800918: jal         0x8008AF24
    // 0x8080091C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_2;
    // 0x8080091C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800920: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800924: jal         0x8008AED4
    // 0x80800928: addiu       $a1, $zero, 0x355
    ctx->r5 = ADD32(0, 0X355);
    anctrl_setIndex(rdram, ctx);
        goto after_3;
    // 0x80800928: addiu       $a1, $zero, 0x355
    ctx->r5 = ADD32(0, 0X355);
    after_3:
    // 0x8080092C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80800930: ori         $a1, $a1, 0xEBEE
    ctx->r5 = ctx->r5 | 0XEBEE;
    // 0x80800934: jal         0x8008B24C
    // 0x80800938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setStart(rdram, ctx);
        goto after_4;
    // 0x80800938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080093C: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x80800940: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80800944: jal         0x8008B1BC
    // 0x80800948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_5;
    // 0x80800948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080094C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800950: jal         0x8008B134
    // 0x80800954: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_6;
    // 0x80800954: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x80800958: jal         0x8008B064
    // 0x8080095C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_7;
    // 0x8080095C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800960: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80800964: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800968: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080096C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800970: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800974: jal         0x8009FFD8
    // 0x80800978: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_8;
    // 0x80800978: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_8:
    // 0x8080097C: jal         0x808000BC
    // 0x80800980: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_808000BC_bswasher(rdram, ctx);
        goto after_9;
    // 0x80800980: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x80800984: sw          $zero, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = 0;
    // 0x80800988: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080098C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800990: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800994: jr          $ra
    // 0x80800998: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800998: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_808003F4_bsstonehead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800400: jal         0x80097AD0
    // 0x80800404: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    bainput_should_enter_first_person(rdram, ctx);
        goto after_0;
    // 0x80800404: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800408: beq         $v0, $zero, L_8080041C
    if (ctx->r2 == 0) {
        // 0x8080040C: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_8080041C;
    }
    // 0x8080040C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800410: jal         0x800848A8
    // 0x80800414: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _badrone_entrypoint_24(rdram, ctx);
        goto after_1;
    // 0x80800414: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800418: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8080041C:
    // 0x8080041C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800420: jal         0x8009EF10
    // 0x80800424: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    bastick_getZone(rdram, ctx);
        goto after_2;
    // 0x80800424: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80800428: blez        $v0, L_80800434
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8080042C: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80800434;
    }
    // 0x8080042C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800430: addiu       $v1, $zero, 0xB2
    ctx->r3 = ADD32(0, 0XB2);
L_80800434:
    // 0x80800434: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800438: jal         0x808003B8
    // 0x8080043C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_808003B8_bsstonehead(rdram, ctx);
        goto after_3;
    // 0x8080043C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_3:
    // 0x80800440: beq         $v0, $zero, L_8080044C
    if (ctx->r2 == 0) {
        // 0x80800444: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_8080044C;
    }
    // 0x80800444: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800448: addiu       $v1, $zero, 0xAE
    ctx->r3 = ADD32(0, 0XAE);
L_8080044C:
    // 0x8080044C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800450: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800454: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800458: jr          $ra
    // 0x8080045C: nop

    return;
    // 0x8080045C: nop

;}
RECOMP_FUNC void func_801084B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801084B0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801084B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801084B8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x801084BC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801084C0: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x801084C4: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x801084C8: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801084CC: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x801084D0: jal         0x800EE904
    // 0x801084D4: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    func_800EE904(rdram, ctx);
        goto after_0;
    // 0x801084D4: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    after_0:
    // 0x801084D8: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x801084DC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x801084E0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x801084E4: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801084E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801084EC: lwc1        $f4, 0x48($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X48);
    // 0x801084F0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801084F4: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x801084F8: jal         0x80108C90
    // 0x801084FC: nop

    func_80108C90(rdram, ctx);
        goto after_1;
    // 0x801084FC: nop

    after_1:
    // 0x80108500: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80108504: jal         0x80106790
    // 0x80108508: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80106790(rdram, ctx);
        goto after_2;
    // 0x80108508: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8010850C: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80108510: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    // 0x80108514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80108518: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8010851C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80108520: jr          $ra
    // 0x80108524: nop

    return;
    // 0x80108524: nop

;}
RECOMP_FUNC void func_80802320_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802320: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80802324: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802328: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8080232C: lhu         $a1, 0x72($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X72);
    // 0x80802330: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80802334: srl         $t7, $a1, 10
    ctx->r15 = S32(U32(ctx->r5) >> 10);
    // 0x80802338: beq         $t7, $at, L_808023C8
    if (ctx->r15 == ctx->r1) {
        // 0x8080233C: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_808023C8;
    }
    // 0x8080233C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80802340: bnel        $t7, $at, L_80802438
    if (ctx->r15 != ctx->r1) {
        // 0x80802344: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802438;
    }
    goto skip_0;
    // 0x80802344: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80802348: jal         0x800DC090
    // 0x8080234C: nop

    func_800DC090(rdram, ctx);
        goto after_0;
    // 0x8080234C: nop

    after_0:
    // 0x80802350: andi        $t8, $v0, 0x3
    ctx->r24 = ctx->r2 & 0X3;
    // 0x80802354: bne         $t8, $zero, L_80802434
    if (ctx->r24 != 0) {
        // 0x80802358: lw          $t9, 0x38($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X38);
            goto L_80802434;
    }
    // 0x80802358: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8080235C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x80802360: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80802364: jal         0x8008A0E0
    // 0x80802368: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80802368: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_1:
    // 0x8080236C: beq         $v0, $zero, L_80802434
    if (ctx->r2 == 0) {
        // 0x80802370: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80802434;
    }
    // 0x80802370: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80802374: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2204, 0X287C) << 16);
    // 0x80802378: addiu       $t0, $t0, 0x287C
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(2204, 0X287C));
    // 0x8080237C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80802380: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80802384: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80802388: jal         0x800BABB8
    // 0x8080238C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x8080238C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x80802390: jal         0x8001211C
    // 0x80802394: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_8001211C(rdram, ctx);
        goto after_3;
    // 0x80802394: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_3:
    // 0x80802398: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x8080239C: beq         $t1, $zero, L_808023AC
    if (ctx->r9 == 0) {
        // 0x808023A0: addiu       $a1, $zero, 0x9E2
        ctx->r5 = ADD32(0, 0X9E2);
            goto L_808023AC;
    }
    // 0x808023A0: addiu       $a1, $zero, 0x9E2
    ctx->r5 = ADD32(0, 0X9E2);
    // 0x808023A4: b           L_808023AC
    // 0x808023A8: addiu       $a1, $zero, 0x9E3
    ctx->r5 = ADD32(0, 0X9E3);
        goto L_808023AC;
    // 0x808023A8: addiu       $a1, $zero, 0x9E3
    ctx->r5 = ADD32(0, 0X9E3);
L_808023AC:
    // 0x808023AC: jal         0x800BA3FC
    // 0x808023B0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800BA3FC(rdram, ctx);
        goto after_4;
    // 0x808023B0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x808023B4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808023B8: jal         0x800BA22C
    // 0x808023BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_5;
    // 0x808023BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808023C0: b           L_80802438
    // 0x808023C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802438;
    // 0x808023C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808023C8:
    // 0x808023C8: jal         0x800DC090
    // 0x808023CC: nop

    func_800DC090(rdram, ctx);
        goto after_6;
    // 0x808023CC: nop

    after_6:
    // 0x808023D0: andi        $t2, $v0, 0xF
    ctx->r10 = ctx->r2 & 0XF;
    // 0x808023D4: sltiu       $at, $t2, 0x3
    ctx->r1 = ctx->r10 < 0X3 ? 1 : 0;
    // 0x808023D8: beq         $at, $zero, L_80802434
    if (ctx->r1 == 0) {
        // 0x808023DC: lw          $t3, 0x38($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X38);
            goto L_80802434;
    }
    // 0x808023DC: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x808023E0: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x808023E4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808023E8: jal         0x8008A0E0
    // 0x808023EC: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_7;
    // 0x808023EC: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_7:
    // 0x808023F0: beq         $v0, $zero, L_80802434
    if (ctx->r2 == 0) {
        // 0x808023F4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80802434;
    }
    // 0x808023F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808023F8: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(2204, 0X28C4) << 16);
    // 0x808023FC: addiu       $t4, $t4, 0x28C4
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(2204, 0X28C4));
    // 0x80802400: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80802404: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80802408: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080240C: jal         0x800BABB8
    // 0x80802410: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_8;
    // 0x80802410: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_8:
    // 0x80802414: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80802418: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080241C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802420: jal         0x800BA4B0
    // 0x80802424: lbu         $a1, 0x9B($t5)
    ctx->r5 = MEM_BU(ctx->r13, 0X9B);
    func_800BA4B0(rdram, ctx);
        goto after_9;
    // 0x80802424: lbu         $a1, 0x9B($t5)
    ctx->r5 = MEM_BU(ctx->r13, 0X9B);
    after_9:
    // 0x80802428: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080242C: jal         0x800BA22C
    // 0x80802430: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_10;
    // 0x80802430: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
L_80802434:
    // 0x80802434: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802438:
    // 0x80802438: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8080243C: jr          $ra
    // 0x80802440: nop

    return;
    // 0x80802440: nop

;}
RECOMP_FUNC void func_80019D78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019D78: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80019D7C: sw          $ra, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r31;
    // 0x80019D80: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80019D84: sw          $a0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r4;
    // 0x80019D88: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80019D8C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80019D90: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80019D94: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80019D98: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80019D9C: jal         0x800137AC
    // 0x80019DA0: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    func_800137AC(rdram, ctx);
        goto after_0;
    // 0x80019DA0: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    after_0:
    // 0x80019DA4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80019DA8: mov.s       $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    ctx->f22.fl = ctx->f2.fl;
    // 0x80019DAC: jal         0x800137AC
    // 0x80019DB0: lwc1        $f12, 0x8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X8);
    func_800137AC(rdram, ctx);
        goto after_1;
    // 0x80019DB0: lwc1        $f12, 0x8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X8);
    after_1:
    // 0x80019DB4: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x80019DB8: mov.s       $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    ctx->f26.fl = ctx->f2.fl;
    // 0x80019DBC: jal         0x800137AC
    // 0x80019DC0: lwc1        $f12, 0xC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC);
    func_800137AC(rdram, ctx);
        goto after_2;
    // 0x80019DC0: lwc1        $f12, 0xC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC);
    after_2:
    // 0x80019DC4: mul.s       $f4, $f20, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80019DC8: lw          $ra, 0x0($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X0);
    // 0x80019DCC: mul.s       $f6, $f20, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80019DD0: lw          $a0, 0x4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4);
    // 0x80019DD4: mul.s       $f12, $f24, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x80019DD8: neg.s       $f16, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f16.fl = -ctx->f26.fl;
    // 0x80019DDC: mul.s       $f10, $f22, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x80019DE0: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x80019DE4: mul.s       $f14, $f24, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f24.fl, ctx->f2.fl);
    // 0x80019DE8: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
    // 0x80019DEC: mul.s       $f18, $f10, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f26.fl);
    // 0x80019DF0: swc1        $f14, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f14.u32l;
    // 0x80019DF4: mul.s       $f8, $f22, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x80019DF8: sub.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80019DFC: mul.s       $f12, $f8, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x80019E00: swc1        $f18, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f18.u32l;
    // 0x80019E04: mul.s       $f14, $f22, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f14.fl = MUL_S(ctx->f22.fl, ctx->f24.fl);
    // 0x80019E08: add.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x80019E0C: mul.s       $f16, $f6, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f26.fl);
    // 0x80019E10: swc1        $f12, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f12.u32l;
    // 0x80019E14: mul.s       $f18, $f4, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x80019E18: swc1        $f14, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f14.u32l;
    // 0x80019E1C: mul.s       $f12, $f20, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = MUL_S(ctx->f20.fl, ctx->f24.fl);
    // 0x80019E20: add.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x80019E24: swc1        $f16, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f16.u32l;
    // 0x80019E28: sub.s       $f18, $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x80019E2C: swc1        $f18, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f18.u32l;
    // 0x80019E30: swc1        $f12, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f12.u32l;
    // 0x80019E34: sw          $zero, 0x38($a0)
    MEM_W(0X38, ctx->r4) = 0;
    // 0x80019E38: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x80019E3C: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x80019E40: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // 0x80019E44: sw          $zero, 0x30($a0)
    MEM_W(0X30, ctx->r4) = 0;
    // 0x80019E48: sw          $zero, 0x34($a0)
    MEM_W(0X34, ctx->r4) = 0;
    // 0x80019E4C: sw          $zero, 0x38($a0)
    MEM_W(0X38, ctx->r4) = 0;
    // 0x80019E50: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80019E54: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80019E58: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80019E5C: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x80019E60: lui         $t0, 0x3F80
    ctx->r8 = S32(0X3F80 << 16);
    // 0x80019E64: jr          $ra
    // 0x80019E68: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80019E68: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80800D5C_chbilldrillplate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D64: jal         0x80800FCC
    // 0x80800D68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800FCC_chbilldrillplate(rdram, ctx);
        goto after_0;
    // 0x80800D68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800D6C: jal         0x800DA298
    // 0x80800D70: lhu         $a0, 0xC($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0XC);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800D70: lhu         $a0, 0xC($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0XC);
    after_1:
    // 0x80800D74: beq         $v0, $zero, L_80800D8C
    if (ctx->r2 == 0) {
        // 0x80800D78: nop
    
            goto L_80800D8C;
    }
    // 0x80800D78: nop

    // 0x80800D7C: jal         0x800FFAB0
    // 0x80800D80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x80800D80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800D84: b           L_80800D98
    // 0x80800D88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800D98;
    // 0x80800D88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800D8C:
    // 0x80800D8C: jal         0x80089D00
    // 0x80800D90: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _subaddiefade_entrypoint_14(rdram, ctx);
        goto after_3;
    // 0x80800D90: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80800D94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800D98:
    // 0x80800D98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D9C: jr          $ra
    // 0x80800DA0: nop

    return;
    // 0x80800DA0: nop

;}
RECOMP_FUNC void _chheggy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087790: syscall     622
    recomp_syscall_handler(rdram, ctx, 0x80087790);
    return;
    // 0x80087794: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800000_chtransparentfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: lw          $v0, 0x70($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X70);
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800014: sll         $a1, $v0, 22
    ctx->r5 = S32(ctx->r2 << 22);
    // 0x80800018: srl         $t6, $a1, 26
    ctx->r14 = S32(U32(ctx->r5) >> 26);
    // 0x8080001C: srl         $a0, $v0, 25
    ctx->r4 = S32(U32(ctx->r2) >> 25);
    // 0x80800020: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80800024: jal         0x800CC63C
    // 0x80800028: addiu       $a1, $t6, -0x1
    ctx->r5 = ADD32(ctx->r14, -0X1);
    func_800CC63C(rdram, ctx);
        goto after_0;
    // 0x80800028: addiu       $a1, $t6, -0x1
    ctx->r5 = ADD32(ctx->r14, -0X1);
    after_0:
    // 0x8080002C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800030: lh          $t7, 0xE($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XE);
    // 0x80800034: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80800038: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8080003C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80800040: lui         $a1, 0x43B1
    ctx->r5 = S32(0X43B1 << 16);
    // 0x80800044: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80800048: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080004C: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x80800050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800054: add.s       $f6, $f2, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x80800058: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x8080005C: nop

    // 0x80800060: bc1fl       L_8080007C
    if (!c1cs) {
        // 0x80800064: sub.s       $f8, $f2, $f12
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f12.fl;
            goto L_8080007C;
    }
    goto skip_0;
    // 0x80800064: sub.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f12.fl;
    skip_0:
    // 0x80800068: jal         0x80102950
    // 0x8080006C: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    func_80102950(rdram, ctx);
        goto after_1;
    // 0x8080006C: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    after_1:
    // 0x80800070: b           L_808000B0
    // 0x80800074: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
        goto L_808000B0;
    // 0x80800074: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800078: sub.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f12.fl;
L_8080007C:
    // 0x8080007C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800084: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    // 0x80800088: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x8080008C: nop

    // 0x80800090: bc1fl       L_808000AC
    if (!c1cs) {
        // 0x80800094: sw          $zero, 0x28($sp)
        MEM_W(0X28, ctx->r29) = 0;
            goto L_808000AC;
    }
    goto skip_1;
    // 0x80800094: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    skip_1:
    // 0x80800098: jal         0x80102950
    // 0x8080009C: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    func_80102950(rdram, ctx);
        goto after_2;
    // 0x8080009C: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    after_2:
    // 0x808000A0: b           L_808000B0
    // 0x808000A4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
        goto L_808000B0;
    // 0x808000A4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x808000A8: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
L_808000AC:
    // 0x808000AC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
L_808000B0:
    // 0x808000B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808000B4: lwc1        $f18, 0x38($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808000B8: lwc1        $f10, 0x54($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X54);
    // 0x808000BC: lwc1        $f8, 0x24($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808000C0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x808000C4: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x808000C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000CC: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x808000D0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x808000D4: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x808000D8: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x808000DC: jal         0x8008A4E8
    // 0x808000E0: nop

    _subaddieDll_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x808000E0: nop

    after_3:
    // 0x808000E4: bne         $v0, $zero, L_80800120
    if (ctx->r2 != 0) {
        // 0x808000E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800120;
    }
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000EC: jal         0x80102D78
    // 0x808000F0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80102D78(rdram, ctx);
        goto after_4;
    // 0x808000F0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x808000F4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808000F8: jal         0x80102924
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102924(rdram, ctx);
        goto after_5;
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800100: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800104: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800108: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8080010C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800110: jal         0x800DC178
    // 0x80800114: nop

    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x80800114: nop

    after_6:
    // 0x80800118: b           L_808001F0
    // 0x8080011C: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
        goto L_808001F0;
    // 0x8080011C: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_80800120:
    // 0x80800120: jal         0x800D8FF8
    // 0x80800124: nop

    func_800D8FF8(rdram, ctx);
        goto after_7;
    // 0x80800124: nop

    after_7:
    // 0x80800128: lwc1        $f18, 0x58($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8080012C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800130: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800134: sub.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x80800138: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    // 0x8080013C: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800140: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x80800144: nop

    // 0x80800148: bc1fl       L_808001F4
    if (!c1cs) {
        // 0x8080014C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808001F4;
    }
    goto skip_2;
    // 0x8080014C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80800150: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800154: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800158: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080015C: jal         0x800DC178
    // 0x80800160: nop

    func_800DC178(rdram, ctx);
        goto after_8;
    // 0x80800160: nop

    after_8:
    // 0x80800164: lui         $at, 0x42D2
    ctx->r1 = S32(0X42D2 << 16);
    // 0x80800168: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080016C: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80800170: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800174: jal         0x800DC178
    // 0x80800178: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_9;
    // 0x80800178: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    after_9:
    // 0x8080017C: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x80800180: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80800184: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2232, 0XF60) << 16);
    // 0x80800188: bnel        $t2, $zero, L_808001B0
    if (ctx->r10 != 0) {
        // 0x8080018C: lui         $at, 0xC20C
        ctx->r1 = S32(0XC20C << 16);
            goto L_808001B0;
    }
    goto skip_3;
    // 0x8080018C: lui         $at, 0xC20C
    ctx->r1 = S32(0XC20C << 16);
    skip_3:
    // 0x80800190: lwc1        $f12, 0xF60($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2232, 0XF60));
    // 0x80800194: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2232, 0XF64) << 16);
    // 0x80800198: jal         0x800DC178
    // 0x8080019C: lwc1        $f14, 0xF64($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2232, 0XF64));
    func_800DC178(rdram, ctx);
        goto after_10;
    // 0x8080019C: lwc1        $f14, 0xF64($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2232, 0XF64));
    after_10:
    // 0x808001A0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808001A4: jal         0x80102950
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102950(rdram, ctx);
        goto after_11;
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808001AC: lui         $at, 0xC20C
    ctx->r1 = S32(0XC20C << 16);
L_808001B0:
    // 0x808001B0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808001B4: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x808001B8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808001BC: jal         0x800DC178
    // 0x808001C0: nop

    func_800DC178(rdram, ctx);
        goto after_12;
    // 0x808001C0: nop

    after_12:
    // 0x808001C4: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x808001C8: jal         0x80102CCC
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102CCC(rdram, ctx);
        goto after_13;
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808001D0: beq         $v0, $zero, L_808001F0
    if (ctx->r2 == 0) {
        // 0x808001D4: lwc1        $f16, 0x2C($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
            goto L_808001F0;
    }
    // 0x808001D4: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808001D8: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x808001E4: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x808001E8: jal         0x80102924
    // 0x808001EC: nop

    func_80102924(rdram, ctx);
        goto after_14;
    // 0x808001EC: nop

    after_14:
L_808001F0:
    // 0x808001F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001F4:
    // 0x808001F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001F8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808001FC: jr          $ra
    // 0x80800200: nop

    return;
    // 0x80800200: nop

;}
RECOMP_FUNC void chmermaidstatue_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1144, 0X354) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x354
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1144, 0X354));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x354
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1144, 0X354));
;}
RECOMP_FUNC void func_80800160_ncpoducam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800160: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800164: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800168: lh          $a1, 0x0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X0);
    // 0x8080016C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800170: beq         $a1, $zero, L_80800190
    if (ctx->r5 == 0) {
        // 0x80800174: sll         $a0, $a1, 16
        ctx->r4 = S32(ctx->r5 << 16);
            goto L_80800190;
    }
    // 0x80800174: sll         $a0, $a1, 16
    ctx->r4 = S32(ctx->r5 << 16);
    // 0x80800178: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8080017C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80800180: jal         0x8001B754
    // 0x80800184: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_8001B754(rdram, ctx);
        goto after_0;
    // 0x80800184: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800188: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8080018C: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
L_80800190:
    // 0x80800190: lh          $a0, 0x2($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2);
    // 0x80800194: beql        $a0, $zero, L_808001B0
    if (ctx->r4 == 0) {
        // 0x80800198: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808001B0;
    }
    goto skip_0;
    // 0x80800198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080019C: jal         0x8001B754
    // 0x808001A0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_8001B754(rdram, ctx);
        goto after_1;
    // 0x808001A0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x808001A4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808001A8: sh          $zero, 0x2($a2)
    MEM_H(0X2, ctx->r6) = 0;
    // 0x808001AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001B0:
    // 0x808001B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001B4: jr          $ra
    // 0x808001B8: nop

    return;
    // 0x808001B8: nop

;}
RECOMP_FUNC void func_808001CC_chcrusherboulder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001D4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808001D8: jal         0x80100094
    // 0x808001DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808001DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808001E0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808001E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001E8: jal         0x80089868
    // 0x808001EC: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    _sumumbofx_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x808001EC: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_1:
    // 0x808001F0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808001F4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808001F8: jal         0x80800100
    // 0x808001FC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_80800100_chcrusherboulder(rdram, ctx);
        goto after_2;
    // 0x808001FC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
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
RECOMP_FUNC void func_808007C8_chstonepillar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007C8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808007CC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808007D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808007D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808007D8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808007DC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808007E0: jal         0x80100094
    // 0x808007E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808007E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808007E8: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x808007EC: addiu       $s2, $sp, 0x28
    ctx->r18 = ADD32(ctx->r29, 0X28);
    // 0x808007F0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808007F4: sll         $t6, $a0, 11
    ctx->r14 = S32(ctx->r4 << 11);
    // 0x808007F8: srl         $a0, $t6, 20
    ctx->r4 = S32(U32(ctx->r14) >> 20);
    // 0x808007FC: jal         0x80089C30
    // 0x80800800: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800800: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x80800804: beq         $v0, $zero, L_80800858
    if (ctx->r2 == 0) {
        // 0x80800808: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800858;
    }
    // 0x80800808: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8080080C:
    // 0x8080080C: beql        $v0, $s0, L_80800840
    if (ctx->r2 == ctx->r16) {
        // 0x80800810: lw          $a0, 0x6C($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X6C);
            goto L_80800840;
    }
    goto skip_0;
    // 0x80800810: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    skip_0:
    // 0x80800814: jal         0x80100094
    // 0x80800818: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80800818: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8080081C: lh          $t9, 0x2C($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X2C);
    // 0x80800820: lh          $t8, 0x2C($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2C);
    // 0x80800824: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800828: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8080082C: bnel        $t8, $t0, L_80800840
    if (ctx->r24 != ctx->r8) {
        // 0x80800830: lw          $a0, 0x6C($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X6C);
            goto L_80800840;
    }
    goto skip_1;
    // 0x80800830: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    skip_1:
    // 0x80800834: jal         0x800EE7F8
    // 0x80800838: addiu       $a0, $s1, 0xC
    ctx->r4 = ADD32(ctx->r17, 0XC);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800838: addiu       $a0, $s1, 0xC
    ctx->r4 = ADD32(ctx->r17, 0XC);
    after_3:
    // 0x8080083C: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
L_80800840:
    // 0x80800840: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80800844: sll         $t1, $a0, 11
    ctx->r9 = S32(ctx->r4 << 11);
    // 0x80800848: jal         0x80089C38
    // 0x8080084C: srl         $a0, $t1, 20
    ctx->r4 = S32(U32(ctx->r9) >> 20);
    _subaddiefind_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x8080084C: srl         $a0, $t1, 20
    ctx->r4 = S32(U32(ctx->r9) >> 20);
    after_4:
    // 0x80800850: bne         $v0, $zero, L_8080080C
    if (ctx->r2 != 0) {
        // 0x80800854: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8080080C;
    }
    // 0x80800854: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80800858:
    // 0x80800858: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080085C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800860: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800864: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800868: jr          $ra
    // 0x8080086C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8080086C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_808024B0_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808024B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808024B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808024B8: jal         0x800A3280
    // 0x808024BC: nop

    func_800A3280(rdram, ctx);
        goto after_0;
    // 0x808024BC: nop

    after_0:
    // 0x808024C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808024C4: lui         $t7, 0x8081
    ctx->r15 = S32(RELOC_HI16(439, 0XAFFC) << 16);
    // 0x808024C8: addiu       $t7, $t7, -0x5004
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(439, 0XAFFC));
    // 0x808024CC: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x808024D0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x808024D4: jr          $ra
    // 0x808024D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x808024D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80803888_chintrochar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803888: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080388C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80803890: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80803894: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80803898: jal         0x80100094
    // 0x8080389C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080389C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x808038A0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808038A4: lhu         $t6, 0x76($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X76);
    // 0x808038A8: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1732, 0X4160) << 16);
    // 0x808038AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808038B0: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x808038B4: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x808038B8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x808038BC: lw          $t9, 0x4160($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(1732, 0X4160));
    // 0x808038C0: jal         0x80103D48
    // 0x808038C4: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    func_80103D48(rdram, ctx);
        goto after_1;
    // 0x808038C4: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    after_1:
    // 0x808038C8: jal         0x800859B8
    // 0x808038CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chanim_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x808038CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808038D0: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x808038D4: lh          $a0, 0xC2($t0)
    ctx->r4 = MEM_H(ctx->r8, 0XC2);
    // 0x808038D8: beql        $a0, $zero, L_808038EC
    if (ctx->r4 == 0) {
        // 0x808038DC: lw          $t1, 0x24($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X24);
            goto L_808038EC;
    }
    goto skip_0;
    // 0x808038DC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808038E0: jal         0x800857C8
    // 0x808038E4: nop

    _chblink_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x808038E4: nop

    after_3:
    // 0x808038E8: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
L_808038EC:
    // 0x808038EC: lh          $a0, 0xC4($t1)
    ctx->r4 = MEM_H(ctx->r9, 0XC4);
    // 0x808038F0: beq         $a0, $zero, L_80803900
    if (ctx->r4 == 0) {
        // 0x808038F4: nop
    
            goto L_80803900;
    }
    // 0x808038F4: nop

    // 0x808038F8: jal         0x800857C8
    // 0x808038FC: nop

    _chblink_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x808038FC: nop

    after_4:
L_80803900:
    // 0x80803900: jal         0x801015D0
    // 0x80803904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801015D0(rdram, ctx);
        goto after_5;
    // 0x80803904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80803908: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8080390C: lh          $a0, 0xC6($t2)
    ctx->r4 = MEM_H(ctx->r10, 0XC6);
    // 0x80803910: beql        $a0, $zero, L_80803930
    if (ctx->r4 == 0) {
        // 0x80803914: lw          $v0, 0x20($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X20);
            goto L_80803930;
    }
    goto skip_1;
    // 0x80803914: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    skip_1:
    // 0x80803918: jal         0x8001B798
    // 0x8080391C: nop

    func_8001B798(rdram, ctx);
        goto after_6;
    // 0x8080391C: nop

    after_6:
    // 0x80803920: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803924: jal         0x800897E0
    // 0x80803928: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _suexpression_entrypoint_11(rdram, ctx);
        goto after_7;
    // 0x80803928: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x8080392C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
L_80803930:
    // 0x80803930: andi        $t3, $v0, 0x10
    ctx->r11 = ctx->r2 & 0X10;
    // 0x80803934: beq         $t3, $zero, L_8080394C
    if (ctx->r11 == 0) {
        // 0x80803938: andi        $t4, $v0, 0x8
        ctx->r12 = ctx->r2 & 0X8;
            goto L_8080394C;
    }
    // 0x80803938: andi        $t4, $v0, 0x8
    ctx->r12 = ctx->r2 & 0X8;
    // 0x8080393C: jal         0x800DF830
    // 0x80803940: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800DF830(rdram, ctx);
        goto after_8;
    // 0x80803940: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_8:
    // 0x80803944: b           L_80803974
    // 0x80803948: nop

        goto L_80803974;
    // 0x80803948: nop

L_8080394C:
    // 0x8080394C: beq         $t4, $zero, L_80803964
    if (ctx->r12 == 0) {
        // 0x80803950: andi        $t5, $v0, 0x20
        ctx->r13 = ctx->r2 & 0X20;
            goto L_80803964;
    }
    // 0x80803950: andi        $t5, $v0, 0x20
    ctx->r13 = ctx->r2 & 0X20;
    // 0x80803954: jal         0x800DF830
    // 0x80803958: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DF830(rdram, ctx);
        goto after_9;
    // 0x80803958: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x8080395C: b           L_80803974
    // 0x80803960: nop

        goto L_80803974;
    // 0x80803960: nop

L_80803964:
    // 0x80803964: beq         $t5, $zero, L_80803974
    if (ctx->r13 == 0) {
        // 0x80803968: nop
    
            goto L_80803974;
    }
    // 0x80803968: nop

    // 0x8080396C: jal         0x800DF830
    // 0x80803970: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800DF830(rdram, ctx);
        goto after_10;
    // 0x80803970: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_10:
L_80803974:
    // 0x80803974: jal         0x80103D70
    // 0x80803978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103D70(rdram, ctx);
        goto after_11;
    // 0x80803978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8080397C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80803980: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80803984: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80803988: jr          $ra
    // 0x8080398C: nop

    return;
    // 0x8080398C: nop

;}
RECOMP_FUNC void func_800C8FB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8FB0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C8FB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C8FB8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800C8FBC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C8FC0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C8FC4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800C8FC8: jal         0x800C8E84
    // 0x800C8FCC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800C8E84(rdram, ctx);
        goto after_0;
    // 0x800C8FCC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x800C8FD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C8FD4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C8FD8: jr          $ra
    // 0x800C8FDC: nop

    return;
    // 0x800C8FDC: nop

;}
RECOMP_FUNC void func_8008B5E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B5E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008B5EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008B5F0: jal         0x8008C0D8
    // 0x8008B5F4: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    func_8008C0D8(rdram, ctx);
        goto after_0;
    // 0x8008B5F4: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_0:
    // 0x8008B5F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008B5FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008B600: jr          $ra
    // 0x8008B604: nop

    return;
    // 0x8008B604: nop

    // 0x8008B608: nop

    // 0x8008B60C: nop

;}
RECOMP_FUNC void func_80109F90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109F90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80109F94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80109F98: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80109F9C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80109FA0: jal         0x8010114C
    // 0x80109FA4: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    func_8010114C(rdram, ctx);
        goto after_0;
    // 0x80109FA4: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    after_0:
    // 0x80109FA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80109FAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80109FB0: jr          $ra
    // 0x80109FB4: nop

    return;
    // 0x80109FB4: nop

;}
RECOMP_FUNC void func_800BA544(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA544: jr          $ra
    // 0x800BA548: sw          $a1, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->r5;
    return;
    // 0x800BA548: sw          $a1, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void bstalk_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: jal         0x8008CABC
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800014: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800018: jal         0x8008AF24
    // 0x8080001C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x8080001C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800020: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800024: jal         0x800A0110
    // 0x80800028: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_800A0110(rdram, ctx);
        goto after_2;
    // 0x80800028: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_2:
    // 0x8080002C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800030: jal         0x8008B134
    // 0x80800034: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_3;
    // 0x80800034: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80800038: jal         0x8008B064
    // 0x8080003C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    anctrl_start(rdram, ctx);
        goto after_4;
    // 0x8080003C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_4:
    // 0x80800040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800044: jal         0x8009C128
    // 0x80800048: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_8009C128(rdram, ctx);
        goto after_5;
    // 0x80800048: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_5:
    // 0x8080004C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800050: jal         0x800A33A0
    // 0x80800054: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_800A33A0(rdram, ctx);
        goto after_6;
    // 0x80800054: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_6:
    // 0x80800058: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8080005C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80800060: jal         0x800F1E6C
    // 0x80800064: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    func_800F1E6C(rdram, ctx);
        goto after_7;
    // 0x80800064: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_7:
    // 0x80800068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080006C: jal         0x8009C914
    // 0x80800070: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    yaw_setIdeal(rdram, ctx);
        goto after_8;
    // 0x80800070: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_8:
    // 0x80800074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800078: jal         0x8008CA4C
    // 0x8080007C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008CA4C(rdram, ctx);
        goto after_9;
    // 0x8080007C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800084: jal         0x8009C908
    // 0x80800088: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    yaw_setUpdateType(rdram, ctx);
        goto after_10;
    // 0x80800088: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x8080008C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800090: jal         0x8009D2D8
    // 0x80800094: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8009D2D8(rdram, ctx);
        goto after_11;
    // 0x80800094: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_11:
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080009C: jal         0x8009B800
    // 0x808000A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    baphysics_set_type(rdram, ctx);
        goto after_12;
    // 0x808000A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_12:
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A8: jal         0x8009B9B0
    // 0x808000AC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_13;
    // 0x808000AC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_13:
    // 0x808000B0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808000B4: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
    // 0x808000B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000C0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808000C4: jr          $ra
    // 0x808000C8: nop

    return;
    // 0x808000C8: nop

;}
RECOMP_FUNC void _bababykaz_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800844A0: syscall     112
    recomp_syscall_handler(rdram, ctx, 0x800844A0);
    return;
    // 0x800844A4: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_8009EC88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EC88: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009EC8C: lbu         $v1, 0x7060($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7060);
    // 0x8009EC90: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8009EC94: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x8009EC98: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8009EC9C: blez        $v1, L_8009ECE4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8009ECA0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8009ECE4;
    }
    // 0x8009ECA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8009ECA4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009ECA8: addiu       $a1, $a1, 0x7040
    ctx->r5 = ADD32(ctx->r5, 0X7040);
L_8009ECAC:
    // 0x8009ECAC: lh          $t6, 0x10($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X10);
    // 0x8009ECB0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8009ECB4: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8009ECB8: bne         $a0, $t6, L_8009ECDC
    if (ctx->r4 != ctx->r14) {
        // 0x8009ECBC: nop
    
            goto L_8009ECDC;
    }
    // 0x8009ECBC: nop

    // 0x8009ECC0: lh          $t7, 0x12($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X12);
    // 0x8009ECC4: bne         $s0, $t7, L_8009ECDC
    if (ctx->r16 != ctx->r15) {
        // 0x8009ECC8: nop
    
            goto L_8009ECDC;
    }
    // 0x8009ECC8: nop

    // 0x8009ECCC: sh          $a2, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r6;
    // 0x8009ECD0: sh          $a3, 0x12($a1)
    MEM_H(0X12, ctx->r5) = ctx->r7;
    // 0x8009ECD4: b           L_8009ECE8
    // 0x8009ECD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8009ECE8;
    // 0x8009ECD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8009ECDC:
    // 0x8009ECDC: bne         $at, $zero, L_8009ECAC
    if (ctx->r1 != 0) {
        // 0x8009ECE0: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8009ECAC;
    }
    // 0x8009ECE0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_8009ECE4:
    // 0x8009ECE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009ECE8:
    // 0x8009ECE8: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x8009ECEC: jr          $ra
    // 0x8009ECF0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8009ECF0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x8009ECF4: nop

    // 0x8009ECF8: nop

    // 0x8009ECFC: nop

;}
RECOMP_FUNC void _chweather_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800859C8: syscall     185
    recomp_syscall_handler(rdram, ctx, 0x800859C8);
    return;
    // 0x800859CC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800910_chlavahand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800910: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800914: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800918: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080091C: lhu         $v1, 0x72($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X72);
    // 0x80800920: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800924: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x80800928: slti        $v0, $t6, 0x2
    ctx->r2 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x8080092C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80800930: beql        $v0, $zero, L_80800940
    if (ctx->r2 == 0) {
        // 0x80800934: lbu         $t9, 0x65($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X65);
            goto L_80800940;
    }
    goto skip_0;
    // 0x80800934: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    skip_0:
    // 0x80800938: slti        $v0, $t6, 0x8
    ctx->r2 = SIGNED(ctx->r14) < 0X8 ? 1 : 0;
    // 0x8080093C: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
L_80800940:
    // 0x80800940: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x80800944: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x80800948: andi        $t0, $t9, 0xFFFE
    ctx->r8 = ctx->r25 & 0XFFFE;
    // 0x8080094C: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80800950: beq         $a0, $zero, L_8080097C
    if (ctx->r4 == 0) {
        // 0x80800954: sb          $t1, 0x65($s0)
        MEM_B(0X65, ctx->r16) = ctx->r9;
            goto L_8080097C;
    }
    // 0x80800954: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    // 0x80800958: lhu         $t2, 0x64($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X64);
    // 0x8080095C: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80800960: bne         $t3, $zero, L_8080097C
    if (ctx->r11 != 0) {
        // 0x80800964: nop
    
            goto L_8080097C;
    }
    // 0x80800964: nop

    // 0x80800968: jal         0x800C8B84
    // 0x8080096C: nop

    func_800C8B84(rdram, ctx);
        goto after_0;
    // 0x8080096C: nop

    after_0:
    // 0x80800970: sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
    // 0x80800974: b           L_808009EC
    // 0x80800978: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_808009EC;
    // 0x80800978: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8080097C:
    // 0x8080097C: bne         $a0, $zero, L_808009EC
    if (ctx->r4 != 0) {
        // 0x80800980: nop
    
            goto L_808009EC;
    }
    // 0x80800980: nop

    // 0x80800984: lhu         $t4, 0x64($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X64);
    // 0x80800988: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x8080098C: beq         $t5, $zero, L_808009EC
    if (ctx->r13 == 0) {
        // 0x80800990: nop
    
            goto L_808009EC;
    }
    // 0x80800990: nop

    // 0x80800994: jal         0x800C8A98
    // 0x80800998: nop

    func_800C8A98(rdram, ctx);
        goto after_1;
    // 0x80800998: nop

    after_1:
    // 0x8080099C: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    // 0x808009A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808009A4: jal         0x800C8CB8
    // 0x808009A8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C8CB8(rdram, ctx);
        goto after_2;
    // 0x808009A8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_2:
    // 0x808009AC: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x808009B0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x808009B4: addiu       $a2, $zero, 0xE1
    ctx->r6 = ADD32(0, 0XE1);
    // 0x808009B8: jal         0x800C8FB0
    // 0x808009BC: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    func_800C8FB0(rdram, ctx);
        goto after_3;
    // 0x808009BC: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    after_3:
    // 0x808009C0: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x808009C4: jal         0x800C8F64
    // 0x808009C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C8F64(rdram, ctx);
        goto after_4;
    // 0x808009C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x808009CC: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x808009D0: lw          $a1, 0x2C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X2C);
    // 0x808009D4: jal         0x800C8E54
    // 0x808009D8: lw          $a2, 0x30($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X30);
    func_800C8E54(rdram, ctx);
        goto after_5;
    // 0x808009D8: lw          $a2, 0x30($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X30);
    after_5:
    // 0x808009DC: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x808009E0: jal         0x800C8FE0
    // 0x808009E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C8FE0(rdram, ctx);
        goto after_6;
    // 0x808009E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808009E8: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
L_808009EC:
    // 0x808009EC: beq         $a0, $zero, L_80800A1C
    if (ctx->r4 == 0) {
        // 0x808009F0: addiu       $a1, $zero, 0x2D
        ctx->r5 = ADD32(0, 0X2D);
            goto L_80800A1C;
    }
    // 0x808009F0: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    // 0x808009F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009F8: jal         0x8008A0D0
    // 0x808009FC: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_7;
    // 0x808009FC: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_7:
    // 0x80800A00: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x80800A04: jal         0x800C8CB8
    // 0x80800A08: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800C8CB8(rdram, ctx);
        goto after_8;
    // 0x80800A08: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_8:
    // 0x80800A0C: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x80800A10: lw          $a1, 0x2C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X2C);
    // 0x80800A14: jal         0x800C8E54
    // 0x80800A18: lw          $a2, 0x30($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X30);
    func_800C8E54(rdram, ctx);
        goto after_9;
    // 0x80800A18: lw          $a2, 0x30($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X30);
    after_9:
L_80800A1C:
    // 0x80800A1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A20: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800A24: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800A28: jr          $ra
    // 0x80800A2C: nop

    return;
    // 0x80800A2C: nop

;}
RECOMP_FUNC void func_800DE498(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_snow_model_drawn(rdram, ctx);
    // 0x800DE498: addiu       $sp, $sp, -0xF8
    ctx->r29 = ADD32(ctx->r29, -0XF8);
    // 0x800DE49C: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x800DE4A0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800DE4A4: sw          $a0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r4;
    // 0x800DE4A8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800DE4AC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DE4B0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DE4B4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800DE4B8: sw          $a2, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r6;
    // 0x800DE4BC: sw          $a3, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r7;
    // 0x800DE4C0: sw          $zero, -0x36C0($at)
    MEM_W(-0X36C0, ctx->r1) = 0;
    // 0x800DE4C4: addiu       $a1, $a1, -0x3158
    ctx->r5 = ADD32(ctx->r5, -0X3158);
    // 0x800DE4C8: jal         0x800E39A8
    // 0x800DE4CC: addiu       $a0, $a0, -0x3168
    ctx->r4 = ADD32(ctx->r4, -0X3168);
    func_800E39A8(rdram, ctx);
        goto after_0;
    // 0x800DE4CC: addiu       $a0, $a0, -0x3168
    ctx->r4 = ADD32(ctx->r4, -0X3168);
    after_0:
    // 0x800DE4D0: beq         $s0, $zero, L_800DE4E8
    if (ctx->r16 == 0) {
        // 0x800DE4D4: addiu       $a0, $sp, 0xE0
        ctx->r4 = ADD32(ctx->r29, 0XE0);
            goto L_800DE4E8;
    }
    // 0x800DE4D4: addiu       $a0, $sp, 0xE0
    ctx->r4 = ADD32(ctx->r29, 0XE0);
    // 0x800DE4D8: jal         0x800EE7F8
    // 0x800DE4DC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x800DE4DC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x800DE4E0: b           L_800DE4F0
    // 0x800DE4E4: nop

        goto L_800DE4F0;
    // 0x800DE4E4: nop

L_800DE4E8:
    // 0x800DE4E8: jal         0x800EFD24
    // 0x800DE4EC: addiu       $a0, $sp, 0xE0
    ctx->r4 = ADD32(ctx->r29, 0XE0);
    func_800EFD24(rdram, ctx);
        goto after_2;
    // 0x800DE4EC: addiu       $a0, $sp, 0xE0
    ctx->r4 = ADD32(ctx->r29, 0XE0);
    after_2:
L_800DE4F0:
    // 0x800DE4F0: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800DE4F4: addiu       $a2, $a2, -0x3168
    ctx->r6 = ADD32(ctx->r6, -0X3168);
    // 0x800DE4F8: addiu       $a0, $sp, 0xEC
    ctx->r4 = ADD32(ctx->r29, 0XEC);
    // 0x800DE4FC: jal         0x800EFB24
    // 0x800DE500: addiu       $a1, $sp, 0xE0
    ctx->r5 = ADD32(ctx->r29, 0XE0);
    func_800EFB24(rdram, ctx);
        goto after_3;
    // 0x800DE500: addiu       $a1, $sp, 0xE0
    ctx->r5 = ADD32(ctx->r29, 0XE0);
    after_3:
    // 0x800DE504: jal         0x800F2100
    // 0x800DE508: lwc1        $f12, 0xEC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XEC);
    mlAbsF(rdram, ctx);
        goto after_4;
    // 0x800DE508: lwc1        $f12, 0xEC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XEC);
    after_4:
    // 0x800DE50C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800DE510: lwc1        $f4, 0x5D54($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5D54);
    // 0x800DE514: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800DE518: nop

    // 0x800DE51C: bc1t        L_800DE568
    if (c1cs) {
        // 0x800DE520: nop
    
            goto L_800DE568;
    }
    // 0x800DE520: nop

    // 0x800DE524: jal         0x800F2100
    // 0x800DE528: lwc1        $f12, 0xF0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XF0);
    mlAbsF(rdram, ctx);
        goto after_5;
    // 0x800DE528: lwc1        $f12, 0xF0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XF0);
    after_5:
    // 0x800DE52C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800DE530: lwc1        $f6, 0x5D58($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5D58);
    // 0x800DE534: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800DE538: nop

    // 0x800DE53C: bc1t        L_800DE568
    if (c1cs) {
        // 0x800DE540: nop
    
            goto L_800DE568;
    }
    // 0x800DE540: nop

    // 0x800DE544: jal         0x800F2100
    // 0x800DE548: lwc1        $f12, 0xF4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XF4);
    mlAbsF(rdram, ctx);
        goto after_6;
    // 0x800DE548: lwc1        $f12, 0xF4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XF4);
    after_6:
    // 0x800DE54C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800DE550: lwc1        $f8, 0x5D5C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5D5C);
    // 0x800DE554: lw          $a1, 0x10C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X10C);
    // 0x800DE558: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x800DE55C: nop

    // 0x800DE560: bc1f        L_800DE578
    if (!c1cs) {
        // 0x800DE564: nop
    
            goto L_800DE578;
    }
    // 0x800DE564: nop

L_800DE568:
    // 0x800DE568: jal         0x800DE318
    // 0x800DE56C: nop

    func_800DE318(rdram, ctx);
        goto after_7;
    // 0x800DE56C: nop

    after_7:
    // 0x800DE570: b           L_800DF310
    // 0x800DE574: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800DF310;
    // 0x800DE574: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800DE578:
    // 0x800DE578: beq         $a1, $zero, L_800DE5E8
    if (ctx->r5 == 0) {
        // 0x800DE57C: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_800DE5E8;
    }
    // 0x800DE57C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800DE580: addiu       $s0, $s0, -0x36B8
    ctx->r16 = ADD32(ctx->r16, -0X36B8);
    // 0x800DE584: lw          $v1, 0x1C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1C);
    // 0x800DE588: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800DE58C: beql        $v1, $zero, L_800DE5A0
    if (ctx->r3 == 0) {
        // 0x800DE590: lw          $t6, 0x10($a1)
        ctx->r14 = MEM_W(ctx->r5, 0X10);
            goto L_800DE5A0;
    }
    goto skip_0;
    // 0x800DE590: lw          $t6, 0x10($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X10);
    skip_0:
    // 0x800DE594: b           L_800DE5A4
    // 0x800DE598: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800DE5A4;
    // 0x800DE598: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800DE59C: lw          $t6, 0x10($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X10);
L_800DE5A0:
    // 0x800DE5A0: addu        $v0, $a1, $t6
    ctx->r2 = ADD32(ctx->r5, ctx->r14);
L_800DE5A4:
    // 0x800DE5A4: lhu         $t7, 0x14($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X14);
    // 0x800DE5A8: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800DE5AC: bgez        $t7, L_800DE5C0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800DE5B0: cvt.s.w     $f14, $f10
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800DE5C0;
    }
    // 0x800DE5B0: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800DE5B4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800DE5B8: nop

    // 0x800DE5BC: add.s       $f14, $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f16.fl;
L_800DE5C0:
    // 0x800DE5C0: lhu         $t8, 0x12($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X12);
    // 0x800DE5C4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800DE5C8: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800DE5CC: bgez        $t8, L_800DE600
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800DE5D0: cvt.s.w     $f12, $f18
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800DE600;
    }
    // 0x800DE5D0: cvt.s.w     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800DE5D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800DE5D8: nop

    // 0x800DE5DC: add.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x800DE5E0: b           L_800DE604
    // 0x800DE5E4: addiu       $a0, $sp, 0xEC
    ctx->r4 = ADD32(ctx->r29, 0XEC);
        goto L_800DE604;
    // 0x800DE5E4: addiu       $a0, $sp, 0xEC
    ctx->r4 = ADD32(ctx->r29, 0XEC);
L_800DE5E8:
    // 0x800DE5E8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DE5EC: lwc1        $f14, -0x35E0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X35E0);
    // 0x800DE5F0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DE5F4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800DE5F8: addiu       $s0, $s0, -0x36B8
    ctx->r16 = ADD32(ctx->r16, -0X36B8);
    // 0x800DE5FC: lwc1        $f12, -0x35E4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X35E4);
L_800DE600:
    // 0x800DE600: addiu       $a0, $sp, 0xEC
    ctx->r4 = ADD32(ctx->r29, 0XEC);
L_800DE604:
    // 0x800DE604: swc1        $f12, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f12.u32l;
    // 0x800DE608: jal         0x800EEF94
    // 0x800DE60C: swc1        $f14, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f14.u32l;
    func_800EEF94(rdram, ctx);
        goto after_8;
    // 0x800DE60C: swc1        $f14, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f14.u32l;
    after_8:
    // 0x800DE610: lui         $at, 0x457A
    ctx->r1 = S32(0X457A << 16);
    // 0x800DE614: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800DE618: lwc1        $f12, 0xD8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800DE61C: lwc1        $f14, 0xD4($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800DE620: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x800DE624: swc1        $f0, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f0.u32l;
    // 0x800DE628: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DE62C: bc1f        L_800DE68C
    if (!c1cs) {
        // 0x800DE630: nop
    
            goto L_800DE68C;
    }
    // 0x800DE630: nop

    // 0x800DE634: lwc1        $f0, -0x37D4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X37D4);
    // 0x800DE638: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800DE63C: lwc1        $f8, 0x5D60($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5D60);
    // 0x800DE640: lwc1        $f10, 0x104($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X104);
    // 0x800DE644: c.eq.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl == ctx->f0.fl;
    // 0x800DE648: nop

    // 0x800DE64C: bc1f        L_800DE68C
    if (!c1cs) {
        // 0x800DE650: nop
    
            goto L_800DE68C;
    }
    // 0x800DE650: nop

    // 0x800DE654: mul.s       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x800DE658: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DE65C: lwc1        $f18, -0x37D0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X37D0);
    // 0x800DE660: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800DE664: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800DE668: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DE66C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800DE670: nop

    // 0x800DE674: mul.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800DE678: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800DE67C: nop

    // 0x800DE680: bc1f        L_800DE68C
    if (!c1cs) {
        // 0x800DE684: nop
    
            goto L_800DE68C;
    }
    // 0x800DE684: nop

    // 0x800DE688: swc1        $f2, -0x37D4($at)
    MEM_W(-0X37D4, ctx->r1) = ctx->f2.u32l;
L_800DE68C:
    // 0x800DE68C: jal         0x800E42C0
    // 0x800DE690: swc1        $f14, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f14.u32l;
    func_800E42C0(rdram, ctx);
        goto after_9;
    // 0x800DE690: swc1        $f14, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f14.u32l;
    after_9:
    // 0x800DE694: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DE698: lwc1        $f8, -0x37D4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X37D4);
    // 0x800DE69C: lwc1        $f16, 0xDC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x800DE6A0: lwc1        $f14, 0xD4($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800DE6A4: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800DE6A8: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800DE6AC: c.le.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl <= ctx->f16.fl;
    // 0x800DE6B0: swc1        $f10, -0x37D4($at)
    MEM_W(-0X37D4, ctx->r1) = ctx->f10.u32l;
    // 0x800DE6B4: bc1f        L_800DE6CC
    if (!c1cs) {
        // 0x800DE6B8: nop
    
            goto L_800DE6CC;
    }
    // 0x800DE6B8: nop

    // 0x800DE6BC: jal         0x800DE318
    // 0x800DE6C0: nop

    func_800DE318(rdram, ctx);
        goto after_10;
    // 0x800DE6C0: nop

    after_10:
    // 0x800DE6C4: b           L_800DF310
    // 0x800DE6C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800DF310;
    // 0x800DE6C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800DE6CC:
    // 0x800DE6CC: lw          $t9, -0x37D8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X37D8);
    // 0x800DE6D0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800DE6D4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DE6D8: beq         $t9, $zero, L_800DE700
    if (ctx->r25 == 0) {
        // 0x800DE6DC: lwc1        $f18, 0x104($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0X104);
            goto L_800DE700;
    }
    // 0x800DE6DC: lwc1        $f18, 0x104($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X104);
    // 0x800DE6E0: mul.s       $f4, $f14, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x800DE6E4: addiu       $a0, $sp, 0xE0
    ctx->r4 = ADD32(ctx->r29, 0XE0);
    // 0x800DE6E8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800DE6EC: jal         0x800E3E8C
    // 0x800DE6F0: nop

    func_800E3E8C(rdram, ctx);
        goto after_11;
    // 0x800DE6F0: nop

    after_11:
    // 0x800DE6F4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DE6F8: b           L_800DE704
    // 0x800DE6FC: sw          $v0, -0x36C0($at)
    MEM_W(-0X36C0, ctx->r1) = ctx->r2;
        goto L_800DE704;
    // 0x800DE6FC: sw          $v0, -0x36C0($at)
    MEM_W(-0X36C0, ctx->r1) = ctx->r2;
L_800DE700:
    // 0x800DE700: sw          $t1, -0x36C0($at)
    MEM_W(-0X36C0, ctx->r1) = ctx->r9;
L_800DE704:
    // 0x800DE704: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800DE708: lw          $t2, -0x36C0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X36C0);
    // 0x800DE70C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800DE710: bne         $t2, $zero, L_800DE728
    if (ctx->r10 != 0) {
        // 0x800DE714: nop
    
            goto L_800DE728;
    }
    // 0x800DE714: nop

    // 0x800DE718: jal         0x800DE318
    // 0x800DE71C: nop

    func_800DE318(rdram, ctx);
        goto after_12;
    // 0x800DE71C: nop

    after_12:
    // 0x800DE720: b           L_800DF310
    // 0x800DE724: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800DF310;
    // 0x800DE724: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800DE728:
    // 0x800DE728: lw          $v0, -0x3658($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3658);
    // 0x800DE72C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DE730: beql        $v0, $zero, L_800DE744
    if (ctx->r2 == 0) {
        // 0x800DE734: lw          $t3, 0x10C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X10C);
            goto L_800DE744;
    }
    goto skip_1;
    // 0x800DE734: lw          $t3, 0x10C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X10C);
    skip_1:
    // 0x800DE738: jalr        $v0
    // 0x800DE73C: lw          $a0, -0x3654($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3654);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_13;
    // 0x800DE73C: lw          $a0, -0x3654($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3654);
    after_13:
    // 0x800DE740: lw          $t3, 0x10C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X10C);
L_800DE744:
    // 0x800DE744: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DE748: bnel        $t3, $zero, L_800DE774
    if (ctx->r11 != 0) {
        // 0x800DE74C: lw          $t4, 0x18($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X18);
            goto L_800DE774;
    }
    goto skip_2;
    // 0x800DE74C: lw          $t4, 0x18($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X18);
    skip_2:
    // 0x800DE750: jal         0x800D674C
    // 0x800DE754: lw          $a0, -0x35E8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X35E8);
    func_800D674C(rdram, ctx);
        goto after_14;
    // 0x800DE754: lw          $a0, -0x35E8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X35E8);
    after_14:
    // 0x800DE758: bne         $v0, $zero, L_800DE770
    if (ctx->r2 != 0) {
        // 0x800DE75C: sw          $v0, 0x10C($sp)
        MEM_W(0X10C, ctx->r29) = ctx->r2;
            goto L_800DE770;
    }
    // 0x800DE75C: sw          $v0, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r2;
    // 0x800DE760: jal         0x800DE318
    // 0x800DE764: nop

    func_800DE318(rdram, ctx);
        goto after_15;
    // 0x800DE764: nop

    after_15:
    // 0x800DE768: b           L_800DF310
    // 0x800DE76C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800DF310;
    // 0x800DE76C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800DE770:
    // 0x800DE770: lw          $t4, 0x18($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X18);
L_800DE774:
    tooie_shadow_note_model(rdram, ctx); tooie_snout_model(rdram, ctx);
    // 0x800DE774: lw          $v1, 0x10C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10C);
    // 0x800DE778: bnel        $t4, $zero, L_800DE790
    if (ctx->r12 != 0) {
        // 0x800DE77C: lw          $t7, 0x14($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X14);
            goto L_800DE790;
    }
    goto skip_3;
    // 0x800DE77C: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    skip_3:
    // 0x800DE780: lw          $t5, 0xC($v1)
    ctx->r13 = MEM_W(ctx->r3, 0XC);
    // 0x800DE784: addu        $t6, $v1, $t5
    ctx->r14 = ADD32(ctx->r3, ctx->r13);
    // 0x800DE788: sw          $t6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r14;
    // 0x800DE78C: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
L_800DE790:
    // 0x800DE790: bnel        $t7, $zero, L_800DE7A8
    if (ctx->r15 != 0) {
        // 0x800DE794: lw          $t1, 0x1C($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X1C);
            goto L_800DE7A8;
    }
    goto skip_4;
    // 0x800DE794: lw          $t1, 0x1C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1C);
    skip_4:
    // 0x800DE798: lh          $t8, 0x8($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X8);
    // 0x800DE79C: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x800DE7A0: sw          $t9, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r25;
    // 0x800DE7A4: lw          $t1, 0x1C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1C);
L_800DE7A8:
    // 0x800DE7A8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800DE7AC: bnel        $t1, $zero, L_800DE7C4
    if (ctx->r9 != 0) {
        // 0x800DE7B0: lw          $v0, 0x20($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X20);
            goto L_800DE7C4;
    }
    goto skip_5;
    // 0x800DE7B0: lw          $v0, 0x20($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X20);
    skip_5:
    // 0x800DE7B4: lw          $t2, 0x10($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X10);
    // 0x800DE7B8: addu        $t3, $v1, $t2
    ctx->r11 = ADD32(ctx->r3, ctx->r10);
    // 0x800DE7BC: sw          $t3, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r11;
    // 0x800DE7C0: lw          $v0, 0x20($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X20);
L_800DE7C4:
    // 0x800DE7C4: bnel        $v0, $zero, L_800DE7D8
    if (ctx->r2 != 0) {
        // 0x800DE7C8: addu        $t4, $v1, $v0
        ctx->r12 = ADD32(ctx->r3, ctx->r2);
            goto L_800DE7D8;
    }
    goto skip_6;
    // 0x800DE7C8: addu        $t4, $v1, $v0
    ctx->r12 = ADD32(ctx->r3, ctx->r2);
    skip_6:
    // 0x800DE7CC: b           L_800DE7DC
    // 0x800DE7D0: sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
        goto L_800DE7DC;
    // 0x800DE7D0: sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
    // 0x800DE7D4: addu        $t4, $v1, $v0
    ctx->r12 = ADD32(ctx->r3, ctx->r2);
L_800DE7D8:
    // 0x800DE7D8: sw          $t4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r12;
L_800DE7DC:
    // 0x800DE7DC: lw          $t5, 0x30($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X30);
    // 0x800DE7E0: bne         $t5, $zero, L_800DE800
    if (ctx->r13 != 0) {
        // 0x800DE7E4: nop
    
            goto L_800DE800;
    }
    // 0x800DE7E4: nop

    // 0x800DE7E8: lw          $v0, 0x38($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X38);
    // 0x800DE7EC: bne         $v0, $zero, L_800DE7FC
    if (ctx->r2 != 0) {
        // 0x800DE7F0: addu        $t6, $v1, $v0
        ctx->r14 = ADD32(ctx->r3, ctx->r2);
            goto L_800DE7FC;
    }
    // 0x800DE7F0: addu        $t6, $v1, $v0
    ctx->r14 = ADD32(ctx->r3, ctx->r2);
    // 0x800DE7F4: b           L_800DE800
    // 0x800DE7F8: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
        goto L_800DE800;
    // 0x800DE7F8: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
L_800DE7FC:
    // 0x800DE7FC: sw          $t6, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r14;
L_800DE800:
    // 0x800DE800: lw          $t7, -0x37CC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X37CC);
    // 0x800DE804: beq         $t7, $zero, L_800DE884
    if (ctx->r15 == 0) {
        // 0x800DE808: lui         $at, 0x442F
        ctx->r1 = S32(0X442F << 16);
            goto L_800DE884;
    }
    // 0x800DE808: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x800DE80C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800DE810: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DE814: lwc1        $f6, -0x37D4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X37D4);
    // 0x800DE818: lwc1        $f8, 0xDC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x800DE81C: sub.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x800DE820: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x800DE824: nop

    // 0x800DE828: bc1fl       L_800DE888
    if (!c1cs) {
        // 0x800DE82C: lw          $t4, 0xF8($sp)
        ctx->r12 = MEM_W(ctx->r29, 0XF8);
            goto L_800DE888;
    }
    goto skip_7;
    // 0x800DE82C: lw          $t4, 0xF8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XF8);
    skip_7:
    // 0x800DE830: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800DE834: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800DE838: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800DE83C: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x800DE840: div.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800DE844: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800DE848: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800DE84C: lw          $t1, -0x365C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X365C);
    // 0x800DE850: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800DE854: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800DE858: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800DE85C: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800DE860: nop

    // 0x800DE864: multu       $t1, $t9
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800DE868: mflo        $t2
    ctx->r10 = lo;
    // 0x800DE86C: bgez        $t2, L_800DE87C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800DE870: sra         $t3, $t2, 8
        ctx->r11 = S32(SIGNED(ctx->r10) >> 8);
            goto L_800DE87C;
    }
    // 0x800DE870: sra         $t3, $t2, 8
    ctx->r11 = S32(SIGNED(ctx->r10) >> 8);
    // 0x800DE874: addiu       $at, $t2, 0xFF
    ctx->r1 = ADD32(ctx->r10, 0XFF);
    // 0x800DE878: sra         $t3, $at, 8
    ctx->r11 = S32(SIGNED(ctx->r1) >> 8);
L_800DE87C:
    // 0x800DE87C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DE880: sw          $t3, -0x365C($at)
    MEM_W(-0X365C, ctx->r1) = ctx->r11;
L_800DE884:
    // 0x800DE884: lw          $t4, 0xF8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XF8);
L_800DE888:
    // 0x800DE888: lui         $t7, 0xDB06
    ctx->r15 = S32(0XDB06 << 16);
    // 0x800DE88C: ori         $t7, $t7, 0x4
    ctx->r15 = ctx->r15 | 0X4;
    // 0x800DE890: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800DE894: sw          $t5, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r13;
    // 0x800DE898: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800DE89C: sw          $t6, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r14;
    // 0x800DE8A0: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x800DE8A4: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x800DE8A8: sw          $v1, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r3;
    // 0x800DE8AC: sw          $t5, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r13;
    // 0x800DE8B0: jal         0x8002E330
    // 0x800DE8B4: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_16;
    // 0x800DE8B4: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_16:
    // 0x800DE8B8: lw          $a1, 0xB8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB8);
    // 0x800DE8BC: lui         $t9, 0xDB06
    ctx->r25 = S32(0XDB06 << 16);
    // 0x800DE8C0: ori         $t9, $t9, 0x8
    ctx->r25 = ctx->r25 | 0X8;
    // 0x800DE8C4: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x800DE8C8: lw          $t8, 0xCC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XCC);
    // 0x800DE8CC: addiu       $t1, $t8, 0x8
    ctx->r9 = ADD32(ctx->r24, 0X8);
    // 0x800DE8D0: sw          $t1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r9;
    // 0x800DE8D4: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x800DE8D8: lw          $v1, 0x14($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X14);
    // 0x800DE8DC: lh          $t2, 0x4($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X4);
    // 0x800DE8E0: sw          $t8, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r24;
    // 0x800DE8E4: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x800DE8E8: addu        $a0, $v1, $t3
    ctx->r4 = ADD32(ctx->r3, ctx->r11);
    // 0x800DE8EC: jal         0x8002E330
    // 0x800DE8F0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_17;
    // 0x800DE8F0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_17:
    // 0x800DE8F4: lw          $a2, 0xB4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB4);
    // 0x800DE8F8: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x800DE8FC: lbu         $t4, 0x24($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X24);
    // 0x800DE900: beq         $t4, $zero, L_800DE994
    if (ctx->r12 == 0) {
        // 0x800DE904: nop
    
            goto L_800DE994;
    }
    // 0x800DE904: nop

    // 0x800DE908: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800DE90C: lbu         $a0, 0x24($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X24);
L_800DE910:
    // 0x800DE910: addiu       $a2, $sp, 0xAC
    ctx->r6 = ADD32(ctx->r29, 0XAC);
    // 0x800DE914: jal         0x800DB9FC
    // 0x800DE918: sw          $a1, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r5;
    func_800DB9FC(rdram, ctx);
        goto after_18;
    // 0x800DE918: sw          $a1, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r5;
    after_18:
    // 0x800DE91C: beq         $v0, $zero, L_800DE984
    if (ctx->r2 == 0) {
        // 0x800DE920: lw          $a1, 0xB0($sp)
        ctx->r5 = MEM_W(ctx->r29, 0XB0);
            goto L_800DE984;
    }
    // 0x800DE920: lw          $a1, 0xB0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB0);
    // 0x800DE924: lw          $t5, 0xCC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XCC);
    // 0x800DE928: negu        $t7, $a1
    ctx->r15 = SUB32(0, ctx->r5);
    // 0x800DE92C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800DE930: addiu       $t1, $t8, 0x3C
    ctx->r9 = ADD32(ctx->r24, 0X3C);
    // 0x800DE934: andi        $t9, $t1, 0xFFFF
    ctx->r25 = ctx->r9 & 0XFFFF;
    // 0x800DE938: lui         $at, 0xDB06
    ctx->r1 = S32(0XDB06 << 16);
    // 0x800DE93C: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800DE940: sw          $t6, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r14;
    // 0x800DE944: or          $t2, $t9, $at
    ctx->r10 = ctx->r25 | ctx->r1;
    // 0x800DE948: sw          $t2, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r10;
    // 0x800DE94C: lw          $v1, 0x14($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X14);
    // 0x800DE950: lw          $t6, 0xAC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XAC);
    // 0x800DE954: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x800DE958: lh          $t3, 0x4($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X4);
    // 0x800DE95C: sw          $a2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r6;
    // 0x800DE960: sw          $a1, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r5;
    // 0x800DE964: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x800DE968: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x800DE96C: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    // 0x800DE970: jal         0x8002E330
    // 0x800DE974: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_19;
    // 0x800DE974: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_19:
    // 0x800DE978: lw          $a2, 0xA8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA8);
    // 0x800DE97C: lw          $a1, 0xB0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB0);
    // 0x800DE980: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
L_800DE984:
    // 0x800DE984: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800DE988: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800DE98C: bnel        $a1, $at, L_800DE910
    if (ctx->r5 != ctx->r1) {
        // 0x800DE990: lbu         $a0, 0x24($s0)
        ctx->r4 = MEM_BU(ctx->r16, 0X24);
            goto L_800DE910;
    }
    goto skip_8;
    // 0x800DE990: lbu         $a0, 0x24($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X24);
    skip_8:
L_800DE994:
    // 0x800DE994: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800DE998: addiu       $a3, $a3, -0x3678
    ctx->r7 = ADD32(ctx->r7, -0X3678);
    // 0x800DE99C: lw          $v1, 0xC($a3)
    ctx->r3 = MEM_W(ctx->r7, 0XC);
    // 0x800DE9A0: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x800DE9A4: beq         $v1, $zero, L_800DEA10
    if (ctx->r3 == 0) {
        // 0x800DE9A8: lui         $t7, 0x8013
        ctx->r15 = S32(0X8013 << 16);
            goto L_800DEA10;
    }
    // 0x800DE9A8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800DE9AC: lw          $t7, -0x37C4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X37C4);
    // 0x800DE9B0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800DE9B4: beql        $t7, $at, L_800DEA14
    if (ctx->r15 == ctx->r1) {
        // 0x800DE9B8: lw          $t3, 0xCC($sp)
        ctx->r11 = MEM_W(ctx->r29, 0XCC);
            goto L_800DEA14;
    }
    goto skip_9;
    // 0x800DE9B8: lw          $t3, 0xCC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XCC);
    skip_9:
    // 0x800DE9BC: lw          $v0, 0x1C($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1C);
    // 0x800DE9C0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800DE9C4: sw          $zero, 0xC($a3)
    MEM_W(0XC, ctx->r7) = 0;
    // 0x800DE9C8: subu        $t8, $t0, $v0
    ctx->r24 = SUB32(ctx->r8, ctx->r2);
    // 0x800DE9CC: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800DE9D0: mflo        $t1
    ctx->r9 = lo;
    // 0x800DE9D4: nop

    // 0x800DE9D8: nop

    // 0x800DE9DC: div         $zero, $t1, $t0
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r8)));
    // 0x800DE9E0: mflo        $t9
    ctx->r25 = lo;
    // 0x800DE9E4: addu        $t2, $t9, $v0
    ctx->r10 = ADD32(ctx->r25, ctx->r2);
    // 0x800DE9E8: sw          $t2, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r10;
    // 0x800DE9EC: bne         $t0, $zero, L_800DE9F8
    if (ctx->r8 != 0) {
        // 0x800DE9F0: nop
    
            goto L_800DE9F8;
    }
    // 0x800DE9F0: nop

    // 0x800DE9F4: break       7
    do_break(2148395508);
L_800DE9F8:
    // 0x800DE9F8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800DE9FC: bne         $t0, $at, L_800DEA10
    if (ctx->r8 != ctx->r1) {
        // 0x800DEA00: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800DEA10;
    }
    // 0x800DEA00: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800DEA04: bne         $t1, $at, L_800DEA10
    if (ctx->r9 != ctx->r1) {
        // 0x800DEA08: nop
    
            goto L_800DEA10;
    }
    // 0x800DEA08: nop

    // 0x800DEA0C: break       6
    do_break(2148395532);
L_800DEA10:
    // 0x800DEA10: lw          $t3, 0xCC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XCC);
L_800DEA14:
    // 0x800DEA14: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x800DEA18: ori         $t8, $t8, 0x800
    ctx->r24 = ctx->r24 | 0X800;
    // 0x800DEA1C: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800DEA20: sw          $t4, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r12;
    // 0x800DEA24: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x800DEA28: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x800DEA2C: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x800DEA30: lui         $t1, 0x80
    ctx->r9 = S32(0X80 << 16);
    // 0x800DEA34: lui         $t3, 0xE300
    ctx->r11 = S32(0XE300 << 16);
    // 0x800DEA38: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800DEA3C: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
    // 0x800DEA40: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x800DEA44: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800DEA48: lw          $t9, 0xCC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XCC);
    // 0x800DEA4C: ori         $t3, $t3, 0xA01
    ctx->r11 = ctx->r11 | 0XA01;
    // 0x800DEA50: lui         $t4, 0x10
    ctx->r12 = S32(0X10 << 16);
    // 0x800DEA54: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x800DEA58: sw          $t2, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r10;
    // 0x800DEA5C: sw          $t4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r12;
    // 0x800DEA60: sw          $t3, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r11;
    // 0x800DEA64: lw          $t5, 0xCC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XCC);
    // 0x800DEA68: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x800DEA6C: lui         $t7, 0xF900
    ctx->r15 = S32(0XF900 << 16);
    // 0x800DEA70: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800DEA74: sw          $t6, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r14;
    // 0x800DEA78: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
    // 0x800DEA7C: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x800DEA80: lw          $a2, 0xCC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XCC);
    // 0x800DEA84: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x800DEA88: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800DEA8C: addiu       $t9, $a2, 0x8
    ctx->r25 = ADD32(ctx->r6, 0X8);
    // 0x800DEA90: sw          $t9, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r25;
    // 0x800DEA94: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
    // 0x800DEA98: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x800DEA9C: lw          $t3, 0xC($a3)
    ctx->r11 = MEM_W(ctx->r7, 0XC);
    // 0x800DEAA0: lw          $t1, 0x4($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X4);
    // 0x800DEAA4: lw          $t5, 0x8($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X8);
    // 0x800DEAA8: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x800DEAAC: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x800DEAB0: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x800DEAB4: andi        $t9, $t1, 0xFF
    ctx->r25 = ctx->r9 & 0XFF;
    // 0x800DEAB8: sll         $t2, $t9, 16
    ctx->r10 = S32(ctx->r25 << 16);
    // 0x800DEABC: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x800DEAC0: sll         $t4, $t6, 8
    ctx->r12 = S32(ctx->r14 << 8);
    // 0x800DEAC4: or          $t3, $t8, $t2
    ctx->r11 = ctx->r24 | ctx->r10;
    // 0x800DEAC8: or          $t7, $t3, $t4
    ctx->r15 = ctx->r11 | ctx->r12;
    // 0x800DEACC: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x800DEAD0: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
    // 0x800DEAD4: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x800DEAD8: addiu       $a1, $a1, -0x35D8
    ctx->r5 = ADD32(ctx->r5, -0X35D8);
    // 0x800DEADC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800DEAE0: sw          $t9, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r25;
    // 0x800DEAE4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800DEAE8: lw          $t3, 0x10($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X10);
    // 0x800DEAEC: lw          $t2, 0x1C($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X1C);
    // 0x800DEAF0: lw          $t1, 0x14($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X14);
    // 0x800DEAF4: lw          $t6, 0x18($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X18);
    // 0x800DEAF8: sll         $t4, $t3, 24
    ctx->r12 = S32(ctx->r11 << 24);
    // 0x800DEAFC: andi        $t5, $t2, 0xFF
    ctx->r13 = ctx->r10 & 0XFF;
    // 0x800DEB00: or          $t7, $t5, $t4
    ctx->r15 = ctx->r13 | ctx->r12;
    // 0x800DEB04: andi        $t9, $t1, 0xFF
    ctx->r25 = ctx->r9 & 0XFF;
    // 0x800DEB08: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x800DEB0C: andi        $t3, $t6, 0xFF
    ctx->r11 = ctx->r14 & 0XFF;
    // 0x800DEB10: sll         $t5, $t3, 8
    ctx->r13 = S32(ctx->r11 << 8);
    // 0x800DEB14: or          $t2, $t7, $t8
    ctx->r10 = ctx->r15 | ctx->r24;
    // 0x800DEB18: or          $t4, $t2, $t5
    ctx->r12 = ctx->r10 | ctx->r13;
    // 0x800DEB1C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800DEB20: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x800DEB24: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800DEB28: beql        $t1, $zero, L_800DEB58
    if (ctx->r9 == 0) {
        // 0x800DEB2C: lw          $t3, 0xCC($sp)
        ctx->r11 = MEM_W(ctx->r29, 0XCC);
            goto L_800DEB58;
    }
    goto skip_10;
    // 0x800DEB2C: lw          $t3, 0xCC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XCC);
    skip_10:
    // 0x800DEB30: lw          $t9, 0xCC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XCC);
    // 0x800DEB34: lui         $t8, 0xD9FF
    ctx->r24 = S32(0XD9FF << 16);
    // 0x800DEB38: ori         $t8, $t8, 0xFFFF
    ctx->r24 = ctx->r24 | 0XFFFF;
    // 0x800DEB3C: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x800DEB40: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
    // 0x800DEB44: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800DEB48: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x800DEB4C: b           L_800DEB70
    // 0x800DEB50: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
        goto L_800DEB70;
    // 0x800DEB50: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800DEB54: lw          $t3, 0xCC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XCC);
L_800DEB58:
    // 0x800DEB58: lui         $t5, 0xD9FF
    ctx->r13 = S32(0XD9FF << 16);
    // 0x800DEB5C: ori         $t5, $t5, 0xFFFE
    ctx->r13 = ctx->r13 | 0XFFFE;
    // 0x800DEB60: addiu       $t2, $t3, 0x8
    ctx->r10 = ADD32(ctx->r11, 0X8);
    // 0x800DEB64: sw          $t2, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r10;
    // 0x800DEB68: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x800DEB6C: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
L_800DEB70:
    // 0x800DEB70: lw          $t4, 0x1C($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X1C);
    // 0x800DEB74: bnel        $t0, $t4, L_800DEBC0
    if (ctx->r8 != ctx->r12) {
        // 0x800DEB78: lw          $t2, 0xCC($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XCC);
            goto L_800DEBC0;
    }
    goto skip_11;
    // 0x800DEB78: lw          $t2, 0xCC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XCC);
    skip_11:
    // 0x800DEB7C: lw          $t1, 0xCC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XCC);
    // 0x800DEB80: lui         $t7, 0xDB06
    ctx->r15 = S32(0XDB06 << 16);
    // 0x800DEB84: ori         $t7, $t7, 0xC
    ctx->r15 = ctx->r15 | 0XC;
    // 0x800DEB88: addiu       $t9, $t1, 0x8
    ctx->r25 = ADD32(ctx->r9, 0X8);
    // 0x800DEB8C: sw          $t9, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r25;
    // 0x800DEB90: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x800DEB94: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800DEB98: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800DEB9C: sw          $t1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r9;
    // 0x800DEBA0: sll         $t3, $t6, 3
    ctx->r11 = S32(ctx->r14 << 3);
    // 0x800DEBA4: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x800DEBA8: jal         0x8002E330
    // 0x800DEBAC: lw          $a0, 0x2DC8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2DC8);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_20;
    // 0x800DEBAC: lw          $a0, 0x2DC8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2DC8);
    after_20:
    // 0x800DEBB0: lw          $v1, 0x84($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X84);
    // 0x800DEBB4: b           L_800DEBF8
    // 0x800DEBB8: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
        goto L_800DEBF8;
    // 0x800DEBB8: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x800DEBBC: lw          $t2, 0xCC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XCC);
L_800DEBC0:
    // 0x800DEBC0: lui         $t4, 0xDB06
    ctx->r12 = S32(0XDB06 << 16);
    // 0x800DEBC4: ori         $t4, $t4, 0xC
    ctx->r12 = ctx->r12 | 0XC;
    // 0x800DEBC8: addiu       $t5, $t2, 0x8
    ctx->r13 = ADD32(ctx->r10, 0X8);
    // 0x800DEBCC: sw          $t5, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r13;
    // 0x800DEBD0: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x800DEBD4: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800DEBD8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800DEBDC: sw          $t2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r10;
    // 0x800DEBE0: sll         $t7, $t9, 3
    ctx->r15 = S32(ctx->r25 << 3);
    // 0x800DEBE4: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x800DEBE8: jal         0x8002E330
    // 0x800DEBEC: lw          $a0, 0x2DCC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2DCC);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_21;
    // 0x800DEBEC: lw          $a0, 0x2DCC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2DCC);
    after_21:
    // 0x800DEBF0: lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X80);
    // 0x800DEBF4: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_800DEBF8:
    // 0x800DEBF8: lw          $t8, 0x10C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10C);
    // 0x800DEBFC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800DEC00: lh          $v0, 0xA($t8)
    ctx->r2 = MEM_H(ctx->r24, 0XA);
    // 0x800DEC04: andi        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 & 0X2;
    // 0x800DEC08: beq         $t6, $zero, L_800DEC20
    if (ctx->r14 == 0) {
        // 0x800DEC0C: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_800DEC20;
    }
    // 0x800DEC0C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800DEC10: addiu       $t3, $t3, 0x2DF0
    ctx->r11 = ADD32(ctx->r11, 0X2DF0);
    // 0x800DEC14: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DEC18: b           L_800DEC60
    // 0x800DEC1C: sw          $t3, -0x37E0($at)
    MEM_W(-0X37E0, ctx->r1) = ctx->r11;
        goto L_800DEC60;
    // 0x800DEC1C: sw          $t3, -0x37E0($at)
    MEM_W(-0X37E0, ctx->r1) = ctx->r11;
L_800DEC20:
    // 0x800DEC20: andi        $t2, $v0, 0x80
    ctx->r10 = ctx->r2 & 0X80;
    // 0x800DEC24: beq         $t2, $zero, L_800DEC40
    if (ctx->r10 == 0) {
        // 0x800DEC28: andi        $t4, $v0, 0x100
        ctx->r12 = ctx->r2 & 0X100;
            goto L_800DEC40;
    }
    // 0x800DEC28: andi        $t4, $v0, 0x100
    ctx->r12 = ctx->r2 & 0X100;
    // 0x800DEC2C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800DEC30: addiu       $t5, $t5, 0x2EB0
    ctx->r13 = ADD32(ctx->r13, 0X2EB0);
    // 0x800DEC34: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DEC38: b           L_800DEC60
    // 0x800DEC3C: sw          $t5, -0x37E0($at)
    MEM_W(-0X37E0, ctx->r1) = ctx->r13;
        goto L_800DEC60;
    // 0x800DEC3C: sw          $t5, -0x37E0($at)
    MEM_W(-0X37E0, ctx->r1) = ctx->r13;
L_800DEC40:
    // 0x800DEC40: beq         $t4, $zero, L_800DEC5C
    if (ctx->r12 == 0) {
        // 0x800DEC44: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_800DEC5C;
    }
    // 0x800DEC44: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DEC48: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800DEC4C: addiu       $t1, $t1, 0x2F70
    ctx->r9 = ADD32(ctx->r9, 0X2F70);
    // 0x800DEC50: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DEC54: b           L_800DEC60
    // 0x800DEC58: sw          $t1, -0x37E0($at)
    MEM_W(-0X37E0, ctx->r1) = ctx->r9;
        goto L_800DEC60;
    // 0x800DEC58: sw          $t1, -0x37E0($at)
    MEM_W(-0X37E0, ctx->r1) = ctx->r9;
L_800DEC5C:
    // 0x800DEC5C: sw          $zero, -0x37E0($at)
    MEM_W(-0X37E0, ctx->r1) = 0;
L_800DEC60:
    // 0x800DEC60: lw          $t9, -0x37E0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X37E0);
    // 0x800DEC64: beql        $t9, $zero, L_800DEC98
    if (ctx->r25 == 0) {
        // 0x800DEC68: lw          $t5, 0x10C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X10C);
            goto L_800DEC98;
    }
    goto skip_12;
    // 0x800DEC68: lw          $t5, 0x10C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X10C);
    skip_12:
    // 0x800DEC6C: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x800DEC70: lui         $t6, 0xDE00
    ctx->r14 = S32(0XDE00 << 16);
    // 0x800DEC74: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800DEC78: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800DEC7C: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
    // 0x800DEC80: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800DEC84: lw          $t3, -0x37E0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X37E0);
    // 0x800DEC88: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800DEC8C: addu        $t2, $t3, $at
    ctx->r10 = ADD32(ctx->r11, ctx->r1);
    // 0x800DEC90: sw          $t2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r10;
    // 0x800DEC94: lw          $t5, 0x10C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X10C);
L_800DEC98:
    // 0x800DEC98: lh          $t4, 0xA($t5)
    ctx->r12 = MEM_H(ctx->r13, 0XA);
    // 0x800DEC9C: andi        $t1, $t4, 0x4
    ctx->r9 = ctx->r12 & 0X4;
    // 0x800DECA0: beql        $t1, $zero, L_800DEDA8
    if (ctx->r9 == 0) {
        // 0x800DECA4: lw          $t2, 0x10C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X10C);
            goto L_800DEDA8;
    }
    goto skip_13;
    // 0x800DECA4: lw          $t2, 0x10C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X10C);
    skip_13:
    // 0x800DECA8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800DECAC: lwc1        $f16, 0xF4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x800DECB0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800DECB4: addiu       $v0, $v0, -0x35C0
    ctx->r2 = ADD32(ctx->r2, -0X35C0);
    // 0x800DECB8: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x800DECBC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800DECC0: bc1fl       L_800DECD4
    if (!c1cs) {
        // 0x800DECC4: lw          $t9, 0xF8($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XF8);
            goto L_800DECD4;
    }
    goto skip_14;
    // 0x800DECC4: lw          $t9, 0xF8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF8);
    skip_14:
    // 0x800DECC8: lwc1        $f18, 0x5D64($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5D64);
    // 0x800DECCC: swc1        $f18, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f18.u32l;
    // 0x800DECD0: lw          $t9, 0xF8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF8);
L_800DECD4:
    // 0x800DECD4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800DECD8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800DECDC: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    // 0x800DECE0: lwc1        $f4, 0x410($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X410);
    // 0x800DECE4: lwc1        $f6, 0xEC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x800DECE8: lwc1        $f8, 0xF0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x800DECEC: lwc1        $f10, 0xF4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x800DECF0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x800DECF4: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x800DECF8: lw          $a1, 0x400($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X400);
    // 0x800DECFC: lw          $a2, 0x408($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X408);
    // 0x800DED00: lw          $a3, 0x40C($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X40C);
    // 0x800DED04: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x800DED08: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800DED0C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800DED10: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800DED14: jal         0x80013C80
    // 0x800DED18: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    func_80013C80(rdram, ctx);
        goto after_22;
    // 0x800DED18: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_22:
    // 0x800DED1C: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x800DED20: lui         $t6, 0xDC08
    ctx->r14 = S32(0XDC08 << 16);
    // 0x800DED24: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800DED28: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800DED2C: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
    // 0x800DED30: ori         $t6, $t6, 0xA
    ctx->r14 = ctx->r14 | 0XA;
    // 0x800DED34: addiu       $a2, $a2, -0x35C0
    ctx->r6 = ADD32(ctx->r6, -0X35C0);
    // 0x800DED38: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800DED3C: lw          $t3, 0x400($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X400);
    // 0x800DED40: lui         $t4, 0xDC08
    ctx->r12 = S32(0XDC08 << 16);
    // 0x800DED44: ori         $t4, $t4, 0x30A
    ctx->r12 = ctx->r12 | 0X30A;
    // 0x800DED48: sw          $t3, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r11;
    // 0x800DED4C: lw          $t2, 0xCC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XCC);
    // 0x800DED50: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x800DED54: addiu       $t5, $t2, 0x8
    ctx->r13 = ADD32(ctx->r10, 0X8);
    // 0x800DED58: sw          $t5, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r13;
    // 0x800DED5C: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x800DED60: lw          $t1, 0x400($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X400);
    // 0x800DED64: addiu       $t9, $t1, 0x10
    ctx->r25 = ADD32(ctx->r9, 0X10);
    // 0x800DED68: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x800DED6C: jal         0x8002E660
    // 0x800DED70: lw          $a0, 0x400($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X400);
    osWritebackDCache_recomp(rdram, ctx);
        goto after_23;
    // 0x800DED70: lw          $a0, 0x400($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X400);
    after_23:
    // 0x800DED74: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800DED78: lw          $t7, -0x31C0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X31C0);
    // 0x800DED7C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DED80: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800DED84: addiu       $t8, $t7, 0x20
    ctx->r24 = ADD32(ctx->r15, 0X20);
    // 0x800DED88: sw          $t8, -0x31C0($at)
    MEM_W(-0X31C0, ctx->r1) = ctx->r24;
    // 0x800DED8C: lw          $t6, -0x31BC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X31BC);
    // 0x800DED90: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800DED94: addiu       $t3, $t3, -0x35C0
    ctx->r11 = ADD32(ctx->r11, -0X35C0);
    // 0x800DED98: bne         $t6, $t8, L_800DEDA4
    if (ctx->r14 != ctx->r24) {
        // 0x800DED9C: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_800DEDA4;
    }
    // 0x800DED9C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DEDA0: sw          $t3, -0x31C0($at)
    MEM_W(-0X31C0, ctx->r1) = ctx->r11;
L_800DEDA4:
    // 0x800DEDA4: lw          $t2, 0x10C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X10C);
L_800DEDA8:
    // 0x800DEDA8: lh          $t5, 0xA($t2)
    ctx->r13 = MEM_H(ctx->r10, 0XA);
    // 0x800DEDAC: andi        $t4, $t5, 0x20
    ctx->r12 = ctx->r13 & 0X20;
    // 0x800DEDB0: beql        $t4, $zero, L_800DEDC4
    if (ctx->r12 == 0) {
        // 0x800DEDB4: lw          $a2, 0x20($s0)
        ctx->r6 = MEM_W(ctx->r16, 0X20);
            goto L_800DEDC4;
    }
    goto skip_15;
    // 0x800DEDB4: lw          $a2, 0x20($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X20);
    skip_15:
    // 0x800DEDB8: jal         0x800D2C54
    // 0x800DEDBC: addiu       $a0, $sp, 0xCC
    ctx->r4 = ADD32(ctx->r29, 0XCC);
    func_800D2C54(rdram, ctx);
        goto after_24;
    // 0x800DEDBC: addiu       $a0, $sp, 0xCC
    ctx->r4 = ADD32(ctx->r29, 0XCC);
    after_24:
    // 0x800DEDC0: lw          $a2, 0x20($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X20);
L_800DEDC4:
    // 0x800DEDC4: beq         $a2, $zero, L_800DEDE4
    if (ctx->r6 == 0) {
        // 0x800DEDC8: nop
    
            goto L_800DEDE4;
    }
    // 0x800DEDC8: nop

    // 0x800DEDCC: lw          $t1, 0x10C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X10C);
    // 0x800DEDD0: lw          $t9, 0x18($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X18);
    // 0x800DEDD4: bne         $t9, $zero, L_800DEDE4
    if (ctx->r25 != 0) {
        // 0x800DEDD8: nop
    
            goto L_800DEDE4;
    }
    // 0x800DEDD8: nop

    // 0x800DEDDC: b           L_800DEE54
    // 0x800DEDE0: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
        goto L_800DEE54;
    // 0x800DEDE0: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
L_800DEDE4:
    // 0x800DEDE4: bne         $a2, $zero, L_800DEE54
    if (ctx->r6 != 0) {
        // 0x800DEDE8: lw          $t7, 0x10C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X10C);
            goto L_800DEE54;
    }
    // 0x800DEDE8: lw          $t7, 0x10C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10C);
    // 0x800DEDEC: lw          $t6, 0x18($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X18);
    // 0x800DEDF0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800DEDF4: beql        $t6, $zero, L_800DEE58
    if (ctx->r14 == 0) {
        // 0x800DEDF8: lw          $a0, 0x28($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X28);
            goto L_800DEE58;
    }
    goto skip_16;
    // 0x800DEDF8: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    skip_16:
    // 0x800DEDFC: lw          $t8, -0x37DC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X37DC);
    // 0x800DEE00: bne         $t8, $zero, L_800DEE28
    if (ctx->r24 != 0) {
        // 0x800DEE04: nop
    
            goto L_800DEE28;
    }
    // 0x800DEE04: nop

    // 0x800DEE08: jal         0x800B27E0
    // 0x800DEE0C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_800B27E0(rdram, ctx);
        goto after_25;
    // 0x800DEE0C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_25:
    // 0x800DEE10: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DEE14: addiu       $a0, $a0, -0x37C0
    ctx->r4 = ADD32(ctx->r4, -0X37C0);
    // 0x800DEE18: jal         0x800ADCD0
    // 0x800DEE1C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800ADCD0(rdram, ctx);
        goto after_26;
    // 0x800DEE1C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_26:
    // 0x800DEE20: b           L_800DEE48
    // 0x800DEE24: nop

        goto L_800DEE48;
    // 0x800DEE24: nop

L_800DEE28:
    // 0x800DEE28: jal         0x800B27E0
    // 0x800DEE2C: lw          $a0, 0x10C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X10C);
    func_800B27E0(rdram, ctx);
        goto after_27;
    // 0x800DEE2C: lw          $a0, 0x10C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X10C);
    after_27:
    // 0x800DEE30: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DEE34: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800DEE38: lw          $a2, -0x37DC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X37DC);
    // 0x800DEE3C: addiu       $a0, $a0, -0x37C0
    ctx->r4 = ADD32(ctx->r4, -0X37C0);
    // 0x800DEE40: jal         0x800AE160
    // 0x800DEE44: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800AE160(rdram, ctx);
        goto after_28;
    // 0x800DEE44: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_28:
L_800DEE48:
    // 0x800DEE48: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800DEE4C: lw          $t3, -0x37C0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X37C0);
    // 0x800DEE50: sw          $t3, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r11;
L_800DEE54:
    // 0x800DEE54: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
L_800DEE58:
    // 0x800DEE58: beq         $a0, $zero, L_800DEE88
    if (ctx->r4 == 0) {
        // 0x800DEE5C: lui         $a1, 0x8013
        ctx->r5 = S32(0X8013 << 16);
            goto L_800DEE88;
    }
    // 0x800DEE5C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800DEE60: addiu       $a1, $a1, -0x3168
    ctx->r5 = ADD32(ctx->r5, -0X3168);
    // 0x800DEE64: lw          $a2, 0x104($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X104);
    // 0x800DEE68: jal         0x80087938
    // 0x800DEE6C: addiu       $a3, $sp, 0xE0
    ctx->r7 = ADD32(ctx->r29, 0XE0);
    _dbzone_entrypoint_1(rdram, ctx);
        goto after_29;
    // 0x800DEE6C: addiu       $a3, $sp, 0xE0
    ctx->r7 = ADD32(ctx->r29, 0XE0);
    after_29:
    // 0x800DEE70: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DEE74: lw          $a0, -0x37B8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X37B8);
    // 0x800DEE78: beql        $a0, $zero, L_800DEE8C
    if (ctx->r4 == 0) {
        // 0x800DEE7C: lw          $t2, 0x10C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X10C);
            goto L_800DEE8C;
    }
    goto skip_17;
    // 0x800DEE7C: lw          $t2, 0x10C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X10C);
    skip_17:
    // 0x800DEE80: jal         0x80088770
    // 0x800DEE84: nop

    _glzone_entrypoint_2(rdram, ctx);
        goto after_30;
    // 0x800DEE84: nop

    after_30:
L_800DEE88:
    // 0x800DEE88: lw          $t2, 0x10C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X10C);
L_800DEE8C:
    // 0x800DEE8C: lw          $v0, 0x28($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X28);
    // 0x800DEE90: beq         $v0, $zero, L_800DEF00
    if (ctx->r2 == 0) {
        // 0x800DEE94: nop
    
            goto L_800DEF00;
    }
    // 0x800DEE94: nop

    // 0x800DEE98: lw          $a2, 0x20($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X20);
    // 0x800DEE9C: beq         $a2, $zero, L_800DEF00
    if (ctx->r6 == 0) {
        // 0x800DEEA0: nop
    
            goto L_800DEF00;
    }
    // 0x800DEEA0: nop

    // 0x800DEEA4: lw          $a3, 0x30($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X30);
    // 0x800DEEA8: addu        $t5, $t2, $v0
    ctx->r13 = ADD32(ctx->r10, ctx->r2);
    // 0x800DEEAC: sw          $t5, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r13;
    // 0x800DEEB0: beq         $a3, $zero, L_800DEEF4
    if (ctx->r7 == 0) {
        // 0x800DEEB4: lui         $t4, 0x8013
        ctx->r12 = S32(0X8013 << 16);
            goto L_800DEEF4;
    }
    // 0x800DEEB4: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800DEEB8: lw          $t4, -0x37C8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X37C8);
    // 0x800DEEBC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800DEEC0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800DEEC4: bnel        $t4, $at, L_800DEEF8
    if (ctx->r12 != ctx->r1) {
        // 0x800DEEC8: lw          $a0, 0x34($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X34);
            goto L_800DEEF8;
    }
    goto skip_18;
    // 0x800DEEC8: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    skip_18:
    // 0x800DEECC: lbu         $v0, -0x35EF($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X35EF);
    // 0x800DEED0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800DEED4: beq         $v0, $at, L_800DEEF4
    if (ctx->r2 == ctx->r1) {
        // 0x800DEED8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800DEEF4;
    }
    // 0x800DEED8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800DEEDC: beq         $v0, $at, L_800DEEF4
    if (ctx->r2 == ctx->r1) {
        // 0x800DEEE0: or          $a0, $t5, $zero
        ctx->r4 = ctx->r13 | 0;
            goto L_800DEEF4;
    }
    // 0x800DEEE0: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x800DEEE4: jal         0x800879B8
    // 0x800DEEE8: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    _dbanim_entrypoint_1(rdram, ctx);
        goto after_31;
    // 0x800DEEE8: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    after_31:
    // 0x800DEEEC: b           L_800DEF00
    // 0x800DEEF0: nop

        goto L_800DEF00;
    // 0x800DEEF0: nop

L_800DEEF4:
    // 0x800DEEF4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
L_800DEEF8:
    // 0x800DEEF8: jal         0x800879B0
    // 0x800DEEFC: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    _dbanim_entrypoint_0(rdram, ctx);
        goto after_32;
    // 0x800DEEFC: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    after_32:
L_800DEF00:
    // 0x800DEF00: jal         0x80019CD4
    // 0x800DEF04: nop

    func_80019CD4(rdram, ctx);
        goto after_33;
    // 0x800DEF04: nop

    after_33:
    // 0x800DEF08: addiu       $a0, $sp, 0xE0
    ctx->r4 = ADD32(ctx->r29, 0XE0);
    // 0x800DEF0C: lw          $a1, 0x100($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X100);
    // 0x800DEF10: lw          $a2, 0x104($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X104);
    // 0x800DEF14: jal         0x80019750
    // 0x800DEF18: lw          $a3, 0x108($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X108);
    func_80019750(rdram, ctx);
        goto after_34;
    // 0x800DEF18: lw          $a3, 0x108($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X108);
    after_34:
    // 0x800DEF1C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800DEF20: addiu       $v1, $v1, -0x3648
    ctx->r3 = ADD32(ctx->r3, -0X3648);
    // 0x800DEF24: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800DEF28: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800DEF2C: beq         $v0, $at, L_800DEF4C
    if (ctx->r2 == ctx->r1) {
        // 0x800DEF30: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800DEF4C;
    }
    // 0x800DEF30: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800DEF34: beq         $v0, $at, L_800DEF64
    if (ctx->r2 == ctx->r1) {
        // 0x800DEF38: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800DEF64;
    }
    // 0x800DEF38: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800DEF3C: beq         $v0, $at, L_800DEF7C
    if (ctx->r2 == ctx->r1) {
        // 0x800DEF40: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800DEF7C;
    }
    // 0x800DEF40: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DEF44: b           L_800DEF84
    // 0x800DEF48: nop

        goto L_800DEF84;
    // 0x800DEF48: nop

L_800DEF4C:
    // 0x800DEF4C: lwc1        $f12, 0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800DEF50: lwc1        $f14, 0x8($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800DEF54: jal         0x80019110
    // 0x800DEF58: lw          $a2, 0xC($v1)
    ctx->r6 = MEM_W(ctx->r3, 0XC);
    mlMtxRotatePYR(rdram, ctx);
        goto after_35;
    // 0x800DEF58: lw          $a2, 0xC($v1)
    ctx->r6 = MEM_W(ctx->r3, 0XC);
    after_35:
    // 0x800DEF5C: b           L_800DEF84
    // 0x800DEF60: nop

        goto L_800DEF84;
    // 0x800DEF60: nop

L_800DEF64:
    // 0x800DEF64: lwc1        $f12, 0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800DEF68: lwc1        $f14, 0x8($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800DEF6C: jal         0x80019D30
    // 0x800DEF70: lw          $a2, 0xC($v1)
    ctx->r6 = MEM_W(ctx->r3, 0XC);
    mlMtxScale_xyz(rdram, ctx);
        goto after_36;
    // 0x800DEF70: lw          $a2, 0xC($v1)
    ctx->r6 = MEM_W(ctx->r3, 0XC);
    after_36:
    // 0x800DEF74: b           L_800DEF84
    // 0x800DEF78: nop

        goto L_800DEF84;
    // 0x800DEF78: nop

L_800DEF7C:
    // 0x800DEF7C: jal         0x80018C50
    // 0x800DEF80: addiu       $a0, $a0, -0x3638
    ctx->r4 = ADD32(ctx->r4, -0X3638);
    func_80018C50(rdram, ctx);
        goto after_37;
    // 0x800DEF80: addiu       $a0, $a0, -0x3638
    ctx->r4 = ADD32(ctx->r4, -0X3638);
    after_37:
L_800DEF84:
    // 0x800DEF84: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DEF88: jal         0x80018AD0
    // 0x800DEF8C: addiu       $a0, $a0, -0x31A8
    ctx->r4 = ADD32(ctx->r4, -0X31A8);
    mlMtxGet(rdram, ctx);
        goto after_38;
    // 0x800DEF8C: addiu       $a0, $a0, -0x31A8
    ctx->r4 = ADD32(ctx->r4, -0X31A8);
    after_38:
    // 0x800DEF90: lw          $t1, 0xF8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XF8);
    // 0x800DEF94: jal         0x80018C28
    // 0x800DEF98: lw          $a0, 0x4($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X4);
    mlMtxApply(rdram, ctx);
        goto after_39;
    // 0x800DEF98: lw          $a0, 0x4($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X4);
    after_39:
    // 0x800DEF9C: lw          $t9, 0x10C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X10C);
    // 0x800DEFA0: lh          $t6, 0xA($t9)
    ctx->r14 = MEM_H(ctx->r25, 0XA);
    // 0x800DEFA4: andi        $t8, $t6, 0x40
    ctx->r24 = ctx->r14 & 0X40;
    // 0x800DEFA8: beql        $t8, $zero, L_800DF080
    if (ctx->r24 == 0) {
        // 0x800DEFAC: lw          $t7, 0xCC($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XCC);
            goto L_800DF080;
    }
    goto skip_19;
    // 0x800DEFAC: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    skip_19:
    // 0x800DEFB0: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x800DEFB4: lw          $a2, 0xF8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XF8);
    // 0x800DEFB8: lui         $t2, 0xDA38
    ctx->r10 = S32(0XDA38 << 16);
    // 0x800DEFBC: addiu       $t3, $t7, 0x8
    ctx->r11 = ADD32(ctx->r15, 0X8);
    // 0x800DEFC0: sw          $t3, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r11;
    // 0x800DEFC4: ori         $t2, $t2, 0x5
    ctx->r10 = ctx->r10 | 0X5;
    // 0x800DEFC8: sw          $t2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r10;
    // 0x800DEFCC: lw          $t5, 0x4($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X4);
    // 0x800DEFD0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800DEFD4: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    // 0x800DEFD8: addu        $t4, $t5, $at
    ctx->r12 = ADD32(ctx->r13, ctx->r1);
    // 0x800DEFDC: sw          $t4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r12;
    // 0x800DEFE0: lw          $t1, 0x4($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X4);
    // 0x800DEFE4: addiu       $t9, $t1, 0x40
    ctx->r25 = ADD32(ctx->r9, 0X40);
    // 0x800DEFE8: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x800DEFEC: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    // 0x800DEFF0: bnel        $t6, $zero, L_800DF014
    if (ctx->r14 != 0) {
        // 0x800DEFF4: lw          $t2, 0xCC($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XCC);
            goto L_800DF014;
    }
    goto skip_20;
    // 0x800DEFF4: lw          $t2, 0xCC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XCC);
    skip_20:
    // 0x800DEFF8: sw          $t9, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r25;
    // 0x800DEFFC: jal         0x800AE598
    // 0x800DF000: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    func_800AE598(rdram, ctx);
        goto after_40;
    // 0x800DF000: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    after_40:
    // 0x800DF004: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x800DF008: addiu       $t3, $t7, 0x40
    ctx->r11 = ADD32(ctx->r15, 0X40);
    // 0x800DF00C: sw          $t3, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r11;
    // 0x800DF010: lw          $t2, 0xCC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XCC);
L_800DF014:
    // 0x800DF014: lui         $t4, 0xDB06
    ctx->r12 = S32(0XDB06 << 16);
    // 0x800DF018: ori         $t4, $t4, 0x14
    ctx->r12 = ctx->r12 | 0X14;
    // 0x800DF01C: addiu       $t5, $t2, 0x8
    ctx->r13 = ADD32(ctx->r10, 0X8);
    // 0x800DF020: sw          $t5, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r13;
    // 0x800DF024: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x800DF028: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x800DF02C: jal         0x8002E330
    // 0x800DF030: sw          $t2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r10;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_41;
    // 0x800DF030: sw          $t2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r10;
    after_41:
    // 0x800DF034: lw          $v1, 0x68($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X68);
    // 0x800DF038: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800DF03C: lui         $t8, 0xDB06
    ctx->r24 = S32(0XDB06 << 16);
    // 0x800DF040: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x800DF044: lw          $t1, -0x37E0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X37E0);
    // 0x800DF048: lw          $t9, 0xCC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XCC);
    // 0x800DF04C: ori         $t8, $t8, 0x18
    ctx->r24 = ctx->r24 | 0X18;
    // 0x800DF050: beq         $t1, $zero, L_800DF0B0
    if (ctx->r9 == 0) {
        // 0x800DF054: addiu       $t6, $t9, 0x8
        ctx->r14 = ADD32(ctx->r25, 0X8);
            goto L_800DF0B0;
    }
    // 0x800DF054: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x800DF058: sw          $t6, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r14;
    // 0x800DF05C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800DF060: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DF064: lw          $a0, -0x37E0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X37E0);
    // 0x800DF068: jal         0x8002E330
    // 0x800DF06C: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_42;
    // 0x800DF06C: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    after_42:
    // 0x800DF070: lw          $v1, 0x64($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X64);
    // 0x800DF074: b           L_800DF0B0
    // 0x800DF078: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
        goto L_800DF0B0;
    // 0x800DF078: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x800DF07C: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
L_800DF080:
    // 0x800DF080: lui         $t2, 0xDA38
    ctx->r10 = S32(0XDA38 << 16);
    // 0x800DF084: ori         $t2, $t2, 0x2
    ctx->r10 = ctx->r10 | 0X2;
    // 0x800DF088: addiu       $t3, $t7, 0x8
    ctx->r11 = ADD32(ctx->r15, 0X8);
    // 0x800DF08C: sw          $t3, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r11;
    // 0x800DF090: sw          $t2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r10;
    // 0x800DF094: lw          $t5, 0xF8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XF8);
    // 0x800DF098: lw          $t4, 0x4($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X4);
    // 0x800DF09C: sw          $t4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r12;
    // 0x800DF0A0: lw          $t1, 0xF8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XF8);
    // 0x800DF0A4: lw          $t9, 0x4($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X4);
    // 0x800DF0A8: addiu       $t6, $t9, 0x40
    ctx->r14 = ADD32(ctx->r25, 0X40);
    // 0x800DF0AC: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
L_800DF0B0:
    // 0x800DF0B0: lw          $a1, 0x100($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X100);
    // 0x800DF0B4: lwc1        $f18, 0x104($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X104);
    // 0x800DF0B8: lw          $t7, 0x108($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X108);
    // 0x800DF0BC: addiu       $t8, $sp, 0xE0
    ctx->r24 = ADD32(ctx->r29, 0XE0);
    // 0x800DF0C0: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x800DF0C4: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800DF0C8: sw          $a1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r5;
    // 0x800DF0CC: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    // 0x800DF0D0: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
    // 0x800DF0D4: lw          $t3, -0x3648($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X3648);
    // 0x800DF0D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800DF0DC: bne         $t3, $at, L_800DF0F0
    if (ctx->r11 != ctx->r1) {
        // 0x800DF0E0: lui         $t2, 0x8013
        ctx->r10 = S32(0X8013 << 16);
            goto L_800DF0F0;
    }
    // 0x800DF0E0: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800DF0E4: addiu       $t2, $t2, -0x3644
    ctx->r10 = ADD32(ctx->r10, -0X3644);
    // 0x800DF0E8: b           L_800DF0F4
    // 0x800DF0EC: sw          $t2, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r10;
        goto L_800DF0F4;
    // 0x800DF0EC: sw          $t2, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r10;
L_800DF0F0:
    // 0x800DF0F0: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
L_800DF0F4:
    // 0x800DF0F4: beq         $a1, $zero, L_800DF10C
    if (ctx->r5 == 0) {
        // 0x800DF0F8: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800DF10C;
    }
    // 0x800DF0F8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DF0FC: jal         0x800EE7F8
    // 0x800DF100: addiu       $a0, $a0, -0x3148
    ctx->r4 = ADD32(ctx->r4, -0X3148);
    func_800EE7F8(rdram, ctx);
        goto after_43;
    // 0x800DF100: addiu       $a0, $a0, -0x3148
    ctx->r4 = ADD32(ctx->r4, -0X3148);
    after_43:
    // 0x800DF104: b           L_800DF11C
    // 0x800DF108: lw          $t5, 0xCC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XCC);
        goto L_800DF11C;
    // 0x800DF108: lw          $t5, 0xCC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XCC);
L_800DF10C:
    // 0x800DF10C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DF110: jal         0x800EFD24
    // 0x800DF114: addiu       $a0, $a0, -0x3148
    ctx->r4 = ADD32(ctx->r4, -0X3148);
    func_800EFD24(rdram, ctx);
        goto after_44;
    // 0x800DF114: addiu       $a0, $a0, -0x3148
    ctx->r4 = ADD32(ctx->r4, -0X3148);
    after_44:
    // 0x800DF118: lw          $t5, 0xCC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XCC);
L_800DF11C:
    // 0x800DF11C: lw          $t4, 0xF8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XF8);
    // 0x800DF120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800DF124: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800DF128: sw          $t5, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r13;
    // 0x800DF12C: lw          $t9, 0x10C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X10C);
    // 0x800DF130: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DF134: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800DF138: lh          $t6, 0xA($t9)
    ctx->r14 = MEM_H(ctx->r25, 0XA);
    // 0x800DF13C: andi        $t1, $t6, 0x10
    ctx->r9 = ctx->r14 & 0X10;
    // 0x800DF140: beq         $t1, $zero, L_800DF150
    if (ctx->r9 == 0) {
        // 0x800DF144: nop
    
            goto L_800DF150;
    }
    // 0x800DF144: nop

    // 0x800DF148: jal         0x8010EF70
    // 0x800DF14C: addiu       $a3, $a3, -0x3168
    ctx->r7 = ADD32(ctx->r7, -0X3168);
    func_8010EF70(rdram, ctx);
        goto after_45;
    // 0x800DF14C: addiu       $a3, $a3, -0x3168
    ctx->r7 = ADD32(ctx->r7, -0X3168);
    after_45:
L_800DF150:
    // 0x800DF150: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800DF154: lw          $t8, -0x37C8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X37C8);
    // 0x800DF158: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800DF15C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800DF160: bnel        $t8, $at, L_800DF1DC
    if (ctx->r24 != ctx->r1) {
        // 0x800DF164: lw          $t1, 0x10C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X10C);
            goto L_800DF1DC;
    }
    goto skip_21;
    // 0x800DF164: lw          $t1, 0x10C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X10C);
    skip_21:
    // 0x800DF168: lbu         $t7, -0x35EF($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X35EF);
    // 0x800DF16C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800DF170: addiu       $t2, $t2, 0x3030
    ctx->r10 = ADD32(ctx->r10, 0X3030);
    // 0x800DF174: sll         $t3, $t7, 2
    ctx->r11 = S32(ctx->r15 << 2);
    // 0x800DF178: subu        $t3, $t3, $t7
    ctx->r11 = SUB32(ctx->r11, ctx->r15);
    // 0x800DF17C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800DF180: addu        $v0, $t3, $t2
    ctx->r2 = ADD32(ctx->r11, ctx->r10);
    // 0x800DF184: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800DF188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800DF18C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800DF190: beq         $v1, $zero, L_800DF1CC
    if (ctx->r3 == 0) {
        // 0x800DF194: lui         $a2, 0x8013
        ctx->r6 = S32(0X8013 << 16);
            goto L_800DF1CC;
    }
    // 0x800DF194: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800DF198: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800DF19C: addiu       $a3, $a3, -0x3168
    ctx->r7 = ADD32(ctx->r7, -0X3168);
    // 0x800DF1A0: lw          $a1, -0x35F8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X35F8);
    // 0x800DF1A4: jalr        $v1
    // 0x800DF1A8: lw          $a2, -0x35F4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X35F4);
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_46;
    // 0x800DF1A8: lw          $a2, -0x35F4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X35F4);
    after_46:
    // 0x800DF1AC: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800DF1B0: lbu         $t5, -0x35EF($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X35EF);
    // 0x800DF1B4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800DF1B8: addiu       $t9, $t9, 0x3030
    ctx->r25 = ADD32(ctx->r25, 0X3030);
    // 0x800DF1BC: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x800DF1C0: subu        $t4, $t4, $t5
    ctx->r12 = SUB32(ctx->r12, ctx->r13);
    // 0x800DF1C4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800DF1C8: addu        $v0, $t4, $t9
    ctx->r2 = ADD32(ctx->r12, ctx->r25);
L_800DF1CC:
    // 0x800DF1CC: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x800DF1D0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DF1D4: sw          $t6, -0x313C($at)
    MEM_W(-0X313C, ctx->r1) = ctx->r14;
    // 0x800DF1D8: lw          $t1, 0x10C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X10C);
L_800DF1DC:
    // 0x800DF1DC: lw          $a0, 0xF8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XF8);
    // 0x800DF1E0: lw          $t8, 0x4($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X4);
    // 0x800DF1E4: jal         0x800DE2A4
    // 0x800DF1E8: addu        $a1, $t1, $t8
    ctx->r5 = ADD32(ctx->r9, ctx->r24);
    func_800DE2A4(rdram, ctx);
        goto after_47;
    // 0x800DF1E8: addu        $a1, $t1, $t8
    ctx->r5 = ADD32(ctx->r9, ctx->r24);
    after_47:
    // 0x800DF1EC: lw          $t7, 0x10C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10C);
    // 0x800DF1F0: lw          $t5, 0xF8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XF8);
    // 0x800DF1F4: lui         $t9, 0xD838
    ctx->r25 = S32(0XD838 << 16);
    // 0x800DF1F8: lh          $t3, 0xA($t7)
    ctx->r11 = MEM_H(ctx->r15, 0XA);
    // 0x800DF1FC: andi        $t2, $t3, 0x40
    ctx->r10 = ctx->r11 & 0X40;
    // 0x800DF200: beql        $t2, $zero, L_800DF21C
    if (ctx->r10 == 0) {
        // 0x800DF204: lw          $v0, 0x0($t5)
        ctx->r2 = MEM_W(ctx->r13, 0X0);
            goto L_800DF21C;
    }
    goto skip_22;
    // 0x800DF204: lw          $v0, 0x0($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X0);
    skip_22:
    // 0x800DF208: jal         0x800E4640
    // 0x800DF20C: lw          $a0, 0xF8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XF8);
    func_800E4640(rdram, ctx);
        goto after_48;
    // 0x800DF20C: lw          $a0, 0xF8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XF8);
    after_48:
    // 0x800DF210: b           L_800DF238
    // 0x800DF214: lw          $t1, 0x10C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X10C);
        goto L_800DF238;
    // 0x800DF214: lw          $t1, 0x10C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X10C);
    // 0x800DF218: lw          $v0, 0x0($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X0);
L_800DF21C:
    // 0x800DF21C: ori         $t9, $t9, 0x2
    ctx->r25 = ctx->r25 | 0X2;
    // 0x800DF220: addiu       $t6, $zero, 0x40
    ctx->r14 = ADD32(0, 0X40);
    // 0x800DF224: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800DF228: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x800DF22C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800DF230: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800DF234: lw          $t1, 0x10C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X10C);
L_800DF238:
    // 0x800DF238: lw          $t3, 0xF8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF8);
    // 0x800DF23C: lui         $t4, 0xDE00
    ctx->r12 = S32(0XDE00 << 16);
    // 0x800DF240: lh          $t8, 0xA($t1)
    ctx->r24 = MEM_H(ctx->r9, 0XA);
    // 0x800DF244: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800DF248: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800DF24C: andi        $t7, $t8, 0x182
    ctx->r15 = ctx->r24 & 0X182;
    // 0x800DF250: beq         $t7, $zero, L_800DF274
    if (ctx->r15 == 0) {
        // 0x800DF254: nop
    
            goto L_800DF274;
    }
    // 0x800DF254: nop

    // 0x800DF258: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x800DF25C: lui         $t5, 0x12
    ctx->r13 = S32(0X12 << 16);
    // 0x800DF260: addiu       $t5, $t5, 0x2DB0
    ctx->r13 = ADD32(ctx->r13, 0X2DB0);
    // 0x800DF264: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x800DF268: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800DF26C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800DF270: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_800DF274:
    // 0x800DF274: lw          $t9, -0x37C8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X37C8);
    // 0x800DF278: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800DF27C: bnel        $t9, $at, L_800DF2BC
    if (ctx->r25 != ctx->r1) {
        // 0x800DF280: lw          $t8, 0x10C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X10C);
            goto L_800DF2BC;
    }
    goto skip_23;
    // 0x800DF280: lw          $t8, 0x10C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10C);
    skip_23:
    // 0x800DF284: lbu         $t6, -0x35EF($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X35EF);
    // 0x800DF288: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800DF28C: sll         $t1, $t6, 2
    ctx->r9 = S32(ctx->r14 << 2);
    // 0x800DF290: subu        $t1, $t1, $t6
    ctx->r9 = SUB32(ctx->r9, ctx->r14);
    // 0x800DF294: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800DF298: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x800DF29C: lw          $v0, 0x3038($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3038);
    // 0x800DF2A0: beq         $v0, $zero, L_800DF2B0
    if (ctx->r2 == 0) {
        // 0x800DF2A4: nop
    
            goto L_800DF2B0;
    }
    // 0x800DF2A4: nop

    // 0x800DF2A8: jalr        $v0
    // 0x800DF2AC: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_49;
    // 0x800DF2AC: nop

    after_49:
L_800DF2B0:
    // 0x800DF2B0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DF2B4: sw          $zero, -0x313C($at)
    MEM_W(-0X313C, ctx->r1) = 0;
    // 0x800DF2B8: lw          $t8, 0x10C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10C);
L_800DF2BC:
    // 0x800DF2BC: lh          $t7, 0xA($t8)
    ctx->r15 = MEM_H(ctx->r24, 0XA);
    // 0x800DF2C0: andi        $t2, $t7, 0x10
    ctx->r10 = ctx->r15 & 0X10;
    // 0x800DF2C4: beq         $t2, $zero, L_800DF2D4
    if (ctx->r10 == 0) {
        // 0x800DF2C8: nop
    
            goto L_800DF2D4;
    }
    // 0x800DF2C8: nop

    // 0x800DF2CC: jal         0x8010F270
    // 0x800DF2D0: nop

    func_8010F270(rdram, ctx);
        goto after_50;
    // 0x800DF2D0: nop

    after_50:
L_800DF2D4:
    // 0x800DF2D4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800DF2D8: lw          $v0, -0x3650($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3650);
    // 0x800DF2DC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DF2E0: beql        $v0, $zero, L_800DF2F4
    if (ctx->r2 == 0) {
        // 0x800DF2E4: lw          $t3, 0x10C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X10C);
            goto L_800DF2F4;
    }
    goto skip_24;
    // 0x800DF2E4: lw          $t3, 0x10C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X10C);
    skip_24:
    // 0x800DF2E8: jalr        $v0
    // 0x800DF2EC: lw          $a0, -0x364C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X364C);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_51;
    // 0x800DF2EC: lw          $a0, -0x364C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X364C);
    after_51:
    // 0x800DF2F0: lw          $t3, 0x10C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X10C);
L_800DF2F4:
    // 0x800DF2F4: lh          $t4, 0xA($t3)
    ctx->r12 = MEM_H(ctx->r11, 0XA);
    // 0x800DF2F8: andi        $t5, $t4, 0x4
    ctx->r13 = ctx->r12 & 0X4;
    // 0x800DF2FC: beq         $t5, $zero, L_800DF304
    if (ctx->r13 == 0) {
        // 0x800DF300: nop
    
            goto L_800DF304;
    }
    // 0x800DF300: nop

L_800DF304:
    // 0x800DF304: jal         0x800DE318
    // 0x800DF308: nop

    func_800DE318(rdram, ctx);
        goto after_52;
    // 0x800DF308: nop

    after_52:
    // 0x800DF30C: lw          $v0, 0x10C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10C);
L_800DF310:
    tooie_gfx_model_done(rdram, ctx);
    // 0x800DF310: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800DF314: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800DF318: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
    // 0x800DF31C: jr          $ra
    // 0x800DF320: nop

    return;
    // 0x800DF320: nop

;}
RECOMP_FUNC void func_80800328_chfriendlystonehead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800328: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080032C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800330: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800334: jal         0x800DA298
    // 0x80800338: addiu       $a0, $zero, 0x9CB
    ctx->r4 = ADD32(0, 0X9CB);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800338: addiu       $a0, $zero, 0x9CB
    ctx->r4 = ADD32(0, 0X9CB);
    after_0:
    // 0x8080033C: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800340: beq         $v1, $zero, L_80800354
    if (ctx->r3 == 0) {
        // 0x80800344: nop
    
            goto L_80800354;
    }
    // 0x80800344: nop

    // 0x80800348: jal         0x800DA298
    // 0x8080034C: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x8080034C: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    after_1:
    // 0x80800350: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
L_80800354:
    // 0x80800354: beq         $v1, $zero, L_80800394
    if (ctx->r3 == 0) {
        // 0x80800358: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_80800394;
    }
    // 0x80800358: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8080035C: jal         0x800D0A9C
    // 0x80800360: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_2;
    // 0x80800360: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800364: bne         $v0, $zero, L_80800394
    if (ctx->r2 != 0) {
        // 0x80800368: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800394;
    }
    // 0x80800368: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080036C: jal         0x80800830
    // 0x80800370: addiu       $a1, $zero, 0xF20
    ctx->r5 = ADD32(0, 0XF20);
    func_80800830_chfriendlystonehead(rdram, ctx);
        goto after_3;
    // 0x80800370: addiu       $a1, $zero, 0xF20
    ctx->r5 = ADD32(0, 0XF20);
    after_3:
    // 0x80800374: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800378: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080037C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800380: addiu       $a3, $zero, 0x2010
    ctx->r7 = ADD32(0, 0X2010);
    // 0x80800384: jal         0x80085708
    // 0x80800388: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_4;
    // 0x80800388: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_4:
    // 0x8080038C: b           L_80800438
    // 0x80800390: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800438;
    // 0x80800390: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800394:
    // 0x80800394: addiu       $a0, $zero, 0x9CA
    ctx->r4 = ADD32(0, 0X9CA);
    // 0x80800398: jal         0x800DA9E4
    // 0x8080039C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DA9E4(rdram, ctx);
        goto after_5;
    // 0x8080039C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x808003A0: beq         $v0, $zero, L_808003BC
    if (ctx->r2 == 0) {
        // 0x808003A4: addiu       $a0, $zero, 0x9CB
        ctx->r4 = ADD32(0, 0X9CB);
            goto L_808003BC;
    }
    // 0x808003A4: addiu       $a0, $zero, 0x9CB
    ctx->r4 = ADD32(0, 0X9CB);
    // 0x808003A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808003AC: jal         0x80800830
    // 0x808003B0: addiu       $a1, $zero, 0xF22
    ctx->r5 = ADD32(0, 0XF22);
    func_80800830_chfriendlystonehead(rdram, ctx);
        goto after_6;
    // 0x808003B0: addiu       $a1, $zero, 0xF22
    ctx->r5 = ADD32(0, 0XF22);
    after_6:
    // 0x808003B4: b           L_80800438
    // 0x808003B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800438;
    // 0x808003B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808003BC:
    // 0x808003BC: jal         0x800DA9E4
    // 0x808003C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DA9E4(rdram, ctx);
        goto after_7;
    // 0x808003C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x808003C4: beq         $v0, $zero, L_80800414
    if (ctx->r2 == 0) {
        // 0x808003C8: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800414;
    }
    // 0x808003C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808003CC: jal         0x808002F8
    // 0x808003D0: nop

    func_808002F8_chfriendlystonehead(rdram, ctx);
        goto after_8;
    // 0x808003D0: nop

    after_8:
    // 0x808003D4: jal         0x800DA298
    // 0x808003D8: addiu       $a0, $zero, 0x5E
    ctx->r4 = ADD32(0, 0X5E);
    func_800DA298(rdram, ctx);
        goto after_9;
    // 0x808003D8: addiu       $a0, $zero, 0x5E
    ctx->r4 = ADD32(0, 0X5E);
    after_9:
    // 0x808003DC: bne         $v0, $zero, L_808003F4
    if (ctx->r2 != 0) {
        // 0x808003E0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808003F4;
    }
    // 0x808003E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808003E4: jal         0x80800830
    // 0x808003E8: addiu       $a1, $zero, 0xF1E
    ctx->r5 = ADD32(0, 0XF1E);
    func_80800830_chfriendlystonehead(rdram, ctx);
        goto after_10;
    // 0x808003E8: addiu       $a1, $zero, 0xF1E
    ctx->r5 = ADD32(0, 0XF1E);
    after_10:
    // 0x808003EC: b           L_80800438
    // 0x808003F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800438;
    // 0x808003F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808003F4:
    // 0x808003F4: jal         0x800DA298
    // 0x808003F8: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    func_800DA298(rdram, ctx);
        goto after_11;
    // 0x808003F8: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    after_11:
    // 0x808003FC: bne         $v0, $zero, L_80800434
    if (ctx->r2 != 0) {
        // 0x80800400: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800434;
    }
    // 0x80800400: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800404: jal         0x80800830
    // 0x80800408: addiu       $a1, $zero, 0xF1F
    ctx->r5 = ADD32(0, 0XF1F);
    func_80800830_chfriendlystonehead(rdram, ctx);
        goto after_12;
    // 0x80800408: addiu       $a1, $zero, 0xF1F
    ctx->r5 = ADD32(0, 0XF1F);
    after_12:
    // 0x8080040C: b           L_80800438
    // 0x80800410: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800438;
    // 0x80800410: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800414:
    // 0x80800414: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1876, 0X978) << 16);
    // 0x80800418: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1876, 0X8C0) << 16);
    // 0x8080041C: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80800420: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800424: addiu       $a3, $a3, 0x8C0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1876, 0X8C0));
    // 0x80800428: addiu       $a2, $a2, 0x978
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1876, 0X978));
    // 0x8080042C: jal         0x8008A1F0
    // 0x80800430: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_13;
    // 0x80800430: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_13:
L_80800434:
    // 0x80800434: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800438:
    // 0x80800438: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080043C: jr          $ra
    // 0x80800440: nop

    return;
    // 0x80800440: nop

;}
RECOMP_FUNC void func_80096ACC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096ACC: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x80096AD0: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80096AD4: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x80096AD8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80096ADC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80096AE0: sw          $a2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r6;
    // 0x80096AE4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80096AE8: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80096AEC: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80096AF0: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80096AF4: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80096AF8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80096AFC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80096B00: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80096B04: sw          $a3, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r7;
    // 0x80096B08: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    // 0x80096B0C: jal         0x800EFB24
    // 0x80096B10: addiu       $a0, $sp, 0x8C
    ctx->r4 = ADD32(ctx->r29, 0X8C);
    func_800EFB24(rdram, ctx);
        goto after_0;
    // 0x80096B10: addiu       $a0, $sp, 0x8C
    ctx->r4 = ADD32(ctx->r29, 0X8C);
    after_0:
    // 0x80096B14: or          $v1, $fp, $zero
    ctx->r3 = ctx->r30 | 0;
    // 0x80096B18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80096B1C: addiu       $v0, $sp, 0xA4
    ctx->r2 = ADD32(ctx->r29, 0XA4);
    // 0x80096B20: addiu       $a1, $sp, 0xB0
    ctx->r5 = ADD32(ctx->r29, 0XB0);
L_80096B24:
    // 0x80096B24: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80096B28: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80096B2C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80096B30: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80096B34: nop

    // 0x80096B38: bc1fl       L_80096B4C
    if (!c1cs) {
        // 0x80096B3C: swc1        $f2, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
            goto L_80096B4C;
    }
    goto skip_0;
    // 0x80096B3C: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    skip_0:
    // 0x80096B40: b           L_80096B4C
    // 0x80096B44: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
        goto L_80096B4C;
    // 0x80096B44: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80096B48: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
L_80096B4C:
    // 0x80096B4C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80096B50: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x80096B54: bne         $at, $zero, L_80096B24
    if (ctx->r1 != 0) {
        // 0x80096B58: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80096B24;
    }
    // 0x80096B58: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80096B5C: or          $v1, $fp, $zero
    ctx->r3 = ctx->r30 | 0;
    // 0x80096B60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80096B64: addiu       $v0, $sp, 0x98
    ctx->r2 = ADD32(ctx->r29, 0X98);
    // 0x80096B68: addiu       $a1, $sp, 0xA4
    ctx->r5 = ADD32(ctx->r29, 0XA4);
L_80096B6C:
    // 0x80096B6C: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80096B70: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80096B74: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80096B78: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80096B7C: nop

    // 0x80096B80: bc1fl       L_80096B94
    if (!c1cs) {
        // 0x80096B84: swc1        $f2, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
            goto L_80096B94;
    }
    goto skip_1;
    // 0x80096B84: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    skip_1:
    // 0x80096B88: b           L_80096B94
    // 0x80096B8C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
        goto L_80096B94;
    // 0x80096B8C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80096B90: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
L_80096B94:
    // 0x80096B94: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80096B98: bne         $v0, $a1, L_80096B6C
    if (ctx->r2 != ctx->r5) {
        // 0x80096B9C: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80096B6C;
    }
    // 0x80096B9C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80096BA0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80096BA4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80096BA8: lwc1        $f4, 0x9C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80096BAC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80096BB0: lwc1        $f10, 0x4DF0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X4DF0);
    // 0x80096BB4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80096BB8: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80096BBC: addiu       $s0, $s0, 0x6D20
    ctx->r16 = ADD32(ctx->r16, 0X6D20);
    // 0x80096BC0: sw          $s0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r16;
    // 0x80096BC4: swc1        $f8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f8.u32l;
    // 0x80096BC8: addiu       $a0, $sp, 0xA4
    ctx->r4 = ADD32(ctx->r29, 0XA4);
    // 0x80096BCC: addiu       $a1, $sp, 0x98
    ctx->r5 = ADD32(ctx->r29, 0X98);
    // 0x80096BD0: addiu       $a2, $sp, 0xB4
    ctx->r6 = ADD32(ctx->r29, 0XB4);
    // 0x80096BD4: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x80096BD8: jal         0x800BED70
    // 0x80096BDC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800BED70(rdram, ctx);
        goto after_1;
    // 0x80096BDC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x80096BE0: bne         $v0, $zero, L_80096BF0
    if (ctx->r2 != 0) {
        // 0x80096BE4: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80096BF0;
    }
    // 0x80096BE4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80096BE8: b           L_80096DA4
    // 0x80096BEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80096DA4;
    // 0x80096BEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80096BF0:
    // 0x80096BF0: addiu       $v1, $v1, 0x6E30
    ctx->r3 = ADD32(ctx->r3, 0X6E30);
    // 0x80096BF4: lw          $t6, 0xB4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB4);
    // 0x80096BF8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80096BFC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80096C00: lwc1        $f16, 0x4DF4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X4DF4);
    // 0x80096C04: sltu        $at, $s0, $t6
    ctx->r1 = ctx->r16 < ctx->r14 ? 1 : 0;
    // 0x80096C08: or          $s4, $s0, $zero
    ctx->r20 = ctx->r16 | 0;
    // 0x80096C0C: beq         $at, $zero, L_80096CA4
    if (ctx->r1 == 0) {
        // 0x80096C10: swc1        $f16, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->f16.u32l;
            goto L_80096CA4;
    }
    // 0x80096C10: swc1        $f16, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f16.u32l;
    // 0x80096C14: addiu       $s7, $sp, 0x80
    ctx->r23 = ADD32(ctx->r29, 0X80);
    // 0x80096C18: addiu       $s6, $sp, 0x74
    ctx->r22 = ADD32(ctx->r29, 0X74);
    // 0x80096C1C: addiu       $s5, $sp, 0x68
    ctx->r21 = ADD32(ctx->r29, 0X68);
    // 0x80096C20: addiu       $s3, $zero, 0x12
    ctx->r19 = ADD32(0, 0X12);
    // 0x80096C24: addiu       $s0, $sp, 0x68
    ctx->r16 = ADD32(ctx->r29, 0X68);
L_80096C28:
    // 0x80096C28: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80096C2C: or          $s2, $s4, $zero
    ctx->r18 = ctx->r20 | 0;
L_80096C30:
    // 0x80096C30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80096C34: jal         0x800EE88C
    // 0x80096C38: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EE88C(rdram, ctx);
        goto after_2;
    // 0x80096C38: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x80096C3C: addiu       $s1, $s1, 0x6
    ctx->r17 = ADD32(ctx->r17, 0X6);
    // 0x80096C40: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80096C44: bne         $s1, $s3, L_80096C30
    if (ctx->r17 != ctx->r19) {
        // 0x80096C48: addiu       $s2, $s2, 0x6
        ctx->r18 = ADD32(ctx->r18, 0X6);
            goto L_80096C30;
    }
    // 0x80096C48: addiu       $s2, $s2, 0x6
    ctx->r18 = ADD32(ctx->r18, 0X6);
    // 0x80096C4C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80096C50: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80096C54: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    // 0x80096C58: jal         0x800967C8
    // 0x80096C5C: addiu       $a3, $sp, 0x8C
    ctx->r7 = ADD32(ctx->r29, 0X8C);
    func_800967C8(rdram, ctx);
        goto after_3;
    // 0x80096C5C: addiu       $a3, $sp, 0x8C
    ctx->r7 = ADD32(ctx->r29, 0X8C);
    after_3:
    // 0x80096C60: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80096C64: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x80096C68: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    // 0x80096C6C: jal         0x800967C8
    // 0x80096C70: addiu       $a3, $sp, 0x8C
    ctx->r7 = ADD32(ctx->r29, 0X8C);
    func_800967C8(rdram, ctx);
        goto after_4;
    // 0x80096C70: addiu       $a3, $sp, 0x8C
    ctx->r7 = ADD32(ctx->r29, 0X8C);
    after_4:
    // 0x80096C74: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80096C78: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80096C7C: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    // 0x80096C80: jal         0x800967C8
    // 0x80096C84: addiu       $a3, $sp, 0x8C
    ctx->r7 = ADD32(ctx->r29, 0X8C);
    func_800967C8(rdram, ctx);
        goto after_5;
    // 0x80096C84: addiu       $a3, $sp, 0x8C
    ctx->r7 = ADD32(ctx->r29, 0X8C);
    after_5:
    // 0x80096C88: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x80096C8C: addiu       $s4, $s4, 0x12
    ctx->r20 = ADD32(ctx->r20, 0X12);
    // 0x80096C90: sltu        $at, $s4, $t7
    ctx->r1 = ctx->r20 < ctx->r15 ? 1 : 0;
    // 0x80096C94: bnel        $at, $zero, L_80096C28
    if (ctx->r1 != 0) {
        // 0x80096C98: addiu       $s0, $sp, 0x68
        ctx->r16 = ADD32(ctx->r29, 0X68);
            goto L_80096C28;
    }
    goto skip_2;
    // 0x80096C98: addiu       $s0, $sp, 0x68
    ctx->r16 = ADD32(ctx->r29, 0X68);
    skip_2:
    // 0x80096C9C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80096CA0: addiu       $v1, $v1, 0x6E30
    ctx->r3 = ADD32(ctx->r3, 0X6E30);
L_80096CA4:
    // 0x80096CA4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80096CA8: lwc1        $f18, 0x4DF8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X4DF8);
    // 0x80096CAC: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80096CB0: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    // 0x80096CB4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80096CB8: c.eq.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl == ctx->f4.fl;
    // 0x80096CBC: nop

    // 0x80096CC0: bc1f        L_80096CD0
    if (!c1cs) {
        // 0x80096CC4: nop
    
            goto L_80096CD0;
    }
    // 0x80096CC4: nop

    // 0x80096CC8: b           L_80096DA4
    // 0x80096CCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80096DA4;
    // 0x80096CCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80096CD0:
    // 0x80096CD0: jal         0x800EE7F8
    // 0x80096CD4: addiu       $a1, $a1, 0x6E5C
    ctx->r5 = ADD32(ctx->r5, 0X6E5C);
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x80096CD4: addiu       $a1, $a1, 0x6E5C
    ctx->r5 = ADD32(ctx->r5, 0X6E5C);
    after_6:
    // 0x80096CD8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80096CDC: addiu       $a1, $a1, 0x6E50
    ctx->r5 = ADD32(ctx->r5, 0X6E50);
    // 0x80096CE0: jal         0x800EE7F8
    // 0x80096CE4: lw          $a0, 0xCC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XCC);
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x80096CE4: lw          $a0, 0xCC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XCC);
    after_7:
    // 0x80096CE8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80096CEC: lwc1        $f6, 0x6E38($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6E38);
    // 0x80096CF0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80096CF4: lwc1        $f8, 0x6E44($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6E44);
    // 0x80096CF8: jal         0x800F2100
    // 0x80096CFC: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    mlAbsF(rdram, ctx);
        goto after_8;
    // 0x80096CFC: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    after_8:
    // 0x80096D00: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80096D04: lwc1        $f10, 0x6E40($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6E40);
    // 0x80096D08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80096D0C: lwc1        $f16, 0x6E4C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6E4C);
    // 0x80096D10: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x80096D14: jal         0x800F2100
    // 0x80096D18: sub.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f16.fl;
    mlAbsF(rdram, ctx);
        goto after_9;
    // 0x80096D18: sub.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f16.fl;
    after_9:
    // 0x80096D1C: lwc1        $f18, 0x5C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80096D20: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x80096D24: lw          $t0, 0xC8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC8);
    // 0x80096D28: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80096D2C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80096D30: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80096D34: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80096D38: bc1f        L_80096D78
    if (!c1cs) {
        // 0x80096D3C: nop
    
            goto L_80096D78;
    }
    // 0x80096D3C: nop

    // 0x80096D40: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80096D44: lwc1        $f14, 0x6E38($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X6E38);
    // 0x80096D48: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80096D4C: lwc1        $f4, 0x6E48($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6E48);
    // 0x80096D50: lwc1        $f12, 0x0($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80096D54: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80096D58: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80096D5C: lw          $a3, 0x6E3C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X6E3C);
    // 0x80096D60: lw          $a2, 0x6E44($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6E44);
    // 0x80096D64: jal         0x800F10B4
    // 0x80096D68: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_10;
    // 0x80096D68: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_10:
    // 0x80096D6C: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x80096D70: b           L_80096DA0
    // 0x80096D74: swc1        $f0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f0.u32l;
        goto L_80096DA0;
    // 0x80096D74: swc1        $f0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f0.u32l;
L_80096D78:
    // 0x80096D78: lwc1        $f14, 0x6E40($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X6E40);
    // 0x80096D7C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80096D80: lwc1        $f6, 0x6E48($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6E48);
    // 0x80096D84: lwc1        $f12, 0x8($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80096D88: lw          $a2, 0x6E4C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6E4C);
    // 0x80096D8C: lw          $a3, 0x6E3C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X6E3C);
    // 0x80096D90: jal         0x800F10B4
    // 0x80096D94: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_11;
    // 0x80096D94: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_11:
    // 0x80096D98: lw          $t1, 0xC8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC8);
    // 0x80096D9C: swc1        $f0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f0.u32l;
L_80096DA0:
    // 0x80096DA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80096DA4:
    // 0x80096DA4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80096DA8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80096DAC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80096DB0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80096DB4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80096DB8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80096DBC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80096DC0: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80096DC4: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80096DC8: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80096DCC: jr          $ra
    // 0x80096DD0: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x80096DD0: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void _gczoombox_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087AF8: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087AF8);
    return;
    // 0x80087AFC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800148_chtransparencypot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800148: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080014C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800150: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800154: lwc1        $f0, 0x48($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X48);
    // 0x80800158: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8080015C: addiu       $a1, $zero, 0x67
    ctx->r5 = ADD32(0, 0X67);
    // 0x80800160: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800164: jal         0x800F7C0C
    // 0x80800168: nop

    func_800F7C0C(rdram, ctx);
        goto after_0;
    // 0x80800168: nop

    after_0:
    // 0x8080016C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800170: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800174: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800178: jal         0x800888C8
    // 0x8080017C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _fxsparkle_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x8080017C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80800180: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2200, 0X1F8) << 16);
    // 0x80800184: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800188: jal         0x800C4AF0
    // 0x8080018C: addiu       $a1, $a1, 0x1F8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2200, 0X1F8));
    func_800C4AF0(rdram, ctx);
        goto after_2;
    // 0x8080018C: addiu       $a1, $a1, 0x1F8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2200, 0X1F8));
    after_2:
    // 0x80800190: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800194: jal         0x8080001C
    // 0x80800198: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8080001C_chtransparencypot(rdram, ctx);
        goto after_3;
    // 0x80800198: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x8080019C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001A4: jr          $ra
    // 0x808001A8: nop

    return;
    // 0x808001A8: nop

    // 0x808001AC: nop

;}
RECOMP_FUNC void func_800C19E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C19E4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800C19E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C19EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C19F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C19F4: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800C19F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C19FC: jal         0x800C1070
    // 0x800C1A00: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_800C1070(rdram, ctx);
        goto after_0;
    // 0x800C1A00: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_0:
    // 0x800C1A04: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800C1A08: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C1A0C: jal         0x800EFB24
    // 0x800C1A10: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    func_800EFB24(rdram, ctx);
        goto after_1;
    // 0x800C1A10: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_1:
    // 0x800C1A14: jal         0x800EEFD4
    // 0x800C1A18: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_800EEFD4(rdram, ctx);
        goto after_2;
    // 0x800C1A18: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_2:
    // 0x800C1A1C: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800C1A20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C1A24: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800C1A28: nop

    // 0x800C1A2C: bc1fl       L_800C1A40
    if (!c1cs) {
        // 0x800C1A30: lwc1        $f2, 0x10($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0X10);
            goto L_800C1A40;
    }
    goto skip_0;
    // 0x800C1A30: lwc1        $f2, 0x10($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X10);
    skip_0:
    // 0x800C1A34: b           L_800C1A94
    // 0x800C1A38: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
        goto L_800C1A94;
    // 0x800C1A38: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x800C1A3C: lwc1        $f2, 0x10($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X10);
L_800C1A40:
    // 0x800C1A40: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800C1A44: nop

    // 0x800C1A48: bc1fl       L_800C1A94
    if (!c1cs) {
        // 0x800C1A4C: lh          $v1, 0x18($s0)
        ctx->r3 = MEM_H(ctx->r16, 0X18);
            goto L_800C1A94;
    }
    goto skip_1;
    // 0x800C1A4C: lh          $v1, 0x18($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X18);
    skip_1:
    // 0x800C1A50: sub.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800C1A54: lh          $v0, 0x18($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X18);
    // 0x800C1A58: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800C1A5C: sub.s       $f6, $f2, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x800C1A60: subu        $t7, $t6, $v0
    ctx->r15 = SUB32(ctx->r14, ctx->r2);
    // 0x800C1A64: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800C1A68: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800C1A6C: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800C1A70: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800C1A74: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C1A78: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800C1A7C: add.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800C1A80: trunc.w.s   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800C1A84: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x800C1A88: b           L_800C1A98
    // 0x800C1A8C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
        goto L_800C1A98;
    // 0x800C1A8C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C1A90: lh          $v1, 0x18($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X18);
L_800C1A94:
    // 0x800C1A94: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
L_800C1A98:
    // 0x800C1A98: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800C1A9C: jr          $ra
    // 0x800C1AA0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800C1AA0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
