#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_8080026C_gcdialogcamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080026C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800270: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800274: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800278: addiu       $a1, $zero, 0x52
    ctx->r5 = ADD32(0, 0X52);
    // 0x8080027C: jal         0x8010114C
    // 0x80800280: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010114C(rdram, ctx);
        goto after_0;
    // 0x80800280: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80800284: bgtzl       $v0, L_80800298
    if (SIGNED(ctx->r2) > 0) {
        // 0x80800288: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800298;
    }
    goto skip_0;
    // 0x80800288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080028C: jal         0x8080015C
    // 0x80800290: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8080015C_gcdialogcamera(rdram, ctx);
        goto after_1;
    // 0x80800290: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800294: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800298:
    // 0x80800298: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080029C: jr          $ra
    // 0x808002A0: nop

    return;
    // 0x808002A0: nop

;}
RECOMP_FUNC void bastick_pushZone(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EFA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009EFAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009EFB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009EFB4: lw          $v0, 0x128($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X128);
    // 0x8009EFB8: lbu         $t7, 0x66($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X66);
    // 0x8009EFBC: addiu       $a1, $v0, 0x38
    ctx->r5 = ADD32(ctx->r2, 0X38);
    // 0x8009EFC0: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8009EFC4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8009EFC8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8009EFCC: jal         0x8009EF40
    // 0x8009EFD0: addu        $a0, $v0, $t8
    ctx->r4 = ADD32(ctx->r2, ctx->r24);
    __bastick_zoneCopy(rdram, ctx);
        goto after_0;
    // 0x8009EFD0: addu        $a0, $v0, $t8
    ctx->r4 = ADD32(ctx->r2, ctx->r24);
    after_0:
    // 0x8009EFD4: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8009EFD8: lw          $v0, 0x128($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X128);
    // 0x8009EFDC: lbu         $t0, 0x66($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X66);
    // 0x8009EFE0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8009EFE4: sb          $t1, 0x66($v0)
    MEM_B(0X66, ctx->r2) = ctx->r9;
    // 0x8009EFE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009EFEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009EFF0: jr          $ra
    // 0x8009EFF4: nop

    return;
    // 0x8009EFF4: nop

;}
RECOMP_FUNC void func_80800838_chrainbow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800838: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x8080083C: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80800840: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x80800844: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80800848: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x8080084C: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x80800850: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x80800854: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x80800858: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x8080085C: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80800860: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80800864: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80800868: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8080086C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800870: jal         0x80100094
    // 0x80800874: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800874: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800878: lhu         $t6, 0x72($s5)
    ctx->r14 = MEM_HU(ctx->r21, 0X72);
    // 0x8080087C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800880: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800884: addiu       $t8, $t7, -0x3
    ctx->r24 = ADD32(ctx->r15, -0X3);
    // 0x80800888: sltiu       $at, $t8, 0x6
    ctx->r1 = ctx->r24 < 0X6 ? 1 : 0;
    // 0x8080088C: beq         $at, $zero, L_80800AC0
    if (ctx->r1 == 0) {
        // 0x80800890: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800AC0;
    }
    // 0x80800890: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800894: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2360, 0XFB8) << 16);
    // 0x80800898: addu        $at, $at, $t8
    gpr jr_addend_808008A0 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8080089C: lw          $t8, 0xFB8($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2360, 0XFB8));
    // 0x808008A0: jr          $t8
    // 0x808008A4: nop

    switch (jr_addend_808008A0 >> 2) {
        case 0: goto L_808008A8; break;
        case 1: goto L_808008A8; break;
        case 2: goto L_808008A8; break;
        case 3: goto L_808009BC; break;
        case 4: goto L_80800AC0; break;
        case 5: goto L_80800AA8; break;
        default: switch_error(__func__, 0x808008A0, 0x80800FB8);
    }
    // 0x808008A4: nop

L_808008A8:
    // 0x808008A8: lui         $at, 0x4128
    ctx->r1 = S32(0X4128 << 16);
    // 0x808008AC: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x808008B0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x808008B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808008B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808008BC: lwc1        $f12, 0x58($s5)
    ctx->f12.u32l = MEM_W(ctx->r21, 0X58);
    // 0x808008C0: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x808008C4: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x808008C8: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x808008CC: jal         0x800F10B4
    // 0x808008D0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x808008D0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x808008D4: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x808008D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808008DC: lwc1        $f12, 0x58($s5)
    ctx->f12.u32l = MEM_W(ctx->r21, 0X58);
    // 0x808008E0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x808008E4: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    // 0x808008E8: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x808008EC: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    // 0x808008F0: jal         0x800F10B4
    // 0x808008F4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x808008F4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x808008F8: lui         $at, 0x4434
    ctx->r1 = S32(0X4434 << 16);
    // 0x808008FC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800900: lwc1        $f12, 0x58($s5)
    ctx->f12.u32l = MEM_W(ctx->r21, 0X58);
    // 0x80800904: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80800908: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8080090C: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x80800910: lui         $a3, 0x43B4
    ctx->r7 = S32(0X43B4 << 16);
    // 0x80800914: jal         0x800F10B4
    // 0x80800918: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x80800918: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x8080091C: mul.s       $f12, $f26, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f26.fl, ctx->f0.fl);
    // 0x80800920: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800924: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80800928: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8080092C: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
    // 0x80800930: addiu       $s1, $s3, 0x8
    ctx->r17 = ADD32(ctx->r19, 0X8);
    // 0x80800934: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800938: addiu       $s3, $sp, 0x9C
    ctx->r19 = ADD32(ctx->r29, 0X9C);
    // 0x8080093C: add.s       $f24, $f12, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f24.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x80800940: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800944: addiu       $s4, $zero, 0x6
    ctx->r20 = ADD32(0, 0X6);
L_80800948:
    // 0x80800948: jal         0x80106790
    // 0x8080094C: lw          $a0, 0x3C($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X3C);
    func_80106790(rdram, ctx);
        goto after_4;
    // 0x8080094C: lw          $a0, 0x3C($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X3C);
    after_4:
    // 0x80800950: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800954: jal         0x800EE7F8
    // 0x80800958: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x80800958: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    after_5:
    // 0x8080095C: mtc1        $s0, $f10
    ctx->f10.u32l = ctx->r16;
    // 0x80800960: mfc1        $a2, $f28
    ctx->r6 = (int32_t)ctx->f28.u32l;
    // 0x80800964: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800968: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8080096C: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x80800970: add.s       $f4, $f24, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f24.fl + ctx->f18.fl;
    // 0x80800974: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80800978: jal         0x800EEB9C
    // 0x8080097C: nop

    func_800EEB9C(rdram, ctx);
        goto after_6;
    // 0x8080097C: nop

    after_6:
    // 0x80800980: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800984: jal         0x800EF04C
    // 0x80800988: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EF04C(rdram, ctx);
        goto after_7;
    // 0x80800988: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_7:
    // 0x8080098C: lwc1        $f6, 0xC($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0XC);
    // 0x80800990: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800994: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800998: add.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f22.fl;
    // 0x8080099C: jal         0x808005E0
    // 0x808009A0: swc1        $f8, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f8.u32l;
    func_808005E0_chrainbow(rdram, ctx);
        goto after_8;
    // 0x808009A0: swc1        $f8, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f8.u32l;
    after_8:
    // 0x808009A4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808009A8: addiu       $s2, $s2, 0x20
    ctx->r18 = ADD32(ctx->r18, 0X20);
    // 0x808009AC: bne         $s0, $s4, L_80800948
    if (ctx->r16 != ctx->r20) {
        // 0x808009B0: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_80800948;
    }
    // 0x808009B0: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x808009B4: b           L_80800AC4
    // 0x808009B8: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
        goto L_80800AC4;
    // 0x808009B8: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_808009BC:
    // 0x808009BC: lui         $at, 0x4128
    ctx->r1 = S32(0X4128 << 16);
    // 0x808009C0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x808009C4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808009C8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808009CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808009D0: lwc1        $f12, 0x58($s5)
    ctx->f12.u32l = MEM_W(ctx->r21, 0X58);
    // 0x808009D4: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x808009D8: lui         $a2, 0x4158
    ctx->r6 = S32(0X4158 << 16);
    // 0x808009DC: jal         0x800F10B4
    // 0x808009E0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_9;
    // 0x808009E0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_9:
    // 0x808009E4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808009E8: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x808009EC: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x808009F0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808009F4: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x808009F8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808009FC: mul.s       $f18, $f0, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80800A00: lui         $at, 0x4434
    ctx->r1 = S32(0X4434 << 16);
    // 0x80800A04: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800A08: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80800A0C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800A10: mul.s       $f14, $f0, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x80800A14: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
    // 0x80800A18: add.s       $f22, $f18, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80800A1C: addiu       $s1, $s3, 0x8
    ctx->r17 = ADD32(ctx->r19, 0X8);
    // 0x80800A20: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800A24: add.s       $f24, $f18, $f28
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f24.fl = ctx->f18.fl + ctx->f28.fl;
    // 0x80800A28: addiu       $s4, $zero, 0x6
    ctx->r20 = ADD32(0, 0X6);
    // 0x80800A2C: addiu       $s3, $sp, 0x84
    ctx->r19 = ADD32(ctx->r29, 0X84);
    // 0x80800A30: add.s       $f26, $f14, $f14
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f26.fl = ctx->f14.fl + ctx->f14.fl;
L_80800A34:
    // 0x80800A34: jal         0x80106790
    // 0x80800A38: lw          $a0, 0x3C($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X3C);
    func_80106790(rdram, ctx);
        goto after_10;
    // 0x80800A38: lw          $a0, 0x3C($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X3C);
    after_10:
    // 0x80800A3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800A40: jal         0x800EE7F8
    // 0x80800A44: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_11;
    // 0x80800A44: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    after_11:
    // 0x80800A48: mtc1        $s0, $f6
    ctx->f6.u32l = ctx->r16;
    // 0x80800A4C: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80800A50: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800A54: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800A58: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80800A5C: add.s       $f16, $f26, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f26.fl + ctx->f10.fl;
    // 0x80800A60: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80800A64: jal         0x800EEB9C
    // 0x80800A68: nop

    func_800EEB9C(rdram, ctx);
        goto after_12;
    // 0x80800A68: nop

    after_12:
    // 0x80800A6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800A70: jal         0x800EF04C
    // 0x80800A74: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EF04C(rdram, ctx);
        goto after_13;
    // 0x80800A74: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_13:
    // 0x80800A78: lwc1        $f18, 0xC($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0XC);
    // 0x80800A7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800A80: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800A84: add.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f22.fl;
    // 0x80800A88: jal         0x808005E0
    // 0x80800A8C: swc1        $f4, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f4.u32l;
    func_808005E0_chrainbow(rdram, ctx);
        goto after_14;
    // 0x80800A8C: swc1        $f4, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f4.u32l;
    after_14:
    // 0x80800A90: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800A94: addiu       $s2, $s2, 0x20
    ctx->r18 = ADD32(ctx->r18, 0X20);
    // 0x80800A98: bne         $s0, $s4, L_80800A34
    if (ctx->r16 != ctx->r20) {
        // 0x80800A9C: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_80800A34;
    }
    // 0x80800A9C: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x80800AA0: b           L_80800AC4
    // 0x80800AA4: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
        goto L_80800AC4;
    // 0x80800AA4: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_80800AA8:
    // 0x80800AA8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800AAC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800AB0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800AB4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800AB8: jal         0x8080063C
    // 0x80800ABC: nop

    func_8080063C_chrainbow(rdram, ctx);
        goto after_15;
    // 0x80800ABC: nop

    after_15:
L_80800AC0:
    // 0x80800AC0: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_80800AC4:
    // 0x80800AC4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800AC8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800ACC: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80800AD0: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80800AD4: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80800AD8: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x80800ADC: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x80800AE0: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x80800AE4: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x80800AE8: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x80800AEC: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x80800AF0: jr          $ra
    // 0x80800AF4: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x80800AF4: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_808002AC_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002B0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808002B4: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(404, 0X223C) << 16);
    // 0x808002B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002BC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808002C0: addiu       $t6, $t6, 0x223C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(404, 0X223C));
    // 0x808002C4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x808002C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808002CC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808002D0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808002D4: jal         0x800BBCB8
    // 0x808002D8: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x808002D8: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_0:
    // 0x808002DC: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(404, 0X2284) << 16);
    // 0x808002E0: addiu       $t7, $t7, 0x2284
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(404, 0X2284));
    // 0x808002E4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808002E8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808002EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808002F0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808002F4: jal         0x800BBCB8
    // 0x808002F8: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    func_800BBCB8(rdram, ctx);
        goto after_1;
    // 0x808002F8: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    after_1:
    // 0x808002FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800300: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800304: jr          $ra
    // 0x80800308: nop

    return;
    // 0x80800308: nop

;}
RECOMP_FUNC void _subaddiefind_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089C50: syscall     807
    recomp_syscall_handler(rdram, ctx, 0x80089C50);
    return;
    // 0x80089C54: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void gspropmarker_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800328: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x8080032C: lui         $at, 0x7F
    ctx->r1 = S32(0X7F << 16);
    // 0x80800330: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80800334: and         $t6, $v0, $at
    ctx->r14 = ctx->r2 & ctx->r1;
    // 0x80800338: beq         $t6, $zero, L_80800370
    if (ctx->r14 == 0) {
        // 0x8080033C: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80800370;
    }
    // 0x8080033C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80800340: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80800344: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800348: bgez        $t6, L_8080035C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8080034C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8080035C;
    }
    // 0x8080034C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800350: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800354: nop

    // 0x80800358: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8080035C:
    // 0x8080035C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2878, 0X390) << 16);
    // 0x80800360: lwc1        $f10, 0x390($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2878, 0X390));
    // 0x80800364: mul.s       $f2, $f6, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80800368: jr          $ra
    // 0x8080036C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x8080036C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80800370:
    // 0x80800370: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800374: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800378: nop

    // 0x8080037C: jr          $ra
    // 0x80800380: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x80800380: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80800384: nop

    // 0x80800388: nop

    // 0x8080038C: nop

;}
RECOMP_FUNC void func_8008BC94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008BC94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008BC98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008BC9C: jal         0x8008BC6C
    // 0x8008BCA0: lbu         $a1, 0x8($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X8);
    func_8008BC6C(rdram, ctx);
        goto after_0;
    // 0x8008BCA0: lbu         $a1, 0x8($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X8);
    after_0:
    // 0x8008BCA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008BCA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008BCAC: jr          $ra
    // 0x8008BCB0: nop

    return;
    // 0x8008BCB0: nop

;}
RECOMP_FUNC void chgameselect_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808027C8: lui         $v0, 0x8081
    ctx->r2 = S32(RELOC_HI16(804, 0X8328) << 16);
    // 0x808027CC: jr          $ra
    // 0x808027D0: addiu       $v0, $v0, -0x7CD8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(804, 0X8328));
    return;
    // 0x808027D0: addiu       $v0, $v0, -0x7CD8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(804, 0X8328));
;}
RECOMP_FUNC void _glhittableDll_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088640: syscall     696
    recomp_syscall_handler(rdram, ctx, 0x80088640);
    return;
    // 0x80088644: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_8008D18C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D18C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008D190: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008D194: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008D198: jal         0x800C6E38
    // 0x8008D19C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800C6E38(rdram, ctx);
        goto after_0;
    // 0x8008D19C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x8008D1A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008D1A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008D1A8: jr          $ra
    // 0x8008D1AC: nop

    return;
    // 0x8008D1AC: nop

;}
RECOMP_FUNC void func_80800DB8_chjollyroger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800DBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800DC0: jal         0x800897C8
    // 0x80800DC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x80800DC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800DC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800DCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800DD0: jr          $ra
    // 0x80800DD4: nop

    return;
    // 0x80800DD4: nop

;}
RECOMP_FUNC void baflamethrower_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800204: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800208: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080020C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800210: lw          $t6, 0x88($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X88);
    // 0x80800214: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800218: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080021C: lbu         $v0, 0xC($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0XC);
    // 0x80800220: beq         $v0, $at, L_80800280
    if (ctx->r2 == ctx->r1) {
        // 0x80800224: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800280;
    }
    // 0x80800224: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800228: beq         $v0, $at, L_80800240
    if (ctx->r2 == ctx->r1) {
        // 0x8080022C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800240;
    }
    // 0x8080022C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800230: beq         $v0, $at, L_80800250
    if (ctx->r2 == ctx->r1) {
        // 0x80800234: nop
    
            goto L_80800250;
    }
    // 0x80800234: nop

    // 0x80800238: b           L_80800280
    // 0x8080023C: nop

        goto L_80800280;
    // 0x8080023C: nop

L_80800240:
    // 0x80800240: jal         0x80800008
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800008_baflamethrower(rdram, ctx);
        goto after_0;
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800248: b           L_80800280
    // 0x8080024C: nop

        goto L_80800280;
    // 0x8080024C: nop

L_80800250:
    // 0x80800250: jal         0x80800008
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800008_baflamethrower(rdram, ctx);
        goto after_1;
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800258: lw          $v0, 0x88($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X88);
    // 0x8080025C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800260: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80800264: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80800268: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8080026C: nop

    // 0x80800270: bc1f        L_80800280
    if (!c1cs) {
        // 0x80800274: nop
    
            goto L_80800280;
    }
    // 0x80800274: nop

    // 0x80800278: jal         0x80800088
    // 0x8080027C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800088_baflamethrower(rdram, ctx);
        goto after_2;
    // 0x8080027C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_80800280:
    // 0x80800280: jal         0x80084B90
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baflameline_entrypoint_7(rdram, ctx);
        goto after_3;
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800288: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080028C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800290: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800294: jr          $ra
    // 0x80800298: nop

    return;
    // 0x80800298: nop

    // 0x8080029C: nop

;}
RECOMP_FUNC void func_80802EA0_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802EA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802EA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802EA8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80802EAC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80802EB0: jal         0x80106790
    // 0x80802EB4: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80802EB4: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x80802EB8: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80802EBC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80802EC0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80802EC4: lhu         $t8, 0x72($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X72);
    // 0x80802EC8: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x80802ECC: beql        $t9, $at, L_80802F08
    if (ctx->r25 == ctx->r1) {
        // 0x80802ED0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80802F08;
    }
    goto skip_0;
    // 0x80802ED0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80802ED4: jal         0x80801320
    // 0x80802ED8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80801320_chstoneballcontrol(rdram, ctx);
        goto after_1;
    // 0x80802ED8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80802EDC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80802EE0: jal         0x80089AF8
    // 0x80802EE4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _sukickball_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x80802EE4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80802EE8: beq         $v0, $zero, L_80802F04
    if (ctx->r2 == 0) {
        // 0x80802EEC: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_80802F04;
    }
    // 0x80802EEC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80802EF0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80802EF4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80802EF8: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    // 0x80802EFC: jal         0x80089B00
    // 0x80802F00: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    _sukickball_entrypoint_13(rdram, ctx);
        goto after_3;
    // 0x80802F00: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_3:
L_80802F04:
    // 0x80802F04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802F08:
    // 0x80802F08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802F0C: jr          $ra
    // 0x80802F10: nop

    return;
    // 0x80802F10: nop

;}
RECOMP_FUNC void chdrips_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800100: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800104: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800108: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8080010C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800110: jal         0x800B53A4
    // 0x80800114: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800B53A4(rdram, ctx);
        goto after_0;
    // 0x80800114: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_0:
    // 0x80800118: addiu       $t6, $zero, 0x32
    ctx->r14 = ADD32(0, 0X32);
    // 0x8080011C: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x80800120: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800124: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80800128: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080012C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800130: addiu       $a1, $zero, -0x32
    ctx->r5 = ADD32(0, -0X32);
    // 0x80800134: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800138: addiu       $a3, $zero, -0x32
    ctx->r7 = ADD32(0, -0X32);
    // 0x8080013C: jal         0x800BA6B0
    // 0x80800140: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_800BA6B0(rdram, ctx);
        goto after_1;
    // 0x80800140: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_1:
    // 0x80800144: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80800148: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8080014C: lwc1        $f4, 0x4($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X4);
    // 0x80800150: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800154: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800158: nop

    // 0x8080015C: sll         $t0, $a1, 16
    ctx->r8 = S32(ctx->r5 << 16);
    // 0x80800160: jal         0x800BA4D0
    // 0x80800164: sra         $a1, $t0, 16
    ctx->r5 = S32(SIGNED(ctx->r8) >> 16);
    func_800BA4D0(rdram, ctx);
        goto after_2;
    // 0x80800164: sra         $a1, $t0, 16
    ctx->r5 = S32(SIGNED(ctx->r8) >> 16);
    after_2:
    // 0x80800168: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(1816, 0X658) << 16);
    // 0x8080016C: addiu       $t2, $t2, 0x658
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(1816, 0X658));
    // 0x80800170: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800174: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800178: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8080017C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800180: jal         0x800BABB8
    // 0x80800184: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_3;
    // 0x80800184: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_3:
    // 0x80800188: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080018C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800190: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1816, 0X5F8) << 16);
    // 0x80800194: jal         0x800DC178
    // 0x80800198: lwc1        $f14, 0x5F8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1816, 0X5F8));
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x80800198: lwc1        $f14, 0x5F8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1816, 0X5F8));
    after_4:
    // 0x8080019C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1816, 0X5FC) << 16);
    // 0x808001A0: lwc1        $f8, 0x5FC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1816, 0X5FC));
    // 0x808001A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808001A8: lui         $a2, 0x5DC
    ctx->r6 = S32(0X5DC << 16);
    // 0x808001AC: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x808001B0: ori         $a2, $a2, 0x12C
    ctx->r6 = ctx->r6 | 0X12C;
    // 0x808001B4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808001B8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x808001BC: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x808001C0: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x808001C4: nop

    // 0x808001C8: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x808001CC: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x808001D0: nop

    // 0x808001D4: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x808001D8: beql        $a0, $zero, L_80800228
    if (ctx->r4 == 0) {
        // 0x808001DC: mfc1        $a0, $f16
        ctx->r4 = (int32_t)ctx->f16.u32l;
            goto L_80800228;
    }
    goto skip_0;
    // 0x808001DC: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x808001E0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808001E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808001E8: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x808001EC: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x808001F0: nop

    // 0x808001F4: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x808001F8: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x808001FC: nop

    // 0x80800200: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x80800204: bne         $a0, $zero, L_8080021C
    if (ctx->r4 != 0) {
        // 0x80800208: nop
    
            goto L_8080021C;
    }
    // 0x80800208: nop

    // 0x8080020C: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x80800210: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800214: b           L_80800234
    // 0x80800218: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_80800234;
    // 0x80800218: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_8080021C:
    // 0x8080021C: b           L_80800234
    // 0x80800220: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_80800234;
    // 0x80800220: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80800224: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
L_80800228:
    // 0x80800228: nop

    // 0x8080022C: bltz        $a0, L_8080021C
    if (SIGNED(ctx->r4) < 0) {
        // 0x80800230: nop
    
            goto L_8080021C;
    }
    // 0x80800230: nop

L_80800234:
    // 0x80800234: or          $t4, $a0, $zero
    ctx->r12 = ctx->r4 | 0;
    // 0x80800238: lui         $at, 0xB
    ctx->r1 = S32(0XB << 16);
    // 0x8080023C: ori         $at, $at, 0xBD52
    ctx->r1 = ctx->r1 | 0XBD52;
    // 0x80800240: sll         $t5, $t4, 21
    ctx->r13 = S32(ctx->r12 << 21);
    // 0x80800244: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80800248: jal         0x800C4140
    // 0x8080024C: addu        $a0, $t5, $at
    ctx->r4 = ADD32(ctx->r13, ctx->r1);
    func_800C4140(rdram, ctx);
        goto after_5;
    // 0x8080024C: addu        $a0, $t5, $at
    ctx->r4 = ADD32(ctx->r13, ctx->r1);
    after_5:
    // 0x80800250: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800254: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800258: jr          $ra
    // 0x8080025C: nop

    return;
    // 0x8080025C: nop

;}
RECOMP_FUNC void func_800CA218(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA218: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800CA21C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CA220: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800CA224: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800CA228: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CA22C: addiu       $a0, $a0, 0x104
    ctx->r4 = ADD32(ctx->r4, 0X104);
    // 0x800CA230: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800CA234: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800CA238: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x800CA23C: jal         0x800EFA4C
    // 0x800CA240: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x800CA240: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_0:
    // 0x800CA244: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800CA248: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800CA24C: jal         0x800EF8BC
    // 0x800CA250: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_800EF8BC(rdram, ctx);
        goto after_1;
    // 0x800CA250: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_1:
    // 0x800CA254: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800CA258: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800CA25C: lui         $a1, 0xBF80
    ctx->r5 = S32(0XBF80 << 16);
    // 0x800CA260: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800CA264: addiu       $a0, $a0, 0xF8
    ctx->r4 = ADD32(ctx->r4, 0XF8);
    // 0x800CA268: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800CA26C: jal         0x800EFA4C
    // 0x800CA270: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_800EFA4C(rdram, ctx);
        goto after_2;
    // 0x800CA270: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_2:
    // 0x800CA274: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800CA278: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800CA27C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800CA280: lwc1        $f4, 0xE8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XE8);
    // 0x800CA284: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800CA288: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800CA28C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x800CA290: jal         0x800EF934
    // 0x800CA294: nop

    func_800EF934(rdram, ctx);
        goto after_3;
    // 0x800CA294: nop

    after_3:
    // 0x800CA298: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CA29C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CA2A0: jr          $ra
    // 0x800CA2A4: nop

    return;
    // 0x800CA2A4: nop

;}
RECOMP_FUNC void func_808004F8_chcactusofstrength(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004F8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808004FC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800500: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800504: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800508: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x8080050C: lw          $v1, 0x50($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X50);
    // 0x80800510: lwc1        $f8, 0x28($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X28);
    // 0x80800514: lwc1        $f6, 0x2C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x80800518: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080051C: beq         $v1, $zero, L_80800548
    if (ctx->r3 == 0) {
        // 0x80800520: sub.s       $f0, $f6, $f8
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
            goto L_80800548;
    }
    // 0x80800520: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80800524: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800528: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8080052C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800530: jal         0x800CEAA8
    // 0x80800534: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    func_800CEAA8(rdram, ctx);
        goto after_0;
    // 0x80800534: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80800538: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8080053C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800540: beq         $v0, $zero, L_808006A8
    if (ctx->r2 == 0) {
        // 0x80800544: lwc1        $f0, 0x28($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
            goto L_808006A8;
    }
    // 0x80800544: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
L_80800548:
    // 0x80800548: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x8080054C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800550: and         $t6, $v0, $a1
    ctx->r14 = ctx->r2 & ctx->r5;
    // 0x80800554: bnel        $t6, $zero, L_808006AC
    if (ctx->r14 != 0) {
        // 0x80800558: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808006AC;
    }
    goto skip_0;
    // 0x80800558: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080055C: beq         $a1, $at, L_80800580
    if (ctx->r5 == ctx->r1) {
        // 0x80800560: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800580;
    }
    // 0x80800560: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800564: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800568: beq         $a1, $at, L_8080059C
    if (ctx->r5 == ctx->r1) {
        // 0x8080056C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8080059C;
    }
    // 0x8080056C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800570: beq         $a1, $at, L_808005B8
    if (ctx->r5 == ctx->r1) {
        // 0x80800574: ori         $t9, $v0, 0x4
        ctx->r25 = ctx->r2 | 0X4;
            goto L_808005B8;
    }
    // 0x80800574: ori         $t9, $v0, 0x4
    ctx->r25 = ctx->r2 | 0X4;
    // 0x80800578: b           L_808005CC
    // 0x8080057C: nop

        goto L_808005CC;
    // 0x8080057C: nop

L_80800580:
    // 0x80800580: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800584: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800588: ori         $t7, $v0, 0x1
    ctx->r15 = ctx->r2 | 0X1;
    // 0x8080058C: sw          $t7, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r15;
    // 0x80800590: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800594: b           L_808005CC
    // 0x80800598: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
        goto L_808005CC;
    // 0x80800598: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
L_8080059C:
    // 0x8080059C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x808005A0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808005A4: ori         $t8, $v0, 0x2
    ctx->r24 = ctx->r2 | 0X2;
    // 0x808005A8: sw          $t8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r24;
    // 0x808005AC: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x808005B0: b           L_808005CC
    // 0x808005B4: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
        goto L_808005CC;
    // 0x808005B4: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
L_808005B8:
    // 0x808005B8: sw          $t9, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r25;
    // 0x808005BC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(824, 0XCC0) << 16);
    // 0x808005C0: lwc1        $f6, 0xCC0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(824, 0XCC0));
    // 0x808005C4: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808005C8: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
L_808005CC:
    // 0x808005CC: bne         $v1, $zero, L_808005F4
    if (ctx->r3 != 0) {
        // 0x808005D0: lui         $a1, 0x41A0
        ctx->r5 = S32(0X41A0 << 16);
            goto L_808005F4;
    }
    // 0x808005D0: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    // 0x808005D4: jal         0x800CE8D8
    // 0x808005D8: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    func_800CE8D8(rdram, ctx);
        goto after_1;
    // 0x808005D8: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_1:
    // 0x808005DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808005E0: jal         0x800CE88C
    // 0x808005E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800CE88C(rdram, ctx);
        goto after_2;
    // 0x808005E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x808005E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005EC: jal         0x8008A4B0
    // 0x808005F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x808005F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
L_808005F4:
    // 0x808005F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005F8: jal         0x80101FDC
    // 0x808005FC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x808005FC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x80800600: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800604: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800608: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8080060C: mul.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800610: jal         0x8002DCA0
    // 0x80800614: nop

    sqrtf_recomp(rdram, ctx);
        goto after_5;
    // 0x80800614: nop

    after_5:
    // 0x80800618: lw          $t0, 0x50($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X50);
    // 0x8080061C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800620: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80800624: andi        $t1, $t0, 0x7
    ctx->r9 = ctx->r8 & 0X7;
    // 0x80800628: beq         $t1, $at, L_80800678
    if (ctx->r9 == ctx->r1) {
        // 0x8080062C: addiu       $a0, $zero, 0x10
        ctx->r4 = ADD32(0, 0X10);
            goto L_80800678;
    }
    // 0x8080062C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80800630: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x80800634: jal         0x800FC618
    // 0x80800638: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_800FC618(rdram, ctx);
        goto after_6;
    // 0x80800638: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_6:
    // 0x8080063C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(824, 0XCC4) << 16);
    // 0x80800640: lwc1        $f18, 0xCC4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(824, 0XCC4));
    // 0x80800644: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800648: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080064C: addiu       $a2, $zero, 0xAA
    ctx->r6 = ADD32(0, 0XAA);
    // 0x80800650: addiu       $a3, $zero, 0x800
    ctx->r7 = ADD32(0, 0X800);
    // 0x80800654: jal         0x80085708
    // 0x80800658: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    _capod_entrypoint_13(rdram, ctx);
        goto after_7;
    // 0x80800658: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    after_7:
    // 0x8080065C: jal         0x800F54E4
    // 0x80800660: nop

    func_800F54E4(rdram, ctx);
        goto after_8;
    // 0x80800660: nop

    after_8:
    // 0x80800664: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800668: jal         0x800F7F98
    // 0x8080066C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F7F98(rdram, ctx);
        goto after_9;
    // 0x8080066C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80800670: b           L_808006AC
    // 0x80800674: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808006AC;
    // 0x80800674: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800678:
    // 0x80800678: jal         0x800FC618
    // 0x8080067C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_800FC618(rdram, ctx);
        goto after_10;
    // 0x8080067C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_10:
    // 0x80800680: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800684: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800688: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8080068C: jal         0x80085708
    // 0x80800690: addiu       $a3, $zero, 0x800
    ctx->r7 = ADD32(0, 0X800);
    _capod_entrypoint_13(rdram, ctx);
        goto after_11;
    // 0x80800690: addiu       $a3, $zero, 0x800
    ctx->r7 = ADD32(0, 0X800);
    after_11:
    // 0x80800694: jal         0x800F54E4
    // 0x80800698: nop

    func_800F54E4(rdram, ctx);
        goto after_12;
    // 0x80800698: nop

    after_12:
    // 0x8080069C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808006A0: jal         0x800F7F98
    // 0x808006A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F7F98(rdram, ctx);
        goto after_13;
    // 0x808006A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
L_808006A8:
    // 0x808006A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808006AC:
    // 0x808006AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808006B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808006B4: jr          $ra
    // 0x808006B8: nop

    return;
    // 0x808006B8: nop

;}
RECOMP_FUNC void func_800EEF94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EEF94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EEF98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EEF9C: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800EEFA0: lwc1        $f14, 0x4($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800EEFA4: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800EEFA8: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800EEFAC: nop

    // 0x800EEFB0: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800EEFB4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800EEFB8: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800EEFBC: jal         0x8002DCA0
    // 0x800EEFC0: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800EEFC0: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    after_0:
    // 0x800EEFC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EEFC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EEFCC: jr          $ra
    // 0x800EEFD0: nop

    return;
    // 0x800EEFD0: nop

;}
RECOMP_FUNC void bsdroneslide_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800438: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080043C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800440: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800444: jal         0x8009BF5C
    // 0x80800448: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_0;
    // 0x80800448: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_0:
    // 0x8080044C: jal         0x800A4E30
    // 0x80800450: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A4E30(rdram, ctx);
        goto after_1;
    // 0x80800450: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800454: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800458: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080045C: jr          $ra
    // 0x80800460: nop

    return;
    // 0x80800460: nop

    // 0x80800464: nop

    // 0x80800468: nop

    // 0x8080046C: nop

;}
RECOMP_FUNC void func_8001A018(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A018: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001A01C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001A020: jal         0x8001ACCC
    // 0x8001A024: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x8001A024: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    after_0:
    // 0x8001A028: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8001A02C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001A030: addiu       $a0, $a0, -0x4340
    ctx->r4 = ADD32(ctx->r4, -0X4340);
    // 0x8001A034: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8001A038: bgez        $v1, L_8001A04C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8001A03C: andi        $t6, $v1, 0x3F
        ctx->r14 = ctx->r3 & 0X3F;
            goto L_8001A04C;
    }
    // 0x8001A03C: andi        $t6, $v1, 0x3F
    ctx->r14 = ctx->r3 & 0X3F;
    // 0x8001A040: beq         $t6, $zero, L_8001A04C
    if (ctx->r14 == 0) {
        // 0x8001A044: nop
    
            goto L_8001A04C;
    }
    // 0x8001A044: nop

    // 0x8001A048: addiu       $t6, $t6, -0x40
    ctx->r14 = ADD32(ctx->r14, -0X40);
L_8001A04C:
    // 0x8001A04C: beq         $t6, $zero, L_8001A074
    if (ctx->r14 == 0) {
        // 0x8001A050: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8001A074;
    }
    // 0x8001A050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001A054: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
L_8001A058:
    // 0x8001A058: bgez        $v1, L_8001A06C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8001A05C: andi        $t7, $v1, 0x3F
        ctx->r15 = ctx->r3 & 0X3F;
            goto L_8001A06C;
    }
    // 0x8001A05C: andi        $t7, $v1, 0x3F
    ctx->r15 = ctx->r3 & 0X3F;
    // 0x8001A060: beq         $t7, $zero, L_8001A06C
    if (ctx->r15 == 0) {
        // 0x8001A064: nop
    
            goto L_8001A06C;
    }
    // 0x8001A064: nop

    // 0x8001A068: addiu       $t7, $t7, -0x40
    ctx->r15 = ADD32(ctx->r15, -0X40);
L_8001A06C:
    // 0x8001A06C: bnel        $t7, $zero, L_8001A058
    if (ctx->r15 != 0) {
        // 0x8001A070: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_8001A058;
    }
    goto skip_0;
    // 0x8001A070: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    skip_0:
L_8001A074:
    // 0x8001A074: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8001A078: jr          $ra
    // 0x8001A07C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8001A07C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80801290_chfantasyeyeball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801290: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801294: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801298: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080129C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808012A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808012A4: jal         0x8008A4B0
    // 0x808012A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808012A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808012AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808012B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2400, 0X1E1C) << 16);
    // 0x808012B4: lwc1        $f4, 0x1E1C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2400, 0X1E1C));
    // 0x808012B8: lbu         $t7, 0x65($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X65);
    // 0x808012BC: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    // 0x808012C0: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x808012C4: sb          $t8, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r24;
    // 0x808012C8: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x808012CC: bnel        $t9, $zero, L_80801308
    if (ctx->r25 != 0) {
        // 0x808012D0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801308;
    }
    goto skip_0;
    // 0x808012D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808012D4: jal         0x800F54E4
    // 0x808012D8: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x808012D8: nop

    after_1:
    // 0x808012DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808012E0: jal         0x800F7B9C
    // 0x808012E4: addiu       $a1, $zero, 0x6B
    ctx->r5 = ADD32(0, 0X6B);
    func_800F7B9C(rdram, ctx);
        goto after_2;
    // 0x808012E4: addiu       $a1, $zero, 0x6B
    ctx->r5 = ADD32(0, 0X6B);
    after_2:
    // 0x808012E8: jal         0x800A50B0
    // 0x808012EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800A50B0(rdram, ctx);
        goto after_3;
    // 0x808012EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x808012F0: jal         0x800F54E4
    // 0x808012F4: nop

    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x808012F4: nop

    after_4:
    // 0x808012F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808012FC: jal         0x800F82D4
    // 0x80801300: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800F82D4(rdram, ctx);
        goto after_5;
    // 0x80801300: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x80801304: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801308:
    // 0x80801308: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080130C: jr          $ra
    // 0x80801310: nop

    return;
    // 0x80801310: nop

;}
RECOMP_FUNC void func_808002DC_chjiggypost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002E0: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x808002E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002E8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808002EC: beq         $a1, $at, L_8080031C
    if (ctx->r5 == ctx->r1) {
        // 0x808002F0: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_8080031C;
    }
    // 0x808002F0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808002F4: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x808002F8: beq         $a1, $at, L_80800334
    if (ctx->r5 == ctx->r1) {
        // 0x808002FC: addiu       $at, $zero, 0x52
        ctx->r1 = ADD32(0, 0X52);
            goto L_80800334;
    }
    // 0x808002FC: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x80800300: beq         $a1, $at, L_8080034C
    if (ctx->r5 == ctx->r1) {
        // 0x80800304: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(796, 0X3C8) << 16);
            goto L_8080034C;
    }
    // 0x80800304: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(796, 0X3C8) << 16);
    // 0x80800308: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x8080030C: beql        $a1, $at, L_8080036C
    if (ctx->r5 == ctx->r1) {
        // 0x80800310: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8080036C;
    }
    goto skip_0;
    // 0x80800310: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800314: b           L_8080036C
    // 0x80800318: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080036C;
    // 0x80800318: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080031C:
    // 0x8080031C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800320: lh          $a1, 0x20($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X20);
    // 0x80800324: jal         0x808001C4
    // 0x80800328: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    func_808001C4_chjiggypost(rdram, ctx);
        goto after_0;
    // 0x80800328: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    after_0:
    // 0x8080032C: b           L_8080036C
    // 0x80800330: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080036C;
    // 0x80800330: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800334:
    // 0x80800334: lhu         $a0, 0x76($a3)
    ctx->r4 = MEM_HU(ctx->r7, 0X76);
    // 0x80800338: srl         $t6, $a0, 7
    ctx->r14 = S32(U32(ctx->r4) >> 7);
    // 0x8080033C: jal         0x8008A6A8
    // 0x80800340: addiu       $a0, $t6, -0x33
    ctx->r4 = ADD32(ctx->r14, -0X33);
    _sujiggy_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800340: addiu       $a0, $t6, -0x33
    ctx->r4 = ADD32(ctx->r14, -0X33);
    after_1:
    // 0x80800344: b           L_80800370
    // 0x80800348: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800370;
    // 0x80800348: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080034C:
    // 0x8080034C: addiu       $a0, $a0, 0x3C8
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(796, 0X3C8));
    // 0x80800350: jal         0x80088090
    // 0x80800354: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800354: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    after_2:
    // 0x80800358: b           L_8080036C
    // 0x8080035C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080036C;
    // 0x8080035C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800360: b           L_8080036C
    // 0x80800364: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080036C;
    // 0x80800364: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800368: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080036C:
    // 0x8080036C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800370:
    // 0x80800370: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800374: jr          $ra
    // 0x80800378: nop

    return;
    // 0x80800378: nop

;}
RECOMP_FUNC void func_808023BC_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808023BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808023C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808023C4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808023C8: jal         0x80100094
    // 0x808023CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808023CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808023D0: jal         0x8008A040
    // 0x808023D4: addiu       $a0, $v0, 0x30
    ctx->r4 = ADD32(ctx->r2, 0X30);
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x808023D4: addiu       $a0, $v0, 0x30
    ctx->r4 = ADD32(ctx->r2, 0X30);
    after_1:
    // 0x808023D8: beq         $v0, $zero, L_808023E8
    if (ctx->r2 == 0) {
        // 0x808023DC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808023E8;
    }
    // 0x808023DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808023E0: jal         0x808041C4
    // 0x808023E4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_808041C4_chweldarboss(rdram, ctx);
        goto after_2;
    // 0x808023E4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
L_808023E8:
    // 0x808023E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808023EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808023F0: jr          $ra
    // 0x808023F4: nop

    return;
    // 0x808023F4: nop

;}
RECOMP_FUNC void gemarkersDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: slti        $at, $a0, 0xB6
    ctx->r1 = SIGNED(ctx->r4) < 0XB6 ? 1 : 0;
    // 0x80800004: bne         $at, $zero, L_80800014
    if (ctx->r1 != 0) {
        // 0x80800008: slti        $at, $a0, 0x546
        ctx->r1 = SIGNED(ctx->r4) < 0X546 ? 1 : 0;
            goto L_80800014;
    }
    // 0x80800008: slti        $at, $a0, 0x546
    ctx->r1 = SIGNED(ctx->r4) < 0X546 ? 1 : 0;
    // 0x8080000C: bne         $at, $zero, L_8080001C
    if (ctx->r1 != 0) {
        // 0x80800010: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_8080001C;
    }
    // 0x80800010: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
L_80800014:
    // 0x80800014: jr          $ra
    // 0x80800018: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80800018: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080001C:
    // 0x8080001C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(3130, 0XFFFFFDB8) << 16);
    // 0x80800020: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800024: lw          $v0, -0x248($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(3130, 0XFFFFFDB8));
    // 0x80800028: jr          $ra
    // 0x8080002C: nop

    return;
    // 0x8080002C: nop

;}
RECOMP_FUNC void func_80016934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016934: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80016938: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001693C: bne         $a0, $zero, L_80016954
    if (ctx->r4 != 0) {
        // 0x80016940: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80016954;
    }
    // 0x80016940: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80016944: jal         0x80016A48
    // 0x80016948: nop

    func_80016A48(rdram, ctx);
        goto after_0;
    // 0x80016948: nop

    after_0:
    // 0x8001694C: b           L_8001695C
    // 0x80016950: nop

        goto L_8001695C;
    // 0x80016950: nop

L_80016954:
    // 0x80016954: jal         0x80016A04
    // 0x80016958: nop

    func_80016A04(rdram, ctx);
        goto after_1;
    // 0x80016958: nop

    after_1:
L_8001695C:
    // 0x8001695C: jal         0x800304C0
    // 0x80016960: nop

    __osDisableInt_recomp(rdram, ctx);
        goto after_2;
    // 0x80016960: nop

    after_2:
    // 0x80016964: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80016968: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001696C: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80016970: bne         $t7, $zero, L_80016984
    if (ctx->r15 != 0) {
        // 0x80016974: lw          $t9, 0x18($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X18);
            goto L_80016984;
    }
    // 0x80016974: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80016978: lw          $t8, -0x6088($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6088);
    // 0x8001697C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80016980: bne         $t8, $at, L_80016990
    if (ctx->r24 != ctx->r1) {
        // 0x80016984: lui         $t0, 0x8008
        ctx->r8 = S32(0X8008 << 16);
            goto L_80016990;
    }
L_80016984:
    // 0x80016984: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80016988: addiu       $t0, $t0, -0x6460
    ctx->r8 = ADD32(ctx->r8, -0X6460);
    // 0x8001698C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
L_80016990:
    // 0x80016990: jal         0x80030530
    // 0x80016994: nop

    __osRestoreInt_recomp(rdram, ctx);
        goto after_3;
    // 0x80016994: nop

    after_3:
    // 0x80016998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001699C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800169A0: jr          $ra
    // 0x800169A4: nop

    return;
    // 0x800169A4: nop

;}
RECOMP_FUNC void func_80094AB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094AB4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80094AB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80094ABC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80094AC0: jal         0x80094348
    // 0x80094AC4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80094348(rdram, ctx);
        goto after_0;
    // 0x80094AC4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80094AC8: bne         $v0, $zero, L_80094B04
    if (ctx->r2 != 0) {
        // 0x80094ACC: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80094B04;
    }
    // 0x80094ACC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80094AD0: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80094AD4: jal         0x80094C64
    // 0x80094AD8: lbu         $a1, 0x1($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X1);
    func_80094C64(rdram, ctx);
        goto after_1;
    // 0x80094AD8: lbu         $a1, 0x1($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X1);
    after_1:
    // 0x80094ADC: beq         $v0, $zero, L_80094B04
    if (ctx->r2 == 0) {
        // 0x80094AE0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80094B04;
    }
    // 0x80094AE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80094AE4: jal         0x800883E8
    // 0x80094AE8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    _gcegg_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x80094AE8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x80094AEC: beq         $v0, $zero, L_80094B04
    if (ctx->r2 == 0) {
        // 0x80094AF0: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_80094B04;
    }
    // 0x80094AF0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80094AF4: jal         0x800883E0
    // 0x80094AF8: nop

    _gcegg_entrypoint_5(rdram, ctx);
        goto after_3;
    // 0x80094AF8: nop

    after_3:
    // 0x80094AFC: jal         0x800D1824
    // 0x80094B00: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800D1824(rdram, ctx);
        goto after_4;
    // 0x80094B00: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
L_80094B04:
    // 0x80094B04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80094B08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80094B0C: jr          $ra
    // 0x80094B10: nop

    return;
    // 0x80094B10: nop

;}
RECOMP_FUNC void chbilldrillplate_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1192, 0X116C) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0x116C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1192, 0X116C));
    return;
    // 0x80800020: addiu       $v0, $v0, 0x116C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1192, 0X116C));
;}
RECOMP_FUNC void bamovegoto_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001A8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808001AC: lw          $t6, 0xC8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC8);
    // 0x808001B0: jr          $ra
    // 0x808001B4: swc1        $f12, 0x70($t6)
    MEM_W(0X70, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x808001B4: swc1        $f12, 0x70($t6)
    MEM_W(0X70, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void _bahold_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084D28: syscall     134
    recomp_syscall_handler(rdram, ctx, 0x80084D28);
    return;
    // 0x80084D2C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800F8730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F8730: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F8734: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800F8738: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800F873C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F8740: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x800F8744: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F8748: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F874C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800F8750: jal         0x800A3538
    // 0x800F8754: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_800A3538(rdram, ctx);
        goto after_0;
    // 0x800F8754: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F8758: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F875C: jal         0x8009E7C8
    // 0x800F8760: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_8009E7C8(rdram, ctx);
        goto after_1;
    // 0x800F8760: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_1:
    // 0x800F8764: xori        $v1, $v0, 0x2
    ctx->r3 = ctx->r2 ^ 0X2;
    // 0x800F8768: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x800F876C: beq         $v1, $zero, L_800F8790
    if (ctx->r3 == 0) {
        // 0x800F8770: sw          $v1, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r3;
            goto L_800F8790;
    }
    // 0x800F8770: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x800F8774: jal         0x800F5410
    // 0x800F8778: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800F5410(rdram, ctx);
        goto after_2;
    // 0x800F8778: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x800F877C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800F8780: beql        $v0, $a0, L_800F8794
    if (ctx->r2 == ctx->r4) {
        // 0x800F8784: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800F8794;
    }
    goto skip_0;
    // 0x800F8784: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800F8788: jal         0x8008A7A0
    // 0x800F878C: nop

    _surestart_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x800F878C: nop

    after_3:
L_800F8790:
    // 0x800F8790: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F8794:
    // 0x800F8794: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x800F8798: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F879C: jr          $ra
    // 0x800F87A0: nop

    return;
    // 0x800F87A0: nop

;}
RECOMP_FUNC void _chlavaexplodbuild_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087170: syscall     525
    recomp_syscall_handler(rdram, ctx, 0x80087170);
    return;
    // 0x80087174: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chintrotext_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006C0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808006C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006C8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x808006CC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x808006D0: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x808006D4: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x808006D8: jal         0x800EFD24
    // 0x808006DC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x808006DC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x808006E0: addiu       $a0, $zero, 0x3B0
    ctx->r4 = ADD32(0, 0X3B0);
    // 0x808006E4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x808006E8: jal         0x80108474
    // 0x808006EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80108474(rdram, ctx);
        goto after_1;
    // 0x808006EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x808006F0: beq         $v0, $zero, L_80800770
    if (ctx->r2 == 0) {
        // 0x808006F4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800770;
    }
    // 0x808006F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808006F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808006FC: jal         0x80100094
    // 0x80800700: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80800700: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_2:
    // 0x80800704: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800708: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080070C: jal         0x80088718
    // 0x80800710: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    _gldbstring_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80800710: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_3:
    // 0x80800714: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800718: jal         0x80088720
    // 0x8080071C: lh          $a1, 0x3E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X3E);
    _gldbstring_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x8080071C: lh          $a1, 0x3E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X3E);
    after_4:
    // 0x80800720: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800724: jal         0x800E7188
    // 0x80800728: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800E7188(rdram, ctx);
        goto after_5;
    // 0x80800728: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x8080072C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800730: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800734: jal         0x80100074
    // 0x80800738: addiu       $a2, $v0, 0x1
    ctx->r6 = ADD32(ctx->r2, 0X1);
    func_80100074(rdram, ctx);
        goto after_6;
    // 0x80800738: addiu       $a2, $v0, 0x1
    ctx->r6 = ADD32(ctx->r2, 0X1);
    after_6:
    // 0x8080073C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800740: jal         0x80100094
    // 0x80800744: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_7;
    // 0x80800744: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80800748: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080074C: jal         0x800E715C
    // 0x80800750: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800E715C(rdram, ctx);
        goto after_8;
    // 0x80800750: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_8:
    // 0x80800754: jal         0x80088728
    // 0x80800758: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    _gldbstring_entrypoint_2(rdram, ctx);
        goto after_9;
    // 0x80800758: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_9:
    // 0x8080075C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80800760: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80800764: sb          $t6, 0x3E($v0)
    MEM_B(0X3E, ctx->r2) = ctx->r14;
    // 0x80800768: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8080076C: sb          $t7, 0x3F($v0)
    MEM_B(0X3F, ctx->r2) = ctx->r15;
L_80800770:
    // 0x80800770: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800774: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800778: jr          $ra
    // 0x8080077C: nop

    return;
    // 0x8080077C: nop

;}
RECOMP_FUNC void func_800F0130(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0130: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800F0134: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800F0138: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800F013C: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x800F0140: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x800F0144: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x800F0148: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
    // 0x800F014C: subu        $t1, $t9, $t0
    ctx->r9 = SUB32(ctx->r25, ctx->r8);
    // 0x800F0150: multu       $t1, $t1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F0154: sw          $t1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r9;
    // 0x800F0158: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x800F015C: mflo        $t3
    ctx->r11 = lo;
    // 0x800F0160: nop

    // 0x800F0164: nop

    // 0x800F0168: multu       $t8, $t8
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F016C: mflo        $t5
    ctx->r13 = lo;
    // 0x800F0170: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x800F0174: nop

    // 0x800F0178: multu       $a1, $a1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F017C: mflo        $t7
    ctx->r15 = lo;
    // 0x800F0180: slt         $v0, $t6, $t7
    ctx->r2 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800F0184: jr          $ra
    // 0x800F0188: nop

    return;
    // 0x800F0188: nop

;}
RECOMP_FUNC void func_8008FC9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FC9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FCA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FCA4: jal         0x800F54E4
    // 0x8008FCA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8008FCA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008FCAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008FCB0: jal         0x800F521C
    // 0x8008FCB4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800F521C(rdram, ctx);
        goto after_1;
    // 0x8008FCB4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8008FCB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008FCBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FCC0: jr          $ra
    // 0x8008FCC4: nop

    return;
    // 0x8008FCC4: nop

;}
RECOMP_FUNC void player_inWater(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E35C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008E360: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008E364: jal         0x800A0FD8
    // 0x8008E368: nop

    func_800A0FD8(rdram, ctx);
        goto after_0;
    // 0x8008E368: nop

    after_0:
    // 0x8008E36C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008E370: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008E374: jr          $ra
    // 0x8008E378: nop

    return;
    // 0x8008E378: nop

;}
RECOMP_FUNC void _gsproplookup_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088C90: syscall     732
    recomp_syscall_handler(rdram, ctx, 0x80088C90);
    return;
    // 0x80088C94: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _chclimbbase_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085758: syscall     172
    recomp_syscall_handler(rdram, ctx, 0x80085758);
    return;
    // 0x8008575C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8080422C_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080422C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80804230: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80804234: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80804238: jal         0x80101FDC
    // 0x8080423C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80101FDC(rdram, ctx);
        goto after_0;
    // 0x8080423C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80804240: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80804244: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80804248: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080424C: beq         $a1, $at, L_80804264
    if (ctx->r5 == ctx->r1) {
        // 0x80804250: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80804264;
    }
    // 0x80804250: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80804254: beq         $a1, $at, L_80804264
    if (ctx->r5 == ctx->r1) {
        // 0x80804258: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80804264;
    }
    // 0x80804258: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8080425C: bne         $a1, $at, L_80804280
    if (ctx->r5 != ctx->r1) {
        // 0x80804260: nop
    
            goto L_80804280;
    }
    // 0x80804260: nop

L_80804264:
    // 0x80804264: jal         0x80104248
    // 0x80804268: nop

    func_80104248(rdram, ctx);
        goto after_1;
    // 0x80804268: nop

    after_1:
    // 0x8080426C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80804270: jal         0x8008B134
    // 0x80804274: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_2;
    // 0x80804274: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80804278: b           L_80804298
    // 0x8080427C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80804298;
    // 0x8080427C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80804280:
    // 0x80804280: jal         0x80104248
    // 0x80804284: nop

    func_80104248(rdram, ctx);
        goto after_3;
    // 0x80804284: nop

    after_3:
    // 0x80804288: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080428C: jal         0x8008B134
    // 0x80804290: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_4;
    // 0x80804290: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80804294: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80804298:
    // 0x80804298: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080429C: jr          $ra
    // 0x808042A0: nop

    return;
    // 0x808042A0: nop

;}
RECOMP_FUNC void func_800D3ABC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3ABC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D3AC0: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800D3AC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D3AC8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800D3ACC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800D3AD0: addiu       $a1, $a1, 0x1864
    ctx->r5 = ADD32(ctx->r5, 0X1864);
    // 0x800D3AD4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800D3AD8: jal         0x800D3B6C
    // 0x800D3ADC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D3B6C(rdram, ctx);
        goto after_0;
    // 0x800D3ADC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x800D3AE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D3AE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D3AE8: jr          $ra
    // 0x800D3AEC: nop

    return;
    // 0x800D3AEC: nop

;}
RECOMP_FUNC void func_80800A44_chcactusofstrength(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A44: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800A48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800A50: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800A54: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800A58: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800A5C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800A60: bnel        $t7, $at, L_80800B14
    if (ctx->r15 != ctx->r1) {
        // 0x80800A64: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800B14;
    }
    goto skip_0;
    // 0x80800A64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800A68: jal         0x80100094
    // 0x80800A6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800A6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800A70: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800A74: jal         0x80088FA8
    // 0x80800A78: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _mlwave_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800A78: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800A7C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800A80: lui         $a1, 0xC1A0
    ctx->r5 = S32(0XC1A0 << 16);
    // 0x80800A84: jal         0x80088FC8
    // 0x80800A88: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    _mlwave_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80800A88: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    after_2:
    // 0x80800A8C: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
    // 0x80800A90: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800A94: jal         0x80088FE0
    // 0x80800A98: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    _mlwave_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x80800A98: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    after_3:
    // 0x80800A9C: bne         $v0, $zero, L_80800AB0
    if (ctx->r2 != 0) {
        // 0x80800AA0: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_80800AB0;
    }
    // 0x80800AA0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800AA4: jal         0x80088FE0
    // 0x80800AA8: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    _mlwave_entrypoint_8(rdram, ctx);
        goto after_4;
    // 0x80800AA8: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    after_4:
    // 0x80800AAC: beq         $v0, $zero, L_80800AC4
    if (ctx->r2 == 0) {
        // 0x80800AB0: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(824, 0XE18) << 16);
            goto L_80800AC4;
    }
L_80800AB0:
    // 0x80800AB0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(824, 0XE18) << 16);
    // 0x80800AB4: addiu       $a2, $a2, 0xE18
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(824, 0XE18));
    // 0x80800AB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800ABC: jal         0x80089D18
    // 0x80800AC0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x80800AC0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_5:
L_80800AC4:
    // 0x80800AC4: jal         0x800D9078
    // 0x80800AC8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_6;
    // 0x80800AC8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_6:
    // 0x80800ACC: beq         $v0, $zero, L_80800B10
    if (ctx->r2 == 0) {
        // 0x80800AD0: addiu       $a0, $sp, 0x24
        ctx->r4 = ADD32(ctx->r29, 0X24);
            goto L_80800B10;
    }
    // 0x80800AD0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800AD4: jal         0x800EE7F8
    // 0x80800AD8: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x80800AD8: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_7:
    // 0x80800ADC: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800AE0: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80800AE4: jal         0x800EF1B8
    // 0x80800AE8: lui         $a2, 0xC270
    ctx->r6 = S32(0XC270 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_8;
    // 0x80800AE8: lui         $a2, 0xC270
    ctx->r6 = S32(0XC270 << 16);
    after_8:
    // 0x80800AEC: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80800AF0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800AF4: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800AF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AFC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80800B00: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800B04: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800B08: jal         0x80086670
    // 0x80800B0C: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_9;
    // 0x80800B0C: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    after_9:
L_80800B10:
    // 0x80800B10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800B14:
    // 0x80800B14: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800B18: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800B1C: jr          $ra
    // 0x80800B20: nop

    return;
    // 0x80800B20: nop

;}
RECOMP_FUNC void ncbaswim_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080004C: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80800050: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800054: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800058: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080005C: jal         0x80112524
    // 0x80800060: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    func_80112524(rdram, ctx);
        goto after_0;
    // 0x80800060: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    after_0:
    // 0x80800064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800068: jal         0x801107F0
    // 0x8080006C: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    func_801107F0(rdram, ctx);
        goto after_1;
    // 0x8080006C: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    after_1:
    // 0x80800070: lw          $t6, 0x5C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X5C);
    // 0x80800074: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80800078: beq         $t7, $zero, L_80800094
    if (ctx->r15 == 0) {
        // 0x8080007C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800094;
    }
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800080: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x80800084: jal         0x80089468
    // 0x80800088: addiu       $a2, $sp, 0x74
    ctx->r6 = ADD32(ctx->r29, 0X74);
    _ncbawaypoint_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800088: addiu       $a2, $sp, 0x74
    ctx->r6 = ADD32(ctx->r29, 0X74);
    after_2:
    // 0x8080008C: b           L_808000A0
    // 0x80800090: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
        goto L_808000A0;
    // 0x80800090: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
L_80800094:
    // 0x80800094: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800098: nop

    // 0x8080009C: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
L_808000A0:
    // 0x808000A0: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    // 0x808000A4: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x808000A8: jal         0x800EFB24
    // 0x808000AC: addiu       $a2, $sp, 0x8C
    ctx->r6 = ADD32(ctx->r29, 0X8C);
    func_800EFB24(rdram, ctx);
        goto after_3;
    // 0x808000AC: addiu       $a2, $sp, 0x8C
    ctx->r6 = ADD32(ctx->r29, 0X8C);
    after_3:
    // 0x808000B0: jal         0x800EEF94
    // 0x808000B4: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    func_800EEF94(rdram, ctx);
        goto after_4;
    // 0x808000B4: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    after_4:
    // 0x808000B8: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x808000BC: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    // 0x808000C0: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x808000C4: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x808000C8: jal         0x800F1A88
    // 0x808000CC: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    func_800F1A88(rdram, ctx);
        goto after_5;
    // 0x808000CC: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000D8: jal         0x80113978
    // 0x808000DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80113978(rdram, ctx);
        goto after_6;
    // 0x808000DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x808000E0: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E8: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x808000EC: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x808000F0: jal         0x80115358
    // 0x808000F4: swc1        $f12, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f12.u32l;
    func_80115358(rdram, ctx);
        goto after_7;
    // 0x808000F4: swc1        $f12, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f12.u32l;
    after_7:
    // 0x808000F8: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x808000FC: jal         0x80110840
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80110840(rdram, ctx);
        goto after_8;
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800104: jal         0x800F53D0
    // 0x80800108: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F53D0(rdram, ctx);
        goto after_9;
    // 0x80800108: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_9:
    // 0x8080010C: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80800110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800114: jal         0x80110818
    // 0x80800118: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_80110818(rdram, ctx);
        goto after_10;
    // 0x80800118: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_10:
    // 0x8080011C: jal         0x800852D8
    // 0x80800120: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    _baswim_entrypoint_14(rdram, ctx);
        goto after_11;
    // 0x80800120: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_11:
    // 0x80800124: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80800128: jal         0x8009BFCC
    // 0x8080012C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_8009BFCC(rdram, ctx);
        goto after_12;
    // 0x8080012C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_12:
    // 0x80800130: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800134: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800138: jal         0x800F1DCC
    // 0x8080013C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    func_800F1DCC(rdram, ctx);
        goto after_13;
    // 0x8080013C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    after_13:
    // 0x80800140: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800144: jal         0x8009C984
    // 0x80800148: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    yaw_get(rdram, ctx);
        goto after_14;
    // 0x80800148: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    after_14:
    // 0x8080014C: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800150: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800154: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800158: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x8080015C: jal         0x80013728
    // 0x80800160: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    func_80013728(rdram, ctx);
        goto after_15;
    // 0x80800160: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    after_15:
    // 0x80800164: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800168: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080016C: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800170: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800174: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800178: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x8080017C: sub.s       $f12, $f16, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x80800180: bc1f        L_80800194
    if (!c1cs) {
        // 0x80800184: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_80800194;
    }
    // 0x80800184: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800188: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080018C: b           L_808001BC
    // 0x80800190: sub.s       $f14, $f6, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f0.fl;
        goto L_808001BC;
    // 0x80800190: sub.s       $f14, $f6, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f0.fl;
L_80800194:
    // 0x80800194: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x80800198: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080019C: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
    // 0x808001A0: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x808001A4: nop

    // 0x808001A8: bc1f        L_808001BC
    if (!c1cs) {
        // 0x808001AC: nop
    
            goto L_808001BC;
    }
    // 0x808001AC: nop

    // 0x808001B0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808001B4: nop

    // 0x808001B8: sub.s       $f14, $f10, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f0.fl;
L_808001BC:
    // 0x808001BC: jal         0x80013728
    // 0x808001C0: swc1        $f14, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f14.u32l;
    func_80013728(rdram, ctx);
        goto after_16;
    // 0x808001C0: swc1        $f14, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f14.u32l;
    after_16:
    // 0x808001C4: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808001C8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808001CC: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808001D0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x808001D4: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x808001D8: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x808001DC: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808001E0: bc1fl       L_808001FC
    if (!c1cs) {
        // 0x808001E4: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_808001FC;
    }
    goto skip_0;
    // 0x808001E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_0:
    // 0x808001E8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808001EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808001F0: b           L_8080021C
    // 0x808001F4: sub.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f0.fl;
        goto L_8080021C;
    // 0x808001F4: sub.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x808001F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_808001FC:
    // 0x808001FC: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
    // 0x80800200: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80800204: nop

    // 0x80800208: bc1fl       L_80800220
    if (!c1cs) {
        // 0x8080020C: lui         $at, 0x4461
        ctx->r1 = S32(0X4461 << 16);
            goto L_80800220;
    }
    goto skip_1;
    // 0x8080020C: lui         $at, 0x4461
    ctx->r1 = S32(0X4461 << 16);
    skip_1:
    // 0x80800210: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800214: nop

    // 0x80800218: sub.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f0.fl;
L_8080021C:
    // 0x8080021C: lui         $at, 0x4461
    ctx->r1 = S32(0X4461 << 16);
L_80800220:
    // 0x80800220: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800224: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3050, 0X360) << 16);
    // 0x80800228: lwc1        $f4, 0x360($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3050, 0X360));
    // 0x8080022C: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800230: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80800234: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080023C: mul.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80800240: nop

    // 0x80800244: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80800248: nop

    // 0x8080024C: mul.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x80800250: sub.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f6.fl;
    // 0x80800254: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80800258: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8080025C: swc1        $f12, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f12.u32l;
    // 0x80800260: jal         0x80115750
    // 0x80800264: swc1        $f16, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f16.u32l;
    func_80115750(rdram, ctx);
        goto after_17;
    // 0x80800264: swc1        $f16, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f16.u32l;
    after_17:
    // 0x80800268: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800270: jal         0x80112C3C
    // 0x80800274: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    func_80112C3C(rdram, ctx);
        goto after_18;
    // 0x80800274: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_18:
    // 0x80800278: lwc1        $f2, 0x64($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8080027C: lwc1        $f18, 0x60($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80800280: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x80800284: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    // 0x80800288: sub.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x8080028C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x80800290: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80800294: jal         0x800EEBF0
    // 0x80800298: nop

    func_800EEBF0(rdram, ctx);
        goto after_19;
    // 0x80800298: nop

    after_19:
    // 0x8080029C: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x808002A0: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x808002A4: jal         0x800EE780
    // 0x808002A8: addiu       $a2, $sp, 0x80
    ctx->r6 = ADD32(ctx->r29, 0X80);
    func_800EE780(rdram, ctx);
        goto after_20;
    // 0x808002A8: addiu       $a2, $sp, 0x80
    ctx->r6 = ADD32(ctx->r29, 0X80);
    after_20:
    // 0x808002AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B0: jal         0x80111CC8
    // 0x808002B4: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    func_80111CC8(rdram, ctx);
        goto after_21;
    // 0x808002B4: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    after_21:
    // 0x808002B8: beql        $v0, $zero, L_80800328
    if (ctx->r2 == 0) {
        // 0x808002BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800328;
    }
    goto skip_2;
    // 0x808002BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x808002C0: jal         0x801138A0
    // 0x808002C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801138A0(rdram, ctx);
        goto after_22;
    // 0x808002C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x808002C8: beq         $v0, $zero, L_808002F0
    if (ctx->r2 == 0) {
        // 0x808002CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002F0;
    }
    // 0x808002CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002D0: jal         0x801138F4
    // 0x808002D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801138F4(rdram, ctx);
        goto after_23;
    // 0x808002D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x808002D8: beql        $v0, $zero, L_80800328
    if (ctx->r2 == 0) {
        // 0x808002DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800328;
    }
    goto skip_3;
    // 0x808002DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x808002E0: jal         0x80110F44
    // 0x808002E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80110F44(rdram, ctx);
        goto after_24;
    // 0x808002E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x808002E8: b           L_80800328
    // 0x808002EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800328;
    // 0x808002EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808002F0:
    // 0x808002F0: jal         0x80115580
    // 0x808002F4: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    func_80115580(rdram, ctx);
        goto after_25;
    // 0x808002F4: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    after_25:
    // 0x808002F8: beql        $v0, $zero, L_80800328
    if (ctx->r2 == 0) {
        // 0x808002FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800328;
    }
    goto skip_4;
    // 0x808002FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_4:
    // 0x80800300: jal         0x801155E8
    // 0x80800304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801155E8(rdram, ctx);
        goto after_26;
    // 0x80800304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80800308: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8080030C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800310: nop

    // 0x80800314: bc1fl       L_80800328
    if (!c1cs) {
        // 0x80800318: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800328;
    }
    goto skip_5;
    // 0x80800318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_5:
    // 0x8080031C: jal         0x801138F4
    // 0x80800320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801138F4(rdram, ctx);
        goto after_27;
    // 0x80800320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x80800324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800328:
    // 0x80800328: jal         0x80112524
    // 0x8080032C: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    func_80112524(rdram, ctx);
        goto after_28;
    // 0x8080032C: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    after_28:
    // 0x80800330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800334: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    // 0x80800338: jal         0x80110A68
    // 0x8080033C: addiu       $a2, $sp, 0x8C
    ctx->r6 = ADD32(ctx->r29, 0X8C);
    func_80110A68(rdram, ctx);
        goto after_29;
    // 0x8080033C: addiu       $a2, $sp, 0x8C
    ctx->r6 = ADD32(ctx->r29, 0X8C);
    after_29:
    // 0x80800340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800344: jal         0x80110790
    // 0x80800348: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    func_80110790(rdram, ctx);
        goto after_30;
    // 0x80800348: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    after_30:
    // 0x8080034C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800350: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800354: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    // 0x80800358: jr          $ra
    // 0x8080035C: nop

    return;
    // 0x8080035C: nop

;}
RECOMP_FUNC void func_80800A24_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800A28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A2C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800A30: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800A34: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800A38: jal         0x80100094
    // 0x80800A3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800A3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800A40: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800A44: jal         0x808007F0
    // 0x80800A48: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_808007F0_chhandcart(rdram, ctx);
        goto after_1;
    // 0x80800A48: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800A4C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A50: lbu         $t7, 0x8F4($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X8F4);
    // 0x80800A54: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x80800A58: beq         $at, $zero, L_80800AA0
    if (ctx->r1 == 0) {
        // 0x80800A5C: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800AA0;
    }
    // 0x80800A5C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800A60: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X4414) << 16);
    // 0x80800A64: addu        $at, $at, $t7
    gpr jr_addend_80800A6C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800A68: lw          $t7, 0x4414($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1632, 0X4414));
    // 0x80800A6C: jr          $t7
    // 0x80800A70: nop

    switch (jr_addend_80800A6C >> 2) {
        case 0: goto L_80800A74; break;
        case 1: goto L_80800A80; break;
        case 2: goto L_80800A80; break;
        case 3: goto L_80800A8C; break;
        case 4: goto L_80800A80; break;
        default: switch_error(__func__, 0x80800A6C, 0x80804414);
    }
    // 0x80800A70: nop

L_80800A74:
    // 0x80800A74: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800A78: jal         0x808007BC
    // 0x80800A7C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_808007BC_chhandcart(rdram, ctx);
        goto after_2;
    // 0x80800A7C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_2:
L_80800A80:
    // 0x80800A80: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A84: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80800A88: sb          $t8, 0x8F4($t9)
    MEM_B(0X8F4, ctx->r25) = ctx->r24;
L_80800A8C:
    // 0x80800A8C: jal         0x800856E0
    // 0x80800A90: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _capod_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x80800A90: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80800A94: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800A98: jal         0x808002B8
    // 0x80800A9C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_808002B8_chhandcart(rdram, ctx);
        goto after_4;
    // 0x80800A9C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_4:
L_80800AA0:
    // 0x80800AA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800AA4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800AA8: jr          $ra
    // 0x80800AAC: nop

    return;
    // 0x80800AAC: nop

;}
RECOMP_FUNC void _fxrain_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800888E0: syscall     710
    recomp_syscall_handler(rdram, ctx, 0x800888E0);
    return;
    // 0x800888E4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _bssub_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083D40: syscall     93
    recomp_syscall_handler(rdram, ctx, 0x80083D40);
    return;
    // 0x80083D44: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chfantasybounce_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085C20: syscall     210
    recomp_syscall_handler(rdram, ctx, 0x80085C20);
    return;
    // 0x80085C24: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8080045C_chclinker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080045C: addiu       $sp, $sp, -0xF8
    ctx->r29 = ADD32(ctx->r29, -0XF8);
    // 0x80800460: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800464: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80800468: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8080046C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800470: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800474: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80800478: sw          $a0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r4;
    // 0x8080047C: lw          $s0, 0x0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X0);
    // 0x80800480: addiu       $a0, $zero, 0x2BA
    ctx->r4 = ADD32(0, 0X2BA);
    // 0x80800484: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x80800488: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    // 0x8080048C: jal         0x800882C0
    // 0x80800490: lw          $s3, 0x0($s0)
    ctx->r19 = MEM_W(ctx->r16, 0X0);
    _gccubesearch_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x80800490: lw          $s3, 0x0($s0)
    ctx->r19 = MEM_W(ctx->r16, 0X0);
    after_0:
    // 0x80800494: blez        $v0, L_8080051C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800498: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_8080051C;
    }
    // 0x80800498: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8080049C: addiu       $s0, $sp, 0x50
    ctx->r16 = ADD32(ctx->r29, 0X50);
    // 0x808004A0: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x808004A4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2208, 0X12F4) << 16);
    // 0x808004A8: lwc1        $f20, 0x12F4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2208, 0X12F4));
    // 0x808004AC: addu        $s1, $t8, $s0
    ctx->r17 = ADD32(ctx->r24, ctx->r16);
L_808004B0:
    // 0x808004B0: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x808004B4: addiu       $a0, $zero, 0x2C1
    ctx->r4 = ADD32(0, 0X2C1);
    // 0x808004B8: lw          $a2, 0xC($a1)
    ctx->r6 = MEM_W(ctx->r5, 0XC);
    // 0x808004BC: srl         $t9, $a2, 23
    ctx->r25 = S32(U32(ctx->r6) >> 23);
    // 0x808004C0: jal         0x801085CC
    // 0x808004C4: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    func_801085CC(rdram, ctx);
        goto after_1;
    // 0x808004C4: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_1:
    // 0x808004C8: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x808004CC: lui         $at, 0x7F
    ctx->r1 = S32(0X7F << 16);
    // 0x808004D0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x808004D4: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x808004D8: and         $t2, $t1, $at
    ctx->r10 = ctx->r9 & ctx->r1;
    // 0x808004DC: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x808004E0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808004E4: bgez        $t2, L_808004F8
    if (SIGNED(ctx->r10) >= 0) {
        // 0x808004E8: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_808004F8;
    }
    // 0x808004E8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808004EC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808004F0: nop

    // 0x808004F4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_808004F8:
    // 0x808004F8: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x808004FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800500: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800504: jal         0x80100094
    // 0x80800508: swc1        $f10, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f10.u32l;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80800508: swc1        $f10, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f10.u32l;
    after_2:
    // 0x8080050C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800510: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x80800514: bne         $at, $zero, L_808004B0
    if (ctx->r1 != 0) {
        // 0x80800518: sw          $s3, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r19;
            goto L_808004B0;
    }
    // 0x80800518: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
L_8080051C:
    // 0x8080051C: jal         0x80106790
    // 0x80800520: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80106790(rdram, ctx);
        goto after_3;
    // 0x80800520: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_3:
    // 0x80800524: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800528: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080052C: jal         0x80100094
    // 0x80800530: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x80800530: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800534: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x80800538: lw          $t3, 0xF8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF8);
    // 0x8080053C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800540: beq         $s2, $zero, L_80800550
    if (ctx->r18 == 0) {
        // 0x80800544: sw          $s0, 0x0($t3)
        MEM_W(0X0, ctx->r11) = ctx->r16;
            goto L_80800550;
    }
    // 0x80800544: sw          $s0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r16;
    // 0x80800548: b           L_80800550
    // 0x8080054C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80800550;
    // 0x8080054C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80800550:
    // 0x80800550: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800554: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800558: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8080055C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800560: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80800564: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80800568: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
    // 0x8080056C: jr          $ra
    // 0x80800570: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80800570: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void _glrecord_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088698: syscall     698
    recomp_syscall_handler(rdram, ctx, 0x80088698);
    return;
    // 0x8008869C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8080000C_suegg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800018: jal         0x80100094
    // 0x8080001C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080001C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800020: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800024: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800028: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x8080002C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800030: jal         0x800EC3E8
    // 0x80800034: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800EC3E8(rdram, ctx);
        goto after_1;
    // 0x80800034: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_1:
    // 0x80800038: jal         0x800AF5A0
    // 0x8080003C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800AF5A0(rdram, ctx);
        goto after_2;
    // 0x8080003C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800040: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800044: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800048: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080004C: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x80800050: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x80800054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800058: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080005C: jr          $ra
    // 0x80800060: nop

    return;
    // 0x80800060: nop

;}
RECOMP_FUNC void gcsectionDll_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001BC: jal         0x808000F0
    // 0x808001C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808000F0_gcsectionDll(rdram, ctx);
        goto after_0;
    // 0x808001C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808001C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001C8: lbu         $v0, 0x4($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4);
    // 0x808001CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001D0: jr          $ra
    // 0x808001D4: nop

    return;
    // 0x808001D4: nop

;}
RECOMP_FUNC void _ncbaspiral_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089180: syscall     764
    recomp_syscall_handler(rdram, ctx, 0x80089180);
    return;
    // 0x80089184: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_8080041C_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080041C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800420: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800424: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800428: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080042C: jal         0x808026F8
    // 0x80800430: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_808026F8_chdiggerboss(rdram, ctx);
        goto after_0;
    // 0x80800430: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800434: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800438: jal         0x80100094
    // 0x8080043C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x8080043C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800440: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800448: jal         0x80102424
    // 0x8080044C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x8080044C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x80800450: jal         0x801022E4
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801022E4(rdram, ctx);
        goto after_3;
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800458: addiu       $at, $zero, 0x429
    ctx->r1 = ADD32(0, 0X429);
    // 0x8080045C: beq         $v0, $at, L_80800484
    if (ctx->r2 == ctx->r1) {
        // 0x80800460: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800484;
    }
    // 0x80800460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800464: addiu       $at, $zero, 0x42B
    ctx->r1 = ADD32(0, 0X42B);
    // 0x80800468: beq         $v0, $at, L_808004A8
    if (ctx->r2 == ctx->r1) {
        // 0x8080046C: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_808004A8;
    }
    // 0x8080046C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800470: addiu       $at, $zero, 0x42D
    ctx->r1 = ADD32(0, 0X42D);
    // 0x80800474: beq         $v0, $at, L_808004D8
    if (ctx->r2 == ctx->r1) {
        // 0x80800478: lw          $t8, 0x20($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X20);
            goto L_808004D8;
    }
    // 0x80800478: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8080047C: b           L_808004E0
    // 0x80800480: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808004E0;
    // 0x80800480: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800484:
    // 0x80800484: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800488: jal         0x808008C0
    // 0x8080048C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_808008C0_chdiggerboss(rdram, ctx);
        goto after_4;
    // 0x8080048C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80800490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800494: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800498: jal         0x808008C0
    // 0x8080049C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_808008C0_chdiggerboss(rdram, ctx);
        goto after_5;
    // 0x8080049C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x808004A0: b           L_808004E0
    // 0x808004A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808004E0;
    // 0x808004A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808004A8:
    // 0x808004A8: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x808004AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004B0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808004B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808004B8: jal         0x808008C0
    // 0x808004BC: sh          $t6, 0x80($t7)
    MEM_H(0X80, ctx->r15) = ctx->r14;
    func_808008C0_chdiggerboss(rdram, ctx);
        goto after_6;
    // 0x808004BC: sh          $t6, 0x80($t7)
    MEM_H(0X80, ctx->r15) = ctx->r14;
    after_6:
    // 0x808004C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808004C8: jal         0x808008C0
    // 0x808004CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_808008C0_chdiggerboss(rdram, ctx);
        goto after_7;
    // 0x808004CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x808004D0: b           L_808004E0
    // 0x808004D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808004E0;
    // 0x808004D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808004D8:
    // 0x808004D8: sh          $zero, 0x80($t8)
    MEM_H(0X80, ctx->r24) = 0;
    // 0x808004DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808004E0:
    // 0x808004E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808004E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808004E8: jr          $ra
    // 0x808004EC: nop

    return;
    // 0x808004EC: nop

;}
