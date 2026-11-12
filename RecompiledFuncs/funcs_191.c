#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void baflameline_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8080000C: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x80800010: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80800014: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80800018: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x8080001C: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x80800020: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x80800024: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x80800028: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x8080002C: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x80800030: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x80800034: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x80800038: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x8080003C: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80800040: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80800044: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800048: jal         0x800B53A4
    // 0x8080004C: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800B53A4(rdram, ctx);
        goto after_0;
    // 0x8080004C: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_0:
    // 0x80800050: lw          $v1, 0x84($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X84);
    // 0x80800054: addiu       $s3, $sp, 0x90
    ctx->r19 = ADD32(ctx->r29, 0X90);
    // 0x80800058: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8080005C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800060: addiu       $a1, $v1, 0xC
    ctx->r5 = ADD32(ctx->r3, 0XC);
    // 0x80800064: jal         0x800EFA20
    // 0x80800068: lw          $a2, 0x18($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X18);
    func_800EFA20(rdram, ctx);
        goto after_1;
    // 0x80800068: lw          $a2, 0x18($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X18);
    after_1:
    // 0x8080006C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800070: jal         0x800EF04C
    // 0x80800074: lw          $a1, 0x84($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X84);
    func_800EF04C(rdram, ctx);
        goto after_2;
    // 0x80800074: lw          $a1, 0x84($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X84);
    after_2:
    // 0x80800078: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(520, 0X6D0) << 16);
    // 0x8080007C: lwc1        $f30, 0x6D0($at)
    ctx->f30.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(520, 0X6D0));
    // 0x80800080: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(520, 0X6D4) << 16);
    // 0x80800084: lwc1        $f28, 0x6D4($at)
    ctx->f28.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(520, 0X6D4));
    // 0x80800088: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8080008C: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80800090: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800094: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80800098: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080009C: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(520, 0X6F0) << 16);
    // 0x808000A0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x808000A4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x808000A8: addiu       $s4, $s4, 0x6F0
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(520, 0X6F0));
    // 0x808000AC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808000B0: addiu       $s5, $zero, 0x7
    ctx->r21 = ADD32(0, 0X7);
    // 0x808000B4: addiu       $s2, $sp, 0x84
    ctx->r18 = ADD32(ctx->r29, 0X84);
    // 0x808000B8: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
L_808000BC:
    // 0x808000BC: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x808000C0: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x808000C4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808000C8: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x808000CC: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x808000D0: add.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x808000D4: jal         0x800F10B4
    // 0x808000D8: div.s       $f12, $f8, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f26.fl);
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x808000D8: div.s       $f12, $f8, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f26.fl);
    after_3:
    // 0x808000DC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808000E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808000E4: lw          $a1, 0x84($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X84);
    // 0x808000E8: jal         0x800EFE50
    // 0x808000EC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_800EFE50(rdram, ctx);
        goto after_4;
    // 0x808000EC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_4:
    // 0x808000F0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x808000F4: jal         0x800DC178
    // 0x808000F8: mov.s       $f14, $f30
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    ctx->f14.fl = ctx->f30.fl;
    func_800DC178(rdram, ctx);
        goto after_5;
    // 0x808000F8: mov.s       $f14, $f30
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    ctx->f14.fl = ctx->f30.fl;
    after_5:
    // 0x808000FC: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800100: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800104: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800108: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080010C: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80800110: nop

    // 0x80800114: sll         $t7, $a3, 16
    ctx->r15 = S32(ctx->r7 << 16);
    // 0x80800118: jal         0x800BA77C
    // 0x8080011C: sra         $a3, $t7, 16
    ctx->r7 = S32(SIGNED(ctx->r15) >> 16);
    func_800BA77C(rdram, ctx);
        goto after_6;
    // 0x8080011C: sra         $a3, $t7, 16
    ctx->r7 = S32(SIGNED(ctx->r15) >> 16);
    after_6:
    // 0x80800120: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800124: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80800128: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080012C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800130: jal         0x800BABB8
    // 0x80800134: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    func_800BABB8(rdram, ctx);
        goto after_7;
    // 0x80800134: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_7:
    // 0x80800138: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8080013C: bnel        $s0, $s5, L_808000BC
    if (ctx->r16 != ctx->r21) {
        // 0x80800140: mtc1        $s0, $f4
        ctx->f4.u32l = ctx->r16;
            goto L_808000BC;
    }
    goto skip_0;
    // 0x80800140: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    skip_0:
    // 0x80800144: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80800148: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8080014C: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80800150: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80800154: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80800158: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x8080015C: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x80800160: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x80800164: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x80800168: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x8080016C: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x80800170: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x80800174: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x80800178: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x8080017C: jr          $ra
    // 0x80800180: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x80800180: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void subaddiefx_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x80800004: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r20;
    // 0x8080000C: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
    // 0x80800010: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800014: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x80800018: sw          $s5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r21;
    // 0x8080001C: sw          $s3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r19;
    // 0x80800020: sw          $s2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r18;
    // 0x80800024: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
    // 0x80800028: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x8080002C: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80800030: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80800034: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80800038: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8080003C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800040: jal         0x80103EAC
    // 0x80800044: sw          $a0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r4;
    func_80103EAC(rdram, ctx);
        goto after_0;
    // 0x80800044: sw          $a0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800048: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8080004C: jal         0x8010A40C
    // 0x80800050: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    func_8010A40C(rdram, ctx);
        goto after_1;
    // 0x80800050: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    after_1:
    // 0x80800054: mul.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80800058: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8080005C: addiu       $s5, $sp, 0xBC
    ctx->r21 = ADD32(ctx->r29, 0XBC);
    // 0x80800060: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80800064: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x80800068: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080006C: beq         $s0, $at, L_80800084
    if (ctx->r16 == ctx->r1) {
        // 0x80800070: swc1        $f4, 0xB8($sp)
        MEM_W(0XB8, ctx->r29) = ctx->f4.u32l;
            goto L_80800084;
    }
    // 0x80800070: swc1        $f4, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f4.u32l;
    // 0x80800074: jal         0x8008A0E0
    // 0x80800078: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800078: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_2:
    // 0x8080007C: bnel        $v0, $zero, L_808000BC
    if (ctx->r2 != 0) {
        // 0x80800080: lw          $t7, 0xC8($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XC8);
            goto L_808000BC;
    }
    goto skip_0;
    // 0x80800080: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
    skip_0:
L_80800084:
    // 0x80800084: lw          $a1, 0xC8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC8);
    // 0x80800088: addiu       $s5, $sp, 0xBC
    ctx->r21 = ADD32(ctx->r29, 0XBC);
    // 0x8080008C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800090: jal         0x800EE7F8
    // 0x80800094: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800094: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_3:
    // 0x80800098: jal         0x80103EF4
    // 0x8080009C: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    func_80103EF4(rdram, ctx);
        goto after_4;
    // 0x8080009C: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    after_4:
    // 0x808000A0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3254, 0X4D0) << 16);
    // 0x808000A4: lwc1        $f8, 0x4D0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3254, 0X4D0));
    // 0x808000A8: lwc1        $f6, 0xC0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x808000AC: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x808000B0: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x808000B4: swc1        $f16, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f16.u32l;
    // 0x808000B8: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
L_808000BC:
    // 0x808000BC: lw          $t8, 0x7C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X7C);
    // 0x808000C0: sll         $t0, $t8, 19
    ctx->r8 = S32(ctx->r24 << 19);
    // 0x808000C4: bgez        $t0, L_80800344
    if (SIGNED(ctx->r8) >= 0) {
        // 0x808000C8: nop
    
            goto L_80800344;
    }
    // 0x808000C8: nop

    // 0x808000CC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x808000D0: jal         0x800D8FF8
    // 0x808000D4: mov.s       $f28, $f22
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 22);
    ctx->f28.fl = ctx->f22.fl;
    func_800D8FF8(rdram, ctx);
        goto after_5;
    // 0x808000D4: mov.s       $f28, $f22
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 22);
    ctx->f28.fl = ctx->f22.fl;
    after_5:
    // 0x808000D8: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    // 0x808000DC: lh          $t1, 0x4($s4)
    ctx->r9 = MEM_H(ctx->r20, 0X4);
    // 0x808000E0: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x808000E4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808000E8: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x808000EC: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x808000F0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x808000F4: mul.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x808000F8: swc1        $f8, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f8.u32l;
    // 0x808000FC: lh          $t2, 0x6($s4)
    ctx->r10 = MEM_H(ctx->r20, 0X6);
    // 0x80800100: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80800104: nop

    // 0x80800108: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8080010C: mul.s       $f30, $f10, $f2
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f30.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80800110: jal         0x800B5BE4
    // 0x80800114: nop

    func_800B5BE4(rdram, ctx);
        goto after_6;
    // 0x80800114: nop

    after_6:
    // 0x80800118: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    // 0x8080011C: jal         0x800B5BE4
    // 0x80800120: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_800B5BE4(rdram, ctx);
        goto after_7;
    // 0x80800120: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_7:
    // 0x80800124: sw          $v0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r2;
    // 0x80800128: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x8080012C: jal         0x800BA3FC
    // 0x80800130: addiu       $a1, $zero, 0x9E0
    ctx->r5 = ADD32(0, 0X9E0);
    func_800BA3FC(rdram, ctx);
        goto after_8;
    // 0x80800130: addiu       $a1, $zero, 0x9E0
    ctx->r5 = ADD32(0, 0X9E0);
    after_8:
    // 0x80800134: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x80800138: jal         0x800BA3FC
    // 0x8080013C: addiu       $a1, $zero, 0x9E9
    ctx->r5 = ADD32(0, 0X9E9);
    func_800BA3FC(rdram, ctx);
        goto after_9;
    // 0x8080013C: addiu       $a1, $zero, 0x9E9
    ctx->r5 = ADD32(0, 0X9E9);
    after_9:
    // 0x80800140: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800144: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80800148: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8080014C: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(3254, 0X4E0) << 16);
    // 0x80800150: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80800154: addiu       $s3, $s3, 0x4E0
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(3254, 0X4E0));
    // 0x80800158: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8080015C: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    // 0x80800160: addiu       $s1, $sp, 0xAC
    ctx->r17 = ADD32(ctx->r29, 0XAC);
    // 0x80800164: addiu       $s0, $sp, 0xA0
    ctx->r16 = ADD32(ctx->r29, 0XA0);
L_80800168:
    // 0x80800168: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x8080016C: lwc1        $f8, 0xB8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800174: sra         $t4, $t3, 17
    ctx->r12 = S32(SIGNED(ctx->r11) >> 17);
    // 0x80800178: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x8080017C: add.s       $f22, $f8, $f28
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f22.fl = ctx->f8.fl + ctx->f28.fl;
    // 0x80800180: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800184: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80800188: add.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x8080018C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80800190: jal         0x800EEB9C
    // 0x80800194: nop

    func_800EEB9C(rdram, ctx);
        goto after_10;
    // 0x80800194: nop

    after_10:
    // 0x80800198: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080019C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x808001A0: jal         0x800EE780
    // 0x808001A4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800EE780(rdram, ctx);
        goto after_11;
    // 0x808001A4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_11:
    // 0x808001A8: lwc1        $f6, 0x8C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x808001AC: jal         0x80013970
    // 0x808001B0: add.s       $f12, $f6, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f20.fl;
    func_80013970(rdram, ctx);
        goto after_12;
    // 0x808001B0: add.s       $f12, $f6, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f20.fl;
    after_12:
    // 0x808001B4: mul.s       $f16, $f24, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x808001B8: lwc1        $f10, 0xB0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x808001BC: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x808001C0: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x808001C4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808001C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808001CC: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x808001D0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x808001D4: jal         0x800BABB8
    // 0x808001D8: swc1        $f18, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f18.u32l;
    func_800BABB8(rdram, ctx);
        goto after_13;
    // 0x808001D8: swc1        $f18, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f18.u32l;
    after_13:
    // 0x808001DC: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x808001E0: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x808001E4: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x808001E8: sll         $t6, $t5, 15
    ctx->r14 = S32(ctx->r13 << 15);
    // 0x808001EC: sra         $t7, $t6, 17
    ctx->r15 = S32(SIGNED(ctx->r14) >> 17);
    // 0x808001F0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x808001F4: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001FC: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800200: add.s       $f6, $f8, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x80800204: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800208: jal         0x800EEB9C
    // 0x8080020C: nop

    func_800EEB9C(rdram, ctx);
        goto after_14;
    // 0x8080020C: nop

    after_14:
    // 0x80800210: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800214: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80800218: jal         0x800EE780
    // 0x8080021C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800EE780(rdram, ctx);
        goto after_15;
    // 0x8080021C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_15:
    // 0x80800220: jal         0x80013970
    // 0x80800224: add.s       $f12, $f30, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f30.fl + ctx->f20.fl;
    func_80013970(rdram, ctx);
        goto after_16;
    // 0x80800224: add.s       $f12, $f30, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f30.fl + ctx->f20.fl;
    after_16:
    // 0x80800228: mul.s       $f16, $f24, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x8080022C: lwc1        $f10, 0xB0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x80800230: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x80800234: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x80800238: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8080023C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800240: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80800244: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80800248: jal         0x800BABB8
    // 0x8080024C: swc1        $f18, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f18.u32l;
    func_800BABB8(rdram, ctx);
        goto after_17;
    // 0x8080024C: swc1        $f18, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f18.u32l;
    after_17:
    // 0x80800250: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800254: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800258: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080025C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800260: bne         $s2, $at, L_80800168
    if (ctx->r18 != ctx->r1) {
        // 0x80800264: add.s       $f20, $f20, $f4
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f4.fl;
            goto L_80800168;
    }
    // 0x80800264: add.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f4.fl;
    // 0x80800268: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x8080026C: lui         $at, 0x43C3
    ctx->r1 = S32(0X43C3 << 16);
    // 0x80800270: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800274: lwc1        $f6, 0x94($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80800278: sra         $t9, $t8, 17
    ctx->r25 = S32(SIGNED(ctx->r24) >> 17);
    // 0x8080027C: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80800280: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80800284: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800288: jal         0x800136E4
    // 0x8080028C: add.s       $f12, $f18, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f10.fl;
    func_800136E4(rdram, ctx);
        goto after_18;
    // 0x8080028C: add.s       $f12, $f18, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f10.fl;
    after_18:
    // 0x80800290: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800294: lh          $t6, 0x0($s4)
    ctx->r14 = MEM_H(ctx->r20, 0X0);
    // 0x80800298: lui         $at, 0x43D7
    ctx->r1 = S32(0X43D7 << 16);
    // 0x8080029C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808002A0: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x808002A4: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x808002A8: sll         $t5, $t3, 1
    ctx->r13 = S32(ctx->r11 << 1);
    // 0x808002AC: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x808002B0: sh          $t8, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r24;
    // 0x808002B4: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x808002B8: lwc1        $f6, 0x94($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X94);
    // 0x808002BC: sll         $t0, $t9, 15
    ctx->r8 = S32(ctx->r25 << 15);
    // 0x808002C0: sra         $t1, $t0, 17
    ctx->r9 = S32(SIGNED(ctx->r8) >> 17);
    // 0x808002C4: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x808002C8: mul.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x808002CC: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x808002D0: jal         0x800136E4
    // 0x808002D4: sub.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f16.fl;
    func_800136E4(rdram, ctx);
        goto after_19;
    // 0x808002D4: sub.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f16.fl;
    after_19:
    // 0x808002D8: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808002DC: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x808002E0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808002E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808002E8: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x808002EC: srl         $t5, $v0, 2
    ctx->r13 = S32(U32(ctx->r2) >> 2);
    // 0x808002F0: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x808002F4: xor         $t7, $t6, $t5
    ctx->r15 = ctx->r14 ^ ctx->r13;
    // 0x808002F8: sll         $t8, $t7, 17
    ctx->r24 = S32(ctx->r15 << 17);
    // 0x808002FC: srl         $t9, $t8, 15
    ctx->r25 = S32(U32(ctx->r24) >> 15);
    // 0x80800300: xor         $t0, $t9, $v0
    ctx->r8 = ctx->r25 ^ ctx->r2;
    // 0x80800304: sw          $t0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r8;
    // 0x80800308: lwc1        $f8, 0x94($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8080030C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800310: lwc1        $f10, 0x8C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80800314: mul.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80800318: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x8080031C: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80800320: add.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80800324: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800328: add.s       $f30, $f30, $f6
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f30.fl = ctx->f30.fl + ctx->f6.fl;
    // 0x8080032C: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    // 0x80800330: mul.s       $f18, $f10, $f30
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f30.fl);
    // 0x80800334: trunc.w.s   $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80800338: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
    // 0x8080033C: nop

    // 0x80800340: sh          $t2, 0x4($s4)
    MEM_H(0X4, ctx->r20) = ctx->r10;
L_80800344:
    // 0x80800344: jal         0x80104118
    // 0x80800348: nop

    func_80104118(rdram, ctx);
        goto after_20;
    // 0x80800348: nop

    after_20:
    // 0x8080034C: lh          $t3, 0xE($v0)
    ctx->r11 = MEM_H(ctx->r2, 0XE);
    // 0x80800350: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800358: beq         $t3, $zero, L_80800370
    if (ctx->r11 == 0) {
        // 0x8080035C: nop
    
            goto L_80800370;
    }
    // 0x8080035C: nop

    // 0x80800360: lbu         $t4, 0xD($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0XD);
    // 0x80800364: addiu       $s1, $sp, 0x70
    ctx->r17 = ADD32(ctx->r29, 0X70);
    // 0x80800368: bne         $t4, $zero, L_80800384
    if (ctx->r12 != 0) {
        // 0x8080036C: nop
    
            goto L_80800384;
    }
    // 0x8080036C: nop

L_80800370:
    // 0x80800370: jal         0x800EE7F8
    // 0x80800374: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_21;
    // 0x80800374: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_21:
    // 0x80800378: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080037C: b           L_808003C0
    // 0x80800380: sb          $t6, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r14;
        goto L_808003C0;
    // 0x80800380: sb          $t6, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r14;
L_80800384:
    // 0x80800384: jal         0x800E3980
    // 0x80800388: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800E3980(rdram, ctx);
        goto after_22;
    // 0x80800388: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_22:
    // 0x8080038C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800390: jal         0x800EEB40
    // 0x80800394: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800EEB40(rdram, ctx);
        goto after_23;
    // 0x80800394: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_23:
    // 0x80800398: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8080039C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808003A0: jal         0x800EEB40
    // 0x808003A4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EEB40(rdram, ctx);
        goto after_24;
    // 0x808003A4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_24:
    // 0x808003A8: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x808003AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003B0: bc1fl       L_808003C4
    if (!c1cs) {
        // 0x808003B4: lw          $t5, 0xC8($sp)
        ctx->r13 = MEM_W(ctx->r29, 0XC8);
            goto L_808003C4;
    }
    goto skip_1;
    // 0x808003B4: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    skip_1:
    // 0x808003B8: jal         0x800EE7F8
    // 0x808003BC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_25;
    // 0x808003BC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_25:
L_808003C0:
    // 0x808003C0: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
L_808003C4:
    // 0x808003C4: lbu         $a0, 0xC($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XC);
    // 0x808003C8: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(3254, 0X500) << 16);
    // 0x808003CC: lw          $t7, 0x70($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X70);
    // 0x808003D0: addiu       $a3, $a3, 0x500
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(3254, 0X500));
    // 0x808003D4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808003D8: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x808003DC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808003E0: jal         0x80089D68
    // 0x808003E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_7(rdram, ctx);
        goto after_26;
    // 0x808003E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_26:
    // 0x808003E8: sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // 0x808003EC: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x808003F0: andi        $t0, $t9, 0x3
    ctx->r8 = ctx->r25 & 0X3;
    // 0x808003F4: bnel        $t0, $zero, L_8080041C
    if (ctx->r8 != 0) {
        // 0x808003F8: lw          $ra, 0x64($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X64);
            goto L_8080041C;
    }
    goto skip_2;
    // 0x808003F8: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    skip_2:
    // 0x808003FC: lbu         $t1, 0x3($s4)
    ctx->r9 = MEM_BU(ctx->r20, 0X3);
    // 0x80800400: andi        $t2, $t1, 0xFFFC
    ctx->r10 = ctx->r9 & 0XFFFC;
    // 0x80800404: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x80800408: sb          $t3, 0x3($s4)
    MEM_B(0X3, ctx->r20) = ctx->r11;
    // 0x8080040C: lh          $t4, 0xE($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XE);
    // 0x80800410: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x80800414: sh          $t6, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r14;
    // 0x80800418: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_8080041C:
    // 0x8080041C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800420: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800424: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80800428: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8080042C: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80800430: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80800434: lw          $s0, 0x4C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4C);
    // 0x80800438: lw          $s1, 0x50($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X50);
    // 0x8080043C: lw          $s2, 0x54($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X54);
    // 0x80800440: lw          $s3, 0x58($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X58);
    // 0x80800444: lw          $s4, 0x5C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X5C);
    // 0x80800448: lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60);
    // 0x8080044C: jr          $ra
    // 0x80800450: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x80800450: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void func_8009AD70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009AD70: jr          $ra
    // 0x8009AD74: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    return;
    // 0x8009AD74: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
;}
RECOMP_FUNC void func_80804A8C_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804A8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80804A90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80804A94: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80804A98: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80804A9C: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
    // 0x80804AA0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80804AA4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80804AA8: blez        $t6, L_80804AE0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80804AAC: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_80804AE0;
    }
    // 0x80804AAC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80804AB0: jal         0x80087D38
    // 0x80804AB4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    _gcnewoption_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80804AB4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80804AB8: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80804ABC: addiu       $a2, $v0, 0x1
    ctx->r6 = ADD32(ctx->r2, 0X1);
    // 0x80804AC0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80804AC4: lw          $t7, 0x18($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X18);
    // 0x80804AC8: slt         $at, $a2, $t7
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80804ACC: bne         $at, $zero, L_80804AD8
    if (ctx->r1 != 0) {
        // 0x80804AD0: nop
    
            goto L_80804AD8;
    }
    // 0x80804AD0: nop

    // 0x80804AD4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80804AD8:
    // 0x80804AD8: jal         0x808049E8
    // 0x80804ADC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_808049E8_chgameselect(rdram, ctx);
        goto after_1;
    // 0x80804ADC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
L_80804AE0:
    // 0x80804AE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80804AE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80804AE8: jr          $ra
    // 0x80804AEC: nop

    return;
    // 0x80804AEC: nop

;}
RECOMP_FUNC void func_80800024_chfactorytoxicpools(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800028: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080002C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800030: jal         0x80100094
    // 0x80800034: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800034: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800038: addiu       $a0, $zero, 0x18E
    ctx->r4 = ADD32(0, 0X18E);
    // 0x8080003C: jal         0x800DA298
    // 0x80800040: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800040: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800044: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800048: addiu       $a1, $zero, 0x18E
    ctx->r5 = ADD32(0, 0X18E);
    // 0x8080004C: jal         0x80085808
    // 0x80800050: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    _chswitch_entrypoint_7(rdram, ctx);
        goto after_2;
    // 0x80800050: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_2:
    // 0x80800054: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800058: beq         $v0, $zero, L_8080007C
    if (ctx->r2 == 0) {
        // 0x8080005C: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_8080007C;
    }
    // 0x8080005C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800060: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800064: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800068: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8080006C: jal         0x80103110
    // 0x80800070: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80103110(rdram, ctx);
        goto after_3;
    // 0x80800070: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_3:
    // 0x80800074: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800078: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_8080007C:
    // 0x8080007C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80800080: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800084: addiu       $t6, $zero, 0x384
    ctx->r14 = ADD32(0, 0X384);
    // 0x80800088: beq         $a2, $zero, L_80800098
    if (ctx->r6 == 0) {
        // 0x8080008C: swc1        $f4, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
            goto L_80800098;
    }
    // 0x8080008C: swc1        $f4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
    // 0x80800090: b           L_8080009C
    // 0x80800094: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
        goto L_8080009C;
    // 0x80800094: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
L_80800098:
    // 0x80800098: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
L_8080009C:
    // 0x8080009C: beq         $a2, $zero, L_808000AC
    if (ctx->r6 == 0) {
        // 0x808000A0: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_808000AC;
    }
    // 0x808000A0: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x808000A4: b           L_808000B0
    // 0x808000A8: sh          $t7, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r15;
        goto L_808000B0;
    // 0x808000A8: sh          $t7, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r15;
L_808000AC:
    // 0x808000AC: sh          $zero, 0x2($v1)
    MEM_H(0X2, ctx->r3) = 0;
L_808000B0:
    // 0x808000B0: beql        $a2, $zero, L_808000C4
    if (ctx->r6 == 0) {
        // 0x808000B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808000C4;
    }
    goto skip_0;
    // 0x808000B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808000B8: jal         0x8010A570
    // 0x808000BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8010A570(rdram, ctx);
        goto after_4;
    // 0x808000BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x808000C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000C4:
    // 0x808000C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000C8: jr          $ra
    // 0x808000CC: nop

    return;
    // 0x808000CC: nop

;}
RECOMP_FUNC void _baduo_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084998: syscall     124
    recomp_syscall_handler(rdram, ctx, 0x80084998);
    return;
    // 0x8008499C: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void func_80800A50_chfireicestorm(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A50: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80800A54: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800A58: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800A5C: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800A60: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800A64: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800A68: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800A6C: bnel        $t7, $at, L_80800B94
    if (ctx->r15 != ctx->r1) {
        // 0x80800A70: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800B94;
    }
    goto skip_0;
    // 0x80800A70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800A74: jal         0x800D8FF8
    // 0x80800A78: nop

    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800A78: nop

    after_0:
    // 0x80800A7C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800A80: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80800A84: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x80800A88: jal         0x800EFA20
    // 0x80800A8C: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    func_800EFA20(rdram, ctx);
        goto after_1;
    // 0x80800A8C: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    after_1:
    // 0x80800A90: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800A94: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800A98: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80800A9C: jal         0x800EE780
    // 0x80800AA0: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    func_800EE780(rdram, ctx);
        goto after_2;
    // 0x80800AA0: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    after_2:
    // 0x80800AA4: lui         $a3, 0x2
    ctx->r7 = S32(0X2 << 16);
    // 0x80800AA8: ori         $a3, $a3, 0x20
    ctx->r7 = ctx->r7 | 0X20;
    // 0x80800AAC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800AB0: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80800AB4: jal         0x800C6A7C
    // 0x80800AB8: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    func_800C6A7C(rdram, ctx);
        goto after_3;
    // 0x80800AB8: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_3:
    // 0x80800ABC: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x80800AC0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800AC4: jal         0x800EE7F8
    // 0x80800AC8: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x80800AC8: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_4:
    // 0x80800ACC: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
    // 0x80800AD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AD4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800AD8: sll         $t0, $t8, 12
    ctx->r8 = S32(ctx->r24 << 12);
    // 0x80800ADC: bgez        $t0, L_80800AF8
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80800AE0: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_80800AF8;
    }
    // 0x80800AE0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800AE4: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(1528, 0XF38) << 16);
    // 0x80800AE8: addiu       $t1, $t1, 0xF38
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(1528, 0XF38));
    // 0x80800AEC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800AF0: jal         0x80089D58
    // 0x80800AF4: addiu       $a3, $zero, 0x5DC
    ctx->r7 = ADD32(0, 0X5DC);
    _subaddieaudioloop_entrypoint_5(rdram, ctx);
        goto after_5;
    // 0x80800AF4: addiu       $a3, $zero, 0x5DC
    ctx->r7 = ADD32(0, 0X5DC);
    after_5:
L_80800AF8:
    // 0x80800AF8: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x80800AFC: beq         $t2, $zero, L_80800B34
    if (ctx->r10 == 0) {
        // 0x80800B00: nop
    
            goto L_80800B34;
    }
    // 0x80800B00: nop

    // 0x80800B04: lw          $t3, 0x64($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X64);
    // 0x80800B08: addiu       $a0, $zero, 0x4A4
    ctx->r4 = ADD32(0, 0X4A4);
    // 0x80800B0C: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x80800B10: sll         $t5, $t3, 12
    ctx->r13 = S32(ctx->r11 << 12);
    // 0x80800B14: bgez        $t5, L_80800B24
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80800B18: nop
    
            goto L_80800B24;
    }
    // 0x80800B18: nop

    // 0x80800B1C: jal         0x80101180
    // 0x80800B20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_6;
    // 0x80800B20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
L_80800B24:
    // 0x80800B24: jal         0x80800D0C
    // 0x80800B28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800D0C_chfireicestorm(rdram, ctx);
        goto after_7;
    // 0x80800B28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800B2C: b           L_80800B50
    // 0x80800B30: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
        goto L_80800B50;
    // 0x80800B30: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
L_80800B34:
    // 0x80800B34: jal         0x800D9078
    // 0x80800B38: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_8;
    // 0x80800B38: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_8:
    // 0x80800B3C: beql        $v0, $zero, L_80800B50
    if (ctx->r2 == 0) {
        // 0x80800B40: addiu       $a0, $sp, 0x40
        ctx->r4 = ADD32(ctx->r29, 0X40);
            goto L_80800B50;
    }
    goto skip_1;
    // 0x80800B40: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    skip_1:
    // 0x80800B44: jal         0x80089CA8
    // 0x80800B48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_9;
    // 0x80800B48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800B4C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
L_80800B50:
    // 0x80800B50: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80800B54: jal         0x800EFA20
    // 0x80800B58: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_800EFA20(rdram, ctx);
        goto after_10;
    // 0x80800B58: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_10:
    // 0x80800B5C: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    // 0x80800B60: jal         0x800EF04C
    // 0x80800B64: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800EF04C(rdram, ctx);
        goto after_11;
    // 0x80800B64: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_11:
    // 0x80800B68: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x80800B6C: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x80800B70: bgez        $t8, L_80800B88
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800B74: nop
    
            goto L_80800B88;
    }
    // 0x80800B74: nop

    // 0x80800B78: jal         0x80800E08
    // 0x80800B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800E08_chfireicestorm(rdram, ctx);
        goto after_12;
    // 0x80800B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800B80: b           L_80800B94
    // 0x80800B84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800B94;
    // 0x80800B84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800B88:
    // 0x80800B88: jal         0x80800DC8
    // 0x80800B8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800DC8_chfireicestorm(rdram, ctx);
        goto after_13;
    // 0x80800B8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800B90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800B94:
    // 0x80800B94: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800B98: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80800B9C: jr          $ra
    // 0x80800BA0: nop

    return;
    // 0x80800BA0: nop

;}
RECOMP_FUNC void _chkingjinjo_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800864C0: syscall     330
    recomp_syscall_handler(rdram, ctx, 0x800864C0);
    return;
    // 0x800864C4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800D28E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D28E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D28EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D28F0: jal         0x800D21D0
    // 0x800D28F4: nop

    func_800D21D0(rdram, ctx);
        goto after_0;
    // 0x800D28F4: nop

    after_0:
    // 0x800D28F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D28FC: lbu         $v0, 0x2($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2);
    // 0x800D2900: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D2904: jr          $ra
    // 0x800D2908: nop

    return;
    // 0x800D2908: nop

    // 0x800D290C: nop

;}
RECOMP_FUNC void func_80800204_chtransparentfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800204: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800208: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080020C: jal         0x80089BC0
    // 0x80800210: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _subaddiejoy_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800210: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800214: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80800218: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080021C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800220: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80800224: mul.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800228: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x8080022C: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80800230: jal         0x80102BAC
    // 0x80800234: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    func_80102BAC(rdram, ctx);
        goto after_1;
    // 0x80800234: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x80800238: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080023C: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800240: lui         $a1, 0x20
    ctx->r5 = S32(0X20 << 16);
    // 0x80800244: lwc1        $f0, 0x24($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80800248: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2232, 0XF68) << 16);
    // 0x8080024C: ori         $a1, $a1, 0x6
    ctx->r5 = ctx->r5 | 0X6;
    // 0x80800250: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80800254: nop

    // 0x80800258: bc1f        L_80800268
    if (!c1cs) {
        // 0x8080025C: nop
    
            goto L_80800268;
    }
    // 0x8080025C: nop

    // 0x80800260: b           L_808002A0
    // 0x80800264: swc1        $f2, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f2.u32l;
        goto L_808002A0;
    // 0x80800264: swc1        $f2, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f2.u32l;
L_80800268:
    // 0x80800268: lwc1        $f6, 0xF68($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2232, 0XF68));
    // 0x8080026C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800270: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800274: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800278: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8080027C: swc1        $f10, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f10.u32l;
    // 0x80800280: lwc1        $f16, 0x24($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80800284: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80800288: nop

    // 0x8080028C: bc1f        L_808002A0
    if (!c1cs) {
        // 0x80800290: nop
    
            goto L_808002A0;
    }
    // 0x80800290: nop

    // 0x80800294: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800298: nop

    // 0x8080029C: swc1        $f4, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f4.u32l;
L_808002A0:
    // 0x808002A0: jal         0x8010BA80
    // 0x808002A4: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_8010BA80(rdram, ctx);
        goto after_2;
    // 0x808002A4: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_2:
    // 0x808002A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002B0: jr          $ra
    // 0x808002B4: nop

    return;
    // 0x808002B4: nop

;}
RECOMP_FUNC void _chquiz_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800877F8: syscall     629
    recomp_syscall_handler(rdram, ctx, 0x800877F8);
    return;
    // 0x800877FC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800F30_chpufferfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F30: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800F34: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800F38: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800F3C: jal         0x80089BC0
    // 0x80800F40: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _subaddiejoy_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800F40: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800F44: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80800F48: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800F4C: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80800F50: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800F54: jal         0x8010D254
    // 0x80800F58: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    func_8010D254(rdram, ctx);
        goto after_1;
    // 0x80800F58: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x80800F5C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800F60: jal         0x800F1828
    // 0x80800F64: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800F1828(rdram, ctx);
        goto after_2;
    // 0x80800F64: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_2:
    // 0x80800F68: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800F6C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800F70: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x80800F74: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800F78: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80800F7C: nop

    // 0x80800F80: bc1fl       L_80800FAC
    if (!c1cs) {
        // 0x80800F84: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_80800FAC;
    }
    goto skip_0;
    // 0x80800F84: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    skip_0:
    // 0x80800F88: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800F8C: lwc1        $f10, 0x50($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80800F90: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80800F94: nop

    // 0x80800F98: bc1fl       L_80800FAC
    if (!c1cs) {
        // 0x80800F9C: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_80800FAC;
    }
    goto skip_1;
    // 0x80800F9C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    skip_1:
    // 0x80800FA0: b           L_80800FE4
    // 0x80800FA4: swc1        $f2, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f2.u32l;
        goto L_80800FE4;
    // 0x80800FA4: swc1        $f2, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f2.u32l;
    // 0x80800FA8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_80800FAC:
    // 0x80800FAC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800FB0: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80800FB4: lui         $at, 0x43A5
    ctx->r1 = S32(0X43A5 << 16);
    // 0x80800FB8: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80800FBC: nop

    // 0x80800FC0: bc1fl       L_80800FE8
    if (!c1cs) {
        // 0x80800FC4: lwc1        $f12, 0x38($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
            goto L_80800FE8;
    }
    goto skip_2;
    // 0x80800FC4: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    skip_2:
    // 0x80800FC8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800FCC: nop

    // 0x80800FD0: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x80800FD4: nop

    // 0x80800FD8: bc1fl       L_80800FE8
    if (!c1cs) {
        // 0x80800FDC: lwc1        $f12, 0x38($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
            goto L_80800FE8;
    }
    goto skip_3;
    // 0x80800FDC: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    skip_3:
    // 0x80800FE0: swc1        $f12, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f12.u32l;
L_80800FE4:
    // 0x80800FE4: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
L_80800FE8:
    // 0x80800FE8: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800FEC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2240, 0X1158) << 16);
    // 0x80800FF0: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x80800FF4: nop

    // 0x80800FF8: bc1f        L_8080100C
    if (!c1cs) {
        // 0x80800FFC: nop
    
            goto L_8080100C;
    }
    // 0x80800FFC: nop

    // 0x80801000: swc1        $f12, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f12.u32l;
    // 0x80801004: b           L_80801040
    // 0x80801008: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
        goto L_80801040;
    // 0x80801008: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
L_8080100C:
    // 0x8080100C: lwc1        $f18, 0x1158($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2240, 0X1158));
    // 0x80801010: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80801014: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80801018: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x8080101C: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80801020: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80801024: nop

    // 0x80801028: bc1fl       L_80801044
    if (!c1cs) {
        // 0x8080102C: swc1        $f0, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
            goto L_80801044;
    }
    goto skip_4;
    // 0x8080102C: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    skip_4:
    // 0x80801030: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80801034: nop

    // 0x80801038: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    // 0x8080103C: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
L_80801040:
    // 0x80801040: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
L_80801044:
    // 0x80801044: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80801048: jal         0x800F1DCC
    // 0x8080104C: lwc1        $f14, 0x54($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X54);
    func_800F1DCC(rdram, ctx);
        goto after_3;
    // 0x8080104C: lwc1        $f14, 0x54($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X54);
    after_3:
    // 0x80801050: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
    // 0x80801054: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801058: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8080105C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801060: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80801064: lui         $a2, 0x4334
    ctx->r6 = S32(0X4334 << 16);
    // 0x80801068: lui         $a3, 0xC170
    ctx->r7 = S32(0XC170 << 16);
    // 0x8080106C: jal         0x800F10B4
    // 0x80801070: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x80801070: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x80801074: jal         0x800136E4
    // 0x80801078: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800136E4(rdram, ctx);
        goto after_5;
    // 0x80801078: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_5:
    // 0x8080107C: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x80801080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801084: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80801088: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x8080108C: jal         0x80102BAC
    // 0x80801090: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    func_80102BAC(rdram, ctx);
        goto after_6;
    // 0x80801090: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    after_6:
    // 0x80801094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801098: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x8080109C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x808010A0: jal         0x80102C58
    // 0x808010A4: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    func_80102C58(rdram, ctx);
        goto after_7;
    // 0x808010A4: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    after_7:
    // 0x808010A8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2240, 0X115C) << 16);
    // 0x808010AC: lwc1        $f16, 0x115C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2240, 0X115C));
    // 0x808010B0: lwc1        $f12, 0x4C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x808010B4: lwc1        $f14, 0x1C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x808010B8: lui         $a2, 0x3C23
    ctx->r6 = S32(0X3C23 << 16);
    // 0x808010BC: lui         $a3, 0x3BA3
    ctx->r7 = S32(0X3BA3 << 16);
    // 0x808010C0: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x808010C4: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x808010C8: jal         0x800F1FF0
    // 0x808010CC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F1FF0(rdram, ctx);
        goto after_8;
    // 0x808010CC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_8:
    // 0x808010D0: lui         $a1, 0x20
    ctx->r5 = S32(0X20 << 16);
    // 0x808010D4: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
    // 0x808010D8: ori         $a1, $a1, 0x6
    ctx->r5 = ctx->r5 | 0X6;
    // 0x808010DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010E0: jal         0x8010BA80
    // 0x808010E4: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_8010BA80(rdram, ctx);
        goto after_9;
    // 0x808010E4: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_9:
    // 0x808010E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808010EC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808010F0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808010F4: jr          $ra
    // 0x808010F8: nop

    return;
    // 0x808010F8: nop

;}
RECOMP_FUNC void func_800ED0D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ED0D4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800ED0D8: lw          $a0, 0x10($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X10);
    // 0x800ED0DC: sll         $t9, $a3, 4
    ctx->r25 = S32(ctx->r7 << 4);
    // 0x800ED0E0: addu        $v1, $t9, $a1
    ctx->r3 = ADD32(ctx->r25, ctx->r5);
    // 0x800ED0E4: lwc1        $f4, 0x44($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X44);
    // 0x800ED0E8: lwc1        $f6, 0x48($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X48);
    // 0x800ED0EC: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800ED0F0: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800ED0F4: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800ED0F8: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x800ED0FC: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x800ED100: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800ED104: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x800ED108: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800ED10C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800ED110: nop

    // 0x800ED114: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x800ED118: beq         $at, $zero, L_800ED13C
    if (ctx->r1 == 0) {
        // 0x800ED11C: sra         $v0, $t7, 16
        ctx->r2 = S32(SIGNED(ctx->r15) >> 16);
            goto L_800ED13C;
    }
    // 0x800ED11C: sra         $v0, $t7, 16
    ctx->r2 = S32(SIGNED(ctx->r15) >> 16);
L_800ED120:
    // 0x800ED120: lh          $t1, 0x4($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X4);
    // 0x800ED124: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800ED128: sltu        $at, $a1, $v1
    ctx->r1 = ctx->r5 < ctx->r3 ? 1 : 0;
    // 0x800ED12C: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x800ED130: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x800ED134: bne         $at, $zero, L_800ED120
    if (ctx->r1 != 0) {
        // 0x800ED138: sh          $t2, -0xC($a2)
        MEM_H(-0XC, ctx->r6) = ctx->r10;
            goto L_800ED120;
    }
    // 0x800ED138: sh          $t2, -0xC($a2)
    MEM_H(-0XC, ctx->r6) = ctx->r10;
L_800ED13C:
    // 0x800ED13C: jr          $ra
    // 0x800ED140: nop

    return;
    // 0x800ED140: nop

;}
RECOMP_FUNC void baalarm_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80800014: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800018: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    // 0x8080001C: beq         $a1, $zero, L_80800034
    if (ctx->r5 == 0) {
        // 0x80800020: andi        $a0, $a1, 0xFF
        ctx->r4 = ctx->r5 & 0XFF;
            goto L_80800034;
    }
    // 0x80800020: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x80800024: jal         0x800C2FDC
    // 0x80800028: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800C2FDC(rdram, ctx);
        goto after_0;
    // 0x80800028: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8080002C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800030: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
L_80800034:
    // 0x80800034: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x80800038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080003C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800040: jr          $ra
    // 0x80800044: nop

    return;
    // 0x80800044: nop

;}
RECOMP_FUNC void func_808000EC_chbadbeehive(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000FC: jal         0x80100094
    // 0x80800100: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800100: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800104: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80800108: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080010C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800114: jal         0x80089F70
    // 0x80800118: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _subaddierouteDll_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800118: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8080011C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800120: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800124: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80800128: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x8080012C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800130: jal         0x800EE7F8
    // 0x80800134: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800134: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_2:
    // 0x80800138: jal         0x8080000C
    // 0x8080013C: nop

    func_8080000C_chbadbeehive(rdram, ctx);
        goto after_3;
    // 0x8080013C: nop

    after_3:
    // 0x80800140: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    // 0x80800144: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800148: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080014C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800150: jr          $ra
    // 0x80800154: nop

    return;
    // 0x80800154: nop

;}
RECOMP_FUNC void baroll_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C4FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009C500: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009C504: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8009C508: jal         0x800136E4
    // 0x8009C50C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800136E4(rdram, ctx);
        goto after_0;
    // 0x8009C50C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8009C510: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8009C514: lw          $t7, 0xF4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XF4);
    // 0x8009C518: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
    // 0x8009C51C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009C520: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009C524: jr          $ra
    // 0x8009C528: nop

    return;
    // 0x8009C528: nop

;}
RECOMP_FUNC void func_80801C24_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C24: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801C28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801C2C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801C30: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801C34: jal         0x80100094
    // 0x80801C38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801C38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801C3C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(932, 0X2EA4) << 16);
    // 0x80801C40: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x80801C44: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80801C48: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80801C4C: addiu       $a2, $a2, 0x2EA4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(932, 0X2EA4));
    // 0x80801C50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C54: jal         0x80089D20
    // 0x80801C58: addiu       $a1, $v0, 0x3C
    ctx->r5 = ADD32(ctx->r2, 0X3C);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80801C58: addiu       $a1, $v0, 0x3C
    ctx->r5 = ADD32(ctx->r2, 0X3C);
    after_1:
    // 0x80801C5C: bne         $v0, $zero, L_80801CD4
    if (ctx->r2 != 0) {
        // 0x80801C60: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801CD4;
    }
    // 0x80801C60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C64: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80801C68: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(932, 0X2B20) << 16);
    // 0x80801C6C: lui         $a3, 0x3F26
    ctx->r7 = S32(0X3F26 << 16);
    // 0x80801C70: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80801C74: addiu       $a2, $a2, 0x2B20
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(932, 0X2B20));
    // 0x80801C78: jal         0x80089D20
    // 0x80801C7C: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80801C7C: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    after_2:
    // 0x80801C80: bne         $v0, $zero, L_80801CA8
    if (ctx->r2 != 0) {
        // 0x80801C84: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801CA8;
    }
    // 0x80801C84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C88: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80801C8C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(932, 0X2B20) << 16);
    // 0x80801C90: lui         $a3, 0x3F61
    ctx->r7 = S32(0X3F61 << 16);
    // 0x80801C94: ori         $a3, $a3, 0x47AE
    ctx->r7 = ctx->r7 | 0X47AE;
    // 0x80801C98: addiu       $a2, $a2, 0x2B20
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(932, 0X2B20));
    // 0x80801C9C: jal         0x80089D20
    // 0x80801CA0: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80801CA0: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    after_3:
    // 0x80801CA4: beq         $v0, $zero, L_80801CD4
    if (ctx->r2 == 0) {
        // 0x80801CA8: lui         $a2, 0x3F66
        ctx->r6 = S32(0X3F66 << 16);
            goto L_80801CD4;
    }
L_80801CA8:
    // 0x80801CA8: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x80801CAC: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80801CB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801CB4: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x80801CB8: jal         0x800E1610
    // 0x80801CBC: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    func_800E1610(rdram, ctx);
        goto after_4;
    // 0x80801CBC: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_4:
    // 0x80801CC0: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80801CC4: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80801CC8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801CCC: jal         0x80018820
    // 0x80801CD0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80018820(rdram, ctx);
        goto after_5;
    // 0x80801CD0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_5:
L_80801CD4:
    // 0x80801CD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801CD8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801CDC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801CE0: jr          $ra
    // 0x80801CE4: nop

    return;
    // 0x80801CE4: nop

;}
RECOMP_FUNC void func_80800C98_chfactoryworkerdirty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C98: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800C9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800CA0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800CA4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800CA8: jal         0x80100094
    // 0x80800CAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800CAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800CB0: beql        $v0, $zero, L_80800D38
    if (ctx->r2 == 0) {
        // 0x80800CB4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800D38;
    }
    goto skip_0;
    // 0x80800CB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800CB8: jal         0x801022E4
    // 0x80800CBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801022E4(rdram, ctx);
        goto after_1;
    // 0x80800CBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800CC0: addiu       $at, $zero, 0x35D
    ctx->r1 = ADD32(0, 0X35D);
    // 0x80800CC4: bne         $v0, $at, L_80800D04
    if (ctx->r2 != ctx->r1) {
        // 0x80800CC8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D04;
    }
    // 0x80800CC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CCC: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x80800CD0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800CD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CD8: jal         0x80102320
    // 0x80800CDC: lui         $a2, 0x3F40
    ctx->r6 = S32(0X3F40 << 16);
    func_80102320(rdram, ctx);
        goto after_2;
    // 0x80800CDC: lui         $a2, 0x3F40
    ctx->r6 = S32(0X3F40 << 16);
    after_2:
    // 0x80800CE0: beq         $v0, $zero, L_80800D18
    if (ctx->r2 == 0) {
        // 0x80800CE4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D18;
    }
    // 0x80800CE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CE8: jal         0x80100094
    // 0x80800CEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x80800CEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800CF0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800CF4: jal         0x80089818
    // 0x80800CF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_18(rdram, ctx);
        goto after_4;
    // 0x80800CF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800CFC: b           L_80800D1C
    // 0x80800D00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800D1C;
    // 0x80800D00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800D04:
    // 0x80800D04: jal         0x80100094
    // 0x80800D08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_5;
    // 0x80800D08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800D0C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800D10: jal         0x80089818
    // 0x80800D14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_18(rdram, ctx);
        goto after_6;
    // 0x80800D14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
L_80800D18:
    // 0x80800D18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800D1C:
    // 0x80800D1C: jal         0x80100094
    // 0x80800D20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_7;
    // 0x80800D20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80800D24: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800D28: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800D2C: jal         0x800897D8
    // 0x80800D30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_8;
    // 0x80800D30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x80800D34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800D38:
    // 0x80800D38: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800D3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800D40: jr          $ra
    // 0x80800D44: nop

    return;
    // 0x80800D44: nop

;}
RECOMP_FUNC void func_8080009C_chgoldfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "func_8080009C_chgoldfish");
    // 0x8080009C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808000A0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000A4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000A8: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x808000AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000B0: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808000B4: addiu       $t7, $t6, -0x2
    ctx->r15 = ADD32(ctx->r14, -0X2);
    // 0x808000B8: sltiu       $at, $t7, 0x9
    ctx->r1 = ctx->r15 < 0X9 ? 1 : 0;
    // 0x808000BC: beq         $at, $zero, L_808000F0
    if (ctx->r1 == 0) {
        // 0x808000C0: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_808000F0;
    }
    // 0x808000C0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x808000C4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808000C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2312, 0XC50) << 16);
    // 0x808000CC: addu        $at, $at, $t7
    gpr jr_addend_808000D4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808000D0: lw          $t7, 0xC50($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2312, 0XC50));
    // 0x808000D4: jr          $t7
    // 0x808000D8: nop

    switch (jr_addend_808000D4 >> 2) {
        case 0: goto L_808000DC; break;
        case 1: goto L_808000F0; break;
        case 2: goto L_808000F0; break;
        case 3: goto L_808000F0; break;
        case 4: goto L_808000DC; break;
        case 5: goto L_808000DC; break;
        case 6: goto L_808000DC; break;
        case 7: goto L_808000DC; break;
        case 8: goto L_808000DC; break;
        default: switch_error(__func__, 0x808000D4, 0x80800C50);
    }
    // 0x808000D8: nop

L_808000DC:
    // 0x808000DC: jal         0x8010C964
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C964(rdram, ctx);
        goto after_0;
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x808000E4: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x808000E8: srl         $t8, $v0, 10
    ctx->r24 = S32(U32(ctx->r2) >> 10);
    // 0x808000EC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_808000F0:
    // 0x808000F0: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x808000F4: sltiu       $at, $t9, 0xA
    ctx->r1 = ctx->r25 < 0XA ? 1 : 0;
    // 0x808000F8: beq         $at, $zero, L_80800498
    if (ctx->r1 == 0) {
        // 0x808000FC: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80800498;
    }
    // 0x808000FC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80800100: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2312, 0XC74) << 16);
    // 0x80800104: addu        $at, $at, $t9
    gpr jr_addend_8080010C = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80800108: lw          $t9, 0xC74($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2312, 0XC74));
    // 0x8080010C: jr          $t9
    // 0x80800110: nop

    switch (jr_addend_8080010C >> 2) {
        case 0: goto L_80800114; break;
        case 1: goto L_80800150; break;
        case 2: goto L_8080018C; break;
        case 3: goto L_80800228; break;
        case 4: goto L_80800280; break;
        case 5: goto L_80800328; break;
        case 6: goto L_808003B0; break;
        case 7: goto L_80800478; break;
        case 8: goto L_80800498; break;
        case 9: goto L_80800498; break;
        default: switch_error(__func__, 0x8080010C, 0x80800C74);
    }
    // 0x80800110: nop

L_80800114:
    // 0x80800114: jal         0x800DA298
    // 0x80800118: addiu       $a0, $zero, 0x51E
    ctx->r4 = ADD32(0, 0X51E);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800118: addiu       $a0, $zero, 0x51E
    ctx->r4 = ADD32(0, 0X51E);
    after_1:
    // 0x8080011C: beq         $v0, $zero, L_80800138
    if (ctx->r2 == 0) {
        // 0x80800120: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800138;
    }
    // 0x80800120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800128: jal         0x808005F0
    // 0x8080012C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808005F0_chgoldfish(rdram, ctx);
        goto after_2;
    // 0x8080012C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80800130: b           L_8080049C
    // 0x80800134: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080049C;
    // 0x80800134: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800138:
    // 0x80800138: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2312, 0XD20) << 16);
    // 0x8080013C: addiu       $a2, $a2, 0xD20
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2312, 0XD20));
    // 0x80800140: jal         0x8008A1E8
    // 0x80800144: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_7(rdram, ctx);
        goto after_3;
    // 0x80800144: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x80800148: b           L_8080049C
    // 0x8080014C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080049C;
    // 0x8080014C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800150:
    // 0x80800150: jal         0x800DA298
    // 0x80800154: addiu       $a0, $zero, 0x1DA
    ctx->r4 = ADD32(0, 0X1DA);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80800154: addiu       $a0, $zero, 0x1DA
    ctx->r4 = ADD32(0, 0X1DA);
    after_4:
    // 0x80800158: bnel        $v0, $zero, L_8080049C
    if (ctx->r2 != 0) {
        // 0x8080015C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080049C;
    }
    goto skip_0;
    // 0x8080015C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800160: jal         0x800DA544
    // 0x80800164: addiu       $a0, $zero, 0x1DA
    ctx->r4 = ADD32(0, 0X1DA);
    func_800DA544(rdram, ctx);
        goto after_5;
    // 0x80800164: addiu       $a0, $zero, 0x1DA
    ctx->r4 = ADD32(0, 0X1DA);
    after_5:
    // 0x80800168: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080016C: addiu       $t0, $zero, 0x67
    ctx->r8 = ADD32(0, 0X67);
    // 0x80800170: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800174: addiu       $a1, $zero, 0x15BF
    ctx->r5 = ADD32(0, 0X15BF);
    // 0x80800178: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x8080017C: jal         0x8008A208
    // 0x80800180: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x80800180: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_6:
    // 0x80800184: b           L_8080049C
    // 0x80800188: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080049C;
    // 0x80800188: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080018C:
    // 0x8080018C: jal         0x800D90A4
    // 0x80800190: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_7;
    // 0x80800190: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_7:
    // 0x80800194: beq         $v0, $zero, L_80800498
    if (ctx->r2 == 0) {
        // 0x80800198: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_80800498;
    }
    // 0x80800198: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8080019C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x808001A0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808001A4: jal         0x800DC178
    // 0x808001A8: nop

    func_800DC178(rdram, ctx);
        goto after_8;
    // 0x808001A8: nop

    after_8:
    // 0x808001AC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808001B0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808001B4: lwc1        $f4, 0x4C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x808001B8: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x808001BC: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x808001C0: c.eq.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl == ctx->f4.fl;
    // 0x808001C4: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x808001C8: bc1fl       L_808001E0
    if (!c1cs) {
        // 0x808001CC: swc1        $f2, 0x50($s0)
        MEM_W(0X50, ctx->r16) = ctx->f2.u32l;
            goto L_808001E0;
    }
    goto skip_1;
    // 0x808001CC: swc1        $f2, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f2.u32l;
    skip_1:
    // 0x808001D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001D4: b           L_808001E0
    // 0x808001D8: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
        goto L_808001E0;
    // 0x808001D8: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
    // 0x808001DC: swc1        $f2, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f2.u32l;
L_808001E0:
    // 0x808001E0: jal         0x800EE7F8
    // 0x808001E4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_9;
    // 0x808001E4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_9:
    // 0x808001E8: lw          $a0, 0x70($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X70);
    // 0x808001EC: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    // 0x808001F0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x808001F4: srl         $t1, $a0, 25
    ctx->r9 = S32(U32(ctx->r4) >> 25);
    // 0x808001F8: addiu       $a0, $t1, -0x1
    ctx->r4 = ADD32(ctx->r9, -0X1);
    // 0x808001FC: jal         0x800CD08C
    // 0x80800200: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_800CD08C(rdram, ctx);
        goto after_10;
    // 0x80800200: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_10:
    // 0x80800204: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800208: jal         0x80800BA8
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800BA8_chgoldfish(rdram, ctx);
        goto after_11;
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800210: beq         $v0, $zero, L_80800498
    if (ctx->r2 == 0) {
        // 0x80800214: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800498;
    }
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800218: jal         0x808005F0
    // 0x8080021C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808005F0_chgoldfish(rdram, ctx);
        goto after_12;
    // 0x8080021C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_12:
    // 0x80800220: b           L_8080049C
    // 0x80800224: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080049C;
    // 0x80800224: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800228:
    // 0x80800228: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080022C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800230: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800234: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080023C: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    // 0x80800240: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    // 0x80800244: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    // 0x80800248: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8080024C: jal         0x80800AB4
    // 0x80800250: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_80800AB4_chgoldfish(rdram, ctx);
        goto after_13;
    // 0x80800250: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_13:
    // 0x80800254: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800258: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080025C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800260: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x80800264: nop

    // 0x80800268: bc1fl       L_8080049C
    if (!c1cs) {
        // 0x8080026C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080049C;
    }
    goto skip_2;
    // 0x8080026C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80800270: jal         0x808005F0
    // 0x80800274: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808005F0_chgoldfish(rdram, ctx);
        goto after_14;
    // 0x80800274: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_14:
    // 0x80800278: b           L_8080049C
    // 0x8080027C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080049C;
    // 0x8080027C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800280:
    // 0x80800280: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    // 0x80800284: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80800288: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080028C: jal         0x8008FE94
    // 0x80800290: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8008FE94(rdram, ctx);
        goto after_15;
    // 0x80800290: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_15:
    // 0x80800294: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800298: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080029C: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x808002A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808002A4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x808002A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002AC: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    // 0x808002B0: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    // 0x808002B4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x808002B8: jal         0x80800AB4
    // 0x808002BC: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_80800AB4_chgoldfish(rdram, ctx);
        goto after_16;
    // 0x808002BC: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_16:
    // 0x808002C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808002C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808002C8: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x808002CC: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x808002D0: nop

    // 0x808002D4: bc1fl       L_808002F4
    if (!c1cs) {
        // 0x808002D8: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_808002F4;
    }
    goto skip_3;
    // 0x808002D8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_3:
    // 0x808002DC: jal         0x80090708
    // 0x808002E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_17;
    // 0x808002E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_17:
    // 0x808002E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E8: jal         0x808005F0
    // 0x808002EC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_808005F0_chgoldfish(rdram, ctx);
        goto after_18;
    // 0x808002EC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_18:
    // 0x808002F0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
L_808002F4:
    // 0x808002F4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808002F8: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808002FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800300: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800304: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800308: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8080030C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800310: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80800314: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800318: jal         0x80800924
    // 0x8080031C: swc1        $f8, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f8.u32l;
    func_80800924_chgoldfish(rdram, ctx);
        goto after_19;
    // 0x8080031C: swc1        $f8, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f8.u32l;
    after_19:
    // 0x80800320: b           L_8080049C
    // 0x80800324: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080049C;
    // 0x80800324: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800328:
    // 0x80800328: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8080032C: jal         0x8008FE68
    // 0x80800330: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_8008FE68(rdram, ctx);
        goto after_20;
    // 0x80800330: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_20:
    // 0x80800334: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800338: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080033C: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800340: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x80800344: add.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80800348: jal         0x800D90A4
    // 0x8080034C: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    func_800D90A4(rdram, ctx);
        goto after_21;
    // 0x8080034C: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    after_21:
    // 0x80800350: beq         $v0, $zero, L_80800388
    if (ctx->r2 == 0) {
        // 0x80800354: lui         $at, 0x4220
        ctx->r1 = S32(0X4220 << 16);
            goto L_80800388;
    }
    // 0x80800354: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80800358: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080035C: addiu       $a0, $zero, 0x15C2
    ctx->r4 = ADD32(0, 0X15C2);
    // 0x80800360: addiu       $a1, $zero, 0x15C5
    ctx->r5 = ADD32(0, 0X15C5);
    // 0x80800364: jal         0x800DC128
    // 0x80800368: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    func_800DC128(rdram, ctx);
        goto after_22;
    // 0x80800368: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    after_22:
    // 0x8080036C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800370: addiu       $t2, $zero, 0x67
    ctx->r10 = ADD32(0, 0X67);
    // 0x80800374: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800378: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8080037C: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800380: jal         0x8008A208
    // 0x80800384: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_23;
    // 0x80800384: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_23:
L_80800388:
    // 0x80800388: jal         0x800F54E4
    // 0x8080038C: nop

    func_800F54E4(rdram, ctx);
        goto after_24;
    // 0x8080038C: nop

    after_24:
    // 0x80800390: jal         0x800F71D4
    // 0x80800394: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F71D4(rdram, ctx);
        goto after_25;
    // 0x80800394: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_25:
    // 0x80800398: beq         $v0, $zero, L_80800498
    if (ctx->r2 == 0) {
        // 0x8080039C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800498;
    }
    // 0x8080039C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003A0: jal         0x808005F0
    // 0x808003A4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_808005F0_chgoldfish(rdram, ctx);
        goto after_26;
    // 0x808003A4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_26:
    // 0x808003A8: b           L_8080049C
    // 0x808003AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080049C;
    // 0x808003AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808003B0:
    // 0x808003B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808003B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808003B8: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808003BC: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x808003C0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808003C4: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    // 0x808003C8: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x808003CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003D0: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    // 0x808003D4: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    // 0x808003D8: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x808003DC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x808003E0: jal         0x80800AB4
    // 0x808003E4: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_80800AB4_chgoldfish(rdram, ctx);
        goto after_27;
    // 0x808003E4: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_27:
    // 0x808003E8: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x808003EC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808003F0: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x808003F4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808003F8: jal         0x800F1214
    // 0x808003FC: lui         $a2, 0x4407
    ctx->r6 = S32(0X4407 << 16);
    func_800F1214(rdram, ctx);
        goto after_28;
    // 0x808003FC: lui         $a2, 0x4407
    ctx->r6 = S32(0X4407 << 16);
    after_28:
    // 0x80800400: jal         0x80013970
    // 0x80800404: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80013970(rdram, ctx);
        goto after_29;
    // 0x80800404: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_29:
    // 0x80800408: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8080040C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800410: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x80800414: mul.s       $f16, $f0, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80800418: jal         0x800D90A4
    // 0x8080041C: swc1        $f16, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f16.u32l;
    func_800D90A4(rdram, ctx);
        goto after_30;
    // 0x8080041C: swc1        $f16, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f16.u32l;
    after_30:
    // 0x80800420: beq         $v0, $zero, L_80800430
    if (ctx->r2 == 0) {
        // 0x80800424: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800430;
    }
    // 0x80800424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800428: jal         0x808005F0
    // 0x8080042C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_808005F0_chgoldfish(rdram, ctx);
        goto after_31;
    // 0x8080042C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_31:
L_80800430:
    // 0x80800430: lwc1        $f0, 0x34($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800434: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800438: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8080043C: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80800440: nop

    // 0x80800444: bc1fl       L_80800468
    if (!c1cs) {
        // 0x80800448: lwc1        $f8, 0x24($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
            goto L_80800468;
    }
    goto skip_4;
    // 0x80800448: lwc1        $f8, 0x24($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
    skip_4:
    // 0x8080044C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80800450: nop

    // 0x80800454: bc1fl       L_80800468
    if (!c1cs) {
        // 0x80800458: lwc1        $f8, 0x24($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
            goto L_80800468;
    }
    goto skip_5;
    // 0x80800458: lwc1        $f8, 0x24($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
    skip_5:
    // 0x8080045C: jal         0x80800964
    // 0x80800460: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80800964_chgoldfish(rdram, ctx);
        goto after_32;
    // 0x80800460: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_32:
    // 0x80800464: lwc1        $f8, 0x24($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
L_80800468:
    // 0x80800468: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8080046C: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800470: b           L_80800498
    // 0x80800474: swc1        $f18, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f18.u32l;
        goto L_80800498;
    // 0x80800474: swc1        $f18, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f18.u32l;
L_80800478:
    // 0x80800478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080047C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80800480: jal         0x8010CE70
    // 0x80800484: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    func_8010CE70(rdram, ctx);
        goto after_33;
    // 0x80800484: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_33:
    // 0x80800488: beq         $v0, $zero, L_80800498
    if (ctx->r2 == 0) {
        // 0x8080048C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800498;
    }
    // 0x8080048C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800490: jal         0x808005F0
    // 0x80800494: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_808005F0_chgoldfish(rdram, ctx);
        goto after_34;
    // 0x80800494: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_34:
L_80800498:
    // 0x80800498: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080049C:
    // 0x8080049C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808004A0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808004A4: jr          $ra
    // 0x808004A8: nop

    return;
    // 0x808004A8: nop

;}
RECOMP_FUNC void bsrest_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080069C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006A4: jal         0x80084C98
    // 0x808006A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bafpctrl_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808006A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808006AC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808006B0: bne         $v0, $at, L_808006C8
    if (ctx->r2 != ctx->r1) {
        // 0x808006B4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808006C8;
    }
    // 0x808006B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808006B8: jal         0x800848A8
    // 0x808006BC: nop

    _badrone_entrypoint_24(rdram, ctx);
        goto after_1;
    // 0x808006BC: nop

    after_1:
    // 0x808006C0: b           L_808006D4
    // 0x808006C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808006D4;
    // 0x808006C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808006C8:
    // 0x808006C8: jal         0x80084750
    // 0x808006CC: nop

    _badata_entrypoint_34(rdram, ctx);
        goto after_2;
    // 0x808006CC: nop

    after_2:
    // 0x808006D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808006D4:
    // 0x808006D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808006D8: jr          $ra
    // 0x808006DC: nop

    return;
    // 0x808006DC: nop

;}
RECOMP_FUNC void func_80800028_chamazonstadiumguard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800028: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8080002C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800030: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800034: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800038: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    // 0x8080003C: jal         0x80100094
    // 0x80800040: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800040: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800044: beq         $v0, $zero, L_80800064
    if (ctx->r2 == 0) {
        // 0x80800048: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80800064;
    }
    // 0x80800048: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080004C: jal         0x80100094
    // 0x80800050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800054: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800058: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8080005C: jal         0x800897D8
    // 0x80800060: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x80800060: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
L_80800064:
    // 0x80800064: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800068: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x8080006C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800070: sltiu       $at, $t8, 0x8
    ctx->r1 = ctx->r24 < 0X8 ? 1 : 0;
    // 0x80800074: beq         $at, $zero, L_80800220
    if (ctx->r1 == 0) {
        // 0x80800078: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800220;
    }
    // 0x80800078: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8080007C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1900, 0X680) << 16);
    // 0x80800080: addu        $at, $at, $t8
    gpr jr_addend_80800088 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800084: lw          $t8, 0x680($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1900, 0X680));
    // 0x80800088: jr          $t8
    // 0x8080008C: nop

    switch (jr_addend_80800088 >> 2) {
        case 0: goto L_80800090; break;
        case 1: goto L_808000B0; break;
        case 2: goto L_808000D8; break;
        case 3: goto L_80800120; break;
        case 4: goto L_8080012C; break;
        case 5: goto L_808001A0; break;
        case 6: goto L_80800208; break;
        case 7: goto L_80800218; break;
        default: switch_error(__func__, 0x80800088, 0x80800680);
    }
    // 0x8080008C: nop

L_80800090:
    // 0x80800090: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80800094: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
    // 0x80800098: jal         0x80800530
    // 0x8080009C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800530_chamazonstadiumguard(rdram, ctx);
        goto after_3;
    // 0x8080009C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808000A0: jal         0x80800648
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800648_chamazonstadiumguard(rdram, ctx);
        goto after_4;
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808000A8: b           L_80800224
    // 0x808000AC: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
        goto L_80800224;
    // 0x808000AC: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
L_808000B0:
    // 0x808000B0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x808000B4: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    // 0x808000B8: jal         0x80101DDC
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_5;
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808000C0: beq         $v0, $zero, L_80800220
    if (ctx->r2 == 0) {
        // 0x808000C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800220;
    }
    // 0x808000C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C8: jal         0x80102424
    // 0x808000CC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x808000CC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x808000D0: b           L_80800224
    // 0x808000D4: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
        goto L_80800224;
    // 0x808000D4: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
L_808000D8:
    // 0x808000D8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x808000DC: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
    // 0x808000E0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808000E4: jal         0x8010CAC0
    // 0x808000E8: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    func_8010CAC0(rdram, ctx);
        goto after_7;
    // 0x808000E8: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    after_7:
    // 0x808000EC: bne         $v0, $zero, L_80800110
    if (ctx->r2 != 0) {
        // 0x808000F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800110;
    }
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F4: jal         0x80102078
    // 0x808000F8: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_80102078(rdram, ctx);
        goto after_8;
    // 0x808000F8: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_8:
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800100: jal         0x80102424
    // 0x80800104: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_9;
    // 0x80800104: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80800108: b           L_80800224
    // 0x8080010C: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
        goto L_80800224;
    // 0x8080010C: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
L_80800110:
    // 0x80800110: jal         0x808005CC
    // 0x80800114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808005CC_chamazonstadiumguard(rdram, ctx);
        goto after_10;
    // 0x80800114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800118: b           L_80800224
    // 0x8080011C: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
        goto L_80800224;
    // 0x8080011C: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
L_80800120:
    // 0x80800120: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80800124: b           L_80800220
    // 0x80800128: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
        goto L_80800220;
    // 0x80800128: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
L_8080012C:
    // 0x8080012C: jal         0x80101DDC
    // 0x80800130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_11;
    // 0x80800130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800134: beq         $v0, $zero, L_80800220
    if (ctx->r2 == 0) {
        // 0x80800138: addiu       $a1, $zero, 0x4
        ctx->r5 = ADD32(0, 0X4);
            goto L_80800220;
    }
    // 0x80800138: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8080013C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800140: jal         0x8008A0E0
    // 0x80800144: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_12;
    // 0x80800144: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    after_12:
    // 0x80800148: beq         $v0, $zero, L_80800160
    if (ctx->r2 == 0) {
        // 0x8080014C: lwc1        $f4, 0x48($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
            goto L_80800160;
    }
    // 0x8080014C: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800150: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x80800154: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80800158: b           L_80800178
    // 0x8080015C: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
        goto L_80800178;
    // 0x8080015C: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
L_80800160:
    // 0x80800160: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1900, 0X6B0) << 16);
    // 0x80800164: addiu       $v0, $v0, 0x6B0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1900, 0X6B0));
    // 0x80800168: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8080016C: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x80800170: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80800174: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
L_80800178:
    // 0x80800178: jal         0x80103014
    // 0x8080017C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103014(rdram, ctx);
        goto after_13;
    // 0x8080017C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800184: jal         0x801020DC
    // 0x80800188: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_801020DC(rdram, ctx);
        goto after_14;
    // 0x80800188: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x8080018C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800190: jal         0x80102424
    // 0x80800194: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_15;
    // 0x80800194: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_15:
    // 0x80800198: b           L_80800224
    // 0x8080019C: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
        goto L_80800224;
    // 0x8080019C: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
L_808001A0:
    // 0x808001A0: jal         0x80800620
    // 0x808001A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800620_chamazonstadiumguard(rdram, ctx);
        goto after_16;
    // 0x808001A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808001A8: jal         0x80800648
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800648_chamazonstadiumguard(rdram, ctx);
        goto after_17;
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x808001B0: jal         0x800DB9B0
    // 0x808001B4: nop

    func_800DB9B0(rdram, ctx);
        goto after_18;
    // 0x808001B4: nop

    after_18:
    // 0x808001B8: bne         $v0, $zero, L_80800220
    if (ctx->r2 != 0) {
        // 0x808001BC: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80800220;
    }
    // 0x808001BC: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808001C0: addiu       $a1, $zero, 0xBB8
    ctx->r5 = ADD32(0, 0XBB8);
    // 0x808001C4: jal         0x8010CAC0
    // 0x808001C8: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    func_8010CAC0(rdram, ctx);
        goto after_19;
    // 0x808001C8: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_19:
    // 0x808001CC: bne         $v0, $zero, L_80800220
    if (ctx->r2 != 0) {
        // 0x808001D0: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_80800220;
    }
    // 0x808001D0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808001D4: lw          $t3, 0x7C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X7C);
    // 0x808001D8: sll         $t5, $t3, 19
    ctx->r13 = S32(ctx->r11 << 19);
    // 0x808001DC: bltzl       $t5, L_80800224
    if (SIGNED(ctx->r13) < 0) {
        // 0x808001E0: lw          $t6, 0x7C($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X7C);
            goto L_80800224;
    }
    goto skip_0;
    // 0x808001E0: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
    skip_0:
    // 0x808001E4: jal         0x800EE7F8
    // 0x808001E8: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_20;
    // 0x808001E8: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    after_20:
    // 0x808001EC: jal         0x80103014
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103014(rdram, ctx);
        goto after_21;
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F8: jal         0x80102424
    // 0x808001FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_22;
    // 0x808001FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_22:
    // 0x80800200: b           L_80800224
    // 0x80800204: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
        goto L_80800224;
    // 0x80800204: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
L_80800208:
    // 0x80800208: jal         0x80800648
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800648_chamazonstadiumguard(rdram, ctx);
        goto after_23;
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80800210: b           L_80800224
    // 0x80800214: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
        goto L_80800224;
    // 0x80800214: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
L_80800218:
    // 0x80800218: jal         0x80800648
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800648_chamazonstadiumguard(rdram, ctx);
        goto after_24;
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
L_80800220:
    // 0x80800220: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
L_80800224:
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800228: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8080022C: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x80800230: bgez        $t8, L_808002B4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800234: lui         $a2, 0x4020
        ctx->r6 = S32(0X4020 << 16);
            goto L_808002B4;
    }
    // 0x80800234: lui         $a2, 0x4020
    ctx->r6 = S32(0X4020 << 16);
    // 0x80800238: lhu         $t9, 0x72($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X72);
    // 0x8080023C: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    // 0x80800240: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x80800244: slti        $at, $t0, 0x5
    ctx->r1 = SIGNED(ctx->r8) < 0X5 ? 1 : 0;
    // 0x80800248: bne         $at, $zero, L_80800258
    if (ctx->r1 != 0) {
        // 0x8080024C: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1900, 0X6A0) << 16);
            goto L_80800258;
    }
    // 0x8080024C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1900, 0X6A0) << 16);
    // 0x80800250: b           L_80800264
    // 0x80800254: lwc1        $f0, 0x6A0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1900, 0X6A0));
        goto L_80800264;
    // 0x80800254: lwc1        $f0, 0x6A0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1900, 0X6A0));
L_80800258:
    // 0x80800258: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080025C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800260: nop

L_80800264:
    // 0x80800264: jal         0x80085778
    // 0x80800268: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    _chbadshad_entrypoint_2(rdram, ctx);
        goto after_25;
    // 0x80800268: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_25:
    // 0x8080026C: beq         $v0, $zero, L_808002B4
    if (ctx->r2 == 0) {
        // 0x80800270: lwc1        $f0, 0x38($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
            goto L_808002B4;
    }
    // 0x80800270: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800274: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80800278: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080027C: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x80800280: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800284: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800288: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x8080028C: lui         $a1, 0x43AF
    ctx->r5 = S32(0X43AF << 16);
    // 0x80800290: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800294: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80800298: jal         0x80089F20
    // 0x8080029C: nop

    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_26;
    // 0x8080029C: nop

    after_26:
    // 0x808002A0: andi        $t2, $v0, 0x2
    ctx->r10 = ctx->r2 & 0X2;
    // 0x808002A4: beq         $t2, $zero, L_808002B4
    if (ctx->r10 == 0) {
        // 0x808002A8: addiu       $a0, $zero, 0x9
        ctx->r4 = ADD32(0, 0X9);
            goto L_808002B4;
    }
    // 0x808002A8: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x808002AC: jal         0x80089F38
    // 0x808002B0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _sudeflect_entrypoint_4(rdram, ctx);
        goto after_27;
    // 0x808002B0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_27:
L_808002B4:
    // 0x808002B4: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x808002B8: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x808002BC: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    // 0x808002C0: beq         $t3, $zero, L_808002E0
    if (ctx->r11 == 0) {
        // 0x808002C4: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(1900, 0X748) << 16);
            goto L_808002E0;
    }
    // 0x808002C4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1900, 0X748) << 16);
    // 0x808002C8: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1900, 0X754) << 16);
    // 0x808002CC: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x808002D0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x808002D4: addiu       $a3, $a3, 0x754
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1900, 0X754));
    // 0x808002D8: jal         0x80089F30
    // 0x808002DC: addiu       $a2, $a2, 0x748
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1900, 0X748));
    _sudeflect_entrypoint_3(rdram, ctx);
        goto after_28;
    // 0x808002DC: addiu       $a2, $a2, 0x748
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1900, 0X748));
    after_28:
L_808002E0:
    // 0x808002E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808002E4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808002E8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x808002EC: jr          $ra
    // 0x808002F0: nop

    return;
    // 0x808002F0: nop

;}
RECOMP_FUNC void func_8080207C_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080207C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802080: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80802084: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802088: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080208C: bne         $a1, $at, L_808020EC
    if (ctx->r5 != ctx->r1) {
        // 0x80802090: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_808020EC;
    }
    // 0x80802090: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80802094: jal         0x801015D0
    // 0x80802098: nop

    func_801015D0(rdram, ctx);
        goto after_0;
    // 0x80802098: nop

    after_0:
    // 0x8080209C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808020A0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1752, 0X4F64) << 16);
    // 0x808020A4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x808020A8: lw          $t7, 0x6C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X6C);
    // 0x808020AC: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x808020B0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x808020B4: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x808020B8: jal         0x800DF744
    // 0x808020BC: lw          $a1, 0x4F64($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(1752, 0X4F64));
    func_800DF744(rdram, ctx);
        goto after_1;
    // 0x808020BC: lw          $a1, 0x4F64($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(1752, 0X4F64));
    after_1:
    // 0x808020C0: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x808020C4: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1752, 0X4F64) << 16);
    // 0x808020C8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x808020CC: lw          $t1, 0x6C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X6C);
    // 0x808020D0: andi        $t2, $t1, 0x1FF
    ctx->r10 = ctx->r9 & 0X1FF;
    // 0x808020D4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x808020D8: addu        $a1, $a1, $t3
    ctx->r5 = ADD32(ctx->r5, ctx->r11);
    // 0x808020DC: jal         0x800DF744
    // 0x808020E0: lw          $a1, 0x4F64($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(1752, 0X4F64));
    func_800DF744(rdram, ctx);
        goto after_2;
    // 0x808020E0: lw          $a1, 0x4F64($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(1752, 0X4F64));
    after_2:
    // 0x808020E4: b           L_808020F4
    // 0x808020E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808020F4;
    // 0x808020E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808020EC:
    // 0x808020EC: b           L_808020F4
    // 0x808020F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808020F4;
    // 0x808020F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808020F4:
    // 0x808020F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808020F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808020FC: jr          $ra
    // 0x80802100: nop

    return;
    // 0x80802100: nop

;}
RECOMP_FUNC void func_808006EC_chlavagargoyle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006EC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x808006F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808006F4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808006F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808006FC: jal         0x8010C754
    // 0x80800700: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    func_8010C754(rdram, ctx);
        goto after_0;
    // 0x80800700: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    after_0:
    // 0x80800704: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x80800708: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    // 0x8080070C: jal         0x800D91EC
    // 0x80800710: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    func_800D91EC(rdram, ctx);
        goto after_1;
    // 0x80800710: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_1:
    // 0x80800714: beq         $v0, $zero, L_80800738
    if (ctx->r2 == 0) {
        // 0x80800718: addiu       $a0, $sp, 0x48
        ctx->r4 = ADD32(ctx->r29, 0X48);
            goto L_80800738;
    }
    // 0x80800718: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8080071C: addiu       $s1, $s0, 0x4
    ctx->r17 = ADD32(ctx->r16, 0X4);
    // 0x80800720: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800724: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80800728: jal         0x80800B8C
    // 0x8080072C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800B8C_chlavagargoyle(rdram, ctx);
        goto after_2;
    // 0x8080072C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800730: b           L_8080098C
    // 0x80800734: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080098C;
    // 0x80800734: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800738:
    // 0x80800738: addiu       $s1, $s0, 0x4
    ctx->r17 = ADD32(ctx->r16, 0X4);
    // 0x8080073C: jal         0x800EE7F8
    // 0x80800740: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800740: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80800744: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800748: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8080074C: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80800750: nop

    // 0x80800754: bc1f        L_808007CC
    if (!c1cs) {
        // 0x80800758: nop
    
            goto L_808007CC;
    }
    // 0x80800758: nop

    // 0x8080075C: jal         0x800D8FF8
    // 0x80800760: nop

    func_800D8FF8(rdram, ctx);
        goto after_4;
    // 0x80800760: nop

    after_4:
    // 0x80800764: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800768: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x8080076C: jal         0x800EF174
    // 0x80800770: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    func_800EF174(rdram, ctx);
        goto after_5;
    // 0x80800770: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    after_5:
    // 0x80800774: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800778: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8080077C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800780: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800784: lw          $a2, 0x58($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X58);
    // 0x80800788: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x8080078C: jal         0x800F10B4
    // 0x80800790: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_6;
    // 0x80800790: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_6:
    // 0x80800794: jal         0x80013970
    // 0x80800798: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80013970(rdram, ctx);
        goto after_7;
    // 0x80800798: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_7:
    // 0x8080079C: lwc1        $f10, 0x34($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X34);
    // 0x808007A0: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x808007A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808007A8: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x808007AC: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    // 0x808007B0: lw          $a3, 0x20($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X20);
    // 0x808007B4: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x808007B8: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x808007BC: jal         0x800EFA4C
    // 0x808007C0: nop

    func_800EFA4C(rdram, ctx);
        goto after_8;
    // 0x808007C0: nop

    after_8:
    // 0x808007C4: b           L_80800804
    // 0x808007C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800804;
    // 0x808007C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808007CC:
    // 0x808007CC: jal         0x800D8FF8
    // 0x808007D0: nop

    func_800D8FF8(rdram, ctx);
        goto after_9;
    // 0x808007D0: nop

    after_9:
    // 0x808007D4: lui         $at, 0xC4FA
    ctx->r1 = S32(0XC4FA << 16);
    // 0x808007D8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808007DC: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x808007E0: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x808007E4: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x808007E8: jal         0x800D8FF8
    // 0x808007EC: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_10;
    // 0x808007EC: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
    after_10:
    // 0x808007F0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808007F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808007F8: jal         0x800EF174
    // 0x808007FC: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    func_800EF174(rdram, ctx);
        goto after_11;
    // 0x808007FC: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    after_11:
    // 0x80800800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800804:
    // 0x80800804: jal         0x8080099C
    // 0x80800808: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8080099C_chlavagargoyle(rdram, ctx);
        goto after_12;
    // 0x80800808: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_12:
    // 0x8080080C: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x80800810: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2324, 0XDC4) << 16);
    // 0x80800814: addiu       $a3, $a3, 0xDC4
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2324, 0XDC4));
    // 0x80800818: slti        $t6, $a2, 0x3E8
    ctx->r14 = SIGNED(ctx->r6) < 0X3E8 ? 1 : 0;
    // 0x8080081C: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80800820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800824: jal         0x80089D50
    // 0x80800828: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_13;
    // 0x80800828: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_13:
    // 0x8080082C: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x80800830: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80800834: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800838: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2324, 0XCE4) << 16);
    // 0x8080083C: lwc1        $f4, 0xCE4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2324, 0XCE4));
    // 0x80800840: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80800844: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x80800848: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8080084C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800850: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80800854: jal         0x800F10B4
    // 0x80800858: cvt.s.w     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
    func_800F10B4(rdram, ctx);
        goto after_14;
    // 0x80800858: cvt.s.w     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = CVT_S_W(ctx->f18.u32l);
    after_14:
    // 0x8080085C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800860: jal         0x80089D30
    // 0x80800864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_0(rdram, ctx);
        goto after_15;
    // 0x80800864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800868: jal         0x8001210C
    // 0x8080086C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001210C(rdram, ctx);
        goto after_16;
    // 0x8080086C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_16:
    // 0x80800870: beq         $v0, $zero, L_808008B4
    if (ctx->r2 == 0) {
        // 0x80800874: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808008B4;
    }
    // 0x80800874: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800878: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2324, 0XDD0) << 16);
    // 0x8080087C: addiu       $t8, $t8, 0xDD0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(2324, 0XDD0));
    // 0x80800880: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x80800884: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800888: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080088C: jal         0x800BBCB8
    // 0x80800890: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_17;
    // 0x80800890: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_17:
    // 0x80800894: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2324, 0XE08) << 16);
    // 0x80800898: addiu       $t9, $t9, 0xE08
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(2324, 0XE08));
    // 0x8080089C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x808008A0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808008A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808008A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808008AC: jal         0x800BBCB8
    // 0x808008B0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_18;
    // 0x808008B0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_18:
L_808008B4:
    // 0x808008B4: jal         0x80103EAC
    // 0x808008B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EAC(rdram, ctx);
        goto after_19;
    // 0x808008B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x808008BC: lui         $a3, 0x2
    ctx->r7 = S32(0X2 << 16);
    // 0x808008C0: ori         $a3, $a3, 0x20
    ctx->r7 = ctx->r7 | 0X20;
    // 0x808008C4: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x808008C8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808008CC: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x808008D0: jal         0x800BF340
    // 0x808008D4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800BF340(rdram, ctx);
        goto after_20;
    // 0x808008D4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_20:
    // 0x808008D8: beq         $v0, $zero, L_80800954
    if (ctx->r2 == 0) {
        // 0x808008DC: lui         $at, 0x4248
        ctx->r1 = S32(0X4248 << 16);
            goto L_80800954;
    }
    // 0x808008DC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x808008E0: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808008E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808008E8: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x808008EC: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x808008F0: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x808008F4: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x808008F8: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x808008FC: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80800900: jal         0x800EFA4C
    // 0x80800904: nop

    func_800EFA4C(rdram, ctx);
        goto after_21;
    // 0x80800904: nop

    after_21:
    // 0x80800908: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    // 0x8080090C: jal         0x800C8CB8
    // 0x80800910: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800C8CB8(rdram, ctx);
        goto after_22;
    // 0x80800910: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_22:
    // 0x80800914: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800918: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8080091C: jal         0x800EFB24
    // 0x80800920: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    func_800EFB24(rdram, ctx);
        goto after_23;
    // 0x80800920: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    after_23:
    // 0x80800924: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800928: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x8080092C: jal         0x800EFDE8
    // 0x80800930: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_800EFDE8(rdram, ctx);
        goto after_24;
    // 0x80800930: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_24:
    // 0x80800934: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800938: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8080093C: jal         0x800EFB24
    // 0x80800940: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    func_800EFB24(rdram, ctx);
        goto after_25;
    // 0x80800940: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    after_25:
    // 0x80800944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800948: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8080094C: jal         0x80800B8C
    // 0x80800950: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_80800B8C_chlavagargoyle(rdram, ctx);
        goto after_26;
    // 0x80800950: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_26:
L_80800954:
    // 0x80800954: jal         0x800D8FF8
    // 0x80800958: nop

    func_800D8FF8(rdram, ctx);
        goto after_27;
    // 0x80800958: nop

    after_27:
    // 0x8080095C: lwc1        $f18, 0x54($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800960: lwc1        $f16, 0x48($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800964: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80800968: add.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8080096C: jal         0x800D8FF8
    // 0x80800970: swc1        $f8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f8.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_28;
    // 0x80800970: swc1        $f8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f8.u32l;
    after_28:
    // 0x80800974: lwc1        $f10, 0x50($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80800978: lwc1        $f6, 0x44($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8080097C: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80800980: add.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80800984: swc1        $f16, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f16.u32l;
    // 0x80800988: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080098C:
    // 0x8080098C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800990: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800994: jr          $ra
    // 0x80800998: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80800998: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_800CA740(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA740: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CA744: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800CA748: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CA74C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800CA750: jal         0x800EE7F8
    // 0x800CA754: addiu       $a1, $a3, 0xC
    ctx->r5 = ADD32(ctx->r7, 0XC);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800CA754: addiu       $a1, $a3, 0xC
    ctx->r5 = ADD32(ctx->r7, 0XC);
    after_0:
    // 0x800CA758: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CA75C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CA760: jr          $ra
    // 0x800CA764: nop

    return;
    // 0x800CA764: nop

;}
RECOMP_FUNC void _bsride_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083A08: syscall     85
    recomp_syscall_handler(rdram, ctx, 0x80083A08);
    return;
    // 0x80083A0C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _subaddiefade_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089C98: syscall     808
    recomp_syscall_handler(rdram, ctx, 0x80089C98);
    return;
    // 0x80089C9C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void bscrashout_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001D0: jal         0x8009BD88
    // 0x808001D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009BD88(rdram, ctx);
        goto after_0;
    // 0x808001D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808001D8: jal         0x8008E95C
    // 0x808001DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008E95C(rdram, ctx);
        goto after_1;
    // 0x808001DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808001E0: jal         0x800951B4
    // 0x808001E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800951B4(rdram, ctx);
        goto after_2;
    // 0x808001E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808001E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001F0: jr          $ra
    // 0x808001F4: nop

    return;
    // 0x808001F4: nop

;}
RECOMP_FUNC void func_800CEA84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CEA84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CEA88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CEA8C: jal         0x800CE3E0
    // 0x800CEA90: nop

    func_800CE3E0(rdram, ctx);
        goto after_0;
    // 0x800CEA90: nop

    after_0:
    // 0x800CEA94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CEA98: lh          $v0, 0xA($v0)
    ctx->r2 = MEM_H(ctx->r2, 0XA);
    // 0x800CEA9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CEAA0: jr          $ra
    // 0x800CEAA4: nop

    return;
    // 0x800CEAA4: nop

;}
RECOMP_FUNC void func_80801008_chonearmbandit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801008: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080100C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80801010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801014: bne         $a1, $at, L_8080102C
    if (ctx->r5 != ctx->r1) {
        // 0x80801018: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_8080102C;
    }
    // 0x80801018: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080101C: jal         0x808010AC
    // 0x80801020: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_808010AC_chonearmbandit(rdram, ctx);
        goto after_0;
    // 0x80801020: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80801024: b           L_80801030
    // 0x80801028: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801030;
    // 0x80801028: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080102C:
    // 0x8080102C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801030:
    // 0x80801030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801034: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801038: jr          $ra
    // 0x8080103C: nop

    return;
    // 0x8080103C: nop

;}
RECOMP_FUNC void chLagoonInnBlockedWall_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003D0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2020, 0X570) << 16);
    // 0x808003D4: jr          $ra
    // 0x808003D8: addiu       $v0, $v0, 0x570
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2020, 0X570));
    return;
    // 0x808003D8: addiu       $v0, $v0, 0x570
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2020, 0X570));
    // 0x808003DC: nop

;}
RECOMP_FUNC void func_808020CC_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808020CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808020D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808020D4: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x808020D8: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x808020DC: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x808020E0: beql        $a1, $t8, L_80802180
    if (ctx->r5 == ctx->r24) {
        // 0x808020E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80802180;
    }
    goto skip_0;
    // 0x808020E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808020E8: beql        $a1, $zero, L_80802130
    if (ctx->r5 == 0) {
        // 0x808020EC: lbu         $v0, 0x79($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X79);
            goto L_80802130;
    }
    goto skip_1;
    // 0x808020EC: lbu         $v0, 0x79($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X79);
    skip_1:
    // 0x808020F0: lbu         $v0, 0x79($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X79);
    // 0x808020F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808020F8: srl         $t9, $v0, 4
    ctx->r25 = S32(U32(ctx->r2) >> 4);
    // 0x808020FC: beql        $t9, $zero, L_80802168
    if (ctx->r25 == 0) {
        // 0x80802100: lbu         $t4, 0x65($a0)
        ctx->r12 = MEM_BU(ctx->r4, 0X65);
            goto L_80802168;
    }
    goto skip_2;
    // 0x80802100: lbu         $t4, 0x65($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X65);
    skip_2:
    // 0x80802104: beq         $t9, $at, L_80802164
    if (ctx->r25 == ctx->r1) {
        // 0x80802108: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80802164;
    }
    // 0x80802108: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080210C: beql        $t9, $at, L_80802168
    if (ctx->r25 == ctx->r1) {
        // 0x80802110: lbu         $t4, 0x65($a0)
        ctx->r12 = MEM_BU(ctx->r4, 0X65);
            goto L_80802168;
    }
    goto skip_3;
    // 0x80802110: lbu         $t4, 0x65($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X65);
    skip_3:
    // 0x80802114: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80802118: jal         0x80089CB0
    // 0x8080211C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    _subaddiefade_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x8080211C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80802120: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80802124: b           L_80802164
    // 0x80802128: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
        goto L_80802164;
    // 0x80802128: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8080212C: lbu         $v0, 0x79($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X79);
L_80802130:
    // 0x80802130: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80802134: srl         $t0, $v0, 4
    ctx->r8 = S32(U32(ctx->r2) >> 4);
    // 0x80802138: beql        $t0, $zero, L_80802168
    if (ctx->r8 == 0) {
        // 0x8080213C: lbu         $t4, 0x65($a0)
        ctx->r12 = MEM_BU(ctx->r4, 0X65);
            goto L_80802168;
    }
    goto skip_4;
    // 0x8080213C: lbu         $t4, 0x65($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X65);
    skip_4:
    // 0x80802140: beq         $t0, $at, L_80802164
    if (ctx->r8 == ctx->r1) {
        // 0x80802144: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80802164;
    }
    // 0x80802144: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80802148: beql        $t0, $at, L_80802168
    if (ctx->r8 == ctx->r1) {
        // 0x8080214C: lbu         $t4, 0x65($a0)
        ctx->r12 = MEM_BU(ctx->r4, 0X65);
            goto L_80802168;
    }
    goto skip_5;
    // 0x8080214C: lbu         $t4, 0x65($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X65);
    skip_5:
    // 0x80802150: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80802154: jal         0x80089CB8
    // 0x80802158: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    _subaddiefade_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80802158: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x8080215C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80802160: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
L_80802164:
    // 0x80802164: lbu         $t4, 0x65($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X65);
L_80802168:
    // 0x80802168: sll         $t2, $a1, 3
    ctx->r10 = S32(ctx->r5 << 3);
    // 0x8080216C: andi        $t3, $t2, 0x8
    ctx->r11 = ctx->r10 & 0X8;
    // 0x80802170: andi        $t5, $t4, 0xFFF7
    ctx->r13 = ctx->r12 & 0XFFF7;
    // 0x80802174: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x80802178: sb          $t6, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r14;
    // 0x8080217C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802180:
    // 0x80802180: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802184: jr          $ra
    // 0x80802188: nop

    return;
    // 0x80802188: nop

;}
RECOMP_FUNC void subaddieDll_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800114: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800118: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080011C: lw          $v0, 0x70($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X70);
    // 0x80800120: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800124: srl         $v1, $v0, 25
    ctx->r3 = S32(U32(ctx->r2) >> 25);
    // 0x80800128: beq         $v1, $zero, L_8080013C
    if (ctx->r3 == 0) {
        // 0x8080012C: sll         $t0, $v0, 22
        ctx->r8 = S32(ctx->r2 << 22);
            goto L_8080013C;
    }
    // 0x8080012C: sll         $t0, $v0, 22
    ctx->r8 = S32(ctx->r2 << 22);
    // 0x80800130: srl         $t6, $t0, 26
    ctx->r14 = S32(U32(ctx->r8) >> 26);
    // 0x80800134: bne         $t6, $zero, L_80800144
    if (ctx->r14 != 0) {
        // 0x80800138: or          $t0, $t6, $zero
        ctx->r8 = ctx->r14 | 0;
            goto L_80800144;
    }
    // 0x80800138: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
L_8080013C:
    // 0x8080013C: b           L_8080018C
    // 0x80800140: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080018C;
    // 0x80800140: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800144:
    // 0x80800144: addiu       $a0, $a3, 0x4
    ctx->r4 = ADD32(ctx->r7, 0X4);
    // 0x80800148: addiu       $a1, $v1, -0x1
    ctx->r5 = ADD32(ctx->r3, -0X1);
    // 0x8080014C: addiu       $a2, $t0, -0x1
    ctx->r6 = ADD32(ctx->r8, -0X1);
    // 0x80800150: jal         0x800CC338
    // 0x80800154: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800CC338(rdram, ctx);
        goto after_0;
    // 0x80800154: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800158: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8080015C: beq         $v0, $at, L_80800188
    if (ctx->r2 == ctx->r1) {
        // 0x80800160: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_80800188;
    }
    // 0x80800160: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80800164: lhu         $t2, 0x72($a3)
    ctx->r10 = MEM_HU(ctx->r7, 0X72);
    // 0x80800168: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x8080016C: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80800170: andi        $t1, $t9, 0x3F0
    ctx->r9 = ctx->r25 & 0X3F0;
    // 0x80800174: andi        $t3, $t2, 0xFC0F
    ctx->r11 = ctx->r10 & 0XFC0F;
    // 0x80800178: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x8080017C: sh          $t4, 0x72($a3)
    MEM_H(0X72, ctx->r7) = ctx->r12;
    // 0x80800180: b           L_8080018C
    // 0x80800184: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080018C;
    // 0x80800184: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800188:
    // 0x80800188: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080018C:
    // 0x8080018C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800190: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800194: jr          $ra
    // 0x80800198: nop

    return;
    // 0x80800198: nop

;}
RECOMP_FUNC void func_8080000C_changlerbossflare(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800010: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800014: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800018: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080001C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1336, 0X4C8) << 16);
    // 0x80800020: addiu       $a2, $a2, 0x4C8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1336, 0X4C8));
    // 0x80800024: jal         0x80089D18
    // 0x80800028: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800028: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_0:
    // 0x8080002C: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800030: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800034: jal         0x8010A3E8
    // 0x80800038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A3E8(rdram, ctx);
        goto after_1;
    // 0x80800038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080003C: jal         0x800C8A98
    // 0x80800040: nop

    func_800C8A98(rdram, ctx);
        goto after_2;
    // 0x80800040: nop

    after_2:
    // 0x80800044: lbu         $t7, 0x73($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X73);
    // 0x80800048: sw          $v0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r2;
    // 0x8080004C: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80800050: sb          $t8, 0x73($s0)
    MEM_B(0X73, ctx->r16) = ctx->r24;
    // 0x80800054: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800058: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080005C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800060: jr          $ra
    // 0x80800064: nop

    return;
    // 0x80800064: nop

;}
RECOMP_FUNC void _chattract_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085C08: syscall     208
    recomp_syscall_handler(rdram, ctx, 0x80085C08);
    return;
    // 0x80085C0C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_8080120C_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080120C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801210: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801214: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80801218: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080121C: jal         0x80100094
    // 0x80801220: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801220: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801224: lbu         $t6, 0x3C($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X3C);
    // 0x80801228: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080122C: addiu       $a0, $zero, 0x65A
    ctx->r4 = ADD32(0, 0X65A);
    // 0x80801230: beql        $t6, $zero, L_8080127C
    if (ctx->r14 == 0) {
        // 0x80801234: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080127C;
    }
    goto skip_0;
    // 0x80801234: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80801238: jal         0x800DA3B8
    // 0x8080123C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DA3B8(rdram, ctx);
        goto after_1;
    // 0x8080123C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80801240: lbu         $t7, 0x39($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X39);
    // 0x80801244: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801248: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080124C: bne         $t7, $at, L_80801278
    if (ctx->r15 != ctx->r1) {
        // 0x80801250: addiu       $s1, $zero, 0x8
        ctx->r17 = ADD32(0, 0X8);
            goto L_80801278;
    }
    // 0x80801250: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
L_80801254:
    // 0x80801254: jal         0x800F6438
    // 0x80801258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6438(rdram, ctx);
        goto after_2;
    // 0x80801258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080125C: beql        $v0, $zero, L_80801270
    if (ctx->r2 == 0) {
        // 0x80801260: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80801270;
    }
    goto skip_1;
    // 0x80801260: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x80801264: jal         0x800F4CC0
    // 0x80801268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F4CC0(rdram, ctx);
        goto after_3;
    // 0x80801268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080126C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80801270:
    // 0x80801270: bne         $s0, $s1, L_80801254
    if (ctx->r16 != ctx->r17) {
        // 0x80801274: nop
    
            goto L_80801254;
    }
    // 0x80801274: nop

L_80801278:
    // 0x80801278: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080127C:
    // 0x8080127C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801280: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801284: jr          $ra
    // 0x80801288: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80801288: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _chjollyroger_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085F68: syscall     264
    recomp_syscall_handler(rdram, ctx, 0x80085F68);
    return;
    // 0x80085F6C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void idlight_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080025C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800260: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2898, 0X310) << 16);
    // 0x80800264: lwc1        $f12, 0x310($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2898, 0X310));
    // 0x80800268: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080026C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2898, 0X314) << 16);
    // 0x80800270: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800274: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800278: lwc1        $f14, 0x314($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2898, 0X314));
    // 0x8080027C: jal         0x800DC264
    // 0x80800280: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800DC264(rdram, ctx);
        goto after_0;
    // 0x80800280: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    if (tooie_light_effect_skip(rdram, ctx)) { ctx->f0.fl = 0.0f; }
    // 0x80800284: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80800288: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080028C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800290: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80800294: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80800298: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2898, 0X318) << 16);
    // 0x8080029C: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x808002A0: addiu       $a2, $a2, -0x7308
    ctx->r6 = ADD32(ctx->r6, -0X7308);
    // 0x808002A4: swc1        $f6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
    // 0x808002A8: lwc1        $f2, 0x0($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X0);
    // 0x808002AC: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x808002B0: nop

    // 0x808002B4: bc1fl       L_808002C8
    if (!c1cs) {
        // 0x808002B8: swc1        $f2, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->f2.u32l;
            goto L_808002C8;
    }
    goto skip_0;
    // 0x808002B8: swc1        $f2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f2.u32l;
    skip_0:
    // 0x808002BC: b           L_808002C8
    // 0x808002C0: swc1        $f12, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f12.u32l;
        goto L_808002C8;
    // 0x808002C0: swc1        $f12, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f12.u32l;
    // 0x808002C4: swc1        $f2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f2.u32l;
L_808002C8:
    // 0x808002C8: lwc1        $f0, 0x318($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2898, 0X318));
    // 0x808002CC: lwc1        $f2, 0x0($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X0);
    // 0x808002D0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x808002D4: nop

    // 0x808002D8: bc1fl       L_808002EC
    if (!c1cs) {
        // 0x808002DC: swc1        $f2, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->f2.u32l;
            goto L_808002EC;
    }
    goto skip_1;
    // 0x808002DC: swc1        $f2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f2.u32l;
    skip_1:
    // 0x808002E0: b           L_808002EC
    // 0x808002E4: swc1        $f0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
        goto L_808002EC;
    // 0x808002E4: swc1        $f0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
    // 0x808002E8: swc1        $f2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f2.u32l;
L_808002EC:
    // 0x808002EC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808002F0: jal         0x80088660
    // 0x808002F4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _glid_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808002F4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808002F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800300: jr          $ra
    // 0x80800304: nop

    return;
    // 0x80800304: nop

    // 0x80800308: nop

    // 0x8080030C: nop

;}
RECOMP_FUNC void func_800E7BC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E7BC8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E7BCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E7BD0: jal         0x8001A0A8
    // 0x800E7BD4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8001A0A8(rdram, ctx);
        goto after_0;
    // 0x800E7BD4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x800E7BD8: beql        $v0, $zero, L_800E7C1C
    if (ctx->r2 == 0) {
        // 0x800E7BDC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800E7C1C;
    }
    goto skip_0;
    // 0x800E7BDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800E7BE0: jal         0x800A8184
    // 0x800E7BE4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800A8184(rdram, ctx);
        goto after_1;
    // 0x800E7BE4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x800E7BE8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800E7BEC: beq         $v0, $at, L_800E7C18
    if (ctx->r2 == ctx->r1) {
        // 0x800E7BF0: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_800E7C18;
    }
    // 0x800E7BF0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800E7BF4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800E7BF8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800E7BFC: addu        $t8, $a0, $at
    ctx->r24 = ADD32(ctx->r4, ctx->r1);
    // 0x800E7C00: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800E7C04: lui         $t7, 0xFE00
    ctx->r15 = S32(0XFE00 << 16);
    // 0x800E7C08: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800E7C0C: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800E7C10: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800E7C14: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_800E7C18:
    // 0x800E7C18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E7C1C:
    // 0x800E7C1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800E7C20: jr          $ra
    // 0x800E7C24: nop

    return;
    // 0x800E7C24: nop

;}
RECOMP_FUNC void _bsbtrot_entrypoint_34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082CD0: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082CD0);
    return;
    // 0x80082CD4: addi        $t0, $zero, 0x88
    ctx->r8 = ADD32(0, 0X88);
;}
RECOMP_FUNC void func_800E401C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E401C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E4020: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E4024: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E4028: jal         0x800CA7A4
    // 0x800E402C: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    func_800CA7A4(rdram, ctx);
        goto after_0;
    // 0x800E402C: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    after_0:
    // 0x800E4030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E4034: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E4038: jr          $ra
    // 0x800E403C: nop

    return;
    // 0x800E403C: nop

;}
RECOMP_FUNC void chsunlightspell_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800830: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2244, 0X8BC) << 16);
    // 0x80800834: jr          $ra
    // 0x80800838: addiu       $v0, $v0, 0x8BC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2244, 0X8BC));
    return;
    // 0x80800838: addiu       $v0, $v0, 0x8BC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2244, 0X8BC));
    // 0x8080083C: nop

;}
RECOMP_FUNC void func_8080020C_cheel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080020C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800210: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800214: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800218: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080021C: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x80800220: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    // 0x80800224: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800228: jal         0x800EEC30
    // 0x8080022C: lui         $a3, 0x4348
    ctx->r7 = S32(0X4348 << 16);
    func_800EEC30(rdram, ctx);
        goto after_0;
    // 0x8080022C: lui         $a3, 0x4348
    ctx->r7 = S32(0X4348 << 16);
    after_0:
    // 0x80800230: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800234: jal         0x800EF04C
    // 0x80800238: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_1;
    // 0x80800238: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x8080023C: lw          $v0, 0x70($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X70);
    // 0x80800240: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800244: sll         $a2, $v0, 22
    ctx->r6 = S32(ctx->r2 << 22);
    // 0x80800248: srl         $t6, $a2, 26
    ctx->r14 = S32(U32(ctx->r6) >> 26);
    // 0x8080024C: srl         $a1, $v0, 25
    ctx->r5 = S32(U32(ctx->r2) >> 25);
    // 0x80800250: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80800254: jal         0x800CC338
    // 0x80800258: addiu       $a2, $t6, -0x1
    ctx->r6 = ADD32(ctx->r14, -0X1);
    func_800CC338(rdram, ctx);
        goto after_2;
    // 0x80800258: addiu       $a2, $t6, -0x1
    ctx->r6 = ADD32(ctx->r14, -0X1);
    after_2:
    // 0x8080025C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800260: beq         $v0, $at, L_80800288
    if (ctx->r2 == ctx->r1) {
        // 0x80800264: addiu       $t8, $v0, 0x1
        ctx->r24 = ADD32(ctx->r2, 0X1);
            goto L_80800288;
    }
    // 0x80800264: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x80800268: lhu         $t1, 0x72($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X72);
    // 0x8080026C: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80800270: andi        $t0, $t9, 0x3F0
    ctx->r8 = ctx->r25 & 0X3F0;
    // 0x80800274: andi        $t2, $t1, 0xFC0F
    ctx->r10 = ctx->r9 & 0XFC0F;
    // 0x80800278: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x8080027C: sh          $t3, 0x72($s0)
    MEM_H(0X72, ctx->r16) = ctx->r11;
    // 0x80800280: b           L_8080028C
    // 0x80800284: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080028C;
    // 0x80800284: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800288:
    // 0x80800288: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080028C:
    // 0x8080028C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800290: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800294: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800298: jr          $ra
    // 0x8080029C: nop

    return;
    // 0x8080029C: nop

;}
RECOMP_FUNC void func_800FFECC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FFECC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800FFED0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FFED4: beq         $a2, $zero, L_80100024
    if (ctx->r6 == 0) {
        // 0x800FFED8: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80100024;
    }
    // 0x800FFED8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800FFEDC: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x800FFEE0: addu        $t1, $a0, $t6
    ctx->r9 = ADD32(ctx->r4, ctx->r14);
    // 0x800FFEE4: lh          $a0, 0x82($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X82);
    // 0x800FFEE8: lui         $at, 0x7FFF
    ctx->r1 = S32(0X7FFF << 16);
    // 0x800FFEEC: ori         $at, $at, 0xFFFC
    ctx->r1 = ctx->r1 | 0XFFFC;
    // 0x800FFEF0: beq         $a0, $zero, L_800FFFC4
    if (ctx->r4 == 0) {
        // 0x800FFEF4: addiu       $a1, $a2, 0x3
        ctx->r5 = ADD32(ctx->r6, 0X3);
            goto L_800FFFC4;
    }
    // 0x800FFEF4: addiu       $a1, $a2, 0x3
    ctx->r5 = ADD32(ctx->r6, 0X3);
    // 0x800FFEF8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800FFEFC: jal         0x8001B7B8
    // 0x800FFF00: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    func_8001B7B8(rdram, ctx);
        goto after_0;
    // 0x800FFF00: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    after_0:
    // 0x800FFF04: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800FFF08: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800FFF0C: lui         $at, 0x7FFF
    ctx->r1 = S32(0X7FFF << 16);
    // 0x800FFF10: ori         $at, $at, 0xFFFC
    ctx->r1 = ctx->r1 | 0XFFFC;
    // 0x800FFF14: addiu       $a1, $a2, 0x3
    ctx->r5 = ADD32(ctx->r6, 0X3);
    // 0x800FFF18: and         $t7, $a1, $at
    ctx->r15 = ctx->r5 & ctx->r1;
    // 0x800FFF1C: lh          $a0, 0x82($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X82);
    // 0x800FFF20: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800FFF24: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800FFF28: jal         0x8001B710
    // 0x800FFF2C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    func_8001B710(rdram, ctx);
        goto after_1;
    // 0x800FFF2C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_1:
    // 0x800FFF30: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800FFF34: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800FFF38: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800FFF3C: sra         $a2, $a1, 2
    ctx->r6 = S32(SIGNED(ctx->r5) >> 2);
    // 0x800FFF40: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800FFF44: beq         $at, $zero, L_8010001C
    if (ctx->r1 == 0) {
        // 0x800FFF48: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_8010001C;
    }
    // 0x800FFF48: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800FFF4C: sra         $a3, $v1, 2
    ctx->r7 = S32(SIGNED(ctx->r3) >> 2);
    // 0x800FFF50: slt         $at, $a2, $a3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800FFF54: bne         $at, $zero, L_8010001C
    if (ctx->r1 != 0) {
        // 0x800FFF58: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8010001C;
    }
    // 0x800FFF58: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800FFF5C: subu        $t0, $a2, $a3
    ctx->r8 = SUB32(ctx->r6, ctx->r7);
    // 0x800FFF60: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800FFF64: andi        $t8, $t0, 0x3
    ctx->r24 = ctx->r8 & 0X3;
    // 0x800FFF68: negu        $t0, $t8
    ctx->r8 = SUB32(0, ctx->r24);
    // 0x800FFF6C: beq         $t0, $zero, L_800FFF94
    if (ctx->r8 == 0) {
        // 0x800FFF70: addu        $a1, $t0, $a2
        ctx->r5 = ADD32(ctx->r8, ctx->r6);
            goto L_800FFF94;
    }
    // 0x800FFF70: addu        $a1, $t0, $a2
    ctx->r5 = ADD32(ctx->r8, ctx->r6);
    // 0x800FFF74: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800FFF78: addu        $v1, $v0, $t9
    ctx->r3 = ADD32(ctx->r2, ctx->r25);
L_800FFF7C:
    // 0x800FFF7C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800FFF80: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800FFF84: bne         $a1, $a0, L_800FFF7C
    if (ctx->r5 != ctx->r4) {
        // 0x800FFF88: addiu       $v1, $v1, -0x4
        ctx->r3 = ADD32(ctx->r3, -0X4);
            goto L_800FFF7C;
    }
    // 0x800FFF88: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x800FFF8C: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
    // 0x800FFF90: beq         $t2, $a3, L_8010001C
    if (ctx->r10 == ctx->r7) {
        // 0x800FFF94: sll         $t3, $a0, 2
        ctx->r11 = S32(ctx->r4 << 2);
            goto L_8010001C;
    }
L_800FFF94:
    // 0x800FFF94: sll         $t3, $a0, 2
    ctx->r11 = S32(ctx->r4 << 2);
    // 0x800FFF98: addu        $v1, $v0, $t3
    ctx->r3 = ADD32(ctx->r2, ctx->r11);
    // 0x800FFF9C: addiu       $a1, $a3, -0x1
    ctx->r5 = ADD32(ctx->r7, -0X1);
L_800FFFA0:
    // 0x800FFFA0: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x800FFFA4: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x800FFFA8: sw          $zero, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = 0;
    // 0x800FFFAC: sw          $zero, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = 0;
    // 0x800FFFB0: addiu       $v1, $v1, -0x10
    ctx->r3 = ADD32(ctx->r3, -0X10);
    // 0x800FFFB4: bne         $a0, $a1, L_800FFFA0
    if (ctx->r4 != ctx->r5) {
        // 0x800FFFB8: sw          $zero, 0x10($v1)
        MEM_W(0X10, ctx->r3) = 0;
            goto L_800FFFA0;
    }
    // 0x800FFFB8: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    // 0x800FFFBC: b           L_8010001C
    // 0x800FFFC0: nop

        goto L_8010001C;
    // 0x800FFFC0: nop

L_800FFFC4:
    // 0x800FFFC4: and         $t4, $a1, $at
    ctx->r12 = ctx->r5 & ctx->r1;
    // 0x800FFFC8: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x800FFFCC: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x800FFFD0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800FFFD4: jal         0x8001B668
    // 0x800FFFD8: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    func_8001B668(rdram, ctx);
        goto after_2;
    // 0x800FFFD8: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    after_2:
    // 0x800FFFDC: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800FFFE0: sh          $v0, 0x82($t1)
    MEM_H(0X82, ctx->r9) = ctx->r2;
    // 0x800FFFE4: jal         0x8001B798
    // 0x800FFFE8: lh          $a0, 0x82($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X82);
    func_8001B798(rdram, ctx);
        goto after_3;
    // 0x800FFFE8: lh          $a0, 0x82($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X82);
    after_3:
    // 0x800FFFEC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800FFFF0: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800FFFF4: sra         $a2, $a1, 2
    ctx->r6 = S32(SIGNED(ctx->r5) >> 2);
    // 0x800FFFF8: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800FFFFC: bltz        $a2, L_8010001C
    if (SIGNED(ctx->r6) < 0) {
        // 0x80100000: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8010001C;
    }
    // 0x80100000: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80100004: sll         $t5, $a2, 2
    ctx->r13 = S32(ctx->r6 << 2);
    // 0x80100008: addu        $v1, $v0, $t5
    ctx->r3 = ADD32(ctx->r2, ctx->r13);
L_8010000C:
    // 0x8010000C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80100010: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x80100014: bgez        $a0, L_8010000C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80100018: sw          $zero, 0x4($v1)
        MEM_W(0X4, ctx->r3) = 0;
            goto L_8010000C;
    }
    // 0x80100018: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
L_8010001C:
    // 0x8010001C: b           L_8010004C
    // 0x80100020: lh          $a0, 0x82($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X82);
        goto L_8010004C;
    // 0x80100020: lh          $a0, 0x82($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X82);
L_80100024:
    // 0x80100024: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x80100028: addu        $t1, $a3, $t6
    ctx->r9 = ADD32(ctx->r7, ctx->r14);
    // 0x8010002C: lh          $a0, 0x82($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X82);
    // 0x80100030: beq         $a0, $zero, L_8010004C
    if (ctx->r4 == 0) {
        // 0x80100034: nop
    
            goto L_8010004C;
    }
    // 0x80100034: nop

    // 0x80100038: jal         0x8001B754
    // 0x8010003C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    func_8001B754(rdram, ctx);
        goto after_4;
    // 0x8010003C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    after_4:
    // 0x80100040: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80100044: sh          $zero, 0x82($t1)
    MEM_H(0X82, ctx->r9) = 0;
    // 0x80100048: lh          $a0, 0x82($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X82);
L_8010004C:
    // 0x8010004C: beq         $a0, $zero, L_80100064
    if (ctx->r4 == 0) {
        // 0x80100050: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80100064;
    }
    // 0x80100050: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80100054: jal         0x8001B798
    // 0x80100058: nop

    func_8001B798(rdram, ctx);
        goto after_5;
    // 0x80100058: nop

    after_5:
    // 0x8010005C: b           L_80100068
    // 0x80100060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80100068;
    // 0x80100060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80100064:
    // 0x80100064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80100068:
    // 0x80100068: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8010006C: jr          $ra
    // 0x80100070: nop

    return;
    // 0x80100070: nop

;}
RECOMP_FUNC void _chlilterry_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086028: syscall     272
    recomp_syscall_handler(rdram, ctx, 0x80086028);
    return;
    // 0x8008602C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80026E90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026E90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80026E94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80026E98: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80026E9C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80026EA0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80026EA4: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x80026EA8: beq         $t7, $zero, L_80026F28
    if (ctx->r15 == 0) {
        // 0x80026EAC: nop
    
            goto L_80026F28;
    }
    // 0x80026EAC: nop

    // 0x80026EB0: jal         0x80021794
    // 0x80026EB4: nop

    func_80021794(rdram, ctx);
        goto after_0;
    // 0x80026EB4: nop

    after_0:
    // 0x80026EB8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80026EBC: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80026EC0: bne         $t8, $zero, L_80026ED0
    if (ctx->r24 != 0) {
        // 0x80026EC4: nop
    
            goto L_80026ED0;
    }
    // 0x80026EC4: nop

    // 0x80026EC8: b           L_80026F30
    // 0x80026ECC: nop

        goto L_80026F30;
    // 0x80026ECC: nop

L_80026ED0:
    // 0x80026ED0: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80026ED4: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80026ED8: lw          $t9, 0x11F4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X11F4);
    // 0x80026EDC: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x80026EE0: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80026EE4: lw          $t0, 0x1C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1C);
    // 0x80026EE8: lw          $t3, 0x88($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X88);
    // 0x80026EEC: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x80026EF0: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x80026EF4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80026EF8: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80026EFC: sh          $t6, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r14;
    // 0x80026F00: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80026F04: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80026F08: swc1        $f4, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f4.u32l;
    // 0x80026F0C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80026F10: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x80026F14: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80026F18: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80026F1C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80026F20: jal         0x8002B684
    // 0x80026F24: lw          $a0, 0x8($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X8);
    func_8002B684(rdram, ctx);
        goto after_1;
    // 0x80026F24: lw          $a0, 0x8($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X8);
    after_1:
L_80026F28:
    // 0x80026F28: b           L_80026F30
    // 0x80026F2C: nop

        goto L_80026F30;
    // 0x80026F2C: nop

L_80026F30:
    // 0x80026F30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80026F34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80026F38: jr          $ra
    // 0x80026F3C: nop

    return;
    // 0x80026F3C: nop

;}
RECOMP_FUNC void func_800972BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800972BC: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800972C0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800972C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800972C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800972CC: jal         0x800EE7F8
    // 0x800972D0: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800972D0: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_0:
    // 0x800972D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800972D8: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x800972DC: jal         0x80095870
    // 0x800972E0: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    func_80095870(rdram, ctx);
        goto after_1;
    // 0x800972E0: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    after_1:
    // 0x800972E4: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800972E8: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800972EC: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800972F0: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x800972F4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800972F8: lwc1        $f18, 0x60($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800972FC: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80097300: swc1        $f16, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f16.u32l;
    // 0x80097304: lw          $a0, 0x98($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X98);
    // 0x80097308: lbu         $t6, 0x24($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X24);
    // 0x8009730C: beql        $t6, $zero, L_80097324
    if (ctx->r14 == 0) {
        // 0x80097310: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_80097324;
    }
    goto skip_0;
    // 0x80097310: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x80097314: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80097318: b           L_8009732C
    // 0x8009731C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
        goto L_8009732C;
    // 0x8009731C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80097320: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80097324:
    // 0x80097324: nop

    // 0x80097328: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
L_8009732C:
    // 0x8009732C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80097330: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80097334: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80097338: neg.s       $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = -ctx->f18.fl;
    // 0x8009733C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80097340: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80097344: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80097348: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x8009734C: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80097350: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80097354: jal         0x80096E30
    // 0x80097358: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_80096E30(rdram, ctx);
        goto after_2;
    // 0x80097358: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x8009735C: sltiu       $at, $v0, 0x5
    ctx->r1 = ctx->r2 < 0X5 ? 1 : 0;
    // 0x80097360: beq         $at, $zero, L_800973D0
    if (ctx->r1 == 0) {
        // 0x80097364: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_800973D0;
    }
    // 0x80097364: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80097368: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009736C: addu        $at, $at, $t7
    gpr jr_addend_80097374 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80097370: lw          $t7, 0x4E00($at)
    ctx->r15 = ADD32(ctx->r1, 0X4E00);
    // 0x80097374: jr          $t7
    // 0x80097378: nop

    switch (jr_addend_80097374 >> 2) {
        case 0: goto L_8009737C; break;
        case 1: goto L_80097390; break;
        case 2: goto L_800973B8; break;
        case 3: goto L_800973C8; break;
        case 4: goto L_800973A4; break;
        default: switch_error(__func__, 0x80097374, 0x80124E00);
    }
    // 0x80097378: nop

L_8009737C:
    // 0x8009737C: lw          $t9, 0x98($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X98);
    // 0x80097380: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80097384: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80097388: b           L_800974E8
    // 0x8009738C: sb          $t8, 0x25($t9)
    MEM_B(0X25, ctx->r25) = ctx->r24;
        goto L_800974E8;
    // 0x8009738C: sb          $t8, 0x25($t9)
    MEM_B(0X25, ctx->r25) = ctx->r24;
L_80097390:
    // 0x80097390: lw          $t1, 0x98($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X98);
    // 0x80097394: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x80097398: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8009739C: b           L_800974E8
    // 0x800973A0: sb          $t0, 0x25($t1)
    MEM_B(0X25, ctx->r9) = ctx->r8;
        goto L_800974E8;
    // 0x800973A0: sb          $t0, 0x25($t1)
    MEM_B(0X25, ctx->r9) = ctx->r8;
L_800973A4:
    // 0x800973A4: lw          $t3, 0x98($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X98);
    // 0x800973A8: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x800973AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800973B0: b           L_800974E8
    // 0x800973B4: sb          $t2, 0x25($t3)
    MEM_B(0X25, ctx->r11) = ctx->r10;
        goto L_800974E8;
    // 0x800973B4: sb          $t2, 0x25($t3)
    MEM_B(0X25, ctx->r11) = ctx->r10;
L_800973B8:
    // 0x800973B8: lw          $t5, 0x98($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X98);
    // 0x800973BC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800973C0: b           L_800973D0
    // 0x800973C4: sb          $t4, 0x24($t5)
    MEM_B(0X24, ctx->r13) = ctx->r12;
        goto L_800973D0;
    // 0x800973C4: sb          $t4, 0x24($t5)
    MEM_B(0X24, ctx->r13) = ctx->r12;
L_800973C8:
    // 0x800973C8: lw          $t6, 0x98($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X98);
    // 0x800973CC: sb          $zero, 0x24($t6)
    MEM_B(0X24, ctx->r14) = 0;
L_800973D0:
    // 0x800973D0: lw          $a0, 0x98($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X98);
    // 0x800973D4: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x800973D8: jal         0x800EE7F8
    // 0x800973DC: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x800973DC: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_3:
    // 0x800973E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800973E4: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x800973E8: jal         0x80097104
    // 0x800973EC: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    func_80097104(rdram, ctx);
        goto after_4;
    // 0x800973EC: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    after_4:
    // 0x800973F0: bne         $v0, $zero, L_80097400
    if (ctx->r2 != 0) {
        // 0x800973F4: lwc1        $f4, 0x60($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
            goto L_80097400;
    }
    // 0x800973F4: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800973F8: b           L_800974E8
    // 0x800973FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800974E8;
    // 0x800973FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80097400:
    // 0x80097400: lui         $at, 0xC190
    ctx->r1 = S32(0XC190 << 16);
    // 0x80097404: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80097408: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8009740C: lw          $a1, 0x98($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X98);
    // 0x80097410: add.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80097414: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80097418: jal         0x800EFA20
    // 0x8009741C: nop

    func_800EFA20(rdram, ctx);
        goto after_5;
    // 0x8009741C: nop

    after_5:
    // 0x80097420: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80097424: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80097428: jal         0x800EFB24
    // 0x8009742C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    func_800EFB24(rdram, ctx);
        goto after_6;
    // 0x8009742C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_6:
    // 0x80097430: lui         $at, 0xC22C
    ctx->r1 = S32(0XC22C << 16);
    // 0x80097434: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80097438: lwc1        $f0, 0x5C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8009743C: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80097440: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80097444: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80097448: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8009744C: sub.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x80097450: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x80097454: mul.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80097458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009745C: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80097460: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80097464: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80097468: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x8009746C: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    // 0x80097470: add.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80097474: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80097478: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8009747C: jal         0x8009700C
    // 0x80097480: nop

    func_8009700C(rdram, ctx);
        goto after_7;
    // 0x80097480: nop

    after_7:
    // 0x80097484: beq         $v0, $zero, L_800974C8
    if (ctx->r2 == 0) {
        // 0x80097488: lwc1        $f6, 0x3C($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
            goto L_800974C8;
    }
    // 0x80097488: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8009748C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80097490: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80097494: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80097498: nop

    // 0x8009749C: bc1fl       L_800974B8
    if (!c1cs) {
        // 0x800974A0: lw          $t0, 0x98($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X98);
            goto L_800974B8;
    }
    goto skip_1;
    // 0x800974A0: lw          $t0, 0x98($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X98);
    skip_1:
    // 0x800974A4: lw          $t8, 0x98($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X98);
    // 0x800974A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800974AC: b           L_800974E8
    // 0x800974B0: sb          $t7, 0x25($t8)
    MEM_B(0X25, ctx->r24) = ctx->r15;
        goto L_800974E8;
    // 0x800974B0: sb          $t7, 0x25($t8)
    MEM_B(0X25, ctx->r24) = ctx->r15;
    // 0x800974B4: lw          $t0, 0x98($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X98);
L_800974B8:
    // 0x800974B8: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x800974BC: sb          $t9, 0x25($t0)
    MEM_B(0X25, ctx->r8) = ctx->r25;
    // 0x800974C0: b           L_800974E8
    // 0x800974C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800974E8;
    // 0x800974C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800974C8:
    // 0x800974C8: lw          $a0, 0x98($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X98);
    // 0x800974CC: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x800974D0: jal         0x800EE7F8
    // 0x800974D4: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_8;
    // 0x800974D4: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_8:
    // 0x800974D8: lw          $t2, 0x98($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X98);
    // 0x800974DC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800974E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800974E4: sb          $t1, 0x25($t2)
    MEM_B(0X25, ctx->r10) = ctx->r9;
L_800974E8:
    // 0x800974E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800974EC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800974F0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x800974F4: jr          $ra
    // 0x800974F8: nop

    return;
    // 0x800974F8: nop

;}
RECOMP_FUNC void _gcstatusDll_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088328: syscall     679
    recomp_syscall_handler(rdram, ctx, 0x80088328);
    return;
    // 0x8008832C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800E0960(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E0960: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E0964: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800E0968: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800E096C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E0970: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800E0974: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800E0978: jal         0x8001ACCC
    // 0x800E097C: addiu       $a0, $t6, 0x20
    ctx->r4 = ADD32(ctx->r14, 0X20);
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x800E097C: addiu       $a0, $t6, 0x20
    ctx->r4 = ADD32(ctx->r14, 0X20);
    after_0:
    // 0x800E0980: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800E0984: addiu       $t7, $v0, 0x20
    ctx->r15 = ADD32(ctx->r2, 0X20);
    // 0x800E0988: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800E098C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800E0990: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800E0994: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800E0998: sh          $t8, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r24;
    // 0x800E099C: jal         0x800E0ACC
    // 0x800E09A0: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    func_800E0ACC(rdram, ctx);
        goto after_1;
    // 0x800E09A0: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    after_1:
    // 0x800E09A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E09A8: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x800E09AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800E09B0: jr          $ra
    // 0x800E09B4: nop

    return;
    // 0x800E09B4: nop

;}
RECOMP_FUNC void func_80800D9C_chdippy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D9C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800DA0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800DA4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800DA8: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800DAC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800DB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800DB4: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800DB8: beq         $t6, $at, L_80801044
    if (ctx->r14 == ctx->r1) {
        // 0x80800DBC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80801044;
    }
    // 0x80800DBC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800DC0: beq         $t6, $at, L_80800DDC
    if (ctx->r14 == ctx->r1) {
        // 0x80800DC4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800DDC;
    }
    // 0x80800DC4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800DC8: beq         $t6, $at, L_80801044
    if (ctx->r14 == ctx->r1) {
        // 0x80800DCC: lui         $t7, 0x8008
        ctx->r15 = S32(0X8008 << 16);
            goto L_80801044;
    }
    // 0x80800DCC: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80800DD0: addiu       $t7, $t7, 0x6490
    ctx->r15 = ADD32(ctx->r15, 0X6490);
    // 0x80800DD4: b           L_808010AC
    // 0x80800DD8: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
        goto L_808010AC;
    // 0x80800DD8: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
L_80800DDC:
    // 0x80800DDC: jal         0x800D9078
    // 0x80800DE0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x80800DE0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_0:
    // 0x80800DE4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800DE8: lui         $at, 0xC4FA
    ctx->r1 = S32(0XC4FA << 16);
    // 0x80800DEC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800DF0: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800DF4: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80800DF8: lui         $a2, 0x40C0
    ctx->r6 = S32(0X40C0 << 16);
    // 0x80800DFC: jal         0x800F12D4
    // 0x80800E00: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F12D4(rdram, ctx);
        goto after_1;
    // 0x80800E00: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80800E04: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800E08: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800E0C: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800E10: lwc1        $f6, 0x1C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80800E14: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800E18: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x80800E1C: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x80800E20: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80800E24: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800E28: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80800E2C: bc1f        L_80800E50
    if (!c1cs) {
        // 0x80800E30: swc1        $f8, 0x8($s0)
        MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
            goto L_80800E50;
    }
    // 0x80800E30: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x80800E34: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1284, 0X16F0) << 16);
    // 0x80800E38: addiu       $t8, $t8, 0x16F0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1284, 0X16F0));
    // 0x80800E3C: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80800E40: jal         0x800BBCB8
    // 0x80800E44: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_800BBCB8(rdram, ctx);
        goto after_2;
    // 0x80800E44: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_2:
    // 0x80800E48: b           L_80800E78
    // 0x80800E4C: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
        goto L_80800E78;
    // 0x80800E4C: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
L_80800E50:
    // 0x80800E50: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800E54: lui         $a3, 0x437F
    ctx->r7 = S32(0X437F << 16);
    // 0x80800E58: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800E5C: jal         0x800F10B4
    // 0x80800E60: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x80800E60: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x80800E64: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800E68: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x80800E6C: nop

    // 0x80800E70: sb          $t0, 0x9B($s0)
    MEM_B(0X9B, ctx->r16) = ctx->r8;
    // 0x80800E74: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
L_80800E78:
    // 0x80800E78: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    // 0x80800E7C: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x80800E80: jal         0x800D90A4
    // 0x80800E84: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
    func_800D90A4(rdram, ctx);
        goto after_4;
    // 0x80800E84: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
    after_4:
    // 0x80800E88: beq         $v0, $zero, L_80800EB0
    if (ctx->r2 == 0) {
        // 0x80800E8C: nop
    
            goto L_80800EB0;
    }
    // 0x80800E8C: nop

    // 0x80800E90: lbu         $t4, 0x65($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X65);
    // 0x80800E94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E98: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800E9C: andi        $t5, $t4, 0xFFFE
    ctx->r13 = ctx->r12 & 0XFFFE;
    // 0x80800EA0: jal         0x80101FDC
    // 0x80800EA4: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
    func_80101FDC(rdram, ctx);
        goto after_5;
    // 0x80800EA4: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
    after_5:
    // 0x80800EA8: b           L_80801034
    // 0x80800EAC: nop

        goto L_80801034;
    // 0x80800EAC: nop

L_80800EB0:
    // 0x80800EB0: jal         0x800D90A4
    // 0x80800EB4: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    func_800D90A4(rdram, ctx);
        goto after_6;
    // 0x80800EB4: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    after_6:
    // 0x80800EB8: beq         $v0, $zero, L_80800EF4
    if (ctx->r2 == 0) {
        // 0x80800EBC: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1284, 0X146C) << 16);
            goto L_80800EF4;
    }
    // 0x80800EBC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1284, 0X146C) << 16);
    // 0x80800EC0: lwc1        $f12, 0x146C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1284, 0X146C));
    // 0x80800EC4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800EC8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800ECC: addiu       $t6, $s0, 0x4
    ctx->r14 = ADD32(ctx->r16, 0X4);
    // 0x80800ED0: jal         0x800DC178
    // 0x80800ED4: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    func_800DC178(rdram, ctx);
        goto after_7;
    // 0x80800ED4: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_7:
    // 0x80800ED8: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80800EDC: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1284, 0X1734) << 16);
    // 0x80800EE0: addiu       $a3, $a3, 0x1734
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1284, 0X1734));
    // 0x80800EE4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80800EE8: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x80800EEC: jal         0x8010D930
    // 0x80800EF0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_8010D930(rdram, ctx);
        goto after_8;
    // 0x80800EF0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_8:
L_80800EF4:
    // 0x80800EF4: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80800EF8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800EFC: lwc1        $f12, 0x20($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80800F00: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800F04: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800F08: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x80800F0C: nop

    // 0x80800F10: bc1fl       L_80800F70
    if (!c1cs) {
        // 0x80800F14: mtc1        $at, $f14
        ctx->f14.u32l = ctx->r1;
            goto L_80800F70;
    }
    goto skip_0;
    // 0x80800F14: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    skip_0:
    // 0x80800F18: jal         0x800DC0C0
    // 0x80800F1C: nop

    func_800DC0C0(rdram, ctx);
        goto after_9;
    // 0x80800F1C: nop

    after_9:
    // 0x80800F20: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800F24: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80800F28: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80800F2C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800F30: lwc1        $f12, 0x20($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80800F34: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80800F38: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800F3C: jal         0x800F10B4
    // 0x80800F40: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    func_800F10B4(rdram, ctx);
        goto after_10;
    // 0x80800F40: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_10:
    // 0x80800F44: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800F48: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800F4C: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80800F50: nop

    // 0x80800F54: bc1f        L_80800F64
    if (!c1cs) {
        // 0x80800F58: nop
    
            goto L_80800F64;
    }
    // 0x80800F58: nop

    // 0x80800F5C: b           L_80800F94
    // 0x80800F60: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
        goto L_80800F94;
    // 0x80800F60: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
L_80800F64:
    // 0x80800F64: b           L_80800F94
    // 0x80800F68: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
        goto L_80800F94;
    // 0x80800F68: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    // 0x80800F6C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
L_80800F70:
    // 0x80800F70: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800F74: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800F78: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x80800F7C: jal         0x800F10B4
    // 0x80800F80: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_11;
    // 0x80800F80: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_11:
    // 0x80800F84: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800F88: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80800F8C: nop

    // 0x80800F90: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
L_80800F94:
    // 0x80800F94: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80800F98: addiu       $t1, $s0, 0x4
    ctx->r9 = ADD32(ctx->r16, 0X4);
    // 0x80800F9C: beq         $t0, $zero, L_80801034
    if (ctx->r8 == 0) {
        // 0x80800FA0: or          $a0, $t0, $zero
        ctx->r4 = ctx->r8 | 0;
            goto L_80801034;
    }
    // 0x80800FA0: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x80800FA4: jal         0x800B53A4
    // 0x80800FA8: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    func_800B53A4(rdram, ctx);
        goto after_12;
    // 0x80800FA8: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    after_12:
    // 0x80800FAC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80800FB0: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80800FB4: jal         0x800EE7F8
    // 0x80800FB8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800EE7F8(rdram, ctx);
        goto after_13;
    // 0x80800FB8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_13:
    // 0x80800FBC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1284, 0X1470) << 16);
    // 0x80800FC0: lwc1        $f10, 0x1470($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1284, 0X1470));
    // 0x80800FC4: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80800FC8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80800FCC: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    // 0x80800FD0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80800FD4: jal         0x800BA5A8
    // 0x80800FD8: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
    func_800BA5A8(rdram, ctx);
        goto after_14;
    // 0x80800FD8: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
    after_14:
    // 0x80800FDC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80800FE0: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    // 0x80800FE4: jal         0x800BA714
    // 0x80800FE8: addiu       $a2, $zero, 0x1F4
    ctx->r6 = ADD32(0, 0X1F4);
    func_800BA714(rdram, ctx);
        goto after_15;
    // 0x80800FE8: addiu       $a2, $zero, 0x1F4
    ctx->r6 = ADD32(0, 0X1F4);
    after_15:
    // 0x80800FEC: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(1284, 0X14D8) << 16);
    // 0x80800FF0: addiu       $t2, $t2, 0x14D8
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(1284, 0X14D8));
    // 0x80800FF4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800FF8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80800FFC: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80801000: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801004: jal         0x800BABB8
    // 0x80801008: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_16;
    // 0x80801008: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_16:
    // 0x8080100C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80801010: jal         0x800BA4D0
    // 0x80801014: addiu       $a1, $zero, 0x5DC
    ctx->r5 = ADD32(0, 0X5DC);
    func_800BA4D0(rdram, ctx);
        goto after_17;
    // 0x80801014: addiu       $a1, $zero, 0x5DC
    ctx->r5 = ADD32(0, 0X5DC);
    after_17:
    // 0x80801018: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8080101C: addiu       $a1, $a1, 0x6488
    ctx->r5 = ADD32(ctx->r5, 0X6488);
    // 0x80801020: jal         0x800BA544
    // 0x80801024: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_800BA544(rdram, ctx);
        goto after_18;
    // 0x80801024: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_18:
    // 0x80801028: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8080102C: jal         0x800BA22C
    // 0x80801030: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    func_800BA22C(rdram, ctx);
        goto after_19;
    // 0x80801030: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_19:
L_80801034:
    // 0x80801034: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x80801038: addiu       $t3, $t3, 0x6490
    ctx->r11 = ADD32(ctx->r11, 0X6490);
    // 0x8080103C: b           L_808010AC
    // 0x80801040: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
        goto L_808010AC;
    // 0x80801040: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
L_80801044:
    // 0x80801044: jal         0x800BEA88
    // 0x80801048: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800BEA88(rdram, ctx);
        goto after_20;
    // 0x80801048: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_20:
    // 0x8080104C: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80801050: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80801054: addiu       $a2, $a2, 0x6490
    ctx->r6 = ADD32(ctx->r6, 0X6490);
    // 0x80801058: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x8080105C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x80801060: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801064: jal         0x80088660
    // 0x80801068: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _glid_entrypoint_0(rdram, ctx);
        goto after_21;
    // 0x80801068: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_21:
    // 0x8080106C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80801070: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80801074: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80801078: jal         0x80088660
    // 0x8080107C: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_22;
    // 0x8080107C: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    after_22:
    // 0x80801080: lbu         $v1, 0x79($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X79);
    // 0x80801084: srl         $a0, $v1, 4
    ctx->r4 = S32(U32(ctx->r3) >> 4);
    // 0x80801088: addiu       $t4, $a0, -0x1
    ctx->r12 = ADD32(ctx->r4, -0X1);
    // 0x8080108C: sll         $t6, $t4, 4
    ctx->r14 = S32(ctx->r12 << 4);
    // 0x80801090: andi        $t7, $v1, 0xFF0F
    ctx->r15 = ctx->r3 & 0XFF0F;
    // 0x80801094: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80801098: sltiu       $v0, $a0, 0x1
    ctx->r2 = ctx->r4 < 0X1 ? 1 : 0;
    // 0x8080109C: beq         $v0, $zero, L_808010AC
    if (ctx->r2 == 0) {
        // 0x808010A0: sb          $t8, 0x79($s0)
        MEM_B(0X79, ctx->r16) = ctx->r24;
            goto L_808010AC;
    }
    // 0x808010A0: sb          $t8, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r24;
    // 0x808010A4: jal         0x800FFAB0
    // 0x808010A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_23;
    // 0x808010A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
L_808010AC:
    // 0x808010AC: jal         0x800BEA88
    // 0x808010B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800BEA88(rdram, ctx);
        goto after_24;
    // 0x808010B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_24:
    // 0x808010B4: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x808010B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808010BC: jal         0x80088F10
    // 0x808010C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _idworld_entrypoint_4(rdram, ctx);
        goto after_25;
    // 0x808010C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_25:
    // 0x808010C4: beq         $v0, $zero, L_808010E8
    if (ctx->r2 == 0) {
        // 0x808010C8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808010E8;
    }
    // 0x808010C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808010CC: lwc1        $f18, 0x18($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X18);
    // 0x808010D0: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x808010D4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x808010D8: nop

    // 0x808010DC: sll         $t0, $a1, 16
    ctx->r8 = S32(ctx->r5 << 16);
    // 0x808010E0: jal         0x80088E98
    // 0x808010E4: sra         $a1, $t0, 16
    ctx->r5 = S32(SIGNED(ctx->r8) >> 16);
    _idwibble_entrypoint_5(rdram, ctx);
        goto after_26;
    // 0x808010E4: sra         $a1, $t0, 16
    ctx->r5 = S32(SIGNED(ctx->r8) >> 16);
    after_26:
L_808010E8:
    // 0x808010E8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808010EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808010F0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x808010F4: jal         0x80088660
    // 0x808010F8: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_27;
    // 0x808010F8: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    after_27:
    // 0x808010FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801100: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801104: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80801108: jr          $ra
    // 0x8080110C: nop

    return;
    // 0x8080110C: nop

;}
RECOMP_FUNC void _chbadjinjo_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086968: syscall     401
    recomp_syscall_handler(rdram, ctx, 0x80086968);
    return;
    // 0x8008696C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
