#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _bsbanshack_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082730: syscall     8
    recomp_syscall_handler(rdram, ctx, 0x80082730);
    return;
    // 0x80082734: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void _cheggice_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087238: syscall     538
    recomp_syscall_handler(rdram, ctx, 0x80087238);
    return;
    // 0x8008723C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808024DC_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808024DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808024E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808024E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808024E8: jal         0x80100094
    // 0x808024EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808024EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808024F0: lbu         $t6, 0x57($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X57);
    // 0x808024F4: bnel        $t6, $zero, L_8080252C
    if (ctx->r14 != 0) {
        // 0x808024F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080252C;
    }
    goto skip_0;
    // 0x808024F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808024FC: lbu         $t7, 0x58($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X58);
    // 0x80802500: beql        $t7, $zero, L_8080252C
    if (ctx->r15 == 0) {
        // 0x80802504: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080252C;
    }
    goto skip_1;
    // 0x80802504: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80802508: lbu         $t8, 0x59($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X59);
    // 0x8080250C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80802510: bnel        $t8, $zero, L_8080252C
    if (ctx->r24 != 0) {
        // 0x80802514: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080252C;
    }
    goto skip_2;
    // 0x80802514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80802518: jal         0x80802538
    // 0x8080251C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80802538_chboilerboss(rdram, ctx);
        goto after_1;
    // 0x8080251C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80802520: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80802524: sb          $zero, 0x58($v1)
    MEM_B(0X58, ctx->r3) = 0;
    // 0x80802528: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080252C:
    // 0x8080252C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802530: jr          $ra
    // 0x80802534: nop

    return;
    // 0x80802534: nop

;}
RECOMP_FUNC void _gsattract_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088C58: syscall     731
    recomp_syscall_handler(rdram, ctx, 0x80088C58);
    return;
    // 0x80088C5C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800020_chfloaty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800020: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800024: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800028: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8080002C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800030: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80800034: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800038: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8080003C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80800040: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80800044: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x80800048: lw          $a3, 0x4($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X4);
    // 0x8080004C: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    // 0x80800050: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x80800054: addiu       $a0, $a0, -0x5A88
    ctx->r4 = ADD32(ctx->r4, -0X5A88);
    // 0x80800058: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8080005C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80800060: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80800064: jal         0x80086D58
    // 0x80800068: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    _chbaddiesetup_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x80800068: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x8080006C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800070: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800074: jr          $ra
    // 0x80800078: nop

    return;
    // 0x80800078: nop

;}
RECOMP_FUNC void _ncbapan_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800891A0: syscall     765
    recomp_syscall_handler(rdram, ctx, 0x800891A0);
    return;
    // 0x800891A4: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void func_8080162C_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080162C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801630: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801634: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801638: jal         0x80100094
    // 0x8080163C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080163C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801640: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80801644: jal         0x80802FCC
    // 0x80801648: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80802FCC_chklungo(rdram, ctx);
        goto after_1;
    // 0x80801648: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8080164C: jal         0x80802558
    // 0x80801650: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80802558_chklungo(rdram, ctx);
        goto after_2;
    // 0x80801650: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80801654: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80801658: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080165C: lh          $t7, 0x1A($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X1A);
    // 0x80801660: bnel        $t7, $zero, L_80801674
    if (ctx->r15 != 0) {
        // 0x80801664: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801674;
    }
    goto skip_0;
    // 0x80801664: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801668: jal         0x800897C8
    // 0x8080166C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x8080166C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80801670: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801674:
    // 0x80801674: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801678: jr          $ra
    // 0x8080167C: nop

    return;
    // 0x8080167C: nop

;}
RECOMP_FUNC void badrone_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080041C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800420: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800424: lw          $t7, 0x54($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X54);
    // 0x80800428: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x8080042C: jal         0x800846F0
    // 0x80800430: sb          $t6, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r14;
    _badata_entrypoint_22(rdram, ctx);
        goto after_0;
    // 0x80800430: sb          $t6, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r14;
    after_0:
    // 0x80800434: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800438: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080043C: jr          $ra
    // 0x80800440: nop

    return;
    // 0x80800440: nop

;}
RECOMP_FUNC void _chfactorydrums_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087438: syscall     571
    recomp_syscall_handler(rdram, ctx, 0x80087438);
    return;
    // 0x8008743C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void bastick_func_8009F18C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F18C: lw          $t6, 0x128($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X128);
    // 0x8009F190: jr          $ra
    // 0x8009F194: sb          $a1, 0x64($t6)
    MEM_B(0X64, ctx->r14) = ctx->r5;
    return;
    // 0x8009F194: sb          $a1, 0x64($t6)
    MEM_B(0X64, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void sueggmove_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800250: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800254: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800258: jal         0x80100094
    // 0x8080025C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080025C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800260: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800264: lbu         $v0, 0xC($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XC);
    // 0x80800268: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080026C: jr          $ra
    // 0x80800270: nop

    return;
    // 0x80800270: nop

;}
RECOMP_FUNC void func_800DAA1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DAA1C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800DAA20: jr          $ra
    // 0x800DAA24: lw          $v0, -0x4670($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4670);
    return;
    // 0x800DAA24: lw          $v0, -0x4670($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4670);
;}
RECOMP_FUNC void func_800EF04C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EF04C: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800EF050: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800EF054: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800EF058: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800EF05C: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800EF060: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x800EF064: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800EF068: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800EF06C: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
    // 0x800EF070: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800EF074: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800EF078: jr          $ra
    // 0x800EF07C: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x800EF07C: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_808026A0_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808026A0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808026A4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808026A8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x808026AC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x808026B0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x808026B4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808026B8: jal         0x800EA05C
    // 0x808026BC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x808026BC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    after_0:
    // 0x808026C0: addiu       $at, $zero, 0xBB
    ctx->r1 = ADD32(0, 0XBB);
    // 0x808026C4: bne         $v0, $at, L_80802798
    if (ctx->r2 != ctx->r1) {
        // 0x808026C8: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1608, 0X4F08) << 16);
            goto L_80802798;
    }
    // 0x808026C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4F08) << 16);
    // 0x808026CC: lwc1        $f4, 0x4F08($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4F08));
    // 0x808026D0: lwc1        $f0, 0x4($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X4);
    // 0x808026D4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4F0C) << 16);
    // 0x808026D8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808026DC: nop

    // 0x808026E0: bc1f        L_808026F0
    if (!c1cs) {
        // 0x808026E4: nop
    
            goto L_808026F0;
    }
    // 0x808026E4: nop

    // 0x808026E8: b           L_80802810
    // 0x808026EC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80802810;
    // 0x808026EC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_808026F0:
    // 0x808026F0: lwc1        $f6, 0x4F0C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4F0C));
    // 0x808026F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4F10) << 16);
    // 0x808026F8: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x808026FC: nop

    // 0x80802700: bc1fl       L_80802714
    if (!c1cs) {
        // 0x80802704: lwc1        $f0, 0xC($s2)
        ctx->f0.u32l = MEM_W(ctx->r18, 0XC);
            goto L_80802714;
    }
    goto skip_0;
    // 0x80802704: lwc1        $f0, 0xC($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XC);
    skip_0:
    // 0x80802708: b           L_80802810
    // 0x8080270C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80802810;
    // 0x8080270C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80802710: lwc1        $f0, 0xC($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XC);
L_80802714:
    // 0x80802714: lwc1        $f8, 0x4F10($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4F10));
    // 0x80802718: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4F14) << 16);
    // 0x8080271C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80802720: nop

    // 0x80802724: bc1f        L_80802734
    if (!c1cs) {
        // 0x80802728: nop
    
            goto L_80802734;
    }
    // 0x80802728: nop

    // 0x8080272C: b           L_80802810
    // 0x80802730: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80802810;
    // 0x80802730: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80802734:
    // 0x80802734: lwc1        $f10, 0x4F14($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4F14));
    // 0x80802738: addiu       $s1, $s2, 0x4
    ctx->r17 = ADD32(ctx->r18, 0X4);
    // 0x8080273C: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(1608, 0X5258) << 16);
    // 0x80802740: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80802744: addiu       $s0, $s0, 0x5258
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(1608, 0X5258));
    // 0x80802748: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(1608, 0X52A0) << 16);
    // 0x8080274C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80802750: bc1fl       L_80802764
    if (!c1cs) {
        // 0x80802754: mtc1        $at, $f20
        ctx->f20.u32l = ctx->r1;
            goto L_80802764;
    }
    goto skip_1;
    // 0x80802754: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    skip_1:
    // 0x80802758: b           L_80802810
    // 0x8080275C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802810;
    // 0x8080275C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80802760: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
L_80802764:
    // 0x80802764: addiu       $s2, $s2, 0x52A0
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(1608, 0X52A0));
    // 0x80802768: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
L_8080276C:
    // 0x8080276C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802770: jal         0x800F0064
    // 0x80802774: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800F0064(rdram, ctx);
        goto after_1;
    // 0x80802774: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_1:
    // 0x80802778: beq         $v0, $zero, L_80802788
    if (ctx->r2 == 0) {
        // 0x8080277C: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_80802788;
    }
    // 0x8080277C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80802780: b           L_80802810
    // 0x80802784: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802810;
    // 0x80802784: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802788:
    // 0x80802788: bnel        $s0, $s2, L_8080276C
    if (ctx->r16 != ctx->r18) {
        // 0x8080278C: mfc1        $a1, $f20
        ctx->r5 = (int32_t)ctx->f20.u32l;
            goto L_8080276C;
    }
    goto skip_2;
    // 0x8080278C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    skip_2:
    // 0x80802790: b           L_80802810
    // 0x80802794: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80802810;
    // 0x80802794: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80802798:
    // 0x80802798: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4F18) << 16);
    // 0x8080279C: lwc1        $f2, 0x4F18($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4F18));
    // 0x808027A0: lwc1        $f0, 0x4($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X4);
    // 0x808027A4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4F1C) << 16);
    // 0x808027A8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x808027AC: nop

    // 0x808027B0: bc1f        L_808027C0
    if (!c1cs) {
        // 0x808027B4: nop
    
            goto L_808027C0;
    }
    // 0x808027B4: nop

    // 0x808027B8: b           L_80802810
    // 0x808027BC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80802810;
    // 0x808027BC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_808027C0:
    // 0x808027C0: lwc1        $f12, 0x4F1C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4F1C));
    // 0x808027C4: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x808027C8: nop

    // 0x808027CC: bc1fl       L_808027E0
    if (!c1cs) {
        // 0x808027D0: lwc1        $f0, 0xC($s2)
        ctx->f0.u32l = MEM_W(ctx->r18, 0XC);
            goto L_808027E0;
    }
    goto skip_3;
    // 0x808027D0: lwc1        $f0, 0xC($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XC);
    skip_3:
    // 0x808027D4: b           L_80802810
    // 0x808027D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80802810;
    // 0x808027D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808027DC: lwc1        $f0, 0xC($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XC);
L_808027E0:
    // 0x808027E0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x808027E4: nop

    // 0x808027E8: bc1fl       L_808027FC
    if (!c1cs) {
        // 0x808027EC: c.lt.s      $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
            goto L_808027FC;
    }
    goto skip_4;
    // 0x808027EC: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    skip_4:
    // 0x808027F0: b           L_80802810
    // 0x808027F4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80802810;
    // 0x808027F4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x808027F8: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
L_808027FC:
    // 0x808027FC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80802800: bc1f        L_80802810
    if (!c1cs) {
        // 0x80802804: nop
    
            goto L_80802810;
    }
    // 0x80802804: nop

    // 0x80802808: b           L_80802810
    // 0x8080280C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802810;
    // 0x8080280C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802810:
    // 0x80802810: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80802814: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80802818: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080281C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80802820: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80802824: jr          $ra
    // 0x80802828: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80802828: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _chnests_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085AA0: syscall     191
    recomp_syscall_handler(rdram, ctx, 0x80085AA0);
    return;
    // 0x80085AA4: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_80800300_chevilmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800300: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800304: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800308: jal         0x8008F8B0
    // 0x8080030C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8008F8B0(rdram, ctx);
        goto after_0;
    // 0x8080030C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800310: jal         0x8008F8D8
    // 0x80800314: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8008F8D8(rdram, ctx);
        goto after_1;
    // 0x80800314: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80800318: jal         0x8008F938
    // 0x8080031C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8008F938(rdram, ctx);
        goto after_2;
    // 0x8080031C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80800320: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800324: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80800328: addiu       $a0, $a0, -0x2A24
    ctx->r4 = ADD32(ctx->r4, -0X2A24);
    // 0x8080032C: jal         0x8008F904
    // 0x80800330: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    func_8008F904(rdram, ctx);
        goto after_3;
    // 0x80800330: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    after_3:
    // 0x80800334: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1676, 0X4294) << 16);
    // 0x80800338: addiu       $a0, $a0, 0x4294
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1676, 0X4294));
    // 0x8080033C: jal         0x8008F990
    // 0x80800340: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    func_8008F990(rdram, ctx);
        goto after_4;
    // 0x80800340: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    after_4:
    // 0x80800344: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800348: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080034C: jr          $ra
    // 0x80800350: nop

    return;
    // 0x80800350: nop

;}
RECOMP_FUNC void func_8008C1F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C1F0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8008C1F4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8008C1F8: jr          $ra
    // 0x8008C1FC: sb          $t6, 0x1A($a0)
    MEM_B(0X1A, ctx->r4) = ctx->r14;
    return;
    // 0x8008C1FC: sb          $t6, 0x1A($a0)
    MEM_B(0X1A, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void fxrain_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808003CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808003D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808003D8: jal         0x8001ACCC
    // 0x808003DC: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x808003DC: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    after_0:
    // 0x808003E0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808003E4: jal         0x800EFD24
    // 0x808003E8: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    func_800EFD24(rdram, ctx);
        goto after_1;
    // 0x808003E8: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    after_1:
    // 0x808003EC: jal         0x800EFD24
    // 0x808003F0: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    func_800EFD24(rdram, ctx);
        goto after_2;
    // 0x808003F0: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    after_2:
    // 0x808003F4: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x808003F8: sb          $zero, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = 0;
    // 0x808003FC: sb          $zero, 0x30($s0)
    MEM_B(0X30, ctx->r16) = 0;
    // 0x80800400: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800404: jal         0x800B2D70
    // 0x80800408: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    vector_new(rdram, ctx);
        goto after_3;
    // 0x80800408: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_3:
    // 0x8080040C: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x80800410: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800414: sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
    // 0x80800418: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2798, 0X8D8) << 16);
    // 0x8080041C: sw          $t6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r14;
    // 0x80800420: lwc1        $f4, 0x8D8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2798, 0X8D8));
    // 0x80800424: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80800428: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    // 0x8080042C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800430: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800434: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800438: jr          $ra
    // 0x8080043C: nop

    return;
    // 0x8080043C: nop

;}
RECOMP_FUNC void bsbeefly_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CCC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800CD0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(76, 0XE70) << 16);
    // 0x80800CD4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800CD8: jr          $ra
    // 0x80800CDC: lw          $v0, 0xE70($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(76, 0XE70));
    return;
    // 0x80800CDC: lw          $v0, 0xE70($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(76, 0XE70));
;}
RECOMP_FUNC void func_8080145C_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080145C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801460: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801464: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80801468: jal         0x80100094
    // 0x8080146C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080146C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801470: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1608, 0X50BC) << 16);
    // 0x80801474: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80801478: addiu       $t6, $t6, 0x50BC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1608, 0X50BC));
    // 0x8080147C: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x80801480: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80801484: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80801488: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x8080148C: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80801490: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x80801494: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x80801498: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    // 0x8080149C: lw          $t9, 0xC($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XC);
    // 0x808014A0: sw          $t9, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r25;
    // 0x808014A4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808014A8: jal         0x80801638
    // 0x808014AC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80801638_chstoneballcontrol(rdram, ctx);
        goto after_1;
    // 0x808014AC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x808014B0: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x808014B4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808014B8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808014BC: lbu         $a0, 0x39($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X39);
    // 0x808014C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808014C4: bne         $a0, $at, L_80801570
    if (ctx->r4 != ctx->r1) {
        // 0x808014C8: nop
    
            goto L_80801570;
    }
    // 0x808014C8: nop

    // 0x808014CC: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    // 0x808014D0: jal         0x800DA298
    // 0x808014D4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x808014D4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_2:
    // 0x808014D8: bne         $v0, $zero, L_808014F4
    if (ctx->r2 != 0) {
        // 0x808014DC: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_808014F4;
    }
    // 0x808014DC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808014E0: addiu       $a0, $zero, 0x9EA
    ctx->r4 = ADD32(0, 0X9EA);
    // 0x808014E4: jal         0x800DA298
    // 0x808014E8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x808014E8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_3:
    // 0x808014EC: beq         $v0, $zero, L_80801508
    if (ctx->r2 == 0) {
        // 0x808014F0: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_80801508;
    }
    // 0x808014F0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
L_808014F4:
    // 0x808014F4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x808014F8: bgtzl       $t1, L_80801558
    if (SIGNED(ctx->r9) > 0) {
        // 0x808014FC: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_80801558;
    }
    goto skip_0;
    // 0x808014FC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    skip_0:
    // 0x80801500: b           L_80801554
    // 0x80801504: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
        goto L_80801554;
    // 0x80801504: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
L_80801508:
    // 0x80801508: addiu       $a0, $zero, 0x5E
    ctx->r4 = ADD32(0, 0X5E);
    // 0x8080150C: jal         0x800DA298
    // 0x80801510: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80801510: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_4:
    // 0x80801514: bne         $v0, $zero, L_80801530
    if (ctx->r2 != 0) {
        // 0x80801518: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_80801530;
    }
    // 0x80801518: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8080151C: addiu       $a0, $zero, 0x9E9
    ctx->r4 = ADD32(0, 0X9E9);
    // 0x80801520: jal         0x800DA298
    // 0x80801524: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x80801524: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_5:
    // 0x80801528: beq         $v0, $zero, L_80801544
    if (ctx->r2 == 0) {
        // 0x8080152C: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_80801544;
    }
    // 0x8080152C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
L_80801530:
    // 0x80801530: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80801534: bgtzl       $t2, L_80801558
    if (SIGNED(ctx->r10) > 0) {
        // 0x80801538: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_80801558;
    }
    goto skip_1;
    // 0x80801538: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    skip_1:
    // 0x8080153C: b           L_80801554
    // 0x80801540: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
        goto L_80801554;
    // 0x80801540: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
L_80801544:
    // 0x80801544: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80801548: bgtzl       $t3, L_80801558
    if (SIGNED(ctx->r11) > 0) {
        // 0x8080154C: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_80801558;
    }
    goto skip_2;
    // 0x8080154C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    skip_2:
    // 0x80801550: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80801554:
    // 0x80801554: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
L_80801558:
    // 0x80801558: beq         $a2, $at, L_80801628
    if (ctx->r6 == ctx->r1) {
        // 0x8080155C: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80801628;
    }
    // 0x8080155C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801560: jal         0x80108B04
    // 0x80801564: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80108B04(rdram, ctx);
        goto after_6;
    // 0x80801564: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_6:
    // 0x80801568: b           L_8080162C
    // 0x8080156C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080162C;
    // 0x8080156C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801570:
    // 0x80801570: jal         0x80800114
    // 0x80801574: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80800114_chstoneballcontrol(rdram, ctx);
        goto after_7;
    // 0x80801574: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_7:
    // 0x80801578: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8080157C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80801580: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80801584: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80801588: beq         $at, $zero, L_80801598
    if (ctx->r1 == 0) {
        // 0x8080158C: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_80801598;
    }
    // 0x8080158C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80801590: b           L_808015E8
    // 0x80801594: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_808015E8;
    // 0x80801594: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80801598:
    // 0x80801598: lbu         $a0, 0x39($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X39);
    // 0x8080159C: jal         0x80800114
    // 0x808015A0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80800114_chstoneballcontrol(rdram, ctx);
        goto after_8;
    // 0x808015A0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_8:
    // 0x808015A4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x808015A8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808015AC: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x808015B0: slt         $at, $t8, $v0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808015B4: beq         $at, $zero, L_808015C4
    if (ctx->r1 == 0) {
        // 0x808015B8: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_808015C4;
    }
    // 0x808015B8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808015BC: b           L_808015E8
    // 0x808015C0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
        goto L_808015E8;
    // 0x808015C0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
L_808015C4:
    // 0x808015C4: lbu         $a0, 0x39($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X39);
    // 0x808015C8: jal         0x80800114
    // 0x808015CC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80800114_chstoneballcontrol(rdram, ctx);
        goto after_9;
    // 0x808015CC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_9:
    // 0x808015D0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x808015D4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808015D8: slt         $at, $t6, $v0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808015DC: beq         $at, $zero, L_808015E8
    if (ctx->r1 == 0) {
        // 0x808015E0: nop
    
            goto L_808015E8;
    }
    // 0x808015E0: nop

    // 0x808015E4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
L_808015E8:
    // 0x808015E8: bltz        $a2, L_80801604
    if (SIGNED(ctx->r6) < 0) {
        // 0x808015EC: lw          $t9, 0x34($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X34);
            goto L_80801604;
    }
    // 0x808015EC: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x808015F0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808015F4: jal         0x80108B04
    // 0x808015F8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80108B04(rdram, ctx);
        goto after_10;
    // 0x808015F8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_10:
    // 0x808015FC: b           L_8080162C
    // 0x80801600: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080162C;
    // 0x80801600: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801604:
    // 0x80801604: lbu         $a0, 0x39($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X39);
    // 0x80801608: jal         0x80800114
    // 0x8080160C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800114_chstoneballcontrol(rdram, ctx);
        goto after_11;
    // 0x8080160C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80801610: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80801614: slt         $at, $t0, $v0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80801618: beql        $at, $zero, L_8080162C
    if (ctx->r1 == 0) {
        // 0x8080161C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080162C;
    }
    goto skip_3;
    // 0x8080161C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x80801620: jal         0x80801884
    // 0x80801624: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80801884_chstoneballcontrol(rdram, ctx);
        goto after_12;
    // 0x80801624: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_12:
L_80801628:
    // 0x80801628: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080162C:
    // 0x8080162C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80801630: jr          $ra
    // 0x80801634: nop

    return;
    // 0x80801634: nop

;}
RECOMP_FUNC void func_80115CA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115CA4: lw          $v0, 0x3C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X3C);
    // 0x80115CA8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80115CAC: lbu         $t6, 0x12($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X12);
    // 0x80115CB0: beql        $t6, $zero, L_80115CD0
    if (ctx->r14 == 0) {
        // 0x80115CB4: lbu         $t7, 0x11($v0)
        ctx->r15 = MEM_BU(ctx->r2, 0X11);
            goto L_80115CD0;
    }
    goto skip_0;
    // 0x80115CB4: lbu         $t7, 0x11($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X11);
    skip_0:
    // 0x80115CB8: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80115CBC: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x80115CC0: nop

    // 0x80115CC4: bc1t        L_80115D00
    if (c1cs) {
        // 0x80115CC8: nop
    
            goto L_80115D00;
    }
    // 0x80115CC8: nop

    // 0x80115CCC: lbu         $t7, 0x11($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X11);
L_80115CD0:
    // 0x80115CD0: beql        $t7, $zero, L_80115CF4
    if (ctx->r15 == 0) {
        // 0x80115CD4: swc1        $f12, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->f12.u32l;
            goto L_80115CF4;
    }
    goto skip_1;
    // 0x80115CD4: swc1        $f12, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f12.u32l;
    skip_1:
    // 0x80115CD8: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80115CDC: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80115CE0: nop

    // 0x80115CE4: bc1fl       L_80115CF4
    if (!c1cs) {
        // 0x80115CE8: swc1        $f12, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->f12.u32l;
            goto L_80115CF4;
    }
    goto skip_2;
    // 0x80115CE8: swc1        $f12, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f12.u32l;
    skip_2:
    // 0x80115CEC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80115CF0: swc1        $f12, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f12.u32l;
L_80115CF4:
    // 0x80115CF4: lw          $t9, 0x3C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X3C);
    // 0x80115CF8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80115CFC: sb          $t8, 0x12($t9)
    MEM_B(0X12, ctx->r25) = ctx->r24;
L_80115D00:
    // 0x80115D00: jr          $ra
    // 0x80115D04: nop

    return;
    // 0x80115D04: nop

;}
RECOMP_FUNC void func_80800F00_chfirefx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F00: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800F04: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800F08: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800F0C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800F10: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800F14: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800F18: jal         0x80100094
    // 0x80800F1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800F1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800F20: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800F24: addiu       $s1, $v0, 0x8
    ctx->r17 = ADD32(ctx->r2, 0X8);
    // 0x80800F28: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800F2C: addiu       $s2, $zero, 0x80
    ctx->r18 = ADD32(0, 0X80);
L_80800F30:
    // 0x80800F30: jal         0x8008A020
    // 0x80800F34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    _subaddielink_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800F34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80800F38: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80800F3C: bne         $s0, $s2, L_80800F30
    if (ctx->r16 != ctx->r18) {
        // 0x80800F40: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_80800F30;
    }
    // 0x80800F40: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80800F44: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80800F48: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x80800F4C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80800F50: lwc1        $f4, 0x48($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X48);
    // 0x80800F54: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800F58: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80800F5C: nop

    // 0x80800F60: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80800F64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800F68: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800F6C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800F70: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800F74: jr          $ra
    // 0x80800F78: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800F78: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80800FE0_gczoombox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FE0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800FE4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800FE8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800FEC: lh          $t6, 0x1AC($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X1AC);
    // 0x80800FF0: lbu         $t7, 0x1B4($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1B4);
    // 0x80800FF4: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80800FF8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80800FFC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801000: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80801004: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80801008: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080100C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80801010: bgez        $t7, L_80801028
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80801014: div.s       $f0, $f6, $f8
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
            goto L_80801028;
    }
    // 0x80801014: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80801018: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8080101C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801020: nop

    // 0x80801024: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_80801028:
    // 0x80801028: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8080102C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80801030: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80801034: nop

    // 0x80801038: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x8080103C: lbu         $t0, 0x1B5($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X1B5);
    // 0x80801040: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x80801044: bgez        $t0, L_8080105C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80801048: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8080105C;
    }
    // 0x80801048: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8080104C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80801050: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801054: nop

    // 0x80801058: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_8080105C:
    // 0x8080105C: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80801060: trunc.w.s   $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80801064: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x80801068: nop

    // 0x8080106C: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x80801070: lbu         $t3, 0x1B6($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X1B6);
    // 0x80801074: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80801078: bgez        $t3, L_80801090
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8080107C: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80801090;
    }
    // 0x8080107C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80801080: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80801084: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801088: nop

    // 0x8080108C: add.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f18.fl;
L_80801090:
    // 0x80801090: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80801094: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80801098: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x8080109C: jal         0x800B7A98
    // 0x808010A0: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    func_800B7A98(rdram, ctx);
        goto after_0;
    // 0x808010A0: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    after_0:
    // 0x808010A4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808010A8: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x808010AC: jal         0x800B7B8C
    // 0x808010B0: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    func_800B7B8C(rdram, ctx);
        goto after_1;
    // 0x808010B0: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    after_1:
    // 0x808010B4: jal         0x800B7ADC
    // 0x808010B8: lh          $a0, 0x1BC($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X1BC);
    func_800B7ADC(rdram, ctx);
        goto after_2;
    // 0x808010B8: lh          $a0, 0x1BC($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X1BC);
    after_2:
    // 0x808010BC: lh          $t7, 0x1E6($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1E6);
    // 0x808010C0: bgezl       $t7, L_808010DC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x808010C4: lw          $t8, 0x1E4($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X1E4);
            goto L_808010DC;
    }
    goto skip_0;
    // 0x808010C4: lw          $t8, 0x1E4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1E4);
    skip_0:
    // 0x808010C8: jal         0x800B7B38
    // 0x808010CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800B7B38(rdram, ctx);
        goto after_3;
    // 0x808010CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x808010D0: b           L_808010F4
    // 0x808010D4: lh          $t1, 0x172($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X172);
        goto L_808010F4;
    // 0x808010D4: lh          $t1, 0x172($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X172);
    // 0x808010D8: lw          $t8, 0x1E4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1E4);
L_808010DC:
    // 0x808010DC: sll         $t0, $t8, 12
    ctx->r8 = S32(ctx->r24 << 12);
    // 0x808010E0: bgezl       $t0, L_808010F4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x808010E4: lh          $t1, 0x172($s0)
        ctx->r9 = MEM_H(ctx->r16, 0X172);
            goto L_808010F4;
    }
    goto skip_1;
    // 0x808010E4: lh          $t1, 0x172($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X172);
    skip_1:
    // 0x808010E8: jal         0x800B7B38
    // 0x808010EC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800B7B38(rdram, ctx);
        goto after_4;
    // 0x808010EC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
    // 0x808010F0: lh          $t1, 0x172($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X172);
L_808010F4:
    // 0x808010F4: addiu       $at, $zero, 0x44
    ctx->r1 = ADD32(0, 0X44);
    // 0x808010F8: bnel        $t1, $at, L_8080113C
    if (ctx->r9 != ctx->r1) {
        // 0x808010FC: lbu         $t5, 0x1E4($s0)
        ctx->r13 = MEM_BU(ctx->r16, 0X1E4);
            goto L_8080113C;
    }
    goto skip_2;
    // 0x808010FC: lbu         $t5, 0x1E4($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X1E4);
    skip_2:
    // 0x80801100: lh          $t2, 0x1AE($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X1AE);
    // 0x80801104: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80801108: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080110C: lwc1        $f6, 0x1DC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1DC);
    // 0x80801110: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x80801114: mul.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80801118: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8080111C: add.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80801120: trunc.w.s   $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80801124: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x80801128: nop

    // 0x8080112C: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x80801130: b           L_8080125C
    // 0x80801134: lw          $v0, 0x1E4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E4);
        goto L_8080125C;
    // 0x80801134: lw          $v0, 0x1E4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E4);
    // 0x80801138: lbu         $t5, 0x1E4($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X1E4);
L_8080113C:
    // 0x8080113C: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x80801140: beql        $t6, $zero, L_808011D8
    if (ctx->r14 == 0) {
        // 0x80801144: lh          $t6, 0x1E6($s0)
        ctx->r14 = MEM_H(ctx->r16, 0X1E6);
            goto L_808011D8;
    }
    goto skip_3;
    // 0x80801144: lh          $t6, 0x1E6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1E6);
    skip_3:
    // 0x80801148: jal         0x800A8184
    // 0x8080114C: nop

    func_800A8184(rdram, ctx);
        goto after_5;
    // 0x8080114C: nop

    after_5:
    // 0x80801150: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801154: bne         $v0, $at, L_80801198
    if (ctx->r2 != ctx->r1) {
        // 0x80801158: addiu       $t1, $zero, 0x130
        ctx->r9 = ADD32(0, 0X130);
            goto L_80801198;
    }
    // 0x80801158: addiu       $t1, $zero, 0x130
    ctx->r9 = ADD32(0, 0X130);
    // 0x8080115C: lui         $at, 0x4358
    ctx->r1 = S32(0X4358 << 16);
    // 0x80801160: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801164: lwc1        $f8, 0x1DC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1DC);
    // 0x80801168: lh          $t7, 0x1AE($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1AE);
    // 0x8080116C: lwc1        $f18, 0x1F4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1F4);
    // 0x80801170: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80801174: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80801178: nop

    // 0x8080117C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80801180: mul.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80801184: sub.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x80801188: trunc.w.s   $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8080118C: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80801190: b           L_808011CC
    // 0x80801194: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
        goto L_808011CC;
    // 0x80801194: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
L_80801198:
    // 0x80801198: lh          $t0, 0x1AE($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X1AE);
    // 0x8080119C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x808011A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808011A4: lwc1        $f4, 0x1DC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1DC);
    // 0x808011A8: subu        $t2, $t1, $t0
    ctx->r10 = SUB32(ctx->r9, ctx->r8);
    // 0x808011AC: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x808011B0: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x808011B4: cvt.s.w     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808011B8: add.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x808011BC: trunc.w.s   $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x808011C0: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x808011C4: nop

    // 0x808011C8: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
L_808011CC:
    // 0x808011CC: b           L_8080125C
    // 0x808011D0: lw          $v0, 0x1E4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E4);
        goto L_8080125C;
    // 0x808011D0: lw          $v0, 0x1E4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E4);
    // 0x808011D4: lh          $t6, 0x1E6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1E6);
L_808011D8:
    // 0x808011D8: lw          $v0, 0x1E4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E4);
    // 0x808011DC: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x808011E0: bgezl       $t6, L_80801228
    if (SIGNED(ctx->r14) >= 0) {
        // 0x808011E4: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_80801228;
    }
    goto skip_4;
    // 0x808011E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_4:
    // 0x808011E8: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x808011EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808011F0: lwc1        $f16, 0x1DC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X1DC);
    // 0x808011F4: lh          $t7, 0x1AE($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1AE);
    // 0x808011F8: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x808011FC: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80801200: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80801204: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801208: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8080120C: add.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80801210: add.s       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80801214: trunc.w.s   $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80801218: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x8080121C: b           L_8080125C
    // 0x80801220: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
        goto L_8080125C;
    // 0x80801220: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x80801224: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_80801228:
    // 0x80801228: lwc1        $f10, 0x1DC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1DC);
    // 0x8080122C: lh          $t1, 0x1AE($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X1AE);
    // 0x80801230: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80801234: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80801238: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8080123C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801240: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80801244: add.s       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80801248: add.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8080124C: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80801250: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x80801254: nop

    // 0x80801258: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
L_8080125C:
    // 0x8080125C: sll         $t4, $v0, 1
    ctx->r12 = S32(ctx->r2 << 1);
    // 0x80801260: bgez        $t4, L_808012D4
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80801264: sll         $t6, $v0, 14
        ctx->r14 = S32(ctx->r2 << 14);
            goto L_808012D4;
    }
    // 0x80801264: sll         $t6, $v0, 14
    ctx->r14 = S32(ctx->r2 << 14);
    // 0x80801268: bgez        $t6, L_8080129C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8080126C: sll         $t8, $v0, 12
        ctx->r24 = S32(ctx->r2 << 12);
            goto L_8080129C;
    }
    // 0x8080126C: sll         $t8, $v0, 12
    ctx->r24 = S32(ctx->r2 << 12);
    // 0x80801270: bgez        $t8, L_80801280
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80801274: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_80801280;
    }
    // 0x80801274: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x80801278: b           L_80801280
    // 0x8080127C: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
        goto L_80801280;
    // 0x8080127C: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_80801280:
    // 0x80801280: lh          $t9, 0x1B0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X1B0);
    // 0x80801284: bgez        $v0, L_80801294
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80801288: sra         $t1, $v0, 1
        ctx->r9 = S32(SIGNED(ctx->r2) >> 1);
            goto L_80801294;
    }
    // 0x80801288: sra         $t1, $v0, 1
    ctx->r9 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8080128C: addiu       $at, $v0, 0x1
    ctx->r1 = ADD32(ctx->r2, 0X1);
    // 0x80801290: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_80801294:
    // 0x80801294: jal         0x800B7B2C
    // 0x80801298: subu        $a0, $t9, $t1
    ctx->r4 = SUB32(ctx->r25, ctx->r9);
    func_800B7B2C(rdram, ctx);
        goto after_6;
    // 0x80801298: subu        $a0, $t9, $t1
    ctx->r4 = SUB32(ctx->r25, ctx->r9);
    after_6:
L_8080129C:
    // 0x8080129C: addiu       $a3, $s0, 0x60
    ctx->r7 = ADD32(ctx->r16, 0X60);
    // 0x808012A0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x808012A4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x808012A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012AC: jal         0x80800E44
    // 0x808012B0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_80800E44_gczoombox(rdram, ctx);
        goto after_7;
    // 0x808012B0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_7:
    // 0x808012B4: lwc1        $f18, 0x1A4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1A4);
    // 0x808012B8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x808012BC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808012C0: trunc.w.s   $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x808012C4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x808012C8: jal         0x800B798C
    // 0x808012CC: nop

    func_800B798C(rdram, ctx);
        goto after_8;
    // 0x808012CC: nop

    after_8:
    // 0x808012D0: lw          $v0, 0x1E4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E4);
L_808012D4:
    // 0x808012D4: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x808012D8: bgezl       $t3, L_80801324
    if (SIGNED(ctx->r11) >= 0) {
        // 0x808012DC: lb          $t6, 0x1E7($s0)
        ctx->r14 = MEM_B(ctx->r16, 0X1E7);
            goto L_80801324;
    }
    goto skip_5;
    // 0x808012DC: lb          $t6, 0x1E7($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1E7);
    skip_5:
    // 0x808012E0: jal         0x800B7B2C
    // 0x808012E4: addiu       $a0, $zero, -0x7FFF
    ctx->r4 = ADD32(0, -0X7FFF);
    func_800B7B2C(rdram, ctx);
        goto after_9;
    // 0x808012E4: addiu       $a0, $zero, -0x7FFF
    ctx->r4 = ADD32(0, -0X7FFF);
    after_9:
    // 0x808012E8: addiu       $a3, $s0, 0x90
    ctx->r7 = ADD32(ctx->r16, 0X90);
    // 0x808012EC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x808012F0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x808012F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012F8: jal         0x80800E44
    // 0x808012FC: addiu       $a2, $s0, 0x30
    ctx->r6 = ADD32(ctx->r16, 0X30);
    func_80800E44_gczoombox(rdram, ctx);
        goto after_10;
    // 0x808012FC: addiu       $a2, $s0, 0x30
    ctx->r6 = ADD32(ctx->r16, 0X30);
    after_10:
    // 0x80801300: lwc1        $f6, 0x1A8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1A8);
    // 0x80801304: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80801308: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8080130C: trunc.w.s   $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80801310: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80801314: jal         0x800B798C
    // 0x80801318: nop

    func_800B798C(rdram, ctx);
        goto after_11;
    // 0x80801318: nop

    after_11:
    // 0x8080131C: lw          $v0, 0x1E4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E4);
    // 0x80801320: lb          $t6, 0x1E7($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1E7);
L_80801324:
    // 0x80801324: sll         $t8, $v0, 30
    ctx->r24 = S32(ctx->r2 << 30);
    // 0x80801328: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8080132C: bgezl       $t6, L_80801348
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80801330: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_80801348;
    }
    goto skip_6;
    // 0x80801330: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_6:
    // 0x80801334: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801338: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080133C: b           L_8080134C
    // 0x80801340: nop

        goto L_8080134C;
    // 0x80801340: nop

    // 0x80801344: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_80801348:
    // 0x80801348: nop

L_8080134C:
    // 0x8080134C: bgez        $t8, L_80801364
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80801350: nop
    
            goto L_80801364;
    }
    // 0x80801350: nop

    // 0x80801354: jal         0x800885F8
    // 0x80801358: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    _glintrosyncDll_entrypoint_5(rdram, ctx);
        goto after_12;
    // 0x80801358: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    after_12:
    // 0x8080135C: b           L_80801370
    // 0x80801360: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
        goto L_80801370;
    // 0x80801360: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
L_80801364:
    // 0x80801364: jal         0x800D8FF8
    // 0x80801368: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_13;
    // 0x80801368: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    after_13:
    // 0x8080136C: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
L_80801370:
    // 0x80801370: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80801374: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801378: lwc1        $f10, 0x1E8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1E8);
    // 0x8080137C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80801380: mul.s       $f18, $f0, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80801384: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801388: mul.s       $f8, $f18, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8080138C: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80801390: swc1        $f6, 0x1E8($s0)
    MEM_W(0X1E8, ctx->r16) = ctx->f6.u32l;
    // 0x80801394: lwc1        $f2, 0x1E8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X1E8);
    // 0x80801398: c.le.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl <= ctx->f2.fl;
    // 0x8080139C: nop

    // 0x808013A0: bc1fl       L_808013D8
    if (!c1cs) {
        // 0x808013A4: mtc1        $zero, $f18
        ctx->f18.u32l = 0;
            goto L_808013D8;
    }
    goto skip_7;
    // 0x808013A4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    skip_7:
    // 0x808013A8: lbu         $v0, 0x1E7($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1E7);
    // 0x808013AC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2578, 0X3DD4) << 16);
    // 0x808013B0: lwc1        $f4, 0x3DD4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2578, 0X3DD4));
    // 0x808013B4: srl         $t9, $v0, 7
    ctx->r25 = S32(U32(ctx->r2) >> 7);
    // 0x808013B8: xori        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 ^ 0X1;
    // 0x808013BC: sll         $t3, $t0, 7
    ctx->r11 = S32(ctx->r8 << 7);
    // 0x808013C0: andi        $t4, $v0, 0xFF7F
    ctx->r12 = ctx->r2 & 0XFF7F;
    // 0x808013C4: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x808013C8: sb          $t5, 0x1E7($s0)
    MEM_B(0X1E7, ctx->r16) = ctx->r13;
    // 0x808013CC: b           L_80801410
    // 0x808013D0: swc1        $f4, 0x1E8($s0)
    MEM_W(0X1E8, ctx->r16) = ctx->f4.u32l;
        goto L_80801410;
    // 0x808013D0: swc1        $f4, 0x1E8($s0)
    MEM_W(0X1E8, ctx->r16) = ctx->f4.u32l;
    // 0x808013D4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_808013D8:
    // 0x808013D8: nop

    // 0x808013DC: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x808013E0: nop

    // 0x808013E4: bc1fl       L_80801414
    if (!c1cs) {
        // 0x808013E8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801414;
    }
    goto skip_8;
    // 0x808013E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_8:
    // 0x808013EC: lbu         $v0, 0x1E7($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1E7);
    // 0x808013F0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x808013F4: srl         $t6, $v0, 7
    ctx->r14 = S32(U32(ctx->r2) >> 7);
    // 0x808013F8: xori        $t8, $t6, 0x1
    ctx->r24 = ctx->r14 ^ 0X1;
    // 0x808013FC: sll         $t1, $t8, 7
    ctx->r9 = S32(ctx->r24 << 7);
    // 0x80801400: andi        $t0, $v0, 0xFF7F
    ctx->r8 = ctx->r2 & 0XFF7F;
    // 0x80801404: or          $t2, $t1, $t0
    ctx->r10 = ctx->r9 | ctx->r8;
    // 0x80801408: sb          $t2, 0x1E7($s0)
    MEM_B(0X1E7, ctx->r16) = ctx->r10;
    // 0x8080140C: swc1        $f10, 0x1E8($s0)
    MEM_W(0X1E8, ctx->r16) = ctx->f10.u32l;
L_80801410:
    // 0x80801410: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801414:
    // 0x80801414: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801418: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8080141C: jr          $ra
    // 0x80801420: nop

    return;
    // 0x80801420: nop

;}
RECOMP_FUNC void func_8008F568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F568: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008F56C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008F570: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8008F574: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8008F578: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8008F57C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x8008F580: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8008F584: jal         0x80084D40
    // 0x8008F588: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    _bahold_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x8008F588: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    after_0:
    // 0x8008F58C: beq         $v0, $zero, L_8008F5A4
    if (ctx->r2 == 0) {
        // 0x8008F590: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8008F5A4;
    }
    // 0x8008F590: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008F594: jal         0x80106790
    // 0x8008F598: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x8008F598: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x8008F59C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008F5A0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_8008F5A4:
    // 0x8008F5A4: beq         $a0, $zero, L_8008F5CC
    if (ctx->r4 == 0) {
        // 0x8008F5A8: lw          $t0, 0x1C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X1C);
            goto L_8008F5CC;
    }
    // 0x8008F5A8: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8008F5AC: lw          $t1, 0x6C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X6C);
    // 0x8008F5B0: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8008F5B4: sll         $t2, $t1, 11
    ctx->r10 = S32(ctx->r9 << 11);
    // 0x8008F5B8: srl         $t3, $t2, 20
    ctx->r11 = S32(U32(ctx->r10) >> 20);
    // 0x8008F5BC: beql        $t9, $t3, L_8008F5D0
    if (ctx->r25 == ctx->r11) {
        // 0x8008F5C0: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_8008F5D0;
    }
    goto skip_0;
    // 0x8008F5C0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_0:
    // 0x8008F5C4: b           L_8008F61C
    // 0x8008F5C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008F61C;
    // 0x8008F5C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008F5CC:
    // 0x8008F5CC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_8008F5D0:
    // 0x8008F5D0: jal         0x8008E9A0
    // 0x8008F5D4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8008E9A0(rdram, ctx);
        goto after_2;
    // 0x8008F5D4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x8008F5D8: jal         0x800D1B34
    // 0x8008F5DC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800D1B34(rdram, ctx);
        goto after_3;
    // 0x8008F5DC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x8008F5E0: jal         0x800D1C38
    // 0x8008F5E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800D1C38(rdram, ctx);
        goto after_4;
    // 0x8008F5E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x8008F5E8: bne         $v0, $zero, L_8008F600
    if (ctx->r2 != 0) {
        // 0x8008F5EC: nop
    
            goto L_8008F600;
    }
    // 0x8008F5EC: nop

    // 0x8008F5F0: jal         0x800904C8
    // 0x8008F5F4: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    func_800904C8(rdram, ctx);
        goto after_5;
    // 0x8008F5F4: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    after_5:
    // 0x8008F5F8: b           L_8008F608
    // 0x8008F5FC: nop

        goto L_8008F608;
    // 0x8008F5FC: nop

L_8008F600:
    // 0x8008F600: b           L_8008F61C
    // 0x8008F604: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8008F61C;
    // 0x8008F604: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008F608:
    // 0x8008F608: jal         0x80106790
    // 0x8008F60C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_80106790(rdram, ctx);
        goto after_6;
    // 0x8008F60C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x8008F610: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8008F614: sw          $v0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r2;
    // 0x8008F618: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008F61C:
    // 0x8008F61C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008F620: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8008F624: jr          $ra
    // 0x8008F628: nop

    return;
    // 0x8008F628: nop

;}
RECOMP_FUNC void func_80809D24_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80809D24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80809D28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80809D2C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80809D30: jal         0x80809DD0
    // 0x80809D34: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80809DD0_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80809D34: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80809D38: jal         0x80809F74
    // 0x80809D3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80809F74_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80809D3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80809D40: jal         0x8080A03C
    // 0x80809D44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080A03C_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80809D44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80809D48: jal         0x8080A194
    // 0x80809D4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080A194_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x80809D4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80809D50: jal         0x8080A250
    // 0x80809D54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080A250_bsfirstp(rdram, ctx);
        goto after_4;
    // 0x80809D54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80809D58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80809D5C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80809D60: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80809D64: jr          $ra
    // 0x80809D68: nop

    return;
    // 0x80809D68: nop

;}
RECOMP_FUNC void _gcmapDll_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088128: syscall     672
    recomp_syscall_handler(rdram, ctx, 0x80088128);
    return;
    // 0x8008812C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_808004D0_chmole_training(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808004D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808004D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808004DC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x808004E0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808004E4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x808004E8: lwc1        $f4, 0x54($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X54);
    // 0x808004EC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x808004F0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808004F4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x808004F8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x808004FC: nop

    // 0x80800500: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80800504: beql        $t7, $zero, L_80800554
    if (ctx->r15 == 0) {
        // 0x80800508: mfc1        $t7, $f6
        ctx->r15 = (int32_t)ctx->f6.u32l;
            goto L_80800554;
    }
    goto skip_0;
    // 0x80800508: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x8080050C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800510: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800514: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800518: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8080051C: nop

    // 0x80800520: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80800524: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80800528: nop

    // 0x8080052C: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80800530: bne         $t7, $zero, L_80800548
    if (ctx->r15 != 0) {
        // 0x80800534: nop
    
            goto L_80800548;
    }
    // 0x80800534: nop

    // 0x80800538: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8080053C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800540: b           L_80800560
    // 0x80800544: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80800560;
    // 0x80800544: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80800548:
    // 0x80800548: b           L_80800560
    // 0x8080054C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80800560;
    // 0x8080054C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80800550: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
L_80800554:
    // 0x80800554: nop

    // 0x80800558: bltz        $t7, L_80800548
    if (SIGNED(ctx->r15) < 0) {
        // 0x8080055C: nop
    
            goto L_80800548;
    }
    // 0x8080055C: nop

L_80800560:
    // 0x80800560: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80800564: sltiu       $at, $t7, 0x8
    ctx->r1 = ctx->r15 < 0X8 ? 1 : 0;
    // 0x80800568: beq         $at, $zero, L_808006C4
    if (ctx->r1 == 0) {
        // 0x8080056C: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_808006C4;
    }
    // 0x8080056C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800570: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1604, 0XD34) << 16);
    // 0x80800574: addu        $at, $at, $t7
    gpr jr_addend_8080057C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800578: lw          $t7, 0xD34($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1604, 0XD34));
    // 0x8080057C: jr          $t7
    // 0x80800580: nop

    switch (jr_addend_8080057C >> 2) {
        case 0: goto L_8080062C; break;
        case 1: goto L_80800584; break;
        case 2: goto L_808005BC; break;
        case 3: goto L_80800654; break;
        case 4: goto L_808005F4; break;
        case 5: goto L_808006A4; break;
        case 6: goto L_808006C4; break;
        case 7: goto L_8080067C; break;
        default: switch_error(__func__, 0x8080057C, 0x80800D34);
    }
    // 0x80800580: nop

L_80800584:
    // 0x80800584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800588: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080058C: jal         0x80087CF8
    // 0x80800590: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_0;
    // 0x80800590: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_0:
    // 0x80800594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800598: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080059C: jal         0x80087CF8
    // 0x808005A0: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_1;
    // 0x808005A0: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    after_1:
    // 0x808005A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808005AC: jal         0x80087CF8
    // 0x808005B0: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x808005B0: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    after_2:
    // 0x808005B4: b           L_808006C8
    // 0x808005B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808006C8;
    // 0x808005B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808005BC:
    // 0x808005BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808005C4: jal         0x80087CF8
    // 0x808005C8: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_3;
    // 0x808005C8: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_3:
    // 0x808005CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808005D4: jal         0x80087CF8
    // 0x808005D8: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_4;
    // 0x808005D8: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_4:
    // 0x808005DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808005E4: jal         0x80087CF8
    // 0x808005E8: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_5;
    // 0x808005E8: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    after_5:
    // 0x808005EC: b           L_808006C8
    // 0x808005F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808006C8;
    // 0x808005F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808005F4:
    // 0x808005F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808005FC: jal         0x80087CF8
    // 0x80800600: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_6;
    // 0x80800600: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    after_6:
    // 0x80800604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800608: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080060C: jal         0x80087CF8
    // 0x80800610: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_7;
    // 0x80800610: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    after_7:
    // 0x80800614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800618: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080061C: jal         0x80087CF8
    // 0x80800620: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_8;
    // 0x80800620: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    after_8:
    // 0x80800624: b           L_808006C8
    // 0x80800628: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808006C8;
    // 0x80800628: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080062C:
    // 0x8080062C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800630: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800634: jal         0x80087CF8
    // 0x80800638: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_9;
    // 0x80800638: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_9:
    // 0x8080063C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800640: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800644: jal         0x80087CF8
    // 0x80800648: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_10;
    // 0x80800648: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    after_10:
    // 0x8080064C: b           L_808006C8
    // 0x80800650: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808006C8;
    // 0x80800650: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800654:
    // 0x80800654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800658: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080065C: jal         0x80087CF8
    // 0x80800660: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_11;
    // 0x80800660: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_11:
    // 0x80800664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800668: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080066C: jal         0x80087CF8
    // 0x80800670: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_12;
    // 0x80800670: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_12:
    // 0x80800674: b           L_808006C8
    // 0x80800678: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808006C8;
    // 0x80800678: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080067C:
    // 0x8080067C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800680: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800684: jal         0x80087CF8
    // 0x80800688: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_13;
    // 0x80800688: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_13:
    // 0x8080068C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800690: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800694: jal         0x80087CF8
    // 0x80800698: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_14;
    // 0x80800698: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    after_14:
    // 0x8080069C: b           L_808006C8
    // 0x808006A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808006C8;
    // 0x808006A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808006A4:
    // 0x808006A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808006AC: jal         0x80087CF8
    // 0x808006B0: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_15;
    // 0x808006B0: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    after_15:
    // 0x808006B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808006BC: jal         0x80087CF8
    // 0x808006C0: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_16;
    // 0x808006C0: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    after_16:
L_808006C4:
    // 0x808006C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808006C8:
    // 0x808006C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808006CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808006D0: jr          $ra
    // 0x808006D4: nop

    return;
    // 0x808006D4: nop

;}
RECOMP_FUNC void baroll_getStructSize(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C2D0: jr          $ra
    // 0x8009C2D4: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    return;
    // 0x8009C2D4: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800D2148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2148: srl         $v1, $a1, 1
    ctx->r3 = S32(U32(ctx->r5) >> 1);
    // 0x800D214C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D2150: slti        $at, $v1, 0x18
    ctx->r1 = SIGNED(ctx->r3) < 0X18 ? 1 : 0;
    // 0x800D2154: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D2158: bne         $at, $zero, L_800D2164
    if (ctx->r1 != 0) {
        // 0x800D215C: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_800D2164;
    }
    // 0x800D215C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800D2160: addiu       $v1, $zero, 0x17
    ctx->r3 = ADD32(0, 0X17);
L_800D2164:
    // 0x800D2164: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800D2168: addiu       $a0, $a0, -0x4DA0
    ctx->r4 = ADD32(ctx->r4, -0X4DA0);
    // 0x800D216C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800D2170: jal         0x8001BBA0
    // 0x800D2174: sll         $a2, $v1, 1
    ctx->r6 = S32(ctx->r3 << 1);
    rare_memcpy(rdram, ctx);
        goto after_0;
    // 0x800D2174: sll         $a2, $v1, 1
    ctx->r6 = S32(ctx->r3 << 1);
    after_0:
    // 0x800D2178: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D217C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D2180: jr          $ra
    // 0x800D2184: nop

    return;
    // 0x800D2184: nop

;}
RECOMP_FUNC void func_800D1A04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1A04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D1A08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D1A0C: jal         0x800D16C4
    // 0x800D1A10: nop

    func_800D16C4(rdram, ctx);
        goto after_0;
    // 0x800D1A10: nop

    after_0:
    // 0x800D1A14: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800D1A18: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800D1A1C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800D1A20: lh          $t7, -0x50AE($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X50AE);
    // 0x800D1A24: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800D1A28: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800D1A2C: bne         $t7, $at, L_800D1A3C
    if (ctx->r15 != ctx->r1) {
        // 0x800D1A30: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D1A3C;
    }
    // 0x800D1A30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D1A34: b           L_800D1A64
    // 0x800D1A38: addiu       $v0, $zero, 0x3E7
    ctx->r2 = ADD32(0, 0X3E7);
        goto L_800D1A64;
    // 0x800D1A38: addiu       $v0, $zero, 0x3E7
    ctx->r2 = ADD32(0, 0X3E7);
L_800D1A3C:
    // 0x800D1A3C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800D1A40: lw          $t8, -0x4DB0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4DB0);
    // 0x800D1A44: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x800D1A48: sll         $t3, $v1, 3
    ctx->r11 = S32(ctx->r3 << 3);
    // 0x800D1A4C: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x800D1A50: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800D1A54: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800D1A58: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x800D1A5C: lh          $t4, 0x1A04($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X1A04);
    // 0x800D1A60: xor         $v0, $t4, $t1
    ctx->r2 = ctx->r12 ^ ctx->r9;
L_800D1A64:
    // 0x800D1A64: jr          $ra
    // 0x800D1A68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800D1A68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80800000_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: addiu       $t6, $zero, 0x9
    ctx->r14 = ADD32(0, 0X9);
    // 0x8080000C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800010: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800014: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800018: jal         0x8009FFD8
    // 0x8080001C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_0;
    // 0x8080001C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_0:
    // 0x80800020: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800024: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800028: jr          $ra
    // 0x8080002C: nop

    return;
    // 0x8080002C: nop

;}
RECOMP_FUNC void func_800FE820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FE820: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800FE824: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800FE828: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FE82C: addiu       $v0, $v0, 0x59C0
    ctx->r2 = ADD32(ctx->r2, 0X59C0);
    // 0x800FE830: div.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800FE834: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800FE838: sb          $t6, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r14;
    // 0x800FE83C: jr          $ra
    // 0x800FE840: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x800FE840: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_808015D4_chsabreman(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808015D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808015D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808015DC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808015E0: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x808015E4: jal         0x8008A0D0
    // 0x808015E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x808015E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808015EC: beq         $v0, $zero, L_80801608
    if (ctx->r2 == 0) {
        // 0x808015F0: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80801608;
    }
    // 0x808015F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808015F4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808015F8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x808015FC: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    // 0x80801600: jal         0x80089F18
    // 0x80801604: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    _sudeflect_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80801604: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_1:
L_80801608:
    // 0x80801608: jal         0x80801218
    // 0x8080160C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80801218_chsabreman(rdram, ctx);
        goto after_2;
    // 0x8080160C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80801610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801614: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801618: jr          $ra
    // 0x8080161C: nop

    return;
    // 0x8080161C: nop

;}
RECOMP_FUNC void func_808018BC_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808018BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
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
    // 0x808018D4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808018D8: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    // 0x808018DC: jal         0x800D0A9C
    // 0x808018E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_1;
    // 0x808018E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808018E4: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x808018E8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x808018EC: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x808018F0: andi        $t8, $t7, 0x8
    ctx->r24 = ctx->r15 & 0X8;
    // 0x808018F4: andi        $t0, $t9, 0xFFF7
    ctx->r8 = ctx->r25 & 0XFFF7;
    // 0x808018F8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808018FC: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80801900: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    // 0x80801904: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80801908: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8080190C: sb          $zero, 0xFA($v1)
    MEM_B(0XFA, ctx->r3) = 0;
    // 0x80801910: jal         0x800D0A9C
    // 0x80801914: swc1        $f4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
    func_800D0A9C(rdram, ctx);
        goto after_2;
    // 0x80801914: swc1        $f4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
    after_2:
    // 0x80801918: beq         $v0, $zero, L_80801930
    if (ctx->r2 == 0) {
        // 0x8080191C: addiu       $a0, $zero, 0x16
        ctx->r4 = ADD32(0, 0X16);
            goto L_80801930;
    }
    // 0x8080191C: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x80801920: jal         0x800D0A9C
    // 0x80801924: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800D0A9C(rdram, ctx);
        goto after_3;
    // 0x80801924: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
    // 0x80801928: beq         $v0, $zero, L_8080194C
    if (ctx->r2 == 0) {
        // 0x8080192C: nop
    
            goto L_8080194C;
    }
    // 0x8080192C: nop

L_80801930:
    // 0x80801930: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80801934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801938: addiu       $a1, $zero, 0x8A1
    ctx->r5 = ADD32(0, 0X8A1);
    // 0x8080193C: jal         0x80103140
    // 0x80801940: lhu         $a2, 0x16($t2)
    ctx->r6 = MEM_HU(ctx->r10, 0X16);
    func_80103140(rdram, ctx);
        goto after_4;
    // 0x80801940: lhu         $a2, 0x16($t2)
    ctx->r6 = MEM_HU(ctx->r10, 0X16);
    after_4:
    // 0x80801944: b           L_80801A84
    // 0x80801948: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801A84;
    // 0x80801948: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080194C:
    // 0x8080194C: jal         0x80800000
    // 0x80801950: nop

    func_80800000_chclockworkmouse(rdram, ctx);
        goto after_5;
    // 0x80801950: nop

    after_5:
    // 0x80801954: beq         $v0, $zero, L_80801974
    if (ctx->r2 == 0) {
        // 0x80801958: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80801974;
    }
    // 0x80801958: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080195C: beq         $v0, $at, L_8080199C
    if (ctx->r2 == ctx->r1) {
        // 0x80801960: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080199C;
    }
    // 0x80801960: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801964: beql        $v0, $at, L_80801A04
    if (ctx->r2 == ctx->r1) {
        // 0x80801968: lw          $t0, 0x64($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X64);
            goto L_80801A04;
    }
    goto skip_0;
    // 0x80801968: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
    skip_0:
    // 0x8080196C: b           L_80801A78
    // 0x80801970: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801A78;
    // 0x80801970: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801974:
    // 0x80801974: jal         0x800DA298
    // 0x80801978: addiu       $a0, $zero, 0x504
    ctx->r4 = ADD32(0, 0X504);
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x80801978: addiu       $a0, $zero, 0x504
    ctx->r4 = ADD32(0, 0X504);
    after_6:
    // 0x8080197C: bne         $v0, $zero, L_80801A74
    if (ctx->r2 != 0) {
        // 0x80801980: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801A74;
    }
    // 0x80801980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801984: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80801988: addiu       $a1, $zero, 0x8A1
    ctx->r5 = ADD32(0, 0X8A1);
    // 0x8080198C: jal         0x80103140
    // 0x80801990: lhu         $a2, 0x16($t3)
    ctx->r6 = MEM_HU(ctx->r11, 0X16);
    func_80103140(rdram, ctx);
        goto after_7;
    // 0x80801990: lhu         $a2, 0x16($t3)
    ctx->r6 = MEM_HU(ctx->r11, 0X16);
    after_7:
    // 0x80801994: b           L_80801A78
    // 0x80801998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801A78;
    // 0x80801998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080199C:
    // 0x8080199C: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
    // 0x808019A0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808019A4: addiu       $a0, $zero, 0x313
    ctx->r4 = ADD32(0, 0X313);
    // 0x808019A8: sll         $t6, $t4, 12
    ctx->r14 = S32(ctx->r12 << 12);
    // 0x808019AC: bgez        $t6, L_808019C8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x808019B0: nop
    
            goto L_808019C8;
    }
    // 0x808019B0: nop

    // 0x808019B4: jal         0x80088480
    // 0x808019B8: addiu       $a0, $zero, 0x314
    ctx->r4 = ADD32(0, 0X314);
    _glsplinefind_entrypoint_0(rdram, ctx);
        goto after_8;
    // 0x808019B8: addiu       $a0, $zero, 0x314
    ctx->r4 = ADD32(0, 0X314);
    after_8:
    // 0x808019BC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x808019C0: b           L_808019D8
    // 0x808019C4: sh          $v0, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r2;
        goto L_808019D8;
    // 0x808019C4: sh          $v0, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r2;
L_808019C8:
    // 0x808019C8: jal         0x80088480
    // 0x808019CC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _glsplinefind_entrypoint_0(rdram, ctx);
        goto after_9;
    // 0x808019CC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_9:
    // 0x808019D0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x808019D4: sh          $v0, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r2;
L_808019D8:
    // 0x808019D8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x808019DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808019E0: lw          $a2, 0x24($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X24);
    // 0x808019E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808019E8: jal         0x801058C4
    // 0x808019EC: lh          $a1, 0x0($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X0);
    func_801058C4(rdram, ctx);
        goto after_10;
    // 0x808019EC: lh          $a1, 0x0($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X0);
    after_10:
    // 0x808019F0: jal         0x8080111C
    // 0x808019F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080111C_chclockworkmouse(rdram, ctx);
        goto after_11;
    // 0x808019F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808019F8: b           L_80801A78
    // 0x808019FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801A78;
    // 0x808019FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A00: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
L_80801A04:
    // 0x80801A04: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80801A08: addiu       $a0, $zero, 0x1F6
    ctx->r4 = ADD32(0, 0X1F6);
    // 0x80801A0C: sll         $t2, $t0, 12
    ctx->r10 = S32(ctx->r8 << 12);
    // 0x80801A10: bgez        $t2, L_80801A28
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80801A14: nop
    
            goto L_80801A28;
    }
    // 0x80801A14: nop

    // 0x80801A18: jal         0x80088278
    // 0x80801A1C: addiu       $a0, $zero, 0x201
    ctx->r4 = ADD32(0, 0X201);
    _gccubesearch_entrypoint_0(rdram, ctx);
        goto after_12;
    // 0x80801A1C: addiu       $a0, $zero, 0x201
    ctx->r4 = ADD32(0, 0X201);
    after_12:
    // 0x80801A20: b           L_80801A34
    // 0x80801A24: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_80801A34;
    // 0x80801A24: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80801A28:
    // 0x80801A28: jal         0x80088278
    // 0x80801A2C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _gccubesearch_entrypoint_0(rdram, ctx);
        goto after_13;
    // 0x80801A2C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_13:
    // 0x80801A30: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80801A34:
    // 0x80801A34: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80801A38: jal         0x800EE88C
    // 0x80801A3C: addiu       $a0, $a0, 0x114
    ctx->r4 = ADD32(ctx->r4, 0X114);
    func_800EE88C(rdram, ctx);
        goto after_14;
    // 0x80801A3C: addiu       $a0, $a0, 0x114
    ctx->r4 = ADD32(ctx->r4, 0X114);
    after_14:
    // 0x80801A40: lw          $t3, 0x64($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X64);
    // 0x80801A44: sll         $t5, $t3, 12
    ctx->r13 = S32(ctx->r11 << 12);
    // 0x80801A48: bgezl       $t5, L_80801A78
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80801A4C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801A78;
    }
    goto skip_1;
    // 0x80801A4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80801A50: jal         0x80800090
    // 0x80801A54: nop

    func_80800090_chclockworkmouse(rdram, ctx);
        goto after_15;
    // 0x80801A54: nop

    after_15:
    // 0x80801A58: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801A5C: bne         $v0, $at, L_80801A74
    if (ctx->r2 != ctx->r1) {
        // 0x80801A60: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801A74;
    }
    // 0x80801A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A64: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80801A68: addiu       $a1, $zero, 0x8A1
    ctx->r5 = ADD32(0, 0X8A1);
    // 0x80801A6C: jal         0x80103140
    // 0x80801A70: lhu         $a2, 0x16($t6)
    ctx->r6 = MEM_HU(ctx->r14, 0X16);
    func_80103140(rdram, ctx);
        goto after_16;
    // 0x80801A70: lhu         $a2, 0x16($t6)
    ctx->r6 = MEM_HU(ctx->r14, 0X16);
    after_16:
L_80801A74:
    // 0x80801A74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801A78:
    // 0x80801A78: jal         0x80108B04
    // 0x80801A7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_17;
    // 0x80801A7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_17:
    // 0x80801A80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801A84:
    // 0x80801A84: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801A88: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801A8C: jr          $ra
    // 0x80801A90: nop

    return;
    // 0x80801A90: nop

;}
RECOMP_FUNC void func_80800738_gcfrontend(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800738: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080073C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800740: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800744: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800748: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8080074C: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x80800750: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80800754: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x80800758: jal         0x800D39A8
    // 0x8080075C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    func_800D39A8(rdram, ctx);
        goto after_0;
    // 0x8080075C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_0:
    // 0x80800760: jal         0x800D39DC
    // 0x80800764: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800D39DC(rdram, ctx);
        goto after_1;
    // 0x80800764: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80800768: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8080076C: beql        $t8, $zero, L_80800794
    if (ctx->r24 == 0) {
        // 0x80800770: lw          $t9, 0x28($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X28);
            goto L_80800794;
    }
    goto skip_0;
    // 0x80800770: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    skip_0:
    // 0x80800774: jal         0x800D3B24
    // 0x80800778: nop

    func_800D3B24(rdram, ctx);
        goto after_2;
    // 0x80800778: nop

    after_2:
    // 0x8080077C: jal         0x80800520
    // 0x80800780: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_80800520_gcfrontend(rdram, ctx);
        goto after_3;
    // 0x80800780: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80800784: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80800788: jal         0x8080068C
    // 0x8080078C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8080068C_gcfrontend(rdram, ctx);
        goto after_4;
    // 0x8080078C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_4:
    // 0x80800790: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
L_80800794:
    // 0x80800794: bnel        $t9, $zero, L_808007A8
    if (ctx->r25 != 0) {
        // 0x80800798: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808007A8;
    }
    goto skip_1;
    // 0x80800798: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_1:
    // 0x8080079C: jal         0x800EA334
    // 0x808007A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800EA334(rdram, ctx);
        goto after_5;
    // 0x808007A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x808007A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_808007A8:
    // 0x808007A8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808007AC: jal         0x800A791C
    // 0x808007B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800A791C(rdram, ctx);
        goto after_6;
    // 0x808007B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x808007B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808007BC: jr          $ra
    // 0x808007C0: nop

    return;
    // 0x808007C0: nop

;}
RECOMP_FUNC void func_808026AC_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808026AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808026B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808026B4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808026B8: jal         0x800A3280
    // 0x808026BC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800A3280(rdram, ctx);
        goto after_0;
    // 0x808026BC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x808026C0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x808026C4: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x808026C8: lui         $t7, 0x8081
    ctx->r15 = S32(RELOC_HI16(439, 0XB0C8) << 16);
    // 0x808026CC: addiu       $t7, $t7, -0x4F38
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(439, 0XB0C8));
    // 0x808026D0: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x808026D4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x808026D8: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x808026DC: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x808026E0: lui         $t0, 0x8081
    ctx->r8 = S32(RELOC_HI16(439, 0XB0F0) << 16);
    // 0x808026E4: addiu       $t0, $t0, -0x4F10
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(439, 0XB0F0));
    // 0x808026E8: addu        $t1, $t6, $t0
    ctx->r9 = ADD32(ctx->r14, ctx->r8);
    // 0x808026EC: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x808026F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808026F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808026F8: jr          $ra
    // 0x808026FC: nop

    return;
    // 0x808026FC: nop

;}
RECOMP_FUNC void sumole_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801594: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801598: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080159C: jal         0x80106790
    // 0x808015A0: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808015A0: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x808015A4: lhu         $t6, 0x72($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X72);
    // 0x808015A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808015AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808015B0: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808015B4: bne         $t7, $at, L_808015C4
    if (ctx->r15 != ctx->r1) {
        // 0x808015B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808015C4;
    }
    // 0x808015B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808015BC: b           L_808015C4
    // 0x808015C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808015C4;
    // 0x808015C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808015C4:
    // 0x808015C4: jr          $ra
    // 0x808015C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x808015C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _chpumproomswitch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085E88: syscall     254
    recomp_syscall_handler(rdram, ctx, 0x80085E88);
    return;
    // 0x80085E8C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800B2190(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2190: jr          $ra
    // 0x800B2194: addiu       $v0, $a0, 0x18
    ctx->r2 = ADD32(ctx->r4, 0X18);
    return;
    // 0x800B2194: addiu       $v0, $a0, 0x18
    ctx->r2 = ADD32(ctx->r4, 0X18);
;}
RECOMP_FUNC void func_800D1960(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1960: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D1964: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D1968: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800D196C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800D1970: jal         0x800D16C4
    // 0x800D1974: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800D16C4(rdram, ctx);
        goto after_0;
    // 0x800D1974: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x800D1978: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800D197C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D1980: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800D1984: bgtz        $a1, L_800D1998
    if (SIGNED(ctx->r5) > 0) {
        // 0x800D1988: sll         $v1, $v0, 2
        ctx->r3 = S32(ctx->r2 << 2);
            goto L_800D1998;
    }
    // 0x800D1988: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800D198C: beql        $a1, $at, L_800D199C
    if (ctx->r5 == ctx->r1) {
        // 0x800D1990: lw          $t6, 0x28($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X28);
            goto L_800D199C;
    }
    goto skip_0;
    // 0x800D1990: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    skip_0:
    // 0x800D1994: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_800D1998:
    // 0x800D1998: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
L_800D199C:
    // 0x800D199C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D19A0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x800D19A4: beq         $t6, $zero, L_800D19C4
    if (ctx->r14 == 0) {
        // 0x800D19A8: sh          $a1, -0x50AE($at)
        MEM_H(-0X50AE, ctx->r1) = ctx->r5;
            goto L_800D19C4;
    }
    // 0x800D19A8: sh          $a1, -0x50AE($at)
    MEM_H(-0X50AE, ctx->r1) = ctx->r5;
    // 0x800D19AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800D19B0: jal         0x800D1A6C
    // 0x800D19B4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_800D1A6C(rdram, ctx);
        goto after_1;
    // 0x800D19B4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_1:
    // 0x800D19B8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800D19BC: b           L_800D19EC
    // 0x800D19C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_800D19EC;
    // 0x800D19C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_800D19C4:
    // 0x800D19C4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800D19C8: lw          $t7, -0x4DB0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4DB0);
    // 0x800D19CC: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x800D19D0: sll         $t1, $v1, 1
    ctx->r9 = S32(ctx->r3 << 1);
    // 0x800D19D4: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800D19D8: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800D19DC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800D19E0: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x800D19E4: lh          $t2, 0x1A04($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X1A04);
    // 0x800D19E8: xor         $a1, $t2, $t0
    ctx->r5 = ctx->r10 ^ ctx->r8;
L_800D19EC:
    // 0x800D19EC: jal         0x800D16CC
    // 0x800D19F0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800D16CC(rdram, ctx);
        goto after_2;
    // 0x800D19F0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x800D19F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D19F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D19FC: jr          $ra
    // 0x800D1A00: nop

    return;
    // 0x800D1A00: nop

;}
RECOMP_FUNC void susplinet_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lh          $t6, 0x32($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X32);
    // 0x80800004: sll         $t0, $a1, 1
    ctx->r8 = S32(ctx->r5 << 1);
    // 0x80800008: beq         $a3, $zero, L_80800028
    if (ctx->r7 == 0) {
        // 0x8080000C: addu        $v0, $a0, $t6
        ctx->r2 = ADD32(ctx->r4, ctx->r14);
            goto L_80800028;
    }
    // 0x8080000C: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x80800010: sll         $t7, $a1, 1
    ctx->r15 = S32(ctx->r5 << 1);
    // 0x80800014: addu        $v1, $v0, $t7
    ctx->r3 = ADD32(ctx->r2, ctx->r15);
    // 0x80800018: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x8080001C: or          $t9, $t8, $a2
    ctx->r25 = ctx->r24 | ctx->r6;
    // 0x80800020: jr          $ra
    // 0x80800024: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
    return;
    // 0x80800024: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
L_80800028:
    // 0x80800028: addu        $v1, $v0, $t0
    ctx->r3 = ADD32(ctx->r2, ctx->r8);
    // 0x8080002C: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x80800030: and         $t1, $a0, $a2
    ctx->r9 = ctx->r4 & ctx->r6;
    // 0x80800034: beq         $t1, $zero, L_80800040
    if (ctx->r9 == 0) {
        // 0x80800038: subu        $t2, $a0, $a2
        ctx->r10 = SUB32(ctx->r4, ctx->r6);
            goto L_80800040;
    }
    // 0x80800038: subu        $t2, $a0, $a2
    ctx->r10 = SUB32(ctx->r4, ctx->r6);
    // 0x8080003C: sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
L_80800040:
    // 0x80800040: jr          $ra
    // 0x80800044: nop

    return;
    // 0x80800044: nop

;}
RECOMP_FUNC void func_800D1510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1510: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D1514: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D1518: addiu       $v0, $v0, -0x4DB0
    ctx->r2 = ADD32(ctx->r2, -0X4DB0);
    // 0x800D151C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D1520: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800D1524: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    // 0x800D1528: jal         0x8001ACEC
    // 0x800D152C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    heap_alloc_sided(rdram, ctx);
        goto after_0;
    // 0x800D152C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800D1530: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D1534: jal         0x800D1490
    // 0x800D1538: sw          $v0, -0x4DB0($at)
    MEM_W(-0X4DB0, ctx->r1) = ctx->r2;
    func_800D1490(rdram, ctx);
        goto after_1;
    // 0x800D1538: sw          $v0, -0x4DB0($at)
    MEM_W(-0X4DB0, ctx->r1) = ctx->r2;
    after_1:
    // 0x800D153C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D1540: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D1544: jr          $ra
    // 0x800D1548: nop

    return;
    // 0x800D1548: nop

;}
RECOMP_FUNC void func_80800134_chwaspstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800134: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800138: addiu       $t7, $a1, -0x1
    ctx->r15 = ADD32(ctx->r5, -0X1);
    // 0x8080013C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800140: sltiu       $at, $t7, 0x6
    ctx->r1 = ctx->r15 < 0X6 ? 1 : 0;
    // 0x80800144: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800148: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080014C: beq         $at, $zero, L_80800330
    if (ctx->r1 == 0) {
        // 0x80800150: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_80800330;
    }
    // 0x80800150: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800154: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800158: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2364, 0X648) << 16);
    // 0x8080015C: addu        $at, $at, $t7
    gpr jr_addend_80800164 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800160: lw          $t7, 0x648($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2364, 0X648));
    // 0x80800164: jr          $t7
    // 0x80800168: nop

    switch (jr_addend_80800164 >> 2) {
        case 0: goto L_8080016C; break;
        case 1: goto L_80800180; break;
        case 2: goto L_80800220; break;
        case 3: goto L_80800248; break;
        case 4: goto L_808002A8; break;
        case 5: goto L_80800314; break;
        default: switch_error(__func__, 0x80800164, 0x80800648);
    }
    // 0x80800168: nop

L_8080016C:
    // 0x8080016C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800170: jal         0x8008A4B0
    // 0x80800174: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800174: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800178: b           L_80800334
    // 0x8080017C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800334;
    // 0x8080017C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800180:
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800184: jal         0x8008A4B0
    // 0x80800188: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800188: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8080018C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800190: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x80800194: jal         0x800CE8D8
    // 0x80800198: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_800CE8D8(rdram, ctx);
        goto after_2;
    // 0x80800198: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_2:
    // 0x8080019C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x808001A0: addiu       $a1, $a1, 0x7630
    ctx->r5 = ADD32(ctx->r5, 0X7630);
    // 0x808001A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808001A8: jal         0x800CE928
    // 0x808001AC: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    func_800CE928(rdram, ctx);
        goto after_3;
    // 0x808001AC: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x808001B0: lhu         $t8, 0x6E($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X6E);
    // 0x808001B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808001B8: addiu       $a0, $zero, 0x6D8
    ctx->r4 = ADD32(0, 0X6D8);
    // 0x808001BC: andi        $t9, $t8, 0xFE00
    ctx->r25 = ctx->r24 & 0XFE00;
    // 0x808001C0: ori         $t0, $t9, 0x14
    ctx->r8 = ctx->r25 | 0X14;
    // 0x808001C4: sh          $t0, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r8;
    // 0x808001C8: jal         0x800DA298
    // 0x808001CC: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x808001CC: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    after_4:
    // 0x808001D0: bne         $v0, $zero, L_80800210
    if (ctx->r2 != 0) {
        // 0x808001D4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800210;
    }
    // 0x808001D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808001D8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808001DC: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    // 0x808001E0: addiu       $a3, $zero, 0x810
    ctx->r7 = ADD32(0, 0X810);
    // 0x808001E4: jal         0x80085708
    // 0x808001E8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    _capod_entrypoint_13(rdram, ctx);
        goto after_5;
    // 0x808001E8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_5:
    // 0x808001EC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808001F0: addiu       $t1, $zero, 0x6D
    ctx->r9 = ADD32(0, 0X6D);
    // 0x808001F4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808001F8: addiu       $a1, $zero, 0x1416
    ctx->r5 = ADD32(0, 0X1416);
    // 0x808001FC: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x80800200: jal         0x8008A208
    // 0x80800204: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x80800204: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_6:
    // 0x80800208: b           L_80800334
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800334;
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800210:
    // 0x80800210: jal         0x800CE88C
    // 0x80800214: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800CE88C(rdram, ctx);
        goto after_7;
    // 0x80800214: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80800218: b           L_80800334
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800334;
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800220:
    // 0x80800220: jal         0x800DA298
    // 0x80800224: addiu       $a0, $zero, 0x6D8
    ctx->r4 = ADD32(0, 0X6D8);
    func_800DA298(rdram, ctx);
        goto after_8;
    // 0x80800224: addiu       $a0, $zero, 0x6D8
    ctx->r4 = ADD32(0, 0X6D8);
    after_8:
    // 0x80800228: bne         $v0, $zero, L_80800238
    if (ctx->r2 != 0) {
        // 0x8080022C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800238;
    }
    // 0x8080022C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800230: jal         0x800CE88C
    // 0x80800234: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800CE88C(rdram, ctx);
        goto after_9;
    // 0x80800234: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
L_80800238:
    // 0x80800238: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8080023C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800240: b           L_80800330
    // 0x80800244: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
        goto L_80800330;
    // 0x80800244: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_80800248:
    // 0x80800248: jal         0x800DA298
    // 0x8080024C: addiu       $a0, $zero, 0x6D9
    ctx->r4 = ADD32(0, 0X6D9);
    func_800DA298(rdram, ctx);
        goto after_10;
    // 0x8080024C: addiu       $a0, $zero, 0x6D9
    ctx->r4 = ADD32(0, 0X6D9);
    after_10:
    // 0x80800250: bne         $v0, $zero, L_80800290
    if (ctx->r2 != 0) {
        // 0x80800254: nop
    
            goto L_80800290;
    }
    // 0x80800254: nop

    // 0x80800258: jal         0x800DA544
    // 0x8080025C: addiu       $a0, $zero, 0x6D9
    ctx->r4 = ADD32(0, 0X6D9);
    func_800DA544(rdram, ctx);
        goto after_11;
    // 0x8080025C: addiu       $a0, $zero, 0x6D9
    ctx->r4 = ADD32(0, 0X6D9);
    after_11:
    // 0x80800260: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800264: addiu       $t2, $zero, 0x6D
    ctx->r10 = ADD32(0, 0X6D);
    // 0x80800268: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8080026C: addiu       $a1, $zero, 0x1419
    ctx->r5 = ADD32(0, 0X1419);
    // 0x80800270: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x80800274: jal         0x8008A208
    // 0x80800278: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_12;
    // 0x80800278: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_12:
    // 0x8080027C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800280: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x80800284: addiu       $a3, $zero, 0x810
    ctx->r7 = ADD32(0, 0X810);
    // 0x80800288: jal         0x80085708
    // 0x8080028C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    _capod_entrypoint_13(rdram, ctx);
        goto after_13;
    // 0x8080028C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_13:
L_80800290:
    // 0x80800290: jal         0x800FC6B0
    // 0x80800294: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    func_800FC6B0(rdram, ctx);
        goto after_14;
    // 0x80800294: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_14:
    // 0x80800298: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8080029C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808002A0: b           L_80800330
    // 0x808002A4: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
        goto L_80800330;
    // 0x808002A4: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
L_808002A8:
    // 0x808002A8: jal         0x800FC6B0
    // 0x808002AC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_800FC6B0(rdram, ctx);
        goto after_15;
    // 0x808002AC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_15:
    // 0x808002B0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x808002B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808002B8: jal         0x800D2498
    // 0x808002BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D2498(rdram, ctx);
        goto after_16;
    // 0x808002BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_16:
    // 0x808002C0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808002C4: addiu       $t3, $zero, 0x6D
    ctx->r11 = ADD32(0, 0X6D);
    // 0x808002C8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x808002CC: addiu       $a1, $zero, 0x1418
    ctx->r5 = ADD32(0, 0X1418);
    // 0x808002D0: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x808002D4: jal         0x8008A208
    // 0x808002D8: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_17;
    // 0x808002D8: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_17:
    // 0x808002DC: addiu       $a0, $zero, 0x411
    ctx->r4 = ADD32(0, 0X411);
    // 0x808002E0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x808002E4: jal         0x80101180
    // 0x808002E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_18;
    // 0x808002E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_18:
    // 0x808002EC: jal         0x800DA544
    // 0x808002F0: addiu       $a0, $zero, 0x35A
    ctx->r4 = ADD32(0, 0X35A);
    func_800DA544(rdram, ctx);
        goto after_19;
    // 0x808002F0: addiu       $a0, $zero, 0x35A
    ctx->r4 = ADD32(0, 0X35A);
    after_19:
    // 0x808002F4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808002F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808002FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800300: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800304: jal         0x800CE88C
    // 0x80800308: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    func_800CE88C(rdram, ctx);
        goto after_20;
    // 0x80800308: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    after_20:
    // 0x8080030C: b           L_80800334
    // 0x80800310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800334;
    // 0x80800310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800314:
    // 0x80800314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800318: jal         0x8008A4B0
    // 0x8080031C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_21;
    // 0x8080031C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
    // 0x80800320: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800324: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800328: nop

    // 0x8080032C: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
L_80800330:
    // 0x80800330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800334:
    // 0x80800334: jal         0x80101FDC
    // 0x80800338: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80101FDC(rdram, ctx);
        goto after_22;
    // 0x80800338: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_22:
    // 0x8080033C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800340: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800344: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800348: jr          $ra
    // 0x8080034C: nop

    return;
    // 0x8080034C: nop

;}
RECOMP_FUNC void cadbfunc_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800448: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080044C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800450: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800454: jal         0x808003EC
    // 0x80800458: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_808003EC_cadbfunc(rdram, ctx);
        goto after_0;
    // 0x80800458: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080045C: bne         $v0, $zero, L_8080046C
    if (ctx->r2 != 0) {
        // 0x80800460: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8080046C;
    }
    // 0x80800460: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800464: b           L_80800488
    // 0x80800468: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800488;
    // 0x80800468: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080046C:
    // 0x8080046C: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80800470: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800474: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800478: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
    // 0x8080047C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80800480: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80800484: swc1        $f6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f6.u32l;
L_80800488:
    // 0x80800488: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080048C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800490: jr          $ra
    // 0x80800494: nop

    return;
    // 0x80800494: nop

;}
RECOMP_FUNC void _chlavaarchgrill3switches_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087118: syscall     517
    recomp_syscall_handler(rdram, ctx, 0x80087118);
    return;
    // 0x8008711C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void glglobaldata_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800144: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800148: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8080014C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800150: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80800154: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800158: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8080015C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800160: jal         0x808001FC
    // 0x80800164: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    glglobaldata_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800164: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800168: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x8080016C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800170: jal         0x80800124
    // 0x80800174: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_80800124_glglobaldata(rdram, ctx);
        goto after_1;
    // 0x80800174: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_1:
    // 0x80800178: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(2734, 0X230) << 16);
    // 0x8080017C: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(2734, 0X238) << 16);
    // 0x80800180: addiu       $s3, $s3, 0x238
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(2734, 0X238));
    // 0x80800184: addiu       $s0, $s0, 0x230
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(2734, 0X230));
    // 0x80800188: addiu       $s2, $sp, 0x38
    ctx->r18 = ADD32(ctx->r29, 0X38);
    // 0x8080018C: addiu       $s1, $sp, 0x3C
    ctx->r17 = ADD32(ctx->r29, 0X3C);
L_80800190:
    // 0x80800190: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80800194: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800198: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8080019C: jalr        $t9
    // 0x808001A0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x808001A0: nop

    after_2:
    // 0x808001A4: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x808001A8: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x808001AC: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x808001B0: jal         0x8001BBA0
    // 0x808001B4: addu        $a0, $s4, $t6
    ctx->r4 = ADD32(ctx->r20, ctx->r14);
    rare_memcpy(rdram, ctx);
        goto after_3;
    // 0x808001B4: addu        $a0, $s4, $t6
    ctx->r4 = ADD32(ctx->r20, ctx->r14);
    after_3:
    // 0x808001B8: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x808001BC: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x808001C0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x808001C4: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x808001C8: bne         $s0, $s3, L_80800190
    if (ctx->r16 != ctx->r19) {
        // 0x808001CC: sw          $t0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r8;
            goto L_80800190;
    }
    // 0x808001CC: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x808001D0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808001D4: jal         0x80088708
    // 0x808001D8: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    _glcrc_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x808001D8: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_4:
    // 0x808001DC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808001E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001E4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808001E8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808001EC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x808001F0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x808001F4: jr          $ra
    // 0x808001F8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x808001F8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_800A4DA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4DA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A4DA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A4DAC: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x800A4DB0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A4DB4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800A4DB8: sb          $a1, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r5;
    // 0x800A4DBC: lw          $t7, 0x38($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X38);
    // 0x800A4DC0: lbu         $v0, 0x6($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X6);
    // 0x800A4DC4: beq         $v0, $at, L_800A4DEC
    if (ctx->r2 == ctx->r1) {
        // 0x800A4DC8: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_800A4DEC;
    }
    // 0x800A4DC8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800A4DCC: beq         $v0, $at, L_800A4DEC
    if (ctx->r2 == ctx->r1) {
        // 0x800A4DD0: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_800A4DEC;
    }
    // 0x800A4DD0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800A4DD4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A4DD8: jal         0x800A3F14
    // 0x800A4DDC: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_800A3F14(rdram, ctx);
        goto after_0;
    // 0x800A4DDC: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x800A4DE0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800A4DE4: jal         0x800A3B78
    // 0x800A4DE8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800A3B78(rdram, ctx);
        goto after_1;
    // 0x800A4DE8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
L_800A4DEC:
    // 0x800A4DEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A4DF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A4DF4: jr          $ra
    // 0x800A4DF8: nop

    return;
    // 0x800A4DF8: nop

;}
RECOMP_FUNC void func_80094390(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094390: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80094394: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80094398: jal         0x800C954C
    // 0x8009439C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800C954C(rdram, ctx);
        goto after_0;
    // 0x8009439C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800943A0: bne         $v0, $zero, L_800943F0
    if (ctx->r2 != 0) {
        // 0x800943A4: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_800943F0;
    }
    // 0x800943A4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800943A8: jal         0x800F6774
    // 0x800943AC: lw          $a0, 0x184($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X184);
    func_800F6774(rdram, ctx);
        goto after_1;
    // 0x800943AC: lw          $a0, 0x184($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X184);
    after_1:
    // 0x800943B0: beq         $v0, $zero, L_800943F0
    if (ctx->r2 == 0) {
        // 0x800943B4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_800943F0;
    }
    // 0x800943B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800943B8: jal         0x800852F0
    // 0x800943BC: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    _batimer_decrement(rdram, ctx);
        goto after_2;
    // 0x800943BC: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_2:
    // 0x800943C0: beq         $v0, $zero, L_800943F0
    if (ctx->r2 == 0) {
        // 0x800943C4: nop
    
            goto L_800943F0;
    }
    // 0x800943C4: nop

    // 0x800943C8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800943CC: jal         0x8009E9F0
    // 0x800943D0: nop

    func_8009E9F0(rdram, ctx);
        goto after_3;
    // 0x800943D0: nop

    after_3:
    // 0x800943D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800943D8: jal         0x80094430
    // 0x800943DC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80094430(rdram, ctx);
        goto after_4;
    // 0x800943DC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x800943E0: addiu       $a0, $zero, 0x1CD
    ctx->r4 = ADD32(0, 0X1CD);
    // 0x800943E4: addiu       $a1, $zero, 0x76
    ctx->r5 = ADD32(0, 0X76);
    // 0x800943E8: jal         0x80101180
    // 0x800943EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_5;
    // 0x800943EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
L_800943F0:
    // 0x800943F0: jal         0x800C0638
    // 0x800943F4: nop

    func_800C0638(rdram, ctx);
        goto after_6;
    // 0x800943F4: nop

    after_6:
    // 0x800943F8: bne         $v0, $zero, L_80094420
    if (ctx->r2 != 0) {
        // 0x800943FC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80094420;
    }
    // 0x800943FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80094400: jal         0x80085300
    // 0x80094404: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    _batimer_get(rdram, ctx);
        goto after_7;
    // 0x80094404: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_7:
    // 0x80094408: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8009440C: addiu       $a0, $zero, 0x105
    ctx->r4 = ADD32(0, 0X105);
    // 0x80094410: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80094414: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80094418: jal         0x800D2498
    // 0x8009441C: nop

    func_800D2498(rdram, ctx);
        goto after_8;
    // 0x8009441C: nop

    after_8:
L_80094420:
    // 0x80094420: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80094424: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80094428: jr          $ra
    // 0x8009442C: nop

    return;
    // 0x8009442C: nop

;}
RECOMP_FUNC void func_80800B80_chsilo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800B84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800B88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800B8C: jal         0x800D8FF8
    // 0x80800B90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800B90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800B94: lw          $t6, 0x6C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X6C);
    // 0x80800B98: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x80800B9C: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80800BA0: beql        $t7, $zero, L_80801070
    if (ctx->r15 == 0) {
        // 0x80800BA4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801070;
    }
    goto skip_0;
    // 0x80800BA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800BA8: lhu         $t8, 0x72($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X72);
    // 0x80800BAC: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x80800BB0: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80800BB4: sltiu       $at, $t0, 0xB
    ctx->r1 = ctx->r8 < 0XB ? 1 : 0;
    // 0x80800BB8: beq         $at, $zero, L_8080102C
    if (ctx->r1 == 0) {
        // 0x80800BBC: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_8080102C;
    }
    // 0x80800BBC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80800BC0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1820, 0X128C) << 16);
    // 0x80800BC4: addu        $at, $at, $t0
    gpr jr_addend_80800BCC = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80800BC8: lw          $t0, 0x128C($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1820, 0X128C));
    // 0x80800BCC: jr          $t0
    // 0x80800BD0: nop

    switch (jr_addend_80800BCC >> 2) {
        case 0: goto L_80800BD4; break;
        case 1: goto L_80800C14; break;
        case 2: goto L_80800C64; break;
        case 3: goto L_80800D34; break;
        case 4: goto L_80800DF4; break;
        case 5: goto L_80800F14; break;
        case 6: goto L_80800FD0; break;
        case 7: goto L_80800F6C; break;
        case 8: goto L_80800F94; break;
        case 9: goto L_80800EAC; break;
        case 10: goto L_80800E10; break;
        default: switch_error(__func__, 0x80800BCC, 0x8080128C);
    }
    // 0x80800BD0: nop

L_80800BD4:
    // 0x80800BD4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800BD8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800BDC: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800BE0: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80800BE4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800BE8: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800BEC: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800BF0: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800BF4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800BF8: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80800BFC: jal         0x8008FB58
    // 0x80800C00: nop

    func_8008FB58(rdram, ctx);
        goto after_1;
    // 0x80800C00: nop

    after_1:
    // 0x80800C04: jal         0x80800A40
    // 0x80800C08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800A40_chsilo(rdram, ctx);
        goto after_2;
    // 0x80800C08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800C0C: b           L_8080102C
    // 0x80800C10: nop

        goto L_8080102C;
    // 0x80800C10: nop

L_80800C14:
    // 0x80800C14: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800C18: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800C1C: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800C20: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80800C24: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800C28: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80800C2C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800C30: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800C34: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80800C38: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80800C3C: jal         0x8008FB58
    // 0x80800C40: nop

    func_8008FB58(rdram, ctx);
        goto after_3;
    // 0x80800C40: nop

    after_3:
    // 0x80800C44: jal         0x80101DDC
    // 0x80800C48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_4;
    // 0x80800C48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800C4C: beq         $v0, $zero, L_8080102C
    if (ctx->r2 == 0) {
        // 0x80800C50: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080102C;
    }
    // 0x80800C50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C54: jal         0x808004C0
    // 0x80800C58: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808004C0_chsilo(rdram, ctx);
        goto after_5;
    // 0x80800C58: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x80800C5C: b           L_8080102C
    // 0x80800C60: nop

        goto L_8080102C;
    // 0x80800C60: nop

L_80800C64:
    // 0x80800C64: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x80800C68: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800C6C: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800C70: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80800C74: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800C78: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800C7C: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x80800C80: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800C84: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800C88: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80800C8C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800C90: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800C94: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80800C98: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80800C9C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80800CA0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800CA4: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80800CA8: jal         0x8010CB0C
    // 0x80800CAC: nop

    func_8010CB0C(rdram, ctx);
        goto after_6;
    // 0x80800CAC: nop

    after_6:
    // 0x80800CB0: beq         $v0, $zero, L_80800D24
    if (ctx->r2 == 0) {
        // 0x80800CB4: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80800D24;
    }
    // 0x80800CB4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800CB8: jal         0x8008FA2C
    // 0x80800CBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008FA2C(rdram, ctx);
        goto after_7;
    // 0x80800CBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80800CC0: beq         $v0, $zero, L_80800D24
    if (ctx->r2 == 0) {
        // 0x80800CC4: nop
    
            goto L_80800D24;
    }
    // 0x80800CC4: nop

    // 0x80800CC8: jal         0x808001A8
    // 0x80800CCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001A8_chsilo(rdram, ctx);
        goto after_8;
    // 0x80800CCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800CD0: blez        $v0, L_80800CFC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800CD4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800CFC;
    }
    // 0x80800CD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CDC: jal         0x80800420
    // 0x80800CE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800420_chsilo(rdram, ctx);
        goto after_9;
    // 0x80800CE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80800CE4: beq         $v0, $zero, L_8080102C
    if (ctx->r2 == 0) {
        // 0x80800CE8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080102C;
    }
    // 0x80800CE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CEC: jal         0x808004C0
    // 0x80800CF0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808004C0_chsilo(rdram, ctx);
        goto after_10;
    // 0x80800CF0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_10:
    // 0x80800CF4: b           L_8080102C
    // 0x80800CF8: nop

        goto L_8080102C;
    // 0x80800CF8: nop

L_80800CFC:
    // 0x80800CFC: addiu       $a1, $zero, 0xDA8
    ctx->r5 = ADD32(0, 0XDA8);
    // 0x80800D00: jal         0x80800104
    // 0x80800D04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80800104_chsilo(rdram, ctx);
        goto after_11;
    // 0x80800D04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x80800D08: jal         0x80800378
    // 0x80800D0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800378_chsilo(rdram, ctx);
        goto after_12;
    // 0x80800D0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800D10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D14: jal         0x808004C0
    // 0x80800D18: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_808004C0_chsilo(rdram, ctx);
        goto after_13;
    // 0x80800D18: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_13:
    // 0x80800D1C: b           L_8080102C
    // 0x80800D20: nop

        goto L_8080102C;
    // 0x80800D20: nop

L_80800D24:
    // 0x80800D24: jal         0x80800A40
    // 0x80800D28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800A40_chsilo(rdram, ctx);
        goto after_14;
    // 0x80800D28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800D2C: b           L_8080102C
    // 0x80800D30: nop

        goto L_8080102C;
    // 0x80800D30: nop

L_80800D34:
    // 0x80800D34: lwc1        $f0, 0x28($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80800D38: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800D3C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1820, 0X12B8) << 16);
    // 0x80800D40: lwc1        $f16, 0x12B8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1820, 0X12B8));
    // 0x80800D44: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80800D48: lwc1        $f2, 0x30($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80800D4C: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80800D50: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80800D54: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800D58: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x80800D5C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800D60: lwc1        $f12, 0x2C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800D64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D68: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80800D6C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800D70: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x80800D74: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1820, 0X12E0) << 16);
    // 0x80800D78: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80800D7C: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
    // 0x80800D80: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800D84: add.s       $f18, $f2, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x80800D88: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800D8C: swc1        $f18, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f18.u32l;
    // 0x80800D90: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x80800D94: nop

    // 0x80800D98: bc1fl       L_80800DC0
    if (!c1cs) {
        // 0x80800D9C: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_80800DC0;
    }
    goto skip_1;
    // 0x80800D9C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_1:
    // 0x80800DA0: jal         0x80089D18
    // 0x80800DA4: addiu       $a2, $a2, 0x12E0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1820, 0X12E0));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_15;
    // 0x80800DA4: addiu       $a2, $a2, 0x12E0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1820, 0X12E0));
    after_15:
    // 0x80800DA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DAC: jal         0x808004C0
    // 0x80800DB0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808004C0_chsilo(rdram, ctx);
        goto after_16;
    // 0x80800DB0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_16:
    // 0x80800DB4: b           L_8080102C
    // 0x80800DB8: nop

        goto L_8080102C;
    // 0x80800DB8: nop

    // 0x80800DBC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_80800DC0:
    // 0x80800DC0: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x80800DC4: mul.s       $f18, $f10, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80800DC8: sub.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x80800DCC: jal         0x800907C0
    // 0x80800DD0: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    func_800907C0(rdram, ctx);
        goto after_17;
    // 0x80800DD0: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    after_17:
    // 0x80800DD4: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1820, 0X12D0) << 16);
    // 0x80800DD8: addiu       $a3, $a3, 0x12D0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1820, 0X12D0));
    // 0x80800DDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DE0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800DE4: jal         0x80089D50
    // 0x80800DE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_18;
    // 0x80800DE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_18:
    // 0x80800DEC: b           L_8080102C
    // 0x80800DF0: nop

        goto L_8080102C;
    // 0x80800DF0: nop

L_80800DF4:
    // 0x80800DF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DF8: jal         0x80100094
    // 0x80800DFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_19;
    // 0x80800DFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_19:
    // 0x80800E00: jal         0x80087C98
    // 0x80800E04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _gcnewoption_entrypoint_0(rdram, ctx);
        goto after_20;
    // 0x80800E04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_20:
    // 0x80800E08: b           L_8080102C
    // 0x80800E0C: nop

        goto L_8080102C;
    // 0x80800E0C: nop

L_80800E10:
    // 0x80800E10: lwc1        $f12, 0x2C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800E14: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800E18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E1C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80800E20: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x80800E24: nop

    // 0x80800E28: bc1fl       L_80800E78
    if (!c1cs) {
        // 0x80800E2C: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_80800E78;
    }
    goto skip_2;
    // 0x80800E2C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_2:
    // 0x80800E30: jal         0x80800398
    // 0x80800E34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800398_chsilo(rdram, ctx);
        goto after_21;
    // 0x80800E34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
    // 0x80800E38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E3C: jal         0x80800420
    // 0x80800E40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800420_chsilo(rdram, ctx);
        goto after_22;
    // 0x80800E40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_22:
    // 0x80800E44: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1820, 0X12E0) << 16);
    // 0x80800E48: addiu       $a2, $a2, 0x12E0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1820, 0X12E0));
    // 0x80800E4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E50: jal         0x80089D18
    // 0x80800E54: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_23;
    // 0x80800E54: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_23:
    // 0x80800E58: jal         0x80800378
    // 0x80800E5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800378_chsilo(rdram, ctx);
        goto after_24;
    // 0x80800E5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80800E60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E64: jal         0x808004C0
    // 0x80800E68: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_808004C0_chsilo(rdram, ctx);
        goto after_25;
    // 0x80800E68: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_25:
    // 0x80800E6C: b           L_8080102C
    // 0x80800E70: nop

        goto L_8080102C;
    // 0x80800E70: nop

    // 0x80800E74: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_80800E78:
    // 0x80800E78: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x80800E7C: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80800E80: add.s       $f18, $f12, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x80800E84: jal         0x800907C0
    // 0x80800E88: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
    func_800907C0(rdram, ctx);
        goto after_26;
    // 0x80800E88: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
    after_26:
    // 0x80800E8C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1820, 0X12D0) << 16);
    // 0x80800E90: addiu       $a3, $a3, 0x12D0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1820, 0X12D0));
    // 0x80800E94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E98: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800E9C: jal         0x80089D50
    // 0x80800EA0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_27;
    // 0x80800EA0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_27:
    // 0x80800EA4: b           L_8080102C
    // 0x80800EA8: nop

        goto L_8080102C;
    // 0x80800EA8: nop

L_80800EAC:
    // 0x80800EAC: jal         0x80101DDC
    // 0x80800EB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_28;
    // 0x80800EB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x80800EB4: beq         $v0, $zero, L_8080102C
    if (ctx->r2 == 0) {
        // 0x80800EB8: nop
    
            goto L_8080102C;
    }
    // 0x80800EB8: nop

    // 0x80800EBC: jal         0x800DA544
    // 0x80800EC0: addiu       $a0, $zero, 0x6BF
    ctx->r4 = ADD32(0, 0X6BF);
    func_800DA544(rdram, ctx);
        goto after_29;
    // 0x80800EC0: addiu       $a0, $zero, 0x6BF
    ctx->r4 = ADD32(0, 0X6BF);
    after_29:
    // 0x80800EC4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800EC8: jal         0x800A7AD4
    // 0x80800ECC: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    func_800A7AD4(rdram, ctx);
        goto after_30;
    // 0x80800ECC: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_30:
    // 0x80800ED0: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800ED4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800ED8: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80800EDC: jal         0x80800000
    // 0x80800EE0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    func_80800000_chsilo(rdram, ctx);
        goto after_31;
    // 0x80800EE0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    after_31:
    // 0x80800EE4: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800EE8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1820, 0X12E8) << 16);
    // 0x80800EEC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800EF0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800EF4: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80800EF8: nop

    // 0x80800EFC: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80800F00: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x80800F04: jal         0x80087A58
    // 0x80800F08: lh          $a1, 0x12E8($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1820, 0X12E8));
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_32;
    // 0x80800F08: lh          $a1, 0x12E8($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1820, 0X12E8));
    after_32:
    // 0x80800F0C: b           L_8080102C
    // 0x80800F10: nop

        goto L_8080102C;
    // 0x80800F10: nop

L_80800F14:
    // 0x80800F14: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800F18: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800F1C: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800F20: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80800F24: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800F28: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80800F2C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800F30: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800F34: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80800F38: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80800F3C: jal         0x8008FB58
    // 0x80800F40: nop

    func_8008FB58(rdram, ctx);
        goto after_33;
    // 0x80800F40: nop

    after_33:
    // 0x80800F44: jal         0x80800A40
    // 0x80800F48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800A40_chsilo(rdram, ctx);
        goto after_34;
    // 0x80800F48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x80800F4C: jal         0x80101DDC
    // 0x80800F50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_35;
    // 0x80800F50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_35:
    // 0x80800F54: beq         $v0, $zero, L_8080102C
    if (ctx->r2 == 0) {
        // 0x80800F58: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080102C;
    }
    // 0x80800F58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F5C: jal         0x808004C0
    // 0x80800F60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808004C0_chsilo(rdram, ctx);
        goto after_36;
    // 0x80800F60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_36:
    // 0x80800F64: b           L_8080102C
    // 0x80800F68: nop

        goto L_8080102C;
    // 0x80800F68: nop

L_80800F6C:
    // 0x80800F6C: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x80800F70: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800F74: jal         0x80101E14
    // 0x80800F78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_37;
    // 0x80800F78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x80800F7C: beq         $v0, $zero, L_8080102C
    if (ctx->r2 == 0) {
        // 0x80800F80: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080102C;
    }
    // 0x80800F80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F84: jal         0x808004C0
    // 0x80800F88: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_808004C0_chsilo(rdram, ctx);
        goto after_38;
    // 0x80800F88: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_38:
    // 0x80800F8C: b           L_8080102C
    // 0x80800F90: nop

        goto L_8080102C;
    // 0x80800F90: nop

L_80800F94:
    // 0x80800F94: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80800F98: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800F9C: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800FA0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800FA4: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80800FA8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800FAC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800FB0: jal         0x8010CAC0
    // 0x80800FB4: nop

    func_8010CAC0(rdram, ctx);
        goto after_39;
    // 0x80800FB4: nop

    after_39:
    // 0x80800FB8: bne         $v0, $zero, L_8080102C
    if (ctx->r2 != 0) {
        // 0x80800FBC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080102C;
    }
    // 0x80800FBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FC0: jal         0x808004C0
    // 0x80800FC4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808004C0_chsilo(rdram, ctx);
        goto after_40;
    // 0x80800FC4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_40:
    // 0x80800FC8: b           L_8080102C
    // 0x80800FCC: nop

        goto L_8080102C;
    // 0x80800FCC: nop

L_80800FD0:
    // 0x80800FD0: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x80800FD4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800FD8: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800FDC: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80800FE0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800FE4: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800FE8: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x80800FEC: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800FF0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800FF4: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80800FF8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800FFC: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80801000: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80801004: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80801008: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8080100C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80801010: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80801014: jal         0x8010CB0C
    // 0x80801018: nop

    func_8010CB0C(rdram, ctx);
        goto after_41;
    // 0x80801018: nop

    after_41:
    // 0x8080101C: bne         $v0, $zero, L_8080102C
    if (ctx->r2 != 0) {
        // 0x80801020: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080102C;
    }
    // 0x80801020: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801024: jal         0x808004C0
    // 0x80801028: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808004C0_chsilo(rdram, ctx);
        goto after_42;
    // 0x80801028: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_42:
L_8080102C:
    // 0x8080102C: jal         0x80090178
    // 0x80801030: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    func_80090178(rdram, ctx);
        goto after_43;
    // 0x80801030: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    after_43:
    // 0x80801034: beq         $v0, $zero, L_8080106C
    if (ctx->r2 == 0) {
        // 0x80801038: lui         $at, 0x4270
        ctx->r1 = S32(0X4270 << 16);
            goto L_8080106C;
    }
    // 0x80801038: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8080103C: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80801040: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801044: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80801048: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8080104C: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80801050: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80801054: jal         0x8010CAC0
    // 0x80801058: nop

    func_8010CAC0(rdram, ctx);
        goto after_44;
    // 0x80801058: nop

    after_44:
    // 0x8080105C: beql        $v0, $zero, L_80801070
    if (ctx->r2 == 0) {
        // 0x80801060: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801070;
    }
    goto skip_3;
    // 0x80801060: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80801064: jal         0x800904C8
    // 0x80801068: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    func_800904C8(rdram, ctx);
        goto after_45;
    // 0x80801068: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_45:
L_8080106C:
    // 0x8080106C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801070:
    // 0x80801070: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801074: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801078: jr          $ra
    // 0x8080107C: nop

    return;
    // 0x8080107C: nop

;}
RECOMP_FUNC void _scinfobar_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A5D8: syscall     845
    recomp_syscall_handler(rdram, ctx, 0x8008A5D8);
    return;
    // 0x8008A5DC: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
