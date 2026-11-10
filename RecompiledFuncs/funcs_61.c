#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _bababykaz_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800844D8: syscall     112
    recomp_syscall_handler(rdram, ctx, 0x800844D8);
    return;
    // 0x800844DC: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void func_80800350_chtoothyfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800350: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800354: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800358: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080035C: addu        $t7, $a1, $a2
    ctx->r15 = ADD32(ctx->r5, ctx->r6);
    // 0x80800360: lbu         $t8, 0x39($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X39);
    // 0x80800364: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80800368: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x8080036C: slti        $at, $t8, 0x1E
    ctx->r1 = SIGNED(ctx->r24) < 0X1E ? 1 : 0;
    // 0x80800370: bne         $at, $zero, L_80800398
    if (ctx->r1 != 0) {
        // 0x80800374: nop
    
            goto L_80800398;
    }
    // 0x80800374: nop

    // 0x80800378: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8080037C: jal         0x80108B04
    // 0x80800380: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80108B04(rdram, ctx);
        goto after_0;
    // 0x80800380: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800384: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800388: lbu         $t0, 0x74($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X74);
    // 0x8080038C: ori         $t1, $t0, 0x20
    ctx->r9 = ctx->r8 | 0X20;
    // 0x80800390: b           L_808003C4
    // 0x80800394: sb          $t1, 0x74($a0)
    MEM_B(0X74, ctx->r4) = ctx->r9;
        goto L_808003C4;
    // 0x80800394: sb          $t1, 0x74($a0)
    MEM_B(0X74, ctx->r4) = ctx->r9;
L_80800398:
    // 0x80800398: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1776, 0X17AC) << 16);
    // 0x8080039C: addiu       $a2, $a2, 0x17AC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1776, 0X17AC));
    // 0x808003A0: jal         0x80089D18
    // 0x808003A4: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x808003A4: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x808003A8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x808003AC: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x808003B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808003B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808003B8: sll         $t3, $a3, 2
    ctx->r11 = S32(ctx->r7 << 2);
    // 0x808003BC: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x808003C0: swc1        $f4, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f4.u32l;
L_808003C4:
    // 0x808003C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003CC: jr          $ra
    // 0x808003D0: nop

    return;
    // 0x808003D0: nop

;}
RECOMP_FUNC void func_80111590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80111590: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80111594: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80111598: lw          $t6, 0x34($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X34);
    // 0x8011159C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x801115A0: swc1        $f12, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f12.u32l;
    // 0x801115A4: lw          $t7, 0x34($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X34);
    // 0x801115A8: swc1        $f14, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f14.u32l;
    // 0x801115AC: lw          $t8, 0x34($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X34);
    // 0x801115B0: lwc1        $f4, 0xC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC);
    // 0x801115B4: swc1        $f4, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f4.u32l;
    // 0x801115B8: lw          $t9, 0x34($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X34);
    // 0x801115BC: lwc1        $f6, 0x10($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X10);
    // 0x801115C0: jr          $ra
    // 0x801115C4: swc1        $f6, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f6.u32l;
    return;
    // 0x801115C4: swc1        $f6, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f6.u32l;
;}
RECOMP_FUNC void _sumissilehome_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A790: syscall     850
    recomp_syscall_handler(rdram, ctx, 0x8008A790);
    return;
    // 0x8008A794: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _bsrest_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083950: syscall     84
    recomp_syscall_handler(rdram, ctx, 0x80083950);
    return;
    // 0x80083954: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800C6060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6060: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800C6064: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C6068: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C606C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C6070: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x800C6074: addiu       $a1, $s0, 0x4C
    ctx->r5 = ADD32(ctx->r16, 0X4C);
    // 0x800C6078: jal         0x800EE7F8
    // 0x800C607C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800C607C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_0:
    // 0x800C6080: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800C6084: addiu       $a0, $zero, 0x6B5
    ctx->r4 = ADD32(0, 0X6B5);
    // 0x800C6088: jal         0x800DA298
    // 0x800C608C: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x800C608C: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x800C6090: beq         $v0, $zero, L_800C60FC
    if (ctx->r2 == 0) {
        // 0x800C6094: lui         $at, 0x4316
        ctx->r1 = S32(0X4316 << 16);
            goto L_800C60FC;
    }
    // 0x800C6094: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x800C6098: lwc1        $f6, 0x5C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x800C609C: lwc1        $f8, 0x50($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800C60A0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800C60A4: jal         0x800F0E00
    // 0x800C60A8: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    func_800F0E00(rdram, ctx);
        goto after_2;
    // 0x800C60A8: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    after_2:
    // 0x800C60AC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800C60B0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C60B4: lw          $a3, 0x88($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X88);
    // 0x800C60B8: addiu       $t6, $sp, 0x48
    ctx->r14 = ADD32(ctx->r29, 0X48);
    // 0x800C60BC: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x800C60C0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800C60C4: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x800C60C8: lui         $a2, 0xC0A0
    ctx->r6 = S32(0XC0A0 << 16);
    // 0x800C60CC: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x800C60D0: jal         0x800C5CC0
    // 0x800C60D4: nop

    func_800C5CC0(rdram, ctx);
        goto after_3;
    // 0x800C60D4: nop

    after_3:
    // 0x800C60D8: bne         $v0, $zero, L_800C60E8
    if (ctx->r2 != 0) {
        // 0x800C60DC: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800C60E8;
    }
    // 0x800C60DC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800C60E0: lbu         $t7, 0x9C($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X9C);
    // 0x800C60E4: beq         $t7, $zero, L_800C60FC
    if (ctx->r15 == 0) {
        // 0x800C60E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800C60FC;
    }
L_800C60E8:
    // 0x800C60E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C60EC: jal         0x800C5FCC
    // 0x800C60F0: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    func_800C5FCC(rdram, ctx);
        goto after_4;
    // 0x800C60F0: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_4:
    // 0x800C60F4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800C60F8: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
L_800C60FC:
    // 0x800C60FC: lui         $a2, 0xC4A2
    ctx->r6 = S32(0XC4A2 << 16);
    // 0x800C6100: lw          $a3, 0x84($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X84);
    // 0x800C6104: addiu       $t9, $sp, 0x48
    ctx->r25 = ADD32(ctx->r29, 0X48);
    // 0x800C6108: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800C610C: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x800C6110: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x800C6114: jal         0x800C5CC0
    // 0x800C6118: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    func_800C5CC0(rdram, ctx);
        goto after_5;
    // 0x800C6118: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    after_5:
    // 0x800C611C: bne         $v0, $zero, L_800C6174
    if (ctx->r2 != 0) {
        // 0x800C6120: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800C6174;
    }
    // 0x800C6120: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800C6124: jal         0x800C5F8C
    // 0x800C6128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C5F8C(rdram, ctx);
        goto after_6;
    // 0x800C6128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x800C612C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800C6130: bnel        $t0, $zero, L_800C614C
    if (ctx->r8 != 0) {
        // 0x800C6134: lwc1        $f18, 0x50($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X50);
            goto L_800C614C;
    }
    goto skip_0;
    // 0x800C6134: lwc1        $f18, 0x50($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X50);
    skip_0:
    // 0x800C6138: jal         0x800C6038
    // 0x800C613C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C6038(rdram, ctx);
        goto after_7;
    // 0x800C613C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x800C6140: b           L_800C6310
    // 0x800C6144: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800C6310;
    // 0x800C6144: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C6148: lwc1        $f18, 0x50($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X50);
L_800C614C:
    // 0x800C614C: lwc1        $f4, 0x74($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X74);
    // 0x800C6150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C6154: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x800C6158: nop

    // 0x800C615C: bc1fl       L_800C6310
    if (!c1cs) {
        // 0x800C6160: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800C6310;
    }
    goto skip_1;
    // 0x800C6160: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x800C6164: jal         0x800C5A10
    // 0x800C6168: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800C5A10(rdram, ctx);
        goto after_8;
    // 0x800C6168: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_8:
    // 0x800C616C: b           L_800C6310
    // 0x800C6170: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800C6310;
    // 0x800C6170: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C6174:
    // 0x800C6174: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x800C6178: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x800C617C: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x800C6180: and         $t1, $v1, $at
    ctx->r9 = ctx->r3 & ctx->r1;
    // 0x800C6184: beq         $t1, $zero, L_800C6240
    if (ctx->r9 == 0) {
        // 0x800C6188: lwc1        $f18, 0x4C($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
            goto L_800C6240;
    }
    // 0x800C6188: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800C618C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C6190: jal         0x800C5FCC
    // 0x800C6194: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    func_800C5FCC(rdram, ctx);
        goto after_9;
    // 0x800C6194: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_9:
    // 0x800C6198: lwc1        $f0, 0x74($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X74);
    // 0x800C619C: lwc1        $f6, 0x70($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X70);
    // 0x800C61A0: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800C61A4: nop

    // 0x800C61A8: bc1fl       L_800C61D4
    if (!c1cs) {
        // 0x800C61AC: lw          $a3, 0x84($s0)
        ctx->r7 = MEM_W(ctx->r16, 0X84);
            goto L_800C61D4;
    }
    goto skip_2;
    // 0x800C61AC: lw          $a3, 0x84($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X84);
    skip_2:
    // 0x800C61B0: lwc1        $f8, 0x50($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800C61B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C61B8: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x800C61BC: nop

    // 0x800C61C0: bc1fl       L_800C61D4
    if (!c1cs) {
        // 0x800C61C4: lw          $a3, 0x84($s0)
        ctx->r7 = MEM_W(ctx->r16, 0X84);
            goto L_800C61D4;
    }
    goto skip_3;
    // 0x800C61C4: lw          $a3, 0x84($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X84);
    skip_3:
    // 0x800C61C8: jal         0x800C5A10
    // 0x800C61CC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800C5A10(rdram, ctx);
        goto after_10;
    // 0x800C61CC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_10:
    // 0x800C61D0: lw          $a3, 0x84($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X84);
L_800C61D4:
    // 0x800C61D4: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x800C61D8: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x800C61DC: addiu       $t3, $sp, 0x48
    ctx->r11 = ADD32(ctx->r29, 0X48);
    // 0x800C61E0: or          $t2, $a3, $at
    ctx->r10 = ctx->r7 | ctx->r1;
    // 0x800C61E4: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
    // 0x800C61E8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800C61EC: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x800C61F0: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x800C61F4: jal         0x800C5CC0
    // 0x800C61F8: lui         $a2, 0xC3E1
    ctx->r6 = S32(0XC3E1 << 16);
    func_800C5CC0(rdram, ctx);
        goto after_11;
    // 0x800C61F8: lui         $a2, 0xC3E1
    ctx->r6 = S32(0XC3E1 << 16);
    after_11:
    // 0x800C61FC: bne         $v0, $zero, L_800C6214
    if (ctx->r2 != 0) {
        // 0x800C6200: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800C6214;
    }
    // 0x800C6200: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800C6204: jal         0x800C5F8C
    // 0x800C6208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C5F8C(rdram, ctx);
        goto after_12;
    // 0x800C6208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x800C620C: b           L_800C6310
    // 0x800C6210: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800C6310;
    // 0x800C6210: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C6214:
    // 0x800C6214: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800C6218: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800C621C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C6220: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x800C6224: nop

    // 0x800C6228: bc1fl       L_800C6310
    if (!c1cs) {
        // 0x800C622C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800C6310;
    }
    goto skip_4;
    // 0x800C622C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x800C6230: jal         0x800C5F40
    // 0x800C6234: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_800C5F40(rdram, ctx);
        goto after_13;
    // 0x800C6234: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_13:
    // 0x800C6238: b           L_800C6310
    // 0x800C623C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800C6310;
    // 0x800C623C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C6240:
    // 0x800C6240: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C6244: sll         $t4, $v1, 15
    ctx->r12 = S32(ctx->r3 << 15);
    // 0x800C6248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C624C: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x800C6250: nop

    // 0x800C6254: bc1f        L_800C62DC
    if (!c1cs) {
        // 0x800C6258: nop
    
            goto L_800C62DC;
    }
    // 0x800C6258: nop

    // 0x800C625C: bltz        $t4, L_800C62DC
    if (SIGNED(ctx->r12) < 0) {
        // 0x800C6260: lwc1        $f6, 0x54($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
            goto L_800C62DC;
    }
    // 0x800C6260: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800C6264: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C6268: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C626C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C6270: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800C6274: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C6278: lwc1        $f18, 0x58A8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X58A8);
    // 0x800C627C: lw          $a3, 0x84($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X84);
    // 0x800C6280: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800C6284: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x800C6288: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x800C628C: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x800C6290: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x800C6294: addiu       $t6, $sp, 0x48
    ctx->r14 = ADD32(ctx->r29, 0X48);
    // 0x800C6298: or          $t5, $a3, $at
    ctx->r13 = ctx->r7 | ctx->r1;
    // 0x800C629C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800C62A0: or          $a3, $t5, $zero
    ctx->r7 = ctx->r13 | 0;
    // 0x800C62A4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800C62A8: jal         0x800C5CC0
    // 0x800C62AC: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    func_800C5CC0(rdram, ctx);
        goto after_14;
    // 0x800C62AC: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_14:
    // 0x800C62B0: beq         $v0, $zero, L_800C62CC
    if (ctx->r2 == 0) {
        // 0x800C62B4: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800C62CC;
    }
    // 0x800C62B4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800C62B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C62BC: jal         0x800C5F40
    // 0x800C62C0: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_800C5F40(rdram, ctx);
        goto after_15;
    // 0x800C62C0: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_15:
    // 0x800C62C4: b           L_800C6310
    // 0x800C62C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800C6310;
    // 0x800C62C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C62CC:
    // 0x800C62CC: jal         0x800C5F8C
    // 0x800C62D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C5F8C(rdram, ctx);
        goto after_16;
    // 0x800C62D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x800C62D4: b           L_800C6310
    // 0x800C62D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800C6310;
    // 0x800C62D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C62DC:
    // 0x800C62DC: jal         0x800C5F40
    // 0x800C62E0: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_800C5F40(rdram, ctx);
        goto after_17;
    // 0x800C62E0: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_17:
    // 0x800C62E4: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800C62E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C62EC: beq         $t7, $zero, L_800C6304
    if (ctx->r15 == 0) {
        // 0x800C62F0: nop
    
            goto L_800C6304;
    }
    // 0x800C62F0: nop

    // 0x800C62F4: jal         0x800C5A10
    // 0x800C62F8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800C5A10(rdram, ctx);
        goto after_18;
    // 0x800C62F8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_18:
    // 0x800C62FC: b           L_800C6310
    // 0x800C6300: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800C6310;
    // 0x800C6300: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C6304:
    // 0x800C6304: jal         0x800C6038
    // 0x800C6308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C6038(rdram, ctx);
        goto after_19;
    // 0x800C6308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x800C630C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C6310:
    // 0x800C6310: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C6314: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x800C6318: jr          $ra
    // 0x800C631C: nop

    return;
    // 0x800C631C: nop

;}
RECOMP_FUNC void chpawnbroker_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1012, 0X1018) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x1018
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1012, 0X1018));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x1018
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1012, 0X1018));
;}
RECOMP_FUNC void func_800AF5D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF5D8: lh          $t6, 0x12($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X12);
    // 0x800AF5DC: jr          $ra
    // 0x800AF5E0: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    return;
    // 0x800AF5E0: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
;}
RECOMP_FUNC void func_8080019C_chfactorystationdoors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080019C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001A4: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x808001A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001B0: bne         $a1, $at, L_80800218
    if (ctx->r5 != ctx->r1) {
        // 0x808001B4: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80800218;
    }
    // 0x808001B4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808001B8: jal         0x80088840
    // 0x808001BC: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_0;
    // 0x808001BC: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    after_0:
    // 0x808001C0: beq         $v0, $zero, L_80800218
    if (ctx->r2 == 0) {
        // 0x808001C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800218;
    }
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C8: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808001CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808001D0: jal         0x80101FDC
    // 0x808001D4: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x808001D4: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    after_1:
    // 0x808001D8: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x808001DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001E0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808001E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808001E8: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808001EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808001F0: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x808001F4: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x808001F8: addiu       $a3, $zero, 0x900
    ctx->r7 = ADD32(0, 0X900);
    // 0x808001FC: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    // 0x80800200: bc1f        L_80800210
    if (!c1cs) {
        // 0x80800204: nop
    
            goto L_80800210;
    }
    // 0x80800204: nop

    // 0x80800208: jal         0x80085708
    // 0x8080020C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_2;
    // 0x8080020C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_2:
L_80800210:
    // 0x80800210: b           L_8080021C
    // 0x80800214: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080021C;
    // 0x80800214: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800218:
    // 0x80800218: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080021C:
    // 0x8080021C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800220: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800224: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800228: jr          $ra
    // 0x8080022C: nop

    return;
    // 0x8080022C: nop

;}
RECOMP_FUNC void func_8080183C_bsbfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080183C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801840: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801844: jal         0x800A4E30
    // 0x80801848: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800A4E30(rdram, ctx);
        goto after_0;
    // 0x80801848: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080184C: jal         0x800A042C
    // 0x80801850: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A042C(rdram, ctx);
        goto after_1;
    // 0x80801850: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801854: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801858: jal         0x800A0CF4
    // 0x8080185C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_2;
    // 0x8080185C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80801860: jal         0x8008E95C
    // 0x80801864: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008E95C(rdram, ctx);
        goto after_3;
    // 0x80801864: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80801868: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080186C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801870: jr          $ra
    // 0x80801874: nop

    return;
    // 0x80801874: nop

;}
RECOMP_FUNC void chstatictorch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800210: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1712, 0X248) << 16);
    // 0x80800214: jr          $ra
    // 0x80800218: addiu       $v0, $v0, 0x248
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1712, 0X248));
    return;
    // 0x80800218: addiu       $v0, $v0, 0x248
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1712, 0X248));
    // 0x8080021C: nop

;}
RECOMP_FUNC void func_800F4A00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F4A00: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F4A04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F4A08: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F4A0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F4A10: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F4A14: jal         0x80084848
    // 0x800F4A18: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    _badrone_entrypoint_12(rdram, ctx);
        goto after_0;
    // 0x800F4A18: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F4A1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F4A20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F4A24: jr          $ra
    // 0x800F4A28: nop

    return;
    // 0x800F4A28: nop

;}
RECOMP_FUNC void func_800F6F00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F6F00: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800F6F04: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800F6F08: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800F6F0C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F6F10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F6F14: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x800F6F18: jal         0x800846B0
    // 0x800F6F1C: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    _badata_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x800F6F1C: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F6F20: bne         $v0, $zero, L_800F6F30
    if (ctx->r2 != 0) {
        // 0x800F6F24: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_800F6F30;
    }
    // 0x800F6F24: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800F6F28: b           L_800F7008
    // 0x800F6F2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800F7008;
    // 0x800F6F2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F6F30:
    // 0x800F6F30: jal         0x800F58CC
    // 0x800F6F34: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800F58CC(rdram, ctx);
        goto after_1;
    // 0x800F6F34: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_1:
    // 0x800F6F38: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800F6F3C: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800F6F40: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800F6F44: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x800F6F48: nop

    // 0x800F6F4C: bc1f        L_800F6F64
    if (!c1cs) {
        // 0x800F6F50: nop
    
            goto L_800F6F64;
    }
    // 0x800F6F50: nop

    // 0x800F6F54: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x800F6F58: nop

    // 0x800F6F5C: bc1t        L_800F6F6C
    if (c1cs) {
        // 0x800F6F60: nop
    
            goto L_800F6F6C;
    }
    // 0x800F6F60: nop

L_800F6F64:
    // 0x800F6F64: b           L_800F7008
    // 0x800F6F68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F7008;
    // 0x800F6F68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F6F6C:
    // 0x800F6F6C: jal         0x800F6C5C
    // 0x800F6F70: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800F6C5C(rdram, ctx);
        goto after_2;
    // 0x800F6F70: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x800F6F74: bne         $v0, $zero, L_800F6F84
    if (ctx->r2 != 0) {
        // 0x800F6F78: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_800F6F84;
    }
    // 0x800F6F78: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800F6F7C: b           L_800F7008
    // 0x800F6F80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F7008;
    // 0x800F6F80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F6F84:
    // 0x800F6F84: jal         0x800F5D70
    // 0x800F6F88: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_800F5D70(rdram, ctx);
        goto after_3;
    // 0x800F6F88: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_3:
    // 0x800F6F8C: jal         0x800F55FC
    // 0x800F6F90: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800F55FC(rdram, ctx);
        goto after_4;
    // 0x800F6F90: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_4:
    // 0x800F6F94: andi        $t8, $v0, 0x8000
    ctx->r24 = ctx->r2 & 0X8000;
    // 0x800F6F98: beq         $t8, $zero, L_800F6FE4
    if (ctx->r24 == 0) {
        // 0x800F6F9C: lwc1        $f0, 0x24($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
            goto L_800F6FE4;
    }
    // 0x800F6F9C: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800F6FA0: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800F6FA4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800F6FA8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800F6FAC: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x800F6FB0: nop

    // 0x800F6FB4: bc1f        L_800F6FDC
    if (!c1cs) {
        // 0x800F6FB8: nop
    
            goto L_800F6FDC;
    }
    // 0x800F6FB8: nop

    // 0x800F6FBC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800F6FC0: nop

    // 0x800F6FC4: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x800F6FC8: nop

    // 0x800F6FCC: bc1f        L_800F6FDC
    if (!c1cs) {
        // 0x800F6FD0: nop
    
            goto L_800F6FDC;
    }
    // 0x800F6FD0: nop

    // 0x800F6FD4: b           L_800F7008
    // 0x800F6FD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800F7008;
    // 0x800F6FD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F6FDC:
    // 0x800F6FDC: b           L_800F7008
    // 0x800F6FE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F7008;
    // 0x800F6FE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F6FE4:
    // 0x800F6FE4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800F6FE8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800F6FEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F6FF0: c.eq.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl == ctx->f0.fl;
    // 0x800F6FF4: nop

    // 0x800F6FF8: bc1t        L_800F7008
    if (c1cs) {
        // 0x800F6FFC: nop
    
            goto L_800F7008;
    }
    // 0x800F6FFC: nop

    // 0x800F7000: b           L_800F7008
    // 0x800F7004: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F7008;
    // 0x800F7004: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F7008:
    // 0x800F7008: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F700C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800F7010: jr          $ra
    // 0x800F7014: nop

    return;
    // 0x800F7014: nop

;}
RECOMP_FUNC void baflameline_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003E4: jal         0x800EE7F8
    // 0x808003E8: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808003E8: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x808003EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003F4: jr          $ra
    // 0x808003F8: nop

    return;
    // 0x808003F8: nop

;}
RECOMP_FUNC void func_800136D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800136D0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800136D4: lwc1        $f0, 0x16B0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X16B0);
    // 0x800136D8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800136DC: b           L_800136F8
    // 0x800136E0: lwc1        $f2, 0x16B4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X16B4);
        goto L_800136F8;
    // 0x800136E0: lwc1        $f2, 0x16B4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X16B4);
    // 0x800136E4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800136E8: lwc1        $f0, 0x16B8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X16B8);
    // 0x800136EC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800136F0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800136F4: nop

L_800136F8:
    // 0x800136F8: mul.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800136FC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80013700: trunc.w.s   $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80013704: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80013708: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8001370C: sub.s       $f0, $f12, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x80013710: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80013714: bc1f        L_80013720
    if (!c1cs) {
        // 0x80013718: nop
    
            goto L_80013720;
    }
    // 0x80013718: nop

    // 0x8001371C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
L_80013720:
    // 0x80013720: jr          $ra
    // 0x80013724: nop

    return;
    // 0x80013724: nop

;}
RECOMP_FUNC void func_800A91A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A91A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A91AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A91B0: bltz        $a0, L_800A91E4
    if (SIGNED(ctx->r4) < 0) {
        // 0x800A91B4: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_800A91E4;
    }
    // 0x800A91B4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800A91B8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A91BC: addiu       $v0, $v0, 0x76D0
    ctx->r2 = ADD32(ctx->r2, 0X76D0);
    // 0x800A91C0: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x800A91C4: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800A91C8: lh          $a0, 0x8($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X8);
    // 0x800A91CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A91D0: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x800A91D4: beq         $a0, $at, L_800A91E4
    if (ctx->r4 == ctx->r1) {
        // 0x800A91D8: addu        $t9, $v0, $t8
        ctx->r25 = ADD32(ctx->r2, ctx->r24);
            goto L_800A91E4;
    }
    // 0x800A91D8: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x800A91DC: jal         0x800A88C4
    // 0x800A91E0: lw          $a1, 0x38($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X38);
    func_800A88C4(rdram, ctx);
        goto after_0;
    // 0x800A91E0: lw          $a1, 0x38($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X38);
    after_0:
L_800A91E4:
    // 0x800A91E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A91E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A91EC: jr          $ra
    // 0x800A91F0: nop

    return;
    // 0x800A91F0: nop

;}
RECOMP_FUNC void gsmaker_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800250: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800254: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800258: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8080025C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800260: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80800264: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80800268: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8080026C: blez        $a2, L_8080028C
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80800270: sw          $ra, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r31;
            goto L_8080028C;
    }
    // 0x80800270: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
L_80800274:
    // 0x80800274: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800278: jal         0x80800230
    // 0x8080027C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    gsmaker_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x8080027C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x80800280: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80800284: bgtz        $s0, L_80800274
    if (SIGNED(ctx->r16) > 0) {
        // 0x80800288: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80800274;
    }
    // 0x80800288: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8080028C:
    // 0x8080028C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800290: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800294: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800298: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8080029C: jr          $ra
    // 0x808002A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808002A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void bsrest_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808005FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800600: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800604: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800608: jal         0x808000E4
    // 0x8080060C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    static_344_808000E4(rdram, ctx);
        goto after_0;
    // 0x8080060C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80800610: jal         0x8008E35C
    // 0x80800614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_1;
    // 0x80800614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800618: beq         $v0, $zero, L_80800624
    if (ctx->r2 == 0) {
        // 0x8080061C: addiu       $t6, $zero, 0x77
        ctx->r14 = ADD32(0, 0X77);
            goto L_80800624;
    }
    // 0x8080061C: addiu       $t6, $zero, 0x77
    ctx->r14 = ADD32(0, 0X77);
    // 0x80800620: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800624:
    // 0x80800624: jal         0x8080032C
    // 0x80800628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    static_344_8080032C(rdram, ctx);
        goto after_2;
    // 0x80800628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080062C: beql        $v0, $zero, L_80800644
    if (ctx->r2 == 0) {
        // 0x80800630: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800644;
    }
    goto skip_0;
    // 0x80800630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800634: jal         0x8080069C
    // 0x80800638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bsrest_entrypoint_13(rdram, ctx);
        goto after_3;
    // 0x80800638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080063C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800640: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800644:
    // 0x80800644: jal         0x8009E5C8
    // 0x80800648: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_4;
    // 0x80800648: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x8080064C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800650: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800654: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800658: jr          $ra
    // 0x8080065C: nop

    return;
    // 0x8080065C: nop

;}
RECOMP_FUNC void func_80800B18_chbanjoctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B18: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800B1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800B20: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800B24: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x80800B28: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800B2C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800B30: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800B34: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80800B38: bgez        $t7, L_80800B4C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80800B3C: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80800B4C;
    }
    // 0x80800B3C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800B40: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800B44: nop

    // 0x80800B48: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_80800B4C:
    // 0x80800B4C: jal         0x800F54E4
    // 0x80800B50: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800B50: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80800B54: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x80800B58: jal         0x800F5410
    // 0x80800B5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5410(rdram, ctx);
        goto after_1;
    // 0x80800B5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800B60: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800B64: beq         $v0, $at, L_80800CF0
    if (ctx->r2 == ctx->r1) {
        // 0x80800B68: lwc1        $f0, 0x4C($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X4C);
            goto L_80800CF0;
    }
    // 0x80800B68: lwc1        $f0, 0x4C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80800B6C: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800B70: lwc1        $f2, 0x18($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80800B74: sub.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x80800B78: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x80800B7C: nop

    // 0x80800B80: bc1tl       L_80800CF4
    if (c1cs) {
        // 0x80800B84: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800CF4;
    }
    goto skip_0;
    // 0x80800B84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800B88: add.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x80800B8C: c.le.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl <= ctx->f2.fl;
    // 0x80800B90: nop

    // 0x80800B94: bc1tl       L_80800CF4
    if (c1cs) {
        // 0x80800B98: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800CF4;
    }
    goto skip_1;
    // 0x80800B98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800B9C: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800BA0: lwc1        $f2, 0x1C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80800BA4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800BA8: sub.s       $f16, $f12, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x80800BAC: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x80800BB0: nop

    // 0x80800BB4: bc1tl       L_80800CF4
    if (c1cs) {
        // 0x80800BB8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800CF4;
    }
    goto skip_2;
    // 0x80800BB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80800BBC: add.s       $f18, $f12, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x80800BC0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800BC4: nop

    // 0x80800BC8: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80800BCC: c.le.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl <= ctx->f2.fl;
    // 0x80800BD0: nop

    // 0x80800BD4: bc1tl       L_80800CF4
    if (c1cs) {
        // 0x80800BD8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800CF4;
    }
    goto skip_3;
    // 0x80800BD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80800BDC: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80800BE0: lwc1        $f2, 0x20($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80800BE4: sub.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x80800BE8: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x80800BEC: nop

    // 0x80800BF0: bc1tl       L_80800CF4
    if (c1cs) {
        // 0x80800BF4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800CF4;
    }
    goto skip_4;
    // 0x80800BF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80800BF8: add.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x80800BFC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800C00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800C04: c.le.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl <= ctx->f2.fl;
    // 0x80800C08: nop

    // 0x80800C0C: bc1tl       L_80800CF4
    if (c1cs) {
        // 0x80800C10: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800CF4;
    }
    goto skip_5;
    // 0x80800C10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x80800C14: jal         0x800F7E3C
    // 0x80800C18: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    func_800F7E3C(rdram, ctx);
        goto after_2;
    // 0x80800C18: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80800C1C: lwc1        $f0, 0x4C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80800C20: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800C24: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80800C28: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    // 0x80800C2C: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x80800C30: lw          $a3, 0x20($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X20);
    // 0x80800C34: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80800C38: jal         0x800EFA4C
    // 0x80800C3C: nop

    func_800EFA4C(rdram, ctx);
        goto after_3;
    // 0x80800C3C: nop

    after_3:
    // 0x80800C40: lwc1        $f0, 0x4C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80800C44: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800C48: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800C4C: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80800C50: sub.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80800C54: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x80800C58: nop

    // 0x80800C5C: bc1fl       L_80800C70
    if (!c1cs) {
        // 0x80800C60: lwc1        $f16, 0xC($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
            goto L_80800C70;
    }
    goto skip_6;
    // 0x80800C60: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    skip_6:
    // 0x80800C64: add.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80800C68: sub.s       $f14, $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f10.fl;
    // 0x80800C6C: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
L_80800C70:
    // 0x80800C70: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800C74: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x80800C78: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x80800C7C: sub.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80800C80: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80800C84: nop

    // 0x80800C88: bc1fl       L_80800C9C
    if (!c1cs) {
        // 0x80800C8C: swc1        $f2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
            goto L_80800C9C;
    }
    goto skip_7;
    // 0x80800C8C: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    skip_7:
    // 0x80800C90: add.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80800C94: sub.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x80800C98: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
L_80800C9C:
    // 0x80800C9C: jal         0x800F2100
    // 0x80800CA0: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    mlAbsF(rdram, ctx);
        goto after_4;
    // 0x80800CA0: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    after_4:
    // 0x80800CA4: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800CA8: jal         0x800F2100
    // 0x80800CAC: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    mlAbsF(rdram, ctx);
        goto after_5;
    // 0x80800CAC: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    after_5:
    // 0x80800CB0: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800CB4: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800CB8: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800CBC: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80800CC0: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800CC4: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800CC8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80800CCC: bc1fl       L_80800CE4
    if (!c1cs) {
        // 0x80800CD0: add.s       $f6, $f18, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
            goto L_80800CE4;
    }
    goto skip_8;
    // 0x80800CD0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    skip_8:
    // 0x80800CD4: add.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x80800CD8: b           L_80800CE8
    // 0x80800CDC: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
        goto L_80800CE8;
    // 0x80800CDC: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    // 0x80800CE0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
L_80800CE4:
    // 0x80800CE4: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
L_80800CE8:
    // 0x80800CE8: jal         0x800F7814
    // 0x80800CEC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_800F7814(rdram, ctx);
        goto after_6;
    // 0x80800CEC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_6:
L_80800CF0:
    // 0x80800CF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800CF4:
    // 0x80800CF4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800CF8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800CFC: jr          $ra
    // 0x80800D00: nop

    return;
    // 0x80800D00: nop

;}
RECOMP_FUNC void func_80800000_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: addiu       $a0, $zero, 0xA4C
    ctx->r4 = ADD32(0, 0XA4C);
    // 0x8080000C: jal         0x800DA564
    // 0x80800010: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DA564(rdram, ctx);
        goto after_0;
    // 0x80800010: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x80800014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800018: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080001C: jr          $ra
    // 0x80800020: nop

    return;
    // 0x80800020: nop

;}
RECOMP_FUNC void func_8080087C_chheggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080087C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800880: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800884: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800888: lw          $t7, 0x28($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X28);
    // 0x8080088C: beql        $t7, $zero, L_808008B8
    if (ctx->r15 == 0) {
        // 0x80800890: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808008B8;
    }
    goto skip_0;
    // 0x80800890: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800894: jal         0x800DA298
    // 0x80800898: addiu       $a0, $zero, 0x64B
    ctx->r4 = ADD32(0, 0X64B);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800898: addiu       $a0, $zero, 0x64B
    ctx->r4 = ADD32(0, 0X64B);
    after_0:
    // 0x8080089C: beql        $v0, $zero, L_808008B8
    if (ctx->r2 == 0) {
        // 0x808008A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808008B8;
    }
    goto skip_1;
    // 0x808008A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808008A4: jal         0x800856B8
    // 0x808008A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _capod_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808008A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x808008AC: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x808008B0: sw          $zero, 0x28($t8)
    MEM_W(0X28, ctx->r24) = 0;
    // 0x808008B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808008B8:
    // 0x808008B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008BC: jr          $ra
    // 0x808008C0: nop

    return;
    // 0x808008C0: nop

;}
RECOMP_FUNC void func_8080115C_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080115C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801160: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80801164: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x80801168: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8080116C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80801170: jal         0x800D8FF8
    // 0x80801174: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80801174: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801178: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080117C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801180: jal         0x80016B30
    // 0x80801184: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    func_80016B30(rdram, ctx);
        goto after_1;
    // 0x80801184: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80801188: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8080118C: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80801190: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80801194: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80801198: nop

    // 0x8080119C: bc1f        L_80801200
    if (!c1cs) {
        // 0x808011A0: nop
    
            goto L_80801200;
    }
    // 0x808011A0: nop

    // 0x808011A4: beq         $v0, $zero, L_808011E4
    if (ctx->r2 == 0) {
        // 0x808011A8: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_808011E4;
    }
    // 0x808011A8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x808011AC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808011B0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x808011B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808011B8: lui         $a2, 0xBC23
    ctx->r6 = S32(0XBC23 << 16);
    // 0x808011BC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808011C0: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x808011C4: jal         0x800F10B4
    // 0x808011C8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x808011C8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x808011CC: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
    // 0x808011D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X4460) << 16);
    // 0x808011D4: lwc1        $f6, 0x4460($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1632, 0X4460));
    // 0x808011D8: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    // 0x808011DC: b           L_8080127C
    // 0x808011E0: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
        goto L_8080127C;
    // 0x808011E0: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
L_808011E4:
    // 0x808011E4: sub.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x808011E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X4464) << 16);
    // 0x808011EC: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    // 0x808011F0: lwc1        $f10, 0x4464($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1632, 0X4464));
    tooie_frame_factor(rdram, &ctx->f10.fl, 0);
    // 0x808011F4: mul.s       $f20, $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x808011F8: b           L_8080125C
    // 0x808011FC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
        goto L_8080125C;
    // 0x808011FC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
L_80801200:
    // 0x80801200: bne         $v0, $zero, L_80801240
    if (ctx->r2 != 0) {
        // 0x80801204: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80801240;
    }
    // 0x80801204: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801208: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080120C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80801210: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801214: lui         $a2, 0x3C23
    ctx->r6 = S32(0X3C23 << 16);
    // 0x80801218: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8080121C: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x80801220: jal         0x800F10B4
    // 0x80801224: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x80801224: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x80801228: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
    // 0x8080122C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X4468) << 16);
    // 0x80801230: lwc1        $f18, 0x4468($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1632, 0X4468));
    // 0x80801234: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    // 0x80801238: b           L_8080127C
    // 0x8080123C: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
        goto L_8080127C;
    // 0x8080123C: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
L_80801240:
    // 0x80801240: add.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x80801244: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X446C) << 16);
    // 0x80801248: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x8080124C: lwc1        $f6, 0x446C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1632, 0X446C));
    tooie_frame_factor(rdram, &ctx->f6.fl, 0);
    // 0x80801250: mul.s       $f20, $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x80801254: nop

    // 0x80801258: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
L_8080125C:
    // 0x8080125C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80801260: nop

    // 0x80801264: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80801268: nop

    // 0x8080126C: bc1fl       L_8080127C
    if (!c1cs) {
        // 0x80801270: mov.s       $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
            goto L_8080127C;
    }
    goto skip_0;
    // 0x80801270: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    skip_0:
    // 0x80801274: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80801278: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
L_8080127C:
    // 0x8080127C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80801280: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80801284: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80801288: jr          $ra
    // 0x8080128C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8080128C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void chblink_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800008: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080000C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800010: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800014: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800018: jal         0x800DC178
    // 0x8080001C: sw          $a1, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r5;
    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x8080001C: sw          $a1, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r5;
    after_0:
    // 0x80800020: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800024: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800028: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x8080002C: jal         0x800DC128
    // 0x80800030: swc1        $f0, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f0.u32l;
    func_800DC128(rdram, ctx);
        goto after_1;
    // 0x80800030: swc1        $f0, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f0.u32l;
    after_1:
    // 0x80800034: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80800038: sw          $v0, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->r2;
    // 0x8080003C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800040: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800044: jr          $ra
    // 0x80800048: nop

    return;
    // 0x80800048: nop

;}
RECOMP_FUNC void func_800E7F40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E7F40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E7F44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E7F48: jal         0x80014DD4
    // 0x800E7F4C: nop

    func_80014DD4(rdram, ctx);
        goto after_0;
    // 0x800E7F4C: nop

    after_0:
    // 0x800E7F50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E7F54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E7F58: jr          $ra
    // 0x800E7F5C: nop

    return;
    // 0x800E7F5C: nop

;}
RECOMP_FUNC void bscrashout_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003A8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808003AC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(148, 0X3D0) << 16);
    // 0x808003B0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808003B4: jr          $ra
    // 0x808003B8: lw          $v0, 0x3D0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(148, 0X3D0));
    return;
    // 0x808003B8: lw          $v0, 0x3D0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(148, 0X3D0));
    // 0x808003BC: nop

;}
RECOMP_FUNC void func_80800260_chfactoryworkerwear(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800260: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800264: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800268: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8080026C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x80800270: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800274: jal         0x80100094
    // 0x80800278: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800278: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080027C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80800280: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800284: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800288: beq         $a2, $at, L_808002AC
    if (ctx->r6 == ctx->r1) {
        // 0x8080028C: sb          $a2, 0x24($v0)
        MEM_B(0X24, ctx->r2) = ctx->r6;
            goto L_808002AC;
    }
    // 0x8080028C: sb          $a2, 0x24($v0)
    MEM_B(0X24, ctx->r2) = ctx->r6;
    // 0x80800290: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800294: beq         $a2, $at, L_808002BC
    if (ctx->r6 == ctx->r1) {
        // 0x80800298: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808002BC;
    }
    // 0x80800298: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080029C: beq         $a2, $at, L_808002CC
    if (ctx->r6 == ctx->r1) {
        // 0x808002A0: nop
    
            goto L_808002CC;
    }
    // 0x808002A0: nop

    // 0x808002A4: b           L_808002D8
    // 0x808002A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808002D8;
    // 0x808002A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002AC:
    // 0x808002AC: jal         0x8080000C
    // 0x808002B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8080000C_chfactoryworkerwear(rdram, ctx);
        goto after_1;
    // 0x808002B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x808002B4: b           L_808002D8
    // 0x808002B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808002D8;
    // 0x808002B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002BC:
    // 0x808002BC: jal         0x8080000C
    // 0x808002C0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8080000C_chfactoryworkerwear(rdram, ctx);
        goto after_2;
    // 0x808002C0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x808002C4: b           L_808002D8
    // 0x808002C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808002D8;
    // 0x808002C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002CC:
    // 0x808002CC: jal         0x8080000C
    // 0x808002D0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8080000C_chfactoryworkerwear(rdram, ctx);
        goto after_3;
    // 0x808002D0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
    // 0x808002D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002D8:
    // 0x808002D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002DC: jr          $ra
    // 0x808002E0: nop

    return;
    // 0x808002E0: nop

;}
RECOMP_FUNC void func_80800048_chmumbopad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800048: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080004C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800050: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x80800054: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1720, 0X10C8) << 16);
    // 0x80800058: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8080005C: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80800060: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80800064: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x80800068: lh          $a1, 0x10C8($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1720, 0X10C8));
    // 0x8080006C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800070: beq         $a1, $at, L_80800088
    if (ctx->r5 == ctx->r1) {
        // 0x80800074: nop
    
            goto L_80800088;
    }
    // 0x80800074: nop

    // 0x80800078: jal         0x800DA298
    // 0x8080007C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x8080007C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800080: b           L_8080008C
    // 0x80800084: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080008C;
    // 0x80800084: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800088:
    // 0x80800088: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080008C:
    // 0x8080008C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800090: jr          $ra
    // 0x80800094: nop

    return;
    // 0x80800094: nop

;}
RECOMP_FUNC void func_808000B0_scinfobar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B0: sh          $zero, 0x30($a0)
    MEM_H(0X30, ctx->r4) = 0;
    // 0x808000B4: lh          $v0, 0x30($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X30);
    // 0x808000B8: sh          $v0, 0x2E($a0)
    MEM_H(0X2E, ctx->r4) = ctx->r2;
    // 0x808000BC: jr          $ra
    // 0x808000C0: sh          $v0, 0x2C($a0)
    MEM_H(0X2C, ctx->r4) = ctx->r2;
    return;
    // 0x808000C0: sh          $v0, 0x2C($a0)
    MEM_H(0X2C, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_8009D3F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D3F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009D3FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009D400: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8009D404: jal         0x800F53D0
    // 0x8009D408: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800F53D0(rdram, ctx);
        goto after_0;
    // 0x8009D408: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8009D40C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8009D410: lw          $t6, 0x104($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X104);
    // 0x8009D414: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8009D418: addiu       $a1, $zero, 0x411
    ctx->r5 = ADD32(0, 0X411);
    // 0x8009D41C: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    // 0x8009D420: jal         0x8009DB04
    // 0x8009D424: lw          $a2, 0x14($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X14);
    func_8009DB04(rdram, ctx);
        goto after_1;
    // 0x8009D424: lw          $a2, 0x14($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X14);
    after_1:
    // 0x8009D428: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8009D42C: lw          $t8, 0x104($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X104);
    // 0x8009D430: jal         0x800C2FDC
    // 0x8009D434: lbu         $a0, 0x1($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X1);
    func_800C2FDC(rdram, ctx);
        goto after_2;
    // 0x8009D434: lbu         $a0, 0x1($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X1);
    after_2:
    // 0x8009D438: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8009D43C: lw          $t0, 0x104($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X104);
    // 0x8009D440: sb          $zero, 0x1($t0)
    MEM_B(0X1, ctx->r8) = 0;
    // 0x8009D444: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009D448: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8009D44C: jr          $ra
    // 0x8009D450: nop

    return;
    // 0x8009D450: nop

;}
RECOMP_FUNC void baeggaim_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800324: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800328: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080032C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800330: jal         0x80084AE8
    // 0x80800334: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _baeggcursor_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x80800334: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80800338: jal         0x80084B30
    // 0x8080033C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _baeggfire_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x8080033C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800340: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800344: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800348: jr          $ra
    // 0x8080034C: nop

    return;
    // 0x8080034C: nop

;}
RECOMP_FUNC void ncbaclimb_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080009C: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x808000A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000A8: jal         0x80110840
    // 0x808000AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80110840(rdram, ctx);
        goto after_0;
    // 0x808000AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808000B0: jal         0x800F53D0
    // 0x808000B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F53D0(rdram, ctx);
        goto after_1;
    // 0x808000B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808000B8: jal         0x8009861C
    // 0x808000BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8009861C(rdram, ctx);
        goto after_2;
    // 0x808000BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x808000C0: xori        $v1, $v0, 0x2
    ctx->r3 = ctx->r2 ^ 0X2;
    // 0x808000C4: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x808000C8: bne         $v1, $zero, L_808000E0
    if (ctx->r3 != 0) {
        // 0x808000CC: sw          $v1, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r3;
            goto L_808000E0;
    }
    // 0x808000CC: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000D8: jal         0x80113978
    // 0x808000DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80113978(rdram, ctx);
        goto after_3;
    // 0x808000DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
L_808000E0:
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E4: jal         0x80800028
    // 0x808000E8: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    func_80800028_ncbaclimb(rdram, ctx);
        goto after_4;
    // 0x808000E8: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_4:
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F0: jal         0x801107F0
    // 0x808000F4: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_801107F0(rdram, ctx);
        goto after_5;
    // 0x808000F4: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_5:
    // 0x808000F8: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x808000FC: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x80800100: jal         0x800EFB24
    // 0x80800104: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    func_800EFB24(rdram, ctx);
        goto after_6;
    // 0x80800104: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    after_6:
    // 0x80800108: jal         0x800EEF94
    // 0x8080010C: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    func_800EEF94(rdram, ctx);
        goto after_7;
    // 0x8080010C: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    after_7:
    // 0x80800110: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x80800114: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80800118: jal         0x800F1A88
    // 0x8080011C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800F1A88(rdram, ctx);
        goto after_8;
    // 0x8080011C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_8:
    // 0x80800120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800124: jal         0x80115358
    // 0x80800128: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_80115358(rdram, ctx);
        goto after_9;
    // 0x80800128: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_9:
    // 0x8080012C: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x80800130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800134: jal         0x80115750
    // 0x80800138: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_80115750(rdram, ctx);
        goto after_10;
    // 0x80800138: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_10:
    // 0x8080013C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80800140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800144: jal         0x80112C3C
    // 0x80800148: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    func_80112C3C(rdram, ctx);
        goto after_11;
    // 0x80800148: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_11:
    // 0x8080014C: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800154: lui         $a1, 0xC270
    ctx->r5 = S32(0XC270 << 16);
    // 0x80800158: jal         0x80115828
    // 0x8080015C: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    func_80115828(rdram, ctx);
        goto after_12;
    // 0x8080015C: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    after_12:
    // 0x80800160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800164: jal         0x80115750
    // 0x80800168: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_80115750(rdram, ctx);
        goto after_13;
    // 0x80800168: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_13:
    // 0x8080016C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80800170: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80800174: beql        $t6, $zero, L_808001D0
    if (ctx->r14 == 0) {
        // 0x80800178: addiu       $a0, $sp, 0x60
        ctx->r4 = ADD32(ctx->r29, 0X60);
            goto L_808001D0;
    }
    goto skip_0;
    // 0x80800178: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    skip_0:
    // 0x8080017C: jal         0x801112B0
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801112B0(rdram, ctx);
        goto after_14;
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800184: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800188: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080018C: jal         0x800F1DCC
    // 0x80800190: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800F1DCC(rdram, ctx);
        goto after_15;
    // 0x80800190: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_15:
    // 0x80800194: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80800198: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808001A4: sub.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x808001A8: add.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x808001AC: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x808001B0: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x808001B4: jal         0x80112D08
    // 0x808001B8: nop

    func_80112D08(rdram, ctx);
        goto after_16;
    // 0x808001B8: nop

    after_16:
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C0: jal         0x80112C3C
    // 0x808001C4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    func_80112C3C(rdram, ctx);
        goto after_17;
    // 0x808001C4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_17:
    // 0x808001C8: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x808001CC: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
L_808001D0:
    // 0x808001D0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x808001D4: jal         0x800EEBF0
    // 0x808001D8: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    func_800EEBF0(rdram, ctx);
        goto after_18;
    // 0x808001D8: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    after_18:
    // 0x808001DC: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x808001E0: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x808001E4: jal         0x800EE780
    // 0x808001E8: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    func_800EE780(rdram, ctx);
        goto after_19;
    // 0x808001E8: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    after_19:
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F0: jal         0x80111CC8
    // 0x808001F4: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_80111CC8(rdram, ctx);
        goto after_20;
    // 0x808001F4: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_20:
    // 0x808001F8: beql        $v0, $zero, L_8080023C
    if (ctx->r2 == 0) {
        // 0x808001FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080023C;
    }
    goto skip_1;
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80800200: jal         0x801138A0
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801138A0(rdram, ctx);
        goto after_21;
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800208: bne         $v0, $zero, L_80800220
    if (ctx->r2 != 0) {
        // 0x8080020C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800220;
    }
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800210: jal         0x80115580
    // 0x80800214: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    func_80115580(rdram, ctx);
        goto after_22;
    // 0x80800214: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_22:
    // 0x80800218: beql        $v0, $zero, L_8080023C
    if (ctx->r2 == 0) {
        // 0x8080021C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080023C;
    }
    goto skip_2;
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
L_80800220:
    // 0x80800220: jal         0x801138F4
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801138F4(rdram, ctx);
        goto after_23;
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80800228: beql        $v0, $zero, L_8080023C
    if (ctx->r2 == 0) {
        // 0x8080022C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080023C;
    }
    goto skip_3;
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x80800230: jal         0x80110F44
    // 0x80800234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80110F44(rdram, ctx);
        goto after_24;
    // 0x80800234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080023C:
    // 0x8080023C: jal         0x80800008
    // 0x80800240: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    func_80800008_ncbaclimb(rdram, ctx);
        goto after_25;
    // 0x80800240: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_25:
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800248: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x8080024C: jal         0x80110A68
    // 0x80800250: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    func_80110A68(rdram, ctx);
        goto after_26;
    // 0x80800250: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    after_26:
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800258: jal         0x80110790
    // 0x8080025C: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_80110790(rdram, ctx);
        goto after_27;
    // 0x8080025C: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_27:
    // 0x80800260: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800264: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800268: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x8080026C: jr          $ra
    // 0x80800270: nop

    return;
    // 0x80800270: nop

    // 0x80800274: nop

    // 0x80800278: nop

    // 0x8080027C: nop

;}
RECOMP_FUNC void _chbounce_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800858E0: syscall     180
    recomp_syscall_handler(rdram, ctx, 0x800858E0);
    return;
    // 0x800858E4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80801A80_bsbfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A80: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801A84: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801A88: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801A8C: jal         0x80800128
    // 0x80801A90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800128_bsbfly(rdram, ctx);
        goto after_0;
    // 0x80801A90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801A94: lui         $a2, 0x3F1E
    ctx->r6 = S32(0X3F1E << 16);
    // 0x80801A98: ori         $a2, $a2, 0xB852
    ctx->r6 = ctx->r6 | 0XB852;
    // 0x80801A9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801AA0: jal         0x8008CB3C
    // 0x80801AA4: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x80801AA4: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    after_1:
    // 0x80801AA8: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80801AAC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801AB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801AB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801AB8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80801ABC: jal         0x8009FFD8
    // 0x80801AC0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80801AC0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x80801AC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801AC8: jal         0x800A0CF4
    // 0x80801ACC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_3;
    // 0x80801ACC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80801AD0: jal         0x800A0024
    // 0x80801AD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A0024(rdram, ctx);
        goto after_4;
    // 0x80801AD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801AD8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801ADC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801AE0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801AE4: jr          $ra
    // 0x80801AE8: nop

    return;
    // 0x80801AE8: nop

;}
RECOMP_FUNC void func_80800000_chhoney(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80800004: lbu         $t6, 0x762C($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X762C);
    // 0x80800008: addiu       $t7, $t6, -0xF
    ctx->r15 = ADD32(ctx->r14, -0XF);
    // 0x8080000C: sltiu       $at, $t7, 0xC
    ctx->r1 = ctx->r15 < 0XC ? 1 : 0;
    // 0x80800010: beq         $at, $zero, L_808000B4
    if (ctx->r1 == 0) {
        // 0x80800014: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_808000B4;
    }
    // 0x80800014: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800018: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1668, 0XF70) << 16);
    // 0x8080001C: addu        $at, $at, $t7
    gpr jr_addend_80800024 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800020: lw          $t7, 0xF70($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1668, 0XF70));
    // 0x80800024: jr          $t7
    // 0x80800028: nop

    switch (jr_addend_80800024 >> 2) {
        case 0: goto L_80800048; break;
        case 1: goto L_8080003C; break;
        case 2: goto L_808000B4; break;
        case 3: goto L_80800054; break;
        case 4: goto L_8080002C; break;
        case 5: goto L_80800060; break;
        case 6: goto L_8080006C; break;
        case 7: goto L_80800078; break;
        case 8: goto L_80800084; break;
        case 9: goto L_80800090; break;
        case 10: goto L_8080009C; break;
        case 11: goto L_808000A8; break;
        default: switch_error(__func__, 0x80800024, 0x80800F70);
    }
    // 0x80800028: nop

L_8080002C:
    // 0x8080002C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800030: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800034: jr          $ra
    // 0x80800038: nop

    return;
    // 0x80800038: nop

L_8080003C:
    // 0x8080003C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1668, 0XFA0) << 16);
    // 0x80800040: jr          $ra
    // 0x80800044: lwc1        $f0, 0xFA0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1668, 0XFA0));
    return;
    // 0x80800044: lwc1        $f0, 0xFA0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1668, 0XFA0));
L_80800048:
    // 0x80800048: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1668, 0XFA4) << 16);
    // 0x8080004C: jr          $ra
    // 0x80800050: lwc1        $f0, 0xFA4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1668, 0XFA4));
    return;
    // 0x80800050: lwc1        $f0, 0xFA4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1668, 0XFA4));
L_80800054:
    // 0x80800054: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1668, 0XFA8) << 16);
    // 0x80800058: jr          $ra
    // 0x8080005C: lwc1        $f0, 0xFA8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1668, 0XFA8));
    return;
    // 0x8080005C: lwc1        $f0, 0xFA8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1668, 0XFA8));
L_80800060:
    // 0x80800060: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1668, 0XFAC) << 16);
    // 0x80800064: jr          $ra
    // 0x80800068: lwc1        $f0, 0xFAC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1668, 0XFAC));
    return;
    // 0x80800068: lwc1        $f0, 0xFAC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1668, 0XFAC));
L_8080006C:
    // 0x8080006C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1668, 0XFB0) << 16);
    // 0x80800070: jr          $ra
    // 0x80800074: lwc1        $f0, 0xFB0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1668, 0XFB0));
    return;
    // 0x80800074: lwc1        $f0, 0xFB0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1668, 0XFB0));
L_80800078:
    // 0x80800078: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1668, 0XFB4) << 16);
    // 0x8080007C: jr          $ra
    // 0x80800080: lwc1        $f0, 0xFB4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1668, 0XFB4));
    return;
    // 0x80800080: lwc1        $f0, 0xFB4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1668, 0XFB4));
L_80800084:
    // 0x80800084: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1668, 0XFB8) << 16);
    // 0x80800088: jr          $ra
    // 0x8080008C: lwc1        $f0, 0xFB8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1668, 0XFB8));
    return;
    // 0x8080008C: lwc1        $f0, 0xFB8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1668, 0XFB8));
L_80800090:
    // 0x80800090: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1668, 0XFBC) << 16);
    // 0x80800094: jr          $ra
    // 0x80800098: lwc1        $f0, 0xFBC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1668, 0XFBC));
    return;
    // 0x80800098: lwc1        $f0, 0xFBC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1668, 0XFBC));
L_8080009C:
    // 0x8080009C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1668, 0XFC0) << 16);
    // 0x808000A0: jr          $ra
    // 0x808000A4: lwc1        $f0, 0xFC0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1668, 0XFC0));
    return;
    // 0x808000A4: lwc1        $f0, 0xFC0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1668, 0XFC0));
L_808000A8:
    // 0x808000A8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1668, 0XFC4) << 16);
    // 0x808000AC: jr          $ra
    // 0x808000B0: lwc1        $f0, 0xFC4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1668, 0XFC4));
    return;
    // 0x808000B0: lwc1        $f0, 0xFC4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1668, 0XFC4));
L_808000B4:
    // 0x808000B4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808000B8: nop

    // 0x808000BC: jr          $ra
    // 0x808000C0: nop

    return;
    // 0x808000C0: nop

;}
RECOMP_FUNC void _chdinoboss_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086000: syscall     270
    recomp_syscall_handler(rdram, ctx, 0x80086000);
    return;
    // 0x80086004: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808000C0_chheggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000CC: lwc1        $f4, 0x48($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X48);
    // 0x808000D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000D4: jal         0x80101F24
    // 0x808000D8: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    func_80101F24(rdram, ctx);
        goto after_0;
    // 0x808000D8: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x808000DC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2456, 0X1E08) << 16);
    // 0x808000E0: addiu       $a1, $a1, 0x1E08
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2456, 0X1E08));
    // 0x808000E4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808000E8: jal         0x800F3780
    // 0x808000EC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_800F3780(rdram, ctx);
        goto after_1;
    // 0x808000EC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_1:
    // 0x808000F0: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x808000F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000FC: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800100: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800104: jal         0x80105A9C
    // 0x80800108: nop

    func_80105A9C(rdram, ctx);
        goto after_2;
    // 0x80800108: nop

    after_2:
    // 0x8080010C: jal         0x80105834
    // 0x80800110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105834(rdram, ctx);
        goto after_3;
    // 0x80800110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800114: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2456, 0X1B80) << 16);
    // 0x80800118: lwc1        $f0, 0x1B80($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2456, 0X1B80));
    // 0x8080011C: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800124: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800128: swc1        $f10, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f10.u32l;
    // 0x8080012C: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800130: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800134: lui         $a3, 0x40C0
    ctx->r7 = S32(0X40C0 << 16);
    // 0x80800138: jal         0x80102BAC
    // 0x8080013C: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
    func_80102BAC(rdram, ctx);
        goto after_4;
    // 0x8080013C: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
    after_4:
    // 0x80800140: jal         0x80105A5C
    // 0x80800144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_5;
    // 0x80800144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800148: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080014C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800150: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800154: jr          $ra
    // 0x80800158: nop

    return;
    // 0x80800158: nop

;}
RECOMP_FUNC void _bsbtrot_entrypoint_39(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082CF8: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082CF8);
    return;
    // 0x80082CFC: addi        $t0, $zero, 0x9C
    ctx->r8 = ADD32(0, 0X9C);
;}
RECOMP_FUNC void func_80800828_chfactoryworkerdirty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800828: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080082C: addiu       $at, $zero, 0x134E
    ctx->r1 = ADD32(0, 0X134E);
    // 0x80800830: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800834: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800838: bne         $a1, $at, L_80800850
    if (ctx->r5 != ctx->r1) {
        // 0x8080083C: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800850;
    }
    // 0x8080083C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800840: jal         0x80800A54
    // 0x80800844: nop

    func_80800A54_chfactoryworkerdirty(rdram, ctx);
        goto after_0;
    // 0x80800844: nop

    after_0:
    // 0x80800848: b           L_80800858
    // 0x8080084C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800858;
    // 0x8080084C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800850:
    // 0x80800850: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800854: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800858:
    // 0x80800858: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080085C: jr          $ra
    // 0x80800860: nop

    return;
    // 0x80800860: nop

;}
RECOMP_FUNC void func_80800850_chphlegm(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800850: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800854: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800858: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080085C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800860: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    // 0x80800864: jal         0x8010D254
    // 0x80800868: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    func_8010D254(rdram, ctx);
        goto after_0;
    // 0x80800868: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080086C: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80800870: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800874: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800878: beq         $t6, $at, L_80800898
    if (ctx->r14 == ctx->r1) {
        // 0x8080087C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800898;
    }
    // 0x8080087C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800880: beq         $t6, $at, L_808008B8
    if (ctx->r14 == ctx->r1) {
        // 0x80800884: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808008B8;
    }
    // 0x80800884: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800888: beq         $t6, $at, L_808009B0
    if (ctx->r14 == ctx->r1) {
        // 0x8080088C: nop
    
            goto L_808009B0;
    }
    // 0x8080088C: nop

    // 0x80800890: b           L_808009CC
    // 0x80800894: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808009CC;
    // 0x80800894: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800898:
    // 0x80800898: jal         0x800C954C
    // 0x8080089C: nop

    func_800C954C(rdram, ctx);
        goto after_1;
    // 0x8080089C: nop

    after_1:
    // 0x808008A0: bne         $v0, $zero, L_808009C8
    if (ctx->r2 != 0) {
        // 0x808008A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009C8;
    }
    // 0x808008A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008A8: jal         0x80101FDC
    // 0x808008AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x808008AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x808008B0: b           L_808009CC
    // 0x808008B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808009CC;
    // 0x808008B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808008B8:
    // 0x808008B8: jal         0x800F54E4
    // 0x808008BC: nop

    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x808008BC: nop

    after_3:
    // 0x808008C0: jal         0x800F55FC
    // 0x808008C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F55FC(rdram, ctx);
        goto after_4;
    // 0x808008C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x808008C8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x808008CC: jal         0x800DA298
    // 0x808008D0: addiu       $a0, $zero, 0x1A6
    ctx->r4 = ADD32(0, 0X1A6);
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x808008D0: addiu       $a0, $zero, 0x1A6
    ctx->r4 = ADD32(0, 0X1A6);
    after_5:
    // 0x808008D4: bne         $v0, $zero, L_80800914
    if (ctx->r2 != 0) {
        // 0x808008D8: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80800914;
    }
    // 0x808008D8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808008DC: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x808008E0: jal         0x800EFFB4
    // 0x808008E4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_800EFFB4(rdram, ctx);
        goto after_6;
    // 0x808008E4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_6:
    // 0x808008E8: beql        $v0, $zero, L_80800918
    if (ctx->r2 == 0) {
        // 0x808008EC: lw          $t8, 0x34($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X34);
            goto L_80800918;
    }
    goto skip_0;
    // 0x808008EC: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x808008F0: jal         0x800DA544
    // 0x808008F4: addiu       $a0, $zero, 0x1A6
    ctx->r4 = ADD32(0, 0X1A6);
    func_800DA544(rdram, ctx);
        goto after_7;
    // 0x808008F4: addiu       $a0, $zero, 0x1A6
    ctx->r4 = ADD32(0, 0X1A6);
    after_7:
    // 0x808008F8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808008FC: addiu       $t7, $zero, 0x57
    ctx->r15 = ADD32(0, 0X57);
    // 0x80800900: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800904: addiu       $a1, $zero, 0x1800
    ctx->r5 = ADD32(0, 0X1800);
    // 0x80800908: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8080090C: jal         0x8008A208
    // 0x80800910: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x80800910: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
L_80800914:
    // 0x80800914: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
L_80800918:
    // 0x80800918: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x8080091C: bgezl       $t9, L_808009CC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800920: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808009CC;
    }
    goto skip_1;
    // 0x80800920: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80800924: jal         0x80090150
    // 0x80800928: nop

    func_80090150(rdram, ctx);
        goto after_9;
    // 0x80800928: nop

    after_9:
    // 0x8080092C: beql        $v0, $zero, L_808009CC
    if (ctx->r2 == 0) {
        // 0x80800930: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808009CC;
    }
    goto skip_2;
    // 0x80800930: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80800934: jal         0x800DA298
    // 0x80800938: addiu       $a0, $zero, 0x170
    ctx->r4 = ADD32(0, 0X170);
    func_800DA298(rdram, ctx);
        goto after_10;
    // 0x80800938: addiu       $a0, $zero, 0x170
    ctx->r4 = ADD32(0, 0X170);
    after_10:
    // 0x8080093C: bne         $v0, $zero, L_8080097C
    if (ctx->r2 != 0) {
        // 0x80800940: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080097C;
    }
    // 0x80800940: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800944: jal         0x800DA544
    // 0x80800948: addiu       $a0, $zero, 0x170
    ctx->r4 = ADD32(0, 0X170);
    func_800DA544(rdram, ctx);
        goto after_11;
    // 0x80800948: addiu       $a0, $zero, 0x170
    ctx->r4 = ADD32(0, 0X170);
    after_11:
    // 0x8080094C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800950: addiu       $t0, $zero, 0x57
    ctx->r8 = ADD32(0, 0X57);
    // 0x80800954: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800958: addiu       $a1, $zero, 0x17FF
    ctx->r5 = ADD32(0, 0X17FF);
    // 0x8080095C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800960: jal         0x8008A208
    // 0x80800964: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_12;
    // 0x80800964: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_12:
    // 0x80800968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080096C: jal         0x80101FDC
    // 0x80800970: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_13;
    // 0x80800970: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_13:
    // 0x80800974: b           L_808009CC
    // 0x80800978: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808009CC;
    // 0x80800978: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080097C:
    // 0x8080097C: jal         0x80108B04
    // 0x80800980: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_14;
    // 0x80800980: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x80800984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800988: jal         0x80101FDC
    // 0x8080098C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_15;
    // 0x8080098C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_15:
    // 0x80800990: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800994: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800998: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8080099C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808009A0: jal         0x800DC178
    // 0x808009A4: nop

    func_800DC178(rdram, ctx);
        goto after_16;
    // 0x808009A4: nop

    after_16:
    // 0x808009A8: b           L_808009C8
    // 0x808009AC: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
        goto L_808009C8;
    // 0x808009AC: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_808009B0:
    // 0x808009B0: jal         0x800D9078
    // 0x808009B4: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_17;
    // 0x808009B4: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_17:
    // 0x808009B8: beq         $v0, $zero, L_808009C8
    if (ctx->r2 == 0) {
        // 0x808009BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009C8;
    }
    // 0x808009BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009C0: jal         0x80101FDC
    // 0x808009C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_18;
    // 0x808009C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_18:
L_808009C8:
    // 0x808009C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808009CC:
    // 0x808009CC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808009D0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808009D4: jr          $ra
    // 0x808009D8: nop

    return;
    // 0x808009D8: nop

;}
RECOMP_FUNC void func_80800F14_changlerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F14: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800F18: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800F1C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80800F20: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800F24: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800F28: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800F2C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80800F30: jal         0x80100094
    // 0x80800F34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800F34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800F38: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80800F3C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80800F40: addiu       $s1, $v0, 0x1
    ctx->r17 = ADD32(ctx->r2, 0X1);
    // 0x80800F44: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800F48: addiu       $s2, $zero, 0x1B
    ctx->r18 = ADD32(0, 0X1B);
L_80800F4C:
    // 0x80800F4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F50: jal         0x800DF744
    // 0x80800F54: lbu         $a1, 0x0($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X0);
    func_800DF744(rdram, ctx);
        goto after_1;
    // 0x80800F54: lbu         $a1, 0x0($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X0);
    after_1:
    // 0x80800F58: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800F5C: bne         $s0, $s2, L_80800F4C
    if (ctx->r16 != ctx->r18) {
        // 0x80800F60: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80800F4C;
    }
    // 0x80800F60: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800F64: jal         0x801015D0
    // 0x80800F68: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_801015D0(rdram, ctx);
        goto after_2;
    // 0x80800F68: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x80800F6C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80800F70: lw          $a0, 0x9C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X9C);
    // 0x80800F74: beql        $a0, $zero, L_80800FA0
    if (ctx->r4 == 0) {
        // 0x80800F78: lw          $a1, 0x2C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X2C);
            goto L_80800FA0;
    }
    goto skip_0;
    // 0x80800F78: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80800F7C: jal         0x80106790
    // 0x80800F80: nop

    func_80106790(rdram, ctx);
        goto after_3;
    // 0x80800F80: nop

    after_3:
    // 0x80800F84: lhu         $t7, 0x64($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X64);
    // 0x80800F88: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80800F8C: beql        $t8, $zero, L_80800FA0
    if (ctx->r24 == 0) {
        // 0x80800F90: lw          $a1, 0x2C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X2C);
            goto L_80800FA0;
    }
    goto skip_1;
    // 0x80800F90: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x80800F94: lw          $t9, 0x54($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X54);
    // 0x80800F98: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x80800F9C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
L_80800FA0:
    // 0x80800FA0: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80800FA4: lui         $at, 0x3
    ctx->r1 = S32(0X3 << 16);
    // 0x80800FA8: andi        $t0, $a1, 0xFFFF
    ctx->r8 = ctx->r5 & 0XFFFF;
    // 0x80800FAC: or          $a1, $t0, $at
    ctx->r5 = ctx->r8 | ctx->r1;
    // 0x80800FB0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80800FB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800FB8: jal         0x800DF660
    // 0x80800FBC: lbu         $a3, 0x9B($t2)
    ctx->r7 = MEM_BU(ctx->r10, 0X9B);
    func_800DF660(rdram, ctx);
        goto after_4;
    // 0x80800FBC: lbu         $a3, 0x9B($t2)
    ctx->r7 = MEM_BU(ctx->r10, 0X9B);
    after_4:
    // 0x80800FC0: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80800FC4: jal         0x80100AC4
    // 0x80800FC8: lh          $a0, 0x60($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X60);
    func_80100AC4(rdram, ctx);
        goto after_5;
    // 0x80800FC8: lh          $a0, 0x60($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X60);
    after_5:
    // 0x80800FCC: jal         0x800DF720
    // 0x80800FD0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF720(rdram, ctx);
        goto after_6;
    // 0x80800FD0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x80800FD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800FD8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800FDC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800FE0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800FE4: jr          $ra
    // 0x80800FE8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800FE8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800B388C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B388C: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x800B3890: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x800B3894: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B3898: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x800B389C: addiu       $t8, $t7, 0x18
    ctx->r24 = ADD32(ctx->r15, 0X18);
    // 0x800B38A0: jr          $ra
    // 0x800B38A4: sw          $t8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r24;
    return;
    // 0x800B38A4: sw          $t8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_8008DE74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DE74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008DE78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008DE7C: jal         0x8009E6F8
    // 0x8008DE80: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bs_getCurrentState(rdram, ctx);
        goto after_0;
    // 0x8008DE80: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008DE84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008DE88: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8008DE8C: jal         0x8009CA70
    // 0x8008DE90: addiu       $a2, $zero, 0x4000
    ctx->r6 = ADD32(0, 0X4000);
    func_8009CA70(rdram, ctx);
        goto after_1;
    // 0x8008DE90: addiu       $a2, $zero, 0x4000
    ctx->r6 = ADD32(0, 0X4000);
    after_1:
    // 0x8008DE94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008DE98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008DE9C: jr          $ra
    // 0x8008DEA0: nop

    return;
    // 0x8008DEA0: nop

;}
RECOMP_FUNC void func_80800364_chfootwear(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800364: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800368: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080036C: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x80800370: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800374: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800378: bne         $a1, $at, L_80800410
    if (ctx->r5 != ctx->r1) {
        // 0x8080037C: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_80800410;
    }
    // 0x8080037C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800380: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80800384: addiu       $a0, $zero, 0x64F
    ctx->r4 = ADD32(0, 0X64F);
    // 0x80800388: lw          $t6, 0x24($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X24);
    // 0x8080038C: srl         $t7, $t6, 22
    ctx->r15 = S32(U32(ctx->r14) >> 22);
    // 0x80800390: bne         $t7, $zero, L_80800408
    if (ctx->r15 != 0) {
        // 0x80800394: nop
    
            goto L_80800408;
    }
    // 0x80800394: nop

    // 0x80800398: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8080039C: jal         0x800DA298
    // 0x808003A0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808003A0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x808003A4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808003A8: beq         $v0, $zero, L_80800408
    if (ctx->r2 == 0) {
        // 0x808003AC: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_80800408;
    }
    // 0x808003AC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808003B0: lhu         $a1, 0x1A($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X1A);
    // 0x808003B4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808003B8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x808003BC: srl         $t8, $a1, 5
    ctx->r24 = S32(U32(ctx->r5) >> 5);
    // 0x808003C0: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x808003C4: jal         0x80800664
    // 0x808003C8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80800664_chfootwear(rdram, ctx);
        goto after_1;
    // 0x808003C8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x808003CC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808003D0: beq         $v0, $zero, L_80800408
    if (ctx->r2 == 0) {
        // 0x808003D4: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_80800408;
    }
    // 0x808003D4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808003D8: lhu         $t9, 0x1A($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X1A);
    // 0x808003DC: lbu         $t4, 0x79($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X79);
    // 0x808003E0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808003E4: srl         $t1, $t9, 5
    ctx->r9 = S32(U32(ctx->r25) >> 5);
    // 0x808003E8: sll         $t3, $t1, 4
    ctx->r11 = S32(ctx->r9 << 4);
    // 0x808003EC: andi        $t5, $t4, 0xFF0F
    ctx->r13 = ctx->r12 & 0XFF0F;
    // 0x808003F0: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x808003F4: sb          $t6, 0x79($a2)
    MEM_B(0X79, ctx->r6) = ctx->r14;
    // 0x808003F8: jal         0x80800424
    // 0x808003FC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800424_chfootwear(rdram, ctx);
        goto after_2;
    // 0x808003FC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80800400: b           L_80800414
    // 0x80800404: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800414;
    // 0x80800404: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800408:
    // 0x80800408: b           L_80800414
    // 0x8080040C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800414;
    // 0x8080040C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800410:
    // 0x80800410: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800414:
    // 0x80800414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800418: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080041C: jr          $ra
    // 0x80800420: nop

    return;
    // 0x80800420: nop

;}
RECOMP_FUNC void _bswalk_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084220: syscall     107
    recomp_syscall_handler(rdram, ctx, 0x80084220);
    return;
    // 0x80084224: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_800F8DA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F8DA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F8DAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F8DB0: jal         0x800F88A0
    // 0x800F8DB4: nop

    func_800F88A0(rdram, ctx);
        goto after_0;
    // 0x800F8DB4: nop

    after_0:
    // 0x800F8DB8: beq         $v0, $zero, L_800F8DC8
    if (ctx->r2 == 0) {
        // 0x800F8DBC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800F8DC8;
    }
    // 0x800F8DBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F8DC0: b           L_800F8DCC
    // 0x800F8DC4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800F8DCC;
    // 0x800F8DC4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800F8DC8:
    // 0x800F8DC8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800F8DCC:
    // 0x800F8DCC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800F8DD0: jr          $ra
    // 0x800F8DD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800F8DD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80801FE0_chfactoryempspell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801FE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801FE4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801FE8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801FEC: jal         0x80089D40
    // 0x80801FF0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80801FF0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801FF4: jal         0x80089D48
    // 0x80801FF8: lbu         $a0, 0x28($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X28);
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80801FF8: lbu         $a0, 0x28($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X28);
    after_1:
    // 0x80801FFC: sb          $v0, 0x28($s0)
    MEM_B(0X28, ctx->r16) = ctx->r2;
    // 0x80802000: jal         0x80801AB4
    // 0x80802004: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801AB4_chfactoryempspell(rdram, ctx);
        goto after_2;
    // 0x80802004: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80802008: lh          $t6, 0x82($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X82);
    // 0x8080200C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802010: beql        $t6, $zero, L_80802024
    if (ctx->r14 == 0) {
        // 0x80802014: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802024;
    }
    goto skip_0;
    // 0x80802014: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80802018: jal         0x80089848
    // 0x8080201C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _sumumbofx_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x8080201C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80802020: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802024:
    // 0x80802024: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802028: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080202C: jr          $ra
    // 0x80802030: nop

    return;
    // 0x80802030: nop

;}
RECOMP_FUNC void _bstalk_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083DB8: syscall     95
    recomp_syscall_handler(rdram, ctx, 0x80083DB8);
    return;
    // 0x80083DBC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _baduo_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084970: syscall     124
    recomp_syscall_handler(rdram, ctx, 0x80084970);
    return;
    // 0x80084974: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_80093448(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093448: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8009344C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80093450: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80093454: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x80093458: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8009345C: lw          $t7, 0x84($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X84);
    // 0x80093460: bne         $t7, $zero, L_80093498
    if (ctx->r15 != 0) {
        // 0x80093464: nop
    
            goto L_80093498;
    }
    // 0x80093464: nop

    // 0x80093468: jal         0x8009C128
    // 0x8009346C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x8009346C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80093470: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80093474: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80093478: addiu       $a0, $a0, 0x27C4
    ctx->r4 = ADD32(ctx->r4, 0X27C4);
    // 0x8009347C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80093480: lw          $t9, 0x184($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X184);
    // 0x80093484: addiu       $a1, $zero, 0x215
    ctx->r5 = ADD32(0, 0X215);
    // 0x80093488: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8009348C: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80093490: jal         0x80086D50
    // 0x80093494: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    _chbaddiesetup_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80093494: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_1:
L_80093498:
    // 0x80093498: jal         0x80093388
    // 0x8009349C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80093388(rdram, ctx);
        goto after_2;
    // 0x8009349C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800934A0: jal         0x80092018
    // 0x800934A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80092018(rdram, ctx);
        goto after_3;
    // 0x800934A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800934A8: jal         0x800920C8
    // 0x800934AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800920C8(rdram, ctx);
        goto after_4;
    // 0x800934AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800934B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800934B4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800934B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800934BC: jr          $ra
    // 0x800934C0: nop

    return;
    // 0x800934C0: nop

;}
RECOMP_FUNC void chvolcanobits_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1264, 0X1154) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x1154
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1264, 0X1154));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x1154
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1264, 0X1154));
;}
