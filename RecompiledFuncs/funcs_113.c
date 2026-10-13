#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void bsdronexform_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005CC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x808005D0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x808005D4: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x808005D8: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x808005DC: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x808005E0: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x808005E4: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x808005E8: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x808005EC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x808005F0: jal         0x800F53D0
    // 0x808005F4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800F53D0(rdram, ctx);
        goto after_0;
    // 0x808005F4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x808005F8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x808005FC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800600: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800604: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800608: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8080060C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800610: addiu       $s1, $sp, 0x4C
    ctx->r17 = ADD32(ctx->r29, 0X4C);
    // 0x80800614: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
L_80800618:
    // 0x80800618: mtc1        $s0, $f6
    ctx->f6.u32l = ctx->r16;
    // 0x8080061C: lw          $t6, 0x18C($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X18C);
    // 0x80800620: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x80800624: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800628: lwc1        $f4, 0x20($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X20);
    // 0x8080062C: div.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f22.fl);
    // 0x80800630: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80800634: jal         0x800F1074
    // 0x80800638: add.s       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f16.fl;
    func_800F1074(rdram, ctx);
        goto after_1;
    // 0x80800638: add.s       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f16.fl;
    after_1:
    // 0x8080063C: lw          $v0, 0x18C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X18C);
    // 0x80800640: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800644: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80800648: lwc1        $f2, 0x24($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8080064C: lwc1        $f18, 0x28($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80800650: mul.s       $f6, $f2, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x80800654: nop

    // 0x80800658: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8080065C: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x80800660: bne         $s0, $s3, L_80800618
    if (ctx->r16 != ctx->r19) {
        // 0x80800664: swc1        $f10, -0x4($s1)
        MEM_W(-0X4, ctx->r17) = ctx->f10.u32l;
            goto L_80800618;
    }
    // 0x80800664: swc1        $f10, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->f10.u32l;
    // 0x80800668: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8080066C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800670: jal         0x800DFF64
    // 0x80800674: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    func_800DFF64(rdram, ctx);
        goto after_2;
    // 0x80800674: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    after_2:
    // 0x80800678: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8080067C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800680: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80800684: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80800688: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8080068C: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80800690: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80800694: jr          $ra
    // 0x80800698: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80800698: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void chgameselect_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(804, 0X7FD8) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x7FD8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(804, 0X7FD8));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x7FD8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(804, 0X7FD8));
;}
RECOMP_FUNC void bsbflap_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080037C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800380: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800384: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800388: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080038C: jal         0x8008CABC
    // 0x80800390: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800390: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80800394: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800398: jal         0x800841D8
    // 0x8080039C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bswalk_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x8080039C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808003A0: lw          $t6, 0x15C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X15C);
    // 0x808003A4: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x808003A8: beq         $at, $zero, L_808005EC
    if (ctx->r1 == 0) {
        // 0x808003AC: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_808005EC;
    }
    // 0x808003AC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808003B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(90, 0X728) << 16);
    // 0x808003B4: addu        $at, $at, $t6
    gpr jr_addend_808003BC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808003B8: lw          $t6, 0x728($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(90, 0X728));
    // 0x808003BC: jr          $t6
    // 0x808003C0: nop

    switch (jr_addend_808003BC >> 2) {
        case 0: goto L_808003C4; break;
        case 1: goto L_80800474; break;
        case 2: goto L_808004C4; break;
        case 3: goto L_8080053C; break;
        case 4: goto L_808005D8; break;
        default: switch_error(__func__, 0x808003BC, 0x80800728);
    }
    // 0x808003C0: nop

L_808003C4:
    // 0x808003C4: jal         0x800956B8
    // 0x808003C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800956B8(rdram, ctx);
        goto after_2;
    // 0x808003C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808003CC: jal         0x80800210
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800210_bsbflap(rdram, ctx);
        goto after_3;
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808003D4: jal         0x80800294
    // 0x808003D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800294_bsbflap(rdram, ctx);
        goto after_4;
    // 0x808003D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808003DC: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x808003E0: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x808003E4: jal         0x8008B348
    // 0x808003E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_5;
    // 0x808003E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x808003EC: beq         $v0, $zero, L_808005EC
    if (ctx->r2 == 0) {
        // 0x808003F0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808005EC;
    }
    // 0x808003F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808003F4: jal         0x8008B1A0
    // 0x808003F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_6;
    // 0x808003F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x808003FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800400: jal         0x8008AED4
    // 0x80800404: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    anctrl_setIndex(rdram, ctx);
        goto after_7;
    // 0x80800404: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_7:
    // 0x80800408: jal         0x80800168
    // 0x8080040C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800168_bsbflap(rdram, ctx);
        goto after_8;
    // 0x8080040C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800410: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800414: jal         0x8008B1BC
    // 0x80800418: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_setDuration(rdram, ctx);
        goto after_9;
    // 0x80800418: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_9:
    // 0x8080041C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800420: jal         0x8008B134
    // 0x80800424: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_10;
    // 0x80800424: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_10:
    // 0x80800428: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080042C: jal         0x8008B24C
    // 0x80800430: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setStart(rdram, ctx);
        goto after_11;
    // 0x80800430: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_11:
    // 0x80800434: jal         0x8008B064
    // 0x80800438: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_start(rdram, ctx);
        goto after_12;
    // 0x80800438: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_12:
    // 0x8080043C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800440: jal         0x8009BA58
    // 0x80800444: lui         $a1, 0x438C
    ctx->r5 = S32(0X438C << 16);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_13;
    // 0x80800444: lui         $a1, 0x438C
    ctx->r5 = S32(0X438C << 16);
    after_13:
    // 0x80800448: lui         $a1, 0xC489
    ctx->r5 = S32(0XC489 << 16);
    // 0x8080044C: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x80800450: jal         0x8009BCB4
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_gravity(rdram, ctx);
        goto after_14;
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800458: lui         $a1, 0xC3C7
    ctx->r5 = S32(0XC3C7 << 16);
    // 0x8080045C: ori         $a1, $a1, 0xF333
    ctx->r5 = ctx->r5 | 0XF333;
    // 0x80800460: jal         0x8009BCC4
    // 0x80800464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_terminal_velocity(rdram, ctx);
        goto after_15;
    // 0x80800464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800468: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8080046C: b           L_808005EC
    // 0x80800470: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
        goto L_808005EC;
    // 0x80800470: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
L_80800474:
    // 0x80800474: jal         0x800956B8
    // 0x80800478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800956B8(rdram, ctx);
        goto after_16;
    // 0x80800478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x8080047C: jal         0x80800210
    // 0x80800480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800210_bsbflap(rdram, ctx);
        goto after_17;
    // 0x80800480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800484: jal         0x80800120
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800120_bsbflap(rdram, ctx);
        goto after_18;
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x8080048C: jal         0x808001D8
    // 0x80800490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001D8_bsbflap(rdram, ctx);
        goto after_19;
    // 0x80800490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800494: jal         0x80800294
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800294_bsbflap(rdram, ctx);
        goto after_20;
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x8080049C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(90, 0X73C) << 16);
    // 0x808004A0: lwc1        $f6, 0x73C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(90, 0X73C));
    // 0x808004A4: lwc1        $f4, 0x170($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X170);
    // 0x808004A8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x808004AC: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x808004B0: nop

    // 0x808004B4: bc1fl       L_808005F0
    if (!c1cs) {
        // 0x808004B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005F0;
    }
    goto skip_0;
    // 0x808004B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808004BC: b           L_808005EC
    // 0x808004C0: sw          $t8, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r24;
        goto L_808005EC;
    // 0x808004C0: sw          $t8, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r24;
L_808004C4:
    // 0x808004C4: jal         0x800956B8
    // 0x808004C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800956B8(rdram, ctx);
        goto after_21;
    // 0x808004C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x808004CC: jal         0x80800210
    // 0x808004D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800210_bsbflap(rdram, ctx);
        goto after_22;
    // 0x808004D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x808004D4: jal         0x80800120
    // 0x808004D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800120_bsbflap(rdram, ctx);
        goto after_23;
    // 0x808004D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x808004DC: jal         0x808001D8
    // 0x808004E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001D8_bsbflap(rdram, ctx);
        goto after_24;
    // 0x808004E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x808004E4: jal         0x80800294
    // 0x808004E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800294_bsbflap(rdram, ctx);
        goto after_25;
    // 0x808004E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x808004EC: lw          $t9, 0x160($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X160);
    // 0x808004F0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808004F4: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x808004F8: bne         $t9, $at, L_80800504
    if (ctx->r25 != ctx->r1) {
        // 0x808004FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800504;
    }
    // 0x808004FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800500: sw          $t0, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r8;
L_80800504:
    // 0x80800504: jal         0x80091A30
    // 0x80800508: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_released(rdram, ctx);
        goto after_26;
    // 0x80800508: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_26:
    // 0x8080050C: beql        $v0, $zero, L_808005F0
    if (ctx->r2 == 0) {
        // 0x80800510: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005F0;
    }
    goto skip_1;
    // 0x80800510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80800514: jal         0x8009BC6C
    // 0x80800518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_27;
    // 0x80800518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x8080051C: jal         0x8009BC90
    // 0x80800520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_terminal_velocity(rdram, ctx);
        goto after_28;
    // 0x80800520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x80800524: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800528: jal         0x8008B1BC
    // 0x8080052C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_29;
    // 0x8080052C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_29:
    // 0x80800530: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x80800534: b           L_808005EC
    // 0x80800538: sw          $t1, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r9;
        goto L_808005EC;
    // 0x80800538: sw          $t1, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r9;
L_8080053C:
    // 0x8080053C: jal         0x800956B8
    // 0x80800540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800956B8(rdram, ctx);
        goto after_30;
    // 0x80800540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x80800544: jal         0x80800210
    // 0x80800548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800210_bsbflap(rdram, ctx);
        goto after_31;
    // 0x80800548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x8080054C: jal         0x80800120
    // 0x80800550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800120_bsbflap(rdram, ctx);
        goto after_32;
    // 0x80800550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x80800554: jal         0x808001D8
    // 0x80800558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001D8_bsbflap(rdram, ctx);
        goto after_33;
    // 0x80800558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
    // 0x8080055C: jal         0x80800294
    // 0x80800560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800294_bsbflap(rdram, ctx);
        goto after_34;
    // 0x80800560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x80800564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800568: jal         0x80091A30
    // 0x8080056C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_released(rdram, ctx);
        goto after_35;
    // 0x8080056C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_35:
    // 0x80800570: beq         $v0, $zero, L_808005AC
    if (ctx->r2 == 0) {
        // 0x80800574: nop
    
            goto L_808005AC;
    }
    // 0x80800574: nop

    // 0x80800578: jal         0x8009BC6C
    // 0x8080057C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_36;
    // 0x8080057C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x80800580: jal         0x8009BC90
    // 0x80800584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_terminal_velocity(rdram, ctx);
        goto after_37;
    // 0x80800584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x80800588: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080058C: jal         0x8008B1BC
    // 0x80800590: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_38;
    // 0x80800590: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_38:
    // 0x80800594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800598: jal         0x80095588
    // 0x8080059C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80095588(rdram, ctx);
        goto after_39;
    // 0x8080059C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_39:
    // 0x808005A0: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x808005A4: b           L_808005EC
    // 0x808005A8: sw          $t2, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r10;
        goto L_808005EC;
    // 0x808005A8: sw          $t2, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r10;
L_808005AC:
    // 0x808005AC: jal         0x8009BB00
    // 0x808005B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_40;
    // 0x808005B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_40:
    // 0x808005B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(90, 0X740) << 16);
    // 0x808005B8: lwc1        $f8, 0x740($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(90, 0X740));
    // 0x808005BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005C0: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x808005C4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x808005C8: jal         0x8009B9B0
    // 0x808005CC: nop

    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_41;
    // 0x808005CC: nop

    after_41:
    // 0x808005D0: b           L_808005F0
    // 0x808005D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808005F0;
    // 0x808005D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808005D8:
    // 0x808005D8: jal         0x8008E260
    // 0x808005DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E260(rdram, ctx);
        goto after_42;
    // 0x808005DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
    // 0x808005E0: beq         $v0, $zero, L_808005EC
    if (ctx->r2 == 0) {
        // 0x808005E4: addiu       $t3, $zero, 0x3D
        ctx->r11 = ADD32(0, 0X3D);
            goto L_808005EC;
    }
    // 0x808005E4: addiu       $t3, $zero, 0x3D
    ctx->r11 = ADD32(0, 0X3D);
    // 0x808005E8: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
L_808005EC:
    // 0x808005EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808005F0:
    // 0x808005F0: jal         0x800852F0
    // 0x808005F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_43;
    // 0x808005F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_43:
    // 0x808005F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005FC: jal         0x80085330
    // 0x80800600: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_isZero(rdram, ctx);
        goto after_44;
    // 0x80800600: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_44:
    // 0x80800604: beq         $v0, $zero, L_80800610
    if (ctx->r2 == 0) {
        // 0x80800608: addiu       $t4, $zero, 0x2F
        ctx->r12 = ADD32(0, 0X2F);
            goto L_80800610;
    }
    // 0x80800608: addiu       $t4, $zero, 0x2F
    ctx->r12 = ADD32(0, 0X2F);
    // 0x8080060C: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
L_80800610:
    // 0x80800610: jal         0x80097A90
    // 0x80800614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_beak_bust(rdram, ctx);
        goto after_45;
    // 0x80800614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_45:
    // 0x80800618: beq         $v0, $zero, L_80800624
    if (ctx->r2 == 0) {
        // 0x8080061C: addiu       $t5, $zero, 0xF
        ctx->r13 = ADD32(0, 0XF);
            goto L_80800624;
    }
    // 0x8080061C: addiu       $t5, $zero, 0xF
    ctx->r13 = ADD32(0, 0XF);
    // 0x80800620: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
L_80800624:
    // 0x80800624: jal         0x8008DA24
    // 0x80800628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DA24(rdram, ctx);
        goto after_46;
    // 0x80800628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_46:
    // 0x8080062C: beq         $v0, $zero, L_80800638
    if (ctx->r2 == 0) {
        // 0x80800630: addiu       $t6, $zero, 0xA8
        ctx->r14 = ADD32(0, 0XA8);
            goto L_80800638;
    }
    // 0x80800630: addiu       $t6, $zero, 0xA8
    ctx->r14 = ADD32(0, 0XA8);
    // 0x80800634: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800638:
    // 0x80800638: jal         0x8008E078
    // 0x8080063C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_47;
    // 0x8080063C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_47:
    // 0x80800640: beq         $v0, $zero, L_80800658
    if (ctx->r2 == 0) {
        // 0x80800644: nop
    
            goto L_80800658;
    }
    // 0x80800644: nop

    // 0x80800648: jal         0x8009FE58
    // 0x8080064C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009FE58(rdram, ctx);
        goto after_48;
    // 0x8080064C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_48:
    // 0x80800650: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80800654: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80800658:
    // 0x80800658: jal         0x8008E35C
    // 0x8080065C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_49;
    // 0x8080065C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_49:
    // 0x80800660: beq         $v0, $zero, L_80800670
    if (ctx->r2 == 0) {
        // 0x80800664: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800670;
    }
    // 0x80800664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800668: addiu       $t8, $zero, 0x4C
    ctx->r24 = ADD32(0, 0X4C);
    // 0x8080066C: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_80800670:
    // 0x80800670: jal         0x8009E5C8
    // 0x80800674: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_50;
    // 0x80800674: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_50:
    // 0x80800678: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080067C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800680: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800684: jr          $ra
    // 0x80800688: nop

    return;
    // 0x80800688: nop

;}
RECOMP_FUNC void func_80800A14_chlakemonster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A14: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800A18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A1C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800A20: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x80800A24: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800A28: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x80800A2C: jal         0x80100094
    // 0x80800A30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800A30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800A34: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x80800A38: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x80800A3C: beql        $t6, $zero, L_80800A50
    if (ctx->r14 == 0) {
        // 0x80800A40: lw          $t7, 0x7C($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X7C);
            goto L_80800A50;
    }
    goto skip_0;
    // 0x80800A40: lw          $t7, 0x7C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X7C);
    skip_0:
    // 0x80800A44: jal         0x8080064C
    // 0x80800A48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080064C_chlakemonster(rdram, ctx);
        goto after_1;
    // 0x80800A48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800A4C: lw          $t7, 0x7C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X7C);
L_80800A50:
    // 0x80800A50: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(1748, 0X21B4) << 16);
    // 0x80800A54: addiu       $t1, $t1, 0x21B4
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(1748, 0X21B4));
    // 0x80800A58: sll         $t9, $t7, 19
    ctx->r25 = S32(ctx->r15 << 19);
    // 0x80800A5C: bgez        $t9, L_80800C74
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800A60: addiu       $t0, $sp, 0x48
        ctx->r8 = ADD32(ctx->r29, 0X48);
            goto L_80800C74;
    }
    // 0x80800A60: addiu       $t0, $sp, 0x48
    ctx->r8 = ADD32(ctx->r29, 0X48);
    // 0x80800A64: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x80800A68: lw          $t3, 0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X4);
    // 0x80800A6C: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(1748, 0X21C8) << 16);
    // 0x80800A70: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x80800A74: lw          $at, 0x8($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X8);
    // 0x80800A78: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
    // 0x80800A7C: lw          $t3, 0xC($t1)
    ctx->r11 = MEM_W(ctx->r9, 0XC);
    // 0x80800A80: sw          $at, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r1;
    // 0x80800A84: lw          $at, 0x10($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X10);
    // 0x80800A88: addiu       $t5, $t5, 0x21C8
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(1748, 0X21C8));
    // 0x80800A8C: sw          $t3, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r11;
    // 0x80800A90: sw          $at, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r1;
    // 0x80800A94: lw          $t7, 0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4);
    // 0x80800A98: lw          $at, 0x0($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X0);
    // 0x80800A9C: addiu       $t4, $sp, 0x40
    ctx->r12 = ADD32(ctx->r29, 0X40);
    // 0x80800AA0: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1748, 0X21D0) << 16);
    // 0x80800AA4: addiu       $t9, $t9, 0x21D0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(1748, 0X21D0));
    // 0x80800AA8: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x80800AAC: sw          $at, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r1;
    // 0x80800AB0: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x80800AB4: addiu       $t8, $sp, 0x2C
    ctx->r24 = ADD32(ctx->r29, 0X2C);
    // 0x80800AB8: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80800ABC: sw          $at, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r1;
    // 0x80800AC0: lw          $at, 0x8($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X8);
    // 0x80800AC4: sw          $t0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r8;
    // 0x80800AC8: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x80800ACC: sw          $at, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r1;
    // 0x80800AD0: lw          $at, 0x10($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X10);
    // 0x80800AD4: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(1748, 0X21E4) << 16);
    // 0x80800AD8: addiu       $t3, $t3, 0x21E4
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(1748, 0X21E4));
    // 0x80800ADC: sw          $t0, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r8;
    // 0x80800AE0: sw          $at, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r1;
    // 0x80800AE4: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x80800AE8: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x80800AEC: addiu       $t1, $sp, 0x24
    ctx->r9 = ADD32(ctx->r29, 0X24);
    // 0x80800AF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AF4: sw          $t4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r12;
    // 0x80800AF8: jal         0x80101F24
    // 0x80800AFC: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    func_80101F24(rdram, ctx);
        goto after_2;
    // 0x80800AFC: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    after_2:
    // 0x80800B00: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80800B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B08: jal         0x80101E4C
    // 0x80800B0C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_80101E4C(rdram, ctx);
        goto after_3;
    // 0x80800B0C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x80800B10: beq         $v0, $zero, L_80800B40
    if (ctx->r2 == 0) {
        // 0x80800B14: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B40;
    }
    // 0x80800B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B18: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1748, 0X2058) << 16);
    // 0x80800B1C: addiu       $a2, $a2, 0x2058
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1748, 0X2058));
    // 0x80800B20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B24: jal         0x80089D18
    // 0x80800B28: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x80800B28: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    after_4:
    // 0x80800B2C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1748, 0X1F60) << 16);
    // 0x80800B30: lwc1        $f4, 0x1F60($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1748, 0X1F60));
    // 0x80800B34: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x80800B38: b           L_80800C28
    // 0x80800B3C: swc1        $f4, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f4.u32l;
        goto L_80800C28;
    // 0x80800B3C: swc1        $f4, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f4.u32l;
L_80800B40:
    // 0x80800B40: jal         0x80101E4C
    // 0x80800B44: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_80101E4C(rdram, ctx);
        goto after_5;
    // 0x80800B44: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_5:
    // 0x80800B48: beq         $v0, $zero, L_80800B68
    if (ctx->r2 == 0) {
        // 0x80800B4C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B68;
    }
    // 0x80800B4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B50: jal         0x808008E8
    // 0x80800B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008E8_chlakemonster(rdram, ctx);
        goto after_6;
    // 0x80800B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800B58: jal         0x808001C0
    // 0x80800B5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001C0_chlakemonster(rdram, ctx);
        goto after_7;
    // 0x80800B5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800B60: b           L_80800C28
    // 0x80800B64: nop

        goto L_80800C28;
    // 0x80800B64: nop

L_80800B68:
    // 0x80800B68: jal         0x80101E4C
    // 0x80800B6C: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_80101E4C(rdram, ctx);
        goto after_8;
    // 0x80800B6C: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_8:
    // 0x80800B70: beq         $v0, $zero, L_80800B88
    if (ctx->r2 == 0) {
        // 0x80800B74: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B88;
    }
    // 0x80800B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B78: jal         0x80800968
    // 0x80800B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800968_chlakemonster(rdram, ctx);
        goto after_9;
    // 0x80800B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800B80: b           L_80800C28
    // 0x80800B84: nop

        goto L_80800C28;
    // 0x80800B84: nop

L_80800B88:
    // 0x80800B88: jal         0x80101E4C
    // 0x80800B8C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_80101E4C(rdram, ctx);
        goto after_10;
    // 0x80800B8C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_10:
    // 0x80800B90: bne         $v0, $zero, L_80800C28
    if (ctx->r2 != 0) {
        // 0x80800B94: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C28;
    }
    // 0x80800B94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B98: lui         $a1, 0x3F77
    ctx->r5 = S32(0X3F77 << 16);
    // 0x80800B9C: jal         0x80101E14
    // 0x80800BA0: ori         $a1, $a1, 0xA3D
    ctx->r5 = ctx->r5 | 0XA3D;
    func_80101E14(rdram, ctx);
        goto after_11;
    // 0x80800BA0: ori         $a1, $a1, 0xA3D
    ctx->r5 = ctx->r5 | 0XA3D;
    after_11:
    // 0x80800BA4: beq         $v0, $zero, L_80800C08
    if (ctx->r2 == 0) {
        // 0x80800BA8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C08;
    }
    // 0x80800BA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BAC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1748, 0X207C) << 16);
    // 0x80800BB0: addiu       $a2, $a2, 0x207C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1748, 0X207C));
    // 0x80800BB4: jal         0x80089D18
    // 0x80800BB8: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_12;
    // 0x80800BB8: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    after_12:
    // 0x80800BBC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800BC0: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80800BC4: jal         0x80018820
    // 0x80800BC8: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    func_80018820(rdram, ctx);
        goto after_13;
    // 0x80800BC8: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    after_13:
    // 0x80800BCC: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x80800BD0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80800BD4: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x80800BD8: beq         $t7, $zero, L_80800BF8
    if (ctx->r15 == 0) {
        // 0x80800BDC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800BF8;
    }
    // 0x80800BDC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800BE0: addiu       $a0, $zero, 0x501
    ctx->r4 = ADD32(0, 0X501);
    // 0x80800BE4: addiu       $a1, $zero, 0xBC
    ctx->r5 = ADD32(0, 0XBC);
    // 0x80800BE8: jal         0x80101180
    // 0x80800BEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_14;
    // 0x80800BEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_14:
    // 0x80800BF0: b           L_80800C28
    // 0x80800BF4: nop

        goto L_80800C28;
    // 0x80800BF4: nop

L_80800BF8:
    // 0x80800BF8: jal         0x8009086C
    // 0x80800BFC: sb          $t2, 0x3D($t8)
    MEM_B(0X3D, ctx->r24) = ctx->r10;
    func_8009086C(rdram, ctx);
        goto after_15;
    // 0x80800BFC: sb          $t2, 0x3D($t8)
    MEM_B(0X3D, ctx->r24) = ctx->r10;
    after_15:
    // 0x80800C00: b           L_80800C28
    // 0x80800C04: nop

        goto L_80800C28;
    // 0x80800C04: nop

L_80800C08:
    // 0x80800C08: jal         0x80101DDC
    // 0x80800C0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_16;
    // 0x80800C0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800C10: beq         $v0, $zero, L_80800C28
    if (ctx->r2 == 0) {
        // 0x80800C14: lw          $t9, 0x64($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X64);
            goto L_80800C28;
    }
    // 0x80800C14: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x80800C18: bne         $t9, $zero, L_80800C28
    if (ctx->r25 != 0) {
        // 0x80800C1C: nop
    
            goto L_80800C28;
    }
    // 0x80800C1C: nop

    // 0x80800C20: jal         0x808009CC
    // 0x80800C24: nop

    func_808009CC_chlakemonster(rdram, ctx);
        goto after_17;
    // 0x80800C24: nop

    after_17:
L_80800C28:
    // 0x80800C28: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1748, 0X1F64) << 16);
    // 0x80800C2C: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800C30: lwc1        $f6, 0x1F64($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1748, 0X1F64));
    // 0x80800C34: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1748, 0X1F68) << 16);
    // 0x80800C38: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80800C3C: nop

    // 0x80800C40: bc1fl       L_80800C78
    if (!c1cs) {
        // 0x80800C44: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800C78;
    }
    goto skip_1;
    // 0x80800C44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800C48: lwc1        $f8, 0x1F68($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1748, 0X1F68));
    // 0x80800C4C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80800C50: nop

    // 0x80800C54: bc1fl       L_80800C78
    if (!c1cs) {
        // 0x80800C58: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800C78;
    }
    goto skip_2;
    // 0x80800C58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80800C5C: jal         0x8001210C
    // 0x80800C60: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_8001210C(rdram, ctx);
        goto after_18;
    // 0x80800C60: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_18:
    // 0x80800C64: beql        $v0, $zero, L_80800C78
    if (ctx->r2 == 0) {
        // 0x80800C68: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800C78;
    }
    goto skip_3;
    // 0x80800C68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80800C6C: jal         0x808001C0
    // 0x80800C70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001C0_chlakemonster(rdram, ctx);
        goto after_19;
    // 0x80800C70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
L_80800C74:
    // 0x80800C74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800C78:
    // 0x80800C78: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800C7C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80800C80: jr          $ra
    // 0x80800C84: nop

    return;
    // 0x80800C84: nop

;}
RECOMP_FUNC void func_8010413C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010413C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80104140: jr          $ra
    // 0x80104144: addiu       $v0, $v0, 0x6D10
    ctx->r2 = ADD32(ctx->r2, 0X6D10);
    return;
    // 0x80104144: addiu       $v0, $v0, 0x6D10
    ctx->r2 = ADD32(ctx->r2, 0X6D10);
;}
RECOMP_FUNC void func_800AD2C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD2C8: addiu       $sp, $sp, -0x128
    ctx->r29 = ADD32(ctx->r29, -0X128);
    // 0x800AD2CC: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800AD2D0: sw          $a0, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r4;
    // 0x800AD2D4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800AD2D8: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x800AD2DC: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x800AD2E0: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x800AD2E4: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x800AD2E8: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x800AD2EC: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x800AD2F0: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x800AD2F4: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800AD2F8: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800AD2FC: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x800AD300: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800AD304: sw          $zero, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = 0;
    // 0x800AD308: addiu       $a0, $sp, 0xEC
    ctx->r4 = ADD32(ctx->r29, 0XEC);
    // 0x800AD30C: addiu       $t1, $sp, 0xF8
    ctx->r9 = ADD32(ctx->r29, 0XF8);
    // 0x800AD310: lw          $v0, 0x138($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X138);
    // 0x800AD314: addiu       $t3, $sp, 0xEC
    ctx->r11 = ADD32(ctx->r29, 0XEC);
    // 0x800AD318: addiu       $v1, $sp, 0xE0
    ctx->r3 = ADD32(ctx->r29, 0XE0);
    // 0x800AD31C: or          $t2, $a2, $zero
    ctx->r10 = ctx->r6 | 0;
    // 0x800AD320: or          $t4, $a3, $zero
    ctx->r12 = ctx->r7 | 0;
L_800AD324:
    // 0x800AD324: lwc1        $f4, 0x0($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X0);
    // 0x800AD328: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800AD32C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800AD330: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x800AD334: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800AD338: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x800AD33C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800AD340: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // 0x800AD344: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800AD348: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    // 0x800AD34C: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800AD350: nop

    // 0x800AD354: sw          $t7, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r15;
    // 0x800AD358: lwc1        $f18, -0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, -0X4);
    // 0x800AD35C: lwc1        $f16, -0x4($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, -0X4);
    // 0x800AD360: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800AD364: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800AD368: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800AD36C: nop

    // 0x800AD370: sw          $t9, -0x4($t3)
    MEM_W(-0X4, ctx->r11) = ctx->r25;
    // 0x800AD374: lwc1        $f8, -0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, -0X4);
    // 0x800AD378: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800AD37C: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x800AD380: bne         $v1, $a0, L_800AD324
    if (ctx->r3 != ctx->r4) {
        // 0x800AD384: sw          $t6, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->r14;
            goto L_800AD324;
    }
    // 0x800AD384: sw          $t6, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r14;
    // 0x800AD388: addiu       $t7, $sp, 0x114
    ctx->r15 = ADD32(ctx->r29, 0X114);
    // 0x800AD38C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800AD390: lw          $a0, 0x128($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X128);
    // 0x800AD394: addiu       $a1, $sp, 0xF8
    ctx->r5 = ADD32(ctx->r29, 0XF8);
    // 0x800AD398: addiu       $a2, $sp, 0xEC
    ctx->r6 = ADD32(ctx->r29, 0XEC);
    // 0x800AD39C: jal         0x800AA7FC
    // 0x800AD3A0: addiu       $a3, $sp, 0x118
    ctx->r7 = ADD32(ctx->r29, 0X118);
    func_800AA7FC(rdram, ctx);
        goto after_0;
    // 0x800AD3A0: addiu       $a3, $sp, 0x118
    ctx->r7 = ADD32(ctx->r29, 0X118);
    after_0:
    // 0x800AD3A4: jal         0x800B2190
    // 0x800AD3A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800B2190(rdram, ctx);
        goto after_1;
    // 0x800AD3A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800AD3AC: lw          $v1, 0x118($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X118);
    // 0x800AD3B0: lw          $t8, 0x114($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X114);
    // 0x800AD3B4: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x800AD3B8: addiu       $s5, $s5, 0x7990
    ctx->r21 = ADD32(ctx->r21, 0X7990);
    // 0x800AD3BC: sltu        $at, $v1, $t8
    ctx->r1 = ctx->r3 < ctx->r24 ? 1 : 0;
    // 0x800AD3C0: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x800AD3C4: sw          $s5, 0x500($s5)
    MEM_W(0X500, ctx->r21) = ctx->r21;
    // 0x800AD3C8: beq         $at, $zero, L_800AD858
    if (ctx->r1 == 0) {
        // 0x800AD3CC: sw          $v1, 0x110($sp)
        MEM_W(0X110, ctx->r29) = ctx->r3;
            goto L_800AD858;
    }
    // 0x800AD3CC: sw          $v1, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r3;
    // 0x800AD3D0: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x800AD3D4: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800AD3D8: addiu       $fp, $fp, 0x7991
    ctx->r30 = ADD32(ctx->r30, 0X7991);
    // 0x800AD3DC: lwc1        $f20, 0x144($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X144);
    // 0x800AD3E0: addiu       $s7, $sp, 0xC8
    ctx->r23 = ADD32(ctx->r29, 0XC8);
    // 0x800AD3E4: addiu       $s4, $sp, 0xEC
    ctx->r20 = ADD32(ctx->r29, 0XEC);
    // 0x800AD3E8: addiu       $s3, $sp, 0xD4
    ctx->r19 = ADD32(ctx->r29, 0XD4);
    // 0x800AD3EC: lw          $s2, 0x13C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X13C);
    // 0x800AD3F0: lw          $a2, 0x11C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X11C);
    // 0x800AD3F4: lw          $a1, 0x140($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X140);
L_800AD3F8:
    // 0x800AD3F8: lw          $t9, 0x110($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X110);
    // 0x800AD3FC: lw          $t7, 0x128($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X128);
    // 0x800AD400: slt         $at, $a2, $a1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800AD404: lw          $v1, 0x0($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X0);
    // 0x800AD408: lhu         $t9, 0x10($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X10);
    // 0x800AD40C: lhu         $t5, 0x0($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X0);
    // 0x800AD410: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800AD414: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x800AD418: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800AD41C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800AD420: lhu         $t6, 0x2($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2);
    // 0x800AD424: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x800AD428: addu        $a0, $t8, $t5
    ctx->r4 = ADD32(ctx->r24, ctx->r13);
    // 0x800AD42C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800AD430: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800AD434: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    // 0x800AD438: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800AD43C: addu        $t9, $t7, $a0
    ctx->r25 = ADD32(ctx->r15, ctx->r4);
    // 0x800AD440: sw          $t9, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r25;
    // 0x800AD444: beq         $at, $zero, L_800AD840
    if (ctx->r1 == 0) {
        // 0x800AD448: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_800AD840;
    }
    // 0x800AD448: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800AD44C: sltu        $at, $a0, $t9
    ctx->r1 = ctx->r4 < ctx->r25 ? 1 : 0;
    // 0x800AD450: beql        $at, $zero, L_800AD844
    if (ctx->r1 == 0) {
        // 0x800AD454: lw          $t8, 0x110($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X110);
            goto L_800AD844;
    }
    goto skip_0;
    // 0x800AD454: lw          $t8, 0x110($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X110);
    skip_0:
    // 0x800AD458: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
L_800AD45C:
    // 0x800AD45C: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x800AD460: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x800AD464: and         $t5, $t8, $at
    ctx->r13 = ctx->r24 & ctx->r1;
    // 0x800AD468: bnel        $t5, $zero, L_800AD828
    if (ctx->r13 != 0) {
        // 0x800AD46C: slt         $at, $a2, $a1
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_800AD828;
    }
    goto skip_1;
    // 0x800AD46C: slt         $at, $a2, $a1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
    skip_1:
    // 0x800AD470: sw          $v0, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r2;
    // 0x800AD474: lhu         $t7, 0x0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X0);
    // 0x800AD478: addiu       $a0, $sp, 0xA4
    ctx->r4 = ADD32(ctx->r29, 0XA4);
    // 0x800AD47C: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x800AD480: addu        $a1, $t9, $s6
    ctx->r5 = ADD32(ctx->r25, ctx->r22);
    // 0x800AD484: lh          $v0, 0x0($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X0);
    // 0x800AD488: sw          $v0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r2;
    // 0x800AD48C: sw          $v0, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r2;
    // 0x800AD490: lh          $v0, 0x2($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X2);
    // 0x800AD494: sw          $v0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r2;
    // 0x800AD498: sw          $v0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r2;
    // 0x800AD49C: lh          $v0, 0x4($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X4);
    // 0x800AD4A0: sw          $v0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r2;
    // 0x800AD4A4: jal         0x800EE8CC
    // 0x800AD4A8: sw          $v0, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r2;
    func_800EE8CC(rdram, ctx);
        goto after_2;
    // 0x800AD4A8: sw          $v0, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r2;
    after_2:
    // 0x800AD4AC: lw          $s1, 0x104($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X104);
    // 0x800AD4B0: addiu       $s0, $sp, 0xB0
    ctx->r16 = ADD32(ctx->r29, 0XB0);
    // 0x800AD4B4: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
L_800AD4B8:
    // 0x800AD4B8: lhu         $t8, 0x0($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X0);
    // 0x800AD4BC: addiu       $a1, $sp, 0xD4
    ctx->r5 = ADD32(ctx->r29, 0XD4);
    // 0x800AD4C0: addiu       $v1, $sp, 0xC8
    ctx->r3 = ADD32(ctx->r29, 0XC8);
    // 0x800AD4C4: sll         $t5, $t8, 4
    ctx->r13 = S32(ctx->r24 << 4);
    // 0x800AD4C8: addu        $a2, $t5, $s6
    ctx->r6 = ADD32(ctx->r13, ctx->r22);
    // 0x800AD4CC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_800AD4D0:
    // 0x800AD4D0: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x800AD4D4: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800AD4D8: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800AD4DC: beql        $at, $zero, L_800AD4F0
    if (ctx->r1 == 0) {
        // 0x800AD4E0: lw          $t7, 0x0($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X0);
            goto L_800AD4F0;
    }
    goto skip_2;
    // 0x800AD4E0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    skip_2:
    // 0x800AD4E4: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800AD4E8: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x800AD4EC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
L_800AD4F0:
    // 0x800AD4F0: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800AD4F4: slt         $at, $t7, $v0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800AD4F8: beql        $at, $zero, L_800AD508
    if (ctx->r1 == 0) {
        // 0x800AD4FC: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800AD508;
    }
    goto skip_3;
    // 0x800AD4FC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_3:
    // 0x800AD500: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800AD504: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_800AD508:
    // 0x800AD508: bne         $v1, $s3, L_800AD4D0
    if (ctx->r3 != ctx->r19) {
        // 0x800AD50C: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_800AD4D0;
    }
    // 0x800AD50C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800AD510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AD514: jal         0x800EE8CC
    // 0x800AD518: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800EE8CC(rdram, ctx);
        goto after_3;
    // 0x800AD518: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_3:
    // 0x800AD51C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800AD520: sltu        $at, $s0, $s7
    ctx->r1 = ctx->r16 < ctx->r23 ? 1 : 0;
    // 0x800AD524: bne         $at, $zero, L_800AD4B8
    if (ctx->r1 != 0) {
        // 0x800AD528: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_800AD4B8;
    }
    // 0x800AD528: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800AD52C: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x800AD530: lw          $t8, 0xF8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF8);
    // 0x800AD534: lw          $t5, 0xEC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XEC);
    // 0x800AD538: lw          $t6, 0xD4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD4);
    // 0x800AD53C: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800AD540: bne         $at, $zero, L_800AD554
    if (ctx->r1 != 0) {
        // 0x800AD544: lw          $a2, 0x11C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X11C);
            goto L_800AD554;
    }
    // 0x800AD544: lw          $a2, 0x11C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X11C);
    // 0x800AD548: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800AD54C: beq         $at, $zero, L_800AD560
    if (ctx->r1 == 0) {
        // 0x800AD550: lw          $t7, 0xCC($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XCC);
            goto L_800AD560;
    }
    // 0x800AD550: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
L_800AD554:
    // 0x800AD554: lw          $a1, 0x140($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X140);
    // 0x800AD558: b           L_800AD824
    // 0x800AD55C: lw          $v0, 0x104($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X104);
        goto L_800AD824;
    // 0x800AD55C: lw          $v0, 0x104($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X104);
L_800AD560:
    // 0x800AD560: lw          $t9, 0xFC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XFC);
    // 0x800AD564: lw          $t8, 0xF0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF0);
    // 0x800AD568: lw          $t5, 0xD8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XD8);
    // 0x800AD56C: slt         $at, $t7, $t9
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800AD570: bne         $at, $zero, L_800AD584
    if (ctx->r1 != 0) {
        // 0x800AD574: lw          $a2, 0x11C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X11C);
            goto L_800AD584;
    }
    // 0x800AD574: lw          $a2, 0x11C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X11C);
    // 0x800AD578: slt         $at, $t8, $t5
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800AD57C: beq         $at, $zero, L_800AD590
    if (ctx->r1 == 0) {
        // 0x800AD580: lw          $t6, 0xD0($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XD0);
            goto L_800AD590;
    }
    // 0x800AD580: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
L_800AD584:
    // 0x800AD584: lw          $a1, 0x140($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X140);
    // 0x800AD588: b           L_800AD824
    // 0x800AD58C: lw          $v0, 0x104($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X104);
        goto L_800AD824;
    // 0x800AD58C: lw          $v0, 0x104($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X104);
L_800AD590:
    // 0x800AD590: lw          $t7, 0x100($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X100);
    // 0x800AD594: lw          $t9, 0xF4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF4);
    // 0x800AD598: lw          $t8, 0xDC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XDC);
    // 0x800AD59C: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800AD5A0: bne         $at, $zero, L_800AD5B4
    if (ctx->r1 != 0) {
        // 0x800AD5A4: lw          $a2, 0x11C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X11C);
            goto L_800AD5B4;
    }
    // 0x800AD5A4: lw          $a2, 0x11C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X11C);
    // 0x800AD5A8: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800AD5AC: beql        $at, $zero, L_800AD5C4
    if (ctx->r1 == 0) {
        // 0x800AD5B0: lw          $v1, 0x500($s5)
        ctx->r3 = MEM_W(ctx->r21, 0X500);
            goto L_800AD5C4;
    }
    goto skip_4;
    // 0x800AD5B0: lw          $v1, 0x500($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X500);
    skip_4:
L_800AD5B4:
    // 0x800AD5B4: lw          $a1, 0x140($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X140);
    // 0x800AD5B8: b           L_800AD824
    // 0x800AD5BC: lw          $v0, 0x104($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X104);
        goto L_800AD824;
    // 0x800AD5BC: lw          $v0, 0x104($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X104);
    // 0x800AD5C0: lw          $v1, 0x500($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X500);
L_800AD5C4:
    // 0x800AD5C4: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
    // 0x800AD5C8: addiu       $a0, $sp, 0x98
    ctx->r4 = ADD32(ctx->r29, 0X98);
    // 0x800AD5CC: sltu        $at, $v1, $fp
    ctx->r1 = ctx->r3 < ctx->r30 ? 1 : 0;
    // 0x800AD5D0: bne         $at, $zero, L_800AD678
    if (ctx->r1 != 0) {
        // 0x800AD5D4: addiu       $a1, $sp, 0xB0
        ctx->r5 = ADD32(ctx->r29, 0XB0);
            goto L_800AD678;
    }
    // 0x800AD5D4: addiu       $a1, $sp, 0xB0
    ctx->r5 = ADD32(ctx->r29, 0XB0);
    // 0x800AD5D8: lw          $t5, 0xA4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA4);
L_800AD5DC:
    // 0x800AD5DC: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x800AD5E0: lw          $t7, 0xA8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA8);
    // 0x800AD5E4: bnel        $t5, $t6, L_800AD66C
    if (ctx->r13 != ctx->r14) {
        // 0x800AD5E8: addiu       $v0, $v0, 0x14
        ctx->r2 = ADD32(ctx->r2, 0X14);
            goto L_800AD66C;
    }
    goto skip_5;
    // 0x800AD5E8: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    skip_5:
    // 0x800AD5EC: lh          $t9, 0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2);
    // 0x800AD5F0: lw          $t8, 0xAC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XAC);
    // 0x800AD5F4: bnel        $t7, $t9, L_800AD66C
    if (ctx->r15 != ctx->r25) {
        // 0x800AD5F8: addiu       $v0, $v0, 0x14
        ctx->r2 = ADD32(ctx->r2, 0X14);
            goto L_800AD66C;
    }
    goto skip_6;
    // 0x800AD5F8: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    skip_6:
    // 0x800AD5FC: lh          $t5, 0x4($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X4);
    // 0x800AD600: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x800AD604: bnel        $t8, $t5, L_800AD66C
    if (ctx->r24 != ctx->r13) {
        // 0x800AD608: addiu       $v0, $v0, 0x14
        ctx->r2 = ADD32(ctx->r2, 0X14);
            goto L_800AD66C;
    }
    goto skip_7;
    // 0x800AD608: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    skip_7:
    // 0x800AD60C: lh          $t7, 0x6($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X6);
    // 0x800AD610: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x800AD614: bnel        $t6, $t7, L_800AD66C
    if (ctx->r14 != ctx->r15) {
        // 0x800AD618: addiu       $v0, $v0, 0x14
        ctx->r2 = ADD32(ctx->r2, 0X14);
            goto L_800AD66C;
    }
    goto skip_8;
    // 0x800AD618: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    skip_8:
    // 0x800AD61C: lh          $t8, 0x8($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X8);
    // 0x800AD620: lw          $t5, 0xB8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB8);
    // 0x800AD624: bnel        $t9, $t8, L_800AD66C
    if (ctx->r25 != ctx->r24) {
        // 0x800AD628: addiu       $v0, $v0, 0x14
        ctx->r2 = ADD32(ctx->r2, 0X14);
            goto L_800AD66C;
    }
    goto skip_9;
    // 0x800AD628: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    skip_9:
    // 0x800AD62C: lh          $t6, 0xA($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XA);
    // 0x800AD630: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x800AD634: bnel        $t5, $t6, L_800AD66C
    if (ctx->r13 != ctx->r14) {
        // 0x800AD638: addiu       $v0, $v0, 0x14
        ctx->r2 = ADD32(ctx->r2, 0X14);
            goto L_800AD66C;
    }
    goto skip_10;
    // 0x800AD638: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    skip_10:
    // 0x800AD63C: lh          $t9, 0xC($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XC);
    // 0x800AD640: lw          $t8, 0xC0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC0);
    // 0x800AD644: bnel        $t7, $t9, L_800AD66C
    if (ctx->r15 != ctx->r25) {
        // 0x800AD648: addiu       $v0, $v0, 0x14
        ctx->r2 = ADD32(ctx->r2, 0X14);
            goto L_800AD66C;
    }
    goto skip_11;
    // 0x800AD648: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    skip_11:
    // 0x800AD64C: lh          $t5, 0xE($v0)
    ctx->r13 = MEM_H(ctx->r2, 0XE);
    // 0x800AD650: lw          $t6, 0xC4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC4);
    // 0x800AD654: bnel        $t8, $t5, L_800AD66C
    if (ctx->r24 != ctx->r13) {
        // 0x800AD658: addiu       $v0, $v0, 0x14
        ctx->r2 = ADD32(ctx->r2, 0X14);
            goto L_800AD66C;
    }
    goto skip_12;
    // 0x800AD658: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    skip_12:
    // 0x800AD65C: lh          $t7, 0x10($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X10);
    // 0x800AD660: beq         $t6, $t7, L_800AD678
    if (ctx->r14 == ctx->r15) {
        // 0x800AD664: nop
    
            goto L_800AD678;
    }
    // 0x800AD664: nop

    // 0x800AD668: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
L_800AD66C:
    // 0x800AD66C: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800AD670: bnel        $at, $zero, L_800AD5DC
    if (ctx->r1 != 0) {
        // 0x800AD674: lw          $t5, 0xA4($sp)
        ctx->r13 = MEM_W(ctx->r29, 0XA4);
            goto L_800AD5DC;
    }
    goto skip_13;
    // 0x800AD674: lw          $t5, 0xA4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA4);
    skip_13:
L_800AD678:
    // 0x800AD678: beq         $v0, $v1, L_800AD68C
    if (ctx->r2 == ctx->r3) {
        // 0x800AD67C: lw          $a2, 0x11C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X11C);
            goto L_800AD68C;
    }
    // 0x800AD67C: lw          $a2, 0x11C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X11C);
    // 0x800AD680: lw          $a1, 0x140($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X140);
    // 0x800AD684: b           L_800AD824
    // 0x800AD688: lw          $v0, 0x104($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X104);
        goto L_800AD824;
    // 0x800AD688: lw          $v0, 0x104($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X104);
L_800AD68C:
    // 0x800AD68C: jal         0x800EFB58
    // 0x800AD690: addiu       $a2, $sp, 0xA4
    ctx->r6 = ADD32(ctx->r29, 0XA4);
    func_800EFB58(rdram, ctx);
        goto after_4;
    // 0x800AD690: addiu       $a2, $sp, 0xA4
    ctx->r6 = ADD32(ctx->r29, 0XA4);
    after_4:
    // 0x800AD694: addiu       $a0, $sp, 0x8C
    ctx->r4 = ADD32(ctx->r29, 0X8C);
    // 0x800AD698: addiu       $a1, $sp, 0xBC
    ctx->r5 = ADD32(ctx->r29, 0XBC);
    // 0x800AD69C: jal         0x800EFB58
    // 0x800AD6A0: addiu       $a2, $sp, 0xA4
    ctx->r6 = ADD32(ctx->r29, 0XA4);
    func_800EFB58(rdram, ctx);
        goto after_5;
    // 0x800AD6A0: addiu       $a2, $sp, 0xA4
    ctx->r6 = ADD32(ctx->r29, 0XA4);
    after_5:
    // 0x800AD6A4: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x800AD6A8: addiu       $a1, $sp, 0x98
    ctx->r5 = ADD32(ctx->r29, 0X98);
    // 0x800AD6AC: jal         0x800EE9EC
    // 0x800AD6B0: addiu       $a2, $sp, 0x8C
    ctx->r6 = ADD32(ctx->r29, 0X8C);
    func_800EE9EC(rdram, ctx);
        goto after_6;
    // 0x800AD6B0: addiu       $a2, $sp, 0x8C
    ctx->r6 = ADD32(ctx->r29, 0X8C);
    after_6:
    // 0x800AD6B4: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800AD6B8: lw          $a2, 0x11C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X11C);
    // 0x800AD6BC: lw          $a1, 0x140($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X140);
    // 0x800AD6C0: c.le.s      $f16, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f16.fl <= ctx->f22.fl;
    // 0x800AD6C4: nop

    // 0x800AD6C8: bc1f        L_800AD6D8
    if (!c1cs) {
        // 0x800AD6CC: nop
    
            goto L_800AD6D8;
    }
    // 0x800AD6CC: nop

    // 0x800AD6D0: b           L_800AD824
    // 0x800AD6D4: lw          $v0, 0x104($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X104);
        goto L_800AD824;
    // 0x800AD6D4: lw          $v0, 0x104($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X104);
L_800AD6D8:
    // 0x800AD6D8: jal         0x800EF2A0
    // 0x800AD6DC: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    func_800EF2A0(rdram, ctx);
        goto after_7;
    // 0x800AD6DC: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    after_7:
    // 0x800AD6E0: lwc1        $f18, 0x78($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800AD6E4: lw          $a2, 0x11C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X11C);
    // 0x800AD6E8: lw          $a1, 0x140($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X140);
    // 0x800AD6EC: c.lt.s      $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f18.fl < ctx->f20.fl;
    // 0x800AD6F0: nop

    // 0x800AD6F4: bc1fl       L_800AD708
    if (!c1cs) {
        // 0x800AD6F8: lw          $v1, 0x500($s5)
        ctx->r3 = MEM_W(ctx->r21, 0X500);
            goto L_800AD708;
    }
    goto skip_14;
    // 0x800AD6F8: lw          $v1, 0x500($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X500);
    skip_14:
    // 0x800AD6FC: b           L_800AD824
    // 0x800AD700: lw          $v0, 0x104($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X104);
        goto L_800AD824;
    // 0x800AD700: lw          $v0, 0x104($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X104);
    // 0x800AD704: lw          $v1, 0x500($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X500);
L_800AD708:
    // 0x800AD708: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x800AD70C: lw          $t5, 0xA4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA4);
    // 0x800AD710: subu        $t9, $v1, $s5
    ctx->r25 = SUB32(ctx->r3, ctx->r21);
    // 0x800AD714: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x800AD718: mflo        $t8
    ctx->r24 = lo;
    // 0x800AD71C: slti        $at, $t8, 0x40
    ctx->r1 = SIGNED(ctx->r24) < 0X40 ? 1 : 0;
    // 0x800AD720: beq         $at, $zero, L_800AD798
    if (ctx->r1 == 0) {
        // 0x800AD724: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_800AD798;
    }
    // 0x800AD724: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800AD728: sh          $t5, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r13;
    // 0x800AD72C: lw          $t7, 0x500($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X500);
    // 0x800AD730: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x800AD734: sh          $t6, 0x2($t7)
    MEM_H(0X2, ctx->r15) = ctx->r14;
    // 0x800AD738: lw          $t8, 0x500($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X500);
    // 0x800AD73C: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x800AD740: sh          $t9, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r25;
    // 0x800AD744: lw          $t6, 0x500($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X500);
    // 0x800AD748: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x800AD74C: sh          $t5, 0x6($t6)
    MEM_H(0X6, ctx->r14) = ctx->r13;
    // 0x800AD750: lw          $t9, 0x500($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X500);
    // 0x800AD754: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x800AD758: sh          $t7, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r15;
    // 0x800AD75C: lw          $t5, 0x500($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X500);
    // 0x800AD760: lw          $t8, 0xB8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB8);
    // 0x800AD764: sh          $t8, 0xA($t5)
    MEM_H(0XA, ctx->r13) = ctx->r24;
    // 0x800AD768: lw          $t7, 0x500($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X500);
    // 0x800AD76C: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x800AD770: sh          $t6, 0xC($t7)
    MEM_H(0XC, ctx->r15) = ctx->r14;
    // 0x800AD774: lw          $t8, 0x500($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X500);
    // 0x800AD778: lw          $t9, 0xC0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC0);
    // 0x800AD77C: sh          $t9, 0xE($t8)
    MEM_H(0XE, ctx->r24) = ctx->r25;
    // 0x800AD780: lw          $t6, 0x500($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X500);
    // 0x800AD784: lw          $t5, 0xC4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC4);
    // 0x800AD788: sh          $t5, 0x10($t6)
    MEM_H(0X10, ctx->r14) = ctx->r13;
    // 0x800AD78C: lw          $t7, 0x500($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X500);
    // 0x800AD790: addiu       $t9, $t7, 0x14
    ctx->r25 = ADD32(ctx->r15, 0X14);
    // 0x800AD794: sw          $t9, 0x500($s5)
    MEM_W(0X500, ctx->r21) = ctx->r25;
L_800AD798:
    // 0x800AD798: lw          $t8, 0x11C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X11C);
    // 0x800AD79C: lw          $t5, 0x140($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X140);
    // 0x800AD7A0: addiu       $a1, $sp, 0xA4
    ctx->r5 = ADD32(ctx->r29, 0XA4);
    // 0x800AD7A4: slt         $at, $t8, $t5
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800AD7A8: beq         $at, $zero, L_800AD818
    if (ctx->r1 == 0) {
        // 0x800AD7AC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800AD818;
    }
L_800AD7AC:
    // 0x800AD7AC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800AD7B0: addiu       $v0, $sp, 0xE0
    ctx->r2 = ADD32(ctx->r29, 0XE0);
    // 0x800AD7B4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_800AD7B8:
    // 0x800AD7B8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800AD7BC: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800AD7C0: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x800AD7C4: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x800AD7C8: subu        $t5, $t5, $t0
    ctx->r13 = SUB32(ctx->r13, ctx->r8);
    // 0x800AD7CC: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x800AD7D0: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x800AD7D4: addu        $t6, $t8, $t5
    ctx->r14 = ADD32(ctx->r24, ctx->r13);
    // 0x800AD7D8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800AD7DC: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x800AD7E0: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800AD7E4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800AD7E8: bne         $v0, $s4, L_800AD7B8
    if (ctx->r2 != ctx->r20) {
        // 0x800AD7EC: sh          $t9, 0x0($t7)
        MEM_H(0X0, ctx->r15) = ctx->r25;
            goto L_800AD7B8;
    }
    // 0x800AD7EC: sh          $t9, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r25;
    // 0x800AD7F0: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800AD7F4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800AD7F8: bne         $t0, $at, L_800AD7AC
    if (ctx->r8 != ctx->r1) {
        // 0x800AD7FC: addiu       $a1, $a1, 0xC
        ctx->r5 = ADD32(ctx->r5, 0XC);
            goto L_800AD7AC;
    }
    // 0x800AD7FC: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    // 0x800AD800: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x800AD804: addiu       $t5, $t8, 0x12
    ctx->r13 = ADD32(ctx->r24, 0X12);
    // 0x800AD808: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x800AD80C: lw          $t6, 0x11C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X11C);
    // 0x800AD810: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x800AD814: sw          $t9, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r25;
L_800AD818:
    // 0x800AD818: lw          $a2, 0x11C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X11C);
    // 0x800AD81C: lw          $a1, 0x140($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X140);
    // 0x800AD820: lw          $v0, 0x104($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X104);
L_800AD824:
    // 0x800AD824: slt         $at, $a2, $a1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
L_800AD828:
    // 0x800AD828: beq         $at, $zero, L_800AD840
    if (ctx->r1 == 0) {
        // 0x800AD82C: addiu       $v0, $v0, 0xC
        ctx->r2 = ADD32(ctx->r2, 0XC);
            goto L_800AD840;
    }
    // 0x800AD82C: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800AD830: lw          $t7, 0x108($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X108);
    // 0x800AD834: sltu        $at, $v0, $t7
    ctx->r1 = ctx->r2 < ctx->r15 ? 1 : 0;
    // 0x800AD838: bnel        $at, $zero, L_800AD45C
    if (ctx->r1 != 0) {
        // 0x800AD83C: lw          $t8, 0x8($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X8);
            goto L_800AD45C;
    }
    goto skip_15;
    // 0x800AD83C: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    skip_15:
L_800AD840:
    // 0x800AD840: lw          $t8, 0x110($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X110);
L_800AD844:
    // 0x800AD844: lw          $t6, 0x114($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X114);
    // 0x800AD848: addiu       $t5, $t8, 0x4
    ctx->r13 = ADD32(ctx->r24, 0X4);
    // 0x800AD84C: sltu        $at, $t5, $t6
    ctx->r1 = ctx->r13 < ctx->r14 ? 1 : 0;
    // 0x800AD850: bne         $at, $zero, L_800AD3F8
    if (ctx->r1 != 0) {
        // 0x800AD854: sw          $t5, 0x110($sp)
        MEM_W(0X110, ctx->r29) = ctx->r13;
            goto L_800AD3F8;
    }
    // 0x800AD854: sw          $t5, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r13;
L_800AD858:
    // 0x800AD858: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x800AD85C: lw          $v0, 0x11C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X11C);
    // 0x800AD860: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800AD864: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800AD868: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800AD86C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800AD870: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x800AD874: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x800AD878: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x800AD87C: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x800AD880: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x800AD884: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x800AD888: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x800AD88C: jr          $ra
    // 0x800AD890: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
    return;
    // 0x800AD890: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
;}
RECOMP_FUNC void _chdinotraindoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087130: syscall     520
    recomp_syscall_handler(rdram, ctx, 0x80087130);
    return;
    // 0x80087134: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80803844_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803844: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80803848: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080384C: jal         0x800DC0C0
    // 0x80803850: nop

    func_800DC0C0(rdram, ctx);
        goto after_0;
    // 0x80803850: nop

    after_0:
    // 0x80803854: addiu       $a0, $zero, 0x6E9
    ctx->r4 = ADD32(0, 0X6E9);
    // 0x80803858: jal         0x800DA298
    // 0x8080385C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x8080385C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80803860: beq         $v0, $zero, L_80803870
    if (ctx->r2 == 0) {
        // 0x80803864: lwc1        $f2, 0x1C($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_80803870;
    }
    // 0x80803864: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80803868: b           L_808038B4
    // 0x8080386C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_808038B4;
    // 0x8080386C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80803870:
    // 0x80803870: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80803874: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80803878: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X4240) << 16);
    // 0x8080387C: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x80803880: nop

    // 0x80803884: bc1f        L_80803894
    if (!c1cs) {
        // 0x80803888: nop
    
            goto L_80803894;
    }
    // 0x80803888: nop

    // 0x8080388C: b           L_808038B4
    // 0x80803890: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808038B4;
    // 0x80803890: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80803894:
    // 0x80803894: lwc1        $f6, 0x4240($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X4240));
    // 0x80803898: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8080389C: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x808038A0: nop

    // 0x808038A4: bc1f        L_808038B4
    if (!c1cs) {
        // 0x808038A8: nop
    
            goto L_808038B4;
    }
    // 0x808038A8: nop

    // 0x808038AC: b           L_808038B4
    // 0x808038B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808038B4;
    // 0x808038B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808038B4:
    // 0x808038B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808038B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808038BC: jr          $ra
    // 0x808038C0: nop

    return;
    // 0x808038C0: nop

;}
RECOMP_FUNC void _chfactorytoxiccloud_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087518: syscall     583
    recomp_syscall_handler(rdram, ctx, 0x80087518);
    return;
    // 0x8008751C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chcauldronenergybars_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800870F0: syscall     514
    recomp_syscall_handler(rdram, ctx, 0x800870F0);
    return;
    // 0x800870F4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chvolcanobits_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1264, 0X11E4) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0x11E4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1264, 0X11E4));
    return;
    // 0x80800020: addiu       $v0, $v0, 0x11E4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1264, 0X11E4));
;}
RECOMP_FUNC void func_80801294_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801294: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801298: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080129C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808012A0: lbu         $v0, 0x15C($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X15C);
    // 0x808012A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808012A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808012AC: beq         $v0, $at, L_808012C8
    if (ctx->r2 == ctx->r1) {
        // 0x808012B0: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_808012C8;
    }
    // 0x808012B0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808012B4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808012B8: beq         $v0, $at, L_808012E0
    if (ctx->r2 == ctx->r1) {
        // 0x808012BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808012E0;
    }
    // 0x808012BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012C0: b           L_808012F0
    // 0x808012C4: nop

        goto L_808012F0;
    // 0x808012C4: nop

L_808012C8:
    // 0x808012C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012CC: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    // 0x808012D0: jal         0x80801258
    // 0x808012D4: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    func_80801258_bstrexsmall(rdram, ctx);
        goto after_0;
    // 0x808012D4: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_0:
    // 0x808012D8: b           L_808012F0
    // 0x808012DC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
        goto L_808012F0;
    // 0x808012DC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
L_808012E0:
    // 0x808012E0: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x808012E4: jal         0x80801258
    // 0x808012E8: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    func_80801258_bstrexsmall(rdram, ctx);
        goto after_1;
    // 0x808012E8: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_1:
    // 0x808012EC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
L_808012F0:
    // 0x808012F0: beq         $a2, $zero, L_8080131C
    if (ctx->r6 == 0) {
        // 0x808012F4: sb          $a2, 0x15C($s0)
        MEM_B(0X15C, ctx->r16) = ctx->r6;
            goto L_8080131C;
    }
    // 0x808012F4: sb          $a2, 0x15C($s0)
    MEM_B(0X15C, ctx->r16) = ctx->r6;
    // 0x808012F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808012FC: beq         $a2, $at, L_80801330
    if (ctx->r6 == ctx->r1) {
        // 0x80801300: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80801330;
    }
    // 0x80801300: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801304: beq         $a2, $at, L_80801394
    if (ctx->r6 == ctx->r1) {
        // 0x80801308: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80801394;
    }
    // 0x80801308: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080130C: beq         $a2, $at, L_808013B8
    if (ctx->r6 == ctx->r1) {
        // 0x80801310: nop
    
            goto L_808013B8;
    }
    // 0x80801310: nop

    // 0x80801314: b           L_808013D8
    // 0x80801318: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808013D8;
    // 0x80801318: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080131C:
    // 0x8080131C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801320: jal         0x808000C8
    // 0x80801324: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808000C8_bstrexsmall(rdram, ctx);
        goto after_2;
    // 0x80801324: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x80801328: b           L_808013D8
    // 0x8080132C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808013D8;
    // 0x8080132C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801330:
    // 0x80801330: jal         0x808004CC
    // 0x80801334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bstrexsmall_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80801334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801338: lui         $a2, 0x4046
    ctx->r6 = S32(0X4046 << 16);
    // 0x8080133C: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80801340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801344: jal         0x8008CCBC
    // 0x80801348: addiu       $a1, $zero, 0x1D0
    ctx->r5 = ADD32(0, 0X1D0);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_4;
    // 0x80801348: addiu       $a1, $zero, 0x1D0
    ctx->r5 = ADD32(0, 0X1D0);
    after_4:
    // 0x8080134C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80801350: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801358: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080135C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80801360: jal         0x8009FFD8
    // 0x80801364: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_8009FFD8(rdram, ctx);
        goto after_5;
    // 0x80801364: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_5:
    // 0x80801368: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x8080136C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80801370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801374: jal         0x8009C99C
    // 0x80801378: lui         $a1, 0x425C
    ctx->r5 = S32(0X425C << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_6;
    // 0x80801378: lui         $a1, 0x425C
    ctx->r5 = S32(0X425C << 16);
    after_6:
    // 0x8080137C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801380: jal         0x8009B9B0
    // 0x80801384: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_7;
    // 0x80801384: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_7:
    // 0x80801388: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8080138C: b           L_808013D4
    // 0x80801390: sb          $t7, 0x15D($s0)
    MEM_B(0X15D, ctx->r16) = ctx->r15;
        goto L_808013D4;
    // 0x80801390: sb          $t7, 0x15D($s0)
    MEM_B(0X15D, ctx->r16) = ctx->r15;
L_80801394:
    // 0x80801394: jal         0x8008CABC
    // 0x80801398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_8;
    // 0x80801398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8080139C: lui         $a2, 0x3E94
    ctx->r6 = S32(0X3E94 << 16);
    // 0x808013A0: ori         $a2, $a2, 0x7AE1
    ctx->r6 = ctx->r6 | 0X7AE1;
    // 0x808013A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808013A8: jal         0x8008B1D4
    // 0x808013AC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_9;
    // 0x808013AC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_9:
    // 0x808013B0: b           L_808013D8
    // 0x808013B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808013D8;
    // 0x808013B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808013B8:
    // 0x808013B8: jal         0x8008CABC
    // 0x808013BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_10;
    // 0x808013BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808013C0: lui         $a2, 0x3EFA
    ctx->r6 = S32(0X3EFA << 16);
    // 0x808013C4: ori         $a2, $a2, 0xE148
    ctx->r6 = ctx->r6 | 0XE148;
    // 0x808013C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808013CC: jal         0x8008B1D4
    // 0x808013D0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_11;
    // 0x808013D0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_11:
L_808013D4:
    // 0x808013D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808013D8:
    // 0x808013D8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808013DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808013E0: jr          $ra
    // 0x808013E4: nop

    return;
    // 0x808013E4: nop

;}
RECOMP_FUNC void _chfirefx_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086158: syscall     281
    recomp_syscall_handler(rdram, ctx, 0x80086158);
    return;
    // 0x8008615C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _chpotogoldbits_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800875D8: syscall     594
    recomp_syscall_handler(rdram, ctx, 0x800875D8);
    return;
    // 0x800875DC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _gcnewoption_entrypoint_45(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087E00: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087E00);
    return;
    // 0x80087E04: addi        $t0, $zero, 0xB4
    ctx->r8 = ADD32(0, 0XB4);
;}
RECOMP_FUNC void badrone_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800178: lw          $t6, 0x54($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X54);
    // 0x8080017C: jr          $ra
    // 0x80800180: lbu         $v0, 0x5($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X5);
    return;
    // 0x80800180: lbu         $v0, 0x5($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X5);
;}
RECOMP_FUNC void func_80800A08_gcmapsects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A08: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800A0C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800A10: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800A14: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800A18: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800A1C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800A20: lbu         $t6, 0x77($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X77);
    // 0x80800A24: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800A28: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80800A2C: blez        $t6, L_80800B28
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80800A30: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80800B28;
    }
    // 0x80800A30: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80800A34: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800A38: lw          $t7, 0x68($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X68);
L_80800A3C:
    // 0x80800A3C: addu        $v1, $t7, $s0
    ctx->r3 = ADD32(ctx->r15, ctx->r16);
    // 0x80800A40: lw          $t8, 0x4C($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4C);
    // 0x80800A44: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x80800A48: bltzl       $t0, L_80800A5C
    if (SIGNED(ctx->r8) < 0) {
        // 0x80800A4C: lhu         $v0, 0x40($v1)
        ctx->r2 = MEM_HU(ctx->r3, 0X40);
            goto L_80800A5C;
    }
    goto skip_0;
    // 0x80800A4C: lhu         $v0, 0x40($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X40);
    skip_0:
    // 0x80800A50: beql        $s3, $zero, L_80800B08
    if (ctx->r19 == 0) {
        // 0x80800A54: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800B08;
    }
    goto skip_1;
    // 0x80800A54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_1:
    // 0x80800A58: lhu         $v0, 0x40($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X40);
L_80800A5C:
    // 0x80800A5C: beql        $v0, $zero, L_80800AB8
    if (ctx->r2 == 0) {
        // 0x80800A60: lw          $t9, 0x68($s1)
        ctx->r25 = MEM_W(ctx->r17, 0X68);
            goto L_80800AB8;
    }
    goto skip_2;
    // 0x80800A60: lw          $t9, 0x68($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X68);
    skip_2:
    // 0x80800A64: jal         0x800D73CC
    // 0x80800A68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800D73CC(rdram, ctx);
        goto after_0;
    // 0x80800A68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_0:
    // 0x80800A6C: bnel        $v0, $zero, L_80800AB8
    if (ctx->r2 != 0) {
        // 0x80800A70: lw          $t9, 0x68($s1)
        ctx->r25 = MEM_W(ctx->r17, 0X68);
            goto L_80800AB8;
    }
    goto skip_3;
    // 0x80800A70: lw          $t9, 0x68($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X68);
    skip_3:
    // 0x80800A74: jal         0x800D5B24
    // 0x80800A78: nop

    func_800D5B24(rdram, ctx);
        goto after_1;
    // 0x80800A78: nop

    after_1:
    // 0x80800A7C: lw          $t1, 0x68($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X68);
    // 0x80800A80: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x80800A84: jal         0x800D674C
    // 0x80800A88: lhu         $a0, 0x40($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X40);
    func_800D674C(rdram, ctx);
        goto after_2;
    // 0x80800A88: lhu         $a0, 0x40($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X40);
    after_2:
    // 0x80800A8C: lw          $t3, 0x68($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X68);
    // 0x80800A90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800A94: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x80800A98: jal         0x800D70F8
    // 0x80800A9C: lhu         $a0, 0x40($t4)
    ctx->r4 = MEM_HU(ctx->r12, 0X40);
    func_800D70F8(rdram, ctx);
        goto after_3;
    // 0x80800A9C: lhu         $a0, 0x40($t4)
    ctx->r4 = MEM_HU(ctx->r12, 0X40);
    after_3:
    // 0x80800AA0: lw          $t5, 0x68($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X68);
    // 0x80800AA4: addu        $v1, $t5, $s0
    ctx->r3 = ADD32(ctx->r13, ctx->r16);
    // 0x80800AA8: lbu         $t7, 0x4C($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X4C);
    // 0x80800AAC: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x80800AB0: sb          $t8, 0x4C($v1)
    MEM_B(0X4C, ctx->r3) = ctx->r24;
    // 0x80800AB4: lw          $t9, 0x68($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X68);
L_80800AB8:
    // 0x80800AB8: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x80800ABC: lhu         $v0, 0x42($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X42);
    // 0x80800AC0: beql        $v0, $zero, L_80800B08
    if (ctx->r2 == 0) {
        // 0x80800AC4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800B08;
    }
    goto skip_4;
    // 0x80800AC4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_4:
    // 0x80800AC8: jal         0x800D73CC
    // 0x80800ACC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800D73CC(rdram, ctx);
        goto after_4;
    // 0x80800ACC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80800AD0: bnel        $v0, $zero, L_80800B08
    if (ctx->r2 != 0) {
        // 0x80800AD4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800B08;
    }
    goto skip_5;
    // 0x80800AD4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_5:
    // 0x80800AD8: jal         0x800D5B24
    // 0x80800ADC: nop

    func_800D5B24(rdram, ctx);
        goto after_5;
    // 0x80800ADC: nop

    after_5:
    // 0x80800AE0: lw          $t1, 0x68($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X68);
    // 0x80800AE4: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x80800AE8: jal         0x800D674C
    // 0x80800AEC: lhu         $a0, 0x42($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X42);
    func_800D674C(rdram, ctx);
        goto after_6;
    // 0x80800AEC: lhu         $a0, 0x42($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X42);
    after_6:
    // 0x80800AF0: lw          $t3, 0x68($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X68);
    // 0x80800AF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800AF8: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x80800AFC: jal         0x800D70F8
    // 0x80800B00: lhu         $a0, 0x42($t4)
    ctx->r4 = MEM_HU(ctx->r12, 0X42);
    func_800D70F8(rdram, ctx);
        goto after_7;
    // 0x80800B00: lhu         $a0, 0x42($t4)
    ctx->r4 = MEM_HU(ctx->r12, 0X42);
    after_7:
    // 0x80800B04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80800B08:
    // 0x80800B08: jal         0x80800250
    // 0x80800B0C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80800250_gcmapsects(rdram, ctx);
        goto after_8;
    // 0x80800B0C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_8:
    // 0x80800B10: lbu         $t5, 0x77($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X77);
    // 0x80800B14: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800B18: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    // 0x80800B1C: slt         $at, $s2, $t5
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80800B20: bnel        $at, $zero, L_80800A3C
    if (ctx->r1 != 0) {
        // 0x80800B24: lw          $t7, 0x68($s1)
        ctx->r15 = MEM_W(ctx->r17, 0X68);
            goto L_80800A3C;
    }
    goto skip_6;
    // 0x80800B24: lw          $t7, 0x68($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X68);
    skip_6:
L_80800B28:
    // 0x80800B28: jal         0x800DB9B0
    // 0x80800B2C: nop

    func_800DB9B0(rdram, ctx);
        goto after_9;
    // 0x80800B2C: nop

    after_9:
    // 0x80800B30: bne         $v0, $zero, L_80800B3C
    if (ctx->r2 != 0) {
        // 0x80800B34: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80800B3C;
    }
    // 0x80800B34: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800B38: sb          $t6, 0x78($s1)
    MEM_B(0X78, ctx->r17) = ctx->r14;
L_80800B3C:
    // 0x80800B3C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800B40: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800B44: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800B48: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B4C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800B50: jr          $ra
    // 0x80800B54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800B54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800C85A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C85A0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C85A4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C85A8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C85AC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800C85B0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800C85B4: addiu       $s0, $s0, -0x5500
    ctx->r16 = ADD32(ctx->r16, -0X5500);
    // 0x800C85B8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C85BC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800C85C0: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800C85C4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C85C8: jal         0x800B28C4
    // 0x800C85CC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    vector_begin(rdram, ctx);
        goto after_0;
    // 0x800C85CC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_0:
    // 0x800C85D0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800C85D4: jal         0x800B296C
    // 0x800C85D8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    vector_end(rdram, ctx);
        goto after_1;
    // 0x800C85D8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x800C85DC: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x800C85E0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800C85E4: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x800C85E8: beql        $at, $zero, L_800C865C
    if (ctx->r1 == 0) {
        // 0x800C85EC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800C865C;
    }
    goto skip_0;
    // 0x800C85EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x800C85F0: lbu         $t7, 0x15($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X15);
L_800C85F4:
    // 0x800C85F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C85F8: beql        $t7, $zero, L_800C864C
    if (ctx->r15 == 0) {
        // 0x800C85FC: addiu       $s0, $s0, 0x1C
        ctx->r16 = ADD32(ctx->r16, 0X1C);
            goto L_800C864C;
    }
    goto skip_1;
    // 0x800C85FC: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    skip_1:
    // 0x800C8600: jalr        $s3
    // 0x800C8604: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    LOOKUP_FUNC(ctx->r19)(rdram, ctx);
        goto after_2;
    // 0x800C8604: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x800C8608: beql        $v0, $zero, L_800C864C
    if (ctx->r2 == 0) {
        // 0x800C860C: addiu       $s0, $s0, 0x1C
        ctx->r16 = ADD32(ctx->r16, 0X1C);
            goto L_800C864C;
    }
    goto skip_2;
    // 0x800C860C: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    skip_2:
    // 0x800C8610: lbu         $t8, 0x17($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X17);
    // 0x800C8614: bnel        $t8, $zero, L_800C862C
    if (ctx->r24 != 0) {
        // 0x800C8618: lw          $t0, 0x2C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X2C);
            goto L_800C862C;
    }
    goto skip_3;
    // 0x800C8618: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    skip_3:
    // 0x800C861C: lbu         $t9, 0x18($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X18);
    // 0x800C8620: beql        $t9, $zero, L_800C864C
    if (ctx->r25 == 0) {
        // 0x800C8624: addiu       $s0, $s0, 0x1C
        ctx->r16 = ADD32(ctx->r16, 0X1C);
            goto L_800C864C;
    }
    goto skip_4;
    // 0x800C8624: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    skip_4:
    // 0x800C8628: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
L_800C862C:
    // 0x800C862C: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x800C8630: subu        $v0, $s0, $t0
    ctx->r2 = SUB32(ctx->r16, ctx->r8);
    // 0x800C8634: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x800C8638: mflo        $t1
    ctx->r9 = lo;
    // 0x800C863C: addiu       $v0, $t1, 0x1
    ctx->r2 = ADD32(ctx->r9, 0X1);
    // 0x800C8640: b           L_800C8660
    // 0x800C8644: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800C8660;
    // 0x800C8644: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C8648: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
L_800C864C:
    // 0x800C864C: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x800C8650: bnel        $at, $zero, L_800C85F4
    if (ctx->r1 != 0) {
        // 0x800C8654: lbu         $t7, 0x15($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X15);
            goto L_800C85F4;
    }
    goto skip_5;
    // 0x800C8654: lbu         $t7, 0x15($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X15);
    skip_5:
    // 0x800C8658: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C865C:
    // 0x800C865C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C8660:
    // 0x800C8660: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C8664: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C8668: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800C866C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800C8670: jr          $ra
    // 0x800C8674: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800C8674: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800EBC0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EBC0C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800EBC10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EBC14: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800EBC18: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800EBC1C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800EBC20: jal         0x800E99E0
    // 0x800EBC24: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800E99E0(rdram, ctx);
        goto after_0;
    // 0x800EBC24: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800EBC28: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800EBC2C: lbu         $t4, 0xB($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0XB);
    // 0x800EBC30: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800EBC34: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800EBC38: andi        $t5, $t4, 0xFFFD
    ctx->r13 = ctx->r12 & 0XFFFD;
    // 0x800EBC3C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x800EBC40: sh          $t6, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r14;
    // 0x800EBC44: lw          $t7, 0x4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4);
    // 0x800EBC48: sh          $t7, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r15;
    // 0x800EBC4C: lw          $t8, 0x8($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X8);
    // 0x800EBC50: lbu         $t7, 0xA($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XA);
    // 0x800EBC54: sh          $t8, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r24;
    // 0x800EBC58: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800EBC5C: andi        $t8, $t7, 0xFF07
    ctx->r24 = ctx->r15 & 0XFF07;
    // 0x800EBC60: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800EBC64: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800EBC68: sb          $t8, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r24;
    // 0x800EBC6C: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x800EBC70: andi        $t3, $t2, 0x2
    ctx->r11 = ctx->r10 & 0X2;
    // 0x800EBC74: or          $t9, $t3, $t5
    ctx->r25 = ctx->r11 | ctx->r13;
    // 0x800EBC78: sb          $t9, 0xB($v0)
    MEM_B(0XB, ctx->r2) = ctx->r25;
    // 0x800EBC7C: andi        $t0, $t9, 0xDF
    ctx->r8 = ctx->r25 & 0XDF;
    // 0x800EBC80: sb          $t0, 0xB($v0)
    MEM_B(0XB, ctx->r2) = ctx->r8;
    // 0x800EBC84: jal         0x800DC214
    // 0x800EBC88: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800DC214(rdram, ctx);
        goto after_1;
    // 0x800EBC88: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x800EBC8C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800EBC90: sll         $t2, $v0, 6
    ctx->r10 = S32(ctx->r2 << 6);
    // 0x800EBC94: andi        $t4, $t2, 0x7C0
    ctx->r12 = ctx->r10 & 0X7C0;
    // 0x800EBC98: lhu         $t3, 0xA($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0XA);
    // 0x800EBC9C: andi        $t5, $t3, 0xF83F
    ctx->r13 = ctx->r11 & 0XF83F;
    // 0x800EBCA0: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x800EBCA4: sh          $t6, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r14;
    // 0x800EBCA8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800EBCAC: sw          $v1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r3;
    // 0x800EBCB0: jal         0x800BD948
    // 0x800EBCB4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800BD948(rdram, ctx);
        goto after_2;
    // 0x800EBCB4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x800EBCB8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800EBCBC: sh          $v0, 0x1C($t8)
    MEM_H(0X1C, ctx->r24) = ctx->r2;
    // 0x800EBCC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EBCC4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800EBCC8: jr          $ra
    // 0x800EBCCC: nop

    return;
    // 0x800EBCCC: nop

;}
RECOMP_FUNC void func_80800068_chnewfreezy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800068: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080006C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800070: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800074: jal         0x80100094
    // 0x80800078: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800078: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8080007C: jal         0x8008A040
    // 0x80800080: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800080: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800084: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800088: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080008C: lbu         $a1, 0x79($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X79);
    // 0x80800090: srl         $t7, $a1, 4
    ctx->r15 = S32(U32(ctx->r5) >> 4);
    // 0x80800094: jal         0x8010A828
    // 0x80800098: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    func_8010A828(rdram, ctx);
        goto after_2;
    // 0x80800098: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
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
RECOMP_FUNC void func_80801188_chterryegg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801188: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080118C: beq         $a1, $zero, L_808011C8
    if (ctx->r5 == 0) {
        // 0x80801190: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_808011C8;
    }
    // 0x80801190: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801194: jal         0x808010DC
    // 0x80801198: nop

    func_808010DC_chterryegg(rdram, ctx);
        goto after_0;
    // 0x80801198: nop

    after_0:
    // 0x8080119C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808011A0: bne         $v0, $at, L_808011B4
    if (ctx->r2 != ctx->r1) {
        // 0x808011A4: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_808011B4;
    }
    // 0x808011A4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808011A8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808011AC: b           L_808011F4
    // 0x808011B0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_808011F4;
    // 0x808011B0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_808011B4:
    // 0x808011B4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808011B8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808011BC: nop

    // 0x808011C0: b           L_808011F4
    // 0x808011C4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_808011F4;
    // 0x808011C4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_808011C8:
    // 0x808011C8: jal         0x80801138
    // 0x808011CC: nop

    func_80801138_chterryegg(rdram, ctx);
        goto after_1;
    // 0x808011CC: nop

    after_1:
    // 0x808011D0: beq         $v0, $zero, L_808011E8
    if (ctx->r2 == 0) {
        // 0x808011D4: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_808011E8;
    }
    // 0x808011D4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808011D8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808011DC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808011E0: b           L_808011F4
    // 0x808011E4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_808011F4;
    // 0x808011E4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_808011E8:
    // 0x808011E8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808011EC: nop

    // 0x808011F0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_808011F4:
    // 0x808011F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808011F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808011FC: jr          $ra
    // 0x80801200: nop

    return;
    // 0x80801200: nop

    // 0x80801204: nop

    // 0x80801208: nop

    // 0x8080120C: nop

;}
RECOMP_FUNC void func_80800090_bskazglide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800090: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800094: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800098: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080009C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000A0: jal         0x8009E6C4
    // 0x808000A4: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    func_8009E6C4(rdram, ctx);
        goto after_0;
    // 0x808000A4: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    after_0:
    // 0x808000A8: bnel        $v0, $zero, L_80800174
    if (ctx->r2 != 0) {
        // 0x808000AC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800174;
    }
    goto skip_0;
    // 0x808000AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808000B0: jal         0x800832E0
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bskaz_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808000B8: jal         0x80084BF0
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafly_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C4: jal         0x80084C00
    // 0x808000C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _bafly_entrypoint_7(rdram, ctx);
        goto after_3;
    // 0x808000C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D0: jal         0x80093360
    // 0x808000D4: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    func_80093360(rdram, ctx);
        goto after_4;
    // 0x808000D4: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    after_4:
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000DC: jal         0x8009C908
    // 0x808000E0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    yaw_setUpdateType(rdram, ctx);
        goto after_5;
    // 0x808000E0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E8: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x808000EC: jal         0x8009C99C
    // 0x808000F0: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_6;
    // 0x808000F0: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_6:
    // 0x808000F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F8: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x808000FC: jal         0x8009C554
    // 0x80800100: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    baroll_setAngularVelocity(rdram, ctx);
        goto after_7;
    // 0x80800100: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_7:
    // 0x80800104: lui         $a2, 0x3F99
    ctx->r6 = S32(0X3F99 << 16);
    // 0x80800108: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8080010C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800110: jal         0x8009BFE4
    // 0x80800114: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    func_8009BFE4(rdram, ctx);
        goto after_8;
    // 0x80800114: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    after_8:
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080011C: jal         0x8009BCB4
    // 0x80800120: lui         $a1, 0xC396
    ctx->r5 = S32(0XC396 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_9;
    // 0x80800120: lui         $a1, 0xC396
    ctx->r5 = S32(0XC396 << 16);
    after_9:
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800128: jal         0x8009BCC4
    // 0x8080012C: lui         $a1, 0xC248
    ctx->r5 = S32(0XC248 << 16);
    baphysics_set_terminal_velocity(rdram, ctx);
        goto after_10;
    // 0x8080012C: lui         $a1, 0xC248
    ctx->r5 = S32(0XC248 << 16);
    after_10:
    // 0x80800130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800134: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x80800138: jal         0x800959C8
    // 0x8080013C: lui         $a2, 0x4234
    ctx->r6 = S32(0X4234 << 16);
    func_800959C8(rdram, ctx);
        goto after_11;
    // 0x8080013C: lui         $a2, 0x4234
    ctx->r6 = S32(0X4234 << 16);
    after_11:
    // 0x80800140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800144: jal         0x800961AC
    // 0x80800148: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800961AC(rdram, ctx);
        goto after_12;
    // 0x80800148: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_12:
    // 0x8080014C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800150: jal         0x800A4DA4
    // 0x80800154: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    func_800A4DA4(rdram, ctx);
        goto after_13;
    // 0x80800154: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_13:
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080015C: jal         0x80095774
    // 0x80800160: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    baflag_clear(rdram, ctx);
        goto after_14;
    // 0x80800160: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_14:
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800168: jal         0x80095774
    // 0x8080016C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    baflag_clear(rdram, ctx);
        goto after_15;
    // 0x8080016C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_15:
    // 0x80800170: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800174:
    // 0x80800174: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800178: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080017C: jr          $ra
    // 0x80800180: nop

    return;
    // 0x80800180: nop

;}
RECOMP_FUNC void _subaddielink_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A030: syscall     823
    recomp_syscall_handler(rdram, ctx, 0x8008A030);
    return;
    // 0x8008A034: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800A2060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2060: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800A2064: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A2068: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A206C: lw          $v1, 0x108($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X108);
    // 0x800A2070: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A2074: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A2078: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800A207C: beql        $v0, $zero, L_800A209C
    if (ctx->r2 == 0) {
        // 0x800A2080: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_800A209C;
    }
    goto skip_0;
    // 0x800A2080: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x800A2084: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A2088: beq         $v0, $at, L_800A20BC
    if (ctx->r2 == ctx->r1) {
        // 0x800A208C: addiu       $a0, $sp, 0x38
        ctx->r4 = ADD32(ctx->r29, 0X38);
            goto L_800A20BC;
    }
    // 0x800A208C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x800A2090: b           L_800A20CC
    // 0x800A2094: nop

        goto L_800A20CC;
    // 0x800A2094: nop

    // 0x800A2098: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_800A209C:
    // 0x800A209C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x800A20A0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800A20A4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800A20A8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800A20AC: jal         0x800EFA4C
    // 0x800A20B0: nop

    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x800A20B0: nop

    after_0:
    // 0x800A20B4: b           L_800A2100
    // 0x800A20B8: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
        goto L_800A2100;
    // 0x800A20B8: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
L_800A20BC:
    // 0x800A20BC: jal         0x800EE7F8
    // 0x800A20C0: addiu       $a1, $v1, 0x4
    ctx->r5 = ADD32(ctx->r3, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x800A20C0: addiu       $a1, $v1, 0x4
    ctx->r5 = ADD32(ctx->r3, 0X4);
    after_1:
    // 0x800A20C4: b           L_800A2100
    // 0x800A20C8: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
        goto L_800A2100;
    // 0x800A20C8: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
L_800A20CC:
    // 0x800A20CC: jal         0x800965C8
    // 0x800A20D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800965C8(rdram, ctx);
        goto after_2;
    // 0x800A20D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800A20D4: beq         $v0, $zero, L_800A20EC
    if (ctx->r2 == 0) {
        // 0x800A20D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A20EC;
    }
    // 0x800A20D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A20DC: jal         0x800A1968
    // 0x800A20E0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800A1968(rdram, ctx);
        goto after_3;
    // 0x800A20E0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_3:
    // 0x800A20E4: b           L_800A2100
    // 0x800A20E8: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
        goto L_800A2100;
    // 0x800A20E8: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
L_800A20EC:
    // 0x800A20EC: lw          $a1, 0x108($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X108);
    // 0x800A20F0: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x800A20F4: jal         0x800EE7F8
    // 0x800A20F8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x800A20F8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_4:
    // 0x800A20FC: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
L_800A2100:
    // 0x800A2100: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800A2104: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A2108: addiu       $v1, $sp, 0x38
    ctx->r3 = ADD32(ctx->r29, 0X38);
    // 0x800A210C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
L_800A2110:
    // 0x800A2110: lw          $t6, 0x108($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X108);
    // 0x800A2114: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800A2118: addu        $v0, $t6, $a0
    ctx->r2 = ADD32(ctx->r14, ctx->r4);
    // 0x800A211C: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800A2120: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800A2124: nop

    // 0x800A2128: bc1fl       L_800A2164
    if (!c1cs) {
        // 0x800A212C: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_800A2164;
    }
    goto skip_1;
    // 0x800A212C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_1:
    // 0x800A2130: add.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x800A2134: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x800A2138: lw          $t7, 0x108($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X108);
    // 0x800A213C: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800A2140: addu        $v0, $t7, $a0
    ctx->r2 = ADD32(ctx->r15, ctx->r4);
    // 0x800A2144: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800A2148: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800A214C: nop

    // 0x800A2150: bc1fl       L_800A21A0
    if (!c1cs) {
        // 0x800A2154: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800A21A0;
    }
    goto skip_2;
    // 0x800A2154: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_2:
    // 0x800A2158: b           L_800A219C
    // 0x800A215C: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
        goto L_800A219C;
    // 0x800A215C: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x800A2160: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_800A2164:
    // 0x800A2164: nop

    // 0x800A2168: bc1fl       L_800A21A0
    if (!c1cs) {
        // 0x800A216C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800A21A0;
    }
    goto skip_3;
    // 0x800A216C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_3:
    // 0x800A2170: sub.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x800A2174: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x800A2178: lw          $t8, 0x108($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X108);
    // 0x800A217C: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800A2180: addu        $v0, $t8, $a0
    ctx->r2 = ADD32(ctx->r24, ctx->r4);
    // 0x800A2184: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800A2188: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x800A218C: nop

    // 0x800A2190: bc1fl       L_800A21A0
    if (!c1cs) {
        // 0x800A2194: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800A21A0;
    }
    goto skip_4;
    // 0x800A2194: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_4:
    // 0x800A2198: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
L_800A219C:
    // 0x800A219C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_800A21A0:
    // 0x800A21A0: bne         $v1, $a1, L_800A2110
    if (ctx->r3 != ctx->r5) {
        // 0x800A21A4: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800A2110;
    }
    // 0x800A21A4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800A21A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A21AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A21B0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800A21B4: jr          $ra
    // 0x800A21B8: nop

    return;
    // 0x800A21B8: nop

    // 0x800A21BC: nop

;}
RECOMP_FUNC void func_80800230_ncba1p(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800230: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800234: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x80800238: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8080023C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80800240: sw          $s5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r21;
    // 0x80800244: sw          $s4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r20;
    // 0x80800248: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x8080024C: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x80800250: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x80800254: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80800258: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8080025C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800260: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80800264: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80800268: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x8080026C: jal         0x800D9078
    // 0x80800270: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x80800270: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_0:
    // 0x80800274: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80800278: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080027C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800280: lwc1        $f4, 0x48($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X48);
    // 0x80800284: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800288: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8080028C: sub.s       $f0, $f20, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f20.fl - ctx->f6.fl;
    // 0x80800290: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800294: jal         0x801163A0
    // 0x80800298: nop

    func_801163A0(rdram, ctx);
        goto after_1;
    // 0x80800298: nop

    after_1:
    // 0x8080029C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808002A0: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x808002A4: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x808002A8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808002AC: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x808002B0: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x808002B4: addiu       $s5, $zero, 0xC
    ctx->r21 = ADD32(0, 0XC);
L_808002B8:
    // 0x808002B8: lw          $s1, 0x0($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X0);
    // 0x808002BC: lwc1        $f8, 0x0($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X0);
    // 0x808002C0: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x808002C4: addu        $t7, $s1, $s0
    ctx->r15 = ADD32(ctx->r17, ctx->r16);
    // 0x808002C8: lw          $a3, 0x18($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X18);
    // 0x808002CC: lwc1        $f12, 0x48($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X48);
    // 0x808002D0: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x808002D4: jal         0x800F130C
    // 0x808002D8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F130C(rdram, ctx);
        goto after_2;
    // 0x808002D8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x808002DC: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x808002E0: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x808002E4: swc1        $f0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f0.u32l;
    // 0x808002E8: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x808002EC: lwc1        $f12, 0x0($s4)
    ctx->f12.u32l = MEM_W(ctx->r20, 0X0);
    // 0x808002F0: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x808002F4: jal         0x800F1DCC
    // 0x808002F8: lwc1        $f14, 0x24($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0X24);
    func_800F1DCC(rdram, ctx);
        goto after_3;
    // 0x808002F8: lwc1        $f14, 0x24($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0X24);
    after_3:
    // 0x808002FC: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x80800300: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80800304: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80800308: lwc1        $f12, 0x48($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X48);
    // 0x8080030C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80800310: jal         0x800F130C
    // 0x80800314: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    func_800F130C(rdram, ctx);
        goto after_4;
    // 0x80800314: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_4:
    // 0x80800318: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x8080031C: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x80800320: lwc1        $f10, 0x24($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X24);
    // 0x80800324: jal         0x800136E4
    // 0x80800328: add.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f10.fl;
    func_800136E4(rdram, ctx);
        goto after_5;
    // 0x80800328: add.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f10.fl;
    after_5:
    // 0x8080032C: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80800330: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80800334: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80800338: addu        $t6, $t5, $s0
    ctx->r14 = ADD32(ctx->r13, ctx->r16);
    // 0x8080033C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800340: bne         $s0, $s5, L_808002B8
    if (ctx->r16 != ctx->r21) {
        // 0x80800344: swc1        $f0, 0xC($t6)
        MEM_W(0XC, ctx->r14) = ctx->f0.u32l;
            goto L_808002B8;
    }
    // 0x80800344: swc1        $f0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f0.u32l;
    // 0x80800348: lw          $s1, 0x0($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X0);
    // 0x8080034C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800350: lwc1        $f16, 0x48($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X48);
    // 0x80800354: c.eq.s      $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f22.fl == ctx->f16.fl;
    // 0x80800358: nop

    // 0x8080035C: bc1fl       L_80800374
    if (!c1cs) {
        // 0x80800360: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800374;
    }
    goto skip_0;
    // 0x80800360: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
    // 0x80800364: jal         0x80800620
    // 0x80800368: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    ncba1p_entrypoint_5(rdram, ctx);
        goto after_6;
    // 0x80800368: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_6:
    // 0x8080036C: lw          $s1, 0x0($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X0);
    // 0x80800370: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80800374:
    // 0x80800374: addiu       $a1, $s1, 0x18
    ctx->r5 = ADD32(ctx->r17, 0X18);
    // 0x80800378: jal         0x80800008
    // 0x8080037C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_80800008_ncba1p(rdram, ctx);
        goto after_7;
    // 0x8080037C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_7:
    // 0x80800380: bne         $v0, $zero, L_80800390
    if (ctx->r2 != 0) {
        // 0x80800384: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800390;
    }
    // 0x80800384: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800388: jal         0x8080004C
    // 0x8080038C: addiu       $a1, $zero, 0x63
    ctx->r5 = ADD32(0, 0X63);
    func_8080004C_ncba1p(rdram, ctx);
        goto after_8;
    // 0x8080038C: addiu       $a1, $zero, 0x63
    ctx->r5 = ADD32(0, 0X63);
    after_8:
L_80800390:
    // 0x80800390: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80800394: jal         0x800EE7F8
    // 0x80800398: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    func_800EE7F8(rdram, ctx);
        goto after_9;
    // 0x80800398: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    after_9:
    // 0x8080039C: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x808003A0: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x808003A4: jal         0x800EE7F8
    // 0x808003A8: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_800EE7F8(rdram, ctx);
        goto after_10;
    // 0x808003A8: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_10:
    // 0x808003AC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x808003B0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808003B4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808003B8: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x808003BC: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x808003C0: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x808003C4: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x808003C8: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x808003CC: lw          $s4, 0x44($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X44);
    // 0x808003D0: lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X48);
    // 0x808003D4: jr          $ra
    // 0x808003D8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x808003D8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8008B8E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B8E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008B8E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008B8E8: jal         0x8008BAC0
    // 0x8008B8EC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_8008BAC0(rdram, ctx);
        goto after_0;
    // 0x8008B8EC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8008B8F0: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x8008B8F4: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x8008B8F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008B8FC: lh          $v0, 0x1E($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X1E);
    // 0x8008B900: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008B904: jr          $ra
    // 0x8008B908: nop

    return;
    // 0x8008B908: nop

;}
RECOMP_FUNC void _ncpoddialog_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800895E8: syscall     784
    recomp_syscall_handler(rdram, ctx, 0x800895E8);
    return;
    // 0x800895EC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800DA0D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DA0D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DA0DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DA0E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800DA0E4: jal         0x800DA054
    // 0x800DA0E8: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    func_800DA054(rdram, ctx);
        goto after_0;
    // 0x800DA0E8: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_0:
    // 0x800DA0EC: jal         0x800888B8
    // 0x800DA0F0: nop

    _gldbDll_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x800DA0F0: nop

    after_1:
    // 0x800DA0F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DA0F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DA0FC: jr          $ra
    // 0x800DA100: nop

    return;
    // 0x800DA100: nop

;}
RECOMP_FUNC void func_8080000C_chklungoleave(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800018: jal         0x80105A9C
    // 0x8080001C: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    func_80105A9C(rdram, ctx);
        goto after_0;
    // 0x8080001C: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    after_0:
    // 0x80800020: jal         0x80105BAC
    // 0x80800024: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80105BAC(rdram, ctx);
        goto after_1;
    // 0x80800024: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080002C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800030: jr          $ra
    // 0x80800034: nop

    return;
    // 0x80800034: nop

;}
RECOMP_FUNC void func_80800094_chhoopswoop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800094: addiu       $sp, $sp, -0x1E0
    ctx->r29 = ADD32(ctx->r29, -0X1E0);
    // 0x80800098: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8080009C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x808000A0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x808000A4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x808000A8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x808000AC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000B0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808000B4: jal         0x80100094
    // 0x808000B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808000B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808000BC: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x808000C0: addiu       $a0, $zero, 0x154
    ctx->r4 = ADD32(0, 0X154);
    // 0x808000C4: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x808000C8: jal         0x800882C0
    // 0x808000CC: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    _gccubesearch_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x808000CC: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    after_1:
    // 0x808000D0: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    // 0x808000D4: blez        $v0, L_80800148
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808000D8: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80800148;
    }
    // 0x808000D8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x808000DC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x808000E0: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x808000E4: addiu       $s3, $s4, 0x16
    ctx->r19 = ADD32(ctx->r20, 0X16);
    // 0x808000E8: addiu       $s1, $sp, 0x50
    ctx->r17 = ADD32(ctx->r29, 0X50);
    // 0x808000EC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_808000F0:
    // 0x808000F0: jal         0x800EE814
    // 0x808000F4: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    func_800EE814(rdram, ctx);
        goto after_2;
    // 0x808000F4: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    after_2:
    // 0x808000F8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x808000FC: lh          $t3, 0x14($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X14);
    // 0x80800100: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800104: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80800108: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x8080010C: swc1        $f20, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f20.u32l;
    // 0x80800110: srl         $t0, $t7, 23
    ctx->r8 = S32(U32(ctx->r15) >> 23);
    // 0x80800114: sll         $t2, $t0, 1
    ctx->r10 = S32(ctx->r8 << 1);
    // 0x80800118: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x8080011C: sh          $t5, 0x14($s0)
    MEM_H(0X14, ctx->r16) = ctx->r13;
    // 0x80800120: lbu         $t6, 0x15($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X15);
    // 0x80800124: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80800128: addiu       $s3, $s3, 0xC
    ctx->r19 = ADD32(ctx->r19, 0XC);
    // 0x8080012C: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x80800130: sb          $t7, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r15;
    // 0x80800134: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x80800138: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8080013C: slt         $at, $s2, $t8
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80800140: bnel        $at, $zero, L_808000F0
    if (ctx->r1 != 0) {
        // 0x80800144: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_808000F0;
    }
    goto skip_0;
    // 0x80800144: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_0:
L_80800148:
    // 0x80800148: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8080014C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800150: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800154: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80800158: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8080015C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80800160: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80800164: jr          $ra
    // 0x80800168: addiu       $sp, $sp, 0x1E0
    ctx->r29 = ADD32(ctx->r29, 0X1E0);
    return;
    // 0x80800168: addiu       $sp, $sp, 0x1E0
    ctx->r29 = ADD32(ctx->r29, 0X1E0);
;}
RECOMP_FUNC void func_80800000_bsmumstill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080000C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800014: jal         0x8009EF10
    // 0x80800018: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    bastick_getZone(rdram, ctx);
        goto after_0;
    // 0x80800018: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    after_0:
    // 0x8080001C: beq         $v0, $zero, L_8080004C
    if (ctx->r2 == 0) {
        // 0x80800020: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080004C;
    }
    // 0x80800020: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800024: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800028: beq         $v0, $at, L_80800040
    if (ctx->r2 == ctx->r1) {
        // 0x8080002C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800040;
    }
    // 0x8080002C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800030: beql        $v0, $at, L_8080004C
    if (ctx->r2 == ctx->r1) {
        // 0x80800034: addiu       $s1, $zero, 0xE7
        ctx->r17 = ADD32(0, 0XE7);
            goto L_8080004C;
    }
    goto skip_0;
    // 0x80800034: addiu       $s1, $zero, 0xE7
    ctx->r17 = ADD32(0, 0XE7);
    skip_0:
    // 0x80800038: b           L_8080004C
    // 0x8080003C: nop

        goto L_8080004C;
    // 0x8080003C: nop

L_80800040:
    // 0x80800040: b           L_8080004C
    // 0x80800044: addiu       $s1, $zero, 0xE6
    ctx->r17 = ADD32(0, 0XE6);
        goto L_8080004C;
    // 0x80800044: addiu       $s1, $zero, 0xE6
    ctx->r17 = ADD32(0, 0XE6);
    // 0x80800048: addiu       $s1, $zero, 0xE7
    ctx->r17 = ADD32(0, 0XE7);
L_8080004C:
    // 0x8080004C: jal         0x80091A58
    // 0x80800050: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_1;
    // 0x80800050: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_1:
    // 0x80800054: beq         $v0, $zero, L_80800060
    if (ctx->r2 == 0) {
        // 0x80800058: nop
    
            goto L_80800060;
    }
    // 0x80800058: nop

    // 0x8080005C: addiu       $s1, $zero, 0xE8
    ctx->r17 = ADD32(0, 0XE8);
L_80800060:
    // 0x80800060: jal         0x80097AD0
    // 0x80800064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_enter_first_person(rdram, ctx);
        goto after_2;
    // 0x80800064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800068: beq         $v0, $zero, L_8080007C
    if (ctx->r2 == 0) {
        // 0x8080006C: nop
    
            goto L_8080007C;
    }
    // 0x8080006C: nop

    // 0x80800070: jal         0x800848A8
    // 0x80800074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_24(rdram, ctx);
        goto after_3;
    // 0x80800074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800078: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_8080007C:
    // 0x8080007C: jal         0x8008E148
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E148(rdram, ctx);
        goto after_4;
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800084: beql        $v0, $zero, L_8080009C
    if (ctx->r2 == 0) {
        // 0x80800088: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080009C;
    }
    goto skip_1;
    // 0x80800088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x8080008C: jal         0x800848B0
    // 0x80800090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_25(rdram, ctx);
        goto after_5;
    // 0x80800090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800094: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080009C:
    // 0x8080009C: jal         0x80091A58
    // 0x808000A0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_6;
    // 0x808000A0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_6:
    // 0x808000A4: beq         $v0, $zero, L_808000B0
    if (ctx->r2 == 0) {
        // 0x808000A8: nop
    
            goto L_808000B0;
    }
    // 0x808000A8: nop

    // 0x808000AC: addiu       $s1, $zero, 0xF7
    ctx->r17 = ADD32(0, 0XF7);
L_808000B0:
    // 0x808000B0: jal         0x8008DD04
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD04(rdram, ctx);
        goto after_7;
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808000B8: beq         $v0, $zero, L_808000C4
    if (ctx->r2 == 0) {
        // 0x808000BC: nop
    
            goto L_808000C4;
    }
    // 0x808000BC: nop

    // 0x808000C0: addiu       $s1, $zero, 0xE9
    ctx->r17 = ADD32(0, 0XE9);
L_808000C4:
    // 0x808000C4: jal         0x8008E35C
    // 0x808000C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_8;
    // 0x808000C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808000CC: beq         $v0, $zero, L_808000D8
    if (ctx->r2 == 0) {
        // 0x808000D0: lw          $s0, 0x14($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X14);
            goto L_808000D8;
    }
    // 0x808000D0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808000D4: addiu       $s1, $zero, 0xF0
    ctx->r17 = ADD32(0, 0XF0);
L_808000D8:
    // 0x808000D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000DC: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x808000E0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808000E4: jr          $ra
    // 0x808000E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808000E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void baduo_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A78: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800A7C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800A80: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800A84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A88: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800A8C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800A90: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800A94: jal         0x800F6224
    // 0x80800A98: lw          $a0, 0x184($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X184);
    func_800F6224(rdram, ctx);
        goto after_0;
    // 0x80800A98: lw          $a0, 0x184($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X184);
    after_0:
    // 0x80800A9C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800AA0: jal         0x800F53D0
    // 0x80800AA4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F53D0(rdram, ctx);
        goto after_1;
    // 0x80800AA4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800AA8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800AAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800AB0: jal         0x800F452C
    // 0x80800AB4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800F452C(rdram, ctx);
        goto after_2;
    // 0x80800AB4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x80800AB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800ABC: jal         0x80800008
    // 0x80800AC0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80800008_baduo(rdram, ctx);
        goto after_3;
    // 0x80800AC0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x80800AC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AC8: jal         0x800A3410
    // 0x80800ACC: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_800A3410(rdram, ctx);
        goto after_4;
    // 0x80800ACC: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_4:
    // 0x80800AD0: jal         0x80092778
    // 0x80800AD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80092778(rdram, ctx);
        goto after_5;
    // 0x80800AD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800AD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800ADC: jal         0x8009C914
    // 0x80800AE0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    yaw_setIdeal(rdram, ctx);
        goto after_6;
    // 0x80800AE0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_6:
    // 0x80800AE4: jal         0x8009C974
    // 0x80800AE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_applyIdeal(rdram, ctx);
        goto after_7;
    // 0x80800AE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800AEC: jal         0x80083B98
    // 0x80800AF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    _bsstatue_entrypoint_1(rdram, ctx);
        goto after_8;
    // 0x80800AF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x80800AF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AF8: jal         0x8009E5C8
    // 0x80800AFC: addiu       $a1, $zero, 0xF9
    ctx->r5 = ADD32(0, 0XF9);
    bs_setState(rdram, ctx);
        goto after_9;
    // 0x80800AFC: addiu       $a1, $zero, 0xF9
    ctx->r5 = ADD32(0, 0XF9);
    after_9:
    // 0x80800B00: jal         0x800F8128
    // 0x80800B04: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800F8128(rdram, ctx);
        goto after_10;
    // 0x80800B04: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_10:
    // 0x80800B08: jal         0x800F8EE4
    // 0x80800B0C: lw          $a0, 0x184($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X184);
    func_800F8EE4(rdram, ctx);
        goto after_11;
    // 0x80800B0C: lw          $a0, 0x184($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X184);
    after_11:
    // 0x80800B10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800B14: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800B18: jal         0x800F45B0
    // 0x80800B1C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_800F45B0(rdram, ctx);
        goto after_12;
    // 0x80800B1C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_12:
    // 0x80800B20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800B24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800B28: jal         0x800A38F0
    // 0x80800B2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800A38F0(rdram, ctx);
        goto after_13;
    // 0x80800B2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_13:
    // 0x80800B30: addiu       $a0, $zero, 0x50
    ctx->r4 = ADD32(0, 0X50);
    // 0x80800B34: jal         0x8008A298
    // 0x80800B38: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    _sudialog_entrypoint_0(rdram, ctx);
        goto after_14;
    // 0x80800B38: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_14:
    // 0x80800B3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B40: jal         0x80800C78
    // 0x80800B44: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_80800C78_baduo(rdram, ctx);
        goto after_15;
    // 0x80800B44: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_15:
    // 0x80800B48: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800B4C: jal         0x80800CA8
    // 0x80800B50: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80800CA8_baduo(rdram, ctx);
        goto after_16;
    // 0x80800B50: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_16:
    // 0x80800B54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B58: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800B5C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800B60: jr          $ra
    // 0x80800B64: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800B64: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _bsstonehead_entrypoint_37(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083D08: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083D08);
    return;
    // 0x80083D0C: addi        $t0, $zero, 0x94
    ctx->r8 = ADD32(0, 0X94);
;}
RECOMP_FUNC void func_80092EB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092EB0: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x80092EB4: jr          $ra
    // 0x80092EB8: lbu         $v0, 0x18($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X18);
    return;
    // 0x80092EB8: lbu         $v0, 0x18($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X18);
;}
RECOMP_FUNC void func_808001E4_bsdronevanish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808001F0: lw          $t7, 0x188($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X188);
    // 0x808001F4: jal         0x800B5450
    // 0x808001F8: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    func_800B5450(rdram, ctx);
        goto after_0;
    // 0x808001F8: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    after_0:
    // 0x808001FC: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80800200: lw          $t9, 0x188($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X188);
    // 0x80800204: jal         0x800B5450
    // 0x80800208: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    func_800B5450(rdram, ctx);
        goto after_1;
    // 0x80800208: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_1:
    // 0x8080020C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800210: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800214: jr          $ra
    // 0x80800218: nop

    return;
    // 0x80800218: nop

;}
RECOMP_FUNC void func_80800978_chbilldrillplate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800978: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080097C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800980: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800984: jal         0x800EA05C
    // 0x80800988: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800988: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080098C: addiu       $at, $zero, 0x101
    ctx->r1 = ADD32(0, 0X101);
    // 0x80800990: beq         $v0, $at, L_808009A8
    if (ctx->r2 == ctx->r1) {
        // 0x80800994: addiu       $at, $zero, 0x107
        ctx->r1 = ADD32(0, 0X107);
            goto L_808009A8;
    }
    // 0x80800994: addiu       $at, $zero, 0x107
    ctx->r1 = ADD32(0, 0X107);
    // 0x80800998: beql        $v0, $at, L_80800AA0
    if (ctx->r2 == ctx->r1) {
        // 0x8080099C: lui         $at, 0x4302
        ctx->r1 = S32(0X4302 << 16);
            goto L_80800AA0;
    }
    goto skip_0;
    // 0x8080099C: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    skip_0:
    // 0x808009A0: b           L_80800B8C
    // 0x808009A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800B8C;
    // 0x808009A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808009A8:
    // 0x808009A8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808009AC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808009B0: addiu       $s0, $sp, 0x34
    ctx->r16 = ADD32(ctx->r29, 0X34);
    // 0x808009B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009B8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808009BC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808009C0: jal         0x800EFA4C
    // 0x808009C4: lui         $a2, 0x43F0
    ctx->r6 = S32(0X43F0 << 16);
    func_800EFA4C(rdram, ctx);
        goto after_1;
    // 0x808009C4: lui         $a2, 0x43F0
    ctx->r6 = S32(0X43F0 << 16);
    after_1:
    // 0x808009C8: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x808009CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009D0: jal         0x800EF04C
    // 0x808009D4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_2;
    // 0x808009D4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_2:
    // 0x808009D8: addiu       $a0, $zero, 0x473
    ctx->r4 = ADD32(0, 0X473);
    // 0x808009DC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808009E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808009E4: jal         0x80108528
    // 0x808009E8: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    func_80108528(rdram, ctx);
        goto after_3;
    // 0x808009E8: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    after_3:
    // 0x808009EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009F0: lui         $a1, 0xC334
    ctx->r5 = S32(0XC334 << 16);
    // 0x808009F4: lui         $a2, 0x43F0
    ctx->r6 = S32(0X43F0 << 16);
    // 0x808009F8: jal         0x800EFA4C
    // 0x808009FC: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    func_800EFA4C(rdram, ctx);
        goto after_4;
    // 0x808009FC: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    after_4:
    // 0x80800A00: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80800A04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A08: jal         0x800EF04C
    // 0x80800A0C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_5;
    // 0x80800A0C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_5:
    // 0x80800A10: addiu       $a0, $zero, 0x473
    ctx->r4 = ADD32(0, 0X473);
    // 0x80800A14: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800A18: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800A1C: jal         0x80108528
    // 0x80800A20: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    func_80108528(rdram, ctx);
        goto after_6;
    // 0x80800A20: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    after_6:
    // 0x80800A24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A28: lui         $a1, 0x4334
    ctx->r5 = S32(0X4334 << 16);
    // 0x80800A2C: lui         $a2, 0x43F0
    ctx->r6 = S32(0X43F0 << 16);
    // 0x80800A30: jal         0x800EFA4C
    // 0x80800A34: lui         $a3, 0xC334
    ctx->r7 = S32(0XC334 << 16);
    func_800EFA4C(rdram, ctx);
        goto after_7;
    // 0x80800A34: lui         $a3, 0xC334
    ctx->r7 = S32(0XC334 << 16);
    after_7:
    // 0x80800A38: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80800A3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A40: jal         0x800EF04C
    // 0x80800A44: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_8;
    // 0x80800A44: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_8:
    // 0x80800A48: addiu       $a0, $zero, 0x473
    ctx->r4 = ADD32(0, 0X473);
    // 0x80800A4C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800A50: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800A54: jal         0x80108528
    // 0x80800A58: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    func_80108528(rdram, ctx);
        goto after_9;
    // 0x80800A58: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    after_9:
    // 0x80800A5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A60: lui         $a1, 0xC334
    ctx->r5 = S32(0XC334 << 16);
    // 0x80800A64: lui         $a2, 0x43F0
    ctx->r6 = S32(0X43F0 << 16);
    // 0x80800A68: jal         0x800EFA4C
    // 0x80800A6C: lui         $a3, 0xC334
    ctx->r7 = S32(0XC334 << 16);
    func_800EFA4C(rdram, ctx);
        goto after_10;
    // 0x80800A6C: lui         $a3, 0xC334
    ctx->r7 = S32(0XC334 << 16);
    after_10:
    // 0x80800A70: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80800A74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A78: jal         0x800EF04C
    // 0x80800A7C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_11;
    // 0x80800A7C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_11:
    // 0x80800A80: addiu       $a0, $zero, 0x473
    ctx->r4 = ADD32(0, 0X473);
    // 0x80800A84: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800A88: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800A8C: jal         0x80108528
    // 0x80800A90: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    func_80108528(rdram, ctx);
        goto after_12;
    // 0x80800A90: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    after_12:
    // 0x80800A94: b           L_80800B8C
    // 0x80800A98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800B8C;
    // 0x80800A98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A9C: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
L_80800AA0:
    // 0x80800AA0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800AA4: addiu       $s0, $sp, 0x28
    ctx->r16 = ADD32(ctx->r29, 0X28);
    // 0x80800AA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AAC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800AB0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800AB4: jal         0x800EFA4C
    // 0x80800AB8: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    func_800EFA4C(rdram, ctx);
        goto after_13;
    // 0x80800AB8: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    after_13:
    // 0x80800ABC: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80800AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AC4: jal         0x800EF04C
    // 0x80800AC8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_14;
    // 0x80800AC8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_14:
    // 0x80800ACC: addiu       $a0, $zero, 0x473
    ctx->r4 = ADD32(0, 0X473);
    // 0x80800AD0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800AD4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800AD8: jal         0x80108528
    // 0x80800ADC: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    func_80108528(rdram, ctx);
        goto after_15;
    // 0x80800ADC: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    after_15:
    // 0x80800AE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AE4: lui         $a1, 0xC302
    ctx->r5 = S32(0XC302 << 16);
    // 0x80800AE8: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    // 0x80800AEC: jal         0x800EFA4C
    // 0x80800AF0: lui         $a3, 0x4302
    ctx->r7 = S32(0X4302 << 16);
    func_800EFA4C(rdram, ctx);
        goto after_16;
    // 0x80800AF0: lui         $a3, 0x4302
    ctx->r7 = S32(0X4302 << 16);
    after_16:
    // 0x80800AF4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80800AF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AFC: jal         0x800EF04C
    // 0x80800B00: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_17;
    // 0x80800B00: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_17:
    // 0x80800B04: addiu       $a0, $zero, 0x473
    ctx->r4 = ADD32(0, 0X473);
    // 0x80800B08: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800B0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800B10: jal         0x80108528
    // 0x80800B14: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    func_80108528(rdram, ctx);
        goto after_18;
    // 0x80800B14: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    after_18:
    // 0x80800B18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B1C: lui         $a1, 0x4302
    ctx->r5 = S32(0X4302 << 16);
    // 0x80800B20: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    // 0x80800B24: jal         0x800EFA4C
    // 0x80800B28: lui         $a3, 0xC302
    ctx->r7 = S32(0XC302 << 16);
    func_800EFA4C(rdram, ctx);
        goto after_19;
    // 0x80800B28: lui         $a3, 0xC302
    ctx->r7 = S32(0XC302 << 16);
    after_19:
    // 0x80800B2C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80800B30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B34: jal         0x800EF04C
    // 0x80800B38: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_20;
    // 0x80800B38: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_20:
    // 0x80800B3C: addiu       $a0, $zero, 0x473
    ctx->r4 = ADD32(0, 0X473);
    // 0x80800B40: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800B44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800B48: jal         0x80108528
    // 0x80800B4C: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    func_80108528(rdram, ctx);
        goto after_21;
    // 0x80800B4C: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    after_21:
    // 0x80800B50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B54: lui         $a1, 0xC302
    ctx->r5 = S32(0XC302 << 16);
    // 0x80800B58: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    // 0x80800B5C: jal         0x800EFA4C
    // 0x80800B60: lui         $a3, 0xC302
    ctx->r7 = S32(0XC302 << 16);
    func_800EFA4C(rdram, ctx);
        goto after_22;
    // 0x80800B60: lui         $a3, 0xC302
    ctx->r7 = S32(0XC302 << 16);
    after_22:
    // 0x80800B64: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80800B68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B6C: jal         0x800EF04C
    // 0x80800B70: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_23;
    // 0x80800B70: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_23:
    // 0x80800B74: addiu       $a0, $zero, 0x473
    ctx->r4 = ADD32(0, 0X473);
    // 0x80800B78: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800B7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800B80: jal         0x80108528
    // 0x80800B84: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    func_80108528(rdram, ctx);
        goto after_24;
    // 0x80800B84: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    after_24:
    // 0x80800B88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800B8C:
    // 0x80800B8C: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x80800B90: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800B94: jr          $ra
    // 0x80800B98: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80800B98: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_801168F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801168F0: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x801168F4: addiu       $t6, $t6, 0x1000
    ctx->r14 = ADD32(ctx->r14, 0X1000);
    // 0x801168F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801168FC: sw          $t6, 0x4A8C($at)
    MEM_W(0X4A8C, ctx->r1) = ctx->r14;
    // 0x80116900: lui         $t7, 0x8001
    ctx->r15 = S32(0X8001 << 16);
    // 0x80116904: addiu       $t7, $t7, -0x1800
    ctx->r15 = ADD32(ctx->r15, -0X1800);
    // 0x80116908: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8011690C: jr          $ra
    // 0x80116910: sw          $t7, 0x4A80($at)
    MEM_W(0X4A80, ctx->r1) = ctx->r15;
    return;
    // 0x80116910: sw          $t7, 0x4A80($at)
    MEM_W(0X4A80, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void func_800F693C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F693C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F6940: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F6944: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F6948: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F694C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F6950: jal         0x8008DD70
    // 0x800F6954: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_8008DD70(rdram, ctx);
        goto after_0;
    // 0x800F6954: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F6958: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F695C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F6960: jr          $ra
    // 0x800F6964: nop

    return;
    // 0x800F6964: nop

;}
RECOMP_FUNC void func_80800980_chklungophial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800980: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800984: addiu       $at, $zero, 0x4F
    ctx->r1 = ADD32(0, 0X4F);
    // 0x80800988: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080098C: bne         $a1, $at, L_808009A4
    if (ctx->r5 != ctx->r1) {
        // 0x80800990: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_808009A4;
    }
    // 0x80800990: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800994: jal         0x80101FDC
    // 0x80800998: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_0;
    // 0x80800998: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x8080099C: b           L_808009AC
    // 0x808009A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808009AC;
    // 0x808009A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808009A4:
    // 0x808009A4: b           L_808009AC
    // 0x808009A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808009AC;
    // 0x808009A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808009AC:
    // 0x808009AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808009B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808009B4: jr          $ra
    // 0x808009B8: nop

    return;
    // 0x808009B8: nop

;}
RECOMP_FUNC void func_8001211C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001211C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80012120: jr          $ra
    // 0x80012124: lw          $v0, 0x59C8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X59C8);
    return;
    // 0x80012124: lw          $v0, 0x59C8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X59C8);
;}
RECOMP_FUNC void subaddierouteDll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004B4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808004B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004BC: lw          $t6, 0x70($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X70);
    // 0x808004C0: srl         $t7, $t6, 25
    ctx->r15 = S32(U32(ctx->r14) >> 25);
    // 0x808004C4: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x808004C8: jal         0x801015B0
    // 0x808004CC: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    func_801015B0(rdram, ctx);
        goto after_0;
    // 0x808004CC: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    after_0:
    // 0x808004D0: jal         0x8001B798
    // 0x808004D4: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    func_8001B798(rdram, ctx);
        goto after_1;
    // 0x808004D4: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    after_1:
    // 0x808004D8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808004DC: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x808004E0: addu        $v1, $v0, $t9
    ctx->r3 = ADD32(ctx->r2, ctx->r25);
    // 0x808004E4: lh          $t0, 0x2($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X2);
    // 0x808004E8: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x808004EC: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x808004F0: sh          $t1, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r9;
    // 0x808004F4: lh          $t2, 0x2($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X2);
    // 0x808004F8: bnel        $t2, $zero, L_80800518
    if (ctx->r10 != 0) {
        // 0x808004FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800518;
    }
    goto skip_0;
    // 0x808004FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800500: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x80800504: jal         0x8001B754
    // 0x80800508: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8001B754(rdram, ctx);
        goto after_2;
    // 0x80800508: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x8080050C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80800510: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x80800514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800518:
    // 0x80800518: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080051C: jr          $ra
    // 0x80800520: nop

    return;
    // 0x80800520: nop

;}
RECOMP_FUNC void _chanim_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085978: syscall     184
    recomp_syscall_handler(rdram, ctx, 0x80085978);
    return;
    // 0x8008597C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808058F0_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808058F0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808058F4: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x808058F8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808058FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80805900: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80805904: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80805908: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080590C: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    // 0x80805910: jal         0x80100094
    // 0x80805914: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80805914: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80805918: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x8080591C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80805920: slti        $at, $a2, 0x84
    ctx->r1 = SIGNED(ctx->r6) < 0X84 ? 1 : 0;
    // 0x80805924: bne         $at, $zero, L_8080594C
    if (ctx->r1 != 0) {
        // 0x80805928: addiu       $t6, $a2, -0xB
        ctx->r14 = ADD32(ctx->r6, -0XB);
            goto L_8080594C;
    }
    // 0x80805928: addiu       $t6, $a2, -0xB
    ctx->r14 = ADD32(ctx->r6, -0XB);
    // 0x8080592C: addiu       $at, $zero, 0x88
    ctx->r1 = ADD32(0, 0X88);
    // 0x80805930: beq         $a2, $at, L_80806318
    if (ctx->r6 == ctx->r1) {
        // 0x80805934: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80806318;
    }
    // 0x80805934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805938: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x8080593C: beq         $a2, $at, L_808059A4
    if (ctx->r6 == ctx->r1) {
        // 0x80805940: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_808059A4;
    }
    // 0x80805940: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80805944: b           L_808064E0
    // 0x80805948: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808064E0;
    // 0x80805948: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080594C:
    // 0x8080594C: slti        $at, $a2, 0x6D
    ctx->r1 = SIGNED(ctx->r6) < 0X6D ? 1 : 0;
    // 0x80805950: bne         $at, $zero, L_80805968
    if (ctx->r1 != 0) {
        // 0x80805954: addiu       $at, $zero, 0x83
        ctx->r1 = ADD32(0, 0X83);
            goto L_80805968;
    }
    // 0x80805954: addiu       $at, $zero, 0x83
    ctx->r1 = ADD32(0, 0X83);
    // 0x80805958: beql        $a2, $at, L_808062D8
    if (ctx->r6 == ctx->r1) {
        // 0x8080595C: lw          $v0, 0x34($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X34);
            goto L_808062D8;
    }
    goto skip_0;
    // 0x8080595C: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    skip_0:
    // 0x80805960: b           L_808064E0
    // 0x80805964: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808064E0;
    // 0x80805964: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80805968:
    // 0x80805968: slti        $at, $a2, 0x33
    ctx->r1 = SIGNED(ctx->r6) < 0X33 ? 1 : 0;
    // 0x8080596C: bne         $at, $zero, L_80805984
    if (ctx->r1 != 0) {
        // 0x80805970: addiu       $at, $zero, 0x6C
        ctx->r1 = ADD32(0, 0X6C);
            goto L_80805984;
    }
    // 0x80805970: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x80805974: beq         $a2, $at, L_808063D0
    if (ctx->r6 == ctx->r1) {
        // 0x80805978: nop
    
            goto L_808063D0;
    }
    // 0x80805978: nop

    // 0x8080597C: b           L_808064E0
    // 0x80805980: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808064E0;
    // 0x80805980: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80805984:
    // 0x80805984: sltiu       $at, $t6, 0x28
    ctx->r1 = ctx->r14 < 0X28 ? 1 : 0;
    // 0x80805988: beq         $at, $zero, L_808064DC
    if (ctx->r1 == 0) {
        // 0x8080598C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_808064DC;
    }
    // 0x8080598C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80805990: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X69D0) << 16);
    // 0x80805994: addu        $at, $at, $t6
    gpr jr_addend_8080599C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80805998: lw          $t6, 0x69D0($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2484, 0X69D0));
    // 0x8080599C: jr          $t6
    // 0x808059A0: nop

    switch (jr_addend_8080599C >> 2) {
        case 0: goto L_8080626C; break;
        case 1: goto L_808064DC; break;
        case 2: goto L_808064DC; break;
        case 3: goto L_808064DC; break;
        case 4: goto L_808064DC; break;
        case 5: goto L_808064DC; break;
        case 6: goto L_808064DC; break;
        case 7: goto L_808064DC; break;
        case 8: goto L_808064DC; break;
        case 9: goto L_808064DC; break;
        case 10: goto L_808064DC; break;
        case 11: goto L_808064DC; break;
        case 12: goto L_808064DC; break;
        case 13: goto L_808064DC; break;
        case 14: goto L_808064DC; break;
        case 15: goto L_808064DC; break;
        case 16: goto L_808064DC; break;
        case 17: goto L_808064DC; break;
        case 18: goto L_808064DC; break;
        case 19: goto L_808064DC; break;
        case 20: goto L_80806428; break;
        case 21: goto L_808062B8; break;
        case 22: goto L_808064DC; break;
        case 23: goto L_808064DC; break;
        case 24: goto L_808064DC; break;
        case 25: goto L_808064DC; break;
        case 26: goto L_808064DC; break;
        case 27: goto L_808064DC; break;
        case 28: goto L_808064DC; break;
        case 29: goto L_808064DC; break;
        case 30: goto L_80806494; break;
        case 31: goto L_808064AC; break;
        case 32: goto L_808064DC; break;
        case 33: goto L_808064DC; break;
        case 34: goto L_808064DC; break;
        case 35: goto L_80805DF8; break;
        case 36: goto L_80805C24; break;
        case 37: goto L_80805B40; break;
        case 38: goto L_808064DC; break;
        case 39: goto L_808064C0; break;
        default: switch_error(__func__, 0x8080599C, 0x808069D0);
    }
    // 0x808059A0: nop

L_808059A4:
    // 0x808059A4: jal         0x80800F34
    // 0x808059A8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    func_80800F34_chquiz(rdram, ctx);
        goto after_1;
    // 0x808059A8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_1:
    // 0x808059AC: jal         0x8008A7D0
    // 0x808059B0: nop

    _suquiz_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808059B0: nop

    after_2:
    // 0x808059B4: sltiu       $at, $v0, 0x6
    ctx->r1 = ctx->r2 < 0X6 ? 1 : 0;
    // 0x808059B8: beq         $at, $zero, L_80805B38
    if (ctx->r1 == 0) {
        // 0x808059BC: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_80805B38;
    }
    // 0x808059BC: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x808059C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X6A70) << 16);
    // 0x808059C4: addu        $at, $at, $t7
    gpr jr_addend_808059CC = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808059C8: lw          $t7, 0x6A70($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2484, 0X6A70));
    // 0x808059CC: jr          $t7
    // 0x808059D0: nop

    switch (jr_addend_808059CC >> 2) {
        case 0: goto L_80805A5C; break;
        case 1: goto L_80805B04; break;
        case 2: goto L_80805B18; break;
        case 3: goto L_80805B2C; break;
        case 4: goto L_80805B38; break;
        case 5: goto L_808059D4; break;
        default: switch_error(__func__, 0x808059CC, 0x80806A70);
    }
    // 0x808059D0: nop

L_808059D4:
    // 0x808059D4: jal         0x8008A7E0
    // 0x808059D8: nop

    _suquiz_entrypoint_5(rdram, ctx);
        goto after_3;
    // 0x808059D8: nop

    after_3:
    // 0x808059DC: beq         $v0, $zero, L_80805A44
    if (ctx->r2 == 0) {
        // 0x808059E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80805A44;
    }
    // 0x808059E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808059E4: jal         0x8008A7E8
    // 0x808059E8: nop

    _suquiz_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x808059E8: nop

    after_4:
    // 0x808059EC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x808059F0: bne         $v0, $at, L_80805A0C
    if (ctx->r2 != ctx->r1) {
        // 0x808059F4: addiu       $a0, $zero, 0x529
        ctx->r4 = ADD32(0, 0X529);
            goto L_80805A0C;
    }
    // 0x808059F4: addiu       $a0, $zero, 0x529
    ctx->r4 = ADD32(0, 0X529);
    // 0x808059F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808059FC: jal         0x80804170
    // 0x80805A00: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    func_80804170_chquiz(rdram, ctx);
        goto after_5;
    // 0x80805A00: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_5:
    // 0x80805A04: b           L_808064E0
    // 0x80805A08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805A08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805A0C:
    // 0x80805A0C: addiu       $a1, $zero, 0x89
    ctx->r5 = ADD32(0, 0X89);
    // 0x80805A10: jal         0x80101180
    // 0x80805A14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_6;
    // 0x80805A14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80805A18: jal         0x8008A7F8
    // 0x80805A1C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _suquiz_entrypoint_8(rdram, ctx);
        goto after_7;
    // 0x80805A1C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x80805A20: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80805A24: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80805A28: jal         0x808016F8
    // 0x80805A2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808016F8_chquiz(rdram, ctx);
        goto after_8;
    // 0x80805A2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80805A30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805A34: jal         0x80804170
    // 0x80805A38: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_80804170_chquiz(rdram, ctx);
        goto after_9;
    // 0x80805A38: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_9:
    // 0x80805A3C: b           L_808064E0
    // 0x80805A40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805A40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805A44:
    // 0x80805A44: jal         0x80804170
    // 0x80805A48: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_80804170_chquiz(rdram, ctx);
        goto after_10;
    // 0x80805A48: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_10:
    // 0x80805A4C: jal         0x8008A850
    // 0x80805A50: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _suquiz_entrypoint_19(rdram, ctx);
        goto after_11;
    // 0x80805A50: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_11:
    // 0x80805A54: b           L_808064E0
    // 0x80805A58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805A58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805A5C:
    // 0x80805A5C: jal         0x800D395C
    // 0x80805A60: nop

    func_800D395C(rdram, ctx);
        goto after_12;
    // 0x80805A60: nop

    after_12:
    // 0x80805A64: beq         $v0, $zero, L_80805AD0
    if (ctx->r2 == 0) {
        // 0x80805A68: nop
    
            goto L_80805AD0;
    }
    // 0x80805A68: nop

    // 0x80805A6C: jal         0x800D3D04
    // 0x80805A70: nop

    func_800D3D04(rdram, ctx);
        goto after_13;
    // 0x80805A70: nop

    after_13:
    // 0x80805A74: addiu       $at, $zero, 0x74
    ctx->r1 = ADD32(0, 0X74);
    // 0x80805A78: beq         $v0, $at, L_80805AA0
    if (ctx->r2 == ctx->r1) {
        // 0x80805A7C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80805AA0;
    }
    // 0x80805A7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805A80: addiu       $at, $zero, 0x75
    ctx->r1 = ADD32(0, 0X75);
    // 0x80805A84: beq         $v0, $at, L_80805AB0
    if (ctx->r2 == ctx->r1) {
        // 0x80805A88: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80805AB0;
    }
    // 0x80805A88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805A8C: addiu       $at, $zero, 0x76
    ctx->r1 = ADD32(0, 0X76);
    // 0x80805A90: beq         $v0, $at, L_80805AC0
    if (ctx->r2 == ctx->r1) {
        // 0x80805A94: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80805AC0;
    }
    // 0x80805A94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805A98: b           L_808064E0
    // 0x80805A9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805A9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805AA0:
    // 0x80805AA0: jal         0x80804170
    // 0x80805AA4: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    func_80804170_chquiz(rdram, ctx);
        goto after_14;
    // 0x80805AA4: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    after_14:
    // 0x80805AA8: b           L_808064E0
    // 0x80805AAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805AAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805AB0:
    // 0x80805AB0: jal         0x80804170
    // 0x80805AB4: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    func_80804170_chquiz(rdram, ctx);
        goto after_15;
    // 0x80805AB4: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    after_15:
    // 0x80805AB8: b           L_808064E0
    // 0x80805ABC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805ABC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805AC0:
    // 0x80805AC0: jal         0x80804170
    // 0x80805AC4: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    func_80804170_chquiz(rdram, ctx);
        goto after_16;
    // 0x80805AC4: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_16:
    // 0x80805AC8: b           L_808064E0
    // 0x80805ACC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805ACC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805AD0:
    // 0x80805AD0: jal         0x800D3948
    // 0x80805AD4: nop

    func_800D3948(rdram, ctx);
        goto after_17;
    // 0x80805AD4: nop

    after_17:
    // 0x80805AD8: beq         $v0, $zero, L_80805AF4
    if (ctx->r2 == 0) {
        // 0x80805ADC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80805AF4;
    }
    // 0x80805ADC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805AE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805AE4: jal         0x80804170
    // 0x80805AE8: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    func_80804170_chquiz(rdram, ctx);
        goto after_18;
    // 0x80805AE8: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    after_18:
    // 0x80805AEC: b           L_808064E0
    // 0x80805AF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805AF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805AF4:
    // 0x80805AF4: jal         0x80804170
    // 0x80805AF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80804170_chquiz(rdram, ctx);
        goto after_19;
    // 0x80805AF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x80805AFC: b           L_808064E0
    // 0x80805B00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805B00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805B04:
    // 0x80805B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805B08: jal         0x80804170
    // 0x80805B0C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80804170_chquiz(rdram, ctx);
        goto after_20;
    // 0x80805B0C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_20:
    // 0x80805B10: b           L_808064E0
    // 0x80805B14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805B14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805B18:
    // 0x80805B18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805B1C: jal         0x80804170
    // 0x80805B20: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80804170_chquiz(rdram, ctx);
        goto after_21;
    // 0x80805B20: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_21:
    // 0x80805B24: b           L_808064E0
    // 0x80805B28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805B28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805B2C:
    // 0x80805B2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805B30: jal         0x80804170
    // 0x80805B34: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80804170_chquiz(rdram, ctx);
        goto after_22;
    // 0x80805B34: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_22:
L_80805B38:
    // 0x80805B38: b           L_808064E0
    // 0x80805B3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805B3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805B40:
    // 0x80805B40: addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // 0x80805B44: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80805B48: slti        $at, $a1, 0x14C7
    ctx->r1 = SIGNED(ctx->r5) < 0X14C7 ? 1 : 0;
    // 0x80805B4C: bne         $at, $zero, L_80805B68
    if (ctx->r1 != 0) {
        // 0x80805B50: addiu       $t8, $a1, -0x148B
        ctx->r24 = ADD32(ctx->r5, -0X148B);
            goto L_80805B68;
    }
    // 0x80805B50: addiu       $t8, $a1, -0x148B
    ctx->r24 = ADD32(ctx->r5, -0X148B);
    // 0x80805B54: addiu       $at, $zero, 0x14D9
    ctx->r1 = ADD32(0, 0X14D9);
    // 0x80805B58: beq         $a1, $at, L_80805BC4
    if (ctx->r5 == ctx->r1) {
        // 0x80805B5C: nop
    
            goto L_80805BC4;
    }
    // 0x80805B5C: nop

    // 0x80805B60: b           L_808064E0
    // 0x80805B64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808064E0;
    // 0x80805B64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80805B68:
    // 0x80805B68: slti        $at, $a1, 0x1495
    ctx->r1 = SIGNED(ctx->r5) < 0X1495 ? 1 : 0;
    // 0x80805B6C: bne         $at, $zero, L_80805B84
    if (ctx->r1 != 0) {
        // 0x80805B70: addiu       $at, $zero, 0x14C6
        ctx->r1 = ADD32(0, 0X14C6);
            goto L_80805B84;
    }
    // 0x80805B70: addiu       $at, $zero, 0x14C6
    ctx->r1 = ADD32(0, 0X14C6);
    // 0x80805B74: beq         $a1, $at, L_80805BB4
    if (ctx->r5 == ctx->r1) {
        // 0x80805B78: nop
    
            goto L_80805BB4;
    }
    // 0x80805B78: nop

    // 0x80805B7C: b           L_808064E0
    // 0x80805B80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808064E0;
    // 0x80805B80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80805B84:
    // 0x80805B84: sltiu       $at, $t8, 0xA
    ctx->r1 = ctx->r24 < 0XA ? 1 : 0;
    // 0x80805B88: beq         $at, $zero, L_80805C1C
    if (ctx->r1 == 0) {
        // 0x80805B8C: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80805C1C;
    }
    // 0x80805B8C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80805B90: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X6A88) << 16);
    // 0x80805B94: addu        $at, $at, $t8
    gpr jr_addend_80805B9C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80805B98: lw          $t8, 0x6A88($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2484, 0X6A88));
    // 0x80805B9C: jr          $t8
    // 0x80805BA0: nop

    switch (jr_addend_80805B9C >> 2) {
        case 0: goto L_80805BA4; break;
        case 1: goto L_80805BA4; break;
        case 2: goto L_80805BA4; break;
        case 3: goto L_80805C1C; break;
        case 4: goto L_80805C1C; break;
        case 5: goto L_80805C1C; break;
        case 6: goto L_80805C1C; break;
        case 7: goto L_80805C1C; break;
        case 8: goto L_80805BD4; break;
        case 9: goto L_80805C0C; break;
        default: switch_error(__func__, 0x80805B9C, 0x80806A88);
    }
    // 0x80805BA0: nop

L_80805BA4:
    // 0x80805BA4: jal         0x80801B7C
    // 0x80805BA8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80801B7C_chquiz(rdram, ctx);
        goto after_23;
    // 0x80805BA8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_23:
    // 0x80805BAC: b           L_808064E4
    // 0x80805BB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808064E4;
    // 0x80805BB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80805BB4:
    // 0x80805BB4: jal         0x800883A0
    // 0x80805BB8: nop

    _gcstatusDll_entrypoint_18(rdram, ctx);
        goto after_24;
    // 0x80805BB8: nop

    after_24:
    // 0x80805BBC: b           L_808064E4
    // 0x80805BC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808064E4;
    // 0x80805BC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80805BC4:
    // 0x80805BC4: jal         0x80088398
    // 0x80805BC8: nop

    _gcstatusDll_entrypoint_17(rdram, ctx);
        goto after_25;
    // 0x80805BC8: nop

    after_25:
    // 0x80805BCC: b           L_808064E4
    // 0x80805BD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808064E4;
    // 0x80805BD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80805BD4:
    // 0x80805BD4: lh          $t9, 0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2);
    // 0x80805BD8: beq         $t9, $zero, L_80805BFC
    if (ctx->r25 == 0) {
        // 0x80805BDC: nop
    
            goto L_80805BFC;
    }
    // 0x80805BDC: nop

    // 0x80805BE0: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x80805BE4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80805BE8: andi        $t0, $a1, 0x1FF
    ctx->r8 = ctx->r5 & 0X1FF;
    // 0x80805BEC: jal         0x80801784
    // 0x80805BF0: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    func_80801784_chquiz(rdram, ctx);
        goto after_26;
    // 0x80805BF0: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    after_26:
    // 0x80805BF4: b           L_808064E4
    // 0x80805BF8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808064E4;
    // 0x80805BF8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80805BFC:
    // 0x80805BFC: jal         0x80088398
    // 0x80805C00: nop

    _gcstatusDll_entrypoint_17(rdram, ctx);
        goto after_27;
    // 0x80805C00: nop

    after_27:
    // 0x80805C04: b           L_808064E4
    // 0x80805C08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808064E4;
    // 0x80805C08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80805C0C:
    // 0x80805C0C: jal         0x800883A0
    // 0x80805C10: nop

    _gcstatusDll_entrypoint_18(rdram, ctx);
        goto after_28;
    // 0x80805C10: nop

    after_28:
    // 0x80805C14: b           L_808064E4
    // 0x80805C18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808064E4;
    // 0x80805C18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80805C1C:
    // 0x80805C1C: b           L_808064E0
    // 0x80805C20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808064E0;
    // 0x80805C20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80805C24:
    // 0x80805C24: addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // 0x80805C28: lh          $t1, 0x2($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X2);
    // 0x80805C2C: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80805C30: sltiu       $at, $t2, 0xD
    ctx->r1 = ctx->r10 < 0XD ? 1 : 0;
    // 0x80805C34: beq         $at, $zero, L_80805DF0
    if (ctx->r1 == 0) {
        // 0x80805C38: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_80805DF0;
    }
    // 0x80805C38: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80805C3C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X6AB0) << 16);
    // 0x80805C40: addu        $at, $at, $t2
    gpr jr_addend_80805C48 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80805C44: lw          $t2, 0x6AB0($at)
    ctx->r10 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2484, 0X6AB0));
    // 0x80805C48: jr          $t2
    // 0x80805C4C: nop

    switch (jr_addend_80805C48 >> 2) {
        case 0: goto L_80805C50; break;
        case 1: goto L_80805C64; break;
        case 2: goto L_80805C7C; break;
        case 3: goto L_80805C94; break;
        case 4: goto L_80805CAC; break;
        case 5: goto L_80805CC4; break;
        case 6: goto L_80805CD8; break;
        case 7: goto L_80805D00; break;
        case 8: goto L_80805D28; break;
        case 9: goto L_80805D50; break;
        case 10: goto L_80805D78; break;
        case 11: goto L_80805DA0; break;
        case 12: goto L_80805DC8; break;
        default: switch_error(__func__, 0x80805C48, 0x80806AB0);
    }
    // 0x80805C4C: nop

L_80805C50:
    // 0x80805C50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805C54: jal         0x80804170
    // 0x80805C58: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    func_80804170_chquiz(rdram, ctx);
        goto after_29;
    // 0x80805C58: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_29:
    // 0x80805C5C: b           L_808064E0
    // 0x80805C60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805C60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805C64:
    // 0x80805C64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805C68: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80805C6C: jal         0x8080100C
    // 0x80805C70: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    func_8080100C_chquiz(rdram, ctx);
        goto after_30;
    // 0x80805C70: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    after_30:
    // 0x80805C74: b           L_808064E0
    // 0x80805C78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805C78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805C7C:
    // 0x80805C7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805C80: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80805C84: jal         0x8080100C
    // 0x80805C88: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    func_8080100C_chquiz(rdram, ctx);
        goto after_31;
    // 0x80805C88: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    after_31:
    // 0x80805C8C: b           L_808064E0
    // 0x80805C90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805C90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805C94:
    // 0x80805C94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805C98: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80805C9C: jal         0x8080100C
    // 0x80805CA0: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    func_8080100C_chquiz(rdram, ctx);
        goto after_32;
    // 0x80805CA0: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    after_32:
    // 0x80805CA4: b           L_808064E0
    // 0x80805CA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805CA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805CAC:
    // 0x80805CAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805CB0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80805CB4: jal         0x8080100C
    // 0x80805CB8: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    func_8080100C_chquiz(rdram, ctx);
        goto after_33;
    // 0x80805CB8: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    after_33:
    // 0x80805CBC: b           L_808064E0
    // 0x80805CC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805CC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805CC4:
    // 0x80805CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805CC8: jal         0x80804170
    // 0x80805CCC: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_80804170_chquiz(rdram, ctx);
        goto after_34;
    // 0x80805CCC: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_34:
    // 0x80805CD0: b           L_808064E0
    // 0x80805CD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805CD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805CD8:
    // 0x80805CD8: addiu       $a0, $zero, 0x52E
    ctx->r4 = ADD32(0, 0X52E);
    // 0x80805CDC: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    // 0x80805CE0: jal         0x80101180
    // 0x80805CE4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80101180(rdram, ctx);
        goto after_35;
    // 0x80805CE4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_35:
    // 0x80805CE8: addiu       $a0, $zero, 0x529
    ctx->r4 = ADD32(0, 0X529);
    // 0x80805CEC: addiu       $a1, $zero, 0x8B
    ctx->r5 = ADD32(0, 0X8B);
    // 0x80805CF0: jal         0x80101180
    // 0x80805CF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_36;
    // 0x80805CF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_36:
    // 0x80805CF8: b           L_808064E0
    // 0x80805CFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805CFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805D00:
    // 0x80805D00: addiu       $a0, $zero, 0x52E
    ctx->r4 = ADD32(0, 0X52E);
    // 0x80805D04: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    // 0x80805D08: jal         0x80101180
    // 0x80805D0C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80101180(rdram, ctx);
        goto after_37;
    // 0x80805D0C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_37:
    // 0x80805D10: addiu       $a0, $zero, 0x529
    ctx->r4 = ADD32(0, 0X529);
    // 0x80805D14: addiu       $a1, $zero, 0x8B
    ctx->r5 = ADD32(0, 0X8B);
    // 0x80805D18: jal         0x80101180
    // 0x80805D1C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80101180(rdram, ctx);
        goto after_38;
    // 0x80805D1C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_38:
    // 0x80805D20: b           L_808064E0
    // 0x80805D24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805D24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805D28:
    // 0x80805D28: addiu       $a0, $zero, 0x52E
    ctx->r4 = ADD32(0, 0X52E);
    // 0x80805D2C: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    // 0x80805D30: jal         0x80101180
    // 0x80805D34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80101180(rdram, ctx);
        goto after_39;
    // 0x80805D34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_39:
    // 0x80805D38: addiu       $a0, $zero, 0x529
    ctx->r4 = ADD32(0, 0X529);
    // 0x80805D3C: addiu       $a1, $zero, 0x8B
    ctx->r5 = ADD32(0, 0X8B);
    // 0x80805D40: jal         0x80101180
    // 0x80805D44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80101180(rdram, ctx);
        goto after_40;
    // 0x80805D44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_40:
    // 0x80805D48: b           L_808064E0
    // 0x80805D4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805D4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805D50:
    // 0x80805D50: addiu       $a0, $zero, 0x52E
    ctx->r4 = ADD32(0, 0X52E);
    // 0x80805D54: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    // 0x80805D58: jal         0x80101180
    // 0x80805D5C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_80101180(rdram, ctx);
        goto after_41;
    // 0x80805D5C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_41:
    // 0x80805D60: addiu       $a0, $zero, 0x529
    ctx->r4 = ADD32(0, 0X529);
    // 0x80805D64: addiu       $a1, $zero, 0x8B
    ctx->r5 = ADD32(0, 0X8B);
    // 0x80805D68: jal         0x80101180
    // 0x80805D6C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_80101180(rdram, ctx);
        goto after_42;
    // 0x80805D6C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_42:
    // 0x80805D70: b           L_808064E0
    // 0x80805D74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805D74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805D78:
    // 0x80805D78: addiu       $a0, $zero, 0x52E
    ctx->r4 = ADD32(0, 0X52E);
    // 0x80805D7C: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    // 0x80805D80: jal         0x80101180
    // 0x80805D84: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80101180(rdram, ctx);
        goto after_43;
    // 0x80805D84: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_43:
    // 0x80805D88: addiu       $a0, $zero, 0x529
    ctx->r4 = ADD32(0, 0X529);
    // 0x80805D8C: addiu       $a1, $zero, 0x8B
    ctx->r5 = ADD32(0, 0X8B);
    // 0x80805D90: jal         0x80101180
    // 0x80805D94: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80101180(rdram, ctx);
        goto after_44;
    // 0x80805D94: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_44:
    // 0x80805D98: b           L_808064E0
    // 0x80805D9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805D9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805DA0:
    // 0x80805DA0: addiu       $a0, $zero, 0x52E
    ctx->r4 = ADD32(0, 0X52E);
    // 0x80805DA4: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    // 0x80805DA8: jal         0x80101180
    // 0x80805DAC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_80101180(rdram, ctx);
        goto after_45;
    // 0x80805DAC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_45:
    // 0x80805DB0: addiu       $a0, $zero, 0x529
    ctx->r4 = ADD32(0, 0X529);
    // 0x80805DB4: addiu       $a1, $zero, 0x8B
    ctx->r5 = ADD32(0, 0X8B);
    // 0x80805DB8: jal         0x80101180
    // 0x80805DBC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_80101180(rdram, ctx);
        goto after_46;
    // 0x80805DBC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_46:
    // 0x80805DC0: b           L_808064E0
    // 0x80805DC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805DC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805DC8:
    // 0x80805DC8: addiu       $a0, $zero, 0x52E
    ctx->r4 = ADD32(0, 0X52E);
    // 0x80805DCC: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    // 0x80805DD0: jal         0x80101180
    // 0x80805DD4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_80101180(rdram, ctx);
        goto after_47;
    // 0x80805DD4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_47:
    // 0x80805DD8: addiu       $a0, $zero, 0x529
    ctx->r4 = ADD32(0, 0X529);
    // 0x80805DDC: addiu       $a1, $zero, 0x8B
    ctx->r5 = ADD32(0, 0X8B);
    // 0x80805DE0: jal         0x80101180
    // 0x80805DE4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_80101180(rdram, ctx);
        goto after_48;
    // 0x80805DE4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_48:
    // 0x80805DE8: b           L_808064E0
    // 0x80805DEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805DEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805DF0:
    // 0x80805DF0: b           L_808064E0
    // 0x80805DF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808064E0;
    // 0x80805DF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80805DF8:
    // 0x80805DF8: addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // 0x80805DFC: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x80805E00: addiu       $t4, $t3, -0x1460
    ctx->r12 = ADD32(ctx->r11, -0X1460);
    // 0x80805E04: sltiu       $at, $t4, 0x80
    ctx->r1 = ctx->r12 < 0X80 ? 1 : 0;
    // 0x80805E08: beq         $at, $zero, L_80806264
    if (ctx->r1 == 0) {
        // 0x80805E0C: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_80806264;
    }
    // 0x80805E0C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80805E10: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X6AE4) << 16);
    // 0x80805E14: addu        $at, $at, $t4
    gpr jr_addend_80805E1C = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80805E18: lw          $t4, 0x6AE4($at)
    ctx->r12 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2484, 0X6AE4));
    // 0x80805E1C: jr          $t4
    // 0x80805E20: nop

    switch (jr_addend_80805E1C >> 2) {
        case 0: goto L_80805E30; break;
        case 1: goto L_80805E24; break;
        case 2: goto L_80805F98; break;
        case 3: goto L_80805E30; break;
        case 4: goto L_80805E48; break;
        case 5: goto L_80805E30; break;
        case 6: goto L_80805E68; break;
        case 7: goto L_80805E84; break;
        case 8: goto L_80805EA0; break;
        case 9: goto L_80806160; break;
        case 10: goto L_80805E68; break;
        case 11: goto L_80805E84; break;
        case 12: goto L_80805EA0; break;
        case 13: goto L_80805F0C; break;
        case 14: goto L_80805F0C; break;
        case 15: goto L_80805F0C; break;
        case 16: goto L_80805F0C; break;
        case 17: goto L_80805F0C; break;
        case 18: goto L_80805F0C; break;
        case 19: goto L_80805EE4; break;
        case 20: goto L_80805EE4; break;
        case 21: goto L_80805EE4; break;
        case 22: goto L_80805EE4; break;
        case 23: goto L_80805EE4; break;
        case 24: goto L_80805EE4; break;
        case 25: goto L_80805EBC; break;
        case 26: goto L_80805EBC; break;
        case 27: goto L_80805EBC; break;
        case 28: goto L_80805EBC; break;
        case 29: goto L_80805EBC; break;
        case 30: goto L_80805EBC; break;
        case 31: goto L_80805ED0; break;
        case 32: goto L_80805ED0; break;
        case 33: goto L_80805ED0; break;
        case 34: goto L_80805ED0; break;
        case 35: goto L_80805ED0; break;
        case 36: goto L_80805ED0; break;
        case 37: goto L_80805FC0; break;
        case 38: goto L_80805FC0; break;
        case 39: goto L_80805FC0; break;
        case 40: goto L_80805FC0; break;
        case 41: goto L_80805FC0; break;
        case 42: goto L_80805FC0; break;
        case 43: goto L_80805F84; break;
        case 44: goto L_80805F84; break;
        case 45: goto L_80805F84; break;
        case 46: goto L_80805F84; break;
        case 47: goto L_80805F84; break;
        case 48: goto L_80805F84; break;
        case 49: goto L_80805F84; break;
        case 50: goto L_80806264; break;
        case 51: goto L_808061DC; break;
        case 52: goto L_808061DC; break;
        case 53: goto L_808061DC; break;
        case 54: goto L_808061C8; break;
        case 55: goto L_808061C8; break;
        case 56: goto L_808061C8; break;
        case 57: goto L_808061C8; break;
        case 58: goto L_80805FAC; break;
        case 59: goto L_80805FAC; break;
        case 60: goto L_80805FAC; break;
        case 61: goto L_80805FAC; break;
        case 62: goto L_80805FAC; break;
        case 63: goto L_80805FAC; break;
        case 64: goto L_80806250; break;
        case 65: goto L_80805F34; break;
        case 66: goto L_80805F34; break;
        case 67: goto L_80805F34; break;
        case 68: goto L_80805EF8; break;
        case 69: goto L_80805EF8; break;
        case 70: goto L_80805EF8; break;
        case 71: goto L_80805EF8; break;
        case 72: goto L_80805EF8; break;
        case 73: goto L_80805EF8; break;
        case 74: goto L_80805F48; break;
        case 75: goto L_80805F48; break;
        case 76: goto L_80805F48; break;
        case 77: goto L_80805F48; break;
        case 78: goto L_80805F48; break;
        case 79: goto L_80805F48; break;
        case 80: goto L_80805F70; break;
        case 81: goto L_80805F70; break;
        case 82: goto L_80805F70; break;
        case 83: goto L_80805F70; break;
        case 84: goto L_80805F70; break;
        case 85: goto L_80805F70; break;
        case 86: goto L_80806264; break;
        case 87: goto L_80806264; break;
        case 88: goto L_80806264; break;
        case 89: goto L_80806264; break;
        case 90: goto L_80806264; break;
        case 91: goto L_80806264; break;
        case 92: goto L_80805F20; break;
        case 93: goto L_80805F20; break;
        case 94: goto L_80805F20; break;
        case 95: goto L_80805F20; break;
        case 96: goto L_80805F20; break;
        case 97: goto L_80805F20; break;
        case 98: goto L_80806194; break;
        case 99: goto L_80806194; break;
        case 100: goto L_80806194; break;
        case 101: goto L_80806194; break;
        case 102: goto L_808061AC; break;
        case 103: goto L_80805FD4; break;
        case 104: goto L_80805FD4; break;
        case 105: goto L_80806040; break;
        case 106: goto L_80806040; break;
        case 107: goto L_80806040; break;
        case 108: goto L_80806054; break;
        case 109: goto L_80806088; break;
        case 110: goto L_808060BC; break;
        case 111: goto L_80806134; break;
        case 112: goto L_80806134; break;
        case 113: goto L_808060F0; break;
        case 114: goto L_80806104; break;
        case 115: goto L_80806118; break;
        case 116: goto L_80806118; break;
        case 117: goto L_80806118; break;
        case 118: goto L_80806194; break;
        case 119: goto L_80806264; break;
        case 120: goto L_80806264; break;
        case 121: goto L_808061AC; break;
        case 122: goto L_80805F5C; break;
        case 123: goto L_80805F5C; break;
        case 124: goto L_80805F5C; break;
        case 125: goto L_80805F5C; break;
        case 126: goto L_80805F5C; break;
        case 127: goto L_80805F5C; break;
        default: switch_error(__func__, 0x80805E1C, 0x80806AE4);
    }
    // 0x80805E20: nop

L_80805E24:
    // 0x80805E24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805E28: jal         0x80801470
    // 0x80805E2C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_80801470_chquiz(rdram, ctx);
        goto after_49;
    // 0x80805E2C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_49:
L_80805E30:
    // 0x80805E30: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x80805E34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805E38: jal         0x80804170
    // 0x80805E3C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    func_80804170_chquiz(rdram, ctx);
        goto after_50;
    // 0x80805E3C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    after_50:
    // 0x80805E40: b           L_808064E0
    // 0x80805E44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805E44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805E48:
    // 0x80805E48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80805E4C: jal         0x808014F8
    // 0x80805E50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808014F8_chquiz(rdram, ctx);
        goto after_51;
    // 0x80805E50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_51:
    // 0x80805E54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805E58: jal         0x80804170
    // 0x80805E5C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80804170_chquiz(rdram, ctx);
        goto after_52;
    // 0x80805E5C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_52:
    // 0x80805E60: b           L_808064E0
    // 0x80805E64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805E64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805E68:
    // 0x80805E68: jal         0x8008A870
    // 0x80805E6C: nop

    _suquiz_entrypoint_23(rdram, ctx);
        goto after_53;
    // 0x80805E6C: nop

    after_53:
    // 0x80805E70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805E74: jal         0x80804170
    // 0x80805E78: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80804170_chquiz(rdram, ctx);
        goto after_54;
    // 0x80805E78: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_54:
    // 0x80805E7C: b           L_808064E0
    // 0x80805E80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805E80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805E84:
    // 0x80805E84: jal         0x8008A870
    // 0x80805E88: nop

    _suquiz_entrypoint_23(rdram, ctx);
        goto after_55;
    // 0x80805E88: nop

    after_55:
    // 0x80805E8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805E90: jal         0x80804170
    // 0x80805E94: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80804170_chquiz(rdram, ctx);
        goto after_56;
    // 0x80805E94: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_56:
    // 0x80805E98: b           L_808064E0
    // 0x80805E9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805E9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805EA0:
    // 0x80805EA0: jal         0x8008A870
    // 0x80805EA4: nop

    _suquiz_entrypoint_23(rdram, ctx);
        goto after_57;
    // 0x80805EA4: nop

    after_57:
    // 0x80805EA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805EAC: jal         0x80804170
    // 0x80805EB0: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80804170_chquiz(rdram, ctx);
        goto after_58;
    // 0x80805EB0: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_58:
    // 0x80805EB4: b           L_808064E0
    // 0x80805EB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805EB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805EBC:
    // 0x80805EBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805EC0: jal         0x80804170
    // 0x80805EC4: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_80804170_chquiz(rdram, ctx);
        goto after_59;
    // 0x80805EC4: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_59:
    // 0x80805EC8: b           L_808064E0
    // 0x80805ECC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805ECC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805ED0:
    // 0x80805ED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805ED4: jal         0x80804170
    // 0x80805ED8: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80804170_chquiz(rdram, ctx);
        goto after_60;
    // 0x80805ED8: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_60:
    // 0x80805EDC: b           L_808064E0
    // 0x80805EE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805EE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805EE4:
    // 0x80805EE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805EE8: jal         0x80804170
    // 0x80805EEC: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80804170_chquiz(rdram, ctx);
        goto after_61;
    // 0x80805EEC: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_61:
    // 0x80805EF0: b           L_808064E0
    // 0x80805EF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805EF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805EF8:
    // 0x80805EF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805EFC: jal         0x80804170
    // 0x80805F00: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80804170_chquiz(rdram, ctx);
        goto after_62;
    // 0x80805F00: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_62:
    // 0x80805F04: b           L_808064E0
    // 0x80805F08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805F08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805F0C:
    // 0x80805F0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805F10: jal         0x80804170
    // 0x80805F14: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80804170_chquiz(rdram, ctx);
        goto after_63;
    // 0x80805F14: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_63:
    // 0x80805F18: b           L_808064E0
    // 0x80805F1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805F1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805F20:
    // 0x80805F20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805F24: jal         0x80804170
    // 0x80805F28: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80804170_chquiz(rdram, ctx);
        goto after_64;
    // 0x80805F28: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_64:
    // 0x80805F2C: b           L_808064E0
    // 0x80805F30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805F30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805F34:
    // 0x80805F34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805F38: jal         0x80804170
    // 0x80805F3C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80804170_chquiz(rdram, ctx);
        goto after_65;
    // 0x80805F3C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_65:
    // 0x80805F40: b           L_808064E0
    // 0x80805F44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805F44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805F48:
    // 0x80805F48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805F4C: jal         0x80804170
    // 0x80805F50: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_80804170_chquiz(rdram, ctx);
        goto after_66;
    // 0x80805F50: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_66:
    // 0x80805F54: b           L_808064E0
    // 0x80805F58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805F58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805F5C:
    // 0x80805F5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805F60: jal         0x80804170
    // 0x80805F64: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80804170_chquiz(rdram, ctx);
        goto after_67;
    // 0x80805F64: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_67:
    // 0x80805F68: b           L_808064E0
    // 0x80805F6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805F6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805F70:
    // 0x80805F70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805F74: jal         0x80804170
    // 0x80805F78: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80804170_chquiz(rdram, ctx);
        goto after_68;
    // 0x80805F78: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_68:
    // 0x80805F7C: b           L_808064E0
    // 0x80805F80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805F80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805F84:
    // 0x80805F84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805F88: jal         0x80804170
    // 0x80805F8C: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    func_80804170_chquiz(rdram, ctx);
        goto after_69;
    // 0x80805F8C: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    after_69:
    // 0x80805F90: b           L_808064E0
    // 0x80805F94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805F94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805F98:
    // 0x80805F98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805F9C: jal         0x80804170
    // 0x80805FA0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80804170_chquiz(rdram, ctx);
        goto after_70;
    // 0x80805FA0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_70:
    // 0x80805FA4: b           L_808064E0
    // 0x80805FA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805FA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805FAC:
    // 0x80805FAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805FB0: jal         0x80804170
    // 0x80805FB4: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80804170_chquiz(rdram, ctx);
        goto after_71;
    // 0x80805FB4: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_71:
    // 0x80805FB8: b           L_808064E0
    // 0x80805FBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805FBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805FC0:
    // 0x80805FC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805FC4: jal         0x80804170
    // 0x80805FC8: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80804170_chquiz(rdram, ctx);
        goto after_72;
    // 0x80805FC8: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_72:
    // 0x80805FCC: b           L_808064E0
    // 0x80805FD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80805FD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80805FD4:
    // 0x80805FD4: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x80805FD8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80805FDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805FE0: andi        $t5, $a1, 0x1FF
    ctx->r13 = ctx->r5 & 0X1FF;
    // 0x80805FE4: beq         $t5, $zero, L_80806008
    if (ctx->r13 == 0) {
        // 0x80805FE8: addiu       $a1, $zero, 0x14C9
        ctx->r5 = ADD32(0, 0X14C9);
            goto L_80806008;
    }
    // 0x80805FE8: addiu       $a1, $zero, 0x14C9
    ctx->r5 = ADD32(0, 0X14C9);
    // 0x80805FEC: beq         $t5, $at, L_80806018
    if (ctx->r13 == ctx->r1) {
        // 0x80805FF0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80806018;
    }
    // 0x80805FF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80805FF4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80805FF8: beq         $t5, $at, L_8080602C
    if (ctx->r13 == ctx->r1) {
        // 0x80805FFC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080602C;
    }
    // 0x80805FFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806000: b           L_808064E0
    // 0x80806004: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80806004: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80806008:
    // 0x80806008: jal         0x80803B54
    // 0x8080600C: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    func_80803B54_chquiz(rdram, ctx);
        goto after_73;
    // 0x8080600C: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    after_73:
    // 0x80806010: b           L_808064E0
    // 0x80806014: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80806014: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80806018:
    // 0x80806018: addiu       $a1, $zero, 0x14CA
    ctx->r5 = ADD32(0, 0X14CA);
    // 0x8080601C: jal         0x80803B54
    // 0x80806020: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    func_80803B54_chquiz(rdram, ctx);
        goto after_74;
    // 0x80806020: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    after_74:
    // 0x80806024: b           L_808064E0
    // 0x80806028: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80806028: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080602C:
    // 0x8080602C: addiu       $a1, $zero, 0x14CB
    ctx->r5 = ADD32(0, 0X14CB);
    // 0x80806030: jal         0x80803B54
    // 0x80806034: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    func_80803B54_chquiz(rdram, ctx);
        goto after_75;
    // 0x80806034: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    after_75:
    // 0x80806038: b           L_808064E0
    // 0x8080603C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x8080603C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80806040:
    // 0x80806040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806044: jal         0x80804170
    // 0x80806048: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    func_80804170_chquiz(rdram, ctx);
        goto after_76;
    // 0x80806048: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    after_76:
    // 0x8080604C: b           L_808064E0
    // 0x80806050: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80806050: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80806054:
    // 0x80806054: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x80806058: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8080605C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806060: beq         $t6, $zero, L_80806078
    if (ctx->r14 == 0) {
        // 0x80806064: nop
    
            goto L_80806078;
    }
    // 0x80806064: nop

    // 0x80806068: jal         0x80804170
    // 0x8080606C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80804170_chquiz(rdram, ctx);
        goto after_77;
    // 0x8080606C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_77:
    // 0x80806070: b           L_808064E0
    // 0x80806074: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80806074: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80806078:
    // 0x80806078: jal         0x80804170
    // 0x8080607C: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    func_80804170_chquiz(rdram, ctx);
        goto after_78;
    // 0x8080607C: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    after_78:
    // 0x80806080: b           L_808064E0
    // 0x80806084: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80806084: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80806088:
    // 0x80806088: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x8080608C: addiu       $a1, $zero, 0x14D1
    ctx->r5 = ADD32(0, 0X14D1);
    // 0x80806090: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    // 0x80806094: beq         $t7, $zero, L_808060AC
    if (ctx->r15 == 0) {
        // 0x80806098: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808060AC;
    }
    // 0x80806098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080609C: jal         0x80803B54
    // 0x808060A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803B54_chquiz(rdram, ctx);
        goto after_79;
    // 0x808060A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_79:
    // 0x808060A4: b           L_808064E0
    // 0x808060A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x808060A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808060AC:
    // 0x808060AC: jal         0x80804170
    // 0x808060B0: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    func_80804170_chquiz(rdram, ctx);
        goto after_80;
    // 0x808060B0: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    after_80:
    // 0x808060B4: b           L_808064E0
    // 0x808060B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x808060B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808060BC:
    // 0x808060BC: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x808060C0: addiu       $a1, $zero, 0x14D2
    ctx->r5 = ADD32(0, 0X14D2);
    // 0x808060C4: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    // 0x808060C8: beq         $t8, $zero, L_808060E0
    if (ctx->r24 == 0) {
        // 0x808060CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808060E0;
    }
    // 0x808060CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808060D0: jal         0x80803B54
    // 0x808060D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803B54_chquiz(rdram, ctx);
        goto after_81;
    // 0x808060D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_81:
    // 0x808060D8: b           L_808064E0
    // 0x808060DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x808060DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808060E0:
    // 0x808060E0: jal         0x80804170
    // 0x808060E4: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    func_80804170_chquiz(rdram, ctx);
        goto after_82;
    // 0x808060E4: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    after_82:
    // 0x808060E8: b           L_808064E0
    // 0x808060EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x808060EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808060F0:
    // 0x808060F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808060F4: jal         0x80804170
    // 0x808060F8: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    func_80804170_chquiz(rdram, ctx);
        goto after_83;
    // 0x808060F8: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    after_83:
    // 0x808060FC: b           L_808064E0
    // 0x80806100: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80806100: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80806104:
    // 0x80806104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806108: jal         0x80804170
    // 0x8080610C: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    func_80804170_chquiz(rdram, ctx);
        goto after_84;
    // 0x8080610C: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    after_84:
    // 0x80806110: b           L_808064E0
    // 0x80806114: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80806114: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80806118:
    // 0x80806118: jal         0x8008A870
    // 0x8080611C: nop

    _suquiz_entrypoint_23(rdram, ctx);
        goto after_85;
    // 0x8080611C: nop

    after_85:
    // 0x80806120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806124: jal         0x80804170
    // 0x80806128: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80804170_chquiz(rdram, ctx);
        goto after_86;
    // 0x80806128: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_86:
    // 0x8080612C: b           L_808064E0
    // 0x80806130: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80806130: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80806134:
    // 0x80806134: lh          $t9, 0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2);
    // 0x80806138: beq         $t9, $zero, L_80806150
    if (ctx->r25 == 0) {
        // 0x8080613C: nop
    
            goto L_80806150;
    }
    // 0x8080613C: nop

    // 0x80806140: jal         0x80088188
    // 0x80806144: nop

    _gcfrontend_entrypoint_11(rdram, ctx);
        goto after_87;
    // 0x80806144: nop

    after_87:
    // 0x80806148: b           L_808064E0
    // 0x8080614C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x8080614C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80806150:
    // 0x80806150: jal         0x80088180
    // 0x80806154: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_88;
    // 0x80806154: nop

    after_88:
    // 0x80806158: b           L_808064E0
    // 0x8080615C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x8080615C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80806160:
    // 0x80806160: lh          $t0, 0x2($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X2);
    // 0x80806164: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    // 0x80806168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080616C: beq         $t0, $zero, L_80806184
    if (ctx->r8 == 0) {
        // 0x80806170: nop
    
            goto L_80806184;
    }
    // 0x80806170: nop

    // 0x80806174: jal         0x80804170
    // 0x80806178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80804170_chquiz(rdram, ctx);
        goto after_89;
    // 0x80806178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_89:
    // 0x8080617C: b           L_808064E0
    // 0x80806180: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80806180: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80806184:
    // 0x80806184: jal         0x80804170
    // 0x80806188: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    func_80804170_chquiz(rdram, ctx);
        goto after_90;
    // 0x80806188: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    after_90:
    // 0x8080618C: b           L_808064E0
    // 0x80806190: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80806190: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80806194:
    // 0x80806194: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x80806198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080619C: jal         0x80804170
    // 0x808061A0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    func_80804170_chquiz(rdram, ctx);
        goto after_91;
    // 0x808061A0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    after_91:
    // 0x808061A4: b           L_808064E0
    // 0x808061A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x808061A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808061AC:
    // 0x808061AC: jal         0x8008A870
    // 0x808061B0: nop

    _suquiz_entrypoint_23(rdram, ctx);
        goto after_92;
    // 0x808061B0: nop

    after_92:
    // 0x808061B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808061B8: jal         0x80804170
    // 0x808061BC: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80804170_chquiz(rdram, ctx);
        goto after_93;
    // 0x808061BC: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_93:
    // 0x808061C0: b           L_808064E0
    // 0x808061C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x808061C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808061C8:
    // 0x808061C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808061CC: jal         0x80804170
    // 0x808061D0: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    func_80804170_chquiz(rdram, ctx);
        goto after_94;
    // 0x808061D0: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    after_94:
    // 0x808061D4: b           L_808064E0
    // 0x808061D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x808061D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808061DC:
    // 0x808061DC: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x808061E0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808061E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808061E8: andi        $t1, $a1, 0x1FF
    ctx->r9 = ctx->r5 & 0X1FF;
    // 0x808061EC: beq         $t1, $at, L_80806220
    if (ctx->r9 == ctx->r1) {
        // 0x808061F0: addiu       $a2, $zero, 0x46
        ctx->r6 = ADD32(0, 0X46);
            goto L_80806220;
    }
    // 0x808061F0: addiu       $a2, $zero, 0x46
    ctx->r6 = ADD32(0, 0X46);
    // 0x808061F4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808061F8: beq         $t1, $at, L_8080622C
    if (ctx->r9 == ctx->r1) {
        // 0x808061FC: addiu       $t3, $zero, 0x1497
        ctx->r11 = ADD32(0, 0X1497);
            goto L_8080622C;
    }
    // 0x808061FC: addiu       $t3, $zero, 0x1497
    ctx->r11 = ADD32(0, 0X1497);
    // 0x80806200: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80806204: beq         $t1, $at, L_80806234
    if (ctx->r9 == ctx->r1) {
        // 0x80806208: addiu       $t4, $zero, 0x1496
        ctx->r12 = ADD32(0, 0X1496);
            goto L_80806234;
    }
    // 0x80806208: addiu       $t4, $zero, 0x1496
    ctx->r12 = ADD32(0, 0X1496);
    // 0x8080620C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80806210: beq         $t1, $at, L_8080623C
    if (ctx->r9 == ctx->r1) {
        // 0x80806214: addiu       $t5, $zero, 0x1499
        ctx->r13 = ADD32(0, 0X1499);
            goto L_8080623C;
    }
    // 0x80806214: addiu       $t5, $zero, 0x1499
    ctx->r13 = ADD32(0, 0X1499);
    // 0x80806218: b           L_80806240
    // 0x8080621C: nop

        goto L_80806240;
    // 0x8080621C: nop

L_80806220:
    // 0x80806220: addiu       $t2, $zero, 0x1498
    ctx->r10 = ADD32(0, 0X1498);
    // 0x80806224: b           L_80806240
    // 0x80806228: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
        goto L_80806240;
    // 0x80806228: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
L_8080622C:
    // 0x8080622C: b           L_80806240
    // 0x80806230: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
        goto L_80806240;
    // 0x80806230: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
L_80806234:
    // 0x80806234: b           L_80806240
    // 0x80806238: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
        goto L_80806240;
    // 0x80806238: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
L_8080623C:
    // 0x8080623C: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
L_80806240:
    // 0x80806240: jal         0x80803B54
    // 0x80806244: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80803B54_chquiz(rdram, ctx);
        goto after_95;
    // 0x80806244: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_95:
    // 0x80806248: b           L_808064E0
    // 0x8080624C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x8080624C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80806250:
    // 0x80806250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806254: jal         0x80804170
    // 0x80806258: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    func_80804170_chquiz(rdram, ctx);
        goto after_96;
    // 0x80806258: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    after_96:
    // 0x8080625C: b           L_808064E0
    // 0x80806260: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80806260: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80806264:
    // 0x80806264: b           L_808064E0
    // 0x80806268: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80806268: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080626C:
    // 0x8080626C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806270: jal         0x80801470
    // 0x80806274: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_80801470_chquiz(rdram, ctx);
        goto after_97;
    // 0x80806274: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_97:
    // 0x80806278: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8080627C: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x80806280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806284: bne         $t6, $at, L_8080629C
    if (ctx->r14 != ctx->r1) {
        // 0x80806288: lw          $t7, 0x40($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X40);
            goto L_8080629C;
    }
    // 0x80806288: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8080628C: jal         0x80804170
    // 0x80806290: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    func_80804170_chquiz(rdram, ctx);
        goto after_98;
    // 0x80806290: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    after_98:
    // 0x80806294: b           L_808064E0
    // 0x80806298: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_808064E0;
    // 0x80806298: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8080629C:
    // 0x8080629C: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x808062A0: bne         $t7, $at, L_808062B0
    if (ctx->r15 != ctx->r1) {
        // 0x808062A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808062B0;
    }
    // 0x808062A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808062A8: jal         0x80804170
    // 0x808062AC: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    func_80804170_chquiz(rdram, ctx);
        goto after_99;
    // 0x808062AC: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    after_99:
L_808062B0:
    // 0x808062B0: b           L_808064E0
    // 0x808062B4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_808064E0;
    // 0x808062B4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_808062B8:
    // 0x808062B8: addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // 0x808062BC: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x808062C0: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x808062C4: jal         0x808005C0
    // 0x808062C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808005C0_chquiz(rdram, ctx);
        goto after_100;
    // 0x808062C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_100:
    // 0x808062CC: b           L_808064E0
    // 0x808062D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x808062D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808062D4: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
L_808062D8:
    // 0x808062D8: addiu       $v1, $zero, 0xD
    ctx->r3 = ADD32(0, 0XD);
    // 0x808062DC: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x808062E0: beq         $v1, $v0, L_808062F0
    if (ctx->r3 == ctx->r2) {
        // 0x808062E4: nop
    
            goto L_808062F0;
    }
    // 0x808062E4: nop

    // 0x808062E8: bne         $v0, $at, L_80806310
    if (ctx->r2 != ctx->r1) {
        // 0x808062EC: nop
    
            goto L_80806310;
    }
    // 0x808062EC: nop

L_808062F0:
    // 0x808062F0: bne         $v1, $v0, L_80806300
    if (ctx->r3 != ctx->r2) {
        // 0x808062F4: addiu       $a1, $zero, 0x10
        ctx->r5 = ADD32(0, 0X10);
            goto L_80806300;
    }
    // 0x808062F4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x808062F8: b           L_80806300
    // 0x808062FC: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
        goto L_80806300;
    // 0x808062FC: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
L_80806300:
    // 0x80806300: jal         0x80804170
    // 0x80806304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80804170_chquiz(rdram, ctx);
        goto after_101;
    // 0x80806304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_101:
    // 0x80806308: b           L_808064E0
    // 0x8080630C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x8080630C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80806310:
    // 0x80806310: b           L_808064E0
    // 0x80806314: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808064E0;
    // 0x80806314: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80806318:
    // 0x80806318: jal         0x800D395C
    // 0x8080631C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    func_800D395C(rdram, ctx);
        goto after_102;
    // 0x8080631C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_102:
    // 0x80806320: beq         $v0, $zero, L_80806350
    if (ctx->r2 == 0) {
        // 0x80806324: nop
    
            goto L_80806350;
    }
    // 0x80806324: nop

    // 0x80806328: lw          $t8, 0x6C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X6C);
    // 0x8080632C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80806330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806334: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x80806338: bne         $t9, $at, L_80806350
    if (ctx->r25 != ctx->r1) {
        // 0x8080633C: nop
    
            goto L_80806350;
    }
    // 0x8080633C: nop

    // 0x80806340: jal         0x80804170
    // 0x80806344: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    func_80804170_chquiz(rdram, ctx);
        goto after_103;
    // 0x80806344: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    after_103:
    // 0x80806348: b           L_808064E0
    // 0x8080634C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x8080634C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80806350:
    // 0x80806350: jal         0x800D3948
    // 0x80806354: nop

    func_800D3948(rdram, ctx);
        goto after_104;
    // 0x80806354: nop

    after_104:
    // 0x80806358: beq         $v0, $zero, L_808063C0
    if (ctx->r2 == 0) {
        // 0x8080635C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808063C0;
    }
    // 0x8080635C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806360: lw          $t0, 0x34($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X34);
    // 0x80806364: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x80806368: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8080636C: beq         $t0, $at, L_808063C8
    if (ctx->r8 == ctx->r1) {
        // 0x80806370: nop
    
            goto L_808063C8;
    }
    // 0x80806370: nop

    // 0x80806374: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
L_80806378:
    // 0x80806378: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8080637C: jal         0x80801784
    // 0x80806380: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    func_80801784_chquiz(rdram, ctx);
        goto after_105;
    // 0x80806380: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_105:
    // 0x80806384: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80806388: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8080638C: jal         0x800AA20C
    // 0x80806390: addiu       $a0, $a2, -0x3
    ctx->r4 = ADD32(ctx->r6, -0X3);
    func_800AA20C(rdram, ctx);
        goto after_106;
    // 0x80806390: addiu       $a0, $a2, -0x3
    ctx->r4 = ADD32(ctx->r6, -0X3);
    after_106:
    // 0x80806394: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80806398: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8080639C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x808063A0: bnel        $a2, $at, L_80806378
    if (ctx->r6 != ctx->r1) {
        // 0x808063A4: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_80806378;
    }
    goto skip_1;
    // 0x808063A4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    skip_1:
    // 0x808063A8: jal         0x80088180
    // 0x808063AC: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_107;
    // 0x808063AC: nop

    after_107:
    // 0x808063B0: addiu       $t1, $zero, 0x38
    ctx->r9 = ADD32(0, 0X38);
    // 0x808063B4: sw          $t1, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r9;
    // 0x808063B8: b           L_808064E0
    // 0x808063BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x808063BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808063C0:
    // 0x808063C0: jal         0x80804170
    // 0x808063C4: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    func_80804170_chquiz(rdram, ctx);
        goto after_108;
    // 0x808063C4: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    after_108:
L_808063C8:
    // 0x808063C8: b           L_808064E0
    // 0x808063CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x808063CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808063D0:
    // 0x808063D0: jal         0x800D3948
    // 0x808063D4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    func_800D3948(rdram, ctx);
        goto after_109;
    // 0x808063D4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_109:
    // 0x808063D8: bne         $v0, $zero, L_80806420
    if (ctx->r2 != 0) {
        // 0x808063DC: nop
    
            goto L_80806420;
    }
    // 0x808063DC: nop

    // 0x808063E0: jal         0x800DA298
    // 0x808063E4: addiu       $a0, $zero, 0x6B6
    ctx->r4 = ADD32(0, 0X6B6);
    func_800DA298(rdram, ctx);
        goto after_110;
    // 0x808063E4: addiu       $a0, $zero, 0x6B6
    ctx->r4 = ADD32(0, 0X6B6);
    after_110:
    // 0x808063E8: beq         $v0, $zero, L_80806420
    if (ctx->r2 == 0) {
        // 0x808063EC: nop
    
            goto L_80806420;
    }
    // 0x808063EC: nop

    // 0x808063F0: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x808063F4: andi        $t2, $a0, 0x1FF
    ctx->r10 = ctx->r4 & 0X1FF;
    // 0x808063F8: jal         0x80801544
    // 0x808063FC: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    func_80801544_chquiz(rdram, ctx);
        goto after_111;
    // 0x808063FC: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_111:
    // 0x80806400: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80806404: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80806408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080640C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80806410: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x80806414: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80806418: jal         0x80801058
    // 0x8080641C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_80801058_chquiz(rdram, ctx);
        goto after_112;
    // 0x8080641C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_112:
L_80806420:
    // 0x80806420: b           L_808064E0
    // 0x80806424: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80806424: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80806428:
    // 0x80806428: jal         0x801015D0
    // 0x8080642C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801015D0(rdram, ctx);
        goto after_113;
    // 0x8080642C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_113:
    // 0x80806430: lhu         $t4, 0x72($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X72);
    // 0x80806434: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2484, 0X7528) << 16);
    // 0x80806438: srl         $t5, $t4, 10
    ctx->r13 = S32(U32(ctx->r12) >> 10);
    // 0x8080643C: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x80806440: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80806444: lhu         $t7, 0x7528($t7)
    ctx->r15 = MEM_HU(ctx->r15, (int16_t)RELOC_LO16(2484, 0X7528));
    // 0x80806448: addiu       $t8, $t7, -0x4C2
    ctx->r24 = ADD32(ctx->r15, -0X4C2);
    // 0x8080644C: sltiu       $at, $t8, 0x6
    ctx->r1 = ctx->r24 < 0X6 ? 1 : 0;
    // 0x80806450: beq         $at, $zero, L_8080648C
    if (ctx->r1 == 0) {
        // 0x80806454: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_8080648C;
    }
    // 0x80806454: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80806458: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X6CE4) << 16);
    // 0x8080645C: addu        $at, $at, $t8
    gpr jr_addend_80806464 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80806460: lw          $t8, 0x6CE4($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2484, 0X6CE4));
    // 0x80806464: jr          $t8
    // 0x80806468: nop

    switch (jr_addend_80806464 >> 2) {
        case 0: goto L_8080646C; break;
        case 1: goto L_8080646C; break;
        case 2: goto L_8080646C; break;
        case 3: goto L_80806480; break;
        case 4: goto L_80806480; break;
        case 5: goto L_80806480; break;
        default: switch_error(__func__, 0x80806464, 0x80806CE4);
    }
    // 0x80806468: nop

L_8080646C:
    // 0x8080646C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80806470: jal         0x800DF744
    // 0x80806474: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_114;
    // 0x80806474: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_114:
    // 0x80806478: b           L_808064E0
    // 0x8080647C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x8080647C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80806480:
    // 0x80806480: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80806484: jal         0x800DF744
    // 0x80806488: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_115;
    // 0x80806488: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_115:
L_8080648C:
    // 0x8080648C: b           L_808064E0
    // 0x80806490: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x80806490: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80806494:
    // 0x80806494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806498: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080649C: jal         0x800897C0
    // 0x808064A0: addiu       $a2, $zero, 0x4D
    ctx->r6 = ADD32(0, 0X4D);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_116;
    // 0x808064A0: addiu       $a2, $zero, 0x4D
    ctx->r6 = ADD32(0, 0X4D);
    after_116:
    // 0x808064A4: b           L_808064E0
    // 0x808064A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x808064A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808064AC:
    // 0x808064AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808064B0: jal         0x800897C8
    // 0x808064B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_117;
    // 0x808064B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_117:
    // 0x808064B8: b           L_808064E0
    // 0x808064BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x808064BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808064C0:
    // 0x808064C0: jal         0x800F54E4
    // 0x808064C4: nop

    func_800F54E4(rdram, ctx);
        goto after_118;
    // 0x808064C4: nop

    after_118:
    // 0x808064C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808064CC: jal         0x800F82D4
    // 0x808064D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800F82D4(rdram, ctx);
        goto after_119;
    // 0x808064D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_119:
    // 0x808064D4: b           L_808064E0
    // 0x808064D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808064E0;
    // 0x808064D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808064DC:
    // 0x808064DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808064E0:
    // 0x808064E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808064E4:
    // 0x808064E4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808064E8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808064EC: jr          $ra
    // 0x808064F0: nop

    return;
    // 0x808064F0: nop

;}
RECOMP_FUNC void bsbwhirl_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800600: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800604: jal         0x80098140
    // 0x80800608: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    bainput_enable(rdram, ctx);
        goto after_0;
    // 0x80800608: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8080060C: jal         0x8080017C
    // 0x80800610: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8080017C_bsbwhirl(rdram, ctx);
        goto after_1;
    // 0x80800610: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800614: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800618: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080061C: jr          $ra
    // 0x80800620: nop

    return;
    // 0x80800620: nop

;}
RECOMP_FUNC void func_80800580_bskazwingwhack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800580: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800584: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800588: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080058C: jal         0x8008CABC
    // 0x80800590: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800590: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800594: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800598: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x8080059C: jal         0x8008B2B4
    // 0x808005A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_getAnimTimer(rdram, ctx);
        goto after_1;
    // 0x808005A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808005A4: lui         $a1, 0x3E8A
    ctx->r5 = S32(0X3E8A << 16);
    // 0x808005A8: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x808005AC: ori         $a1, $a1, 0x3D71
    ctx->r5 = ctx->r5 | 0X3D71;
    // 0x808005B0: jal         0x8008B348
    // 0x808005B4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    anctrl_isAt(rdram, ctx);
        goto after_2;
    // 0x808005B4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_2:
    // 0x808005B8: beq         $v0, $zero, L_808005CC
    if (ctx->r2 == 0) {
        // 0x808005BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005CC;
    }
    // 0x808005BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808005C4: jal         0x8009E5A4
    // 0x808005C8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_8009E5A4(rdram, ctx);
        goto after_3;
    // 0x808005C8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_3:
L_808005CC:
    // 0x808005CC: lui         $a1, 0x3EE2
    ctx->r5 = S32(0X3EE2 << 16);
    // 0x808005D0: ori         $a1, $a1, 0x4DD3
    ctx->r5 = ctx->r5 | 0X4DD3;
    // 0x808005D4: jal         0x8008B348
    // 0x808005D8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    anctrl_isAt(rdram, ctx);
        goto after_4;
    // 0x808005D8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_4:
    // 0x808005DC: beq         $v0, $zero, L_808005F0
    if (ctx->r2 == 0) {
        // 0x808005E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005F0;
    }
    // 0x808005E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005E4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808005E8: jal         0x8009E5A4
    // 0x808005EC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_8009E5A4(rdram, ctx);
        goto after_5;
    // 0x808005EC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_5:
L_808005F0:
    // 0x808005F0: lui         $a1, 0x3F35
    ctx->r5 = S32(0X3F35 << 16);
    // 0x808005F4: ori         $a1, $a1, 0xC28F
    ctx->r5 = ctx->r5 | 0XC28F;
    // 0x808005F8: jal         0x8008B348
    // 0x808005FC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    anctrl_isAt(rdram, ctx);
        goto after_6;
    // 0x808005FC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_6:
    // 0x80800600: beq         $v0, $zero, L_80800614
    if (ctx->r2 == 0) {
        // 0x80800604: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800614;
    }
    // 0x80800604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800608: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080060C: jal         0x8009E55C
    // 0x80800610: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8009E55C(rdram, ctx);
        goto after_7;
    // 0x80800610: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_7:
L_80800614:
    // 0x80800614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800618: jal         0x80095774
    // 0x8080061C: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    baflag_clear(rdram, ctx);
        goto after_8;
    // 0x8080061C: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    after_8:
    // 0x80800620: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(300, 0X920) << 16);
    // 0x80800624: addiu       $a1, $a1, 0x920
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(300, 0X920));
    // 0x80800628: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8080062C: jal         0x800F3780
    // 0x80800630: addiu       $a2, $zero, 0x2C
    ctx->r6 = ADD32(0, 0X2C);
    func_800F3780(rdram, ctx);
        goto after_9;
    // 0x80800630: addiu       $a2, $zero, 0x2C
    ctx->r6 = ADD32(0, 0X2C);
    after_9:
    // 0x80800634: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800638: jal         0x8009B9F0
    // 0x8080063C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009B9F0(rdram, ctx);
        goto after_10;
    // 0x8080063C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800640: lui         $a1, 0x3DD4
    ctx->r5 = S32(0X3DD4 << 16);
    // 0x80800644: ori         $a1, $a1, 0xFDF4
    ctx->r5 = ctx->r5 | 0XFDF4;
    // 0x80800648: jal         0x8008B348
    // 0x8080064C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    anctrl_isAt(rdram, ctx);
        goto after_11;
    // 0x8080064C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_11:
    // 0x80800650: beq         $v0, $zero, L_80800668
    if (ctx->r2 == 0) {
        // 0x80800654: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800668;
    }
    // 0x80800654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800658: addiu       $a1, $zero, 0x459F
    ctx->r5 = ADD32(0, 0X459F);
    // 0x8080065C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800660: jal         0x8009DF18
    // 0x80800664: addiu       $a3, $zero, 0x6590
    ctx->r7 = ADD32(0, 0X6590);
    func_8009DF18(rdram, ctx);
        goto after_12;
    // 0x80800664: addiu       $a3, $zero, 0x6590
    ctx->r7 = ADD32(0, 0X6590);
    after_12:
L_80800668:
    // 0x80800668: lui         $a1, 0x3E1D
    ctx->r5 = S32(0X3E1D << 16);
    // 0x8080066C: ori         $a1, $a1, 0xB22D
    ctx->r5 = ctx->r5 | 0XB22D;
    // 0x80800670: jal         0x8008B348
    // 0x80800674: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    anctrl_isAt(rdram, ctx);
        goto after_13;
    // 0x80800674: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_13:
    // 0x80800678: beq         $v0, $zero, L_80800690
    if (ctx->r2 == 0) {
        // 0x8080067C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800690;
    }
    // 0x8080067C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800680: addiu       $a1, $zero, 0x3FF
    ctx->r5 = ADD32(0, 0X3FF);
    // 0x80800684: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800688: jal         0x8009DF94
    // 0x8080068C: addiu       $a3, $zero, 0x3A98
    ctx->r7 = ADD32(0, 0X3A98);
    func_8009DF94(rdram, ctx);
        goto after_14;
    // 0x8080068C: addiu       $a3, $zero, 0x3A98
    ctx->r7 = ADD32(0, 0X3A98);
    after_14:
L_80800690:
    // 0x80800690: lui         $a1, 0x3EA2
    ctx->r5 = S32(0X3EA2 << 16);
    // 0x80800694: ori         $a1, $a1, 0x4DD3
    ctx->r5 = ctx->r5 | 0X4DD3;
    // 0x80800698: jal         0x8008B348
    // 0x8080069C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    anctrl_isAt(rdram, ctx);
        goto after_15;
    // 0x8080069C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_15:
    // 0x808006A0: beq         $v0, $zero, L_808006BC
    if (ctx->r2 == 0) {
        // 0x808006A4: lui         $a2, 0x3F86
        ctx->r6 = S32(0X3F86 << 16);
            goto L_808006BC;
    }
    // 0x808006A4: lui         $a2, 0x3F86
    ctx->r6 = S32(0X3F86 << 16);
    // 0x808006A8: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x808006AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006B0: addiu       $a1, $zero, 0x45A0
    ctx->r5 = ADD32(0, 0X45A0);
    // 0x808006B4: jal         0x8009DF18
    // 0x808006B8: addiu       $a3, $zero, 0x6590
    ctx->r7 = ADD32(0, 0X6590);
    func_8009DF18(rdram, ctx);
        goto after_16;
    // 0x808006B8: addiu       $a3, $zero, 0x6590
    ctx->r7 = ADD32(0, 0X6590);
    after_16:
L_808006BC:
    // 0x808006BC: lui         $a1, 0x3EBB
    ctx->r5 = S32(0X3EBB << 16);
    // 0x808006C0: ori         $a1, $a1, 0xE76D
    ctx->r5 = ctx->r5 | 0XE76D;
    // 0x808006C4: jal         0x8008B348
    // 0x808006C8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    anctrl_isAt(rdram, ctx);
        goto after_17;
    // 0x808006C8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_17:
    // 0x808006CC: beq         $v0, $zero, L_808006E8
    if (ctx->r2 == 0) {
        // 0x808006D0: lui         $a2, 0x3F8C
        ctx->r6 = S32(0X3F8C << 16);
            goto L_808006E8;
    }
    // 0x808006D0: lui         $a2, 0x3F8C
    ctx->r6 = S32(0X3F8C << 16);
    // 0x808006D4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808006D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006DC: addiu       $a1, $zero, 0x3FF
    ctx->r5 = ADD32(0, 0X3FF);
    // 0x808006E0: jal         0x8009DF94
    // 0x808006E4: addiu       $a3, $zero, 0x3A98
    ctx->r7 = ADD32(0, 0X3A98);
    func_8009DF94(rdram, ctx);
        goto after_18;
    // 0x808006E4: addiu       $a3, $zero, 0x3A98
    ctx->r7 = ADD32(0, 0X3A98);
    after_18:
L_808006E8:
    // 0x808006E8: lui         $a1, 0x3F14
    ctx->r5 = S32(0X3F14 << 16);
    // 0x808006EC: ori         $a1, $a1, 0x7AE1
    ctx->r5 = ctx->r5 | 0X7AE1;
    // 0x808006F0: jal         0x8008B348
    // 0x808006F4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    anctrl_isAt(rdram, ctx);
        goto after_19;
    // 0x808006F4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_19:
    // 0x808006F8: beq         $v0, $zero, L_80800714
    if (ctx->r2 == 0) {
        // 0x808006FC: lui         $a2, 0x3F73
        ctx->r6 = S32(0X3F73 << 16);
            goto L_80800714;
    }
    // 0x808006FC: lui         $a2, 0x3F73
    ctx->r6 = S32(0X3F73 << 16);
    // 0x80800700: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800708: addiu       $a1, $zero, 0x45A1
    ctx->r5 = ADD32(0, 0X45A1);
    // 0x8080070C: jal         0x8009DF18
    // 0x80800710: addiu       $a3, $zero, 0x6590
    ctx->r7 = ADD32(0, 0X6590);
    func_8009DF18(rdram, ctx);
        goto after_20;
    // 0x80800710: addiu       $a3, $zero, 0x6590
    ctx->r7 = ADD32(0, 0X6590);
    after_20:
L_80800714:
    // 0x80800714: lui         $a1, 0x3F21
    ctx->r5 = S32(0X3F21 << 16);
    // 0x80800718: ori         $a1, $a1, 0x47AE
    ctx->r5 = ctx->r5 | 0X47AE;
    // 0x8080071C: jal         0x8008B348
    // 0x80800720: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    anctrl_isAt(rdram, ctx);
        goto after_21;
    // 0x80800720: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_21:
    // 0x80800724: beq         $v0, $zero, L_80800740
    if (ctx->r2 == 0) {
        // 0x80800728: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800740;
    }
    // 0x80800728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080072C: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x80800730: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800734: addiu       $a1, $zero, 0x3FF
    ctx->r5 = ADD32(0, 0X3FF);
    // 0x80800738: jal         0x8009DF94
    // 0x8080073C: addiu       $a3, $zero, 0x3A98
    ctx->r7 = ADD32(0, 0X3A98);
    func_8009DF94(rdram, ctx);
        goto after_22;
    // 0x8080073C: addiu       $a3, $zero, 0x3A98
    ctx->r7 = ADD32(0, 0X3A98);
    after_22:
L_80800740:
    // 0x80800740: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(300, 0X8FC) << 16);
    // 0x80800744: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800748: lwc1        $f4, 0x8FC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(300, 0X8FC));
    // 0x8080074C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(300, 0X900) << 16);
    // 0x80800750: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800754: nop

    // 0x80800758: bc1f        L_808007AC
    if (!c1cs) {
        // 0x8080075C: nop
    
            goto L_808007AC;
    }
    // 0x8080075C: nop

    // 0x80800760: lwc1        $f6, 0x900($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(300, 0X900));
    // 0x80800764: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800768: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x8080076C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80800770: nop

    // 0x80800774: bc1f        L_808007AC
    if (!c1cs) {
        // 0x80800778: nop
    
            goto L_808007AC;
    }
    // 0x80800778: nop

    // 0x8080077C: jal         0x800F3BD0
    // 0x80800780: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    func_800F3BD0(rdram, ctx);
        goto after_23;
    // 0x80800780: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_23:
    // 0x80800784: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800788: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8080078C: lui         $a2, 0x4234
    ctx->r6 = S32(0X4234 << 16);
    // 0x80800790: jal         0x80800000
    // 0x80800794: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_80800000_bskazwingwhack(rdram, ctx);
        goto after_24;
    // 0x80800794: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_24:
    // 0x80800798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080079C: jal         0x80095760
    // 0x808007A0: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    baflag_set(rdram, ctx);
        goto after_25;
    // 0x808007A0: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    after_25:
    // 0x808007A4: b           L_80800880
    // 0x808007A8: nop

        goto L_80800880;
    // 0x808007A8: nop

L_808007AC:
    // 0x808007AC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(300, 0X904) << 16);
    // 0x808007B0: lwc1        $f8, 0x904($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(300, 0X904));
    // 0x808007B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(300, 0X908) << 16);
    // 0x808007B8: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x808007BC: nop

    // 0x808007C0: bc1f        L_80800820
    if (!c1cs) {
        // 0x808007C4: nop
    
            goto L_80800820;
    }
    // 0x808007C4: nop

    // 0x808007C8: lwc1        $f10, 0x908($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(300, 0X908));
    // 0x808007CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007D0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x808007D4: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x808007D8: nop

    // 0x808007DC: bc1f        L_80800820
    if (!c1cs) {
        // 0x808007E0: nop
    
            goto L_80800820;
    }
    // 0x808007E0: nop

    // 0x808007E4: jal         0x800F3BD0
    // 0x808007E8: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    func_800F3BD0(rdram, ctx);
        goto after_26;
    // 0x808007E8: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_26:
    // 0x808007EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(300, 0X90C) << 16);
    // 0x808007F0: jal         0x800136E4
    // 0x808007F4: lwc1        $f12, 0x90C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(300, 0X90C));
    func_800136E4(rdram, ctx);
        goto after_27;
    // 0x808007F4: lwc1        $f12, 0x90C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(300, 0X90C));
    after_27:
    // 0x808007F8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808007FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800800: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80800804: jal         0x80800000
    // 0x80800808: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    func_80800000_bskazwingwhack(rdram, ctx);
        goto after_28;
    // 0x80800808: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    after_28:
    // 0x8080080C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800810: jal         0x80095760
    // 0x80800814: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    baflag_set(rdram, ctx);
        goto after_29;
    // 0x80800814: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    after_29:
    // 0x80800818: b           L_80800880
    // 0x8080081C: nop

        goto L_80800880;
    // 0x8080081C: nop

L_80800820:
    // 0x80800820: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(300, 0X910) << 16);
    // 0x80800824: lwc1        $f16, 0x910($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(300, 0X910));
    // 0x80800828: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(300, 0X914) << 16);
    // 0x8080082C: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80800830: nop

    // 0x80800834: bc1f        L_80800880
    if (!c1cs) {
        // 0x80800838: nop
    
            goto L_80800880;
    }
    // 0x80800838: nop

    // 0x8080083C: lwc1        $f18, 0x914($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(300, 0X914));
    // 0x80800840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800844: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800848: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8080084C: nop

    // 0x80800850: bc1f        L_80800880
    if (!c1cs) {
        // 0x80800854: nop
    
            goto L_80800880;
    }
    // 0x80800854: nop

    // 0x80800858: jal         0x800F3BD0
    // 0x8080085C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    func_800F3BD0(rdram, ctx);
        goto after_30;
    // 0x8080085C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_30:
    // 0x80800860: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800864: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80800868: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x8080086C: jal         0x80800000
    // 0x80800870: lui         $a3, 0xC1F0
    ctx->r7 = S32(0XC1F0 << 16);
    func_80800000_bskazwingwhack(rdram, ctx);
        goto after_31;
    // 0x80800870: lui         $a3, 0xC1F0
    ctx->r7 = S32(0XC1F0 << 16);
    after_31:
    // 0x80800874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800878: jal         0x80095760
    // 0x8080087C: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    baflag_set(rdram, ctx);
        goto after_32;
    // 0x8080087C: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    after_32:
L_80800880:
    // 0x80800880: jal         0x8008B324
    // 0x80800884: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    anctrl_isStopped(rdram, ctx);
        goto after_33;
    // 0x80800884: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_33:
    // 0x80800888: beq         $v0, $zero, L_80800894
    if (ctx->r2 == 0) {
        // 0x8080088C: addiu       $t6, $zero, 0xBB
        ctx->r14 = ADD32(0, 0XBB);
            goto L_80800894;
    }
    // 0x8080088C: addiu       $t6, $zero, 0xBB
    ctx->r14 = ADD32(0, 0XBB);
    // 0x80800890: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
L_80800894:
    // 0x80800894: jal         0x8008E078
    // 0x80800898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_34;
    // 0x80800898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x8080089C: bne         $v0, $zero, L_808008A8
    if (ctx->r2 != 0) {
        // 0x808008A0: addiu       $t7, $zero, 0xDF
        ctx->r15 = ADD32(0, 0XDF);
            goto L_808008A8;
    }
    // 0x808008A0: addiu       $t7, $zero, 0xDF
    ctx->r15 = ADD32(0, 0XDF);
    // 0x808008A4: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
L_808008A8:
    // 0x808008A8: jal         0x8008E35C
    // 0x808008AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_35;
    // 0x808008AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_35:
    // 0x808008B0: beq         $v0, $zero, L_808008C0
    if (ctx->r2 == 0) {
        // 0x808008B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008C0;
    }
    // 0x808008B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008B8: addiu       $t8, $zero, 0x160
    ctx->r24 = ADD32(0, 0X160);
    // 0x808008BC: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
L_808008C0:
    // 0x808008C0: jal         0x8009E5C8
    // 0x808008C4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    bs_setState(rdram, ctx);
        goto after_36;
    // 0x808008C4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_36:
    // 0x808008C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808008CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808008D0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808008D4: jr          $ra
    // 0x808008D8: nop

    return;
    // 0x808008D8: nop

;}
RECOMP_FUNC void baeggcursor_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003C0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808003C4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808003C8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808003CC: lw          $v1, 0x68($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X68);
    // 0x808003D0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808003D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003D8: lbu         $v0, 0x9($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X9);
    // 0x808003DC: beq         $v0, $at, L_80800400
    if (ctx->r2 == ctx->r1) {
        // 0x808003E0: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800400;
    }
    // 0x808003E0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808003E4: beq         $v0, $at, L_808004D0
    if (ctx->r2 == ctx->r1) {
        // 0x808003E8: lui         $a2, 0x3E4C
        ctx->r6 = S32(0X3E4C << 16);
            goto L_808004D0;
    }
    // 0x808003E8: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x808003EC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808003F0: beql        $v0, $at, L_80800560
    if (ctx->r2 == ctx->r1) {
        // 0x808003F4: lwc1        $f12, 0xC($v1)
        ctx->f12.u32l = MEM_W(ctx->r3, 0XC);
            goto L_80800560;
    }
    goto skip_0;
    // 0x808003F4: lwc1        $f12, 0xC($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0XC);
    skip_0:
    // 0x808003F8: b           L_8080062C
    // 0x808003FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080062C;
    // 0x808003FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800400:
    // 0x80800400: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(512, 0X660) << 16);
    // 0x80800404: lwc1        $f4, 0x660($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(512, 0X660));
    // 0x80800408: lwc1        $f12, 0xC($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8080040C: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80800410: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800414: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x80800418: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(512, 0X668) << 16);
    // 0x8080041C: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x80800420: bc1f        L_80800450
    if (!c1cs) {
        // 0x80800424: nop
    
            goto L_80800450;
    }
    // 0x80800424: nop

    // 0x80800428: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(512, 0X664) << 16);
    // 0x8080042C: lwc1        $f6, 0x664($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(512, 0X664));
    // 0x80800430: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800434: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80800438: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8080043C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800440: jal         0x800F10B4
    // 0x80800444: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_0;
    // 0x80800444: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80800448: b           L_8080046C
    // 0x8080044C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_8080046C;
    // 0x8080044C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80800450:
    // 0x80800450: lwc1        $f14, 0x668($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(512, 0X668));
    // 0x80800454: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80800458: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080045C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800460: jal         0x800F10B4
    // 0x80800464: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x80800464: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80800468: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8080046C:
    // 0x8080046C: lw          $t6, 0x68($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X68);
    // 0x80800470: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800474: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800478: swc1        $f2, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f2.u32l;
    // 0x8080047C: lw          $t7, 0x68($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X68);
    // 0x80800480: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80800484: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800488: lwc1        $f12, 0xC($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0XC);
    // 0x8080048C: lui         $a3, 0x42F0
    ctx->r7 = S32(0X42F0 << 16);
    // 0x80800490: jal         0x800F10B4
    // 0x80800494: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x80800494: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x80800498: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8080049C: lw          $t2, 0x68($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X68);
    // 0x808004A0: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x808004A4: nop

    // 0x808004A8: sw          $t9, 0x14($t2)
    MEM_W(0X14, ctx->r10) = ctx->r25;
    // 0x808004AC: lw          $a0, 0x68($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X68);
    // 0x808004B0: jal         0x800D9078
    // 0x808004B4: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800D9078(rdram, ctx);
        goto after_3;
    // 0x808004B4: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_3:
    // 0x808004B8: beq         $v0, $zero, L_80800628
    if (ctx->r2 == 0) {
        // 0x808004BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800628;
    }
    // 0x808004BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004C0: jal         0x8080018C
    // 0x808004C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    baeggcursor_entrypoint_7(rdram, ctx);
        goto after_4;
    // 0x808004C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x808004C8: b           L_8080062C
    // 0x808004CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080062C;
    // 0x808004CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808004D0:
    // 0x808004D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808004D4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808004D8: lwc1        $f12, 0xC($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0XC);
    // 0x808004DC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808004E0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808004E4: lui         $a3, 0x4180
    ctx->r7 = S32(0X4180 << 16);
    // 0x808004E8: jal         0x800F10B4
    // 0x808004EC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F10B4(rdram, ctx);
        goto after_5;
    // 0x808004EC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_5:
    // 0x808004F0: lw          $t3, 0x68($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X68);
    // 0x808004F4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x808004F8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x808004FC: swc1        $f0, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f0.u32l;
    // 0x80800500: lw          $t4, 0x68($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X68);
    // 0x80800504: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800508: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080050C: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80800510: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80800514: lwc1        $f12, 0xC($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0XC);
    // 0x80800518: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8080051C: jal         0x800F10B4
    // 0x80800520: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_6;
    // 0x80800520: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x80800524: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800528: lw          $t7, 0x68($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X68);
    // 0x8080052C: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x80800530: nop

    // 0x80800534: sw          $t6, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r14;
    // 0x80800538: lw          $a0, 0x68($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X68);
    // 0x8080053C: jal         0x800D9078
    // 0x80800540: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800D9078(rdram, ctx);
        goto after_7;
    // 0x80800540: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_7:
    // 0x80800544: beq         $v0, $zero, L_80800628
    if (ctx->r2 == 0) {
        // 0x80800548: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800628;
    }
    // 0x80800548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080054C: jal         0x8080018C
    // 0x80800550: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    baeggcursor_entrypoint_7(rdram, ctx);
        goto after_8;
    // 0x80800550: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80800554: b           L_8080062C
    // 0x80800558: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080062C;
    // 0x80800558: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080055C: lwc1        $f12, 0xC($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0XC);
L_80800560:
    // 0x80800560: lbu         $a0, 0x10($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X10);
    // 0x80800564: jal         0x80800000
    // 0x80800568: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    func_80800000_baeggcursor(rdram, ctx);
        goto after_9;
    // 0x80800568: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    after_9:
    // 0x8080056C: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800570: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80800574: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x80800578: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8080057C: c.le.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl <= ctx->f12.fl;
    // 0x80800580: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800584: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800588: bc1fl       L_808005F8
    if (!c1cs) {
        // 0x8080058C: sll         $t9, $t0, 3
        ctx->r25 = S32(ctx->r8 << 3);
            goto L_808005F8;
    }
    goto skip_1;
    // 0x8080058C: sll         $t9, $t0, 3
    ctx->r25 = S32(ctx->r8 << 3);
    skip_1:
    // 0x80800590: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800594: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800598: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
L_8080059C:
    // 0x8080059C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x808005A0: addu        $t8, $t1, $v1
    ctx->r24 = ADD32(ctx->r9, ctx->r3);
    // 0x808005A4: c.eq.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl == ctx->f10.fl;
    // 0x808005A8: nop

    // 0x808005AC: bc1fl       L_808005DC
    if (!c1cs) {
        // 0x808005B0: lwc1        $f16, 0x0($t8)
        ctx->f16.u32l = MEM_W(ctx->r24, 0X0);
            goto L_808005DC;
    }
    goto skip_2;
    // 0x808005B0: lwc1        $f16, 0x0($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X0);
    skip_2:
    // 0x808005B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005B8: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x808005BC: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x808005C0: jal         0x8080018C
    // 0x808005C4: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    baeggcursor_entrypoint_7(rdram, ctx);
        goto after_10;
    // 0x808005C4: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    after_10:
    // 0x808005C8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x808005CC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x808005D0: b           L_808005F4
    // 0x808005D4: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
        goto L_808005F4;
    // 0x808005D4: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808005D8: lwc1        $f16, 0x0($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X0);
L_808005DC:
    // 0x808005DC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x808005E0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x808005E4: c.le.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl <= ctx->f12.fl;
    // 0x808005E8: nop

    // 0x808005EC: bc1tl       L_8080059C
    if (c1cs) {
        // 0x808005F0: lwc1        $f10, 0x4($a0)
        ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
            goto L_8080059C;
    }
    goto skip_3;
    // 0x808005F0: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    skip_3:
L_808005F4:
    // 0x808005F4: sll         $t9, $t0, 3
    ctx->r25 = S32(ctx->r8 << 3);
L_808005F8:
    // 0x808005F8: addu        $v0, $t1, $t9
    ctx->r2 = ADD32(ctx->r9, ctx->r25);
    // 0x808005FC: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80800600: lwc1        $f14, -0x8($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, -0X8);
    // 0x80800604: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x80800608: lw          $a3, -0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, -0X4);
    // 0x8080060C: jal         0x800F10B4
    // 0x80800610: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F10B4(rdram, ctx);
        goto after_11;
    // 0x80800610: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_11:
    // 0x80800614: lw          $t2, 0x68($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X68);
    // 0x80800618: swc1        $f0, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->f0.u32l;
    // 0x8080061C: lw          $a0, 0x68($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X68);
    // 0x80800620: jal         0x800D91B8
    // 0x80800624: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800D91B8(rdram, ctx);
        goto after_12;
    // 0x80800624: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_12:
L_80800628:
    // 0x80800628: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080062C:
    // 0x8080062C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800630: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800634: jr          $ra
    // 0x80800638: nop

    return;
    // 0x80800638: nop

    // 0x8080063C: nop

;}
RECOMP_FUNC void func_800F61E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F61E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F61E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F61EC: jal         0x800F6140
    // 0x800F61F0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    func_800F6140(rdram, ctx);
        goto after_0;
    // 0x800F61F0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_0:
    // 0x800F61F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F61F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F61FC: jr          $ra
    // 0x800F6200: nop

    return;
    // 0x800F6200: nop

;}
RECOMP_FUNC void func_80020BE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020BE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80020BE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80020BE8: jal         0x80020AD0
    // 0x80020BEC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_80020AD0(rdram, ctx);
        goto after_0;
    // 0x80020BEC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x80020BF0: b           L_80020BF8
    // 0x80020BF4: nop

        goto L_80020BF8;
    // 0x80020BF4: nop

L_80020BF8:
    // 0x80020BF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80020BFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80020C00: jr          $ra
    // 0x80020C04: nop

    return;
    // 0x80020C04: nop

;}
RECOMP_FUNC void func_808001CC_chtalontorpedoboulder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001CC: lhu         $v1, 0x76($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X76);
    // 0x808001D0: srl         $t6, $v1, 7
    ctx->r14 = S32(U32(ctx->r3) >> 7);
    // 0x808001D4: addiu       $v1, $t6, -0x32
    ctx->r3 = ADD32(ctx->r14, -0X32);
    // 0x808001D8: bltz        $v1, L_808001E8
    if (SIGNED(ctx->r3) < 0) {
        // 0x808001DC: slti        $at, $v1, 0x5
        ctx->r1 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
            goto L_808001E8;
    }
    // 0x808001DC: slti        $at, $v1, 0x5
    ctx->r1 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x808001E0: bne         $at, $zero, L_808001F0
    if (ctx->r1 != 0) {
        // 0x808001E4: addiu       $v0, $v1, 0x3EF
        ctx->r2 = ADD32(ctx->r3, 0X3EF);
            goto L_808001F0;
    }
    // 0x808001E4: addiu       $v0, $v1, 0x3EF
    ctx->r2 = ADD32(ctx->r3, 0X3EF);
L_808001E8:
    // 0x808001E8: jr          $ra
    // 0x808001EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x808001EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808001F0:
    // 0x808001F0: jr          $ra
    // 0x808001F4: nop

    return;
    // 0x808001F4: nop

;}
RECOMP_FUNC void func_800B7D28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7D28: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B7D2C: lw          $a0, -0x7D50($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D50);
    // 0x800B7D30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B7D34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B7D38: beq         $a0, $zero, L_800B7D48
    if (ctx->r4 == 0) {
        // 0x800B7D3C: nop
    
            goto L_800B7D48;
    }
    // 0x800B7D3C: nop

    // 0x800B7D40: jal         0x80088958
    // 0x800B7D44: nop

    _fxleaves_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x800B7D44: nop

    after_0:
L_800B7D48:
    // 0x800B7D48: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B7D4C: lw          $a0, -0x7D4C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D4C);
    // 0x800B7D50: beq         $a0, $zero, L_800B7D60
    if (ctx->r4 == 0) {
        // 0x800B7D54: nop
    
            goto L_800B7D60;
    }
    // 0x800B7D54: nop

    // 0x800B7D58: jal         0x80088918
    // 0x800B7D5C: nop

    _fxrain_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x800B7D5C: nop

    after_1:
L_800B7D60:
    // 0x800B7D60: jal         0x800B90C8
    // 0x800B7D64: nop

    func_800B90C8(rdram, ctx);
        goto after_2;
    // 0x800B7D64: nop

    after_2:
    // 0x800B7D68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B7D6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B7D70: jr          $ra
    // 0x800B7D74: nop

    return;
    // 0x800B7D74: nop

;}
