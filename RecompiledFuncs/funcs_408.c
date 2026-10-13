#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _baattach_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084458: syscall     111
    recomp_syscall_handler(rdram, ctx, 0x80084458);
    return;
    // 0x8008445C: xori        $t0, $zero, 0x10
    ctx->r8 = 0 ^ 0X10;
;}
RECOMP_FUNC void func_80809900_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80809900: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80809904: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80809908: jal         0x80802534
    // 0x8080990C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80802534_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x8080990C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80809910: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80809914: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80809918: jal         0x80800424
    // 0x8080991C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_80800424_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x8080991C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_1:
    // 0x80809920: jal         0x808001FC
    // 0x80809924: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808001FC_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80809924: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80809928: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080992C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80809930: jr          $ra
    // 0x80809934: nop

    return;
    // 0x80809934: nop

;}
RECOMP_FUNC void func_800B3310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3310: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B3314: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800B3318: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800B331C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B3320: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800B3324: sll         $v0, $t6, 2
    ctx->r2 = S32(ctx->r14 << 2);
    // 0x800B3328: addiu       $a0, $v0, 0x18
    ctx->r4 = ADD32(ctx->r2, 0X18);
    // 0x800B332C: jal         0x8001ACCC
    // 0x800B3330: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x800B3330: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // 0x800B3334: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800B3338: jal         0x800B38C8
    // 0x800B333C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800B38C8(rdram, ctx);
        goto after_1;
    // 0x800B333C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x800B3340: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3344: addiu       $a0, $v0, 0x18
    ctx->r4 = ADD32(ctx->r2, 0X18);
    // 0x800B3348: sw          $a0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r4;
    // 0x800B334C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800B3350: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x800B3354: sw          $t8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r24;
    // 0x800B3358: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800B335C: sw          $t9, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r25;
    // 0x800B3360: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B3364: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B3368: jr          $ra
    // 0x800B336C: nop

    return;
    // 0x800B336C: nop

;}
RECOMP_FUNC void bavan_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
;}
RECOMP_FUNC void anseq_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800200: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800204: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80800208: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8080020C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80800210: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80800214: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80800218: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080021C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800220: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80800224: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80800228: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8080022C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80800230: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800234: jal         0x80800134
    // 0x80800238: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_80800134_anseq(rdram, ctx);
        goto after_0;
    // 0x80800238: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_0:
    // 0x8080023C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800240: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800244: jr          $ra
    // 0x80800248: nop

    return;
    // 0x80800248: nop

;}
RECOMP_FUNC void func_8009E9A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E9A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009E9AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009E9B0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8009E9B4: jal         0x8009E9FC
    // 0x8009E9B8: nop

    func_8009E9FC(rdram, ctx);
        goto after_0;
    // 0x8009E9B8: nop

    after_0:
    // 0x8009E9BC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8009E9C0: jal         0x8009EB0C
    // 0x8009E9C4: nop

    func_8009EB0C(rdram, ctx);
        goto after_1;
    // 0x8009E9C4: nop

    after_1:
    // 0x8009E9C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009E9CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009E9D0: jr          $ra
    // 0x8009E9D4: nop

    return;
    // 0x8009E9D4: nop

;}
RECOMP_FUNC void func_800A0D68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A0D68: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x800A0D6C: jr          $ra
    // 0x800A0D70: sb          $a1, 0x17($t6)
    MEM_B(0X17, ctx->r14) = ctx->r5;
    return;
    // 0x800A0D70: sb          $a1, 0x17($t6)
    MEM_B(0X17, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_808006F8_chpoolkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808006FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800700: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800704: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80800708: jal         0x800DA298
    // 0x8080070C: addiu       $a0, $zero, 0x166
    ctx->r4 = ADD32(0, 0X166);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x8080070C: addiu       $a0, $zero, 0x166
    ctx->r4 = ADD32(0, 0X166);
    after_0:
    // 0x80800710: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800714: jal         0x800DA298
    // 0x80800718: addiu       $a0, $zero, 0x167
    ctx->r4 = ADD32(0, 0X167);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800718: addiu       $a0, $zero, 0x167
    ctx->r4 = ADD32(0, 0X167);
    after_1:
    // 0x8080071C: jal         0x80088848
    // 0x80800720: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_2;
    // 0x80800720: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x80800724: beq         $v0, $zero, L_8080073C
    if (ctx->r2 == 0) {
        // 0x80800728: nop
    
            goto L_8080073C;
    }
    // 0x80800728: nop

    // 0x8080072C: jal         0x80800618
    // 0x80800730: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80800618_chpoolkids(rdram, ctx);
        goto after_3;
    // 0x80800730: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80800734: b           L_808007C8
    // 0x80800738: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
        goto L_808007C8;
    // 0x80800738: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
L_8080073C:
    // 0x8080073C: jal         0x80088840
    // 0x80800740: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_4;
    // 0x80800740: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_4:
    // 0x80800744: bnel        $v0, $zero, L_8080075C
    if (ctx->r2 != 0) {
        // 0x80800748: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8080075C;
    }
    goto skip_0;
    // 0x80800748: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    skip_0:
    // 0x8080074C: jal         0x80088840
    // 0x80800750: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_5;
    // 0x80800750: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_5:
    // 0x80800754: beq         $v0, $zero, L_80800764
    if (ctx->r2 == 0) {
        // 0x80800758: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80800764;
    }
    // 0x80800758: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_8080075C:
    // 0x8080075C: b           L_808007C4
    // 0x80800760: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
        goto L_808007C4;
    // 0x80800760: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_80800764:
    // 0x80800764: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80800768: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8080076C: beq         $v0, $zero, L_8080078C
    if (ctx->r2 == 0) {
        // 0x80800770: nop
    
            goto L_8080078C;
    }
    // 0x80800770: nop

    // 0x80800774: bne         $v1, $zero, L_8080078C
    if (ctx->r3 != 0) {
        // 0x80800778: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_8080078C;
    }
    // 0x80800778: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080077C: jal         0x80102424
    // 0x80800780: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x80800780: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_6:
    // 0x80800784: b           L_808007C8
    // 0x80800788: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
        goto L_808007C8;
    // 0x80800788: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
L_8080078C:
    // 0x8080078C: bne         $v0, $zero, L_808007AC
    if (ctx->r2 != 0) {
        // 0x80800790: lw          $v1, 0x20($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X20);
            goto L_808007AC;
    }
    // 0x80800790: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80800794: beq         $v1, $zero, L_808007AC
    if (ctx->r3 == 0) {
        // 0x80800798: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_808007AC;
    }
    // 0x80800798: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080079C: jal         0x80102424
    // 0x808007A0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_7;
    // 0x808007A0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_7:
    // 0x808007A4: b           L_808007C8
    // 0x808007A8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
        goto L_808007C8;
    // 0x808007A8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
L_808007AC:
    // 0x808007AC: beql        $v0, $zero, L_808007C8
    if (ctx->r2 == 0) {
        // 0x808007B0: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_808007C8;
    }
    goto skip_1;
    // 0x808007B0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x808007B4: beql        $v1, $zero, L_808007C8
    if (ctx->r3 == 0) {
        // 0x808007B8: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_808007C8;
    }
    goto skip_2;
    // 0x808007B8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x808007BC: jal         0x80800618
    // 0x808007C0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80800618_chpoolkids(rdram, ctx);
        goto after_8;
    // 0x808007C0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_8:
L_808007C4:
    // 0x808007C4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
L_808007C8:
    // 0x808007C8: beql        $t7, $zero, L_808007E4
    if (ctx->r15 == 0) {
        // 0x808007CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808007E4;
    }
    goto skip_3;
    // 0x808007CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x808007D0: jal         0x800DA524
    // 0x808007D4: addiu       $a0, $zero, 0x168
    ctx->r4 = ADD32(0, 0X168);
    func_800DA524(rdram, ctx);
        goto after_9;
    // 0x808007D4: addiu       $a0, $zero, 0x168
    ctx->r4 = ADD32(0, 0X168);
    after_9:
    // 0x808007D8: jal         0x800DA524
    // 0x808007DC: addiu       $a0, $zero, 0x1CE
    ctx->r4 = ADD32(0, 0X1CE);
    func_800DA524(rdram, ctx);
        goto after_10;
    // 0x808007DC: addiu       $a0, $zero, 0x1CE
    ctx->r4 = ADD32(0, 0X1CE);
    after_10:
    // 0x808007E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808007E4:
    // 0x808007E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808007E8: jr          $ra
    // 0x808007EC: nop

    return;
    // 0x808007EC: nop

;}
RECOMP_FUNC void func_800BA4C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA4C4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800BA4C8: jr          $ra
    // 0x800BA4CC: swc1        $f12, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x800BA4CC: swc1        $f12, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_80800DD8_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800DDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800DE0: jal         0x808006F0
    // 0x80800DE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bstrexlarge_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800DE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800DE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800DEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800DF0: jal         0x80800BC4
    // 0x80800DF4: sb          $zero, 0x15C($a0)
    MEM_B(0X15C, ctx->r4) = 0;
    func_80800BC4_bstrexlarge(rdram, ctx);
        goto after_1;
    // 0x80800DF4: sb          $zero, 0x15C($a0)
    MEM_B(0X15C, ctx->r4) = 0;
    after_1:
    // 0x80800DF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800DFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800E00: jr          $ra
    // 0x80800E04: nop

    return;
    // 0x80800E04: nop

;}
RECOMP_FUNC void func_8080000C_choctopus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1028, 0X820) << 16);
    // 0x80800018: lwc1        $f6, 0x820($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1028, 0X820));
    // 0x8080001C: lwc1        $f4, 0x38($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80800020: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800024: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800028: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8080002C: jal         0x80102FDC
    // 0x80800030: nop

    func_80102FDC(rdram, ctx);
        goto after_0;
    // 0x80800030: nop

    after_0:
    // 0x80800034: jal         0x80089F48
    // 0x80800038: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _subaddiesect_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800038: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080003C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800040: sw          $v0, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r2;
    // 0x80800044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800048: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080004C: jr          $ra
    // 0x80800050: nop

    return;
    // 0x80800050: nop

;}
RECOMP_FUNC void func_80800114_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800114: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800118: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8080011C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80800120: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80800124: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80800128: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1840, 0X4CF0) << 16);
    // 0x8080012C: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x80800130: jr          $ra
    // 0x80800134: lw          $v0, 0x4CF0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(1840, 0X4CF0));
    return;
    // 0x80800134: lw          $v0, 0x4CF0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(1840, 0X4CF0));
;}
RECOMP_FUNC void func_8008FBC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FBC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FBC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FBC8: jal         0x8008FB94
    // 0x8008FBCC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    func_8008FB94(rdram, ctx);
        goto after_0;
    // 0x8008FBCC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_0:
    // 0x8008FBD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008FBD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FBD8: jr          $ra
    // 0x8008FBDC: nop

    return;
    // 0x8008FBDC: nop

;}
RECOMP_FUNC void func_80800A4C_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800A50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A54: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800A58: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(804, 0X7DFC) << 16);
    // 0x80800A5C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800A60: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80800A64: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80800A68: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800A6C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80800A70: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800A74: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x80800A78: lw          $v0, 0x7DFC($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(804, 0X7DFC));
    // 0x80800A7C: beql        $v0, $zero, L_80800A90
    if (ctx->r2 == 0) {
        // 0x80800A80: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800A90;
    }
    goto skip_0;
    // 0x80800A80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800A84: jalr        $v0
    // 0x80800A88: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80800A88: nop

    after_0:
    // 0x80800A8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800A90:
    // 0x80800A90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A94: jr          $ra
    // 0x80800A98: nop

    return;
    // 0x80800A98: nop

;}
RECOMP_FUNC void _bamum_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084F08: syscall     142
    recomp_syscall_handler(rdram, ctx, 0x80084F08);
    return;
    // 0x80084F0C: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void func_8001E380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E380: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001E384: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E388: jal         0x8001E2A0
    // 0x8001E38C: nop

    func_8001E2A0(rdram, ctx);
        goto after_0;
    // 0x8001E38C: nop

    after_0:
    // 0x8001E390: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001E394: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001E398: jr          $ra
    // 0x8001E39C: nop

    return;
    // 0x8001E39C: nop

;}
RECOMP_FUNC void func_808001C8_chdinocoaster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001C8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808001CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001D0: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x808001D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001DC: beq         $a1, $at, L_80800210
    if (ctx->r5 == ctx->r1) {
        // 0x808001E0: sw          $a2, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r6;
            goto L_80800210;
    }
    // 0x808001E0: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x808001E4: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x808001E8: beq         $a1, $at, L_80800244
    if (ctx->r5 == ctx->r1) {
        // 0x808001EC: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(1072, 0X468) << 16);
            goto L_80800244;
    }
    // 0x808001EC: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1072, 0X468) << 16);
    // 0x808001F0: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x808001F4: beq         $a1, $at, L_80800254
    if (ctx->r5 == ctx->r1) {
        // 0x808001F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800254;
    }
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001FC: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800200: beql        $a1, $at, L_8080029C
    if (ctx->r5 == ctx->r1) {
        // 0x80800204: lbu         $t7, 0x65($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X65);
            goto L_8080029C;
    }
    goto skip_0;
    // 0x80800204: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    skip_0:
    // 0x80800208: b           L_808002A4
    // 0x8080020C: nop

        goto L_808002A4;
    // 0x8080020C: nop

L_80800210:
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800214: jal         0x80101FDC
    // 0x80800218: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_80101FDC(rdram, ctx);
        goto after_0;
    // 0x80800218: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_0:
    // 0x8080021C: jal         0x8010A590
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_1;
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800224: lh          $t6, 0x40($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X40);
    // 0x80800228: addiu       $at, $zero, 0x17B8
    ctx->r1 = ADD32(0, 0X17B8);
    // 0x8080022C: bnel        $t6, $at, L_808002B8
    if (ctx->r14 != ctx->r1) {
        // 0x80800230: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808002B8;
    }
    goto skip_1;
    // 0x80800230: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x80800234: jal         0x8009032C
    // 0x80800238: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    func_8009032C(rdram, ctx);
        goto after_2;
    // 0x80800238: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_2:
    // 0x8080023C: b           L_808002B8
    // 0x80800240: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808002B8;
    // 0x80800240: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800244:
    // 0x80800244: jal         0x80101074
    // 0x80800248: addiu       $a0, $a0, 0x468
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1072, 0X468));
    func_80101074(rdram, ctx);
        goto after_3;
    // 0x80800248: addiu       $a0, $a0, 0x468
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1072, 0X468));
    after_3:
    // 0x8080024C: b           L_808002B8
    // 0x80800250: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_808002B8;
    // 0x80800250: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_80800254:
    // 0x80800254: jal         0x8010CD28
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010CD28(rdram, ctx);
        goto after_4;
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080025C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800260: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800264: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800268: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8080026C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80800270: jal         0x800EFA4C
    // 0x80800274: nop

    func_800EFA4C(rdram, ctx);
        goto after_5;
    // 0x80800274: nop

    after_5:
    // 0x80800278: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1072, 0X544) << 16);
    // 0x8080027C: addiu       $a0, $a0, 0x544
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1072, 0X544));
    // 0x80800280: jal         0x80088090
    // 0x80800284: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x80800284: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_6:
    // 0x80800288: jal         0x800880A0
    // 0x8080028C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    _gcdialogcamera_entrypoint_5(rdram, ctx);
        goto after_7;
    // 0x8080028C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_7:
    // 0x80800290: b           L_808002B8
    // 0x80800294: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808002B8;
    // 0x80800294: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800298: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
L_8080029C:
    // 0x8080029C: andi        $t8, $t7, 0xFFEF
    ctx->r24 = ctx->r15 & 0XFFEF;
    // 0x808002A0: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
L_808002A4:
    // 0x808002A4: jal         0x8008A1A0
    // 0x808002A8: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    _sucoaster_entrypoint_21(rdram, ctx);
        goto after_8;
    // 0x808002A8: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_8:
    // 0x808002AC: b           L_808002BC
    // 0x808002B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002BC;
    // 0x808002B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002B8:
    // 0x808002B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002BC:
    // 0x808002BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002C0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808002C4: jr          $ra
    // 0x808002C8: nop

    return;
    // 0x808002C8: nop

;}
RECOMP_FUNC void func_800E705C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E705C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800E7060: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x800E7064: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800E7068: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800E706C: beq         $t7, $zero, L_800E7084
    if (ctx->r15 == 0) {
        // 0x800E7070: addiu       $t9, $zero, 0x30
        ctx->r25 = ADD32(0, 0X30);
            goto L_800E7084;
    }
    // 0x800E7070: addiu       $t9, $zero, 0x30
    ctx->r25 = ADD32(0, 0X30);
    // 0x800E7074: lbu         $t8, 0x1($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X1);
L_800E7078:
    // 0x800E7078: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800E707C: bnel        $t8, $zero, L_800E7078
    if (ctx->r24 != 0) {
        // 0x800E7080: lbu         $t8, 0x1($a0)
        ctx->r24 = MEM_BU(ctx->r4, 0X1);
            goto L_800E7078;
    }
    goto skip_0;
    // 0x800E7080: lbu         $t8, 0x1($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X1);
    skip_0:
L_800E7084:
    // 0x800E7084: addiu       $t0, $zero, 0x78
    ctx->r8 = ADD32(0, 0X78);
    // 0x800E7088: sb          $t9, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r25;
    // 0x800E708C: sb          $t0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r8;
    // 0x800E7090: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800E7094: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800E7098: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
L_800E709C:
    // 0x800E709C: srav        $v0, $v1, $a2
    ctx->r2 = S32(SIGNED(ctx->r3) >> (ctx->r6 & 31));
    // 0x800E70A0: andi        $t1, $v0, 0xF
    ctx->r9 = ctx->r2 & 0XF;
    // 0x800E70A4: slti        $t2, $t1, 0xA
    ctx->r10 = SIGNED(ctx->r9) < 0XA ? 1 : 0;
    // 0x800E70A8: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x800E70AC: beq         $t3, $zero, L_800E70C0
    if (ctx->r11 == 0) {
        // 0x800E70B0: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_800E70C0;
    }
    // 0x800E70B0: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800E70B4: addiu       $t4, $t1, 0x30
    ctx->r12 = ADD32(ctx->r9, 0X30);
    // 0x800E70B8: b           L_800E70C8
    // 0x800E70BC: sb          $t4, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r12;
        goto L_800E70C8;
    // 0x800E70BC: sb          $t4, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r12;
L_800E70C0:
    // 0x800E70C0: addiu       $t5, $v0, 0x37
    ctx->r13 = ADD32(ctx->r2, 0X37);
    // 0x800E70C4: sb          $t5, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r13;
L_800E70C8:
    // 0x800E70C8: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x800E70CC: bgez        $a2, L_800E709C
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800E70D0: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800E709C;
    }
    // 0x800E70D0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800E70D4: jr          $ra
    // 0x800E70D8: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    return;
    // 0x800E70D8: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
;}
RECOMP_FUNC void bsblongleg_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A94: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800A98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800AA0: jal         0x80800994
    // 0x80800AA4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800994_bsblongleg(rdram, ctx);
        goto after_0;
    // 0x80800AA4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800AA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AAC: jal         0x8008CA4C
    // 0x80800AB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008CA4C(rdram, ctx);
        goto after_1;
    // 0x80800AB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800AB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AB8: jal         0x8009D2D8
    // 0x80800ABC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009D2D8(rdram, ctx);
        goto after_2;
    // 0x80800ABC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80800AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AC4: jal         0x8009B9B0
    // 0x80800AC8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_3;
    // 0x80800AC8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x80800ACC: jal         0x800C2E04
    // 0x80800AD0: nop

    func_800C2E04(rdram, ctx);
        goto after_4;
    // 0x80800AD0: nop

    after_4:
    // 0x80800AD4: sb          $v0, 0x160($s0)
    MEM_B(0X160, ctx->r16) = ctx->r2;
    // 0x80800AD8: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x80800ADC: jal         0x800C301C
    // 0x80800AE0: addiu       $a1, $zero, 0x41D
    ctx->r5 = ADD32(0, 0X41D);
    func_800C301C(rdram, ctx);
        goto after_5;
    // 0x80800AE0: addiu       $a1, $zero, 0x41D
    ctx->r5 = ADD32(0, 0X41D);
    after_5:
    // 0x80800AE4: lbu         $a0, 0x160($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X160);
    // 0x80800AE8: jal         0x800C330C
    // 0x80800AEC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800C330C(rdram, ctx);
        goto after_6;
    // 0x80800AEC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x80800AF0: lui         $a1, 0x3FB3
    ctx->r5 = S32(0X3FB3 << 16);
    // 0x80800AF4: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x80800AF8: lui         $a3, 0xBF99
    ctx->r7 = S32(0XBF99 << 16);
    // 0x80800AFC: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80800B00: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800B04: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80800B08: jal         0x800C3730
    // 0x80800B0C: lbu         $a0, 0x160($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X160);
    func_800C3730(rdram, ctx);
        goto after_7;
    // 0x80800B0C: lbu         $a0, 0x160($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X160);
    after_7:
    // 0x80800B10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B14: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800B18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800B1C: jr          $ra
    // 0x80800B20: nop

    return;
    // 0x80800B20: nop

;}
RECOMP_FUNC void _badata_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800846E8: syscall     118
    recomp_syscall_handler(rdram, ctx, 0x800846E8);
    return;
    // 0x800846EC: addi        $t0, $zero, 0x54
    ctx->r8 = ADD32(0, 0X54);
;}
RECOMP_FUNC void func_800A8178(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8178: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A817C: jr          $ra
    // 0x800A8180: lh          $v0, 0x7634($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X7634);
    return;
    // 0x800A8180: lh          $v0, 0x7634($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X7634);
;}
RECOMP_FUNC void _suexpression_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800897B0: syscall     795
    recomp_syscall_handler(rdram, ctx, 0x800897B0);
    return;
    // 0x800897B4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _bsbtrot_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082BF0: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082BF0);
    return;
    // 0x80082BF4: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_808000B0_bsmumswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000B8: jal         0x8009EF1C
    // 0x808000BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    bastick_getZonePosition(rdram, ctx);
        goto after_0;
    // 0x808000BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000C0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x808000C4: jal         0x8009EF10
    // 0x808000C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bastick_getZone(rdram, ctx);
        goto after_1;
    // 0x808000C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808000CC: bne         $v0, $zero, L_808000E8
    if (ctx->r2 != 0) {
        // 0x808000D0: lwc1        $f12, 0x1C($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_808000E8;
    }
    // 0x808000D0: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x808000D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808000D8: jal         0x8009B9B0
    // 0x808000DC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x808000DC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x808000E0: b           L_80800108
    // 0x808000E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800108;
    // 0x808000E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000E8:
    // 0x808000E8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x808000EC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808000F0: jal         0x800F1214
    // 0x808000F4: lui         $a2, 0x43AF
    ctx->r6 = S32(0X43AF << 16);
    func_800F1214(rdram, ctx);
        goto after_3;
    // 0x808000F4: lui         $a2, 0x43AF
    ctx->r6 = S32(0X43AF << 16);
    after_3:
    // 0x808000F8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808000FC: jal         0x8009B9B0
    // 0x80800100: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x80800100: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80800104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800108:
    // 0x80800108: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080010C: jr          $ra
    // 0x80800110: nop

    return;
    // 0x80800110: nop

;}
RECOMP_FUNC void func_800FAF78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FAF78: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800FAF7C: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x800FAF80: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800FAF84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FAF88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800FAF8C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800FAF90: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800FAF94: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x800FAF98: jal         0x800EFB24
    // 0x800FAF9C: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_800EFB24(rdram, ctx);
        goto after_0;
    // 0x800FAF9C: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_0:
    // 0x800FAFA0: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800FAFA4: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x800FAFA8: jal         0x800EFB24
    // 0x800FAFAC: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    func_800EFB24(rdram, ctx);
        goto after_1;
    // 0x800FAFAC: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    after_1:
    // 0x800FAFB0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x800FAFB4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800FAFB8: jal         0x800EFB24
    // 0x800FAFBC: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    func_800EFB24(rdram, ctx);
        goto after_2;
    // 0x800FAFBC: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_2:
    // 0x800FAFC0: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800FAFC4: jal         0x800EEAA4
    // 0x800FAFC8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800EEAA4(rdram, ctx);
        goto after_3;
    // 0x800FAFC8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_3:
    // 0x800FAFCC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800FAFD0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800FAFD4: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    // 0x800FAFD8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800FAFDC: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x800FAFE0: nop

    // 0x800FAFE4: bc1fl       L_800FAFF4
    if (!c1cs) {
        // 0x800FAFE8: lwc1        $f6, 0x0($a0)
        ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
            goto L_800FAFF4;
    }
    goto skip_0;
    // 0x800FAFE8: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x800FAFEC: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x800FAFF0: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
L_800FAFF4:
    // 0x800FAFF4: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800FAFF8: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800FAFFC: mul.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x800FB000: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800FB004: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800FB008: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x800FB00C: lwc1        $f18, 0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800FB010: mul.s       $f6, $f12, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x800FB014: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x800FB018: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x800FB01C: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800FB020: mul.s       $f18, $f12, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x800FB024: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800FB028: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    // 0x800FB02C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FB030: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800FB034: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800FB038: jr          $ra
    // 0x800FB03C: nop

    return;
    // 0x800FB03C: nop

;}
RECOMP_FUNC void func_80800588_chtntdetonator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800588: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080058C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800590: lhu         $a2, 0x72($a0)
    ctx->r6 = MEM_HU(ctx->r4, 0X72);
    // 0x80800594: addiu       $a1, $a0, 0x18
    ctx->r5 = ADD32(ctx->r4, 0X18);
    // 0x80800598: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(904, 0X798) << 16);
    // 0x8080059C: srl         $t6, $a2, 10
    ctx->r14 = S32(U32(ctx->r6) >> 10);
    // 0x808005A0: xori        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 ^ 0X2;
    // 0x808005A4: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x808005A8: bne         $t7, $zero, L_808005C4
    if (ctx->r15 != 0) {
        // 0x808005AC: or          $a2, $t7, $zero
        ctx->r6 = ctx->r15 | 0;
            goto L_808005C4;
    }
    // 0x808005AC: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x808005B0: bnel        $t7, $zero, L_808005D0
    if (ctx->r15 != 0) {
        // 0x808005B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808005D0;
    }
    goto skip_0;
    // 0x808005B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808005B8: lbu         $t8, 0x5F($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X5F);
    // 0x808005BC: beql        $t8, $zero, L_808005D0
    if (ctx->r24 == 0) {
        // 0x808005C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808005D0;
    }
    goto skip_1;
    // 0x808005C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
L_808005C4:
    // 0x808005C4: jal         0x80089D50
    // 0x808005C8: addiu       $a3, $a3, 0x798
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(904, 0X798));
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808005C8: addiu       $a3, $a3, 0x798
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(904, 0X798));
    after_0:
    // 0x808005CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808005D0:
    // 0x808005D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808005D4: jr          $ra
    // 0x808005D8: nop

    return;
    // 0x808005D8: nop

;}
RECOMP_FUNC void _baswim_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800852D0: syscall     156
    recomp_syscall_handler(rdram, ctx, 0x800852D0);
    return;
    // 0x800852D4: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void func_80800174_bstntswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800174: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800178: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080017C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800180: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800184: jal         0x8009E69C
    // 0x80800188: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009E69C(rdram, ctx);
        goto after_0;
    // 0x80800188: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8080018C: bne         $v0, $zero, L_808001B0
    if (ctx->r2 != 0) {
        // 0x80800190: nop
    
            goto L_808001B0;
    }
    // 0x80800190: nop

    // 0x80800194: jal         0x8009BC90
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_terminal_velocity(rdram, ctx);
        goto after_1;
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080019C: jal         0x8009BC6C
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_2;
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808001A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A8: jal         0x800961AC
    // 0x808001AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800961AC(rdram, ctx);
        goto after_3;
    // 0x808001AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
L_808001B0:
    // 0x808001B0: jal         0x80083F60
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bstnt_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808001B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001C4: jr          $ra
    // 0x808001C8: nop

    return;
    // 0x808001C8: nop

;}
RECOMP_FUNC void func_80801F30_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801F30: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801F34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801F38: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801F3C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80801F40: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801F44: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80801F48: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80801F4C: jal         0x80100094
    // 0x80801F50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801F50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801F54: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80801F58: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80801F5C: slti        $at, $a3, 0xCEC
    ctx->r1 = SIGNED(ctx->r7) < 0XCEC ? 1 : 0;
    // 0x80801F60: bne         $at, $zero, L_80801F88
    if (ctx->r1 != 0) {
        // 0x80801F64: addiu       $t6, $a3, -0x1355
        ctx->r14 = ADD32(ctx->r7, -0X1355);
            goto L_80801F88;
    }
    // 0x80801F64: addiu       $t6, $a3, -0x1355
    ctx->r14 = ADD32(ctx->r7, -0X1355);
    // 0x80801F68: sltiu       $at, $t6, 0xB
    ctx->r1 = ctx->r14 < 0XB ? 1 : 0;
    // 0x80801F6C: beq         $at, $zero, L_808020EC
    if (ctx->r1 == 0) {
        // 0x80801F70: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_808020EC;
    }
    // 0x80801F70: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80801F74: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1360, 0X4504) << 16);
    // 0x80801F78: addu        $at, $at, $t6
    gpr jr_addend_80801F80 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80801F7C: lw          $t6, 0x4504($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1360, 0X4504));
    // 0x80801F80: jr          $t6
    // 0x80801F84: nop

    switch (jr_addend_80801F80 >> 2) {
        case 0: goto L_80801F9C; break;
        case 1: goto L_80801F9C; break;
        case 2: goto L_808020EC; break;
        case 3: goto L_808020EC; break;
        case 4: goto L_80802094; break;
        case 5: goto L_808020EC; break;
        case 6: goto L_808020EC; break;
        case 7: goto L_808020EC; break;
        case 8: goto L_80802028; break;
        case 9: goto L_8080203C; break;
        case 10: goto L_8080206C; break;
        default: switch_error(__func__, 0x80801F80, 0x80804504);
    }
    // 0x80801F84: nop

L_80801F88:
    // 0x80801F88: addiu       $at, $zero, 0xCEB
    ctx->r1 = ADD32(0, 0XCEB);
    // 0x80801F8C: beq         $a3, $at, L_808020CC
    if (ctx->r7 == ctx->r1) {
        // 0x80801F90: lw          $t2, 0x38($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X38);
            goto L_808020CC;
    }
    // 0x80801F90: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80801F94: b           L_808020F0
    // 0x80801F98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808020F0;
    // 0x80801F98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801F9C:
    // 0x80801F9C: jal         0x800DA544
    // 0x80801FA0: addiu       $a0, $zero, 0x174
    ctx->r4 = ADD32(0, 0X174);
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x80801FA0: addiu       $a0, $zero, 0x174
    ctx->r4 = ADD32(0, 0X174);
    after_1:
    // 0x80801FA4: jal         0x80088178
    // 0x80801FA8: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    _gcfrontend_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x80801FA8: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_2:
    // 0x80801FAC: jal         0x80803D64
    // 0x80801FB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803D64_chweldarboss(rdram, ctx);
        goto after_3;
    // 0x80801FB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801FB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801FB8: jal         0x80801AA0
    // 0x80801FBC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_4;
    // 0x80801FBC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_4:
    // 0x80801FC0: jal         0x800FDC28
    // 0x80801FC4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800FDC28(rdram, ctx);
        goto after_5;
    // 0x80801FC4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_5:
    // 0x80801FC8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80801FCC: jal         0x800BF744
    // 0x80801FD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800BF744(rdram, ctx);
        goto after_6;
    // 0x80801FD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80801FD4: addiu       $a0, $zero, 0x3A7
    ctx->r4 = ADD32(0, 0X3A7);
    // 0x80801FD8: jal         0x80089C30
    // 0x80801FDC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_7;
    // 0x80801FDC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_7:
    // 0x80801FE0: beq         $v0, $zero, L_808020EC
    if (ctx->r2 == 0) {
        // 0x80801FE4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808020EC;
    }
    // 0x80801FE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80801FE8:
    // 0x80801FE8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1360, 0X4530) << 16);
    // 0x80801FEC: lwc1        $f6, 0x4530($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1360, 0X4530));
    // 0x80801FF0: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80801FF4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80801FF8: nop

    // 0x80801FFC: bc1fl       L_80802010
    if (!c1cs) {
        // 0x80802000: addiu       $a0, $zero, 0x3A7
        ctx->r4 = ADD32(0, 0X3A7);
            goto L_80802010;
    }
    goto skip_0;
    // 0x80802000: addiu       $a0, $zero, 0x3A7
    ctx->r4 = ADD32(0, 0X3A7);
    skip_0:
    // 0x80802004: jal         0x800FFAB0
    // 0x80802008: nop

    func_800FFAB0(rdram, ctx);
        goto after_8;
    // 0x80802008: nop

    after_8:
    // 0x8080200C: addiu       $a0, $zero, 0x3A7
    ctx->r4 = ADD32(0, 0X3A7);
L_80802010:
    // 0x80802010: jal         0x80089C38
    // 0x80802014: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    _subaddiefind_entrypoint_3(rdram, ctx);
        goto after_9;
    // 0x80802014: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_9:
    // 0x80802018: bne         $v0, $zero, L_80801FE8
    if (ctx->r2 != 0) {
        // 0x8080201C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80801FE8;
    }
    // 0x8080201C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802020: b           L_808020F0
    // 0x80802024: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808020F0;
    // 0x80802024: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802028:
    // 0x80802028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080202C: jal         0x80801AA0
    // 0x80802030: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_10;
    // 0x80802030: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    after_10:
    // 0x80802034: b           L_808020F0
    // 0x80802038: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808020F0;
    // 0x80802038: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080203C:
    // 0x8080203C: jal         0x808036C8
    // 0x80802040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808036C8_chweldarboss(rdram, ctx);
        goto after_11;
    // 0x80802040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80802044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802048: addiu       $a1, $zero, 0x135F
    ctx->r5 = ADD32(0, 0X135F);
    // 0x8080204C: jal         0x80802214
    // 0x80802050: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_80802214_chweldarboss(rdram, ctx);
        goto after_12;
    // 0x80802050: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_12:
    // 0x80802054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802058: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    // 0x8080205C: jal         0x80803CF0
    // 0x80802060: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_80803CF0_chweldarboss(rdram, ctx);
        goto after_13;
    // 0x80802060: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_13:
    // 0x80802064: b           L_808020F0
    // 0x80802068: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808020F0;
    // 0x80802068: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080206C:
    // 0x8080206C: jal         0x80803D64
    // 0x80802070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803D64_chweldarboss(rdram, ctx);
        goto after_14;
    // 0x80802070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80802074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802078: jal         0x80801AA0
    // 0x8080207C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_15;
    // 0x8080207C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_15:
    // 0x80802080: jal         0x808033D8
    // 0x80802084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808033D8_chweldarboss(rdram, ctx);
        goto after_16;
    // 0x80802084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80802088: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8080208C: b           L_808020EC
    // 0x80802090: sb          $v0, 0x63($t7)
    MEM_B(0X63, ctx->r15) = ctx->r2;
        goto L_808020EC;
    // 0x80802090: sb          $v0, 0x63($t7)
    MEM_B(0X63, ctx->r15) = ctx->r2;
L_80802094:
    // 0x80802094: lhu         $t8, 0x72($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X72);
    // 0x80802098: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8080209C: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x808020A0: bnel        $t9, $at, L_808020F0
    if (ctx->r25 != ctx->r1) {
        // 0x808020A4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808020F0;
    }
    goto skip_1;
    // 0x808020A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x808020A8: jal         0x80803D64
    // 0x808020AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803D64_chweldarboss(rdram, ctx);
        goto after_17;
    // 0x808020AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x808020B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808020B4: jal         0x80801AA0
    // 0x808020B8: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_18;
    // 0x808020B8: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_18:
    // 0x808020BC: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x808020C0: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x808020C4: b           L_808020EC
    // 0x808020C8: sb          $t0, 0x63($t1)
    MEM_B(0X63, ctx->r9) = ctx->r8;
        goto L_808020EC;
    // 0x808020C8: sb          $t0, 0x63($t1)
    MEM_B(0X63, ctx->r9) = ctx->r8;
L_808020CC:
    // 0x808020CC: blez        $t2, L_808020E4
    if (SIGNED(ctx->r10) <= 0) {
        // 0x808020D0: nop
    
            goto L_808020E4;
    }
    // 0x808020D0: nop

    // 0x808020D4: jal         0x80088188
    // 0x808020D8: nop

    _gcfrontend_entrypoint_11(rdram, ctx);
        goto after_19;
    // 0x808020D8: nop

    after_19:
    // 0x808020DC: b           L_808020F0
    // 0x808020E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808020F0;
    // 0x808020E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808020E4:
    // 0x808020E4: jal         0x80088180
    // 0x808020E8: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_20;
    // 0x808020E8: nop

    after_20:
L_808020EC:
    // 0x808020EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808020F0:
    // 0x808020F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808020F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808020F8: jr          $ra
    // 0x808020FC: nop

    return;
    // 0x808020FC: nop

;}
RECOMP_FUNC void bsfirstp_entrypoint_36(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80809490: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80809494: lui         $v0, 0x8081
    ctx->r2 = S32(RELOC_HI16(439, 0XB5D0) << 16);
    // 0x80809498: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080949C: jr          $ra
    // 0x808094A0: lw          $v0, -0x4A30($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(439, 0XB5D0));
    return;
    // 0x808094A0: lw          $v0, -0x4A30($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(439, 0XB5D0));
;}
RECOMP_FUNC void func_801072A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801072A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801072AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801072B0: jal         0x80106F30
    // 0x801072B4: nop

    func_80106F30(rdram, ctx);
        goto after_0;
    // 0x801072B4: nop

    after_0:
    // 0x801072B8: bne         $v0, $zero, L_801072C8
    if (ctx->r2 != 0) {
        // 0x801072BC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801072C8;
    }
    // 0x801072BC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801072C0: b           L_801072D4
    // 0x801072C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801072D4;
    // 0x801072C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801072C8:
    // 0x801072C8: lh          $v0, 0xA($v1)
    ctx->r2 = MEM_H(ctx->r3, 0XA);
    // 0x801072CC: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x801072D0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_801072D4:
    // 0x801072D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801072D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801072DC: jr          $ra
    // 0x801072E0: nop

    return;
    // 0x801072E0: nop

;}
RECOMP_FUNC void subaddiestore_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800004: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800008: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8080000C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80800014: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800018: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8080001C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800020: jal         0x808003AC
    // 0x80800024: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_808003AC_subaddiestore(rdram, ctx);
        goto after_0;
    // 0x80800024: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x80800028: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8080002C: subu        $s1, $s0, $a0
    ctx->r17 = SUB32(ctx->r16, ctx->r4);
    // 0x80800030: jal         0x8001B208
    // 0x80800034: addu        $a1, $s1, $v0
    ctx->r5 = ADD32(ctx->r17, ctx->r2);
    heap_realloc(rdram, ctx);
        goto after_1;
    // 0x80800034: addu        $a1, $s1, $v0
    ctx->r5 = ADD32(ctx->r17, ctx->r2);
    after_1:
    // 0x80800038: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8080003C: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80800040: addu        $v1, $v0, $s1
    ctx->r3 = ADD32(ctx->r2, ctx->r17);
    // 0x80800044: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
    // 0x80800048: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8080004C: addiu       $s2, $sp, 0x2C
    ctx->r18 = ADD32(ctx->r29, 0X2C);
    // 0x80800050: addiu       $s0, $v1, 0x4
    ctx->r16 = ADD32(ctx->r3, 0X4);
    // 0x80800054: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800058: jal         0x801067C4
    // 0x8080005C: sh          $t7, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r15;
    func_801067C4(rdram, ctx);
        goto after_2;
    // 0x8080005C: sh          $t7, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r15;
    after_2:
    // 0x80800060: beq         $v0, $zero, L_80800084
    if (ctx->r2 == 0) {
        // 0x80800064: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800084;
    }
    // 0x80800064: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80800068:
    // 0x80800068: jal         0x808004FC
    // 0x8080006C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_808004FC_subaddiestore(rdram, ctx);
        goto after_3;
    // 0x8080006C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x80800070: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800074: jal         0x8010682C
    // 0x80800078: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    func_8010682C(rdram, ctx);
        goto after_4;
    // 0x80800078: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_4:
    // 0x8080007C: bne         $v0, $zero, L_80800068
    if (ctx->r2 != 0) {
        // 0x80800080: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800068;
    }
    // 0x80800080: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80800084:
    // 0x80800084: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x80800088: jal         0x801067C4
    // 0x8080008C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_801067C4(rdram, ctx);
        goto after_5;
    // 0x8080008C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_5:
    // 0x80800090: beq         $v0, $zero, L_808000B4
    if (ctx->r2 == 0) {
        // 0x80800094: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808000B4;
    }
    // 0x80800094: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80800098:
    // 0x80800098: jal         0x80800AD8
    // 0x8080009C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80800AD8_subaddiestore(rdram, ctx);
        goto after_6;
    // 0x8080009C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x808000A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808000A4: jal         0x8010682C
    // 0x808000A8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    func_8010682C(rdram, ctx);
        goto after_7;
    // 0x808000A8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    after_7:
    // 0x808000AC: bne         $v0, $zero, L_80800098
    if (ctx->r2 != 0) {
        // 0x808000B0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800098;
    }
    // 0x808000B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_808000B4:
    // 0x808000B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808000B8: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x808000BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000C0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808000C4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808000C8: jr          $ra
    // 0x808000CC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x808000CC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80800838_bskazpaddle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800838: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080083C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800840: jal         0x80800068
    // 0x80800844: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80800068_bskazpaddle(rdram, ctx);
        goto after_0;
    // 0x80800844: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800848: lui         $a2, 0x4019
    ctx->r6 = S32(0X4019 << 16);
    // 0x8080084C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800850: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800854: jal         0x8008CCBC
    // 0x80800858: addiu       $a1, $zero, 0x13A
    ctx->r5 = ADD32(0, 0X13A);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_1;
    // 0x80800858: addiu       $a1, $zero, 0x13A
    ctx->r5 = ADD32(0, 0X13A);
    after_1:
    // 0x8080085C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800860: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800864: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800868: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080086C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800870: jal         0x8009FFD8
    // 0x80800874: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80800874: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x80800878: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080087C: jal         0x8009B9B0
    // 0x80800880: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_3;
    // 0x80800880: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x80800884: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800888: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080088C: jr          $ra
    // 0x80800890: nop

    return;
    // 0x80800890: nop

;}
RECOMP_FUNC void bswalk_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800674: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800678: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(435, 0X1520) << 16);
    // 0x8080067C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800680: jr          $ra
    // 0x80800684: lw          $v0, 0x1520($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(435, 0X1520));
    return;
    // 0x80800684: lw          $v0, 0x1520($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(435, 0X1520));
;}
RECOMP_FUNC void _fxkern_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088B10: syscall     724
    recomp_syscall_handler(rdram, ctx, 0x80088B10);
    return;
    // 0x80088B14: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _bawasher_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085438: syscall     161
    recomp_syscall_handler(rdram, ctx, 0x80085438);
    return;
    // 0x8008543C: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_808019B0_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808019B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808019B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808019B8: jal         0x80802484
    // 0x808019BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80802484_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x808019BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808019C0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808019C4: jal         0x800A4C88
    // 0x808019C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800A4C88(rdram, ctx);
        goto after_1;
    // 0x808019C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808019CC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x808019D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808019D4: jal         0x8010FD60
    // 0x808019D8: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    func_8010FD60(rdram, ctx);
        goto after_2;
    // 0x808019D8: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    after_2:
    // 0x808019DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808019E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808019E4: jr          $ra
    // 0x808019E8: nop

    return;
    // 0x808019E8: nop

;}
RECOMP_FUNC void func_80800694_chswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800694: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800698: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080069C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808006A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808006A4: jal         0x800DA298
    // 0x808006A8: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808006A8: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x808006AC: beq         $v0, $zero, L_80800748
    if (ctx->r2 == 0) {
        // 0x808006B0: addiu       $a0, $sp, 0x2C
        ctx->r4 = ADD32(ctx->r29, 0X2C);
            goto L_80800748;
    }
    // 0x808006B0: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x808006B4: jal         0x80087898
    // 0x808006B8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _plsu_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808006B8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x808006BC: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    // 0x808006C0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x808006C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006C8: sltiu       $t6, $a1, 0x1
    ctx->r14 = ctx->r5 < 0X1 ? 1 : 0;
    // 0x808006CC: jal         0x80103110
    // 0x808006D0: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    func_80103110(rdram, ctx);
        goto after_2;
    // 0x808006D0: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_2:
    // 0x808006D4: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
    // 0x808006D8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x808006DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006E0: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x808006E4: bne         $t8, $zero, L_8080073C
    if (ctx->r24 != 0) {
        // 0x808006E8: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_8080073C;
    }
    // 0x808006E8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808006EC: jal         0x80102424
    // 0x808006F0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x808006F0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_3:
    // 0x808006F4: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x808006F8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x808006FC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800700: bnel        $t9, $zero, L_8080074C
    if (ctx->r25 != 0) {
        // 0x80800704: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080074C;
    }
    goto skip_0;
    // 0x80800704: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800708: beql        $a2, $at, L_8080074C
    if (ctx->r6 == ctx->r1) {
        // 0x8080070C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080074C;
    }
    goto skip_1;
    // 0x8080070C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800710: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    // 0x80800714: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800718: ori         $t2, $t1, 0x10
    ctx->r10 = ctx->r9 | 0X10;
    // 0x8080071C: jal         0x800F5410
    // 0x80800720: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
    func_800F5410(rdram, ctx);
        goto after_4;
    // 0x80800720: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
    after_4:
    // 0x80800724: lhu         $t3, 0x6E($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800728: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
    // 0x8080072C: andi        $t4, $t3, 0xFE00
    ctx->r12 = ctx->r11 & 0XFE00;
    // 0x80800730: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x80800734: b           L_80800748
    // 0x80800738: sh          $t5, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r13;
        goto L_80800748;
    // 0x80800738: sh          $t5, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r13;
L_8080073C:
    // 0x8080073C: jal         0x800F5410
    // 0x80800740: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800F5410(rdram, ctx);
        goto after_5;
    // 0x80800740: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_5:
    // 0x80800744: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
L_80800748:
    // 0x80800748: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080074C:
    // 0x8080074C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800750: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800754: jr          $ra
    // 0x80800758: nop

    return;
    // 0x80800758: nop

;}
RECOMP_FUNC void func_800A3040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3040: jr          $ra
    // 0x800A3044: addiu       $v0, $zero, 0x58
    ctx->r2 = ADD32(0, 0X58);
    return;
    // 0x800A3044: addiu       $v0, $zero, 0x58
    ctx->r2 = ADD32(0, 0X58);
;}
RECOMP_FUNC void func_80110720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110720: jr          $ra
    // 0x80110724: sb          $a1, 0x70($a0)
    MEM_B(0X70, ctx->r4) = ctx->r5;
    return;
    // 0x80110724: sb          $a1, 0x70($a0)
    MEM_B(0X70, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void _bsfirstp_entrypoint_29(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084370: syscall     108
    recomp_syscall_handler(rdram, ctx, 0x80084370);
    return;
    // 0x80084374: addi        $t0, $zero, 0x74
    ctx->r8 = ADD32(0, 0X74);
;}
RECOMP_FUNC void bsbfly_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801BA0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801BA4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(96, 0X1DC8) << 16);
    // 0x80801BA8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801BAC: jr          $ra
    // 0x80801BB0: lw          $v0, 0x1DC8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(96, 0X1DC8));
    return;
    // 0x80801BB0: lw          $v0, 0x1DC8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(96, 0X1DC8));
;}
RECOMP_FUNC void func_800A0CD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A0CD0: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x800A0CD4: jr          $ra
    // 0x800A0CD8: sb          $a1, 0x12($t6)
    MEM_B(0X12, ctx->r14) = ctx->r5;
    return;
    // 0x800A0CD8: sb          $a1, 0x12($t6)
    MEM_B(0X12, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_808001D0_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001D8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808001DC: jal         0x80100094
    // 0x808001E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808001E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808001E4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808001E8: addiu       $a0, $zero, 0xA4C
    ctx->r4 = ADD32(0, 0XA4C);
    // 0x808001EC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808001F0: jal         0x800DA7A8
    // 0x808001F4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800DA7A8(rdram, ctx);
        goto after_1;
    // 0x808001F4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_1:
    // 0x808001F8: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x808001FC: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80800200: sb          $t6, 0xF($t7)
    MEM_B(0XF, ctx->r15) = ctx->r14;
    // 0x80800204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800208: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080020C: jr          $ra
    // 0x80800210: nop

    return;
    // 0x80800210: nop

;}
RECOMP_FUNC void _suegg_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A3D8: syscall     841
    recomp_syscall_handler(rdram, ctx, 0x8008A3D8);
    return;
    // 0x8008A3DC: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void func_80801FD0_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801FD0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80801FD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801FD8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80801FDC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80801FE0: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x80801FE4: lw          $s1, 0x188($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X188);
    // 0x80801FE8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80801FEC: lwc1        $f2, 0xB4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XB4);
    // 0x80801FF0: jal         0x800D9004
    // 0x80801FF4: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    func_800D9004(rdram, ctx);
        goto after_0;
    // 0x80801FF4: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x80801FF8: lw          $v0, 0xA0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XA0);
    // 0x80801FFC: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x80802000: lwc1        $f2, 0x4C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80802004: beq         $v0, $zero, L_80802020
    if (ctx->r2 == 0) {
        // 0x80802008: subu        $t7, $t7, $s0
        ctx->r15 = SUB32(ctx->r15, ctx->r16);
            goto L_80802020;
    }
    // 0x80802008: subu        $t7, $t7, $s0
    ctx->r15 = SUB32(ctx->r15, ctx->r16);
    // 0x8080200C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80802010: beql        $v0, $at, L_80802050
    if (ctx->r2 == ctx->r1) {
        // 0x80802014: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80802050;
    }
    goto skip_0;
    // 0x80802014: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x80802018: b           L_8080207C
    // 0x8080201C: nop

        goto L_8080207C;
    // 0x8080201C: nop

L_80802020:
    // 0x80802020: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80802024: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80802028: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8080202C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80802030: sub.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x80802034: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80802038: nop

    // 0x8080203C: bc1f        L_8080207C
    if (!c1cs) {
        // 0x80802040: nop
    
            goto L_8080207C;
    }
    // 0x80802040: nop

    // 0x80802044: b           L_8080207C
    // 0x80802048: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
        goto L_8080207C;
    // 0x80802048: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8080204C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80802050:
    // 0x80802050: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80802054: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80802058: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080205C: nop

    // 0x80802060: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80802064: add.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x80802068: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x8080206C: nop

    // 0x80802070: bc1f        L_8080207C
    if (!c1cs) {
        // 0x80802074: nop
    
            goto L_8080207C;
    }
    // 0x80802074: nop

    // 0x80802078: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_8080207C:
    // 0x8080207C: lui         $t8, 0x8081
    ctx->r24 = S32(RELOC_HI16(439, 0XA5D0) << 16);
    // 0x80802080: addiu       $t8, $t8, -0x5A30
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(439, 0XA5D0));
    // 0x80802084: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80802088: swc1        $f2, 0xB4($s1)
    MEM_W(0XB4, ctx->r17) = ctx->f2.u32l;
    // 0x8080208C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80802090: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80802094: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80802098: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8080209C: lwc1        $f14, 0x8($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X8);
    // 0x808020A0: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x808020A4: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x808020A8: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x808020AC: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x808020B0: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x808020B4: sub.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x808020B8: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x808020BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808020C0: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x808020C4: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x808020C8: sub.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x808020CC: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    // 0x808020D0: lwc1        $f4, 0x24($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X24);
    // 0x808020D4: add.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x808020D8: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x808020DC: sub.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x808020E0: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    // 0x808020E4: lwc1        $f4, 0x28($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X28);
    // 0x808020E8: add.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x808020EC: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x808020F0: sub.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x808020F4: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    // 0x808020F8: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x808020FC: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80802100: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80802104: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x80802108: lwc1        $f6, 0x2C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8080210C: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
    // 0x80802110: add.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80802114: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80802118: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x8080211C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80802120: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80802124: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80802128: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    // 0x8080212C: lw          $t9, 0xA8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XA8);
    // 0x80802130: bnel        $t9, $at, L_80802150
    if (ctx->r25 != ctx->r1) {
        // 0x80802134: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_80802150;
    }
    goto skip_1;
    // 0x80802134: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_1:
    // 0x80802138: lwc1        $f10, 0x168($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X168);
    // 0x8080213C: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x80802140: lwc1        $f4, 0x184($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X184);
    // 0x80802144: b           L_8080215C
    // 0x80802148: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
        goto L_8080215C;
    // 0x80802148: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x8080214C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80802150:
    // 0x80802150: nop

    // 0x80802154: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80802158: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
L_8080215C:
    // 0x8080215C: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80802160: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80802164: lui         $at, 0x4318
    ctx->r1 = S32(0X4318 << 16);
    // 0x80802168: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080216C: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80802170: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80802174: lui         $at, 0x42E4
    ctx->r1 = S32(0X42E4 << 16);
    // 0x80802178: addiu       $s0, $s1, 0xB8
    ctx->r16 = ADD32(ctx->r17, 0XB8);
    // 0x8080217C: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x80802180: add.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80802184: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80802188: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8080218C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80802190: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    // 0x80802194: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80802198: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x8080219C: jal         0x8080222C
    // 0x808021A0: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    func_8080222C_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x808021A0: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x808021A4: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x808021A8: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x808021AC: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808021B0: jal         0x8080222C
    // 0x808021B4: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    func_8080222C_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x808021B4: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    after_2:
    // 0x808021B8: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x808021BC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808021C0: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x808021C4: jal         0x80084B00
    // 0x808021C8: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    _baeggcursor_entrypoint_10(rdram, ctx);
        goto after_3;
    // 0x808021C8: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x808021CC: lui         $at, 0x4318
    ctx->r1 = S32(0X4318 << 16);
    // 0x808021D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808021D4: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x808021D8: lwc1        $f14, 0x60($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X60);
    // 0x808021DC: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x808021E0: jal         0x80802304
    // 0x808021E4: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_80802304_bsfirstp(rdram, ctx);
        goto after_4;
    // 0x808021E4: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_4:
    // 0x808021E8: addiu       $v0, $s1, 0xC0
    ctx->r2 = ADD32(ctx->r17, 0XC0);
    // 0x808021EC: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x808021F0: lui         $at, 0x42E4
    ctx->r1 = S32(0X42E4 << 16);
    // 0x808021F4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808021F8: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x808021FC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80802200: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x80802204: lwc1        $f14, 0x64($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80802208: jal         0x80802304
    // 0x8080220C: sub.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f8.fl;
    func_80802304_bsfirstp(rdram, ctx);
        goto after_5;
    // 0x8080220C: sub.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f8.fl;
    after_5:
    // 0x80802210: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80802214: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80802218: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080221C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80802220: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80802224: jr          $ra
    // 0x80802228: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80802228: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void chlavaexplodbuild_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800280: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2068, 0X2E0) << 16);
    // 0x80800284: jr          $ra
    // 0x80800288: addiu       $v0, $v0, 0x2E0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2068, 0X2E0));
    return;
    // 0x80800288: addiu       $v0, $v0, 0x2E0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2068, 0X2E0));
    // 0x8080028C: nop

;}
RECOMP_FUNC void _sucoasterfly_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089EE0: syscall     813
    recomp_syscall_handler(rdram, ctx, 0x80089EE0);
    return;
    // 0x80089EE4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _chchuffyglow_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086D88: syscall     450
    recomp_syscall_handler(rdram, ctx, 0x80086D88);
    return;
    // 0x80086D8C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void yaw_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C830: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009C834: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009C838: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8009C83C: lw          $t6, 0xF8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XF8);
    // 0x8009C840: lui         $a1, 0x442F
    ctx->r5 = S32(0X442F << 16);
    // 0x8009C844: lui         $a2, 0x40F0
    ctx->r6 = S32(0X40F0 << 16);
    // 0x8009C848: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    // 0x8009C84C: lw          $t7, 0xF8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XF8);
    // 0x8009C850: swc1        $f0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f0.u32l;
    // 0x8009C854: jal         0x8009C99C
    // 0x8009C858: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    yaw_setVelocityBounded(rdram, ctx);
        goto after_0;
    // 0x8009C858: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8009C85C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8009C860: jal         0x8009C9B8
    // 0x8009C864: lui         $a1, 0x43B4
    ctx->r5 = S32(0X43B4 << 16);
    yaw_setVelocityUnbounded(rdram, ctx);
        goto after_1;
    // 0x8009C864: lui         $a1, 0x43B4
    ctx->r5 = S32(0X43B4 << 16);
    after_1:
    // 0x8009C868: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8009C86C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8009C870: lw          $t8, 0xF8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XF8);
    // 0x8009C874: jal         0x8009C908
    // 0x8009C878: sw          $zero, 0xC($t8)
    MEM_W(0XC, ctx->r24) = 0;
    yaw_setUpdateType(rdram, ctx);
        goto after_2;
    // 0x8009C878: sw          $zero, 0xC($t8)
    MEM_W(0XC, ctx->r24) = 0;
    after_2:
    // 0x8009C87C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009C880: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009C884: jr          $ra
    // 0x8009C888: nop

    return;
    // 0x8009C888: nop

;}
