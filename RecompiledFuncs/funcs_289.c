#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_808016A8_changlerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808016A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808016AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808016B0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808016B4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808016B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808016BC: jal         0x80100094
    // 0x808016C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808016C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808016C4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808016C8: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x808016CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_808016D0:
    // 0x808016D0: jal         0x800DC128
    // 0x808016D4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_800DC128(rdram, ctx);
        goto after_1;
    // 0x808016D4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_1:
    // 0x808016D8: addu        $t6, $s0, $v0
    ctx->r14 = ADD32(ctx->r16, ctx->r2);
    // 0x808016DC: lbu         $t7, 0x1B($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X1B);
    // 0x808016E0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808016E4: bnel        $s1, $t7, L_808016D0
    if (ctx->r17 != ctx->r15) {
        // 0x808016E8: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_808016D0;
    }
    goto skip_0;
    // 0x808016E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_0:
    // 0x808016EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808016F0: jal         0x808015F4
    // 0x808016F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_808015F4_changlerboss(rdram, ctx);
        goto after_2;
    // 0x808016F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x808016F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808016FC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801700: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801704: jr          $ra
    // 0x80801708: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80801708: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_808002E0_chcrystalbaddie(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808002E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002EC: beq         $a1, $at, L_80800338
    if (ctx->r5 == ctx->r1) {
        // 0x808002F0: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800338;
    }
    // 0x808002F0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808002F4: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x808002F8: beq         $a1, $at, L_80800328
    if (ctx->r5 == ctx->r1) {
        // 0x808002FC: addiu       $at, $zero, 0x90
        ctx->r1 = ADD32(0, 0X90);
            goto L_80800328;
    }
    // 0x808002FC: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x80800300: beq         $a1, $at, L_80800318
    if (ctx->r5 == ctx->r1) {
        // 0x80800304: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_80800318;
    }
    // 0x80800304: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800308: beq         $a1, $at, L_80800358
    if (ctx->r5 == ctx->r1) {
        // 0x8080030C: nop
    
            goto L_80800358;
    }
    // 0x8080030C: nop

    // 0x80800310: b           L_80800374
    // 0x80800314: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800374;
    // 0x80800314: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800318:
    // 0x80800318: jal         0x8080052C
    // 0x8080031C: nop

    func_8080052C_chcrystalbaddie(rdram, ctx);
        goto after_0;
    // 0x8080031C: nop

    after_0:
    // 0x80800320: b           L_80800374
    // 0x80800324: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800374;
    // 0x80800324: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800328:
    // 0x80800328: jal         0x808004D4
    // 0x8080032C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_808004D4_chcrystalbaddie(rdram, ctx);
        goto after_1;
    // 0x8080032C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800330: b           L_80800374
    // 0x80800334: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800374;
    // 0x80800334: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800338:
    // 0x80800338: jal         0x8008A4A8
    // 0x8080033C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _subaddieDll_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x8080033C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x80800340: bne         $v0, $zero, L_80800370
    if (ctx->r2 != 0) {
        // 0x80800344: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800370;
    }
    // 0x80800344: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800348: jal         0x80107070
    // 0x8080034C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80107070(rdram, ctx);
        goto after_3;
    // 0x8080034C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800350: b           L_80800374
    // 0x80800354: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800374;
    // 0x80800354: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800358:
    // 0x80800358: jal         0x80089F60
    // 0x8080035C: nop

    _subaddierouteDll_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x8080035C: nop

    after_4:
    // 0x80800360: b           L_80800374
    // 0x80800364: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800374;
    // 0x80800364: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800368: b           L_80800374
    // 0x8080036C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800374;
    // 0x8080036C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800370:
    // 0x80800370: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800374:
    // 0x80800374: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800378: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080037C: jr          $ra
    // 0x80800380: nop

    return;
    // 0x80800380: nop

;}
RECOMP_FUNC void func_80801118_bsvan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801118: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080111C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801120: jal         0x800845D0
    // 0x80801124: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _babounce_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80801124: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801128: jal         0x808000F0
    // 0x8080112C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bsvan_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x8080112C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801134: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801138: jr          $ra
    // 0x8080113C: nop

    return;
    // 0x8080113C: nop

;}
RECOMP_FUNC void func_800FC81C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC81C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FC820: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800FC824: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800FC828: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FC82C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800FC830: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FC834: addiu       $s1, $s1, 0x59B0
    ctx->r17 = ADD32(ctx->r17, 0X59B0);
    // 0x800FC838: addiu       $s0, $s0, 0x57D0
    ctx->r16 = ADD32(ctx->r16, 0X57D0);
    // 0x800FC83C: lh          $a0, 0x28($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X28);
L_800FC840:
    // 0x800FC840: bltzl       $a0, L_800FC864
    if (SIGNED(ctx->r4) < 0) {
        // 0x800FC844: addiu       $s0, $s0, 0x50
        ctx->r16 = ADD32(ctx->r16, 0X50);
            goto L_800FC864;
    }
    goto skip_0;
    // 0x800FC844: addiu       $s0, $s0, 0x50
    ctx->r16 = ADD32(ctx->r16, 0X50);
    skip_0:
    // 0x800FC848: jal         0x800FE7A8
    // 0x800FC84C: nop

    func_800FE7A8(rdram, ctx);
        goto after_0;
    // 0x800FC84C: nop

    after_0:
    // 0x800FC850: bnel        $v0, $zero, L_800FC864
    if (ctx->r2 != 0) {
        // 0x800FC854: addiu       $s0, $s0, 0x50
        ctx->r16 = ADD32(ctx->r16, 0X50);
            goto L_800FC864;
    }
    goto skip_1;
    // 0x800FC854: addiu       $s0, $s0, 0x50
    ctx->r16 = ADD32(ctx->r16, 0X50);
    skip_1:
    // 0x800FC858: jal         0x800FB774
    // 0x800FC85C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FB774(rdram, ctx);
        goto after_1;
    // 0x800FC85C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800FC860: addiu       $s0, $s0, 0x50
    ctx->r16 = ADD32(ctx->r16, 0X50);
L_800FC864:
    // 0x800FC864: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x800FC868: bnel        $at, $zero, L_800FC840
    if (ctx->r1 != 0) {
        // 0x800FC86C: lh          $a0, 0x28($s0)
        ctx->r4 = MEM_H(ctx->r16, 0X28);
            goto L_800FC840;
    }
    goto skip_2;
    // 0x800FC86C: lh          $a0, 0x28($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X28);
    skip_2:
    // 0x800FC870: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FC874: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800FC878: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800FC87C: jr          $ra
    // 0x800FC880: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800FC880: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80800960_chnests(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800960: jr          $ra
    // 0x80800964: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800964: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800E4088(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E4088: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E408C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E4090: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E4094: jal         0x800CA7B4
    // 0x800E4098: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    func_800CA7B4(rdram, ctx);
        goto after_0;
    // 0x800E4098: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    after_0:
    // 0x800E409C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E40A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E40A4: jr          $ra
    // 0x800E40A8: nop

    return;
    // 0x800E40A8: nop

;}
RECOMP_FUNC void _bsbtrot_entrypoint_42(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082D10: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082D10);
    return;
    // 0x80082D14: addi        $t0, $zero, 0xA8
    ctx->r8 = ADD32(0, 0XA8);
;}
RECOMP_FUNC void func_808001C4_bsbeefly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808001C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001D4: jal         0x8008CABC
    // 0x808001D8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808001D8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x808001DC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x808001E0: jal         0x80082840
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsbee_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808001E8: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    // 0x808001EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808001F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808001F4: beq         $v0, $zero, L_8080020C
    if (ctx->r2 == 0) {
        // 0x808001F8: lui         $a1, 0x3E88
        ctx->r5 = S32(0X3E88 << 16);
            goto L_8080020C;
    }
    // 0x808001F8: lui         $a1, 0x3E88
    ctx->r5 = S32(0X3E88 << 16);
    // 0x808001FC: beq         $v0, $at, L_80800244
    if (ctx->r2 == ctx->r1) {
        // 0x80800200: nop
    
            goto L_80800244;
    }
    // 0x80800200: nop

    // 0x80800204: b           L_80800294
    // 0x80800208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800294;
    // 0x80800208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080020C:
    // 0x8080020C: jal         0x8008B348
    // 0x80800210: ori         $a1, $a1, 0x3127
    ctx->r5 = ctx->r5 | 0X3127;
    anctrl_isAt(rdram, ctx);
        goto after_2;
    // 0x80800210: ori         $a1, $a1, 0x3127
    ctx->r5 = ctx->r5 | 0X3127;
    after_2:
    // 0x80800214: beq         $v0, $zero, L_80800290
    if (ctx->r2 == 0) {
        // 0x80800218: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800290;
    }
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080021C: jal         0x8009BA58
    // 0x80800220: lui         $a1, 0x44C8
    ctx->r5 = S32(0X44C8 << 16);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_3;
    // 0x80800220: lui         $a1, 0x44C8
    ctx->r5 = S32(0X44C8 << 16);
    after_3:
    // 0x80800224: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x80800228: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800230: jal         0x8009DE38
    // 0x80800234: addiu       $a1, $zero, 0x406
    ctx->r5 = ADD32(0, 0X406);
    func_8009DE38(rdram, ctx);
        goto after_4;
    // 0x80800234: addiu       $a1, $zero, 0x406
    ctx->r5 = ADD32(0, 0X406);
    after_4:
    // 0x80800238: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080023C: b           L_80800290
    // 0x80800240: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
        goto L_80800290;
    // 0x80800240: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
L_80800244:
    // 0x80800244: jal         0x80800000
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsbeefly(rdram, ctx);
        goto after_5;
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080024C: jal         0x8008B324
    // 0x80800250: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isStopped(rdram, ctx);
        goto after_6;
    // 0x80800250: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x80800254: beq         $v0, $zero, L_8080026C
    if (ctx->r2 == 0) {
        // 0x80800258: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080026C;
    }
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080025C: lui         $a2, 0x3EC2
    ctx->r6 = S32(0X3EC2 << 16);
    // 0x80800260: ori         $a2, $a2, 0x8F5C
    ctx->r6 = ctx->r6 | 0X8F5C;
    // 0x80800264: jal         0x8008CB3C
    // 0x80800268: addiu       $a1, $zero, 0x1DC
    ctx->r5 = ADD32(0, 0X1DC);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_7;
    // 0x80800268: addiu       $a1, $zero, 0x1DC
    ctx->r5 = ADD32(0, 0X1DC);
    after_7:
L_8080026C:
    // 0x8080026C: jal         0x8009BB50
    // 0x80800270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_8;
    // 0x80800270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800274: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800278: addiu       $t7, $zero, 0x8C
    ctx->r15 = ADD32(0, 0X8C);
    // 0x8080027C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800280: nop

    // 0x80800284: bc1fl       L_80800294
    if (!c1cs) {
        // 0x80800288: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800294;
    }
    goto skip_0;
    // 0x80800288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8080028C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80800290:
    // 0x80800290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800294:
    // 0x80800294: jal         0x8009E5C8
    // 0x80800298: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_9;
    // 0x80800298: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_9:
    // 0x8080029C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808002A8: jr          $ra
    // 0x808002AC: nop

    return;
    // 0x808002AC: nop

;}
RECOMP_FUNC void aligned4_memmove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BC68: bgez        $a2, L_8001BC78
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8001BC6C: sra         $t6, $a2, 2
        ctx->r14 = S32(SIGNED(ctx->r6) >> 2);
            goto L_8001BC78;
    }
    // 0x8001BC6C: sra         $t6, $a2, 2
    ctx->r14 = S32(SIGNED(ctx->r6) >> 2);
    // 0x8001BC70: addiu       $at, $a2, 0x3
    ctx->r1 = ADD32(ctx->r6, 0X3);
    // 0x8001BC74: sra         $t6, $at, 2
    ctx->r14 = S32(SIGNED(ctx->r1) >> 2);
L_8001BC78:
    // 0x8001BC78: sltu        $at, $a0, $a1
    ctx->r1 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x8001BC7C: beq         $at, $zero, L_8001BCB4
    if (ctx->r1 == 0) {
        // 0x8001BC80: or          $a2, $t6, $zero
        ctx->r6 = ctx->r14 | 0;
            goto L_8001BCB4;
    }
    // 0x8001BC80: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x8001BC84: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8001BC88: beq         $a2, $zero, L_8001BCF0
    if (ctx->r6 == 0) {
        // 0x8001BC8C: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_8001BCF0;
    }
    // 0x8001BC8C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_8001BC90:
    // 0x8001BC90: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8001BC94: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8001BC98: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8001BC9C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8001BCA0: sw          $t7, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->r15;
    // 0x8001BCA4: bne         $a2, $zero, L_8001BC90
    if (ctx->r6 != 0) {
        // 0x8001BCA8: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_8001BC90;
    }
    // 0x8001BCA8: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8001BCAC: jr          $ra
    // 0x8001BCB0: nop

    return;
    // 0x8001BCB0: nop

L_8001BCB4:
    // 0x8001BCB4: sll         $v1, $a2, 2
    ctx->r3 = S32(ctx->r6 << 2);
    // 0x8001BCB8: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8001BCBC: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x8001BCC0: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // 0x8001BCC4: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x8001BCC8: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x8001BCCC: beq         $a2, $zero, L_8001BCF0
    if (ctx->r6 == 0) {
        // 0x8001BCD0: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_8001BCF0;
    }
    // 0x8001BCD0: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_8001BCD4:
    // 0x8001BCD4: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8001BCD8: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8001BCDC: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x8001BCE0: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x8001BCE4: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8001BCE8: bne         $a2, $zero, L_8001BCD4
    if (ctx->r6 != 0) {
        // 0x8001BCEC: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_8001BCD4;
    }
    // 0x8001BCEC: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_8001BCF0:
    // 0x8001BCF0: jr          $ra
    // 0x8001BCF4: nop

    return;
    // 0x8001BCF4: nop

;}
RECOMP_FUNC void _bsbpeck_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082AD0: syscall     25
    recomp_syscall_handler(rdram, ctx, 0x80082AD0);
    return;
    // 0x80082AD4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80110528(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110528: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8011052C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80110530: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80110534: jal         0x801138A0
    // 0x80110538: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_801138A0(rdram, ctx);
        goto after_0;
    // 0x80110538: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8011053C: beql        $v0, $zero, L_80110550
    if (ctx->r2 == 0) {
        // 0x80110540: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80110550;
    }
    goto skip_0;
    // 0x80110540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80110544: jal         0x801138F4
    // 0x80110548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801138F4(rdram, ctx);
        goto after_1;
    // 0x80110548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8011054C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80110550:
    // 0x80110550: jal         0x80112524
    // 0x80110554: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_80112524(rdram, ctx);
        goto after_2;
    // 0x80110554: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_2:
    // 0x80110558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8011055C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80110560: jal         0x80110A68
    // 0x80110564: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_80110A68(rdram, ctx);
        goto after_3;
    // 0x80110564: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x80110568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8011056C: jal         0x80110790
    // 0x80110570: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_80110790(rdram, ctx);
        goto after_4;
    // 0x80110570: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_4:
    // 0x80110574: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80110578: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8011057C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80110580: jr          $ra
    // 0x80110584: nop

    return;
    // 0x80110584: nop

;}
RECOMP_FUNC void func_80026500(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026500: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80026504: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80026508: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8002650C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80026510: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80026514: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80026518: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8002651C: jal         0x8002FEC0
    // 0x80026520: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80026520: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80026524: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80026528: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8002652C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80026530: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80026534: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80026538: bne         $t8, $zero, L_80026550
    if (ctx->r24 != 0) {
        // 0x8002653C: nop
    
            goto L_80026550;
    }
    // 0x8002653C: nop

    // 0x80026540: jal         0x8002FEC0
    // 0x80026544: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x80026544: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80026548: b           L_800266A0
    // 0x8002654C: nop

        goto L_800266A0;
    // 0x8002654C: nop

L_80026550:
    // 0x80026550: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80026554: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80026558: bne         $t0, $zero, L_8002657C
    if (ctx->r8 != 0) {
        // 0x8002655C: nop
    
            goto L_8002657C;
    }
    // 0x8002655C: nop

    // 0x80026560: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80026564: bne         $t1, $zero, L_8002657C
    if (ctx->r9 != 0) {
        // 0x80026568: nop
    
            goto L_8002657C;
    }
    // 0x80026568: nop

    // 0x8002656C: jal         0x8002FEC0
    // 0x80026570: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    osSetIntMask_recomp(rdram, ctx);
        goto after_2;
    // 0x80026570: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80026574: b           L_800266A0
    // 0x80026578: nop

        goto L_800266A0;
    // 0x80026578: nop

L_8002657C:
    // 0x8002657C: jal         0x80020E74
    // 0x80026580: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_80020E74(rdram, ctx);
        goto after_3;
    // 0x80026580: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x80026584: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80026588: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8002658C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80026590: jal         0x80031BF0
    // 0x80026594: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    _bcopy(rdram, ctx);
        goto after_4;
    // 0x80026594: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_4:
    // 0x80026598: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8002659C: lui         $at, 0x7FFF
    ctx->r1 = S32(0X7FFF << 16);
    // 0x800265A0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800265A4: bne         $t2, $at, L_800265B4
    if (ctx->r10 != ctx->r1) {
        // 0x800265A8: nop
    
            goto L_800265B4;
    }
    // 0x800265A8: nop

    // 0x800265AC: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800265B0: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
L_800265B4:
    // 0x800265B4: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800265B8: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800265BC: beq         $t5, $zero, L_80026690
    if (ctx->r13 == 0) {
        // 0x800265C0: sw          $t5, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r13;
            goto L_80026690;
    }
    // 0x800265C0: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
L_800265C4:
    // 0x800265C4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800265C8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800265CC: bne         $t7, $zero, L_80026614
    if (ctx->r15 != 0) {
        // 0x800265D0: nop
    
            goto L_80026614;
    }
    // 0x800265D0: nop

    // 0x800265D4: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800265D8: beq         $t8, $zero, L_800265EC
    if (ctx->r24 == 0) {
        // 0x800265DC: nop
    
            goto L_800265EC;
    }
    // 0x800265DC: nop

    // 0x800265E0: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800265E4: b           L_800265F8
    // 0x800265E8: sw          $zero, 0x8($t9)
    MEM_W(0X8, ctx->r25) = 0;
        goto L_800265F8;
    // 0x800265E8: sw          $zero, 0x8($t9)
    MEM_W(0X8, ctx->r25) = 0;
L_800265EC:
    // 0x800265EC: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800265F0: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800265F4: sw          $t0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r8;
L_800265F8:
    // 0x800265F8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800265FC: jal         0x80020E40
    // 0x80026600: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80020E40(rdram, ctx);
        goto after_5;
    // 0x80026600: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x80026604: b           L_80026690
    // 0x80026608: nop

        goto L_80026690;
    // 0x80026608: nop

    // 0x8002660C: b           L_80026680
    // 0x80026610: nop

        goto L_80026680;
    // 0x80026610: nop

L_80026614:
    // 0x80026614: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80026618: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8002661C: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x80026620: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80026624: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80026628: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x8002662C: slt         $at, $t4, $t6
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80026630: beq         $at, $zero, L_8002666C
    if (ctx->r1 == 0) {
        // 0x80026634: nop
    
            goto L_8002666C;
    }
    // 0x80026634: nop

    // 0x80026638: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8002663C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80026640: sw          $t7, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r15;
    // 0x80026644: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80026648: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8002664C: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x80026650: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x80026654: sw          $t2, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r10;
    // 0x80026658: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8002665C: jal         0x80020E40
    // 0x80026660: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80020E40(rdram, ctx);
        goto after_6;
    // 0x80026660: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x80026664: b           L_80026690
    // 0x80026668: nop

        goto L_80026690;
    // 0x80026668: nop

L_8002666C:
    // 0x8002666C: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80026670: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80026674: lw          $t4, 0x8($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X8);
    // 0x80026678: subu        $t6, $t3, $t4
    ctx->r14 = SUB32(ctx->r11, ctx->r12);
    // 0x8002667C: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
L_80026680:
    // 0x80026680: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80026684: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80026688: bne         $t8, $zero, L_800265C4
    if (ctx->r24 != 0) {
        // 0x8002668C: sw          $t8, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r24;
            goto L_800265C4;
    }
    // 0x8002668C: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_80026690:
    // 0x80026690: jal         0x8002FEC0
    // 0x80026694: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    osSetIntMask_recomp(rdram, ctx);
        goto after_7;
    // 0x80026694: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_7:
    // 0x80026698: b           L_800266A0
    // 0x8002669C: nop

        goto L_800266A0;
    // 0x8002669C: nop

L_800266A0:
    // 0x800266A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800266A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800266A8: jr          $ra
    // 0x800266AC: nop

    return;
    // 0x800266AC: nop

;}
RECOMP_FUNC void idbounce_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D98: jal         0x808008B4
    // 0x80800D9C: nop

    func_808008B4_idbounce(rdram, ctx);
        goto after_0;
    // 0x80800D9C: nop

    after_0:
    // 0x80800DA0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80800DA4: addiu       $a0, $a0, 0x5480
    ctx->r4 = ADD32(ctx->r4, 0X5480);
    // 0x80800DA8: lbu         $v1, 0x1($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X1);
    // 0x80800DAC: sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
    // 0x80800DB0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80800DB4: sltiu       $t6, $v1, 0x1
    ctx->r14 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80800DB8: beq         $t6, $zero, L_80800DC4
    if (ctx->r14 == 0) {
        // 0x80800DBC: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_80800DC4;
    }
    // 0x80800DBC: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x80800DC0: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
L_80800DC4:
    // 0x80800DC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800DC8: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x80800DCC: sb          $v0, 0x5481($at)
    MEM_B(0X5481, ctx->r1) = ctx->r2;
    // 0x80800DD0: jr          $ra
    // 0x80800DD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800DD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800D5440(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5440: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D5444: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800D5448: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D544C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800D5450: lw          $a0, -0x4810($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4810);
    // 0x800D5454: jal         0x800B296C
    // 0x800D5458: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    vector_end(rdram, ctx);
        goto after_0;
    // 0x800D5458: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800D545C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800D5460: lw          $a0, -0x4810($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4810);
    // 0x800D5464: jal         0x800B28C4
    // 0x800D5468: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    vector_begin(rdram, ctx);
        goto after_1;
    // 0x800D5468: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x800D546C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800D5470: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800D5474: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800D5478: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x800D547C: beq         $at, $zero, L_800D54AC
    if (ctx->r1 == 0) {
        // 0x800D5480: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800D54AC;
    }
    // 0x800D5480: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800D5484: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x800D5488: beql        $a2, $t6, L_800D54B0
    if (ctx->r6 == ctx->r14) {
        // 0x800D548C: sltu        $at, $v1, $a1
        ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
            goto L_800D54B0;
    }
    goto skip_0;
    // 0x800D548C: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    skip_0:
    // 0x800D5490: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_800D5494:
    // 0x800D5494: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x800D5498: beql        $at, $zero, L_800D54B0
    if (ctx->r1 == 0) {
        // 0x800D549C: sltu        $at, $v1, $a1
        ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
            goto L_800D54B0;
    }
    goto skip_1;
    // 0x800D549C: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    skip_1:
    // 0x800D54A0: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x800D54A4: bnel        $a2, $t7, L_800D5494
    if (ctx->r6 != ctx->r15) {
        // 0x800D54A8: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_800D5494;
    }
    goto skip_2;
    // 0x800D54A8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    skip_2:
L_800D54AC:
    // 0x800D54AC: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
L_800D54B0:
    // 0x800D54B0: beq         $at, $zero, L_800D54C8
    if (ctx->r1 == 0) {
        // 0x800D54B4: addiu       $a0, $a0, -0x4810
        ctx->r4 = ADD32(ctx->r4, -0X4810);
            goto L_800D54C8;
    }
    // 0x800D54B4: addiu       $a0, $a0, -0x4810
    ctx->r4 = ADD32(ctx->r4, -0X4810);
    // 0x800D54B8: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800D54BC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800D54C0: b           L_800D54E0
    // 0x800D54C4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
        goto L_800D54E0;
    // 0x800D54C4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_800D54C8:
    // 0x800D54C8: jal         0x800B2974
    // 0x800D54CC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    vector_push_back(rdram, ctx);
        goto after_2;
    // 0x800D54CC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_2:
    // 0x800D54D0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800D54D4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800D54D8: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x800D54DC: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
L_800D54E0:
    // 0x800D54E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D54E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D54E8: jr          $ra
    // 0x800D54EC: nop

    return;
    // 0x800D54EC: nop

;}
RECOMP_FUNC void func_80800540_chmineprospector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800540: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800544: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800548: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8080054C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(892, 0X111A) << 16);
    // 0x80800550: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800554: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800558: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8080055C: sb          $a3, 0x111A($at)
    MEM_B((int16_t)RELOC_LO16(892, 0X111A), ctx->r1) = ctx->r7;
    // 0x80800560: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(892, 0X110C) << 16);
    // 0x80800564: addiu       $a2, $a2, 0x110C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(892, 0X110C));
    // 0x80800568: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8080056C: addiu       $a1, $a0, 0x28
    ctx->r5 = ADD32(ctx->r4, 0X28);
    // 0x80800570: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800574: jal         0x8008A1F0
    // 0x80800578: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x80800578: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x8080057C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800580: bne         $v0, $zero, L_80800590
    if (ctx->r2 != 0) {
        // 0x80800584: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80800590;
    }
    // 0x80800584: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800588: b           L_808005E0
    // 0x8080058C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808005E0;
    // 0x8080058C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800590:
    // 0x80800590: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80800594: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80800598: jal         0x8008A1F8
    // 0x8080059C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _subaddiedialog_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x8080059C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x808005A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808005A4: beq         $v0, $at, L_808005C0
    if (ctx->r2 == ctx->r1) {
        // 0x808005A8: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808005C0;
    }
    // 0x808005A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808005AC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808005B0: beq         $v0, $at, L_808005D4
    if (ctx->r2 == ctx->r1) {
        // 0x808005B4: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_808005D4;
    }
    // 0x808005B4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808005B8: b           L_808005E0
    // 0x808005BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005E0;
    // 0x808005BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005C0:
    // 0x808005C0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808005C4: jal         0x808009B0
    // 0x808005C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_808009B0_chmineprospector(rdram, ctx);
        goto after_2;
    // 0x808005C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x808005CC: b           L_808005E0
    // 0x808005D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005E0;
    // 0x808005D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005D4:
    // 0x808005D4: jal         0x808009B0
    // 0x808005D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_808009B0_chmineprospector(rdram, ctx);
        goto after_3;
    // 0x808005D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x808005DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005E0:
    // 0x808005E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808005E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808005E8: jr          $ra
    // 0x808005EC: nop

    return;
    // 0x808005EC: nop

;}
RECOMP_FUNC void func_80803FC4_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803FC4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80803FC8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80803FCC: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x80803FD0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80803FD4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80803FD8: bne         $at, $zero, L_80803FF4
    if (ctx->r1 != 0) {
        // 0x80803FDC: sw          $a2, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r6;
            goto L_80803FF4;
    }
    // 0x80803FDC: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80803FE0: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x80803FE4: beq         $a1, $at, L_808042C4
    if (ctx->r5 == ctx->r1) {
        // 0x80803FE8: nop
    
            goto L_808042C4;
    }
    // 0x80803FE8: nop

    // 0x80803FEC: b           L_80804358
    // 0x80803FF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80804358;
    // 0x80803FF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80803FF4:
    // 0x80803FF4: addiu       $t6, $a1, -0xD
    ctx->r14 = ADD32(ctx->r5, -0XD);
    // 0x80803FF8: sltiu       $at, $t6, 0x23
    ctx->r1 = ctx->r14 < 0X23 ? 1 : 0;
    // 0x80803FFC: beq         $at, $zero, L_8080434C
    if (ctx->r1 == 0) {
        // 0x80804000: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8080434C;
    }
    // 0x80804000: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80804004: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X4604) << 16);
    // 0x80804008: addu        $at, $at, $t6
    gpr jr_addend_80804010 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8080400C: lw          $t6, 0x4604($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1632, 0X4604));
    // 0x80804010: jr          $t6
    // 0x80804014: nop

    switch (jr_addend_80804010 >> 2) {
        case 0: goto L_808040A8; break;
        case 1: goto L_80804018; break;
        case 2: goto L_8080434C; break;
        case 3: goto L_8080434C; break;
        case 4: goto L_8080434C; break;
        case 5: goto L_8080434C; break;
        case 6: goto L_8080434C; break;
        case 7: goto L_8080434C; break;
        case 8: goto L_8080434C; break;
        case 9: goto L_8080434C; break;
        case 10: goto L_8080434C; break;
        case 11: goto L_8080434C; break;
        case 12: goto L_8080434C; break;
        case 13: goto L_8080434C; break;
        case 14: goto L_8080434C; break;
        case 15: goto L_8080434C; break;
        case 16: goto L_8080434C; break;
        case 17: goto L_8080434C; break;
        case 18: goto L_80804304; break;
        case 19: goto L_8080434C; break;
        case 20: goto L_8080434C; break;
        case 21: goto L_8080434C; break;
        case 22: goto L_8080434C; break;
        case 23: goto L_8080434C; break;
        case 24: goto L_8080434C; break;
        case 25: goto L_8080434C; break;
        case 26: goto L_8080434C; break;
        case 27: goto L_8080434C; break;
        case 28: goto L_8080434C; break;
        case 29: goto L_8080434C; break;
        case 30: goto L_8080434C; break;
        case 31: goto L_8080434C; break;
        case 32: goto L_8080434C; break;
        case 33: goto L_80804120; break;
        case 34: goto L_8080402C; break;
        default: switch_error(__func__, 0x80804010, 0x80804604);
    }
    // 0x80804014: nop

L_80804018:
    // 0x80804018: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080401C: jal         0x80802400
    // 0x80804020: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    func_80802400_chhandcart(rdram, ctx);
        goto after_0;
    // 0x80804020: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_0:
    // 0x80804024: b           L_80804358
    // 0x80804028: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80804358;
    // 0x80804028: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8080402C:
    // 0x8080402C: jal         0x80106790
    // 0x80804030: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80804030: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_1:
    // 0x80804034: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80804038: jal         0x80100094
    // 0x8080403C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x8080403C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80804040: lh          $v1, 0x40($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X40);
    // 0x80804044: addiu       $at, $zero, 0xF84
    ctx->r1 = ADD32(0, 0XF84);
    // 0x80804048: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x8080404C: beq         $v1, $at, L_80804068
    if (ctx->r3 == ctx->r1) {
        // 0x80804050: addiu       $a0, $zero, 0xC
        ctx->r4 = ADD32(0, 0XC);
            goto L_80804068;
    }
    // 0x80804050: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80804054: addiu       $at, $zero, 0xF89
    ctx->r1 = ADD32(0, 0XF89);
    // 0x80804058: beq         $v1, $at, L_80804088
    if (ctx->r3 == ctx->r1) {
        // 0x8080405C: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_80804088;
    }
    // 0x8080405C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80804060: b           L_80804358
    // 0x80804064: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80804358;
    // 0x80804064: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80804068:
    // 0x80804068: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8080406C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80804070: addiu       $a2, $t0, 0x90C
    ctx->r6 = ADD32(ctx->r8, 0X90C);
    // 0x80804074: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80804078: jal         0x800D1000
    // 0x8080407C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_800D1000(rdram, ctx);
        goto after_3;
    // 0x8080407C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_3:
    // 0x80804080: b           L_80804358
    // 0x80804084: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80804358;
    // 0x80804084: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80804088:
    // 0x80804088: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8080408C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80804090: addiu       $a2, $t0, 0x90C
    ctx->r6 = ADD32(ctx->r8, 0X90C);
    // 0x80804094: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80804098: jal         0x800D1000
    // 0x8080409C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_800D1000(rdram, ctx);
        goto after_4;
    // 0x8080409C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_4:
    // 0x808040A0: b           L_80804358
    // 0x808040A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80804358;
    // 0x808040A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808040A8:
    // 0x808040A8: jal         0x80106790
    // 0x808040AC: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_5;
    // 0x808040AC: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_5:
    // 0x808040B0: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x808040B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808040B8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808040BC: andi        $t9, $v1, 0xFFFF
    ctx->r25 = ctx->r3 & 0XFFFF;
    // 0x808040C0: beq         $t9, $at, L_808040D8
    if (ctx->r25 == ctx->r1) {
        // 0x808040C4: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808040D8;
    }
    // 0x808040C4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808040C8: beq         $t9, $at, L_808040FC
    if (ctx->r25 == ctx->r1) {
        // 0x808040CC: nop
    
            goto L_808040FC;
    }
    // 0x808040CC: nop

    // 0x808040D0: b           L_80804358
    // 0x808040D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80804358;
    // 0x808040D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808040D8:
    // 0x808040D8: jal         0x80101080
    // 0x808040DC: nop

    func_80101080(rdram, ctx);
        goto after_6;
    // 0x808040DC: nop

    after_6:
    // 0x808040E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808040E4: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    // 0x808040E8: addiu       $a2, $zero, 0x2000
    ctx->r6 = ADD32(0, 0X2000);
    // 0x808040EC: jal         0x8080090C
    // 0x808040F0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_8080090C_chhandcart(rdram, ctx);
        goto after_7;
    // 0x808040F0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_7:
    // 0x808040F4: b           L_80804358
    // 0x808040F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80804358;
    // 0x808040F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808040FC:
    // 0x808040FC: jal         0x80101080
    // 0x80804100: nop

    func_80101080(rdram, ctx);
        goto after_8;
    // 0x80804100: nop

    after_8:
    // 0x80804104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804108: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    // 0x8080410C: addiu       $a2, $zero, 0x2000
    ctx->r6 = ADD32(0, 0X2000);
    // 0x80804110: jal         0x8080090C
    // 0x80804114: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_8080090C_chhandcart(rdram, ctx);
        goto after_9;
    // 0x80804114: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_9:
    // 0x80804118: b           L_80804358
    // 0x8080411C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80804358;
    // 0x8080411C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80804120:
    // 0x80804120: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80804124: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80804128: beq         $a0, $zero, L_80804140
    if (ctx->r4 == 0) {
        // 0x8080412C: nop
    
            goto L_80804140;
    }
    // 0x8080412C: nop

    // 0x80804130: jal         0x80106790
    // 0x80804134: nop

    func_80106790(rdram, ctx);
        goto after_10;
    // 0x80804134: nop

    after_10:
    // 0x80804138: b           L_80804140
    // 0x8080413C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
        goto L_80804140;
    // 0x8080413C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_80804140:
    // 0x80804140: lh          $v1, 0x40($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X40);
    // 0x80804144: slti        $at, $v1, 0xFAA
    ctx->r1 = SIGNED(ctx->r3) < 0XFAA ? 1 : 0;
    // 0x80804148: bne         $at, $zero, L_8080416C
    if (ctx->r1 != 0) {
        // 0x8080414C: addiu       $t1, $v1, -0xF7F
        ctx->r9 = ADD32(ctx->r3, -0XF7F);
            goto L_8080416C;
    }
    // 0x8080414C: addiu       $t1, $v1, -0xF7F
    ctx->r9 = ADD32(ctx->r3, -0XF7F);
    // 0x80804150: addiu       $at, $zero, 0xFAF
    ctx->r1 = ADD32(0, 0XFAF);
    // 0x80804154: beq         $v1, $at, L_808042A0
    if (ctx->r3 == ctx->r1) {
        // 0x80804158: addiu       $at, $zero, 0xFB7
        ctx->r1 = ADD32(0, 0XFB7);
            goto L_808042A0;
    }
    // 0x80804158: addiu       $at, $zero, 0xFB7
    ctx->r1 = ADD32(0, 0XFB7);
    // 0x8080415C: beq         $v1, $at, L_808041E0
    if (ctx->r3 == ctx->r1) {
        // 0x80804160: nop
    
            goto L_808041E0;
    }
    // 0x80804160: nop

    // 0x80804164: b           L_808042B8
    // 0x80804168: lbu         $t8, 0x74($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X74);
        goto L_808042B8;
    // 0x80804168: lbu         $t8, 0x74($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X74);
L_8080416C:
    // 0x8080416C: slti        $at, $v1, 0xF89
    ctx->r1 = SIGNED(ctx->r3) < 0XF89 ? 1 : 0;
    // 0x80804170: bne         $at, $zero, L_80804188
    if (ctx->r1 != 0) {
        // 0x80804174: addiu       $at, $zero, 0xFA9
        ctx->r1 = ADD32(0, 0XFA9);
            goto L_80804188;
    }
    // 0x80804174: addiu       $at, $zero, 0xFA9
    ctx->r1 = ADD32(0, 0XFA9);
    // 0x80804178: beq         $v1, $at, L_808041C4
    if (ctx->r3 == ctx->r1) {
        // 0x8080417C: nop
    
            goto L_808041C4;
    }
    // 0x8080417C: nop

    // 0x80804180: b           L_808042B8
    // 0x80804184: lbu         $t8, 0x74($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X74);
        goto L_808042B8;
    // 0x80804184: lbu         $t8, 0x74($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X74);
L_80804188:
    // 0x80804188: slti        $at, $v1, 0xCED
    ctx->r1 = SIGNED(ctx->r3) < 0XCED ? 1 : 0;
    // 0x8080418C: bne         $at, $zero, L_808041B0
    if (ctx->r1 != 0) {
        // 0x80804190: sltiu       $at, $t1, 0xA
        ctx->r1 = ctx->r9 < 0XA ? 1 : 0;
            goto L_808041B0;
    }
    // 0x80804190: sltiu       $at, $t1, 0xA
    ctx->r1 = ctx->r9 < 0XA ? 1 : 0;
    // 0x80804194: beq         $at, $zero, L_808042B4
    if (ctx->r1 == 0) {
        // 0x80804198: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_808042B4;
    }
    // 0x80804198: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8080419C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X4690) << 16);
    // 0x808041A0: addu        $at, $at, $t1
    gpr jr_addend_808041A8 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x808041A4: lw          $t1, 0x4690($at)
    ctx->r9 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1632, 0X4690));
    // 0x808041A8: jr          $t1
    // 0x808041AC: nop

    switch (jr_addend_808041A8 >> 2) {
        case 0: goto L_808041C4; break;
        case 1: goto L_808041E0; break;
        case 2: goto L_808042B4; break;
        case 3: goto L_80804230; break;
        case 4: goto L_8080420C; break;
        case 5: goto L_808042B4; break;
        case 6: goto L_80804268; break;
        case 7: goto L_808042B4; break;
        case 8: goto L_8080424C; break;
        case 9: goto L_8080420C; break;
        default: switch_error(__func__, 0x808041A8, 0x80804690);
    }
    // 0x808041AC: nop

L_808041B0:
    // 0x808041B0: addiu       $at, $zero, 0xCEC
    ctx->r1 = ADD32(0, 0XCEC);
    // 0x808041B4: beq         $v1, $at, L_808041FC
    if (ctx->r3 == ctx->r1) {
        // 0x808041B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808041FC;
    }
    // 0x808041B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808041BC: b           L_808042B8
    // 0x808041C0: lbu         $t8, 0x74($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X74);
        goto L_808042B8;
    // 0x808041C0: lbu         $t8, 0x74($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X74);
L_808041C4:
    // 0x808041C4: jal         0x800DA544
    // 0x808041C8: addiu       $a0, $zero, 0x57A
    ctx->r4 = ADD32(0, 0X57A);
    func_800DA544(rdram, ctx);
        goto after_11;
    // 0x808041C8: addiu       $a0, $zero, 0x57A
    ctx->r4 = ADD32(0, 0X57A);
    after_11:
    // 0x808041CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808041D0: jal         0x80802CE8
    // 0x808041D4: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    func_80802CE8_chhandcart(rdram, ctx);
        goto after_12;
    // 0x808041D4: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    after_12:
    // 0x808041D8: b           L_808042B8
    // 0x808041DC: lbu         $t8, 0x74($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X74);
        goto L_808042B8;
    // 0x808041DC: lbu         $t8, 0x74($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X74);
L_808041E0:
    // 0x808041E0: jal         0x80800AB0
    // 0x808041E4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80800AB0_chhandcart(rdram, ctx);
        goto after_13;
    // 0x808041E4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_13:
    // 0x808041E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808041EC: jal         0x808031D0
    // 0x808041F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808031D0_chhandcart(rdram, ctx);
        goto after_14;
    // 0x808041F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_14:
    // 0x808041F4: b           L_808042B8
    // 0x808041F8: lbu         $t8, 0x74($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X74);
        goto L_808042B8;
    // 0x808041F8: lbu         $t8, 0x74($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X74);
L_808041FC:
    // 0x808041FC: jal         0x808031D0
    // 0x80804200: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_808031D0_chhandcart(rdram, ctx);
        goto after_15;
    // 0x80804200: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_15:
    // 0x80804204: b           L_808042B8
    // 0x80804208: lbu         $t8, 0x74($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X74);
        goto L_808042B8;
    // 0x80804208: lbu         $t8, 0x74($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X74);
L_8080420C:
    // 0x8080420C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804210: jal         0x808001D0
    // 0x80804214: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808001D0_chhandcart(rdram, ctx);
        goto after_16;
    // 0x80804214: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x80804218: jal         0x808000B4
    // 0x8080421C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000B4_chhandcart(rdram, ctx);
        goto after_17;
    // 0x8080421C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80804220: jal         0x800904C8
    // 0x80804224: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    func_800904C8(rdram, ctx);
        goto after_18;
    // 0x80804224: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_18:
    // 0x80804228: b           L_808042B8
    // 0x8080422C: lbu         $t8, 0x74($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X74);
        goto L_808042B8;
    // 0x8080422C: lbu         $t8, 0x74($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X74);
L_80804230:
    // 0x80804230: jal         0x80800AB0
    // 0x80804234: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80800AB0_chhandcart(rdram, ctx);
        goto after_19;
    // 0x80804234: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_19:
    // 0x80804238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080423C: jal         0x808031D0
    // 0x80804240: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808031D0_chhandcart(rdram, ctx);
        goto after_20;
    // 0x80804240: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_20:
    // 0x80804244: b           L_808042B8
    // 0x80804248: lbu         $t8, 0x74($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X74);
        goto L_808042B8;
    // 0x80804248: lbu         $t8, 0x74($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X74);
L_8080424C:
    // 0x8080424C: jal         0x80800AB0
    // 0x80804250: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80800AB0_chhandcart(rdram, ctx);
        goto after_21;
    // 0x80804250: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_21:
    // 0x80804254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804258: jal         0x808031D0
    // 0x8080425C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808031D0_chhandcart(rdram, ctx);
        goto after_22;
    // 0x8080425C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_22:
    // 0x80804260: b           L_808042B8
    // 0x80804264: lbu         $t8, 0x74($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X74);
        goto L_808042B8;
    // 0x80804264: lbu         $t8, 0x74($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X74);
L_80804268:
    // 0x80804268: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8080426C: jal         0x80800AB0
    // 0x80804270: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80800AB0_chhandcart(rdram, ctx);
        goto after_23;
    // 0x80804270: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_23:
    // 0x80804274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804278: jal         0x808031D0
    // 0x8080427C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808031D0_chhandcart(rdram, ctx);
        goto after_24;
    // 0x8080427C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_24:
    // 0x80804280: lbu         $t3, 0x65($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X65);
    // 0x80804284: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80804288: ori         $t4, $t3, 0x8
    ctx->r12 = ctx->r11 | 0X8;
    // 0x8080428C: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
    // 0x80804290: lbu         $t6, 0x65($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X65);
    // 0x80804294: ori         $t7, $t6, 0x8
    ctx->r15 = ctx->r14 | 0X8;
    // 0x80804298: b           L_808042B4
    // 0x8080429C: sb          $t7, 0x65($a2)
    MEM_B(0X65, ctx->r6) = ctx->r15;
        goto L_808042B4;
    // 0x8080429C: sb          $t7, 0x65($a2)
    MEM_B(0X65, ctx->r6) = ctx->r15;
L_808042A0:
    // 0x808042A0: jal         0x80800AB0
    // 0x808042A4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80800AB0_chhandcart(rdram, ctx);
        goto after_25;
    // 0x808042A4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_25:
    // 0x808042A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808042AC: jal         0x808031D0
    // 0x808042B0: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    func_808031D0_chhandcart(rdram, ctx);
        goto after_26;
    // 0x808042B0: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_26:
L_808042B4:
    // 0x808042B4: lbu         $t8, 0x74($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X74);
L_808042B8:
    // 0x808042B8: andi        $t9, $t8, 0xFFBF
    ctx->r25 = ctx->r24 & 0XFFBF;
    // 0x808042BC: b           L_80804354
    // 0x808042C0: sb          $t9, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r25;
        goto L_80804354;
    // 0x808042C0: sb          $t9, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r25;
L_808042C4:
    // 0x808042C4: jal         0x801022E4
    // 0x808042C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801022E4(rdram, ctx);
        goto after_27;
    // 0x808042C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x808042CC: addiu       $at, $zero, 0x7D
    ctx->r1 = ADD32(0, 0X7D);
    // 0x808042D0: bne         $v0, $at, L_808042F0
    if (ctx->r2 != ctx->r1) {
        // 0x808042D4: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(1632, 0X4E5C) << 16);
            goto L_808042F0;
    }
    // 0x808042D4: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1632, 0X4E5C) << 16);
    // 0x808042D8: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1632, 0X4E4C) << 16);
    // 0x808042DC: addiu       $a0, $a0, 0x4E4C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1632, 0X4E4C));
    // 0x808042E0: jal         0x80088090
    // 0x808042E4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_28;
    // 0x808042E4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_28:
    // 0x808042E8: b           L_80804358
    // 0x808042EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80804358;
    // 0x808042EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808042F0:
    // 0x808042F0: addiu       $a0, $a0, 0x4E5C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1632, 0X4E5C));
    // 0x808042F4: jal         0x80088090
    // 0x808042F8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_29;
    // 0x808042F8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_29:
    // 0x808042FC: b           L_80804358
    // 0x80804300: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80804358;
    // 0x80804300: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80804304:
    // 0x80804304: jal         0x801015D0
    // 0x80804308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801015D0(rdram, ctx);
        goto after_30;
    // 0x80804308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x8080430C: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x80804310: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x80804314: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80804318: srl         $t1, $v1, 10
    ctx->r9 = S32(U32(ctx->r3) >> 10);
    // 0x8080431C: beq         $t1, $at, L_8080432C
    if (ctx->r9 == ctx->r1) {
        // 0x80804320: addiu       $at, $zero, 0x19
        ctx->r1 = ADD32(0, 0X19);
            goto L_8080432C;
    }
    // 0x80804320: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x80804324: bne         $t1, $at, L_8080433C
    if (ctx->r9 != ctx->r1) {
        // 0x80804328: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8080433C;
    }
    // 0x80804328: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8080432C:
    // 0x8080432C: jal         0x800DF744
    // 0x80804330: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_31;
    // 0x80804330: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_31:
    // 0x80804334: b           L_80804358
    // 0x80804338: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80804358;
    // 0x80804338: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080433C:
    // 0x8080433C: jal         0x800DF744
    // 0x80804340: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800DF744(rdram, ctx);
        goto after_32;
    // 0x80804340: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_32:
    // 0x80804344: b           L_80804358
    // 0x80804348: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80804358;
    // 0x80804348: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080434C:
    // 0x8080434C: b           L_80804358
    // 0x80804350: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80804358;
    // 0x80804350: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80804354:
    // 0x80804354: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80804358:
    // 0x80804358: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080435C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80804360: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80804364: jr          $ra
    // 0x80804368: nop

    return;
    // 0x80804368: nop

;}
RECOMP_FUNC void func_80109518(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109518: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8010951C: jr          $ra
    // 0x80109520: addiu       $v0, $v0, 0x464C
    ctx->r2 = ADD32(ctx->r2, 0X464C);
    return;
    // 0x80109520: addiu       $v0, $v0, 0x464C
    ctx->r2 = ADD32(ctx->r2, 0X464C);
;}
RECOMP_FUNC void _gclevel_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088230: syscall     676
    recomp_syscall_handler(rdram, ctx, 0x80088230);
    return;
    // 0x80088234: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800C8A98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8A98: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C8A9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C8AA0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C8AA4: jal         0x800B28C4
    // 0x800C8AA8: lw          $a0, -0x5500($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5500);
    vector_begin(rdram, ctx);
        goto after_0;
    // 0x800C8AA8: lw          $a0, -0x5500($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5500);
    after_0:
    // 0x800C8AAC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C8AB0: lw          $a0, -0x5500($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5500);
    // 0x800C8AB4: jal         0x800B296C
    // 0x800C8AB8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    vector_end(rdram, ctx);
        goto after_1;
    // 0x800C8AB8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x800C8ABC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800C8AC0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800C8AC4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C8AC8: sltu        $at, $a2, $v0
    ctx->r1 = ctx->r6 < ctx->r2 ? 1 : 0;
    // 0x800C8ACC: beq         $at, $zero, L_800C8AF0
    if (ctx->r1 == 0) {
        // 0x800C8AD0: nop
    
            goto L_800C8AF0;
    }
    // 0x800C8AD0: nop

    // 0x800C8AD4: lbu         $t6, 0x15($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X15);
L_800C8AD8:
    // 0x800C8AD8: beq         $t6, $zero, L_800C8AF0
    if (ctx->r14 == 0) {
        // 0x800C8ADC: nop
    
            goto L_800C8AF0;
    }
    // 0x800C8ADC: nop

    // 0x800C8AE0: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    // 0x800C8AE4: sltu        $at, $a2, $v1
    ctx->r1 = ctx->r6 < ctx->r3 ? 1 : 0;
    // 0x800C8AE8: bnel        $at, $zero, L_800C8AD8
    if (ctx->r1 != 0) {
        // 0x800C8AEC: lbu         $t6, 0x15($a2)
        ctx->r14 = MEM_BU(ctx->r6, 0X15);
            goto L_800C8AD8;
    }
    goto skip_0;
    // 0x800C8AEC: lbu         $t6, 0x15($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X15);
    skip_0:
L_800C8AF0:
    // 0x800C8AF0: bne         $a2, $v0, L_800C8B04
    if (ctx->r6 != ctx->r2) {
        // 0x800C8AF4: nop
    
            goto L_800C8B04;
    }
    // 0x800C8AF4: nop

    // 0x800C8AF8: jal         0x800B2974
    // 0x800C8AFC: addiu       $a0, $a0, -0x5500
    ctx->r4 = ADD32(ctx->r4, -0X5500);
    vector_push_back(rdram, ctx);
        goto after_2;
    // 0x800C8AFC: addiu       $a0, $a0, -0x5500
    ctx->r4 = ADD32(ctx->r4, -0X5500);
    after_2:
    // 0x800C8B00: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_800C8B04:
    // 0x800C8B04: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C8B08: lw          $a0, -0x5500($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5500);
    // 0x800C8B0C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800C8B10: jal         0x800B28E8
    // 0x800C8B14: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    vector_index_of(rdram, ctx);
        goto after_3;
    // 0x800C8B14: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_3:
    // 0x800C8B18: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800C8B1C: addiu       $a0, $v0, 0x1
    ctx->r4 = ADD32(ctx->r2, 0X1);
    // 0x800C8B20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C8B24: addiu       $t7, $zero, 0xB
    ctx->r15 = ADD32(0, 0XB);
    // 0x800C8B28: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800C8B2C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800C8B30: addiu       $a1, $a1, -0x5634
    ctx->r5 = ADD32(ctx->r5, -0X5634);
    // 0x800C8B34: sb          $t7, 0x15($a2)
    MEM_B(0X15, ctx->r6) = ctx->r15;
    // 0x800C8B38: sb          $t9, 0x17($a2)
    MEM_B(0X17, ctx->r6) = ctx->r25;
    // 0x800C8B3C: sb          $t9, 0x16($a2)
    MEM_B(0X16, ctx->r6) = ctx->r25;
    // 0x800C8B40: sb          $zero, 0x14($a2)
    MEM_B(0X14, ctx->r6) = 0;
    // 0x800C8B44: sb          $zero, 0x18($a2)
    MEM_B(0X18, ctx->r6) = 0;
    // 0x800C8B48: jal         0x800C8CB8
    // 0x800C8B4C: sb          $zero, 0x19($a2)
    MEM_B(0X19, ctx->r6) = 0;
    func_800C8CB8(rdram, ctx);
        goto after_4;
    // 0x800C8B4C: sb          $zero, 0x19($a2)
    MEM_B(0X19, ctx->r6) = 0;
    after_4:
    // 0x800C8B50: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800C8B54: addiu       $a1, $a1, -0x5628
    ctx->r5 = ADD32(ctx->r5, -0X5628);
    // 0x800C8B58: jal         0x800C8D4C
    // 0x800C8B5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800C8D4C(rdram, ctx);
        goto after_5;
    // 0x800C8B5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_5:
    // 0x800C8B60: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800C8B64: addiu       $a1, $a1, -0x5620
    ctx->r5 = ADD32(ctx->r5, -0X5620);
    // 0x800C8B68: jal         0x800C8E84
    // 0x800C8B6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800C8E84(rdram, ctx);
        goto after_6;
    // 0x800C8B6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_6:
    // 0x800C8B70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C8B74: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x800C8B78: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C8B7C: jr          $ra
    // 0x800C8B80: nop

    return;
    // 0x800C8B80: nop

;}
RECOMP_FUNC void func_8008FB94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FB94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FB98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FB9C: jal         0x800F54E4
    // 0x8008FBA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8008FBA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008FBA4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008FBA8: jal         0x800F4924
    // 0x8008FBAC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800F4924(rdram, ctx);
        goto after_1;
    // 0x8008FBAC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8008FBB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008FBB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FBB8: jr          $ra
    // 0x8008FBBC: nop

    return;
    // 0x8008FBBC: nop

;}
RECOMP_FUNC void _chglowbo_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086AF0: syscall     414
    recomp_syscall_handler(rdram, ctx, 0x80086AF0);
    return;
    // 0x80086AF4: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_800D41D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D41D8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800D41DC: lh          $t6, -0x49E0($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X49E0);
    // 0x800D41E0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800D41E4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800D41E8: bne         $a0, $t6, L_800D41F8
    if (ctx->r4 != ctx->r14) {
        // 0x800D41EC: nop
    
            goto L_800D41F8;
    }
    // 0x800D41EC: nop

    // 0x800D41F0: jr          $ra
    // 0x800D41F4: lh          $v0, -0x49DE($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X49DE);
    return;
    // 0x800D41F4: lh          $v0, -0x49DE($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X49DE);
L_800D41F8:
    // 0x800D41F8: lh          $t7, -0x49DC($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X49DC);
    // 0x800D41FC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800D4200: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800D4204: bne         $a0, $t7, L_800D4214
    if (ctx->r4 != ctx->r15) {
        // 0x800D4208: nop
    
            goto L_800D4214;
    }
    // 0x800D4208: nop

    // 0x800D420C: jr          $ra
    // 0x800D4210: lh          $v0, -0x49DA($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X49DA);
    return;
    // 0x800D4210: lh          $v0, -0x49DA($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X49DA);
L_800D4214:
    // 0x800D4214: lh          $t8, -0x49D8($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X49D8);
    // 0x800D4218: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800D421C: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800D4220: bne         $a0, $t8, L_800D4234
    if (ctx->r4 != ctx->r24) {
        // 0x800D4224: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_800D4234;
    }
    // 0x800D4224: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800D4228: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800D422C: jr          $ra
    // 0x800D4230: lh          $v0, -0x49D6($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X49D6);
    return;
    // 0x800D4230: lh          $v0, -0x49D6($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X49D6);
L_800D4234:
    // 0x800D4234: addiu       $t0, $t0, -0x49E0
    ctx->r8 = ADD32(ctx->r8, -0X49E0);
    // 0x800D4238: addu        $v1, $t9, $t0
    ctx->r3 = ADD32(ctx->r25, ctx->r8);
    // 0x800D423C: lh          $t1, 0x0($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X0);
    // 0x800D4240: bnel        $a0, $t1, L_800D4254
    if (ctx->r4 != ctx->r9) {
        // 0x800D4244: lh          $t2, 0x4($v1)
        ctx->r10 = MEM_H(ctx->r3, 0X4);
            goto L_800D4254;
    }
    goto skip_0;
    // 0x800D4244: lh          $t2, 0x4($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X4);
    skip_0:
    // 0x800D4248: jr          $ra
    // 0x800D424C: lh          $v0, 0x2($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2);
    return;
    // 0x800D424C: lh          $v0, 0x2($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2);
    // 0x800D4250: lh          $t2, 0x4($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X4);
L_800D4254:
    // 0x800D4254: bnel        $a0, $t2, L_800D4268
    if (ctx->r4 != ctx->r10) {
        // 0x800D4258: lh          $t3, 0x8($v1)
        ctx->r11 = MEM_H(ctx->r3, 0X8);
            goto L_800D4268;
    }
    goto skip_1;
    // 0x800D4258: lh          $t3, 0x8($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X8);
    skip_1:
    // 0x800D425C: jr          $ra
    // 0x800D4260: lh          $v0, 0x6($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X6);
    return;
    // 0x800D4260: lh          $v0, 0x6($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X6);
    // 0x800D4264: lh          $t3, 0x8($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X8);
L_800D4268:
    // 0x800D4268: bnel        $a0, $t3, L_800D427C
    if (ctx->r4 != ctx->r11) {
        // 0x800D426C: lh          $t4, 0xC($v1)
        ctx->r12 = MEM_H(ctx->r3, 0XC);
            goto L_800D427C;
    }
    goto skip_2;
    // 0x800D426C: lh          $t4, 0xC($v1)
    ctx->r12 = MEM_H(ctx->r3, 0XC);
    skip_2:
    // 0x800D4270: jr          $ra
    // 0x800D4274: lh          $v0, 0xA($v1)
    ctx->r2 = MEM_H(ctx->r3, 0XA);
    return;
    // 0x800D4274: lh          $v0, 0xA($v1)
    ctx->r2 = MEM_H(ctx->r3, 0XA);
    // 0x800D4278: lh          $t4, 0xC($v1)
    ctx->r12 = MEM_H(ctx->r3, 0XC);
L_800D427C:
    // 0x800D427C: bnel        $a0, $t4, L_800D4290
    if (ctx->r4 != ctx->r12) {
        // 0x800D4280: addiu       $v0, $zero, 0x3C
        ctx->r2 = ADD32(0, 0X3C);
            goto L_800D4290;
    }
    goto skip_3;
    // 0x800D4280: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    skip_3:
    // 0x800D4284: jr          $ra
    // 0x800D4288: lh          $v0, 0xE($v1)
    ctx->r2 = MEM_H(ctx->r3, 0XE);
    return;
    // 0x800D4288: lh          $v0, 0xE($v1)
    ctx->r2 = MEM_H(ctx->r3, 0XE);
    // 0x800D428C: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
L_800D4290:
    // 0x800D4290: jr          $ra
    // 0x800D4294: nop

    return;
    // 0x800D4294: nop

;}
RECOMP_FUNC void _gcnewoption_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087CF0: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087CF0);
    return;
    // 0x80087CF4: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void chexplodingchainlinks_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1440, 0X170) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x170
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1440, 0X170));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x170
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1440, 0X170));
;}
RECOMP_FUNC void func_808006C4_chnests(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808006C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808006CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808006D0: lhu         $v0, 0x76($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X76);
    // 0x808006D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808006D8: srl         $t6, $v0, 7
    ctx->r14 = S32(U32(ctx->r2) >> 7);
    // 0x808006DC: addiu       $v0, $t6, -0x32
    ctx->r2 = ADD32(ctx->r14, -0X32);
    // 0x808006E0: blez        $v0, L_808006F0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808006E4: slti        $at, $v0, 0x12
        ctx->r1 = SIGNED(ctx->r2) < 0X12 ? 1 : 0;
            goto L_808006F0;
    }
    // 0x808006E4: slti        $at, $v0, 0x12
    ctx->r1 = SIGNED(ctx->r2) < 0X12 ? 1 : 0;
    // 0x808006E8: bne         $at, $zero, L_80800700
    if (ctx->r1 != 0) {
        // 0x808006EC: addiu       $a0, $zero, 0x6
        ctx->r4 = ADD32(0, 0X6);
            goto L_80800700;
    }
    // 0x808006EC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
L_808006F0:
    // 0x808006F0: jal         0x800FFAB0
    // 0x808006F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_0;
    // 0x808006F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x808006F8: b           L_808007B8
    // 0x808006FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808007B8;
    // 0x808006FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800700:
    // 0x80800700: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80800704: jal         0x800D13E8
    // 0x80800708: lbu         $a1, 0x762C($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X762C);
    func_800D13E8(rdram, ctx);
        goto after_1;
    // 0x80800708: lbu         $a1, 0x762C($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X762C);
    after_1:
    // 0x8080070C: lhu         $t7, 0x76($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X76);
    // 0x80800710: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80800714: srl         $t8, $t7, 7
    ctx->r24 = S32(U32(ctx->r15) >> 7);
    // 0x80800718: addu        $a0, $v0, $t8
    ctx->r4 = ADD32(ctx->r2, ctx->r24);
    // 0x8080071C: addiu       $a0, $a0, -0x32
    ctx->r4 = ADD32(ctx->r4, -0X32);
    // 0x80800720: jal         0x800D0B68
    // 0x80800724: sw          $a0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r4;
    func_800D0B68(rdram, ctx);
        goto after_2;
    // 0x80800724: sw          $a0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r4;
    after_2:
    // 0x80800728: beq         $v0, $zero, L_80800740
    if (ctx->r2 == 0) {
        // 0x8080072C: nop
    
            goto L_80800740;
    }
    // 0x8080072C: nop

    // 0x80800730: jal         0x800FFAB0
    // 0x80800734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_3;
    // 0x80800734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800738: b           L_808007B8
    // 0x8080073C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808007B8;
    // 0x8080073C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800740:
    // 0x80800740: jal         0x80800000
    // 0x80800744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_chnests(rdram, ctx);
        goto after_4;
    // 0x80800744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800748: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8080074C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800750: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800754: jal         0x800DC298
    // 0x80800758: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
    func_800DC298(rdram, ctx);
        goto after_5;
    // 0x80800758: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
    after_5:
    // 0x8080075C: beq         $v0, $zero, L_80800774
    if (ctx->r2 == 0) {
        // 0x80800760: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80800774;
    }
    // 0x80800760: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800764: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80800768: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8080076C: b           L_80800780
    // 0x80800770: lui         $at, 0x4407
    ctx->r1 = S32(0X4407 << 16);
        goto L_80800780;
    // 0x80800770: lui         $at, 0x4407
    ctx->r1 = S32(0X4407 << 16);
L_80800774:
    // 0x80800774: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800778: nop

    // 0x8080077C: lui         $at, 0x4407
    ctx->r1 = S32(0X4407 << 16);
L_80800780:
    // 0x80800780: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800784: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(752, 0X10E0) << 16);
    // 0x80800788: lwc1        $f14, 0x10E0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(752, 0X10E0));
    // 0x8080078C: jal         0x800DC178
    // 0x80800790: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x80800790: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    after_6:
    // 0x80800794: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800798: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8080079C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808007A0: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x808007A4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x808007A8: jal         0x800DC178
    // 0x808007AC: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    func_800DC178(rdram, ctx);
        goto after_7;
    // 0x808007AC: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    after_7:
    // 0x808007B0: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x808007B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808007B8:
    // 0x808007B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808007BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808007C0: jr          $ra
    // 0x808007C4: nop

    return;
    // 0x808007C4: nop

;}
RECOMP_FUNC void ncba1p_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800614: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80800618: jr          $ra
    // 0x8080061C: sb          $a1, 0x50($t6)
    MEM_B(0X50, ctx->r14) = ctx->r5;
    return;
    // 0x8080061C: sb          $a1, 0x50($t6)
    MEM_B(0X50, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_800C929C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C929C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C92A0: jr          $ra
    // 0x800C92A4: sb          $zero, -0x54AC($at)
    MEM_B(-0X54AC, ctx->r1) = 0;
    return;
    // 0x800C92A4: sb          $zero, -0x54AC($at)
    MEM_B(-0X54AC, ctx->r1) = 0;
;}
RECOMP_FUNC void func_80800090_chstoneballcoach(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800090: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800094: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800098: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080009C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808000A0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808000A4: beq         $a1, $zero, L_808000EC
    if (ctx->r5 == 0) {
        // 0x808000A8: sw          $a2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r6;
            goto L_808000EC;
    }
    // 0x808000A8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x808000AC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x808000B0: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x808000B4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x808000B8: addiu       $t7, $zero, 0x34
    ctx->r15 = ADD32(0, 0X34);
    // 0x808000BC: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x808000C0: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x808000C4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x808000C8: jal         0x800C05B8
    // 0x808000CC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800C05B8(rdram, ctx);
        goto after_0;
    // 0x808000CC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x808000D0: lbu         $t8, 0x72($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X72);
    // 0x808000D4: lbu         $t2, 0x74($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X74);
    // 0x808000D8: andi        $t9, $t8, 0xFF03
    ctx->r25 = ctx->r24 & 0XFF03;
    // 0x808000DC: ori         $t0, $t9, 0x8
    ctx->r8 = ctx->r25 | 0X8;
    // 0x808000E0: ori         $t3, $t2, 0x40
    ctx->r11 = ctx->r10 | 0X40;
    // 0x808000E4: sb          $t0, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r8;
    // 0x808000E8: sb          $t3, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r11;
L_808000EC:
    // 0x808000EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808000F0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808000F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808000F8: jr          $ra
    // 0x808000FC: nop

    return;
    // 0x808000FC: nop

;}
RECOMP_FUNC void func_80102078(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102078: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010207C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80102080: jal         0x80104248
    // 0x80102084: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80104248(rdram, ctx);
        goto after_0;
    // 0x80102084: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80102088: beq         $v0, $zero, L_80102098
    if (ctx->r2 == 0) {
        // 0x8010208C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80102098;
    }
    // 0x8010208C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80102090: jal         0x8008B1C8
    // 0x80102094: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8008B1C8(rdram, ctx);
        goto after_1;
    // 0x80102094: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
L_80102098:
    // 0x80102098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010209C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801020A0: jr          $ra
    // 0x801020A4: nop

    return;
    // 0x801020A4: nop

;}
RECOMP_FUNC void chbadjinjo_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1576, 0X1288) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x1288
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1576, 0X1288));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x1288
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1576, 0X1288));
;}
RECOMP_FUNC void chnewshovel_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1516, 0XFB4) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xFB4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1516, 0XFB4));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xFB4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1516, 0XFB4));
;}
RECOMP_FUNC void func_80801490_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801490: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801494: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801498: jal         0x800839B8
    // 0x8080149C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsrest_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x8080149C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808014A0: jal         0x808008D8
    // 0x808014A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808008D8_bssub(rdram, ctx);
        goto after_1;
    // 0x808014A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808014A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808014AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808014B0: jr          $ra
    // 0x808014B4: nop

    return;
    // 0x808014B4: nop

;}
RECOMP_FUNC void func_80800068_bscrouch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800068: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080006C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800070: lui         $a3, 0x3F7F
    ctx->r7 = S32(0X3F7F << 16);
    // 0x80800074: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800078: ori         $a3, $a3, 0xF972
    ctx->r7 = ctx->r7 | 0XF972;
    // 0x8080007C: addiu       $a1, $zero, 0x10C
    ctx->r5 = ADD32(0, 0X10C);
    // 0x80800080: jal         0x8008CD30
    // 0x80800084: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    baanim_playForDuration_onceSmoothStartingAt(rdram, ctx);
        goto after_0;
    // 0x80800084: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_0:
    // 0x80800088: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080008C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800090: jal         0x80085338
    // 0x80800094: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    _batimer_set(rdram, ctx);
        goto after_1;
    // 0x80800094: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_1:
    // 0x80800098: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8080009C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808000A0: sw          $t6, 0x15C($t7)
    MEM_W(0X15C, ctx->r15) = ctx->r14;
    // 0x808000A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000AC: jr          $ra
    // 0x808000B0: nop

    return;
    // 0x808000B0: nop

;}
RECOMP_FUNC void func_8009DBB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009DBB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009DBB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009DBB8: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8009DBBC: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x8009DBC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009DBC4: jal         0x800DC178
    // 0x8009DBC8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x8009DBC8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8009DBCC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8009DBD0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8009DBD4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8009DBD8: jal         0x8009DB04
    // 0x8009DBDC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    func_8009DB04(rdram, ctx);
        goto after_1;
    // 0x8009DBDC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8009DBE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009DBE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009DBE8: jr          $ra
    // 0x8009DBEC: nop

    return;
    // 0x8009DBEC: nop

;}
RECOMP_FUNC void _bsbeemain_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800828B0: syscall     17
    recomp_syscall_handler(rdram, ctx, 0x800828B0);
    return;
    // 0x800828B4: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_80800414_bsbansnooze(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800414: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800418: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080041C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800420: lui         $a1, 0x3F45
    ctx->r5 = S32(0X3F45 << 16);
    // 0x80800424: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800428: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8080042C: jal         0x8008CB10
    // 0x80800430: ori         $a1, $a1, 0x1EB8
    ctx->r5 = ctx->r5 | 0X1EB8;
    baanim_isAt(rdram, ctx);
        goto after_0;
    // 0x80800430: ori         $a1, $a1, 0x1EB8
    ctx->r5 = ctx->r5 | 0X1EB8;
    after_0:
    // 0x80800434: beq         $v0, $zero, L_8080044C
    if (ctx->r2 == 0) {
        // 0x80800438: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080044C;
    }
    // 0x80800438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080043C: lui         $a2, 0x3F8C
    ctx->r6 = S32(0X3F8C << 16);
    // 0x80800440: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800444: jal         0x8009DE38
    // 0x80800448: addiu       $a1, $zero, 0x584
    ctx->r5 = ADD32(0, 0X584);
    func_8009DE38(rdram, ctx);
        goto after_1;
    // 0x80800448: addiu       $a1, $zero, 0x584
    ctx->r5 = ADD32(0, 0X584);
    after_1:
L_8080044C:
    // 0x8080044C: lui         $a1, 0x3F27
    ctx->r5 = S32(0X3F27 << 16);
    // 0x80800450: ori         $a1, $a1, 0xD567
    ctx->r5 = ctx->r5 | 0XD567;
    // 0x80800454: jal         0x8008CB10
    // 0x80800458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_2;
    // 0x80800458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080045C: beq         $v0, $zero, L_80800478
    if (ctx->r2 == 0) {
        // 0x80800460: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800478;
    }
    // 0x80800460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800464: jal         0x80084538
    // 0x80800468: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _babackpack_set_state(rdram, ctx);
        goto after_3;
    // 0x80800468: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8080046C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800470: jal         0x800A0CD0
    // 0x80800474: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CD0(rdram, ctx);
        goto after_4;
    // 0x80800474: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
L_80800478:
    // 0x80800478: jal         0x8008CAEC
    // 0x8080047C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_5;
    // 0x8080047C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800480: beq         $v0, $zero, L_80800490
    if (ctx->r2 == 0) {
        // 0x80800484: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800490;
    }
    // 0x80800484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800488: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080048C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800490:
    // 0x80800490: jal         0x8009E5C8
    // 0x80800494: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_6;
    // 0x80800494: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x80800498: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080049C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808004A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808004A4: jr          $ra
    // 0x808004A8: nop

    return;
    // 0x808004A8: nop

;}
RECOMP_FUNC void func_808003BC_chweather(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003C0: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808003C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003C8: bne         $a1, $at, L_808003E0
    if (ctx->r5 != ctx->r1) {
        // 0x808003CC: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_808003E0;
    }
    // 0x808003CC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808003D0: jal         0x80800138
    // 0x808003D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800138_chweather(rdram, ctx);
        goto after_0;
    // 0x808003D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x808003D8: b           L_808003E4
    // 0x808003DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003E4;
    // 0x808003DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003E0:
    // 0x808003E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808003E4:
    // 0x808003E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003EC: jr          $ra
    // 0x808003F0: nop

    return;
    // 0x808003F0: nop

    // 0x808003F4: nop

    // 0x808003F8: nop

    // 0x808003FC: nop

;}
RECOMP_FUNC void func_800F551C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F551C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F5520: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800F5524: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800F5528: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F552C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5530: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x800F5534: jal         0x800A3148
    // 0x800F5538: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_800A3148(rdram, ctx);
        goto after_0;
    // 0x800F5538: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F553C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5540: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F5544: jr          $ra
    // 0x800F5548: nop

    return;
    // 0x800F5548: nop

;}
RECOMP_FUNC void _susplinet_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089E58: syscall     812
    recomp_syscall_handler(rdram, ctx, 0x80089E58);
    return;
    // 0x80089E5C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void glglobalsettings_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800458: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080045C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800460: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800464: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800468: jal         0x80015670
    // 0x8080046C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80015670(rdram, ctx);
        goto after_0;
    // 0x8080046C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800470: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800474: addiu       $s0, $s0, 0x28
    ctx->r16 = ADD32(ctx->r16, 0X28);
    // 0x80800478: addiu       $a0, $zero, 0xBBA
    ctx->r4 = ADD32(0, 0XBBA);
    // 0x8080047C: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    // 0x80800480: slti        $at, $a3, 0x40
    ctx->r1 = SIGNED(ctx->r7) < 0X40 ? 1 : 0;
    // 0x80800484: bne         $at, $zero, L_80800490
    if (ctx->r1 != 0) {
        // 0x80800488: addiu       $a2, $zero, 0x6
        ctx->r6 = ADD32(0, 0X6);
            goto L_80800490;
    }
    // 0x80800488: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8080048C: addiu       $a3, $zero, 0x3F
    ctx->r7 = ADD32(0, 0X3F);
L_80800490:
    // 0x80800490: slti        $at, $s0, 0x40
    ctx->r1 = SIGNED(ctx->r16) < 0X40 ? 1 : 0;
    // 0x80800494: bne         $at, $zero, L_808004A0
    if (ctx->r1 != 0) {
        // 0x80800498: nop
    
            goto L_808004A0;
    }
    // 0x80800498: nop

    // 0x8080049C: addiu       $s0, $zero, 0x3F
    ctx->r16 = ADD32(0, 0X3F);
L_808004A0:
    // 0x808004A0: jal         0x800DA7A8
    // 0x808004A4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_800DA7A8(rdram, ctx);
        goto after_1;
    // 0x808004A4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_1:
    // 0x808004A8: addiu       $a0, $zero, 0xBC0
    ctx->r4 = ADD32(0, 0XBC0);
    // 0x808004AC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808004B0: jal         0x800DA7A8
    // 0x808004B4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_800DA7A8(rdram, ctx);
        goto after_2;
    // 0x808004B4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_2:
    // 0x808004B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808004BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808004C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808004C4: jr          $ra
    // 0x808004C8: nop

    return;
    // 0x808004C8: nop

;}
RECOMP_FUNC void func_80102D20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102D20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102D24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80102D28: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80102D2C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80102D30: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80102D34: jal         0x800F20BC
    // 0x80102D38: lwc1        $f12, 0x48($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X48);
    func_800F20BC(rdram, ctx);
        goto after_0;
    // 0x80102D38: lwc1        $f12, 0x48($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X48);
    after_0:
    // 0x80102D3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80102D40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80102D44: jr          $ra
    // 0x80102D48: nop

    return;
    // 0x80102D48: nop

;}
RECOMP_FUNC void func_80800440_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800440: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800444: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800448: jal         0x808036D8
    // 0x8080044C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808036D8_chgameselect(rdram, ctx);
        goto after_0;
    // 0x8080044C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800450: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800454: lw          $a0, 0x50($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X50);
    // 0x80800458: beql        $a0, $zero, L_8080046C
    if (ctx->r4 == 0) {
        // 0x8080045C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080046C;
    }
    goto skip_0;
    // 0x8080045C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800460: jal         0x8001B084
    // 0x80800464: nop

    heap_free(rdram, ctx);
        goto after_1;
    // 0x80800464: nop

    after_1:
    // 0x80800468: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080046C:
    // 0x8080046C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800470: jr          $ra
    // 0x80800474: nop

    return;
    // 0x80800474: nop

;}
RECOMP_FUNC void vector_insert(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2B38: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B2B3C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B2B40: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800B2B44: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800B2B48: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800B2B4C: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800B2B50: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800B2B54: jal         0x800B2974
    // 0x800B2B58: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    vector_push_back(rdram, ctx);
        goto after_0;
    // 0x800B2B58: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x800B2B5C: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x800B2B60: lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X4);
    // 0x800B2B64: lw          $t6, 0x8($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X8);
    // 0x800B2B68: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x800B2B6C: subu        $t7, $t6, $v1
    ctx->r15 = SUB32(ctx->r14, ctx->r3);
    // 0x800B2B70: div         $zero, $t7, $a2
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r6)));
    // 0x800B2B74: bne         $a2, $zero, L_800B2B80
    if (ctx->r6 != 0) {
        // 0x800B2B78: nop
    
            goto L_800B2B80;
    }
    // 0x800B2B78: nop

    // 0x800B2B7C: break       7
    do_break(2148215676);
L_800B2B80:
    // 0x800B2B80: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B2B84: bne         $a2, $at, L_800B2B98
    if (ctx->r6 != ctx->r1) {
        // 0x800B2B88: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B2B98;
    }
    // 0x800B2B88: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B2B8C: bne         $t7, $at, L_800B2B98
    if (ctx->r15 != ctx->r1) {
        // 0x800B2B90: nop
    
            goto L_800B2B98;
    }
    // 0x800B2B90: nop

    // 0x800B2B94: break       6
    do_break(2148215700);
L_800B2B98:
    // 0x800B2B98: mflo        $s0
    ctx->r16 = lo;
    // 0x800B2B9C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800B2BA0: slt         $at, $s3, $s0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800B2BA4: beq         $at, $zero, L_800B2BF0
    if (ctx->r1 == 0) {
        // 0x800B2BA8: nop
    
            goto L_800B2BF0;
    }
    // 0x800B2BA8: nop

L_800B2BAC:
    // 0x800B2BAC: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x800B2BB0: addiu       $s1, $s0, -0x1
    ctx->r17 = ADD32(ctx->r16, -0X1);
    // 0x800B2BB4: lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X4);
    // 0x800B2BB8: multu       $s0, $a2
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B2BBC: mflo        $t8
    ctx->r24 = lo;
    // 0x800B2BC0: addu        $a0, $v1, $t8
    ctx->r4 = ADD32(ctx->r3, ctx->r24);
    // 0x800B2BC4: nop

    // 0x800B2BC8: multu       $s1, $a2
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B2BCC: mflo        $t9
    ctx->r25 = lo;
    // 0x800B2BD0: addu        $a1, $v1, $t9
    ctx->r5 = ADD32(ctx->r3, ctx->r25);
    // 0x800B2BD4: jal         0x8001BBC8
    // 0x800B2BD8: nop

    aligned4_memcpy(rdram, ctx);
        goto after_1;
    // 0x800B2BD8: nop

    after_1:
    // 0x800B2BDC: slt         $at, $s3, $s1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800B2BE0: bne         $at, $zero, L_800B2BAC
    if (ctx->r1 != 0) {
        // 0x800B2BE4: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800B2BAC;
    }
    // 0x800B2BE4: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800B2BE8: lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X4);
    // 0x800B2BEC: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
L_800B2BF0:
    // 0x800B2BF0: multu       $s3, $a2
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B2BF4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800B2BF8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800B2BFC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800B2C00: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800B2C04: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2C08: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800B2C0C: mflo        $t0
    ctx->r8 = lo;
    // 0x800B2C10: addu        $v0, $v1, $t0
    ctx->r2 = ADD32(ctx->r3, ctx->r8);
    // 0x800B2C14: jr          $ra
    // 0x800B2C18: nop

    return;
    // 0x800B2C18: nop

;}
RECOMP_FUNC void func_8010FE34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010FE34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8010FE38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010FE3C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010FE40: lbu         $v0, 0x20($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X20);
    // 0x8010FE44: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8010FE48: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8010FE4C: beq         $v0, $zero, L_8010FEBC
    if (ctx->r2 == 0) {
        // 0x8010FE50: lui         $a1, 0x8013
        ctx->r5 = S32(0X8013 << 16);
            goto L_8010FEBC;
    }
    // 0x8010FE50: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8010FE54: lh          $t6, 0x16($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X16);
    // 0x8010FE58: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8010FE5C: sb          $zero, 0x20($a0)
    MEM_B(0X20, ctx->r4) = 0;
    // 0x8010FE60: bne         $t6, $at, L_8010FEBC
    if (ctx->r14 != ctx->r1) {
        // 0x8010FE64: addiu       $at, $zero, 0x28
        ctx->r1 = ADD32(0, 0X28);
            goto L_8010FEBC;
    }
    // 0x8010FE64: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x8010FE68: beq         $v0, $at, L_8010FE84
    if (ctx->r2 == ctx->r1) {
        // 0x8010FE6C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8010FE84;
    }
    // 0x8010FE6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010FE70: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x8010FE74: beql        $v0, $at, L_8010FEA4
    if (ctx->r2 == ctx->r1) {
        // 0x8010FE78: lw          $a0, 0x4($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X4);
            goto L_8010FEA4;
    }
    goto skip_0;
    // 0x8010FE78: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    skip_0:
    // 0x8010FE7C: b           L_8010FEAC
    // 0x8010FE80: nop

        goto L_8010FEAC;
    // 0x8010FE80: nop

L_8010FE84:
    // 0x8010FE84: addiu       $a1, $s0, 0x24
    ctx->r5 = ADD32(ctx->r16, 0X24);
    // 0x8010FE88: jal         0x8010FE14
    // 0x8010FE8C: addiu       $a2, $s0, 0x30
    ctx->r6 = ADD32(ctx->r16, 0X30);
    func_8010FE14(rdram, ctx);
        goto after_0;
    // 0x8010FE8C: addiu       $a2, $s0, 0x30
    ctx->r6 = ADD32(ctx->r16, 0X30);
    after_0:
    // 0x8010FE90: jal         0x801108A0
    // 0x8010FE94: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    func_801108A0(rdram, ctx);
        goto after_1;
    // 0x8010FE94: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_1:
    // 0x8010FE98: b           L_8010FEAC
    // 0x8010FE9C: nop

        goto L_8010FEAC;
    // 0x8010FE9C: nop

    // 0x8010FEA0: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
L_8010FEA4:
    // 0x8010FEA4: jal         0x80110970
    // 0x8010FEA8: lw          $a1, 0x3C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X3C);
    func_80110970(rdram, ctx);
        goto after_2;
    // 0x8010FEA8: lw          $a1, 0x3C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X3C);
    after_2:
L_8010FEAC:
    // 0x8010FEAC: jal         0x8010FD08
    // 0x8010FEB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010FD08(rdram, ctx);
        goto after_3;
    // 0x8010FEB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8010FEB4: b           L_8010FF70
    // 0x8010FEB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8010FF70;
    // 0x8010FEB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8010FEBC:
    // 0x8010FEBC: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8010FEC0: addiu       $a2, $a2, 0x7330
    ctx->r6 = ADD32(ctx->r6, 0X7330);
    // 0x8010FEC4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8010FEC8: jal         0x80089438
    // 0x8010FECC: addiu       $a1, $a1, 0x7320
    ctx->r5 = ADD32(ctx->r5, 0X7320);
    _ncstart_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x8010FECC: addiu       $a1, $a1, 0x7320
    ctx->r5 = ADD32(ctx->r5, 0X7320);
    after_4:
    // 0x8010FED0: bnel        $v0, $zero, L_8010FF04
    if (ctx->r2 != 0) {
        // 0x8010FED4: lh          $t8, 0x16($s0)
        ctx->r24 = MEM_H(ctx->r16, 0X16);
            goto L_8010FF04;
    }
    goto skip_1;
    // 0x8010FED4: lh          $t8, 0x16($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X16);
    skip_1:
    // 0x8010FED8: lh          $t7, 0x16($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X16);
    // 0x8010FEDC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8010FEE0: bne         $t7, $at, L_8010FEF0
    if (ctx->r15 != ctx->r1) {
        // 0x8010FEE4: nop
    
            goto L_8010FEF0;
    }
    // 0x8010FEE4: nop

    // 0x8010FEE8: jal         0x80110928
    // 0x8010FEEC: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    func_80110928(rdram, ctx);
        goto after_5;
    // 0x8010FEEC: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_5:
L_8010FEF0:
    // 0x8010FEF0: jal         0x8010FD08
    // 0x8010FEF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010FD08(rdram, ctx);
        goto after_6;
    // 0x8010FEF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8010FEF8: b           L_8010FF70
    // 0x8010FEFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8010FF70;
    // 0x8010FEFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010FF00: lh          $t8, 0x16($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X16);
L_8010FF04:
    // 0x8010FF04: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8010FF08: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8010FF0C: bne         $t8, $at, L_8010FF24
    if (ctx->r24 != ctx->r1) {
        // 0x8010FF10: addiu       $a1, $a1, 0x7330
        ctx->r5 = ADD32(ctx->r5, 0X7330);
            goto L_8010FF24;
    }
    // 0x8010FF10: addiu       $a1, $a1, 0x7330
    ctx->r5 = ADD32(ctx->r5, 0X7330);
    // 0x8010FF14: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8010FF18: addiu       $a2, $a2, 0x7320
    ctx->r6 = ADD32(ctx->r6, 0X7320);
    // 0x8010FF1C: jal         0x80110A24
    // 0x8010FF20: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    func_80110A24(rdram, ctx);
        goto after_7;
    // 0x8010FF20: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_7:
L_8010FF24:
    // 0x8010FF24: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8010FF28: addiu       $a1, $a1, 0x7320
    ctx->r5 = ADD32(ctx->r5, 0X7320);
    // 0x8010FF2C: jal         0x800CA5B8
    // 0x8010FF30: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800CA5B8(rdram, ctx);
        goto after_8;
    // 0x8010FF30: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_8:
    // 0x8010FF34: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8010FF38: addiu       $a1, $a1, 0x7330
    ctx->r5 = ADD32(ctx->r5, 0X7330);
    // 0x8010FF3C: jal         0x800CA668
    // 0x8010FF40: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800CA668(rdram, ctx);
        goto after_9;
    // 0x8010FF40: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_9:
    // 0x8010FF44: jal         0x800CAF34
    // 0x8010FF48: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800CAF34(rdram, ctx);
        goto after_10;
    // 0x8010FF48: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_10:
    // 0x8010FF4C: lh          $t9, 0x16($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X16);
    // 0x8010FF50: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8010FF54: bnel        $t9, $at, L_8010FF70
    if (ctx->r25 != ctx->r1) {
        // 0x8010FF58: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8010FF70;
    }
    goto skip_2;
    // 0x8010FF58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8010FF5C: jal         0x801108A0
    // 0x8010FF60: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    func_801108A0(rdram, ctx);
        goto after_11;
    // 0x8010FF60: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_11:
    // 0x8010FF64: jal         0x8010FD08
    // 0x8010FF68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010FD08(rdram, ctx);
        goto after_12;
    // 0x8010FF68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8010FF6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8010FF70:
    // 0x8010FF70: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8010FF74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8010FF78: jr          $ra
    // 0x8010FF7C: nop

    return;
    // 0x8010FF7C: nop

;}
RECOMP_FUNC void func_80801C20_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801C24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801C28: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801C2C: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80801C30: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801C34: sll         $t8, $t6, 13
    ctx->r24 = S32(ctx->r14 << 13);
    // 0x80801C38: bltzl       $t8, L_80801D5C
    if (SIGNED(ctx->r24) < 0) {
        // 0x80801C3C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801D5C;
    }
    goto skip_0;
    // 0x80801C3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80801C40: lbu         $t0, 0x75($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X75);
    // 0x80801C44: lhu         $t2, 0x72($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X72);
    // 0x80801C48: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801C4C: ori         $t1, $t0, 0x4
    ctx->r9 = ctx->r8 | 0X4;
    // 0x80801C50: srl         $t3, $t2, 10
    ctx->r11 = S32(U32(ctx->r10) >> 10);
    // 0x80801C54: beq         $t3, $at, L_80801D58
    if (ctx->r11 == ctx->r1) {
        // 0x80801C58: sb          $t1, 0x75($a0)
        MEM_B(0X75, ctx->r4) = ctx->r9;
            goto L_80801D58;
    }
    // 0x80801C58: sb          $t1, 0x75($a0)
    MEM_B(0X75, ctx->r4) = ctx->r9;
    // 0x80801C5C: jal         0x800EA090
    // 0x80801C60: nop

    func_800EA090(rdram, ctx);
        goto after_0;
    // 0x80801C60: nop

    after_0:
    // 0x80801C64: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801C68: beq         $v0, $at, L_80801CEC
    if (ctx->r2 == ctx->r1) {
        // 0x80801C6C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80801CEC;
    }
    // 0x80801C6C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801C70: beq         $v0, $at, L_80801CC8
    if (ctx->r2 == ctx->r1) {
        // 0x80801C74: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801CC8;
    }
    // 0x80801C74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C78: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801C7C: bnel        $v0, $at, L_80801D5C
    if (ctx->r2 != ctx->r1) {
        // 0x80801C80: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801D5C;
    }
    goto skip_1;
    // 0x80801C80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80801C84: jal         0x800C964C
    // 0x80801C88: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_800C964C(rdram, ctx);
        goto after_1;
    // 0x80801C88: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_1:
    // 0x80801C8C: jal         0x80801BA0
    // 0x80801C90: nop

    func_80801BA0_chtntmineshoot(rdram, ctx);
        goto after_2;
    // 0x80801C90: nop

    after_2:
    // 0x80801C94: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801C98: jal         0x80800078
    // 0x80801C9C: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    func_80800078_chtntmineshoot(rdram, ctx);
        goto after_3;
    // 0x80801C9C: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    after_3:
    // 0x80801CA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801CA4: jal         0x80101FDC
    // 0x80801CA8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x80801CA8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_4:
    // 0x80801CAC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80801CB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801CB4: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80801CB8: jal         0x80085708
    // 0x80801CBC: addiu       $a3, $zero, 0x2000
    ctx->r7 = ADD32(0, 0X2000);
    _capod_entrypoint_13(rdram, ctx);
        goto after_5;
    // 0x80801CBC: addiu       $a3, $zero, 0x2000
    ctx->r7 = ADD32(0, 0X2000);
    after_5:
    // 0x80801CC0: b           L_80801D5C
    // 0x80801CC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801D5C;
    // 0x80801CC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801CC8:
    // 0x80801CC8: jal         0x80101FDC
    // 0x80801CCC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_6;
    // 0x80801CCC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_6:
    // 0x80801CD0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80801CD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801CD8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80801CDC: jal         0x80085708
    // 0x80801CE0: addiu       $a3, $zero, 0x2000
    ctx->r7 = ADD32(0, 0X2000);
    _capod_entrypoint_13(rdram, ctx);
        goto after_7;
    // 0x80801CE0: addiu       $a3, $zero, 0x2000
    ctx->r7 = ADD32(0, 0X2000);
    after_7:
    // 0x80801CE4: b           L_80801D5C
    // 0x80801CE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801D5C;
    // 0x80801CE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801CEC:
    // 0x80801CEC: jal         0x800C6E38
    // 0x80801CF0: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    func_800C6E38(rdram, ctx);
        goto after_8;
    // 0x80801CF0: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_8:
    // 0x80801CF4: beql        $v0, $zero, L_80801D5C
    if (ctx->r2 == 0) {
        // 0x80801CF8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801D5C;
    }
    goto skip_2;
    // 0x80801CF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80801CFC: jal         0x800F5410
    // 0x80801D00: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800F5410(rdram, ctx);
        goto after_9;
    // 0x80801D00: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x80801D04: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801D08: bne         $v0, $at, L_80801D58
    if (ctx->r2 != ctx->r1) {
        // 0x80801D0C: addiu       $a0, $zero, 0x6B9
        ctx->r4 = ADD32(0, 0X6B9);
            goto L_80801D58;
    }
    // 0x80801D0C: addiu       $a0, $zero, 0x6B9
    ctx->r4 = ADD32(0, 0X6B9);
    // 0x80801D10: jal         0x800DA9E4
    // 0x80801D14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_10;
    // 0x80801D14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80801D18: bne         $v0, $zero, L_80801D58
    if (ctx->r2 != 0) {
        // 0x80801D1C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801D58;
    }
    // 0x80801D1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D20: jal         0x80101FDC
    // 0x80801D24: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_11;
    // 0x80801D24: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_11:
    // 0x80801D28: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80801D2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801D30: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80801D34: jal         0x80085708
    // 0x80801D38: addiu       $a3, $zero, 0x2020
    ctx->r7 = ADD32(0, 0X2020);
    _capod_entrypoint_13(rdram, ctx);
        goto after_12;
    // 0x80801D38: addiu       $a3, $zero, 0x2020
    ctx->r7 = ADD32(0, 0X2020);
    after_12:
    // 0x80801D3C: jal         0x800F54E4
    // 0x80801D40: nop

    func_800F54E4(rdram, ctx);
        goto after_13;
    // 0x80801D40: nop

    after_13:
    // 0x80801D44: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80801D48: addiu       $a1, $a1, 0x4318
    ctx->r5 = ADD32(ctx->r5, 0X4318);
    // 0x80801D4C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801D50: jal         0x800F49D4
    // 0x80801D54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800F49D4(rdram, ctx);
        goto after_14;
    // 0x80801D54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_14:
L_80801D58:
    // 0x80801D58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801D5C:
    // 0x80801D5C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801D60: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801D64: jr          $ra
    // 0x80801D68: nop

    return;
    // 0x80801D68: nop

;}
RECOMP_FUNC void _bsdronegoto_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800830E0: syscall     43
    recomp_syscall_handler(rdram, ctx, 0x800830E0);
    return;
    // 0x800830E4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800C9FD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9FD0: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x800C9FD4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C9FD8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C9FDC: addiu       $s0, $s0, -0x54A0
    ctx->r16 = ADD32(ctx->r16, -0X54A0);
    // 0x800C9FE0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800C9FE4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C9FE8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C9FEC: beql        $a0, $zero, L_800CA050
    if (ctx->r4 == 0) {
        // 0x800C9FF0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800CA050;
    }
    goto skip_0;
    // 0x800C9FF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800C9FF4: jal         0x800B2928
    // 0x800C9FF8: nop

    vector_size(rdram, ctx);
        goto after_0;
    // 0x800C9FF8: nop

    after_0:
    // 0x800C9FFC: blez        $v0, L_800CA040
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800CA000: addiu       $s1, $sp, 0x24
        ctx->r17 = ADD32(ctx->r29, 0X24);
            goto L_800CA040;
    }
    // 0x800CA000: addiu       $s1, $sp, 0x24
    ctx->r17 = ADD32(ctx->r29, 0X24);
L_800CA004:
    // 0x800CA004: jal         0x800B28C4
    // 0x800CA008: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    vector_begin(rdram, ctx);
        goto after_1;
    // 0x800CA008: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x800CA00C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800CA010: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800CA014: jal         0x8001BBA0
    // 0x800CA018: addiu       $a2, $zero, 0x70
    ctx->r6 = ADD32(0, 0X70);
    rare_memcpy(rdram, ctx);
        goto after_2;
    // 0x800CA018: addiu       $a2, $zero, 0x70
    ctx->r6 = ADD32(0, 0X70);
    after_2:
    // 0x800CA01C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800CA020: jal         0x800B2E30
    // 0x800CA024: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    vector_erase(rdram, ctx);
        goto after_3;
    // 0x800CA024: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x800CA028: jal         0x800C986C
    // 0x800CA02C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800C986C(rdram, ctx);
        goto after_4;
    // 0x800CA02C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x800CA030: jal         0x800B2928
    // 0x800CA034: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    vector_size(rdram, ctx);
        goto after_5;
    // 0x800CA034: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_5:
    // 0x800CA038: bgtz        $v0, L_800CA004
    if (SIGNED(ctx->r2) > 0) {
        // 0x800CA03C: nop
    
            goto L_800CA004;
    }
    // 0x800CA03C: nop

L_800CA040:
    // 0x800CA040: jal         0x800B2D28
    // 0x800CA044: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    vector_free(rdram, ctx);
        goto after_6;
    // 0x800CA044: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_6:
    // 0x800CA048: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x800CA04C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800CA050:
    // 0x800CA050: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800CA054: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800CA058: jr          $ra
    // 0x800CA05C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x800CA05C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_80803F70_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803F70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80803F74: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80803F78: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80803F7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80803F80: jal         0x80106790
    // 0x80803F84: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80803F84: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x80803F88: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x80803F8C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803F90: andi        $t6, $a1, 0x1FF
    ctx->r14 = ctx->r5 & 0X1FF;
    // 0x80803F94: jal         0x80089AF8
    // 0x80803F98: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    _sukickball_entrypoint_12(rdram, ctx);
        goto after_1;
    // 0x80803F98: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_1:
    // 0x80803F9C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80803FA0: bnel        $v0, $at, L_80803FC0
    if (ctx->r2 != ctx->r1) {
        // 0x80803FA4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803FC0;
    }
    goto skip_0;
    // 0x80803FA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80803FA8: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x80803FAC: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80803FB0: andi        $t7, $a0, 0x1FF
    ctx->r15 = ctx->r4 & 0X1FF;
    // 0x80803FB4: jal         0x80089AB8
    // 0x80803FB8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    _sukickball_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80803FB8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_2:
    // 0x80803FBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80803FC0:
    // 0x80803FC0: jal         0x80102D78
    // 0x80803FC4: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    func_80102D78(rdram, ctx);
        goto after_3;
    // 0x80803FC4: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_3:
    // 0x80803FC8: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80803FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803FD0: jal         0x80102CF4
    // 0x80803FD4: lui         $a1, 0x4180
    ctx->r5 = S32(0X4180 << 16);
    func_80102CF4(rdram, ctx);
        goto after_4;
    // 0x80803FD4: lui         $a1, 0x4180
    ctx->r5 = S32(0X4180 << 16);
    after_4:
    // 0x80803FD8: bne         $v0, $zero, L_80803FF4
    if (ctx->r2 != 0) {
        // 0x80803FDC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803FF4;
    }
    // 0x80803FDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803FE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803FE4: jal         0x80102B2C
    // 0x80803FE8: lui         $a1, 0x4180
    ctx->r5 = S32(0X4180 << 16);
    func_80102B2C(rdram, ctx);
        goto after_5;
    // 0x80803FE8: lui         $a1, 0x4180
    ctx->r5 = S32(0X4180 << 16);
    after_5:
    // 0x80803FEC: b           L_8080404C
    // 0x80803FF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080404C;
    // 0x80803FF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803FF4:
    // 0x80803FF4: jal         0x80102CF4
    // 0x80803FF8: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    func_80102CF4(rdram, ctx);
        goto after_6;
    // 0x80803FF8: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_6:
    // 0x80803FFC: bne         $v0, $zero, L_80804018
    if (ctx->r2 != 0) {
        // 0x80804000: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_80804018;
    }
    // 0x80804000: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80804004: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804008: jal         0x80102B2C
    // 0x8080400C: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    func_80102B2C(rdram, ctx);
        goto after_7;
    // 0x8080400C: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_7:
    // 0x80804010: b           L_8080404C
    // 0x80804014: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080404C;
    // 0x80804014: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80804018:
    // 0x80804018: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080401C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80804020: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80804024: jal         0x800DC178
    // 0x80804028: nop

    func_800DC178(rdram, ctx);
        goto after_8;
    // 0x80804028: nop

    after_8:
    // 0x8080402C: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x80804030: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x80804034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804038: ori         $t0, $t9, 0x10
    ctx->r8 = ctx->r25 | 0X10;
    // 0x8080403C: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    // 0x80804040: jal         0x8080324C
    // 0x80804044: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8080324C_chcollballcontrol(rdram, ctx);
        goto after_9;
    // 0x80804044: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x80804048: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080404C:
    // 0x8080404C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80804050: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80804054: jr          $ra
    // 0x80804058: nop

    return;
    // 0x80804058: nop

;}
RECOMP_FUNC void func_80803FF4_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803FF4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80803FF8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80803FFC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80804000: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80804004: beq         $a1, $zero, L_80804028
    if (ctx->r5 == 0) {
        // 0x80804008: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80804028;
    }
    // 0x80804008: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8080400C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80804010: beq         $a1, $at, L_80804048
    if (ctx->r5 == ctx->r1) {
        // 0x80804014: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80804048;
    }
    // 0x80804014: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80804018: beq         $a1, $at, L_80804068
    if (ctx->r5 == ctx->r1) {
        // 0x8080401C: nop
    
            goto L_80804068;
    }
    // 0x8080401C: nop

    // 0x80804020: b           L_80804088
    // 0x80804024: nop

        goto L_80804088;
    // 0x80804024: nop

L_80804028:
    // 0x80804028: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4FA0) << 16);
    // 0x8080402C: lwc1        $f12, 0x4FA0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4FA0));
    // 0x80804030: jal         0x800DC298
    // 0x80804034: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800DC298(rdram, ctx);
        goto after_0;
    // 0x80804034: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x80804038: beq         $v0, $zero, L_80804088
    if (ctx->r2 == 0) {
        // 0x8080403C: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_80804088;
    }
    // 0x8080403C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80804040: b           L_808040A4
    // 0x80804044: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808040A4;
    // 0x80804044: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80804048:
    // 0x80804048: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4FA4) << 16);
    // 0x8080404C: lwc1        $f12, 0x4FA4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4FA4));
    // 0x80804050: jal         0x800DC298
    // 0x80804054: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800DC298(rdram, ctx);
        goto after_1;
    // 0x80804054: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x80804058: beq         $v0, $zero, L_80804088
    if (ctx->r2 == 0) {
        // 0x8080405C: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_80804088;
    }
    // 0x8080405C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80804060: b           L_808040A4
    // 0x80804064: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808040A4;
    // 0x80804064: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80804068:
    // 0x80804068: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4FA8) << 16);
    // 0x8080406C: lwc1        $f12, 0x4FA8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4FA8));
    // 0x80804070: jal         0x800DC298
    // 0x80804074: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800DC298(rdram, ctx);
        goto after_2;
    // 0x80804074: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_2:
    // 0x80804078: beq         $v0, $zero, L_80804088
    if (ctx->r2 == 0) {
        // 0x8080407C: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_80804088;
    }
    // 0x8080407C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80804080: b           L_808040A4
    // 0x80804084: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808040A4;
    // 0x80804084: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80804088:
    // 0x80804088: bne         $s0, $s0, L_808040A0
    if (ctx->r16 != ctx->r16) {
        // 0x8080408C: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_808040A0;
    }
L_8080408C:
    // 0x8080408C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80804090: jal         0x800DC128
    // 0x80804094: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800DC128(rdram, ctx);
        goto after_3;
    // 0x80804094: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
    // 0x80804098: beq         $v0, $s0, L_8080408C
    if (ctx->r2 == ctx->r16) {
        // 0x8080409C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8080408C;
    }
    // 0x8080409C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_808040A0:
    // 0x808040A0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_808040A4:
    // 0x808040A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808040A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808040AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808040B0: jr          $ra
    // 0x808040B4: nop

    return;
    // 0x808040B4: nop

;}
RECOMP_FUNC void baduo_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800540: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800544: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800548: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8080054C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800550: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800554: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800558: jal         0x800F6224
    // 0x8080055C: lw          $a0, 0x184($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X184);
    func_800F6224(rdram, ctx);
        goto after_0;
    // 0x8080055C: lw          $a0, 0x184($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X184);
    after_0:
    // 0x80800560: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800564: jal         0x800F53D0
    // 0x80800568: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F53D0(rdram, ctx);
        goto after_1;
    // 0x80800568: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8080056C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800570: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800574: jal         0x800F452C
    // 0x80800578: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800F452C(rdram, ctx);
        goto after_2;
    // 0x80800578: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x8080057C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800580: jal         0x800A3410
    // 0x80800584: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    func_800A3410(rdram, ctx);
        goto after_3;
    // 0x80800584: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_3:
    // 0x80800588: jal         0x80092778
    // 0x8080058C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80092778(rdram, ctx);
        goto after_4;
    // 0x8080058C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800590: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800594: jal         0x80800008
    // 0x80800598: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80800008_baduo(rdram, ctx);
        goto after_5;
    // 0x80800598: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x8080059C: jal         0x800844B0
    // 0x808005A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bababykaz_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x808005A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808005A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005A8: jal         0x8009E5C8
    // 0x808005AC: addiu       $a1, $zero, 0x139
    ctx->r5 = ADD32(0, 0X139);
    bs_setState(rdram, ctx);
        goto after_7;
    // 0x808005AC: addiu       $a1, $zero, 0x139
    ctx->r5 = ADD32(0, 0X139);
    after_7:
    // 0x808005B0: jal         0x8009C984
    // 0x808005B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_get(rdram, ctx);
        goto after_8;
    // 0x808005B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x808005B8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808005BC: jal         0x8009C944
    // 0x808005C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_set(rdram, ctx);
        goto after_9;
    // 0x808005C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808005C4: jal         0x8009C990
    // 0x808005C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_10;
    // 0x808005C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x808005CC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808005D0: jal         0x8009C914
    // 0x808005D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_11;
    // 0x808005D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808005D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005DC: jal         0x800844C0
    // 0x808005E0: lw          $a1, 0x184($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X184);
    _bababykaz_entrypoint_10(rdram, ctx);
        goto after_12;
    // 0x808005E0: lw          $a1, 0x184($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X184);
    after_12:
    // 0x808005E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808005E8: jal         0x80084368
    // 0x808005EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _bsfirstp_entrypoint_28(rdram, ctx);
        goto after_13;
    // 0x808005EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_13:
    // 0x808005F0: jal         0x800A91A8
    // 0x808005F4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800A91A8(rdram, ctx);
        goto after_14;
    // 0x808005F4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_14:
    // 0x808005F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808005FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800600: jal         0x800A38F0
    // 0x80800604: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800A38F0(rdram, ctx);
        goto after_15;
    // 0x80800604: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_15:
    // 0x80800608: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080060C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800610: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800614: jr          $ra
    // 0x80800618: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800618: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
