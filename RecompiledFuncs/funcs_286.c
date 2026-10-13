#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800D433C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D433C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D4340: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D4344: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D4348: jal         0x800D41D8
    // 0x800D434C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800D41D8(rdram, ctx);
        goto after_0;
    // 0x800D434C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800D4350: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x800D4354: beq         $v0, $at, L_800D4370
    if (ctx->r2 == ctx->r1) {
        // 0x800D4358: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800D4370;
    }
    // 0x800D4358: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D435C: jal         0x800C6E38
    // 0x800D4360: nop

    func_800C6E38(rdram, ctx);
        goto after_1;
    // 0x800D4360: nop

    after_1:
    // 0x800D4364: bne         $v0, $zero, L_800D4370
    if (ctx->r2 != 0) {
        // 0x800D4368: nop
    
            goto L_800D4370;
    }
    // 0x800D4368: nop

    // 0x800D436C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800D4370:
    // 0x800D4370: jal         0x800D1ACC
    // 0x800D4374: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800D1ACC(rdram, ctx);
        goto after_2;
    // 0x800D4374: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x800D4378: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800D437C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800D4380: jal         0x800D1960
    // 0x800D4384: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_800D1960(rdram, ctx);
        goto after_3;
    // 0x800D4384: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x800D4388: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D438C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D4390: jr          $ra
    // 0x800D4394: nop

    return;
    // 0x800D4394: nop

;}
RECOMP_FUNC void func_808001B0_chlagoonlockerdoorhits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808001B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001B8: addiu       $a0, $zero, 0x3A4
    ctx->r4 = ADD32(0, 0X3A4);
    // 0x808001BC: jal         0x800DA564
    // 0x808001C0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800DA564(rdram, ctx);
        goto after_0;
    // 0x808001C0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x808001C4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808001C8: jal         0x800DA298
    // 0x808001CC: addiu       $a0, $zero, 0x3A8
    ctx->r4 = ADD32(0, 0X3A8);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x808001CC: addiu       $a0, $zero, 0x3A8
    ctx->r4 = ADD32(0, 0X3A8);
    after_1:
    // 0x808001D0: beq         $v0, $zero, L_808001E0
    if (ctx->r2 == 0) {
        // 0x808001D4: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_808001E0;
    }
    // 0x808001D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808001D8: b           L_808001E0
    // 0x808001DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_808001E0;
    // 0x808001DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_808001E0:
    // 0x808001E0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x808001E4: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x808001E8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x808001EC: addiu       $a0, $t6, 0x9
    ctx->r4 = ADD32(ctx->r14, 0X9);
    // 0x808001F0: jal         0x800BF744
    // 0x808001F4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_800BF744(rdram, ctx);
        goto after_2;
    // 0x808001F4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_2:
    // 0x808001F8: jal         0x800DA298
    // 0x808001FC: addiu       $a0, $zero, 0x3A8
    ctx->r4 = ADD32(0, 0X3A8);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x808001FC: addiu       $a0, $zero, 0x3A8
    ctx->r4 = ADD32(0, 0X3A8);
    after_3:
    // 0x80800200: beq         $v0, $zero, L_80800210
    if (ctx->r2 == 0) {
        // 0x80800204: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_80800210;
    }
    // 0x80800204: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800208: b           L_80800214
    // 0x8080020C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_80800214;
    // 0x8080020C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80800210:
    // 0x80800210: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
L_80800214:
    // 0x80800214: jal         0x800BF744
    // 0x80800218: addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
    func_800BF744(rdram, ctx);
        goto after_4;
    // 0x80800218: addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
    after_4:
    // 0x8080021C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800220: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800224: jr          $ra
    // 0x80800228: nop

    return;
    // 0x80800228: nop

;}
RECOMP_FUNC void func_800BED18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BED18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BED1C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800BED20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BED24: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800BED28: jal         0x800EE830
    // 0x800BED2C: addiu       $a1, $a1, -0x78B8
    ctx->r5 = ADD32(ctx->r5, -0X78B8);
    func_800EE830(rdram, ctx);
        goto after_0;
    // 0x800BED2C: addiu       $a1, $a1, -0x78B8
    ctx->r5 = ADD32(ctx->r5, -0X78B8);
    after_0:
    // 0x800BED30: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800BED34: addiu       $a1, $a1, -0x78AC
    ctx->r5 = ADD32(ctx->r5, -0X78AC);
    // 0x800BED38: jal         0x800EE830
    // 0x800BED3C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800EE830(rdram, ctx);
        goto after_1;
    // 0x800BED3C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800BED40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BED44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BED48: jr          $ra
    // 0x800BED4C: nop

    return;
    // 0x800BED4C: nop

;}
RECOMP_FUNC void func_800F4950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F4950: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F4954: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F4958: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F495C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F4960: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F4964: jal         0x80084448
    // 0x800F4968: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    _baattach_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x800F4968: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F496C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F4970: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F4974: jr          $ra
    // 0x800F4978: nop

    return;
    // 0x800F4978: nop

;}
RECOMP_FUNC void func_8008BA5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008BA5C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008BA60: addiu       $v1, $v1, 0x6CC0
    ctx->r3 = ADD32(ctx->r3, 0X6CC0);
    // 0x8008BA64: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8008BA68: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x8008BA6C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8008BA70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008BA74: subu        $t7, $t6, $a0
    ctx->r15 = SUB32(ctx->r14, ctx->r4);
    // 0x8008BA78: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x8008BA7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008BA80: mflo        $t8
    ctx->r24 = lo;
    // 0x8008BA84: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8008BA88: jal         0x8001BAFC
    // 0x8008BA8C: nop

    defrag(rdram, ctx);
        goto after_0;
    // 0x8008BA8C: nop

    after_0:
    // 0x8008BA90: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8008BA94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008BA98: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008BA9C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8008BAA0: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8008BAA4: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x8008BAA8: addiu       $v1, $v1, 0x6CC0
    ctx->r3 = ADD32(ctx->r3, 0X6CC0);
    // 0x8008BAAC: addu        $t2, $t0, $v0
    ctx->r10 = ADD32(ctx->r8, ctx->r2);
    // 0x8008BAB0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8008BAB4: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x8008BAB8: jr          $ra
    // 0x8008BABC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8008BABC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void bskazshoesspringjump_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800184: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800188: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080018C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800190: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80800194: lw          $v0, 0x15C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X15C);
    // 0x80800198: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080019C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808001A0: beq         $v0, $at, L_808001BC
    if (ctx->r2 == ctx->r1) {
        // 0x808001A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001BC;
    }
    // 0x808001A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808001AC: beq         $v0, $at, L_808001E0
    if (ctx->r2 == ctx->r1) {
        // 0x808001B0: nop
    
            goto L_808001E0;
    }
    // 0x808001B0: nop

    // 0x808001B4: b           L_80800228
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800228;
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808001BC:
    // 0x808001BC: lui         $a1, 0x3EF2
    ctx->r5 = S32(0X3EF2 << 16);
    // 0x808001C0: jal         0x8008CB10
    // 0x808001C4: ori         $a1, $a1, 0xE48F
    ctx->r5 = ctx->r5 | 0XE48F;
    baanim_isAt(rdram, ctx);
        goto after_0;
    // 0x808001C4: ori         $a1, $a1, 0xE48F
    ctx->r5 = ctx->r5 | 0XE48F;
    after_0:
    // 0x808001C8: beq         $v0, $zero, L_80800224
    if (ctx->r2 == 0) {
        // 0x808001CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800224;
    }
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D0: jal         0x80800000
    // 0x808001D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800000_bskazshoesspringjump(rdram, ctx);
        goto after_1;
    // 0x808001D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x808001D8: b           L_80800228
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800228;
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808001E0:
    // 0x808001E0: jal         0x8008CAC8
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getTimer(rdram, ctx);
        goto after_2;
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808001E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(276, 0X260) << 16);
    // 0x808001EC: lwc1        $f4, 0x260($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(276, 0X260));
    // 0x808001F0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808001F4: nop

    // 0x808001F8: bc1f        L_80800208
    if (!c1cs) {
        // 0x808001FC: nop
    
            goto L_80800208;
    }
    // 0x808001FC: nop

    // 0x80800200: jal         0x80085058
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bashoes_entrypoint_16(rdram, ctx);
        goto after_3;
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_80800208:
    // 0x80800208: jal         0x800834B0
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bskazmove_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800210: jal         0x8008CAEC
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_5;
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800218: beq         $v0, $zero, L_80800224
    if (ctx->r2 == 0) {
        // 0x8080021C: addiu       $t6, $zero, 0xDF
        ctx->r14 = ADD32(0, 0XDF);
            goto L_80800224;
    }
    // 0x8080021C: addiu       $t6, $zero, 0xDF
    ctx->r14 = ADD32(0, 0XDF);
    // 0x80800220: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800224:
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800228:
    // 0x80800228: jal         0x8009E5C8
    // 0x8080022C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_6;
    // 0x8080022C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x80800230: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800234: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800238: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080023C: jr          $ra
    // 0x80800240: nop

    return;
    // 0x80800240: nop

;}
RECOMP_FUNC void _cheggnormal_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087258: syscall     539
    recomp_syscall_handler(rdram, ctx, 0x80087258);
    return;
    // 0x8008725C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800068_chcrusher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800068: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080006C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800070: jal         0x80101870
    // 0x80800074: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80101870(rdram, ctx);
        goto after_0;
    // 0x80800074: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800078: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8080007C: lw          $t7, 0x7C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X7C);
    // 0x80800080: sll         $t9, $t7, 19
    ctx->r25 = S32(ctx->r15 << 19);
    // 0x80800084: bgezl       $t9, L_808000C8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800088: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808000C8;
    }
    goto skip_0;
    // 0x80800088: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080008C: jal         0x80104130
    // 0x80800090: nop

    func_80104130(rdram, ctx);
        goto after_1;
    // 0x80800090: nop

    after_1:
    // 0x80800094: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800098: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080009C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x808000A0: jal         0x800DBEFC
    // 0x808000A4: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    func_800DBEFC(rdram, ctx);
        goto after_2;
    // 0x808000A4: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    after_2:
    // 0x808000A8: jal         0x80104130
    // 0x808000AC: nop

    func_80104130(rdram, ctx);
        goto after_3;
    // 0x808000AC: nop

    after_3:
    // 0x808000B0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808000B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000B8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808000BC: jal         0x800DBEFC
    // 0x808000C0: addiu       $a2, $a2, 0x28
    ctx->r6 = ADD32(ctx->r6, 0X28);
    func_800DBEFC(rdram, ctx);
        goto after_4;
    // 0x808000C0: addiu       $a2, $a2, 0x28
    ctx->r6 = ADD32(ctx->r6, 0X28);
    after_4:
    // 0x808000C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000C8:
    // 0x808000C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000CC: jr          $ra
    // 0x808000D0: nop

    return;
    // 0x808000D0: nop

;}
RECOMP_FUNC void func_808018E0_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808018E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808018E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808018E8: jal         0x800A4CA8
    // 0x808018EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800A4CA8(rdram, ctx);
        goto after_0;
    // 0x808018EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808018F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808018F4: jal         0x80110730
    // 0x808018F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80110730(rdram, ctx);
        goto after_1;
    // 0x808018F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808018FC: jal         0x800A4C88
    // 0x80801900: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A4C88(rdram, ctx);
        goto after_2;
    // 0x80801900: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80801904: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801908: jal         0x8010FD38
    // 0x8080190C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8010FD38(rdram, ctx);
        goto after_3;
    // 0x8080190C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x80801910: jal         0x800A5044
    // 0x80801914: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A5044(rdram, ctx);
        goto after_4;
    // 0x80801914: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x80801918: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080191C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801920: jr          $ra
    // 0x80801924: nop

    return;
    // 0x80801924: nop

;}
RECOMP_FUNC void _gcdialogexec_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087E78: syscall     658
    recomp_syscall_handler(rdram, ctx, 0x80087E78);
    return;
    // 0x80087E7C: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_80800028_ncbaspiral(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800028: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080002C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800030: jal         0x80112524
    // 0x80800034: nop

    func_80112524(rdram, ctx);
        goto after_0;
    // 0x80800034: nop

    after_0:
    // 0x80800038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080003C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800040: jr          $ra
    // 0x80800044: nop

    return;
    // 0x80800044: nop

;}
RECOMP_FUNC void _glintrosyncDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800885D0: syscall     695
    recomp_syscall_handler(rdram, ctx, 0x800885D0);
    return;
    // 0x800885D4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void fxleaves_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800290: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800294: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800298: jal         0x800B28B8
    // 0x8080029C: lw          $a0, 0x1C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1C);
    vector_clear(rdram, ctx);
        goto after_0;
    // 0x8080029C: lw          $a0, 0x1C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1C);
    after_0:
    // 0x808002A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002A8: jr          $ra
    // 0x808002AC: nop

    return;
    // 0x808002AC: nop

;}
RECOMP_FUNC void func_808008D0_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808008DC: lhu         $t7, 0x72($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X72);
    // 0x808008E0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(804, 0X7DE0) << 16);
    // 0x808008E4: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x808008E8: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x808008EC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x808008F0: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x808008F4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x808008F8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x808008FC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80800900: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x80800904: lw          $v0, 0x7DE0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(804, 0X7DE0));
    // 0x80800908: beql        $v0, $zero, L_80800920
    if (ctx->r2 == 0) {
        // 0x8080090C: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_80800920;
    }
    goto skip_0;
    // 0x8080090C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    skip_0:
    // 0x80800910: jalr        $v0
    // 0x80800914: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80800914: nop

    after_0:
    // 0x80800918: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8080091C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
L_80800920:
    // 0x80800920: beq         $a3, $at, L_80800934
    if (ctx->r7 == ctx->r1) {
        // 0x80800924: lw          $t0, 0x18($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X18);
            goto L_80800934;
    }
    // 0x80800924: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80800928: lw          $a0, 0x2C($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X2C);
    // 0x8080092C: jal         0x808026C8
    // 0x80800930: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_808026C8_chgameselect(rdram, ctx);
        goto after_1;
    // 0x80800930: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_1:
L_80800934:
    // 0x80800934: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800938: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080093C: jr          $ra
    // 0x80800940: nop

    return;
    // 0x80800940: nop

;}
RECOMP_FUNC void gsworldDll_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808004E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808004E4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808004E8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808004EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808004F0: jal         0x8001A2B0
    // 0x808004F4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    func_8001A2B0(rdram, ctx);
        goto after_0;
    // 0x808004F4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    after_0:
    // 0x808004F8: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x808004FC: jal         0x800A5104
    // 0x80800500: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800A5104(rdram, ctx);
        goto after_1;
    // 0x80800500: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x80800504: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80800508: jal         0x800C2A5C
    // 0x8080050C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800C2A5C(rdram, ctx);
        goto after_2;
    // 0x8080050C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x80800510: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80800514: jal         0x800FE8BC
    // 0x80800518: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800FE8BC(rdram, ctx);
        goto after_3;
    // 0x80800518: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x8080051C: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80800520: jal         0x800C7574
    // 0x80800524: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800C7574(rdram, ctx);
        goto after_4;
    // 0x80800524: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x80800528: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8080052C: jal         0x800B5654
    // 0x80800530: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800B5654(rdram, ctx);
        goto after_5;
    // 0x80800530: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x80800534: sh          $s1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r17;
    // 0x80800538: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080053C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800540: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800544: jr          $ra
    // 0x80800548: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800548: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void gctransitionDll_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009B8: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x808009BC: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x808009C0: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2654, 0XEA4) << 16);
    // 0x808009C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808009C8: addiu       $t7, $t7, 0xEA4
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2654, 0XEA4));
    // 0x808009CC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808009D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009D4: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    // 0x808009D8: jal         0x808000D8
    // 0x808009DC: lbu         $a1, 0x1($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X1);
    func_808000D8_gctransitionDll(rdram, ctx);
        goto after_0;
    // 0x808009DC: lbu         $a1, 0x1($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X1);
    after_0:
    // 0x808009E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808009E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808009E8: jr          $ra
    // 0x808009EC: nop

    return;
    // 0x808009EC: nop

;}
RECOMP_FUNC void bafly_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080020C: lw          $t6, 0x8C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8C);
    // 0x80800210: jr          $ra
    // 0x80800214: sb          $a1, 0x8($t6)
    MEM_B(0X8, ctx->r14) = ctx->r5;
    return;
    // 0x80800214: sb          $a1, 0x8($t6)
    MEM_B(0X8, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void suchase_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800068: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080006C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800070: jal         0x80800000
    // 0x80800074: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    suchase_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800074: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800078: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8080007C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80800080: bne         $t6, $zero, L_80800098
    if (ctx->r14 != 0) {
        // 0x80800084: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80800098;
    }
    // 0x80800084: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80800088: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8080008C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80800090: xor         $v0, $v1, $t8
    ctx->r2 = ctx->r3 ^ ctx->r24;
    // 0x80800094: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80800098:
    // 0x80800098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080009C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000A0: jr          $ra
    // 0x808000A4: nop

    return;
    // 0x808000A4: nop

;}
RECOMP_FUNC void func_80801838_bskazfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801838: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080183C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801840: addiu       $a1, $zero, 0x162
    ctx->r5 = ADD32(0, 0X162);
    // 0x80801844: jal         0x80084C38
    // 0x80801848: addiu       $a2, $zero, 0xBB
    ctx->r6 = ADD32(0, 0XBB);
    _bafly_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80801848: addiu       $a2, $zero, 0xBB
    ctx->r6 = ADD32(0, 0XBB);
    after_0:
    // 0x8080184C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801850: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801854: jr          $ra
    // 0x80801858: nop

    return;
    // 0x80801858: nop

;}
RECOMP_FUNC void _bapulse_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084F48: syscall     144
    recomp_syscall_handler(rdram, ctx, 0x80084F48);
    return;
    // 0x80084F4C: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void bskazpaddle_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008D8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808008DC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(268, 0XA80) << 16);
    // 0x808008E0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808008E4: jr          $ra
    // 0x808008E8: lw          $v0, 0xA80($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(268, 0XA80));
    return;
    // 0x808008E8: lw          $v0, 0xA80($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(268, 0XA80));
;}
RECOMP_FUNC void func_80803B3C_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803B3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803B40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803B44: jal         0x80088360
    // 0x80803B48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _gcstatusDll_entrypoint_10(rdram, ctx);
        goto after_0;
    // 0x80803B48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80803B4C: jal         0x80016BDC
    // 0x80803B50: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80016BDC(rdram, ctx);
        goto after_1;
    // 0x80803B50: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80803B54: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80803B58: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80803B5C: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80803B60: jal         0x800C9DAC
    // 0x80803B64: addiu       $a1, $a1, -0x5E60
    ctx->r5 = ADD32(ctx->r5, -0X5E60);
    func_800C9DAC(rdram, ctx);
        goto after_2;
    // 0x80803B64: addiu       $a1, $a1, -0x5E60
    ctx->r5 = ADD32(ctx->r5, -0X5E60);
    after_2:
    // 0x80803B68: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80803B6C: jal         0x80800478
    // 0x80803B70: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80800478_chgameselect(rdram, ctx);
        goto after_3;
    // 0x80803B70: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_3:
    // 0x80803B74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803B78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803B7C: jr          $ra
    // 0x80803B80: nop

    return;
    // 0x80803B80: nop

;}
RECOMP_FUNC void func_80804D30_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804D30: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80804D34: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80804D38: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x80804D3C: lui         $t8, 0x8081
    ctx->r24 = S32(RELOC_HI16(804, 0X83E8) << 16);
    // 0x80804D40: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80804D44: addiu       $t8, $t8, -0x7C18
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(804, 0X83E8));
    // 0x80804D48: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80804D4C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80804D50: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80804D54: lh          $a0, 0x2($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X2);
    // 0x80804D58: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80804D5C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80804D60: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80804D64: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80804D68: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80804D6C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80804D70: jal         0x80088150
    // 0x80804D74: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    _gcfrontend_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80804D74: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x80804D78: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80804D7C: jal         0x80088158
    // 0x80804D80: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    _gcfrontend_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80804D80: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x80804D84: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80804D88: lw          $a0, 0x30($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X30);
    // 0x80804D8C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80804D90: jal         0x80802D40
    // 0x80804D94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80802D40_chgameselect(rdram, ctx);
        goto after_2;
    // 0x80804D94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80804D98: blez        $s2, L_80804DE8
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80804D9C: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80804DE8;
    }
    // 0x80804D9C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80804DA0: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
L_80804DA4:
    // 0x80804DA4: jal         0x80088148
    // 0x80804DA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcfrontend_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80804DA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80804DAC: beql        $v0, $zero, L_80804DE0
    if (ctx->r2 == 0) {
        // 0x80804DB0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80804DE0;
    }
    goto skip_0;
    // 0x80804DB0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x80804DB4: jal         0x800881A0
    // 0x80804DB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcfrontend_entrypoint_14(rdram, ctx);
        goto after_4;
    // 0x80804DB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80804DBC: lw          $a0, 0x30($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X30);
    // 0x80804DC0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80804DC4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80804DC8: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80804DCC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80804DD0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80804DD4: jal         0x80802DB4
    // 0x80804DD8: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    func_80802DB4_chgameselect(rdram, ctx);
        goto after_5;
    // 0x80804DD8: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    after_5:
    // 0x80804DDC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80804DE0:
    // 0x80804DE0: bne         $s1, $s2, L_80804DA4
    if (ctx->r17 != ctx->r18) {
        // 0x80804DE4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80804DA4;
    }
    // 0x80804DE4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80804DE8:
    // 0x80804DE8: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80804DEC: lw          $a0, 0x30($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X30);
    // 0x80804DF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80804DF4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80804DF8: jal         0x80802E38
    // 0x80804DFC: lh          $a1, 0x0($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X0);
    func_80802E38_chgameselect(rdram, ctx);
        goto after_6;
    // 0x80804DFC: lh          $a1, 0x0($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X0);
    after_6:
    // 0x80804E00: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80804E04: lw          $a0, 0x2C($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X2C);
    // 0x80804E08: jal         0x808026C8
    // 0x80804E0C: addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    func_808026C8_chgameselect(rdram, ctx);
        goto after_7;
    // 0x80804E0C: addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    after_7:
    // 0x80804E10: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80804E14: sw          $t1, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r9;
    // 0x80804E18: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80804E1C: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80804E20: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80804E24: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80804E28: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80804E2C: jr          $ra
    // 0x80804E30: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80804E30: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8080012C_chmumboskullfakearchpanellava(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080012C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800130: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800134: jal         0x800EFD24
    // 0x80800138: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x80800138: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x8080013C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800140: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800144: jr          $ra
    // 0x80800148: nop

    return;
    // 0x80800148: nop

;}
RECOMP_FUNC void func_80806F10_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806F10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80806F14: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80806F18: lbu         $t6, 0x27($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X27);
    // 0x80806F1C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80806F20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80806F24: bne         $t6, $zero, L_80806F3C
    if (ctx->r14 != 0) {
        // 0x80806F28: addiu       $a1, $a2, 0x4
        ctx->r5 = ADD32(ctx->r6, 0X4);
            goto L_80806F3C;
    }
    // 0x80806F28: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    // 0x80806F2C: jal         0x80089D10
    // 0x80806F30: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    _subaddieaudioquick_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80806F30: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80806F34: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80806F38: sb          $v0, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r2;
L_80806F3C:
    // 0x80806F3C: addiu       $t7, $a2, 0x4
    ctx->r15 = ADD32(ctx->r6, 0X4);
    // 0x80806F40: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80806F44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80806F48: jal         0x800DC128
    // 0x80806F4C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DC128(rdram, ctx);
        goto after_1;
    // 0x80806F4C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80806F50: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x80806F54: lui         $a0, 0x8081
    ctx->r4 = S32(RELOC_HI16(1480, 0XA11C) << 16);
    // 0x80806F58: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x80806F5C: jal         0x800C4B7C
    // 0x80806F60: lh          $a0, -0x5EE4($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(1480, 0XA11C));
    func_800C4B7C(rdram, ctx);
        goto after_2;
    // 0x80806F60: lh          $a0, -0x5EE4($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(1480, 0XA11C));
    after_2:
    // 0x80806F64: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0XA104) << 16);
    // 0x80806F68: addiu       $a2, $a2, -0x5EFC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0XA104));
    // 0x80806F6C: lbu         $a0, 0x27($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X27);
    // 0x80806F70: jal         0x800C4350
    // 0x80806F74: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800C4350(rdram, ctx);
        goto after_3;
    // 0x80806F74: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80806F78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80806F7C: lbu         $v0, 0x27($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X27);
    // 0x80806F80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80806F84: jr          $ra
    // 0x80806F88: nop

    return;
    // 0x80806F88: nop

;}
RECOMP_FUNC void func_80800BE0_chstatueboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BE0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800BE4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800BE8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800BEC: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800BF0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800BF4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800BF8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800BFC: jal         0x80100094
    // 0x80800C00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800C00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800C04: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800C08: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800C0C: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
    // 0x80800C10: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80800C14:
    // 0x80800C14: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800C18: jal         0x80801640
    // 0x80800C1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80801640_chstatueboss(rdram, ctx);
        goto after_1;
    // 0x80800C1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80800C20: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800C24: bnel        $s0, $s2, L_80800C14
    if (ctx->r16 != ctx->r18) {
        // 0x80800C28: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80800C14;
    }
    goto skip_0;
    // 0x80800C28: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_0:
    // 0x80800C2C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800C30: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800C34: jal         0x80801640
    // 0x80800C38: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80801640_chstatueboss(rdram, ctx);
        goto after_2;
    // 0x80800C38: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80800C3C: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(1312, 0X25C0) << 16);
    // 0x80800C40: addiu       $t0, $t0, 0x25C0
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(1312, 0X25C0));
    // 0x80800C44: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800C48: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800C4C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80800C50: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_80800C54:
    // 0x80800C54: lh          $t6, 0x0($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X0);
    // 0x80800C58: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x80800C5C: subu        $t7, $t7, $a3
    ctx->r15 = SUB32(ctx->r15, ctx->r7);
    // 0x80800C60: beq         $a1, $t6, L_80800C94
    if (ctx->r5 == ctx->r14) {
        // 0x80800C64: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800C94;
    }
    // 0x80800C64: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800C68: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1312, 0X25C0) << 16);
    // 0x80800C6C: addiu       $t8, $t8, 0x25C0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1312, 0X25C0));
    // 0x80800C70: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80800C74: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x80800C78: addu        $t9, $s1, $a0
    ctx->r25 = ADD32(ctx->r17, ctx->r4);
L_80800C7C:
    // 0x80800C7C: sb          $a2, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r6;
    // 0x80800C80: lh          $a0, 0x2($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2);
    // 0x80800C84: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80800C88: bnel        $a1, $a0, L_80800C7C
    if (ctx->r5 != ctx->r4) {
        // 0x80800C8C: addu        $t9, $s1, $a0
        ctx->r25 = ADD32(ctx->r17, ctx->r4);
            goto L_80800C7C;
    }
    goto skip_1;
    // 0x80800C8C: addu        $t9, $s1, $a0
    ctx->r25 = ADD32(ctx->r17, ctx->r4);
    skip_1:
    // 0x80800C90: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80800C94:
    // 0x80800C94: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80800C98: slti        $at, $a3, 0x4
    ctx->r1 = SIGNED(ctx->r7) < 0X4 ? 1 : 0;
    // 0x80800C9C: bne         $at, $zero, L_80800C54
    if (ctx->r1 != 0) {
        // 0x80800CA0: addiu       $t0, $t0, 0xC
        ctx->r8 = ADD32(ctx->r8, 0XC);
            goto L_80800C54;
    }
    // 0x80800CA0: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x80800CA4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800CA8: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_80800CAC:
    // 0x80800CAC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800CB0: slti        $at, $s0, 0x5
    ctx->r1 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
    // 0x80800CB4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800CB8: bne         $at, $zero, L_80800CAC
    if (ctx->r1 != 0) {
        // 0x80800CBC: swc1        $f0, 0x6C($v0)
        MEM_W(0X6C, ctx->r2) = ctx->f0.u32l;
            goto L_80800CAC;
    }
    // 0x80800CBC: swc1        $f0, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f0.u32l;
    // 0x80800CC0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800CC4: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_80800CC8:
    // 0x80800CC8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800CCC: slti        $at, $s0, 0x6
    ctx->r1 = SIGNED(ctx->r16) < 0X6 ? 1 : 0;
    // 0x80800CD0: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x80800CD4: sw          $zero, 0x94($v0)
    MEM_W(0X94, ctx->r2) = 0;
    // 0x80800CD8: swc1        $f0, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->f0.u32l;
    // 0x80800CDC: bne         $at, $zero, L_80800CC8
    if (ctx->r1 != 0) {
        // 0x80800CE0: swc1        $f0, 0x9C($v0)
        MEM_W(0X9C, ctx->r2) = ctx->f0.u32l;
            goto L_80800CC8;
    }
    // 0x80800CE0: swc1        $f0, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = ctx->f0.u32l;
    // 0x80800CE4: swc1        $f0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f0.u32l;
    // 0x80800CE8: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x80800CEC: addiu       $v0, $s1, 0x8
    ctx->r2 = ADD32(ctx->r17, 0X8);
    // 0x80800CF0: addiu       $v1, $zero, 0x16
    ctx->r3 = ADD32(0, 0X16);
L_80800CF4:
    // 0x80800CF4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800CF8: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x80800CFC: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x80800D00: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    // 0x80800D04: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80800D08: bne         $s0, $v1, L_80800CF4
    if (ctx->r16 != ctx->r3) {
        // 0x80800D0C: swc1        $f0, 0x8($v0)
        MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
            goto L_80800CF4;
    }
    // 0x80800D0C: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x80800D10: sh          $zero, 0x84($s1)
    MEM_H(0X84, ctx->r17) = 0;
    // 0x80800D14: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800D18: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800D1C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D20: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800D24: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800D28: jr          $ra
    // 0x80800D2C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800D2C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _bskazpaddle_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083540: syscall     65
    recomp_syscall_handler(rdram, ctx, 0x80083540);
    return;
    // 0x80083544: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _chbiggafoot_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086348: syscall     310
    recomp_syscall_handler(rdram, ctx, 0x80086348);
    return;
    // 0x8008634C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _gzreg_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A958: syscall     880
    recomp_syscall_handler(rdram, ctx, 0x8008A958);
    return;
    // 0x8008A95C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800BD708(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD708: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
    // 0x800BD70C: or          $t3, $a1, $zero
    ctx->r11 = ctx->r5 | 0;
    // 0x800BD710: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800BD714: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800BD718: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BD71C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800BD720: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800BD724: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800BD728: addiu       $t2, $t2, -0x7BF0
    ctx->r10 = ADD32(ctx->r10, -0X7BF0);
    // 0x800BD72C: addiu       $a0, $a0, -0x7BF0
    ctx->r4 = ADD32(ctx->r4, -0X7BF0);
    // 0x800BD730: addiu       $a1, $a1, -0x7BE4
    ctx->r5 = ADD32(ctx->r5, -0X7BE4);
    // 0x800BD734: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x800BD738: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x800BD73C: lwc1        $f14, 0x10($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X10);
L_800BD740:
    // 0x800BD740: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800BD744: lwc1        $f2, 0x0($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800BD748: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800BD74C: nop

    // 0x800BD750: bc1fl       L_800BD764
    if (!c1cs) {
        // 0x800BD754: mov.s       $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
            goto L_800BD764;
    }
    goto skip_0;
    // 0x800BD754: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    skip_0:
    // 0x800BD758: b           L_800BD764
    // 0x800BD75C: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
        goto L_800BD764;
    // 0x800BD75C: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x800BD760: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_800BD764:
    // 0x800BD764: c.le.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl <= ctx->f12.fl;
    // 0x800BD768: sub.s       $f0, $f12, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x800BD76C: bc1fl       L_800BD790
    if (!c1cs) {
        // 0x800BD770: lwc1        $f10, 0x40($a0)
        ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
            goto L_800BD790;
    }
    goto skip_1;
    // 0x800BD770: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    skip_1:
    // 0x800BD774: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x800BD778: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800BD77C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800BD780: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x800BD784: b           L_800BD7A8
    // 0x800BD788: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
        goto L_800BD7A8;
    // 0x800BD788: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x800BD78C: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
L_800BD790:
    // 0x800BD790: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800BD794: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x800BD798: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800BD79C: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x800BD7A0: nop

    // 0x800BD7A4: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
L_800BD7A8:
    // 0x800BD7A8: lw          $v0, 0x4($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X4);
    // 0x800BD7AC: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800BD7B0: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800BD7B4: beql        $at, $zero, L_800BD7C4
    if (ctx->r1 == 0) {
        // 0x800BD7B8: lwc1        $f2, 0x0($t0)
        ctx->f2.u32l = MEM_W(ctx->r8, 0X0);
            goto L_800BD7C4;
    }
    goto skip_2;
    // 0x800BD7B8: lwc1        $f2, 0x0($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X0);
    skip_2:
    // 0x800BD7BC: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    // 0x800BD7C0: lwc1        $f2, 0x0($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X0);
L_800BD7C4:
    // 0x800BD7C4: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800BD7C8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800BD7CC: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x800BD7D0: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800BD7D4: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x800BD7D8: bc1fl       L_800BD7EC
    if (!c1cs) {
        // 0x800BD7DC: mov.s       $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
            goto L_800BD7EC;
    }
    goto skip_3;
    // 0x800BD7DC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    skip_3:
    // 0x800BD7E0: b           L_800BD7EC
    // 0x800BD7E4: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
        goto L_800BD7EC;
    // 0x800BD7E4: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x800BD7E8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_800BD7EC:
    // 0x800BD7EC: add.s       $f2, $f12, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x800BD7F0: c.le.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl <= ctx->f2.fl;
    // 0x800BD7F4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x800BD7F8: bc1fl       L_800BD81C
    if (!c1cs) {
        // 0x800BD7FC: lwc1        $f8, 0x40($a0)
        ctx->f8.u32l = MEM_W(ctx->r4, 0X40);
            goto L_800BD81C;
    }
    goto skip_4;
    // 0x800BD7FC: lwc1        $f8, 0x40($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X40);
    skip_4:
    // 0x800BD800: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    // 0x800BD804: mul.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x800BD808: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800BD80C: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x800BD810: b           L_800BD834
    // 0x800BD814: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
        goto L_800BD834;
    // 0x800BD814: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x800BD818: lwc1        $f8, 0x40($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X40);
L_800BD81C:
    // 0x800BD81C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800BD820: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800BD824: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800BD828: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800BD82C: nop

    // 0x800BD830: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
L_800BD834:
    // 0x800BD834: lw          $v0, 0x10($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X10);
    // 0x800BD838: lw          $t9, 0x0($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X0);
    // 0x800BD83C: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x800BD840: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800BD844: beq         $at, $zero, L_800BD850
    if (ctx->r1 == 0) {
        // 0x800BD848: nop
    
            goto L_800BD850;
    }
    // 0x800BD848: nop

    // 0x800BD84C: sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
L_800BD850:
    // 0x800BD850: bne         $t2, $a1, L_800BD740
    if (ctx->r10 != ctx->r5) {
        // 0x800BD854: addiu       $t3, $t3, 0x4
        ctx->r11 = ADD32(ctx->r11, 0X4);
            goto L_800BD740;
    }
    // 0x800BD854: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // 0x800BD858: jr          $ra
    // 0x800BD85C: nop

    return;
    // 0x800BD85C: nop

;}
RECOMP_FUNC void func_8080086C_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080086C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800870: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800874: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800878: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x8080087C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800880: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800884: sltiu       $at, $t8, 0x9
    ctx->r1 = ctx->r24 < 0X9 ? 1 : 0;
    // 0x80800888: beq         $at, $zero, L_808008B8
    if (ctx->r1 == 0) {
        // 0x8080088C: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808008B8;
    }
    // 0x8080088C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800890: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(804, 0X7C44) << 16);
    // 0x80800894: addu        $at, $at, $t8
    gpr jr_addend_8080089C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800898: lw          $t8, 0x7C44($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(804, 0X7C44));
    // 0x8080089C: jr          $t8
    // 0x808008A0: nop

    switch (jr_addend_8080089C >> 2) {
        case 0: goto L_808008A4; break;
        case 1: goto L_808008C0; break;
        case 2: goto L_808008B8; break;
        case 3: goto L_808008B8; break;
        case 4: goto L_808008C0; break;
        case 5: goto L_808008C0; break;
        case 6: goto L_808008C0; break;
        case 7: goto L_808008C0; break;
        case 8: goto L_808008C0; break;
        default: switch_error(__func__, 0x8080089C, 0x80807C44);
    }
    // 0x808008A0: nop

L_808008A4:
    // 0x808008A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808008A8: jal         0x80803D00
    // 0x808008AC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80803D00_chgameselect(rdram, ctx);
        goto after_0;
    // 0x808008AC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x808008B0: b           L_808008C4
    // 0x808008B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808008C4;
    // 0x808008B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808008B8:
    // 0x808008B8: jal         0x80800478
    // 0x808008BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800478_chgameselect(rdram, ctx);
        goto after_1;
    // 0x808008BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_808008C0:
    // 0x808008C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808008C4:
    // 0x808008C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008C8: jr          $ra
    // 0x808008CC: nop

    return;
    // 0x808008CC: nop

;}
RECOMP_FUNC void bsjig_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: xori        $v0, $a0, 0x44
    ctx->r2 = ctx->r4 ^ 0X44;
    // 0x80800004: jr          $ra
    // 0x80800008: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    return;
    // 0x80800008: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void func_800A2FCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2FCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A2FD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A2FD4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800A2FD8: jal         0x800A2C84
    // 0x800A2FDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800A2C84(rdram, ctx);
        goto after_0;
    // 0x800A2FDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A2FE0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800A2FE4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800A2FE8: lw          $t7, 0x124($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X124);
    // 0x800A2FEC: sb          $t6, 0x4($t7)
    MEM_B(0X4, ctx->r15) = ctx->r14;
    // 0x800A2FF0: lw          $t8, 0x124($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X124);
    // 0x800A2FF4: jal         0x80088A40
    // 0x800A2FF8: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    _fxstep_entrypoint_12(rdram, ctx);
        goto after_1;
    // 0x800A2FF8: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_1:
    // 0x800A2FFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A3000: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A3004: jr          $ra
    // 0x800A3008: nop

    return;
    // 0x800A3008: nop

;}
RECOMP_FUNC void func_80800324_chgoldsnakehead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800324: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800328: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080032C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800330: jal         0x8010A570
    // 0x80800334: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_8010A570(rdram, ctx);
        goto after_0;
    // 0x80800334: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800338: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080033C: jal         0x80101FDC
    // 0x80800340: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x80800340: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80800344: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800348: jal         0x80102FE8
    // 0x8080034C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80102FE8(rdram, ctx);
        goto after_2;
    // 0x8080034C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800350: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800354: jal         0x80103110
    // 0x80800358: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_3;
    // 0x80800358: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8080035C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80800360: jal         0x800DA564
    // 0x80800364: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DA564(rdram, ctx);
        goto after_4;
    // 0x80800364: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x80800368: addiu       $a1, $v0, 0x1
    ctx->r5 = ADD32(ctx->r2, 0X1);
    // 0x8080036C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800370: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80800374: jal         0x800DA7A8
    // 0x80800378: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800DA7A8(rdram, ctx);
        goto after_5;
    // 0x80800378: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_5:
    // 0x8080037C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800380: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800384: addiu       $a0, $zero, 0x10E
    ctx->r4 = ADD32(0, 0X10E);
    // 0x80800388: bne         $t6, $at, L_80800398
    if (ctx->r14 != ctx->r1) {
        // 0x8080038C: addiu       $a1, $zero, 0x7
        ctx->r5 = ADD32(0, 0X7);
            goto L_80800398;
    }
    // 0x8080038C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800390: jal         0x80101180
    // 0x80800394: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_6;
    // 0x80800394: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
L_80800398:
    // 0x80800398: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080039C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003A0: jr          $ra
    // 0x808003A4: nop

    return;
    // 0x808003A4: nop

;}
RECOMP_FUNC void _ncbatarget_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800894A0: syscall     782
    recomp_syscall_handler(rdram, ctx, 0x800894A0);
    return;
    // 0x800894A4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_801125F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801125F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801125F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801125FC: jal         0x800F53D0
    // 0x80112600: nop

    func_800F53D0(rdram, ctx);
        goto after_0;
    // 0x80112600: nop

    after_0:
    // 0x80112604: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80112608: jal         0x8009D2E4
    // 0x8011260C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8009D2E4(rdram, ctx);
        goto after_1;
    // 0x8011260C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80112610: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80112614: jal         0x8009BAF4
    // 0x80112618: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8009BAF4(rdram, ctx);
        goto after_2;
    // 0x80112618: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x8011261C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80112620: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80112624: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80112628: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x8011262C: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80112630: beq         $v0, $zero, L_80112640
    if (ctx->r2 == 0) {
        // 0x80112634: nop
    
            goto L_80112640;
    }
    // 0x80112634: nop

    // 0x80112638: xori        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 ^ 0X2;
    // 0x8011263C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80112640:
    // 0x80112640: jr          $ra
    // 0x80112644: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80112644: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80801338_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801338: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080133C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801340: lbu         $v0, 0x79($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X79);
    // 0x80801344: lw          $v1, 0x18($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X18);
    // 0x80801348: srl         $t6, $v0, 4
    ctx->r14 = S32(U32(ctx->r2) >> 4);
    // 0x8080134C: addu        $a2, $t6, $a1
    ctx->r6 = ADD32(ctx->r14, ctx->r5);
    // 0x80801350: beq         $v1, $zero, L_80801380
    if (ctx->r3 == 0) {
        // 0x80801354: andi        $a3, $t6, 0x3
        ctx->r7 = ctx->r14 & 0X3;
            goto L_80801380;
    }
    // 0x80801354: andi        $a3, $t6, 0x3
    ctx->r7 = ctx->r14 & 0X3;
    // 0x80801358: addiu       $t7, $a2, 0x1
    ctx->r15 = ADD32(ctx->r6, 0X1);
    // 0x8080135C: bne         $t7, $v1, L_80801380
    if (ctx->r15 != ctx->r3) {
        // 0x80801360: nop
    
            goto L_80801380;
    }
    // 0x80801360: nop

    // 0x80801364: bne         $a1, $zero, L_8080137C
    if (ctx->r5 != 0) {
        // 0x80801368: andi        $a3, $a2, 0x3
        ctx->r7 = ctx->r6 & 0X3;
            goto L_8080137C;
    }
    // 0x80801368: andi        $a3, $a2, 0x3
    ctx->r7 = ctx->r6 & 0X3;
    // 0x8080136C: bne         $a2, $zero, L_8080137C
    if (ctx->r6 != 0) {
        // 0x80801370: addiu       $a1, $zero, -0x1
        ctx->r5 = ADD32(0, -0X1);
            goto L_8080137C;
    }
    // 0x80801370: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80801374: b           L_8080137C
    // 0x80801378: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_8080137C;
    // 0x80801378: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8080137C:
    // 0x8080137C: addu        $a2, $a2, $a1
    ctx->r6 = ADD32(ctx->r6, ctx->r5);
L_80801380:
    // 0x80801380: bgez        $a1, L_808013A0
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80801384: nop
    
            goto L_808013A0;
    }
    // 0x80801384: nop

    // 0x80801388: beq         $a3, $zero, L_808013A0
    if (ctx->r7 == 0) {
        // 0x8080138C: nop
    
            goto L_808013A0;
    }
    // 0x8080138C: nop

    // 0x80801390: jal         0x808013C8
    // 0x80801394: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_808013C8_chgameselect(rdram, ctx);
        goto after_0;
    // 0x80801394: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80801398: b           L_808013BC
    // 0x8080139C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808013BC;
    // 0x8080139C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808013A0:
    // 0x808013A0: blez        $a1, L_808013B8
    if (SIGNED(ctx->r5) <= 0) {
        // 0x808013A4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808013B8;
    }
    // 0x808013A4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808013A8: beql        $a3, $at, L_808013BC
    if (ctx->r7 == ctx->r1) {
        // 0x808013AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808013BC;
    }
    goto skip_0;
    // 0x808013AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808013B0: jal         0x808013C8
    // 0x808013B4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_808013C8_chgameselect(rdram, ctx);
        goto after_1;
    // 0x808013B4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_1:
L_808013B8:
    // 0x808013B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808013BC:
    // 0x808013BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808013C0: jr          $ra
    // 0x808013C4: nop

    return;
    // 0x808013C4: nop

;}
RECOMP_FUNC void func_8080412C_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080412C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80804130: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80804134: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80804138: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8080413C: jal         0x80100094
    // 0x80804140: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80804140: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80804144: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1360, 0X45DC) << 16);
    // 0x80804148: lwc1        $f4, 0x45DC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1360, 0X45DC));
    // 0x8080414C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80804150: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80804154: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80804158: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x8080415C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80804160: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80804164: jal         0x800F12D4
    // 0x80804168: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F12D4(rdram, ctx);
        goto after_1;
    // 0x80804168: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8080416C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80804170: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1360, 0X45E0) << 16);
    // 0x80804174: lwc1        $f6, 0x45E0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1360, 0X45E0));
    // 0x80804178: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8080417C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80804180: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x80804184: lwc1        $f12, 0x8($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X8);
    // 0x80804188: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8080418C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80804190: jal         0x800F12D4
    // 0x80804194: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F12D4(rdram, ctx);
        goto after_2;
    // 0x80804194: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x80804198: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080419C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808041A0: jal         0x800DF500
    // 0x808041A4: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    func_800DF500(rdram, ctx);
        goto after_3;
    // 0x808041A4: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x808041A8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808041AC: jal         0x80101870
    // 0x808041B0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80101870(rdram, ctx);
        goto after_4;
    // 0x808041B0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x808041B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808041B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808041BC: jr          $ra
    // 0x808041C0: nop

    return;
    // 0x808041C0: nop

;}
RECOMP_FUNC void func_80807824_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80807824: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80807828: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080782C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80807830: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80807834: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80807838: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080783C: jal         0x80100094
    // 0x80807840: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80807840: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80807844: jal         0x8001211C
    // 0x80807848: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    func_8001211C(rdram, ctx);
        goto after_1;
    // 0x80807848: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    after_1:
    // 0x8080784C: sll         $v1, $v0, 5
    ctx->r3 = S32(ctx->r2 << 5);
    // 0x80807850: andi        $t6, $v1, 0x1FF
    ctx->r14 = ctx->r3 & 0X1FF;
    // 0x80807854: slti        $at, $t6, 0x100
    ctx->r1 = SIGNED(ctx->r14) < 0X100 ? 1 : 0;
    // 0x80807858: bne         $at, $zero, L_80807868
    if (ctx->r1 != 0) {
        // 0x8080785C: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_80807868;
    }
    // 0x8080785C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80807860: addiu       $t7, $zero, 0x200
    ctx->r15 = ADD32(0, 0X200);
    // 0x80807864: subu        $a0, $t7, $t6
    ctx->r4 = SUB32(ctx->r15, ctx->r14);
L_80807868:
    // 0x80807868: lui         $s2, 0x8081
    ctx->r18 = S32(RELOC_HI16(804, 0X8590) << 16);
    // 0x8080786C: addiu       $s2, $s2, -0x7A70
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(804, 0X8590));
    // 0x80807870: bgez        $a0, L_80807880
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80807874: sra         $v0, $a0, 1
        ctx->r2 = S32(SIGNED(ctx->r4) >> 1);
            goto L_80807880;
    }
    // 0x80807874: sra         $v0, $a0, 1
    ctx->r2 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80807878: addiu       $at, $a0, 0x1
    ctx->r1 = ADD32(ctx->r4, 0X1);
    // 0x8080787C: sra         $v0, $at, 1
    ctx->r2 = S32(SIGNED(ctx->r1) >> 1);
L_80807880:
    // 0x80807880: addiu       $v0, $v0, 0x7F
    ctx->r2 = ADD32(ctx->r2, 0X7F);
    // 0x80807884: sh          $v0, 0x4($s2)
    MEM_H(0X4, ctx->r18) = ctx->r2;
    // 0x80807888: sh          $v0, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r2;
    // 0x8080788C: sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
    // 0x80807890: lh          $t8, 0x24($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X24);
    // 0x80807894: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80807898: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
    // 0x8080789C: blezl       $t8, L_808078CC
    if (SIGNED(ctx->r24) <= 0) {
        // 0x808078A0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808078CC;
    }
    goto skip_0;
    // 0x808078A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808078A4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
L_808078A8:
    // 0x808078A8: jal         0x80087BB8
    // 0x808078AC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    _gczoombox_entrypoint_27(rdram, ctx);
        goto after_2;
    // 0x808078AC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x808078B0: lh          $t9, 0x24($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X24);
    // 0x808078B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808078B8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x808078BC: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x808078C0: bnel        $at, $zero, L_808078A8
    if (ctx->r1 != 0) {
        // 0x808078C4: lw          $a0, 0x0($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X0);
            goto L_808078A8;
    }
    goto skip_1;
    // 0x808078C4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    skip_1:
    // 0x808078C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808078CC:
    // 0x808078CC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808078D0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808078D4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808078D8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808078DC: jr          $ra
    // 0x808078E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808078E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80800000_bskazcrouch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: addiu       $a1, $zero, 0x28F
    ctx->r5 = ADD32(0, 0X28F);
    // 0x80800010: jal         0x8008CB3C
    // 0x80800014: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_0;
    // 0x80800014: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_0:
    // 0x80800018: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8080001C: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80800020: sw          $t6, 0x15C($t7)
    MEM_W(0X15C, ctx->r15) = ctx->r14;
    // 0x80800024: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800028: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080002C: jr          $ra
    // 0x80800030: nop

    return;
    // 0x80800030: nop

;}
RECOMP_FUNC void _sccustom_banjo_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A938: syscall     857
    recomp_syscall_handler(rdram, ctx, 0x8008A938);
    return;
    // 0x8008A93C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void chjujubagfx_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1728, 0X470) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x470
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1728, 0X470));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x470
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1728, 0X470));
;}
RECOMP_FUNC void mlspline_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800130: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80800134: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80800138: lwc1        $f2, 0x4($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8080013C: lwc1        $f14, 0x8($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80800140: add.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x80800144: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800148: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080014C: add.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x80800150: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800154: add.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f0.fl;
    // 0x80800158: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8080015C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800160: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800164: nop

    // 0x80800168: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8080016C: nop

    // 0x80800170: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80800174: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80800178: sub.s       $f18, $f10, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x8080017C: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80800180: mul.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80800184: add.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80800188: jr          $ra
    // 0x8080018C: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
    return;
    // 0x8080018C: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_80800360_chfactoryrobot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800360: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800364: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80800368: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080036C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800370: beq         $a1, $at, L_808003CC
    if (ctx->r5 == ctx->r1) {
        // 0x80800374: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_808003CC;
    }
    // 0x80800374: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800378: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8080037C: beq         $a1, $at, L_808003A0
    if (ctx->r5 == ctx->r1) {
        // 0x80800380: addiu       $at, $zero, 0x8F
        ctx->r1 = ADD32(0, 0X8F);
            goto L_808003A0;
    }
    // 0x80800380: addiu       $at, $zero, 0x8F
    ctx->r1 = ADD32(0, 0X8F);
    // 0x80800384: beq         $a1, $at, L_808003E0
    if (ctx->r5 == ctx->r1) {
        // 0x80800388: lw          $t6, 0x20($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X20);
            goto L_808003E0;
    }
    // 0x80800388: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8080038C: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800390: beq         $a1, $at, L_808003F8
    if (ctx->r5 == ctx->r1) {
        // 0x80800394: nop
    
            goto L_808003F8;
    }
    // 0x80800394: nop

    // 0x80800398: b           L_80800414
    // 0x8080039C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800414;
    // 0x8080039C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808003A0:
    // 0x808003A0: lw          $a0, 0x3C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X3C);
    // 0x808003A4: jal         0x80106790
    // 0x808003A8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808003A8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x808003AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808003B0: jal         0x808005D4
    // 0x808003B4: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    func_808005D4_chfactoryrobot(rdram, ctx);
        goto after_1;
    // 0x808003B4: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    after_1:
    // 0x808003B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808003BC: jal         0x80107070
    // 0x808003C0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80107070(rdram, ctx);
        goto after_2;
    // 0x808003C0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x808003C4: b           L_80800414
    // 0x808003C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800414;
    // 0x808003C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003CC:
    // 0x808003CC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808003D0: jal         0x80800424
    // 0x808003D4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_80800424_chfactoryrobot(rdram, ctx);
        goto after_3;
    // 0x808003D4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x808003D8: b           L_80800414
    // 0x808003DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800414;
    // 0x808003DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003E0:
    // 0x808003E0: bnel        $t6, $zero, L_80800414
    if (ctx->r14 != 0) {
        // 0x808003E4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800414;
    }
    goto skip_0;
    // 0x808003E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x808003E8: jal         0x80800508
    // 0x808003EC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80800508_chfactoryrobot(rdram, ctx);
        goto after_4;
    // 0x808003EC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_4:
    // 0x808003F0: b           L_80800414
    // 0x808003F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800414;
    // 0x808003F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003F8:
    // 0x808003F8: jal         0x80800508
    // 0x808003FC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80800508_chfactoryrobot(rdram, ctx);
        goto after_5;
    // 0x808003FC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_5:
    // 0x80800400: b           L_80800414
    // 0x80800404: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800414;
    // 0x80800404: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800408: b           L_80800414
    // 0x8080040C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800414;
    // 0x8080040C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800410: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800414:
    // 0x80800414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800418: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080041C: jr          $ra
    // 0x80800420: nop

    return;
    // 0x80800420: nop

;}
RECOMP_FUNC void func_80103FB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103FB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103FBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80103FC0: jal         0x80103328
    // 0x80103FC4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80103328(rdram, ctx);
        goto after_0;
    // 0x80103FC4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80103FC8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80103FCC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80103FD0: lhu         $t6, 0x6A($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X6A);
    // 0x80103FD4: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80103FD8: bgez        $t6, L_80103FEC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80103FDC: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80103FEC;
    }
    // 0x80103FDC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80103FE0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80103FE4: nop

    // 0x80103FE8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80103FEC:
    // 0x80103FEC: lwc1        $f10, 0x38($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80103FF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80103FF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80103FF8: mul.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80103FFC: jr          $ra
    // 0x80104000: nop

    return;
    // 0x80104000: nop

;}
RECOMP_FUNC void baroll_applyIdeal(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C52C: lw          $v0, 0xF4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XF4);
    // 0x8009C530: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8009C534: jr          $ra
    // 0x8009C538: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x8009C538: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
;}
RECOMP_FUNC void bsvan_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801638: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080163C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(427, 0X1D70) << 16);
    // 0x80801640: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801644: jr          $ra
    // 0x80801648: lw          $v0, 0x1D70($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(427, 0X1D70));
    return;
    // 0x80801648: lw          $v0, 0x1D70($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(427, 0X1D70));
;}
RECOMP_FUNC void func_80800148_chbouncycastle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800148: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080014C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800150: jal         0x801065A4
    // 0x80800154: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_801065A4(rdram, ctx);
        goto after_0;
    // 0x80800154: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800158: beq         $v0, $zero, L_80800168
    if (ctx->r2 == 0) {
        // 0x8080015C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800168;
    }
    // 0x8080015C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800160: jal         0x80088898
    // 0x80800164: nop

    _glidmake_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800164: nop

    after_1:
L_80800168:
    // 0x80800168: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8080016C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800170: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80800174: jal         0x800888A0
    // 0x80800178: lhu         $a0, 0x14($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X14);
    _glidmake_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80800178: lhu         $a0, 0x14($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X14);
    after_2:
    // 0x8080017C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800180: jal         0x8010647C
    // 0x80800184: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8010647C(rdram, ctx);
        goto after_3;
    // 0x80800184: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80800188: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080018C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800190: jr          $ra
    // 0x80800194: nop

    return;
    // 0x80800194: nop

;}
RECOMP_FUNC void func_80800910_bssnowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800910: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800914: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800918: jal         0x80800198
    // 0x8080091C: nop

    bssnowball_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x8080091C: nop

    after_0:
    // 0x80800920: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800924: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800928: jr          $ra
    // 0x8080092C: nop

    return;
    // 0x8080092C: nop

;}
RECOMP_FUNC void chmole_prehist_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1836, 0XF0) << 16);
    // 0x808000B8: jr          $ra
    // 0x808000BC: addiu       $v0, $v0, 0xF0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1836, 0XF0));
    return;
    // 0x808000BC: addiu       $v0, $v0, 0xF0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1836, 0XF0));
;}
