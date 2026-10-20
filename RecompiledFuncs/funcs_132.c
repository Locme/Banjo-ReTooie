#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void glzone_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800044: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800048: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080004C: jal         0x8001B084
    // 0x80800050: nop

    heap_free(rdram, ctx);
        goto after_0;
    // 0x80800050: nop

    after_0:
    // 0x80800054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800058: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080005C: jr          $ra
    // 0x80800060: nop

    return;
    // 0x80800060: nop

;}
RECOMP_FUNC void subaddieDll_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080042C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800430: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800434: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800438: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8080043C: lw          $t6, 0x70($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X70);
    // 0x80800440: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800444: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    // 0x80800448: srl         $t7, $t6, 25
    ctx->r15 = S32(U32(ctx->r14) >> 25);
    // 0x8080044C: bne         $t7, $zero, L_8080045C
    if (ctx->r15 != 0) {
        // 0x80800450: addiu       $a0, $sp, 0x1C
        ctx->r4 = ADD32(ctx->r29, 0X1C);
            goto L_8080045C;
    }
    // 0x80800450: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80800454: b           L_808004CC
    // 0x80800458: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004CC;
    // 0x80800458: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080045C:
    // 0x8080045C: jal         0x800EE7F8
    // 0x80800460: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800460: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800464: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80800468: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8080046C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80800470: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80800474: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80800478: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080047C: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800480: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80800484: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80800488: jal         0x800EF1B8
    // 0x8080048C: nop

    func_800EF1B8(rdram, ctx);
        goto after_1;
    // 0x8080048C: nop

    after_1:
    // 0x80800490: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80800494: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80800498: lw          $v0, 0x70($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X70);
    // 0x8080049C: sll         $a2, $v0, 22
    ctx->r6 = S32(ctx->r2 << 22);
    // 0x808004A0: srl         $t1, $a2, 26
    ctx->r9 = S32(U32(ctx->r6) >> 26);
    // 0x808004A4: srl         $a1, $v0, 25
    ctx->r5 = S32(U32(ctx->r2) >> 25);
    // 0x808004A8: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x808004AC: jal         0x800CC338
    // 0x808004B0: addiu       $a2, $t1, -0x1
    ctx->r6 = ADD32(ctx->r9, -0X1);
    func_800CC338(rdram, ctx);
        goto after_2;
    // 0x808004B0: addiu       $a2, $t1, -0x1
    ctx->r6 = ADD32(ctx->r9, -0X1);
    after_2:
    // 0x808004B4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808004B8: bnel        $v0, $at, L_808004CC
    if (ctx->r2 != ctx->r1) {
        // 0x808004BC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808004CC;
    }
    goto skip_0;
    // 0x808004BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x808004C0: b           L_808004CC
    // 0x808004C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808004CC;
    // 0x808004C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808004C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004CC:
    // 0x808004CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808004D4: jr          $ra
    // 0x808004D8: nop

    return;
    // 0x808004D8: nop

;}
RECOMP_FUNC void func_80800034_chmole_training(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800034: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800038: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080003C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800040: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800044: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800048: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x8080004C: beq         $t6, $at, L_80800064
    if (ctx->r14 == ctx->r1) {
        // 0x80800050: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80800064;
    }
    // 0x80800050: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800054: beq         $t6, $at, L_80800064
    if (ctx->r14 == ctx->r1) {
        // 0x80800058: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80800064;
    }
    // 0x80800058: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8080005C: bnel        $t6, $at, L_8080007C
    if (ctx->r14 != ctx->r1) {
        // 0x80800060: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080007C;
    }
    goto skip_0;
    // 0x80800060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_80800064:
    // 0x80800064: jal         0x80100094
    // 0x80800068: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800068: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080006C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800070: jal         0x80087CA0
    // 0x80800074: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _gcnewoption_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800074: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
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
RECOMP_FUNC void func_80800A88_chnutsnbolts(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800A8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A90: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800A94: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800A98: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800A9C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800AA0: jal         0x80100094
    // 0x80800AA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800AA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800AA8: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x80800AAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AB0: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80800AB4: bgezl       $t8, L_80800AD0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800AB8: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_80800AD0;
    }
    goto skip_0;
    // 0x80800AB8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_0:
    // 0x80800ABC: jal         0x8080092C
    // 0x80800AC0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_8080092C_chnutsnbolts(rdram, ctx);
        goto after_1;
    // 0x80800AC0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80800AC4: b           L_80800B6C
    // 0x80800AC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B6C;
    // 0x80800AC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800ACC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_80800AD0:
    // 0x80800AD0: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800AD4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800AD8: nop

    // 0x80800ADC: bc1fl       L_80800AF0
    if (!c1cs) {
        // 0x80800AE0: lbu         $t9, 0x16($v0)
        ctx->r25 = MEM_BU(ctx->r2, 0X16);
            goto L_80800AF0;
    }
    goto skip_1;
    // 0x80800AE0: lbu         $t9, 0x16($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X16);
    skip_1:
    // 0x80800AE4: b           L_80800B6C
    // 0x80800AE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800B6C;
    // 0x80800AE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800AEC: lbu         $t9, 0x16($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X16);
L_80800AF0:
    // 0x80800AF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AF4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80800AF8: beq         $t9, $zero, L_80800B10
    if (ctx->r25 == 0) {
        // 0x80800AFC: nop
    
            goto L_80800B10;
    }
    // 0x80800AFC: nop

    // 0x80800B00: jal         0x8080092C
    // 0x80800B04: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_8080092C_chnutsnbolts(rdram, ctx);
        goto after_2;
    // 0x80800B04: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80800B08: b           L_80800B6C
    // 0x80800B0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B6C;
    // 0x80800B0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B10:
    // 0x80800B10: bnel        $t0, $zero, L_80800B38
    if (ctx->r8 != 0) {
        // 0x80800B14: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80800B38;
    }
    goto skip_2;
    // 0x80800B14: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    skip_2:
    // 0x80800B18: jal         0x80089F78
    // 0x80800B1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80800B1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800B20: beq         $v0, $zero, L_80800B68
    if (ctx->r2 == 0) {
        // 0x80800B24: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1304, 0XCB0) << 16);
            goto L_80800B68;
    }
    // 0x80800B24: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1304, 0XCB0) << 16);
    // 0x80800B28: jal         0x800DC298
    // 0x80800B2C: lwc1        $f12, 0xCB0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1304, 0XCB0));
    func_800DC298(rdram, ctx);
        goto after_4;
    // 0x80800B2C: lwc1        $f12, 0xCB0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1304, 0XCB0));
    after_4:
    // 0x80800B30: beq         $v0, $zero, L_80800B68
    if (ctx->r2 == 0) {
        // 0x80800B34: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80800B68;
    }
    // 0x80800B34: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
L_80800B38:
    // 0x80800B38: jal         0x8010C9B0
    // 0x80800B3C: addiu       $a1, $zero, 0x5DC
    ctx->r5 = ADD32(0, 0X5DC);
    func_8010C9B0(rdram, ctx);
        goto after_5;
    // 0x80800B3C: addiu       $a1, $zero, 0x5DC
    ctx->r5 = ADD32(0, 0X5DC);
    after_5:
    // 0x80800B40: beql        $v0, $zero, L_80800B6C
    if (ctx->r2 == 0) {
        // 0x80800B44: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800B6C;
    }
    goto skip_3;
    // 0x80800B44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x80800B48: jal         0x8010C500
    // 0x80800B4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C500(rdram, ctx);
        goto after_6;
    // 0x80800B4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800B50: beq         $v0, $zero, L_80800B68
    if (ctx->r2 == 0) {
        // 0x80800B54: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B68;
    }
    // 0x80800B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B58: jal         0x8080092C
    // 0x80800B5C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_8080092C_chnutsnbolts(rdram, ctx);
        goto after_7;
    // 0x80800B5C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_7:
    // 0x80800B60: b           L_80800B6C
    // 0x80800B64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B6C;
    // 0x80800B64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B68:
    // 0x80800B68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800B6C:
    // 0x80800B6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B70: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800B74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800B78: jr          $ra
    // 0x80800B7C: nop

    return;
    // 0x80800B7C: nop

;}
RECOMP_FUNC void func_800F586C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F586C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5870: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F5874: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5878: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F587C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5880: jal         0x80098B5C
    // 0x800F5884: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_80098B5C(rdram, ctx);
        goto after_0;
    // 0x800F5884: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F5888: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F588C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F5890: jr          $ra
    // 0x800F5894: nop

    return;
    // 0x800F5894: nop

;}
RECOMP_FUNC void func_800F543C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F543C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5440: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F5444: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5448: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F544C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5450: jal         0x800A3274
    // 0x800F5454: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_800A3274(rdram, ctx);
        goto after_0;
    // 0x800F5454: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F5458: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F545C: addiu       $t7, $v0, 0x1F
    ctx->r15 = ADD32(ctx->r2, 0X1F);
    // 0x800F5460: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800F5464: sllv        $v0, $t8, $t7
    ctx->r2 = S32(ctx->r24 << (ctx->r15 & 31));
    // 0x800F5468: jr          $ra
    // 0x800F546C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800F546C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800965D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800965D4: lw          $t6, 0x94($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X94);
    // 0x800965D8: jr          $ra
    // 0x800965DC: lw          $v0, 0x50($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X50);
    return;
    // 0x800965DC: lw          $v0, 0x50($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X50);
;}
RECOMP_FUNC void chfog_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A34: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1620, 0XA90) << 16);
    // 0x80800A38: jr          $ra
    // 0x80800A3C: addiu       $v0, $v0, 0xA90
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1620, 0XA90));
    return;
    // 0x80800A3C: addiu       $v0, $v0, 0xA90
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1620, 0XA90));
;}
RECOMP_FUNC void sucoaster_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000CC: jal         0x80100094
    // 0x808000D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808000D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808000D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000D8: jal         0x80802728
    // 0x808000DC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80802728_sucoaster(rdram, ctx);
        goto after_1;
    // 0x808000DC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x808000E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000E8: jr          $ra
    // 0x808000EC: nop

    return;
    // 0x808000EC: nop

;}
RECOMP_FUNC void func_80800E80_chboggyfatboy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800E84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800E88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800E8C: jal         0x801022E4
    // 0x80800E90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_801022E4(rdram, ctx);
        goto after_0;
    // 0x80800E90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800E94: addiu       $at, $zero, 0x246
    ctx->r1 = ADD32(0, 0X246);
    // 0x80800E98: bne         $v0, $at, L_80800F2C
    if (ctx->r2 != ctx->r1) {
        // 0x80800E9C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800F2C;
    }
    // 0x80800E9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EA0: jal         0x80101E14
    // 0x80800EA4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80101E14(rdram, ctx);
        goto after_1;
    // 0x80800EA4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x80800EA8: beq         $v0, $zero, L_80800EE0
    if (ctx->r2 == 0) {
        // 0x80800EAC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800EE0;
    }
    // 0x80800EAC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800EB0: jal         0x800DC128
    // 0x80800EB4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800DC128(rdram, ctx);
        goto after_2;
    // 0x80800EB4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_2:
    // 0x80800EB8: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x80800EBC: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1540, 0X12A0) << 16);
    // 0x80800EC0: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x80800EC4: jal         0x800C4B7C
    // 0x80800EC8: lh          $a0, 0x12A0($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(1540, 0X12A0));
    func_800C4B7C(rdram, ctx);
        goto after_3;
    // 0x80800EC8: lh          $a0, 0x12A0($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(1540, 0X12A0));
    after_3:
    // 0x80800ECC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1540, 0X12BC) << 16);
    // 0x80800ED0: addiu       $a2, $a2, 0x12BC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1540, 0X12BC));
    // 0x80800ED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800ED8: jal         0x80089D18
    // 0x80800EDC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x80800EDC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_4:
L_80800EE0:
    // 0x80800EE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EE4: jal         0x80101E14
    // 0x80800EE8: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_80101E14(rdram, ctx);
        goto after_5;
    // 0x80800EE8: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_5:
    // 0x80800EEC: beq         $v0, $zero, L_80800F04
    if (ctx->r2 == 0) {
        // 0x80800EF0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800F04;
    }
    // 0x80800EF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EF4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1540, 0X12CC) << 16);
    // 0x80800EF8: addiu       $a2, $a2, 0x12CC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1540, 0X12CC));
    // 0x80800EFC: jal         0x80089D18
    // 0x80800F00: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80800F00: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_6:
L_80800F04:
    // 0x80800F04: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1540, 0X12AC) << 16);
    // 0x80800F08: addiu       $a1, $a1, 0x12AC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1540, 0X12AC));
    // 0x80800F0C: jal         0x80101E4C
    // 0x80800F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E4C(rdram, ctx);
        goto after_7;
    // 0x80800F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800F14: beq         $v0, $zero, L_80800F2C
    if (ctx->r2 == 0) {
        // 0x80800F18: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800F2C;
    }
    // 0x80800F18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F1C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1540, 0X12E8) << 16);
    // 0x80800F20: addiu       $a2, $a2, 0x12E8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1540, 0X12E8));
    // 0x80800F24: jal         0x80089D18
    // 0x80800F28: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x80800F28: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_8:
L_80800F2C:
    // 0x80800F2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800F30: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800F34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800F38: jr          $ra
    // 0x80800F3C: nop

    return;
    // 0x80800F3C: nop

;}
RECOMP_FUNC void func_800CCDF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CCDF4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800CCDF8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800CCDFC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800CCE00: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800CCE04: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800CCE08: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800CCE0C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800CCE10: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800CCE14: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800CCE18: bne         $v1, $t6, L_800CCE44
    if (ctx->r3 != ctx->r14) {
        // 0x800CCE1C: or          $s1, $a2, $zero
        ctx->r17 = ctx->r6 | 0;
            goto L_800CCE44;
    }
    // 0x800CCE1C: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800CCE20: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800CCE24: jal         0x800CBDD4
    // 0x800CCE28: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    func_800CBDD4(rdram, ctx);
        goto after_0;
    // 0x800CCE28: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    after_0:
    // 0x800CCE2C: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800CCE30: bne         $v0, $v1, L_800CCE44
    if (ctx->r2 != ctx->r3) {
        // 0x800CCE34: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_800CCE44;
    }
    // 0x800CCE34: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800CCE38: sw          $v1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r3;
    // 0x800CCE3C: b           L_800CCEE0
    // 0x800CCE40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800CCEE0;
    // 0x800CCE40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CCE44:
    // 0x800CCE44: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800CCE48: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800CCE4C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800CCE50: bne         $v1, $v0, L_800CCE60
    if (ctx->r3 != ctx->r2) {
        // 0x800CCE54: lw          $t7, 0x38($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X38);
            goto L_800CCE60;
    }
    // 0x800CCE54: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800CCE58: b           L_800CCE64
    // 0x800CCE5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_800CCE64;
    // 0x800CCE5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800CCE60:
    // 0x800CCE60: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_800CCE64:
    // 0x800CCE64: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x800CCE68: jal         0x800CCAB0
    // 0x800CCE6C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_800CCAB0(rdram, ctx);
        goto after_1;
    // 0x800CCE6C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_1:
    // 0x800CCE70: bltz        $v0, L_800CCE80
    if (SIGNED(ctx->r2) < 0) {
        // 0x800CCE74: sw          $v0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r2;
            goto L_800CCE80;
    }
    // 0x800CCE74: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x800CCE78: b           L_800CCEE0
    // 0x800CCE7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800CCEE0;
    // 0x800CCE7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800CCE80:
    // 0x800CCE80: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800CCE84: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800CCE88: jal         0x800CBDD4
    // 0x800CCE8C: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    func_800CBDD4(rdram, ctx);
        goto after_2;
    // 0x800CCE8C: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x800CCE90: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800CCE94: bne         $v0, $v1, L_800CCEA8
    if (ctx->r2 != ctx->r3) {
        // 0x800CCE98: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_800CCEA8;
    }
    // 0x800CCE98: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800CCE9C: sw          $v1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r3;
    // 0x800CCEA0: b           L_800CCEE0
    // 0x800CCEA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800CCEE0;
    // 0x800CCEA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CCEA8:
    // 0x800CCEA8: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800CCEAC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800CCEB0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800CCEB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CCEB8: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x800CCEBC: jal         0x800CCAB0
    // 0x800CCEC0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_800CCAB0(rdram, ctx);
        goto after_3;
    // 0x800CCEC0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_3:
    // 0x800CCEC4: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800CCEC8: bltz        $v0, L_800CCED8
    if (SIGNED(ctx->r2) < 0) {
        // 0x800CCECC: sw          $v0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r2;
            goto L_800CCED8;
    }
    // 0x800CCECC: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x800CCED0: b           L_800CCEE0
    // 0x800CCED4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800CCEE0;
    // 0x800CCED4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800CCED8:
    // 0x800CCED8: sw          $v1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r3;
    // 0x800CCEDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CCEE0:
    // 0x800CCEE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800CCEE4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800CCEE8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800CCEEC: jr          $ra
    // 0x800CCEF0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800CCEF0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_808001A8_chfriendlystonehead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001AC: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x808001B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001B4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808001B8: beq         $a1, $at, L_808001E0
    if (ctx->r5 == ctx->r1) {
        // 0x808001BC: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_808001E0;
    }
    // 0x808001BC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808001C0: addiu       $at, $zero, 0x2F
    ctx->r1 = ADD32(0, 0X2F);
    // 0x808001C4: beq         $a1, $at, L_808001F4
    if (ctx->r5 == ctx->r1) {
        // 0x808001C8: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_808001F4;
    }
    // 0x808001C8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808001CC: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x808001D0: beq         $a1, $at, L_80800208
    if (ctx->r5 == ctx->r1) {
        // 0x808001D4: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(1876, 0X968) << 16);
            goto L_80800208;
    }
    // 0x808001D4: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1876, 0X968) << 16);
    // 0x808001D8: b           L_80800228
    // 0x808001DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800228;
    // 0x808001DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808001E0:
    // 0x808001E0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808001E4: jal         0x80102424
    // 0x808001E8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x808001E8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x808001EC: b           L_80800228
    // 0x808001F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800228;
    // 0x808001F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001F4:
    // 0x808001F4: lh          $a1, 0x20($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X20);
    // 0x808001F8: jal         0x808006C4
    // 0x808001FC: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    func_808006C4_chfriendlystonehead(rdram, ctx);
        goto after_1;
    // 0x808001FC: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    after_1:
    // 0x80800200: b           L_80800228
    // 0x80800204: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800228;
    // 0x80800204: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800208:
    // 0x80800208: addiu       $a0, $a0, 0x968
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1876, 0X968));
    // 0x8080020C: jal         0x80088090
    // 0x80800210: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800210: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    after_2:
    // 0x80800214: b           L_80800228
    // 0x80800218: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800228;
    // 0x80800218: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080021C: b           L_80800228
    // 0x80800220: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800228;
    // 0x80800220: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800224: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800228:
    // 0x80800228: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080022C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800230: jr          $ra
    // 0x80800234: nop

    return;
    // 0x80800234: nop

;}
RECOMP_FUNC void _chboggykids_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085CE0: syscall     226
    recomp_syscall_handler(rdram, ctx, 0x80085CE0);
    return;
    // 0x80085CE4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800A04_chvolcanobits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A04: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800A08: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800A0C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800A10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800A14: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800A18: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80800A1C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80800A20: beq         $a1, $at, L_80800A3C
    if (ctx->r5 == ctx->r1) {
        // 0x80800A24: sw          $s1, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r17;
            goto L_80800A3C;
    }
    // 0x80800A24: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800A28: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80800A2C: beql        $a1, $at, L_80800A80
    if (ctx->r5 == ctx->r1) {
        // 0x80800A30: lhu         $s2, 0x76($s0)
        ctx->r18 = MEM_HU(ctx->r16, 0X76);
            goto L_80800A80;
    }
    goto skip_0;
    // 0x80800A30: lhu         $s2, 0x76($s0)
    ctx->r18 = MEM_HU(ctx->r16, 0X76);
    skip_0:
    // 0x80800A34: b           L_80800ABC
    // 0x80800A38: nop

        goto L_80800ABC;
    // 0x80800A38: nop

L_80800A3C:
    // 0x80800A3C: lhu         $t6, 0x76($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X76);
    // 0x80800A40: addiu       $at, $zero, 0x37
    ctx->r1 = ADD32(0, 0X37);
    // 0x80800A44: addiu       $a0, $zero, 0x3E
    ctx->r4 = ADD32(0, 0X3E);
    // 0x80800A48: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800A4C: bne         $t7, $at, L_80800A64
    if (ctx->r15 != ctx->r1) {
        // 0x80800A50: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80800A64;
    }
    // 0x80800A50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800A54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800A58: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800A5C: jal         0x800D1000
    // 0x80800A60: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D1000(rdram, ctx);
        goto after_0;
    // 0x80800A60: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
L_80800A64:
    // 0x80800A64: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80800A68: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80800A6C: jal         0x8010114C
    // 0x80800A70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010114C(rdram, ctx);
        goto after_1;
    // 0x80800A70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80800A74: b           L_80800AD0
    // 0x80800A78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800AD0;
    // 0x80800A78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800A7C: lhu         $s2, 0x76($s0)
    ctx->r18 = MEM_HU(ctx->r16, 0X76);
L_80800A80:
    // 0x80800A80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A84: srl         $t8, $s2, 7
    ctx->r24 = S32(U32(ctx->r18) >> 7);
    // 0x80800A88: jal         0x801015D0
    // 0x80800A8C: addiu       $s2, $t8, -0x32
    ctx->r18 = ADD32(ctx->r24, -0X32);
    func_801015D0(rdram, ctx);
        goto after_2;
    // 0x80800A8C: addiu       $s2, $t8, -0x32
    ctx->r18 = ADD32(ctx->r24, -0X32);
    after_2:
    // 0x80800A90: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800A94: addiu       $s3, $zero, 0x6
    ctx->r19 = ADD32(0, 0X6);
L_80800A98:
    // 0x80800A98: addiu       $s1, $s0, 0x1
    ctx->r17 = ADD32(ctx->r16, 0X1);
    // 0x80800A9C: xor         $a1, $s2, $s0
    ctx->r5 = ctx->r18 ^ ctx->r16;
    // 0x80800AA0: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    // 0x80800AA4: jal         0x800DF744
    // 0x80800AA8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800DF744(rdram, ctx);
        goto after_3;
    // 0x80800AA8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80800AAC: bne         $s1, $s3, L_80800A98
    if (ctx->r17 != ctx->r19) {
        // 0x80800AB0: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80800A98;
    }
    // 0x80800AB0: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80800AB4: b           L_80800AD0
    // 0x80800AB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800AD0;
    // 0x80800AB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800ABC:
    // 0x80800ABC: jal         0x80085820
    // 0x80800AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chswitch_entrypoint_10(rdram, ctx);
        goto after_4;
    // 0x80800AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800AC4: b           L_80800AD4
    // 0x80800AC8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800AD4;
    // 0x80800AC8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800ACC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800AD0:
    // 0x80800AD0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800AD4:
    // 0x80800AD4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800AD8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800ADC: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80800AE0: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80800AE4: jr          $ra
    // 0x80800AE8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800AE8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8009FBB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009FBB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009FBB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009FBB8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8009FBBC: jal         0x800964DC
    // 0x8009FBC0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800964DC(rdram, ctx);
        goto after_0;
    // 0x8009FBC0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8009FBC4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8009FBC8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8009FBCC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8009FBD0: jal         0x800889D0
    // 0x8009FBD4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    _fxairbub_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x8009FBD4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8009FBD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009FBDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009FBE0: jr          $ra
    // 0x8009FBE4: nop

    return;
    // 0x8009FBE4: nop

;}
RECOMP_FUNC void func_80020738(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020738: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8002073C: beq         $a0, $zero, L_80020750
    if (ctx->r4 == 0) {
        // 0x80020740: nop
    
            goto L_80020750;
    }
    // 0x80020740: nop

    // 0x80020744: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80020748: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8002074C: sb          $t7, 0x40($a0)
    MEM_B(0X40, ctx->r4) = ctx->r15;
L_80020750:
    // 0x80020750: jr          $ra
    // 0x80020754: nop

    return;
    // 0x80020754: nop

;}
RECOMP_FUNC void _chboggyboy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086860: syscall     390
    recomp_syscall_handler(rdram, ctx, 0x80086860);
    return;
    // 0x80086864: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808006E0_gcboundDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006E8: jal         0x808006A8
    // 0x808006EC: nop

    func_808006A8_gcboundDll(rdram, ctx);
        goto after_0;
    // 0x808006EC: nop

    after_0:
    // 0x808006F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808006F8: jr          $ra
    // 0x808006FC: nop

    return;
    // 0x808006FC: nop

;}
RECOMP_FUNC void func_80801734_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801734: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801738: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8080173C: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80801740: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801744: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80801748: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8080174C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80801750: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80801754: jal         0x80100094
    // 0x80801758: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801758: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080175C: lbu         $t6, 0x3A($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X3A);
    // 0x80801760: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80801764: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801768: blez        $t6, L_80801790
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8080176C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80801790;
    }
    // 0x8080176C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80801770:
    // 0x80801770: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80801774: jal         0x80801808
    // 0x80801778: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_80801808_chstoneballcontrol(rdram, ctx);
        goto after_1;
    // 0x80801778: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_1:
    // 0x8080177C: lbu         $t7, 0x3A($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X3A);
    // 0x80801780: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80801784: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80801788: bnel        $at, $zero, L_80801770
    if (ctx->r1 != 0) {
        // 0x8080178C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80801770;
    }
    goto skip_0;
    // 0x8080178C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
L_80801790:
    // 0x80801790: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801794: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801798: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080179C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808017A0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808017A4: jr          $ra
    // 0x808017A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808017A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8080021C_bsdronevanish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080021C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800220: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800224: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800228: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8080022C: lw          $t6, 0x188($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X188);
    // 0x80800230: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800234: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800238: swc1        $f0, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f0.u32l;
    // 0x8080023C: lw          $t7, 0x188($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X188);
    // 0x80800240: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800244: swc1        $f0, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f0.u32l;
    // 0x80800248: lw          $t8, 0x188($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X188);
    // 0x8080024C: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x80800250: jal         0x800B53A4
    // 0x80800254: swc1        $f4, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f4.u32l;
    func_800B53A4(rdram, ctx);
        goto after_0;
    // 0x80800254: swc1        $f4, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f4.u32l;
    after_0:
    // 0x80800258: lw          $t9, 0x188($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X188);
    // 0x8080025C: addiu       $a1, $zero, 0x9E5
    ctx->r5 = ADD32(0, 0X9E5);
    // 0x80800260: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x80800264: lw          $t0, 0x188($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X188);
    // 0x80800268: jal         0x8080019C
    // 0x8080026C: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    func_8080019C_bsdronevanish(rdram, ctx);
        goto after_1;
    // 0x8080026C: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    after_1:
    // 0x80800270: jal         0x800B53A4
    // 0x80800274: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    func_800B53A4(rdram, ctx);
        goto after_2;
    // 0x80800274: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_2:
    // 0x80800278: lw          $t1, 0x188($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X188);
    // 0x8080027C: addiu       $a1, $zero, 0x9E2
    ctx->r5 = ADD32(0, 0X9E2);
    // 0x80800280: sw          $v0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r2;
    // 0x80800284: lw          $t2, 0x188($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X188);
    // 0x80800288: jal         0x8080019C
    // 0x8080028C: lw          $a0, 0x4($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X4);
    func_8080019C_bsdronevanish(rdram, ctx);
        goto after_3;
    // 0x8080028C: lw          $a0, 0x4($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X4);
    after_3:
    // 0x80800290: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800294: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800298: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080029C: jr          $ra
    // 0x808002A0: nop

    return;
    // 0x808002A0: nop

;}
RECOMP_FUNC void subaddieskeleton_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800198: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080019C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001A0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808001A4: jal         0x80106790
    // 0x808001A8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808001A8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x808001AC: lw          $t6, 0x7C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X7C);
    // 0x808001B0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x808001B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001B8: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x808001BC: bgezl       $t8, L_808001F0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808001C0: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_808001F0;
    }
    goto skip_0;
    // 0x808001C0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_0:
    // 0x808001C4: jal         0x8080020C
    // 0x808001C8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    subaddieskeleton_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x808001C8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808001CC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x808001D0: beq         $v0, $zero, L_808001EC
    if (ctx->r2 == 0) {
        // 0x808001D4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808001EC;
    }
    // 0x808001D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001D8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808001DC: jal         0x800DBEFC
    // 0x808001E0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    func_800DBEFC(rdram, ctx);
        goto after_2;
    // 0x808001E0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x808001E4: b           L_808001FC
    // 0x808001E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808001FC;
    // 0x808001E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001EC:
    // 0x808001EC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_808001F0:
    // 0x808001F0: jal         0x800EE7F8
    // 0x808001F4: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x808001F4: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    after_3:
    // 0x808001F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808001FC:
    // 0x808001FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800200: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800204: jr          $ra
    // 0x80800208: nop

    return;
    // 0x80800208: nop

;}
RECOMP_FUNC void func_80800370_chalienkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800370: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800374: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800378: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080037C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80800380: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800384: jal         0x80100094
    // 0x80800388: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800388: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080038C: lw          $t6, 0x2C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2C);
    // 0x80800390: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80800394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800398: beq         $t6, $zero, L_808003EC
    if (ctx->r14 == 0) {
        // 0x8080039C: nop
    
            goto L_808003EC;
    }
    // 0x8080039C: nop

    // 0x808003A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003A4: jal         0x80089CD8
    // 0x808003A8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    _subaddiefade_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x808003A8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808003AC: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x808003B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003B4: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x808003B8: jal         0x80086598
    // 0x808003BC: lw          $a1, 0x2C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X2C);
    _chlifeforcespell_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808003BC: lw          $a1, 0x2C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X2C);
    after_2:
    // 0x808003C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003C4: jal         0x80089CE8
    // 0x808003C8: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    _subaddiefade_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x808003C8: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_3:
    // 0x808003CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003D0: jal         0x80800D58
    // 0x808003D4: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_80800D58_chalienkids(rdram, ctx);
        goto after_4;
    // 0x808003D4: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_4:
    // 0x808003D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003DC: jal         0x80089CE8
    // 0x808003E0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    _subaddiefade_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x808003E0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_5:
    // 0x808003E4: b           L_808003F8
    // 0x808003E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808003F8;
    // 0x808003E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808003EC:
    // 0x808003EC: jal         0x80800D58
    // 0x808003F0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_80800D58_chalienkids(rdram, ctx);
        goto after_6;
    // 0x808003F0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_6:
    // 0x808003F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808003F8:
    // 0x808003F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003FC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800400: jr          $ra
    // 0x80800404: nop

    return;
    // 0x80800404: nop

;}
RECOMP_FUNC void bstrexsmall_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800434: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800438: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(416, 0X1B08) << 16);
    // 0x8080043C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800440: jr          $ra
    // 0x80800444: lw          $v0, 0x1B08($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(416, 0X1B08));
    return;
    // 0x80800444: lw          $v0, 0x1B08($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(416, 0X1B08));
;}
RECOMP_FUNC void func_80800508_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800508: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080050C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800510: lbu         $t6, 0x15E($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X15E);
    // 0x80800514: bne         $t6, $zero, L_80800528
    if (ctx->r14 != 0) {
        // 0x80800518: nop
    
            goto L_80800528;
    }
    // 0x80800518: nop

    // 0x8080051C: jal         0x808002D4
    // 0x80800520: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808002D4_bsbansack(rdram, ctx);
        goto after_0;
    // 0x80800520: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800524: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80800528:
    // 0x80800528: jal         0x80800238
    // 0x8080052C: nop

    func_80800238_bsbansack(rdram, ctx);
        goto after_1;
    // 0x8080052C: nop

    after_1:
    // 0x80800530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800534: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800538: jr          $ra
    // 0x8080053C: nop

    return;
    // 0x8080053C: nop

;}
RECOMP_FUNC void boot_osCreateThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void subaddiedraw25d_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lbu         $t7, 0x7E($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X7E);
    // 0x80800004: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x80800008: jr          $ra
    // 0x8080000C: sb          $t8, 0x7E($a0)
    MEM_B(0X7E, ctx->r4) = ctx->r24;
    return;
    // 0x8080000C: sb          $t8, 0x7E($a0)
    MEM_B(0X7E, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_80801780_chfpsgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801780: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801784: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801788: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080178C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801790: jal         0x80100094
    // 0x80801794: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801794: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801798: jal         0x800EB854
    // 0x8080179C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800EB854(rdram, ctx);
        goto after_1;
    // 0x8080179C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808017A0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808017A4: beq         $v0, $at, L_808017C0
    if (ctx->r2 == ctx->r1) {
        // 0x808017A8: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_808017C0;
    }
    // 0x808017A8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808017AC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808017B0: beq         $v0, $at, L_808017E8
    if (ctx->r2 == ctx->r1) {
        // 0x808017B4: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808017E8;
    }
    // 0x808017B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808017B8: b           L_80801808
    // 0x808017BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801808;
    // 0x808017BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808017C0:
    // 0x808017C0: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    // 0x808017C4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808017C8: jal         0x800899C8
    // 0x808017CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _sumultiscore_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x808017CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x808017D0: jal         0x80089740
    // 0x808017D4: nop

    _scradar_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x808017D4: nop

    after_3:
    // 0x808017D8: jal         0x80089748
    // 0x808017DC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    _scradar_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x808017DC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x808017E0: b           L_80801808
    // 0x808017E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801808;
    // 0x808017E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808017E8:
    // 0x808017E8: jal         0x80801B30
    // 0x808017EC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80801B30_chfpsgame(rdram, ctx);
        goto after_5;
    // 0x808017EC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x808017F0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808017F4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808017F8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x808017FC: jal         0x800899C8
    // 0x80801800: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    _sumultiscore_entrypoint_12(rdram, ctx);
        goto after_6;
    // 0x80801800: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_6:
    // 0x80801804: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801808:
    // 0x80801808: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080180C: jr          $ra
    // 0x80801810: nop

    return;
    // 0x80801810: nop

;}
RECOMP_FUNC void func_8008E944(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E944: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x8008E948: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x8008E94C: lbu         $t7, 0x2A($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2A);
    // 0x8008E950: andi        $t8, $t7, 0xFFFD
    ctx->r24 = ctx->r15 & 0XFFFD;
    // 0x8008E954: jr          $ra
    // 0x8008E958: sb          $t8, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r24;
    return;
    // 0x8008E958: sb          $t8, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void func_8010D284(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010D284: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010D288: jr          $ra
    // 0x8010D28C: lw          $v0, 0x6F64($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6F64);
    return;
    // 0x8010D28C: lw          $v0, 0x6F64($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6F64);
;}
RECOMP_FUNC void func_80800638_chmineprospector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800638: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080063C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800640: addiu       $a1, $a0, 0x28
    ctx->r5 = ADD32(ctx->r4, 0X28);
    // 0x80800644: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(892, 0X111C) << 16);
    // 0x80800648: lui         $a3, 0x3CF5
    ctx->r7 = S32(0X3CF5 << 16);
    // 0x8080064C: ori         $a3, $a3, 0xC28F
    ctx->r7 = ctx->r7 | 0XC28F;
    // 0x80800650: addiu       $a2, $a2, 0x111C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(892, 0X111C));
    // 0x80800654: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800658: jal         0x80089D20
    // 0x8080065C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x8080065C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800660: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(892, 0XFB0) << 16);
    // 0x80800664: lui         $a3, 0x3F26
    ctx->r7 = S32(0X3F26 << 16);
    // 0x80800668: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080066C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800670: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80800674: jal         0x80089D20
    // 0x80800678: addiu       $a2, $a2, 0xFB0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(892, 0XFB0));
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800678: addiu       $a2, $a2, 0xFB0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(892, 0XFB0));
    after_1:
    // 0x8080067C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800680: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800684: jr          $ra
    // 0x80800688: nop

    return;
    // 0x80800688: nop

;}
RECOMP_FUNC void cosection_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: jr          $ra
    // 0x8080000C: addiu       $v0, $zero, 0x18B
    ctx->r2 = ADD32(0, 0X18B);
    return;
    // 0x8080000C: addiu       $v0, $zero, 0x18B
    ctx->r2 = ADD32(0, 0X18B);
;}
RECOMP_FUNC void func_80800D18_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D18: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80800D1C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80800D20: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80800D24: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800D28: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80800D2C: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80800D30: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80800D34: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800D38: jal         0x80802484
    // 0x80800D3C: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    func_80802484_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80800D3C: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800D40: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x80800D44: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80800D48: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800D4C: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x80800D50: jal         0x80800978
    // 0x80800D54: addiu       $a3, $sp, 0x5C
    ctx->r7 = ADD32(ctx->r29, 0X5C);
    func_80800978_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80800D54: addiu       $a3, $sp, 0x5C
    ctx->r7 = ADD32(ctx->r29, 0X5C);
    after_1:
    // 0x80800D58: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80800D5C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800D60: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800D64: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x80800D68: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80800D6C: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x80800D70: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80800D74: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80800D78: lbu         $a1, 0x2B($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X2B);
    // 0x80800D7C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80800D80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D84: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    // 0x80800D88: jal         0x800E0AFC
    // 0x80800D8C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_2;
    // 0x80800D8C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x80800D90: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80800D94: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x80800D98: lwc1        $f18, 0x60($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80800D9C: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x80800DA0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80800DA4: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80800DA8: lbu         $a1, 0x2F($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X2F);
    // 0x80800DAC: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    // 0x80800DB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DB4: jal         0x800E0AFC
    // 0x80800DB8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_3;
    // 0x80800DB8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x80800DBC: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x80800DC0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800DC4: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80800DC8: lw          $v0, 0x188($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X188);
    // 0x80800DCC: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x80800DD0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800DD4: lwc1        $f4, 0x44($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80800DD8: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x80800DDC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800DE0: mul.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800DE4: lwc1        $f8, 0x60($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X60);
    // 0x80800DE8: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x80800DEC: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80800DF0: mul.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800DF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DF8: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x80800DFC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80800E00: neg.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = -ctx->f22.fl;
    // 0x80800E04: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80800E08: jal         0x800E0AFC
    // 0x80800E0C: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_4;
    // 0x80800E0C: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x80800E10: lwc1        $f0, 0x48($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800E14: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80800E18: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x80800E1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E20: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    // 0x80800E24: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80800E28: jal         0x800E0AFC
    // 0x80800E2C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_5;
    // 0x80800E2C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x80800E30: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80800E34: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x80800E38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E3C: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    // 0x80800E40: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80800E44: jal         0x800E0AFC
    // 0x80800E48: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_6;
    // 0x80800E48: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    after_6:
    // 0x80800E4C: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80800E50: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x80800E54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E58: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x80800E5C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80800E60: jal         0x800E0AFC
    // 0x80800E64: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_7;
    // 0x80800E64: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    after_7:
    // 0x80800E68: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80800E6C: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80800E70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E74: addiu       $a1, $zero, 0x54
    ctx->r5 = ADD32(0, 0X54);
    // 0x80800E78: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80800E7C: jal         0x800E0AFC
    // 0x80800E80: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_8;
    // 0x80800E80: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    after_8:
    // 0x80800E84: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80800E88: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80800E8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E90: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    // 0x80800E94: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80800E98: jal         0x800E0AFC
    // 0x80800E9C: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_9;
    // 0x80800E9C: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    after_9:
    // 0x80800EA0: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80800EA4: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80800EA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EAC: addiu       $a1, $zero, 0x5B
    ctx->r5 = ADD32(0, 0X5B);
    // 0x80800EB0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80800EB4: jal         0x800E0AFC
    // 0x80800EB8: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_10;
    // 0x80800EB8: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    after_10:
    // 0x80800EBC: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80800EC0: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80800EC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EC8: addiu       $a1, $zero, 0x5C
    ctx->r5 = ADD32(0, 0X5C);
    // 0x80800ECC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80800ED0: jal         0x800E0AFC
    // 0x80800ED4: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_11;
    // 0x80800ED4: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    after_11:
    // 0x80800ED8: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80800EDC: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80800EE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EE4: addiu       $a1, $zero, 0x5D
    ctx->r5 = ADD32(0, 0X5D);
    // 0x80800EE8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80800EEC: jal         0x800E0AFC
    // 0x80800EF0: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_12;
    // 0x80800EF0: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    after_12:
    // 0x80800EF4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80800EF8: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80800EFC: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80800F00: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80800F04: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80800F08: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80800F0C: jr          $ra
    // 0x80800F10: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80800F10: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void _bsbswim_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082B80: syscall     28
    recomp_syscall_handler(rdram, ctx, 0x80082B80);
    return;
    // 0x80082B84: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_80800EF0_chvolcanobits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EF0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800EF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800EF8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800EFC: jal         0x8080108C
    // 0x80800F00: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8080108C_chvolcanobits(rdram, ctx);
        goto after_0;
    // 0x80800F00: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800F04: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800F08: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80800F0C: lhu         $a2, 0x76($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X76);
    // 0x80800F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F14: addiu       $a1, $zero, 0x429
    ctx->r5 = ADD32(0, 0X429);
    // 0x80800F18: srl         $t6, $a2, 7
    ctx->r14 = S32(U32(ctx->r6) >> 7);
    // 0x80800F1C: jal         0x80089C70
    // 0x80800F20: addiu       $a2, $t6, 0x1
    ctx->r6 = ADD32(ctx->r14, 0X1);
    _subaddiefind_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x80800F20: addiu       $a2, $t6, 0x1
    ctx->r6 = ADD32(ctx->r14, 0X1);
    after_1:
    // 0x80800F24: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800F28: jal         0x800EFD24
    // 0x80800F2C: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    func_800EFD24(rdram, ctx);
        goto after_2;
    // 0x80800F2C: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_2:
    // 0x80800F30: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80800F34: jal         0x800EFD24
    // 0x80800F38: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800EFD24(rdram, ctx);
        goto after_3;
    // 0x80800F38: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_3:
    // 0x80800F3C: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x80800F40: jal         0x800EFD24
    // 0x80800F44: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_800EFD24(rdram, ctx);
        goto after_4;
    // 0x80800F44: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_4:
    // 0x80800F48: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80800F4C: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800F50: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80800F54: lh          $t8, 0x4($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X4);
    // 0x80800F58: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80800F5C: nop

    // 0x80800F60: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800F64: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80800F68: beq         $a0, $zero, L_80800F7C
    if (ctx->r4 == 0) {
        // 0x80800F6C: swc1        $f10, 0x2C($s0)
        MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
            goto L_80800F7C;
    }
    // 0x80800F6C: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
    // 0x80800F70: jal         0x80106790
    // 0x80800F74: nop

    func_80106790(rdram, ctx);
        goto after_5;
    // 0x80800F74: nop

    after_5:
    // 0x80800F78: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
L_80800F7C:
    // 0x80800F7C: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80800F80: beql        $t9, $zero, L_80800F9C
    if (ctx->r25 == 0) {
        // 0x80800F84: lw          $t0, 0x34($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X34);
            goto L_80800F9C;
    }
    goto skip_0;
    // 0x80800F84: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x80800F88: lwc1        $f16, 0x8($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X8);
    // 0x80800F8C: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800F90: sub.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80800F94: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
    // 0x80800F98: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
L_80800F9C:
    // 0x80800F9C: jal         0x800DA298
    // 0x80800FA0: lh          $a0, 0x6($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X6);
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x80800FA0: lh          $a0, 0x6($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X6);
    after_6:
    // 0x80800FA4: beq         $v0, $zero, L_80800FD4
    if (ctx->r2 == 0) {
        // 0x80800FA8: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_80800FD4;
    }
    // 0x80800FA8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800FAC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800FB0: jal         0x800EE7F8
    // 0x80800FB4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x80800FB4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_7:
    // 0x80800FB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FBC: jal         0x80101FDC
    // 0x80800FC0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_8;
    // 0x80800FC0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_8:
    // 0x80800FC4: jal         0x800FFAB0
    // 0x80800FC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_9;
    // 0x80800FC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800FCC: b           L_80801008
    // 0x80800FD0: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
        goto L_80801008;
    // 0x80800FD0: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
L_80800FD4:
    // 0x80800FD4: jal         0x800EE7F8
    // 0x80800FD8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_10;
    // 0x80800FD8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_10:
    // 0x80800FDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FE0: jal         0x80101FDC
    // 0x80800FE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_11;
    // 0x80800FE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80800FE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FEC: jal         0x80103110
    // 0x80800FF0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_12;
    // 0x80800FF0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80800FF4: lbu         $t1, 0x79($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X79);
    // 0x80800FF8: andi        $t2, $t1, 0xFF0F
    ctx->r10 = ctx->r9 & 0XFF0F;
    // 0x80800FFC: ori         $t3, $t2, 0x20
    ctx->r11 = ctx->r10 | 0X20;
    // 0x80801000: sb          $t3, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r11;
    // 0x80801004: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
L_80801008:
    // 0x80801008: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080100C: beq         $t4, $zero, L_80801024
    if (ctx->r12 == 0) {
        // 0x80801010: nop
    
            goto L_80801024;
    }
    // 0x80801010: nop

    // 0x80801014: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80801018: lwc1        $f8, 0x54($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8080101C: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80801020: swc1        $f10, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f10.u32l;
L_80801024:
    // 0x80801024: jal         0x80801040
    // 0x80801028: sb          $zero, 0x5F($s0)
    MEM_B(0X5F, ctx->r16) = 0;
    func_80801040_chvolcanobits(rdram, ctx);
        goto after_13;
    // 0x80801028: sb          $zero, 0x5F($s0)
    MEM_B(0X5F, ctx->r16) = 0;
    after_13:
    // 0x8080102C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801030: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801034: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80801038: jr          $ra
    // 0x8080103C: nop

    return;
    // 0x8080103C: nop

;}
RECOMP_FUNC void _basetup_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084FA8: syscall     146
    recomp_syscall_handler(rdram, ctx, 0x80084FA8);
    return;
    // 0x80084FAC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800A06E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A06E0: jr          $ra
    // 0x800A06E4: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    return;
    // 0x800A06E4: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
;}
RECOMP_FUNC void _vpwibble_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089030: syscall     756
    recomp_syscall_handler(rdram, ctx, 0x80089030);
    return;
    // 0x80089034: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_8009588C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009588C: lw          $t6, 0x94($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X94);
    // 0x80095890: jr          $ra
    // 0x80095894: lw          $v0, 0x14($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X14);
    return;
    // 0x80095894: lw          $v0, 0x14($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X14);
;}
RECOMP_FUNC void _chfiregen_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086988: syscall     404
    recomp_syscall_handler(rdram, ctx, 0x80086988);
    return;
    // 0x8008698C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808017FC_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808017FC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801800: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801804: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801808: jal         0x808006F0
    // 0x8080180C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bstrexlarge_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x8080180C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801810: lui         $a2, 0x3F99
    ctx->r6 = S32(0X3F99 << 16);
    // 0x80801814: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80801818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080181C: jal         0x8008CB3C
    // 0x80801820: addiu       $a1, $zero, 0x1CE
    ctx->r5 = ADD32(0, 0X1CE);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x80801820: addiu       $a1, $zero, 0x1CE
    ctx->r5 = ADD32(0, 0X1CE);
    after_1:
    // 0x80801824: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x80801828: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080182C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801830: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80801834: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80801838: jal         0x8009FFD8
    // 0x8080183C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x8080183C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80801840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801844: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    // 0x80801848: jal         0x8009C99C
    // 0x8080184C: lui         $a2, 0x4060
    ctx->r6 = S32(0X4060 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_3;
    // 0x8080184C: lui         $a2, 0x4060
    ctx->r6 = S32(0X4060 << 16);
    after_3:
    // 0x80801850: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80801854: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80801858: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080185C: jal         0x8008C9BC
    // 0x80801860: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    baanim_setDurationRange(rdram, ctx);
        goto after_4;
    // 0x80801860: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    after_4:
    // 0x80801864: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801868: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080186C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801870: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x80801874: lui         $a2, 0x43C8
    ctx->r6 = S32(0X43C8 << 16);
    // 0x80801878: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    // 0x8080187C: jal         0x8008C9F0
    // 0x80801880: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_5;
    // 0x80801880: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x80801884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801888: jal         0x8008CA30
    // 0x8080188C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8008CA30(rdram, ctx);
        goto after_6;
    // 0x8080188C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_6:
    // 0x80801890: jal         0x80800000
    // 0x80801894: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bstrexlarge(rdram, ctx);
        goto after_7;
    // 0x80801894: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80801898: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080189C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808018A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808018A4: jr          $ra
    // 0x808018A8: nop

    return;
    // 0x808018A8: nop

;}
RECOMP_FUNC void func_80800204_chattract(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800204: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800208: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8080020C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800210: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80800214: lwc1        $f0, 0x48($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X48);
    // 0x80800218: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080021C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800220: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x80800224: nop

    // 0x80800228: bc1t        L_80800254
    if (c1cs) {
        // 0x8080022C: nop
    
            goto L_80800254;
    }
    // 0x8080022C: nop

    // 0x80800230: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800234: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800238: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x8080023C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80800240: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80800244: jal         0x800EFA4C
    // 0x80800248: nop

    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x80800248: nop

    after_0:
    // 0x8080024C: jal         0x800DF4CC
    // 0x80800250: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_800DF4CC(rdram, ctx);
        goto after_1;
    // 0x80800250: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_1:
L_80800254:
    // 0x80800254: jal         0x800DF410
    // 0x80800258: lbu         $a0, 0x9B($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X9B);
    func_800DF410(rdram, ctx);
        goto after_2;
    // 0x80800258: lbu         $a0, 0x9B($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X9B);
    after_2:
    // 0x8080025C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80800260: addiu       $a0, $a0, 0x15D0
    ctx->r4 = ADD32(ctx->r4, 0X15D0);
    // 0x80800264: jal         0x800DF47C
    // 0x80800268: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800DF47C(rdram, ctx);
        goto after_3;
    // 0x80800268: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x8080026C: jal         0x8010347C
    // 0x80800270: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_8010347C(rdram, ctx);
        goto after_4;
    // 0x80800270: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_4:
    // 0x80800274: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x80800278: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080027C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80800280: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80800284: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800288: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8080028C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800290: jal         0x800DF944
    // 0x80800294: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_800DF944(rdram, ctx);
        goto after_5;
    // 0x80800294: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_5:
    // 0x80800298: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8080029C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808002A0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808002A4: jr          $ra
    // 0x808002A8: nop

    return;
    // 0x808002A8: nop

;}
RECOMP_FUNC void _bsbwhirl_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082E08: syscall     30
    recomp_syscall_handler(rdram, ctx, 0x80082E08);
    return;
    // 0x80082E0C: addi        $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
;}
RECOMP_FUNC void func_80110970(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "func_80110970");
    // 0x80110970: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80110974: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80110978: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8011097C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80110980: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    // 0x80110984: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80110988: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8011098C: beq         $v0, $at, L_801109B0
    if (ctx->r2 == ctx->r1) {
        // 0x80110990: addiu       $a1, $sp, 0x34
        ctx->r5 = ADD32(ctx->r29, 0X34);
            goto L_801109B0;
    }
    // 0x80110990: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80110994: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80110998: beq         $v0, $at, L_801109B0
    if (ctx->r2 == ctx->r1) {
        // 0x8011099C: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_801109B0;
    }
    // 0x8011099C: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x801109A0: beq         $v0, $at, L_801109B0
    if (ctx->r2 == ctx->r1) {
        // 0x801109A4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801109B0;
    }
    // 0x801109A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801109A8: bnel        $v0, $at, L_80110A14
    if (ctx->r2 != ctx->r1) {
        // 0x801109AC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80110A14;
    }
    goto skip_0;
    // 0x801109AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_801109B0:
    // 0x801109B0: jal         0x800F5A00
    // 0x801109B4: lw          $a0, 0x68($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X68);
    func_800F5A00(rdram, ctx);
        goto after_0;
    // 0x801109B4: lw          $a0, 0x68($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X68);
    after_0:
    // 0x801109B8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801109BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801109C0: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801109C4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801109C8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x801109CC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801109D0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801109D4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801109D8: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x801109DC: jal         0x800EFA4C
    // 0x801109E0: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    func_800EFA4C(rdram, ctx);
        goto after_1;
    // 0x801109E0: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x801109E4: lw          $a0, 0x64($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X64);
    // 0x801109E8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x801109EC: jal         0x8010FE14
    // 0x801109F0: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    func_8010FE14(rdram, ctx);
        goto after_2;
    // 0x801109F0: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x801109F4: jal         0x8010FF80
    // 0x801109F8: lw          $a0, 0x64($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X64);
    func_8010FF80(rdram, ctx);
        goto after_3;
    // 0x801109F8: lw          $a0, 0x64($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X64);
    after_3:
    // 0x801109FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80110A00: jal         0x800CA3A4
    // 0x80110A04: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    func_800CA3A4(rdram, ctx);
        goto after_4;
    // 0x80110A04: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    after_4:
    // 0x80110A08: jal         0x801108A0
    // 0x80110A0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801108A0(rdram, ctx);
        goto after_5;
    // 0x80110A0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80110A10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80110A14:
    // 0x80110A14: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80110A18: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80110A1C: jr          $ra
    // 0x80110A20: nop

    return;
    // 0x80110A20: nop

;}
RECOMP_FUNC void bahold_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_808004B0_vplight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808004B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004B8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808004BC: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x808004C0: jal         0x800C8800
    // 0x808004C4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800C8800(rdram, ctx);
        goto after_0;
    // 0x808004C4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x808004C8: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x808004CC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x808004D0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808004D4: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x808004D8: nop

    // 0x808004DC: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x808004E0: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x808004E4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808004E8: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x808004EC: nop

    // 0x808004F0: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x808004F4: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808004F8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x808004FC: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x80800500: nop

    // 0x80800504: sw          $t1, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r9;
    // 0x80800508: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080050C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800510: jr          $ra
    // 0x80800514: nop

    return;
    // 0x80800514: nop

;}
RECOMP_FUNC void func_800F53D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F53D0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F53D4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F53D8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800F53DC: jr          $ra
    // 0x800F53E0: lw          $v0, 0x5490($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5490);
    return;
    // 0x800F53E0: lw          $v0, 0x5490($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5490);
;}
RECOMP_FUNC void func_80800B88_chjiggygamenew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B88: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800B8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800B90: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800B94: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800B98: jal         0x80100094
    // 0x80800B9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800B9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800BA0: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x80800BA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800BA8: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80800BAC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800BB0: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x80800BB4: addiu       $a3, $zero, 0x2A1
    ctx->r7 = ADD32(0, 0X2A1);
    // 0x80800BB8: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
L_80800BBC:
    // 0x80800BBC: lhu         $a0, 0x4($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X4);
    // 0x80800BC0: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x80800BC4: beql        $a1, $a0, L_80800CA4
    if (ctx->r5 == ctx->r4) {
        // 0x80800BC8: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80800CA4;
    }
    goto skip_0;
    // 0x80800BC8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_0:
    // 0x80800BCC: beql        $a3, $a0, L_80800CA4
    if (ctx->r7 == ctx->r4) {
        // 0x80800BD0: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80800CA4;
    }
    goto skip_1;
    // 0x80800BD0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_1:
    // 0x80800BD4: beq         $a0, $zero, L_80800BFC
    if (ctx->r4 == 0) {
        // 0x80800BD8: addiu       $at, $zero, 0x800
        ctx->r1 = ADD32(0, 0X800);
            goto L_80800BFC;
    }
    // 0x80800BD8: addiu       $at, $zero, 0x800
    ctx->r1 = ADD32(0, 0X800);
    // 0x80800BDC: beq         $a0, $at, L_80800BFC
    if (ctx->r4 == ctx->r1) {
        // 0x80800BE0: addiu       $at, $zero, 0x1FFF
        ctx->r1 = ADD32(0, 0X1FFF);
            goto L_80800BFC;
    }
    // 0x80800BE0: addiu       $at, $zero, 0x1FFF
    ctx->r1 = ADD32(0, 0X1FFF);
    // 0x80800BE4: beq         $a0, $at, L_80800BFC
    if (ctx->r4 == ctx->r1) {
        // 0x80800BE8: ori         $at, $zero, 0xA000
        ctx->r1 = 0 | 0XA000;
            goto L_80800BFC;
    }
    // 0x80800BE8: ori         $at, $zero, 0xA000
    ctx->r1 = 0 | 0XA000;
    // 0x80800BEC: beq         $a0, $at, L_80800C20
    if (ctx->r4 == ctx->r1) {
        // 0x80800BF0: addu        $s0, $t2, $t1
        ctx->r16 = ADD32(ctx->r10, ctx->r9);
            goto L_80800C20;
    }
    // 0x80800BF0: addu        $s0, $t2, $t1
    ctx->r16 = ADD32(ctx->r10, ctx->r9);
    // 0x80800BF4: b           L_80800C54
    // 0x80800BF8: addu        $s0, $t2, $t1
    ctx->r16 = ADD32(ctx->r10, ctx->r9);
        goto L_80800C54;
    // 0x80800BF8: addu        $s0, $t2, $t1
    ctx->r16 = ADD32(ctx->r10, ctx->r9);
L_80800BFC:
    // 0x80800BFC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800C00: addu        $s0, $t2, $t1
    ctx->r16 = ADD32(ctx->r10, ctx->r9);
    // 0x80800C04: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x80800C08: lw          $a0, 0x3C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X3C);
    // 0x80800C0C: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80800C10: jal         0x808035C4
    // 0x80800C14: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_808035C4_chjiggygamenew(rdram, ctx);
        goto after_1;
    // 0x80800C14: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x80800C18: b           L_80800C84
    // 0x80800C1C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
        goto L_80800C84;
    // 0x80800C1C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
L_80800C20:
    // 0x80800C20: lbu         $t7, 0x3($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X3);
    // 0x80800C24: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(772, 0X3AE0) << 16);
    // 0x80800C28: addiu       $t9, $t9, 0x3AE0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(772, 0X3AE0));
    // 0x80800C2C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80800C30: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80800C34: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800C38: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    // 0x80800C3C: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80800C40: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800C44: jal         0x800EE7F8
    // 0x80800C48: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800C48: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    after_2:
    // 0x80800C4C: b           L_80800C84
    // 0x80800C50: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
        goto L_80800C84;
    // 0x80800C50: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
L_80800C54:
    // 0x80800C54: lb          $t3, 0x1($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1);
    // 0x80800C58: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(772, 0X3BD0) << 16);
    // 0x80800C5C: addiu       $t5, $t5, 0x3BD0
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(772, 0X3BD0));
    // 0x80800C60: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80800C64: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80800C68: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80800C6C: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    // 0x80800C70: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80800C74: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800C78: jal         0x800EE7F8
    // 0x80800C7C: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800C7C: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    after_3:
    // 0x80800C80: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
L_80800C84:
    // 0x80800C84: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800C88: jal         0x808007E4
    // 0x80800C8C: addiu       $a1, $zero, 0x9EC
    ctx->r5 = ADD32(0, 0X9EC);
    func_808007E4_chjiggygamenew(rdram, ctx);
        goto after_4;
    // 0x80800C8C: addiu       $a1, $zero, 0x9EC
    ctx->r5 = ADD32(0, 0X9EC);
    after_4:
    // 0x80800C90: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800C94: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800C98: b           L_80800CAC
    // 0x80800C9C: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
        goto L_80800CAC;
    // 0x80800C9C: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x80800CA0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80800CA4:
    // 0x80800CA4: bne         $a2, $t0, L_80800BBC
    if (ctx->r6 != ctx->r8) {
        // 0x80800CA8: addiu       $t1, $t1, 0x18
        ctx->r9 = ADD32(ctx->r9, 0X18);
            goto L_80800BBC;
    }
    // 0x80800CA8: addiu       $t1, $t1, 0x18
    ctx->r9 = ADD32(ctx->r9, 0X18);
L_80800CAC:
    // 0x80800CAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800CB0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800CB4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800CB8: jr          $ra
    // 0x80800CBC: nop

    return;
    // 0x80800CBC: nop

;}
RECOMP_FUNC void _bsbanswim_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082778: syscall     10
    recomp_syscall_handler(rdram, ctx, 0x80082778);
    return;
    // 0x8008277C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_8009B4D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B4D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009B4D4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8009B4D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009B4DC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8009B4E0: lw          $a1, 0xC8($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XC8);
    // 0x8009B4E4: jal         0x800EE7F8
    // 0x8009B4E8: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8009B4E8: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    after_0:
    // 0x8009B4EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009B4F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009B4F4: jr          $ra
    // 0x8009B4F8: nop

    return;
    // 0x8009B4F8: nop

;}
RECOMP_FUNC void _bashoessuck_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085090: syscall     149
    recomp_syscall_handler(rdram, ctx, 0x80085090);
    return;
    // 0x80085094: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
