#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800034_chjiggytemple(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800034: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800038: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080003C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800040: jal         0x8010C908
    // 0x80800044: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    func_8010C908(rdram, ctx);
        goto after_0;
    // 0x80800044: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80800048: jal         0x8080000C
    // 0x8080004C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8080000C_chjiggytemple(rdram, ctx);
        goto after_1;
    // 0x8080004C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800050: jal         0x800DB9B0
    // 0x80800054: nop

    func_800DB9B0(rdram, ctx);
        goto after_2;
    // 0x80800054: nop

    after_2:
    // 0x80800058: bnel        $v0, $zero, L_8080009C
    if (ctx->r2 != 0) {
        // 0x8080005C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080009C;
    }
    goto skip_0;
    // 0x8080005C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800060: jal         0x800D035C
    // 0x80800064: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800D035C(rdram, ctx);
        goto after_3;
    // 0x80800064: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80800068: addiu       $a0, $zero, 0x10E
    ctx->r4 = ADD32(0, 0X10E);
    // 0x8080006C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800070: jal         0x800D2498
    // 0x80800074: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D2498(rdram, ctx);
        goto after_4;
    // 0x80800074: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80800078: jal         0x8008A698
    // 0x8080007C: nop

    _sujiggy_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x8080007C: nop

    after_5:
    // 0x80800080: jal         0x8008A6A8
    // 0x80800084: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sujiggy_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80800084: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x80800088: addiu       $a0, $zero, 0x106
    ctx->r4 = ADD32(0, 0X106);
    // 0x8080008C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800090: jal         0x800D2498
    // 0x80800094: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D2498(rdram, ctx);
        goto after_7;
    // 0x80800094: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x80800098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080009C:
    // 0x8080009C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000A0: jr          $ra
    // 0x808000A4: nop

    return;
    // 0x808000A4: nop

;}
RECOMP_FUNC void func_80801334_bsbfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801334: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801338: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080133C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801340: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801344: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80801348: jal         0x8009BB24
    // 0x8080134C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_8009BB24(rdram, ctx);
        goto after_0;
    // 0x8080134C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x80801350: lw          $v0, 0x160($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X160);
    // 0x80801354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801358: beq         $v0, $zero, L_80801370
    if (ctx->r2 == 0) {
        // 0x8080135C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80801370;
    }
    // 0x8080135C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801360: beq         $v0, $at, L_8080139C
    if (ctx->r2 == ctx->r1) {
        // 0x80801364: nop
    
            goto L_8080139C;
    }
    // 0x80801364: nop

    // 0x80801368: b           L_8080139C
    // 0x8080136C: nop

        goto L_8080139C;
    // 0x8080136C: nop

L_80801370:
    // 0x80801370: jal         0x8008DF8C
    // 0x80801374: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    func_8008DF8C(rdram, ctx);
        goto after_1;
    // 0x80801374: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_1:
    // 0x80801378: beq         $v0, $zero, L_8080139C
    if (ctx->r2 == 0) {
        // 0x8080137C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080139C;
    }
    // 0x8080137C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801380: lui         $a3, 0x3F2A
    ctx->r7 = S32(0X3F2A << 16);
    // 0x80801384: ori         $a3, $a3, 0xACDA
    ctx->r7 = ctx->r7 | 0XACDA;
    // 0x80801388: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8080138C: jal         0x8008CD30
    // 0x80801390: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    baanim_playForDuration_onceSmoothStartingAt(rdram, ctx);
        goto after_2;
    // 0x80801390: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_2:
    // 0x80801394: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80801398: sw          $t6, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r14;
L_8080139C:
    // 0x8080139C: jal         0x800D8FF8
    // 0x808013A0: nop

    func_800D8FF8(rdram, ctx);
        goto after_3;
    // 0x808013A0: nop

    after_3:
    // 0x808013A4: lw          $v0, 0x188($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X188);
    // 0x808013A8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x808013AC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808013B0: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x808013B4: addiu       $t9, $zero, 0x24
    ctx->r25 = ADD32(0, 0X24);
    // 0x808013B8: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x808013BC: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x808013C0: lw          $t7, 0x188($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X188);
    // 0x808013C4: lwc1        $f8, 0x0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X0);
    // 0x808013C8: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x808013CC: nop

    // 0x808013D0: bc1f        L_808013E0
    if (!c1cs) {
        // 0x808013D4: nop
    
            goto L_808013E0;
    }
    // 0x808013D4: nop

    // 0x808013D8: sw          $t8, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r24;
    // 0x808013DC: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
L_808013E0:
    // 0x808013E0: jal         0x80097A90
    // 0x808013E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_beak_bust(rdram, ctx);
        goto after_4;
    // 0x808013E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808013E8: beq         $v0, $zero, L_808013F4
    if (ctx->r2 == 0) {
        // 0x808013EC: addiu       $t0, $zero, 0xF
        ctx->r8 = ADD32(0, 0XF);
            goto L_808013F4;
    }
    // 0x808013EC: addiu       $t0, $zero, 0xF
    ctx->r8 = ADD32(0, 0XF);
    // 0x808013F0: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
L_808013F4:
    // 0x808013F4: jal         0x8008E078
    // 0x808013F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_5;
    // 0x808013F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808013FC: beq         $v0, $zero, L_80801414
    if (ctx->r2 == 0) {
        // 0x80801400: nop
    
            goto L_80801414;
    }
    // 0x80801400: nop

    // 0x80801404: jal         0x8009FE58
    // 0x80801408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009FE58(rdram, ctx);
        goto after_6;
    // 0x80801408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080140C: addiu       $t1, $zero, 0x20
    ctx->r9 = ADD32(0, 0X20);
    // 0x80801410: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
L_80801414:
    // 0x80801414: jal         0x8008E35C
    // 0x80801418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_7;
    // 0x80801418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080141C: beq         $v0, $zero, L_8080142C
    if (ctx->r2 == 0) {
        // 0x80801420: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080142C;
    }
    // 0x80801420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801424: addiu       $t2, $zero, 0x2D
    ctx->r10 = ADD32(0, 0X2D);
    // 0x80801428: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
L_8080142C:
    // 0x8080142C: jal         0x8009E5C8
    // 0x80801430: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    bs_setState(rdram, ctx);
        goto after_8;
    // 0x80801430: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_8:
    // 0x80801434: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801438: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080143C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80801440: jr          $ra
    // 0x80801444: nop

    return;
    // 0x80801444: nop

;}
RECOMP_FUNC void chhoopswoop_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1016, 0X1F08) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x1F08
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1016, 0X1F08));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x1F08
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1016, 0X1F08));
;}
RECOMP_FUNC void func_800D3E40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3E40: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800D3E44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D3E48: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800D3E4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D3E50: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800D3E54: jal         0x800DA298
    // 0x800D3E58: lhu         $a0, -0x4A44($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X4A44);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x800D3E58: lhu         $a0, -0x4A44($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X4A44);
    after_0:
    // 0x800D3E5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D3E60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D3E64: jr          $ra
    // 0x800D3E68: nop

    return;
    // 0x800D3E68: nop

;}
RECOMP_FUNC void dbshift_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800080: jr          $ra
    // 0x80800084: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    return;
    // 0x80800084: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
;}
RECOMP_FUNC void func_800EEB9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EEB9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EEBA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EEBA4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800EEBA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800EEBAC: jal         0x800137F4
    // 0x800EEBB0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800137F4(rdram, ctx);
        goto after_0;
    // 0x800EEBB0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800EEBB4: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800EEBB8: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x800EEBBC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800EEBC0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800EEBC4: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x800EEBC8: jal         0x80013788
    // 0x800EEBCC: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    func_80013788(rdram, ctx);
        goto after_1;
    // 0x800EEBCC: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    after_1:
    // 0x800EEBD0: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800EEBD4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800EEBD8: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800EEBDC: swc1        $f16, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f16.u32l;
    // 0x800EEBE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EEBE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EEBE8: jr          $ra
    // 0x800EEBEC: nop

    return;
    // 0x800EEBEC: nop

;}
RECOMP_FUNC void _chmasterjiggy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085B08: syscall     196
    recomp_syscall_handler(rdram, ctx, 0x80085B08);
    return;
    // 0x80085B0C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800168_bsbpeck(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800168: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080016C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800170: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800174: lw          $v0, 0x160($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X160);
    // 0x80800178: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080017C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800180: beq         $v0, $zero, L_808001A4
    if (ctx->r2 == 0) {
        // 0x80800184: or          $s0, $a0, $zero
        ctx->r16 = ctx->r4 | 0;
            goto L_808001A4;
    }
    // 0x80800184: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800188: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080018C: beq         $v0, $at, L_808001B0
    if (ctx->r2 == ctx->r1) {
        // 0x80800190: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808001B0;
    }
    // 0x80800190: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800194: beq         $v0, $at, L_808001BC
    if (ctx->r2 == ctx->r1) {
        // 0x80800198: nop
    
            goto L_808001BC;
    }
    // 0x80800198: nop

    // 0x8080019C: b           L_808001C8
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808001C8;
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808001A4:
    // 0x808001A4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(108, 0X490) << 16);
    // 0x808001A8: b           L_808001C4
    // 0x808001AC: lwc1        $f0, 0x490($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(108, 0X490));
        goto L_808001C4;
    // 0x808001AC: lwc1        $f0, 0x490($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(108, 0X490));
L_808001B0:
    // 0x808001B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(108, 0X494) << 16);
    // 0x808001B4: b           L_808001C4
    // 0x808001B8: lwc1        $f0, 0x494($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(108, 0X494));
        goto L_808001C4;
    // 0x808001B8: lwc1        $f0, 0x494($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(108, 0X494));
L_808001BC:
    // 0x808001BC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(108, 0X498) << 16);
    // 0x808001C0: lwc1        $f0, 0x498($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(108, 0X498));
L_808001C4:
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808001C8:
    // 0x808001C8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808001CC: jal         0x80095760
    // 0x808001D0: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    baflag_set(rdram, ctx);
        goto after_0;
    // 0x808001D0: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x808001D4: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001DC: addiu       $a1, $zero, 0x442C
    ctx->r5 = ADD32(0, 0X442C);
    // 0x808001E0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808001E4: jal         0x8009DE38
    // 0x808001E8: nop

    func_8009DE38(rdram, ctx);
        goto after_1;
    // 0x808001E8: nop

    after_1:
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F0: jal         0x8009BA58
    // 0x808001F4: lui         $a1, 0x42F0
    ctx->r5 = S32(0X42F0 << 16);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_2;
    // 0x808001F4: lui         $a1, 0x42F0
    ctx->r5 = S32(0X42F0 << 16);
    after_2:
    // 0x808001F8: lw          $t6, 0x160($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X160);
    // 0x808001FC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80800200: sw          $t7, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r15;
    // 0x80800204: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800208: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080020C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800210: jr          $ra
    // 0x80800214: nop

    return;
    // 0x80800214: nop

;}
RECOMP_FUNC void func_80801170_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801170: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80801174: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801178: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080117C: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80801180: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80801184: jal         0x800D90A4
    // 0x80801188: addiu       $a0, $a1, 0x54
    ctx->r4 = ADD32(ctx->r5, 0X54);
    func_800D90A4(rdram, ctx);
        goto after_0;
    // 0x80801188: addiu       $a0, $a1, 0x54
    ctx->r4 = ADD32(ctx->r5, 0X54);
    after_0:
    // 0x8080118C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80801190: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80801194: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801198: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080119C: lwc1        $f14, 0x58($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808011A0: lwc1        $f12, 0x54($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X54);
    // 0x808011A4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808011A8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808011AC: jal         0x800F12D4
    // 0x808011B0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F12D4(rdram, ctx);
        goto after_1;
    // 0x808011B0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x808011B4: jal         0x800A89F8
    // 0x808011B8: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    func_800A89F8(rdram, ctx);
        goto after_2;
    // 0x808011B8: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x808011BC: jal         0x800A9478
    // 0x808011C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800A9478(rdram, ctx);
        goto after_3;
    // 0x808011C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x808011C4: jal         0x800F5EF8
    // 0x808011C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5EF8(rdram, ctx);
        goto after_4;
    // 0x808011C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x808011CC: jal         0x80110024
    // 0x808011D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110024(rdram, ctx);
        goto after_5;
    // 0x808011D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x808011D4: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x808011D8: lbu         $t6, 0x5C($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X5C);
    // 0x808011DC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808011E0: beql        $t6, $at, L_80801224
    if (ctx->r14 == ctx->r1) {
        // 0x808011E4: lbu         $t7, 0x5C($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X5C);
            goto L_80801224;
    }
    goto skip_0;
    // 0x808011E4: lbu         $t7, 0x5C($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X5C);
    skip_0:
    // 0x808011E8: jal         0x80089510
    // 0x808011EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _ncpod_entrypoint_10(rdram, ctx);
        goto after_6;
    // 0x808011EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x808011F0: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x808011F4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808011F8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808011FC: c.eq.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl == ctx->f14.fl;
    // 0x80801200: nop

    // 0x80801204: bc1tl       L_80801224
    if (c1cs) {
        // 0x80801208: lbu         $t7, 0x5C($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X5C);
            goto L_80801224;
    }
    goto skip_1;
    // 0x80801208: lbu         $t7, 0x5C($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X5C);
    skip_1:
    // 0x8080120C: jal         0x800F15F8
    // 0x80801210: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    func_800F15F8(rdram, ctx);
        goto after_7;
    // 0x80801210: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_7:
    // 0x80801214: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80801218: jal         0x80089508
    // 0x8080121C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    _ncpod_entrypoint_9(rdram, ctx);
        goto after_8;
    // 0x8080121C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_8:
    // 0x80801220: lbu         $t7, 0x5C($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X5C);
L_80801224:
    // 0x80801224: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x80801228: beq         $at, $zero, L_8080137C
    if (ctx->r1 == 0) {
        // 0x8080122C: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8080137C;
    }
    // 0x8080122C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80801230: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X6590) << 16);
    // 0x80801234: addu        $at, $at, $t7
    gpr jr_addend_8080123C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80801238: lw          $t7, 0x6590($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2484, 0X6590));
    // 0x8080123C: jr          $t7
    // 0x80801240: nop

    switch (jr_addend_8080123C >> 2) {
        case 0: goto L_80801244; break;
        case 1: goto L_80801280; break;
        case 2: goto L_808012D8; break;
        case 3: goto L_8080137C; break;
        case 4: goto L_8080137C; break;
        default: switch_error(__func__, 0x8080123C, 0x80806590);
    }
    // 0x80801240: nop

L_80801244:
    // 0x80801244: addiu       $a1, $s0, 0x1C
    ctx->r5 = ADD32(ctx->r16, 0X1C);
    // 0x80801248: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x8080124C: jal         0x800EE7F8
    // 0x80801250: addiu       $a0, $s0, 0x38
    ctx->r4 = ADD32(ctx->r16, 0X38);
    func_800EE7F8(rdram, ctx);
        goto after_9;
    // 0x80801250: addiu       $a0, $s0, 0x38
    ctx->r4 = ADD32(ctx->r16, 0X38);
    after_9:
    // 0x80801254: addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
    // 0x80801258: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8080125C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x80801260: jal         0x800EE7F8
    // 0x80801264: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    func_800EE7F8(rdram, ctx);
        goto after_10;
    // 0x80801264: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    after_10:
    // 0x80801268: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8080126C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80801270: jal         0x80089500
    // 0x80801274: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    _ncpod_entrypoint_8(rdram, ctx);
        goto after_11;
    // 0x80801274: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_11:
    // 0x80801278: b           L_80801380
    // 0x8080127C: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
        goto L_80801380;
    // 0x8080127C: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
L_80801280:
    // 0x80801280: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x80801284: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80801288: addiu       $a2, $s0, 0x1C
    ctx->r6 = ADD32(ctx->r16, 0X1C);
    // 0x8080128C: jal         0x800EFE50
    // 0x80801290: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    func_800EFE50(rdram, ctx);
        goto after_12;
    // 0x80801290: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    after_12:
    // 0x80801294: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80801298: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x8080129C: addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
    // 0x808012A0: jal         0x800F16AC
    // 0x808012A4: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    func_800F16AC(rdram, ctx);
        goto after_13;
    // 0x808012A4: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    after_13:
    // 0x808012A8: addiu       $a0, $s0, 0x38
    ctx->r4 = ADD32(ctx->r16, 0X38);
    // 0x808012AC: jal         0x800EE7F8
    // 0x808012B0: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    func_800EE7F8(rdram, ctx);
        goto after_14;
    // 0x808012B0: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    after_14:
    // 0x808012B4: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    // 0x808012B8: jal         0x800EE7F8
    // 0x808012BC: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    func_800EE7F8(rdram, ctx);
        goto after_15;
    // 0x808012BC: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_15:
    // 0x808012C0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808012C4: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x808012C8: jal         0x80089500
    // 0x808012CC: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    _ncpod_entrypoint_8(rdram, ctx);
        goto after_16;
    // 0x808012CC: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    after_16:
    // 0x808012D0: b           L_80801380
    // 0x808012D4: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
        goto L_80801380;
    // 0x808012D4: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
L_808012D8:
    // 0x808012D8: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x808012DC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808012E0: addiu       $a2, $s0, 0x1C
    ctx->r6 = ADD32(ctx->r16, 0X1C);
    // 0x808012E4: jal         0x800EFE50
    // 0x808012E8: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    func_800EFE50(rdram, ctx);
        goto after_17;
    // 0x808012E8: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    after_17:
    // 0x808012EC: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x808012F0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808012F4: jal         0x800EFB24
    // 0x808012F8: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    func_800EFB24(rdram, ctx);
        goto after_18;
    // 0x808012F8: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    after_18:
    // 0x808012FC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80801300: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801304: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80801308: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x8080130C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80801310: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80801314: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80801318: jal         0x800EF934
    // 0x8080131C: nop

    func_800EF934(rdram, ctx);
        goto after_19;
    // 0x8080131C: nop

    after_19:
    // 0x80801320: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x80801324: jal         0x800EF04C
    // 0x80801328: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    func_800EF04C(rdram, ctx);
        goto after_20;
    // 0x80801328: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_20:
    // 0x8080132C: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80801330: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80801334: jal         0x800F1214
    // 0x80801338: lw          $a2, 0x20($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X20);
    func_800F1214(rdram, ctx);
        goto after_21;
    // 0x80801338: lw          $a2, 0x20($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X20);
    after_21:
    // 0x8080133C: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x80801340: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80801344: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x80801348: addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
    // 0x8080134C: jal         0x800F16AC
    // 0x80801350: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    func_800F16AC(rdram, ctx);
        goto after_22;
    // 0x80801350: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    after_22:
    // 0x80801354: addiu       $a0, $s0, 0x38
    ctx->r4 = ADD32(ctx->r16, 0X38);
    // 0x80801358: jal         0x800EE7F8
    // 0x8080135C: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    func_800EE7F8(rdram, ctx);
        goto after_23;
    // 0x8080135C: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    after_23:
    // 0x80801360: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    // 0x80801364: jal         0x800EE7F8
    // 0x80801368: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    func_800EE7F8(rdram, ctx);
        goto after_24;
    // 0x80801368: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_24:
    // 0x8080136C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80801370: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x80801374: jal         0x80089500
    // 0x80801378: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    _ncpod_entrypoint_8(rdram, ctx);
        goto after_25;
    // 0x80801378: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    after_25:
L_8080137C:
    // 0x8080137C: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
L_80801380:
    // 0x80801380: beql        $t8, $zero, L_808013D0
    if (ctx->r24 == 0) {
        // 0x80801384: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808013D0;
    }
    goto skip_2;
    // 0x80801384: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80801388: lbu         $v0, 0x5C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X5C);
    // 0x8080138C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801390: beq         $v0, $at, L_808013CC
    if (ctx->r2 == ctx->r1) {
        // 0x80801394: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808013CC;
    }
    // 0x80801394: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801398: beq         $v0, $at, L_808013CC
    if (ctx->r2 == ctx->r1) {
        // 0x8080139C: addiu       $t9, $zero, 0x3
        ctx->r25 = ADD32(0, 0X3);
            goto L_808013CC;
    }
    // 0x8080139C: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x808013A0: sb          $t9, 0x5C($s0)
    MEM_B(0X5C, ctx->r16) = ctx->r25;
    // 0x808013A4: addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
    // 0x808013A8: addiu       $t0, $s0, 0xC
    ctx->r8 = ADD32(ctx->r16, 0XC);
    // 0x808013AC: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x808013B0: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x808013B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013B8: jal         0x800EE7F8
    // 0x808013BC: addiu       $a1, $s0, 0x1C
    ctx->r5 = ADD32(ctx->r16, 0X1C);
    func_800EE7F8(rdram, ctx);
        goto after_26;
    // 0x808013BC: addiu       $a1, $s0, 0x1C
    ctx->r5 = ADD32(ctx->r16, 0X1C);
    after_26:
    // 0x808013C0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808013C4: jal         0x800EE7F8
    // 0x808013C8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800EE7F8(rdram, ctx);
        goto after_27;
    // 0x808013C8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_27:
L_808013CC:
    // 0x808013CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808013D0:
    // 0x808013D0: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x808013D4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808013D8: jr          $ra
    // 0x808013DC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x808013DC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80800380_chflowerbaddie(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800380: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80800384: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800388: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080038C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800390: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800394: beq         $a1, $at, L_808005C8
    if (ctx->r5 == ctx->r1) {
        // 0x80800398: sw          $a2, 0x70($sp)
        MEM_W(0X70, ctx->r29) = ctx->r6;
            goto L_808005C8;
    }
    // 0x80800398: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x8080039C: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x808003A0: beq         $a1, $at, L_8080058C
    if (ctx->r5 == ctx->r1) {
        // 0x808003A4: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(1388, 0XBCC) << 16);
            goto L_8080058C;
    }
    // 0x808003A4: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1388, 0XBCC) << 16);
    // 0x808003A8: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x808003AC: beq         $a1, $at, L_808003E8
    if (ctx->r5 == ctx->r1) {
        // 0x808003B0: addiu       $at, $zero, 0x3F
        ctx->r1 = ADD32(0, 0X3F);
            goto L_808003E8;
    }
    // 0x808003B0: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x808003B4: beq         $a1, $at, L_808003F8
    if (ctx->r5 == ctx->r1) {
        // 0x808003B8: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_808003F8;
    }
    // 0x808003B8: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x808003BC: beq         $a1, $at, L_80800440
    if (ctx->r5 == ctx->r1) {
        // 0x808003C0: lw          $v0, 0x70($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X70);
            goto L_80800440;
    }
    // 0x808003C0: lw          $v0, 0x70($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X70);
    // 0x808003C4: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x808003C8: beq         $a1, $at, L_80800478
    if (ctx->r5 == ctx->r1) {
        // 0x808003CC: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_80800478;
    }
    // 0x808003CC: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808003D0: beq         $a1, $at, L_8080057C
    if (ctx->r5 == ctx->r1) {
        // 0x808003D4: addiu       $at, $zero, 0x97
        ctx->r1 = ADD32(0, 0X97);
            goto L_8080057C;
    }
    // 0x808003D4: addiu       $at, $zero, 0x97
    ctx->r1 = ADD32(0, 0X97);
    // 0x808003D8: beql        $a1, $at, L_808005A0
    if (ctx->r5 == ctx->r1) {
        // 0x808003DC: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_808005A0;
    }
    goto skip_0;
    // 0x808003DC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x808003E0: b           L_808005FC
    // 0x808003E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808005FC;
    // 0x808003E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808003E8:
    // 0x808003E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808003EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808003F0: b           L_808005F8
    // 0x808003F4: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_808005F8;
    // 0x808003F4: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_808003F8:
    // 0x808003F8: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x808003FC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800400: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800404: beql        $t7, $at, L_808005FC
    if (ctx->r15 == ctx->r1) {
        // 0x80800408: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808005FC;
    }
    goto skip_1;
    // 0x80800408: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x8080040C: lw          $t8, 0x78($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X78);
    // 0x80800410: sll         $t0, $t8, 29
    ctx->r8 = S32(ctx->r24 << 29);
    // 0x80800414: bltzl       $t0, L_808005FC
    if (SIGNED(ctx->r8) < 0) {
        // 0x80800418: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808005FC;
    }
    goto skip_2;
    // 0x80800418: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x8080041C: jal         0x80089D40
    // 0x80800420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800428: jal         0x80102424
    // 0x8080042C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x8080042C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_1:
    // 0x80800430: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800434: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800438: b           L_808005F8
    // 0x8080043C: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
        goto L_808005F8;
    // 0x8080043C: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_80800440:
    // 0x80800440: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800448: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8080044C: jal         0x80086678
    // 0x80800450: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    _chexploder_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80800450: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_2:
    // 0x80800454: jal         0x80089D40
    // 0x80800458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080045C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1388, 0XCC0) << 16);
    // 0x80800460: addiu       $a2, $a2, 0xCC0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1388, 0XCC0));
    // 0x80800464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800468: jal         0x80089D18
    // 0x8080046C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x8080046C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_4:
    // 0x80800470: b           L_808005FC
    // 0x80800474: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005FC;
    // 0x80800474: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800478:
    // 0x80800478: jal         0x80101080
    // 0x8080047C: nop

    func_80101080(rdram, ctx);
        goto after_5;
    // 0x8080047C: nop

    after_5:
    // 0x80800480: jal         0x80106790
    // 0x80800484: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_6;
    // 0x80800484: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x80800488: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080048C: addiu       $v1, $zero, 0x44
    ctx->r3 = ADD32(0, 0X44);
    // 0x80800490: addiu       $a3, $sp, 0xC8
    ctx->r7 = ADD32(ctx->r29, 0XC8);
L_80800494:
    // 0x80800494: sh          $v1, -0x88($a3)
    MEM_H(-0X88, ctx->r7) = ctx->r3;
    // 0x80800498: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8080049C: slti        $at, $v1, 0x53
    ctx->r1 = SIGNED(ctx->r3) < 0X53 ? 1 : 0;
    // 0x808004A0: bne         $at, $zero, L_80800494
    if (ctx->r1 != 0) {
        // 0x808004A4: addiu       $a3, $a3, 0x2
        ctx->r7 = ADD32(ctx->r7, 0X2);
            goto L_80800494;
    }
    // 0x808004A4: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x808004A8: addiu       $t1, $zero, 0x5B
    ctx->r9 = ADD32(0, 0X5B);
    // 0x808004AC: addiu       $t2, $zero, 0x5C
    ctx->r10 = ADD32(0, 0X5C);
    // 0x808004B0: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x808004B4: sh          $t1, -0x88($a3)
    MEM_H(-0X88, ctx->r7) = ctx->r9;
    // 0x808004B8: sh          $t2, -0x86($a3)
    MEM_H(-0X86, ctx->r7) = ctx->r10;
    // 0x808004BC: sh          $t3, -0x84($a3)
    MEM_H(-0X84, ctx->r7) = ctx->r11;
    // 0x808004C0: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x808004C4: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    // 0x808004C8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808004CC: jal         0x800866A0
    // 0x808004D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_7;
    // 0x808004D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x808004D4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808004D8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808004DC: jal         0x800866A0
    // 0x808004E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_8;
    // 0x808004E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x808004E4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808004E8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808004EC: jal         0x800866A0
    // 0x808004F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_9;
    // 0x808004F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x808004F4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808004F8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808004FC: jal         0x800866A0
    // 0x80800500: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_10;
    // 0x80800500: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_10:
    // 0x80800504: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800508: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8080050C: jal         0x800866A0
    // 0x80800510: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_11;
    // 0x80800510: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x80800514: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800518: jal         0x800866A8
    // 0x8080051C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    _chexploder_entrypoint_10(rdram, ctx);
        goto after_12;
    // 0x8080051C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_12:
    // 0x80800520: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800524: lui         $a1, 0x4416
    ctx->r5 = S32(0X4416 << 16);
    // 0x80800528: jal         0x80086688
    // 0x8080052C: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    _chexploder_entrypoint_6(rdram, ctx);
        goto after_13;
    // 0x8080052C: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    after_13:
    // 0x80800530: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800534: lui         $a1, 0xC448
    ctx->r5 = S32(0XC448 << 16);
    // 0x80800538: jal         0x80086690
    // 0x8080053C: lui         $a2, 0xC416
    ctx->r6 = S32(0XC416 << 16);
    _chexploder_entrypoint_7(rdram, ctx);
        goto after_14;
    // 0x8080053C: lui         $a2, 0xC416
    ctx->r6 = S32(0XC416 << 16);
    after_14:
    // 0x80800540: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800544: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    // 0x80800548: jal         0x80086698
    // 0x8080054C: lui         $a2, 0x4320
    ctx->r6 = S32(0X4320 << 16);
    _chexploder_entrypoint_8(rdram, ctx);
        goto after_15;
    // 0x8080054C: lui         $a2, 0x4320
    ctx->r6 = S32(0X4320 << 16);
    after_15:
    // 0x80800550: jal         0x808006A0
    // 0x80800554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808006A0_chflowerbaddie(rdram, ctx);
        goto after_16;
    // 0x80800554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080055C: jal         0x80107070
    // 0x80800560: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80107070(rdram, ctx);
        goto after_17;
    // 0x80800560: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_17:
    // 0x80800564: bnel        $v0, $zero, L_808005FC
    if (ctx->r2 != 0) {
        // 0x80800568: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808005FC;
    }
    goto skip_3;
    // 0x80800568: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_3:
    // 0x8080056C: jal         0x800FFAB0
    // 0x80800570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_18;
    // 0x80800570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800574: b           L_808005FC
    // 0x80800578: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005FC;
    // 0x80800578: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080057C:
    // 0x8080057C: jal         0x80089F60
    // 0x80800580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_1(rdram, ctx);
        goto after_19;
    // 0x80800580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800584: b           L_808005FC
    // 0x80800588: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005FC;
    // 0x80800588: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080058C:
    // 0x8080058C: jal         0x80101074
    // 0x80800590: addiu       $a0, $a0, 0xBCC
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1388, 0XBCC));
    func_80101074(rdram, ctx);
        goto after_20;
    // 0x80800590: addiu       $a0, $a0, 0xBCC
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1388, 0XBCC));
    after_20:
    // 0x80800594: b           L_808005FC
    // 0x80800598: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_808005FC;
    // 0x80800598: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x8080059C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_808005A0:
    // 0x808005A0: addiu       $s0, $sp, 0x2C
    ctx->r16 = ADD32(ctx->r29, 0X2C);
    // 0x808005A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005A8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808005AC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808005B0: jal         0x800EFA4C
    // 0x808005B4: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    func_800EFA4C(rdram, ctx);
        goto after_21;
    // 0x808005B4: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    after_21:
    // 0x808005B8: jal         0x80101010
    // 0x808005BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101010(rdram, ctx);
        goto after_22;
    // 0x808005BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x808005C0: b           L_808005FC
    // 0x808005C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005FC;
    // 0x808005C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005C8:
    // 0x808005C8: jal         0x8008A4A8
    // 0x808005CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieDll_entrypoint_3(rdram, ctx);
        goto after_23;
    // 0x808005CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x808005D0: bne         $v0, $zero, L_808005F8
    if (ctx->r2 != 0) {
        // 0x808005D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005F8;
    }
    // 0x808005D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005D8: jal         0x80107070
    // 0x808005DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80107070(rdram, ctx);
        goto after_24;
    // 0x808005DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_24:
    // 0x808005E0: lbu         $t4, 0x65($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X65);
    // 0x808005E4: andi        $t5, $t4, 0xFFEF
    ctx->r13 = ctx->r12 & 0XFFEF;
    // 0x808005E8: b           L_808005F8
    // 0x808005EC: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
        goto L_808005F8;
    // 0x808005EC: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
    // 0x808005F0: b           L_808005FC
    // 0x808005F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808005FC;
    // 0x808005F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005F8:
    // 0x808005F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005FC:
    // 0x808005FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800600: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800604: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80800608: jr          $ra
    // 0x8080060C: nop

    return;
    // 0x8080060C: nop

;}
RECOMP_FUNC void func_800A0180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A0180: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A0184: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A0188: jal         0x800846C0
    // 0x800A018C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _badata_entrypoint_16(rdram, ctx);
        goto after_0;
    // 0x800A018C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A0190: jal         0x800D395C
    // 0x800A0194: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800D395C(rdram, ctx);
        goto after_1;
    // 0x800A0194: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x800A0198: beq         $v0, $zero, L_800A01C0
    if (ctx->r2 == 0) {
        // 0x800A019C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_800A01C0;
    }
    // 0x800A019C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800A01A0: jal         0x800FCCD4
    // 0x800A01A4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800FCCD4(rdram, ctx);
        goto after_2;
    // 0x800A01A4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x800A01A8: bnel        $v0, $zero, L_800A01EC
    if (ctx->r2 != 0) {
        // 0x800A01AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A01EC;
    }
    goto skip_0;
    // 0x800A01AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800A01B0: jal         0x800A0150
    // 0x800A01B4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800A0150(rdram, ctx);
        goto after_3;
    // 0x800A01B4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x800A01B8: b           L_800A01EC
    // 0x800A01BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A01EC;
    // 0x800A01BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A01C0:
    // 0x800A01C0: jal         0x80095738
    // 0x800A01C4: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    baflag_isTrue(rdram, ctx);
        goto after_4;
    // 0x800A01C4: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    after_4:
    // 0x800A01C8: bne         $v0, $zero, L_800A01E8
    if (ctx->r2 != 0) {
        // 0x800A01CC: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_800A01E8;
    }
    // 0x800A01CC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800A01D0: jal         0x80095760
    // 0x800A01D4: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    baflag_set(rdram, ctx);
        goto after_5;
    // 0x800A01D4: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    after_5:
    // 0x800A01D8: jal         0x800A0150
    // 0x800A01DC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800A0150(rdram, ctx);
        goto after_6;
    // 0x800A01DC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_6:
    // 0x800A01E0: jal         0x800FE4E4
    // 0x800A01E4: nop

    func_800FE4E4(rdram, ctx);
        goto after_7;
    // 0x800A01E4: nop

    after_7:
L_800A01E8:
    // 0x800A01E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A01EC:
    // 0x800A01EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A01F0: jr          $ra
    // 0x800A01F4: nop

    return;
    // 0x800A01F4: nop

;}
RECOMP_FUNC void func_80800000_chskeletonexplode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: jal         0x80100094
    // 0x80800010: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800010: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800014: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800018: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8080001C: swc1        $f0, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f0.u32l;
    // 0x80800020: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80800024: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800028: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080002C: jr          $ra
    // 0x80800030: nop

    return;
    // 0x80800030: nop

;}
RECOMP_FUNC void func_800E8B3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8B3C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E8B40: lw          $a0, -0x2980($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2980);
    // 0x800E8B44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E8B48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E8B4C: beql        $a0, $zero, L_800E8B68
    if (ctx->r4 == 0) {
        // 0x800E8B50: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800E8B68;
    }
    goto skip_0;
    // 0x800E8B50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800E8B54: jal         0x800B32E4
    // 0x800E8B58: nop

    freelist_defrag(rdram, ctx);
        goto after_0;
    // 0x800E8B58: nop

    after_0:
    // 0x800E8B5C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E8B60: sw          $v0, -0x2980($at)
    MEM_W(-0X2980, ctx->r1) = ctx->r2;
    // 0x800E8B64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E8B68:
    // 0x800E8B68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E8B6C: jr          $ra
    // 0x800E8B70: nop

    return;
    // 0x800E8B70: nop

;}
RECOMP_FUNC void func_800DFC20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DFC20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DFC24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DFC28: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800DFC2C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800DFC30: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x800DFC34: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x800DFC38: addu        $t8, $t8, $a1
    ctx->r24 = ADD32(ctx->r24, ctx->r5);
    // 0x800DFC3C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800DFC40: addu        $a1, $t6, $t8
    ctx->r5 = ADD32(ctx->r14, ctx->r24);
    // 0x800DFC44: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    // 0x800DFC48: jal         0x800EE7F8
    // 0x800DFC4C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800DFC4C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x800DFC50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DFC54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DFC58: jr          $ra
    // 0x800DFC5C: nop

    return;
    // 0x800DFC5C: nop

;}
RECOMP_FUNC void func_800EA05C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA05C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800EA060: jr          $ra
    // 0x800EA064: lhu         $v0, 0x2DC2($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X2DC2);
    return;
    // 0x800EA064: lhu         $v0, 0x2DC2($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X2DC2);
;}
RECOMP_FUNC void func_80800D24_chclinker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800D30: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800D34: jal         0x800C064C
    // 0x80800D38: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800C064C(rdram, ctx);
        goto after_0;
    // 0x80800D38: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800D3C: slti        $at, $v0, 0xCED
    ctx->r1 = SIGNED(ctx->r2) < 0XCED ? 1 : 0;
    // 0x80800D40: bne         $at, $zero, L_80800D68
    if (ctx->r1 != 0) {
        // 0x80800D44: addiu       $t6, $v0, -0x1371
        ctx->r14 = ADD32(ctx->r2, -0X1371);
            goto L_80800D68;
    }
    // 0x80800D44: addiu       $t6, $v0, -0x1371
    ctx->r14 = ADD32(ctx->r2, -0X1371);
    // 0x80800D48: sltiu       $at, $t6, 0xF
    ctx->r1 = ctx->r14 < 0XF ? 1 : 0;
    // 0x80800D4C: beq         $at, $zero, L_80800E0C
    if (ctx->r1 == 0) {
        // 0x80800D50: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800E0C;
    }
    // 0x80800D50: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800D54: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2208, 0X1320) << 16);
    // 0x80800D58: addu        $at, $at, $t6
    gpr jr_addend_80800D60 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800D5C: lw          $t6, 0x1320($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2208, 0X1320));
    // 0x80800D60: jr          $t6
    // 0x80800D64: nop

    switch (jr_addend_80800D60 >> 2) {
        case 0: goto L_80800E0C; break;
        case 1: goto L_80800D88; break;
        case 2: goto L_80800E0C; break;
        case 3: goto L_80800E0C; break;
        case 4: goto L_80800E0C; break;
        case 5: goto L_80800E0C; break;
        case 6: goto L_80800E0C; break;
        case 7: goto L_80800E0C; break;
        case 8: goto L_80800E0C; break;
        case 9: goto L_80800E0C; break;
        case 10: goto L_80800E0C; break;
        case 11: goto L_80800D9C; break;
        case 12: goto L_80800DD8; break;
        case 13: goto L_80800DD8; break;
        case 14: goto L_80800DD8; break;
        default: switch_error(__func__, 0x80800D60, 0x80801320);
    }
    // 0x80800D64: nop

L_80800D68:
    // 0x80800D68: addiu       $at, $zero, 0xCEB
    ctx->r1 = ADD32(0, 0XCEB);
    // 0x80800D6C: beq         $v0, $at, L_80800DEC
    if (ctx->r2 == ctx->r1) {
        // 0x80800D70: lw          $t7, 0x20($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X20);
            goto L_80800DEC;
    }
    // 0x80800D70: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80800D74: addiu       $at, $zero, 0xCEC
    ctx->r1 = ADD32(0, 0XCEC);
    // 0x80800D78: beq         $v0, $at, L_80800DB0
    if (ctx->r2 == ctx->r1) {
        // 0x80800D7C: nop
    
            goto L_80800DB0;
    }
    // 0x80800D7C: nop

    // 0x80800D80: b           L_80800E10
    // 0x80800D84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800E10;
    // 0x80800D84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800D88:
    // 0x80800D88: addiu       $a0, $zero, 0x187
    ctx->r4 = ADD32(0, 0X187);
    // 0x80800D8C: jal         0x800887D8
    // 0x80800D90: addiu       $a1, $zero, 0x87
    ctx->r5 = ADD32(0, 0X87);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800D90: addiu       $a1, $zero, 0x87
    ctx->r5 = ADD32(0, 0X87);
    after_1:
    // 0x80800D94: b           L_80800E10
    // 0x80800D98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800E10;
    // 0x80800D98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800D9C:
    // 0x80800D9C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800DA0: jal         0x80800BDC
    // 0x80800DA4: addiu       $a1, $zero, 0xCEC
    ctx->r5 = ADD32(0, 0XCEC);
    func_80800BDC_chclinker(rdram, ctx);
        goto after_2;
    // 0x80800DA4: addiu       $a1, $zero, 0xCEC
    ctx->r5 = ADD32(0, 0XCEC);
    after_2:
    // 0x80800DA8: b           L_80800E10
    // 0x80800DAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800E10;
    // 0x80800DAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800DB0:
    // 0x80800DB0: jal         0x800F54E4
    // 0x80800DB4: nop

    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x80800DB4: nop

    after_3:
    // 0x80800DB8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800DBC: jal         0x800F7F98
    // 0x80800DC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F7F98(rdram, ctx);
        goto after_4;
    // 0x80800DC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800DC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800DC8: jal         0x808008E0
    // 0x80800DCC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_808008E0_chclinker(rdram, ctx);
        goto after_5;
    // 0x80800DCC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_5:
    // 0x80800DD0: b           L_80800E10
    // 0x80800DD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800E10;
    // 0x80800DD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800DD8:
    // 0x80800DD8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800DDC: jal         0x808008E0
    // 0x80800DE0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_808008E0_chclinker(rdram, ctx);
        goto after_6;
    // 0x80800DE0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_6:
    // 0x80800DE4: b           L_80800E10
    // 0x80800DE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800E10;
    // 0x80800DE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800DEC:
    // 0x80800DEC: blez        $t7, L_80800E04
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80800DF0: nop
    
            goto L_80800E04;
    }
    // 0x80800DF0: nop

    // 0x80800DF4: jal         0x80088188
    // 0x80800DF8: nop

    _gcfrontend_entrypoint_11(rdram, ctx);
        goto after_7;
    // 0x80800DF8: nop

    after_7:
    // 0x80800DFC: b           L_80800E10
    // 0x80800E00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800E10;
    // 0x80800E00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800E04:
    // 0x80800E04: jal         0x80088180
    // 0x80800E08: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_8;
    // 0x80800E08: nop

    after_8:
L_80800E0C:
    // 0x80800E0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800E10:
    // 0x80800E10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800E14: jr          $ra
    // 0x80800E18: nop

    return;
    // 0x80800E18: nop

;}
RECOMP_FUNC void func_80800478_chblackeye(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800478: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8080047C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80800480: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800484: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800488: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8080048C: jal         0x800B53A4
    // 0x80800490: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800B53A4(rdram, ctx);
        goto after_0;
    // 0x80800490: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x80800494: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x80800498: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080049C: lwc1        $f0, 0x38($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X38);
    // 0x808004A0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808004A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808004A8: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808004AC: addiu       $t3, $zero, -0xF
    ctx->r11 = ADD32(0, -0XF);
    // 0x808004B0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808004B4: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x808004B8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x808004BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808004C0: addiu       $a2, $zero, -0xA
    ctx->r6 = ADD32(0, -0XA);
    // 0x808004C4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x808004C8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x808004CC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x808004D0: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x808004D4: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x808004D8: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    // 0x808004DC: sll         $a3, $a1, 16
    ctx->r7 = S32(ctx->r5 << 16);
    // 0x808004E0: sll         $t1, $v1, 16
    ctx->r9 = S32(ctx->r3 << 16);
    // 0x808004E4: sra         $v1, $t1, 16
    ctx->r3 = S32(SIGNED(ctx->r9) >> 16);
    // 0x808004E8: sra         $t9, $a3, 16
    ctx->r25 = S32(SIGNED(ctx->r7) >> 16);
    // 0x808004EC: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x808004F0: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x808004F4: jal         0x800BA6B0
    // 0x808004F8: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_800BA6B0(rdram, ctx);
        goto after_1;
    // 0x808004F8: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_1:
    // 0x808004FC: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x80800500: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800504: lwc1        $f4, 0x38($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X38);
    // 0x80800508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080050C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800510: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800514: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800518: nop

    // 0x8080051C: sll         $t5, $a1, 16
    ctx->r13 = S32(ctx->r5 << 16);
    // 0x80800520: jal         0x800BA4D0
    // 0x80800524: sra         $a1, $t5, 16
    ctx->r5 = S32(SIGNED(ctx->r13) >> 16);
    func_800BA4D0(rdram, ctx);
        goto after_2;
    // 0x80800524: sra         $a1, $t5, 16
    ctx->r5 = S32(SIGNED(ctx->r13) >> 16);
    after_2:
    // 0x80800528: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1796, 0XDC0) << 16);
    // 0x8080052C: lwc1        $f16, 0xDC0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1796, 0XDC0));
    // 0x80800530: lwc1        $f0, 0x38($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X38);
    // 0x80800534: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1796, 0XDC4) << 16);
    // 0x80800538: lwc1        $f4, 0xDC4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1796, 0XDC4));
    // 0x8080053C: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800544: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800548: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8080054C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80800550: jal         0x800BA7C4
    // 0x80800554: nop

    func_800BA7C4(rdram, ctx);
        goto after_3;
    // 0x80800554: nop

    after_3:
    // 0x80800558: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1796, 0XDC8) << 16);
    // 0x8080055C: lwc1        $f10, 0xDC8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1796, 0XDC8));
    // 0x80800560: lwc1        $f8, 0x38($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X38);
    // 0x80800564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800568: mul.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8080056C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800570: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800574: jal         0x800BA7FC
    // 0x80800578: nop

    func_800BA7FC(rdram, ctx);
        goto after_4;
    // 0x80800578: nop

    after_4:
    // 0x8080057C: lui         $at, 0x431B
    ctx->r1 = S32(0X431B << 16);
    // 0x80800580: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800584: lwc1        $f0, 0x48($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X48);
    // 0x80800588: lui         $at, 0x434D
    ctx->r1 = S32(0X434D << 16);
    // 0x8080058C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800590: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80800594: addiu       $t0, $zero, 0x2D
    ctx->r8 = ADD32(0, 0X2D);
    // 0x80800598: addiu       $t3, $zero, 0x4B
    ctx->r11 = ADD32(0, 0X4B);
    // 0x8080059C: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x808005A0: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x808005A4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x808005A8: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x808005AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005B0: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    // 0x808005B4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808005B8: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x808005BC: addiu       $a3, $zero, 0x19
    ctx->r7 = ADD32(0, 0X19);
    // 0x808005C0: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x808005C4: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x808005C8: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    // 0x808005CC: jal         0x800BA994
    // 0x808005D0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    func_800BA994(rdram, ctx);
        goto after_5;
    // 0x808005D0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_5:
    // 0x808005D4: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x808005D8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808005DC: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x808005E0: jal         0x800DBEFC
    // 0x808005E4: lw          $a0, 0x4($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X4);
    func_800DBEFC(rdram, ctx);
        goto after_6;
    // 0x808005E4: lw          $a0, 0x4($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X4);
    after_6:
    // 0x808005E8: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(1796, 0XEB8) << 16);
    // 0x808005EC: addiu       $t5, $t5, 0xEB8
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(1796, 0XEB8));
    // 0x808005F0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x808005F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005F8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x808005FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800600: jal         0x800BABB8
    // 0x80800604: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_7;
    // 0x80800604: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_7:
    // 0x80800608: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8080060C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80800610: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80800614: jr          $ra
    // 0x80800618: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80800618: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void bsstonehead_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A44: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800A48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800A50: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800A54: jal         0x808000CC
    // 0x80800A58: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    func_808000CC_bsstonehead(rdram, ctx);
        goto after_0;
    // 0x80800A58: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80800A5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A60: jal         0x8009D3A8
    // 0x80800A64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_1;
    // 0x80800A64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800A68: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    // 0x80800A6C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A74: beq         $v0, $at, L_80800A94
    if (ctx->r2 == ctx->r1) {
        // 0x80800A78: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800A94;
    }
    // 0x80800A78: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800A7C: beq         $v0, $at, L_80800AB4
    if (ctx->r2 == ctx->r1) {
        // 0x80800A80: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800AB4;
    }
    // 0x80800A80: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800A84: beq         $v0, $at, L_80800AD4
    if (ctx->r2 == ctx->r1) {
        // 0x80800A88: nop
    
            goto L_80800AD4;
    }
    // 0x80800A88: nop

    // 0x80800A8C: b           L_80800AE8
    // 0x80800A90: nop

        goto L_80800AE8;
    // 0x80800A90: nop

L_80800A94:
    // 0x80800A94: jal         0x8008DF8C
    // 0x80800A98: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008DF8C(rdram, ctx);
        goto after_2;
    // 0x80800A98: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_2:
    // 0x80800A9C: beq         $v0, $zero, L_80800AE8
    if (ctx->r2 == 0) {
        // 0x80800AA0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800AE8;
    }
    // 0x80800AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AA4: jal         0x808008CC
    // 0x80800AA8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808008CC_bsstonehead(rdram, ctx);
        goto after_3;
    // 0x80800AA8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80800AAC: b           L_80800AE8
    // 0x80800AB0: nop

        goto L_80800AE8;
    // 0x80800AB0: nop

L_80800AB4:
    // 0x80800AB4: jal         0x8008E078
    // 0x80800AB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_4;
    // 0x80800AB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800ABC: beq         $v0, $zero, L_80800AE8
    if (ctx->r2 == 0) {
        // 0x80800AC0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800AE8;
    }
    // 0x80800AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AC4: jal         0x808008CC
    // 0x80800AC8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808008CC_bsstonehead(rdram, ctx);
        goto after_5;
    // 0x80800AC8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x80800ACC: b           L_80800AE8
    // 0x80800AD0: nop

        goto L_80800AE8;
    // 0x80800AD0: nop

L_80800AD4:
    // 0x80800AD4: jal         0x8008CAEC
    // 0x80800AD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_6;
    // 0x80800AD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800ADC: beq         $v0, $zero, L_80800AE8
    if (ctx->r2 == 0) {
        // 0x80800AE0: addiu       $t6, $zero, 0xB3
        ctx->r14 = ADD32(0, 0XB3);
            goto L_80800AE8;
    }
    // 0x80800AE0: addiu       $t6, $zero, 0xB3
    ctx->r14 = ADD32(0, 0XB3);
    // 0x80800AE4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800AE8:
    // 0x80800AE8: jal         0x8008E078
    // 0x80800AEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_7;
    // 0x80800AEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800AF0: beq         $v0, $zero, L_80800B04
    if (ctx->r2 == 0) {
        // 0x80800AF4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B04;
    }
    // 0x80800AF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AF8: jal         0x808003F4
    // 0x80800AFC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_808003F4_bsstonehead(rdram, ctx);
        goto after_8;
    // 0x80800AFC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_8:
    // 0x80800B00: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_80800B04:
    // 0x80800B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B08: jal         0x8009E5C8
    // 0x80800B0C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_9;
    // 0x80800B0C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_9:
    // 0x80800B10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B14: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800B18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800B1C: jr          $ra
    // 0x80800B20: nop

    return;
    // 0x80800B20: nop

;}
RECOMP_FUNC void _fxdialog_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088B50: syscall     725
    recomp_syscall_handler(rdram, ctx, 0x80088B50);
    return;
    // 0x80088B54: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_808009C0_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808009C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009C8: jal         0x808004CC
    // 0x808009CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bstrexsmall_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808009CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808009D0: jal         0x80082FE0
    // 0x808009D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808009D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808009D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808009DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808009E0: jr          $ra
    // 0x808009E4: nop

    return;
    // 0x808009E4: nop

;}
RECOMP_FUNC void func_80800408_chdinofoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800408: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080040C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800410: jal         0x8010D248
    // 0x80800414: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_8010D248(rdram, ctx);
        goto after_0;
    // 0x80800414: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800418: bne         $v0, $zero, L_80800428
    if (ctx->r2 != 0) {
        // 0x8080041C: nop
    
            goto L_80800428;
    }
    // 0x8080041C: nop

    // 0x80800420: b           L_80800470
    // 0x80800424: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800470;
    // 0x80800424: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800428:
    // 0x80800428: jal         0x8010D254
    // 0x8080042C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_8010D254(rdram, ctx);
        goto after_1;
    // 0x8080042C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x80800430: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1040, 0X7C8) << 16);
    // 0x80800434: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800438: lwc1        $f4, 0x7C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1040, 0X7C8));
    // 0x8080043C: lui         $at, 0xC57A
    ctx->r1 = S32(0XC57A << 16);
    // 0x80800440: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800444: nop

    // 0x80800448: bc1t        L_80800468
    if (c1cs) {
        // 0x8080044C: nop
    
            goto L_80800468;
    }
    // 0x8080044C: nop

    // 0x80800450: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800454: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800458: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8080045C: nop

    // 0x80800460: bc1f        L_80800470
    if (!c1cs) {
        // 0x80800464: nop
    
            goto L_80800470;
    }
    // 0x80800464: nop

L_80800468:
    // 0x80800468: b           L_80800470
    // 0x8080046C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800470;
    // 0x8080046C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800470:
    // 0x80800470: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800474: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800478: jr          $ra
    // 0x8080047C: nop

    return;
    // 0x8080047C: nop

;}
RECOMP_FUNC void baeggsetup_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800788: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080078C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800790: jal         0x8009C128
    // 0x80800794: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x80800794: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80800798: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080079C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808007A0: jal         0x800C4B64
    // 0x808007A4: nop

    func_800C4B64(rdram, ctx);
        goto after_1;
    // 0x808007A4: nop

    after_1:
    // 0x808007A8: jal         0x800C4B70
    // 0x808007AC: addiu       $a0, $zero, 0x7FFF
    ctx->r4 = ADD32(0, 0X7FFF);
    func_800C4B70(rdram, ctx);
        goto after_2;
    // 0x808007AC: addiu       $a0, $zero, 0x7FFF
    ctx->r4 = ADD32(0, 0X7FFF);
    after_2:
    // 0x808007B0: jal         0x800C4B7C
    // 0x808007B4: addiu       $a0, $zero, 0x4A5
    ctx->r4 = ADD32(0, 0X4A5);
    func_800C4B7C(rdram, ctx);
        goto after_3;
    // 0x808007B4: addiu       $a0, $zero, 0x4A5
    ctx->r4 = ADD32(0, 0X4A5);
    after_3:
    // 0x808007B8: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(504, 0X860) << 16);
    // 0x808007BC: addiu       $a3, $a3, 0x860
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(504, 0X860));
    // 0x808007C0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x808007C4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x808007C8: jal         0x8010D930
    // 0x808007CC: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    func_8010D930(rdram, ctx);
        goto after_4;
    // 0x808007CC: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_4:
    // 0x808007D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808007D8: jr          $ra
    // 0x808007DC: nop

    return;
    // 0x808007DC: nop

;}
RECOMP_FUNC void func_80800700_chboilerid(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800700: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800704: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800708: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8080070C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800710: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800714: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800718: jal         0x800EE88C
    // 0x8080071C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_800EE88C(rdram, ctx);
        goto after_0;
    // 0x8080071C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80800720: jal         0x800EEF94
    // 0x80800724: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_800EEF94(rdram, ctx);
        goto after_1;
    // 0x80800724: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x80800728: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080072C: lui         $a2, 0x3F19
    ctx->r6 = S32(0X3F19 << 16);
    // 0x80800730: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800734: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800738: jal         0x80088FC0
    // 0x8080073C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    _mlwave_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x8080073C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x80800740: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80800744: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80800748: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1084, 0XCF0) << 16);
    // 0x8080074C: lwc1        $f6, 0xCF0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1084, 0XCF0));
    // 0x80800750: lwc1        $f4, 0x1C($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x80800754: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800758: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1084, 0XDFC) << 16);
    // 0x8080075C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800760: addiu       $a2, $a2, 0xDFC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1084, 0XDFC));
    // 0x80800764: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80800768: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    // 0x8080076C: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80800770: jal         0x800F3320
    // 0x80800774: nop

    func_800F3320(rdram, ctx);
        goto after_3;
    // 0x80800774: nop

    after_3:
    // 0x80800778: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8080077C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80800780: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80800784: jal         0x800F2FD0
    // 0x80800788: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800F2FD0(rdram, ctx);
        goto after_4;
    // 0x80800788: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_4:
    // 0x8080078C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800790: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800794: jr          $ra
    // 0x80800798: nop

    return;
    // 0x80800798: nop

;}
RECOMP_FUNC void func_8080044C_chfreezy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080044C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800450: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800454: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800458: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080045C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80800460: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800464: addiu       $at, $zero, 0x2F6
    ctx->r1 = ADD32(0, 0X2F6);
    // 0x80800468: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x8080046C: addiu       $a0, $a0, 0x44
    ctx->r4 = ADD32(ctx->r4, 0X44);
    // 0x80800470: addiu       $a1, $a1, 0x44
    ctx->r5 = ADD32(ctx->r5, 0X44);
    // 0x80800474: srl         $t8, $t7, 22
    ctx->r24 = S32(U32(ctx->r15) >> 22);
    // 0x80800478: bnel        $t8, $at, L_808004AC
    if (ctx->r24 != ctx->r1) {
        // 0x8080047C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808004AC;
    }
    goto skip_0;
    // 0x8080047C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800480: jal         0x800EE7F8
    // 0x80800484: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800484: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800488: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8080048C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800490: jal         0x80103DFC
    // 0x80800494: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_80103DFC(rdram, ctx);
        goto after_1;
    // 0x80800494: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_1:
    // 0x80800498: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080049C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808004A0: jal         0x808004B8
    // 0x808004A4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    func_808004B8_chfreezy(rdram, ctx);
        goto after_2;
    // 0x808004A4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808004A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808004AC:
    // 0x808004AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004B0: jr          $ra
    // 0x808004B4: nop

    return;
    // 0x808004B4: nop

;}
RECOMP_FUNC void func_808010CC_chtiptup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808010D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808010D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808010D8: jal         0x80089F48
    // 0x808010DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _subaddiesect_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808010DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808010E0: lhu         $t8, 0x6E($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X6E);
    // 0x808010E4: andi        $t7, $v0, 0x1FF
    ctx->r15 = ctx->r2 & 0X1FF;
    // 0x808010E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010EC: andi        $t9, $t8, 0xFE00
    ctx->r25 = ctx->r24 & 0XFE00;
    // 0x808010F0: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x808010F4: sh          $t0, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r8;
    // 0x808010F8: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x808010FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801100: andi        $t1, $a1, 0x1FF
    ctx->r9 = ctx->r5 & 0X1FF;
    // 0x80801104: jal         0x80089F50
    // 0x80801108: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    _subaddiesect_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80801108: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    after_1:
    // 0x8080110C: jal         0x80088848
    // 0x80801110: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_2;
    // 0x80801110: nop

    after_2:
    // 0x80801114: beq         $v0, $zero, L_8080112C
    if (ctx->r2 == 0) {
        // 0x80801118: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080112C;
    }
    // 0x80801118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080111C: jal         0x80102424
    // 0x80801120: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x80801120: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
    // 0x80801124: b           L_80801170
    // 0x80801128: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801170;
    // 0x80801128: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080112C:
    // 0x8080112C: jal         0x800DA298
    // 0x80801130: addiu       $a0, $zero, 0xBD
    ctx->r4 = ADD32(0, 0XBD);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80801130: addiu       $a0, $zero, 0xBD
    ctx->r4 = ADD32(0, 0XBD);
    after_4:
    // 0x80801134: beq         $v0, $zero, L_80801158
    if (ctx->r2 == 0) {
        // 0x80801138: nop
    
            goto L_80801158;
    }
    // 0x80801138: nop

    // 0x8080113C: jal         0x8010A570
    // 0x80801140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_5;
    // 0x80801140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80801144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801148: jal         0x80102424
    // 0x8080114C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x8080114C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x80801150: b           L_80801170
    // 0x80801154: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801170;
    // 0x80801154: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801158:
    // 0x80801158: jal         0x8010A63C
    // 0x8080115C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A63C(rdram, ctx);
        goto after_7;
    // 0x8080115C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80801160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801164: jal         0x80102424
    // 0x80801168: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_8;
    // 0x80801168: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x8080116C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801170:
    // 0x80801170: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801174: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801178: jr          $ra
    // 0x8080117C: nop

    return;
    // 0x8080117C: nop

;}
RECOMP_FUNC void func_80800134_chtemplelobbydoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800134: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800138: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080013C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800140: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800144: jal         0x80100094
    // 0x80800148: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800148: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080014C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800150: jal         0x800EA090
    // 0x80800154: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    func_800EA090(rdram, ctx);
        goto after_1;
    // 0x80800154: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    after_1:
    // 0x80800158: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080015C: beq         $v0, $at, L_80800174
    if (ctx->r2 == ctx->r1) {
        // 0x80800160: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800174;
    }
    // 0x80800160: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800164: beq         $v0, $at, L_808001EC
    if (ctx->r2 == ctx->r1) {
        // 0x80800168: nop
    
            goto L_808001EC;
    }
    // 0x80800168: nop

    // 0x8080016C: b           L_8080023C
    // 0x80800170: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080023C;
    // 0x80800170: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800174:
    // 0x80800174: jal         0x800C6E38
    // 0x80800178: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    func_800C6E38(rdram, ctx);
        goto after_2;
    // 0x80800178: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_2:
    // 0x8080017C: beql        $v0, $zero, L_8080023C
    if (ctx->r2 == 0) {
        // 0x80800180: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080023C;
    }
    goto skip_0;
    // 0x80800180: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800184: jal         0x8009E958
    // 0x80800188: nop

    func_8009E958(rdram, ctx);
        goto after_3;
    // 0x80800188: nop

    after_3:
    // 0x8080018C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800190: bne         $v0, $at, L_80800238
    if (ctx->r2 != ctx->r1) {
        // 0x80800194: addiu       $a0, $zero, 0x6B8
        ctx->r4 = ADD32(0, 0X6B8);
            goto L_80800238;
    }
    // 0x80800194: addiu       $a0, $zero, 0x6B8
    ctx->r4 = ADD32(0, 0X6B8);
    // 0x80800198: jal         0x800DA9E4
    // 0x8080019C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_4;
    // 0x8080019C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x808001A0: bne         $v0, $zero, L_80800238
    if (ctx->r2 != 0) {
        // 0x808001A4: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80800238;
    }
    // 0x808001A4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808001A8: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x808001AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808001B0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x808001B4: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x808001B8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x808001BC: addiu       $a3, $zero, 0x2020
    ctx->r7 = ADD32(0, 0X2020);
    // 0x808001C0: jal         0x80085708
    // 0x808001C4: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_5;
    // 0x808001C4: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_5:
    // 0x808001C8: jal         0x800F54E4
    // 0x808001CC: nop

    func_800F54E4(rdram, ctx);
        goto after_6;
    // 0x808001CC: nop

    after_6:
    // 0x808001D0: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x808001D4: addiu       $a1, $a1, 0x4318
    ctx->r5 = ADD32(ctx->r5, 0X4318);
    // 0x808001D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001DC: jal         0x800F49D4
    // 0x808001E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800F49D4(rdram, ctx);
        goto after_7;
    // 0x808001E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x808001E4: b           L_8080023C
    // 0x808001E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080023C;
    // 0x808001E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001EC:
    // 0x808001EC: jal         0x800DA298
    // 0x808001F0: addiu       $a0, $zero, 0x36F
    ctx->r4 = ADD32(0, 0X36F);
    func_800DA298(rdram, ctx);
        goto after_8;
    // 0x808001F0: addiu       $a0, $zero, 0x36F
    ctx->r4 = ADD32(0, 0X36F);
    after_8:
    // 0x808001F4: bne         $v0, $zero, L_80800238
    if (ctx->r2 != 0) {
        // 0x808001F8: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2192, 0X390) << 16);
            goto L_80800238;
    }
    // 0x808001F8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2192, 0X390) << 16);
    // 0x808001FC: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80800200: addiu       $t0, $zero, 0xB2
    ctx->r8 = ADD32(0, 0XB2);
    // 0x80800204: lwc1        $f12, 0x390($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2192, 0X390));
    // 0x80800208: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    // 0x8080020C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80800210: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800214: addiu       $a2, $zero, 0xF50
    ctx->r6 = ADD32(0, 0XF50);
    // 0x80800218: jal         0x800C9CD0
    // 0x8080021C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_800C9CD0(rdram, ctx);
        goto after_9;
    // 0x8080021C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_9:
    // 0x80800220: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80800224: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800228: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080022C: addiu       $a3, $zero, 0x2020
    ctx->r7 = ADD32(0, 0X2020);
    // 0x80800230: jal         0x80085708
    // 0x80800234: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_10;
    // 0x80800234: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    after_10:
L_80800238:
    // 0x80800238: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080023C:
    // 0x8080023C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800240: jr          $ra
    // 0x80800244: nop

    return;
    // 0x80800244: nop

;}
RECOMP_FUNC void _badronemem_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084910: syscall     123
    recomp_syscall_handler(rdram, ctx, 0x80084910);
    return;
    // 0x80084914: xori        $t0, $zero, 0xC
    ctx->r8 = 0 ^ 0XC;
;}
RECOMP_FUNC void func_8009CBFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CBFC: jr          $ra
    // 0x8009CC00: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8009CC00: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8009CC04: nop

    // 0x8009CC08: nop

    // 0x8009CC0C: nop

;}
RECOMP_FUNC void _ncpod_entrypoint_28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800895A0: syscall     783
    recomp_syscall_handler(rdram, ctx, 0x800895A0);
    return;
    // 0x800895A4: addi        $t0, $zero, 0x70
    ctx->r8 = ADD32(0, 0X70);
;}
RECOMP_FUNC void gczoombox_entrypoint_35(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803924: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803928: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080392C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80803930: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80803934: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80803938: sw          $a1, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r5;
    // 0x8080393C: or          $t9, $a0, $zero
    ctx->r25 = ctx->r4 | 0;
    // 0x80803940: sh          $a2, 0x13A($a0)
    MEM_H(0X13A, ctx->r4) = ctx->r6;
    // 0x80803944: sw          $a3, 0x13C($a0)
    MEM_W(0X13C, ctx->r4) = ctx->r7;
    // 0x80803948: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8080394C: jal         0x800EC370
    // 0x80803950: addiu       $a1, $t9, 0x134
    ctx->r5 = ADD32(ctx->r25, 0X134);
    func_800EC370(rdram, ctx);
        goto after_0;
    // 0x80803950: addiu       $a1, $t9, 0x134
    ctx->r5 = ADD32(ctx->r25, 0X134);
    after_0:
    // 0x80803954: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803958: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080395C: jr          $ra
    // 0x80803960: nop

    return;
    // 0x80803960: nop

;}
RECOMP_FUNC void _fxstep_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088A00: syscall     718
    recomp_syscall_handler(rdram, ctx, 0x80088A00);
    return;
    // 0x80088A04: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800054_chfactorystationdoors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800054: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800058: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080005C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800060: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800064: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800068: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080006C: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800070: beq         $t6, $at, L_80800094
    if (ctx->r14 == ctx->r1) {
        // 0x80800074: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800094;
    }
    // 0x80800074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800078: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080007C: beq         $t6, $at, L_808000A4
    if (ctx->r14 == ctx->r1) {
        // 0x80800080: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808000A4;
    }
    // 0x80800080: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800084: beq         $t6, $at, L_8080013C
    if (ctx->r14 == ctx->r1) {
        // 0x80800088: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080013C;
    }
    // 0x80800088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080008C: b           L_80800148
    // 0x80800090: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800148;
    // 0x80800090: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800094:
    // 0x80800094: jal         0x80103110
    // 0x80800098: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_0;
    // 0x80800098: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080009C: b           L_80800148
    // 0x808000A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800148;
    // 0x808000A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000A4:
    // 0x808000A4: jal         0x800D90A4
    // 0x808000A8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_1;
    // 0x808000A8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_1:
    // 0x808000AC: beq         $v0, $zero, L_808000E4
    if (ctx->r2 == 0) {
        // 0x808000B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000E4;
    }
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B4: jal         0x80089D40
    // 0x808000B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808000B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808000BC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2340, 0X25C) << 16);
    // 0x808000C0: addiu       $a2, $a2, 0x25C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2340, 0X25C));
    // 0x808000C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C8: jal         0x80089D18
    // 0x808000CC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x808000CC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D4: jal         0x80101FDC
    // 0x808000D8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x808000D8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x808000DC: b           L_808000F8
    // 0x808000E0: nop

        goto L_808000F8;
    // 0x808000E0: nop

L_808000E4:
    // 0x808000E4: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2340, 0X250) << 16);
    // 0x808000E8: addiu       $a3, $a3, 0x250
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2340, 0X250));
    // 0x808000EC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808000F0: jal         0x80089D50
    // 0x808000F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x808000F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
L_808000F8:
    // 0x808000F8: jal         0x80103EF4
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EF4(rdram, ctx);
        goto after_6;
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800100: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x80800104: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800108: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2340, 0X240) << 16);
    // 0x8080010C: lwc1        $f4, 0x240($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2340, 0X240));
    // 0x80800110: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800114: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800118: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8080011C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80800120: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80800124: jal         0x800F10B4
    // 0x80800128: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_7;
    // 0x80800128: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_7:
    // 0x8080012C: lwc1        $f8, 0x34($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800130: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80800134: b           L_80800144
    // 0x80800138: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
        goto L_80800144;
    // 0x80800138: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
L_8080013C:
    // 0x8080013C: jal         0x80103110
    // 0x80800140: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_8;
    // 0x80800140: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
L_80800144:
    // 0x80800144: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800148:
    // 0x80800148: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080014C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800150: jr          $ra
    // 0x80800154: nop

    return;
    // 0x80800154: nop

;}
RECOMP_FUNC void _chtransparencypot_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087380: syscall     558
    recomp_syscall_handler(rdram, ctx, 0x80087380);
    return;
    // 0x80087384: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void bafpctrl_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BA0: lw          $t6, 0x90($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X90);
    // 0x80800BA4: jr          $ra
    // 0x80800BA8: lbu         $v0, 0x12($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X12);
    return;
    // 0x80800BA8: lbu         $v0, 0x12($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X12);
;}
RECOMP_FUNC void func_800BD09C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD09C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BD0A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BD0A4: jal         0x8001B084
    // 0x800BD0A8: nop

    heap_free(rdram, ctx);
        goto after_0;
    // 0x800BD0A8: nop

    after_0:
    // 0x800BD0AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BD0B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BD0B4: jr          $ra
    // 0x800BD0B8: nop

    return;
    // 0x800BD0B8: nop

;}
RECOMP_FUNC void func_8080011C_chbabydino(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080011C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800120: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800124: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800128: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080012C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800130: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800134: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800138: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8080013C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800140: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800144: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800148: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080014C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800150: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x80800154: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800158: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8080015C: jal         0x80089F18
    // 0x80800160: nop

    _sudeflect_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800160: nop

    after_0:
    // 0x80800164: jal         0x80089828
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suexpression_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080016C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800170: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800174: jal         0x800897D8
    // 0x80800178: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x80800178: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8080017C: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800180: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800184: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800188: sltiu       $at, $t8, 0x5
    ctx->r1 = ctx->r24 < 0X5 ? 1 : 0;
    // 0x8080018C: beq         $at, $zero, L_80800270
    if (ctx->r1 == 0) {
        // 0x80800190: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800270;
    }
    // 0x80800190: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800194: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(848, 0X6E0) << 16);
    // 0x80800198: addu        $at, $at, $t8
    gpr jr_addend_808001A0 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8080019C: lw          $t8, 0x6E0($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(848, 0X6E0));
    // 0x808001A0: jr          $t8
    // 0x808001A4: nop

    switch (jr_addend_808001A0 >> 2) {
        case 0: goto L_80800270; break;
        case 1: goto L_808001A8; break;
        case 2: goto L_808001B8; break;
        case 3: goto L_8080020C; break;
        case 4: goto L_8080025C; break;
        default: switch_error(__func__, 0x808001A0, 0x808006E0);
    }
    // 0x808001A4: nop

L_808001A8:
    // 0x808001A8: jal         0x80800448
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800448_chbabydino(rdram, ctx);
        goto after_3;
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808001B0: b           L_80800270
    // 0x808001B4: nop

        goto L_80800270;
    // 0x808001B4: nop

L_808001B8:
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001BC: jal         0x808005A0
    // 0x808001C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808005A0_chbabydino(rdram, ctx);
        goto after_4;
    // 0x808001C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x808001C4: bne         $v0, $zero, L_80800270
    if (ctx->r2 != 0) {
        // 0x808001C8: nop
    
            goto L_80800270;
    }
    // 0x808001C8: nop

    // 0x808001CC: jal         0x80085710
    // 0x808001D0: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_5;
    // 0x808001D0: nop

    after_5:
    // 0x808001D4: jal         0x80088840
    // 0x808001D8: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_6;
    // 0x808001D8: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_6:
    // 0x808001DC: beq         $v0, $zero, L_808001FC
    if (ctx->r2 == 0) {
        // 0x808001E0: addiu       $a0, $zero, 0xEC
        ctx->r4 = ADD32(0, 0XEC);
            goto L_808001FC;
    }
    // 0x808001E0: addiu       $a0, $zero, 0xEC
    ctx->r4 = ADD32(0, 0XEC);
    // 0x808001E4: addiu       $a0, $zero, 0xEC
    ctx->r4 = ADD32(0, 0XEC);
    // 0x808001E8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x808001EC: jal         0x80088868
    // 0x808001F0: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    _glcutDll_entrypoint_24(rdram, ctx);
        goto after_7;
    // 0x808001F0: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    after_7:
    // 0x808001F4: b           L_80800270
    // 0x808001F8: nop

        goto L_80800270;
    // 0x808001F8: nop

L_808001FC:
    // 0x808001FC: jal         0x800887D8
    // 0x80800200: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_8;
    // 0x80800200: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    after_8:
    // 0x80800204: b           L_80800270
    // 0x80800208: nop

        goto L_80800270;
    // 0x80800208: nop

L_8080020C:
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800210: jal         0x808005A0
    // 0x80800214: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808005A0_chbabydino(rdram, ctx);
        goto after_9;
    // 0x80800214: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x80800218: bne         $v0, $zero, L_80800270
    if (ctx->r2 != 0) {
        // 0x8080021C: nop
    
            goto L_80800270;
    }
    // 0x8080021C: nop

    // 0x80800220: jal         0x800DA544
    // 0x80800224: addiu       $a0, $zero, 0x588
    ctx->r4 = ADD32(0, 0X588);
    func_800DA544(rdram, ctx);
        goto after_10;
    // 0x80800224: addiu       $a0, $zero, 0x588
    ctx->r4 = ADD32(0, 0X588);
    after_10:
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080022C: jal         0x80102424
    // 0x80800230: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_11;
    // 0x80800230: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_11:
    // 0x80800234: jal         0x800FFAB0
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_12;
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8080023C: jal         0x80088820
    // 0x80800240: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _glcutDll_entrypoint_15(rdram, ctx);
        goto after_13;
    // 0x80800240: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_13:
    // 0x80800244: jal         0x80088830
    // 0x80800248: nop

    _glcutDll_entrypoint_17(rdram, ctx);
        goto after_14;
    // 0x80800248: nop

    after_14:
    // 0x8080024C: jal         0x80085710
    // 0x80800250: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_15;
    // 0x80800250: nop

    after_15:
    // 0x80800254: b           L_80800270
    // 0x80800258: nop

        goto L_80800270;
    // 0x80800258: nop

L_8080025C:
    // 0x8080025C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(848, 0X7B8) << 16);
    // 0x80800260: addiu       $a2, $a2, 0x7B8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(848, 0X7B8));
    // 0x80800264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800268: jal         0x8008A1E8
    // 0x8080026C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _subaddiedialog_entrypoint_7(rdram, ctx);
        goto after_16;
    // 0x8080026C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_16:
L_80800270:
    // 0x80800270: jal         0x80087738
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chdinofamilyfx_entrypoint_0(rdram, ctx);
        goto after_17;
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800278: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080027C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800280: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800284: jr          $ra
    // 0x80800288: nop

    return;
    // 0x80800288: nop

;}
RECOMP_FUNC void func_808002B0_chmrsboggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808002B4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808002B8: slti        $at, $a1, 0x53
    ctx->r1 = SIGNED(ctx->r5) < 0X53 ? 1 : 0;
    // 0x808002BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808002C4: bne         $at, $zero, L_808002F8
    if (ctx->r1 != 0) {
        // 0x808002C8: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_808002F8;
    }
    // 0x808002C8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808002CC: addiu       $at, $zero, 0x57
    ctx->r1 = ADD32(0, 0X57);
    // 0x808002D0: beq         $a1, $at, L_80800438
    if (ctx->r5 == ctx->r1) {
        // 0x808002D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800438;
    }
    // 0x808002D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002D8: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808002DC: beq         $a1, $at, L_80800490
    if (ctx->r5 == ctx->r1) {
        // 0x808002E0: addiu       $a0, $zero, 0x357
        ctx->r4 = ADD32(0, 0X357);
            goto L_80800490;
    }
    // 0x808002E0: addiu       $a0, $zero, 0x357
    ctx->r4 = ADD32(0, 0X357);
    // 0x808002E4: addiu       $at, $zero, 0xB8
    ctx->r1 = ADD32(0, 0XB8);
    // 0x808002E8: beq         $a1, $at, L_80800470
    if (ctx->r5 == ctx->r1) {
        // 0x808002EC: nop
    
            goto L_80800470;
    }
    // 0x808002EC: nop

    // 0x808002F0: b           L_808004E0
    // 0x808002F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808004E0;
    // 0x808002F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808002F8:
    // 0x808002F8: slti        $at, $a1, 0x50
    ctx->r1 = SIGNED(ctx->r5) < 0X50 ? 1 : 0;
    // 0x808002FC: bne         $at, $zero, L_80800318
    if (ctx->r1 != 0) {
        // 0x80800300: addiu       $t6, $a1, -0x23
        ctx->r14 = ADD32(ctx->r5, -0X23);
            goto L_80800318;
    }
    // 0x80800300: addiu       $t6, $a1, -0x23
    ctx->r14 = ADD32(ctx->r5, -0X23);
    // 0x80800304: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x80800308: beq         $a1, $at, L_80800424
    if (ctx->r5 == ctx->r1) {
        // 0x8080030C: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(888, 0XA80) << 16);
            goto L_80800424;
    }
    // 0x8080030C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(888, 0XA80) << 16);
    // 0x80800310: b           L_808004E0
    // 0x80800314: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808004E0;
    // 0x80800314: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800318:
    // 0x80800318: slti        $at, $a1, 0x32
    ctx->r1 = SIGNED(ctx->r5) < 0X32 ? 1 : 0;
    // 0x8080031C: bne         $at, $zero, L_80800334
    if (ctx->r1 != 0) {
        // 0x80800320: addiu       $at, $zero, 0x4F
        ctx->r1 = ADD32(0, 0X4F);
            goto L_80800334;
    }
    // 0x80800320: addiu       $at, $zero, 0x4F
    ctx->r1 = ADD32(0, 0X4F);
    // 0x80800324: beq         $a1, $at, L_80800460
    if (ctx->r5 == ctx->r1) {
        // 0x80800328: nop
    
            goto L_80800460;
    }
    // 0x80800328: nop

    // 0x8080032C: b           L_808004E0
    // 0x80800330: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808004E0;
    // 0x80800330: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800334:
    // 0x80800334: sltiu       $at, $t6, 0xF
    ctx->r1 = ctx->r14 < 0XF ? 1 : 0;
    // 0x80800338: beq         $at, $zero, L_808004D4
    if (ctx->r1 == 0) {
        // 0x8080033C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_808004D4;
    }
    // 0x8080033C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800340: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(888, 0X9E0) << 16);
    // 0x80800344: addu        $at, $at, $t6
    gpr jr_addend_8080034C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800348: lw          $t6, 0x9E0($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(888, 0X9E0));
    // 0x8080034C: jr          $t6
    // 0x80800350: nop

    switch (jr_addend_8080034C >> 2) {
        case 0: goto L_808004A0; break;
        case 1: goto L_808004D4; break;
        case 2: goto L_808004D4; break;
        case 3: goto L_808004D4; break;
        case 4: goto L_808004D4; break;
        case 5: goto L_808004D4; break;
        case 6: goto L_80800404; break;
        case 7: goto L_80800414; break;
        case 8: goto L_808004D4; break;
        case 9: goto L_808004D4; break;
        case 10: goto L_808004D4; break;
        case 11: goto L_80800354; break;
        case 12: goto L_808004D4; break;
        case 13: goto L_80800370; break;
        case 14: goto L_8080038C; break;
        default: switch_error(__func__, 0x8080034C, 0x808009E0);
    }
    // 0x80800350: nop

L_80800354:
    // 0x80800354: addiu       $v0, $sp, 0x30
    ctx->r2 = ADD32(ctx->r29, 0X30);
    // 0x80800358: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x8080035C: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x80800360: jal         0x808005D8
    // 0x80800364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808005D8_chmrsboggy(rdram, ctx);
        goto after_0;
    // 0x80800364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800368: b           L_808004E0
    // 0x8080036C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004E0;
    // 0x8080036C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800370:
    // 0x80800370: addiu       $v0, $sp, 0x30
    ctx->r2 = ADD32(ctx->r29, 0X30);
    // 0x80800374: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80800378: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x8080037C: jal         0x8080070C
    // 0x80800380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080070C_chmrsboggy(rdram, ctx);
        goto after_1;
    // 0x80800380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800384: b           L_808004E4
    // 0x80800388: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808004E4;
    // 0x80800388: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080038C:
    // 0x8080038C: lhu         $t7, 0x72($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X72);
    // 0x80800390: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800394: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80800398: bne         $t8, $at, L_808003A8
    if (ctx->r24 != ctx->r1) {
        // 0x8080039C: nop
    
            goto L_808003A8;
    }
    // 0x8080039C: nop

    // 0x808003A0: b           L_808004E0
    // 0x808003A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808004E0;
    // 0x808003A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808003A8:
    // 0x808003A8: jal         0x800DA544
    // 0x808003AC: addiu       $a0, $zero, 0x8B
    ctx->r4 = ADD32(0, 0X8B);
    func_800DA544(rdram, ctx);
        goto after_2;
    // 0x808003AC: addiu       $a0, $zero, 0x8B
    ctx->r4 = ADD32(0, 0X8B);
    after_2:
    // 0x808003B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003B4: jal         0x80102424
    // 0x808003B8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x808003B8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x808003BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003C0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808003C4: jal         0x808007CC
    // 0x808003C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_808007CC_chmrsboggy(rdram, ctx);
        goto after_4;
    // 0x808003C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x808003CC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808003D0: addiu       $t9, $zero, 0x3E
    ctx->r25 = ADD32(0, 0X3E);
    // 0x808003D4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808003D8: addiu       $a1, $zero, 0x109D
    ctx->r5 = ADD32(0, 0X109D);
    // 0x808003DC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x808003E0: jal         0x8008A208
    // 0x808003E4: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x808003E4: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_5:
    // 0x808003E8: jal         0x800F54E4
    // 0x808003EC: nop

    func_800F54E4(rdram, ctx);
        goto after_6;
    // 0x808003EC: nop

    after_6:
    // 0x808003F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003F4: jal         0x800F82D4
    // 0x808003F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800F82D4(rdram, ctx);
        goto after_7;
    // 0x808003F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x808003FC: b           L_808004E0
    // 0x80800400: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004E0;
    // 0x80800400: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800404:
    // 0x80800404: jal         0x808004F4
    // 0x80800408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808004F4_chmrsboggy(rdram, ctx);
        goto after_8;
    // 0x80800408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8080040C: b           L_808004E0
    // 0x80800410: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004E0;
    // 0x80800410: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800414:
    // 0x80800414: jal         0x80800548
    // 0x80800418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800548_chmrsboggy(rdram, ctx);
        goto after_9;
    // 0x80800418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080041C: b           L_808004E0
    // 0x80800420: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004E0;
    // 0x80800420: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800424:
    // 0x80800424: addiu       $a0, $a0, 0xA80
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(888, 0XA80));
    // 0x80800428: jal         0x80088090
    // 0x8080042C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_10;
    // 0x8080042C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_10:
    // 0x80800430: b           L_808004E0
    // 0x80800434: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004E0;
    // 0x80800434: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800438:
    // 0x80800438: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8080043C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80800440: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80800444: andi        $t0, $a1, 0xFFFF
    ctx->r8 = ctx->r5 & 0XFFFF;
    // 0x80800448: and         $t1, $a2, $at
    ctx->r9 = ctx->r6 & ctx->r1;
    // 0x8080044C: srl         $a2, $t1, 16
    ctx->r6 = S32(U32(ctx->r9) >> 16);
    // 0x80800450: jal         0x80800738
    // 0x80800454: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    func_80800738_chmrsboggy(rdram, ctx);
        goto after_11;
    // 0x80800454: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    after_11:
    // 0x80800458: b           L_808004E4
    // 0x8080045C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808004E4;
    // 0x8080045C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800460:
    // 0x80800460: jal         0x80800790
    // 0x80800464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800790_chmrsboggy(rdram, ctx);
        goto after_12;
    // 0x80800464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800468: b           L_808004E0
    // 0x8080046C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004E0;
    // 0x8080046C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800470:
    // 0x80800470: jal         0x80800990
    // 0x80800474: nop

    func_80800990_chmrsboggy(rdram, ctx);
        goto after_13;
    // 0x80800474: nop

    after_13:
    // 0x80800478: beq         $v0, $zero, L_80800488
    if (ctx->r2 == 0) {
        // 0x8080047C: addiu       $v1, $zero, 0x109B
        ctx->r3 = ADD32(0, 0X109B);
            goto L_80800488;
    }
    // 0x8080047C: addiu       $v1, $zero, 0x109B
    ctx->r3 = ADD32(0, 0X109B);
    // 0x80800480: b           L_808004E0
    // 0x80800484: addiu       $v0, $zero, 0x109C
    ctx->r2 = ADD32(0, 0X109C);
        goto L_808004E0;
    // 0x80800484: addiu       $v0, $zero, 0x109C
    ctx->r2 = ADD32(0, 0X109C);
L_80800488:
    // 0x80800488: b           L_808004E0
    // 0x8080048C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_808004E0;
    // 0x8080048C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80800490:
    // 0x80800490: jal         0x80088480
    // 0x80800494: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    _glsplinefind_entrypoint_0(rdram, ctx);
        goto after_14;
    // 0x80800494: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_14:
    // 0x80800498: b           L_808004DC
    // 0x8080049C: sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
        goto L_808004DC;
    // 0x8080049C: sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
L_808004A0:
    // 0x808004A0: addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    // 0x808004A4: jal         0x800DA980
    // 0x808004A8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DA980(rdram, ctx);
        goto after_15;
    // 0x808004A8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_15:
    // 0x808004AC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808004B0: bnel        $v0, $at, L_808004E0
    if (ctx->r2 != ctx->r1) {
        // 0x808004B4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808004E0;
    }
    goto skip_0;
    // 0x808004B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x808004B8: jal         0x800DA524
    // 0x808004BC: addiu       $a0, $zero, 0x8B
    ctx->r4 = ADD32(0, 0X8B);
    func_800DA524(rdram, ctx);
        goto after_16;
    // 0x808004BC: addiu       $a0, $zero, 0x8B
    ctx->r4 = ADD32(0, 0X8B);
    after_16:
    // 0x808004C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004C4: jal         0x80102424
    // 0x808004C8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_17;
    // 0x808004C8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_17:
    // 0x808004CC: b           L_808004E0
    // 0x808004D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004E0;
    // 0x808004D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004D4:
    // 0x808004D4: b           L_808004E0
    // 0x808004D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808004E0;
    // 0x808004D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808004DC:
    // 0x808004DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004E0:
    // 0x808004E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808004E4:
    // 0x808004E4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808004E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808004EC: jr          $ra
    // 0x808004F0: nop

    return;
    // 0x808004F0: nop

;}
RECOMP_FUNC void _fxegg_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088A98: syscall     719
    recomp_syscall_handler(rdram, ctx, 0x80088A98);
    return;
    // 0x80088A9C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void bamovethrust_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800084: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80800088: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080008C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800090: lw          $a1, 0xC8($a0)
    ctx->r5 = MEM_W(ctx->r4, 0XC8);
    // 0x80800094: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x80800098: jal         0x80800000
    // 0x8080009C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    func_80800000_bamovethrust(rdram, ctx);
        goto after_0;
    // 0x8080009C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_0:
    // 0x808000A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000A8: jr          $ra
    // 0x808000AC: nop

    return;
    // 0x808000AC: nop

;}
RECOMP_FUNC void chmole_overworld_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800184: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1784, 0X1F0) << 16);
    // 0x80800188: jr          $ra
    // 0x8080018C: addiu       $v0, $v0, 0x1F0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1784, 0X1F0));
    return;
    // 0x8080018C: addiu       $v0, $v0, 0x1F0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1784, 0X1F0));
;}
RECOMP_FUNC void func_808009BC_chhoney(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808009C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808009C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808009C8: jal         0x800D8FF8
    // 0x808009CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808009CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808009D0: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808009D4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x808009D8: lwc1        $f8, 0x30($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X30);
    // 0x808009DC: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x808009E0: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x808009E4: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    // 0x808009E8: lwc1        $f18, 0x58($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808009EC: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
    // 0x808009F0: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x808009F4: nop

    // 0x808009F8: bc1fl       L_80800A4C
    if (!c1cs) {
        // 0x808009FC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800A4C;
    }
    goto skip_0;
    // 0x808009FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800A00: jal         0x8008FC00
    // 0x80800A04: nop

    func_8008FC00(rdram, ctx);
        goto after_1;
    // 0x80800A04: nop

    after_1:
    // 0x80800A08: addiu       $a1, $v0, 0x1
    ctx->r5 = ADD32(ctx->r2, 0X1);
    // 0x80800A0C: jal         0x8008FC28
    // 0x80800A10: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_8008FC28(rdram, ctx);
        goto after_2;
    // 0x80800A10: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_2:
    // 0x80800A14: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800A18: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80800A1C: beql        $at, $zero, L_80800A2C
    if (ctx->r1 == 0) {
        // 0x80800A20: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80800A2C;
    }
    goto skip_1;
    // 0x80800A20: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    skip_1:
    // 0x80800A24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800A28: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_80800A2C:
    // 0x80800A2C: jal         0x8008FC70
    // 0x80800A30: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_8008FC70(rdram, ctx);
        goto after_3;
    // 0x80800A30: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_3:
    // 0x80800A34: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800A38: jal         0x80800870
    // 0x80800A3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800870_chhoney(rdram, ctx);
        goto after_4;
    // 0x80800A3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800A40: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800A44: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    // 0x80800A48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800A4C:
    // 0x80800A4C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800A50: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800A54: jr          $ra
    // 0x80800A58: nop

    return;
    // 0x80800A58: nop

;}
RECOMP_FUNC void func_800A86D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A86D8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A86DC: lw          $a0, 0x76BC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X76BC);
    // 0x800A86E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A86E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A86E8: beql        $a0, $zero, L_800A8704
    if (ctx->r4 == 0) {
        // 0x800A86EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A8704;
    }
    goto skip_0;
    // 0x800A86EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800A86F0: jal         0x800CA384
    // 0x800A86F4: nop

    func_800CA384(rdram, ctx);
        goto after_0;
    // 0x800A86F4: nop

    after_0:
    // 0x800A86F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A86FC: sw          $v0, 0x76BC($at)
    MEM_W(0X76BC, ctx->r1) = ctx->r2;
    // 0x800A8700: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A8704:
    // 0x800A8704: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A8708: jr          $ra
    // 0x800A870C: nop

    return;
    // 0x800A870C: nop

;}
RECOMP_FUNC void func_8001BD50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BD50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001BD54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001BD58: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x8001BD5C: jal         0x8001B3F4
    // 0x8001BD60: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    heap_largest_free(rdram, ctx);
        goto after_0;
    // 0x8001BD60: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8001BD64: jal         0x8001B3C0
    // 0x8001BD68: nop

    heap_bytes_free(rdram, ctx);
        goto after_1;
    // 0x8001BD68: nop

    after_1:
    // 0x8001BD6C: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8001BD70: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8001BD74: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8001BD78: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001BD7C: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8001BD80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001BD84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001BD88: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8001BD8C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8001BD90: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x8001BD94: nop

    // 0x8001BD98: bc1f        L_8001BDA4
    if (!c1cs) {
        // 0x8001BD9C: nop
    
            goto L_8001BDA4;
    }
    // 0x8001BD9C: nop

    // 0x8001BDA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8001BDA4:
    // 0x8001BDA4: jr          $ra
    // 0x8001BDA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8001BDA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80018704(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018704: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x80018708: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001870C: sll         $t6, $a0, 5
    ctx->r14 = S32(ctx->r4 << 5);
    // 0x80018710: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x80018714: c.eq.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl == ctx->f4.fl;
    // 0x80018718: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8001871C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80018720: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80018724: bc1t        L_800187AC
    if (c1cs) {
        // 0x80018728: lui         $t7, 0x8008
        ctx->r15 = S32(0X8008 << 16);
            goto L_800187AC;
    }
    // 0x80018728: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x8001872C: addiu       $t7, $t7, -0x4D30
    ctx->r15 = ADD32(ctx->r15, -0X4D30);
    // 0x80018730: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80018734: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80018738: lw          $t9, 0x10($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X10);
    // 0x8001873C: beq         $t8, $zero, L_800187AC
    if (ctx->r24 == 0) {
        // 0x80018740: nop
    
            goto L_800187AC;
    }
    // 0x80018740: nop

    // 0x80018744: bnel        $t9, $zero, L_80018798
    if (ctx->r25 != 0) {
        // 0x80018748: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_80018798;
    }
    goto skip_0;
    // 0x80018748: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_0:
    // 0x8001874C: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80018750: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80018754: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80018758: lwc1        $f6, 0x1730($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1730);
    // 0x8001875C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80018760: lwc1        $f18, 0x8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X8);
    // 0x80018764: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    // 0x80018768: nop

    // 0x8001876C: bc1fl       L_80018798
    if (!c1cs) {
        // 0x80018770: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_80018798;
    }
    goto skip_1;
    // 0x80018770: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_1:
    // 0x80018774: lwc1        $f8, 0x18($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80018778: lwc1        $f10, 0x14($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8001877C: add.s       $f4, $f14, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f18.fl;
    // 0x80018780: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80018784: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80018788: nop

    // 0x8001878C: bc1t        L_800187AC
    if (c1cs) {
        // 0x80018790: nop
    
            goto L_800187AC;
    }
    // 0x80018790: nop

    // 0x80018794: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_80018798:
    // 0x80018798: lwc1        $f18, 0x8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8001879C: swc1        $f12, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f12.u32l;
    // 0x800187A0: swc1        $f14, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f14.u32l;
    // 0x800187A4: swc1        $f16, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f16.u32l;
    // 0x800187A8: swc1        $f18, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f18.u32l;
L_800187AC:
    // 0x800187AC: jr          $ra
    // 0x800187B0: nop

    return;
    // 0x800187B0: nop

;}
RECOMP_FUNC void _susubgame_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A2B0: syscall     834
    recomp_syscall_handler(rdram, ctx, 0x8008A2B0);
    return;
    // 0x8008A2B4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80112D90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80112D90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80112D94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80112D98: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80112D9C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80112DA0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80112DA4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80112DA8: lw          $v0, 0x60($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X60);
    // 0x80112DAC: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80112DB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80112DB4: lh          $t7, 0xE($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XE);
    // 0x80112DB8: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80112DBC: bnel        $at, $zero, L_80112E40
    if (ctx->r1 != 0) {
        // 0x80112DC0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80112E40;
    }
    goto skip_0;
    // 0x80112DC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80112DC4: lh          $t9, 0xC($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XC);
    // 0x80112DC8: beql        $a3, $t9, L_80112DE0
    if (ctx->r7 == ctx->r25) {
        // 0x80112DCC: lwc1        $f4, 0x24($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
            goto L_80112DE0;
    }
    goto skip_1;
    // 0x80112DCC: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80112DD0: jal         0x80112D2C
    // 0x80112DD4: nop

    func_80112D2C(rdram, ctx);
        goto after_0;
    // 0x80112DD4: nop

    after_0:
    // 0x80112DD8: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
    // 0x80112DDC: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
L_80112DE0:
    // 0x80112DE0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80112DE4: swc1        $f4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f4.u32l;
    // 0x80112DE8: lw          $t0, 0x60($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X60);
    // 0x80112DEC: swc1        $f6, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f6.u32l;
    // 0x80112DF0: lw          $v0, 0x60($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X60);
    // 0x80112DF4: lwc1        $f12, 0x10($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80112DF8: jal         0x800F1DCC
    // 0x80112DFC: lwc1        $f14, 0x14($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X14);
    func_800F1DCC(rdram, ctx);
        goto after_1;
    // 0x80112DFC: lwc1        $f14, 0x14($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X14);
    after_1:
    // 0x80112E00: jal         0x800F2100
    // 0x80112E04: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_2;
    // 0x80112E04: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_2:
    // 0x80112E08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80112E0C: lwc1        $f8, 0x65A8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X65A8);
    // 0x80112E10: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80112E14: lw          $t1, 0x60($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X60);
    // 0x80112E18: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80112E1C: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80112E20: swc1        $f18, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->f18.u32l;
    // 0x80112E24: lw          $t3, 0x60($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X60);
    // 0x80112E28: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80112E2C: sh          $t2, 0xC($t3)
    MEM_H(0XC, ctx->r11) = ctx->r10;
    // 0x80112E30: lw          $t5, 0x60($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X60);
    // 0x80112E34: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80112E38: sh          $t4, 0xE($t5)
    MEM_H(0XE, ctx->r13) = ctx->r12;
    // 0x80112E3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80112E40:
    // 0x80112E40: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80112E44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80112E48: jr          $ra
    // 0x80112E4C: nop

    return;
    // 0x80112E4C: nop

;}
RECOMP_FUNC void mlMtxSet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018EFC: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80018F00: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80018F04: addiu       $a1, $a1, -0x4350
    ctx->r5 = ADD32(ctx->r5, -0X4350);
    // 0x80018F08: addiu       $v0, $t6, -0x4B10
    ctx->r2 = ADD32(ctx->r14, -0X4B10);
    // 0x80018F0C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80018F10: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80018F14: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80018F18:
    // 0x80018F18: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80018F1C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80018F20: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80018F24: swc1        $f4, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f4.u32l;
    // 0x80018F28: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80018F2C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80018F30: swc1        $f6, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f6.u32l;
    // 0x80018F34: lwc1        $f8, -0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, -0X8);
    // 0x80018F38: swc1        $f8, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f8.u32l;
    // 0x80018F3C: lwc1        $f10, -0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, -0X4);
    // 0x80018F40: bne         $v1, $a1, L_80018F18
    if (ctx->r3 != ctx->r5) {
        // 0x80018F44: swc1        $f10, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
            goto L_80018F18;
    }
    // 0x80018F44: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
    // 0x80018F48: jr          $ra
    // 0x80018F4C: nop

    return;
    // 0x80018F4C: nop

;}
RECOMP_FUNC void func_8080090C_chbubbleelevator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080090C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800910: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800914: beq         $a1, $at, L_80800930
    if (ctx->r5 == ctx->r1) {
        // 0x80800918: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80800930;
    }
    // 0x80800918: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080091C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800920: beq         $a1, $at, L_8080094C
    if (ctx->r5 == ctx->r1) {
        // 0x80800924: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8080094C;
    }
    // 0x80800924: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800928: b           L_80800A00
    // 0x8080092C: nop

        goto L_80800A00;
    // 0x8080092C: nop

L_80800930:
    // 0x80800930: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x80800934: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80800938: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080093C: jal         0x808004DC
    // 0x80800940: swc1        $f6, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f6.u32l;
    func_808004DC_chbubbleelevator(rdram, ctx);
        goto after_0;
    // 0x80800940: swc1        $f6, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f6.u32l;
    after_0:
    // 0x80800944: b           L_80800A00
    // 0x80800948: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A00;
    // 0x80800948: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080094C:
    // 0x8080094C: lbu         $t6, 0x79($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X79);
    // 0x80800950: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2368, 0XC20) << 16);
    // 0x80800954: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800958: srl         $t7, $t6, 4
    ctx->r15 = S32(U32(ctx->r14) >> 4);
    // 0x8080095C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80800960: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80800964: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80800968: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8080096C: lbu         $t9, 0xC20($t9)
    ctx->r25 = MEM_BU(ctx->r25, (int16_t)RELOC_LO16(2368, 0XC20));
    // 0x80800970: bnel        $a2, $t9, L_80800990
    if (ctx->r6 != ctx->r25) {
        // 0x80800974: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80800990;
    }
    goto skip_0;
    // 0x80800974: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    skip_0:
    // 0x80800978: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080097C: jal         0x808004DC
    // 0x80800980: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_808004DC_chbubbleelevator(rdram, ctx);
        goto after_1;
    // 0x80800980: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x80800984: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800988: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8080098C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
L_80800990:
    // 0x80800990: jal         0x800EA05C
    // 0x80800994: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800EA05C(rdram, ctx);
        goto after_2;
    // 0x80800994: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_2:
    // 0x80800998: addiu       $at, $zero, 0x136
    ctx->r1 = ADD32(0, 0X136);
    // 0x8080099C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808009A0: bne         $v0, $at, L_808009F8
    if (ctx->r2 != ctx->r1) {
        // 0x808009A4: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_808009F8;
    }
    // 0x808009A4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808009A8: lbu         $t0, 0x79($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X79);
    // 0x808009AC: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(2368, 0XC20) << 16);
    // 0x808009B0: addiu       $a0, $zero, 0x504
    ctx->r4 = ADD32(0, 0X504);
    // 0x808009B4: srl         $t1, $t0, 4
    ctx->r9 = S32(U32(ctx->r8) >> 4);
    // 0x808009B8: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x808009BC: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x808009C0: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x808009C4: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x808009C8: lbu         $t3, 0xC20($t3)
    ctx->r11 = MEM_BU(ctx->r11, (int16_t)RELOC_LO16(2368, 0XC20));
    // 0x808009CC: bne         $a2, $t3, L_808009F8
    if (ctx->r6 != ctx->r11) {
        // 0x808009D0: nop
    
            goto L_808009F8;
    }
    // 0x808009D0: nop

    // 0x808009D4: jal         0x800DA298
    // 0x808009D8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x808009D8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_3:
    // 0x808009DC: bne         $v0, $zero, L_808009F8
    if (ctx->r2 != 0) {
        // 0x808009E0: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_808009F8;
    }
    // 0x808009E0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808009E4: addiu       $a0, $zero, 0x383
    ctx->r4 = ADD32(0, 0X383);
    // 0x808009E8: jal         0x80101180
    // 0x808009EC: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80101180(rdram, ctx);
        goto after_4;
    // 0x808009EC: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_4:
    // 0x808009F0: b           L_80800A04
    // 0x808009F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800A04;
    // 0x808009F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808009F8:
    // 0x808009F8: b           L_80800A00
    // 0x808009FC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80800A00;
    // 0x808009FC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80800A00:
    // 0x80800A00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800A04:
    // 0x80800A04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A08: jr          $ra
    // 0x80800A0C: nop

    return;
    // 0x80800A0C: nop

;}
RECOMP_FUNC void _dbpalette_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087958: syscall     641
    recomp_syscall_handler(rdram, ctx, 0x80087958);
    return;
    // 0x8008795C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800A18_chexploder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800A1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800A24: jal         0x80100094
    // 0x80800A28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800A28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800A2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800A30: addiu       $t6, $zero, 0x320
    ctx->r14 = ADD32(0, 0X320);
    // 0x80800A34: addiu       $t7, $zero, 0x3E8
    ctx->r15 = ADD32(0, 0X3E8);
    // 0x80800A38: addiu       $t8, $zero, 0xC8
    ctx->r24 = ADD32(0, 0XC8);
    // 0x80800A3C: addiu       $t9, $zero, 0x12C
    ctx->r25 = ADD32(0, 0X12C);
    // 0x80800A40: addiu       $t0, $zero, -0x41A
    ctx->r8 = ADD32(0, -0X41A);
    // 0x80800A44: addiu       $t1, $zero, -0x3B6
    ctx->r9 = ADD32(0, -0X3B6);
    // 0x80800A48: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
    // 0x80800A4C: sh          $t7, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r15;
    // 0x80800A50: sh          $t8, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r24;
    // 0x80800A54: sh          $t9, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r25;
    // 0x80800A58: sh          $t0, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r8;
    // 0x80800A5C: sh          $t1, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r9;
    // 0x80800A60: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800A64: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800A68: lwc1        $f4, 0x38($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80800A6C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800A70: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800A74: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800A78: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80800A7C: sh          $t4, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r12;
    // 0x80800A80: sb          $zero, 0x18($v0)
    MEM_B(0X18, ctx->r2) = 0;
    // 0x80800A84: sb          $zero, 0x12($v0)
    MEM_B(0X12, ctx->r2) = 0;
    // 0x80800A88: sb          $zero, 0x13($v0)
    MEM_B(0X13, ctx->r2) = 0;
    // 0x80800A8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800A90: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800A94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800A98: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x80800A9C: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x80800AA0: jal         0x808017D4
    // 0x80800AA4: sh          $t3, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r11;
    chexploder_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80800AA4: sh          $t3, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r11;
    after_1:
    // 0x80800AA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800AAC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800AB0: jal         0x808017D4
    // 0x80800AB4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    chexploder_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x80800AB4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80800AB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800ABC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800AC0: jr          $ra
    // 0x80800AC4: nop

    return;
    // 0x80800AC4: nop

;}
