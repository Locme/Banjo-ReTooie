#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _subaddie3d_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089830: syscall     796
    recomp_syscall_handler(rdram, ctx, 0x80089830);
    return;
    // 0x80089834: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chhoney_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F60: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1668, 0X10D8) << 16);
    // 0x80800F64: jr          $ra
    // 0x80800F68: addiu       $v0, $v0, 0x10D8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1668, 0X10D8));
    return;
    // 0x80800F68: addiu       $v0, $v0, 0x10D8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1668, 0X10D8));
    // 0x80800F6C: nop

;}
RECOMP_FUNC void func_808007DC_cheggclockwork(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808007E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007E4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808007E8: jal         0x80100094
    // 0x808007EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808007EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808007F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808007F4: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // 0x808007F8: jal         0x8001B668
    // 0x808007FC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8001B668(rdram, ctx);
        goto after_1;
    // 0x808007FC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800800: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800804: sh          $v0, 0x2C($v1)
    MEM_H(0X2C, ctx->r3) = ctx->r2;
    // 0x80800808: jal         0x8001B798
    // 0x8080080C: lh          $a0, 0x2C($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2C);
    func_8001B798(rdram, ctx);
        goto after_2;
    // 0x8080080C: lh          $a0, 0x2C($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2C);
    after_2:
    // 0x80800810: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80800814: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800818: jal         0x800EE7F8
    // 0x8080081C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x8080081C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80800820: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800824: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800828: jal         0x800EE7F8
    // 0x8080082C: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x8080082C: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_4:
    // 0x80800830: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800834: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800838: jal         0x800EE7F8
    // 0x8080083C: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x8080083C: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_5:
    // 0x80800840: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800844: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800848: jr          $ra
    // 0x8080084C: nop

    return;
    // 0x8080084C: nop

;}
RECOMP_FUNC void func_80115444(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115444: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x80115448: lwc1        $f4, 0xC($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XC);
    // 0x8011544C: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x80115450: lw          $t7, 0x14($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X14);
    // 0x80115454: lwc1        $f6, 0x10($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X10);
    // 0x80115458: jr          $ra
    // 0x8011545C: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    return;
    // 0x8011545C: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_80800000_gcnewoption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lh          $t6, 0xA($a0)
    ctx->r14 = MEM_H(ctx->r4, 0XA);
    // 0x80800004: lh          $v0, 0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2);
    // 0x80800008: addu        $v1, $t6, $a1
    ctx->r3 = ADD32(ctx->r14, ctx->r5);
    // 0x8080000C: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800010: bne         $at, $zero, L_80800024
    if (ctx->r1 != 0) {
        // 0x80800014: nop
    
            goto L_80800024;
    }
    // 0x80800014: nop

    // 0x80800018: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x8080001C: jr          $ra
    // 0x80800020: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80800020: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80800024:
    // 0x80800024: bgez        $v1, L_80800030
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80800028: nop
    
            goto L_80800030;
    }
    // 0x80800028: nop

    // 0x8080002C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
L_80800030:
    // 0x80800030: jr          $ra
    // 0x80800034: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80800034: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_800C6038(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6038: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C603C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C6040: lui         $a1, 0xC694
    ctx->r5 = S32(0XC694 << 16);
    // 0x800C6044: ori         $a1, $a1, 0x7000
    ctx->r5 = ctx->r5 | 0X7000;
    // 0x800C6048: jal         0x800C5FCC
    // 0x800C604C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800C5FCC(rdram, ctx);
        goto after_0;
    // 0x800C604C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800C6050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C6054: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C6058: jr          $ra
    // 0x800C605C: nop

    return;
    // 0x800C605C: nop

;}
RECOMP_FUNC void _gcnewoption_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087CA0: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087CA0);
    return;
    // 0x80087CA4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800000_chstonedartgunhead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800004: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800008: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080000C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800010: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80800014: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80800018: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8080001C: jal         0x800882E0
    // 0x80800020: addiu       $a1, $zero, 0x122
    ctx->r5 = ADD32(0, 0X122);
    _gccubesearch_entrypoint_13(rdram, ctx);
        goto after_0;
    // 0x80800020: addiu       $a1, $zero, 0x122
    ctx->r5 = ADD32(0, 0X122);
    after_0:
    // 0x80800024: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800028: jal         0x800EFB8C
    // 0x8080002C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800EFB8C(rdram, ctx);
        goto after_1;
    // 0x8080002C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x80800030: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x80800034: addiu       $a0, $zero, 0x122
    ctx->r4 = ADD32(0, 0X122);
    // 0x80800038: jal         0x80088280
    // 0x8080003C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    _gccubesearch_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x8080003C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x80800040: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800044: jal         0x80088C08
    // 0x80800048: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _gspropctrl_entrypoint_12(rdram, ctx);
        goto after_3;
    // 0x80800048: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x8080004C: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80800050: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800054: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800058: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080005C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80800060: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    // 0x80800064: jal         0x80088C10
    // 0x80800068: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    _gspropctrl_entrypoint_13(rdram, ctx);
        goto after_4;
    // 0x80800068: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_4:
    // 0x8080006C: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x80800070: lbu         $t7, 0x64($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X64);
    // 0x80800074: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80800078: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8080007C: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80800080: sb          $t8, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r24;
    // 0x80800084: swc1        $f18, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f18.u32l;
    // 0x80800088: lbu         $t0, 0x2A($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X2A);
    // 0x8080008C: ori         $t1, $t0, 0x20
    ctx->r9 = ctx->r8 | 0X20;
    // 0x80800090: sb          $t1, 0x2A($v1)
    MEM_B(0X2A, ctx->r3) = ctx->r9;
    // 0x80800094: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800098: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080009C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808000A0: jr          $ra
    // 0x808000A4: nop

    return;
    // 0x808000A4: nop

;}
RECOMP_FUNC void func_8008ED80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008ED80: jr          $ra
    // 0x8008ED84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8008ED84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void _chfiregen_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800869A8: syscall     404
    recomp_syscall_handler(rdram, ctx, 0x800869A8);
    return;
    // 0x800869AC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800098_gctransitionDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800098: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080009C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808000A4: jal         0x800A8AF0
    // 0x808000A8: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_800A8AF0(rdram, ctx);
        goto after_0;
    // 0x808000A8: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x808000AC: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x808000B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808000B4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x808000B8: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808000BC: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x808000C0: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x808000C4: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x808000C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000D0: jr          $ra
    // 0x808000D4: nop

    return;
    // 0x808000D4: nop

;}
RECOMP_FUNC void func_80800360_chstatuebossbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800360: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800364: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800368: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080036C: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800370: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800374: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800378: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x8080037C: beq         $t6, $at, L_808003F8
    if (ctx->r14 == ctx->r1) {
        // 0x80800380: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808003F8;
    }
    // 0x80800380: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800384: beq         $t6, $at, L_808003F8
    if (ctx->r14 == ctx->r1) {
        // 0x80800388: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808003F8;
    }
    // 0x80800388: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080038C: bnel        $t6, $at, L_808003FC
    if (ctx->r14 != ctx->r1) {
        // 0x80800390: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808003FC;
    }
    goto skip_0;
    // 0x80800390: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800394: jal         0x800D9078
    // 0x80800398: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x80800398: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_0:
    // 0x8080039C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808003A0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808003A4: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808003A8: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    // 0x808003AC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x808003B0: jal         0x800F12D4
    // 0x808003B4: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F12D4(rdram, ctx);
        goto after_1;
    // 0x808003B4: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x808003B8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808003BC: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808003C0: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    // 0x808003C4: jal         0x800EFE50
    // 0x808003C8: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    func_800EFE50(rdram, ctx);
        goto after_2;
    // 0x808003C8: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    after_2:
    // 0x808003CC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003D4: beql        $t7, $zero, L_808003FC
    if (ctx->r15 == 0) {
        // 0x808003D8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808003FC;
    }
    goto skip_1;
    // 0x808003D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x808003DC: jal         0x80101FDC
    // 0x808003E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x808003E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003E8: jal         0x80103110
    // 0x808003EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_4;
    // 0x808003EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808003F0: jal         0x8010A590
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_5;
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_808003F8:
    // 0x808003F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808003FC:
    // 0x808003FC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800400: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800404: jr          $ra
    // 0x80800408: nop

    return;
    // 0x80800408: nop

;}
RECOMP_FUNC void func_80800068_chlighthalo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800068: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8080006C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800070: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800074: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800078: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8080007C: jal         0x800A89F8
    // 0x80800080: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    func_800A89F8(rdram, ctx);
        goto after_0;
    // 0x80800080: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    after_0:
    // 0x80800084: lbu         $a0, 0x34($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X34);
    // 0x80800088: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8080008C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800090: jal         0x800E8918
    // 0x80800094: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    func_800E8918(rdram, ctx);
        goto after_1;
    // 0x80800094: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    after_1:
    // 0x80800098: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8080009C: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x808000A0: beq         $v0, $at, L_808000C0
    if (ctx->r2 == ctx->r1) {
        // 0x808000A4: sw          $v0, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r2;
            goto L_808000C0;
    }
    // 0x808000A4: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x808000A8: beq         $v0, $zero, L_80800334
    if (ctx->r2 == 0) {
        // 0x808000AC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80800334;
    }
    // 0x808000AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000B0: beql        $v0, $at, L_80800384
    if (ctx->r2 == ctx->r1) {
        // 0x808000B4: addiu       $v1, $zero, 0xFF
        ctx->r3 = ADD32(0, 0XFF);
            goto L_80800384;
    }
    goto skip_0;
    // 0x808000B4: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    skip_0:
    // 0x808000B8: b           L_80800388
    // 0x808000BC: lbu         $v0, 0x9B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X9B);
        goto L_80800388;
    // 0x808000BC: lbu         $v0, 0x9B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X9B);
L_808000C0:
    // 0x808000C0: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x808000C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808000C8: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x808000CC: bgezl       $t8, L_80800338
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808000D0: lbu         $v0, 0x9B($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X9B);
            goto L_80800338;
    }
    goto skip_1;
    // 0x808000D0: lbu         $v0, 0x9B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X9B);
    skip_1:
    // 0x808000D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808000D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808000DC: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x808000E0: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x808000E4: lwc1        $f2, 0x38($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808000E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808000EC: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x808000F0: lui         $at, 0x4398
    ctx->r1 = S32(0X4398 << 16);
    // 0x808000F4: mul.s       $f16, $f2, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x808000F8: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x808000FC: nop

    // 0x80800100: bc1tl       L_80800134
    if (c1cs) {
        // 0x80800104: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_80800134;
    }
    goto skip_2;
    // 0x80800104: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    skip_2:
    // 0x80800108: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080010C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800110: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800114: nop

    // 0x80800118: mul.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8080011C: add.s       $f0, $f14, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f14.fl + ctx->f4.fl;
    // 0x80800120: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80800124: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80800128: nop

    // 0x8080012C: bc1f        L_80800140
    if (!c1cs) {
        // 0x80800130: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_80800140;
    }
    // 0x80800130: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
L_80800134:
    // 0x80800134: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800138: b           L_808001F8
    // 0x8080013C: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
        goto L_808001F8;
    // 0x8080013C: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
L_80800140:
    // 0x80800140: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800144: nop

    // 0x80800148: c.le.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl <= ctx->f10.fl;
    // 0x8080014C: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80800150: bc1fl       L_808001A8
    if (!c1cs) {
        // 0x80800154: c.le.s      $f14, $f10
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl <= ctx->f10.fl;
            goto L_808001A8;
    }
    goto skip_3;
    // 0x80800154: c.le.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl <= ctx->f10.fl;
    skip_3:
    // 0x80800158: c.le.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl <= ctx->f4.fl;
    // 0x8080015C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800160: bc1fl       L_808001A8
    if (!c1cs) {
        // 0x80800164: c.le.s      $f14, $f10
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl <= ctx->f10.fl;
            goto L_808001A8;
    }
    goto skip_4;
    // 0x80800164: c.le.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl <= ctx->f10.fl;
    skip_4:
    // 0x80800168: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8080016C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800170: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80800174: mov.s       $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = ctx->f4.fl;
    // 0x80800178: swc1        $f18, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f18.u32l;
    // 0x8080017C: jal         0x800F10B4
    // 0x80800180: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x80800180: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x80800184: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x80800188: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x8080018C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800190: lwc1        $f2, 0x38($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800194: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800198: mul.s       $f16, $f2, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8080019C: b           L_808001FC
    // 0x808001A0: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
        goto L_808001FC;
    // 0x808001A0: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x808001A4: c.le.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl <= ctx->f10.fl;
L_808001A8:
    // 0x808001A8: nop

    // 0x808001AC: bc1fl       L_808001FC
    if (!c1cs) {
        // 0x808001B0: lwc1        $f6, 0x5C($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
            goto L_808001FC;
    }
    goto skip_5;
    // 0x808001B0: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    skip_5:
    // 0x808001B4: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x808001B8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x808001BC: bc1fl       L_808001FC
    if (!c1cs) {
        // 0x808001C0: lwc1        $f6, 0x5C($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
            goto L_808001FC;
    }
    goto skip_6;
    // 0x808001C0: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    skip_6:
    // 0x808001C4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808001C8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808001CC: mov.s       $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = ctx->f10.fl;
    // 0x808001D0: swc1        $f18, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f18.u32l;
    // 0x808001D4: jal         0x800F10B4
    // 0x808001D8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x808001D8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x808001DC: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x808001E0: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x808001E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808001E8: lwc1        $f2, 0x38($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808001EC: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x808001F0: mul.s       $f16, $f2, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x808001F4: nop

L_808001F8:
    // 0x808001F8: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
L_808001FC:
    // 0x808001FC: lui         $at, 0x4364
    ctx->r1 = S32(0X4364 << 16);
    // 0x80800200: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    // 0x80800204: nop

    // 0x80800208: bc1tl       L_8080023C
    if (c1cs) {
        // 0x8080020C: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_8080023C;
    }
    goto skip_7;
    // 0x8080020C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    skip_7:
    // 0x80800210: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800214: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800218: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080021C: nop

    // 0x80800220: mul.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80800224: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80800228: add.s       $f0, $f14, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f14.fl + ctx->f4.fl;
    // 0x8080022C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80800230: nop

    // 0x80800234: bc1f        L_80800248
    if (!c1cs) {
        // 0x80800238: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_80800248;
    }
    // 0x80800238: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
L_8080023C:
    // 0x8080023C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800240: b           L_808002CC
    // 0x80800244: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
        goto L_808002CC;
    // 0x80800244: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
L_80800248:
    // 0x80800248: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8080024C: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80800250: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80800254: nop

    // 0x80800258: bc1fl       L_80800294
    if (!c1cs) {
        // 0x8080025C: c.le.s      $f14, $f6
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl <= ctx->f6.fl;
            goto L_80800294;
    }
    goto skip_8;
    // 0x8080025C: c.le.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl <= ctx->f6.fl;
    skip_8:
    // 0x80800260: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x80800264: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800268: bc1fl       L_80800294
    if (!c1cs) {
        // 0x8080026C: c.le.s      $f14, $f6
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl <= ctx->f6.fl;
            goto L_80800294;
    }
    goto skip_9;
    // 0x8080026C: c.le.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl <= ctx->f6.fl;
    skip_9:
    // 0x80800270: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800274: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800278: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8080027C: mov.s       $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = ctx->f10.fl;
    // 0x80800280: jal         0x800F10B4
    // 0x80800284: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x80800284: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x80800288: b           L_808002C8
    // 0x8080028C: mov.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
        goto L_808002C8;
    // 0x8080028C: mov.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
    // 0x80800290: c.le.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl <= ctx->f6.fl;
L_80800294:
    // 0x80800294: nop

    // 0x80800298: bc1fl       L_808002CC
    if (!c1cs) {
        // 0x8080029C: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_808002CC;
    }
    goto skip_10;
    // 0x8080029C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    skip_10:
    // 0x808002A0: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x808002A4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x808002A8: bc1fl       L_808002CC
    if (!c1cs) {
        // 0x808002AC: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_808002CC;
    }
    goto skip_11;
    // 0x808002AC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    skip_11:
    // 0x808002B0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808002B4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808002B8: mov.s       $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = ctx->f6.fl;
    // 0x808002BC: jal         0x800F10B4
    // 0x808002C0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_5;
    // 0x808002C0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x808002C4: mov.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
L_808002C8:
    // 0x808002C8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
L_808002CC:
    // 0x808002CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808002D0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x808002D4: c.eq.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl == ctx->f10.fl;
    // 0x808002D8: nop

    // 0x808002DC: bc1tl       L_80800338
    if (c1cs) {
        // 0x808002E0: lbu         $v0, 0x9B($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X9B);
            goto L_80800338;
    }
    goto skip_12;
    // 0x808002E0: lbu         $v0, 0x9B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X9B);
    skip_12:
    // 0x808002E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808002E8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808002EC: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x808002F0: c.eq.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl == ctx->f4.fl;
    // 0x808002F4: nop

    // 0x808002F8: bc1tl       L_80800338
    if (c1cs) {
        // 0x808002FC: lbu         $v0, 0x9B($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X9B);
            goto L_80800338;
    }
    goto skip_13;
    // 0x808002FC: lbu         $v0, 0x9B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X9B);
    skip_13:
    // 0x80800300: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80800304: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800308: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8080030C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800310: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800314: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80800318: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x8080031C: lbu         $v0, 0x9B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X9B);
    // 0x80800320: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800324: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800328: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x8080032C: b           L_8080038C
    // 0x80800330: addu        $t3, $v0, $v1
    ctx->r11 = ADD32(ctx->r2, ctx->r3);
        goto L_8080038C;
    // 0x80800330: addu        $t3, $v0, $v1
    ctx->r11 = ADD32(ctx->r2, ctx->r3);
L_80800334:
    // 0x80800334: lbu         $v0, 0x9B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X9B);
L_80800338:
    // 0x80800338: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8080033C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80800340: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80800344: bgez        $v0, L_80800358
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80800348: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80800358;
    }
    // 0x80800348: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080034C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800350: nop

    // 0x80800354: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80800358:
    // 0x80800358: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2432, 0X650) << 16);
    // 0x8080035C: lwc1        $f10, 0x650($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2432, 0X650));
    // 0x80800360: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80800364: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800368: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x8080036C: nop

    // 0x80800370: beql        $v1, $zero, L_8080038C
    if (ctx->r3 == 0) {
        // 0x80800374: addu        $t3, $v0, $v1
        ctx->r11 = ADD32(ctx->r2, ctx->r3);
            goto L_8080038C;
    }
    goto skip_14;
    // 0x80800374: addu        $t3, $v0, $v1
    ctx->r11 = ADD32(ctx->r2, ctx->r3);
    skip_14:
    // 0x80800378: b           L_80800388
    // 0x8080037C: sw          $t2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r10;
        goto L_80800388;
    // 0x8080037C: sw          $t2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r10;
    // 0x80800380: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_80800384:
    // 0x80800384: lbu         $v0, 0x9B($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X9B);
L_80800388:
    // 0x80800388: addu        $t3, $v0, $v1
    ctx->r11 = ADD32(ctx->r2, ctx->r3);
L_8080038C:
    // 0x8080038C: sra         $t4, $t3, 1
    ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
    // 0x80800390: sb          $t4, 0x9B($s0)
    MEM_B(0X9B, ctx->r16) = ctx->r12;
    // 0x80800394: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x80800398: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080039C: bnel        $t5, $at, L_8080042C
    if (ctx->r13 != ctx->r1) {
        // 0x808003A0: lbu         $t2, 0x65($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0X65);
            goto L_8080042C;
    }
    goto skip_15;
    // 0x808003A0: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    skip_15:
    // 0x808003A4: jal         0x80089C00
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiedraw25d_entrypoint_0(rdram, ctx);
        goto after_6;
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808003AC: lwc1        $f2, 0x38($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808003B0: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x808003B4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x808003B8: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x808003BC: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x808003C0: jal         0x800EFA4C
    // 0x808003C4: nop

    func_800EFA4C(rdram, ctx);
        goto after_7;
    // 0x808003C4: nop

    after_7:
    // 0x808003C8: jal         0x800E2588
    // 0x808003CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800E2588(rdram, ctx);
        goto after_8;
    // 0x808003CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x808003D0: lbu         $a0, 0x98($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X98);
    // 0x808003D4: lbu         $a1, 0x99($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X99);
    // 0x808003D8: jal         0x800E24F8
    // 0x808003DC: lbu         $a2, 0x9A($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X9A);
    func_800E24F8(rdram, ctx);
        goto after_9;
    // 0x808003DC: lbu         $a2, 0x9A($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X9A);
    after_9:
    // 0x808003E0: jal         0x800E257C
    // 0x808003E4: lbu         $a0, 0x9B($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X9B);
    func_800E257C(rdram, ctx);
        goto after_10;
    // 0x808003E4: lbu         $a0, 0x9B($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X9B);
    after_10:
    // 0x808003E8: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x808003EC: jal         0x800D674C
    // 0x808003F0: lhu         $a0, 0x14($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X14);
    func_800D674C(rdram, ctx);
        goto after_11;
    // 0x808003F0: lhu         $a0, 0x14($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X14);
    after_11:
    // 0x808003F4: addiu       $t7, $s0, 0x4
    ctx->r15 = ADD32(ctx->r16, 0X4);
    // 0x808003F8: addiu       $t8, $sp, 0x3C
    ctx->r24 = ADD32(ctx->r29, 0X3C);
    // 0x808003FC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80800400: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800404: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80800408: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8080040C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800410: jal         0x800E2AA4
    // 0x80800414: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800E2AA4(rdram, ctx);
        goto after_12;
    // 0x80800414: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_12:
    // 0x80800418: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x8080041C: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x80800420: b           L_80800434
    // 0x80800424: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
        goto L_80800434;
    // 0x80800424: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    // 0x80800428: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
L_8080042C:
    // 0x8080042C: andi        $t3, $t2, 0xFFEF
    ctx->r11 = ctx->r10 & 0XFFEF;
    // 0x80800430: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
L_80800434:
    // 0x80800434: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800438: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080043C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80800440: jr          $ra
    // 0x80800444: nop

    return;
    // 0x80800444: nop

;}
RECOMP_FUNC void chstarspinnerctrl_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800604: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800608: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080060C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800610: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800614: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800618: jal         0x800DA298
    // 0x8080061C: addiu       $a0, $zero, 0xEA
    ctx->r4 = ADD32(0, 0XEA);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x8080061C: addiu       $a0, $zero, 0xEA
    ctx->r4 = ADD32(0, 0XEA);
    after_0:
    // 0x80800620: bne         $v0, $zero, L_80800640
    if (ctx->r2 != 0) {
        // 0x80800624: nop
    
            goto L_80800640;
    }
    // 0x80800624: nop

    // 0x80800628: jal         0x80088848
    // 0x8080062C: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x8080062C: nop

    after_1:
    // 0x80800630: bne         $v0, $zero, L_80800640
    if (ctx->r2 != 0) {
        // 0x80800634: nop
    
            goto L_80800640;
    }
    // 0x80800634: nop

    // 0x80800638: b           L_80800688
    // 0x8080063C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800688;
    // 0x8080063C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800640:
    // 0x80800640: jal         0x800C8A98
    // 0x80800644: nop

    func_800C8A98(rdram, ctx);
        goto after_2;
    // 0x80800644: nop

    after_2:
    // 0x80800648: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(960, 0X8E0) << 16);
    // 0x8080064C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800650: addiu       $a1, $a1, 0x8E0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(960, 0X8E0));
    // 0x80800654: jal         0x800C8D4C
    // 0x80800658: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800C8D4C(rdram, ctx);
        goto after_3;
    // 0x80800658: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x8080065C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(960, 0X8F4) << 16);
    // 0x80800660: addiu       $a1, $a1, 0x8F4
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(960, 0X8F4));
    // 0x80800664: jal         0x800C8E84
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C8E84(rdram, ctx);
        goto after_4;
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080066C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800670: jal         0x800C8CB8
    // 0x80800674: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800C8CB8(rdram, ctx);
        goto after_5;
    // 0x80800674: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x80800678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080067C: jal         0x800C8F64
    // 0x80800680: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_800C8F64(rdram, ctx);
        goto after_6;
    // 0x80800680: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_6:
    // 0x80800684: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80800688:
    // 0x80800688: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080068C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800690: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800694: jr          $ra
    // 0x80800698: nop

    return;
    // 0x80800698: nop

;}
RECOMP_FUNC void func_800CA8B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA8B4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800CA8B8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800CA8BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CA8C0: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800CA8C4: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
L_800CA8C8:
    // 0x800CA8C8: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800CA8CC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800CA8D0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800CA8D4: swc1        $f4, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
    // 0x800CA8D8: lwc1        $f6, 0x18($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X18);
    // 0x800CA8DC: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800CA8E0: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x800CA8E4: bne         $v0, $a0, L_800CA8C8
    if (ctx->r2 != ctx->r4) {
        // 0x800CA8E8: swc1        $f6, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->f6.u32l;
            goto L_800CA8C8;
    }
    // 0x800CA8E8: swc1        $f6, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->f6.u32l;
    // 0x800CA8EC: jr          $ra
    // 0x800CA8F0: nop

    return;
    // 0x800CA8F0: nop

;}
RECOMP_FUNC void func_8002D030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D030: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002D034: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002D038: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8002D03C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8002D040: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8002D044: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8002D048: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8002D04C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8002D050: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8002D054: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8002D058: jal         0x8002D450
    // 0x8002D05C: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    func_8002D450(rdram, ctx);
        goto after_0;
    // 0x8002D05C: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    after_0:
    // 0x8002D060: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8002D064: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8002D068: lbu         $t8, 0x8C($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X8C);
    // 0x8002D06C: beq         $t8, $zero, L_8002D218
    if (ctx->r24 == 0) {
        // 0x8002D070: nop
    
            goto L_8002D218;
    }
    // 0x8002D070: nop

    // 0x8002D074: slti        $at, $t8, 0x40
    ctx->r1 = SIGNED(ctx->r24) < 0X40 ? 1 : 0;
    // 0x8002D078: beq         $at, $zero, L_8002D218
    if (ctx->r1 == 0) {
        // 0x8002D07C: nop
    
            goto L_8002D218;
    }
    // 0x8002D07C: nop

    // 0x8002D080: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8002D084: lbu         $t0, 0x8C($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X8C);
    // 0x8002D088: slti        $at, $t0, 0x6
    ctx->r1 = SIGNED(ctx->r8) < 0X6 ? 1 : 0;
    // 0x8002D08C: bne         $at, $zero, L_8002D0DC
    if (ctx->r1 != 0) {
        // 0x8002D090: nop
    
            goto L_8002D0DC;
    }
    // 0x8002D090: nop

    // 0x8002D094: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8002D098: lbu         $t2, 0x8C($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X8C);
    // 0x8002D09C: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8002D0A0: bgez        $t2, L_8002D0B8
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8002D0A4: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8002D0B8;
    }
    // 0x8002D0A4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002D0A8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8002D0AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002D0B0: nop

    // 0x8002D0B4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8002D0B8:
    // 0x8002D0B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002D0BC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002D0C0: jal         0x8002DCA0
    // 0x8002D0C4: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8002D0C4: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    after_1:
    // 0x8002D0C8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8002D0CC: lwc1        $f16, 0x1DA0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X1DA0);
    // 0x8002D0D0: div.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8002D0D4: b           L_8002D11C
    // 0x8002D0D8: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
        goto L_8002D11C;
    // 0x8002D0D8: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
L_8002D0DC:
    // 0x8002D0DC: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8002D0E0: lbu         $t4, 0x8C($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X8C);
    // 0x8002D0E4: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8002D0E8: bgez        $t4, L_8002D100
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8002D0EC: cvt.s.w     $f8, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8002D100;
    }
    // 0x8002D0EC: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002D0F0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8002D0F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002D0F8: nop

    // 0x8002D0FC: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_8002D100:
    // 0x8002D100: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002D104: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002D108: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x8002D10C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8002D110: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8002D114: div.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8002D118: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
L_8002D11C:
    // 0x8002D11C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8002D120: lwc1        $f8, 0x1DA4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1DA4);
    // 0x8002D124: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8002D128: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8002D12C: nop

    // 0x8002D130: bc1f        L_8002D144
    if (!c1cs) {
        // 0x8002D134: nop
    
            goto L_8002D144;
    }
    // 0x8002D134: nop

    // 0x8002D138: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8002D13C: lwc1        $f10, 0x1DA8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X1DA8);
    // 0x8002D140: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
L_8002D144:
    // 0x8002D144: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x8002D148: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8002D14C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8002D150: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x8002D154: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8002D158: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8002D15C: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x8002D160: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x8002D164: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8002D168: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8002D16C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8002D170: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8002D174: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8002D178: cvt.w.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8002D17C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8002D180: nop

    // 0x8002D184: andi        $at, $t2, 0x4
    ctx->r1 = ctx->r10 & 0X4;
    // 0x8002D188: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x8002D18C: beq         $t2, $zero, L_8002D1E0
    if (ctx->r10 == 0) {
        // 0x8002D190: nop
    
            goto L_8002D1E0;
    }
    // 0x8002D190: nop

    // 0x8002D194: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8002D198: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8002D19C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8002D1A0: sub.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x8002D1A4: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8002D1A8: nop

    // 0x8002D1AC: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8002D1B0: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8002D1B4: nop

    // 0x8002D1B8: andi        $at, $t2, 0x4
    ctx->r1 = ctx->r10 & 0X4;
    // 0x8002D1BC: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x8002D1C0: bne         $t2, $zero, L_8002D1D8
    if (ctx->r10 != 0) {
        // 0x8002D1C4: nop
    
            goto L_8002D1D8;
    }
    // 0x8002D1C4: nop

    // 0x8002D1C8: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
    // 0x8002D1CC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8002D1D0: b           L_8002D1F0
    // 0x8002D1D4: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_8002D1F0;
    // 0x8002D1D4: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_8002D1D8:
    // 0x8002D1D8: b           L_8002D1F0
    // 0x8002D1DC: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_8002D1F0;
    // 0x8002D1DC: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
L_8002D1E0:
    // 0x8002D1E0: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
    // 0x8002D1E4: nop

    // 0x8002D1E8: bltz        $t2, L_8002D1D8
    if (SIGNED(ctx->r10) < 0) {
        // 0x8002D1EC: nop
    
            goto L_8002D1D8;
    }
    // 0x8002D1EC: nop

L_8002D1F0:
    // 0x8002D1F0: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8002D1F4: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8002D1F8: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x8002D1FC: lbu         $t6, 0x8C($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X8C);
    // 0x8002D200: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x8002D204: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8002D208: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8002D20C: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8002D210: or          $t9, $t4, $t8
    ctx->r25 = ctx->r12 | ctx->r24;
    // 0x8002D214: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
L_8002D218:
    // 0x8002D218: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8002D21C: lh          $t2, 0x92($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X92);
    // 0x8002D220: blez        $t2, L_8002D308
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8002D224: nop
    
            goto L_8002D308;
    }
    // 0x8002D224: nop

    // 0x8002D228: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8002D22C: lw          $t5, 0xB8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0XB8);
    // 0x8002D230: beq         $t5, $zero, L_8002D24C
    if (ctx->r13 == 0) {
        // 0x8002D234: nop
    
            goto L_8002D24C;
    }
    // 0x8002D234: nop

    // 0x8002D238: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8002D23C: lui         $a1, 0x46AC
    ctx->r5 = S32(0X46AC << 16);
    // 0x8002D240: ori         $a1, $a1, 0x4400
    ctx->r5 = ctx->r5 | 0X4400;
    // 0x8002D244: jal         0x80028C04
    // 0x8002D248: addiu       $a0, $a0, 0x90
    ctx->r4 = ADD32(ctx->r4, 0X90);
    func_80028C04(rdram, ctx);
        goto after_2;
    // 0x8002D248: addiu       $a0, $a0, 0x90
    ctx->r4 = ADD32(ctx->r4, 0X90);
    after_2:
L_8002D24C:
    // 0x8002D24C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8002D250: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8002D254: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8002D258: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8002D25C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8002D260: lui         $t4, 0xB00
    ctx->r12 = S32(0XB00 << 16);
    // 0x8002D264: ori         $t4, $t4, 0x20
    ctx->r12 = ctx->r12 | 0X20;
    // 0x8002D268: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
    // 0x8002D26C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8002D270: jal         0x8002E330
    // 0x8002D274: addiu       $a0, $a0, 0x98
    ctx->r4 = ADD32(ctx->r4, 0X98);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_3;
    // 0x8002D274: addiu       $a0, $a0, 0x98
    ctx->r4 = ADD32(ctx->r4, 0X98);
    after_3:
    // 0x8002D278: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8002D27C: sw          $v0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r2;
    // 0x8002D280: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8002D284: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8002D288: lw          $t1, 0xB8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XB8);
    // 0x8002D28C: bne         $t1, $at, L_8002D29C
    if (ctx->r9 != ctx->r1) {
        // 0x8002D290: nop
    
            goto L_8002D29C;
    }
    // 0x8002D290: nop

    // 0x8002D294: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8002D298: sw          $zero, 0xB8($t2)
    MEM_W(0XB8, ctx->r10) = 0;
L_8002D29C:
    // 0x8002D29C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8002D2A0: addiu       $t5, $t3, 0x8
    ctx->r13 = ADD32(ctx->r11, 0X8);
    // 0x8002D2A4: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x8002D2A8: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x8002D2AC: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8002D2B0: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8002D2B4: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8002D2B8: lw          $t9, 0xB8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XB8);
    // 0x8002D2BC: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x8002D2C0: lui         $at, 0xE00
    ctx->r1 = S32(0XE00 << 16);
    // 0x8002D2C4: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x8002D2C8: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x8002D2CC: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x8002D2D0: andi        $t4, $t7, 0xFFFF
    ctx->r12 = ctx->r15 & 0XFFFF;
    // 0x8002D2D4: or          $t3, $t4, $t2
    ctx->r11 = ctx->r12 | ctx->r10;
    // 0x8002D2D8: sw          $t3, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r11;
    // 0x8002D2DC: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8002D2E0: jal         0x8002E330
    // 0x8002D2E4: lw          $a0, 0xBC($t6)
    ctx->r4 = MEM_W(ctx->r14, 0XBC);
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_4;
    // 0x8002D2E4: lw          $a0, 0xBC($t6)
    ctx->r4 = MEM_W(ctx->r14, 0XBC);
    after_4:
    // 0x8002D2E8: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8002D2EC: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8002D2F0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8002D2F4: and         $t7, $v0, $at
    ctx->r15 = ctx->r2 & ctx->r1;
    // 0x8002D2F8: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x8002D2FC: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8002D300: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8002D304: sw          $zero, 0xB8($t0)
    MEM_W(0XB8, ctx->r8) = 0;
L_8002D308:
    // 0x8002D308: b           L_8002D318
    // 0x8002D30C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
        goto L_8002D318;
    // 0x8002D30C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8002D310: b           L_8002D318
    // 0x8002D314: nop

        goto L_8002D318;
    // 0x8002D314: nop

L_8002D318:
    // 0x8002D318: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002D31C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8002D320: jr          $ra
    // 0x8002D324: nop

    return;
    // 0x8002D324: nop

;}
RECOMP_FUNC void func_80013430(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013430: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80013434: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80013438: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x8001343C: jal         0x8002E900
    // 0x80013440: addiu       $a0, $a0, 0x6A20
    ctx->r4 = ADD32(ctx->r4, 0X6A20);
    osStopThread_recomp(rdram, ctx);
        goto after_0;
    // 0x80013440: addiu       $a0, $a0, 0x6A20
    ctx->r4 = ADD32(ctx->r4, 0X6A20);
    after_0:
    // 0x80013444: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x80013448: jal         0x8002E9C0
    // 0x8001344C: addiu       $a0, $a0, 0x6A20
    ctx->r4 = ADD32(ctx->r4, 0X6A20);
    osDestroyThread_recomp(rdram, ctx);
        goto after_1;
    // 0x8001344C: addiu       $a0, $a0, 0x6A20
    ctx->r4 = ADD32(ctx->r4, 0X6A20);
    after_1:
    // 0x80013450: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80013454: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80013458: jr          $ra
    // 0x8001345C: nop

    return;
    // 0x8001345C: nop

;}
RECOMP_FUNC void _plsu_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800878A8: syscall     638
    recomp_syscall_handler(rdram, ctx, 0x800878A8);
    return;
    // 0x800878AC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_8002AB30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AB30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002AB34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002AB38: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002AB3C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8002AB40: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8002AB44: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x8002AB48: beq         $t7, $zero, L_8002ABC8
    if (ctx->r15 == 0) {
        // 0x8002AB4C: nop
    
            goto L_8002ABC8;
    }
    // 0x8002AB4C: nop

    // 0x8002AB50: jal         0x80021794
    // 0x8002AB54: nop

    func_80021794(rdram, ctx);
        goto after_0;
    // 0x8002AB54: nop

    after_0:
    // 0x8002AB58: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8002AB5C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8002AB60: bne         $t8, $zero, L_8002AB70
    if (ctx->r24 != 0) {
        // 0x8002AB64: nop
    
            goto L_8002AB70;
    }
    // 0x8002AB64: nop

    // 0x8002AB68: b           L_8002ABD0
    // 0x8002AB6C: nop

        goto L_8002ABD0;
    // 0x8002AB6C: nop

L_8002AB70:
    // 0x8002AB70: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8002AB74: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x8002AB78: lw          $t9, 0x11F4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X11F4);
    // 0x8002AB7C: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x8002AB80: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8002AB84: lw          $t0, 0x1C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1C);
    // 0x8002AB88: lw          $t3, 0x88($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X88);
    // 0x8002AB8C: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x8002AB90: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x8002AB94: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8002AB98: addiu       $t6, $zero, 0x11
    ctx->r14 = ADD32(0, 0X11);
    // 0x8002AB9C: sh          $t6, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r14;
    // 0x8002ABA0: lbu         $t8, 0x27($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X27);
    // 0x8002ABA4: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8002ABA8: sw          $t8, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r24;
    // 0x8002ABAC: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8002ABB0: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8002ABB4: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8002ABB8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8002ABBC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8002ABC0: jal         0x8002B684
    // 0x8002ABC4: lw          $a0, 0x8($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X8);
    func_8002B684(rdram, ctx);
        goto after_1;
    // 0x8002ABC4: lw          $a0, 0x8($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X8);
    after_1:
L_8002ABC8:
    // 0x8002ABC8: b           L_8002ABD0
    // 0x8002ABCC: nop

        goto L_8002ABD0;
    // 0x8002ABCC: nop

L_8002ABD0:
    // 0x8002ABD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002ABD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002ABD8: jr          $ra
    // 0x8002ABDC: nop

    return;
    // 0x8002ABDC: nop

;}
RECOMP_FUNC void func_800A3B78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3B78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A3B7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A3B80: jal         0x800A4CA8
    // 0x800A3B84: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800A4CA8(rdram, ctx);
        goto after_0;
    // 0x800A3B84: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800A3B88: beq         $v0, $zero, L_800A3B98
    if (ctx->r2 == 0) {
        // 0x800A3B8C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800A3B98;
    }
    // 0x800A3B8C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A3B90: jal         0x801106A8
    // 0x800A3B94: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_801106A8(rdram, ctx);
        goto after_1;
    // 0x800A3B94: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
L_800A3B98:
    // 0x800A3B98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A3B9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A3BA0: jr          $ra
    // 0x800A3BA4: nop

    return;
    // 0x800A3BA4: nop

;}
RECOMP_FUNC void func_8010CE70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010CE70: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x8010CE74: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8010CE78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010CE7C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8010CE80: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010CE84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010CE88: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x8010CE8C: addiu       $a3, $a3, 0x6F50
    ctx->r7 = ADD32(ctx->r7, 0X6F50);
    // 0x8010CE90: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8010CE94: jal         0x80102844
    // 0x8010CE98: nop

    func_80102844(rdram, ctx);
        goto after_0;
    // 0x8010CE98: nop

    after_0:
    // 0x8010CE9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010CEA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010CEA4: jr          $ra
    // 0x8010CEA8: nop

    return;
    // 0x8010CEA8: nop

;}
RECOMP_FUNC void _bsbwhirl_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082DE8: syscall     30
    recomp_syscall_handler(rdram, ctx, 0x80082DE8);
    return;
    // 0x80082DEC: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void func_80800200_chcactusofstrength(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800200: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800204: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800208: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080020C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800210: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800214: jal         0x800EE7F8
    // 0x80800218: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800218: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x8080021C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800220: lui         $a1, 0x4307
    ctx->r5 = S32(0X4307 << 16);
    // 0x80800224: jal         0x800EF1B8
    // 0x80800228: lui         $a2, 0xC25C
    ctx->r6 = S32(0XC25C << 16);
    func_800EF1B8(rdram, ctx);
        goto after_1;
    // 0x80800228: lui         $a2, 0xC25C
    ctx->r6 = S32(0XC25C << 16);
    after_1:
    // 0x8080022C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800230: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x80800234: lui         $a2, 0x4296
    ctx->r6 = S32(0X4296 << 16);
    // 0x80800238: jal         0x80089F18
    // 0x8080023C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    _sudeflect_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x8080023C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_2:
    // 0x80800240: jal         0x8080094C
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080094C_chcactusofstrength(rdram, ctx);
        goto after_3;
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800248: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x8080024C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800250: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800254: beq         $t6, $at, L_80800278
    if (ctx->r14 == ctx->r1) {
        // 0x80800258: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800278;
    }
    // 0x80800258: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080025C: beq         $t6, $at, L_80800288
    if (ctx->r14 == ctx->r1) {
        // 0x80800260: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800288;
    }
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800264: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800268: beq         $t6, $at, L_8080034C
    if (ctx->r14 == ctx->r1) {
        // 0x8080026C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080034C;
    }
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800270: b           L_808003DC
    // 0x80800274: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808003DC;
    // 0x80800274: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800278:
    // 0x80800278: jal         0x808006BC
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808006BC_chcactusofstrength(rdram, ctx);
        goto after_4;
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800280: b           L_808003DC
    // 0x80800284: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808003DC;
    // 0x80800284: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800288:
    // 0x80800288: jal         0x80800824
    // 0x8080028C: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    func_80800824_chcactusofstrength(rdram, ctx);
        goto after_5;
    // 0x8080028C: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    after_5:
    // 0x80800290: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800294: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800298: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x8080029C: nop

    // 0x808002A0: bc1fl       L_808002C4
    if (!c1cs) {
        // 0x808002A4: lwc1        $f0, 0x24($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
            goto L_808002C4;
    }
    goto skip_0;
    // 0x808002A4: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    skip_0:
    // 0x808002A8: jal         0x800D9078
    // 0x808002AC: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_6;
    // 0x808002AC: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_6:
    // 0x808002B0: beql        $v0, $zero, L_808003DC
    if (ctx->r2 == 0) {
        // 0x808002B4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808003DC;
    }
    goto skip_1;
    // 0x808002B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x808002B8: b           L_808003DC
    // 0x808002BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808003DC;
    // 0x808002BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002C0: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
L_808002C4:
    // 0x808002C4: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808002C8: lwc1        $f2, 0x2C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x808002CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002D0: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x808002D4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808002D8: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x808002DC: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808002E0: c.le.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl <= ctx->f10.fl;
    // 0x808002E4: nop

    // 0x808002E8: bc1fl       L_8080031C
    if (!c1cs) {
        // 0x808002EC: mtc1        $at, $f16
        ctx->f16.u32l = ctx->r1;
            goto L_8080031C;
    }
    goto skip_2;
    // 0x808002EC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    skip_2:
    // 0x808002F0: jal         0x80800718
    // 0x808002F4: swc1        $f2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f2.u32l;
    func_80800718_chcactusofstrength(rdram, ctx);
        goto after_7;
    // 0x808002F4: swc1        $f2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f2.u32l;
    after_7:
    // 0x808002F8: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x808002FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800300: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800304: andi        $t8, $t7, 0xFFFE
    ctx->r24 = ctx->r15 & 0XFFFE;
    // 0x80800308: jal         0x80101FDC
    // 0x8080030C: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    func_80101FDC(rdram, ctx);
        goto after_8;
    // 0x8080030C: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    after_8:
    // 0x80800310: b           L_808003DC
    // 0x80800314: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808003DC;
    // 0x80800314: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800318: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
L_8080031C:
    // 0x8080031C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800320: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80800324: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    // 0x80800328: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8080032C: c.le.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl <= ctx->f12.fl;
    // 0x80800330: nop

    // 0x80800334: bc1fl       L_808003DC
    if (!c1cs) {
        // 0x80800338: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808003DC;
    }
    goto skip_3;
    // 0x80800338: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8080033C: jal         0x80101FDC
    // 0x80800340: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_9;
    // 0x80800340: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80800344: b           L_808003DC
    // 0x80800348: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808003DC;
    // 0x80800348: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080034C:
    // 0x8080034C: jal         0x80800824
    // 0x80800350: lui         $a1, 0xC1A0
    ctx->r5 = S32(0XC1A0 << 16);
    func_80800824_chcactusofstrength(rdram, ctx);
        goto after_10;
    // 0x80800350: lui         $a1, 0xC1A0
    ctx->r5 = S32(0XC1A0 << 16);
    after_10:
    // 0x80800354: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800358: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8080035C: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800360: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800364: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80800368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080036C: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80800370: bc1f        L_80800388
    if (!c1cs) {
        // 0x80800374: swc1        $f8, 0x8($s0)
        MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
            goto L_80800388;
    }
    // 0x80800374: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x80800378: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8080037C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800380: b           L_80800394
    // 0x80800384: sub.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f2.fl;
        goto L_80800394;
    // 0x80800384: sub.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f2.fl;
L_80800388:
    // 0x80800388: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8080038C: nop

    // 0x80800390: sub.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f2.fl;
L_80800394:
    // 0x80800394: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x80800398: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080039C: swc1        $f16, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f16.u32l;
    // 0x808003A0: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808003A4: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x808003A8: nop

    // 0x808003AC: bc1fl       L_808003BC
    if (!c1cs) {
        // 0x808003B0: lwc1        $f0, 0x28($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X28);
            goto L_808003BC;
    }
    goto skip_4;
    // 0x808003B0: lwc1        $f0, 0x28($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X28);
    skip_4:
    // 0x808003B4: swc1        $f12, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f12.u32l;
    // 0x808003B8: lwc1        $f0, 0x28($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X28);
L_808003BC:
    // 0x808003BC: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808003C0: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x808003C4: nop

    // 0x808003C8: bc1fl       L_808003DC
    if (!c1cs) {
        // 0x808003CC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808003DC;
    }
    goto skip_5;
    // 0x808003CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x808003D0: jal         0x80800780
    // 0x808003D4: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    func_80800780_chcactusofstrength(rdram, ctx);
        goto after_11;
    // 0x808003D4: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    after_11:
    // 0x808003D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808003DC:
    // 0x808003DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003E0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808003E4: jr          $ra
    // 0x808003E8: nop

    return;
    // 0x808003E8: nop

;}
RECOMP_FUNC void _bsbeefly_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082868: syscall     16
    recomp_syscall_handler(rdram, ctx, 0x80082868);
    return;
    // 0x8008286C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void dbpalette_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800048: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8080004C: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x80800050: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80800054: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80800058: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8080005C: lw          $t9, 0x4($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X4);
    // 0x80800060: sll         $t0, $t9, 8
    ctx->r8 = S32(ctx->r25 << 8);
    // 0x80800064: or          $t1, $t7, $t0
    ctx->r9 = ctx->r15 | ctx->r8;
    // 0x80800068: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8080006C: lw          $t3, 0x8($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X8);
    // 0x80800070: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x80800074: or          $t5, $t1, $t4
    ctx->r13 = ctx->r9 | ctx->r12;
    // 0x80800078: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8080007C: lw          $t7, 0xC($a2)
    ctx->r15 = MEM_W(ctx->r6, 0XC);
    // 0x80800080: sll         $t9, $t7, 24
    ctx->r25 = S32(ctx->r15 << 24);
    // 0x80800084: or          $t8, $t5, $t9
    ctx->r24 = ctx->r13 | ctx->r25;
    // 0x80800088: jr          $ra
    // 0x8080008C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    return;
    // 0x8080008C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void func_800E3AA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E3AA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E3AA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E3AAC: jal         0x800E3A80
    // 0x800E3AB0: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    func_800E3A80(rdram, ctx);
        goto after_0;
    // 0x800E3AB0: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x800E3AB4: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800E3AB8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800E3ABC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800E3AC0: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800E3AC4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800E3AC8: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x800E3ACC: nop

    // 0x800E3AD0: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800E3AD4: nop

    // 0x800E3AD8: cvt.s.w     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800E3ADC: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x800E3AE0: nop

    // 0x800E3AE4: bc1fl       L_800E3B0C
    if (!c1cs) {
        // 0x800E3AE8: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_800E3B0C;
    }
    goto skip_0;
    // 0x800E3AE8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    skip_0:
    // 0x800E3AEC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800E3AF0: nop

    // 0x800E3AF4: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
L_800E3AF8:
    // 0x800E3AF8: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x800E3AFC: nop

    // 0x800E3B00: bc1tl       L_800E3AF8
    if (c1cs) {
        // 0x800E3B04: add.s       $f2, $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
            goto L_800E3AF8;
    }
    goto skip_1;
    // 0x800E3B04: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    skip_1:
    // 0x800E3B08: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
L_800E3B0C:
    // 0x800E3B0C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800E3B10: nop

    // 0x800E3B14: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800E3B18: nop

    // 0x800E3B1C: bc1fl       L_800E3B3C
    if (!c1cs) {
        // 0x800E3B20: trunc.w.s   $f16, $f2
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.u32l = TRUNC_W_S(ctx->f2.fl);
            goto L_800E3B3C;
    }
    goto skip_2;
    // 0x800E3B20: trunc.w.s   $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.u32l = TRUNC_W_S(ctx->f2.fl);
    skip_2:
    // 0x800E3B24: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
L_800E3B28:
    // 0x800E3B28: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800E3B2C: nop

    // 0x800E3B30: bc1tl       L_800E3B28
    if (c1cs) {
        // 0x800E3B34: sub.s       $f2, $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_800E3B28;
    }
    goto skip_3;
    // 0x800E3B34: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    skip_3:
    // 0x800E3B38: trunc.w.s   $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.u32l = TRUNC_W_S(ctx->f2.fl);
L_800E3B3C:
    // 0x800E3B3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E3B40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E3B44: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x800E3B48: jr          $ra
    // 0x800E3B4C: nop

    return;
    // 0x800E3B4C: nop

;}
RECOMP_FUNC void bsdrone_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800060: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800064: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800068: jal         0x80084808
    // 0x8080006C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _badrone_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x8080006C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800070: jal         0x80800000
    // 0x80800074: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800000_bsdrone(rdram, ctx);
        goto after_1;
    // 0x80800074: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800078: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8080007C: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80800080: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800084: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(160, 0X184) << 16);
    // 0x80800088: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x8080008C: lw          $t9, 0x184($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(160, 0X184));
    // 0x80800090: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800094: jalr        $t9
    // 0x80800098: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80800098: nop

    after_2:
    // 0x8080009C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000A4: jr          $ra
    // 0x808000A8: nop

    return;
    // 0x808000A8: nop

;}
RECOMP_FUNC void sucoaster_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A7C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80801A80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801A84: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80801A88: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80801A8C: jal         0x80100094
    // 0x80801A90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801A90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801A94: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    // 0x80801A98: srl         $t6, $a0, 28
    ctx->r14 = S32(U32(ctx->r4) >> 28);
    // 0x80801A9C: jal         0x8008A240
    // 0x80801AA0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    _sucoasterdata_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80801AA0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_1:
    // 0x80801AA4: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x80801AA8: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80801AAC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80801AB0: sll         $t7, $v1, 3
    ctx->r15 = S32(ctx->r3 << 3);
    // 0x80801AB4: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80801AB8: lh          $t9, 0x4($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X4);
    // 0x80801ABC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80801AC0: beq         $t9, $zero, L_80801B78
    if (ctx->r25 == 0) {
        // 0x80801AC4: nop
    
            goto L_80801B78;
    }
    // 0x80801AC4: nop

    // 0x80801AC8: jal         0x8010D640
    // 0x80801ACC: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    func_8010D640(rdram, ctx);
        goto after_2;
    // 0x80801ACC: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    after_2:
    // 0x80801AD0: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80801AD4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80801AD8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80801ADC: jal         0x800EEB40
    // 0x80801AE0: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_800EEB40(rdram, ctx);
        goto after_3;
    // 0x80801AE0: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_3:
    // 0x80801AE4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3274, 0X2870) << 16);
    // 0x80801AE8: lwc1        $f4, 0x2870($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3274, 0X2870));
    // 0x80801AEC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3274, 0X2874) << 16);
    // 0x80801AF0: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80801AF4: nop

    // 0x80801AF8: bc1f        L_80801B08
    if (!c1cs) {
        // 0x80801AFC: nop
    
            goto L_80801B08;
    }
    // 0x80801AFC: nop

    // 0x80801B00: b           L_80801B78
    // 0x80801B04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801B78;
    // 0x80801B04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801B08:
    // 0x80801B08: lwc1        $f12, 0x2874($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3274, 0X2874));
    // 0x80801B0C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3274, 0X2878) << 16);
    // 0x80801B10: jal         0x800DC178
    // 0x80801B14: lwc1        $f14, 0x2878($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3274, 0X2878));
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x80801B14: lwc1        $f14, 0x2878($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3274, 0X2878));
    after_4:
    // 0x80801B18: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80801B1C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80801B20: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x80801B24: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801B28: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x80801B2C: lh          $t2, 0x8($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X8);
    // 0x80801B30: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3274, 0X287C) << 16);
    // 0x80801B34: lwc1        $f18, 0x287C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3274, 0X287C));
    // 0x80801B38: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80801B3C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3274, 0X2880) << 16);
    // 0x80801B40: lwc1        $f4, 0x2880($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3274, 0X2880));
    // 0x80801B44: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80801B48: lh          $a0, 0x4($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X4);
    // 0x80801B4C: lh          $a2, 0x6($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X6);
    // 0x80801B50: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80801B54: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80801B58: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80801B5C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80801B60: add.s       $f2, $f0, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80801B64: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80801B68: jal         0x800C4104
    // 0x80801B6C: nop

    func_800C4104(rdram, ctx);
        goto after_5;
    // 0x80801B6C: nop

    after_5:
    // 0x80801B70: b           L_80801B78
    // 0x80801B74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801B78;
    // 0x80801B74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801B78:
    // 0x80801B78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801B7C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80801B80: jr          $ra
    // 0x80801B84: nop

    return;
    // 0x80801B84: nop

;}
RECOMP_FUNC void func_80800000_bsmumcast(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080000C: sltiu       $at, $a1, 0x5
    ctx->r1 = ctx->r5 < 0X5 ? 1 : 0;
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800014: beq         $at, $zero, L_80800170
    if (ctx->r1 == 0) {
        // 0x80800018: sw          $a1, 0x15C($a0)
        MEM_W(0X15C, ctx->r4) = ctx->r5;
            goto L_80800170;
    }
    // 0x80800018: sw          $a1, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r5;
    // 0x8080001C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80800020: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(316, 0X430) << 16);
    // 0x80800024: addu        $at, $at, $t6
    gpr jr_addend_8080002C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800028: lw          $t6, 0x430($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(316, 0X430));
    // 0x8080002C: jr          $t6
    // 0x80800030: nop

    switch (jr_addend_8080002C >> 2) {
        case 0: goto L_80800170; break;
        case 1: goto L_80800034; break;
        case 2: goto L_80800080; break;
        case 3: goto L_808000B4; break;
        case 4: goto L_8080010C; break;
        default: switch_error(__func__, 0x8080002C, 0x80800430);
    }
    // 0x80800030: nop

L_80800034:
    // 0x80800034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800038: addiu       $a1, $zero, 0xFC
    ctx->r5 = ADD32(0, 0XFC);
    // 0x8080003C: jal         0x8008CCBC
    // 0x80800040: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_0;
    // 0x80800040: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    after_0:
    // 0x80800044: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80800048: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8080004C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800050: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800054: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800058: jal         0x8009FFD8
    // 0x8080005C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x8080005C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x80800060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800064: jal         0x8009BA9C
    // 0x80800068: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009BA9C(rdram, ctx);
        goto after_2;
    // 0x80800068: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800070: jal         0x8009B9B0
    // 0x80800074: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_3;
    // 0x80800074: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x80800078: b           L_80800174
    // 0x8080007C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800174;
    // 0x8080007C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800080:
    // 0x80800080: lui         $a2, 0x3FDA
    ctx->r6 = S32(0X3FDA << 16);
    // 0x80800084: ori         $a2, $a2, 0xE148
    ctx->r6 = ctx->r6 | 0XE148;
    // 0x80800088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080008C: jal         0x8008CB3C
    // 0x80800090: addiu       $a1, $zero, 0x4A1
    ctx->r5 = ADD32(0, 0X4A1);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_4;
    // 0x80800090: addiu       $a1, $zero, 0x4A1
    ctx->r5 = ADD32(0, 0X4A1);
    after_4:
    // 0x80800094: jal         0x8009EAA0
    // 0x80800098: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8009EAA0(rdram, ctx);
        goto after_5;
    // 0x80800098: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x8080009C: jal         0x800FC6B0
    // 0x808000A0: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    func_800FC6B0(rdram, ctx);
        goto after_6;
    // 0x808000A0: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    after_6:
    // 0x808000A4: jal         0x800DA544
    // 0x808000A8: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    func_800DA544(rdram, ctx);
        goto after_7;
    // 0x808000A8: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    after_7:
    // 0x808000AC: b           L_80800174
    // 0x808000B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800174;
    // 0x808000B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000B4:
    // 0x808000B4: addiu       $a0, $zero, 0x9DF
    ctx->r4 = ADD32(0, 0X9DF);
    // 0x808000B8: jal         0x800DA3B8
    // 0x808000BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DA3B8(rdram, ctx);
        goto after_8;
    // 0x808000BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C4: addiu       $a1, $zero, 0xFB
    ctx->r5 = ADD32(0, 0XFB);
    // 0x808000C8: jal         0x8008CCBC
    // 0x808000CC: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_9;
    // 0x808000CC: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    after_9:
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D4: addiu       $a1, $zero, 0x3FE
    ctx->r5 = ADD32(0, 0X3FE);
    // 0x808000D8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808000DC: jal         0x8009DB04
    // 0x808000E0: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    func_8009DB04(rdram, ctx);
        goto after_10;
    // 0x808000E0: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    after_10:
    // 0x808000E4: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    // 0x808000E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000EC: jal         0x800FCAE0
    // 0x808000F0: addiu       $a2, $zero, 0x708
    ctx->r6 = ADD32(0, 0X708);
    func_800FCAE0(rdram, ctx);
        goto after_11;
    // 0x808000F0: addiu       $a2, $zero, 0x708
    ctx->r6 = ADD32(0, 0X708);
    after_11:
    // 0x808000F4: jal         0x800FCA90
    // 0x808000F8: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    func_800FCA90(rdram, ctx);
        goto after_12;
    // 0x808000F8: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    after_12:
    // 0x808000FC: jal         0x8009EAA0
    // 0x80800100: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8009EAA0(rdram, ctx);
        goto after_13;
    // 0x80800100: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
    // 0x80800104: b           L_80800174
    // 0x80800108: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800174;
    // 0x80800108: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080010C:
    // 0x8080010C: lui         $a3, 0x3F7F
    ctx->r7 = S32(0X3F7F << 16);
    // 0x80800110: ori         $a3, $a3, 0xF972
    ctx->r7 = ctx->r7 | 0XF972;
    // 0x80800114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800118: addiu       $a1, $zero, 0xFC
    ctx->r5 = ADD32(0, 0XFC);
    // 0x8080011C: jal         0x8008CE3C
    // 0x80800120: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    baanim_playForDuration_onceStartingAt(rdram, ctx);
        goto after_14;
    // 0x80800120: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    after_14:
    // 0x80800124: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80800128: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800130: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800134: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800138: jal         0x8009FFD8
    // 0x8080013C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8009FFD8(rdram, ctx);
        goto after_15;
    // 0x8080013C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_15:
    // 0x80800140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800144: jal         0x8009BA9C
    // 0x80800148: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009BA9C(rdram, ctx);
        goto after_16;
    // 0x80800148: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x8080014C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800150: jal         0x8009B9B0
    // 0x80800154: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_17;
    // 0x80800154: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_17:
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080015C: jal         0x800A0DAC
    // 0x80800160: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0DAC(rdram, ctx);
        goto after_18;
    // 0x80800160: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_18:
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800168: jal         0x800A0DA0
    // 0x8080016C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0DA0(rdram, ctx);
        goto after_19;
    // 0x8080016C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
L_80800170:
    // 0x80800170: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800174:
    // 0x80800174: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800178: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080017C: jr          $ra
    // 0x80800180: nop

    return;
    // 0x80800180: nop

;}
RECOMP_FUNC void _chmoley_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086900: syscall     396
    recomp_syscall_handler(rdram, ctx, 0x80086900);
    return;
    // 0x80086904: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800F5794(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5794: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5798: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F579C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F57A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F57A4: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F57A8: jal         0x800F3B3C
    // 0x800F57AC: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_800F3B3C(rdram, ctx);
        goto after_0;
    // 0x800F57AC: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F57B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F57B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F57B8: jr          $ra
    // 0x800F57BC: nop

    return;
    // 0x800F57BC: nop

;}
RECOMP_FUNC void bsbeemain_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801230: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801234: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(80, 0X12E0) << 16);
    // 0x80801238: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080123C: jr          $ra
    // 0x80801240: lw          $v0, 0x12E0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(80, 0X12E0));
    return;
    // 0x80801240: lw          $v0, 0x12E0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(80, 0X12E0));
    // 0x80801244: nop

    // 0x80801248: nop

    // 0x8080124C: nop

;}
RECOMP_FUNC void func_808001FC_chcauldronentrydoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800200: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800204: lhu         $t6, 0x6E($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X6E);
    // 0x80800208: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080020C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800210: andi        $t7, $t6, 0xFE00
    ctx->r15 = ctx->r14 & 0XFE00;
    // 0x80800214: sh          $t7, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r15;
    // 0x80800218: swc1        $f4, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f4.u32l;
    // 0x8080021C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x80800220: jal         0x800DA298
    // 0x80800224: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800224: addiu       $a0, $zero, 0x436
    ctx->r4 = ADD32(0, 0X436);
    after_0:
    // 0x80800228: beq         $v0, $zero, L_80800240
    if (ctx->r2 == 0) {
        // 0x8080022C: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_80800240;
    }
    // 0x8080022C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800230: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800234: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800238: b           L_80800250
    // 0x8080023C: swc1        $f6, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->f6.u32l;
        goto L_80800250;
    // 0x8080023C: swc1        $f6, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->f6.u32l;
L_80800240:
    // 0x80800240: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x80800244: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800248: nop

    // 0x8080024C: swc1        $f8, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->f8.u32l;
L_80800250:
    // 0x80800250: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800254: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800258: lwc1        $f16, 0x1C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x8080025C: swc1        $f10, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->f10.u32l;
    // 0x80800260: swc1        $f16, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->f16.u32l;
    // 0x80800264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800268: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080026C: jr          $ra
    // 0x80800270: nop

    return;
    // 0x80800270: nop

;}
RECOMP_FUNC void func_80800B54_bsbeefly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800B58: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800B5C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800B60: jal         0x80082838
    // 0x80800B64: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _bsbee_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800B64: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800B68: jal         0x8080039C
    // 0x80800B6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080039C_bsbeefly(rdram, ctx);
        goto after_1;
    // 0x80800B6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800B70: jal         0x800839C8
    // 0x80800B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsrest_entrypoint_16(rdram, ctx);
        goto after_2;
    // 0x80800B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800B78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B7C: jal         0x8009BCB4
    // 0x80800B80: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_gravity(rdram, ctx);
        goto after_3;
    // 0x80800B80: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x80800B84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B88: jal         0x8009BA9C
    // 0x80800B8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009BA9C(rdram, ctx);
        goto after_4;
    // 0x80800B8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800B90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B94: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800B98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800B9C: jr          $ra
    // 0x80800BA0: nop

    return;
    // 0x80800BA0: nop

;}
RECOMP_FUNC void func_80016B54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016B54: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x80016B58: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80016B5C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80016B60: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80016B64: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80016B68: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80016B6C: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x80016B70: jr          $ra
    // 0x80016B74: lw          $v0, -0x6608($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6608);
    return;
    // 0x80016B74: lw          $v0, -0x6608($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6608);
;}
RECOMP_FUNC void func_800C8588(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8588: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800C858C: jr          $ra
    // 0x800C8590: lbu         $v0, 0x14($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X14);
    return;
    // 0x800C8590: lbu         $v0, 0x14($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X14);
;}
RECOMP_FUNC void func_808013BC_bsvan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808013C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808013C4: jal         0x808000F0
    // 0x808013C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bsvan_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x808013C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808013CC: jal         0x80090A2C
    // 0x808013D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80090A2C(rdram, ctx);
        goto after_1;
    // 0x808013D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808013D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808013D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808013DC: jr          $ra
    // 0x808013E0: nop

    return;
    // 0x808013E0: nop

;}
RECOMP_FUNC void ncpod_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808005C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808005C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808005CC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808005D0: lbu         $v0, 0x41($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X41);
    // 0x808005D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808005D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808005DC: beq         $v0, $at, L_808005FC
    if (ctx->r2 == ctx->r1) {
        // 0x808005E0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808005FC;
    }
    // 0x808005E0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808005E4: beq         $v0, $at, L_8080060C
    if (ctx->r2 == ctx->r1) {
        // 0x808005E8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8080060C;
    }
    // 0x808005E8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808005EC: beq         $v0, $at, L_8080061C
    if (ctx->r2 == ctx->r1) {
        // 0x808005F0: nop
    
            goto L_8080061C;
    }
    // 0x808005F0: nop

    // 0x808005F4: b           L_8080062C
    // 0x808005F8: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
        goto L_8080062C;
    // 0x808005F8: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
L_808005FC:
    // 0x808005FC: jal         0x800895E8
    // 0x80800600: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    _ncpoddialog_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800600: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    after_0:
    // 0x80800604: b           L_80800628
    // 0x80800608: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
        goto L_80800628;
    // 0x80800608: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
L_8080060C:
    // 0x8080060C: jal         0x80089660
    // 0x80800610: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    _ncpoducam_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800610: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    after_1:
    // 0x80800614: b           L_80800628
    // 0x80800618: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
        goto L_80800628;
    // 0x80800618: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
L_8080061C:
    // 0x8080061C: jal         0x80089698
    // 0x80800620: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
    _ncpodfixpos_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800620: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
    after_2:
    // 0x80800624: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
L_80800628:
    // 0x80800628: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
L_8080062C:
    // 0x8080062C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800630: andi        $v0, $t6, 0xFF
    ctx->r2 = ctx->r14 & 0XFF;
    // 0x80800634: beq         $v0, $at, L_80800658
    if (ctx->r2 == ctx->r1) {
        // 0x80800638: sb          $t6, 0x41($s0)
        MEM_B(0X41, ctx->r16) = ctx->r14;
            goto L_80800658;
    }
    // 0x80800638: sb          $t6, 0x41($s0)
    MEM_B(0X41, ctx->r16) = ctx->r14;
    // 0x8080063C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800640: beq         $v0, $at, L_80800668
    if (ctx->r2 == ctx->r1) {
        // 0x80800644: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800668;
    }
    // 0x80800644: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800648: beq         $v0, $at, L_80800678
    if (ctx->r2 == ctx->r1) {
        // 0x8080064C: nop
    
            goto L_80800678;
    }
    // 0x8080064C: nop

    // 0x80800650: b           L_80800688
    // 0x80800654: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800688;
    // 0x80800654: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800658:
    // 0x80800658: jal         0x800895E0
    // 0x8080065C: nop

    _ncpoddialog_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x8080065C: nop

    after_3:
    // 0x80800660: b           L_80800684
    // 0x80800664: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
        goto L_80800684;
    // 0x80800664: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
L_80800668:
    // 0x80800668: jal         0x80089630
    // 0x8080066C: nop

    _ncpoducam_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x8080066C: nop

    after_4:
    // 0x80800670: b           L_80800684
    // 0x80800674: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
        goto L_80800684;
    // 0x80800674: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
L_80800678:
    // 0x80800678: jal         0x80089690
    // 0x8080067C: nop

    _ncpodfixpos_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x8080067C: nop

    after_5:
    // 0x80800680: sh          $v0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r2;
L_80800684:
    // 0x80800684: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800688:
    // 0x80800688: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080068C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800690: jr          $ra
    // 0x80800694: nop

    return;
    // 0x80800694: nop

;}
RECOMP_FUNC void _gclevel_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088220: syscall     676
    recomp_syscall_handler(rdram, ctx, 0x80088220);
    return;
    // 0x80088224: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800BA0_chboggyfatboy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BA0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800BA4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800BA8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800BAC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800BB0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800BB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800BB8: jal         0x80089C30
    // 0x80800BBC: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800BBC: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    after_0:
    // 0x80800BC0: beq         $v0, $zero, L_80800C28
    if (ctx->r2 == 0) {
        // 0x80800BC4: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_80800C28;
    }
    // 0x80800BC4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800BC8: jal         0x800CBC3C
    // 0x80800BCC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_800CBC3C(rdram, ctx);
        goto after_1;
    // 0x80800BCC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800BD0: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80800BD4: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80800BD8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800BDC: lw          $t7, 0x70($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X70);
    // 0x80800BE0: addiu       $a1, $v1, 0x4
    ctx->r5 = ADD32(ctx->r3, 0X4);
    // 0x80800BE4: srl         $t8, $t7, 25
    ctx->r24 = S32(U32(ctx->r15) >> 25);
    // 0x80800BE8: bnel        $t6, $t8, L_80800C2C
    if (ctx->r14 != ctx->r24) {
        // 0x80800BEC: addiu       $a0, $zero, 0x1097
        ctx->r4 = ADD32(0, 0X1097);
            goto L_80800C2C;
    }
    goto skip_0;
    // 0x80800BEC: addiu       $a0, $zero, 0x1097
    ctx->r4 = ADD32(0, 0X1097);
    skip_0:
    // 0x80800BF0: jal         0x800EE7F8
    // 0x80800BF4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800BF4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80800BF8: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80800BFC: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80800C00: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800C04: lwc1        $f4, 0x48($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X48);
    // 0x80800C08: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800C0C: lui         $a2, 0x4334
    ctx->r6 = S32(0X4334 << 16);
    // 0x80800C10: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800C14: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800C18: jal         0x800EF1B8
    // 0x80800C1C: nop

    func_800EF1B8(rdram, ctx);
        goto after_3;
    // 0x80800C1C: nop

    after_3:
    // 0x80800C20: b           L_80800C4C
    // 0x80800C24: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80800C4C;
    // 0x80800C24: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80800C28:
    // 0x80800C28: addiu       $a0, $zero, 0x1097
    ctx->r4 = ADD32(0, 0X1097);
L_80800C2C:
    // 0x80800C2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800C30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800C34: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800C38: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800C3C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80800C40: jal         0x800C05B8
    // 0x80800C44: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    func_800C05B8(rdram, ctx);
        goto after_4;
    // 0x80800C44: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_4:
    // 0x80800C48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C4C:
    // 0x80800C4C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800C50: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800C54: jr          $ra
    // 0x80800C58: nop

    return;
    // 0x80800C58: nop

;}
RECOMP_FUNC void func_80090038(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090038: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009003C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80090040: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80090044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090048: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8009004C: jal         0x800EE88C
    // 0x80090050: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800EE88C(rdram, ctx);
        goto after_0;
    // 0x80090050: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80090054: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80090058: addiu       $a1, $zero, 0x58
    ctx->r5 = ADD32(0, 0X58);
    // 0x8009005C: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x80090060: lhu         $a0, 0x1A($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X1A);
    // 0x80090064: srl         $t7, $a0, 5
    ctx->r15 = S32(U32(ctx->r4) >> 5);
    // 0x80090068: jal         0x800F7CF4
    // 0x8009006C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_800F7CF4(rdram, ctx);
        goto after_1;
    // 0x8009006C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_1:
    // 0x80090070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80090074: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80090078: jr          $ra
    // 0x8009007C: nop

    return;
    // 0x8009007C: nop

;}
RECOMP_FUNC void func_8080000C_changlerbossdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800010: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800014: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800018: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080001C: jal         0x800DA298
    // 0x80800020: addiu       $a0, $zero, 0x1AF
    ctx->r4 = ADD32(0, 0X1AF);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800020: addiu       $a0, $zero, 0x1AF
    ctx->r4 = ADD32(0, 0X1AF);
    after_0:
    // 0x80800024: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800028: bne         $v1, $zero, L_8080003C
    if (ctx->r3 != 0) {
        // 0x8080002C: nop
    
            goto L_8080003C;
    }
    // 0x8080002C: nop

    // 0x80800030: jal         0x80088848
    // 0x80800034: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x80800034: nop

    after_1:
    // 0x80800038: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
L_8080003C:
    // 0x8080003C: beq         $v1, $zero, L_8080004C
    if (ctx->r3 == 0) {
        // 0x80800040: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080004C;
    }
    // 0x80800040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800044: jal         0x80101FDC
    // 0x80800048: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80800048: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_8080004C:
    // 0x8080004C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80800050: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800054: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080005C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800060: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800064: jal         0x80102FDC
    // 0x80800068: nop

    func_80102FDC(rdram, ctx);
        goto after_3;
    // 0x80800068: nop

    after_3:
    // 0x8080006C: lbu         $t7, 0x73($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X73);
    // 0x80800070: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800074: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800078: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x8080007C: sb          $t8, 0x73($s0)
    MEM_B(0X73, ctx->r16) = ctx->r24;
    // 0x80800080: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800084: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    // 0x80800088: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x8080008C: jal         0x800EF6A8
    // 0x80800090: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800EF6A8(rdram, ctx);
        goto after_4;
    // 0x80800090: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x80800094: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800098: jal         0x800F1A88
    // 0x8080009C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800F1A88(rdram, ctx);
        goto after_5;
    // 0x8080009C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_5:
    // 0x808000A0: addiu       $t9, $zero, 0x802
    ctx->r25 = ADD32(0, 0X802);
    // 0x808000A4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x808000A8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x808000AC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x808000B8: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x808000BC: jal         0x80086898
    // 0x808000C0: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x808000C0: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    after_6:
    // 0x808000C4: beq         $v0, $zero, L_808000F0
    if (ctx->r2 == 0) {
        // 0x808000C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000F0;
    }
    // 0x808000C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000CC: jal         0x800868A8
    // 0x808000D0: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_7;
    // 0x808000D0: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_7:
    // 0x808000D4: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x808000D8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808000DC: jal         0x800868B0
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chdoormake_entrypoint_6(rdram, ctx);
        goto after_8;
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E8: jal         0x800868C0
    // 0x808000EC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_9;
    // 0x808000EC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_9:
L_808000F0:
    // 0x808000F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808000F4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808000F8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808000FC: jr          $ra
    // 0x80800100: nop

    return;
    // 0x80800100: nop

    // 0x80800104: nop

    // 0x80800108: nop

    // 0x8080010C: nop

;}
RECOMP_FUNC void func_80800C10_chstonepillar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800C14: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(880, 0X14B8) << 16);
    // 0x80800C18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800C1C: addiu       $t6, $t6, 0x14B8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(880, 0X14B8));
    // 0x80800C20: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800C24: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800C28: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800C2C: jal         0x800BBCB8
    // 0x80800C30: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x80800C30: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_0:
    // 0x80800C34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800C3C: jr          $ra
    // 0x80800C40: nop

    return;
    // 0x80800C40: nop

;}
RECOMP_FUNC void heap_alloc_sided(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001ACEC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001ACF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001ACF4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001ACF8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001ACFC: jal         0x8001B3E8
    // 0x8001AD00: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    heap_bytes_allocated(rdram, ctx);
        goto after_0;
    // 0x8001AD00: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x8001AD04: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001AD08: lw          $v1, -0x1670($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X1670);
    // 0x8001AD0C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8001AD10: lw          $t6, 0x14($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X14);
    // 0x8001AD14: addu        $t8, $v0, $v1
    ctx->r24 = ADD32(ctx->r2, ctx->r3);
    // 0x8001AD18: addiu       $t7, $t6, 0x20
    ctx->r15 = ADD32(ctx->r14, 0X20);
    // 0x8001AD1C: bne         $t7, $t8, L_8001AD2C
    if (ctx->r15 != ctx->r24) {
        // 0x8001AD20: nop
    
            goto L_8001AD2C;
    }
    // 0x8001AD20: nop

    // 0x8001AD24: jal         0x8001A6C0
    // 0x8001AD28: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8001A6C0(rdram, ctx);
        goto after_1;
    // 0x8001AD28: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
L_8001AD2C:
    // 0x8001AD2C: blez        $s0, L_8001AD3C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8001AD30: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8001AD3C;
    }
    // 0x8001AD30: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8001AD34: b           L_8001AD3C
    // 0x8001AD38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8001AD3C;
    // 0x8001AD38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8001AD3C:
    // 0x8001AD3C: jal         0x8001BD30
    // 0x8001AD40: nop

    func_8001BD30(rdram, ctx);
        goto after_2;
    // 0x8001AD40: nop

    after_2:
    // 0x8001AD44: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8001AD48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001AD4C: jal         0x8001AAE4
    // 0x8001AD50: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    find_free_block(rdram, ctx);
        goto after_3;
    // 0x8001AD50: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x8001AD54: bne         $v0, $zero, L_8001AD90
    if (ctx->r2 != 0) {
        // 0x8001AD58: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8001AD90;
    }
    // 0x8001AD58: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8001AD5C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8001AD60: jal         0x800A9D90
    // 0x8001AD64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A9D90(rdram, ctx);
        goto after_4;
    // 0x8001AD64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8001AD68: bne         $v0, $zero, L_8001AD84
    if (ctx->r2 != 0) {
        // 0x8001AD6C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8001AD84;
    }
    // 0x8001AD6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001AD70: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8001AD74: jal         0x8001A6C0
    // 0x8001AD78: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8001A6C0(rdram, ctx);
        goto after_5;
    // 0x8001AD78: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x8001AD7C: b           L_8001AF00
    // 0x8001AD80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001AF00;
    // 0x8001AD80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001AD84:
    // 0x8001AD84: jal         0x8001AAE4
    // 0x8001AD88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    find_free_block(rdram, ctx);
        goto after_6;
    // 0x8001AD88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8001AD8C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8001AD90:
    // 0x8001AD90: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x8001AD94: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8001AD98: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8001AD9C: subu        $t1, $t0, $v0
    ctx->r9 = SUB32(ctx->r8, ctx->r2);
    // 0x8001ADA0: addiu       $t2, $t1, -0x10
    ctx->r10 = ADD32(ctx->r9, -0X10);
    // 0x8001ADA4: addiu       $t9, $a2, 0x10
    ctx->r25 = ADD32(ctx->r6, 0X10);
    // 0x8001ADA8: sltu        $at, $t9, $t2
    ctx->r1 = ctx->r25 < ctx->r10 ? 1 : 0;
    // 0x8001ADAC: beq         $at, $zero, L_8001AE68
    if (ctx->r1 == 0) {
        // 0x8001ADB0: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8001AE68;
    }
    // 0x8001ADB0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001ADB4: bne         $t3, $at, L_8001ADF0
    if (ctx->r11 != ctx->r1) {
        // 0x8001ADB8: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_8001ADF0;
    }
    // 0x8001ADB8: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8001ADBC: lw          $t4, 0x4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X4);
    // 0x8001ADC0: lw          $t5, 0x4($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4);
    // 0x8001ADC4: subu        $v1, $t4, $a2
    ctx->r3 = SUB32(ctx->r12, ctx->r6);
    // 0x8001ADC8: sw          $t5, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->r13;
    // 0x8001ADCC: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8001ADD0: addiu       $v1, $v1, -0x10
    ctx->r3 = ADD32(ctx->r3, -0X10);
    // 0x8001ADD4: sw          $v1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r3;
    // 0x8001ADD8: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // 0x8001ADDC: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8001ADE0: jal         0x8001AF14
    // 0x8001ADE4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    heap_merge_free_block(rdram, ctx);
        goto after_7;
    // 0x8001ADE4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_7:
    // 0x8001ADE8: b           L_8001AE80
    // 0x8001ADEC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
        goto L_8001AE80;
    // 0x8001ADEC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_8001ADF0:
    // 0x8001ADF0: lw          $t7, 0x14($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X14);
    // 0x8001ADF4: addu        $v0, $v1, $a2
    ctx->r2 = ADD32(ctx->r3, ctx->r6);
    // 0x8001ADF8: addiu       $a0, $v0, 0x10
    ctx->r4 = ADD32(ctx->r2, 0X10);
    // 0x8001ADFC: sw          $t7, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r15;
    // 0x8001AE00: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
    // 0x8001AE04: sw          $t8, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r24;
    // 0x8001AE08: sw          $a0, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->r4;
    // 0x8001AE0C: lw          $t1, 0x20($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X20);
    // 0x8001AE10: sw          $a0, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r4;
    // 0x8001AE14: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x8001AE18: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x8001AE1C: sw          $t9, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r25;
    // 0x8001AE20: sw          $a0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r4;
    // 0x8001AE24: lbu         $t3, 0x1F($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X1F);
    // 0x8001AE28: andi        $t5, $t3, 0xFF3F
    ctx->r13 = ctx->r11 & 0XFF3F;
    // 0x8001AE2C: andi        $t7, $t5, 0xF7
    ctx->r15 = ctx->r13 & 0XF7;
    // 0x8001AE30: sb          $t5, 0x1F($v0)
    MEM_B(0X1F, ctx->r2) = ctx->r13;
    // 0x8001AE34: sb          $t7, 0x1F($v0)
    MEM_B(0X1F, ctx->r2) = ctx->r15;
    // 0x8001AE38: andi        $t8, $t7, 0xFB
    ctx->r24 = ctx->r15 & 0XFB;
    // 0x8001AE3C: sb          $t8, 0x1F($v0)
    MEM_B(0X1F, ctx->r2) = ctx->r24;
    // 0x8001AE40: lw          $a1, 0x1C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X1C);
    // 0x8001AE44: srl         $t0, $a1, 8
    ctx->r8 = S32(U32(ctx->r5) >> 8);
    // 0x8001AE48: sll         $t1, $t0, 8
    ctx->r9 = S32(ctx->r8 << 8);
    // 0x8001AE4C: xor         $t9, $t1, $a1
    ctx->r25 = ctx->r9 ^ ctx->r5;
    // 0x8001AE50: sw          $t9, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r25;
    // 0x8001AE54: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x8001AE58: jal         0x8001AF14
    // 0x8001AE5C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    heap_merge_free_block(rdram, ctx);
        goto after_8;
    // 0x8001AE5C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_8:
    // 0x8001AE60: b           L_8001AE80
    // 0x8001AE64: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
        goto L_8001AE80;
    // 0x8001AE64: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_8001AE68:
    // 0x8001AE68: lw          $t2, 0x10($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X10);
    // 0x8001AE6C: lw          $t3, 0x14($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X14);
    // 0x8001AE70: sw          $t2, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r10;
    // 0x8001AE74: lw          $t5, 0x10($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X10);
    // 0x8001AE78: lw          $t4, 0x14($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X14);
    // 0x8001AE7C: sw          $t4, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r12;
L_8001AE80:
    // 0x8001AE80: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x8001AE84: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    // 0x8001AE88: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8001AE8C: subu        $a0, $t6, $v1
    ctx->r4 = SUB32(ctx->r14, ctx->r3);
    // 0x8001AE90: subu        $t7, $a0, $s0
    ctx->r15 = SUB32(ctx->r4, ctx->r16);
    // 0x8001AE94: addiu       $t8, $t7, -0x10
    ctx->r24 = ADD32(ctx->r15, -0X10);
    // 0x8001AE98: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8001AE9C: and         $t0, $t8, $at
    ctx->r8 = ctx->r24 & ctx->r1;
    // 0x8001AEA0: srl         $t1, $a1, 8
    ctx->r9 = S32(U32(ctx->r5) >> 8);
    // 0x8001AEA4: xor         $t9, $t0, $t1
    ctx->r25 = ctx->r8 ^ ctx->r9;
    // 0x8001AEA8: sll         $t2, $t9, 8
    ctx->r10 = S32(ctx->r25 << 8);
    // 0x8001AEAC: xor         $t3, $t2, $a1
    ctx->r11 = ctx->r10 ^ ctx->r5;
    // 0x8001AEB0: sw          $t3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r11;
    // 0x8001AEB4: lbu         $t4, 0xF($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0XF);
    // 0x8001AEB8: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x8001AEBC: addiu       $a2, $a2, -0x8B0
    ctx->r6 = ADD32(ctx->r6, -0X8B0);
    // 0x8001AEC0: andi        $t5, $t4, 0xFF3F
    ctx->r13 = ctx->r12 & 0XFF3F;
    // 0x8001AEC4: ori         $t7, $t5, 0x40
    ctx->r15 = ctx->r13 | 0X40;
    // 0x8001AEC8: andi        $t0, $t7, 0xF7
    ctx->r8 = ctx->r15 & 0XF7;
    // 0x8001AECC: sb          $t7, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r15;
    // 0x8001AED0: sb          $t0, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r8;
    // 0x8001AED4: andi        $t4, $t0, 0xFB
    ctx->r12 = ctx->r8 & 0XFB;
    // 0x8001AED8: sb          $t4, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r12;
    // 0x8001AEDC: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8001AEE0: andi        $t5, $t4, 0xFC
    ctx->r13 = ctx->r12 & 0XFC;
    // 0x8001AEE4: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x8001AEE8: andi        $t3, $t2, 0x3
    ctx->r11 = ctx->r10 & 0X3;
    // 0x8001AEEC: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x8001AEF0: sb          $t6, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r14;
    // 0x8001AEF4: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x8001AEF8: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x8001AEFC: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
L_8001AF00:
    // 0x8001AF00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AF04: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001AF08: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001AF0C: jr          $ra
    // 0x8001AF10: nop

    return;
    // 0x8001AF10: nop

;}
RECOMP_FUNC void _chfirefx_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086138: syscall     281
    recomp_syscall_handler(rdram, ctx, 0x80086138);
    return;
    // 0x8008613C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800260_subaddiestore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800260: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800264: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800268: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8080026C: bnel        $t6, $zero, L_80800280
    if (ctx->r14 != 0) {
        // 0x80800270: lw          $t7, 0x74($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X74);
            goto L_80800280;
    }
    goto skip_0;
    // 0x80800270: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    skip_0:
    // 0x80800274: b           L_80800320
    // 0x80800278: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800320;
    // 0x80800278: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080027C: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
L_80800280:
    // 0x80800280: sll         $t9, $t7, 14
    ctx->r25 = S32(ctx->r15 << 14);
    // 0x80800284: bgez        $t9, L_8080029C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800288: nop
    
            goto L_8080029C;
    }
    // 0x80800288: nop

    // 0x8080028C: lw          $t0, 0x64($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X64);
    // 0x80800290: sll         $t2, $t0, 14
    ctx->r10 = S32(ctx->r8 << 14);
    // 0x80800294: bgezl       $t2, L_808002A8
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80800298: lw          $t3, 0x70($a0)
        ctx->r11 = MEM_W(ctx->r4, 0X70);
            goto L_808002A8;
    }
    goto skip_1;
    // 0x80800298: lw          $t3, 0x70($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X70);
    skip_1:
L_8080029C:
    // 0x8080029C: b           L_80800320
    // 0x808002A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800320;
    // 0x808002A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808002A4: lw          $t3, 0x70($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X70);
L_808002A8:
    // 0x808002A8: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x808002AC: sll         $t5, $t3, 14
    ctx->r13 = S32(ctx->r11 << 14);
    // 0x808002B0: bgez        $t5, L_80800304
    if (SIGNED(ctx->r13) >= 0) {
        // 0x808002B4: nop
    
            goto L_80800304;
    }
    // 0x808002B4: nop

    // 0x808002B8: jal         0x800DB9B0
    // 0x808002BC: nop

    func_800DB9B0(rdram, ctx);
        goto after_0;
    // 0x808002BC: nop

    after_0:
    // 0x808002C0: sltu        $a0, $zero, $v0
    ctx->r4 = 0 < ctx->r2 ? 1 : 0;
    // 0x808002C4: beq         $a0, $zero, L_808002E8
    if (ctx->r4 == 0) {
        // 0x808002C8: nop
    
            goto L_808002E8;
    }
    // 0x808002C8: nop

    // 0x808002CC: jal         0x800887E8
    // 0x808002D0: nop

    _glcutDll_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x808002D0: nop

    after_1:
    // 0x808002D4: jal         0x800EA05C
    // 0x808002D8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800EA05C(rdram, ctx);
        goto after_2;
    // 0x808002D8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x808002DC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x808002E0: xor         $a0, $v0, $t6
    ctx->r4 = ctx->r2 ^ ctx->r14;
    // 0x808002E4: sltu        $a0, $zero, $a0
    ctx->r4 = 0 < ctx->r4 ? 1 : 0;
L_808002E8:
    // 0x808002E8: beql        $a0, $zero, L_808002FC
    if (ctx->r4 == 0) {
        // 0x808002EC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_808002FC;
    }
    goto skip_2;
    // 0x808002EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_2:
    // 0x808002F0: b           L_80800320
    // 0x808002F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800320;
    // 0x808002F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808002F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_808002FC:
    // 0x808002FC: b           L_80800320
    // 0x80800300: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_80800320;
    // 0x80800300: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80800304:
    // 0x80800304: jal         0x80102F74
    // 0x80800308: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_80102F74(rdram, ctx);
        goto after_3;
    // 0x80800308: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_3:
    // 0x8080030C: beql        $v0, $zero, L_80800320
    if (ctx->r2 == 0) {
        // 0x80800310: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800320;
    }
    goto skip_3;
    // 0x80800310: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_3:
    // 0x80800314: b           L_80800320
    // 0x80800318: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80800320;
    // 0x80800318: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8080031C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800320:
    // 0x80800320: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800324: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800328: jr          $ra
    // 0x8080032C: nop

    return;
    // 0x8080032C: nop

;}
RECOMP_FUNC void func_8080094C_chcactusofstrength(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080094C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800950: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800954: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800958: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x8080095C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800960: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800964: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800968: beq         $t6, $at, L_80800978
    if (ctx->r14 == ctx->r1) {
        // 0x8080096C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800978;
    }
    // 0x8080096C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800970: bne         $t6, $at, L_80800A28
    if (ctx->r14 != ctx->r1) {
        // 0x80800974: nop
    
            goto L_80800A28;
    }
    // 0x80800974: nop

L_80800978:
    // 0x80800978: lbu         $v0, 0x5F($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X5F);
    // 0x8080097C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800980: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800984: bne         $v0, $zero, L_8080099C
    if (ctx->r2 != 0) {
        // 0x80800988: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_8080099C;
    }
    // 0x80800988: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080098C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(824, 0XE08) << 16);
    // 0x80800990: jal         0x80089D50
    // 0x80800994: addiu       $a3, $a3, 0xE08
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(824, 0XE08));
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800994: addiu       $a3, $a3, 0xE08
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(824, 0XE08));
    after_0:
    // 0x80800998: lbu         $v0, 0x5F($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X5F);
L_8080099C:
    // 0x8080099C: beq         $v0, $zero, L_80800A30
    if (ctx->r2 == 0) {
        // 0x808009A0: addiu       $t7, $s0, 0x4
        ctx->r15 = ADD32(ctx->r16, 0X4);
            goto L_80800A30;
    }
    // 0x808009A0: addiu       $t7, $s0, 0x4
    ctx->r15 = ADD32(ctx->r16, 0X4);
    // 0x808009A4: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808009A8: jal         0x800F2100
    // 0x808009AC: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    mlAbsF(rdram, ctx);
        goto after_1;
    // 0x808009AC: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    after_1:
    // 0x808009B0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x808009B4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808009B8: jal         0x800F13F0
    // 0x808009BC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800F13F0(rdram, ctx);
        goto after_2;
    // 0x808009BC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_2:
    // 0x808009C0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808009C4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808009C8: jal         0x800F0E00
    // 0x808009CC: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    func_800F0E00(rdram, ctx);
        goto after_3;
    // 0x808009CC: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    after_3:
    // 0x808009D0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808009D4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808009D8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(824, 0XCD0) << 16);
    // 0x808009DC: lwc1        $f4, 0xCD0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(824, 0XCD0));
    // 0x808009E0: lui         $a3, 0x3F8C
    ctx->r7 = S32(0X3F8C << 16);
    // 0x808009E4: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808009E8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808009EC: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    // 0x808009F0: jal         0x800F10B4
    // 0x808009F4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x808009F4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x808009F8: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x808009FC: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x80800A00: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800A04: jal         0x800C4350
    // 0x80800A08: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800C4350(rdram, ctx);
        goto after_5;
    // 0x80800A08: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x80800A0C: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x80800A10: jal         0x800C31DC
    // 0x80800A14: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800C31DC(rdram, ctx);
        goto after_6;
    // 0x80800A14: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_6:
    // 0x80800A18: jal         0x800C3BDC
    // 0x80800A1C: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    func_800C3BDC(rdram, ctx);
        goto after_7;
    // 0x80800A1C: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    after_7:
    // 0x80800A20: b           L_80800A34
    // 0x80800A24: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800A34;
    // 0x80800A24: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800A28:
    // 0x80800A28: jal         0x80089D40
    // 0x80800A2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x80800A2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_80800A30:
    // 0x80800A30: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800A34:
    // 0x80800A34: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800A38: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800A3C: jr          $ra
    // 0x80800A40: nop

    return;
    // 0x80800A40: nop

;}
RECOMP_FUNC void _chglowbo_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086AE0: syscall     414
    recomp_syscall_handler(rdram, ctx, 0x80086AE0);
    return;
    // 0x80086AE4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800976DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800976DC: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800976E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800976E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800976E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800976EC: jal         0x80091570
    // 0x800976F0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    bastatetimer_isActive(rdram, ctx);
        goto after_0;
    // 0x800976F0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_0:
    // 0x800976F4: beq         $v0, $zero, L_80097704
    if (ctx->r2 == 0) {
        // 0x800976F8: nop
    
            goto L_80097704;
    }
    // 0x800976F8: nop

    // 0x800976FC: b           L_80097844
    // 0x80097700: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80097844;
    // 0x80097700: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80097704:
    // 0x80097704: jal         0x8009650C
    // 0x80097708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009650C(rdram, ctx);
        goto after_1;
    // 0x80097708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8009770C: bne         $v0, $zero, L_8009771C
    if (ctx->r2 != 0) {
        // 0x80097710: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8009771C;
    }
    // 0x80097710: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80097714: b           L_80097844
    // 0x80097718: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80097844;
    // 0x80097718: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009771C:
    // 0x8009771C: jal         0x80096440
    // 0x80097720: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    func_80096440(rdram, ctx);
        goto after_2;
    // 0x80097720: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_2:
    // 0x80097724: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80097728: lwc1        $f0, 0x5C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8009772C: lwc1        $f4, 0x4E14($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X4E14);
    // 0x80097730: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80097734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80097738: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8009773C: nop

    // 0x80097740: bc1f        L_80097764
    if (!c1cs) {
        // 0x80097744: nop
    
            goto L_80097764;
    }
    // 0x80097744: nop

    // 0x80097748: lwc1        $f6, 0x4E18($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X4E18);
    // 0x8009774C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80097750: nop

    // 0x80097754: bc1f        L_80097764
    if (!c1cs) {
        // 0x80097758: nop
    
            goto L_80097764;
    }
    // 0x80097758: nop

    // 0x8009775C: b           L_80097844
    // 0x80097760: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80097844;
    // 0x80097760: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80097764:
    // 0x80097764: jal         0x8009C128
    // 0x80097768: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    func_8009C128(rdram, ctx);
        goto after_3;
    // 0x80097768: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    after_3:
    // 0x8009776C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80097770: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x80097774: jal         0x80095870
    // 0x80097778: addiu       $a2, $sp, 0x74
    ctx->r6 = ADD32(ctx->r29, 0X74);
    func_80095870(rdram, ctx);
        goto after_4;
    // 0x80097778: addiu       $a2, $sp, 0x74
    ctx->r6 = ADD32(ctx->r29, 0X74);
    after_4:
    // 0x8009777C: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80097780: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80097784: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80097788: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8009778C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80097790: jal         0x8009646C
    // 0x80097794: swc1        $f16, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f16.u32l;
    func_8009646C(rdram, ctx);
        goto after_5;
    // 0x80097794: swc1        $f16, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x80097798: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x8009779C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x800977A0: jal         0x800F0410
    // 0x800977A4: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    func_800F0410(rdram, ctx);
        goto after_6;
    // 0x800977A4: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    after_6:
    // 0x800977A8: lw          $a0, 0x98($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X98);
    // 0x800977AC: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x800977B0: jal         0x800EFB24
    // 0x800977B4: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    func_800EFB24(rdram, ctx);
        goto after_7;
    // 0x800977B4: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    after_7:
    // 0x800977B8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800977BC: lw          $t6, 0x98($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X98);
    // 0x800977C0: swc1        $f18, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f18.u32l;
    // 0x800977C4: jal         0x800EF2A0
    // 0x800977C8: lw          $a0, 0x98($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X98);
    func_800EF2A0(rdram, ctx);
        goto after_8;
    // 0x800977C8: lw          $a0, 0x98($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X98);
    after_8:
    // 0x800977CC: lw          $v0, 0x98($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X98);
    // 0x800977D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800977D4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800977D8: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800977DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800977E0: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x800977E4: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x800977E8: nop

    // 0x800977EC: bc1f        L_80097810
    if (!c1cs) {
        // 0x800977F0: nop
    
            goto L_80097810;
    }
    // 0x800977F0: nop

    // 0x800977F4: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800977F8: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x800977FC: nop

    // 0x80097800: bc1f        L_80097810
    if (!c1cs) {
        // 0x80097804: nop
    
            goto L_80097810;
    }
    // 0x80097804: nop

    // 0x80097808: b           L_80097844
    // 0x8009780C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80097844;
    // 0x8009780C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80097810:
    // 0x80097810: jal         0x8009C128
    // 0x80097814: sb          $t7, 0x24($v0)
    MEM_B(0X24, ctx->r2) = ctx->r15;
    func_8009C128(rdram, ctx);
        goto after_9;
    // 0x80097814: sb          $t7, 0x24($v0)
    MEM_B(0X24, ctx->r2) = ctx->r15;
    after_9:
    // 0x80097818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009781C: jal         0x800972BC
    // 0x80097820: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    func_800972BC(rdram, ctx);
        goto after_10;
    // 0x80097820: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    after_10:
    // 0x80097824: bnel        $v0, $zero, L_80097838
    if (ctx->r2 != 0) {
        // 0x80097828: lw          $a1, 0x98($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X98);
            goto L_80097838;
    }
    goto skip_0;
    // 0x80097828: lw          $a1, 0x98($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X98);
    skip_0:
    // 0x8009782C: b           L_80097844
    // 0x80097830: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80097844;
    // 0x80097830: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80097834: lw          $a1, 0x98($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X98);
L_80097838:
    // 0x80097838: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009783C: jal         0x800972BC
    // 0x80097840: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    func_800972BC(rdram, ctx);
        goto after_11;
    // 0x80097840: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    after_11:
L_80097844:
    // 0x80097844: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80097848: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009784C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x80097850: jr          $ra
    // 0x80097854: nop

    return;
    // 0x80097854: nop

;}
RECOMP_FUNC void ncba1p_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007D0: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x808007D4: jal         0x800EE7F8
    // 0x808007D8: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808007D8: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_0:
    // 0x808007DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007E4: jr          $ra
    // 0x808007E8: nop

    return;
    // 0x808007E8: nop

;}
