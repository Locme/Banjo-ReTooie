#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_808037B0_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808037B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808037B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808037B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808037BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808037C0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808037C4: jal         0x80106790
    // 0x808037C8: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808037C8: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x808037CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808037D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808037D4: jal         0x80100094
    // 0x808037D8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808037D8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x808037DC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x808037E0: lhu         $t6, 0x76($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X76);
    // 0x808037E4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x808037E8: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x808037EC: addu        $v1, $v0, $t7
    ctx->r3 = ADD32(ctx->r2, ctx->r15);
    // 0x808037F0: lb          $t8, 0x8($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X8);
    // 0x808037F4: lbu         $t9, 0x4($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X4);
    // 0x808037F8: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x808037FC: slti        $at, $t0, 0x3
    ctx->r1 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
    // 0x80803800: beql        $at, $zero, L_8080389C
    if (ctx->r1 == 0) {
        // 0x80803804: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080389C;
    }
    goto skip_0;
    // 0x80803804: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80803808: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x8080380C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80803810: srl         $t1, $v0, 10
    ctx->r9 = S32(U32(ctx->r2) >> 10);
    // 0x80803814: beq         $t1, $at, L_80803824
    if (ctx->r9 == ctx->r1) {
        // 0x80803818: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80803824;
    }
    // 0x80803818: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8080381C: bnel        $t1, $at, L_8080389C
    if (ctx->r9 != ctx->r1) {
        // 0x80803820: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080389C;
    }
    goto skip_1;
    // 0x80803820: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
L_80803824:
    // 0x80803824: jal         0x808003F8
    // 0x80803828: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_808003F8_chdragonbrothers(rdram, ctx);
        goto after_2;
    // 0x80803828: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x8080382C: beq         $v0, $zero, L_80803898
    if (ctx->r2 == 0) {
        // 0x80803830: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803898;
    }
    // 0x80803830: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803834: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1852, 0X543C) << 16);
    // 0x80803838: addiu       $a2, $a2, 0x543C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1852, 0X543C));
    // 0x8080383C: jal         0x80089D18
    // 0x80803840: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80803840: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x80803844: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80803848: lbu         $t7, 0x79($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X79);
    // 0x8080384C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803850: addiu       $t4, $t2, -0x26B
    ctx->r12 = ADD32(ctx->r10, -0X26B);
    // 0x80803854: sll         $t6, $t4, 4
    ctx->r14 = S32(ctx->r12 << 4);
    // 0x80803858: andi        $t8, $t7, 0xFF0F
    ctx->r24 = ctx->r15 & 0XFF0F;
    // 0x8080385C: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80803860: sb          $t9, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r25;
    // 0x80803864: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80803868: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x8080386C: srl         $t1, $t0, 4
    ctx->r9 = S32(U32(ctx->r8) >> 4);
    // 0x80803870: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80803874: jal         0x808036EC
    // 0x80803878: sb          $t1, 0x5C($t2)
    MEM_B(0X5C, ctx->r10) = ctx->r9;
    func_808036EC_chdragonbrothers(rdram, ctx);
        goto after_4;
    // 0x80803878: sb          $t1, 0x5C($t2)
    MEM_B(0X5C, ctx->r10) = ctx->r9;
    after_4:
    // 0x8080387C: lhu         $t4, 0x76($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X76);
    // 0x80803880: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80803884: srl         $t5, $t4, 7
    ctx->r13 = S32(U32(ctx->r12) >> 7);
    // 0x80803888: addu        $v0, $t3, $t5
    ctx->r2 = ADD32(ctx->r11, ctx->r13);
    // 0x8080388C: lb          $t7, 0x8($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X8);
    // 0x80803890: addiu       $t6, $t7, 0x1
    ctx->r14 = ADD32(ctx->r15, 0X1);
    // 0x80803894: sb          $t6, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r14;
L_80803898:
    // 0x80803898: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080389C:
    // 0x8080389C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808038A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808038A4: jr          $ra
    // 0x808038A8: nop

    return;
    // 0x808038A8: nop

;}
RECOMP_FUNC void func_800B2354(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2354: lhu         $t6, 0x14($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X14);
    // 0x800B2358: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B235C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800B2360: bgez        $t6, L_800B2374
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800B2364: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800B2374;
    }
    // 0x800B2364: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B2368: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B236C: nop

    // 0x800B2370: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_800B2374:
    // 0x800B2374: jr          $ra
    // 0x800B2378: nop

    return;
    // 0x800B2378: nop

;}
RECOMP_FUNC void func_800B23E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B23E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B23E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B23E8: jal         0x8001B084
    // 0x800B23EC: nop

    heap_free(rdram, ctx);
        goto after_0;
    // 0x800B23EC: nop

    after_0:
    // 0x800B23F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B23F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B23F8: jr          $ra
    // 0x800B23FC: nop

    return;
    // 0x800B23FC: nop

;}
RECOMP_FUNC void func_80801004_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801004: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801008: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080100C: jal         0x80090A2C
    // 0x80801010: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80090A2C(rdram, ctx);
        goto after_0;
    // 0x80801010: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801014: jal         0x808008D8
    // 0x80801018: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808008D8_bssub(rdram, ctx);
        goto after_1;
    // 0x80801018: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080101C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801020: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801024: jr          $ra
    // 0x80801028: nop

    return;
    // 0x80801028: nop

;}
RECOMP_FUNC void func_800C51A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C51A4: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x800C51A8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C51AC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C51B0: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800C51B4: swc1        $f14, -0x55FC($at)
    MEM_W(-0X55FC, ctx->r1) = ctx->f14.u32l;
    // 0x800C51B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C51BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C51C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C51C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C51C8: c.eq.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl == ctx->f4.fl;
    // 0x800C51CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C51D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C51D4: bc1t        L_800C5224
    if (c1cs) {
        // 0x800C51D8: nop
    
            goto L_800C5224;
    }
    // 0x800C51D8: nop

    // 0x800C51DC: jal         0x800C517C
    // 0x800C51E0: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    func_800C517C(rdram, ctx);
        goto after_0;
    // 0x800C51E0: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x800C51E4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800C51E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C51EC: nop

    // 0x800C51F0: mul.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800C51F4: jal         0x800139F8
    // 0x800C51F8: nop

    func_800139F8(rdram, ctx);
        goto after_1;
    // 0x800C51F8: nop

    after_1:
    // 0x800C51FC: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C5200: jal         0x80013B7C
    // 0x800C5204: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80013B7C(rdram, ctx);
        goto after_2;
    // 0x800C5204: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_2:
    // 0x800C5208: add.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800C520C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C5210: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800C5214: jal         0x800C5094
    // 0x800C5218: nop

    func_800C5094(rdram, ctx);
        goto after_3;
    // 0x800C5218: nop

    after_3:
    // 0x800C521C: b           L_800C523C
    // 0x800C5220: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800C523C;
    // 0x800C5220: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800C5224:
    // 0x800C5224: jal         0x800C517C
    // 0x800C5228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C517C(rdram, ctx);
        goto after_4;
    // 0x800C5228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800C522C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800C5230: jal         0x800C5094
    // 0x800C5234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C5094(rdram, ctx);
        goto after_5;
    // 0x800C5234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800C5238: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800C523C:
    // 0x800C523C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C5240: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C5244: jr          $ra
    // 0x800C5248: nop

    return;
    // 0x800C5248: nop

;}
RECOMP_FUNC void bsclimb_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080077C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800780: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(144, 0X90C) << 16);
    // 0x80800784: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800788: jr          $ra
    // 0x8080078C: lw          $v0, 0x90C($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(144, 0X90C));
    return;
    // 0x8080078C: lw          $v0, 0x90C($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(144, 0X90C));
;}
RECOMP_FUNC void func_80018028(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018028: sll         $t6, $a0, 5
    ctx->r14 = S32(ctx->r4 << 5);
    // 0x8001802C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80018030: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80018034: addiu       $t7, $t7, -0x4D30
    ctx->r15 = ADD32(ctx->r15, -0X4D30);
    // 0x80018038: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8001803C: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80018040: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    // 0x80018044: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80018048: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001804C: beq         $t8, $zero, L_80018080
    if (ctx->r24 == 0) {
        // 0x80018050: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_80018080;
    }
    // 0x80018050: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80018054: jal         0x80016934
    // 0x80018058: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_80016934(rdram, ctx);
        goto after_0;
    // 0x80018058: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x8001805C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80018060: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80018064: jal         0x80030640
    // 0x80018068: addiu       $a0, $v1, 0x1C
    ctx->r4 = ADD32(ctx->r3, 0X1C);
    __osMotorAccess_recomp(rdram, ctx);
        goto after_1;
    // 0x80018068: addiu       $a0, $v1, 0x1C
    ctx->r4 = ADD32(ctx->r3, 0X1C);
    after_1:
    // 0x8001806C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80018070: sltiu       $t9, $v0, 0x1
    ctx->r25 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80018074: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80018078: jal         0x80016934
    // 0x8001807C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    func_80016934(rdram, ctx);
        goto after_2;
    // 0x8001807C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    after_2:
L_80018080:
    // 0x80018080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80018084: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80018088: jr          $ra
    // 0x8001808C: nop

    return;
    // 0x8001808C: nop

;}
RECOMP_FUNC void func_808001A0_chlagoonfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001AC: lhu         $v0, 0x76($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X76);
    // 0x808001B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001B4: srl         $t6, $v0, 7
    ctx->r14 = S32(U32(ctx->r2) >> 7);
    // 0x808001B8: slti        $at, $t6, 0x33
    ctx->r1 = SIGNED(ctx->r14) < 0X33 ? 1 : 0;
    // 0x808001BC: beq         $at, $zero, L_808001D4
    if (ctx->r1 == 0) {
        // 0x808001C0: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_808001D4;
    }
    // 0x808001C0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x808001C4: jal         0x800FFAB0
    // 0x808001C8: nop

    func_800FFAB0(rdram, ctx);
        goto after_0;
    // 0x808001C8: nop

    after_0:
    // 0x808001CC: b           L_80800230
    // 0x808001D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800230;
    // 0x808001D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001D4:
    // 0x808001D4: lhu         $t0, 0x6E($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X6E);
    // 0x808001D8: addiu       $t8, $v0, -0x32
    ctx->r24 = ADD32(ctx->r2, -0X32);
    // 0x808001DC: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x808001E0: andi        $t1, $t0, 0xFE00
    ctx->r9 = ctx->r8 & 0XFE00;
    // 0x808001E4: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x808001E8: sh          $t2, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r10;
    // 0x808001EC: jal         0x80800000
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_chlagoonfish(rdram, ctx);
        goto after_1;
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F8: jal         0x80800A44
    // 0x808001FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800A44_chlagoonfish(rdram, ctx);
        goto after_2;
    // 0x808001FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800200: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80800204: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800208: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800210: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800214: jal         0x80089F48
    // 0x80800218: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    _subaddiesect_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80800218: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    after_3:
    // 0x8080021C: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80800220: nop

    // 0x80800224: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800228: swc1        $f16, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f16.u32l;
    // 0x8080022C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800230:
    // 0x80800230: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800234: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800238: jr          $ra
    // 0x8080023C: nop

    return;
    // 0x8080023C: nop

;}
RECOMP_FUNC void bsbansnooze_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800368: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080036C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(49, 0XA40) << 16);
    // 0x80800370: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800374: jr          $ra
    // 0x80800378: lw          $v0, 0xA40($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(49, 0XA40));
    return;
    // 0x80800378: lw          $v0, 0xA40($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(49, 0XA40));
;}
RECOMP_FUNC void func_80800670_chbouncycastle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800670: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800674: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800678: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080067C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800680: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x80800684: jal         0x800CBDD4
    // 0x80800688: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800CBDD4(rdram, ctx);
        goto after_0;
    // 0x80800688: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8080068C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800690: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800694: beq         $v0, $at, L_808006B4
    if (ctx->r2 == ctx->r1) {
        // 0x80800698: sw          $v0, 0x28($t6)
        MEM_W(0X28, ctx->r14) = ctx->r2;
            goto L_808006B4;
    }
    // 0x80800698: sw          $v0, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->r2;
    // 0x8080069C: jal         0x800DA298
    // 0x808006A0: addiu       $a0, $zero, 0xB2
    ctx->r4 = ADD32(0, 0XB2);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x808006A0: addiu       $a0, $zero, 0xB2
    ctx->r4 = ADD32(0, 0XB2);
    after_1:
    // 0x808006A4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x808006A8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808006AC: jal         0x800CBB80
    // 0x808006B0: lw          $a0, 0x28($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X28);
    func_800CBB80(rdram, ctx);
        goto after_2;
    // 0x808006B0: lw          $a0, 0x28($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X28);
    after_2:
L_808006B4:
    // 0x808006B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808006BC: jr          $ra
    // 0x808006C0: nop

    return;
    // 0x808006C0: nop

;}
RECOMP_FUNC void func_80800014_chjiggypost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800014: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800018: addiu       $at, $zero, 0x1515
    ctx->r1 = ADD32(0, 0X1515);
    // 0x8080001C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800020: bne         $a1, $at, L_80800030
    if (ctx->r5 != ctx->r1) {
        // 0x80800024: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_80800030;
    }
    // 0x80800024: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800028: b           L_80800034
    // 0x8080002C: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
        goto L_80800034;
    // 0x8080002C: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
L_80800030:
    // 0x80800030: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
L_80800034:
    // 0x80800034: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800038: addiu       $t7, $zero, 0x97
    ctx->r15 = ADD32(0, 0X97);
    // 0x8080003C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80800040: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800044: jal         0x8008A208
    // 0x80800048: addiu       $a3, $t6, 0x4
    ctx->r7 = ADD32(ctx->r14, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x80800048: addiu       $a3, $t6, 0x4
    ctx->r7 = ADD32(ctx->r14, 0X4);
    after_0:
    // 0x8080004C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800050: jal         0x80101FDC
    // 0x80800054: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x80800054: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80800058: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080005C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800060: jr          $ra
    // 0x80800064: nop

    return;
    // 0x80800064: nop

;}
RECOMP_FUNC void _chanim_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800859B8: syscall     184
    recomp_syscall_handler(rdram, ctx, 0x800859B8);
    return;
    // 0x800859BC: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_80800194_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800194: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800198: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080019C: jal         0x80100094
    // 0x808001A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808001A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808001A4: addiu       $a0, $zero, 0xA4C
    ctx->r4 = ADD32(0, 0XA4C);
    // 0x808001A8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808001AC: jal         0x800DA564
    // 0x808001B0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800DA564(rdram, ctx);
        goto after_1;
    // 0x808001B0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808001B4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808001B8: sb          $v0, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r2;
    // 0x808001BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001C4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x808001C8: jr          $ra
    // 0x808001CC: nop

    return;
    // 0x808001CC: nop

;}
RECOMP_FUNC void func_80800790_choctopus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800790: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800794: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800798: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080079C: jal         0x80100094
    // 0x808007A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808007A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808007A4: bne         $v0, $zero, L_808007D4
    if (ctx->r2 != 0) {
        // 0x808007A8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808007D4;
    }
    // 0x808007A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808007AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808007B0: jal         0x800897C0
    // 0x808007B4: addiu       $a2, $zero, 0xB6
    ctx->r6 = ADD32(0, 0XB6);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x808007B4: addiu       $a2, $zero, 0xB6
    ctx->r6 = ADD32(0, 0XB6);
    after_1:
    // 0x808007B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808007BC: jal         0x80100094
    // 0x808007C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x808007C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x808007C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808007C8: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    // 0x808007CC: jal         0x800897E8
    // 0x808007D0: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_3;
    // 0x808007D0: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    after_3:
L_808007D4:
    // 0x808007D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007DC: jr          $ra
    // 0x808007E0: nop

    return;
    // 0x808007E0: nop

;}
RECOMP_FUNC void func_800C9610(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9610: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C9614: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9618: jal         0x800C91C8
    // 0x800C961C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800C91C8(rdram, ctx);
        goto after_0;
    // 0x800C961C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x800C9620: bne         $v0, $zero, L_800C9634
    if (ctx->r2 != 0) {
        // 0x800C9624: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800C9634;
    }
    // 0x800C9624: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C9628: jal         0x800C9150
    // 0x800C962C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800C9150(rdram, ctx);
        goto after_1;
    // 0x800C962C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_1:
    // 0x800C9630: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800C9634:
    // 0x800C9634: jal         0x800881D8
    // 0x800C9638: nop

    _gctransitionDll_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x800C9638: nop

    after_2:
    // 0x800C963C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C9640: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C9644: jr          $ra
    // 0x800C9648: nop

    return;
    // 0x800C9648: nop

;}
RECOMP_FUNC void func_80092A1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092A1C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80092A20: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80092A24: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80092A28: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80092A2C: jal         0x80092EC8
    // 0x80092A30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80092EC8(rdram, ctx);
        goto after_0;
    // 0x80092A30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80092A34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80092A38: jal         0x8009359C
    // 0x80092A3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009359C(rdram, ctx);
        goto after_1;
    // 0x80092A3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80092A40: lw          $t6, 0x50($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X50);
    // 0x80092A44: jal         0x800ADFE0
    // 0x80092A48: lh          $a0, 0x0($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X0);
    func_800ADFE0(rdram, ctx);
        goto after_2;
    // 0x80092A48: lh          $a0, 0x0($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X0);
    after_2:
    // 0x80092A4C: lw          $t7, 0x50($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X50);
    // 0x80092A50: sh          $zero, 0x0($t7)
    MEM_H(0X0, ctx->r15) = 0;
    // 0x80092A54: lw          $t8, 0x50($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X50);
    // 0x80092A58: jal         0x800DBFD8
    // 0x80092A5C: lw          $a0, 0x4($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X4);
    func_800DBFD8(rdram, ctx);
        goto after_3;
    // 0x80092A5C: lw          $a0, 0x4($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X4);
    after_3:
    // 0x80092A60: lw          $t9, 0x50($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X50);
    // 0x80092A64: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x80092A68: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x80092A6C: lw          $a0, 0x84($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X84);
    // 0x80092A70: beql        $a0, $zero, L_80092A88
    if (ctx->r4 == 0) {
        // 0x80092A74: sw          $zero, 0x84($v0)
        MEM_W(0X84, ctx->r2) = 0;
            goto L_80092A88;
    }
    goto skip_0;
    // 0x80092A74: sw          $zero, 0x84($v0)
    MEM_W(0X84, ctx->r2) = 0;
    skip_0:
    // 0x80092A78: jal         0x800A70B0
    // 0x80092A7C: nop

    func_800A70B0(rdram, ctx);
        goto after_4;
    // 0x80092A7C: nop

    after_4:
    // 0x80092A80: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x80092A84: sw          $zero, 0x84($v0)
    MEM_W(0X84, ctx->r2) = 0;
L_80092A88:
    // 0x80092A88: jal         0x80084528
    // 0x80092A8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babackpack_entrypoint_8(rdram, ctx);
        goto after_5;
    // 0x80092A8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80092A90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80092A94: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80092A98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80092A9C: jr          $ra
    // 0x80092AA0: nop

    return;
    // 0x80092AA0: nop

;}
RECOMP_FUNC void chfactorytoxicpools_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800500: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800504: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800508: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080050C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80800510: addiu       $a0, $zero, 0x166
    ctx->r4 = ADD32(0, 0X166);
    // 0x80800514: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800518: jal         0x800DA298
    // 0x8080051C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x8080051C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800520: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800524: beq         $v0, $zero, L_80800534
    if (ctx->r2 == 0) {
        // 0x80800528: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_80800534;
    }
    // 0x80800528: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8080052C: b           L_80800538
    // 0x80800530: addiu       $v0, $zero, -0x12C
    ctx->r2 = ADD32(0, -0X12C);
        goto L_80800538;
    // 0x80800530: addiu       $v0, $zero, -0x12C
    ctx->r2 = ADD32(0, -0X12C);
L_80800534:
    // 0x80800534: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800538:
    // 0x80800538: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8080053C: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80800540: addu        $v1, $t7, $a1
    ctx->r3 = ADD32(ctx->r15, ctx->r5);
    // 0x80800544: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x80800548: beql        $at, $zero, L_80800570
    if (ctx->r1 == 0) {
        // 0x8080054C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800570;
    }
    goto skip_0;
    // 0x8080054C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_80800550:
    // 0x80800550: lh          $t8, 0x2($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X2);
    // 0x80800554: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80800558: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x8080055C: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x80800560: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x80800564: bne         $at, $zero, L_80800550
    if (ctx->r1 != 0) {
        // 0x80800568: sh          $t9, -0xE($a2)
        MEM_H(-0XE, ctx->r6) = ctx->r25;
            goto L_80800550;
    }
    // 0x80800568: sh          $t9, -0xE($a2)
    MEM_H(-0XE, ctx->r6) = ctx->r25;
    // 0x8080056C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800570:
    // 0x80800570: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800574: jr          $ra
    // 0x80800578: nop

    return;
    // 0x80800578: nop

;}
RECOMP_FUNC void func_800E0B8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E0B8C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800E0B90: lh          $t7, 0x6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X6);
    // 0x800E0B94: lh          $v0, 0x4($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X4);
    // 0x800E0B98: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800E0B9C: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x800E0BA0: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800E0BA4: beq         $at, $zero, L_800E0C18
    if (ctx->r1 == 0) {
        // 0x800E0BA8: andi        $t6, $a1, 0xFF
        ctx->r14 = ctx->r5 & 0XFF;
            goto L_800E0C18;
    }
    // 0x800E0BA8: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800E0BAC: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x800E0BB0: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x800E0BB4: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x800E0BB8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800E0BBC: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    // 0x800E0BC0: sh          $t0, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r8;
    // 0x800E0BC4: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x800E0BC8: swc1        $f12, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f12.u32l;
    // 0x800E0BCC: swc1        $f14, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f14.u32l;
    // 0x800E0BD0: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800E0BD4: sra         $t2, $t6, 5
    ctx->r10 = S32(SIGNED(ctx->r14) >> 5);
    // 0x800E0BD8: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x800E0BDC: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
    // 0x800E0BE0: lwc1        $f6, 0x14($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800E0BE4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800E0BE8: sb          $t1, 0x11($v1)
    MEM_B(0X11, ctx->r3) = ctx->r9;
    // 0x800E0BEC: sb          $t6, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r14;
    // 0x800E0BF0: addu        $a3, $a0, $t3
    ctx->r7 = ADD32(ctx->r4, ctx->r11);
    // 0x800E0BF4: swc1        $f6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f6.u32l;
    // 0x800E0BF8: lw          $t4, 0x10($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X10);
    // 0x800E0BFC: andi        $t5, $t6, 0x1F
    ctx->r13 = ctx->r14 & 0X1F;
    // 0x800E0C00: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800E0C04: sllv        $t7, $t6, $t5
    ctx->r15 = S32(ctx->r14 << (ctx->r13 & 31));
    // 0x800E0C08: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x800E0C0C: sw          $t8, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r24;
    // 0x800E0C10: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800E0C14: sb          $t9, 0x9($a0)
    MEM_B(0X9, ctx->r4) = ctx->r25;
L_800E0C18:
    // 0x800E0C18: jr          $ra
    // 0x800E0C1C: nop

    return;
    // 0x800E0C1C: nop

;}
RECOMP_FUNC void func_8002AA74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AA74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002AA78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002AA7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8002AA80: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8002AA84: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8002AA88: lh          $t6, 0x1E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1E);
    // 0x8002AA8C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8002AA90: bne         $t6, $at, L_8002AACC
    if (ctx->r14 != ctx->r1) {
        // 0x8002AA94: nop
    
            goto L_8002AACC;
    }
    // 0x8002AA94: nop

    // 0x8002AA98: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8002AA9C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8002AAA0: lwc1        $f8, 0x1D30($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1D30);
    // 0x8002AAA4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8002AAA8: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8002AAAC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8002AAB0: nop

    // 0x8002AAB4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002AAB8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8002AABC: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8002AAC0: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x8002AAC4: b           L_8002AAEC
    // 0x8002AAC8: sh          $t0, 0x2($t1)
    MEM_H(0X2, ctx->r9) = ctx->r8;
        goto L_8002AAEC;
    // 0x8002AAC8: sh          $t0, 0x2($t1)
    MEM_H(0X2, ctx->r9) = ctx->r8;
L_8002AACC:
    // 0x8002AACC: lh          $t2, 0x1E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X1E);
    // 0x8002AAD0: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8002AAD4: bne         $t2, $at, L_8002AAEC
    if (ctx->r10 != ctx->r1) {
        // 0x8002AAD8: nop
    
            goto L_8002AAEC;
    }
    // 0x8002AAD8: nop

    // 0x8002AADC: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8002AAE0: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8002AAE4: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8002AAE8: sh          $t4, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r12;
L_8002AAEC:
    // 0x8002AAEC: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8002AAF0: lw          $t6, 0x11F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11F4);
    // 0x8002AAF4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8002AAF8: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x8002AAFC: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8002AB00: nop

    // 0x8002AB04: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8002AB08: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8002AB0C: jal         0x80028C04
    // 0x8002AB10: nop

    func_80028C04(rdram, ctx);
        goto after_0;
    // 0x8002AB10: nop

    after_0:
    // 0x8002AB14: b           L_8002AB1C
    // 0x8002AB18: nop

        goto L_8002AB1C;
    // 0x8002AB18: nop

L_8002AB1C:
    // 0x8002AB1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002AB20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002AB24: jr          $ra
    // 0x8002AB28: nop

    return;
    // 0x8002AB28: nop

    // 0x8002AB2C: nop

;}
RECOMP_FUNC void chfiregen_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1588, 0X171C) << 16);
    // 0x808000E4: jr          $ra
    // 0x808000E8: addiu       $v0, $v0, 0x171C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1588, 0X171C));
    return;
    // 0x808000E8: addiu       $v0, $v0, 0x171C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1588, 0X171C));
;}
RECOMP_FUNC void gccubeDll_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800998: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080099C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808009A0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808009A4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808009A8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808009AC: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x808009B0: jal         0x800BE52C
    // 0x808009B4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800BE52C(rdram, ctx);
        goto after_0;
    // 0x808009B4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x808009B8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808009BC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x808009C0: sltu        $at, $a0, $t6
    ctx->r1 = ctx->r4 < ctx->r14 ? 1 : 0;
    // 0x808009C4: beql        $at, $zero, L_80800A30
    if (ctx->r1 == 0) {
        // 0x808009C8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800A30;
    }
    goto skip_0;
    // 0x808009C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_808009CC:
    // 0x808009CC: jal         0x800E9D68
    // 0x808009D0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_800E9D68(rdram, ctx);
        goto after_1;
    // 0x808009D0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_1:
    // 0x808009D4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808009D8: jal         0x800E9D90
    // 0x808009DC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    func_800E9D90(rdram, ctx);
        goto after_2;
    // 0x808009DC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_2:
    // 0x808009E0: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x808009E4: beq         $at, $zero, L_80800A14
    if (ctx->r1 == 0) {
        // 0x808009E8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800A14;
    }
    // 0x808009E8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808009EC: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
L_808009F0:
    // 0x808009F0: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x808009F4: srl         $t7, $v0, 21
    ctx->r15 = S32(U32(ctx->r2) >> 21);
    // 0x808009F8: sltu        $at, $s1, $t7
    ctx->r1 = ctx->r17 < ctx->r15 ? 1 : 0;
    // 0x808009FC: beql        $at, $zero, L_80800A0C
    if (ctx->r1 == 0) {
        // 0x80800A00: sltu        $at, $s0, $v1
        ctx->r1 = ctx->r16 < ctx->r3 ? 1 : 0;
            goto L_80800A0C;
    }
    goto skip_1;
    // 0x80800A00: sltu        $at, $s0, $v1
    ctx->r1 = ctx->r16 < ctx->r3 ? 1 : 0;
    skip_1:
    // 0x80800A04: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x80800A08: sltu        $at, $s0, $v1
    ctx->r1 = ctx->r16 < ctx->r3 ? 1 : 0;
L_80800A0C:
    // 0x80800A0C: bnel        $at, $zero, L_808009F0
    if (ctx->r1 != 0) {
        // 0x80800A10: lw          $v0, 0x10($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X10);
            goto L_808009F0;
    }
    goto skip_2;
    // 0x80800A10: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    skip_2:
L_80800A14:
    // 0x80800A14: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800A18: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80800A1C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80800A20: sltu        $at, $a0, $t8
    ctx->r1 = ctx->r4 < ctx->r24 ? 1 : 0;
    // 0x80800A24: bne         $at, $zero, L_808009CC
    if (ctx->r1 != 0) {
        // 0x80800A28: nop
    
            goto L_808009CC;
    }
    // 0x80800A28: nop

    // 0x80800A2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800A30:
    // 0x80800A30: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80800A34: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800A38: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800A3C: jr          $ra
    // 0x80800A40: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800A40: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800A44: nop

    // 0x80800A48: nop

    // 0x80800A4C: nop

;}
RECOMP_FUNC void _gcmapsects_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087F30: syscall     662
    recomp_syscall_handler(rdram, ctx, 0x80087F30);
    return;
    // 0x80087F34: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void ncbaledge_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080008C: jr          $ra
    // 0x80800090: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800090: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void _bswalk_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800841F8: syscall     107
    recomp_syscall_handler(rdram, ctx, 0x800841F8);
    return;
    // 0x800841FC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80800478_gcdialogexec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800478: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080047C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800480: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800484: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800488: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8080048C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800490: beql        $v0, $zero, L_808004E0
    if (ctx->r2 == 0) {
        // 0x80800494: lw          $a0, 0x168($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X168);
            goto L_808004E0;
    }
    goto skip_0;
    // 0x80800494: lw          $a0, 0x168($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X168);
    skip_0:
    // 0x80800498: lw          $a0, 0x168($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X168);
    // 0x8080049C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x808004A0: bne         $a0, $zero, L_808004B8
    if (ctx->r4 != 0) {
        // 0x808004A4: nop
    
            goto L_808004B8;
    }
    // 0x808004A4: nop

    // 0x808004A8: jalr        $v0
    // 0x808004AC: lh          $a1, 0x162($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X162);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x808004AC: lh          $a1, 0x162($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X162);
    after_0:
    // 0x808004B0: b           L_808004E0
    // 0x808004B4: lw          $a0, 0x168($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X168);
        goto L_808004E0;
    // 0x808004B4: lw          $a0, 0x168($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X168);
L_808004B8:
    // 0x808004B8: jal         0x80800000
    // 0x808004BC: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    func_80800000_gcdialogexec(rdram, ctx);
        goto after_1;
    // 0x808004BC: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    after_1:
    // 0x808004C0: beql        $v0, $zero, L_808004E0
    if (ctx->r2 == 0) {
        // 0x808004C4: lw          $a0, 0x168($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X168);
            goto L_808004E0;
    }
    goto skip_1;
    // 0x808004C4: lw          $a0, 0x168($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X168);
    skip_1:
    // 0x808004C8: lw          $t9, 0x174($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X174);
    // 0x808004CC: lw          $a0, 0x168($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X168);
    // 0x808004D0: lh          $a1, 0x162($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X162);
    // 0x808004D4: jalr        $t9
    // 0x808004D8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x808004D8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x808004DC: lw          $a0, 0x168($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X168);
L_808004E0:
    // 0x808004E0: beql        $a0, $zero, L_8080051C
    if (ctx->r4 == 0) {
        // 0x808004E4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080051C;
    }
    goto skip_2;
    // 0x808004E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x808004E8: jal         0x80800000
    // 0x808004EC: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    func_80800000_gcdialogexec(rdram, ctx);
        goto after_3;
    // 0x808004EC: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    after_3:
    // 0x808004F0: beql        $v0, $zero, L_8080051C
    if (ctx->r2 == 0) {
        // 0x808004F4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080051C;
    }
    goto skip_3;
    // 0x808004F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x808004F8: lw          $a0, 0x168($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X168);
    // 0x808004FC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80800500: lhu         $t6, 0x18($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X18);
    // 0x80800504: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80800508: beql        $t7, $zero, L_8080051C
    if (ctx->r15 == 0) {
        // 0x8080050C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080051C;
    }
    goto skip_4;
    // 0x8080050C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80800510: jal         0x8008A218
    // 0x80800514: lh          $a1, 0x162($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X162);
    _subaddiedialog_entrypoint_13(rdram, ctx);
        goto after_4;
    // 0x80800514: lh          $a1, 0x162($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X162);
    after_4:
    // 0x80800518: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080051C:
    // 0x8080051C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800520: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800524: jr          $ra
    // 0x80800528: nop

    return;
    // 0x80800528: nop

;}
RECOMP_FUNC void func_800A3904(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3904: lw          $t6, 0xA0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA0);
    // 0x800A3908: jr          $ra
    // 0x800A390C: sb          $a1, 0x3E($t6)
    MEM_B(0X3E, ctx->r14) = ctx->r5;
    return;
    // 0x800A390C: sb          $a1, 0x3E($t6)
    MEM_B(0X3E, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void _suexpressmorph_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089B48: syscall     803
    recomp_syscall_handler(rdram, ctx, 0x80089B48);
    return;
    // 0x80089B4C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _bamovespline_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084E88: syscall     140
    recomp_syscall_handler(rdram, ctx, 0x80084E88);
    return;
    // 0x80084E8C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _subaddiefind_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089C68: syscall     807
    recomp_syscall_handler(rdram, ctx, 0x80089C68);
    return;
    // 0x80089C6C: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_80800170_chbottlesparty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800170: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800174: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800178: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080017C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800180: jal         0x800DA298
    // 0x80800184: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800184: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    after_0:
    // 0x80800188: bnel        $v0, $zero, L_8080021C
    if (ctx->r2 != 0) {
        // 0x8080018C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080021C;
    }
    goto skip_0;
    // 0x8080018C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800190: jal         0x800DA298
    // 0x80800194: addiu       $a0, $zero, 0x67C
    ctx->r4 = ADD32(0, 0X67C);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800194: addiu       $a0, $zero, 0x67C
    ctx->r4 = ADD32(0, 0X67C);
    after_1:
    // 0x80800198: bne         $v0, $zero, L_808001B8
    if (ctx->r2 != 0) {
        // 0x8080019C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001B8;
    }
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1508, 0X4B0) << 16);
    // 0x808001A4: addiu       $a2, $a2, 0x4B0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1508, 0X4B0));
    // 0x808001A8: jal         0x8008A1E8
    // 0x808001AC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_7(rdram, ctx);
        goto after_2;
    // 0x808001AC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_2:
    // 0x808001B0: b           L_8080021C
    // 0x808001B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080021C;
    // 0x808001B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001B8:
    // 0x808001B8: jal         0x800F54E4
    // 0x808001BC: nop

    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x808001BC: nop

    after_3:
    // 0x808001C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001C4: jal         0x800F64A4
    // 0x808001C8: addiu       $a1, $zero, 0x601
    ctx->r5 = ADD32(0, 0X601);
    func_800F64A4(rdram, ctx);
        goto after_4;
    // 0x808001C8: addiu       $a1, $zero, 0x601
    ctx->r5 = ADD32(0, 0X601);
    after_4:
    // 0x808001CC: beq         $v0, $zero, L_80800218
    if (ctx->r2 == 0) {
        // 0x808001D0: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80800218;
    }
    // 0x808001D0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808001D4: jal         0x8010CAC0
    // 0x808001D8: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    func_8010CAC0(rdram, ctx);
        goto after_5;
    // 0x808001D8: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    after_5:
    // 0x808001DC: beql        $v0, $zero, L_8080021C
    if (ctx->r2 == 0) {
        // 0x808001E0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080021C;
    }
    goto skip_1;
    // 0x808001E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x808001E4: jal         0x800D90A4
    // 0x808001E8: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800D90A4(rdram, ctx);
        goto after_6;
    // 0x808001E8: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_6:
    // 0x808001EC: beq         $v0, $zero, L_80800218
    if (ctx->r2 == 0) {
        // 0x808001F0: addiu       $a1, $zero, 0x154F
        ctx->r5 = ADD32(0, 0X154F);
            goto L_80800218;
    }
    // 0x808001F0: addiu       $a1, $zero, 0x154F
    ctx->r5 = ADD32(0, 0X154F);
    // 0x808001F4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808001F8: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x808001FC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800200: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800204: jal         0x8008A208
    // 0x80800208: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_7;
    // 0x80800208: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800210: jal         0x80101FDC
    // 0x80800214: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_8;
    // 0x80800214: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
L_80800218:
    // 0x80800218: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080021C:
    // 0x8080021C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800220: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800224: jr          $ra
    // 0x80800228: nop

    return;
    // 0x80800228: nop

;}
RECOMP_FUNC void func_80800ABC_chboggygirl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800ABC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800AC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800AC4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800AC8: jal         0x80100094
    // 0x80800ACC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800ACC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800AD0: bne         $v0, $zero, L_80800B18
    if (ctx->r2 != 0) {
        // 0x80800AD4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800B18;
    }
    // 0x80800AD4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800AD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800ADC: jal         0x800897C0
    // 0x80800AE0: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x80800AE0: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    after_1:
    // 0x80800AE4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800AE8: jal         0x80100094
    // 0x80800AEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80800AEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800AF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800AF4: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x80800AF8: jal         0x800897E8
    // 0x80800AFC: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_3;
    // 0x80800AFC: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    after_3:
    // 0x80800B00: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800B04: jal         0x80100094
    // 0x80800B08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x80800B08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800B0C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800B10: jal         0x80089810
    // 0x80800B14: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    _suexpression_entrypoint_17(rdram, ctx);
        goto after_5;
    // 0x80800B14: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    after_5:
L_80800B18:
    // 0x80800B18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B20: jr          $ra
    // 0x80800B24: nop

    return;
    // 0x80800B24: nop

;}
RECOMP_FUNC void func_80800CA8_gcboundDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CA8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80800CAC: beq         $a1, $zero, L_80800CC4
    if (ctx->r5 == 0) {
        // 0x80800CB0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80800CC4;
    }
    // 0x80800CB0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800CB4: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x80800CB8: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x80800CBC: bne         $a2, $t6, L_80800CCC
    if (ctx->r6 != ctx->r14) {
        // 0x80800CC0: sll         $t8, $t7, 3
        ctx->r24 = S32(ctx->r15 << 3);
            goto L_80800CCC;
    }
    // 0x80800CC0: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
L_80800CC4:
    // 0x80800CC4: jr          $ra
    // 0x80800CC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80800CC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800CCC:
    // 0x80800CCC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80800CD0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800CD4: addu        $t0, $t8, $a1
    ctx->r8 = ADD32(ctx->r24, ctx->r5);
    // 0x80800CD8: sltu        $at, $a1, $t0
    ctx->r1 = ctx->r5 < ctx->r8 ? 1 : 0;
    // 0x80800CDC: beq         $at, $zero, L_80800D34
    if (ctx->r1 == 0) {
        // 0x80800CE0: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80800D34;
    }
    // 0x80800CE0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800CE4: lh          $a1, 0x18($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X18);
L_80800CE8:
    // 0x80800CE8: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80800CEC: bnel        $at, $zero, L_80800D28
    if (ctx->r1 != 0) {
        // 0x80800CF0: addiu       $a0, $a0, 0x1C
        ctx->r4 = ADD32(ctx->r4, 0X1C);
            goto L_80800D28;
    }
    goto skip_0;
    // 0x80800CF0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    skip_0:
    // 0x80800CF4: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80800CF8: beq         $v0, $zero, L_80800D08
    if (ctx->r2 == 0) {
        // 0x80800CFC: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80800D08;
    }
    // 0x80800CFC: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800D00: beq         $at, $zero, L_80800D14
    if (ctx->r1 == 0) {
        // 0x80800D04: nop
    
            goto L_80800D14;
    }
    // 0x80800D04: nop

L_80800D08:
    // 0x80800D08: sw          $a1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r5;
    // 0x80800D0C: lh          $a1, 0x18($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X18);
    // 0x80800D10: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_80800D14:
    // 0x80800D14: bnel        $a2, $a1, L_80800D28
    if (ctx->r6 != ctx->r5) {
        // 0x80800D18: addiu       $a0, $a0, 0x1C
        ctx->r4 = ADD32(ctx->r4, 0X1C);
            goto L_80800D28;
    }
    goto skip_1;
    // 0x80800D18: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    skip_1:
    // 0x80800D1C: jr          $ra
    // 0x80800D20: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80800D20: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80800D24: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
L_80800D28:
    // 0x80800D28: sltu        $at, $a0, $t0
    ctx->r1 = ctx->r4 < ctx->r8 ? 1 : 0;
    // 0x80800D2C: bnel        $at, $zero, L_80800CE8
    if (ctx->r1 != 0) {
        // 0x80800D30: lh          $a1, 0x18($a0)
        ctx->r5 = MEM_H(ctx->r4, 0X18);
            goto L_80800CE8;
    }
    goto skip_2;
    // 0x80800D30: lh          $a1, 0x18($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X18);
    skip_2:
L_80800D34:
    // 0x80800D34: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800D38: jr          $ra
    // 0x80800D3C: nop

    return;
    // 0x80800D3C: nop

;}
RECOMP_FUNC void freelist_capacity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3034: jr          $ra
    // 0x800B3038: lh          $v0, 0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2);
    return;
    // 0x800B3038: lh          $v0, 0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2);
;}
RECOMP_FUNC void func_800EEB40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EEB40: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800EEB44: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800EEB48: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800EEB4C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800EEB50: swc1        $f8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f8.u32l;
    // 0x800EEB54: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800EEB58: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800EEB5C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800EEB60: lwc1        $f10, 0x4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800EEB64: swc1        $f18, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f18.u32l;
    // 0x800EEB68: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800EEB6C: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800EEB70: mul.s       $f16, $f10, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800EEB74: lwc1        $f18, 0x8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800EEB78: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800EEB7C: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800EEB80: swc1        $f8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f8.u32l;
    // 0x800EEB84: lwc1        $f8, 0xC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800EEB88: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x800EEB8C: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x800EEB90: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800EEB94: jr          $ra
    // 0x800EEB98: add.s       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f6.fl;
    return;
    // 0x800EEB98: add.s       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f6.fl;
;}
RECOMP_FUNC void chcoderoomdoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1948, 0XE0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xE0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1948, 0XE0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xE0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1948, 0XE0));
;}
RECOMP_FUNC void func_80103D48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103D48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103D4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80103D50: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80103D54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80103D58: jal         0x800D70F8
    // 0x80103D5C: lhu         $a0, 0x14($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X14);
    func_800D70F8(rdram, ctx);
        goto after_0;
    // 0x80103D5C: lhu         $a0, 0x14($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X14);
    after_0:
    // 0x80103D60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80103D64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80103D68: jr          $ra
    // 0x80103D6C: nop

    return;
    // 0x80103D6C: nop

;}
RECOMP_FUNC void _subaddiedraw25d_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089C18: syscall     806
    recomp_syscall_handler(rdram, ctx, 0x80089C18);
    return;
    // 0x80089C1C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800114_sucoasterhit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800114: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800118: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080011C: jal         0x80106790
    // 0x80800120: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800120: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800124: lw          $t6, 0x78($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X78);
    // 0x80800128: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080012C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800130: sll         $t8, $t6, 29
    ctx->r24 = S32(ctx->r14 << 29);
    // 0x80800134: bltzl       $t8, L_808001BC
    if (SIGNED(ctx->r24) < 0) {
        // 0x80800138: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808001BC;
    }
    goto skip_0;
    // 0x80800138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080013C: jal         0x80100094
    // 0x80800140: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800140: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800144: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80800148: addiu       $at, $zero, 0x27D
    ctx->r1 = ADD32(0, 0X27D);
    // 0x8080014C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800150: lw          $t0, 0x24($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X24);
    // 0x80800154: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800158: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x8080015C: srl         $t1, $t0, 22
    ctx->r9 = S32(U32(ctx->r8) >> 22);
    // 0x80800160: bne         $t1, $at, L_8080019C
    if (ctx->r9 != ctx->r1) {
        // 0x80800164: nop
    
            goto L_8080019C;
    }
    // 0x80800164: nop

    // 0x80800168: lhu         $t2, 0x72($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X72);
    // 0x8080016C: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80800170: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x80800174: srl         $t3, $t2, 10
    ctx->r11 = S32(U32(ctx->r10) >> 10);
    // 0x80800178: beq         $t3, $at, L_8080018C
    if (ctx->r11 == ctx->r1) {
        // 0x8080017C: addiu       $a2, $zero, 0x4
        ctx->r6 = ADD32(0, 0X4);
            goto L_8080018C;
    }
    // 0x8080017C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800180: jal         0x8008A140
    // 0x80800184: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    _sucoaster_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x80800184: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_2:
    // 0x80800188: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
L_8080018C:
    // 0x8080018C: lbu         $t5, 0x18($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X18);
    // 0x80800190: ori         $t6, $t5, 0x8
    ctx->r14 = ctx->r13 | 0X8;
    // 0x80800194: b           L_808001B8
    // 0x80800198: sb          $t6, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r14;
        goto L_808001B8;
    // 0x80800198: sb          $t6, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r14;
L_8080019C:
    // 0x8080019C: jal         0x801021BC
    // 0x808001A0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_801021BC(rdram, ctx);
        goto after_3;
    // 0x808001A0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_3:
    // 0x808001A4: beq         $v0, $zero, L_808001B8
    if (ctx->r2 == 0) {
        // 0x808001A8: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_808001B8;
    }
    // 0x808001A8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808001AC: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x808001B0: jal         0x8008A140
    // 0x808001B4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    _sucoaster_entrypoint_9(rdram, ctx);
        goto after_4;
    // 0x808001B4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_4:
L_808001B8:
    // 0x808001B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001BC:
    // 0x808001BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001C0: jr          $ra
    // 0x808001C4: nop

    return;
    // 0x808001C4: nop

;}
RECOMP_FUNC void heap_alloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001ACCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001ACD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001ACD4: jal         0x8001ACEC
    // 0x8001ACD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    heap_alloc_sided(rdram, ctx);
        goto after_0;
    // 0x8001ACD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8001ACDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001ACE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001ACE4: jr          $ra
    // 0x8001ACE8: nop

    return;
    // 0x8001ACE8: nop

;}
RECOMP_FUNC void func_8009BB24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BB24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009BB28: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8009BB2C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8009BB30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009BB34: lw          $a1, 0xC8($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XC8);
    // 0x8009BB38: jal         0x800EE7F8
    // 0x8009BB3C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8009BB3C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_0:
    // 0x8009BB40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009BB44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009BB48: jr          $ra
    // 0x8009BB4C: nop

    return;
    // 0x8009BB4C: nop

;}
RECOMP_FUNC void _bsbanpackwhack_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082690: syscall     6
    recomp_syscall_handler(rdram, ctx, 0x80082690);
    return;
    // 0x80082694: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chbosskogsdoor_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087500: syscall     581
    recomp_syscall_handler(rdram, ctx, 0x80087500);
    return;
    // 0x80087504: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800284_chlagoonfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800284: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800288: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080028C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800290: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800294: jal         0x80102B6C
    // 0x80800298: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_80102B6C(rdram, ctx);
        goto after_0;
    // 0x80800298: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_0:
    // 0x8080029C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A0: jal         0x80102B2C
    // 0x808002A4: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_80102B2C(rdram, ctx);
        goto after_1;
    // 0x808002A4: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_1:
    // 0x808002A8: lui         $a1, 0x50
    ctx->r5 = S32(0X50 << 16);
    // 0x808002AC: ori         $a1, $a1, 0x106
    ctx->r5 = ctx->r5 | 0X106;
    // 0x808002B0: jal         0x8010B990
    // 0x808002B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010B990(rdram, ctx);
        goto after_2;
    // 0x808002B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808002B8: andi        $t6, $v0, 0x24
    ctx->r14 = ctx->r2 & 0X24;
    // 0x808002BC: beql        $t6, $zero, L_808002E8
    if (ctx->r14 == 0) {
        // 0x808002C0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808002E8;
    }
    goto skip_0;
    // 0x808002C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808002C4: lhu         $t7, 0x72($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X72);
    // 0x808002C8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808002CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002D0: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x808002D4: beql        $t8, $at, L_808002E8
    if (ctx->r24 == ctx->r1) {
        // 0x808002D8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808002E8;
    }
    goto skip_1;
    // 0x808002D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x808002DC: jal         0x80800A44
    // 0x808002E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800A44_chlagoonfish(rdram, ctx);
        goto after_3;
    // 0x808002E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x808002E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002E8:
    // 0x808002E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002F0: jr          $ra
    // 0x808002F4: nop

    return;
    // 0x808002F4: nop

;}
RECOMP_FUNC void func_808005CC_chskeletonexplode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005CC: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x808005D0: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x808005D4: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x808005D8: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x808005DC: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x808005E0: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x808005E4: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x808005E8: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x808005EC: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x808005F0: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x808005F4: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x808005F8: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x808005FC: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80800600: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80800604: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800608: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8080060C: sw          $a2, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r6;
    // 0x80800610: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800614: jal         0x801039E4
    // 0x80800618: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_801039E4(rdram, ctx);
        goto after_0;
    // 0x80800618: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x8080061C: jal         0x800B27E0
    // 0x80800620: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B27E0(rdram, ctx);
        goto after_1;
    // 0x80800620: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800624: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80800628: jal         0x80104248
    // 0x8080062C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_2;
    // 0x8080062C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800630: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800634: jal         0x8008AEDC
    // 0x80800638: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8008AEDC(rdram, ctx);
        goto after_3;
    // 0x80800638: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x8080063C: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
    // 0x80800640: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800644: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800648: jal         0x8008C200
    // 0x8080064C: lh          $a0, 0x10($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X10);
    func_8008C200(rdram, ctx);
        goto after_4;
    // 0x8080064C: lh          $a0, 0x10($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X10);
    after_4:
    // 0x80800650: jal         0x8008AEDC
    // 0x80800654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008AEDC(rdram, ctx);
        goto after_5;
    // 0x80800654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800658: jal         0x8008C27C
    // 0x8080065C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8008C27C(rdram, ctx);
        goto after_6;
    // 0x8080065C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x80800660: sw          $v0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r2;
    // 0x80800664: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x80800668: jal         0x800AE124
    // 0x8080066C: lh          $a0, 0x10($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X10);
    func_800AE124(rdram, ctx);
        goto after_7;
    // 0x8080066C: lh          $a0, 0x10($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X10);
    after_7:
    // 0x80800670: lhu         $t0, 0x6E($s5)
    ctx->r8 = MEM_HU(ctx->r21, 0X6E);
    // 0x80800674: andi        $t9, $v0, 0x1FF
    ctx->r25 = ctx->r2 & 0X1FF;
    // 0x80800678: lw          $t3, 0x0($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X0);
    // 0x8080067C: andi        $t1, $t0, 0xFE00
    ctx->r9 = ctx->r8 & 0XFE00;
    // 0x80800680: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80800684: sh          $t2, 0x6E($s5)
    MEM_H(0X6E, ctx->r21) = ctx->r10;
    // 0x80800688: jal         0x800AE080
    // 0x8080068C: lh          $a0, 0x10($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X10);
    func_800AE080(rdram, ctx);
        goto after_8;
    // 0x8080068C: lh          $a0, 0x10($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X10);
    after_8:
    // 0x80800690: lw          $a2, 0x6C($s5)
    ctx->r6 = MEM_W(ctx->r21, 0X6C);
    // 0x80800694: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x80800698: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8080069C: andi        $t4, $a2, 0x1FF
    ctx->r12 = ctx->r6 & 0X1FF;
    // 0x808006A0: sll         $a2, $t4, 6
    ctx->r6 = S32(ctx->r12 << 6);
    // 0x808006A4: jal         0x80100074
    // 0x808006A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100074(rdram, ctx);
        goto after_9;
    // 0x808006A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x808006AC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808006B0: jal         0x80100094
    // 0x808006B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_10;
    // 0x808006B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x808006B8: lw          $v1, 0x6C($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X6C);
    // 0x808006BC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808006C0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x808006C4: andi        $t6, $v1, 0x1FF
    ctx->r14 = ctx->r3 & 0X1FF;
    // 0x808006C8: beq         $t6, $zero, L_808007E4
    if (ctx->r14 == 0) {
        // 0x808006CC: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_808007E4;
    }
    // 0x808006CC: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x808006D0: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x808006D4: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x808006D8: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x808006DC: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x808006E0: addiu       $fp, $s5, 0x4
    ctx->r30 = ADD32(ctx->r21, 0X4);
    // 0x808006E4: addiu       $s6, $sp, 0x80
    ctx->r22 = ADD32(ctx->r29, 0X80);
L_808006E8:
    // 0x808006E8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808006EC: jal         0x80087A28
    // 0x808006F0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    _dbskeleton_entrypoint_4(rdram, ctx);
        goto after_11;
    // 0x808006F0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_11:
    // 0x808006F4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x808006F8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x808006FC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800700: jal         0x800ADE50
    // 0x80800704: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800ADE50(rdram, ctx);
        goto after_12;
    // 0x80800704: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_12:
    // 0x80800708: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080070C: jal         0x800F2C1C
    // 0x80800710: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    func_800F2C1C(rdram, ctx);
        goto after_13;
    // 0x80800710: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_13:
    // 0x80800714: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80800718: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8080071C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80800720: jal         0x800AE630
    // 0x80800724: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_800AE630(rdram, ctx);
        goto after_14;
    // 0x80800724: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_14:
    // 0x80800728: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8080072C: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x80800730: jal         0x800EE780
    // 0x80800734: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800EE780(rdram, ctx);
        goto after_15;
    // 0x80800734: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_15:
    // 0x80800738: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8080073C: jal         0x800F1DF4
    // 0x80800740: lw          $a1, 0xB8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB8);
    func_800F1DF4(rdram, ctx);
        goto after_16;
    // 0x80800740: lw          $a1, 0xB8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB8);
    after_16:
    // 0x80800744: lwc1        $f4, 0x48($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X48);
    // 0x80800748: addiu       $s1, $s0, 0xC
    ctx->r17 = ADD32(ctx->r16, 0XC);
    // 0x8080074C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80800750: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800754: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800758: jal         0x80087A18
    // 0x8080075C: sub.s       $f20, $f0, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f0.fl - ctx->f4.fl;
    _dbskeleton_entrypoint_2(rdram, ctx);
        goto after_17;
    // 0x8080075C: sub.s       $f20, $f0, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f0.fl - ctx->f4.fl;
    after_17:
    // 0x80800760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800764: jal         0x800EF3DC
    // 0x80800768: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EF3DC(rdram, ctx);
        goto after_18;
    // 0x80800768: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_18:
    // 0x8080076C: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x80800770: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800774: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800778: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080077C: jal         0x800DC178
    // 0x80800780: nop

    func_800DC178(rdram, ctx);
        goto after_19;
    // 0x80800780: nop

    after_19:
    // 0x80800784: lui         $at, 0xC282
    ctx->r1 = S32(0XC282 << 16);
    // 0x80800788: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080078C: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x80800790: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800794: jal         0x800DC178
    // 0x80800798: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    func_800DC178(rdram, ctx);
        goto after_20;
    // 0x80800798: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_20:
    // 0x8080079C: add.s       $f6, $f22, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f22.fl + ctx->f24.fl;
    // 0x808007A0: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x808007A4: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    // 0x808007A8: add.s       $f8, $f0, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x808007AC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808007B0: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x808007B4: jal         0x800EEC30
    // 0x808007B8: nop

    func_800EEC30(rdram, ctx);
        goto after_21;
    // 0x808007B8: nop

    after_21:
    // 0x808007BC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808007C0: sb          $t7, 0x3C($s0)
    MEM_B(0X3C, ctx->r16) = ctx->r15;
    // 0x808007C4: lw          $v1, 0x6C($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X6C);
    // 0x808007C8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x808007CC: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    // 0x808007D0: andi        $t8, $v1, 0x1FF
    ctx->r24 = ctx->r3 & 0X1FF;
    // 0x808007D4: sltu        $at, $s2, $t8
    ctx->r1 = ctx->r18 < ctx->r24 ? 1 : 0;
    // 0x808007D8: bne         $at, $zero, L_808006E8
    if (ctx->r1 != 0) {
        // 0x808007DC: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_808006E8;
    }
    // 0x808007DC: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x808007E0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_808007E4:
    // 0x808007E4: beq         $v1, $zero, L_80800854
    if (ctx->r3 == 0) {
        // 0x808007E8: addiu       $s1, $zero, 0x4
        ctx->r17 = ADD32(0, 0X4);
            goto L_80800854;
    }
    // 0x808007E8: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x808007EC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_808007F0:
    // 0x808007F0: jal         0x80100094
    // 0x808007F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_22;
    // 0x808007F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_22:
    // 0x808007F8: sll         $t0, $s2, 6
    ctx->r8 = S32(ctx->r18 << 6);
    // 0x808007FC: addu        $s0, $v0, $t0
    ctx->r16 = ADD32(ctx->r2, ctx->r8);
    // 0x80800800: lbu         $t9, 0x3C($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X3C);
    // 0x80800804: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800808: bnel        $s1, $t9, L_80800840
    if (ctx->r17 != ctx->r25) {
        // 0x8080080C: lw          $t1, 0x6C($s5)
        ctx->r9 = MEM_W(ctx->r21, 0X6C);
            goto L_80800840;
    }
    goto skip_0;
    // 0x8080080C: lw          $t1, 0x6C($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X6C);
    skip_0:
    // 0x80800810: jal         0x80087A28
    // 0x80800814: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    _dbskeleton_entrypoint_4(rdram, ctx);
        goto after_23;
    // 0x80800814: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_23:
    // 0x80800818: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x8080081C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800820: jal         0x800DFC20
    // 0x80800824: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800DFC20(rdram, ctx);
        goto after_24;
    // 0x80800824: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_24:
    // 0x80800828: jal         0x80087A10
    // 0x8080082C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    _dbskeleton_entrypoint_1(rdram, ctx);
        goto after_25;
    // 0x8080082C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_25:
    // 0x80800830: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800834: jal         0x800EF334
    // 0x80800838: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EF334(rdram, ctx);
        goto after_26;
    // 0x80800838: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x8080083C: lw          $t1, 0x6C($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X6C);
L_80800840:
    // 0x80800840: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800844: andi        $t2, $t1, 0x1FF
    ctx->r10 = ctx->r9 & 0X1FF;
    // 0x80800848: sltu        $at, $s2, $t2
    ctx->r1 = ctx->r18 < ctx->r10 ? 1 : 0;
    // 0x8080084C: bnel        $at, $zero, L_808007F0
    if (ctx->r1 != 0) {
        // 0x80800850: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_808007F0;
    }
    goto skip_1;
    // 0x80800850: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_1:
L_80800854:
    // 0x80800854: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80800858: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8080085C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800860: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80800864: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80800868: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8080086C: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80800870: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80800874: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80800878: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8080087C: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80800880: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x80800884: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x80800888: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x8080088C: jr          $ra
    // 0x80800890: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x80800890: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_80800A74_bsbeemain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800A78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A7C: jal         0x80082830
    // 0x80800A80: nop

    _bsbee_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800A80: nop

    after_0:
    // 0x80800A84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A8C: jr          $ra
    // 0x80800A90: nop

    return;
    // 0x80800A90: nop

;}
RECOMP_FUNC void func_800FC240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC240: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800FC244: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800FC248: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800FC24C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800FC250: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800FC254: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FC258: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800FC25C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800FC260: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800FC264: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800FC268: addiu       $s3, $s3, 0x5960
    ctx->r19 = ADD32(ctx->r19, 0X5960);
    // 0x800FC26C: addiu       $s0, $s0, 0x57D0
    ctx->r16 = ADD32(ctx->r16, 0X57D0);
    // 0x800FC270: lh          $a0, 0x28($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X28);
L_800FC274:
    // 0x800FC274: bltzl       $a0, L_800FC2A0
    if (SIGNED(ctx->r4) < 0) {
        // 0x800FC278: addiu       $s0, $s0, 0x50
        ctx->r16 = ADD32(ctx->r16, 0X50);
            goto L_800FC2A0;
    }
    goto skip_0;
    // 0x800FC278: addiu       $s0, $s0, 0x50
    ctx->r16 = ADD32(ctx->r16, 0X50);
    skip_0:
    // 0x800FC27C: jal         0x800FE7A8
    // 0x800FC280: nop

    func_800FE7A8(rdram, ctx);
        goto after_0;
    // 0x800FC280: nop

    after_0:
    // 0x800FC284: bne         $v0, $zero, L_800FC29C
    if (ctx->r2 != 0) {
        // 0x800FC288: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_800FC29C;
    }
    // 0x800FC288: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800FC28C: lh          $a0, 0x28($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X28);
    // 0x800FC290: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800FC294: jal         0x800FCB00
    // 0x800FC298: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800FCB00(rdram, ctx);
        goto after_1;
    // 0x800FC298: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
L_800FC29C:
    // 0x800FC29C: addiu       $s0, $s0, 0x50
    ctx->r16 = ADD32(ctx->r16, 0X50);
L_800FC2A0:
    // 0x800FC2A0: bnel        $s0, $s3, L_800FC274
    if (ctx->r16 != ctx->r19) {
        // 0x800FC2A4: lh          $a0, 0x28($s0)
        ctx->r4 = MEM_H(ctx->r16, 0X28);
            goto L_800FC274;
    }
    goto skip_1;
    // 0x800FC2A4: lh          $a0, 0x28($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X28);
    skip_1:
    // 0x800FC2A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800FC2AC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800FC2B0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800FC2B4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800FC2B8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800FC2BC: jr          $ra
    // 0x800FC2C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800FC2C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80800064_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800064: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800068: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080006C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800070: jal         0x80097AD0
    // 0x80800074: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    bainput_should_enter_first_person(rdram, ctx);
        goto after_0;
    // 0x80800074: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800078: beq         $v0, $zero, L_8080008C
    if (ctx->r2 == 0) {
        // 0x8080007C: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_8080008C;
    }
    // 0x8080007C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800080: jal         0x800848A8
    // 0x80800084: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _badrone_entrypoint_24(rdram, ctx);
        goto after_1;
    // 0x80800084: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800088: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8080008C:
    // 0x8080008C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800090: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80800094: jal         0x80091A58
    // 0x80800098: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    bakey_pressed(rdram, ctx);
        goto after_2;
    // 0x80800098: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x8080009C: beq         $v0, $zero, L_808000A8
    if (ctx->r2 == 0) {
        // 0x808000A0: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_808000A8;
    }
    // 0x808000A0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808000A4: addiu       $v1, $zero, 0x35
    ctx->r3 = ADD32(0, 0X35);
L_808000A8:
    // 0x808000A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000B0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x808000B4: jr          $ra
    // 0x808000B8: nop

    return;
    // 0x808000B8: nop

;}
RECOMP_FUNC void func_801060E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801060E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801060E8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801060EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801060F0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801060F4: lw          $a0, 0x6ED0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6ED0);
    // 0x801060F8: jal         0x800B301C
    // 0x801060FC: lh          $a1, 0x22($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X22);
    freelist_at(rdram, ctx);
        goto after_0;
    // 0x801060FC: lh          $a1, 0x22($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X22);
    after_0:
    // 0x80106100: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80106104: jal         0x800B2D28
    // 0x80106108: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    vector_free(rdram, ctx);
        goto after_1;
    // 0x80106108: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    after_1:
    // 0x8010610C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80106110: jal         0x80088898
    // 0x80106114: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    _glidmake_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80106114: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_2:
    // 0x80106118: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010611C: lw          $a0, 0x6ED0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6ED0);
    // 0x80106120: jal         0x800B32C0
    // 0x80106124: lh          $a1, 0x22($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X22);
    freelist_erase(rdram, ctx);
        goto after_3;
    // 0x80106124: lh          $a1, 0x22($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X22);
    after_3:
    // 0x80106128: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010612C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80106130: jr          $ra
    // 0x80106134: nop

    return;
    // 0x80106134: nop

;}
RECOMP_FUNC void _glhittableDll_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088628: syscall     696
    recomp_syscall_handler(rdram, ctx, 0x80088628);
    return;
    // 0x8008862C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void baflamethrower_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800180: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800184: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800188: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080018C: jal         0x80084B70
    // 0x80800190: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _baflameline_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800190: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800194: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800198: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8080019C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808001A0: lw          $t7, 0x88($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X88);
    // 0x808001A4: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x808001A8: lw          $t8, 0x88($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X88);
    // 0x808001AC: jal         0x80800088
    // 0x808001B0: sb          $zero, 0xC($t8)
    MEM_B(0XC, ctx->r24) = 0;
    func_80800088_baflamethrower(rdram, ctx);
        goto after_1;
    // 0x808001B0: sb          $zero, 0xC($t8)
    MEM_B(0XC, ctx->r24) = 0;
    after_1:
    // 0x808001B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001BC: jr          $ra
    // 0x808001C0: nop

    return;
    // 0x808001C0: nop

;}
