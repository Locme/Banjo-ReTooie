#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800EFFB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EFFB4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800EFFB8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800EFFBC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800EFFC0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800EFFC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EFFC8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800EFFCC: jal         0x800EFB24
    // 0x800EFFD0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800EFB24(rdram, ctx);
        goto after_0;
    // 0x800EFFD0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x800EFFD4: jal         0x800EEFD4
    // 0x800EFFD8: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800EEFD4(rdram, ctx);
        goto after_1;
    // 0x800EFFD8: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x800EFFDC: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800EFFE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EFFE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EFFE8: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800EFFEC: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x800EFFF0: nop

    // 0x800EFFF4: bc1f        L_800F0000
    if (!c1cs) {
        // 0x800EFFF8: nop
    
            goto L_800F0000;
    }
    // 0x800EFFF8: nop

    // 0x800EFFFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F0000:
    // 0x800F0000: jr          $ra
    // 0x800F0004: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800F0004: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void bsdronewaitbabykaz_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800004: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void chwaspnestgame_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(776, 0X1FC8) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x1FC8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(776, 0X1FC8));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x1FC8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(776, 0X1FC8));
;}
RECOMP_FUNC void func_8080038C_chweather(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080038C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800390: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800394: jal         0x8010C500
    // 0x80800398: nop

    func_8010C500(rdram, ctx);
        goto after_0;
    // 0x80800398: nop

    after_0:
    // 0x8080039C: beql        $v0, $zero, L_808003B0
    if (ctx->r2 == 0) {
        // 0x808003A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808003B0;
    }
    goto skip_0;
    // 0x808003A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808003A4: jal         0x800B7DC8
    // 0x808003A8: nop

    func_800B7DC8(rdram, ctx);
        goto after_1;
    // 0x808003A8: nop

    after_1:
    // 0x808003AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003B0:
    // 0x808003B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003B4: jr          $ra
    // 0x808003B8: nop

    return;
    // 0x808003B8: nop

;}
RECOMP_FUNC void func_80800A64_chboggyboy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800A68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800A70: jal         0x80100094
    // 0x80800A74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800A74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800A78: bne         $v0, $zero, L_80800AC0
    if (ctx->r2 != 0) {
        // 0x80800A7C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800AC0;
    }
    // 0x80800A7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800A80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800A84: jal         0x800897C0
    // 0x80800A88: addiu       $a2, $zero, 0x3B
    ctx->r6 = ADD32(0, 0X3B);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x80800A88: addiu       $a2, $zero, 0x3B
    ctx->r6 = ADD32(0, 0X3B);
    after_1:
    // 0x80800A8C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800A90: jal         0x80100094
    // 0x80800A94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80800A94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800A98: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800A9C: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x80800AA0: jal         0x800897E8
    // 0x80800AA4: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_3;
    // 0x80800AA4: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    after_3:
    // 0x80800AA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800AAC: jal         0x80100094
    // 0x80800AB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x80800AB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800AB4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800AB8: jal         0x80089810
    // 0x80800ABC: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    _suexpression_entrypoint_17(rdram, ctx);
        goto after_5;
    // 0x80800ABC: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    after_5:
L_80800AC0:
    // 0x80800AC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800AC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800AC8: jr          $ra
    // 0x80800ACC: nop

    return;
    // 0x80800ACC: nop

;}
RECOMP_FUNC void bastatetimerlist_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091648: jr          $ra
    // 0x8009164C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8009164C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80800864_bstntswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800864: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800868: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080086C: jal         0x800839B8
    // 0x80800870: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsrest_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80800870: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800874: jal         0x80800174
    // 0x80800878: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800174_bstntswim(rdram, ctx);
        goto after_1;
    // 0x80800878: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080087C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800880: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800884: jr          $ra
    // 0x80800888: nop

    return;
    // 0x80800888: nop

;}
RECOMP_FUNC void func_808008C0_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008C8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808008CC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808008D0: jal         0x80100094
    // 0x808008D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808008D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808008D8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x808008DC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808008E0: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x808008E4: sb          $t6, 0xE4($t8)
    MEM_B(0XE4, ctx->r24) = ctx->r14;
    // 0x808008E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008F0: jr          $ra
    // 0x808008F4: nop

    return;
    // 0x808008F4: nop

;}
RECOMP_FUNC void func_8009AE00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009AE00: jr          $ra
    // 0x8009AE04: addiu       $v0, $zero, 0xC4
    ctx->r2 = ADD32(0, 0XC4);
    return;
    // 0x8009AE04: addiu       $v0, $zero, 0xC4
    ctx->r2 = ADD32(0, 0XC4);
;}
RECOMP_FUNC void func_8080050C_chmricecube(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080050C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800510: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800514: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80800518: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080051C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800520: beq         $a1, $at, L_8080055C
    if (ctx->r5 == ctx->r1) {
        // 0x80800524: sw          $a2, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r6;
            goto L_8080055C;
    }
    // 0x80800524: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80800528: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8080052C: beq         $a1, $at, L_808005B8
    if (ctx->r5 == ctx->r1) {
        // 0x80800530: lw          $t7, 0x50($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X50);
            goto L_808005B8;
    }
    // 0x80800530: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80800534: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x80800538: beq         $a1, $at, L_8080063C
    if (ctx->r5 == ctx->r1) {
        // 0x8080053C: addiu       $at, $zero, 0x52
        ctx->r1 = ADD32(0, 0X52);
            goto L_8080063C;
    }
    // 0x8080053C: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x80800540: beq         $a1, $at, L_808006CC
    if (ctx->r5 == ctx->r1) {
        // 0x80800544: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(1224, 0X9A8) << 16);
            goto L_808006CC;
    }
    // 0x80800544: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1224, 0X9A8) << 16);
    // 0x80800548: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x8080054C: beq         $a1, $at, L_808006E0
    if (ctx->r5 == ctx->r1) {
        // 0x80800550: nop
    
            goto L_808006E0;
    }
    // 0x80800550: nop

    // 0x80800554: b           L_80800720
    // 0x80800558: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800720;
    // 0x80800558: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080055C:
    // 0x8080055C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1224, 0X8B0) << 16);
    // 0x80800560: lh          $a1, 0x50($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X50);
    // 0x80800564: addiu       $a2, $a2, 0x8B0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1224, 0X8B0));
    // 0x80800568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080056C: jal         0x8008A1F8
    // 0x80800570: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    _subaddiedialog_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x80800570: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_0:
    // 0x80800574: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800578: bnel        $v0, $at, L_8080058C
    if (ctx->r2 != ctx->r1) {
        // 0x8080057C: lhu         $v0, 0x72($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X72);
            goto L_8080058C;
    }
    goto skip_0;
    // 0x8080057C: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    skip_0:
    // 0x80800580: jal         0x8010A590
    // 0x80800584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_1;
    // 0x80800584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800588: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
L_8080058C:
    // 0x8080058C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800594: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800598: beq         $t6, $at, L_808005A8
    if (ctx->r14 == ctx->r1) {
        // 0x8080059C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808005A8;
    }
    // 0x8080059C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808005A0: bnel        $t6, $at, L_80800720
    if (ctx->r14 != ctx->r1) {
        // 0x808005A4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800720;
    }
    goto skip_1;
    // 0x808005A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
L_808005A8:
    // 0x808005A8: jal         0x80102424
    // 0x808005AC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x808005AC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x808005B0: b           L_80800720
    // 0x808005B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800720;
    // 0x808005B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005B8:
    // 0x808005B8: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x808005BC: jal         0x8010A624
    // 0x808005C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A624(rdram, ctx);
        goto after_3;
    // 0x808005C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808005C4: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x808005C8: jal         0x800EE7F8
    // 0x808005CC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x808005CC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_4:
    // 0x808005D0: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x808005D4: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x808005D8: jal         0x800EF1B8
    // 0x808005DC: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_5;
    // 0x808005DC: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    after_5:
    // 0x808005E0: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x808005E4: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x808005E8: lhu         $a0, 0x1A($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X1A);
    // 0x808005EC: srl         $t9, $a0, 5
    ctx->r25 = S32(U32(ctx->r4) >> 5);
    // 0x808005F0: jal         0x800F77E8
    // 0x808005F4: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_800F77E8(rdram, ctx);
        goto after_6;
    // 0x808005F4: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_6:
    // 0x808005F8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808005FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800600: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800604: jal         0x80085708
    // 0x80800608: addiu       $a3, $zero, 0x831
    ctx->r7 = ADD32(0, 0X831);
    _capod_entrypoint_13(rdram, ctx);
        goto after_7;
    // 0x80800608: addiu       $a3, $zero, 0x831
    ctx->r7 = ADD32(0, 0X831);
    after_7:
    // 0x8080060C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800610: jal         0x80102424
    // 0x80800614: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_8;
    // 0x80800614: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_8:
    // 0x80800618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080061C: jal         0x8008A4B0
    // 0x80800620: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_9;
    // 0x80800620: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80800624: jal         0x8010A570
    // 0x80800628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_10;
    // 0x80800628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8080062C: jal         0x800FC660
    // 0x80800630: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC660(rdram, ctx);
        goto after_11;
    // 0x80800630: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_11:
    // 0x80800634: b           L_80800720
    // 0x80800638: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800720;
    // 0x80800638: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080063C:
    // 0x8080063C: jal         0x800EA05C
    // 0x80800640: nop

    func_800EA05C(rdram, ctx);
        goto after_12;
    // 0x80800640: nop

    after_12:
    // 0x80800644: addiu       $at, $zero, 0x127
    ctx->r1 = ADD32(0, 0X127);
    // 0x80800648: bne         $v0, $at, L_808006C4
    if (ctx->r2 != ctx->r1) {
        // 0x8080064C: nop
    
            goto L_808006C4;
    }
    // 0x8080064C: nop

    // 0x80800650: jal         0x80088840
    // 0x80800654: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_13;
    // 0x80800654: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    after_13:
    // 0x80800658: beq         $v0, $zero, L_808006C4
    if (ctx->r2 == 0) {
        // 0x8080065C: addiu       $a1, $zero, 0x13CC
        ctx->r5 = ADD32(0, 0X13CC);
            goto L_808006C4;
    }
    // 0x8080065C: addiu       $a1, $zero, 0x13CC
    ctx->r5 = ADD32(0, 0X13CC);
    // 0x80800660: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800664: addiu       $t0, $zero, 0xA9
    ctx->r8 = ADD32(0, 0XA9);
    // 0x80800668: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8080066C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800670: jal         0x8008A208
    // 0x80800674: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_14;
    // 0x80800674: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_14:
    // 0x80800678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080067C: jal         0x80102424
    // 0x80800680: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80102424(rdram, ctx);
        goto after_15;
    // 0x80800680: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_15:
    // 0x80800684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800688: jal         0x8008A4B0
    // 0x8080068C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_16;
    // 0x8080068C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x80800690: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800694: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800698: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x8080069C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808006A0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808006A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808006A8: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x808006AC: addiu       $a3, $zero, 0x2831
    ctx->r7 = ADD32(0, 0X2831);
    // 0x808006B0: swc1        $f4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f4.u32l;
    // 0x808006B4: jal         0x80085708
    // 0x808006B8: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    _capod_entrypoint_13(rdram, ctx);
        goto after_17;
    // 0x808006B8: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    after_17:
    // 0x808006BC: b           L_80800720
    // 0x808006C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800720;
    // 0x808006C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006C4:
    // 0x808006C4: b           L_80800720
    // 0x808006C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800720;
    // 0x808006C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808006CC:
    // 0x808006CC: addiu       $a0, $a0, 0x9A8
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1224, 0X9A8));
    // 0x808006D0: jal         0x80088090
    // 0x808006D4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_18;
    // 0x808006D4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_18:
    // 0x808006D8: b           L_80800720
    // 0x808006DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800720;
    // 0x808006DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006E0:
    // 0x808006E0: jal         0x800EA05C
    // 0x808006E4: nop

    func_800EA05C(rdram, ctx);
        goto after_19;
    // 0x808006E4: nop

    after_19:
    // 0x808006E8: addiu       $at, $zero, 0x127
    ctx->r1 = ADD32(0, 0X127);
    // 0x808006EC: bnel        $v0, $at, L_80800720
    if (ctx->r2 != ctx->r1) {
        // 0x808006F0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800720;
    }
    goto skip_2;
    // 0x808006F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x808006F4: jal         0x80088840
    // 0x808006F8: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_20;
    // 0x808006F8: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    after_20:
    // 0x808006FC: bnel        $v0, $zero, L_80800720
    if (ctx->r2 != 0) {
        // 0x80800700: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800720;
    }
    goto skip_3;
    // 0x80800700: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_3:
    // 0x80800704: jal         0x800FFAB0
    // 0x80800708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_21;
    // 0x80800708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x8080070C: b           L_80800720
    // 0x80800710: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800720;
    // 0x80800710: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800714: b           L_80800720
    // 0x80800718: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800720;
    // 0x80800718: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080071C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800720:
    // 0x80800720: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800724: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800728: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8080072C: jr          $ra
    // 0x80800730: nop

    return;
    // 0x80800730: nop

;}
RECOMP_FUNC void fxfontstring_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800074: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800078: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080007C: jal         0x80800000
    // 0x80800080: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80800000_fxfontstring(rdram, ctx);
        goto after_0;
    // 0x80800080: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800084: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800088: addiu       $t6, $zero, 0xFD
    ctx->r14 = ADD32(0, 0XFD);
    // 0x8080008C: addiu       $t7, $zero, 0x61
    ctx->r15 = ADD32(0, 0X61);
    // 0x80800090: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x80800094: sb          $t7, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r15;
    // 0x80800098: bgtz        $a1, L_808000AC
    if (SIGNED(ctx->r5) > 0) {
        // 0x8080009C: addiu       $v1, $v0, 0x2
        ctx->r3 = ADD32(ctx->r2, 0X2);
            goto L_808000AC;
    }
    // 0x8080009C: addiu       $v1, $v0, 0x2
    ctx->r3 = ADD32(ctx->r2, 0X2);
    // 0x808000A0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808000A4: b           L_808000C4
    // 0x808000A8: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
        goto L_808000C4;
    // 0x808000A8: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
L_808000AC:
    // 0x808000AC: slti        $at, $a1, 0x100
    ctx->r1 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    // 0x808000B0: bne         $at, $zero, L_808000C0
    if (ctx->r1 != 0) {
        // 0x808000B4: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_808000C0;
    }
    // 0x808000B4: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x808000B8: b           L_808000C0
    // 0x808000BC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
        goto L_808000C0;
    // 0x808000BC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_808000C0:
    // 0x808000C0: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_808000C4:
    // 0x808000C4: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x808000C8: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x808000CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000D4: jr          $ra
    // 0x808000D8: nop

    return;
    // 0x808000D8: nop

;}
RECOMP_FUNC void _vpflicker_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089050: syscall     757
    recomp_syscall_handler(rdram, ctx, 0x80089050);
    return;
    // 0x80089054: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80114C7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80114C7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80114C80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80114C84: jal         0x8001B084
    // 0x80114C88: nop

    heap_free(rdram, ctx);
        goto after_0;
    // 0x80114C88: nop

    after_0:
    // 0x80114C8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80114C90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80114C94: jr          $ra
    // 0x80114C98: nop

    return;
    // 0x80114C98: nop

;}
RECOMP_FUNC void func_800BF99C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF99C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800BF9A0: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800BF9A4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BF9A8: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800BF9AC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800BF9B0: addiu       $t7, $t7, -0x7A50
    ctx->r15 = ADD32(ctx->r15, -0X7A50);
    // 0x800BF9B4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BF9B8: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800BF9BC: lw          $t8, 0x1C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X1C);
    // 0x800BF9C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800BF9C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BF9C8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800BF9CC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800BF9D0: beq         $t8, $zero, L_800BF9F4
    if (ctx->r24 == 0) {
        // 0x800BF9D4: sw          $t8, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r24;
            goto L_800BF9F4;
    }
    // 0x800BF9D4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800BF9D8: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x800BF9DC: lw          $a1, 0x18($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X18);
    // 0x800BF9E0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800BF9E4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800BF9E8: jal         0x800890D0
    // 0x800BF9EC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    _vpmodule_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x800BF9EC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x800BF9F0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_800BF9F4:
    // 0x800BF9F4: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x800BF9F8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800BF9FC: beql        $a0, $zero, L_800BFA10
    if (ctx->r4 == 0) {
        // 0x800BFA00: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800BFA10;
    }
    goto skip_0;
    // 0x800BFA00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800BFA04: jal         0x80088F58
    // 0x800BFA08: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    _idworldmake_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x800BFA08: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x800BFA0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800BFA10:
    // 0x800BFA10: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800BFA14: jr          $ra
    // 0x800BFA18: nop

    return;
    // 0x800BFA18: nop

;}
RECOMP_FUNC void func_80800118_chblink(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800118: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080011C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800120: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80800124: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80800128: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8080012C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800130: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80800134: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x80800138: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8080013C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800140: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800144: jal         0x800D8FF8
    // 0x80800148: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800148: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    after_0:
    // 0x8080014C: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80800150: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800154: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x80800158: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x8080015C: nop

    // 0x80800160: bc1fl       L_80800208
    if (!c1cs) {
        // 0x80800164: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80800208;
    }
    goto skip_0;
    // 0x80800164: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
L_80800168:
    // 0x80800168: lwc1        $f4, 0x18($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X18);
    // 0x8080016C: sub.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x80800170: swc1        $f6, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f6.u32l;
    // 0x80800174: lwc1        $f12, 0x18($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X18);
    // 0x80800178: c.lt.s      $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f22.fl < ctx->f12.fl;
    // 0x8080017C: nop

    // 0x80800180: bc1tl       L_80800208
    if (c1cs) {
        // 0x80800184: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80800208;
    }
    goto skip_1;
    // 0x80800184: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_1:
    // 0x80800188: jal         0x800F2100
    // 0x8080018C: nop

    mlAbsF(rdram, ctx);
        goto after_1;
    // 0x8080018C: nop

    after_1:
    // 0x80800190: lw          $t6, 0x1C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X1C);
    // 0x80800194: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800198: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080019C: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x808001A0: addu        $s0, $t7, $s2
    ctx->r16 = ADD32(ctx->r15, ctx->r18);
    // 0x808001A4: lbu         $a1, 0x4($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X4);
    // 0x808001A8: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x808001AC: jal         0x808000CC
    // 0x808001B0: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    func_808000CC_chblink(rdram, ctx);
        goto after_2;
    // 0x808001B0: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    after_2:
    // 0x808001B4: lbu         $t8, 0x14($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X14);
    // 0x808001B8: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x808001BC: bnel        $s3, $t8, L_808001EC
    if (ctx->r19 != ctx->r24) {
        // 0x808001C0: lw          $t9, 0x1C($s1)
        ctx->r25 = MEM_W(ctx->r17, 0X1C);
            goto L_808001EC;
    }
    goto skip_2;
    // 0x808001C0: lw          $t9, 0x1C($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X1C);
    skip_2:
    // 0x808001C4: bne         $s4, $zero, L_808001E0
    if (ctx->r20 != 0) {
        // 0x808001C8: or          $s0, $s2, $zero
        ctx->r16 = ctx->r18 | 0;
            goto L_808001E0;
    }
    // 0x808001C8: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x808001CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808001D0: jal         0x80800000
    // 0x808001D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    chblink_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x808001D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808001D8: b           L_80800208
    // 0x808001DC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80800208;
    // 0x808001DC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_808001E0:
    // 0x808001E0: b           L_808001F4
    // 0x808001E4: sw          $zero, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = 0;
        goto L_808001F4;
    // 0x808001E4: sw          $zero, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = 0;
    // 0x808001E8: lw          $t9, 0x1C($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X1C);
L_808001EC:
    // 0x808001EC: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x808001F0: sw          $t0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r8;
L_808001F4:
    // 0x808001F4: c.lt.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
    // 0x808001F8: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x808001FC: bc1t        L_80800168
    if (c1cs) {
        // 0x80800200: swc1        $f8, 0x18($s1)
        MEM_W(0X18, ctx->r17) = ctx->f8.u32l;
            goto L_80800168;
    }
    // 0x80800200: swc1        $f8, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f8.u32l;
    // 0x80800204: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80800208:
    // 0x80800208: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8080020C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800210: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800214: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80800218: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8080021C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80800220: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80800224: jr          $ra
    // 0x80800228: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80800228: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8010347C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010347C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80103480: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80103484: jal         0x80106790
    // 0x80103488: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80103488: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8010348C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80103490: jal         0x80103328
    // 0x80103494: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80103328(rdram, ctx);
        goto after_1;
    // 0x80103494: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80103498: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8010349C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x801034A0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801034A4: lhu         $t7, 0x68($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X68);
    // 0x801034A8: lhu         $a0, 0x14($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X14);
    // 0x801034AC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x801034B0: bgez        $t7, L_801034C4
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801034B4: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801034C4;
    }
    // 0x801034B4: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801034B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801034BC: nop

    // 0x801034C0: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_801034C4:
    // 0x801034C4: lhu         $t8, 0x6A($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X6A);
    // 0x801034C8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801034CC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801034D0: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x801034D4: bgez        $t8, L_801034E8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801034D8: cvt.s.w     $f8, $f8
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
            goto L_801034E8;
    }
    // 0x801034D8: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801034DC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801034E0: nop

    // 0x801034E4: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_801034E8:
    // 0x801034E8: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x801034EC: jal         0x800DF7F8
    // 0x801034F0: nop

    func_800DF7F8(rdram, ctx);
        goto after_2;
    // 0x801034F0: nop

    after_2:
    // 0x801034F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801034F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801034FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80103500: jr          $ra
    // 0x80103504: nop

    return;
    // 0x80103504: nop

;}
RECOMP_FUNC void baattach_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_801128D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801128D4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801128D8: swc1        $f12, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f12.u32l;
    // 0x801128DC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801128E0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801128E4: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x801128E8: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x801128EC: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x801128F0: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801128F4: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x801128F8: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x801128FC: nop

    // 0x80112900: bc1f        L_80112914
    if (!c1cs) {
        // 0x80112904: nop
    
            goto L_80112914;
    }
    // 0x80112904: nop

    // 0x80112908: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8011290C: b           L_80112A70
    // 0x80112910: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
        goto L_80112A70;
    // 0x80112910: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
L_80112914:
    // 0x80112914: jal         0x800D8FF8
    // 0x80112918: nop

    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80112918: nop

    after_0:
    // 0x8011291C: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80112920: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80112924: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80112928: jal         0x800F1DCC
    // 0x8011292C: lwc1        $f14, 0x0($t7)
    ctx->f14.u32l = MEM_W(ctx->r15, 0X0);
    func_800F1DCC(rdram, ctx);
        goto after_1;
    // 0x8011292C: lwc1        $f14, 0x0($t7)
    ctx->f14.u32l = MEM_W(ctx->r15, 0X0);
    after_1:
    // 0x80112930: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80112934: jal         0x800F2100
    // 0x80112938: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_2;
    // 0x80112938: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_2:
    // 0x8011293C: lwc1        $f2, 0x54($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80112940: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80112944: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80112948: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8011294C: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x80112950: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80112954: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80112958: bc1f        L_8011297C
    if (!c1cs) {
        // 0x8011295C: lwc1        $f6, 0x38($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
            goto L_8011297C;
    }
    // 0x8011295C: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80112960: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80112964: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80112968: jal         0x800F1344
    // 0x8011296C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F1344(rdram, ctx);
        goto after_3;
    // 0x8011296C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x80112970: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x80112974: b           L_801129F8
    // 0x80112978: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
        goto L_801129F8;
    // 0x80112978: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
L_8011297C:
    // 0x8011297C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80112980: mul.s       $f2, $f10, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80112984: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    // 0x80112988: nop

    // 0x8011298C: bc1f        L_80112998
    if (!c1cs) {
        // 0x80112990: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_80112998;
    }
    // 0x80112990: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80112994: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
L_80112998:
    // 0x80112998: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8011299C: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x801129A0: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x801129A4: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801129A8: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x801129AC: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x801129B0: nop

    // 0x801129B4: bc1fl       L_801129E4
    if (!c1cs) {
        // 0x801129B8: c.lt.s      $f18, $f2
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
            goto L_801129E4;
    }
    goto skip_0;
    // 0x801129B8: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    skip_0:
    // 0x801129BC: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x801129C0: neg.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = -ctx->f18.fl;
    // 0x801129C4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x801129C8: nop

    // 0x801129CC: bc1fl       L_801129FC
    if (!c1cs) {
        // 0x801129D0: lwc1        $f4, 0x30($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
            goto L_801129FC;
    }
    goto skip_1;
    // 0x801129D0: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    skip_1:
    // 0x801129D4: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x801129D8: b           L_801129F8
    // 0x801129DC: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
        goto L_801129F8;
    // 0x801129DC: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801129E0: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
L_801129E4:
    // 0x801129E4: nop

    // 0x801129E8: bc1fl       L_801129FC
    if (!c1cs) {
        // 0x801129EC: lwc1        $f4, 0x30($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
            goto L_801129FC;
    }
    goto skip_2;
    // 0x801129EC: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    skip_2:
    // 0x801129F0: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    // 0x801129F4: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
L_801129F8:
    // 0x801129F8: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
L_801129FC:
    // 0x801129FC: mul.s       $f12, $f2, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80112A00: jal         0x800F2100
    // 0x80112A04: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    mlAbsF(rdram, ctx);
        goto after_4;
    // 0x80112A04: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    after_4:
    // 0x80112A08: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80112A0C: jal         0x800F2100
    // 0x80112A10: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    mlAbsF(rdram, ctx);
        goto after_5;
    // 0x80112A10: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    after_5:
    // 0x80112A14: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80112A18: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80112A1C: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80112A20: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80112A24: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80112A28: bc1fl       L_80112A5C
    if (!c1cs) {
        // 0x80112A2C: lw          $t9, 0x44($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X44);
            goto L_80112A5C;
    }
    goto skip_3;
    // 0x80112A2C: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    skip_3:
    // 0x80112A30: mul.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x80112A34: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x80112A38: nop

    // 0x80112A3C: bc1fl       L_80112A5C
    if (!c1cs) {
        // 0x80112A40: lw          $t9, 0x44($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X44);
            goto L_80112A5C;
    }
    goto skip_4;
    // 0x80112A40: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    skip_4:
    // 0x80112A44: swc1        $f16, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f16.u32l;
    // 0x80112A48: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80112A4C: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80112A50: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
    // 0x80112A54: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    // 0x80112A58: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
L_80112A5C:
    // 0x80112A5C: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80112A60: jal         0x800136E4
    // 0x80112A64: add.s       $f12, $f6, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f14.fl;
    func_800136E4(rdram, ctx);
        goto after_6;
    // 0x80112A64: add.s       $f12, $f6, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f14.fl;
    after_6:
    // 0x80112A68: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80112A6C: swc1        $f0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f0.u32l;
L_80112A70:
    // 0x80112A70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80112A74: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80112A78: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80112A7C: jr          $ra
    // 0x80112A80: nop

    return;
    // 0x80112A80: nop

;}
RECOMP_FUNC void boot___osSiRawWriteIo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void chklungophial_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1244, 0XC30) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xC30
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1244, 0XC30));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xC30
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1244, 0XC30));
;}
RECOMP_FUNC void func_80801AF0_chstatueboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801AF0: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80801AF4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80801AF8: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1312, 0X2804) << 16);
    // 0x80801AFC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80801B00: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80801B04: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80801B08: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801B0C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80801B10: addiu       $t7, $t7, 0x2804
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1312, 0X2804));
    // 0x80801B14: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80801B18: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80801B1C: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x80801B20: addiu       $t6, $sp, 0x70
    ctx->r14 = ADD32(ctx->r29, 0X70);
    // 0x80801B24: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80801B28: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x80801B2C: lw          $t0, 0xC($t7)
    ctx->r8 = MEM_W(ctx->r15, 0XC);
    // 0x80801B30: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80801B34: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(1312, 0X281C) << 16);
    // 0x80801B38: sw          $t0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r8;
    // 0x80801B3C: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80801B40: lw          $at, 0x10($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X10);
    // 0x80801B44: lw          $t0, 0x14($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X14);
    // 0x80801B48: addiu       $t2, $t2, 0x281C
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(1312, 0X281C));
    // 0x80801B4C: sw          $at, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r1;
    // 0x80801B50: sw          $t0, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r8;
    // 0x80801B54: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x80801B58: addiu       $t1, $sp, 0x5C
    ctx->r9 = ADD32(ctx->r29, 0X5C);
    // 0x80801B5C: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x80801B60: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x80801B64: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x80801B68: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x80801B6C: lw          $t5, 0xC($t2)
    ctx->r13 = MEM_W(ctx->r10, 0XC);
    // 0x80801B70: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    // 0x80801B74: lw          $at, 0x10($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X10);
    // 0x80801B78: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1312, 0X2830) << 16);
    // 0x80801B7C: addiu       $t8, $t8, 0x2830
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1312, 0X2830));
    // 0x80801B80: sw          $t5, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r13;
    // 0x80801B84: sw          $at, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r1;
    // 0x80801B88: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x80801B8C: addiu       $t9, $sp, 0x48
    ctx->r25 = ADD32(ctx->r29, 0X48);
    // 0x80801B90: lw          $t0, 0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X4);
    // 0x80801B94: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
    // 0x80801B98: lw          $at, 0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X8);
    // 0x80801B9C: sw          $t0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r8;
    // 0x80801BA0: lw          $t0, 0xC($t8)
    ctx->r8 = MEM_W(ctx->r24, 0XC);
    // 0x80801BA4: sw          $at, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r1;
    // 0x80801BA8: lw          $at, 0x10($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X10);
    // 0x80801BAC: sw          $t0, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r8;
    // 0x80801BB0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80801BB4: sw          $at, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->r1;
    // 0x80801BB8: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80801BBC: addiu       $s0, $sp, 0x70
    ctx->r16 = ADD32(ctx->r29, 0X70);
    // 0x80801BC0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80801BC4: c.eq.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl == ctx->f4.fl;
    // 0x80801BC8: nop

    // 0x80801BCC: bc1tl       L_80801C60
    if (c1cs) {
        // 0x80801BD0: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80801C60;
    }
    goto skip_0;
    // 0x80801BD0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80801BD4: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80801BD8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_80801BDC:
    // 0x80801BDC: jal         0x80101E14
    // 0x80801BE0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80101E14(rdram, ctx);
        goto after_0;
    // 0x80801BE0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x80801BE4: beq         $v0, $zero, L_80801C40
    if (ctx->r2 == 0) {
        // 0x80801BE8: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1312, 0X2568) << 16);
            goto L_80801C40;
    }
    // 0x80801BE8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1312, 0X2568) << 16);
    // 0x80801BEC: lwc1        $f12, 0x2568($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1312, 0X2568));
    // 0x80801BF0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1312, 0X256C) << 16);
    // 0x80801BF4: jal         0x800DC178
    // 0x80801BF8: lwc1        $f14, 0x256C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1312, 0X256C));
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80801BF8: lwc1        $f14, 0x256C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1312, 0X256C));
    after_1:
    // 0x80801BFC: addu        $t3, $sp, $s1
    ctx->r11 = ADD32(ctx->r29, ctx->r17);
    // 0x80801C00: lwc1        $f6, 0x5C($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X5C);
    // 0x80801C04: jal         0x800C4B64
    // 0x80801C08: add.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f6.fl;
    func_800C4B64(rdram, ctx);
        goto after_2;
    // 0x80801C08: add.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f6.fl;
    after_2:
    // 0x80801C0C: addu        $t1, $sp, $s1
    ctx->r9 = ADD32(ctx->r29, ctx->r17);
    // 0x80801C10: lwc1        $f8, 0x48($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X48);
    // 0x80801C14: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80801C18: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x80801C1C: jal         0x800C4B70
    // 0x80801C20: nop

    func_800C4B70(rdram, ctx);
        goto after_3;
    // 0x80801C20: nop

    after_3:
    // 0x80801C24: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1312, 0X2844) << 16);
    // 0x80801C28: addiu       $a2, $a2, 0x2844
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1312, 0X2844));
    // 0x80801C2C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801C30: jal         0x80089D18
    // 0x80801C34: addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x80801C34: addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    after_4:
    // 0x80801C38: b           L_80801C60
    // 0x80801C3C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80801C60;
    // 0x80801C3C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80801C40:
    // 0x80801C40: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80801C44: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80801C48: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80801C4C: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    // 0x80801C50: nop

    // 0x80801C54: bc1fl       L_80801BDC
    if (!c1cs) {
        // 0x80801C58: mfc1        $a1, $f0
        ctx->r5 = (int32_t)ctx->f0.u32l;
            goto L_80801BDC;
    }
    goto skip_1;
    // 0x80801C58: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    skip_1:
    // 0x80801C5C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80801C60:
    // 0x80801C60: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80801C64: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801C68: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80801C6C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80801C70: jr          $ra
    // 0x80801C74: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80801C74: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void bsjump_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800924: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800928: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080092C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800930: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800934: jal         0x8008CABC
    // 0x80800938: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800938: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x8080093C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800940: jal         0x80098840
    // 0x80800944: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80098840(rdram, ctx);
        goto after_1;
    // 0x80800944: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80800948: jal         0x8008AF24
    // 0x8080094C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_reset(rdram, ctx);
        goto after_2;
    // 0x8080094C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800954: jal         0x8008AED4
    // 0x80800958: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    anctrl_setIndex(rdram, ctx);
        goto after_3;
    // 0x80800958: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_3:
    // 0x8080095C: lui         $a1, 0x3FF3
    ctx->r5 = S32(0X3FF3 << 16);
    // 0x80800960: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80800964: jal         0x8008B1BC
    // 0x80800968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_4;
    // 0x80800968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080096C: lui         $a1, 0x3E09
    ctx->r5 = S32(0X3E09 << 16);
    // 0x80800970: ori         $a1, $a1, 0x374C
    ctx->r5 = ctx->r5 | 0X374C;
    // 0x80800974: jal         0x8008B1C8
    // 0x80800978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008B1C8(rdram, ctx);
        goto after_5;
    // 0x80800978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080097C: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800980: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800984: jal         0x8008B24C
    // 0x80800988: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setStart(rdram, ctx);
        goto after_6;
    // 0x80800988: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080098C: lui         $a2, 0x3F01
    ctx->r6 = S32(0X3F01 << 16);
    // 0x80800990: ori         $a2, $a2, 0x1340
    ctx->r6 = ctx->r6 | 0X1340;
    // 0x80800994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800998: jal         0x8008B1D4
    // 0x8080099C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_7;
    // 0x8080099C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_7:
    // 0x808009A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009A4: jal         0x8008B134
    // 0x808009A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_8;
    // 0x808009A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x808009AC: jal         0x8008B064
    // 0x808009B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_9;
    // 0x808009B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808009B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808009B8: jal         0x8008CA4C
    // 0x808009BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008CA4C(rdram, ctx);
        goto after_10;
    // 0x808009BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x808009C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808009C4: jal         0x8009C908
    // 0x808009C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    yaw_setUpdateType(rdram, ctx);
        goto after_11;
    // 0x808009C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x808009CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808009D0: jal         0x8009D2D8
    // 0x808009D4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8009D2D8(rdram, ctx);
        goto after_12;
    // 0x808009D4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_12:
    // 0x808009D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808009DC: jal         0x8009B800
    // 0x808009E0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    baphysics_set_type(rdram, ctx);
        goto after_13;
    // 0x808009E0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_13:
    // 0x808009E4: jal         0x8009C990
    // 0x808009E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_14;
    // 0x808009E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
    // 0x808009EC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808009F0: jal         0x8009B9C0
    // 0x808009F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_15;
    // 0x808009F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x808009F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808009FC: jal         0x8009B9B0
    // 0x80800A00: lui         $a1, 0x42F0
    ctx->r5 = S32(0X42F0 << 16);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_16;
    // 0x80800A00: lui         $a1, 0x42F0
    ctx->r5 = S32(0X42F0 << 16);
    after_16:
    // 0x80800A04: jal         0x8009C990
    // 0x80800A08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_17;
    // 0x80800A08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_17:
    // 0x80800A0C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80800A10: jal         0x8009BB00
    // 0x80800A14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_18;
    // 0x80800A14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_18:
    // 0x80800A18: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800A1C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800A20: jal         0x8009BA68
    // 0x80800A24: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_19;
    // 0x80800A24: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_19:
    // 0x80800A28: lui         $a1, 0x4431
    ctx->r5 = S32(0X4431 << 16);
    // 0x80800A2C: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x80800A30: jal         0x8009BA58
    // 0x80800A34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_20;
    // 0x80800A34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_20:
    // 0x80800A38: lui         $a1, 0xC4A8
    ctx->r5 = S32(0XC4A8 << 16);
    // 0x80800A3C: ori         $a1, $a1, 0xC000
    ctx->r5 = ctx->r5 | 0XC000;
    // 0x80800A40: jal         0x8009BCB4
    // 0x80800A44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_set_gravity(rdram, ctx);
        goto after_21;
    // 0x80800A44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_21:
    // 0x80800A48: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800A4C: jal         0x800961AC
    // 0x80800A50: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_800961AC(rdram, ctx);
        goto after_22;
    // 0x80800A50: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_22:
    // 0x80800A54: sw          $zero, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = 0;
    // 0x80800A58: jal         0x80800000
    // 0x80800A5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800000_bsjump(rdram, ctx);
        goto after_23;
    // 0x80800A5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_23:
    // 0x80800A60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A64: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800A68: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800A6C: jr          $ra
    // 0x80800A70: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800A70: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _vpscroll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089088: syscall     759
    recomp_syscall_handler(rdram, ctx, 0x80089088);
    return;
    // 0x8008908C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _vpmodule_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800890D0: syscall     761
    recomp_syscall_handler(rdram, ctx, 0x800890D0);
    return;
    // 0x800890D4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800108_chsquits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800108: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080010C: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80800110: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800114: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800118: beq         $a1, $at, L_80800134
    if (ctx->r5 == ctx->r1) {
        // 0x8080011C: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800134;
    }
    // 0x8080011C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800120: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800124: beq         $a1, $at, L_80800148
    if (ctx->r5 == ctx->r1) {
        // 0x80800128: nop
    
            goto L_80800148;
    }
    // 0x80800128: nop

    // 0x8080012C: b           L_80800194
    // 0x80800130: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800194;
    // 0x80800130: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800134:
    // 0x80800134: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800138: jal         0x80101FDC
    // 0x8080013C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_0;
    // 0x8080013C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800140: b           L_80800194
    // 0x80800144: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800194;
    // 0x80800144: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800148:
    // 0x80800148: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1456, 0X5A0) << 16);
    // 0x8080014C: jal         0x800DC298
    // 0x80800150: lwc1        $f12, 0x5A0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1456, 0X5A0));
    func_800DC298(rdram, ctx);
        goto after_1;
    // 0x80800150: lwc1        $f12, 0x5A0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1456, 0X5A0));
    after_1:
    // 0x80800154: bne         $v0, $zero, L_80800178
    if (ctx->r2 != 0) {
        // 0x80800158: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80800178;
    }
    // 0x80800158: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8080015C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800160: jal         0x800BF744
    // 0x80800164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800BF744(rdram, ctx);
        goto after_2;
    // 0x80800164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800168: jal         0x800FFAB0
    // 0x8080016C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_3;
    // 0x8080016C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80800170: b           L_80800194
    // 0x80800174: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800194;
    // 0x80800174: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800178:
    // 0x80800178: jal         0x800BF744
    // 0x8080017C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BF744(rdram, ctx);
        goto after_4;
    // 0x8080017C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800180: b           L_80800194
    // 0x80800184: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800194;
    // 0x80800184: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800188: b           L_80800194
    // 0x8080018C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800194;
    // 0x8080018C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800190: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800194:
    // 0x80800194: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800198: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080019C: jr          $ra
    // 0x808001A0: nop

    return;
    // 0x808001A0: nop

;}
RECOMP_FUNC void vpglow_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800104: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800108: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080010C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800110: jal         0x800D8FF8
    // 0x80800114: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800114: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800118: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8080011C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800120: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800124: lwc1        $f2, 0x4($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80800128: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8080012C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800130: mul.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80800134: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2990, 0X414) << 16);
    // 0x80800138: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080013C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80800140: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800144: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
    // 0x80800148: lwc1        $f12, 0x0($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8080014C: c.le.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl <= ctx->f12.fl;
    // 0x80800150: nop

    // 0x80800154: bc1f        L_8080016C
    if (!c1cs) {
        // 0x80800158: nop
    
            goto L_8080016C;
    }
    // 0x80800158: nop

    // 0x8080015C: neg.s       $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = -ctx->f2.fl;
    // 0x80800160: swc1        $f14, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f14.u32l;
    // 0x80800164: b           L_8080018C
    // 0x80800168: swc1        $f10, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f10.u32l;
        goto L_8080018C;
    // 0x80800168: swc1        $f10, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f10.u32l;
L_8080016C:
    // 0x8080016C: lwc1        $f0, 0x414($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2990, 0X414));
    // 0x80800170: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80800174: nop

    // 0x80800178: bc1fl       L_80800190
    if (!c1cs) {
        // 0x8080017C: lw          $t7, 0x8($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X8);
            goto L_80800190;
    }
    goto skip_0;
    // 0x8080017C: lw          $t7, 0x8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X8);
    skip_0:
    // 0x80800180: neg.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = -ctx->f2.fl;
    // 0x80800184: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
    // 0x80800188: swc1        $f16, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f16.u32l;
L_8080018C:
    // 0x8080018C: lw          $t7, 0x8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X8);
L_80800190:
    // 0x80800190: lw          $t6, 0x1C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X1C);
    // 0x80800194: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800198: blez        $t7, L_808001D0
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8080019C: addu        $a3, $v1, $t6
        ctx->r7 = ADD32(ctx->r3, ctx->r14);
            goto L_808001D0;
    }
    // 0x8080019C: addu        $a3, $v1, $t6
    ctx->r7 = ADD32(ctx->r3, ctx->r14);
    // 0x808001A0: addiu       $v1, $a2, 0xC
    ctx->r3 = ADD32(ctx->r6, 0XC);
    // 0x808001A4: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
L_808001A8:
    // 0x808001A8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x808001AC: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x808001B0: multu       $t8, $a0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808001B4: mflo        $t9
    ctx->r25 = lo;
    // 0x808001B8: addu        $t0, $a3, $t9
    ctx->r8 = ADD32(ctx->r7, ctx->r25);
    // 0x808001BC: sb          $a1, 0x3($t0)
    MEM_B(0X3, ctx->r8) = ctx->r5;
    // 0x808001C0: lw          $t1, 0x8($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X8);
    // 0x808001C4: slt         $at, $v0, $t1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x808001C8: bnel        $at, $zero, L_808001A8
    if (ctx->r1 != 0) {
        // 0x808001CC: lh          $t8, 0x0($v1)
        ctx->r24 = MEM_H(ctx->r3, 0X0);
            goto L_808001A8;
    }
    goto skip_1;
    // 0x808001CC: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    skip_1:
L_808001D0:
    // 0x808001D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001D8: jr          $ra
    // 0x808001DC: nop

    return;
    // 0x808001DC: nop

;}
RECOMP_FUNC void func_800E7E70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E7E70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E7E74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800E7E78: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800E7E7C: jal         0x800E7B88
    // 0x800E7E80: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800E7B88(rdram, ctx);
        goto after_0;
    // 0x800E7E80: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x800E7E84: jal         0x800E7BC8
    // 0x800E7E88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E7BC8(rdram, ctx);
        goto after_1;
    // 0x800E7E88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800E7E8C: jal         0x800E7C28
    // 0x800E7E90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E7C28(rdram, ctx);
        goto after_2;
    // 0x800E7E90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800E7E94: jal         0x800E7CF4
    // 0x800E7E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E7CF4(rdram, ctx);
        goto after_3;
    // 0x800E7E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800E7E9C: jal         0x800E7D4C
    // 0x800E7EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E7D4C(rdram, ctx);
        goto after_4;
    // 0x800E7EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800E7EA4: jal         0x800E7DAC
    // 0x800E7EA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E7DAC(rdram, ctx);
        goto after_5;
    // 0x800E7EA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800E7EAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800E7EB0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800E7EB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800E7EB8: jr          $ra
    // 0x800E7EBC: nop

    return;
    // 0x800E7EBC: nop

;}
RECOMP_FUNC void bsvan_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800F30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F34: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80800F38: jal         0x80800E60
    // 0x80800F3C: addiu       $a1, $a1, 0x2FF8
    ctx->r5 = ADD32(ctx->r5, 0X2FF8);
    func_80800E60_bsvan(rdram, ctx);
        goto after_0;
    // 0x80800F3C: addiu       $a1, $a1, 0x2FF8
    ctx->r5 = ADD32(ctx->r5, 0X2FF8);
    after_0:
    // 0x80800F40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800F44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F48: jr          $ra
    // 0x80800F4C: nop

    return;
    // 0x80800F4C: nop

;}
RECOMP_FUNC void func_800CA7AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA7AC: jr          $ra
    // 0x800CA7B0: addiu       $v0, $a0, 0xA4
    ctx->r2 = ADD32(ctx->r4, 0XA4);
    return;
    // 0x800CA7B0: addiu       $v0, $a0, 0xA4
    ctx->r2 = ADD32(ctx->r4, 0XA4);
;}
RECOMP_FUNC void _bskazshoessuckspline_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800835F0: syscall     68
    recomp_syscall_handler(rdram, ctx, 0x800835F0);
    return;
    // 0x800835F4: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void bsdronebubbled_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002B4: jal         0x80099B94
    // 0x808002B8: nop

    func_80099B94(rdram, ctx);
        goto after_0;
    // 0x808002B8: nop

    after_0:
    // 0x808002BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002C4: jr          $ra
    // 0x808002C8: nop

    return;
    // 0x808002C8: nop

;}
RECOMP_FUNC void func_8001690C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001690C: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x80016910: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80016914: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80016918: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001691C: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80016920: jr          $ra
    // 0x80016924: sw          $a1, -0x6608($at)
    MEM_W(-0X6608, ctx->r1) = ctx->r5;
    return;
    // 0x80016924: sw          $a1, -0x6608($at)
    MEM_W(-0X6608, ctx->r1) = ctx->r5;
;}
RECOMP_FUNC void func_80808F38_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80808F38: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80808F3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80808F40: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80808F44: lw          $t6, 0x188($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X188);
    // 0x80808F48: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80808F4C: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x80808F50: jal         0x800D3948
    // 0x80808F54: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    func_800D3948(rdram, ctx);
        goto after_0;
    // 0x80808F54: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    after_0:
    // 0x80808F58: beq         $v0, $zero, L_80808F90
    if (ctx->r2 == 0) {
        // 0x80808F5C: nop
    
            goto L_80808F90;
    }
    // 0x80808F5C: nop

    // 0x80808F60: jal         0x80088380
    // 0x80808F64: nop

    _gcstatusDll_entrypoint_14(rdram, ctx);
        goto after_1;
    // 0x80808F64: nop

    after_1:
    // 0x80808F68: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80808F6C: bne         $v0, $at, L_80808F90
    if (ctx->r2 != ctx->r1) {
        // 0x80808F70: nop
    
            goto L_80808F90;
    }
    // 0x80808F70: nop

    // 0x80808F74: jal         0x80088388
    // 0x80808F78: nop

    _gcstatusDll_entrypoint_15(rdram, ctx);
        goto after_2;
    // 0x80808F78: nop

    after_2:
    // 0x80808F7C: lw          $t7, 0x184($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X184);
    // 0x80808F80: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80808F84: beq         $v0, $t7, L_80808F90
    if (ctx->r2 == ctx->r15) {
        // 0x80808F88: nop
    
            goto L_80808F90;
    }
    // 0x80808F88: nop

    // 0x80808F8C: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
L_80808F90:
    // 0x80808F90: jal         0x8008E944
    // 0x80808F94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E944(rdram, ctx);
        goto after_3;
    // 0x80808F94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80808F98: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    // 0x80808F9C: jal         0x800F7F98
    // 0x80808FA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F7F98(rdram, ctx);
        goto after_4;
    // 0x80808FA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80808FA4: jal         0x800844E0
    // 0x80808FA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bababykaz_entrypoint_14(rdram, ctx);
        goto after_5;
    // 0x80808FA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80808FAC: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80808FB0: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80808FB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808FB8: bne         $t9, $zero, L_80809018
    if (ctx->r25 != 0) {
        // 0x80808FBC: nop
    
            goto L_80809018;
    }
    // 0x80808FBC: nop

    // 0x80808FC0: lw          $t1, 0xEC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XEC);
    // 0x80808FC4: addiu       $at, $zero, 0x45
    ctx->r1 = ADD32(0, 0X45);
    // 0x80808FC8: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80808FCC: bne         $t1, $at, L_80808FDC
    if (ctx->r9 != ctx->r1) {
        // 0x80808FD0: lw          $t3, 0x44($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X44);
            goto L_80808FDC;
    }
    // 0x80808FD0: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80808FD4: b           L_80809018
    // 0x80808FD8: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
        goto L_80809018;
    // 0x80808FD8: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
L_80808FDC:
    // 0x80808FDC: lw          $v0, 0xF4($t3)
    ctx->r2 = MEM_W(ctx->r11, 0XF4);
    // 0x80808FE0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80808FE4: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80808FE8: beq         $v0, $at, L_80809004
    if (ctx->r2 == ctx->r1) {
        // 0x80808FEC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80809004;
    }
    // 0x80808FEC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80808FF0: beq         $v0, $at, L_8080900C
    if (ctx->r2 == ctx->r1) {
        // 0x80808FF4: addiu       $t5, $zero, 0x4
        ctx->r13 = ADD32(0, 0X4);
            goto L_8080900C;
    }
    // 0x80808FF4: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80808FF8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80808FFC: beq         $v0, $at, L_80809014
    if (ctx->r2 == ctx->r1) {
        // 0x80809000: addiu       $t6, $zero, 0x5
        ctx->r14 = ADD32(0, 0X5);
            goto L_80809014;
    }
    // 0x80809000: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
L_80809004:
    // 0x80809004: b           L_80809018
    // 0x80809008: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
        goto L_80809018;
    // 0x80809008: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
L_8080900C:
    // 0x8080900C: b           L_80809018
    // 0x80809010: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
        goto L_80809018;
    // 0x80809010: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
L_80809014:
    // 0x80809014: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
L_80809018:
    // 0x80809018: jal         0x8009C128
    // 0x8080901C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_8009C128(rdram, ctx);
        goto after_6;
    // 0x8080901C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_6:
    // 0x80809020: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80809024: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80809028: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x8080902C: jal         0x800F1E6C
    // 0x80809030: addiu       $a0, $a0, 0xF8
    ctx->r4 = ADD32(ctx->r4, 0XF8);
    func_800F1E6C(rdram, ctx);
        goto after_7;
    // 0x80809030: addiu       $a0, $a0, 0xF8
    ctx->r4 = ADD32(ctx->r4, 0XF8);
    after_7:
    // 0x80809034: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80809038: lui         $t9, 0x8081
    ctx->r25 = S32(RELOC_HI16(439, 0XA650) << 16);
    // 0x8080903C: addiu       $t9, $t9, -0x59B0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(439, 0XA650));
    // 0x80809040: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80809044: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80809048: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8080904C: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x80809050: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x80809054: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80809058: jal         0x8009B9B0
    // 0x8080905C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_8;
    // 0x8080905C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80809060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80809064: jal         0x8009B9C0
    // 0x80809068: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    baphysics_set_target_yaw(rdram, ctx);
        goto after_9;
    // 0x80809068: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_9:
    // 0x8080906C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80809070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80809074: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80809078: jal         0x8009BA68
    // 0x8080907C: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_10;
    // 0x8080907C: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    after_10:
    // 0x80809080: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80809084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80809088: jal         0x8009BA58
    // 0x8080908C: lw          $a1, 0x4($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X4);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_11;
    // 0x8080908C: lw          $a1, 0x4($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X4);
    after_11:
    // 0x80809090: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80809094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80809098: jal         0x8009BCB4
    // 0x8080909C: lw          $a1, 0x8($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X8);
    baphysics_set_gravity(rdram, ctx);
        goto after_12;
    // 0x8080909C: lw          $a1, 0x8($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X8);
    after_12:
    // 0x808090A0: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x808090A4: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x808090A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808090AC: lwc1        $f4, 0xC($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0XC);
    // 0x808090B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808090B4: jal         0x8080911C
    // 0x808090B8: swc1        $f4, 0x10C($t4)
    MEM_W(0X10C, ctx->r12) = ctx->f4.u32l;
    func_8080911C_bsfirstp(rdram, ctx);
        goto after_13;
    // 0x808090B8: swc1        $f4, 0x10C($t4)
    MEM_W(0X10C, ctx->r12) = ctx->f4.u32l;
    after_13:
    // 0x808090BC: jal         0x8009C974
    // 0x808090C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_applyIdeal(rdram, ctx);
        goto after_14;
    // 0x808090C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808090C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808090C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808090CC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808090D0: jr          $ra
    // 0x808090D4: nop

    return;
    // 0x808090D4: nop

;}
RECOMP_FUNC void func_808036E4_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808036E4: jr          $ra
    // 0x808036E8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x808036E8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80021794(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021794: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80021798: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x8002179C: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800217A0: lw          $t6, 0x11F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11F4);
    // 0x800217A4: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x800217A8: beq         $t7, $zero, L_800217DC
    if (ctx->r15 == 0) {
        // 0x800217AC: nop
    
            goto L_800217DC;
    }
    // 0x800217AC: nop

    // 0x800217B0: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x800217B4: lw          $t8, 0x11F4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X11F4);
    // 0x800217B8: lw          $t9, 0x2C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X2C);
    // 0x800217BC: sw          $t9, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r25;
    // 0x800217C0: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x800217C4: lw          $t0, 0x11F4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X11F4);
    // 0x800217C8: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x800217CC: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800217D0: sw          $t2, 0x2C($t0)
    MEM_W(0X2C, ctx->r8) = ctx->r10;
    // 0x800217D4: lw          $t3, 0x4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4);
    // 0x800217D8: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
L_800217DC:
    // 0x800217DC: b           L_800217EC
    // 0x800217E0: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
        goto L_800217EC;
    // 0x800217E0: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
    // 0x800217E4: b           L_800217EC
    // 0x800217E8: nop

        goto L_800217EC;
    // 0x800217E8: nop

L_800217EC:
    // 0x800217EC: jr          $ra
    // 0x800217F0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800217F0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void _ncbaswim_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089328: syscall     773
    recomp_syscall_handler(rdram, ctx, 0x80089328);
    return;
    // 0x8008932C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_808027A8_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808027A8: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x808027AC: lui         $t8, 0x8081
    ctx->r24 = S32(RELOC_HI16(439, 0XAC24) << 16);
    // 0x808027B0: addiu       $t8, $t8, -0x53DC
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(439, 0XAC24));
    // 0x808027B4: addiu       $t7, $t6, -0x10
    ctx->r15 = ADD32(ctx->r14, -0X10);
    // 0x808027B8: jr          $ra
    // 0x808027BC: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    return;
    // 0x808027BC: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
;}
RECOMP_FUNC void func_80801014_chnests(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801014: lw          $v1, 0x6C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X6C);
    // 0x80801018: sll         $t6, $v1, 11
    ctx->r14 = S32(ctx->r3 << 11);
    // 0x8080101C: srl         $t7, $t6, 20
    ctx->r15 = S32(U32(ctx->r14) >> 20);
    // 0x80801020: xori        $v0, $t7, 0x1C8
    ctx->r2 = ctx->r15 ^ 0X1C8;
    // 0x80801024: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80801028: bne         $v0, $zero, L_80801098
    if (ctx->r2 != 0) {
        // 0x8080102C: nop
    
            goto L_80801098;
    }
    // 0x8080102C: nop

    // 0x80801030: xori        $v0, $t7, 0x1C9
    ctx->r2 = ctx->r15 ^ 0X1C9;
    // 0x80801034: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80801038: bne         $v0, $zero, L_80801098
    if (ctx->r2 != 0) {
        // 0x8080103C: nop
    
            goto L_80801098;
    }
    // 0x8080103C: nop

    // 0x80801040: xori        $v0, $t7, 0x1CA
    ctx->r2 = ctx->r15 ^ 0X1CA;
    // 0x80801044: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80801048: bne         $v0, $zero, L_80801098
    if (ctx->r2 != 0) {
        // 0x8080104C: nop
    
            goto L_80801098;
    }
    // 0x8080104C: nop

    // 0x80801050: xori        $v0, $t7, 0x1CB
    ctx->r2 = ctx->r15 ^ 0X1CB;
    // 0x80801054: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80801058: bne         $v0, $zero, L_80801098
    if (ctx->r2 != 0) {
        // 0x8080105C: nop
    
            goto L_80801098;
    }
    // 0x8080105C: nop

    // 0x80801060: xori        $v0, $t7, 0x1CC
    ctx->r2 = ctx->r15 ^ 0X1CC;
    // 0x80801064: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80801068: bne         $v0, $zero, L_80801098
    if (ctx->r2 != 0) {
        // 0x8080106C: nop
    
            goto L_80801098;
    }
    // 0x8080106C: nop

    // 0x80801070: xori        $v0, $t7, 0x1CD
    ctx->r2 = ctx->r15 ^ 0X1CD;
    // 0x80801074: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80801078: bne         $v0, $zero, L_80801098
    if (ctx->r2 != 0) {
        // 0x8080107C: nop
    
            goto L_80801098;
    }
    // 0x8080107C: nop

    // 0x80801080: xori        $v0, $t7, 0x2B8
    ctx->r2 = ctx->r15 ^ 0X2B8;
    // 0x80801084: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80801088: bne         $v0, $zero, L_80801098
    if (ctx->r2 != 0) {
        // 0x8080108C: nop
    
            goto L_80801098;
    }
    // 0x8080108C: nop

    // 0x80801090: xori        $v0, $t7, 0x1E9
    ctx->r2 = ctx->r15 ^ 0X1E9;
    // 0x80801094: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80801098:
    // 0x80801098: jr          $ra
    // 0x8080109C: nop

    return;
    // 0x8080109C: nop

;}
RECOMP_FUNC void _chblink_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800857B0: syscall     175
    recomp_syscall_handler(rdram, ctx, 0x800857B0);
    return;
    // 0x800857B4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void bskazstill_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808006BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808006C0: jal         0x800832E0
    // 0x808006C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _bskaz_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808006C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808006C8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x808006CC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808006D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808006D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808006D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808006DC: jal         0x8009FFD8
    // 0x808006E0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x808006E0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x808006E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808006E8: jal         0x8009B9B0
    // 0x808006EC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x808006EC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x808006F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808006F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808006F8: jr          $ra
    // 0x808006FC: nop

    return;
    // 0x808006FC: nop

;}
RECOMP_FUNC void func_80800330_subaddiestore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800330: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800334: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800338: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080033C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800340: lw          $s0, 0x6C($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X6C);
    // 0x80800344: addiu       $s1, $sp, 0x28
    ctx->r17 = ADD32(ctx->r29, 0X28);
    // 0x80800348: srl         $t6, $s0, 21
    ctx->r14 = S32(U32(ctx->r16) >> 21);
    // 0x8080034C: bne         $t6, $zero, L_8080035C
    if (ctx->r14 != 0) {
        // 0x80800350: or          $s0, $t6, $zero
        ctx->r16 = ctx->r14 | 0;
            goto L_8080035C;
    }
    // 0x80800350: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x80800354: b           L_80800398
    // 0x80800358: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800398;
    // 0x80800358: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080035C:
    // 0x8080035C: jal         0x801067C4
    // 0x80800360: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_801067C4(rdram, ctx);
        goto after_0;
    // 0x80800360: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x80800364: beql        $v0, $zero, L_80800398
    if (ctx->r2 == 0) {
        // 0x80800368: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800398;
    }
    goto skip_0;
    // 0x80800368: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x8080036C: lw          $t7, 0x6C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X6C);
L_80800370:
    // 0x80800370: srl         $t8, $t7, 21
    ctx->r24 = S32(U32(ctx->r15) >> 21);
    // 0x80800374: bne         $s0, $t8, L_80800384
    if (ctx->r16 != ctx->r24) {
        // 0x80800378: nop
    
            goto L_80800384;
    }
    // 0x80800378: nop

    // 0x8080037C: b           L_80800398
    // 0x80800380: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800398;
    // 0x80800380: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800384:
    // 0x80800384: jal         0x8010682C
    // 0x80800388: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8010682C(rdram, ctx);
        goto after_1;
    // 0x80800388: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8080038C: bnel        $v0, $zero, L_80800370
    if (ctx->r2 != 0) {
        // 0x80800390: lw          $t7, 0x6C($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X6C);
            goto L_80800370;
    }
    goto skip_1;
    // 0x80800390: lw          $t7, 0x6C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X6C);
    skip_1:
    // 0x80800394: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800398:
    // 0x80800398: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080039C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808003A0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808003A4: jr          $ra
    // 0x808003A8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808003A8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_808002AC_bsbanshack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002B4: lbu         $t6, 0x15D($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X15D);
    // 0x808002B8: beq         $t6, $zero, L_808002D0
    if (ctx->r14 == 0) {
        // 0x808002BC: nop
    
            goto L_808002D0;
    }
    // 0x808002BC: nop

    // 0x808002C0: jal         0x80800164
    // 0x808002C4: nop

    func_80800164_bsbanshack(rdram, ctx);
        goto after_0;
    // 0x808002C4: nop

    after_0:
    // 0x808002C8: b           L_80800300
    // 0x808002CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800300;
    // 0x808002CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002D0:
    // 0x808002D0: jal         0x80084508
    // 0x808002D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _babackpack_get_state(rdram, ctx);
        goto after_1;
    // 0x808002D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x808002D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808002DC: beq         $v0, $at, L_808002FC
    if (ctx->r2 == ctx->r1) {
        // 0x808002E0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808002FC;
    }
    // 0x808002E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808002E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808002E8: jal         0x800A0CD0
    // 0x808002EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800A0CD0(rdram, ctx);
        goto after_2;
    // 0x808002EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x808002F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808002F4: jal         0x80084538
    // 0x808002F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _babackpack_set_state(rdram, ctx);
        goto after_3;
    // 0x808002F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
L_808002FC:
    // 0x808002FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800300:
    // 0x80800300: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800304: jr          $ra
    // 0x80800308: nop

    return;
    // 0x80800308: nop

;}
RECOMP_FUNC void _ncba1p_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089418: syscall     777
    recomp_syscall_handler(rdram, ctx, 0x80089418);
    return;
    // 0x8008941C: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void _chlightdemon_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085D58: syscall     235
    recomp_syscall_handler(rdram, ctx, 0x80085D58);
    return;
    // 0x80085D5C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808006B4_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006BC: sb          $a1, 0x169($a0)
    MEM_B(0X169, ctx->r4) = ctx->r5;
    // 0x808006C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808006C4: jal         0x80095760
    // 0x808006C8: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    baflag_set(rdram, ctx);
        goto after_0;
    // 0x808006C8: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    after_0:
    // 0x808006CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808006D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808006D4: jal         0x8009E55C
    // 0x808006D8: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    func_8009E55C(rdram, ctx);
        goto after_1;
    // 0x808006D8: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    after_1:
    // 0x808006DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808006E4: jr          $ra
    // 0x808006E8: nop

    return;
    // 0x808006E8: nop

;}
RECOMP_FUNC void func_8080000C_chgobiwitchy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800018: jal         0x80089828
    // 0x8080001C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _suexpression_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x8080001C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800020: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800024: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800028: jal         0x800897D8
    // 0x8080002C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x8080002C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80800030: jal         0x80086770
    // 0x80800034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chgobicommon_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80800034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800038: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8080003C: lui         $a1, 0x4370
    ctx->r5 = S32(0X4370 << 16);
    // 0x80800040: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800044: jal         0x8008FB10
    // 0x80800048: lui         $a3, 0x4316
    ctx->r7 = S32(0X4316 << 16);
    func_8008FB10(rdram, ctx);
        goto after_3;
    // 0x80800048: lui         $a3, 0x4316
    ctx->r7 = S32(0X4316 << 16);
    after_3:
    // 0x8080004C: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x80800050: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800054: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x80800058: beq         $t6, $at, L_80800078
    if (ctx->r14 == ctx->r1) {
        // 0x8080005C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800078;
    }
    // 0x8080005C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800060: beq         $t6, $at, L_808000C8
    if (ctx->r14 == ctx->r1) {
        // 0x80800064: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808000C8;
    }
    // 0x80800064: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800068: beq         $t6, $at, L_80800088
    if (ctx->r14 == ctx->r1) {
        // 0x8080006C: nop
    
            goto L_80800088;
    }
    // 0x8080006C: nop

    // 0x80800070: b           L_808000C8
    // 0x80800074: nop

        goto L_808000C8;
    // 0x80800074: nop

L_80800078:
    // 0x80800078: jal         0x808002DC
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002DC_chgobiwitchy(rdram, ctx);
        goto after_4;
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800080: b           L_808000C8
    // 0x80800084: nop

        goto L_808000C8;
    // 0x80800084: nop

L_80800088:
    // 0x80800088: jal         0x80105834
    // 0x8080008C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105834(rdram, ctx);
        goto after_5;
    // 0x8080008C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800090: jal         0x80105A5C
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_6;
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800098: beq         $v0, $zero, L_808000C8
    if (ctx->r2 == 0) {
        // 0x8080009C: nop
    
            goto L_808000C8;
    }
    // 0x8080009C: nop

    // 0x808000A0: jal         0x800FFAB0
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_7;
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808000A8: jal         0x80085710
    // 0x808000AC: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_8;
    // 0x808000AC: nop

    after_8:
    // 0x808000B0: jal         0x80088238
    // 0x808000B4: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    _gclevel_entrypoint_3(rdram, ctx);
        goto after_9;
    // 0x808000B4: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_9:
    // 0x808000B8: beq         $v0, $zero, L_808000C8
    if (ctx->r2 == 0) {
        // 0x808000BC: addiu       $a0, $zero, 0x127
        ctx->r4 = ADD32(0, 0X127);
            goto L_808000C8;
    }
    // 0x808000BC: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    // 0x808000C0: jal         0x800887D8
    // 0x808000C4: addiu       $a1, $zero, 0x47
    ctx->r5 = ADD32(0, 0X47);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_10;
    // 0x808000C4: addiu       $a1, $zero, 0x47
    ctx->r5 = ADD32(0, 0X47);
    after_10:
L_808000C8:
    // 0x808000C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(844, 0X3B0) << 16);
    // 0x808000CC: lwc1        $f6, 0x3B0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(844, 0X3B0));
    // 0x808000D0: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000DC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808000E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808000E4: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x808000E8: jal         0x80085778
    // 0x808000EC: nop

    _chbadshad_entrypoint_2(rdram, ctx);
        goto after_11;
    // 0x808000EC: nop

    after_11:
    // 0x808000F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000FC: jr          $ra
    // 0x80800100: nop

    return;
    // 0x80800100: nop

;}
RECOMP_FUNC void func_800CB764(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB764: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CB768: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800CB76C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800CB770: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800CB774: addiu       $t7, $t7, -0x5490
    ctx->r15 = ADD32(ctx->r15, -0X5490);
    // 0x800CB778: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x800CB77C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CB780: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800CB784: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800CB788: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800CB78C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800CB790: addiu       $a0, $v0, 0x8
    ctx->r4 = ADD32(ctx->r2, 0X8);
    // 0x800CB794: jal         0x800EE7F8
    // 0x800CB798: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800CB798: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x800CB79C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800CB7A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CB7A4: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800CB7A8: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800CB7AC: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800CB7B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CB7B4: swc1        $f4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f4.u32l;
    // 0x800CB7B8: sh          $t8, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r24;
    // 0x800CB7BC: jr          $ra
    // 0x800CB7C0: sh          $t9, 0x1A($v0)
    MEM_H(0X1A, ctx->r2) = ctx->r25;
    return;
    // 0x800CB7C0: sh          $t9, 0x1A($v0)
    MEM_H(0X1A, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void func_800EA09C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA09C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800EA0A0: jr          $ra
    // 0x800EA0A4: lh          $v0, 0x2DC0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2DC0);
    return;
    // 0x800EA0A4: lh          $v0, 0x2DC0($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2DC0);
;}
RECOMP_FUNC void func_800F4244(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F4244: jr          $ra
    // 0x800F4248: lw          $v0, 0x17C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X17C);
    return;
    // 0x800F4248: lw          $v0, 0x17C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X17C);
;}
RECOMP_FUNC void func_808000B8_chtntblockage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808000BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000C0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808000C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000CC: beq         $a1, $at, L_808000F0
    if (ctx->r5 == ctx->r1) {
        // 0x808000D0: sw          $a2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r6;
            goto L_808000F0;
    }
    // 0x808000D0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x808000D4: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x808000D8: beq         $a1, $at, L_80800138
    if (ctx->r5 == ctx->r1) {
        // 0x808000DC: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_80800138;
    }
    // 0x808000DC: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808000E0: beq         $a1, $at, L_80800148
    if (ctx->r5 == ctx->r1) {
        // 0x808000E4: nop
    
            goto L_80800148;
    }
    // 0x808000E4: nop

    // 0x808000E8: b           L_80800170
    // 0x808000EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800170;
    // 0x808000EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000F0:
    // 0x808000F0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x808000F4: jal         0x800EE7F8
    // 0x808000F8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808000F8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_0:
    // 0x808000FC: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800100: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80800104: jal         0x800EF1B8
    // 0x80800108: lui         $a2, 0xC396
    ctx->r6 = S32(0XC396 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_1;
    // 0x80800108: lui         $a2, 0xC396
    ctx->r6 = S32(0XC396 << 16);
    after_1:
    // 0x8080010C: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x80800110: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800114: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080011C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80800120: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800124: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800128: jal         0x80086670
    // 0x8080012C: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x8080012C: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x80800130: b           L_80800170
    // 0x80800134: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800170;
    // 0x80800134: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800138:
    // 0x80800138: jal         0x80800184
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800184_chtntblockage(rdram, ctx);
        goto after_3;
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800140: b           L_80800170
    // 0x80800144: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800170;
    // 0x80800144: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800148:
    // 0x80800148: jal         0x808000A8
    // 0x8080014C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000A8_chtntblockage(rdram, ctx);
        goto after_4;
    // 0x8080014C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800154: jal         0x80085D28
    // 0x80800158: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _chtntdetonator_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x80800158: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x8080015C: b           L_80800170
    // 0x80800160: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800170;
    // 0x80800160: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800164: b           L_80800170
    // 0x80800168: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800170;
    // 0x80800168: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080016C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800170:
    // 0x80800170: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800174: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800178: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080017C: jr          $ra
    // 0x80800180: nop

    return;
    // 0x80800180: nop

;}
