#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_808026F0_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808026F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808026F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808026F8: jal         0x80100094
    // 0x808026FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808026FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802700: lbu         $t6, 0x59($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X59);
    // 0x80802704: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80802708: beql        $t6, $zero, L_80802724
    if (ctx->r14 == 0) {
        // 0x8080270C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80802724;
    }
    goto skip_0;
    // 0x8080270C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80802710: jal         0x800856B8
    // 0x80802714: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    _capod_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80802714: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80802718: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8080271C: sb          $zero, 0x59($v1)
    MEM_B(0X59, ctx->r3) = 0;
    // 0x80802720: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802724:
    // 0x80802724: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802728: jr          $ra
    // 0x8080272C: nop

    return;
    // 0x8080272C: nop

;}
RECOMP_FUNC void basub_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800544: lw          $v0, 0x130($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X130);
    // 0x80800548: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8080054C: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80800550: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x80800554: nop

    // 0x80800558: bc1fl       L_8080056C
    if (!c1cs) {
        // 0x8080055C: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_8080056C;
    }
    goto skip_0;
    // 0x8080055C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_0:
    // 0x80800560: jr          $ra
    // 0x80800564: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    return;
    // 0x80800564: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80800568: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8080056C:
    // 0x8080056C: jr          $ra
    // 0x80800570: nop

    return;
    // 0x80800570: nop

;}
RECOMP_FUNC void _bainvisible_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800854D8: syscall     164
    recomp_syscall_handler(rdram, ctx, 0x800854D8);
    return;
    // 0x800854DC: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_80800060_chlightdemon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800060: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800064: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800068: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080006C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800070: bne         $a1, $at, L_808000C4
    if (ctx->r5 != ctx->r1) {
        // 0x80800074: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_808000C4;
    }
    // 0x80800074: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800078: jal         0x800C8A98
    // 0x8080007C: nop

    func_800C8A98(rdram, ctx);
        goto after_0;
    // 0x8080007C: nop

    after_0:
    // 0x80800080: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800084: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(920, 0X194) << 16);
    // 0x80800088: addiu       $a1, $a1, 0x194
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(920, 0X194));
    // 0x8080008C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800090: jal         0x800C8D4C
    // 0x80800094: sw          $v0, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->r2;
    func_800C8D4C(rdram, ctx);
        goto after_1;
    // 0x80800094: sw          $v0, 0x28($t6)
    MEM_W(0X28, ctx->r14) = ctx->r2;
    after_1:
    // 0x80800098: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8080009C: lw          $a0, 0x28($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X28);
    // 0x808000A0: jal         0x800C8CB8
    // 0x808000A4: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    func_800C8CB8(rdram, ctx);
        goto after_2;
    // 0x808000A4: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    after_2:
    // 0x808000A8: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x808000AC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(920, 0X188) << 16);
    // 0x808000B0: addiu       $a1, $a1, 0x188
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(920, 0X188));
    // 0x808000B4: jal         0x800C8E84
    // 0x808000B8: lw          $a0, 0x28($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X28);
    func_800C8E84(rdram, ctx);
        goto after_3;
    // 0x808000B8: lw          $a0, 0x28($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X28);
    after_3:
    // 0x808000BC: b           L_808000C8
    // 0x808000C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808000C8;
    // 0x808000C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000C4:
    // 0x808000C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000C8:
    // 0x808000C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000D0: jr          $ra
    // 0x808000D4: nop

    return;
    // 0x808000D4: nop

;}
RECOMP_FUNC void func_8080000C_chweather(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800018: jal         0x8010D254
    // 0x8080001C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_8010D254(rdram, ctx);
        goto after_0;
    // 0x8080001C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80800020: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(732, 0X400) << 16);
    // 0x80800024: lwc1        $f6, 0x400($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(732, 0X400));
    // 0x80800028: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8080002C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800034: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800038: nop

    // 0x8080003C: bc1f        L_80800048
    if (!c1cs) {
        // 0x80800040: nop
    
            goto L_80800048;
    }
    // 0x80800040: nop

    // 0x80800044: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800048:
    // 0x80800048: jr          $ra
    // 0x8080004C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8080004C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80801640_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801640: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801644: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801648: jal         0x800A4C68
    // 0x8080164C: nop

    func_800A4C68(rdram, ctx);
        goto after_0;
    // 0x8080164C: nop

    after_0:
    // 0x80801650: jal         0x800C517C
    // 0x80801654: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800C517C(rdram, ctx);
        goto after_1;
    // 0x80801654: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80801658: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080165C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801660: jr          $ra
    // 0x80801664: nop

    return;
    // 0x80801664: nop

;}
RECOMP_FUNC void func_80800058_chpoolkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800058: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080005C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800060: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800064: jal         0x80104248
    // 0x80800068: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80104248(rdram, ctx);
        goto after_0;
    // 0x80800068: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080006C: beql        $v0, $zero, L_80800140
    if (ctx->r2 == 0) {
        // 0x80800070: lui         $at, 0x4270
        ctx->r1 = S32(0X4270 << 16);
            goto L_80800140;
    }
    goto skip_0;
    // 0x80800070: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    skip_0:
    // 0x80800074: jal         0x801022E4
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801022E4(rdram, ctx);
        goto after_1;
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080007C: addiu       $at, $zero, 0x2B9
    ctx->r1 = ADD32(0, 0X2B9);
    // 0x80800080: bnel        $v0, $at, L_80800128
    if (ctx->r2 != ctx->r1) {
        // 0x80800084: lbu         $t2, 0x77($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0X77);
            goto L_80800128;
    }
    goto skip_1;
    // 0x80800084: lbu         $t2, 0x77($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X77);
    skip_1:
    // 0x80800088: jal         0x80101F24
    // 0x8080008C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_2;
    // 0x8080008C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800090: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80800094: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800098: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8080009C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808000A0: lui         $a2, 0x3F7D
    ctx->r6 = S32(0X3F7D << 16);
    // 0x808000A4: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x808000A8: ori         $a2, $a2, 0x70A4
    ctx->r6 = ctx->r6 | 0X70A4;
    // 0x808000AC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808000B0: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x808000B4: jal         0x800F10B4
    // 0x808000B8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x808000B8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x808000BC: jal         0x80013970
    // 0x808000C0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80013970(rdram, ctx);
        goto after_4;
    // 0x808000C0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_4:
    // 0x808000C4: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808000C8: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x808000CC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1092, 0X1260) << 16);
    // 0x808000D0: lwc1        $f6, 0x1260($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1092, 0X1260));
    // 0x808000D4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1092, 0X1264) << 16);
    // 0x808000D8: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x808000DC: nop

    // 0x808000E0: bc1fl       L_80800114
    if (!c1cs) {
        // 0x808000E4: lbu         $t9, 0x77($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X77);
            goto L_80800114;
    }
    goto skip_2;
    // 0x808000E4: lbu         $t9, 0x77($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X77);
    skip_2:
    // 0x808000E8: lwc1        $f8, 0x1264($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1092, 0X1264));
    // 0x808000EC: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x808000F0: nop

    // 0x808000F4: bc1fl       L_80800114
    if (!c1cs) {
        // 0x808000F8: lbu         $t9, 0x77($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X77);
            goto L_80800114;
    }
    goto skip_3;
    // 0x808000F8: lbu         $t9, 0x77($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X77);
    skip_3:
    // 0x808000FC: lbu         $t6, 0x77($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X77);
    // 0x80800100: andi        $t7, $t6, 0xFFF0
    ctx->r15 = ctx->r14 & 0XFFF0;
    // 0x80800104: ori         $t8, $t7, 0x2
    ctx->r24 = ctx->r15 | 0X2;
    // 0x80800108: b           L_8080013C
    // 0x8080010C: sb          $t8, 0x77($s0)
    MEM_B(0X77, ctx->r16) = ctx->r24;
        goto L_8080013C;
    // 0x8080010C: sb          $t8, 0x77($s0)
    MEM_B(0X77, ctx->r16) = ctx->r24;
    // 0x80800110: lbu         $t9, 0x77($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X77);
L_80800114:
    // 0x80800114: andi        $t0, $t9, 0xFFF0
    ctx->r8 = ctx->r25 & 0XFFF0;
    // 0x80800118: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x8080011C: b           L_8080013C
    // 0x80800120: sb          $t1, 0x77($s0)
    MEM_B(0X77, ctx->r16) = ctx->r9;
        goto L_8080013C;
    // 0x80800120: sb          $t1, 0x77($s0)
    MEM_B(0X77, ctx->r16) = ctx->r9;
    // 0x80800124: lbu         $t2, 0x77($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X77);
L_80800128:
    // 0x80800128: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8080012C: andi        $t3, $t2, 0xFFF0
    ctx->r11 = ctx->r10 & 0XFFF0;
    // 0x80800130: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x80800134: sb          $t4, 0x77($s0)
    MEM_B(0X77, ctx->r16) = ctx->r12;
    // 0x80800138: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
L_8080013C:
    // 0x8080013C: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
L_80800140:
    // 0x80800140: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800144: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800148: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8080014C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800150: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800154: jal         0x8008FB58
    // 0x80800158: nop

    func_8008FB58(rdram, ctx);
        goto after_5;
    // 0x80800158: nop

    after_5:
    // 0x8080015C: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x80800160: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800164: srl         $t5, $v1, 10
    ctx->r13 = S32(U32(ctx->r3) >> 10);
    // 0x80800168: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8080016C: sltiu       $at, $t6, 0x6
    ctx->r1 = ctx->r14 < 0X6 ? 1 : 0;
    // 0x80800170: beq         $at, $zero, L_8080027C
    if (ctx->r1 == 0) {
        // 0x80800174: or          $v1, $t5, $zero
        ctx->r3 = ctx->r13 | 0;
            goto L_8080027C;
    }
    // 0x80800174: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x80800178: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8080017C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1092, 0X1268) << 16);
    // 0x80800180: addu        $at, $at, $t6
    gpr jr_addend_80800188 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800184: lw          $t6, 0x1268($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1092, 0X1268));
    // 0x80800188: jr          $t6
    // 0x8080018C: nop

    switch (jr_addend_80800188 >> 2) {
        case 0: goto L_80800190; break;
        case 1: goto L_808001C4; break;
        case 2: goto L_808001D4; break;
        case 3: goto L_808001FC; break;
        case 4: goto L_80800230; break;
        case 5: goto L_80800264; break;
        default: switch_error(__func__, 0x80800188, 0x80801268);
    }
    // 0x8080018C: nop

L_80800190:
    // 0x80800190: sw          $v1, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r3;
    // 0x80800194: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1092, 0X14C8) << 16);
    // 0x80800198: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1092, 0X12B0) << 16);
    // 0x8080019C: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x808001A0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808001A4: addiu       $a3, $a3, 0x12B0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1092, 0X12B0));
    // 0x808001A8: addiu       $a2, $a2, 0x14C8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1092, 0X14C8));
    // 0x808001AC: jal         0x8008A1F0
    // 0x808001B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x808001B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808001B4: jal         0x80800AA0
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800AA0_chpoolkids(rdram, ctx);
        goto after_7;
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808001BC: b           L_80800280
    // 0x808001C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800280;
    // 0x808001C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001C4:
    // 0x808001C4: jal         0x80800AA0
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800AA0_chpoolkids(rdram, ctx);
        goto after_8;
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808001CC: b           L_80800280
    // 0x808001D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800280;
    // 0x808001D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001D4:
    // 0x808001D4: jal         0x80800AA0
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800AA0_chpoolkids(rdram, ctx);
        goto after_9;
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808001DC: jal         0x800D9078
    // 0x808001E0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_10;
    // 0x808001E0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_10:
    // 0x808001E4: beql        $v0, $zero, L_80800280
    if (ctx->r2 == 0) {
        // 0x808001E8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800280;
    }
    goto skip_4;
    // 0x808001E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x808001EC: jal         0x80088830
    // 0x808001F0: nop

    _glcutDll_entrypoint_17(rdram, ctx);
        goto after_11;
    // 0x808001F0: nop

    after_11:
    // 0x808001F4: b           L_80800280
    // 0x808001F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800280;
    // 0x808001F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001FC:
    // 0x808001FC: sw          $v1, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r3;
    // 0x80800200: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1092, 0X14C8) << 16);
    // 0x80800204: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1092, 0X12D8) << 16);
    // 0x80800208: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8080020C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800210: addiu       $a3, $a3, 0x12D8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1092, 0X12D8));
    // 0x80800214: addiu       $a2, $a2, 0x14C8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1092, 0X14C8));
    // 0x80800218: jal         0x8008A1F0
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_12;
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800220: jal         0x80800AA0
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800AA0_chpoolkids(rdram, ctx);
        goto after_13;
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800228: b           L_80800280
    // 0x8080022C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800280;
    // 0x8080022C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800230:
    // 0x80800230: sw          $v1, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r3;
    // 0x80800234: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1092, 0X14C8) << 16);
    // 0x80800238: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1092, 0X12F8) << 16);
    // 0x8080023C: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80800240: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800244: addiu       $a3, $a3, 0x12F8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1092, 0X12F8));
    // 0x80800248: addiu       $a2, $a2, 0x14C8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1092, 0X14C8));
    // 0x8080024C: jal         0x8008A1F0
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_14;
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800254: jal         0x80800AA0
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800AA0_chpoolkids(rdram, ctx);
        goto after_15;
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x8080025C: b           L_80800280
    // 0x80800260: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800280;
    // 0x80800260: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800264:
    // 0x80800264: jal         0x808008DC
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008DC_chpoolkids(rdram, ctx);
        goto after_16;
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x8080026C: lui         $a1, 0x3F0C
    ctx->r5 = S32(0X3F0C << 16);
    // 0x80800270: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800274: jal         0x80800944
    // 0x80800278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800944_chpoolkids(rdram, ctx);
        goto after_17;
    // 0x80800278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
L_8080027C:
    // 0x8080027C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800280:
    // 0x80800280: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800284: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800288: jr          $ra
    // 0x8080028C: nop

    return;
    // 0x8080028C: nop

;}
RECOMP_FUNC void func_800996E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800996E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800996E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800996E8: jal         0x800A1718
    // 0x800996EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800A1718(rdram, ctx);
        goto after_0;
    // 0x800996EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800996F0: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800996F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800996F8: beq         $at, $zero, L_80099710
    if (ctx->r1 == 0) {
        // 0x800996FC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80099710;
    }
    // 0x800996FC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80099700: jal         0x800A17A8
    // 0x80099704: negu        $a1, $v0
    ctx->r5 = SUB32(0, ctx->r2);
    func_800A17A8(rdram, ctx);
        goto after_1;
    // 0x80099704: negu        $a1, $v0
    ctx->r5 = SUB32(0, ctx->r2);
    after_1:
    // 0x80099708: b           L_80099720
    // 0x8009970C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80099720;
    // 0x8009970C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80099710:
    // 0x80099710: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80099714: jal         0x800A17A8
    // 0x80099718: subu        $a1, $t6, $v1
    ctx->r5 = SUB32(ctx->r14, ctx->r3);
    func_800A17A8(rdram, ctx);
        goto after_2;
    // 0x80099718: subu        $a1, $t6, $v1
    ctx->r5 = SUB32(ctx->r14, ctx->r3);
    after_2:
    // 0x8009971C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80099720:
    // 0x80099720: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80099724: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80099728: jr          $ra
    // 0x8009972C: nop

    return;
    // 0x8009972C: nop

;}
RECOMP_FUNC void baflag_isTrue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095738: lw          $t6, 0x80($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X80);
    // 0x8009573C: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x80095740: jr          $ra
    // 0x80095744: lbu         $v0, 0x0($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X0);
    return;
    // 0x80095744: lbu         $v0, 0x0($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X0);
;}
RECOMP_FUNC void _suflamefx_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089930: syscall     798
    recomp_syscall_handler(rdram, ctx, 0x80089930);
    return;
    // 0x80089934: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _bavan_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800853A0: syscall     159
    recomp_syscall_handler(rdram, ctx, 0x800853A0);
    return;
    // 0x800853A4: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void gcgoto_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800198: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080019C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808001A4: jal         0x8080011C
    // 0x808001A8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8080011C_gcgoto(rdram, ctx);
        goto after_0;
    // 0x808001A8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x808001AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001B4: jr          $ra
    // 0x808001B8: nop

    return;
    // 0x808001B8: nop

;}
RECOMP_FUNC void glidmake_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002B4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x808002B8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x808002BC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x808002C0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808002C4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x808002C8: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x808002CC: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x808002D0: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x808002D4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x808002D8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x808002DC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x808002E0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808002E4: jal         0x800D674C
    // 0x808002E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_800D674C(rdram, ctx);
        goto after_0;
    // 0x808002E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x808002EC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808002F0: jal         0x800B274C
    // 0x808002F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B274C(rdram, ctx);
        goto after_1;
    // 0x808002F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808002F8: bne         $v0, $zero, L_80800308
    if (ctx->r2 != 0) {
        // 0x808002FC: sw          $v0, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r2;
            goto L_80800308;
    }
    // 0x808002FC: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x80800300: b           L_808004FC
    // 0x80800304: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808004FC;
    // 0x80800304: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800308:
    // 0x80800308: jal         0x800B2840
    // 0x8080030C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800B2840(rdram, ctx);
        goto after_2;
    // 0x8080030C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800310: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
    // 0x80800314: jal         0x800879C8
    // 0x80800318: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    _dbid_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80800318: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    after_3:
    // 0x8080031C: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x80800320: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x80800324: lh          $v1, 0x0($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X0);
    // 0x80800328: addiu       $s1, $a2, 0x2
    ctx->r17 = ADD32(ctx->r6, 0X2);
    // 0x8080032C: or          $s6, $s1, $zero
    ctx->r22 = ctx->r17 | 0;
    // 0x80800330: sll         $t7, $v1, 3
    ctx->r15 = S32(ctx->r3 << 3);
    // 0x80800334: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x80800338: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x8080033C: blez        $v1, L_8080038C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80800340: sw          $zero, 0x40($sp)
        MEM_W(0X40, ctx->r29) = 0;
            goto L_8080038C;
    }
    // 0x80800340: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_80800344:
    // 0x80800344: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80800348: jal         0x800879C0
    // 0x8080034C: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
    _dbid_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x8080034C: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
    after_4:
    // 0x80800350: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x80800354: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80800358: lh          $t9, 0x2($s6)
    ctx->r25 = MEM_H(ctx->r22, 0X2);
    // 0x8080035C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800360: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x80800364: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x80800368: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8080036C: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80800370: addu        $s6, $s6, $t0
    ctx->r22 = ADD32(ctx->r22, ctx->r8);
    // 0x80800374: slt         $at, $v1, $t2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80800378: addu        $s0, $s0, $t8
    ctx->r16 = ADD32(ctx->r16, ctx->r24);
    // 0x8080037C: bne         $at, $zero, L_80800344
    if (ctx->r1 != 0) {
        // 0x80800380: addiu       $s6, $s6, 0x4
        ctx->r22 = ADD32(ctx->r22, 0X4);
            goto L_80800344;
    }
    // 0x80800380: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x80800384: or          $s6, $s1, $zero
    ctx->r22 = ctx->r17 | 0;
    // 0x80800388: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_8080038C:
    // 0x8080038C: jal         0x8001ACCC
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    heap_alloc(rdram, ctx);
        goto after_5;
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800394: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x80800398: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x8080039C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808003A0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x808003A4: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x808003A8: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x808003AC: beq         $s3, $zero, L_808003C8
    if (ctx->r19 == 0) {
        // 0x808003B0: sw          $t4, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r12;
            goto L_808003C8;
    }
    // 0x808003B0: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x808003B4: addiu       $a0, $v0, 0x8
    ctx->r4 = ADD32(ctx->r2, 0X8);
    // 0x808003B8: jal         0x800EE7F8
    // 0x808003BC: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x808003BC: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    after_6:
    // 0x808003C0: b           L_808003D4
    // 0x808003C4: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
        goto L_808003D4;
    // 0x808003C4: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
L_808003C8:
    // 0x808003C8: jal         0x800EFD24
    // 0x808003CC: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    func_800EFD24(rdram, ctx);
        goto after_7;
    // 0x808003CC: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    after_7:
    // 0x808003D0: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
L_808003D4:
    // 0x808003D4: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x808003D8: sw          $fp, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r30;
    // 0x808003DC: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
    // 0x808003E0: lh          $t5, 0x0($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X0);
    // 0x808003E4: addiu       $s7, $v1, 0x1C
    ctx->r23 = ADD32(ctx->r3, 0X1C);
    // 0x808003E8: blezl       $t5, L_808004FC
    if (SIGNED(ctx->r13) <= 0) {
        // 0x808003EC: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_808004FC;
    }
    goto skip_0;
    // 0x808003EC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_0:
L_808003F0:
    // 0x808003F0: lh          $t6, 0x0($s6)
    ctx->r14 = MEM_H(ctx->r22, 0X0);
    // 0x808003F4: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x808003F8: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x808003FC: sh          $t6, 0x0($s7)
    MEM_H(0X0, ctx->r23) = ctx->r14;
    // 0x80800400: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
    // 0x80800404: jal         0x800879C0
    // 0x80800408: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    _dbid_entrypoint_0(rdram, ctx);
        goto after_8;
    // 0x80800408: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    after_8:
    // 0x8080040C: sh          $v0, 0x2($s7)
    MEM_H(0X2, ctx->r23) = ctx->r2;
    // 0x80800410: lh          $t7, 0x2($s7)
    ctx->r15 = MEM_H(ctx->r23, 0X2);
    // 0x80800414: lh          $s5, 0x4($s6)
    ctx->r21 = MEM_H(ctx->r22, 0X4);
    // 0x80800418: addiu       $s1, $s7, 0x8
    ctx->r17 = ADD32(ctx->r23, 0X8);
    // 0x8080041C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80800420: addu        $s2, $t8, $s7
    ctx->r18 = ADD32(ctx->r24, ctx->r23);
    // 0x80800424: sll         $t9, $s5, 4
    ctx->r25 = S32(ctx->r21 << 4);
    // 0x80800428: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x8080042C: addu        $a1, $t9, $fp
    ctx->r5 = ADD32(ctx->r25, ctx->r30);
    // 0x80800430: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    // 0x80800434: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800438: jal         0x8001BBC8
    // 0x8080043C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    aligned4_memcpy(rdram, ctx);
        goto after_9;
    // 0x8080043C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_9:
    // 0x80800440: lh          $t0, 0x2($s6)
    ctx->r8 = MEM_H(ctx->r22, 0X2);
    // 0x80800444: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x80800448: addiu       $s0, $s6, 0x2
    ctx->r16 = ADD32(ctx->r22, 0X2);
    // 0x8080044C: slti        $at, $t0, 0x2
    ctx->r1 = SIGNED(ctx->r8) < 0X2 ? 1 : 0;
    // 0x80800450: bnel        $at, $zero, L_808004B8
    if (ctx->r1 != 0) {
        // 0x80800454: lw          $v0, 0x40($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X40);
            goto L_808004B8;
    }
    goto skip_1;
    // 0x80800454: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    skip_1:
L_80800458:
    // 0x80800458: lh          $t2, 0x2($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X2);
    // 0x8080045C: lh          $v0, 0x4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4);
    // 0x80800460: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800464: addiu       $t1, $t2, 0x1
    ctx->r9 = ADD32(ctx->r10, 0X1);
    // 0x80800468: beq         $v0, $t1, L_80800488
    if (ctx->r2 == ctx->r9) {
        // 0x8080046C: addiu       $a2, $zero, 0x10
        ctx->r6 = ADD32(0, 0X10);
            goto L_80800488;
    }
    // 0x8080046C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80800470: sh          $s5, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r21;
    // 0x80800474: sh          $s3, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r19;
    // 0x80800478: lh          $v0, 0x4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4);
    // 0x8080047C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80800480: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80800484: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
L_80800488:
    // 0x80800488: sll         $t3, $v0, 4
    ctx->r11 = S32(ctx->r2 << 4);
    // 0x8080048C: addu        $a1, $t3, $fp
    ctx->r5 = ADD32(ctx->r11, ctx->r30);
    // 0x80800490: jal         0x8001BBC8
    // 0x80800494: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    aligned4_memcpy(rdram, ctx);
        goto after_10;
    // 0x80800494: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    after_10:
    // 0x80800498: lh          $t4, 0x2($s6)
    ctx->r12 = MEM_H(ctx->r22, 0X2);
    // 0x8080049C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x808004A0: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x808004A4: slt         $at, $s4, $t4
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x808004A8: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x808004AC: bne         $at, $zero, L_80800458
    if (ctx->r1 != 0) {
        // 0x808004B0: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_80800458;
    }
    // 0x808004B0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x808004B4: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
L_808004B8:
    // 0x808004B8: sh          $s5, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r21;
    // 0x808004BC: sh          $s3, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r19;
    // 0x808004C0: subu        $t5, $s2, $s7
    ctx->r13 = SUB32(ctx->r18, ctx->r23);
    // 0x808004C4: sw          $t5, 0x4($s7)
    MEM_W(0X4, ctx->r23) = ctx->r13;
    // 0x808004C8: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x808004CC: lh          $t6, 0x2($s6)
    ctx->r14 = MEM_H(ctx->r22, 0X2);
    // 0x808004D0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x808004D4: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x808004D8: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x808004DC: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x808004E0: addu        $s6, $s6, $t7
    ctx->r22 = ADD32(ctx->r22, ctx->r15);
    // 0x808004E4: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x808004E8: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x808004EC: bne         $at, $zero, L_808003F0
    if (ctx->r1 != 0) {
        // 0x808004F0: or          $s7, $s2, $zero
        ctx->r23 = ctx->r18 | 0;
            goto L_808003F0;
    }
    // 0x808004F0: or          $s7, $s2, $zero
    ctx->r23 = ctx->r18 | 0;
    // 0x808004F4: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x808004F8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_808004FC:
    // 0x808004FC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80800500: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800504: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800508: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8080050C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80800510: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800514: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80800518: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8080051C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80800520: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80800524: jr          $ra
    // 0x80800528: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80800528: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8080052C: nop

;}
RECOMP_FUNC void _ncbafly_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800892E0: syscall     771
    recomp_syscall_handler(rdram, ctx, 0x800892E0);
    return;
    // 0x800892E4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_808003B4_fxstep(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808003B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003BC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808003C0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808003C4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x808003C8: jal         0x80800000
    // 0x808003CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80800000_fxstep(rdram, ctx);
        goto after_0;
    // 0x808003CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808003D0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x808003D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808003D8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x808003DC: beq         $t6, $zero, L_808003FC
    if (ctx->r14 == 0) {
        // 0x808003E0: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_808003FC;
    }
    // 0x808003E0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808003E4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x808003E8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808003EC: jal         0x808002B4
    // 0x808003F0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_808002B4_fxstep(rdram, ctx);
        goto after_1;
    // 0x808003F0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808003F4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808003F8: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_808003FC:
    // 0x808003FC: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x80800400: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80800404: beql        $v0, $zero, L_80800418
    if (ctx->r2 == 0) {
        // 0x80800408: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800418;
    }
    goto skip_0;
    // 0x80800408: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080040C: jalr        $v0
    // 0x80800410: lw          $a2, 0x20($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X20);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_2;
    // 0x80800410: lw          $a2, 0x20($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X20);
    after_2:
    // 0x80800414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800418:
    // 0x80800418: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080041C: jr          $ra
    // 0x80800420: nop

    return;
    // 0x80800420: nop

;}
RECOMP_FUNC void bskazjump_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A78: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800A7C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800A80: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800A84: jal         0x800832E0
    // 0x80800A88: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _bskaz_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800A88: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800A8C: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x80800A90: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800A94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A98: jal         0x8008CBB0
    // 0x80800A9C: addiu       $a1, $zero, 0x13C
    ctx->r5 = ADD32(0, 0X13C);
    baanim_playForDuration_loop(rdram, ctx);
        goto after_1;
    // 0x80800A9C: addiu       $a1, $zero, 0x13C
    ctx->r5 = ADD32(0, 0X13C);
    after_1:
    // 0x80800AA0: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80800AA4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800AA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800AB0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800AB4: jal         0x8009FFD8
    // 0x80800AB8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80800AB8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x80800ABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AC0: jal         0x80093360
    // 0x80800AC4: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    func_80093360(rdram, ctx);
        goto after_3;
    // 0x80800AC4: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    after_3:
    // 0x80800AC8: jal         0x8009557C
    // 0x80800ACC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009557C(rdram, ctx);
        goto after_4;
    // 0x80800ACC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800AD0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800AD4: bne         $v0, $at, L_80800B1C
    if (ctx->r2 != ctx->r1) {
        // 0x80800AD8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B1C;
    }
    // 0x80800AD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800ADC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800AE4: jal         0x80085338
    // 0x80800AE8: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    _batimer_set(rdram, ctx);
        goto after_5;
    // 0x80800AE8: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_5:
    // 0x80800AEC: lui         $a2, 0x3ED1
    ctx->r6 = S32(0X3ED1 << 16);
    // 0x80800AF0: ori         $a2, $a2, 0xEB85
    ctx->r6 = ctx->r6 | 0XEB85;
    // 0x80800AF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AF8: jal         0x80085338
    // 0x80800AFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _batimer_set(rdram, ctx);
        goto after_6;
    // 0x80800AFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80800B00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B04: addiu       $a1, $zero, 0x4668
    ctx->r5 = ADD32(0, 0X4668);
    // 0x80800B08: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800B0C: jal         0x8009DF18
    // 0x80800B10: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    func_8009DF18(rdram, ctx);
        goto after_7;
    // 0x80800B10: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    after_7:
    // 0x80800B14: b           L_80800B40
    // 0x80800B18: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
        goto L_80800B40;
    // 0x80800B18: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_80800B1C:
    // 0x80800B1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800B20: jal         0x80085338
    // 0x80800B24: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    _batimer_set(rdram, ctx);
        goto after_8;
    // 0x80800B24: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_8:
    // 0x80800B28: lui         $a2, 0x3C23
    ctx->r6 = S32(0X3C23 << 16);
    // 0x80800B2C: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x80800B30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B34: jal         0x80085338
    // 0x80800B38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _batimer_set(rdram, ctx);
        goto after_9;
    // 0x80800B38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80800B3C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_80800B40:
    // 0x80800B40: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
    // 0x80800B44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800B48: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800B4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800B50: jr          $ra
    // 0x80800B54: nop

    return;
    // 0x80800B54: nop

;}
RECOMP_FUNC void func_80024C9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024C9C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80024CA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80024CA4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80024CA8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80024CAC: jal         0x8002FEC0
    // 0x80024CB0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80024CB0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80024CB4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80024CB8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80024CBC: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80024CC0: beq         $t7, $zero, L_80024D70
    if (ctx->r15 == 0) {
        // 0x80024CC4: sw          $t7, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r15;
            goto L_80024D70;
    }
    // 0x80024CC4: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
L_80024CC8:
    // 0x80024CC8: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80024CCC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80024CD0: bne         $t9, $zero, L_80024CF4
    if (ctx->r25 != 0) {
        // 0x80024CD4: nop
    
            goto L_80024CF4;
    }
    // 0x80024CD4: nop

    // 0x80024CD8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80024CDC: jal         0x80020E40
    // 0x80024CE0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_80020E40(rdram, ctx);
        goto after_1;
    // 0x80024CE0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80024CE4: b           L_80024D70
    // 0x80024CE8: nop

        goto L_80024D70;
    // 0x80024CE8: nop

    // 0x80024CEC: b           L_80024D60
    // 0x80024CF0: nop

        goto L_80024D60;
    // 0x80024CF0: nop

L_80024CF4:
    // 0x80024CF4: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80024CF8: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80024CFC: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80024D00: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80024D04: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80024D08: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x80024D0C: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x80024D10: slt         $at, $t3, $t5
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80024D14: beq         $at, $zero, L_80024D48
    if (ctx->r1 == 0) {
        // 0x80024D18: nop
    
            goto L_80024D48;
    }
    // 0x80024D18: nop

    // 0x80024D1C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80024D20: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80024D24: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x80024D28: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x80024D2C: subu        $t0, $t7, $t9
    ctx->r8 = SUB32(ctx->r15, ctx->r25);
    // 0x80024D30: sw          $t0, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r8;
    // 0x80024D34: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80024D38: jal         0x80020E40
    // 0x80024D3C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_80020E40(rdram, ctx);
        goto after_2;
    // 0x80024D3C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80024D40: b           L_80024D70
    // 0x80024D44: nop

        goto L_80024D70;
    // 0x80024D44: nop

L_80024D48:
    // 0x80024D48: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80024D4C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80024D50: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x80024D54: lw          $t3, 0x8($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X8);
    // 0x80024D58: subu        $t5, $t2, $t3
    ctx->r13 = SUB32(ctx->r10, ctx->r11);
    // 0x80024D5C: sw          $t5, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r13;
L_80024D60:
    // 0x80024D60: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80024D64: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x80024D68: bne         $t7, $zero, L_80024CC8
    if (ctx->r15 != 0) {
        // 0x80024D6C: sw          $t7, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r15;
            goto L_80024CC8;
    }
    // 0x80024D6C: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
L_80024D70:
    // 0x80024D70: jal         0x8002FEC0
    // 0x80024D74: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    osSetIntMask_recomp(rdram, ctx);
        goto after_3;
    // 0x80024D74: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80024D78: b           L_80024D80
    // 0x80024D7C: nop

        goto L_80024D80;
    // 0x80024D7C: nop

L_80024D80:
    // 0x80024D80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80024D84: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80024D88: jr          $ra
    // 0x80024D8C: nop

    return;
    // 0x80024D8C: nop

;}
RECOMP_FUNC void _chdrawbridgeswitches_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087150: syscall     523
    recomp_syscall_handler(rdram, ctx, 0x80087150);
    return;
    // 0x80087154: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800E36D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E36D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E36D4: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x800E36D8: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x800E36DC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800E36E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800E36E4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800E36E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800E36EC: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800E36F0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800E36F4:
    // 0x800E36F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800E36F8:
    // 0x800E36F8: beql        $v0, $zero, L_800E370C
    if (ctx->r2 == 0) {
        // 0x800E36FC: lw          $a1, 0x0($s1)
        ctx->r5 = MEM_W(ctx->r17, 0X0);
            goto L_800E370C;
    }
    goto skip_0;
    // 0x800E36FC: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    skip_0:
    // 0x800E3700: b           L_800E370C
    // 0x800E3704: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
        goto L_800E370C;
    // 0x800E3704: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800E3708: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
L_800E370C:
    // 0x800E370C: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x800E3710: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800E3714: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800E3718: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800E371C: beq         $v1, $zero, L_800E372C
    if (ctx->r3 == 0) {
        // 0x800E3720: swc1        $f10, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
            goto L_800E372C;
    }
    // 0x800E3720: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x800E3724: b           L_800E3730
    // 0x800E3728: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
        goto L_800E3730;
    // 0x800E3728: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
L_800E372C:
    // 0x800E372C: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
L_800E3730:
    // 0x800E3730: mtc1        $a1, $f16
    ctx->f16.u32l = ctx->r5;
    // 0x800E3734: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800E3738: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800E373C: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800E3740: beq         $a0, $zero, L_800E3750
    if (ctx->r4 == 0) {
        // 0x800E3744: swc1        $f6, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
            goto L_800E3750;
    }
    // 0x800E3744: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x800E3748: b           L_800E3754
    // 0x800E374C: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
        goto L_800E3754;
    // 0x800E374C: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
L_800E3750:
    // 0x800E3750: lw          $a1, 0x8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8);
L_800E3754:
    // 0x800E3754: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x800E3758: lwc1        $f16, 0x8($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800E375C: lwc1        $f6, 0x14($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800E3760: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800E3764: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800E3768: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800E376C: lwc1        $f16, 0x18($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800E3770: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x800E3774: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800E3778: lwc1        $f10, 0x4($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X4);
    // 0x800E377C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800E3780: nop

    // 0x800E3784: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800E3788: lwc1        $f10, 0x8($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X8);
    // 0x800E378C: mul.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800E3790: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800E3794: add.s       $f2, $f16, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x800E3798: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800E379C: nop

    // 0x800E37A0: bc1f        L_800E37AC
    if (!c1cs) {
        // 0x800E37A4: nop
    
            goto L_800E37AC;
    }
    // 0x800E37A4: nop

    // 0x800E37A8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800E37AC:
    // 0x800E37AC: bne         $a0, $t0, L_800E36F8
    if (ctx->r4 != ctx->r8) {
        // 0x800E37B0: nop
    
            goto L_800E36F8;
    }
    // 0x800E37B0: nop

    // 0x800E37B4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800E37B8: bnel        $v1, $t0, L_800E36F8
    if (ctx->r3 != ctx->r8) {
        // 0x800E37BC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800E36F8;
    }
    goto skip_1;
    // 0x800E37BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_1:
    // 0x800E37C0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800E37C4: bnel        $v0, $t0, L_800E36F4
    if (ctx->r2 != ctx->r8) {
        // 0x800E37C8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800E36F4;
    }
    goto skip_2;
    // 0x800E37C8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    skip_2:
    // 0x800E37CC: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800E37D0: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x800E37D4: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x800E37D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800E37DC: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x800E37E0: jr          $ra
    // 0x800E37E4: nop

    return;
    // 0x800E37E4: nop

;}
RECOMP_FUNC void func_80800A90_chfishshootgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800A94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A98: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800A9C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800AA0: jal         0x80100094
    // 0x80800AA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800AA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800AA8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800AAC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800AB0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800AB4: jal         0x800EE7F8
    // 0x80800AB8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800AB8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_1:
    // 0x80800ABC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800AC0: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80800AC4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800AC8: lwc1        $f4, 0x24($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X24);
    // 0x80800ACC: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80800AD0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800AD4: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80800AD8: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80800ADC: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    // 0x80800AE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800AE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800AE8: jr          $ra
    // 0x80800AEC: nop

    return;
    // 0x80800AEC: nop

;}
RECOMP_FUNC void _bscrouch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082F58: syscall     36
    recomp_syscall_handler(rdram, ctx, 0x80082F58);
    return;
    // 0x80082F5C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800D0A9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0A9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D0AA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D0AA4: jal         0x800D0908
    // 0x800D0AA8: nop

    func_800D0908(rdram, ctx);
        goto after_0;
    // 0x800D0AA8: nop

    after_0:
    // 0x800D0AAC: bne         $v0, $zero, L_800D0ABC
    if (ctx->r2 != 0) {
        // 0x800D0AB0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800D0ABC;
    }
    // 0x800D0AB0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D0AB4: b           L_800D0AF8
    // 0x800D0AB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800D0AF8;
    // 0x800D0AB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D0ABC:
    // 0x800D0ABC: jal         0x800DA298
    // 0x800D0AC0: nop

    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x800D0AC0: nop

    after_1:
    // 0x800D0AC4: bne         $v0, $zero, L_800D0AEC
    if (ctx->r2 != 0) {
        // 0x800D0AC8: nop
    
            goto L_800D0AEC;
    }
    // 0x800D0AC8: nop

    // 0x800D0ACC: jal         0x80088848
    // 0x800D0AD0: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_2;
    // 0x800D0AD0: nop

    after_2:
    // 0x800D0AD4: bne         $v0, $zero, L_800D0AEC
    if (ctx->r2 != 0) {
        // 0x800D0AD8: nop
    
            goto L_800D0AEC;
    }
    // 0x800D0AD8: nop

    // 0x800D0ADC: jal         0x800D395C
    // 0x800D0AE0: nop

    func_800D395C(rdram, ctx);
        goto after_3;
    // 0x800D0AE0: nop

    after_3:
    // 0x800D0AE4: beq         $v0, $zero, L_800D0AF4
    if (ctx->r2 == 0) {
        // 0x800D0AE8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800D0AF4;
    }
    // 0x800D0AE8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800D0AEC:
    // 0x800D0AEC: b           L_800D0AF4
    // 0x800D0AF0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800D0AF4;
    // 0x800D0AF0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800D0AF4:
    // 0x800D0AF4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800D0AF8:
    // 0x800D0AF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D0AFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D0B00: jr          $ra
    // 0x800D0B04: nop

    return;
    // 0x800D0B04: nop

;}
RECOMP_FUNC void _dbid_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800879C8: syscall     646
    recomp_syscall_handler(rdram, ctx, 0x800879C8);
    return;
    // 0x800879CC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _bsclimb_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082F20: syscall     34
    recomp_syscall_handler(rdram, ctx, 0x80082F20);
    return;
    // 0x80082F24: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void bsbegghead_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080000C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800010: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    // 0x80800014: jal         0x8008CDB8
    // 0x80800018: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    baanim_playForDuration_once(rdram, ctx);
        goto after_0;
    // 0x80800018: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_0:
    // 0x8080001C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80800020: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800028: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080002C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800030: jal         0x8009FFD8
    // 0x80800034: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x80800034: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x80800038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080003C: lui         $a1, 0x43AF
    ctx->r5 = S32(0X43AF << 16);
    // 0x80800040: jal         0x8009C99C
    // 0x80800044: lui         $a2, 0x4160
    ctx->r6 = S32(0X4160 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_2;
    // 0x80800044: lui         $a2, 0x4160
    ctx->r6 = S32(0X4160 << 16);
    after_2:
    // 0x80800048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080004C: jal         0x8009B9B0
    // 0x80800050: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_3;
    // 0x80800050: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800058: jal         0x800A0CF4
    // 0x8080005C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_4;
    // 0x8080005C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800060: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800064: sw          $v0, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r2;
    // 0x80800068: sw          $v0, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r2;
    // 0x8080006C: jal         0x80094510
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80094510(rdram, ctx);
        goto after_5;
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800074: sw          $v0, 0x164($s0)
    MEM_W(0X164, ctx->r16) = ctx->r2;
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080007C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800080: jal         0x80098140
    // 0x80800084: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    bainput_enable(rdram, ctx);
        goto after_6;
    // 0x80800084: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80800088: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080008C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800090: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800094: jr          $ra
    // 0x80800098: nop

    return;
    // 0x80800098: nop

;}
RECOMP_FUNC void func_800B4374(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4374: jr          $ra
    // 0x800B4378: lh          $v0, 0x4($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X4);
    return;
    // 0x800B4378: lh          $v0, 0x4($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X4);
    // 0x800B437C: nop

;}
RECOMP_FUNC void idtwinkle_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800008: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080000C: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x80800010: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800014: addiu       $v1, $sp, 0xC
    ctx->r3 = ADD32(ctx->r29, 0XC);
    // 0x80800018: addiu       $v0, $sp, 0x18
    ctx->r2 = ADD32(ctx->r29, 0X18);
L_8080001C:
    // 0x8080001C: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x80800020: lh          $t7, 0xE($a2)
    ctx->r15 = MEM_H(ctx->r6, 0XE);
    // 0x80800024: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800028: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8080002C: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80800030: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80800034: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x80800038: bne         $at, $zero, L_8080001C
    if (ctx->r1 != 0) {
        // 0x8080003C: sw          $t8, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->r24;
            goto L_8080001C;
    }
    // 0x8080003C: sw          $t8, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r24;
    // 0x80800040: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x80800044: lw          $t1, 0xC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC);
    // 0x80800048: lw          $t4, 0x10($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X10);
    // 0x8080004C: multu       $t9, $t9
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800050: lw          $t6, 0x14($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X14);
    // 0x80800054: mflo        $t0
    ctx->r8 = lo;
    // 0x80800058: nop

    // 0x8080005C: nop

    // 0x80800060: multu       $t1, $t1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800064: mflo        $t2
    ctx->r10 = lo;
    // 0x80800068: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x8080006C: nop

    // 0x80800070: multu       $t4, $t4
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800074: mflo        $t5
    ctx->r13 = lo;
    // 0x80800078: addu        $v0, $t3, $t5
    ctx->r2 = ADD32(ctx->r11, ctx->r13);
    // 0x8080007C: slt         $at, $t6, $v0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800080: bne         $at, $zero, L_8080013C
    if (ctx->r1 != 0) {
        // 0x80800084: nop
    
            goto L_8080013C;
    }
    // 0x80800084: nop

    // 0x80800088: lh          $v1, 0x28($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X28);
    // 0x8080008C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800090: blez        $v1, L_808000DC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80800094: nop
    
            goto L_808000DC;
    }
    // 0x80800094: nop

    // 0x80800098: lw          $a0, 0x2C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X2C);
    // 0x8080009C: lh          $a2, 0x0($a1)
    ctx->r6 = MEM_H(ctx->r5, 0X0);
L_808000A0:
    // 0x808000A0: lh          $t7, 0x8($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X8);
    // 0x808000A4: bnel        $t7, $a2, L_808000D0
    if (ctx->r15 != ctx->r6) {
        // 0x808000A8: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_808000D0;
    }
    goto skip_0;
    // 0x808000A8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x808000AC: lh          $t8, 0xA($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XA);
    // 0x808000B0: lh          $t9, 0x2($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X2);
    // 0x808000B4: bnel        $t8, $t9, L_808000D0
    if (ctx->r24 != ctx->r25) {
        // 0x808000B8: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_808000D0;
    }
    goto skip_1;
    // 0x808000B8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_1:
    // 0x808000BC: lh          $t1, 0xC($a0)
    ctx->r9 = MEM_H(ctx->r4, 0XC);
    // 0x808000C0: lh          $t0, 0x4($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X4);
    // 0x808000C4: beq         $t1, $t0, L_808000DC
    if (ctx->r9 == ctx->r8) {
        // 0x808000C8: nop
    
            goto L_808000DC;
    }
    // 0x808000C8: nop

    // 0x808000CC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_808000D0:
    // 0x808000D0: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x808000D4: bne         $at, $zero, L_808000A0
    if (ctx->r1 != 0) {
        // 0x808000D8: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_808000A0;
    }
    // 0x808000D8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
L_808000DC:
    // 0x808000DC: bne         $v0, $v1, L_8080013C
    if (ctx->r2 != ctx->r3) {
        // 0x808000E0: slti        $at, $v1, 0xA
        ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
            goto L_8080013C;
    }
    // 0x808000E0: slti        $at, $v1, 0xA
    ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x808000E4: beq         $at, $zero, L_8080013C
    if (ctx->r1 == 0) {
        // 0x808000E8: nop
    
            goto L_8080013C;
    }
    // 0x808000E8: nop

    // 0x808000EC: lw          $t4, 0x2C($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X2C);
    // 0x808000F0: lh          $t2, 0x0($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X0);
    // 0x808000F4: sll         $t3, $v1, 4
    ctx->r11 = S32(ctx->r3 << 4);
    // 0x808000F8: addu        $t5, $t4, $t3
    ctx->r13 = ADD32(ctx->r12, ctx->r11);
    // 0x808000FC: sh          $t2, 0x8($t5)
    MEM_H(0X8, ctx->r13) = ctx->r10;
    // 0x80800100: lh          $t8, 0x28($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X28);
    // 0x80800104: lw          $t7, 0x2C($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X2C);
    // 0x80800108: lh          $t6, 0x2($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X2);
    // 0x8080010C: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80800110: addu        $t1, $t7, $t9
    ctx->r9 = ADD32(ctx->r15, ctx->r25);
    // 0x80800114: sh          $t6, 0xA($t1)
    MEM_H(0XA, ctx->r9) = ctx->r14;
    // 0x80800118: lh          $t3, 0x28($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X28);
    // 0x8080011C: lw          $t4, 0x2C($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X2C);
    // 0x80800120: lh          $t0, 0x4($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X4);
    // 0x80800124: sll         $t2, $t3, 4
    ctx->r10 = S32(ctx->r11 << 4);
    // 0x80800128: addu        $t5, $t4, $t2
    ctx->r13 = ADD32(ctx->r12, ctx->r10);
    // 0x8080012C: sh          $t0, 0xC($t5)
    MEM_H(0XC, ctx->r13) = ctx->r8;
    // 0x80800130: lh          $t8, 0x28($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X28);
    // 0x80800134: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x80800138: sh          $t7, 0x28($a3)
    MEM_H(0X28, ctx->r7) = ctx->r15;
L_8080013C:
    // 0x8080013C: jr          $ra
    // 0x80800140: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800140: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80800000_bstntswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800004: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x80096544
    // 0x8080000C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_80096544(rdram, ctx);
        goto after_0;
    // 0x8080000C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800010: beql        $v0, $zero, L_808000A4
    if (ctx->r2 == 0) {
        // 0x80800014: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808000A4;
    }
    goto skip_0;
    // 0x80800014: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800018: jal         0x800DC0C0
    // 0x8080001C: nop

    func_800DC0C0(rdram, ctx);
        goto after_1;
    // 0x8080001C: nop

    after_1:
    // 0x80800020: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800024: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800028: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8080002C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800030: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800034: nop

    // 0x80800038: bc1f        L_80800050
    if (!c1cs) {
        // 0x8080003C: nop
    
            goto L_80800050;
    }
    // 0x8080003C: nop

    // 0x80800040: jal         0x80092C00
    // 0x80800044: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80092C00(rdram, ctx);
        goto after_2;
    // 0x80800044: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x80800048: b           L_8080005C
    // 0x8080004C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
        goto L_8080005C;
    // 0x8080004C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_80800050:
    // 0x80800050: jal         0x80092C24
    // 0x80800054: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_80092C24(rdram, ctx);
        goto after_3;
    // 0x80800054: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x80800058: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_8080005C:
    // 0x8080005C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800060: jal         0x8009FBB0
    // 0x80800064: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8009FBB0(rdram, ctx);
        goto after_4;
    // 0x80800064: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_4:
    // 0x80800068: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x8080006C: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x80800070: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800074: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80800078: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080007C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800080: addiu       $a1, $zero, -0x3C
    ctx->r5 = ADD32(0, -0X3C);
    // 0x80800084: addiu       $a2, $zero, -0x64
    ctx->r6 = ADD32(0, -0X64);
    // 0x80800088: addiu       $a3, $zero, -0x3C
    ctx->r7 = ADD32(0, -0X3C);
    // 0x8080008C: jal         0x800BA930
    // 0x80800090: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_800BA930(rdram, ctx);
        goto after_5;
    // 0x80800090: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_5:
    // 0x80800094: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800098: jal         0x800BA22C
    // 0x8080009C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_6;
    // 0x8080009C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808000A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000A4:
    // 0x808000A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808000A8: jr          $ra
    // 0x808000AC: nop

    return;
    // 0x808000AC: nop

;}
RECOMP_FUNC void func_80800034_bskazcrouch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800034: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800038: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080003C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800040: addiu       $a1, $zero, 0x141
    ctx->r5 = ADD32(0, 0X141);
    // 0x80800044: jal         0x8008CCBC
    // 0x80800048: lui         $a2, 0x4060
    ctx->r6 = S32(0X4060 << 16);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_0;
    // 0x80800048: lui         $a2, 0x4060
    ctx->r6 = S32(0X4060 << 16);
    after_0:
    // 0x8080004C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800050: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800054: sw          $t6, 0x15C($t7)
    MEM_W(0X15C, ctx->r15) = ctx->r14;
    // 0x80800058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080005C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800060: jr          $ra
    // 0x80800064: nop

    return;
    // 0x80800064: nop

;}
RECOMP_FUNC void _gcegg_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800883C0: syscall     680
    recomp_syscall_handler(rdram, ctx, 0x800883C0);
    return;
    // 0x800883C4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _bsblongleg_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082A08: syscall     24
    recomp_syscall_handler(rdram, ctx, 0x80082A08);
    return;
    // 0x80082A0C: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void bamotor_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800070: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800074: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800078: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080007C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800080: jal         0x800918F8
    // 0x80800084: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    bakey_getControllerIndex(rdram, ctx);
        goto after_0;
    // 0x80800084: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800088: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080008C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800090: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800094: jal         0x800187E8
    // 0x80800098: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    func_800187E8(rdram, ctx);
        goto after_1;
    // 0x80800098: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8080009C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000A4: jr          $ra
    // 0x808000A8: nop

    return;
    // 0x808000A8: nop

;}
RECOMP_FUNC void _bsrest_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800839B0: syscall     84
    recomp_syscall_handler(rdram, ctx, 0x800839B0);
    return;
    // 0x800839B4: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void _bskazstilt_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083690: syscall     71
    recomp_syscall_handler(rdram, ctx, 0x80083690);
    return;
    // 0x80083694: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void _ncpod_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800894F0: syscall     783
    recomp_syscall_handler(rdram, ctx, 0x800894F0);
    return;
    // 0x800894F4: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_80801534_chevilspirit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801534: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801538: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080153C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801540: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801544: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80801548: jal         0x8008FE94
    // 0x8080154C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_8008FE94(rdram, ctx);
        goto after_0;
    // 0x8080154C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_0:
    // 0x80801550: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80801554: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801558: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8080155C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801560: lui         $a1, 0x41C8
    ctx->r5 = S32(0X41C8 << 16);
    // 0x80801564: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80801568: jal         0x808015E0
    // 0x8080156C: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
    func_808015E0_chevilspirit(rdram, ctx);
        goto after_1;
    // 0x8080156C: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
    after_1:
    // 0x80801570: beq         $v0, $zero, L_80801590
    if (ctx->r2 == 0) {
        // 0x80801574: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801590;
    }
    // 0x80801574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801578: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(924, 0X22E8) << 16);
    // 0x8080157C: jal         0x80802090
    // 0x80801580: addiu       $a1, $a1, 0x22E8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(924, 0X22E8));
    func_80802090_chevilspirit(rdram, ctx);
        goto after_2;
    // 0x80801580: addiu       $a1, $a1, 0x22E8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(924, 0X22E8));
    after_2:
    // 0x80801584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801588: jal         0x80102424
    // 0x8080158C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x8080158C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
L_80801590:
    // 0x80801590: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801594: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801598: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080159C: jr          $ra
    // 0x808015A0: nop

    return;
    // 0x808015A0: nop

;}
RECOMP_FUNC void _chwitchytents_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085C18: syscall     209
    recomp_syscall_handler(rdram, ctx, 0x80085C18);
    return;
    // 0x80085C1C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void bsjump_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800E24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E28: jal         0x8008E95C
    // 0x80800E2C: nop

    func_8008E95C(rdram, ctx);
        goto after_0;
    // 0x80800E2C: nop

    after_0:
    // 0x80800E30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800E38: jr          $ra
    // 0x80800E3C: nop

    return;
    // 0x80800E3C: nop

;}
RECOMP_FUNC void func_80801A64_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A64: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801A68: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801A6C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801A70: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801A74: jal         0x8008CABC
    // 0x80801A78: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80801A78: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_0:
    // 0x80801A7C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80801A80: jal         0x808001D4
    // 0x80801A84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001D4_bsbansack(rdram, ctx);
        goto after_1;
    // 0x80801A84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801A88: lbu         $v0, 0x15C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X15C);
    // 0x80801A8C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801A90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A94: beq         $v0, $at, L_80801AC4
    if (ctx->r2 == ctx->r1) {
        // 0x80801A98: lui         $a1, 0x3D4C
        ctx->r5 = S32(0X3D4C << 16);
            goto L_80801AC4;
    }
    // 0x80801A98: lui         $a1, 0x3D4C
    ctx->r5 = S32(0X3D4C << 16);
    // 0x80801A9C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801AA0: beq         $v0, $at, L_80801B60
    if (ctx->r2 == ctx->r1) {
        // 0x80801AA4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801B60;
    }
    // 0x80801AA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801AA8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801AAC: beq         $v0, $at, L_80801BA0
    if (ctx->r2 == ctx->r1) {
        // 0x80801AB0: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80801BA0;
    }
    // 0x80801AB0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801AB4: beq         $v0, $at, L_80801BE8
    if (ctx->r2 == ctx->r1) {
        // 0x80801AB8: nop
    
            goto L_80801BE8;
    }
    // 0x80801AB8: nop

    // 0x80801ABC: b           L_80801C6C
    // 0x80801AC0: nop

        goto L_80801C6C;
    // 0x80801AC0: nop

L_80801AC4:
    // 0x80801AC4: jal         0x8008CB10
    // 0x80801AC8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    baanim_isAt(rdram, ctx);
        goto after_2;
    // 0x80801AC8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_2:
    // 0x80801ACC: beq         $v0, $zero, L_80801AFC
    if (ctx->r2 == 0) {
        // 0x80801AD0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801AFC;
    }
    // 0x80801AD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801AD4: lui         $a2, 0x3F73
    ctx->r6 = S32(0X3F73 << 16);
    // 0x80801AD8: lui         $a3, 0x3F86
    ctx->r7 = S32(0X3F86 << 16);
    // 0x80801ADC: addiu       $t6, $zero, 0x2328
    ctx->r14 = ADD32(0, 0X2328);
    // 0x80801AE0: addiu       $t7, $zero, 0x2AF8
    ctx->r15 = ADD32(0, 0X2AF8);
    // 0x80801AE4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80801AE8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801AEC: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80801AF0: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80801AF4: jal         0x8009DEC0
    // 0x80801AF8: addiu       $a1, $zero, 0x58A
    ctx->r5 = ADD32(0, 0X58A);
    func_8009DEC0(rdram, ctx);
        goto after_3;
    // 0x80801AF8: addiu       $a1, $zero, 0x58A
    ctx->r5 = ADD32(0, 0X58A);
    after_3:
L_80801AFC:
    // 0x80801AFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801B00: jal         0x8008DF8C
    // 0x80801B04: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008DF8C(rdram, ctx);
        goto after_4;
    // 0x80801B04: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_4:
    // 0x80801B08: bnel        $v0, $zero, L_80801B20
    if (ctx->r2 != 0) {
        // 0x80801B0C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801B20;
    }
    goto skip_0;
    // 0x80801B0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80801B10: jal         0x80800AA4
    // 0x80801B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800AA4_bsbansack(rdram, ctx);
        goto after_5;
    // 0x80801B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80801B18: beq         $v0, $zero, L_80801B30
    if (ctx->r2 == 0) {
        // 0x80801B1C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801B30;
    }
    // 0x80801B1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801B20:
    // 0x80801B20: jal         0x80801680
    // 0x80801B24: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80801680_bsbansack(rdram, ctx);
        goto after_6;
    // 0x80801B24: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x80801B28: b           L_80801B4C
    // 0x80801B2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801B4C;
    // 0x80801B2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801B30:
    // 0x80801B30: jal         0x8008B324
    // 0x80801B34: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_isStopped(rdram, ctx);
        goto after_7;
    // 0x80801B34: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_7:
    // 0x80801B38: beq         $v0, $zero, L_80801B48
    if (ctx->r2 == 0) {
        // 0x80801B3C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801B48;
    }
    // 0x80801B3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801B40: jal         0x80801680
    // 0x80801B44: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80801680_bsbansack(rdram, ctx);
        goto after_8;
    // 0x80801B44: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
L_80801B48:
    // 0x80801B48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801B4C:
    // 0x80801B4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801B50: jal         0x80800000
    // 0x80801B54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800000_bsbansack(rdram, ctx);
        goto after_9;
    // 0x80801B54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x80801B58: b           L_80801C6C
    // 0x80801B5C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
        goto L_80801C6C;
    // 0x80801B5C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_80801B60:
    // 0x80801B60: jal         0x8008DF8C
    // 0x80801B64: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008DF8C(rdram, ctx);
        goto after_10;
    // 0x80801B64: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_10:
    // 0x80801B68: bnel        $v0, $zero, L_80801B80
    if (ctx->r2 != 0) {
        // 0x80801B6C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801B80;
    }
    goto skip_1;
    // 0x80801B6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80801B70: jal         0x80800AA4
    // 0x80801B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800AA4_bsbansack(rdram, ctx);
        goto after_11;
    // 0x80801B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80801B78: beq         $v0, $zero, L_80801B88
    if (ctx->r2 == 0) {
        // 0x80801B7C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801B88;
    }
    // 0x80801B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801B80:
    // 0x80801B80: jal         0x80801680
    // 0x80801B84: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80801680_bsbansack(rdram, ctx);
        goto after_12;
    // 0x80801B84: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_12:
L_80801B88:
    // 0x80801B88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801B8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801B90: jal         0x80800000
    // 0x80801B94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800000_bsbansack(rdram, ctx);
        goto after_13;
    // 0x80801B94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_13:
    // 0x80801B98: b           L_80801C6C
    // 0x80801B9C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
        goto L_80801C6C;
    // 0x80801B9C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_80801BA0:
    // 0x80801BA0: jal         0x80800368
    // 0x80801BA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800368_bsbansack(rdram, ctx);
        goto after_14;
    // 0x80801BA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80801BA8: jal         0x8008E078
    // 0x80801BAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_15;
    // 0x80801BAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80801BB0: bnel        $v0, $zero, L_80801BC8
    if (ctx->r2 != 0) {
        // 0x80801BB4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801BC8;
    }
    goto skip_2;
    // 0x80801BB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80801BB8: jal         0x8008E35C
    // 0x80801BBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_16;
    // 0x80801BBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80801BC0: beq         $v0, $zero, L_80801BD0
    if (ctx->r2 == 0) {
        // 0x80801BC4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801BD0;
    }
    // 0x80801BC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801BC8:
    // 0x80801BC8: jal         0x80801680
    // 0x80801BCC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80801680_bsbansack(rdram, ctx);
        goto after_17;
    // 0x80801BCC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_17:
L_80801BD0:
    // 0x80801BD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801BD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801BD8: jal         0x80800000
    // 0x80801BDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800000_bsbansack(rdram, ctx);
        goto after_18;
    // 0x80801BDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_18:
    // 0x80801BE0: b           L_80801C6C
    // 0x80801BE4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
        goto L_80801C6C;
    // 0x80801BE4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_80801BE8:
    // 0x80801BE8: jal         0x80800368
    // 0x80801BEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800368_bsbansack(rdram, ctx);
        goto after_19;
    // 0x80801BEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80801BF0: jal         0x8008B324
    // 0x80801BF4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_isStopped(rdram, ctx);
        goto after_20;
    // 0x80801BF4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_20:
    // 0x80801BF8: beq         $v0, $zero, L_80801C54
    if (ctx->r2 == 0) {
        // 0x80801BFC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801C54;
    }
    // 0x80801BFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C00: jal         0x8009BB00
    // 0x80801C04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_21;
    // 0x80801C04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80801C08: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801C0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C10: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80801C14: nop

    // 0x80801C18: bc1f        L_80801C30
    if (!c1cs) {
        // 0x80801C1C: nop
    
            goto L_80801C30;
    }
    // 0x80801C1C: nop

    // 0x80801C20: jal         0x80801680
    // 0x80801C24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801680_bsbansack(rdram, ctx);
        goto after_22;
    // 0x80801C24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_22:
    // 0x80801C28: b           L_80801C60
    // 0x80801C2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801C60;
    // 0x80801C2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801C30:
    // 0x80801C30: jal         0x8008E35C
    // 0x80801C34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_23;
    // 0x80801C34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80801C38: beq         $v0, $zero, L_80801C4C
    if (ctx->r2 == 0) {
        // 0x80801C3C: addiu       $t9, $zero, 0x165
        ctx->r25 = ADD32(0, 0X165);
            goto L_80801C4C;
    }
    // 0x80801C3C: addiu       $t9, $zero, 0x165
    ctx->r25 = ADD32(0, 0X165);
    // 0x80801C40: addiu       $t8, $zero, 0x167
    ctx->r24 = ADD32(0, 0X167);
    // 0x80801C44: b           L_80801C5C
    // 0x80801C48: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
        goto L_80801C5C;
    // 0x80801C48: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
L_80801C4C:
    // 0x80801C4C: b           L_80801C5C
    // 0x80801C50: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
        goto L_80801C5C;
    // 0x80801C50: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_80801C54:
    // 0x80801C54: jal         0x8009B9B0
    // 0x80801C58: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_24;
    // 0x80801C58: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    after_24:
L_80801C5C:
    // 0x80801C5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801C60:
    // 0x80801C60: jal         0x80800084
    // 0x80801C64: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80800084_bsbansack(rdram, ctx);
        goto after_25;
    // 0x80801C64: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_25:
    // 0x80801C68: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_80801C6C:
    // 0x80801C6C: jal         0x8008E260
    // 0x80801C70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E260(rdram, ctx);
        goto after_26;
    // 0x80801C70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80801C74: beq         $v0, $zero, L_80801C84
    if (ctx->r2 == 0) {
        // 0x80801C78: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801C84;
    }
    // 0x80801C78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C7C: addiu       $t0, $zero, 0x3D
    ctx->r8 = ADD32(0, 0X3D);
    // 0x80801C80: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
L_80801C84:
    // 0x80801C84: jal         0x8009E5C8
    // 0x80801C88: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    bs_setState(rdram, ctx);
        goto after_27;
    // 0x80801C88: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_27:
    // 0x80801C8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801C90: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801C94: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80801C98: jr          $ra
    // 0x80801C9C: nop

    return;
    // 0x80801C9C: nop

;}
RECOMP_FUNC void func_80800050_chfactorybattery(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800050: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800054: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800058: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080005C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800060: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800064: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80800068: jal         0x800CB3E0
    // 0x8080006C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800CB3E0(rdram, ctx);
        goto after_0;
    // 0x8080006C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800070: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800074: beq         $v0, $at, L_808000A4
    if (ctx->r2 == ctx->r1) {
        // 0x80800078: andi        $t7, $s1, 0x1FF
        ctx->r15 = ctx->r17 & 0X1FF;
            goto L_808000A4;
    }
    // 0x80800078: andi        $t7, $s1, 0x1FF
    ctx->r15 = ctx->r17 & 0X1FF;
    // 0x8080007C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800080: beq         $v0, $at, L_808000E0
    if (ctx->r2 == ctx->r1) {
        // 0x80800084: andi        $t5, $s1, 0x1FF
        ctx->r13 = ctx->r17 & 0X1FF;
            goto L_808000E0;
    }
    // 0x80800084: andi        $t5, $s1, 0x1FF
    ctx->r13 = ctx->r17 & 0X1FF;
    // 0x80800088: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080008C: beq         $v0, $at, L_80800118
    if (ctx->r2 == ctx->r1) {
        // 0x80800090: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80800118;
    }
    // 0x80800090: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800094: beq         $v0, $at, L_8080015C
    if (ctx->r2 == ctx->r1) {
        // 0x80800098: nop
    
            goto L_8080015C;
    }
    // 0x80800098: nop

    // 0x8080009C: b           L_8080015C
    // 0x808000A0: nop

        goto L_8080015C;
    // 0x808000A0: nop

L_808000A4:
    // 0x808000A4: lhu         $t8, 0x6E($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X6E);
    // 0x808000A8: lui         $a1, 0x3EE6
    ctx->r5 = S32(0X3EE6 << 16);
    // 0x808000AC: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x808000B0: andi        $t9, $t8, 0xFE00
    ctx->r25 = ctx->r24 & 0XFE00;
    // 0x808000B4: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x808000B8: sh          $t0, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r8;
    // 0x808000BC: jal         0x80102FDC
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102FDC(rdram, ctx);
        goto after_1;
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808000C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C8: jal         0x8080130C
    // 0x808000CC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_8080130C_chfactorybattery(rdram, ctx);
        goto after_2;
    // 0x808000CC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_2:
    // 0x808000D0: lbu         $t2, 0x64($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X64);
    // 0x808000D4: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x808000D8: b           L_8080015C
    // 0x808000DC: sb          $t3, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r11;
        goto L_8080015C;
    // 0x808000DC: sb          $t3, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r11;
L_808000E0:
    // 0x808000E0: lhu         $t6, 0x6E($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X6E);
    // 0x808000E4: lui         $a1, 0x3EE6
    ctx->r5 = S32(0X3EE6 << 16);
    // 0x808000E8: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x808000EC: andi        $t8, $t6, 0xFE00
    ctx->r24 = ctx->r14 & 0XFE00;
    // 0x808000F0: or          $t7, $t5, $t8
    ctx->r15 = ctx->r13 | ctx->r24;
    // 0x808000F4: sh          $t7, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r15;
    // 0x808000F8: jal         0x80102FDC
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102FDC(rdram, ctx);
        goto after_3;
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800104: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800108: jal         0x8008A548
    // 0x8080010C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    _subaddietaxi_entrypoint_10(rdram, ctx);
        goto after_4;
    // 0x8080010C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_4:
    // 0x80800110: b           L_8080015C
    // 0x80800114: nop

        goto L_8080015C;
    // 0x80800114: nop

L_80800118:
    // 0x80800118: jal         0x80800580
    // 0x8080011C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_80800580_chfactorybattery(rdram, ctx);
        goto after_5;
    // 0x8080011C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_5:
    // 0x80800120: lhu         $t1, 0x6E($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800124: andi        $t0, $s1, 0x1FF
    ctx->r8 = ctx->r17 & 0X1FF;
    // 0x80800128: lui         $a1, 0x3EE6
    ctx->r5 = S32(0X3EE6 << 16);
    // 0x8080012C: andi        $t2, $t1, 0xFE00
    ctx->r10 = ctx->r9 & 0XFE00;
    // 0x80800130: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x80800134: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x80800138: sh          $t3, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r11;
    // 0x8080013C: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80800140: jal         0x80102FDC
    // 0x80800144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102FDC(rdram, ctx);
        goto after_6;
    // 0x80800144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080014C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800150: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x80800154: jal         0x8008A4F8
    // 0x80800158: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _subaddietaxi_entrypoint_0(rdram, ctx);
        goto after_7;
    // 0x80800158: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_7:
L_8080015C:
    // 0x8080015C: beql        $s0, $zero, L_8080018C
    if (ctx->r16 == 0) {
        // 0x80800160: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080018C;
    }
    goto skip_0;
    // 0x80800160: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800164: lw          $t4, 0x6C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X6C);
    // 0x80800168: srl         $t6, $t4, 21
    ctx->r14 = S32(U32(ctx->r12) >> 21);
    // 0x8080016C: bnel        $t6, $zero, L_8080018C
    if (ctx->r14 != 0) {
        // 0x80800170: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080018C;
    }
    goto skip_1;
    // 0x80800170: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800174: lhu         $t7, 0x6E($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800178: andi        $t8, $s1, 0x1FF
    ctx->r24 = ctx->r17 & 0X1FF;
    // 0x8080017C: andi        $t9, $t7, 0xFE00
    ctx->r25 = ctx->r15 & 0XFE00;
    // 0x80800180: or          $t1, $t8, $t9
    ctx->r9 = ctx->r24 | ctx->r25;
    // 0x80800184: sh          $t1, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r9;
    // 0x80800188: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080018C:
    // 0x8080018C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800190: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800194: jr          $ra
    // 0x80800198: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800198: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80801A94_chhoopswoop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801A98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801A9C: jal         0x80101870
    // 0x80801AA0: nop

    func_80101870(rdram, ctx);
        goto after_0;
    // 0x80801AA0: nop

    after_0:
    // 0x80801AA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801AA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801AAC: jr          $ra
    // 0x80801AB0: nop

    return;
    // 0x80801AB0: nop

;}
RECOMP_FUNC void func_80802540_chdinoboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802540: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802544: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802548: jal         0x800F54E4
    // 0x8080254C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8080254C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80802550: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80802554: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80802558: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8080255C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802560: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80802564: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80802568: jal         0x800F4F34
    // 0x8080256C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800F4F34(rdram, ctx);
        goto after_1;
    // 0x8080256C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_1:
    // 0x80802570: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80802574: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80802578: jal         0x8008A0D0
    // 0x8080257C: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x8080257C: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_2:
    // 0x80802580: beql        $v0, $zero, L_808025A8
    if (ctx->r2 == 0) {
        // 0x80802584: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_808025A8;
    }
    goto skip_0;
    // 0x80802584: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_0:
    // 0x80802588: jal         0x800F54E4
    // 0x8080258C: nop

    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x8080258C: nop

    after_3:
    // 0x80802590: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802594: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80802598: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8080259C: jal         0x800F4F34
    // 0x808025A0: lui         $a3, 0x4396
    ctx->r7 = S32(0X4396 << 16);
    func_800F4F34(rdram, ctx);
        goto after_4;
    // 0x808025A0: lui         $a3, 0x4396
    ctx->r7 = S32(0X4396 << 16);
    after_4:
    // 0x808025A4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_808025A8:
    // 0x808025A8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x808025AC: jal         0x8008A0D0
    // 0x808025B0: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x808025B0: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_5:
    // 0x808025B4: beql        $v0, $zero, L_808025DC
    if (ctx->r2 == 0) {
        // 0x808025B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808025DC;
    }
    goto skip_1;
    // 0x808025B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808025BC: jal         0x800F54E4
    // 0x808025C0: nop

    func_800F54E4(rdram, ctx);
        goto after_6;
    // 0x808025C0: nop

    after_6:
    // 0x808025C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808025C8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x808025CC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808025D0: jal         0x800F4F34
    // 0x808025D4: lui         $a3, 0x4396
    ctx->r7 = S32(0X4396 << 16);
    func_800F4F34(rdram, ctx);
        goto after_7;
    // 0x808025D4: lui         $a3, 0x4396
    ctx->r7 = S32(0X4396 << 16);
    after_7:
    // 0x808025D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808025DC:
    // 0x808025DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808025E0: jr          $ra
    // 0x808025E4: nop

    return;
    // 0x808025E4: nop

;}
RECOMP_FUNC void glgamedata_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800300: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800304: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800308: jal         0x808002CC
    // 0x8080030C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_808002CC_glgamedata(rdram, ctx);
        goto after_0;
    // 0x8080030C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800310: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80800314: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80800318: bne         $v0, $zero, L_80800328
    if (ctx->r2 != 0) {
        // 0x8080031C: sw          $v0, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r2;
            goto L_80800328;
    }
    // 0x8080031C: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x80800320: b           L_80800374
    // 0x80800324: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800374;
    // 0x80800324: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800328:
    // 0x80800328: lbu         $a1, 0x27($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X27);
L_8080032C:
    // 0x8080032C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80800330: addu        $v0, $t6, $s0
    ctx->r2 = ADD32(ctx->r14, ctx->r16);
    // 0x80800334: lbu         $t7, 0x1($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X1);
    // 0x80800338: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x8080033C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80800340: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80800344: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80800348: addiu       $t9, $t8, 0x2
    ctx->r25 = ADD32(ctx->r24, 0X2);
    // 0x8080034C: bne         $a1, $a0, L_8080035C
    if (ctx->r5 != ctx->r4) {
        // 0x80800350: sw          $t9, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r25;
            goto L_8080035C;
    }
    // 0x80800350: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80800354: b           L_80800374
    // 0x80800358: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800374;
    // 0x80800358: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080035C:
    // 0x8080035C: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x80800360: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x80800364: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80800368: bne         $a0, $zero, L_8080032C
    if (ctx->r4 != 0) {
        // 0x8080036C: sw          $t2, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r10;
            goto L_8080032C;
    }
    // 0x8080036C: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
    // 0x80800370: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800374:
    // 0x80800374: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800378: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080037C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800380: jr          $ra
    // 0x80800384: nop

    return;
    // 0x80800384: nop

;}
RECOMP_FUNC void _sujiggy_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A6E8: syscall     849
    recomp_syscall_handler(rdram, ctx, 0x8008A6E8);
    return;
    // 0x8008A6EC: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void _gspropctrl_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088BE0: syscall     728
    recomp_syscall_handler(rdram, ctx, 0x80088BE0);
    return;
    // 0x80088BE4: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void _gsmaker_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800825C8: syscall     2
    recomp_syscall_handler(rdram, ctx, 0x800825C8);
    return;
    // 0x800825CC: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void bamovehover_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001FC: bne         $a1, $zero, L_80800218
    if (ctx->r5 != 0) {
        // 0x80800200: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_80800218;
    }
    // 0x80800200: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800204: lw          $a0, 0xC8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XC8);
    // 0x80800208: jal         0x800EFD24
    // 0x8080020C: addiu       $a0, $a0, 0xB8
    ctx->r4 = ADD32(ctx->r4, 0XB8);
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x8080020C: addiu       $a0, $a0, 0xB8
    ctx->r4 = ADD32(ctx->r4, 0XB8);
    after_0:
    // 0x80800210: b           L_80800228
    // 0x80800214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800228;
    // 0x80800214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800218:
    // 0x80800218: lw          $a0, 0xC8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XC8);
    // 0x8080021C: jal         0x800EE7F8
    // 0x80800220: addiu       $a0, $a0, 0xB8
    ctx->r4 = ADD32(ctx->r4, 0XB8);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800220: addiu       $a0, $a0, 0xB8
    ctx->r4 = ADD32(ctx->r4, 0XB8);
    after_1:
    // 0x80800224: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800228:
    // 0x80800228: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080022C: jr          $ra
    // 0x80800230: nop

    return;
    // 0x80800230: nop

    // 0x80800234: nop

    // 0x80800238: nop

    // 0x8080023C: nop

;}
RECOMP_FUNC void func_808000B4_baeggaim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000BC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x808000C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000C4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808000C8: jal         0x80084AC8
    // 0x808000CC: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    _baeggcursor_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808000CC: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_0:
    // 0x808000D0: jal         0x8009EF28
    // 0x808000D4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    bastick_getX(rdram, ctx);
        goto after_1;
    // 0x808000D4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x808000D8: lui         $at, 0x42E4
    ctx->r1 = S32(0X42E4 << 16);
    // 0x808000DC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808000E0: lui         $at, 0x4218
    ctx->r1 = S32(0X4218 << 16);
    // 0x808000E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808000E8: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x808000EC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808000F0: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x808000F4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x808000F8: jal         0x8009EF34
    // 0x808000FC: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    bastick_getY(rdram, ctx);
        goto after_2;
    // 0x808000FC: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x80800100: lui         $at, 0x42AB
    ctx->r1 = S32(0X42AB << 16);
    // 0x80800104: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800108: lui         $at, 0x41E4
    ctx->r1 = S32(0X41E4 << 16);
    // 0x8080010C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800110: mul.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80800114: lui         $a2, 0x40EC
    ctx->r6 = S32(0X40EC << 16);
    // 0x80800118: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8080011C: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800120: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x80800124: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80800128: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8080012C: jal         0x80800008
    // 0x80800130: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    func_80800008_baeggaim(rdram, ctx);
        goto after_3;
    // 0x80800130: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x80800134: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x80800138: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8080013C: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800140: jal         0x80800008
    // 0x80800144: lui         $a2, 0x40B0
    ctx->r6 = S32(0X40B0 << 16);
    func_80800008_baeggaim(rdram, ctx);
        goto after_4;
    // 0x80800144: lui         $a2, 0x40B0
    ctx->r6 = S32(0X40B0 << 16);
    after_4:
    // 0x80800148: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x8080014C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800150: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800154: jal         0x80084B00
    // 0x80800158: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    _baeggcursor_entrypoint_10(rdram, ctx);
        goto after_5;
    // 0x80800158: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_5:
    // 0x8080015C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800160: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800164: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800168: jr          $ra
    // 0x8080016C: nop

    return;
    // 0x8080016C: nop

;}
RECOMP_FUNC void _bsdronesuckunder_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083158: syscall     47
    recomp_syscall_handler(rdram, ctx, 0x80083158);
    return;
    // 0x8008315C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void idworldmake_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A20: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800A24: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800A28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A2C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800A30: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80800A34: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800A38: lw          $a0, 0x7EF8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7EF8);
    // 0x80800A3C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x80800A40: jal         0x800B296C
    // 0x80800A44: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    vector_end(rdram, ctx);
        goto after_0;
    // 0x80800A44: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800A48: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80800A4C: lw          $a0, 0x7EF8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7EF8);
    // 0x80800A50: jal         0x800B28C4
    // 0x80800A54: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    vector_begin(rdram, ctx);
        goto after_1;
    // 0x80800A54: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800A58: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800A5C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80800A60: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80800A64: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x80800A68: beq         $at, $zero, L_80800A9C
    if (ctx->r1 == 0) {
        // 0x80800A6C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800A9C;
    }
    // 0x80800A6C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800A70: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_80800A74:
    // 0x80800A74: bnel        $a3, $t6, L_80800A90
    if (ctx->r7 != ctx->r14) {
        // 0x80800A78: addiu       $v1, $v1, 0xA8
        ctx->r3 = ADD32(ctx->r3, 0XA8);
            goto L_80800A90;
    }
    goto skip_0;
    // 0x80800A78: addiu       $v1, $v1, 0xA8
    ctx->r3 = ADD32(ctx->r3, 0XA8);
    skip_0:
    // 0x80800A7C: lh          $t7, 0x4($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X4);
    // 0x80800A80: bnel        $s0, $t7, L_80800A90
    if (ctx->r16 != ctx->r15) {
        // 0x80800A84: addiu       $v1, $v1, 0xA8
        ctx->r3 = ADD32(ctx->r3, 0XA8);
            goto L_80800A90;
    }
    goto skip_1;
    // 0x80800A84: addiu       $v1, $v1, 0xA8
    ctx->r3 = ADD32(ctx->r3, 0XA8);
    skip_1:
    // 0x80800A88: sb          $a2, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r6;
    // 0x80800A8C: addiu       $v1, $v1, 0xA8
    ctx->r3 = ADD32(ctx->r3, 0XA8);
L_80800A90:
    // 0x80800A90: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x80800A94: bnel        $at, $zero, L_80800A74
    if (ctx->r1 != 0) {
        // 0x80800A98: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_80800A74;
    }
    goto skip_2;
    // 0x80800A98: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_2:
L_80800A9C:
    // 0x80800A9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800AA0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800AA4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800AA8: jr          $ra
    // 0x80800AAC: nop

    return;
    // 0x80800AAC: nop

;}
