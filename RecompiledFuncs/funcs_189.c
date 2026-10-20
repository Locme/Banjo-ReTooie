#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _chnests_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085AA8: syscall     191
    recomp_syscall_handler(rdram, ctx, 0x80085AA8);
    return;
    // 0x80085AAC: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_80801400_bskaztorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801400: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801404: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801408: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080140C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80801410: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    // 0x80801414: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80801418: jal         0x80091290
    // 0x8080141C: addiu       $a3, $zero, 0xD
    ctx->r7 = ADD32(0, 0XD);
    func_80091290(rdram, ctx);
        goto after_0;
    // 0x8080141C: addiu       $a3, $zero, 0xD
    ctx->r7 = ADD32(0, 0XD);
    after_0:
    // 0x80801420: jal         0x80085158
    // 0x80801424: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _baspin_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80801424: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80801428: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080142C: bnel        $v0, $at, L_80801458
    if (ctx->r2 != ctx->r1) {
        // 0x80801430: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80801458;
    }
    goto skip_0;
    // 0x80801430: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x80801434: jal         0x8008E124
    // 0x80801438: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8008E124(rdram, ctx);
        goto after_2;
    // 0x80801438: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8080143C: beq         $v0, $zero, L_80801450
    if (ctx->r2 == 0) {
        // 0x80801440: addiu       $t7, $zero, 0x154
        ctx->r15 = ADD32(0, 0X154);
            goto L_80801450;
    }
    // 0x80801440: addiu       $t7, $zero, 0x154
    ctx->r15 = ADD32(0, 0X154);
    // 0x80801444: addiu       $t6, $zero, 0x155
    ctx->r14 = ADD32(0, 0X155);
    // 0x80801448: b           L_80801454
    // 0x8080144C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
        goto L_80801454;
    // 0x8080144C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_80801450:
    // 0x80801450: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
L_80801454:
    // 0x80801454: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_80801458:
    // 0x80801458: jal         0x8009E5C8
    // 0x8080145C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_3;
    // 0x8080145C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80801460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801464: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801468: jr          $ra
    // 0x8080146C: nop

    return;
    // 0x8080146C: nop

;}
RECOMP_FUNC void _subaddieskeleton_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A0D0: syscall     828
    recomp_syscall_handler(rdram, ctx, 0x8008A0D0);
    return;
    // 0x8008A0D4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void fxrain_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080037C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800380: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800384: lbu         $a2, 0x0($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X0);
    // 0x80800388: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8080038C: beq         $a2, $zero, L_808003A4
    if (ctx->r6 == 0) {
        // 0x80800390: andi        $a0, $a2, 0xFF
        ctx->r4 = ctx->r6 & 0XFF;
            goto L_808003A4;
    }
    // 0x80800390: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    // 0x80800394: jal         0x800C2FDC
    // 0x80800398: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800C2FDC(rdram, ctx);
        goto after_0;
    // 0x80800398: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080039C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x808003A0: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
L_808003A4:
    // 0x808003A4: lw          $a0, 0x20($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X20);
    // 0x808003A8: jal         0x800B2D28
    // 0x808003AC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    vector_free(rdram, ctx);
        goto after_1;
    // 0x808003AC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x808003B0: jal         0x8001B084
    // 0x808003B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    heap_free(rdram, ctx);
        goto after_2;
    // 0x808003B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808003B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003C0: jr          $ra
    // 0x808003C4: nop

    return;
    // 0x808003C4: nop

;}
RECOMP_FUNC void func_800A5CF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5CF0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A5CF4: jr          $ra
    // 0x800A5CF8: sb          $a0, 0x7115($at)
    MEM_B(0X7115, ctx->r1) = ctx->r4;
    return;
    // 0x800A5CF8: sb          $a0, 0x7115($at)
    MEM_B(0X7115, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void bsbeefly_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D80: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800D84: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(76, 0XE80) << 16);
    // 0x80800D88: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800D8C: jr          $ra
    // 0x80800D90: lw          $v0, 0xE80($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(76, 0XE80));
    return;
    // 0x80800D90: lw          $v0, 0xE80($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(76, 0XE80));
    // 0x80800D94: nop

    // 0x80800D98: nop

    // 0x80800D9C: nop

;}
RECOMP_FUNC void func_808009D4_bsmumswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808009D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009DC: jal         0x800839B8
    // 0x808009E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsrest_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x808009E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808009E4: jal         0x80800198
    // 0x808009E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800198_bsmumswim(rdram, ctx);
        goto after_1;
    // 0x808009E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808009EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808009F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808009F4: jr          $ra
    // 0x808009F8: nop

    return;
    // 0x808009F8: nop

;}
RECOMP_FUNC void func_800ED964(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ED964: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800ED968: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800ED96C: lwc1        $f6, 0x48($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X48);
    // 0x800ED970: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800ED974: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800ED978: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800ED97C: nop

    // 0x800ED980: bc1fl       L_800ED994
    if (!c1cs) {
        // 0x800ED984: lw          $v0, 0xC($a0)
        ctx->r2 = MEM_W(ctx->r4, 0XC);
            goto L_800ED994;
    }
    goto skip_0;
    // 0x800ED984: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    skip_0:
    // 0x800ED988: lwc1        $f8, 0x5E60($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5E60);
    // 0x800ED98C: swc1        $f8, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f8.u32l;
    // 0x800ED990: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
L_800ED994:
    // 0x800ED994: beql        $v0, $zero, L_800ED9A8
    if (ctx->r2 == 0) {
        // 0x800ED998: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800ED9A8;
    }
    goto skip_1;
    // 0x800ED998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800ED99C: jalr        $v0
    // 0x800ED9A0: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x800ED9A0: nop

    after_0:
    // 0x800ED9A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800ED9A8:
    // 0x800ED9A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800ED9AC: jr          $ra
    // 0x800ED9B0: nop

    return;
    // 0x800ED9B0: nop

;}
RECOMP_FUNC void _badust_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800849E0: syscall     125
    recomp_syscall_handler(rdram, ctx, 0x800849E0);
    return;
    // 0x800849E4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void ncpoddialog_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802684: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80802688: sll         $t6, $a1, 4
    ctx->r14 = S32(ctx->r5 << 4);
    // 0x8080268C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80802690: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80802694: addu        $t1, $a0, $t6
    ctx->r9 = ADD32(ctx->r4, ctx->r14);
    // 0x80802698: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8080269C: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x808026A0: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
L_808026A4:
    // 0x808026A4: lwc1        $f0, 0x0($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X0);
    // 0x808026A8: lwc1        $f2, 0x0($t1)
    ctx->f2.u32l = MEM_W(ctx->r9, 0X0);
    // 0x808026AC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x808026B0: add.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x808026B4: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x808026B8: nop

    // 0x808026BC: bc1tl       L_808026DC
    if (c1cs) {
        // 0x808026C0: swc1        $f0, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->f0.u32l;
            goto L_808026DC;
    }
    goto skip_0;
    // 0x808026C0: swc1        $f0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f0.u32l;
    skip_0:
    // 0x808026C4: sub.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x808026C8: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x808026CC: nop

    // 0x808026D0: bc1fl       L_808026E4
    if (!c1cs) {
        // 0x808026D4: lwc1        $f0, 0x4($t0)
        ctx->f0.u32l = MEM_W(ctx->r8, 0X4);
            goto L_808026E4;
    }
    goto skip_1;
    // 0x808026D4: lwc1        $f0, 0x4($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X4);
    skip_1:
    // 0x808026D8: swc1        $f0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f0.u32l;
L_808026DC:
    // 0x808026DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808026E0: lwc1        $f0, 0x4($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X4);
L_808026E4:
    // 0x808026E4: lwc1        $f2, 0x4($t1)
    ctx->f2.u32l = MEM_W(ctx->r9, 0X4);
    // 0x808026E8: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x808026EC: add.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x808026F0: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x808026F4: nop

    // 0x808026F8: bc1tl       L_80802718
    if (c1cs) {
        // 0x808026FC: swc1        $f0, 0x4($t1)
        MEM_W(0X4, ctx->r9) = ctx->f0.u32l;
            goto L_80802718;
    }
    goto skip_2;
    // 0x808026FC: swc1        $f0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f0.u32l;
    skip_2:
    // 0x80802700: sub.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x80802704: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x80802708: nop

    // 0x8080270C: bc1f        L_8080271C
    if (!c1cs) {
        // 0x80802710: nop
    
            goto L_8080271C;
    }
    // 0x80802710: nop

    // 0x80802714: swc1        $f0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f0.u32l;
L_80802718:
    // 0x80802718: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080271C:
    // 0x8080271C: bne         $a3, $v1, L_808026A4
    if (ctx->r7 != ctx->r3) {
        // 0x80802720: addiu       $t1, $t1, 0x8
        ctx->r9 = ADD32(ctx->r9, 0X8);
            goto L_808026A4;
    }
    // 0x80802720: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80802724: beq         $v0, $zero, L_80802768
    if (ctx->r2 == 0) {
        // 0x80802728: sll         $t7, $a1, 4
        ctx->r15 = S32(ctx->r5 << 4);
            goto L_80802768;
    }
    // 0x80802728: sll         $t7, $a1, 4
    ctx->r15 = S32(ctx->r5 << 4);
    // 0x8080272C: addu        $v0, $a0, $t7
    ctx->r2 = ADD32(ctx->r4, ctx->r15);
    // 0x80802730: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80802734: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80802738: sll         $t2, $a1, 2
    ctx->r10 = S32(ctx->r5 << 2);
    // 0x8080273C: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x80802740: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80802744: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x80802748: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    // 0x8080274C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80802750: bc1fl       L_80802764
    if (!c1cs) {
        // 0x80802754: swc1        $f0, 0x20($t3)
        MEM_W(0X20, ctx->r11) = ctx->f0.u32l;
            goto L_80802764;
    }
    goto skip_3;
    // 0x80802754: swc1        $f0, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f0.u32l;
    skip_3:
    // 0x80802758: b           L_80802764
    // 0x8080275C: swc1        $f2, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->f2.u32l;
        goto L_80802764;
    // 0x8080275C: swc1        $f2, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->f2.u32l;
    // 0x80802760: swc1        $f0, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f0.u32l;
L_80802764:
    // 0x80802764: sb          $t4, 0x216($a0)
    MEM_B(0X216, ctx->r4) = ctx->r12;
L_80802768:
    // 0x80802768: jr          $ra
    // 0x8080276C: nop

    return;
    // 0x8080276C: nop

;}
RECOMP_FUNC void func_80092C6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092C6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80092C70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80092C74: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80092C78: jal         0x800921E0
    // 0x80092C7C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_800921E0(rdram, ctx);
        goto after_0;
    // 0x80092C7C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_0:
    // 0x80092C80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80092C84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80092C88: jr          $ra
    // 0x80092C8C: nop

    return;
    // 0x80092C8C: nop

;}
RECOMP_FUNC void func_8009BB94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BB94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009BB98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009BB9C: lw          $a0, 0xC8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XC8);
    // 0x8009BBA0: jal         0x800EEF94
    // 0x8009BBA4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_800EEF94(rdram, ctx);
        goto after_0;
    // 0x8009BBA4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_0:
    // 0x8009BBA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009BBAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009BBB0: jr          $ra
    // 0x8009BBB4: nop

    return;
    // 0x8009BBB4: nop

;}
RECOMP_FUNC void _chswitch_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800857F8: syscall     176
    recomp_syscall_handler(rdram, ctx, 0x800857F8);
    return;
    // 0x800857FC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_8008B6E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B6E0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008B6E4: addiu       $v1, $v1, 0x6CC0
    ctx->r3 = ADD32(ctx->r3, 0X6CC0);
    // 0x8008B6E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008B6EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008B6F0: lw          $s0, 0x0($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X0);
    // 0x8008B6F4: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8008B6F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008B6FC: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x8008B700: beql        $at, $zero, L_8008B758
    if (ctx->r1 == 0) {
        // 0x8008B704: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8008B758;
    }
    goto skip_0;
    // 0x8008B704: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8008B708: lh          $t6, 0x4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4);
L_8008B70C:
    // 0x8008B70C: beql        $t6, $zero, L_8008B748
    if (ctx->r14 == 0) {
        // 0x8008B710: addiu       $s0, $s0, 0x6
        ctx->r16 = ADD32(ctx->r16, 0X6);
            goto L_8008B748;
    }
    goto skip_1;
    // 0x8008B710: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    skip_1:
    // 0x8008B714: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8008B718: beql        $a0, $zero, L_8008B748
    if (ctx->r4 == 0) {
        // 0x8008B71C: addiu       $s0, $s0, 0x6
        ctx->r16 = ADD32(ctx->r16, 0X6);
            goto L_8008B748;
    }
    goto skip_2;
    // 0x8008B71C: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    skip_2:
    // 0x8008B720: lh          $t7, 0x2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X2);
    // 0x8008B724: slti        $at, $t7, 0x3B
    ctx->r1 = SIGNED(ctx->r15) < 0X3B ? 1 : 0;
    // 0x8008B728: beql        $at, $zero, L_8008B748
    if (ctx->r1 == 0) {
        // 0x8008B72C: addiu       $s0, $s0, 0x6
        ctx->r16 = ADD32(ctx->r16, 0X6);
            goto L_8008B748;
    }
    goto skip_3;
    // 0x8008B72C: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    skip_3:
    // 0x8008B730: jal         0x800DFCC0
    // 0x8008B734: nop

    func_800DFCC0(rdram, ctx);
        goto after_0;
    // 0x8008B734: nop

    after_0:
    // 0x8008B738: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x8008B73C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008B740: lw          $v0, 0x6CC4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6CC4);
    // 0x8008B744: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
L_8008B748:
    // 0x8008B748: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x8008B74C: bnel        $at, $zero, L_8008B70C
    if (ctx->r1 != 0) {
        // 0x8008B750: lh          $t6, 0x4($s0)
        ctx->r14 = MEM_H(ctx->r16, 0X4);
            goto L_8008B70C;
    }
    goto skip_4;
    // 0x8008B750: lh          $t6, 0x4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4);
    skip_4:
    // 0x8008B754: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8008B758:
    // 0x8008B758: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008B75C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008B760: jr          $ra
    // 0x8008B764: nop

    return;
    // 0x8008B764: nop

;}
RECOMP_FUNC void func_8080038C_chlagoonfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "func_8080038C_chlagoonfish");
    // 0x8080038C: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80800390: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80800394: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80800398: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8080039C: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x808003A0: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x808003A4: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x808003A8: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x808003AC: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x808003B0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808003B4: jal         0x80100094
    // 0x808003B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808003B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808003BC: bnel        $v0, $zero, L_808003D0
    if (ctx->r2 != 0) {
        // 0x808003C0: lhu         $v0, 0x72($s2)
        ctx->r2 = MEM_HU(ctx->r18, 0X72);
            goto L_808003D0;
    }
    goto skip_0;
    // 0x808003C0: lhu         $v0, 0x72($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X72);
    skip_0:
    // 0x808003C4: jal         0x80800000
    // 0x808003C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80800000_chlagoonfish(rdram, ctx);
        goto after_1;
    // 0x808003C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x808003CC: lhu         $v0, 0x72($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X72);
L_808003D0:
    // 0x808003D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808003D4: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808003D8: beq         $t6, $at, L_808003F0
    if (ctx->r14 == ctx->r1) {
        // 0x808003DC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808003F0;
    }
    // 0x808003DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808003E0: beq         $t6, $at, L_808004D4
    if (ctx->r14 == ctx->r1) {
        // 0x808003E4: addiu       $s0, $s2, 0x4
        ctx->r16 = ADD32(ctx->r18, 0X4);
            goto L_808004D4;
    }
    // 0x808003E4: addiu       $s0, $s2, 0x4
    ctx->r16 = ADD32(ctx->r18, 0X4);
    // 0x808003E8: b           L_80800570
    // 0x808003EC: nop

        goto L_80800570;
    // 0x808003EC: nop

L_808003F0:
    // 0x808003F0: jal         0x80800284
    // 0x808003F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80800284_chlagoonfish(rdram, ctx);
        goto after_2;
    // 0x808003F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x808003F8: jal         0x808002F8
    // 0x808003FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_808002F8_chlagoonfish(rdram, ctx);
        goto after_3;
    // 0x808003FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x80800400: bne         $v0, $zero, L_8080041C
    if (ctx->r2 != 0) {
        // 0x80800404: lui         $at, 0x4416
        ctx->r1 = S32(0X4416 << 16);
            goto L_8080041C;
    }
    // 0x80800404: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80800408: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080040C: jal         0x80800A44
    // 0x80800410: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800A44_chlagoonfish(rdram, ctx);
        goto after_4;
    // 0x80800410: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x80800414: b           L_80800454
    // 0x80800418: nop

        goto L_80800454;
    // 0x80800418: nop

L_8080041C:
    // 0x8080041C: lwc1        $f2, 0x38($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X38);
    // 0x80800420: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800424: lwc1        $f0, 0x24($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X24);
    // 0x80800428: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8080042C: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80800430: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80800434: nop

    // 0x80800438: bc1f        L_80800454
    if (!c1cs) {
        // 0x8080043C: nop
    
            goto L_80800454;
    }
    // 0x8080043C: nop

    // 0x80800440: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800444: nop

    // 0x80800448: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8080044C: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80800450: swc1        $f16, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f16.u32l;
L_80800454:
    // 0x80800454: jal         0x800DC0C0
    // 0x80800458: nop

    func_800DC0C0(rdram, ctx);
        goto after_5;
    // 0x80800458: nop

    after_5:
    // 0x8080045C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1800, 0XB54) << 16);
    // 0x80800460: lwc1        $f20, 0xB54($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1800, 0XB54));
    // 0x80800464: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x80800468: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8080046C: nop

    // 0x80800470: bc1f        L_80800498
    if (!c1cs) {
        // 0x80800474: nop
    
            goto L_80800498;
    }
    // 0x80800474: nop

    // 0x80800478: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080047C: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80800480: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800484: jal         0x800DC178
    // 0x80800488: nop

    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x80800488: nop

    after_6:
    // 0x8080048C: lwc1        $f18, 0x50($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X50);
    // 0x80800490: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x80800494: swc1        $f4, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f4.u32l;
L_80800498:
    // 0x80800498: jal         0x800DC0C0
    // 0x8080049C: nop

    func_800DC0C0(rdram, ctx);
        goto after_7;
    // 0x8080049C: nop

    after_7:
    // 0x808004A0: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x808004A4: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x808004A8: bc1f        L_80800570
    if (!c1cs) {
        // 0x808004AC: nop
    
            goto L_80800570;
    }
    // 0x808004AC: nop

    // 0x808004B0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808004B4: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x808004B8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808004BC: jal         0x800DC178
    // 0x808004C0: nop

    func_800DC178(rdram, ctx);
        goto after_8;
    // 0x808004C0: nop

    after_8:
    // 0x808004C4: lwc1        $f6, 0x54($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X54);
    // 0x808004C8: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x808004CC: b           L_80800570
    // 0x808004D0: swc1        $f8, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f8.u32l;
        goto L_80800570;
    // 0x808004D0: swc1        $f8, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f8.u32l;
L_808004D4:
    // 0x808004D4: addiu       $s1, $s2, 0x18
    ctx->r17 = ADD32(ctx->r18, 0X18);
    // 0x808004D8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808004DC: jal         0x800F1DF4
    // 0x808004E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F1DF4(rdram, ctx);
        goto after_9;
    // 0x808004E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808004E4: swc1        $f0, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f0.u32l;
    // 0x808004E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004EC: jal         0x800F1828
    // 0x808004F0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800F1828(rdram, ctx);
        goto after_10;
    // 0x808004F0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_10:
    // 0x808004F4: swc1        $f0, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f0.u32l;
    // 0x808004F8: jal         0x80800284
    // 0x808004FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80800284_chlagoonfish(rdram, ctx);
        goto after_11;
    // 0x808004FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_11:
    // 0x80800500: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800504: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    // 0x80800508: jal         0x800EFFB4
    // 0x8080050C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800EFFB4(rdram, ctx);
        goto after_12;
    // 0x8080050C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_12:
    // 0x80800510: beq         $v0, $zero, L_80800538
    if (ctx->r2 == 0) {
        // 0x80800514: lui         $at, 0x4416
        ctx->r1 = S32(0X4416 << 16);
            goto L_80800538;
    }
    // 0x80800514: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80800518: jal         0x808002F8
    // 0x8080051C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_808002F8_chlagoonfish(rdram, ctx);
        goto after_13;
    // 0x8080051C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_13:
    // 0x80800520: beq         $v0, $zero, L_80800570
    if (ctx->r2 == 0) {
        // 0x80800524: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800570;
    }
    // 0x80800524: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800528: jal         0x80800A44
    // 0x8080052C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800A44_chlagoonfish(rdram, ctx);
        goto after_14;
    // 0x8080052C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x80800530: b           L_80800570
    // 0x80800534: nop

        goto L_80800570;
    // 0x80800534: nop

L_80800538:
    // 0x80800538: lwc1        $f2, 0x38($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X38);
    // 0x8080053C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800540: lwc1        $f0, 0x24($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X24);
    // 0x80800544: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80800548: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8080054C: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80800550: nop

    // 0x80800554: bc1f        L_80800570
    if (!c1cs) {
        // 0x80800558: nop
    
            goto L_80800570;
    }
    // 0x80800558: nop

    // 0x8080055C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800560: nop

    // 0x80800564: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80800568: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8080056C: swc1        $f6, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f6.u32l;
L_80800570:
    // 0x80800570: jal         0x800D8FF8
    // 0x80800574: nop

    func_800D8FF8(rdram, ctx);
        goto after_15;
    // 0x80800574: nop

    after_15:
    // 0x80800578: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
    // 0x8080057C: jal         0x8001210C
    // 0x80800580: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001210C(rdram, ctx);
        goto after_16;
    // 0x80800580: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_16:
    // 0x80800584: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x80800588: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080058C: jal         0x80100094
    // 0x80800590: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_17;
    // 0x80800590: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_17:
    // 0x80800594: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800598: jal         0x8008FFBC
    // 0x8080059C: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    func_8008FFBC(rdram, ctx);
        goto after_18;
    // 0x8080059C: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    after_18:
    // 0x808005A0: jal         0x800F2100
    // 0x808005A4: lwc1        $f12, 0x8C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X8C);
    mlAbsF(rdram, ctx);
        goto after_19;
    // 0x808005A4: lwc1        $f12, 0x8C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X8C);
    after_19:
    // 0x808005A8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x808005AC: jal         0x800F2100
    // 0x808005B0: lwc1        $f12, 0x88($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X88);
    mlAbsF(rdram, ctx);
        goto after_20;
    // 0x808005B0: lwc1        $f12, 0x88($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X88);
    after_20:
    // 0x808005B4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x808005B8: jal         0x800F2100
    // 0x808005BC: lwc1        $f12, 0x90($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X90);
    mlAbsF(rdram, ctx);
        goto after_21;
    // 0x808005BC: lwc1        $f12, 0x90($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X90);
    after_21:
    // 0x808005C0: add.s       $f8, $f20, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f20.fl + ctx->f22.fl;
    // 0x808005C4: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x808005C8: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x808005CC: jal         0x8008FE68
    // 0x808005D0: swc1        $f10, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f10.u32l;
    func_8008FE68(rdram, ctx);
        goto after_22;
    // 0x808005D0: swc1        $f10, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f10.u32l;
    after_22:
    // 0x808005D4: lw          $t7, 0x6C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X6C);
    // 0x808005D8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808005DC: lui         $at, 0xC3C8
    ctx->r1 = S32(0XC3C8 << 16);
    // 0x808005E0: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x808005E4: beql        $t8, $zero, L_808008E4
    if (ctx->r24 == 0) {
        // 0x808005E8: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_808008E4;
    }
    goto skip_1;
    // 0x808005E8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_1:
    // 0x808005EC: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x808005F0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808005F4: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x808005F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808005FC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800600: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80800604: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800608: nop

    // 0x8080060C: lwc1        $f16, 0x28($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X28);
L_80800610:
    // 0x80800610: lwc1        $f18, 0x80($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80800614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800618: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8080061C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80800620: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x80800624: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80800628: jal         0x800EF214
    // 0x8080062C: nop

    func_800EF214(rdram, ctx);
        goto after_23;
    // 0x8080062C: nop

    after_23:
    // 0x80800630: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x80800634: andi        $t0, $s1, 0x1
    ctx->r8 = ctx->r17 & 0X1;
    // 0x80800638: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x8080063C: beq         $t9, $zero, L_8080064C
    if (ctx->r25 == 0) {
        // 0x80800640: nop
    
            goto L_8080064C;
    }
    // 0x80800640: nop

    // 0x80800644: bnel        $t0, $zero, L_80800660
    if (ctx->r8 != 0) {
        // 0x80800648: lwc1        $f6, 0x84($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X84);
            goto L_80800660;
    }
    goto skip_2;
    // 0x80800648: lwc1        $f6, 0x84($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X84);
    skip_2:
L_8080064C:
    // 0x8080064C: bne         $t1, $zero, L_808008C4
    if (ctx->r9 != 0) {
        // 0x80800650: andi        $t2, $s1, 0x1
        ctx->r10 = ctx->r17 & 0X1;
            goto L_808008C4;
    }
    // 0x80800650: andi        $t2, $s1, 0x1
    ctx->r10 = ctx->r17 & 0X1;
    // 0x80800654: bnel        $t2, $zero, L_808008C8
    if (ctx->r10 != 0) {
        // 0x80800658: lw          $t3, 0x6C($s2)
        ctx->r11 = MEM_W(ctx->r18, 0X6C);
            goto L_808008C8;
    }
    goto skip_3;
    // 0x80800658: lw          $t3, 0x6C($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X6C);
    skip_3:
    // 0x8080065C: lwc1        $f6, 0x84($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X84);
L_80800660:
    // 0x80800660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800664: addiu       $a2, $sp, 0x88
    ctx->r6 = ADD32(ctx->r29, 0X88);
    // 0x80800668: mul.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x8080066C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800670: jal         0x800EFFB4
    // 0x80800674: nop

    func_800EFFB4(rdram, ctx);
        goto after_24;
    // 0x80800674: nop

    after_24:
    // 0x80800678: beq         $v0, $zero, L_808006C8
    if (ctx->r2 == 0) {
        // 0x8080067C: addiu       $a0, $sp, 0x5C
        ctx->r4 = ADD32(ctx->r29, 0X5C);
            goto L_808006C8;
    }
    // 0x8080067C: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x80800680: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x80800684: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800688: jal         0x800F18FC
    // 0x8080068C: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    func_800F18FC(rdram, ctx);
        goto after_25;
    // 0x8080068C: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    after_25:
    // 0x80800690: lwc1        $f2, 0x38($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X38);
    // 0x80800694: lwc1        $f0, 0x28($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80800698: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8080069C: mul.s       $f10, $f20, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x808006A0: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x808006A4: nop

    // 0x808006A8: bc1f        L_80800718
    if (!c1cs) {
        // 0x808006AC: nop
    
            goto L_80800718;
    }
    // 0x808006AC: nop

    // 0x808006B0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808006B4: nop

    // 0x808006B8: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x808006BC: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x808006C0: b           L_80800718
    // 0x808006C4: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
        goto L_80800718;
    // 0x808006C4: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
L_808006C8:
    // 0x808006C8: addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    // 0x808006CC: jal         0x800EE780
    // 0x808006D0: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    func_800EE780(rdram, ctx);
        goto after_26;
    // 0x808006D0: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    after_26:
    // 0x808006D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006D8: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x808006DC: jal         0x800F18FC
    // 0x808006E0: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    func_800F18FC(rdram, ctx);
        goto after_27;
    // 0x808006E0: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    after_27:
    // 0x808006E4: lwc1        $f2, 0x38($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X38);
    // 0x808006E8: lwc1        $f0, 0x28($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X28);
    // 0x808006EC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x808006F0: mul.s       $f6, $f20, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x808006F4: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x808006F8: nop

    // 0x808006FC: bc1f        L_80800718
    if (!c1cs) {
        // 0x80800700: nop
    
            goto L_80800718;
    }
    // 0x80800700: nop

    // 0x80800704: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800708: nop

    // 0x8080070C: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80800710: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80800714: swc1        $f16, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f16.u32l;
L_80800718:
    // 0x80800718: jal         0x800DC0C0
    // 0x8080071C: nop

    func_800DC0C0(rdram, ctx);
        goto after_28;
    // 0x8080071C: nop

    after_28:
    // 0x80800720: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1800, 0XB58) << 16);
    // 0x80800724: lwc1        $f18, 0xB58($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1800, 0XB58));
    // 0x80800728: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8080072C: nop

    // 0x80800730: bc1fl       L_8080076C
    if (!c1cs) {
        // 0x80800734: lwc1        $f12, 0x70($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X70);
            goto L_8080076C;
    }
    goto skip_4;
    // 0x80800734: lwc1        $f12, 0x70($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X70);
    skip_4:
    // 0x80800738: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    // 0x8080073C: jal         0x800DC178
    // 0x80800740: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    func_800DC178(rdram, ctx);
        goto after_29;
    // 0x80800740: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_29:
    // 0x80800744: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x80800748: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    // 0x8080074C: jal         0x800DC178
    // 0x80800750: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    func_800DC178(rdram, ctx);
        goto after_30;
    // 0x80800750: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_30:
    // 0x80800754: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x80800758: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    // 0x8080075C: jal         0x800DC178
    // 0x80800760: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    func_800DC178(rdram, ctx);
        goto after_31;
    // 0x80800760: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_31:
    // 0x80800764: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x80800768: lwc1        $f12, 0x70($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X70);
L_8080076C:
    // 0x8080076C: jal         0x800F1DCC
    // 0x80800770: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    func_800F1DCC(rdram, ctx);
        goto after_32;
    // 0x80800770: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    after_32:
    // 0x80800774: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x80800778: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8080077C: bc1fl       L_808007E0
    if (!c1cs) {
        // 0x80800780: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_808007E0;
    }
    goto skip_5;
    // 0x80800780: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_5:
    // 0x80800784: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80800788: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080078C: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80800790: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800794: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800798: nop

    // 0x8080079C: bc1f        L_808007B8
    if (!c1cs) {
        // 0x808007A0: nop
    
            goto L_808007B8;
    }
    // 0x808007A0: nop

    // 0x808007A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808007A8: nop

    // 0x808007AC: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x808007B0: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x808007B4: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
L_808007B8:
    // 0x808007B8: mul.s       $f16, $f0, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x808007BC: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x808007C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1800, 0XB5C) << 16);
    // 0x808007C4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x808007C8: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
    // 0x808007CC: lwc1        $f4, 0xB5C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1800, 0XB5C));
    // 0x808007D0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808007D4: b           L_80800844
    // 0x808007D8: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
        goto L_80800844;
    // 0x808007D8: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x808007DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_808007E0:
    // 0x808007E0: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x808007E4: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x808007E8: nop

    // 0x808007EC: bc1fl       L_80800848
    if (!c1cs) {
        // 0x808007F0: lwc1        $f12, 0x6C($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X6C);
            goto L_80800848;
    }
    goto skip_6;
    // 0x808007F0: lwc1        $f12, 0x6C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X6C);
    skip_6:
    // 0x808007F4: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
    // 0x808007F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808007FC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800800: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80800804: nop

    // 0x80800808: bc1f        L_80800824
    if (!c1cs) {
        // 0x8080080C: nop
    
            goto L_80800824;
    }
    // 0x8080080C: nop

    // 0x80800810: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800814: nop

    // 0x80800818: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x8080081C: swc1        $f18, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f18.u32l;
    // 0x80800820: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
L_80800824:
    // 0x80800824: mul.s       $f6, $f0, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x80800828: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8080082C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1800, 0XB60) << 16);
    // 0x80800830: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800834: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
    // 0x80800838: lwc1        $f10, 0xB60($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1800, 0XB60));
    // 0x8080083C: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800840: swc1        $f16, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f16.u32l;
L_80800844:
    // 0x80800844: lwc1        $f12, 0x6C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X6C);
L_80800848:
    // 0x80800848: jal         0x800F1DCC
    // 0x8080084C: lwc1        $f14, 0xC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XC);
    func_800F1DCC(rdram, ctx);
        goto after_33;
    // 0x8080084C: lwc1        $f14, 0xC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XC);
    after_33:
    // 0x80800850: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x80800854: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80800858: bc1fl       L_8080088C
    if (!c1cs) {
        // 0x8080085C: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_8080088C;
    }
    goto skip_7;
    // 0x8080085C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_7:
    // 0x80800860: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800864: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800868: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8080086C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80800870: nop

    // 0x80800874: bc1fl       L_808008C8
    if (!c1cs) {
        // 0x80800878: lw          $t3, 0x6C($s2)
        ctx->r11 = MEM_W(ctx->r18, 0X6C);
            goto L_808008C8;
    }
    goto skip_8;
    // 0x80800878: lw          $t3, 0x6C($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X6C);
    skip_8:
    // 0x8080087C: add.s       $f4, $f0, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f22.fl;
    // 0x80800880: b           L_808008C4
    // 0x80800884: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
        goto L_808008C4;
    // 0x80800884: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x80800888: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_8080088C:
    // 0x8080088C: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80800890: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80800894: nop

    // 0x80800898: bc1fl       L_808008C8
    if (!c1cs) {
        // 0x8080089C: lw          $t3, 0x6C($s2)
        ctx->r11 = MEM_W(ctx->r18, 0X6C);
            goto L_808008C8;
    }
    goto skip_9;
    // 0x8080089C: lw          $t3, 0x6C($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X6C);
    skip_9:
    // 0x808008A0: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x808008A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808008A8: nop

    // 0x808008AC: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x808008B0: nop

    // 0x808008B4: bc1fl       L_808008C8
    if (!c1cs) {
        // 0x808008B8: lw          $t3, 0x6C($s2)
        ctx->r11 = MEM_W(ctx->r18, 0X6C);
            goto L_808008C8;
    }
    goto skip_10;
    // 0x808008B8: lw          $t3, 0x6C($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X6C);
    skip_10:
    // 0x808008BC: sub.s       $f10, $f0, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x808008C0: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
L_808008C4:
    // 0x808008C4: lw          $t3, 0x6C($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X6C);
L_808008C8:
    // 0x808008C8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808008CC: addiu       $s0, $s0, 0x30
    ctx->r16 = ADD32(ctx->r16, 0X30);
    // 0x808008D0: andi        $t4, $t3, 0x1FF
    ctx->r12 = ctx->r11 & 0X1FF;
    // 0x808008D4: sltu        $at, $s1, $t4
    ctx->r1 = ctx->r17 < ctx->r12 ? 1 : 0;
    // 0x808008D8: bnel        $at, $zero, L_80800610
    if (ctx->r1 != 0) {
        // 0x808008DC: lwc1        $f16, 0x28($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X28);
            goto L_80800610;
    }
    goto skip_11;
    // 0x808008DC: lwc1        $f16, 0x28($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X28);
    skip_11:
    // 0x808008E0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_808008E4:
    // 0x808008E4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808008E8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808008EC: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x808008F0: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x808008F4: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x808008F8: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x808008FC: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80800900: jr          $ra
    // 0x80800904: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x80800904: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void chtrashcangame_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802D20: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2384, 0X3430) << 16);
    // 0x80802D24: jr          $ra
    // 0x80802D28: addiu       $v0, $v0, 0x3430
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2384, 0X3430));
    return;
    // 0x80802D28: addiu       $v0, $v0, 0x3430
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2384, 0X3430));
    // 0x80802D2C: nop

;}
RECOMP_FUNC void _scinfobar_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A610: syscall     845
    recomp_syscall_handler(rdram, ctx, 0x8008A610);
    return;
    // 0x8008A614: addi        $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
;}
RECOMP_FUNC void func_80800268_chdumbwaiterlift(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800268: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080026C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800270: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800274: lhu         $t7, 0x72($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X72);
    // 0x80800278: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8080027C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800280: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80800284: bnel        $t8, $at, L_80800298
    if (ctx->r24 != ctx->r1) {
        // 0x80800288: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800298;
    }
    goto skip_0;
    // 0x80800288: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x8080028C: jal         0x800C53EC
    // 0x80800290: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C53EC(rdram, ctx);
        goto after_0;
    // 0x80800290: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800294: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80800298:
    // 0x80800298: jal         0x80100094
    // 0x8080029C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x8080029C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808002A0: beq         $v0, $zero, L_808002B0
    if (ctx->r2 == 0) {
        // 0x808002A4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808002B0;
    }
    // 0x808002A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808002A8: jal         0x80087CC8
    // 0x808002AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gcnewoption_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x808002AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
L_808002B0:
    // 0x808002B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002B8: jr          $ra
    // 0x808002BC: nop

    return;
    // 0x808002BC: nop

;}
RECOMP_FUNC void func_80800000_chfactorytoxiccloud(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8080000C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800010: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800014: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800018: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080001C: jal         0x80100094
    // 0x80800020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800024: lw          $t6, 0x78($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X78);
    // 0x80800028: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8080002C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800030: sll         $t8, $t6, 26
    ctx->r24 = S32(ctx->r14 << 26);
    // 0x80800034: bgez        $t8, L_80800060
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800038: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800060;
    }
    // 0x80800038: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080003C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800040: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800044: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80800048: jal         0x80089C98
    // 0x8080004C: swc1        $f4, 0x38($s2)
    MEM_W(0X38, ctx->r18) = ctx->f4.u32l;
    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x8080004C: swc1        $f4, 0x38($s2)
    MEM_W(0X38, ctx->r18) = ctx->f4.u32l;
    after_1:
    // 0x80800050: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80800054: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800058: b           L_80800098
    // 0x8080005C: swc1        $f6, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f6.u32l;
        goto L_80800098;
    // 0x8080005C: swc1        $f6, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f6.u32l;
L_80800060:
    // 0x80800060: jal         0x80102424
    // 0x80800064: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x80800064: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800068: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8080006C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800070: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800074: jal         0x80089C98
    // 0x80800078: swc1        $f8, 0x58($s2)
    MEM_W(0X58, ctx->r18) = ctx->f8.u32l;
    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80800078: swc1        $f8, 0x58($s2)
    MEM_W(0X58, ctx->r18) = ctx->f8.u32l;
    after_3:
    // 0x8080007C: lbu         $t9, 0x65($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X65);
    // 0x80800080: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800084: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800088: andi        $t0, $t9, 0xFFFE
    ctx->r8 = ctx->r25 & 0XFFFE;
    // 0x8080008C: sb          $t0, 0x65($s2)
    MEM_B(0X65, ctx->r18) = ctx->r8;
    // 0x80800090: jal         0x8010A570
    // 0x80800094: swc1        $f10, 0x38($s2)
    MEM_W(0X38, ctx->r18) = ctx->f10.u32l;
    func_8010A570(rdram, ctx);
        goto after_4;
    // 0x80800094: swc1        $f10, 0x38($s2)
    MEM_W(0X38, ctx->r18) = ctx->f10.u32l;
    after_4:
L_80800098:
    // 0x80800098: lbu         $t2, 0x64($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X64);
    // 0x8080009C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808000A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000A4: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x808000A8: jal         0x80800FCC
    // 0x808000AC: sb          $t3, 0x64($s2)
    MEM_B(0X64, ctx->r18) = ctx->r11;
    func_80800FCC_chfactorytoxiccloud(rdram, ctx);
        goto after_5;
    // 0x808000AC: sb          $t3, 0x64($s2)
    MEM_B(0X64, ctx->r18) = ctx->r11;
    after_5:
    // 0x808000B0: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
    // 0x808000B4: addiu       $s3, $zero, 0x144
    ctx->r19 = ADD32(0, 0X144);
    // 0x808000B8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_808000BC:
    // 0x808000BC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808000C0: jal         0x80800A34
    // 0x808000C4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80800A34_chfactorytoxiccloud(rdram, ctx);
        goto after_6;
    // 0x808000C4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x808000C8: addiu       $s0, $s0, 0x24
    ctx->r16 = ADD32(ctx->r16, 0X24);
    // 0x808000CC: bne         $s0, $s3, L_808000BC
    if (ctx->r16 != ctx->r19) {
        // 0x808000D0: addiu       $s1, $s1, 0x24
        ctx->r17 = ADD32(ctx->r17, 0X24);
            goto L_808000BC;
    }
    // 0x808000D0: addiu       $s1, $s1, 0x24
    ctx->r17 = ADD32(ctx->r17, 0X24);
    // 0x808000D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808000D8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808000DC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808000E0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808000E4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808000E8: jr          $ra
    // 0x808000EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808000EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void subaddiefade_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: lbu         $v0, 0x9B($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X9B);
    return;
    // 0x80800004: lbu         $v0, 0x9B($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X9B);
;}
RECOMP_FUNC void func_800F6388(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F6388: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F638C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F6390: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F6394: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F6398: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F639C: jal         0x8008F788
    // 0x800F63A0: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_8008F788(rdram, ctx);
        goto after_0;
    // 0x800F63A0: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F63A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F63A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F63AC: jr          $ra
    // 0x800F63B0: nop

    return;
    // 0x800F63B0: nop

;}
RECOMP_FUNC void cadbfunc_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800498: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080049C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004A0: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x808004A4: jal         0x808003EC
    // 0x808004A8: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    func_808003EC_cadbfunc(rdram, ctx);
        goto after_0;
    // 0x808004A8: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x808004AC: bne         $v0, $zero, L_808004BC
    if (ctx->r2 != 0) {
        // 0x808004B0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_808004BC;
    }
    // 0x808004B0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808004B4: b           L_808004D0
    // 0x808004B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808004D0;
    // 0x808004B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808004BC:
    // 0x808004BC: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x808004C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808004C4: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x808004C8: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x808004CC: swc1        $f6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f6.u32l;
L_808004D0:
    // 0x808004D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004D8: jr          $ra
    // 0x808004DC: nop

    return;
    // 0x808004DC: nop

;}
RECOMP_FUNC void func_80800034_chbottlesdead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800034: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800038: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080003C: jal         0x8010C964
    // 0x80800040: nop

    func_8010C964(rdram, ctx);
        goto after_0;
    // 0x80800040: nop

    after_0:
    // 0x80800044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800048: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080004C: jr          $ra
    // 0x80800050: nop

    return;
    // 0x80800050: nop

;}
RECOMP_FUNC void func_800AAD28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AAD28: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800AAD2C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800AAD30: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AAD34: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800AAD38: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800AAD3C: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800AAD40: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800AAD44: addiu       $s2, $s2, 0x795C
    ctx->r18 = ADD32(ctx->r18, 0X795C);
    // 0x800AAD48: addiu       $s0, $s0, 0x7938
    ctx->r16 = ADD32(ctx->r16, 0X7938);
    // 0x800AAD4C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
L_800AAD50:
    // 0x800AAD50: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800AAD54: jal         0x800EE7F8
    // 0x800AAD58: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800AAD58: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x800AAD5C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800AAD60: bne         $s0, $s2, L_800AAD50
    if (ctx->r16 != ctx->r18) {
        // 0x800AAD64: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_800AAD50;
    }
    // 0x800AAD64: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x800AAD68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800AAD6C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800AAD70: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800AAD74: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800AAD78: jr          $ra
    // 0x800AAD7C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800AAD7C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void susplinet_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A4: jr          $ra
    // 0x808002A8: lwc1        $f0, 0x44($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X44);
    return;
    // 0x808002A8: lwc1        $f0, 0x44($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X44);
;}
RECOMP_FUNC void bsbtrot_entrypoint_24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A9C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801AA0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801AA4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80801AA8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801AAC: jal         0x8008CABC
    // 0x80801AB0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80801AB0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    after_0:
    // 0x80801AB4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80801AB8: jal         0x8008AF24
    // 0x80801ABC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x80801ABC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80801AC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801AC4: jal         0x8008AED4
    // 0x80801AC8: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    anctrl_setIndex(rdram, ctx);
        goto after_2;
    // 0x80801AC8: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    after_2:
    // 0x80801ACC: lui         $a1, 0x3FB3
    ctx->r5 = S32(0X3FB3 << 16);
    // 0x80801AD0: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80801AD4: jal         0x8008B1BC
    // 0x80801AD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_3;
    // 0x80801AD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80801ADC: lui         $a1, 0x3EEE
    ctx->r5 = S32(0X3EEE << 16);
    // 0x80801AE0: ori         $a1, $a1, 0x3BCD
    ctx->r5 = ctx->r5 | 0X3BCD;
    // 0x80801AE4: jal         0x8008B24C
    // 0x80801AE8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    anctrl_setStart(rdram, ctx);
        goto after_4;
    // 0x80801AE8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80801AEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801AF0: jal         0x8008B134
    // 0x80801AF4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_5;
    // 0x80801AF4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x80801AF8: jal         0x8008B064
    // 0x80801AFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    anctrl_start(rdram, ctx);
        goto after_6;
    // 0x80801AFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x80801B00: jal         0x80800538
    // 0x80801B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800538_bsbtrot(rdram, ctx);
        goto after_7;
    // 0x80801B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80801B08: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80801B0C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801B10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801B14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801B18: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80801B1C: jal         0x8009FFD8
    // 0x80801B20: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_8;
    // 0x80801B20: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_8:
    // 0x80801B24: jal         0x8009C990
    // 0x80801B28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_9;
    // 0x80801B28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80801B2C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80801B30: jal         0x8009B9C0
    // 0x80801B34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_10;
    // 0x80801B34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80801B38: jal         0x80800438
    // 0x80801B3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800438_bsbtrot(rdram, ctx);
        goto after_11;
    // 0x80801B3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80801B40: jal         0x8009C990
    // 0x80801B44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_12;
    // 0x80801B44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80801B48: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80801B4C: jal         0x8009BB00
    // 0x80801B50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_13;
    // 0x80801B50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80801B54: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80801B58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801B5C: jal         0x8009BA68
    // 0x80801B60: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_14;
    // 0x80801B60: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_14:
    // 0x80801B64: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
    // 0x80801B68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801B6C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80801B70: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80801B74: jr          $ra
    // 0x80801B78: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80801B78: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void _bskazstill_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083620: syscall     70
    recomp_syscall_handler(rdram, ctx, 0x80083620);
    return;
    // 0x80083624: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800F7C_chfirefx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F7C: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x80800F80: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800F84: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800F88: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800F8C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800F90: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800F94: sw          $a0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r4;
    // 0x80800F98: jal         0x80100094
    // 0x80800F9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800F9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800FA0: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x80800FA4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800FA8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800FAC: blez        $t6, L_80800FF4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80800FB0: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80800FF4;
    }
    // 0x80800FB0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80800FB4: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    // 0x80800FB8: addiu       $v1, $sp, 0xA0
    ctx->r3 = ADD32(ctx->r29, 0XA0);
    // 0x80800FBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800FC0:
    // 0x80800FC0: jal         0x8008A040
    // 0x80800FC4: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800FC4: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_1:
    // 0x80800FC8: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80800FCC: beq         $v0, $zero, L_80800FDC
    if (ctx->r2 == 0) {
        // 0x80800FD0: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_80800FDC;
    }
    // 0x80800FD0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80800FD4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800FD8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80800FDC:
    // 0x80800FDC: lw          $t7, 0x4($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X4);
    // 0x80800FE0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800FE4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80800FE8: slt         $at, $s1, $t7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80800FEC: bnel        $at, $zero, L_80800FC0
    if (ctx->r1 != 0) {
        // 0x80800FF0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FC0;
    }
    goto skip_0;
    // 0x80800FF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
L_80800FF4:
    // 0x80800FF4: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x80800FF8: jal         0x80103110
    // 0x80800FFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_2;
    // 0x80800FFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80801000: beq         $s2, $zero, L_80801150
    if (ctx->r18 == 0) {
        // 0x80801004: sw          $zero, 0x4($s3)
        MEM_W(0X4, ctx->r19) = 0;
            goto L_80801150;
    }
    // 0x80801004: sw          $zero, 0x4($s3)
    MEM_W(0X4, ctx->r19) = 0;
    // 0x80801008: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x8080100C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80801010: slt         $at, $t8, $s2
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80801014: bne         $at, $zero, L_80801040
    if (ctx->r1 != 0) {
        // 0x80801018: nop
    
            goto L_80801040;
    }
    // 0x80801018: nop

    // 0x8080101C: blez        $s2, L_80801150
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80801020: addiu       $s0, $sp, 0xA0
        ctx->r16 = ADD32(ctx->r29, 0XA0);
            goto L_80801150;
    }
    // 0x80801020: addiu       $s0, $sp, 0xA0
    ctx->r16 = ADD32(ctx->r29, 0XA0);
L_80801024:
    // 0x80801024: jal         0x80800AA8
    // 0x80801028: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_80800AA8_chfirefx(rdram, ctx);
        goto after_3;
    // 0x80801028: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x8080102C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80801030: bne         $s1, $s2, L_80801024
    if (ctx->r17 != ctx->r18) {
        // 0x80801034: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80801024;
    }
    // 0x80801034: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80801038: b           L_80801154
    // 0x8080103C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801154;
    // 0x8080103C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801040:
    // 0x80801040: jal         0x8010D254
    // 0x80801044: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    func_8010D254(rdram, ctx);
        goto after_4;
    // 0x80801044: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_4:
    // 0x80801048: blez        $s2, L_80801080
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8080104C: addiu       $s0, $sp, 0xA0
        ctx->r16 = ADD32(ctx->r29, 0XA0);
            goto L_80801080;
    }
    // 0x8080104C: addiu       $s0, $sp, 0xA0
    ctx->r16 = ADD32(ctx->r29, 0XA0);
    // 0x80801050: addiu       $v0, $sp, 0x54
    ctx->r2 = ADD32(ctx->r29, 0X54);
L_80801054:
    // 0x80801054: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80801058: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8080105C: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80801060: jal         0x800EEB40
    // 0x80801064: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EEB40(rdram, ctx);
        goto after_5;
    // 0x80801064: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_5:
    // 0x80801068: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8080106C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80801070: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80801074: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80801078: bne         $s1, $s2, L_80801054
    if (ctx->r17 != ctx->r18) {
        // 0x8080107C: swc1        $f0, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f0.u32l;
            goto L_80801054;
    }
    // 0x8080107C: swc1        $f0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f0.u32l;
L_80801080:
    // 0x80801080: slti        $at, $s2, 0x2
    ctx->r1 = SIGNED(ctx->r18) < 0X2 ? 1 : 0;
    // 0x80801084: bne         $at, $zero, L_8080111C
    if (ctx->r1 != 0) {
        // 0x80801088: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8080111C;
    }
    // 0x80801088: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080108C: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    // 0x80801090: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
L_80801094:
    // 0x80801094: blez        $a1, L_80801110
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80801098: or          $s1, $a1, $zero
        ctx->r17 = ctx->r5 | 0;
            goto L_80801110;
    }
    // 0x80801098: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8080109C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x808010A0: addu        $v0, $a2, $t9
    ctx->r2 = ADD32(ctx->r6, ctx->r25);
    // 0x808010A4: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x808010A8: lwc1        $f6, -0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, -0X4);
    // 0x808010AC: sll         $v1, $s1, 2
    ctx->r3 = S32(ctx->r17 << 2);
    // 0x808010B0: addiu       $t0, $sp, 0xA0
    ctx->r8 = ADD32(ctx->r29, 0XA0);
    // 0x808010B4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808010B8: addu        $s0, $v1, $t0
    ctx->r16 = ADD32(ctx->r3, ctx->r8);
    // 0x808010BC: addu        $v0, $a2, $v1
    ctx->r2 = ADD32(ctx->r6, ctx->r3);
    // 0x808010C0: bc1fl       L_80801114
    if (!c1cs) {
        // 0x808010C4: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80801114;
    }
    goto skip_1;
    // 0x808010C4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_1:
    // 0x808010C8: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x808010CC: lwc1        $f12, -0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, -0X4);
    // 0x808010D0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_808010D4:
    // 0x808010D4: lw          $t1, -0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, -0X4);
    // 0x808010D8: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x808010DC: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x808010E0: swc1        $f12, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f12.u32l;
    // 0x808010E4: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x808010E8: addiu       $s0, $s0, -0x4
    ctx->r16 = ADD32(ctx->r16, -0X4);
    // 0x808010EC: sw          $v1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r3;
    // 0x808010F0: bne         $at, $zero, L_80801110
    if (ctx->r1 != 0) {
        // 0x808010F4: sw          $t1, 0x4($s0)
        MEM_W(0X4, ctx->r16) = ctx->r9;
            goto L_80801110;
    }
    // 0x808010F4: sw          $t1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r9;
    // 0x808010F8: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x808010FC: lwc1        $f12, -0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80801100: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80801104: nop

    // 0x80801108: bc1tl       L_808010D4
    if (c1cs) {
        // 0x8080110C: lw          $v1, 0x0($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X0);
            goto L_808010D4;
    }
    goto skip_2;
    // 0x8080110C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    skip_2:
L_80801110:
    // 0x80801110: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80801114:
    // 0x80801114: bne         $a1, $s2, L_80801094
    if (ctx->r5 != ctx->r18) {
        // 0x80801118: nop
    
            goto L_80801094;
    }
    // 0x80801118: nop

L_8080111C:
    // 0x8080111C: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x80801120: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80801124: addiu       $s0, $sp, 0xA0
    ctx->r16 = ADD32(ctx->r29, 0XA0);
    // 0x80801128: blezl       $t2, L_80801154
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8080112C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80801154;
    }
    goto skip_3;
    // 0x8080112C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
L_80801130:
    // 0x80801130: jal         0x80800AA8
    // 0x80801134: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_80800AA8_chfirefx(rdram, ctx);
        goto after_6;
    // 0x80801134: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_6:
    // 0x80801138: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x8080113C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80801140: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80801144: slt         $at, $s1, $t3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80801148: bne         $at, $zero, L_80801130
    if (ctx->r1 != 0) {
        // 0x8080114C: nop
    
            goto L_80801130;
    }
    // 0x8080114C: nop

L_80801150:
    // 0x80801150: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801154:
    // 0x80801154: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801158: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080115C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80801160: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80801164: jr          $ra
    // 0x80801168: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    return;
    // 0x80801168: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
;}
RECOMP_FUNC void glglobaldata_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080008C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800090: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80800094: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800098: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8080009C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x808000A0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x808000A4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808000A8: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(2734, 0X230) << 16);
    // 0x808000AC: lui         $s5, 0x8080
    ctx->r21 = S32(RELOC_HI16(2734, 0X238) << 16);
    // 0x808000B0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x808000B4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808000B8: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x808000BC: addiu       $s5, $s5, 0x238
    ctx->r21 = ADD32(ctx->r21, (int16_t)RELOC_LO16(2734, 0X238));
    // 0x808000C0: addiu       $s0, $s0, 0x230
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(2734, 0X230));
    // 0x808000C4: addiu       $s3, $sp, 0x3C
    ctx->r19 = ADD32(ctx->r29, 0X3C);
    // 0x808000C8: addiu       $s4, $sp, 0x38
    ctx->r20 = ADD32(ctx->r29, 0X38);
L_808000CC:
    // 0x808000CC: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x808000D0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808000D4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x808000D8: jalr        $t9
    // 0x808000DC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x808000DC: nop

    after_0:
    // 0x808000E0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808000E4: addu        $a1, $s2, $s1
    ctx->r5 = ADD32(ctx->r18, ctx->r17);
    // 0x808000E8: jal         0x8001BBA0
    // 0x808000EC: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    rare_memcpy(rdram, ctx);
        goto after_1;
    // 0x808000EC: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    after_1:
    // 0x808000F0: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x808000F4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x808000F8: bne         $s0, $s5, L_808000CC
    if (ctx->r16 != ctx->r21) {
        // 0x808000FC: addu        $s1, $s1, $t6
        ctx->r17 = ADD32(ctx->r17, ctx->r14);
            goto L_808000CC;
    }
    // 0x808000FC: addu        $s1, $s1, $t6
    ctx->r17 = ADD32(ctx->r17, ctx->r14);
    // 0x80800100: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800104: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800108: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080010C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800110: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800114: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80800118: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8080011C: jr          $ra
    // 0x80800120: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80800120: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void _bsbabykaz_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800827B8: syscall     14
    recomp_syscall_handler(rdram, ctx, 0x800827B8);
    return;
    // 0x800827BC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8080077C_chnicecavemen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080077C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800780: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800784: addiu       $at, $zero, 0x17D5
    ctx->r1 = ADD32(0, 0X17D5);
    // 0x80800788: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080078C: beq         $a1, $at, L_808007CC
    if (ctx->r5 == ctx->r1) {
        // 0x80800790: sw          $ra, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r31;
            goto L_808007CC;
    }
    // 0x80800790: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800794: addiu       $at, $zero, 0x17D7
    ctx->r1 = ADD32(0, 0X17D7);
    // 0x80800798: beq         $a1, $at, L_80800850
    if (ctx->r5 == ctx->r1) {
        // 0x8080079C: addiu       $at, $zero, 0x17D8
        ctx->r1 = ADD32(0, 0X17D8);
            goto L_80800850;
    }
    // 0x8080079C: addiu       $at, $zero, 0x17D8
    ctx->r1 = ADD32(0, 0X17D8);
    // 0x808007A0: beq         $a1, $at, L_80800890
    if (ctx->r5 == ctx->r1) {
        // 0x808007A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800890;
    }
    // 0x808007A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007A8: addiu       $at, $zero, 0x17FD
    ctx->r1 = ADD32(0, 0X17FD);
    // 0x808007AC: beq         $a1, $at, L_808008BC
    if (ctx->r5 == ctx->r1) {
        // 0x808007B0: addiu       $at, $zero, 0x1803
        ctx->r1 = ADD32(0, 0X1803);
            goto L_808008BC;
    }
    // 0x808007B0: addiu       $at, $zero, 0x1803
    ctx->r1 = ADD32(0, 0X1803);
    // 0x808007B4: beq         $a1, $at, L_808007CC
    if (ctx->r5 == ctx->r1) {
        // 0x808007B8: addiu       $at, $zero, 0x1811
        ctx->r1 = ADD32(0, 0X1811);
            goto L_808007CC;
    }
    // 0x808007B8: addiu       $at, $zero, 0x1811
    ctx->r1 = ADD32(0, 0X1811);
    // 0x808007BC: beq         $a1, $at, L_808008BC
    if (ctx->r5 == ctx->r1) {
        // 0x808007C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008BC;
    }
    // 0x808007C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007C4: b           L_808008D8
    // 0x808007C8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1096, 0X1810) << 16);
        goto L_808008D8;
    // 0x808007C8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1096, 0X1810) << 16);
L_808007CC:
    // 0x808007CC: blez        $a2, L_80800830
    if (SIGNED(ctx->r6) <= 0) {
        // 0x808007D0: addiu       $a1, $zero, 0x17D6
        ctx->r5 = ADD32(0, 0X17D6);
            goto L_80800830;
    }
    // 0x808007D0: addiu       $a1, $zero, 0x17D6
    ctx->r5 = ADD32(0, 0X17D6);
    // 0x808007D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007D8: jal         0x80100094
    // 0x808007DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808007DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808007E0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x808007E4: jal         0x800FC660
    // 0x808007E8: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC660(rdram, ctx);
        goto after_1;
    // 0x808007E8: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_1:
    // 0x808007EC: jal         0x800DA298
    // 0x808007F0: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x808007F0: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    after_2:
    // 0x808007F4: beq         $v0, $zero, L_80800804
    if (ctx->r2 == 0) {
        // 0x808007F8: addiu       $a1, $zero, 0x5
        ctx->r5 = ADD32(0, 0X5);
            goto L_80800804;
    }
    // 0x808007F8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808007FC: b           L_80800804
    // 0x80800800: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
        goto L_80800804;
    // 0x80800800: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
L_80800804:
    // 0x80800804: jal         0x80800AB8
    // 0x80800808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800AB8_chnicecavemen(rdram, ctx);
        goto after_3;
    // 0x80800808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080080C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800810: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    // 0x80800814: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80800818: jal         0x80089FD0
    // 0x8080081C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _subaddieitem_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x8080081C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x80800820: jal         0x80089FE0
    // 0x80800824: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    _subaddieitem_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x80800824: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_5:
    // 0x80800828: b           L_80800AA8
    // 0x8080082C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800AA8;
    // 0x8080082C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800830:
    // 0x80800830: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800834: addiu       $t6, $zero, 0xA2
    ctx->r14 = ADD32(0, 0XA2);
    // 0x80800838: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080083C: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x80800840: jal         0x8008A208
    // 0x80800844: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x80800844: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_6:
    // 0x80800848: b           L_80800AA8
    // 0x8080084C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800AA8;
    // 0x8080084C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800850:
    // 0x80800850: jal         0x80800BF8
    // 0x80800854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800BF8_chnicecavemen(rdram, ctx);
        goto after_7;
    // 0x80800854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800858: bne         $v0, $zero, L_80800868
    if (ctx->r2 != 0) {
        // 0x8080085C: nop
    
            goto L_80800868;
    }
    // 0x8080085C: nop

    // 0x80800860: jal         0x80801428
    // 0x80800864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801428_chnicecavemen(rdram, ctx);
        goto after_8;
    // 0x80800864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_80800868:
    // 0x80800868: jal         0x800DA298
    // 0x8080086C: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    func_800DA298(rdram, ctx);
        goto after_9;
    // 0x8080086C: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    after_9:
    // 0x80800870: beq         $v0, $zero, L_80800880
    if (ctx->r2 == 0) {
        // 0x80800874: addiu       $a1, $zero, 0x9
        ctx->r5 = ADD32(0, 0X9);
            goto L_80800880;
    }
    // 0x80800874: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80800878: b           L_80800880
    // 0x8080087C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
        goto L_80800880;
    // 0x8080087C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
L_80800880:
    // 0x80800880: jal         0x80800AB8
    // 0x80800884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800AB8_chnicecavemen(rdram, ctx);
        goto after_10;
    // 0x80800884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800888: b           L_80800AA8
    // 0x8080088C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800AA8;
    // 0x8080088C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800890:
    // 0x80800890: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800894: jal         0x80801508
    // 0x80800898: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_80801508_chnicecavemen(rdram, ctx);
        goto after_11;
    // 0x80800898: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_11:
    // 0x8080089C: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    // 0x808008A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808008A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808008A8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808008AC: jal         0x800D1000
    // 0x808008B0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D1000(rdram, ctx);
        goto after_12;
    // 0x808008B0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_12:
    // 0x808008B4: b           L_80800AA8
    // 0x808008B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800AA8;
    // 0x808008B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808008BC:
    // 0x808008BC: jal         0x80801428
    // 0x808008C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801428_chnicecavemen(rdram, ctx);
        goto after_13;
    // 0x808008C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808008C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008C8: jal         0x80800AB8
    // 0x808008CC: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80800AB8_chnicecavemen(rdram, ctx);
        goto after_14;
    // 0x808008CC: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_14:
    // 0x808008D0: b           L_80800AA8
    // 0x808008D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800AA8;
    // 0x808008D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808008D8:
    // 0x808008D8: addiu       $a2, $a2, 0x1810
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1096, 0X1810));
    // 0x808008DC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x808008E0: jal         0x8008A1F8
    // 0x808008E4: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    _subaddiedialog_entrypoint_9(rdram, ctx);
        goto after_15;
    // 0x808008E4: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_15:
    // 0x808008E8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1096, 0X1848) << 16);
    // 0x808008EC: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x808008F0: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x808008F4: addiu       $a2, $a2, 0x1848
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1096, 0X1848));
    // 0x808008F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008FC: jal         0x8008A1F8
    // 0x80800900: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    _subaddiedialog_entrypoint_9(rdram, ctx);
        goto after_16;
    // 0x80800900: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_16:
    // 0x80800904: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1096, 0X1880) << 16);
    // 0x80800908: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8080090C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800910: addiu       $a2, $a2, 0x1880
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1096, 0X1880));
    // 0x80800914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800918: jal         0x8008A1F8
    // 0x8080091C: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    _subaddiedialog_entrypoint_9(rdram, ctx);
        goto after_17;
    // 0x8080091C: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_17:
    // 0x80800920: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1096, 0X18B8) << 16);
    // 0x80800924: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80800928: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8080092C: addiu       $a2, $a2, 0x18B8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1096, 0X18B8));
    // 0x80800930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800934: jal         0x8008A1F8
    // 0x80800938: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    _subaddiedialog_entrypoint_9(rdram, ctx);
        goto after_18;
    // 0x80800938: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_18:
    // 0x8080093C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800940: jal         0x8008A200
    // 0x80800944: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    _subaddiedialog_entrypoint_10(rdram, ctx);
        goto after_19;
    // 0x80800944: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_19:
    // 0x80800948: bne         $v0, $zero, L_80800960
    if (ctx->r2 != 0) {
        // 0x8080094C: nop
    
            goto L_80800960;
    }
    // 0x8080094C: nop

    // 0x80800950: jal         0x8008A200
    // 0x80800954: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    _subaddiedialog_entrypoint_10(rdram, ctx);
        goto after_20;
    // 0x80800954: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_20:
    // 0x80800958: beq         $v0, $zero, L_808009DC
    if (ctx->r2 == 0) {
        // 0x8080095C: nop
    
            goto L_808009DC;
    }
    // 0x8080095C: nop

L_80800960:
    // 0x80800960: jal         0x80801580
    // 0x80800964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801580_chnicecavemen(rdram, ctx);
        goto after_21;
    // 0x80800964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800968: beq         $v0, $zero, L_8080099C
    if (ctx->r2 == 0) {
        // 0x8080096C: addiu       $a0, $zero, 0x64
        ctx->r4 = ADD32(0, 0X64);
            goto L_8080099C;
    }
    // 0x8080096C: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x80800970: jal         0x8080126C
    // 0x80800974: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080126C_chnicecavemen(rdram, ctx);
        goto after_22;
    // 0x80800974: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80800978: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080097C: addiu       $t7, $zero, 0xA2
    ctx->r15 = ADD32(0, 0XA2);
    // 0x80800980: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800984: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800988: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    // 0x8080098C: jal         0x8008A208
    // 0x80800990: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_23;
    // 0x80800990: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_23:
    // 0x80800994: b           L_80800AA8
    // 0x80800998: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800AA8;
    // 0x80800998: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080099C:
    // 0x8080099C: jal         0x800C01A8
    // 0x808009A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C01A8(rdram, ctx);
        goto after_24;
    // 0x808009A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_24:
    // 0x808009A4: jal         0x800C0850
    // 0x808009A8: nop

    func_800C0850(rdram, ctx);
        goto after_25;
    // 0x808009A8: nop

    after_25:
    // 0x808009AC: jal         0x80801428
    // 0x808009B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801428_chnicecavemen(rdram, ctx);
        goto after_26;
    // 0x808009B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x808009B4: jal         0x800DA298
    // 0x808009B8: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    func_800DA298(rdram, ctx);
        goto after_27;
    // 0x808009B8: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    after_27:
    // 0x808009BC: beq         $v0, $zero, L_808009CC
    if (ctx->r2 == 0) {
        // 0x808009C0: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_808009CC;
    }
    // 0x808009C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808009C4: b           L_808009CC
    // 0x808009C8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
        goto L_808009CC;
    // 0x808009C8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
L_808009CC:
    // 0x808009CC: jal         0x80800AB8
    // 0x808009D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800AB8_chnicecavemen(rdram, ctx);
        goto after_28;
    // 0x808009D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x808009D4: b           L_80800AA8
    // 0x808009D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800AA8;
    // 0x808009D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808009DC:
    // 0x808009DC: jal         0x8008A200
    // 0x808009E0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    _subaddiedialog_entrypoint_10(rdram, ctx);
        goto after_29;
    // 0x808009E0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_29:
    // 0x808009E4: beq         $v0, $zero, L_80800A08
    if (ctx->r2 == 0) {
        // 0x808009E8: nop
    
            goto L_80800A08;
    }
    // 0x808009E8: nop

    // 0x808009EC: jal         0x80801428
    // 0x808009F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801428_chnicecavemen(rdram, ctx);
        goto after_30;
    // 0x808009F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x808009F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009F8: jal         0x80800AB8
    // 0x808009FC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80800AB8_chnicecavemen(rdram, ctx);
        goto after_31;
    // 0x808009FC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_31:
    // 0x80800A00: b           L_80800AA8
    // 0x80800A04: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800AA8;
    // 0x80800A04: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800A08:
    // 0x80800A08: jal         0x8008A200
    // 0x80800A0C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    _subaddiedialog_entrypoint_10(rdram, ctx);
        goto after_32;
    // 0x80800A0C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_32:
    // 0x80800A10: beq         $v0, $zero, L_80800A44
    if (ctx->r2 == 0) {
        // 0x80800A14: nop
    
            goto L_80800A44;
    }
    // 0x80800A14: nop

    // 0x80800A18: jal         0x80800BF8
    // 0x80800A1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800BF8_chnicecavemen(rdram, ctx);
        goto after_33;
    // 0x80800A1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
    // 0x80800A20: bnel        $v0, $zero, L_80800A34
    if (ctx->r2 != 0) {
        // 0x80800A24: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A34;
    }
    goto skip_0;
    // 0x80800A24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800A28: jal         0x80801428
    // 0x80800A2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801428_chnicecavemen(rdram, ctx);
        goto after_34;
    // 0x80800A2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x80800A30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800A34:
    // 0x80800A34: jal         0x80800AB8
    // 0x80800A38: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80800AB8_chnicecavemen(rdram, ctx);
        goto after_35;
    // 0x80800A38: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_35:
    // 0x80800A3C: b           L_80800AA8
    // 0x80800A40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800AA8;
    // 0x80800A40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800A44:
    // 0x80800A44: jal         0x800DA298
    // 0x80800A48: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    func_800DA298(rdram, ctx);
        goto after_36;
    // 0x80800A48: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    after_36:
    // 0x80800A4C: beq         $v0, $zero, L_80800A74
    if (ctx->r2 == 0) {
        // 0x80800A50: nop
    
            goto L_80800A74;
    }
    // 0x80800A50: nop

    // 0x80800A54: jal         0x800DA298
    // 0x80800A58: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    func_800DA298(rdram, ctx);
        goto after_37;
    // 0x80800A58: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    after_37:
    // 0x80800A5C: beq         $v0, $zero, L_80800A6C
    if (ctx->r2 == 0) {
        // 0x80800A60: nop
    
            goto L_80800A6C;
    }
    // 0x80800A60: nop

    // 0x80800A64: b           L_80800A8C
    // 0x80800A68: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
        goto L_80800A8C;
    // 0x80800A68: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
L_80800A6C:
    // 0x80800A6C: b           L_80800A8C
    // 0x80800A70: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
        goto L_80800A8C;
    // 0x80800A70: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
L_80800A74:
    // 0x80800A74: jal         0x800DA298
    // 0x80800A78: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    func_800DA298(rdram, ctx);
        goto after_38;
    // 0x80800A78: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    after_38:
    // 0x80800A7C: beq         $v0, $zero, L_80800A8C
    if (ctx->r2 == 0) {
        // 0x80800A80: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80800A8C;
    }
    // 0x80800A80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800A84: b           L_80800A8C
    // 0x80800A88: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
        goto L_80800A8C;
    // 0x80800A88: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
L_80800A8C:
    // 0x80800A8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A90: jal         0x80801428
    // 0x80800A94: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_80801428_chnicecavemen(rdram, ctx);
        goto after_39;
    // 0x80800A94: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_39:
    // 0x80800A98: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800A9C: jal         0x80800AB8
    // 0x80800AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800AB8_chnicecavemen(rdram, ctx);
        goto after_40;
    // 0x80800AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_40:
    // 0x80800AA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800AA8:
    // 0x80800AA8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800AAC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800AB0: jr          $ra
    // 0x80800AB4: nop

    return;
    // 0x80800AB4: nop

;}
RECOMP_FUNC void func_80013500(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013500: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80013504: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80013508: jal         0x80012530
    // 0x8001350C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80012530(rdram, ctx);
        goto after_0;
    // 0x8001350C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80013510: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80013514: bne         $v0, $at, L_80013528
    if (ctx->r2 != ctx->r1) {
        // 0x80013518: lui         $a0, 0x8007
        ctx->r4 = S32(0X8007 << 16);
            goto L_80013528;
    }
    // 0x80013518: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x8001351C: addiu       $a0, $a0, 0x6A20
    ctx->r4 = ADD32(ctx->r4, 0X6A20);
    // 0x80013520: jal         0x8002EC20
    // 0x80013524: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    osSetThreadPri_recomp(rdram, ctx);
        goto after_1;
    // 0x80013524: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
L_80013528:
    // 0x80013528: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001352C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80013530: jr          $ra
    // 0x80013534: nop

    return;
    // 0x80013534: nop

;}
RECOMP_FUNC void func_80800054_charea51gate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800054: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800058: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080005C: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x80800060: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(980, 0X280) << 16);
    // 0x80800064: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x80800068: bgezl       $t8, L_80800094
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8080006C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800094;
    }
    goto skip_0;
    // 0x8080006C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800070: lwc1        $f12, 0x280($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(980, 0X280));
    // 0x80800074: jal         0x800DC298
    // 0x80800078: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800DC298(rdram, ctx);
        goto after_0;
    // 0x80800078: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080007C: beq         $v0, $zero, L_80800090
    if (ctx->r2 == 0) {
        // 0x80800080: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800090;
    }
    // 0x80800080: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800084: addiu       $a1, $a0, 0x18
    ctx->r5 = ADD32(ctx->r4, 0X18);
    // 0x80800088: jal         0x800862C0
    // 0x8080008C: addiu       $a2, $a0, 0x28
    ctx->r6 = ADD32(ctx->r4, 0X28);
    _chelectricfence_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x8080008C: addiu       $a2, $a0, 0x28
    ctx->r6 = ADD32(ctx->r4, 0X28);
    after_1:
L_80800090:
    // 0x80800090: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800094:
    // 0x80800094: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800098: jr          $ra
    // 0x8080009C: nop

    return;
    // 0x8080009C: nop

;}
RECOMP_FUNC void _chwaterfallgrill_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087018: syscall     493
    recomp_syscall_handler(rdram, ctx, 0x80087018);
    return;
    // 0x8008701C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800610_chmusicmenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800610: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800614: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800618: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080061C: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80800620: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800624: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x80800628: bltzl       $t8, L_80800650
    if (SIGNED(ctx->r24) < 0) {
        // 0x8080062C: lw          $t2, 0x30($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X30);
            goto L_80800650;
    }
    goto skip_0;
    // 0x8080062C: lw          $t2, 0x30($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X30);
    skip_0:
    // 0x80800630: jal         0x800FEC60
    // 0x80800634: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800FEC60(rdram, ctx);
        goto after_0;
    // 0x80800634: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_0:
    // 0x80800638: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x8080063C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800640: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x80800644: jal         0x800DA544
    // 0x80800648: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x80800648: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    after_1:
    // 0x8080064C: lw          $t2, 0x30($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X30);
L_80800650:
    // 0x80800650: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(1824, 0X14F4) << 16);
    // 0x80800654: lw          $t4, 0x18($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X18);
    // 0x80800658: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8080065C: addu        $v1, $v1, $t3
    ctx->r3 = ADD32(ctx->r3, ctx->r11);
    // 0x80800660: lw          $v1, 0x14F4($v1)
    ctx->r3 = MEM_W(ctx->r3, (int16_t)RELOC_LO16(1824, 0X14F4));
    // 0x80800664: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80800668: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080066C: addu        $t6, $v1, $t5
    ctx->r14 = ADD32(ctx->r3, ctx->r13);
    // 0x80800670: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x80800674: addiu       $a2, $zero, 0x14D
    ctx->r6 = ADD32(0, 0X14D);
    // 0x80800678: sh          $t7, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r15;
    // 0x8080067C: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
    // 0x80800680: srl         $t8, $v0, 7
    ctx->r24 = S32(U32(ctx->r2) >> 7);
    // 0x80800684: beq         $t8, $zero, L_808006B0
    if (ctx->r24 == 0) {
        // 0x80800688: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_808006B0;
    }
    // 0x80800688: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8080068C: jal         0x800FCAE0
    // 0x80800690: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_800FCAE0(rdram, ctx);
        goto after_2;
    // 0x80800690: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_2:
    // 0x80800694: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    // 0x80800698: srl         $t9, $a0, 7
    ctx->r25 = S32(U32(ctx->r4) >> 7);
    // 0x8080069C: jal         0x800FCA90
    // 0x808006A0: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_800FCA90(rdram, ctx);
        goto after_3;
    // 0x808006A0: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_3:
    // 0x808006A4: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
    // 0x808006A8: srl         $t0, $v0, 7
    ctx->r8 = S32(U32(ctx->r2) >> 7);
    // 0x808006AC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_808006B0:
    // 0x808006B0: lh          $t1, 0x26($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X26);
    // 0x808006B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006B8: bne         $t1, $v0, L_808006D0
    if (ctx->r9 != ctx->r2) {
        // 0x808006BC: or          $a1, $t1, $zero
        ctx->r5 = ctx->r9 | 0;
            goto L_808006D0;
    }
    // 0x808006BC: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x808006C0: jal         0x80800560
    // 0x808006C4: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    func_80800560_chmusicmenu(rdram, ctx);
        goto after_4;
    // 0x808006C4: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    after_4:
    // 0x808006C8: b           L_808006EC
    // 0x808006CC: lh          $t6, 0x26($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X26);
        goto L_808006EC;
    // 0x808006CC: lh          $t6, 0x26($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X26);
L_808006D0:
    // 0x808006D0: lbu         $t3, 0x65($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X65);
    // 0x808006D4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808006D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808006DC: ori         $t4, $t3, 0x8
    ctx->r12 = ctx->r11 | 0X8;
    // 0x808006E0: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
    // 0x808006E4: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    // 0x808006E8: lh          $t6, 0x26($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X26);
L_808006EC:
    // 0x808006EC: lhu         $t9, 0x76($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X76);
    // 0x808006F0: sll         $t8, $t6, 7
    ctx->r24 = S32(ctx->r14 << 7);
    // 0x808006F4: andi        $t0, $t9, 0x7F
    ctx->r8 = ctx->r25 & 0X7F;
    // 0x808006F8: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x808006FC: sh          $t1, 0x76($s0)
    MEM_H(0X76, ctx->r16) = ctx->r9;
    // 0x80800700: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800704: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800708: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080070C: jr          $ra
    // 0x80800710: nop

    return;
    // 0x80800710: nop

;}
RECOMP_FUNC void func_800E73D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E73D4: jr          $ra
    // 0x800E73D8: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    return;
    // 0x800E73D8: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
;}
RECOMP_FUNC void func_80114184(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80114184: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80114188: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8011418C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80114190: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80114194: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x80114198: bne         $a3, $zero, L_801141B0
    if (ctx->r7 != 0) {
        // 0x8011419C: sw          $a2, 0x80($sp)
        MEM_W(0X80, ctx->r29) = ctx->r6;
            goto L_801141B0;
    }
    // 0x8011419C: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x801141A0: jal         0x80113FF0
    // 0x801141A4: nop

    func_80113FF0(rdram, ctx);
        goto after_0;
    // 0x801141A4: nop

    after_0:
    // 0x801141A8: b           L_80114394
    // 0x801141AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80114394;
    // 0x801141AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801141B0:
    // 0x801141B0: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x801141B4: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x801141B8: jal         0x800CA8F4
    // 0x801141BC: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    func_800CA8F4(rdram, ctx);
        goto after_1;
    // 0x801141BC: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    after_1:
    // 0x801141C0: lbu         $t6, 0x3($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X3);
    // 0x801141C4: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x801141C8: addiu       $a1, $s0, 0x3C
    ctx->r5 = ADD32(ctx->r16, 0X3C);
    // 0x801141CC: beql        $t6, $zero, L_8011422C
    if (ctx->r14 == 0) {
        // 0x801141D0: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_8011422C;
    }
    goto skip_0;
    // 0x801141D0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    skip_0:
    // 0x801141D4: jal         0x800EEAA4
    // 0x801141D8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_800EEAA4(rdram, ctx);
        goto after_2;
    // 0x801141D8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_2:
    // 0x801141DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801141E0: lwc1        $f4, 0x65E0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X65E0);
    // 0x801141E4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x801141E8: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x801141EC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x801141F0: nop

    // 0x801141F4: bc1fl       L_8011422C
    if (!c1cs) {
        // 0x801141F8: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_8011422C;
    }
    goto skip_1;
    // 0x801141F8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    skip_1:
    // 0x801141FC: jal         0x800EFB24
    // 0x80114200: addiu       $a2, $s0, 0x14
    ctx->r6 = ADD32(ctx->r16, 0X14);
    func_800EFB24(rdram, ctx);
        goto after_3;
    // 0x80114200: addiu       $a2, $s0, 0x14
    ctx->r6 = ADD32(ctx->r16, 0X14);
    after_3:
    // 0x80114204: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80114208: jal         0x800EEAA4
    // 0x8011420C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800EEAA4(rdram, ctx);
        goto after_4;
    // 0x8011420C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x80114210: lw          $t7, 0x38($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X38);
    // 0x80114214: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80114218: sb          $t0, 0x98($s0)
    MEM_B(0X98, ctx->r16) = ctx->r8;
    // 0x8011421C: swc1        $f0, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f0.u32l;
    // 0x80114220: b           L_8011423C
    // 0x80114224: sw          $t7, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->r15;
        goto L_8011423C;
    // 0x80114224: sw          $t7, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->r15;
    // 0x80114228: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
L_8011422C:
    // 0x8011422C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80114230: sw          $zero, 0x90($s0)
    MEM_W(0X90, ctx->r16) = 0;
    // 0x80114234: sb          $zero, 0x98($s0)
    MEM_B(0X98, ctx->r16) = 0;
    // 0x80114238: swc1        $f6, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f6.u32l;
L_8011423C:
    // 0x8011423C: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x80114240: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x80114244: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x80114248: jal         0x8011413C
    // 0x8011424C: lh          $a3, 0x0($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X0);
    func_8011413C(rdram, ctx);
        goto after_5;
    // 0x8011424C: lh          $a3, 0x0($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X0);
    after_5:
    // 0x80114250: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x80114254: jal         0x800EF04C
    // 0x80114258: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    func_800EF04C(rdram, ctx);
        goto after_6;
    // 0x80114258: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    after_6:
    // 0x8011425C: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80114260: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x80114264: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    // 0x80114268: jal         0x800C6A7C
    // 0x8011426C: lw          $a3, 0x88($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X88);
    func_800C6A7C(rdram, ctx);
        goto after_7;
    // 0x8011426C: lw          $a3, 0x88($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X88);
    after_7:
    // 0x80114270: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80114274: beq         $v0, $zero, L_801142D8
    if (ctx->r2 == 0) {
        // 0x80114278: sw          $v0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r2;
            goto L_801142D8;
    }
    // 0x80114278: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x8011427C: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80114280: jal         0x800EEAD4
    // 0x80114284: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    func_800EEAD4(rdram, ctx);
        goto after_8;
    // 0x80114284: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_8:
    // 0x80114288: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x8011428C: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x80114290: jal         0x800EF3DC
    // 0x80114294: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    func_800EF3DC(rdram, ctx);
        goto after_9;
    // 0x80114294: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    after_9:
    // 0x80114298: lh          $t1, 0x0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X0);
    // 0x8011429C: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x801142A0: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x801142A4: multu       $t1, $v0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801142A8: lwc1        $f2, 0x50($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X50);
    // 0x801142AC: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x801142B0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801142B4: mflo        $t2
    ctx->r10 = lo;
    // 0x801142B8: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x801142BC: sw          $t9, 0x48($t3)
    MEM_W(0X48, ctx->r11) = ctx->r25;
    // 0x801142C0: lh          $t4, 0x0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X0);
    // 0x801142C4: multu       $t4, $v0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801142C8: mflo        $t5
    ctx->r13 = lo;
    // 0x801142CC: addu        $t6, $s0, $t5
    ctx->r14 = ADD32(ctx->r16, ctx->r13);
    // 0x801142D0: b           L_8011430C
    // 0x801142D4: sb          $t0, 0x50($t6)
    MEM_B(0X50, ctx->r14) = ctx->r8;
        goto L_8011430C;
    // 0x801142D4: sb          $t0, 0x50($t6)
    MEM_B(0X50, ctx->r14) = ctx->r8;
L_801142D8:
    // 0x801142D8: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x801142DC: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x801142E0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x801142E4: multu       $t7, $v0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801142E8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801142EC: mflo        $t8
    ctx->r24 = lo;
    // 0x801142F0: addu        $t1, $s0, $t8
    ctx->r9 = ADD32(ctx->r16, ctx->r24);
    // 0x801142F4: sw          $zero, 0x48($t1)
    MEM_W(0X48, ctx->r9) = 0;
    // 0x801142F8: lh          $t2, 0x0($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X0);
    // 0x801142FC: multu       $t2, $v0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80114300: mflo        $t9
    ctx->r25 = lo;
    // 0x80114304: addu        $t3, $s0, $t9
    ctx->r11 = ADD32(ctx->r16, ctx->r25);
    // 0x80114308: sb          $zero, 0x50($t3)
    MEM_B(0X50, ctx->r11) = 0;
L_8011430C:
    // 0x8011430C: lh          $t4, 0x0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X0);
    // 0x80114310: lui         $a1, 0x2
    ctx->r5 = S32(0X2 << 16);
    // 0x80114314: ori         $a1, $a1, 0x20
    ctx->r5 = ctx->r5 | 0X20;
    // 0x80114318: multu       $t4, $v0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8011431C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80114320: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80114324: addiu       $a2, $zero, 0x54
    ctx->r6 = ADD32(0, 0X54);
    // 0x80114328: mflo        $t5
    ctx->r13 = lo;
    // 0x8011432C: addu        $t6, $s0, $t5
    ctx->r14 = ADD32(ctx->r16, ctx->r13);
    // 0x80114330: swc1        $f2, 0x4C($t6)
    MEM_W(0X4C, ctx->r14) = ctx->f2.u32l;
    // 0x80114334: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x80114338: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8011433C: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
    // 0x80114340: lh          $t1, 0x0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X0);
    // 0x80114344: slti        $at, $t1, 0x6
    ctx->r1 = SIGNED(ctx->r9) < 0X6 ? 1 : 0;
    // 0x80114348: bnel        $at, $zero, L_80114358
    if (ctx->r1 != 0) {
        // 0x8011434C: sb          $zero, 0x2($s0)
        MEM_B(0X2, ctx->r16) = 0;
            goto L_80114358;
    }
    goto skip_2;
    // 0x8011434C: sb          $zero, 0x2($s0)
    MEM_B(0X2, ctx->r16) = 0;
    skip_2:
    // 0x80114350: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x80114354: sb          $zero, 0x2($s0)
    MEM_B(0X2, ctx->r16) = 0;
L_80114358:
    // 0x80114358: lw          $a0, 0x48($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X48);
    // 0x8011435C: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x80114360: beq         $a0, $zero, L_80114380
    if (ctx->r4 == 0) {
        // 0x80114364: and         $t2, $a0, $a1
        ctx->r10 = ctx->r4 & ctx->r5;
            goto L_80114380;
    }
    // 0x80114364: and         $t2, $a0, $a1
    ctx->r10 = ctx->r4 & ctx->r5;
    // 0x80114368: beq         $t2, $zero, L_80114378
    if (ctx->r10 == 0) {
        // 0x8011436C: nop
    
            goto L_80114378;
    }
    // 0x8011436C: nop

    // 0x80114370: b           L_80114380
    // 0x80114374: sb          $t0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r8;
        goto L_80114380;
    // 0x80114374: sb          $t0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r8;
L_80114378:
    // 0x80114378: b           L_80114388
    // 0x8011437C: sb          $zero, 0x2($s0)
    MEM_B(0X2, ctx->r16) = 0;
        goto L_80114388;
    // 0x8011437C: sb          $zero, 0x2($s0)
    MEM_B(0X2, ctx->r16) = 0;
L_80114380:
    // 0x80114380: bne         $v0, $a2, L_80114358
    if (ctx->r2 != ctx->r6) {
        // 0x80114384: addiu       $v1, $v1, 0xC
        ctx->r3 = ADD32(ctx->r3, 0XC);
            goto L_80114358;
    }
    // 0x80114384: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
L_80114388:
    // 0x80114388: jal         0x80113FF0
    // 0x8011438C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80113FF0(rdram, ctx);
        goto after_10;
    // 0x8011438C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80114390: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80114394:
    // 0x80114394: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80114398: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x8011439C: jr          $ra
    // 0x801143A0: nop

    return;
    // 0x801143A0: nop

;}
RECOMP_FUNC void func_800AE708(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE708: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800AE70C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800AE710: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800AE714: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800AE718: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800AE71C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800AE720: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800AE724: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800AE728: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AE72C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800AE730: jal         0x800AE0B8
    // 0x800AE734: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    func_800AE0B8(rdram, ctx);
        goto after_0;
    // 0x800AE734: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800AE738: bne         $v0, $zero, L_800AE748
    if (ctx->r2 != 0) {
        // 0x800AE73C: lw          $a3, 0x3C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X3C);
            goto L_800AE748;
    }
    // 0x800AE73C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x800AE740: b           L_800AE7FC
    // 0x800AE744: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AE7FC;
    // 0x800AE744: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800AE748:
    // 0x800AE748: lh          $t6, 0x4($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X4);
    // 0x800AE74C: lh          $t7, 0x4($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X4);
    // 0x800AE750: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800AE754: beql        $at, $zero, L_800AE768
    if (ctx->r1 == 0) {
        // 0x800AE758: lwc1        $f4, 0x0($a3)
        ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
            goto L_800AE768;
    }
    goto skip_0;
    // 0x800AE758: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    skip_0:
    // 0x800AE75C: b           L_800AE7FC
    // 0x800AE760: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AE7FC;
    // 0x800AE760: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800AE764: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
L_800AE768:
    // 0x800AE768: lwc1        $f6, 0x0($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X0);
    // 0x800AE76C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800AE770: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800AE774: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800AE778: nop

    // 0x800AE77C: bc1t        L_800AE78C
    if (c1cs) {
        // 0x800AE780: nop
    
            goto L_800AE78C;
    }
    // 0x800AE780: nop

    // 0x800AE784: b           L_800AE7FC
    // 0x800AE788: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AE7FC;
    // 0x800AE788: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800AE78C:
    // 0x800AE78C: jal         0x800ADCD0
    // 0x800AE790: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    func_800ADCD0(rdram, ctx);
        goto after_1;
    // 0x800AE790: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_1:
    // 0x800AE794: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x800AE798: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800AE79C: lh          $t8, 0x4($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X4);
    // 0x800AE7A0: lw          $s1, 0x0($t0)
    ctx->r17 = MEM_W(ctx->r8, 0X0);
    // 0x800AE7A4: addiu       $s0, $a3, 0x8
    ctx->r16 = ADD32(ctx->r7, 0X8);
    // 0x800AE7A8: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x800AE7AC: addu        $s2, $t9, $a3
    ctx->r18 = ADD32(ctx->r25, ctx->r7);
    // 0x800AE7B0: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800AE7B4: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x800AE7B8: beq         $at, $zero, L_800AE7F8
    if (ctx->r1 == 0) {
        // 0x800AE7BC: addiu       $s1, $s1, 0x50
        ctx->r17 = ADD32(ctx->r17, 0X50);
            goto L_800AE7F8;
    }
    // 0x800AE7BC: addiu       $s1, $s1, 0x50
    ctx->r17 = ADD32(ctx->r17, 0X50);
L_800AE7C0:
    // 0x800AE7C0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800AE7C4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800AE7C8: jal         0x800ADE50
    // 0x800AE7CC: lh          $a2, 0xC($s0)
    ctx->r6 = MEM_H(ctx->r16, 0XC);
    func_800ADE50(rdram, ctx);
        goto after_2;
    // 0x800AE7CC: lh          $a2, 0xC($s0)
    ctx->r6 = MEM_H(ctx->r16, 0XC);
    after_2:
    // 0x800AE7D0: bne         $v0, $zero, L_800AE7E0
    if (ctx->r2 != 0) {
        // 0x800AE7D4: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800AE7E0;
    }
    // 0x800AE7D4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800AE7D8: b           L_800AE7FC
    // 0x800AE7DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AE7FC;
    // 0x800AE7DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800AE7E0:
    // 0x800AE7E0: jal         0x800F293C
    // 0x800AE7E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800F293C(rdram, ctx);
        goto after_3;
    // 0x800AE7E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x800AE7E8: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x800AE7EC: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x800AE7F0: bne         $at, $zero, L_800AE7C0
    if (ctx->r1 != 0) {
        // 0x800AE7F4: addiu       $s1, $s1, 0x40
        ctx->r17 = ADD32(ctx->r17, 0X40);
            goto L_800AE7C0;
    }
    // 0x800AE7F4: addiu       $s1, $s1, 0x40
    ctx->r17 = ADD32(ctx->r17, 0X40);
L_800AE7F8:
    // 0x800AE7F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800AE7FC:
    // 0x800AE7FC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800AE800: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800AE804: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800AE808: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800AE80C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800AE810: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800AE814: jr          $ra
    // 0x800AE818: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800AE818: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800AE81C: nop

;}
RECOMP_FUNC void func_8080000C_chboilerbossdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800010: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800014: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800018: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080001C: jal         0x800DA298
    // 0x80800020: addiu       $a0, $zero, 0x179
    ctx->r4 = ADD32(0, 0X179);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800020: addiu       $a0, $zero, 0x179
    ctx->r4 = ADD32(0, 0X179);
    after_0:
    // 0x80800024: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800028: bne         $v1, $zero, L_80800040
    if (ctx->r3 != 0) {
        // 0x8080002C: sw          $v1, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r3;
            goto L_80800040;
    }
    // 0x8080002C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x80800030: jal         0x80088848
    // 0x80800034: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x80800034: nop

    after_1:
    // 0x80800038: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
    // 0x8080003C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
L_80800040:
    // 0x80800040: beq         $v1, $zero, L_80800050
    if (ctx->r3 == 0) {
        // 0x80800044: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800050;
    }
    // 0x80800044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800048: jal         0x80101FDC
    // 0x8080004C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x8080004C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_80800050:
    // 0x80800050: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1416, 0XE0) << 16);
    // 0x80800054: lwc1        $f6, 0xE0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1416, 0XE0));
    // 0x80800058: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800060: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800064: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800068: jal         0x80102FDC
    // 0x8080006C: nop

    func_80102FDC(rdram, ctx);
        goto after_3;
    // 0x8080006C: nop

    after_3:
    // 0x80800070: addiu       $t6, $zero, 0x802
    ctx->r14 = ADD32(0, 0X802);
    // 0x80800074: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80800078: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8080007C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800084: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800088: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x8080008C: jal         0x80086898
    // 0x80800090: lui         $a3, 0x43C8
    ctx->r7 = S32(0X43C8 << 16);
    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80800090: lui         $a3, 0x43C8
    ctx->r7 = S32(0X43C8 << 16);
    after_4:
    // 0x80800094: beq         $v0, $zero, L_808000B0
    if (ctx->r2 == 0) {
        // 0x80800098: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000B0;
    }
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080009C: jal         0x800868A8
    // 0x808000A0: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_5;
    // 0x808000A0: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_5:
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A8: jal         0x800868C0
    // 0x808000AC: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x808000AC: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_6:
L_808000B0:
    // 0x808000B0: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x808000BC: bnel        $t8, $zero, L_808000D0
    if (ctx->r24 != 0) {
        // 0x808000C0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808000D0;
    }
    goto skip_0;
    // 0x808000C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808000C4: jal         0x8010108C
    // 0x808000C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_7;
    // 0x808000C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x808000CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000D0:
    // 0x808000D0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808000D4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808000D8: jr          $ra
    // 0x808000DC: nop

    return;
    // 0x808000DC: nop

;}
RECOMP_FUNC void bstaxi_entrypoint_27(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801774: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801778: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080177C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801780: jal         0x80801600
    // 0x80801784: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801600_bstaxi(rdram, ctx);
        goto after_0;
    // 0x80801784: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801788: jal         0x808000D4
    // 0x8080178C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bstaxi_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x8080178C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801790: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801794: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801798: jr          $ra
    // 0x8080179C: nop

    return;
    // 0x8080179C: nop

;}
RECOMP_FUNC void player_isStable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E078: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008E07C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008E080: jal         0x800A0FCC
    // 0x8008E084: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800A0FCC(rdram, ctx);
        goto after_0;
    // 0x8008E084: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008E088: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008E08C: beq         $t6, $zero, L_8008E0B8
    if (ctx->r14 == 0) {
        // 0x8008E090: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8008E0B8;
    }
    // 0x8008E090: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8008E094: jal         0x8009BB50
    // 0x8008E098: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_1;
    // 0x8008E098: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8008E09C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8008E0A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008E0A4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8008E0A8: nop

    // 0x8008E0AC: bc1fl       L_8008E0BC
    if (!c1cs) {
        // 0x8008E0B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8008E0BC;
    }
    goto skip_0;
    // 0x8008E0B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8008E0B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008E0B8:
    // 0x8008E0B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008E0BC:
    // 0x8008E0BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008E0C0: jr          $ra
    // 0x8008E0C4: nop

    return;
    // 0x8008E0C4: nop

;}
RECOMP_FUNC void func_800E7778(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E7778: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E777C: addiu       $v0, $v0, -0x2A80
    ctx->r2 = ADD32(ctx->r2, -0X2A80);
    // 0x800E7780: lw          $t6, 0x14($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X14);
    // 0x800E7784: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E7788: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E778C: beql        $a1, $t6, L_800E781C
    if (ctx->r5 == ctx->r14) {
        // 0x800E7790: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800E781C;
    }
    goto skip_0;
    // 0x800E7790: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800E7794: sw          $a1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r5;
    // 0x800E7798: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800E779C: jal         0x800E765C
    // 0x800E77A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800E765C(rdram, ctx);
        goto after_0;
    // 0x800E77A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800E77A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800E77A8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800E77AC: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x800E77B0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800E77B4: ori         $t8, $t8, 0xA01
    ctx->r24 = ctx->r24 | 0XA01;
    // 0x800E77B8: lui         $t3, 0xE200
    ctx->r11 = S32(0XE200 << 16);
    // 0x800E77BC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800E77C0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800E77C4: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x800E77C8: bne         $a1, $zero, L_800E77F8
    if (ctx->r5 != 0) {
        // 0x800E77CC: sw          $t8, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r24;
            goto L_800E77F8;
    }
    // 0x800E77CC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800E77D0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800E77D4: lui         $t0, 0xE200
    ctx->r8 = S32(0XE200 << 16);
    // 0x800E77D8: lui         $t1, 0x50
    ctx->r9 = S32(0X50 << 16);
    // 0x800E77DC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800E77E0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800E77E4: ori         $t1, $t1, 0x4A40
    ctx->r9 = ctx->r9 | 0X4A40;
    // 0x800E77E8: ori         $t0, $t0, 0x1C
    ctx->r8 = ctx->r8 | 0X1C;
    // 0x800E77EC: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x800E77F0: b           L_800E7818
    // 0x800E77F4: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
        goto L_800E7818;
    // 0x800E77F4: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
L_800E77F8:
    // 0x800E77F8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800E77FC: lui         $t4, 0xC18
    ctx->r12 = S32(0XC18 << 16);
    // 0x800E7800: ori         $t4, $t4, 0x4A40
    ctx->r12 = ctx->r12 | 0X4A40;
    // 0x800E7804: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x800E7808: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x800E780C: ori         $t3, $t3, 0x1C
    ctx->r11 = ctx->r11 | 0X1C;
    // 0x800E7810: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800E7814: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
L_800E7818:
    // 0x800E7818: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E781C:
    // 0x800E781C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E7820: jr          $ra
    // 0x800E7824: nop

    return;
    // 0x800E7824: nop

;}
RECOMP_FUNC void chjinjo_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011A8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1672, 0X13A4) << 16);
    // 0x808011AC: jr          $ra
    // 0x808011B0: addiu       $v0, $v0, 0x13A4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1672, 0X13A4));
    return;
    // 0x808011B0: addiu       $v0, $v0, 0x13A4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1672, 0X13A4));
;}
RECOMP_FUNC void gcnewoption_entrypoint_44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802DFC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80802E00: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80802E04: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80802E08: lbu         $t9, 0x1D($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1D);
    // 0x80802E0C: sll         $t7, $a1, 4
    ctx->r15 = S32(ctx->r5 << 4);
    // 0x80802E10: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x80802E14: andi        $t0, $t9, 0xFFEF
    ctx->r8 = ctx->r25 & 0XFFEF;
    // 0x80802E18: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80802E1C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802E20: beq         $a1, $zero, L_80802E58
    if (ctx->r5 == 0) {
        // 0x80802E24: sb          $t1, 0x1D($a0)
        MEM_B(0X1D, ctx->r4) = ctx->r9;
            goto L_80802E58;
    }
    // 0x80802E24: sb          $t1, 0x1D($a0)
    MEM_B(0X1D, ctx->r4) = ctx->r9;
    // 0x80802E28: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2590, 0X307C) << 16);
    // 0x80802E2C: lwc1        $f4, 0x307C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2590, 0X307C));
    // 0x80802E30: lw          $a0, 0x20($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20);
    // 0x80802E34: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80802E38: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80802E3C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80802E40: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80802E44: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80802E48: jal         0x80087B80
    // 0x80802E4C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    _gczoombox_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80802E4C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80802E50: b           L_80802EFC
    // 0x80802E54: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80802EFC;
    // 0x80802E54: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80802E58:
    // 0x80802E58: lw          $v1, 0x1C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1C);
    // 0x80802E5C: sll         $t3, $v1, 13
    ctx->r11 = S32(ctx->r3 << 13);
    // 0x80802E60: bltzl       $t3, L_80802E9C
    if (SIGNED(ctx->r11) < 0) {
        // 0x80802E64: sll         $t9, $v1, 10
        ctx->r25 = S32(ctx->r3 << 10);
            goto L_80802E9C;
    }
    goto skip_0;
    // 0x80802E64: sll         $t9, $v1, 10
    ctx->r25 = S32(ctx->r3 << 10);
    skip_0:
    // 0x80802E68: jal         0x80087BE0
    // 0x80802E6C: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    _gczoombox_entrypoint_32(rdram, ctx);
        goto after_1;
    // 0x80802E6C: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    after_1:
    // 0x80802E70: lw          $a0, 0x23C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X23C);
    // 0x80802E74: jal         0x80088720
    // 0x80802E78: lh          $a1, 0x26($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X26);
    _gldbstring_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80802E78: lh          $a1, 0x26($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X26);
    after_2:
    // 0x80802E7C: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x80802E80: jal         0x80087B20
    // 0x80802E84: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _gczoombox_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x80802E84: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80802E88: lbu         $t5, 0x1D($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X1D);
    // 0x80802E8C: ori         $t6, $t5, 0x4
    ctx->r14 = ctx->r13 | 0X4;
    // 0x80802E90: sb          $t6, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r14;
    // 0x80802E94: lw          $v1, 0x1C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1C);
    // 0x80802E98: sll         $t9, $v1, 10
    ctx->r25 = S32(ctx->r3 << 10);
L_80802E9C:
    // 0x80802E9C: bgez        $t9, L_80802ED4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80802EA0: lui         $a1, 0x4170
        ctx->r5 = S32(0X4170 << 16);
            goto L_80802ED4;
    }
    // 0x80802EA0: lui         $a1, 0x4170
    ctx->r5 = S32(0X4170 << 16);
    // 0x80802EA4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2590, 0X3080) << 16);
    // 0x80802EA8: lwc1        $f6, 0x3080($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2590, 0X3080));
    // 0x80802EAC: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x80802EB0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80802EB4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80802EB8: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x80802EBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80802EC0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80802EC4: jal         0x80087B80
    // 0x80802EC8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    _gczoombox_entrypoint_20(rdram, ctx);
        goto after_4;
    // 0x80802EC8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x80802ECC: b           L_80802EFC
    // 0x80802ED0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80802EFC;
    // 0x80802ED0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80802ED4:
    // 0x80802ED4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2590, 0X3084) << 16);
    // 0x80802ED8: lwc1        $f8, 0x3084($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2590, 0X3084));
    // 0x80802EDC: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x80802EE0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80802EE4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80802EE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80802EEC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80802EF0: jal         0x80087B80
    // 0x80802EF4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    _gczoombox_entrypoint_20(rdram, ctx);
        goto after_5;
    // 0x80802EF4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x80802EF8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80802EFC:
    // 0x80802EFC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80802F00: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80802F04: jr          $ra
    // 0x80802F08: nop

    return;
    // 0x80802F08: nop

;}
RECOMP_FUNC void func_8009D874(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D874: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009D878: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009D87C: lui         $a2, 0x3F8E
    ctx->r6 = S32(0X3F8E << 16);
    // 0x8009D880: ori         $a2, $a2, 0xF9DB
    ctx->r6 = ctx->r6 | 0XF9DB;
    // 0x8009D884: jal         0x8009DE38
    // 0x8009D888: addiu       $a1, $zero, 0x442E
    ctx->r5 = ADD32(0, 0X442E);
    func_8009DE38(rdram, ctx);
        goto after_0;
    // 0x8009D888: addiu       $a1, $zero, 0x442E
    ctx->r5 = ADD32(0, 0X442E);
    after_0:
    // 0x8009D88C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009D890: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009D894: jr          $ra
    // 0x8009D898: nop

    return;
    // 0x8009D898: nop

;}
RECOMP_FUNC void bababykaz_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000D4: jal         0x800F8B88
    // 0x808000D8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800F8B88(rdram, ctx);
        goto after_0;
    // 0x808000D8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000E0: bne         $v0, $at, L_808000F0
    if (ctx->r2 != ctx->r1) {
        // 0x808000E4: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_808000F0;
    }
    // 0x808000E4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808000E8: b           L_808000F0
    // 0x808000EC: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
        goto L_808000F0;
    // 0x808000EC: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
L_808000F0:
    // 0x808000F0: jal         0x800F8A5C
    // 0x808000F4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_800F8A5C(rdram, ctx);
        goto after_1;
    // 0x808000F4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_1:
    // 0x808000F8: jal         0x800EA05C
    // 0x808000FC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800EA05C(rdram, ctx);
        goto after_2;
    // 0x808000FC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x80800100: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800104: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800108: beq         $v0, $t6, L_80800118
    if (ctx->r2 == ctx->r14) {
        // 0x8080010C: nop
    
            goto L_80800118;
    }
    // 0x8080010C: nop

    // 0x80800110: b           L_80800120
    // 0x80800114: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80800120;
    // 0x80800114: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80800118:
    // 0x80800118: jal         0x800878A0
    // 0x8080011C: nop

    _plsu_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x8080011C: nop

    after_3:
L_80800120:
    // 0x80800120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800124: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800128: jr          $ra
    // 0x8080012C: nop

    return;
    // 0x8080012C: nop

;}
RECOMP_FUNC void _bstaxi_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083E78: syscall     96
    recomp_syscall_handler(rdram, ctx, 0x80083E78);
    return;
    // 0x80083E7C: addi        $t0, $zero, 0x58
    ctx->r8 = ADD32(0, 0X58);
;}
RECOMP_FUNC void bapreload_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800100: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800104: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800108: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8080010C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800110: jal         0x800D3948
    // 0x80800114: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800D3948(rdram, ctx);
        goto after_0;
    // 0x80800114: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800118: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8080011C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800120: beq         $v0, $zero, L_80800138
    if (ctx->r2 == 0) {
        // 0x80800124: lw          $a3, 0x24($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X24);
            goto L_80800138;
    }
    // 0x80800124: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80800128: jal         0x80800000
    // 0x8080012C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800000_bapreload(rdram, ctx);
        goto after_1;
    // 0x8080012C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800130: b           L_808001BC
    // 0x80800134: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808001BC;
    // 0x80800134: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800138:
    // 0x80800138: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8080013C: bne         $a1, $at, L_80800174
    if (ctx->r5 != ctx->r1) {
        // 0x80800140: sll         $t8, $a1, 2
        ctx->r24 = S32(ctx->r5 << 2);
            goto L_80800174;
    }
    // 0x80800140: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x80800144: jal         0x8009EA2C
    // 0x80800148: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_8009EA2C(rdram, ctx);
        goto after_2;
    // 0x80800148: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_2:
    // 0x8080014C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800150: beq         $v0, $zero, L_80800164
    if (ctx->r2 == 0) {
        // 0x80800154: lw          $a3, 0x24($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X24);
            goto L_80800164;
    }
    // 0x80800154: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80800158: addiu       $t6, $zero, 0x83A
    ctx->r14 = ADD32(0, 0X83A);
    // 0x8080015C: b           L_8080016C
    // 0x80800160: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
        goto L_8080016C;
    // 0x80800160: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
L_80800164:
    // 0x80800164: addiu       $t7, $zero, 0x61C
    ctx->r15 = ADD32(0, 0X61C);
    // 0x80800168: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
L_8080016C:
    // 0x8080016C: b           L_808001B8
    // 0x80800170: sh          $zero, 0x0($a3)
    MEM_H(0X0, ctx->r7) = 0;
        goto L_808001B8;
    // 0x80800170: sh          $zero, 0x0($a3)
    MEM_H(0X0, ctx->r7) = 0;
L_80800174:
    // 0x80800174: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(572, 0X2A0) << 16);
    // 0x80800178: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8080017C: lh          $t9, 0x2A0($t9)
    ctx->r25 = MEM_H(ctx->r25, (int16_t)RELOC_LO16(572, 0X2A0));
    // 0x80800180: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80800184: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
    // 0x80800188: sh          $zero, 0x0($a3)
    MEM_H(0X0, ctx->r7) = 0;
    // 0x8080018C: lh          $t0, 0x0($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X0);
    // 0x80800190: bnel        $t0, $zero, L_808001BC
    if (ctx->r8 != 0) {
        // 0x80800194: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808001BC;
    }
    goto skip_0;
    // 0x80800194: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800198: lbu         $t1, 0x762C($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X762C);
    // 0x8080019C: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x808001A0: addiu       $t2, $zero, 0x607
    ctx->r10 = ADD32(0, 0X607);
    // 0x808001A4: bnel        $t1, $at, L_808001B8
    if (ctx->r9 != ctx->r1) {
        // 0x808001A8: sh          $t2, 0x0($a2)
        MEM_H(0X0, ctx->r6) = ctx->r10;
            goto L_808001B8;
    }
    goto skip_1;
    // 0x808001A8: sh          $t2, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r10;
    skip_1:
    // 0x808001AC: b           L_808001B8
    // 0x808001B0: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
        goto L_808001B8;
    // 0x808001B0: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
    // 0x808001B4: sh          $t2, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r10;
L_808001B8:
    // 0x808001B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001BC:
    // 0x808001BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001C0: jr          $ra
    // 0x808001C4: nop

    return;
    // 0x808001C4: nop

;}
RECOMP_FUNC void func_808029A4_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808029A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808029A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808029AC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808029B0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808029B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808029B8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808029BC: jal         0x80100094
    // 0x808029C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808029C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808029C4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808029C8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808029CC: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
L_808029D0:
    // 0x808029D0: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    // 0x808029D4: beql        $a0, $zero, L_808029E8
    if (ctx->r4 == 0) {
        // 0x808029D8: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_808029E8;
    }
    goto skip_0;
    // 0x808029D8: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    skip_0:
    // 0x808029DC: jal         0x800857C0
    // 0x808029E0: nop

    _chblink_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808029E0: nop

    after_1:
    // 0x808029E4: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
L_808029E8:
    // 0x808029E8: bne         $s0, $s2, L_808029D0
    if (ctx->r16 != ctx->r18) {
        // 0x808029EC: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_808029D0;
    }
    // 0x808029EC: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x808029F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808029F4: jal         0x80100094
    // 0x808029F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x808029F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x808029FC: beq         $v0, $zero, L_80802A0C
    if (ctx->r2 == 0) {
        // 0x80802A00: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80802A0C;
    }
    // 0x80802A00: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80802A04: jal         0x800897C8
    // 0x80802A08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x80802A08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
L_80802A0C:
    // 0x80802A0C: jal         0x8080216C
    // 0x80802A10: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8080216C_chquiz(rdram, ctx);
        goto after_4;
    // 0x80802A10: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x80802A14: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80802A18: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802A1C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80802A20: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80802A24: jr          $ra
    // 0x80802A28: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80802A28: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _idflashbaddie_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088DE0: syscall     741
    recomp_syscall_handler(rdram, ctx, 0x80088DE0);
    return;
    // 0x80088DE4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
