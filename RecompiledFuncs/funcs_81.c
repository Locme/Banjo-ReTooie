#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void bssplitup_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800680: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800684: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800688: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080068C: jal         0x8008CAEC
    // 0x80800690: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    baanim_isStopped(rdram, ctx);
        goto after_0;
    // 0x80800690: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80800694: beq         $v0, $zero, L_808006A0
    if (ctx->r2 == 0) {
        // 0x80800698: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_808006A0;
    }
    // 0x80800698: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8080069C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_808006A0:
    // 0x808006A0: jal         0x8009E5C8
    // 0x808006A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bs_setState(rdram, ctx);
        goto after_1;
    // 0x808006A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808006A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808006B0: jr          $ra
    // 0x808006B4: nop

    return;
    // 0x808006B4: nop

;}
RECOMP_FUNC void chgoldfish_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C44: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2312, 0XD94) << 16);
    // 0x80800C48: jr          $ra
    // 0x80800C4C: addiu       $v0, $v0, 0xD94
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2312, 0XD94));
    return;
    // 0x80800C4C: addiu       $v0, $v0, 0xD94
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2312, 0XD94));
;}
RECOMP_FUNC void func_8080037C_chscreenadjust(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080037C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800380: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800384: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800388: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8080038C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800390: addiu       $t6, $zero, 0xE4
    ctx->r14 = ADD32(0, 0XE4);
    // 0x80800394: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x80800398: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x8080039C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x808003A0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x808003A4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x808003A8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x808003AC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808003B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808003B4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x808003B8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x808003BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808003C0: jal         0x808001E0
    // 0x808003C4: addiu       $a3, $zero, 0x130
    ctx->r7 = ADD32(0, 0X130);
    func_808001E0_chscreenadjust(rdram, ctx);
        goto after_0;
    // 0x808003C4: addiu       $a3, $zero, 0x130
    ctx->r7 = ADD32(0, 0X130);
    after_0:
    // 0x808003C8: addiu       $t0, $zero, 0xC4
    ctx->r8 = ADD32(0, 0XC4);
    // 0x808003CC: addiu       $t1, $zero, 0x20
    ctx->r9 = ADD32(0, 0X20);
    // 0x808003D0: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x808003D4: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x808003D8: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x808003DC: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x808003E0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x808003E4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x808003E8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808003EC: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x808003F0: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x808003F4: addiu       $a3, $zero, 0x110
    ctx->r7 = ADD32(0, 0X110);
    // 0x808003F8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x808003FC: jal         0x808001E0
    // 0x80800400: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    func_808001E0_chscreenadjust(rdram, ctx);
        goto after_1;
    // 0x80800400: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_1:
    // 0x80800404: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800408: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080040C: jr          $ra
    // 0x80800410: nop

    return;
    // 0x80800410: nop

;}
RECOMP_FUNC void _bsjig_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083210: syscall     51
    recomp_syscall_handler(rdram, ctx, 0x80083210);
    return;
    // 0x80083214: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void bsjig_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808003B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808003C0: jal         0x8008E95C
    // 0x808003C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8008E95C(rdram, ctx);
        goto after_0;
    // 0x808003C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808003C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003CC: jal         0x800A0CF4
    // 0x808003D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_1;
    // 0x808003D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808003D4: jal         0x800A4E30
    // 0x808003D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4E30(rdram, ctx);
        goto after_2;
    // 0x808003D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808003DC: jal         0x800A4C68
    // 0x808003E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4C68(rdram, ctx);
        goto after_3;
    // 0x808003E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808003E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003E8: jal         0x800C53EC
    // 0x808003EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800C53EC(rdram, ctx);
        goto after_4;
    // 0x808003EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x808003F0: jal         0x8009CEE8
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009CEE8(rdram, ctx);
        goto after_5;
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808003F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800400: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800404: jr          $ra
    // 0x80800408: nop

    return;
    // 0x80800408: nop

;}
RECOMP_FUNC void func_808062EC_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808062EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808062F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808062F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808062F8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808062FC: jal         0x80087D38
    // 0x80806300: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    _gcnewoption_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80806300: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80806304: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80806308: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080630C: addiu       $a0, $zero, 0xC0B
    ctx->r4 = ADD32(0, 0XC0B);
    // 0x80806310: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
    // 0x80806314: bne         $v1, $at, L_80806334
    if (ctx->r3 != ctx->r1) {
        // 0x80806318: or          $a2, $v1, $zero
        ctx->r6 = ctx->r3 | 0;
            goto L_80806334;
    }
    // 0x80806318: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8080631C: jal         0x800DA298
    // 0x80806320: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80806320: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80806324: bne         $v0, $zero, L_80806334
    if (ctx->r2 != 0) {
        // 0x80806328: lw          $a2, 0x1C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X1C);
            goto L_80806334;
    }
    // 0x80806328: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8080632C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80806330: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
L_80806334:
    // 0x80806334: slti        $at, $a2, 0x5
    ctx->r1 = SIGNED(ctx->r6) < 0X5 ? 1 : 0;
    // 0x80806338: bne         $at, $zero, L_80806348
    if (ctx->r1 != 0) {
        // 0x8080633C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80806348;
    }
    // 0x8080633C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80806340: b           L_80806354
    // 0x80806344: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_80806354;
    // 0x80806344: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80806348:
    // 0x80806348: bgezl       $a2, L_80806358
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8080634C: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_80806358;
    }
    goto skip_0;
    // 0x8080634C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80806350: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
L_80806354:
    // 0x80806354: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
L_80806358:
    // 0x80806358: jal         0x80806218
    // 0x8080635C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80806218_chgameselect(rdram, ctx);
        goto after_2;
    // 0x8080635C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80806360: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80806364: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80806368: jr          $ra
    // 0x8080636C: nop

    return;
    // 0x8080636C: nop

;}
RECOMP_FUNC void func_80800728_chtrashcangame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800728: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080072C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800730: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800734: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800738: jal         0x800FDC28
    // 0x8080073C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FDC28(rdram, ctx);
        goto after_0;
    // 0x8080073C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80800740: addiu       $a0, $zero, 0x533
    ctx->r4 = ADD32(0, 0X533);
    // 0x80800744: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800748: jal         0x80101180
    // 0x8080074C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_1;
    // 0x8080074C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80800750: jal         0x800D395C
    // 0x80800754: nop

    func_800D395C(rdram, ctx);
        goto after_2;
    // 0x80800754: nop

    after_2:
    // 0x80800758: beq         $v0, $zero, L_80800818
    if (ctx->r2 == 0) {
        // 0x8080075C: addiu       $a0, $zero, 0x4E
        ctx->r4 = ADD32(0, 0X4E);
            goto L_80800818;
    }
    // 0x8080075C: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    // 0x80800760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800764: jal         0x80800014
    // 0x80800768: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800014_chtrashcangame(rdram, ctx);
        goto after_3;
    // 0x80800768: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8080076C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800770: jal         0x800D211C
    // 0x80800774: addiu       $a0, $zero, 0x86
    ctx->r4 = ADD32(0, 0X86);
    func_800D211C(rdram, ctx);
        goto after_4;
    // 0x80800774: addiu       $a0, $zero, 0x86
    ctx->r4 = ADD32(0, 0X86);
    after_4:
    // 0x80800778: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8080077C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800780: bne         $v0, $t6, L_808007A8
    if (ctx->r2 != ctx->r14) {
        // 0x80800784: nop
    
            goto L_808007A8;
    }
    // 0x80800784: nop

    // 0x80800788: jal         0x800FC660
    // 0x8080078C: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_800FC660(rdram, ctx);
        goto after_5;
    // 0x8080078C: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_5:
    // 0x80800790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800794: addiu       $a1, $zero, 0x1446
    ctx->r5 = ADD32(0, 0X1446);
    // 0x80800798: jal         0x808017F0
    // 0x8080079C: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_808017F0_chtrashcangame(rdram, ctx);
        goto after_6;
    // 0x8080079C: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_6:
    // 0x808007A0: b           L_80800808
    // 0x808007A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800808;
    // 0x808007A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808007A8:
    // 0x808007A8: jal         0x80800014
    // 0x808007AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800014_chtrashcangame(rdram, ctx);
        goto after_7;
    // 0x808007AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x808007B0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808007B4: jal         0x800D211C
    // 0x808007B8: addiu       $a0, $zero, 0x86
    ctx->r4 = ADD32(0, 0X86);
    func_800D211C(rdram, ctx);
        goto after_8;
    // 0x808007B8: addiu       $a0, $zero, 0x86
    ctx->r4 = ADD32(0, 0X86);
    after_8:
    // 0x808007BC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x808007C0: slt         $at, $t7, $v0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808007C4: beq         $at, $zero, L_808007EC
    if (ctx->r1 == 0) {
        // 0x808007C8: nop
    
            goto L_808007EC;
    }
    // 0x808007C8: nop

    // 0x808007CC: jal         0x800FC660
    // 0x808007D0: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_800FC660(rdram, ctx);
        goto after_9;
    // 0x808007D0: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_9:
    // 0x808007D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007D8: addiu       $a1, $zero, 0x1445
    ctx->r5 = ADD32(0, 0X1445);
    // 0x808007DC: jal         0x808017F0
    // 0x808007E0: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_808017F0_chtrashcangame(rdram, ctx);
        goto after_10;
    // 0x808007E0: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_10:
    // 0x808007E4: b           L_80800808
    // 0x808007E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800808;
    // 0x808007E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808007EC:
    // 0x808007EC: jal         0x800FC660
    // 0x808007F0: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_800FC660(rdram, ctx);
        goto after_11;
    // 0x808007F0: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_11:
    // 0x808007F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007F8: addiu       $a1, $zero, 0x1447
    ctx->r5 = ADD32(0, 0X1447);
    // 0x808007FC: jal         0x808017F0
    // 0x80800800: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_808017F0_chtrashcangame(rdram, ctx);
        goto after_12;
    // 0x80800800: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_12:
    // 0x80800804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800808:
    // 0x80800808: jal         0x808003D0
    // 0x8080080C: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    func_808003D0_chtrashcangame(rdram, ctx);
        goto after_13;
    // 0x8080080C: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_13:
    // 0x80800810: b           L_8080092C
    // 0x80800814: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080092C;
    // 0x80800814: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800818:
    // 0x80800818: jal         0x800D0A9C
    // 0x8080081C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_14;
    // 0x8080081C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x80800820: beq         $v0, $zero, L_808008D8
    if (ctx->r2 == 0) {
        // 0x80800824: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008D8;
    }
    // 0x80800824: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080082C: jal         0x80800014
    // 0x80800830: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800014_chtrashcangame(rdram, ctx);
        goto after_15;
    // 0x80800830: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x80800834: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800838: jal         0x800D211C
    // 0x8080083C: addiu       $a0, $zero, 0x86
    ctx->r4 = ADD32(0, 0X86);
    func_800D211C(rdram, ctx);
        goto after_16;
    // 0x8080083C: addiu       $a0, $zero, 0x86
    ctx->r4 = ADD32(0, 0X86);
    after_16:
    // 0x80800840: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80800844: addiu       $a1, $zero, 0x13F9
    ctx->r5 = ADD32(0, 0X13F9);
    // 0x80800848: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x8080084C: bne         $v0, $t8, L_80800870
    if (ctx->r2 != ctx->r24) {
        // 0x80800850: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800870;
    }
    // 0x80800850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800854: jal         0x808017F0
    // 0x80800858: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808017F0_chtrashcangame(rdram, ctx);
        goto after_17;
    // 0x80800858: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x8080085C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800860: jal         0x808003D0
    // 0x80800864: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_808003D0_chtrashcangame(rdram, ctx);
        goto after_18;
    // 0x80800864: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_18:
    // 0x80800868: b           L_8080092C
    // 0x8080086C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080092C;
    // 0x8080086C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800870:
    // 0x80800870: jal         0x80800014
    // 0x80800874: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800014_chtrashcangame(rdram, ctx);
        goto after_19;
    // 0x80800874: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_19:
    // 0x80800878: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080087C: jal         0x800D211C
    // 0x80800880: addiu       $a0, $zero, 0x86
    ctx->r4 = ADD32(0, 0X86);
    func_800D211C(rdram, ctx);
        goto after_20;
    // 0x80800880: addiu       $a0, $zero, 0x86
    ctx->r4 = ADD32(0, 0X86);
    after_20:
    // 0x80800884: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80800888: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x8080088C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800890: slt         $at, $t9, $v0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800894: beq         $at, $zero, L_808008BC
    if (ctx->r1 == 0) {
        // 0x80800898: addiu       $a1, $zero, 0x13FA
        ctx->r5 = ADD32(0, 0X13FA);
            goto L_808008BC;
    }
    // 0x80800898: addiu       $a1, $zero, 0x13FA
    ctx->r5 = ADD32(0, 0X13FA);
    // 0x8080089C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008A0: jal         0x808017F0
    // 0x808008A4: addiu       $a1, $zero, 0x13F8
    ctx->r5 = ADD32(0, 0X13F8);
    func_808017F0_chtrashcangame(rdram, ctx);
        goto after_21;
    // 0x808008A4: addiu       $a1, $zero, 0x13F8
    ctx->r5 = ADD32(0, 0X13F8);
    after_21:
    // 0x808008A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008AC: jal         0x808003D0
    // 0x808008B0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_808003D0_chtrashcangame(rdram, ctx);
        goto after_22;
    // 0x808008B0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_22:
    // 0x808008B4: b           L_8080092C
    // 0x808008B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080092C;
    // 0x808008B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808008BC:
    // 0x808008BC: jal         0x808017F0
    // 0x808008C0: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_808017F0_chtrashcangame(rdram, ctx);
        goto after_23;
    // 0x808008C0: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_23:
    // 0x808008C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008C8: jal         0x808003D0
    // 0x808008CC: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_808003D0_chtrashcangame(rdram, ctx);
        goto after_24;
    // 0x808008CC: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_24:
    // 0x808008D0: b           L_8080092C
    // 0x808008D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080092C;
    // 0x808008D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808008D8:
    // 0x808008D8: jal         0x80800014
    // 0x808008DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800014_chtrashcangame(rdram, ctx);
        goto after_25;
    // 0x808008DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_25:
    // 0x808008E0: slti        $at, $v0, 0x32
    ctx->r1 = SIGNED(ctx->r2) < 0X32 ? 1 : 0;
    // 0x808008E4: beq         $at, $zero, L_80800910
    if (ctx->r1 == 0) {
        // 0x808008E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800910;
    }
    // 0x808008E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008F0: addiu       $a1, $zero, 0x13F6
    ctx->r5 = ADD32(0, 0X13F6);
    // 0x808008F4: jal         0x808017F0
    // 0x808008F8: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_808017F0_chtrashcangame(rdram, ctx);
        goto after_26;
    // 0x808008F8: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_26:
    // 0x808008FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800900: jal         0x808003D0
    // 0x80800904: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_808003D0_chtrashcangame(rdram, ctx);
        goto after_27;
    // 0x80800904: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_27:
    // 0x80800908: b           L_8080092C
    // 0x8080090C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080092C;
    // 0x8080090C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800910:
    // 0x80800910: addiu       $a1, $zero, 0x13F7
    ctx->r5 = ADD32(0, 0X13F7);
    // 0x80800914: jal         0x808017F0
    // 0x80800918: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_808017F0_chtrashcangame(rdram, ctx);
        goto after_28;
    // 0x80800918: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_28:
    // 0x8080091C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800920: jal         0x808003D0
    // 0x80800924: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_808003D0_chtrashcangame(rdram, ctx);
        goto after_29;
    // 0x80800924: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_29:
    // 0x80800928: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080092C:
    // 0x8080092C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800930: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800934: jr          $ra
    // 0x80800938: nop

    return;
    // 0x80800938: nop

;}
RECOMP_FUNC void func_800C1070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1070: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C1074: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C1078: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800C107C: jal         0x800F5310
    // 0x800C1080: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    func_800F5310(rdram, ctx);
        goto after_0;
    // 0x800C1080: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x800C1084: beq         $v0, $zero, L_800C10EC
    if (ctx->r2 == 0) {
        // 0x800C1088: nop
    
            goto L_800C10EC;
    }
    // 0x800C1088: nop

    // 0x800C108C: jal         0x800EA068
    // 0x800C1090: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    func_800EA068(rdram, ctx);
        goto after_1;
    // 0x800C1090: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_1:
    // 0x800C1094: beq         $v0, $zero, L_800C10B0
    if (ctx->r2 == 0) {
        // 0x800C1098: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_800C10B0;
    }
    // 0x800C1098: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800C109C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800C10A0: jal         0x80087898
    // 0x800C10A4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    _plsu_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x800C10A4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_2:
    // 0x800C10A8: b           L_800C10F8
    // 0x800C10AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800C10F8;
    // 0x800C10AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C10B0:
    // 0x800C10B0: jal         0x80087898
    // 0x800C10B4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    _plsu_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x800C10B4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x800C10B8: jal         0x800F5EF8
    // 0x800C10BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5EF8(rdram, ctx);
        goto after_4;
    // 0x800C10BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x800C10C0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800C10C4: jal         0x8010FFA8
    // 0x800C10C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8010FFA8(rdram, ctx);
        goto after_5;
    // 0x800C10C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x800C10CC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C10D0: beq         $v0, $at, L_800C10F4
    if (ctx->r2 == ctx->r1) {
        // 0x800C10D4: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_800C10F4;
    }
    // 0x800C10D4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800C10D8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800C10DC: jal         0x8010FFB0
    // 0x800C10E0: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    func_8010FFB0(rdram, ctx);
        goto after_6;
    // 0x800C10E0: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_6:
    // 0x800C10E4: b           L_800C10F8
    // 0x800C10E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800C10F8;
    // 0x800C10E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C10EC:
    // 0x800C10EC: jal         0x800E3980
    // 0x800C10F0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800E3980(rdram, ctx);
        goto after_7;
    // 0x800C10F0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_7:
L_800C10F4:
    // 0x800C10F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C10F8:
    // 0x800C10F8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800C10FC: jr          $ra
    // 0x800C1100: nop

    return;
    // 0x800C1100: nop

;}
RECOMP_FUNC void func_80800394_chcrusher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800394: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800398: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080039C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808003A0: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1624, 0XBF0) << 16);
    // 0x808003A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003A8: addiu       $t6, $t6, 0xBF0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1624, 0XBF0));
    // 0x808003AC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808003B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808003B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808003B8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x808003BC: jal         0x800BABB8
    // 0x808003C0: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    func_800BABB8(rdram, ctx);
        goto after_0;
    // 0x808003C0: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    after_0:
    // 0x808003C4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1624, 0XB10) << 16);
    // 0x808003C8: lwc1        $f4, 0xB10($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1624, 0XB10));
    // 0x808003CC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x808003D0: swc1        $f4, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->f4.u32l;
    // 0x808003D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003DC: jr          $ra
    // 0x808003E0: nop

    return;
    // 0x808003E0: nop

;}
RECOMP_FUNC void func_80116898(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80116898: daddiu      $a0, $a0, 0x1
    ctx->r4 = ctx->r4 + 0X1;
    // 0x8011689C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801168A0: sd          $a0, 0x4A70($at)
    SD(ctx->r4, 0X4A70, ctx->r1);
    // 0x801168A4: jr          $ra
    // 0x801168A8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    return;
    // 0x801168A8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
;}
RECOMP_FUNC void gcgoto_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800694: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800698: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080069C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808006A0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808006A4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x808006A8: jal         0x8008A368
    // 0x808006AC: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    _sutempleboss_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x808006AC: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x808006B0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x808006B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808006B8: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x808006BC: beq         $v0, $zero, L_808006CC
    if (ctx->r2 == 0) {
        // 0x808006C0: sll         $t6, $v0, 8
        ctx->r14 = S32(ctx->r2 << 8);
            goto L_808006CC;
    }
    // 0x808006C0: sll         $t6, $v0, 8
    ctx->r14 = S32(ctx->r2 << 8);
    // 0x808006C4: jal         0x808003D0
    // 0x808006C8: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    func_808003D0_gcgoto(rdram, ctx);
        goto after_1;
    // 0x808006C8: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
L_808006CC:
    // 0x808006CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808006D4: jr          $ra
    // 0x808006D8: nop

    return;
    // 0x808006D8: nop

;}
RECOMP_FUNC void func_80115E88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115E88: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x80115E8C: jr          $ra
    // 0x80115E90: lwc1        $f0, 0x18($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X18);
    return;
    // 0x80115E90: lwc1        $f0, 0x18($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X18);
    // 0x80115E94: nop

    // 0x80115E98: nop

    // 0x80115E9C: nop

;}
RECOMP_FUNC void func_80109EE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109EE0: lhu         $t6, 0x66($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X66);
    // 0x80109EE4: jr          $ra
    // 0x80109EE8: and         $v0, $t6, $a1
    ctx->r2 = ctx->r14 & ctx->r5;
    return;
    // 0x80109EE8: and         $v0, $t6, $a1
    ctx->r2 = ctx->r14 & ctx->r5;
;}
RECOMP_FUNC void _chgameselect_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085BC0: syscall     205
    recomp_syscall_handler(rdram, ctx, 0x80085BC0);
    return;
    // 0x80085BC4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800BFCD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BFCD0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BFCD4: addiu       $v0, $v0, -0x7890
    ctx->r2 = ADD32(ctx->r2, -0X7890);
    // 0x800BFCD8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800BFCDC: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800BFCE0: sw          $a1, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r5;
    // 0x800BFCE4: lw          $t8, 0x30($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X30);
    // 0x800BFCE8: slt         $at, $t8, $a0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BFCEC: beq         $at, $zero, L_800BFCF8
    if (ctx->r1 == 0) {
        // 0x800BFCF0: nop
    
            goto L_800BFCF8;
    }
    // 0x800BFCF0: nop

    // 0x800BFCF4: sw          $a0, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r4;
L_800BFCF8:
    // 0x800BFCF8: jr          $ra
    // 0x800BFCFC: nop

    return;
    // 0x800BFCFC: nop

;}
RECOMP_FUNC void func_80105BE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105BE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105BE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80105BE8: jal         0x80105494
    // 0x80105BEC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80105494(rdram, ctx);
        goto after_0;
    // 0x80105BEC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80105BF0: beq         $v0, $zero, L_80105C10
    if (ctx->r2 == 0) {
        // 0x80105BF4: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_80105C10;
    }
    // 0x80105BF4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80105BF8: lbu         $t0, 0x27($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X27);
    // 0x80105BFC: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x80105C00: andi        $t9, $t8, 0x20
    ctx->r25 = ctx->r24 & 0X20;
    // 0x80105C04: andi        $t1, $t0, 0xFFDF
    ctx->r9 = ctx->r8 & 0XFFDF;
    // 0x80105C08: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80105C0C: sb          $t2, 0x27($v0)
    MEM_B(0X27, ctx->r2) = ctx->r10;
L_80105C10:
    // 0x80105C10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80105C14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80105C18: jr          $ra
    // 0x80105C1C: nop

    return;
    // 0x80105C1C: nop

;}
RECOMP_FUNC void func_808000BC_chfpsgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000C4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808000C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000CC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808000D0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808000D4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808000D8: jal         0x80088368
    // 0x808000DC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x808000DC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_0:
    // 0x808000E0: blez        $v0, L_8080010C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808000E4: lhu         $s2, 0x2A($sp)
        ctx->r18 = MEM_HU(ctx->r29, 0X2A);
            goto L_8080010C;
    }
    // 0x808000E4: lhu         $s2, 0x2A($sp)
    ctx->r18 = MEM_HU(ctx->r29, 0X2A);
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808000EC:
    // 0x808000EC: jal         0x80016BBC
    // 0x808000F0: andi        $a1, $s2, 0xFFFF
    ctx->r5 = ctx->r18 & 0XFFFF;
    func_80016BBC(rdram, ctx);
        goto after_1;
    // 0x808000F0: andi        $a1, $s2, 0xFFFF
    ctx->r5 = ctx->r18 & 0XFFFF;
    after_1:
    // 0x808000F4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808000F8: jal         0x80088368
    // 0x808000FC: or          $s1, $s1, $v0
    ctx->r17 = ctx->r17 | ctx->r2;
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x808000FC: or          $s1, $s1, $v0
    ctx->r17 = ctx->r17 | ctx->r2;
    after_2:
    // 0x80800100: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800104: bnel        $at, $zero, L_808000EC
    if (ctx->r1 != 0) {
        // 0x80800108: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000EC;
    }
    goto skip_0;
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
L_8080010C:
    // 0x8080010C: beq         $s1, $zero, L_8080011C
    if (ctx->r17 == 0) {
        // 0x80800110: lw          $s0, 0x18($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X18);
            goto L_8080011C;
    }
    // 0x80800110: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800114: b           L_80800120
    // 0x80800118: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80800120;
    // 0x80800118: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8080011C:
    // 0x8080011C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80800120:
    // 0x80800120: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800124: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800128: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8080012C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800130: jr          $ra
    // 0x80800134: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80800134: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_8080016C_bswalk(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080016C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800170: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800174: jal         0x8008E1A0
    // 0x80800178: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8008E1A0(rdram, ctx);
        goto after_0;
    // 0x80800178: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080017C: beq         $v0, $zero, L_808001C0
    if (ctx->r2 == 0) {
        // 0x80800180: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808001C0;
    }
    // 0x80800180: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800184: jal         0x8009BBB8
    // 0x80800188: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8009BBB8(rdram, ctx);
        goto after_1;
    // 0x80800188: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8080018C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(435, 0X14F4) << 16);
    // 0x80800190: lwc1        $f4, 0x14F4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(435, 0X14F4));
    // 0x80800194: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800198: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8080019C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808001A0: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x808001A4: jal         0x800F10B4
    // 0x808001A8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x808001A8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x808001AC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808001B0: jal         0x8008CA30
    // 0x808001B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8008CA30(rdram, ctx);
        goto after_3;
    // 0x808001B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x808001B8: b           L_808001CC
    // 0x808001BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808001CC;
    // 0x808001BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001C0:
    // 0x808001C0: jal         0x8008CA30
    // 0x808001C4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8008CA30(rdram, ctx);
        goto after_4;
    // 0x808001C4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_4:
    // 0x808001C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001CC:
    // 0x808001CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001D0: jr          $ra
    // 0x808001D4: nop

    return;
    // 0x808001D4: nop

;}
RECOMP_FUNC void func_80800218_chlaundry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800218: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080021C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800220: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800224: jal         0x80100094
    // 0x80800228: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800228: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080022C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800230: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80800234: jal         0x800D8FF8
    // 0x80800238: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80800238: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8080023C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800240: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80800244: jal         0x80800058
    // 0x80800248: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80800058_chlaundry(rdram, ctx);
        goto after_2;
    // 0x80800248: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8080024C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80800250: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800254: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800258: lbu         $t6, 0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1);
    // 0x8080025C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80800260: beq         $t6, $zero, L_80800278
    if (ctx->r14 == 0) {
        // 0x80800264: swc1        $f10, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
            goto L_80800278;
    }
    // 0x80800264: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x80800268: jal         0x808003A0
    // 0x8080026C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_808003A0_chlaundry(rdram, ctx);
        goto after_3;
    // 0x8080026C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80800270: jal         0x800FFAB0
    // 0x80800274: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800FFAB0(rdram, ctx);
        goto after_4;
    // 0x80800274: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
L_80800278:
    // 0x80800278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080027C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800280: jr          $ra
    // 0x80800284: nop

    return;
    // 0x80800284: nop

;}
RECOMP_FUNC void func_80802098_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802098: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080209C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808020A0: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    // 0x808020A4: addiu       $at, $zero, 0x223
    ctx->r1 = ADD32(0, 0X223);
    // 0x808020A8: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x808020AC: sll         $t6, $v0, 11
    ctx->r14 = S32(ctx->r2 << 11);
    // 0x808020B0: srl         $t7, $t6, 20
    ctx->r15 = S32(U32(ctx->r14) >> 20);
    // 0x808020B4: beq         $t7, $at, L_808020D8
    if (ctx->r15 == ctx->r1) {
        // 0x808020B8: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(932, 0X2EB0) << 16);
            goto L_808020D8;
    }
    // 0x808020B8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(932, 0X2EB0) << 16);
    // 0x808020BC: addiu       $at, $zero, 0x224
    ctx->r1 = ADD32(0, 0X224);
    // 0x808020C0: beq         $t7, $at, L_808020D8
    if (ctx->r15 == ctx->r1) {
        // 0x808020C4: addiu       $at, $zero, 0x225
        ctx->r1 = ADD32(0, 0X225);
            goto L_808020D8;
    }
    // 0x808020C4: addiu       $at, $zero, 0x225
    ctx->r1 = ADD32(0, 0X225);
    // 0x808020C8: beq         $t7, $at, L_808020F0
    if (ctx->r15 == ctx->r1) {
        // 0x808020CC: addiu       $a1, $a0, 0x4
        ctx->r5 = ADD32(ctx->r4, 0X4);
            goto L_808020F0;
    }
    // 0x808020CC: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x808020D0: b           L_80802108
    // 0x808020D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80802108;
    // 0x808020D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808020D8:
    // 0x808020D8: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(932, 0X2EC4) << 16);
    // 0x808020DC: addiu       $a3, $a3, 0x2EC4
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(932, 0X2EC4));
    // 0x808020E0: jal         0x80089D28
    // 0x808020E4: addiu       $a2, $a2, 0x2EB0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(932, 0X2EB0));
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808020E4: addiu       $a2, $a2, 0x2EB0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(932, 0X2EB0));
    after_0:
    // 0x808020E8: b           L_80802108
    // 0x808020EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80802108;
    // 0x808020EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808020F0:
    // 0x808020F0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(932, 0X2EB0) << 16);
    // 0x808020F4: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(932, 0X2ED0) << 16);
    // 0x808020F8: addiu       $a3, $a3, 0x2ED0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(932, 0X2ED0));
    // 0x808020FC: jal         0x80089D28
    // 0x80802100: addiu       $a2, $a2, 0x2EB0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(932, 0X2EB0));
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80802100: addiu       $a2, $a2, 0x2EB0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(932, 0X2EB0));
    after_1:
    // 0x80802104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802108:
    // 0x80802108: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080210C: jr          $ra
    // 0x80802110: nop

    return;
    // 0x80802110: nop

;}
RECOMP_FUNC void func_80800000_chintroticker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8080000C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800010: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800014: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800018: jal         0x800EA05C
    // 0x8080001C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x8080001C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800020: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(1648, 0X830) << 16);
    // 0x80800024: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(1648, 0X8A8) << 16);
    // 0x80800028: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8080002C: addiu       $s3, $s3, 0x8A8
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(1648, 0X8A8));
    // 0x80800030: addiu       $s0, $s0, 0x830
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(1648, 0X830));
    // 0x80800034: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x80800038: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
L_8080003C:
    // 0x8080003C: bnel        $s2, $t6, L_8080008C
    if (ctx->r18 != ctx->r14) {
        // 0x80800040: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_8080008C;
    }
    goto skip_0;
    // 0x80800040: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    skip_0:
    // 0x80800044: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    // 0x80800048: beql        $s1, $a0, L_80800078
    if (ctx->r17 == ctx->r4) {
        // 0x8080004C: lh          $a0, 0x4($s0)
        ctx->r4 = MEM_H(ctx->r16, 0X4);
            goto L_80800078;
    }
    goto skip_1;
    // 0x8080004C: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
    skip_1:
    // 0x80800050: jal         0x800FCCD4
    // 0x80800054: nop

    func_800FCCD4(rdram, ctx);
        goto after_1;
    // 0x80800054: nop

    after_1:
    // 0x80800058: beq         $v0, $zero, L_80800074
    if (ctx->r2 == 0) {
        // 0x8080005C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800074;
    }
    // 0x8080005C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800060: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    // 0x80800064: jal         0x800FCAE0
    // 0x80800068: addiu       $a2, $zero, 0x2EE0
    ctx->r6 = ADD32(0, 0X2EE0);
    func_800FCAE0(rdram, ctx);
        goto after_2;
    // 0x80800068: addiu       $a2, $zero, 0x2EE0
    ctx->r6 = ADD32(0, 0X2EE0);
    after_2:
    // 0x8080006C: jal         0x800FCA90
    // 0x80800070: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    func_800FCA90(rdram, ctx);
        goto after_3;
    // 0x80800070: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    after_3:
L_80800074:
    // 0x80800074: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
L_80800078:
    // 0x80800078: beql        $s1, $a0, L_8080008C
    if (ctx->r17 == ctx->r4) {
        // 0x8080007C: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_8080008C;
    }
    goto skip_2;
    // 0x8080007C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    skip_2:
    // 0x80800080: jal         0x800FC6B0
    // 0x80800084: nop

    func_800FC6B0(rdram, ctx);
        goto after_4;
    // 0x80800084: nop

    after_4:
    // 0x80800088: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_8080008C:
    // 0x8080008C: bnel        $s0, $s3, L_8080003C
    if (ctx->r16 != ctx->r19) {
        // 0x80800090: lh          $t6, 0x0($s0)
        ctx->r14 = MEM_H(ctx->r16, 0X0);
            goto L_8080003C;
    }
    goto skip_3;
    // 0x80800090: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    skip_3:
    // 0x80800094: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800098: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080009C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808000A0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808000A4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808000A8: jr          $ra
    // 0x808000AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808000AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _bakaztorpedo_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084D98: syscall     136
    recomp_syscall_handler(rdram, ctx, 0x80084D98);
    return;
    // 0x80084D9C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void chdippy_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801354: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801358: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080135C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801360: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80801364: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801368: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080136C: jal         0x80106790
    // 0x80801370: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80801370: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80801374: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80801378: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8080137C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80801380: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80801384: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x80801388: addu        $a0, $t0, $a2
    ctx->r4 = ADD32(ctx->r8, ctx->r6);
    // 0x8080138C: sltu        $at, $a2, $a0
    ctx->r1 = ctx->r6 < ctx->r4 ? 1 : 0;
    // 0x80801390: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x80801394: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80801398: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x8080139C: beq         $at, $zero, L_808013C0
    if (ctx->r1 == 0) {
        // 0x808013A0: sra         $v1, $t7, 16
        ctx->r3 = S32(SIGNED(ctx->r15) >> 16);
            goto L_808013C0;
    }
    // 0x808013A0: sra         $v1, $t7, 16
    ctx->r3 = S32(SIGNED(ctx->r15) >> 16);
L_808013A4:
    // 0x808013A4: lh          $t1, 0x2($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X2);
    // 0x808013A8: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x808013AC: sltu        $at, $a2, $a0
    ctx->r1 = ctx->r6 < ctx->r4 ? 1 : 0;
    // 0x808013B0: addu        $t2, $t1, $v1
    ctx->r10 = ADD32(ctx->r9, ctx->r3);
    // 0x808013B4: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x808013B8: bne         $at, $zero, L_808013A4
    if (ctx->r1 != 0) {
        // 0x808013BC: sh          $t2, -0xE($a2)
        MEM_H(-0XE, ctx->r6) = ctx->r10;
            goto L_808013A4;
    }
    // 0x808013BC: sh          $t2, -0xE($a2)
    MEM_H(-0XE, ctx->r6) = ctx->r10;
L_808013C0:
    // 0x808013C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808013C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808013C8: jr          $ra
    // 0x808013CC: nop

    return;
    // 0x808013CC: nop

;}
RECOMP_FUNC void _bsbeemain_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082870: syscall     17
    recomp_syscall_handler(rdram, ctx, 0x80082870);
    return;
    // 0x80082874: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800018_chfactorycrusher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8080001C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800020: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80800024: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800028: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8080002C: addiu       $s0, $s4, 0x4
    ctx->r16 = ADD32(ctx->r20, 0X4);
    // 0x80800030: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800034: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800038: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8080003C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800040: jal         0x800EE7F8
    // 0x80800044: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800044: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_0:
    // 0x80800048: addiu       $s1, $s4, 0x28
    ctx->r17 = ADD32(ctx->r20, 0X28);
    // 0x8080004C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800050: jal         0x800EE7F8
    // 0x80800054: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800054: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80800058: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080005C: lw          $a1, 0x48($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X48);
    // 0x80800060: jal         0x800EF1B8
    // 0x80800064: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    func_800EF1B8(rdram, ctx);
        goto after_2;
    // 0x80800064: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    after_2:
    // 0x80800068: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080006C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800070: jal         0x8010A63C
    // 0x80800074: swc1        $f4, 0x58($s4)
    MEM_W(0X58, ctx->r20) = ctx->f4.u32l;
    func_8010A63C(rdram, ctx);
        goto after_3;
    // 0x80800074: swc1        $f4, 0x58($s4)
    MEM_W(0X58, ctx->r20) = ctx->f4.u32l;
    after_3:
    // 0x80800078: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8080007C: jal         0x80100094
    // 0x80800080: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x80800080: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800084: addiu       $s0, $sp, 0x50
    ctx->r16 = ADD32(ctx->r29, 0X50);
    // 0x80800088: addiu       $s1, $sp, 0x44
    ctx->r17 = ADD32(ctx->r29, 0X44);
    // 0x8080008C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800090: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80800094: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800098: jal         0x80104004
    // 0x8080009C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_80104004(rdram, ctx);
        goto after_5;
    // 0x8080009C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_5:
    // 0x808000A0: beq         $v0, $zero, L_80800104
    if (ctx->r2 == 0) {
        // 0x808000A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800104;
    }
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808000AC: jal         0x800EF934
    // 0x808000B0: lw          $a2, 0x48($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X48);
    func_800EF934(rdram, ctx);
        goto after_6;
    // 0x808000B0: lw          $a2, 0x48($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X48);
    after_6:
    // 0x808000B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808000B8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808000BC: jal         0x800EF934
    // 0x808000C0: lw          $a2, 0x48($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X48);
    func_800EF934(rdram, ctx);
        goto after_7;
    // 0x808000C0: lw          $a2, 0x48($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X48);
    after_7:
    // 0x808000C4: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
    // 0x808000C8: addiu       $s3, $sp, 0x50
    ctx->r19 = ADD32(ctx->r29, 0X50);
    // 0x808000CC: addiu       $s1, $sp, 0x50
    ctx->r17 = ADD32(ctx->r29, 0X50);
    // 0x808000D0: addiu       $s0, $sp, 0x44
    ctx->r16 = ADD32(ctx->r29, 0X44);
L_808000D4:
    // 0x808000D4: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
    // 0x808000D8: jal         0x800F13F0
    // 0x808000DC: lwc1        $f14, 0x0($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X0);
    func_800F13F0(rdram, ctx);
        goto after_8;
    // 0x808000DC: lwc1        $f14, 0x0($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X0);
    after_8:
    // 0x808000E0: swc1        $f0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f0.u32l;
    // 0x808000E4: lwc1        $f14, 0x0($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X0);
    // 0x808000E8: jal         0x800F0E00
    // 0x808000EC: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
    func_800F0E00(rdram, ctx);
        goto after_9;
    // 0x808000EC: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
    after_9:
    // 0x808000F0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x808000F4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x808000F8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x808000FC: bne         $s0, $s3, L_808000D4
    if (ctx->r16 != ctx->r19) {
        // 0x80800100: swc1        $f0, 0x8($s2)
        MEM_W(0X8, ctx->r18) = ctx->f0.u32l;
            goto L_808000D4;
    }
    // 0x80800100: swc1        $f0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f0.u32l;
L_80800104:
    // 0x80800104: lhu         $t6, 0x76($s4)
    ctx->r14 = MEM_HU(ctx->r20, 0X76);
    // 0x80800108: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x8080010C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800110: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800114: beql        $t7, $at, L_80800134
    if (ctx->r15 == ctx->r1) {
        // 0x80800118: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800134;
    }
    goto skip_0;
    // 0x80800118: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x8080011C: jal         0x80101FDC
    // 0x80800120: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80101FDC(rdram, ctx);
        goto after_10;
    // 0x80800120: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_10:
    // 0x80800124: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800128: jal         0x80103110
    // 0x8080012C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_11;
    // 0x8080012C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80800130: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800134:
    // 0x80800134: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800138: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8080013C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800140: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80800144: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800148: jr          $ra
    // 0x8080014C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8080014C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_808000B8_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000BC: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1752, 0X4DFC) << 16);
    // 0x808000C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000C4: addiu       $t6, $t6, 0x4DFC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1752, 0X4DFC));
    // 0x808000C8: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x808000CC: addiu       $v0, $sp, 0x18
    ctx->r2 = ADD32(ctx->r29, 0X18);
    // 0x808000D0: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x808000D4: sw          $at, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r1;
    // 0x808000D8: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x808000DC: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x808000E0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x808000E4: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x808000E8: sw          $at, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r1;
    // 0x808000EC: lw          $t9, 0xC($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XC);
    // 0x808000F0: sw          $t9, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r25;
    // 0x808000F4: jal         0x800904C8
    // 0x808000F8: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    func_800904C8(rdram, ctx);
        goto after_0;
    // 0x808000F8: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    after_0:
    // 0x808000FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800100: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800104: jr          $ra
    // 0x80800108: nop

    return;
    // 0x80800108: nop

;}
RECOMP_FUNC void func_808016A0_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808016A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808016A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808016A8: jal         0x80106790
    // 0x808016AC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808016AC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808016B0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x808016B4: beql        $t6, $zero, L_808016D0
    if (ctx->r14 == 0) {
        // 0x808016B8: lbu         $t0, 0x65($v0)
        ctx->r8 = MEM_BU(ctx->r2, 0X65);
            goto L_808016D0;
    }
    goto skip_0;
    // 0x808016B8: lbu         $t0, 0x65($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X65);
    skip_0:
    // 0x808016BC: lbu         $t8, 0x65($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X65);
    // 0x808016C0: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x808016C4: b           L_808016D8
    // 0x808016C8: sb          $t9, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r25;
        goto L_808016D8;
    // 0x808016C8: sb          $t9, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r25;
    // 0x808016CC: lbu         $t0, 0x65($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X65);
L_808016D0:
    // 0x808016D0: andi        $t1, $t0, 0xFFEF
    ctx->r9 = ctx->r8 & 0XFFEF;
    // 0x808016D4: sb          $t1, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r9;
L_808016D8:
    // 0x808016D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808016DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808016E0: jr          $ra
    // 0x808016E4: nop

    return;
    // 0x808016E4: nop

;}
RECOMP_FUNC void _chnests_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085AC0: syscall     191
    recomp_syscall_handler(rdram, ctx, 0x80085AC0);
    return;
    // 0x80085AC4: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_80804610_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804610: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80804614: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80804618: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080461C: jal         0x80100094
    // 0x80804620: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80804620: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80804624: jal         0x800D8FF8
    // 0x80804628: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80804628: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8080462C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80804630: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80804634: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80804638: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8080463C: lw          $t6, 0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC);
    // 0x80804640: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80804644: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80804648: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8080464C: jal         0x800F13C4
    // 0x80804650: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    func_800F13C4(rdram, ctx);
        goto after_2;
    // 0x80804650: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    after_2:
    // 0x80804654: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80804658: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8080465C: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x80804660: lw          $t1, 0xC($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XC);
    // 0x80804664: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x80804668: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8080466C: div         $zero, $t0, $t1
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r9)));
    // 0x80804670: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80804674: mfhi        $t2
    ctx->r10 = hi;
    // 0x80804678: andi        $t3, $t2, 0x1F
    ctx->r11 = ctx->r10 & 0X1F;
    // 0x8080467C: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x80804680: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80804684: andi        $t5, $t4, 0xF8
    ctx->r13 = ctx->r12 & 0XF8;
    // 0x80804688: lbu         $t6, 0xA($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XA);
    // 0x8080468C: bne         $t1, $zero, L_80804698
    if (ctx->r9 != 0) {
        // 0x80804690: nop
    
            goto L_80804698;
    }
    // 0x80804690: nop

    // 0x80804694: break       7
    do_break(2155890324);
L_80804698:
    // 0x80804698: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8080469C: bne         $t1, $at, L_808046B0
    if (ctx->r9 != ctx->r1) {
        // 0x808046A0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_808046B0;
    }
    // 0x808046A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808046A4: bne         $t0, $at, L_808046B0
    if (ctx->r8 != ctx->r1) {
        // 0x808046A8: nop
    
            goto L_808046B0;
    }
    // 0x808046A8: nop

    // 0x808046AC: break       6
    do_break(2155890348);
L_808046B0:
    // 0x808046B0: andi        $t7, $t6, 0xFF07
    ctx->r15 = ctx->r14 & 0XFF07;
    // 0x808046B4: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x808046B8: sb          $t8, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r24;
    // 0x808046BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808046C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808046C4: jr          $ra
    // 0x808046C8: nop

    return;
    // 0x808046C8: nop

;}
RECOMP_FUNC void func_808003C4_chcheato(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808003C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808003D0: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x808003D4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x808003D8: jal         0x80800824
    // 0x808003DC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_80800824_chcheato(rdram, ctx);
        goto after_0;
    // 0x808003DC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x808003E0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(868, 0XEE6) << 16);
    // 0x808003E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808003E8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x808003EC: sh          $v0, 0xEE6($at)
    MEM_H((int16_t)RELOC_LO16(868, 0XEE6), ctx->r1) = ctx->r2;
    // 0x808003F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(868, 0XEF4) << 16);
    // 0x808003F4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(868, 0XEE0) << 16);
    // 0x808003F8: addiu       $a2, $a2, 0xEE0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(868, 0XEE0));
    // 0x808003FC: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x80800400: jal         0x8008A1E8
    // 0x80800404: sh          $t7, 0xEF4($at)
    MEM_H((int16_t)RELOC_LO16(868, 0XEF4), ctx->r1) = ctx->r15;
    _subaddiedialog_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x80800404: sh          $t7, 0xEF4($at)
    MEM_H((int16_t)RELOC_LO16(868, 0XEF4), ctx->r1) = ctx->r15;
    after_1:
    // 0x80800408: beq         $v0, $zero, L_80800424
    if (ctx->r2 == 0) {
        // 0x8080040C: addiu       $at, $zero, 0x1208
        ctx->r1 = ADD32(0, 0X1208);
            goto L_80800424;
    }
    // 0x8080040C: addiu       $at, $zero, 0x1208
    ctx->r1 = ADD32(0, 0X1208);
    // 0x80800410: beq         $v0, $at, L_80800424
    if (ctx->r2 == ctx->r1) {
        // 0x80800414: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800424;
    }
    // 0x80800414: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800418: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8080041C: jal         0x80800D08
    // 0x80800420: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80800D08_chcheato(rdram, ctx);
        goto after_2;
    // 0x80800420: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
L_80800424:
    // 0x80800424: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800428: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080042C: jr          $ra
    // 0x80800430: nop

    return;
    // 0x80800430: nop

;}
RECOMP_FUNC void func_808001A4_chsquits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001AC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808001B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808001B4: lw          $a2, 0x30($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X30);
    // 0x808001B8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808001BC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_808001C0:
    // 0x808001C0: sllv        $t7, $t6, $v1
    ctx->r15 = S32(ctx->r14 << (ctx->r3 & 31));
    // 0x808001C4: and         $t8, $a2, $t7
    ctx->r24 = ctx->r6 & ctx->r15;
    // 0x808001C8: bne         $t8, $zero, L_808001D4
    if (ctx->r24 != 0) {
        // 0x808001CC: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_808001D4;
    }
    // 0x808001CC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x808001D0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_808001D4:
    // 0x808001D4: sltiu       $at, $v1, 0xA
    ctx->r1 = ctx->r3 < 0XA ? 1 : 0;
    // 0x808001D8: bnel        $at, $zero, L_808001C0
    if (ctx->r1 != 0) {
        // 0x808001DC: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_808001C0;
    }
    goto skip_0;
    // 0x808001DC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    skip_0:
    // 0x808001E0: bne         $a1, $zero, L_808001F0
    if (ctx->r5 != 0) {
        // 0x808001E4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_808001F0;
    }
    // 0x808001E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808001E8: sw          $zero, 0x30($a3)
    MEM_W(0X30, ctx->r7) = 0;
    // 0x808001EC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
L_808001F0:
    // 0x808001F0: jal         0x800DC128
    // 0x808001F4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800DC128(rdram, ctx);
        goto after_0;
    // 0x808001F4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x808001F8: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x808001FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800200: lw          $a2, 0x30($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X30);
    // 0x80800204: andi        $t9, $a2, 0x1
    ctx->r25 = ctx->r6 & 0X1;
    // 0x80800208: bne         $t9, $zero, L_8080022C
    if (ctx->r25 != 0) {
        // 0x8080020C: andi        $t2, $a2, 0x2
        ctx->r10 = ctx->r6 & 0X2;
            goto L_8080022C;
    }
    // 0x8080020C: andi        $t2, $a2, 0x2
    ctx->r10 = ctx->r6 & 0X2;
    // 0x80800210: bne         $v0, $zero, L_8080022C
    if (ctx->r2 != 0) {
        // 0x80800214: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8080022C;
    }
    // 0x80800214: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800218: ori         $t1, $a2, 0x1
    ctx->r9 = ctx->r6 | 0X1;
    // 0x8080021C: sw          $t1, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r9;
    // 0x80800220: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1456, 0X6C4) << 16);
    // 0x80800224: b           L_80800348
    // 0x80800228: lh          $v0, 0x6C4($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(1456, 0X6C4));
        goto L_80800348;
    // 0x80800228: lh          $v0, 0x6C4($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(1456, 0X6C4));
L_8080022C:
    // 0x8080022C: bne         $t2, $zero, L_80800250
    if (ctx->r10 != 0) {
        // 0x80800230: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_80800250;
    }
    // 0x80800230: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80800234: bne         $a0, $v0, L_8080024C
    if (ctx->r4 != ctx->r2) {
        // 0x80800238: ori         $t3, $a2, 0x2
        ctx->r11 = ctx->r6 | 0X2;
            goto L_8080024C;
    }
    // 0x80800238: ori         $t3, $a2, 0x2
    ctx->r11 = ctx->r6 | 0X2;
    // 0x8080023C: sw          $t3, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r11;
    // 0x80800240: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1456, 0X6C6) << 16);
    // 0x80800244: b           L_80800348
    // 0x80800248: lh          $v0, 0x6C6($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(1456, 0X6C6));
        goto L_80800348;
    // 0x80800248: lh          $v0, 0x6C6($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(1456, 0X6C6));
L_8080024C:
    // 0x8080024C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80800250:
    // 0x80800250: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x80800254: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
L_80800258:
    // 0x80800258: sllv        $a1, $t4, $v1
    ctx->r5 = S32(ctx->r12 << (ctx->r3 & 31));
    // 0x8080025C: and         $t5, $a2, $a1
    ctx->r13 = ctx->r6 & ctx->r5;
    // 0x80800260: bne         $t5, $zero, L_8080028C
    if (ctx->r13 != 0) {
        // 0x80800264: addiu       $t8, $v1, 0x1
        ctx->r24 = ADD32(ctx->r3, 0X1);
            goto L_8080028C;
    }
    // 0x80800264: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x80800268: bne         $a0, $v0, L_80800288
    if (ctx->r4 != ctx->r2) {
        // 0x8080026C: or          $t6, $a2, $a1
        ctx->r14 = ctx->r6 | ctx->r5;
            goto L_80800288;
    }
    // 0x8080026C: or          $t6, $a2, $a1
    ctx->r14 = ctx->r6 | ctx->r5;
    // 0x80800270: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x80800274: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1456, 0X6C4) << 16);
    // 0x80800278: sw          $t6, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r14;
    // 0x8080027C: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80800280: b           L_80800348
    // 0x80800284: lh          $v0, 0x6C4($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(1456, 0X6C4));
        goto L_80800348;
    // 0x80800284: lh          $v0, 0x6C4($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(1456, 0X6C4));
L_80800288:
    // 0x80800288: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8080028C:
    // 0x8080028C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80800290: sllv        $a1, $t9, $t8
    ctx->r5 = S32(ctx->r25 << (ctx->r24 & 31));
    // 0x80800294: and         $t1, $a2, $a1
    ctx->r9 = ctx->r6 & ctx->r5;
    // 0x80800298: bne         $t1, $zero, L_808002C4
    if (ctx->r9 != 0) {
        // 0x8080029C: addiu       $t4, $v1, 0x2
        ctx->r12 = ADD32(ctx->r3, 0X2);
            goto L_808002C4;
    }
    // 0x8080029C: addiu       $t4, $v1, 0x2
    ctx->r12 = ADD32(ctx->r3, 0X2);
    // 0x808002A0: bne         $a0, $v0, L_808002C0
    if (ctx->r4 != ctx->r2) {
        // 0x808002A4: or          $t2, $a2, $a1
        ctx->r10 = ctx->r6 | ctx->r5;
            goto L_808002C0;
    }
    // 0x808002A4: or          $t2, $a2, $a1
    ctx->r10 = ctx->r6 | ctx->r5;
    // 0x808002A8: sll         $t3, $v1, 1
    ctx->r11 = S32(ctx->r3 << 1);
    // 0x808002AC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1456, 0X6C6) << 16);
    // 0x808002B0: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x808002B4: sw          $t2, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r10;
    // 0x808002B8: b           L_80800348
    // 0x808002BC: lh          $v0, 0x6C6($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(1456, 0X6C6));
        goto L_80800348;
    // 0x808002BC: lh          $v0, 0x6C6($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(1456, 0X6C6));
L_808002C0:
    // 0x808002C0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_808002C4:
    // 0x808002C4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x808002C8: sllv        $a1, $t5, $t4
    ctx->r5 = S32(ctx->r13 << (ctx->r12 & 31));
    // 0x808002CC: and         $t6, $a2, $a1
    ctx->r14 = ctx->r6 & ctx->r5;
    // 0x808002D0: bne         $t6, $zero, L_808002FC
    if (ctx->r14 != 0) {
        // 0x808002D4: addiu       $t8, $v1, 0x3
        ctx->r24 = ADD32(ctx->r3, 0X3);
            goto L_808002FC;
    }
    // 0x808002D4: addiu       $t8, $v1, 0x3
    ctx->r24 = ADD32(ctx->r3, 0X3);
    // 0x808002D8: bne         $a0, $v0, L_808002F8
    if (ctx->r4 != ctx->r2) {
        // 0x808002DC: or          $t7, $a2, $a1
        ctx->r15 = ctx->r6 | ctx->r5;
            goto L_808002F8;
    }
    // 0x808002DC: or          $t7, $a2, $a1
    ctx->r15 = ctx->r6 | ctx->r5;
    // 0x808002E0: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x808002E4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1456, 0X6C8) << 16);
    // 0x808002E8: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x808002EC: sw          $t7, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r15;
    // 0x808002F0: b           L_80800348
    // 0x808002F4: lh          $v0, 0x6C8($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(1456, 0X6C8));
        goto L_80800348;
    // 0x808002F4: lh          $v0, 0x6C8($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(1456, 0X6C8));
L_808002F8:
    // 0x808002F8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_808002FC:
    // 0x808002FC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80800300: sllv        $a1, $t1, $t8
    ctx->r5 = S32(ctx->r9 << (ctx->r24 & 31));
    // 0x80800304: and         $t2, $a2, $a1
    ctx->r10 = ctx->r6 & ctx->r5;
    // 0x80800308: bnel        $t2, $zero, L_80800338
    if (ctx->r10 != 0) {
        // 0x8080030C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80800338;
    }
    goto skip_1;
    // 0x8080030C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_1:
    // 0x80800310: bne         $a0, $v0, L_80800330
    if (ctx->r4 != ctx->r2) {
        // 0x80800314: or          $t3, $a2, $a1
        ctx->r11 = ctx->r6 | ctx->r5;
            goto L_80800330;
    }
    // 0x80800314: or          $t3, $a2, $a1
    ctx->r11 = ctx->r6 | ctx->r5;
    // 0x80800318: sll         $t5, $v1, 1
    ctx->r13 = S32(ctx->r3 << 1);
    // 0x8080031C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1456, 0X6CA) << 16);
    // 0x80800320: addu        $v0, $v0, $t5
    ctx->r2 = ADD32(ctx->r2, ctx->r13);
    // 0x80800324: sw          $t3, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r11;
    // 0x80800328: b           L_80800348
    // 0x8080032C: lh          $v0, 0x6CA($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(1456, 0X6CA));
        goto L_80800348;
    // 0x8080032C: lh          $v0, 0x6CA($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(1456, 0X6CA));
L_80800330:
    // 0x80800330: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80800334: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80800338:
    // 0x80800338: bnel        $v1, $t0, L_80800258
    if (ctx->r3 != ctx->r8) {
        // 0x8080033C: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_80800258;
    }
    goto skip_2;
    // 0x8080033C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    skip_2:
    // 0x80800340: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1456, 0X6C4) << 16);
    // 0x80800344: lh          $v0, 0x6C4($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(1456, 0X6C4));
L_80800348:
    // 0x80800348: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080034C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800350: jr          $ra
    // 0x80800354: nop

    return;
    // 0x80800354: nop

;}
RECOMP_FUNC void _babounce_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800845E0: syscall     116
    recomp_syscall_handler(rdram, ctx, 0x800845E0);
    return;
    // 0x800845E4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80800014_ch1pfreeze(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800014: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800018: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080001C: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800020: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800024: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x80800028: beql        $at, $zero, L_80800048
    if (ctx->r1 == 0) {
        // 0x8080002C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800048;
    }
    goto skip_0;
    // 0x8080002C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800030: jal         0x80100094
    // 0x80800034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800038: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8080003C: jal         0x800F7B9C
    // 0x80800040: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_800F7B9C(rdram, ctx);
        goto after_1;
    // 0x80800040: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_1:
    // 0x80800044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800048:
    // 0x80800048: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080004C: jr          $ra
    // 0x80800050: nop

    return;
    // 0x80800050: nop

;}
RECOMP_FUNC void _bsstonehead_entrypoint_27(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083CB8: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083CB8);
    return;
    // 0x80083CBC: addi        $t0, $zero, 0x6C
    ctx->r8 = ADD32(0, 0X6C);
;}
RECOMP_FUNC void func_8080034C_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080034C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800350: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800354: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800358: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080035C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800360: jal         0x80100094
    // 0x80800364: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800364: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800368: lw          $s0, 0x94($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X94);
    // 0x8080036C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800370: jal         0x80100094
    // 0x80800374: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800374: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800378: lbu         $t6, 0x98($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X98);
    // 0x8080037C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80800380: bnel        $t6, $zero, L_808003AC
    if (ctx->r14 != 0) {
        // 0x80800384: lw          $t8, 0x24($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X24);
            goto L_808003AC;
    }
    goto skip_0;
    // 0x80800384: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800388: beql        $t7, $zero, L_808005B0
    if (ctx->r15 == 0) {
        // 0x8080038C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808005B0;
    }
    goto skip_1;
    // 0x8080038C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800390: jal         0x80800B6C
    // 0x80800394: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800B6C_chquiz(rdram, ctx);
        goto after_2;
    // 0x80800394: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800398: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080039C: jal         0x808000FC
    // 0x808003A0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_808000FC_chquiz(rdram, ctx);
        goto after_3;
    // 0x808003A0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x808003A4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808003A8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
L_808003AC:
    // 0x808003AC: sltiu       $at, $t8, 0x5
    ctx->r1 = ctx->r24 < 0X5 ? 1 : 0;
    // 0x808003B0: beq         $at, $zero, L_80800598
    if (ctx->r1 == 0) {
        // 0x808003B4: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800598;
    }
    // 0x808003B4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808003B8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X6554) << 16);
    // 0x808003BC: addu        $at, $at, $t8
    gpr jr_addend_808003C4 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x808003C0: lw          $t8, 0x6554($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2484, 0X6554));
    // 0x808003C4: jr          $t8
    // 0x808003C8: nop

    switch (jr_addend_808003C4 >> 2) {
        case 0: goto L_808003CC; break;
        case 1: goto L_808003FC; break;
        case 2: goto L_80800424; break;
        case 3: goto L_80800494; break;
        case 4: goto L_80800530; break;
        default: switch_error(__func__, 0x808003C4, 0x80806554);
    }
    // 0x808003C8: nop

L_808003CC:
    // 0x808003CC: beq         $s0, $zero, L_808003E8
    if (ctx->r16 == 0) {
        // 0x808003D0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808003E8;
    }
    // 0x808003D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808003D4: jal         0x80100094
    // 0x808003D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x808003D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808003DC: lw          $a0, 0x94($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X94);
    // 0x808003E0: jal         0x80087DC0
    // 0x808003E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcnewoption_entrypoint_37(rdram, ctx);
        goto after_5;
    // 0x808003E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
L_808003E8:
    // 0x808003E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808003EC: jal         0x80100094
    // 0x808003F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_6;
    // 0x808003F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x808003F4: b           L_80800598
    // 0x808003F8: sb          $zero, 0x99($v0)
    MEM_B(0X99, ctx->r2) = 0;
        goto L_80800598;
    // 0x808003F8: sb          $zero, 0x99($v0)
    MEM_B(0X99, ctx->r2) = 0;
L_808003FC:
    // 0x808003FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800400: jal         0x80100094
    // 0x80800404: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_7;
    // 0x80800404: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80800408: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8080040C: sb          $t9, 0x99($v0)
    MEM_B(0X99, ctx->r2) = ctx->r25;
    // 0x80800410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800414: jal         0x80087E08
    // 0x80800418: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    _gcnewoption_entrypoint_46(rdram, ctx);
        goto after_8;
    // 0x80800418: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_8:
    // 0x8080041C: b           L_8080059C
    // 0x80800420: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
        goto L_8080059C;
    // 0x80800420: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_80800424:
    // 0x80800424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800428: jal         0x80087D60
    // 0x8080042C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcnewoption_entrypoint_25(rdram, ctx);
        goto after_9;
    // 0x8080042C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80800430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800434: jal         0x80087D68
    // 0x80800438: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcnewoption_entrypoint_26(rdram, ctx);
        goto after_10;
    // 0x80800438: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x8080043C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800440: jal         0x80087D80
    // 0x80800444: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcnewoption_entrypoint_29(rdram, ctx);
        goto after_11;
    // 0x80800444: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80800448: jal         0x8008A7E8
    // 0x8080044C: nop

    _suquiz_entrypoint_6(rdram, ctx);
        goto after_12;
    // 0x8080044C: nop

    after_12:
    // 0x80800450: jal         0x8008A808
    // 0x80800454: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _suquiz_entrypoint_10(rdram, ctx);
        goto after_13;
    // 0x80800454: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_13:
    // 0x80800458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080045C: jal         0x80087E08
    // 0x80800460: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _gcnewoption_entrypoint_46(rdram, ctx);
        goto after_14;
    // 0x80800460: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_14:
    // 0x80800464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800468: jal         0x80087DF8
    // 0x8080046C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcnewoption_entrypoint_44(rdram, ctx);
        goto after_15;
    // 0x8080046C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x80800470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800474: jal         0x80087DE0
    // 0x80800478: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gcnewoption_entrypoint_41(rdram, ctx);
        goto after_16;
    // 0x80800478: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x8080047C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800480: jal         0x80100094
    // 0x80800484: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_17;
    // 0x80800484: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_17:
    // 0x80800488: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8080048C: b           L_80800598
    // 0x80800490: sb          $t0, 0x99($v0)
    MEM_B(0X99, ctx->r2) = ctx->r8;
        goto L_80800598;
    // 0x80800490: sb          $t0, 0x99($v0)
    MEM_B(0X99, ctx->r2) = ctx->r8;
L_80800494:
    // 0x80800494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800498: jal         0x80087D60
    // 0x8080049C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcnewoption_entrypoint_25(rdram, ctx);
        goto after_18;
    // 0x8080049C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_18:
    // 0x808004A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004A4: jal         0x80087D68
    // 0x808004A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gcnewoption_entrypoint_26(rdram, ctx);
        goto after_19;
    // 0x808004A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_19:
    // 0x808004AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004B0: jal         0x80087D80
    // 0x808004B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gcnewoption_entrypoint_29(rdram, ctx);
        goto after_20;
    // 0x808004B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_20:
    // 0x808004B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004BC: jal         0x80087E08
    // 0x808004C0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    _gcnewoption_entrypoint_46(rdram, ctx);
        goto after_21;
    // 0x808004C0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_21:
    // 0x808004C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004C8: jal         0x80087DF8
    // 0x808004CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gcnewoption_entrypoint_44(rdram, ctx);
        goto after_22;
    // 0x808004CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_22:
    // 0x808004D0: jal         0x80800C00
    // 0x808004D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800C00_chquiz(rdram, ctx);
        goto after_23;
    // 0x808004D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_23:
    // 0x808004D8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808004DC: beql        $v0, $at, L_8080051C
    if (ctx->r2 == ctx->r1) {
        // 0x808004E0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8080051C;
    }
    goto skip_2;
    // 0x808004E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_2:
    // 0x808004E4: jal         0x80800C00
    // 0x808004E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800C00_chquiz(rdram, ctx);
        goto after_24;
    // 0x808004E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_24:
    // 0x808004EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004F0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808004F4: jal         0x80087DF0
    // 0x808004F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _gcnewoption_entrypoint_43(rdram, ctx);
        goto after_25;
    // 0x808004F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_25:
    // 0x808004FC: jal         0x80800C00
    // 0x80800500: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800C00_chquiz(rdram, ctx);
        goto after_26;
    // 0x80800500: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_26:
    // 0x80800504: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2484, 0X70B0) << 16);
    // 0x80800508: addiu       $a2, $a2, 0x70B0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2484, 0X70B0));
    // 0x8080050C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800510: jal         0x80087D00
    // 0x80800514: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _gcnewoption_entrypoint_13(rdram, ctx);
        goto after_27;
    // 0x80800514: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_27:
    // 0x80800518: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_8080051C:
    // 0x8080051C: jal         0x80100094
    // 0x80800520: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_28;
    // 0x80800520: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_28:
    // 0x80800524: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80800528: b           L_80800598
    // 0x8080052C: sb          $t1, 0x99($v0)
    MEM_B(0X99, ctx->r2) = ctx->r9;
        goto L_80800598;
    // 0x8080052C: sb          $t1, 0x99($v0)
    MEM_B(0X99, ctx->r2) = ctx->r9;
L_80800530:
    // 0x80800530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800534: jal         0x80087D68
    // 0x80800538: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcnewoption_entrypoint_26(rdram, ctx);
        goto after_29;
    // 0x80800538: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_29:
    // 0x8080053C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800540: jal         0x80087D80
    // 0x80800544: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcnewoption_entrypoint_29(rdram, ctx);
        goto after_30;
    // 0x80800544: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_30:
    // 0x80800548: jal         0x80800C00
    // 0x8080054C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800C00_chquiz(rdram, ctx);
        goto after_31;
    // 0x8080054C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_31:
    // 0x80800550: bne         $v0, $zero, L_80800560
    if (ctx->r2 != 0) {
        // 0x80800554: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800560;
    }
    // 0x80800554: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800558: b           L_80800560
    // 0x8080055C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80800560;
    // 0x8080055C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80800560:
    // 0x80800560: jal         0x80087DE0
    // 0x80800564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcnewoption_entrypoint_41(rdram, ctx);
        goto after_32;
    // 0x80800564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x80800568: jal         0x8008A7E8
    // 0x8080056C: nop

    _suquiz_entrypoint_6(rdram, ctx);
        goto after_33;
    // 0x8080056C: nop

    after_33:
    // 0x80800570: jal         0x8008A808
    // 0x80800574: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _suquiz_entrypoint_10(rdram, ctx);
        goto after_34;
    // 0x80800574: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_34:
    // 0x80800578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080057C: jal         0x80087E08
    // 0x80800580: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _gcnewoption_entrypoint_46(rdram, ctx);
        goto after_35;
    // 0x80800580: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_35:
    // 0x80800584: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800588: jal         0x80100094
    // 0x8080058C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_36;
    // 0x8080058C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_36:
    // 0x80800590: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80800594: sb          $t2, 0x99($v0)
    MEM_B(0X99, ctx->r2) = ctx->r10;
L_80800598:
    // 0x80800598: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_8080059C:
    // 0x8080059C: jal         0x80100094
    // 0x808005A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_37;
    // 0x808005A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_37:
    // 0x808005A4: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x808005A8: sb          $t3, 0x98($v0)
    MEM_B(0X98, ctx->r2) = ctx->r11;
    // 0x808005AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808005B0:
    // 0x808005B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808005B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808005B8: jr          $ra
    // 0x808005BC: nop

    return;
    // 0x808005BC: nop

;}
RECOMP_FUNC void _bsbkflamethrower_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800829B8: syscall     23
    recomp_syscall_handler(rdram, ctx, 0x800829B8);
    return;
    // 0x800829BC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void bamoveledge_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: jr          $ra
    // 0x8080000C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8080000C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80805CD8_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80805CD8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80805CDC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80805CE0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80805CE4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80805CE8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80805CEC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80805CF0: lw          $a2, 0x20($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X20);
    // 0x80805CF4: jal         0x80806068
    // 0x80805CF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80806068_chgameselect(rdram, ctx);
        goto after_0;
    // 0x80805CF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80805CFC: jal         0x80088380
    // 0x80805D00: nop

    _gcstatusDll_entrypoint_14(rdram, ctx);
        goto after_1;
    // 0x80805D00: nop

    after_1:
    // 0x80805D04: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80805D08: bne         $v0, $at, L_80805D18
    if (ctx->r2 != ctx->r1) {
        // 0x80805D0C: nop
    
            goto L_80805D18;
    }
    // 0x80805D0C: nop

    // 0x80805D10: jal         0x80088330
    // 0x80805D14: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _gcstatusDll_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80805D14: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
L_80805D18:
    // 0x80805D18: jal         0x80088380
    // 0x80805D1C: nop

    _gcstatusDll_entrypoint_14(rdram, ctx);
        goto after_3;
    // 0x80805D1C: nop

    after_3:
    // 0x80805D20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805D24: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80805D28: jal         0x80806068
    // 0x80805D2C: addiu       $a2, $v0, -0x1
    ctx->r6 = ADD32(ctx->r2, -0X1);
    func_80806068_chgameselect(rdram, ctx);
        goto after_4;
    // 0x80805D2C: addiu       $a2, $v0, -0x1
    ctx->r6 = ADD32(ctx->r2, -0X1);
    after_4:
    // 0x80805D30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805D34: jal         0x80805ECC
    // 0x80805D38: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80805ECC_chgameselect(rdram, ctx);
        goto after_5;
    // 0x80805D38: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x80805D3C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80805D40: beq         $v0, $at, L_80805D4C
    if (ctx->r2 == ctx->r1) {
        // 0x80805D44: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80805D4C;
    }
    // 0x80805D44: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80805D48: bne         $v0, $at, L_80805D54
    if (ctx->r2 != ctx->r1) {
        // 0x80805D4C: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80805D54;
    }
L_80805D4C:
    // 0x80805D4C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80805D50: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
L_80805D54:
    // 0x80805D54: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80805D58: beq         $v0, $at, L_80805D70
    if (ctx->r2 == ctx->r1) {
        // 0x80805D5C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80805D70;
    }
    // 0x80805D5C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80805D60: beq         $v0, $at, L_80805D84
    if (ctx->r2 == ctx->r1) {
        // 0x80805D64: addiu       $t7, $v0, 0x5
        ctx->r15 = ADD32(ctx->r2, 0X5);
            goto L_80805D84;
    }
    // 0x80805D64: addiu       $t7, $v0, 0x5
    ctx->r15 = ADD32(ctx->r2, 0X5);
    // 0x80805D68: b           L_80805D94
    // 0x80805D6C: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
        goto L_80805D94;
    // 0x80805D6C: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
L_80805D70:
    // 0x80805D70: jal         0x808068E8
    // 0x80805D74: nop

    func_808068E8_chgameselect(rdram, ctx);
        goto after_6;
    // 0x80805D74: nop

    after_6:
    // 0x80805D78: addiu       $t8, $v0, 0xA
    ctx->r24 = ADD32(ctx->r2, 0XA);
    // 0x80805D7C: b           L_80805D94
    // 0x80805D80: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
        goto L_80805D94;
    // 0x80805D80: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
L_80805D84:
    // 0x80805D84: jal         0x80806A30
    // 0x80805D88: nop

    func_80806A30_chgameselect(rdram, ctx);
        goto after_7;
    // 0x80805D88: nop

    after_7:
    // 0x80805D8C: addiu       $t9, $v0, 0x14
    ctx->r25 = ADD32(ctx->r2, 0X14);
    // 0x80805D90: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_80805D94:
    // 0x80805D94: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x80805D98: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80805D9C: jal         0x80802D40
    // 0x80805DA0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80802D40_chgameselect(rdram, ctx);
        goto after_8;
    // 0x80805DA0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x80805DA4: lui         $t1, 0x8081
    ctx->r9 = S32(RELOC_HI16(804, 0X8404) << 16);
    // 0x80805DA8: lbu         $t1, -0x7BFC($t1)
    ctx->r9 = MEM_BU(ctx->r9, (int16_t)RELOC_LO16(804, 0X8404));
    // 0x80805DAC: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x80805DB0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80805DB4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80805DB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80805DBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80805DC0: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x80805DC4: jal         0x80802DB4
    // 0x80805DC8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    func_80802DB4_chgameselect(rdram, ctx);
        goto after_9;
    // 0x80805DC8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_9:
    // 0x80805DCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805DD0: jal         0x80805ECC
    // 0x80805DD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80805ECC_chgameselect(rdram, ctx);
        goto after_10;
    // 0x80805DD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80805DD8: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80805DDC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80805DE0: addiu       $a2, $v1, 0x23
    ctx->r6 = ADD32(ctx->r3, 0X23);
    // 0x80805DE4: beq         $t2, $zero, L_80805DF4
    if (ctx->r10 == 0) {
        // 0x80805DE8: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80805DF4;
    }
    // 0x80805DE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80805DEC: b           L_80805DF8
    // 0x80805DF0: addiu       $a3, $zero, 0x26
    ctx->r7 = ADD32(0, 0X26);
        goto L_80805DF8;
    // 0x80805DF0: addiu       $a3, $zero, 0x26
    ctx->r7 = ADD32(0, 0X26);
L_80805DF4:
    // 0x80805DF4: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_80805DF8:
    // 0x80805DF8: lui         $t4, 0x8081
    ctx->r12 = S32(RELOC_HI16(804, 0X8405) << 16);
    // 0x80805DFC: lbu         $t4, -0x7BFB($t4)
    ctx->r12 = MEM_BU(ctx->r12, (int16_t)RELOC_LO16(804, 0X8405));
    // 0x80805E00: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x80805E04: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80805E08: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80805E0C: jal         0x80802DB4
    // 0x80805E10: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    func_80802DB4_chgameselect(rdram, ctx);
        goto after_11;
    // 0x80805E10: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_11:
    // 0x80805E14: lui         $t6, 0x8081
    ctx->r14 = S32(RELOC_HI16(804, 0X8406) << 16);
    // 0x80805E18: lbu         $t6, -0x7BFA($t6)
    ctx->r14 = MEM_BU(ctx->r14, (int16_t)RELOC_LO16(804, 0X8406));
    // 0x80805E1C: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x80805E20: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80805E24: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80805E28: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80805E2C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80805E30: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x80805E34: jal         0x80802DB4
    // 0x80805E38: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    func_80802DB4_chgameselect(rdram, ctx);
        goto after_12;
    // 0x80805E38: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_12:
    // 0x80805E3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805E40: jal         0x80805ECC
    // 0x80805E44: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80805ECC_chgameselect(rdram, ctx);
        goto after_13;
    // 0x80805E44: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_13:
    // 0x80805E48: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80805E4C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80805E50: addiu       $a2, $v1, 0x1B
    ctx->r6 = ADD32(ctx->r3, 0X1B);
    // 0x80805E54: beq         $t7, $zero, L_80805E64
    if (ctx->r15 == 0) {
        // 0x80805E58: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_80805E64;
    }
    // 0x80805E58: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80805E5C: b           L_80805E68
    // 0x80805E60: addiu       $a3, $zero, 0x27
    ctx->r7 = ADD32(0, 0X27);
        goto L_80805E68;
    // 0x80805E60: addiu       $a3, $zero, 0x27
    ctx->r7 = ADD32(0, 0X27);
L_80805E64:
    // 0x80805E64: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_80805E68:
    // 0x80805E68: lui         $t9, 0x8081
    ctx->r25 = S32(RELOC_HI16(804, 0X8407) << 16);
    // 0x80805E6C: lbu         $t9, -0x7BF9($t9)
    ctx->r25 = MEM_BU(ctx->r25, (int16_t)RELOC_LO16(804, 0X8407));
    // 0x80805E70: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x80805E74: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80805E78: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80805E7C: jal         0x80802DB4
    // 0x80805E80: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    func_80802DB4_chgameselect(rdram, ctx);
        goto after_14;
    // 0x80805E80: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_14:
    // 0x80805E84: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x80805E88: addiu       $a1, $zero, 0x18F4
    ctx->r5 = ADD32(0, 0X18F4);
    // 0x80805E8C: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80805E90: jal         0x80802E38
    // 0x80805E94: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_80802E38_chgameselect(rdram, ctx);
        goto after_15;
    // 0x80805E94: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_15:
    // 0x80805E98: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    // 0x80805E9C: jal         0x808026C8
    // 0x80805EA0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_808026C8_chgameselect(rdram, ctx);
        goto after_16;
    // 0x80805EA0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_16:
    // 0x80805EA4: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x80805EA8: sw          $t0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r8;
    // 0x80805EAC: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x80805EB0: jal         0x80802D04
    // 0x80805EB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80802D04_chgameselect(rdram, ctx);
        goto after_17;
    // 0x80805EB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x80805EB8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80805EBC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80805EC0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80805EC4: jr          $ra
    // 0x80805EC8: nop

    return;
    // 0x80805EC8: nop

;}
RECOMP_FUNC void suexpression_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080073C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800740: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800744: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80800748: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8080074C: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x80800750: lw          $t6, 0x28($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X28);
    // 0x80800754: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800758: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8080075C: srl         $t7, $t6, 23
    ctx->r15 = S32(U32(ctx->r14) >> 23);
    // 0x80800760: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80800764: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x80800768: bgez        $t7, L_8080077C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8080076C: cvt.s.w     $f22, $f4
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8080077C;
    }
    // 0x8080076C: cvt.s.w     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800770: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800774: nop

    // 0x80800778: add.s       $f22, $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f6.fl;
L_8080077C:
    // 0x8080077C: lhu         $t8, 0x26($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X26);
    // 0x80800780: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800784: srl         $t9, $t8, 7
    ctx->r25 = S32(U32(ctx->r24) >> 7);
    // 0x80800788: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8080078C: bgez        $t9, L_808007A0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800790: cvt.s.w     $f20, $f8
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    ctx->f20.fl = CVT_S_W(ctx->f8.u32l);
            goto L_808007A0;
    }
    // 0x80800790: cvt.s.w     $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    ctx->f20.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800794: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800798: nop

    // 0x8080079C: add.s       $f20, $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f10.fl;
L_808007A0:
    // 0x808007A0: lbu         $a0, 0xD($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0XD);
    // 0x808007A4: jal         0x80800080
    // 0x808007A8: sw          $a3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r7;
    suexpression_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808007A8: sw          $a3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r7;
    after_0:
    // 0x808007AC: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x808007B0: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x808007B4: jal         0x800F1E6C
    // 0x808007B8: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    func_800F1E6C(rdram, ctx);
        goto after_1;
    // 0x808007B8: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    after_1:
    // 0x808007BC: jal         0x80013728
    // 0x808007C0: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    func_80013728(rdram, ctx);
        goto after_2;
    // 0x808007C0: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_2:
    // 0x808007C4: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x808007C8: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    // 0x808007CC: jal         0x800F0E7C
    // 0x808007D0: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    func_800F0E7C(rdram, ctx);
        goto after_3;
    // 0x808007D0: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    after_3:
    // 0x808007D4: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x808007D8: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x808007DC: lh          $v1, 0x6($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X6);
    // 0x808007E0: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    // 0x808007E4: nop

    // 0x808007E8: cvt.s.w     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808007EC: add.s       $f18, $f2, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f22.fl;
    // 0x808007F0: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x808007F4: nop

    // 0x808007F8: bc1fl       L_80800A50
    if (!c1cs) {
        // 0x808007FC: lh          $t4, 0x6($a3)
        ctx->r12 = MEM_H(ctx->r7, 0X6);
            goto L_80800A50;
    }
    goto skip_0;
    // 0x808007FC: lh          $t4, 0x6($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X6);
    skip_0:
    // 0x80800800: sub.s       $f4, $f22, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f22.fl - ctx->f2.fl;
    // 0x80800804: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800808: nop

    // 0x8080080C: bc1fl       L_80800A50
    if (!c1cs) {
        // 0x80800810: lh          $t4, 0x6($a3)
        ctx->r12 = MEM_H(ctx->r7, 0X6);
            goto L_80800A50;
    }
    goto skip_1;
    // 0x80800810: lh          $t4, 0x6($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X6);
    skip_1:
    // 0x80800814: beq         $v1, $zero, L_80800A4C
    if (ctx->r3 == 0) {
        // 0x80800818: addiu       $a0, $sp, 0x3C
        ctx->r4 = ADD32(ctx->r29, 0X3C);
            goto L_80800A4C;
    }
    // 0x80800818: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x8080081C: lh          $v0, 0x4($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X4);
    // 0x80800820: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80800824: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80800828: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8080082C: add.s       $f12, $f2, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f22.fl;
    // 0x80800830: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80800834: nop

    // 0x80800838: bc1fl       L_80800884
    if (!c1cs) {
        // 0x8080083C: lwc1        $f8, 0x54($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
            goto L_80800884;
    }
    goto skip_2;
    // 0x8080083C: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    skip_2:
    // 0x80800840: beql        $at, $zero, L_80800884
    if (ctx->r1 == 0) {
        // 0x80800844: lwc1        $f8, 0x54($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
            goto L_80800884;
    }
    goto skip_3;
    // 0x80800844: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    skip_3:
    // 0x80800848: sub.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x8080084C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3138, 0XD30) << 16);
    // 0x80800850: lwc1        $f10, 0xD30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3138, 0XD30));
    // 0x80800854: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800858: add.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x8080085C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80800860: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x80800864: nop

    // 0x80800868: sh          $t1, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r9;
    // 0x8080086C: lh          $v0, 0x4($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X4);
    // 0x80800870: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80800874: nop

    // 0x80800878: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8080087C: add.s       $f12, $f2, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f22.fl;
    // 0x80800880: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
L_80800884:
    // 0x80800884: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x80800888: nop

    // 0x8080088C: bc1fl       L_808008D0
    if (!c1cs) {
        // 0x80800890: lw          $a1, 0x60($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X60);
            goto L_808008D0;
    }
    goto skip_4;
    // 0x80800890: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    skip_4:
    // 0x80800894: lh          $t2, 0x6($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X6);
    // 0x80800898: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x8080089C: slt         $at, $t3, $v0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808008A0: beql        $at, $zero, L_808008D0
    if (ctx->r1 == 0) {
        // 0x808008A4: lw          $a1, 0x60($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X60);
            goto L_808008D0;
    }
    goto skip_5;
    // 0x808008A4: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    skip_5:
    // 0x808008A8: sub.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x808008AC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3138, 0XD34) << 16);
    // 0x808008B0: lwc1        $f16, 0xD34($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3138, 0XD34));
    // 0x808008B4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x808008B8: sub.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x808008BC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808008C0: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x808008C4: nop

    // 0x808008C8: sh          $t5, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r13;
    // 0x808008CC: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
L_808008D0:
    // 0x808008D0: jal         0x800F1828
    // 0x808008D4: sw          $a3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r7;
    func_800F1828(rdram, ctx);
        goto after_4;
    // 0x808008D4: sw          $a3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r7;
    after_4:
    // 0x808008D8: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x808008DC: jal         0x80013728
    // 0x808008E0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80013728(rdram, ctx);
        goto after_5;
    // 0x808008E0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_5:
    // 0x808008E4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x808008E8: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x808008EC: jal         0x800F0E7C
    // 0x808008F0: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    func_800F0E7C(rdram, ctx);
        goto after_6;
    // 0x808008F0: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    after_6:
    // 0x808008F4: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x808008F8: lh          $v1, 0xA($a3)
    ctx->r3 = MEM_H(ctx->r7, 0XA);
    // 0x808008FC: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x80800900: nop

    // 0x80800904: cvt.s.w     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    ctx->f2.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800908: add.s       $f10, $f2, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f20.fl;
    // 0x8080090C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80800910: nop

    // 0x80800914: bc1fl       L_808009E8
    if (!c1cs) {
        // 0x80800918: mtc1        $v1, $f18
        ctx->f18.u32l = ctx->r3;
            goto L_808009E8;
    }
    goto skip_6;
    // 0x80800918: mtc1        $v1, $f18
    ctx->f18.u32l = ctx->r3;
    skip_6:
    // 0x8080091C: sub.s       $f16, $f20, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f20.fl - ctx->f2.fl;
    // 0x80800920: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80800924: nop

    // 0x80800928: bc1fl       L_808009E8
    if (!c1cs) {
        // 0x8080092C: mtc1        $v1, $f18
        ctx->f18.u32l = ctx->r3;
            goto L_808009E8;
    }
    goto skip_7;
    // 0x8080092C: mtc1        $v1, $f18
    ctx->f18.u32l = ctx->r3;
    skip_7:
    // 0x80800930: beql        $v1, $zero, L_808009E8
    if (ctx->r3 == 0) {
        // 0x80800934: mtc1        $v1, $f18
        ctx->f18.u32l = ctx->r3;
            goto L_808009E8;
    }
    goto skip_8;
    // 0x80800934: mtc1        $v1, $f18
    ctx->f18.u32l = ctx->r3;
    skip_8:
    // 0x80800938: lh          $v0, 0x8($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X8);
    // 0x8080093C: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x80800940: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80800944: cvt.s.w     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    ctx->f2.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800948: add.s       $f12, $f2, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f20.fl;
    // 0x8080094C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80800950: nop

    // 0x80800954: bc1fl       L_808009A4
    if (!c1cs) {
        // 0x80800958: c.lt.s      $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
            goto L_808009A4;
    }
    goto skip_9;
    // 0x80800958: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    skip_9:
    // 0x8080095C: beql        $at, $zero, L_808009A4
    if (ctx->r1 == 0) {
        // 0x80800960: c.lt.s      $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
            goto L_808009A4;
    }
    goto skip_10;
    // 0x80800960: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    skip_10:
    // 0x80800964: sub.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x80800968: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3138, 0XD38) << 16);
    // 0x8080096C: lwc1        $f6, 0xD38($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3138, 0XD38));
    // 0x80800970: lh          $v1, 0xA($a3)
    ctx->r3 = MEM_H(ctx->r7, 0XA);
    // 0x80800974: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800978: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x8080097C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80800980: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x80800984: nop

    // 0x80800988: sh          $t7, 0x8($a3)
    MEM_H(0X8, ctx->r7) = ctx->r15;
    // 0x8080098C: lh          $v0, 0x8($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X8);
    // 0x80800990: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x80800994: nop

    // 0x80800998: cvt.s.w     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    ctx->f2.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8080099C: add.s       $f12, $f2, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f20.fl;
    // 0x808009A0: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
L_808009A4:
    // 0x808009A4: negu        $t8, $v1
    ctx->r24 = SUB32(0, ctx->r3);
    // 0x808009A8: slt         $at, $t8, $v0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808009AC: bc1fl       L_808009E8
    if (!c1cs) {
        // 0x808009B0: mtc1        $v1, $f18
        ctx->f18.u32l = ctx->r3;
            goto L_808009E8;
    }
    goto skip_11;
    // 0x808009B0: mtc1        $v1, $f18
    ctx->f18.u32l = ctx->r3;
    skip_11:
    // 0x808009B4: beql        $at, $zero, L_808009E8
    if (ctx->r1 == 0) {
        // 0x808009B8: mtc1        $v1, $f18
        ctx->f18.u32l = ctx->r3;
            goto L_808009E8;
    }
    goto skip_12;
    // 0x808009B8: mtc1        $v1, $f18
    ctx->f18.u32l = ctx->r3;
    skip_12:
    // 0x808009BC: sub.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x808009C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3138, 0XD3C) << 16);
    // 0x808009C4: lwc1        $f6, 0xD3C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3138, 0XD3C));
    // 0x808009C8: lh          $v1, 0xA($a3)
    ctx->r3 = MEM_H(ctx->r7, 0XA);
    // 0x808009CC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808009D0: sub.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x808009D4: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x808009D8: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x808009DC: nop

    // 0x808009E0: sh          $t0, 0x8($a3)
    MEM_H(0X8, ctx->r7) = ctx->r8;
    // 0x808009E4: mtc1        $v1, $f18
    ctx->f18.u32l = ctx->r3;
L_808009E8:
    // 0x808009E8: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x808009EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808009F0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x808009F4: mul.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808009F8: add.s       $f8, $f2, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f20.fl;
    // 0x808009FC: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x80800A00: nop

    // 0x80800A04: bc1tl       L_80800A24
    if (c1cs) {
        // 0x80800A08: lh          $t1, 0x8($a3)
        ctx->r9 = MEM_H(ctx->r7, 0X8);
            goto L_80800A24;
    }
    goto skip_13;
    // 0x80800A08: lh          $t1, 0x8($a3)
    ctx->r9 = MEM_H(ctx->r7, 0X8);
    skip_13:
    // 0x80800A0C: sub.s       $f10, $f20, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f20.fl - ctx->f2.fl;
    // 0x80800A10: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x80800A14: nop

    // 0x80800A18: bc1fl       L_80800A50
    if (!c1cs) {
        // 0x80800A1C: lh          $t4, 0x6($a3)
        ctx->r12 = MEM_H(ctx->r7, 0X6);
            goto L_80800A50;
    }
    goto skip_14;
    // 0x80800A1C: lh          $t4, 0x6($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X6);
    skip_14:
    // 0x80800A20: lh          $t1, 0x8($a3)
    ctx->r9 = MEM_H(ctx->r7, 0X8);
L_80800A24:
    // 0x80800A24: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3138, 0XD40) << 16);
    // 0x80800A28: lwc1        $f2, 0xD40($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3138, 0XD40));
    // 0x80800A2C: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x80800A30: nop

    // 0x80800A34: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800A38: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80800A3C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800A40: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x80800A44: nop

    // 0x80800A48: sh          $t3, 0x8($a3)
    MEM_H(0X8, ctx->r7) = ctx->r11;
L_80800A4C:
    // 0x80800A4C: lh          $t4, 0x6($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X6);
L_80800A50:
    // 0x80800A50: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3138, 0XD44) << 16);
    // 0x80800A54: lwc1        $f2, 0xD44($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3138, 0XD44));
    // 0x80800A58: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80800A5C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800A60: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800A64: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800A68: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80800A6C: mul.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800A70: add.s       $f4, $f0, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f22.fl;
    // 0x80800A74: c.le.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl <= ctx->f18.fl;
    // 0x80800A78: nop

    // 0x80800A7C: bc1tl       L_80800A9C
    if (c1cs) {
        // 0x80800A80: lh          $t5, 0x4($a3)
        ctx->r13 = MEM_H(ctx->r7, 0X4);
            goto L_80800A9C;
    }
    goto skip_15;
    // 0x80800A80: lh          $t5, 0x4($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X4);
    skip_15:
    // 0x80800A84: sub.s       $f6, $f22, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f22.fl - ctx->f0.fl;
    // 0x80800A88: c.le.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl <= ctx->f6.fl;
    // 0x80800A8C: nop

    // 0x80800A90: bc1fl       L_80800AD8
    if (!c1cs) {
        // 0x80800A94: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800AD8;
    }
    goto skip_16;
    // 0x80800A94: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_16:
    // 0x80800A98: lh          $t5, 0x4($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X4);
L_80800A9C:
    // 0x80800A9C: lh          $t8, 0x8($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X8);
    // 0x80800AA0: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80800AA4: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80800AA8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800AAC: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800AB0: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80800AB4: nop

    // 0x80800AB8: mul.s       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80800ABC: trunc.w.s   $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800AC0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800AC4: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x80800AC8: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x80800ACC: sh          $t7, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r15;
    // 0x80800AD0: sh          $t0, 0x8($a3)
    MEM_H(0X8, ctx->r7) = ctx->r8;
    // 0x80800AD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800AD8:
    // 0x80800AD8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800ADC: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80800AE0: jr          $ra
    // 0x80800AE4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80800AE4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_8010D1E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010D1E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010D1EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010D1F0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010D1F4: jal         0x8008FE68
    // 0x8010D1F8: addiu       $a0, $a0, 0x6F50
    ctx->r4 = ADD32(ctx->r4, 0X6F50);
    func_8008FE68(rdram, ctx);
        goto after_0;
    // 0x8010D1F8: addiu       $a0, $a0, 0x6F50
    ctx->r4 = ADD32(ctx->r4, 0X6F50);
    after_0:
    // 0x8010D1FC: jal         0x80090128
    // 0x8010D200: nop

    func_80090128(rdram, ctx);
        goto after_1;
    // 0x8010D200: nop

    after_1:
    // 0x8010D204: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010D208: jal         0x80090150
    // 0x8010D20C: sh          $v0, 0x6F5C($at)
    MEM_H(0X6F5C, ctx->r1) = ctx->r2;
    func_80090150(rdram, ctx);
        goto after_2;
    // 0x8010D20C: sh          $v0, 0x6F5C($at)
    MEM_H(0X6F5C, ctx->r1) = ctx->r2;
    after_2:
    // 0x8010D210: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010D214: jal         0x8008FD48
    // 0x8010D218: sh          $v0, 0x6F5E($at)
    MEM_H(0X6F5E, ctx->r1) = ctx->r2;
    func_8008FD48(rdram, ctx);
        goto after_3;
    // 0x8010D218: sh          $v0, 0x6F5E($at)
    MEM_H(0X6F5E, ctx->r1) = ctx->r2;
    after_3:
    // 0x8010D21C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010D220: jal         0x8008FF6C
    // 0x8010D224: sw          $v0, 0x6F60($at)
    MEM_W(0X6F60, ctx->r1) = ctx->r2;
    func_8008FF6C(rdram, ctx);
        goto after_4;
    // 0x8010D224: sw          $v0, 0x6F60($at)
    MEM_W(0X6F60, ctx->r1) = ctx->r2;
    after_4:
    // 0x8010D228: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010D22C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010D230: sw          $v0, 0x6F64($at)
    MEM_W(0X6F64, ctx->r1) = ctx->r2;
    // 0x8010D234: jr          $ra
    // 0x8010D238: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8010D238: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80800030_chgruntyfireball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800030: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800034: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800038: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080003C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800040: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800044: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1488, 0X4C8) << 16);
    // 0x80800048: addiu       $a3, $a3, 0x4C8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1488, 0X4C8));
    // 0x8080004C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80800050: jal         0x80089D50
    // 0x80800054: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800054: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80800058: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x8080005C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800060: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x80800064: beq         $t6, $at, L_8080007C
    if (ctx->r14 == ctx->r1) {
        // 0x80800068: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080007C;
    }
    // 0x80800068: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080006C: beq         $t6, $at, L_8080008C
    if (ctx->r14 == ctx->r1) {
        // 0x80800070: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080008C;
    }
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800074: b           L_808000E4
    // 0x80800078: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
        goto L_808000E4;
    // 0x80800078: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
L_8080007C:
    // 0x8080007C: jal         0x808003D8
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808003D8_chgruntyfireball(rdram, ctx);
        goto after_1;
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800084: b           L_808000E4
    // 0x80800088: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
        goto L_808000E4;
    // 0x80800088: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
L_8080008C:
    // 0x8080008C: lui         $a1, 0x40
    ctx->r5 = S32(0X40 << 16);
    // 0x80800090: jal         0x8010B990
    // 0x80800094: ori         $a1, $a1, 0x7
    ctx->r5 = ctx->r5 | 0X7;
    func_8010B990(rdram, ctx);
        goto after_2;
    // 0x80800094: ori         $a1, $a1, 0x7
    ctx->r5 = ctx->r5 | 0X7;
    after_2:
    // 0x80800098: andi        $t7, $v0, 0x20
    ctx->r15 = ctx->r2 & 0X20;
    // 0x8080009C: beq         $t7, $zero, L_808000D8
    if (ctx->r15 == 0) {
        // 0x808000A0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_808000D8;
    }
    // 0x808000A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808000A4: lui         $a2, 0x3E38
    ctx->r6 = S32(0X3E38 << 16);
    // 0x808000A8: ori         $a2, $a2, 0x51EC
    ctx->r6 = ctx->r6 | 0X51EC;
    // 0x808000AC: jal         0x80018820
    // 0x808000B0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80018820(rdram, ctx);
        goto after_3;
    // 0x808000B0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_3:
    // 0x808000B4: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x808000B8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808000BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808000C0: jal         0x800E15CC
    // 0x808000C4: lui         $a1, 0x41B0
    ctx->r5 = S32(0X41B0 << 16);
    func_800E15CC(rdram, ctx);
        goto after_4;
    // 0x808000C4: lui         $a1, 0x41B0
    ctx->r5 = S32(0X41B0 << 16);
    after_4:
    // 0x808000C8: jal         0x80800260
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800260_chgruntyfireball(rdram, ctx);
        goto after_5;
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808000D0: b           L_808000E4
    // 0x808000D4: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
        goto L_808000E4;
    // 0x808000D4: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
L_808000D8:
    // 0x808000D8: jal         0x808003D8
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808003D8_chgruntyfireball(rdram, ctx);
        goto after_6;
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808000E0: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
L_808000E4:
    // 0x808000E4: beql        $a0, $zero, L_80800120
    if (ctx->r4 == 0) {
        // 0x808000E8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800120;
    }
    goto skip_0;
    // 0x808000E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808000EC: jal         0x800C8CB8
    // 0x808000F0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800C8CB8(rdram, ctx);
        goto after_7;
    // 0x808000F0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_7:
    // 0x808000F4: jal         0x8001210C
    // 0x808000F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001210C(rdram, ctx);
        goto after_8;
    // 0x808000F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
    // 0x808000FC: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80800100: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x80800104: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1488, 0X4E0) << 16);
    // 0x80800108: addiu       $t9, $t9, 0x4E0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(1488, 0X4E0));
    // 0x8080010C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800110: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    // 0x80800114: jal         0x800C8E84
    // 0x80800118: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    func_800C8E84(rdram, ctx);
        goto after_9;
    // 0x80800118: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    after_9:
    // 0x8080011C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800120:
    // 0x80800120: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800124: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800128: jr          $ra
    // 0x8080012C: nop

    return;
    // 0x8080012C: nop

;}
RECOMP_FUNC void ncfixposrot_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000E8: jal         0x800EE7F8
    // 0x808000EC: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808000EC: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_0:
    // 0x808000F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000F8: jr          $ra
    // 0x808000FC: nop

    return;
    // 0x808000FC: nop

;}
RECOMP_FUNC void func_800C2000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2000: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800C2004: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C2008: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C200C: jal         0x800D8FF8
    // 0x800C2010: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x800C2010: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    after_0:
    // 0x800C2014: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x800C2018: jal         0x800C1414
    // 0x800C201C: lbu         $a0, 0x4B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X4B);
    func_800C1414(rdram, ctx);
        goto after_1;
    // 0x800C201C: lbu         $a0, 0x4B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X4B);
    after_1:
    // 0x800C2020: lwc1        $f4, 0x54($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X54);
    // 0x800C2024: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C2028: lw          $v1, 0x78($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X78);
    // 0x800C202C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800C2030: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800C2034: sll         $t7, $v1, 26
    ctx->r15 = S32(ctx->r3 << 26);
    // 0x800C2038: sll         $t5, $v1, 28
    ctx->r13 = S32(ctx->r3 << 28);
    // 0x800C203C: bgez        $t7, L_800C2100
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800C2040: swc1        $f8, 0x54($v0)
        MEM_W(0X54, ctx->r2) = ctx->f8.u32l;
            goto L_800C2100;
    }
    // 0x800C2040: swc1        $f8, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f8.u32l;
    // 0x800C2044: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C2048: lwc1        $f16, 0x44($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X44);
    // 0x800C204C: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x800C2050: nop

    // 0x800C2054: bc1fl       L_800C2068
    if (!c1cs) {
        // 0x800C2058: lh          $t8, 0x4E($s0)
        ctx->r24 = MEM_H(ctx->r16, 0X4E);
            goto L_800C2068;
    }
    goto skip_0;
    // 0x800C2058: lh          $t8, 0x4E($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X4E);
    skip_0:
    // 0x800C205C: b           L_800C20D0
    // 0x800C2060: sh          $zero, 0x5A($v0)
    MEM_H(0X5A, ctx->r2) = 0;
        goto L_800C20D0;
    // 0x800C2060: sh          $zero, 0x5A($v0)
    MEM_H(0X5A, ctx->r2) = 0;
    // 0x800C2064: lh          $t8, 0x4E($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X4E);
L_800C2068:
    // 0x800C2068: lwc1        $f6, 0x44($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X44);
    // 0x800C206C: lh          $t9, 0x5A($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X5A);
    // 0x800C2070: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800C2074: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C2078: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C207C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800C2080: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x800C2084: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800C2088: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800C208C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800C2090: sub.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x800C2094: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800C2098: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x800C209C: nop

    // 0x800C20A0: sh          $t1, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r9;
    // 0x800C20A4: jal         0x800F0E28
    // 0x800C20A8: lh          $a1, 0x5A($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X5A);
    func_800F0E28(rdram, ctx);
        goto after_2;
    // 0x800C20A8: lh          $a1, 0x5A($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X5A);
    after_2:
    // 0x800C20AC: jal         0x800EA05C
    // 0x800C20B0: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
    func_800EA05C(rdram, ctx);
        goto after_3;
    // 0x800C20B0: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
    after_3:
    // 0x800C20B4: lh          $t2, 0x5E($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X5E);
    // 0x800C20B8: beql        $v0, $t2, L_800C20D4
    if (ctx->r2 == ctx->r10) {
        // 0x800C20BC: lh          $t3, 0x5A($s0)
        ctx->r11 = MEM_H(ctx->r16, 0X5A);
            goto L_800C20D4;
    }
    goto skip_1;
    // 0x800C20BC: lh          $t3, 0x5A($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X5A);
    skip_1:
    // 0x800C20C0: lh          $a0, 0x5C($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X5C);
    // 0x800C20C4: jal         0x800F1418
    // 0x800C20C8: lh          $a1, 0x5A($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X5A);
    func_800F1418(rdram, ctx);
        goto after_4;
    // 0x800C20C8: lh          $a1, 0x5A($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X5A);
    after_4:
    // 0x800C20CC: sh          $v0, 0x5C($s0)
    MEM_H(0X5C, ctx->r16) = ctx->r2;
L_800C20D0:
    // 0x800C20D0: lh          $t3, 0x5A($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X5A);
L_800C20D4:
    // 0x800C20D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C20D8: bgtz        $t3, L_800C20F0
    if (SIGNED(ctx->r11) > 0) {
        // 0x800C20DC: nop
    
            goto L_800C20F0;
    }
    // 0x800C20DC: nop

    // 0x800C20E0: jal         0x800C2FDC
    // 0x800C20E4: lbu         $a0, 0x4B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X4B);
    func_800C2FDC(rdram, ctx);
        goto after_5;
    // 0x800C20E4: lbu         $a0, 0x4B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X4B);
    after_5:
    // 0x800C20E8: b           L_800C268C
    // 0x800C20EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800C268C;
    // 0x800C20EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C20F0:
    // 0x800C20F0: jal         0x800C13A0
    // 0x800C20F4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800C13A0(rdram, ctx);
        goto after_6;
    // 0x800C20F4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_6:
    // 0x800C20F8: b           L_800C22BC
    // 0x800C20FC: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
        goto L_800C22BC;
    // 0x800C20FC: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
L_800C2100:
    // 0x800C2100: bgezl       $t5, L_800C22BC
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800C2104: lw          $v0, 0x78($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X78);
            goto L_800C22BC;
    }
    goto skip_2;
    // 0x800C2104: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
    skip_2:
    // 0x800C2108: lwc1        $f0, 0x54($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X54);
    // 0x800C210C: lwc1        $f2, 0x40($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X40);
    // 0x800C2110: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800C2114: nop

    // 0x800C2118: bc1fl       L_800C2160
    if (!c1cs) {
        // 0x800C211C: lwc1        $f12, 0x48($v0)
        ctx->f12.u32l = MEM_W(ctx->r2, 0X48);
            goto L_800C2160;
    }
    goto skip_3;
    // 0x800C211C: lwc1        $f12, 0x48($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X48);
    skip_3:
    // 0x800C2120: div.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C2124: lh          $t6, 0x4C($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4C);
    // 0x800C2128: lh          $t7, 0x4E($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4E);
    // 0x800C212C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800C2130: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C2134: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800C2138: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800C213C: nop

    // 0x800C2140: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800C2144: mul.s       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800C2148: div.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800C214C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800C2150: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x800C2154: b           L_800C2288
    // 0x800C2158: sh          $t0, 0x5A($v0)
    MEM_H(0X5A, ctx->r2) = ctx->r8;
        goto L_800C2288;
    // 0x800C2158: sh          $t0, 0x5A($v0)
    MEM_H(0X5A, ctx->r2) = ctx->r8;
    // 0x800C215C: lwc1        $f12, 0x48($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X48);
L_800C2160:
    // 0x800C2160: add.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x800C2164: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x800C2168: nop

    // 0x800C216C: bc1fl       L_800C223C
    if (!c1cs) {
        // 0x800C2170: sub.s       $f18, $f0, $f2
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800C223C;
    }
    goto skip_4;
    // 0x800C2170: sub.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f2.fl;
    skip_4:
    // 0x800C2174: lh          $a0, 0x5A($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X5A);
    // 0x800C2178: lh          $v1, 0x4C($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4C);
    // 0x800C217C: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800C2180: bnel        $at, $zero, L_800C219C
    if (ctx->r1 != 0) {
        // 0x800C2184: lh          $t2, 0x4E($v0)
        ctx->r10 = MEM_H(ctx->r2, 0X4E);
            goto L_800C219C;
    }
    goto skip_5;
    // 0x800C2184: lh          $t2, 0x4E($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X4E);
    skip_5:
    // 0x800C2188: lh          $t1, 0x4E($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X4E);
    // 0x800C218C: slt         $at, $t1, $a0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800C2190: beql        $at, $zero, L_800C21B8
    if (ctx->r1 == 0) {
        // 0x800C2194: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_800C21B8;
    }
    goto skip_6;
    // 0x800C2194: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    skip_6:
    // 0x800C2198: lh          $t2, 0x4E($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X4E);
L_800C219C:
    // 0x800C219C: addu        $t3, $v1, $t2
    ctx->r11 = ADD32(ctx->r3, ctx->r10);
    // 0x800C21A0: bgez        $t3, L_800C21B0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800C21A4: sra         $t4, $t3, 1
        ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
            goto L_800C21B0;
    }
    // 0x800C21A4: sra         $t4, $t3, 1
    ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
    // 0x800C21A8: addiu       $at, $t3, 0x1
    ctx->r1 = ADD32(ctx->r11, 0X1);
    // 0x800C21AC: sra         $t4, $at, 1
    ctx->r12 = S32(SIGNED(ctx->r1) >> 1);
L_800C21B0:
    // 0x800C21B0: sh          $t4, 0x5A($v0)
    MEM_H(0X5A, ctx->r2) = ctx->r12;
    // 0x800C21B4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
L_800C21B8:
    // 0x800C21B8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800C21BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C21C0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800C21C4: jal         0x800DC264
    // 0x800C21C8: nop

    func_800DC264(rdram, ctx);
        goto after_7;
    // 0x800C21C8: nop

    after_7:
    // 0x800C21CC: lh          $t5, 0x5A($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X5A);
    // 0x800C21D0: lwc1        $f6, 0x50($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800C21D4: lh          $v1, 0x4E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4E);
    // 0x800C21D8: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x800C21DC: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800C21E0: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800C21E4: add.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800C21E8: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800C21EC: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x800C21F0: nop

    // 0x800C21F4: sh          $t7, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r15;
    // 0x800C21F8: lh          $v0, 0x5A($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X5A);
    // 0x800C21FC: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800C2200: beql        $at, $zero, L_800C2214
    if (ctx->r1 == 0) {
        // 0x800C2204: sh          $v0, 0x5A($s0)
        MEM_H(0X5A, ctx->r16) = ctx->r2;
            goto L_800C2214;
    }
    goto skip_7;
    // 0x800C2204: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
    skip_7:
    // 0x800C2208: b           L_800C2214
    // 0x800C220C: sh          $v1, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r3;
        goto L_800C2214;
    // 0x800C220C: sh          $v1, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r3;
    // 0x800C2210: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
L_800C2214:
    // 0x800C2214: lh          $v0, 0x5A($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X5A);
    // 0x800C2218: lh          $v1, 0x4C($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4C);
    // 0x800C221C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800C2220: beq         $at, $zero, L_800C2230
    if (ctx->r1 == 0) {
        // 0x800C2224: nop
    
            goto L_800C2230;
    }
    // 0x800C2224: nop

    // 0x800C2228: b           L_800C2288
    // 0x800C222C: sh          $v1, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r3;
        goto L_800C2288;
    // 0x800C222C: sh          $v1, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r3;
L_800C2230:
    // 0x800C2230: b           L_800C2288
    // 0x800C2234: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
        goto L_800C2288;
    // 0x800C2234: sh          $v0, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r2;
    // 0x800C2238: sub.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f2.fl;
L_800C223C:
    // 0x800C223C: lwc1        $f16, 0x44($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X44);
    // 0x800C2240: lh          $t8, 0x4C($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4C);
    // 0x800C2244: lh          $t9, 0x4E($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X4E);
    // 0x800C2248: sub.s       $f6, $f18, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f12.fl;
    // 0x800C224C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C2250: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800C2254: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x800C2258: div.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800C225C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C2260: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800C2264: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800C2268: sub.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800C226C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C2270: mul.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800C2274: div.s       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = DIV_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800C2278: trunc.w.s   $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800C227C: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x800C2280: nop

    // 0x800C2284: sh          $t2, 0x5A($v0)
    MEM_H(0X5A, ctx->r2) = ctx->r10;
L_800C2288:
    // 0x800C2288: jal         0x800EA05C
    // 0x800C228C: nop

    func_800EA05C(rdram, ctx);
        goto after_8;
    // 0x800C228C: nop

    after_8:
    // 0x800C2290: lh          $t3, 0x5E($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X5E);
    // 0x800C2294: beql        $v0, $t3, L_800C22B0
    if (ctx->r2 == ctx->r11) {
        // 0x800C2298: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800C22B0;
    }
    goto skip_8;
    // 0x800C2298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_8:
    // 0x800C229C: lh          $a0, 0x5C($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X5C);
    // 0x800C22A0: jal         0x800F1418
    // 0x800C22A4: lh          $a1, 0x5A($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X5A);
    func_800F1418(rdram, ctx);
        goto after_9;
    // 0x800C22A4: lh          $a1, 0x5A($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X5A);
    after_9:
    // 0x800C22A8: sh          $v0, 0x5C($s0)
    MEM_H(0X5C, ctx->r16) = ctx->r2;
    // 0x800C22AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800C22B0:
    // 0x800C22B0: jal         0x800C13A0
    // 0x800C22B4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800C13A0(rdram, ctx);
        goto after_10;
    // 0x800C22B4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_10:
    // 0x800C22B8: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
L_800C22BC:
    // 0x800C22BC: sll         $t5, $v0, 27
    ctx->r13 = S32(ctx->r2 << 27);
    // 0x800C22C0: bgezl       $t5, L_800C2318
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800C22C4: lbu         $v0, 0x79($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X79);
            goto L_800C2318;
    }
    goto skip_9;
    // 0x800C22C4: lbu         $v0, 0x79($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X79);
    skip_9:
    // 0x800C22C8: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x800C22CC: lwc1        $f16, 0x48($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
    // 0x800C22D0: lwc1        $f8, 0x44($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X44);
    // 0x800C22D4: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800C22D8: add.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800C22DC: sll         $t7, $v0, 30
    ctx->r15 = S32(ctx->r2 << 30);
    // 0x800C22E0: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800C22E4: c.le.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl <= ctx->f4.fl;
    // 0x800C22E8: nop

    // 0x800C22EC: bc1fl       L_800C2318
    if (!c1cs) {
        // 0x800C22F0: lbu         $v0, 0x79($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X79);
            goto L_800C2318;
    }
    goto skip_10;
    // 0x800C22F0: lbu         $v0, 0x79($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X79);
    skip_10:
    // 0x800C22F4: bgez        $t7, L_800C230C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800C22F8: nop
    
            goto L_800C230C;
    }
    // 0x800C22F8: nop

    // 0x800C22FC: jal         0x800C2FDC
    // 0x800C2300: lbu         $a0, 0x4B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X4B);
    func_800C2FDC(rdram, ctx);
        goto after_11;
    // 0x800C2300: lbu         $a0, 0x4B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X4B);
    after_11:
    // 0x800C2304: b           L_800C268C
    // 0x800C2308: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800C268C;
    // 0x800C2308: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C230C:
    // 0x800C230C: jal         0x800C1860
    // 0x800C2310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C1860(rdram, ctx);
        goto after_12;
    // 0x800C2310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x800C2314: lbu         $v0, 0x79($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X79);
L_800C2318:
    // 0x800C2318: beql        $v0, $zero, L_800C24EC
    if (ctx->r2 == 0) {
        // 0x800C231C: lhu         $v0, 0x7A($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X7A);
            goto L_800C24EC;
    }
    goto skip_11;
    // 0x800C231C: lhu         $v0, 0x7A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X7A);
    skip_11:
    // 0x800C2320: lw          $t8, 0x78($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X78);
    // 0x800C2324: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C2328: sll         $t9, $t8, 19
    ctx->r25 = S32(ctx->r24 << 19);
    // 0x800C232C: srl         $t0, $t9, 29
    ctx->r8 = S32(U32(ctx->r25) >> 29);
    // 0x800C2330: bnel        $t0, $at, L_800C24EC
    if (ctx->r8 != ctx->r1) {
        // 0x800C2334: lhu         $v0, 0x7A($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X7A);
            goto L_800C24EC;
    }
    goto skip_12;
    // 0x800C2334: lhu         $v0, 0x7A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X7A);
    skip_12:
    // 0x800C2338: jal         0x800C1448
    // 0x800C233C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800C1448(rdram, ctx);
        goto after_13;
    // 0x800C233C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_13:
    // 0x800C2340: beql        $v0, $zero, L_800C24EC
    if (ctx->r2 == 0) {
        // 0x800C2344: lhu         $v0, 0x7A($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X7A);
            goto L_800C24EC;
    }
    goto skip_13;
    // 0x800C2344: lhu         $v0, 0x7A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X7A);
    skip_13:
    // 0x800C2348: lw          $t1, 0x78($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X78);
    // 0x800C234C: sll         $t2, $t1, 22
    ctx->r10 = S32(ctx->r9 << 22);
    // 0x800C2350: srl         $t3, $t2, 28
    ctx->r11 = S32(U32(ctx->r10) >> 28);
    // 0x800C2354: sltiu       $at, $t3, 0x5
    ctx->r1 = ctx->r11 < 0X5 ? 1 : 0;
    // 0x800C2358: beq         $at, $zero, L_800C24E8
    if (ctx->r1 == 0) {
        // 0x800C235C: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_800C24E8;
    }
    // 0x800C235C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800C2360: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C2364: addu        $at, $at, $t3
    gpr jr_addend_800C236C = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800C2368: lw          $t3, 0x57DC($at)
    ctx->r11 = ADD32(ctx->r1, 0X57DC);
    // 0x800C236C: jr          $t3
    // 0x800C2370: nop

    switch (jr_addend_800C236C >> 2) {
        case 0: goto L_800C24E8; break;
        case 1: goto L_800C2374; break;
        case 2: goto L_800C23D0; break;
        case 3: goto L_800C2418; break;
        case 4: goto L_800C244C; break;
        default: switch_error(__func__, 0x800C236C, 0x801257DC);
    }
    // 0x800C2370: nop

L_800C2374:
    // 0x800C2374: lwc1        $f0, 0x28($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800C2378: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C237C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C2380: lwc1        $f6, 0x6C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x800C2384: mul.s       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800C2388: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800C238C: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800C2390: bc1f        L_800C23AC
    if (!c1cs) {
        // 0x800C2394: swc1        $f8, 0x6C($s0)
        MEM_W(0X6C, ctx->r16) = ctx->f8.u32l;
            goto L_800C23AC;
    }
    // 0x800C2394: swc1        $f8, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f8.u32l;
    // 0x800C2398: lwc1        $f12, 0x6C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x800C239C: jal         0x800F13F0
    // 0x800C23A0: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
    func_800F13F0(rdram, ctx);
        goto after_14;
    // 0x800C23A0: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
    after_14:
    // 0x800C23A4: b           L_800C23BC
    // 0x800C23A8: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
        goto L_800C23BC;
    // 0x800C23A8: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
L_800C23AC:
    // 0x800C23AC: lwc1        $f12, 0x6C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x800C23B0: jal         0x800F0E00
    // 0x800C23B4: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
    func_800F0E00(rdram, ctx);
        goto after_15;
    // 0x800C23B4: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
    after_15:
    // 0x800C23B8: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
L_800C23BC:
    // 0x800C23BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C23C0: jal         0x800C13A0
    // 0x800C23C4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800C13A0(rdram, ctx);
        goto after_16;
    // 0x800C23C4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_16:
    // 0x800C23C8: b           L_800C24EC
    // 0x800C23CC: lhu         $v0, 0x7A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X7A);
        goto L_800C24EC;
    // 0x800C23CC: lhu         $v0, 0x7A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X7A);
L_800C23D0:
    // 0x800C23D0: lwc1        $f14, 0x30($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X30);
    // 0x800C23D4: jal         0x800DC264
    // 0x800C23D8: neg.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = -ctx->f14.fl;
    func_800DC264(rdram, ctx);
        goto after_17;
    // 0x800C23D8: neg.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = -ctx->f14.fl;
    after_17:
    // 0x800C23DC: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C23E0: lwc1        $f18, 0x6C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x800C23E4: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800C23E8: mul.s       $f6, $f0, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800C23EC: lw          $a2, 0x28($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X28);
    // 0x800C23F0: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800C23F4: swc1        $f10, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f10.u32l;
    // 0x800C23F8: jal         0x800F0D50
    // 0x800C23FC: lwc1        $f12, 0x6C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X6C);
    func_800F0D50(rdram, ctx);
        goto after_18;
    // 0x800C23FC: lwc1        $f12, 0x6C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X6C);
    after_18:
    // 0x800C2400: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    // 0x800C2404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C2408: jal         0x800C13A0
    // 0x800C240C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800C13A0(rdram, ctx);
        goto after_19;
    // 0x800C240C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_19:
    // 0x800C2410: b           L_800C24EC
    // 0x800C2414: lhu         $v0, 0x7A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X7A);
        goto L_800C24EC;
    // 0x800C2414: lhu         $v0, 0x7A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X7A);
L_800C2418:
    // 0x800C2418: lwc1        $f8, 0x34($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X34);
    // 0x800C241C: lwc1        $f12, 0x54($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800C2420: lwc1        $f14, 0x28($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800C2424: lw          $a2, 0x2C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X2C);
    // 0x800C2428: lw          $a3, 0x30($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X30);
    // 0x800C242C: jal         0x800F10B4
    // 0x800C2430: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_20;
    // 0x800C2430: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_20:
    // 0x800C2434: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    // 0x800C2438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C243C: jal         0x800C13A0
    // 0x800C2440: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800C13A0(rdram, ctx);
        goto after_21;
    // 0x800C2440: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_21:
    // 0x800C2444: b           L_800C24EC
    // 0x800C2448: lhu         $v0, 0x7A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X7A);
        goto L_800C24EC;
    // 0x800C2448: lhu         $v0, 0x7A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X7A);
L_800C244C:
    // 0x800C244C: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800C2450: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x800C2454: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800C2458: lwc1        $f0, 0x28($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800C245C: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x800C2460: nop

    // 0x800C2464: bc1fl       L_800C2494
    if (!c1cs) {
        // 0x800C2468: lwc1        $f6, 0x2C($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
            goto L_800C2494;
    }
    goto skip_14;
    // 0x800C2468: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    skip_14:
    // 0x800C246C: lwc1        $f18, 0x38($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X38);
    // 0x800C2470: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800C2474: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800C2478: lw          $a3, 0x34($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X34);
    // 0x800C247C: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
    // 0x800C2480: jal         0x800F10B4
    // 0x800C2484: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F10B4(rdram, ctx);
        goto after_22;
    // 0x800C2484: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_22:
    // 0x800C2488: b           L_800C24DC
    // 0x800C248C: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
        goto L_800C24DC;
    // 0x800C248C: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    // 0x800C2490: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
L_800C2494:
    // 0x800C2494: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800C2498: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800C249C: add.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x800C24A0: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x800C24A4: nop

    // 0x800C24A8: bc1fl       L_800C24C0
    if (!c1cs) {
        // 0x800C24AC: lwc1        $f16, 0x3C($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
            goto L_800C24C0;
    }
    goto skip_15;
    // 0x800C24AC: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
    skip_15:
    // 0x800C24B0: lwc1        $f8, 0x38($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X38);
    // 0x800C24B4: b           L_800C24DC
    // 0x800C24B8: swc1        $f8, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f8.u32l;
        goto L_800C24DC;
    // 0x800C24B8: swc1        $f8, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f8.u32l;
    // 0x800C24BC: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
L_800C24C0:
    // 0x800C24C0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800C24C4: lw          $a2, 0x30($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X30);
    // 0x800C24C8: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x800C24CC: sub.s       $f12, $f4, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x800C24D0: jal         0x800F10B4
    // 0x800C24D4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F10B4(rdram, ctx);
        goto after_23;
    // 0x800C24D4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_23:
    // 0x800C24D8: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
L_800C24DC:
    // 0x800C24DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C24E0: jal         0x800C13A0
    // 0x800C24E4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800C13A0(rdram, ctx);
        goto after_24;
    // 0x800C24E4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_24:
L_800C24E8:
    // 0x800C24E8: lhu         $v0, 0x7A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X7A);
L_800C24EC:
    // 0x800C24EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C24F0: srl         $t4, $v0, 13
    ctx->r12 = S32(U32(ctx->r2) >> 13);
    // 0x800C24F4: beq         $t4, $at, L_800C2514
    if (ctx->r12 == ctx->r1) {
        // 0x800C24F8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800C2514;
    }
    // 0x800C24F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C24FC: beq         $t4, $at, L_800C2550
    if (ctx->r12 == ctx->r1) {
        // 0x800C2500: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800C2550;
    }
    // 0x800C2500: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800C2504: beq         $t4, $at, L_800C2598
    if (ctx->r12 == ctx->r1) {
        // 0x800C2508: nop
    
            goto L_800C2598;
    }
    // 0x800C2508: nop

    // 0x800C250C: b           L_800C2598
    // 0x800C2510: nop

        goto L_800C2598;
    // 0x800C2510: nop

L_800C2514:
    // 0x800C2514: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
    // 0x800C2518: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C251C: sll         $t5, $v0, 19
    ctx->r13 = S32(ctx->r2 << 19);
    // 0x800C2520: srl         $t6, $t5, 29
    ctx->r14 = S32(U32(ctx->r13) >> 29);
    // 0x800C2524: beq         $t6, $zero, L_800C2540
    if (ctx->r14 == 0) {
        // 0x800C2528: nop
    
            goto L_800C2540;
    }
    // 0x800C2528: nop

    // 0x800C252C: bne         $t6, $at, L_800C2598
    if (ctx->r14 != ctx->r1) {
        // 0x800C2530: nop
    
            goto L_800C2598;
    }
    // 0x800C2530: nop

    // 0x800C2534: lbu         $t7, 0x79($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X79);
    // 0x800C2538: bne         $t7, $zero, L_800C2598
    if (ctx->r15 != 0) {
        // 0x800C253C: nop
    
            goto L_800C2598;
    }
    // 0x800C253C: nop

L_800C2540:
    // 0x800C2540: jal         0x800C2FDC
    // 0x800C2544: lbu         $a0, 0x4B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X4B);
    func_800C2FDC(rdram, ctx);
        goto after_25;
    // 0x800C2544: lbu         $a0, 0x4B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X4B);
    after_25:
    // 0x800C2548: b           L_800C268C
    // 0x800C254C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800C268C;
    // 0x800C254C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C2550:
    // 0x800C2550: lw          $t8, 0x78($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X78);
    // 0x800C2554: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C2558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C255C: sll         $t9, $t8, 19
    ctx->r25 = S32(ctx->r24 << 19);
    // 0x800C2560: srl         $t0, $t9, 29
    ctx->r8 = S32(U32(ctx->r25) >> 29);
    // 0x800C2564: bnel        $t0, $at, L_800C2590
    if (ctx->r8 != ctx->r1) {
        // 0x800C2568: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800C2590;
    }
    goto skip_16;
    // 0x800C2568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_16:
    // 0x800C256C: jal         0x800C13D0
    // 0x800C2570: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C13D0(rdram, ctx);
        goto after_26;
    // 0x800C2570: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_26:
    // 0x800C2574: beql        $v0, $zero, L_800C2590
    if (ctx->r2 == 0) {
        // 0x800C2578: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800C2590;
    }
    goto skip_17;
    // 0x800C2578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_17:
    // 0x800C257C: jal         0x800C3CE8
    // 0x800C2580: lbu         $a0, 0x4B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X4B);
    func_800C3CE8(rdram, ctx);
        goto after_27;
    // 0x800C2580: lbu         $a0, 0x4B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X4B);
    after_27:
    // 0x800C2584: b           L_800C2598
    // 0x800C2588: nop

        goto L_800C2598;
    // 0x800C2588: nop

    // 0x800C258C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800C2590:
    // 0x800C2590: jal         0x800C13B0
    // 0x800C2594: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C13B0(rdram, ctx);
        goto after_28;
    // 0x800C2594: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_28:
L_800C2598:
    // 0x800C2598: jal         0x800C1D80
    // 0x800C259C: lbu         $a0, 0x4B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X4B);
    func_800C1D80(rdram, ctx);
        goto after_29;
    // 0x800C259C: lbu         $a0, 0x4B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X4B);
    after_29:
    // 0x800C25A0: lw          $t1, 0x78($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X78);
    // 0x800C25A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C25A8: sll         $t2, $t1, 19
    ctx->r10 = S32(ctx->r9 << 19);
    // 0x800C25AC: srl         $t3, $t2, 29
    ctx->r11 = S32(U32(ctx->r10) >> 29);
    // 0x800C25B0: bnel        $t3, $at, L_800C2664
    if (ctx->r11 != ctx->r1) {
        // 0x800C25B4: lbu         $v0, 0x79($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X79);
            goto L_800C2664;
    }
    goto skip_18;
    // 0x800C25B4: lbu         $v0, 0x79($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X79);
    skip_18:
    // 0x800C25B8: lh          $a0, 0x58($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X58);
    // 0x800C25BC: jal         0x800C42E0
    // 0x800C25C0: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    func_800C42E0(rdram, ctx);
        goto after_30;
    // 0x800C25C0: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    after_30:
    // 0x800C25C4: beq         $v0, $zero, L_800C2660
    if (ctx->r2 == 0) {
        // 0x800C25C8: lw          $v1, 0x40($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X40);
            goto L_800C2660;
    }
    // 0x800C25C8: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x800C25CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C25D0: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x800C25D4: jal         0x800C13C4
    // 0x800C25D8: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    func_800C13C4(rdram, ctx);
        goto after_31;
    // 0x800C25D8: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_31:
    // 0x800C25DC: beq         $v0, $zero, L_800C2638
    if (ctx->r2 == 0) {
        // 0x800C25E0: lw          $v1, 0x40($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X40);
            goto L_800C2638;
    }
    // 0x800C25E0: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x800C25E4: bnel        $v1, $zero, L_800C2664
    if (ctx->r3 != 0) {
        // 0x800C25E8: lbu         $v0, 0x79($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X79);
            goto L_800C2664;
    }
    goto skip_19;
    // 0x800C25E8: lbu         $v0, 0x79($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X79);
    skip_19:
    // 0x800C25EC: jal         0x800C15BC
    // 0x800C25F0: nop

    func_800C15BC(rdram, ctx);
        goto after_32;
    // 0x800C25F0: nop

    after_32:
    // 0x800C25F4: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800C25F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C25FC: jal         0x8002EC20
    // 0x800C2600: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    osSetThreadPri_recomp(rdram, ctx);
        goto after_33;
    // 0x800C2600: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    after_33:
    // 0x800C2604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C2608: jal         0x800C16F8
    // 0x800C260C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    func_800C16F8(rdram, ctx);
        goto after_34;
    // 0x800C260C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_34:
    // 0x800C2610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C2614: jal         0x800C13B0
    // 0x800C2618: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_800C13B0(rdram, ctx);
        goto after_35;
    // 0x800C2618: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_35:
    // 0x800C261C: jal         0x800C1D80
    // 0x800C2620: lbu         $a0, 0x4B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X4B);
    func_800C1D80(rdram, ctx);
        goto after_36;
    // 0x800C2620: lbu         $a0, 0x4B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X4B);
    after_36:
    // 0x800C2624: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800C2628: jal         0x8002EC20
    // 0x800C262C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    osSetThreadPri_recomp(rdram, ctx);
        goto after_37;
    // 0x800C262C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_37:
    // 0x800C2630: b           L_800C2664
    // 0x800C2634: lbu         $v0, 0x79($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X79);
        goto L_800C2664;
    // 0x800C2634: lbu         $v0, 0x79($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X79);
L_800C2638:
    // 0x800C2638: beql        $v1, $zero, L_800C2664
    if (ctx->r3 == 0) {
        // 0x800C263C: lbu         $v0, 0x79($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X79);
            goto L_800C2664;
    }
    goto skip_20;
    // 0x800C263C: lbu         $v0, 0x79($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X79);
    skip_20:
    // 0x800C2640: jal         0x800C1860
    // 0x800C2644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C1860(rdram, ctx);
        goto after_38;
    // 0x800C2644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_38:
    // 0x800C2648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C264C: jal         0x800C1210
    // 0x800C2650: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C1210(rdram, ctx);
        goto after_39;
    // 0x800C2650: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_39:
    // 0x800C2654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C2658: jal         0x800C13A0
    // 0x800C265C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_800C13A0(rdram, ctx);
        goto after_40;
    // 0x800C265C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_40:
L_800C2660:
    // 0x800C2660: lbu         $v0, 0x79($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X79);
L_800C2664:
    // 0x800C2664: beql        $v0, $zero, L_800C268C
    if (ctx->r2 == 0) {
        // 0x800C2668: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800C268C;
    }
    goto skip_21;
    // 0x800C2668: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_21:
    // 0x800C266C: jal         0x800C1448
    // 0x800C2670: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800C1448(rdram, ctx);
        goto after_41;
    // 0x800C2670: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_41:
    // 0x800C2674: bnel        $v0, $zero, L_800C268C
    if (ctx->r2 != 0) {
        // 0x800C2678: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800C268C;
    }
    goto skip_22;
    // 0x800C2678: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_22:
    // 0x800C267C: jal         0x800C1568
    // 0x800C2680: lbu         $a0, 0x79($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X79);
    func_800C1568(rdram, ctx);
        goto after_42;
    // 0x800C2680: lbu         $a0, 0x79($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X79);
    after_42:
    // 0x800C2684: sb          $zero, 0x79($s0)
    MEM_B(0X79, ctx->r16) = 0;
    // 0x800C2688: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C268C:
    // 0x800C268C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C2690: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800C2694: jr          $ra
    // 0x800C2698: nop

    return;
    // 0x800C2698: nop

;}
RECOMP_FUNC void func_80800130_chfactorydrums(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800130: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x80800134: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80800138: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x8080013C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80800140: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80800144: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80800148: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8080014C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80800150: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80800154: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80800158: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8080015C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800160: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800164: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x80800168: addiu       $a0, $zero, 0x3F0
    ctx->r4 = ADD32(0, 0X3F0);
    // 0x8080016C: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    // 0x80800170: jal         0x80089C40
    // 0x80800174: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    _subaddiefind_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800174: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_0:
    // 0x80800178: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
    // 0x8080017C: blez        $v0, L_80800280
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800180: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80800280;
    }
    // 0x80800180: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80800184: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800188: addiu       $s1, $sp, 0x88
    ctx->r17 = ADD32(ctx->r29, 0X88);
    // 0x8080018C: addiu       $s5, $sp, 0x64
    ctx->r21 = ADD32(ctx->r29, 0X64);
    // 0x80800190: addiu       $s4, $sp, 0x58
    ctx->r20 = ADD32(ctx->r29, 0X58);
    // 0x80800194: addiu       $s3, $sp, 0x70
    ctx->r19 = ADD32(ctx->r29, 0X70);
L_80800198:
    // 0x80800198: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8080019C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808001A0: lhu         $v1, 0x72($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X72);
    // 0x808001A4: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x808001A8: beq         $t6, $at, L_808001B8
    if (ctx->r14 == ctx->r1) {
        // 0x808001AC: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_808001B8;
    }
    // 0x808001AC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808001B0: bnel        $t6, $at, L_80800274
    if (ctx->r14 != ctx->r1) {
        // 0x808001B4: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80800274;
    }
    goto skip_0;
    // 0x808001B4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
L_808001B8:
    // 0x808001B8: beql        $s7, $v0, L_80800274
    if (ctx->r23 == ctx->r2) {
        // 0x808001BC: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80800274;
    }
    goto skip_1;
    // 0x808001BC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_1:
    // 0x808001C0: jal         0x800F54E4
    // 0x808001C4: addiu       $s0, $s7, 0x4
    ctx->r16 = ADD32(ctx->r23, 0X4);
    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x808001C4: addiu       $s0, $s7, 0x4
    ctx->r16 = ADD32(ctx->r23, 0X4);
    after_1:
    // 0x808001C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001CC: jal         0x800F5A00
    // 0x808001D0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800F5A00(rdram, ctx);
        goto after_2;
    // 0x808001D0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_2:
    // 0x808001D4: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x808001D8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808001DC: jal         0x800EE7F8
    // 0x808001E0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x808001E0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_3:
    // 0x808001E4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808001E8: jal         0x800EE7F8
    // 0x808001EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x808001EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x808001F0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808001F4: jal         0x800EF3DC
    // 0x808001F8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EF3DC(rdram, ctx);
        goto after_5;
    // 0x808001F8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_5:
    // 0x808001FC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800200: jal         0x800EF3DC
    // 0x80800204: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EF3DC(rdram, ctx);
        goto after_6;
    // 0x80800204: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_6:
    // 0x80800208: jal         0x800EF2A0
    // 0x8080020C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800EF2A0(rdram, ctx);
        goto after_7;
    // 0x8080020C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_7:
    // 0x80800210: jal         0x800EF2A0
    // 0x80800214: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800EF2A0(rdram, ctx);
        goto after_8;
    // 0x80800214: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_8:
    // 0x80800218: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8080021C: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80800220: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80800224: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80800228: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8080022C: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80800230: or          $t7, $zero, $zero
    ctx->r15 = 0 | 0;
    // 0x80800234: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800238: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8080023C: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80800240: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80800244: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80800248: c.le.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl <= ctx->f20.fl;
    // 0x8080024C: nop

    // 0x80800250: bc1fl       L_80800260
    if (!c1cs) {
        // 0x80800254: and         $s6, $s6, $t7
        ctx->r22 = ctx->r22 & ctx->r15;
            goto L_80800260;
    }
    goto skip_2;
    // 0x80800254: and         $s6, $s6, $t7
    ctx->r22 = ctx->r22 & ctx->r15;
    skip_2:
    // 0x80800258: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8080025C: and         $s6, $s6, $t7
    ctx->r22 = ctx->r22 & ctx->r15;
L_80800260:
    // 0x80800260: bnel        $s6, $zero, L_80800274
    if (ctx->r22 != 0) {
        // 0x80800264: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80800274;
    }
    goto skip_3;
    // 0x80800264: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_3:
    // 0x80800268: b           L_80800284
    // 0x8080026C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800284;
    // 0x8080026C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800270: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80800274:
    // 0x80800274: slt         $at, $s2, $fp
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r30) ? 1 : 0;
    // 0x80800278: bne         $at, $zero, L_80800198
    if (ctx->r1 != 0) {
        // 0x8080027C: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80800198;
    }
    // 0x8080027C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80800280:
    // 0x80800280: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
L_80800284:
    // 0x80800284: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80800288: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8080028C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800290: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80800294: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80800298: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8080029C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x808002A0: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x808002A4: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x808002A8: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x808002AC: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x808002B0: jr          $ra
    // 0x808002B4: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x808002B4: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_8080261C_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080261C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802620: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802624: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80802628: jal         0x800A3280
    // 0x8080262C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800A3280(rdram, ctx);
        goto after_0;
    // 0x8080262C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80802630: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80802634: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x80802638: lui         $t7, 0x8081
    ctx->r15 = S32(RELOC_HI16(439, 0XB208) << 16);
    // 0x8080263C: addiu       $t7, $t7, -0x4DF8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(439, 0XB208));
    // 0x80802640: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x80802644: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80802648: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8080264C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80802650: lui         $t0, 0x8081
    ctx->r8 = S32(RELOC_HI16(439, 0XB230) << 16);
    // 0x80802654: addiu       $t0, $t0, -0x4DD0
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(439, 0XB230));
    // 0x80802658: addu        $t1, $t6, $t0
    ctx->r9 = ADD32(ctx->r14, ctx->r8);
    // 0x8080265C: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80802660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802664: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802668: jr          $ra
    // 0x8080266C: nop

    return;
    // 0x8080266C: nop

;}
RECOMP_FUNC void bsjump_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006D8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808006DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808006E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808006E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808006E8: jal         0x8008CABC
    // 0x808006EC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808006EC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_0:
    // 0x808006F0: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x808006F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006F8: jal         0x80095738
    // 0x808006FC: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    baflag_isTrue(rdram, ctx);
        goto after_1;
    // 0x808006FC: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_1:
    // 0x80800700: beq         $v0, $zero, L_80800718
    if (ctx->r2 == 0) {
        // 0x80800704: nop
    
            goto L_80800718;
    }
    // 0x80800704: nop

    // 0x80800708: jal         0x8009B7C0
    // 0x8080070C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009B7C0(rdram, ctx);
        goto after_2;
    // 0x8080070C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800710: b           L_80800724
    // 0x80800714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800724;
    // 0x80800714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800718:
    // 0x80800718: jal         0x800841D8
    // 0x8080071C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bswalk_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x8080071C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800724:
    // 0x80800724: jal         0x8009BB24
    // 0x80800728: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009BB24(rdram, ctx);
        goto after_4;
    // 0x80800728: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x8080072C: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    // 0x80800730: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800738: beq         $v0, $zero, L_80800750
    if (ctx->r2 == 0) {
        // 0x8080073C: nop
    
            goto L_80800750;
    }
    // 0x8080073C: nop

    // 0x80800740: beql        $v0, $at, L_808007B0
    if (ctx->r2 == ctx->r1) {
        // 0x80800744: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007B0;
    }
    goto skip_0;
    // 0x80800744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800748: b           L_808007B0
    // 0x8080074C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808007B0;
    // 0x8080074C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800750:
    // 0x80800750: jal         0x8008DF8C
    // 0x80800754: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    func_8008DF8C(rdram, ctx);
        goto after_5;
    // 0x80800754: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_5:
    // 0x80800758: beql        $v0, $zero, L_808007B0
    if (ctx->r2 == 0) {
        // 0x8080075C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007B0;
    }
    goto skip_1;
    // 0x8080075C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80800760: jal         0x8008AF24
    // 0x80800764: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_reset(rdram, ctx);
        goto after_6;
    // 0x80800764: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_6:
    // 0x80800768: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8080076C: jal         0x8008AED4
    // 0x80800770: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    anctrl_setIndex(rdram, ctx);
        goto after_7;
    // 0x80800770: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_7:
    // 0x80800774: lui         $a1, 0x3F2A
    ctx->r5 = S32(0X3F2A << 16);
    // 0x80800778: ori         $a1, $a1, 0xACDA
    ctx->r5 = ctx->r5 | 0XACDA;
    // 0x8080077C: jal         0x8008B24C
    // 0x80800780: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_setStart(rdram, ctx);
        goto after_8;
    // 0x80800780: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_8:
    // 0x80800784: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800788: jal         0x8008B1BC
    // 0x8080078C: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_9;
    // 0x8080078C: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_9:
    // 0x80800790: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800794: jal         0x8008B134
    // 0x80800798: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_10;
    // 0x80800798: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x8080079C: jal         0x8008B064
    // 0x808007A0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_start(rdram, ctx);
        goto after_11;
    // 0x808007A0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_11:
    // 0x808007A4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808007A8: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
    // 0x808007AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808007B0:
    // 0x808007B0: jal         0x80095748
    // 0x808007B4: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    baflag_isFalse(rdram, ctx);
        goto after_12;
    // 0x808007B4: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_12:
    // 0x808007B8: beq         $v0, $zero, L_80800888
    if (ctx->r2 == 0) {
        // 0x808007BC: nop
    
            goto L_80800888;
    }
    // 0x808007BC: nop

    // 0x808007C0: jal         0x8008E260
    // 0x808007C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E260(rdram, ctx);
        goto after_13;
    // 0x808007C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808007C8: beq         $v0, $zero, L_808007D4
    if (ctx->r2 == 0) {
        // 0x808007CC: addiu       $t7, $zero, 0x3D
        ctx->r15 = ADD32(0, 0X3D);
            goto L_808007D4;
    }
    // 0x808007CC: addiu       $t7, $zero, 0x3D
    ctx->r15 = ADD32(0, 0X3D);
    // 0x808007D0: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
L_808007D4:
    // 0x808007D4: jal         0x800A3274
    // 0x808007D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3274(rdram, ctx);
        goto after_14;
    // 0x808007D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808007DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808007E0: beq         $v0, $at, L_808007F8
    if (ctx->r2 == ctx->r1) {
        // 0x808007E4: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_808007F8;
    }
    // 0x808007E4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x808007E8: beq         $v0, $at, L_80800848
    if (ctx->r2 == ctx->r1) {
        // 0x808007EC: nop
    
            goto L_80800848;
    }
    // 0x808007EC: nop

    // 0x808007F0: b           L_8080085C
    // 0x808007F4: nop

        goto L_8080085C;
    // 0x808007F4: nop

L_808007F8:
    // 0x808007F8: jal         0x80097DF4
    // 0x808007FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_func_80097DF4(rdram, ctx);
        goto after_15;
    // 0x808007FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800800: beq         $v0, $zero, L_8080081C
    if (ctx->r2 == 0) {
        // 0x80800804: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080081C;
    }
    // 0x80800804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800808: jal         0x80095748
    // 0x8080080C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    baflag_isFalse(rdram, ctx);
        goto after_16;
    // 0x8080080C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_16:
    // 0x80800810: beq         $v0, $zero, L_8080081C
    if (ctx->r2 == 0) {
        // 0x80800814: addiu       $t8, $zero, 0x10
        ctx->r24 = ADD32(0, 0X10);
            goto L_8080081C;
    }
    // 0x80800814: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x80800818: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_8080081C:
    // 0x8080081C: jal         0x80097F08
    // 0x80800820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_func_80097F08(rdram, ctx);
        goto after_17;
    // 0x80800820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800824: beq         $v0, $zero, L_80800830
    if (ctx->r2 == 0) {
        // 0x80800828: addiu       $t9, $zero, 0x11
        ctx->r25 = ADD32(0, 0X11);
            goto L_80800830;
    }
    // 0x80800828: addiu       $t9, $zero, 0x11
    ctx->r25 = ADD32(0, 0X11);
    // 0x8080082C: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
L_80800830:
    // 0x80800830: jal         0x80097A90
    // 0x80800834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_beak_bust(rdram, ctx);
        goto after_18;
    // 0x80800834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800838: beq         $v0, $zero, L_8080085C
    if (ctx->r2 == 0) {
        // 0x8080083C: addiu       $t0, $zero, 0xF
        ctx->r8 = ADD32(0, 0XF);
            goto L_8080085C;
    }
    // 0x8080083C: addiu       $t0, $zero, 0xF
    ctx->r8 = ADD32(0, 0XF);
    // 0x80800840: b           L_8080085C
    // 0x80800844: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
        goto L_8080085C;
    // 0x80800844: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
L_80800848:
    // 0x80800848: jal         0x80097EC8
    // 0x8080084C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_func_80097EC8(rdram, ctx);
        goto after_19;
    // 0x8080084C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800850: beq         $v0, $zero, L_8080085C
    if (ctx->r2 == 0) {
        // 0x80800854: addiu       $t1, $zero, 0xE4
        ctx->r9 = ADD32(0, 0XE4);
            goto L_8080085C;
    }
    // 0x80800854: addiu       $t1, $zero, 0xE4
    ctx->r9 = ADD32(0, 0XE4);
    // 0x80800858: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
L_8080085C:
    // 0x8080085C: jal         0x8008DA24
    // 0x80800860: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DA24(rdram, ctx);
        goto after_20;
    // 0x80800860: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80800864: beq         $v0, $zero, L_80800870
    if (ctx->r2 == 0) {
        // 0x80800868: addiu       $t2, $zero, 0xA8
        ctx->r10 = ADD32(0, 0XA8);
            goto L_80800870;
    }
    // 0x80800868: addiu       $t2, $zero, 0xA8
    ctx->r10 = ADD32(0, 0XA8);
    // 0x8080086C: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
L_80800870:
    // 0x80800870: jal         0x8008E35C
    // 0x80800874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_21;
    // 0x80800874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800878: beq         $v0, $zero, L_808008C8
    if (ctx->r2 == 0) {
        // 0x8080087C: addiu       $t3, $zero, 0x4C
        ctx->r11 = ADD32(0, 0X4C);
            goto L_808008C8;
    }
    // 0x8080087C: addiu       $t3, $zero, 0x4C
    ctx->r11 = ADD32(0, 0X4C);
    // 0x80800880: b           L_808008C8
    // 0x80800884: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
        goto L_808008C8;
    // 0x80800884: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
L_80800888:
    // 0x80800888: jal         0x8008E35C
    // 0x8080088C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_22;
    // 0x8080088C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80800890: beq         $v0, $zero, L_808008C8
    if (ctx->r2 == 0) {
        // 0x80800894: nop
    
            goto L_808008C8;
    }
    // 0x80800894: nop

    // 0x80800898: jal         0x800A046C
    // 0x8080089C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A046C(rdram, ctx);
        goto after_23;
    // 0x8080089C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x808008A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008A4: jal         0x80095738
    // 0x808008A8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    baflag_isTrue(rdram, ctx);
        goto after_24;
    // 0x808008A8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_24:
    // 0x808008AC: bne         $v0, $zero, L_808008C0
    if (ctx->r2 != 0) {
        // 0x808008B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008C0;
    }
    // 0x808008B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008B4: jal         0x80095738
    // 0x808008B8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    baflag_isTrue(rdram, ctx);
        goto after_25;
    // 0x808008B8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_25:
    // 0x808008BC: beq         $v0, $zero, L_808008C8
    if (ctx->r2 == 0) {
        // 0x808008C0: addiu       $t4, $zero, 0xD
        ctx->r12 = ADD32(0, 0XD);
            goto L_808008C8;
    }
L_808008C0:
    // 0x808008C0: addiu       $t4, $zero, 0xD
    ctx->r12 = ADD32(0, 0XD);
    // 0x808008C4: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
L_808008C8:
    // 0x808008C8: jal         0x8008E078
    // 0x808008CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_26;
    // 0x808008CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x808008D0: beql        $v0, $zero, L_808008EC
    if (ctx->r2 == 0) {
        // 0x808008D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008EC;
    }
    goto skip_2;
    // 0x808008D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x808008D8: jal         0x8009FE58
    // 0x808008DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009FE58(rdram, ctx);
        goto after_27;
    // 0x808008DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x808008E0: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x808008E4: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x808008E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808008EC:
    // 0x808008EC: jal         0x8009E5C8
    // 0x808008F0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    bs_setState(rdram, ctx);
        goto after_28;
    // 0x808008F0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_28:
    // 0x808008F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808008F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808008FC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800900: jr          $ra
    // 0x80800904: nop

    return;
    // 0x80800904: nop

;}
RECOMP_FUNC void func_8008E4B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E4B0: jr          $ra
    // 0x8008E4B4: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
    return;
    // 0x8008E4B4: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_80091FE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091FE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80091FE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80091FEC: jal         0x800DB9B0
    // 0x80091FF0: nop

    func_800DB9B0(rdram, ctx);
        goto after_0;
    // 0x80091FF0: nop

    after_0:
    // 0x80091FF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80091FF8: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80091FFC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80092000: jr          $ra
    // 0x80092004: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80092004: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80092008: nop

    // 0x8009200C: nop

;}
RECOMP_FUNC void func_8080041C_chfactorymaindoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080041C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800420: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800424: jal         0x800857E8
    // 0x80800428: addiu       $a1, $zero, 0x188
    ctx->r5 = ADD32(0, 0X188);
    _chswitch_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800428: addiu       $a1, $zero, 0x188
    ctx->r5 = ADD32(0, 0X188);
    after_0:
    // 0x8080042C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800430: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800434: jr          $ra
    // 0x80800438: nop

    return;
    // 0x80800438: nop

;}
RECOMP_FUNC void func_80800D30_chstatueboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D38: jal         0x80100094
    // 0x80800D3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800D3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800D40: lh          $v1, 0x84($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X84);
    // 0x80800D44: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1312, 0X25C0) << 16);
    // 0x80800D48: addiu       $t7, $t7, 0x25C0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1312, 0X25C0));
    // 0x80800D4C: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80800D50: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x80800D54: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800D58: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80800D5C: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x80800D60: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x80800D64: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x80800D68: beq         $a3, $t9, L_80800D98
    if (ctx->r7 == ctx->r25) {
        // 0x80800D6C: subu        $t0, $t0, $v1
        ctx->r8 = SUB32(ctx->r8, ctx->r3);
            goto L_80800D98;
    }
    // 0x80800D6C: subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // 0x80800D70: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80800D74: addu        $a0, $t0, $t7
    ctx->r4 = ADD32(ctx->r8, ctx->r15);
    // 0x80800D78: lh          $a1, 0x0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X0);
    // 0x80800D7C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800D80: addu        $t1, $v0, $a1
    ctx->r9 = ADD32(ctx->r2, ctx->r5);
L_80800D84:
    // 0x80800D84: sb          $a2, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r6;
    // 0x80800D88: lh          $a1, 0x2($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X2);
    // 0x80800D8C: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80800D90: bnel        $a3, $a1, L_80800D84
    if (ctx->r7 != ctx->r5) {
        // 0x80800D94: addu        $t1, $v0, $a1
        ctx->r9 = ADD32(ctx->r2, ctx->r5);
            goto L_80800D84;
    }
    goto skip_0;
    // 0x80800D94: addu        $t1, $v0, $a1
    ctx->r9 = ADD32(ctx->r2, ctx->r5);
    skip_0:
L_80800D98:
    // 0x80800D98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800DA0: jr          $ra
    // 0x80800DA4: nop

    return;
    // 0x80800DA4: nop

;}
