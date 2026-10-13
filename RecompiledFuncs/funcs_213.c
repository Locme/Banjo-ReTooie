#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_8001A080(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A080: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001A084: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001A088: lui         $a0, 0x2
    ctx->r4 = S32(0X2 << 16);
    // 0x8001A08C: jal         0x8001A018
    // 0x8001A090: ori         $a0, $a0, 0x1D80
    ctx->r4 = ctx->r4 | 0X1D80;
    func_8001A018(rdram, ctx);
        goto after_0;
    // 0x8001A090: ori         $a0, $a0, 0x1D80
    ctx->r4 = ctx->r4 | 0X1D80;
    after_0:
    // 0x8001A094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001A098: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001A09C: sw          $v0, -0x433C($at)
    MEM_W(-0X433C, ctx->r1) = ctx->r2;
    // 0x8001A0A0: jr          $ra
    // 0x8001A0A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8001A0A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void bsvan_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003BC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808003C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808003C4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808003C8: jal         0x8009C990
    // 0x808003CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_0;
    // 0x808003CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808003D0: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x808003D4: jal         0x8009C984
    // 0x808003D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_1;
    // 0x808003D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808003DC: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808003E0: jal         0x800F1DCC
    // 0x808003E4: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    func_800F1DCC(rdram, ctx);
        goto after_2;
    // 0x808003E4: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    after_2:
    // 0x808003E8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808003EC: jal         0x80085390
    // 0x808003F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bavan_entrypoint_5(rdram, ctx);
        goto after_3;
    // 0x808003F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808003F4: jal         0x8009BB5C
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB5C(rdram, ctx);
        goto after_4;
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808003FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800400: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800404: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800408: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8080040C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800410: lui         $a2, 0x4461
    ctx->r6 = S32(0X4461 << 16);
    // 0x80800414: bc1fl       L_80800440
    if (!c1cs) {
        // 0x80800418: mtc1        $zero, $f12
        ctx->f12.u32l = 0;
            goto L_80800440;
    }
    goto skip_0;
    // 0x80800418: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    skip_0:
    // 0x8080041C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800420: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(427, 0X1A74) << 16);
    // 0x80800424: lwc1        $f6, 0x1A74($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(427, 0X1A74));
    // 0x80800428: lui         $a3, 0x4234
    ctx->r7 = S32(0X4234 << 16);
    // 0x8080042C: jal         0x800F10B4
    // 0x80800430: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_5;
    // 0x80800430: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x80800434: b           L_80800444
    // 0x80800438: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
        goto L_80800444;
    // 0x80800438: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8080043C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
L_80800440:
    // 0x80800440: nop

L_80800444:
    // 0x80800444: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80800448: jal         0x80085398
    // 0x8080044C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bavan_entrypoint_6(rdram, ctx);
        goto after_6;
    // 0x8080044C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800450: jal         0x8009BB5C
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB5C(rdram, ctx);
        goto after_7;
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800458: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8080045C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800460: lui         $a2, 0x4461
    ctx->r6 = S32(0X4461 << 16);
    // 0x80800464: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80800468: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x8080046C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(427, 0X1A78) << 16);
    // 0x80800470: bc1f        L_8080049C
    if (!c1cs) {
        // 0x80800474: nop
    
            goto L_8080049C;
    }
    // 0x80800474: nop

    // 0x80800478: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8080047C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800480: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x80800484: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800488: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8080048C: jal         0x800F10B4
    // 0x80800490: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_8;
    // 0x80800490: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_8:
    // 0x80800494: b           L_808004A0
    // 0x80800498: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_808004A0;
    // 0x80800498: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8080049C:
    // 0x8080049C: lwc1        $f2, 0x1A78($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(427, 0X1A78));
L_808004A0:
    // 0x808004A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004A4: jal         0x8008E078
    // 0x808004A8: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    player_isStable(rdram, ctx);
        goto after_9;
    // 0x808004A8: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    after_9:
    // 0x808004AC: bne         $v0, $zero, L_808004D0
    if (ctx->r2 != 0) {
        // 0x808004B0: lwc1        $f2, 0x3C($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
            goto L_808004D0;
    }
    // 0x808004B0: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808004B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(427, 0X1A7C) << 16);
    // 0x808004B8: lwc1        $f12, 0x1A7C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(427, 0X1A7C));
    // 0x808004BC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(427, 0X1A80) << 16);
    // 0x808004C0: lwc1        $f16, 0x1A80($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(427, 0X1A80));
    // 0x808004C4: jal         0x800F13F0
    // 0x808004C8: add.s       $f14, $f2, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f2.fl + ctx->f16.fl;
    func_800F13F0(rdram, ctx);
        goto after_10;
    // 0x808004C8: add.s       $f14, $f2, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f2.fl + ctx->f16.fl;
    after_10:
    // 0x808004CC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_808004D0:
    // 0x808004D0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x808004D4: jal         0x80085388
    // 0x808004D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bavan_entrypoint_4(rdram, ctx);
        goto after_11;
    // 0x808004D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808004DC: jal         0x800853A8
    // 0x808004E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bavan_entrypoint_8(rdram, ctx);
        goto after_12;
    // 0x808004E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808004E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808004E8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808004EC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808004F0: jr          $ra
    // 0x808004F4: nop

    return;
    // 0x808004F4: nop

;}
RECOMP_FUNC void ncbatarget_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800104: jr          $ra
    // 0x80800108: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800108: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void bsdronebubbled_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800040: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800048: lw          $t6, 0x54($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X54);
    // 0x8080004C: lw          $t7, 0x48($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X48);
    // 0x80800050: beql        $t7, $zero, L_80800064
    if (ctx->r15 == 0) {
        // 0x80800054: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800064;
    }
    goto skip_0;
    // 0x80800054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800058: jal         0x80800000
    // 0x8080005C: nop

    func_80800000_bsdronebubbled(rdram, ctx);
        goto after_0;
    // 0x8080005C: nop

    after_0:
    // 0x80800060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800064:
    // 0x80800064: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800068: jr          $ra
    // 0x8080006C: nop

    return;
    // 0x8080006C: nop

;}
RECOMP_FUNC void func_80800000_ncpodfixpos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800004: bnel        $a1, $at, L_80800018
    if (ctx->r5 != ctx->r1) {
        // 0x80800008: lhu         $t6, 0x12($a0)
        ctx->r14 = MEM_HU(ctx->r4, 0X12);
            goto L_80800018;
    }
    goto skip_0;
    // 0x80800008: lhu         $t6, 0x12($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X12);
    skip_0:
    // 0x8080000C: jr          $ra
    // 0x80800010: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80800010: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800014: lhu         $t6, 0x12($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X12);
L_80800018:
    // 0x80800018: srl         $t7, $t6, 1
    ctx->r15 = S32(U32(ctx->r14) >> 1);
    // 0x8080001C: xor         $v1, $a1, $t7
    ctx->r3 = ctx->r5 ^ ctx->r15;
    // 0x80800020: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80800024: jr          $ra
    // 0x80800028: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80800028: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void vector_erase(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2E30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B2E34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B2E38: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800B2E3C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800B2E40: addiu       $t8, $a1, 0x1
    ctx->r24 = ADD32(ctx->r5, 0X1);
    // 0x800B2E44: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800B2E48: multu       $a1, $v1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B2E4C: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x800B2E50: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x800B2E54: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x800B2E58: subu        $t1, $t9, $v0
    ctx->r9 = SUB32(ctx->r25, ctx->r2);
    // 0x800B2E5C: mflo        $t7
    ctx->r15 = lo;
    // 0x800B2E60: addu        $a0, $v0, $t7
    ctx->r4 = ADD32(ctx->r2, ctx->r15);
    // 0x800B2E64: nop

    // 0x800B2E68: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B2E6C: mflo        $t0
    ctx->r8 = lo;
    // 0x800B2E70: subu        $a2, $t1, $t0
    ctx->r6 = SUB32(ctx->r9, ctx->r8);
    // 0x800B2E74: jal         0x8001BBC8
    // 0x800B2E78: addu        $a1, $v0, $t0
    ctx->r5 = ADD32(ctx->r2, ctx->r8);
    aligned4_memcpy(rdram, ctx);
        goto after_0;
    // 0x800B2E78: addu        $a1, $v0, $t0
    ctx->r5 = ADD32(ctx->r2, ctx->r8);
    after_0:
    // 0x800B2E7C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800B2E80: lw          $t2, 0x8($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X8);
    // 0x800B2E84: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x800B2E88: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x800B2E8C: sw          $t4, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r12;
    // 0x800B2E90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B2E94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B2E98: jr          $ra
    // 0x800B2E9C: nop

    return;
    // 0x800B2E9C: nop

;}
RECOMP_FUNC void bsbswim_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800620: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800624: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(120, 0X1E70) << 16);
    // 0x80800628: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080062C: jr          $ra
    // 0x80800630: lw          $v0, 0x1E70($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(120, 0X1E70));
    return;
    // 0x80800630: lw          $v0, 0x1E70($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(120, 0X1E70));
;}
RECOMP_FUNC void _cadbfunc_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085598: syscall     169
    recomp_syscall_handler(rdram, ctx, 0x80085598);
    return;
    // 0x8008559C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800A0FCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A0FCC: lw          $t6, 0x150($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X150);
    // 0x800A0FD0: jr          $ra
    // 0x800A0FD4: lbu         $v0, 0x2($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X2);
    return;
    // 0x800A0FD4: lbu         $v0, 0x2($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X2);
;}
RECOMP_FUNC void func_80113D30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80113D30: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x80113D34: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80113D38: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80113D3C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80113D40: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80113D44: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80113D48: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80113D4C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80113D50: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80113D54: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80113D58: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80113D5C: jal         0x80110840
    // 0x80113D60: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    func_80110840(rdram, ctx);
        goto after_0;
    // 0x80113D60: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    after_0:
    // 0x80113D64: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80113D68: jal         0x80110898
    // 0x80113D6C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_80110898(rdram, ctx);
        goto after_1;
    // 0x80113D6C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_1:
    // 0x80113D70: jal         0x8010FF80
    // 0x80113D74: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8010FF80(rdram, ctx);
        goto after_2;
    // 0x80113D74: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80113D78: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80113D7C: jal         0x800A940C
    // 0x80113D80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A940C(rdram, ctx);
        goto after_3;
    // 0x80113D80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80113D84: addiu       $s0, $sp, 0xA4
    ctx->r16 = ADD32(ctx->r29, 0XA4);
    // 0x80113D88: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x80113D8C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80113D90: jal         0x80112550
    // 0x80113D94: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_80112550(rdram, ctx);
        goto after_4;
    // 0x80113D94: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_4:
    // 0x80113D98: addiu       $s2, $sp, 0x8C
    ctx->r18 = ADD32(ctx->r29, 0X8C);
    // 0x80113D9C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80113DA0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80113DA4: jal         0x800CA7E4
    // 0x80113DA8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800CA7E4(rdram, ctx);
        goto after_5;
    // 0x80113DA8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80113DAC: addiu       $s3, $sp, 0xB0
    ctx->r19 = ADD32(ctx->r29, 0XB0);
    // 0x80113DB0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80113DB4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80113DB8: jal         0x800EFB24
    // 0x80113DBC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_800EFB24(rdram, ctx);
        goto after_6;
    // 0x80113DBC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_6:
    // 0x80113DC0: addiu       $a0, $sp, 0xBC
    ctx->r4 = ADD32(ctx->r29, 0XBC);
    // 0x80113DC4: jal         0x800EF410
    // 0x80113DC8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EF410(rdram, ctx);
        goto after_7;
    // 0x80113DC8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_7:
    // 0x80113DCC: addiu       $a0, $sp, 0x98
    ctx->r4 = ADD32(ctx->r29, 0X98);
    // 0x80113DD0: jal         0x800EE7F8
    // 0x80113DD4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_8;
    // 0x80113DD4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x80113DD8: jal         0x800CA7A4
    // 0x80113DDC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800CA7A4(rdram, ctx);
        goto after_9;
    // 0x80113DDC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x80113DE0: jal         0x80018EFC
    // 0x80113DE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mlMtxSet(rdram, ctx);
        goto after_10;
    // 0x80113DE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_10:
    // 0x80113DE8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80113DEC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80113DF0: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80113DF4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80113DF8: addiu       $s6, $sp, 0x74
    ctx->r22 = ADD32(ctx->r29, 0X74);
    // 0x80113DFC: addiu       $s3, $sp, 0x80
    ctx->r19 = ADD32(ctx->r29, 0X80);
L_80113E00:
    // 0x80113E00: beq         $s1, $zero, L_80113E28
    if (ctx->r17 == 0) {
        // 0x80113E04: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80113E28;
    }
    // 0x80113E04: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80113E08: beq         $s1, $at, L_80113E48
    if (ctx->r17 == ctx->r1) {
        // 0x80113E0C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80113E48;
    }
    // 0x80113E0C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80113E10: beq         $s1, $at, L_80113E64
    if (ctx->r17 == ctx->r1) {
        // 0x80113E14: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80113E64;
    }
    // 0x80113E14: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80113E18: beql        $s1, $at, L_80113E84
    if (ctx->r17 == ctx->r1) {
        // 0x80113E1C: neg.s       $f6, $f22
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = -ctx->f22.fl;
            goto L_80113E84;
    }
    goto skip_0;
    // 0x80113E1C: neg.s       $f6, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = -ctx->f22.fl;
    skip_0:
    // 0x80113E20: b           L_80113E9C
    // 0x80113E24: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
        goto L_80113E9C;
    // 0x80113E24: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80113E28:
    // 0x80113E28: neg.s       $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = -ctx->f22.fl;
    // 0x80113E2C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80113E30: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80113E34: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80113E38: jal         0x800EFA4C
    // 0x80113E3C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800EFA4C(rdram, ctx);
        goto after_11;
    // 0x80113E3C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_11:
    // 0x80113E40: b           L_80113E9C
    // 0x80113E44: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
        goto L_80113E9C;
    // 0x80113E44: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80113E48:
    // 0x80113E48: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80113E4C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80113E50: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80113E54: jal         0x800EFA4C
    // 0x80113E58: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800EFA4C(rdram, ctx);
        goto after_12;
    // 0x80113E58: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_12:
    // 0x80113E5C: b           L_80113E9C
    // 0x80113E60: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
        goto L_80113E9C;
    // 0x80113E60: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80113E64:
    // 0x80113E64: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80113E68: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80113E6C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80113E70: jal         0x800EFA4C
    // 0x80113E74: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800EFA4C(rdram, ctx);
        goto after_13;
    // 0x80113E74: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_13:
    // 0x80113E78: b           L_80113E9C
    // 0x80113E7C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
        goto L_80113E9C;
    // 0x80113E7C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80113E80: neg.s       $f6, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = -ctx->f22.fl;
L_80113E84:
    // 0x80113E84: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80113E88: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80113E8C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80113E90: jal         0x800EFA4C
    // 0x80113E94: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800EFA4C(rdram, ctx);
        goto after_14;
    // 0x80113E94: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_14:
    // 0x80113E98: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80113E9C:
    // 0x80113E9C: jal         0x80019224
    // 0x80113EA0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_80019224(rdram, ctx);
        goto after_15;
    // 0x80113EA0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_15:
    // 0x80113EA4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80113EA8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80113EAC: jal         0x800EE780
    // 0x80113EB0: addiu       $a2, $sp, 0x98
    ctx->r6 = ADD32(ctx->r29, 0X98);
    func_800EE780(rdram, ctx);
        goto after_16;
    // 0x80113EB0: addiu       $a2, $sp, 0x98
    ctx->r6 = ADD32(ctx->r29, 0X98);
    after_16:
    // 0x80113EB4: lw          $t6, 0x28($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X28);
    // 0x80113EB8: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80113EBC: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x80113EC0: jal         0x800E8830
    // 0x80113EC4: lbu         $a0, 0x34($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X34);
    func_800E8830(rdram, ctx);
        goto after_17;
    // 0x80113EC4: lbu         $a0, 0x34($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X34);
    after_17:
    // 0x80113EC8: lw          $s0, 0x28($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X28);
    // 0x80113ECC: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x80113ED0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80113ED4: addu        $t8, $s0, $s1
    ctx->r24 = ADD32(ctx->r16, ctx->r17);
    // 0x80113ED8: addu        $a2, $s0, $s5
    ctx->r6 = ADD32(ctx->r16, ctx->r21);
    // 0x80113EDC: addiu       $a2, $a2, 0x4C
    ctx->r6 = ADD32(ctx->r6, 0X4C);
    // 0x80113EE0: jal         0x800E8918
    // 0x80113EE4: lbu         $a0, 0x34($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X34);
    func_800E8918(rdram, ctx);
        goto after_18;
    // 0x80113EE4: lbu         $a0, 0x34($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X34);
    after_18:
    // 0x80113EE8: lw          $t9, 0x28($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X28);
    // 0x80113EEC: addu        $t0, $t9, $s1
    ctx->r8 = ADD32(ctx->r25, ctx->r17);
    // 0x80113EF0: sb          $v0, 0x38($t0)
    MEM_B(0X38, ctx->r8) = ctx->r2;
    // 0x80113EF4: lw          $s0, 0x28($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X28);
    // 0x80113EF8: addu        $t1, $s0, $s1
    ctx->r9 = ADD32(ctx->r16, ctx->r17);
    // 0x80113EFC: lb          $t2, 0x38($t1)
    ctx->r10 = MEM_B(ctx->r9, 0X38);
    // 0x80113F00: addu        $v1, $s0, $s2
    ctx->r3 = ADD32(ctx->r16, ctx->r18);
    // 0x80113F04: addu        $t9, $s0, $s2
    ctx->r25 = ADD32(ctx->r16, ctx->r18);
    // 0x80113F08: bnel        $t2, $zero, L_80113F4C
    if (ctx->r10 != 0) {
        // 0x80113F0C: sw          $zero, 0x18($t9)
        MEM_W(0X18, ctx->r25) = 0;
            goto L_80113F4C;
    }
    goto skip_1;
    // 0x80113F0C: sw          $zero, 0x18($t9)
    MEM_W(0X18, ctx->r25) = 0;
    skip_1:
    // 0x80113F10: lw          $t3, 0x18($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X18);
    // 0x80113F14: bnel        $t3, $zero, L_80113F3C
    if (ctx->r11 != 0) {
        // 0x80113F18: lw          $t7, 0x3C($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X3C);
            goto L_80113F3C;
    }
    goto skip_2;
    // 0x80113F18: lw          $t7, 0x3C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X3C);
    skip_2:
    // 0x80113F1C: jal         0x8001211C
    // 0x80113F20: nop

    func_8001211C(rdram, ctx);
        goto after_19;
    // 0x80113F20: nop

    after_19:
    // 0x80113F24: lw          $t4, 0x28($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X28);
    // 0x80113F28: addu        $t5, $t4, $s2
    ctx->r13 = ADD32(ctx->r12, ctx->r18);
    // 0x80113F2C: sw          $v0, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r2;
    // 0x80113F30: lw          $t6, 0x28($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X28);
    // 0x80113F34: addu        $v1, $t6, $s2
    ctx->r3 = ADD32(ctx->r14, ctx->r18);
    // 0x80113F38: lw          $t7, 0x3C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X3C);
L_80113F3C:
    // 0x80113F3C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80113F40: b           L_80113F5C
    // 0x80113F44: sw          $t8, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r24;
        goto L_80113F5C;
    // 0x80113F44: sw          $t8, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r24;
    // 0x80113F48: sw          $zero, 0x18($t9)
    MEM_W(0X18, ctx->r25) = 0;
L_80113F4C:
    // 0x80113F4C: lw          $t0, 0x28($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X28);
    // 0x80113F50: addu        $v1, $t0, $s2
    ctx->r3 = ADD32(ctx->r8, ctx->r18);
    // 0x80113F54: lw          $t1, 0x18($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X18);
    // 0x80113F58: sw          $t1, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r9;
L_80113F5C:
    // 0x80113F5C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80113F60: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x80113F64: addiu       $s5, $s5, 0xC
    ctx->r21 = ADD32(ctx->r21, 0XC);
    // 0x80113F68: bne         $at, $zero, L_80113E00
    if (ctx->r1 != 0) {
        // 0x80113F6C: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80113E00;
    }
    // 0x80113F6C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80113F70: lw          $t2, 0x28($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X28);
    // 0x80113F74: sh          $zero, 0xC($t2)
    MEM_H(0XC, ctx->r10) = 0;
    // 0x80113F78: lw          $t3, 0x28($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X28);
    // 0x80113F7C: lh          $s1, 0xC($t3)
    ctx->r17 = MEM_H(ctx->r11, 0XC);
    // 0x80113F80: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x80113F84: beq         $at, $zero, L_80113FC0
    if (ctx->r1 == 0) {
        // 0x80113F88: sll         $s2, $s1, 2
        ctx->r18 = S32(ctx->r17 << 2);
            goto L_80113FC0;
    }
    // 0x80113F88: sll         $s2, $s1, 2
    ctx->r18 = S32(ctx->r17 << 2);
    // 0x80113F8C: lw          $s0, 0x28($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X28);
L_80113F90:
    // 0x80113F90: addu        $t4, $s0, $s2
    ctx->r12 = ADD32(ctx->r16, ctx->r18);
    // 0x80113F94: lw          $t5, 0x3C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X3C);
    // 0x80113F98: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80113F9C: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
    // 0x80113FA0: bnel        $at, $zero, L_80113FB8
    if (ctx->r1 != 0) {
        // 0x80113FA4: slti        $at, $s2, 0x10
        ctx->r1 = SIGNED(ctx->r18) < 0X10 ? 1 : 0;
            goto L_80113FB8;
    }
    goto skip_3;
    // 0x80113FA4: slti        $at, $s2, 0x10
    ctx->r1 = SIGNED(ctx->r18) < 0X10 ? 1 : 0;
    skip_3:
    // 0x80113FA8: lh          $t6, 0xC($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XC);
    // 0x80113FAC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80113FB0: sh          $t7, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r15;
    // 0x80113FB4: slti        $at, $s2, 0x10
    ctx->r1 = SIGNED(ctx->r18) < 0X10 ? 1 : 0;
L_80113FB8:
    // 0x80113FB8: bnel        $at, $zero, L_80113F90
    if (ctx->r1 != 0) {
        // 0x80113FBC: lw          $s0, 0x28($s4)
        ctx->r16 = MEM_W(ctx->r20, 0X28);
            goto L_80113F90;
    }
    goto skip_4;
    // 0x80113FBC: lw          $s0, 0x28($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X28);
    skip_4:
L_80113FC0:
    // 0x80113FC0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80113FC4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80113FC8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80113FCC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80113FD0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80113FD4: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80113FD8: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80113FDC: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80113FE0: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80113FE4: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80113FE8: jr          $ra
    // 0x80113FEC: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x80113FEC: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void func_80800620_gcdialogcamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800620: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800624: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800628: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8080062C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800630: jal         0x800856B0
    // 0x80800634: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800634: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_0:
    // 0x80800638: beql        $v0, $zero, L_80800654
    if (ctx->r2 == 0) {
        // 0x8080063C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800654;
    }
    goto skip_0;
    // 0x8080063C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80800640: jal         0x800856E0
    // 0x80800644: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _capod_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800644: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80800648: b           L_80800654
    // 0x8080064C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800654;
    // 0x8080064C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800650: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800654:
    // 0x80800654: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800658: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080065C: jr          $ra
    // 0x80800660: nop

    return;
    // 0x80800660: nop

;}
RECOMP_FUNC void bskazstill_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800344: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800348: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080034C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800350: jal         0x80800030
    // 0x80800354: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800030_bskazstill(rdram, ctx);
        goto after_0;
    // 0x80800354: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800358: jal         0x80090A2C
    // 0x8080035C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80090A2C(rdram, ctx);
        goto after_1;
    // 0x8080035C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800360: jal         0x800951B4
    // 0x80800364: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800951B4(rdram, ctx);
        goto after_2;
    // 0x80800364: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800368: jal         0x800832E8
    // 0x8080036C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bskaz_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x8080036C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80800370: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800374: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800378: jr          $ra
    // 0x8080037C: nop

    return;
    // 0x8080037C: nop

;}
RECOMP_FUNC void func_800F018C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F018C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800F0190: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800F0194: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F0198: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800F019C: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800F01A0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800F01A4: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800F01A8: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800F01AC: jal         0x800EFB24
    // 0x800F01B0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800EFB24(rdram, ctx);
        goto after_0;
    // 0x800F01B0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x800F01B4: jal         0x800EEFD4
    // 0x800F01B8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800EEFD4(rdram, ctx);
        goto after_1;
    // 0x800F01B8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_1:
    // 0x800F01BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800F01C0: lwc1        $f4, 0x5EB0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5EB0);
    // 0x800F01C4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x800F01C8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800F01CC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800F01D0: nop

    // 0x800F01D4: bc1f        L_800F01EC
    if (!c1cs) {
        // 0x800F01D8: nop
    
            goto L_800F01EC;
    }
    // 0x800F01D8: nop

    // 0x800F01DC: jal         0x800EE7F8
    // 0x800F01E0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x800F01E0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_2:
    // 0x800F01E4: b           L_800F0268
    // 0x800F01E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F0268;
    // 0x800F01E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F01EC:
    // 0x800F01EC: jal         0x8002DCA0
    // 0x800F01F0: nop

    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x800F01F0: nop

    after_3:
    // 0x800F01F4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800F01F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800F01FC: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800F0200: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800F0204: div.s       $f2, $f6, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800F0208: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800F020C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800F0210: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x800F0214: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800F0218: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800F021C: nop

    // 0x800F0220: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800F0224: nop

    // 0x800F0228: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800F022C: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x800F0230: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    // 0x800F0234: jal         0x800EFB24
    // 0x800F0238: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    func_800EFB24(rdram, ctx);
        goto after_4;
    // 0x800F0238: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x800F023C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800F0240: jal         0x800EEAA4
    // 0x800F0244: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800EEAA4(rdram, ctx);
        goto after_5;
    // 0x800F0244: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_5:
    // 0x800F0248: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800F024C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800F0250: jal         0x800EFA20
    // 0x800F0254: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800EFA20(rdram, ctx);
        goto after_6;
    // 0x800F0254: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_6:
    // 0x800F0258: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800F025C: jal         0x800EF04C
    // 0x800F0260: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_800EF04C(rdram, ctx);
        goto after_7;
    // 0x800F0260: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_7:
    // 0x800F0264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F0268:
    // 0x800F0268: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800F026C: jr          $ra
    // 0x800F0270: nop

    return;
    // 0x800F0270: nop

;}
RECOMP_FUNC void func_80800018_glcutDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080001C: addiu       $t7, $a0, -0x1
    ctx->r15 = ADD32(ctx->r4, -0X1);
    // 0x80800020: sltiu       $at, $t7, 0x6
    ctx->r1 = ctx->r15 < 0X6 ? 1 : 0;
    // 0x80800024: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800028: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080002C: beq         $at, $zero, L_80800310
    if (ctx->r1 == 0) {
        // 0x80800030: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_80800310;
    }
    // 0x80800030: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800034: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800038: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2778, 0X7E0) << 16);
    // 0x8080003C: addu        $at, $at, $t7
    gpr jr_addend_80800044 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800040: lw          $t7, 0x7E0($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2778, 0X7E0));
    // 0x80800044: jr          $t7
    // 0x80800048: nop

    switch (jr_addend_80800044 >> 2) {
        case 0: goto L_8080004C; break;
        case 1: goto L_80800078; break;
        case 2: goto L_80800128; break;
        case 3: goto L_80800194; break;
        case 4: goto L_8080020C; break;
        case 5: goto L_808002BC; break;
        default: switch_error(__func__, 0x80800044, 0x808007E0);
    }
    // 0x80800048: nop

L_8080004C:
    // 0x8080004C: jal         0x8080000C
    // 0x80800050: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8080000C_glcutDll(rdram, ctx);
        goto after_0;
    // 0x80800050: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80800054: jal         0x80800000
    // 0x80800058: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80800000_glcutDll(rdram, ctx);
        goto after_1;
    // 0x80800058: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8080005C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80800060: addiu       $s0, $s0, 0x75E8
    ctx->r16 = ADD32(ctx->r16, 0X75E8);
    // 0x80800064: sb          $zero, 0xC($s0)
    MEM_B(0XC, ctx->r16) = 0;
    // 0x80800068: jal         0x800FE734
    // 0x8080006C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FE734(rdram, ctx);
        goto after_2;
    // 0x8080006C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80800070: b           L_80800314
    // 0x80800074: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
        goto L_80800314;
    // 0x80800074: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
L_80800078:
    // 0x80800078: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8080007C: addiu       $s0, $s0, 0x75E8
    ctx->r16 = ADD32(ctx->r16, 0X75E8);
    // 0x80800080: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    // 0x80800084: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x80800088: bnel        $t8, $t9, L_808000A4
    if (ctx->r24 != ctx->r25) {
        // 0x8080008C: lbu         $t0, 0xA($s0)
        ctx->r8 = MEM_BU(ctx->r16, 0XA);
            goto L_808000A4;
    }
    goto skip_0;
    // 0x8080008C: lbu         $t0, 0xA($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0XA);
    skip_0:
    // 0x80800090: jal         0x800DA298
    // 0x80800094: addiu       $a0, $zero, 0xA52
    ctx->r4 = ADD32(0, 0XA52);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80800094: addiu       $a0, $zero, 0xA52
    ctx->r4 = ADD32(0, 0XA52);
    after_3:
    // 0x80800098: beq         $v0, $zero, L_808000EC
    if (ctx->r2 == 0) {
        // 0x8080009C: nop
    
            goto L_808000EC;
    }
    // 0x8080009C: nop

    // 0x808000A0: lbu         $t0, 0xA($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0XA);
L_808000A4:
    // 0x808000A4: beq         $t0, $zero, L_808000BC
    if (ctx->r8 == 0) {
        // 0x808000A8: nop
    
            goto L_808000BC;
    }
    // 0x808000A8: nop

    // 0x808000AC: jal         0x800FE844
    // 0x808000B0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800FE844(rdram, ctx);
        goto after_4;
    // 0x808000B0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
    // 0x808000B4: jal         0x800FE734
    // 0x808000B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800FE734(rdram, ctx);
        goto after_5;
    // 0x808000B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
L_808000BC:
    // 0x808000BC: jal         0x80088268
    // 0x808000C0: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    _gcsectionDll_entrypoint_4(rdram, ctx);
        goto after_6;
    // 0x808000C0: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    after_6:
    // 0x808000C4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x808000C8: lbu         $t1, 0x762C($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X762C);
    // 0x808000CC: beql        $v0, $t1, L_808000E0
    if (ctx->r2 == ctx->r9) {
        // 0x808000D0: lh          $a0, 0x0($s0)
        ctx->r4 = MEM_H(ctx->r16, 0X0);
            goto L_808000E0;
    }
    goto skip_1;
    // 0x808000D0: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    skip_1:
    // 0x808000D4: jal         0x800A8230
    // 0x808000D8: nop

    func_800A8230(rdram, ctx);
        goto after_7;
    // 0x808000D8: nop

    after_7:
    // 0x808000DC: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
L_808000E0:
    // 0x808000E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000E4: jal         0x800A7990
    // 0x808000E8: lbu         $a2, 0x10($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X10);
    func_800A7990(rdram, ctx);
        goto after_8;
    // 0x808000E8: lbu         $a2, 0x10($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X10);
    after_8:
L_808000EC:
    // 0x808000EC: jal         0x800DA544
    // 0x808000F0: addiu       $a0, $zero, 0x641
    ctx->r4 = ADD32(0, 0X641);
    func_800DA544(rdram, ctx);
        goto after_9;
    // 0x808000F0: addiu       $a0, $zero, 0x641
    ctx->r4 = ADD32(0, 0X641);
    after_9:
    // 0x808000F4: lbu         $t2, 0xB($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0XB);
    // 0x808000F8: bnel        $t2, $zero, L_80800120
    if (ctx->r10 != 0) {
        // 0x808000FC: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_80800120;
    }
    goto skip_2;
    // 0x808000FC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    skip_2:
    // 0x80800100: lbu         $t3, 0xF($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XF);
    // 0x80800104: bnel        $t3, $zero, L_80800120
    if (ctx->r11 != 0) {
        // 0x80800108: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_80800120;
    }
    goto skip_3;
    // 0x80800108: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    skip_3:
    // 0x8080010C: jal         0x800C78CC
    // 0x80800110: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C78CC(rdram, ctx);
        goto after_10;
    // 0x80800110: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_10:
    // 0x80800114: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80800118: sb          $t4, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r12;
    // 0x8080011C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_80800120:
    // 0x80800120: b           L_80800310
    // 0x80800124: sb          $t5, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r13;
        goto L_80800310;
    // 0x80800124: sb          $t5, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r13;
L_80800128:
    // 0x80800128: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8080012C: addiu       $s0, $s0, 0x75E8
    ctx->r16 = ADD32(ctx->r16, 0X75E8);
    // 0x80800130: lbu         $t6, 0x8($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X8);
    // 0x80800134: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800138: bnel        $t6, $at, L_80800314
    if (ctx->r14 != ctx->r1) {
        // 0x8080013C: lw          $t3, 0x20($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X20);
            goto L_80800314;
    }
    goto skip_4;
    // 0x8080013C: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    skip_4:
    // 0x80800140: lh          $t7, 0x2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X2);
    // 0x80800144: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x80800148: bnel        $t7, $t8, L_80800164
    if (ctx->r15 != ctx->r24) {
        // 0x8080014C: lbu         $t9, 0x7($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X7);
            goto L_80800164;
    }
    goto skip_5;
    // 0x8080014C: lbu         $t9, 0x7($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X7);
    skip_5:
    // 0x80800150: jal         0x800DA298
    // 0x80800154: addiu       $a0, $zero, 0xA52
    ctx->r4 = ADD32(0, 0XA52);
    func_800DA298(rdram, ctx);
        goto after_11;
    // 0x80800154: addiu       $a0, $zero, 0xA52
    ctx->r4 = ADD32(0, 0XA52);
    after_11:
    // 0x80800158: beql        $v0, $zero, L_80800314
    if (ctx->r2 == 0) {
        // 0x8080015C: lw          $t3, 0x20($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X20);
            goto L_80800314;
    }
    goto skip_6;
    // 0x8080015C: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    skip_6:
    // 0x80800160: lbu         $t9, 0x7($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X7);
L_80800164:
    // 0x80800164: beql        $t9, $zero, L_80800314
    if (ctx->r25 == 0) {
        // 0x80800168: lw          $t3, 0x20($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X20);
            goto L_80800314;
    }
    goto skip_7;
    // 0x80800168: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    skip_7:
    // 0x8080016C: jal         0x80800000
    // 0x80800170: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80800000_glcutDll(rdram, ctx);
        goto after_12;
    // 0x80800170: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_12:
    // 0x80800174: jal         0x8080000C
    // 0x80800178: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8080000C_glcutDll(rdram, ctx);
        goto after_13;
    // 0x80800178: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
    // 0x8080017C: jal         0x800D9290
    // 0x80800180: nop

    func_800D9290(rdram, ctx);
        goto after_14;
    // 0x80800180: nop

    after_14:
    // 0x80800184: jal         0x800D9330
    // 0x80800188: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800D9330(rdram, ctx);
        goto after_15;
    // 0x80800188: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_15:
    // 0x8080018C: b           L_80800314
    // 0x80800190: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
        goto L_80800314;
    // 0x80800190: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
L_80800194:
    // 0x80800194: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80800198: addiu       $s0, $s0, 0x75E8
    ctx->r16 = ADD32(ctx->r16, 0X75E8);
    // 0x8080019C: lbu         $t0, 0x6($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X6);
    // 0x808001A0: beq         $t0, $zero, L_808001B0
    if (ctx->r8 == 0) {
        // 0x808001A4: nop
    
            goto L_808001B0;
    }
    // 0x808001A4: nop

    // 0x808001A8: jal         0x800D92F4
    // 0x808001AC: nop

    func_800D92F4(rdram, ctx);
        goto after_16;
    // 0x808001AC: nop

    after_16:
L_808001B0:
    // 0x808001B0: jal         0x800DA524
    // 0x808001B4: addiu       $a0, $zero, 0x641
    ctx->r4 = ADD32(0, 0X641);
    func_800DA524(rdram, ctx);
        goto after_17;
    // 0x808001B4: addiu       $a0, $zero, 0x641
    ctx->r4 = ADD32(0, 0X641);
    after_17:
    // 0x808001B8: lbu         $t1, 0xB($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0XB);
    // 0x808001BC: bnel        $t1, $zero, L_808001E0
    if (ctx->r9 != 0) {
        // 0x808001C0: lbu         $t3, 0xE($s0)
        ctx->r11 = MEM_BU(ctx->r16, 0XE);
            goto L_808001E0;
    }
    goto skip_8;
    // 0x808001C0: lbu         $t3, 0xE($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XE);
    skip_8:
    // 0x808001C4: lbu         $t2, 0xF($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0XF);
    // 0x808001C8: beql        $t2, $zero, L_808001E0
    if (ctx->r10 == 0) {
        // 0x808001CC: lbu         $t3, 0xE($s0)
        ctx->r11 = MEM_BU(ctx->r16, 0XE);
            goto L_808001E0;
    }
    goto skip_9;
    // 0x808001CC: lbu         $t3, 0xE($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XE);
    skip_9:
    // 0x808001D0: jal         0x800C78CC
    // 0x808001D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C78CC(rdram, ctx);
        goto after_18;
    // 0x808001D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_18:
    // 0x808001D8: sb          $zero, 0xF($s0)
    MEM_B(0XF, ctx->r16) = 0;
    // 0x808001DC: lbu         $t3, 0xE($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XE);
L_808001E0:
    // 0x808001E0: beq         $t3, $zero, L_808001F0
    if (ctx->r11 == 0) {
        // 0x808001E4: nop
    
            goto L_808001F0;
    }
    // 0x808001E4: nop

    // 0x808001E8: jal         0x80090708
    // 0x808001EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_19;
    // 0x808001EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_19:
L_808001F0:
    // 0x808001F0: jal         0x8080000C
    // 0x808001F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8080000C_glcutDll(rdram, ctx);
        goto after_20;
    // 0x808001F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_20:
    // 0x808001F8: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x808001FC: jal         0x800DA524
    // 0x80800200: addiu       $a0, $zero, 0xA52
    ctx->r4 = ADD32(0, 0XA52);
    func_800DA524(rdram, ctx);
        goto after_21;
    // 0x80800200: addiu       $a0, $zero, 0xA52
    ctx->r4 = ADD32(0, 0XA52);
    after_21:
    // 0x80800204: b           L_80800314
    // 0x80800208: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
        goto L_80800314;
    // 0x80800208: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
L_8080020C:
    // 0x8080020C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80800210: addiu       $s0, $s0, 0x75E8
    ctx->r16 = ADD32(ctx->r16, 0X75E8);
    // 0x80800214: lbu         $t4, 0xA($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0XA);
    // 0x80800218: beq         $t4, $zero, L_80800230
    if (ctx->r12 == 0) {
        // 0x8080021C: nop
    
            goto L_80800230;
    }
    // 0x8080021C: nop

    // 0x80800220: jal         0x800FE844
    // 0x80800224: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800FE844(rdram, ctx);
        goto after_22;
    // 0x80800224: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_22:
    // 0x80800228: jal         0x800FE734
    // 0x8080022C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800FE734(rdram, ctx);
        goto after_23;
    // 0x8080022C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_23:
L_80800230:
    // 0x80800230: jal         0x80088268
    // 0x80800234: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    _gcsectionDll_entrypoint_4(rdram, ctx);
        goto after_24;
    // 0x80800234: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    after_24:
    // 0x80800238: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8080023C: lbu         $t5, 0x762C($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X762C);
    // 0x80800240: beql        $v0, $t5, L_80800254
    if (ctx->r2 == ctx->r13) {
        // 0x80800244: lh          $a0, 0x2($s0)
        ctx->r4 = MEM_H(ctx->r16, 0X2);
            goto L_80800254;
    }
    goto skip_10;
    // 0x80800244: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    skip_10:
    // 0x80800248: jal         0x800A8230
    // 0x8080024C: nop

    func_800A8230(rdram, ctx);
        goto after_25;
    // 0x8080024C: nop

    after_25:
    // 0x80800250: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
L_80800254:
    // 0x80800254: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800258: jal         0x800A7990
    // 0x8080025C: lbu         $a2, 0x10($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X10);
    func_800A7990(rdram, ctx);
        goto after_26;
    // 0x8080025C: lbu         $a2, 0x10($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X10);
    after_26:
    // 0x80800260: jal         0x800DA524
    // 0x80800264: addiu       $a0, $zero, 0x641
    ctx->r4 = ADD32(0, 0X641);
    func_800DA524(rdram, ctx);
        goto after_27;
    // 0x80800264: addiu       $a0, $zero, 0x641
    ctx->r4 = ADD32(0, 0X641);
    after_27:
    // 0x80800268: lbu         $t6, 0xB($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XB);
    // 0x8080026C: bnel        $t6, $zero, L_80800290
    if (ctx->r14 != 0) {
        // 0x80800270: lbu         $t8, 0x6($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X6);
            goto L_80800290;
    }
    goto skip_11;
    // 0x80800270: lbu         $t8, 0x6($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X6);
    skip_11:
    // 0x80800274: lbu         $t7, 0xF($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XF);
    // 0x80800278: beql        $t7, $zero, L_80800290
    if (ctx->r15 == 0) {
        // 0x8080027C: lbu         $t8, 0x6($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X6);
            goto L_80800290;
    }
    goto skip_12;
    // 0x8080027C: lbu         $t8, 0x6($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X6);
    skip_12:
    // 0x80800280: jal         0x800C78CC
    // 0x80800284: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C78CC(rdram, ctx);
        goto after_28;
    // 0x80800284: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_28:
    // 0x80800288: sb          $zero, 0xF($s0)
    MEM_B(0XF, ctx->r16) = 0;
    // 0x8080028C: lbu         $t8, 0x6($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X6);
L_80800290:
    // 0x80800290: beql        $t8, $zero, L_808002A4
    if (ctx->r24 == 0) {
        // 0x80800294: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_808002A4;
    }
    goto skip_13;
    // 0x80800294: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    skip_13:
    // 0x80800298: jal         0x8080000C
    // 0x8080029C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8080000C_glcutDll(rdram, ctx);
        goto after_29;
    // 0x8080029C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_29:
    // 0x808002A0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
L_808002A4:
    // 0x808002A4: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x808002A8: sb          $t9, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r25;
    // 0x808002AC: jal         0x800DA524
    // 0x808002B0: addiu       $a0, $zero, 0xA52
    ctx->r4 = ADD32(0, 0XA52);
    func_800DA524(rdram, ctx);
        goto after_30;
    // 0x808002B0: addiu       $a0, $zero, 0xA52
    ctx->r4 = ADD32(0, 0XA52);
    after_30:
    // 0x808002B4: b           L_80800314
    // 0x808002B8: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
        goto L_80800314;
    // 0x808002B8: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
L_808002BC:
    // 0x808002BC: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x808002C0: addiu       $s0, $s0, 0x75E8
    ctx->r16 = ADD32(ctx->r16, 0X75E8);
    // 0x808002C4: lbu         $t0, 0x9($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X9);
    // 0x808002C8: beql        $t0, $zero, L_808002F4
    if (ctx->r8 == 0) {
        // 0x808002CC: lbu         $t1, 0xC($s0)
        ctx->r9 = MEM_BU(ctx->r16, 0XC);
            goto L_808002F4;
    }
    goto skip_14;
    // 0x808002CC: lbu         $t1, 0xC($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0XC);
    skip_14:
    // 0x808002D0: jal         0x800D92F4
    // 0x808002D4: nop

    func_800D92F4(rdram, ctx);
        goto after_31;
    // 0x808002D4: nop

    after_31:
    // 0x808002D8: jal         0x80800000
    // 0x808002DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80800000_glcutDll(rdram, ctx);
        goto after_32;
    // 0x808002DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_32:
    // 0x808002E0: jal         0x8080000C
    // 0x808002E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8080000C_glcutDll(rdram, ctx);
        goto after_33;
    // 0x808002E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_33:
    // 0x808002E8: jal         0x800FE734
    // 0x808002EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FE734(rdram, ctx);
        goto after_34;
    // 0x808002EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_34:
    // 0x808002F0: lbu         $t1, 0xC($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0XC);
L_808002F4:
    // 0x808002F4: beql        $t1, $zero, L_80800304
    if (ctx->r9 == 0) {
        // 0x808002F8: lbu         $t2, 0xD($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0XD);
            goto L_80800304;
    }
    goto skip_15;
    // 0x808002F8: lbu         $t2, 0xD($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0XD);
    skip_15:
    // 0x808002FC: sb          $zero, 0xC($s0)
    MEM_B(0XC, ctx->r16) = 0;
    // 0x80800300: lbu         $t2, 0xD($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0XD);
L_80800304:
    // 0x80800304: beql        $t2, $zero, L_80800314
    if (ctx->r10 == 0) {
        // 0x80800308: lw          $t3, 0x20($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X20);
            goto L_80800314;
    }
    goto skip_16;
    // 0x80800308: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    skip_16:
    // 0x8080030C: sb          $zero, 0xD($s0)
    MEM_B(0XD, ctx->r16) = 0;
L_80800310:
    // 0x80800310: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
L_80800314:
    // 0x80800314: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80800318: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080031C: addiu       $s0, $s0, 0x75E8
    ctx->r16 = ADD32(ctx->r16, 0X75E8);
    // 0x80800320: sb          $t3, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r11;
    // 0x80800324: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800328: jr          $ra
    // 0x8080032C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8080032C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80800508_bssnowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800508: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080050C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800510: jal         0x80800234
    // 0x80800514: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bssnowball_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800514: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800518: jal         0x80082FE0
    // 0x8080051C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x8080051C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800520: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800524: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800528: jr          $ra
    // 0x8080052C: nop

    return;
    // 0x8080052C: nop

;}
RECOMP_FUNC void func_80114CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80114CC0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80114CC4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80114CC8: sb          $t6, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r14;
    // 0x80114CCC: jr          $ra
    // 0x80114CD0: swc1        $f12, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x80114CD0: swc1        $f12, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_800FF4A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FF4A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800FF4A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800FF4AC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800FF4B0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800FF4B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800FF4B8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800FF4BC: jal         0x8010381C
    // 0x800FF4C0: lw          $s0, 0x0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X0);
    func_8010381C(rdram, ctx);
        goto after_0;
    // 0x800FF4C0: lw          $s0, 0x0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x800FF4C4: jal         0x80103938
    // 0x800FF4C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80103938(rdram, ctx);
        goto after_1;
    // 0x800FF4C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x800FF4CC: lw          $t6, 0x7C($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X7C);
    // 0x800FF4D0: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x800FF4D4: beql        $t7, $zero, L_800FF500
    if (ctx->r15 == 0) {
        // 0x800FF4D8: lhu         $t0, 0x24($s0)
        ctx->r8 = MEM_HU(ctx->r16, 0X24);
            goto L_800FF500;
    }
    goto skip_0;
    // 0x800FF4D8: lhu         $t0, 0x24($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X24);
    skip_0:
    // 0x800FF4DC: jal         0x80105494
    // 0x800FF4E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80105494(rdram, ctx);
        goto after_2;
    // 0x800FF4E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x800FF4E4: lw          $a0, 0x24($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X24);
    // 0x800FF4E8: sll         $t8, $a0, 23
    ctx->r24 = S32(ctx->r4 << 23);
    // 0x800FF4EC: jal         0x800D8808
    // 0x800FF4F0: srl         $a0, $t8, 29
    ctx->r4 = S32(U32(ctx->r24) >> 29);
    func_800D8808(rdram, ctx);
        goto after_3;
    // 0x800FF4F0: srl         $a0, $t8, 29
    ctx->r4 = S32(U32(ctx->r24) >> 29);
    after_3:
    // 0x800FF4F4: jal         0x80105634
    // 0x800FF4F8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80105634(rdram, ctx);
        goto after_4;
    // 0x800FF4F8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x800FF4FC: lhu         $t0, 0x24($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X24);
L_800FF500:
    // 0x800FF500: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800FF504: andi        $t1, $t0, 0x3F
    ctx->r9 = ctx->r8 & 0X3F;
    // 0x800FF508: jal         0x80104328
    // 0x800FF50C: sh          $t1, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r9;
    func_80104328(rdram, ctx);
        goto after_5;
    // 0x800FF50C: sh          $t1, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r9;
    after_5:
    // 0x800FF510: jal         0x80089D40
    // 0x800FF514: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x800FF514: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x800FF518: jal         0x80104504
    // 0x800FF51C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80104504(rdram, ctx);
        goto after_7;
    // 0x800FF51C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_7:
    // 0x800FF520: jal         0x80106EE0
    // 0x800FF524: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80106EE0(rdram, ctx);
        goto after_8;
    // 0x800FF524: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_8:
    // 0x800FF528: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800FF52C: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x800FF530: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800FF534:
    // 0x800FF534: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800FF538: jal         0x80100074
    // 0x800FF53C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80100074(rdram, ctx);
        goto after_9;
    // 0x800FF53C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x800FF540: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800FF544: bnel        $s0, $s1, L_800FF534
    if (ctx->r16 != ctx->r17) {
        // 0x800FF548: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800FF534;
    }
    goto skip_1;
    // 0x800FF548: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_1:
    // 0x800FF54C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800FF550: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800FF554: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800FF558: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800FF55C: jr          $ra
    // 0x800FF560: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800FF560: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _chmasterjiggy_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085B10: syscall     196
    recomp_syscall_handler(rdram, ctx, 0x80085B10);
    return;
    // 0x80085B14: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800D1000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1000: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800D1004: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800D1008: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800D100C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x800D1010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800D1014: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800D1018: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800D101C: jal         0x800D0A9C
    // 0x800D1020: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    func_800D0A9C(rdram, ctx);
        goto after_0;
    // 0x800D1020: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800D1024: bne         $v0, $zero, L_800D10C0
    if (ctx->r2 != 0) {
        // 0x800D1028: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800D10C0;
    }
    // 0x800D1028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D102C: jal         0x800D0B68
    // 0x800D1030: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800D0B68(rdram, ctx);
        goto after_1;
    // 0x800D1030: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x800D1034: bne         $v0, $zero, L_800D10C0
    if (ctx->r2 != 0) {
        // 0x800D1038: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800D10C0;
    }
    // 0x800D1038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D103C: jal         0x800D0B08
    // 0x800D1040: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800D0B08(rdram, ctx);
        goto after_2;
    // 0x800D1040: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x800D1044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D1048: jal         0x800D053C
    // 0x800D104C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800D053C(rdram, ctx);
        goto after_3;
    // 0x800D104C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x800D1050: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x800D1054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D1058: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x800D105C: beq         $a1, $zero, L_800D1074
    if (ctx->r5 == 0) {
        // 0x800D1060: nop
    
            goto L_800D1074;
    }
    // 0x800D1060: nop

    // 0x800D1064: jal         0x800EE904
    // 0x800D1068: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    func_800EE904(rdram, ctx);
        goto after_4;
    // 0x800D1068: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    after_4:
    // 0x800D106C: b           L_800D108C
    // 0x800D1070: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
        goto L_800D108C;
    // 0x800D1070: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
L_800D1074:
    // 0x800D1074: jal         0x800D07CC
    // 0x800D1078: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800D07CC(rdram, ctx);
        goto after_5;
    // 0x800D1078: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x800D107C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x800D1080: jal         0x800EE904
    // 0x800D1084: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800EE904(rdram, ctx);
        goto after_6;
    // 0x800D1084: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_6:
    // 0x800D1088: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
L_800D108C:
    // 0x800D108C: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x800D1090: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x800D1094: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800D1098: sll         $t6, $s0, 16
    ctx->r14 = S32(ctx->r16 << 16);
    // 0x800D109C: andi        $t7, $s1, 0xFFFF
    ctx->r15 = ctx->r17 & 0XFFFF;
    // 0x800D10A0: or          $a1, $t6, $t7
    ctx->r5 = ctx->r14 | ctx->r15;
    // 0x800D10A4: addiu       $a0, $a0, 0xF9C
    ctx->r4 = ADD32(ctx->r4, 0XF9C);
    // 0x800D10A8: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800D10AC: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x800D10B0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800D10B4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800D10B8: jal         0x80086D58
    // 0x800D10BC: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    _chbaddiesetup_entrypoint_6(rdram, ctx);
        goto after_7;
    // 0x800D10BC: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_7:
L_800D10C0:
    // 0x800D10C0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800D10C4: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x800D10C8: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800D10CC: jr          $ra
    // 0x800D10D0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800D10D0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80800890_chpowerhutwitchy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800890: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800894: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800898: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8080089C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808008A0: jal         0x800BEA88
    // 0x808008A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BEA88(rdram, ctx);
        goto after_0;
    // 0x808008A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x808008A8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x808008AC: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x808008B0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808008B4: addiu       $s0, $s0, 0x6088
    ctx->r16 = ADD32(ctx->r16, 0X6088);
    // 0x808008B8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808008BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808008C0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808008C4: jal         0x80088660
    // 0x808008C8: lw          $a3, 0x0($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808008C8: lw          $a3, 0x0($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X0);
    after_1:
    // 0x808008CC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x808008D0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808008D4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808008D8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808008DC: jal         0x80088660
    // 0x808008E0: lw          $a3, 0x0($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x808008E0: lw          $a3, 0x0($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X0);
    after_2:
    // 0x808008E4: jal         0x800BEA88
    // 0x808008E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800BEA88(rdram, ctx);
        goto after_3;
    // 0x808008E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x808008EC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x808008F0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808008F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808008F8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808008FC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800900: jal         0x80088660
    // 0x80800904: lw          $a3, 0x0($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x80800904: lw          $a3, 0x0($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X0);
    after_4:
    // 0x80800908: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8080090C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800910: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800914: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800918: jal         0x80088660
    // 0x8080091C: lw          $a3, 0x0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x8080091C: lw          $a3, 0x0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X0);
    after_5:
    // 0x80800920: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800924: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800928: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080092C: jr          $ra
    // 0x80800930: nop

    return;
    // 0x80800930: nop

;}
RECOMP_FUNC void func_80803E10_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803E10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80803E14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803E18: jal         0x80100094
    // 0x80803E1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80803E1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80803E20: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80803E24: sb          $zero, 0xB($v0)
    MEM_B(0XB, ctx->r2) = 0;
    // 0x80803E28: sb          $zero, 0xC($v0)
    MEM_B(0XC, ctx->r2) = 0;
    // 0x80803E2C: sb          $zero, 0xD($v0)
    MEM_B(0XD, ctx->r2) = 0;
    // 0x80803E30: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9B40) << 16);
    // 0x80803E34: lwc1        $f12, -0x64C0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9B40));
    // 0x80803E38: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80803E3C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80803E40: jal         0x800DC178
    // 0x80803E44: nop

    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80803E44: nop

    after_1:
    // 0x80803E48: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80803E4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80803E50: jal         0x800E8B74
    // 0x80803E54: swc1        $f0, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f0.u32l;
    func_800E8B74(rdram, ctx);
        goto after_2;
    // 0x80803E54: swc1        $f0, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f0.u32l;
    after_2:
    // 0x80803E58: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80803E5C: lui         $a1, 0x8081
    ctx->r5 = S32(RELOC_HI16(1480, 0X9F98) << 16);
    // 0x80803E60: addiu       $a1, $a1, -0x6068
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1480, 0X9F98));
    // 0x80803E64: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x80803E68: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80803E6C: jal         0x800E8D5C
    // 0x80803E70: sb          $v0, 0xA($v1)
    MEM_B(0XA, ctx->r3) = ctx->r2;
    func_800E8D5C(rdram, ctx);
        goto after_3;
    // 0x80803E70: sb          $v0, 0xA($v1)
    MEM_B(0XA, ctx->r3) = ctx->r2;
    after_3:
    // 0x80803E74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803E78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80803E7C: jr          $ra
    // 0x80803E80: nop

    return;
    // 0x80803E80: nop

;}
RECOMP_FUNC void func_80800110_basnowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800110: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800114: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800118: jal         0x800A1718
    // 0x8080011C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800A1718(rdram, ctx);
        goto after_0;
    // 0x8080011C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800120: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(604, 0X1068) << 16);
    // 0x80800124: addiu       $t7, $t7, 0x1068
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(604, 0X1068));
    // 0x80800128: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x8080012C: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80800130: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x80800134: lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4);
    // 0x80800138: jal         0x800A4D6C
    // 0x8080013C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A4D6C(rdram, ctx);
        goto after_1;
    // 0x8080013C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800144: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800148: jr          $ra
    // 0x8080014C: nop

    return;
    // 0x8080014C: nop

;}
RECOMP_FUNC void func_80800290_chpoolkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800290: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80800294: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800298: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080029C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808002A0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808002A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808002AC: addiu       $s1, $a0, 0x4
    ctx->r17 = ADD32(ctx->r4, 0X4);
    // 0x808002B0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808002B4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808002B8: jal         0x8008FB58
    // 0x808002BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8008FB58(rdram, ctx);
        goto after_0;
    // 0x808002BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x808002C0: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x808002C4: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808002C8: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x808002CC: sltiu       $at, $t7, 0x6
    ctx->r1 = ctx->r15 < 0X6 ? 1 : 0;
    // 0x808002D0: beq         $at, $zero, L_808003C8
    if (ctx->r1 == 0) {
        // 0x808002D4: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_808003C8;
    }
    // 0x808002D4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x808002D8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808002DC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1092, 0X1280) << 16);
    // 0x808002E0: addu        $at, $at, $t7
    gpr jr_addend_808002E8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808002E4: lw          $t7, 0x1280($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1092, 0X1280));
    // 0x808002E8: jr          $t7
    // 0x808002EC: nop

    switch (jr_addend_808002E8 >> 2) {
        case 0: goto L_808002F0; break;
        case 1: goto L_80800328; break;
        case 2: goto L_808003C8; break;
        case 3: goto L_80800338; break;
        case 4: goto L_80800370; break;
        case 5: goto L_808003A8; break;
        default: switch_error(__func__, 0x808002E8, 0x80801280);
    }
    // 0x808002EC: nop

L_808002F0:
    // 0x808002F0: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    // 0x808002F4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1092, 0X14D8) << 16);
    // 0x808002F8: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1092, 0X1318) << 16);
    // 0x808002FC: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x80800300: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800304: addiu       $a3, $a3, 0x1318
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1092, 0X1318));
    // 0x80800308: addiu       $a2, $a2, 0x14D8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1092, 0X14D8));
    // 0x8080030C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800310: jal         0x8008A1F0
    // 0x80800314: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800314: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x80800318: jal         0x80800B38
    // 0x8080031C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800B38_chpoolkids(rdram, ctx);
        goto after_2;
    // 0x8080031C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800320: b           L_808003CC
    // 0x80800324: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808003CC;
    // 0x80800324: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800328:
    // 0x80800328: jal         0x80800B38
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800B38_chpoolkids(rdram, ctx);
        goto after_3;
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800330: b           L_808003CC
    // 0x80800334: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808003CC;
    // 0x80800334: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800338:
    // 0x80800338: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    // 0x8080033C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1092, 0X14D8) << 16);
    // 0x80800340: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1092, 0X1340) << 16);
    // 0x80800344: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80800348: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8080034C: addiu       $a3, $a3, 0x1340
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1092, 0X1340));
    // 0x80800350: addiu       $a2, $a2, 0x14D8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1092, 0X14D8));
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800358: jal         0x8008A1F0
    // 0x8080035C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_4;
    // 0x8080035C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x80800360: jal         0x80800B38
    // 0x80800364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800B38_chpoolkids(rdram, ctx);
        goto after_5;
    // 0x80800364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800368: b           L_808003CC
    // 0x8080036C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808003CC;
    // 0x8080036C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800370:
    // 0x80800370: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    // 0x80800374: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1092, 0X14D8) << 16);
    // 0x80800378: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1092, 0X1360) << 16);
    // 0x8080037C: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80800380: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800384: addiu       $a3, $a3, 0x1360
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1092, 0X1360));
    // 0x80800388: addiu       $a2, $a2, 0x14D8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1092, 0X14D8));
    // 0x8080038C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800390: jal         0x8008A1F0
    // 0x80800394: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x80800394: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x80800398: jal         0x80800B38
    // 0x8080039C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800B38_chpoolkids(rdram, ctx);
        goto after_7;
    // 0x8080039C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808003A0: b           L_808003CC
    // 0x808003A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808003CC;
    // 0x808003A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808003A8:
    // 0x808003A8: jal         0x80800884
    // 0x808003AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800884_chpoolkids(rdram, ctx);
        goto after_8;
    // 0x808003AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808003B0: jal         0x808008DC
    // 0x808003B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008DC_chpoolkids(rdram, ctx);
        goto after_9;
    // 0x808003B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808003B8: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x808003BC: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x808003C0: jal         0x80800944
    // 0x808003C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800944_chpoolkids(rdram, ctx);
        goto after_10;
    // 0x808003C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
L_808003C8:
    // 0x808003C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808003CC:
    // 0x808003CC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808003D0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808003D4: jr          $ra
    // 0x808003D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808003D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void bsstonehead_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B24: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800B28: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(376, 0X1660) << 16);
    // 0x80800B2C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800B30: jr          $ra
    // 0x80800B34: lw          $v0, 0x1660($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(376, 0X1660));
    return;
    // 0x80800B34: lw          $v0, 0x1660($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(376, 0X1660));
;}
RECOMP_FUNC void func_800BEAAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BEAAC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800BEAB0: lbu         $t6, -0x79D9($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X79D9);
    // 0x800BEAB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BEAB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BEABC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800BEAC0: beq         $t6, $zero, L_800BEAE0
    if (ctx->r14 == 0) {
        // 0x800BEAC4: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_800BEAE0;
    }
    // 0x800BEAC4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800BEAC8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BEACC: addiu       $a0, $a0, -0x7A50
    ctx->r4 = ADD32(ctx->r4, -0X7A50);
    // 0x800BEAD0: jal         0x80087F30
    // 0x800BEAD4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    _gcmapsects_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x800BEAD4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x800BEAD8: b           L_800BEAE8
    // 0x800BEADC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800BEAE8;
    // 0x800BEADC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800BEAE0:
    // 0x800BEAE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BEAE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800BEAE8:
    // 0x800BEAE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BEAEC: jr          $ra
    // 0x800BEAF0: nop

    return;
    // 0x800BEAF0: nop

;}
RECOMP_FUNC void bareact_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800064: lw          $t6, 0xEC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XEC);
    // 0x80800068: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8080006C: jr          $ra
    // 0x80800070: lbu         $v0, 0x1($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X1);
    return;
    // 0x80800070: lbu         $v0, 0x1($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X1);
;}
RECOMP_FUNC void _fxstep_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800889F8: syscall     718
    recomp_syscall_handler(rdram, ctx, 0x800889F8);
    return;
    // 0x800889FC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800948_bsbanshack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800948: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080094C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800950: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800954: jal         0x8080021C
    // 0x80800958: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8080021C_bsbanshack(rdram, ctx);
        goto after_0;
    // 0x80800958: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080095C: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x80800960: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800968: jal         0x8008CB3C
    // 0x8080096C: addiu       $a1, $zero, 0x146
    ctx->r5 = ADD32(0, 0X146);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x8080096C: addiu       $a1, $zero, 0x146
    ctx->r5 = ADD32(0, 0X146);
    after_1:
    // 0x80800970: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800974: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080097C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800980: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800984: jal         0x8009FFD8
    // 0x80800988: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80800988: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x8080098C: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80800990: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800998: jal         0x8008C9BC
    // 0x8080099C: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    baanim_setDurationRange(rdram, ctx);
        goto after_3;
    // 0x8080099C: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    after_3:
    // 0x808009A0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808009A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808009A8: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x808009AC: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808009B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009B4: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x808009B8: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    // 0x808009BC: jal         0x8008C9F0
    // 0x808009C0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_4;
    // 0x808009C0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x808009C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009C8: jal         0x8008CA30
    // 0x808009CC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8008CA30(rdram, ctx);
        goto after_5;
    // 0x808009CC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_5:
    // 0x808009D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808009D4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808009D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808009DC: jr          $ra
    // 0x808009E0: nop

    return;
    // 0x808009E0: nop

;}
RECOMP_FUNC void func_8080051C_chbouncycastle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080051C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80800520: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x80800524: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800528: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x8080052C: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x80800530: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1000, 0X8F0) << 16);
    // 0x80800534: lwc1        $f28, 0x8F0($at)
    ctx->f28.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1000, 0X8F0));
    // 0x80800538: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x8080053C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800540: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x80800544: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x80800548: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8080054C: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80800550: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x80800554: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x80800558: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x8080055C: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80800560: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1000, 0X8F4) << 16);
    // 0x80800564: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(1000, 0XA5C) << 16);
    // 0x80800568: lui         $s6, 0x8080
    ctx->r22 = S32(RELOC_HI16(1000, 0XA50) << 16);
    // 0x8080056C: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80800570: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800574: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80800578: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x8080057C: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x80800580: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800584: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
    // 0x80800588: addiu       $s6, $s6, 0xA50
    ctx->r22 = ADD32(ctx->r22, (int16_t)RELOC_LO16(1000, 0XA50));
    // 0x8080058C: addiu       $s2, $s2, 0xA5C
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(1000, 0XA5C));
    // 0x80800590: lwc1        $f24, 0x8F4($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1000, 0X8F4));
    // 0x80800594: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80800598:
    // 0x80800598: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8080059C: jal         0x80101E14
    // 0x808005A0: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    func_80101E14(rdram, ctx);
        goto after_0;
    // 0x808005A0: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    after_0:
    // 0x808005A4: beq         $v0, $zero, L_80800620
    if (ctx->r2 == 0) {
        // 0x808005A8: addiu       $t6, $zero, 0x3
        ctx->r14 = ADD32(0, 0X3);
            goto L_80800620;
    }
    // 0x808005A8: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x808005AC: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x808005B0: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x808005B4: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x808005B8: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808005BC: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x808005C0: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x808005C4: addiu       $s0, $s3, 0x4
    ctx->r16 = ADD32(ctx->r19, 0X4);
    // 0x808005C8: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808005CC: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x808005D0: jal         0x800F10B4
    // 0x808005D4: nop

    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x808005D4: nop

    after_1:
    // 0x808005D8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x808005DC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808005E0: jal         0x80089D10
    // 0x808005E4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x808005E4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x808005E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1000, 0X8F8) << 16);
    // 0x808005EC: lwc1        $f8, 0x8F8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1000, 0X8F8));
    // 0x808005F0: mfc1        $a1, $f28
    ctx->r5 = (int32_t)ctx->f28.u32l;
    // 0x808005F4: mfc1        $a2, $f30
    ctx->r6 = (int32_t)ctx->f30.u32l;
    // 0x808005F8: add.s       $f10, $f20, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f20.fl + ctx->f8.fl;
    // 0x808005FC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800600: andi        $s4, $v0, 0xFF
    ctx->r20 = ctx->r2 & 0XFF;
    // 0x80800604: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x80800608: jal         0x800C3868
    // 0x8080060C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800C3868(rdram, ctx);
        goto after_3;
    // 0x8080060C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x80800610: andi        $a0, $s4, 0xFF
    ctx->r4 = ctx->r20 & 0XFF;
    // 0x80800614: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800618: jal         0x800C4350
    // 0x8080061C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_800C4350(rdram, ctx);
        goto after_4;
    // 0x8080061C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_4:
L_80800620:
    // 0x80800620: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800624: slt         $at, $s1, $s5
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80800628: bne         $at, $zero, L_80800598
    if (ctx->r1 != 0) {
        // 0x8080062C: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80800598;
    }
    // 0x8080062C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80800630: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80800634: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80800638: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8080063C: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80800640: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80800644: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x80800648: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x8080064C: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x80800650: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x80800654: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x80800658: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x8080065C: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x80800660: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x80800664: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x80800668: jr          $ra
    // 0x8080066C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8080066C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_808003F4_chstonepillar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808003F8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808003FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800400: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800404: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800408: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8080040C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800410: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800414: addiu       $s2, $zero, 0x5
    ctx->r18 = ADD32(0, 0X5);
L_80800418:
    // 0x80800418: addiu       $s1, $s0, 0x1
    ctx->r17 = ADD32(ctx->r16, 0X1);
    // 0x8080041C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800420: jal         0x800DF744
    // 0x80800424: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_0;
    // 0x80800424: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800428: bne         $s1, $s2, L_80800418
    if (ctx->r17 != ctx->r18) {
        // 0x8080042C: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80800418;
    }
    // 0x8080042C: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80800430: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800434: jal         0x80100094
    // 0x80800438: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800438: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8080043C: lbu         $a0, 0x2E($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X2E);
    // 0x80800440: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800444: jal         0x800DF744
    // 0x80800448: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    func_800DF744(rdram, ctx);
        goto after_2;
    // 0x80800448: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    after_2:
    // 0x8080044C: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80800450: addiu       $a1, $a1, 0x15D0
    ctx->r5 = ADD32(ctx->r5, 0X15D0);
    // 0x80800454: jal         0x80101808
    // 0x80800458: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80101808(rdram, ctx);
        goto after_3;
    // 0x80800458: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x8080045C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800460: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800464: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800468: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8080046C: jr          $ra
    // 0x80800470: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800470: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80800FDC_chcoderoombits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FDC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800FE0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800FE4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800FE8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800FEC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800FF0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800FF4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80800FF8: addiu       $s2, $zero, 0xD
    ctx->r18 = ADD32(0, 0XD);
L_80800FFC:
    // 0x80800FFC: jal         0x800D3E14
    // 0x80801000: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800D3E14(rdram, ctx);
        goto after_0;
    // 0x80801000: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80801004: beq         $v0, $zero, L_80801010
    if (ctx->r2 == 0) {
        // 0x80801008: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80801010;
    }
    // 0x80801008: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8080100C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80801010:
    // 0x80801010: bne         $s0, $s2, L_80800FFC
    if (ctx->r16 != ctx->r18) {
        // 0x80801014: nop
    
            goto L_80800FFC;
    }
    // 0x80801014: nop

    // 0x80801018: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080101C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80801020: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80801024: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801028: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8080102C: jr          $ra
    // 0x80801030: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80801030: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801034: nop

    // 0x80801038: nop

    // 0x8080103C: nop

;}
RECOMP_FUNC void _chcheato_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085CB8: syscall     222
    recomp_syscall_handler(rdram, ctx, 0x80085CB8);
    return;
    // 0x80085CBC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _susubgame_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A2B8: syscall     834
    recomp_syscall_handler(rdram, ctx, 0x8008A2B8);
    return;
    // 0x8008A2BC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800060_bsstonehead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800060: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800064: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800068: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080006C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800070: jal         0x8009E77C
    // 0x80800074: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8009E77C(rdram, ctx);
        goto after_0;
    // 0x80800074: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x80800078: bne         $v0, $zero, L_808000B8
    if (ctx->r2 != 0) {
        // 0x8080007C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000B8;
    }
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800080: lui         $a1, 0x4282
    ctx->r5 = S32(0X4282 << 16);
    // 0x80800084: jal         0x800959C8
    // 0x80800088: lui         $a2, 0x420C
    ctx->r6 = S32(0X420C << 16);
    func_800959C8(rdram, ctx);
        goto after_1;
    // 0x80800088: lui         $a2, 0x420C
    ctx->r6 = S32(0X420C << 16);
    after_1:
    // 0x8080008C: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x80800090: ori         $a1, $a1, 0x6600
    ctx->r5 = ctx->r5 | 0X6600;
    // 0x80800094: jal         0x80092864
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80092864(rdram, ctx);
        goto after_2;
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080009C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000A4: jal         0x800947EC
    // 0x808000A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800947EC(rdram, ctx);
        goto after_3;
    // 0x808000A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B0: jal         0x80095A74
    // 0x808000B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80095A74(rdram, ctx);
        goto after_4;
    // 0x808000B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
L_808000B8:
    // 0x808000B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000C4: jr          $ra
    // 0x808000C8: nop

    return;
    // 0x808000C8: nop

;}
RECOMP_FUNC void bsbwhirl_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800BF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BFC: jal         0x8009BC6C
    // 0x80800C00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    baphysics_reset_gravity(rdram, ctx);
        goto after_0;
    // 0x80800C00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800C04: jal         0x8080017C
    // 0x80800C08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8080017C_bsbwhirl(rdram, ctx);
        goto after_1;
    // 0x80800C08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800C0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C14: jr          $ra
    // 0x80800C18: nop

    return;
    // 0x80800C18: nop

;}
RECOMP_FUNC void bafpctrl_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B94: lw          $t6, 0x90($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X90);
    // 0x80800B98: jr          $ra
    // 0x80800B9C: lbu         $v0, 0x11($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X11);
    return;
    // 0x80800B9C: lbu         $v0, 0x11($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X11);
;}
RECOMP_FUNC void func_8080182C_chfantasyeyeball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080182C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80801830: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80801834: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801838: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080183C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80801840: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    // 0x80801844: jal         0x800D91EC
    // 0x80801848: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    func_800D91EC(rdram, ctx);
        goto after_0;
    // 0x80801848: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    after_0:
    // 0x8080184C: beq         $v0, $zero, L_80801868
    if (ctx->r2 == 0) {
        // 0x80801850: addiu       $a0, $sp, 0x4C
        ctx->r4 = ADD32(ctx->r29, 0X4C);
            goto L_80801868;
    }
    // 0x80801850: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80801854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801858: jal         0x80801BC4
    // 0x8080185C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801BC4_chfantasyeyeball(rdram, ctx);
        goto after_1;
    // 0x8080185C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80801860: b           L_80801A40
    // 0x80801864: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801A40;
    // 0x80801864: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801868:
    // 0x80801868: addiu       $s1, $s0, 0x4
    ctx->r17 = ADD32(ctx->r16, 0X4);
    // 0x8080186C: jal         0x800EE7F8
    // 0x80801870: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80801870: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x80801874: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80801878: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8080187C: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80801880: nop

    // 0x80801884: bc1f        L_808018FC
    if (!c1cs) {
        // 0x80801888: nop
    
            goto L_808018FC;
    }
    // 0x80801888: nop

    // 0x8080188C: jal         0x800D8FF8
    // 0x80801890: nop

    func_800D8FF8(rdram, ctx);
        goto after_3;
    // 0x80801890: nop

    after_3:
    // 0x80801894: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80801898: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x8080189C: jal         0x800EF174
    // 0x808018A0: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    func_800EF174(rdram, ctx);
        goto after_4;
    // 0x808018A0: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    after_4:
    // 0x808018A4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808018A8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808018AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808018B0: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808018B4: lw          $a2, 0x58($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X58);
    // 0x808018B8: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x808018BC: jal         0x800F10B4
    // 0x808018C0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_5;
    // 0x808018C0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x808018C4: jal         0x80013970
    // 0x808018C8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80013970(rdram, ctx);
        goto after_6;
    // 0x808018C8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_6:
    // 0x808018CC: lwc1        $f10, 0x34($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X34);
    // 0x808018D0: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x808018D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808018D8: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x808018DC: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    // 0x808018E0: lw          $a3, 0x20($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X20);
    // 0x808018E4: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x808018E8: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x808018EC: jal         0x800EFA4C
    // 0x808018F0: nop

    func_800EFA4C(rdram, ctx);
        goto after_7;
    // 0x808018F0: nop

    after_7:
    // 0x808018F4: b           L_80801934
    // 0x808018F8: lui         $at, 0x4204
    ctx->r1 = S32(0X4204 << 16);
        goto L_80801934;
    // 0x808018F8: lui         $at, 0x4204
    ctx->r1 = S32(0X4204 << 16);
L_808018FC:
    // 0x808018FC: jal         0x800D8FF8
    // 0x80801900: nop

    func_800D8FF8(rdram, ctx);
        goto after_8;
    // 0x80801900: nop

    after_8:
    // 0x80801904: lui         $at, 0xC4FA
    ctx->r1 = S32(0XC4FA << 16);
    // 0x80801908: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080190C: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80801910: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80801914: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80801918: jal         0x800D8FF8
    // 0x8080191C: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_9;
    // 0x8080191C: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
    after_9:
    // 0x80801920: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80801924: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801928: jal         0x800EF174
    // 0x8080192C: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    func_800EF174(rdram, ctx);
        goto after_10;
    // 0x8080192C: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    after_10:
    // 0x80801930: lui         $at, 0x4204
    ctx->r1 = S32(0X4204 << 16);
L_80801934:
    // 0x80801934: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801938: lwc1        $f18, 0x38($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8080193C: lui         $a3, 0x2
    ctx->r7 = S32(0X2 << 16);
    // 0x80801940: ori         $a3, $a3, 0x20
    ctx->r7 = ctx->r7 | 0X20;
    // 0x80801944: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80801948: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x8080194C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80801950: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x80801954: jal         0x800BF340
    // 0x80801958: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800BF340(rdram, ctx);
        goto after_11;
    // 0x80801958: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_11:
    // 0x8080195C: beq         $v0, $zero, L_808019B0
    if (ctx->r2 == 0) {
        // 0x80801960: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808019B0;
    }
    // 0x80801960: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801964: addiu       $a3, $s0, 0x18
    ctx->r7 = ADD32(ctx->r16, 0X18);
    // 0x80801968: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8080196C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x80801970: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80801974: jal         0x800EFB24
    // 0x80801978: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    func_800EFB24(rdram, ctx);
        goto after_12;
    // 0x80801978: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    after_12:
    // 0x8080197C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80801980: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x80801984: jal         0x800EFDE8
    // 0x80801988: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800EFDE8(rdram, ctx);
        goto after_13;
    // 0x80801988: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_13:
    // 0x8080198C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80801990: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80801994: jal         0x800EFB24
    // 0x80801998: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800EFB24(rdram, ctx);
        goto after_14;
    // 0x80801998: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_14:
    // 0x8080199C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808019A0: jal         0x80801BC4
    // 0x808019A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801BC4_chfantasyeyeball(rdram, ctx);
        goto after_15;
    // 0x808019A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808019A8: b           L_80801A40
    // 0x808019AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801A40;
    // 0x808019AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808019B0:
    // 0x808019B0: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2400, 0X1FB0) << 16);
    // 0x808019B4: addiu       $a3, $a3, 0x1FB0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2400, 0X1FB0));
    // 0x808019B8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808019BC: jal         0x80089D50
    // 0x808019C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_16;
    // 0x808019C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_16:
    // 0x808019C4: jal         0x800B53A4
    // 0x808019C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800B53A4(rdram, ctx);
        goto after_17;
    // 0x808019C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_17:
    // 0x808019CC: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x808019D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808019D4: jal         0x800DC128
    // 0x808019D8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_800DC128(rdram, ctx);
        goto after_18;
    // 0x808019D8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_18:
    // 0x808019DC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808019E0: jal         0x800BA3FC
    // 0x808019E4: addiu       $a1, $v0, 0x9DF
    ctx->r5 = ADD32(ctx->r2, 0X9DF);
    func_800BA3FC(rdram, ctx);
        goto after_19;
    // 0x808019E4: addiu       $a1, $v0, 0x9DF
    ctx->r5 = ADD32(ctx->r2, 0X9DF);
    after_19:
    // 0x808019E8: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2400, 0X1F70) << 16);
    // 0x808019EC: addiu       $t6, $t6, 0x1F70
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2400, 0X1F70));
    // 0x808019F0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808019F4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808019F8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808019FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801A00: jal         0x800BABB8
    // 0x80801A04: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_20;
    // 0x80801A04: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_20:
    // 0x80801A08: jal         0x800D8FF8
    // 0x80801A0C: nop

    func_800D8FF8(rdram, ctx);
        goto after_21;
    // 0x80801A0C: nop

    after_21:
    // 0x80801A10: lwc1        $f10, 0x50($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80801A14: lwc1        $f6, 0x44($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80801A18: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80801A1C: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80801A20: jal         0x800D8FF8
    // 0x80801A24: swc1        $f18, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f18.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_22;
    // 0x80801A24: swc1        $f18, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f18.u32l;
    after_22:
    // 0x80801A28: lwc1        $f8, 0x54($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80801A2C: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80801A30: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80801A34: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80801A38: swc1        $f6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f6.u32l;
    // 0x80801A3C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801A40:
    // 0x80801A40: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80801A44: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80801A48: jr          $ra
    // 0x80801A4C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80801A4C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80802380_bsbtrot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802380: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802384: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80802388: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080238C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80802390: beq         $a1, $zero, L_808023B8
    if (ctx->r5 == 0) {
        // 0x80802394: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_808023B8;
    }
    // 0x80802394: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80802398: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080239C: beq         $a1, $at, L_808023C8
    if (ctx->r5 == ctx->r1) {
        // 0x808023A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808023C8;
    }
    // 0x808023A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808023A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808023A8: beq         $a1, $at, L_80802418
    if (ctx->r5 == ctx->r1) {
        // 0x808023AC: nop
    
            goto L_80802418;
    }
    // 0x808023AC: nop

    // 0x808023B0: b           L_8080246C
    // 0x808023B4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
        goto L_8080246C;
    // 0x808023B4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
L_808023B8:
    // 0x808023B8: jal         0x8009BC6C
    // 0x808023BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_0;
    // 0x808023BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x808023C0: b           L_8080246C
    // 0x808023C4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
        goto L_8080246C;
    // 0x808023C4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
L_808023C8:
    // 0x808023C8: lui         $a2, 0x3FF3
    ctx->r6 = S32(0X3FF3 << 16);
    // 0x808023CC: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x808023D0: jal         0x8008CCBC
    // 0x808023D4: addiu       $a1, $zero, 0x298
    ctx->r5 = ADD32(0, 0X298);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_1;
    // 0x808023D4: addiu       $a1, $zero, 0x298
    ctx->r5 = ADD32(0, 0X298);
    after_1:
    // 0x808023D8: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x808023DC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808023E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808023E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808023E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808023EC: jal         0x8009FFD8
    // 0x808023F0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x808023F0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x808023F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808023F8: jal         0x8009B9B0
    // 0x808023FC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_3;
    // 0x808023FC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x80802400: lui         $a1, 0xC528
    ctx->r5 = S32(0XC528 << 16);
    // 0x80802404: ori         $a1, $a1, 0xC000
    ctx->r5 = ctx->r5 | 0XC000;
    // 0x80802408: jal         0x8009BCB4
    // 0x8080240C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_gravity(rdram, ctx);
        goto after_4;
    // 0x8080240C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80802410: b           L_8080246C
    // 0x80802414: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
        goto L_8080246C;
    // 0x80802414: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
L_80802418:
    // 0x80802418: jal         0x80085060
    // 0x8080241C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bashoes_entrypoint_17(rdram, ctx);
        goto after_5;
    // 0x8080241C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80802420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802424: jal         0x8009B800
    // 0x80802428: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    baphysics_set_type(rdram, ctx);
        goto after_6;
    // 0x80802428: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_6:
    // 0x8080242C: lui         $a1, 0x4514
    ctx->r5 = S32(0X4514 << 16);
    // 0x80802430: ori         $a1, $a1, 0xF000
    ctx->r5 = ctx->r5 | 0XF000;
    // 0x80802434: jal         0x8009BA58
    // 0x80802438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_7;
    // 0x80802438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080243C: lui         $a2, 0x3F73
    ctx->r6 = S32(0X3F73 << 16);
    // 0x80802440: lui         $a3, 0x3F86
    ctx->r7 = S32(0X3F86 << 16);
    // 0x80802444: addiu       $t8, $zero, 0x7FFF
    ctx->r24 = ADD32(0, 0X7FFF);
    // 0x80802448: addiu       $t9, $zero, 0x7FFF
    ctx->r25 = ADD32(0, 0X7FFF);
    // 0x8080244C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80802450: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80802454: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80802458: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x8080245C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802460: jal         0x8009DEC0
    // 0x80802464: addiu       $a1, $zero, 0x4598
    ctx->r5 = ADD32(0, 0X4598);
    func_8009DEC0(rdram, ctx);
        goto after_8;
    // 0x80802464: addiu       $a1, $zero, 0x4598
    ctx->r5 = ADD32(0, 0X4598);
    after_8:
    // 0x80802468: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
L_8080246C:
    // 0x8080246C: sw          $t0, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r8;
    // 0x80802470: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80802474: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80802478: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080247C: jr          $ra
    // 0x80802480: nop

    return;
    // 0x80802480: nop

;}
RECOMP_FUNC void func_800E0450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E0450: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x800E0454: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x800E0458: subu        $v0, $t6, $t7
    ctx->r2 = SUB32(ctx->r14, ctx->r15);
    // 0x800E045C: jr          $ra
    // 0x800E0460: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    return;
    // 0x800E0460: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
;}
RECOMP_FUNC void gczoombox_entrypoint_38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803B24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803B28: beq         $a0, $zero, L_80803B38
    if (ctx->r4 == 0) {
        // 0x80803B2C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80803B38;
    }
    // 0x80803B2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803B30: jal         0x80800294
    // 0x80803B34: sh          $a1, 0x1B0($a0)
    MEM_H(0X1B0, ctx->r4) = ctx->r5;
    func_80800294_gczoombox(rdram, ctx);
        goto after_0;
    // 0x80803B34: sh          $a1, 0x1B0($a0)
    MEM_H(0X1B0, ctx->r4) = ctx->r5;
    after_0:
L_80803B38:
    // 0x80803B38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803B3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803B40: jr          $ra
    // 0x80803B44: nop

    return;
    // 0x80803B44: nop

;}
RECOMP_FUNC void func_80802464_chjiggygamenew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802464: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802468: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080246C: jal         0x800E41CC
    // 0x80802470: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800E41CC(rdram, ctx);
        goto after_0;
    // 0x80802470: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80802474: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80802478: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080247C: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x80802480: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80802484: jal         0x800E3C8C
    // 0x80802488: nop

    func_800E3C8C(rdram, ctx);
        goto after_1;
    // 0x80802488: nop

    after_1:
    // 0x8080248C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(772, 0X3D10) << 16);
    // 0x80802490: jal         0x800E3BAC
    // 0x80802494: addiu       $a0, $a0, 0x3D10
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(772, 0X3D10));
    func_800E3BAC(rdram, ctx);
        goto after_2;
    // 0x80802494: addiu       $a0, $a0, 0x3D10
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(772, 0X3D10));
    after_2:
    // 0x80802498: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(772, 0X3D1C) << 16);
    // 0x8080249C: jal         0x800E3C30
    // 0x808024A0: addiu       $a0, $a0, 0x3D1C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(772, 0X3D1C));
    func_800E3C30(rdram, ctx);
        goto after_3;
    // 0x808024A0: addiu       $a0, $a0, 0x3D1C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(772, 0X3D1C));
    after_3:
    // 0x808024A4: jal         0x800E3CE8
    // 0x808024A8: nop

    func_800E3CE8(rdram, ctx);
        goto after_4;
    // 0x808024A8: nop

    after_4:
    // 0x808024AC: jal         0x800E44FC
    // 0x808024B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800E44FC(rdram, ctx);
        goto after_5;
    // 0x808024B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_5:
    // 0x808024B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808024B8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(772, 0X3D28) << 16);
    // 0x808024BC: lwc1        $f0, 0x3D28($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(772, 0X3D28));
    // 0x808024C0: jr          $ra
    // 0x808024C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x808024C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800D35D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D35D0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800D35D4: beq         $a0, $v0, L_800D35F8
    if (ctx->r4 == ctx->r2) {
        // 0x800D35D8: nop
    
            goto L_800D35F8;
    }
    // 0x800D35D8: nop

    // 0x800D35DC: beq         $a0, $zero, L_800D35F8
    if (ctx->r4 == 0) {
        // 0x800D35E0: slti        $at, $a1, 0x61
        ctx->r1 = SIGNED(ctx->r5) < 0X61 ? 1 : 0;
            goto L_800D35F8;
    }
    // 0x800D35E0: slti        $at, $a1, 0x61
    ctx->r1 = SIGNED(ctx->r5) < 0X61 ? 1 : 0;
    // 0x800D35E4: bne         $at, $zero, L_800D35F8
    if (ctx->r1 != 0) {
        // 0x800D35E8: slti        $at, $a1, 0x7B
        ctx->r1 = SIGNED(ctx->r5) < 0X7B ? 1 : 0;
            goto L_800D35F8;
    }
    // 0x800D35E8: slti        $at, $a1, 0x7B
    ctx->r1 = SIGNED(ctx->r5) < 0X7B ? 1 : 0;
    // 0x800D35EC: beq         $at, $zero, L_800D35F8
    if (ctx->r1 == 0) {
        // 0x800D35F0: nop
    
            goto L_800D35F8;
    }
    // 0x800D35F0: nop

    // 0x800D35F4: addiu       $a1, $a1, -0x20
    ctx->r5 = ADD32(ctx->r5, -0X20);
L_800D35F8:
    // 0x800D35F8: beq         $a0, $zero, L_800D3624
    if (ctx->r4 == 0) {
        // 0x800D35FC: slti        $at, $a1, 0x21
        ctx->r1 = SIGNED(ctx->r5) < 0X21 ? 1 : 0;
            goto L_800D3624;
    }
    // 0x800D35FC: slti        $at, $a1, 0x21
    ctx->r1 = SIGNED(ctx->r5) < 0X21 ? 1 : 0;
    // 0x800D3600: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D3604: beql        $a0, $at, L_800D3640
    if (ctx->r4 == ctx->r1) {
        // 0x800D3608: slti        $at, $a1, 0x80
        ctx->r1 = SIGNED(ctx->r5) < 0X80 ? 1 : 0;
            goto L_800D3640;
    }
    goto skip_0;
    // 0x800D3608: slti        $at, $a1, 0x80
    ctx->r1 = SIGNED(ctx->r5) < 0X80 ? 1 : 0;
    skip_0:
    // 0x800D360C: beq         $a0, $v0, L_800D3660
    if (ctx->r4 == ctx->r2) {
        // 0x800D3610: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800D3660;
    }
    // 0x800D3610: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800D3614: beql        $a0, $at, L_800D367C
    if (ctx->r4 == ctx->r1) {
        // 0x800D3618: slti        $at, $a1, 0x30
        ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
            goto L_800D367C;
    }
    goto skip_1;
    // 0x800D3618: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    skip_1:
    // 0x800D361C: b           L_800D36A0
    // 0x800D3620: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800D36A0;
    // 0x800D3620: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800D3624:
    // 0x800D3624: bne         $at, $zero, L_800D369C
    if (ctx->r1 != 0) {
        // 0x800D3628: slti        $at, $a1, 0x7B
        ctx->r1 = SIGNED(ctx->r5) < 0X7B ? 1 : 0;
            goto L_800D369C;
    }
    // 0x800D3628: slti        $at, $a1, 0x7B
    ctx->r1 = SIGNED(ctx->r5) < 0X7B ? 1 : 0;
    // 0x800D362C: beql        $at, $zero, L_800D36A0
    if (ctx->r1 == 0) {
        // 0x800D3630: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_800D36A0;
    }
    goto skip_2;
    // 0x800D3630: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_2:
    // 0x800D3634: jr          $ra
    // 0x800D3638: addiu       $v0, $a1, -0x21
    ctx->r2 = ADD32(ctx->r5, -0X21);
    return;
    // 0x800D3638: addiu       $v0, $a1, -0x21
    ctx->r2 = ADD32(ctx->r5, -0X21);
    // 0x800D363C: slti        $at, $a1, 0x80
    ctx->r1 = SIGNED(ctx->r5) < 0X80 ? 1 : 0;
L_800D3640:
    // 0x800D3640: beq         $at, $zero, L_800D369C
    if (ctx->r1 == 0) {
        // 0x800D3644: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_800D369C;
    }
    // 0x800D3644: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800D3648: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800D364C: lb          $v1, -0x4C90($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X4C90);
    // 0x800D3650: bltzl       $v1, L_800D36A0
    if (SIGNED(ctx->r3) < 0) {
        // 0x800D3654: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_800D36A0;
    }
    goto skip_3;
    // 0x800D3654: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_3:
    // 0x800D3658: jr          $ra
    // 0x800D365C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800D365C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800D3660:
    // 0x800D3660: blez        $a1, L_800D369C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800D3664: slti        $at, $a1, 0xFD
        ctx->r1 = SIGNED(ctx->r5) < 0XFD ? 1 : 0;
            goto L_800D369C;
    }
    // 0x800D3664: slti        $at, $a1, 0xFD
    ctx->r1 = SIGNED(ctx->r5) < 0XFD ? 1 : 0;
    // 0x800D3668: beql        $at, $zero, L_800D36A0
    if (ctx->r1 == 0) {
        // 0x800D366C: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_800D36A0;
    }
    goto skip_4;
    // 0x800D366C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_4:
    // 0x800D3670: jr          $ra
    // 0x800D3674: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x800D3674: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800D3678: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
L_800D367C:
    // 0x800D367C: bne         $at, $zero, L_800D3694
    if (ctx->r1 != 0) {
        // 0x800D3680: slti        $at, $a1, 0x3B
        ctx->r1 = SIGNED(ctx->r5) < 0X3B ? 1 : 0;
            goto L_800D3694;
    }
    // 0x800D3680: slti        $at, $a1, 0x3B
    ctx->r1 = SIGNED(ctx->r5) < 0X3B ? 1 : 0;
    // 0x800D3684: beq         $at, $zero, L_800D3694
    if (ctx->r1 == 0) {
        // 0x800D3688: nop
    
            goto L_800D3694;
    }
    // 0x800D3688: nop

    // 0x800D368C: jr          $ra
    // 0x800D3690: addiu       $v0, $a1, -0x30
    ctx->r2 = ADD32(ctx->r5, -0X30);
    return;
    // 0x800D3690: addiu       $v0, $a1, -0x30
    ctx->r2 = ADD32(ctx->r5, -0X30);
L_800D3694:
    // 0x800D3694: jr          $ra
    // 0x800D3698: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    return;
    // 0x800D3698: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_800D369C:
    // 0x800D369C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800D36A0:
    // 0x800D36A0: jr          $ra
    // 0x800D36A4: nop

    return;
    // 0x800D36A4: nop

;}
RECOMP_FUNC void bamovethrust_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808000B4: lw          $t6, 0xC8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC8);
    // 0x808000B8: jr          $ra
    // 0x808000BC: swc1        $f12, 0x8C($t6)
    MEM_W(0X8C, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x808000BC: swc1        $f12, 0x8C($t6)
    MEM_W(0X8C, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void _fxegg_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088A90: syscall     719
    recomp_syscall_handler(rdram, ctx, 0x80088A90);
    return;
    // 0x80088A94: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_808000B4_chcredits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x808000B8: addiu       $v0, $v0, 0x7610
    ctx->r2 = ADD32(ctx->r2, 0X7610);
    // 0x808000BC: sb          $a0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r4;
    // 0x808000C0: jr          $ra
    // 0x808000C4: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    return;
    // 0x808000C4: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
;}
RECOMP_FUNC void _sumumbofx_entrypoint_27(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089918: syscall     797
    recomp_syscall_handler(rdram, ctx, 0x80089918);
    return;
    // 0x8008991C: addi        $t0, $zero, 0x6C
    ctx->r8 = ADD32(0, 0X6C);
;}
RECOMP_FUNC void func_80800340_chmineprospector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800340: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800344: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800348: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080034C: jal         0x80101870
    // 0x80800350: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80101870(rdram, ctx);
        goto after_0;
    // 0x80800350: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800354: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
    // 0x80800358: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x8080035C: bgezl       $t8, L_80800388
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800360: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800388;
    }
    goto skip_0;
    // 0x80800360: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800364: jal         0x80104130
    // 0x80800368: nop

    func_80104130(rdram, ctx);
        goto after_1;
    // 0x80800368: nop

    after_1:
    // 0x8080036C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800370: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800374: jal         0x800DBEFC
    // 0x80800378: addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
    func_800DBEFC(rdram, ctx);
        goto after_2;
    // 0x80800378: addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
    after_2:
    // 0x8080037C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800380: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    // 0x80800384: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800388:
    // 0x80800388: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080038C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800390: jr          $ra
    // 0x80800394: nop

    return;
    // 0x80800394: nop

;}
RECOMP_FUNC void func_80800D3C_susplinet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D3C: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x80800D40: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800D44: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80800D48: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80800D4C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80800D50: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80800D54: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800D58: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800D5C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800D60: lh          $t6, 0x34($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X34);
    // 0x80800D64: mtc1        $a1, $f22
    ctx->f22.u32l = ctx->r5;
    // 0x80800D68: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800D6C: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80800D70: sw          $t7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r15;
    // 0x80800D74: lh          $t8, 0x30($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X30);
    // 0x80800D78: lh          $t9, 0x4E($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X4E);
    // 0x80800D7C: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x80800D80: addu        $s1, $a0, $t8
    ctx->r17 = ADD32(ctx->r4, ctx->r24);
    // 0x80800D84: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x80800D88: addu        $t1, $s1, $t0
    ctx->r9 = ADD32(ctx->r17, ctx->r8);
    // 0x80800D8C: lh          $t2, -0x2($t1)
    ctx->r10 = MEM_H(ctx->r9, -0X2);
    // 0x80800D90: addiu       $s0, $sp, 0xC8
    ctx->r16 = ADD32(ctx->r29, 0XC8);
    // 0x80800D94: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800D98: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80800D9C: addiu       $a1, $sp, 0xB0
    ctx->r5 = ADD32(ctx->r29, 0XB0);
    // 0x80800DA0: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800DA4: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80800DA8: nop

    // 0x80800DAC: bc1fl       L_80800DC0
    if (!c1cs) {
        // 0x80800DB0: lh          $t3, 0x0($s1)
        ctx->r11 = MEM_H(ctx->r17, 0X0);
            goto L_80800DC0;
    }
    goto skip_0;
    // 0x80800DB0: lh          $t3, 0x0($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X0);
    skip_0:
    // 0x80800DB4: b           L_80800DE0
    // 0x80800DB8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
        goto L_80800DE0;
    // 0x80800DB8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80800DBC: lh          $t3, 0x0($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X0);
L_80800DC0:
    // 0x80800DC0: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80800DC4: nop

    // 0x80800DC8: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800DCC: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x80800DD0: nop

    // 0x80800DD4: bc1fl       L_80800DE4
    if (!c1cs) {
        // 0x80800DD8: lbu         $t4, 0x51($s3)
        ctx->r12 = MEM_BU(ctx->r19, 0X51);
            goto L_80800DE4;
    }
    goto skip_1;
    // 0x80800DD8: lbu         $t4, 0x51($s3)
    ctx->r12 = MEM_BU(ctx->r19, 0X51);
    skip_1:
    // 0x80800DDC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
L_80800DE0:
    // 0x80800DE0: lbu         $t4, 0x51($s3)
    ctx->r12 = MEM_BU(ctx->r19, 0X51);
L_80800DE4:
    // 0x80800DE4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80800DE8: blezl       $t4, L_80800E20
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80800DEC: lbu         $t8, 0x52($s3)
        ctx->r24 = MEM_BU(ctx->r19, 0X52);
            goto L_80800E20;
    }
    goto skip_2;
    // 0x80800DEC: lbu         $t8, 0x52($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X52);
    skip_2:
    // 0x80800DF0: lh          $t5, 0x36($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X36);
L_80800DF4:
    // 0x80800DF4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800DF8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800DFC: addu        $t6, $t5, $s3
    ctx->r14 = ADD32(ctx->r13, ctx->r19);
    // 0x80800E00: sw          $t6, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r14;
    // 0x80800E04: lbu         $t7, 0x51($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X51);
    // 0x80800E08: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80800E0C: slt         $at, $s2, $t7
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80800E10: bnel        $at, $zero, L_80800DF4
    if (ctx->r1 != 0) {
        // 0x80800E14: lh          $t5, 0x36($v0)
        ctx->r13 = MEM_H(ctx->r2, 0X36);
            goto L_80800DF4;
    }
    goto skip_3;
    // 0x80800E14: lh          $t5, 0x36($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X36);
    skip_3:
    // 0x80800E18: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80800E1C: lbu         $t8, 0x52($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X52);
L_80800E20:
    // 0x80800E20: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x80800E24: addiu       $s0, $sp, 0xBC
    ctx->r16 = ADD32(ctx->r29, 0XBC);
    // 0x80800E28: blezl       $t8, L_80800E5C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80800E2C: lh          $t2, 0x4E($s3)
        ctx->r10 = MEM_H(ctx->r19, 0X4E);
            goto L_80800E5C;
    }
    goto skip_4;
    // 0x80800E2C: lh          $t2, 0x4E($s3)
    ctx->r10 = MEM_H(ctx->r19, 0X4E);
    skip_4:
    // 0x80800E30: lh          $t9, 0x3E($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X3E);
L_80800E34:
    // 0x80800E34: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800E38: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80800E3C: addu        $t0, $t9, $s3
    ctx->r8 = ADD32(ctx->r25, ctx->r19);
    // 0x80800E40: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80800E44: lbu         $t1, 0x52($s3)
    ctx->r9 = MEM_BU(ctx->r19, 0X52);
    // 0x80800E48: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800E4C: slt         $at, $s2, $t1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80800E50: bnel        $at, $zero, L_80800E34
    if (ctx->r1 != 0) {
        // 0x80800E54: lh          $t9, 0x3E($v0)
        ctx->r25 = MEM_H(ctx->r2, 0X3E);
            goto L_80800E34;
    }
    goto skip_5;
    // 0x80800E54: lh          $t9, 0x3E($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X3E);
    skip_5:
    // 0x80800E58: lh          $t2, 0x4E($s3)
    ctx->r10 = MEM_H(ctx->r19, 0X4E);
L_80800E5C:
    // 0x80800E5C: slti        $at, $t2, 0x4
    ctx->r1 = SIGNED(ctx->r10) < 0X4 ? 1 : 0;
    // 0x80800E60: bnel        $at, $zero, L_808010C4
    if (ctx->r1 != 0) {
        // 0x80800E64: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_808010C4;
    }
    goto skip_6;
    // 0x80800E64: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_6:
    // 0x80800E68: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80800E6C: jal         0x80800620
    // 0x80800E70: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    func_80800620_susplinet(rdram, ctx);
        goto after_0;
    // 0x80800E70: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    after_0:
    // 0x80800E74: lh          $t4, 0xB2($sp)
    ctx->r12 = MEM_H(ctx->r29, 0XB2);
    // 0x80800E78: lh          $t3, 0xB0($sp)
    ctx->r11 = MEM_H(ctx->r29, 0XB0);
    // 0x80800E7C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800E80: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80800E84: beq         $t3, $t4, L_80800ECC
    if (ctx->r11 == ctx->r12) {
        // 0x80800E88: addu        $t6, $s1, $t5
        ctx->r14 = ADD32(ctx->r17, ctx->r13);
            goto L_80800ECC;
    }
    // 0x80800E88: addu        $t6, $s1, $t5
    ctx->r14 = ADD32(ctx->r17, ctx->r13);
    // 0x80800E8C: sll         $t7, $t3, 1
    ctx->r15 = S32(ctx->r11 << 1);
    // 0x80800E90: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x80800E94: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x80800E98: lh          $v0, 0x0($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X0);
    // 0x80800E9C: bnel        $t9, $v0, L_80800ED0
    if (ctx->r25 != ctx->r2) {
        // 0x80800EA0: sb          $zero, 0x53($s3)
        MEM_B(0X53, ctx->r19) = 0;
            goto L_80800ED0;
    }
    goto skip_7;
    // 0x80800EA0: sb          $zero, 0x53($s3)
    MEM_B(0X53, ctx->r19) = 0;
    skip_7:
    // 0x80800EA4: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80800EA8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800EAC: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800EB0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800EB4: jal         0x80800214
    // 0x80800EB8: nop

    susplinet_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80800EB8: nop

    after_1:
    // 0x80800EBC: beq         $v0, $zero, L_80800ECC
    if (ctx->r2 == 0) {
        // 0x80800EC0: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80800ECC;
    }
    // 0x80800EC0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80800EC4: b           L_80800ED0
    // 0x80800EC8: sb          $t0, 0x53($s3)
    MEM_B(0X53, ctx->r19) = ctx->r8;
        goto L_80800ED0;
    // 0x80800EC8: sb          $t0, 0x53($s3)
    MEM_B(0X53, ctx->r19) = ctx->r8;
L_80800ECC:
    // 0x80800ECC: sb          $zero, 0x53($s3)
    MEM_B(0X53, ctx->r19) = 0;
L_80800ED0:
    // 0x80800ED0: lh          $t1, 0xB0($sp)
    ctx->r9 = MEM_H(ctx->r29, 0XB0);
    // 0x80800ED4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80800ED8: lh          $t2, 0xB2($sp)
    ctx->r10 = MEM_H(ctx->r29, 0XB2);
    // 0x80800EDC: multu       $t1, $v0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800EE0: lh          $t4, 0xB4($sp)
    ctx->r12 = MEM_H(ctx->r29, 0XB4);
    // 0x80800EE4: lh          $t5, 0xB6($sp)
    ctx->r13 = MEM_H(ctx->r29, 0XB6);
    // 0x80800EE8: lbu         $t6, 0x51($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X51);
    // 0x80800EEC: addiu       $s0, $sp, 0xC8
    ctx->r16 = ADD32(ctx->r29, 0XC8);
    // 0x80800EF0: or          $s4, $s3, $zero
    ctx->r20 = ctx->r19 | 0;
    // 0x80800EF4: addiu       $s1, $sp, 0x6C
    ctx->r17 = ADD32(ctx->r29, 0X6C);
    // 0x80800EF8: mflo        $v1
    ctx->r3 = lo;
    // 0x80800EFC: nop

    // 0x80800F00: nop

    // 0x80800F04: multu       $t2, $v0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800F08: mflo        $a0
    ctx->r4 = lo;
    // 0x80800F0C: sll         $t3, $a0, 2
    ctx->r11 = S32(ctx->r4 << 2);
    // 0x80800F10: nop

    // 0x80800F14: multu       $t4, $v0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800F18: mflo        $a1
    ctx->r5 = lo;
    // 0x80800F1C: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80800F20: nop

    // 0x80800F24: multu       $t5, $v0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800F28: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80800F2C: mflo        $a2
    ctx->r6 = lo;
    // 0x80800F30: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80800F34: blezl       $t6, L_80801030
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80800F38: lbu         $t9, 0x52($s3)
        ctx->r25 = MEM_BU(ctx->r19, 0X52);
            goto L_80801030;
    }
    goto skip_8;
    // 0x80800F38: lbu         $t9, 0x52($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X52);
    skip_8:
    // 0x80800F3C: sw          $t3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r11;
    // 0x80800F40: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x80800F44: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x80800F48: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
L_80800F4C:
    // 0x80800F4C: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    // 0x80800F50: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80800F54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800F58: jal         0x800EE7F8
    // 0x80800F5C: addu        $a1, $t9, $v0
    ctx->r5 = ADD32(ctx->r25, ctx->r2);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800F5C: addu        $a1, $t9, $v0
    ctx->r5 = ADD32(ctx->r25, ctx->r2);
    after_2:
    // 0x80800F60: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80800F64: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80800F68: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x80800F6C: jal         0x800EE7F8
    // 0x80800F70: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800F70: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_3:
    // 0x80800F74: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80800F78: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x80800F7C: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x80800F80: jal         0x800EE7F8
    // 0x80800F84: addu        $a1, $t2, $t4
    ctx->r5 = ADD32(ctx->r10, ctx->r12);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x80800F84: addu        $a1, $t2, $t4
    ctx->r5 = ADD32(ctx->r10, ctx->r12);
    after_4:
    // 0x80800F88: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80800F8C: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80800F90: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
    // 0x80800F94: jal         0x800EE7F8
    // 0x80800F98: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x80800F98: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    after_5:
    // 0x80800F9C: bne         $s2, $zero, L_80800FC8
    if (ctx->r18 != 0) {
        // 0x80800FA0: lw          $t3, 0xDC($sp)
        ctx->r11 = MEM_W(ctx->r29, 0XDC);
            goto L_80800FC8;
    }
    // 0x80800FA0: lw          $t3, 0xDC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XDC);
    // 0x80800FA4: lh          $t7, 0x0($t3)
    ctx->r15 = MEM_H(ctx->r11, 0X0);
    // 0x80800FA8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800FAC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800FB0: beq         $t7, $at, L_80800FC8
    if (ctx->r15 == ctx->r1) {
        // 0x80800FB4: addiu       $a2, $sp, 0xB0
        ctx->r6 = ADD32(ctx->r29, 0XB0);
            goto L_80800FC8;
    }
    // 0x80800FB4: addiu       $a2, $sp, 0xB0
    ctx->r6 = ADD32(ctx->r29, 0XB0);
    // 0x80800FB8: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80800FBC: jal         0x808007D0
    // 0x80800FC0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    func_808007D0_susplinet(rdram, ctx);
        goto after_6;
    // 0x80800FC0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_6:
    // 0x80800FC4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_80800FC8:
    // 0x80800FC8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800FCC: jal         0x808000FC
    // 0x80800FD0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_808000FC_susplinet(rdram, ctx);
        goto after_7;
    // 0x80800FD0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_7:
    // 0x80800FD4: beq         $v0, $zero, L_80800FE4
    if (ctx->r2 == 0) {
        // 0x80800FD8: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_80800FE4;
    }
    // 0x80800FD8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80800FDC: jal         0x800F0EF0
    // 0x80800FE0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800F0EF0(rdram, ctx);
        goto after_8;
    // 0x80800FE0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_8:
L_80800FE4:
    // 0x80800FE4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80800FE8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800FEC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80800FF0: jal         0x800890F8
    // 0x80800FF4: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    _mlspline_entrypoint_4(rdram, ctx);
        goto after_9;
    // 0x80800FF4: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_9:
    // 0x80800FF8: bne         $s2, $zero, L_80801010
    if (ctx->r18 != 0) {
        // 0x80800FFC: addiu       $a1, $zero, 0x4
        ctx->r5 = ADD32(0, 0X4);
            goto L_80801010;
    }
    // 0x80800FFC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80801000: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80801004: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80801008: jal         0x80089118
    // 0x8080100C: addiu       $a3, $s4, 0x18
    ctx->r7 = ADD32(ctx->r20, 0X18);
    _mlspline_entrypoint_8(rdram, ctx);
        goto after_10;
    // 0x8080100C: addiu       $a3, $s4, 0x18
    ctx->r7 = ADD32(ctx->r20, 0X18);
    after_10:
L_80801010:
    // 0x80801010: lbu         $t8, 0x51($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X51);
    // 0x80801014: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80801018: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8080101C: slt         $at, $s2, $t8
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80801020: bne         $at, $zero, L_80800F4C
    if (ctx->r1 != 0) {
        // 0x80801024: addiu       $s4, $s4, 0xC
        ctx->r20 = ADD32(ctx->r20, 0XC);
            goto L_80800F4C;
    }
    // 0x80801024: addiu       $s4, $s4, 0xC
    ctx->r20 = ADD32(ctx->r20, 0XC);
    // 0x80801028: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8080102C: lbu         $t9, 0x52($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X52);
L_80801030:
    // 0x80801030: addiu       $s0, $sp, 0xBC
    ctx->r16 = ADD32(ctx->r29, 0XBC);
    // 0x80801034: addiu       $s1, $s3, 0x24
    ctx->r17 = ADD32(ctx->r19, 0X24);
    // 0x80801038: blez        $t9, L_808010C0
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8080103C: addiu       $s4, $sp, 0x9C
        ctx->r20 = ADD32(ctx->r29, 0X9C);
            goto L_808010C0;
    }
    // 0x8080103C: addiu       $s4, $sp, 0x9C
    ctx->r20 = ADD32(ctx->r29, 0X9C);
L_80801040:
    // 0x80801040: lh          $t0, 0xB0($sp)
    ctx->r8 = MEM_H(ctx->r29, 0XB0);
    // 0x80801044: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80801048: lh          $t4, 0xB2($sp)
    ctx->r12 = MEM_H(ctx->r29, 0XB2);
    // 0x8080104C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80801050: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x80801054: lwc1        $f10, 0x0($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80801058: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8080105C: lh          $t3, 0xB4($sp)
    ctx->r11 = MEM_H(ctx->r29, 0XB4);
    // 0x80801060: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x80801064: swc1        $f10, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f10.u32l;
    // 0x80801068: lwc1        $f16, 0x0($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8080106C: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x80801070: lh          $t9, 0xB6($sp)
    ctx->r25 = MEM_H(ctx->r29, 0XB6);
    // 0x80801074: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80801078: swc1        $f16, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f16.u32l;
    // 0x8080107C: lwc1        $f18, 0x0($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80801080: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80801084: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x80801088: swc1        $f18, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f18.u32l;
    // 0x8080108C: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80801090: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80801094: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80801098: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x8080109C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x808010A0: jal         0x80089120
    // 0x808010A4: swc1        $f4, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f4.u32l;
    _mlspline_entrypoint_9(rdram, ctx);
        goto after_11;
    // 0x808010A4: swc1        $f4, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f4.u32l;
    after_11:
    // 0x808010A8: lbu         $t2, 0x52($s3)
    ctx->r10 = MEM_BU(ctx->r19, 0X52);
    // 0x808010AC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x808010B0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x808010B4: slt         $at, $s2, $t2
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x808010B8: bne         $at, $zero, L_80801040
    if (ctx->r1 != 0) {
        // 0x808010BC: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80801040;
    }
    // 0x808010BC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_808010C0:
    // 0x808010C0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_808010C4:
    // 0x808010C4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808010C8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808010CC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808010D0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x808010D4: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x808010D8: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x808010DC: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x808010E0: jr          $ra
    // 0x808010E4: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    return;
    // 0x808010E4: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
;}
RECOMP_FUNC void func_80800C08_chbottlesfamily(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C10: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800C14: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800C18: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    // 0x80800C1C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800C20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800C24: andi        $t6, $v0, 0x1FF
    ctx->r14 = ctx->r2 & 0X1FF;
    // 0x80800C28: beq         $t6, $zero, L_80800C4C
    if (ctx->r14 == 0) {
        // 0x80800C2C: addiu       $a1, $zero, 0x18
        ctx->r5 = ADD32(0, 0X18);
            goto L_80800C4C;
    }
    // 0x80800C2C: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x80800C30: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800C34: beq         $t6, $at, L_80800C5C
    if (ctx->r14 == ctx->r1) {
        // 0x80800C38: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800C5C;
    }
    // 0x80800C38: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800C3C: beql        $t6, $at, L_80800C8C
    if (ctx->r14 == ctx->r1) {
        // 0x80800C40: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_80800C8C;
    }
    goto skip_0;
    // 0x80800C40: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800C44: b           L_80800C98
    // 0x80800C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800C98;
    // 0x80800C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C4C:
    // 0x80800C4C: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80800C50: jal         0x800856B0
    // 0x80800C54: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800C54: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800C58: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_80800C5C:
    // 0x80800C5C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800C60: jal         0x800856E0
    // 0x80800C64: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    _capod_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800C64: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x80800C68: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800C6C: lhu         $t7, 0x6E($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X6E);
    // 0x80800C70: andi        $t8, $t7, 0xFE00
    ctx->r24 = ctx->r15 & 0XFE00;
    // 0x80800C74: ori         $t9, $t8, 0x2
    ctx->r25 = ctx->r24 | 0X2;
    // 0x80800C78: jal         0x80800A84
    // 0x80800C7C: sh          $t9, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r25;
    func_80800A84_chbottlesfamily(rdram, ctx);
        goto after_2;
    // 0x80800C7C: sh          $t9, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r25;
    after_2:
    // 0x80800C80: jal         0x800880B8
    // 0x80800C84: nop

    _gcdialogcamera_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x80800C84: nop

    after_3:
    // 0x80800C88: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_80800C8C:
    // 0x80800C8C: jal         0x800856D8
    // 0x80800C90: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _capod_entrypoint_7(rdram, ctx);
        goto after_4;
    // 0x80800C90: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80800C94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C98:
    // 0x80800C98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C9C: jr          $ra
    // 0x80800CA0: nop

    return;
    // 0x80800CA0: nop

;}
RECOMP_FUNC void bsblongleg_entrypoint_31(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080144C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801450: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(104, 0X14E0) << 16);
    // 0x80801454: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801458: jr          $ra
    // 0x8080145C: lw          $v0, 0x14E0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(104, 0X14E0));
    return;
    // 0x8080145C: lw          $v0, 0x14E0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(104, 0X14E0));
;}
