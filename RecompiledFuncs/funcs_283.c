#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _chseaweedbaddy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085F28: syscall     261
    recomp_syscall_handler(rdram, ctx, 0x80085F28);
    return;
    // 0x80085F2C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800A51C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A51C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A51C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A51C8: jal         0x800F54E4
    // 0x800A51CC: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x800A51CC: nop

    after_0:
    // 0x800A51D0: jal         0x800878B8
    // 0x800A51D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _plcamera_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x800A51D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800A51D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A51DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A51E0: jr          $ra
    // 0x800A51E4: nop

    return;
    // 0x800A51E4: nop

;}
RECOMP_FUNC void _bsstonehead_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083C50: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083C50);
    return;
    // 0x80083C54: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void func_8008F748(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F748: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008F74C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8008F750: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008F754: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8008F758: jal         0x80088278
    // 0x8008F75C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    _gccubesearch_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x8008F75C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x8008F760: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008F764: jal         0x80088C00
    // 0x8008F768: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x8008F768: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x8008F76C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8008F770: jal         0x800A3514
    // 0x8008F774: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800A3514(rdram, ctx);
        goto after_2;
    // 0x8008F774: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_2:
    // 0x8008F778: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008F77C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8008F780: jr          $ra
    // 0x8008F784: nop

    return;
    // 0x8008F784: nop

;}
RECOMP_FUNC void func_80800210_bsmumstill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800210: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800214: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800218: jal         0x80083808
    // 0x8080021C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _bsmum_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x8080021C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800220: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800224: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800228: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080022C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800230: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800234: jal         0x8009FFD8
    // 0x80800238: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x80800238: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x8080023C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800240: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800244: jr          $ra
    // 0x80800248: nop

    return;
    // 0x80800248: nop

;}
RECOMP_FUNC void func_80081BC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081BC0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80081BC4: lui         $at, 0xFC00
    ctx->r1 = S32(0XFC00 << 16);
    // 0x80081BC8: ori         $at, $at, 0x3F
    ctx->r1 = ctx->r1 | 0X3F;
    // 0x80081BCC: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80081BD0: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80081BD4: bne         $t7, $at, L_80081BE4
    if (ctx->r15 != ctx->r1) {
        // 0x80081BD8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80081BE4;
    }
    // 0x80081BD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80081BDC: jr          $ra
    // 0x80081BE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80081BE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80081BE4:
    // 0x80081BE4: jr          $ra
    // 0x80081BE8: nop

    return;
    // 0x80081BE8: nop

;}
RECOMP_FUNC void bsstatue_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D0C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800D10: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(372, 0X15D0) << 16);
    // 0x80800D14: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800D18: jr          $ra
    // 0x80800D1C: lw          $v0, 0x15D0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(372, 0X15D0));
    return;
    // 0x80800D1C: lw          $v0, 0x15D0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(372, 0X15D0));
;}
RECOMP_FUNC void _cosection_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087890: syscall     637
    recomp_syscall_handler(rdram, ctx, 0x80087890);
    return;
    // 0x80087894: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80801C7C_chfactoryrobot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801C80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801C84: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801C88: jal         0x80100094
    // 0x80801C8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801C8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801C90: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80801C94: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x80801C98: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80801C9C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801CA0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80801CA4: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80801CA8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80801CAC: lw          $a0, 0x70($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X70);
    // 0x80801CB0: addiu       $a1, $a3, 0x18
    ctx->r5 = ADD32(ctx->r7, 0X18);
    // 0x80801CB4: srl         $t6, $a0, 25
    ctx->r14 = S32(U32(ctx->r4) >> 25);
    // 0x80801CB8: addiu       $a0, $t6, -0x1
    ctx->r4 = ADD32(ctx->r14, -0X1);
    // 0x80801CBC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80801CC0: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80801CC4: jal         0x800CD1E0
    // 0x80801CC8: nop

    func_800CD1E0(rdram, ctx);
        goto after_1;
    // 0x80801CC8: nop

    after_1:
    // 0x80801CCC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80801CD0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801CD4: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80801CD8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801CDC: jal         0x800DC178
    // 0x80801CE0: nop

    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80801CE0: nop

    after_2:
    // 0x80801CE4: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80801CE8: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80801CEC: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x80801CF0: nop

    // 0x80801CF4: sh          $t9, 0x6($t0)
    MEM_H(0X6, ctx->r8) = ctx->r25;
    // 0x80801CF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801CFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801D00: jr          $ra
    // 0x80801D04: nop

    return;
    // 0x80801D04: nop

;}
RECOMP_FUNC void func_80092E08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092E08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80092E0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80092E10: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80092E14: jal         0x800921E0
    // 0x80092E18: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_800921E0(rdram, ctx);
        goto after_0;
    // 0x80092E18: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_0:
    // 0x80092E1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80092E20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80092E24: jr          $ra
    // 0x80092E28: nop

    return;
    // 0x80092E28: nop

;}
RECOMP_FUNC void func_80102D78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102D78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102D7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80102D80: jal         0x800F1DF4
    // 0x80102D84: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800F1DF4(rdram, ctx);
        goto after_0;
    // 0x80102D84: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80102D88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80102D8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80102D90: jr          $ra
    // 0x80102D94: nop

    return;
    // 0x80102D94: nop

;}
RECOMP_FUNC void func_80802414_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802414: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802418: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080241C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80802420: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802424: jal         0x80100094
    // 0x80802428: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802428: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080242C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80802430: jal         0x808026F0
    // 0x80802434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808026F0_chboilerboss(rdram, ctx);
        goto after_1;
    // 0x80802434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80802438: jal         0x800A51C0
    // 0x8080243C: nop

    func_800A51C0(rdram, ctx);
        goto after_2;
    // 0x8080243C: nop

    after_2:
    // 0x80802440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802444: jal         0x80800F34
    // 0x80802448: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800F34_chboilerboss(rdram, ctx);
        goto after_3;
    // 0x80802448: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_3:
    // 0x8080244C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802450: jal         0x80109FE8
    // 0x80802454: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80109FE8(rdram, ctx);
        goto after_4;
    // 0x80802454: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80802458: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8080245C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80802460: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(932, 0X2B5C) << 16);
    // 0x80802464: sb          $t6, 0x55($v0)
    MEM_B(0X55, ctx->r2) = ctx->r14;
    // 0x80802468: lwc1        $f4, 0x2B5C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(932, 0X2B5C));
    // 0x8080246C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80802470: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80802474: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80802478: addiu       $a0, $zero, 0x179
    ctx->r4 = ADD32(0, 0X179);
    // 0x8080247C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80802480: sw          $t7, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->r15;
    // 0x80802484: jal         0x800DA544
    // 0x80802488: swc1        $f8, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f8.u32l;
    func_800DA544(rdram, ctx);
        goto after_5;
    // 0x80802488: swc1        $f8, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f8.u32l;
    after_5:
    // 0x8080248C: jal         0x80088178
    // 0x80802490: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    _gcfrontend_entrypoint_9(rdram, ctx);
        goto after_6;
    // 0x80802490: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    after_6:
    // 0x80802494: jal         0x8010A590
    // 0x80802498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_7;
    // 0x80802498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080249C: jal         0x800FDC28
    // 0x808024A0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800FDC28(rdram, ctx);
        goto after_8;
    // 0x808024A0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_8:
    // 0x808024A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808024A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808024AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808024B0: jr          $ra
    // 0x808024B4: nop

    return;
    // 0x808024B4: nop

;}
RECOMP_FUNC void func_800F20BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F20BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F20C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F20C4: jal         0x800F2094
    // 0x800F20C8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800F2094(rdram, ctx);
        goto after_0;
    // 0x800F20C8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800F20CC: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F20D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F20D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F20D8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800F20DC: nop

    // 0x800F20E0: bc1f        L_800F20EC
    if (!c1cs) {
        // 0x800F20E4: nop
    
            goto L_800F20EC;
    }
    // 0x800F20E4: nop

    // 0x800F20E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F20EC:
    // 0x800F20EC: jr          $ra
    // 0x800F20F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800F20F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F20F4: nop

    // 0x800F20F8: nop

    // 0x800F20FC: nop

;}
RECOMP_FUNC void func_80800014_chtnthut(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800014: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800018: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080001C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800020: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800024: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800028: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080002C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800030: bnel        $t7, $at, L_808000A0
    if (ctx->r15 != ctx->r1) {
        // 0x80800034: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808000A0;
    }
    goto skip_0;
    // 0x80800034: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800038: jal         0x800D8FF8
    // 0x8080003C: nop

    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x8080003C: nop

    after_0:
    // 0x80800040: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800044: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800048: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080004C: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80800050: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x80800054: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80800058: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(908, 0X210) << 16);
    // 0x8080005C: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    // 0x80800060: lwc1        $f10, 0x58($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800064: addiu       $a0, $zero, 0x43F
    ctx->r4 = ADD32(0, 0X43F);
    // 0x80800068: addiu       $a2, $zero, 0x6D60
    ctx->r6 = ADD32(0, 0X6D60);
    // 0x8080006C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80800070: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    // 0x80800074: bc1fl       L_808000A0
    if (!c1cs) {
        // 0x80800078: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808000A0;
    }
    goto skip_1;
    // 0x80800078: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8080007C: lwc1        $f16, 0x210($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(908, 0X210));
    // 0x80800080: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(908, 0X214) << 16);
    // 0x80800084: lwc1        $f18, 0x214($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(908, 0X214));
    // 0x80800088: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8080008C: jal         0x800C4104
    // 0x80800090: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_800C4104(rdram, ctx);
        goto after_1;
    // 0x80800090: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x80800094: jal         0x800FFAB0
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080009C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000A0:
    // 0x808000A0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808000A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000A8: jr          $ra
    // 0x808000AC: nop

    return;
    // 0x808000AC: nop

;}
RECOMP_FUNC void func_80800050_gspropprop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800050: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800054: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800058: jal         0x80088C88
    // 0x8080005C: nop

    _gsproplookup_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x8080005C: nop

    after_0:
    // 0x80800060: jal         0x800BFC34
    // 0x80800064: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800BFC34(rdram, ctx);
        goto after_1;
    // 0x80800064: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800068: jal         0x800B2840
    // 0x8080006C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B2840(rdram, ctx);
        goto after_2;
    // 0x8080006C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800070: jal         0x800B2354
    // 0x80800074: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B2354(rdram, ctx);
        goto after_3;
    // 0x80800074: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80800078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080007C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800080: jr          $ra
    // 0x80800084: nop

    return;
    // 0x80800084: nop

;}
RECOMP_FUNC void func_800C431C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C431C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C4320: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C4324: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C4328: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800C432C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800C4330: jal         0x800C1414
    // 0x800C4334: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800C1414(rdram, ctx);
        goto after_0;
    // 0x800C4334: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800C4338: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800C433C: sb          $t7, 0x63($v0)
    MEM_B(0X63, ctx->r2) = ctx->r15;
    // 0x800C4340: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C4344: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C4348: jr          $ra
    // 0x800C434C: nop

    return;
    // 0x800C434C: nop

;}
RECOMP_FUNC void func_800CA314(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA314: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CA318: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CA31C: jal         0x8001BBC8
    // 0x800CA320: addiu       $a2, $zero, 0x168
    ctx->r6 = ADD32(0, 0X168);
    aligned4_memcpy(rdram, ctx);
        goto after_0;
    // 0x800CA320: addiu       $a2, $zero, 0x168
    ctx->r6 = ADD32(0, 0X168);
    after_0:
    // 0x800CA324: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CA328: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CA32C: jr          $ra
    // 0x800CA330: nop

    return;
    // 0x800CA330: nop

;}
RECOMP_FUNC void func_80800F64_chglowbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F64: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800F68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800F6C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800F70: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800F74: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800F78: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800F7C: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800F80: beq         $t6, $at, L_80800F98
    if (ctx->r14 == ctx->r1) {
        // 0x80800F84: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_80800F98;
    }
    // 0x80800F84: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80800F88: beql        $t6, $at, L_808010A4
    if (ctx->r14 == ctx->r1) {
        // 0x80800F8C: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_808010A4;
    }
    goto skip_0;
    // 0x80800F8C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    skip_0:
    // 0x80800F90: b           L_80801108
    // 0x80800F94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801108;
    // 0x80800F94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800F98:
    // 0x80800F98: jal         0x80801258
    // 0x80800F9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801258_chglowbo(rdram, ctx);
        goto after_0;
    // 0x80800F9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800FA0: lwc1        $f2, 0x1C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80800FA4: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800FA8: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x80800FAC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800FB0: lwc1        $f4, 0x44($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80800FB4: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80800FB8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800FBC: bc1t        L_80800FE0
    if (c1cs) {
        // 0x80800FC0: swc1        $f8, 0x44($s0)
        MEM_W(0X44, ctx->r16) = ctx->f8.u32l;
            goto L_80800FE0;
    }
    // 0x80800FC0: swc1        $f8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f8.u32l;
    // 0x80800FC4: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800FC8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800FCC: nop

    // 0x80800FD0: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80800FD4: nop

    // 0x80800FD8: bc1fl       L_80801028
    if (!c1cs) {
        // 0x80800FDC: c.le.s      $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
            goto L_80801028;
    }
    goto skip_1;
    // 0x80800FDC: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    skip_1:
L_80800FE0:
    // 0x80800FE0: jal         0x800D8FF8
    // 0x80800FE4: nop

    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80800FE4: nop

    after_1:
    // 0x80800FE8: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800FEC: lwc1        $f16, 0x2C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800FF0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800FF4: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80800FF8: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80800FFC: lw          $a2, 0x24($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X24);
    // 0x80801000: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80801004: jal         0x800EF1B8
    // 0x80801008: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    func_800EF1B8(rdram, ctx);
        goto after_2;
    // 0x80801008: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    after_2:
    // 0x8080100C: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80801010: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80801014: lwc1        $f2, 0x1C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80801018: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8080101C: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x80801020: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80801024: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
L_80801028:
    // 0x80801028: nop

    // 0x8080102C: bc1fl       L_80801108
    if (!c1cs) {
        // 0x80801030: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801108;
    }
    goto skip_2;
    // 0x80801030: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80801034: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80801038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080103C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801040: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x80801044: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1628, 0X1448) << 16);
    // 0x80801048: bc1fl       L_80801108
    if (!c1cs) {
        // 0x8080104C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801108;
    }
    goto skip_3;
    // 0x8080104C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80801050: jal         0x80089D18
    // 0x80801054: addiu       $a2, $a2, 0x1448
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1628, 0X1448));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80801054: addiu       $a2, $a2, 0x1448
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1628, 0X1448));
    after_3:
    // 0x80801058: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8080105C: lwc1        $f16, 0x1C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80801060: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801064: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801068: lwc1        $f12, 0x44($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8080106C: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    // 0x80801070: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    // 0x80801074: jal         0x800136E4
    // 0x80801078: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    func_800136E4(rdram, ctx);
        goto after_4;
    // 0x80801078: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    after_4:
    // 0x8080107C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80801080: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801084: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x80801088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080108C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80801090: jal         0x80101FDC
    // 0x80801094: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    func_80101FDC(rdram, ctx);
        goto after_5;
    // 0x80801094: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    after_5:
    // 0x80801098: b           L_80801108
    // 0x8080109C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801108;
    // 0x8080109C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808010A0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
L_808010A4:
    // 0x808010A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808010A8: lwc1        $f0, 0x44($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X44);
    // 0x808010AC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1628, 0X13A0) << 16);
    // 0x808010B0: lwc1        $f16, 0x13A0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1628, 0X13A0));
    // 0x808010B4: sub.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x808010B8: lui         $a1, 0x50
    ctx->r5 = S32(0X50 << 16);
    // 0x808010BC: ori         $a1, $a1, 0x1105
    ctx->r5 = ctx->r5 | 0X1105;
    // 0x808010C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010C4: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x808010C8: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x808010CC: jal         0x8010B990
    // 0x808010D0: swc1        $f6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f6.u32l;
    func_8010B990(rdram, ctx);
        goto after_6;
    // 0x808010D0: swc1        $f6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f6.u32l;
    after_6:
    // 0x808010D4: andi        $t7, $v0, 0x24
    ctx->r15 = ctx->r2 & 0X24;
    // 0x808010D8: beql        $t7, $zero, L_808010EC
    if (ctx->r15 == 0) {
        // 0x808010DC: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_808010EC;
    }
    goto skip_4;
    // 0x808010DC: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    skip_4:
    // 0x808010E0: jal         0x80089CA8
    // 0x808010E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_7;
    // 0x808010E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808010E8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
L_808010EC:
    // 0x808010EC: jal         0x8010CAC0
    // 0x808010F0: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    func_8010CAC0(rdram, ctx);
        goto after_8;
    // 0x808010F0: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    after_8:
    // 0x808010F4: bnel        $v0, $zero, L_80801108
    if (ctx->r2 != 0) {
        // 0x808010F8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801108;
    }
    goto skip_5;
    // 0x808010F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x808010FC: jal         0x80089CA8
    // 0x80801100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_9;
    // 0x80801100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80801104: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801108:
    // 0x80801108: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080110C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801110: jr          $ra
    // 0x80801114: nop

    return;
    // 0x80801114: nop

;}
RECOMP_FUNC void _ncbawaypoint_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089458: syscall     780
    recomp_syscall_handler(rdram, ctx, 0x80089458);
    return;
    // 0x8008945C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800C44_chfiregen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C44: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800C48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C4C: jal         0x800D8FF8
    // 0x80800C50: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800C50: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800C54: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80800C58: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800C5C: lwc1        $f2, 0x24($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X24);
    // 0x80800C60: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x80800C64: nop

    // 0x80800C68: bc1fl       L_80800C80
    if (!c1cs) {
        // 0x80800C6C: lw          $a0, 0x6C($a2)
        ctx->r4 = MEM_W(ctx->r6, 0X6C);
            goto L_80800C80;
    }
    goto skip_0;
    // 0x80800C6C: lw          $a0, 0x6C($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X6C);
    skip_0:
    // 0x80800C70: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80800C74: b           L_80800E44
    // 0x80800C78: swc1        $f6, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->f6.u32l;
        goto L_80800E44;
    // 0x80800C78: swc1        $f6, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->f6.u32l;
    // 0x80800C7C: lw          $a0, 0x6C($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X6C);
L_80800C80:
    // 0x80800C80: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800C84: andi        $t6, $a0, 0x1FF
    ctx->r14 = ctx->r4 & 0X1FF;
    // 0x80800C88: jal         0x800DA298
    // 0x80800C8C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800C8C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_1:
    // 0x80800C90: beq         $v0, $zero, L_80800CCC
    if (ctx->r2 == 0) {
        // 0x80800C94: lw          $a2, 0x38($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X38);
            goto L_80800CCC;
    }
    // 0x80800C94: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80800C98: lhu         $v0, 0x72($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X72);
    // 0x80800C9C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800CA0: srl         $t7, $v0, 10
    ctx->r15 = S32(U32(ctx->r2) >> 10);
    // 0x80800CA4: beq         $t7, $at, L_80800CFC
    if (ctx->r15 == ctx->r1) {
        // 0x80800CA8: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_80800CFC;
    }
    // 0x80800CA8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80800CAC: lbu         $t8, 0x72($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X72);
    // 0x80800CB0: andi        $t9, $t8, 0xFF03
    ctx->r25 = ctx->r24 & 0XFF03;
    // 0x80800CB4: ori         $t0, $t9, 0x8
    ctx->r8 = ctx->r25 | 0X8;
    // 0x80800CB8: sb          $t0, 0x72($a2)
    MEM_B(0X72, ctx->r6) = ctx->r8;
    // 0x80800CBC: lhu         $v0, 0x72($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X72);
    // 0x80800CC0: srl         $t1, $v0, 10
    ctx->r9 = S32(U32(ctx->r2) >> 10);
    // 0x80800CC4: b           L_80800CFC
    // 0x80800CC8: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_80800CFC;
    // 0x80800CC8: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_80800CCC:
    // 0x80800CCC: lhu         $v0, 0x72($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X72);
    // 0x80800CD0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800CD4: srl         $t2, $v0, 10
    ctx->r10 = S32(U32(ctx->r2) >> 10);
    // 0x80800CD8: beq         $t2, $at, L_80800CFC
    if (ctx->r10 == ctx->r1) {
        // 0x80800CDC: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_80800CFC;
    }
    // 0x80800CDC: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80800CE0: lbu         $t3, 0x72($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X72);
    // 0x80800CE4: andi        $t4, $t3, 0xFF03
    ctx->r12 = ctx->r11 & 0XFF03;
    // 0x80800CE8: ori         $t5, $t4, 0x10
    ctx->r13 = ctx->r12 | 0X10;
    // 0x80800CEC: sb          $t5, 0x72($a2)
    MEM_B(0X72, ctx->r6) = ctx->r13;
    // 0x80800CF0: lhu         $v0, 0x72($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X72);
    // 0x80800CF4: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800CF8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_80800CFC:
    // 0x80800CFC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800D00: beq         $v0, $at, L_80800D1C
    if (ctx->r2 == ctx->r1) {
        // 0x80800D04: or          $v1, $a2, $zero
        ctx->r3 = ctx->r6 | 0;
            goto L_80800D1C;
    }
    // 0x80800D04: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x80800D08: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800D0C: beq         $v0, $at, L_80800D60
    if (ctx->r2 == ctx->r1) {
        // 0x80800D10: nop
    
            goto L_80800D60;
    }
    // 0x80800D10: nop

    // 0x80800D14: b           L_80800D9C
    // 0x80800D18: lwc1        $f4, 0x4C($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4C);
        goto L_80800D9C;
    // 0x80800D18: lwc1        $f4, 0x4C($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4C);
L_80800D1C:
    // 0x80800D1C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X1504) << 16);
    // 0x80800D20: lwc1        $f8, 0x1504($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X1504));
    // 0x80800D24: lwc1        $f0, 0x30($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X30);
    // 0x80800D28: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X1508) << 16);
    // 0x80800D2C: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x80800D30: nop

    // 0x80800D34: bc1fl       L_80800D50
    if (!c1cs) {
        // 0x80800D38: lbu         $t7, 0x72($a2)
        ctx->r15 = MEM_BU(ctx->r6, 0X72);
            goto L_80800D50;
    }
    goto skip_1;
    // 0x80800D38: lbu         $t7, 0x72($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X72);
    skip_1:
    // 0x80800D3C: lwc1        $f10, 0x1508($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X1508));
    // 0x80800D40: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80800D44: b           L_80800D98
    // 0x80800D48: swc1        $f16, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->f16.u32l;
        goto L_80800D98;
    // 0x80800D48: swc1        $f16, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->f16.u32l;
    // 0x80800D4C: lbu         $t7, 0x72($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X72);
L_80800D50:
    // 0x80800D50: andi        $t8, $t7, 0xFF03
    ctx->r24 = ctx->r15 & 0XFF03;
    // 0x80800D54: ori         $t9, $t8, 0xC
    ctx->r25 = ctx->r24 | 0XC;
    // 0x80800D58: b           L_80800D98
    // 0x80800D5C: sb          $t9, 0x72($a2)
    MEM_B(0X72, ctx->r6) = ctx->r25;
        goto L_80800D98;
    // 0x80800D5C: sb          $t9, 0x72($a2)
    MEM_B(0X72, ctx->r6) = ctx->r25;
L_80800D60:
    // 0x80800D60: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X150C) << 16);
    // 0x80800D64: lwc1        $f2, 0x150C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X150C));
    // 0x80800D68: lwc1        $f0, 0x30($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X30);
    // 0x80800D6C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80800D70: nop

    // 0x80800D74: bc1fl       L_80800D8C
    if (!c1cs) {
        // 0x80800D78: lbu         $t0, 0x72($a2)
        ctx->r8 = MEM_BU(ctx->r6, 0X72);
            goto L_80800D8C;
    }
    goto skip_2;
    // 0x80800D78: lbu         $t0, 0x72($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X72);
    skip_2:
    // 0x80800D7C: sub.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80800D80: b           L_80800D98
    // 0x80800D84: swc1        $f18, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->f18.u32l;
        goto L_80800D98;
    // 0x80800D84: swc1        $f18, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->f18.u32l;
    // 0x80800D88: lbu         $t0, 0x72($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X72);
L_80800D8C:
    // 0x80800D8C: andi        $t1, $t0, 0xFF03
    ctx->r9 = ctx->r8 & 0XFF03;
    // 0x80800D90: ori         $t2, $t1, 0x4
    ctx->r10 = ctx->r9 | 0X4;
    // 0x80800D94: sb          $t2, 0x72($a2)
    MEM_B(0X72, ctx->r6) = ctx->r10;
L_80800D98:
    // 0x80800D98: lwc1        $f4, 0x4C($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4C);
L_80800D9C:
    // 0x80800D9C: lwc1        $f6, 0x30($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X30);
    // 0x80800DA0: addiu       $v0, $sp, 0x24
    ctx->r2 = ADD32(ctx->r29, 0X24);
    // 0x80800DA4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800DA8: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80800DAC: nop

    // 0x80800DB0: bc1tl       L_80800E48
    if (c1cs) {
        // 0x80800DB4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800E48;
    }
    goto skip_3;
    // 0x80800DB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x80800DB8: lwc1        $f16, 0x30($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X30);
    // 0x80800DBC: lwc1        $f14, 0x18($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80800DC0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800DC4: mul.s       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80800DC8: beql        $v0, $a0, L_80800E00
    if (ctx->r2 == ctx->r4) {
        // 0x80800DCC: trunc.w.s   $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
            goto L_80800E00;
    }
    goto skip_4;
    // 0x80800DCC: trunc.w.s   $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
    skip_4:
    // 0x80800DD0: trunc.w.s   $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
L_80800DD4:
    // 0x80800DD4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800DD8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800DDC: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    // 0x80800DE0: nop

    // 0x80800DE4: sw          $t4, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->r12;
    // 0x80800DE8: lwc1        $f16, 0x30($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X30);
    // 0x80800DEC: lwc1        $f14, 0x18($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80800DF0: mul.s       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80800DF4: bnel        $v0, $a0, L_80800DD4
    if (ctx->r2 != ctx->r4) {
        // 0x80800DF8: trunc.w.s   $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
            goto L_80800DD4;
    }
    goto skip_5;
    // 0x80800DF8: trunc.w.s   $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
    skip_5:
    // 0x80800DFC: trunc.w.s   $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
L_80800E00:
    // 0x80800E00: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800E04: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    // 0x80800E08: nop

    // 0x80800E0C: sw          $t4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r12;
    // 0x80800E10: lwc1        $f4, 0x50($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X50);
    // 0x80800E14: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800E18: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80800E1C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800E20: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80800E24: jal         0x800C8E84
    // 0x80800E28: nop

    func_800C8E84(rdram, ctx);
        goto after_2;
    // 0x80800E28: nop

    after_2:
    // 0x80800E2C: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80800E30: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X1510) << 16);
    // 0x80800E34: lwc1        $f8, 0x30($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X30);
    // 0x80800E38: swc1        $f8, 0x4C($a2)
    MEM_W(0X4C, ctx->r6) = ctx->f8.u32l;
    // 0x80800E3C: lwc1        $f10, 0x1510($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X1510));
    // 0x80800E40: swc1        $f10, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->f10.u32l;
L_80800E44:
    // 0x80800E44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800E48:
    // 0x80800E48: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800E4C: jr          $ra
    // 0x80800E50: nop

    return;
    // 0x80800E50: nop

;}
RECOMP_FUNC void func_80806AD4_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806AD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80806AD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80806ADC: jal         0x80088360
    // 0x80806AE0: nop

    _gcstatusDll_entrypoint_10(rdram, ctx);
        goto after_0;
    // 0x80806AE0: nop

    after_0:
    // 0x80806AE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80806AE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80806AEC: jr          $ra
    // 0x80806AF0: nop

    return;
    // 0x80806AF0: nop

;}
RECOMP_FUNC void _bsmum_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083818: syscall     75
    recomp_syscall_handler(rdram, ctx, 0x80083818);
    return;
    // 0x8008381C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_808041D0_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808041D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808041D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808041D8: jal         0x80807BB8
    // 0x808041DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80807BB8_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x808041DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808041E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808041E4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x808041E8: jal         0x80802700
    // 0x808041EC: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    func_80802700_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x808041EC: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x808041F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808041F4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808041F8: jal         0x80804104
    // 0x808041FC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    func_80804104_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x808041FC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80804200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80804204: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80804208: jr          $ra
    // 0x8080420C: nop

    return;
    // 0x8080420C: nop

;}
RECOMP_FUNC void vpmodule_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800364: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800368: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8080036C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80800370: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80800374: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80800378: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8080037C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800380: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800384: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800388: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8080038C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800390: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80800394: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x80800398: lw          $t6, 0x1C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X1C);
    // 0x8080039C: lui         $s5, 0x8080
    ctx->r21 = S32(RELOC_HI16(3002, 0X8C0) << 16);
    // 0x808003A0: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x808003A4: addu        $v0, $a1, $t6
    ctx->r2 = ADD32(ctx->r5, ctx->r14);
    // 0x808003A8: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x808003AC: lw          $t8, 0x14($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X14);
    // 0x808003B0: addiu       $s5, $s5, 0x8C0
    ctx->r21 = ADD32(ctx->r21, (int16_t)RELOC_LO16(3002, 0X8C0));
    // 0x808003B4: addiu       $s6, $zero, 0x14
    ctx->r22 = ADD32(0, 0X14);
    // 0x808003B8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x808003BC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x808003C0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x808003C4: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x808003C8: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x808003CC: lw          $t2, 0x2C($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X2C);
    // 0x808003D0: sltu        $at, $v0, $t1
    ctx->r1 = ctx->r2 < ctx->r9 ? 1 : 0;
    // 0x808003D4: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x808003D8: addu        $t5, $t3, $a0
    ctx->r13 = ADD32(ctx->r11, ctx->r4);
    // 0x808003DC: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x808003E0: beq         $at, $zero, L_80800594
    if (ctx->r1 == 0) {
        // 0x808003E4: sw          $t6, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r14;
            goto L_80800594;
    }
    // 0x808003E4: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
    // 0x808003E8: lbu         $t7, 0x3($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X3);
L_808003EC:
    // 0x808003EC: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x808003F0: addiu       $a1, $v0, 0xA
    ctx->r5 = ADD32(ctx->r2, 0XA);
    // 0x808003F4: beql        $t7, $zero, L_80800584
    if (ctx->r15 == 0) {
        // 0x808003F8: lw          $t4, 0x44($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X44);
            goto L_80800584;
    }
    goto skip_0;
    // 0x808003F8: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x808003FC: jal         0x800E3DC0
    // 0x80800400: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    func_800E3DC0(rdram, ctx);
        goto after_0;
    // 0x80800400: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    after_0:
    // 0x80800404: bne         $v0, $zero, L_80800414
    if (ctx->r2 != 0) {
        // 0x80800408: lw          $v1, 0x58($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X58);
            goto L_80800414;
    }
    // 0x80800408: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x8080040C: b           L_80800580
    // 0x80800410: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
        goto L_80800580;
    // 0x80800410: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
L_80800414:
    // 0x80800414: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x80800418: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    // 0x8080041C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80800420: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x80800424: lbu         $a2, 0x2($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X2);
    // 0x80800428: addiu       $s0, $v1, 0x8
    ctx->r16 = ADD32(ctx->r3, 0X8);
    // 0x8080042C: addu        $s3, $v1, $t8
    ctx->r19 = ADD32(ctx->r3, ctx->r24);
    // 0x80800430: addu        $t2, $v1, $t9
    ctx->r10 = ADD32(ctx->r3, ctx->r25);
    // 0x80800434: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x80800438: sll         $t5, $a2, 4
    ctx->r13 = S32(ctx->r6 << 4);
    // 0x8080043C: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x80800440: addu        $a1, $t2, $t4
    ctx->r5 = ADD32(ctx->r10, ctx->r12);
    // 0x80800444: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800448: jal         0x80019E70
    // 0x8080044C: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    aligned8_memcpy(rdram, ctx);
        goto after_1;
    // 0x8080044C: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    after_1:
    // 0x80800450: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80800454: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x80800458: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x8080045C: sltu        $at, $s0, $t6
    ctx->r1 = ctx->r16 < ctx->r14 ? 1 : 0;
    // 0x80800460: beq         $at, $zero, L_80800528
    if (ctx->r1 == 0) {
        // 0x80800464: subu        $s4, $t0, $t1
        ctx->r20 = SUB32(ctx->r8, ctx->r9);
            goto L_80800528;
    }
    // 0x80800464: subu        $s4, $t0, $t1
    ctx->r20 = SUB32(ctx->r8, ctx->r9);
    // 0x80800468: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8080046C: div         $zero, $s4, $at
    lo = S32(S64(S32(ctx->r20)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r20)) % S64(S32(ctx->r1)));
    // 0x80800470: mflo        $s4
    ctx->r20 = lo;
    // 0x80800474: sll         $fp, $s4, 2
    ctx->r30 = S32(ctx->r20 << 2);
    // 0x80800478: nop

    // 0x8080047C: lh          $t8, 0x2($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X2);
L_80800480:
    // 0x80800480: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80800484: addu        $t3, $s7, $t9
    ctx->r11 = ADD32(ctx->r23, ctx->r25);
    // 0x80800488: lw          $t2, 0x30($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X30);
    // 0x8080048C: addu        $v1, $t2, $s7
    ctx->r3 = ADD32(ctx->r10, ctx->r23);
    // 0x80800490: addu        $a0, $v1, $fp
    ctx->r4 = ADD32(ctx->r3, ctx->r30);
    // 0x80800494: lhu         $t4, 0x16($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X16);
    // 0x80800498: addiu       $v0, $a0, 0x14
    ctx->r2 = ADD32(ctx->r4, 0X14);
    // 0x8080049C: beql        $t4, $zero, L_80800518
    if (ctx->r12 == 0) {
        // 0x808004A0: lw          $t5, 0x50($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X50);
            goto L_80800518;
    }
    goto skip_1;
    // 0x808004A0: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    skip_1:
    // 0x808004A4: lw          $t5, 0x14($s7)
    ctx->r13 = MEM_W(ctx->r23, 0X14);
    // 0x808004A8: lhu         $t1, 0x0($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X0);
    // 0x808004AC: lhu         $t7, 0x2($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X2);
    // 0x808004B0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x808004B4: addu        $t0, $v1, $t6
    ctx->r8 = ADD32(ctx->r3, ctx->r14);
    // 0x808004B8: addu        $s0, $t0, $t1
    ctx->r16 = ADD32(ctx->r8, ctx->r9);
    // 0x808004BC: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x808004C0: addu        $s2, $t7, $s0
    ctx->r18 = ADD32(ctx->r15, ctx->r16);
    // 0x808004C4: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x808004C8: beql        $at, $zero, L_80800518
    if (ctx->r1 == 0) {
        // 0x808004CC: lw          $t5, 0x50($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X50);
            goto L_80800518;
    }
    goto skip_2;
    // 0x808004CC: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    skip_2:
    // 0x808004D0: lbu         $t3, 0x0($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X0);
L_808004D4:
    // 0x808004D4: lbu         $t8, 0x1($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1);
    // 0x808004D8: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    // 0x808004DC: multu       $t3, $s6
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808004E0: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x808004E4: addu        $a2, $t9, $s3
    ctx->r6 = ADD32(ctx->r25, ctx->r19);
    // 0x808004E8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x808004EC: lbu         $a3, 0x0($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X0);
    // 0x808004F0: mflo        $t2
    ctx->r10 = lo;
    // 0x808004F4: addu        $t4, $s5, $t2
    ctx->r12 = ADD32(ctx->r21, ctx->r10);
    // 0x808004F8: lw          $t9, 0xC($t4)
    ctx->r25 = MEM_W(ctx->r12, 0XC);
    // 0x808004FC: jalr        $t9
    // 0x80800500: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80800500: nop

    after_2:
    // 0x80800504: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80800508: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x8080050C: bnel        $at, $zero, L_808004D4
    if (ctx->r1 != 0) {
        // 0x80800510: lbu         $t3, 0x0($s1)
        ctx->r11 = MEM_BU(ctx->r17, 0X0);
            goto L_808004D4;
    }
    goto skip_3;
    // 0x80800510: lbu         $t3, 0x0($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X0);
    skip_3:
    // 0x80800514: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
L_80800518:
    // 0x80800518: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8080051C: sltu        $at, $s1, $t5
    ctx->r1 = ctx->r17 < ctx->r13 ? 1 : 0;
    // 0x80800520: bnel        $at, $zero, L_80800480
    if (ctx->r1 != 0) {
        // 0x80800524: lh          $t8, 0x2($s1)
        ctx->r24 = MEM_H(ctx->r17, 0X2);
            goto L_80800480;
    }
    goto skip_4;
    // 0x80800524: lh          $t8, 0x2($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X2);
    skip_4:
L_80800528:
    // 0x80800528: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8080052C: lw          $s1, 0x60($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X60);
    // 0x80800530: lbu         $t0, 0x2($t6)
    ctx->r8 = MEM_BU(ctx->r14, 0X2);
    // 0x80800534: addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
    // 0x80800538: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x8080053C: addu        $s0, $t1, $s3
    ctx->r16 = ADD32(ctx->r9, ctx->r19);
    // 0x80800540: sltu        $at, $s3, $s0
    ctx->r1 = ctx->r19 < ctx->r16 ? 1 : 0;
    // 0x80800544: beql        $at, $zero, L_8080057C
    if (ctx->r1 == 0) {
        // 0x80800548: lw          $v0, 0x48($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X48);
            goto L_8080057C;
    }
    goto skip_5;
    // 0x80800548: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    skip_5:
    // 0x8080054C: lhu         $t7, 0x6($s3)
    ctx->r15 = MEM_HU(ctx->r19, 0X6);
L_80800550:
    // 0x80800550: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800554: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80800558: andi        $t8, $t7, 0x7FFF
    ctx->r24 = ctx->r15 & 0X7FFF;
    // 0x8080055C: sll         $t3, $t8, 4
    ctx->r11 = S32(ctx->r24 << 4);
    // 0x80800560: jal         0x80019E70
    // 0x80800564: addu        $a0, $t3, $s1
    ctx->r4 = ADD32(ctx->r11, ctx->r17);
    aligned8_memcpy(rdram, ctx);
        goto after_3;
    // 0x80800564: addu        $a0, $t3, $s1
    ctx->r4 = ADD32(ctx->r11, ctx->r17);
    after_3:
    // 0x80800568: addiu       $s3, $s3, 0x10
    ctx->r19 = ADD32(ctx->r19, 0X10);
    // 0x8080056C: sltu        $at, $s3, $s0
    ctx->r1 = ctx->r19 < ctx->r16 ? 1 : 0;
    // 0x80800570: bnel        $at, $zero, L_80800550
    if (ctx->r1 != 0) {
        // 0x80800574: lhu         $t7, 0x6($s3)
        ctx->r15 = MEM_HU(ctx->r19, 0X6);
            goto L_80800550;
    }
    goto skip_6;
    // 0x80800574: lhu         $t7, 0x6($s3)
    ctx->r15 = MEM_HU(ctx->r19, 0X6);
    skip_6:
    // 0x80800578: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
L_8080057C:
    // 0x8080057C: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
L_80800580:
    // 0x80800580: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
L_80800584:
    // 0x80800584: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x80800588: sltu        $at, $v0, $t4
    ctx->r1 = ctx->r2 < ctx->r12 ? 1 : 0;
    // 0x8080058C: bnel        $at, $zero, L_808003EC
    if (ctx->r1 != 0) {
        // 0x80800590: lbu         $t7, 0x3($v0)
        ctx->r15 = MEM_BU(ctx->r2, 0X3);
            goto L_808003EC;
    }
    goto skip_7;
    // 0x80800590: lbu         $t7, 0x3($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X3);
    skip_7:
L_80800594:
    // 0x80800594: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80800598: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080059C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808005A0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808005A4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x808005A8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x808005AC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x808005B0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x808005B4: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x808005B8: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x808005BC: jr          $ra
    // 0x808005C0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x808005C0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_8080017C_chproplighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080017C: jr          $ra
    // 0x80800180: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800180: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80800184: nop

    // 0x80800188: nop

    // 0x8080018C: nop

;}
RECOMP_FUNC void chbaddieDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800010: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800014: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800018: jal         0x800CB9B4
    // 0x8080001C: sb          $zero, 0x4($a0)
    MEM_B(0X4, ctx->r4) = 0;
    func_800CB9B4(rdram, ctx);
        goto after_0;
    // 0x8080001C: sb          $zero, 0x4($a0)
    MEM_B(0X4, ctx->r4) = 0;
    after_0:
    // 0x80800020: jal         0x800BDD00
    // 0x80800024: nop

    func_800BDD00(rdram, ctx);
        goto after_1;
    // 0x80800024: nop

    after_1:
    // 0x80800028: jal         0x800FF390
    // 0x8080002C: nop

    func_800FF390(rdram, ctx);
        goto after_2;
    // 0x8080002C: nop

    after_2:
    // 0x80800030: jal         0x8001E204
    // 0x80800034: nop

    func_8001E204(rdram, ctx);
        goto after_3;
    // 0x80800034: nop

    after_3:
    // 0x80800038: bnel        $v0, $zero, L_80800054
    if (ctx->r2 != 0) {
        // 0x8080003C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800054;
    }
    goto skip_0;
    // 0x8080003C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800040: jal         0x800BDCB8
    // 0x80800044: nop

    func_800BDCB8(rdram, ctx);
        goto after_4;
    // 0x80800044: nop

    after_4:
    // 0x80800048: jal         0x80089FB0
    // 0x8080004C: nop

    _suautobaddies_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x8080004C: nop

    after_5:
    // 0x80800050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800054:
    // 0x80800054: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800058: jr          $ra
    // 0x8080005C: nop

    return;
    // 0x8080005C: nop

;}
RECOMP_FUNC void func_800D1DFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1DFC: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800D1E00: addiu       $t2, $t2, -0x4DB0
    ctx->r10 = ADD32(ctx->r10, -0X4DB0);
    // 0x800D1E04: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x800D1E08: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800D1E0C: addiu       $a2, $a2, 0x1A04
    ctx->r6 = ADD32(ctx->r6, 0X1A04);
    // 0x800D1E10: lh          $t6, 0x0($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X0);
    // 0x800D1E14: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x800D1E18: addiu       $a1, $a0, 0x2
    ctx->r5 = ADD32(ctx->r4, 0X2);
    // 0x800D1E1C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800D1E20: xor         $t9, $t6, $t8
    ctx->r25 = ctx->r14 ^ ctx->r24;
    // 0x800D1E24: sra         $t4, $t9, 8
    ctx->r12 = S32(SIGNED(ctx->r25) >> 8);
    // 0x800D1E28: sb          $t4, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r12;
    // 0x800D1E2C: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x800D1E30: lh          $t5, 0x0($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X0);
    // 0x800D1E34: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x800D1E38: lh          $t6, 0x0($t7)
    ctx->r14 = MEM_H(ctx->r15, 0X0);
    // 0x800D1E3C: xor         $t9, $t5, $t6
    ctx->r25 = ctx->r13 ^ ctx->r14;
    // 0x800D1E40: sb          $t9, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r25;
    // 0x800D1E44: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
L_800D1E48:
    // 0x800D1E48: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x800D1E4C: addu        $v0, $a2, $a3
    ctx->r2 = ADD32(ctx->r6, ctx->r7);
    // 0x800D1E50: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x800D1E54: addu        $t7, $t4, $v1
    ctx->r15 = ADD32(ctx->r12, ctx->r3);
    // 0x800D1E58: lh          $t5, 0x0($t7)
    ctx->r13 = MEM_H(ctx->r15, 0X0);
    // 0x800D1E5C: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    // 0x800D1E60: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x800D1E64: xor         $t6, $t3, $t5
    ctx->r14 = ctx->r11 ^ ctx->r13;
    // 0x800D1E68: sra         $t9, $t6, 8
    ctx->r25 = S32(SIGNED(ctx->r14) >> 8);
    // 0x800D1E6C: sb          $t9, -0x8($a1)
    MEM_B(-0X8, ctx->r5) = ctx->r25;
    // 0x800D1E70: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x800D1E74: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    // 0x800D1E78: addu        $t3, $t7, $v1
    ctx->r11 = ADD32(ctx->r15, ctx->r3);
    // 0x800D1E7C: lh          $t5, 0x0($t3)
    ctx->r13 = MEM_H(ctx->r11, 0X0);
    // 0x800D1E80: xor         $t8, $t4, $t5
    ctx->r24 = ctx->r12 ^ ctx->r13;
    // 0x800D1E84: sb          $t8, -0x7($a1)
    MEM_B(-0X7, ctx->r5) = ctx->r24;
    // 0x800D1E88: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x800D1E8C: lh          $t9, 0x8($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X8);
    // 0x800D1E90: addu        $t3, $t7, $v1
    ctx->r11 = ADD32(ctx->r15, ctx->r3);
    // 0x800D1E94: lh          $t4, 0x2($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X2);
    // 0x800D1E98: xor         $t5, $t9, $t4
    ctx->r13 = ctx->r25 ^ ctx->r12;
    // 0x800D1E9C: sra         $t8, $t5, 8
    ctx->r24 = S32(SIGNED(ctx->r13) >> 8);
    // 0x800D1EA0: sb          $t8, -0x6($a1)
    MEM_B(-0X6, ctx->r5) = ctx->r24;
    // 0x800D1EA4: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800D1EA8: lh          $t7, 0x8($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X8);
    // 0x800D1EAC: addu        $t9, $t3, $v1
    ctx->r25 = ADD32(ctx->r11, ctx->r3);
    // 0x800D1EB0: lh          $t4, 0x2($t9)
    ctx->r12 = MEM_H(ctx->r25, 0X2);
    // 0x800D1EB4: xor         $t6, $t7, $t4
    ctx->r14 = ctx->r15 ^ ctx->r12;
    // 0x800D1EB8: sb          $t6, -0x5($a1)
    MEM_B(-0X5, ctx->r5) = ctx->r14;
    // 0x800D1EBC: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800D1EC0: lh          $t8, 0x10($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X10);
    // 0x800D1EC4: addu        $t9, $t3, $v1
    ctx->r25 = ADD32(ctx->r11, ctx->r3);
    // 0x800D1EC8: lh          $t7, 0x4($t9)
    ctx->r15 = MEM_H(ctx->r25, 0X4);
    // 0x800D1ECC: xor         $t4, $t8, $t7
    ctx->r12 = ctx->r24 ^ ctx->r15;
    // 0x800D1ED0: sra         $t6, $t4, 8
    ctx->r14 = S32(SIGNED(ctx->r12) >> 8);
    // 0x800D1ED4: sb          $t6, -0x4($a1)
    MEM_B(-0X4, ctx->r5) = ctx->r14;
    // 0x800D1ED8: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x800D1EDC: lh          $t3, 0x10($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X10);
    // 0x800D1EE0: addu        $t8, $t9, $v1
    ctx->r24 = ADD32(ctx->r25, ctx->r3);
    // 0x800D1EE4: lh          $t7, 0x4($t8)
    ctx->r15 = MEM_H(ctx->r24, 0X4);
    // 0x800D1EE8: xor         $t5, $t3, $t7
    ctx->r13 = ctx->r11 ^ ctx->r15;
    // 0x800D1EEC: sb          $t5, -0x3($a1)
    MEM_B(-0X3, ctx->r5) = ctx->r13;
    // 0x800D1EF0: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x800D1EF4: lh          $t6, 0x18($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X18);
    // 0x800D1EF8: addu        $t8, $t9, $v1
    ctx->r24 = ADD32(ctx->r25, ctx->r3);
    // 0x800D1EFC: lh          $t3, 0x6($t8)
    ctx->r11 = MEM_H(ctx->r24, 0X6);
    // 0x800D1F00: xor         $t7, $t6, $t3
    ctx->r15 = ctx->r14 ^ ctx->r11;
    // 0x800D1F04: sra         $t5, $t7, 8
    ctx->r13 = S32(SIGNED(ctx->r15) >> 8);
    // 0x800D1F08: sb          $t5, -0x2($a1)
    MEM_B(-0X2, ctx->r5) = ctx->r13;
    // 0x800D1F0C: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x800D1F10: lh          $t9, 0x18($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X18);
    // 0x800D1F14: addu        $t6, $t8, $v1
    ctx->r14 = ADD32(ctx->r24, ctx->r3);
    // 0x800D1F18: lh          $t3, 0x6($t6)
    ctx->r11 = MEM_H(ctx->r14, 0X6);
    // 0x800D1F1C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800D1F20: xor         $t4, $t9, $t3
    ctx->r12 = ctx->r25 ^ ctx->r11;
    // 0x800D1F24: bne         $a3, $a0, L_800D1E48
    if (ctx->r7 != ctx->r4) {
        // 0x800D1F28: sb          $t4, -0x1($a1)
        MEM_B(-0X1, ctx->r5) = ctx->r12;
            goto L_800D1E48;
    }
    // 0x800D1F28: sb          $t4, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r12;
    // 0x800D1F2C: jr          $ra
    // 0x800D1F30: nop

    return;
    // 0x800D1F30: nop

;}
RECOMP_FUNC void func_800E9DCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9DCC: jr          $ra
    // 0x800E9DD0: lh          $v0, 0x6($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X6);
    return;
    // 0x800E9DD0: lh          $v0, 0x6($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X6);
;}
RECOMP_FUNC void func_80800418_chboilerid(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800418: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080041C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800420: jal         0x80100094
    // 0x80800424: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800424: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800428: jal         0x80088FA8
    // 0x8080042C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _mlwave_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x8080042C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800430: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800434: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800438: jr          $ra
    // 0x8080043C: nop

    return;
    // 0x8080043C: nop

;}
RECOMP_FUNC void chswappy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800488: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x8080048C: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80800490: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x80800494: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x80800498: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x8080049C: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x808004A0: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x808004A4: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x808004A8: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x808004AC: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x808004B0: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x808004B4: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x808004B8: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x808004BC: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x808004C0: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x808004C4: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x808004C8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808004CC: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x808004D0: bgezl       $t8, L_8080062C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808004D4: lw          $ra, 0x6C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X6C);
            goto L_8080062C;
    }
    goto skip_0;
    // 0x808004D4: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    skip_0:
    // 0x808004D8: beq         $a1, $zero, L_80800500
    if (ctx->r5 == 0) {
        // 0x808004DC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800500;
    }
    // 0x808004DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808004E0: jal         0x800B5BE4
    // 0x808004E4: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    func_800B5BE4(rdram, ctx);
        goto after_0;
    // 0x808004E4: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    after_0:
    // 0x808004E8: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x808004EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808004F0: jal         0x800BA3FC
    // 0x808004F4: addiu       $a1, $zero, 0x9DE
    ctx->r5 = ADD32(0, 0X9DE);
    func_800BA3FC(rdram, ctx);
        goto after_1;
    // 0x808004F4: addiu       $a1, $zero, 0x9DE
    ctx->r5 = ADD32(0, 0X9DE);
    after_1:
    // 0x808004F8: b           L_80800534
    // 0x808004FC: addiu       $s0, $sp, 0xA4
    ctx->r16 = ADD32(ctx->r29, 0XA4);
        goto L_80800534;
    // 0x808004FC: addiu       $s0, $sp, 0xA4
    ctx->r16 = ADD32(ctx->r29, 0XA4);
L_80800500:
    // 0x80800500: jal         0x800DC128
    // 0x80800504: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DC128(rdram, ctx);
        goto after_2;
    // 0x80800504: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x80800508: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080050C: jal         0x800B5BE4
    // 0x80800510: addiu       $a0, $v0, 0x1E
    ctx->r4 = ADD32(ctx->r2, 0X1E);
    func_800B5BE4(rdram, ctx);
        goto after_3;
    // 0x80800510: addiu       $a0, $v0, 0x1E
    ctx->r4 = ADD32(ctx->r2, 0X1E);
    after_3:
    // 0x80800514: sll         $t9, $s0, 1
    ctx->r25 = S32(ctx->r16 << 1);
    // 0x80800518: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2156, 0X6CC) << 16);
    // 0x8080051C: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x80800520: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x80800524: lhu         $a1, 0x6CC($a1)
    ctx->r5 = MEM_HU(ctx->r5, (int16_t)RELOC_LO16(2156, 0X6CC));
    // 0x80800528: jal         0x800BA3FC
    // 0x8080052C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800BA3FC(rdram, ctx);
        goto after_4;
    // 0x8080052C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80800530: addiu       $s0, $sp, 0xA4
    ctx->r16 = ADD32(ctx->r29, 0XA4);
L_80800534:
    // 0x80800534: jal         0x800E3980
    // 0x80800538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E3980(rdram, ctx);
        goto after_5;
    // 0x80800538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080053C: addiu       $s2, $s1, 0x4
    ctx->r18 = ADD32(ctx->r17, 0X4);
    // 0x80800540: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800544: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800548: jal         0x800F18FC
    // 0x8080054C: addiu       $a2, $sp, 0x7C
    ctx->r6 = ADD32(ctx->r29, 0X7C);
    func_800F18FC(rdram, ctx);
        goto after_6;
    // 0x8080054C: addiu       $a2, $sp, 0x7C
    ctx->r6 = ADD32(ctx->r29, 0X7C);
    after_6:
    // 0x80800550: addiu       $s3, $sp, 0x98
    ctx->r19 = ADD32(ctx->r29, 0X98);
    // 0x80800554: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800558: jal         0x800EE7F8
    // 0x8080055C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x8080055C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_7:
    // 0x80800560: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800564: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800568: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x8080056C: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80800570: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800574: lwc1        $f4, 0x9C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80800578: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8080057C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800580: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80800584: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800588: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8080058C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800590: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x80800594: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2156, 0X690) << 16);
    // 0x80800598: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8080059C: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x808005A0: swc1        $f8, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f8.u32l;
    // 0x808005A4: addiu       $s4, $s4, 0x690
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2156, 0X690));
    // 0x808005A8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808005AC: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x808005B0: addiu       $s1, $sp, 0x8C
    ctx->r17 = ADD32(ctx->r29, 0X8C);
    // 0x808005B4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
L_808005B8:
    // 0x808005B8: jal         0x800DC178
    // 0x808005BC: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_800DC178(rdram, ctx);
        goto after_8;
    // 0x808005BC: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_8:
    // 0x808005C0: lwc1        $f10, 0x80($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X80);
    // 0x808005C4: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x808005C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808005CC: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x808005D0: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x808005D4: jal         0x800EEB9C
    // 0x808005D8: nop

    func_800EEB9C(rdram, ctx);
        goto after_9;
    // 0x808005D8: nop

    after_9:
    // 0x808005DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808005E0: jal         0x800EF04C
    // 0x808005E4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EF04C(rdram, ctx);
        goto after_10;
    // 0x808005E4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_10:
    // 0x808005E8: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    // 0x808005EC: jal         0x800DC178
    // 0x808005F0: mov.s       $f14, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    ctx->f14.fl = ctx->f28.fl;
    func_800DC178(rdram, ctx);
        goto after_11;
    // 0x808005F0: mov.s       $f14, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    ctx->f14.fl = ctx->f28.fl;
    after_11:
    // 0x808005F4: add.s       $f4, $f30, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f30.fl + ctx->f0.fl;
    // 0x808005F8: lwc1        $f18, 0x90($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X90);
    // 0x808005FC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80800600: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800604: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80800608: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x8080060C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800610: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x80800614: jal         0x800BABB8
    // 0x80800618: swc1        $f6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f6.u32l;
    func_800BABB8(rdram, ctx);
        goto after_12;
    // 0x80800618: swc1        $f6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f6.u32l;
    after_12:
    // 0x8080061C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800620: bnel        $s0, $s5, L_808005B8
    if (ctx->r16 != ctx->r21) {
        // 0x80800624: mov.s       $f12, $f20
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
            goto L_808005B8;
    }
    goto skip_1;
    // 0x80800624: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    skip_1:
    // 0x80800628: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
L_8080062C:
    // 0x8080062C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80800630: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80800634: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80800638: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x8080063C: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x80800640: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x80800644: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x80800648: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x8080064C: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x80800650: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x80800654: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x80800658: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x8080065C: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x80800660: jr          $ra
    // 0x80800664: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x80800664: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_808032A8_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808032A8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808032AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808032B0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808032B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808032B8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808032BC: jal         0x80100094
    // 0x808032C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808032C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808032C4: lbu         $t6, 0x60($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X60);
    // 0x808032C8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808032CC: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x808032D0: beql        $t6, $zero, L_80803368
    if (ctx->r14 == 0) {
        // 0x808032D4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80803368;
    }
    goto skip_0;
    // 0x808032D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808032D8: jal         0x800EE7F8
    // 0x808032DC: addiu       $a1, $v0, 0x44
    ctx->r5 = ADD32(ctx->r2, 0X44);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x808032DC: addiu       $a1, $v0, 0x44
    ctx->r5 = ADD32(ctx->r2, 0X44);
    after_1:
    // 0x808032E0: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x808032E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808032E8: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808032EC: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x808032F0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x808032F4: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x808032F8: jal         0x800F8294
    // 0x808032FC: lh          $a0, 0x76($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X76);
    func_800F8294(rdram, ctx);
        goto after_2;
    // 0x808032FC: lh          $a0, 0x76($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X76);
    after_2:
    // 0x80803300: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x80803304: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80803308: jal         0x80101E14
    // 0x8080330C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_3;
    // 0x8080330C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80803310: beq         $v0, $zero, L_80803364
    if (ctx->r2 == 0) {
        // 0x80803314: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803364;
    }
    // 0x80803314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803318: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1360, 0X4AA4) << 16);
    // 0x8080331C: addiu       $a2, $a2, 0x4AA4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1360, 0X4AA4));
    // 0x80803320: jal         0x80089D18
    // 0x80803324: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x80803324: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_4:
    // 0x80803328: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8080332C: jal         0x800EE7F8
    // 0x80803330: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x80803330: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_5:
    // 0x80803334: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80803338: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x8080333C: jal         0x800EF1B8
    // 0x80803340: lui         $a2, 0x442F
    ctx->r6 = S32(0X442F << 16);
    func_800EF1B8(rdram, ctx);
        goto after_6;
    // 0x80803340: lui         $a2, 0x442F
    ctx->r6 = S32(0X442F << 16);
    after_6:
    // 0x80803344: lh          $a0, 0x76($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X76);
    // 0x80803348: addiu       $a1, $zero, 0x92
    ctx->r5 = ADD32(0, 0X92);
    // 0x8080334C: jal         0x800F7CF4
    // 0x80803350: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_800F7CF4(rdram, ctx);
        goto after_7;
    // 0x80803350: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_7:
    // 0x80803354: lh          $a0, 0x76($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X76);
    // 0x80803358: jal         0x800F8150
    // 0x8080335C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F8150(rdram, ctx);
        goto after_8;
    // 0x8080335C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80803360: sb          $zero, 0x60($s1)
    MEM_B(0X60, ctx->r17) = 0;
L_80803364:
    // 0x80803364: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803368:
    // 0x80803368: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080336C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80803370: jr          $ra
    // 0x80803374: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80803374: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void gccubesearch_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800930: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80800934: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800938: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080093C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800940: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800944: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800948: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8080094C: sw          $a2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r6;
    // 0x80800950: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x80800954: jal         0x800BE554
    // 0x80800958: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_800BE554(rdram, ctx);
        goto after_0;
    // 0x80800958: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_0:
    // 0x8080095C: addiu       $s2, $sp, 0x7C
    ctx->r18 = ADD32(ctx->r29, 0X7C);
    // 0x80800960: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800964: jal         0x800BD64C
    // 0x80800968: lw          $a1, 0x90($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X90);
    func_800BD64C(rdram, ctx);
        goto after_1;
    // 0x80800968: lw          $a1, 0x90($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X90);
    after_1:
    // 0x8080096C: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    // 0x80800970: addiu       $t0, $sp, 0x7C
    ctx->r8 = ADD32(ctx->r29, 0X7C);
    // 0x80800974: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80800978: addiu       $t1, $sp, 0x54
    ctx->r9 = ADD32(ctx->r29, 0X54);
    // 0x8080097C: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    // 0x80800980: addiu       $t2, $sp, 0x54
    ctx->r10 = ADD32(ctx->r29, 0X54);
L_80800984:
    // 0x80800984: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80800988: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x8080098C: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80800990: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x80800994: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80800998: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8080099C: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // 0x808009A0: beq         $at, $zero, L_808009AC
    if (ctx->r1 == 0) {
        // 0x808009A4: sw          $t6, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r14;
            goto L_808009AC;
    }
    // 0x808009A4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x808009A8: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
L_808009AC:
    // 0x808009AC: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x808009B0: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x808009B4: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x808009B8: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x808009BC: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x808009C0: beq         $at, $zero, L_808009CC
    if (ctx->r1 == 0) {
        // 0x808009C4: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_808009CC;
    }
    // 0x808009C4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x808009C8: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_808009CC:
    // 0x808009CC: bne         $a3, $t2, L_80800984
    if (ctx->r7 != ctx->r10) {
        // 0x808009D0: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80800984;
    }
    // 0x808009D0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808009D4: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x808009D8: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x808009DC: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x808009E0: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x808009E4: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x808009E8: bne         $at, $zero, L_80800A98
    if (ctx->r1 != 0) {
        // 0x808009EC: sw          $t8, 0x7C($sp)
        MEM_W(0X7C, ctx->r29) = ctx->r24;
            goto L_80800A98;
    }
    // 0x808009EC: sw          $t8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r24;
L_808009F0:
    // 0x808009F0: lw          $v1, 0x70($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X70);
    // 0x808009F4: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x808009F8: bnel        $at, $zero, L_80800A84
    if (ctx->r1 != 0) {
        // 0x808009FC: lw          $t5, 0x7C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X7C);
            goto L_80800A84;
    }
    goto skip_0;
    // 0x808009FC: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    skip_0:
    // 0x80800A00: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
L_80800A04:
    // 0x80800A04: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800A08: bne         $at, $zero, L_80800A70
    if (ctx->r1 != 0) {
        // 0x80800A0C: sw          $v0, 0x84($sp)
        MEM_W(0X84, ctx->r29) = ctx->r2;
            goto L_80800A70;
    }
    // 0x80800A0C: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    // 0x80800A10: sw          $v1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r3;
L_80800A14:
    // 0x80800A14: jal         0x800BDAD4
    // 0x80800A18: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800BDAD4(rdram, ctx);
        goto after_2;
    // 0x80800A18: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x80800A1C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800A20: jal         0x80088C38
    // 0x80800A24: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _gspropmarker_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80800A24: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80800A28: beq         $v0, $zero, L_80800A50
    if (ctx->r2 == 0) {
        // 0x80800A2C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800A50;
    }
    // 0x80800A2C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800A30: beq         $s0, $zero, L_80800A48
    if (ctx->r16 == 0) {
        // 0x80800A34: nop
    
            goto L_80800A48;
    }
    // 0x80800A34: nop

    // 0x80800A38: lw          $t3, 0x10($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X10);
    // 0x80800A3C: srl         $t4, $t3, 21
    ctx->r12 = S32(U32(ctx->r11) >> 21);
    // 0x80800A40: bnel        $s0, $t4, L_80800A54
    if (ctx->r16 != ctx->r12) {
        // 0x80800A44: lw          $v0, 0x84($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X84);
            goto L_80800A54;
    }
    goto skip_1;
    // 0x80800A44: lw          $v0, 0x84($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X84);
    skip_1:
L_80800A48:
    // 0x80800A48: b           L_80800A9C
    // 0x80800A4C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80800A9C;
    // 0x80800A4C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80800A50:
    // 0x80800A50: lw          $v0, 0x84($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X84);
L_80800A54:
    // 0x80800A54: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x80800A58: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80800A5C: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800A60: beq         $at, $zero, L_80800A14
    if (ctx->r1 == 0) {
        // 0x80800A64: sw          $v0, 0x84($sp)
        MEM_W(0X84, ctx->r29) = ctx->r2;
            goto L_80800A14;
    }
    // 0x80800A64: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    // 0x80800A68: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80800A6C: lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X80);
L_80800A70:
    // 0x80800A70: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800A74: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80800A78: beql        $at, $zero, L_80800A04
    if (ctx->r1 == 0) {
        // 0x80800A7C: lw          $v0, 0x74($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X74);
            goto L_80800A04;
    }
    goto skip_2;
    // 0x80800A7C: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
    skip_2:
    // 0x80800A80: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
L_80800A84:
    // 0x80800A84: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x80800A88: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80800A8C: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80800A90: beq         $at, $zero, L_808009F0
    if (ctx->r1 == 0) {
        // 0x80800A94: sw          $t6, 0x7C($sp)
        MEM_W(0X7C, ctx->r29) = ctx->r14;
            goto L_808009F0;
    }
    // 0x80800A94: sw          $t6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r14;
L_80800A98:
    // 0x80800A98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800A9C:
    // 0x80800A9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800AA0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800AA4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800AA8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800AAC: jr          $ra
    // 0x80800AB0: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80800AB0: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_80108B8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108B8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80108B90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80108B94: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80108B98: lhu         $t6, 0x12($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X12);
    // 0x80108B9C: srl         $t7, $t6, 1
    ctx->r15 = S32(U32(ctx->r14) >> 1);
    // 0x80108BA0: bnel        $a2, $t7, L_80108BC8
    if (ctx->r6 != ctx->r15) {
        // 0x80108BA4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80108BC8;
    }
    goto skip_0;
    // 0x80108BA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80108BA8: jal         0x801069A4
    // 0x80108BAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_801069A4(rdram, ctx);
        goto after_0;
    // 0x80108BAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80108BB0: beq         $v0, $zero, L_80108BC4
    if (ctx->r2 == 0) {
        // 0x80108BB4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80108BC4;
    }
    // 0x80108BB4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80108BB8: addiu       $a1, $zero, 0x59
    ctx->r5 = ADD32(0, 0X59);
    // 0x80108BBC: jal         0x8010114C
    // 0x80108BC0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_8010114C(rdram, ctx);
        goto after_1;
    // 0x80108BC0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_1:
L_80108BC4:
    // 0x80108BC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80108BC8:
    // 0x80108BC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80108BCC: jr          $ra
    // 0x80108BD0: nop

    return;
    // 0x80108BD0: nop

;}
RECOMP_FUNC void sucoasterplayer_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808006E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006E8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808006EC: jal         0x80100094
    // 0x808006F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808006F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808006F4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808006F8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808006FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800700: jal         0x80089BF0
    // 0x80800704: addiu       $a1, $a0, 0x54
    ctx->r5 = ADD32(ctx->r4, 0X54);
    _subaddiejoy_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80800704: addiu       $a1, $a0, 0x54
    ctx->r5 = ADD32(ctx->r4, 0X54);
    after_1:
    // 0x80800708: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8080070C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80800710: lw          $a0, 0x18($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X18);
    // 0x80800714: srl         $t7, $a0, 28
    ctx->r15 = S32(U32(ctx->r4) >> 28);
    // 0x80800718: jal         0x8008A258
    // 0x8080071C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    _sucoasterdata_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x8080071C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_2:
    // 0x80800720: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80800724: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80800728: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080072C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800730: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800734: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800738: jal         0x8008A128
    // 0x8080073C: nop

    _sucoaster_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x8080073C: nop

    after_3:
    // 0x80800740: lwc1        $f16, 0x18($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80800744: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80800748: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080074C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800750: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x80800754: nop

    // 0x80800758: bc1t        L_80800764
    if (c1cs) {
        // 0x8080075C: nop
    
            goto L_80800764;
    }
    // 0x8080075C: nop

    // 0x80800760: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800764:
    // 0x80800764: jr          $ra
    // 0x80800768: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800768: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void chhotwaterpoolbits_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "chhotwaterpoolbits_entrypoint_5");
    // 0x8080088C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800890: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800894: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80800898: jal         0x800F54E4
    // 0x8080089C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8080089C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_0:
    // 0x808008A0: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x808008A4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808008A8: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808008AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808008B0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x808008B4: jal         0x800F7620
    // 0x808008B8: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    func_800F7620(rdram, ctx);
        goto after_1;
    // 0x808008B8: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_1:
    // 0x808008BC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808008C0: jal         0x800F5A00
    // 0x808008C4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800F5A00(rdram, ctx);
        goto after_2;
    // 0x808008C4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x808008C8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1268, 0XAD8) << 16);
    // 0x808008CC: addiu       $a2, $a2, 0xAD8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1268, 0XAD8));
    // 0x808008D0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808008D4: jal         0x800EE780
    // 0x808008D8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800EE780(rdram, ctx);
        goto after_3;
    // 0x808008D8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_3:
    // 0x808008DC: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1268, 0XA88) << 16);
    // 0x808008E0: addiu       $t6, $t6, 0xA88
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1268, 0XA88));
    // 0x808008E4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808008E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808008EC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x808008F0: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x808008F4: jal         0x800BABB8
    // 0x808008F8: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    func_800BABB8(rdram, ctx);
        goto after_4;
    // 0x808008F8: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    after_4:
    // 0x808008FC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1268, 0XAC0) << 16);
    // 0x80800900: addiu       $a2, $a2, 0xAC0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1268, 0XAC0));
    // 0x80800904: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800908: jal         0x80089D18
    // 0x8080090C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x8080090C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_5:
    // 0x80800910: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800914: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800918: jr          $ra
    // 0x8080091C: nop

    return;
    // 0x8080091C: nop

;}
RECOMP_FUNC void _mlspline_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089110: syscall     762
    recomp_syscall_handler(rdram, ctx, 0x80089110);
    return;
    // 0x80089114: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void bssub_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801690: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801694: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(380, 0X1900) << 16);
    // 0x80801698: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080169C: jr          $ra
    // 0x808016A0: lw          $v0, 0x1900($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(380, 0X1900));
    return;
    // 0x808016A0: lw          $v0, 0x1900($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(380, 0X1900));
    // 0x808016A4: nop

    // 0x808016A8: nop

    // 0x808016AC: nop

;}
RECOMP_FUNC void func_80803F4C_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "func_80803F4C_chdragonbrothers");
    // 0x80803F4C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80803F50: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80803F54: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80803F58: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80803F5C: jal         0x80106790
    // 0x80803F60: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80803F60: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x80803F64: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803F68: jal         0x80100094
    // 0x80803F6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80803F6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80803F70: lhu         $v1, 0x76($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X76);
    // 0x80803F74: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80803F78: srl         $t6, $v1, 7
    ctx->r14 = S32(U32(ctx->r3) >> 7);
    // 0x80803F7C: addiu       $t8, $t6, -0x32
    ctx->r24 = ADD32(ctx->r14, -0X32);
    // 0x80803F80: sll         $t0, $t8, 7
    ctx->r8 = S32(ctx->r24 << 7);
    // 0x80803F84: andi        $t1, $v1, 0x7F
    ctx->r9 = ctx->r3 & 0X7F;
    // 0x80803F88: or          $t2, $t0, $t1
    ctx->r10 = ctx->r8 | ctx->r9;
    // 0x80803F8C: sh          $t2, 0x76($s0)
    MEM_H(0X76, ctx->r16) = ctx->r10;
    // 0x80803F90: jal         0x800F5A00
    // 0x80803F94: lw          $a0, 0x20($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X20);
    func_800F5A00(rdram, ctx);
        goto after_2;
    // 0x80803F94: lw          $a0, 0x20($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X20);
    after_2:
    // 0x80803F98: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80803F9C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80803FA0: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80803FA4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80803FA8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80803FAC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80803FB0: jal         0x800F1828
    // 0x80803FB4: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    func_800F1828(rdram, ctx);
        goto after_3;
    // 0x80803FB4: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x80803FB8: lw          $t3, 0x64($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X64);
    // 0x80803FBC: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x80803FC0: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x80803FC4: sll         $t5, $t3, 12
    ctx->r13 = S32(ctx->r11 << 12);
    // 0x80803FC8: bgez        $t5, L_80803FDC
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80803FCC: lui         $at, 0x457A
        ctx->r1 = S32(0X457A << 16);
            goto L_80803FDC;
    }
    // 0x80803FCC: lui         $at, 0x457A
    ctx->r1 = S32(0X457A << 16);
    // 0x80803FD0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X5348) << 16);
    // 0x80803FD4: b           L_80803FE4
    // 0x80803FD8: lwc1        $f0, 0x5348($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1852, 0X5348));
        goto L_80803FE4;
    // 0x80803FD8: lwc1        $f0, 0x5348($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1852, 0X5348));
L_80803FDC:
    // 0x80803FDC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80803FE0: nop

L_80803FE4:
    // 0x80803FE4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80803FE8: jal         0x800EEBF0
    // 0x80803FEC: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    func_800EEBF0(rdram, ctx);
        goto after_4;
    // 0x80803FEC: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    after_4:
    // 0x80803FF0: jal         0x800EA05C
    // 0x80803FF4: nop

    func_800EA05C(rdram, ctx);
        goto after_5;
    // 0x80803FF4: nop

    after_5:
    // 0x80803FF8: addiu       $at, $zero, 0x12B
    ctx->r1 = ADD32(0, 0X12B);
    // 0x80803FFC: bne         $v0, $at, L_80804014
    if (ctx->r2 != ctx->r1) {
        // 0x80804000: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80804014;
    }
    // 0x80804000: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804004: lbu         $t6, 0x7A($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X7A);
    // 0x80804008: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x8080400C: b           L_80804020
    // 0x80804010: sb          $t7, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r15;
        goto L_80804020;
    // 0x80804010: sb          $t7, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r15;
L_80804014:
    // 0x80804014: lbu         $t9, 0x7A($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X7A);
    // 0x80804018: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x8080401C: sb          $t0, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r8;
L_80804020:
    // 0x80804020: lbu         $t1, 0x7A($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X7A);
    // 0x80804024: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80804028: beql        $t2, $zero, L_80804044
    if (ctx->r10 == 0) {
        // 0x8080402C: lui         $at, 0x4248
        ctx->r1 = S32(0X4248 << 16);
            goto L_80804044;
    }
    goto skip_0;
    // 0x8080402C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    skip_0:
    // 0x80804030: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80804034: addiu       $a1, $zero, 0x814
    ctx->r5 = ADD32(0, 0X814);
    // 0x80804038: jal         0x801032B0
    // 0x8080403C: lhu         $a2, 0x16($t3)
    ctx->r6 = MEM_HU(ctx->r11, 0X16);
    func_801032B0(rdram, ctx);
        goto after_6;
    // 0x8080403C: lhu         $a2, 0x16($t3)
    ctx->r6 = MEM_HU(ctx->r11, 0X16);
    after_6:
    // 0x80804040: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
L_80804044:
    // 0x80804044: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80804048: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8080404C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80804050: jal         0x800DC178
    // 0x80804054: nop

    func_800DC178(rdram, ctx);
        goto after_7;
    // 0x80804054: nop

    after_7:
    // 0x80804058: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8080405C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80804060: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80804064: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80804068: jal         0x800DC178
    // 0x8080406C: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_8;
    // 0x8080406C: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    after_8:
    // 0x80804070: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80804074: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80804078: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8080407C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80804080: jal         0x800DC178
    // 0x80804084: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_9;
    // 0x80804084: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    after_9:
    // 0x80804088: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x8080408C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80804090: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80804094: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80804098: jr          $ra
    // 0x8080409C: nop

    return;
    // 0x8080409C: nop

;}
RECOMP_FUNC void func_80804160_chintrochar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804160: addu        $v0, $s0, $t6
    ctx->r2 = ADD32(ctx->r16, ctx->r14);
    // 0x80804164: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80804168: lwc1        $f10, 0xD8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XD8);
    // 0x8080416C: sll         $t0, $a1, 1
    ctx->r8 = S32(ctx->r5 << 1);
    // 0x80804170: addu        $t1, $s0, $t0
    ctx->r9 = ADD32(ctx->r16, ctx->r8);
    // 0x80804174: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80804178: nop

    // 0x8080417C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80804180: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80804184: swc1        $f16, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->f16.u32l;
    // 0x80804188: lwc1        $f0, 0xD8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XD8);
    // 0x8080418C: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80804190: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x80804194: nop

    // 0x80804198: slti        $at, $v1, 0x2000
    ctx->r1 = SIGNED(ctx->r3) < 0X2000 ? 1 : 0;
    // 0x8080419C: bne         $at, $zero, L_808041CC
    if (ctx->r1 != 0) {
        // 0x808041A0: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_808041CC;
    }
    // 0x808041A0: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x808041A4: lui         $at, 0x4600
    ctx->r1 = S32(0X4600 << 16);
    // 0x808041A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808041AC: nop

    // 0x808041B0: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x808041B4: swc1        $f6, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->f6.u32l;
    // 0x808041B8: lwc1        $f10, 0xD8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XD8);
    // 0x808041BC: trunc.w.s   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x808041C0: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x808041C4: b           L_808041F8
    // 0x808041C8: sh          $v1, 0xE0($t1)
    MEM_H(0XE0, ctx->r9) = ctx->r3;
        goto L_808041F8;
    // 0x808041C8: sh          $v1, 0xE0($t1)
    MEM_H(0XE0, ctx->r9) = ctx->r3;
L_808041CC:
    // 0x808041CC: bgez        $a0, L_808041F4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x808041D0: lui         $at, 0x4600
        ctx->r1 = S32(0X4600 << 16);
            goto L_808041F4;
    }
    // 0x808041D0: lui         $at, 0x4600
    ctx->r1 = S32(0X4600 << 16);
    // 0x808041D4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808041D8: nop

    // 0x808041DC: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x808041E0: swc1        $f18, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->f18.u32l;
    // 0x808041E4: lwc1        $f4, 0xD8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XD8);
    // 0x808041E8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808041EC: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x808041F0: nop

L_808041F4:
    // 0x808041F4: sh          $v1, 0xE0($t1)
    MEM_H(0XE0, ctx->r9) = ctx->r3;
L_808041F8:
    // 0x808041F8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1732, 0X477C) << 16);
    // 0x808041FC: lwc1        $f10, 0x477C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1732, 0X477C));
    // 0x80804200: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1732, 0X4780) << 16);
    // 0x80804204: lwc1        $f18, 0x4780($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1732, 0X4780));
    // 0x80804208: mul.s       $f8, $f12, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x8080420C: lwc1        $f6, 0xD0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XD0);
    // 0x80804210: mul.s       $f16, $f8, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80804214: nop

    // 0x80804218: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8080421C: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80804220: swc1        $f10, 0xD0($v0)
    MEM_W(0XD0, ctx->r2) = ctx->f10.u32l;
    // 0x80804224: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80804228: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080422C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80804230: jr          $ra
    // 0x80804234: nop

    return;
    // 0x80804234: nop

;}
RECOMP_FUNC void func_808001C8_chdiggerground(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808001D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808001D8: jal         0x80100094
    // 0x808001DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808001DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808001E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001E4: bne         $v0, $zero, L_808001FC
    if (ctx->r2 != 0) {
        // 0x808001E8: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_808001FC;
    }
    // 0x808001E8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808001EC: jal         0x80101870
    // 0x808001F0: nop

    func_80101870(rdram, ctx);
        goto after_1;
    // 0x808001F0: nop

    after_1:
    // 0x808001F4: b           L_80800208
    // 0x808001F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800208;
    // 0x808001F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001FC:
    // 0x808001FC: jal         0x8008A198
    // 0x80800200: nop

    _sucoaster_entrypoint_20(rdram, ctx);
        goto after_2;
    // 0x80800200: nop

    after_2:
    // 0x80800204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800208:
    // 0x80800208: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080020C: jr          $ra
    // 0x80800210: nop

    return;
    // 0x80800210: nop

;}
RECOMP_FUNC void _chanemone_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085F50: syscall     263
    recomp_syscall_handler(rdram, ctx, 0x80085F50);
    return;
    // 0x80085F54: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808088A4_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808088A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808088A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808088AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808088B0: jal         0x808086B0
    // 0x808088B4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808086B0_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x808088B4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x808088B8: jal         0x80807C8C
    // 0x808088BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80807C8C_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x808088BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808088C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808088C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808088C8: jr          $ra
    // 0x808088CC: nop

    return;
    // 0x808088CC: nop

;}
RECOMP_FUNC void _bamovegoto_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084E08: syscall     137
    recomp_syscall_handler(rdram, ctx, 0x80084E08);
    return;
    // 0x80084E0C: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void _chfog_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086A90: syscall     412
    recomp_syscall_handler(rdram, ctx, 0x80086A90);
    return;
    // 0x80086A94: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808007DC_chtrashcompactor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007E0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x808007E4: bne         $a1, $at, L_80800804
    if (ctx->r5 != ctx->r1) {
        // 0x808007E8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80800804;
    }
    // 0x808007E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007EC: addiu       $a0, $zero, 0x3B7
    ctx->r4 = ADD32(0, 0X3B7);
    // 0x808007F0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x808007F4: jal         0x80101180
    // 0x808007F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_0;
    // 0x808007F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x808007FC: b           L_80800810
    // 0x80800800: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800810;
    // 0x80800800: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800804:
    // 0x80800804: jal         0x80085820
    // 0x80800808: nop

    _chswitch_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x80800808: nop

    after_1:
    // 0x8080080C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800810:
    // 0x80800810: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800814: jr          $ra
    // 0x80800818: nop

    return;
    // 0x80800818: nop

;}
RECOMP_FUNC void func_808000AC_bsmumattack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000B4: lbu         $a2, 0x160($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X160);
    // 0x808000B8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808000BC: beql        $a2, $zero, L_808000D4
    if (ctx->r6 == 0) {
        // 0x808000C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808000D4;
    }
    goto skip_0;
    // 0x808000C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808000C4: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x808000C8: jal         0x800C31DC
    // 0x808000CC: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    func_800C31DC(rdram, ctx);
        goto after_0;
    // 0x808000CC: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    after_0:
    // 0x808000D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000D4:
    // 0x808000D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000D8: jr          $ra
    // 0x808000DC: nop

    return;
    // 0x808000DC: nop

;}
RECOMP_FUNC void func_8080049C_bstntswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080049C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808004A0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808004A4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808004A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808004AC: jal         0x8008CABC
    // 0x808004B0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808004B0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_0:
    // 0x808004B4: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x808004B8: jal         0x8001210C
    // 0x808004BC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_8001210C(rdram, ctx);
        goto after_1;
    // 0x808004BC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_1:
    // 0x808004C0: bne         $v0, $zero, L_808004F4
    if (ctx->r2 != 0) {
        // 0x808004C4: nop
    
            goto L_808004F4;
    }
    // 0x808004C4: nop

    // 0x808004C8: jal         0x800DC0C0
    // 0x808004CC: nop

    func_800DC0C0(rdram, ctx);
        goto after_2;
    // 0x808004CC: nop

    after_2:
    // 0x808004D0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808004D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808004D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004DC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808004E0: nop

    // 0x808004E4: bc1f        L_808004F4
    if (!c1cs) {
        // 0x808004E8: nop
    
            goto L_808004F4;
    }
    // 0x808004E8: nop

    // 0x808004EC: jal         0x8009FC34
    // 0x808004F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009FC34(rdram, ctx);
        goto after_3;
    // 0x808004F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
L_808004F4:
    // 0x808004F4: jal         0x8001210C
    // 0x808004F8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_8001210C(rdram, ctx);
        goto after_4;
    // 0x808004F8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_4:
    // 0x808004FC: bnel        $v0, $zero, L_80800534
    if (ctx->r2 != 0) {
        // 0x80800500: lui         $a1, 0x3C23
        ctx->r5 = S32(0X3C23 << 16);
            goto L_80800534;
    }
    goto skip_0;
    // 0x80800500: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    skip_0:
    // 0x80800504: jal         0x800DC0C0
    // 0x80800508: nop

    func_800DC0C0(rdram, ctx);
        goto after_5;
    // 0x80800508: nop

    after_5:
    // 0x8080050C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800510: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800514: nop

    // 0x80800518: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8080051C: nop

    // 0x80800520: bc1fl       L_80800534
    if (!c1cs) {
        // 0x80800524: lui         $a1, 0x3C23
        ctx->r5 = S32(0X3C23 << 16);
            goto L_80800534;
    }
    goto skip_1;
    // 0x80800524: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    skip_1:
    // 0x80800528: jal         0x80800000
    // 0x8080052C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bstntswim(rdram, ctx);
        goto after_6;
    // 0x8080052C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800530: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
L_80800534:
    // 0x80800534: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80800538: jal         0x8008B348
    // 0x8080053C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    anctrl_isAt(rdram, ctx);
        goto after_7;
    // 0x8080053C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_7:
    // 0x80800540: beq         $v0, $zero, L_80800570
    if (ctx->r2 == 0) {
        // 0x80800544: lui         $a2, 0x3F59
        ctx->r6 = S32(0X3F59 << 16);
            goto L_80800570;
    }
    // 0x80800544: lui         $a2, 0x3F59
    ctx->r6 = S32(0X3F59 << 16);
    // 0x80800548: lui         $a3, 0x3F93
    ctx->r7 = S32(0X3F93 << 16);
    // 0x8080054C: addiu       $t6, $zero, 0x3E80
    ctx->r14 = ADD32(0, 0X3E80);
    // 0x80800550: addiu       $t7, $zero, 0x3E80
    ctx->r15 = ADD32(0, 0X3E80);
    // 0x80800554: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80800558: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080055C: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x80800560: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800568: jal         0x8009DEC0
    // 0x8080056C: addiu       $a1, $zero, 0x46F
    ctx->r5 = ADD32(0, 0X46F);
    func_8009DEC0(rdram, ctx);
        goto after_8;
    // 0x8080056C: addiu       $a1, $zero, 0x46F
    ctx->r5 = ADD32(0, 0X46F);
    after_8:
L_80800570:
    // 0x80800570: jal         0x8009EF10
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_9;
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800578: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080057C: bne         $v0, $at, L_80800588
    if (ctx->r2 != ctx->r1) {
        // 0x80800580: addiu       $t8, $zero, 0x110
        ctx->r24 = ADD32(0, 0X110);
            goto L_80800588;
    }
    // 0x80800580: addiu       $t8, $zero, 0x110
    ctx->r24 = ADD32(0, 0X110);
    // 0x80800584: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
L_80800588:
    // 0x80800588: jal         0x8008E35C
    // 0x8080058C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_10;
    // 0x8080058C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800590: bne         $v0, $zero, L_8080059C
    if (ctx->r2 != 0) {
        // 0x80800594: addiu       $t9, $zero, 0x10C
        ctx->r25 = ADD32(0, 0X10C);
            goto L_8080059C;
    }
    // 0x80800594: addiu       $t9, $zero, 0x10C
    ctx->r25 = ADD32(0, 0X10C);
    // 0x80800598: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_8080059C:
    // 0x8080059C: jal         0x80083F90
    // 0x808005A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bstnt_entrypoint_8(rdram, ctx);
        goto after_11;
    // 0x808005A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808005A4: beq         $v0, $zero, L_808005B0
    if (ctx->r2 == 0) {
        // 0x808005A8: addiu       $t0, $zero, 0x10E
        ctx->r8 = ADD32(0, 0X10E);
            goto L_808005B0;
    }
    // 0x808005A8: addiu       $t0, $zero, 0x10E
    ctx->r8 = ADD32(0, 0X10E);
    // 0x808005AC: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
L_808005B0:
    // 0x808005B0: jal         0x80096500
    // 0x808005B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80096500(rdram, ctx);
        goto after_12;
    // 0x808005B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808005B8: beq         $v0, $zero, L_808005D4
    if (ctx->r2 == 0) {
        // 0x808005BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005D4;
    }
    // 0x808005BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005C0: jal         0x80091A58
    // 0x808005C4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_13;
    // 0x808005C4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_13:
    // 0x808005C8: beq         $v0, $zero, L_808005D4
    if (ctx->r2 == 0) {
        // 0x808005CC: addiu       $t1, $zero, 0x107
        ctx->r9 = ADD32(0, 0X107);
            goto L_808005D4;
    }
    // 0x808005CC: addiu       $t1, $zero, 0x107
    ctx->r9 = ADD32(0, 0X107);
    // 0x808005D0: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
L_808005D4:
    // 0x808005D4: jal         0x80083F70
    // 0x808005D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bstnt_entrypoint_4(rdram, ctx);
        goto after_14;
    // 0x808005D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808005DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005E0: jal         0x8009E5C8
    // 0x808005E4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    bs_setState(rdram, ctx);
        goto after_15;
    // 0x808005E4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_15:
    // 0x808005E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808005EC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808005F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808005F4: jr          $ra
    // 0x808005F8: nop

    return;
    // 0x808005F8: nop

;}
RECOMP_FUNC void _bafly_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084BE8: syscall     132
    recomp_syscall_handler(rdram, ctx, 0x80084BE8);
    return;
    // 0x80084BEC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void chfactoryprop_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1124, 0XCB0) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0xCB0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1124, 0XCB0));
    return;
    // 0x80800020: addiu       $v0, $v0, 0xCB0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1124, 0XCB0));
;}
RECOMP_FUNC void _dbanim_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800879B8: syscall     645
    recomp_syscall_handler(rdram, ctx, 0x800879B8);
    return;
    // 0x800879BC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
