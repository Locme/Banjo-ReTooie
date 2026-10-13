#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800E97C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E97C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E97C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E97C8: jal         0x800EA09C
    // 0x800E97CC: nop

    func_800EA09C(rdram, ctx);
        goto after_0;
    // 0x800E97CC: nop

    after_0:
    // 0x800E97D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E97D4: beql        $v0, $at, L_800E97F8
    if (ctx->r2 == ctx->r1) {
        // 0x800E97D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800E97F8;
    }
    goto skip_0;
    // 0x800E97D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800E97DC: jal         0x800EA45C
    // 0x800E97E0: nop

    func_800EA45C(rdram, ctx);
        goto after_1;
    // 0x800E97E0: nop

    after_1:
    // 0x800E97E4: jal         0x800A5CFC
    // 0x800E97E8: nop

    func_800A5CFC(rdram, ctx);
        goto after_2;
    // 0x800E97E8: nop

    after_2:
    // 0x800E97EC: jal         0x800EA51C
    // 0x800E97F0: nop

    func_800EA51C(rdram, ctx);
        goto after_3;
    // 0x800E97F0: nop

    after_3:
    // 0x800E97F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E97F8:
    // 0x800E97F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E97FC: jr          $ra
    // 0x800E9800: nop

    return;
    // 0x800E9800: nop

;}
RECOMP_FUNC void func_808004CC_chminelight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004CC: jr          $ra
    // 0x808004D0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x808004D0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80800000_chmole_cuckoo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1848, 0XC0) << 16);
    // 0x8080000C: jal         0x800899E8
    // 0x80800010: addiu       $a3, $a3, 0xC0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1848, 0XC0));
    _sumole_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800010: addiu       $a3, $a3, 0xC0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1848, 0XC0));
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
RECOMP_FUNC void _fxrain_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800888E8: syscall     710
    recomp_syscall_handler(rdram, ctx, 0x800888E8);
    return;
    // 0x800888EC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80801294_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801294: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801298: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080129C: jal         0x800845D0
    // 0x808012A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _babounce_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808012A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808012A4: jal         0x808000F0
    // 0x808012A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808000F0_bswasher(rdram, ctx);
        goto after_1;
    // 0x808012A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808012AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808012B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808012B4: jr          $ra
    // 0x808012B8: nop

    return;
    // 0x808012B8: nop

;}
RECOMP_FUNC void func_80802670_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802670: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802674: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802678: jal         0x800A3280
    // 0x8080267C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800A3280(rdram, ctx);
        goto after_0;
    // 0x8080267C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80802680: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80802684: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80802688: lui         $t8, 0x8081
    ctx->r24 = S32(RELOC_HI16(439, 0XB258) << 16);
    // 0x8080268C: addiu       $t8, $t8, -0x4DA8
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(439, 0XB258));
    // 0x80802690: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80802694: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80802698: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8080269C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808026A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808026A4: jr          $ra
    // 0x808026A8: nop

    return;
    // 0x808026A8: nop

;}
RECOMP_FUNC void _bstwirl_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084118: syscall     104
    recomp_syscall_handler(rdram, ctx, 0x80084118);
    return;
    // 0x8008411C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chdrips_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086E50: syscall     461
    recomp_syscall_handler(rdram, ctx, 0x80086E50);
    return;
    // 0x80086E54: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800588_bsbansnooze(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800588: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080058C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800590: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800594: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800598: jal         0x8008CABC
    // 0x8080059C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x8080059C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    after_0:
    // 0x808005A0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808005A4: jal         0x8008B2B4
    // 0x808005A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_getAnimTimer(rdram, ctx);
        goto after_1;
    // 0x808005A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808005AC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(49, 0XA60) << 16);
    // 0x808005B0: addiu       $a1, $a1, 0xA60
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(49, 0XA60));
    // 0x808005B4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808005B8: jal         0x800F3780
    // 0x808005BC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800F3780(rdram, ctx);
        goto after_2;
    // 0x808005BC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_2:
    // 0x808005C0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808005C4: jal         0x80800128
    // 0x808005C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800128_bsbansnooze(rdram, ctx);
        goto after_3;
    // 0x808005C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808005CC: jal         0x8009EF10
    // 0x808005D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_4;
    // 0x808005D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808005D4: bne         $v0, $zero, L_808005F0
    if (ctx->r2 != 0) {
        // 0x808005D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005F0;
    }
    // 0x808005D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005DC: jal         0x8009BCD4
    // 0x808005E0: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    func_8009BCD4(rdram, ctx);
        goto after_5;
    // 0x808005E0: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_5:
    // 0x808005E4: beql        $v0, $zero, L_808005F4
    if (ctx->r2 == 0) {
        // 0x808005E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005F4;
    }
    goto skip_0;
    // 0x808005E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808005EC: addiu       $s1, $zero, 0x16F
    ctx->r17 = ADD32(0, 0X16F);
L_808005F0:
    // 0x808005F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808005F4:
    // 0x808005F4: jal         0x80091A30
    // 0x808005F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_released(rdram, ctx);
        goto after_6;
    // 0x808005F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808005FC: beq         $v0, $zero, L_80800608
    if (ctx->r2 == 0) {
        // 0x80800600: nop
    
            goto L_80800608;
    }
    // 0x80800600: nop

    // 0x80800604: addiu       $s1, $zero, 0x172
    ctx->r17 = ADD32(0, 0X172);
L_80800608:
    // 0x80800608: jal         0x8008E35C
    // 0x8080060C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_7;
    // 0x8080060C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800610: beq         $v0, $zero, L_8080061C
    if (ctx->r2 == 0) {
        // 0x80800614: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080061C;
    }
    // 0x80800614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800618: addiu       $s1, $zero, 0x4C
    ctx->r17 = ADD32(0, 0X4C);
L_8080061C:
    // 0x8080061C: jal         0x8009E5C8
    // 0x80800620: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    bs_setState(rdram, ctx);
        goto after_8;
    // 0x80800620: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_8:
    // 0x80800624: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800628: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080062C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800630: jr          $ra
    // 0x80800634: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800634: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800F5B64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5B64: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5B68: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800F5B6C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5B70: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5B74: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F5B78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5B7C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800F5B80: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x800F5B84: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x800F5B88: jal         0x80095870
    // 0x800F5B8C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_80095870(rdram, ctx);
        goto after_0;
    // 0x800F5B8C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F5B90: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F5B94: jal         0x8009C128
    // 0x800F5B98: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8009C128(rdram, ctx);
        goto after_1;
    // 0x800F5B98: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x800F5B9C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x800F5BA0: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F5BA4: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800F5BA8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800F5BAC: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x800F5BB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5BB4: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800F5BB8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800F5BBC: jr          $ra
    // 0x800F5BC0: nop

    return;
    // 0x800F5BC0: nop

;}
RECOMP_FUNC void func_80801890_bsvan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801890: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801894: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801898: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080189C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808018A0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x808018A4: jal         0x8009D3A8
    // 0x808018A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_0;
    // 0x808018A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808018AC: lw          $t6, 0x15C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X15C);
    // 0x808018B0: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x808018B4: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x808018B8: beq         $at, $zero, L_80801A30
    if (ctx->r1 == 0) {
        // 0x808018BC: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80801A30;
    }
    // 0x808018BC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808018C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(427, 0X1B70) << 16);
    // 0x808018C4: addu        $at, $at, $t7
    gpr jr_addend_808018CC = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808018C8: lw          $t7, 0x1B70($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(427, 0X1B70));
    // 0x808018CC: jr          $t7
    // 0x808018D0: nop

    switch (jr_addend_808018CC >> 2) {
        case 0: goto L_808018D4; break;
        case 1: goto L_80801910; break;
        case 2: goto L_80801960; break;
        case 3: goto L_808019C8; break;
        case 4: goto L_808019E8; break;
        default: switch_error(__func__, 0x808018CC, 0x80801B70);
    }
    // 0x808018D0: nop

L_808018D4:
    // 0x808018D4: jal         0x8009C984
    // 0x808018D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_1;
    // 0x808018D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808018DC: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x808018E0: jal         0x8009C990
    // 0x808018E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_2;
    // 0x808018E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808018E8: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x808018EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808018F0: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x808018F4: nop

    // 0x808018F8: bc1f        L_80801A30
    if (!c1cs) {
        // 0x808018FC: nop
    
            goto L_80801A30;
    }
    // 0x808018FC: nop

    // 0x80801900: jal         0x8080164C
    // 0x80801904: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8080164C_bsvan(rdram, ctx);
        goto after_3;
    // 0x80801904: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80801908: b           L_80801A30
    // 0x8080190C: nop

        goto L_80801A30;
    // 0x8080190C: nop

L_80801910:
    // 0x80801910: lui         $a1, 0x3DA3
    ctx->r5 = S32(0X3DA3 << 16);
    // 0x80801914: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80801918: jal         0x8008CB10
    // 0x8080191C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_4;
    // 0x8080191C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801920: beq         $v0, $zero, L_80801938
    if (ctx->r2 == 0) {
        // 0x80801924: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801938;
    }
    // 0x80801924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801928: addiu       $a1, $zero, 0x56D
    ctx->r5 = ADD32(0, 0X56D);
    // 0x8080192C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801930: jal         0x8009DF18
    // 0x80801934: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    func_8009DF18(rdram, ctx);
        goto after_5;
    // 0x80801934: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    after_5:
L_80801938:
    // 0x80801938: lui         $a1, 0x3F01
    ctx->r5 = S32(0X3F01 << 16);
    // 0x8080193C: ori         $a1, $a1, 0x4120
    ctx->r5 = ctx->r5 | 0X4120;
    // 0x80801940: jal         0x8008CB10
    // 0x80801944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_6;
    // 0x80801944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80801948: beq         $v0, $zero, L_80801A30
    if (ctx->r2 == 0) {
        // 0x8080194C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801A30;
    }
    // 0x8080194C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801950: jal         0x8080164C
    // 0x80801954: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8080164C_bsvan(rdram, ctx);
        goto after_7;
    // 0x80801954: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
    // 0x80801958: b           L_80801A30
    // 0x8080195C: nop

        goto L_80801A30;
    // 0x8080195C: nop

L_80801960:
    // 0x80801960: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801964: jal         0x800852F0
    // 0x80801968: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _batimer_decrement(rdram, ctx);
        goto after_8;
    // 0x80801968: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_8:
    // 0x8080196C: beq         $v0, $zero, L_80801A30
    if (ctx->r2 == 0) {
        // 0x80801970: lui         $a0, 0x8008
        ctx->r4 = S32(0X8008 << 16);
            goto L_80801A30;
    }
    // 0x80801970: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80801974: addiu       $a0, $a0, 0x4198
    ctx->r4 = ADD32(ctx->r4, 0X4198);
    // 0x80801978: jal         0x80086D30
    // 0x8080197C: lw          $a1, 0x184($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X184);
    _chbaddiesetup_entrypoint_1(rdram, ctx);
        goto after_9;
    // 0x8080197C: lw          $a1, 0x184($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X184);
    after_9:
    // 0x80801980: lw          $v0, 0x188($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X188);
    // 0x80801984: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80801988: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080198C: lw          $t8, 0x10($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X10);
    // 0x80801990: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80801994: sw          $t9, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r25;
    // 0x80801998: lw          $t0, 0x188($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X188);
    // 0x8080199C: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x808019A0: beq         $t1, $zero, L_808019B8
    if (ctx->r9 == 0) {
        // 0x808019A4: nop
    
            goto L_808019B8;
    }
    // 0x808019A4: nop

    // 0x808019A8: jal         0x8080164C
    // 0x808019AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080164C_bsvan(rdram, ctx);
        goto after_10;
    // 0x808019AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808019B0: b           L_80801A30
    // 0x808019B4: nop

        goto L_80801A30;
    // 0x808019B4: nop

L_808019B8:
    // 0x808019B8: jal         0x8080164C
    // 0x808019BC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8080164C_bsvan(rdram, ctx);
        goto after_11;
    // 0x808019BC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_11:
    // 0x808019C0: b           L_80801A30
    // 0x808019C4: nop

        goto L_80801A30;
    // 0x808019C4: nop

L_808019C8:
    // 0x808019C8: jal         0x8008CAEC
    // 0x808019CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_12;
    // 0x808019CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808019D0: beq         $v0, $zero, L_80801A30
    if (ctx->r2 == 0) {
        // 0x808019D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801A30;
    }
    // 0x808019D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808019D8: jal         0x8080164C
    // 0x808019DC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_8080164C_bsvan(rdram, ctx);
        goto after_13;
    // 0x808019DC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_13:
    // 0x808019E0: b           L_80801A30
    // 0x808019E4: nop

        goto L_80801A30;
    // 0x808019E4: nop

L_808019E8:
    // 0x808019E8: jal         0x8009C984
    // 0x808019EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_14;
    // 0x808019EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808019F0: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x808019F4: jal         0x8009C990
    // 0x808019F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_15;
    // 0x808019F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808019FC: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80801A00: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x80801A04: nop

    // 0x80801A08: bc1f        L_80801A30
    if (!c1cs) {
        // 0x80801A0C: nop
    
            goto L_80801A30;
    }
    // 0x80801A0C: nop

    // 0x80801A10: jal         0x8008E124
    // 0x80801A14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E124(rdram, ctx);
        goto after_16;
    // 0x80801A14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80801A18: beq         $v0, $zero, L_80801A2C
    if (ctx->r2 == 0) {
        // 0x80801A1C: addiu       $t3, $zero, 0x11A
        ctx->r11 = ADD32(0, 0X11A);
            goto L_80801A2C;
    }
    // 0x80801A1C: addiu       $t3, $zero, 0x11A
    ctx->r11 = ADD32(0, 0X11A);
    // 0x80801A20: addiu       $t2, $zero, 0x119
    ctx->r10 = ADD32(0, 0X119);
    // 0x80801A24: b           L_80801A30
    // 0x80801A28: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
        goto L_80801A30;
    // 0x80801A28: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
L_80801A2C:
    // 0x80801A2C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
L_80801A30:
    // 0x80801A30: jal         0x808003BC
    // 0x80801A34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bsvan_entrypoint_3(rdram, ctx);
        goto after_17;
    // 0x80801A34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80801A38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A3C: jal         0x8009E5C8
    // 0x80801A40: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_18;
    // 0x80801A40: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_18:
    // 0x80801A44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801A48: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801A4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801A50: jr          $ra
    // 0x80801A54: nop

    return;
    // 0x80801A54: nop

;}
RECOMP_FUNC void func_80800910_chmrsboggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800910: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800914: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800918: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080091C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800920: lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28);
    // 0x80800924: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800928: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8080092C: beq         $v0, $zero, L_80800958
    if (ctx->r2 == 0) {
        // 0x80800930: addiu       $a1, $zero, 0x12
        ctx->r5 = ADD32(0, 0X12);
            goto L_80800958;
    }
    // 0x80800930: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x80800934: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800938: beq         $v0, $at, L_80800968
    if (ctx->r2 == ctx->r1) {
        // 0x8080093C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800968;
    }
    // 0x8080093C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800940: beq         $v0, $at, L_80800968
    if (ctx->r2 == ctx->r1) {
        // 0x80800944: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800968;
    }
    // 0x80800944: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800948: beql        $v0, $at, L_80800974
    if (ctx->r2 == ctx->r1) {
        // 0x8080094C: lw          $a0, 0x0($a3)
        ctx->r4 = MEM_W(ctx->r7, 0X0);
            goto L_80800974;
    }
    goto skip_0;
    // 0x8080094C: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    skip_0:
    // 0x80800950: b           L_80800984
    // 0x80800954: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800984;
    // 0x80800954: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800958:
    // 0x80800958: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x8080095C: jal         0x800856B0
    // 0x80800960: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800960: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800964: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_80800968:
    // 0x80800968: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080096C: sw          $t6, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->r14;
    // 0x80800970: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
L_80800974:
    // 0x80800974: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800978: jal         0x80085740
    // 0x8080097C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _capod_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x8080097C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800980: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800984:
    // 0x80800984: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800988: jr          $ra
    // 0x8080098C: nop

    return;
    // 0x8080098C: nop

;}
RECOMP_FUNC void func_80800088_chtntblockage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800088: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080008C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800090: jal         0x80089D00
    // 0x80800094: nop

    _subaddiefade_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80800094: nop

    after_0:
    // 0x80800098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080009C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000A0: jr          $ra
    // 0x808000A4: nop

    return;
    // 0x808000A4: nop

;}
RECOMP_FUNC void gczoombox_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803534: beq         $a0, $zero, L_80803560
    if (ctx->r4 == 0) {
        // 0x80803538: nop
    
            goto L_80803560;
    }
    // 0x80803538: nop

    // 0x8080353C: beql        $a1, $zero, L_80803558
    if (ctx->r5 == 0) {
        // 0x80803540: lbu         $t9, 0x1E6($a0)
        ctx->r25 = MEM_BU(ctx->r4, 0X1E6);
            goto L_80803558;
    }
    goto skip_0;
    // 0x80803540: lbu         $t9, 0x1E6($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1E6);
    skip_0:
    // 0x80803544: lbu         $t7, 0x1E6($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1E6);
    // 0x80803548: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x8080354C: jr          $ra
    // 0x80803550: sb          $t8, 0x1E6($a0)
    MEM_B(0X1E6, ctx->r4) = ctx->r24;
    return;
    // 0x80803550: sb          $t8, 0x1E6($a0)
    MEM_B(0X1E6, ctx->r4) = ctx->r24;
    // 0x80803554: lbu         $t9, 0x1E6($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1E6);
L_80803558:
    // 0x80803558: andi        $t0, $t9, 0xFFF7
    ctx->r8 = ctx->r25 & 0XFFF7;
    // 0x8080355C: sb          $t0, 0x1E6($a0)
    MEM_B(0X1E6, ctx->r4) = ctx->r8;
L_80803560:
    // 0x80803560: jr          $ra
    // 0x80803564: nop

    return;
    // 0x80803564: nop

;}
RECOMP_FUNC void suspline_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D38: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800D3C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800D40: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800D44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800D48: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800D4C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800D50: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80800D54: jal         0x800EFD24
    // 0x80800D58: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x80800D58: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    after_0:
    // 0x80800D5C: addiu       $a1, $s0, 0x48
    ctx->r5 = ADD32(ctx->r16, 0X48);
    // 0x80800D60: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800D64: jal         0x800EFD24
    // 0x80800D68: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_800EFD24(rdram, ctx);
        goto after_1;
    // 0x80800D68: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_1:
    // 0x80800D6C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800D70: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800D74: sb          $zero, 0x7E($s0)
    MEM_B(0X7E, ctx->r16) = 0;
    // 0x80800D78: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80800D7C: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
    // 0x80800D80: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x80800D84: swc1        $f0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f0.u32l;
    // 0x80800D88: swc1        $f0, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f0.u32l;
L_80800D8C:
    // 0x80800D8C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800D90: sb          $zero, 0x7F($v0)
    MEM_B(0X7F, ctx->r2) = 0;
    // 0x80800D94: sb          $zero, 0x80($v0)
    MEM_B(0X80, ctx->r2) = 0;
    // 0x80800D98: sb          $zero, 0x81($v0)
    MEM_B(0X81, ctx->r2) = 0;
    // 0x80800D9C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800DA0: bne         $v1, $a0, L_80800D8C
    if (ctx->r3 != ctx->r4) {
        // 0x80800DA4: sb          $zero, 0x7A($v0)
        MEM_B(0X7A, ctx->r2) = 0;
            goto L_80800D8C;
    }
    // 0x80800DA4: sb          $zero, 0x7A($v0)
    MEM_B(0X7A, ctx->r2) = 0;
    // 0x80800DA8: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80800DAC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800DB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800DB4: sh          $t6, 0x7A($s0)
    MEM_H(0X7A, ctx->r16) = ctx->r14;
    // 0x80800DB8: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80800DBC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800DC0: sh          $t7, 0x7C($s0)
    MEM_H(0X7C, ctx->r16) = ctx->r15;
    // 0x80800DC4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80800DC8: sh          $t8, 0x78($s0)
    MEM_H(0X78, ctx->r16) = ctx->r24;
    // 0x80800DCC: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80800DD0: sb          $t9, 0x88($s0)
    MEM_B(0X88, ctx->r16) = ctx->r25;
    // 0x80800DD4: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80800DD8: sb          $zero, 0x87($s0)
    MEM_B(0X87, ctx->r16) = 0;
    // 0x80800DDC: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
    // 0x80800DE0: jal         0x800EFD24
    // 0x80800DE4: sb          $t0, 0x89($s0)
    MEM_B(0X89, ctx->r16) = ctx->r8;
    func_800EFD24(rdram, ctx);
        goto after_2;
    // 0x80800DE4: sb          $t0, 0x89($s0)
    MEM_B(0X89, ctx->r16) = ctx->r8;
    after_2:
    // 0x80800DE8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800DEC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3202, 0XEBC) << 16);
    // 0x80800DF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DF4: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x80800DF8: lwc1        $f6, 0xEBC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3202, 0XEBC));
    // 0x80800DFC: sb          $zero, 0x8B($s0)
    MEM_B(0X8B, ctx->r16) = 0;
    // 0x80800E00: sb          $zero, 0x8A($s0)
    MEM_B(0X8A, ctx->r16) = 0;
    // 0x80800E04: jal         0x80800C8C
    // 0x80800E08: swc1        $f6, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f6.u32l;
    func_80800C8C_suspline(rdram, ctx);
        goto after_3;
    // 0x80800E08: swc1        $f6, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f6.u32l;
    after_3:
    // 0x80800E0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800E14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800E18: jr          $ra
    // 0x80800E1C: nop

    return;
    // 0x80800E1C: nop

;}
RECOMP_FUNC void func_8009EA08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EA08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009EA0C: jr          $ra
    // 0x8009EA10: swc1        $f12, 0x7070($at)
    MEM_W(0X7070, ctx->r1) = ctx->f12.u32l;
    return;
    // 0x8009EA10: swc1        $f12, 0x7070($at)
    MEM_W(0X7070, ctx->r1) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_80800078_chhotwaterpoolbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800078: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080007C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800080: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800084: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800088: bne         $a1, $at, L_808000FC
    if (ctx->r5 != ctx->r1) {
        // 0x8080008C: sw          $ra, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r31;
            goto L_808000FC;
    }
    // 0x8080008C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800090: addiu       $a0, $zero, 0x31B
    ctx->r4 = ADD32(0, 0X31B);
    // 0x80800094: jal         0x800DA298
    // 0x80800098: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800098: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080009C: bne         $v0, $zero, L_808000C4
    if (ctx->r2 != 0) {
        // 0x808000A0: lw          $a1, 0x2C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X2C);
            goto L_808000C4;
    }
    // 0x808000A0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808000A4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808000A8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808000AC: addiu       $a1, $zero, 0x12B0
    ctx->r5 = ADD32(0, 0X12B0);
    // 0x808000B0: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x808000B4: jal         0x8008A208
    // 0x808000B8: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x808000B8: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x808000BC: b           L_80800110
    // 0x808000C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800110;
    // 0x808000C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000C4:
    // 0x808000C4: addiu       $a0, $zero, 0x428
    ctx->r4 = ADD32(0, 0X428);
    // 0x808000C8: jal         0x80101180
    // 0x808000CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_2;
    // 0x808000CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x808000D0: addiu       $a0, $zero, 0x439
    ctx->r4 = ADD32(0, 0X439);
    // 0x808000D4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x808000D8: jal         0x80101180
    // 0x808000DC: addiu       $a2, $zero, 0x427
    ctx->r6 = ADD32(0, 0X427);
    func_80101180(rdram, ctx);
        goto after_3;
    // 0x808000DC: addiu       $a2, $zero, 0x427
    ctx->r6 = ADD32(0, 0X427);
    after_3:
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E4: jal         0x80103110
    // 0x808000E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_4;
    // 0x808000E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808000EC: jal         0x80085818
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chswitch_entrypoint_9(rdram, ctx);
        goto after_5;
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808000F4: b           L_80800110
    // 0x808000F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800110;
    // 0x808000F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000FC:
    // 0x808000FC: jal         0x80085820
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chswitch_entrypoint_10(rdram, ctx);
        goto after_6;
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800104: b           L_80800114
    // 0x80800108: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800114;
    // 0x80800108: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080010C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800110:
    // 0x80800110: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800114:
    // 0x80800114: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800118: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080011C: jr          $ra
    // 0x80800120: nop

    return;
    // 0x80800120: nop

;}
RECOMP_FUNC void func_800C9150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9150: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C9154: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9158: jal         0x800C91C8
    // 0x800C915C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800C91C8(rdram, ctx);
        goto after_0;
    // 0x800C915C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x800C9160: bne         $v0, $zero, L_800C91B4
    if (ctx->r2 != 0) {
        // 0x800C9164: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800C91B4;
    }
    // 0x800C9164: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800C9168: jal         0x8001ACCC
    // 0x800C916C: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    heap_alloc(rdram, ctx);
        goto after_1;
    // 0x800C916C: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    after_1:
    // 0x800C9170: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C9174: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    // 0x800C9178: jal         0x8002D6E0
    // 0x800C917C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    _bzero(rdram, ctx);
        goto after_2;
    // 0x800C917C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x800C9180: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C9184: addiu       $v0, $v0, -0x54C0
    ctx->r2 = ADD32(ctx->r2, -0X54C0);
    // 0x800C9188: lbu         $t6, 0x14($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X14);
    // 0x800C918C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9190: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800C9194: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800C9198: sw          $a0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r4;
    // 0x800C919C: lbu         $t9, 0x14($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X14);
    // 0x800C91A0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800C91A4: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800C91A8: jal         0x800881E8
    // 0x800C91AC: sb          $t0, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r8;
    _gctransitionDll_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x800C91AC: sb          $t0, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r8;
    after_3:
    // 0x800C91B0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
L_800C91B4:
    // 0x800C91B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C91B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C91BC: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x800C91C0: jr          $ra
    // 0x800C91C4: nop

    return;
    // 0x800C91C4: nop

;}
RECOMP_FUNC void gccollectDll_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800184: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800188: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080018C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800190: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800194: jal         0x80800000
    // 0x80800198: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_80800000_gccollectDll(rdram, ctx);
        goto after_0;
    // 0x80800198: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8080019C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808001A0: jal         0x800CF870
    // 0x808001A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800CF870(rdram, ctx);
        goto after_1;
    // 0x808001A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808001A8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808001AC: beql        $s1, $at, L_80800230
    if (ctx->r17 == ctx->r1) {
        // 0x808001B0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800230;
    }
    goto skip_0;
    // 0x808001B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808001B4: jal         0x800CFA90
    // 0x808001B8: nop

    func_800CFA90(rdram, ctx);
        goto after_2;
    // 0x808001B8: nop

    after_2:
    // 0x808001BC: addiu       $s2, $s1, 0xA
    ctx->r18 = ADD32(ctx->r17, 0XA);
    // 0x808001C0: slt         $at, $s1, $s2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x808001C4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808001C8: beq         $at, $zero, L_80800214
    if (ctx->r1 == 0) {
        // 0x808001CC: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80800214;
    }
    // 0x808001CC: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x808001D0: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2626, 0XC0C) << 16);
    // 0x808001D4: addiu       $s1, $s1, 0xC0C
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2626, 0XC0C));
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808001DC:
    // 0x808001DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808001E0: jal         0x800D0778
    // 0x808001E4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800D0778(rdram, ctx);
        goto after_3;
    // 0x808001E4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_3:
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808001F0: jal         0x800D05E4
    // 0x808001F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D05E4(rdram, ctx);
        goto after_4;
    // 0x808001F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800200: jal         0x800D0594
    // 0x80800204: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D0594(rdram, ctx);
        goto after_5;
    // 0x80800204: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x80800208: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8080020C: bnel        $s0, $s2, L_808001DC
    if (ctx->r16 != ctx->r18) {
        // 0x80800210: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001DC;
    }
    goto skip_1;
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
L_80800214:
    // 0x80800214: jal         0x800DB9B0
    // 0x80800218: nop

    func_800DB9B0(rdram, ctx);
        goto after_6;
    // 0x80800218: nop

    after_6:
    // 0x8080021C: bnel        $v0, $zero, L_80800230
    if (ctx->r2 != 0) {
        // 0x80800220: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800230;
    }
    goto skip_2;
    // 0x80800220: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80800224: jal         0x80088450
    // 0x80800228: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    _gcgamefix_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x80800228: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_7:
    // 0x8080022C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800230:
    // 0x80800230: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800234: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800238: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8080023C: jr          $ra
    // 0x80800240: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800240: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8010114C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010114C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80101150: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80101154: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80101158: jal         0x80106790
    // 0x8010115C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x8010115C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80101160: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80101164: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80101168: jal         0x8010108C
    // 0x8010116C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    func_8010108C(rdram, ctx);
        goto after_1;
    // 0x8010116C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80101170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80101174: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80101178: jr          $ra
    // 0x8010117C: nop

    return;
    // 0x8010117C: nop

;}
RECOMP_FUNC void _ncba1p_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800893F8: syscall     777
    recomp_syscall_handler(rdram, ctx, 0x800893F8);
    return;
    // 0x800893FC: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_80801CB4_chinflatableboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801CB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801CB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801CBC: jal         0x80100094
    // 0x80801CC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801CC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801CC4: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x80801CC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801CCC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801CD0: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x80801CD4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_80801CD8:
    // 0x80801CD8: lbu         $t6, 0x487($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X487);
    // 0x80801CDC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80801CE0: bnel        $a1, $t6, L_80801CF0
    if (ctx->r5 != ctx->r14) {
        // 0x80801CE4: lbu         $t7, 0x488($a0)
        ctx->r15 = MEM_BU(ctx->r4, 0X488);
            goto L_80801CF0;
    }
    goto skip_0;
    // 0x80801CE4: lbu         $t7, 0x488($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X488);
    skip_0:
    // 0x80801CE8: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80801CEC: lbu         $t7, 0x488($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X488);
L_80801CF0:
    // 0x80801CF0: bnel        $a1, $t7, L_80801D00
    if (ctx->r5 != ctx->r15) {
        // 0x80801CF4: lbu         $t8, 0x489($a0)
        ctx->r24 = MEM_BU(ctx->r4, 0X489);
            goto L_80801D00;
    }
    goto skip_1;
    // 0x80801CF4: lbu         $t8, 0x489($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X489);
    skip_1:
    // 0x80801CF8: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80801CFC: lbu         $t8, 0x489($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X489);
L_80801D00:
    // 0x80801D00: bnel        $a1, $t8, L_80801D10
    if (ctx->r5 != ctx->r24) {
        // 0x80801D04: lbu         $t9, 0x48A($a0)
        ctx->r25 = MEM_BU(ctx->r4, 0X48A);
            goto L_80801D10;
    }
    goto skip_2;
    // 0x80801D04: lbu         $t9, 0x48A($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X48A);
    skip_2:
    // 0x80801D08: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80801D0C: lbu         $t9, 0x48A($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X48A);
L_80801D10:
    // 0x80801D10: bne         $a1, $t9, L_80801D1C
    if (ctx->r5 != ctx->r25) {
        // 0x80801D14: nop
    
            goto L_80801D1C;
    }
    // 0x80801D14: nop

    // 0x80801D18: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
L_80801D1C:
    // 0x80801D1C: bne         $a2, $a3, L_80801CD8
    if (ctx->r6 != ctx->r7) {
        // 0x80801D20: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80801CD8;
    }
    // 0x80801D20: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80801D24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801D28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801D2C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80801D30: jr          $ra
    // 0x80801D34: nop

    return;
    // 0x80801D34: nop

;}
RECOMP_FUNC void _gcmapsects_entrypoint_24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087FC0: syscall     662
    recomp_syscall_handler(rdram, ctx, 0x80087FC0);
    return;
    // 0x80087FC4: addi        $t0, $zero, 0x60
    ctx->r8 = ADD32(0, 0X60);
;}
RECOMP_FUNC void _bstrexsmall_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800840A0: syscall     102
    recomp_syscall_handler(rdram, ctx, 0x800840A0);
    return;
    // 0x800840A4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80099A70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099A70: lw          $t6, 0xC0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC0);
    // 0x80099A74: jr          $ra
    // 0x80099A78: lw          $v0, 0x20($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X20);
    return;
    // 0x80099A78: lw          $v0, 0x20($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X20);
;}
RECOMP_FUNC void func_80800320_chpawnbroker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800320: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800324: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800328: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8080032C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80800330: jal         0x80088278
    // 0x80800334: addiu       $a0, $zero, 0x154
    ctx->r4 = ADD32(0, 0X154);
    _gccubesearch_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800334: addiu       $a0, $zero, 0x154
    ctx->r4 = ADD32(0, 0X154);
    after_0:
    // 0x80800338: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8080033C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800340: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    // 0x80800344: jal         0x800EE88C
    // 0x80800348: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_800EE88C(rdram, ctx);
        goto after_1;
    // 0x80800348: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_1:
    // 0x8080034C: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x80800350: jal         0x800D0B68
    // 0x80800354: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0B68(rdram, ctx);
        goto after_2;
    // 0x80800354: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800358: beq         $v0, $zero, L_80800378
    if (ctx->r2 == 0) {
        // 0x8080035C: addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
            goto L_80800378;
    }
    // 0x8080035C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80800360: jal         0x800D0B68
    // 0x80800364: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800D0B68(rdram, ctx);
        goto after_3;
    // 0x80800364: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
    // 0x80800368: beq         $v0, $zero, L_80800378
    if (ctx->r2 == 0) {
        // 0x8080036C: addiu       $t6, $zero, 0x8
        ctx->r14 = ADD32(0, 0X8);
            goto L_80800378;
    }
    // 0x8080036C: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80800370: b           L_80800478
    // 0x80800374: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
        goto L_80800478;
    // 0x80800374: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
L_80800378:
    // 0x80800378: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x8080037C: jal         0x800D0B68
    // 0x80800380: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0B68(rdram, ctx);
        goto after_4;
    // 0x80800380: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800384: beq         $v0, $zero, L_80800458
    if (ctx->r2 == 0) {
        // 0x80800388: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80800458;
    }
    // 0x80800388: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8080038C: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x80800390: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800394: jal         0x80087898
    // 0x80800398: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _plsu_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x80800398: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x8080039C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808003A0: beq         $v0, $at, L_808003D0
    if (ctx->r2 == ctx->r1) {
        // 0x808003A4: addiu       $a0, $sp, 0x34
        ctx->r4 = ADD32(ctx->r29, 0X34);
            goto L_808003D0;
    }
    // 0x808003A4: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808003A8: jal         0x800EEAD4
    // 0x808003AC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800EEAD4(rdram, ctx);
        goto after_6;
    // 0x808003AC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x808003B0: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x808003B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808003B8: nop

    // 0x808003BC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808003C0: nop

    // 0x808003C4: bc1f        L_808003D0
    if (!c1cs) {
        // 0x808003C8: nop
    
            goto L_808003D0;
    }
    // 0x808003C8: nop

    // 0x808003CC: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_808003D0:
    // 0x808003D0: jal         0x800DA298
    // 0x808003D4: addiu       $a0, $zero, 0xB5
    ctx->r4 = ADD32(0, 0XB5);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x808003D4: addiu       $a0, $zero, 0xB5
    ctx->r4 = ADD32(0, 0XB5);
    after_7:
    // 0x808003D8: beq         $v0, $zero, L_80800414
    if (ctx->r2 == 0) {
        // 0x808003DC: lw          $t9, 0x30($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X30);
            goto L_80800414;
    }
    // 0x808003DC: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x808003E0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x808003E4: jal         0x800D0A9C
    // 0x808003E8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800D0A9C(rdram, ctx);
        goto after_8;
    // 0x808003E8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_8:
    // 0x808003EC: bne         $v0, $zero, L_80800408
    if (ctx->r2 != 0) {
        // 0x808003F0: addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
            goto L_80800408;
    }
    // 0x808003F0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x808003F4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808003F8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x808003FC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80800400: jal         0x800D1000
    // 0x80800404: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D1000(rdram, ctx);
        goto after_9;
    // 0x80800404: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_9:
L_80800408:
    // 0x80800408: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x8080040C: b           L_80800478
    // 0x80800410: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
        goto L_80800478;
    // 0x80800410: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
L_80800414:
    // 0x80800414: beq         $t9, $zero, L_80800450
    if (ctx->r25 == 0) {
        // 0x80800418: addiu       $t1, $zero, 0x5
        ctx->r9 = ADD32(0, 0X5);
            goto L_80800450;
    }
    // 0x80800418: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x8080041C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80800420: jal         0x800D0A9C
    // 0x80800424: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800D0A9C(rdram, ctx);
        goto after_10;
    // 0x80800424: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_10:
    // 0x80800428: bne         $v0, $zero, L_80800444
    if (ctx->r2 != 0) {
        // 0x8080042C: addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
            goto L_80800444;
    }
    // 0x8080042C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80800430: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800434: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80800438: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x8080043C: jal         0x800D1000
    // 0x80800440: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D1000(rdram, ctx);
        goto after_11;
    // 0x80800440: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_11:
L_80800444:
    // 0x80800444: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x80800448: b           L_80800478
    // 0x8080044C: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
        goto L_80800478;
    // 0x8080044C: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
L_80800450:
    // 0x80800450: b           L_80800478
    // 0x80800454: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
        goto L_80800478;
    // 0x80800454: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
L_80800458:
    // 0x80800458: jal         0x800DA298
    // 0x8080045C: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    func_800DA298(rdram, ctx);
        goto after_12;
    // 0x8080045C: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    after_12:
    // 0x80800460: beq         $v0, $zero, L_80800474
    if (ctx->r2 == 0) {
        // 0x80800464: addiu       $t3, $zero, 0x2
        ctx->r11 = ADD32(0, 0X2);
            goto L_80800474;
    }
    // 0x80800464: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80800468: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x8080046C: b           L_80800478
    // 0x80800470: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
        goto L_80800478;
    // 0x80800470: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
L_80800474:
    // 0x80800474: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
L_80800478:
    // 0x80800478: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x8080047C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800480: beq         $t4, $at, L_80800498
    if (ctx->r12 == ctx->r1) {
        // 0x80800484: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80800498;
    }
    // 0x80800484: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800488: beq         $t4, $at, L_80800498
    if (ctx->r12 == ctx->r1) {
        // 0x8080048C: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_80800498;
    }
    // 0x8080048C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800490: jal         0x80108B04
    // 0x80800494: addiu       $a1, $zero, 0x353
    ctx->r5 = ADD32(0, 0X353);
    func_80108B04(rdram, ctx);
        goto after_13;
    // 0x80800494: addiu       $a1, $zero, 0x353
    ctx->r5 = ADD32(0, 0X353);
    after_13:
L_80800498:
    // 0x80800498: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8080049C: jal         0x80100094
    // 0x808004A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_14;
    // 0x808004A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x808004A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808004A8: addiu       $a1, $zero, 0x4E4
    ctx->r5 = ADD32(0, 0X4E4);
    // 0x808004AC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x808004B0: jal         0x80089FD0
    // 0x808004B4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _subaddieitem_entrypoint_0(rdram, ctx);
        goto after_15;
    // 0x808004B4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_15:
    // 0x808004B8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x808004BC: jal         0x80100094
    // 0x808004C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_16;
    // 0x808004C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x808004C4: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x808004C8: jal         0x800DA298
    // 0x808004CC: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    func_800DA298(rdram, ctx);
        goto after_17;
    // 0x808004CC: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    after_17:
    // 0x808004D0: beq         $v0, $zero, L_808004E0
    if (ctx->r2 == 0) {
        // 0x808004D4: addiu       $a1, $zero, 0x14
        ctx->r5 = ADD32(0, 0X14);
            goto L_808004E0;
    }
    // 0x808004D4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x808004D8: b           L_808004E0
    // 0x808004DC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
        goto L_808004E0;
    // 0x808004DC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
L_808004E0:
    // 0x808004E0: jal         0x80089FD8
    // 0x808004E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    _subaddieitem_entrypoint_1(rdram, ctx);
        goto after_18;
    // 0x808004E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_18:
    // 0x808004E8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x808004EC: jal         0x80101FDC
    // 0x808004F0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_80101FDC(rdram, ctx);
        goto after_19;
    // 0x808004F0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_19:
    // 0x808004F4: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x808004F8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808004FC: jal         0x8010A3E8
    // 0x80800500: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_8010A3E8(rdram, ctx);
        goto after_20;
    // 0x80800500: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_20:
    // 0x80800504: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800508: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8080050C: jr          $ra
    // 0x80800510: nop

    return;
    // 0x80800510: nop

;}
RECOMP_FUNC void func_8080142C_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080142C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801430: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801434: jal         0x808000F0
    // 0x80801438: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808000F0_bswasher(rdram, ctx);
        goto after_0;
    // 0x80801438: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080143C: jal         0x80090A2C
    // 0x80801440: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80090A2C(rdram, ctx);
        goto after_1;
    // 0x80801440: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801444: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801448: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080144C: jr          $ra
    // 0x80801450: nop

    return;
    // 0x80801450: nop

;}
RECOMP_FUNC void _bskazmove_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800834D0: syscall     63
    recomp_syscall_handler(rdram, ctx, 0x800834D0);
    return;
    // 0x800834D4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_8080000C_chiciclebits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800018: lhu         $v0, 0x76($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X76);
    // 0x8080001C: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1228, 0X3E8) << 16);
    // 0x80800020: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800024: srl         $t6, $v0, 7
    ctx->r14 = S32(U32(ctx->r2) >> 7);
    // 0x80800028: addiu       $v0, $t6, -0x32
    ctx->r2 = ADD32(ctx->r14, -0X32);
    // 0x8080002C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80800030: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x80800034: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80800038: addiu       $t8, $t8, 0x3E8
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1228, 0X3E8));
    // 0x8080003C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x80800040: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800044: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800048: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080004C: jal         0x800EE88C
    // 0x80800050: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_800EE88C(rdram, ctx);
        goto after_0;
    // 0x80800050: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80800054: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800058: jal         0x800EF334
    // 0x8080005C: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    func_800EF334(rdram, ctx);
        goto after_1;
    // 0x8080005C: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    after_1:
    // 0x80800060: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80800064: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80800068: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8080006C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800070: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1228, 0X390) << 16);
    // 0x80800074: sw          $t9, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r25;
    // 0x80800078: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x8080007C: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    // 0x80800080: lwc1        $f6, 0x390($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1228, 0X390));
    // 0x80800084: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80800088: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x8080008C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80800090: jal         0x800DA298
    // 0x80800094: lhu         $a0, 0x6($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X6);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800094: lhu         $a0, 0x6($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X6);
    after_2:
    // 0x80800098: beql        $v0, $zero, L_808000C0
    if (ctx->r2 == 0) {
        // 0x8080009C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808000C0;
    }
    goto skip_0;
    // 0x8080009C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808000A0: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A8: jal         0x8010A570
    // 0x808000AC: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    func_8010A570(rdram, ctx);
        goto after_3;
    // 0x808000AC: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    after_3:
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B4: jal         0x80101FDC
    // 0x808000B8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x808000B8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_4:
    // 0x808000BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000C0:
    // 0x808000C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000C4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808000C8: jr          $ra
    // 0x808000CC: nop

    return;
    // 0x808000CC: nop

;}
RECOMP_FUNC void func_80800058_chcoderoombits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800058: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080005C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800060: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80800064: jal         0x80100094
    // 0x80800068: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800068: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080006C: jal         0x800F54E4
    // 0x80800070: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80800070: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800074: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800078: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080007C: jal         0x800F5A00
    // 0x80800080: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800F5A00(rdram, ctx);
        goto after_2;
    // 0x80800080: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_2:
    // 0x80800084: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80800088: lhu         $t7, 0x72($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X72);
    // 0x8080008C: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80800090: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80800094: sltiu       $at, $t9, 0x5
    ctx->r1 = ctx->r25 < 0X5 ? 1 : 0;
    // 0x80800098: beq         $at, $zero, L_80800324
    if (ctx->r1 == 0) {
        // 0x8080009C: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80800324;
    }
    // 0x8080009C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x808000A0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1172, 0X1138) << 16);
    // 0x808000A4: addu        $at, $at, $t9
    gpr jr_addend_808000AC = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x808000A8: lw          $t9, 0x1138($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1172, 0X1138));
    // 0x808000AC: jr          $t9
    // 0x808000B0: nop

    switch (jr_addend_808000AC >> 2) {
        case 0: goto L_808000B4; break;
        case 1: goto L_80800258; break;
        case 2: goto L_80800324; break;
        case 3: goto L_808002D0; break;
        case 4: goto L_80800308; break;
        default: switch_error(__func__, 0x808000AC, 0x80801138);
    }
    // 0x808000B0: nop

L_808000B4:
    // 0x808000B4: jal         0x800DA298
    // 0x808000B8: addiu       $a0, $zero, 0x6A
    ctx->r4 = ADD32(0, 0X6A);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x808000B8: addiu       $a0, $zero, 0x6A
    ctx->r4 = ADD32(0, 0X6A);
    after_3:
    // 0x808000BC: bne         $v0, $zero, L_80800150
    if (ctx->r2 != 0) {
        // 0x808000C0: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_80800150;
    }
    // 0x808000C0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808000C4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808000C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808000CC: jal         0x8010C9B0
    // 0x808000D0: addiu       $a1, $zero, 0x15E
    ctx->r5 = ADD32(0, 0X15E);
    func_8010C9B0(rdram, ctx);
        goto after_4;
    // 0x808000D0: addiu       $a1, $zero, 0x15E
    ctx->r5 = ADD32(0, 0X15E);
    after_4:
    // 0x808000D4: beq         $v0, $zero, L_80800324
    if (ctx->r2 == 0) {
        // 0x808000D8: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_80800324;
    }
    // 0x808000D8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808000DC: jal         0x800F64A4
    // 0x808000E0: addiu       $a1, $zero, 0x201
    ctx->r5 = ADD32(0, 0X201);
    func_800F64A4(rdram, ctx);
        goto after_5;
    // 0x808000E0: addiu       $a1, $zero, 0x201
    ctx->r5 = ADD32(0, 0X201);
    after_5:
    // 0x808000E4: beq         $v0, $zero, L_80800324
    if (ctx->r2 == 0) {
        // 0x808000E8: nop
    
            goto L_80800324;
    }
    // 0x808000E8: nop

    // 0x808000EC: jal         0x800C6E38
    // 0x808000F0: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_800C6E38(rdram, ctx);
        goto after_6;
    // 0x808000F0: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_6:
    // 0x808000F4: beq         $v0, $zero, L_80800108
    if (ctx->r2 == 0) {
        // 0x808000F8: addiu       $a2, $zero, 0x4
        ctx->r6 = ADD32(0, 0X4);
            goto L_80800108;
    }
    // 0x808000F8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x808000FC: addiu       $t0, $zero, 0x1140
    ctx->r8 = ADD32(0, 0X1140);
    // 0x80800100: b           L_80800110
    // 0x80800104: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
        goto L_80800110;
    // 0x80800104: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
L_80800108:
    // 0x80800108: addiu       $t1, $zero, 0x115C
    ctx->r9 = ADD32(0, 0X115C);
    // 0x8080010C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
L_80800110:
    // 0x80800110: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800114: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800118: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8080011C: jal         0x8008A2C8
    // 0x80800120: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_7;
    // 0x80800120: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_7:
    // 0x80800124: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80800128: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8080012C: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800130: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x80800134: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800138: jal         0x8008A208
    // 0x8080013C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x8080013C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_8:
    // 0x80800140: jal         0x800DA544
    // 0x80800144: addiu       $a0, $zero, 0x6A
    ctx->r4 = ADD32(0, 0X6A);
    func_800DA544(rdram, ctx);
        goto after_9;
    // 0x80800144: addiu       $a0, $zero, 0x6A
    ctx->r4 = ADD32(0, 0X6A);
    after_9:
    // 0x80800148: b           L_80800324
    // 0x8080014C: nop

        goto L_80800324;
    // 0x8080014C: nop

L_80800150:
    // 0x80800150: jal         0x800C6E38
    // 0x80800154: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_800C6E38(rdram, ctx);
        goto after_10;
    // 0x80800154: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_10:
    // 0x80800158: beq         $v0, $zero, L_80800324
    if (ctx->r2 == 0) {
        // 0x8080015C: nop
    
            goto L_80800324;
    }
    // 0x8080015C: nop

    // 0x80800160: jal         0x800F6478
    // 0x80800164: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800F6478(rdram, ctx);
        goto after_11;
    // 0x80800164: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_11:
    // 0x80800168: beq         $v0, $zero, L_80800324
    if (ctx->r2 == 0) {
        // 0x8080016C: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_80800324;
    }
    // 0x8080016C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800170: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800174: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800178: jal         0x800EEAD4
    // 0x8080017C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800EEAD4(rdram, ctx);
        goto after_12;
    // 0x8080017C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_12:
    // 0x80800180: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800184: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800188: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8080018C: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80800190: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800194: nop

    // 0x80800198: bc1fl       L_808001AC
    if (!c1cs) {
        // 0x8080019C: lbu         $t5, 0x18($t4)
        ctx->r13 = MEM_BU(ctx->r12, 0X18);
            goto L_808001AC;
    }
    goto skip_0;
    // 0x8080019C: lbu         $t5, 0x18($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X18);
    skip_0:
    // 0x808001A0: b           L_80800324
    // 0x808001A4: sb          $zero, 0x18($t3)
    MEM_B(0X18, ctx->r11) = 0;
        goto L_80800324;
    // 0x808001A4: sb          $zero, 0x18($t3)
    MEM_B(0X18, ctx->r11) = 0;
    // 0x808001A8: lbu         $t5, 0x18($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X18);
L_808001AC:
    // 0x808001AC: bne         $t5, $zero, L_80800324
    if (ctx->r13 != 0) {
        // 0x808001B0: nop
    
            goto L_80800324;
    }
    // 0x808001B0: nop

    // 0x808001B4: jal         0x800F6C5C
    // 0x808001B8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800F6C5C(rdram, ctx);
        goto after_13;
    // 0x808001B8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_13:
    // 0x808001BC: beq         $v0, $zero, L_80800324
    if (ctx->r2 == 0) {
        // 0x808001C0: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_80800324;
    }
    // 0x808001C0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808001C4: jal         0x800F64A4
    // 0x808001C8: addiu       $a1, $zero, 0x201
    ctx->r5 = ADD32(0, 0X201);
    func_800F64A4(rdram, ctx);
        goto after_14;
    // 0x808001C8: addiu       $a1, $zero, 0x201
    ctx->r5 = ADD32(0, 0X201);
    after_14:
    // 0x808001CC: beq         $v0, $zero, L_80800324
    if (ctx->r2 == 0) {
        // 0x808001D0: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_80800324;
    }
    // 0x808001D0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808001D4: jal         0x800F52B8
    // 0x808001D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F52B8(rdram, ctx);
        goto after_15;
    // 0x808001D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x808001DC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x808001E0: beq         $v0, $at, L_80800324
    if (ctx->r2 == ctx->r1) {
        // 0x808001E4: nop
    
            goto L_80800324;
    }
    // 0x808001E4: nop

    // 0x808001E8: jal         0x800F497C
    // 0x808001EC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800F497C(rdram, ctx);
        goto after_16;
    // 0x808001EC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_16:
    // 0x808001F0: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x808001F4: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x808001F8: addiu       $a1, $a1, -0x2A24
    ctx->r5 = ADD32(ctx->r5, -0X2A24);
    // 0x808001FC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800200: jal         0x800F49D4
    // 0x80800204: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    func_800F49D4(rdram, ctx);
        goto after_17;
    // 0x80800204: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    after_17:
    // 0x80800208: lui         $a2, 0x3F19
    ctx->r6 = S32(0X3F19 << 16);
    // 0x8080020C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800210: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800214: jal         0x800F4A8C
    // 0x80800218: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800F4A8C(rdram, ctx);
        goto after_18;
    // 0x80800218: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_18:
    // 0x8080021C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800220: jal         0x800F4A00
    // 0x80800224: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F4A00(rdram, ctx);
        goto after_19;
    // 0x80800224: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_19:
    // 0x80800228: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8080022C: jal         0x800F7F98
    // 0x80800230: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F7F98(rdram, ctx);
        goto after_20;
    // 0x80800230: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
    // 0x80800234: jal         0x808004B8
    // 0x80800238: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_808004B8_chcoderoombits(rdram, ctx);
        goto after_21;
    // 0x80800238: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_21:
    // 0x8080023C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800240: jal         0x80101FDC
    // 0x80800244: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_22;
    // 0x80800244: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_22:
    // 0x80800248: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8080024C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800250: b           L_80800324
    // 0x80800254: sb          $t7, 0x18($t8)
    MEM_B(0X18, ctx->r24) = ctx->r15;
        goto L_80800324;
    // 0x80800254: sb          $t7, 0x18($t8)
    MEM_B(0X18, ctx->r24) = ctx->r15;
L_80800258:
    // 0x80800258: jal         0x800F5C94
    // 0x8080025C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800F5C94(rdram, ctx);
        goto after_23;
    // 0x8080025C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_23:
    // 0x80800260: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800264: bne         $v0, $at, L_80800324
    if (ctx->r2 != ctx->r1) {
        // 0x80800268: nop
    
            goto L_80800324;
    }
    // 0x80800268: nop

    // 0x8080026C: jal         0x800DA298
    // 0x80800270: addiu       $a0, $zero, 0x6B
    ctx->r4 = ADD32(0, 0X6B);
    func_800DA298(rdram, ctx);
        goto after_24;
    // 0x80800270: addiu       $a0, $zero, 0x6B
    ctx->r4 = ADD32(0, 0X6B);
    after_24:
    // 0x80800274: bne         $v0, $zero, L_808002B4
    if (ctx->r2 != 0) {
        // 0x80800278: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_808002B4;
    }
    // 0x80800278: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8080027C: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80800280: addiu       $a1, $zero, 0x1141
    ctx->r5 = ADD32(0, 0X1141);
    // 0x80800284: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80800288: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x8080028C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800290: jal         0x8008A208
    // 0x80800294: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_25;
    // 0x80800294: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_25:
    // 0x80800298: jal         0x800DA544
    // 0x8080029C: addiu       $a0, $zero, 0x6B
    ctx->r4 = ADD32(0, 0X6B);
    func_800DA544(rdram, ctx);
        goto after_26;
    // 0x8080029C: addiu       $a0, $zero, 0x6B
    ctx->r4 = ADD32(0, 0X6B);
    after_26:
    // 0x808002A0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808002A4: jal         0x80101FDC
    // 0x808002A8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_27;
    // 0x808002A8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_27:
    // 0x808002AC: b           L_80800324
    // 0x808002B0: nop

        goto L_80800324;
    // 0x808002B0: nop

L_808002B4:
    // 0x808002B4: jal         0x80101FDC
    // 0x808002B8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_28;
    // 0x808002B8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_28:
    // 0x808002BC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808002C0: jal         0x800F7F98
    // 0x808002C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F7F98(rdram, ctx);
        goto after_29;
    // 0x808002C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_29:
    // 0x808002C8: b           L_80800324
    // 0x808002CC: nop

        goto L_80800324;
    // 0x808002CC: nop

L_808002D0:
    // 0x808002D0: jal         0x800F5C94
    // 0x808002D4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800F5C94(rdram, ctx);
        goto after_30;
    // 0x808002D4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_30:
    // 0x808002D8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808002DC: beq         $v0, $at, L_80800324
    if (ctx->r2 == ctx->r1) {
        // 0x808002E0: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_80800324;
    }
    // 0x808002E0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808002E4: jal         0x80101FDC
    // 0x808002E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_31;
    // 0x808002E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_31:
    // 0x808002EC: jal         0x800F53D0
    // 0x808002F0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800F53D0(rdram, ctx);
        goto after_32;
    // 0x808002F0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_32:
    // 0x808002F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002F8: jal         0x800946C4
    // 0x808002FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800946C4(rdram, ctx);
        goto after_33;
    // 0x808002FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_33:
    // 0x80800300: b           L_80800324
    // 0x80800304: nop

        goto L_80800324;
    // 0x80800304: nop

L_80800308:
    // 0x80800308: jal         0x800C064C
    // 0x8080030C: nop

    func_800C064C(rdram, ctx);
        goto after_34;
    // 0x8080030C: nop

    after_34:
    // 0x80800310: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800314: bne         $v0, $at, L_80800324
    if (ctx->r2 != ctx->r1) {
        // 0x80800318: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_80800324;
    }
    // 0x80800318: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8080031C: jal         0x80101FDC
    // 0x80800320: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_35;
    // 0x80800320: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_35:
L_80800324:
    // 0x80800324: jal         0x80800BF4
    // 0x80800328: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_80800BF4_chcoderoombits(rdram, ctx);
        goto after_36;
    // 0x80800328: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_36:
    // 0x8080032C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800330: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800334: jr          $ra
    // 0x80800338: nop

    return;
    // 0x80800338: nop

;}
RECOMP_FUNC void func_80802298_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802298: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080229C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808022A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808022A4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x808022A8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x808022AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808022B0: jal         0x800EE7F8
    // 0x808022B4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808022B4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_0:
    // 0x808022B8: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x808022BC: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x808022C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808022C4: lwc1        $f4, 0x38($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X38);
    // 0x808022C8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808022CC: lw          $a1, 0x48($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X48);
    // 0x808022D0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808022D4: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x808022D8: jal         0x800EF1B8
    // 0x808022DC: nop

    func_800EF1B8(rdram, ctx);
        goto after_1;
    // 0x808022DC: nop

    after_1:
    // 0x808022E0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808022E4: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9A2C) << 16);
    // 0x808022E8: lwc1        $f16, -0x65D4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9A2C));
    // 0x808022EC: lwc1        $f10, 0x38($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X38);
    // 0x808022F0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x808022F4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x808022F8: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x808022FC: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80802300: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80802304: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802308: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080230C: jr          $ra
    // 0x80802310: nop

    return;
    // 0x80802310: nop

;}
RECOMP_FUNC void func_808000CC_glsavegame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000D4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808000D8: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x808000DC: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x808000E0: jal         0x80088588
    // 0x808000E4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _glgamedata_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808000E4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x808000E8: beq         $v0, $zero, L_80800108
    if (ctx->r2 == 0) {
        // 0x808000EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800108;
    }
    // 0x808000EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000F0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808000F4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x808000F8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x808000FC: lbu         $v0, 0x0($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X0);
    // 0x80800100: b           L_8080010C
    // 0x80800104: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_8080010C;
    // 0x80800104: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_80800108:
    // 0x80800108: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8080010C:
    // 0x8080010C: jr          $ra
    // 0x80800110: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800110: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _ncbaspline_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089390: syscall     776
    recomp_syscall_handler(rdram, ctx, 0x80089390);
    return;
    // 0x80089394: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void bastick_getX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EF28: lw          $t6, 0x128($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X128);
    // 0x8009EF2C: jr          $ra
    // 0x8009EF30: lwc1        $f0, 0x54($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X54);
    return;
    // 0x8009EF30: lwc1        $f0, 0x54($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X54);
;}
RECOMP_FUNC void func_800A5D60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5D60: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A5D64: jr          $ra
    // 0x800A5D68: addiu       $v0, $v0, 0x7110
    ctx->r2 = ADD32(ctx->r2, 0X7110);
    return;
    // 0x800A5D68: addiu       $v0, $v0, 0x7110
    ctx->r2 = ADD32(ctx->r2, 0X7110);
;}
RECOMP_FUNC void bawasher_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808000AC: lw          $t6, 0x14C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14C);
    // 0x808000B0: jr          $ra
    // 0x808000B4: swc1        $f12, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x808000B4: swc1        $f12, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_80107BB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107BB0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80107BB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80107BB8: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80107BBC: addiu       $a0, $zero, 0x4F0
    ctx->r4 = ADD32(0, 0X4F0);
    // 0x80107BC0: jal         0x800882C0
    // 0x80107BC4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    _gccubesearch_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x80107BC4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x80107BC8: blez        $v0, L_80107BE4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80107BCC: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80107BE4;
    }
    // 0x80107BCC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80107BD0: jal         0x80088C50
    // 0x80107BD4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _gspropmarker_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80107BD4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80107BD8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80107BDC: b           L_80107BF0
    // 0x80107BE0: swc1        $f0, 0x6F10($at)
    MEM_W(0X6F10, ctx->r1) = ctx->f0.u32l;
        goto L_80107BF0;
    // 0x80107BE0: swc1        $f0, 0x6F10($at)
    MEM_W(0X6F10, ctx->r1) = ctx->f0.u32l;
L_80107BE4:
    // 0x80107BE4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80107BE8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80107BEC: swc1        $f4, 0x6F10($at)
    MEM_W(0X6F10, ctx->r1) = ctx->f4.u32l;
L_80107BF0:
    // 0x80107BF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80107BF4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80107BF8: jr          $ra
    // 0x80107BFC: nop

    return;
    // 0x80107BFC: nop

;}
RECOMP_FUNC void _chfiregen_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800869E0: syscall     404
    recomp_syscall_handler(rdram, ctx, 0x800869E0);
    return;
    // 0x800869E4: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_800FB1B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FB1B0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800FB1B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FB1B8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800FB1BC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800FB1C0: jal         0x800EE7F8
    // 0x800FB1C4: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800FB1C4: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x800FB1C8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800FB1CC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800FB1D0: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x800FB1D4: jal         0x800C6A7C
    // 0x800FB1D8: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    func_800C6A7C(rdram, ctx);
        goto after_1;
    // 0x800FB1D8: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x800FB1DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FB1E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800FB1E4: jr          $ra
    // 0x800FB1E8: nop

    return;
    // 0x800FB1E8: nop

;}
RECOMP_FUNC void func_808003A8_chquizremotectrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808003AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808003B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808003BC: jal         0x800CEA38
    // 0x808003C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800CEA38(rdram, ctx);
        goto after_0;
    // 0x808003C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808003C4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808003C8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808003CC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808003D0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808003D4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808003D8: jal         0x800EFA4C
    // 0x808003DC: nop

    func_800EFA4C(rdram, ctx);
        goto after_1;
    // 0x808003DC: nop

    after_1:
    // 0x808003E0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808003EC: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
    // 0x808003F0: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x808003F4: jal         0x808001BC
    // 0x808003F8: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    func_808001BC_chquizremotectrl(rdram, ctx);
        goto after_2;
    // 0x808003F8: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    after_2:
    // 0x808003FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800400: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800404: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800408: jr          $ra
    // 0x8080040C: nop

    return;
    // 0x8080040C: nop

;}
RECOMP_FUNC void func_8010CCE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010CCE0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010CCE4: jr          $ra
    // 0x8010CCE8: sw          $zero, 0x6F8C($at)
    MEM_W(0X6F8C, ctx->r1) = 0;
    return;
    // 0x8010CCE8: sw          $zero, 0x6F8C($at)
    MEM_W(0X6F8C, ctx->r1) = 0;
;}
RECOMP_FUNC void _bsfirstp_entrypoint_35(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800843A0: syscall     108
    recomp_syscall_handler(rdram, ctx, 0x800843A0);
    return;
    // 0x800843A4: addi        $t0, $zero, 0x8C
    ctx->r8 = ADD32(0, 0X8C);
;}
RECOMP_FUNC void _basudie_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085258: syscall     155
    recomp_syscall_handler(rdram, ctx, 0x80085258);
    return;
    // 0x8008525C: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_8080298C_chfantasyathlete(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080298C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80802990: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80802994: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80802998: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080299C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x808029A0: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x808029A4: jal         0x80801718
    // 0x808029A8: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    func_80801718_chfantasyathlete(rdram, ctx);
        goto after_0;
    // 0x808029A8: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    after_0:
    // 0x808029AC: jal         0x80105834
    // 0x808029B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105834(rdram, ctx);
        goto after_1;
    // 0x808029B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808029B4: jal         0x800F54E4
    // 0x808029B8: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x808029B8: nop

    after_2:
    // 0x808029BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808029C0: jal         0x800F5A00
    // 0x808029C4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800F5A00(rdram, ctx);
        goto after_3;
    // 0x808029C4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_3:
    // 0x808029C8: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x808029CC: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x808029D0: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x808029D4: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x808029D8: bltzl       $t8, L_80802AB8
    if (SIGNED(ctx->r24) < 0) {
        // 0x808029DC: lw          $t1, 0x64($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X64);
            goto L_80802AB8;
    }
    goto skip_0;
    // 0x808029DC: lw          $t1, 0x64($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X64);
    skip_0:
    // 0x808029E0: lwc1        $f6, 0x4($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X4);
    // 0x808029E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808029E8: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x808029EC: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x808029F0: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x808029F4: nop

    // 0x808029F8: bc1fl       L_80802A68
    if (!c1cs) {
        // 0x808029FC: lwc1        $f16, 0x58($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
            goto L_80802A68;
    }
    goto skip_1;
    // 0x808029FC: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    skip_1:
    // 0x80802A00: jal         0x800F54E4
    // 0x80802A04: nop

    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x80802A04: nop

    after_4:
    // 0x80802A08: jal         0x800F6C5C
    // 0x80802A0C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6C5C(rdram, ctx);
        goto after_5;
    // 0x80802A0C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x80802A10: bnel        $v0, $zero, L_80802A68
    if (ctx->r2 != 0) {
        // 0x80802A14: lwc1        $f16, 0x58($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
            goto L_80802A68;
    }
    goto skip_2;
    // 0x80802A14: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    skip_2:
    // 0x80802A18: jal         0x800F54E4
    // 0x80802A1C: nop

    func_800F54E4(rdram, ctx);
        goto after_6;
    // 0x80802A1C: nop

    after_6:
    // 0x80802A20: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802A24: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80802A28: jal         0x800F7ECC
    // 0x80802A2C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_800F7ECC(rdram, ctx);
        goto after_7;
    // 0x80802A2C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_7:
    // 0x80802A30: jal         0x800FDC28
    // 0x80802A34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FDC28(rdram, ctx);
        goto after_8;
    // 0x80802A34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x80802A38: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
    // 0x80802A3C: sll         $t2, $t0, 11
    ctx->r10 = S32(ctx->r8 << 11);
    // 0x80802A40: bltz        $t2, L_80802A5C
    if (SIGNED(ctx->r10) < 0) {
        // 0x80802A44: nop
    
            goto L_80802A5C;
    }
    // 0x80802A44: nop

    // 0x80802A48: jal         0x800FC6B0
    // 0x80802A4C: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_800FC6B0(rdram, ctx);
        goto after_9;
    // 0x80802A4C: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_9:
    // 0x80802A50: lbu         $t4, 0x65($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X65);
    // 0x80802A54: ori         $t5, $t4, 0x8
    ctx->r13 = ctx->r12 | 0X8;
    // 0x80802A58: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
L_80802A5C:
    // 0x80802A5C: b           L_80802C04
    // 0x80802A60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802C04;
    // 0x80802A60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80802A64: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
L_80802A68:
    // 0x80802A68: addiu       $t6, $sp, 0x3C
    ctx->r14 = ADD32(ctx->r29, 0X3C);
    // 0x80802A6C: addiu       $t7, $s0, 0x2C
    ctx->r15 = ADD32(ctx->r16, 0X2C);
    // 0x80802A70: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80802A74: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80802A78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802A7C: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80802A80: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x80802A84: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x80802A88: jal         0x80801114
    // 0x80802A8C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_80801114_chfantasyathlete(rdram, ctx);
        goto after_10;
    // 0x80802A8C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_10:
    // 0x80802A90: beql        $v0, $zero, L_80802AB8
    if (ctx->r2 == 0) {
        // 0x80802A94: lw          $t1, 0x64($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X64);
            goto L_80802AB8;
    }
    goto skip_3;
    // 0x80802A94: lw          $t1, 0x64($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X64);
    skip_3:
    // 0x80802A98: jal         0x800FDC28
    // 0x80802A9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FDC28(rdram, ctx);
        goto after_11;
    // 0x80802A9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_11:
    // 0x80802AA0: jal         0x800FC6B0
    // 0x80802AA4: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_800FC6B0(rdram, ctx);
        goto after_12;
    // 0x80802AA4: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_12:
    // 0x80802AA8: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x80802AAC: ori         $t0, $t9, 0x10
    ctx->r8 = ctx->r25 | 0X10;
    // 0x80802AB0: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    // 0x80802AB4: lw          $t1, 0x64($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X64);
L_80802AB8:
    // 0x80802AB8: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x80802ABC: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80802AC0: sll         $t3, $t1, 11
    ctx->r11 = S32(ctx->r9 << 11);
    // 0x80802AC4: bltzl       $t3, L_80802B94
    if (SIGNED(ctx->r11) < 0) {
        // 0x80802AC8: lw          $v0, 0x64($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X64);
            goto L_80802B94;
    }
    goto skip_4;
    // 0x80802AC8: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    skip_4:
    // 0x80802ACC: lwc1        $f6, 0x4($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X4);
    // 0x80802AD0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80802AD4: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80802AD8: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80802ADC: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80802AE0: nop

    // 0x80802AE4: bc1fl       L_80802B44
    if (!c1cs) {
        // 0x80802AE8: lwc1        $f10, 0x58($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
            goto L_80802B44;
    }
    goto skip_5;
    // 0x80802AE8: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    skip_5:
    // 0x80802AEC: jal         0x800F54E4
    // 0x80802AF0: nop

    func_800F54E4(rdram, ctx);
        goto after_13;
    // 0x80802AF0: nop

    after_13:
    // 0x80802AF4: jal         0x800F6C5C
    // 0x80802AF8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6C5C(rdram, ctx);
        goto after_14;
    // 0x80802AF8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_14:
    // 0x80802AFC: bnel        $v0, $zero, L_80802B44
    if (ctx->r2 != 0) {
        // 0x80802B00: lwc1        $f10, 0x58($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
            goto L_80802B44;
    }
    goto skip_6;
    // 0x80802B00: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    skip_6:
    // 0x80802B04: jal         0x800F54E4
    // 0x80802B08: nop

    func_800F54E4(rdram, ctx);
        goto after_15;
    // 0x80802B08: nop

    after_15:
    // 0x80802B0C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802B10: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80802B14: jal         0x800F7ECC
    // 0x80802B18: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_800F7ECC(rdram, ctx);
        goto after_16;
    // 0x80802B18: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_16:
    // 0x80802B1C: jal         0x800FDC28
    // 0x80802B20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FDC28(rdram, ctx);
        goto after_17;
    // 0x80802B20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_17:
    // 0x80802B24: jal         0x800FC6B0
    // 0x80802B28: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_800FC6B0(rdram, ctx);
        goto after_18;
    // 0x80802B28: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_18:
    // 0x80802B2C: lbu         $t6, 0x65($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X65);
    // 0x80802B30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80802B34: ori         $t7, $t6, 0x8
    ctx->r15 = ctx->r14 | 0X8;
    // 0x80802B38: b           L_80802C04
    // 0x80802B3C: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
        goto L_80802C04;
    // 0x80802B3C: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
    // 0x80802B40: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
L_80802B44:
    // 0x80802B44: addiu       $t8, $s0, 0x4
    ctx->r24 = ADD32(ctx->r16, 0X4);
    // 0x80802B48: addiu       $t9, $s0, 0x34
    ctx->r25 = ADD32(ctx->r16, 0X34);
    // 0x80802B4C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80802B50: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80802B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802B58: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80802B5C: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x80802B60: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x80802B64: jal         0x80801114
    // 0x80802B68: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_80801114_chfantasyathlete(rdram, ctx);
        goto after_19;
    // 0x80802B68: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_19:
    // 0x80802B6C: beql        $v0, $zero, L_80802B94
    if (ctx->r2 == 0) {
        // 0x80802B70: lw          $v0, 0x64($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X64);
            goto L_80802B94;
    }
    goto skip_7;
    // 0x80802B70: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    skip_7:
    // 0x80802B74: jal         0x800FDC28
    // 0x80802B78: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FDC28(rdram, ctx);
        goto after_20;
    // 0x80802B78: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_20:
    // 0x80802B7C: jal         0x800FC6B0
    // 0x80802B80: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_800FC6B0(rdram, ctx);
        goto after_21;
    // 0x80802B80: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_21:
    // 0x80802B84: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    // 0x80802B88: ori         $t2, $t1, 0x8
    ctx->r10 = ctx->r9 | 0X8;
    // 0x80802B8C: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
    // 0x80802B90: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
L_80802B94:
    // 0x80802B94: sll         $t4, $v0, 11
    ctx->r12 = S32(ctx->r2 << 11);
    // 0x80802B98: bltz        $t4, L_80802BA8
    if (SIGNED(ctx->r12) < 0) {
        // 0x80802B9C: sll         $t6, $v0, 12
        ctx->r14 = S32(ctx->r2 << 12);
            goto L_80802BA8;
    }
    // 0x80802B9C: sll         $t6, $v0, 12
    ctx->r14 = S32(ctx->r2 << 12);
    // 0x80802BA0: bgez        $t6, L_80802C04
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80802BA4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80802C04;
    }
    // 0x80802BA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80802BA8:
    // 0x80802BA8: jal         0x800F54E4
    // 0x80802BAC: nop

    func_800F54E4(rdram, ctx);
        goto after_22;
    // 0x80802BAC: nop

    after_22:
    // 0x80802BB0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802BB4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80802BB8: jal         0x800F7ECC
    // 0x80802BBC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_800F7ECC(rdram, ctx);
        goto after_23;
    // 0x80802BBC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_23:
    // 0x80802BC0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X302C) << 16);
    // 0x80802BC4: lwc1        $f6, 0x302C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X302C));
    // 0x80802BC8: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80802BCC: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x80802BD0: mul.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80802BD4: jal         0x800FCCD4
    // 0x80802BD8: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    func_800FCCD4(rdram, ctx);
        goto after_24;
    // 0x80802BD8: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    after_24:
    // 0x80802BDC: bne         $v0, $zero, L_80802BFC
    if (ctx->r2 != 0) {
        // 0x80802BE0: nop
    
            goto L_80802BFC;
    }
    // 0x80802BE0: nop

    // 0x80802BE4: jal         0x800FCCD4
    // 0x80802BE8: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_800FCCD4(rdram, ctx);
        goto after_25;
    // 0x80802BE8: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_25:
    // 0x80802BEC: bne         $v0, $zero, L_80802BFC
    if (ctx->r2 != 0) {
        // 0x80802BF0: nop
    
            goto L_80802BFC;
    }
    // 0x80802BF0: nop

    // 0x80802BF4: b           L_80802C04
    // 0x80802BF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802C04;
    // 0x80802BF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802BFC:
    // 0x80802BFC: b           L_80802C04
    // 0x80802C00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80802C04;
    // 0x80802C00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80802C04:
    // 0x80802C04: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80802C08: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80802C0C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80802C10: jr          $ra
    // 0x80802C14: nop

    return;
    // 0x80802C14: nop

;}
RECOMP_FUNC void _bsbee_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082840: syscall     15
    recomp_syscall_handler(rdram, ctx, 0x80082840);
    return;
    // 0x80082844: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void gczoomboxdata_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800310: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800314: addiu       $at, $zero, 0x44
    ctx->r1 = ADD32(0, 0X44);
    // 0x80800318: bne         $a0, $at, L_80800328
    if (ctx->r4 != ctx->r1) {
        // 0x8080031C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80800328;
    }
    // 0x8080031C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800320: b           L_80800368
    // 0x80800324: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800368;
    // 0x80800324: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800328:
    // 0x80800328: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080032C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80800330: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800334: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(2686, 0XAA8) << 16);
    // 0x80800338: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x8080033C: lhu         $v1, 0xAA8($v1)
    ctx->r3 = MEM_HU(ctx->r3, (int16_t)RELOC_LO16(2686, 0XAA8));
    // 0x80800340: beq         $v1, $zero, L_8080035C
    if (ctx->r3 == 0) {
        // 0x80800344: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_8080035C;
    }
    // 0x80800344: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80800348: jal         0x800D58FC
    // 0x8080034C: sh          $v1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r3;
    func_800D58FC(rdram, ctx);
        goto after_0;
    // 0x8080034C: sh          $v1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r3;
    after_0:
    // 0x80800350: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800354: bne         $v0, $at, L_80800364
    if (ctx->r2 != ctx->r1) {
        // 0x80800358: lhu         $v1, 0x1E($sp)
        ctx->r3 = MEM_HU(ctx->r29, 0X1E);
            goto L_80800364;
    }
    // 0x80800358: lhu         $v1, 0x1E($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X1E);
L_8080035C:
    // 0x8080035C: b           L_80800368
    // 0x80800360: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800368;
    // 0x80800360: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800364:
    // 0x80800364: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80800368:
    // 0x80800368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080036C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800370: jr          $ra
    // 0x80800374: nop

    return;
    // 0x80800374: nop

;}
RECOMP_FUNC void func_80801020_gcdialogexec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801020: beq         $a0, $zero, L_80801030
    if (ctx->r4 == 0) {
        // 0x80801024: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80801030;
    }
    // 0x80801024: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80801028: jr          $ra
    // 0x8080102C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8080102C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801030:
    // 0x80801030: jr          $ra
    // 0x80801034: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80801034: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void sujiggy_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800200: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800204: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800208: jal         0x808000E8
    // 0x8080020C: nop

    sujiggy_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x8080020C: nop

    after_0:
    // 0x80800210: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800214: jal         0x800DA298
    // 0x80800218: addiu       $a0, $zero, 0x3E9
    ctx->r4 = ADD32(0, 0X3E9);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800218: addiu       $a0, $zero, 0x3E9
    ctx->r4 = ADD32(0, 0X3E9);
    after_1:
    // 0x8080021C: bne         $v0, $zero, L_80800240
    if (ctx->r2 != 0) {
        // 0x80800220: addiu       $a0, $zero, 0xC0D
        ctx->r4 = ADD32(0, 0XC0D);
            goto L_80800240;
    }
    // 0x80800220: addiu       $a0, $zero, 0xC0D
    ctx->r4 = ADD32(0, 0XC0D);
    // 0x80800224: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800228: jal         0x800DA7A8
    // 0x8080022C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_800DA7A8(rdram, ctx);
        goto after_2;
    // 0x8080022C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_2:
    // 0x80800230: addiu       $a0, $zero, 0xD57
    ctx->r4 = ADD32(0, 0XD57);
    // 0x80800234: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800238: jal         0x800DA7A8
    // 0x8080023C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800DA7A8(rdram, ctx);
        goto after_3;
    // 0x8080023C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
L_80800240:
    // 0x80800240: jal         0x800DA524
    // 0x80800244: addiu       $a0, $zero, 0xD4D
    ctx->r4 = ADD32(0, 0XD4D);
    func_800DA524(rdram, ctx);
        goto after_4;
    // 0x80800244: addiu       $a0, $zero, 0xD4D
    ctx->r4 = ADD32(0, 0XD4D);
    after_4:
    // 0x80800248: jal         0x800DA544
    // 0x8080024C: addiu       $a0, $zero, 0xD4E
    ctx->r4 = ADD32(0, 0XD4E);
    func_800DA544(rdram, ctx);
        goto after_5;
    // 0x8080024C: addiu       $a0, $zero, 0xD4E
    ctx->r4 = ADD32(0, 0XD4E);
    after_5:
    // 0x80800250: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80800254: slti        $at, $t6, 0xA
    ctx->r1 = SIGNED(ctx->r14) < 0XA ? 1 : 0;
    // 0x80800258: bne         $at, $zero, L_8080027C
    if (ctx->r1 != 0) {
        // 0x8080025C: nop
    
            goto L_8080027C;
    }
    // 0x8080025C: nop

    // 0x80800260: jal         0x800DA298
    // 0x80800264: addiu       $a0, $zero, 0x589
    ctx->r4 = ADD32(0, 0X589);
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x80800264: addiu       $a0, $zero, 0x589
    ctx->r4 = ADD32(0, 0X589);
    after_6:
    // 0x80800268: addiu       $a0, $zero, 0xD49
    ctx->r4 = ADD32(0, 0XD49);
    // 0x8080026C: jal         0x800DA3B8
    // 0x80800270: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800DA3B8(rdram, ctx);
        goto after_7;
    // 0x80800270: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x80800274: b           L_80800290
    // 0x80800278: nop

        goto L_80800290;
    // 0x80800278: nop

L_8080027C:
    // 0x8080027C: jal         0x800DA298
    // 0x80800280: addiu       $a0, $zero, 0x3E9
    ctx->r4 = ADD32(0, 0X3E9);
    func_800DA298(rdram, ctx);
        goto after_8;
    // 0x80800280: addiu       $a0, $zero, 0x3E9
    ctx->r4 = ADD32(0, 0X3E9);
    after_8:
    // 0x80800284: addiu       $a0, $zero, 0xD49
    ctx->r4 = ADD32(0, 0XD49);
    // 0x80800288: jal         0x800DA3B8
    // 0x8080028C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800DA3B8(rdram, ctx);
        goto after_9;
    // 0x8080028C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_9:
L_80800290:
    // 0x80800290: jal         0x800DA298
    // 0x80800294: addiu       $a0, $zero, 0x57B
    ctx->r4 = ADD32(0, 0X57B);
    func_800DA298(rdram, ctx);
        goto after_10;
    // 0x80800294: addiu       $a0, $zero, 0x57B
    ctx->r4 = ADD32(0, 0X57B);
    after_10:
    // 0x80800298: addiu       $a0, $zero, 0xD74
    ctx->r4 = ADD32(0, 0XD74);
    // 0x8080029C: jal         0x800DA3B8
    // 0x808002A0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800DA3B8(rdram, ctx);
        goto after_11;
    // 0x808002A0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_11:
    // 0x808002A4: addiu       $a0, $zero, 0xD50
    ctx->r4 = ADD32(0, 0XD50);
    // 0x808002A8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808002AC: jal         0x800DA7A8
    // 0x808002B0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800DA7A8(rdram, ctx);
        goto after_12;
    // 0x808002B0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_12:
    // 0x808002B4: jal         0x800DA524
    // 0x808002B8: addiu       $a0, $zero, 0xD73
    ctx->r4 = ADD32(0, 0XD73);
    func_800DA524(rdram, ctx);
        goto after_13;
    // 0x808002B8: addiu       $a0, $zero, 0xD73
    ctx->r4 = ADD32(0, 0XD73);
    after_13:
    // 0x808002BC: jal         0x800FE844
    // 0x808002C0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800FE844(rdram, ctx);
        goto after_14;
    // 0x808002C0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_14:
    // 0x808002C4: jal         0x800FE734
    // 0x808002C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800FE734(rdram, ctx);
        goto after_15;
    // 0x808002C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_15:
    // 0x808002CC: jal         0x800FC6B0
    // 0x808002D0: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    func_800FC6B0(rdram, ctx);
        goto after_16;
    // 0x808002D0: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    after_16:
    // 0x808002D4: jal         0x800A9B84
    // 0x808002D8: nop

    func_800A9B84(rdram, ctx);
        goto after_17;
    // 0x808002D8: nop

    after_17:
    // 0x808002DC: addiu       $a0, $zero, 0x151
    ctx->r4 = ADD32(0, 0X151);
    // 0x808002E0: jal         0x800A9B8C
    // 0x808002E4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800A9B8C(rdram, ctx);
        goto after_18;
    // 0x808002E4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_18:
    // 0x808002E8: jal         0x80800178
    // 0x808002EC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    sujiggy_entrypoint_4(rdram, ctx);
        goto after_19;
    // 0x808002EC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_19:
    // 0x808002F0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808002F4: jal         0x808001AC
    // 0x808002F8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    sujiggy_entrypoint_5(rdram, ctx);
        goto after_20;
    // 0x808002F8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_20:
    // 0x808002FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800300: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800304: jal         0x800A9BA0
    // 0x80800308: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800A9BA0(rdram, ctx);
        goto after_21;
    // 0x80800308: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_21:
    // 0x8080030C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800310: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800314: jr          $ra
    // 0x80800318: nop

    return;
    // 0x80800318: nop

;}
RECOMP_FUNC void bamovespline_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002EC: jr          $ra
    // 0x808002F0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x808002F0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800F5578(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5578: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F557C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F5580: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5584: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5588: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F558C: jal         0x800A1718
    // 0x800F5590: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_800A1718(rdram, ctx);
        goto after_0;
    // 0x800F5590: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F5594: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5598: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F559C: jr          $ra
    // 0x800F55A0: nop

    return;
    // 0x800F55A0: nop

;}
