#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_808003A8_chclinker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003A8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808003AC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808003B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003B4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808003B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003BC: addiu       $s1, $s0, 0x4
    ctx->r17 = ADD32(ctx->r16, 0X4);
    // 0x808003C0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808003C4: jal         0x800EE7F8
    // 0x808003C8: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808003C8: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_0:
    // 0x808003CC: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x808003D0: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x808003D4: jal         0x800EF1B8
    // 0x808003D8: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_1;
    // 0x808003D8: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_1:
    // 0x808003DC: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x808003E0: jal         0x800EE7F8
    // 0x808003E4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x808003E4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x808003E8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x808003EC: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x808003F0: jal         0x800EF1B8
    // 0x808003F4: lui         $a2, 0xC348
    ctx->r6 = S32(0XC348 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_3;
    // 0x808003F4: lui         $a2, 0xC348
    ctx->r6 = S32(0XC348 << 16);
    after_3:
    // 0x808003F8: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x808003FC: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80800400: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x80800404: jal         0x800BEF00
    // 0x80800408: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    func_800BEF00(rdram, ctx);
        goto after_4;
    // 0x80800408: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    after_4:
    // 0x8080040C: beq         $v0, $zero, L_8080043C
    if (ctx->r2 == 0) {
        // 0x80800410: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8080043C;
    }
    // 0x80800410: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800414: jal         0x800EE7F8
    // 0x80800418: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x80800418: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_5:
    // 0x8080041C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800420: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80800424: jal         0x800EF1B8
    // 0x80800428: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_6;
    // 0x80800428: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    after_6:
    // 0x8080042C: jal         0x80103014
    // 0x80800430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103014(rdram, ctx);
        goto after_7;
    // 0x80800430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800434: jal         0x8008A7A8
    // 0x80800438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiezone_entrypoint_0(rdram, ctx);
        goto after_8;
    // 0x80800438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_8080043C:
    // 0x8080043C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800440: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800444: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800448: jr          $ra
    // 0x8080044C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8080044C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80801850_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801850: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801854: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80801858: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8080185C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801860: addiu       $a0, $zero, 0x226
    ctx->r4 = ADD32(0, 0X226);
    // 0x80801864: jal         0x80088280
    // 0x80801868: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    _gccubesearch_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80801868: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_0:
    // 0x8080186C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801870: jal         0x80088C00
    // 0x80801874: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x80801874: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x80801878: addiu       $a0, $zero, 0x383
    ctx->r4 = ADD32(0, 0X383);
    // 0x8080187C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80801880: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801884: jal         0x80108528
    // 0x80801888: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    func_80108528(rdram, ctx);
        goto after_2;
    // 0x80801888: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    after_2:
    // 0x8080188C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80801890: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80801894: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801898: sw          $t6, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->r14;
    // 0x8080189C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x808018A0: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x808018A4: jal         0x80100120
    // 0x808018A8: sw          $t9, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r25;
    func_80100120(rdram, ctx);
        goto after_3;
    // 0x808018A8: sw          $t9, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r25;
    after_3:
    // 0x808018AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808018B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808018B4: jr          $ra
    // 0x808018B8: nop

    return;
    // 0x808018B8: nop

;}
RECOMP_FUNC void _ncbadolly_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089378: syscall     775
    recomp_syscall_handler(rdram, ctx, 0x80089378);
    return;
    // 0x8008937C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _bsbabykaz_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082800: syscall     14
    recomp_syscall_handler(rdram, ctx, 0x80082800);
    return;
    // 0x80082804: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_80800738_chbilldrillplate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800738: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080073C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800740: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x80800744: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800748: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080074C: bne         $a1, $at, L_80800828
    if (ctx->r5 != ctx->r1) {
        // 0x80800750: sw          $a2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r6;
            goto L_80800828;
    }
    // 0x80800750: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800754: jal         0x80801020
    // 0x80800758: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    func_80801020_chbilldrillplate(rdram, ctx);
        goto after_0;
    // 0x80800758: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080075C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800760: lhu         $t7, 0xE($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0XE);
    // 0x80800764: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80800768: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8080076C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800770: bnel        $t6, $t7, L_8080082C
    if (ctx->r14 != ctx->r15) {
        // 0x80800774: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_8080082C;
    }
    goto skip_0;
    // 0x80800774: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    skip_0:
    // 0x80800778: jal         0x80103110
    // 0x8080077C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_1;
    // 0x8080077C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800780: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80800784: jal         0x800DA298
    // 0x80800788: lhu         $a0, 0xC($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0XC);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800788: lhu         $a0, 0xC($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0XC);
    after_2:
    // 0x8080078C: beq         $v0, $zero, L_808007E0
    if (ctx->r2 == 0) {
        // 0x80800790: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_808007E0;
    }
    // 0x80800790: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80800794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800798: jal         0x80101FDC
    // 0x8080079C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x8080079C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x808007A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808007A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808007A8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x808007AC: jal         0x800FC660
    // 0x808007B0: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    func_800FC660(rdram, ctx);
        goto after_4;
    // 0x808007B0: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    after_4:
    // 0x808007B4: jal         0x80800978
    // 0x808007B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800978_chbilldrillplate(rdram, ctx);
        goto after_5;
    // 0x808007B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808007BC: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x808007C0: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x808007C4: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x808007C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808007CC: addiu       $a3, $zero, 0x900
    ctx->r7 = ADD32(0, 0X900);
    // 0x808007D0: jal         0x80085708
    // 0x808007D4: lhu         $a2, 0x8($t9)
    ctx->r6 = MEM_HU(ctx->r25, 0X8);
    _capod_entrypoint_13(rdram, ctx);
        goto after_6;
    // 0x808007D4: lhu         $a2, 0x8($t9)
    ctx->r6 = MEM_HU(ctx->r25, 0X8);
    after_6:
    // 0x808007D8: b           L_80800910
    // 0x808007DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800910;
    // 0x808007DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808007E0:
    // 0x808007E0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808007E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808007E8: sw          $t0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r8;
    // 0x808007EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007F0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808007F4: jal         0x80101FDC
    // 0x808007F8: swc1        $f6, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f6.u32l;
    func_80101FDC(rdram, ctx);
        goto after_7;
    // 0x808007F8: swc1        $f6, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f6.u32l;
    after_7:
    // 0x808007FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800800: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800804: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800808: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080080C: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    // 0x80800810: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80800814: addiu       $a3, $zero, 0x900
    ctx->r7 = ADD32(0, 0X900);
    // 0x80800818: jal         0x80085708
    // 0x8080081C: lhu         $a2, 0xA($t1)
    ctx->r6 = MEM_HU(ctx->r9, 0XA);
    _capod_entrypoint_13(rdram, ctx);
        goto after_8;
    // 0x8080081C: lhu         $a2, 0xA($t1)
    ctx->r6 = MEM_HU(ctx->r9, 0XA);
    after_8:
    // 0x80800820: b           L_80800910
    // 0x80800824: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800910;
    // 0x80800824: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800828:
    // 0x80800828: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
L_8080082C:
    // 0x8080082C: bne         $a1, $at, L_8080090C
    if (ctx->r5 != ctx->r1) {
        // 0x80800830: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080090C;
    }
    // 0x80800830: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800834: jal         0x80100094
    // 0x80800838: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_9;
    // 0x80800838: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x8080083C: jal         0x80801020
    // 0x80800840: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_80801020_chbilldrillplate(rdram, ctx);
        goto after_10;
    // 0x80800840: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_10:
    // 0x80800844: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800848: lbu         $t2, 0x12($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X12);
    // 0x8080084C: beql        $t2, $zero, L_80800860
    if (ctx->r10 == 0) {
        // 0x80800850: lw          $t3, 0x24($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X24);
            goto L_80800860;
    }
    goto skip_1;
    // 0x80800850: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80800854: jal         0x8008A490
    // 0x80800858: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieDll_entrypoint_0(rdram, ctx);
        goto after_11;
    // 0x80800858: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8080085C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
L_80800860:
    // 0x80800860: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80800864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800868: lhu         $a1, 0x6($t3)
    ctx->r5 = MEM_HU(ctx->r11, 0X6);
    // 0x8080086C: jal         0x80103140
    // 0x80800870: lhu         $a2, 0x16($t4)
    ctx->r6 = MEM_HU(ctx->r12, 0X16);
    func_80103140(rdram, ctx);
        goto after_12;
    // 0x80800870: lhu         $a2, 0x16($t4)
    ctx->r6 = MEM_HU(ctx->r12, 0X16);
    after_12:
    // 0x80800874: jal         0x8008A020
    // 0x80800878: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    _subaddielink_entrypoint_0(rdram, ctx);
        goto after_13;
    // 0x80800878: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_13:
    // 0x8080087C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80800880: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800884: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80800888: lhu         $v0, 0x10($t5)
    ctx->r2 = MEM_HU(ctx->r13, 0X10);
    // 0x8080088C: beq         $v0, $zero, L_808008AC
    if (ctx->r2 == 0) {
        // 0x80800890: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_808008AC;
    }
    // 0x80800890: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800894: jal         0x80089C20
    // 0x80800898: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiefind_entrypoint_0(rdram, ctx);
        goto after_14;
    // 0x80800898: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_14:
    // 0x8080089C: beq         $v0, $zero, L_808008AC
    if (ctx->r2 == 0) {
        // 0x808008A0: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_808008AC;
    }
    // 0x808008A0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808008A4: jal         0x8008A028
    // 0x808008A8: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    _subaddielink_entrypoint_1(rdram, ctx);
        goto after_15;
    // 0x808008A8: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    after_15:
L_808008AC:
    // 0x808008AC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x808008B0: jal         0x80088840
    // 0x808008B4: lhu         $a0, 0xE($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0XE);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_16;
    // 0x808008B4: lhu         $a0, 0xE($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0XE);
    after_16:
    // 0x808008B8: bne         $v0, $zero, L_808008E4
    if (ctx->r2 != 0) {
        // 0x808008BC: lw          $t7, 0x24($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X24);
            goto L_808008E4;
    }
    // 0x808008BC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x808008C0: jal         0x800DA298
    // 0x808008C4: lhu         $a0, 0xC($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0XC);
    func_800DA298(rdram, ctx);
        goto after_17;
    // 0x808008C4: lhu         $a0, 0xC($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0XC);
    after_17:
    // 0x808008C8: beq         $v0, $zero, L_808008E0
    if (ctx->r2 == 0) {
        // 0x808008CC: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_808008E0;
    }
    // 0x808008CC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808008D0: lwc1        $f10, 0x28($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X28);
    // 0x808008D4: sw          $zero, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = 0;
    // 0x808008D8: b           L_808008E4
    // 0x808008DC: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
        goto L_808008E4;
    // 0x808008DC: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
L_808008E0:
    // 0x808008E0: sw          $t8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r24;
L_808008E4:
    // 0x808008E4: jal         0x8008A040
    // 0x808008E8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_18;
    // 0x808008E8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_18:
    // 0x808008EC: beq         $v0, $zero, L_8080090C
    if (ctx->r2 == 0) {
        // 0x808008F0: lw          $t9, 0x28($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X28);
            goto L_8080090C;
    }
    // 0x808008F0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x808008F4: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808008F8: lwc1        $f18, 0x8($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X8);
    // 0x808008FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800900: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80800904: jal         0x80103014
    // 0x80800908: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    func_80103014(rdram, ctx);
        goto after_19;
    // 0x80800908: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    after_19:
L_8080090C:
    // 0x8080090C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800910:
    // 0x80800910: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800914: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800918: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080091C: jr          $ra
    // 0x80800920: nop

    return;
    // 0x80800920: nop

;}
RECOMP_FUNC void func_808000B8_chdoormake(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000C8: jal         0x80100094
    // 0x808000CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808000CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808000D0: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x808000D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808000DC: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x808000E0: beq         $t6, $at, L_80800130
    if (ctx->r14 == ctx->r1) {
        // 0x808000E4: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800130;
    }
    // 0x808000E4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808000E8: bnel        $t6, $at, L_80800170
    if (ctx->r14 != ctx->r1) {
        // 0x808000EC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800170;
    }
    goto skip_0;
    // 0x808000EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808000F0: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x808000F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F8: andi        $t8, $t7, 0x800
    ctx->r24 = ctx->r15 & 0X800;
    // 0x808000FC: beql        $t8, $zero, L_80800114
    if (ctx->r24 == 0) {
        // 0x80800100: lw          $t9, 0x0($a1)
        ctx->r25 = MEM_W(ctx->r5, 0X0);
            goto L_80800114;
    }
    goto skip_1;
    // 0x80800100: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    skip_1:
    // 0x80800104: jal         0x8010A624
    // 0x80800108: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_8010A624(rdram, ctx);
        goto after_1;
    // 0x80800108: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_1:
    // 0x8080010C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800110: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
L_80800114:
    // 0x80800114: andi        $t0, $t9, 0x2000
    ctx->r8 = ctx->r25 & 0X2000;
    // 0x80800118: beql        $t0, $zero, L_80800170
    if (ctx->r8 == 0) {
        // 0x8080011C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800170;
    }
    goto skip_2;
    // 0x8080011C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80800120: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    // 0x80800124: andi        $t2, $t1, 0xFFFE
    ctx->r10 = ctx->r9 & 0XFFFE;
    // 0x80800128: b           L_8080016C
    // 0x8080012C: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
        goto L_8080016C;
    // 0x8080012C: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
L_80800130:
    // 0x80800130: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800138: andi        $t4, $t3, 0x800
    ctx->r12 = ctx->r11 & 0X800;
    // 0x8080013C: beql        $t4, $zero, L_80800154
    if (ctx->r12 == 0) {
        // 0x80800140: lw          $t5, 0x0($a1)
        ctx->r13 = MEM_W(ctx->r5, 0X0);
            goto L_80800154;
    }
    goto skip_3;
    // 0x80800140: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    skip_3:
    // 0x80800144: jal         0x8010A63C
    // 0x80800148: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_8010A63C(rdram, ctx);
        goto after_2;
    // 0x80800148: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_2:
    // 0x8080014C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800150: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
L_80800154:
    // 0x80800154: andi        $t6, $t5, 0x2000
    ctx->r14 = ctx->r13 & 0X2000;
    // 0x80800158: beql        $t6, $zero, L_80800170
    if (ctx->r14 == 0) {
        // 0x8080015C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800170;
    }
    goto skip_4;
    // 0x8080015C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80800160: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    // 0x80800164: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80800168: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
L_8080016C:
    // 0x8080016C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800170:
    // 0x80800170: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800174: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800178: jr          $ra
    // 0x8080017C: nop

    return;
    // 0x8080017C: nop

;}
RECOMP_FUNC void func_800953E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800953E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800953E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800953E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800953EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800953F0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800953F4: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x800953F8: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800953FC: bgez        $t7, L_8009540C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80095400: nop
    
            goto L_8009540C;
    }
    // 0x80095400: nop

    // 0x80095404: b           L_80095480
    // 0x80095408: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80095480;
    // 0x80095408: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009540C:
    // 0x8009540C: jal         0x800A3274
    // 0x80095410: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A3274(rdram, ctx);
        goto after_0;
    // 0x80095410: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x80095414: addiu       $t8, $v0, -0x2
    ctx->r24 = ADD32(ctx->r2, -0X2);
    // 0x80095418: sltiu       $at, $t8, 0x12
    ctx->r1 = ctx->r24 < 0X12 ? 1 : 0;
    // 0x8009541C: beq         $at, $zero, L_80095468
    if (ctx->r1 == 0) {
        // 0x80095420: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80095468;
    }
    // 0x80095420: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80095424: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80095428: addu        $at, $at, $t8
    gpr jr_addend_80095430 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8009542C: lw          $t8, 0x4D70($at)
    ctx->r24 = ADD32(ctx->r1, 0X4D70);
    // 0x80095430: jr          $t8
    // 0x80095434: nop

    switch (jr_addend_80095430 >> 2) {
        case 0: goto L_80095468; break;
        case 1: goto L_80095468; break;
        case 2: goto L_80095468; break;
        case 3: goto L_80095468; break;
        case 4: goto L_80095468; break;
        case 5: goto L_80095468; break;
        case 6: goto L_80095468; break;
        case 7: goto L_80095468; break;
        case 8: goto L_80095438; break;
        case 9: goto L_80095468; break;
        case 10: goto L_80095468; break;
        case 11: goto L_80095468; break;
        case 12: goto L_80095468; break;
        case 13: goto L_80095468; break;
        case 14: goto L_80095468; break;
        case 15: goto L_80095468; break;
        case 16: goto L_80095468; break;
        case 17: goto L_80095468; break;
        default: switch_error(__func__, 0x80095430, 0x80124D70);
    }
    // 0x80095434: nop

L_80095438:
    // 0x80095438: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8009543C: jal         0x8009E71C
    // 0x80095440: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    func_8009E71C(rdram, ctx);
        goto after_1;
    // 0x80095440: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_1:
    // 0x80095444: beq         $v0, $zero, L_80095468
    if (ctx->r2 == 0) {
        // 0x80095448: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_80095468;
    }
    // 0x80095448: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8009544C: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80095450: addiu       $a2, $a2, 0x7E60
    ctx->r6 = ADD32(ctx->r6, 0X7E60);
    // 0x80095454: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80095458: jal         0x80095388
    // 0x8009545C: addiu       $a3, $zero, 0x3E8
    ctx->r7 = ADD32(0, 0X3E8);
    func_80095388(rdram, ctx);
        goto after_2;
    // 0x8009545C: addiu       $a3, $zero, 0x3E8
    ctx->r7 = ADD32(0, 0X3E8);
    after_2:
    // 0x80095460: b           L_80095484
    // 0x80095464: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80095484;
    // 0x80095464: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80095468:
    // 0x80095468: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x8009546C: addiu       $a2, $a2, 0x7E60
    ctx->r6 = ADD32(ctx->r6, 0X7E60);
    // 0x80095470: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80095474: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80095478: jal         0x80095388
    // 0x8009547C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80095388(rdram, ctx);
        goto after_3;
    // 0x8009547C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
L_80095480:
    // 0x80095480: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80095484:
    // 0x80095484: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80095488: jr          $ra
    // 0x8009548C: nop

    return;
    // 0x8009548C: nop

;}
RECOMP_FUNC void _gsmaker_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082580: syscall     2
    recomp_syscall_handler(rdram, ctx, 0x80082580);
    return;
    // 0x80082584: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void susplinet_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800294: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80800298: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8080029C: jr          $ra
    // 0x808002A0: lwc1        $f0, 0x24($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X24);
    return;
    // 0x808002A0: lwc1        $f0, 0x24($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X24);
;}
RECOMP_FUNC void _bskazstill_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083628: syscall     70
    recomp_syscall_handler(rdram, ctx, 0x80083628);
    return;
    // 0x8008362C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void bsbtrot_entrypoint_27(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801F04: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801F08: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(124, 0X2EB0) << 16);
    // 0x80801F0C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801F10: jr          $ra
    // 0x80801F14: lw          $v0, 0x2EB0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(124, 0X2EB0));
    return;
    // 0x80801F14: lw          $v0, 0x2EB0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(124, 0X2EB0));
;}
RECOMP_FUNC void func_808007EC_bsbabykaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007F4: jal         0x808004B8
    // 0x808007F8: nop

    bsbabykaz_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808007F8: nop

    after_0:
    // 0x808007FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800800: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800804: jr          $ra
    // 0x80800808: nop

    return;
    // 0x80800808: nop

;}
RECOMP_FUNC void func_80029B18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029B18: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80029B1C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80029B20: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x80029B24: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80029B28: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x80029B2C: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80029B30: beq         $t7, $zero, L_80029B88
    if (ctx->r15 == 0) {
        // 0x80029B34: nop
    
            goto L_80029B88;
    }
    // 0x80029B34: nop

L_80029B38:
    // 0x80029B38: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x80029B3C: lbu         $t9, 0x36($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X36);
    // 0x80029B40: bne         $t9, $a1, L_80029B78
    if (ctx->r25 != ctx->r5) {
        // 0x80029B44: nop
    
            goto L_80029B78;
    }
    // 0x80029B44: nop

    // 0x80029B48: lbu         $t0, 0x35($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X35);
    // 0x80029B4C: bne         $t0, $a2, L_80029B78
    if (ctx->r8 != ctx->r6) {
        // 0x80029B50: nop
    
            goto L_80029B78;
    }
    // 0x80029B50: nop

    // 0x80029B54: lbu         $t1, 0x39($t8)
    ctx->r9 = MEM_BU(ctx->r24, 0X39);
    // 0x80029B58: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80029B5C: beq         $t1, $at, L_80029B78
    if (ctx->r9 == ctx->r1) {
        // 0x80029B60: nop
    
            goto L_80029B78;
    }
    // 0x80029B60: nop

    // 0x80029B64: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80029B68: beq         $t1, $at, L_80029B78
    if (ctx->r9 == ctx->r1) {
        // 0x80029B6C: nop
    
            goto L_80029B78;
    }
    // 0x80029B6C: nop

    // 0x80029B70: b           L_80029B98
    // 0x80029B74: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
        goto L_80029B98;
    // 0x80029B74: lw          $v0, 0x4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4);
L_80029B78:
    // 0x80029B78: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x80029B7C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80029B80: bne         $t3, $zero, L_80029B38
    if (ctx->r11 != 0) {
        // 0x80029B84: sw          $t3, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r11;
            goto L_80029B38;
    }
    // 0x80029B84: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
L_80029B88:
    // 0x80029B88: b           L_80029B98
    // 0x80029B8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80029B98;
    // 0x80029B8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80029B90: b           L_80029B98
    // 0x80029B94: nop

        goto L_80029B98;
    // 0x80029B94: nop

L_80029B98:
    // 0x80029B98: jr          $ra
    // 0x80029B9C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80029B9C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void bstaxi_entrypoint_28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808017A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808017A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808017A8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808017AC: jal         0x80800144
    // 0x808017B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bstaxi_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808017B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808017B4: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x808017B8: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x808017BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017C0: jal         0x8008CCBC
    // 0x808017C4: addiu       $a1, $zero, 0xF5
    ctx->r5 = ADD32(0, 0XF5);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_1;
    // 0x808017C4: addiu       $a1, $zero, 0xF5
    ctx->r5 = ADD32(0, 0XF5);
    after_1:
    // 0x808017C8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x808017CC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808017D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808017D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808017DC: jal         0x8009FFD8
    // 0x808017E0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x808017E0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x808017E4: sb          $zero, 0x15C($s0)
    MEM_B(0X15C, ctx->r16) = 0;
    // 0x808017E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017EC: jal         0x80801600
    // 0x808017F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801600_bstaxi(rdram, ctx);
        goto after_3;
    // 0x808017F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808017F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808017F8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808017FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801800: jr          $ra
    // 0x80801804: nop

    return;
    // 0x80801804: nop

;}
RECOMP_FUNC void func_800CEBD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CEBD8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800CEBDC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CEBE0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800CEBE4: jal         0x800F54E4
    // 0x800CEBE8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x800CEBE8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800CEBEC: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x800CEBF0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x800CEBF4: beql        $t6, $zero, L_800CEC68
    if (ctx->r14 == 0) {
        // 0x800CEBF8: lw          $t7, 0x38($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X38);
            goto L_800CEC68;
    }
    goto skip_0;
    // 0x800CEBF8: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    skip_0:
    // 0x800CEBFC: jal         0x800DB9B0
    // 0x800CEC00: nop

    func_800DB9B0(rdram, ctx);
        goto after_1;
    // 0x800CEC00: nop

    after_1:
    // 0x800CEC04: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800CEC08: jal         0x800F6D24
    // 0x800CEC0C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_800F6D24(rdram, ctx);
        goto after_2;
    // 0x800CEC0C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_2:
    // 0x800CEC10: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800CEC14: jal         0x800F8004
    // 0x800CEC18: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_800F8004(rdram, ctx);
        goto after_3;
    // 0x800CEC18: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x800CEC1C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800CEC20: jal         0x800F68B8
    // 0x800CEC24: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_800F68B8(rdram, ctx);
        goto after_4;
    // 0x800CEC24: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_4:
    // 0x800CEC28: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800CEC2C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800CEC30: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800CEC34: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800CEC38: jal         0x800CE59C
    // 0x800CEC3C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800CE59C(rdram, ctx);
        goto after_5;
    // 0x800CEC3C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_5:
    // 0x800CEC40: beql        $v0, $zero, L_800CEC68
    if (ctx->r2 == 0) {
        // 0x800CEC44: lw          $t7, 0x38($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X38);
            goto L_800CEC68;
    }
    goto skip_1;
    // 0x800CEC44: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    skip_1:
    // 0x800CEC48: jal         0x800CE3E0
    // 0x800CEC4C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800CE3E0(rdram, ctx);
        goto after_6;
    // 0x800CEC4C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_6:
    // 0x800CEC50: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CEC54: jal         0x800CE3F4
    // 0x800CEC58: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    func_800CE3F4(rdram, ctx);
        goto after_7;
    // 0x800CEC58: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_7:
    // 0x800CEC5C: b           L_800CEC88
    // 0x800CEC60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800CEC88;
    // 0x800CEC60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CEC64: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
L_800CEC68:
    // 0x800CEC68: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800CEC6C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800CEC70: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800CEC74: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x800CEC78: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x800CEC7C: jal         0x800D284C
    // 0x800CEC80: lh          $a0, -0x55D0($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X55D0);
    func_800D284C(rdram, ctx);
        goto after_8;
    // 0x800CEC80: lh          $a0, -0x55D0($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X55D0);
    after_8:
    // 0x800CEC84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800CEC88:
    // 0x800CEC88: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800CEC8C: jr          $ra
    // 0x800CEC90: nop

    return;
    // 0x800CEC90: nop

;}
RECOMP_FUNC void func_800A5C28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5C28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A5C2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A5C30: jal         0x80088030
    // 0x800A5C34: nop

    _gccollectDll_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x800A5C34: nop

    after_0:
    // 0x800A5C38: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A5C3C: jal         0x80085928
    // 0x800A5C40: addiu       $a0, $a0, 0x7110
    ctx->r4 = ADD32(ctx->r4, 0X7110);
    _chbaddieDll_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x800A5C40: addiu       $a0, $a0, 0x7110
    ctx->r4 = ADD32(ctx->r4, 0X7110);
    after_1:
    // 0x800A5C44: jal         0x8008A518
    // 0x800A5C48: nop

    _subaddietaxi_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x800A5C48: nop

    after_2:
    // 0x800A5C4C: jal         0x800EA05C
    // 0x800A5C50: nop

    func_800EA05C(rdram, ctx);
        goto after_3;
    // 0x800A5C50: nop

    after_3:
    // 0x800A5C54: jal         0x80087850
    // 0x800A5C58: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _cosectionstor_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x800A5C58: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x800A5C5C: jal         0x80108C14
    // 0x800A5C60: nop

    func_80108C14(rdram, ctx);
        goto after_5;
    // 0x800A5C60: nop

    after_5:
    // 0x800A5C64: jal         0x800FFB74
    // 0x800A5C68: nop

    func_800FFB74(rdram, ctx);
        goto after_6;
    // 0x800A5C68: nop

    after_6:
    // 0x800A5C6C: jal         0x8001E204
    // 0x800A5C70: nop

    func_8001E204(rdram, ctx);
        goto after_7;
    // 0x800A5C70: nop

    after_7:
    // 0x800A5C74: bnel        $v0, $zero, L_800A5C88
    if (ctx->r2 != 0) {
        // 0x800A5C78: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A5C88;
    }
    goto skip_0;
    // 0x800A5C78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800A5C7C: jal         0x800BDCDC
    // 0x800A5C80: nop

    func_800BDCDC(rdram, ctx);
        goto after_8;
    // 0x800A5C80: nop

    after_8:
    // 0x800A5C84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A5C88:
    // 0x800A5C88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A5C8C: jr          $ra
    // 0x800A5C90: nop

    return;
    // 0x800A5C90: nop

;}
RECOMP_FUNC void func_80800370_chjollyroger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800370: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800374: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800378: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8080037C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800380: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800384: beq         $a1, $at, L_808003D0
    if (ctx->r5 == ctx->r1) {
        // 0x80800388: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_808003D0;
    }
    // 0x80800388: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8080038C: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80800390: beq         $a1, $at, L_808004A8
    if (ctx->r5 == ctx->r1) {
        // 0x80800394: addiu       $v0, $sp, 0x30
        ctx->r2 = ADD32(ctx->r29, 0X30);
            goto L_808004A8;
    }
    // 0x80800394: addiu       $v0, $sp, 0x30
    ctx->r2 = ADD32(ctx->r29, 0X30);
    // 0x80800398: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x8080039C: beq         $a1, $at, L_808004C0
    if (ctx->r5 == ctx->r1) {
        // 0x808003A0: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(1036, 0X12A8) << 16);
            goto L_808004C0;
    }
    // 0x808003A0: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1036, 0X12A8) << 16);
    // 0x808003A4: addiu       $at, $zero, 0x57
    ctx->r1 = ADD32(0, 0X57);
    // 0x808003A8: beq         $a1, $at, L_808004D4
    if (ctx->r5 == ctx->r1) {
        // 0x808003AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004D4;
    }
    // 0x808003AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003B0: addiu       $at, $zero, 0x6E
    ctx->r1 = ADD32(0, 0X6E);
    // 0x808003B4: beq         $a1, $at, L_80800530
    if (ctx->r5 == ctx->r1) {
        // 0x808003B8: lw          $v0, 0x30($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X30);
            goto L_80800530;
    }
    // 0x808003B8: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x808003BC: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808003C0: beq         $a1, $at, L_808004FC
    if (ctx->r5 == ctx->r1) {
        // 0x808003C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004FC;
    }
    // 0x808003C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003C8: b           L_80800558
    // 0x808003CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800558;
    // 0x808003CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808003D0:
    // 0x808003D0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x808003D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808003D8: beq         $t6, $at, L_808003F0
    if (ctx->r14 == ctx->r1) {
        // 0x808003DC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808003F0;
    }
    // 0x808003DC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808003E0: beq         $t6, $at, L_80800470
    if (ctx->r14 == ctx->r1) {
        // 0x808003E4: nop
    
            goto L_80800470;
    }
    // 0x808003E4: nop

    // 0x808003E8: b           L_80800558
    // 0x808003EC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800558;
    // 0x808003EC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808003F0:
    // 0x808003F0: jal         0x800F54E4
    // 0x808003F4: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x808003F4: nop

    after_0:
    // 0x808003F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003FC: jal         0x800F7F98
    // 0x80800400: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F7F98(rdram, ctx);
        goto after_1;
    // 0x80800400: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800404: jal         0x800DA298
    // 0x80800408: addiu       $a0, $zero, 0xC2
    ctx->r4 = ADD32(0, 0XC2);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800408: addiu       $a0, $zero, 0xC2
    ctx->r4 = ADD32(0, 0XC2);
    after_2:
    // 0x8080040C: bne         $v0, $zero, L_80800454
    if (ctx->r2 != 0) {
        // 0x80800410: nop
    
            goto L_80800454;
    }
    // 0x80800410: nop

    // 0x80800414: jal         0x800DA298
    // 0x80800418: addiu       $a0, $zero, 0x41
    ctx->r4 = ADD32(0, 0X41);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80800418: addiu       $a0, $zero, 0x41
    ctx->r4 = ADD32(0, 0X41);
    after_3:
    // 0x8080041C: bne         $v0, $zero, L_80800454
    if (ctx->r2 != 0) {
        // 0x80800420: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800454;
    }
    // 0x80800420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800424: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800428: jal         0x80800E6C
    // 0x8080042C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800E6C_chjollyroger(rdram, ctx);
        goto after_4;
    // 0x8080042C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80800430: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800434: addiu       $t7, $zero, 0x55
    ctx->r15 = ADD32(0, 0X55);
    // 0x80800438: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8080043C: addiu       $a1, $zero, 0x1002
    ctx->r5 = ADD32(0, 0X1002);
    // 0x80800440: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    // 0x80800444: jal         0x8008A208
    // 0x80800448: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x80800448: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_5:
    // 0x8080044C: b           L_80800558
    // 0x80800450: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800558;
    // 0x80800450: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800454:
    // 0x80800454: jal         0x80800E30
    // 0x80800458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800E30_chjollyroger(rdram, ctx);
        goto after_6;
    // 0x80800458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080045C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800460: jal         0x80102424
    // 0x80800464: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_7;
    // 0x80800464: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
    // 0x80800468: b           L_80800558
    // 0x8080046C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800558;
    // 0x8080046C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800470:
    // 0x80800470: jal         0x800DA298
    // 0x80800474: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    func_800DA298(rdram, ctx);
        goto after_8;
    // 0x80800474: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    after_8:
    // 0x80800478: beq         $v0, $zero, L_80800488
    if (ctx->r2 == 0) {
        // 0x8080047C: addiu       $a2, $zero, 0xE
        ctx->r6 = ADD32(0, 0XE);
            goto L_80800488;
    }
    // 0x8080047C: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800480: b           L_8080048C
    // 0x80800484: addiu       $a1, $zero, 0x1043
    ctx->r5 = ADD32(0, 0X1043);
        goto L_8080048C;
    // 0x80800484: addiu       $a1, $zero, 0x1043
    ctx->r5 = ADD32(0, 0X1043);
L_80800488:
    // 0x80800488: addiu       $a1, $zero, 0x1042
    ctx->r5 = ADD32(0, 0X1042);
L_8080048C:
    // 0x8080048C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800490: addiu       $t8, $zero, 0x55
    ctx->r24 = ADD32(0, 0X55);
    // 0x80800494: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800498: jal         0x8008A208
    // 0x8080049C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_9;
    // 0x8080049C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_9:
    // 0x808004A0: b           L_80800558
    // 0x808004A4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800558;
    // 0x808004A4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808004A8:
    // 0x808004A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004AC: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x808004B0: jal         0x80800624
    // 0x808004B4: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    func_80800624_chjollyroger(rdram, ctx);
        goto after_10;
    // 0x808004B4: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    after_10:
    // 0x808004B8: b           L_80800558
    // 0x808004BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800558;
    // 0x808004BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004C0:
    // 0x808004C0: addiu       $a0, $a0, 0x12A8
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1036, 0X12A8));
    // 0x808004C4: jal         0x80088090
    // 0x808004C8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_11;
    // 0x808004C8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_11:
    // 0x808004CC: b           L_80800558
    // 0x808004D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800558;
    // 0x808004D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004D4:
    // 0x808004D4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x808004D8: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x808004DC: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x808004E0: andi        $t9, $a1, 0xFFFF
    ctx->r25 = ctx->r5 & 0XFFFF;
    // 0x808004E4: and         $t0, $a2, $at
    ctx->r8 = ctx->r6 & ctx->r1;
    // 0x808004E8: srl         $a2, $t0, 16
    ctx->r6 = S32(U32(ctx->r8) >> 16);
    // 0x808004EC: jal         0x80800DD8
    // 0x808004F0: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    func_80800DD8_chjollyroger(rdram, ctx);
        goto after_12;
    // 0x808004F0: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_12:
    // 0x808004F4: b           L_8080055C
    // 0x808004F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080055C;
    // 0x808004F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808004FC:
    // 0x808004FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800500: jal         0x800897C0
    // 0x80800504: addiu       $a2, $zero, 0x55
    ctx->r6 = ADD32(0, 0X55);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_13;
    // 0x80800504: addiu       $a2, $zero, 0x55
    ctx->r6 = ADD32(0, 0X55);
    after_13:
    // 0x80800508: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080050C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800510: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x80800514: jal         0x800897E8
    // 0x80800518: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_14;
    // 0x80800518: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    after_14:
    // 0x8080051C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800520: jal         0x80089810
    // 0x80800524: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    _suexpression_entrypoint_17(rdram, ctx);
        goto after_15;
    // 0x80800524: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    after_15:
    // 0x80800528: b           L_80800558
    // 0x8080052C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800558;
    // 0x8080052C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800530:
    // 0x80800530: lbu         $t5, 0x65($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X65);
    // 0x80800534: sltiu       $t3, $v0, 0x1
    ctx->r11 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80800538: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x8080053C: andi        $t6, $t5, 0xFFFE
    ctx->r14 = ctx->r13 & 0XFFFE;
    // 0x80800540: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x80800544: b           L_80800554
    // 0x80800548: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
        goto L_80800554;
    // 0x80800548: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
    // 0x8080054C: b           L_80800558
    // 0x80800550: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800558;
    // 0x80800550: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800554:
    // 0x80800554: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800558:
    // 0x80800558: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080055C:
    // 0x8080055C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800560: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800564: jr          $ra
    // 0x80800568: nop

    return;
    // 0x80800568: nop

;}
RECOMP_FUNC void func_80800030_chdinoswitches(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800030: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800034: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800038: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080003C: jal         0x80800108
    // 0x80800040: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800108_chdinoswitches(rdram, ctx);
        goto after_0;
    // 0x80800040: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800044: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800048: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080004C: bne         $v0, $at, L_8080007C
    if (ctx->r2 != ctx->r1) {
        // 0x80800050: sw          $v0, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->r2;
            goto L_8080007C;
    }
    // 0x80800050: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x80800054: jal         0x800DA298
    // 0x80800058: addiu       $a0, $zero, 0x676
    ctx->r4 = ADD32(0, 0X676);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800058: addiu       $a0, $zero, 0x676
    ctx->r4 = ADD32(0, 0X676);
    after_1:
    // 0x8080005C: bne         $v0, $zero, L_80800074
    if (ctx->r2 != 0) {
        // 0x80800060: addiu       $a0, $zero, 0x18
        ctx->r4 = ADD32(0, 0X18);
            goto L_80800074;
    }
    // 0x80800060: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x80800064: jal         0x800D0B68
    // 0x80800068: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800D0B68(rdram, ctx);
        goto after_2;
    // 0x80800068: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8080006C: beql        $v0, $zero, L_80800080
    if (ctx->r2 == 0) {
        // 0x80800070: lw          $t6, 0x24($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X24);
            goto L_80800080;
    }
    goto skip_0;
    // 0x80800070: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    skip_0:
L_80800074:
    // 0x80800074: jal         0x800DA544
    // 0x80800078: addiu       $a0, $zero, 0xA10
    ctx->r4 = ADD32(0, 0XA10);
    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x80800078: addiu       $a0, $zero, 0xA10
    ctx->r4 = ADD32(0, 0XA10);
    after_3:
L_8080007C:
    // 0x8080007C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
L_80800080:
    // 0x80800080: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1048, 0XB20) << 16);
    // 0x80800084: addiu       $t8, $t8, 0xB20
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1048, 0XB20));
    // 0x80800088: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8080008C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80800090: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800094: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80800098: lhu         $a1, 0x2($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X2);
    // 0x8080009C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x808000A0: jal         0x80085808
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chswitch_entrypoint_7(rdram, ctx);
        goto after_4;
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808000A8: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B0: jal         0x80085810
    // 0x808000B4: lw          $a1, 0x4($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X4);
    _chswitch_entrypoint_8(rdram, ctx);
        goto after_5;
    // 0x808000B4: lw          $a1, 0x4($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X4);
    after_5:
    // 0x808000B8: lw          $t0, 0x18($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X18);
    // 0x808000BC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808000C0: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x808000C4: bne         $t0, $at, L_808000EC
    if (ctx->r8 != ctx->r1) {
        // 0x808000C8: nop
    
            goto L_808000EC;
    }
    // 0x808000C8: nop

    // 0x808000CC: jal         0x800DA298
    // 0x808000D0: lhu         $a0, 0x2($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X2);
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x808000D0: lhu         $a0, 0x2($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X2);
    after_6:
    // 0x808000D4: beq         $v0, $zero, L_808000F4
    if (ctx->r2 == 0) {
        // 0x808000D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000F4;
    }
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000DC: jal         0x80103110
    // 0x808000E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_7;
    // 0x808000E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x808000E4: b           L_808000F8
    // 0x808000E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000F8;
    // 0x808000E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000EC:
    // 0x808000EC: jal         0x80085818
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chswitch_entrypoint_9(rdram, ctx);
        goto after_8;
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_808000F4:
    // 0x808000F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000F8:
    // 0x808000F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800100: jr          $ra
    // 0x80800104: nop

    return;
    // 0x80800104: nop

;}
RECOMP_FUNC void func_80103B24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103B24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103B28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80103B2C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80103B30: bne         $a2, $zero, L_80103B40
    if (ctx->r6 != 0) {
        // 0x80103B34: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80103B40;
    }
    // 0x80103B34: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80103B38: b           L_80103BAC
    // 0x80103B3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80103BAC;
    // 0x80103B3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80103B40:
    // 0x80103B40: lbu         $t6, 0x70($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X70);
    // 0x80103B44: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80103B48: beql        $t7, $zero, L_80103B7C
    if (ctx->r15 == 0) {
        // 0x80103B4C: lw          $t1, 0x70($a3)
        ctx->r9 = MEM_W(ctx->r7, 0X70);
            goto L_80103B7C;
    }
    goto skip_0;
    // 0x80103B4C: lw          $t1, 0x70($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X70);
    skip_0:
    // 0x80103B50: lh          $a0, 0x60($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X60);
    // 0x80103B54: beql        $a0, $zero, L_80103B7C
    if (ctx->r4 == 0) {
        // 0x80103B58: lw          $t1, 0x70($a3)
        ctx->r9 = MEM_W(ctx->r7, 0X70);
            goto L_80103B7C;
    }
    goto skip_1;
    // 0x80103B58: lw          $t1, 0x70($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X70);
    skip_1:
    // 0x80103B5C: lbu         $t8, 0x71($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X71);
    // 0x80103B60: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80103B64: srl         $t9, $t8, 7
    ctx->r25 = S32(U32(ctx->r24) >> 7);
    // 0x80103B68: jal         0x80100A74
    // 0x80103B6C: xor         $a1, $t9, $t0
    ctx->r5 = ctx->r25 ^ ctx->r8;
    func_80100A74(rdram, ctx);
        goto after_0;
    // 0x80103B6C: xor         $a1, $t9, $t0
    ctx->r5 = ctx->r25 ^ ctx->r8;
    after_0:
    // 0x80103B70: b           L_80103BB0
    // 0x80103B74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80103BB0;
    // 0x80103B74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80103B78: lw          $t1, 0x70($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X70);
L_80103B7C:
    // 0x80103B7C: sll         $t3, $t1, 10
    ctx->r11 = S32(ctx->r9 << 10);
    // 0x80103B80: bgez        $t3, L_80103BA4
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80103B84: nop
    
            goto L_80103BA4;
    }
    // 0x80103B84: nop

    // 0x80103B88: lh          $a0, 0x60($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X60);
    // 0x80103B8C: beq         $a0, $zero, L_80103BA4
    if (ctx->r4 == 0) {
        // 0x80103B90: nop
    
            goto L_80103BA4;
    }
    // 0x80103B90: nop

    // 0x80103B94: jal         0x80100A74
    // 0x80103B98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100A74(rdram, ctx);
        goto after_1;
    // 0x80103B98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80103B9C: b           L_80103BB0
    // 0x80103BA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80103BB0;
    // 0x80103BA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80103BA4:
    // 0x80103BA4: jal         0x800B2840
    // 0x80103BA8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800B2840(rdram, ctx);
        goto after_2;
    // 0x80103BA8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
L_80103BAC:
    // 0x80103BAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80103BB0:
    // 0x80103BB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80103BB4: jr          $ra
    // 0x80103BB8: nop

    return;
    // 0x80103BB8: nop

;}
RECOMP_FUNC void func_8001395C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001395C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80013960: lwc1        $f14, 0x16EC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X16EC);
    // 0x80013964: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80013968: b           L_80013984
    // 0x8001396C: lwc1        $f16, 0x16F0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X16F0);
        goto L_80013984;
    // 0x8001396C: lwc1        $f16, 0x16F0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X16F0);
    // 0x80013970: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80013974: lwc1        $f14, 0x16F4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X16F4);
    // 0x80013978: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8001397C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80013980: nop

L_80013984:
    // 0x80013984: mul.s       $f0, $f12, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80013988: lui         $at, 0x4B00
    ctx->r1 = S32(0X4B00 << 16);
    // 0x8001398C: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x80013990: addiu       $t1, $t1, -0x2C60
    ctx->r9 = ADD32(ctx->r9, -0X2C60);
    // 0x80013994: trunc.w.s   $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80013998: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8001399C: mul.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800139A0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800139A4: sub.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x800139A8: mul.s       $f12, $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x800139AC: nop

    // 0x800139B0: mul.s       $f4, $f12, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x800139B4: round.w.s   $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = lroundf(ctx->f4.fl);
    // 0x800139B8: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x800139BC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800139C0: lwc1        $f6, 0x16F8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X16F8);
    // 0x800139C4: andi        $t2, $a0, 0xFFF
    ctx->r10 = ctx->r4 & 0XFFF;
    // 0x800139C8: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800139CC: srl         $t0, $a0, 10
    ctx->r8 = S32(U32(ctx->r4) >> 10);
    // 0x800139D0: andi        $t0, $t0, 0x1FFC
    ctx->r8 = ctx->r8 & 0X1FFC;
    // 0x800139D4: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800139D8: addu        $t2, $t1, $t0
    ctx->r10 = ADD32(ctx->r9, ctx->r8);
    // 0x800139DC: lwc1        $f10, 0x0($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X0);
    // 0x800139E0: lwc1        $f12, 0x4($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X4);
    // 0x800139E4: mul.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800139E8: sub.s       $f12, $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x800139EC: mul.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x800139F0: jr          $ra
    // 0x800139F4: add.s       $f0, $f12, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f10.fl;
    return;
    // 0x800139F4: add.s       $f0, $f12, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f10.fl;
;}
RECOMP_FUNC void func_8009BD18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BD18: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8009BD1C: lw          $t6, 0xC8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC8);
    // 0x8009BD20: jr          $ra
    // 0x8009BD24: swc1        $f12, 0x50($t6)
    MEM_W(0X50, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x8009BD24: swc1        $f12, 0x50($t6)
    MEM_W(0X50, ctx->r14) = ctx->f12.u32l;
    // 0x8009BD28: nop

    // 0x8009BD2C: nop

;}
RECOMP_FUNC void freelist_erase(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B32C0: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x800B32C4: lh          $t8, 0x4($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X4);
    // 0x800B32C8: multu       $a1, $t6
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B32CC: mflo        $t7
    ctx->r15 = lo;
    // 0x800B32D0: addu        $v0, $a0, $t7
    ctx->r2 = ADD32(ctx->r4, ctx->r15);
    // 0x800B32D4: sh          $t8, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r24;
    // 0x800B32D8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800B32DC: jr          $ra
    // 0x800B32E0: sh          $a1, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r5;
    return;
    // 0x800B32E0: sh          $a1, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void baanim_playForDuration_loopStartingAt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CC34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008CC38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008CC3C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008CC40: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8008CC44: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8008CC48: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8008CC4C: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8008CC50: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8008CC54: jal         0x8008AF24
    // 0x8008CC58: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    anctrl_reset(rdram, ctx);
        goto after_0;
    // 0x8008CC58: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x8008CC5C: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x8008CC60: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8008CC64: jal         0x8008AED4
    // 0x8008CC68: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    anctrl_setIndex(rdram, ctx);
        goto after_1;
    // 0x8008CC68: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_1:
    // 0x8008CC6C: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x8008CC70: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8008CC74: jal         0x8008B1BC
    // 0x8008CC78: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    anctrl_setDuration(rdram, ctx);
        goto after_2;
    // 0x8008CC78: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_2:
    // 0x8008CC7C: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x8008CC80: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8008CC84: jal         0x8008B24C
    // 0x8008CC88: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    anctrl_setStart(rdram, ctx);
        goto after_3;
    // 0x8008CC88: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_3:
    // 0x8008CC8C: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x8008CC90: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8008CC94: jal         0x8008B134
    // 0x8008CC98: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_4;
    // 0x8008CC98: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    after_4:
    // 0x8008CC9C: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x8008CCA0: jal         0x8008B064
    // 0x8008CCA4: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    anctrl_start(rdram, ctx);
        goto after_5;
    // 0x8008CCA4: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    after_5:
    // 0x8008CCA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008CCAC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008CCB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008CCB4: jr          $ra
    // 0x8008CCB8: nop

    return;
    // 0x8008CCB8: nop

;}
RECOMP_FUNC void func_808013B4_bskaztorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808013B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808013BC: jal         0x808005F0
    // 0x808013C0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_808005F0_bskaztorpedo(rdram, ctx);
        goto after_0;
    // 0x808013C0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808013C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808013C8: jal         0x80084DA0
    // 0x808013CC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _bakaztorpedo_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x808013CC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x808013D0: lui         $a2, 0x3FE6
    ctx->r6 = S32(0X3FE6 << 16);
    // 0x808013D4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808013D8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808013DC: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x808013E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808013E4: addiu       $a1, $zero, 0x134
    ctx->r5 = ADD32(0, 0X134);
    // 0x808013E8: jal         0x80085150
    // 0x808013EC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _baspin_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808013EC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x808013F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808013F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808013F8: jr          $ra
    // 0x808013FC: nop

    return;
    // 0x808013FC: nop

;}
RECOMP_FUNC void _bstaxi_entrypoint_29(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083EB0: syscall     96
    recomp_syscall_handler(rdram, ctx, 0x80083EB0);
    return;
    // 0x80083EB4: addi        $t0, $zero, 0x74
    ctx->r8 = ADD32(0, 0X74);
;}
RECOMP_FUNC void chjinjo_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011B4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1672, 0X13EC) << 16);
    // 0x808011B8: jr          $ra
    // 0x808011BC: addiu       $v0, $v0, 0x13EC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1672, 0X13EC));
    return;
    // 0x808011BC: addiu       $v0, $v0, 0x13EC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1672, 0X13EC));
;}
RECOMP_FUNC void bababykaz_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C0: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x808000C4: jr          $ra
    // 0x808000C8: lbu         $v0, 0x0($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X0);
    return;
    // 0x808000C8: lbu         $v0, 0x0($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X0);
;}
RECOMP_FUNC void func_8010D350(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010D350: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x8010D354: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x8010D358: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8010D35C: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x8010D360: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x8010D364: mtc1        $a2, $f26
    ctx->f26.u32l = ctx->r6;
    // 0x8010D368: addiu       $s4, $sp, 0x90
    ctx->r20 = ADD32(ctx->r29, 0X90);
    // 0x8010D36C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8010D370: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8010D374: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x8010D378: sw          $a0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r4;
    // 0x8010D37C: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x8010D380: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x8010D384: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x8010D388: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x8010D38C: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x8010D390: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8010D394: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8010D398: jal         0x800EE7F8
    // 0x8010D39C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8010D39C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_0:
    // 0x8010D3A0: addiu       $s5, $sp, 0x84
    ctx->r21 = ADD32(ctx->r29, 0X84);
    // 0x8010D3A4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8010D3A8: jal         0x800EE7F8
    // 0x8010D3AC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x8010D3AC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x8010D3B0: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8010D3B4: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8010D3B8: jal         0x800F5898
    // 0x8010D3BC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    func_800F5898(rdram, ctx);
        goto after_2;
    // 0x8010D3BC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_2:
    // 0x8010D3C0: blez        $v0, L_8010D458
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8010D3C4: addiu       $s2, $sp, 0x78
        ctx->r18 = ADD32(ctx->r29, 0X78);
            goto L_8010D458;
    }
    // 0x8010D3C4: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
    // 0x8010D3C8: addiu       $s1, $sp, 0x9C
    ctx->r17 = ADD32(ctx->r29, 0X9C);
L_8010D3CC:
    // 0x8010D3CC: jal         0x800F6438
    // 0x8010D3D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6438(rdram, ctx);
        goto after_3;
    // 0x8010D3D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8010D3D4: beq         $v0, $zero, L_8010D444
    if (ctx->r2 == 0) {
        // 0x8010D3D8: nop
    
            goto L_8010D444;
    }
    // 0x8010D3D8: nop

    // 0x8010D3DC: beq         $s0, $s3, L_8010D444
    if (ctx->r16 == ctx->r19) {
        // 0x8010D3E0: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_8010D444;
    }
    // 0x8010D3E0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8010D3E4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8010D3E8: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x8010D3EC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8010D3F0: mul.s       $f20, $f26, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = MUL_S(ctx->f26.fl, ctx->f18.fl);
    // 0x8010D3F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010D3F8: add.s       $f22, $f16, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f22.fl = ctx->f16.fl + ctx->f26.fl;
    // 0x8010D3FC: jal         0x800F5A00
    // 0x8010D400: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800F5A00(rdram, ctx);
        goto after_4;
    // 0x8010D400: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x8010D404: lwc1        $f8, 0xA0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8010D408: add.s       $f24, $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f20.fl;
    // 0x8010D40C: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8010D410: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8010D414: sub.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f26.fl;
    // 0x8010D418: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x8010D41C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8010D420: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8010D424: swc1        $f10, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f10.u32l;
    // 0x8010D428: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    // 0x8010D42C: jal         0x800F0734
    // 0x8010D430: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    func_800F0734(rdram, ctx);
        goto after_5;
    // 0x8010D430: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    after_5:
    // 0x8010D434: beq         $v0, $zero, L_8010D444
    if (ctx->r2 == 0) {
        // 0x8010D438: nop
    
            goto L_8010D444;
    }
    // 0x8010D438: nop

    // 0x8010D43C: b           L_8010D45C
    // 0x8010D440: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_8010D45C;
    // 0x8010D440: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8010D444:
    // 0x8010D444: jal         0x800F5898
    // 0x8010D448: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    func_800F5898(rdram, ctx);
        goto after_6;
    // 0x8010D448: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_6:
    // 0x8010D44C: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8010D450: bne         $at, $zero, L_8010D3CC
    if (ctx->r1 != 0) {
        // 0x8010D454: nop
    
            goto L_8010D3CC;
    }
    // 0x8010D454: nop

L_8010D458:
    // 0x8010D458: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8010D45C:
    // 0x8010D45C: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8010D460: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8010D464: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8010D468: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x8010D46C: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x8010D470: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x8010D474: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x8010D478: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x8010D47C: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x8010D480: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x8010D484: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x8010D488: jr          $ra
    // 0x8010D48C: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x8010D48C: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void bawandglow_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800114: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800118: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080011C: lw          $v0, 0x148($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X148);
    // 0x80800120: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800124: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    // 0x80800128: beq         $a2, $zero, L_80800140
    if (ctx->r6 == 0) {
        // 0x8080012C: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80800140;
    }
    // 0x8080012C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800130: jal         0x800872F8
    // 0x80800134: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    _chwandglow_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800134: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800138: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8080013C: lw          $v0, 0x148($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X148);
L_80800140:
    // 0x80800140: sb          $zero, 0x10($v0)
    MEM_B(0X10, ctx->r2) = 0;
    // 0x80800144: lw          $t6, 0x148($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X148);
    // 0x80800148: sw          $zero, 0xC($t6)
    MEM_W(0XC, ctx->r14) = 0;
    // 0x8080014C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800150: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800154: jr          $ra
    // 0x80800158: nop

    return;
    // 0x80800158: nop

;}
RECOMP_FUNC void func_800CB9FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB9FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CBA00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CBA04: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800CBA08: jal         0x80087EE8
    // 0x800CBA0C: addiu       $a0, $a0, -0x5180
    ctx->r4 = ADD32(ctx->r4, -0X5180);
    _gcboundDll_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x800CBA0C: addiu       $a0, $a0, -0x5180
    ctx->r4 = ADD32(ctx->r4, -0X5180);
    after_0:
    // 0x800CBA10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CBA14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CBA18: jr          $ra
    // 0x800CBA1C: nop

    return;
    // 0x800CBA1C: nop

;}
RECOMP_FUNC void func_8008DD90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DD90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008DD94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008DD98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008DD9C: jal         0x8009E674
    // 0x8008DDA0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_8009E674(rdram, ctx);
        goto after_0;
    // 0x8008DDA0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_0:
    // 0x8008DDA4: beq         $v0, $zero, L_8008DDB4
    if (ctx->r2 == 0) {
        // 0x8008DDA8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8008DDB4;
    }
    // 0x8008DDA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008DDAC: b           L_8008DDDC
    // 0x8008DDB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8008DDDC;
    // 0x8008DDB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008DDB4:
    // 0x8008DDB4: jal         0x8009E674
    // 0x8008DDB8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_8009E674(rdram, ctx);
        goto after_1;
    // 0x8008DDB8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_1:
    // 0x8008DDBC: beql        $v0, $zero, L_8008DDDC
    if (ctx->r2 == 0) {
        // 0x8008DDC0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8008DDDC;
    }
    goto skip_0;
    // 0x8008DDC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8008DDC4: jal         0x800847F0
    // 0x8008DDC8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _badrone_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x8008DDC8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8008DDCC: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8008DDD0: b           L_8008DDDC
    // 0x8008DDD4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_8008DDDC;
    // 0x8008DDD4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8008DDD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008DDDC:
    // 0x8008DDDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008DDE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008DDE4: jr          $ra
    // 0x8008DDE8: nop

    return;
    // 0x8008DDE8: nop

;}
RECOMP_FUNC void bakey_setState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091C80: lw          $v1, 0x40($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X40);
    // 0x80091C84: xori        $t7, $a2, 0x2
    ctx->r15 = ctx->r6 ^ 0X2;
    // 0x80091C88: addu        $a3, $v1, $a1
    ctx->r7 = ADD32(ctx->r3, ctx->r5);
    // 0x80091C8C: lbu         $v0, 0xA($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0XA);
    // 0x80091C90: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x80091C94: bne         $t6, $zero, L_80091CAC
    if (ctx->r14 != 0) {
        // 0x80091C98: nop
    
            goto L_80091CAC;
    }
    // 0x80091C98: nop

    // 0x80091C9C: bne         $t7, $zero, L_80091CAC
    if (ctx->r15 != 0) {
        // 0x80091CA0: nop
    
            goto L_80091CAC;
    }
    // 0x80091CA0: nop

    // 0x80091CA4: jr          $ra
    // 0x80091CA8: lbu         $v0, 0x18($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X18);
    return;
    // 0x80091CA8: lbu         $v0, 0x18($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X18);
L_80091CAC:
    // 0x80091CAC: beq         $a2, $zero, L_80091CCC
    if (ctx->r6 == 0) {
        // 0x80091CB0: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80091CCC;
    }
    // 0x80091CB0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80091CB4: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    // 0x80091CB8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80091CBC: sllv        $t0, $t9, $a1
    ctx->r8 = S32(ctx->r25 << (ctx->r5 & 31));
    // 0x80091CC0: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80091CC4: b           L_80091CE0
    // 0x80091CC8: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
        goto L_80091CE0;
    // 0x80091CC8: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
L_80091CCC:
    // 0x80091CCC: lw          $t2, 0x4($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X4);
    // 0x80091CD0: sllv        $t4, $t3, $a1
    ctx->r12 = S32(ctx->r11 << (ctx->r5 & 31));
    // 0x80091CD4: nor         $t5, $t4, $zero
    ctx->r13 = ~(ctx->r12 | 0);
    // 0x80091CD8: and         $t6, $t2, $t5
    ctx->r14 = ctx->r10 & ctx->r13;
    // 0x80091CDC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
L_80091CE0:
    // 0x80091CE0: lw          $t7, 0x40($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X40);
    // 0x80091CE4: addu        $t9, $t7, $a1
    ctx->r25 = ADD32(ctx->r15, ctx->r5);
    // 0x80091CE8: sb          $a2, 0xA($t9)
    MEM_B(0XA, ctx->r25) = ctx->r6;
    // 0x80091CEC: lw          $t8, 0x40($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X40);
    // 0x80091CF0: addu        $t0, $t8, $a1
    ctx->r8 = ADD32(ctx->r24, ctx->r5);
    // 0x80091CF4: lbu         $v0, 0x18($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X18);
    // 0x80091CF8: jr          $ra
    // 0x80091CFC: nop

    return;
    // 0x80091CFC: nop

;}
RECOMP_FUNC void _bsbanbflip_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082680: syscall     5
    recomp_syscall_handler(rdram, ctx, 0x80082680);
    return;
    // 0x80082684: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800A18_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A18: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800A1C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800A20: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800A24: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800A28: jal         0x80802484
    // 0x80800A2C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    func_80802484_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80800A2C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800A30: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80800A34: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800A38: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800A3C: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x80800A40: jal         0x80800978
    // 0x80800A44: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    func_80800978_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80800A44: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    after_1:
    // 0x80800A48: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80800A4C: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800A50: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800A54: lbu         $a1, 0x2B($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X2B);
    // 0x80800A58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A5C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800A60: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80800A64: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80800A68: jal         0x800E0AFC
    // 0x80800A6C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_2;
    // 0x80800A6C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x80800A70: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80800A74: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800A78: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800A7C: lbu         $a1, 0x2F($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X2F);
    // 0x80800A80: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x80800A84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A88: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x80800A8C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800A90: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800A94: jal         0x800E0AFC
    // 0x80800A98: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_3;
    // 0x80800A98: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x80800A9C: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80800AA0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800AA4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800AA8: lw          $v0, 0x188($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X188);
    // 0x80800AAC: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x80800AB0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800AB4: lwc1        $f18, 0x44($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80800AB8: lwc1        $f6, 0x60($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X60);
    // 0x80800ABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AC0: mul.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80800AC4: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    // 0x80800AC8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800ACC: mul.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800AD0: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800AD4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80800AD8: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800ADC: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x80800AE0: jal         0x800E0AFC
    // 0x80800AE4: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_4;
    // 0x80800AE4: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    after_4:
    // 0x80800AE8: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800AEC: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800AF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AF4: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    // 0x80800AF8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800AFC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800B00: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80800B04: jal         0x800E0AFC
    // 0x80800B08: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_5;
    // 0x80800B08: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x80800B0C: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800B10: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B18: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    // 0x80800B1C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800B20: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800B24: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80800B28: jal         0x800E0AFC
    // 0x80800B2C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_6;
    // 0x80800B2C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x80800B30: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800B34: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800B38: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800B3C: jr          $ra
    // 0x80800B40: nop

    return;
    // 0x80800B40: nop

;}
RECOMP_FUNC void func_80800658_chlagoonbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800658: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080065C: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80800660: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800664: beq         $a1, $at, L_80800698
    if (ctx->r5 == ctx->r1) {
        // 0x80800668: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80800698;
    }
    // 0x80800668: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080066C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800670: beq         $a1, $at, L_80800688
    if (ctx->r5 == ctx->r1) {
        // 0x80800674: addiu       $at, $zero, 0x90
        ctx->r1 = ADD32(0, 0X90);
            goto L_80800688;
    }
    // 0x80800674: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x80800678: beq         $a1, $at, L_808006A8
    if (ctx->r5 == ctx->r1) {
        // 0x8080067C: nop
    
            goto L_808006A8;
    }
    // 0x8080067C: nop

    // 0x80800680: b           L_80800720
    // 0x80800684: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800720;
    // 0x80800684: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800688:
    // 0x80800688: jal         0x80800730
    // 0x8080068C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_80800730_chlagoonbits(rdram, ctx);
        goto after_0;
    // 0x8080068C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_0:
    // 0x80800690: b           L_80800720
    // 0x80800694: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800720;
    // 0x80800694: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800698:
    // 0x80800698: jal         0x808005D0
    // 0x8080069C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_808005D0_chlagoonbits(rdram, ctx);
        goto after_1;
    // 0x8080069C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x808006A0: b           L_80800720
    // 0x808006A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800720;
    // 0x808006A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006A8:
    // 0x808006A8: jal         0x80101080
    // 0x808006AC: nop

    func_80101080(rdram, ctx);
        goto after_2;
    // 0x808006AC: nop

    after_2:
    // 0x808006B0: jal         0x80106790
    // 0x808006B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_3;
    // 0x808006B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x808006B8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x808006BC: addiu       $at, $zero, 0x761
    ctx->r1 = ADD32(0, 0X761);
    // 0x808006C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808006C4: beq         $t6, $at, L_808006E0
    if (ctx->r14 == ctx->r1) {
        // 0x808006C8: lui         $a1, 0x43FA
        ctx->r5 = S32(0X43FA << 16);
            goto L_808006E0;
    }
    // 0x808006C8: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x808006CC: addiu       $at, $zero, 0x786
    ctx->r1 = ADD32(0, 0X786);
    // 0x808006D0: beq         $t6, $at, L_80800704
    if (ctx->r14 == ctx->r1) {
        // 0x808006D4: nop
    
            goto L_80800704;
    }
    // 0x808006D4: nop

    // 0x808006D8: b           L_80800720
    // 0x808006DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800720;
    // 0x808006DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006E0:
    // 0x808006E0: lui         $a2, 0x4416
    ctx->r6 = S32(0X4416 << 16);
    // 0x808006E4: jal         0x80086688
    // 0x808006E8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    _chexploder_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x808006E8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_4:
    // 0x808006EC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808006F0: lui         $a1, 0xC3FA
    ctx->r5 = S32(0XC3FA << 16);
    // 0x808006F4: jal         0x80086690
    // 0x808006F8: lui         $a2, 0xC3C8
    ctx->r6 = S32(0XC3C8 << 16);
    _chexploder_entrypoint_7(rdram, ctx);
        goto after_5;
    // 0x808006F8: lui         $a2, 0xC3C8
    ctx->r6 = S32(0XC3C8 << 16);
    after_5:
    // 0x808006FC: b           L_80800720
    // 0x80800700: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800720;
    // 0x80800700: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800704:
    // 0x80800704: jal         0x800866B8
    // 0x80800708: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    _chexploder_entrypoint_12(rdram, ctx);
        goto after_6;
    // 0x80800708: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    after_6:
    // 0x8080070C: b           L_80800720
    // 0x80800710: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800720;
    // 0x80800710: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800714: b           L_80800720
    // 0x80800718: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800720;
    // 0x80800718: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080071C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800720:
    // 0x80800720: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800724: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800728: jr          $ra
    // 0x8080072C: nop

    return;
    // 0x8080072C: nop

;}
RECOMP_FUNC void bashoes_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: lw          $t6, 0x10C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10C);
    // 0x8080000C: jr          $ra
    // 0x80800010: lbu         $v0, 0x4($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X4);
    return;
    // 0x80800010: lbu         $v0, 0x4($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X4);
;}
RECOMP_FUNC void func_800C7FD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7FD4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C7FD8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C7FDC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C7FE0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800C7FE4: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800C7FE8: lbu         $t6, 0x4($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X4);
    // 0x800C7FEC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C7FF0: beq         $t6, $zero, L_800C8008
    if (ctx->r14 == 0) {
        // 0x800C7FF4: nop
    
            goto L_800C8008;
    }
    // 0x800C7FF4: nop

    // 0x800C7FF8: jal         0x800885F8
    // 0x800C7FFC: nop

    _glintrosyncDll_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x800C7FFC: nop

    after_0:
    // 0x800C8000: b           L_800C8014
    // 0x800C8004: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_800C8014;
    // 0x800C8004: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_800C8008:
    // 0x800C8008: jal         0x800D8FF8
    // 0x800C800C: nop

    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x800C800C: nop

    after_1:
    // 0x800C8010: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_800C8014:
    // 0x800C8014: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C8018: jal         0x800C7E28
    // 0x800C801C: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    func_800C7E28(rdram, ctx);
        goto after_2;
    // 0x800C801C: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x800C8020: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x800C8024: jal         0x800C7980
    // 0x800C8028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C7980(rdram, ctx);
        goto after_3;
    // 0x800C8028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800C802C: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800C8030: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C8034: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800C8038: lbu         $a0, 0x2($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X2);
    // 0x800C803C: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800C8040: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x800C8044: addiu       $a1, $s0, 0x14
    ctx->r5 = ADD32(ctx->r16, 0X14);
    // 0x800C8048: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x800C804C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800C8050: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x800C8054: jal         0x80089140
    // 0x800C8058: nop

    _mlspline_entrypoint_13(rdram, ctx);
        goto after_4;
    // 0x800C8058: nop

    after_4:
    // 0x800C805C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C8060: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C8064: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800C8068: jr          $ra
    // 0x800C806C: nop

    return;
    // 0x800C806C: nop

;}
RECOMP_FUNC void chdoormake_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800264: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800268: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080026C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800270: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800274: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800278: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8080027C: jal         0x80800000
    // 0x80800280: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800000_chdoormake(rdram, ctx);
        goto after_0;
    // 0x80800280: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x80800284: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800288: lwc1        $f4, 0x44($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8080028C: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800290: jal         0x800136E4
    // 0x80800294: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    func_800136E4(rdram, ctx);
        goto after_1;
    // 0x80800294: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_1:
    // 0x80800298: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8080029C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A4: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x808002A8: nop

    // 0x808002AC: sh          $t7, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r15;
    // 0x808002B0: lwc1        $f10, 0x44($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X44);
    // 0x808002B4: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x808002B8: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x808002BC: jal         0x808008C4
    // 0x808002C0: sh          $t9, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r25;
    func_808008C4_chdoormake(rdram, ctx);
        goto after_2;
    // 0x808002C0: sh          $t9, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r25;
    after_2:
    // 0x808002C4: bne         $v0, $zero, L_808002DC
    if (ctx->r2 != 0) {
        // 0x808002C8: lw          $t2, 0x30($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X30);
            goto L_808002DC;
    }
    // 0x808002C8: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x808002CC: lhu         $t0, 0x72($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X72);
    // 0x808002D0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808002D4: srl         $t1, $t0, 10
    ctx->r9 = S32(U32(ctx->r8) >> 10);
    // 0x808002D8: bne         $t1, $at, L_80800328
    if (ctx->r9 != ctx->r1) {
        // 0x808002DC: andi        $t3, $t2, 0x1
        ctx->r11 = ctx->r10 & 0X1;
            goto L_80800328;
    }
L_808002DC:
    // 0x808002DC: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x808002E0: beq         $t3, $zero, L_808002F8
    if (ctx->r11 == 0) {
        // 0x808002E4: lw          $t4, 0x24($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X24);
            goto L_808002F8;
    }
    // 0x808002E4: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x808002E8: jal         0x800FFAB0
    // 0x808002EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_3;
    // 0x808002EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808002F0: b           L_80800334
    // 0x808002F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800334;
    // 0x808002F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808002F8:
    // 0x808002F8: lh          $t5, 0x10($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X10);
    // 0x808002FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800300: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800304: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x80800308: nop

    // 0x8080030C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800310: jal         0x80101FDC
    // 0x80800314: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x80800314: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
    after_4:
    // 0x80800318: jal         0x808000B8
    // 0x8080031C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000B8_chdoormake(rdram, ctx);
        goto after_5;
    // 0x8080031C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800320: b           L_80800334
    // 0x80800324: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80800334;
    // 0x80800324: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80800328:
    // 0x80800328: jal         0x808000B8
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000B8_chdoormake(rdram, ctx);
        goto after_6;
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800330: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800334:
    // 0x80800334: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800338: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080033C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800340: jr          $ra
    // 0x80800344: nop

    return;
    // 0x80800344: nop

;}
RECOMP_FUNC void _gczoomboxdata_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088418: syscall     682
    recomp_syscall_handler(rdram, ctx, 0x80088418);
    return;
    // 0x8008841C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800DC3D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DC3D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800DC3D8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800DC3DC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800DC3E0: lbu         $t8, 0x3B($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X3B);
    // 0x800DC3E4: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800DC3E8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800DC3EC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800DC3F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800DC3F4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800DC3F8: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x800DC3FC: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x800DC400: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800DC404: lhu         $a1, 0x32($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X32);
    // 0x800DC408: lbu         $a2, 0x37($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X37);
    // 0x800DC40C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800DC410: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800DC414: jal         0x80020790
    // 0x800DC418: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    func_80020790(rdram, ctx);
        goto after_0;
    // 0x800DC418: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    after_0:
    // 0x800DC41C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800DC420: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800DC424: jr          $ra
    // 0x800DC428: nop

    return;
    // 0x800DC428: nop

;}
RECOMP_FUNC void func_80800314_ncpod(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800314: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800318: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080031C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800320: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800324: lh          $v0, 0x3C($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X3C);
    // 0x80800328: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080032C: beql        $v0, $zero, L_808003CC
    if (ctx->r2 == 0) {
        // 0x80800330: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_808003CC;
    }
    goto skip_0;
    // 0x80800330: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_0:
    // 0x80800334: beq         $v0, $at, L_80800358
    if (ctx->r2 == ctx->r1) {
        // 0x80800338: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80800358;
    }
    // 0x80800338: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8080033C: beq         $v0, $at, L_808003B4
    if (ctx->r2 == ctx->r1) {
        // 0x80800340: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_808003B4;
    }
    // 0x80800340: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800344: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800348: beql        $v0, $at, L_808003CC
    if (ctx->r2 == ctx->r1) {
        // 0x8080034C: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_808003CC;
    }
    goto skip_1;
    // 0x8080034C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_1:
    // 0x80800350: b           L_808003CC
    // 0x80800354: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_808003CC;
    // 0x80800354: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80800358:
    // 0x80800358: jal         0x80089638
    // 0x8080035C: lh          $a0, 0x2($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X2);
    _ncpoducam_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080035C: lh          $a0, 0x2($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X2);
    after_0:
    // 0x80800360: jal         0x80089658
    // 0x80800364: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _ncpoducam_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80800364: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800368: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8080036C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800370: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800374: bne         $t6, $at, L_808003C8
    if (ctx->r14 != ctx->r1) {
        // 0x80800378: andi        $t7, $v0, 0x100
        ctx->r15 = ctx->r2 & 0X100;
            goto L_808003C8;
    }
    // 0x80800378: andi        $t7, $v0, 0x100
    ctx->r15 = ctx->r2 & 0X100;
    // 0x8080037C: beql        $t7, $zero, L_80800394
    if (ctx->r15 == 0) {
        // 0x80800380: andi        $t8, $v1, 0x20
        ctx->r24 = ctx->r3 & 0X20;
            goto L_80800394;
    }
    goto skip_2;
    // 0x80800380: andi        $t8, $v1, 0x20
    ctx->r24 = ctx->r3 & 0X20;
    skip_2:
    // 0x80800384: jal         0x80088830
    // 0x80800388: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    _glcutDll_entrypoint_17(rdram, ctx);
        goto after_2;
    // 0x80800388: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x8080038C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800390: andi        $t8, $v1, 0x20
    ctx->r24 = ctx->r3 & 0X20;
L_80800394:
    // 0x80800394: bne         $t8, $zero, L_808003AC
    if (ctx->r24 != 0) {
        // 0x80800398: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808003AC;
    }
    // 0x80800398: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080039C: jal         0x808009E4
    // 0x808003A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ncpod_entrypoint_17(rdram, ctx);
        goto after_3;
    // 0x808003A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808003A4: b           L_808003D0
    // 0x808003A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808003D0;
    // 0x808003A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003AC:
    // 0x808003AC: b           L_808003CC
    // 0x808003B0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_808003CC;
    // 0x808003B0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808003B4:
    // 0x808003B4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x808003B8: jal         0x80088080
    // 0x808003BC: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    _gcdialogcamera_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x808003BC: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_4:
    // 0x808003C0: b           L_808003D0
    // 0x808003C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808003D0;
    // 0x808003C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003C8:
    // 0x808003C8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_808003CC:
    // 0x808003CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003D0:
    // 0x808003D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003D4: jr          $ra
    // 0x808003D8: nop

    return;
    // 0x808003D8: nop

;}
RECOMP_FUNC void _chtrashcompactor_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800861F0: syscall     288
    recomp_syscall_handler(rdram, ctx, 0x800861F0);
    return;
    // 0x800861F4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_8080416C_chintrochar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
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
RECOMP_FUNC void func_8080000C_chfactoryworkerwear(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800018: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080001C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800020: jal         0x80100094
    // 0x80800024: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800024: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800028: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8080002C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800030: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800034: beq         $a3, $at, L_8080005C
    if (ctx->r7 == ctx->r1) {
        // 0x80800038: addiu       $a0, $v1, 0x4
        ctx->r4 = ADD32(ctx->r3, 0X4);
            goto L_8080005C;
    }
    // 0x80800038: addiu       $a0, $v1, 0x4
    ctx->r4 = ADD32(ctx->r3, 0X4);
    // 0x8080003C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800040: beq         $a3, $at, L_80800080
    if (ctx->r7 == ctx->r1) {
        // 0x80800044: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80800080;
    }
    // 0x80800044: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800048: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080004C: beql        $a3, $at, L_808000B8
    if (ctx->r7 == ctx->r1) {
        // 0x80800050: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_808000B8;
    }
    goto skip_0;
    // 0x80800050: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_0:
    // 0x80800054: b           L_808000E4
    // 0x80800058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808000E4;
    // 0x80800058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080005C:
    // 0x8080005C: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800060: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800064: jal         0x800EE7F8
    // 0x80800068: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800068: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    after_1:
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800070: jal         0x8010A800
    // 0x80800074: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8010A800(rdram, ctx);
        goto after_2;
    // 0x80800074: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800078: b           L_808000E0
    // 0x8080007C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
        goto L_808000E0;
    // 0x8080007C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
L_80800080:
    // 0x80800080: jal         0x800EE7F8
    // 0x80800084: addiu       $a1, $v1, 0x10
    ctx->r5 = ADD32(ctx->r3, 0X10);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800084: addiu       $a1, $v1, 0x10
    ctx->r5 = ADD32(ctx->r3, 0X10);
    after_3:
    // 0x80800088: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8080008C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800090: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800094: jal         0x800136E4
    // 0x80800098: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    func_800136E4(rdram, ctx);
        goto after_4;
    // 0x80800098: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_4:
    // 0x8080009C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808000A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808000A4: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x808000A8: swc1        $f10, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f10.u32l;
    // 0x808000AC: b           L_808000E0
    // 0x808000B0: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
        goto L_808000E0;
    // 0x808000B0: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x808000B4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_808000B8:
    // 0x808000B8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2172, 0X400) << 16);
    // 0x808000BC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x808000C0: swc1        $f16, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f16.u32l;
    // 0x808000C4: lwc1        $f18, 0x400($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2172, 0X400));
    // 0x808000C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000CC: addiu       $a1, $zero, 0x83C
    ctx->r5 = ADD32(0, 0X83C);
    // 0x808000D0: swc1        $f18, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f18.u32l;
    // 0x808000D4: jal         0x801032B0
    // 0x808000D8: lhu         $a2, 0x16($t6)
    ctx->r6 = MEM_HU(ctx->r14, 0X16);
    func_801032B0(rdram, ctx);
        goto after_5;
    // 0x808000D8: lhu         $a2, 0x16($t6)
    ctx->r6 = MEM_HU(ctx->r14, 0X16);
    after_5:
    // 0x808000DC: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
L_808000E0:
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808000E4:
    // 0x808000E4: jal         0x80102424
    // 0x808000E8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x808000E8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_6:
    // 0x808000EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000F8: jr          $ra
    // 0x808000FC: nop

    return;
    // 0x808000FC: nop

;}
RECOMP_FUNC void func_8009E390(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E390: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8009E394: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8009E398: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8009E39C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8009E3A0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8009E3A4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8009E3A8: lw          $t6, 0x114($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X114);
    // 0x8009E3AC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8009E3B0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8009E3B4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8009E3B8: addiu       $s1, $zero, 0x78
    ctx->r17 = ADD32(0, 0X78);
    // 0x8009E3BC: sb          $zero, 0xF0($t6)
    MEM_B(0XF0, ctx->r14) = 0;
    // 0x8009E3C0: lw          $t7, 0x114($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X114);
L_8009E3C4:
    // 0x8009E3C4: addu        $v0, $t7, $s0
    ctx->r2 = ADD32(ctx->r15, ctx->r16);
    // 0x8009E3C8: swc1        $f20, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f20.u32l;
    // 0x8009E3CC: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x8009E3D0: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x8009E3D4: swc1        $f20, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f20.u32l;
    // 0x8009E3D8: swc1        $f20, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f20.u32l;
    // 0x8009E3DC: swc1        $f20, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f20.u32l;
    // 0x8009E3E0: swc1        $f20, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f20.u32l;
    // 0x8009E3E4: jal         0x800EFD24
    // 0x8009E3E8: addiu       $a0, $v0, 0xC
    ctx->r4 = ADD32(ctx->r2, 0XC);
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x8009E3E8: addiu       $a0, $v0, 0xC
    ctx->r4 = ADD32(ctx->r2, 0XC);
    after_0:
    // 0x8009E3EC: addiu       $s0, $s0, 0x28
    ctx->r16 = ADD32(ctx->r16, 0X28);
    // 0x8009E3F0: bnel        $s0, $s1, L_8009E3C4
    if (ctx->r16 != ctx->r17) {
        // 0x8009E3F4: lw          $t7, 0x114($s2)
        ctx->r15 = MEM_W(ctx->r18, 0X114);
            goto L_8009E3C4;
    }
    goto skip_0;
    // 0x8009E3F4: lw          $t7, 0x114($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X114);
    skip_0:
    // 0x8009E3F8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8009E3FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009E400: jal         0x8009E5A4
    // 0x8009E404: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8009E5A4(rdram, ctx);
        goto after_1;
    // 0x8009E404: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8009E408: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8009E40C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8009E410: jal         0x8009E5A4
    // 0x8009E414: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_8009E5A4(rdram, ctx);
        goto after_2;
    // 0x8009E414: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_2:
    // 0x8009E418: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8009E41C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8009E420: jal         0x8009E5A4
    // 0x8009E424: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_8009E5A4(rdram, ctx);
        goto after_3;
    // 0x8009E424: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_3:
    // 0x8009E428: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8009E42C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009E430: jal         0x8009E55C
    // 0x8009E434: lui         $a2, 0x4200
    ctx->r6 = S32(0X4200 << 16);
    func_8009E55C(rdram, ctx);
        goto after_4;
    // 0x8009E434: lui         $a2, 0x4200
    ctx->r6 = S32(0X4200 << 16);
    after_4:
    // 0x8009E438: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8009E43C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8009E440: jal         0x8009E55C
    // 0x8009E444: lui         $a2, 0x41E0
    ctx->r6 = S32(0X41E0 << 16);
    func_8009E55C(rdram, ctx);
        goto after_5;
    // 0x8009E444: lui         $a2, 0x41E0
    ctx->r6 = S32(0X41E0 << 16);
    after_5:
    // 0x8009E448: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8009E44C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8009E450: jal         0x8009E55C
    // 0x8009E454: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8009E55C(rdram, ctx);
        goto after_6;
    // 0x8009E454: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_6:
    // 0x8009E458: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8009E45C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8009E460: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8009E464: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8009E468: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8009E46C: jr          $ra
    // 0x8009E470: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8009E470: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _chTalTorpWall_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087120: syscall     518
    recomp_syscall_handler(rdram, ctx, 0x80087120);
    return;
    // 0x80087124: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void idglowa_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800108: jr          $ra
    // 0x8080010C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8080010C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_808038C4_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808038C4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808038C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808038CC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808038D0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808038D4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x808038D8: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x808038DC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808038E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808038E4: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x808038E8: addiu       $a0, $zero, 0x2A4
    ctx->r4 = ADD32(0, 0X2A4);
    // 0x808038EC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808038F0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808038F4: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x808038F8: jal         0x80108474
    // 0x808038FC: nop

    func_80108474(rdram, ctx);
        goto after_0;
    // 0x808038FC: nop

    after_0:
    // 0x80803900: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x80803904: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80803908: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8080390C: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80803910: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80803914: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80803918: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x8080391C: lwc1        $f18, 0x4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80803920: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80803924: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80803928: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x8080392C: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80803930: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80803934: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x80803938: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8080393C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80803940: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80803944: lui         $a3, 0x4316
    ctx->r7 = S32(0X4316 << 16);
    // 0x80803948: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x8080394C: sw          $t9, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r25;
    // 0x80803950: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80803954: lbu         $t4, 0x79($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X79);
    // 0x80803958: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x8080395C: andi        $t5, $t4, 0xFF0F
    ctx->r13 = ctx->r12 & 0XFF0F;
    // 0x80803960: swc1        $f18, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f18.u32l;
    // 0x80803964: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80803968: sll         $t3, $t1, 4
    ctx->r11 = S32(ctx->r9 << 4);
    // 0x8080396C: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x80803970: sb          $t6, 0x79($v0)
    MEM_B(0X79, ctx->r2) = ctx->r14;
    // 0x80803974: jal         0x800EF6A8
    // 0x80803978: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800EF6A8(rdram, ctx);
        goto after_1;
    // 0x80803978: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8080397C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80803980: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80803984: jal         0x800EF04C
    // 0x80803988: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_2;
    // 0x80803988: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_2:
    // 0x8080398C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80803990: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80803994: jal         0x800EE7F8
    // 0x80803998: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80803998: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_3:
    // 0x8080399C: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x808039A0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x808039A4: swc1        $f6, 0x58($t7)
    MEM_W(0X58, ctx->r15) = ctx->f6.u32l;
    // 0x808039A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808039AC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808039B0: jr          $ra
    // 0x808039B4: nop

    return;
    // 0x808039B4: nop

;}
RECOMP_FUNC void func_80800F34_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800F38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F3C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800F40: jal         0x800A89F8
    // 0x80800F44: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800A89F8(rdram, ctx);
        goto after_0;
    // 0x80800F44: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800F48: jal         0x800A9478
    // 0x80800F4C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800A9478(rdram, ctx);
        goto after_1;
    // 0x80800F4C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    if (tooie_quiz_no_player(rdram, ctx)) { ctx->r29 = ADD32(ctx->r29, 0X20); return; }
    // 0x80800F50: jal         0x800F5EF8
    // 0x80800F54: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5EF8(rdram, ctx);
        goto after_2;
    // 0x80800F54: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800F58: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80800F5C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800F60: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80800F64: sb          $t6, 0x5C($v1)
    MEM_B(0X5C, ctx->r3) = ctx->r14;
    // 0x80800F68: sh          $zero, 0x50($v1)
    MEM_H(0X50, ctx->r3) = 0;
    // 0x80800F6C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80800F70: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800F74: addiu       $a2, $zero, 0x2C
    ctx->r6 = ADD32(0, 0X2C);
    // 0x80800F78: addiu       $a3, $zero, 0x804
    ctx->r7 = ADD32(0, 0X804);
    // 0x80800F7C: jal         0x80089540
    // 0x80800F80: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    _ncpod_entrypoint_16(rdram, ctx);
        goto after_3;
    // 0x80800F80: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    after_3:
    // 0x80800F84: jal         0x80110024
    // 0x80800F88: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80110024(rdram, ctx);
        goto after_4;
    // 0x80800F88: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_4:
    // 0x80800F8C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800F90: jal         0x80089520
    // 0x80800F94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _ncpod_entrypoint_12(rdram, ctx);
        goto after_5;
    // 0x80800F94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80800F98: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800F9C: jal         0x80801170
    // 0x80800FA0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80801170_chquiz(rdram, ctx);
        goto after_6;
    // 0x80800FA0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x80800FA4: jal         0x8010FD88
    // 0x80800FA8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8010FD88(rdram, ctx);
        goto after_7;
    // 0x80800FA8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_7:
    // 0x80800FAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800FB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800FB4: jr          $ra
    // 0x80800FB8: nop

    return;
    // 0x80800FB8: nop

;}
RECOMP_FUNC void vpscroll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: lw          $a0, 0x14($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X14);
    // 0x80800010: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800014: sll         $t7, $a0, 1
    ctx->r15 = S32(ctx->r4 << 1);
    // 0x80800018: jal         0x8001ACCC
    // 0x8080001C: addiu       $a0, $t7, 0x10
    ctx->r4 = ADD32(ctx->r15, 0X10);
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x8080001C: addiu       $a0, $t7, 0x10
    ctx->r4 = ADD32(ctx->r15, 0X10);
    after_0:
    // 0x80800020: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80800024: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80800028: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080002C: lw          $t9, 0x14($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X14);
    // 0x80800030: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x80800034: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x80800038: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8080003C: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x80800040: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80800044: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80800048: div         $zero, $t1, $at
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r1)));
    // 0x8080004C: mfhi        $t2
    ctx->r10 = hi;
    // 0x80800050: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80800054: addu        $a1, $t0, $a2
    ctx->r5 = ADD32(ctx->r8, ctx->r6);
    // 0x80800058: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    // 0x8080005C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800060: addiu       $a0, $a2, 0x14
    ctx->r4 = ADD32(ctx->r6, 0X14);
    // 0x80800064: sltu        $at, $a0, $a1
    ctx->r1 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x80800068: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8080006C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80800070: beq         $at, $zero, L_808000B8
    if (ctx->r1 == 0) {
        // 0x80800074: swc1        $f8, 0x8($v0)
        MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
            goto L_808000B8;
    }
    // 0x80800074: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x80800078: lhu         $t3, 0x2($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X2);
L_8080007C:
    // 0x8080007C: beql        $t3, $zero, L_808000AC
    if (ctx->r11 == 0) {
        // 0x80800080: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_808000AC;
    }
    goto skip_0;
    // 0x80800080: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_0:
    // 0x80800084: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x80800088: subu        $t4, $v1, $a0
    ctx->r12 = SUB32(ctx->r3, ctx->r4);
    // 0x8080008C: sra         $t5, $t4, 2
    ctx->r13 = S32(SIGNED(ctx->r12) >> 2);
    // 0x80800090: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80800094: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80800098: sh          $t5, 0x10($t8)
    MEM_H(0X10, ctx->r24) = ctx->r13;
    // 0x8080009C: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x808000A0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x808000A4: sw          $t0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r8;
    // 0x808000A8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_808000AC:
    // 0x808000AC: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x808000B0: bnel        $at, $zero, L_8080007C
    if (ctx->r1 != 0) {
        // 0x808000B4: lhu         $t3, 0x2($v1)
        ctx->r11 = MEM_HU(ctx->r3, 0X2);
            goto L_8080007C;
    }
    goto skip_1;
    // 0x808000B4: lhu         $t3, 0x2($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X2);
    skip_1:
L_808000B8:
    // 0x808000B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000C0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x808000C4: jr          $ra
    // 0x808000C8: nop

    return;
    // 0x808000C8: nop

;}
