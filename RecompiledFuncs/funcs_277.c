#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800C8560(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8560: lbu         $v0, 0x16($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X16);
    // 0x800C8564: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x800C8568: beq         $t6, $zero, L_800C8580
    if (ctx->r14 == 0) {
        // 0x800C856C: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_800C8580;
    }
    // 0x800C856C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800C8570: lbu         $t7, 0x15($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X15);
    // 0x800C8574: and         $v0, $t7, $a1
    ctx->r2 = ctx->r15 & ctx->r5;
    // 0x800C8578: sltu        $t8, $zero, $v0
    ctx->r24 = 0 < ctx->r2 ? 1 : 0;
    // 0x800C857C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800C8580:
    // 0x800C8580: jr          $ra
    // 0x800C8584: nop

    return;
    // 0x800C8584: nop

;}
RECOMP_FUNC void _scradar_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089748: syscall     792
    recomp_syscall_handler(rdram, ctx, 0x80089748);
    return;
    // 0x8008974C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80115564(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115564: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x80115568: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8011556C: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x80115570: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x80115574: lwc1        $f6, 0x18($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80115578: jr          $ra
    // 0x8011557C: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x8011557C: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
;}
RECOMP_FUNC void boot___osSetFpcCsr(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_8080056C_bsmumswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080056C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800570: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800574: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800578: jal         0x8008CABC
    // 0x8080057C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x8080057C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80800580: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800584: jal         0x8001210C
    // 0x80800588: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_8001210C(rdram, ctx);
        goto after_1;
    // 0x80800588: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_1:
    // 0x8080058C: bne         $v0, $zero, L_808005C0
    if (ctx->r2 != 0) {
        // 0x80800590: nop
    
            goto L_808005C0;
    }
    // 0x80800590: nop

    // 0x80800594: jal         0x800DC0C0
    // 0x80800598: nop

    func_800DC0C0(rdram, ctx);
        goto after_2;
    // 0x80800598: nop

    after_2:
    // 0x8080059C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808005A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808005A4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808005A8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808005AC: nop

    // 0x808005B0: bc1f        L_808005C0
    if (!c1cs) {
        // 0x808005B4: nop
    
            goto L_808005C0;
    }
    // 0x808005B4: nop

    // 0x808005B8: jal         0x8009FC34
    // 0x808005BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009FC34(rdram, ctx);
        goto after_3;
    // 0x808005BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
L_808005C0:
    // 0x808005C0: jal         0x8001210C
    // 0x808005C4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_8001210C(rdram, ctx);
        goto after_4;
    // 0x808005C4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_4:
    // 0x808005C8: bnel        $v0, $zero, L_80800600
    if (ctx->r2 != 0) {
        // 0x808005CC: lui         $a1, 0x3C23
        ctx->r5 = S32(0X3C23 << 16);
            goto L_80800600;
    }
    goto skip_0;
    // 0x808005CC: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    skip_0:
    // 0x808005D0: jal         0x800DC0C0
    // 0x808005D4: nop

    func_800DC0C0(rdram, ctx);
        goto after_5;
    // 0x808005D4: nop

    after_5:
    // 0x808005D8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808005DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808005E0: nop

    // 0x808005E4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x808005E8: nop

    // 0x808005EC: bc1fl       L_80800600
    if (!c1cs) {
        // 0x808005F0: lui         $a1, 0x3C23
        ctx->r5 = S32(0X3C23 << 16);
            goto L_80800600;
    }
    goto skip_1;
    // 0x808005F0: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    skip_1:
    // 0x808005F4: jal         0x80800000
    // 0x808005F8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80800000_bsmumswim(rdram, ctx);
        goto after_6;
    // 0x808005F8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_6:
    // 0x808005FC: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
L_80800600:
    // 0x80800600: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80800604: jal         0x8008B348
    // 0x80800608: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_7;
    // 0x80800608: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_7:
    // 0x8080060C: bne         $v0, $zero, L_80800660
    if (ctx->r2 != 0) {
        // 0x80800610: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800660;
    }
    // 0x80800610: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800614: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80800618: jal         0x8008B348
    // 0x8080061C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    anctrl_isAt(rdram, ctx);
        goto after_8;
    // 0x8080061C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_8:
    // 0x80800620: bne         $v0, $zero, L_80800660
    if (ctx->r2 != 0) {
        // 0x80800624: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800660;
    }
    // 0x80800624: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800628: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x8080062C: jal         0x8008B348
    // 0x80800630: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    anctrl_isAt(rdram, ctx);
        goto after_9;
    // 0x80800630: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_9:
    // 0x80800634: bne         $v0, $zero, L_80800660
    if (ctx->r2 != 0) {
        // 0x80800638: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800660;
    }
    // 0x80800638: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080063C: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x80800640: jal         0x8008B348
    // 0x80800644: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    anctrl_isAt(rdram, ctx);
        goto after_10;
    // 0x80800644: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    after_10:
    // 0x80800648: bne         $v0, $zero, L_80800660
    if (ctx->r2 != 0) {
        // 0x8080064C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800660;
    }
    // 0x8080064C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800650: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x80800654: jal         0x8008B348
    // 0x80800658: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    anctrl_isAt(rdram, ctx);
        goto after_11;
    // 0x80800658: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_11:
    // 0x8080065C: beq         $v0, $zero, L_8080068C
    if (ctx->r2 == 0) {
        // 0x80800660: lui         $a2, 0x3F59
        ctx->r6 = S32(0X3F59 << 16);
            goto L_8080068C;
    }
L_80800660:
    // 0x80800660: lui         $a2, 0x3F59
    ctx->r6 = S32(0X3F59 << 16);
    // 0x80800664: lui         $a3, 0x3F93
    ctx->r7 = S32(0X3F93 << 16);
    // 0x80800668: addiu       $t6, $zero, 0x4650
    ctx->r14 = ADD32(0, 0X4650);
    // 0x8080066C: addiu       $t7, $zero, 0x4650
    ctx->r15 = ADD32(0, 0X4650);
    // 0x80800670: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80800674: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800678: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x8080067C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800680: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800684: jal         0x8009DEC0
    // 0x80800688: addiu       $a1, $zero, 0x678
    ctx->r5 = ADD32(0, 0X678);
    func_8009DEC0(rdram, ctx);
        goto after_12;
    // 0x80800688: addiu       $a1, $zero, 0x678
    ctx->r5 = ADD32(0, 0X678);
    after_12:
L_8080068C:
    // 0x8080068C: jal         0x8009EF10
    // 0x80800690: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    bastick_getZone(rdram, ctx);
        goto after_13;
    // 0x80800690: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_13:
    // 0x80800694: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800698: bne         $v0, $at, L_808006A4
    if (ctx->r2 != ctx->r1) {
        // 0x8080069C: addiu       $t8, $zero, 0xF1
        ctx->r24 = ADD32(0, 0XF1);
            goto L_808006A4;
    }
    // 0x8080069C: addiu       $t8, $zero, 0xF1
    ctx->r24 = ADD32(0, 0XF1);
    // 0x808006A0: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_808006A4:
    // 0x808006A4: jal         0x8008E35C
    // 0x808006A8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    player_inWater(rdram, ctx);
        goto after_14;
    // 0x808006A8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_14:
    // 0x808006AC: bne         $v0, $zero, L_808006B8
    if (ctx->r2 != 0) {
        // 0x808006B0: addiu       $t9, $zero, 0xE5
        ctx->r25 = ADD32(0, 0XE5);
            goto L_808006B8;
    }
    // 0x808006B0: addiu       $t9, $zero, 0xE5
    ctx->r25 = ADD32(0, 0XE5);
    // 0x808006B4: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_808006B8:
    // 0x808006B8: jal         0x80097AD0
    // 0x808006BC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    bainput_should_enter_first_person(rdram, ctx);
        goto after_15;
    // 0x808006BC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_15:
    // 0x808006C0: beq         $v0, $zero, L_808006D4
    if (ctx->r2 == 0) {
        // 0x808006C4: nop
    
            goto L_808006D4;
    }
    // 0x808006C4: nop

    // 0x808006C8: jal         0x800848A8
    // 0x808006CC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    _badrone_entrypoint_24(rdram, ctx);
        goto after_16;
    // 0x808006CC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_16:
    // 0x808006D0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_808006D4:
    // 0x808006D4: jal         0x80096500
    // 0x808006D8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80096500(rdram, ctx);
        goto after_17;
    // 0x808006D8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_17:
    // 0x808006DC: beq         $v0, $zero, L_808006F8
    if (ctx->r2 == 0) {
        // 0x808006E0: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_808006F8;
    }
    // 0x808006E0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808006E4: jal         0x80091A58
    // 0x808006E8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_18;
    // 0x808006E8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_18:
    // 0x808006EC: beq         $v0, $zero, L_808006F8
    if (ctx->r2 == 0) {
        // 0x808006F0: addiu       $t0, $zero, 0xE8
        ctx->r8 = ADD32(0, 0XE8);
            goto L_808006F8;
    }
    // 0x808006F0: addiu       $t0, $zero, 0xE8
    ctx->r8 = ADD32(0, 0XE8);
    // 0x808006F4: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
L_808006F8:
    // 0x808006F8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808006FC: jal         0x8009E5C8
    // 0x80800700: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_19;
    // 0x80800700: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_19:
    // 0x80800704: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800708: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080070C: jr          $ra
    // 0x80800710: nop

    return;
    // 0x80800710: nop

;}
RECOMP_FUNC void func_8080098C_chflamer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080098C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800990: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1088, 0XB68) << 16);
    // 0x80800994: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800998: addiu       $t6, $t6, 0xB68
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1088, 0XB68));
    // 0x8080099C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808009A0: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x808009A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808009A8: jal         0x80089D58
    // 0x808009AC: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    _subaddieaudioloop_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x808009AC: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    after_0:
    // 0x808009B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808009B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808009B8: jr          $ra
    // 0x808009BC: nop

    return;
    // 0x808009BC: nop

;}
RECOMP_FUNC void func_800A391C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A391C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800A3920: lw          $t6, 0xA0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA0);
    // 0x800A3924: jr          $ra
    // 0x800A3928: swc1        $f12, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x800A3928: swc1        $f12, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_80801954_chfactoryrobot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801954: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801958: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080195C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80801960: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80801964: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80801968: jal         0x80100094
    // 0x8080196C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080196C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801970: jal         0x800D8FF8
    // 0x80801974: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80801974: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_1:
    // 0x80801978: lhu         $t6, 0x72($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0X72);
    // 0x8080197C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80801980: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80801984: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80801988: beq         $t7, $at, L_80801A04
    if (ctx->r15 == ctx->r1) {
        // 0x8080198C: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80801A04;
    }
    // 0x8080198C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80801990: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801994: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80801998: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080199C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808019A0: lwc1        $f12, 0x10($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X10);
    // 0x808019A4: lwc1        $f14, 0x54($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X54);
    // 0x808019A8: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x808019AC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x808019B0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808019B4: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x808019B8: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x808019BC: jal         0x800F1FF0
    // 0x808019C0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F1FF0(rdram, ctx);
        goto after_2;
    // 0x808019C0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x808019C4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808019C8: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808019CC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808019D0: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x808019D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808019D8: mul.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x808019DC: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x808019E0: lwc1        $f14, 0x54($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X54);
    // 0x808019E4: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x808019E8: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x808019EC: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x808019F0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808019F4: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x808019F8: jal         0x800F1FF0
    // 0x808019FC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F1FF0(rdram, ctx);
        goto after_3;
    // 0x808019FC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x80801A00: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
L_80801A04:
    // 0x80801A04: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80801A08: jal         0x8010262C
    // 0x80801A0C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010262C(rdram, ctx);
        goto after_4;
    // 0x80801A0C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x80801A10: beq         $v0, $zero, L_80801A6C
    if (ctx->r2 == 0) {
        // 0x80801A14: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80801A6C;
    }
    // 0x80801A14: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80801A18: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80801A1C: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80801A20: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801A24: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80801A28: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80801A2C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801A30: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80801A34: jal         0x800E0AFC
    // 0x80801A38: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_5;
    // 0x80801A38: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x80801A3C: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80801A40: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80801A44: jal         0x800136E4
    // 0x80801A48: sub.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f16.fl;
    func_800136E4(rdram, ctx);
        goto after_6;
    // 0x80801A48: sub.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f16.fl;
    after_6:
    // 0x80801A4C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80801A50: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801A54: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x80801A58: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80801A5C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801A60: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80801A64: jal         0x800E0AFC
    // 0x80801A68: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_7;
    // 0x80801A68: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    after_7:
L_80801A6C:
    // 0x80801A6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801A70: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80801A74: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80801A78: jr          $ra
    // 0x80801A7C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80801A7C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _bsbeemain_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800828C8: syscall     17
    recomp_syscall_handler(rdram, ctx, 0x800828C8);
    return;
    // 0x800828CC: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_80800478_bsdronebitten(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800478: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080047C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800480: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800484: jal         0x8008E124
    // 0x80800488: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8008E124(rdram, ctx);
        goto after_0;
    // 0x80800488: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080048C: beq         $v0, $zero, L_808004A4
    if (ctx->r2 == 0) {
        // 0x80800490: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808004A4;
    }
    // 0x80800490: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800494: jal         0x80084740
    // 0x80800498: nop

    _badata_entrypoint_32(rdram, ctx);
        goto after_1;
    // 0x80800498: nop

    after_1:
    // 0x8080049C: b           L_808004B0
    // 0x808004A0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_808004B0;
    // 0x808004A0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_808004A4:
    // 0x808004A4: jal         0x80084750
    // 0x808004A8: nop

    _badata_entrypoint_34(rdram, ctx);
        goto after_2;
    // 0x808004A8: nop

    after_2:
    // 0x808004AC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_808004B0:
    // 0x808004B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004B8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x808004BC: jr          $ra
    // 0x808004C0: nop

    return;
    // 0x808004C0: nop

;}
RECOMP_FUNC void func_800CA364(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA364: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CA368: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CA36C: jal         0x8001B084
    // 0x800CA370: nop

    heap_free(rdram, ctx);
        goto after_0;
    // 0x800CA370: nop

    after_0:
    // 0x800CA374: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CA378: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CA37C: jr          $ra
    // 0x800CA380: nop

    return;
    // 0x800CA380: nop

;}
RECOMP_FUNC void _sumole_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089A58: syscall     800
    recomp_syscall_handler(rdram, ctx, 0x80089A58);
    return;
    // 0x80089A5C: addi        $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
;}
RECOMP_FUNC void bstrexlarge_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808017C8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808017CC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(412, 0X1A30) << 16);
    // 0x808017D0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808017D4: jr          $ra
    // 0x808017D8: lw          $v0, 0x1A30($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(412, 0X1A30));
    return;
    // 0x808017D8: lw          $v0, 0x1A30($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(412, 0X1A30));
;}
RECOMP_FUNC void func_80112518(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80112518: lw          $t6, 0x30($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X30);
    // 0x8011251C: jr          $ra
    // 0x80112520: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    return;
    // 0x80112520: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
;}
RECOMP_FUNC void fxstep_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800518: jr          $ra
    // 0x8080051C: sb          $a1, 0x27($a0)
    MEM_B(0X27, ctx->r4) = ctx->r5;
    return;
    // 0x8080051C: sb          $a1, 0x27($a0)
    MEM_B(0X27, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void bssnowball_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800300: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800304: jal         0x800A3274
    // 0x80800308: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800A3274(rdram, ctx);
        goto after_0;
    // 0x80800308: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080030C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800310: bnel        $v0, $at, L_808003A0
    if (ctx->r2 != ctx->r1) {
        // 0x80800314: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808003A0;
    }
    goto skip_0;
    // 0x80800314: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800318: lbu         $t6, 0x165($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X165);
    // 0x8080031C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800320: beq         $t6, $zero, L_80800338
    if (ctx->r14 == 0) {
        // 0x80800324: nop
    
            goto L_80800338;
    }
    // 0x80800324: nop

    // 0x80800328: jal         0x80085120
    // 0x8080032C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    _basnowball_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x8080032C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x80800330: b           L_80800350
    // 0x80800334: lbu         $t7, 0x165($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X165);
        goto L_80800350;
    // 0x80800334: lbu         $t7, 0x165($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X165);
L_80800338:
    // 0x80800338: jal         0x8009BB5C
    // 0x8080033C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB5C(rdram, ctx);
        goto after_2;
    // 0x8080033C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800340: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800344: jal         0x80085120
    // 0x80800348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basnowball_entrypoint_9(rdram, ctx);
        goto after_3;
    // 0x80800348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080034C: lbu         $t7, 0x165($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X165);
L_80800350:
    // 0x80800350: bnel        $t7, $zero, L_8080037C
    if (ctx->r15 != 0) {
        // 0x80800354: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080037C;
    }
    goto skip_1;
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80800358: jal         0x8009BB00
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800360: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800368: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x8080036C: nop

    // 0x80800370: bc1f        L_8080038C
    if (!c1cs) {
        // 0x80800374: nop
    
            goto L_8080038C;
    }
    // 0x80800374: nop

    // 0x80800378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080037C:
    // 0x8080037C: jal         0x80085118
    // 0x80800380: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _basnowball_entrypoint_8(rdram, ctx);
        goto after_5;
    // 0x80800380: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800384: b           L_80800394
    // 0x80800388: nop

        goto L_80800394;
    // 0x80800388: nop

L_8080038C:
    // 0x8080038C: jal         0x80085118
    // 0x80800390: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _basnowball_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x80800390: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
L_80800394:
    // 0x80800394: jal         0x80085138
    // 0x80800398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basnowball_entrypoint_12(rdram, ctx);
        goto after_7;
    // 0x80800398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080039C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808003A0:
    // 0x808003A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003A8: jr          $ra
    // 0x808003AC: nop

    return;
    // 0x808003AC: nop

;}
RECOMP_FUNC void func_800AA20C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA20C: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x800AA210: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AA214: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800AA218: jr          $ra
    // 0x800AA21C: sh          $a1, 0x778C($at)
    MEM_H(0X778C, ctx->r1) = ctx->r5;
    return;
    // 0x800AA21C: sh          $a1, 0x778C($at)
    MEM_H(0X778C, ctx->r1) = ctx->r5;
;}
RECOMP_FUNC void func_80800024_chmole_cuckoo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800028: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080002C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800030: jal         0x800899D0
    // 0x80800034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _sumole_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800038: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080003C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800040: lhu         $v0, 0x76($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X76);
    // 0x80800044: srl         $t6, $v0, 7
    ctx->r14 = S32(U32(ctx->r2) >> 7);
    // 0x80800048: addiu       $t8, $t6, -0x32
    ctx->r24 = ADD32(ctx->r14, -0X32);
    // 0x8080004C: sll         $t0, $t8, 7
    ctx->r8 = S32(ctx->r24 << 7);
    // 0x80800050: andi        $t1, $v0, 0x7F
    ctx->r9 = ctx->r2 & 0X7F;
    // 0x80800054: or          $t2, $t0, $t1
    ctx->r10 = ctx->r8 | ctx->r9;
    // 0x80800058: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x8080005C: srl         $t4, $t3, 7
    ctx->r12 = S32(U32(ctx->r11) >> 7);
    // 0x80800060: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80800064: sh          $t2, 0x76($a0)
    MEM_H(0X76, ctx->r4) = ctx->r10;
    // 0x80800068: bgez        $t4, L_8080007C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8080006C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8080007C;
    }
    // 0x8080006C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800070: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800074: nop

    // 0x80800078: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8080007C:
    // 0x8080007C: swc1        $f6, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f6.u32l;
    // 0x80800080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800084: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800088: jr          $ra
    // 0x8080008C: nop

    return;
    // 0x8080008C: nop

;}
RECOMP_FUNC void func_801045AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801045AC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801045B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801045B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801045B8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x801045BC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x801045C0: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x801045C4: jal         0x80104410
    // 0x801045C8: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    func_80104410(rdram, ctx);
        goto after_0;
    // 0x801045C8: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_0:
    // 0x801045CC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801045D0: jal         0x80104958
    // 0x801045D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80104958(rdram, ctx);
        goto after_1;
    // 0x801045D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x801045D8: jal         0x800AAAE0
    // 0x801045DC: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    func_800AAAE0(rdram, ctx);
        goto after_2;
    // 0x801045DC: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    after_2:
    // 0x801045E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801045E4: jal         0x8010486C
    // 0x801045E8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_8010486C(rdram, ctx);
        goto after_3;
    // 0x801045E8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_3:
    // 0x801045EC: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x801045F0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801045F4: lbu         $t0, 0x28($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X28);
    // 0x801045F8: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x801045FC: sb          $t8, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r24;
    // 0x80104600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80104604: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80104608: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8010460C: nop

    // 0x80104610: sh          $t7, 0x16($s0)
    MEM_H(0X16, ctx->r16) = ctx->r15;
    // 0x80104614: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x80104618: bne         $t0, $zero, L_80104654
    if (ctx->r8 != 0) {
        // 0x8010461C: sw          $t9, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r25;
            goto L_80104654;
    }
    // 0x8010461C: sw          $t9, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r25;
    // 0x80104620: jal         0x801049B4
    // 0x80104624: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    func_801049B4(rdram, ctx);
        goto after_4;
    // 0x80104624: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_4:
    // 0x80104628: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8010462C: jal         0x80104D80
    // 0x80104630: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    func_80104D80(rdram, ctx);
        goto after_5;
    // 0x80104630: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_5:
    // 0x80104634: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80104638: jal         0x80104E24
    // 0x8010463C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_80104E24(rdram, ctx);
        goto after_6;
    // 0x8010463C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_6:
    // 0x80104640: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80104644: jal         0x80089CE8
    // 0x80104648: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    _subaddiefade_entrypoint_11(rdram, ctx);
        goto after_7;
    // 0x80104648: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_7:
    // 0x8010464C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80104650: sb          $t1, 0x28($s0)
    MEM_B(0X28, ctx->r16) = ctx->r9;
L_80104654:
    // 0x80104654: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80104658: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8010465C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80104660: jr          $ra
    // 0x80104664: nop

    return;
    // 0x80104664: nop

;}
RECOMP_FUNC void func_800C191C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C191C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C1920: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C1924: beq         $a0, $zero, L_800C1940
    if (ctx->r4 == 0) {
        // 0x800C1928: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_800C1940;
    }
    // 0x800C1928: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C192C: jal         0x800C1448
    // 0x800C1930: nop

    func_800C1448(rdram, ctx);
        goto after_0;
    // 0x800C1930: nop

    after_0:
    // 0x800C1934: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C1938: jal         0x800DC4B0
    // 0x800C193C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800DC4B0(rdram, ctx);
        goto after_1;
    // 0x800C193C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
L_800C1940:
    // 0x800C1940: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C1944: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C1948: jr          $ra
    // 0x800C194C: nop

    return;
    // 0x800C194C: nop

;}
RECOMP_FUNC void func_8008E40C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E40C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008E410: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008E414: jal         0x80084FE0
    // 0x8008E418: nop

    _bashoes_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8008E418: nop

    after_0:
    // 0x8008E41C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008E420: xori        $t6, $v0, 0x4
    ctx->r14 = ctx->r2 ^ 0X4;
    // 0x8008E424: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8008E428: jr          $ra
    // 0x8008E42C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8008E42C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8009989C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009989C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800998A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800998A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800998A8: lw          $a2, 0xC0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XC0);
    // 0x800998AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800998B0: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800998B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800998B8: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
L_800998BC:
    // 0x800998BC: lw          $t6, 0x4C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4C);
    // 0x800998C0: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // 0x800998C4: slti        $at, $v0, 0xC8
    ctx->r1 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
    // 0x800998C8: beql        $a3, $t6, L_80099960
    if (ctx->r7 == ctx->r14) {
        // 0x800998CC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80099960;
    }
    goto skip_0;
    // 0x800998CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800998D0: bne         $at, $zero, L_800998BC
    if (ctx->r1 != 0) {
        // 0x800998D4: addiu       $v1, $v1, 0x28
        ctx->r3 = ADD32(ctx->r3, 0X28);
            goto L_800998BC;
    }
    // 0x800998D4: addiu       $v1, $v1, 0x28
    ctx->r3 = ADD32(ctx->r3, 0X28);
    // 0x800998D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800998DC: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x800998E0: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
L_800998E4:
    // 0x800998E4: lw          $t7, 0x4C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4C);
    // 0x800998E8: bnel        $t7, $zero, L_80099954
    if (ctx->r15 != 0) {
        // 0x800998EC: addiu       $v0, $v0, 0x28
        ctx->r2 = ADD32(ctx->r2, 0X28);
            goto L_80099954;
    }
    goto skip_1;
    // 0x800998EC: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    skip_1:
    // 0x800998F0: sw          $a3, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->r7;
    // 0x800998F4: lw          $a2, 0xC0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC0);
    // 0x800998F8: lw          $t8, 0x18($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X18);
    // 0x800998FC: addu        $t9, $a2, $v0
    ctx->r25 = ADD32(ctx->r6, ctx->r2);
    // 0x80099900: sw          $t8, 0x40($t9)
    MEM_W(0X40, ctx->r25) = ctx->r24;
    // 0x80099904: lw          $a2, 0xC0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC0);
    // 0x80099908: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8009990C: addu        $t1, $a2, $v0
    ctx->r9 = ADD32(ctx->r6, ctx->r2);
    // 0x80099910: swc1        $f4, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->f4.u32l;
    // 0x80099914: lw          $a2, 0xC0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC0);
    // 0x80099918: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8009991C: addu        $t2, $a2, $v0
    ctx->r10 = ADD32(ctx->r6, ctx->r2);
    // 0x80099920: swc1        $f6, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->f6.u32l;
    // 0x80099924: lw          $a2, 0xC0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC0);
    // 0x80099928: lw          $t3, 0x14($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X14);
    // 0x8009992C: addu        $t4, $a2, $v0
    ctx->r12 = ADD32(ctx->r6, ctx->r2);
    // 0x80099930: sw          $t3, 0x3C($t4)
    MEM_W(0X3C, ctx->r12) = ctx->r11;
    // 0x80099934: lw          $a2, 0xC0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC0);
    // 0x80099938: addu        $a0, $a2, $v0
    ctx->r4 = ADD32(ctx->r6, ctx->r2);
    // 0x8009993C: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    // 0x80099940: jal         0x800EE7F8
    // 0x80099944: addiu       $a1, $a2, 0x8
    ctx->r5 = ADD32(ctx->r6, 0X8);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80099944: addiu       $a1, $a2, 0x8
    ctx->r5 = ADD32(ctx->r6, 0X8);
    after_0:
    // 0x80099948: b           L_80099960
    // 0x8009994C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80099960;
    // 0x8009994C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80099950: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
L_80099954:
    // 0x80099954: bne         $v0, $a0, L_800998E4
    if (ctx->r2 != ctx->r4) {
        // 0x80099958: addiu       $v1, $v1, 0x28
        ctx->r3 = ADD32(ctx->r3, 0X28);
            goto L_800998E4;
    }
    // 0x80099958: addiu       $v1, $v1, 0x28
    ctx->r3 = ADD32(ctx->r3, 0X28);
    // 0x8009995C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80099960:
    // 0x80099960: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80099964: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80099968: jr          $ra
    // 0x8009996C: nop

    return;
    // 0x8009996C: nop

;}
RECOMP_FUNC void _baeggaim_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084AA0: syscall     127
    recomp_syscall_handler(rdram, ctx, 0x80084AA0);
    return;
    // 0x80084AA4: xori        $t0, $zero, 0x8
    ctx->r8 = 0 ^ 0X8;
;}
RECOMP_FUNC void func_800E7988(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E7988: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E798C: addiu       $v0, $v0, -0x2A80
    ctx->r2 = ADD32(ctx->r2, -0X2A80);
    // 0x800E7990: lw          $t6, 0x1C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1C);
    // 0x800E7994: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E7998: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E799C: beql        $a1, $t6, L_800E79DC
    if (ctx->r5 == ctx->r14) {
        // 0x800E79A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800E79DC;
    }
    goto skip_0;
    // 0x800E79A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800E79A4: sw          $a1, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r5;
    // 0x800E79A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800E79AC: jal         0x800E765C
    // 0x800E79B0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800E765C(rdram, ctx);
        goto after_0;
    // 0x800E79B0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800E79B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800E79B8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800E79BC: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x800E79C0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800E79C4: ori         $t8, $t8, 0xC00
    ctx->r24 = ctx->r24 | 0XC00;
    // 0x800E79C8: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800E79CC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800E79D0: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x800E79D4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800E79D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E79DC:
    // 0x800E79DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E79E0: jr          $ra
    // 0x800E79E4: nop

    return;
    // 0x800E79E4: nop

;}
RECOMP_FUNC void func_8008EE1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008EE1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008EE20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008EE24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008EE28: jal         0x800F53D0
    // 0x8008EE2C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800F53D0(rdram, ctx);
        goto after_0;
    // 0x8008EE2C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8008EE30: jal         0x8009E6F8
    // 0x8008EE34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    bs_getCurrentState(rdram, ctx);
        goto after_1;
    // 0x8008EE34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8008EE38: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8008EE3C: beq         $v0, $at, L_8008EE58
    if (ctx->r2 == ctx->r1) {
        // 0x8008EE40: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8008EE58;
    }
    // 0x8008EE40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008EE44: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x8008EE48: beq         $v0, $at, L_8008EE70
    if (ctx->r2 == ctx->r1) {
        // 0x8008EE4C: lw          $t0, 0x18($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X18);
            goto L_8008EE70;
    }
    // 0x8008EE4C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8008EE50: b           L_8008EE80
    // 0x8008EE54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8008EE80;
    // 0x8008EE54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008EE58:
    // 0x8008EE58: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8008EE5C: lw          $v0, 0x74($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X74);
    // 0x8008EE60: sll         $t7, $v0, 12
    ctx->r15 = S32(ctx->r2 << 12);
    // 0x8008EE64: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x8008EE68: b           L_8008EE80
    // 0x8008EE6C: sltiu       $v0, $t8, 0x1
    ctx->r2 = ctx->r24 < 0X1 ? 1 : 0;
        goto L_8008EE80;
    // 0x8008EE6C: sltiu       $v0, $t8, 0x1
    ctx->r2 = ctx->r24 < 0X1 ? 1 : 0;
L_8008EE70:
    // 0x8008EE70: lhu         $v0, 0x74($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X74);
    // 0x8008EE74: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x8008EE78: b           L_8008EE80
    // 0x8008EE7C: sltiu       $v0, $t1, 0x1
    ctx->r2 = ctx->r9 < 0X1 ? 1 : 0;
        goto L_8008EE80;
    // 0x8008EE7C: sltiu       $v0, $t1, 0x1
    ctx->r2 = ctx->r9 < 0X1 ? 1 : 0;
L_8008EE80:
    // 0x8008EE80: jr          $ra
    // 0x8008EE84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8008EE84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80801EA8_chlakemonster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801EA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801EAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801EB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801EB4: jal         0x80085840
    // 0x80801EB8: addiu       $a1, $zero, 0x187
    ctx->r5 = ADD32(0, 0X187);
    _chswitch_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80801EB8: addiu       $a1, $zero, 0x187
    ctx->r5 = ADD32(0, 0X187);
    after_0:
    // 0x80801EBC: jal         0x800DA298
    // 0x80801EC0: addiu       $a0, $zero, 0x187
    ctx->r4 = ADD32(0, 0X187);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80801EC0: addiu       $a0, $zero, 0x187
    ctx->r4 = ADD32(0, 0X187);
    after_1:
    // 0x80801EC4: beql        $v0, $zero, L_80801ED8
    if (ctx->r2 == 0) {
        // 0x80801EC8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801ED8;
    }
    goto skip_0;
    // 0x80801EC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801ECC: jal         0x8010A570
    // 0x80801ED0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8010A570(rdram, ctx);
        goto after_2;
    // 0x80801ED0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80801ED4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801ED8:
    // 0x80801ED8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801EDC: jr          $ra
    // 0x80801EE0: nop

    return;
    // 0x80801EE0: nop

;}
RECOMP_FUNC void func_8080000C_chdiggerbossdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800010: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800014: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800018: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080001C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800020: jal         0x800EA090
    // 0x80800024: swc1        $f4, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f4.u32l;
    func_800EA090(rdram, ctx);
        goto after_0;
    // 0x80800024: swc1        $f4, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f4.u32l;
    after_0:
    // 0x80800028: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8080002C: bne         $v0, $at, L_8080009C
    if (ctx->r2 != ctx->r1) {
        // 0x80800030: lui         $at, 0xC3FA
        ctx->r1 = S32(0XC3FA << 16);
            goto L_8080009C;
    }
    // 0x80800030: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
    // 0x80800034: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800038: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    // 0x8080003C: jal         0x800DA298
    // 0x80800040: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800040: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
    after_1:
    // 0x80800044: beql        $v0, $zero, L_808000A0
    if (ctx->r2 == 0) {
        // 0x80800048: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808000A0;
    }
    goto skip_0;
    // 0x80800048: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080004C: jal         0x80800370
    // 0x80800050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800370_chdiggerbossdoor(rdram, ctx);
        goto after_2;
    // 0x80800050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800058: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x8080005C: jal         0x8010108C
    // 0x80800060: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_3;
    // 0x80800060: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80800064: jal         0x800F54E4
    // 0x80800068: nop

    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x80800068: nop

    after_4:
    // 0x8080006C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800070: jal         0x800F8294
    // 0x80800074: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800F8294(rdram, ctx);
        goto after_5;
    // 0x80800074: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_5:
    // 0x80800078: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080007C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800080: addiu       $a2, $zero, 0x55
    ctx->r6 = ADD32(0, 0X55);
    // 0x80800084: jal         0x80085748
    // 0x80800088: addiu       $a3, $zero, 0x2010
    ctx->r7 = ADD32(0, 0X2010);
    _capod_entrypoint_21(rdram, ctx);
        goto after_6;
    // 0x80800088: addiu       $a3, $zero, 0x2010
    ctx->r7 = ADD32(0, 0X2010);
    after_6:
    // 0x8080008C: lhu         $t6, 0x6E($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800090: andi        $t7, $t6, 0xFE00
    ctx->r15 = ctx->r14 & 0XFE00;
    // 0x80800094: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80800098: sh          $t8, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r24;
L_8080009C:
    // 0x8080009C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000A0:
    // 0x808000A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000A8: jr          $ra
    // 0x808000AC: nop

    return;
    // 0x808000AC: nop

;}
RECOMP_FUNC void bssplitup_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080000C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800010: jal         0x800A3410
    // 0x80800014: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_800A3410(rdram, ctx);
        goto after_0;
    // 0x80800014: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_0:
    // 0x80800018: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080001C: jal         0x80084788
    // 0x80800020: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _bapackctrl_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80800020: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x80800024: lui         $a2, 0x400C
    ctx->r6 = S32(0X400C << 16);
    // 0x80800028: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8080002C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800030: jal         0x8008CCBC
    // 0x80800034: addiu       $a1, $zero, 0xA2
    ctx->r5 = ADD32(0, 0XA2);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_2;
    // 0x80800034: addiu       $a1, $zero, 0xA2
    ctx->r5 = ADD32(0, 0XA2);
    after_2:
    // 0x80800038: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8080003C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800044: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800048: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080004C: jal         0x8009FFD8
    // 0x80800050: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_3;
    // 0x80800050: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_3:
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800058: jal         0x8009B94C
    // 0x8080005C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009B94C(rdram, ctx);
        goto after_4;
    // 0x8080005C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800064: jal         0x8009BA9C
    // 0x80800068: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009BA9C(rdram, ctx);
        goto after_5;
    // 0x80800068: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8080006C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800070: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800074: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800078: jr          $ra
    // 0x8080007C: nop

    return;
    // 0x8080007C: nop

;}
RECOMP_FUNC void func_8010D5DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010D5DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010D5E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010D5E4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8010D5E8: jal         0x8010114C
    // 0x8010D5EC: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    func_8010114C(rdram, ctx);
        goto after_0;
    // 0x8010D5EC: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    after_0:
    // 0x8010D5F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010D5F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010D5F8: jr          $ra
    // 0x8010D5FC: nop

    return;
    // 0x8010D5FC: nop

;}
RECOMP_FUNC void func_80802700_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802700: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802704: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802708: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080270C: jal         0x800A3280
    // 0x80802710: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800A3280(rdram, ctx);
        goto after_0;
    // 0x80802710: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80802714: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80802718: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x8080271C: lui         $t7, 0x8081
    ctx->r15 = S32(RELOC_HI16(439, 0XB118) << 16);
    // 0x80802720: addiu       $t7, $t7, -0x4EE8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(439, 0XB118));
    // 0x80802724: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x80802728: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8080272C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80802730: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80802734: lui         $t0, 0x8081
    ctx->r8 = S32(RELOC_HI16(439, 0XB140) << 16);
    // 0x80802738: addiu       $t0, $t0, -0x4EC0
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(439, 0XB140));
    // 0x8080273C: addu        $t1, $t6, $t0
    ctx->r9 = ADD32(ctx->r14, ctx->r8);
    // 0x80802740: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80802744: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802748: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080274C: jr          $ra
    // 0x80802750: nop

    return;
    // 0x80802750: nop

;}
RECOMP_FUNC void func_8080087C_chcrusherboulder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080087C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800880: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800884: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800888: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x8080088C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800890: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800894: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800898: beq         $t6, $at, L_808008BC
    if (ctx->r14 == ctx->r1) {
        // 0x8080089C: addiu       $a0, $zero, 0x9DE
        ctx->r4 = ADD32(0, 0X9DE);
            goto L_808008BC;
    }
    // 0x8080089C: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    // 0x808008A0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x808008A4: beq         $t6, $at, L_808008DC
    if (ctx->r14 == ctx->r1) {
        // 0x808008A8: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_808008DC;
    }
    // 0x808008A8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x808008AC: beq         $t6, $at, L_80800944
    if (ctx->r14 == ctx->r1) {
        // 0x808008B0: nop
    
            goto L_80800944;
    }
    // 0x808008B0: nop

    // 0x808008B4: b           L_808009B0
    // 0x808008B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808009B0;
    // 0x808008B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808008BC:
    // 0x808008BC: jal         0x800DA9E4
    // 0x808008C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DA9E4(rdram, ctx);
        goto after_0;
    // 0x808008C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808008C4: beq         $v0, $zero, L_808009AC
    if (ctx->r2 == 0) {
        // 0x808008C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009AC;
    }
    // 0x808008C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008CC: jal         0x80800A1C
    // 0x808008D0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80800A1C_chcrusherboulder(rdram, ctx);
        goto after_1;
    // 0x808008D0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_1:
    // 0x808008D4: b           L_808009B0
    // 0x808008D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808009B0;
    // 0x808008D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808008DC:
    // 0x808008DC: jal         0x80800210
    // 0x808008E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800210_chcrusherboulder(rdram, ctx);
        goto after_2;
    // 0x808008E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808008E4: jal         0x808001CC
    // 0x808008E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001CC_chcrusherboulder(rdram, ctx);
        goto after_3;
    // 0x808008E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808008EC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808008F0: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808008F4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808008F8: nop

    // 0x808008FC: bc1fl       L_80800920
    if (!c1cs) {
        // 0x80800900: lw          $t7, 0x64($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X64);
            goto L_80800920;
    }
    goto skip_0;
    // 0x80800900: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    skip_0:
    // 0x80800904: jal         0x800D8FF8
    // 0x80800908: nop

    func_800D8FF8(rdram, ctx);
        goto after_4;
    // 0x80800908: nop

    after_4:
    // 0x8080090C: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800910: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80800914: b           L_808009AC
    // 0x80800918: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
        goto L_808009AC;
    // 0x80800918: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    // 0x8080091C: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
L_80800920:
    // 0x80800920: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x80800924: bltzl       $t9, L_808009B0
    if (SIGNED(ctx->r25) < 0) {
        // 0x80800928: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808009B0;
    }
    goto skip_1;
    // 0x80800928: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8080092C: jal         0x80086AF0
    // 0x80800930: nop

    _chglowbo_entrypoint_6(rdram, ctx);
        goto after_5;
    // 0x80800930: nop

    after_5:
    // 0x80800934: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    // 0x80800938: ori         $t2, $t1, 0x8
    ctx->r10 = ctx->r9 | 0X8;
    // 0x8080093C: b           L_808009AC
    // 0x80800940: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
        goto L_808009AC;
    // 0x80800940: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
L_80800944:
    // 0x80800944: jal         0x800D8FF8
    // 0x80800948: nop

    func_800D8FF8(rdram, ctx);
        goto after_6;
    // 0x80800948: nop

    after_6:
    // 0x8080094C: lwc1        $f16, 0x58($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800950: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800954: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x80800958: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    // 0x8080095C: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800960: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800964: nop

    // 0x80800968: bc1fl       L_808009B0
    if (!c1cs) {
        // 0x8080096C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808009B0;
    }
    goto skip_2;
    // 0x8080096C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80800970: jal         0x8001211C
    // 0x80800974: nop

    func_8001211C(rdram, ctx);
        goto after_7;
    // 0x80800974: nop

    after_7:
    // 0x80800978: andi        $t3, $v0, 0x2
    ctx->r11 = ctx->r2 & 0X2;
    // 0x8080097C: bnel        $t3, $zero, L_808009B0
    if (ctx->r11 != 0) {
        // 0x80800980: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808009B0;
    }
    goto skip_3;
    // 0x80800980: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80800984: jal         0x800DC0C0
    // 0x80800988: nop

    func_800DC0C0(rdram, ctx);
        goto after_8;
    // 0x80800988: nop

    after_8:
    // 0x8080098C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1640, 0X12E8) << 16);
    // 0x80800990: lwc1        $f8, 0x12E8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1640, 0X12E8));
    // 0x80800994: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80800998: nop

    // 0x8080099C: bc1fl       L_808009B0
    if (!c1cs) {
        // 0x808009A0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808009B0;
    }
    goto skip_4;
    // 0x808009A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x808009A4: jal         0x808010EC
    // 0x808009A8: nop

    func_808010EC_chcrusherboulder(rdram, ctx);
        goto after_9;
    // 0x808009A8: nop

    after_9:
L_808009AC:
    // 0x808009AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808009B0:
    // 0x808009B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808009B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808009B8: jr          $ra
    // 0x808009BC: nop

    return;
    // 0x808009BC: nop

;}
RECOMP_FUNC void func_80801BA4_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801BA4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801BA8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X4488) << 16);
    // 0x80801BAC: lwc1        $f4, 0x4488($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1632, 0X4488));
    // 0x80801BB0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801BB4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80801BB8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801BBC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80801BC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801BC4: jal         0x80100094
    // 0x80801BC8: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801BC8: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80801BCC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80801BD0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801BD4: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80801BD8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80801BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801BE0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80801BE4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80801BE8: jal         0x80105A9C
    // 0x80801BEC: nop

    func_80105A9C(rdram, ctx);
        goto after_1;
    // 0x80801BEC: nop

    after_1:
    // 0x80801BF0: jal         0x80105834
    // 0x80801BF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105834(rdram, ctx);
        goto after_2;
    // 0x80801BF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801BF8: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80801BFC: jal         0x800F1DCC
    // 0x80801C00: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    func_800F1DCC(rdram, ctx);
        goto after_3;
    // 0x80801C00: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    after_3:
    // 0x80801C04: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80801C08: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801C0C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80801C10: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80801C14: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80801C18: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80801C1C: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    // 0x80801C20: jal         0x800F10B4
    // 0x80801C24: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x80801C24: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x80801C28: lbu         $t6, 0x8F7($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X8F7);
    // 0x80801C2C: swc1        $f0, 0x920($s1)
    MEM_W(0X920, ctx->r17) = ctx->f0.u32l;
    // 0x80801C30: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80801C34: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801C38: bne         $t6, $zero, L_80801C50
    if (ctx->r14 != 0) {
        // 0x80801C3C: swc1        $f4, 0x8($s1)
        MEM_W(0X8, ctx->r17) = ctx->f4.u32l;
            goto L_80801C50;
    }
    // 0x80801C3C: swc1        $f4, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f4.u32l;
    // 0x80801C40: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801C44: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80801C48: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x80801C4C: sb          $t7, 0x8F7($s1)
    MEM_B(0X8F7, ctx->r17) = ctx->r15;
L_80801C50:
    // 0x80801C50: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80801C54: jal         0x800F1DCC
    // 0x80801C58: lwc1        $f14, 0x44($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X44);
    func_800F1DCC(rdram, ctx);
        goto after_5;
    // 0x80801C58: lwc1        $f14, 0x44($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X44);
    after_5:
    // 0x80801C5C: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80801C60: lwc1        $f8, 0x44($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80801C64: lwc1        $f12, 0x54($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80801C68: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80801C6C: lwc1        $f14, 0x48($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80801C70: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80801C74: jal         0x800F1DCC
    // 0x80801C78: swc1        $f18, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f18.u32l;
    func_800F1DCC(rdram, ctx);
        goto after_6;
    // 0x80801C78: swc1        $f18, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f18.u32l;
    after_6:
    // 0x80801C7C: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80801C80: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80801C84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C88: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80801C8C: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80801C90: jal         0x80801850
    // 0x80801C94: swc1        $f8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f8.u32l;
    func_80801850_chhandcart(rdram, ctx);
        goto after_7;
    // 0x80801C94: swc1        $f8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f8.u32l;
    after_7:
    // 0x80801C98: jal         0x80800CD0
    // 0x80801C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800CD0_chhandcart(rdram, ctx);
        goto after_8;
    // 0x80801C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80801CA0: jal         0x80801290
    // 0x80801CA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801290_chhandcart(rdram, ctx);
        goto after_9;
    // 0x80801CA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80801CA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801CAC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80801CB0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80801CB4: jr          $ra
    // 0x80801CB8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80801CB8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void bskaztorpedo_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E84: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800E88: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(296, 0X1760) << 16);
    // 0x80800E8C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800E90: jr          $ra
    // 0x80800E94: lw          $v0, 0x1760($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(296, 0X1760));
    return;
    // 0x80800E94: lw          $v0, 0x1760($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(296, 0X1760));
;}
RECOMP_FUNC void func_80800D30_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D38: jal         0x80085148
    // 0x80800D3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _baspin_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800D3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800D40: jal         0x80800104
    // 0x80800D44: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800104_bsbswim(rdram, ctx);
        goto after_1;
    // 0x80800D44: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800D48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D50: jr          $ra
    // 0x80800D54: nop

    return;
    // 0x80800D54: nop

;}
RECOMP_FUNC void _fxfontstring_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088990: syscall     713
    recomp_syscall_handler(rdram, ctx, 0x80088990);
    return;
    // 0x80088994: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800D3A14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3A14: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D3A18: jr          $ra
    // 0x800D3A1C: sb          $a0, -0x4C0D($at)
    MEM_B(-0X4C0D, ctx->r1) = ctx->r4;
    return;
    // 0x800D3A1C: sb          $a0, -0x4C0D($at)
    MEM_B(-0X4C0D, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_800AA240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA240: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AA244: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AA248: jal         0x800AA0C4
    // 0x800AA24C: nop

    func_800AA0C4(rdram, ctx);
        goto after_0;
    // 0x800AA24C: nop

    after_0:
    // 0x800AA250: jal         0x800AA0D0
    // 0x800AA254: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800AA0D0(rdram, ctx);
        goto after_1;
    // 0x800AA254: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x800AA258: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800AA25C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AA260: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x800AA264: slt         $v0, $t6, $t7
    ctx->r2 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800AA268: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x800AA26C: jr          $ra
    // 0x800AA270: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800AA270: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80800388_chdingpot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "func_80800388_chdingpot");
    // 0x80800388: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080038C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800390: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80800394: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800398: jal         0x800DA298
    // 0x8080039C: addiu       $a0, $zero, 0x1AC
    ctx->r4 = ADD32(0, 0X1AC);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x8080039C: addiu       $a0, $zero, 0x1AC
    ctx->r4 = ADD32(0, 0X1AC);
    after_0:
    // 0x808003A0: beq         $v0, $zero, L_8080048C
    if (ctx->r2 == 0) {
        // 0x808003A4: lw          $t6, 0x38($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X38);
            goto L_8080048C;
    }
    // 0x808003A4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x808003A8: jal         0x800878B0
    // 0x808003AC: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    _plsu_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808003AC: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_1:
    // 0x808003B0: jal         0x800F54E4
    // 0x808003B4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x808003B4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_2:
    // 0x808003B8: bne         $v0, $s0, L_8080048C
    if (ctx->r2 != ctx->r16) {
        // 0x808003BC: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_8080048C;
    }
    // 0x808003BC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808003C0: beq         $s0, $at, L_8080048C
    if (ctx->r16 == ctx->r1) {
        // 0x808003C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080048C;
    }
    // 0x808003C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003C8: jal         0x800F64A4
    // 0x808003CC: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_800F64A4(rdram, ctx);
        goto after_3;
    // 0x808003CC: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_3:
    // 0x808003D0: beq         $v0, $zero, L_8080048C
    if (ctx->r2 == 0) {
        // 0x808003D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080048C;
    }
    // 0x808003D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003D8: jal         0x800F5A00
    // 0x808003DC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800F5A00(rdram, ctx);
        goto after_4;
    // 0x808003DC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_4:
    // 0x808003E0: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x808003E4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x808003E8: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x808003EC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808003F0: jal         0x800EEB40
    // 0x808003F4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_800EEB40(rdram, ctx);
        goto after_5;
    // 0x808003F4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_5:
    // 0x808003F8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1176, 0X4A0) << 16);
    // 0x808003FC: lwc1        $f4, 0x4A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1176, 0X4A0));
    // 0x80800400: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80800404: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800408: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8080040C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1176, 0X5D8) << 16);
    // 0x80800410: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80800414: bc1fl       L_80800490
    if (!c1cs) {
        // 0x80800418: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800490;
    }
    goto skip_0;
    // 0x80800418: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080041C: jal         0x80089D18
    // 0x80800420: addiu       $a2, $a2, 0x5D8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1176, 0X5D8));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80800420: addiu       $a2, $a2, 0x5D8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1176, 0X5D8));
    after_6:
    // 0x80800424: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800428: jal         0x8008A4B0
    // 0x8080042C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x8080042C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80800430: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800434: jal         0x80102424
    // 0x80800438: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_8;
    // 0x80800438: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_8:
    // 0x8080043C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800440: jal         0x800F82D4
    // 0x80800444: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800F82D4(rdram, ctx);
        goto after_9;
    // 0x80800444: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x80800448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080044C: jal         0x800F7F98
    // 0x80800450: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F7F98(rdram, ctx);
        goto after_10;
    // 0x80800450: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80800454: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80800458: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080045C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80800460: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x80800464: jal         0x80085708
    // 0x80800468: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_11;
    // 0x80800468: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_11:
    // 0x8080046C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800470: jal         0x800F4CEC
    // 0x80800474: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    func_800F4CEC(rdram, ctx);
        goto after_12;
    // 0x80800474: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    after_12:
    // 0x80800478: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080047C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800480: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    // 0x80800484: jal         0x800C9C04
    // 0x80800488: addiu       $a2, $zero, 0x55F0
    ctx->r6 = ADD32(0, 0X55F0);
    func_800C9C04(rdram, ctx);
        goto after_13;
    // 0x80800488: addiu       $a2, $zero, 0x55F0
    ctx->r6 = ADD32(0, 0X55F0);
    after_13:
L_8080048C:
    // 0x8080048C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800490:
    // 0x80800490: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800494: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800498: jr          $ra
    // 0x8080049C: nop

    return;
    // 0x8080049C: nop

;}
RECOMP_FUNC void func_80801888_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801888: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080188C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801890: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80801894: jal         0x8010D600
    // 0x80801898: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_8010D600(rdram, ctx);
        goto after_0;
    // 0x80801898: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8080189C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808018A0: jal         0x80102D78
    // 0x808018A4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_80102D78(rdram, ctx);
        goto after_1;
    // 0x808018A4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x808018A8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808018AC: lui         $a1, 0x3E19
    ctx->r5 = S32(0X3E19 << 16);
    // 0x808018B0: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x808018B4: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x808018B8: lui         $a3, 0x4348
    ctx->r7 = S32(0X4348 << 16);
    // 0x808018BC: jal         0x80102BF8
    // 0x808018C0: swc1        $f0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f0.u32l;
    func_80102BF8(rdram, ctx);
        goto after_2;
    // 0x808018C0: swc1        $f0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f0.u32l;
    after_2:
    // 0x808018C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808018C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808018CC: jr          $ra
    // 0x808018D0: nop

    return;
    // 0x808018D0: nop

;}
RECOMP_FUNC void func_808002A4_chburgerstand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808002A8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808002AC: slti        $at, $a1, 0x53
    ctx->r1 = SIGNED(ctx->r5) < 0X53 ? 1 : 0;
    // 0x808002B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808002B8: bne         $at, $zero, L_808002DC
    if (ctx->r1 != 0) {
        // 0x808002BC: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_808002DC;
    }
    // 0x808002BC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808002C0: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808002C4: beq         $a1, $at, L_80800444
    if (ctx->r5 == ctx->r1) {
        // 0x808002C8: addiu       $at, $zero, 0xB8
        ctx->r1 = ADD32(0, 0XB8);
            goto L_80800444;
    }
    // 0x808002C8: addiu       $at, $zero, 0xB8
    ctx->r1 = ADD32(0, 0XB8);
    // 0x808002CC: beq         $a1, $at, L_80800464
    if (ctx->r5 == ctx->r1) {
        // 0x808002D0: lw          $v0, 0x30($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X30);
            goto L_80800464;
    }
    // 0x808002D0: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x808002D4: b           L_808004C8
    // 0x808002D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808004C8;
    // 0x808002D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808002DC:
    // 0x808002DC: slti        $at, $a1, 0xB
    ctx->r1 = SIGNED(ctx->r5) < 0XB ? 1 : 0;
    // 0x808002E0: bne         $at, $zero, L_80800308
    if (ctx->r1 != 0) {
        // 0x808002E4: addiu       $t6, $a1, -0x29
        ctx->r14 = ADD32(ctx->r5, -0X29);
            goto L_80800308;
    }
    // 0x808002E4: addiu       $t6, $a1, -0x29
    ctx->r14 = ADD32(ctx->r5, -0X29);
    // 0x808002E8: sltiu       $at, $t6, 0x2A
    ctx->r1 = ctx->r14 < 0X2A ? 1 : 0;
    // 0x808002EC: beq         $at, $zero, L_80800314
    if (ctx->r1 == 0) {
        // 0x808002F0: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800314;
    }
    // 0x808002F0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808002F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(936, 0XB10) << 16);
    // 0x808002F8: addu        $at, $at, $t6
    gpr jr_addend_80800300 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808002FC: lw          $t6, 0xB10($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(936, 0XB10));
    // 0x80800300: jr          $t6
    // 0x80800304: nop

    switch (jr_addend_80800300 >> 2) {
        case 0: goto L_80800424; break;
        case 1: goto L_80800434; break;
        case 2: goto L_80800314; break;
        case 3: goto L_80800314; break;
        case 4: goto L_80800314; break;
        case 5: goto L_8080031C; break;
        case 6: goto L_80800338; break;
        case 7: goto L_80800314; break;
        case 8: goto L_80800314; break;
        case 9: goto L_80800354; break;
        case 10: goto L_80800314; break;
        case 11: goto L_80800314; break;
        case 12: goto L_80800314; break;
        case 13: goto L_80800314; break;
        case 14: goto L_80800314; break;
        case 15: goto L_80800314; break;
        case 16: goto L_80800314; break;
        case 17: goto L_80800314; break;
        case 18: goto L_80800314; break;
        case 19: goto L_80800314; break;
        case 20: goto L_80800368; break;
        case 21: goto L_80800314; break;
        case 22: goto L_80800314; break;
        case 23: goto L_80800314; break;
        case 24: goto L_80800314; break;
        case 25: goto L_80800314; break;
        case 26: goto L_80800314; break;
        case 27: goto L_80800314; break;
        case 28: goto L_80800314; break;
        case 29: goto L_80800314; break;
        case 30: goto L_80800314; break;
        case 31: goto L_80800314; break;
        case 32: goto L_80800314; break;
        case 33: goto L_80800314; break;
        case 34: goto L_80800314; break;
        case 35: goto L_80800314; break;
        case 36: goto L_80800314; break;
        case 37: goto L_80800314; break;
        case 38: goto L_80800314; break;
        case 39: goto L_80800314; break;
        case 40: goto L_80800314; break;
        case 41: goto L_80800378; break;
        default: switch_error(__func__, 0x80800300, 0x80800B10);
    }
    // 0x80800304: nop

L_80800308:
    // 0x80800308: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8080030C: beql        $a1, $at, L_80800394
    if (ctx->r5 == ctx->r1) {
        // 0x80800310: lbu         $t8, 0x65($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X65);
            goto L_80800394;
    }
    goto skip_0;
    // 0x80800310: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    skip_0:
L_80800314:
    // 0x80800314: b           L_808004C8
    // 0x80800318: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808004C8;
    // 0x80800318: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080031C:
    // 0x8080031C: addiu       $v0, $sp, 0x30
    ctx->r2 = ADD32(ctx->r29, 0X30);
    // 0x80800320: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80800324: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x80800328: jal         0x808007A0
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808007A0_chburgerstand(rdram, ctx);
        goto after_0;
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800330: b           L_808004C8
    // 0x80800334: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004C8;
    // 0x80800334: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800338:
    // 0x80800338: addiu       $v0, $sp, 0x30
    ctx->r2 = ADD32(ctx->r29, 0X30);
    // 0x8080033C: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80800340: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x80800344: jal         0x8080087C
    // 0x80800348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080087C_chburgerstand(rdram, ctx);
        goto after_1;
    // 0x80800348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080034C: b           L_808004C8
    // 0x80800350: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004C8;
    // 0x80800350: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800354:
    // 0x80800354: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800358: jal         0x80090734
    // 0x8080035C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_80090734(rdram, ctx);
        goto after_2;
    // 0x8080035C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_2:
    // 0x80800360: b           L_808004C8
    // 0x80800364: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004C8;
    // 0x80800364: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800368:
    // 0x80800368: jal         0x80800940
    // 0x8080036C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800940_chburgerstand(rdram, ctx);
        goto after_3;
    // 0x8080036C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800370: b           L_808004C8
    // 0x80800374: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004C8;
    // 0x80800374: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800378:
    // 0x80800378: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(936, 0XD50) << 16);
    // 0x8080037C: addiu       $a0, $a0, 0xD50
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(936, 0XD50));
    // 0x80800380: jal         0x80088090
    // 0x80800384: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80800384: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_4:
    // 0x80800388: b           L_808004C8
    // 0x8080038C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004C8;
    // 0x8080038C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800390: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
L_80800394:
    // 0x80800394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800398: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080039C: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x808003A0: jal         0x80102424
    // 0x808003A4: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
    func_80102424(rdram, ctx);
        goto after_5;
    // 0x808003A4: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
    after_5:
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003AC: jal         0x80101EE4
    // 0x808003B0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80101EE4(rdram, ctx);
        goto after_6;
    // 0x808003B0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
    // 0x808003B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003B8: jal         0x80103110
    // 0x808003BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_7;
    // 0x808003BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x808003C0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x808003C4: beql        $a0, $zero, L_808003F0
    if (ctx->r4 == 0) {
        // 0x808003C8: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_808003F0;
    }
    goto skip_1;
    // 0x808003C8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x808003CC: jal         0x80106790
    // 0x808003D0: nop

    func_80106790(rdram, ctx);
        goto after_8;
    // 0x808003D0: nop

    after_8:
    // 0x808003D4: lhu         $t1, 0x64($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X64);
    // 0x808003D8: lbu         $t3, 0x65($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X65);
    // 0x808003DC: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x808003E0: andi        $t4, $t3, 0xFFFE
    ctx->r12 = ctx->r11 & 0XFFFE;
    // 0x808003E4: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x808003E8: sb          $t5, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r13;
    // 0x808003EC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_808003F0:
    // 0x808003F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808003F4: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x808003F8: jal         0x80085708
    // 0x808003FC: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    _capod_entrypoint_13(rdram, ctx);
        goto after_9;
    // 0x808003FC: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_9:
    // 0x80800400: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800404: addiu       $t6, $zero, 0x50
    ctx->r14 = ADD32(0, 0X50);
    // 0x80800408: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080040C: addiu       $a1, $zero, 0x10DF
    ctx->r5 = ADD32(0, 0X10DF);
    // 0x80800410: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800414: jal         0x8008A208
    // 0x80800418: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_10;
    // 0x80800418: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_10:
    // 0x8080041C: b           L_808004C8
    // 0x80800420: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004C8;
    // 0x80800420: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800424:
    // 0x80800424: jal         0x808006B4
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808006B4_chburgerstand(rdram, ctx);
        goto after_11;
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8080042C: b           L_808004C8
    // 0x80800430: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004C8;
    // 0x80800430: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800434:
    // 0x80800434: jal         0x80800720
    // 0x80800438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800720_chburgerstand(rdram, ctx);
        goto after_12;
    // 0x80800438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8080043C: b           L_808004C8
    // 0x80800440: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004C8;
    // 0x80800440: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800444:
    // 0x80800444: jal         0x800D1A04
    // 0x80800448: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    func_800D1A04(rdram, ctx);
        goto after_13;
    // 0x80800448: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    after_13:
    // 0x8080044C: bne         $v0, $zero, L_808004C4
    if (ctx->r2 != 0) {
        // 0x80800450: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004C4;
    }
    // 0x80800450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800454: jal         0x80108B04
    // 0x80800458: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_14;
    // 0x80800458: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x8080045C: b           L_808004C8
    // 0x80800460: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004C8;
    // 0x80800460: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800464:
    // 0x80800464: andi        $t7, $v0, 0xFFFF
    ctx->r15 = ctx->r2 & 0XFFFF;
    // 0x80800468: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080046C: beq         $t7, $at, L_80800484
    if (ctx->r15 == ctx->r1) {
        // 0x80800470: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800484;
    }
    // 0x80800470: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800474: beql        $t7, $at, L_808004A8
    if (ctx->r15 == ctx->r1) {
        // 0x80800478: lw          $t9, 0x3C($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X3C);
            goto L_808004A8;
    }
    goto skip_2;
    // 0x80800478: lw          $t9, 0x3C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X3C);
    skip_2:
    // 0x8080047C: b           L_808004C8
    // 0x80800480: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808004C8;
    // 0x80800480: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800484:
    // 0x80800484: lw          $t8, 0x3C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X3C);
    // 0x80800488: addiu       $v1, $zero, 0x10AC
    ctx->r3 = ADD32(0, 0X10AC);
    // 0x8080048C: beq         $t8, $zero, L_8080049C
    if (ctx->r24 == 0) {
        // 0x80800490: nop
    
            goto L_8080049C;
    }
    // 0x80800490: nop

    // 0x80800494: b           L_808004C8
    // 0x80800498: addiu       $v0, $zero, 0x10AB
    ctx->r2 = ADD32(0, 0X10AB);
        goto L_808004C8;
    // 0x80800498: addiu       $v0, $zero, 0x10AB
    ctx->r2 = ADD32(0, 0X10AB);
L_8080049C:
    // 0x8080049C: b           L_808004C8
    // 0x808004A0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_808004C8;
    // 0x808004A0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x808004A4: lw          $t9, 0x3C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X3C);
L_808004A8:
    // 0x808004A8: addiu       $v1, $zero, 0x1107
    ctx->r3 = ADD32(0, 0X1107);
    // 0x808004AC: beq         $t9, $zero, L_808004BC
    if (ctx->r25 == 0) {
        // 0x808004B0: nop
    
            goto L_808004BC;
    }
    // 0x808004B0: nop

    // 0x808004B4: b           L_808004C8
    // 0x808004B8: addiu       $v0, $zero, 0x1106
    ctx->r2 = ADD32(0, 0X1106);
        goto L_808004C8;
    // 0x808004B8: addiu       $v0, $zero, 0x1106
    ctx->r2 = ADD32(0, 0X1106);
L_808004BC:
    // 0x808004BC: b           L_808004C8
    // 0x808004C0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_808004C8;
    // 0x808004C0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_808004C4:
    // 0x808004C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004C8:
    // 0x808004C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808004CC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808004D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808004D4: jr          $ra
    // 0x808004D8: nop

    return;
    // 0x808004D8: nop

;}
RECOMP_FUNC void func_80026860(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026860: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80026864: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80026868: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002686C: jal         0x8002FEC0
    // 0x80026870: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80026870: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80026874: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80026878: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8002687C: lw          $t6, 0x11F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11F4);
    // 0x80026880: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80026884: lw          $t7, 0x20($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20);
    // 0x80026888: sw          $t7, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r15;
    // 0x8002688C: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80026890: lw          $t9, 0x11F4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X11F4);
    // 0x80026894: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80026898: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8002689C: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800268A0: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x800268A4: lw          $t3, 0x11F4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X11F4);
    // 0x800268A8: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800268AC: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x800268B0: jal         0x8002FEC0
    // 0x800268B4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x800268B4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800268B8: b           L_800268C0
    // 0x800268BC: nop

        goto L_800268C0;
    // 0x800268BC: nop

L_800268C0:
    // 0x800268C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800268C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800268C8: jr          $ra
    // 0x800268CC: nop

    return;
    // 0x800268CC: nop

;}
RECOMP_FUNC void func_80800554_chboggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800554: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800558: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080055C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800560: jal         0x80088EF0
    // 0x80800564: addiu       $a0, $zero, 0x35C
    ctx->r4 = ADD32(0, 0X35C);
    _idworld_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800564: addiu       $a0, $zero, 0x35C
    ctx->r4 = ADD32(0, 0X35C);
    after_0:
    // 0x80800568: beq         $v0, $zero, L_80800618
    if (ctx->r2 == 0) {
        // 0x8080056C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800618;
    }
    // 0x8080056C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800570: jal         0x80088D88
    // 0x80800574: nop

    _idglowa_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800574: nop

    after_1:
    // 0x80800578: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8080057C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800580: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x80800584: addiu       $a0, $zero, 0xA2E
    ctx->r4 = ADD32(0, 0XA2E);
    // 0x80800588: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8080058C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80800590: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80800594: nop

    // 0x80800598: bne         $v0, $at, L_808005AC
    if (ctx->r2 != ctx->r1) {
        // 0x8080059C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_808005AC;
    }
    // 0x8080059C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808005A0: jal         0x800DA544
    // 0x808005A4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800DA544(rdram, ctx);
        goto after_2;
    // 0x808005A4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_2:
    // 0x808005A8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_808005AC:
    // 0x808005AC: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x808005B0: bnel        $v1, $at, L_8080061C
    if (ctx->r3 != ctx->r1) {
        // 0x808005B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080061C;
    }
    goto skip_0;
    // 0x808005B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808005B8: jal         0x800DA298
    // 0x808005BC: addiu       $a0, $zero, 0xA2E
    ctx->r4 = ADD32(0, 0XA2E);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x808005BC: addiu       $a0, $zero, 0xA2E
    ctx->r4 = ADD32(0, 0XA2E);
    after_3:
    // 0x808005C0: beq         $v0, $zero, L_80800618
    if (ctx->r2 == 0) {
        // 0x808005C4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800618;
    }
    // 0x808005C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808005C8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2072, 0X830) << 16);
    // 0x808005CC: addiu       $a2, $a2, 0x830
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2072, 0X830));
    // 0x808005D0: jal         0x800C4350
    // 0x808005D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C4350(rdram, ctx);
        goto after_4;
    // 0x808005D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808005D8: sb          $v0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r2;
    // 0x808005DC: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x808005E0: jal         0x800C36F4
    // 0x808005E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C36F4(rdram, ctx);
        goto after_5;
    // 0x808005E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808005E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808005EC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808005F0: lui         $a2, 0x3FB3
    ctx->r6 = S32(0X3FB3 << 16);
    // 0x808005F4: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x808005F8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808005FC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800600: jal         0x800C3A40
    // 0x80800604: lbu         $a0, 0x1F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1F);
    func_800C3A40(rdram, ctx);
        goto after_6;
    // 0x80800604: lbu         $a0, 0x1F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1F);
    after_6:
    // 0x80800608: jal         0x800C3BDC
    // 0x8080060C: lbu         $a0, 0x1F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1F);
    func_800C3BDC(rdram, ctx);
        goto after_7;
    // 0x8080060C: lbu         $a0, 0x1F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1F);
    after_7:
    // 0x80800610: jal         0x800DA524
    // 0x80800614: addiu       $a0, $zero, 0xA2E
    ctx->r4 = ADD32(0, 0XA2E);
    func_800DA524(rdram, ctx);
        goto after_8;
    // 0x80800614: addiu       $a0, $zero, 0xA2E
    ctx->r4 = ADD32(0, 0XA2E);
    after_8:
L_80800618:
    // 0x80800618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080061C:
    // 0x8080061C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800620: jr          $ra
    // 0x80800624: nop

    return;
    // 0x80800624: nop

;}
RECOMP_FUNC void func_8080000C_chhotwatersteam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: jal         0x808001E8
    // 0x80800018: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808001E8_chhotwatersteam(rdram, ctx);
        goto after_0;
    // 0x80800018: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080001C: bne         $v0, $zero, L_8080002C
    if (ctx->r2 != 0) {
        // 0x80800020: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_8080002C;
    }
    // 0x80800020: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800024: jal         0x800FFA88
    // 0x80800028: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_1;
    // 0x80800028: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_1:
L_8080002C:
    // 0x8080002C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800034: jr          $ra
    // 0x80800038: nop

    return;
    // 0x80800038: nop

;}
RECOMP_FUNC void mlwave_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080011C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800120: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800124: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800128: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8080012C: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x80800130: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80800134: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80800138: sub.s       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f6.fl;
    // 0x8080013C: mul.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80800140: jal         0x8001395C
    // 0x80800144: nop

    func_8001395C(rdram, ctx);
        goto after_0;
    // 0x80800144: nop

    after_0:
    // 0x80800148: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8080014C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80800150: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800154: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800158: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080015C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80800160: jal         0x800F10B4
    // 0x80800164: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x80800164: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x80800168: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080016C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800170: jr          $ra
    // 0x80800174: nop

    return;
    // 0x80800174: nop

;}
RECOMP_FUNC void func_800DBFD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DBFD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DBFDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DBFE0: jal         0x8001B084
    // 0x800DBFE4: nop

    heap_free(rdram, ctx);
        goto after_0;
    // 0x800DBFE4: nop

    after_0:
    // 0x800DBFE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DBFEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DBFF0: jr          $ra
    // 0x800DBFF4: nop

    return;
    // 0x800DBFF4: nop

;}
RECOMP_FUNC void _chboilerid_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800860A0: syscall     276
    recomp_syscall_handler(rdram, ctx, 0x800860A0);
    return;
    // 0x800860A4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800DF758(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF758: addiu       $a2, $a0, 0x4
    ctx->r6 = ADD32(ctx->r4, 0X4);
    // 0x800DF75C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800DF760: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DF764: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800DF768: sw          $t6, -0x37AC($at)
    MEM_W(-0X37AC, ctx->r1) = ctx->r14;
    // 0x800DF76C: lw          $t7, 0x4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4);
    // 0x800DF770: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DF774: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800DF778: sw          $t7, -0x37A8($at)
    MEM_W(-0X37A8, ctx->r1) = ctx->r15;
    // 0x800DF77C: lw          $t8, 0x8($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X8);
    // 0x800DF780: addiu       $v0, $v0, -0x36C0
    ctx->r2 = ADD32(ctx->r2, -0X36C0);
    // 0x800DF784: addiu       $v1, $v1, -0x37A0
    ctx->r3 = ADD32(ctx->r3, -0X37A0);
    // 0x800DF788: addiu       $a1, $a0, 0x10
    ctx->r5 = ADD32(ctx->r4, 0X10);
    // 0x800DF78C: sw          $t8, -0x37A4($at)
    MEM_W(-0X37A4, ctx->r1) = ctx->r24;
L_800DF790:
    // 0x800DF790: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800DF794: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800DF798: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800DF79C: sw          $t9, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->r25;
    // 0x800DF7A0: lw          $t0, -0xC($a1)
    ctx->r8 = MEM_W(ctx->r5, -0XC);
    // 0x800DF7A4: sw          $t0, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->r8;
    // 0x800DF7A8: lw          $t1, -0x8($a1)
    ctx->r9 = MEM_W(ctx->r5, -0X8);
    // 0x800DF7AC: sw          $t1, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->r9;
    // 0x800DF7B0: lw          $t2, -0x4($a1)
    ctx->r10 = MEM_W(ctx->r5, -0X4);
    // 0x800DF7B4: bne         $v1, $v0, L_800DF790
    if (ctx->r3 != ctx->r2) {
        // 0x800DF7B8: sw          $t2, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->r10;
            goto L_800DF790;
    }
    // 0x800DF7B8: sw          $t2, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r10;
    // 0x800DF7BC: jr          $ra
    // 0x800DF7C0: nop

    return;
    // 0x800DF7C0: nop

;}
RECOMP_FUNC void _babackpack_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084510: syscall     113
    recomp_syscall_handler(rdram, ctx, 0x80084510);
    return;
    // 0x80084514: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_808002FC_chlakemonster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002FC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800300: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800304: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800308: jal         0x800B53A4
    // 0x8080030C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_800B53A4(rdram, ctx);
        goto after_0;
    // 0x8080030C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_0:
    // 0x80800310: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800314: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800318: jal         0x80100094
    // 0x8080031C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x8080031C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800320: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800324: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1748, 0X212C) << 16);
    // 0x80800328: addiu       $t6, $t6, 0x212C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1748, 0X212C));
    // 0x8080032C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800330: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800334: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800338: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8080033C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800340: jal         0x800BABB8
    // 0x80800344: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x80800344: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    after_2:
    // 0x80800348: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8080034C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800350: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800354: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80800358: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8080035C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800360: lwc1        $f12, 0x38($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X38);
    // 0x80800364: lwc1        $f0, 0x20($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X20);
    // 0x80800368: lwc1        $f2, 0x1C($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x8080036C: mul.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x80800370: sub.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x80800374: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800378: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8080037C: sub.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x80800380: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800384: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80800388: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080038C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800390: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800394: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80800398: mul.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x8080039C: add.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x808003A0: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x808003A4: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x808003A8: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    // 0x808003AC: add.s       $f10, $f2, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x808003B0: sll         $t5, $a3, 16
    ctx->r13 = S32(ctx->r7 << 16);
    // 0x808003B4: sll         $t1, $a2, 16
    ctx->r9 = S32(ctx->r6 << 16);
    // 0x808003B8: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x808003BC: sra         $a2, $t1, 16
    ctx->r6 = S32(SIGNED(ctx->r9) >> 16);
    // 0x808003C0: sra         $a3, $t5, 16
    ctx->r7 = S32(SIGNED(ctx->r13) >> 16);
    // 0x808003C4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808003C8: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x808003CC: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x808003D0: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x808003D4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808003D8: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x808003DC: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x808003E0: jal         0x800BA994
    // 0x808003E4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    func_800BA994(rdram, ctx);
        goto after_3;
    // 0x808003E4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_3:
    // 0x808003E8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808003EC: jal         0x800BA22C
    // 0x808003F0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_800BA22C(rdram, ctx);
        goto after_4;
    // 0x808003F0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_4:
    // 0x808003F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808003F8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808003FC: jr          $ra
    // 0x80800400: nop

    return;
    // 0x80800400: nop

;}
RECOMP_FUNC void func_800E3B50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E3B50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E3B54: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800E3B58: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800E3B5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800E3B60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E3B64: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x800E3B68: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E3B6C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800E3B70: jal         0x800CAA00
    // 0x800E3B74: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    func_800CAA00(rdram, ctx);
        goto after_0;
    // 0x800E3B74: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    after_0:
    // 0x800E3B78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E3B7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E3B80: jr          $ra
    // 0x800E3B84: nop

    return;
    // 0x800E3B84: nop

;}
