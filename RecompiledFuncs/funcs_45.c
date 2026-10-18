#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void ncbakaztorp_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080000C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800014: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800018: lui         $a1, 0x44FA
    ctx->r5 = S32(0X44FA << 16);
    // 0x8080001C: lui         $a2, 0x457A
    ctx->r6 = S32(0X457A << 16);
    // 0x80800020: jal         0x801120CC
    // 0x80800024: lui         $a3, 0xC57A
    ctx->r7 = S32(0XC57A << 16);
    func_801120CC(rdram, ctx);
        goto after_0;
    // 0x80800024: lui         $a3, 0xC57A
    ctx->r7 = S32(0XC57A << 16);
    after_0:
    // 0x80800028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080002C: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    // 0x80800030: jal         0x80111B8C
    // 0x80800034: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    func_80111B8C(rdram, ctx);
        goto after_1;
    // 0x80800034: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    after_1:
    // 0x80800038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080003C: jal         0x801124D0
    // 0x80800040: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_801124D0(rdram, ctx);
        goto after_2;
    // 0x80800040: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800048: jal         0x80115858
    // 0x8080004C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80115858(rdram, ctx);
        goto after_3;
    // 0x8080004C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80800050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800054: jal         0x80115870
    // 0x80800058: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80115870(rdram, ctx);
        goto after_4;
    // 0x80800058: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x8080005C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800060: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800064: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800068: jr          $ra
    // 0x8080006C: nop

    return;
    // 0x8080006C: nop

;}
RECOMP_FUNC void func_808009B8_chfantasycannon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009B8: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x808009BC: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x808009C0: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x808009C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808009C8: sw          $s7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r23;
    // 0x808009CC: sw          $s6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r22;
    // 0x808009D0: sw          $s5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r21;
    // 0x808009D4: sw          $s4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r20;
    // 0x808009D8: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x808009DC: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x808009E0: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x808009E4: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x808009E8: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x808009EC: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x808009F0: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x808009F4: jal         0x80100094
    // 0x808009F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808009F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808009FC: addiu       $s7, $s0, 0x4
    ctx->r23 = ADD32(ctx->r16, 0X4);
    // 0x80800A00: addiu       $s5, $s0, 0x18
    ctx->r21 = ADD32(ctx->r16, 0X18);
    // 0x80800A04: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x80800A08: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80800A0C: jal         0x800F1DF4
    // 0x80800A10: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_800F1DF4(rdram, ctx);
        goto after_1;
    // 0x80800A10: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_1:
    // 0x80800A14: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800A18: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800A1C: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x80800A20: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80800A24: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80800A28: lw          $s3, 0x74($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X74);
    // 0x80800A2C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80800A30: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800A34: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800A38: addiu       $s0, $zero, 0x5
    ctx->r16 = ADD32(0, 0X5);
    // 0x80800A3C: addiu       $s4, $zero, 0x3C
    ctx->r20 = ADD32(0, 0X3C);
    // 0x80800A40: addiu       $s6, $sp, 0x7C
    ctx->r22 = ADD32(ctx->r29, 0X7C);
    // 0x80800A44: addiu       $s2, $sp, 0x88
    ctx->r18 = ADD32(ctx->r29, 0X88);
    // 0x80800A48: sub.s       $f20, $f0, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80800A4C: addiu       $s3, $s3, 0x18
    ctx->r19 = ADD32(ctx->r19, 0X18);
L_80800A50:
    // 0x80800A50: jal         0x800DC0C0
    // 0x80800A54: nop

    func_800DC0C0(rdram, ctx);
        goto after_2;
    // 0x80800A54: nop

    after_2:
    // 0x80800A58: mtc1        $s4, $f10
    ctx->f10.u32l = ctx->r20;
    // 0x80800A5C: mul.s       $f6, $f0, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x80800A60: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x80800A64: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800A68: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800A6C: add.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x80800A70: add.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x80800A74: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800A78: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80800A7C: jal         0x800EEC30
    // 0x80800A80: nop

    func_800EEC30(rdram, ctx);
        goto after_3;
    // 0x80800A80: nop

    after_3:
    // 0x80800A84: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800A88: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80800A8C: jal         0x800EE780
    // 0x80800A90: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_800EE780(rdram, ctx);
        goto after_4;
    // 0x80800A90: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_4:
    // 0x80800A94: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80800A98: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800A9C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80800AA0: jal         0x800BEF00
    // 0x80800AA4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800BEF00(rdram, ctx);
        goto after_5;
    // 0x80800AA4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x80800AA8: beq         $v0, $zero, L_80800B20
    if (ctx->r2 == 0) {
        // 0x80800AAC: negu        $at, $s0
        ctx->r1 = SUB32(0, ctx->r16);
            goto L_80800B20;
    }
    // 0x80800AAC: negu        $at, $s0
    ctx->r1 = SUB32(0, ctx->r16);
    // 0x80800AB0: sll         $s1, $at, 2
    ctx->r17 = S32(ctx->r1 << 2);
    // 0x80800AB4: subu        $s1, $s1, $at
    ctx->r17 = SUB32(ctx->r17, ctx->r1);
    // 0x80800AB8: jal         0x800DC0C0
    // 0x80800ABC: sll         $s1, $s1, 2
    ctx->r17 = S32(ctx->r17 << 2);
    func_800DC0C0(rdram, ctx);
        goto after_6;
    // 0x80800ABC: sll         $s1, $s1, 2
    ctx->r17 = S32(ctx->r17 << 2);
    after_6:
    // 0x80800AC0: mtc1        $s1, $f8
    ctx->f8.u32l = ctx->r17;
    // 0x80800AC4: mul.s       $f4, $f0, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x80800AC8: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x80800ACC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800AD0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800AD4: add.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f24.fl;
    // 0x80800AD8: add.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x80800ADC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800AE0: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80800AE4: jal         0x800EEC30
    // 0x80800AE8: nop

    func_800EEC30(rdram, ctx);
        goto after_7;
    // 0x80800AE8: nop

    after_7:
    // 0x80800AEC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800AF0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80800AF4: jal         0x800EE780
    // 0x80800AF8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_800EE780(rdram, ctx);
        goto after_8;
    // 0x80800AF8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_8:
    // 0x80800AFC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80800B00: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800B04: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80800B08: jal         0x800BEF00
    // 0x80800B0C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800BEF00(rdram, ctx);
        goto after_9;
    // 0x80800B0C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_9:
    // 0x80800B10: beq         $v0, $zero, L_80800B20
    if (ctx->r2 == 0) {
        // 0x80800B14: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80800B20;
    }
    // 0x80800B14: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800B18: bgez        $s0, L_80800A50
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80800B1C: addiu       $s4, $s4, 0xC
        ctx->r20 = ADD32(ctx->r20, 0XC);
            goto L_80800A50;
    }
    // 0x80800B1C: addiu       $s4, $s4, 0xC
    ctx->r20 = ADD32(ctx->r20, 0XC);
L_80800B20:
    // 0x80800B20: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x80800B24: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800B28: jal         0x800EE780
    // 0x80800B2C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    func_800EE780(rdram, ctx);
        goto after_10;
    // 0x80800B2C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_10:
    // 0x80800B30: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x80800B34: jal         0x800EF334
    // 0x80800B38: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_800EF334(rdram, ctx);
        goto after_11;
    // 0x80800B38: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_11:
    // 0x80800B3C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80800B40: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800B44: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80800B48: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80800B4C: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x80800B50: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x80800B54: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x80800B58: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x80800B5C: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x80800B60: lw          $s4, 0x44($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X44);
    // 0x80800B64: lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X48);
    // 0x80800B68: lw          $s6, 0x4C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X4C);
    // 0x80800B6C: lw          $s7, 0x50($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X50);
    // 0x80800B70: jr          $ra
    // 0x80800B74: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x80800B74: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_808001B8_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001B8: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x808001BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001C0: sltiu       $at, $t6, 0x6
    ctx->r1 = ctx->r14 < 0X6 ? 1 : 0;
    // 0x808001C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001C8: beq         $at, $zero, L_80800260
    if (ctx->r1 == 0) {
        // 0x808001CC: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_80800260;
    }
    // 0x808001CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808001D0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808001D4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1840, 0X4B18) << 16);
    // 0x808001D8: addu        $at, $at, $t6
    gpr jr_addend_808001E0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808001DC: lw          $t6, 0x4B18($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1840, 0X4B18));
    // 0x808001E0: jr          $t6
    // 0x808001E4: nop

    switch (jr_addend_808001E0 >> 2) {
        case 0: goto L_808001E8; break;
        case 1: goto L_80800230; break;
        case 2: goto L_8080021C; break;
        case 3: goto L_80800244; break;
        case 4: goto L_808001FC; break;
        case 5: goto L_808001E8; break;
        default: switch_error(__func__, 0x808001E0, 0x80804B18);
    }
    // 0x808001E4: nop

L_808001E8:
    // 0x808001E8: addiu       $a0, $zero, 0x1A1
    ctx->r4 = ADD32(0, 0X1A1);
    // 0x808001EC: jal         0x801084B0
    // 0x808001F0: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_801084B0(rdram, ctx);
        goto after_0;
    // 0x808001F0: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x808001F4: b           L_80800260
    // 0x808001F8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80800260;
    // 0x808001F8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_808001FC:
    // 0x808001FC: addiu       $a0, $zero, 0x1A1
    ctx->r4 = ADD32(0, 0X1A1);
    // 0x80800200: jal         0x801084B0
    // 0x80800204: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_801084B0(rdram, ctx);
        goto after_1;
    // 0x80800204: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_1:
    // 0x80800208: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8080020C: lbu         $t8, 0x65($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X65);
    // 0x80800210: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x80800214: b           L_80800260
    // 0x80800218: sb          $t9, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r25;
        goto L_80800260;
    // 0x80800218: sb          $t9, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r25;
L_8080021C:
    // 0x8080021C: addiu       $a0, $zero, 0x1A3
    ctx->r4 = ADD32(0, 0X1A3);
    // 0x80800220: jal         0x801084B0
    // 0x80800224: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_801084B0(rdram, ctx);
        goto after_2;
    // 0x80800224: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_2:
    // 0x80800228: b           L_80800260
    // 0x8080022C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80800260;
    // 0x8080022C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80800230:
    // 0x80800230: addiu       $a0, $zero, 0x1A2
    ctx->r4 = ADD32(0, 0X1A2);
    // 0x80800234: jal         0x801084B0
    // 0x80800238: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_801084B0(rdram, ctx);
        goto after_3;
    // 0x80800238: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_3:
    // 0x8080023C: b           L_80800260
    // 0x80800240: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_80800260;
    // 0x80800240: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80800244:
    // 0x80800244: addiu       $a0, $zero, 0x1A2
    ctx->r4 = ADD32(0, 0X1A2);
    // 0x80800248: jal         0x801084B0
    // 0x8080024C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_801084B0(rdram, ctx);
        goto after_4;
    // 0x8080024C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_4:
    // 0x80800250: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800254: lbu         $t1, 0x65($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X65);
    // 0x80800258: ori         $t2, $t1, 0x8
    ctx->r10 = ctx->r9 | 0X8;
    // 0x8080025C: sb          $t2, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r10;
L_80800260:
    // 0x80800260: lui         $at, 0xC3EB
    ctx->r1 = S32(0XC3EB << 16);
    // 0x80800264: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800268: lui         $at, 0x43EB
    ctx->r1 = S32(0X43EB << 16);
    // 0x8080026C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800270: jal         0x800DC178
    // 0x80800274: nop

    func_800DC178(rdram, ctx);
        goto after_5;
    // 0x80800274: nop

    after_5:
    // 0x80800278: lui         $at, 0xC3EB
    ctx->r1 = S32(0XC3EB << 16);
    // 0x8080027C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800280: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80800284: lui         $at, 0x43EB
    ctx->r1 = S32(0X43EB << 16);
    // 0x80800288: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080028C: jal         0x800DC178
    // 0x80800290: swc1        $f0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x80800290: swc1        $f0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f0.u32l;
    after_6:
    // 0x80800294: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80800298: swc1        $f0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f0.u32l;
    // 0x8080029C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x808002A0: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x808002A4: sw          $t5, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r13;
    // 0x808002A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002B0: jr          $ra
    // 0x808002B4: nop

    return;
    // 0x808002B4: nop

;}
RECOMP_FUNC void func_80802170_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802170: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802174: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802178: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080217C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80802180: jal         0x80100094
    // 0x80802184: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802184: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802188: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8080218C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80802190: addu        $t6, $v0, $a1
    ctx->r14 = ADD32(ctx->r2, ctx->r5);
    // 0x80802194: lbu         $t7, 0xFD($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XFD);
    // 0x80802198: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080219C: bne         $t7, $zero, L_808021D8
    if (ctx->r15 != 0) {
        // 0x808021A0: nop
    
            goto L_808021D8;
    }
    // 0x808021A0: nop

    // 0x808021A4: jal         0x80802158
    // 0x808021A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80802158_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x808021A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808021AC: beq         $v0, $zero, L_808021BC
    if (ctx->r2 == 0) {
        // 0x808021B0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808021BC;
    }
    // 0x808021B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808021B4: jal         0x800DA544
    // 0x808021B8: nop

    func_800DA544(rdram, ctx);
        goto after_2;
    // 0x808021B8: nop

    after_2:
L_808021BC:
    // 0x808021BC: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x808021C0: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x808021C4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808021C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808021CC: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x808021D0: b           L_808021D8
    // 0x808021D4: sb          $t8, 0xFD($t1)
    MEM_B(0XFD, ctx->r9) = ctx->r24;
        goto L_808021D8;
    // 0x808021D4: sb          $t8, 0xFD($t1)
    MEM_B(0XFD, ctx->r9) = ctx->r24;
L_808021D8:
    // 0x808021D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808021DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808021E0: jr          $ra
    // 0x808021E4: nop

    return;
    // 0x808021E4: nop

;}
RECOMP_FUNC void _suegg_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A3C8: syscall     841
    recomp_syscall_handler(rdram, ctx, 0x8008A3C8);
    return;
    // 0x8008A3CC: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_800CA934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA934: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x800CA938: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800CA93C: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800CA940: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800CA944: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800CA948: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x800CA94C: nop

    // 0x800CA950: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800CA954: nop

    // 0x800CA958: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800CA95C: div.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800CA960: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800CA964: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x800CA968: nop

    // 0x800CA96C: sh          $t9, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r25;
    // 0x800CA970: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800CA974: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800CA978: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800CA97C: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x800CA980: nop

    // 0x800CA984: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x800CA988: nop

    // 0x800CA98C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800CA990: div.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800CA994: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800CA998: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x800CA99C: nop

    // 0x800CA9A0: sh          $t3, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r11;
    // 0x800CA9A4: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800CA9A8: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800CA9AC: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800CA9B0: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x800CA9B4: nop

    // 0x800CA9B8: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x800CA9BC: nop

    // 0x800CA9C0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800CA9C4: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800CA9C8: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800CA9CC: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x800CA9D0: jr          $ra
    // 0x800CA9D4: sh          $t7, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r15;
    return;
    // 0x800CA9D4: sh          $t7, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r15;
;}
RECOMP_FUNC void func_800F8874(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F8874: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F8878: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F887C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F8880: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F8884: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F8888: jal         0x8009224C
    // 0x800F888C: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_8009224C(rdram, ctx);
        goto after_0;
    // 0x800F888C: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F8890: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F8894: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F8898: jr          $ra
    // 0x800F889C: nop

    return;
    // 0x800F889C: nop

;}
RECOMP_FUNC void func_8001E2C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E2C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001E2CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E2D0: jal         0x8001D96C
    // 0x8001E2D4: nop

    func_8001D96C(rdram, ctx);
        goto after_0;
    // 0x8001E2D4: nop

    after_0:
    // 0x8001E2D8: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8001E2DC: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8001E2E0: lw          $a1, -0x16B0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X16B0);
    // 0x8001E2E4: jal         0x8001D37C
    // 0x8001E2E8: addiu       $a0, $a0, 0x1840
    ctx->r4 = ADD32(ctx->r4, 0X1840);
    func_8001D37C(rdram, ctx);
        goto after_1;
    // 0x8001E2E8: addiu       $a0, $a0, 0x1840
    ctx->r4 = ADD32(ctx->r4, 0X1840);
    after_1:
    // 0x8001E2EC: jal         0x8001E2A0
    // 0x8001E2F0: nop

    func_8001E2A0(rdram, ctx);
        goto after_2;
    // 0x8001E2F0: nop

    after_2:
    // 0x8001E2F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001E2F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001E2FC: jr          $ra
    // 0x8001E300: nop

    return;
    // 0x8001E300: nop

;}
RECOMP_FUNC void chdiggerboss_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80808FA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80808FA8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80808FAC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80808FB0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80808FB4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80808FB8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80808FBC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80808FC0: jal         0x80106790
    // 0x80808FC4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80808FC4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80808FC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80808FCC: jal         0x80100094
    // 0x80808FD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80808FD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80808FD4: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80808FD8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80808FDC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80808FE0: beq         $v1, $at, L_80808FFC
    if (ctx->r3 == ctx->r1) {
        // 0x80808FE4: lw          $t6, 0x2C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X2C);
            goto L_80808FFC;
    }
    // 0x80808FE4: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80808FE8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80808FEC: beq         $v1, $at, L_80809034
    if (ctx->r3 == ctx->r1) {
        // 0x80808FF0: lw          $t0, 0x2C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X2C);
            goto L_80809034;
    }
    // 0x80808FF0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80808FF4: b           L_80809068
    // 0x80808FF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80809068;
    // 0x80808FF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80808FFC:
    // 0x80808FFC: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80809000: addu        $a0, $t7, $s0
    ctx->r4 = ADD32(ctx->r15, ctx->r16);
    // 0x80809004: sltu        $at, $s0, $a0
    ctx->r1 = ctx->r16 < ctx->r4 ? 1 : 0;
    // 0x80809008: beq         $at, $zero, L_80809064
    if (ctx->r1 == 0) {
        // 0x8080900C: lh          $v1, 0xD0($v0)
        ctx->r3 = MEM_H(ctx->r2, 0XD0);
            goto L_80809064;
    }
    // 0x8080900C: lh          $v1, 0xD0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XD0);
L_80809010:
    // 0x80809010: lh          $t8, 0xA($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XA);
    // 0x80809014: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80809018: sltu        $at, $s0, $a0
    ctx->r1 = ctx->r16 < ctx->r4 ? 1 : 0;
    // 0x8080901C: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x80809020: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x80809024: bne         $at, $zero, L_80809010
    if (ctx->r1 != 0) {
        // 0x80809028: sh          $t9, -0x6($a2)
        MEM_H(-0X6, ctx->r6) = ctx->r25;
            goto L_80809010;
    }
    // 0x80809028: sh          $t9, -0x6($a2)
    MEM_H(-0X6, ctx->r6) = ctx->r25;
    // 0x8080902C: b           L_80809068
    // 0x80809030: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80809068;
    // 0x80809030: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80809034:
    // 0x80809034: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x80809038: addu        $a0, $t1, $s0
    ctx->r4 = ADD32(ctx->r9, ctx->r16);
    // 0x8080903C: sltu        $at, $s0, $a0
    ctx->r1 = ctx->r16 < ctx->r4 ? 1 : 0;
    // 0x80809040: beq         $at, $zero, L_80809064
    if (ctx->r1 == 0) {
        // 0x80809044: lh          $v1, 0xD2($v0)
        ctx->r3 = MEM_H(ctx->r2, 0XD2);
            goto L_80809064;
    }
    // 0x80809044: lh          $v1, 0xD2($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XD2);
L_80809048:
    // 0x80809048: lh          $t2, 0xA($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XA);
    // 0x8080904C: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80809050: sltu        $at, $s0, $a0
    ctx->r1 = ctx->r16 < ctx->r4 ? 1 : 0;
    // 0x80809054: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x80809058: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8080905C: bne         $at, $zero, L_80809048
    if (ctx->r1 != 0) {
        // 0x80809060: sh          $t3, -0x6($a2)
        MEM_H(-0X6, ctx->r6) = ctx->r11;
            goto L_80809048;
    }
    // 0x80809060: sh          $t3, -0x6($a2)
    MEM_H(-0X6, ctx->r6) = ctx->r11;
L_80809064:
    // 0x80809064: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80809068:
    // 0x80809068: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080906C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80809070: jr          $ra
    // 0x80809074: nop

    return;
    // 0x80809074: nop

;}
RECOMP_FUNC void func_800E42B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E42B4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E42B8: jr          $ra
    // 0x800E42BC: sw          $a0, -0x2B00($at)
    MEM_W(-0X2B00, ctx->r1) = ctx->r4;
    return;
    // 0x800E42BC: sw          $a0, -0x2B00($at)
    MEM_W(-0X2B00, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void _chbaddiesetup_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086D28: syscall     449
    recomp_syscall_handler(rdram, ctx, 0x80086D28);
    return;
    // 0x80086D2C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8011447C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011447C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80114480: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80114484: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80114488: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8011448C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80114490: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80114494: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80114498: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x8011449C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x801144A0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801144A4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801144A8: jal         0x800F5898
    // 0x801144AC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    func_800F5898(rdram, ctx);
        goto after_0;
    // 0x801144AC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_0:
    // 0x801144B0: blez        $v0, L_80114564
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801144B4: addiu       $s1, $sp, 0x4C
        ctx->r17 = ADD32(ctx->r29, 0X4C);
            goto L_80114564;
    }
    // 0x801144B4: addiu       $s1, $sp, 0x4C
    ctx->r17 = ADD32(ctx->r29, 0X4C);
L_801144B8:
    // 0x801144B8: jal         0x800F6BE4
    // 0x801144BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6BE4(rdram, ctx);
        goto after_1;
    // 0x801144BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801144C0: beq         $v0, $zero, L_80114550
    if (ctx->r2 == 0) {
        // 0x801144C4: nop
    
            goto L_80114550;
    }
    // 0x801144C4: nop

    // 0x801144C8: jal         0x800F6BE4
    // 0x801144CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6BE4(rdram, ctx);
        goto after_2;
    // 0x801144CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801144D0: beq         $v0, $zero, L_80114550
    if (ctx->r2 == 0) {
        // 0x801144D4: nop
    
            goto L_80114550;
    }
    // 0x801144D4: nop

    // 0x801144D8: jal         0x800F6438
    // 0x801144DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6438(rdram, ctx);
        goto after_3;
    // 0x801144DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801144E0: beq         $v0, $zero, L_80114550
    if (ctx->r2 == 0) {
        // 0x801144E4: nop
    
            goto L_80114550;
    }
    // 0x801144E4: nop

    // 0x801144E8: jal         0x800F6640
    // 0x801144EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6640(rdram, ctx);
        goto after_4;
    // 0x801144EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801144F0: beq         $v0, $zero, L_80114550
    if (ctx->r2 == 0) {
        // 0x801144F4: nop
    
            goto L_80114550;
    }
    // 0x801144F4: nop

    // 0x801144F8: jal         0x800F6690
    // 0x801144FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6690(rdram, ctx);
        goto after_5;
    // 0x801144FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80114500: beq         $v0, $zero, L_80114550
    if (ctx->r2 == 0) {
        // 0x80114504: nop
    
            goto L_80114550;
    }
    // 0x80114504: nop

    // 0x80114508: jal         0x800F5EF8
    // 0x8011450C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F5EF8(rdram, ctx);
        goto after_6;
    // 0x8011450C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80114510: jal         0x80110014
    // 0x80114514: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110014(rdram, ctx);
        goto after_7;
    // 0x80114514: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x80114518: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8011451C: jal         0x80112550
    // 0x80114520: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80112550(rdram, ctx);
        goto after_8;
    // 0x80114520: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_8:
    // 0x80114524: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80114528: jal         0x80114444
    // 0x8011452C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80114444(rdram, ctx);
        goto after_9;
    // 0x8011452C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80114530: mul.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80114534: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80114538: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8011453C: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x80114540: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80114544: jal         0x801143A4
    // 0x80114548: nop

    func_801143A4(rdram, ctx);
        goto after_10;
    // 0x80114548: nop

    after_10:
    // 0x8011454C: or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
L_80114550:
    // 0x80114550: jal         0x800F5898
    // 0x80114554: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    func_800F5898(rdram, ctx);
        goto after_11;
    // 0x80114554: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_11:
    // 0x80114558: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8011455C: bne         $at, $zero, L_801144B8
    if (ctx->r1 != 0) {
        // 0x80114560: nop
    
            goto L_801144B8;
    }
    // 0x80114560: nop

L_80114564:
    // 0x80114564: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80114568: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x8011456C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80114570: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80114574: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80114578: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8011457C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80114580: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80114584: jr          $ra
    // 0x80114588: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80114588: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80801844_gcnewpause(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801844: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801848: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8080184C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80801850: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80801854: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801858: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8080185C: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x80801860: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801864: bne         $t6, $at, L_808018A8
    if (ctx->r14 != ctx->r1) {
        // 0x80801868: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_808018A8;
    }
    // 0x80801868: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080186C: beq         $a1, $zero, L_80801898
    if (ctx->r5 == 0) {
        // 0x80801870: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801898;
    }
    // 0x80801870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801874: jal         0x800FA9B4
    // 0x80801878: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800FA9B4(rdram, ctx);
        goto after_0;
    // 0x80801878: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x8080187C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801880: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80801884: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80801888: jal         0x800FA708
    // 0x8080188C: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    func_800FA708(rdram, ctx);
        goto after_1;
    // 0x8080188C: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x80801890: b           L_808018F8
    // 0x80801894: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808018F8;
    // 0x80801894: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801898:
    // 0x80801898: jal         0x800FAAB4
    // 0x8080189C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800FAAB4(rdram, ctx);
        goto after_2;
    // 0x8080189C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x808018A0: b           L_808018F8
    // 0x808018A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808018F8;
    // 0x808018A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808018A8:
    // 0x808018A8: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x808018AC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808018B0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808018B4: bne         $t7, $at, L_808018DC
    if (ctx->r15 != ctx->r1) {
        // 0x808018B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808018DC;
    }
    // 0x808018B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808018BC: jal         0x800FAAB4
    // 0x808018C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FAAB4(rdram, ctx);
        goto after_3;
    // 0x808018C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808018C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808018C8: jal         0x800FA934
    // 0x808018CC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800FA934(rdram, ctx);
        goto after_4;
    // 0x808018CC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x808018D0: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x808018D4: b           L_808018F8
    // 0x808018D8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_808018F8;
    // 0x808018D8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_808018DC:
    // 0x808018DC: jal         0x800FA818
    // 0x808018E0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800FA818(rdram, ctx);
        goto after_5;
    // 0x808018E0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x808018E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808018E8: jal         0x800FA8E8
    // 0x808018EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800FA8E8(rdram, ctx);
        goto after_6;
    // 0x808018EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x808018F0: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x808018F4: sltiu       $v0, $t9, 0x1
    ctx->r2 = ctx->r25 < 0X1 ? 1 : 0;
L_808018F8:
    // 0x808018F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808018FC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801900: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801904: jr          $ra
    // 0x80801908: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80801908: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80801690_chpiranha(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801690: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801694: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801698: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1804, 0X1B10) << 16);
    // 0x8080169C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808016A0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808016A4: addiu       $t6, $t6, 0x1B10
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1804, 0X1B10));
    // 0x808016A8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x808016AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808016B0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808016B4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808016B8: jal         0x800BBCB8
    // 0x808016BC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x808016BC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x808016C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808016C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808016C8: jr          $ra
    // 0x808016CC: nop

    return;
    // 0x808016CC: nop

;}
RECOMP_FUNC void func_80800070_chdiggerground(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800070: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800074: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800078: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x8080007C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800080: srl         $t7, $t6, 21
    ctx->r15 = S32(U32(ctx->r14) >> 21);
    // 0x80800084: beq         $t7, $zero, L_808000AC
    if (ctx->r15 == 0) {
        // 0x80800088: nop
    
            goto L_808000AC;
    }
    // 0x80800088: nop

    // 0x8080008C: jal         0x80101FDC
    // 0x80800090: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80101FDC(rdram, ctx);
        goto after_0;
    // 0x80800090: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800094: jal         0x808000C4
    // 0x80800098: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808000C4_chdiggerground(rdram, ctx);
        goto after_1;
    // 0x80800098: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080009C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000A0: lbu         $t9, 0x65($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X65);
    // 0x808000A4: ori         $t0, $t9, 0x10
    ctx->r8 = ctx->r25 | 0X10;
    // 0x808000A8: sb          $t0, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r8;
L_808000AC:
    // 0x808000AC: jal         0x8010A3E8
    // 0x808000B0: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    func_8010A3E8(rdram, ctx);
        goto after_2;
    // 0x808000B0: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    after_2:
    // 0x808000B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000BC: jr          $ra
    // 0x808000C0: nop

    return;
    // 0x808000C0: nop

;}
RECOMP_FUNC void _glcutDll_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088818: syscall     705
    recomp_syscall_handler(rdram, ctx, 0x80088818);
    return;
    // 0x8008881C: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void func_80101F24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101F24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80101F28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80101F2C: jal         0x80104248
    // 0x80101F30: nop

    func_80104248(rdram, ctx);
        goto after_0;
    // 0x80101F30: nop

    after_0:
    // 0x80101F34: beq         $v0, $zero, L_80101F4C
    if (ctx->r2 == 0) {
        // 0x80101F38: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80101F4C;
    }
    // 0x80101F38: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80101F3C: jal         0x8008B2B4
    // 0x80101F40: nop

    anctrl_getAnimTimer(rdram, ctx);
        goto after_1;
    // 0x80101F40: nop

    after_1:
    // 0x80101F44: b           L_80101F58
    // 0x80101F48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80101F58;
    // 0x80101F48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80101F4C:
    // 0x80101F4C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80101F50: nop

    // 0x80101F54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80101F58:
    // 0x80101F58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80101F5C: jr          $ra
    // 0x80101F60: nop

    return;
    // 0x80101F60: nop

;}
RECOMP_FUNC void func_800E2E48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E2E48: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800E2E4C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800E2E50: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800E2E54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800E2E58: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800E2E5C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800E2E60: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800E2E64: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x800E2E68: jal         0x800E42F0
    // 0x800E2E6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800E42F0(rdram, ctx);
        goto after_0;
    // 0x800E2E6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800E2E70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E2E74: jal         0x800E1DF4
    // 0x800E2E78: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800E1DF4(rdram, ctx);
        goto after_1;
    // 0x800E2E78: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x800E2E7C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800E2E80: addiu       $v1, $v1, -0x2B90
    ctx->r3 = ADD32(ctx->r3, -0X2B90);
    // 0x800E2E84: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x800E2E88: beql        $v0, $zero, L_800E2E9C
    if (ctx->r2 == 0) {
        // 0x800E2E8C: lh          $t6, 0x8($s0)
        ctx->r14 = MEM_H(ctx->r16, 0X8);
            goto L_800E2E9C;
    }
    goto skip_0;
    // 0x800E2E8C: lh          $t6, 0x8($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X8);
    skip_0:
    // 0x800E2E90: b           L_800E2EA4
    // 0x800E2E94: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
        goto L_800E2EA4;
    // 0x800E2E94: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800E2E98: lh          $t6, 0x8($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X8);
L_800E2E9C:
    // 0x800E2E9C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800E2EA0: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
L_800E2EA4:
    // 0x800E2EA4: lh          $v0, 0x2($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2);
    // 0x800E2EA8: beql        $v0, $zero, L_800E2EBC
    if (ctx->r2 == 0) {
        // 0x800E2EAC: lh          $t8, 0xA($s0)
        ctx->r24 = MEM_H(ctx->r16, 0XA);
            goto L_800E2EBC;
    }
    goto skip_1;
    // 0x800E2EAC: lh          $t8, 0xA($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XA);
    skip_1:
    // 0x800E2EB0: b           L_800E2EC4
    // 0x800E2EB4: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
        goto L_800E2EC4;
    // 0x800E2EB4: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x800E2EB8: lh          $t8, 0xA($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XA);
L_800E2EBC:
    // 0x800E2EBC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800E2EC0: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
L_800E2EC4:
    // 0x800E2EC4: jal         0x800E2DF0
    // 0x800E2EC8: nop

    func_800E2DF0(rdram, ctx);
        goto after_2;
    // 0x800E2EC8: nop

    after_2:
    // 0x800E2ECC: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800E2ED0: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x800E2ED4: lh          $t1, 0x8($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X8);
    // 0x800E2ED8: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800E2EDC: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800E2EE0: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x800E2EE4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800E2EE8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E2EEC: addiu       $v0, $v0, -0x2B90
    ctx->r2 = ADD32(ctx->r2, -0X2B90);
    // 0x800E2EF0: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x800E2EF4: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x800E2EF8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800E2EFC: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800E2F00: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x800E2F04: addiu       $t7, $zero, 0x1C8
    ctx->r15 = ADD32(0, 0X1C8);
    // 0x800E2F08: lw          $a3, 0x34($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X34);
    // 0x800E2F0C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x800E2F10: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800E2F14: div.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800E2F18: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800E2F1C: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    // 0x800E2F20: lh          $t3, 0xA($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XA);
    // 0x800E2F24: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x800E2F28: nop

    // 0x800E2F2C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800E2F30: div.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    // 0x800E2F34: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x800E2F38: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x800E2F3C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800E2F40: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x800E2F44: addiu       $t5, $t4, -0x260
    ctx->r13 = ADD32(ctx->r12, -0X260);
    // 0x800E2F48: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800E2F4C: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800E2F50: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800E2F54: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800E2F58: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800E2F5C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800E2F60: jal         0x800EFA4C
    // 0x800E2F64: nop

    func_800EFA4C(rdram, ctx);
        goto after_3;
    // 0x800E2F64: nop

    after_3:
    // 0x800E2F68: jal         0x80019CD4
    // 0x800E2F6C: nop

    func_80019CD4(rdram, ctx);
        goto after_4;
    // 0x800E2F6C: nop

    after_4:
    // 0x800E2F70: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800E2F74: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800E2F78: jal         0x800191F8
    // 0x800E2F7C: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    func_800191F8(rdram, ctx);
        goto after_5;
    // 0x800E2F7C: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    after_5:
    // 0x800E2F80: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E2F84: lwc1        $f12, -0x2B68($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2B68);
    // 0x800E2F88: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800E2F8C: nop

    // 0x800E2F90: c.eq.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl == ctx->f12.fl;
    // 0x800E2F94: nop

    // 0x800E2F98: bc1tl       L_800E2FAC
    if (c1cs) {
        // 0x800E2F9C: lh          $v0, 0x4($s0)
        ctx->r2 = MEM_H(ctx->r16, 0X4);
            goto L_800E2FAC;
    }
    goto skip_2;
    // 0x800E2F9C: lh          $v0, 0x4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4);
    skip_2:
    // 0x800E2FA0: jal         0x8001907C
    // 0x800E2FA4: nop

    mlMtxRotRoll(rdram, ctx);
        goto after_6;
    // 0x800E2FA4: nop

    after_6:
    // 0x800E2FA8: lh          $v0, 0x4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4);
L_800E2FAC:
    // 0x800E2FAC: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x800E2FB0: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x800E2FB4: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800E2FB8: bnel        $t9, $v0, L_800E3004
    if (ctx->r25 != ctx->r2) {
        // 0x800E2FBC: lh          $t2, 0x8($s0)
        ctx->r10 = MEM_H(ctx->r16, 0X8);
            goto L_800E3004;
    }
    goto skip_3;
    // 0x800E2FBC: lh          $t2, 0x8($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X8);
    skip_3:
    // 0x800E2FC0: lh          $t1, 0x6($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X6);
    // 0x800E2FC4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800E2FC8: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800E2FCC: bnel        $t0, $t1, L_800E3004
    if (ctx->r8 != ctx->r9) {
        // 0x800E2FD0: lh          $t2, 0x8($s0)
        ctx->r10 = MEM_H(ctx->r16, 0X8);
            goto L_800E3004;
    }
    goto skip_4;
    // 0x800E2FD0: lh          $t2, 0x8($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X8);
    skip_4:
    // 0x800E2FD4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800E2FD8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E2FDC: c.eq.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl == ctx->f0.fl;
    // 0x800E2FE0: nop

    // 0x800E2FE4: bc1fl       L_800E3004
    if (!c1cs) {
        // 0x800E2FE8: lh          $t2, 0x8($s0)
        ctx->r10 = MEM_H(ctx->r16, 0X8);
            goto L_800E3004;
    }
    goto skip_5;
    // 0x800E2FE8: lh          $t2, 0x8($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X8);
    skip_5:
    // 0x800E2FEC: lwc1        $f18, -0x2B60($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2B60);
    // 0x800E2FF0: c.eq.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl == ctx->f18.fl;
    // 0x800E2FF4: nop

    // 0x800E2FF8: bc1t        L_800E3054
    if (c1cs) {
        // 0x800E2FFC: nop
    
            goto L_800E3054;
    }
    // 0x800E2FFC: nop

    // 0x800E3000: lh          $t2, 0x8($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X8);
L_800E3004:
    // 0x800E3004: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x800E3008: lh          $t3, 0xA($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XA);
    // 0x800E300C: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800E3010: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800E3014: lh          $t4, 0x6($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X6);
    // 0x800E3018: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800E301C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800E3020: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800E3024: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800E3028: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800E302C: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800E3030: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800E3034: nop

    // 0x800E3038: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800E303C: div.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800E3040: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x800E3044: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800E3048: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800E304C: jal         0x80019D30
    // 0x800E3050: div.s       $f14, $f8, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    mlMtxScale_xyz(rdram, ctx);
        goto after_7;
    // 0x800E3050: div.s       $f14, $f8, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    after_7:
L_800E3054:
    // 0x800E3054: jal         0x80018C28
    // 0x800E3058: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    mlMtxApply(rdram, ctx);
        goto after_8;
    // 0x800E3058: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    after_8:
    // 0x800E305C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800E3060: lui         $t7, 0xDA38
    ctx->r15 = S32(0XDA38 << 16);
    // 0x800E3064: ori         $t7, $t7, 0x2
    ctx->r15 = ctx->r15 | 0X2;
    // 0x800E3068: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x800E306C: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x800E3070: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800E3074: lw          $t6, 0x4($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X4);
    // 0x800E3078: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E307C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800E3080: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800E3084: lw          $t8, 0x4($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X4);
    // 0x800E3088: addiu       $t9, $t8, 0x40
    ctx->r25 = ADD32(ctx->r24, 0X40);
    // 0x800E308C: sw          $t9, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r25;
    // 0x800E3090: jal         0x800E2180
    // 0x800E3094: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    func_800E2180(rdram, ctx);
        goto after_9;
    // 0x800E3094: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    after_9:
    // 0x800E3098: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800E309C: lui         $t1, 0xD838
    ctx->r9 = S32(0XD838 << 16);
    // 0x800E30A0: ori         $t1, $t1, 0x2
    ctx->r9 = ctx->r9 | 0X2;
    // 0x800E30A4: addiu       $t0, $v1, 0x8
    ctx->r8 = ADD32(ctx->r3, 0X8);
    // 0x800E30A8: sw          $t0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r8;
    // 0x800E30AC: addiu       $t2, $zero, 0x40
    ctx->r10 = ADD32(0, 0X40);
    // 0x800E30B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E30B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800E30B8: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x800E30BC: jal         0x800E22F0
    // 0x800E30C0: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    func_800E22F0(rdram, ctx);
        goto after_10;
    // 0x800E30C0: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    after_10:
    // 0x800E30C4: jal         0x800E4640
    // 0x800E30C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800E4640(rdram, ctx);
        goto after_11;
    // 0x800E30C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x800E30CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800E30D0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800E30D4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800E30D8: jr          $ra
    // 0x800E30DC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800E30DC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8008C1DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C1DC: jr          $ra
    // 0x8008C1E0: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    return;
    // 0x8008C1E0: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void _subaddiedialog_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A230: syscall     830
    recomp_syscall_handler(rdram, ctx, 0x8008A230);
    return;
    // 0x8008A234: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void func_80802390_chfactorymagnet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802390: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80802394: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80802398: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080239C: lhu         $a3, 0x72($a0)
    ctx->r7 = MEM_HU(ctx->r4, 0X72);
    // 0x808023A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808023A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808023A8: srl         $t6, $a3, 10
    ctx->r14 = S32(U32(ctx->r7) >> 10);
    // 0x808023AC: beq         $t6, $at, L_808023C4
    if (ctx->r14 == ctx->r1) {
        // 0x808023B0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808023C4;
    }
    // 0x808023B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808023B4: beq         $t6, $at, L_808024E8
    if (ctx->r14 == ctx->r1) {
        // 0x808023B8: nop
    
            goto L_808024E8;
    }
    // 0x808023B8: nop

    // 0x808023BC: b           L_808025A4
    // 0x808023C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808025A4;
    // 0x808023C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808023C4:
    // 0x808023C4: jal         0x800D90A4
    // 0x808023C8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_0;
    // 0x808023C8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_0:
    // 0x808023CC: beq         $v0, $zero, L_808025A0
    if (ctx->r2 == 0) {
        // 0x808023D0: addiu       $a0, $zero, 0x3F5
        ctx->r4 = ADD32(0, 0X3F5);
            goto L_808025A0;
    }
    // 0x808023D0: addiu       $a0, $zero, 0x3F5
    ctx->r4 = ADD32(0, 0X3F5);
    // 0x808023D4: jal         0x80089C30
    // 0x808023D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x808023D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808023DC: lhu         $t7, 0x72($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X72);
    // 0x808023E0: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x808023E4: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x808023E8: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x808023EC: bne         $t8, $at, L_808024C4
    if (ctx->r24 != ctx->r1) {
        // 0x808023F0: addiu       $a1, $s0, 0x18
        ctx->r5 = ADD32(ctx->r16, 0X18);
            goto L_808024C4;
    }
    // 0x808023F0: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x808023F4: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2284, 0X2AFC) << 16);
    // 0x808023F8: addiu       $t9, $t9, 0x2AFC
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(2284, 0X2AFC));
    // 0x808023FC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80802400: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80802404: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x80802408: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x8080240C: jal         0x800BBCB8
    // 0x80802410: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_800BBCB8(rdram, ctx);
        goto after_2;
    // 0x80802410: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_2:
    // 0x80802414: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2284, 0X2AFC) << 16);
    // 0x80802418: addiu       $t0, $t0, 0x2AFC
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(2284, 0X2AFC));
    // 0x8080241C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80802420: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80802424: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80802428: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080242C: jal         0x800BBCB8
    // 0x80802430: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    func_800BBCB8(rdram, ctx);
        goto after_3;
    // 0x80802430: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_3:
    // 0x80802434: jal         0x800C8A98
    // 0x80802438: nop

    func_800C8A98(rdram, ctx);
        goto after_4;
    // 0x80802438: nop

    after_4:
    // 0x8080243C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2284, 0X2B50) << 16);
    // 0x80802440: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x80802444: addiu       $a1, $a1, 0x2B50
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2284, 0X2B50));
    // 0x80802448: jal         0x800C8D4C
    // 0x8080244C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800C8D4C(rdram, ctx);
        goto after_5;
    // 0x8080244C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x80802450: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x80802454: jal         0x800C8FE0
    // 0x80802458: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C8FE0(rdram, ctx);
        goto after_6;
    // 0x80802458: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x8080245C: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x80802460: jal         0x800C8F64
    // 0x80802464: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_800C8F64(rdram, ctx);
        goto after_7;
    // 0x80802464: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_7:
    // 0x80802468: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x8080246C: jal         0x800C8CB8
    // 0x80802470: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C8CB8(rdram, ctx);
        goto after_8;
    // 0x80802470: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_8:
    // 0x80802474: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x80802478: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x8080247C: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    // 0x80802480: jal         0x800C8FB0
    // 0x80802484: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800C8FB0(rdram, ctx);
        goto after_9;
    // 0x80802484: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_9:
    // 0x80802488: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080248C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80802490: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x80802494: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80802498: jal         0x800DC178
    // 0x8080249C: nop

    func_800DC178(rdram, ctx);
        goto after_10;
    // 0x8080249C: nop

    after_10:
    // 0x808024A0: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x808024A4: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x808024A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808024AC: jal         0x80101FDC
    // 0x808024B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_11;
    // 0x808024B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_11:
    // 0x808024B4: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    // 0x808024B8: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x808024BC: b           L_808025A0
    // 0x808024C0: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
        goto L_808025A0;
    // 0x808024C0: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
L_808024C4:
    // 0x808024C4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808024C8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808024CC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x808024D0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808024D4: jal         0x800DC178
    // 0x808024D8: nop

    func_800DC178(rdram, ctx);
        goto after_12;
    // 0x808024D8: nop

    after_12:
    // 0x808024DC: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x808024E0: b           L_808025A0
    // 0x808024E4: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
        goto L_808025A0;
    // 0x808024E4: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_808024E8:
    // 0x808024E8: jal         0x800D90A4
    // 0x808024EC: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_13;
    // 0x808024EC: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_13:
    // 0x808024F0: beq         $v0, $zero, L_80802548
    if (ctx->r2 == 0) {
        // 0x808024F4: nop
    
            goto L_80802548;
    }
    // 0x808024F4: nop

    // 0x808024F8: jal         0x80089D40
    // 0x808024FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_14;
    // 0x808024FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80802500: jal         0x800C8B84
    // 0x80802504: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    func_800C8B84(rdram, ctx);
        goto after_15;
    // 0x80802504: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    after_15:
    // 0x80802508: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    // 0x8080250C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802510: jal         0x80101FDC
    // 0x80802514: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_16;
    // 0x80802514: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x80802518: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8080251C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80802520: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80802524: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80802528: jal         0x800DC178
    // 0x8080252C: nop

    func_800DC178(rdram, ctx);
        goto after_17;
    // 0x8080252C: nop

    after_17:
    // 0x80802530: lbu         $t4, 0x65($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X65);
    // 0x80802534: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x80802538: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x8080253C: andi        $t5, $t4, 0xFFFE
    ctx->r13 = ctx->r12 & 0XFFFE;
    // 0x80802540: b           L_808025A0
    // 0x80802544: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
        goto L_808025A0;
    // 0x80802544: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
L_80802548:
    // 0x80802548: jal         0x8001210C
    // 0x8080254C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001210C(rdram, ctx);
        goto after_18;
    // 0x8080254C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_18:
    // 0x80802550: beq         $v0, $zero, L_80802560
    if (ctx->r2 == 0) {
        // 0x80802554: addiu       $a1, $zero, 0xA0
        ctx->r5 = ADD32(0, 0XA0);
            goto L_80802560;
    }
    // 0x80802554: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80802558: b           L_80802560
    // 0x8080255C: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
        goto L_80802560;
    // 0x8080255C: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
L_80802560:
    // 0x80802560: beq         $v0, $zero, L_80802570
    if (ctx->r2 == 0) {
        // 0x80802564: addiu       $a2, $zero, 0xA0
        ctx->r6 = ADD32(0, 0XA0);
            goto L_80802570;
    }
    // 0x80802564: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // 0x80802568: b           L_80802570
    // 0x8080256C: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
        goto L_80802570;
    // 0x8080256C: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
L_80802570:
    // 0x80802570: beq         $v0, $zero, L_80802580
    if (ctx->r2 == 0) {
        // 0x80802574: addiu       $a3, $zero, 0xC8
        ctx->r7 = ADD32(0, 0XC8);
            goto L_80802580;
    }
    // 0x80802574: addiu       $a3, $zero, 0xC8
    ctx->r7 = ADD32(0, 0XC8);
    // 0x80802578: b           L_80802580
    // 0x8080257C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
        goto L_80802580;
    // 0x8080257C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
L_80802580:
    // 0x80802580: jal         0x800C8FB0
    // 0x80802584: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    func_800C8FB0(rdram, ctx);
        goto after_19;
    // 0x80802584: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    after_19:
    // 0x80802588: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2284, 0X2B58) << 16);
    // 0x8080258C: addiu       $a3, $a3, 0x2B58
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2284, 0X2B58));
    // 0x80802590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802594: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80802598: jal         0x80089D50
    // 0x8080259C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_20;
    // 0x8080259C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_20:
L_808025A0:
    // 0x808025A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808025A4:
    // 0x808025A4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808025A8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808025AC: jr          $ra
    // 0x808025B0: nop

    return;
    // 0x808025B0: nop

;}
RECOMP_FUNC void func_800F0064(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0064: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F0068: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F006C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800F0070: jal         0x800EFC7C
    // 0x800F0074: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800EFC7C(rdram, ctx);
        goto after_0;
    // 0x800F0074: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x800F0078: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800F007C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F0080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F0084: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800F0088: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800F008C: nop

    // 0x800F0090: bc1f        L_800F009C
    if (!c1cs) {
        // 0x800F0094: nop
    
            goto L_800F009C;
    }
    // 0x800F0094: nop

    // 0x800F0098: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F009C:
    // 0x800F009C: jr          $ra
    // 0x800F00A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800F00A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _babounce_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084608: syscall     116
    recomp_syscall_handler(rdram, ctx, 0x80084608);
    return;
    // 0x8008460C: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_800D7520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D7520: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D7524: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D7528: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D752C: bne         $a0, $at, L_800D753C
    if (ctx->r4 != ctx->r1) {
        // 0x800D7530: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_800D753C;
    }
    // 0x800D7530: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800D7534: b           L_800D7560
    // 0x800D7538: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D7560;
    // 0x800D7538: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D753C:
    // 0x800D753C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800D7540: lh          $a0, -0x400C($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X400C);
    // 0x800D7544: jal         0x8001B798
    // 0x800D7548: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_8001B798(rdram, ctx);
        goto after_0;
    // 0x800D7548: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x800D754C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800D7550: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x800D7554: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800D7558: jal         0x8001B798
    // 0x800D755C: lh          $a0, 0x0($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X0);
    func_8001B798(rdram, ctx);
        goto after_1;
    // 0x800D755C: lh          $a0, 0x0($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X0);
    after_1:
L_800D7560:
    // 0x800D7560: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D7564: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D7568: jr          $ra
    // 0x800D756C: nop

    return;
    // 0x800D756C: nop

;}
RECOMP_FUNC void func_80097530(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097530: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80097534: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80097538: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009753C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80097540: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x80097544: jal         0x80095870
    // 0x80097548: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    func_80095870(rdram, ctx);
        goto after_0;
    // 0x80097548: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    after_0:
    // 0x8009754C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80097550: lw          $a1, 0x98($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X98);
    // 0x80097554: jal         0x800EFA20
    // 0x80097558: lui         $a2, 0x41C8
    ctx->r6 = S32(0X41C8 << 16);
    func_800EFA20(rdram, ctx);
        goto after_1;
    // 0x80097558: lui         $a2, 0x41C8
    ctx->r6 = S32(0X41C8 << 16);
    after_1:
    // 0x8009755C: lw          $a1, 0x98($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X98);
    // 0x80097560: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80097564: jal         0x800EF04C
    // 0x80097568: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_800EF04C(rdram, ctx);
        goto after_2;
    // 0x80097568: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_2:
    // 0x8009756C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80097570: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80097574: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80097578: addiu       $s0, $sp, 0x44
    ctx->r16 = ADD32(ctx->r29, 0X44);
    // 0x8009757C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80097580: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80097584: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80097588: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8009758C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80097590: jal         0x800EFA4C
    // 0x80097594: nop

    func_800EFA4C(rdram, ctx);
        goto after_3;
    // 0x80097594: nop

    after_3:
    // 0x80097598: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8009759C: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800975A0: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800975A4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800975A8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800975AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800975B0: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x800975B4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800975B8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800975BC: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x800975C0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800975C4: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800975C8: jal         0x800EFA4C
    // 0x800975CC: nop

    func_800EFA4C(rdram, ctx);
        goto after_4;
    // 0x800975CC: nop

    after_4:
    // 0x800975D0: lui         $a3, 0x42
    ctx->r7 = S32(0X42 << 16);
    // 0x800975D4: ori         $a3, $a3, 0x25
    ctx->r7 = ctx->r7 | 0X25;
    // 0x800975D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800975DC: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800975E0: jal         0x800C6A7C
    // 0x800975E4: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_800C6A7C(rdram, ctx);
        goto after_5;
    // 0x800975E4: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_5:
    // 0x800975E8: beq         $v0, $zero, L_800975F8
    if (ctx->r2 == 0) {
        // 0x800975EC: lwc1        $f16, 0x30($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
            goto L_800975F8;
    }
    // 0x800975EC: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800975F0: b           L_800976C8
    // 0x800975F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800976C8;
    // 0x800975F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800975F8:
    // 0x800975F8: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800975FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80097600: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80097604: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80097608: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8009760C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80097610: jal         0x800EFA4C
    // 0x80097614: nop

    func_800EFA4C(rdram, ctx);
        goto after_6;
    // 0x80097614: nop

    after_6:
    // 0x80097618: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8009761C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80097620: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80097624: lui         $a3, 0x42
    ctx->r7 = S32(0X42 << 16);
    // 0x80097628: ori         $a3, $a3, 0x25
    ctx->r7 = ctx->r7 | 0X25;
    // 0x8009762C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80097630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80097634: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x80097638: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8009763C: jal         0x800C6C94
    // 0x80097640: nop

    func_800C6C94(rdram, ctx);
        goto after_7;
    // 0x80097640: nop

    after_7:
    // 0x80097644: beq         $v0, $zero, L_80097654
    if (ctx->r2 == 0) {
        // 0x80097648: lwc1        $f6, 0x54($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
            goto L_80097654;
    }
    // 0x80097648: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8009764C: b           L_800976C8
    // 0x80097650: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800976C8;
    // 0x80097650: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80097654:
    // 0x80097654: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80097658: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009765C: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80097660: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80097664: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80097668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009766C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80097670: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80097674: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80097678: sub.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8009767C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80097680: jal         0x800EFA4C
    // 0x80097684: nop

    func_800EFA4C(rdram, ctx);
        goto after_8;
    // 0x80097684: nop

    after_8:
    // 0x80097688: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8009768C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80097690: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80097694: lui         $a3, 0x42
    ctx->r7 = S32(0X42 << 16);
    // 0x80097698: ori         $a3, $a3, 0x25
    ctx->r7 = ctx->r7 | 0X25;
    // 0x8009769C: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800976A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800976A4: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x800976A8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800976AC: jal         0x800C6C94
    // 0x800976B0: nop

    func_800C6C94(rdram, ctx);
        goto after_9;
    // 0x800976B0: nop

    after_9:
    // 0x800976B4: beql        $v0, $zero, L_800976C8
    if (ctx->r2 == 0) {
        // 0x800976B8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800976C8;
    }
    goto skip_0;
    // 0x800976B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x800976BC: b           L_800976C8
    // 0x800976C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800976C8;
    // 0x800976C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800976C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800976C8:
    // 0x800976C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800976CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800976D0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800976D4: jr          $ra
    // 0x800976D8: nop

    return;
    // 0x800976D8: nop

;}
RECOMP_FUNC void func_80800298_bsbbilldrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800298: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080029C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002A0: jal         0x800841D8
    // 0x808002A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bswalk_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808002A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808002A8: jal         0x8009BB00
    // 0x808002AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_1;
    // 0x808002AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808002B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(61, 0XA6C) << 16);
    // 0x808002B4: lwc1        $f4, 0xA6C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(61, 0XA6C));
    // 0x808002B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808002BC: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808002C0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808002C4: jal         0x8009B9B0
    // 0x808002C8: nop

    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x808002C8: nop

    after_2:
    // 0x808002CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002D4: jr          $ra
    // 0x808002D8: nop

    return;
    // 0x808002D8: nop

;}
RECOMP_FUNC void func_80800238_chhumba(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800238: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080023C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800240: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800244: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800248: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080024C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800250: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800254: lwc1        $f4, 0x38($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X38);
    // 0x80800258: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x8080025C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800260: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800264: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800268: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8080026C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800270: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800274: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800278: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8080027C: jal         0x800EFA4C
    // 0x80800280: nop

    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x80800280: nop

    after_0:
    // 0x80800284: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800288: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080028C: jr          $ra
    // 0x80800290: nop

    return;
    // 0x80800290: nop

;}
RECOMP_FUNC void gcmapsects_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801D10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801D14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801D18: jal         0x80801640
    // 0x80801D1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80801640_gcmapsects(rdram, ctx);
        goto after_0;
    // 0x80801D1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801D20: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80801D24: lbu         $v0, 0x7B($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X7B);
    // 0x80801D28: lbu         $t6, 0x7A($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X7A);
    // 0x80801D2C: beql        $t6, $v0, L_80801D64
    if (ctx->r14 == ctx->r2) {
        // 0x80801D30: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80801D64;
    }
    goto skip_0;
    // 0x80801D30: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    skip_0:
    // 0x80801D34: beq         $v0, $zero, L_80801D4C
    if (ctx->r2 == 0) {
        // 0x80801D38: nop
    
            goto L_80801D4C;
    }
    // 0x80801D38: nop

    // 0x80801D3C: jal         0x800BFF4C
    // 0x80801D40: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800BFF4C(rdram, ctx);
        goto after_1;
    // 0x80801D40: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x80801D44: b           L_80801D58
    // 0x80801D48: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
        goto L_80801D58;
    // 0x80801D48: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_80801D4C:
    // 0x80801D4C: jal         0x800BFF28
    // 0x80801D50: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800BFF28(rdram, ctx);
        goto after_2;
    // 0x80801D50: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_2:
    // 0x80801D54: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_80801D58:
    // 0x80801D58: lbu         $t7, 0x7B($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X7B);
    // 0x80801D5C: sb          $t7, 0x7A($a2)
    MEM_B(0X7A, ctx->r6) = ctx->r15;
    // 0x80801D60: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80801D64:
    // 0x80801D64: jal         0x800BF4DC
    // 0x80801D68: lbu         $a1, 0x7E($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X7E);
    func_800BF4DC(rdram, ctx);
        goto after_3;
    // 0x80801D68: lbu         $a1, 0x7E($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X7E);
    after_3:
    // 0x80801D6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801D70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801D74: jr          $ra
    // 0x80801D78: nop

    return;
    // 0x80801D78: nop

;}
RECOMP_FUNC void func_808012A0_ncpoddialog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808012A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808012A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808012AC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808012B0: jal         0x800F690C
    // 0x808012B4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800F690C(rdram, ctx);
        goto after_0;
    // 0x808012B4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x808012B8: bnel        $v0, $zero, L_808012D4
    if (ctx->r2 != 0) {
        // 0x808012BC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808012D4;
    }
    goto skip_0;
    // 0x808012BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x808012C0: jal         0x800F693C
    // 0x808012C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800F693C(rdram, ctx);
        goto after_1;
    // 0x808012C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808012C8: beq         $v0, $zero, L_808012E8
    if (ctx->r2 == 0) {
        // 0x808012CC: nop
    
            goto L_808012E8;
    }
    // 0x808012CC: nop

    // 0x808012D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_808012D4:
    // 0x808012D4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808012D8: jal         0x80087928
    // 0x808012DC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _plcamera_entrypoint_14(rdram, ctx);
        goto after_2;
    // 0x808012DC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808012E0: b           L_80801304
    // 0x808012E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801304;
    // 0x808012E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808012E8:
    // 0x808012E8: jal         0x800F5EF8
    // 0x808012EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800F5EF8(rdram, ctx);
        goto after_3;
    // 0x808012EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x808012F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808012F4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808012F8: jal         0x8010FFB0
    // 0x808012FC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    func_8010FFB0(rdram, ctx);
        goto after_4;
    // 0x808012FC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80801300: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801304:
    // 0x80801304: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801308: jr          $ra
    // 0x8080130C: nop

    return;
    // 0x8080130C: nop

;}
RECOMP_FUNC void func_808001D8_bswalk(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001D8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808001DC: jr          $ra
    // 0x808001E0: swc1        $f12, 0x16C($a0)
    MEM_W(0X16C, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x808001E0: swc1        $f12, 0x16C($a0)
    MEM_W(0X16C, ctx->r4) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_80801654_chfantasyathlete(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801654: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80801658: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8080165C: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x80801660: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80801664: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x80801668: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8080166C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80801670: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80801674: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80801678: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8080167C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801680: addiu       $a0, $zero, 0x479
    ctx->r4 = ADD32(0, 0X479);
    // 0x80801684: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x80801688: jal         0x800882C0
    // 0x8080168C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    _gccubesearch_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x8080168C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_0:
    // 0x80801690: blez        $v0, L_808016F0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80801694: addiu       $s0, $sp, 0x60
        ctx->r16 = ADD32(ctx->r29, 0X60);
            goto L_808016F0;
    }
    // 0x80801694: addiu       $s0, $sp, 0x60
    ctx->r16 = ADD32(ctx->r29, 0X60);
    // 0x80801698: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8080169C: addu        $s5, $t7, $s0
    ctx->r21 = ADD32(ctx->r15, ctx->r16);
    // 0x808016A0: addiu       $s3, $sp, 0x4C
    ctx->r19 = ADD32(ctx->r29, 0X4C);
L_808016A4:
    // 0x808016A4: jal         0x80088BE8
    // 0x808016A8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _gspropctrl_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x808016A8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x808016AC: addiu       $s2, $v0, -0x32
    ctx->r18 = ADD32(ctx->r2, -0X32);
    // 0x808016B0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808016B4: jal         0x80088C00
    // 0x808016B8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x808016B8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_2:
    // 0x808016BC: jal         0x80088C08
    // 0x808016C0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _gspropctrl_entrypoint_12(rdram, ctx);
        goto after_3;
    // 0x808016C0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x808016C4: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x808016C8: sll         $t8, $s2, 2
    ctx->r24 = S32(ctx->r18 << 2);
    // 0x808016CC: addu        $s1, $s6, $t8
    ctx->r17 = ADD32(ctx->r22, ctx->r24);
    // 0x808016D0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808016D4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808016D8: jal         0x80088498
    // 0x808016DC: swc1        $f6, 0x94($s1)
    MEM_W(0X94, ctx->r17) = ctx->f6.u32l;
    _glsplinefind_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x808016DC: swc1        $f6, 0x94($s1)
    MEM_W(0X94, ctx->r17) = ctx->f6.u32l;
    after_4:
    // 0x808016E0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x808016E4: sltu        $at, $s0, $s5
    ctx->r1 = ctx->r16 < ctx->r21 ? 1 : 0;
    // 0x808016E8: bne         $at, $zero, L_808016A4
    if (ctx->r1 != 0) {
        // 0x808016EC: sw          $v0, 0x78($s1)
        MEM_W(0X78, ctx->r17) = ctx->r2;
            goto L_808016A4;
    }
    // 0x808016EC: sw          $v0, 0x78($s1)
    MEM_W(0X78, ctx->r17) = ctx->r2;
L_808016F0:
    // 0x808016F0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x808016F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808016F8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808016FC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80801700: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80801704: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80801708: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8080170C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80801710: jr          $ra
    // 0x80801714: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80801714: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_800A26B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A26B8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800A26BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A26C0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800A26C4: jal         0x8009C128
    // 0x800A26C8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x800A26C8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x800A26CC: jal         0x800964DC
    // 0x800A26D0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_800964DC(rdram, ctx);
        goto after_1;
    // 0x800A26D0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x800A26D4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800A26D8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x800A26DC: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x800A26E0: jal         0x80095870
    // 0x800A26E4: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    func_80095870(rdram, ctx);
        goto after_2;
    // 0x800A26E4: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x800A26E8: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800A26EC: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800A26F0: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800A26F4: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800A26F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800A26FC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800A2700: sub.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x800A2704: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x800A2708: nop

    // 0x800A270C: bc1tl       L_800A2750
    if (c1cs) {
        // 0x800A2710: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A2750;
    }
    goto skip_0;
    // 0x800A2710: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800A2714: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x800A2718: jal         0x8009FC34
    // 0x800A271C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_8009FC34(rdram, ctx);
        goto after_3;
    // 0x800A271C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_3:
    // 0x800A2720: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x800A2724: jal         0x80088AE8
    // 0x800A2728: lui         $a1, 0x41C8
    ctx->r5 = S32(0X41C8 << 16);
    _fxsplash_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x800A2728: lui         $a1, 0x41C8
    ctx->r5 = S32(0X41C8 << 16);
    after_4:
    // 0x800A272C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A2730: addiu       $t6, $t6, -0x6CE0
    ctx->r14 = ADD32(ctx->r14, -0X6CE0);
    // 0x800A2734: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800A2738: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A273C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A2740: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800A2744: jal         0x800BABB8
    // 0x800A2748: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_5;
    // 0x800A2748: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_5:
    // 0x800A274C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A2750:
    // 0x800A2750: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800A2754: jr          $ra
    // 0x800A2758: nop

    return;
    // 0x800A2758: nop

;}
RECOMP_FUNC void _suchase_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089F00: syscall     814
    recomp_syscall_handler(rdram, ctx, 0x80089F00);
    return;
    // 0x80089F04: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _bsblongleg_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082A68: syscall     24
    recomp_syscall_handler(rdram, ctx, 0x80082A68);
    return;
    // 0x80082A6C: addi        $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
;}
RECOMP_FUNC void func_808013C4_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808013C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808013CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808013D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808013D4: jal         0x80085298
    // 0x808013D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _baswim_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x808013D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808013DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013E0: jal         0x800910BC
    // 0x808013E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800910BC(rdram, ctx);
        goto after_1;
    // 0x808013E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808013E8: jal         0x800A4E30
    // 0x808013EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4E30(rdram, ctx);
        goto after_2;
    // 0x808013EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808013F0: jal         0x8008E95C
    // 0x808013F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E95C(rdram, ctx);
        goto after_3;
    // 0x808013F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808013F8: jal         0x80800104
    // 0x808013FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800104_bsbswim(rdram, ctx);
        goto after_4;
    // 0x808013FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801400: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801404: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801408: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080140C: jr          $ra
    // 0x80801410: nop

    return;
    // 0x80801410: nop

;}
RECOMP_FUNC void func_808018BC_sucoasterfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808018BC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808018C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808018C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808018C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808018CC: jal         0x80100094
    // 0x808018D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808018D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808018D4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808018D8: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x808018DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808018E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808018E4: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x808018E8: bgez        $t8, L_80801900
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808018EC: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80801900;
    }
    // 0x808018EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808018F0: jal         0x80089BF0
    // 0x808018F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _subaddiejoy_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x808018F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x808018F8: b           L_80801908
    // 0x808018FC: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
        goto L_80801908;
    // 0x808018FC: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
L_80801900:
    // 0x80801900: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801904: nop

L_80801908:
    // 0x80801908: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8080190C: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80801910: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80801914: lwc1        $f0, 0xC($t9)
    ctx->f0.u32l = MEM_W(ctx->r25, 0XC);
    // 0x80801918: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8080191C: nop

    // 0x80801920: bc1fl       L_80801944
    if (!c1cs) {
        // 0x80801924: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80801944;
    }
    goto skip_0;
    // 0x80801924: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_0:
    // 0x80801928: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080192C: jal         0x800F0E00
    // 0x80801930: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    func_800F0E00(rdram, ctx);
        goto after_2;
    // 0x80801930: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x80801934: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80801938: b           L_80801944
    // 0x8080193C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_80801944;
    // 0x8080193C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80801940: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80801944:
    // 0x80801944: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3210, 0X226C) << 16);
    // 0x80801948: lwc1        $f4, 0x226C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3210, 0X226C));
    // 0x8080194C: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x80801950: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80801954: jal         0x80107C00
    // 0x80801958: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    func_80107C00(rdram, ctx);
        goto after_3;
    // 0x80801958: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x8080195C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80801960: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80801964: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80801968: lwc1        $f8, 0xC($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XC);
    // 0x8080196C: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80801970: mul.s       $f14, $f8, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80801974: nop

    // 0x80801978: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8080197C: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80801980: jal         0x800F15F8
    // 0x80801984: nop

    func_800F15F8(rdram, ctx);
        goto after_4;
    // 0x80801984: nop

    after_4:
    // 0x80801988: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x8080198C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801990: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801994: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80801998: jr          $ra
    // 0x8080199C: nop

    return;
    // 0x8080199C: nop

;}
RECOMP_FUNC void capod_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    if (tooie_test_room_quiet()) { ctx->r2 = 0; return; }
    // 0x808004E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004F0: jal         0x8008FFE8
    // 0x808004F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8008FFE8(rdram, ctx);
        goto after_0;
    // 0x808004F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808004F8: beq         $v0, $zero, L_80800508
    if (ctx->r2 == 0) {
        // 0x808004FC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800508;
    }
    // 0x808004FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800500: jal         0x800895B8
    // 0x80800504: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    _ncpod_entrypoint_31(rdram, ctx);
        goto after_1;
    // 0x80800504: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
L_80800508:
    // 0x80800508: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080050C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800510: jr          $ra
    // 0x80800514: nop

    return;
    // 0x80800514: nop

;}
RECOMP_FUNC void func_800A33CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A33CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A33D0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800A33D4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800A33D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A33DC: lw          $a1, 0xA0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XA0);
    // 0x800A33E0: jal         0x800EE7F8
    // 0x800A33E4: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800A33E4: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    after_0:
    // 0x800A33E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A33EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A33F0: jr          $ra
    // 0x800A33F4: nop

    return;
    // 0x800A33F4: nop

;}
RECOMP_FUNC void func_800B0D6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B0D6C: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x800B0D70: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x800B0D74: jr          $ra
    // 0x800B0D78: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    return;
    // 0x800B0D78: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800B0D7C: nop

;}
RECOMP_FUNC void func_800C3AE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3AE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C3AE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C3AE8: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800C3AEC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800C3AF0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800C3AF4: beq         $t6, $zero, L_800C3B7C
    if (ctx->r14 == 0) {
        // 0x800C3AF8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800C3B7C;
    }
    // 0x800C3AF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C3AFC: jal         0x800C1414
    // 0x800C3B00: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_800C1414(rdram, ctx);
        goto after_0;
    // 0x800C3B00: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x800C3B04: lw          $t7, 0x78($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X78);
    // 0x800C3B08: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800C3B0C: sll         $t9, $t7, 28
    ctx->r25 = S32(ctx->r15 << 28);
    // 0x800C3B10: bgezl       $t9, L_800C3B5C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800C3B14: lh          $t6, 0x5A($v0)
        ctx->r14 = MEM_H(ctx->r2, 0X5A);
            goto L_800C3B5C;
    }
    goto skip_0;
    // 0x800C3B14: lh          $t6, 0x5A($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X5A);
    skip_0:
    // 0x800C3B18: lh          $t0, 0x4C($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X4C);
    // 0x800C3B1C: lh          $t3, 0x4E($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X4E);
    // 0x800C3B20: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800C3B24: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x800C3B28: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C3B2C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800C3B30: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800C3B34: nop

    // 0x800C3B38: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800C3B3C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800C3B40: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800C3B44: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x800C3B48: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x800C3B4C: sh          $t2, 0x4C($v0)
    MEM_H(0X4C, ctx->r2) = ctx->r10;
    // 0x800C3B50: b           L_800C3B7C
    // 0x800C3B54: sh          $t5, 0x4E($v0)
    MEM_H(0X4E, ctx->r2) = ctx->r13;
        goto L_800C3B7C;
    // 0x800C3B54: sh          $t5, 0x4E($v0)
    MEM_H(0X4E, ctx->r2) = ctx->r13;
    // 0x800C3B58: lh          $t6, 0x5A($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X5A);
L_800C3B5C:
    // 0x800C3B5C: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800C3B60: nop

    // 0x800C3B64: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C3B68: mul.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800C3B6C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800C3B70: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x800C3B74: nop

    // 0x800C3B78: sh          $t8, 0x5A($v0)
    MEM_H(0X5A, ctx->r2) = ctx->r24;
L_800C3B7C:
    // 0x800C3B7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C3B80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C3B84: jr          $ra
    // 0x800C3B88: nop

    return;
    // 0x800C3B88: nop

;}
RECOMP_FUNC void func_80800AF0_chboggyfatboy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800AF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800AF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800AFC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800B00: jal         0x800DA298
    // 0x80800B04: addiu       $a0, $zero, 0xBB
    ctx->r4 = ADD32(0, 0XBB);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800B04: addiu       $a0, $zero, 0xBB
    ctx->r4 = ADD32(0, 0XBB);
    after_0:
    // 0x80800B08: beq         $v0, $zero, L_80800B28
    if (ctx->r2 == 0) {
        // 0x80800B0C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800B28;
    }
    // 0x80800B0C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800B10: jal         0x8008A508
    // 0x80800B14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddietaxi_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800B14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800B18: beq         $v0, $zero, L_80800B28
    if (ctx->r2 == 0) {
        // 0x80800B1C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800B28;
    }
    // 0x80800B1C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800B20: jal         0x80102424
    // 0x80800B24: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x80800B24: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_2:
L_80800B28:
    // 0x80800B28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B30: jr          $ra
    // 0x80800B34: nop

    return;
    // 0x80800B34: nop

;}
RECOMP_FUNC void _sufreezy_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089B80: syscall     804
    recomp_syscall_handler(rdram, ctx, 0x80089B80);
    return;
    // 0x80089B84: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void bamotor_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000B4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808000B8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808000BC: jal         0x800918F8
    // 0x808000C0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    bakey_getControllerIndex(rdram, ctx);
        goto after_0;
    // 0x808000C0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_0:
    // 0x808000C4: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808000C8: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808000CC: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x808000D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000D4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808000D8: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x808000DC: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x808000E0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x808000E4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x808000E8: jal         0x80018854
    // 0x808000EC: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    func_80018854(rdram, ctx);
        goto after_1;
    // 0x808000EC: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x808000F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808000F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000F8: jr          $ra
    // 0x808000FC: nop

    return;
    // 0x808000FC: nop

;}
RECOMP_FUNC void subaddiemulti_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000EC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808000F0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808000F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000F8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808000FC: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
L_80800100:
    // 0x80800100: jal         0x800F6438
    // 0x80800104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6438(rdram, ctx);
        goto after_0;
    // 0x80800104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800108: beq         $v0, $zero, L_80800118
    if (ctx->r2 == 0) {
        // 0x8080010C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800118;
    }
    // 0x8080010C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800110: jal         0x800F82D4
    // 0x80800114: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_1;
    // 0x80800114: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
L_80800118:
    // 0x80800118: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8080011C: bne         $s0, $s1, L_80800100
    if (ctx->r16 != ctx->r17) {
        // 0x80800120: nop
    
            goto L_80800100;
    }
    // 0x80800120: nop

    // 0x80800124: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800128: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080012C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800130: jr          $ra
    // 0x80800134: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800134: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800EB5E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EB5E0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800EB5E4: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800EB5E8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800EB5EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800EB5F0: addiu       $s4, $sp, 0x40
    ctx->r20 = ADD32(ctx->r29, 0X40);
    // 0x800EB5F4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800EB5F8: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800EB5FC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800EB600: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800EB604: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800EB608: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800EB60C: jal         0x800E3A30
    // 0x800EB610: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800E3A30(rdram, ctx);
        goto after_0;
    // 0x800EB610: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_0:
    // 0x800EB614: jal         0x800E9E88
    // 0x800EB618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E9E88(rdram, ctx);
        goto after_1;
    // 0x800EB618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800EB61C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800EB620: jal         0x800E9EB4
    // 0x800EB624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E9EB4(rdram, ctx);
        goto after_2;
    // 0x800EB624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800EB628: sltu        $at, $s2, $v0
    ctx->r1 = ctx->r18 < ctx->r2 ? 1 : 0;
    // 0x800EB62C: beq         $at, $zero, L_800EB6E8
    if (ctx->r1 == 0) {
        // 0x800EB630: or          $s5, $v0, $zero
        ctx->r21 = ctx->r2 | 0;
            goto L_800EB6E8;
    }
    // 0x800EB630: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x800EB634: addiu       $s3, $zero, 0x7
    ctx->r19 = ADD32(0, 0X7);
    // 0x800EB638: lw          $v0, 0x8($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X8);
L_800EB63C:
    // 0x800EB63C: sll         $t7, $v0, 27
    ctx->r15 = S32(ctx->r2 << 27);
    // 0x800EB640: bgez        $t7, L_800EB6D8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800EB644: sll         $t9, $v0, 30
        ctx->r25 = S32(ctx->r2 << 30);
            goto L_800EB6D8;
    }
    // 0x800EB644: sll         $t9, $v0, 30
    ctx->r25 = S32(ctx->r2 << 30);
    // 0x800EB648: bltzl       $t9, L_800EB660
    if (SIGNED(ctx->r25) < 0) {
        // 0x800EB64C: andi        $t0, $v0, 0x1
        ctx->r8 = ctx->r2 & 0X1;
            goto L_800EB660;
    }
    goto skip_0;
    // 0x800EB64C: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    skip_0:
    // 0x800EB650: jal         0x80088C28
    // 0x800EB654: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    _gspropprop_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x800EB654: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x800EB658: lw          $v0, 0x8($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X8);
    // 0x800EB65C: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
L_800EB660:
    // 0x800EB660: beq         $t0, $zero, L_800EB6BC
    if (ctx->r8 == 0) {
        // 0x800EB664: sll         $t8, $v0, 28
        ctx->r24 = S32(ctx->r2 << 28);
            goto L_800EB6BC;
    }
    // 0x800EB664: sll         $t8, $v0, 28
    ctx->r24 = S32(ctx->r2 << 28);
    // 0x800EB668: lw          $s1, 0x0($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X0);
    // 0x800EB66C: jal         0x800EC800
    // 0x800EB670: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800EC800(rdram, ctx);
        goto after_4;
    // 0x800EB670: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x800EB674: beq         $v0, $zero, L_800EB6D8
    if (ctx->r2 == 0) {
        // 0x800EB678: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800EB6D8;
    }
    // 0x800EB678: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800EB67C: lw          $t1, 0x28($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X28);
L_800EB680:
    // 0x800EB680: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800EB684: sllv        $t5, $t4, $s0
    ctx->r13 = S32(ctx->r12 << (ctx->r16 & 31));
    // 0x800EB688: sll         $t2, $t1, 23
    ctx->r10 = S32(ctx->r9 << 23);
    // 0x800EB68C: srl         $t3, $t2, 24
    ctx->r11 = S32(U32(ctx->r10) >> 24);
    // 0x800EB690: and         $t6, $t3, $t5
    ctx->r14 = ctx->r11 & ctx->r13;
    // 0x800EB694: beq         $t6, $zero, L_800EB6A8
    if (ctx->r14 == 0) {
        // 0x800EB698: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800EB6A8;
    }
    // 0x800EB698: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800EB69C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800EB6A0: jal         0x800EB3D0
    // 0x800EB6A4: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_800EB3D0(rdram, ctx);
        goto after_5;
    // 0x800EB6A4: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_5:
L_800EB6A8:
    // 0x800EB6A8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800EB6AC: bnel        $s0, $s3, L_800EB680
    if (ctx->r16 != ctx->r19) {
        // 0x800EB6B0: lw          $t1, 0x28($s1)
        ctx->r9 = MEM_W(ctx->r17, 0X28);
            goto L_800EB680;
    }
    goto skip_1;
    // 0x800EB6B0: lw          $t1, 0x28($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X28);
    skip_1:
    // 0x800EB6B4: b           L_800EB6DC
    // 0x800EB6B8: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
        goto L_800EB6DC;
    // 0x800EB6B8: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
L_800EB6BC:
    // 0x800EB6BC: bgez        $t8, L_800EB6CC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800EB6C0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800EB6CC;
    }
    // 0x800EB6C0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800EB6C4: b           L_800EB6D0
    // 0x800EB6C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_800EB6D0;
    // 0x800EB6C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_800EB6CC:
    // 0x800EB6CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800EB6D0:
    // 0x800EB6D0: jal         0x800EB3D0
    // 0x800EB6D4: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_800EB3D0(rdram, ctx);
        goto after_6;
    // 0x800EB6D4: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_6:
L_800EB6D8:
    // 0x800EB6D8: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
L_800EB6DC:
    // 0x800EB6DC: sltu        $at, $s2, $s5
    ctx->r1 = ctx->r18 < ctx->r21 ? 1 : 0;
    // 0x800EB6E0: bnel        $at, $zero, L_800EB63C
    if (ctx->r1 != 0) {
        // 0x800EB6E4: lw          $v0, 0x8($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X8);
            goto L_800EB63C;
    }
    goto skip_2;
    // 0x800EB6E4: lw          $v0, 0x8($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X8);
    skip_2:
L_800EB6E8:
    // 0x800EB6E8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800EB6EC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800EB6F0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800EB6F4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800EB6F8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800EB6FC: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800EB700: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800EB704: jr          $ra
    // 0x800EB708: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800EB708: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80800054_chtntdetonator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800054: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800058: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080005C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800060: jal         0x80800588
    // 0x80800064: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800588_chtntdetonator(rdram, ctx);
        goto after_0;
    // 0x80800064: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800068: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x8080006C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800070: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800074: beq         $t6, $at, L_8080008C
    if (ctx->r14 == ctx->r1) {
        // 0x80800078: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080008C;
    }
    // 0x80800078: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080007C: beq         $t6, $at, L_8080009C
    if (ctx->r14 == ctx->r1) {
        // 0x80800080: nop
    
            goto L_8080009C;
    }
    // 0x80800080: nop

    // 0x80800084: b           L_80800138
    // 0x80800088: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800138;
    // 0x80800088: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080008C:
    // 0x8080008C: jal         0x8080021C
    // 0x80800090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080021C_chtntdetonator(rdram, ctx);
        goto after_1;
    // 0x80800090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800094: b           L_80800138
    // 0x80800098: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800138;
    // 0x80800098: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080009C:
    // 0x8080009C: jal         0x800D8FF8
    // 0x808000A0: nop

    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x808000A0: nop

    after_2:
    // 0x808000A4: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x808000A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808000AC: lwc1        $f4, 0x50($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X50);
    // 0x808000B0: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x808000B4: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808000B8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808000BC: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x808000C0: swc1        $f10, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f10.u32l;
    // 0x808000C4: lwc1        $f16, 0x50($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X50);
    // 0x808000C8: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x808000CC: nop

    // 0x808000D0: bc1f        L_808000E4
    if (!c1cs) {
        // 0x808000D4: nop
    
            goto L_808000E4;
    }
    // 0x808000D4: nop

    // 0x808000D8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808000DC: nop

    // 0x808000E0: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
L_808000E4:
    // 0x808000E4: jal         0x80101DDC
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_3;
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808000EC: beql        $v0, $zero, L_80800138
    if (ctx->r2 == 0) {
        // 0x808000F0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800138;
    }
    goto skip_0;
    // 0x808000F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808000F4: jal         0x808002D8
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002D8_chtntdetonator(rdram, ctx);
        goto after_4;
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808000FC: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80800100: beql        $a0, $zero, L_8080011C
    if (ctx->r4 == 0) {
        // 0x80800104: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8080011C;
    }
    goto skip_1;
    // 0x80800104: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_1:
    // 0x80800108: jal         0x80106790
    // 0x8080010C: nop

    func_80106790(rdram, ctx);
        goto after_5;
    // 0x8080010C: nop

    after_5:
    // 0x80800110: b           L_8080011C
    // 0x80800114: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_8080011C;
    // 0x80800114: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800118: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8080011C:
    // 0x8080011C: beq         $a0, $zero, L_8080012C
    if (ctx->r4 == 0) {
        // 0x80800120: addiu       $a1, $zero, 0x5
        ctx->r5 = ADD32(0, 0X5);
            goto L_8080012C;
    }
    // 0x80800120: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800124: jal         0x8010108C
    // 0x80800128: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_6;
    // 0x80800128: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
L_8080012C:
    // 0x8080012C: jal         0x800FFAB0
    // 0x80800130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_7;
    // 0x80800130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800134: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800138:
    // 0x80800138: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080013C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800140: jr          $ra
    // 0x80800144: nop

    return;
    // 0x80800144: nop

;}
RECOMP_FUNC void func_800D2820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2820: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D2824: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D2828: jal         0x800D21D0
    // 0x800D282C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D21D0(rdram, ctx);
        goto after_0;
    // 0x800D282C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800D2830: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D2834: jal         0x800D2398
    // 0x800D2838: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800D2398(rdram, ctx);
        goto after_1;
    // 0x800D2838: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800D283C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D2840: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D2844: jr          $ra
    // 0x800D2848: nop

    return;
    // 0x800D2848: nop

;}
RECOMP_FUNC void chgruntylairexttowerwindow_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1964, 0X150) << 16);
    // 0x808000C8: jr          $ra
    // 0x808000CC: addiu       $v0, $v0, 0x150
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1964, 0X150));
    return;
    // 0x808000CC: addiu       $v0, $v0, 0x150
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1964, 0X150));
;}
RECOMP_FUNC void _subaddiecustomhits_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089FF0: syscall     822
    recomp_syscall_handler(rdram, ctx, 0x80089FF0);
    return;
    // 0x80089FF4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8001B518(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B518: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8001B51C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8001B520: addiu       $v0, $v0, -0x3920
    ctx->r2 = ADD32(ctx->r2, -0X3920);
    // 0x8001B524: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8001B528: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8001B52C: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8001B530: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8001B534: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8001B538: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8001B53C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8001B540: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8001B544: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8001B548: beq         $t6, $zero, L_8001B554
    if (ctx->r14 == 0) {
        // 0x8001B54C: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_8001B554;
    }
    // 0x8001B54C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001B550: beq         $a0, $zero, L_8001B63C
    if (ctx->r4 == 0) {
        // 0x8001B554: addiu       $s7, $zero, 0x1
        ctx->r23 = ADD32(0, 0X1);
            goto L_8001B63C;
    }
L_8001B554:
    // 0x8001B554: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x8001B558: beq         $a0, $zero, L_8001B568
    if (ctx->r4 == 0) {
        // 0x8001B55C: sw          $s7, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r23;
            goto L_8001B568;
    }
    // 0x8001B55C: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x8001B560: b           L_8001B56C
    // 0x8001B564: addiu       $s4, $zero, 0xFA
    ctx->r20 = ADD32(0, 0XFA);
        goto L_8001B56C;
    // 0x8001B564: addiu       $s4, $zero, 0xFA
    ctx->r20 = ADD32(0, 0XFA);
L_8001B568:
    // 0x8001B568: addiu       $s4, $zero, 0x14
    ctx->r20 = ADD32(0, 0X14);
L_8001B56C:
    // 0x8001B56C: slti        $at, $s4, 0x2
    ctx->r1 = SIGNED(ctx->r20) < 0X2 ? 1 : 0;
    // 0x8001B570: bne         $at, $zero, L_8001B63C
    if (ctx->r1 != 0) {
        // 0x8001B574: or          $s2, $s7, $zero
        ctx->r18 = ctx->r23 | 0;
            goto L_8001B63C;
    }
    // 0x8001B574: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
    // 0x8001B578: lui         $s3, 0x8008
    ctx->r19 = S32(0X8008 << 16);
    // 0x8001B57C: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x8001B580: addiu       $s1, $s1, -0x391C
    ctx->r17 = ADD32(ctx->r17, -0X391C);
    // 0x8001B584: addiu       $s3, $s3, -0x40F0
    ctx->r19 = ADD32(ctx->r19, -0X40F0);
    // 0x8001B588: addiu       $s6, $zero, 0x5
    ctx->r22 = ADD32(0, 0X5);
    // 0x8001B58C: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
    // 0x8001B590: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
L_8001B594:
    // 0x8001B594: addiu       $v0, $t7, 0x1
    ctx->r2 = ADD32(ctx->r15, 0X1);
    // 0x8001B598: slti        $at, $v0, 0xFA
    ctx->r1 = SIGNED(ctx->r2) < 0XFA ? 1 : 0;
    // 0x8001B59C: bne         $at, $zero, L_8001B5AC
    if (ctx->r1 != 0) {
        // 0x8001B5A0: sw          $v0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r2;
            goto L_8001B5AC;
    }
    // 0x8001B5A0: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8001B5A4: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x8001B5A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001B5AC:
    // 0x8001B5AC: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    // 0x8001B5B0: addu        $t0, $s3, $t9
    ctx->r8 = ADD32(ctx->r19, ctx->r25);
    // 0x8001B5B4: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x8001B5B8: beql        $a0, $zero, L_8001B634
    if (ctx->r4 == 0) {
        // 0x8001B5BC: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8001B634;
    }
    goto skip_0;
    // 0x8001B5BC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x8001B5C0: jal         0x8001BAFC
    // 0x8001B5C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    defrag(rdram, ctx);
        goto after_0;
    // 0x8001B5C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8001B5C8: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x8001B5CC: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x8001B5D0: addu        $v1, $s3, $t2
    ctx->r3 = ADD32(ctx->r19, ctx->r10);
    // 0x8001B5D4: beq         $v0, $s0, L_8001B630
    if (ctx->r2 == ctx->r16) {
        // 0x8001B5D8: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8001B630;
    }
    // 0x8001B5D8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8001B5DC: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8001B5E0: beql        $v0, $zero, L_8001B634
    if (ctx->r2 == 0) {
        // 0x8001B5E4: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8001B634;
    }
    goto skip_1;
    // 0x8001B5E4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_1:
    // 0x8001B5E8: beq         $v0, $s7, L_8001B608
    if (ctx->r2 == ctx->r23) {
        // 0x8001B5EC: nop
    
            goto L_8001B608;
    }
    // 0x8001B5EC: nop

    // 0x8001B5F0: beq         $v0, $s5, L_8001B618
    if (ctx->r2 == ctx->r21) {
        // 0x8001B5F4: nop
    
            goto L_8001B618;
    }
    // 0x8001B5F4: nop

    // 0x8001B5F8: beq         $v0, $s6, L_8001B628
    if (ctx->r2 == ctx->r22) {
        // 0x8001B5FC: nop
    
            goto L_8001B628;
    }
    // 0x8001B5FC: nop

    // 0x8001B600: b           L_8001B634
    // 0x8001B604: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_8001B634;
    // 0x8001B604: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8001B608:
    // 0x8001B608: jal         0x800E0040
    // 0x8001B60C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    func_800E0040(rdram, ctx);
        goto after_1;
    // 0x8001B60C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    after_1:
    // 0x8001B610: b           L_8001B634
    // 0x8001B614: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_8001B634;
    // 0x8001B614: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8001B618:
    // 0x8001B618: jal         0x800E0AC0
    // 0x8001B61C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    func_800E0AC0(rdram, ctx);
        goto after_2;
    // 0x8001B61C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    after_2:
    // 0x8001B620: b           L_8001B634
    // 0x8001B624: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_8001B634;
    // 0x8001B624: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8001B628:
    // 0x8001B628: jal         0x800B2FB0
    // 0x8001B62C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    vector_update_pointers(rdram, ctx);
        goto after_3;
    // 0x8001B62C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    after_3:
L_8001B630:
    // 0x8001B630: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8001B634:
    // 0x8001B634: bnel        $s2, $s4, L_8001B594
    if (ctx->r18 != ctx->r20) {
        // 0x8001B638: lw          $t7, 0x0($s1)
        ctx->r15 = MEM_W(ctx->r17, 0X0);
            goto L_8001B594;
    }
    goto skip_2;
    // 0x8001B638: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    skip_2:
L_8001B63C:
    // 0x8001B63C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8001B640: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001B644: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8001B648: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B64C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8001B650: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8001B654: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8001B658: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8001B65C: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8001B660: jr          $ra
    // 0x8001B664: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8001B664: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
