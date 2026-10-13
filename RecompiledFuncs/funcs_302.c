#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80801058_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801058: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080105C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801060: jal         0x80085240
    // 0x80801064: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _basudie_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x80801064: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801068: jal         0x80800E54
    // 0x8080106C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bstnt_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x8080106C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801074: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801078: jr          $ra
    // 0x8080107C: nop

    return;
    // 0x8080107C: nop

;}
RECOMP_FUNC void _chmrsicecube_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086318: syscall     307
    recomp_syscall_handler(rdram, ctx, 0x80086318);
    return;
    // 0x8008631C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808000B0_chbilldrillplate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808000B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000BC: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x808000C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000C8: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808000CC: beq         $t6, $at, L_8080022C
    if (ctx->r14 == ctx->r1) {
        // 0x808000D0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080022C;
    }
    // 0x808000D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000D4: beq         $t6, $at, L_808000EC
    if (ctx->r14 == ctx->r1) {
        // 0x808000D8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808000EC;
    }
    // 0x808000D8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808000DC: beq         $t6, $at, L_808001C4
    if (ctx->r14 == ctx->r1) {
        // 0x808000E0: nop
    
            goto L_808001C4;
    }
    // 0x808000E0: nop

    // 0x808000E4: b           L_80800230
    // 0x808000E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800230;
    // 0x808000E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000EC:
    // 0x808000EC: jal         0x800D90A4
    // 0x808000F0: addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    func_800D90A4(rdram, ctx);
        goto after_0;
    // 0x808000F0: addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    after_0:
    // 0x808000F4: beq         $v0, $zero, L_80800118
    if (ctx->r2 == 0) {
        // 0x808000F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800118;
    }
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000FC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1192, 0X11B4) << 16);
    // 0x80800100: addiu       $a2, $a2, 0x11B4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1192, 0X11B4));
    // 0x80800104: jal         0x80089D18
    // 0x80800108: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800108: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x8080010C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1192, 0X1080) << 16);
    // 0x80800110: lwc1        $f4, 0x1080($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1192, 0X1080));
    // 0x80800114: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
L_80800118:
    // 0x80800118: jal         0x800D8FF8
    // 0x8080011C: nop

    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x8080011C: nop

    after_2:
    // 0x80800120: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80800124: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800128: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8080012C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800130: jal         0x800136E4
    // 0x80800134: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    func_800136E4(rdram, ctx);
        goto after_3;
    // 0x80800134: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_3:
    // 0x80800138: jal         0x800D8FF8
    // 0x8080013C: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_4;
    // 0x8080013C: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    after_4:
    // 0x80800140: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800144: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800148: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8080014C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800150: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80800154: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80800158: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8080015C: jal         0x8008A4C0
    // 0x80800160: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    _subaddieDll_entrypoint_6(rdram, ctx);
        goto after_5;
    // 0x80800160: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    after_5:
    // 0x80800164: beq         $v0, $zero, L_8080022C
    if (ctx->r2 == 0) {
        // 0x80800168: addiu       $t7, $s0, 0x4
        ctx->r15 = ADD32(ctx->r16, 0X4);
            goto L_8080022C;
    }
    // 0x80800168: addiu       $t7, $s0, 0x4
    ctx->r15 = ADD32(ctx->r16, 0X4);
    // 0x8080016C: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800170: jal         0x800858E0
    // 0x80800174: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    _chbounce_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x80800174: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    after_6:
    // 0x80800178: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    // 0x8080017C: jal         0x800858F0
    // 0x80800180: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _chbounce_entrypoint_5(rdram, ctx);
        goto after_7;
    // 0x80800180: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800188: jal         0x80101FDC
    // 0x8080018C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_8;
    // 0x8080018C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_8:
    // 0x80800190: jal         0x8010A624
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A624(rdram, ctx);
        goto after_9;
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800198: jal         0x8010A570
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_10;
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808001A0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1192, 0X11B4) << 16);
    // 0x808001A4: addiu       $a2, $a2, 0x11B4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1192, 0X11B4));
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001AC: jal         0x80089D18
    // 0x808001B0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_11;
    // 0x808001B0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_11:
    // 0x808001B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1192, 0X1084) << 16);
    // 0x808001B8: lwc1        $f8, 0x1084($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1192, 0X1084));
    // 0x808001BC: b           L_8080022C
    // 0x808001C0: swc1        $f8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f8.u32l;
        goto L_8080022C;
    // 0x808001C0: swc1        $f8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f8.u32l;
L_808001C4:
    // 0x808001C4: jal         0x800D8FF8
    // 0x808001C8: nop

    func_800D8FF8(rdram, ctx);
        goto after_12;
    // 0x808001C8: nop

    after_12:
    // 0x808001CC: lwc1        $f10, 0x28($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X28);
    // 0x808001D0: lwc1        $f16, 0x44($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X44);
    // 0x808001D4: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x808001D8: jal         0x800136E4
    // 0x808001DC: add.s       $f12, $f18, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f16.fl;
    func_800136E4(rdram, ctx);
        goto after_13;
    // 0x808001DC: add.s       $f12, $f18, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f16.fl;
    after_13:
    // 0x808001E0: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x808001E4: jal         0x800D9078
    // 0x808001E8: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    func_800D9078(rdram, ctx);
        goto after_14;
    // 0x808001E8: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    after_14:
    // 0x808001EC: beql        $v0, $zero, L_80800200
    if (ctx->r2 == 0) {
        // 0x808001F0: lw          $t8, 0x78($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X78);
            goto L_80800200;
    }
    goto skip_0;
    // 0x808001F0: lw          $t8, 0x78($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X78);
    skip_0:
    // 0x808001F4: jal         0x808002A0
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002A0_chbilldrillplate(rdram, ctx);
        goto after_15;
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808001FC: lw          $t8, 0x78($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X78);
L_80800200:
    // 0x80800200: sll         $t0, $t8, 28
    ctx->r8 = S32(ctx->r24 << 28);
    // 0x80800204: bltzl       $t0, L_80800230
    if (SIGNED(ctx->r8) < 0) {
        // 0x80800208: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800230;
    }
    goto skip_1;
    // 0x80800208: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8080020C: jal         0x80089CA8
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_16;
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800218: jal         0x80101FDC
    // 0x8080021C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_17;
    // 0x8080021C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_17:
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800224: jal         0x80103110
    // 0x80800228: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_18;
    // 0x80800228: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_18:
L_8080022C:
    // 0x8080022C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800230:
    // 0x80800230: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800234: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800238: jr          $ra
    // 0x8080023C: nop

    return;
    // 0x8080023C: nop

;}
RECOMP_FUNC void bashoes_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800974: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800978: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080097C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800980: jal         0x800B53A4
    // 0x80800984: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800B53A4(rdram, ctx);
        goto after_0;
    // 0x80800984: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x80800988: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8080098C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800990: jal         0x80092E2C
    // 0x80800994: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_80092E2C(rdram, ctx);
        goto after_1;
    // 0x80800994: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x80800998: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8080099C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808009A0: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808009A4: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(592, 0XB90) << 16);
    // 0x808009A8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x808009AC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x808009B0: addiu       $t6, $t6, 0xB90
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(592, 0XB90));
    // 0x808009B4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808009B8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808009BC: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x808009C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808009C4: jal         0x800BABB8
    // 0x808009C8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x808009C8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x808009CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808009D0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808009D4: jr          $ra
    // 0x808009D8: nop

    return;
    // 0x808009D8: nop

;}
RECOMP_FUNC void sccustom_banjo_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080044C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800450: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800454: jal         0x800CF6D0
    // 0x80800458: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800CF6D0(rdram, ctx);
        goto after_0;
    // 0x80800458: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080045C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80800460: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80800464: jal         0x8008A610
    // 0x80800468: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _scinfobar_entrypoint_18(rdram, ctx);
        goto after_1;
    // 0x80800468: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8080046C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80800470: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800474: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800478: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8080047C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80800480: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800484: addiu       $t9, $t8, 0x28
    ctx->r25 = ADD32(ctx->r24, 0X28);
    // 0x80800488: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8080048C: nop

    // 0x80800490: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800494: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80800498: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8080049C: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x808004A0: jr          $ra
    // 0x808004A4: nop

    return;
    // 0x808004A4: nop

    // 0x808004A8: nop

    // 0x808004AC: nop

;}
RECOMP_FUNC void func_800F1480(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F1480: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800F1484: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800F1488: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F148C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F1490: mul.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x800F1494: jal         0x80013970
    // 0x800F1498: nop

    func_80013970(rdram, ctx);
        goto after_0;
    // 0x800F1498: nop

    after_0:
    // 0x800F149C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F14A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F14A4: jr          $ra
    // 0x800F14A8: nop

    return;
    // 0x800F14A8: nop

;}
RECOMP_FUNC void func_80800ED8_chnests(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800ED8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800EDC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800EE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800EE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800EE8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800EEC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800EF0: jal         0x80800BD8
    // 0x80800EF4: addiu       $a1, $zero, 0x1CE
    ctx->r5 = ADD32(0, 0X1CE);
    func_80800BD8_chnests(rdram, ctx);
        goto after_0;
    // 0x80800EF4: addiu       $a1, $zero, 0x1CE
    ctx->r5 = ADD32(0, 0X1CE);
    after_0:
    // 0x80800EF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800EFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F00: jr          $ra
    // 0x80800F04: nop

    return;
    // 0x80800F04: nop

;}
RECOMP_FUNC void _bsbfly_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082960: syscall     22
    recomp_syscall_handler(rdram, ctx, 0x80082960);
    return;
    // 0x80082964: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _bssnowball_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083A18: syscall     87
    recomp_syscall_handler(rdram, ctx, 0x80083A18);
    return;
    // 0x80083A1C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8080318C_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080318C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80803190: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803194: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80803198: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080319C: lwc1        $f6, 0x24($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X24);
    // 0x808031A0: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808031A4: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x808031A8: lhu         $a1, 0x72($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X72);
    // 0x808031AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808031B0: srl         $t6, $a1, 10
    ctx->r14 = S32(U32(ctx->r5) >> 10);
    // 0x808031B4: jal         0x8010203C
    // 0x808031B8: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    func_8010203C(rdram, ctx);
        goto after_0;
    // 0x808031B8: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_0:
    // 0x808031BC: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x808031C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808031C4: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x808031C8: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x808031CC: jal         0x80101CDC
    // 0x808031D0: nop

    func_80101CDC(rdram, ctx);
        goto after_1;
    // 0x808031D0: nop

    after_1:
    // 0x808031D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808031D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808031DC: jr          $ra
    // 0x808031E0: nop

    return;
    // 0x808031E0: nop

;}
RECOMP_FUNC void bawobble_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002BC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808002C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808002C4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808002C8: lw          $v0, 0x154($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X154);
    // 0x808002CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808002D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002D4: lbu         $t6, 0xC($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XC);
    // 0x808002D8: bnel        $a1, $t6, L_808003C8
    if (ctx->r5 != ctx->r14) {
        // 0x808002DC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808003C8;
    }
    goto skip_0;
    // 0x808002DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808002E0: lbu         $v1, 0x1C($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X1C);
    // 0x808002E4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808002E8: beq         $v1, $a1, L_80800300
    if (ctx->r3 == ctx->r5) {
        // 0x808002EC: nop
    
            goto L_80800300;
    }
    // 0x808002EC: nop

    // 0x808002F0: beq         $v1, $at, L_80800368
    if (ctx->r3 == ctx->r1) {
        // 0x808002F4: nop
    
            goto L_80800368;
    }
    // 0x808002F4: nop

    // 0x808002F8: b           L_808003BC
    // 0x808002FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808003BC;
    // 0x808002FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800300:
    // 0x80800300: jal         0x800D9078
    // 0x80800304: addiu       $a0, $v0, 0x18
    ctx->r4 = ADD32(ctx->r2, 0X18);
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x80800304: addiu       $a0, $v0, 0x18
    ctx->r4 = ADD32(ctx->r2, 0X18);
    after_0:
    // 0x80800308: lw          $v0, 0x154($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X154);
    // 0x8080030C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800310: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800314: lwc1        $f12, 0x18($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80800318: lw          $a2, 0x10($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X10);
    // 0x8080031C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800320: jal         0x800F10B4
    // 0x80800324: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x80800324: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80800328: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080032C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800330: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800334: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x80800338: nop

    // 0x8080033C: bc1fl       L_808003BC
    if (!c1cs) {
        // 0x80800340: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003BC;
    }
    goto skip_1;
    // 0x80800340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80800344: lw          $t7, 0x154($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X154);
    // 0x80800348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080034C: lbu         $t8, 0x1D($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X1D);
    // 0x80800350: beql        $t8, $zero, L_808003BC
    if (ctx->r24 == 0) {
        // 0x80800354: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003BC;
    }
    goto skip_2;
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80800358: jal         0x80800008
    // 0x8080035C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800008_bawobble(rdram, ctx);
        goto after_2;
    // 0x8080035C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x80800360: b           L_808003BC
    // 0x80800364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808003BC;
    // 0x80800364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800368:
    // 0x80800368: jal         0x800D9078
    // 0x8080036C: addiu       $a0, $v0, 0x18
    ctx->r4 = ADD32(ctx->r2, 0X18);
    func_800D9078(rdram, ctx);
        goto after_3;
    // 0x8080036C: addiu       $a0, $v0, 0x18
    ctx->r4 = ADD32(ctx->r2, 0X18);
    after_3:
    // 0x80800370: lw          $v0, 0x154($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X154);
    // 0x80800374: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800378: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080037C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800380: lwc1        $f12, 0x18($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80800384: lw          $a2, 0x14($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X14);
    // 0x80800388: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8080038C: jal         0x800F10B4
    // 0x80800390: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x80800390: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x80800394: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800398: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8080039C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003A0: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x808003A4: nop

    // 0x808003A8: bc1fl       L_808003BC
    if (!c1cs) {
        // 0x808003AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003BC;
    }
    goto skip_3;
    // 0x808003AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x808003B0: jal         0x8080004C
    // 0x808003B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8080004C_bawobble(rdram, ctx);
        goto after_5;
    // 0x808003B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808003B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808003BC:
    // 0x808003BC: jal         0x808001C0
    // 0x808003C0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_808001C0_bawobble(rdram, ctx);
        goto after_6;
    // 0x808003C0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_6:
    // 0x808003C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808003C8:
    // 0x808003C8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808003CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808003D0: jr          $ra
    // 0x808003D4: nop

    return;
    // 0x808003D4: nop

;}
RECOMP_FUNC void func_800A13B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A13B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A13B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A13B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A13BC: jal         0x80088258
    // 0x800A13C0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _gcsectionDll_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x800A13C0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A13C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A13C8: jal         0x80088260
    // 0x800A13CC: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    _gcsectionDll_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x800A13CC: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    after_1:
    // 0x800A13D0: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A13D4: addiu       $s0, $s0, 0x7090
    ctx->r16 = ADD32(ctx->r16, 0X7090);
    // 0x800A13D8: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // 0x800A13DC: jal         0x800F8B64
    // 0x800A13E0: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
    func_800F8B64(rdram, ctx);
        goto after_2;
    // 0x800A13E0: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
    after_2:
    // 0x800A13E4: beq         $v0, $zero, L_800A13F8
    if (ctx->r2 == 0) {
        // 0x800A13E8: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_800A13F8;
    }
    // 0x800A13E8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800A13EC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800A13F0: sb          $t6, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r14;
    // 0x800A13F4: sb          $t7, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r15;
L_800A13F8:
    // 0x800A13F8: jal         0x800F99E8
    // 0x800A13FC: nop

    func_800F99E8(rdram, ctx);
        goto after_3;
    // 0x800A13FC: nop

    after_3:
    // 0x800A1400: beq         $v0, $zero, L_800A1410
    if (ctx->r2 == 0) {
        // 0x800A1404: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_800A1410;
    }
    // 0x800A1404: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800A1408: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800A140C: sb          $t8, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r24;
L_800A1410:
    // 0x800A1410: sb          $t9, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r25;
    // 0x800A1414: jal         0x80088258
    // 0x800A1418: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _gcsectionDll_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x800A1418: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x800A141C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A1420: jal         0x80088260
    // 0x800A1424: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    _gcsectionDll_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x800A1424: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    after_5:
    // 0x800A1428: beq         $v0, $zero, L_800A1438
    if (ctx->r2 == 0) {
        // 0x800A142C: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_800A1438;
    }
    // 0x800A142C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800A1430: b           L_800A143C
    // 0x800A1434: sb          $t0, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r8;
        goto L_800A143C;
    // 0x800A1434: sb          $t0, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r8;
L_800A1438:
    // 0x800A1438: sb          $zero, 0x5($s0)
    MEM_B(0X5, ctx->r16) = 0;
L_800A143C:
    // 0x800A143C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A1440: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A1444: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A1448: jr          $ra
    // 0x800A144C: nop

    return;
    // 0x800A144C: nop

;}
RECOMP_FUNC void func_800C7150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7150: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C7154: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7158: jal         0x8001BAFC
    // 0x800C715C: nop

    defrag(rdram, ctx);
        goto after_0;
    // 0x800C715C: nop

    after_0:
    // 0x800C7160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C7164: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C7168: jr          $ra
    // 0x800C716C: nop

    return;
    // 0x800C716C: nop

;}
RECOMP_FUNC void func_80800E10_gcnewpause(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800E14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800E1C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800E20: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E24: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800E28: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80800E2C: jal         0x8080105C
    // 0x80800E30: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8080105C_gcnewpause(rdram, ctx);
        goto after_0;
    // 0x80800E30: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80800E34: jal         0x8008FBE0
    // 0x80800E38: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8008FBE0(rdram, ctx);
        goto after_1;
    // 0x80800E38: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80800E3C: jal         0x800CF7F4
    // 0x80800E40: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800CF7F4(rdram, ctx);
        goto after_2;
    // 0x80800E40: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800E44: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E48: beq         $t6, $zero, L_80800E88
    if (ctx->r14 == 0) {
        // 0x80800E4C: nop
    
            goto L_80800E88;
    }
    // 0x80800E4C: nop

    // 0x80800E50: jal         0x800D035C
    // 0x80800E54: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800D035C(rdram, ctx);
        goto after_3;
    // 0x80800E54: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80800E58: addiu       $a0, $zero, 0xD6
    ctx->r4 = ADD32(0, 0XD6);
    // 0x80800E5C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800E60: jal         0x800D2498
    // 0x80800E64: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D2498(rdram, ctx);
        goto after_4;
    // 0x80800E64: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80800E68: jal         0x800D035C
    // 0x80800E6C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_800D035C(rdram, ctx);
        goto after_5;
    // 0x80800E6C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_5:
    // 0x80800E70: addiu       $a0, $zero, 0xD0
    ctx->r4 = ADD32(0, 0XD0);
    // 0x80800E74: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800E78: jal         0x800D2498
    // 0x80800E7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D2498(rdram, ctx);
        goto after_6;
    // 0x80800E7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80800E80: b           L_80800E9C
    // 0x80800E84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800E9C;
    // 0x80800E84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800E88:
    // 0x80800E88: jal         0x800D284C
    // 0x80800E8C: addiu       $a0, $zero, 0xD6
    ctx->r4 = ADD32(0, 0XD6);
    func_800D284C(rdram, ctx);
        goto after_7;
    // 0x80800E8C: addiu       $a0, $zero, 0xD6
    ctx->r4 = ADD32(0, 0XD6);
    after_7:
    // 0x80800E90: jal         0x800D284C
    // 0x80800E94: addiu       $a0, $zero, 0xD0
    ctx->r4 = ADD32(0, 0XD0);
    func_800D284C(rdram, ctx);
        goto after_8;
    // 0x80800E94: addiu       $a0, $zero, 0xD0
    ctx->r4 = ADD32(0, 0XD0);
    after_8:
    // 0x80800E98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800E9C:
    // 0x80800E9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800EA0: jr          $ra
    // 0x80800EA4: nop

    return;
    // 0x80800EA4: nop

;}
RECOMP_FUNC void func_80800990_chbadbeehive(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800990: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800994: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800998: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080099C: lwc1        $f6, 0x58($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X58);
    // 0x808009A0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808009A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808009A8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808009AC: nop

    // 0x808009B0: bc1f        L_808009C0
    if (!c1cs) {
        // 0x808009B4: nop
    
            goto L_808009C0;
    }
    // 0x808009B4: nop

    // 0x808009B8: b           L_80800A0C
    // 0x808009BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800A0C;
    // 0x808009BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808009C0:
    // 0x808009C0: jal         0x80089F78
    // 0x808009C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808009C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x808009C8: beq         $v0, $zero, L_80800A08
    if (ctx->r2 == 0) {
        // 0x808009CC: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80800A08;
    }
    // 0x808009CC: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808009D0: jal         0x8010C9B0
    // 0x808009D4: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    func_8010C9B0(rdram, ctx);
        goto after_1;
    // 0x808009D4: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    after_1:
    // 0x808009D8: beql        $v0, $zero, L_80800A0C
    if (ctx->r2 == 0) {
        // 0x808009DC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800A0C;
    }
    goto skip_0;
    // 0x808009DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x808009E0: jal         0x80089F00
    // 0x808009E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suchase_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x808009E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808009E8: beql        $v0, $zero, L_80800A0C
    if (ctx->r2 == 0) {
        // 0x808009EC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800A0C;
    }
    goto skip_1;
    // 0x808009EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x808009F0: jal         0x8010C500
    // 0x808009F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C500(rdram, ctx);
        goto after_3;
    // 0x808009F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808009F8: beql        $v0, $zero, L_80800A0C
    if (ctx->r2 == 0) {
        // 0x808009FC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800A0C;
    }
    goto skip_2;
    // 0x808009FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x80800A00: b           L_80800A0C
    // 0x80800A04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A0C;
    // 0x80800A04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A08:
    // 0x80800A08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800A0C:
    // 0x80800A0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800A14: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800A18: jr          $ra
    // 0x80800A1C: nop

    return;
    // 0x80800A1C: nop

;}
RECOMP_FUNC void chtransparencypot_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2200, 0X1B0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x1B0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2200, 0X1B0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x1B0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2200, 0X1B0));
;}
RECOMP_FUNC void func_80115428(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115428: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8011542C: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x80115430: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80115434: swc1        $f12, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f12.u32l;
    // 0x80115438: lw          $t7, 0x14($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X14);
    // 0x8011543C: jr          $ra
    // 0x80115440: swc1        $f14, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f14.u32l;
    return;
    // 0x80115440: swc1        $f14, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f14.u32l;
;}
RECOMP_FUNC void func_80800728_chbanjoctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800728: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080072C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800730: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800734: lbu         $v0, 0x30($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X30);
    // 0x80800738: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080073C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800740: beq         $v0, $at, L_80800758
    if (ctx->r2 == ctx->r1) {
        // 0x80800744: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800758;
    }
    // 0x80800744: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800748: beq         $v0, $at, L_80800778
    if (ctx->r2 == ctx->r1) {
        // 0x8080074C: nop
    
            goto L_80800778;
    }
    // 0x8080074C: nop

    // 0x80800750: b           L_808007C8
    // 0x80800754: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808007C8;
    // 0x80800754: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800758:
    // 0x80800758: jal         0x808006A8
    // 0x8080075C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808006A8_chbanjoctrl(rdram, ctx);
        goto after_0;
    // 0x8080075C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800760: beq         $v0, $zero, L_808007C4
    if (ctx->r2 == 0) {
        // 0x80800764: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007C4;
    }
    // 0x80800764: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800768: jal         0x80800638
    // 0x8080076C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800638_chbanjoctrl(rdram, ctx);
        goto after_1;
    // 0x8080076C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80800770: b           L_808007C8
    // 0x80800774: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808007C8;
    // 0x80800774: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800778:
    // 0x80800778: jal         0x800D9078
    // 0x8080077C: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800D9078(rdram, ctx);
        goto after_2;
    // 0x8080077C: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_2:
    // 0x80800780: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800784: lwc1        $f6, 0x28($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80800788: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8080078C: nop

    // 0x80800790: bc1fl       L_808007C8
    if (!c1cs) {
        // 0x80800794: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808007C8;
    }
    goto skip_0;
    // 0x80800794: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800798: jal         0x808006A8
    // 0x8080079C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808006A8_chbanjoctrl(rdram, ctx);
        goto after_3;
    // 0x8080079C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808007A0: beq         $v0, $zero, L_808007BC
    if (ctx->r2 == 0) {
        // 0x808007A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007BC;
    }
    // 0x808007A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007AC: jal         0x80800638
    // 0x808007B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800638_chbanjoctrl(rdram, ctx);
        goto after_4;
    // 0x808007B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x808007B4: b           L_808007C8
    // 0x808007B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808007C8;
    // 0x808007B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808007BC:
    // 0x808007BC: jal         0x80800638
    // 0x808007C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800638_chbanjoctrl(rdram, ctx);
        goto after_5;
    // 0x808007C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
L_808007C4:
    // 0x808007C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808007C8:
    // 0x808007C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808007CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808007D0: jr          $ra
    // 0x808007D4: nop

    return;
    // 0x808007D4: nop

;}
RECOMP_FUNC void func_80800EC8_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EC8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800ECC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800ED0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800ED4: jal         0x8009E6EC
    // 0x80800ED8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x80800ED8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800EDC: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x80800EE0: bne         $v0, $at, L_80800F00
    if (ctx->r2 != ctx->r1) {
        // 0x80800EE4: nop
    
            goto L_80800F00;
    }
    // 0x80800EE4: nop

    // 0x80800EE8: jal         0x80099A4C
    // 0x80800EEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099A4C(rdram, ctx);
        goto after_1;
    // 0x80800EEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800EF0: sw          $v0, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r2;
    // 0x80800EF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EF8: jal         0x8009E5C8
    // 0x80800EFC: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    bs_setState(rdram, ctx);
        goto after_2;
    // 0x80800EFC: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    after_2:
L_80800F00:
    // 0x80800F00: jal         0x80099B94
    // 0x80800F04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099B94(rdram, ctx);
        goto after_3;
    // 0x80800F04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800F08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800F0C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800F10: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800F14: jr          $ra
    // 0x80800F18: nop

    return;
    // 0x80800F18: nop

;}
RECOMP_FUNC void func_80801500_chhoopswoop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801500: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801504: addiu       $at, $zero, 0x10CD
    ctx->r1 = ADD32(0, 0X10CD);
    // 0x80801508: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080150C: bne         $a1, $at, L_80801528
    if (ctx->r5 != ctx->r1) {
        // 0x80801510: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80801528;
    }
    // 0x80801510: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80801514: jal         0x80100094
    // 0x80801518: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801518: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080151C: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x80801520: b           L_8080152C
    // 0x80801524: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_8080152C;
    // 0x80801524: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80801528:
    // 0x80801528: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080152C:
    // 0x8080152C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801530: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801534: jr          $ra
    // 0x80801538: nop

    return;
    // 0x80801538: nop

;}
RECOMP_FUNC void chattract_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003B0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x808003B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003B8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x808003BC: jal         0x80086D30
    // 0x808003C0: addiu       $a0, $a0, 0x5C08
    ctx->r4 = ADD32(ctx->r4, 0X5C08);
    _chbaddiesetup_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808003C0: addiu       $a0, $a0, 0x5C08
    ctx->r4 = ADD32(ctx->r4, 0X5C08);
    after_0:
    // 0x808003C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003CC: jr          $ra
    // 0x808003D0: nop

    return;
    // 0x808003D0: nop

;}
RECOMP_FUNC void func_800CBD84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CBD84: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CBD88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CBD8C: jal         0x800CBC3C
    // 0x800CBD90: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800CBC3C(rdram, ctx);
        goto after_0;
    // 0x800CBD90: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x800CBD94: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800CBD98: beq         $v0, $at, L_800CBDC0
    if (ctx->r2 == ctx->r1) {
        // 0x800CBD9C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800CBDC0;
    }
    // 0x800CBD9C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800CBDA0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800CBDA4: jal         0x800CC4D4
    // 0x800CBDA8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800CC4D4(rdram, ctx);
        goto after_1;
    // 0x800CBDA8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x800CBDAC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800CBDB0: beq         $v0, $at, L_800CBDC0
    if (ctx->r2 == ctx->r1) {
        // 0x800CBDB4: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_800CBDC0;
    }
    // 0x800CBDB4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800CBDB8: b           L_800CBDC4
    // 0x800CBDBC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800CBDC4;
    // 0x800CBDBC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800CBDC0:
    // 0x800CBDC0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_800CBDC4:
    // 0x800CBDC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CBDC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CBDCC: jr          $ra
    // 0x800CBDD0: nop

    return;
    // 0x800CBDD0: nop

;}
RECOMP_FUNC void func_8008FF40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FF40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FF44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FF48: jal         0x800F54E4
    // 0x8008FF4C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8008FF4C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008FF50: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008FF54: jal         0x800F5B38
    // 0x8008FF58: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800F5B38(rdram, ctx);
        goto after_1;
    // 0x8008FF58: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8008FF5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008FF60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FF64: jr          $ra
    // 0x8008FF68: nop

    return;
    // 0x8008FF68: nop

;}
RECOMP_FUNC void subaddietaxi_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080033C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800340: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800344: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800348: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8080034C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800350: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800354: jal         0x800EA05C
    // 0x80800358: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800358: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8080035C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800360: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80800364: addiu       $s4, $zero, 0x10
    ctx->r20 = ADD32(0, 0X10);
    // 0x80800368: addiu       $s2, $sp, 0x34
    ctx->r18 = ADD32(ctx->r29, 0X34);
    // 0x8080036C: addiu       $s1, $sp, 0x44
    ctx->r17 = ADD32(ctx->r29, 0X44);
L_80800370:
    // 0x80800370: jal         0x800CB3E0
    // 0x80800374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800CB3E0(rdram, ctx);
        goto after_1;
    // 0x80800374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800378: sltiu       $at, $v0, 0x7
    ctx->r1 = ctx->r2 < 0X7 ? 1 : 0;
    // 0x8080037C: beq         $at, $zero, L_80800440
    if (ctx->r1 == 0) {
        // 0x80800380: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_80800440;
    }
    // 0x80800380: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80800384: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3334, 0XD18) << 16);
    // 0x80800388: addu        $at, $at, $t6
    gpr jr_addend_80800390 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8080038C: lw          $t6, 0xD18($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(3334, 0XD18));
    // 0x80800390: jr          $t6
    // 0x80800394: nop

    switch (jr_addend_80800390 >> 2) {
        case 0: goto L_80800440; break;
        case 1: goto L_80800398; break;
        case 2: goto L_80800440; break;
        case 3: goto L_80800440; break;
        case 4: goto L_80800440; break;
        case 5: goto L_808003CC; break;
        case 6: goto L_80800414; break;
        default: switch_error(__func__, 0x80800390, 0x80800D18);
    }
    // 0x80800394: nop

L_80800398:
    // 0x80800398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080039C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808003A0: jal         0x800CB3FC
    // 0x808003A4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_800CB3FC(rdram, ctx);
        goto after_2;
    // 0x808003A4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_2:
    // 0x808003A8: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x808003AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003B0: bnel        $t7, $s3, L_80800444
    if (ctx->r15 != ctx->r19) {
        // 0x808003B4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80800444;
    }
    goto skip_0;
    // 0x808003B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x808003B8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808003BC: jal         0x800CB534
    // 0x808003C0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800CB534(rdram, ctx);
        goto after_3;
    // 0x808003C0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x808003C4: b           L_80800444
    // 0x808003C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_80800444;
    // 0x808003C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_808003CC:
    // 0x808003CC: jal         0x800CB70C
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800CB70C(rdram, ctx);
        goto after_4;
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808003D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003D8: jal         0x800CB698
    // 0x808003DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800CB698(rdram, ctx);
        goto after_5;
    // 0x808003DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808003E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003E4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808003E8: jal         0x800CB3FC
    // 0x808003EC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_800CB3FC(rdram, ctx);
        goto after_6;
    // 0x808003EC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_6:
    // 0x808003F0: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003F8: bnel        $t8, $s3, L_80800444
    if (ctx->r24 != ctx->r19) {
        // 0x808003FC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80800444;
    }
    goto skip_1;
    // 0x808003FC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x80800400: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800404: jal         0x800CB534
    // 0x80800408: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800CB534(rdram, ctx);
        goto after_7;
    // 0x80800408: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x8080040C: b           L_80800444
    // 0x80800410: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_80800444;
    // 0x80800410: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80800414:
    // 0x80800414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800418: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8080041C: jal         0x800CB3FC
    // 0x80800420: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_800CB3FC(rdram, ctx);
        goto after_8;
    // 0x80800420: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_8:
    // 0x80800424: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080042C: bnel        $t9, $s3, L_80800444
    if (ctx->r25 != ctx->r19) {
        // 0x80800430: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80800444;
    }
    goto skip_2;
    // 0x80800430: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_2:
    // 0x80800434: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800438: jal         0x800CB534
    // 0x8080043C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800CB534(rdram, ctx);
        goto after_9;
    // 0x8080043C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_9:
L_80800440:
    // 0x80800440: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80800444:
    // 0x80800444: bne         $s0, $s4, L_80800370
    if (ctx->r16 != ctx->r20) {
        // 0x80800448: nop
    
            goto L_80800370;
    }
    // 0x80800448: nop

    // 0x8080044C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800450: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800454: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800458: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8080045C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80800460: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800464: jr          $ra
    // 0x80800468: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80800468: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80800000_chcauldronentrydoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080000C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800010: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800014: jal         0x80100094
    // 0x80800018: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800018: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8080001C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800020: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800024: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800028: jal         0x800868A0
    // 0x8080002C: addiu       $a2, $zero, 0x58E
    ctx->r6 = ADD32(0, 0X58E);
    _chdoormake_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x8080002C: addiu       $a2, $zero, 0x58E
    ctx->r6 = ADD32(0, 0X58E);
    after_1:
    // 0x80800030: beq         $v0, $zero, L_8080006C
    if (ctx->r2 == 0) {
        // 0x80800034: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080006C;
    }
    // 0x80800034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800038: jal         0x800868A8
    // 0x8080003C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x8080003C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_2:
    // 0x80800040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800044: jal         0x800868B0
    // 0x80800048: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    _chdoormake_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x80800048: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_3:
    // 0x8080004C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800050: jal         0x800868C0
    // 0x80800054: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_4;
    // 0x80800054: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_4:
    // 0x80800058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080005C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800060: addiu       $a2, $zero, 0x56
    ctx->r6 = ADD32(0, 0X56);
    // 0x80800064: jal         0x800868C8
    // 0x80800068: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    _chdoormake_entrypoint_9(rdram, ctx);
        goto after_5;
    // 0x80800068: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    after_5:
L_8080006C:
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800070: jal         0x8010A800
    // 0x80800074: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8010A800(rdram, ctx);
        goto after_6;
    // 0x80800074: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080007C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800080: jal         0x80104004
    // 0x80800084: addiu       $a2, $s1, 0xC
    ctx->r6 = ADD32(ctx->r17, 0XC);
    func_80104004(rdram, ctx);
        goto after_7;
    // 0x80800084: addiu       $a2, $s1, 0xC
    ctx->r6 = ADD32(ctx->r17, 0XC);
    after_7:
    // 0x80800088: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8080008C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800090: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80800094: addiu       $a0, $zero, 0x5B
    ctx->r4 = ADD32(0, 0X5B);
    // 0x80800098: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8080009C: jal         0x80088840
    // 0x808000A0: swc1        $f8, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f8.u32l;
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_8;
    // 0x808000A0: swc1        $f8, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f8.u32l;
    after_8:
    // 0x808000A4: beql        $v0, $zero, L_808000B8
    if (ctx->r2 == 0) {
        // 0x808000A8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808000B8;
    }
    goto skip_0;
    // 0x808000A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808000AC: jal         0x800FFAB0
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_9;
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808000B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000B8:
    // 0x808000B8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808000BC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808000C0: jr          $ra
    // 0x808000C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808000C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void plsu_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800184: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800188: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080018C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800190: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800194: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800198: jal         0x800F5898
    // 0x8080019C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    func_800F5898(rdram, ctx);
        goto after_0;
    // 0x8080019C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_0:
    // 0x808001A0: blezl       $v0, L_808001F8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808001A4: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_808001F8;
    }
    goto skip_0;
    // 0x808001A4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_0:
L_808001A8:
    // 0x808001A8: jal         0x800F6BE4
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6BE4(rdram, ctx);
        goto after_1;
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808001B0: beq         $v0, $zero, L_808001E0
    if (ctx->r2 == 0) {
        // 0x808001B4: nop
    
            goto L_808001E0;
    }
    // 0x808001B4: nop

    // 0x808001B8: jal         0x800F6C5C
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6C5C(rdram, ctx);
        goto after_2;
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808001C0: beq         $v0, $zero, L_808001E0
    if (ctx->r2 == 0) {
        // 0x808001C4: nop
    
            goto L_808001E0;
    }
    // 0x808001C4: nop

    // 0x808001C8: jal         0x800F55D0
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F55D0(rdram, ctx);
        goto after_3;
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808001D0: bne         $v0, $s1, L_808001E0
    if (ctx->r2 != ctx->r17) {
        // 0x808001D4: nop
    
            goto L_808001E0;
    }
    // 0x808001D4: nop

    // 0x808001D8: b           L_808001F8
    // 0x808001DC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_808001F8;
    // 0x808001DC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_808001E0:
    // 0x808001E0: jal         0x800F5898
    // 0x808001E4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    func_800F5898(rdram, ctx);
        goto after_4;
    // 0x808001E4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_4:
    // 0x808001E8: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808001EC: bne         $at, $zero, L_808001A8
    if (ctx->r1 != 0) {
        // 0x808001F0: nop
    
            goto L_808001A8;
    }
    // 0x808001F0: nop

    // 0x808001F4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_808001F8:
    // 0x808001F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001FC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800200: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800204: jr          $ra
    // 0x80800208: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800208: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080020C: nop

;}
RECOMP_FUNC void func_800F4354(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F4354: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800F4358: addiu       $t7, $t7, 0x35D0
    ctx->r15 = ADD32(ctx->r15, 0X35D0);
    // 0x800F435C: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800F4360: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800F4364: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800F4368: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F436C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F4370: bltzl       $a1, L_800F4384
    if (SIGNED(ctx->r5) < 0) {
        // 0x800F4374: lw          $t9, 0x4($v1)
        ctx->r25 = MEM_W(ctx->r3, 0X4);
            goto L_800F4384;
    }
    goto skip_0;
    // 0x800F4374: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    skip_0:
    // 0x800F4378: b           L_800F4398
    // 0x800F437C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_800F4398;
    // 0x800F437C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800F4380: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
L_800F4384:
    // 0x800F4384: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x800F4388: jalr        $t9
    // 0x800F438C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800F438C: nop

    after_0:
    // 0x800F4390: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800F4394: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_800F4398:
    // 0x800F4398: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F439C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F43A0: jr          $ra
    // 0x800F43A4: nop

    return;
    // 0x800F43A4: nop

;}
RECOMP_FUNC void func_80800028_chhumba(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800028: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080002C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800030: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800034: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800038: lhu         $v0, 0x76($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X76);
    // 0x8080003C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800040: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800044: srl         $t6, $v0, 7
    ctx->r14 = S32(U32(ctx->r2) >> 7);
    // 0x80800048: beq         $t6, $zero, L_80800074
    if (ctx->r14 == 0) {
        // 0x8080004C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800074;
    }
    // 0x8080004C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800050: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800054: beq         $t6, $at, L_80800080
    if (ctx->r14 == ctx->r1) {
        // 0x80800058: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800080;
    }
    // 0x80800058: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080005C: beq         $t6, $at, L_808000B8
    if (ctx->r14 == ctx->r1) {
        // 0x80800060: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808000B8;
    }
    // 0x80800060: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800064: beql        $t6, $at, L_80800084
    if (ctx->r14 == ctx->r1) {
        // 0x80800068: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80800084;
    }
    goto skip_0;
    // 0x80800068: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    skip_0:
    // 0x8080006C: b           L_808000C8
    // 0x80800070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808000C8;
    // 0x80800070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800074:
    // 0x80800074: jal         0x80800000
    // 0x80800078: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80800000_chhumba(rdram, ctx);
        goto after_0;
    // 0x80800078: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x8080007C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_80800080:
    // 0x80800080: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80800084:
    // 0x80800084: jal         0x800856E0
    // 0x80800088: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    _capod_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800088: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x8080008C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80800090: lhu         $t7, 0x76($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X76);
    // 0x80800094: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80800098: andi        $t8, $t7, 0x7F
    ctx->r24 = ctx->r15 & 0X7F;
    // 0x8080009C: ori         $t9, $t8, 0x100
    ctx->r25 = ctx->r24 | 0X100;
    // 0x808000A0: jal         0x800880A8
    // 0x808000A4: sh          $t9, 0x76($a3)
    MEM_H(0X76, ctx->r7) = ctx->r25;
    _gcdialogcamera_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x808000A4: sh          $t9, 0x76($a3)
    MEM_H(0X76, ctx->r7) = ctx->r25;
    after_2:
    // 0x808000A8: jal         0x800880B8
    // 0x808000AC: nop

    _gcdialogcamera_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x808000AC: nop

    after_3:
    // 0x808000B0: jal         0x80085700
    // 0x808000B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _capod_entrypoint_12(rdram, ctx);
        goto after_4;
    // 0x808000B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
L_808000B8:
    // 0x808000B8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808000BC: jal         0x800856D8
    // 0x808000C0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _capod_entrypoint_7(rdram, ctx);
        goto after_5;
    // 0x808000C0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_5:
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
RECOMP_FUNC void _suquiz_entrypoint_25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A880: syscall     853
    recomp_syscall_handler(rdram, ctx, 0x8008A880);
    return;
    // 0x8008A884: addi        $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
;}
RECOMP_FUNC void _basudie_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085208: syscall     155
    recomp_syscall_handler(rdram, ctx, 0x80085208);
    return;
    // 0x8008520C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _gcnewoption_entrypoint_37(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087DC0: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087DC0);
    return;
    // 0x80087DC4: addi        $t0, $zero, 0x94
    ctx->r8 = ADD32(0, 0X94);
;}
RECOMP_FUNC void _chboggykidshome_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800866E8: syscall     355
    recomp_syscall_handler(rdram, ctx, 0x800866E8);
    return;
    // 0x800866EC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void freelist_at(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B301C: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x800B3020: multu       $a1, $t6
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B3024: mflo        $t7
    ctx->r15 = lo;
    // 0x800B3028: addu        $v0, $a0, $t7
    ctx->r2 = ADD32(ctx->r4, ctx->r15);
    // 0x800B302C: jr          $ra
    // 0x800B3030: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x800B3030: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
;}
RECOMP_FUNC void func_808010DC_chmayafarmer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808010E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808010E4: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1612, 0X12E8) << 16);
    // 0x808010E8: addiu       $a3, $a3, 0x12E8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1612, 0X12E8));
    // 0x808010EC: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x808010F0: jal         0x80089D50
    // 0x808010F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808010F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x808010F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808010FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801100: jr          $ra
    // 0x80801104: nop

    return;
    // 0x80801104: nop

;}
RECOMP_FUNC void rtlight_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800630: addiu       $sp, $sp, -0xF8
    ctx->r29 = ADD32(ctx->r29, -0XF8);
    // 0x80800634: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80800638: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8080063C: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80800640: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80800644: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80800648: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8080064C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80800650: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80800654: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80800658: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8080065C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800660: sw          $a1, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r5;
    // 0x80800664: sw          $a2, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r6;
    // 0x80800668: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x8080066C: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80800670: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80800674: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x80800678: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x8080067C: addiu       $t9, $t8, 0xC
    ctx->r25 = ADD32(ctx->r24, 0XC);
    // 0x80800680: sw          $t9, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r25;
    // 0x80800684: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800688: jal         0x800C8760
    // 0x8080068C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800C8760(rdram, ctx);
        goto after_0;
    // 0x8080068C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80800690: beq         $v0, $zero, L_808007B8
    if (ctx->r2 == 0) {
        // 0x80800694: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_808007B8;
    }
    // 0x80800694: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800698: addiu       $s2, $s5, 0xC
    ctx->r18 = ADD32(ctx->r21, 0XC);
    // 0x8080069C: addiu       $fp, $sp, 0xC4
    ctx->r30 = ADD32(ctx->r29, 0XC4);
    // 0x808006A0: addiu       $s7, $sp, 0xC8
    ctx->r23 = ADD32(ctx->r29, 0XC8);
    // 0x808006A4: addiu       $s6, $sp, 0xCC
    ctx->r22 = ADD32(ctx->r29, 0XCC);
    // 0x808006A8: addiu       $s4, $sp, 0xD4
    ctx->r20 = ADD32(ctx->r29, 0XD4);
    // 0x808006AC: addiu       $s3, $zero, 0xF
    ctx->r19 = ADD32(0, 0XF);
L_808006B0:
    // 0x808006B0: lw          $a2, 0xE8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XE8);
    // 0x808006B4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x808006B8: sltu        $at, $s2, $a2
    ctx->r1 = ctx->r18 < ctx->r6 ? 1 : 0;
    // 0x808006BC: beql        $at, $zero, L_80800710
    if (ctx->r1 == 0) {
        // 0x808006C0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800710;
    }
    goto skip_0;
    // 0x808006C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x808006C4: lb          $t0, 0xF($a1)
    ctx->r8 = MEM_B(ctx->r5, 0XF);
L_808006C8:
    // 0x808006C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808006CC: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x808006D0: bltzl       $t0, L_80800700
    if (SIGNED(ctx->r8) < 0) {
        // 0x808006D4: addiu       $a1, $a1, 0x20
        ctx->r5 = ADD32(ctx->r5, 0X20);
            goto L_80800700;
    }
    goto skip_1;
    // 0x808006D4: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    skip_1:
L_808006D8:
    // 0x808006D8: lbu         $t1, 0x0($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X0);
    // 0x808006DC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x808006E0: bne         $v0, $t1, L_808006F4
    if (ctx->r2 != ctx->r9) {
        // 0x808006E4: nop
    
            goto L_808006F4;
    }
    // 0x808006E4: nop

    // 0x808006E8: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x808006EC: b           L_808006FC
    // 0x808006F0: sb          $s0, 0xF($a1)
    MEM_B(0XF, ctx->r5) = ctx->r16;
        goto L_808006FC;
    // 0x808006F0: sb          $s0, 0xF($a1)
    MEM_B(0XF, ctx->r5) = ctx->r16;
L_808006F4:
    // 0x808006F4: bne         $a0, $s3, L_808006D8
    if (ctx->r4 != ctx->r19) {
        // 0x808006F8: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_808006D8;
    }
    // 0x808006F8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_808006FC:
    // 0x808006FC: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
L_80800700:
    // 0x80800700: sltu        $at, $a1, $a2
    ctx->r1 = ctx->r5 < ctx->r6 ? 1 : 0;
    // 0x80800704: bnel        $at, $zero, L_808006C8
    if (ctx->r1 != 0) {
        // 0x80800708: lb          $t0, 0xF($a1)
        ctx->r8 = MEM_B(ctx->r5, 0XF);
            goto L_808006C8;
    }
    goto skip_2;
    // 0x80800708: lb          $t0, 0xF($a1)
    ctx->r8 = MEM_B(ctx->r5, 0XF);
    skip_2:
    // 0x8080070C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80800710:
    // 0x80800710: jal         0x800C8800
    // 0x80800714: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800C8800(rdram, ctx);
        goto after_1;
    // 0x80800714: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_1:
    // 0x80800718: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080071C: jal         0x800C883C
    // 0x80800720: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_800C883C(rdram, ctx);
        goto after_2;
    // 0x80800720: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_2:
    // 0x80800724: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800728: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8080072C: lw          $a2, 0xD0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XD0);
    // 0x80800730: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x80800734: jal         0x8080036C
    // 0x80800738: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    func_8080036C_rtlight(rdram, ctx);
        goto after_3;
    // 0x80800738: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    after_3:
    // 0x8080073C: lw          $t2, 0xC8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC8);
    // 0x80800740: lw          $t3, 0xC4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC4);
    // 0x80800744: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800748: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080074C: sltu        $at, $t2, $t3
    ctx->r1 = ctx->r10 < ctx->r11 ? 1 : 0;
    // 0x80800750: beq         $at, $zero, L_808007A8
    if (ctx->r1 == 0) {
        // 0x80800754: nop
    
            goto L_808007A8;
    }
    // 0x80800754: nop

L_80800758:
    // 0x80800758: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x8080075C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800760: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
L_80800764:
    // 0x80800764: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    // 0x80800768: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8080076C: bne         $t5, $zero, L_80800788
    if (ctx->r13 != 0) {
        // 0x80800770: nop
    
            goto L_80800788;
    }
    // 0x80800770: nop

    // 0x80800774: sb          $s1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r17;
    // 0x80800778: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x8080077C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80800780: b           L_80800790
    // 0x80800784: sb          $s0, 0xF($t7)
    MEM_B(0XF, ctx->r15) = ctx->r16;
        goto L_80800790;
    // 0x80800784: sb          $s0, 0xF($t7)
    MEM_B(0XF, ctx->r15) = ctx->r16;
L_80800788:
    // 0x80800788: bne         $v1, $s3, L_80800764
    if (ctx->r3 != ctx->r19) {
        // 0x8080078C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80800764;
    }
    // 0x8080078C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80800790:
    // 0x80800790: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x80800794: lw          $t0, 0xC4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC4);
    // 0x80800798: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x8080079C: sltu        $at, $t9, $t0
    ctx->r1 = ctx->r25 < ctx->r8 ? 1 : 0;
    // 0x808007A0: bne         $at, $zero, L_80800758
    if (ctx->r1 != 0) {
        // 0x808007A4: sw          $t9, 0xC8($sp)
        MEM_W(0XC8, ctx->r29) = ctx->r25;
            goto L_80800758;
    }
    // 0x808007A4: sw          $t9, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r25;
L_808007A8:
    // 0x808007A8: jal         0x800C878C
    // 0x808007AC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800C878C(rdram, ctx);
        goto after_4;
    // 0x808007AC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_4:
    // 0x808007B0: bne         $v0, $zero, L_808006B0
    if (ctx->r2 != 0) {
        // 0x808007B4: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_808006B0;
    }
    // 0x808007B4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_808007B8:
    // 0x808007B8: addiu       $s2, $s5, 0xC
    ctx->r18 = ADD32(ctx->r21, 0XC);
    // 0x808007BC: addiu       $s3, $zero, 0xF
    ctx->r19 = ADD32(0, 0XF);
    // 0x808007C0: sw          $s2, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r18;
    // 0x808007C4: jal         0x800B2190
    // 0x808007C8: lw          $a0, 0xFC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XFC);
    func_800B2190(rdram, ctx);
        goto after_5;
    // 0x808007C8: lw          $a0, 0xFC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XFC);
    after_5:
    // 0x808007CC: lw          $t1, 0xE8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XE8);
    // 0x808007D0: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x808007D4: lui         $fp, 0x1
    ctx->r30 = S32(0X1 << 16);
    // 0x808007D8: sltu        $at, $s2, $t1
    ctx->r1 = ctx->r18 < ctx->r9 ? 1 : 0;
    // 0x808007DC: beq         $at, $zero, L_80800AEC
    if (ctx->r1 == 0) {
        // 0x808007E0: addiu       $s7, $zero, 0x4000
        ctx->r23 = ADD32(0, 0X4000);
            goto L_80800AEC;
    }
    // 0x808007E0: addiu       $s7, $zero, 0x4000
    ctx->r23 = ADD32(0, 0X4000);
    // 0x808007E4: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x808007E8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x808007EC: lw          $v0, 0xEC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XEC);
    // 0x808007F0: lb          $t2, 0xF($v0)
    ctx->r10 = MEM_B(ctx->r2, 0XF);
L_808007F4:
    // 0x808007F4: addiu       $a0, $v0, 0x10
    ctx->r4 = ADD32(ctx->r2, 0X10);
    // 0x808007F8: addiu       $a1, $v0, 0x16
    ctx->r5 = ADD32(ctx->r2, 0X16);
    // 0x808007FC: blezl       $t2, L_80800AD8
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80800800: lw          $t9, 0xE8($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XE8);
            goto L_80800AD8;
    }
    goto skip_3;
    // 0x80800800: lw          $t9, 0xE8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE8);
    skip_3:
    // 0x80800804: jal         0x800E3DC0
    // 0x80800808: sw          $v0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r2;
    func_800E3DC0(rdram, ctx);
        goto after_6;
    // 0x80800808: sw          $v0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r2;
    after_6:
    // 0x8080080C: bne         $v0, $zero, L_8080081C
    if (ctx->r2 != 0) {
        // 0x80800810: or          $s6, $zero, $zero
        ctx->r22 = 0 | 0;
            goto L_8080081C;
    }
    // 0x80800810: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x80800814: b           L_80800AD4
    // 0x80800818: lw          $v0, 0xEC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XEC);
        goto L_80800AD4;
    // 0x80800818: lw          $v0, 0xEC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XEC);
L_8080081C:
    // 0x8080081C: lw          $s4, 0xEC($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XEC);
L_80800820:
    // 0x80800820: lbu         $t3, 0x0($s4)
    ctx->r11 = MEM_BU(ctx->r20, 0X0);
    // 0x80800824: bnel        $t3, $zero, L_8080083C
    if (ctx->r11 != 0) {
        // 0x80800828: lw          $t4, 0xEC($sp)
        ctx->r12 = MEM_W(ctx->r29, 0XEC);
            goto L_8080083C;
    }
    goto skip_4;
    // 0x80800828: lw          $t4, 0xEC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XEC);
    skip_4:
    // 0x8080082C: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x80800830: bne         $s6, $s3, L_80800820
    if (ctx->r22 != ctx->r19) {
        // 0x80800834: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_80800820;
    }
    // 0x80800834: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80800838: lw          $t4, 0xEC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XEC);
L_8080083C:
    // 0x8080083C: lw          $t7, 0xE8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE8);
    // 0x80800840: lh          $t5, 0x1C($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X1C);
    // 0x80800844: lh          $t8, 0x1E($t4)
    ctx->r24 = MEM_H(ctx->r12, 0X1E);
    // 0x80800848: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8080084C: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80800850: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80800854: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800858: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8080085C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80800860: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
    // 0x80800864: bne         $s6, $s3, L_808008B0
    if (ctx->r22 != ctx->r19) {
        // 0x80800868: addu        $s2, $t9, $s1
        ctx->r18 = ADD32(ctx->r25, ctx->r17);
            goto L_808008B0;
    }
    // 0x80800868: addu        $s2, $t9, $s1
    ctx->r18 = ADD32(ctx->r25, ctx->r17);
    // 0x8080086C: sltu        $at, $s1, $s2
    ctx->r1 = ctx->r17 < ctx->r18 ? 1 : 0;
    // 0x80800870: beql        $at, $zero, L_80800AC8
    if (ctx->r1 == 0) {
        // 0x80800874: lw          $v0, 0xEC($sp)
        ctx->r2 = MEM_W(ctx->r29, 0XEC);
            goto L_80800AC8;
    }
    goto skip_5;
    // 0x80800874: lw          $v0, 0xEC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XEC);
    skip_5:
L_80800878:
    // 0x80800878: lh          $t0, 0x6($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X6);
    // 0x8080087C: lbu         $t2, 0x8($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X8);
    // 0x80800880: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x80800884: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x80800888: addu        $v0, $t1, $s5
    ctx->r2 = ADD32(ctx->r9, ctx->r21);
    // 0x8080088C: sb          $t2, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r10;
    // 0x80800890: lbu         $t3, -0x3($s1)
    ctx->r11 = MEM_BU(ctx->r17, -0X3);
    // 0x80800894: sltu        $at, $s1, $s2
    ctx->r1 = ctx->r17 < ctx->r18 ? 1 : 0;
    // 0x80800898: sb          $t3, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r11;
    // 0x8080089C: lbu         $t5, -0x2($s1)
    ctx->r13 = MEM_BU(ctx->r17, -0X2);
    // 0x808008A0: bne         $at, $zero, L_80800878
    if (ctx->r1 != 0) {
        // 0x808008A4: sb          $t5, 0xE($v0)
        MEM_B(0XE, ctx->r2) = ctx->r13;
            goto L_80800878;
    }
    // 0x808008A4: sb          $t5, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r13;
    // 0x808008A8: b           L_80800AC8
    // 0x808008AC: lw          $v0, 0xEC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XEC);
        goto L_80800AC8;
    // 0x808008AC: lw          $v0, 0xEC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XEC);
L_808008B0:
    // 0x808008B0: sltu        $at, $s1, $s2
    ctx->r1 = ctx->r17 < ctx->r18 ? 1 : 0;
    // 0x808008B4: beq         $at, $zero, L_808008E0
    if (ctx->r1 == 0) {
        // 0x808008B8: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_808008E0;
    }
    // 0x808008B8: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_808008BC:
    // 0x808008BC: lbu         $t6, 0x8($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X8);
    // 0x808008C0: lbu         $t7, 0x9($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X9);
    // 0x808008C4: lbu         $t4, 0xA($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0XA);
    // 0x808008C8: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x808008CC: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x808008D0: sh          $t6, -0xC($s0)
    MEM_H(-0XC, ctx->r16) = ctx->r14;
    // 0x808008D4: sh          $t7, -0xA($s0)
    MEM_H(-0XA, ctx->r16) = ctx->r15;
    // 0x808008D8: bne         $at, $zero, L_808008BC
    if (ctx->r1 != 0) {
        // 0x808008DC: sh          $t4, -0x8($s0)
        MEM_H(-0X8, ctx->r16) = ctx->r12;
            goto L_808008BC;
    }
    // 0x808008DC: sh          $t4, -0x8($s0)
    MEM_H(-0X8, ctx->r16) = ctx->r12;
L_808008E0:
    // 0x808008E0: slti        $at, $s6, 0xF
    ctx->r1 = SIGNED(ctx->r22) < 0XF ? 1 : 0;
    // 0x808008E4: beql        $at, $zero, L_80800A60
    if (ctx->r1 == 0) {
        // 0x808008E8: sltu        $at, $s1, $s2
        ctx->r1 = ctx->r17 < ctx->r18 ? 1 : 0;
            goto L_80800A60;
    }
    goto skip_6;
    // 0x808008E8: sltu        $at, $s1, $s2
    ctx->r1 = ctx->r17 < ctx->r18 ? 1 : 0;
    skip_6:
L_808008EC:
    // 0x808008EC: lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X0);
    // 0x808008F0: addiu       $a1, $sp, 0x9C
    ctx->r5 = ADD32(ctx->r29, 0X9C);
    // 0x808008F4: beq         $v0, $zero, L_80800A4C
    if (ctx->r2 == 0) {
        // 0x808008F8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800A4C;
    }
    // 0x808008F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808008FC: jal         0x80800544
    // 0x80800900: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    func_80800544_rtlight(rdram, ctx);
        goto after_7;
    // 0x80800900: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    after_7:
    // 0x80800904: lbu         $a0, 0x0($s4)
    ctx->r4 = MEM_BU(ctx->r20, 0X0);
    // 0x80800908: jal         0x808005AC
    // 0x8080090C: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    func_808005AC_rtlight(rdram, ctx);
        goto after_8;
    // 0x8080090C: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    after_8:
    // 0x80800910: lbu         $a0, 0x0($s4)
    ctx->r4 = MEM_BU(ctx->r20, 0X0);
    // 0x80800914: jal         0x800C8900
    // 0x80800918: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    func_800C8900(rdram, ctx);
        goto after_9;
    // 0x80800918: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    after_9:
    // 0x8080091C: sltu        $at, $s1, $s2
    ctx->r1 = ctx->r17 < ctx->r18 ? 1 : 0;
    // 0x80800920: beql        $at, $zero, L_80800A50
    if (ctx->r1 == 0) {
        // 0x80800924: addiu       $s6, $s6, 0x1
        ctx->r22 = ADD32(ctx->r22, 0X1);
            goto L_80800A50;
    }
    goto skip_7;
    // 0x80800924: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    skip_7:
    // 0x80800928: lh          $t8, 0x6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X6);
L_8080092C:
    // 0x8080092C: lw          $t0, 0x9C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X9C);
    // 0x80800930: lw          $t2, 0xA0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA0);
    // 0x80800934: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80800938: addu        $v0, $t9, $s5
    ctx->r2 = ADD32(ctx->r25, ctx->r21);
    // 0x8080093C: lh          $t1, 0x0($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X0);
    // 0x80800940: lh          $t3, 0x2($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X2);
    // 0x80800944: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x80800948: subu        $v1, $t0, $t1
    ctx->r3 = SUB32(ctx->r8, ctx->r9);
    // 0x8080094C: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800950: subu        $a0, $t2, $t3
    ctx->r4 = SUB32(ctx->r10, ctx->r11);
    // 0x80800954: lw          $t5, 0xA4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA4);
    // 0x80800958: lw          $t0, 0x94($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X94);
    // 0x8080095C: subu        $a1, $t5, $t6
    ctx->r5 = SUB32(ctx->r13, ctx->r14);
    // 0x80800960: mflo        $t7
    ctx->r15 = lo;
    // 0x80800964: nop

    // 0x80800968: nop

    // 0x8080096C: multu       $a0, $a0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800970: mflo        $t4
    ctx->r12 = lo;
    // 0x80800974: addu        $t8, $t7, $t4
    ctx->r24 = ADD32(ctx->r15, ctx->r12);
    // 0x80800978: nop

    // 0x8080097C: multu       $a1, $a1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800980: mflo        $t9
    ctx->r25 = lo;
    // 0x80800984: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    // 0x80800988: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8080098C: beq         $at, $zero, L_80800A3C
    if (ctx->r1 == 0) {
        // 0x80800990: or          $a3, $a2, $zero
        ctx->r7 = ctx->r6 | 0;
            goto L_80800A3C;
    }
    // 0x80800990: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80800994: beql        $a2, $zero, L_808009BC
    if (ctx->r6 == 0) {
        // 0x80800998: lw          $t2, 0x90($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X90);
            goto L_808009BC;
    }
    goto skip_8;
    // 0x80800998: lw          $t2, 0x90($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X90);
    skip_8:
    // 0x8080099C: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x808009A0: jal         0x8002DCA0
    // 0x808009A4: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    sqrtf_recomp(rdram, ctx);
        goto after_10;
    // 0x808009A4: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_10:
    // 0x808009A8: mul.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x808009AC: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x808009B0: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x808009B4: nop

    // 0x808009B8: lw          $t2, 0x90($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X90);
L_808009BC:
    // 0x808009BC: lw          $t3, 0x98($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X98);
    // 0x808009C0: or          $v0, $fp, $zero
    ctx->r2 = ctx->r30 | 0;
    // 0x808009C4: slt         $at, $t2, $a3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x808009C8: beq         $at, $zero, L_808009EC
    if (ctx->r1 == 0) {
        // 0x808009CC: lw          $t8, 0x84($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X84);
            goto L_808009EC;
    }
    // 0x808009CC: lw          $t8, 0x84($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X84);
    // 0x808009D0: subu        $t5, $a3, $t2
    ctx->r13 = SUB32(ctx->r7, ctx->r10);
    // 0x808009D4: multu       $t3, $t5
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808009D8: mflo        $t6
    ctx->r14 = lo;
    // 0x808009DC: sra         $t7, $t6, 8
    ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
    // 0x808009E0: subu        $v1, $s7, $t7
    ctx->r3 = SUB32(ctx->r23, ctx->r15);
    // 0x808009E4: b           L_808009EC
    // 0x808009E8: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
        goto L_808009EC;
    // 0x808009E8: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
L_808009EC:
    // 0x808009EC: multu       $t8, $v0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808009F0: lh          $t4, 0x0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X0);
    // 0x808009F4: lh          $t2, 0x2($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X2);
    // 0x808009F8: lh          $t8, 0x4($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X4);
    // 0x808009FC: mflo        $t9
    ctx->r25 = lo;
    // 0x80800A00: sra         $t0, $t9, 16
    ctx->r8 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80800A04: addu        $t1, $t4, $t0
    ctx->r9 = ADD32(ctx->r12, ctx->r8);
    // 0x80800A08: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
    // 0x80800A0C: lw          $t3, 0x88($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X88);
    // 0x80800A10: multu       $t3, $v0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800A14: mflo        $t5
    ctx->r13 = lo;
    // 0x80800A18: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80800A1C: addu        $t7, $t2, $t6
    ctx->r15 = ADD32(ctx->r10, ctx->r14);
    // 0x80800A20: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x80800A24: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    // 0x80800A28: multu       $t9, $v0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800A2C: mflo        $t4
    ctx->r12 = lo;
    // 0x80800A30: sra         $t0, $t4, 16
    ctx->r8 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80800A34: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80800A38: sh          $t1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r9;
L_80800A3C:
    // 0x80800A3C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80800A40: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x80800A44: bnel        $at, $zero, L_8080092C
    if (ctx->r1 != 0) {
        // 0x80800A48: lh          $t8, 0x6($s0)
        ctx->r24 = MEM_H(ctx->r16, 0X6);
            goto L_8080092C;
    }
    goto skip_9;
    // 0x80800A48: lh          $t8, 0x6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X6);
    skip_9:
L_80800A4C:
    // 0x80800A4C: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
L_80800A50:
    // 0x80800A50: slti        $at, $s6, 0xF
    ctx->r1 = SIGNED(ctx->r22) < 0XF ? 1 : 0;
    // 0x80800A54: bne         $at, $zero, L_808008EC
    if (ctx->r1 != 0) {
        // 0x80800A58: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_808008EC;
    }
    // 0x80800A58: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80800A5C: sltu        $at, $s1, $s2
    ctx->r1 = ctx->r17 < ctx->r18 ? 1 : 0;
L_80800A60:
    // 0x80800A60: beql        $at, $zero, L_80800AC8
    if (ctx->r1 == 0) {
        // 0x80800A64: lw          $v0, 0xEC($sp)
        ctx->r2 = MEM_W(ctx->r29, 0XEC);
            goto L_80800AC8;
    }
    goto skip_10;
    // 0x80800A64: lw          $v0, 0xEC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XEC);
    skip_10:
L_80800A68:
    // 0x80800A68: lh          $t3, 0x6($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X6);
    // 0x80800A6C: lh          $v0, 0x0($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X0);
    // 0x80800A70: sll         $t5, $t3, 4
    ctx->r13 = S32(ctx->r11 << 4);
    // 0x80800A74: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x80800A78: bne         $at, $zero, L_80800A84
    if (ctx->r1 != 0) {
        // 0x80800A7C: addu        $v1, $t5, $s5
        ctx->r3 = ADD32(ctx->r13, ctx->r21);
            goto L_80800A84;
    }
    // 0x80800A7C: addu        $v1, $t5, $s5
    ctx->r3 = ADD32(ctx->r13, ctx->r21);
    // 0x80800A80: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80800A84:
    // 0x80800A84: sb          $v0, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r2;
    // 0x80800A88: lh          $v0, 0x2($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X2);
    // 0x80800A8C: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x80800A90: bnel        $at, $zero, L_80800AA0
    if (ctx->r1 != 0) {
        // 0x80800A94: sb          $v0, 0xD($v1)
        MEM_B(0XD, ctx->r3) = ctx->r2;
            goto L_80800AA0;
    }
    goto skip_11;
    // 0x80800A94: sb          $v0, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r2;
    skip_11:
    // 0x80800A98: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80800A9C: sb          $v0, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r2;
L_80800AA0:
    // 0x80800AA0: lh          $v0, 0x4($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X4);
    // 0x80800AA4: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x80800AA8: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x80800AAC: bnel        $at, $zero, L_80800ABC
    if (ctx->r1 != 0) {
        // 0x80800AB0: sltu        $at, $s1, $s2
        ctx->r1 = ctx->r17 < ctx->r18 ? 1 : 0;
            goto L_80800ABC;
    }
    goto skip_12;
    // 0x80800AB0: sltu        $at, $s1, $s2
    ctx->r1 = ctx->r17 < ctx->r18 ? 1 : 0;
    skip_12:
    // 0x80800AB4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80800AB8: sltu        $at, $s1, $s2
    ctx->r1 = ctx->r17 < ctx->r18 ? 1 : 0;
L_80800ABC:
    // 0x80800ABC: bne         $at, $zero, L_80800A68
    if (ctx->r1 != 0) {
        // 0x80800AC0: sb          $v0, 0xE($v1)
        MEM_B(0XE, ctx->r3) = ctx->r2;
            goto L_80800A68;
    }
    // 0x80800AC0: sb          $v0, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r2;
    // 0x80800AC4: lw          $v0, 0xEC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XEC);
L_80800AC8:
    // 0x80800AC8: lb          $t6, 0xF($v0)
    ctx->r14 = MEM_B(ctx->r2, 0XF);
    // 0x80800ACC: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80800AD0: sb          $t7, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r15;
L_80800AD4:
    // 0x80800AD4: lw          $t9, 0xE8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE8);
L_80800AD8:
    // 0x80800AD8: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x80800ADC: sltu        $at, $v0, $t9
    ctx->r1 = ctx->r2 < ctx->r25 ? 1 : 0;
    // 0x80800AE0: bnel        $at, $zero, L_808007F4
    if (ctx->r1 != 0) {
        // 0x80800AE4: lb          $t2, 0xF($v0)
        ctx->r10 = MEM_B(ctx->r2, 0XF);
            goto L_808007F4;
    }
    goto skip_13;
    // 0x80800AE4: lb          $t2, 0xF($v0)
    ctx->r10 = MEM_B(ctx->r2, 0XF);
    skip_13:
    // 0x80800AE8: sw          $v0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r2;
L_80800AEC:
    // 0x80800AEC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80800AF0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80800AF4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800AF8: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80800AFC: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80800B00: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80800B04: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80800B08: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80800B0C: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80800B10: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80800B14: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80800B18: jr          $ra
    // 0x80800B1C: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
    return;
    // 0x80800B1C: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
;}
RECOMP_FUNC void gcstatusDll_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x808000DC: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x808000E0: jr          $ra
    // 0x808000E4: sb          $a1, -0x4BF6($at)
    MEM_B(-0X4BF6, ctx->r1) = ctx->r5;
    return;
    // 0x808000E4: sb          $a1, -0x4BF6($at)
    MEM_B(-0X4BF6, ctx->r1) = ctx->r5;
;}
RECOMP_FUNC void suspline_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800160: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800164: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80800168: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x8080016C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800170: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800174: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800178: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8080017C: addu        $a1, $a3, $t7
    ctx->r5 = ADD32(ctx->r7, ctx->r15);
    // 0x80800180: jal         0x800EE7F8
    // 0x80800184: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800184: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80800188: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080018C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800190: jr          $ra
    // 0x80800194: nop

    return;
    // 0x80800194: nop

;}
RECOMP_FUNC void func_80800190_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800190: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800194: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800198: lw          $t6, 0x188($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X188);
    // 0x8080019C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808001A0: jal         0x80800858
    // 0x808001A4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_80800858_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x808001A4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x808001A8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808001AC: jal         0x800EFD24
    // 0x808001B0: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    func_800EFD24(rdram, ctx);
        goto after_1;
    // 0x808001B0: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    after_1:
    // 0x808001B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808001B8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x808001BC: swc1        $f4, 0x50($t7)
    MEM_W(0X50, ctx->r15) = ctx->f4.u32l;
    // 0x808001C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001C8: jr          $ra
    // 0x808001CC: nop

    return;
    // 0x808001CC: nop

;}
RECOMP_FUNC void func_808001A8_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001B0: jal         0x80800104
    // 0x808001B4: nop

    func_80800104_bsbswim(rdram, ctx);
        goto after_0;
    // 0x808001B4: nop

    after_0:
    // 0x808001B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001C0: jr          $ra
    // 0x808001C4: nop

    return;
    // 0x808001C4: nop

;}
RECOMP_FUNC void func_80800388_badata(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800388: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080038C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800390: jal         0x8009EA4C
    // 0x80800394: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8009EA4C(rdram, ctx);
        goto after_0;
    // 0x80800394: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800398: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080039C: jal         0x800A3274
    // 0x808003A0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800A3274(rdram, ctx);
        goto after_1;
    // 0x808003A0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808003A4: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x808003A8: sltiu       $at, $t6, 0x13
    ctx->r1 = ctx->r14 < 0X13 ? 1 : 0;
    // 0x808003AC: beq         $at, $zero, L_808005B8
    if (ctx->r1 == 0) {
        // 0x808003B0: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_808005B8;
    }
    // 0x808003B0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808003B4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808003B8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(473, 0X100C) << 16);
    // 0x808003BC: addu        $at, $at, $t6
    gpr jr_addend_808003C4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808003C0: lw          $t6, 0x100C($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(473, 0X100C));
    // 0x808003C4: jr          $t6
    // 0x808003C8: nop

    switch (jr_addend_808003C4 >> 2) {
        case 0: goto L_808005B8; break;
        case 1: goto L_808003CC; break;
        case 2: goto L_808005B8; break;
        case 3: goto L_808005B8; break;
        case 4: goto L_808005B8; break;
        case 5: goto L_808003D4; break;
        case 6: goto L_808003F0; break;
        case 7: goto L_808003F8; break;
        case 8: goto L_808005B0; break;
        case 9: goto L_80800400; break;
        case 10: goto L_808004B8; break;
        case 11: goto L_80800590; break;
        case 12: goto L_80800558; break;
        case 13: goto L_80800578; break;
        case 14: goto L_80800580; break;
        case 15: goto L_80800588; break;
        case 16: goto L_80800598; break;
        case 17: goto L_808005A0; break;
        case 18: goto L_808005A8; break;
        default: switch_error(__func__, 0x808003C4, 0x8080100C);
    }
    // 0x808003C8: nop

L_808003CC:
    // 0x808003CC: b           L_8080069C
    // 0x808003D0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8080069C;
    // 0x808003D0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_808003D4:
    // 0x808003D4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808003D8: bne         $v1, $at, L_808003E8
    if (ctx->r3 != ctx->r1) {
        // 0x808003DC: nop
    
            goto L_808003E8;
    }
    // 0x808003DC: nop

    // 0x808003E0: b           L_8080069C
    // 0x808003E4: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
        goto L_8080069C;
    // 0x808003E4: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
L_808003E8:
    // 0x808003E8: b           L_8080069C
    // 0x808003EC: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
        goto L_8080069C;
    // 0x808003EC: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
L_808003F0:
    // 0x808003F0: b           L_8080069C
    // 0x808003F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080069C;
    // 0x808003F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808003F8:
    // 0x808003F8: b           L_8080069C
    // 0x808003FC: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
        goto L_8080069C;
    // 0x808003FC: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
L_80800400:
    // 0x80800400: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800404: jal         0x8008E35C
    // 0x80800408: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    player_inWater(rdram, ctx);
        goto after_2;
    // 0x80800408: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x8080040C: beq         $v0, $zero, L_80800474
    if (ctx->r2 == 0) {
        // 0x80800410: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80800474;
    }
    // 0x80800410: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800414: jal         0x800F8B88
    // 0x80800418: nop

    func_800F8B88(rdram, ctx);
        goto after_3;
    // 0x80800418: nop

    after_3:
    // 0x8080041C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800420: bne         $v0, $at, L_80800430
    if (ctx->r2 != ctx->r1) {
        // 0x80800424: nop
    
            goto L_80800430;
    }
    // 0x80800424: nop

    // 0x80800428: b           L_8080069C
    // 0x8080042C: addiu       $v0, $zero, 0x21
    ctx->r2 = ADD32(0, 0X21);
        goto L_8080069C;
    // 0x8080042C: addiu       $v0, $zero, 0x21
    ctx->r2 = ADD32(0, 0X21);
L_80800430:
    // 0x80800430: jal         0x8009C150
    // 0x80800434: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8009C150(rdram, ctx);
        goto after_4;
    // 0x80800434: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80800438: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8080043C: jal         0x800964DC
    // 0x80800440: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800964DC(rdram, ctx);
        goto after_5;
    // 0x80800440: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x80800444: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80800448: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080044C: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80800450: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80800454: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80800458: nop

    // 0x8080045C: bc1f        L_8080046C
    if (!c1cs) {
        // 0x80800460: nop
    
            goto L_8080046C;
    }
    // 0x80800460: nop

    // 0x80800464: b           L_8080069C
    // 0x80800468: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_8080069C;
    // 0x80800468: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8080046C:
    // 0x8080046C: b           L_8080069C
    // 0x80800470: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_8080069C;
    // 0x80800470: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_80800474:
    // 0x80800474: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800478: beq         $v1, $at, L_80800498
    if (ctx->r3 == ctx->r1) {
        // 0x8080047C: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80800498;
    }
    // 0x8080047C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800480: beq         $v1, $at, L_808004A0
    if (ctx->r3 == ctx->r1) {
        // 0x80800484: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_808004A0;
    }
    // 0x80800484: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800488: beq         $v1, $at, L_808004A8
    if (ctx->r3 == ctx->r1) {
        // 0x8080048C: nop
    
            goto L_808004A8;
    }
    // 0x8080048C: nop

    // 0x80800490: b           L_8080069C
    // 0x80800494: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
        goto L_8080069C;
    // 0x80800494: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_80800498:
    // 0x80800498: b           L_8080069C
    // 0x8080049C: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_8080069C;
    // 0x8080049C: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_808004A0:
    // 0x808004A0: b           L_8080069C
    // 0x808004A4: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
        goto L_8080069C;
    // 0x808004A4: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
L_808004A8:
    // 0x808004A8: b           L_8080069C
    // 0x808004AC: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
        goto L_8080069C;
    // 0x808004AC: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x808004B0: b           L_8080069C
    // 0x808004B4: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
        goto L_8080069C;
    // 0x808004B4: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_808004B8:
    // 0x808004B8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808004BC: bne         $v1, $at, L_808004CC
    if (ctx->r3 != ctx->r1) {
        // 0x808004C0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808004CC;
    }
    // 0x808004C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808004C4: b           L_8080069C
    // 0x808004C8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8080069C;
    // 0x808004C8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808004CC:
    // 0x808004CC: jal         0x80091538
    // 0x808004D0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    bastatetimer_get(rdram, ctx);
        goto after_6;
    // 0x808004D0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x808004D4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x808004D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808004DC: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x808004E0: nop

    // 0x808004E4: bc1t        L_808004F4
    if (c1cs) {
        // 0x808004E8: nop
    
            goto L_808004F4;
    }
    // 0x808004E8: nop

    // 0x808004EC: b           L_8080069C
    // 0x808004F0: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
        goto L_8080069C;
    // 0x808004F0: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_808004F4:
    // 0x808004F4: jal         0x80091538
    // 0x808004F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    bastatetimer_get(rdram, ctx);
        goto after_7;
    // 0x808004F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x808004FC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80800500: nop

    // 0x80800504: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x80800508: nop

    // 0x8080050C: bc1t        L_8080051C
    if (c1cs) {
        // 0x80800510: nop
    
            goto L_8080051C;
    }
    // 0x80800510: nop

    // 0x80800514: b           L_8080069C
    // 0x80800518: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080069C;
    // 0x80800518: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080051C:
    // 0x8080051C: jal         0x800F8B88
    // 0x80800520: nop

    func_800F8B88(rdram, ctx);
        goto after_8;
    // 0x80800520: nop

    after_8:
    // 0x80800524: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800528: bne         $v0, $at, L_80800538
    if (ctx->r2 != ctx->r1) {
        // 0x8080052C: nop
    
            goto L_80800538;
    }
    // 0x8080052C: nop

    // 0x80800530: b           L_8080069C
    // 0x80800534: addiu       $v0, $zero, 0x1A
    ctx->r2 = ADD32(0, 0X1A);
        goto L_8080069C;
    // 0x80800534: addiu       $v0, $zero, 0x1A
    ctx->r2 = ADD32(0, 0X1A);
L_80800538:
    // 0x80800538: jal         0x8008E35C
    // 0x8080053C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    player_inWater(rdram, ctx);
        goto after_9;
    // 0x8080053C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_9:
    // 0x80800540: beq         $v0, $zero, L_80800550
    if (ctx->r2 == 0) {
        // 0x80800544: nop
    
            goto L_80800550;
    }
    // 0x80800544: nop

    // 0x80800548: b           L_8080069C
    // 0x8080054C: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
        goto L_8080069C;
    // 0x8080054C: addiu       $v0, $zero, 0x1B
    ctx->r2 = ADD32(0, 0X1B);
L_80800550:
    // 0x80800550: b           L_8080069C
    // 0x80800554: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
        goto L_8080069C;
    // 0x80800554: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_80800558:
    // 0x80800558: jal         0x8008E35C
    // 0x8080055C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    player_inWater(rdram, ctx);
        goto after_10;
    // 0x8080055C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_10:
    // 0x80800560: beq         $v0, $zero, L_80800570
    if (ctx->r2 == 0) {
        // 0x80800564: nop
    
            goto L_80800570;
    }
    // 0x80800564: nop

    // 0x80800568: b           L_8080069C
    // 0x8080056C: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
        goto L_8080069C;
    // 0x8080056C: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
L_80800570:
    // 0x80800570: b           L_8080069C
    // 0x80800574: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
        goto L_8080069C;
    // 0x80800574: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
L_80800578:
    // 0x80800578: b           L_8080069C
    // 0x8080057C: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
        goto L_8080069C;
    // 0x8080057C: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
L_80800580:
    // 0x80800580: b           L_8080069C
    // 0x80800584: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
        goto L_8080069C;
    // 0x80800584: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
L_80800588:
    // 0x80800588: b           L_8080069C
    // 0x8080058C: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
        goto L_8080069C;
    // 0x8080058C: addiu       $v0, $zero, 0x15
    ctx->r2 = ADD32(0, 0X15);
L_80800590:
    // 0x80800590: b           L_8080069C
    // 0x80800594: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
        goto L_8080069C;
    // 0x80800594: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
L_80800598:
    // 0x80800598: b           L_8080069C
    // 0x8080059C: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
        goto L_8080069C;
    // 0x8080059C: addiu       $v0, $zero, 0x17
    ctx->r2 = ADD32(0, 0X17);
L_808005A0:
    // 0x808005A0: b           L_8080069C
    // 0x808005A4: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
        goto L_8080069C;
    // 0x808005A4: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
L_808005A8:
    // 0x808005A8: b           L_8080069C
    // 0x808005AC: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
        goto L_8080069C;
    // 0x808005AC: addiu       $v0, $zero, 0x19
    ctx->r2 = ADD32(0, 0X19);
L_808005B0:
    // 0x808005B0: b           L_8080069C
    // 0x808005B4: addiu       $v0, $zero, 0x1D
    ctx->r2 = ADD32(0, 0X1D);
        goto L_8080069C;
    // 0x808005B4: addiu       $v0, $zero, 0x1D
    ctx->r2 = ADD32(0, 0X1D);
L_808005B8:
    // 0x808005B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808005BC: jal         0x8008E35C
    // 0x808005C0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    player_inWater(rdram, ctx);
        goto after_11;
    // 0x808005C0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_11:
    // 0x808005C4: beq         $v0, $zero, L_80800610
    if (ctx->r2 == 0) {
        // 0x808005C8: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80800610;
    }
    // 0x808005C8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808005CC: jal         0x8009C150
    // 0x808005D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8009C150(rdram, ctx);
        goto after_12;
    // 0x808005D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_12:
    // 0x808005D4: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x808005D8: jal         0x800964DC
    // 0x808005DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800964DC(rdram, ctx);
        goto after_13;
    // 0x808005DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_13:
    // 0x808005E0: lui         $at, 0x42BE
    ctx->r1 = S32(0X42BE << 16);
    // 0x808005E4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808005E8: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x808005EC: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x808005F0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808005F4: nop

    // 0x808005F8: bc1f        L_80800608
    if (!c1cs) {
        // 0x808005FC: nop
    
            goto L_80800608;
    }
    // 0x808005FC: nop

    // 0x80800600: b           L_8080069C
    // 0x80800604: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_8080069C;
    // 0x80800604: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800608:
    // 0x80800608: b           L_8080069C
    // 0x8080060C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_8080069C;
    // 0x8080060C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_80800610:
    // 0x80800610: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800614: bnel        $v1, $at, L_80800628
    if (ctx->r3 != ctx->r1) {
        // 0x80800618: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80800628;
    }
    goto skip_0;
    // 0x80800618: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    skip_0:
    // 0x8080061C: b           L_8080069C
    // 0x80800620: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_8080069C;
    // 0x80800620: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80800624: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_80800628:
    // 0x80800628: bnel        $v1, $at, L_8080063C
    if (ctx->r3 != ctx->r1) {
        // 0x8080062C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080063C;
    }
    goto skip_1;
    // 0x8080062C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_1:
    // 0x80800630: b           L_8080069C
    // 0x80800634: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_8080069C;
    // 0x80800634: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80800638: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8080063C:
    // 0x8080063C: bne         $v1, $at, L_8080064C
    if (ctx->r3 != ctx->r1) {
        // 0x80800640: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8080064C;
    }
    // 0x80800640: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800644: b           L_8080069C
    // 0x80800648: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_8080069C;
    // 0x80800648: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_8080064C:
    // 0x8080064C: jal         0x80091538
    // 0x80800650: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    bastatetimer_get(rdram, ctx);
        goto after_14;
    // 0x80800650: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_14:
    // 0x80800654: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80800658: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080065C: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x80800660: nop

    // 0x80800664: bc1t        L_80800674
    if (c1cs) {
        // 0x80800668: nop
    
            goto L_80800674;
    }
    // 0x80800668: nop

    // 0x8080066C: b           L_8080069C
    // 0x80800670: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_8080069C;
    // 0x80800670: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_80800674:
    // 0x80800674: jal         0x80091538
    // 0x80800678: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    bastatetimer_get(rdram, ctx);
        goto after_15;
    // 0x80800678: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_15:
    // 0x8080067C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800680: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80800684: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x80800688: nop

    // 0x8080068C: bc1t        L_8080069C
    if (c1cs) {
        // 0x80800690: nop
    
            goto L_8080069C;
    }
    // 0x80800690: nop

    // 0x80800694: b           L_8080069C
    // 0x80800698: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
        goto L_8080069C;
    // 0x80800698: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_8080069C:
    // 0x8080069C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808006A4: jr          $ra
    // 0x808006A8: nop

    return;
    // 0x808006A8: nop

;}
RECOMP_FUNC void func_800B4290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4290: sh          $zero, 0x2($a0)
    MEM_H(0X2, ctx->r4) = 0;
    // 0x800B4294: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x800B4298: jr          $ra
    // 0x800B429C: sh          $t6, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r14;
    return;
    // 0x800B429C: sh          $t6, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_80800850_ch2dbaddy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800850: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800854: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800858: jal         0x8008A110
    // 0x8080085C: nop

    _sucoaster_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x8080085C: nop

    after_0:
    // 0x80800860: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800864: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800868: jal         0x800DC128
    // 0x8080086C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DC128(rdram, ctx);
        goto after_1;
    // 0x8080086C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x80800870: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x80800874: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1356, 0XB00) << 16);
    // 0x80800878: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8080087C: lh          $t7, 0xB00($t7)
    ctx->r15 = MEM_H(ctx->r15, (int16_t)RELOC_LO16(1356, 0XB00));
    // 0x80800880: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80800884: sh          $t7, 0x6($t8)
    MEM_H(0X6, ctx->r24) = ctx->r15;
    // 0x80800888: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080088C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800890: jr          $ra
    // 0x80800894: nop

    return;
    // 0x80800894: nop

    // 0x80800898: nop

    // 0x8080089C: nop

;}
RECOMP_FUNC void inantab_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806518: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080651C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80806520: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80806524: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80806528: jal         0x80106790
    // 0x8080652C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x8080652C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80806530: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80806534: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80806538: bnel        $t6, $zero, L_80806584
    if (ctx->r14 != 0) {
        // 0x8080653C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80806584;
    }
    goto skip_0;
    // 0x8080653C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80806540: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80806544: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80806548: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x8080654C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80806550: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80806554: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80806558: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8080655C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80806560: mul.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80806564: nop

    // 0x80806568: mul.s       $f14, $f10, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8080656C: jal         0x800DC178
    // 0x80806570: nop

    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80806570: nop

    after_1:
    // 0x80806574: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80806578: jal         0x80101CDC
    // 0x8080657C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80101CDC(rdram, ctx);
        goto after_2;
    // 0x8080657C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80806580: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80806584:
    // 0x80806584: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80806588: jr          $ra
    // 0x8080658C: nop

    return;
    // 0x8080658C: nop

;}
RECOMP_FUNC void func_800C89A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C89A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C89AC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800C89B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C89B4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C89B8: lw          $a0, -0x5500($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5500);
    // 0x800C89BC: jal         0x800B28CC
    // 0x800C89C0: addiu       $a1, $a2, -0x1
    ctx->r5 = ADD32(ctx->r6, -0X1);
    vector_at(rdram, ctx);
        goto after_0;
    // 0x800C89C0: addiu       $a1, $a2, -0x1
    ctx->r5 = ADD32(ctx->r6, -0X1);
    after_0:
    // 0x800C89C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C89C8: lbu         $v0, 0x15($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X15);
    // 0x800C89CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C89D0: jr          $ra
    // 0x800C89D4: nop

    return;
    // 0x800C89D4: nop

;}
RECOMP_FUNC void glrecord_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800130: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80800134: lw          $a0, -0x2A4C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2A4C);
    // 0x80800138: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080013C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800140: beql        $a0, $zero, L_8080015C
    if (ctx->r4 == 0) {
        // 0x80800144: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080015C;
    }
    goto skip_0;
    // 0x80800144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800148: jal         0x800D56C4
    // 0x8080014C: nop

    func_800D56C4(rdram, ctx);
        goto after_0;
    // 0x8080014C: nop

    after_0:
    // 0x80800150: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80800154: sw          $zero, -0x2A4C($at)
    MEM_W(-0X2A4C, ctx->r1) = 0;
    // 0x80800158: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080015C:
    // 0x8080015C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800160: jr          $ra
    // 0x80800164: nop

    return;
    // 0x80800164: nop

    // 0x80800168: nop

    // 0x8080016C: nop

;}
RECOMP_FUNC void idglow_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800238: jr          $ra
    // 0x8080023C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8080023C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_808001CC_bsride(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001CC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x808001D0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808001D4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808001D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001DC: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    // 0x808001E0: jal         0x8009C128
    // 0x808001E4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x808001E4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x808001E8: addiu       $a2, $s0, 0x16C
    ctx->r6 = ADD32(ctx->r16, 0X16C);
    // 0x808001EC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808001F0: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x808001F4: jal         0x800EFB24
    // 0x808001F8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800EFB24(rdram, ctx);
        goto after_1;
    // 0x808001F8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_1:
    // 0x808001FC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800200: jal         0x800EE7F8
    // 0x80800204: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800204: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_2:
    // 0x80800208: jal         0x800EEF94
    // 0x8080020C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    func_800EEF94(rdram, ctx);
        goto after_3;
    // 0x8080020C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_3:
    // 0x80800210: jal         0x800D8FF8
    // 0x80800214: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_4;
    // 0x80800214: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x80800218: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(348, 0X9B0) << 16);
    // 0x8080021C: lwc1        $f6, 0x9B0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(348, 0X9B0));
    // 0x80800220: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80800224: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800228: lui         $a3, 0x3F66
    ctx->r7 = S32(0X3F66 << 16);
    // 0x8080022C: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80800230: lui         $a2, 0x44FA
    ctx->r6 = S32(0X44FA << 16);
    // 0x80800234: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80800238: jal         0x800F10B4
    // 0x8080023C: div.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    func_800F10B4(rdram, ctx);
        goto after_5;
    // 0x8080023C: div.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    after_5:
    // 0x80800240: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x80800244: jal         0x8008CABC
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_6;
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080024C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800250: jal         0x8008B1BC
    // 0x80800254: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    anctrl_setDuration(rdram, ctx);
        goto after_7;
    // 0x80800254: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_7:
    // 0x80800258: lw          $t6, 0x15C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X15C);
    // 0x8080025C: addiu       $t7, $zero, 0x2F
    ctx->r15 = ADD32(0, 0X2F);
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800264: bne         $t6, $zero, L_80800270
    if (ctx->r14 != 0) {
        // 0x80800268: nop
    
            goto L_80800270;
    }
    // 0x80800268: nop

    // 0x8080026C: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
L_80800270:
    // 0x80800270: jal         0x8009E5C8
    // 0x80800274: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    bs_setState(rdram, ctx);
        goto after_8;
    // 0x80800274: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_8:
    // 0x80800278: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080027C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800280: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80800284: jr          $ra
    // 0x80800288: nop

    return;
    // 0x80800288: nop

;}
RECOMP_FUNC void bsdronebitten_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808002F4: jal         0x800961A0
    // 0x808002F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800961A0(rdram, ctx);
        goto after_0;
    // 0x808002F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808002FC: jal         0x8008E95C
    // 0x80800300: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008E95C(rdram, ctx);
        goto after_1;
    // 0x80800300: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800304: jal         0x80084D10
    // 0x80800308: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bafpctrl_entrypoint_19(rdram, ctx);
        goto after_2;
    // 0x80800308: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8080030C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800310: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800314: jr          $ra
    // 0x80800318: nop

    return;
    // 0x80800318: nop

;}
RECOMP_FUNC void func_80800180_chchuffyglow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800180: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x80800184: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1772, 0X568) << 16);
    // 0x80800188: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8080018C: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80800190: addiu       $t7, $t7, 0x568
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1772, 0X568));
    // 0x80800194: addiu       $s1, $sp, 0x78
    ctx->r17 = ADD32(ctx->r29, 0X78);
    // 0x80800198: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x8080019C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x808001A0: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x808001A4: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x808001A8: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x808001AC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x808001B0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808001B4: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x808001B8: addiu       $t0, $t7, 0x3C
    ctx->r8 = ADD32(ctx->r15, 0X3C);
    // 0x808001BC: addiu       $t6, $sp, 0x84
    ctx->r14 = ADD32(ctx->r29, 0X84);
L_808001C0:
    // 0x808001C0: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x808001C4: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x808001C8: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x808001CC: sw          $at, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r1;
    // 0x808001D0: lw          $at, -0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X8);
    // 0x808001D4: sw          $at, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r1;
    // 0x808001D8: lw          $at, -0x4($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X4);
    // 0x808001DC: bne         $t7, $t0, L_808001C0
    if (ctx->r15 != ctx->r8) {
        // 0x808001E0: sw          $at, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r1;
            goto L_808001C0;
    }
    // 0x808001E0: sw          $at, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r1;
    // 0x808001E4: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(1772, 0X5A4) << 16);
    // 0x808001E8: addiu       $t1, $t1, 0x5A4
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(1772, 0X5A4));
    // 0x808001EC: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x808001F0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808001F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808001F8: sw          $at, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r1;
    // 0x808001FC: lw          $t4, 0x4($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X4);
    // 0x80800200: sw          $t4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r12;
    // 0x80800204: lw          $at, 0x8($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X8);
    // 0x80800208: jal         0x80100094
    // 0x8080020C: sw          $at, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r1;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080020C: sw          $at, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r1;
    after_0:
    // 0x80800210: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x80800214: addiu       $s6, $s5, 0x18
    ctx->r22 = ADD32(ctx->r21, 0X18);
    // 0x80800218: addiu       $s0, $s5, 0x28
    ctx->r16 = ADD32(ctx->r21, 0X28);
    // 0x8080021C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800220: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80800224: jal         0x80086C20
    // 0x80800228: lw          $a0, 0x3C($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X3C);
    _chchuffy_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800228: lw          $a0, 0x3C($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X3C);
    after_1:
    // 0x8080022C: lhu         $v1, 0x72($s5)
    ctx->r3 = MEM_HU(ctx->r21, 0X72);
    // 0x80800230: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800234: srl         $t5, $v1, 10
    ctx->r13 = S32(U32(ctx->r3) >> 10);
    // 0x80800238: beq         $t5, $at, L_8080025C
    if (ctx->r13 == ctx->r1) {
        // 0x8080023C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080025C;
    }
    // 0x8080023C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800240: beq         $t5, $at, L_808002D0
    if (ctx->r13 == ctx->r1) {
        // 0x80800244: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808002D0;
    }
    // 0x80800244: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800248: beq         $t5, $at, L_808002FC
    if (ctx->r13 == ctx->r1) {
        // 0x8080024C: nop
    
            goto L_808002FC;
    }
    // 0x8080024C: nop

    // 0x80800250: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800254: b           L_80800340
    // 0x80800258: lw          $a0, 0x3C($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X3C);
        goto L_80800340;
    // 0x80800258: lw          $a0, 0x3C($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X3C);
L_8080025C:
    // 0x8080025C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800260: lwc1        $f4, 0x58($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X58);
    // 0x80800264: c.le.s      $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f4.fl <= ctx->f20.fl;
    // 0x80800268: nop

    // 0x8080026C: bc1f        L_808002B8
    if (!c1cs) {
        // 0x80800270: nop
    
            goto L_808002B8;
    }
    // 0x80800270: nop

    // 0x80800274: jal         0x80089C90
    // 0x80800278: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80800278: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_2:
    // 0x8080027C: slti        $at, $v0, 0xFD
    ctx->r1 = SIGNED(ctx->r2) < 0XFD ? 1 : 0;
    // 0x80800280: beql        $at, $zero, L_808002A8
    if (ctx->r1 == 0) {
        // 0x80800284: lbu         $t9, 0x72($s5)
        ctx->r25 = MEM_BU(ctx->r21, 0X72);
            goto L_808002A8;
    }
    goto skip_0;
    // 0x80800284: lbu         $t9, 0x72($s5)
    ctx->r25 = MEM_BU(ctx->r21, 0X72);
    skip_0:
    // 0x80800288: jal         0x80089C90
    // 0x8080028C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x8080028C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_3:
    // 0x80800290: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800294: jal         0x80089C98
    // 0x80800298: addiu       $a1, $v0, 0x3
    ctx->r5 = ADD32(ctx->r2, 0X3);
    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x80800298: addiu       $a1, $v0, 0x3
    ctx->r5 = ADD32(ctx->r2, 0X3);
    after_4:
    // 0x8080029C: b           L_80800340
    // 0x808002A0: lw          $a0, 0x3C($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X3C);
        goto L_80800340;
    // 0x808002A0: lw          $a0, 0x3C($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X3C);
    // 0x808002A4: lbu         $t9, 0x72($s5)
    ctx->r25 = MEM_BU(ctx->r21, 0X72);
L_808002A8:
    // 0x808002A8: andi        $t8, $t9, 0xFF03
    ctx->r24 = ctx->r25 & 0XFF03;
    // 0x808002AC: ori         $t0, $t8, 0x8
    ctx->r8 = ctx->r24 | 0X8;
    // 0x808002B0: b           L_8080033C
    // 0x808002B4: sb          $t0, 0x72($s5)
    MEM_B(0X72, ctx->r21) = ctx->r8;
        goto L_8080033C;
    // 0x808002B4: sb          $t0, 0x72($s5)
    MEM_B(0X72, ctx->r21) = ctx->r8;
L_808002B8:
    // 0x808002B8: jal         0x800D8FF8
    // 0x808002BC: nop

    func_800D8FF8(rdram, ctx);
        goto after_5;
    // 0x808002BC: nop

    after_5:
    // 0x808002C0: lwc1        $f6, 0x58($s5)
    ctx->f6.u32l = MEM_W(ctx->r21, 0X58);
    // 0x808002C4: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x808002C8: b           L_8080033C
    // 0x808002CC: swc1        $f8, 0x58($s5)
    MEM_W(0X58, ctx->r21) = ctx->f8.u32l;
        goto L_8080033C;
    // 0x808002CC: swc1        $f8, 0x58($s5)
    MEM_W(0X58, ctx->r21) = ctx->f8.u32l;
L_808002D0:
    // 0x808002D0: lw          $t7, 0x64($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X64);
    // 0x808002D4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x808002D8: sll         $t3, $t7, 11
    ctx->r11 = S32(ctx->r15 << 11);
    // 0x808002DC: bltz        $t3, L_808002F4
    if (SIGNED(ctx->r11) < 0) {
        // 0x808002E0: nop
    
            goto L_808002F4;
    }
    // 0x808002E0: nop

    // 0x808002E4: lbu         $t2, 0x72($s5)
    ctx->r10 = MEM_BU(ctx->r21, 0X72);
    // 0x808002E8: andi        $t1, $t2, 0xFF03
    ctx->r9 = ctx->r10 & 0XFF03;
    // 0x808002EC: ori         $t4, $t1, 0xC
    ctx->r12 = ctx->r9 | 0XC;
    // 0x808002F0: sb          $t4, 0x72($s5)
    MEM_B(0X72, ctx->r21) = ctx->r12;
L_808002F4:
    // 0x808002F4: b           L_80800340
    // 0x808002F8: lw          $a0, 0x3C($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X3C);
        goto L_80800340;
    // 0x808002F8: lw          $a0, 0x3C($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X3C);
L_808002FC:
    // 0x808002FC: jal         0x80089C90
    // 0x80800300: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_6;
    // 0x80800300: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_6:
    // 0x80800304: slti        $at, $v0, 0x7
    ctx->r1 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x80800308: bne         $at, $zero, L_8080032C
    if (ctx->r1 != 0) {
        // 0x8080030C: nop
    
            goto L_8080032C;
    }
    // 0x8080030C: nop

    // 0x80800310: jal         0x80089C90
    // 0x80800314: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_7;
    // 0x80800314: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_7:
    // 0x80800318: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8080031C: jal         0x80089C98
    // 0x80800320: addiu       $a1, $v0, -0x7
    ctx->r5 = ADD32(ctx->r2, -0X7);
    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_8;
    // 0x80800320: addiu       $a1, $v0, -0x7
    ctx->r5 = ADD32(ctx->r2, -0X7);
    after_8:
    // 0x80800324: b           L_80800338
    // 0x80800328: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
        goto L_80800338;
    // 0x80800328: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
L_8080032C:
    // 0x8080032C: jal         0x800FFAB0
    // 0x80800330: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_9;
    // 0x80800330: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_9:
    // 0x80800334: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
L_80800338:
    // 0x80800338: nop

L_8080033C:
    // 0x8080033C: lw          $a0, 0x3C($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X3C);
L_80800340:
    // 0x80800340: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80800344: jal         0x80086C20
    // 0x80800348: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    _chchuffy_entrypoint_1(rdram, ctx);
        goto after_10;
    // 0x80800348: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_10:
    // 0x8080034C: lbu         $t0, 0x65($s5)
    ctx->r8 = MEM_BU(ctx->r21, 0X65);
    // 0x80800350: sll         $t9, $v0, 4
    ctx->r25 = S32(ctx->r2 << 4);
    // 0x80800354: andi        $t8, $t9, 0x10
    ctx->r24 = ctx->r25 & 0X10;
    // 0x80800358: andi        $t7, $t0, 0xFFEF
    ctx->r15 = ctx->r8 & 0XFFEF;
    // 0x8080035C: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x80800360: sb          $t6, 0x65($s5)
    MEM_B(0X65, ctx->r21) = ctx->r14;
    // 0x80800364: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80800368: jal         0x800EE7F8
    // 0x8080036C: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_11;
    // 0x8080036C: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_11:
    // 0x80800370: lui         $a1, 0x3BDA
    ctx->r5 = S32(0X3BDA << 16);
    // 0x80800374: ori         $a1, $a1, 0x740E
    ctx->r5 = ctx->r5 | 0X740E;
    // 0x80800378: jal         0x800EF334
    // 0x8080037C: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    func_800EF334(rdram, ctx);
        goto after_12;
    // 0x8080037C: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    after_12:
    // 0x80800380: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80800384: jal         0x800EF3DC
    // 0x80800388: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EF3DC(rdram, ctx);
        goto after_13;
    // 0x80800388: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_13:
    // 0x8080038C: jal         0x800E3980
    // 0x80800390: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    func_800E3980(rdram, ctx);
        goto after_14;
    // 0x80800390: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    after_14:
    // 0x80800394: lw          $s0, 0x64($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X64);
    // 0x80800398: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8080039C: addiu       $s4, $sp, 0x84
    ctx->r20 = ADD32(ctx->r29, 0X84);
    // 0x808003A0: addiu       $s1, $s0, 0xC
    ctx->r17 = ADD32(ctx->r16, 0XC);
    // 0x808003A4: addiu       $s3, $s0, 0x48
    ctx->r19 = ADD32(ctx->r16, 0X48);
L_808003A8:
    // 0x808003A8: mtc1        $s2, $f10
    ctx->f10.u32l = ctx->r18;
    // 0x808003AC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x808003B0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808003B4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808003B8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1772, 0X520) << 16);
    // 0x808003BC: lwc1        $f6, 0x520($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1772, 0X520));
    // 0x808003C0: lw          $a1, 0x28($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X28);
    // 0x808003C4: lw          $a2, 0x2C($s5)
    ctx->r6 = MEM_W(ctx->r21, 0X2C);
    // 0x808003C8: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x808003CC: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x808003D0: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x808003D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808003D8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808003DC: jal         0x800EF4E4
    // 0x808003E0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800EF4E4(rdram, ctx);
        goto after_15;
    // 0x808003E0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_15:
    // 0x808003E4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x808003E8: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x808003EC: jal         0x800F18FC
    // 0x808003F0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_800F18FC(rdram, ctx);
        goto after_16;
    // 0x808003F0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_16:
    // 0x808003F4: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808003F8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808003FC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800400: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80800404: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800408: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8080040C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80800410: lui         $a1, 0x3BDA
    ctx->r5 = S32(0X3BDA << 16);
    // 0x80800414: swc1        $f20, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f20.u32l;
    // 0x80800418: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8080041C: swc1        $f18, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f18.u32l;
    // 0x80800420: ori         $a1, $a1, 0x740E
    ctx->r5 = ctx->r5 | 0X740E;
    // 0x80800424: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800428: jal         0x800EF334
    // 0x8080042C: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
    func_800EF334(rdram, ctx);
        goto after_17;
    // 0x8080042C: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
    after_17:
    // 0x80800430: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800434: jal         0x800EF3DC
    // 0x80800438: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800EF3DC(rdram, ctx);
        goto after_18;
    // 0x80800438: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_18:
    // 0x8080043C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800440: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800444: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x80800448: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8080044C: addiu       $s3, $s3, 0x10
    ctx->r19 = ADD32(ctx->r19, 0X10);
    // 0x80800450: bne         $s2, $at, L_808003A8
    if (ctx->r18 != ctx->r1) {
        // 0x80800454: addiu       $s4, $s4, 0xC
        ctx->r20 = ADD32(ctx->r20, 0XC);
            goto L_808003A8;
    }
    // 0x80800454: addiu       $s4, $s4, 0xC
    ctx->r20 = ADD32(ctx->r20, 0XC);
    // 0x80800458: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8080045C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80800460: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800464: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80800468: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8080046C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80800470: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80800474: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80800478: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8080047C: jr          $ra
    // 0x80800480: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x80800480: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void func_800C18C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C18C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C18CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C18D0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C18D4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800C18D8: beq         $a0, $zero, L_800C190C
    if (ctx->r4 == 0) {
        // 0x800C18DC: sw          $a3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r7;
            goto L_800C190C;
    }
    // 0x800C18DC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800C18E0: jal         0x800C1448
    // 0x800C18E4: nop

    func_800C1448(rdram, ctx);
        goto after_0;
    // 0x800C18E4: nop

    after_0:
    // 0x800C18E8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800C18EC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800C18F0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800C18F4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800C18F8: jal         0x800C122C
    // 0x800C18FC: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    func_800C122C(rdram, ctx);
        goto after_1;
    // 0x800C18FC: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x800C1900: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800C1904: jal         0x800DC48C
    // 0x800C1908: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800DC48C(rdram, ctx);
        goto after_2;
    // 0x800C1908: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
L_800C190C:
    // 0x800C190C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C1910: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C1914: jr          $ra
    // 0x800C1918: nop

    return;
    // 0x800C1918: nop

;}
