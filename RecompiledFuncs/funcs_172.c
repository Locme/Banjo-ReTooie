#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_808001E4_glgamedata(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001E4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x808001E8: jr          $ra
    // 0x808001EC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x808001EC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808005AC_chintroticker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808005B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808005B4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x808005B8: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x808005BC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x808005C0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808005C4: jal         0x800EA05C
    // 0x808005C8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x808005C8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x808005CC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x808005D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808005D4: jal         0x800DA9E4
    // 0x808005D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DA9E4(rdram, ctx);
        goto after_1;
    // 0x808005D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808005DC: beq         $v0, $zero, L_80800614
    if (ctx->r2 == 0) {
        // 0x808005E0: lui         $s0, 0x8080
        ctx->r16 = S32(RELOC_HI16(1648, 0X8C4) << 16);
            goto L_80800614;
    }
    // 0x808005E0: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(1648, 0X8C4) << 16);
    // 0x808005E4: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(1648, 0X934) << 16);
    // 0x808005E8: addiu       $s1, $s1, 0x934
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(1648, 0X934));
    // 0x808005EC: addiu       $s0, $s0, 0x8C4
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(1648, 0X8C4));
    // 0x808005F0: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
L_808005F4:
    // 0x808005F4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808005F8: bnel        $s2, $t6, L_8080060C
    if (ctx->r18 != ctx->r14) {
        // 0x808005FC: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8080060C;
    }
    goto skip_0;
    // 0x808005FC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x80800600: jal         0x808004A8
    // 0x80800604: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    func_808004A8_chintroticker(rdram, ctx);
        goto after_2;
    // 0x80800604: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    after_2:
    // 0x80800608: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8080060C:
    // 0x8080060C: bnel        $s0, $s1, L_808005F4
    if (ctx->r16 != ctx->r17) {
        // 0x80800610: lh          $t6, 0x0($s0)
        ctx->r14 = MEM_H(ctx->r16, 0X0);
            goto L_808005F4;
    }
    goto skip_1;
    // 0x80800610: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    skip_1:
L_80800614:
    // 0x80800614: lbu         $v0, 0x79($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X79);
    // 0x80800618: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8080061C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800620: srl         $t7, $v0, 4
    ctx->r15 = S32(U32(ctx->r2) >> 4);
    // 0x80800624: beq         $t7, $s0, L_8080063C
    if (ctx->r15 == ctx->r16) {
        // 0x80800628: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8080063C;
    }
    // 0x80800628: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080062C: beq         $t7, $at, L_8080067C
    if (ctx->r15 == ctx->r1) {
        // 0x80800630: nop
    
            goto L_8080067C;
    }
    // 0x80800630: nop

    // 0x80800634: b           L_8080067C
    // 0x80800638: nop

        goto L_8080067C;
    // 0x80800638: nop

L_8080063C:
    // 0x8080063C: jal         0x800DA298
    // 0x80800640: addiu       $a0, $zero, 0xD56
    ctx->r4 = ADD32(0, 0XD56);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80800640: addiu       $a0, $zero, 0xD56
    ctx->r4 = ADD32(0, 0XD56);
    after_3:
    // 0x80800644: beq         $v0, $zero, L_80800694
    if (ctx->r2 == 0) {
        // 0x80800648: nop
    
            goto L_80800694;
    }
    // 0x80800648: nop

    // 0x8080064C: jal         0x800A8264
    // 0x80800650: nop

    func_800A8264(rdram, ctx);
        goto after_4;
    // 0x80800650: nop

    after_4:
    // 0x80800654: bne         $v0, $zero, L_80800694
    if (ctx->r2 != 0) {
        // 0x80800658: nop
    
            goto L_80800694;
    }
    // 0x80800658: nop

    // 0x8080065C: jal         0x80015FA0
    // 0x80800660: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80015FA0(rdram, ctx);
        goto after_5;
    // 0x80800660: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x80800664: bne         $v0, $s0, L_80800694
    if (ctx->r2 != ctx->r16) {
        // 0x80800668: nop
    
            goto L_80800694;
    }
    // 0x80800668: nop

    // 0x8080066C: jal         0x80088180
    // 0x80800670: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_6;
    // 0x80800670: nop

    after_6:
    // 0x80800674: b           L_80800694
    // 0x80800678: nop

        goto L_80800694;
    // 0x80800678: nop

L_8080067C:
    // 0x8080067C: jal         0x80016B30
    // 0x80800680: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80016B30(rdram, ctx);
        goto after_7;
    // 0x80800680: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x80800684: bne         $v0, $s0, L_80800694
    if (ctx->r2 != ctx->r16) {
        // 0x80800688: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80800694;
    }
    // 0x80800688: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8080068C: jal         0x80800530
    // 0x80800690: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80800530_chintroticker(rdram, ctx);
        goto after_8;
    // 0x80800690: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_8:
L_80800694:
    // 0x80800694: jal         0x800D9004
    // 0x80800698: nop

    func_800D9004(rdram, ctx);
        goto after_9;
    // 0x80800698: nop

    after_9:
    // 0x8080069C: jal         0x800885F0
    // 0x808006A0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    _glintrosyncDll_entrypoint_4(rdram, ctx);
        goto after_10;
    // 0x808006A0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_10:
    // 0x808006A4: jal         0x800D9004
    // 0x808006A8: nop

    func_800D9004(rdram, ctx);
        goto after_11;
    // 0x808006A8: nop

    after_11:
    // 0x808006AC: lwc1        $f4, 0x28($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X28);
    // 0x808006B0: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x808006B4: jal         0x800D8FF8
    // 0x808006B8: swc1        $f6, 0x28($s3)
    MEM_W(0X28, ctx->r19) = ctx->f6.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_12;
    // 0x808006B8: swc1        $f6, 0x28($s3)
    MEM_W(0X28, ctx->r19) = ctx->f6.u32l;
    after_12:
    // 0x808006BC: lwc1        $f8, 0x2C($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X2C);
    // 0x808006C0: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x808006C4: swc1        $f10, 0x2C($s3)
    MEM_W(0X2C, ctx->r19) = ctx->f10.u32l;
    // 0x808006C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808006CC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808006D0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808006D4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808006D8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808006DC: jr          $ra
    // 0x808006E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808006E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8080087C_chsilo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080087C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800880: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800884: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800888: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080088C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800890: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80800894: jal         0x80088280
    // 0x80800898: addiu       $a0, $zero, 0x309
    ctx->r4 = ADD32(0, 0X309);
    _gccubesearch_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800898: addiu       $a0, $zero, 0x309
    ctx->r4 = ADD32(0, 0X309);
    after_0:
    // 0x8080089C: lhu         $t6, 0x76($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X76);
    // 0x808008A0: lhu         $t1, 0x6E($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X6E);
    // 0x808008A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808008A8: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x808008AC: addiu       $t9, $t7, -0x32
    ctx->r25 = ADD32(ctx->r15, -0X32);
    // 0x808008B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808008B4: andi        $t0, $t9, 0x1FF
    ctx->r8 = ctx->r25 & 0X1FF;
    // 0x808008B8: andi        $t2, $t1, 0xFE00
    ctx->r10 = ctx->r9 & 0XFE00;
    // 0x808008BC: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x808008C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808008C4: sh          $t3, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r11;
    // 0x808008C8: bne         $v0, $zero, L_8080090C
    if (ctx->r2 != 0) {
        // 0x808008CC: swc1        $f4, 0x38($s0)
        MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
            goto L_8080090C;
    }
    // 0x808008CC: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    // 0x808008D0: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x808008D4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x808008D8: jal         0x800EE7F8
    // 0x808008DC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x808008DC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x808008E0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808008E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808008E8: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808008EC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808008F0: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    // 0x808008F4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x808008F8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x808008FC: jal         0x800EF1B8
    // 0x80800900: nop

    func_800EF1B8(rdram, ctx);
        goto after_2;
    // 0x80800900: nop

    after_2:
    // 0x80800904: b           L_80800918
    // 0x80800908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800918;
    // 0x80800908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080090C:
    // 0x8080090C: jal         0x80088C00
    // 0x80800910: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x80800910: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_3:
    // 0x80800914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800918:
    // 0x80800918: jal         0x8010A828
    // 0x8080091C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010A828(rdram, ctx);
        goto after_4;
    // 0x8080091C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x80800920: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x80800924: andi        $t4, $a0, 0x1FF
    ctx->r12 = ctx->r4 & 0X1FF;
    // 0x80800928: jal         0x800DA298
    // 0x8080092C: addiu       $a0, $t4, 0x32C
    ctx->r4 = ADD32(ctx->r12, 0X32C);
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x8080092C: addiu       $a0, $t4, 0x32C
    ctx->r4 = ADD32(ctx->r12, 0X32C);
    after_5:
    // 0x80800930: beq         $v0, $zero, L_808009CC
    if (ctx->r2 == 0) {
        // 0x80800934: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009CC;
    }
    // 0x80800934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800938: lbu         $t6, 0x65($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X65);
    // 0x8080093C: addiu       $a0, $zero, 0x6BF
    ctx->r4 = ADD32(0, 0X6BF);
    // 0x80800940: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800944: ori         $t7, $t6, 0x10
    ctx->r15 = ctx->r14 | 0X10;
    // 0x80800948: jal         0x800DA9E4
    // 0x8080094C: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
    func_800DA9E4(rdram, ctx);
        goto after_6;
    // 0x8080094C: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
    after_6:
    // 0x80800950: beq         $v0, $zero, L_808009B8
    if (ctx->r2 == 0) {
        // 0x80800954: lui         $at, 0x425C
        ctx->r1 = S32(0X425C << 16);
            goto L_808009B8;
    }
    // 0x80800954: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x80800958: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8080095C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800960: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80800964: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800968: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8080096C: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x80800970: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800974: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800978: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080097C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80800980: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800984: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80800988: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8080098C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80800990: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80800994: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80800998: jal         0x8010CB0C
    // 0x8080099C: nop

    func_8010CB0C(rdram, ctx);
        goto after_7;
    // 0x8080099C: nop

    after_7:
    // 0x808009A0: beq         $v0, $zero, L_808009B8
    if (ctx->r2 == 0) {
        // 0x808009A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009B8;
    }
    // 0x808009A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009A8: jal         0x808004C0
    // 0x808009AC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_808004C0_chsilo(rdram, ctx);
        goto after_8;
    // 0x808009AC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_8:
    // 0x808009B0: b           L_808009D8
    // 0x808009B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808009D8;
    // 0x808009B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808009B8:
    // 0x808009B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009BC: jal         0x808004C0
    // 0x808009C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808004C0_chsilo(rdram, ctx);
        goto after_9;
    // 0x808009C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x808009C4: b           L_808009D8
    // 0x808009C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808009D8;
    // 0x808009C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808009CC:
    // 0x808009CC: jal         0x808004C0
    // 0x808009D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808004C0_chsilo(rdram, ctx);
        goto after_10;
    // 0x808009D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x808009D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808009D8:
    // 0x808009D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808009DC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808009E0: jr          $ra
    // 0x808009E4: nop

    return;
    // 0x808009E4: nop

;}
RECOMP_FUNC void func_80800000_bsmumattack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: lbu         $a1, 0x160($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X160);
    // 0x8080000C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800010: beq         $a1, $zero, L_80800028
    if (ctx->r5 == 0) {
        // 0x80800014: andi        $a0, $a1, 0xFF
        ctx->r4 = ctx->r5 & 0XFF;
            goto L_80800028;
    }
    // 0x80800014: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x80800018: jal         0x800C2FDC
    // 0x8080001C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800C2FDC(rdram, ctx);
        goto after_0;
    // 0x8080001C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800020: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800024: sb          $zero, 0x160($a2)
    MEM_B(0X160, ctx->r6) = 0;
L_80800028:
    // 0x80800028: lw          $a0, 0x164($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X164);
    // 0x8080002C: beql        $a0, $zero, L_80800048
    if (ctx->r4 == 0) {
        // 0x80800030: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800048;
    }
    goto skip_0;
    // 0x80800030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800034: jal         0x800C8B84
    // 0x80800038: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800C8B84(rdram, ctx);
        goto after_1;
    // 0x80800038: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x8080003C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800040: sw          $zero, 0x164($a2)
    MEM_W(0X164, ctx->r6) = 0;
    // 0x80800044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800048:
    // 0x80800048: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080004C: jr          $ra
    // 0x80800050: nop

    return;
    // 0x80800050: nop

;}
RECOMP_FUNC void _bsdronevanish_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083188: syscall     48
    recomp_syscall_handler(rdram, ctx, 0x80083188);
    return;
    // 0x8008318C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void gcboundDll_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800554: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800558: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8080055C: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x80800560: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80800564: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80800568: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8080056C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80800570: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800574: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80800578: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x8080057C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80800580: jal         0x80801450
    // 0x80800584: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80801450_gcboundDll(rdram, ctx);
        goto after_0;
    // 0x80800584: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80800588: beq         $v0, $zero, L_808005C4
    if (ctx->r2 == 0) {
        // 0x8080058C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_808005C4;
    }
    // 0x8080058C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80800590:
    // 0x80800590: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800594: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800598: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8080059C: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x808005A0: jal         0x80801484
    // 0x808005A4: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    func_80801484_gcboundDll(rdram, ctx);
        goto after_1;
    // 0x808005A4: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_1:
    // 0x808005A8: bne         $v0, $zero, L_808005C4
    if (ctx->r2 != 0) {
        // 0x808005AC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808005C4;
    }
    // 0x808005AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808005B0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x808005B4: jal         0x80801450
    // 0x808005B8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_80801450_gcboundDll(rdram, ctx);
        goto after_2;
    // 0x808005B8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_2:
    // 0x808005BC: bne         $v0, $zero, L_80800590
    if (ctx->r2 != 0) {
        // 0x808005C0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80800590;
    }
    // 0x808005C0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_808005C4:
    // 0x808005C4: bne         $s0, $zero, L_808005DC
    if (ctx->r16 != 0) {
        // 0x808005C8: addiu       $a0, $s1, 0x10
        ctx->r4 = ADD32(ctx->r17, 0X10);
            goto L_808005DC;
    }
    // 0x808005C8: addiu       $a0, $s1, 0x10
    ctx->r4 = ADD32(ctx->r17, 0X10);
    // 0x808005CC: addiu       $a1, $s1, 0x14
    ctx->r5 = ADD32(ctx->r17, 0X14);
    // 0x808005D0: jal         0x80800280
    // 0x808005D4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_80800280_gcboundDll(rdram, ctx);
        goto after_3;
    // 0x808005D4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_3:
    // 0x808005D8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_808005DC:
    // 0x808005DC: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x808005E0: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x808005E4: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x808005E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808005EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808005F0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x808005F4: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x808005F8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x808005FC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80800600: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800604: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80800608: jal         0x808001A8
    // 0x8080060C: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    func_808001A8_gcboundDll(rdram, ctx);
        goto after_4;
    // 0x8080060C: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    after_4:
    // 0x80800610: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80800614: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80800618: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8080061C: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80800620: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80800624: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80800628: jr          $ra
    // 0x8080062C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8080062C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_800D58CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D58CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D58D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D58D4: jal         0x8001A2B0
    // 0x800D58D8: nop

    func_8001A2B0(rdram, ctx);
        goto after_0;
    // 0x800D58D8: nop

    after_0:
    // 0x800D58DC: jal         0x800D55DC
    // 0x800D58E0: nop

    func_800D55DC(rdram, ctx);
        goto after_1;
    // 0x800D58E0: nop

    after_1:
    // 0x800D58E4: jal         0x800D55DC
    // 0x800D58E8: nop

    func_800D55DC(rdram, ctx);
        goto after_2;
    // 0x800D58E8: nop

    after_2:
    // 0x800D58EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D58F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D58F4: jr          $ra
    // 0x800D58F8: nop

    return;
    // 0x800D58F8: nop

;}
RECOMP_FUNC void func_80801330_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801330: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80801334: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801338: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8080133C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801340: jal         0x80100094
    // 0x80801344: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801344: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801348: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8080134C: addu        $t6, $v0, $s0
    ctx->r14 = ADD32(ctx->r2, ctx->r16);
    // 0x80801350: lbu         $v1, 0xA($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0XA);
    // 0x80801354: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801358: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8080135C: beq         $v1, $at, L_80801378
    if (ctx->r3 == ctx->r1) {
        // 0x80801360: sll         $t8, $s0, 2
        ctx->r24 = S32(ctx->r16 << 2);
            goto L_80801378;
    }
    // 0x80801360: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x80801364: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801368: beq         $v1, $at, L_808013E0
    if (ctx->r3 == ctx->r1) {
        // 0x8080136C: nop
    
            goto L_808013E0;
    }
    // 0x8080136C: nop

    // 0x80801370: b           L_80801440
    // 0x80801374: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
        goto L_80801440;
    // 0x80801374: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
L_80801378:
    // 0x80801378: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8080137C: jal         0x80106790
    // 0x80801380: lw          $a0, 0x10($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X10);
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80801380: lw          $a0, 0x10($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X10);
    after_1:
    // 0x80801384: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80801388: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080138C: jal         0x80100094
    // 0x80801390: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80801390: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80801394: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80801398: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8080139C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013A0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x808013A4: jal         0x80089B18
    // 0x808013A8: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    _sukickball_entrypoint_16(rdram, ctx);
        goto after_3;
    // 0x808013A8: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_3:
    // 0x808013AC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808013B0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808013B4: jal         0x800EE7F8
    // 0x808013B8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x808013B8: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_4:
    // 0x808013BC: jal         0x80089B10
    // 0x808013C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sukickball_entrypoint_15(rdram, ctx);
        goto after_5;
    // 0x808013C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808013C4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808013C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808013CC: swc1        $f0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f0.u32l;
    // 0x808013D0: jal         0x808012E0
    // 0x808013D4: swc1        $f0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f0.u32l;
    func_808012E0_chstoneballcontrol(rdram, ctx);
        goto after_6;
    // 0x808013D4: swc1        $f0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f0.u32l;
    after_6:
    // 0x808013D8: b           L_80801440
    // 0x808013DC: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
        goto L_80801440;
    // 0x808013DC: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
L_808013E0:
    // 0x808013E0: jal         0x800EA05C
    // 0x808013E4: nop

    func_800EA05C(rdram, ctx);
        goto after_7;
    // 0x808013E4: nop

    after_7:
    // 0x808013E8: addiu       $at, $zero, 0xBB
    ctx->r1 = ADD32(0, 0XBB);
    // 0x808013EC: beq         $v0, $at, L_8080143C
    if (ctx->r2 == ctx->r1) {
        // 0x808013F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080143C;
    }
    // 0x808013F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013F4: jal         0x800F82D4
    // 0x808013F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800F82D4(rdram, ctx);
        goto after_8;
    // 0x808013F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x808013FC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801404: jal         0x80089B10
    // 0x80801408: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    _sukickball_entrypoint_15(rdram, ctx);
        goto after_9;
    // 0x80801408: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    after_9:
    // 0x8080140C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80801410: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80801414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801418: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8080141C: jal         0x800F832C
    // 0x80801420: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    func_800F832C(rdram, ctx);
        goto after_10;
    // 0x80801420: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    after_10:
    // 0x80801424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801428: jal         0x80089B18
    // 0x8080142C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    _sukickball_entrypoint_16(rdram, ctx);
        goto after_11;
    // 0x8080142C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_11:
    // 0x80801430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801434: jal         0x800F8294
    // 0x80801438: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800F8294(rdram, ctx);
        goto after_12;
    // 0x80801438: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_12:
L_8080143C:
    // 0x8080143C: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
L_80801440:
    // 0x80801440: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x80801444: sb          $zero, 0x34($t1)
    MEM_B(0X34, ctx->r9) = 0;
    // 0x80801448: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080144C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801450: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80801454: jr          $ra
    // 0x80801458: nop

    return;
    // 0x80801458: nop

;}
RECOMP_FUNC void bashoes_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800750: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800754: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800758: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080075C: jal         0x8009E69C
    // 0x80800760: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    func_8009E69C(rdram, ctx);
        goto after_0;
    // 0x80800760: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_0:
    // 0x80800764: jal         0x800F6B34
    // 0x80800768: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800F6B34(rdram, ctx);
        goto after_1;
    // 0x80800768: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8080076C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800770: bnel        $t6, $zero, L_8080078C
    if (ctx->r14 != 0) {
        // 0x80800774: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080078C;
    }
    goto skip_0;
    // 0x80800774: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800778: bne         $v0, $zero, L_80800788
    if (ctx->r2 != 0) {
        // 0x8080077C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800788;
    }
    // 0x8080077C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800780: jal         0x80800384
    // 0x80800784: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bashoes_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x80800784: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_80800788:
    // 0x80800788: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080078C:
    // 0x8080078C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800790: jr          $ra
    // 0x80800794: nop

    return;
    // 0x80800794: nop

;}
RECOMP_FUNC void func_800BCD78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BCD78: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800BCD7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BCD80: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800BCD84: lbu         $v0, 0x4($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X4);
    // 0x800BCD88: addu        $t7, $a0, $a1
    ctx->r15 = ADD32(ctx->r4, ctx->r5);
    // 0x800BCD8C: lbu         $t8, 0x8($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X8);
    // 0x800BCD90: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x800BCD94: subu        $a2, $v0, $a2
    ctx->r6 = SUB32(ctx->r2, ctx->r6);
    // 0x800BCD98: addu        $a2, $a2, $t8
    ctx->r6 = ADD32(ctx->r6, ctx->r24);
    // 0x800BCD9C: div         $zero, $a2, $v0
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r2)));
    // 0x800BCDA0: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x800BCDA4: bne         $v0, $zero, L_800BCDB0
    if (ctx->r2 != 0) {
        // 0x800BCDA8: nop
    
            goto L_800BCDB0;
    }
    // 0x800BCDA8: nop

    // 0x800BCDAC: break       7
    do_break(2148257196);
L_800BCDB0:
    // 0x800BCDB0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BCDB4: bne         $v0, $at, L_800BCDC8
    if (ctx->r2 != ctx->r1) {
        // 0x800BCDB8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BCDC8;
    }
    // 0x800BCDB8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BCDBC: bne         $a2, $at, L_800BCDC8
    if (ctx->r6 != ctx->r1) {
        // 0x800BCDC0: nop
    
            goto L_800BCDC8;
    }
    // 0x800BCDC0: nop

    // 0x800BCDC4: break       6
    do_break(2148257220);
L_800BCDC8:
    // 0x800BCDC8: mfhi        $a2
    ctx->r6 = hi;
    // 0x800BCDCC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800BCDD0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800BCDD4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800BCDD8: jal         0x800BCCC0
    // 0x800BCDDC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    static_16_800BCCC0(rdram, ctx);
        goto after_0;
    // 0x800BCDDC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x800BCDE0: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x800BCDE4: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800BCDE8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800BCDEC: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x800BCDF0: addu        $t1, $v0, $t9
    ctx->r9 = ADD32(ctx->r2, ctx->r25);
    // 0x800BCDF4: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
    // 0x800BCDF8: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x800BCDFC: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800BCE00: srl         $t2, $t0, 1
    ctx->r10 = S32(U32(ctx->r8) >> 1);
    // 0x800BCE04: bne         $a3, $zero, L_800BCE14
    if (ctx->r7 != 0) {
        // 0x800BCE08: or          $t0, $t2, $zero
        ctx->r8 = ctx->r10 | 0;
            goto L_800BCE14;
    }
    // 0x800BCE08: or          $t0, $t2, $zero
    ctx->r8 = ctx->r10 | 0;
    // 0x800BCE0C: b           L_800BCE70
    // 0x800BCE10: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
        goto L_800BCE70;
    // 0x800BCE10: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
L_800BCE14:
    // 0x800BCE14: lbu         $t4, 0x4($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X4);
    // 0x800BCE18: addiu       $t3, $a2, 0x1
    ctx->r11 = ADD32(ctx->r6, 0X1);
    // 0x800BCE1C: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800BCE20: div         $zero, $t3, $t4
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r12))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r12)));
    // 0x800BCE24: mfhi        $a1
    ctx->r5 = hi;
    // 0x800BCE28: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x800BCE2C: bne         $t4, $zero, L_800BCE38
    if (ctx->r12 != 0) {
        // 0x800BCE30: nop
    
            goto L_800BCE38;
    }
    // 0x800BCE30: nop

    // 0x800BCE34: break       7
    do_break(2148257332);
L_800BCE38:
    // 0x800BCE38: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BCE3C: bne         $t4, $at, L_800BCE50
    if (ctx->r12 != ctx->r1) {
        // 0x800BCE40: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BCE50;
    }
    // 0x800BCE40: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BCE44: bne         $t3, $at, L_800BCE50
    if (ctx->r11 != ctx->r1) {
        // 0x800BCE48: nop
    
            goto L_800BCE50;
    }
    // 0x800BCE48: nop

    // 0x800BCE4C: break       6
    do_break(2148257356);
L_800BCE50:
    // 0x800BCE50: jal         0x800BCCC0
    // 0x800BCE54: nop

    static_16_800BCCC0(rdram, ctx);
        goto after_1;
    // 0x800BCE54: nop

    after_1:
    // 0x800BCE58: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800BCE5C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800BCE60: addu        $t5, $v0, $v1
    ctx->r13 = ADD32(ctx->r2, ctx->r3);
    // 0x800BCE64: lw          $a1, 0x0($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X0);
    // 0x800BCE68: srl         $t6, $a1, 1
    ctx->r14 = S32(U32(ctx->r5) >> 1);
    // 0x800BCE6C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
L_800BCE70:
    // 0x800BCE70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BCE74: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800BCE78: subu        $v0, $a1, $t0
    ctx->r2 = SUB32(ctx->r5, ctx->r8);
    // 0x800BCE7C: jr          $ra
    // 0x800BCE80: nop

    return;
    // 0x800BCE80: nop

;}
RECOMP_FUNC void chcolldoors_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800264: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1844, 0X280) << 16);
    // 0x80800268: jr          $ra
    // 0x8080026C: addiu       $v0, $v0, 0x280
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1844, 0X280));
    return;
    // 0x8080026C: addiu       $v0, $v0, 0x280
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1844, 0X280));
;}
RECOMP_FUNC void _suegg_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A390: syscall     841
    recomp_syscall_handler(rdram, ctx, 0x8008A390);
    return;
    // 0x8008A394: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_8080030C_gcdialogcamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080030C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800310: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800314: jal         0x800F54E4
    // 0x80800318: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800318: nop

    after_0:
    // 0x8080031C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800320: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800324: jal         0x800F5A00
    // 0x80800328: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800F5A00(rdram, ctx);
        goto after_1;
    // 0x80800328: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_1:
    // 0x8080032C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800330: jal         0x800F5DC8
    // 0x80800334: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_800F5DC8(rdram, ctx);
        goto after_2;
    // 0x80800334: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_2:
    // 0x80800338: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8080033C: jal         0x800856F0
    // 0x80800340: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    _capod_entrypoint_10(rdram, ctx);
        goto after_3;
    // 0x80800340: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x80800344: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800348: jal         0x800856F8
    // 0x8080034C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    _capod_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x8080034C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_4:
    // 0x80800350: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800354: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800358: jr          $ra
    // 0x8080035C: nop

    return;
    // 0x8080035C: nop

;}
RECOMP_FUNC void func_80800108_chlagoonbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800108: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080010C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800110: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800114: jal         0x80089F48
    // 0x80800118: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _subaddiesect_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800118: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080011C: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x80800120: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    // 0x80800124: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800128: jal         0x80102FDC
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102FDC(rdram, ctx);
        goto after_1;
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800130: addiu       $a0, $zero, 0xD0
    ctx->r4 = ADD32(0, 0XD0);
    // 0x80800134: jal         0x800DA9E4
    // 0x80800138: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_2;
    // 0x80800138: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8080013C: bne         $v0, $zero, L_8080015C
    if (ctx->r2 != 0) {
        // 0x80800140: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8080015C;
    }
    // 0x80800140: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800144: jal         0x800DC128
    // 0x80800148: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800DC128(rdram, ctx);
        goto after_3;
    // 0x80800148: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
    // 0x8080014C: addiu       $a0, $zero, 0xD1
    ctx->r4 = ADD32(0, 0XD1);
    // 0x80800150: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800154: jal         0x800DA7A8
    // 0x80800158: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800DA7A8(rdram, ctx);
        goto after_4;
    // 0x80800158: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_4:
L_8080015C:
    // 0x8080015C: addiu       $a0, $zero, 0xD1
    ctx->r4 = ADD32(0, 0XD1);
    // 0x80800160: jal         0x800DA564
    // 0x80800164: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DA564(rdram, ctx);
        goto after_5;
    // 0x80800164: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x80800168: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
    // 0x8080016C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800170: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    // 0x80800174: srl         $t6, $a1, 7
    ctx->r14 = S32(U32(ctx->r5) >> 7);
    // 0x80800178: addiu       $a1, $t6, -0x32
    ctx->r5 = ADD32(ctx->r14, -0X32);
    // 0x8080017C: jal         0x800DA298
    // 0x80800180: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x80800180: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_6:
    // 0x80800184: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80800188: bne         $v0, $zero, L_80800198
    if (ctx->r2 != 0) {
        // 0x8080018C: lw          $a1, 0x28($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X28);
            goto L_80800198;
    }
    // 0x8080018C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800190: beq         $v1, $a1, L_808001D4
    if (ctx->r3 == ctx->r5) {
        // 0x80800194: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001D4;
    }
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800198:
    // 0x80800198: bne         $v1, $a1, L_808001C4
    if (ctx->r3 != ctx->r5) {
        // 0x8080019C: addiu       $a0, $zero, 0x14
        ctx->r4 = ADD32(0, 0X14);
            goto L_808001C4;
    }
    // 0x8080019C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x808001A0: jal         0x800D0B68
    // 0x808001A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800D0B68(rdram, ctx);
        goto after_7;
    // 0x808001A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x808001A8: bne         $v0, $zero, L_808001C4
    if (ctx->r2 != 0) {
        // 0x808001AC: addiu       $a0, $zero, 0x14
        ctx->r4 = ADD32(0, 0X14);
            goto L_808001C4;
    }
    // 0x808001AC: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x808001B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808001B4: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x808001B8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x808001BC: jal         0x800D1000
    // 0x808001C0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D1000(rdram, ctx);
        goto after_8;
    // 0x808001C0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_8:
L_808001C4:
    // 0x808001C4: jal         0x800FFAB0
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_9;
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808001CC: b           L_808001E4
    // 0x808001D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808001E4;
    // 0x808001D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001D4:
    // 0x808001D4: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    // 0x808001D8: jal         0x80089F50
    // 0x808001DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddiesect_entrypoint_2(rdram, ctx);
        goto after_10;
    // 0x808001DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_10:
    // 0x808001E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001E4:
    // 0x808001E4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808001E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808001EC: jr          $ra
    // 0x808001F0: nop

    return;
    // 0x808001F0: nop

;}
RECOMP_FUNC void func_8080061C_chvolcanobits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080061C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800620: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800624: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80800628: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x8080062C: bgezl       $t8, L_80800650
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800630: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800650;
    }
    goto skip_0;
    // 0x80800630: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800634: jal         0x800CF494
    // 0x80800638: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800CF494(rdram, ctx);
        goto after_0;
    // 0x80800638: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080063C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800640: lbu         $t9, 0x65($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X65);
    // 0x80800644: andi        $t0, $t9, 0xFFEF
    ctx->r8 = ctx->r25 & 0XFFEF;
    // 0x80800648: sb          $t0, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r8;
    // 0x8080064C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800650:
    // 0x80800650: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800654: jr          $ra
    // 0x80800658: nop

    return;
    // 0x80800658: nop

;}
RECOMP_FUNC void func_808006A8_chbanjoctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808006AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006B0: jal         0x800F54E4
    // 0x808006B4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x808006B4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808006B8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808006BC: jal         0x800F6DA0
    // 0x808006C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6DA0(rdram, ctx);
        goto after_1;
    // 0x808006C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808006C4: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x808006C8: beq         $t6, $zero, L_80800718
    if (ctx->r14 == 0) {
        // 0x808006CC: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80800718;
    }
    // 0x808006CC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x808006D0: jal         0x800F6E40
    // 0x808006D4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800F6E40(rdram, ctx);
        goto after_2;
    // 0x808006D4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x808006D8: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x808006DC: beq         $t7, $zero, L_80800718
    if (ctx->r15 == 0) {
        // 0x808006E0: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_80800718;
    }
    // 0x808006E0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x808006E4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808006E8: jal         0x800F64A4
    // 0x808006EC: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    func_800F64A4(rdram, ctx);
        goto after_3;
    // 0x808006EC: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    after_3:
    // 0x808006F0: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x808006F4: beq         $t8, $zero, L_80800718
    if (ctx->r24 == 0) {
        // 0x808006F8: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_80800718;
    }
    // 0x808006F8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x808006FC: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80800700: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800704: lw          $t9, 0x50($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X50);
    // 0x80800708: jalr        $t9
    // 0x8080070C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x8080070C: nop

    after_4:
    // 0x80800710: sltu        $t0, $zero, $v0
    ctx->r8 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800714: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_80800718:
    // 0x80800718: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080071C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800720: jr          $ra
    // 0x80800724: nop

    return;
    // 0x80800724: nop

;}
RECOMP_FUNC void func_80802F14_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802F14: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802F18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802F1C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80802F20: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80802F24: jal         0x80100094
    // 0x80802F28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802F28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802F2C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80802F30: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80802F34: jal         0x80106790
    // 0x80802F38: lw          $a0, 0x3C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X3C);
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80802F38: lw          $a0, 0x3C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X3C);
    after_1:
    // 0x80802F3C: lbu         $a1, 0x20($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X20);
    // 0x80802F40: addiu       $at, $zero, 0x7F
    ctx->r1 = ADD32(0, 0X7F);
    // 0x80802F44: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802F48: beql        $a1, $at, L_80802FAC
    if (ctx->r5 == ctx->r1) {
        // 0x80802F4C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802FAC;
    }
    goto skip_0;
    // 0x80802F4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80802F50: jal         0x80089AC8
    // 0x80802F54: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    _sukickball_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x80802F54: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x80802F58: beq         $v0, $zero, L_80802F88
    if (ctx->r2 == 0) {
        // 0x80802F5C: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_80802F88;
    }
    // 0x80802F5C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80802F60: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80802F64: lbu         $a0, 0x20($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X20);
    // 0x80802F68: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x80802F6C: jal         0x800F4F98
    // 0x80802F70: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800F4F98(rdram, ctx);
        goto after_3;
    // 0x80802F70: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_3:
    // 0x80802F74: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80802F78: jal         0x80089AF0
    // 0x80802F7C: lbu         $a1, 0x20($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X20);
    _sukickball_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x80802F7C: lbu         $a1, 0x20($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X20);
    after_4:
    // 0x80802F80: b           L_80802F98
    // 0x80802F84: addiu       $t8, $zero, 0x7F
    ctx->r24 = ADD32(0, 0X7F);
        goto L_80802F98;
    // 0x80802F84: addiu       $t8, $zero, 0x7F
    ctx->r24 = ADD32(0, 0X7F);
L_80802F88:
    // 0x80802F88: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80802F8C: jal         0x80089AF0
    // 0x80802F90: lbu         $a1, 0x20($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X20);
    _sukickball_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x80802F90: lbu         $a1, 0x20($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X20);
    after_5:
    // 0x80802F94: addiu       $t8, $zero, 0x7F
    ctx->r24 = ADD32(0, 0X7F);
L_80802F98:
    // 0x80802F98: sb          $t8, 0x20($s0)
    MEM_B(0X20, ctx->r16) = ctx->r24;
    // 0x80802F9C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4F50) << 16);
    // 0x80802FA0: lwc1        $f4, 0x4F50($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4F50));
    // 0x80802FA4: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x80802FA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802FAC:
    // 0x80802FAC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802FB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80802FB4: jr          $ra
    // 0x80802FB8: nop

    return;
    // 0x80802FB8: nop

;}
RECOMP_FUNC void func_80800300_bsmumstill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800300: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800304: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800308: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080030C: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x80800310: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800314: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800318: bne         $t6, $at, L_80800398
    if (ctx->r14 != ctx->r1) {
        // 0x8080031C: lui         $a1, 0x3E00
        ctx->r5 = S32(0X3E00 << 16);
            goto L_80800398;
    }
    // 0x8080031C: lui         $a1, 0x3E00
    ctx->r5 = S32(0X3E00 << 16);
    // 0x80800320: jal         0x8008CB10
    // 0x80800324: ori         $a1, $a1, 0xB780
    ctx->r5 = ctx->r5 | 0XB780;
    baanim_isAt(rdram, ctx);
        goto after_0;
    // 0x80800324: ori         $a1, $a1, 0xB780
    ctx->r5 = ctx->r5 | 0XB780;
    after_0:
    // 0x80800328: beq         $v0, $zero, L_80800340
    if (ctx->r2 == 0) {
        // 0x8080032C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800340;
    }
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800330: addiu       $a1, $zero, 0x3FF
    ctx->r5 = ADD32(0, 0X3FF);
    // 0x80800334: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800338: jal         0x8009DF18
    // 0x8080033C: addiu       $a3, $zero, 0x7D00
    ctx->r7 = ADD32(0, 0X7D00);
    func_8009DF18(rdram, ctx);
        goto after_1;
    // 0x8080033C: addiu       $a3, $zero, 0x7D00
    ctx->r7 = ADD32(0, 0X7D00);
    after_1:
L_80800340:
    // 0x80800340: lui         $a1, 0x3ECA
    ctx->r5 = S32(0X3ECA << 16);
    // 0x80800344: ori         $a1, $a1, 0x9931
    ctx->r5 = ctx->r5 | 0X9931;
    // 0x80800348: jal         0x8008CB10
    // 0x8080034C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_2;
    // 0x8080034C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800350: beq         $v0, $zero, L_8080036C
    if (ctx->r2 == 0) {
        // 0x80800354: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080036C;
    }
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800358: lui         $a2, 0x3F8C
    ctx->r6 = S32(0X3F8C << 16);
    // 0x8080035C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800360: addiu       $a1, $zero, 0x3FF
    ctx->r5 = ADD32(0, 0X3FF);
    // 0x80800364: jal         0x8009DF18
    // 0x80800368: addiu       $a3, $zero, 0x6D60
    ctx->r7 = ADD32(0, 0X6D60);
    func_8009DF18(rdram, ctx);
        goto after_3;
    // 0x80800368: addiu       $a3, $zero, 0x6D60
    ctx->r7 = ADD32(0, 0X6D60);
    after_3:
L_8080036C:
    // 0x8080036C: lui         $a1, 0x3F12
    ctx->r5 = S32(0X3F12 << 16);
    // 0x80800370: ori         $a1, $a1, 0x6E98
    ctx->r5 = ctx->r5 | 0X6E98;
    // 0x80800374: jal         0x8008CB10
    // 0x80800378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_4;
    // 0x80800378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080037C: beq         $v0, $zero, L_80800398
    if (ctx->r2 == 0) {
        // 0x80800380: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800398;
    }
    // 0x80800380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800384: lui         $a2, 0x3F99
    ctx->r6 = S32(0X3F99 << 16);
    // 0x80800388: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8080038C: addiu       $a1, $zero, 0x4BA
    ctx->r5 = ADD32(0, 0X4BA);
    // 0x80800390: jal         0x8009DF18
    // 0x80800394: addiu       $a3, $zero, 0x61A8
    ctx->r7 = ADD32(0, 0X61A8);
    func_8009DF18(rdram, ctx);
        goto after_5;
    // 0x80800394: addiu       $a3, $zero, 0x61A8
    ctx->r7 = ADD32(0, 0X61A8);
    after_5:
L_80800398:
    // 0x80800398: jal         0x8008CAEC
    // 0x8080039C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_6;
    // 0x8080039C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808003A0: beql        $v0, $zero, L_808003C0
    if (ctx->r2 == 0) {
        // 0x808003A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003C0;
    }
    goto skip_0;
    // 0x808003A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808003A8: jal         0x808000EC
    // 0x808003AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000EC_bsmumstill(rdram, ctx);
        goto after_7;
    // 0x808003AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808003B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003B4: jal         0x8080011C
    // 0x808003B8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8080011C_bsmumstill(rdram, ctx);
        goto after_8;
    // 0x808003B8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_8:
    // 0x808003BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808003C0:
    // 0x808003C0: jal         0x80800000
    // 0x808003C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800000_bsmumstill(rdram, ctx);
        goto after_9;
    // 0x808003C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x808003C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003CC: jal         0x8009E5C8
    // 0x808003D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_10;
    // 0x808003D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_10:
    // 0x808003D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003E0: jr          $ra
    // 0x808003E4: nop

    return;
    // 0x808003E4: nop

;}
RECOMP_FUNC void _chmrsicecube_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086320: syscall     307
    recomp_syscall_handler(rdram, ctx, 0x80086320);
    return;
    // 0x80086324: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800E7FCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E7FCC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E7FD0: addiu       $v0, $v0, -0x2A30
    ctx->r2 = ADD32(ctx->r2, -0X2A30);
    // 0x800E7FD4: lh          $t6, 0x8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X8);
    // 0x800E7FD8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800E7FDC: lh          $t7, 0xA($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XA);
    // 0x800E7FE0: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800E7FE4: lh          $t8, 0xC($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XC);
    // 0x800E7FE8: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x800E7FEC: lh          $t9, 0xE($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XE);
    // 0x800E7FF0: jr          $ra
    // 0x800E7FF4: sw          $t9, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r25;
    return;
    // 0x800E7FF4: sw          $t9, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void func_80096434(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096434: lw          $t6, 0x94($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X94);
    // 0x80096438: jr          $ra
    // 0x8009643C: lw          $v0, 0x74($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X74);
    return;
    // 0x8009643C: lw          $v0, 0x74($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X74);
;}
RECOMP_FUNC void susubgame_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800940: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80800944: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    // 0x80800948: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8080094C: swc1        $f6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f6.u32l;
    // 0x80800950: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80800954: swc1        $f8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f8.u32l;
    // 0x80800958: lwc1        $f10, 0xC($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8080095C: jr          $ra
    // 0x80800960: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
    return;
    // 0x80800960: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
    // 0x80800964: nop

    // 0x80800968: nop

    // 0x8080096C: nop

;}
RECOMP_FUNC void func_800D15CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D15CC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800D15D0: lw          $a0, -0x4DB0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4DB0);
    // 0x800D15D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D15D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D15DC: beql        $a0, $zero, L_800D15F8
    if (ctx->r4 == 0) {
        // 0x800D15E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D15F8;
    }
    goto skip_0;
    // 0x800D15E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D15E4: jal         0x8001BAFC
    // 0x800D15E8: nop

    defrag(rdram, ctx);
        goto after_0;
    // 0x800D15E8: nop

    after_0:
    // 0x800D15EC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D15F0: sw          $v0, -0x4DB0($at)
    MEM_W(-0X4DB0, ctx->r1) = ctx->r2;
    // 0x800D15F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D15F8:
    // 0x800D15F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D15FC: jr          $ra
    // 0x800D1600: nop

    return;
    // 0x800D1600: nop

;}
RECOMP_FUNC void func_800B2324(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2324: addiu       $v0, $a0, 0x18
    ctx->r2 = ADD32(ctx->r4, 0X18);
    // 0x800B2328: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800B232C: lhu         $t6, 0x16($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X16);
    // 0x800B2330: srl         $t7, $t6, 1
    ctx->r15 = S32(U32(ctx->r14) >> 1);
    // 0x800B2334: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x800B2338: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x800B233C: jr          $ra
    // 0x800B2340: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    return;
    // 0x800B2340: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
;}
RECOMP_FUNC void boot___osEPiRawReadIo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_800907EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800907EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800907F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800907F4: jal         0x800F54E4
    // 0x800907F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x800907F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800907FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80090800: jal         0x800F8730
    // 0x80090804: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800F8730(rdram, ctx);
        goto after_1;
    // 0x80090804: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80090808: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009080C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80090810: jr          $ra
    // 0x80090814: nop

    return;
    // 0x80090814: nop

;}
RECOMP_FUNC void func_80801F30_chfactoryempspell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801F30: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801F34: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801F38: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801F3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801F40: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80801F44: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80801F48: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80801F4C: jal         0x80086C68
    // 0x80801F50: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    _chmumbopad_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80801F50: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_0:
    // 0x80801F54: sll         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2 << 16);
    // 0x80801F58: sra         $t6, $a3, 16
    ctx->r14 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80801F5C: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x80801F60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801F64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801F68: jal         0x80089840
    // 0x80801F6C: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    _sumumbofx_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80801F6C: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_1:
    // 0x80801F70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801F74: jal         0x80100094
    // 0x80801F78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80801F78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80801F7C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80801F80: jal         0x80089850
    // 0x80801F84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80801F84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80801F88: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80801F8C: jal         0x80089900
    // 0x80801F90: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    _sumumbofx_entrypoint_24(rdram, ctx);
        goto after_4;
    // 0x80801F90: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_4:
    // 0x80801F94: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80801F98: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    // 0x80801F9C: jal         0x80089908
    // 0x80801FA0: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    _sumumbofx_entrypoint_25(rdram, ctx);
        goto after_5;
    // 0x80801FA0: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_5:
    // 0x80801FA4: jal         0x80801B2C
    // 0x80801FA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801B2C_chfactoryempspell(rdram, ctx);
        goto after_6;
    // 0x80801FA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80801FAC: jal         0x808016AC
    // 0x80801FB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808016AC_chfactoryempspell(rdram, ctx);
        goto after_7;
    // 0x80801FB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80801FB4: lui         $a3, 0x459C
    ctx->r7 = S32(0X459C << 16);
    // 0x80801FB8: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    // 0x80801FBC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80801FC0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801FC4: jal         0x80089920
    // 0x80801FC8: lui         $a2, 0x457A
    ctx->r6 = S32(0X457A << 16);
    _sumumbofx_entrypoint_28(rdram, ctx);
        goto after_8;
    // 0x80801FC8: lui         $a2, 0x457A
    ctx->r6 = S32(0X457A << 16);
    after_8:
    // 0x80801FCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801FD0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801FD4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80801FD8: jr          $ra
    // 0x80801FDC: nop

    return;
    // 0x80801FDC: nop

;}
RECOMP_FUNC void func_800E3958(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E3958: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E395C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800E3960: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E3964: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E3968: jal         0x800CA740
    // 0x800E396C: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    func_800CA740(rdram, ctx);
        goto after_0;
    // 0x800E396C: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    after_0:
    // 0x800E3970: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E3974: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E3978: jr          $ra
    // 0x800E397C: nop

    return;
    // 0x800E397C: nop

;}
RECOMP_FUNC void _bsbtrot_entrypoint_28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082CA0: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082CA0);
    return;
    // 0x80082CA4: addi        $t0, $zero, 0x70
    ctx->r8 = ADD32(0, 0X70);
;}
RECOMP_FUNC void chnewmumbo_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808016FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801700: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801704: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80801708: jal         0x80100094
    // 0x8080170C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080170C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801710: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80801714: jal         0x800EE7F8
    // 0x80801718: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80801718: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    after_1:
    // 0x8080171C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801720: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801724: jr          $ra
    // 0x80801728: nop

    return;
    // 0x80801728: nop

;}
RECOMP_FUNC void ncbabee_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800010: lui         $a1, 0x44FA
    ctx->r5 = S32(0X44FA << 16);
    // 0x80800014: lui         $a2, 0x457A
    ctx->r6 = S32(0X457A << 16);
    // 0x80800018: jal         0x801120CC
    // 0x8080001C: lui         $a3, 0xC57A
    ctx->r7 = S32(0XC57A << 16);
    func_801120CC(rdram, ctx);
        goto after_0;
    // 0x8080001C: lui         $a3, 0xC57A
    ctx->r7 = S32(0XC57A << 16);
    after_0:
    // 0x80800020: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800024: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    // 0x80800028: jal         0x80111B8C
    // 0x8080002C: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    func_80111B8C(rdram, ctx);
        goto after_1;
    // 0x8080002C: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    after_1:
    // 0x80800030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800034: jal         0x80115858
    // 0x80800038: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80115858(rdram, ctx);
        goto after_2;
    // 0x80800038: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8080003C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800040: jal         0x80115870
    // 0x80800044: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80115870(rdram, ctx);
        goto after_3;
    // 0x80800044: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x80800048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080004C: jal         0x801124D0
    // 0x80800050: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_801124D0(rdram, ctx);
        goto after_4;
    // 0x80800050: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800054: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800058: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080005C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800060: jr          $ra
    // 0x80800064: nop

    return;
    // 0x80800064: nop

;}
RECOMP_FUNC void func_80800104_chcrate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800104: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800108: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080010C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800110: jal         0x80101080
    // 0x80800114: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80101080(rdram, ctx);
        goto after_0;
    // 0x80800114: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800118: jal         0x80106790
    // 0x8080011C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x8080011C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800120: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80800124: jal         0x80800380
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800380_chcrate(rdram, ctx);
        goto after_2;
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080012C: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x80800130: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80800134: jal         0x800866B8
    // 0x80800138: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    _chexploder_entrypoint_12(rdram, ctx);
        goto after_3;
    // 0x80800138: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    after_3:
    // 0x8080013C: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1912, 0X508) << 16);
    // 0x80800140: addiu       $t6, $t6, 0x508
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1912, 0X508));
    // 0x80800144: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800148: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x8080014C: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80800150: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800154: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80800158: jal         0x800BBCB8
    // 0x8080015C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    func_800BBCB8(rdram, ctx);
        goto after_4;
    // 0x8080015C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_4:
    // 0x80800160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800164: jal         0x801096C8
    // 0x80800168: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_801096C8(rdram, ctx);
        goto after_5;
    // 0x80800168: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8080016C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1912, 0X4E8) << 16);
    // 0x80800170: addiu       $a2, $a2, 0x4E8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1912, 0X4E8));
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800178: jal         0x80089D18
    // 0x8080017C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x8080017C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_6:
    // 0x80800180: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1912, 0X4F8) << 16);
    // 0x80800184: addiu       $a2, $a2, 0x4F8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1912, 0X4F8));
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080018C: jal         0x80089D18
    // 0x80800190: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_7;
    // 0x80800190: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_7:
    // 0x80800194: lhu         $t7, 0x76($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X76);
    // 0x80800198: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8080019C: srl         $t8, $t7, 7
    ctx->r24 = S32(U32(ctx->r15) >> 7);
    // 0x808001A0: slti        $at, $t8, 0x33
    ctx->r1 = SIGNED(ctx->r24) < 0X33 ? 1 : 0;
    // 0x808001A4: bne         $at, $zero, L_80800224
    if (ctx->r1 != 0) {
        // 0x808001A8: nop
    
            goto L_80800224;
    }
    // 0x808001A8: nop

    // 0x808001AC: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x808001B0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x808001B4: addiu       $a0, $a0, 0x6FB0
    ctx->r4 = ADD32(ctx->r4, 0X6FB0);
    // 0x808001B8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808001BC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808001C0: nop

    // 0x808001C4: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x808001C8: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808001CC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808001D0: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x808001D4: nop

    // 0x808001D8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x808001DC: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x808001E0: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x808001E4: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x808001E8: nop

    // 0x808001EC: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x808001F0: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808001F4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808001F8: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x808001FC: nop

    // 0x80800200: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x80800204: lhu         $t7, 0x76($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X76);
    // 0x80800208: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080020C: srl         $t8, $t7, 7
    ctx->r24 = S32(U32(ctx->r15) >> 7);
    // 0x80800210: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x80800214: jal         0x80086D50
    // 0x80800218: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    _chbaddiesetup_entrypoint_5(rdram, ctx);
        goto after_8;
    // 0x80800218: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_8:
    // 0x8080021C: b           L_80800238
    // 0x80800220: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
        goto L_80800238;
    // 0x80800220: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
L_80800224:
    // 0x80800224: beql        $a0, $zero, L_80800238
    if (ctx->r4 == 0) {
        // 0x80800228: lw          $t1, 0x48($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X48);
            goto L_80800238;
    }
    goto skip_0;
    // 0x80800228: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    skip_0:
    // 0x8080022C: jal         0x800DA544
    // 0x80800230: nop

    func_800DA544(rdram, ctx);
        goto after_9;
    // 0x80800230: nop

    after_9:
    // 0x80800234: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
L_80800238:
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080023C: beq         $t1, $zero, L_80800254
    if (ctx->r9 == 0) {
        // 0x80800240: nop
    
            goto L_80800254;
    }
    // 0x80800240: nop

    // 0x80800244: jal         0x800FFAB0
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_10;
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8080024C: b           L_80800288
    // 0x80800250: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800288;
    // 0x80800250: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800254:
    // 0x80800254: jal         0x80101FDC
    // 0x80800258: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_11;
    // 0x80800258: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_11:
    // 0x8080025C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800260: jal         0x80103110
    // 0x80800264: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_12;
    // 0x80800264: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x80800268: jal         0x8010A570
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_13;
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800270: jal         0x8010A624
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A624(rdram, ctx);
        goto after_14;
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800278: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    // 0x8080027C: andi        $t3, $t2, 0xFFFE
    ctx->r11 = ctx->r10 & 0XFFFE;
    // 0x80800280: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
    // 0x80800284: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800288:
    // 0x80800288: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080028C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800290: jr          $ra
    // 0x80800294: nop

    return;
    // 0x80800294: nop

;}
RECOMP_FUNC void func_8080146C_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080146C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801470: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801474: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80801478: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8080147C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80801480: jal         0x80100094
    // 0x80801484: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801484: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801488: jal         0x800F54E4
    // 0x8080148C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x8080148C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_1:
    // 0x80801490: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801494: jal         0x800F5A00
    // 0x80801498: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800F5A00(rdram, ctx);
        goto after_2;
    // 0x80801498: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x8080149C: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
    // 0x808014A0: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x808014A4: beq         $at, $zero, L_808015F0
    if (ctx->r1 == 0) {
        // 0x808014A8: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_808015F0;
    }
    // 0x808014A8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808014AC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2204, 0X24D4) << 16);
    // 0x808014B0: addu        $at, $at, $t6
    gpr jr_addend_808014B8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808014B4: lw          $t6, 0x24D4($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2204, 0X24D4));
    // 0x808014B8: jr          $t6
    // 0x808014BC: nop

    switch (jr_addend_808014B8 >> 2) {
        case 0: goto L_808014C0; break;
        case 1: goto L_80801510; break;
        case 2: goto L_80801544; break;
        case 3: goto L_80801584; break;
        case 4: goto L_808015D8; break;
        default: switch_error(__func__, 0x808014B8, 0x808024D4);
    }
    // 0x808014BC: nop

L_808014C0:
    // 0x808014C0: lbu         $a0, 0xC($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XC);
    // 0x808014C4: jal         0x800C35E8
    // 0x808014C8: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    func_800C35E8(rdram, ctx);
        goto after_3;
    // 0x808014C8: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    after_3:
    // 0x808014CC: lbu         $a0, 0xC($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XC);
    // 0x808014D0: jal         0x800C301C
    // 0x808014D4: addiu       $a1, $zero, 0x414
    ctx->r5 = ADD32(0, 0X414);
    func_800C301C(rdram, ctx);
        goto after_4;
    // 0x808014D4: addiu       $a1, $zero, 0x414
    ctx->r5 = ADD32(0, 0X414);
    after_4:
    // 0x808014D8: lbu         $a0, 0xC($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XC);
    // 0x808014DC: jal         0x800C3058
    // 0x808014E0: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    func_800C3058(rdram, ctx);
        goto after_5;
    // 0x808014E0: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_5:
    // 0x808014E4: jal         0x800C3BDC
    // 0x808014E8: lbu         $a0, 0xC($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XC);
    func_800C3BDC(rdram, ctx);
        goto after_6;
    // 0x808014E8: lbu         $a0, 0xC($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XC);
    after_6:
    // 0x808014EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808014F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808014F4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808014F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808014FC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80801500: swc1        $f4, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f4.u32l;
    // 0x80801504: sw          $t7, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r15;
    // 0x80801508: b           L_808015F0
    // 0x8080150C: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
        goto L_808015F0;
    // 0x8080150C: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
L_80801510:
    // 0x80801510: jal         0x800D9078
    // 0x80801514: addiu       $a0, $s1, 0x58
    ctx->r4 = ADD32(ctx->r17, 0X58);
    func_800D9078(rdram, ctx);
        goto after_7;
    // 0x80801514: addiu       $a0, $s1, 0x58
    ctx->r4 = ADD32(ctx->r17, 0X58);
    after_7:
    // 0x80801518: beql        $v0, $zero, L_808015F4
    if (ctx->r2 == 0) {
        // 0x8080151C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808015F4;
    }
    goto skip_0;
    // 0x8080151C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80801520: jal         0x800C3CE8
    // 0x80801524: lbu         $a0, 0xC($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XC);
    func_800C3CE8(rdram, ctx);
        goto after_8;
    // 0x80801524: lbu         $a0, 0xC($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XC);
    after_8:
    // 0x80801528: addiu       $a0, $zero, 0x2BE
    ctx->r4 = ADD32(0, 0X2BE);
    // 0x8080152C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80801530: jal         0x80101180
    // 0x80801534: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_9;
    // 0x80801534: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x80801538: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8080153C: b           L_808015F0
    // 0x80801540: sw          $t8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r24;
        goto L_808015F0;
    // 0x80801540: sw          $t8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r24;
L_80801544:
    // 0x80801544: lui         $a1, 0x3F73
    ctx->r5 = S32(0X3F73 << 16);
    // 0x80801548: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x8080154C: jal         0x80800078
    // 0x80801550: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80800078_chtntmineshoot(rdram, ctx);
        goto after_10;
    // 0x80801550: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x80801554: jal         0x80800188
    // 0x80801558: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80800188_chtntmineshoot(rdram, ctx);
        goto after_11;
    // 0x80801558: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_11:
    // 0x8080155C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2204, 0X24E8) << 16);
    // 0x80801560: lwc1        $f12, 0x24E8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2204, 0X24E8));
    // 0x80801564: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801568: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080156C: jal         0x800DC178
    // 0x80801570: nop

    func_800DC178(rdram, ctx);
        goto after_12;
    // 0x80801570: nop

    after_12:
    // 0x80801574: swc1        $f0, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f0.u32l;
    // 0x80801578: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8080157C: b           L_808015F0
    // 0x80801580: sw          $t9, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r25;
        goto L_808015F0;
    // 0x80801580: sw          $t9, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r25;
L_80801584:
    // 0x80801584: jal         0x800D9078
    // 0x80801588: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    func_800D9078(rdram, ctx);
        goto after_13;
    // 0x80801588: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    after_13:
    // 0x8080158C: beq         $v0, $zero, L_808015C0
    if (ctx->r2 == 0) {
        // 0x80801590: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_808015C0;
    }
    // 0x80801590: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801594: lui         $a1, 0x3F73
    ctx->r5 = S32(0X3F73 << 16);
    // 0x80801598: jal         0x80800078
    // 0x8080159C: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    func_80800078_chtntmineshoot(rdram, ctx);
        goto after_14;
    // 0x8080159C: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    after_14:
    // 0x808015A0: jal         0x80800150
    // 0x808015A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800150_chtntmineshoot(rdram, ctx);
        goto after_15;
    // 0x808015A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x808015A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808015AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808015B0: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x808015B4: sw          $t0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r8;
    // 0x808015B8: b           L_808015F0
    // 0x808015BC: swc1        $f8, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f8.u32l;
        goto L_808015F0;
    // 0x808015BC: swc1        $f8, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f8.u32l;
L_808015C0:
    // 0x808015C0: jal         0x800D9078
    // 0x808015C4: addiu       $a0, $s1, 0x58
    ctx->r4 = ADD32(ctx->r17, 0X58);
    func_800D9078(rdram, ctx);
        goto after_16;
    // 0x808015C4: addiu       $a0, $s1, 0x58
    ctx->r4 = ADD32(ctx->r17, 0X58);
    after_16:
    // 0x808015C8: beq         $v0, $zero, L_808015F0
    if (ctx->r2 == 0) {
        // 0x808015CC: addiu       $t1, $zero, 0x2
        ctx->r9 = ADD32(0, 0X2);
            goto L_808015F0;
    }
    // 0x808015CC: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x808015D0: b           L_808015F0
    // 0x808015D4: sw          $t1, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r9;
        goto L_808015F0;
    // 0x808015D4: sw          $t1, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r9;
L_808015D8:
    // 0x808015D8: jal         0x800D9078
    // 0x808015DC: addiu       $a0, $s1, 0x58
    ctx->r4 = ADD32(ctx->r17, 0X58);
    func_800D9078(rdram, ctx);
        goto after_17;
    // 0x808015DC: addiu       $a0, $s1, 0x58
    ctx->r4 = ADD32(ctx->r17, 0X58);
    after_17:
    // 0x808015E0: beq         $v0, $zero, L_808015F0
    if (ctx->r2 == 0) {
        // 0x808015E4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808015F0;
    }
    // 0x808015E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808015E8: jal         0x80800E64
    // 0x808015EC: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80800E64_chtntmineshoot(rdram, ctx);
        goto after_18;
    // 0x808015EC: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_18:
L_808015F0:
    // 0x808015F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808015F4:
    // 0x808015F4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808015F8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808015FC: jr          $ra
    // 0x80801600: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80801600: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void _gldbstring_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088728: syscall     701
    recomp_syscall_handler(rdram, ctx, 0x80088728);
    return;
    // 0x8008872C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _chbadshad_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085778: syscall     173
    recomp_syscall_handler(rdram, ctx, 0x80085778);
    return;
    // 0x8008577C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800038_glgamestore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800038: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080003C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800040: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800044: jal         0x80800030
    // 0x80800048: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80800030_glgamestore(rdram, ctx);
        goto after_0;
    // 0x80800048: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x8080004C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800054: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800058: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8080005C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80800060: sll         $t7, $t7, 6
    ctx->r15 = S32(ctx->r15 << 6);
    // 0x80800064: jr          $ra
    // 0x80800068: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    return;
    // 0x80800068: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
;}
RECOMP_FUNC void func_800BA198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA198: beq         $a0, $zero, L_800BA1C8
    if (ctx->r4 == 0) {
        // 0x800BA19C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800BA1C8;
    }
    // 0x800BA19C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BA1A0: lw          $v1, 0x90($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X90);
    // 0x800BA1A4: beq         $v1, $zero, L_800BA1C8
    if (ctx->r3 == 0) {
        // 0x800BA1A8: nop
    
            goto L_800BA1C8;
    }
    // 0x800BA1A8: nop

    // 0x800BA1AC: lw          $t6, 0x8C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8C);
    // 0x800BA1B0: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x800BA1B4: subu        $v0, $v1, $t6
    ctx->r2 = SUB32(ctx->r3, ctx->r14);
    // 0x800BA1B8: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x800BA1BC: mflo        $v0
    ctx->r2 = lo;
    // 0x800BA1C0: jr          $ra
    // 0x800BA1C4: nop

    return;
    // 0x800BA1C4: nop

L_800BA1C8:
    // 0x800BA1C8: jr          $ra
    // 0x800BA1CC: nop

    return;
    // 0x800BA1CC: nop

;}
RECOMP_FUNC void _chcolldoors_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086EC8: syscall     468
    recomp_syscall_handler(rdram, ctx, 0x80086EC8);
    return;
    // 0x80086ECC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800100_chcrusherboulder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800100: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800104: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1640, 0X1388) << 16);
    // 0x80800108: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8080010C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800110: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80800114: addiu       $t6, $t6, 0x1388
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1640, 0X1388));
    // 0x80800118: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8080011C: addiu       $v0, $sp, 0x3C
    ctx->r2 = ADD32(ctx->r29, 0X3C);
    // 0x80800120: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(1640, 0X1394) << 16);
    // 0x80800124: sw          $at, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r1;
    // 0x80800128: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8080012C: addiu       $t0, $t0, 0x1394
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(1640, 0X1394));
    // 0x80800130: addiu       $v1, $sp, 0x30
    ctx->r3 = ADD32(ctx->r29, 0X30);
    // 0x80800134: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80800138: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x8080013C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800140: lui         $a1, 0x4361
    ctx->r5 = S32(0X4361 << 16);
    // 0x80800144: sw          $at, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r1;
    // 0x80800148: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x8080014C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800150: addiu       $a3, $zero, 0x19
    ctx->r7 = ADD32(0, 0X19);
    // 0x80800154: sw          $at, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r1;
    // 0x80800158: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x8080015C: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x80800160: lw          $at, 0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X8);
    // 0x80800164: sw          $at, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r1;
    // 0x80800168: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8080016C: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x80800170: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80800174: jal         0x80089878
    // 0x80800178: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    _sumumbofx_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x80800178: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_0:
    // 0x8080017C: jal         0x800898B0
    // 0x80800180: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    _sumumbofx_entrypoint_14(rdram, ctx);
        goto after_1;
    // 0x80800180: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_1:
    // 0x80800184: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80800188: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080018C: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800190: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800194: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800198: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x8080019C: jal         0x80089898
    // 0x808001A0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    _sumumbofx_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x808001A0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_2:
    // 0x808001A4: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x808001A8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808001AC: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x808001B0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x808001B4: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x808001B8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808001BC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808001C0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808001C4: jr          $ra
    // 0x808001C8: nop

    return;
    // 0x808001C8: nop

;}
RECOMP_FUNC void func_800D0018(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0018: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D001C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800D0020: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800D0024: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D0028: sltiu       $at, $a0, 0x7
    ctx->r1 = ctx->r4 < 0X7 ? 1 : 0;
    // 0x800D002C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800D0030: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800D0034: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D0038: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800D003C: beq         $at, $zero, L_800D02F4
    if (ctx->r1 == 0) {
        // 0x800D0040: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_800D02F4;
    }
    // 0x800D0040: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800D0044: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800D0048: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D004C: addu        $at, $at, $t6
    gpr jr_addend_800D0054 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800D0050: lw          $t6, 0x59F4($at)
    ctx->r14 = ADD32(ctx->r1, 0X59F4);
    // 0x800D0054: jr          $t6
    // 0x800D0058: nop

    switch (jr_addend_800D0054 >> 2) {
        case 0: goto L_800D005C; break;
        case 1: goto L_800D00C8; break;
        case 2: goto L_800D0130; break;
        case 3: goto L_800D0198; break;
        case 4: goto L_800D0200; break;
        case 5: goto L_800D02F4; break;
        case 6: goto L_800D0268; break;
        default: switch_error(__func__, 0x800D0054, 0x801259F4);
    }
    // 0x800D0058: nop

L_800D005C:
    // 0x800D005C: jal         0x800D0820
    // 0x800D0060: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D0820(rdram, ctx);
        goto after_0;
    // 0x800D0060: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x800D0064: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800D0068: jal         0x800D0894
    // 0x800D006C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D0894(rdram, ctx);
        goto after_1;
    // 0x800D006C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x800D0070: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800D0074: bne         $at, $zero, L_800D00C0
    if (ctx->r1 != 0) {
        // 0x800D0078: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800D00C0;
    }
    // 0x800D0078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800D007C:
    // 0x800D007C: jal         0x800D0B68
    // 0x800D0080: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800D0B68(rdram, ctx);
        goto after_2;
    // 0x800D0080: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x800D0084: beq         $v0, $zero, L_800D00AC
    if (ctx->r2 == 0) {
        // 0x800D0088: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800D00AC;
    }
    // 0x800D0088: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D008C: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x800D0090: subu        $t7, $t7, $s0
    ctx->r15 = SUB32(ctx->r15, ctx->r16);
    // 0x800D0094: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800D0098: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800D009C: lbu         $t8, -0x54C3($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X54C3);
    // 0x800D00A0: bne         $s3, $t8, L_800D00AC
    if (ctx->r19 != ctx->r24) {
        // 0x800D00A4: nop
    
            goto L_800D00AC;
    }
    // 0x800D00A4: nop

    // 0x800D00A8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800D00AC:
    // 0x800D00AC: jal         0x800D0894
    // 0x800D00B0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    func_800D0894(rdram, ctx);
        goto after_3;
    // 0x800D00B0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_3:
    // 0x800D00B4: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800D00B8: beql        $at, $zero, L_800D007C
    if (ctx->r1 == 0) {
        // 0x800D00BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800D007C;
    }
    goto skip_0;
    // 0x800D00BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
L_800D00C0:
    // 0x800D00C0: b           L_800D0340
    // 0x800D00C4: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
        goto L_800D0340;
    // 0x800D00C4: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_800D00C8:
    // 0x800D00C8: jal         0x800D0820
    // 0x800D00CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D0820(rdram, ctx);
        goto after_4;
    // 0x800D00CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x800D00D0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800D00D4: jal         0x800D0894
    // 0x800D00D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D0894(rdram, ctx);
        goto after_5;
    // 0x800D00D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x800D00DC: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800D00E0: bne         $at, $zero, L_800D0128
    if (ctx->r1 != 0) {
        // 0x800D00E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800D0128;
    }
    // 0x800D00E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800D00E8:
    // 0x800D00E8: jal         0x800D0B68
    // 0x800D00EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800D0B68(rdram, ctx);
        goto after_6;
    // 0x800D00EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x800D00F0: beq         $v0, $zero, L_800D0114
    if (ctx->r2 == 0) {
        // 0x800D00F4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800D0114;
    }
    // 0x800D00F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D00F8: sll         $t9, $s0, 1
    ctx->r25 = S32(ctx->r16 << 1);
    // 0x800D00FC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800D0100: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800D0104: lbu         $t0, -0x543A($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X543A);
    // 0x800D0108: bne         $s3, $t0, L_800D0114
    if (ctx->r19 != ctx->r8) {
        // 0x800D010C: nop
    
            goto L_800D0114;
    }
    // 0x800D010C: nop

    // 0x800D0110: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800D0114:
    // 0x800D0114: jal         0x800D0894
    // 0x800D0118: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    func_800D0894(rdram, ctx);
        goto after_7;
    // 0x800D0118: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_7:
    // 0x800D011C: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800D0120: beql        $at, $zero, L_800D00E8
    if (ctx->r1 == 0) {
        // 0x800D0124: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800D00E8;
    }
    goto skip_1;
    // 0x800D0124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
L_800D0128:
    // 0x800D0128: b           L_800D0340
    // 0x800D012C: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
        goto L_800D0340;
    // 0x800D012C: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_800D0130:
    // 0x800D0130: jal         0x800D0820
    // 0x800D0134: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D0820(rdram, ctx);
        goto after_8;
    // 0x800D0134: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x800D0138: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800D013C: jal         0x800D0894
    // 0x800D0140: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D0894(rdram, ctx);
        goto after_9;
    // 0x800D0140: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x800D0144: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800D0148: bne         $at, $zero, L_800D0190
    if (ctx->r1 != 0) {
        // 0x800D014C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800D0190;
    }
    // 0x800D014C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800D0150:
    // 0x800D0150: jal         0x800D0B68
    // 0x800D0154: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800D0B68(rdram, ctx);
        goto after_10;
    // 0x800D0154: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_10:
    // 0x800D0158: beq         $v0, $zero, L_800D017C
    if (ctx->r2 == 0) {
        // 0x800D015C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800D017C;
    }
    // 0x800D015C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D0160: sll         $t1, $s0, 1
    ctx->r9 = S32(ctx->r16 << 1);
    // 0x800D0164: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800D0168: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800D016C: lbu         $t2, -0x5386($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X5386);
    // 0x800D0170: bne         $s3, $t2, L_800D017C
    if (ctx->r19 != ctx->r10) {
        // 0x800D0174: nop
    
            goto L_800D017C;
    }
    // 0x800D0174: nop

    // 0x800D0178: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800D017C:
    // 0x800D017C: jal         0x800D0894
    // 0x800D0180: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    func_800D0894(rdram, ctx);
        goto after_11;
    // 0x800D0180: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_11:
    // 0x800D0184: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800D0188: beql        $at, $zero, L_800D0150
    if (ctx->r1 == 0) {
        // 0x800D018C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800D0150;
    }
    goto skip_2;
    // 0x800D018C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
L_800D0190:
    // 0x800D0190: b           L_800D0340
    // 0x800D0194: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
        goto L_800D0340;
    // 0x800D0194: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_800D0198:
    // 0x800D0198: jal         0x800D0820
    // 0x800D019C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D0820(rdram, ctx);
        goto after_12;
    // 0x800D019C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x800D01A0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800D01A4: jal         0x800D0894
    // 0x800D01A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D0894(rdram, ctx);
        goto after_13;
    // 0x800D01A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x800D01AC: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800D01B0: bne         $at, $zero, L_800D01F8
    if (ctx->r1 != 0) {
        // 0x800D01B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800D01F8;
    }
    // 0x800D01B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800D01B8:
    // 0x800D01B8: jal         0x800D0B68
    // 0x800D01BC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800D0B68(rdram, ctx);
        goto after_14;
    // 0x800D01BC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_14:
    // 0x800D01C0: beq         $v0, $zero, L_800D01E4
    if (ctx->r2 == 0) {
        // 0x800D01C4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800D01E4;
    }
    // 0x800D01C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D01C8: sll         $t3, $s0, 1
    ctx->r11 = S32(ctx->r16 << 1);
    // 0x800D01CC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800D01D0: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800D01D4: lbu         $t4, -0x5352($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X5352);
    // 0x800D01D8: bne         $s3, $t4, L_800D01E4
    if (ctx->r19 != ctx->r12) {
        // 0x800D01DC: nop
    
            goto L_800D01E4;
    }
    // 0x800D01DC: nop

    // 0x800D01E0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800D01E4:
    // 0x800D01E4: jal         0x800D0894
    // 0x800D01E8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    func_800D0894(rdram, ctx);
        goto after_15;
    // 0x800D01E8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_15:
    // 0x800D01EC: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800D01F0: beql        $at, $zero, L_800D01B8
    if (ctx->r1 == 0) {
        // 0x800D01F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800D01B8;
    }
    goto skip_3;
    // 0x800D01F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
L_800D01F8:
    // 0x800D01F8: b           L_800D0340
    // 0x800D01FC: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
        goto L_800D0340;
    // 0x800D01FC: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_800D0200:
    // 0x800D0200: jal         0x800D0820
    // 0x800D0204: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D0820(rdram, ctx);
        goto after_16;
    // 0x800D0204: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_16:
    // 0x800D0208: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800D020C: jal         0x800D0894
    // 0x800D0210: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D0894(rdram, ctx);
        goto after_17;
    // 0x800D0210: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_17:
    // 0x800D0214: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800D0218: bne         $at, $zero, L_800D0260
    if (ctx->r1 != 0) {
        // 0x800D021C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800D0260;
    }
    // 0x800D021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800D0220:
    // 0x800D0220: jal         0x800D0B68
    // 0x800D0224: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800D0B68(rdram, ctx);
        goto after_18;
    // 0x800D0224: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_18:
    // 0x800D0228: beq         $v0, $zero, L_800D024C
    if (ctx->r2 == 0) {
        // 0x800D022C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800D024C;
    }
    // 0x800D022C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D0230: sll         $t5, $s0, 1
    ctx->r13 = S32(ctx->r16 << 1);
    // 0x800D0234: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800D0238: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800D023C: lbu         $t6, -0x532E($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X532E);
    // 0x800D0240: bne         $s3, $t6, L_800D024C
    if (ctx->r19 != ctx->r14) {
        // 0x800D0244: nop
    
            goto L_800D024C;
    }
    // 0x800D0244: nop

    // 0x800D0248: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800D024C:
    // 0x800D024C: jal         0x800D0894
    // 0x800D0250: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    func_800D0894(rdram, ctx);
        goto after_19;
    // 0x800D0250: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_19:
    // 0x800D0254: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800D0258: beql        $at, $zero, L_800D0220
    if (ctx->r1 == 0) {
        // 0x800D025C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800D0220;
    }
    goto skip_4;
    // 0x800D025C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_4:
L_800D0260:
    // 0x800D0260: b           L_800D0340
    // 0x800D0264: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
        goto L_800D0340;
    // 0x800D0264: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_800D0268:
    // 0x800D0268: jal         0x800D0820
    // 0x800D026C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D0820(rdram, ctx);
        goto after_20;
    // 0x800D026C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_20:
    // 0x800D0270: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800D0274: jal         0x800D0894
    // 0x800D0278: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D0894(rdram, ctx);
        goto after_21;
    // 0x800D0278: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_21:
    // 0x800D027C: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800D0280: bne         $at, $zero, L_800D02EC
    if (ctx->r1 != 0) {
        // 0x800D0284: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800D02EC;
    }
    // 0x800D0284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800D0288:
    // 0x800D0288: jal         0x800D0B68
    // 0x800D028C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800D0B68(rdram, ctx);
        goto after_22;
    // 0x800D028C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_22:
    // 0x800D0290: beq         $v0, $zero, L_800D02D4
    if (ctx->r2 == 0) {
        // 0x800D0294: sll         $t7, $s0, 1
        ctx->r15 = S32(ctx->r16 << 1);
            goto L_800D02D4;
    }
    // 0x800D0294: sll         $t7, $s0, 1
    ctx->r15 = S32(ctx->r16 << 1);
    // 0x800D0298: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800D029C: addiu       $t8, $t8, -0x52F8
    ctx->r24 = ADD32(ctx->r24, -0X52F8);
    // 0x800D02A0: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800D02A4: lbu         $t9, -0x2($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X2);
    // 0x800D02A8: bnel        $s3, $t9, L_800D02D8
    if (ctx->r19 != ctx->r25) {
        // 0x800D02AC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800D02D8;
    }
    goto skip_5;
    // 0x800D02AC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_5:
    // 0x800D02B0: lbu         $t0, -0x1($v0)
    ctx->r8 = MEM_BU(ctx->r2, -0X1);
    // 0x800D02B4: addiu       $a0, $zero, 0x1D9
    ctx->r4 = ADD32(0, 0X1D9);
    // 0x800D02B8: beq         $t0, $zero, L_800D02C8
    if (ctx->r8 == 0) {
        // 0x800D02BC: nop
    
            goto L_800D02C8;
    }
    // 0x800D02BC: nop

    // 0x800D02C0: b           L_800D02C8
    // 0x800D02C4: addiu       $a0, $zero, 0x1DA
    ctx->r4 = ADD32(0, 0X1DA);
        goto L_800D02C8;
    // 0x800D02C4: addiu       $a0, $zero, 0x1DA
    ctx->r4 = ADD32(0, 0X1DA);
L_800D02C8:
    // 0x800D02C8: jal         0x80085AD8
    // 0x800D02CC: nop

    _chnests_entrypoint_13(rdram, ctx);
        goto after_23;
    // 0x800D02CC: nop

    after_23:
    // 0x800D02D0: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
L_800D02D4:
    // 0x800D02D4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800D02D8:
    // 0x800D02D8: jal         0x800D0894
    // 0x800D02DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D0894(rdram, ctx);
        goto after_24;
    // 0x800D02DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_24:
    // 0x800D02E0: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800D02E4: beql        $at, $zero, L_800D0288
    if (ctx->r1 == 0) {
        // 0x800D02E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800D0288;
    }
    goto skip_6;
    // 0x800D02E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_6:
L_800D02EC:
    // 0x800D02EC: b           L_800D0340
    // 0x800D02F0: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
        goto L_800D0340;
    // 0x800D02F0: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_800D02F4:
    // 0x800D02F4: jal         0x800D0820
    // 0x800D02F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D0820(rdram, ctx);
        goto after_25;
    // 0x800D02F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_25:
    // 0x800D02FC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800D0300: jal         0x800D0894
    // 0x800D0304: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D0894(rdram, ctx);
        goto after_26;
    // 0x800D0304: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_26:
    // 0x800D0308: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800D030C: bne         $at, $zero, L_800D033C
    if (ctx->r1 != 0) {
        // 0x800D0310: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800D033C;
    }
    // 0x800D0310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800D0314:
    // 0x800D0314: jal         0x800D0B68
    // 0x800D0318: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800D0B68(rdram, ctx);
        goto after_27;
    // 0x800D0318: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_27:
    // 0x800D031C: beq         $v0, $zero, L_800D0328
    if (ctx->r2 == 0) {
        // 0x800D0320: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800D0328;
    }
    // 0x800D0320: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800D0324: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800D0328:
    // 0x800D0328: jal         0x800D0894
    // 0x800D032C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D0894(rdram, ctx);
        goto after_28;
    // 0x800D032C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_28:
    // 0x800D0330: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800D0334: beql        $at, $zero, L_800D0314
    if (ctx->r1 == 0) {
        // 0x800D0338: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800D0314;
    }
    goto skip_7;
    // 0x800D0338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_7:
L_800D033C:
    // 0x800D033C: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_800D0340:
    // 0x800D0340: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800D0344: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D0348: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D034C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800D0350: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800D0354: jr          $ra
    // 0x800D0358: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800D0358: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _chmole_witchy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086BD8: syscall     427
    recomp_syscall_handler(rdram, ctx, 0x80086BD8);
    return;
    // 0x80086BDC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800E8CB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8CB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E8CB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800E8CB8: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x800E8CBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E8CC0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E8CC4: jal         0x800B301C
    // 0x800E8CC8: lw          $a0, -0x2980($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2980);
    freelist_at(rdram, ctx);
        goto after_0;
    // 0x800E8CC8: lw          $a0, -0x2980($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2980);
    after_0:
    // 0x800E8CCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E8CD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E8CD4: jr          $ra
    // 0x800E8CD8: nop

    return;
    // 0x800E8CD8: nop

;}
RECOMP_FUNC void chsabreman_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1232, 0X1DC0) << 16);
    // 0x80800028: jr          $ra
    // 0x8080002C: addiu       $v0, $v0, 0x1DC0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1232, 0X1DC0));
    return;
    // 0x8080002C: addiu       $v0, $v0, 0x1DC0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1232, 0X1DC0));
;}
RECOMP_FUNC void bskazfly_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080191C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801920: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(236, 0X1C98) << 16);
    // 0x80801924: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801928: jr          $ra
    // 0x8080192C: lw          $v0, 0x1C98($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(236, 0X1C98));
    return;
    // 0x8080192C: lw          $v0, 0x1C98($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(236, 0X1C98));
;}
RECOMP_FUNC void func_808007CC_bainvisible(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007D4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808007D8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x808007DC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x808007E0: jal         0x80800000
    // 0x808007E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80800000_bainvisible(rdram, ctx);
        goto after_0;
    // 0x808007E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808007E8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808007EC: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x808007F0: swc1        $f4, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->f4.u32l;
    // 0x808007F4: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808007F8: swc1        $f6, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f6.u32l;
    // 0x808007FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800800: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800804: jr          $ra
    // 0x80800808: nop

    return;
    // 0x80800808: nop

;}
RECOMP_FUNC void func_8080152C_chaliendad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080152C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80801530: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801534: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80801538: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080153C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80801540: jal         0x80100094
    // 0x80801544: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801544: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801548: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8080154C: jal         0x800D90A4
    // 0x80801550: addiu       $a0, $v0, 0x1C
    ctx->r4 = ADD32(ctx->r2, 0X1C);
    func_800D90A4(rdram, ctx);
        goto after_1;
    // 0x80801550: addiu       $a0, $v0, 0x1C
    ctx->r4 = ADD32(ctx->r2, 0X1C);
    after_1:
    // 0x80801554: addiu       $a0, $s1, 0x20
    ctx->r4 = ADD32(ctx->r17, 0X20);
    // 0x80801558: jal         0x800D90A4
    // 0x8080155C: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    func_800D90A4(rdram, ctx);
        goto after_2;
    // 0x8080155C: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_2:
    // 0x80801560: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80801564: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x80801568: lwc1        $f12, 0x1C($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8080156C: lui         $a2, 0x40C0
    ctx->r6 = S32(0X40C0 << 16);
    // 0x80801570: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80801574: jal         0x800F10B4
    // 0x80801578: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x80801578: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_3:
    // 0x8080157C: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x80801580: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80801584: lw          $a2, 0x24($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X24);
    // 0x80801588: lwc1        $f12, 0x20($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8080158C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80801590: jal         0x800F10B4
    // 0x80801594: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x80801594: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_4:
    // 0x80801598: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x8080159C: lw          $v1, 0x78($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X78);
    // 0x808015A0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808015A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808015A8: sll         $v0, $v1, 18
    ctx->r2 = S32(ctx->r3 << 18);
    // 0x808015AC: srl         $t6, $v0, 30
    ctx->r14 = S32(U32(ctx->r2) >> 30);
    // 0x808015B0: beq         $t6, $zero, L_808015DC
    if (ctx->r14 == 0) {
        // 0x808015B4: nop
    
            goto L_808015DC;
    }
    // 0x808015B4: nop

    // 0x808015B8: beq         $t6, $at, L_80801628
    if (ctx->r14 == ctx->r1) {
        // 0x808015BC: sll         $v0, $v1, 20
        ctx->r2 = S32(ctx->r3 << 20);
            goto L_80801628;
    }
    // 0x808015BC: sll         $v0, $v1, 20
    ctx->r2 = S32(ctx->r3 << 20);
    // 0x808015C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808015C4: beq         $t6, $at, L_808016A0
    if (ctx->r14 == ctx->r1) {
        // 0x808015C8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808016A0;
    }
    // 0x808015C8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808015CC: beq         $t6, $at, L_808016E8
    if (ctx->r14 == ctx->r1) {
        // 0x808015D0: lwc1        $f12, 0x50($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
            goto L_808016E8;
    }
    // 0x808015D0: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x808015D4: b           L_80801858
    // 0x808015D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801858;
    // 0x808015D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808015DC:
    // 0x808015DC: jal         0x800D90A4
    // 0x808015E0: nop

    func_800D90A4(rdram, ctx);
        goto after_5;
    // 0x808015E0: nop

    after_5:
    // 0x808015E4: beq         $v0, $zero, L_80801854
    if (ctx->r2 == 0) {
        // 0x808015E8: lui         $a2, 0x3F80
        ctx->r6 = S32(0X3F80 << 16);
            goto L_80801854;
    }
    // 0x808015E8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808015EC: lbu         $t7, 0x7A($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X7A);
    // 0x808015F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1364, 0X2588) << 16);
    // 0x808015F4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808015F8: andi        $t8, $t7, 0xFFCF
    ctx->r24 = ctx->r15 & 0XFFCF;
    // 0x808015FC: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x80801600: sb          $t9, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r25;
    // 0x80801604: lwc1        $f4, 0x2588($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1364, 0X2588));
    // 0x80801608: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x8080160C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80801610: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80801614: jal         0x800F10B4
    // 0x80801618: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_6;
    // 0x80801618: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x8080161C: swc1        $f0, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f0.u32l;
    // 0x80801620: b           L_80801854
    // 0x80801624: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
        goto L_80801854;
    // 0x80801624: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
L_80801628:
    // 0x80801628: srl         $t0, $v0, 29
    ctx->r8 = S32(U32(ctx->r2) >> 29);
    // 0x8080162C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801630: bne         $t0, $at, L_80801680
    if (ctx->r8 != ctx->r1) {
        // 0x80801634: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_80801680;
    }
    // 0x80801634: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80801638: jal         0x800D90A4
    // 0x8080163C: nop

    func_800D90A4(rdram, ctx);
        goto after_7;
    // 0x8080163C: nop

    after_7:
    // 0x80801640: beq         $v0, $zero, L_80801854
    if (ctx->r2 == 0) {
        // 0x80801644: lui         $a2, 0x3F80
        ctx->r6 = S32(0X3F80 << 16);
            goto L_80801854;
    }
    // 0x80801644: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801648: lbu         $t1, 0x7A($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X7A);
    // 0x8080164C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80801650: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1364, 0X258C) << 16);
    // 0x80801654: andi        $t2, $t1, 0xFFCF
    ctx->r10 = ctx->r9 & 0XFFCF;
    // 0x80801658: ori         $t3, $t2, 0x20
    ctx->r11 = ctx->r10 | 0X20;
    // 0x8080165C: sb          $t3, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r11;
    // 0x80801660: lwc1        $f6, 0x258C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1364, 0X258C));
    // 0x80801664: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80801668: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8080166C: jal         0x800F10B4
    // 0x80801670: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_8;
    // 0x80801670: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_8:
    // 0x80801674: swc1        $f0, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f0.u32l;
    // 0x80801678: b           L_80801854
    // 0x8080167C: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
        goto L_80801854;
    // 0x8080167C: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
L_80801680:
    // 0x80801680: lbu         $t7, 0x7A($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X7A);
    // 0x80801684: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x80801688: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8080168C: andi        $t6, $t5, 0xE
    ctx->r14 = ctx->r13 & 0XE;
    // 0x80801690: andi        $t8, $t7, 0xFFF1
    ctx->r24 = ctx->r15 & 0XFFF1;
    // 0x80801694: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80801698: b           L_80801854
    // 0x8080169C: sb          $t9, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r25;
        goto L_80801854;
    // 0x8080169C: sb          $t9, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r25;
L_808016A0:
    // 0x808016A0: jal         0x800D90A4
    // 0x808016A4: nop

    func_800D90A4(rdram, ctx);
        goto after_9;
    // 0x808016A4: nop

    after_9:
    // 0x808016A8: beq         $v0, $zero, L_80801854
    if (ctx->r2 == 0) {
        // 0x808016AC: lui         $a2, 0x3F80
        ctx->r6 = S32(0X3F80 << 16);
            goto L_80801854;
    }
    // 0x808016AC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808016B0: lbu         $t1, 0x7A($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X7A);
    // 0x808016B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1364, 0X2590) << 16);
    // 0x808016B8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808016BC: ori         $t2, $t1, 0x30
    ctx->r10 = ctx->r9 | 0X30;
    // 0x808016C0: sb          $t2, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r10;
    // 0x808016C4: lwc1        $f8, 0x2590($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1364, 0X2590));
    // 0x808016C8: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x808016CC: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808016D0: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x808016D4: jal         0x800F10B4
    // 0x808016D8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_10;
    // 0x808016D8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_10:
    // 0x808016DC: swc1        $f0, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f0.u32l;
    // 0x808016E0: b           L_80801854
    // 0x808016E4: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
        goto L_80801854;
    // 0x808016E4: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
L_808016E8:
    // 0x808016E8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808016EC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808016F0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808016F4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808016F8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x808016FC: jal         0x800F10B4
    // 0x80801700: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_11;
    // 0x80801700: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_11:
    // 0x80801704: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80801708: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8080170C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801710: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80801714: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x80801718: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8080171C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801720: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x80801724: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80801728: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x8080172C: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80801730: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80801734: jal         0x800F10B4
    // 0x80801738: nop

    func_800F10B4(rdram, ctx);
        goto after_12;
    // 0x80801738: nop

    after_12:
    // 0x8080173C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80801740: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80801744: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80801748: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x8080174C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80801750: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80801754: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80801758: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080175C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80801760: nop

    // 0x80801764: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80801768: beql        $t5, $zero, L_808017B8
    if (ctx->r13 == 0) {
        // 0x8080176C: mfc1        $t5, $f6
        ctx->r13 = (int32_t)ctx->f6.u32l;
            goto L_808017B8;
    }
    goto skip_0;
    // 0x8080176C: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x80801770: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801774: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80801778: sub.s       $f6, $f0, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8080177C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80801780: nop

    // 0x80801784: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80801788: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8080178C: nop

    // 0x80801790: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80801794: bne         $t5, $zero, L_808017AC
    if (ctx->r13 != 0) {
        // 0x80801798: nop
    
            goto L_808017AC;
    }
    // 0x80801798: nop

    // 0x8080179C: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x808017A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808017A4: b           L_808017C4
    // 0x808017A8: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_808017C4;
    // 0x808017A8: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_808017AC:
    // 0x808017AC: b           L_808017C4
    // 0x808017B0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_808017C4;
    // 0x808017B0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x808017B4: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
L_808017B8:
    // 0x808017B8: nop

    // 0x808017BC: bltz        $t5, L_808017AC
    if (SIGNED(ctx->r13) < 0) {
        // 0x808017C0: nop
    
            goto L_808017AC;
    }
    // 0x808017C0: nop

L_808017C4:
    // 0x808017C4: lbu         $t9, 0x7A($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X7A);
    // 0x808017C8: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x808017CC: andi        $t8, $t6, 0xE
    ctx->r24 = ctx->r14 & 0XE;
    // 0x808017D0: andi        $t0, $t9, 0xFFF1
    ctx->r8 = ctx->r25 & 0XFFF1;
    // 0x808017D4: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x808017D8: sb          $t1, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r9;
    // 0x808017DC: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x808017E0: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x808017E4: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x808017E8: beq         $t2, $zero, L_80801854
    if (ctx->r10 == 0) {
        // 0x808017EC: or          $t6, $t1, $zero
        ctx->r14 = ctx->r9 | 0;
            goto L_80801854;
    }
    // 0x808017EC: or          $t6, $t1, $zero
    ctx->r14 = ctx->r9 | 0;
    // 0x808017F0: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x808017F4: andi        $t7, $t5, 0xE
    ctx->r15 = ctx->r13 & 0XE;
    // 0x808017F8: andi        $t9, $t6, 0xF1
    ctx->r25 = ctx->r14 & 0XF1;
    // 0x808017FC: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x80801800: sb          $t0, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r8;
    // 0x80801804: andi        $t1, $t0, 0xCF
    ctx->r9 = ctx->r8 & 0XCF;
    // 0x80801808: sb          $t1, 0x7A($s0)
    MEM_B(0X7A, ctx->r16) = ctx->r9;
    // 0x8080180C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1364, 0X2594) << 16);
    // 0x80801810: lwc1        $f8, 0x2594($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1364, 0X2594));
    // 0x80801814: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80801818: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8080181C: jal         0x800F10B4
    // 0x80801820: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_13;
    // 0x80801820: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_13:
    // 0x80801824: swc1        $f0, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f0.u32l;
    // 0x80801828: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
    // 0x8080182C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801830: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801834: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80801838: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080183C: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x80801840: nop

    // 0x80801844: bc1fl       L_80801858
    if (!c1cs) {
        // 0x80801848: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80801858;
    }
    goto skip_1;
    // 0x80801848: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8080184C: jal         0x80801324
    // 0x80801850: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80801324_chaliendad(rdram, ctx);
        goto after_14;
    // 0x80801850: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_14:
L_80801854:
    // 0x80801854: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801858:
    // 0x80801858: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8080185C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80801860: jr          $ra
    // 0x80801864: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80801864: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void gcstatusDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800098: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8080009C: jr          $ra
    // 0x808000A0: sw          $a0, -0x4C00($at)
    MEM_W(-0X4C00, ctx->r1) = ctx->r4;
    return;
    // 0x808000A0: sw          $a0, -0x4C00($at)
    MEM_W(-0X4C00, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void _gcnewoption_entrypoint_32(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087D98: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087D98);
    return;
    // 0x80087D9C: addi        $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
;}
RECOMP_FUNC void func_8080158C_chalienkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080158C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801590: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801594: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801598: jal         0x80103EAC
    // 0x8080159C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80103EAC(rdram, ctx);
        goto after_0;
    // 0x8080159C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808015A0: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x808015A4: jal         0x8010A40C
    // 0x808015A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A40C(rdram, ctx);
        goto after_1;
    // 0x808015A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808015AC: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808015B0: lhu         $t6, 0x64($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X64);
    // 0x808015B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015B8: mul.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808015BC: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x808015C0: beql        $t7, $zero, L_80801618
    if (ctx->r15 == 0) {
        // 0x808015C4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801618;
    }
    goto skip_0;
    // 0x808015C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808015C8: jal         0x8010A698
    // 0x808015CC: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    func_8010A698(rdram, ctx);
        goto after_2;
    // 0x808015CC: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x808015D0: bne         $v0, $zero, L_80801614
    if (ctx->r2 != 0) {
        // 0x808015D4: lwc1        $f2, 0x28($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
            goto L_80801614;
    }
    // 0x808015D4: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808015D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015DC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808015E0: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x808015E4: jal         0x8008A0D0
    // 0x808015E8: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x808015E8: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    after_3:
    // 0x808015EC: beq         $v0, $zero, L_80801614
    if (ctx->r2 == 0) {
        // 0x808015F0: lwc1        $f2, 0x28($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
            goto L_80801614;
    }
    // 0x808015F0: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808015F4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808015F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808015FC: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80801600: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80801604: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80801608: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8080160C: jal         0x8008FB58
    // 0x80801610: nop

    func_8008FB58(rdram, ctx);
        goto after_4;
    // 0x80801610: nop

    after_4:
L_80801614:
    // 0x80801614: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801618:
    // 0x80801618: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080161C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80801620: jr          $ra
    // 0x80801624: nop

    return;
    // 0x80801624: nop

;}
RECOMP_FUNC void func_800BAAE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BAAE4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800BAAE8: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800BAAEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BAAF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BAAF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800BAAF8: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800BAAFC: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800BAB00: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800BAB04: jal         0x800EFA4C
    // 0x800BAB08: addiu       $a0, $a0, 0x6C
    ctx->r4 = ADD32(ctx->r4, 0X6C);
    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x800BAB08: addiu       $a0, $a0, 0x6C
    ctx->r4 = ADD32(ctx->r4, 0X6C);
    after_0:
    // 0x800BAB0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BAB10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BAB14: jr          $ra
    // 0x800BAB18: nop

    return;
    // 0x800BAB18: nop

;}
