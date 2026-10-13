#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80801FD0_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801FD0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80801FD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801FD8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80801FDC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80801FE0: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x80801FE4: lw          $s1, 0x188($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X188);
    // 0x80801FE8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80801FEC: lwc1        $f2, 0xB4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XB4);
    // 0x80801FF0: jal         0x800D9004
    // 0x80801FF4: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    func_800D9004(rdram, ctx);
        goto after_0;
    // 0x80801FF4: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x80801FF8: lw          $v0, 0xA0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XA0);
    // 0x80801FFC: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x80802000: lwc1        $f2, 0x4C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80802004: beq         $v0, $zero, L_80802020
    if (ctx->r2 == 0) {
        // 0x80802008: subu        $t7, $t7, $s0
        ctx->r15 = SUB32(ctx->r15, ctx->r16);
            goto L_80802020;
    }
    // 0x80802008: subu        $t7, $t7, $s0
    ctx->r15 = SUB32(ctx->r15, ctx->r16);
    // 0x8080200C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80802010: beql        $v0, $at, L_80802050
    if (ctx->r2 == ctx->r1) {
        // 0x80802014: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80802050;
    }
    goto skip_0;
    // 0x80802014: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x80802018: b           L_8080207C
    // 0x8080201C: nop

        goto L_8080207C;
    // 0x8080201C: nop

L_80802020:
    // 0x80802020: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80802024: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80802028: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8080202C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80802030: sub.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x80802034: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80802038: nop

    // 0x8080203C: bc1f        L_8080207C
    if (!c1cs) {
        // 0x80802040: nop
    
            goto L_8080207C;
    }
    // 0x80802040: nop

    // 0x80802044: b           L_8080207C
    // 0x80802048: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
        goto L_8080207C;
    // 0x80802048: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8080204C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80802050:
    // 0x80802050: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80802054: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80802058: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080205C: nop

    // 0x80802060: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80802064: add.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x80802068: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x8080206C: nop

    // 0x80802070: bc1f        L_8080207C
    if (!c1cs) {
        // 0x80802074: nop
    
            goto L_8080207C;
    }
    // 0x80802074: nop

    // 0x80802078: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_8080207C:
    // 0x8080207C: lui         $t8, 0x8081
    ctx->r24 = S32(RELOC_HI16(439, 0XA5D0) << 16);
    // 0x80802080: addiu       $t8, $t8, -0x5A30
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(439, 0XA5D0));
    // 0x80802084: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80802088: swc1        $f2, 0xB4($s1)
    MEM_W(0XB4, ctx->r17) = ctx->f2.u32l;
    // 0x8080208C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80802090: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80802094: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80802098: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8080209C: lwc1        $f14, 0x8($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X8);
    // 0x808020A0: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x808020A4: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x808020A8: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x808020AC: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x808020B0: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x808020B4: sub.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x808020B8: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x808020BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808020C0: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x808020C4: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x808020C8: sub.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x808020CC: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    // 0x808020D0: lwc1        $f4, 0x24($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X24);
    // 0x808020D4: add.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x808020D8: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x808020DC: sub.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x808020E0: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    // 0x808020E4: lwc1        $f4, 0x28($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X28);
    // 0x808020E8: add.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x808020EC: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x808020F0: sub.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x808020F4: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    // 0x808020F8: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x808020FC: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80802100: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80802104: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x80802108: lwc1        $f6, 0x2C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8080210C: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
    // 0x80802110: add.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80802114: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80802118: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x8080211C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80802120: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80802124: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80802128: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    // 0x8080212C: lw          $t9, 0xA8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XA8);
    // 0x80802130: bnel        $t9, $at, L_80802150
    if (ctx->r25 != ctx->r1) {
        // 0x80802134: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_80802150;
    }
    goto skip_1;
    // 0x80802134: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_1:
    // 0x80802138: lwc1        $f10, 0x168($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X168);
    // 0x8080213C: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x80802140: lwc1        $f4, 0x184($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X184);
    // 0x80802144: b           L_8080215C
    // 0x80802148: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
        goto L_8080215C;
    // 0x80802148: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x8080214C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80802150:
    // 0x80802150: nop

    // 0x80802154: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80802158: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
L_8080215C:
    // 0x8080215C: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80802160: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80802164: lui         $at, 0x4318
    ctx->r1 = S32(0X4318 << 16);
    // 0x80802168: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080216C: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80802170: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80802174: lui         $at, 0x42E4
    ctx->r1 = S32(0X42E4 << 16);
    // 0x80802178: addiu       $s0, $s1, 0xB8
    ctx->r16 = ADD32(ctx->r17, 0XB8);
    // 0x8080217C: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x80802180: add.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80802184: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80802188: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8080218C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80802190: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    // 0x80802194: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80802198: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x8080219C: jal         0x8080222C
    // 0x808021A0: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    func_8080222C_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x808021A0: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x808021A4: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x808021A8: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x808021AC: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808021B0: jal         0x8080222C
    // 0x808021B4: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    func_8080222C_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x808021B4: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    after_2:
    // 0x808021B8: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x808021BC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808021C0: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x808021C4: jal         0x80084B00
    // 0x808021C8: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    _baeggcursor_entrypoint_10(rdram, ctx);
        goto after_3;
    // 0x808021C8: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x808021CC: lui         $at, 0x4318
    ctx->r1 = S32(0X4318 << 16);
    // 0x808021D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808021D4: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x808021D8: lwc1        $f14, 0x60($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X60);
    // 0x808021DC: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x808021E0: jal         0x80802304
    // 0x808021E4: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_80802304_bsfirstp(rdram, ctx);
        goto after_4;
    // 0x808021E4: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_4:
    // 0x808021E8: addiu       $v0, $s1, 0xC0
    ctx->r2 = ADD32(ctx->r17, 0XC0);
    // 0x808021EC: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x808021F0: lui         $at, 0x42E4
    ctx->r1 = S32(0X42E4 << 16);
    // 0x808021F4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808021F8: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x808021FC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80802200: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x80802204: lwc1        $f14, 0x64($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80802208: jal         0x80802304
    // 0x8080220C: sub.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f8.fl;
    func_80802304_bsfirstp(rdram, ctx);
        goto after_5;
    // 0x8080220C: sub.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f8.fl;
    after_5:
    // 0x80802210: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80802214: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80802218: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080221C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80802220: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80802224: jr          $ra
    // 0x80802228: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80802228: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void chlavaexplodbuild_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800280: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2068, 0X2E0) << 16);
    // 0x80800284: jr          $ra
    // 0x80800288: addiu       $v0, $v0, 0x2E0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2068, 0X2E0));
    return;
    // 0x80800288: addiu       $v0, $v0, 0x2E0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2068, 0X2E0));
    // 0x8080028C: nop

;}
RECOMP_FUNC void _sucoasterfly_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089EE0: syscall     813
    recomp_syscall_handler(rdram, ctx, 0x80089EE0);
    return;
    // 0x80089EE4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _chchuffyglow_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086D88: syscall     450
    recomp_syscall_handler(rdram, ctx, 0x80086D88);
    return;
    // 0x80086D8C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void yaw_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C830: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009C834: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009C838: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8009C83C: lw          $t6, 0xF8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XF8);
    // 0x8009C840: lui         $a1, 0x442F
    ctx->r5 = S32(0X442F << 16);
    // 0x8009C844: lui         $a2, 0x40F0
    ctx->r6 = S32(0X40F0 << 16);
    // 0x8009C848: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    // 0x8009C84C: lw          $t7, 0xF8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XF8);
    // 0x8009C850: swc1        $f0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f0.u32l;
    // 0x8009C854: jal         0x8009C99C
    // 0x8009C858: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    yaw_setVelocityBounded(rdram, ctx);
        goto after_0;
    // 0x8009C858: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8009C85C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8009C860: jal         0x8009C9B8
    // 0x8009C864: lui         $a1, 0x43B4
    ctx->r5 = S32(0X43B4 << 16);
    yaw_setVelocityUnbounded(rdram, ctx);
        goto after_1;
    // 0x8009C864: lui         $a1, 0x43B4
    ctx->r5 = S32(0X43B4 << 16);
    after_1:
    // 0x8009C868: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8009C86C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8009C870: lw          $t8, 0xF8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XF8);
    // 0x8009C874: jal         0x8009C908
    // 0x8009C878: sw          $zero, 0xC($t8)
    MEM_W(0XC, ctx->r24) = 0;
    yaw_setUpdateType(rdram, ctx);
        goto after_2;
    // 0x8009C878: sw          $zero, 0xC($t8)
    MEM_W(0XC, ctx->r24) = 0;
    after_2:
    // 0x8009C87C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009C880: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009C884: jr          $ra
    // 0x8009C888: nop

    return;
    // 0x8009C888: nop

;}
RECOMP_FUNC void func_800CE3E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE3E0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800CE3E4: addiu       $t7, $t7, -0x4FD0
    ctx->r15 = ADD32(ctx->r15, -0X4FD0);
    // 0x800CE3E8: sll         $t6, $a0, 5
    ctx->r14 = S32(ctx->r4 << 5);
    // 0x800CE3EC: jr          $ra
    // 0x800CE3F0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    return;
    // 0x800CE3F0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
;}
RECOMP_FUNC void func_80800000_glgamestore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x80088710
    // 0x8080000C: nop

    _glcrc_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080000C: nop

    after_0:
    // 0x80800010: beq         $v0, $zero, L_8080001C
    if (ctx->r2 == 0) {
        // 0x80800014: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8080001C;
    }
    // 0x80800014: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800018: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_8080001C:
    // 0x8080001C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800020: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800024: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800028: jr          $ra
    // 0x8080002C: nop

    return;
    // 0x8080002C: nop

;}
RECOMP_FUNC void func_800FC124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC124: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800FC128: lh          $t6, 0x5988($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X5988);
    // 0x800FC12C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FC130: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FC134: beq         $a0, $t6, L_800FC198
    if (ctx->r4 == ctx->r14) {
        // 0x800FC138: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_800FC198;
    }
    // 0x800FC138: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800FC13C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FC140: addiu       $a0, $a0, 0x5960
    ctx->r4 = ADD32(ctx->r4, 0X5960);
    // 0x800FC144: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800FC148: jal         0x800FB6E0
    // 0x800FC14C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800FB6E0(rdram, ctx);
        goto after_0;
    // 0x800FC14C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x800FC150: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800FC154: jal         0x800172D4
    // 0x800FC158: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800172D4(rdram, ctx);
        goto after_1;
    // 0x800FC158: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_1:
    // 0x800FC15C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800FC160: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FC164: jal         0x80017764
    // 0x800FC168: sh          $a0, 0x5988($at)
    MEM_H(0X5988, ctx->r1) = ctx->r4;
    func_80017764(rdram, ctx);
        goto after_2;
    // 0x800FC168: sh          $a0, 0x5988($at)
    MEM_H(0X5988, ctx->r1) = ctx->r4;
    after_2:
    // 0x800FC16C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FC170: sw          $v0, 0x5980($at)
    MEM_W(0X5980, ctx->r1) = ctx->r2;
    // 0x800FC174: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FC178: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800FC17C: sh          $zero, 0x598A($at)
    MEM_H(0X598A, ctx->r1) = 0;
    // 0x800FC180: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FC184: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FC188: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800FC18C: addiu       $a0, $a0, 0x5960
    ctx->r4 = ADD32(ctx->r4, 0X5960);
    // 0x800FC190: jal         0x800FB6C0
    // 0x800FC194: swc1        $f4, 0x5964($at)
    MEM_W(0X5964, ctx->r1) = ctx->f4.u32l;
    func_800FB6C0(rdram, ctx);
        goto after_3;
    // 0x800FC194: swc1        $f4, 0x5964($at)
    MEM_W(0X5964, ctx->r1) = ctx->f4.u32l;
    after_3:
L_800FC198:
    // 0x800FC198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FC19C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FC1A0: jr          $ra
    // 0x800FC1A4: nop

    return;
    // 0x800FC1A4: nop

;}
RECOMP_FUNC void func_80800018_chdiggerfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080001C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800020: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800024: jal         0x80089EC8
    // 0x80800028: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _sucoasterfly_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800028: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080002C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800030: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80800034: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800038: lwc1        $f4, 0x38($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8080003C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800040: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800044: jal         0x80102FDC
    // 0x80800048: nop

    func_80102FDC(rdram, ctx);
        goto after_1;
    // 0x80800048: nop

    after_1:
    // 0x8080004C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800050: jal         0x8010A3E8
    // 0x80800054: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    func_8010A3E8(rdram, ctx);
        goto after_2;
    // 0x80800054: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    after_2:
    // 0x80800058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080005C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800060: jr          $ra
    // 0x80800064: nop

    return;
    // 0x80800064: nop

    // 0x80800068: nop

    // 0x8080006C: nop

;}
RECOMP_FUNC void func_808002CC_chdinocoaster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002CC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808002D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002DC: jal         0x801051C8
    // 0x808002E0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_801051C8(rdram, ctx);
        goto after_0;
    // 0x808002E0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x808002E4: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808002E8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x808002EC: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x808002F0: jal         0x800F1B78
    // 0x808002F4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800F1B78(rdram, ctx);
        goto after_1;
    // 0x808002F4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x808002F8: beq         $v0, $zero, L_80800310
    if (ctx->r2 == 0) {
        // 0x808002FC: lwc1        $f4, 0x34($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
            goto L_80800310;
    }
    // 0x808002FC: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800300: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
    // 0x80800304: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800308: b           L_80800320
    // 0x8080030C: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
        goto L_80800320;
    // 0x8080030C: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
L_80800310:
    // 0x80800310: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800314: nop

    // 0x80800318: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x8080031C: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
L_80800320:
    // 0x80800320: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x80800324: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x80800328: bltz        $t8, L_80800350
    if (SIGNED(ctx->r24) < 0) {
        // 0x8080032C: nop
    
            goto L_80800350;
    }
    // 0x8080032C: nop

    // 0x80800330: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x80800334: lwc1        $f8, 0x50($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80800338: lwc1        $f10, 0x28($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8080033C: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x80800340: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    // 0x80800344: swc1        $f8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f8.u32l;
    // 0x80800348: b           L_808003A8
    // 0x8080034C: swc1        $f10, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f10.u32l;
        goto L_808003A8;
    // 0x8080034C: swc1        $f10, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f10.u32l;
L_80800350:
    // 0x80800350: jal         0x800D8FF8
    // 0x80800354: nop

    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x80800354: nop

    after_2:
    // 0x80800358: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8080035C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800360: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80800364: lwc1        $f14, 0x50($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80800368: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8080036C: lwc1        $f12, 0x44($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80800370: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80800374: jal         0x800F1F38
    // 0x80800378: nop

    func_800F1F38(rdram, ctx);
        goto after_3;
    // 0x80800378: nop

    after_3:
    // 0x8080037C: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x80800380: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800384: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800388: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8080038C: lwc1        $f12, 0x4C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80800390: lwc1        $f14, 0x28($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80800394: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800398: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8080039C: jal         0x800F1F38
    // 0x808003A0: nop

    func_800F1F38(rdram, ctx);
        goto after_4;
    // 0x808003A0: nop

    after_4:
    // 0x808003A4: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
L_808003A8:
    // 0x808003A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003B0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808003B4: jr          $ra
    // 0x808003B8: nop

    return;
    // 0x808003B8: nop

    // 0x808003BC: nop

;}
RECOMP_FUNC void func_80800238_chjamjarsdummy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800238: jr          $ra
    // 0x8080023C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8080023C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80800484_bsmum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800484: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800488: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080048C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800490: jal         0x80085228
    // 0x80800494: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _basudie_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x80800494: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080049C: jal         0x8009B9B0
    // 0x808004A0: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_1;
    // 0x808004A0: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    after_1:
    // 0x808004A4: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    // 0x808004A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808004AC: beq         $v0, $at, L_808004CC
    if (ctx->r2 == ctx->r1) {
        // 0x808004B0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808004CC;
    }
    // 0x808004B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808004B4: beq         $v0, $at, L_808004EC
    if (ctx->r2 == ctx->r1) {
        // 0x808004B8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808004EC;
    }
    // 0x808004B8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808004BC: beql        $v0, $at, L_80800510
    if (ctx->r2 == ctx->r1) {
        // 0x808004C0: mtc1        $zero, $f12
        ctx->f12.u32l = 0;
            goto L_80800510;
    }
    goto skip_0;
    // 0x808004C0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    skip_0:
    // 0x808004C4: b           L_8080053C
    // 0x808004C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080053C;
    // 0x808004C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808004CC:
    // 0x808004CC: jal         0x8008E078
    // 0x808004D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_2;
    // 0x808004D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808004D4: beq         $v0, $zero, L_80800538
    if (ctx->r2 == 0) {
        // 0x808004D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800538;
    }
    // 0x808004D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004DC: jal         0x808002B8
    // 0x808004E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808002B8_bsmum(rdram, ctx);
        goto after_3;
    // 0x808004E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x808004E4: b           L_8080053C
    // 0x808004E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080053C;
    // 0x808004E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808004EC:
    // 0x808004EC: jal         0x8008E078
    // 0x808004F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_4;
    // 0x808004F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808004F4: beq         $v0, $zero, L_80800538
    if (ctx->r2 == 0) {
        // 0x808004F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800538;
    }
    // 0x808004F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004FC: jal         0x808002B8
    // 0x80800500: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808002B8_bsmum(rdram, ctx);
        goto after_5;
    // 0x80800500: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x80800504: b           L_8080053C
    // 0x80800508: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080053C;
    // 0x80800508: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080050C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
L_80800510:
    // 0x80800510: lwc1        $f0, 0x16C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x80800514: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800518: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8080051C: nop

    // 0x80800520: bc1fl       L_8080053C
    if (!c1cs) {
        // 0x80800524: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080053C;
    }
    goto skip_1;
    // 0x80800524: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800528: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080052C: jal         0x800F0E00
    // 0x80800530: sub.s       $f14, $f0, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f4.fl;
    func_800F0E00(rdram, ctx);
        goto after_6;
    // 0x80800530: sub.s       $f14, $f0, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f4.fl;
    after_6:
    // 0x80800534: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
L_80800538:
    // 0x80800538: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080053C:
    // 0x8080053C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800540: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800544: jr          $ra
    // 0x80800548: nop

    return;
    // 0x80800548: nop

;}
RECOMP_FUNC void gspropprop_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800154: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800158: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080015C: lhu         $t6, 0xA($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA);
    // 0x80800160: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800164: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80800168: beql        $t7, $zero, L_80800188
    if (ctx->r15 == 0) {
        // 0x8080016C: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80800188;
    }
    goto skip_0;
    // 0x8080016C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    skip_0:
    // 0x80800170: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80800174: jal         0x800EC3E8
    // 0x80800178: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    func_800EC3E8(rdram, ctx);
        goto after_0;
    // 0x80800178: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    after_0:
    // 0x8080017C: b           L_8080019C
    // 0x80800180: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
        goto L_8080019C;
    // 0x80800180: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x80800184: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_80800188:
    // 0x80800188: jal         0x80088C90
    // 0x8080018C: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    _gsproplookup_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x8080018C: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    after_1:
    // 0x80800190: jal         0x800BFC94
    // 0x80800194: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800BFC94(rdram, ctx);
        goto after_2;
    // 0x80800194: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800198: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
L_8080019C:
    // 0x8080019C: beql        $v0, $zero, L_80800508
    if (ctx->r2 == 0) {
        // 0x808001A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800508;
    }
    goto skip_1;
    // 0x808001A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808001A4: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x808001A8: addiu       $ra, $zero, 0x1
    ctx->r31 = ADD32(0, 0X1);
    // 0x808001AC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808001B0: sll         $a1, $v1, 4
    ctx->r5 = S32(ctx->r3 << 4);
    // 0x808001B4: srl         $t8, $a1, 29
    ctx->r24 = S32(U32(ctx->r5) >> 29);
    // 0x808001B8: beq         $t8, $zero, L_80800504
    if (ctx->r24 == 0) {
        // 0x808001BC: srl         $t0, $v1, 28
        ctx->r8 = S32(U32(ctx->r3) >> 28);
            goto L_80800504;
    }
    // 0x808001BC: srl         $t0, $v1, 28
    ctx->r8 = S32(U32(ctx->r3) >> 28);
    // 0x808001C0: sll         $a3, $v1, 7
    ctx->r7 = S32(ctx->r3 << 7);
    // 0x808001C4: sll         $t2, $v1, 9
    ctx->r10 = S32(ctx->r3 << 9);
    // 0x808001C8: xor         $t3, $t8, $ra
    ctx->r11 = ctx->r24 ^ ctx->r31;
    // 0x808001CC: srl         $t9, $a3, 30
    ctx->r25 = S32(U32(ctx->r7) >> 30);
    // 0x808001D0: srl         $t6, $t2, 30
    ctx->r14 = S32(U32(ctx->r10) >> 30);
    // 0x808001D4: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x808001D8: or          $t1, $t8, $zero
    ctx->r9 = ctx->r24 | 0;
    // 0x808001DC: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x808001E0: or          $t2, $t6, $zero
    ctx->r10 = ctx->r14 | 0;
    // 0x808001E4: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    // 0x808001E8: bne         $t3, $zero, L_808001F8
    if (ctx->r11 != 0) {
        // 0x808001EC: or          $a0, $t3, $zero
        ctx->r4 = ctx->r11 | 0;
            goto L_808001F8;
    }
    // 0x808001EC: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x808001F0: xori        $a0, $t8, 0x2
    ctx->r4 = ctx->r24 ^ 0X2;
    // 0x808001F4: sltiu       $a0, $a0, 0x1
    ctx->r4 = ctx->r4 < 0X1 ? 1 : 0;
L_808001F8:
    // 0x808001F8: bne         $t1, $at, L_80800208
    if (ctx->r9 != ctx->r1) {
        // 0x808001FC: sw          $a0, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r4;
            goto L_80800208;
    }
    // 0x808001FC: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x80800200: b           L_80800214
    // 0x80800204: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
        goto L_80800214;
    // 0x80800204: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
L_80800208:
    // 0x80800208: subu        $a1, $t4, $a0
    ctx->r5 = SUB32(ctx->r12, ctx->r4);
    // 0x8080020C: sll         $t7, $a1, 1
    ctx->r15 = S32(ctx->r5 << 1);
    // 0x80800210: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
L_80800214:
    // 0x80800214: lhu         $t8, 0xA($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0XA);
    // 0x80800218: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x8080021C: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x80800220: sll         $t9, $t8, 21
    ctx->r25 = S32(ctx->r24 << 21);
    // 0x80800224: srl         $t6, $t9, 27
    ctx->r14 = S32(U32(ctx->r25) >> 27);
    // 0x80800228: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8080022C: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x80800230: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x80800234: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    // 0x80800238: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    // 0x8080023C: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80800240: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x80800244: mflo        $t7
    ctx->r15 = lo;
    // 0x80800248: bgez        $t7, L_80800258
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8080024C: sra         $t8, $t7, 5
        ctx->r24 = S32(SIGNED(ctx->r15) >> 5);
            goto L_80800258;
    }
    // 0x8080024C: sra         $t8, $t7, 5
    ctx->r24 = S32(SIGNED(ctx->r15) >> 5);
    // 0x80800250: addiu       $at, $t7, 0x1F
    ctx->r1 = ADD32(ctx->r15, 0X1F);
    // 0x80800254: sra         $t8, $at, 5
    ctx->r24 = S32(SIGNED(ctx->r1) >> 5);
L_80800258:
    // 0x80800258: jal         0x8001211C
    // 0x8080025C: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    func_8001211C(rdram, ctx);
        goto after_3;
    // 0x8080025C: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    after_3:
    // 0x80800260: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800264: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x80800268: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8080026C: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80800270: multu       $a1, $t0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800274: addiu       $ra, $zero, 0x1
    ctx->r31 = ADD32(0, 0X1);
    // 0x80800278: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x8080027C: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80800280: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80800284: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80800288: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8080028C: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x80800290: mflo        $t9
    ctx->r25 = lo;
    // 0x80800294: nop

    // 0x80800298: nop

    // 0x8080029C: div         $zero, $v0, $t9
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r25))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r25)));
    // 0x808002A0: mfhi        $t6
    ctx->r14 = hi;
    // 0x808002A4: bne         $t9, $zero, L_808002B0
    if (ctx->r25 != 0) {
        // 0x808002A8: nop
    
            goto L_808002B0;
    }
    // 0x808002A8: nop

    // 0x808002AC: break       7
    do_break(2155872940);
L_808002B0:
    // 0x808002B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808002B4: bne         $t9, $at, L_808002C8
    if (ctx->r25 != ctx->r1) {
        // 0x808002B8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_808002C8;
    }
    // 0x808002B8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808002BC: bne         $v0, $at, L_808002C8
    if (ctx->r2 != ctx->r1) {
        // 0x808002C0: nop
    
            goto L_808002C8;
    }
    // 0x808002C0: nop

    // 0x808002C4: break       6
    do_break(2155872964);
L_808002C8:
    // 0x808002C8: div         $zero, $t6, $t0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r8)));
    // 0x808002CC: mflo        $t7
    ctx->r15 = lo;
    // 0x808002D0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x808002D4: bne         $t0, $zero, L_808002E0
    if (ctx->r8 != 0) {
        // 0x808002D8: nop
    
            goto L_808002E0;
    }
    // 0x808002D8: nop

    // 0x808002DC: break       7
    do_break(2155872988);
L_808002E0:
    // 0x808002E0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808002E4: bne         $t0, $at, L_808002F8
    if (ctx->r8 != ctx->r1) {
        // 0x808002E8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_808002F8;
    }
    // 0x808002E8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808002EC: bne         $t6, $at, L_808002F8
    if (ctx->r14 != ctx->r1) {
        // 0x808002F0: nop
    
            goto L_808002F8;
    }
    // 0x808002F0: nop

    // 0x808002F4: break       6
    do_break(2155873012);
L_808002F8:
    // 0x808002F8: div         $zero, $t9, $a1
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r5)));
    // 0x808002FC: mfhi        $a0
    ctx->r4 = hi;
    // 0x80800300: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80800304: bne         $a1, $zero, L_80800310
    if (ctx->r5 != 0) {
        // 0x80800308: nop
    
            goto L_80800310;
    }
    // 0x80800308: nop

    // 0x8080030C: break       7
    do_break(2155873036);
L_80800310:
    // 0x80800310: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800314: bne         $a1, $at, L_80800328
    if (ctx->r5 != ctx->r1) {
        // 0x80800318: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80800328;
    }
    // 0x80800318: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8080031C: bne         $t9, $at, L_80800328
    if (ctx->r25 != ctx->r1) {
        // 0x80800320: nop
    
            goto L_80800328;
    }
    // 0x80800320: nop

    // 0x80800324: break       6
    do_break(2155873060);
L_80800328:
    // 0x80800328: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8080032C: beql        $a3, $ra, L_80800354
    if (ctx->r7 == ctx->r31) {
        // 0x80800330: lhu         $t6, 0xA($a2)
        ctx->r14 = MEM_HU(ctx->r6, 0XA);
            goto L_80800354;
    }
    goto skip_2;
    // 0x80800330: lhu         $t6, 0xA($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0XA);
    skip_2:
    // 0x80800334: beq         $a3, $v0, L_80800380
    if (ctx->r7 == ctx->r2) {
        // 0x80800338: nop
    
            goto L_80800380;
    }
    // 0x80800338: nop

    // 0x8080033C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800340: beql        $a3, $at, L_8080038C
    if (ctx->r7 == ctx->r1) {
        // 0x80800344: lhu         $a3, 0x2($a2)
        ctx->r7 = MEM_HU(ctx->r6, 0X2);
            goto L_8080038C;
    }
    goto skip_3;
    // 0x80800344: lhu         $a3, 0x2($a2)
    ctx->r7 = MEM_HU(ctx->r6, 0X2);
    skip_3:
    // 0x80800348: b           L_80800394
    // 0x8080034C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
        goto L_80800394;
    // 0x8080034C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800350: lhu         $t6, 0xA($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0XA);
L_80800354:
    // 0x80800354: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800358: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8080035C: sll         $t7, $t6, 21
    ctx->r15 = S32(ctx->r14 << 21);
    // 0x80800360: srl         $t8, $t7, 27
    ctx->r24 = S32(U32(ctx->r15) >> 27);
    // 0x80800364: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x80800368: beq         $t9, $zero, L_80800378
    if (ctx->r25 == 0) {
        // 0x8080036C: nop
    
            goto L_80800378;
    }
    // 0x8080036C: nop

    // 0x80800370: b           L_80800394
    // 0x80800374: or          $a3, $ra, $zero
    ctx->r7 = ctx->r31 | 0;
        goto L_80800394;
    // 0x80800374: or          $a3, $ra, $zero
    ctx->r7 = ctx->r31 | 0;
L_80800378:
    // 0x80800378: b           L_80800394
    // 0x8080037C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80800394;
    // 0x8080037C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80800380:
    // 0x80800380: b           L_80800394
    // 0x80800384: or          $a3, $ra, $zero
    ctx->r7 = ctx->r31 | 0;
        goto L_80800394;
    // 0x80800384: or          $a3, $ra, $zero
    ctx->r7 = ctx->r31 | 0;
    // 0x80800388: lhu         $a3, 0x2($a2)
    ctx->r7 = MEM_HU(ctx->r6, 0X2);
L_8080038C:
    // 0x8080038C: sll         $t6, $a3, 30
    ctx->r14 = S32(ctx->r7 << 30);
    // 0x80800390: srl         $a3, $t6, 31
    ctx->r7 = S32(U32(ctx->r14) >> 31);
L_80800394:
    // 0x80800394: bnel        $t3, $zero, L_808003BC
    if (ctx->r11 != 0) {
        // 0x80800398: slt         $t2, $a0, $t4
        ctx->r10 = SIGNED(ctx->r4) < SIGNED(ctx->r12) ? 1 : 0;
            goto L_808003BC;
    }
    goto skip_4;
    // 0x80800398: slt         $t2, $a0, $t4
    ctx->r10 = SIGNED(ctx->r4) < SIGNED(ctx->r12) ? 1 : 0;
    skip_4:
    // 0x8080039C: beql        $t1, $v0, L_808003C8
    if (ctx->r9 == ctx->r2) {
        // 0x808003A0: slt         $t5, $a0, $t4
        ctx->r13 = SIGNED(ctx->r4) < SIGNED(ctx->r12) ? 1 : 0;
            goto L_808003C8;
    }
    goto skip_5;
    // 0x808003A0: slt         $t5, $a0, $t4
    ctx->r13 = SIGNED(ctx->r4) < SIGNED(ctx->r12) ? 1 : 0;
    skip_5:
    // 0x808003A4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808003A8: bne         $t1, $at, L_808003CC
    if (ctx->r9 != ctx->r1) {
        // 0x808003AC: nop
    
            goto L_808003CC;
    }
    // 0x808003AC: nop

    // 0x808003B0: slt         $t5, $a0, $t4
    ctx->r13 = SIGNED(ctx->r4) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x808003B4: xori        $t5, $t5, 0x1
    ctx->r13 = ctx->r13 ^ 0X1;
    // 0x808003B8: slt         $t2, $a0, $t4
    ctx->r10 = SIGNED(ctx->r4) < SIGNED(ctx->r12) ? 1 : 0;
L_808003BC:
    // 0x808003BC: b           L_80800440
    // 0x808003C0: xori        $t2, $t2, 0x1
    ctx->r10 = ctx->r10 ^ 0X1;
        goto L_80800440;
    // 0x808003C0: xori        $t2, $t2, 0x1
    ctx->r10 = ctx->r10 ^ 0X1;
    // 0x808003C4: slt         $t5, $a0, $t4
    ctx->r13 = SIGNED(ctx->r4) < SIGNED(ctx->r12) ? 1 : 0;
L_808003C8:
    // 0x808003C8: xori        $t5, $t5, 0x1
    ctx->r13 = ctx->r13 ^ 0X1;
L_808003CC:
    // 0x808003CC: beql        $t2, $ra, L_808003E8
    if (ctx->r10 == ctx->r31) {
        // 0x808003D0: lhu         $t8, 0xA($a2)
        ctx->r24 = MEM_HU(ctx->r6, 0XA);
            goto L_808003E8;
    }
    goto skip_6;
    // 0x808003D0: lhu         $t8, 0xA($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0XA);
    skip_6:
    // 0x808003D4: beq         $t2, $v0, L_8080040C
    if (ctx->r10 == ctx->r2) {
        // 0x808003D8: nop
    
            goto L_8080040C;
    }
    // 0x808003D8: nop

    // 0x808003DC: b           L_80800414
    // 0x808003E0: lhu         $v0, 0xA($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0XA);
        goto L_80800414;
    // 0x808003E0: lhu         $v0, 0xA($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0XA);
    // 0x808003E4: lhu         $t8, 0xA($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0XA);
L_808003E8:
    // 0x808003E8: sll         $t9, $t8, 21
    ctx->r25 = S32(ctx->r24 << 21);
    // 0x808003EC: srl         $t6, $t9, 27
    ctx->r14 = S32(U32(ctx->r25) >> 27);
    // 0x808003F0: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x808003F4: beq         $t7, $zero, L_80800404
    if (ctx->r15 == 0) {
        // 0x808003F8: nop
    
            goto L_80800404;
    }
    // 0x808003F8: nop

    // 0x808003FC: b           L_80800440
    // 0x80800400: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_80800440;
    // 0x80800400: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_80800404:
    // 0x80800404: b           L_80800440
    // 0x80800408: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
        goto L_80800440;
    // 0x80800408: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_8080040C:
    // 0x8080040C: b           L_80800440
    // 0x80800410: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_80800440;
    // 0x80800410: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_80800414:
    // 0x80800414: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x80800418: beql        $t8, $zero, L_80800434
    if (ctx->r24 == 0) {
        // 0x8080041C: lhu         $t2, 0x2($a2)
        ctx->r10 = MEM_HU(ctx->r6, 0X2);
            goto L_80800434;
    }
    goto skip_7;
    // 0x8080041C: lhu         $t2, 0x2($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0X2);
    skip_7:
    // 0x80800420: lw          $t2, 0x8($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X8);
    // 0x80800424: sll         $t9, $t2, 26
    ctx->r25 = S32(ctx->r10 << 26);
    // 0x80800428: b           L_80800440
    // 0x8080042C: srl         $t2, $t9, 31
    ctx->r10 = S32(U32(ctx->r25) >> 31);
        goto L_80800440;
    // 0x8080042C: srl         $t2, $t9, 31
    ctx->r10 = S32(U32(ctx->r25) >> 31);
    // 0x80800430: lhu         $t2, 0x2($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0X2);
L_80800434:
    // 0x80800434: sll         $t7, $t2, 30
    ctx->r15 = S32(ctx->r10 << 30);
    // 0x80800438: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x8080043C: or          $t2, $t8, $zero
    ctx->r10 = ctx->r24 | 0;
L_80800440:
    // 0x80800440: xor         $t9, $t2, $a3
    ctx->r25 = ctx->r10 ^ ctx->r7;
    // 0x80800444: xor         $t6, $t9, $t5
    ctx->r14 = ctx->r25 ^ ctx->r13;
    // 0x80800448: beq         $t6, $zero, L_80800454
    if (ctx->r14 == 0) {
        // 0x8080044C: lw          $t7, 0x34($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X34);
            goto L_80800454;
    }
    // 0x8080044C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80800450: subu        $v1, $a1, $a0
    ctx->r3 = SUB32(ctx->r5, ctx->r4);
L_80800454:
    // 0x80800454: beq         $t7, $zero, L_80800464
    if (ctx->r15 == 0) {
        // 0x80800458: negu        $a0, $a3
        ctx->r4 = SUB32(0, ctx->r7);
            goto L_80800464;
    }
    // 0x80800458: negu        $a0, $a3
    ctx->r4 = SUB32(0, ctx->r7);
    // 0x8080045C: b           L_80800464
    // 0x80800460: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
        goto L_80800464;
    // 0x80800460: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_80800464:
    // 0x80800464: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80800468: bgez        $v1, L_80800478
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8080046C: nop
    
            goto L_80800478;
    }
    // 0x8080046C: nop

    // 0x80800470: b           L_808004AC
    // 0x80800474: addu        $v1, $v1, $t4
    ctx->r3 = ADD32(ctx->r3, ctx->r12);
        goto L_808004AC;
    // 0x80800474: addu        $v1, $v1, $t4
    ctx->r3 = ADD32(ctx->r3, ctx->r12);
L_80800478:
    // 0x80800478: div         $zero, $v1, $t4
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r12))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r12)));
    // 0x8080047C: bne         $t4, $zero, L_80800488
    if (ctx->r12 != 0) {
        // 0x80800480: nop
    
            goto L_80800488;
    }
    // 0x80800480: nop

    // 0x80800484: break       7
    do_break(2155873412);
L_80800488:
    // 0x80800488: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8080048C: bne         $t4, $at, L_808004A0
    if (ctx->r12 != ctx->r1) {
        // 0x80800490: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_808004A0;
    }
    // 0x80800490: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800494: bne         $v1, $at, L_808004A0
    if (ctx->r3 != ctx->r1) {
        // 0x80800498: nop
    
            goto L_808004A0;
    }
    // 0x80800498: nop

    // 0x8080049C: break       6
    do_break(2155873436);
L_808004A0:
    // 0x808004A0: mfhi        $v1
    ctx->r3 = hi;
    // 0x808004A4: nop

    // 0x808004A8: nop

L_808004AC:
    // 0x808004AC: lbu         $t7, 0xA($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0XA);
    // 0x808004B0: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x808004B4: andi        $t8, $t7, 0xFF07
    ctx->r24 = ctx->r15 & 0XFF07;
    // 0x808004B8: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x808004BC: sb          $t9, 0xA($a2)
    MEM_B(0XA, ctx->r6) = ctx->r25;
    // 0x808004C0: lhu         $t7, 0xA($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0XA);
    // 0x808004C4: andi        $t6, $t7, 0x1
    ctx->r14 = ctx->r15 & 0X1;
    // 0x808004C8: beql        $t6, $zero, L_808004F0
    if (ctx->r14 == 0) {
        // 0x808004CC: lbu         $t9, 0x3($a2)
        ctx->r25 = MEM_BU(ctx->r6, 0X3);
            goto L_808004F0;
    }
    goto skip_8;
    // 0x808004CC: lbu         $t9, 0x3($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X3);
    skip_8:
    // 0x808004D0: lbu         $t6, 0xB($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0XB);
    // 0x808004D4: sll         $t9, $t2, 5
    ctx->r25 = S32(ctx->r10 << 5);
    // 0x808004D8: andi        $t7, $t9, 0x20
    ctx->r15 = ctx->r25 & 0X20;
    // 0x808004DC: andi        $t8, $t6, 0xFFDF
    ctx->r24 = ctx->r14 & 0XFFDF;
    // 0x808004E0: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x808004E4: b           L_80800504
    // 0x808004E8: sb          $t9, 0xB($a2)
    MEM_B(0XB, ctx->r6) = ctx->r25;
        goto L_80800504;
    // 0x808004E8: sb          $t9, 0xB($a2)
    MEM_B(0XB, ctx->r6) = ctx->r25;
    // 0x808004EC: lbu         $t9, 0x3($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X3);
L_808004F0:
    // 0x808004F0: sll         $t7, $t2, 1
    ctx->r15 = S32(ctx->r10 << 1);
    // 0x808004F4: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x808004F8: andi        $t6, $t9, 0xFFFD
    ctx->r14 = ctx->r25 & 0XFFFD;
    // 0x808004FC: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x80800500: sb          $t7, 0x3($a2)
    MEM_B(0X3, ctx->r6) = ctx->r15;
L_80800504:
    // 0x80800504: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800508:
    // 0x80800508: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8080050C: jr          $ra
    // 0x80800510: nop

    return;
    // 0x80800510: nop

;}
RECOMP_FUNC void sccustom_big_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800280: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800284: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800288: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080028C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800290: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800294: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800298: jal         0x80800000
    // 0x8080029C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80800000_sccustom_big(rdram, ctx);
        goto after_0;
    // 0x8080029C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x808002A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808002A4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808002A8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x808002AC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x808002B0: jal         0x808000B4
    // 0x808002B4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_808000B4_sccustom_big(rdram, ctx);
        goto after_1;
    // 0x808002B4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_1:
    // 0x808002B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002C0: jr          $ra
    // 0x808002C4: nop

    return;
    // 0x808002C4: nop

;}
RECOMP_FUNC void func_800EA398(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA398: jr          $ra
    // 0x800EA39C: nop

    return;
    // 0x800EA39C: nop

;}
RECOMP_FUNC void func_8080167C_chchuffy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080167C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801680: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801684: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801688: jal         0x80088840
    // 0x8080168C: addiu       $a0, $zero, 0x72
    ctx->r4 = ADD32(0, 0X72);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_0;
    // 0x8080168C: addiu       $a0, $zero, 0x72
    ctx->r4 = ADD32(0, 0X72);
    after_0:
    // 0x80801690: beq         $v0, $zero, L_808016B8
    if (ctx->r2 == 0) {
        // 0x80801694: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_808016B8;
    }
    // 0x80801694: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80801698: jal         0x80085710
    // 0x8080169C: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_1;
    // 0x8080169C: nop

    after_1:
    // 0x808016A0: jal         0x800D9290
    // 0x808016A4: nop

    func_800D9290(rdram, ctx);
        goto after_2;
    // 0x808016A4: nop

    after_2:
    // 0x808016A8: jal         0x80088850
    // 0x808016AC: nop

    _glcutDll_entrypoint_21(rdram, ctx);
        goto after_3;
    // 0x808016AC: nop

    after_3:
    // 0x808016B0: b           L_808016C4
    // 0x808016B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808016C4;
    // 0x808016B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808016B8:
    // 0x808016B8: addiu       $t6, $zero, 0xD0
    ctx->r14 = ADD32(0, 0XD0);
    // 0x808016BC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x808016C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808016C4:
    // 0x808016C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808016C8: jr          $ra
    // 0x808016CC: nop

    return;
    // 0x808016CC: nop

;}
RECOMP_FUNC void func_8080017C_chweldarbossfireball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080017C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800180: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800184: lw          $a1, 0x34($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X34);
    // 0x80800188: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8080018C: beq         $a1, $zero, L_808001A4
    if (ctx->r5 == 0) {
        // 0x80800190: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_808001A4;
    }
    // 0x80800190: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800194: jal         0x800C8B84
    // 0x80800198: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800C8B84(rdram, ctx);
        goto after_0;
    // 0x80800198: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8080019C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808001A0: sw          $zero, 0x34($a2)
    MEM_W(0X34, ctx->r6) = 0;
L_808001A4:
    // 0x808001A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001AC: jr          $ra
    // 0x808001B0: nop

    return;
    // 0x808001B0: nop

;}
RECOMP_FUNC void func_800CF184(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF184: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800CF188: jr          $ra
    // 0x800CF18C: sb          $zero, -0x4E94($at)
    MEM_B(-0X4E94, ctx->r1) = 0;
    return;
    // 0x800CF18C: sb          $zero, -0x4E94($at)
    MEM_B(-0X4E94, ctx->r1) = 0;
;}
RECOMP_FUNC void func_80016864(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016864: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80016868: addiu       $a3, $t6, -0x6620
    ctx->r7 = ADD32(ctx->r14, -0X6620);
    // 0x8001686C: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80016870: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80016874: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x80016878: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001687C: addiu       $t1, $t1, -0x6540
    ctx->r9 = ADD32(ctx->r9, -0X6540);
    // 0x80016880: addiu       $a0, $a0, -0x6640
    ctx->r4 = ADD32(ctx->r4, -0X6640);
    // 0x80016884: addiu       $v1, $v1, -0x6508
    ctx->r3 = ADD32(ctx->r3, -0X6508);
    // 0x80016888: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8001688C: addiu       $t0, $zero, 0xE
    ctx->r8 = ADD32(0, 0XE);
L_80016890:
    // 0x80016890: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x80016894: sh          $zero, 0x2($v1)
    MEM_H(0X2, ctx->r3) = 0;
    // 0x80016898: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x8001689C: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x800168A0: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x800168A4: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
    // 0x800168A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800168AC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
L_800168B0:
    // 0x800168B0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800168B4: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800168B8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800168BC: bne         $at, $zero, L_800168B0
    if (ctx->r1 != 0) {
        // 0x800168C0: sw          $zero, -0x4($a1)
        MEM_W(-0X4, ctx->r5) = 0;
            goto L_800168B0;
    }
    // 0x800168C0: sw          $zero, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = 0;
    // 0x800168C4: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x800168C8: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x800168CC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800168D0: addiu       $a1, $a2, 0x8
    ctx->r5 = ADD32(ctx->r6, 0X8);
L_800168D4:
    // 0x800168D4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800168D8: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800168DC: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    // 0x800168E0: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
    // 0x800168E4: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800168E8: bne         $v0, $t0, L_800168D4
    if (ctx->r2 != ctx->r8) {
        // 0x800168EC: sw          $zero, -0x10($a1)
        MEM_W(-0X10, ctx->r5) = 0;
            goto L_800168D4;
    }
    // 0x800168EC: sw          $zero, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = 0;
    // 0x800168F0: addiu       $a3, $a3, 0x38
    ctx->r7 = ADD32(ctx->r7, 0X38);
    // 0x800168F4: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800168F8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x800168FC: bne         $a3, $t1, L_80016890
    if (ctx->r7 != ctx->r9) {
        // 0x80016900: addiu       $a2, $a2, 0x38
        ctx->r6 = ADD32(ctx->r6, 0X38);
            goto L_80016890;
    }
    // 0x80016900: addiu       $a2, $a2, 0x38
    ctx->r6 = ADD32(ctx->r6, 0X38);
    // 0x80016904: jr          $ra
    // 0x80016908: nop

    return;
    // 0x80016908: nop

;}
RECOMP_FUNC void func_8080000C_chgruntyfireball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x80800018: jal         0x80109EEC
    // 0x8080001C: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_80109EEC(rdram, ctx);
        goto after_0;
    // 0x8080001C: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_0:
    // 0x80800020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800024: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800028: jr          $ra
    // 0x8080002C: nop

    return;
    // 0x8080002C: nop

;}
RECOMP_FUNC void func_80800000_scinfobar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80800004: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x80800008: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(3338, 0X8B0) << 16);
    // 0x8080000C: addiu       $t7, $t7, 0x8B0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(3338, 0X8B0));
    // 0x80800010: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800014: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80800018: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8080001C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800020: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800024: sll         $t8, $v0, 17
    ctx->r24 = S32(ctx->r2 << 17);
    // 0x80800028: sra         $v0, $t8, 17
    ctx->r2 = S32(SIGNED(ctx->r24) >> 17);
    // 0x8080002C: beq         $v0, $zero, L_8080009C
    if (ctx->r2 == 0) {
        // 0x80800030: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_8080009C;
    }
    // 0x80800030: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800034: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80800038: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x8080003C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800040: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800044: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x80800048: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x8080004C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x80800050: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800054: jal         0x800E8B74
    // 0x80800058: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    func_800E8B74(rdram, ctx);
        goto after_0;
    // 0x80800058: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x8080005C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800060: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80800064: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x80800068: sb          $v0, 0x32($a3)
    MEM_B(0X32, ctx->r7) = ctx->r2;
    // 0x8080006C: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
    // 0x80800070: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800074: beql        $a1, $zero, L_8080008C
    if (ctx->r5 == 0) {
        // 0x80800078: lbu         $a0, 0x32($a3)
        ctx->r4 = MEM_BU(ctx->r7, 0X32);
            goto L_8080008C;
    }
    goto skip_0;
    // 0x80800078: lbu         $a0, 0x32($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X32);
    skip_0:
    // 0x8080007C: jal         0x800E8D5C
    // 0x80800080: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_800E8D5C(rdram, ctx);
        goto after_1;
    // 0x80800080: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x80800084: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800088: lbu         $a0, 0x32($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X32);
L_8080008C:
    // 0x8080008C: jal         0x800E8D28
    // 0x80800090: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800E8D28(rdram, ctx);
        goto after_2;
    // 0x80800090: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800094: b           L_808000A4
    // 0x80800098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808000A4;
    // 0x80800098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080009C:
    // 0x8080009C: sb          $zero, 0x32($a3)
    MEM_B(0X32, ctx->r7) = 0;
    // 0x808000A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000A4:
    // 0x808000A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000A8: jr          $ra
    // 0x808000AC: nop

    return;
    // 0x808000AC: nop

;}
RECOMP_FUNC void func_800FCB9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FCB9C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800FCBA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FCBA4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800FCBA8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800FCBAC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800FCBB0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800FCBB4: jal         0x800FB5F8
    // 0x800FCBB8: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    func_800FB5F8(rdram, ctx);
        goto after_0;
    // 0x800FCBB8: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800FCBBC: beq         $v0, $zero, L_800FCCC0
    if (ctx->r2 == 0) {
        // 0x800FCBC0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800FCCC0;
    }
    // 0x800FCBC0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800FCBC4: lh          $t6, 0x28($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X28);
    // 0x800FCBC8: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800FCBCC: bgezl       $t6, L_800FCC48
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800FCBD0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800FCC48;
    }
    goto skip_0;
    // 0x800FCBD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x800FCBD4: beq         $t7, $zero, L_800FCCC0
    if (ctx->r15 == 0) {
        // 0x800FCBD8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800FCCC0;
    }
    // 0x800FCBD8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800FCBDC: jal         0x800FB6E0
    // 0x800FCBE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800FB6E0(rdram, ctx);
        goto after_1;
    // 0x800FCBE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x800FCBE4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800FCBE8: addiu       $t8, $t8, 0x57D0
    ctx->r24 = ADD32(ctx->r24, 0X57D0);
    // 0x800FCBEC: subu        $a0, $s0, $t8
    ctx->r4 = SUB32(ctx->r16, ctx->r24);
    // 0x800FCBF0: addiu       $at, $zero, 0x50
    ctx->r1 = ADD32(0, 0X50);
    // 0x800FCBF4: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x800FCBF8: mflo        $t9
    ctx->r25 = lo;
    // 0x800FCBFC: andi        $a0, $t9, 0xFF
    ctx->r4 = ctx->r25 & 0XFF;
    // 0x800FCC00: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x800FCC04: jal         0x800172D4
    // 0x800FCC08: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800172D4(rdram, ctx);
        goto after_2;
    // 0x800FCC08: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x800FCC0C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800FCC10: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800FCC14: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x800FCC18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800FCC1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800FCC20: sh          $t1, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r9;
    // 0x800FCC24: jal         0x800FB6C0
    // 0x800FCC28: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    func_800FB6C0(rdram, ctx);
        goto after_3;
    // 0x800FCC28: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    after_3:
    // 0x800FCC2C: lbu         $t2, 0x34($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X34);
    // 0x800FCC30: lbu         $a0, 0x27($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X27);
    // 0x800FCC34: bnel        $t2, $zero, L_800FCC48
    if (ctx->r10 != 0) {
        // 0x800FCC38: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800FCC48;
    }
    goto skip_1;
    // 0x800FCC38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x800FCC3C: jal         0x80017404
    // 0x800FCC40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80017404(rdram, ctx);
        goto after_4;
    // 0x800FCC40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x800FCC44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800FCC48:
    // 0x800FCC48: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x800FCC4C: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x800FCC50: jal         0x800FBF9C
    // 0x800FCC54: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    func_800FBF9C(rdram, ctx);
        goto after_5;
    // 0x800FCC54: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    after_5:
    // 0x800FCC58: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800FCC5C: lw          $t3, 0x20($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X20);
    // 0x800FCC60: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    // 0x800FCC64: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800FCC68: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800FCC6C: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800FCC70: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800FCC74: beq         $at, $zero, L_800FCC84
    if (ctx->r1 == 0) {
        // 0x800FCC78: negu        $t7, $t6
        ctx->r15 = SUB32(0, ctx->r14);
            goto L_800FCC84;
    }
    // 0x800FCC78: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x800FCC7C: b           L_800FCC88
    // 0x800FCC80: sh          $t5, 0x2A($s0)
    MEM_H(0X2A, ctx->r16) = ctx->r13;
        goto L_800FCC88;
    // 0x800FCC80: sh          $t5, 0x2A($s0)
    MEM_H(0X2A, ctx->r16) = ctx->r13;
L_800FCC84:
    // 0x800FCC84: sh          $t7, 0x2A($s0)
    MEM_H(0X2A, ctx->r16) = ctx->r15;
L_800FCC88:
    // 0x800FCC88: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800FCC8C: sw          $t8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r24;
    // 0x800FCC90: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x800FCC94: beq         $t9, $zero, L_800FCCAC
    if (ctx->r25 == 0) {
        // 0x800FCC98: nop
    
            goto L_800FCCAC;
    }
    // 0x800FCC98: nop

    // 0x800FCC9C: jal         0x800FB540
    // 0x800FCCA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FB540(rdram, ctx);
        goto after_6;
    // 0x800FCCA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x800FCCA4: b           L_800FCCB8
    // 0x800FCCA8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_800FCCB8;
    // 0x800FCCA8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800FCCAC:
    // 0x800FCCAC: jal         0x800FB5BC
    // 0x800FCCB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FB5BC(rdram, ctx);
        goto after_7;
    // 0x800FCCB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x800FCCB4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800FCCB8:
    // 0x800FCCB8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FCCBC: sb          $t0, 0x59B0($at)
    MEM_B(0X59B0, ctx->r1) = ctx->r8;
L_800FCCC0:
    // 0x800FCCC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FCCC4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800FCCC8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800FCCCC: jr          $ra
    // 0x800FCCD0: nop

    return;
    // 0x800FCCD0: nop

;}
RECOMP_FUNC void glintrosyncDll_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003E8: jal         0x80088268
    // 0x808003EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _gcsectionDll_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808003EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808003F0: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x808003F4: bne         $v0, $at, L_80800410
    if (ctx->r2 != ctx->r1) {
        // 0x808003F8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800410;
    }
    // 0x808003F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808003FC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80800400: addiu       $a1, $a1, 0x75D0
    ctx->r5 = ADD32(ctx->r5, 0X75D0);
    // 0x80800404: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800408: b           L_8080041C
    // 0x8080040C: sb          $t6, 0x10($a1)
    MEM_B(0X10, ctx->r5) = ctx->r14;
        goto L_8080041C;
    // 0x8080040C: sb          $t6, 0x10($a1)
    MEM_B(0X10, ctx->r5) = ctx->r14;
L_80800410:
    // 0x80800410: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80800414: addiu       $a1, $a1, 0x75D0
    ctx->r5 = ADD32(ctx->r5, 0X75D0);
    // 0x80800418: sb          $zero, 0x10($a1)
    MEM_B(0X10, ctx->r5) = 0;
L_8080041C:
    // 0x8080041C: lbu         $t7, 0x10($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X10);
    // 0x80800420: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800424: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800428: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2738, 0X4F8) << 16);
    // 0x8080042C: beq         $t7, $zero, L_80800464
    if (ctx->r15 == 0) {
        // 0x80800430: swc1        $f4, 0xC($a1)
        MEM_W(0XC, ctx->r5) = ctx->f4.u32l;
            goto L_80800464;
    }
    // 0x80800430: swc1        $f4, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f4.u32l;
    // 0x80800434: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(2738, 0X5D0) << 16);
    // 0x80800438: addiu       $v1, $v1, 0x5D0
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(2738, 0X5D0));
    // 0x8080043C: addiu       $v0, $v0, 0x4F8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2738, 0X4F8));
    // 0x80800440: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
L_80800444:
    // 0x80800444: bnel        $a0, $t8, L_8080045C
    if (ctx->r4 != ctx->r24) {
        // 0x80800448: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_8080045C;
    }
    goto skip_0;
    // 0x80800448: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    skip_0:
    // 0x8080044C: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80800450: b           L_80800464
    // 0x80800454: swc1        $f6, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f6.u32l;
        goto L_80800464;
    // 0x80800454: swc1        $f6, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f6.u32l;
    // 0x80800458: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_8080045C:
    // 0x8080045C: bnel        $v0, $v1, L_80800444
    if (ctx->r2 != ctx->r3) {
        // 0x80800460: lw          $t8, 0x0($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X0);
            goto L_80800444;
    }
    goto skip_1;
    // 0x80800460: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    skip_1:
L_80800464:
    // 0x80800464: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800468: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080046C: jr          $ra
    // 0x80800470: nop

    return;
    // 0x80800470: nop

    // 0x80800474: nop

    // 0x80800478: nop

    // 0x8080047C: nop

;}
RECOMP_FUNC void _glglobalsettings_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800886D8: syscall     699
    recomp_syscall_handler(rdram, ctx, 0x800886D8);
    return;
    // 0x800886DC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80090E40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090E40: jr          $ra
    // 0x80090E44: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    return;
    // 0x80090E44: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_80800E20_chevilspirit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E20: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800E24: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800E28: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800E2C: beq         $t6, $at, L_80800F84
    if (ctx->r14 == ctx->r1) {
        // 0x80800E30: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800F84;
    }
    // 0x80800E30: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800E34: beq         $t6, $at, L_80800F84
    if (ctx->r14 == ctx->r1) {
        // 0x80800E38: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800F84;
    }
    // 0x80800E38: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800E3C: beq         $t6, $at, L_80800F84
    if (ctx->r14 == ctx->r1) {
        // 0x80800E40: lui         $t4, 0xE400
        ctx->r12 = S32(0XE400 << 16);
            goto L_80800F84;
    }
    // 0x80800E40: lui         $t4, 0xE400
    ctx->r12 = S32(0XE400 << 16);
    // 0x80800E44: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80800E48: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80800E4C: lw          $t8, 0x4($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X4);
    // 0x80800E50: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x80800E54: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80800E58: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x80800E5C: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80800E60: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x80800E64: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80800E68: andi        $v0, $t7, 0xFFFC
    ctx->r2 = ctx->r15 & 0XFFFC;
    // 0x80800E6C: andi        $v1, $t8, 0xFFFC
    ctx->r3 = ctx->r24 & 0XFFFC;
    // 0x80800E70: addiu       $t7, $t0, 0x8
    ctx->r15 = ADD32(ctx->r8, 0X8);
    // 0x80800E74: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80800E78: lui         $t8, 0xF800
    ctx->r24 = S32(0XF800 << 16);
    // 0x80800E7C: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80800E80: lbu         $t9, 0x9B($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X9B);
    // 0x80800E84: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80800E88: lui         $t2, 0xE100
    ctx->r10 = S32(0XE100 << 16);
    // 0x80800E8C: sll         $t6, $t9, 7
    ctx->r14 = S32(ctx->r25 << 7);
    // 0x80800E90: sra         $t7, $t6, 8
    ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
    // 0x80800E94: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80800E98: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80800E9C: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x80800EA0: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80800EA4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80800EA8: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80800EAC: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x80800EB0: addiu       $t6, $t0, 0x8
    ctx->r14 = ADD32(ctx->r8, 0X8);
    // 0x80800EB4: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80800EB8: addiu       $t7, $v1, 0x4
    ctx->r15 = ADD32(ctx->r3, 0X4);
    // 0x80800EBC: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80800EC0: or          $t6, $t9, $t4
    ctx->r14 = ctx->r25 | ctx->r12;
    // 0x80800EC4: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80800EC8: addiu       $t7, $v0, -0x4
    ctx->r15 = ADD32(ctx->r2, -0X4);
    // 0x80800ECC: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x80800ED0: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80800ED4: andi        $t9, $v1, 0xFFF
    ctx->r25 = ctx->r3 & 0XFFF;
    // 0x80800ED8: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80800EDC: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x80800EE0: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x80800EE4: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80800EE8: lui         $t5, 0x100
    ctx->r13 = S32(0X100 << 16);
    // 0x80800EEC: ori         $t5, $t5, 0x100
    ctx->r13 = ctx->r13 | 0X100;
    // 0x80800EF0: addiu       $t6, $t0, 0x8
    ctx->r14 = ADD32(ctx->r8, 0X8);
    // 0x80800EF4: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80800EF8: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x80800EFC: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x80800F00: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80800F04: lui         $t3, 0xF100
    ctx->r11 = S32(0XF100 << 16);
    // 0x80800F08: addiu       $t7, $v0, 0x4
    ctx->r15 = ADD32(ctx->r2, 0X4);
    // 0x80800F0C: addiu       $t8, $t0, 0x8
    ctx->r24 = ADD32(ctx->r8, 0X8);
    // 0x80800F10: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80800F14: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
    // 0x80800F18: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80800F1C: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80800F20: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x80800F24: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80800F28: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x80800F2C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80800F30: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80800F34: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x80800F38: or          $t9, $t8, $t4
    ctx->r25 = ctx->r24 | ctx->r12;
    // 0x80800F3C: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x80800F40: addiu       $t6, $v1, -0x4
    ctx->r14 = ADD32(ctx->r3, -0X4);
    // 0x80800F44: andi        $t7, $v0, 0xFFF
    ctx->r15 = ctx->r2 & 0XFFF;
    // 0x80800F48: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80800F4C: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x80800F50: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x80800F54: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x80800F58: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x80800F5C: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80800F60: addiu       $t6, $t0, 0x8
    ctx->r14 = ADD32(ctx->r8, 0X8);
    // 0x80800F64: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80800F68: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x80800F6C: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x80800F70: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80800F74: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x80800F78: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80800F7C: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
    // 0x80800F80: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
L_80800F84:
    // 0x80800F84: jr          $ra
    // 0x80800F88: nop

    return;
    // 0x80800F88: nop

;}
RECOMP_FUNC void _glcutDll_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088808: syscall     705
    recomp_syscall_handler(rdram, ctx, 0x80088808);
    return;
    // 0x8008880C: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void _subaddiedialog_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A220: syscall     830
    recomp_syscall_handler(rdram, ctx, 0x8008A220);
    return;
    // 0x8008A224: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void func_800BA670(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA670: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BA674: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BA678: lhu         $t6, 0x2($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X2);
    // 0x800BA67C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800BA680: beql        $a1, $t6, L_800BA6A4
    if (ctx->r5 == ctx->r14) {
        // 0x800BA684: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800BA6A4;
    }
    goto skip_0;
    // 0x800BA684: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800BA688: sh          $a1, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r5;
    // 0x800BA68C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x800BA690: jal         0x800D738C
    // 0x800BA694: andi        $a0, $a1, 0xFFFF
    ctx->r4 = ctx->r5 & 0XFFFF;
    func_800D738C(rdram, ctx);
        goto after_0;
    // 0x800BA694: andi        $a0, $a1, 0xFFFF
    ctx->r4 = ctx->r5 & 0XFFFF;
    after_0:
    // 0x800BA698: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800BA69C: sb          $v0, 0xA($a2)
    MEM_B(0XA, ctx->r6) = ctx->r2;
    // 0x800BA6A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800BA6A4:
    // 0x800BA6A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BA6A8: jr          $ra
    // 0x800BA6AC: nop

    return;
    // 0x800BA6AC: nop

;}
RECOMP_FUNC void func_80800F40_chamazongoldhordeofficial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F40: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80800F44: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x80800F48: or          $t6, $a2, $zero
    ctx->r14 = ctx->r6 | 0;
    // 0x80800F4C: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80800F50: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800F54: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800F58: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800F5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800F60: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80800F64: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800F68: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x80800F6C: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80800F70: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800F74: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800F78: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x80800F7C: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    // 0x80800F80: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x80800F84: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    // 0x80800F88: jal         0x800F0064
    // 0x80800F8C: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    func_800F0064(rdram, ctx);
        goto after_0;
    // 0x80800F8C: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x80800F90: beq         $v0, $zero, L_80800FB4
    if (ctx->r2 == 0) {
        // 0x80800F94: nop
    
            goto L_80800FB4;
    }
    // 0x80800F94: nop

    // 0x80800F98: jal         0x800D8FF8
    // 0x80800F9C: nop

    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80800F9C: nop

    after_1:
    // 0x80800FA0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1860, 0X11B8) << 16);
    // 0x80800FA4: lwc1        $f18, 0x11B8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1860, 0X11B8));
    // 0x80800FA8: mul.s       $f2, $f0, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80800FAC: b           L_80800FD4
    // 0x80800FB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800FD4;
    // 0x80800FB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800FB4:
    // 0x80800FB4: jal         0x800D8FF8
    // 0x80800FB8: nop

    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x80800FB8: nop

    after_2:
    // 0x80800FBC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800FC0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800FC4: nop

    // 0x80800FC8: mul.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800FCC: nop

    // 0x80800FD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800FD4:
    // 0x80800FD4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80800FD8: jal         0x80102D78
    // 0x80800FDC: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    func_80102D78(rdram, ctx);
        goto after_3;
    // 0x80800FDC: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    after_3:
    // 0x80800FE0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800FE4: jal         0x80102924
    // 0x80800FE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102924(rdram, ctx);
        goto after_4;
    // 0x80800FE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800FEC: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800FF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FF4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80800FF8: jal         0x80102B2C
    // 0x80800FFC: nop

    func_80102B2C(rdram, ctx);
        goto after_5;
    // 0x80800FFC: nop

    after_5:
    // 0x80801000: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80801004: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    // 0x80801008: jal         0x800F0064
    // 0x8080100C: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    func_800F0064(rdram, ctx);
        goto after_6;
    // 0x8080100C: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_6:
    // 0x80801010: bne         $v0, $zero, L_80801028
    if (ctx->r2 != 0) {
        // 0x80801014: sw          $v0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r2;
            goto L_80801028;
    }
    // 0x80801014: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80801018: lui         $a1, 0x20
    ctx->r5 = S32(0X20 << 16);
    // 0x8080101C: ori         $a1, $a1, 0x1005
    ctx->r5 = ctx->r5 | 0X1005;
    // 0x80801020: jal         0x8010B990
    // 0x80801024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010B990(rdram, ctx);
        goto after_7;
    // 0x80801024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
L_80801028:
    // 0x80801028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080102C: jal         0x80102CF4
    // 0x80801030: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    func_80102CF4(rdram, ctx);
        goto after_8;
    // 0x80801030: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    after_8:
    // 0x80801034: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x80801038: beq         $t7, $zero, L_8080104C
    if (ctx->r15 == 0) {
        // 0x8080103C: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_8080104C;
    }
    // 0x8080103C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80801040: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80801044: sltu        $t8, $zero, $v0
    ctx->r24 = 0 < ctx->r2 ? 1 : 0;
    // 0x80801048: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8080104C:
    // 0x8080104C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801050: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801054: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80801058: jr          $ra
    // 0x8080105C: nop

    return;
    // 0x8080105C: nop

;}
RECOMP_FUNC void func_80800908_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800908: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8080090C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800910: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80800914: jal         0x80100094
    // 0x80800918: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800918: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080091C: lw          $v1, 0x60($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X60);
    // 0x80800920: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800924: lbu         $t6, 0x72($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X72);
    // 0x80800928: andi        $t7, $t6, 0xFF03
    ctx->r15 = ctx->r14 & 0XFF03;
    // 0x8080092C: ori         $t8, $t7, 0x18
    ctx->r24 = ctx->r15 | 0X18;
    // 0x80800930: sb          $t8, 0x72($v1)
    MEM_B(0X72, ctx->r3) = ctx->r24;
    // 0x80800934: jal         0x800FDC28
    // 0x80800938: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    func_800FDC28(rdram, ctx);
        goto after_1;
    // 0x80800938: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8080093C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800940: jal         0x80801734
    // 0x80800944: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801734_chstoneballcontrol(rdram, ctx);
        goto after_2;
    // 0x80800944: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800948: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8080094C: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80800950: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x80800954: lbu         $t9, 0x3A($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X3A);
    // 0x80800958: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8080095C: addiu       $a0, $t0, 0x20
    ctx->r4 = ADD32(ctx->r8, 0X20);
    // 0x80800960: jal         0x80089978
    // 0x80800964: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    _sumultiscore_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800964: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_3:
    // 0x80800968: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8080096C: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x80800970: lbu         $t1, 0x39($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X39);
    // 0x80800974: slti        $at, $t1, 0x3
    ctx->r1 = SIGNED(ctx->r9) < 0X3 ? 1 : 0;
    // 0x80800978: beql        $at, $zero, L_80800AC4
    if (ctx->r1 == 0) {
        // 0x8080097C: lbu         $t9, 0x3A($t0)
        ctx->r25 = MEM_BU(ctx->r8, 0X3A);
            goto L_80800AC4;
    }
    goto skip_0;
    // 0x8080097C: lbu         $t9, 0x3A($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X3A);
    skip_0:
    // 0x80800980: lw          $t3, 0x64($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X64);
    // 0x80800984: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x80800988: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8080098C: sll         $t5, $t3, 12
    ctx->r13 = S32(ctx->r11 << 12);
    // 0x80800990: bgez        $t5, L_80800A14
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80800994: nop
    
            goto L_80800A14;
    }
    // 0x80800994: nop

    // 0x80800998: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x8080099C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808009A0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808009A4: beq         $v1, $a3, L_808009CC
    if (ctx->r3 == ctx->r7) {
        // 0x808009A8: lw          $t6, 0x3C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X3C);
            goto L_808009CC;
    }
    // 0x808009A8: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x808009AC: beq         $v1, $at, L_808009F4
    if (ctx->r3 == ctx->r1) {
        // 0x808009B0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808009F4;
    }
    // 0x808009B0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808009B4: beq         $v1, $at, L_808009F4
    if (ctx->r3 == ctx->r1) {
        // 0x808009B8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808009F4;
    }
    // 0x808009B8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808009BC: beql        $v1, $at, L_808009F8
    if (ctx->r3 == ctx->r1) {
        // 0x808009C0: lw          $a0, 0x60($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X60);
            goto L_808009F8;
    }
    goto skip_1;
    // 0x808009C0: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    skip_1:
    // 0x808009C4: b           L_80800B40
    // 0x808009C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800B40;
    // 0x808009C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808009CC:
    // 0x808009CC: bnel        $t6, $zero, L_808009F8
    if (ctx->r14 != 0) {
        // 0x808009D0: lw          $a0, 0x60($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X60);
            goto L_808009F8;
    }
    goto skip_2;
    // 0x808009D0: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    skip_2:
    // 0x808009D4: jal         0x800FC6B0
    // 0x808009D8: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_800FC6B0(rdram, ctx);
        goto after_4;
    // 0x808009D8: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_4:
    // 0x808009DC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x808009E0: addiu       $a1, $zero, 0xF4D
    ctx->r5 = ADD32(0, 0XF4D);
    // 0x808009E4: jal         0x80800000
    // 0x808009E8: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    func_80800000_chstoneballcontrol(rdram, ctx);
        goto after_5;
    // 0x808009E8: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    after_5:
    // 0x808009EC: b           L_80800B40
    // 0x808009F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800B40;
    // 0x808009F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808009F4:
    // 0x808009F4: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
L_808009F8:
    // 0x808009F8: addiu       $a1, $zero, 0xF4E
    ctx->r5 = ADD32(0, 0XF4E);
    // 0x808009FC: jal         0x80800000
    // 0x80800A00: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    func_80800000_chstoneballcontrol(rdram, ctx);
        goto after_6;
    // 0x80800A00: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    after_6:
    // 0x80800A04: jal         0x800FC6B0
    // 0x80800A08: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_800FC6B0(rdram, ctx);
        goto after_7;
    // 0x80800A08: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_7:
    // 0x80800A0C: b           L_80800B40
    // 0x80800A10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800B40;
    // 0x80800A10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800A14:
    // 0x80800A14: beq         $v1, $a3, L_80800A40
    if (ctx->r3 == ctx->r7) {
        // 0x80800A18: lw          $t7, 0x3C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X3C);
            goto L_80800A40;
    }
    // 0x80800A18: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80800A1C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800A20: beq         $v1, $at, L_80800A84
    if (ctx->r3 == ctx->r1) {
        // 0x80800A24: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800A84;
    }
    // 0x80800A24: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800A28: beq         $v1, $at, L_80800A84
    if (ctx->r3 == ctx->r1) {
        // 0x80800A2C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800A84;
    }
    // 0x80800A2C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800A30: beq         $v1, $at, L_80800AA4
    if (ctx->r3 == ctx->r1) {
        // 0x80800A34: lw          $a0, 0x60($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X60);
            goto L_80800AA4;
    }
    // 0x80800A34: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800A38: b           L_80800B40
    // 0x80800A3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800B40;
    // 0x80800A3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800A40:
    // 0x80800A40: bne         $t7, $zero, L_80800A84
    if (ctx->r15 != 0) {
        // 0x80800A44: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800A84;
    }
    // 0x80800A44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800A48: addiu       $a1, $t1, 0x8E
    ctx->r5 = ADD32(ctx->r9, 0X8E);
    // 0x80800A4C: jal         0x800D2054
    // 0x80800A50: lw          $a2, 0x20($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X20);
    func_800D2054(rdram, ctx);
        goto after_8;
    // 0x80800A50: lw          $a2, 0x20($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X20);
    after_8:
    // 0x80800A54: jal         0x800DA544
    // 0x80800A58: addiu       $a0, $zero, 0x9CB
    ctx->r4 = ADD32(0, 0X9CB);
    func_800DA544(rdram, ctx);
        goto after_9;
    // 0x80800A58: addiu       $a0, $zero, 0x9CB
    ctx->r4 = ADD32(0, 0X9CB);
    after_9:
    // 0x80800A5C: jal         0x800FC6B0
    // 0x80800A60: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_800FC6B0(rdram, ctx);
        goto after_10;
    // 0x80800A60: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_10:
    // 0x80800A64: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800A68: jal         0x80101FDC
    // 0x80800A6C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80101FDC(rdram, ctx);
        goto after_11;
    // 0x80800A6C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_11:
    // 0x80800A70: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80800A74: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800A78: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x80800A7C: b           L_80800B3C
    // 0x80800A80: swc1        $f4, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->f4.u32l;
        goto L_80800B3C;
    // 0x80800A80: swc1        $f4, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->f4.u32l;
L_80800A84:
    // 0x80800A84: jal         0x800FC6B0
    // 0x80800A88: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_800FC6B0(rdram, ctx);
        goto after_12;
    // 0x80800A88: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_12:
    // 0x80800A8C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800A90: addiu       $a1, $zero, 0xF21
    ctx->r5 = ADD32(0, 0XF21);
    // 0x80800A94: jal         0x80800000
    // 0x80800A98: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    func_80800000_chstoneballcontrol(rdram, ctx);
        goto after_13;
    // 0x80800A98: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    after_13:
    // 0x80800A9C: b           L_80800B40
    // 0x80800AA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800B40;
    // 0x80800AA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800AA4:
    // 0x80800AA4: addiu       $a1, $zero, 0xF22
    ctx->r5 = ADD32(0, 0XF22);
    // 0x80800AA8: jal         0x80800000
    // 0x80800AAC: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    func_80800000_chstoneballcontrol(rdram, ctx);
        goto after_14;
    // 0x80800AAC: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    after_14:
    // 0x80800AB0: jal         0x800FC6B0
    // 0x80800AB4: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_800FC6B0(rdram, ctx);
        goto after_15;
    // 0x80800AB4: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_15:
    // 0x80800AB8: b           L_80800B40
    // 0x80800ABC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800B40;
    // 0x80800ABC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800AC0: lbu         $t9, 0x3A($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X3A);
L_80800AC4:
    // 0x80800AC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800AC8: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80800ACC: blez        $t9, L_80800B0C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80800AD0: or          $v1, $t0, $zero
        ctx->r3 = ctx->r8 | 0;
            goto L_80800B0C;
    }
    // 0x80800AD0: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x80800AD4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800AD8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80800ADC:
    // 0x80800ADC: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x80800AE0: bnel        $a3, $t2, L_80800AF4
    if (ctx->r7 != ctx->r10) {
        // 0x80800AE4: sb          $zero, 0x30($v1)
        MEM_B(0X30, ctx->r3) = 0;
            goto L_80800AF4;
    }
    goto skip_3;
    // 0x80800AE4: sb          $zero, 0x30($v1)
    MEM_B(0X30, ctx->r3) = 0;
    skip_3:
    // 0x80800AE8: b           L_80800AF4
    // 0x80800AEC: sb          $a2, 0x30($v1)
    MEM_B(0X30, ctx->r3) = ctx->r6;
        goto L_80800AF4;
    // 0x80800AEC: sb          $a2, 0x30($v1)
    MEM_B(0X30, ctx->r3) = ctx->r6;
    // 0x80800AF0: sb          $zero, 0x30($v1)
    MEM_B(0X30, ctx->r3) = 0;
L_80800AF4:
    // 0x80800AF4: lbu         $t3, 0x3A($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X3A);
    // 0x80800AF8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80800AFC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800B00: slt         $at, $a1, $t3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80800B04: bne         $at, $zero, L_80800ADC
    if (ctx->r1 != 0) {
        // 0x80800B08: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80800ADC;
    }
    // 0x80800B08: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80800B0C:
    // 0x80800B0C: beq         $v0, $zero, L_80800B20
    if (ctx->r2 == 0) {
        // 0x80800B10: addiu       $a0, $zero, 0x10
        ctx->r4 = ADD32(0, 0X10);
            goto L_80800B20;
    }
    // 0x80800B10: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80800B14: addiu       $a1, $zero, 0xF51
    ctx->r5 = ADD32(0, 0XF51);
    // 0x80800B18: b           L_80800B24
    // 0x80800B1C: sb          $v0, 0x3B($t0)
    MEM_B(0X3B, ctx->r8) = ctx->r2;
        goto L_80800B24;
    // 0x80800B1C: sb          $v0, 0x3B($t0)
    MEM_B(0X3B, ctx->r8) = ctx->r2;
L_80800B20:
    // 0x80800B20: addiu       $a1, $zero, 0xF52
    ctx->r5 = ADD32(0, 0XF52);
L_80800B24:
    // 0x80800B24: jal         0x800FC6B0
    // 0x80800B28: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    func_800FC6B0(rdram, ctx);
        goto after_16;
    // 0x80800B28: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_16:
    // 0x80800B2C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800B30: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800B34: jal         0x80800000
    // 0x80800B38: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80800000_chstoneballcontrol(rdram, ctx);
        goto after_17;
    // 0x80800B38: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_17:
L_80800B3C:
    // 0x80800B3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800B40:
    // 0x80800B40: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80800B44: jr          $ra
    // 0x80800B48: nop

    return;
    // 0x80800B48: nop

;}
RECOMP_FUNC void func_8080030C_bsbanshack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080030C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800310: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800314: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800318: lui         $a2, 0x3FB3
    ctx->r6 = S32(0X3FB3 << 16);
    // 0x8080031C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800320: sb          $zero, 0x15D($a0)
    MEM_B(0X15D, ctx->r4) = 0;
    // 0x80800324: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800328: jal         0x8008CCBC
    // 0x8080032C: addiu       $a1, $zero, 0x145
    ctx->r5 = ADD32(0, 0X145);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_0;
    // 0x8080032C: addiu       $a1, $zero, 0x145
    ctx->r5 = ADD32(0, 0X145);
    after_0:
    // 0x80800330: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800334: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080033C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800340: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800344: jal         0x8009FFD8
    // 0x80800348: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x80800348: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x8080034C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800350: jal         0x8009B9B0
    // 0x80800354: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x80800354: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080035C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800360: jal         0x80098140
    // 0x80800364: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    bainput_enable(rdram, ctx);
        goto after_3;
    // 0x80800364: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80800368: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080036C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800370: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800374: jr          $ra
    // 0x80800378: nop

    return;
    // 0x80800378: nop

;}
RECOMP_FUNC void func_80800354_chkingjinjobits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800354: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800358: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080035C: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80800360: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    // 0x80800364: jal         0x800DA298
    // 0x80800368: addiu       $a0, $zero, 0x360
    ctx->r4 = ADD32(0, 0X360);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800368: addiu       $a0, $zero, 0x360
    ctx->r4 = ADD32(0, 0X360);
    after_0:
    // 0x8080036C: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80800370: jal         0x800DA298
    // 0x80800374: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800374: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    after_1:
    // 0x80800378: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x8080037C: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    // 0x80800380: jal         0x800D0B68
    // 0x80800384: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0B68(rdram, ctx);
        goto after_2;
    // 0x80800384: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800388: jal         0x800EA05C
    // 0x8080038C: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    func_800EA05C(rdram, ctx);
        goto after_3;
    // 0x8080038C: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    after_3:
    // 0x80800390: slti        $at, $v0, 0x191
    ctx->r1 = SIGNED(ctx->r2) < 0X191 ? 1 : 0;
    // 0x80800394: bne         $at, $zero, L_808003AC
    if (ctx->r1 != 0) {
        // 0x80800398: addiu       $at, $zero, 0x198
        ctx->r1 = ADD32(0, 0X198);
            goto L_808003AC;
    }
    // 0x80800398: addiu       $at, $zero, 0x198
    ctx->r1 = ADD32(0, 0X198);
    // 0x8080039C: beq         $v0, $at, L_80800650
    if (ctx->r2 == ctx->r1) {
        // 0x808003A0: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80800650;
    }
    // 0x808003A0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x808003A4: b           L_80800724
    // 0x808003A8: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
        goto L_80800724;
    // 0x808003A8: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
L_808003AC:
    // 0x808003AC: slti        $at, $v0, 0x161
    ctx->r1 = SIGNED(ctx->r2) < 0X161 ? 1 : 0;
    // 0x808003B0: bne         $at, $zero, L_808003CC
    if (ctx->r1 != 0) {
        // 0x808003B4: addiu       $t6, $v0, -0x142
        ctx->r14 = ADD32(ctx->r2, -0X142);
            goto L_808003CC;
    }
    // 0x808003B4: addiu       $t6, $v0, -0x142
    ctx->r14 = ADD32(ctx->r2, -0X142);
    // 0x808003B8: addiu       $at, $zero, 0x190
    ctx->r1 = ADD32(0, 0X190);
    // 0x808003BC: beq         $v0, $at, L_808005F8
    if (ctx->r2 == ctx->r1) {
        // 0x808003C0: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_808005F8;
    }
    // 0x808003C0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808003C4: b           L_80800724
    // 0x808003C8: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
        goto L_80800724;
    // 0x808003C8: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
L_808003CC:
    // 0x808003CC: sltiu       $at, $t6, 0x1F
    ctx->r1 = ctx->r14 < 0X1F ? 1 : 0;
    // 0x808003D0: beq         $at, $zero, L_80800720
    if (ctx->r1 == 0) {
        // 0x808003D4: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800720;
    }
    // 0x808003D4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808003D8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1464, 0X9F8) << 16);
    // 0x808003DC: addu        $at, $at, $t6
    gpr jr_addend_808003E4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808003E0: lw          $t6, 0x9F8($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1464, 0X9F8));
    // 0x808003E4: jr          $t6
    // 0x808003E8: nop

    switch (jr_addend_808003E4 >> 2) {
        case 0: goto L_808003EC; break;
        case 1: goto L_80800720; break;
        case 2: goto L_80800720; break;
        case 3: goto L_80800574; break;
        case 4: goto L_80800574; break;
        case 5: goto L_80800574; break;
        case 6: goto L_80800574; break;
        case 7: goto L_80800574; break;
        case 8: goto L_80800574; break;
        case 9: goto L_80800574; break;
        case 10: goto L_80800574; break;
        case 11: goto L_80800574; break;
        case 12: goto L_80800574; break;
        case 13: goto L_808005CC; break;
        case 14: goto L_80800720; break;
        case 15: goto L_80800720; break;
        case 16: goto L_80800720; break;
        case 17: goto L_80800720; break;
        case 18: goto L_80800720; break;
        case 19: goto L_80800720; break;
        case 20: goto L_80800720; break;
        case 21: goto L_80800720; break;
        case 22: goto L_80800720; break;
        case 23: goto L_80800720; break;
        case 24: goto L_80800720; break;
        case 25: goto L_80800720; break;
        case 26: goto L_80800720; break;
        case 27: goto L_80800720; break;
        case 28: goto L_80800720; break;
        case 29: goto L_80800720; break;
        case 30: goto L_808006AC; break;
        default: switch_error(__func__, 0x808003E4, 0x808009F8);
    }
    // 0x808003E8: nop

L_808003EC:
    // 0x808003EC: jal         0x80088840
    // 0x808003F0: addiu       $a0, $zero, 0x66
    ctx->r4 = ADD32(0, 0X66);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_4;
    // 0x808003F0: addiu       $a0, $zero, 0x66
    ctx->r4 = ADD32(0, 0X66);
    after_4:
    // 0x808003F4: beq         $v0, $zero, L_80800454
    if (ctx->r2 == 0) {
        // 0x808003F8: addiu       $a3, $zero, 0x900
        ctx->r7 = ADD32(0, 0X900);
            goto L_80800454;
    }
    // 0x808003F8: addiu       $a3, $zero, 0x900
    ctx->r7 = ADD32(0, 0X900);
    // 0x808003FC: jal         0x800EA364
    // 0x80800400: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    func_800EA364(rdram, ctx);
        goto after_5;
    // 0x80800400: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_5:
    // 0x80800404: addiu       $at, $zero, 0x143
    ctx->r1 = ADD32(0, 0X143);
    // 0x80800408: bne         $v0, $at, L_80800414
    if (ctx->r2 != ctx->r1) {
        // 0x8080040C: lw          $a3, 0x44($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X44);
            goto L_80800414;
    }
    // 0x8080040C: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x80800410: addiu       $a3, $zero, 0x2900
    ctx->r7 = ADD32(0, 0X2900);
L_80800414:
    // 0x80800414: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x80800418: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080041C: addiu       $a2, $zero, 0x4B
    ctx->r6 = ADD32(0, 0X4B);
    // 0x80800420: jal         0x80085708
    // 0x80800424: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_6;
    // 0x80800424: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_6:
    // 0x80800428: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x8080042C: addiu       $t9, $zero, 0xAE
    ctx->r25 = ADD32(0, 0XAE);
    // 0x80800430: addiu       $a1, $zero, 0x154D
    ctx->r5 = ADD32(0, 0X154D);
    // 0x80800434: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x80800438: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8080043C: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    // 0x80800440: jal         0x8008A208
    // 0x80800444: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_7;
    // 0x80800444: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
    // 0x80800448: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8080044C: b           L_80800540
    // 0x80800450: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
        goto L_80800540;
    // 0x80800450: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
L_80800454:
    // 0x80800454: jal         0x800DB9B0
    // 0x80800458: nop

    func_800DB9B0(rdram, ctx);
        goto after_8;
    // 0x80800458: nop

    after_8:
    // 0x8080045C: bne         $v0, $zero, L_80800540
    if (ctx->r2 != 0) {
        // 0x80800460: lw          $t1, 0x50($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X50);
            goto L_80800540;
    }
    // 0x80800460: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80800464: bne         $t1, $zero, L_80800540
    if (ctx->r9 != 0) {
        // 0x80800468: lw          $t2, 0x4C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X4C);
            goto L_80800540;
    }
    // 0x80800468: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x8080046C: bnel        $t2, $zero, L_80800544
    if (ctx->r10 != 0) {
        // 0x80800470: lw          $a1, 0x50($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X50);
            goto L_80800544;
    }
    goto skip_0;
    // 0x80800470: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    skip_0:
    // 0x80800474: jal         0x800EA090
    // 0x80800478: nop

    func_800EA090(rdram, ctx);
        goto after_9;
    // 0x80800478: nop

    after_9:
    // 0x8080047C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800480: bne         $v0, $at, L_80800540
    if (ctx->r2 != ctx->r1) {
        // 0x80800484: lw          $t3, 0x48($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X48);
            goto L_80800540;
    }
    // 0x80800484: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80800488: beql        $t3, $zero, L_80800544
    if (ctx->r11 == 0) {
        // 0x8080048C: lw          $a1, 0x50($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X50);
            goto L_80800544;
    }
    goto skip_1;
    // 0x8080048C: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    skip_1:
    // 0x80800490: jal         0x800F54E4
    // 0x80800494: nop

    func_800F54E4(rdram, ctx);
        goto after_10;
    // 0x80800494: nop

    after_10:
    // 0x80800498: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8080049C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x808004A0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x808004A4: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x808004A8: addiu       $a1, $zero, 0x154
    ctx->r5 = ADD32(0, 0X154);
    // 0x808004AC: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    // 0x808004B0: jal         0x8008A0C8
    // 0x808004B4: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    _subaddiemarker_entrypoint_1(rdram, ctx);
        goto after_11;
    // 0x808004B4: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    after_11:
    // 0x808004B8: jal         0x800F497C
    // 0x808004BC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800F497C(rdram, ctx);
        goto after_12;
    // 0x808004BC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_12:
    // 0x808004C0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808004C4: jal         0x800F49A8
    // 0x808004C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F49A8(rdram, ctx);
        goto after_13;
    // 0x808004C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x808004CC: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x808004D0: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x808004D4: addiu       $a1, $a1, -0x2A24
    ctx->r5 = ADD32(ctx->r5, -0X2A24);
    // 0x808004D8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808004DC: jal         0x800F49D4
    // 0x808004E0: lw          $a2, 0x0($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X0);
    func_800F49D4(rdram, ctx);
        goto after_14;
    // 0x808004E0: lw          $a2, 0x0($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X0);
    after_14:
    // 0x808004E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808004E8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x808004EC: jal         0x800F4A58
    // 0x808004F0: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    func_800F4A58(rdram, ctx);
        goto after_15;
    // 0x808004F0: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    after_15:
    // 0x808004F4: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x808004F8: addiu       $t7, $zero, 0xAE
    ctx->r15 = ADD32(0, 0XAE);
    // 0x808004FC: addiu       $a1, $zero, 0x154C
    ctx->r5 = ADD32(0, 0X154C);
    // 0x80800500: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80800504: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800508: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    // 0x8080050C: jal         0x8008A208
    // 0x80800510: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_16;
    // 0x80800510: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_16:
    // 0x80800514: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80800518: jal         0x80101FDC
    // 0x8080051C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_17;
    // 0x8080051C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_17:
    // 0x80800520: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x80800524: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800528: addiu       $a2, $zero, 0x4C
    ctx->r6 = ADD32(0, 0X4C);
    // 0x8080052C: addiu       $a3, $zero, 0x2030
    ctx->r7 = ADD32(0, 0X2030);
    // 0x80800530: jal         0x80085708
    // 0x80800534: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_18;
    // 0x80800534: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_18:
    // 0x80800538: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8080053C: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
L_80800540:
    // 0x80800540: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
L_80800544:
    // 0x80800544: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800548: sltiu       $t0, $a1, 0x1
    ctx->r8 = ctx->r5 < 0X1 ? 1 : 0;
    // 0x8080054C: jal         0x800BF744
    // 0x80800550: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    func_800BF744(rdram, ctx);
        goto after_19;
    // 0x80800550: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    after_19:
    // 0x80800554: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800558: jal         0x800BF744
    // 0x8080055C: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    func_800BF744(rdram, ctx);
        goto after_20;
    // 0x8080055C: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    after_20:
    // 0x80800560: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800564: jal         0x800BF744
    // 0x80800568: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800BF744(rdram, ctx);
        goto after_21;
    // 0x80800568: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
    // 0x8080056C: b           L_80800724
    // 0x80800570: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
        goto L_80800724;
    // 0x80800570: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
L_80800574:
    // 0x80800574: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80800578: bnel        $t1, $zero, L_80800724
    if (ctx->r9 != 0) {
        // 0x8080057C: lw          $t7, 0x54($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X54);
            goto L_80800724;
    }
    goto skip_2;
    // 0x8080057C: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    skip_2:
    // 0x80800580: jal         0x800DB9B0
    // 0x80800584: nop

    func_800DB9B0(rdram, ctx);
        goto after_22;
    // 0x80800584: nop

    after_22:
    // 0x80800588: bne         $v0, $zero, L_80800720
    if (ctx->r2 != 0) {
        // 0x8080058C: addiu       $a0, $zero, 0x67D
        ctx->r4 = ADD32(0, 0X67D);
            goto L_80800720;
    }
    // 0x8080058C: addiu       $a0, $zero, 0x67D
    ctx->r4 = ADD32(0, 0X67D);
    // 0x80800590: jal         0x800DA9E4
    // 0x80800594: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_23;
    // 0x80800594: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_23:
    // 0x80800598: bne         $v0, $zero, L_80800720
    if (ctx->r2 != 0) {
        // 0x8080059C: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_80800720;
    }
    // 0x8080059C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x808005A0: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x808005A4: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x808005A8: addiu       $t4, $zero, 0xAE
    ctx->r12 = ADD32(0, 0XAE);
    // 0x808005AC: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x808005B0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x808005B4: addiu       $a1, $zero, 0x1536
    ctx->r5 = ADD32(0, 0X1536);
    // 0x808005B8: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x808005BC: jal         0x8008A208
    // 0x808005C0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_24;
    // 0x808005C0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_24:
    // 0x808005C4: b           L_80800724
    // 0x808005C8: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
        goto L_80800724;
    // 0x808005C8: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
L_808005CC:
    // 0x808005CC: jal         0x800DA298
    // 0x808005D0: addiu       $a0, $zero, 0x367
    ctx->r4 = ADD32(0, 0X367);
    func_800DA298(rdram, ctx);
        goto after_25;
    // 0x808005D0: addiu       $a0, $zero, 0x367
    ctx->r4 = ADD32(0, 0X367);
    after_25:
    // 0x808005D4: sltiu       $t5, $v0, 0x1
    ctx->r13 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x808005D8: sw          $t5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r13;
    // 0x808005DC: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x808005E0: jal         0x80101FDC
    // 0x808005E4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_26;
    // 0x808005E4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_26:
    // 0x808005E8: jal         0x8008A498
    // 0x808005EC: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    _subaddieDll_entrypoint_1(rdram, ctx);
        goto after_27;
    // 0x808005EC: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_27:
    // 0x808005F0: b           L_80800724
    // 0x808005F4: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
        goto L_80800724;
    // 0x808005F4: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
L_808005F8:
    // 0x808005F8: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x808005FC: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80800600: jal         0x80101FDC
    // 0x80800604: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_28;
    // 0x80800604: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_28:
    // 0x80800608: lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X58);
    // 0x8080060C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80800610: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800614: lhu         $t7, 0x6E($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X6E);
    // 0x80800618: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8080061C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800620: andi        $t8, $t7, 0xFE00
    ctx->r24 = ctx->r15 & 0XFE00;
    // 0x80800624: sh          $t8, 0x6E($v0)
    MEM_H(0X6E, ctx->r2) = ctx->r24;
    // 0x80800628: jal         0x800BF744
    // 0x8080062C: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    func_800BF744(rdram, ctx);
        goto after_29;
    // 0x8080062C: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    after_29:
    // 0x80800630: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800634: jal         0x800BF744
    // 0x80800638: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BF744(rdram, ctx);
        goto after_30;
    // 0x80800638: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_30:
    // 0x8080063C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800640: jal         0x800BF744
    // 0x80800644: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BF744(rdram, ctx);
        goto after_31;
    // 0x80800644: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_31:
    // 0x80800648: b           L_80800724
    // 0x8080064C: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
        goto L_80800724;
    // 0x8080064C: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
L_80800650:
    // 0x80800650: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
    // 0x80800654: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80800658: jal         0x80101FDC
    // 0x8080065C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80101FDC(rdram, ctx);
        goto after_32;
    // 0x8080065C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_32:
    // 0x80800660: lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X58);
    // 0x80800664: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80800668: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080066C: lhu         $t0, 0x6E($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X6E);
    // 0x80800670: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800674: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800678: andi        $t1, $t0, 0xFE00
    ctx->r9 = ctx->r8 & 0XFE00;
    // 0x8080067C: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80800680: sh          $t2, 0x6E($v0)
    MEM_H(0X6E, ctx->r2) = ctx->r10;
    // 0x80800684: jal         0x800BF744
    // 0x80800688: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    func_800BF744(rdram, ctx);
        goto after_33;
    // 0x80800688: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    after_33:
    // 0x8080068C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800690: jal         0x800BF744
    // 0x80800694: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BF744(rdram, ctx);
        goto after_34;
    // 0x80800694: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_34:
    // 0x80800698: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8080069C: jal         0x800BF744
    // 0x808006A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BF744(rdram, ctx);
        goto after_35;
    // 0x808006A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_35:
    // 0x808006A4: b           L_80800724
    // 0x808006A8: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
        goto L_80800724;
    // 0x808006A8: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
L_808006AC:
    // 0x808006AC: jal         0x800EA090
    // 0x808006B0: nop

    func_800EA090(rdram, ctx);
        goto after_36;
    // 0x808006B0: nop

    after_36:
    // 0x808006B4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808006B8: bne         $v0, $at, L_80800720
    if (ctx->r2 != ctx->r1) {
        // 0x808006BC: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80800720;
    }
    // 0x808006BC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x808006C0: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x808006C4: sw          $t3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r11;
    // 0x808006C8: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    // 0x808006CC: addiu       $a2, $zero, 0x2000
    ctx->r6 = ADD32(0, 0X2000);
    // 0x808006D0: jal         0x800856B0
    // 0x808006D4: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    _capod_entrypoint_2(rdram, ctx);
        goto after_37;
    // 0x808006D4: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    after_37:
    // 0x808006D8: jal         0x800856E0
    // 0x808006DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _capod_entrypoint_8(rdram, ctx);
        goto after_38;
    // 0x808006DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_38:
    // 0x808006E0: jal         0x800880B8
    // 0x808006E4: nop

    _gcdialogcamera_entrypoint_8(rdram, ctx);
        goto after_39;
    // 0x808006E4: nop

    after_39:
    // 0x808006E8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x808006EC: jal         0x800856D8
    // 0x808006F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _capod_entrypoint_7(rdram, ctx);
        goto after_40;
    // 0x808006F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_40:
    // 0x808006F4: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x808006F8: addiu       $t6, $zero, 0x22
    ctx->r14 = ADD32(0, 0X22);
    // 0x808006FC: addiu       $a1, $zero, 0x14D7
    ctx->r5 = ADD32(0, 0X14D7);
    // 0x80800700: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x80800704: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800708: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x8080070C: jal         0x8008A208
    // 0x80800710: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_41;
    // 0x80800710: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_41:
    // 0x80800714: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80800718: jal         0x80101FDC
    // 0x8080071C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80101FDC(rdram, ctx);
        goto after_42;
    // 0x8080071C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_42:
L_80800720:
    // 0x80800720: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
L_80800724:
    // 0x80800724: bnel        $t7, $zero, L_80800738
    if (ctx->r15 != 0) {
        // 0x80800728: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800738;
    }
    goto skip_3;
    // 0x80800728: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8080072C: jal         0x800FFAB0
    // 0x80800730: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_800FFAB0(rdram, ctx);
        goto after_43;
    // 0x80800730: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_43:
    // 0x80800734: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800738:
    // 0x80800738: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8080073C: jr          $ra
    // 0x80800740: nop

    return;
    // 0x80800740: nop

;}
RECOMP_FUNC void func_8080000C_chlaundry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: jal         0x80100094
    // 0x80800018: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800018: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080001C: jal         0x800A940C
    // 0x80800020: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    func_800A940C(rdram, ctx);
        goto after_1;
    // 0x80800020: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    after_1:
    // 0x80800024: jal         0x800C5190
    // 0x80800028: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800C5190(rdram, ctx);
        goto after_2;
    // 0x80800028: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x8080002C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800030: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800038: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8080003C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80800040: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800044: bc1f        L_80800050
    if (!c1cs) {
        // 0x80800048: nop
    
            goto L_80800050;
    }
    // 0x80800048: nop

    // 0x8080004C: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_80800050:
    // 0x80800050: jr          $ra
    // 0x80800054: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x80800054: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void chcollballcontrol_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803228: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1840, 0X4F58) << 16);
    // 0x8080322C: jr          $ra
    // 0x80803230: addiu       $v0, $v0, 0x4F58
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1840, 0X4F58));
    return;
    // 0x80803230: addiu       $v0, $v0, 0x4F58
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1840, 0X4F58));
;}
RECOMP_FUNC void _sucoasterflydata_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A290: syscall     832
    recomp_syscall_handler(rdram, ctx, 0x8008A290);
    return;
    // 0x8008A294: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_800BE444(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE444: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800BE448: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BE44C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800BE450: jal         0x800EE904
    // 0x800BE454: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800EE904(rdram, ctx);
        goto after_0;
    // 0x800BE454: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x800BE458: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BE45C: addiu       $a0, $a0, -0x7AC8
    ctx->r4 = ADD32(ctx->r4, -0X7AC8);
    // 0x800BE460: jal         0x800BE09C
    // 0x800BE464: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800BE09C(rdram, ctx);
        goto after_1;
    // 0x800BE464: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x800BE468: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BE46C: addiu       $a0, $a0, -0x7BBC
    ctx->r4 = ADD32(ctx->r4, -0X7BBC);
    // 0x800BE470: jal         0x800E9DCC
    // 0x800BE474: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_800E9DCC(rdram, ctx);
        goto after_2;
    // 0x800BE474: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_2:
    // 0x800BE478: beq         $v0, $zero, L_800BE4A0
    if (ctx->r2 == 0) {
        // 0x800BE47C: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_800BE4A0;
    }
    // 0x800BE47C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800BE480: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BE484: addiu       $a0, $a0, -0x7AC8
    ctx->r4 = ADD32(ctx->r4, -0X7AC8);
    // 0x800BE488: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800BE48C: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800BE490: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x800BE494: addiu       $t6, $t6, -0x7BBC
    ctx->r14 = ADD32(ctx->r14, -0X7BBC);
    // 0x800BE498: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x800BE49C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800BE4A0:
    // 0x800BE4A0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BE4A4: addiu       $v0, $a0, -0x7AC8
    ctx->r2 = ADD32(ctx->r4, -0X7AC8);
    // 0x800BE4A8: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x800BE4AC: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x800BE4B0: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x800BE4B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BE4B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800BE4BC: jr          $ra
    // 0x800BE4C0: nop

    return;
    // 0x800BE4C0: nop

;}
RECOMP_FUNC void func_80015768(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015768: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001576C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80015770: jr          $ra
    // 0x80015774: sh          $t6, -0x709E($at)
    MEM_H(-0X709E, ctx->r1) = ctx->r14;
    return;
    // 0x80015774: sh          $t6, -0x709E($at)
    MEM_H(-0X709E, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_808005F0_gczoombox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005F0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x808005F4: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x808005F8: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x808005FC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80800600: bne         $t7, $zero, L_80800654
    if (ctx->r15 != 0) {
        // 0x80800604: sw          $a1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r5;
            goto L_80800654;
    }
    // 0x80800604: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80800608: xori        $v0, $t6, 0x2E
    ctx->r2 = ctx->r14 ^ 0X2E;
    // 0x8080060C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80800610: bne         $v0, $zero, L_8080068C
    if (ctx->r2 != 0) {
        // 0x80800614: nop
    
            goto L_8080068C;
    }
    // 0x80800614: nop

    // 0x80800618: xori        $v0, $t6, 0x21
    ctx->r2 = ctx->r14 ^ 0X21;
    // 0x8080061C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80800620: bne         $v0, $zero, L_8080068C
    if (ctx->r2 != 0) {
        // 0x80800624: nop
    
            goto L_8080068C;
    }
    // 0x80800624: nop

    // 0x80800628: xori        $v0, $t6, 0x2C
    ctx->r2 = ctx->r14 ^ 0X2C;
    // 0x8080062C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80800630: bne         $v0, $zero, L_8080068C
    if (ctx->r2 != 0) {
        // 0x80800634: nop
    
            goto L_8080068C;
    }
    // 0x80800634: nop

    // 0x80800638: xori        $v0, $t6, 0x2D
    ctx->r2 = ctx->r14 ^ 0X2D;
    // 0x8080063C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80800640: bne         $v0, $zero, L_8080068C
    if (ctx->r2 != 0) {
        // 0x80800644: nop
    
            goto L_8080068C;
    }
    // 0x80800644: nop

    // 0x80800648: xori        $v0, $t6, 0x3F
    ctx->r2 = ctx->r14 ^ 0X3F;
    // 0x8080064C: jr          $ra
    // 0x80800650: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    return;
    // 0x80800650: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80800654:
    // 0x80800654: xori        $v0, $a0, 0x1
    ctx->r2 = ctx->r4 ^ 0X1;
    // 0x80800658: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8080065C: bne         $v0, $zero, L_8080068C
    if (ctx->r2 != 0) {
        // 0x80800660: nop
    
            goto L_8080068C;
    }
    // 0x80800660: nop

    // 0x80800664: xori        $v0, $a0, 0x34
    ctx->r2 = ctx->r4 ^ 0X34;
    // 0x80800668: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8080066C: bne         $v0, $zero, L_8080068C
    if (ctx->r2 != 0) {
        // 0x80800670: nop
    
            goto L_8080068C;
    }
    // 0x80800670: nop

    // 0x80800674: xori        $v0, $a0, 0x40
    ctx->r2 = ctx->r4 ^ 0X40;
    // 0x80800678: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8080067C: bne         $v0, $zero, L_8080068C
    if (ctx->r2 != 0) {
        // 0x80800680: nop
    
            goto L_8080068C;
    }
    // 0x80800680: nop

    // 0x80800684: xori        $v0, $a0, 0x42
    ctx->r2 = ctx->r4 ^ 0X42;
    // 0x80800688: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_8080068C:
    // 0x8080068C: jr          $ra
    // 0x80800690: nop

    return;
    // 0x80800690: nop

;}
RECOMP_FUNC void func_80803E84_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803E84: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80803E88: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80803E8C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80803E90: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80803E94: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80803E98: jal         0x80100094
    // 0x80803E9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80803E9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80803EA0: lbu         $t6, 0x8($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X8);
    // 0x80803EA4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80803EA8: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x80803EAC: beq         $at, $zero, L_808040BC
    if (ctx->r1 == 0) {
        // 0x80803EB0: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_808040BC;
    }
    // 0x80803EB0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80803EB4: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9B44) << 16);
    // 0x80803EB8: addu        $at, $at, $t6
    gpr jr_addend_80803EC0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80803EBC: lw          $t6, -0x64BC($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9B44));
    // 0x80803EC0: jr          $t6
    // 0x80803EC4: nop

    switch (jr_addend_80803EC0 >> 2) {
        case 0: goto L_808040BC; break;
        case 1: goto L_80803EC8; break;
        case 2: goto L_80803F10; break;
        case 3: goto L_80804088; break;
        case 4: goto L_808040B4; break;
        default: switch_error(__func__, 0x80803EC0, 0x80809B44);
    }
    // 0x80803EC4: nop

L_80803EC8:
    // 0x80803EC8: lw          $t7, 0x70($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X70);
    // 0x80803ECC: lbu         $a0, 0xD($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XD);
    // 0x80803ED0: lui         $a3, 0x8081
    ctx->r7 = S32(RELOC_HI16(1480, 0X9FB0) << 16);
    // 0x80803ED4: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80803ED8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80803EDC: addiu       $a3, $a3, -0x6050
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1480, 0X9FB0));
    // 0x80803EE0: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x80803EE4: jal         0x80089D68
    // 0x80803EE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x80803EE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80803EEC: sb          $v0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r2;
    // 0x80803EF0: jal         0x800D9078
    // 0x80803EF4: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    func_800D9078(rdram, ctx);
        goto after_2;
    // 0x80803EF4: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    after_2:
    // 0x80803EF8: beq         $v0, $zero, L_808040BC
    if (ctx->r2 == 0) {
        // 0x80803EFC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808040BC;
    }
    // 0x80803EFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80803F00: jal         0x808041E4
    // 0x80803F04: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808041E4_chdiggerboss(rdram, ctx);
        goto after_3;
    // 0x80803F04: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80803F08: b           L_808040BC
    // 0x80803F0C: nop

        goto L_808040BC;
    // 0x80803F0C: nop

L_80803F10:
    // 0x80803F10: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9B58) << 16);
    // 0x80803F14: lwc1        $f4, -0x64A8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9B58));
    // 0x80803F18: lwc1        $f12, 0x24($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80803F1C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80803F20: lui         $a3, 0x3F59
    ctx->r7 = S32(0X3F59 << 16);
    // 0x80803F24: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80803F28: lui         $a2, 0x43AF
    ctx->r6 = S32(0X43AF << 16);
    // 0x80803F2C: jal         0x800F10B4
    // 0x80803F30: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x80803F30: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x80803F34: lui         $at, 0x46FA
    ctx->r1 = S32(0X46FA << 16);
    // 0x80803F38: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80803F3C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80803F40: lwc1        $f12, 0x24($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80803F44: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80803F48: lui         $a3, 0x46C3
    ctx->r7 = S32(0X46C3 << 16);
    // 0x80803F4C: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x80803F50: lui         $a2, 0x43AF
    ctx->r6 = S32(0X43AF << 16);
    // 0x80803F54: jal         0x800F10B4
    // 0x80803F58: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_5;
    // 0x80803F58: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x80803F5C: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80803F60: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x80803F64: nop

    // 0x80803F68: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x80803F6C: lbu         $a0, 0xB($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XB);
    // 0x80803F70: bnel        $a0, $zero, L_80803F90
    if (ctx->r4 != 0) {
        // 0x80803F74: lw          $t1, 0x70($s1)
        ctx->r9 = MEM_W(ctx->r17, 0X70);
            goto L_80803F90;
    }
    goto skip_0;
    // 0x80803F74: lw          $t1, 0x70($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X70);
    skip_0:
    // 0x80803F78: jal         0x800C4B64
    // 0x80803F7C: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    func_800C4B64(rdram, ctx);
        goto after_6;
    // 0x80803F7C: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    after_6:
    // 0x80803F80: jal         0x800C4B70
    // 0x80803F84: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800C4B70(rdram, ctx);
        goto after_7;
    // 0x80803F84: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_7:
    // 0x80803F88: lbu         $a0, 0xB($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XB);
    // 0x80803F8C: lw          $t1, 0x70($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X70);
L_80803F90:
    // 0x80803F90: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x80803F94: lui         $a3, 0x8081
    ctx->r7 = S32(RELOC_HI16(1480, 0X9FC0) << 16);
    // 0x80803F98: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80803F9C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80803FA0: addiu       $a3, $a3, -0x6040
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1480, 0X9FC0));
    // 0x80803FA4: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80803FA8: jal         0x80089D68
    // 0x80803FAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_7(rdram, ctx);
        goto after_8;
    // 0x80803FAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // 0x80803FB0: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x80803FB4: beq         $a0, $zero, L_80803FD0
    if (ctx->r4 == 0) {
        // 0x80803FB8: sb          $v0, 0xB($s0)
        MEM_B(0XB, ctx->r16) = ctx->r2;
            goto L_80803FD0;
    }
    // 0x80803FB8: sb          $v0, 0xB($s0)
    MEM_B(0XB, ctx->r16) = ctx->r2;
    // 0x80803FBC: jal         0x800C31DC
    // 0x80803FC0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800C31DC(rdram, ctx);
        goto after_9;
    // 0x80803FC0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_9:
    // 0x80803FC4: lbu         $a0, 0xB($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XB);
    // 0x80803FC8: jal         0x800C3058
    // 0x80803FCC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800C3058(rdram, ctx);
        goto after_10;
    // 0x80803FCC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_10:
L_80803FD0:
    // 0x80803FD0: jal         0x80802314
    // 0x80803FD4: nop

    func_80802314_chdiggerboss(rdram, ctx);
        goto after_11;
    // 0x80803FD4: nop

    after_11:
    // 0x80803FD8: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80803FDC: beq         $at, $zero, L_80804028
    if (ctx->r1 == 0) {
        // 0x80803FE0: nop
    
            goto L_80804028;
    }
    // 0x80803FE0: nop

    // 0x80803FE4: jal         0x800D90A4
    // 0x80803FE8: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    func_800D90A4(rdram, ctx);
        goto after_12;
    // 0x80803FE8: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    after_12:
    // 0x80803FEC: beq         $v0, $zero, L_80804028
    if (ctx->r2 == 0) {
        // 0x80803FF0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80804028;
    }
    // 0x80803FF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80803FF4: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9F44) << 16);
    // 0x80803FF8: addiu       $a2, $a2, -0x60BC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9F44));
    // 0x80803FFC: jal         0x80089D18
    // 0x80804000: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_13;
    // 0x80804000: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_13:
    // 0x80804004: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9B5C) << 16);
    // 0x80804008: lwc1        $f12, -0x64A4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9B5C));
    // 0x8080400C: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80804010: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80804014: jal         0x800DC178
    // 0x80804018: nop

    func_800DC178(rdram, ctx);
        goto after_14;
    // 0x80804018: nop

    after_14:
    // 0x8080401C: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80804020: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    // 0x80804024: sb          $t3, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r11;
L_80804028:
    // 0x80804028: jal         0x80804680
    // 0x8080402C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80804680_chdiggerboss(rdram, ctx);
        goto after_15;
    // 0x8080402C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x80804030: jal         0x8001210C
    // 0x80804034: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001210C(rdram, ctx);
        goto after_16;
    // 0x80804034: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_16:
    // 0x80804038: beq         $v0, $zero, L_808040BC
    if (ctx->r2 == 0) {
        // 0x8080403C: nop
    
            goto L_808040BC;
    }
    // 0x8080403C: nop

    // 0x80804040: lbu         $t4, 0x9($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X9);
    // 0x80804044: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80804048: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8080404C: beq         $t4, $zero, L_80804078
    if (ctx->r12 == 0) {
        // 0x80804050: lui         $a2, 0x8081
        ctx->r6 = S32(RELOC_HI16(1480, 0X9F40) << 16);
            goto L_80804078;
    }
    // 0x80804050: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9F40) << 16);
    // 0x80804054: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9F3C) << 16);
    // 0x80804058: addiu       $a2, $a2, -0x60C4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9F3C));
    // 0x8080405C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80804060: jal         0x808043D8
    // 0x80804064: lui         $a1, 0x3FA0
    ctx->r5 = S32(0X3FA0 << 16);
    func_808043D8_chdiggerboss(rdram, ctx);
        goto after_17;
    // 0x80804064: lui         $a1, 0x3FA0
    ctx->r5 = S32(0X3FA0 << 16);
    after_17:
    // 0x80804068: lbu         $t5, 0x9($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X9);
    // 0x8080406C: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x80804070: b           L_808040BC
    // 0x80804074: sb          $t6, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r14;
        goto L_808040BC;
    // 0x80804074: sb          $t6, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r14;
L_80804078:
    // 0x80804078: jal         0x808043D8
    // 0x8080407C: addiu       $a2, $a2, -0x60C0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9F40));
    func_808043D8_chdiggerboss(rdram, ctx);
        goto after_18;
    // 0x8080407C: addiu       $a2, $a2, -0x60C0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9F40));
    after_18:
    // 0x80804080: b           L_808040BC
    // 0x80804084: nop

        goto L_808040BC;
    // 0x80804084: nop

L_80804088:
    // 0x80804088: lw          $t7, 0x70($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X70);
    // 0x8080408C: lbu         $a0, 0xC($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XC);
    // 0x80804090: lui         $a3, 0x8081
    ctx->r7 = S32(RELOC_HI16(1480, 0X9FD0) << 16);
    // 0x80804094: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80804098: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8080409C: addiu       $a3, $a3, -0x6030
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1480, 0X9FD0));
    // 0x808040A0: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x808040A4: jal         0x80089D68
    // 0x808040A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_7(rdram, ctx);
        goto after_19;
    // 0x808040A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_19:
    // 0x808040AC: b           L_808040BC
    // 0x808040B0: sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
        goto L_808040BC;
    // 0x808040B0: sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
L_808040B4:
    // 0x808040B4: jal         0x80804450
    // 0x808040B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80804450_chdiggerboss(rdram, ctx);
        goto after_20;
    // 0x808040B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_20:
L_808040BC:
    // 0x808040BC: jal         0x80804140
    // 0x808040C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80804140_chdiggerboss(rdram, ctx);
        goto after_21;
    // 0x808040C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_21:
    // 0x808040C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808040C8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808040CC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808040D0: jr          $ra
    // 0x808040D4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x808040D4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800C986C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C986C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C9870: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C9874: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C9878: lbu         $t6, 0x4($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X4);
    // 0x800C987C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C9880: sltiu       $at, $t6, 0x7
    ctx->r1 = ctx->r14 < 0X7 ? 1 : 0;
    // 0x800C9884: beq         $at, $zero, L_800C9960
    if (ctx->r1 == 0) {
        // 0x800C9888: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_800C9960;
    }
    // 0x800C9888: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800C988C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800C9890: addu        $at, $at, $t6
    gpr jr_addend_800C9898 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800C9894: lw          $t6, 0x5930($at)
    ctx->r14 = ADD32(ctx->r1, 0X5930);
    // 0x800C9898: jr          $t6
    // 0x800C989C: nop

    switch (jr_addend_800C9898 >> 2) {
        case 0: goto L_800C98A0; break;
        case 1: goto L_800C98B4; break;
        case 2: goto L_800C98CC; break;
        case 3: goto L_800C98E8; break;
        case 4: goto L_800C9904; break;
        case 5: goto L_800C9924; break;
        case 6: goto L_800C9950; break;
        default: switch_error(__func__, 0x800C9898, 0x80125930);
    }
    // 0x800C989C: nop

L_800C98A0:
    // 0x800C98A0: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x800C98A4: jalr        $t9
    // 0x800C98A8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800C98A8: nop

    after_0:
    // 0x800C98AC: b           L_800C9964
    // 0x800C98B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800C9964;
    // 0x800C98B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C98B4:
    // 0x800C98B4: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x800C98B8: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x800C98BC: jalr        $t9
    // 0x800C98C0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800C98C0: nop

    after_1:
    // 0x800C98C4: b           L_800C9964
    // 0x800C98C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800C9964;
    // 0x800C98C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C98CC:
    // 0x800C98CC: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x800C98D0: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x800C98D4: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    // 0x800C98D8: jalr        $t9
    // 0x800C98DC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800C98DC: nop

    after_2:
    // 0x800C98E0: b           L_800C9964
    // 0x800C98E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800C9964;
    // 0x800C98E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C98E8:
    // 0x800C98E8: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x800C98EC: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x800C98F0: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    // 0x800C98F4: jalr        $t9
    // 0x800C98F8: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x800C98F8: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    after_3:
    // 0x800C98FC: b           L_800C9964
    // 0x800C9900: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800C9964;
    // 0x800C9900: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C9904:
    // 0x800C9904: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x800C9908: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x800C990C: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    // 0x800C9910: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x800C9914: jalr        $t9
    // 0x800C9918: lw          $a3, 0x18($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X18);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x800C9918: lw          $a3, 0x18($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X18);
    after_4:
    // 0x800C991C: b           L_800C9964
    // 0x800C9920: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800C9964;
    // 0x800C9920: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C9924:
    // 0x800C9924: lw          $t7, 0x1C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1C);
    // 0x800C9928: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x800C992C: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    // 0x800C9930: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x800C9934: lw          $a3, 0x18($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X18);
    // 0x800C9938: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800C993C: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x800C9940: jalr        $t9
    // 0x800C9944: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x800C9944: nop

    after_5:
    // 0x800C9948: b           L_800C9964
    // 0x800C994C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800C9964;
    // 0x800C994C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C9950:
    // 0x800C9950: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x800C9954: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    // 0x800C9958: jalr        $t9
    // 0x800C995C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x800C995C: nop

    after_6:
L_800C9960:
    // 0x800C9960: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C9964:
    // 0x800C9964: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C9968: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C996C: jr          $ra
    // 0x800C9970: nop

    return;
    // 0x800C9970: nop

;}
RECOMP_FUNC void _idworldmake_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088F40: syscall     749
    recomp_syscall_handler(rdram, ctx, 0x80088F40);
    return;
    // 0x80088F44: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _ncbasuck_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089718: syscall     790
    recomp_syscall_handler(rdram, ctx, 0x80089718);
    return;
    // 0x8008971C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void gcmapsects_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801F24: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80801F28: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80801F2C: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x80801F30: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x80801F34: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80801F38: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80801F3C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80801F40: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80801F44: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80801F48: lbu         $v1, 0x77($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X77);
    // 0x80801F4C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80801F50: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801F54: blez        $v1, L_80802088
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80801F58: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80802088;
    }
    // 0x80801F58: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801F5C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80801F60: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2610, 0X29A4) << 16);
    // 0x80801F64: lwc1        $f20, 0x29A4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2610, 0X29A4));
    // 0x80801F68: lw          $t6, 0x68($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X68);
L_80801F6C:
    // 0x80801F6C: addu        $v0, $t6, $s0
    ctx->r2 = ADD32(ctx->r14, ctx->r16);
    // 0x80801F70: lw          $t7, 0x4C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4C);
    // 0x80801F74: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x80801F78: bnel        $t8, $zero, L_80801F9C
    if (ctx->r24 != 0) {
        // 0x80801F7C: lhu         $a1, 0x42($v0)
        ctx->r5 = MEM_HU(ctx->r2, 0X42);
            goto L_80801F9C;
    }
    goto skip_0;
    // 0x80801F7C: lhu         $a1, 0x42($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X42);
    skip_0:
    // 0x80801F80: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80801F84: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80801F88: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80801F8C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80801F90: b           L_80802078
    // 0x80801F94: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
        goto L_80802078;
    // 0x80801F94: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80801F98: lhu         $a1, 0x42($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X42);
L_80801F9C:
    // 0x80801F9C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80801FA0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80801FA4: bne         $a1, $zero, L_80801FB8
    if (ctx->r5 != 0) {
        // 0x80801FA8: sll         $v0, $v0, 2
        ctx->r2 = S32(ctx->r2 << 2);
            goto L_80801FB8;
    }
    // 0x80801FA8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80801FAC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80801FB0: b           L_80802078
    // 0x80801FB4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
        goto L_80802078;
    // 0x80801FB4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
L_80801FB8:
    // 0x80801FB8: jal         0x800D674C
    // 0x80801FBC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800D674C(rdram, ctx);
        goto after_0;
    // 0x80801FBC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80801FC0: bne         $v0, $zero, L_80801FE4
    if (ctx->r2 != 0) {
        // 0x80801FC4: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80801FE4;
    }
    // 0x80801FC4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80801FC8: lbu         $v1, 0x77($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X77);
    // 0x80801FCC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80801FD0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80801FD4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80801FD8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80801FDC: b           L_80802078
    // 0x80801FE0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
        goto L_80802078;
    // 0x80801FE0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
L_80801FE4:
    // 0x80801FE4: jal         0x800B2840
    // 0x80801FE8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800B2840(rdram, ctx);
        goto after_1;
    // 0x80801FE8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x80801FEC: jal         0x800BF774
    // 0x80801FF0: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    func_800BF774(rdram, ctx);
        goto after_2;
    // 0x80801FF0: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    after_2:
    // 0x80801FF4: jal         0x800DF830
    // 0x80801FF8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800DF830(rdram, ctx);
        goto after_3;
    // 0x80801FF8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // 0x80801FFC: jal         0x800DF440
    // 0x80802000: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DF440(rdram, ctx);
        goto after_4;
    // 0x80802000: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x80802004: jal         0x800DF428
    // 0x80802008: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_800DF428(rdram, ctx);
        goto after_5;
    // 0x80802008: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_5:
    // 0x8080200C: lw          $t9, 0x68($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X68);
    // 0x80802010: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x80802014: jal         0x800DF7DC
    // 0x80802018: lw          $a0, 0x48($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X48);
    func_800DF7DC(rdram, ctx);
        goto after_6;
    // 0x80802018: lw          $a0, 0x48($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X48);
    after_6:
    // 0x8080201C: jal         0x800DF818
    // 0x80802020: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800DF818(rdram, ctx);
        goto after_7;
    // 0x80802020: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_7:
    // 0x80802024: jal         0x800DF4B0
    // 0x80802028: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800DF4B0(rdram, ctx);
        goto after_8;
    // 0x80802028: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_8:
    // 0x8080202C: lw          $t1, 0x68($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X68);
    // 0x80802030: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80802034: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x80802038: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080203C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80802040: jal         0x800DE448
    // 0x80802044: addu        $a0, $t1, $s0
    ctx->r4 = ADD32(ctx->r9, ctx->r16);
    func_800DE448(rdram, ctx);
        goto after_9;
    // 0x80802044: addu        $a0, $t1, $s0
    ctx->r4 = ADD32(ctx->r9, ctx->r16);
    after_9:
    // 0x80802048: bnel        $v0, $zero, L_80802064
    if (ctx->r2 != 0) {
        // 0x8080204C: lbu         $v1, 0x77($s1)
        ctx->r3 = MEM_BU(ctx->r17, 0X77);
            goto L_80802064;
    }
    goto skip_1;
    // 0x8080204C: lbu         $v1, 0x77($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X77);
    skip_1:
    // 0x80802050: lw          $t2, 0x68($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X68);
    // 0x80802054: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x80802058: jal         0x800D62E4
    // 0x8080205C: lhu         $a0, 0x42($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0X42);
    func_800D62E4(rdram, ctx);
        goto after_10;
    // 0x8080205C: lhu         $a0, 0x42($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0X42);
    after_10:
    // 0x80802060: lbu         $v1, 0x77($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X77);
L_80802064:
    // 0x80802064: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80802068: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8080206C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80802070: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80802074: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
L_80802078:
    // 0x80802078: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    // 0x8080207C: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80802080: bnel        $at, $zero, L_80801F6C
    if (ctx->r1 != 0) {
        // 0x80802084: lw          $t6, 0x68($s1)
        ctx->r14 = MEM_W(ctx->r17, 0X68);
            goto L_80801F6C;
    }
    goto skip_2;
    // 0x80802084: lw          $t6, 0x68($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X68);
    skip_2:
L_80802088:
    // 0x80802088: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8080208C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80802090: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80802094: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80802098: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x8080209C: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x808020A0: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x808020A4: jr          $ra
    // 0x808020A8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x808020A8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_808005D0_chnutsnbolts(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005D0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x808005D4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808005D8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x808005DC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808005E0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x808005E4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x808005E8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x808005EC: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x808005F0: jal         0x80100094
    // 0x808005F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808005F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808005F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808005FC: beq         $s0, $at, L_808007B4
    if (ctx->r16 == ctx->r1) {
        // 0x80800600: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_808007B4;
    }
    // 0x80800600: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800604: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x80800608: beq         $s0, $at, L_80800898
    if (ctx->r16 == ctx->r1) {
        // 0x8080060C: addiu       $at, $zero, 0x3E
        ctx->r1 = ADD32(0, 0X3E);
            goto L_80800898;
    }
    // 0x8080060C: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x80800610: beq         $s0, $at, L_80800644
    if (ctx->r16 == ctx->r1) {
        // 0x80800614: addiu       $at, $zero, 0x3F
        ctx->r1 = ADD32(0, 0X3F);
            goto L_80800644;
    }
    // 0x80800614: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x80800618: beq         $s0, $at, L_8080067C
    if (ctx->r16 == ctx->r1) {
        // 0x8080061C: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8080067C;
    }
    // 0x8080061C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800620: beq         $s0, $at, L_808006BC
    if (ctx->r16 == ctx->r1) {
        // 0x80800624: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808006BC;
    }
    // 0x80800624: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800628: addiu       $at, $zero, 0x8E
    ctx->r1 = ADD32(0, 0X8E);
    // 0x8080062C: beq         $s0, $at, L_8080081C
    if (ctx->r16 == ctx->r1) {
        // 0x80800630: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_8080081C;
    }
    // 0x80800630: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800634: beq         $s0, $at, L_80800888
    if (ctx->r16 == ctx->r1) {
        // 0x80800638: nop
    
            goto L_80800888;
    }
    // 0x80800638: nop

    // 0x8080063C: b           L_808008E4
    // 0x80800640: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808008E4;
    // 0x80800640: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800644:
    // 0x80800644: lw          $t6, 0x64($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X64);
    // 0x80800648: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8080064C: bltzl       $t8, L_808008E4
    if (SIGNED(ctx->r24) < 0) {
        // 0x80800650: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808008E4;
    }
    goto skip_0;
    // 0x80800650: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800654: lhu         $t9, 0x72($s2)
    ctx->r25 = MEM_HU(ctx->r18, 0X72);
    // 0x80800658: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080065C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800660: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x80800664: bnel        $t0, $at, L_808008E4
    if (ctx->r8 != ctx->r1) {
        // 0x80800668: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808008E4;
    }
    goto skip_1;
    // 0x80800668: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x8080066C: jal         0x8080092C
    // 0x80800670: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_8080092C_chnutsnbolts(rdram, ctx);
        goto after_1;
    // 0x80800670: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_1:
    // 0x80800674: b           L_808008E4
    // 0x80800678: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808008E4;
    // 0x80800678: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080067C:
    // 0x8080067C: lw          $t1, 0x78($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X78);
    // 0x80800680: sll         $t3, $t1, 29
    ctx->r11 = S32(ctx->r9 << 29);
    // 0x80800684: bgezl       $t3, L_80800698
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80800688: lhu         $t4, 0x72($s2)
        ctx->r12 = MEM_HU(ctx->r18, 0X72);
            goto L_80800698;
    }
    goto skip_2;
    // 0x80800688: lhu         $t4, 0x72($s2)
    ctx->r12 = MEM_HU(ctx->r18, 0X72);
    skip_2:
    // 0x8080068C: b           L_808008E4
    // 0x80800690: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808008E4;
    // 0x80800690: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800694: lhu         $t4, 0x72($s2)
    ctx->r12 = MEM_HU(ctx->r18, 0X72);
L_80800698:
    // 0x80800698: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8080069C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808006A0: srl         $t5, $t4, 10
    ctx->r13 = S32(U32(ctx->r12) >> 10);
    // 0x808006A4: beql        $t5, $at, L_808008E4
    if (ctx->r13 == ctx->r1) {
        // 0x808006A8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808008E4;
    }
    goto skip_3;
    // 0x808006A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_3:
    // 0x808006AC: jal         0x8080092C
    // 0x808006B0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_8080092C_chnutsnbolts(rdram, ctx);
        goto after_2;
    // 0x808006B0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_2:
    // 0x808006B4: b           L_808008E4
    // 0x808006B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808008E4;
    // 0x808006B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006BC:
    // 0x808006BC: jal         0x80103DFC
    // 0x808006C0: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    func_80103DFC(rdram, ctx);
        goto after_3;
    // 0x808006C0: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    after_3:
    // 0x808006C4: lbu         $t6, 0x16($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X16);
    // 0x808006C8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x808006CC: addiu       $s1, $zero, 0x43E
    ctx->r17 = ADD32(0, 0X43E);
    // 0x808006D0: bne         $t6, $zero, L_80800714
    if (ctx->r14 != 0) {
        // 0x808006D4: addiu       $s0, $sp, 0x5C
        ctx->r16 = ADD32(ctx->r29, 0X5C);
            goto L_80800714;
    }
    // 0x808006D4: addiu       $s0, $sp, 0x5C
    ctx->r16 = ADD32(ctx->r29, 0X5C);
    // 0x808006D8: jal         0x8010A430
    // 0x808006DC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8010A430(rdram, ctx);
        goto after_4;
    // 0x808006DC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x808006E0: beq         $v0, $zero, L_808007A0
    if (ctx->r2 == 0) {
        // 0x808006E4: lui         $a0, 0x8008
        ctx->r4 = S32(0X8008 << 16);
            goto L_808007A0;
    }
    // 0x808006E4: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x808006E8: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x808006EC: addiu       $a0, $a0, 0x6D78
    ctx->r4 = ADD32(ctx->r4, 0X6D78);
    // 0x808006F0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808006F4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808006F8: lw          $t8, 0x48($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X48);
    // 0x808006FC: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x80800700: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x80800704: jal         0x80086D50
    // 0x80800708: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    _chbaddiesetup_entrypoint_5(rdram, ctx);
        goto after_5;
    // 0x80800708: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_5:
    // 0x8080070C: b           L_808007A4
    // 0x80800710: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
        goto L_808007A4;
    // 0x80800710: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80800714:
    // 0x80800714: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
    // 0x80800718: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8080071C:
    // 0x8080071C: jal         0x80089C30
    // 0x80800720: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80800720: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x80800724: beql        $v0, $zero, L_80800764
    if (ctx->r2 == 0) {
        // 0x80800728: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80800764;
    }
    goto skip_4;
    // 0x80800728: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_4:
L_8080072C:
    // 0x8080072C: beq         $v0, $s2, L_80800750
    if (ctx->r2 == ctx->r18) {
        // 0x80800730: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800750;
    }
    // 0x80800730: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800734: lhu         $t0, 0x72($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X72);
    // 0x80800738: srl         $t1, $t0, 10
    ctx->r9 = S32(U32(ctx->r8) >> 10);
    // 0x8080073C: slti        $at, $t1, 0x8
    ctx->r1 = SIGNED(ctx->r9) < 0X8 ? 1 : 0;
    // 0x80800740: beq         $at, $zero, L_80800750
    if (ctx->r1 == 0) {
        // 0x80800744: nop
    
            goto L_80800750;
    }
    // 0x80800744: nop

    // 0x80800748: b           L_80800770
    // 0x8080074C: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
        goto L_80800770;
    // 0x8080074C: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
L_80800750:
    // 0x80800750: jal         0x80089C38
    // 0x80800754: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _subaddiefind_entrypoint_3(rdram, ctx);
        goto after_7;
    // 0x80800754: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x80800758: bne         $v0, $zero, L_8080072C
    if (ctx->r2 != 0) {
        // 0x8080075C: nop
    
            goto L_8080072C;
    }
    // 0x8080075C: nop

    // 0x80800760: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80800764:
    // 0x80800764: slti        $at, $s1, 0x441
    ctx->r1 = SIGNED(ctx->r17) < 0X441 ? 1 : 0;
    // 0x80800768: bnel        $at, $zero, L_8080071C
    if (ctx->r1 != 0) {
        // 0x8080076C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8080071C;
    }
    goto skip_5;
    // 0x8080076C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_5:
L_80800770:
    // 0x80800770: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x80800774: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80800778: addiu       $a0, $a0, 0x6D78
    ctx->r4 = ADD32(ctx->r4, 0X6D78);
    // 0x8080077C: beq         $t2, $zero, L_808007A0
    if (ctx->r10 == 0) {
        // 0x80800780: lw          $t3, 0x68($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X68);
            goto L_808007A0;
    }
    // 0x80800780: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x80800784: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80800788: lw          $t4, 0x48($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X48);
    // 0x8080078C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800790: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x80800794: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x80800798: jal         0x80086D50
    // 0x8080079C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    _chbaddiesetup_entrypoint_5(rdram, ctx);
        goto after_8;
    // 0x8080079C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_8:
L_808007A0:
    // 0x808007A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808007A4:
    // 0x808007A4: jal         0x8080092C
    // 0x808007A8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_8080092C_chnutsnbolts(rdram, ctx);
        goto after_9;
    // 0x808007A8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_9:
    // 0x808007AC: b           L_808008E4
    // 0x808007B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808008E4;
    // 0x808007B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808007B4:
    // 0x808007B4: jal         0x8008A4A8
    // 0x808007B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    _subaddieDll_entrypoint_3(rdram, ctx);
        goto after_10;
    // 0x808007B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_10:
    // 0x808007BC: bne         $v0, $zero, L_808008E0
    if (ctx->r2 != 0) {
        // 0x808007C0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808008E0;
    }
    // 0x808007C0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808007C4: jal         0x80107070
    // 0x808007C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80107070(rdram, ctx);
        goto after_11;
    // 0x808007C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x808007CC: bne         $v0, $zero, L_808008E0
    if (ctx->r2 != 0) {
        // 0x808007D0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808008E0;
    }
    // 0x808007D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808007D4: jal         0x8080092C
    // 0x808007D8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_8080092C_chnutsnbolts(rdram, ctx);
        goto after_12;
    // 0x808007D8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_12:
    // 0x808007DC: jal         0x80089CA8
    // 0x808007E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_13;
    // 0x808007E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_13:
    // 0x808007E4: lbu         $t5, 0x71($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0X71);
    // 0x808007E8: lbu         $t1, 0x64($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X64);
    // 0x808007EC: andi        $t6, $t5, 0xFFFE
    ctx->r14 = ctx->r13 & 0XFFFE;
    // 0x808007F0: sb          $t6, 0x71($s2)
    MEM_B(0X71, ctx->r18) = ctx->r14;
    // 0x808007F4: lhu         $t8, 0x70($s2)
    ctx->r24 = MEM_HU(ctx->r18, 0X70);
    // 0x808007F8: andi        $t2, $t1, 0xFF7F
    ctx->r10 = ctx->r9 & 0XFF7F;
    // 0x808007FC: sll         $t0, $t8, 7
    ctx->r8 = S32(ctx->r24 << 7);
    // 0x80800800: or          $t5, $t0, $t2
    ctx->r13 = ctx->r8 | ctx->r10;
    // 0x80800804: andi        $t6, $t5, 0xFE
    ctx->r14 = ctx->r13 & 0XFE;
    // 0x80800808: andi        $t4, $t8, 0x1
    ctx->r12 = ctx->r24 & 0X1;
    // 0x8080080C: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x80800810: sb          $t5, 0x64($s2)
    MEM_B(0X64, ctx->r18) = ctx->r13;
    // 0x80800814: b           L_808008E0
    // 0x80800818: sb          $t7, 0x64($s2)
    MEM_B(0X64, ctx->r18) = ctx->r15;
        goto L_808008E0;
    // 0x80800818: sb          $t7, 0x64($s2)
    MEM_B(0X64, ctx->r18) = ctx->r15;
L_8080081C:
    // 0x8080081C: jal         0x80101038
    // 0x80800820: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    func_80101038(rdram, ctx);
        goto after_14;
    // 0x80800820: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    after_14:
    // 0x80800824: addiu       $s0, $s2, 0x28
    ctx->r16 = ADD32(ctx->r18, 0X28);
    // 0x80800828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080082C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80800830: jal         0x800EFB24
    // 0x80800834: addiu       $a2, $s2, 0x4
    ctx->r6 = ADD32(ctx->r18, 0X4);
    func_800EFB24(rdram, ctx);
        goto after_15;
    // 0x80800834: addiu       $a2, $s2, 0x4
    ctx->r6 = ADD32(ctx->r18, 0X4);
    after_15:
    // 0x80800838: lui         $at, 0x44E1
    ctx->r1 = S32(0X44E1 << 16);
    // 0x8080083C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800840: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x80800844: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800848: jal         0x800DC178
    // 0x8080084C: nop

    func_800DC178(rdram, ctx);
        goto after_16;
    // 0x8080084C: nop

    after_16:
    // 0x80800850: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800854: jal         0x800EF368
    // 0x80800858: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EF368(rdram, ctx);
        goto after_17;
    // 0x80800858: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x8080085C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800860: jal         0x8080092C
    // 0x80800864: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8080092C_chnutsnbolts(rdram, ctx);
        goto after_18;
    // 0x80800864: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_18:
    // 0x80800868: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080086C: jal         0x8008A4B0
    // 0x80800870: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_19;
    // 0x80800870: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x80800874: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800878: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8080087C: sb          $t8, 0x16($s1)
    MEM_B(0X16, ctx->r17) = ctx->r24;
    // 0x80800880: b           L_808008E0
    // 0x80800884: swc1        $f4, 0x58($s2)
    MEM_W(0X58, ctx->r18) = ctx->f4.u32l;
        goto L_808008E0;
    // 0x80800884: swc1        $f4, 0x58($s2)
    MEM_W(0X58, ctx->r18) = ctx->f4.u32l;
L_80800888:
    // 0x80800888: jal         0x80089F60
    // 0x8080088C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    _subaddierouteDll_entrypoint_1(rdram, ctx);
        goto after_20;
    // 0x8080088C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_20:
    // 0x80800890: b           L_808008E4
    // 0x80800894: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808008E4;
    // 0x80800894: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800898:
    // 0x80800898: lw          $t9, 0x6C($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X6C);
    // 0x8080089C: addiu       $at, $zero, 0x440
    ctx->r1 = ADD32(0, 0X440);
    // 0x808008A0: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1304, 0XE04) << 16);
    // 0x808008A4: sll         $t1, $t9, 11
    ctx->r9 = S32(ctx->r25 << 11);
    // 0x808008A8: srl         $t0, $t1, 20
    ctx->r8 = S32(U32(ctx->r9) >> 20);
    // 0x808008AC: bne         $t0, $at, L_808008C8
    if (ctx->r8 != ctx->r1) {
        // 0x808008B0: nop
    
            goto L_808008C8;
    }
    // 0x808008B0: nop

    // 0x808008B4: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1304, 0XE10) << 16);
    // 0x808008B8: jal         0x80101074
    // 0x808008BC: addiu       $a0, $a0, 0xE10
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1304, 0XE10));
    func_80101074(rdram, ctx);
        goto after_21;
    // 0x808008BC: addiu       $a0, $a0, 0xE10
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1304, 0XE10));
    after_21:
    // 0x808008C0: b           L_808008E4
    // 0x808008C4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_808008E4;
    // 0x808008C4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_808008C8:
    // 0x808008C8: jal         0x80101074
    // 0x808008CC: addiu       $a0, $a0, 0xE04
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1304, 0XE04));
    func_80101074(rdram, ctx);
        goto after_22;
    // 0x808008CC: addiu       $a0, $a0, 0xE04
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1304, 0XE04));
    after_22:
    // 0x808008D0: b           L_808008E4
    // 0x808008D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808008E4;
    // 0x808008D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808008D8: b           L_808008E4
    // 0x808008DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808008E4;
    // 0x808008DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808008E0:
    // 0x808008E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808008E4:
    // 0x808008E4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808008E8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808008EC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x808008F0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x808008F4: jr          $ra
    // 0x808008F8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x808008F8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void _baeggfire_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084B50: syscall     129
    recomp_syscall_handler(rdram, ctx, 0x80084B50);
    return;
    // 0x80084B54: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void capod_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080046C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800470: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800474: jal         0x8008FFE8
    // 0x80800478: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    func_8008FFE8(rdram, ctx);
        goto after_0;
    // 0x80800478: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x8080047C: beq         $v0, $zero, L_80800494
    if (ctx->r2 == 0) {
        // 0x80800480: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800494;
    }
    // 0x80800480: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800484: jal         0x800895A8
    // 0x80800488: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    _ncpod_entrypoint_29(rdram, ctx);
        goto after_1;
    // 0x80800488: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080048C: b           L_8080049C
    // 0x80800490: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080049C;
    // 0x80800490: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800494:
    // 0x80800494: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800498: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080049C:
    // 0x8080049C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004A0: jr          $ra
    // 0x808004A4: nop

    return;
    // 0x808004A4: nop

;}
RECOMP_FUNC void _chwaterfallgrillswitch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087010: syscall     492
    recomp_syscall_handler(rdram, ctx, 0x80087010);
    return;
    // 0x80087014: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chjinjo_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086B88: syscall     425
    recomp_syscall_handler(rdram, ctx, 0x80086B88);
    return;
    // 0x80086B8C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808000F4_chtntminecelldoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000FC: jal         0x80101080
    // 0x80800100: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80101080(rdram, ctx);
        goto after_0;
    // 0x80800100: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800104: jal         0x80106790
    // 0x80800108: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80800108: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8080010C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800110: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800114: jal         0x800866C0
    // 0x80800118: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _chexploder_entrypoint_13(rdram, ctx);
        goto after_2;
    // 0x80800118: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8080011C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800120: jal         0x800866B8
    // 0x80800124: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    _chexploder_entrypoint_12(rdram, ctx);
        goto after_3;
    // 0x80800124: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_3:
    // 0x80800128: jal         0x800DA544
    // 0x8080012C: addiu       $a0, $zero, 0x85
    ctx->r4 = ADD32(0, 0X85);
    func_800DA544(rdram, ctx);
        goto after_4;
    // 0x8080012C: addiu       $a0, $zero, 0x85
    ctx->r4 = ADD32(0, 0X85);
    after_4:
    // 0x80800130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800134: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800138: jr          $ra
    // 0x8080013C: nop

    return;
    // 0x8080013C: nop

;}
