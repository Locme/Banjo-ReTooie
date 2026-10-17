#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _subaddietaxi_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A520: syscall     844
    recomp_syscall_handler(rdram, ctx, 0x8008A520);
    return;
    // 0x8008A524: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_800DF7DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF7DC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DF7E0: jr          $ra
    // 0x800DF7E4: sw          $a0, -0x36A4($at)
    MEM_W(-0X36A4, ctx->r1) = ctx->r4;
    return;
    // 0x800DF7E4: sw          $a0, -0x36A4($at)
    MEM_W(-0X36A4, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void cheggproximity_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2220, 0XCE0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xCE0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2220, 0XCE0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xCE0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2220, 0XCE0));
;}
RECOMP_FUNC void _chintrocam_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086CA8: syscall     441
    recomp_syscall_handler(rdram, ctx, 0x80086CA8);
    return;
    // 0x80086CAC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80804750_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804750: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80804754: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80804758: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080475C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80804760: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80804764: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x80804768: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8080476C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80804770: bne         $v0, $at, L_80804788
    if (ctx->r2 != ctx->r1) {
        // 0x80804774: addiu       $s0, $zero, -0x1
        ctx->r16 = ADD32(0, -0X1);
            goto L_80804788;
    }
    // 0x80804774: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x80804778: jal         0x80804A38
    // 0x8080477C: nop

    func_80804A38_chgameselect(rdram, ctx);
        goto after_0;
    // 0x8080477C: nop

    after_0:
    // 0x80804780: b           L_80804868
    // 0x80804784: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80804868;
    // 0x80804784: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80804788:
    // 0x80804788: beq         $v0, $zero, L_808047F0
    if (ctx->r2 == 0) {
        // 0x8080478C: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_808047F0;
    }
    // 0x8080478C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80804790: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80804794: jal         0x80087D38
    // 0x80804798: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    _gcnewoption_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x80804798: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_1:
    // 0x8080479C: jal         0x80803C80
    // 0x808047A0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_80803C80_chgameselect(rdram, ctx);
        goto after_2;
    // 0x808047A0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    tooie_vanilla_widescreen_row_stack(rdram, ctx);
    // 0x808047A4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808047A8: jal         0x8080499C
    // 0x808047AC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_8080499C_chgameselect(rdram, ctx);
        goto after_3;
    // 0x808047AC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x808047B0: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x808047B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808047B8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x808047BC: bne         $v1, $at, L_808047E0
    if (ctx->r3 != ctx->r1) {
        // 0x808047C0: lw          $t6, 0x20($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X20);
            goto L_808047E0;
    }
    // 0x808047C0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808047C4: beq         $t6, $zero, L_808047D4
    if (ctx->r14 == 0) {
        // 0x808047C8: addiu       $t7, $zero, -0x2
        ctx->r15 = ADD32(0, -0X2);
            goto L_808047D4;
    }
    // 0x808047C8: addiu       $t7, $zero, -0x2
    ctx->r15 = ADD32(0, -0X2);
    // 0x808047CC: b           L_808047D8
    // 0x808047D0: addiu       $s0, $zero, 0x6
    ctx->r16 = ADD32(0, 0X6);
        goto L_808047D8;
    // 0x808047D0: addiu       $s0, $zero, 0x6
    ctx->r16 = ADD32(0, 0X6);
L_808047D4:
    // 0x808047D4: addiu       $s0, $zero, 0x7
    ctx->r16 = ADD32(0, 0X7);
L_808047D8:
    // 0x808047D8: b           L_80804864
    // 0x808047DC: sw          $t7, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r15;
        goto L_80804864;
    // 0x808047DC: sw          $t7, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r15;
L_808047E0:
    // 0x808047E0: jal         0x80804A38
    // 0x808047E4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80804A38_chgameselect(rdram, ctx);
        goto after_4;
    // 0x808047E4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_4:
    // 0x808047E8: b           L_80804868
    // 0x808047EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80804868;
    // 0x808047EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808047F0:
    // 0x808047F0: bnel        $v0, $zero, L_80804868
    if (ctx->r2 != 0) {
        // 0x808047F4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80804868;
    }
    goto skip_0;
    // 0x808047F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808047F8: lw          $a0, 0x30($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X30);
    // 0x808047FC: jal         0x80802C10
    // 0x80804800: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_80802C10_chgameselect(rdram, ctx);
        goto after_5;
    // 0x80804800: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_5:
    tooie_vanilla_widescreen_row_stack(rdram, ctx);
    // 0x80804804: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80804808: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8080480C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80804810: beq         $v1, $zero, L_80804838
    if (ctx->r3 == 0) {
        // 0x80804814: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80804838;
    }
    // 0x80804814: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80804818: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080481C: beq         $v1, $at, L_80804850
    if (ctx->r3 == ctx->r1) {
        // 0x80804820: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_80804850;
    }
    // 0x80804820: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80804824: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80804828: beq         $v1, $at, L_8080485C
    if (ctx->r3 == ctx->r1) {
        // 0x8080482C: addiu       $t0, $zero, 0x4
        ctx->r8 = ADD32(0, 0X4);
            goto L_8080485C;
    }
    // 0x8080482C: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80804830: b           L_80804868
    // 0x80804834: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80804868;
    // 0x80804834: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80804838:
    // 0x80804838: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x8080483C: sw          $t8, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r24;
    // 0x80804840: jal         0x80108B04
    // 0x80804844: addiu       $a1, $zero, 0x1E8
    ctx->r5 = ADD32(0, 0X1E8);
    func_80108B04(rdram, ctx);
        goto after_6;
    // 0x80804844: addiu       $a1, $zero, 0x1E8
    ctx->r5 = ADD32(0, 0X1E8);
    after_6:
    // 0x80804848: b           L_80804868
    // 0x8080484C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80804868;
    // 0x8080484C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80804850:
    // 0x80804850: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x80804854: b           L_80804864
    // 0x80804858: sw          $t9, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r25;
        goto L_80804864;
    // 0x80804858: sw          $t9, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r25;
L_8080485C:
    // 0x8080485C: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
    // 0x80804860: sw          $t0, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r8;
L_80804864:
    // 0x80804864: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80804868:
    // 0x80804868: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8080486C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80804870: jr          $ra
    // 0x80804874: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80804874: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void bskazshock_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005E4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808005E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808005EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808005F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808005F4: jal         0x8008CABC
    // 0x808005F8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808005F8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_0:
    // 0x808005FC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800600: jal         0x800834B0
    // 0x80800604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bskazmove_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080060C: jal         0x8009BB24
    // 0x80800610: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_8009BB24(rdram, ctx);
        goto after_2;
    // 0x80800610: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x80800614: lui         $a1, 0x3F1C
    ctx->r5 = S32(0X3F1C << 16);
    // 0x80800618: ori         $a1, $a1, 0x28F6
    ctx->r5 = ctx->r5 | 0X28F6;
    // 0x8080061C: jal         0x8008B348
    // 0x80800620: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_3;
    // 0x80800620: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80800624: beq         $v0, $zero, L_80800638
    if (ctx->r2 == 0) {
        // 0x80800628: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800638;
    }
    // 0x80800628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080062C: addiu       $a1, $zero, 0x4598
    ctx->r5 = ADD32(0, 0X4598);
    // 0x80800630: jal         0x8009DF58
    // 0x80800634: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8009DF58(rdram, ctx);
        goto after_4;
    // 0x80800634: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_4:
L_80800638:
    // 0x80800638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080063C: jal         0x80091A30
    // 0x80800640: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_released(rdram, ctx);
        goto after_5;
    // 0x80800640: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_5:
    // 0x80800644: beq         $v0, $zero, L_8080066C
    if (ctx->r2 == 0) {
        // 0x80800648: lwc1        $f6, 0x2C($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
            goto L_8080066C;
    }
    // 0x80800648: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8080064C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800650: nop

    // 0x80800654: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800658: nop

    // 0x8080065C: bc1fl       L_80800670
    if (!c1cs) {
        // 0x80800660: lw          $t6, 0x160($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X160);
            goto L_80800670;
    }
    goto skip_0;
    // 0x80800660: lw          $t6, 0x160($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X160);
    skip_0:
    // 0x80800664: jal         0x8009BC6C
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_6;
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_8080066C:
    // 0x8080066C: lw          $t6, 0x160($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X160);
L_80800670:
    // 0x80800670: bne         $t6, $zero, L_808006A0
    if (ctx->r14 != 0) {
        // 0x80800674: nop
    
            goto L_808006A0;
    }
    // 0x80800674: nop

    // 0x80800678: jal         0x80800000
    // 0x8080067C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bskazshock_entrypoint_0(rdram, ctx);
        goto after_7;
    // 0x8080067C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800680: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800684: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800688: addiu       $t7, $zero, 0xDF
    ctx->r15 = ADD32(0, 0XDF);
    // 0x8080068C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80800690: nop

    // 0x80800694: bc1f        L_808006A0
    if (!c1cs) {
        // 0x80800698: nop
    
            goto L_808006A0;
    }
    // 0x80800698: nop

    // 0x8080069C: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
L_808006A0:
    // 0x808006A0: jal         0x8008E078
    // 0x808006A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_8;
    // 0x808006A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808006A8: bnel        $v0, $zero, L_80800710
    if (ctx->r2 != 0) {
        // 0x808006AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800710;
    }
    goto skip_1;
    // 0x808006AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x808006B0: jal         0x8008E260
    // 0x808006B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E260(rdram, ctx);
        goto after_9;
    // 0x808006B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808006B8: beq         $v0, $zero, L_808006C4
    if (ctx->r2 == 0) {
        // 0x808006BC: addiu       $t8, $zero, 0xE0
        ctx->r24 = ADD32(0, 0XE0);
            goto L_808006C4;
    }
    // 0x808006BC: addiu       $t8, $zero, 0xE0
    ctx->r24 = ADD32(0, 0XE0);
    // 0x808006C0: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_808006C4:
    // 0x808006C4: jal         0x80097D9C
    // 0x808006C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_feathery_flap(rdram, ctx);
        goto after_10;
    // 0x808006C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808006CC: beq         $v0, $zero, L_808006D8
    if (ctx->r2 == 0) {
        // 0x808006D0: addiu       $t9, $zero, 0x15C
        ctx->r25 = ADD32(0, 0X15C);
            goto L_808006D8;
    }
    // 0x808006D0: addiu       $t9, $zero, 0x15C
    ctx->r25 = ADD32(0, 0X15C);
    // 0x808006D4: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
L_808006D8:
    // 0x808006D8: jal         0x8009BB50
    // 0x808006DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_11;
    // 0x808006DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808006E0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x808006E4: nop

    // 0x808006E8: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x808006EC: nop

    // 0x808006F0: bc1fl       L_80800710
    if (!c1cs) {
        // 0x808006F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800710;
    }
    goto skip_2;
    // 0x808006F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x808006F8: jal         0x80097E74
    // 0x808006FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_func_80097E74(rdram, ctx);
        goto after_12;
    // 0x808006FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800700: beq         $v0, $zero, L_8080070C
    if (ctx->r2 == 0) {
        // 0x80800704: addiu       $t0, $zero, 0xBE
        ctx->r8 = ADD32(0, 0XBE);
            goto L_8080070C;
    }
    // 0x80800704: addiu       $t0, $zero, 0xBE
    ctx->r8 = ADD32(0, 0XBE);
    // 0x80800708: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
L_8080070C:
    // 0x8080070C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800710:
    // 0x80800710: jal         0x8009E5C8
    // 0x80800714: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    bs_setState(rdram, ctx);
        goto after_13;
    // 0x80800714: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_13:
    // 0x80800718: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080071C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800720: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800724: jr          $ra
    // 0x80800728: nop

    return;
    // 0x80800728: nop

;}
RECOMP_FUNC void func_808010A0_chstatueboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808010A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808010A8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x808010AC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808010B0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x808010B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808010B8: jal         0x80100094
    // 0x808010BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808010BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808010C0: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x808010C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808010C8: slti        $at, $a3, 0xCEC
    ctx->r1 = SIGNED(ctx->r7) < 0XCEC ? 1 : 0;
    // 0x808010CC: bne         $at, $zero, L_808010F4
    if (ctx->r1 != 0) {
        // 0x808010D0: addiu       $t6, $a3, -0xF33
        ctx->r14 = ADD32(ctx->r7, -0XF33);
            goto L_808010F4;
    }
    // 0x808010D0: addiu       $t6, $a3, -0xF33
    ctx->r14 = ADD32(ctx->r7, -0XF33);
    // 0x808010D4: sltiu       $at, $t6, 0x11
    ctx->r1 = ctx->r14 < 0X11 ? 1 : 0;
    // 0x808010D8: beq         $at, $zero, L_80801190
    if (ctx->r1 == 0) {
        // 0x808010DC: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80801190;
    }
    // 0x808010DC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808010E0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1312, 0X251C) << 16);
    // 0x808010E4: addu        $at, $at, $t6
    gpr jr_addend_808010EC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808010E8: lw          $t6, 0x251C($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1312, 0X251C));
    // 0x808010EC: jr          $t6
    // 0x808010F0: nop

    switch (jr_addend_808010EC >> 2) {
        case 0: goto L_80801108; break;
        case 1: goto L_80801128; break;
        case 2: goto L_80801160; break;
        case 3: goto L_80801138; break;
        case 4: goto L_80801190; break;
        case 5: goto L_80801190; break;
        case 6: goto L_80801190; break;
        case 7: goto L_80801190; break;
        case 8: goto L_80801190; break;
        case 9: goto L_80801190; break;
        case 10: goto L_80801190; break;
        case 11: goto L_80801190; break;
        case 12: goto L_80801190; break;
        case 13: goto L_80801190; break;
        case 14: goto L_80801118; break;
        case 15: goto L_80801190; break;
        case 16: goto L_80801154; break;
        default: switch_error(__func__, 0x808010EC, 0x8080251C);
    }
    // 0x808010F0: nop

L_808010F4:
    // 0x808010F4: addiu       $at, $zero, 0xCEB
    ctx->r1 = ADD32(0, 0XCEB);
    // 0x808010F8: beq         $a3, $at, L_80801170
    if (ctx->r7 == ctx->r1) {
        // 0x808010FC: lw          $t8, 0x20($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X20);
            goto L_80801170;
    }
    // 0x808010FC: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80801100: b           L_80801194
    // 0x80801104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801194;
    // 0x80801104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801108:
    // 0x80801108: jal         0x80800DA8
    // 0x8080110C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800DA8_chstatueboss(rdram, ctx);
        goto after_1;
    // 0x8080110C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_1:
    // 0x80801110: b           L_80801194
    // 0x80801114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801194;
    // 0x80801114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801118:
    // 0x80801118: jal         0x80800DA8
    // 0x8080111C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800DA8_chstatueboss(rdram, ctx);
        goto after_2;
    // 0x8080111C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_2:
    // 0x80801120: b           L_80801194
    // 0x80801124: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801194;
    // 0x80801124: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801128:
    // 0x80801128: jal         0x80800DA8
    // 0x8080112C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800DA8_chstatueboss(rdram, ctx);
        goto after_3;
    // 0x8080112C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_3:
    // 0x80801130: b           L_80801194
    // 0x80801134: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801194;
    // 0x80801134: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801138:
    // 0x80801138: jal         0x80801E90
    // 0x8080113C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80801E90_chstatueboss(rdram, ctx);
        goto after_4;
    // 0x8080113C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_4:
    // 0x80801140: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801144: jal         0x80800DA8
    // 0x80801148: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    func_80800DA8_chstatueboss(rdram, ctx);
        goto after_5;
    // 0x80801148: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_5:
    // 0x8080114C: b           L_80801194
    // 0x80801150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801194;
    // 0x80801150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801154:
    // 0x80801154: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80801158: b           L_80801190
    // 0x8080115C: sb          $t7, 0x1CF($v0)
    MEM_B(0X1CF, ctx->r2) = ctx->r15;
        goto L_80801190;
    // 0x8080115C: sb          $t7, 0x1CF($v0)
    MEM_B(0X1CF, ctx->r2) = ctx->r15;
L_80801160:
    // 0x80801160: jal         0x80801E90
    // 0x80801164: nop

    func_80801E90_chstatueboss(rdram, ctx);
        goto after_6;
    // 0x80801164: nop

    after_6:
    // 0x80801168: b           L_80801194
    // 0x8080116C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801194;
    // 0x8080116C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801170:
    // 0x80801170: blez        $t8, L_80801188
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80801174: nop
    
            goto L_80801188;
    }
    // 0x80801174: nop

    // 0x80801178: jal         0x80088188
    // 0x8080117C: nop

    _gcfrontend_entrypoint_11(rdram, ctx);
        goto after_7;
    // 0x8080117C: nop

    after_7:
    // 0x80801180: b           L_80801194
    // 0x80801184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801194;
    // 0x80801184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801188:
    // 0x80801188: jal         0x80088180
    // 0x8080118C: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_8;
    // 0x8080118C: nop

    after_8:
L_80801190:
    // 0x80801190: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801194:
    // 0x80801194: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801198: jr          $ra
    // 0x8080119C: nop

    return;
    // 0x8080119C: nop

;}
RECOMP_FUNC void gcmapsects_lagoonmid_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800108: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080010C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800110: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80800114: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800118: jal         0x800E39A8
    // 0x8080011C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_800E39A8(rdram, ctx);
        goto after_0;
    // 0x8080011C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x80800120: jal         0x80013728
    // 0x80800124: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    func_80013728(rdram, ctx);
        goto after_1;
    // 0x80800124: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800128: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8080012C: jal         0x800136E4
    // 0x80800130: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    func_800136E4(rdram, ctx);
        goto after_2;
    // 0x80800130: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80800134: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x80800138: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8080013C: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800140: lbu         $v0, 0x7E($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X7E);
    // 0x80800144: lui         $at, 0x45FA
    ctx->r1 = S32(0X45FA << 16);
    // 0x80800148: beq         $v0, $zero, L_808001BC
    if (ctx->r2 == 0) {
        // 0x8080014C: nop
    
            goto L_808001BC;
    }
    // 0x8080014C: nop

    // 0x80800150: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800154: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x80800158: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8080015C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800160: nop

    // 0x80800164: bc1f        L_80800180
    if (!c1cs) {
        // 0x80800168: nop
    
            goto L_80800180;
    }
    // 0x80800168: nop

    // 0x8080016C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800170: nop

    // 0x80800174: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80800178: nop

    // 0x8080017C: bc1t        L_808001B4
    if (c1cs) {
        // 0x80800180: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2618, 0X220) << 16);
            goto L_808001B4;
    }
L_80800180:
    // 0x80800180: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2618, 0X220) << 16);
    // 0x80800184: lwc1        $f10, 0x220($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2618, 0X220));
    // 0x80800188: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8080018C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80800190: nop

    // 0x80800194: bc1f        L_808001BC
    if (!c1cs) {
        // 0x80800198: nop
    
            goto L_808001BC;
    }
    // 0x80800198: nop

    // 0x8080019C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x808001A0: nop

    // 0x808001A4: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x808001A8: nop

    // 0x808001AC: bc1f        L_808001BC
    if (!c1cs) {
        // 0x808001B0: nop
    
            goto L_808001BC;
    }
    // 0x808001B0: nop

L_808001B4:
    // 0x808001B4: sb          $zero, 0x7E($v1)
    MEM_B(0X7E, ctx->r3) = 0;
    // 0x808001B8: andi        $v0, $zero, 0xFF
    ctx->r2 = 0 & 0XFF;
L_808001BC:
    // 0x808001BC: beq         $v0, $zero, L_8080020C
    if (ctx->r2 == 0) {
        // 0x808001C0: lwc1        $f0, 0x30($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
            goto L_8080020C;
    }
    // 0x808001C0: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808001C4: lui         $at, 0x457A
    ctx->r1 = S32(0X457A << 16);
    // 0x808001C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808001CC: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x808001D0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808001D4: nop

    // 0x808001D8: bc1fl       L_80800210
    if (!c1cs) {
        // 0x808001DC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800210;
    }
    goto skip_0;
    // 0x808001DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808001E0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808001E4: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2618, 0X2F4) << 16);
    // 0x808001E8: addiu       $a0, $a0, 0x2F4
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2618, 0X2F4));
    // 0x808001EC: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x808001F0: lui         $a1, 0x4475
    ctx->r5 = S32(0X4475 << 16);
    // 0x808001F4: bc1fl       L_80800210
    if (!c1cs) {
        // 0x808001F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800210;
    }
    goto skip_1;
    // 0x808001F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808001FC: jal         0x800E3E8C
    // 0x80800200: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    func_800E3E8C(rdram, ctx);
        goto after_3;
    // 0x80800200: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    after_3:
    // 0x80800204: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80800208: sb          $v0, 0x7E($t6)
    MEM_B(0X7E, ctx->r14) = ctx->r2;
L_8080020C:
    // 0x8080020C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800210:
    // 0x80800210: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800214: jr          $ra
    // 0x80800218: nop

    return;
    // 0x80800218: nop

    // 0x8080021C: nop

;}
RECOMP_FUNC void func_80108B44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108B44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80108B48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80108B4C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80108B50: lhu         $t6, 0x12($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X12);
    // 0x80108B54: srl         $t7, $t6, 1
    ctx->r15 = S32(U32(ctx->r14) >> 1);
    // 0x80108B58: bnel        $a2, $t7, L_80108B80
    if (ctx->r6 != ctx->r15) {
        // 0x80108B5C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80108B80;
    }
    goto skip_0;
    // 0x80108B5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80108B60: jal         0x801069A4
    // 0x80108B64: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_801069A4(rdram, ctx);
        goto after_0;
    // 0x80108B64: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80108B68: beq         $v0, $zero, L_80108B7C
    if (ctx->r2 == 0) {
        // 0x80108B6C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80108B7C;
    }
    // 0x80108B6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80108B70: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    // 0x80108B74: jal         0x8010114C
    // 0x80108B78: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_8010114C(rdram, ctx);
        goto after_1;
    // 0x80108B78: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_1:
L_80108B7C:
    // 0x80108B7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80108B80:
    // 0x80108B80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80108B84: jr          $ra
    // 0x80108B88: nop

    return;
    // 0x80108B88: nop

;}
RECOMP_FUNC void _bsstonehead_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083BF0: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083BF0);
    return;
    // 0x80083BF4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80803484_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803484: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80803488: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8080348C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80803490: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80803494: jal         0x80100094
    // 0x80803498: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80803498: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080349C: jal         0x800D8FF8
    // 0x808034A0: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x808034A0: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    after_1:
    // 0x808034A4: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x808034A8: jal         0x80106790
    // 0x808034AC: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_2;
    // 0x808034AC: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_2:
    // 0x808034B0: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x808034B4: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x808034B8: jal         0x800BD2D0
    // 0x808034BC: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800BD2D0(rdram, ctx);
        goto after_3;
    // 0x808034BC: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_3:
    // 0x808034C0: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x808034C4: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x808034C8: lwc1        $f4, 0x4($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X4);
    // 0x808034CC: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x808034D0: swc1        $f6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f6.u32l;
    // 0x808034D4: lhu         $t8, 0x72($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X72);
    // 0x808034D8: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x808034DC: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x808034E0: sltiu       $at, $t0, 0xC
    ctx->r1 = ctx->r8 < 0XC ? 1 : 0;
    // 0x808034E4: beq         $at, $zero, L_80803CC8
    if (ctx->r1 == 0) {
        // 0x808034E8: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_80803CC8;
    }
    // 0x808034E8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x808034EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1840, 0X4BEC) << 16);
    // 0x808034F0: addu        $at, $at, $t0
    gpr jr_addend_808034F8 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x808034F4: lw          $t0, 0x4BEC($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1840, 0X4BEC));
    // 0x808034F8: jr          $t0
    // 0x808034FC: nop

    switch (jr_addend_808034F8 >> 2) {
        case 0: goto L_80803978; break;
        case 1: goto L_80803890; break;
        case 2: goto L_808039FC; break;
        case 3: goto L_80803A48; break;
        case 4: goto L_80803B78; break;
        case 5: goto L_80803B9C; break;
        case 6: goto L_80803BD8; break;
        case 7: goto L_80803658; break;
        case 8: goto L_80803C3C; break;
        case 9: goto L_80803500; break;
        case 10: goto L_80803CC8; break;
        case 11: goto L_80803804; break;
        default: switch_error(__func__, 0x808034F8, 0x80804BEC);
    }
    // 0x808034FC: nop

L_80803500:
    // 0x80803500: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80803504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803508: jal         0x80089BC0
    // 0x8080350C: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    _subaddiejoy_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x8080350C: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    after_4:
    // 0x80803510: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x80803514: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80803518: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8080351C: andi        $t1, $a1, 0x1FF
    ctx->r9 = ctx->r5 & 0X1FF;
    // 0x80803520: jal         0x80089AF8
    // 0x80803524: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    _sukickball_entrypoint_12(rdram, ctx);
        goto after_5;
    // 0x80803524: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    after_5:
    // 0x80803528: beq         $v0, $zero, L_80803558
    if (ctx->r2 == 0) {
        // 0x8080352C: nop
    
            goto L_80803558;
    }
    // 0x8080352C: nop

    // 0x80803530: jal         0x80800070
    // 0x80803534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800070_chcollballcontrol(rdram, ctx);
        goto after_6;
    // 0x80803534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80803538: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080353C: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80803540: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80803544: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80803548: jal         0x800F10B4
    // 0x8080354C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_800F10B4(rdram, ctx);
        goto after_7;
    // 0x8080354C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_7:
    // 0x80803550: b           L_8080357C
    // 0x80803554: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
        goto L_8080357C;
    // 0x80803554: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
L_80803558:
    // 0x80803558: jal         0x80800040
    // 0x8080355C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800040_chcollballcontrol(rdram, ctx);
        goto after_8;
    // 0x8080355C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80803560: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80803564: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80803568: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8080356C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80803570: jal         0x800F10B4
    // 0x80803574: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800F10B4(rdram, ctx);
        goto after_9;
    // 0x80803574: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_9:
    // 0x80803578: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
L_8080357C:
    // 0x8080357C: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x80803580: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80803584: andi        $t2, $a1, 0x1FF
    ctx->r10 = ctx->r5 & 0X1FF;
    // 0x80803588: jal         0x80089AF8
    // 0x8080358C: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    _sukickball_entrypoint_12(rdram, ctx);
        goto after_10;
    // 0x8080358C: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    after_10:
    // 0x80803590: beq         $v0, $zero, L_80803604
    if (ctx->r2 == 0) {
        // 0x80803594: lw          $t3, 0x64($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X64);
            goto L_80803604;
    }
    // 0x80803594: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x80803598: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x8080359C: jal         0x800BCFC4
    // 0x808035A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BCFC4(rdram, ctx);
        goto after_11;
    // 0x808035A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x808035A4: beq         $v0, $zero, L_80803604
    if (ctx->r2 == 0) {
        // 0x808035A8: lw          $t4, 0x64($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X64);
            goto L_80803604;
    }
    // 0x808035A8: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x808035AC: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x808035B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808035B4: jal         0x800BCD78
    // 0x808035B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800BCD78(rdram, ctx);
        goto after_12;
    // 0x808035B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_12:
    // 0x808035BC: jal         0x800D8FF8
    // 0x808035C0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_13;
    // 0x808035C0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_13:
    // 0x808035C4: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x808035C8: lui         $at, 0x4461
    ctx->r1 = S32(0X4461 << 16);
    // 0x808035CC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808035D0: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x808035D4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808035D8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808035DC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808035E0: lui         $a3, 0x43E1
    ctx->r7 = S32(0X43E1 << 16);
    // 0x808035E4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x808035E8: mul.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x808035EC: jal         0x800F10B4
    // 0x808035F0: nop

    func_800F10B4(rdram, ctx);
        goto after_14;
    // 0x808035F0: nop

    after_14:
    // 0x808035F4: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x808035F8: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x808035FC: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x80803600: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
L_80803604:
    // 0x80803604: jal         0x8080486C
    // 0x80803608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080486C_chcollballcontrol(rdram, ctx);
        goto after_15;
    // 0x80803608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x8080360C: jal         0x8080009C
    // 0x80803610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080009C_chcollballcontrol(rdram, ctx);
        goto after_16;
    // 0x80803610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80803614: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x80803618: jal         0x80800040
    // 0x8080361C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800040_chcollballcontrol(rdram, ctx);
        goto after_17;
    // 0x8080361C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80803620: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80803624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803628: jal         0x80089AA8
    // 0x8080362C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    _sukickball_entrypoint_2(rdram, ctx);
        goto after_18;
    // 0x8080362C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_18:
    // 0x80803630: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x80803634: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80803638: jal         0x800BD030
    // 0x8080363C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    func_800BD030(rdram, ctx);
        goto after_19;
    // 0x8080363C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_19:
    // 0x80803640: beq         $v0, $zero, L_80803CC8
    if (ctx->r2 == 0) {
        // 0x80803644: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803CC8;
    }
    // 0x80803644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803648: jal         0x8080324C
    // 0x8080364C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_8080324C_chcollballcontrol(rdram, ctx);
        goto after_20;
    // 0x8080364C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_20:
    // 0x80803650: b           L_80803CCC
    // 0x80803654: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
        goto L_80803CCC;
    // 0x80803654: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
L_80803658:
    // 0x80803658: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8080365C: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80803660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803664: lui         $a1, 0x3E9D
    ctx->r5 = S32(0X3E9D << 16);
    // 0x80803668: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
    // 0x8080366C: nop

    // 0x80803670: bc1fl       L_80803704
    if (!c1cs) {
        // 0x80803674: c.eq.s      $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
            goto L_80803704;
    }
    goto skip_0;
    // 0x80803674: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
    skip_0:
    // 0x80803678: jal         0x80101E14
    // 0x8080367C: ori         $a1, $a1, 0x8ADB
    ctx->r5 = ctx->r5 | 0X8ADB;
    func_80101E14(rdram, ctx);
        goto after_21;
    // 0x8080367C: ori         $a1, $a1, 0x8ADB
    ctx->r5 = ctx->r5 | 0X8ADB;
    after_21:
    // 0x80803680: beql        $v0, $zero, L_808036F8
    if (ctx->r2 == 0) {
        // 0x80803684: mtc1        $zero, $f12
        ctx->f12.u32l = 0;
            goto L_808036F8;
    }
    goto skip_1;
    // 0x80803684: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    skip_1:
    // 0x80803688: jal         0x80104248
    // 0x8080368C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_22;
    // 0x8080368C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80803690: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803694: jal         0x8008B134
    // 0x80803698: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_23;
    // 0x80803698: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_23:
    // 0x8080369C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808036A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808036A4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1840, 0X4C1C) << 16);
    // 0x808036A8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x808036AC: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
    // 0x808036B0: lwc1        $f6, 0x4C1C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1840, 0X4C1C));
    // 0x808036B4: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x808036B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808036BC: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x808036C0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1840, 0X50B0) << 16);
    // 0x808036C4: addiu       $t0, $zero, 0x7D
    ctx->r8 = ADD32(0, 0X7D);
    // 0x808036C8: addiu       $t1, $zero, 0xFA
    ctx->r9 = ADD32(0, 0XFA);
    // 0x808036CC: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x808036D0: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x808036D4: addiu       $a2, $a2, 0x50B0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1840, 0X50B0));
    // 0x808036D8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x808036DC: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808036E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808036E4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808036E8: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x808036EC: jal         0x800B4470
    // 0x808036F0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800B4470(rdram, ctx);
        goto after_24;
    // 0x808036F0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_24:
    // 0x808036F4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
L_808036F8:
    // 0x808036F8: b           L_80803784
    // 0x808036FC: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
        goto L_80803784;
    // 0x808036FC: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80803700: c.eq.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl == ctx->f0.fl;
L_80803704:
    // 0x80803704: nop

    // 0x80803708: bc1tl       L_80803788
    if (c1cs) {
        // 0x8080370C: lwc1        $f16, 0x24($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
            goto L_80803788;
    }
    goto skip_2;
    // 0x8080370C: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    skip_2:
    // 0x80803710: add.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80803714: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80803718: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080371C: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80803720: swc1        $f16, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f16.u32l;
    // 0x80803724: lwc1        $f4, 0x50($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80803728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080372C: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80803730: nop

    // 0x80803734: bc1t        L_80803758
    if (c1cs) {
        // 0x80803738: nop
    
            goto L_80803758;
    }
    // 0x80803738: nop

    // 0x8080373C: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80803740: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80803744: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1840, 0X4C20) << 16);
    // 0x80803748: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8080374C: nop

    // 0x80803750: bc1f        L_80803778
    if (!c1cs) {
        // 0x80803754: nop
    
            goto L_80803778;
    }
    // 0x80803754: nop

L_80803758:
    // 0x80803758: jal         0x8080324C
    // 0x8080375C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8080324C_chcollballcontrol(rdram, ctx);
        goto after_25;
    // 0x8080375C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_25:
    // 0x80803760: jal         0x8080009C
    // 0x80803764: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080009C_chcollballcontrol(rdram, ctx);
        goto after_26;
    // 0x80803764: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80803768: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x8080376C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80803770: b           L_80803784
    // 0x80803774: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
        goto L_80803784;
    // 0x80803774: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
L_80803778:
    // 0x80803778: lwc1        $f8, 0x4C20($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1840, 0X4C20));
    // 0x8080377C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80803780: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
L_80803784:
    // 0x80803784: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
L_80803788:
    // 0x80803788: swc1        $f12, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f12.u32l;
    // 0x8080378C: addiu       $a3, $s0, 0x28
    ctx->r7 = ADD32(ctx->r16, 0X28);
    // 0x80803790: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80803794: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80803798: addiu       $t2, $s0, 0x4
    ctx->r10 = ADD32(ctx->r16, 0X4);
    // 0x8080379C: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x808037A0: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x808037A4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808037A8: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x808037AC: jal         0x800EEB9C
    // 0x808037B0: nop

    func_800EEB9C(rdram, ctx);
        goto after_27;
    // 0x808037B0: nop

    after_27:
    // 0x808037B4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x808037B8: jal         0x800EF04C
    // 0x808037BC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    func_800EF04C(rdram, ctx);
        goto after_28;
    // 0x808037BC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_28:
    // 0x808037C0: lw          $t3, 0x64($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X64);
    // 0x808037C4: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x808037C8: bgez        $t5, L_808037F4
    if (SIGNED(ctx->r13) >= 0) {
        // 0x808037CC: nop
    
            goto L_808037F4;
    }
    // 0x808037CC: nop

    // 0x808037D0: jal         0x80089BC0
    // 0x808037D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiejoy_entrypoint_3(rdram, ctx);
        goto after_29;
    // 0x808037D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x808037D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808037DC: jal         0x80102CF4
    // 0x808037E0: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    func_80102CF4(rdram, ctx);
        goto after_30;
    // 0x808037E0: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    after_30:
    // 0x808037E4: bne         $v0, $zero, L_808037F4
    if (ctx->r2 != 0) {
        // 0x808037E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808037F4;
    }
    // 0x808037E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808037EC: jal         0x80102B2C
    // 0x808037F0: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    func_80102B2C(rdram, ctx);
        goto after_31;
    // 0x808037F0: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    after_31:
L_808037F4:
    // 0x808037F4: jal         0x8080405C
    // 0x808037F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080405C_chcollballcontrol(rdram, ctx);
        goto after_32;
    // 0x808037F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x808037FC: b           L_80803CCC
    // 0x80803800: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
        goto L_80803CCC;
    // 0x80803800: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
L_80803804:
    // 0x80803804: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80803808: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080380C: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80803810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803814: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1840, 0X4C24) << 16);
    // 0x80803818: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8080381C: nop

    // 0x80803820: bc1f        L_80803844
    if (!c1cs) {
        // 0x80803824: nop
    
            goto L_80803844;
    }
    // 0x80803824: nop

    // 0x80803828: jal         0x8080324C
    // 0x8080382C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8080324C_chcollballcontrol(rdram, ctx);
        goto after_33;
    // 0x8080382C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_33:
    // 0x80803830: jal         0x8080009C
    // 0x80803834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080009C_chcollballcontrol(rdram, ctx);
        goto after_34;
    // 0x80803834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x80803838: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x8080383C: b           L_80803850
    // 0x80803840: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
        goto L_80803850;
    // 0x80803840: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
L_80803844:
    // 0x80803844: lwc1        $f6, 0x4C24($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1840, 0X4C24));
    // 0x80803848: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8080384C: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
L_80803850:
    // 0x80803850: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80803854: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80803858: addiu       $a3, $s0, 0x28
    ctx->r7 = ADD32(ctx->r16, 0X28);
    // 0x8080385C: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80803860: lw          $a1, 0x54($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X54);
    // 0x80803864: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
    // 0x80803868: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x8080386C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80803870: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80803874: jal         0x800EEB9C
    // 0x80803878: nop

    func_800EEB9C(rdram, ctx);
        goto after_35;
    // 0x80803878: nop

    after_35:
    // 0x8080387C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80803880: jal         0x800EF04C
    // 0x80803884: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_36;
    // 0x80803884: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_36:
    // 0x80803888: b           L_80803CCC
    // 0x8080388C: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
        goto L_80803CCC;
    // 0x8080388C: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
L_80803890:
    // 0x80803890: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x80803894: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803898: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8080389C: bgez        $t8, L_808038B8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808038A0: nop
    
            goto L_808038B8;
    }
    // 0x808038A0: nop

    // 0x808038A4: jal         0x8080324C
    // 0x808038A8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_8080324C_chcollballcontrol(rdram, ctx);
        goto after_37;
    // 0x808038A8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_37:
    // 0x808038AC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808038B0: nop

    // 0x808038B4: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_808038B8:
    // 0x808038B8: jal         0x8080451C
    // 0x808038BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080451C_chcollballcontrol(rdram, ctx);
        goto after_38;
    // 0x808038BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_38:
    // 0x808038C0: bne         $v0, $zero, L_808038D0
    if (ctx->r2 != 0) {
        // 0x808038C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808038D0;
    }
    // 0x808038C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808038C8: jal         0x8080324C
    // 0x808038CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8080324C_chcollballcontrol(rdram, ctx);
        goto after_39;
    // 0x808038CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_39:
L_808038D0:
    // 0x808038D0: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x808038D4: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x808038D8: andi        $t9, $a1, 0x1FF
    ctx->r25 = ctx->r5 & 0X1FF;
    // 0x808038DC: jal         0x80089AF8
    // 0x808038E0: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    _sukickball_entrypoint_12(rdram, ctx);
        goto after_40;
    // 0x808038E0: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_40:
    // 0x808038E4: beq         $v0, $zero, L_80803944
    if (ctx->r2 == 0) {
        // 0x808038E8: nop
    
            goto L_80803944;
    }
    // 0x808038E8: nop

    // 0x808038EC: jal         0x800DC0C0
    // 0x808038F0: nop

    func_800DC0C0(rdram, ctx);
        goto after_41;
    // 0x808038F0: nop

    after_41:
    // 0x808038F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1840, 0X4C28) << 16);
    // 0x808038F8: lwc1        $f6, 0x4C28($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1840, 0X4C28));
    // 0x808038FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803900: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80803904: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80803908: nop

    // 0x8080390C: bc1fl       L_80803928
    if (!c1cs) {
        // 0x80803910: mtc1        $zero, $f12
        ctx->f12.u32l = 0;
            goto L_80803928;
    }
    goto skip_3;
    // 0x80803910: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    skip_3:
    // 0x80803914: jal         0x8080324C
    // 0x80803918: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_8080324C_chcollballcontrol(rdram, ctx);
        goto after_42;
    // 0x80803918: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_42:
    // 0x8080391C: b           L_80803944
    // 0x80803920: nop

        goto L_80803944;
    // 0x80803920: nop

    // 0x80803924: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
L_80803928:
    // 0x80803928: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080392C: jal         0x800DC178
    // 0x80803930: nop

    func_800DC178(rdram, ctx);
        goto after_43;
    // 0x80803930: nop

    after_43:
    // 0x80803934: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x80803938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080393C: jal         0x8080324C
    // 0x80803940: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8080324C_chcollballcontrol(rdram, ctx);
        goto after_44;
    // 0x80803940: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_44:
L_80803944:
    // 0x80803944: jal         0x8080486C
    // 0x80803948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080486C_chcollballcontrol(rdram, ctx);
        goto after_45;
    // 0x80803948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_45:
    // 0x8080394C: jal         0x8080009C
    // 0x80803950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080009C_chcollballcontrol(rdram, ctx);
        goto after_46;
    // 0x80803950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_46:
    // 0x80803954: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x80803958: jal         0x80800040
    // 0x8080395C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800040_chcollballcontrol(rdram, ctx);
        goto after_47;
    // 0x8080395C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_47:
    // 0x80803960: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80803964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803968: jal         0x80089AA8
    // 0x8080396C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    _sukickball_entrypoint_2(rdram, ctx);
        goto after_48;
    // 0x8080396C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_48:
    // 0x80803970: b           L_80803CCC
    // 0x80803974: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
        goto L_80803CCC;
    // 0x80803974: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
L_80803978:
    // 0x80803978: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x8080397C: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80803980: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80803984: andi        $t0, $a0, 0x1FF
    ctx->r8 = ctx->r4 & 0X1FF;
    // 0x80803988: jal         0x80089B18
    // 0x8080398C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    _sukickball_entrypoint_16(rdram, ctx);
        goto after_49;
    // 0x8080398C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_49:
    // 0x80803990: jal         0x8080486C
    // 0x80803994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080486C_chcollballcontrol(rdram, ctx);
        goto after_50;
    // 0x80803994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_50:
    // 0x80803998: jal         0x8080009C
    // 0x8080399C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080009C_chcollballcontrol(rdram, ctx);
        goto after_51;
    // 0x8080399C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_51:
    // 0x808039A0: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x808039A4: jal         0x80800040
    // 0x808039A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800040_chcollballcontrol(rdram, ctx);
        goto after_52;
    // 0x808039A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_52:
    // 0x808039AC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808039B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808039B4: jal         0x80089AA8
    // 0x808039B8: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    _sukickball_entrypoint_2(rdram, ctx);
        goto after_53;
    // 0x808039B8: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_53:
    // 0x808039BC: jal         0x8080451C
    // 0x808039C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080451C_chcollballcontrol(rdram, ctx);
        goto after_54;
    // 0x808039C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_54:
    // 0x808039C4: beq         $v0, $zero, L_808039D4
    if (ctx->r2 == 0) {
        // 0x808039C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808039D4;
    }
    // 0x808039C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808039CC: jal         0x8080324C
    // 0x808039D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8080324C_chcollballcontrol(rdram, ctx);
        goto after_55;
    // 0x808039D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_55:
L_808039D4:
    // 0x808039D4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808039D8: lui         $a1, 0x4248
    ctx->r5 = S32(0X4248 << 16);
    // 0x808039DC: jal         0x800EFFB4
    // 0x808039E0: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    func_800EFFB4(rdram, ctx);
        goto after_56;
    // 0x808039E0: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    after_56:
    // 0x808039E4: beq         $v0, $zero, L_80803CC8
    if (ctx->r2 == 0) {
        // 0x808039E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803CC8;
    }
    // 0x808039E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808039EC: jal         0x8080324C
    // 0x808039F0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8080324C_chcollballcontrol(rdram, ctx);
        goto after_57;
    // 0x808039F0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_57:
    // 0x808039F4: b           L_80803CCC
    // 0x808039F8: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
        goto L_80803CCC;
    // 0x808039F8: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
L_808039FC:
    // 0x808039FC: jal         0x8080451C
    // 0x80803A00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080451C_chcollballcontrol(rdram, ctx);
        goto after_58;
    // 0x80803A00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_58:
    // 0x80803A04: beq         $v0, $zero, L_80803A14
    if (ctx->r2 == 0) {
        // 0x80803A08: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803A14;
    }
    // 0x80803A08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803A0C: jal         0x8080324C
    // 0x80803A10: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8080324C_chcollballcontrol(rdram, ctx);
        goto after_59;
    // 0x80803A10: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_59:
L_80803A14:
    // 0x80803A14: jal         0x80089B08
    // 0x80803A18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sukickball_entrypoint_14(rdram, ctx);
        goto after_60;
    // 0x80803A18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_60:
    // 0x80803A1C: jal         0x8080009C
    // 0x80803A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080009C_chcollballcontrol(rdram, ctx);
        goto after_61;
    // 0x80803A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_61:
    // 0x80803A24: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x80803A28: jal         0x80800040
    // 0x80803A2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800040_chcollballcontrol(rdram, ctx);
        goto after_62;
    // 0x80803A2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_62:
    // 0x80803A30: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80803A34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803A38: jal         0x80089AA8
    // 0x80803A3C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    _sukickball_entrypoint_2(rdram, ctx);
        goto after_63;
    // 0x80803A3C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_63:
    // 0x80803A40: b           L_80803CCC
    // 0x80803A44: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
        goto L_80803CCC;
    // 0x80803A44: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
L_80803A48:
    // 0x80803A48: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(1840, 0X50A4) << 16);
    // 0x80803A4C: addiu       $t2, $t2, 0x50A4
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(1840, 0X50A4));
    // 0x80803A50: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x80803A54: addiu       $t1, $sp, 0x50
    ctx->r9 = ADD32(ctx->r29, 0X50);
    // 0x80803A58: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80803A5C: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x80803A60: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x80803A64: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x80803A68: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80803A6C: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    // 0x80803A70: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80803A74: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80803A78: nop

    // 0x80803A7C: bc1fl       L_80803A94
    if (!c1cs) {
        // 0x80803A80: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803A94;
    }
    goto skip_4;
    // 0x80803A80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_4:
    // 0x80803A84: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80803A88: b           L_80803A9C
    // 0x80803A8C: swc1        $f10, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f10.u32l;
        goto L_80803A9C;
    // 0x80803A8C: swc1        $f10, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f10.u32l;
    // 0x80803A90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80803A94:
    // 0x80803A94: jal         0x8080324C
    // 0x80803A98: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_8080324C_chcollballcontrol(rdram, ctx);
        goto after_64;
    // 0x80803A98: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_64:
L_80803A9C:
    // 0x80803A9C: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x80803AA0: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80803AA4: andi        $t6, $a1, 0x1FF
    ctx->r14 = ctx->r5 & 0X1FF;
    // 0x80803AA8: jal         0x80089AF8
    // 0x80803AAC: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    _sukickball_entrypoint_12(rdram, ctx);
        goto after_65;
    // 0x80803AAC: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_65:
    // 0x80803AB0: bne         $v0, $zero, L_80803AC0
    if (ctx->r2 != 0) {
        // 0x80803AB4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803AC0;
    }
    // 0x80803AB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803AB8: jal         0x8080324C
    // 0x80803ABC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8080324C_chcollballcontrol(rdram, ctx);
        goto after_66;
    // 0x80803ABC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_66:
L_80803AC0:
    // 0x80803AC0: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x80803AC4: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80803AC8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80803ACC: andi        $t7, $a0, 0x1FF
    ctx->r15 = ctx->r4 & 0X1FF;
    // 0x80803AD0: jal         0x80089B18
    // 0x80803AD4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    _sukickball_entrypoint_16(rdram, ctx);
        goto after_67;
    // 0x80803AD4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_67:
    // 0x80803AD8: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x80803ADC: andi        $t8, $a0, 0x1FF
    ctx->r24 = ctx->r4 & 0X1FF;
    // 0x80803AE0: jal         0x80089B10
    // 0x80803AE4: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    _sukickball_entrypoint_15(rdram, ctx);
        goto after_68;
    // 0x80803AE4: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_68:
    // 0x80803AE8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80803AEC: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80803AF0: jal         0x800EFCD8
    // 0x80803AF4: lui         $a2, 0x437A
    ctx->r6 = S32(0X437A << 16);
    func_800EFCD8(rdram, ctx);
        goto after_69;
    // 0x80803AF4: lui         $a2, 0x437A
    ctx->r6 = S32(0X437A << 16);
    after_69:
    // 0x80803AF8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80803AFC: jal         0x800EF04C
    // 0x80803B00: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    func_800EF04C(rdram, ctx);
        goto after_70;
    // 0x80803B00: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_70:
    // 0x80803B04: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80803B08: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x80803B0C: jal         0x800F0064
    // 0x80803B10: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    func_800F0064(rdram, ctx);
        goto after_71;
    // 0x80803B10: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    after_71:
    // 0x80803B14: bnel        $v0, $zero, L_80803B3C
    if (ctx->r2 != 0) {
        // 0x80803B18: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803B3C;
    }
    goto skip_5;
    // 0x80803B18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_5:
    // 0x80803B1C: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x80803B20: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80803B24: andi        $t9, $a1, 0x1FF
    ctx->r25 = ctx->r5 & 0X1FF;
    // 0x80803B28: jal         0x80089AF8
    // 0x80803B2C: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    _sukickball_entrypoint_12(rdram, ctx);
        goto after_72;
    // 0x80803B2C: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_72:
    // 0x80803B30: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80803B34: bne         $v0, $at, L_80803B44
    if (ctx->r2 != ctx->r1) {
        // 0x80803B38: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803B44;
    }
    // 0x80803B38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80803B3C:
    // 0x80803B3C: jal         0x8080324C
    // 0x80803B40: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_8080324C_chcollballcontrol(rdram, ctx);
        goto after_73;
    // 0x80803B40: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_73:
L_80803B44:
    // 0x80803B44: jal         0x8080486C
    // 0x80803B48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080486C_chcollballcontrol(rdram, ctx);
        goto after_74;
    // 0x80803B48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_74:
    // 0x80803B4C: jal         0x8080009C
    // 0x80803B50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080009C_chcollballcontrol(rdram, ctx);
        goto after_75;
    // 0x80803B50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_75:
    // 0x80803B54: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x80803B58: jal         0x80800040
    // 0x80803B5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800040_chcollballcontrol(rdram, ctx);
        goto after_76;
    // 0x80803B5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_76:
    // 0x80803B60: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80803B64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803B68: jal         0x80089AA8
    // 0x80803B6C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    _sukickball_entrypoint_2(rdram, ctx);
        goto after_77;
    // 0x80803B6C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_77:
    // 0x80803B70: b           L_80803CCC
    // 0x80803B74: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
        goto L_80803CCC;
    // 0x80803B74: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
L_80803B78:
    // 0x80803B78: jal         0x80803E18
    // 0x80803B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803E18_chcollballcontrol(rdram, ctx);
        goto after_78;
    // 0x80803B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_78:
    // 0x80803B80: jal         0x80803F70
    // 0x80803B84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803F70_chcollballcontrol(rdram, ctx);
        goto after_79;
    // 0x80803B84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_79:
    // 0x80803B88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803B8C: jal         0x8080324C
    // 0x80803B90: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_8080324C_chcollballcontrol(rdram, ctx);
        goto after_80;
    // 0x80803B90: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_80:
    // 0x80803B94: b           L_80803CCC
    // 0x80803B98: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
        goto L_80803CCC;
    // 0x80803B98: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
L_80803B9C:
    // 0x80803B9C: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x80803BA0: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80803BA4: andi        $t0, $a1, 0x1FF
    ctx->r8 = ctx->r5 & 0X1FF;
    // 0x80803BA8: jal         0x80089AF8
    // 0x80803BAC: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    _sukickball_entrypoint_12(rdram, ctx);
        goto after_81;
    // 0x80803BAC: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    after_81:
    // 0x80803BB0: beq         $v0, $zero, L_80803BC8
    if (ctx->r2 == 0) {
        // 0x80803BB4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803BC8;
    }
    // 0x80803BB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803BB8: jal         0x80803F70
    // 0x80803BBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803F70_chcollballcontrol(rdram, ctx);
        goto after_82;
    // 0x80803BBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_82:
    // 0x80803BC0: b           L_80803CCC
    // 0x80803BC4: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
        goto L_80803CCC;
    // 0x80803BC4: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
L_80803BC8:
    // 0x80803BC8: jal         0x8080324C
    // 0x80803BCC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8080324C_chcollballcontrol(rdram, ctx);
        goto after_83;
    // 0x80803BCC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_83:
    // 0x80803BD0: b           L_80803CCC
    // 0x80803BD4: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
        goto L_80803CCC;
    // 0x80803BD4: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
L_80803BD8:
    // 0x80803BD8: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80803BDC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80803BE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803BE4: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80803BE8: nop

    // 0x80803BEC: bc1f        L_80803C00
    if (!c1cs) {
        // 0x80803BF0: nop
    
            goto L_80803C00;
    }
    // 0x80803BF0: nop

    // 0x80803BF4: sub.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80803BF8: b           L_80803C08
    // 0x80803BFC: swc1        $f18, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f18.u32l;
        goto L_80803C08;
    // 0x80803BFC: swc1        $f18, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f18.u32l;
L_80803C00:
    // 0x80803C00: jal         0x8080324C
    // 0x80803C04: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8080324C_chcollballcontrol(rdram, ctx);
        goto after_84;
    // 0x80803C04: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_84:
L_80803C08:
    // 0x80803C08: jal         0x8080486C
    // 0x80803C0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080486C_chcollballcontrol(rdram, ctx);
        goto after_85;
    // 0x80803C0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_85:
    // 0x80803C10: jal         0x8080009C
    // 0x80803C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080009C_chcollballcontrol(rdram, ctx);
        goto after_86;
    // 0x80803C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_86:
    // 0x80803C18: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x80803C1C: jal         0x80800040
    // 0x80803C20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800040_chcollballcontrol(rdram, ctx);
        goto after_87;
    // 0x80803C20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_87:
    // 0x80803C24: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80803C28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803C2C: jal         0x80089AA8
    // 0x80803C30: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    _sukickball_entrypoint_2(rdram, ctx);
        goto after_88;
    // 0x80803C30: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_88:
    // 0x80803C34: b           L_80803CCC
    // 0x80803C38: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
        goto L_80803CCC;
    // 0x80803C38: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
L_80803C3C:
    // 0x80803C3C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80803C40: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80803C44: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80803C48: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80803C4C: lbu         $t4, 0x65($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X65);
    // 0x80803C50: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80803C54: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80803C58: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80803C5C: andi        $t3, $t4, 0xFFEF
    ctx->r11 = ctx->r12 & 0XFFEF;
    // 0x80803C60: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
    // 0x80803C64: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    // 0x80803C68: bc1f        L_80803C84
    if (!c1cs) {
        // 0x80803C6C: swc1        $f8, 0x48($s0)
        MEM_W(0X48, ctx->r16) = ctx->f8.u32l;
            goto L_80803C84;
    }
    // 0x80803C6C: swc1        $f8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f8.u32l;
    // 0x80803C70: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1840, 0X4C2C) << 16);
    // 0x80803C74: lwc1        $f16, 0x4C2C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1840, 0X4C2C));
    // 0x80803C78: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80803C7C: b           L_80803CC8
    // 0x80803C80: swc1        $f18, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f18.u32l;
        goto L_80803CC8;
    // 0x80803C80: swc1        $f18, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f18.u32l;
L_80803C84:
    // 0x80803C84: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80803C88: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80803C8C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1840, 0X4C30) << 16);
    // 0x80803C90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803C94: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80803C98: nop

    // 0x80803C9C: bc1f        L_80803CB4
    if (!c1cs) {
        // 0x80803CA0: nop
    
            goto L_80803CB4;
    }
    // 0x80803CA0: nop

    // 0x80803CA4: lwc1        $f6, 0x4C30($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1840, 0X4C30));
    // 0x80803CA8: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80803CAC: b           L_80803CC8
    // 0x80803CB0: swc1        $f8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f8.u32l;
        goto L_80803CC8;
    // 0x80803CB0: swc1        $f8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f8.u32l;
L_80803CB4:
    // 0x80803CB4: jal         0x8080324C
    // 0x80803CB8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8080324C_chcollballcontrol(rdram, ctx);
        goto after_89;
    // 0x80803CB8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_89:
    // 0x80803CBC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80803CC0: nop

    // 0x80803CC4: swc1        $f10, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f10.u32l;
L_80803CC8:
    // 0x80803CC8: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
L_80803CCC:
    // 0x80803CCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803CD0: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80803CD4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80803CD8: jal         0x80089AC0
    // 0x80803CDC: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    _sukickball_entrypoint_5(rdram, ctx);
        goto after_90;
    // 0x80803CDC: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    after_90:
    // 0x80803CE0: beq         $v0, $zero, L_80803D34
    if (ctx->r2 == 0) {
        // 0x80803CE4: lw          $a2, 0x3C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X3C);
            goto L_80803D34;
    }
    // 0x80803CE4: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80803CE8: lhu         $t1, 0x72($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X72);
    // 0x80803CEC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80803CF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803CF4: srl         $t2, $t1, 10
    ctx->r10 = S32(U32(ctx->r9) >> 10);
    // 0x80803CF8: bnel        $t2, $at, L_80803D14
    if (ctx->r10 != ctx->r1) {
        // 0x80803CFC: lw          $t5, 0x64($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X64);
            goto L_80803D14;
    }
    goto skip_6;
    // 0x80803CFC: lw          $t5, 0x64($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X64);
    skip_6:
    // 0x80803D00: jal         0x8080324C
    // 0x80803D04: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8080324C_chcollballcontrol(rdram, ctx);
        goto after_91;
    // 0x80803D04: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_91:
    // 0x80803D08: b           L_80803D44
    // 0x80803D0C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_80803D44;
    // 0x80803D0C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80803D10: lw          $t5, 0x64($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X64);
L_80803D14:
    // 0x80803D14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803D18: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80803D1C: bltzl       $t7, L_80803D44
    if (SIGNED(ctx->r15) < 0) {
        // 0x80803D20: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80803D44;
    }
    goto skip_7;
    // 0x80803D20: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_7:
    // 0x80803D24: jal         0x808032CC
    // 0x80803D28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808032CC_chcollballcontrol(rdram, ctx);
        goto after_92;
    // 0x80803D28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_92:
    // 0x80803D2C: b           L_80803D44
    // 0x80803D30: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_80803D44;
    // 0x80803D30: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80803D34:
    // 0x80803D34: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80803D38: jal         0x800EE7F8
    // 0x80803D3C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_93;
    // 0x80803D3C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_93:
    // 0x80803D40: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80803D44:
    // 0x80803D44: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80803D48: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80803D4C: jr          $ra
    // 0x80803D50: nop

    return;
    // 0x80803D50: nop

;}
RECOMP_FUNC void func_800EE670(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EE670: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800EE674: lw          $a0, 0x7EF8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7EF8);
    // 0x800EE678: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800EE67C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800EE680: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800EE684: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800EE688: beq         $a0, $zero, L_800EE700
    if (ctx->r4 == 0) {
        // 0x800EE68C: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_800EE700;
    }
    // 0x800EE68C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800EE690: jal         0x800B296C
    // 0x800EE694: nop

    vector_end(rdram, ctx);
        goto after_0;
    // 0x800EE694: nop

    after_0:
    // 0x800EE698: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800EE69C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800EE6A0: jal         0x800B28C4
    // 0x800EE6A4: lw          $a0, 0x7EF8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7EF8);
    vector_begin(rdram, ctx);
        goto after_1;
    // 0x800EE6A4: lw          $a0, 0x7EF8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7EF8);
    after_1:
    // 0x800EE6A8: sltu        $at, $v0, $s2
    ctx->r1 = ctx->r2 < ctx->r18 ? 1 : 0;
    // 0x800EE6AC: beq         $at, $zero, L_800EE6EC
    if (ctx->r1 == 0) {
        // 0x800EE6B0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800EE6EC;
    }
    // 0x800EE6B0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800EE6B4: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800EE6B8: addiu       $s1, $s1, 0x3590
    ctx->r17 = ADD32(ctx->r17, 0X3590);
    // 0x800EE6BC: lbu         $t6, 0x6($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X6);
L_800EE6C0:
    // 0x800EE6C0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800EE6C4: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x800EE6C8: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x800EE6CC: beql        $v0, $zero, L_800EE6E0
    if (ctx->r2 == 0) {
        // 0x800EE6D0: addiu       $s0, $s0, 0xA8
        ctx->r16 = ADD32(ctx->r16, 0XA8);
            goto L_800EE6E0;
    }
    goto skip_0;
    // 0x800EE6D0: addiu       $s0, $s0, 0xA8
    ctx->r16 = ADD32(ctx->r16, 0XA8);
    skip_0:
    // 0x800EE6D4: jalr        $v0
    // 0x800EE6D8: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_2;
    // 0x800EE6D8: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    after_2:
    // 0x800EE6DC: addiu       $s0, $s0, 0xA8
    ctx->r16 = ADD32(ctx->r16, 0XA8);
L_800EE6E0:
    // 0x800EE6E0: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x800EE6E4: bnel        $at, $zero, L_800EE6C0
    if (ctx->r1 != 0) {
        // 0x800EE6E8: lbu         $t6, 0x6($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X6);
            goto L_800EE6C0;
    }
    goto skip_1;
    // 0x800EE6E8: lbu         $t6, 0x6($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X6);
    skip_1:
L_800EE6EC:
    // 0x800EE6EC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800EE6F0: jal         0x800B2F58
    // 0x800EE6F4: lw          $a0, 0x7EF8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7EF8);
    vector_defrag(rdram, ctx);
        goto after_3;
    // 0x800EE6F4: lw          $a0, 0x7EF8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7EF8);
    after_3:
    // 0x800EE6F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800EE6FC: sw          $v0, 0x7EF8($at)
    MEM_W(0X7EF8, ctx->r1) = ctx->r2;
L_800EE700:
    // 0x800EE700: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800EE704: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800EE708: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800EE70C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800EE710: jr          $ra
    // 0x800EE714: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800EE714: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80800960_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800960: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800964: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800968: jal         0x80800694
    // 0x8080096C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800694_bstnt(rdram, ctx);
        goto after_0;
    // 0x8080096C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800970: jal         0x80800060
    // 0x80800974: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800060_bstnt(rdram, ctx);
        goto after_1;
    // 0x80800974: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800978: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080097C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800980: jal         0x808007EC
    // 0x80800984: sw          $zero, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = 0;
    func_808007EC_bstnt(rdram, ctx);
        goto after_2;
    // 0x80800984: sw          $zero, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = 0;
    after_2:
    // 0x80800988: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080098C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800990: jr          $ra
    // 0x80800994: nop

    return;
    // 0x80800994: nop

;}
RECOMP_FUNC void _bamovegoto_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084DE8: syscall     137
    recomp_syscall_handler(rdram, ctx, 0x80084DE8);
    return;
    // 0x80084DEC: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_808002DC_cheggclockwork(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808002E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002E8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808002EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002F0: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x808002F4: jal         0x80100094
    // 0x808002F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808002F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808002FC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80800300: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800304: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800308: beq         $a2, $at, L_8080032C
    if (ctx->r6 == ctx->r1) {
        // 0x8080030C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080032C;
    }
    // 0x8080030C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800310: beq         $a2, $at, L_80800368
    if (ctx->r6 == ctx->r1) {
        // 0x80800314: lw          $t7, 0x24($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X24);
            goto L_80800368;
    }
    // 0x80800314: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80800318: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080031C: beq         $a2, $at, L_80800398
    if (ctx->r6 == ctx->r1) {
        // 0x80800320: nop
    
            goto L_80800398;
    }
    // 0x80800320: nop

    // 0x80800324: b           L_808003A4
    // 0x80800328: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808003A4;
    // 0x80800328: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080032C:
    // 0x8080032C: jal         0x80800270
    // 0x80800330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800270_cheggclockwork(rdram, ctx);
        goto after_1;
    // 0x80800330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800334: beq         $v0, $zero, L_80800358
    if (ctx->r2 == 0) {
        // 0x80800338: nop
    
            goto L_80800358;
    }
    // 0x80800338: nop

    // 0x8080033C: jal         0x808006E8
    // 0x80800340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808006E8_cheggclockwork(rdram, ctx);
        goto after_2;
    // 0x80800340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800344: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80800348: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    // 0x8080034C: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80800350: jal         0x800F7CF4
    // 0x80800354: lh          $a0, 0x3A($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X3A);
    func_800F7CF4(rdram, ctx);
        goto after_3;
    // 0x80800354: lh          $a0, 0x3A($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X3A);
    after_3:
L_80800358:
    // 0x80800358: jal         0x8008A390
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800360: b           L_808003A4
    // 0x80800364: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808003A4;
    // 0x80800364: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800368:
    // 0x80800368: jal         0x8001B798
    // 0x8080036C: lh          $a0, 0x2C($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X2C);
    func_8001B798(rdram, ctx);
        goto after_5;
    // 0x8080036C: lh          $a0, 0x2C($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X2C);
    after_5:
    // 0x80800370: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80800374: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800378: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x8080037C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800380: jal         0x808005D4
    // 0x80800384: lh          $a2, 0x3A($t8)
    ctx->r6 = MEM_H(ctx->r24, 0X3A);
    cheggclockwork_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x80800384: lh          $a2, 0x3A($t8)
    ctx->r6 = MEM_H(ctx->r24, 0X3A);
    after_6:
    // 0x80800388: jal         0x800FFAB0
    // 0x8080038C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_7;
    // 0x8080038C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800390: b           L_808003A4
    // 0x80800394: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808003A4;
    // 0x80800394: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800398:
    // 0x80800398: jal         0x8008A390
    // 0x8080039C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_3(rdram, ctx);
        goto after_8;
    // 0x8080039C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808003A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808003A4:
    // 0x808003A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808003AC: jr          $ra
    // 0x808003B0: nop

    return;
    // 0x808003B0: nop

;}
RECOMP_FUNC void chfactorystationdoors_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800230: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2340, 0X268) << 16);
    // 0x80800234: jr          $ra
    // 0x80800238: addiu       $v0, $v0, 0x268
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2340, 0X268));
    return;
    // 0x80800238: addiu       $v0, $v0, 0x268
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2340, 0X268));
    // 0x8080023C: nop

;}
RECOMP_FUNC void bainvisible_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800408: jr          $ra
    // 0x8080040C: addiu       $v0, $zero, 0x7C
    ctx->r2 = ADD32(0, 0X7C);
    return;
    // 0x8080040C: addiu       $v0, $zero, 0x7C
    ctx->r2 = ADD32(0, 0X7C);
;}
RECOMP_FUNC void _glsplinefuncs_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088470: syscall     686
    recomp_syscall_handler(rdram, ctx, 0x80088470);
    return;
    // 0x80088474: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808005F4_chpowerhut(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800600: jal         0x80100094
    // 0x80800604: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800604: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800608: jal         0x800898F0
    // 0x8080060C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_22(rdram, ctx);
        goto after_1;
    // 0x8080060C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800610: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1076, 0X940) << 16);
    // 0x80800614: lwc1        $f4, 0x940($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1076, 0X940));
    // 0x80800618: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080061C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800620: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800624: nop

    // 0x80800628: bc1f        L_80800688
    if (!c1cs) {
        // 0x8080062C: nop
    
            goto L_80800688;
    }
    // 0x8080062C: nop

    // 0x80800630: jal         0x80100094
    // 0x80800634: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80800634: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800638: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x8080063C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800640: beq         $t6, $zero, L_8080065C
    if (ctx->r14 == 0) {
        // 0x80800644: nop
    
            goto L_8080065C;
    }
    // 0x80800644: nop

    // 0x80800648: lhu         $t7, 0x0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X0);
    // 0x8080064C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800650: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x80800654: b           L_80800688
    // 0x80800658: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800688;
    // 0x80800658: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080065C:
    // 0x8080065C: jal         0x80089848
    // 0x80800660: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _sumumbofx_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80800660: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800664: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800668: jal         0x80101FDC
    // 0x8080066C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x8080066C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_4:
    // 0x80800670: jal         0x800DA524
    // 0x80800674: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    func_800DA524(rdram, ctx);
        goto after_5;
    // 0x80800674: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    after_5:
    // 0x80800678: jal         0x800DA544
    // 0x8080067C: addiu       $a0, $zero, 0x9DF
    ctx->r4 = ADD32(0, 0X9DF);
    func_800DA544(rdram, ctx);
        goto after_6;
    // 0x8080067C: addiu       $a0, $zero, 0x9DF
    ctx->r4 = ADD32(0, 0X9DF);
    after_6:
    // 0x80800680: b           L_80800688
    // 0x80800684: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800688;
    // 0x80800684: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800688:
    // 0x80800688: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080068C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800690: jr          $ra
    // 0x80800694: nop

    return;
    // 0x80800694: nop

;}
RECOMP_FUNC void func_80800094_chminelightswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800094: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800098: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080009C: jal         0x80085808
    // 0x808000A0: addiu       $a1, $zero, 0x9E0
    ctx->r5 = ADD32(0, 0X9E0);
    _chswitch_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x808000A0: addiu       $a1, $zero, 0x9E0
    ctx->r5 = ADD32(0, 0X9E0);
    after_0:
    // 0x808000A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000AC: jr          $ra
    // 0x808000B0: nop

    return;
    // 0x808000B0: nop

;}
RECOMP_FUNC void func_80800384_chfireicestorm(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800384: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800388: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080038C: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80800390: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800394: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800398: beq         $a1, $at, L_808003C0
    if (ctx->r5 == ctx->r1) {
        // 0x8080039C: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_808003C0;
    }
    // 0x8080039C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808003A0: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x808003A4: beq         $a1, $at, L_80800414
    if (ctx->r5 == ctx->r1) {
        // 0x808003A8: lw          $v0, 0x20($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X20);
            goto L_80800414;
    }
    // 0x808003A8: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x808003AC: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808003B0: beq         $a1, $at, L_80800460
    if (ctx->r5 == ctx->r1) {
        // 0x808003B4: nop
    
            goto L_80800460;
    }
    // 0x808003B4: nop

    // 0x808003B8: b           L_8080047C
    // 0x808003BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080047C;
    // 0x808003BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808003C0:
    // 0x808003C0: lh          $v0, 0x20($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X20);
    // 0x808003C4: addiu       $at, $zero, 0x12CF
    ctx->r1 = ADD32(0, 0X12CF);
    // 0x808003C8: addiu       $a0, $zero, 0x43F
    ctx->r4 = ADD32(0, 0X43F);
    // 0x808003CC: beq         $v0, $at, L_808003E4
    if (ctx->r2 == ctx->r1) {
        // 0x808003D0: addiu       $at, $zero, 0x12D0
        ctx->r1 = ADD32(0, 0X12D0);
            goto L_808003E4;
    }
    // 0x808003D0: addiu       $at, $zero, 0x12D0
    ctx->r1 = ADD32(0, 0X12D0);
    // 0x808003D4: beq         $v0, $at, L_808003F4
    if (ctx->r2 == ctx->r1) {
        // 0x808003D8: addiu       $a0, $zero, 0x43E
        ctx->r4 = ADD32(0, 0X43E);
            goto L_808003F4;
    }
    // 0x808003D8: addiu       $a0, $zero, 0x43E
    ctx->r4 = ADD32(0, 0X43E);
    // 0x808003DC: b           L_80800404
    // 0x808003E0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
        goto L_80800404;
    // 0x808003E0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_808003E4:
    // 0x808003E4: jal         0x800DA544
    // 0x808003E8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800DA544(rdram, ctx);
        goto after_0;
    // 0x808003E8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x808003EC: b           L_80800400
    // 0x808003F0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
        goto L_80800400;
    // 0x808003F0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_808003F4:
    // 0x808003F4: jal         0x800DA544
    // 0x808003F8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x808003F8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x808003FC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_80800400:
    // 0x80800400: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_80800404:
    // 0x80800404: jal         0x80800558
    // 0x80800408: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800558_chfireicestorm(rdram, ctx);
        goto after_2;
    // 0x80800408: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x8080040C: b           L_8080047C
    // 0x80800410: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080047C;
    // 0x80800410: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800414:
    // 0x80800414: beq         $v0, $zero, L_80800430
    if (ctx->r2 == 0) {
        // 0x80800418: addiu       $a0, $zero, 0x6CD
        ctx->r4 = ADD32(0, 0X6CD);
            goto L_80800430;
    }
    // 0x80800418: addiu       $a0, $zero, 0x6CD
    ctx->r4 = ADD32(0, 0X6CD);
    // 0x8080041C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800420: beq         $v0, $at, L_80800450
    if (ctx->r2 == ctx->r1) {
        // 0x80800424: nop
    
            goto L_80800450;
    }
    // 0x80800424: nop

    // 0x80800428: b           L_8080047C
    // 0x8080042C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080047C;
    // 0x8080042C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800430:
    // 0x80800430: jal         0x800DA298
    // 0x80800434: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80800434: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_3:
    // 0x80800438: bne         $v0, $zero, L_80800478
    if (ctx->r2 != 0) {
        // 0x8080043C: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_80800478;
    }
    // 0x8080043C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800440: jal         0x80800608
    // 0x80800444: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80800608_chfireicestorm(rdram, ctx);
        goto after_4;
    // 0x80800444: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_4:
    // 0x80800448: b           L_8080047C
    // 0x8080044C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080047C;
    // 0x8080044C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800450:
    // 0x80800450: jal         0x808007EC
    // 0x80800454: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_808007EC_chfireicestorm(rdram, ctx);
        goto after_5;
    // 0x80800454: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_5:
    // 0x80800458: b           L_8080047C
    // 0x8080045C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080047C;
    // 0x8080045C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800460:
    // 0x80800460: jal         0x8080048C
    // 0x80800464: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_8080048C_chfireicestorm(rdram, ctx);
        goto after_6;
    // 0x80800464: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_6:
    // 0x80800468: b           L_8080047C
    // 0x8080046C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080047C;
    // 0x8080046C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800470: b           L_8080047C
    // 0x80800474: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080047C;
    // 0x80800474: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800478:
    // 0x80800478: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080047C:
    // 0x8080047C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800480: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800484: jr          $ra
    // 0x80800488: nop

    return;
    // 0x80800488: nop

;}
RECOMP_FUNC void func_800E9C44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9C44: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800E9C48: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800E9C4C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800E9C50: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800E9C54: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800E9C58: jal         0x800E9E88
    // 0x800E9C5C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_800E9E88(rdram, ctx);
        goto after_0;
    // 0x800E9C5C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x800E9C60: beq         $v0, $zero, L_800E9CC0
    if (ctx->r2 == 0) {
        // 0x800E9C64: nop
    
            goto L_800E9CC0;
    }
    // 0x800E9C64: nop

    // 0x800E9C68: jal         0x800E9E88
    // 0x800E9C6C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800E9E88(rdram, ctx);
        goto after_1;
    // 0x800E9C6C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x800E9C70: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800E9C74: jal         0x800E9EB4
    // 0x800E9C78: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800E9EB4(rdram, ctx);
        goto after_2;
    // 0x800E9C78: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x800E9C7C: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x800E9C80: beq         $at, $zero, L_800E9CB0
    if (ctx->r1 == 0) {
        // 0x800E9C84: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_800E9CB0;
    }
    // 0x800E9C84: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800E9C88: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
L_800E9C8C:
    // 0x800E9C8C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x800E9C90: beql        $t7, $zero, L_800E9CA4
    if (ctx->r15 == 0) {
        // 0x800E9C94: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_800E9CA4;
    }
    goto skip_0;
    // 0x800E9C94: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_0:
    // 0x800E9C98: jal         0x800EBE24
    // 0x800E9C9C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800EBE24(rdram, ctx);
        goto after_3;
    // 0x800E9C9C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x800E9CA0: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_800E9CA4:
    // 0x800E9CA4: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x800E9CA8: bnel        $at, $zero, L_800E9C8C
    if (ctx->r1 != 0) {
        // 0x800E9CAC: lw          $t6, 0x8($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X8);
            goto L_800E9C8C;
    }
    goto skip_1;
    // 0x800E9CAC: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    skip_1:
L_800E9CB0:
    // 0x800E9CB0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E9CB4: addiu       $a0, $a0, 0x2DB4
    ctx->r4 = ADD32(ctx->r4, 0X2DB4);
    // 0x800E9CB8: jal         0x800B422C
    // 0x800E9CBC: addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    func_800B422C(rdram, ctx);
        goto after_4;
    // 0x800E9CBC: addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    after_4:
L_800E9CC0:
    // 0x800E9CC0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E9CC4: addiu       $a0, $a0, 0x2DB0
    ctx->r4 = ADD32(ctx->r4, 0X2DB0);
    // 0x800E9CC8: jal         0x800B422C
    // 0x800E9CCC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800B422C(rdram, ctx);
        goto after_5;
    // 0x800E9CCC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_5:
    // 0x800E9CD0: jal         0x800BE5C4
    // 0x800E9CD4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800BE5C4(rdram, ctx);
        goto after_6;
    // 0x800E9CD4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x800E9CD8: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x800E9CDC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800E9CE0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800E9CE4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800E9CE8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800E9CEC: jr          $ra
    // 0x800E9CF0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800E9CF0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _chfactoryliftdoor_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086200: syscall     289
    recomp_syscall_handler(rdram, ctx, 0x80086200);
    return;
    // 0x80086204: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void fxegg_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800048: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080004C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800050: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800054: jal         0x80800000
    // 0x80800058: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80800000_fxegg(rdram, ctx);
        goto after_0;
    // 0x80800058: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x8080005C: lh          $a0, 0x2($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X2);
    // 0x80800060: lh          $a1, 0x4($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X4);
    // 0x80800064: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80800068: jal         0x8080009C
    // 0x8080006C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    func_8080009C_fxegg(rdram, ctx);
        goto after_1;
    // 0x8080006C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80800070: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80800074: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800078: jal         0x800BA75C
    // 0x8080007C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800BA75C(rdram, ctx);
        goto after_2;
    // 0x8080007C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80800080: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800084: jal         0x800BA22C
    // 0x80800088: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800BA22C(rdram, ctx);
        goto after_3;
    // 0x80800088: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_3:
    // 0x8080008C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800090: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800094: jr          $ra
    // 0x80800098: nop

    return;
    // 0x80800098: nop

;}
RECOMP_FUNC void func_800CC6CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC6CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CC6D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CC6D4: jal         0x800CC63C
    // 0x800CC6D8: nop

    func_800CC63C(rdram, ctx);
        goto after_0;
    // 0x800CC6D8: nop

    after_0:
    // 0x800CC6DC: lhu         $v0, 0x14($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X14);
    // 0x800CC6E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CC6E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CC6E8: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x800CC6EC: jr          $ra
    // 0x800CC6F0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    return;
    // 0x800CC6F0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
;}
RECOMP_FUNC void func_80105AC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105AC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105AC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80105ACC: jal         0x80105494
    // 0x80105AD0: nop

    func_80105494(rdram, ctx);
        goto after_0;
    // 0x80105AD0: nop

    after_0:
    // 0x80105AD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80105AD8: lwc1        $f0, 0x14($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80105ADC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80105AE0: jr          $ra
    // 0x80105AE4: nop

    return;
    // 0x80105AE4: nop

;}
RECOMP_FUNC void _subaddieitem_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089FE8: syscall     821
    recomp_syscall_handler(rdram, ctx, 0x80089FE8);
    return;
    // 0x80089FEC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _bsdronejump_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800830F8: syscall     44
    recomp_syscall_handler(rdram, ctx, 0x800830F8);
    return;
    // 0x800830FC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800F04_chsabreman(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F04: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800F08: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800F0C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800F10: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800F14: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800F18: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80800F1C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800F20: jal         0x800DA564
    // 0x80800F24: addiu       $a0, $zero, 0x1CA
    ctx->r4 = ADD32(0, 0X1CA);
    func_800DA564(rdram, ctx);
        goto after_0;
    // 0x80800F24: addiu       $a0, $zero, 0x1CA
    ctx->r4 = ADD32(0, 0X1CA);
    after_0:
    // 0x80800F28: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800F2C: beq         $v0, $at, L_80800F64
    if (ctx->r2 == ctx->r1) {
        // 0x80800F30: lw          $v1, 0x2C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X2C);
            goto L_80800F64;
    }
    // 0x80800F30: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80800F34: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x80800F38: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80800F3C: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80800F40: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x80800F44: lw          $a3, 0x4($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X4);
    // 0x80800F48: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80800F4C: addiu       $a0, $a0, -0x5A88
    ctx->r4 = ADD32(ctx->r4, -0X5A88);
    // 0x80800F50: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800F54: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800F58: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80800F5C: jal         0x80086D58
    // 0x80800F60: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    _chbaddiesetup_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800F60: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_1:
L_80800F64:
    // 0x80800F64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800F68: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800F6C: jr          $ra
    // 0x80800F70: nop

    return;
    // 0x80800F70: nop

;}
RECOMP_FUNC void bsbanswim_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080065C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800660: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(53, 0XA40) << 16);
    // 0x80800664: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800668: jr          $ra
    // 0x8080066C: lw          $v0, 0xA40($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(53, 0XA40));
    return;
    // 0x8080066C: lw          $v0, 0xA40($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(53, 0XA40));
;}
RECOMP_FUNC void glcutDll_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005B4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x808005B8: jr          $ra
    // 0x808005BC: lh          $v0, 0x75EC($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X75EC);
    return;
    // 0x808005BC: lh          $v0, 0x75EC($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X75EC);
;}
RECOMP_FUNC void func_80800000_idworld(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80800004: lw          $t6, 0x7EF8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7EF8);
    // 0x80800008: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800014: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800018: bne         $t6, $zero, L_80800028
    if (ctx->r14 != 0) {
        // 0x8080001C: sw          $t6, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r14;
            goto L_80800028;
    }
    // 0x8080001C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80800020: b           L_80800094
    // 0x80800024: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800094;
    // 0x80800024: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800028:
    // 0x80800028: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8080002C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x80800030: jal         0x800B296C
    // 0x80800034: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    vector_end(rdram, ctx);
        goto after_0;
    // 0x80800034: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800038: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8080003C: lw          $a0, 0x7EF8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7EF8);
    // 0x80800040: jal         0x800B28C4
    // 0x80800044: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    vector_begin(rdram, ctx);
        goto after_1;
    // 0x80800044: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800048: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8080004C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80800050: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80800054: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x80800058: beq         $at, $zero, L_80800090
    if (ctx->r1 == 0) {
        // 0x8080005C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800090;
    }
    // 0x8080005C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800060: lbu         $t7, 0x6($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X6);
L_80800064:
    // 0x80800064: bnel        $a2, $t7, L_80800084
    if (ctx->r6 != ctx->r15) {
        // 0x80800068: addiu       $v1, $v1, 0xA8
        ctx->r3 = ADD32(ctx->r3, 0XA8);
            goto L_80800084;
    }
    goto skip_0;
    // 0x80800068: addiu       $v1, $v1, 0xA8
    ctx->r3 = ADD32(ctx->r3, 0XA8);
    skip_0:
    // 0x8080006C: lh          $t8, 0x4($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X4);
    // 0x80800070: bnel        $a3, $t8, L_80800084
    if (ctx->r7 != ctx->r24) {
        // 0x80800074: addiu       $v1, $v1, 0xA8
        ctx->r3 = ADD32(ctx->r3, 0XA8);
            goto L_80800084;
    }
    goto skip_1;
    // 0x80800074: addiu       $v1, $v1, 0xA8
    ctx->r3 = ADD32(ctx->r3, 0XA8);
    skip_1:
    // 0x80800078: b           L_80800094
    // 0x8080007C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80800094;
    // 0x8080007C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800080: addiu       $v1, $v1, 0xA8
    ctx->r3 = ADD32(ctx->r3, 0XA8);
L_80800084:
    // 0x80800084: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x80800088: bnel        $at, $zero, L_80800064
    if (ctx->r1 != 0) {
        // 0x8080008C: lbu         $t7, 0x6($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0X6);
            goto L_80800064;
    }
    goto skip_2;
    // 0x8080008C: lbu         $t7, 0x6($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X6);
    skip_2:
L_80800090:
    // 0x80800090: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800094:
    // 0x80800094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800098: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080009C: jr          $ra
    // 0x808000A0: nop

    return;
    // 0x808000A0: nop

;}
RECOMP_FUNC void func_80800904_bafpctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800904: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800908: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080090C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800910: jal         0x80091A58
    // 0x80800914: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    bakey_pressed(rdram, ctx);
        goto after_0;
    // 0x80800914: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_0:
    // 0x80800918: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x8080091C: beq         $t6, $zero, L_80800960
    if (ctx->r14 == 0) {
        // 0x80800920: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80800960;
    }
    // 0x80800920: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80800924: jal         0x800C6E38
    // 0x80800928: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_800C6E38(rdram, ctx);
        goto after_1;
    // 0x80800928: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_1:
    // 0x8080092C: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800930: beq         $t7, $zero, L_80800960
    if (ctx->r15 == 0) {
        // 0x80800934: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_80800960;
    }
    // 0x80800934: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80800938: jal         0x80800C10
    // 0x8080093C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bafpctrl_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x8080093C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800940: sltu        $t8, $zero, $v0
    ctx->r24 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800944: beq         $t8, $zero, L_80800960
    if (ctx->r24 == 0) {
        // 0x80800948: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_80800960;
    }
    // 0x80800948: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8080094C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80800950: lw          $t0, 0x90($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X90);
    // 0x80800954: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80800958: andi        $t1, $v0, 0x4
    ctx->r9 = ctx->r2 & 0X4;
    // 0x8080095C: sltiu       $v0, $t1, 0x1
    ctx->r2 = ctx->r9 < 0X1 ? 1 : 0;
L_80800960:
    // 0x80800960: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800964: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800968: jr          $ra
    // 0x8080096C: nop

    return;
    // 0x8080096C: nop

;}
RECOMP_FUNC void _sumumbofx_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800898A8: syscall     797
    recomp_syscall_handler(rdram, ctx, 0x800898A8);
    return;
    // 0x800898AC: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void func_808005C4_vpmodule(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005C4: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x808005C8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x808005CC: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x808005D0: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x808005D4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x808005D8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x808005DC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x808005E0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x808005E4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808005E8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808005EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808005F0: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    // 0x808005F4: lw          $t7, 0x14($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X14);
    // 0x808005F8: lw          $t6, 0x1C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X1C);
    // 0x808005FC: lw          $t9, 0x2C($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X2C);
    // 0x80800600: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80800604: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80800608: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8080060C: addu        $v1, $a1, $t6
    ctx->r3 = ADD32(ctx->r5, ctx->r14);
    // 0x80800610: addu        $t0, $t8, $v1
    ctx->r8 = ADD32(ctx->r24, ctx->r3);
    // 0x80800614: sll         $t1, $t9, 3
    ctx->r9 = S32(ctx->r25 << 3);
    // 0x80800618: addu        $fp, $t1, $a0
    ctx->r30 = ADD32(ctx->r9, ctx->r4);
    // 0x8080061C: sltu        $at, $v1, $t0
    ctx->r1 = ctx->r3 < ctx->r8 ? 1 : 0;
    // 0x80800620: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x80800624: addiu       $fp, $fp, 0x8
    ctx->r30 = ADD32(ctx->r30, 0X8);
    // 0x80800628: beq         $at, $zero, L_8080081C
    if (ctx->r1 == 0) {
        // 0x8080062C: or          $s7, $v1, $zero
        ctx->r23 = ctx->r3 | 0;
            goto L_8080081C;
    }
    // 0x8080062C: or          $s7, $v1, $zero
    ctx->r23 = ctx->r3 | 0;
    // 0x80800630: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x80800634: lui         $s5, 0x8080
    ctx->r21 = S32(RELOC_HI16(3002, 0X8C0) << 16);
    // 0x80800638: addiu       $s5, $s5, 0x8C0
    ctx->r21 = ADD32(ctx->r21, (int16_t)RELOC_LO16(3002, 0X8C0));
    // 0x8080063C: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80800640: sw          $v1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r3;
    // 0x80800644: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x80800648: sw          $t0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r8;
    // 0x8080064C: addiu       $s4, $zero, 0x14
    ctx->r20 = ADD32(0, 0X14);
    // 0x80800650: lw          $a3, 0x80($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X80);
L_80800654:
    // 0x80800654: lh          $t5, 0x0($s7)
    ctx->r13 = MEM_H(ctx->r23, 0X0);
    // 0x80800658: lbu         $a2, 0x2($s7)
    ctx->r6 = MEM_BU(ctx->r23, 0X2);
    // 0x8080065C: lw          $t2, 0x4($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X4);
    // 0x80800660: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x80800664: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x80800668: sll         $t7, $a2, 4
    ctx->r15 = S32(ctx->r6 << 4);
    // 0x8080066C: addu        $s3, $a3, $t2
    ctx->r19 = ADD32(ctx->r7, ctx->r10);
    // 0x80800670: addu        $t4, $a3, $t3
    ctx->r12 = ADD32(ctx->r7, ctx->r11);
    // 0x80800674: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80800678: addu        $a1, $t4, $t6
    ctx->r5 = ADD32(ctx->r12, ctx->r14);
    // 0x8080067C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800680: jal         0x80019E70
    // 0x80800684: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    aligned8_memcpy(rdram, ctx);
        goto after_0;
    // 0x80800684: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    after_0:
    // 0x80800688: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8080068C: sltu        $at, $t8, $fp
    ctx->r1 = ctx->r24 < ctx->r30 ? 1 : 0;
    // 0x80800690: beql        $at, $zero, L_80800794
    if (ctx->r1 == 0) {
        // 0x80800694: lw          $v0, 0x80($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X80);
            goto L_80800794;
    }
    goto skip_0;
    // 0x80800694: lw          $v0, 0x80($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X80);
    skip_0:
    // 0x80800698: lbu         $t9, 0x0($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X0);
L_8080069C:
    // 0x8080069C: multu       $t9, $s4
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808006A0: mflo        $t1
    ctx->r9 = lo;
    // 0x808006A4: addu        $t2, $s5, $t1
    ctx->r10 = ADD32(ctx->r21, ctx->r9);
    // 0x808006A8: lw          $t3, 0x10($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X10);
    // 0x808006AC: beql        $t3, $zero, L_80800784
    if (ctx->r11 == 0) {
        // 0x808006B0: addiu       $s2, $s2, 0x8
        ctx->r18 = ADD32(ctx->r18, 0X8);
            goto L_80800784;
    }
    goto skip_1;
    // 0x808006B0: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    skip_1:
    // 0x808006B4: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x808006B8: lh          $t5, 0x2($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X2);
    // 0x808006BC: subu        $t9, $s7, $t8
    ctx->r25 = SUB32(ctx->r23, ctx->r24);
    // 0x808006C0: div         $zero, $t9, $s4
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r20)));
    // 0x808006C4: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x808006C8: addu        $t6, $s6, $t4
    ctx->r14 = ADD32(ctx->r22, ctx->r12);
    // 0x808006CC: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x808006D0: mflo        $t1
    ctx->r9 = lo;
    // 0x808006D4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x808006D8: addu        $v1, $t7, $s6
    ctx->r3 = ADD32(ctx->r15, ctx->r22);
    // 0x808006DC: addu        $a0, $v1, $t2
    ctx->r4 = ADD32(ctx->r3, ctx->r10);
    // 0x808006E0: lhu         $t3, 0x16($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X16);
    // 0x808006E4: bne         $s4, $zero, L_808006F0
    if (ctx->r20 != 0) {
        // 0x808006E8: nop
    
            goto L_808006F0;
    }
    // 0x808006E8: nop

    // 0x808006EC: break       7
    do_break(2155874028);
L_808006F0:
    // 0x808006F0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808006F4: bne         $s4, $at, L_80800708
    if (ctx->r20 != ctx->r1) {
        // 0x808006F8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80800708;
    }
    // 0x808006F8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808006FC: bne         $t9, $at, L_80800708
    if (ctx->r25 != ctx->r1) {
        // 0x80800700: nop
    
            goto L_80800708;
    }
    // 0x80800700: nop

    // 0x80800704: break       6
    do_break(2155874052);
L_80800708:
    // 0x80800708: beql        $t3, $zero, L_80800784
    if (ctx->r11 == 0) {
        // 0x8080070C: addiu       $s2, $s2, 0x8
        ctx->r18 = ADD32(ctx->r18, 0X8);
            goto L_80800784;
    }
    goto skip_2;
    // 0x8080070C: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    skip_2:
    // 0x80800710: lw          $t5, 0x14($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X14);
    // 0x80800714: addiu       $v0, $a0, 0x14
    ctx->r2 = ADD32(ctx->r4, 0X14);
    // 0x80800718: lhu         $t7, 0x0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X0);
    // 0x8080071C: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x80800720: lhu         $t8, 0x2($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X2);
    // 0x80800724: addu        $t6, $v1, $t4
    ctx->r14 = ADD32(ctx->r3, ctx->r12);
    // 0x80800728: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x8080072C: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x80800730: addu        $s1, $t8, $s0
    ctx->r17 = ADD32(ctx->r24, ctx->r16);
    // 0x80800734: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x80800738: beql        $at, $zero, L_80800784
    if (ctx->r1 == 0) {
        // 0x8080073C: addiu       $s2, $s2, 0x8
        ctx->r18 = ADD32(ctx->r18, 0X8);
            goto L_80800784;
    }
    goto skip_3;
    // 0x8080073C: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    skip_3:
    // 0x80800740: lbu         $t1, 0x0($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X0);
L_80800744:
    // 0x80800744: lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1);
    // 0x80800748: lbu         $a1, 0x0($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X0);
    // 0x8080074C: multu       $t1, $s4
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800750: sll         $t9, $v0, 4
    ctx->r25 = S32(ctx->r2 << 4);
    // 0x80800754: addu        $a0, $t9, $s3
    ctx->r4 = ADD32(ctx->r25, ctx->r19);
    // 0x80800758: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8080075C: mflo        $t2
    ctx->r10 = lo;
    // 0x80800760: addu        $t3, $s5, $t2
    ctx->r11 = ADD32(ctx->r21, ctx->r10);
    // 0x80800764: lw          $t9, 0x10($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X10);
    // 0x80800768: jalr        $t9
    // 0x8080076C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8080076C: nop

    after_1:
    // 0x80800770: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800774: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x80800778: bnel        $at, $zero, L_80800744
    if (ctx->r1 != 0) {
        // 0x8080077C: lbu         $t1, 0x0($s2)
        ctx->r9 = MEM_BU(ctx->r18, 0X0);
            goto L_80800744;
    }
    goto skip_4;
    // 0x8080077C: lbu         $t1, 0x0($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X0);
    skip_4:
    // 0x80800780: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
L_80800784:
    // 0x80800784: sltu        $at, $s2, $fp
    ctx->r1 = ctx->r18 < ctx->r30 ? 1 : 0;
    // 0x80800788: bnel        $at, $zero, L_8080069C
    if (ctx->r1 != 0) {
        // 0x8080078C: lbu         $t9, 0x0($s2)
        ctx->r25 = MEM_BU(ctx->r18, 0X0);
            goto L_8080069C;
    }
    goto skip_5;
    // 0x8080078C: lbu         $t9, 0x0($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X0);
    skip_5:
    // 0x80800790: lw          $v0, 0x80($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X80);
L_80800794:
    // 0x80800794: lh          $t6, 0x0($s7)
    ctx->r14 = MEM_H(ctx->r23, 0X0);
    // 0x80800798: lbu         $a2, 0x2($s7)
    ctx->r6 = MEM_BU(ctx->r23, 0X2);
    // 0x8080079C: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x808007A0: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x808007A4: sll         $t8, $a2, 4
    ctx->r24 = S32(ctx->r6 << 4);
    // 0x808007A8: addu        $t4, $v0, $t5
    ctx->r12 = ADD32(ctx->r2, ctx->r13);
    // 0x808007AC: addu        $a0, $t4, $t7
    ctx->r4 = ADD32(ctx->r12, ctx->r15);
    // 0x808007B0: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x808007B4: jal         0x80019E70
    // 0x808007B8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    aligned8_memcpy(rdram, ctx);
        goto after_2;
    // 0x808007B8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_2:
    // 0x808007BC: lbu         $t1, 0x2($s7)
    ctx->r9 = MEM_BU(ctx->r23, 0X2);
    // 0x808007C0: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x808007C4: addu        $s0, $t2, $s3
    ctx->r16 = ADD32(ctx->r10, ctx->r19);
    // 0x808007C8: sltu        $at, $s3, $s0
    ctx->r1 = ctx->r19 < ctx->r16 ? 1 : 0;
    // 0x808007CC: beql        $at, $zero, L_8080080C
    if (ctx->r1 == 0) {
        // 0x808007D0: lw          $t6, 0x6C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X6C);
            goto L_8080080C;
    }
    goto skip_6;
    // 0x808007D0: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    skip_6:
    // 0x808007D4: lw          $s1, 0x88($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X88);
    // 0x808007D8: addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
    // 0x808007DC: lhu         $t3, 0x6($s3)
    ctx->r11 = MEM_HU(ctx->r19, 0X6);
L_808007E0:
    // 0x808007E0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x808007E4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x808007E8: andi        $t9, $t3, 0x7FFF
    ctx->r25 = ctx->r11 & 0X7FFF;
    // 0x808007EC: sll         $t5, $t9, 4
    ctx->r13 = S32(ctx->r25 << 4);
    // 0x808007F0: jal         0x80019E70
    // 0x808007F4: addu        $a0, $t5, $s1
    ctx->r4 = ADD32(ctx->r13, ctx->r17);
    aligned8_memcpy(rdram, ctx);
        goto after_3;
    // 0x808007F4: addu        $a0, $t5, $s1
    ctx->r4 = ADD32(ctx->r13, ctx->r17);
    after_3:
    // 0x808007F8: addiu       $s3, $s3, 0x10
    ctx->r19 = ADD32(ctx->r19, 0X10);
    // 0x808007FC: sltu        $at, $s3, $s0
    ctx->r1 = ctx->r19 < ctx->r16 ? 1 : 0;
    // 0x80800800: bnel        $at, $zero, L_808007E0
    if (ctx->r1 != 0) {
        // 0x80800804: lhu         $t3, 0x6($s3)
        ctx->r11 = MEM_HU(ctx->r19, 0X6);
            goto L_808007E0;
    }
    goto skip_7;
    // 0x80800804: lhu         $t3, 0x6($s3)
    ctx->r11 = MEM_HU(ctx->r19, 0X6);
    skip_7:
    // 0x80800808: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
L_8080080C:
    // 0x8080080C: addiu       $s7, $s7, 0x14
    ctx->r23 = ADD32(ctx->r23, 0X14);
    // 0x80800810: sltu        $at, $s7, $t6
    ctx->r1 = ctx->r23 < ctx->r14 ? 1 : 0;
    // 0x80800814: bnel        $at, $zero, L_80800654
    if (ctx->r1 != 0) {
        // 0x80800818: lw          $a3, 0x80($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X80);
            goto L_80800654;
    }
    goto skip_8;
    // 0x80800818: lw          $a3, 0x80($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X80);
    skip_8:
L_8080081C:
    // 0x8080081C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80800820: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800824: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800828: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8080082C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80800830: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800834: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80800838: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8080083C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80800840: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80800844: jr          $ra
    // 0x80800848: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80800848: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void sumultiscore_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EE4: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80800EE8: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x80800EEC: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80800EF0: addu        $t8, $t8, $a1
    ctx->r24 = ADD32(ctx->r24, ctx->r5);
    // 0x80800EF4: lw          $v1, 0x4($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X4);
    // 0x80800EF8: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x80800EFC: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x80800F00: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800F04: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x80800F08: sll         $t0, $v1, 5
    ctx->r8 = S32(ctx->r3 << 5);
    // 0x80800F0C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80800F10: jr          $ra
    // 0x80800F14: lh          $v0, 0x48($t1)
    ctx->r2 = MEM_H(ctx->r9, 0X48);
    return;
    // 0x80800F14: lh          $v0, 0x48($t1)
    ctx->r2 = MEM_H(ctx->r9, 0X48);
;}
RECOMP_FUNC void func_80092744(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092744: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x80092748: jr          $ra
    // 0x8009274C: sb          $a1, 0x88($t6)
    MEM_B(0X88, ctx->r14) = ctx->r5;
    return;
    // 0x8009274C: sb          $a1, 0x88($t6)
    MEM_B(0X88, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_80800C00_chpawnbroker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C08: blez        $a1, L_80800C5C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80800C0C: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80800C5C;
    }
    // 0x80800C0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800C10: jal         0x800D1A04
    // 0x80800C14: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    func_800D1A04(rdram, ctx);
        goto after_0;
    // 0x80800C14: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    after_0:
    // 0x80800C18: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800C1C: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80800C20: bne         $at, $zero, L_80800C54
    if (ctx->r1 != 0) {
        // 0x80800C24: nop
    
            goto L_80800C54;
    }
    // 0x80800C24: nop

    // 0x80800C28: jal         0x800F54E4
    // 0x80800C2C: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80800C2C: nop

    after_1:
    // 0x80800C30: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800C34: jal         0x800F64A4
    // 0x80800C38: addiu       $a1, $zero, 0x201
    ctx->r5 = ADD32(0, 0X201);
    func_800F64A4(rdram, ctx);
        goto after_2;
    // 0x80800C38: addiu       $a1, $zero, 0x201
    ctx->r5 = ADD32(0, 0X201);
    after_2:
    // 0x80800C3C: beq         $v0, $zero, L_80800C4C
    if (ctx->r2 == 0) {
        // 0x80800C40: nop
    
            goto L_80800C4C;
    }
    // 0x80800C40: nop

    // 0x80800C44: b           L_80800C60
    // 0x80800C48: addiu       $v0, $zero, 0x1040
    ctx->r2 = ADD32(0, 0X1040);
        goto L_80800C60;
    // 0x80800C48: addiu       $v0, $zero, 0x1040
    ctx->r2 = ADD32(0, 0X1040);
L_80800C4C:
    // 0x80800C4C: b           L_80800C60
    // 0x80800C50: addiu       $v0, $zero, 0x1225
    ctx->r2 = ADD32(0, 0X1225);
        goto L_80800C60;
    // 0x80800C50: addiu       $v0, $zero, 0x1225
    ctx->r2 = ADD32(0, 0X1225);
L_80800C54:
    // 0x80800C54: b           L_80800C60
    // 0x80800C58: addiu       $v0, $zero, 0xFE9
    ctx->r2 = ADD32(0, 0XFE9);
        goto L_80800C60;
    // 0x80800C58: addiu       $v0, $zero, 0xFE9
    ctx->r2 = ADD32(0, 0XFE9);
L_80800C5C:
    // 0x80800C5C: addiu       $v0, $zero, 0xFE7
    ctx->r2 = ADD32(0, 0XFE7);
L_80800C60:
    // 0x80800C60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C68: jr          $ra
    // 0x80800C6C: nop

    return;
    // 0x80800C6C: nop

;}
RECOMP_FUNC void func_800A9768(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9768: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A976C: addiu       $v0, $v0, 0x76D0
    ctx->r2 = ADD32(ctx->r2, 0X76D0);
    // 0x800A9770: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800A9774: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
L_800A9778:
    // 0x800A9778: lh          $t6, 0x8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X8);
    // 0x800A977C: bne         $a0, $t6, L_800A9794
    if (ctx->r4 != ctx->r14) {
        // 0x800A9780: sll         $t7, $v1, 2
        ctx->r15 = S32(ctx->r3 << 2);
            goto L_800A9794;
    }
    // 0x800A9780: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800A9784: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A9788: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x800A978C: jr          $ra
    // 0x800A9790: lw          $v0, 0x76E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X76E8);
    return;
    // 0x800A9790: lw          $v0, 0x76E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X76E8);
L_800A9794:
    // 0x800A9794: lh          $t8, 0xA($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XA);
    // 0x800A9798: bne         $a0, $t8, L_800A97B0
    if (ctx->r4 != ctx->r24) {
        // 0x800A979C: sll         $t9, $v1, 2
        ctx->r25 = S32(ctx->r3 << 2);
            goto L_800A97B0;
    }
    // 0x800A979C: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x800A97A0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A97A4: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x800A97A8: jr          $ra
    // 0x800A97AC: lw          $v0, 0x76EC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X76EC);
    return;
    // 0x800A97AC: lw          $v0, 0x76EC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X76EC);
L_800A97B0:
    // 0x800A97B0: lh          $t0, 0xC($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XC);
    // 0x800A97B4: bne         $a0, $t0, L_800A97CC
    if (ctx->r4 != ctx->r8) {
        // 0x800A97B8: sll         $t1, $v1, 2
        ctx->r9 = S32(ctx->r3 << 2);
            goto L_800A97CC;
    }
    // 0x800A97B8: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x800A97BC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A97C0: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x800A97C4: jr          $ra
    // 0x800A97C8: lw          $v0, 0x76F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X76F0);
    return;
    // 0x800A97C8: lw          $v0, 0x76F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X76F0);
L_800A97CC:
    // 0x800A97CC: lh          $t2, 0xE($v0)
    ctx->r10 = MEM_H(ctx->r2, 0XE);
    // 0x800A97D0: bne         $a0, $t2, L_800A97E8
    if (ctx->r4 != ctx->r10) {
        // 0x800A97D4: sll         $t3, $v1, 2
        ctx->r11 = S32(ctx->r3 << 2);
            goto L_800A97E8;
    }
    // 0x800A97D4: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x800A97D8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A97DC: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x800A97E0: jr          $ra
    // 0x800A97E4: lw          $v0, 0x76F4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X76F4);
    return;
    // 0x800A97E4: lw          $v0, 0x76F4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X76F4);
L_800A97E8:
    // 0x800A97E8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800A97EC: bne         $v1, $a1, L_800A9778
    if (ctx->r3 != ctx->r5) {
        // 0x800A97F0: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_800A9778;
    }
    // 0x800A97F0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800A97F4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800A97F8: jr          $ra
    // 0x800A97FC: nop

    return;
    // 0x800A97FC: nop

;}
RECOMP_FUNC void func_800E22F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E22F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E22F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800E22F8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800E22FC: addiu       $a1, $a1, -0x2B90
    ctx->r5 = ADD32(ctx->r5, -0X2B90);
    // 0x800E2300: lbu         $t6, 0x1F($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X1F);
    // 0x800E2304: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E2308: beql        $t6, $zero, L_800E2320
    if (ctx->r14 == 0) {
        // 0x800E230C: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_800E2320;
    }
    goto skip_0;
    // 0x800E230C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x800E2310: lbu         $t7, 0x20($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X20);
    // 0x800E2314: beq         $t7, $zero, L_800E2384
    if (ctx->r15 == 0) {
        // 0x800E2318: nop
    
            goto L_800E2384;
    }
    // 0x800E2318: nop

    // 0x800E231C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_800E2320:
    // 0x800E2320: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800E2324: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800E2328: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800E232C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800E2330: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800E2334: lbu         $t0, 0x1F($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X1F);
    // 0x800E2338: bnel        $t0, $zero, L_800E2360
    if (ctx->r8 != 0) {
        // 0x800E233C: lbu         $t3, 0x20($a1)
        ctx->r11 = MEM_BU(ctx->r5, 0X20);
            goto L_800E2360;
    }
    goto skip_1;
    // 0x800E233C: lbu         $t3, 0x20($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X20);
    skip_1:
    // 0x800E2340: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800E2344: lui         $t2, 0xE300
    ctx->r10 = S32(0XE300 << 16);
    // 0x800E2348: ori         $t2, $t2, 0x1801
    ctx->r10 = ctx->r10 | 0X1801;
    // 0x800E234C: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x800E2350: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x800E2354: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800E2358: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800E235C: lbu         $t3, 0x20($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X20);
L_800E2360:
    // 0x800E2360: beq         $t3, $zero, L_800E2384
    if (ctx->r11 == 0) {
        // 0x800E2364: nop
    
            goto L_800E2384;
    }
    // 0x800E2364: nop

    // 0x800E2368: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800E236C: lui         $t5, 0xE200
    ctx->r13 = S32(0XE200 << 16);
    // 0x800E2370: ori         $t5, $t5, 0x1E01
    ctx->r13 = ctx->r13 | 0X1E01;
    // 0x800E2374: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800E2378: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800E237C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800E2380: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_800E2384:
    // 0x800E2384: jal         0x800E8078
    // 0x800E2388: nop

    func_800E8078(rdram, ctx);
        goto after_0;
    // 0x800E2388: nop

    after_0:
    // 0x800E238C: jal         0x800E23A4
    // 0x800E2390: nop

    func_800E23A4(rdram, ctx);
        goto after_1;
    // 0x800E2390: nop

    after_1:
    // 0x800E2394: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E2398: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E239C: jr          $ra
    // 0x800E23A0: nop

    return;
    // 0x800E23A0: nop

;}
RECOMP_FUNC void gcegg_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800160: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x80800164: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80800168: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8080016C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2678, 0X20A) << 16);
    // 0x80800170: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x80800174: lbu         $a1, 0x20A($a1)
    ctx->r5 = MEM_BU(ctx->r5, (int16_t)RELOC_LO16(2678, 0X20A));
    // 0x80800178: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080017C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800180: xori        $v0, $a1, 0x3C
    ctx->r2 = ctx->r5 ^ 0X3C;
    // 0x80800184: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80800188: bnel        $v0, $zero, L_808001A4
    if (ctx->r2 != 0) {
        // 0x8080018C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808001A4;
    }
    goto skip_0;
    // 0x8080018C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800190: jal         0x800C6E38
    // 0x80800194: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800C6E38(rdram, ctx);
        goto after_0;
    // 0x80800194: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800198: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x8080019C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x808001A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001A4:
    // 0x808001A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001A8: jr          $ra
    // 0x808001AC: nop

    return;
    // 0x808001AC: nop

;}
RECOMP_FUNC void bsbreegullbash_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800524: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800528: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(112, 0X560) << 16);
    // 0x8080052C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800530: jr          $ra
    // 0x80800534: lw          $v0, 0x560($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(112, 0X560));
    return;
    // 0x80800534: lw          $v0, 0x560($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(112, 0X560));
    // 0x80800538: nop

    // 0x8080053C: nop

;}
RECOMP_FUNC void _capod_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800856F0: syscall     171
    recomp_syscall_handler(rdram, ctx, 0x800856F0);
    return;
    // 0x800856F4: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void chboilerid_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800490: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800494: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800498: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080049C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808004A0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808004A4: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x808004A8: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x808004AC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x808004B0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x808004B4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x808004B8: jal         0x80106790
    // 0x808004BC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808004BC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_0:
    // 0x808004C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808004C4: jal         0x80100094
    // 0x808004C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808004C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808004CC: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x808004D0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x808004D4: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x808004D8: addu        $s3, $t7, $s0
    ctx->r19 = ADD32(ctx->r15, ctx->r16);
    // 0x808004DC: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x808004E0: beq         $at, $zero, L_80800504
    if (ctx->r1 == 0) {
        // 0x808004E4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800504;
    }
L_808004E4:
    // 0x808004E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808004E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808004EC: jal         0x80800700
    // 0x808004F0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_80800700_chboilerid(rdram, ctx);
        goto after_2;
    // 0x808004F0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_2:
    // 0x808004F4: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x808004F8: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x808004FC: bne         $at, $zero, L_808004E4
    if (ctx->r1 != 0) {
        // 0x80800500: addiu       $s1, $s1, 0x10
        ctx->r17 = ADD32(ctx->r17, 0X10);
            goto L_808004E4;
    }
    // 0x80800500: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
L_80800504:
    // 0x80800504: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800508: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080050C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800510: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800514: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800518: jr          $ra
    // 0x8080051C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8080051C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80101010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101010: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80101014: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80101018: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010101C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80101020: jal         0x800EE7F8
    // 0x80101024: addiu       $a0, $a0, 0x5A70
    ctx->r4 = ADD32(ctx->r4, 0X5A70);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80101024: addiu       $a0, $a0, 0x5A70
    ctx->r4 = ADD32(ctx->r4, 0X5A70);
    after_0:
    // 0x80101028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010102C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80101030: jr          $ra
    // 0x80101034: nop

    return;
    // 0x80101034: nop

;}
RECOMP_FUNC void func_80800804_bskazstill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800804: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800808: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080080C: jal         0x800832E0
    // 0x80800810: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bskaz_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800810: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800814: jal         0x800839C8
    // 0x80800818: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsrest_entrypoint_16(rdram, ctx);
        goto after_1;
    // 0x80800818: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080081C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800820: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800824: jr          $ra
    // 0x80800828: nop

    return;
    // 0x80800828: nop

;}
RECOMP_FUNC void bsblongleg_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011A4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808011A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808011AC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808011B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808011B4: jal         0x808000C8
    // 0x808011B8: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    func_808000C8_bsblongleg(rdram, ctx);
        goto after_0;
    // 0x808011B8: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    after_0:
    // 0x808011BC: jal         0x8009D658
    // 0x808011C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D658(rdram, ctx);
        goto after_1;
    // 0x808011C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808011C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011C8: jal         0x800852F0
    // 0x808011CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_2;
    // 0x808011CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808011D0: jal         0x8008E148
    // 0x808011D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E148(rdram, ctx);
        goto after_3;
    // 0x808011D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808011D8: beq         $v0, $zero, L_80801260
    if (ctx->r2 == 0) {
        // 0x808011DC: addiu       $t6, $zero, 0x26
        ctx->r14 = ADD32(0, 0X26);
            goto L_80801260;
    }
    // 0x808011DC: addiu       $t6, $zero, 0x26
    ctx->r14 = ADD32(0, 0X26);
    // 0x808011E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011E4: jal         0x800963C0
    // 0x808011E8: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800963C0(rdram, ctx);
        goto after_4;
    // 0x808011E8: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_4:
    // 0x808011EC: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x808011F0: jal         0x800F1EA4
    // 0x808011F4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800F1EA4(rdram, ctx);
        goto after_5;
    // 0x808011F4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_5:
    // 0x808011F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801200: jal         0x8009D2F0
    // 0x80801204: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    func_8009D2F0(rdram, ctx);
        goto after_6;
    // 0x80801204: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_6:
    // 0x80801208: jal         0x8009BFD8
    // 0x8080120C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BFD8(rdram, ctx);
        goto after_7;
    // 0x8080120C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80801210: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80801214: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801218: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x8080121C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801220: lui         $a3, 0x4409
    ctx->r7 = S32(0X4409 << 16);
    // 0x80801224: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x80801228: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8080122C: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    // 0x80801230: jal         0x800F10B4
    // 0x80801234: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_8;
    // 0x80801234: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_8:
    // 0x80801238: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080123C: jal         0x8009B9B0
    // 0x80801240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_9;
    // 0x80801240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80801244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801248: jal         0x8009B9C0
    // 0x8080124C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    baphysics_set_target_yaw(rdram, ctx);
        goto after_10;
    // 0x8080124C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_10:
    // 0x80801250: jal         0x800849D0
    // 0x80801254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badust_entrypoint_1(rdram, ctx);
        goto after_11;
    // 0x80801254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80801258: b           L_80801268
    // 0x8080125C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801268;
    // 0x8080125C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801260:
    // 0x80801260: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x80801264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801268:
    // 0x80801268: jal         0x80085330
    // 0x8080126C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_isZero(rdram, ctx);
        goto after_12;
    // 0x8080126C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x80801270: beq         $v0, $zero, L_8080128C
    if (ctx->r2 == 0) {
        // 0x80801274: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080128C;
    }
    // 0x80801274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801278: jal         0x80091A58
    // 0x8080127C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_13;
    // 0x8080127C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_13:
    // 0x80801280: beq         $v0, $zero, L_8080128C
    if (ctx->r2 == 0) {
        // 0x80801284: addiu       $t7, $zero, 0x28
        ctx->r15 = ADD32(0, 0X28);
            goto L_8080128C;
    }
    // 0x80801284: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x80801288: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
L_8080128C:
    // 0x8080128C: jal         0x80800000
    // 0x80801290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsblongleg(rdram, ctx);
        goto after_14;
    // 0x80801290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80801294: beq         $v0, $zero, L_808012A4
    if (ctx->r2 == 0) {
        // 0x80801298: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808012A4;
    }
    // 0x80801298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080129C: addiu       $t8, $zero, 0x4C
    ctx->r24 = ADD32(0, 0X4C);
    // 0x808012A0: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
L_808012A4:
    // 0x808012A4: jal         0x8009E5C8
    // 0x808012A8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    bs_setState(rdram, ctx);
        goto after_15;
    // 0x808012A8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_15:
    // 0x808012AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808012B0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808012B4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808012B8: jr          $ra
    // 0x808012BC: nop

    return;
    // 0x808012BC: nop

;}
RECOMP_FUNC void chbosskogsdoor_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800868: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2292, 0X9EC) << 16);
    // 0x8080086C: jr          $ra
    // 0x80800870: addiu       $v0, $v0, 0x9EC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2292, 0X9EC));
    return;
    // 0x80800870: addiu       $v0, $v0, 0x9EC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2292, 0X9EC));
    // 0x80800874: nop

    // 0x80800878: nop

    // 0x8080087C: nop

;}
RECOMP_FUNC void _baeggsetup_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084A60: syscall     126
    recomp_syscall_handler(rdram, ctx, 0x80084A60);
    return;
    // 0x80084A64: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_808024D4_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808024D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808024D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808024DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808024E0: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x808024E4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808024E8: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x808024EC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x808024F0: jal         0x80087B08
    // 0x808024F4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _gczoombox_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x808024F4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x808024F8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808024FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802500: jal         0x80087B28
    // 0x80802504: sw          $v0, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->r2;
    _gczoombox_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80802504: sw          $v0, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->r2;
    after_1:
    // 0x80802508: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8080250C: jal         0x80087B38
    // 0x80802510: lw          $a0, 0x28($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X28);
    _gczoombox_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x80802510: lw          $a0, 0x28($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X28);
    after_2:
    // 0x80802514: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80802518: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8080251C: sw          $t8, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->r24;
    // 0x80802520: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802524: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802528: jr          $ra
    // 0x8080252C: nop

    return;
    // 0x8080252C: nop

;}
