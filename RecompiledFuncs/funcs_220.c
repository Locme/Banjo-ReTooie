#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800D3EC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3EC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D3ECC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D3ED0: jal         0x800D3E14
    // 0x800D3ED4: nop

    func_800D3E14(rdram, ctx);
        goto after_0;
    // 0x800D3ED4: nop

    after_0:
    // 0x800D3ED8: beq         $v0, $zero, L_800D3EE8
    if (ctx->r2 == 0) {
        // 0x800D3EDC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D3EE8;
    }
    // 0x800D3EDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D3EE0: b           L_800D3EEC
    // 0x800D3EE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D3EEC;
    // 0x800D3EE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D3EE8:
    // 0x800D3EE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D3EEC:
    // 0x800D3EEC: jr          $ra
    // 0x800D3EF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800D3EF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800D3574(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3574: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800D3578: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800D357C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800D3580: lbu         $t7, -0x4A9E($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X4A9E);
    // 0x800D3584: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800D3588: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800D358C: bgez        $t7, L_800D35A0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800D3590: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800D35A0;
    }
    // 0x800D3590: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D3594: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800D3598: nop

    // 0x800D359C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800D35A0:
    // 0x800D35A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D35A4: lwc1        $f10, 0x5B10($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5B10);
    // 0x800D35A8: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800D35AC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800D35B0: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x800D35B4: jr          $ra
    // 0x800D35B8: nop

    return;
    // 0x800D35B8: nop

;}
RECOMP_FUNC void suflamefx_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800078: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8080007C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80800080: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x80800084: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80800088: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8080008C: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x80800090: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x80800094: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x80800098: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x8080009C: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x808000A0: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x808000A4: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x808000A8: jal         0x800D8FF8
    // 0x808000AC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808000AC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    after_0:
    // 0x808000B0: lbu         $t6, 0x1B($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X1B);
    // 0x808000B4: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x808000B8: addiu       $s0, $s1, 0x20
    ctx->r16 = ADD32(ctx->r17, 0X20);
    // 0x808000BC: blez        $t6, L_808001AC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x808000C0: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_808001AC;
    }
    // 0x808000C0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x808000C4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3150, 0X520) << 16);
    // 0x808000C8: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x808000CC: lwc1        $f20, 0x520($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3150, 0X520));
    // 0x808000D0: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x808000D4: addiu       $s3, $zero, 0xFF
    ctx->r19 = ADD32(0, 0XFF);
    // 0x808000D8: lwc1        $f0, 0x28($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X28);
L_808000DC:
    // 0x808000DC: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x808000E0: nop

    // 0x808000E4: bc1fl       L_80800134
    if (!c1cs) {
        // 0x808000E8: lbu         $t7, 0x1C($s1)
        ctx->r15 = MEM_BU(ctx->r17, 0X1C);
            goto L_80800134;
    }
    goto skip_0;
    // 0x808000E8: lbu         $t7, 0x1C($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X1C);
    skip_0:
    // 0x808000EC: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808000F0: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x808000F4: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x808000F8: mul.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x808000FC: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80800100: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80800104: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x80800108: lwc1        $f18, 0x10($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8080010C: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80800110: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x80800114: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80800118: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8080011C: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    // 0x80800120: lwc1        $f16, 0x14($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80800124: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80800128: b           L_80800154
    // 0x8080012C: swc1        $f18, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f18.u32l;
        goto L_80800154;
    // 0x8080012C: swc1        $f18, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f18.u32l;
    // 0x80800130: lbu         $t7, 0x1C($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X1C);
L_80800134:
    // 0x80800134: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800138: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080013C: bne         $s4, $t7, L_8080014C
    if (ctx->r20 != ctx->r15) {
        // 0x80800140: nop
    
            goto L_8080014C;
    }
    // 0x80800140: nop

    // 0x80800144: b           L_80800154
    // 0x80800148: swc1        $f22, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f22.u32l;
        goto L_80800154;
    // 0x80800148: swc1        $f22, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f22.u32l;
L_8080014C:
    // 0x8080014C: jal         0x80800428
    // 0x80800150: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_80800428_suflamefx(rdram, ctx);
        goto after_1;
    // 0x80800150: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_1:
L_80800154:
    // 0x80800154: lbu         $t8, 0x1A($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X1A);
    // 0x80800158: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x8080015C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800160: bne         $s3, $t8, L_8080018C
    if (ctx->r19 != ctx->r24) {
        // 0x80800164: nop
    
            goto L_8080018C;
    }
    // 0x80800164: nop

    // 0x80800168: lbu         $v0, 0x2C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2C);
    // 0x8080016C: lbu         $t9, 0x1D($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X1D);
    // 0x80800170: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    // 0x80800174: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80800178: bnel        $at, $zero, L_8080018C
    if (ctx->r1 != 0) {
        // 0x8080017C: sb          $t0, 0x2C($s0)
        MEM_B(0X2C, ctx->r16) = ctx->r8;
            goto L_8080018C;
    }
    goto skip_1;
    // 0x8080017C: sb          $t0, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = ctx->r8;
    skip_1:
    // 0x80800180: b           L_8080018C
    // 0x80800184: sb          $zero, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = 0;
        goto L_8080018C;
    // 0x80800184: sb          $zero, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = 0;
    // 0x80800188: sb          $t0, 0x2C($s0)
    MEM_B(0X2C, ctx->r16) = ctx->r8;
L_8080018C:
    // 0x8080018C: jal         0x800EE780
    // 0x80800190: addiu       $a2, $s0, 0xC
    ctx->r6 = ADD32(ctx->r16, 0XC);
    func_800EE780(rdram, ctx);
        goto after_2;
    // 0x80800190: addiu       $a2, $s0, 0xC
    ctx->r6 = ADD32(ctx->r16, 0XC);
    after_2:
    // 0x80800194: lbu         $t1, 0x1B($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X1B);
    // 0x80800198: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8080019C: addiu       $s0, $s0, 0x30
    ctx->r16 = ADD32(ctx->r16, 0X30);
    // 0x808001A0: slt         $at, $s2, $t1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x808001A4: bnel        $at, $zero, L_808000DC
    if (ctx->r1 != 0) {
        // 0x808001A8: lwc1        $f0, 0x28($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X28);
            goto L_808000DC;
    }
    goto skip_2;
    // 0x808001A8: lwc1        $f0, 0x28($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X28);
    skip_2:
L_808001AC:
    // 0x808001AC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x808001B0: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x808001B4: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x808001B8: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x808001BC: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x808001C0: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x808001C4: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x808001C8: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x808001CC: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x808001D0: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x808001D4: jr          $ra
    // 0x808001D8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x808001D8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void _glsavegame_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088568: syscall     692
    recomp_syscall_handler(rdram, ctx, 0x80088568);
    return;
    // 0x8008856C: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_80800408_chfactorylight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800408: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080040C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800410: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800414: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800418: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080041C: jal         0x80100094
    // 0x80800420: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800420: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800424: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800428: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080042C: addiu       $s2, $zero, 0x8
    ctx->r18 = ADD32(0, 0X8);
L_80800430:
    // 0x80800430: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800434: beql        $a0, $zero, L_8080044C
    if (ctx->r4 == 0) {
        // 0x80800438: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8080044C;
    }
    goto skip_0;
    // 0x80800438: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    skip_0:
    // 0x8080043C: jal         0x800C8B84
    // 0x80800440: nop

    func_800C8B84(rdram, ctx);
        goto after_1;
    // 0x80800440: nop

    after_1:
    // 0x80800444: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80800448: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8080044C:
    // 0x8080044C: bne         $s1, $s2, L_80800430
    if (ctx->r17 != ctx->r18) {
        // 0x80800450: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80800430;
    }
    // 0x80800450: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800454: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800458: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080045C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800460: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800464: jr          $ra
    // 0x80800468: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800468: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80092BC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092BC4: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x80092BC8: jr          $ra
    // 0x80092BCC: lbu         $v0, 0xC4($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0XC4);
    return;
    // 0x80092BCC: lbu         $v0, 0xC4($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0XC4);
;}
RECOMP_FUNC void func_800D7460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D7460: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D7464: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D7468: jal         0x800D743C
    // 0x800D746C: nop

    func_800D743C(rdram, ctx);
        goto after_0;
    // 0x800D746C: nop

    after_0:
    // 0x800D7470: jal         0x800D7418
    // 0x800D7474: nop

    func_800D7418(rdram, ctx);
        goto after_1;
    // 0x800D7474: nop

    after_1:
    // 0x800D7478: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D747C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D7480: jr          $ra
    // 0x800D7484: nop

    return;
    // 0x800D7484: nop

;}
RECOMP_FUNC void func_808019A4_chsabreman(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808019A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808019A8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x808019AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808019B0: beq         $a1, $at, L_808019CC
    if (ctx->r5 == ctx->r1) {
        // 0x808019B4: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_808019CC;
    }
    // 0x808019B4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808019B8: addiu       $at, $zero, 0x48
    ctx->r1 = ADD32(0, 0X48);
    // 0x808019BC: beql        $a1, $at, L_808019E0
    if (ctx->r5 == ctx->r1) {
        // 0x808019C0: lbu         $t7, 0x65($a0)
        ctx->r15 = MEM_BU(ctx->r4, 0X65);
            goto L_808019E0;
    }
    goto skip_0;
    // 0x808019C0: lbu         $t7, 0x65($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X65);
    skip_0:
    // 0x808019C4: b           L_808019F8
    // 0x808019C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808019F8;
    // 0x808019C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808019CC:
    // 0x808019CC: jal         0x80102424
    // 0x808019D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x808019D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x808019D4: b           L_808019F8
    // 0x808019D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808019F8;
    // 0x808019D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808019DC: lbu         $t7, 0x65($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X65);
L_808019E0:
    // 0x808019E0: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x808019E4: b           L_808019F4
    // 0x808019E8: sb          $t8, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r24;
        goto L_808019F4;
    // 0x808019E8: sb          $t8, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r24;
    // 0x808019EC: b           L_808019F8
    // 0x808019F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808019F8;
    // 0x808019F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808019F4:
    // 0x808019F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808019F8:
    // 0x808019F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808019FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801A00: jr          $ra
    // 0x80801A04: nop

    return;
    // 0x80801A04: nop

    // 0x80801A08: nop

    // 0x80801A0C: nop

;}
RECOMP_FUNC void func_80800230_chballoonbomb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800230: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800234: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800238: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080023C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800240: jal         0x800D8FF8
    // 0x80800244: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800244: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800248: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8080024C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800250: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800254: lui         $a1, 0x50
    ctx->r5 = S32(0X50 << 16);
    // 0x80800258: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8080025C: lwc1        $f4, 0x2C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x80800260: ori         $a1, $a1, 0x7
    ctx->r5 = ctx->r5 | 0X7;
    // 0x80800264: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80800268: jal         0x8010B990
    // 0x8080026C: swc1        $f10, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f10.u32l;
    func_8010B990(rdram, ctx);
        goto after_1;
    // 0x8080026C: swc1        $f10, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f10.u32l;
    after_1:
    // 0x80800270: andi        $t6, $v0, 0x20
    ctx->r14 = ctx->r2 & 0X20;
    // 0x80800274: beq         $t6, $zero, L_80800284
    if (ctx->r14 == 0) {
        // 0x80800278: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800284;
    }
    // 0x80800278: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080027C: jal         0x80800294
    // 0x80800280: nop

    func_80800294_chballoonbomb(rdram, ctx);
        goto after_2;
    // 0x80800280: nop

    after_2:
L_80800284:
    // 0x80800284: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800288: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080028C: jr          $ra
    // 0x80800290: nop

    return;
    // 0x80800290: nop

;}
RECOMP_FUNC void func_80800000_chwandglow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800004: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800008: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080000C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80800014: lw          $a0, 0x6C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C);
    // 0x80800018: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x8080001C: andi        $t6, $a0, 0x1FF
    ctx->r14 = ctx->r4 & 0X1FF;
    // 0x80800020: jal         0x800F5A00
    // 0x80800024: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_800F5A00(rdram, ctx);
        goto after_0;
    // 0x80800024: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x80800028: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x8080002C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80800030: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x80800034: andi        $t7, $a0, 0x1FF
    ctx->r15 = ctx->r4 & 0X1FF;
    // 0x80800038: jal         0x800F5A2C
    // 0x8080003C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_800F5A2C(rdram, ctx);
        goto after_1;
    // 0x8080003C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_1:
    // 0x80800040: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80800044: jal         0x800EECE0
    // 0x80800048: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800EECE0(rdram, ctx);
        goto after_2;
    // 0x80800048: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_2:
    // 0x8080004C: bne         $v0, $zero, L_8080005C
    if (ctx->r2 != 0) {
        // 0x80800050: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_8080005C;
    }
    // 0x80800050: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800054: jal         0x800EE7F8
    // 0x80800058: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800058: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_3:
L_8080005C:
    // 0x8080005C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800060: addiu       $t8, $s0, 0x4
    ctx->r24 = ADD32(ctx->r16, 0X4);
    // 0x80800064: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x80800068: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x8080006C: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80800070: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80800074: jal         0x800EFA4C
    // 0x80800078: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    func_800EFA4C(rdram, ctx);
        goto after_4;
    // 0x80800078: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_4:
    // 0x8080007C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800080: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80800084: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800088: lwc1        $f12, 0x2C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8080008C: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80800090: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800094: jal         0x800F10B4
    // 0x80800098: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_5;
    // 0x80800098: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x8080009C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808000A0: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x808000A4: jal         0x800DF410
    // 0x808000A8: nop

    func_800DF410(rdram, ctx);
        goto after_6;
    // 0x808000A8: nop

    after_6:
    // 0x808000AC: jal         0x800DF830
    // 0x808000B0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800DF830(rdram, ctx);
        goto after_7;
    // 0x808000B0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_7:
    // 0x808000B4: jal         0x801039E4
    // 0x808000B8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_801039E4(rdram, ctx);
        goto after_8;
    // 0x808000B8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_8:
    // 0x808000BC: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x808000C0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x808000C4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808000C8: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x808000CC: jal         0x800DE448
    // 0x808000D0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800DE448(rdram, ctx);
        goto after_9;
    // 0x808000D0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_9:
    // 0x808000D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808000D8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808000DC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x808000E0: jr          $ra
    // 0x808000E4: nop

    return;
    // 0x808000E4: nop

;}
RECOMP_FUNC void func_80024DD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024DD8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80024DDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80024DE0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80024DE4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80024DE8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80024DEC: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x80024DF0: bne         $t7, $at, L_80024E04
    if (ctx->r15 != ctx->r1) {
        // 0x80024DF4: nop
    
            goto L_80024E04;
    }
    // 0x80024DF4: nop

    // 0x80024DF8: lw          $t8, 0x18($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X18);
    // 0x80024DFC: bne         $t8, $zero, L_80024E0C
    if (ctx->r24 != 0) {
        // 0x80024E00: nop
    
            goto L_80024E0C;
    }
    // 0x80024E00: nop

L_80024E04:
    // 0x80024E04: b           L_80024E60
    // 0x80024E08: nop

        goto L_80024E60;
    // 0x80024E08: nop

L_80024E0C:
    // 0x80024E0C: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80024E10: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80024E14: jal         0x8002ABE0
    // 0x80024E18: lw          $a0, 0x18($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X18);
    func_8002ABE0(rdram, ctx);
        goto after_0;
    // 0x80024E18: lw          $a0, 0x18($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X18);
    after_0:
    // 0x80024E1C: bne         $v0, $zero, L_80024E2C
    if (ctx->r2 != 0) {
        // 0x80024E20: nop
    
            goto L_80024E2C;
    }
    // 0x80024E20: nop

    // 0x80024E24: b           L_80024E60
    // 0x80024E28: nop

        goto L_80024E60;
    // 0x80024E28: nop

L_80024E2C:
    // 0x80024E2C: sh          $zero, 0x20($sp)
    MEM_H(0X20, ctx->r29) = 0;
    // 0x80024E30: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80024E34: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80024E38: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80024E3C: lw          $t1, 0x24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X24);
    // 0x80024E40: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80024E44: addiu       $a0, $t0, 0x48
    ctx->r4 = ADD32(ctx->r8, 0X48);
    // 0x80024E48: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80024E4C: mflo        $a2
    ctx->r6 = lo;
    // 0x80024E50: jal         0x80026500
    // 0x80024E54: nop

    func_80026500(rdram, ctx);
        goto after_1;
    // 0x80024E54: nop

    after_1:
    // 0x80024E58: b           L_80024E60
    // 0x80024E5C: nop

        goto L_80024E60;
    // 0x80024E5C: nop

L_80024E60:
    // 0x80024E60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80024E64: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80024E68: jr          $ra
    // 0x80024E6C: nop

    return;
    // 0x80024E6C: nop

;}
RECOMP_FUNC void chbaddiesetup_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808000B0: jal         0x800A5D60
    // 0x808000B4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800A5D60(rdram, ctx);
        goto after_0;
    // 0x808000B4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x808000B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000BC: jal         0x80800000
    // 0x808000C0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80800000_chbaddiesetup(rdram, ctx);
        goto after_1;
    // 0x808000C0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808000C4: beq         $v0, $zero, L_80800120
    if (ctx->r2 == 0) {
        // 0x808000C8: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80800120;
    }
    // 0x808000C8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808000CC: lbu         $t8, 0x4($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X4);
    // 0x808000D0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x808000D4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808000D8: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x808000DC: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x808000E0: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x808000E4: lbu         $t3, 0x4($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X4);
    // 0x808000E8: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x808000EC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x808000F0: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x808000F4: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x808000F8: sw          $t1, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r9;
    // 0x808000FC: lbu         $t9, 0x4($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X4);
    // 0x80800100: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80800104: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80800108: sll         $t6, $t9, 5
    ctx->r14 = S32(ctx->r25 << 5);
    // 0x8080010C: addu        $t0, $t7, $t6
    ctx->r8 = ADD32(ctx->r15, ctx->r14);
    // 0x80800110: sw          $t8, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r24;
    // 0x80800114: lbu         $t3, 0x4($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X4);
    // 0x80800118: addiu       $t2, $t3, 0x1
    ctx->r10 = ADD32(ctx->r11, 0X1);
    // 0x8080011C: sb          $t2, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r10;
L_80800120:
    // 0x80800120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800124: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800128: jr          $ra
    // 0x8080012C: nop

    return;
    // 0x8080012C: nop

;}
RECOMP_FUNC void func_80800390_bsbanswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800390: addiu       $at, $zero, 0x81
    ctx->r1 = ADD32(0, 0X81);
    // 0x80800394: beq         $a0, $at, L_808003AC
    if (ctx->r4 == ctx->r1) {
        // 0x80800398: addiu       $at, $zero, 0x82
        ctx->r1 = ADD32(0, 0X82);
            goto L_808003AC;
    }
    // 0x80800398: addiu       $at, $zero, 0x82
    ctx->r1 = ADD32(0, 0X82);
    // 0x8080039C: beq         $a0, $at, L_808003AC
    if (ctx->r4 == ctx->r1) {
        // 0x808003A0: addiu       $at, $zero, 0x90
        ctx->r1 = ADD32(0, 0X90);
            goto L_808003AC;
    }
    // 0x808003A0: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x808003A4: bne         $a0, $at, L_808003B4
    if (ctx->r4 != ctx->r1) {
        // 0x808003A8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808003B4;
    }
    // 0x808003A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808003AC:
    // 0x808003AC: jr          $ra
    // 0x808003B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x808003B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003B4:
    // 0x808003B4: jr          $ra
    // 0x808003B8: nop

    return;
    // 0x808003B8: nop

;}
RECOMP_FUNC void chbounce_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800048: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080004C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800050: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800054: jal         0x800EE84C
    // 0x80800058: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800EE84C(rdram, ctx);
        goto after_0;
    // 0x80800058: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8080005C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800060: jal         0x80800664
    // 0x80800064: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    chbounce_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800064: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x80800068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080006C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800070: jr          $ra
    // 0x80800074: nop

    return;
    // 0x80800074: nop

;}
RECOMP_FUNC void chmolehill_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A38: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1560, 0XB70) << 16);
    // 0x80800A3C: jr          $ra
    // 0x80800A40: addiu       $v0, $v0, 0xB70
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1560, 0XB70));
    return;
    // 0x80800A40: addiu       $v0, $v0, 0xB70
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1560, 0XB70));
    // 0x80800A44: nop

    // 0x80800A48: nop

    // 0x80800A4C: nop

;}
RECOMP_FUNC void func_80801D30_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801D30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801D34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801D38: jal         0x80800104
    // 0x80801D3C: nop

    func_80800104_bsbswim(rdram, ctx);
        goto after_0;
    // 0x80801D3C: nop

    after_0:
    // 0x80801D40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801D44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801D48: jr          $ra
    // 0x80801D4C: nop

    return;
    // 0x80801D4C: nop

;}
RECOMP_FUNC void _chfiregen_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800869F0: syscall     404
    recomp_syscall_handler(rdram, ctx, 0x800869F0);
    return;
    // 0x800869F4: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void boot_osCreateMesgQueue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80101180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101180: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80101184: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80101188: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8010118C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80101190: addiu       $s4, $sp, 0x38
    ctx->r20 = ADD32(ctx->r29, 0X38);
    // 0x80101194: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80101198: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8010119C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801011A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801011A4: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x801011A8: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x801011AC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801011B0: jal         0x801067C4
    // 0x801011B4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_801067C4(rdram, ctx);
        goto after_0;
    // 0x801011B4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_0:
    // 0x801011B8: beq         $v0, $zero, L_80101214
    if (ctx->r2 == 0) {
        // 0x801011BC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80101214;
    }
    // 0x801011BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_801011C0:
    // 0x801011C0: lw          $t6, 0x64($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X64);
    // 0x801011C4: sll         $t8, $t6, 14
    ctx->r24 = S32(ctx->r14 << 14);
    // 0x801011C8: bltz        $t8, L_80101204
    if (SIGNED(ctx->r24) < 0) {
        // 0x801011CC: nop
    
            goto L_80101204;
    }
    // 0x801011CC: nop

    // 0x801011D0: lw          $t9, 0x6C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X6C);
    // 0x801011D4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x801011D8: sll         $t0, $t9, 11
    ctx->r8 = S32(ctx->r25 << 11);
    // 0x801011DC: srl         $t1, $t0, 20
    ctx->r9 = S32(U32(ctx->r8) >> 20);
    // 0x801011E0: bne         $s1, $t1, L_80101204
    if (ctx->r17 != ctx->r9) {
        // 0x801011E4: nop
    
            goto L_80101204;
    }
    // 0x801011E4: nop

    // 0x801011E8: jal         0x8010108C
    // 0x801011EC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_8010108C(rdram, ctx);
        goto after_1;
    // 0x801011EC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_1:
    // 0x801011F0: blez        $v0, L_80101204
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801011F4: nop
    
            goto L_80101204;
    }
    // 0x801011F4: nop

    // 0x801011F8: bne         $s0, $zero, L_80101204
    if (ctx->r16 != 0) {
        // 0x801011FC: nop
    
            goto L_80101204;
    }
    // 0x801011FC: nop

    // 0x80101200: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80101204:
    // 0x80101204: jal         0x8010682C
    // 0x80101208: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_8010682C(rdram, ctx);
        goto after_2;
    // 0x80101208: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_2:
    // 0x8010120C: bne         $v0, $zero, L_801011C0
    if (ctx->r2 != 0) {
        // 0x80101210: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_801011C0;
    }
    // 0x80101210: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80101214:
    // 0x80101214: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80101218: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8010121C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80101220: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80101224: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80101228: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8010122C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80101230: jr          $ra
    // 0x80101234: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80101234: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void _ncbaspline_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800893A0: syscall     776
    recomp_syscall_handler(rdram, ctx, 0x800893A0);
    return;
    // 0x800893A4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800000_bskazstill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lw          $v1, 0x160($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X160);
    // 0x80800004: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(288, 0X8A0) << 16);
    // 0x80800008: sltiu       $at, $v1, 0x4
    ctx->r1 = ctx->r3 < 0X4 ? 1 : 0;
    // 0x8080000C: bnel        $at, $zero, L_80800020
    if (ctx->r1 != 0) {
        // 0x80800010: addu        $a1, $a1, $v1
        ctx->r5 = ADD32(ctx->r5, ctx->r3);
            goto L_80800020;
    }
    goto skip_0;
    // 0x80800010: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    skip_0:
    // 0x80800014: sw          $zero, 0x160($a0)
    MEM_W(0X160, ctx->r4) = 0;
    // 0x80800018: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8080001C: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
L_80800020:
    // 0x80800020: lbu         $v0, 0x8A0($a1)
    ctx->r2 = MEM_BU(ctx->r5, (int16_t)RELOC_LO16(288, 0X8A0));
    // 0x80800024: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x80800028: jr          $ra
    // 0x8080002C: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
    return;
    // 0x8080002C: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void _bsfirstp_entrypoint_37(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800843B0: syscall     108
    recomp_syscall_handler(rdram, ctx, 0x800843B0);
    return;
    // 0x800843B4: addi        $t0, $zero, 0x94
    ctx->r8 = ADD32(0, 0X94);
;}
RECOMP_FUNC void func_800A9C98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9C98: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A9C9C: lbu         $v0, 0x7760($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7760);
    // 0x800A9CA0: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x800A9CA4: jr          $ra
    // 0x800A9CA8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    return;
    // 0x800A9CA8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
;}
RECOMP_FUNC void func_800F12D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F12D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F12D8: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800F12DC: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x800F12E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F12E4: addiu       $t6, $t6, 0x1434
    ctx->r14 = ADD32(ctx->r14, 0X1434);
    // 0x800F12E8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800F12EC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800F12F0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800F12F4: jal         0x800F1274
    // 0x800F12F8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F1274(rdram, ctx);
        goto after_0;
    // 0x800F12F8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x800F12FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F1300: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F1304: jr          $ra
    // 0x800F1308: nop

    return;
    // 0x800F1308: nop

;}
RECOMP_FUNC void func_800F59D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F59D4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F59D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F59DC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F59E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F59E4: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F59E8: jal         0x80084768
    // 0x800F59EC: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    _bapackctrl_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x800F59EC: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F59F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F59F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F59F8: jr          $ra
    // 0x800F59FC: nop

    return;
    // 0x800F59FC: nop

;}
RECOMP_FUNC void _bstrexsmall_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800840B0: syscall     102
    recomp_syscall_handler(rdram, ctx, 0x800840B0);
    return;
    // 0x800840B4: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void _cadbio_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085578: syscall     168
    recomp_syscall_handler(rdram, ctx, 0x80085578);
    return;
    // 0x8008557C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _bahold_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084D50: syscall     134
    recomp_syscall_handler(rdram, ctx, 0x80084D50);
    return;
    // 0x80084D54: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void chdingpot_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1176, 0X500) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x500
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1176, 0X500));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x500
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1176, 0X500));
;}
RECOMP_FUNC void chjigsawdance_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800430: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(708, 0X488) << 16);
    // 0x80800434: jr          $ra
    // 0x80800438: addiu       $v0, $v0, 0x488
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(708, 0X488));
    return;
    // 0x80800438: addiu       $v0, $v0, 0x488
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(708, 0X488));
    // 0x8080043C: nop

;}
RECOMP_FUNC void func_80801BA4_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801BA4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801BA8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801BAC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801BB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801BB4: jal         0x8009BB00
    // 0x80801BB8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_0;
    // 0x80801BB8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_0:
    // 0x80801BBC: jal         0x800D8FF8
    // 0x80801BC0: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80801BC0: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80801BC4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(443, 0X1D4C) << 16);
    // 0x80801BC8: lwc1        $f4, 0x1D4C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(443, 0X1D4C));
    // 0x80801BCC: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80801BD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801BD4: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80801BD8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80801BDC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80801BE0: jal         0x8009B9B0
    // 0x80801BE4: nop

    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x80801BE4: nop

    after_2:
    // 0x80801BE8: lui         $a1, 0x3E06
    ctx->r5 = S32(0X3E06 << 16);
    // 0x80801BEC: ori         $a1, $a1, 0xAA6
    ctx->r5 = ctx->r5 | 0XAA6;
    // 0x80801BF0: jal         0x8008CB10
    // 0x80801BF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_3;
    // 0x80801BF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801BF8: beq         $v0, $zero, L_80801C58
    if (ctx->r2 == 0) {
        // 0x80801BFC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801C58;
    }
    // 0x80801BFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C00: lui         $a2, 0x3F86
    ctx->r6 = S32(0X3F86 << 16);
    // 0x80801C04: lui         $a3, 0x3F93
    ctx->r7 = S32(0X3F93 << 16);
    // 0x80801C08: addiu       $t6, $zero, 0x4E20
    ctx->r14 = ADD32(0, 0X4E20);
    // 0x80801C0C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801C10: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x80801C14: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80801C18: jal         0x8009DBB0
    // 0x80801C1C: addiu       $a1, $zero, 0x573
    ctx->r5 = ADD32(0, 0X573);
    func_8009DBB0(rdram, ctx);
        goto after_4;
    // 0x80801C1C: addiu       $a1, $zero, 0x573
    ctx->r5 = ADD32(0, 0X573);
    after_4:
    // 0x80801C20: lui         $a2, 0x3F59
    ctx->r6 = S32(0X3F59 << 16);
    // 0x80801C24: lui         $a3, 0x3F73
    ctx->r7 = S32(0X3F73 << 16);
    // 0x80801C28: addiu       $t7, $zero, 0x4E20
    ctx->r15 = ADD32(0, 0X4E20);
    // 0x80801C2C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80801C30: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x80801C34: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80801C38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C3C: jal         0x8009DBB0
    // 0x80801C40: addiu       $a1, $zero, 0x406
    ctx->r5 = ADD32(0, 0X406);
    func_8009DBB0(rdram, ctx);
        goto after_5;
    // 0x80801C40: addiu       $a1, $zero, 0x406
    ctx->r5 = ADD32(0, 0X406);
    after_5:
    // 0x80801C44: jal         0x80085428
    // 0x80801C48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bawasher_entrypoint_7(rdram, ctx);
        goto after_6;
    // 0x80801C48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80801C4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C50: jal         0x8009D2D8
    // 0x80801C54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009D2D8(rdram, ctx);
        goto after_7;
    // 0x80801C54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
L_80801C58:
    // 0x80801C58: jal         0x8008CAEC
    // 0x80801C5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_8;
    // 0x80801C5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80801C60: beq         $v0, $zero, L_80801C6C
    if (ctx->r2 == 0) {
        // 0x80801C64: addiu       $t8, $zero, 0x32
        ctx->r24 = ADD32(0, 0X32);
            goto L_80801C6C;
    }
    // 0x80801C64: addiu       $t8, $zero, 0x32
    ctx->r24 = ADD32(0, 0X32);
    // 0x80801C68: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_80801C6C:
    // 0x80801C6C: jal         0x8008CAC8
    // 0x80801C70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getTimer(rdram, ctx);
        goto after_9;
    // 0x80801C70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80801C74: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(443, 0X1D50) << 16);
    // 0x80801C78: lwc1        $f16, 0x1D50($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(443, 0X1D50));
    // 0x80801C7C: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80801C80: nop

    // 0x80801C84: bc1fl       L_80801CBC
    if (!c1cs) {
        // 0x80801C88: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801CBC;
    }
    goto skip_0;
    // 0x80801C88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80801C8C: jal         0x8009EF10
    // 0x80801C90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_10;
    // 0x80801C90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80801C94: beq         $v0, $zero, L_80801CA4
    if (ctx->r2 == 0) {
        // 0x80801C98: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801CA4;
    }
    // 0x80801C98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C9C: addiu       $t9, $zero, 0x33
    ctx->r25 = ADD32(0, 0X33);
    // 0x80801CA0: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
L_80801CA4:
    // 0x80801CA4: jal         0x80091A58
    // 0x80801CA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_pressed(rdram, ctx);
        goto after_11;
    // 0x80801CA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80801CAC: beq         $v0, $zero, L_80801CB8
    if (ctx->r2 == 0) {
        // 0x80801CB0: addiu       $t0, $zero, 0x38
        ctx->r8 = ADD32(0, 0X38);
            goto L_80801CB8;
    }
    // 0x80801CB0: addiu       $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
    // 0x80801CB4: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
L_80801CB8:
    // 0x80801CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801CBC:
    // 0x80801CBC: jal         0x8009E5C8
    // 0x80801CC0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    bs_setState(rdram, ctx);
        goto after_12;
    // 0x80801CC0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_12:
    // 0x80801CC4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801CC8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801CCC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80801CD0: jr          $ra
    // 0x80801CD4: nop

    return;
    // 0x80801CD4: nop

;}
RECOMP_FUNC void bafpctrl_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D1C: lw          $t6, 0x90($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X90);
    // 0x80800D20: jal         0x80084AE0
    // 0x80800D24: sb          $a1, 0x13($t6)
    MEM_B(0X13, ctx->r14) = ctx->r5;
    _baeggcursor_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x80800D24: sb          $a1, 0x13($t6)
    MEM_B(0X13, ctx->r14) = ctx->r5;
    after_0:
    // 0x80800D28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D30: jr          $ra
    // 0x80800D34: nop

    return;
    // 0x80800D34: nop

;}
RECOMP_FUNC void func_80807304_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80807304: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80807308: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080730C: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80807310: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80807314: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80807318: jal         0x80100094
    // 0x8080731C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080731C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80807320: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80807324: jal         0x80802228
    // 0x80807328: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x80807328: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    after_1:
    // 0x8080732C: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x80807330: jal         0x80802248
    // 0x80807334: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    func_80802248_chdiggerboss(rdram, ctx);
        goto after_2;
    // 0x80807334: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    after_2:
    // 0x80807338: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x8080733C: jal         0x8080761C
    // 0x80807340: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    func_8080761C_chdiggerboss(rdram, ctx);
        goto after_3;
    // 0x80807340: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    after_3:
    // 0x80807344: beq         $v0, $zero, L_80807414
    if (ctx->r2 == 0) {
        // 0x80807348: lw          $a0, 0x58($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X58);
            goto L_80807414;
    }
    // 0x80807348: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8080734C: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x80807350: jal         0x8010CD50
    // 0x80807354: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    func_8010CD50(rdram, ctx);
        goto after_4;
    // 0x80807354: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_4:
    // 0x80807358: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x8080735C: lh          $t6, 0x8A($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X8A);
    // 0x80807360: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x80807364: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80807368: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8080736C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80807370: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80807374: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80807378: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x8080737C: lh          $t7, 0x8C($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X8C);
    // 0x80807380: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80807384: nop

    // 0x80807388: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8080738C: bne         $t8, $at, L_808073A4
    if (ctx->r24 != ctx->r1) {
        // 0x80807390: swc1        $f10, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
            goto L_808073A4;
    }
    // 0x80807390: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x80807394: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x80807398: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080739C: b           L_808073B4
    // 0x808073A0: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
        goto L_808073B4;
    // 0x808073A0: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
L_808073A4:
    // 0x808073A4: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808073A8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808073AC: nop

    // 0x808073B0: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
L_808073B4:
    // 0x808073B4: jal         0x8010D09C
    // 0x808073B8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_8010D09C(rdram, ctx);
        goto after_5;
    // 0x808073B8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_5:
    // 0x808073BC: lui         $at, 0xC2A0
    ctx->r1 = S32(0XC2A0 << 16);
    // 0x808073C0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808073C4: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x808073C8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808073CC: jal         0x800DC178
    // 0x808073D0: nop

    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x808073D0: nop

    after_6:
    // 0x808073D4: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x808073D8: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808073DC: jal         0x800DC178
    // 0x808073E0: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    func_800DC178(rdram, ctx);
        goto after_7;
    // 0x808073E0: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    after_7:
    // 0x808073E4: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808073E8: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808073EC: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808073F0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808073F4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808073F8: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x808073FC: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80807400: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80807404: jal         0x800EF1B8
    // 0x80807408: nop

    func_800EF1B8(rdram, ctx);
        goto after_8;
    // 0x80807408: nop

    after_8:
    // 0x8080740C: b           L_80807424
    // 0x80807410: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
        goto L_80807424;
    // 0x80807410: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_80807414:
    // 0x80807414: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80807418: jal         0x8010D09C
    // 0x8080741C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8010D09C(rdram, ctx);
        goto after_9;
    // 0x8080741C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_9:
    // 0x80807420: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_80807424:
    // 0x80807424: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80807428: jal         0x800EEFD4
    // 0x8080742C: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    func_800EEFD4(rdram, ctx);
        goto after_10;
    // 0x8080742C: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    after_10:
    // 0x80807430: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9C0C) << 16);
    // 0x80807434: lwc1        $f4, -0x63F4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9C0C));
    // 0x80807438: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8080743C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80807440: nop

    // 0x80807444: bc1fl       L_80807458
    if (!c1cs) {
        // 0x80807448: lw          $t9, 0x68($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X68);
            goto L_80807458;
    }
    goto skip_0;
    // 0x80807448: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    skip_0:
    // 0x8080744C: jal         0x800EF368
    // 0x80807450: lui         $a1, 0x44E1
    ctx->r5 = S32(0X44E1 << 16);
    func_800EF368(rdram, ctx);
        goto after_11;
    // 0x80807450: lui         $a1, 0x44E1
    ctx->r5 = S32(0X44E1 << 16);
    after_11:
    // 0x80807454: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
L_80807458:
    // 0x80807458: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x8080745C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80807460: lwc1        $f6, 0x8($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X8);
    // 0x80807464: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80807468: beq         $t0, $at, L_80807484
    if (ctx->r8 == ctx->r1) {
        // 0x8080746C: swc1        $f6, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
            goto L_80807484;
    }
    // 0x8080746C: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x80807470: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80807474: beq         $t0, $at, L_8080752C
    if (ctx->r8 == ctx->r1) {
        // 0x80807478: lw          $a0, 0x60($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X60);
            goto L_8080752C;
    }
    // 0x80807478: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8080747C: b           L_808075C4
    // 0x80807480: nop

        goto L_808075C4;
    // 0x80807480: nop

L_80807484:
    // 0x80807484: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80807488: jal         0x808008C0
    // 0x8080748C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_808008C0_chdiggerboss(rdram, ctx);
        goto after_12;
    // 0x8080748C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
    // 0x80807490: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x80807494: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80807498: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    // 0x8080749C: jal         0x8008A0E0
    // 0x808074A0: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_13;
    // 0x808074A0: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    after_13:
    // 0x808074A4: addiu       $a0, $zero, 0x4F3
    ctx->r4 = ADD32(0, 0X4F3);
    // 0x808074A8: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x808074AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808074B0: jal         0x80108528
    // 0x808074B4: addiu       $a3, $sp, 0x68
    ctx->r7 = ADD32(ctx->r29, 0X68);
    func_80108528(rdram, ctx);
        goto after_14;
    // 0x808074B4: addiu       $a3, $sp, 0x68
    ctx->r7 = ADD32(ctx->r29, 0X68);
    after_14:
    // 0x808074B8: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x808074BC: addiu       $a0, $v0, 0x18
    ctx->r4 = ADD32(ctx->r2, 0X18);
    // 0x808074C0: jal         0x800EE7F8
    // 0x808074C4: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800EE7F8(rdram, ctx);
        goto after_15;
    // 0x808074C4: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_15:
    // 0x808074C8: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x808074CC: jal         0x80102FDC
    // 0x808074D0: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    func_80102FDC(rdram, ctx);
        goto after_16;
    // 0x808074D0: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    after_16:
    // 0x808074D4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x808074D8: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x808074DC: swc1        $f10, 0x54($t2)
    MEM_W(0X54, ctx->r10) = ctx->f10.u32l;
    // 0x808074E0: lh          $t4, 0x96($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X96);
    // 0x808074E4: lh          $t3, 0x94($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X94);
    // 0x808074E8: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x808074EC: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x808074F0: cvt.s.w     $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808074F4: jal         0x800DC178
    // 0x808074F8: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    func_800DC178(rdram, ctx);
        goto after_17;
    // 0x808074F8: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    after_17:
    // 0x808074FC: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x80807500: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0XA140) << 16);
    // 0x80807504: addiu       $a2, $a2, -0x5EC0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0XA140));
    // 0x80807508: swc1        $f0, 0x24($t5)
    MEM_W(0X24, ctx->r13) = ctx->f0.u32l;
    // 0x8080750C: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x80807510: jal         0x80089D18
    // 0x80807514: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_18;
    // 0x80807514: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_18:
    // 0x80807518: lh          $v0, 0x7E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X7E);
    // 0x8080751C: blez        $v0, L_808075C4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80807520: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_808075C4;
    }
    // 0x80807520: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x80807524: b           L_808075C4
    // 0x80807528: sh          $t7, 0x7E($s0)
    MEM_H(0X7E, ctx->r16) = ctx->r15;
        goto L_808075C4;
    // 0x80807528: sh          $t7, 0x7E($s0)
    MEM_H(0X7E, ctx->r16) = ctx->r15;
L_8080752C:
    // 0x8080752C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80807530: jal         0x808008C0
    // 0x80807534: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_808008C0_chdiggerboss(rdram, ctx);
        goto after_19;
    // 0x80807534: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_19:
    // 0x80807538: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8080753C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80807540: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    // 0x80807544: jal         0x8008A0E0
    // 0x80807548: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_20;
    // 0x80807548: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_20:
    // 0x8080754C: addiu       $a0, $zero, 0x4F3
    ctx->r4 = ADD32(0, 0X4F3);
    // 0x80807550: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80807554: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80807558: jal         0x80108528
    // 0x8080755C: addiu       $a3, $sp, 0x68
    ctx->r7 = ADD32(ctx->r29, 0X68);
    func_80108528(rdram, ctx);
        goto after_21;
    // 0x8080755C: addiu       $a3, $sp, 0x68
    ctx->r7 = ADD32(ctx->r29, 0X68);
    after_21:
    // 0x80807560: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x80807564: addiu       $a0, $v0, 0x18
    ctx->r4 = ADD32(ctx->r2, 0X18);
    // 0x80807568: jal         0x800EE7F8
    // 0x8080756C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800EE7F8(rdram, ctx);
        goto after_22;
    // 0x8080756C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_22:
    // 0x80807570: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80807574: jal         0x80102FDC
    // 0x80807578: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    func_80102FDC(rdram, ctx);
        goto after_23;
    // 0x80807578: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    after_23:
    // 0x8080757C: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80807580: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80807584: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x80807588: swc1        $f18, 0x54($t9)
    MEM_W(0X54, ctx->r25) = ctx->f18.u32l;
    // 0x8080758C: lh          $t1, 0x96($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X96);
    // 0x80807590: lh          $t0, 0x94($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X94);
    // 0x80807594: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80807598: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8080759C: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808075A0: jal         0x800DC178
    // 0x808075A4: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    func_800DC178(rdram, ctx);
        goto after_24;
    // 0x808075A4: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_24:
    // 0x808075A8: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x808075AC: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0XA140) << 16);
    // 0x808075B0: addiu       $a2, $a2, -0x5EC0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0XA140));
    // 0x808075B4: swc1        $f0, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->f0.u32l;
    // 0x808075B8: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x808075BC: jal         0x80089D18
    // 0x808075C0: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_25;
    // 0x808075C0: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_25:
L_808075C4:
    // 0x808075C4: jal         0x8080761C
    // 0x808075C8: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    func_8080761C_chdiggerboss(rdram, ctx);
        goto after_26;
    // 0x808075C8: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    after_26:
    // 0x808075CC: beq         $v0, $zero, L_808075E0
    if (ctx->r2 == 0) {
        // 0x808075D0: lw          $t4, 0x6C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X6C);
            goto L_808075E0;
    }
    // 0x808075D0: lw          $t4, 0x6C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X6C);
    // 0x808075D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808075D8: bnel        $t4, $at, L_8080760C
    if (ctx->r12 != ctx->r1) {
        // 0x808075DC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080760C;
    }
    goto skip_1;
    // 0x808075DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
L_808075E0:
    // 0x808075E0: lh          $t5, 0x7E($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X7E);
    // 0x808075E4: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x808075E8: bnel        $t5, $zero, L_808075FC
    if (ctx->r13 != 0) {
        // 0x808075EC: lwc1        $f10, 0x90($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X90);
            goto L_808075FC;
    }
    goto skip_2;
    // 0x808075EC: lwc1        $f10, 0x90($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X90);
    skip_2:
    // 0x808075F0: b           L_80807608
    // 0x808075F4: sh          $t6, 0x7C($s0)
    MEM_H(0X7C, ctx->r16) = ctx->r14;
        goto L_80807608;
    // 0x808075F4: sh          $t6, 0x7C($s0)
    MEM_H(0X7C, ctx->r16) = ctx->r14;
    // 0x808075F8: lwc1        $f10, 0x90($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X90);
L_808075FC:
    // 0x808075FC: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80807600: sh          $t7, 0x7C($s0)
    MEM_H(0X7C, ctx->r16) = ctx->r15;
    // 0x80807604: swc1        $f10, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->f10.u32l;
L_80807608:
    // 0x80807608: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080760C:
    // 0x8080760C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80807610: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80807614: jr          $ra
    // 0x80807618: nop

    return;
    // 0x80807618: nop

;}
RECOMP_FUNC void boot_inflate_dynamic(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800008B0: sw          $ra, 0xA44($sp)
    MEM_W(0XA44, ctx->r29) = ctx->r31;
    // 0x800008B4: lui         $t5, 0x8000
    ctx->r13 = S32(0X8000 << 16);
    // 0x800008B8: addiu       $t5, $t5, 0x439C
    ctx->r13 = ADD32(ctx->r13, 0X439C);
    // 0x800008BC: slti        $at, $fp, 0xE
    ctx->r1 = SIGNED(ctx->r30) < 0XE ? 1 : 0;
    // 0x800008C0: beq         $at, $zero, L_800008E8
    if (ctx->r1 == 0) {
        // 0x800008C4: nop
    
            goto L_800008E8;
    }
    // 0x800008C4: nop

    // 0x800008C8: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
L_800008CC:
    // 0x800008CC: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800008D0: sllv        $at, $at, $fp
    ctx->r1 = S32(ctx->r1 << (ctx->r30 & 31));
    // 0x800008D4: or          $gp, $gp, $at
    ctx->r28 = ctx->r28 | ctx->r1;
    // 0x800008D8: addiu       $fp, $fp, 0x8
    ctx->r30 = ADD32(ctx->r30, 0X8);
    // 0x800008DC: slti        $at, $fp, 0xE
    ctx->r1 = SIGNED(ctx->r30) < 0XE ? 1 : 0;
    // 0x800008E0: bnel        $at, $zero, L_800008CC
    if (ctx->r1 != 0) {
        // 0x800008E4: lbu         $at, 0x0($s7)
        ctx->r1 = MEM_BU(ctx->r23, 0X0);
            goto L_800008CC;
    }
    goto skip_0;
    // 0x800008E4: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
    skip_0:
L_800008E8:
    // 0x800008E8: andi        $t2, $gp, 0x1F
    ctx->r10 = ctx->r28 & 0X1F;
    // 0x800008EC: addiu       $t2, $t2, 0x101
    ctx->r10 = ADD32(ctx->r10, 0X101);
    // 0x800008F0: andi        $t3, $gp, 0x3E0
    ctx->r11 = ctx->r28 & 0X3E0;
    // 0x800008F4: srl         $t3, $t3, 5
    ctx->r11 = S32(U32(ctx->r11) >> 5);
    // 0x800008F8: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800008FC: andi        $t1, $gp, 0x3C00
    ctx->r9 = ctx->r28 & 0X3C00;
    // 0x80000900: srl         $t1, $t1, 10
    ctx->r9 = S32(U32(ctx->r9) >> 10);
    // 0x80000904: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x80000908: srl         $gp, $gp, 14
    ctx->r28 = S32(U32(ctx->r28) >> 14);
    // 0x8000090C: addiu       $fp, $fp, -0xE
    ctx->r30 = ADD32(ctx->r30, -0XE);
    // 0x80000910: slti        $at, $t2, 0x11F
    ctx->r1 = SIGNED(ctx->r10) < 0X11F ? 1 : 0;
    // 0x80000914: beq         $at, $zero, L_80000CA4
    if (ctx->r1 == 0) {
        // 0x80000918: slti        $at, $t3, 0x1F
        ctx->r1 = SIGNED(ctx->r11) < 0X1F ? 1 : 0;
            goto L_80000CA4;
    }
    // 0x80000918: slti        $at, $t3, 0x1F
    ctx->r1 = SIGNED(ctx->r11) < 0X1F ? 1 : 0;
    // 0x8000091C: beq         $at, $zero, L_80000CA4
    if (ctx->r1 == 0) {
        // 0x80000920: addiu       $s1, $zero, 0x0
        ctx->r17 = ADD32(0, 0X0);
            goto L_80000CA4;
    }
    // 0x80000920: addiu       $s1, $zero, 0x0
    ctx->r17 = ADD32(0, 0X0);
L_80000924:
    // 0x80000924: slti        $at, $fp, 0x3
    ctx->r1 = SIGNED(ctx->r30) < 0X3 ? 1 : 0;
    // 0x80000928: beq         $at, $zero, L_80000950
    if (ctx->r1 == 0) {
        // 0x8000092C: nop
    
            goto L_80000950;
    }
    // 0x8000092C: nop

    // 0x80000930: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
L_80000934:
    // 0x80000934: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80000938: sllv        $at, $at, $fp
    ctx->r1 = S32(ctx->r1 << (ctx->r30 & 31));
    // 0x8000093C: or          $gp, $gp, $at
    ctx->r28 = ctx->r28 | ctx->r1;
    // 0x80000940: addiu       $fp, $fp, 0x8
    ctx->r30 = ADD32(ctx->r30, 0X8);
    // 0x80000944: slti        $at, $fp, 0x3
    ctx->r1 = SIGNED(ctx->r30) < 0X3 ? 1 : 0;
    // 0x80000948: bnel        $at, $zero, L_80000934
    if (ctx->r1 != 0) {
        // 0x8000094C: lbu         $at, 0x0($s7)
        ctx->r1 = MEM_BU(ctx->r23, 0X0);
            goto L_80000934;
    }
    goto skip_1;
    // 0x8000094C: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
    skip_1:
L_80000950:
    // 0x80000950: addu        $t8, $t5, $s1
    ctx->r24 = ADD32(ctx->r13, ctx->r17);
    // 0x80000954: lbu         $t8, 0x0($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X0);
    // 0x80000958: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8000095C: addu        $t8, $t8, $sp
    ctx->r24 = ADD32(ctx->r24, ctx->r29);
    // 0x80000960: andi        $at, $gp, 0x7
    ctx->r1 = ctx->r28 & 0X7;
    // 0x80000964: sw          $at, 0x548($t8)
    MEM_W(0X548, ctx->r24) = ctx->r1;
    // 0x80000968: srl         $gp, $gp, 3
    ctx->r28 = S32(U32(ctx->r28) >> 3);
    // 0x8000096C: addiu       $fp, $fp, -0x3
    ctx->r30 = ADD32(ctx->r30, -0X3);
    // 0x80000970: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80000974: slt         $at, $s1, $t1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80000978: bne         $at, $zero, L_80000924
    if (ctx->r1 != 0) {
        // 0x8000097C: slti        $at, $s1, 0x13
        ctx->r1 = SIGNED(ctx->r17) < 0X13 ? 1 : 0;
            goto L_80000924;
    }
    // 0x8000097C: slti        $at, $s1, 0x13
    ctx->r1 = SIGNED(ctx->r17) < 0X13 ? 1 : 0;
    // 0x80000980: beq         $at, $zero, L_800009A4
    if (ctx->r1 == 0) {
        // 0x80000984: addu        $t8, $t5, $s1
        ctx->r24 = ADD32(ctx->r13, ctx->r17);
            goto L_800009A4;
    }
L_80000984:
    // 0x80000984: addu        $t8, $t5, $s1
    ctx->r24 = ADD32(ctx->r13, ctx->r17);
    // 0x80000988: lbu         $t8, 0x0($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X0);
    // 0x8000098C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80000990: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80000994: addu        $t8, $t8, $sp
    ctx->r24 = ADD32(ctx->r24, ctx->r29);
    // 0x80000998: sw          $zero, 0x548($t8)
    MEM_W(0X548, ctx->r24) = 0;
    // 0x8000099C: slti        $at, $s1, 0x13
    ctx->r1 = SIGNED(ctx->r17) < 0X13 ? 1 : 0;
    // 0x800009A0: bne         $at, $zero, L_80000984
    if (ctx->r1 != 0) {
        // 0x800009A4: addiu       $t8, $zero, 0x7
        ctx->r24 = ADD32(0, 0X7);
            goto L_80000984;
    }
L_800009A4:
    // 0x800009A4: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x800009A8: sw          $t8, 0xA3C($sp)
    MEM_W(0XA3C, ctx->r29) = ctx->r24;
    // 0x800009AC: mtc1        $t2, $f0
    ctx->f0.u32l = ctx->r10;
    // 0x800009B0: mtc1        $t3, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r11;
    // 0x800009B4: addiu       $a0, $sp, 0x548
    ctx->r4 = ADD32(ctx->r29, 0X548);
    // 0x800009B8: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // 0x800009BC: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x800009C0: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x800009C4: addiu       $t7, $zero, 0x0
    ctx->r15 = ADD32(0, 0X0);
    // 0x800009C8: addiu       $t8, $sp, 0xA38
    ctx->r24 = ADD32(ctx->r29, 0XA38);
    // 0x800009CC: jal         0x80000E1C
    // 0x800009D0: addiu       $t9, $sp, 0xA3C
    ctx->r25 = ADD32(ctx->r29, 0XA3C);
    boot_huft_build(rdram, ctx);
        goto after_0;
    // 0x800009D0: addiu       $t9, $sp, 0xA3C
    ctx->r25 = ADD32(ctx->r29, 0XA3C);
    after_0:
    // 0x800009D4: mfc1        $t2, $f0
    ctx->r10 = (int32_t)ctx->f0.u32l;
    // 0x800009D8: mfc1        $t3, $f1
    ctx->r11 = (int32_t)ctx->f_odd[(1 - 1) * 2];
    // 0x800009DC: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800009E0: addiu       $t6, $t6, 0x4300
    ctx->r14 = ADD32(ctx->r14, 0X4300);
    // 0x800009E4: lhu         $s5, 0xA38($sp)
    ctx->r21 = MEM_HU(ctx->r29, 0XA38);
    // 0x800009E8: lw          $t0, 0xA3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA3C);
    // 0x800009EC: addu        $s4, $t2, $t3
    ctx->r20 = ADD32(ctx->r10, ctx->r11);
    // 0x800009F0: sll         $s3, $t0, 1
    ctx->r19 = S32(ctx->r8 << 1);
    // 0x800009F4: addu        $s3, $s3, $t6
    ctx->r19 = ADD32(ctx->r19, ctx->r14);
    // 0x800009F8: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x800009FC: addiu       $s2, $zero, 0x0
    ctx->r18 = ADD32(0, 0X0);
    // 0x80000A00: slt         $at, $t9, $s4
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80000A04: beq         $at, $zero, L_80000BE8
    if (ctx->r1 == 0) {
        // 0x80000A08: lhu         $s3, 0x0($s3)
        ctx->r19 = MEM_HU(ctx->r19, 0X0);
            goto L_80000BE8;
    }
    // 0x80000A08: lhu         $s3, 0x0($s3)
    ctx->r19 = MEM_HU(ctx->r19, 0X0);
L_80000A0C:
    // 0x80000A0C: slt         $at, $fp, $t0
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80000A10: beq         $at, $zero, L_80000A38
    if (ctx->r1 == 0) {
        // 0x80000A14: nop
    
            goto L_80000A38;
    }
    // 0x80000A14: nop

    // 0x80000A18: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
L_80000A1C:
    // 0x80000A1C: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80000A20: sllv        $at, $at, $fp
    ctx->r1 = S32(ctx->r1 << (ctx->r30 & 31));
    // 0x80000A24: or          $gp, $gp, $at
    ctx->r28 = ctx->r28 | ctx->r1;
    // 0x80000A28: addiu       $fp, $fp, 0x8
    ctx->r30 = ADD32(ctx->r30, 0X8);
    // 0x80000A2C: slt         $at, $fp, $t0
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80000A30: bnel        $at, $zero, L_80000A1C
    if (ctx->r1 != 0) {
        // 0x80000A34: lbu         $at, 0x0($s7)
        ctx->r1 = MEM_BU(ctx->r23, 0X0);
            goto L_80000A1C;
    }
    goto skip_2;
    // 0x80000A34: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
    skip_2:
L_80000A38:
    // 0x80000A38: and         $s0, $gp, $s3
    ctx->r16 = ctx->r28 & ctx->r19;
    // 0x80000A3C: addu        $s0, $s0, $s5
    ctx->r16 = ADD32(ctx->r16, ctx->r21);
    // 0x80000A40: sll         $s1, $s0, 2
    ctx->r17 = S32(ctx->r16 << 2);
    // 0x80000A44: addu        $s1, $s1, $s6
    ctx->r17 = ADD32(ctx->r17, ctx->r22);
    // 0x80000A48: lbu         $s1, 0x1($s1)
    ctx->r17 = MEM_BU(ctx->r17, 0X1);
    // 0x80000A4C: srlv        $gp, $gp, $s1
    ctx->r28 = S32(U32(ctx->r28) >> (ctx->r17 & 31));
    // 0x80000A50: subu        $fp, $fp, $s1
    ctx->r30 = SUB32(ctx->r30, ctx->r17);
    // 0x80000A54: sll         $s1, $s0, 2
    ctx->r17 = S32(ctx->r16 << 2);
    // 0x80000A58: addu        $s1, $s1, $s6
    ctx->r17 = ADD32(ctx->r17, ctx->r22);
    // 0x80000A5C: lhu         $s1, 0x2($s1)
    ctx->r17 = MEM_HU(ctx->r17, 0X2);
    // 0x80000A60: slti        $at, $s1, 0x10
    ctx->r1 = SIGNED(ctx->r17) < 0X10 ? 1 : 0;
    // 0x80000A64: beq         $at, $zero, L_80000A84
    if (ctx->r1 == 0) {
        // 0x80000A68: nop
    
            goto L_80000A84;
    }
    // 0x80000A68: nop

    // 0x80000A6C: sll         $s2, $t9, 2
    ctx->r18 = S32(ctx->r25 << 2);
    // 0x80000A70: addu        $s2, $s2, $sp
    ctx->r18 = ADD32(ctx->r18, ctx->r29);
    // 0x80000A74: sw          $s1, 0x548($s2)
    MEM_W(0X548, ctx->r18) = ctx->r17;
    // 0x80000A78: addiu       $t9, $t9, 0x1
    ctx->r25 = ADD32(ctx->r25, 0X1);
    // 0x80000A7C: j           L_80000BDC
    // 0x80000A80: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
        goto L_80000BDC;
    // 0x80000A80: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
L_80000A84:
    // 0x80000A84: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80000A88: bne         $s1, $at, L_80000AFC
    if (ctx->r17 != ctx->r1) {
        // 0x80000A8C: nop
    
            goto L_80000AFC;
    }
    // 0x80000A8C: nop

    // 0x80000A90: slti        $at, $fp, 0x2
    ctx->r1 = SIGNED(ctx->r30) < 0X2 ? 1 : 0;
    // 0x80000A94: beq         $at, $zero, L_80000ABC
    if (ctx->r1 == 0) {
        // 0x80000A98: nop
    
            goto L_80000ABC;
    }
    // 0x80000A98: nop

    // 0x80000A9C: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
L_80000AA0:
    // 0x80000AA0: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80000AA4: sllv        $at, $at, $fp
    ctx->r1 = S32(ctx->r1 << (ctx->r30 & 31));
    // 0x80000AA8: or          $gp, $gp, $at
    ctx->r28 = ctx->r28 | ctx->r1;
    // 0x80000AAC: addiu       $fp, $fp, 0x8
    ctx->r30 = ADD32(ctx->r30, 0X8);
    // 0x80000AB0: slti        $at, $fp, 0x2
    ctx->r1 = SIGNED(ctx->r30) < 0X2 ? 1 : 0;
    // 0x80000AB4: bnel        $at, $zero, L_80000AA0
    if (ctx->r1 != 0) {
        // 0x80000AB8: lbu         $at, 0x0($s7)
        ctx->r1 = MEM_BU(ctx->r23, 0X0);
            goto L_80000AA0;
    }
    goto skip_3;
    // 0x80000AB8: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
    skip_3:
L_80000ABC:
    // 0x80000ABC: andi        $s1, $gp, 0x3
    ctx->r17 = ctx->r28 & 0X3;
    // 0x80000AC0: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x80000AC4: srl         $gp, $gp, 2
    ctx->r28 = S32(U32(ctx->r28) >> 2);
    // 0x80000AC8: addiu       $fp, $fp, -0x2
    ctx->r30 = ADD32(ctx->r30, -0X2);
    // 0x80000ACC: addu        $t8, $t9, $s1
    ctx->r24 = ADD32(ctx->r25, ctx->r17);
    // 0x80000AD0: slt         $at, $s4, $t8
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80000AD4: bne         $at, $zero, L_80000CA4
    if (ctx->r1 != 0) {
        // 0x80000AD8: sll         $t8, $t9, 2
        ctx->r24 = S32(ctx->r25 << 2);
            goto L_80000CA4;
    }
    // 0x80000AD8: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80000ADC: addu        $t8, $t8, $sp
    ctx->r24 = ADD32(ctx->r24, ctx->r29);
L_80000AE0:
    // 0x80000AE0: sw          $s2, 0x548($t8)
    MEM_W(0X548, ctx->r24) = ctx->r18;
    // 0x80000AE4: addiu       $t9, $t9, 0x1
    ctx->r25 = ADD32(ctx->r25, 0X1);
    // 0x80000AE8: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80000AEC: bne         $s1, $zero, L_80000AE0
    if (ctx->r17 != 0) {
        // 0x80000AF0: addiu       $t8, $t8, 0x4
        ctx->r24 = ADD32(ctx->r24, 0X4);
            goto L_80000AE0;
    }
    // 0x80000AF0: addiu       $t8, $t8, 0x4
    ctx->r24 = ADD32(ctx->r24, 0X4);
    // 0x80000AF4: j           L_80000BDC
    // 0x80000AF8: nop

        goto L_80000BDC;
    // 0x80000AF8: nop

L_80000AFC:
    // 0x80000AFC: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80000B00: bne         $s1, $at, L_80000B74
    if (ctx->r17 != ctx->r1) {
        // 0x80000B04: nop
    
            goto L_80000B74;
    }
    // 0x80000B04: nop

    // 0x80000B08: slti        $at, $fp, 0x3
    ctx->r1 = SIGNED(ctx->r30) < 0X3 ? 1 : 0;
    // 0x80000B0C: beq         $at, $zero, L_80000B34
    if (ctx->r1 == 0) {
        // 0x80000B10: nop
    
            goto L_80000B34;
    }
    // 0x80000B10: nop

    // 0x80000B14: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
L_80000B18:
    // 0x80000B18: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80000B1C: sllv        $at, $at, $fp
    ctx->r1 = S32(ctx->r1 << (ctx->r30 & 31));
    // 0x80000B20: or          $gp, $gp, $at
    ctx->r28 = ctx->r28 | ctx->r1;
    // 0x80000B24: addiu       $fp, $fp, 0x8
    ctx->r30 = ADD32(ctx->r30, 0X8);
    // 0x80000B28: slti        $at, $fp, 0x3
    ctx->r1 = SIGNED(ctx->r30) < 0X3 ? 1 : 0;
    // 0x80000B2C: bnel        $at, $zero, L_80000B18
    if (ctx->r1 != 0) {
        // 0x80000B30: lbu         $at, 0x0($s7)
        ctx->r1 = MEM_BU(ctx->r23, 0X0);
            goto L_80000B18;
    }
    goto skip_4;
    // 0x80000B30: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
    skip_4:
L_80000B34:
    // 0x80000B34: andi        $s1, $gp, 0x7
    ctx->r17 = ctx->r28 & 0X7;
    // 0x80000B38: addiu       $s1, $s1, 0x3
    ctx->r17 = ADD32(ctx->r17, 0X3);
    // 0x80000B3C: srl         $gp, $gp, 3
    ctx->r28 = S32(U32(ctx->r28) >> 3);
    // 0x80000B40: addiu       $fp, $fp, -0x3
    ctx->r30 = ADD32(ctx->r30, -0X3);
    // 0x80000B44: addu        $t8, $t9, $s1
    ctx->r24 = ADD32(ctx->r25, ctx->r17);
    // 0x80000B48: slt         $at, $s4, $t8
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80000B4C: bne         $at, $zero, L_80000CA4
    if (ctx->r1 != 0) {
        // 0x80000B50: sll         $t8, $t9, 2
        ctx->r24 = S32(ctx->r25 << 2);
            goto L_80000CA4;
    }
    // 0x80000B50: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80000B54: addu        $t8, $t8, $sp
    ctx->r24 = ADD32(ctx->r24, ctx->r29);
L_80000B58:
    // 0x80000B58: sw          $zero, 0x548($t8)
    MEM_W(0X548, ctx->r24) = 0;
    // 0x80000B5C: addiu       $t9, $t9, 0x1
    ctx->r25 = ADD32(ctx->r25, 0X1);
    // 0x80000B60: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80000B64: bne         $s1, $zero, L_80000B58
    if (ctx->r17 != 0) {
        // 0x80000B68: addiu       $t8, $t8, 0x4
        ctx->r24 = ADD32(ctx->r24, 0X4);
            goto L_80000B58;
    }
    // 0x80000B68: addiu       $t8, $t8, 0x4
    ctx->r24 = ADD32(ctx->r24, 0X4);
    // 0x80000B6C: j           L_80000BDC
    // 0x80000B70: addiu       $s2, $zero, 0x0
    ctx->r18 = ADD32(0, 0X0);
        goto L_80000BDC;
    // 0x80000B70: addiu       $s2, $zero, 0x0
    ctx->r18 = ADD32(0, 0X0);
L_80000B74:
    // 0x80000B74: slti        $at, $fp, 0x7
    ctx->r1 = SIGNED(ctx->r30) < 0X7 ? 1 : 0;
    // 0x80000B78: beq         $at, $zero, L_80000BA0
    if (ctx->r1 == 0) {
        // 0x80000B7C: nop
    
            goto L_80000BA0;
    }
    // 0x80000B7C: nop

    // 0x80000B80: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
L_80000B84:
    // 0x80000B84: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x80000B88: sllv        $at, $at, $fp
    ctx->r1 = S32(ctx->r1 << (ctx->r30 & 31));
    // 0x80000B8C: or          $gp, $gp, $at
    ctx->r28 = ctx->r28 | ctx->r1;
    // 0x80000B90: addiu       $fp, $fp, 0x8
    ctx->r30 = ADD32(ctx->r30, 0X8);
    // 0x80000B94: slti        $at, $fp, 0x7
    ctx->r1 = SIGNED(ctx->r30) < 0X7 ? 1 : 0;
    // 0x80000B98: bnel        $at, $zero, L_80000B84
    if (ctx->r1 != 0) {
        // 0x80000B9C: lbu         $at, 0x0($s7)
        ctx->r1 = MEM_BU(ctx->r23, 0X0);
            goto L_80000B84;
    }
    goto skip_5;
    // 0x80000B9C: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
    skip_5:
L_80000BA0:
    // 0x80000BA0: andi        $s1, $gp, 0x7F
    ctx->r17 = ctx->r28 & 0X7F;
    // 0x80000BA4: addiu       $s1, $s1, 0xB
    ctx->r17 = ADD32(ctx->r17, 0XB);
    // 0x80000BA8: srl         $gp, $gp, 7
    ctx->r28 = S32(U32(ctx->r28) >> 7);
    // 0x80000BAC: addiu       $fp, $fp, -0x7
    ctx->r30 = ADD32(ctx->r30, -0X7);
    // 0x80000BB0: addu        $t8, $t9, $s1
    ctx->r24 = ADD32(ctx->r25, ctx->r17);
    // 0x80000BB4: slt         $at, $s4, $t8
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80000BB8: bne         $at, $zero, L_80000CA4
    if (ctx->r1 != 0) {
        // 0x80000BBC: sll         $t8, $t9, 2
        ctx->r24 = S32(ctx->r25 << 2);
            goto L_80000CA4;
    }
    // 0x80000BBC: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80000BC0: addu        $t8, $t8, $sp
    ctx->r24 = ADD32(ctx->r24, ctx->r29);
L_80000BC4:
    // 0x80000BC4: sw          $zero, 0x548($t8)
    MEM_W(0X548, ctx->r24) = 0;
    // 0x80000BC8: addiu       $t9, $t9, 0x1
    ctx->r25 = ADD32(ctx->r25, 0X1);
    // 0x80000BCC: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80000BD0: bne         $s1, $zero, L_80000BC4
    if (ctx->r17 != 0) {
        // 0x80000BD4: addiu       $t8, $t8, 0x4
        ctx->r24 = ADD32(ctx->r24, 0X4);
            goto L_80000BC4;
    }
    // 0x80000BD4: addiu       $t8, $t8, 0x4
    ctx->r24 = ADD32(ctx->r24, 0X4);
    // 0x80000BD8: addiu       $s2, $zero, 0x0
    ctx->r18 = ADD32(0, 0X0);
L_80000BDC:
    // 0x80000BDC: slt         $at, $t9, $s4
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80000BE0: bne         $at, $zero, L_80000A0C
    if (ctx->r1 != 0) {
        // 0x80000BE4: nop
    
            goto L_80000A0C;
    }
    // 0x80000BE4: nop

L_80000BE8:
    // 0x80000BE8: sh          $s5, 0xA38($sp)
    MEM_H(0XA38, ctx->r29) = ctx->r21;
    // 0x80000BEC: sh          $s0, 0xA3A($sp)
    MEM_H(0XA3A, ctx->r29) = ctx->r16;
    // 0x80000BF0: addiu       $t8, $zero, 0x9
    ctx->r24 = ADD32(0, 0X9);
    // 0x80000BF4: sw          $t8, 0xA3C($sp)
    MEM_W(0XA3C, ctx->r29) = ctx->r24;
    // 0x80000BF8: mtc1        $t2, $f0
    ctx->f0.u32l = ctx->r10;
    // 0x80000BFC: mtc1        $t3, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r11;
    // 0x80000C00: addiu       $a0, $sp, 0x548
    ctx->r4 = ADD32(ctx->r29, 0X548);
    // 0x80000C04: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x80000C08: addiu       $a2, $zero, 0x101
    ctx->r6 = ADD32(0, 0X101);
    // 0x80000C0C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80000C10: addiu       $a3, $a3, 0x4322
    ctx->r7 = ADD32(ctx->r7, 0X4322);
    // 0x80000C14: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x80000C18: addiu       $t7, $t7, 0x43AF
    ctx->r15 = ADD32(ctx->r15, 0X43AF);
    // 0x80000C1C: addiu       $t8, $sp, 0xA38
    ctx->r24 = ADD32(ctx->r29, 0XA38);
    // 0x80000C20: jal         0x80000E1C
    // 0x80000C24: addiu       $t9, $sp, 0xA3C
    ctx->r25 = ADD32(ctx->r29, 0XA3C);
    boot_huft_build(rdram, ctx);
        goto after_1;
    // 0x80000C24: addiu       $t9, $sp, 0xA3C
    ctx->r25 = ADD32(ctx->r29, 0XA3C);
    after_1:
    // 0x80000C28: mfc1        $t2, $f0
    ctx->r10 = (int32_t)ctx->f0.u32l;
    // 0x80000C2C: mfc1        $t3, $f1
    ctx->r11 = (int32_t)ctx->f_odd[(1 - 1) * 2];
    // 0x80000C30: bne         $v0, $zero, L_80000CA4
    if (ctx->r2 != 0) {
        // 0x80000C34: addiu       $t8, $zero, 0x6
        ctx->r24 = ADD32(0, 0X6);
            goto L_80000CA4;
    }
    // 0x80000C34: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x80000C38: sw          $t8, 0xA40($sp)
    MEM_W(0XA40, ctx->r29) = ctx->r24;
    // 0x80000C3C: sll         $a0, $t2, 2
    ctx->r4 = S32(ctx->r10 << 2);
    // 0x80000C40: addu        $a0, $a0, $sp
    ctx->r4 = ADD32(ctx->r4, ctx->r29);
    // 0x80000C44: addiu       $a0, $a0, 0x548
    ctx->r4 = ADD32(ctx->r4, 0X548);
    // 0x80000C48: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x80000C4C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80000C50: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80000C54: addiu       $a3, $a3, 0x4360
    ctx->r7 = ADD32(ctx->r7, 0X4360);
    // 0x80000C58: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x80000C5C: addiu       $t7, $t7, 0x43CE
    ctx->r15 = ADD32(ctx->r15, 0X43CE);
    // 0x80000C60: addiu       $t8, $sp, 0xA3A
    ctx->r24 = ADD32(ctx->r29, 0XA3A);
    // 0x80000C64: jal         0x80000E1C
    // 0x80000C68: addiu       $t9, $sp, 0xA40
    ctx->r25 = ADD32(ctx->r29, 0XA40);
    boot_huft_build(rdram, ctx);
        goto after_2;
    // 0x80000C68: addiu       $t9, $sp, 0xA40
    ctx->r25 = ADD32(ctx->r29, 0XA40);
    after_2:
    // 0x80000C6C: bne         $v0, $zero, L_80000CA4
    if (ctx->r2 != 0) {
        // 0x80000C70: lhu         $a0, 0xA38($sp)
        ctx->r4 = MEM_HU(ctx->r29, 0XA38);
            goto L_80000CA4;
    }
    // 0x80000C70: lhu         $a0, 0xA38($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0XA38);
    // 0x80000C74: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80000C78: addu        $a0, $a0, $s6
    ctx->r4 = ADD32(ctx->r4, ctx->r22);
    // 0x80000C7C: lhu         $a1, 0xA3A($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0XA3A);
    // 0x80000C80: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x80000C84: addu        $a1, $a1, $s6
    ctx->r5 = ADD32(ctx->r5, ctx->r22);
    // 0x80000C88: lw          $a2, 0xA3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA3C);
    // 0x80000C8C: jal         0x800012B0
    // 0x80000C90: lw          $a3, 0xA40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA40);
    boot_inflate_codes(rdram, ctx);
        goto after_3;
    // 0x80000C90: lw          $a3, 0xA40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA40);
    after_3:
    // 0x80000C94: bne         $v0, $zero, L_80000CA4
    if (ctx->r2 != 0) {
        // 0x80000C98: nop
    
            goto L_80000CA4;
    }
    // 0x80000C98: nop

    // 0x80000C9C: j           L_80000CA8
    // 0x80000CA0: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
        goto L_80000CA8;
    // 0x80000CA0: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
L_80000CA4:
    // 0x80000CA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80000CA8:
    // 0x80000CA8: lw          $ra, 0xA44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA44);
    // 0x80000CAC: jr          $ra
    // 0x80000CB0: nop

    return;
    // 0x80000CB0: nop

;}
RECOMP_FUNC void _idworld_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088F00: syscall     748
    recomp_syscall_handler(rdram, ctx, 0x80088F00);
    return;
    // 0x80088F04: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_808006F8_bsbansnooze(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800700: jal         0x80800098
    // 0x80800704: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800098_bsbansnooze(rdram, ctx);
        goto after_0;
    // 0x80800704: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800708: jal         0x800839C8
    // 0x8080070C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsrest_entrypoint_16(rdram, ctx);
        goto after_1;
    // 0x8080070C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800710: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800714: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800718: jr          $ra
    // 0x8080071C: nop

    return;
    // 0x8080071C: nop

;}
RECOMP_FUNC void func_80800070_chjigsaw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800070: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800074: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800078: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080007C: lwc1        $f4, 0x50($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
    // 0x80800080: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800084: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800088: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8080008C: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80800090: jal         0x800D0B68
    // 0x80800094: nop

    func_800D0B68(rdram, ctx);
        goto after_0;
    // 0x80800094: nop

    after_0:
    // 0x80800098: beql        $v0, $zero, L_808000B4
    if (ctx->r2 == 0) {
        // 0x8080009C: lwc1        $f8, 0x50($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
            goto L_808000B4;
    }
    goto skip_0;
    // 0x8080009C: lwc1        $f8, 0x50($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
    skip_0:
    // 0x808000A0: jal         0x800FFAB0
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808000A8: b           L_8080010C
    // 0x808000AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080010C;
    // 0x808000AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000B0: lwc1        $f8, 0x50($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
L_808000B4:
    // 0x808000B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000B8: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x808000BC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808000C0: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x808000C4: jal         0x800D05E4
    // 0x808000C8: nop

    func_800D05E4(rdram, ctx);
        goto after_2;
    // 0x808000C8: nop

    after_2:
    // 0x808000CC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x808000D0: lwc1        $f18, 0x58($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808000D4: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x808000D8: nop

    // 0x808000DC: bc1tl       L_808000F0
    if (c1cs) {
        // 0x808000E0: lwc1        $f4, 0x50($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X50);
            goto L_808000F0;
    }
    goto skip_1;
    // 0x808000E0: lwc1        $f4, 0x50($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X50);
    skip_1:
    // 0x808000E4: jal         0x800FC6B0
    // 0x808000E8: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    func_800FC6B0(rdram, ctx);
        goto after_3;
    // 0x808000E8: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_3:
    // 0x808000EC: lwc1        $f4, 0x50($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X50);
L_808000F0:
    // 0x808000F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000F4: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x808000F8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808000FC: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80800100: jal         0x800D0778
    // 0x80800104: nop

    func_800D0778(rdram, ctx);
        goto after_4;
    // 0x80800104: nop

    after_4:
    // 0x80800108: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080010C:
    // 0x8080010C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800110: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800114: jr          $ra
    // 0x80800118: nop

    return;
    // 0x80800118: nop

;}
RECOMP_FUNC void func_808004C0_chsilo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004C0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808004C4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808004C8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808004CC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x808004D0: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808004D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808004D8: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808004DC: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x808004E0: sltiu       $at, $t8, 0xB
    ctx->r1 = ctx->r24 < 0XB ? 1 : 0;
    // 0x808004E4: beq         $at, $zero, L_808005A0
    if (ctx->r1 == 0) {
        // 0x808004E8: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808005A0;
    }
    // 0x808004E8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808004EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1820, 0X1230) << 16);
    // 0x808004F0: addu        $at, $at, $t8
    gpr jr_addend_808004F8 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x808004F4: lw          $t8, 0x1230($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1820, 0X1230));
    // 0x808004F8: jr          $t8
    // 0x808004FC: nop

    switch (jr_addend_808004F8 >> 2) {
        case 0: goto L_80800500; break;
        case 1: goto L_80800514; break;
        case 2: goto L_808005A0; break;
        case 3: goto L_808005A0; break;
        case 4: goto L_80800550; break;
        case 5: goto L_80800540; break;
        case 6: goto L_808005A0; break;
        case 7: goto L_80800578; break;
        case 8: goto L_808005A0; break;
        case 9: goto L_808005A0; break;
        case 10: goto L_8080058C; break;
        default: switch_error(__func__, 0x808004F8, 0x80801230);
    }
    // 0x808004FC: nop

L_80800500:
    // 0x80800500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800504: jal         0x8008A4B0
    // 0x80800508: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800508: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8080050C: b           L_808005A4
    // 0x80800510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808005A4;
    // 0x80800510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800514:
    // 0x80800514: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x80800518: andi        $t9, $a0, 0x1FF
    ctx->r25 = ctx->r4 & 0X1FF;
    // 0x8080051C: jal         0x800DA544
    // 0x80800520: addiu       $a0, $t9, 0x32C
    ctx->r4 = ADD32(ctx->r25, 0X32C);
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x80800520: addiu       $a0, $t9, 0x32C
    ctx->r4 = ADD32(ctx->r25, 0X32C);
    after_1:
    // 0x80800524: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    // 0x80800528: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8080052C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800530: ori         $t2, $t1, 0x10
    ctx->r10 = ctx->r9 | 0X10;
    // 0x80800534: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
    // 0x80800538: b           L_808005A0
    // 0x8080053C: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
        goto L_808005A0;
    // 0x8080053C: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
L_80800540:
    // 0x80800540: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800544: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800548: b           L_808005A0
    // 0x8080054C: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
        goto L_808005A0;
    // 0x8080054C: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
L_80800550:
    // 0x80800550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800554: jal         0x80087CC8
    // 0x80800558: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gcnewoption_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x80800558: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8080055C: jal         0x80090708
    // 0x80800560: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_3;
    // 0x80800560: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80800564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800568: jal         0x8010A828
    // 0x8080056C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010A828(rdram, ctx);
        goto after_4;
    // 0x8080056C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x80800570: b           L_808005A4
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808005A4;
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800578:
    // 0x80800578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080057C: jal         0x80800420
    // 0x80800580: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800420_chsilo(rdram, ctx);
        goto after_5;
    // 0x80800580: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80800584: b           L_808005A4
    // 0x80800588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808005A4;
    // 0x80800588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080058C:
    // 0x8080058C: jal         0x800F54E4
    // 0x80800590: nop

    func_800F54E4(rdram, ctx);
        goto after_6;
    // 0x80800590: nop

    after_6:
    // 0x80800594: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800598: jal         0x800878D0
    // 0x8080059C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _plcamera_entrypoint_3(rdram, ctx);
        goto after_7;
    // 0x8080059C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
L_808005A0:
    // 0x808005A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808005A4:
    // 0x808005A4: jal         0x80102424
    // 0x808005A8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_80102424(rdram, ctx);
        goto after_8;
    // 0x808005A8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_8:
    // 0x808005AC: lhu         $t3, 0x72($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X72);
    // 0x808005B0: srl         $t4, $t3, 10
    ctx->r12 = S32(U32(ctx->r11) >> 10);
    // 0x808005B4: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x808005B8: sltiu       $at, $t5, 0xB
    ctx->r1 = ctx->r13 < 0XB ? 1 : 0;
    // 0x808005BC: beq         $at, $zero, L_80800868
    if (ctx->r1 == 0) {
        // 0x808005C0: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_80800868;
    }
    // 0x808005C0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x808005C4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1820, 0X125C) << 16);
    // 0x808005C8: addu        $at, $at, $t5
    gpr jr_addend_808005D0 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x808005CC: lw          $t5, 0x125C($at)
    ctx->r13 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1820, 0X125C));
    // 0x808005D0: jr          $t5
    // 0x808005D4: nop

    switch (jr_addend_808005D0 >> 2) {
        case 0: goto L_808005D8; break;
        case 1: goto L_808005EC; break;
        case 2: goto L_80800868; break;
        case 3: goto L_80800624; break;
        case 4: goto L_80800664; break;
        case 5: goto L_80800608; break;
        case 6: goto L_80800868; break;
        case 7: goto L_80800780; break;
        case 8: goto L_80800838; break;
        case 9: goto L_8080075C; break;
        case 10: goto L_808007EC; break;
        default: switch_error(__func__, 0x808005D0, 0x8080125C);
    }
    // 0x808005D4: nop

L_808005D8:
    // 0x808005D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005DC: jal         0x8008A4B0
    // 0x808005E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_9;
    // 0x808005E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x808005E4: b           L_8080086C
    // 0x808005E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080086C;
    // 0x808005E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808005EC:
    // 0x808005EC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1820, 0X12C0) << 16);
    // 0x808005F0: addiu       $a2, $a2, 0x12C0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1820, 0X12C0));
    // 0x808005F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005F8: jal         0x80089D18
    // 0x808005FC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_10;
    // 0x808005FC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_10:
    // 0x80800600: b           L_8080086C
    // 0x80800604: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080086C;
    // 0x80800604: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800608:
    // 0x80800608: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1820, 0X12C0) << 16);
    // 0x8080060C: addiu       $a2, $a2, 0x12C0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1820, 0X12C0));
    // 0x80800610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800614: jal         0x80089D18
    // 0x80800618: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_11;
    // 0x80800618: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_11:
    // 0x8080061C: b           L_8080086C
    // 0x80800620: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080086C;
    // 0x80800620: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800624:
    // 0x80800624: jal         0x800F54E4
    // 0x80800628: nop

    func_800F54E4(rdram, ctx);
        goto after_12;
    // 0x80800628: nop

    after_12:
    // 0x8080062C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800630: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800634: jal         0x800F82D4
    // 0x80800638: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F82D4(rdram, ctx);
        goto after_13;
    // 0x80800638: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x8080063C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800640: jal         0x800878D0
    // 0x80800644: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _plcamera_entrypoint_3(rdram, ctx);
        goto after_14;
    // 0x80800644: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x80800648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080064C: jal         0x80800398
    // 0x80800650: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800398_chsilo(rdram, ctx);
        goto after_15;
    // 0x80800650: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x80800654: jal         0x8008FE68
    // 0x80800658: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_8008FE68(rdram, ctx);
        goto after_16;
    // 0x80800658: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_16:
    // 0x8080065C: b           L_8080086C
    // 0x80800660: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080086C;
    // 0x80800660: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800664:
    // 0x80800664: jal         0x808001A8
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001A8_chsilo(rdram, ctx);
        goto after_17;
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x8080066C: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80800670: addiu       $t6, $zero, 0x184F
    ctx->r14 = ADD32(0, 0X184F);
    // 0x80800674: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80800678: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080067C: addiu       $a2, $a2, 0x7DB0
    ctx->r6 = ADD32(ctx->r6, 0X7DB0);
    // 0x80800680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800684: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800688: jal         0x80087CB8
    // 0x8080068C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _gcnewoption_entrypoint_4(rdram, ctx);
        goto after_18;
    // 0x8080068C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_18:
    // 0x80800690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800694: jal         0x80100094
    // 0x80800698: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_19;
    // 0x80800698: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_19:
    // 0x8080069C: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x808006A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808006A4: slti        $at, $v1, 0x6
    ctx->r1 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
    // 0x808006A8: bne         $at, $zero, L_808006B8
    if (ctx->r1 != 0) {
        // 0x808006AC: or          $a1, $v1, $zero
        ctx->r5 = ctx->r3 | 0;
            goto L_808006B8;
    }
    // 0x808006AC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x808006B0: b           L_808006B8
    // 0x808006B4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
        goto L_808006B8;
    // 0x808006B4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
L_808006B8:
    // 0x808006B8: jal         0x80087CD8
    // 0x808006BC: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    _gcnewoption_entrypoint_8(rdram, ctx);
        goto after_20;
    // 0x808006BC: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    after_20:
    // 0x808006C0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808006C4: jal         0x80087CE0
    // 0x808006C8: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    _gcnewoption_entrypoint_9(rdram, ctx);
        goto after_21;
    // 0x808006C8: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_21:
    // 0x808006CC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808006D0: jal         0x80087CE8
    // 0x808006D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gcnewoption_entrypoint_10(rdram, ctx);
        goto after_22;
    // 0x808006D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_22:
    // 0x808006D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006DC: jal         0x80800210
    // 0x808006E0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80800210_chsilo(rdram, ctx);
        goto after_23;
    // 0x808006E0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_23:
    // 0x808006E4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808006E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808006EC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808006F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808006F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808006F8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x808006FC: jal         0x80087D08
    // 0x80800700: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    _gcnewoption_entrypoint_14(rdram, ctx);
        goto after_24;
    // 0x80800700: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_24:
    // 0x80800704: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1820, 0X1288) << 16);
    // 0x80800708: lwc1        $f10, 0x1288($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1820, 0X1288));
    // 0x8080070C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800710: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800714: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800718: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    // 0x8080071C: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    // 0x80800720: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x80800724: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80800728: jal         0x80087DD8
    // 0x8080072C: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    _gcnewoption_entrypoint_40(rdram, ctx);
        goto after_25;
    // 0x8080072C: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_25:
    // 0x80800730: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80800734: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800738: jal         0x80087DE8
    // 0x8080073C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    _gcnewoption_entrypoint_42(rdram, ctx);
        goto after_26;
    // 0x8080073C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_26:
    // 0x80800740: jal         0x80087CF0
    // 0x80800744: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    _gcnewoption_entrypoint_11(rdram, ctx);
        goto after_27;
    // 0x80800744: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_27:
    // 0x80800748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080074C: jal         0x8010A828
    // 0x80800750: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_8010A828(rdram, ctx);
        goto after_28;
    // 0x80800750: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_28:
    // 0x80800754: b           L_8080086C
    // 0x80800758: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080086C;
    // 0x80800758: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080075C:
    // 0x8080075C: jal         0x80090708
    // 0x80800760: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80090708(rdram, ctx);
        goto after_29;
    // 0x80800760: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_29:
    // 0x80800764: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1820, 0X12C0) << 16);
    // 0x80800768: addiu       $a2, $a2, 0x12C0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1820, 0X12C0));
    // 0x8080076C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800770: jal         0x80089D18
    // 0x80800774: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_30;
    // 0x80800774: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_30:
    // 0x80800778: b           L_8080086C
    // 0x8080077C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080086C;
    // 0x8080077C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800780:
    // 0x80800780: jal         0x800C964C
    // 0x80800784: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_800C964C(rdram, ctx);
        goto after_31;
    // 0x80800784: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_31:
    // 0x80800788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080078C: jal         0x80800420
    // 0x80800790: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800420_chsilo(rdram, ctx);
        goto after_32;
    // 0x80800790: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_32:
    // 0x80800794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800798: jal         0x80800398
    // 0x8080079C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800398_chsilo(rdram, ctx);
        goto after_33;
    // 0x8080079C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_33:
    // 0x808007A0: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x808007A4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808007A8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808007AC: jal         0x800EE7F8
    // 0x808007B0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800EE7F8(rdram, ctx);
        goto after_34;
    // 0x808007B0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_34:
    // 0x808007B4: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x808007B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808007BC: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x808007C0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808007C4: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x808007C8: jal         0x800907C0
    // 0x808007CC: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    func_800907C0(rdram, ctx);
        goto after_35;
    // 0x808007CC: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    after_35:
    // 0x808007D0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1820, 0X12C0) << 16);
    // 0x808007D4: addiu       $a2, $a2, 0x12C0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1820, 0X12C0));
    // 0x808007D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007DC: jal         0x80089D18
    // 0x808007E0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_36;
    // 0x808007E0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_36:
    // 0x808007E4: b           L_8080086C
    // 0x808007E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080086C;
    // 0x808007E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808007EC:
    // 0x808007EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007F0: jal         0x80800398
    // 0x808007F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800398_chsilo(rdram, ctx);
        goto after_37;
    // 0x808007F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_37:
    // 0x808007F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007FC: jal         0x80800420
    // 0x80800800: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800420_chsilo(rdram, ctx);
        goto after_38;
    // 0x80800800: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_38:
    // 0x80800804: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x80800808: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8080080C: jal         0x800EE7F8
    // 0x80800810: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_39;
    // 0x80800810: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_39:
    // 0x80800814: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80800818: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080081C: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800820: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800824: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80800828: jal         0x800907C0
    // 0x8080082C: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
    func_800907C0(rdram, ctx);
        goto after_40;
    // 0x8080082C: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
    after_40:
    // 0x80800830: b           L_8080086C
    // 0x80800834: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080086C;
    // 0x80800834: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800838:
    // 0x80800838: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080083C: jal         0x80800398
    // 0x80800840: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800398_chsilo(rdram, ctx);
        goto after_41;
    // 0x80800840: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_41:
    // 0x80800844: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80800848: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080084C: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800850: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x80800854: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80800858: jal         0x800907C0
    // 0x8080085C: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    func_800907C0(rdram, ctx);
        goto after_42;
    // 0x8080085C: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    after_42:
    // 0x80800860: jal         0x80800378
    // 0x80800864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800378_chsilo(rdram, ctx);
        goto after_43;
    // 0x80800864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_43:
L_80800868:
    // 0x80800868: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080086C:
    // 0x8080086C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800870: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800874: jr          $ra
    // 0x80800878: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80800878: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void chjadestatue_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800304: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2180, 0X358) << 16);
    // 0x80800308: jr          $ra
    // 0x8080030C: addiu       $v0, $v0, 0x358
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2180, 0X358));
    return;
    // 0x8080030C: addiu       $v0, $v0, 0x358
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2180, 0X358));
;}
RECOMP_FUNC void func_808000F4_chdiggerbossinterior(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000F8: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x808000FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800100: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800104: bne         $a1, $at, L_8080015C
    if (ctx->r5 != ctx->r1) {
        // 0x80800108: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_8080015C;
    }
    // 0x80800108: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080010C: jal         0x80800178
    // 0x80800110: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    func_80800178_chdiggerbossinterior(rdram, ctx);
        goto after_0;
    // 0x80800110: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    after_0:
    // 0x80800114: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800118: addiu       $a0, $zero, 0xA4F
    ctx->r4 = ADD32(0, 0XA4F);
    // 0x8080011C: jal         0x800DA980
    // 0x80800120: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DA980(rdram, ctx);
        goto after_1;
    // 0x80800120: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80800124: blez        $v0, L_80800138
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800128: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800138;
    }
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080012C: jal         0x80800178
    // 0x80800130: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    func_80800178_chdiggerbossinterior(rdram, ctx);
        goto after_2;
    // 0x80800130: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    after_2:
    // 0x80800134: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80800138:
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080013C: jal         0x80101FDC
    // 0x80800140: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x80800140: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80800144: lbu         $t6, 0x79($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X79);
    // 0x80800148: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080014C: andi        $t7, $t6, 0xFF0F
    ctx->r15 = ctx->r14 & 0XFF0F;
    // 0x80800150: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x80800154: b           L_80800164
    // 0x80800158: sb          $t8, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r24;
        goto L_80800164;
    // 0x80800158: sb          $t8, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r24;
L_8080015C:
    // 0x8080015C: b           L_80800164
    // 0x80800160: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800164;
    // 0x80800160: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800164:
    // 0x80800164: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800168: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080016C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800170: jr          $ra
    // 0x80800174: nop

    return;
    // 0x80800174: nop

;}
RECOMP_FUNC void func_80800194_bsstonehead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800194: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800198: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080019C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808001A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001A4: jal         0x8008CABC
    // 0x808001A8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808001A8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808001AC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x808001B0: lw          $t6, 0x15C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X15C);
    // 0x808001B4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001BC: bne         $t6, $zero, L_808001D0
    if (ctx->r14 != 0) {
        // 0x808001C0: nop
    
            goto L_808001D0;
    }
    // 0x808001C0: nop

    // 0x808001C4: jal         0x80800060
    // 0x808001C8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    func_80800060_bsstonehead(rdram, ctx);
        goto after_1;
    // 0x808001C8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_1:
    // 0x808001CC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
L_808001D0:
    // 0x808001D0: beq         $a1, $zero, L_80800384
    if (ctx->r5 == 0) {
        // 0x808001D4: sw          $a1, 0x15C($s0)
        MEM_W(0X15C, ctx->r16) = ctx->r5;
            goto L_80800384;
    }
    // 0x808001D4: sw          $a1, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r5;
    // 0x808001D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808001DC: beq         $a1, $at, L_80800200
    if (ctx->r5 == ctx->r1) {
        // 0x808001E0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800200;
    }
    // 0x808001E0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808001E4: beq         $a1, $at, L_80800330
    if (ctx->r5 == ctx->r1) {
        // 0x808001E8: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_80800330;
    }
    // 0x808001E8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808001EC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808001F0: beq         $a1, $at, L_80800350
    if (ctx->r5 == ctx->r1) {
        // 0x808001F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800350;
    }
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F8: b           L_808003A8
    // 0x808001FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808003A8;
    // 0x808001FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800200:
    // 0x80800200: jal         0x8008DE24
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DE24(rdram, ctx);
        goto after_2;
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800208: beql        $v0, $zero, L_80800230
    if (ctx->r2 == 0) {
        // 0x8080020C: lui         $at, 0x4416
        ctx->r1 = S32(0X4416 << 16);
            goto L_80800230;
    }
    goto skip_0;
    // 0x8080020C: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    skip_0:
    // 0x80800210: jal         0x8008E078
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_3;
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800218: beq         $v0, $zero, L_8080022C
    if (ctx->r2 == 0) {
        // 0x8080021C: lui         $at, 0x4316
        ctx->r1 = S32(0X4316 << 16);
            goto L_8080022C;
    }
    // 0x8080021C: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80800220: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800224: b           L_8080023C
    // 0x80800228: swc1        $f4, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f4.u32l;
        goto L_8080023C;
    // 0x80800228: swc1        $f4, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f4.u32l;
L_8080022C:
    // 0x8080022C: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
L_80800230:
    // 0x80800230: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800234: nop

    // 0x80800238: swc1        $f6, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f6.u32l;
L_8080023C:
    // 0x8080023C: lui         $a2, 0x3FB3
    ctx->r6 = S32(0X3FB3 << 16);
    // 0x80800240: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800248: addiu       $a1, $zero, 0x5A7
    ctx->r5 = ADD32(0, 0X5A7);
    // 0x8080024C: jal         0x8009DF94
    // 0x80800250: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    func_8009DF94(rdram, ctx);
        goto after_4;
    // 0x80800250: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    after_4:
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800258: jal         0x80095760
    // 0x8080025C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    baflag_set(rdram, ctx);
        goto after_5;
    // 0x8080025C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_5:
    // 0x80800260: lui         $a2, 0x3C23
    ctx->r6 = S32(0X3C23 << 16);
    // 0x80800264: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080026C: jal         0x80085338
    // 0x80800270: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_set(rdram, ctx);
        goto after_6;
    // 0x80800270: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80800274: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80800278: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800280: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800284: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800288: jal         0x8009FFD8
    // 0x8080028C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_7;
    // 0x8080028C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_7:
    // 0x80800290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800294: jal         0x80084A28
    // 0x80800298: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _badust_entrypoint_12(rdram, ctx);
        goto after_8;
    // 0x80800298: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x8080029C: jal         0x8009C990
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_9;
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808002A4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808002A8: jal         0x8009B9C0
    // 0x808002AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_10;
    // 0x808002AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808002B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B4: jal         0x8009B9B0
    // 0x808002B8: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_11;
    // 0x808002B8: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    after_11:
    // 0x808002BC: jal         0x8009C990
    // 0x808002C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_12;
    // 0x808002C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808002C4: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x808002C8: jal         0x8009BB00
    // 0x808002CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_13;
    // 0x808002CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808002D0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808002D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002D8: jal         0x8009BA68
    // 0x808002DC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_14;
    // 0x808002DC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_14:
    // 0x808002E0: jal         0x8008AF24
    // 0x808002E4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_reset(rdram, ctx);
        goto after_15;
    // 0x808002E4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_15:
    // 0x808002E8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808002EC: jal         0x8008AED4
    // 0x808002F0: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    anctrl_setIndex(rdram, ctx);
        goto after_16;
    // 0x808002F0: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    after_16:
    // 0x808002F4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808002F8: jal         0x8008B1BC
    // 0x808002FC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_17;
    // 0x808002FC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_17:
    // 0x80800300: lui         $a2, 0x3E85
    ctx->r6 = S32(0X3E85 << 16);
    // 0x80800304: ori         $a2, $a2, 0x1EB8
    ctx->r6 = ctx->r6 | 0X1EB8;
    // 0x80800308: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8080030C: jal         0x8008B1D4
    // 0x80800310: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_18;
    // 0x80800310: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_18:
    // 0x80800314: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800318: jal         0x8008B134
    // 0x8080031C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_19;
    // 0x8080031C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x80800320: jal         0x8008B064
    // 0x80800324: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_start(rdram, ctx);
        goto after_20;
    // 0x80800324: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_20:
    // 0x80800328: b           L_808003A8
    // 0x8080032C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808003A8;
    // 0x8080032C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800330:
    // 0x80800330: jal         0x8008B1BC
    // 0x80800334: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_21;
    // 0x80800334: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    after_21:
    // 0x80800338: lui         $a1, 0x3E9D
    ctx->r5 = S32(0X3E9D << 16);
    // 0x8080033C: ori         $a1, $a1, 0x97F6
    ctx->r5 = ctx->r5 | 0X97F6;
    // 0x80800340: jal         0x8008CED4
    // 0x80800344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_setEnd(rdram, ctx);
        goto after_22;
    // 0x80800344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80800348: b           L_808003A8
    // 0x8080034C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808003A8;
    // 0x8080034C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800350:
    // 0x80800350: jal         0x80084A28
    // 0x80800354: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _badust_entrypoint_12(rdram, ctx);
        goto after_23;
    // 0x80800354: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_23:
    // 0x80800358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080035C: jal         0x80095774
    // 0x80800360: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    baflag_clear(rdram, ctx);
        goto after_24;
    // 0x80800360: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_24:
    // 0x80800364: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800368: jal         0x8008B1BC
    // 0x8080036C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_25;
    // 0x8080036C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_25:
    // 0x80800370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800374: jal         0x8008CED4
    // 0x80800378: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    baanim_setEnd(rdram, ctx);
        goto after_26;
    // 0x80800378: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_26:
    // 0x8080037C: b           L_808003A8
    // 0x80800380: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808003A8;
    // 0x80800380: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800384:
    // 0x80800384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800388: jal         0x80084A28
    // 0x8080038C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _badust_entrypoint_12(rdram, ctx);
        goto after_27;
    // 0x8080038C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_27:
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800394: jal         0x80095774
    // 0x80800398: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    baflag_clear(rdram, ctx);
        goto after_28;
    // 0x80800398: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_28:
    // 0x8080039C: jal         0x80800000
    // 0x808003A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsstonehead(rdram, ctx);
        goto after_29;
    // 0x808003A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x808003A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808003A8:
    // 0x808003A8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808003AC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808003B0: jr          $ra
    // 0x808003B4: nop

    return;
    // 0x808003B4: nop

;}
RECOMP_FUNC void chfirefx_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1104, 0X1248) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x1248
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1104, 0X1248));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x1248
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1104, 0X1248));
;}
RECOMP_FUNC void bskazstilt_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E0C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800E10: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800E14: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800E18: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800E1C: jal         0x8008CABC
    // 0x80800E20: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800E20: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    after_0:
    // 0x80800E24: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800E28: jal         0x8080013C
    // 0x80800E2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080013C_bskazstilt(rdram, ctx);
        goto after_1;
    // 0x80800E2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800E30: jal         0x8008AF24
    // 0x80800E34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    anctrl_reset(rdram, ctx);
        goto after_2;
    // 0x80800E34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80800E38: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800E3C: jal         0x8008AED4
    // 0x80800E40: addiu       $a1, $zero, 0x14A
    ctx->r5 = ADD32(0, 0X14A);
    anctrl_setIndex(rdram, ctx);
        goto after_3;
    // 0x80800E40: addiu       $a1, $zero, 0x14A
    ctx->r5 = ADD32(0, 0X14A);
    after_3:
    // 0x80800E44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800E48: jal         0x8008B134
    // 0x80800E4C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_4;
    // 0x80800E4C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x80800E50: lui         $a1, 0x3DB1
    ctx->r5 = S32(0X3DB1 << 16);
    // 0x80800E54: ori         $a1, $a1, 0x26E9
    ctx->r5 = ctx->r5 | 0X26E9;
    // 0x80800E58: jal         0x8008B24C
    // 0x80800E5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    anctrl_setStart(rdram, ctx);
        goto after_5;
    // 0x80800E5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80800E60: jal         0x8008B064
    // 0x80800E64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    anctrl_start(rdram, ctx);
        goto after_6;
    // 0x80800E64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x80800E68: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80800E6C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800E70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800E78: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800E7C: jal         0x8009FFD8
    // 0x80800E80: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_7;
    // 0x80800E80: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_7:
    // 0x80800E84: jal         0x8009C990
    // 0x80800E88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_8;
    // 0x80800E88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800E8C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800E90: jal         0x8009B9C0
    // 0x80800E94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_9;
    // 0x80800E94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800E98: jal         0x8009C990
    // 0x80800E9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_10;
    // 0x80800E9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800EA0: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800EA4: jal         0x8009BB00
    // 0x80800EA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_11;
    // 0x80800EA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800EAC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800EB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EB4: jal         0x8009BA68
    // 0x80800EB8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_12;
    // 0x80800EB8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_12:
    // 0x80800EBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EC0: jal         0x800A0CF4
    // 0x80800EC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_13;
    // 0x80800EC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x80800EC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800ECC: jal         0x800A0CE8
    // 0x80800ED0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CE8(rdram, ctx);
        goto after_14;
    // 0x80800ED0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x80800ED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800ED8: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x80800EDC: jal         0x8009BFE4
    // 0x80800EE0: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    func_8009BFE4(rdram, ctx);
        goto after_15;
    // 0x80800EE0: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_15:
    // 0x80800EE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EE8: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x80800EEC: jal         0x8009C554
    // 0x80800EF0: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    baroll_setAngularVelocity(rdram, ctx);
        goto after_16;
    // 0x80800EF0: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_16:
    // 0x80800EF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EF8: jal         0x8009B9B0
    // 0x80800EFC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_17;
    // 0x80800EFC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_17:
    // 0x80800F00: jal         0x8009D658
    // 0x80800F04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D658(rdram, ctx);
        goto after_18;
    // 0x80800F04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800F08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800F10: jal         0x80085338
    // 0x80800F14: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    _batimer_set(rdram, ctx);
        goto after_19;
    // 0x80800F14: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_19:
    // 0x80800F18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800F1C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800F20: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800F24: jr          $ra
    // 0x80800F28: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800F28: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void _gccubesearch_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800882F8: syscall     678
    recomp_syscall_handler(rdram, ctx, 0x800882F8);
    return;
    // 0x800882FC: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void plcamera_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000D0: jal         0x800F5EF8
    // 0x808000D4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800F5EF8(rdram, ctx);
        goto after_0;
    // 0x808000D4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808000D8: jal         0x80110014
    // 0x808000DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110014(rdram, ctx);
        goto after_1;
    // 0x808000DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808000E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000E4: jal         0x801106A8
    // 0x808000E8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_801106A8(rdram, ctx);
        goto after_2;
    // 0x808000E8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x808000EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000F4: jr          $ra
    // 0x808000F8: nop

    return;
    // 0x808000F8: nop

;}
RECOMP_FUNC void chtransparentfish_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B54: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2232, 0X1098) << 16);
    // 0x80800B58: jr          $ra
    // 0x80800B5C: addiu       $v0, $v0, 0x1098
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2232, 0X1098));
    return;
    // 0x80800B5C: addiu       $v0, $v0, 0x1098
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2232, 0X1098));
;}
RECOMP_FUNC void badata_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A9C: jr          $ra
    // 0x80800AA0: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    return;
    // 0x80800AA0: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
;}
RECOMP_FUNC void _chjigsaw_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800858A8: syscall     178
    recomp_syscall_handler(rdram, ctx, 0x800858A8);
    return;
    // 0x800858AC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _suspline_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089D90: syscall     811
    recomp_syscall_handler(rdram, ctx, 0x80089D90);
    return;
    // 0x80089D94: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80801588_chtoothyfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801588: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080158C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801590: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80801594: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801598: jal         0x80100094
    // 0x8080159C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080159C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808015A0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x808015A4: addiu       $a0, $zero, 0x310
    ctx->r4 = ADD32(0, 0X310);
    // 0x808015A8: jal         0x801084B0
    // 0x808015AC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_801084B0(rdram, ctx);
        goto after_1;
    // 0x808015AC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_1:
    // 0x808015B0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808015B4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808015B8: jal         0x800DA544
    // 0x808015BC: addiu       $a0, $a0, 0x4F6
    ctx->r4 = ADD32(ctx->r4, 0X4F6);
    func_800DA544(rdram, ctx);
        goto after_2;
    // 0x808015BC: addiu       $a0, $a0, 0x4F6
    ctx->r4 = ADD32(ctx->r4, 0X4F6);
    after_2:
    // 0x808015C0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x808015C4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x808015C8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808015CC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808015D0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x808015D4: sb          $t6, 0x34($t9)
    MEM_B(0X34, ctx->r25) = ctx->r14;
    // 0x808015D8: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x808015DC: lhu         $t5, 0x6E($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X6E);
    // 0x808015E0: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x808015E4: andi        $t7, $t5, 0xFE00
    ctx->r15 = ctx->r13 & 0XFE00;
    // 0x808015E8: sw          $t1, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r9;
    // 0x808015EC: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x808015F0: andi        $t4, $t3, 0x1FF
    ctx->r12 = ctx->r11 & 0X1FF;
    // 0x808015F4: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x808015F8: sh          $t8, 0x6E($v1)
    MEM_H(0X6E, ctx->r3) = ctx->r24;
    // 0x808015FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801600: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801604: jr          $ra
    // 0x80801608: nop

    return;
    // 0x80801608: nop

;}
