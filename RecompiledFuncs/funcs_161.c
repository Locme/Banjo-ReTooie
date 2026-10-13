#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800904_chflysaucercrate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800904: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800908: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080090C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800910: jal         0x800DC0C0
    // 0x80800914: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800DC0C0(rdram, ctx);
        goto after_0;
    // 0x80800914: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800918: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1696, 0XCCC) << 16);
    // 0x8080091C: lwc1        $f4, 0xCCC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1696, 0XCCC));
    // 0x80800920: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80800924: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800928: nop

    // 0x8080092C: bc1fl       L_80800950
    if (!c1cs) {
        // 0x80800930: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800950;
    }
    goto skip_0;
    // 0x80800930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800934: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800938: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8080093C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800940: jal         0x800DC178
    // 0x80800944: nop

    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80800944: nop

    after_1:
    // 0x80800948: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x8080094C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800950:
    // 0x80800950: jal         0x80102B6C
    // 0x80800954: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80102B6C(rdram, ctx);
        goto after_2;
    // 0x80800954: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_2:
    // 0x80800958: jal         0x800DC0C0
    // 0x8080095C: nop

    func_800DC0C0(rdram, ctx);
        goto after_3;
    // 0x8080095C: nop

    after_3:
    // 0x80800960: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1696, 0XCD0) << 16);
    // 0x80800964: lwc1        $f6, 0xCD0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1696, 0XCD0));
    // 0x80800968: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x8080096C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80800970: nop

    // 0x80800974: bc1fl       L_80800998
    if (!c1cs) {
        // 0x80800978: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800998;
    }
    goto skip_1;
    // 0x80800978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x8080097C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800980: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800984: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800988: jal         0x800DC178
    // 0x8080098C: nop

    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x8080098C: nop

    after_4:
    // 0x80800990: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800998:
    // 0x80800998: jal         0x80102B2C
    // 0x8080099C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80102B2C(rdram, ctx);
        goto after_5;
    // 0x8080099C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_5:
    // 0x808009A0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x808009A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808009A8: lwc1        $f2, 0x4C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x808009AC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808009B0: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x808009B4: nop

    // 0x808009B8: bc1fl       L_808009E4
    if (!c1cs) {
        // 0x808009BC: lui         $at, 0xC120
        ctx->r1 = S32(0XC120 << 16);
            goto L_808009E4;
    }
    goto skip_2;
    // 0x808009BC: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    skip_2:
    // 0x808009C0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x808009C4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808009C8: jal         0x800DC178
    // 0x808009CC: nop

    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x808009CC: nop

    after_6:
    // 0x808009D0: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x808009D4: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x808009D8: swc1        $f16, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f16.u32l;
    // 0x808009DC: lwc1        $f2, 0x4C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x808009E0: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
L_808009E4:
    // 0x808009E4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808009E8: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x808009EC: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x808009F0: nop

    // 0x808009F4: bc1fl       L_80800A1C
    if (!c1cs) {
        // 0x808009F8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800A1C;
    }
    goto skip_3;
    // 0x808009F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x808009FC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800A00: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800A04: jal         0x800DC178
    // 0x80800A08: nop

    func_800DC178(rdram, ctx);
        goto after_7;
    // 0x80800A08: nop

    after_7:
    // 0x80800A0C: lwc1        $f4, 0x4C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80800A10: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80800A14: swc1        $f6, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f6.u32l;
    // 0x80800A18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800A1C:
    // 0x80800A1C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800A20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800A24: jr          $ra
    // 0x80800A28: nop

    return;
    // 0x80800A28: nop

;}
RECOMP_FUNC void baduo_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080061C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800620: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800624: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80800628: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8080062C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800630: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800634: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800638: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080063C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800640: jal         0x800F6224
    // 0x80800644: lw          $a0, 0x184($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X184);
    func_800F6224(rdram, ctx);
        goto after_0;
    // 0x80800644: lw          $a0, 0x184($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X184);
    after_0:
    // 0x80800648: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x8080064C: jal         0x800F53D0
    // 0x80800650: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F53D0(rdram, ctx);
        goto after_1;
    // 0x80800650: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800654: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800658: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080065C: jal         0x800F452C
    // 0x80800660: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800F452C(rdram, ctx);
        goto after_2;
    // 0x80800660: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x80800664: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800668: jal         0x800A3410
    // 0x8080066C: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    func_800A3410(rdram, ctx);
        goto after_3;
    // 0x8080066C: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_3:
    // 0x80800670: jal         0x80092778
    // 0x80800674: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80092778(rdram, ctx);
        goto after_4;
    // 0x80800674: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_4:
    // 0x80800678: jal         0x800844B0
    // 0x8080067C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    _bababykaz_entrypoint_8(rdram, ctx);
        goto after_5;
    // 0x8080067C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_5:
    // 0x80800680: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800684: jal         0x80800008
    // 0x80800688: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_80800008_baduo(rdram, ctx);
        goto after_6;
    // 0x80800688: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_6:
    // 0x8080068C: jal         0x800A4CA8
    // 0x80800690: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_7;
    // 0x80800690: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_7:
    // 0x80800694: addiu       $s1, $sp, 0x34
    ctx->r17 = ADD32(ctx->r29, 0X34);
    // 0x80800698: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8080069C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808006A0: jal         0x800F3BB0
    // 0x808006A4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800F3BB0(rdram, ctx);
        goto after_8;
    // 0x808006A4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_8:
    // 0x808006A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006AC: jal         0x800EEB40
    // 0x808006B0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EEB40(rdram, ctx);
        goto after_9;
    // 0x808006B0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_9:
    // 0x808006B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(496, 0XCE0) << 16);
    // 0x808006B8: lwc1        $f4, 0xCE0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(496, 0XCE0));
    // 0x808006BC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x808006C0: nop

    // 0x808006C4: bc1f        L_808006E4
    if (!c1cs) {
        // 0x808006C8: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_808006E4;
    }
    // 0x808006C8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808006CC: addiu       $s1, $zero, 0x3C
    ctx->r17 = ADD32(0, 0X3C);
L_808006D0:
    // 0x808006D0: jal         0x80110588
    // 0x808006D4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80110588(rdram, ctx);
        goto after_10;
    // 0x808006D4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_10:
    // 0x808006D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808006DC: bne         $s0, $s1, L_808006D0
    if (ctx->r16 != ctx->r17) {
        // 0x808006E0: nop
    
            goto L_808006D0;
    }
    // 0x808006E0: nop

L_808006E4:
    // 0x808006E4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808006E8: jal         0x8009E5C8
    // 0x808006EC: addiu       $a1, $zero, 0x136
    ctx->r5 = ADD32(0, 0X136);
    bs_setState(rdram, ctx);
        goto after_11;
    // 0x808006EC: addiu       $a1, $zero, 0x136
    ctx->r5 = ADD32(0, 0X136);
    after_11:
    // 0x808006F0: jal         0x800F8128
    // 0x808006F4: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    func_800F8128(rdram, ctx);
        goto after_12;
    // 0x808006F4: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_12:
    // 0x808006F8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808006FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800700: jal         0x800A38F0
    // 0x80800704: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800A38F0(rdram, ctx);
        goto after_13;
    // 0x80800704: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_13:
    // 0x80800708: jal         0x800F8EE4
    // 0x8080070C: lw          $a0, 0x184($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X184);
    func_800F8EE4(rdram, ctx);
        goto after_14;
    // 0x8080070C: lw          $a0, 0x184($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X184);
    after_14:
    // 0x80800710: jal         0x800848D0
    // 0x80800714: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    _badrone_entrypoint_29(rdram, ctx);
        goto after_15;
    // 0x80800714: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_15:
    // 0x80800718: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8080071C: jal         0x8009E5C8
    // 0x80800720: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_16;
    // 0x80800720: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_16:
    // 0x80800724: addiu       $a0, $zero, 0xE8
    ctx->r4 = ADD32(0, 0XE8);
    // 0x80800728: jal         0x8008A298
    // 0x8080072C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    _sudialog_entrypoint_0(rdram, ctx);
        goto after_17;
    // 0x8080072C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_17:
    // 0x80800730: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800734: jal         0x80800C78
    // 0x80800738: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    func_80800C78_baduo(rdram, ctx);
        goto after_18;
    // 0x80800738: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_18:
    // 0x8080073C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800740: jal         0x80800CA8
    // 0x80800744: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_80800CA8_baduo(rdram, ctx);
        goto after_19;
    // 0x80800744: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_19:
    // 0x80800748: lw          $a0, 0x184($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X184);
    // 0x8080074C: jal         0x800F86C4
    // 0x80800750: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    func_800F86C4(rdram, ctx);
        goto after_20;
    // 0x80800750: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_20:
    // 0x80800754: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800758: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080075C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800760: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800764: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80800768: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8080076C: jr          $ra
    // 0x80800770: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80800770: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_800D4E7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4E7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D4E80: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800D4E84: bne         $a0, $at, L_800D4E90
    if (ctx->r4 != ctx->r1) {
        // 0x800D4E88: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800D4E90;
    }
    // 0x800D4E88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D4E8C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800D4E90:
    // 0x800D4E90: jal         0x800D4DD0
    // 0x800D4E94: nop

    func_800D4DD0(rdram, ctx);
        goto after_0;
    // 0x800D4E94: nop

    after_0:
    // 0x800D4E98: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800D4E9C: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x800D4EA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D4EA4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800D4EA8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800D4EAC: lbu         $v0, -0x49BF($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X49BF);
    // 0x800D4EB0: jr          $ra
    // 0x800D4EB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800D4EB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _susplinet_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089E40: syscall     812
    recomp_syscall_handler(rdram, ctx, 0x80089E40);
    return;
    // 0x80089E44: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void glglobalsettings_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800408: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080040C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800410: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800414: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800418: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8080041C: jal         0x800DA564
    // 0x80800420: addiu       $a0, $zero, 0xBBA
    ctx->r4 = ADD32(0, 0XBBA);
    func_800DA564(rdram, ctx);
        goto after_0;
    // 0x80800420: addiu       $a0, $zero, 0xBBA
    ctx->r4 = ADD32(0, 0XBBA);
    after_0:
    // 0x80800424: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800428: addiu       $t6, $v0, -0x20
    ctx->r14 = ADD32(ctx->r2, -0X20);
    // 0x8080042C: addiu       $a0, $zero, 0xBC0
    ctx->r4 = ADD32(0, 0XBC0);
    // 0x80800430: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80800434: jal         0x800DA564
    // 0x80800438: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    func_800DA564(rdram, ctx);
        goto after_1;
    // 0x80800438: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    after_1:
    // 0x8080043C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80800440: addiu       $t8, $v0, -0x28
    ctx->r24 = ADD32(ctx->r2, -0X28);
    // 0x80800444: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80800448: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080044C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800450: jr          $ra
    // 0x80800454: nop

    return;
    // 0x80800454: nop

;}
RECOMP_FUNC void _badrone_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084858: syscall     122
    recomp_syscall_handler(rdram, ctx, 0x80084858);
    return;
    // 0x8008485C: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void func_8008BD1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008BD1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008BD20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008BD24: jal         0x8008BCEC
    // 0x8008BD28: lbu         $a1, 0x8($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X8);
    func_8008BCEC(rdram, ctx);
        goto after_0;
    // 0x8008BD28: lbu         $a1, 0x8($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X8);
    after_0:
    // 0x8008BD2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008BD30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008BD34: jr          $ra
    // 0x8008BD38: nop

    return;
    // 0x8008BD38: nop

;}
RECOMP_FUNC void func_8009AE08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009AE08: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8009AE0C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8009AE10: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8009AE14: lw          $v0, 0xC8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC8);
    // 0x8009AE18: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8009AE1C: lwc1        $f4, 0x3C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8009AE20: lwc1        $f6, 0x50($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X50);
    // 0x8009AE24: addiu       $a0, $v0, 0x1C
    ctx->r4 = ADD32(ctx->r2, 0X1C);
    // 0x8009AE28: lw          $a1, 0x40($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X40);
    // 0x8009AE2C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8009AE30: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8009AE34: jal         0x800EEB9C
    // 0x8009AE38: nop

    func_800EEB9C(rdram, ctx);
        goto after_0;
    // 0x8009AE38: nop

    after_0:
    // 0x8009AE3C: lw          $t6, 0xC8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC8);
    // 0x8009AE40: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8009AE44: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x8009AE48: lwc1        $f10, 0x10($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X10);
    // 0x8009AE4C: swc1        $f16, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f16.u32l;
    // 0x8009AE50: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    // 0x8009AE54: lw          $t7, 0xC8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC8);
    // 0x8009AE58: lwc1        $f18, 0x18($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X18);
    // 0x8009AE5C: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    // 0x8009AE60: lw          $a1, 0xC8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC8);
    // 0x8009AE64: jal         0x800EE7F8
    // 0x8009AE68: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x8009AE68: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_1:
    // 0x8009AE6C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8009AE70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009AE74: jal         0x80096518
    // 0x8009AE78: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    func_80096518(rdram, ctx);
        goto after_2;
    // 0x8009AE78: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x8009AE7C: beq         $v0, $zero, L_8009AF88
    if (ctx->r2 == 0) {
        // 0x8009AE80: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8009AF88;
    }
    // 0x8009AE80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009AE84: jal         0x800963C0
    // 0x8009AE88: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_800963C0(rdram, ctx);
        goto after_3;
    // 0x8009AE88: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_3:
    // 0x8009AE8C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8009AE90: jal         0x800EF410
    // 0x8009AE94: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    func_800EF410(rdram, ctx);
        goto after_4;
    // 0x8009AE94: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_4:
    // 0x8009AE98: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8009AE9C: jal         0x800EEAA4
    // 0x8009AEA0: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_800EEAA4(rdram, ctx);
        goto after_5;
    // 0x8009AEA0: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_5:
    // 0x8009AEA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009AEA8: jal         0x800A3378
    // 0x8009AEAC: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    func_800A3378(rdram, ctx);
        goto after_6;
    // 0x8009AEAC: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x8009AEB0: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8009AEB4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8009AEB8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8009AEBC: c.eq.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl == ctx->f14.fl;
    // 0x8009AEC0: nop

    // 0x8009AEC4: bc1t        L_8009AF88
    if (c1cs) {
        // 0x8009AEC8: nop
    
            goto L_8009AF88;
    }
    // 0x8009AEC8: nop

    // 0x8009AECC: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x8009AED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009AED4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8009AED8: bc1fl       L_8009AF68
    if (!c1cs) {
        // 0x8009AEDC: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_8009AF68;
    }
    goto skip_0;
    // 0x8009AEDC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_0:
    // 0x8009AEE0: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    // 0x8009AEE4: jal         0x8008E1C4
    // 0x8009AEE8: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    func_8008E1C4(rdram, ctx);
        goto after_7;
    // 0x8009AEE8: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    after_7:
    // 0x8009AEEC: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8009AEF0: beq         $v0, $zero, L_8009AF2C
    if (ctx->r2 == 0) {
        // 0x8009AEF4: lwc1        $f12, 0x38($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
            goto L_8009AF2C;
    }
    // 0x8009AEF4: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8009AEF8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8009AEFC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009AF00: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8009AF04: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8009AF08: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8009AF0C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8009AF10: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8009AF14: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8009AF18: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8009AF1C: jal         0x800F10B4
    // 0x8009AF20: nop

    func_800F10B4(rdram, ctx);
        goto after_8;
    // 0x8009AF20: nop

    after_8:
    // 0x8009AF24: b           L_8009AF40
    // 0x8009AF28: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
        goto L_8009AF40;
    // 0x8009AF28: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_8009AF2C:
    // 0x8009AF2C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8009AF30: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009AF34: nop

    // 0x8009AF38: mul.s       $f12, $f2, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8009AF3C: nop

L_8009AF40:
    // 0x8009AF40: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8009AF44: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009AF48: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x8009AF4C: add.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f12.fl;
    // 0x8009AF50: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8009AF54: jal         0x800EF334
    // 0x8009AF58: nop

    func_800EF334(rdram, ctx);
        goto after_9;
    // 0x8009AF58: nop

    after_9:
    // 0x8009AF5C: b           L_8009AF88
    // 0x8009AF60: nop

        goto L_8009AF88;
    // 0x8009AF60: nop

    // 0x8009AF64: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_8009AF68:
    // 0x8009AF68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009AF6C: lwc1        $f8, 0x52A0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X52A0);
    // 0x8009AF70: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x8009AF74: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x8009AF78: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8009AF7C: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8009AF80: jal         0x800EF334
    // 0x8009AF84: nop

    func_800EF334(rdram, ctx);
        goto after_10;
    // 0x8009AF84: nop

    after_10:
L_8009AF88:
    // 0x8009AF88: jal         0x80094E98
    // 0x8009AF8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80094E98(rdram, ctx);
        goto after_11;
    // 0x8009AF8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8009AF90: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8009AF94: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x8009AF98: jal         0x800EFA20
    // 0x8009AF9C: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    func_800EFA20(rdram, ctx);
        goto after_12;
    // 0x8009AF9C: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_12:
    // 0x8009AFA0: jal         0x80094E98
    // 0x8009AFA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80094E98(rdram, ctx);
        goto after_13;
    // 0x8009AFA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8009AFA8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8009AFAC: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x8009AFB0: jal         0x800EFA20
    // 0x8009AFB4: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    func_800EFA20(rdram, ctx);
        goto after_14;
    // 0x8009AFB4: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    after_14:
    // 0x8009AFB8: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x8009AFBC: jal         0x800EF3DC
    // 0x8009AFC0: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    func_800EF3DC(rdram, ctx);
        goto after_15;
    // 0x8009AFC0: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    after_15:
    // 0x8009AFC4: jal         0x800D8FF8
    // 0x8009AFC8: nop

    func_800D8FF8(rdram, ctx);
        goto after_16;
    // 0x8009AFC8: nop

    after_16:
    // 0x8009AFCC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8009AFD0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009AFD4: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x8009AFD8: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8009AFDC: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8009AFE0: jal         0x800EF334
    // 0x8009AFE4: nop

    func_800EF334(rdram, ctx);
        goto after_17;
    // 0x8009AFE4: nop

    after_17:
    // 0x8009AFE8: lw          $a0, 0xC8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC8);
    // 0x8009AFEC: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    // 0x8009AFF0: jal         0x800EF04C
    // 0x8009AFF4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_800EF04C(rdram, ctx);
        goto after_18;
    // 0x8009AFF4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_18:
    // 0x8009AFF8: jal         0x800D8FF8
    // 0x8009AFFC: nop

    func_800D8FF8(rdram, ctx);
        goto after_19;
    // 0x8009AFFC: nop

    after_19:
    // 0x8009B000: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
    // 0x8009B004: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x8009B008: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8009B00C: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8009B010: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8009B014: swc1        $f16, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f16.u32l;
    // 0x8009B018: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
    // 0x8009B01C: lwc1        $f2, 0x38($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8009B020: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8009B024: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x8009B028: nop

    // 0x8009B02C: bc1f        L_8009B038
    if (!c1cs) {
        // 0x8009B030: nop
    
            goto L_8009B038;
    }
    // 0x8009B030: nop

    // 0x8009B034: swc1        $f2, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f2.u32l;
L_8009B038:
    // 0x8009B038: jal         0x800D8FF8
    // 0x8009B03C: nop

    func_800D8FF8(rdram, ctx);
        goto after_20;
    // 0x8009B03C: nop

    after_20:
    // 0x8009B040: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
    // 0x8009B044: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8009B048: addiu       $a0, $v0, 0x28
    ctx->r4 = ADD32(ctx->r2, 0X28);
    // 0x8009B04C: jal         0x800EFA20
    // 0x8009B050: addiu       $a1, $v0, 0x10
    ctx->r5 = ADD32(ctx->r2, 0X10);
    func_800EFA20(rdram, ctx);
        goto after_21;
    // 0x8009B050: addiu       $a1, $v0, 0x10
    ctx->r5 = ADD32(ctx->r2, 0X10);
    after_21:
    // 0x8009B054: lw          $v0, 0xC8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC8);
    // 0x8009B058: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x8009B05C: jal         0x800EF04C
    // 0x8009B060: addiu       $a1, $v0, 0x28
    ctx->r5 = ADD32(ctx->r2, 0X28);
    func_800EF04C(rdram, ctx);
        goto after_22;
    // 0x8009B060: addiu       $a1, $v0, 0x28
    ctx->r5 = ADD32(ctx->r2, 0X28);
    after_22:
    // 0x8009B064: lw          $a0, 0xC8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC8);
    // 0x8009B068: lui         $a1, 0x38D1
    ctx->r5 = S32(0X38D1 << 16);
    // 0x8009B06C: ori         $a1, $a1, 0xB717
    ctx->r5 = ctx->r5 | 0XB717;
    // 0x8009B070: jal         0x800F2168
    // 0x8009B074: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_800F2168(rdram, ctx);
        goto after_23;
    // 0x8009B074: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_23:
    // 0x8009B078: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8009B07C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8009B080: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x8009B084: jr          $ra
    // 0x8009B088: nop

    return;
    // 0x8009B088: nop

;}
RECOMP_FUNC void func_808001F4_chlagoonbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001FC: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800200: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800204: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80800208: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x8080020C: bnel        $t7, $at, L_80800230
    if (ctx->r15 != ctx->r1) {
        // 0x80800210: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800230;
    }
    goto skip_0;
    // 0x80800210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800214: jal         0x8008A4C0
    // 0x80800218: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _subaddieDll_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x80800218: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080021C: beq         $v0, $zero, L_8080022C
    if (ctx->r2 == 0) {
        // 0x80800220: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080022C;
    }
    // 0x80800220: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800224: jal         0x8080023C
    // 0x80800228: nop

    func_8080023C_chlagoonbits(rdram, ctx);
        goto after_1;
    // 0x80800228: nop

    after_1:
L_8080022C:
    // 0x8080022C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800230:
    // 0x80800230: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800234: jr          $ra
    // 0x80800238: nop

    return;
    // 0x80800238: nop

;}
RECOMP_FUNC void sulights_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808004F8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808004FC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800500: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80800504: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800508: jal         0x80800000
    // 0x8080050C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80800000_sulights(rdram, ctx);
        goto after_0;
    // 0x8080050C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x80800510: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3374, 0X9E4) << 16);
    // 0x80800514: lwc1        $f0, 0x9E4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3374, 0X9E4));
    // 0x80800518: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8080051C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800520: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800524: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80800528: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8080052C: bc1fl       L_80800540
    if (!c1cs) {
        // 0x80800530: swc1        $f2, 0x38($v0)
        MEM_W(0X38, ctx->r2) = ctx->f2.u32l;
            goto L_80800540;
    }
    goto skip_0;
    // 0x80800530: swc1        $f2, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f2.u32l;
    skip_0:
    // 0x80800534: b           L_80800540
    // 0x80800538: swc1        $f0, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f0.u32l;
        goto L_80800540;
    // 0x80800538: swc1        $f0, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f0.u32l;
    // 0x8080053C: swc1        $f2, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f2.u32l;
L_80800540:
    // 0x80800540: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800544: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
L_80800548:
    // 0x80800548: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8080054C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80800550: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800554: swc1        $f4, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f4.u32l;
    // 0x80800558: lwc1        $f8, -0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, -0X4);
    // 0x8080055C: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80800560: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80800564: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800568: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8080056C: bne         $a1, $a3, L_80800548
    if (ctx->r5 != ctx->r7) {
        // 0x80800570: swc1        $f10, 0x24($a0)
        MEM_W(0X24, ctx->r4) = ctx->f10.u32l;
            goto L_80800548;
    }
    // 0x80800570: swc1        $f10, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f10.u32l;
    // 0x80800574: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800578: jal         0x800C8D4C
    // 0x8080057C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800C8D4C(rdram, ctx);
        goto after_1;
    // 0x8080057C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80800580: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800584: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800588: jr          $ra
    // 0x8080058C: nop

    return;
    // 0x8080058C: nop

;}
RECOMP_FUNC void suexpression_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800610: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800614: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800618: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8080061C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800620: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80800624: mul.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80800628: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8080062C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80800630: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80800634: nop

    // 0x80800638: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8080063C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80800640: nop

    // 0x80800644: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80800648: beql        $t7, $zero, L_80800698
    if (ctx->r15 == 0) {
        // 0x8080064C: mfc1        $t7, $f6
        ctx->r15 = (int32_t)ctx->f6.u32l;
            goto L_80800698;
    }
    goto skip_0;
    // 0x8080064C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x80800650: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800654: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800658: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8080065C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80800660: nop

    // 0x80800664: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80800668: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8080066C: nop

    // 0x80800670: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80800674: bne         $t7, $zero, L_8080068C
    if (ctx->r15 != 0) {
        // 0x80800678: nop
    
            goto L_8080068C;
    }
    // 0x80800678: nop

    // 0x8080067C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80800680: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800684: b           L_808006A4
    // 0x80800688: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_808006A4;
    // 0x80800688: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_8080068C:
    // 0x8080068C: b           L_808006A4
    // 0x80800690: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_808006A4;
    // 0x80800690: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80800694: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
L_80800698:
    // 0x80800698: nop

    // 0x8080069C: bltz        $t7, L_8080068C
    if (SIGNED(ctx->r15) < 0) {
        // 0x808006A0: nop
    
            goto L_8080068C;
    }
    // 0x808006A0: nop

L_808006A4:
    // 0x808006A4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x808006A8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x808006AC: sb          $t7, 0x10($a0)
    MEM_B(0X10, ctx->r4) = ctx->r15;
    // 0x808006B0: mul.s       $f8, $f0, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x808006B4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808006B8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x808006BC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x808006C0: nop

    // 0x808006C4: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x808006C8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x808006CC: nop

    // 0x808006D0: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x808006D4: beql        $t9, $zero, L_80800724
    if (ctx->r25 == 0) {
        // 0x808006D8: mfc1        $t9, $f10
        ctx->r25 = (int32_t)ctx->f10.u32l;
            goto L_80800724;
    }
    goto skip_1;
    // 0x808006D8: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    skip_1:
    // 0x808006DC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808006E0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x808006E4: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x808006E8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x808006EC: nop

    // 0x808006F0: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x808006F4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x808006F8: nop

    // 0x808006FC: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80800700: bne         $t9, $zero, L_80800718
    if (ctx->r25 != 0) {
        // 0x80800704: nop
    
            goto L_80800718;
    }
    // 0x80800704: nop

    // 0x80800708: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8080070C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800710: b           L_80800730
    // 0x80800714: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_80800730;
    // 0x80800714: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_80800718:
    // 0x80800718: b           L_80800730
    // 0x8080071C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_80800730;
    // 0x8080071C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80800720: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
L_80800724:
    // 0x80800724: nop

    // 0x80800728: bltz        $t9, L_80800718
    if (SIGNED(ctx->r25) < 0) {
        // 0x8080072C: nop
    
            goto L_80800718;
    }
    // 0x8080072C: nop

L_80800730:
    // 0x80800730: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80800734: jr          $ra
    // 0x80800738: sb          $t9, 0x11($a0)
    MEM_B(0X11, ctx->r4) = ctx->r25;
    return;
    // 0x80800738: sb          $t9, 0x11($a0)
    MEM_B(0X11, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void func_800B196C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B196C: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x800B1970: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x800B1974: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x800B1978: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x800B197C: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x800B1980: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x800B1984: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x800B1988: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x800B198C: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x800B1990: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x800B1994: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x800B1998: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x800B199C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x800B19A0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800B19A4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800B19A8: sw          $a1, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r5;
    // 0x800B19AC: sw          $a2, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r6;
    // 0x800B19B0: sw          $a3, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r7;
    // 0x800B19B4: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x800B19B8: lh          $t8, 0x2($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X2);
    // 0x800B19BC: lwc1        $f24, 0xEC($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x800B19C0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800B19C4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800B19C8: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800B19CC: addu        $s0, $t7, $a0
    ctx->r16 = ADD32(ctx->r15, ctx->r4);
    // 0x800B19D0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800B19D4: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x800B19D8: addu        $s7, $t9, $s0
    ctx->r23 = ADD32(ctx->r25, ctx->r16);
    // 0x800B19DC: sltu        $at, $s0, $s7
    ctx->r1 = ctx->r16 < ctx->r23 ? 1 : 0;
    // 0x800B19E0: beq         $at, $zero, L_800B1CF8
    if (ctx->r1 == 0) {
        // 0x800B19E4: lw          $fp, 0xF0($sp)
        ctx->r30 = MEM_W(ctx->r29, 0XF0);
            goto L_800B1CF8;
    }
    // 0x800B19E4: lw          $fp, 0xF0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0XF0);
    // 0x800B19E8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800B19EC: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x800B19F0: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800B19F4: addiu       $s6, $sp, 0x7C
    ctx->r22 = ADD32(ctx->r29, 0X7C);
    // 0x800B19F8: addiu       $s5, $sp, 0x88
    ctx->r21 = ADD32(ctx->r29, 0X88);
    // 0x800B19FC: addiu       $s4, $sp, 0x70
    ctx->r20 = ADD32(ctx->r29, 0X70);
    // 0x800B1A00: addiu       $s3, $sp, 0x94
    ctx->r19 = ADD32(ctx->r29, 0X94);
    // 0x800B1A04: addiu       $s2, $sp, 0xA0
    ctx->r18 = ADD32(ctx->r29, 0XA0);
    // 0x800B1A08: lw          $s1, 0xE8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XE8);
    // 0x800B1A0C: lbu         $v0, 0xD($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XD);
L_800B1A10:
    // 0x800B1A10: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800B1A14: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800B1A18: sllv        $t1, $t0, $v0
    ctx->r9 = S32(ctx->r8 << (ctx->r2 & 31));
    // 0x800B1A1C: and         $t2, $t1, $fp
    ctx->r10 = ctx->r9 & ctx->r30;
    // 0x800B1A20: bnel        $t2, $zero, L_800B1CEC
    if (ctx->r10 != 0) {
        // 0x800B1A24: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_800B1CEC;
    }
    goto skip_0;
    // 0x800B1A24: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    skip_0:
    // 0x800B1A28: lh          $t3, 0x4($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X4);
    // 0x800B1A2C: lw          $a0, 0xE4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE4);
    // 0x800B1A30: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800B1A34: nop

    // 0x800B1A38: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B1A3C: swc1        $f6, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f6.u32l;
    // 0x800B1A40: lh          $t4, 0x6($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X6);
    // 0x800B1A44: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x800B1A48: nop

    // 0x800B1A4C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B1A50: swc1        $f10, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f10.u32l;
    // 0x800B1A54: lh          $t5, 0x8($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X8);
    // 0x800B1A58: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x800B1A5C: nop

    // 0x800B1A60: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800B1A64: swc1        $f4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f4.u32l;
    // 0x800B1A68: lbu         $t6, 0xA($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XA);
    // 0x800B1A6C: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800B1A70: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800B1A74: nop

    // 0x800B1A78: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800B1A7C: swc1        $f8, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f8.u32l;
    // 0x800B1A80: lbu         $t8, 0xB($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XB);
    // 0x800B1A84: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800B1A88: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x800B1A8C: nop

    // 0x800B1A90: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800B1A94: swc1        $f18, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f18.u32l;
    // 0x800B1A98: lbu         $t0, 0xC($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0XC);
    // 0x800B1A9C: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x800B1AA0: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800B1AA4: nop

    // 0x800B1AA8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B1AAC: swc1        $f6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f6.u32l;
    // 0x800B1AB0: jal         0x800ADE2C
    // 0x800B1AB4: lb          $a1, 0xE($s0)
    ctx->r5 = MEM_B(ctx->r16, 0XE);
    func_800ADE2C(rdram, ctx);
        goto after_0;
    // 0x800B1AB4: lb          $a1, 0xE($s0)
    ctx->r5 = MEM_B(ctx->r16, 0XE);
    after_0:
    // 0x800B1AB8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800B1ABC: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    // 0x800B1AC0: jal         0x80019AA0
    // 0x800B1AC4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80019AA0(rdram, ctx);
        goto after_1;
    // 0x800B1AC4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x800B1AC8: addiu       $a0, $sp, 0xC0
    ctx->r4 = ADD32(ctx->r29, 0XC0);
    // 0x800B1ACC: jal         0x800198D4
    // 0x800B1AD0: addiu       $a1, $sp, 0xB4
    ctx->r5 = ADD32(ctx->r29, 0XB4);
    func_800198D4(rdram, ctx);
        goto after_2;
    // 0x800B1AD0: addiu       $a1, $sp, 0xB4
    ctx->r5 = ADD32(ctx->r29, 0XB4);
    after_2:
    // 0x800B1AD4: lh          $t2, 0x2($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X2);
    // 0x800B1AD8: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x800B1ADC: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x800B1AE0: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x800B1AE4: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x800B1AE8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B1AEC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B1AF0: mul.s       $f18, $f10, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f26.fl);
    // 0x800B1AF4: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x800B1AF8: jal         0x80019480
    // 0x800B1AFC: nop

    func_80019480(rdram, ctx);
        goto after_3;
    // 0x800B1AFC: nop

    after_3:
    // 0x800B1B00: lh          $t4, 0x2($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X2);
    // 0x800B1B04: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x800B1B08: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x800B1B0C: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x800B1B10: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800B1B14: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B1B18: mul.s       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f26.fl);
    // 0x800B1B1C: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x800B1B20: jal         0x80019480
    // 0x800B1B24: nop

    func_80019480(rdram, ctx);
        goto after_4;
    // 0x800B1B24: nop

    after_4:
    // 0x800B1B28: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
    // 0x800B1B2C: lh          $t5, 0x0($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X0);
    // 0x800B1B30: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x800B1B34: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x800B1B38: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x800B1B3C: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800B1B40: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800B1B44: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800B1B48: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800B1B4C: mul.s       $f6, $f4, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x800B1B50: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800B1B54: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x800B1B58: jal         0x80019480
    // 0x800B1B5C: nop

    func_80019480(rdram, ctx);
        goto after_5;
    // 0x800B1B5C: nop

    after_5:
    // 0x800B1B60: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800B1B64: jal         0x800EF3DC
    // 0x800B1B68: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EF3DC(rdram, ctx);
        goto after_6;
    // 0x800B1B68: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_6:
    // 0x800B1B6C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800B1B70: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800B1B74: jal         0x800EFB24
    // 0x800B1B78: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_800EFB24(rdram, ctx);
        goto after_7;
    // 0x800B1B78: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_7:
    // 0x800B1B7C: jal         0x800EF2A0
    // 0x800B1B80: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800EF2A0(rdram, ctx);
        goto after_8;
    // 0x800B1B80: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_8:
    // 0x800B1B84: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800B1B88: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800B1B8C: jal         0x800EFB24
    // 0x800B1B90: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_800EFB24(rdram, ctx);
        goto after_9;
    // 0x800B1B90: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_9:
    // 0x800B1B94: lwc1        $f8, 0x88($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800B1B98: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800B1B9C: lwc1        $f4, 0x8C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800B1BA0: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800B1BA4: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800B1BA8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800B1BAC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800B1BB0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B1BB4: lwc1        $f6, 0x90($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800B1BB8: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800B1BBC: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800B1BC0: mul.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B1BC4: add.s       $f20, $f18, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x800B1BC8: c.lt.s      $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f24.fl < ctx->f20.fl;
    // 0x800B1BCC: nop

    // 0x800B1BD0: bc1t        L_800B1CE0
    if (c1cs) {
        // 0x800B1BD4: nop
    
            goto L_800B1CE0;
    }
    // 0x800B1BD4: nop

    // 0x800B1BD8: jal         0x800EFB24
    // 0x800B1BDC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_800EFB24(rdram, ctx);
        goto after_10;
    // 0x800B1BDC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_10:
    // 0x800B1BE0: lwc1        $f8, 0x88($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800B1BE4: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800B1BE8: lwc1        $f18, 0x8C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800B1BEC: lwc1        $f10, 0x80($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800B1BF0: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800B1BF4: nop

    // 0x800B1BF8: mul.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800B1BFC: lwc1        $f10, 0x90($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800B1C00: lwc1        $f18, 0x84($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800B1C04: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800B1C08: mul.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800B1C0C: lwc1        $f10, 0x88($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800B1C10: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800B1C14: neg.s       $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = -ctx->f8.fl;
    // 0x800B1C18: c.lt.s      $f24, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f24.fl < ctx->f18.fl;
    // 0x800B1C1C: nop

    // 0x800B1C20: bc1t        L_800B1CE0
    if (c1cs) {
        // 0x800B1C24: nop
    
            goto L_800B1CE0;
    }
    // 0x800B1C24: nop

    // 0x800B1C28: mul.s       $f6, $f10, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800B1C2C: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800B1C30: lwc1        $f18, 0x0($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800B1C34: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800B1C38: lwc1        $f6, 0x8C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800B1C3C: mul.s       $f4, $f6, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800B1C40: sub.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x800B1C44: lwc1        $f18, 0xA4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x800B1C48: swc1        $f10, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f10.u32l;
    // 0x800B1C4C: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800B1C50: add.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x800B1C54: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800B1C58: mul.s       $f18, $f4, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800B1C5C: sub.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800B1C60: lwc1        $f10, 0xA8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800B1C64: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    // 0x800B1C68: lwc1        $f6, 0x8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800B1C6C: add.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x800B1C70: lwc1        $f18, 0x7C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800B1C74: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800B1C78: mul.s       $f10, $f18, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800B1C7C: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800B1C80: swc1        $f4, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f4.u32l;
    // 0x800B1C84: mul.s       $f8, $f6, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x800B1C88: lwc1        $f18, 0x84($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800B1C8C: mul.s       $f6, $f18, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800B1C90: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800B1C94: jal         0x8002DCA0
    // 0x800B1C98: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_11;
    // 0x800B1C98: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    after_11:
    // 0x800B1C9C: lwc1        $f14, 0x70($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800B1CA0: lwc1        $f16, 0x74($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800B1CA4: lwc1        $f2, 0x78($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800B1CA8: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800B1CAC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800B1CB0: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800B1CB4: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800B1CB8: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800B1CBC: jal         0x8002DCA0
    // 0x800B1CC0: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_12;
    // 0x800B1CC0: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    after_12:
    // 0x800B1CC4: sub.s       $f4, $f20, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f20.fl - ctx->f24.fl;
    // 0x800B1CC8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800B1CCC: nop

    // 0x800B1CD0: bc1t        L_800B1CE0
    if (c1cs) {
        // 0x800B1CD4: nop
    
            goto L_800B1CE0;
    }
    // 0x800B1CD4: nop

    // 0x800B1CD8: b           L_800B1CFC
    // 0x800B1CDC: lbu         $v0, 0xD($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XD);
        goto L_800B1CFC;
    // 0x800B1CDC: lbu         $v0, 0xD($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XD);
L_800B1CE0:
    // 0x800B1CE0: jal         0x80018DAC
    // 0x800B1CE4: nop

    mlMtxPop(rdram, ctx);
        goto after_13;
    // 0x800B1CE4: nop

    after_13:
    // 0x800B1CE8: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
L_800B1CEC:
    // 0x800B1CEC: sltu        $at, $s0, $s7
    ctx->r1 = ctx->r16 < ctx->r23 ? 1 : 0;
    // 0x800B1CF0: bnel        $at, $zero, L_800B1A10
    if (ctx->r1 != 0) {
        // 0x800B1CF4: lbu         $v0, 0xD($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0XD);
            goto L_800B1A10;
    }
    goto skip_1;
    // 0x800B1CF4: lbu         $v0, 0xD($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XD);
    skip_1:
L_800B1CF8:
    // 0x800B1CF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B1CFC:
    // 0x800B1CFC: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x800B1D00: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800B1D04: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800B1D08: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x800B1D0C: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x800B1D10: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800B1D14: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x800B1D18: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x800B1D1C: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x800B1D20: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x800B1D24: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x800B1D28: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x800B1D2C: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x800B1D30: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x800B1D34: jr          $ra
    // 0x800B1D38: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x800B1D38: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void func_8010C460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010C460: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010C464: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010C468: jal         0x80103F38
    // 0x8010C46C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103F38(rdram, ctx);
        goto after_0;
    // 0x8010C46C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8010C470: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8010C474: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8010C478: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8010C47C: lwc1        $f4, 0x6524($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6524);
    // 0x8010C480: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010C484: mul.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8010C488: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x8010C48C: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x8010C490: bc1fl       L_8010C4A4
    if (!c1cs) {
        // 0x8010C494: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_8010C4A4;
    }
    goto skip_0;
    // 0x8010C494: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_0:
    // 0x8010C498: b           L_8010C4A4
    // 0x8010C49C: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
        goto L_8010C4A4;
    // 0x8010C49C: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    // 0x8010C4A0: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8010C4A4:
    // 0x8010C4A4: jr          $ra
    // 0x8010C4A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8010C4A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80800898_chnewmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800898: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8080089C: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(1584, 0X1A00) << 16);
    // 0x808008A0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1584, 0X1A0C) << 16);
    // 0x808008A4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808008A8: addiu       $v0, $v0, 0x1A0C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1584, 0X1A0C));
    // 0x808008AC: addiu       $v1, $v1, 0x1A00
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(1584, 0X1A00));
    // 0x808008B0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
L_808008B4:
    // 0x808008B4: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x808008B8: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
    // 0x808008BC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x808008C0: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x808008C4: nop

    // 0x808008C8: bc1t        L_808008E0
    if (c1cs) {
        // 0x808008CC: nop
    
            goto L_808008E0;
    }
    // 0x808008CC: nop

    // 0x808008D0: sub.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x808008D4: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x808008D8: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x808008DC: swc1        $f8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f8.u32l;
L_808008E0:
    // 0x808008E0: bne         $v1, $v0, L_808008B4
    if (ctx->r3 != ctx->r2) {
        // 0x808008E4: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_808008B4;
    }
    // 0x808008E4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x808008E8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x808008EC: lwc1        $f0, 0x48($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X48);
    // 0x808008F0: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x808008F4: nop

    // 0x808008F8: bc1tl       L_8080090C
    if (c1cs) {
        // 0x808008FC: lwc1        $f0, 0x44($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X44);
            goto L_8080090C;
    }
    goto skip_0;
    // 0x808008FC: lwc1        $f0, 0x44($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X44);
    skip_0:
    // 0x80800900: mul.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80800904: swc1        $f10, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f10.u32l;
    // 0x80800908: lwc1        $f0, 0x44($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X44);
L_8080090C:
    // 0x8080090C: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x80800910: nop

    // 0x80800914: bc1t        L_80800924
    if (c1cs) {
        // 0x80800918: nop
    
            goto L_80800924;
    }
    // 0x80800918: nop

    // 0x8080091C: mul.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80800920: swc1        $f16, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f16.u32l;
L_80800924:
    // 0x80800924: jr          $ra
    // 0x80800928: nop

    return;
    // 0x80800928: nop

;}
RECOMP_FUNC void subaddielink_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800138: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8080013C: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80800140: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x80800144: jr          $ra
    // 0x80800148: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    return;
    // 0x80800148: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8080014C: nop

;}
RECOMP_FUNC void func_800BCCF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BCCF4: jr          $ra
    // 0x800BCCF8: lbu         $v0, 0x6($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X6);
    return;
    // 0x800BCCF8: lbu         $v0, 0x6($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X6);
;}
RECOMP_FUNC void bsstand_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800CE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CEC: jal         0x80082FE0
    // 0x80800CF0: nop

    _bsdrone_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800CF0: nop

    after_0:
    // 0x80800CF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800CF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800CFC: jr          $ra
    // 0x80800D00: nop

    return;
    // 0x80800D00: nop

;}
RECOMP_FUNC void _chdiggerbossdoor_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800867E8: syscall     378
    recomp_syscall_handler(rdram, ctx, 0x800867E8);
    return;
    // 0x800867EC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800018_chloggo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080001C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800020: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800024: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800028: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080002C: jal         0x80088278
    // 0x80800030: addiu       $a0, $zero, 0x201
    ctx->r4 = ADD32(0, 0X201);
    _gccubesearch_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800030: addiu       $a0, $zero, 0x201
    ctx->r4 = ADD32(0, 0X201);
    after_0:
    // 0x80800034: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80800038: jal         0x800EE88C
    // 0x8080003C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800EE88C(rdram, ctx);
        goto after_1;
    // 0x8080003C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80800040: jal         0x80088848
    // 0x80800044: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_2;
    // 0x80800044: nop

    after_2:
    // 0x80800048: beq         $v0, $zero, L_80800064
    if (ctx->r2 == 0) {
        // 0x8080004C: addiu       $a0, $zero, 0x10
        ctx->r4 = ADD32(0, 0X10);
            goto L_80800064;
    }
    // 0x8080004C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80800050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800054: jal         0x80102424
    // 0x80800058: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x80800058: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
    // 0x8080005C: b           L_8080009C
    // 0x80800060: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080009C;
    // 0x80800060: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800064:
    // 0x80800064: jal         0x800D0A9C
    // 0x80800068: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800D0A9C(rdram, ctx);
        goto after_4;
    // 0x80800068: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_4:
    // 0x8080006C: beq         $v0, $zero, L_80800084
    if (ctx->r2 == 0) {
        // 0x80800070: nop
    
            goto L_80800084;
    }
    // 0x80800070: nop

    // 0x80800074: jal         0x8010A570
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_5;
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080007C: b           L_8080009C
    // 0x80800080: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080009C;
    // 0x80800080: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800084:
    // 0x80800084: jal         0x800DA298
    // 0x80800088: addiu       $a0, $zero, 0x169
    ctx->r4 = ADD32(0, 0X169);
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x80800088: addiu       $a0, $zero, 0x169
    ctx->r4 = ADD32(0, 0X169);
    after_6:
    // 0x8080008C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800090: jal         0x8010A5B0
    // 0x80800094: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8010A5B0(rdram, ctx);
        goto after_7;
    // 0x80800094: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x80800098: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080009C:
    // 0x8080009C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000A4: jr          $ra
    // 0x808000A8: nop

    return;
    // 0x808000A8: nop

;}
RECOMP_FUNC void func_80800C28_chstonedartgunhead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C28: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800C2C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800C30: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800C34: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800C38: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800C3C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800C40: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800C44: beq         $t6, $at, L_80800C68
    if (ctx->r14 == ctx->r1) {
        // 0x80800C48: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_80800C68;
    }
    // 0x80800C48: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80800C4C: beq         $t6, $at, L_80800D00
    if (ctx->r14 == ctx->r1) {
        // 0x80800C50: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80800D00;
    }
    // 0x80800C50: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800C54: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80800C58: beq         $t6, $at, L_80800CCC
    if (ctx->r14 == ctx->r1) {
        // 0x80800C5C: nop
    
            goto L_80800CCC;
    }
    // 0x80800C5C: nop

    // 0x80800C60: b           L_80800D40
    // 0x80800C64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800D40;
    // 0x80800C64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800C68:
    // 0x80800C68: jal         0x800D8FF8
    // 0x80800C6C: nop

    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800C6C: nop

    after_0:
    // 0x80800C70: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800C74: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800C78: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    // 0x80800C7C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800C80: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x80800C84: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80800C88: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80800C8C: jal         0x800EF214
    // 0x80800C90: nop

    func_800EF214(rdram, ctx);
        goto after_1;
    // 0x80800C90: nop

    after_1:
    // 0x80800C94: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80800C98: jal         0x800EEB40
    // 0x80800C9C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800EEB40(rdram, ctx);
        goto after_2;
    // 0x80800C9C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x80800CA0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1872, 0XE10) << 16);
    // 0x80800CA4: lwc1        $f8, 0xE10($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1872, 0XE10));
    // 0x80800CA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CAC: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80800CB0: nop

    // 0x80800CB4: bc1fl       L_80800D40
    if (!c1cs) {
        // 0x80800CB8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800D40;
    }
    goto skip_0;
    // 0x80800CB8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800CBC: jal         0x80101FDC
    // 0x80800CC0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x80800CC0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_3:
    // 0x80800CC4: b           L_80800D40
    // 0x80800CC8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800D40;
    // 0x80800CC8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800CCC:
    // 0x80800CCC: jal         0x800D9078
    // 0x80800CD0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_4;
    // 0x80800CD0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_4:
    // 0x80800CD4: bne         $v0, $zero, L_80800CEC
    if (ctx->r2 != 0) {
        // 0x80800CD8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800CEC;
    }
    // 0x80800CD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CDC: lui         $a1, 0x10
    ctx->r5 = S32(0X10 << 16);
    // 0x80800CE0: jal         0x8010B990
    // 0x80800CE4: ori         $a1, $a1, 0x6
    ctx->r5 = ctx->r5 | 0X6;
    func_8010B990(rdram, ctx);
        goto after_5;
    // 0x80800CE4: ori         $a1, $a1, 0x6
    ctx->r5 = ctx->r5 | 0X6;
    after_5:
    // 0x80800CE8: beq         $v0, $zero, L_80800D3C
    if (ctx->r2 == 0) {
        // 0x80800CEC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D3C;
    }
L_80800CEC:
    // 0x80800CEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CF0: jal         0x80102424
    // 0x80800CF4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x80800CF4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_6:
    // 0x80800CF8: b           L_80800D40
    // 0x80800CFC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800D40;
    // 0x80800CFC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800D00:
    // 0x80800D00: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1872, 0XF58) << 16);
    // 0x80800D04: addiu       $t7, $t7, 0xF58
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1872, 0XF58));
    // 0x80800D08: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x80800D0C: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80800D10: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800D14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800D18: jal         0x800BBCB8
    // 0x80800D1C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_800BBCB8(rdram, ctx);
        goto after_7;
    // 0x80800D1C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_7:
    // 0x80800D20: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1872, 0XFA0) << 16);
    // 0x80800D24: addiu       $a2, $a2, 0xFA0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1872, 0XFA0));
    // 0x80800D28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D2C: jal         0x80089D18
    // 0x80800D30: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x80800D30: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_8:
    // 0x80800D34: jal         0x800FFAB0
    // 0x80800D38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_9;
    // 0x80800D38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
L_80800D3C:
    // 0x80800D3C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800D40:
    // 0x80800D40: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800D44: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800D48: jr          $ra
    // 0x80800D4C: nop

    return;
    // 0x80800D4C: nop

;}
RECOMP_FUNC void _gldialog_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088738: syscall     702
    recomp_syscall_handler(rdram, ctx, 0x80088738);
    return;
    // 0x8008873C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void ncfixposrot_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800150: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800154: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800158: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080015C: jal         0x800A5800
    // 0x80800160: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800A5800(rdram, ctx);
        goto after_0;
    // 0x80800160: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800164: jal         0x80085580
    // 0x80800168: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _cadbfunc_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800168: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080016C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800170: jal         0x80085590
    // 0x80800174: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    _cadbfunc_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800174: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_2:
    // 0x80800178: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080017C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800180: jr          $ra
    // 0x80800184: nop

    return;
    // 0x80800184: nop

;}
RECOMP_FUNC void bsjump_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080002C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800030: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800034: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800038: jal         0x8008CABC
    // 0x8080003C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x8080003C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800040: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800048: jal         0x80095738
    // 0x8080004C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    baflag_isTrue(rdram, ctx);
        goto after_1;
    // 0x8080004C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80800050: sltu        $a1, $zero, $v0
    ctx->r5 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800054: beql        $a1, $zero, L_8080006C
    if (ctx->r5 == 0) {
        // 0x80800058: sw          $a1, 0x164($s0)
        MEM_W(0X164, ctx->r16) = ctx->r5;
            goto L_8080006C;
    }
    goto skip_0;
    // 0x80800058: sw          $a1, 0x164($s0)
    MEM_W(0X164, ctx->r16) = ctx->r5;
    skip_0:
    // 0x8080005C: jal         0x8008E23C
    // 0x80800060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E23C(rdram, ctx);
        goto after_2;
    // 0x80800060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800064: sltiu       $a1, $v0, 0x1
    ctx->r5 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80800068: sw          $a1, 0x164($s0)
    MEM_W(0X164, ctx->r16) = ctx->r5;
L_8080006C:
    // 0x8080006C: jal         0x8009E710
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getPreviousState(rdram, ctx);
        goto after_3;
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800074: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080007C: jal         0x8009CBDC
    // 0x80800080: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8009CBDC(rdram, ctx);
        goto after_4;
    // 0x80800080: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80800084: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80800088: bnel        $v0, $at, L_8080009C
    if (ctx->r2 != ctx->r1) {
        // 0x8080008C: lw          $a1, 0x38($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X38);
            goto L_8080009C;
    }
    goto skip_1;
    // 0x8080008C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    skip_1:
    // 0x80800090: jal         0x80098840
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80098840(rdram, ctx);
        goto after_5;
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800098: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
L_8080009C:
    // 0x8080009C: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A4: bne         $a1, $at, L_808000F0
    if (ctx->r5 != ctx->r1) {
        // 0x808000A8: lui         $a2, 0x3F2A
        ctx->r6 = S32(0X3F2A << 16);
            goto L_808000F0;
    }
    // 0x808000A8: lui         $a2, 0x3F2A
    ctx->r6 = S32(0X3F2A << 16);
    // 0x808000AC: ori         $a2, $a2, 0xACDA
    ctx->r6 = ctx->r6 | 0XACDA;
    // 0x808000B0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808000B4: jal         0x8008B1D4
    // 0x808000B8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_6;
    // 0x808000B8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
    // 0x808000BC: lui         $a1, 0x3F01
    ctx->r5 = S32(0X3F01 << 16);
    // 0x808000C0: ori         $a1, $a1, 0x1340
    ctx->r5 = ctx->r5 | 0X1340;
    // 0x808000C4: jal         0x8008B24C
    // 0x808000C8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    anctrl_setStart(rdram, ctx);
        goto after_7;
    // 0x808000C8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_7:
    // 0x808000CC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808000D0: jal         0x8008B1BC
    // 0x808000D4: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_8;
    // 0x808000D4: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    after_8:
    // 0x808000D8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808000DC: jal         0x8008B134
    // 0x808000E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_9;
    // 0x808000E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x808000E4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808000E8: b           L_80800268
    // 0x808000EC: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
        goto L_80800268;
    // 0x808000EC: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
L_808000F0:
    // 0x808000F0: jal         0x8009CA70
    // 0x808000F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8009CA70(rdram, ctx);
        goto after_10;
    // 0x808000F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_10:
    // 0x808000F8: sw          $v0, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r2;
    // 0x808000FC: jal         0x8008AF24
    // 0x80800100: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    anctrl_reset(rdram, ctx);
        goto after_11;
    // 0x80800100: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_11:
    // 0x80800104: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800108: jal         0x8008AED4
    // 0x8080010C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    anctrl_setIndex(rdram, ctx);
        goto after_12;
    // 0x8080010C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_12:
    // 0x80800110: lui         $a1, 0x3FF3
    ctx->r5 = S32(0X3FF3 << 16);
    // 0x80800114: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80800118: jal         0x8008B1BC
    // 0x8080011C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    anctrl_setDuration(rdram, ctx);
        goto after_13;
    // 0x8080011C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_13:
    // 0x80800120: lui         $a1, 0x3E09
    ctx->r5 = S32(0X3E09 << 16);
    // 0x80800124: ori         $a1, $a1, 0x374C
    ctx->r5 = ctx->r5 | 0X374C;
    // 0x80800128: jal         0x8008B1C8
    // 0x8080012C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    func_8008B1C8(rdram, ctx);
        goto after_14;
    // 0x8080012C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_14:
    // 0x80800130: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800134: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800138: jal         0x8008B24C
    // 0x8080013C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    anctrl_setStart(rdram, ctx);
        goto after_15;
    // 0x8080013C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_15:
    // 0x80800140: lui         $a2, 0x3F01
    ctx->r6 = S32(0X3F01 << 16);
    // 0x80800144: ori         $a2, $a2, 0x1340
    ctx->r6 = ctx->r6 | 0X1340;
    // 0x80800148: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8080014C: jal         0x8008B1D4
    // 0x80800150: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_16;
    // 0x80800150: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_16:
    // 0x80800154: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800158: jal         0x8008B134
    // 0x8080015C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_17;
    // 0x8080015C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x80800160: jal         0x8008B064
    // 0x80800164: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    anctrl_start(rdram, ctx);
        goto after_18;
    // 0x80800164: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_18:
    // 0x80800168: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x8080016C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800174: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800178: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080017C: jal         0x8009FFD8
    // 0x80800180: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_19;
    // 0x80800180: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_19:
    // 0x80800184: jal         0x8009EF04
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_distance(rdram, ctx);
        goto after_20;
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x8080018C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800190: nop

    // 0x80800194: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80800198: nop

    // 0x8080019C: bc1t        L_808001B8
    if (c1cs) {
        // 0x808001A0: nop
    
            goto L_808001B8;
    }
    // 0x808001A0: nop

    // 0x808001A4: jal         0x8009EEB8
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_21;
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x808001AC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808001B0: jal         0x8009C914
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_22;
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
L_808001B8:
    // 0x808001B8: jal         0x8009C990
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_23;
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x808001C0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808001C4: jal         0x8009B9C0
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_24;
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x808001CC: jal         0x800841D8
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bswalk_entrypoint_1(rdram, ctx);
        goto after_25;
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x808001D4: jal         0x8009C990
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_26;
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x808001DC: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x808001E0: jal         0x8009BB00
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_27;
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x808001E8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F0: jal         0x8009BA68
    // 0x808001F4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_28;
    // 0x808001F4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_28:
    // 0x808001F8: lw          $t8, 0x160($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X160);
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800200: lui         $a1, 0x4431
    ctx->r5 = S32(0X4431 << 16);
    // 0x80800204: beq         $t8, $zero, L_80800224
    if (ctx->r24 == 0) {
        // 0x80800208: nop
    
            goto L_80800224;
    }
    // 0x80800208: nop

    // 0x8080020C: lui         $a1, 0x4418
    ctx->r5 = S32(0X4418 << 16);
    // 0x80800210: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x80800214: jal         0x8009BA58
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_29;
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x8080021C: b           L_80800230
    // 0x80800220: lui         $a1, 0xC4A8
    ctx->r5 = S32(0XC4A8 << 16);
        goto L_80800230;
    // 0x80800220: lui         $a1, 0xC4A8
    ctx->r5 = S32(0XC4A8 << 16);
L_80800224:
    // 0x80800224: jal         0x8009BA58
    // 0x80800228: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_30;
    // 0x80800228: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    after_30:
    // 0x8080022C: lui         $a1, 0xC4A8
    ctx->r5 = S32(0XC4A8 << 16);
L_80800230:
    // 0x80800230: ori         $a1, $a1, 0xC000
    ctx->r5 = ctx->r5 | 0XC000;
    // 0x80800234: jal         0x8009BCB4
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_gravity(rdram, ctx);
        goto after_31;
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x8080023C: lw          $t9, 0x164($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X164);
    // 0x80800240: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800248: beq         $t9, $zero, L_80800260
    if (ctx->r25 == 0) {
        // 0x8080024C: addiu       $a1, $zero, 0x422
        ctx->r5 = ADD32(0, 0X422);
            goto L_80800260;
    }
    // 0x8080024C: addiu       $a1, $zero, 0x422
    ctx->r5 = ADD32(0, 0X422);
    // 0x80800250: jal         0x8009DE38
    // 0x80800254: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8009DE38(rdram, ctx);
        goto after_32;
    // 0x80800254: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_32:
    // 0x80800258: b           L_8080026C
    // 0x8080025C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080026C;
    // 0x8080025C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800260:
    // 0x80800260: jal         0x80800000
    // 0x80800264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsjump(rdram, ctx);
        goto after_33;
    // 0x80800264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
L_80800268:
    // 0x80800268: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080026C:
    // 0x8080026C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800270: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800274: jr          $ra
    // 0x80800278: nop

    return;
    // 0x80800278: nop

;}
RECOMP_FUNC void func_800D0C78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0C78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D0C7C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D0C80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D0C84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D0C88: bne         $a1, $at, L_800D0CB8
    if (ctx->r5 != ctx->r1) {
        // 0x800D0C8C: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_800D0CB8;
    }
    // 0x800D0C8C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800D0C90: jal         0x800D0B08
    // 0x800D0C94: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800D0B08(rdram, ctx);
        goto after_0;
    // 0x800D0C94: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800D0C98: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800D0C9C: jal         0x800D0BD4
    // 0x800D0CA0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800D0BD4(rdram, ctx);
        goto after_1;
    // 0x800D0CA0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800D0CA4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800D0CA8: bnel        $t6, $zero, L_800D0CBC
    if (ctx->r14 != 0) {
        // 0x800D0CAC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D0CBC;
    }
    goto skip_0;
    // 0x800D0CAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D0CB0: jal         0x800FC660
    // 0x800D0CB4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800FC660(rdram, ctx);
        goto after_2;
    // 0x800D0CB4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_2:
L_800D0CB8:
    // 0x800D0CB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D0CBC:
    // 0x800D0CBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D0CC0: jr          $ra
    // 0x800D0CC4: nop

    return;
    // 0x800D0CC4: nop

;}
RECOMP_FUNC void func_808001D8_chfactoryprop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808001E4: jal         0x80089D48
    // 0x808001E8: lbu         $a0, 0x18($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X18);
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808001E8: lbu         $a0, 0x18($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X18);
    after_0:
    // 0x808001EC: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x808001F0: sb          $v0, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r2;
    // 0x808001F4: jal         0x80089D48
    // 0x808001F8: lbu         $a0, 0x1C($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X1C);
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808001F8: lbu         $a0, 0x1C($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X1C);
    after_1:
    // 0x808001FC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800200: sb          $v0, 0x1C($t7)
    MEM_B(0X1C, ctx->r15) = ctx->r2;
    // 0x80800204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800208: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080020C: jr          $ra
    // 0x80800210: nop

    return;
    // 0x80800210: nop

;}
RECOMP_FUNC void func_80101238(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101238: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8010123C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80101240: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80101244: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80101248: addiu       $s3, $sp, 0x30
    ctx->r19 = ADD32(ctx->r29, 0X30);
    // 0x8010124C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80101250: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80101254: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80101258: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8010125C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80101260: jal         0x801067C4
    // 0x80101264: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_801067C4(rdram, ctx);
        goto after_0;
    // 0x80101264: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
    // 0x80101268: beq         $v0, $zero, L_801012B0
    if (ctx->r2 == 0) {
        // 0x8010126C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_801012B0;
    }
    // 0x8010126C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80101270:
    // 0x80101270: lw          $t6, 0x64($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X64);
    // 0x80101274: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80101278: sll         $t8, $t6, 14
    ctx->r24 = S32(ctx->r14 << 14);
    // 0x8010127C: bltz        $t8, L_801012A0
    if (SIGNED(ctx->r24) < 0) {
        // 0x80101280: nop
    
            goto L_801012A0;
    }
    // 0x80101280: nop

    // 0x80101284: jal         0x8010108C
    // 0x80101288: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_8010108C(rdram, ctx);
        goto after_1;
    // 0x80101288: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_1:
    // 0x8010128C: blez        $v0, L_801012A0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80101290: nop
    
            goto L_801012A0;
    }
    // 0x80101290: nop

    // 0x80101294: bne         $s0, $zero, L_801012A0
    if (ctx->r16 != 0) {
        // 0x80101298: nop
    
            goto L_801012A0;
    }
    // 0x80101298: nop

    // 0x8010129C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_801012A0:
    // 0x801012A0: jal         0x8010682C
    // 0x801012A4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_8010682C(rdram, ctx);
        goto after_2;
    // 0x801012A4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_2:
    // 0x801012A8: bne         $v0, $zero, L_80101270
    if (ctx->r2 != 0) {
        // 0x801012AC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80101270;
    }
    // 0x801012AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_801012B0:
    // 0x801012B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801012B4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x801012B8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801012BC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801012C0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x801012C4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x801012C8: jr          $ra
    // 0x801012CC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801012CC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8009BF04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BF04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009BF08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009BF0C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8009BF10: lw          $t6, 0xDC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XDC);
    // 0x8009BF14: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    // 0x8009BF18: lw          $t7, 0xDC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XDC);
    // 0x8009BF1C: jal         0x8009C000
    // 0x8009BF20: swc1        $f0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f0.u32l;
    func_8009C000(rdram, ctx);
        goto after_0;
    // 0x8009BF20: swc1        $f0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f0.u32l;
    after_0:
    // 0x8009BF24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009BF28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009BF2C: jr          $ra
    // 0x8009BF30: nop

    return;
    // 0x8009BF30: nop

;}
RECOMP_FUNC void func_80095A40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095A40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80095A44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80095A48: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    // 0x80095A4C: jal         0x800959C8
    // 0x80095A50: lui         $a2, 0x420C
    ctx->r6 = S32(0X420C << 16);
    func_800959C8(rdram, ctx);
        goto after_0;
    // 0x80095A50: lui         $a2, 0x420C
    ctx->r6 = S32(0X420C << 16);
    after_0:
    // 0x80095A54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80095A58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80095A5C: jr          $ra
    // 0x80095A60: nop

    return;
    // 0x80095A60: nop

;}
RECOMP_FUNC void _chgobiwitchy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085C80: syscall     216
    recomp_syscall_handler(rdram, ctx, 0x80085C80);
    return;
    // 0x80085C84: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8080549C_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080549C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x808054A0: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA474) << 16);
    // 0x808054A4: lwc1        $f6, -0x5B8C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA474));
    // 0x808054A8: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x808054AC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x808054B0: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x808054B4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808054B8: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x808054BC: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x808054C0: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x808054C4: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x808054C8: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x808054CC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x808054D0: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x808054D4: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x808054D8: lwc1        $f10, 0x0($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X0);
    // 0x808054DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808054E0: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x808054E4: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x808054E8: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x808054EC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808054F0: bc1f        L_80805500
    if (!c1cs) {
        // 0x808054F4: div.s       $f22, $f10, $f8
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
            goto L_80805500;
    }
    // 0x808054F4: div.s       $f22, $f10, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x808054F8: b           L_80805504
    // 0x808054FC: mov.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
        goto L_80805504;
    // 0x808054FC: mov.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
L_80805500:
    // 0x80805500: neg.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f24.fl = -ctx->f12.fl;
L_80805504:
    // 0x80805504: div.s       $f26, $f20, $f24
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f26.fl = DIV_S(ctx->f20.fl, ctx->f24.fl);
    // 0x80805508: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8080550C: div.s       $f14, $f2, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f14.fl = DIV_S(ctx->f2.fl, ctx->f24.fl);
    // 0x80805510: c.lt.s      $f26, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f26.fl < ctx->f12.fl;
    // 0x80805514: nop

    // 0x80805518: bc1f        L_80805524
    if (!c1cs) {
        // 0x8080551C: nop
    
            goto L_80805524;
    }
    // 0x8080551C: nop

    // 0x80805520: mov.s       $f26, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    ctx->f26.fl = ctx->f12.fl;
L_80805524:
    // 0x80805524: jal         0x80013AA0
    // 0x80805528: sub.s       $f12, $f18, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f14.fl;
    func_80013AA0(rdram, ctx);
        goto after_0;
    // 0x80805528: sub.s       $f12, $f18, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f14.fl;
    after_0:
    // 0x8080552C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80805530: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80805534: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80805538: jal         0x80013AA0
    // 0x8080553C: sub.s       $f12, $f4, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f26.fl;
    func_80013AA0(rdram, ctx);
        goto after_1;
    // 0x8080553C: sub.s       $f12, $f4, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f26.fl;
    after_1:
    // 0x80805540: sub.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x80805544: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x80805548: c.lt.s      $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f22.fl < ctx->f6.fl;
    // 0x8080554C: nop

    // 0x80805550: bc1fl       L_80805560
    if (!c1cs) {
        // 0x80805554: sub.s       $f10, $f14, $f20
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f20.fl;
            goto L_80805560;
    }
    goto skip_0;
    // 0x80805554: sub.s       $f10, $f14, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f20.fl;
    skip_0:
    // 0x80805558: add.s       $f14, $f20, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = ctx->f20.fl + ctx->f22.fl;
    // 0x8080555C: sub.s       $f10, $f14, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f20.fl;
L_80805560:
    // 0x80805560: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA478) << 16);
    // 0x80805564: lwc1        $f8, -0x5B88($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA478));
    // 0x80805568: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x8080556C: sub.s       $f22, $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f22.fl - ctx->f10.fl;
    // 0x80805570: c.lt.s      $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f22.fl < ctx->f8.fl;
    // 0x80805574: nop

    // 0x80805578: bc1f        L_80805588
    if (!c1cs) {
        // 0x8080557C: nop
    
            goto L_80805588;
    }
    // 0x8080557C: nop

    // 0x80805580: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80805584: nop

L_80805588:
    // 0x80805588: jal         0x80013798
    // 0x8080558C: swc1        $f14, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f14.u32l;
    func_80013798(rdram, ctx);
        goto after_2;
    // 0x8080558C: swc1        $f14, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f14.u32l;
    after_2:
    // 0x80805590: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x80805594: jal         0x800138BC
    // 0x80805598: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_800138BC(rdram, ctx);
        goto after_3;
    // 0x80805598: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_3:
    // 0x8080559C: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x808055A0: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x808055A4: add.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x808055A8: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA47C) << 16);
    // 0x808055AC: lwc1        $f6, -0x5B84($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA47C));
    // 0x808055B0: add.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x808055B4: sub.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x808055B8: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x808055BC: nop

    // 0x808055C0: bc1f        L_808055D0
    if (!c1cs) {
        // 0x808055C4: nop
    
            goto L_808055D0;
    }
    // 0x808055C4: nop

    // 0x808055C8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x808055CC: nop

L_808055D0:
    // 0x808055D0: jal         0x800137C4
    // 0x808055D4: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    func_800137C4(rdram, ctx);
        goto after_4;
    // 0x808055D4: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    after_4:
    // 0x808055D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808055DC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808055E0: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA480) << 16);
    // 0x808055E4: lwc1        $f8, -0x5B80($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA480));
    // 0x808055E8: sub.s       $f14, $f10, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x808055EC: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808055F0: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x808055F4: add.s       $f16, $f26, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f26.fl + ctx->f8.fl;
    // 0x808055F8: mul.s       $f18, $f2, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x808055FC: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x80805600: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
    // 0x80805604: mul.s       $f6, $f2, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f24.fl);
    // 0x80805608: bc1f        L_80805614
    if (!c1cs) {
        // 0x8080560C: nop
    
            goto L_80805614;
    }
    // 0x8080560C: nop

    // 0x80805610: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
L_80805614:
    // 0x80805614: mul.s       $f4, $f24, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f14.fl);
    // 0x80805618: swc1        $f18, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f18.u32l;
    // 0x8080561C: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x80805620: mul.s       $f0, $f6, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80805624: swc1        $f4, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f4.u32l;
    // 0x80805628: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8080562C: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x80805630: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80805634: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80805638: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8080563C: jr          $ra
    // 0x80805640: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80805640: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void ncbatarget_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _idflash_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088D48: syscall     737
    recomp_syscall_handler(rdram, ctx, 0x80088D48);
    return;
    // 0x80088D4C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800970_chballoonburst(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800970: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800974: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800978: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080097C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800980: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800984: jal         0x8008A098
    // 0x80800988: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    _subaddiemulti_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800988: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080098C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800990: jal         0x80101FDC
    // 0x80800994: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x80800994: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x80800998: addiu       $a0, $zero, 0xC1
    ctx->r4 = ADD32(0, 0XC1);
    // 0x8080099C: jal         0x800D2770
    // 0x808009A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800D2770(rdram, ctx);
        goto after_2;
    // 0x808009A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808009A4: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
    // 0x808009A8: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x808009AC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808009B0: srl         $t7, $v0, 7
    ctx->r15 = S32(U32(ctx->r2) >> 7);
    // 0x808009B4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x808009B8: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x808009BC: andi        $t6, $a0, 0x1FF
    ctx->r14 = ctx->r4 & 0X1FF;
    // 0x808009C0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x808009C4: bgez        $t7, L_808009D8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x808009C8: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_808009D8;
    }
    // 0x808009C8: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808009CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808009D0: nop

    // 0x808009D4: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_808009D8:
    // 0x808009D8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x808009DC: jal         0x800CE8D8
    // 0x808009E0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800CE8D8(rdram, ctx);
        goto after_3;
    // 0x808009E0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_3:
    // 0x808009E4: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x808009E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808009EC: andi        $t8, $a0, 0x1FF
    ctx->r24 = ctx->r4 & 0X1FF;
    // 0x808009F0: jal         0x800CE88C
    // 0x808009F4: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_800CE88C(rdram, ctx);
        goto after_4;
    // 0x808009F4: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_4:
    // 0x808009F8: jal         0x800DA524
    // 0x808009FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA524(rdram, ctx);
        goto after_5;
    // 0x808009FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x80800A00: jal         0x800DA524
    // 0x80800A04: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800DA524(rdram, ctx);
        goto after_6;
    // 0x80800A04: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_6:
    // 0x80800A08: jal         0x800DA524
    // 0x80800A0C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800DA524(rdram, ctx);
        goto after_7;
    // 0x80800A0C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_7:
    // 0x80800A10: jal         0x800DA524
    // 0x80800A14: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DA524(rdram, ctx);
        goto after_8;
    // 0x80800A14: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
    // 0x80800A18: jal         0x800FDC28
    // 0x80800A1C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_800FDC28(rdram, ctx);
        goto after_9;
    // 0x80800A1C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_9:
    // 0x80800A20: jal         0x80088368
    // 0x80800A24: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_10;
    // 0x80800A24: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_10:
    // 0x80800A28: blez        $v0, L_80800A68
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800A2C: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_80800A68;
    }
    // 0x80800A2C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80800A30: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800A34: nop

    // 0x80800A38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800A3C:
    // 0x80800A3C: jal         0x800F7B9C
    // 0x80800A40: addiu       $a1, $zero, 0x69
    ctx->r5 = ADD32(0, 0X69);
    func_800F7B9C(rdram, ctx);
        goto after_11;
    // 0x80800A40: addiu       $a1, $zero, 0x69
    ctx->r5 = ADD32(0, 0X69);
    after_11:
    // 0x80800A44: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80800A48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A4C: jal         0x800F7C0C
    // 0x80800A50: addiu       $a1, $zero, 0x5F
    ctx->r5 = ADD32(0, 0X5F);
    func_800F7C0C(rdram, ctx);
        goto after_12;
    // 0x80800A50: addiu       $a1, $zero, 0x5F
    ctx->r5 = ADD32(0, 0X5F);
    after_12:
    // 0x80800A54: jal         0x80088368
    // 0x80800A58: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_13;
    // 0x80800A58: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_13:
    // 0x80800A5C: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800A60: bnel        $at, $zero, L_80800A3C
    if (ctx->r1 != 0) {
        // 0x80800A64: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A3C;
    }
    goto skip_0;
    // 0x80800A64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
L_80800A68:
    // 0x80800A68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800A6C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800A70: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800A74: jr          $ra
    // 0x80800A78: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800A78: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8008BC6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008BC6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008BC70: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x8008BC74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008BC78: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8008BC7C: jal         0x8008B90C
    // 0x8008BC80: lh          $a0, 0xA($t7)
    ctx->r4 = MEM_H(ctx->r15, 0XA);
    func_8008B90C(rdram, ctx);
        goto after_0;
    // 0x8008BC80: lh          $a0, 0xA($t7)
    ctx->r4 = MEM_H(ctx->r15, 0XA);
    after_0:
    // 0x8008BC84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008BC88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008BC8C: jr          $ra
    // 0x8008BC90: nop

    return;
    // 0x8008BC90: nop

;}
RECOMP_FUNC void bsvan_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001B8: jal         0x8009E77C
    // 0x808001BC: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_8009E77C(rdram, ctx);
        goto after_0;
    // 0x808001BC: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_0:
    // 0x808001C0: bne         $v0, $zero, L_808002C4
    if (ctx->r2 != 0) {
        // 0x808001C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002C4;
    }
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C8: jal         0x80085160
    // 0x808001CC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    _bastatemem_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808001CC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_1:
    // 0x808001D0: jal         0x80085380
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bavan_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808001D8: lw          $t6, 0x188($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X188);
    // 0x808001DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808001E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808001E4: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808001F0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808001F4: jal         0x80085338
    // 0x808001F8: swc1        $f4, 0x174($s0)
    MEM_W(0X174, ctx->r16) = ctx->f4.u32l;
    _batimer_set(rdram, ctx);
        goto after_3;
    // 0x808001F8: swc1        $f4, 0x174($s0)
    MEM_W(0X174, ctx->r16) = ctx->f4.u32l;
    after_3:
    // 0x808001FC: lui         $a1, 0x4013
    ctx->r5 = S32(0X4013 << 16);
    // 0x80800200: ori         $a1, $a1, 0x3300
    ctx->r5 = ctx->r5 | 0X3300;
    // 0x80800204: jal         0x80092864
    // 0x80800208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80092864(rdram, ctx);
        goto after_4;
    // 0x80800208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800210: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x80800214: jal         0x8009BFE4
    // 0x80800218: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    func_8009BFE4(rdram, ctx);
        goto after_5;
    // 0x80800218: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_5:
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800220: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x80800224: jal         0x8009C554
    // 0x80800228: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    baroll_setAngularVelocity(rdram, ctx);
        goto after_6;
    // 0x80800228: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_6:
    // 0x8080022C: jal         0x8009EFA8
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_pushZone(rdram, ctx);
        goto after_7;
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800234: lui         $a2, 0x3DF5
    ctx->r6 = S32(0X3DF5 << 16);
    // 0x80800238: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800240: jal         0x8009F1C8
    // 0x80800244: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bastick_setZoneMax(rdram, ctx);
        goto after_8;
    // 0x80800244: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080024C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800250: jal         0x8009F1C8
    // 0x80800254: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    bastick_setZoneMax(rdram, ctx);
        goto after_9;
    // 0x80800254: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_9:
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080025C: lui         $a1, 0x42DC
    ctx->r5 = S32(0X42DC << 16);
    // 0x80800260: jal         0x800959C8
    // 0x80800264: lui         $a2, 0x4282
    ctx->r6 = S32(0X4282 << 16);
    func_800959C8(rdram, ctx);
        goto after_10;
    // 0x80800264: lui         $a2, 0x4282
    ctx->r6 = S32(0X4282 << 16);
    after_10:
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080026C: jal         0x8009590C
    // 0x80800270: lui         $a1, 0x42DC
    ctx->r5 = S32(0X42DC << 16);
    func_8009590C(rdram, ctx);
        goto after_11;
    // 0x80800270: lui         $a1, 0x42DC
    ctx->r5 = S32(0X42DC << 16);
    after_11:
    // 0x80800274: jal         0x8009E4AC
    // 0x80800278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E4AC(rdram, ctx);
        goto after_12;
    // 0x80800278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800280: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800284: jal         0x8009E55C
    // 0x80800288: lui         $a2, 0x428C
    ctx->r6 = S32(0X428C << 16);
    func_8009E55C(rdram, ctx);
        goto after_13;
    // 0x80800288: lui         $a2, 0x428C
    ctx->r6 = S32(0X428C << 16);
    after_13:
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800290: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800294: jal         0x8009E55C
    // 0x80800298: lui         $a2, 0x429C
    ctx->r6 = S32(0X429C << 16);
    func_8009E55C(rdram, ctx);
        goto after_14;
    // 0x80800298: lui         $a2, 0x429C
    ctx->r6 = S32(0X429C << 16);
    after_14:
    // 0x8080029C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A0: jal         0x80095760
    // 0x808002A4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    baflag_set(rdram, ctx);
        goto after_15;
    // 0x808002A4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_15:
    // 0x808002A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002AC: jal         0x80095760
    // 0x808002B0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    baflag_set(rdram, ctx);
        goto after_16;
    // 0x808002B0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_16:
    // 0x808002B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808002BC: jal         0x800947EC
    // 0x808002C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800947EC(rdram, ctx);
        goto after_17;
    // 0x808002C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_17:
L_808002C4:
    // 0x808002C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002D0: jr          $ra
    // 0x808002D4: nop

    return;
    // 0x808002D4: nop

;}
RECOMP_FUNC void func_808000FC_chlensflare(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000FC: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x80800100: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x80800104: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x80800108: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8080010C: sw          $a0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r4;
    // 0x80800110: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x80800114: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80800118: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x8080011C: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80800120: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80800124: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800128: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8080012C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800130: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800134: jal         0x800BFFB4
    // 0x80800138: addiu       $a2, $sp, 0xC4
    ctx->r6 = ADD32(ctx->r29, 0XC4);
    func_800BFFB4(rdram, ctx);
        goto after_0;
    // 0x80800138: addiu       $a2, $sp, 0xC4
    ctx->r6 = ADD32(ctx->r29, 0XC4);
    after_0:
    // 0x8080013C: beq         $v0, $zero, L_80800608
    if (ctx->r2 == 0) {
        // 0x80800140: lw          $t6, 0xD0($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XD0);
            goto L_80800608;
    }
    // 0x80800140: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
    // 0x80800144: lbu         $a0, 0x50($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X50);
    // 0x80800148: jal         0x800E8830
    // 0x8080014C: addiu       $a1, $sp, 0xC4
    ctx->r5 = ADD32(ctx->r29, 0XC4);
    func_800E8830(rdram, ctx);
        goto after_1;
    // 0x8080014C: addiu       $a1, $sp, 0xC4
    ctx->r5 = ADD32(ctx->r29, 0XC4);
    after_1:
    // 0x80800150: lw          $t7, 0xD0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD0);
    // 0x80800154: addiu       $a1, $sp, 0xA4
    ctx->r5 = ADD32(ctx->r29, 0XA4);
    // 0x80800158: jal         0x800E88AC
    // 0x8080015C: lbu         $a0, 0x50($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X50);
    func_800E88AC(rdram, ctx);
        goto after_2;
    // 0x8080015C: lbu         $a0, 0x50($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X50);
    after_2:
    // 0x80800160: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800164: beq         $v0, $at, L_80800184
    if (ctx->r2 == ctx->r1) {
        // 0x80800168: lwc1        $f4, 0xA4($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0XA4);
            goto L_80800184;
    }
    // 0x80800168: lwc1        $f4, 0xA4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x8080016C: lw          $v0, 0xD0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD0);
    // 0x80800170: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2296, 0X6A0) << 16);
    // 0x80800174: lw          $t8, 0x64($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X64);
    // 0x80800178: sll         $t0, $t8, 11
    ctx->r8 = S32(ctx->r24 << 11);
    // 0x8080017C: bgez        $t0, L_80800280
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80800180: nop
    
            goto L_80800280;
    }
    // 0x80800180: nop

L_80800184:
    // 0x80800184: lui         $at, 0x4318
    ctx->r1 = S32(0X4318 << 16);
    // 0x80800188: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080018C: jal         0x800F2100
    // 0x80800190: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    mlAbsF(rdram, ctx);
        goto after_3;
    // 0x80800190: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_3:
    // 0x80800194: lui         $at, 0x4318
    ctx->r1 = S32(0X4318 << 16);
    // 0x80800198: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080019C: lwc1        $f8, 0xA4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x808001A0: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x808001A4: jal         0x800F2100
    // 0x808001A8: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    mlAbsF(rdram, ctx);
        goto after_4;
    // 0x808001A8: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    after_4:
    // 0x808001AC: lui         $at, 0x42E4
    ctx->r1 = S32(0X42E4 << 16);
    // 0x808001B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808001B4: lwc1        $f18, 0xA8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x808001B8: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x808001BC: jal         0x800F2100
    // 0x808001C0: sub.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f4.fl;
    mlAbsF(rdram, ctx);
        goto after_5;
    // 0x808001C0: sub.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f4.fl;
    after_5:
    // 0x808001C4: lui         $at, 0x42E4
    ctx->r1 = S32(0X42E4 << 16);
    // 0x808001C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001CC: lwc1        $f14, 0xA8($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x808001D0: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x808001D4: jal         0x800F2100
    // 0x808001D8: sub.s       $f12, $f14, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f6.fl;
    mlAbsF(rdram, ctx);
        goto after_6;
    // 0x808001D8: sub.s       $f12, $f14, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f6.fl;
    after_6:
    // 0x808001DC: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x808001E0: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x808001E4: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x808001E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2296, 0X694) << 16);
    // 0x808001EC: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x808001F0: lwc1        $f10, 0x694($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2296, 0X694));
    // 0x808001F4: lw          $v0, 0xD0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD0);
    // 0x808001F8: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808001FC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2296, 0X69C) << 16);
    // 0x80800200: lwc1        $f2, 0x34($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80800204: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80800208: div.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8080020C: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80800210: mov.s       $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.fl = ctx->f12.fl;
    // 0x80800214: bc1f        L_80800250
    if (!c1cs) {
        // 0x80800218: nop
    
            goto L_80800250;
    }
    // 0x80800218: nop

    // 0x8080021C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2296, 0X698) << 16);
    // 0x80800220: lwc1        $f4, 0x698($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2296, 0X698));
    // 0x80800224: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80800228: swc1        $f6, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f6.u32l;
    // 0x8080022C: lwc1        $f2, 0x34($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80800230: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80800234: nop

    // 0x80800238: bc1f        L_80800248
    if (!c1cs) {
        // 0x8080023C: nop
    
            goto L_80800248;
    }
    // 0x8080023C: nop

    // 0x80800240: b           L_808002D8
    // 0x80800244: swc1        $f12, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f12.u32l;
        goto L_808002D8;
    // 0x80800244: swc1        $f12, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f12.u32l;
L_80800248:
    // 0x80800248: b           L_808002D8
    // 0x8080024C: mov.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
        goto L_808002D8;
    // 0x8080024C: mov.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
L_80800250:
    // 0x80800250: lwc1        $f18, 0x69C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2296, 0X69C));
    // 0x80800254: div.s       $f8, $f2, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = DIV_S(ctx->f2.fl, ctx->f18.fl);
    // 0x80800258: swc1        $f8, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f8.u32l;
    // 0x8080025C: lwc1        $f2, 0x34($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80800260: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80800264: nop

    // 0x80800268: bc1f        L_80800278
    if (!c1cs) {
        // 0x8080026C: nop
    
            goto L_80800278;
    }
    // 0x8080026C: nop

    // 0x80800270: b           L_808002D8
    // 0x80800274: swc1        $f12, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f12.u32l;
        goto L_808002D8;
    // 0x80800274: swc1        $f12, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f12.u32l;
L_80800278:
    // 0x80800278: b           L_808002D8
    // 0x8080027C: mov.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
        goto L_808002D8;
    // 0x8080027C: mov.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
L_80800280:
    // 0x80800280: lwc1        $f0, 0x6A0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2296, 0X6A0));
    // 0x80800284: lwc1        $f2, 0x34($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80800288: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2296, 0X6A4) << 16);
    // 0x8080028C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80800290: nop

    // 0x80800294: bc1fl       L_808002B0
    if (!c1cs) {
        // 0x80800298: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_808002B0;
    }
    goto skip_0;
    // 0x80800298: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x8080029C: lwc1        $f10, 0x6A4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2296, 0X6A4));
    // 0x808002A0: mul.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x808002A4: swc1        $f4, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f4.u32l;
    // 0x808002A8: lwc1        $f2, 0x34($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X34);
    // 0x808002AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_808002B0:
    // 0x808002B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808002B4: nop

    // 0x808002B8: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x808002BC: nop

    // 0x808002C0: bc1fl       L_808002D4
    if (!c1cs) {
        // 0x808002C4: swc1        $f2, 0xA0($sp)
        MEM_W(0XA0, ctx->r29) = ctx->f2.u32l;
            goto L_808002D4;
    }
    goto skip_1;
    // 0x808002C4: swc1        $f2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f2.u32l;
    skip_1:
    // 0x808002C8: b           L_80800608
    // 0x808002CC: swc1        $f0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f0.u32l;
        goto L_80800608;
    // 0x808002CC: swc1        $f0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f0.u32l;
    // 0x808002D0: swc1        $f2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f2.u32l;
L_808002D4:
    // 0x808002D4: lwc1        $f16, 0xA0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA0);
L_808002D8:
    // 0x808002D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808002DC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808002E0: addiu       $s5, $sp, 0xB8
    ctx->r21 = ADD32(ctx->r29, 0XB8);
    // 0x808002E4: lwc1        $f12, 0xA4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x808002E8: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x808002EC: lwc1        $f14, 0xA8($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x808002F0: lui         $at, 0x4398
    ctx->r1 = S32(0X4398 << 16);
    // 0x808002F4: bc1tl       L_8080060C
    if (c1cs) {
        // 0x808002F8: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8080060C;
    }
    goto skip_2;
    // 0x808002F8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_2:
    // 0x808002FC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800300: lui         $at, 0x4364
    ctx->r1 = S32(0X4364 << 16);
    // 0x80800304: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800308: sub.s       $f12, $f8, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x8080030C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80800310: addiu       $a3, $sp, 0xAC
    ctx->r7 = ADD32(ctx->r29, 0XAC);
    // 0x80800314: sub.s       $f14, $f10, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x80800318: swc1        $f12, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f12.u32l;
    // 0x8080031C: swc1        $f16, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f16.u32l;
    // 0x80800320: jal         0x800E40DC
    // 0x80800324: swc1        $f14, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f14.u32l;
    func_800E40DC(rdram, ctx);
        goto after_7;
    // 0x80800324: swc1        $f14, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f14.u32l;
    after_7:
    // 0x80800328: addiu       $a0, $sp, 0xAC
    ctx->r4 = ADD32(ctx->r29, 0XAC);
    // 0x8080032C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80800330: jal         0x800EFB24
    // 0x80800334: addiu       $a2, $sp, 0xC4
    ctx->r6 = ADD32(ctx->r29, 0XC4);
    func_800EFB24(rdram, ctx);
        goto after_8;
    // 0x80800334: addiu       $a2, $sp, 0xC4
    ctx->r6 = ADD32(ctx->r29, 0XC4);
    after_8:
    // 0x80800338: lw          $t1, 0xD0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XD0);
    // 0x8080033C: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2296, 0X8F4) << 16);
    // 0x80800340: addiu       $s2, $sp, 0x88
    ctx->r18 = ADD32(ctx->r29, 0X88);
    // 0x80800344: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x80800348: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080034C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800350: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x80800354: addu        $s1, $s1, $t3
    ctx->r17 = ADD32(ctx->r17, ctx->r11);
    // 0x80800358: lw          $s1, 0x8F4($s1)
    ctx->r17 = MEM_W(ctx->r17, (int16_t)RELOC_LO16(2296, 0X8F4));
    // 0x8080035C: lbu         $t4, 0xC($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0XC);
    // 0x80800360: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80800364: beql        $t4, $zero, L_80800384
    if (ctx->r12 == 0) {
        // 0x80800368: sll         $t6, $v0, 4
        ctx->r14 = S32(ctx->r2 << 4);
            goto L_80800384;
    }
    goto skip_3;
    // 0x80800368: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    skip_3:
    // 0x8080036C: lbu         $t5, 0x1C($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X1C);
L_80800370:
    // 0x80800370: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80800374: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80800378: bnel        $t5, $zero, L_80800370
    if (ctx->r13 != 0) {
        // 0x8080037C: lbu         $t5, 0x1C($s0)
        ctx->r13 = MEM_BU(ctx->r16, 0X1C);
            goto L_80800370;
    }
    goto skip_4;
    // 0x8080037C: lbu         $t5, 0x1C($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X1C);
    skip_4:
    // 0x80800380: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
L_80800384:
    // 0x80800384: addu        $s0, $s1, $t6
    ctx->r16 = ADD32(ctx->r17, ctx->r14);
    // 0x80800388: lbu         $a1, 0x0($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X0);
    // 0x8080038C: beql        $a1, $zero, L_808003F0
    if (ctx->r5 == 0) {
        // 0x80800390: or          $s6, $zero, $zero
        ctx->r22 = 0 | 0;
            goto L_808003F0;
    }
    goto skip_5;
    // 0x80800390: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    skip_5:
    // 0x80800394: lbu         $a2, 0x1($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1);
    // 0x80800398: jal         0x800EFA88
    // 0x8080039C: lbu         $a3, 0x2($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X2);
    func_800EFA88(rdram, ctx);
        goto after_9;
    // 0x8080039C: lbu         $a3, 0x2($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X2);
    after_9:
    // 0x808003A0: lbu         $t7, 0x3($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X3);
    // 0x808003A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808003A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808003AC: lwc1        $f6, 0xA0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x808003B0: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x808003B4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x808003B8: sub.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x808003BC: bgez        $t7, L_808003D4
    if (SIGNED(ctx->r15) >= 0) {
        // 0x808003C0: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_808003D4;
    }
    // 0x808003C0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x808003C4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808003C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808003CC: nop

    // 0x808003D0: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_808003D4:
    // 0x808003D4: mul.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x808003D8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x808003DC: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x808003E0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x808003E4: jal         0x800B99CC
    // 0x808003E8: nop

    func_800B99CC(rdram, ctx);
        goto after_10;
    // 0x808003E8: nop

    after_10:
    // 0x808003EC: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
L_808003F0:
    // 0x808003F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808003F4: jal         0x800E2588
    // 0x808003F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    func_800E2588(rdram, ctx);
        goto after_11;
    // 0x808003F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    after_11:
    // 0x808003FC: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    // 0x80800400: lbu         $a1, 0x1($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X1);
    // 0x80800404: jal         0x800E24F8
    // 0x80800408: lbu         $a2, 0x2($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X2);
    func_800E24F8(rdram, ctx);
        goto after_12;
    // 0x80800408: lbu         $a2, 0x2($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X2);
    after_12:
    // 0x8080040C: jal         0x800D674C
    // 0x80800410: addiu       $a0, $zero, 0x9D2
    ctx->r4 = ADD32(0, 0X9D2);
    func_800D674C(rdram, ctx);
        goto after_13;
    // 0x80800410: addiu       $a0, $zero, 0x9D2
    ctx->r4 = ADD32(0, 0X9D2);
    after_13:
    // 0x80800414: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80800418: jal         0x800E2594
    // 0x8080041C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800E2594(rdram, ctx);
        goto after_14;
    // 0x8080041C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_14:
    // 0x80800420: lbu         $t9, 0xC($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0XC);
    // 0x80800424: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800428: lwc1        $f10, 0xA0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8080042C: beq         $t9, $zero, L_808005F0
    if (ctx->r25 == 0) {
        // 0x80800430: nop
    
            goto L_808005F0;
    }
    // 0x80800430: nop

    // 0x80800434: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800438: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x8080043C: addiu       $s4, $sp, 0x60
    ctx->r20 = ADD32(ctx->r29, 0X60);
    // 0x80800440: sub.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80800444: addiu       $s3, $sp, 0x6C
    ctx->r19 = ADD32(ctx->r29, 0X6C);
    // 0x80800448: addiu       $s2, $sp, 0x7C
    ctx->r18 = ADD32(ctx->r29, 0X7C);
    // 0x8080044C: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    // 0x80800450: lbu         $t0, 0x3($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X3);
L_80800454:
    // 0x80800454: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800458: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8080045C: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x80800460: bgez        $t0, L_80800474
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80800464: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80800474;
    }
    // 0x80800464: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800468: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080046C: nop

    // 0x80800470: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
L_80800474:
    // 0x80800474: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800478: trunc.w.s   $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8080047C: mfc1        $s1, $f6
    ctx->r17 = (int32_t)ctx->f6.u32l;
    // 0x80800480: nop

    // 0x80800484: bnel        $s1, $s6, L_80800494
    if (ctx->r17 != ctx->r22) {
        // 0x80800488: or          $s6, $s1, $zero
        ctx->r22 = ctx->r17 | 0;
            goto L_80800494;
    }
    goto skip_6;
    // 0x80800488: or          $s6, $s1, $zero
    ctx->r22 = ctx->r17 | 0;
    skip_6:
    // 0x8080048C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800490: or          $s6, $s1, $zero
    ctx->r22 = ctx->r17 | 0;
L_80800494:
    // 0x80800494: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x80800498: lbu         $a1, 0x1($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1);
    // 0x8080049C: jal         0x800E24F8
    // 0x808004A0: lbu         $a2, 0x2($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X2);
    func_800E24F8(rdram, ctx);
        goto after_15;
    // 0x808004A0: lbu         $a2, 0x2($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X2);
    after_15:
    // 0x808004A4: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x808004A8: lwc1        $f8, 0xA0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x808004AC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808004B0: add.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x808004B4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808004B8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808004BC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808004C0: jal         0x800EFA4C
    // 0x808004C4: nop

    func_800EFA4C(rdram, ctx);
        goto after_16;
    // 0x808004C4: nop

    after_16:
    // 0x808004C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808004CC: jal         0x800EE7F8
    // 0x808004D0: addiu       $a1, $sp, 0xC4
    ctx->r5 = ADD32(ctx->r29, 0XC4);
    func_800EE7F8(rdram, ctx);
        goto after_17;
    // 0x808004D0: addiu       $a1, $sp, 0xC4
    ctx->r5 = ADD32(ctx->r29, 0XC4);
    after_17:
    // 0x808004D4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808004D8: addiu       $a1, $sp, 0xAC
    ctx->r5 = ADD32(ctx->r29, 0XAC);
    // 0x808004DC: jal         0x800EF174
    // 0x808004E0: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    func_800EF174(rdram, ctx);
        goto after_18;
    // 0x808004E0: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    after_18:
    // 0x808004E4: jal         0x800E3980
    // 0x808004E8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800E3980(rdram, ctx);
        goto after_19;
    // 0x808004E8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_19:
    // 0x808004EC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808004F0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x808004F4: jal         0x800EFB24
    // 0x808004F8: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_800EFB24(rdram, ctx);
        goto after_20;
    // 0x808004F8: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_20:
    // 0x808004FC: jal         0x800EEFD4
    // 0x80800500: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800EEFD4(rdram, ctx);
        goto after_21;
    // 0x80800500: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_21:
    // 0x80800504: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2296, 0X6A8) << 16);
    // 0x80800508: lwc1        $f10, 0x6A8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2296, 0X6A8));
    // 0x8080050C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800510: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800514: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80800518: lui         $a2, 0x469C
    ctx->r6 = S32(0X469C << 16);
    // 0x8080051C: bc1fl       L_80800540
    if (!c1cs) {
        // 0x80800520: lbu         $v0, 0xC($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0XC);
            goto L_80800540;
    }
    goto skip_7;
    // 0x80800520: lbu         $v0, 0xC($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XC);
    skip_7:
    // 0x80800524: jal         0x800EFA98
    // 0x80800528: ori         $a2, $a2, 0x4000
    ctx->r6 = ctx->r6 | 0X4000;
    func_800EFA98(rdram, ctx);
        goto after_22;
    // 0x80800528: ori         $a2, $a2, 0x4000
    ctx->r6 = ctx->r6 | 0X4000;
    after_22:
    // 0x8080052C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800530: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800534: jal         0x800EE780
    // 0x80800538: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_800EE780(rdram, ctx);
        goto after_23;
    // 0x80800538: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_23:
    // 0x8080053C: lbu         $v0, 0xC($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XC);
L_80800540:
    // 0x80800540: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800544: beq         $v0, $at, L_80800564
    if (ctx->r2 == ctx->r1) {
        // 0x80800548: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800564;
    }
    // 0x80800548: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080054C: beq         $v0, $at, L_80800594
    if (ctx->r2 == ctx->r1) {
        // 0x80800550: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800594;
    }
    // 0x80800550: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800554: beq         $v0, $at, L_808005C8
    if (ctx->r2 == ctx->r1) {
        // 0x80800558: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_808005C8;
    }
    // 0x80800558: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8080055C: b           L_808005E4
    // 0x80800560: lbu         $t2, 0x1C($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X1C);
        goto L_808005E4;
    // 0x80800560: lbu         $t2, 0x1C($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X1C);
L_80800564:
    // 0x80800564: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800568: jal         0x800E2530
    // 0x8080056C: nop

    func_800E2530(rdram, ctx);
        goto after_24;
    // 0x8080056C: nop

    after_24:
    // 0x80800570: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80800574: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800578: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080057C: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x80800580: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x80800584: jal         0x800E2720
    // 0x80800588: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    func_800E2720(rdram, ctx);
        goto after_25;
    // 0x80800588: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    after_25:
    // 0x8080058C: b           L_808005E4
    // 0x80800590: lbu         $t2, 0x1C($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X1C);
        goto L_808005E4;
    // 0x80800590: lbu         $t2, 0x1C($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X1C);
L_80800594:
    // 0x80800594: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80800598: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080059C: jal         0x800E2530
    // 0x808005A0: nop

    func_800E2530(rdram, ctx);
        goto after_26;
    // 0x808005A0: nop

    after_26:
    // 0x808005A4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x808005A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808005AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808005B0: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x808005B4: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x808005B8: jal         0x800E2720
    // 0x808005BC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    func_800E2720(rdram, ctx);
        goto after_27;
    // 0x808005BC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    after_27:
    // 0x808005C0: b           L_808005E4
    // 0x808005C4: lbu         $t2, 0x1C($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X1C);
        goto L_808005E4;
    // 0x808005C4: lbu         $t2, 0x1C($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X1C);
L_808005C8:
    // 0x808005C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808005CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808005D0: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x808005D4: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x808005D8: jal         0x800E2720
    // 0x808005DC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    func_800E2720(rdram, ctx);
        goto after_28;
    // 0x808005DC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    after_28:
    // 0x808005E0: lbu         $t2, 0x1C($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X1C);
L_808005E4:
    // 0x808005E4: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x808005E8: bnel        $t2, $zero, L_80800454
    if (ctx->r10 != 0) {
        // 0x808005EC: lbu         $t0, 0x3($s0)
        ctx->r8 = MEM_BU(ctx->r16, 0X3);
            goto L_80800454;
    }
    goto skip_8;
    // 0x808005EC: lbu         $t0, 0x3($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X3);
    skip_8:
L_808005F0:
    // 0x808005F0: jal         0x800E2A14
    // 0x808005F4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_800E2A14(rdram, ctx);
        goto after_29;
    // 0x808005F4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_29:
    // 0x808005F8: lw          $t3, 0xD0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XD0);
    // 0x808005FC: lbu         $t4, 0x65($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X65);
    // 0x80800600: andi        $t5, $t4, 0xFFEF
    ctx->r13 = ctx->r12 & 0XFFEF;
    // 0x80800604: sb          $t5, 0x65($t3)
    MEM_B(0X65, ctx->r11) = ctx->r13;
L_80800608:
    // 0x80800608: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8080060C:
    // 0x8080060C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800610: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800614: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80800618: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8080061C: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80800620: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80800624: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x80800628: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x8080062C: jr          $ra
    // 0x80800630: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x80800630: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void _cadbfunc_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800855A8: syscall     169
    recomp_syscall_handler(rdram, ctx, 0x800855A8);
    return;
    // 0x800855AC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80800000_bamovegoto(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: beq         $a1, $zero, L_80800020
    if (ctx->r5 == 0) {
        // 0x80800010: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_80800020;
    }
    // 0x80800010: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800014: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800018: bnel        $a1, $at, L_80800044
    if (ctx->r5 != ctx->r1) {
        // 0x8080001C: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_80800044;
    }
    goto skip_0;
    // 0x8080001C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    skip_0:
L_80800020:
    // 0x80800020: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800024: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800028: jal         0x8009B9B0
    // 0x8080002C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_0;
    // 0x8080002C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800030: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800034: jal         0x8009BA9C
    // 0x80800038: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009BA9C(rdram, ctx);
        goto after_1;
    // 0x80800038: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8080003C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80800040: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
L_80800044:
    // 0x80800044: lw          $t7, 0xC8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC8);
    // 0x80800048: sb          $a2, 0x54($t7)
    MEM_B(0X54, ctx->r15) = ctx->r6;
    // 0x8080004C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800050: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800054: jr          $ra
    // 0x80800058: nop

    return;
    // 0x80800058: nop

;}
RECOMP_FUNC void func_800D0CE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0CE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D0CE4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D0CE8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D0CEC: sltiu       $at, $a2, 0x7
    ctx->r1 = ctx->r6 < 0X7 ? 1 : 0;
    // 0x800D0CF0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800D0CF4: beq         $at, $zero, L_800D0D94
    if (ctx->r1 == 0) {
        // 0x800D0CF8: sw          $zero, 0x0($a3)
        MEM_W(0X0, ctx->r7) = 0;
            goto L_800D0D94;
    }
    // 0x800D0CF8: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x800D0CFC: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x800D0D00: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D0D04: addu        $at, $at, $t6
    gpr jr_addend_800D0D0C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800D0D08: lw          $t6, 0x5A98($at)
    ctx->r14 = ADD32(ctx->r1, 0X5A98);
    // 0x800D0D0C: jr          $t6
    // 0x800D0D10: nop

    switch (jr_addend_800D0D0C >> 2) {
        case 0: goto L_800D0D14; break;
        case 1: goto L_800D0D28; break;
        case 2: goto L_800D0D58; break;
        case 3: goto L_800D0D50; break;
        case 4: goto L_800D0D3C; break;
        case 5: goto L_800D0D6C; break;
        case 6: goto L_800D0D80; break;
        default: switch_error(__func__, 0x800D0D0C, 0x80125A98);
    }
    // 0x800D0D10: nop

L_800D0D14:
    // 0x800D0D14: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x800D0D18: jal         0x80085900
    // 0x800D0D1C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    _chbounce_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x800D0D1C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_0:
    // 0x800D0D20: b           L_800D0D9C
    // 0x800D0D24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800D0D9C;
    // 0x800D0D24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800D0D28:
    // 0x800D0D28: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x800D0D2C: jal         0x80085900
    // 0x800D0D30: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    _chbounce_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x800D0D30: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_1:
    // 0x800D0D34: b           L_800D0D9C
    // 0x800D0D38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800D0D9C;
    // 0x800D0D38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800D0D3C:
    // 0x800D0D3C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x800D0D40: jal         0x80085900
    // 0x800D0D44: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    _chbounce_entrypoint_7(rdram, ctx);
        goto after_2;
    // 0x800D0D44: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_2:
    // 0x800D0D48: b           L_800D0D9C
    // 0x800D0D4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800D0D9C;
    // 0x800D0D4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800D0D50:
    // 0x800D0D50: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800D0D54: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
L_800D0D58:
    // 0x800D0D58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D0D5C: jal         0x80108474
    // 0x800D0D60: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80108474(rdram, ctx);
        goto after_3;
    // 0x800D0D60: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x800D0D64: b           L_800D0D9C
    // 0x800D0D68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800D0D9C;
    // 0x800D0D68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800D0D6C:
    // 0x800D0D6C: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x800D0D70: jal         0x80085900
    // 0x800D0D74: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    _chbounce_entrypoint_7(rdram, ctx);
        goto after_4;
    // 0x800D0D74: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_4:
    // 0x800D0D78: b           L_800D0D9C
    // 0x800D0D7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800D0D9C;
    // 0x800D0D7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800D0D80:
    // 0x800D0D80: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x800D0D84: jal         0x80085900
    // 0x800D0D88: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    _chbounce_entrypoint_7(rdram, ctx);
        goto after_5;
    // 0x800D0D88: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_5:
    // 0x800D0D8C: b           L_800D0D9C
    // 0x800D0D90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800D0D9C;
    // 0x800D0D90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800D0D94:
    // 0x800D0D94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D0D98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800D0D9C:
    // 0x800D0D9C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D0DA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D0DA4: jr          $ra
    // 0x800D0DA8: nop

    return;
    // 0x800D0DA8: nop

;}
RECOMP_FUNC void func_8080069C_chdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080069C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808006A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006A4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808006A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808006AC: jal         0x80100094
    // 0x808006B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808006B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808006B4: lh          $t6, 0x42($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X42);
    // 0x808006B8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x808006BC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808006C0: beql        $t6, $zero, L_80800748
    if (ctx->r14 == 0) {
        // 0x808006C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800748;
    }
    goto skip_0;
    // 0x808006C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808006C8: beq         $v1, $zero, L_808006DC
    if (ctx->r3 == 0) {
        // 0x808006CC: nop
    
            goto L_808006DC;
    }
    // 0x808006CC: nop

    // 0x808006D0: lh          $t7, 0x3E($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X3E);
    // 0x808006D4: bnel        $t7, $zero, L_808006F4
    if (ctx->r15 != 0) {
        // 0x808006D8: lh          $a0, 0x42($a1)
        ctx->r4 = MEM_H(ctx->r5, 0X42);
            goto L_808006F4;
    }
    goto skip_1;
    // 0x808006D8: lh          $a0, 0x42($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X42);
    skip_1:
L_808006DC:
    // 0x808006DC: bnel        $v1, $zero, L_80800748
    if (ctx->r3 != 0) {
        // 0x808006E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800748;
    }
    goto skip_2;
    // 0x808006E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x808006E4: lh          $t8, 0x40($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X40);
    // 0x808006E8: beql        $t8, $zero, L_80800748
    if (ctx->r24 == 0) {
        // 0x808006EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800748;
    }
    goto skip_3;
    // 0x808006EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x808006F0: lh          $a0, 0x42($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X42);
L_808006F4:
    // 0x808006F4: jal         0x800C4B7C
    // 0x808006F8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800C4B7C(rdram, ctx);
        goto after_1;
    // 0x808006F8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x808006FC: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80800700: jal         0x800C4B70
    // 0x80800704: lh          $a0, 0x44($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X44);
    func_800C4B70(rdram, ctx);
        goto after_2;
    // 0x80800704: lh          $a0, 0x44($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X44);
    after_2:
    // 0x80800708: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8080070C: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x80800710: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800714: lh          $t1, 0x46($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X46);
    // 0x80800718: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8080071C: nop

    // 0x80800720: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800724: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800728: jal         0x800C4B64
    // 0x8080072C: nop

    func_800C4B64(rdram, ctx);
        goto after_3;
    // 0x8080072C: nop

    after_3:
    // 0x80800730: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800734: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1148, 0X15B0) << 16);
    // 0x80800738: addiu       $a2, $a2, 0x15B0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1148, 0X15B0));
    // 0x8080073C: jal         0x80089D18
    // 0x80800740: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x80800740: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_4:
    // 0x80800744: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800748:
    // 0x80800748: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080074C: jr          $ra
    // 0x80800750: nop

    return;
    // 0x80800750: nop

;}
RECOMP_FUNC void func_80800D04_chbanjoctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D0C: lwc1        $f4, 0x1C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80800D10: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80800D14: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800D18: nop

    // 0x80800D1C: bc1fl       L_80800D44
    if (!c1cs) {
        // 0x80800D20: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800D44;
    }
    goto skip_0;
    // 0x80800D20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800D24: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x80800D28: jal         0x800F54E4
    // 0x80800D2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800D2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800D30: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800D34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800D38: jal         0x800F8418
    // 0x80800D3C: addiu       $a1, $a2, 0x18
    ctx->r5 = ADD32(ctx->r6, 0X18);
    func_800F8418(rdram, ctx);
        goto after_1;
    // 0x80800D3C: addiu       $a1, $a2, 0x18
    ctx->r5 = ADD32(ctx->r6, 0X18);
    after_1:
    // 0x80800D40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800D44:
    // 0x80800D44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D48: jr          $ra
    // 0x80800D4C: nop

    return;
    // 0x80800D4C: nop

;}
RECOMP_FUNC void _chdinofamilysick_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800876F0: syscall     610
    recomp_syscall_handler(rdram, ctx, 0x800876F0);
    return;
    // 0x800876F4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808000EC_bsrebound(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000F4: jal         0x800845D0
    // 0x808000F8: nop

    _babounce_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808000F8: nop

    after_0:
    // 0x808000FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800100: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800104: jr          $ra
    // 0x80800108: nop

    return;
    // 0x80800108: nop

;}
RECOMP_FUNC void _gccubesearch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088278: syscall     678
    recomp_syscall_handler(rdram, ctx, 0x80088278);
    return;
    // 0x8008827C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80801568_chfishshootgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801568: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080156C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801570: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80801574: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801578: lwc1        $f6, 0x58($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X58);
    // 0x8080157C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(740, 0X1838) << 16);
    // 0x80801580: lwc1        $f4, 0x1838($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(740, 0X1838));
    // 0x80801584: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x80801588: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8080158C: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
    // 0x80801590: bc1f        L_808015AC
    if (!c1cs) {
        // 0x80801594: nop
    
            goto L_808015AC;
    }
    // 0x80801594: nop

    // 0x80801598: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080159C: jal         0x800DC178
    // 0x808015A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x808015A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808015A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808015A8: swc1        $f0, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f0.u32l;
L_808015AC:
    // 0x808015AC: jal         0x80801358
    // 0x808015B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80801358_chfishshootgame(rdram, ctx);
        goto after_1;
    // 0x808015B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x808015B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808015B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808015BC: lbu         $t6, 0x72($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X72);
    // 0x808015C0: andi        $t7, $t6, 0xFF03
    ctx->r15 = ctx->r14 & 0XFF03;
    // 0x808015C4: jal         0x80801424
    // 0x808015C8: sb          $t7, 0x72($a0)
    MEM_B(0X72, ctx->r4) = ctx->r15;
    func_80801424_chfishshootgame(rdram, ctx);
        goto after_2;
    // 0x808015C8: sb          $t7, 0x72($a0)
    MEM_B(0X72, ctx->r4) = ctx->r15;
    after_2:
    // 0x808015CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808015D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808015D4: jr          $ra
    // 0x808015D8: nop

    return;
    // 0x808015D8: nop

;}
RECOMP_FUNC void func_8080000C_chweldarhead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80800010: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800018: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080001C: jal         0x80100094
    // 0x80800020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800024: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x80800028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080002C: addiu       $a1, $v0, 0x18
    ctx->r5 = ADD32(ctx->r2, 0X18);
    // 0x80800030: jal         0x8008A2A0
    // 0x80800034: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _susubgame_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800034: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80800038: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8080003C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1404, 0X4E0) << 16);
    // 0x80800040: addiu       $a1, $a1, 0x4E0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1404, 0X4E0));
    // 0x80800044: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    // 0x80800048: jal         0x8008A300
    // 0x8080004C: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    _susubgame_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x8080004C: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_2:
    // 0x80800050: jal         0x800DA298
    // 0x80800054: addiu       $a0, $zero, 0x18C
    ctx->r4 = ADD32(0, 0X18C);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80800054: addiu       $a0, $zero, 0x18C
    ctx->r4 = ADD32(0, 0X18C);
    after_3:
    // 0x80800058: bne         $v0, $zero, L_80800070
    if (ctx->r2 != 0) {
        // 0x8080005C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800070;
    }
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800060: jal         0x800FFAB0
    // 0x80800064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_4;
    // 0x80800064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800068: b           L_80800160
    // 0x8080006C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800160;
    // 0x8080006C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800070:
    // 0x80800070: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800074: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800078: addiu       $a1, $zero, 0x320
    ctx->r5 = ADD32(0, 0X320);
    // 0x8080007C: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    // 0x80800080: jal         0x8008A0C8
    // 0x80800084: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    _subaddiemarker_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x80800084: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    after_5:
    // 0x80800088: addiu       $a0, $zero, 0x9C9
    ctx->r4 = ADD32(0, 0X9C9);
    // 0x8080008C: jal         0x800DA9E4
    // 0x80800090: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DA9E4(rdram, ctx);
        goto after_6;
    // 0x80800090: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80800094: beql        $v0, $zero, L_80800148
    if (ctx->r2 == 0) {
        // 0x80800098: lbu         $t9, 0x65($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X65);
            goto L_80800148;
    }
    goto skip_0;
    // 0x80800098: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    skip_0:
    // 0x8080009C: jal         0x800F54E4
    // 0x808000A0: nop

    func_800F54E4(rdram, ctx);
        goto after_7;
    // 0x808000A0: nop

    after_7:
    // 0x808000A4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808000A8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x808000AC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B4: addiu       $a1, $zero, 0x320
    ctx->r5 = ADD32(0, 0X320);
    // 0x808000B8: addiu       $a2, $zero, 0x33
    ctx->r6 = ADD32(0, 0X33);
    // 0x808000BC: jal         0x8008A0C8
    // 0x808000C0: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
    _subaddiemarker_entrypoint_1(rdram, ctx);
        goto after_8;
    // 0x808000C0: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
    after_8:
    // 0x808000C4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808000C8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D0: addiu       $a1, $zero, 0x320
    ctx->r5 = ADD32(0, 0X320);
    // 0x808000D4: addiu       $a2, $zero, 0x34
    ctx->r6 = ADD32(0, 0X34);
    // 0x808000D8: jal         0x8008A0C8
    // 0x808000DC: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    _subaddiemarker_entrypoint_1(rdram, ctx);
        goto after_9;
    // 0x808000DC: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    after_9:
    // 0x808000E0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808000E4: jal         0x800F8294
    // 0x808000E8: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_800F8294(rdram, ctx);
        goto after_10;
    // 0x808000E8: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_10:
    // 0x808000EC: jal         0x800F497C
    // 0x808000F0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800F497C(rdram, ctx);
        goto after_11;
    // 0x808000F0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_11:
    // 0x808000F4: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x808000F8: addiu       $a1, $a1, -0x2A24
    ctx->r5 = ADD32(ctx->r5, -0X2A24);
    // 0x808000FC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800100: jal         0x800F49D4
    // 0x80800104: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    func_800F49D4(rdram, ctx);
        goto after_12;
    // 0x80800104: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    after_12:
    // 0x80800108: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8080010C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80800110: jal         0x800F4A58
    // 0x80800114: lui         $a2, 0x437A
    ctx->r6 = S32(0X437A << 16);
    func_800F4A58(rdram, ctx);
        goto after_13;
    // 0x80800114: lui         $a2, 0x437A
    ctx->r6 = S32(0X437A << 16);
    after_13:
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080011C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800120: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    // 0x80800124: addiu       $a3, $zero, 0x2030
    ctx->r7 = ADD32(0, 0X2030);
    // 0x80800128: jal         0x8008A2D0
    // 0x8080012C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_6(rdram, ctx);
        goto after_14;
    // 0x8080012C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_14:
    // 0x80800130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800134: jal         0x80102424
    // 0x80800138: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_15;
    // 0x80800138: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_15:
    // 0x8080013C: b           L_80800160
    // 0x80800140: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800160;
    // 0x80800140: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800144: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
L_80800148:
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080014C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800150: andi        $t0, $t9, 0xFFEF
    ctx->r8 = ctx->r25 & 0XFFEF;
    // 0x80800154: jal         0x80108B04
    // 0x80800158: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    func_80108B04(rdram, ctx);
        goto after_16;
    // 0x80800158: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    after_16:
    // 0x8080015C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800160:
    // 0x80800160: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800164: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80800168: jr          $ra
    // 0x8080016C: nop

    return;
    // 0x8080016C: nop

;}
RECOMP_FUNC void bareact_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800084: lw          $t6, 0xEC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XEC);
    // 0x80800088: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8080008C: jr          $ra
    // 0x80800090: lwc1        $f0, 0xC($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0XC);
    return;
    // 0x80800090: lwc1        $f0, 0xC($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0XC);
;}
RECOMP_FUNC void func_80800000_bsblongleg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x8008E35C
    // 0x8080000C: nop

    player_inWater(rdram, ctx);
        goto after_0;
    // 0x8080000C: nop

    after_0:
    // 0x80800010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800014: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800018: jr          $ra
    // 0x8080001C: nop

    return;
    // 0x8080001C: nop

;}
RECOMP_FUNC void bsstonehead_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800A14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A18: jal         0x80800060
    // 0x80800A1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800060_bsstonehead(rdram, ctx);
        goto after_0;
    // 0x80800A1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800A20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800A24: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800A28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800A2C: jal         0x808008CC
    // 0x80800A30: sw          $t6, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r14;
    func_808008CC_bsstonehead(rdram, ctx);
        goto after_1;
    // 0x80800A30: sw          $t6, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r14;
    after_1:
    // 0x80800A34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A3C: jr          $ra
    // 0x80800A40: nop

    return;
    // 0x80800A40: nop

;}
RECOMP_FUNC void func_80801290_chballoonburst(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801290: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801294: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801298: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080129C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808012A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808012A4: jal         0x800BF744
    // 0x808012A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BF744(rdram, ctx);
        goto after_0;
    // 0x808012A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808012AC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x808012B0: jal         0x800BF744
    // 0x808012B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800BF744(rdram, ctx);
        goto after_1;
    // 0x808012B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808012B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808012BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808012C0: jal         0x800BF544
    // 0x808012C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800BF544(rdram, ctx);
        goto after_2;
    // 0x808012C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x808012C8: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x808012CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808012D0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x808012D4: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808012D8: bne         $t7, $at, L_808012E8
    if (ctx->r15 != ctx->r1) {
        // 0x808012DC: nop
    
            goto L_808012E8;
    }
    // 0x808012DC: nop

    // 0x808012E0: jal         0x8008A090
    // 0x808012E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiemulti_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x808012E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
L_808012E8:
    // 0x808012E8: jal         0x80088368
    // 0x808012EC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x808012EC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_4:
    // 0x808012F0: blez        $v0, L_80801324
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808012F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801324;
    }
    // 0x808012F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808012F8:
    // 0x808012F8: addiu       $a1, $zero, 0x5D
    ctx->r5 = ADD32(0, 0X5D);
    // 0x808012FC: jal         0x800F7C58
    // 0x80801300: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800F7C58(rdram, ctx);
        goto after_5;
    // 0x80801300: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80801304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801308: jal         0x800F4CEC
    // 0x8080130C: addiu       $a1, $zero, 0x77
    ctx->r5 = ADD32(0, 0X77);
    func_800F4CEC(rdram, ctx);
        goto after_6;
    // 0x8080130C: addiu       $a1, $zero, 0x77
    ctx->r5 = ADD32(0, 0X77);
    after_6:
    // 0x80801310: jal         0x80088368
    // 0x80801314: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_7;
    // 0x80801314: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_7:
    // 0x80801318: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8080131C: bnel        $at, $zero, L_808012F8
    if (ctx->r1 != 0) {
        // 0x80801320: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808012F8;
    }
    goto skip_0;
    // 0x80801320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
L_80801324:
    // 0x80801324: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801328: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080132C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801330: jr          $ra
    // 0x80801334: nop

    return;
    // 0x80801334: nop

;}
