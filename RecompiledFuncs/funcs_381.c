#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void chclinker_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012DC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2208, 0X1598) << 16);
    // 0x808012E0: jr          $ra
    // 0x808012E4: addiu       $v0, $v0, 0x1598
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2208, 0X1598));
    return;
    // 0x808012E4: addiu       $v0, $v0, 0x1598
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2208, 0X1598));
    // 0x808012E8: nop

    // 0x808012EC: nop

;}
RECOMP_FUNC void _bsjump_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800832B0: syscall     52
    recomp_syscall_handler(rdram, ctx, 0x800832B0);
    return;
    // 0x800832B4: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void sumumbofx_entrypoint_26(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013B4: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x808013B8: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x808013BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808013C0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808013C4: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808013C8: jr          $ra
    // 0x808013CC: sub.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f8.fl;
    return;
    // 0x808013CC: sub.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f8.fl;
;}
RECOMP_FUNC void _bsbtrot_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082C60: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082C60);
    return;
    // 0x80082C64: addi        $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
;}
RECOMP_FUNC void _chfairgroundworker_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085C70: syscall     215
    recomp_syscall_handler(rdram, ctx, 0x80085C70);
    return;
    // 0x80085C74: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80103D98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103D98: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80103D9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80103DA0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80103DA4: jal         0x800AE0E8
    // 0x80103DA8: lh          $a0, 0x10($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X10);
    func_800AE0E8(rdram, ctx);
        goto after_0;
    // 0x80103DA8: lh          $a0, 0x10($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X10);
    after_0:
    // 0x80103DAC: bne         $v0, $zero, L_80103DBC
    if (ctx->r2 != 0) {
        // 0x80103DB0: nop
    
            goto L_80103DBC;
    }
    // 0x80103DB0: nop

    // 0x80103DB4: b           L_80103DEC
    // 0x80103DB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80103DEC;
    // 0x80103DB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80103DBC:
    // 0x80103DBC: jal         0x801039A4
    // 0x80103DC0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_801039A4(rdram, ctx);
        goto after_1;
    // 0x80103DC0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80103DC4: bne         $v0, $zero, L_80103DD4
    if (ctx->r2 != 0) {
        // 0x80103DC8: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80103DD4;
    }
    // 0x80103DC8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80103DCC: b           L_80103DEC
    // 0x80103DD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80103DEC;
    // 0x80103DD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80103DD4:
    // 0x80103DD4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80103DD8: lhu         $a0, 0x14($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X14);
    // 0x80103DDC: jal         0x800D62E4
    // 0x80103DE0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800D62E4(rdram, ctx);
        goto after_2;
    // 0x80103DE0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_2:
    // 0x80103DE4: jal         0x800B2824
    // 0x80103DE8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800B2824(rdram, ctx);
        goto after_3;
    // 0x80103DE8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
L_80103DEC:
    // 0x80103DEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80103DF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80103DF4: jr          $ra
    // 0x80103DF8: nop

    return;
    // 0x80103DF8: nop

;}
RECOMP_FUNC void _bsdie_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082F80: syscall     37
    recomp_syscall_handler(rdram, ctx, 0x80082F80);
    return;
    // 0x80082F84: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chpowerhut_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001C0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808001C4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808001C8: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x808001CC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808001D0: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x808001D4: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x808001D8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808001DC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808001E0: jal         0x80100094
    // 0x808001E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808001E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808001E8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808001EC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808001F0: jal         0x80100094
    // 0x808001F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808001F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808001F8: beq         $v0, $zero, L_80800214
    if (ctx->r2 == 0) {
        // 0x808001FC: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_80800214;
    }
    // 0x808001FC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800200: jal         0x80100094
    // 0x80800204: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80800204: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800208: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080020C: jal         0x80089880
    // 0x80800210: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _sumumbofx_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x80800210: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
L_80800214:
    // 0x80800214: lh          $t6, 0xC($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XC);
    // 0x80800218: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080021C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800220: bnel        $t6, $at, L_80800294
    if (ctx->r14 != ctx->r1) {
        // 0x80800224: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800294;
    }
    goto skip_0;
    // 0x80800224: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80800228: jal         0x800DC128
    // 0x8080022C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800DC128(rdram, ctx);
        goto after_4;
    // 0x8080022C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_4:
    // 0x80800230: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800234: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800238: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
L_8080023C:
    // 0x8080023C: bne         $s3, $s1, L_8080024C
    if (ctx->r19 != ctx->r17) {
        // 0x80800240: addiu       $s0, $s1, 0x1
        ctx->r16 = ADD32(ctx->r17, 0X1);
            goto L_8080024C;
    }
    // 0x80800240: addiu       $s0, $s1, 0x1
    ctx->r16 = ADD32(ctx->r17, 0X1);
    // 0x80800244: b           L_80800250
    // 0x80800248: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80800250;
    // 0x80800248: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8080024C:
    // 0x8080024C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80800250:
    // 0x80800250: jal         0x800DF744
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800DF744(rdram, ctx);
        goto after_5;
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800258: bne         $s0, $s2, L_8080023C
    if (ctx->r16 != ctx->r18) {
        // 0x8080025C: or          $s1, $s0, $zero
        ctx->r17 = ctx->r16 | 0;
            goto L_8080023C;
    }
    // 0x8080025C: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x80800260: jal         0x800DF830
    // 0x80800264: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800DF830(rdram, ctx);
        goto after_6;
    // 0x80800264: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_6:
    // 0x80800268: jal         0x800D674C
    // 0x8080026C: addiu       $a0, $zero, 0x742
    ctx->r4 = ADD32(0, 0X742);
    func_800D674C(rdram, ctx);
        goto after_7;
    // 0x8080026C: addiu       $a0, $zero, 0x742
    ctx->r4 = ADD32(0, 0X742);
    after_7:
    // 0x80800270: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800274: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1076, 0X988) << 16);
    // 0x80800278: addiu       $a1, $a1, 0x988
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1076, 0X988));
    // 0x8080027C: lui         $a2, 0x4020
    ctx->r6 = S32(0X4020 << 16);
    // 0x80800280: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800284: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80800288: jal         0x800DE448
    // 0x8080028C: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800DE448(rdram, ctx);
        goto after_8;
    // 0x8080028C: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_8:
    // 0x80800290: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800294:
    // 0x80800294: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800298: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8080029C: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x808002A0: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x808002A4: jr          $ra
    // 0x808002A8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808002A8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80800000_gcdialogcamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: slti        $at, $a0, 0x32
    ctx->r1 = SIGNED(ctx->r4) < 0X32 ? 1 : 0;
    // 0x80800004: beq         $at, $zero, L_80800014
    if (ctx->r1 == 0) {
        // 0x80800008: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80800014;
    }
    // 0x80800008: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8080000C: b           L_80800030
    // 0x80800010: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80800030;
    // 0x80800010: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80800014:
    // 0x80800014: slti        $at, $a0, 0x64
    ctx->r1 = SIGNED(ctx->r4) < 0X64 ? 1 : 0;
    // 0x80800018: bne         $at, $zero, L_8080002C
    if (ctx->r1 != 0) {
        // 0x8080001C: addiu       $v0, $a0, -0x32
        ctx->r2 = ADD32(ctx->r4, -0X32);
            goto L_8080002C;
    }
    // 0x8080001C: addiu       $v0, $a0, -0x32
    ctx->r2 = ADD32(ctx->r4, -0X32);
    // 0x80800020: addiu       $v0, $a0, -0x64
    ctx->r2 = ADD32(ctx->r4, -0X64);
    // 0x80800024: b           L_80800030
    // 0x80800028: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80800030;
    // 0x80800028: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8080002C:
    // 0x8080002C: addiu       $v1, $zero, 0x32
    ctx->r3 = ADD32(0, 0X32);
L_80800030:
    // 0x80800030: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // 0x80800034: jr          $ra
    // 0x80800038: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    return;
    // 0x80800038: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
;}
RECOMP_FUNC void bssplitup_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080028C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800290: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800294: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800298: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080029C: jal         0x800A3410
    // 0x808002A0: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_800A3410(rdram, ctx);
        goto after_0;
    // 0x808002A0: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_0:
    // 0x808002A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808002AC: jal         0x800A38F0
    // 0x808002B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800A38F0(rdram, ctx);
        goto after_1;
    // 0x808002B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x808002B4: jal         0x80092778
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80092778(rdram, ctx);
        goto after_2;
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808002BC: jal         0x8009F258
    // 0x808002C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_func_8009F258(rdram, ctx);
        goto after_3;
    // 0x808002C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808002C4: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
    // 0x808002C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002CC: jal         0x8080012C
    // 0x808002D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8080012C_bssplitup(rdram, ctx);
        goto after_4;
    // 0x808002D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x808002D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002E0: jr          $ra
    // 0x808002E4: nop

    return;
    // 0x808002E4: nop

;}
RECOMP_FUNC void bssnowball_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008DC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808008E0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(356, 0X1084) << 16);
    // 0x808008E4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808008E8: jr          $ra
    // 0x808008EC: lw          $v0, 0x1084($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(356, 0X1084));
    return;
    // 0x808008EC: lw          $v0, 0x1084($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(356, 0X1084));
;}
RECOMP_FUNC void func_800F52B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F52B8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F52BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F52C0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F52C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F52C8: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F52CC: jal         0x8008EF3C
    // 0x800F52D0: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_8008EF3C(rdram, ctx);
        goto after_0;
    // 0x800F52D0: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F52D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F52D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F52DC: jr          $ra
    // 0x800F52E0: nop

    return;
    // 0x800F52E0: nop

;}
RECOMP_FUNC void func_80800358_chbadjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800358: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080035C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800360: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800364: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800368: jal         0x80100094
    // 0x8080036C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080036C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800370: jal         0x800D395C
    // 0x80800374: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800D395C(rdram, ctx);
        goto after_1;
    // 0x80800374: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800378: beq         $v0, $zero, L_80800390
    if (ctx->r2 == 0) {
        // 0x8080037C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800390;
    }
    // 0x8080037C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800380: jal         0x800FFAB0
    // 0x80800384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x80800384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800388: b           L_808003DC
    // 0x8080038C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808003DC;
    // 0x8080038C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800390:
    // 0x80800390: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80800394: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800398: jal         0x80089F70
    // 0x8080039C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _subaddierouteDll_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x8080039C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x808003A0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808003A4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808003A8: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x808003AC: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x808003B0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808003B4: jal         0x800EE7F8
    // 0x808003B8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x808003B8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_4:
    // 0x808003BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808003C0: jal         0x800DC128
    // 0x808003C4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_800DC128(rdram, ctx);
        goto after_5;
    // 0x808003C4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_5:
    // 0x808003C8: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x808003CC: jal         0x80800278
    // 0x808003D0: sb          $v0, 0x24($t6)
    MEM_B(0X24, ctx->r14) = ctx->r2;
    func_80800278_chbadjinjo(rdram, ctx);
        goto after_6;
    // 0x808003D0: sb          $v0, 0x24($t6)
    MEM_B(0X24, ctx->r14) = ctx->r2;
    after_6:
    // 0x808003D4: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    // 0x808003D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808003DC:
    // 0x808003DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808003E4: jr          $ra
    // 0x808003E8: nop

    return;
    // 0x808003E8: nop

;}
RECOMP_FUNC void func_808002B8_chfactorytoxicpools(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002C0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808002C4: jal         0x80100094
    // 0x808002C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808002C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808002CC: addiu       $a0, $zero, 0x166
    ctx->r4 = ADD32(0, 0X166);
    // 0x808002D0: jal         0x800DA298
    // 0x808002D4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x808002D4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808002D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808002DC: addiu       $a1, $zero, 0x166
    ctx->r5 = ADD32(0, 0X166);
    // 0x808002E0: jal         0x80085840
    // 0x808002E4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    _chswitch_entrypoint_14(rdram, ctx);
        goto after_2;
    // 0x808002E4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_2:
    // 0x808002E8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808002EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808002F0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808002F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808002F8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x808002FC: beq         $a2, $zero, L_8080030C
    if (ctx->r6 == 0) {
        // 0x80800300: swc1        $f4, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
            goto L_8080030C;
    }
    // 0x80800300: swc1        $f4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
    // 0x80800304: b           L_80800310
    // 0x80800308: sh          $t6, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r14;
        goto L_80800310;
    // 0x80800308: sh          $t6, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r14;
L_8080030C:
    // 0x8080030C: sh          $zero, 0x2($v1)
    MEM_H(0X2, ctx->r3) = 0;
L_80800310:
    // 0x80800310: beq         $a2, $zero, L_80800320
    if (ctx->r6 == 0) {
        // 0x80800314: nop
    
            goto L_80800320;
    }
    // 0x80800314: nop

    // 0x80800318: jal         0x8010A570
    // 0x8080031C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8010A570(rdram, ctx);
        goto after_3;
    // 0x8080031C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
L_80800320:
    // 0x80800320: jal         0x80105010
    // 0x80800324: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80105010(rdram, ctx);
        goto after_4;
    // 0x80800324: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80800328: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080032C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800330: jr          $ra
    // 0x80800334: nop

    return;
    // 0x80800334: nop

;}
RECOMP_FUNC void func_80800000_chstadiumdoors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: lhu         $v0, 0x76($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X76);
    // 0x8080000C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800010: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x80800014: srl         $t6, $v0, 7
    ctx->r14 = S32(U32(ctx->r2) >> 7);
    // 0x80800018: beq         $t6, $at, L_80800040
    if (ctx->r14 == ctx->r1) {
        // 0x8080001C: addiu       $a0, $zero, 0x576
        ctx->r4 = ADD32(0, 0X576);
            goto L_80800040;
    }
    // 0x8080001C: addiu       $a0, $zero, 0x576
    ctx->r4 = ADD32(0, 0X576);
    // 0x80800020: addiu       $at, $zero, 0x34
    ctx->r1 = ADD32(0, 0X34);
    // 0x80800024: beq         $t6, $at, L_8080007C
    if (ctx->r14 == ctx->r1) {
        // 0x80800028: addiu       $a0, $zero, 0x5E
        ctx->r4 = ADD32(0, 0X5E);
            goto L_8080007C;
    }
    // 0x80800028: addiu       $a0, $zero, 0x5E
    ctx->r4 = ADD32(0, 0X5E);
    // 0x8080002C: addiu       $at, $zero, 0x35
    ctx->r1 = ADD32(0, 0X35);
    // 0x80800030: beq         $t6, $at, L_808000B8
    if (ctx->r14 == ctx->r1) {
        // 0x80800034: addiu       $a0, $zero, 0x5F
        ctx->r4 = ADD32(0, 0X5F);
            goto L_808000B8;
    }
    // 0x80800034: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    // 0x80800038: b           L_808000F0
    // 0x8080003C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808000F0;
    // 0x8080003C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800040:
    // 0x80800040: jal         0x800DA298
    // 0x80800044: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800044: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800048: beq         $v0, $zero, L_808000EC
    if (ctx->r2 == 0) {
        // 0x8080004C: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_808000EC;
    }
    // 0x8080004C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800050: lbu         $t7, 0x72($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X72);
    // 0x80800054: lui         $at, 0xC2AA
    ctx->r1 = S32(0XC2AA << 16);
    // 0x80800058: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080005C: andi        $t8, $t7, 0xFF03
    ctx->r24 = ctx->r15 & 0XFF03;
    // 0x80800060: ori         $t9, $t8, 0xC
    ctx->r25 = ctx->r24 | 0XC;
    // 0x80800064: sb          $t9, 0x72($a1)
    MEM_B(0X72, ctx->r5) = ctx->r25;
    // 0x80800068: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    // 0x8080006C: jal         0x80088178
    // 0x80800070: swc1        $f4, 0x48($a1)
    MEM_W(0X48, ctx->r5) = ctx->f4.u32l;
    _gcfrontend_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80800070: swc1        $f4, 0x48($a1)
    MEM_W(0X48, ctx->r5) = ctx->f4.u32l;
    after_1:
    // 0x80800074: b           L_808000F0
    // 0x80800078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808000F0;
    // 0x80800078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080007C:
    // 0x8080007C: jal         0x800DA298
    // 0x80800080: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800080: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_2:
    // 0x80800084: beq         $v0, $zero, L_808000EC
    if (ctx->r2 == 0) {
        // 0x80800088: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_808000EC;
    }
    // 0x80800088: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8080008C: lbu         $t0, 0x72($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X72);
    // 0x80800090: lui         $at, 0xC2AA
    ctx->r1 = S32(0XC2AA << 16);
    // 0x80800094: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800098: andi        $t1, $t0, 0xFF03
    ctx->r9 = ctx->r8 & 0XFF03;
    // 0x8080009C: ori         $t2, $t1, 0xC
    ctx->r10 = ctx->r9 | 0XC;
    // 0x808000A0: sb          $t2, 0x72($a1)
    MEM_B(0X72, ctx->r5) = ctx->r10;
    // 0x808000A4: addiu       $a0, $zero, 0x61
    ctx->r4 = ADD32(0, 0X61);
    // 0x808000A8: jal         0x80088178
    // 0x808000AC: swc1        $f6, 0x48($a1)
    MEM_W(0X48, ctx->r5) = ctx->f6.u32l;
    _gcfrontend_entrypoint_9(rdram, ctx);
        goto after_3;
    // 0x808000AC: swc1        $f6, 0x48($a1)
    MEM_W(0X48, ctx->r5) = ctx->f6.u32l;
    after_3:
    // 0x808000B0: b           L_808000F0
    // 0x808000B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808000F0;
    // 0x808000B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000B8:
    // 0x808000B8: jal         0x800DA298
    // 0x808000BC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x808000BC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_4:
    // 0x808000C0: beq         $v0, $zero, L_808000EC
    if (ctx->r2 == 0) {
        // 0x808000C4: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_808000EC;
    }
    // 0x808000C4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x808000C8: lbu         $t3, 0x72($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X72);
    // 0x808000CC: lui         $at, 0xC2AA
    ctx->r1 = S32(0XC2AA << 16);
    // 0x808000D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808000D4: andi        $t4, $t3, 0xFF03
    ctx->r12 = ctx->r11 & 0XFF03;
    // 0x808000D8: ori         $t5, $t4, 0xC
    ctx->r13 = ctx->r12 | 0XC;
    // 0x808000DC: sb          $t5, 0x72($a1)
    MEM_B(0X72, ctx->r5) = ctx->r13;
    // 0x808000E0: addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    // 0x808000E4: jal         0x80088178
    // 0x808000E8: swc1        $f8, 0x48($a1)
    MEM_W(0X48, ctx->r5) = ctx->f8.u32l;
    _gcfrontend_entrypoint_9(rdram, ctx);
        goto after_5;
    // 0x808000E8: swc1        $f8, 0x48($a1)
    MEM_W(0X48, ctx->r5) = ctx->f8.u32l;
    after_5:
L_808000EC:
    // 0x808000EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000F0:
    // 0x808000F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000F4: jr          $ra
    // 0x808000F8: nop

    return;
    // 0x808000F8: nop

;}
RECOMP_FUNC void func_800F5BF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5BF0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5BF4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5BF8: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5BFC: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F5C00: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800F5C04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5C08: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800F5C0C: jal         0x80092B8C
    // 0x800F5C10: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_80092B8C(rdram, ctx);
        goto after_0;
    // 0x800F5C10: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F5C14: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F5C18: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x800F5C1C: jal         0x8009C128
    // 0x800F5C20: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_8009C128(rdram, ctx);
        goto after_1;
    // 0x800F5C20: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_1:
    // 0x800F5C24: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800F5C28: jal         0x800EF04C
    // 0x800F5C2C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_800EF04C(rdram, ctx);
        goto after_2;
    // 0x800F5C2C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_2:
    // 0x800F5C30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5C34: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800F5C38: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800F5C3C: jr          $ra
    // 0x800F5C40: nop

    return;
    // 0x800F5C40: nop

;}
RECOMP_FUNC void func_80800474_chstonepillar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800474: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800478: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080047C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800480: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800484: jal         0x80100094
    // 0x80800488: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800488: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080048C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800490: jal         0x8080112C
    // 0x80800494: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_8080112C_chstonepillar(rdram, ctx);
        goto after_1;
    // 0x80800494: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x80800498: beq         $v0, $zero, L_808004B0
    if (ctx->r2 == 0) {
        // 0x8080049C: nop
    
            goto L_808004B0;
    }
    // 0x8080049C: nop

    // 0x808004A0: jal         0x800DA298
    // 0x808004A4: addiu       $a0, $zero, 0x9D5
    ctx->r4 = ADD32(0, 0X9D5);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x808004A4: addiu       $a0, $zero, 0x9D5
    ctx->r4 = ADD32(0, 0X9D5);
    after_2:
    // 0x808004A8: bne         $v0, $zero, L_808004B8
    if (ctx->r2 != 0) {
        // 0x808004AC: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_808004B8;
    }
    // 0x808004AC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
L_808004B0:
    // 0x808004B0: b           L_8080050C
    // 0x808004B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080050C;
    // 0x808004B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808004B8:
    // 0x808004B8: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x808004BC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808004C0: jal         0x800EFB8C
    // 0x808004C4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EFB8C(rdram, ctx);
        goto after_3;
    // 0x808004C4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_3:
    // 0x808004C8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808004CC: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x808004D0: jal         0x80102D78
    // 0x808004D4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80102D78(rdram, ctx);
        goto after_4;
    // 0x808004D4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_4:
    // 0x808004D8: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    // 0x808004DC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(880, 0X13D0) << 16);
    // 0x808004E0: lwc1        $f4, 0x13D0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(880, 0X13D0));
    // 0x808004E4: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808004E8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808004EC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808004F0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808004F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(880, 0X13D4) << 16);
    // 0x808004F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808004FC: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800500: swc1        $f16, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f16.u32l;
    // 0x80800504: lwc1        $f18, 0x13D4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(880, 0X13D4));
    // 0x80800508: swc1        $f18, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f18.u32l;
L_8080050C:
    // 0x8080050C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800510: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800514: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800518: jr          $ra
    // 0x8080051C: nop

    return;
    // 0x8080051C: nop

;}
RECOMP_FUNC void func_8008D544(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D544: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008D548: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008D54C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008D550: jal         0x800C6E38
    // 0x8008D554: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800C6E38(rdram, ctx);
        goto after_0;
    // 0x8008D554: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x8008D558: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008D55C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008D560: jr          $ra
    // 0x8008D564: nop

    return;
    // 0x8008D564: nop

;}
RECOMP_FUNC void func_808003A0_chappearfx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003A0: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x808003A4: sw          $s7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r23;
    // 0x808003A8: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x808003AC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x808003B0: sw          $s6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r22;
    // 0x808003B4: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x808003B8: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x808003BC: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x808003C0: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x808003C4: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x808003C8: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x808003CC: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x808003D0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808003D4: jal         0x80100094
    // 0x808003D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808003D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808003DC: lbu         $t7, 0x7E($s6)
    ctx->r15 = MEM_BU(ctx->r22, 0X7E);
    // 0x808003E0: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x808003E4: addiu       $s0, $v0, 0x1C
    ctx->r16 = ADD32(ctx->r2, 0X1C);
    // 0x808003E8: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x808003EC: sb          $t8, 0x7E($s6)
    MEM_B(0X7E, ctx->r22) = ctx->r24;
    // 0x808003F0: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x808003F4: beql        $t9, $zero, L_80800528
    if (ctx->r25 == 0) {
        // 0x808003F8: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_80800528;
    }
    goto skip_0;
    // 0x808003F8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x808003FC: lh          $t0, 0xE($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XE);
    // 0x80800400: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1188, 0X970) << 16);
    // 0x80800404: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80800408: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x8080040C: jal         0x800D674C
    // 0x80800410: lw          $a0, 0x970($a0)
    ctx->r4 = MEM_W(ctx->r4, (int16_t)RELOC_LO16(1188, 0X970));
    func_800D674C(rdram, ctx);
        goto after_1;
    // 0x80800410: lw          $a0, 0x970($a0)
    ctx->r4 = MEM_W(ctx->r4, (int16_t)RELOC_LO16(1188, 0X970));
    after_1:
    // 0x80800414: lhu         $t2, 0x4($s3)
    ctx->r10 = MEM_HU(ctx->r19, 0X4);
    // 0x80800418: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8080041C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800420: andi        $t3, $t2, 0x10
    ctx->r11 = ctx->r10 & 0X10;
    // 0x80800424: beq         $t3, $zero, L_80800434
    if (ctx->r11 == 0) {
        // 0x80800428: nop
    
            goto L_80800434;
    }
    // 0x80800428: nop

    // 0x8080042C: b           L_80800434
    // 0x80800430: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80800434;
    // 0x80800430: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80800434:
    // 0x80800434: jal         0x800E2588
    // 0x80800438: nop

    func_800E2588(rdram, ctx);
        goto after_2;
    // 0x80800438: nop

    after_2:
    // 0x8080043C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80800440: jal         0x800E2594
    // 0x80800444: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800E2594(rdram, ctx);
        goto after_3;
    // 0x80800444: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80800448: jal         0x800E24D8
    // 0x8080044C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800E24D8(rdram, ctx);
        goto after_4;
    // 0x8080044C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x80800450: lh          $t4, 0x0($s3)
    ctx->r12 = MEM_H(ctx->r19, 0X0);
    // 0x80800454: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800458: addiu       $s5, $s6, 0x4
    ctx->r21 = ADD32(ctx->r22, 0X4);
    // 0x8080045C: blez        $t4, L_8080051C
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80800460: addiu       $s4, $sp, 0x58
        ctx->r20 = ADD32(ctx->r29, 0X58);
            goto L_8080051C;
    }
    // 0x80800460: addiu       $s4, $sp, 0x58
    ctx->r20 = ADD32(ctx->r29, 0X58);
    // 0x80800464: addiu       $s2, $sp, 0x64
    ctx->r18 = ADD32(ctx->r29, 0X64);
    // 0x80800468: lwc1        $f4, 0x38($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X38);
L_8080046C:
    // 0x8080046C: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80800470: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800474: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80800478: mul.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8080047C: jal         0x800EE7F8
    // 0x80800480: nop

    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x80800480: nop

    after_5:
    // 0x80800484: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
    // 0x80800488: lh          $t6, 0x6($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X6);
    // 0x8080048C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800490: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80800494: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80800498: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8080049C: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808004A0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x808004A4: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x808004A8: jal         0x800EF1B8
    // 0x808004AC: nop

    func_800EF1B8(rdram, ctx);
        goto after_6;
    // 0x808004AC: nop

    after_6:
    // 0x808004B0: lh          $t7, 0x8($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X8);
    // 0x808004B4: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x808004B8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808004BC: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x808004C0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x808004C4: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x808004C8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x808004CC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808004D0: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x808004D4: jal         0x800EFA4C
    // 0x808004D8: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    func_800EFA4C(rdram, ctx);
        goto after_7;
    // 0x808004D8: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    after_7:
    // 0x808004DC: jal         0x800E2530
    // 0x808004E0: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    func_800E2530(rdram, ctx);
        goto after_8;
    // 0x808004E0: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    after_8:
    // 0x808004E4: lh          $a2, 0x4($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X4);
    // 0x808004E8: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x808004EC: lbu         $t8, 0xC($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0XC);
    // 0x808004F0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x808004F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808004F8: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x808004FC: jal         0x800E2720
    // 0x80800500: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    func_800E2720(rdram, ctx);
        goto after_9;
    // 0x80800500: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_9:
    // 0x80800504: lh          $t9, 0x0($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X0);
    // 0x80800508: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8080050C: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x80800510: slt         $at, $s1, $t9
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80800514: bnel        $at, $zero, L_8080046C
    if (ctx->r1 != 0) {
        // 0x80800518: lwc1        $f4, 0x38($s6)
        ctx->f4.u32l = MEM_W(ctx->r22, 0X38);
            goto L_8080046C;
    }
    goto skip_1;
    // 0x80800518: lwc1        $f4, 0x38($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X38);
    skip_1:
L_8080051C:
    // 0x8080051C: jal         0x800E2A14
    // 0x80800520: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_800E2A14(rdram, ctx);
        goto after_10;
    // 0x80800520: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_10:
    // 0x80800524: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80800528:
    // 0x80800528: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8080052C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80800530: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80800534: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80800538: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x8080053C: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x80800540: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x80800544: lw          $s6, 0x3C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X3C);
    // 0x80800548: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x8080054C: jr          $ra
    // 0x80800550: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80800550: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_800E04C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E04C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800E04C4: sw          $s0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r16;
    // 0x800E04C8: sw          $s1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r17;
    // 0x800E04CC: sw          $s2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r18;
    // 0x800E04D0: sw          $s3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r19;
    // 0x800E04D4: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x800E04D8: sw          $s5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r21;
    // 0x800E04DC: sw          $s6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r22;
    // 0x800E04E0: sw          $s7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r23;
    // 0x800E04E4: sw          $fp, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r30;
    // 0x800E04E8: lh          $t2, 0x2($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X2);
    // 0x800E04EC: addiu       $s4, $a0, 0x4
    ctx->r20 = ADD32(ctx->r4, 0X4);
    // 0x800E04F0: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x800E04F4: bnel        $t2, $zero, L_800E0524
    if (ctx->r10 != 0) {
        // 0x800E04F8: mtc1        $a1, $f12
        ctx->f12.u32l = ctx->r5;
            goto L_800E0524;
    }
    goto skip_0;
    // 0x800E04F8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    skip_0:
    // 0x800E04FC: lh          $t3, 0x2($s4)
    ctx->r11 = MEM_H(ctx->r20, 0X2);
    // 0x800E0500: lui         $at, 0x3C80
    ctx->r1 = S32(0X3C80 << 16);
    // 0x800E0504: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800E0508: mtc1        $t3, $f0
    ctx->f0.u32l = ctx->r11;
    // 0x800E050C: nop

    // 0x800E0510: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800E0514: mul.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800E0518: b           L_800E0824
    // 0x800E051C: lw          $s0, 0x0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X0);
        goto L_800E0824;
    // 0x800E051C: lw          $s0, 0x0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X0);
    // 0x800E0520: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
L_800E0524:
    // 0x800E0524: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800E0528: lh          $t2, 0x0($s4)
    ctx->r10 = MEM_H(ctx->r20, 0X0);
    // 0x800E052C: trunc.w.s   $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x800E0530: addu        $s5, $s4, $t3
    ctx->r21 = ADD32(ctx->r20, ctx->r11);
    // 0x800E0534: andi        $t2, $t2, 0x3FFF
    ctx->r10 = ctx->r10 & 0X3FFF;
    // 0x800E0538: mfc1        $t0, $f0
    ctx->r8 = (int32_t)ctx->f0.u32l;
    // 0x800E053C: nop

    // 0x800E0540: sltu        $at, $t0, $t2
    ctx->r1 = ctx->r8 < ctx->r10 ? 1 : 0;
    // 0x800E0544: beql        $at, $zero, L_800E0578
    if (ctx->r1 == 0) {
        // 0x800E0548: lh          $t1, 0x0($s5)
        ctx->r9 = MEM_H(ctx->r21, 0X0);
            goto L_800E0578;
    }
    goto skip_1;
    // 0x800E0548: lh          $t1, 0x0($s5)
    ctx->r9 = MEM_H(ctx->r21, 0X0);
    skip_1:
    // 0x800E054C: beq         $a2, $zero, L_800E0568
    if (ctx->r6 == 0) {
        // 0x800E0550: or          $s2, $s4, $zero
        ctx->r18 = ctx->r20 | 0;
            goto L_800E0568;
    }
    // 0x800E0550: or          $s2, $s4, $zero
    ctx->r18 = ctx->r20 | 0;
    // 0x800E0554: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
    // 0x800E0558: lh          $t1, 0x0($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X0);
    // 0x800E055C: andi        $t1, $t1, 0x3FFF
    ctx->r9 = ctx->r9 & 0X3FFF;
    // 0x800E0560: b           L_800E0604
    // 0x800E0564: subu        $t1, $t1, $a2
    ctx->r9 = SUB32(ctx->r9, ctx->r6);
        goto L_800E0604;
    // 0x800E0564: subu        $t1, $t1, $a2
    ctx->r9 = SUB32(ctx->r9, ctx->r6);
L_800E0568:
    // 0x800E0568: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
    // 0x800E056C: b           L_800E0604
    // 0x800E0570: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
        goto L_800E0604;
    // 0x800E0570: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
    // 0x800E0574: lh          $t1, 0x0($s5)
    ctx->r9 = MEM_H(ctx->r21, 0X0);
L_800E0578:
    // 0x800E0578: andi        $t1, $t1, 0x3FFF
    ctx->r9 = ctx->r9 & 0X3FFF;
    // 0x800E057C: sltu        $at, $t0, $t1
    ctx->r1 = ctx->r8 < ctx->r9 ? 1 : 0;
    // 0x800E0580: bnel        $at, $zero, L_800E05B4
    if (ctx->r1 != 0) {
        // 0x800E0584: or          $s1, $s4, $zero
        ctx->r17 = ctx->r20 | 0;
            goto L_800E05B4;
    }
    goto skip_2;
    // 0x800E0584: or          $s1, $s4, $zero
    ctx->r17 = ctx->r20 | 0;
    skip_2:
    // 0x800E0588: beq         $a2, $zero, L_800E05A4
    if (ctx->r6 == 0) {
        // 0x800E058C: or          $s1, $s5, $zero
        ctx->r17 = ctx->r21 | 0;
            goto L_800E05A4;
    }
    // 0x800E058C: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
    // 0x800E0590: or          $s2, $s4, $zero
    ctx->r18 = ctx->r20 | 0;
    // 0x800E0594: lh          $t2, 0x0($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X0);
    // 0x800E0598: andi        $t2, $t2, 0x3FFF
    ctx->r10 = ctx->r10 & 0X3FFF;
    // 0x800E059C: b           L_800E0604
    // 0x800E05A0: addu        $t2, $t2, $a2
    ctx->r10 = ADD32(ctx->r10, ctx->r6);
        goto L_800E0604;
    // 0x800E05A0: addu        $t2, $t2, $a2
    ctx->r10 = ADD32(ctx->r10, ctx->r6);
L_800E05A4:
    // 0x800E05A4: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
    // 0x800E05A8: b           L_800E0604
    // 0x800E05AC: or          $t2, $t1, $zero
    ctx->r10 = ctx->r9 | 0;
        goto L_800E0604;
    // 0x800E05AC: or          $t2, $t1, $zero
    ctx->r10 = ctx->r9 | 0;
    // 0x800E05B0: or          $s1, $s4, $zero
    ctx->r17 = ctx->r20 | 0;
L_800E05B4:
    // 0x800E05B4: b           L_800E05C0
    // 0x800E05B8: or          $s2, $s5, $zero
    ctx->r18 = ctx->r21 | 0;
        goto L_800E05C0;
    // 0x800E05B8: or          $s2, $s5, $zero
    ctx->r18 = ctx->r21 | 0;
    // 0x800E05BC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_800E05C0:
    // 0x800E05C0: subu        $v0, $s2, $s1
    ctx->r2 = SUB32(ctx->r18, ctx->r17);
    // 0x800E05C4: srl         $v0, $v0, 3
    ctx->r2 = S32(U32(ctx->r2) >> 3);
    // 0x800E05C8: beql        $v0, $zero, L_800E05F8
    if (ctx->r2 == 0) {
        // 0x800E05CC: lh          $t1, 0x0($s1)
        ctx->r9 = MEM_H(ctx->r17, 0X0);
            goto L_800E05F8;
    }
    goto skip_3;
    // 0x800E05CC: lh          $t1, 0x0($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X0);
    skip_3:
    // 0x800E05D0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800E05D4: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x800E05D8: lh          $t1, 0x0($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X0);
    // 0x800E05DC: andi        $t1, $t1, 0x3FFF
    ctx->r9 = ctx->r9 & 0X3FFF;
    // 0x800E05E0: sltu        $at, $t0, $t1
    ctx->r1 = ctx->r8 < ctx->r9 ? 1 : 0;
    // 0x800E05E4: beql        $at, $zero, L_800E05C0
    if (ctx->r1 == 0) {
        // 0x800E05E8: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_800E05C0;
    }
    goto skip_4;
    // 0x800E05E8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    skip_4:
    // 0x800E05EC: b           L_800E05C0
    // 0x800E05F0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
        goto L_800E05C0;
    // 0x800E05F0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800E05F4: lh          $t1, 0x0($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X0);
L_800E05F8:
    // 0x800E05F8: lh          $t2, 0x0($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X0);
    // 0x800E05FC: andi        $t1, $t1, 0x3FFF
    ctx->r9 = ctx->r9 & 0X3FFF;
    // 0x800E0600: andi        $t2, $t2, 0x3FFF
    ctx->r10 = ctx->r10 & 0X3FFF;
L_800E0604:
    // 0x800E0604: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800E0608: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800E060C: sltu        $at, $t2, $t0
    ctx->r1 = ctx->r10 < ctx->r8 ? 1 : 0;
    // 0x800E0610: bnel        $at, $zero, L_800E0640
    if (ctx->r1 != 0) {
        // 0x800E0614: lhu         $s6, 0x0($s1)
        ctx->r22 = MEM_HU(ctx->r17, 0X0);
            goto L_800E0640;
    }
    goto skip_5;
    // 0x800E0614: lhu         $s6, 0x0($s1)
    ctx->r22 = MEM_HU(ctx->r17, 0X0);
    skip_5:
    // 0x800E0618: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x800E061C: beql        $t2, $zero, L_800E0640
    if (ctx->r10 == 0) {
        // 0x800E0620: lhu         $s6, 0x0($s1)
        ctx->r22 = MEM_HU(ctx->r17, 0X0);
            goto L_800E0640;
    }
    goto skip_6;
    // 0x800E0620: lhu         $s6, 0x0($s1)
    ctx->r22 = MEM_HU(ctx->r17, 0X0);
    skip_6:
    // 0x800E0624: mtc1        $t1, $f0
    ctx->f0.u32l = ctx->r9;
    // 0x800E0628: mtc1        $t2, $f2
    ctx->f2.u32l = ctx->r10;
    // 0x800E062C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800E0630: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800E0634: sub.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x800E0638: div.s       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800E063C: lhu         $s6, 0x0($s1)
    ctx->r22 = MEM_HU(ctx->r17, 0X0);
L_800E0640:
    // 0x800E0640: lh          $t5, 0x2($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X2);
    // 0x800E0644: lh          $t6, 0x2($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X2);
    // 0x800E0648: andi        $s6, $s6, 0x4000
    ctx->r22 = ctx->r22 & 0X4000;
    // 0x800E064C: beql        $s6, $zero, L_800E067C
    if (ctx->r22 == 0) {
        // 0x800E0650: or          $t4, $t5, $zero
        ctx->r12 = ctx->r13 | 0;
            goto L_800E067C;
    }
    goto skip_7;
    // 0x800E0650: or          $t4, $t5, $zero
    ctx->r12 = ctx->r13 | 0;
    skip_7:
    // 0x800E0654: addiu       $s0, $s1, -0x4
    ctx->r16 = ADD32(ctx->r17, -0X4);
    // 0x800E0658: sltu        $at, $s0, $s4
    ctx->r1 = ctx->r16 < ctx->r20 ? 1 : 0;
    // 0x800E065C: beq         $at, $zero, L_800E0670
    if (ctx->r1 == 0) {
        // 0x800E0660: nop
    
            goto L_800E0670;
    }
    // 0x800E0660: nop

    // 0x800E0664: beq         $a2, $zero, L_800E0670
    if (ctx->r6 == 0) {
        // 0x800E0668: or          $s0, $s4, $zero
        ctx->r16 = ctx->r20 | 0;
            goto L_800E0670;
    }
    // 0x800E0668: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x800E066C: or          $s0, $s5, $zero
    ctx->r16 = ctx->r21 | 0;
L_800E0670:
    // 0x800E0670: b           L_800E067C
    // 0x800E0674: lh          $t4, 0x2($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X2);
        goto L_800E067C;
    // 0x800E0674: lh          $t4, 0x2($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X2);
    // 0x800E0678: or          $t4, $t5, $zero
    ctx->r12 = ctx->r13 | 0;
L_800E067C:
    // 0x800E067C: lhu         $t0, 0x0($s2)
    ctx->r8 = MEM_HU(ctx->r18, 0X0);
    // 0x800E0680: andi        $t0, $t0, 0x8000
    ctx->r8 = ctx->r8 & 0X8000;
    // 0x800E0684: beq         $t0, $zero, L_800E06B0
    if (ctx->r8 == 0) {
        // 0x800E0688: or          $s6, $s6, $t0
        ctx->r22 = ctx->r22 | ctx->r8;
            goto L_800E06B0;
    }
    // 0x800E0688: or          $s6, $s6, $t0
    ctx->r22 = ctx->r22 | ctx->r8;
    // 0x800E068C: addiu       $s3, $s2, 0x4
    ctx->r19 = ADD32(ctx->r18, 0X4);
    // 0x800E0690: sltu        $at, $s5, $s3
    ctx->r1 = ctx->r21 < ctx->r19 ? 1 : 0;
    // 0x800E0694: beq         $at, $zero, L_800E06A8
    if (ctx->r1 == 0) {
        // 0x800E0698: nop
    
            goto L_800E06A8;
    }
    // 0x800E0698: nop

    // 0x800E069C: beq         $a2, $zero, L_800E06A8
    if (ctx->r6 == 0) {
        // 0x800E06A0: or          $s3, $s5, $zero
        ctx->r19 = ctx->r21 | 0;
            goto L_800E06A8;
    }
    // 0x800E06A0: or          $s3, $s5, $zero
    ctx->r19 = ctx->r21 | 0;
    // 0x800E06A4: or          $s3, $s4, $zero
    ctx->r19 = ctx->r20 | 0;
L_800E06A8:
    // 0x800E06A8: b           L_800E06B4
    // 0x800E06AC: lh          $t7, 0x2($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X2);
        goto L_800E06B4;
    // 0x800E06AC: lh          $t7, 0x2($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X2);
L_800E06B0:
    // 0x800E06B0: or          $t7, $t6, $zero
    ctx->r15 = ctx->r14 | 0;
L_800E06B4:
    // 0x800E06B4: lhu         $t0, 0x0($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X0);
    // 0x800E06B8: addiu       $s7, $zero, 0x0
    ctx->r23 = ADD32(0, 0X0);
    // 0x800E06BC: andi        $t0, $t0, 0xF
    ctx->r8 = ctx->r8 & 0XF;
    // 0x800E06C0: addiu       $t0, $t0, -0x9
    ctx->r8 = ADD32(ctx->r8, -0X9);
    // 0x800E06C4: bltz        $t0, L_800E0730
    if (SIGNED(ctx->r8) < 0) {
        // 0x800E06C8: nop
    
            goto L_800E0730;
    }
    // 0x800E06C8: nop

    // 0x800E06CC: sub         $s0, $t5, $t4
    ctx->r16 = SUB32(ctx->r13, ctx->r12);
    // 0x800E06D0: sub         $s1, $t6, $t5
    ctx->r17 = SUB32(ctx->r14, ctx->r13);
    // 0x800E06D4: sub         $s2, $t7, $t6
    ctx->r18 = SUB32(ctx->r15, ctx->r14);
    // 0x800E06D8: ori         $s7, $zero, 0xB400
    ctx->r23 = 0 | 0XB400;
    // 0x800E06DC: addiu       $t0, $s0, 0x5A00
    ctx->r8 = ADD32(ctx->r16, 0X5A00);
    // 0x800E06E0: sltu        $t1, $s7, $t0
    ctx->r9 = ctx->r23 < ctx->r8 ? 1 : 0;
    // 0x800E06E4: beq         $t1, $zero, L_800E06F8
    if (ctx->r9 == 0) {
        // 0x800E06E8: addiu       $t0, $s1, 0x5A00
        ctx->r8 = ADD32(ctx->r17, 0X5A00);
            goto L_800E06F8;
    }
    // 0x800E06E8: addiu       $t0, $s1, 0x5A00
    ctx->r8 = ADD32(ctx->r17, 0X5A00);
    // 0x800E06EC: bltzl       $s0, L_800E06F8
    if (SIGNED(ctx->r16) < 0) {
        // 0x800E06F0: add         $s0, $s0, $s7
        ctx->r16 = ADD32(ctx->r16, ctx->r23);
            goto L_800E06F8;
    }
    goto skip_8;
    // 0x800E06F0: add         $s0, $s0, $s7
    ctx->r16 = ADD32(ctx->r16, ctx->r23);
    skip_8:
    // 0x800E06F4: sub         $s0, $s0, $s7
    ctx->r16 = SUB32(ctx->r16, ctx->r23);
L_800E06F8:
    // 0x800E06F8: sltu        $t1, $s7, $t0
    ctx->r9 = ctx->r23 < ctx->r8 ? 1 : 0;
    // 0x800E06FC: beq         $t1, $zero, L_800E0710
    if (ctx->r9 == 0) {
        // 0x800E0700: addiu       $t0, $s2, 0x5A00
        ctx->r8 = ADD32(ctx->r18, 0X5A00);
            goto L_800E0710;
    }
    // 0x800E0700: addiu       $t0, $s2, 0x5A00
    ctx->r8 = ADD32(ctx->r18, 0X5A00);
    // 0x800E0704: bltzl       $s1, L_800E0710
    if (SIGNED(ctx->r17) < 0) {
        // 0x800E0708: add         $s1, $s1, $s7
        ctx->r17 = ADD32(ctx->r17, ctx->r23);
            goto L_800E0710;
    }
    goto skip_9;
    // 0x800E0708: add         $s1, $s1, $s7
    ctx->r17 = ADD32(ctx->r17, ctx->r23);
    skip_9:
    // 0x800E070C: sub         $s1, $s1, $s7
    ctx->r17 = SUB32(ctx->r17, ctx->r23);
L_800E0710:
    // 0x800E0710: sltu        $t1, $s7, $t0
    ctx->r9 = ctx->r23 < ctx->r8 ? 1 : 0;
    // 0x800E0714: beq         $t1, $zero, L_800E0728
    if (ctx->r9 == 0) {
        // 0x800E0718: add         $t5, $t4, $s0
        ctx->r13 = ADD32(ctx->r12, ctx->r16);
            goto L_800E0728;
    }
    // 0x800E0718: add         $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x800E071C: bltzl       $s2, L_800E0728
    if (SIGNED(ctx->r18) < 0) {
        // 0x800E0720: add         $s2, $s2, $s7
        ctx->r18 = ADD32(ctx->r18, ctx->r23);
            goto L_800E0728;
    }
    goto skip_10;
    // 0x800E0720: add         $s2, $s2, $s7
    ctx->r18 = ADD32(ctx->r18, ctx->r23);
    skip_10:
    // 0x800E0724: sub         $s2, $s2, $s7
    ctx->r18 = SUB32(ctx->r18, ctx->r23);
L_800E0728:
    // 0x800E0728: add         $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x800E072C: add         $t7, $t6, $s2
    ctx->r15 = ADD32(ctx->r14, ctx->r18);
L_800E0730:
    // 0x800E0730: beql        $s6, $zero, L_800E07B4
    if (ctx->r22 == 0) {
        // 0x800E0734: mtc1        $t5, $f4
        ctx->f4.u32l = ctx->r13;
            goto L_800E07B4;
    }
    goto skip_11;
    // 0x800E0734: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    skip_11:
    // 0x800E0738: sub         $t0, $t7, $t4
    ctx->r8 = SUB32(ctx->r15, ctx->r12);
    // 0x800E073C: sub         $t8, $t6, $t5
    ctx->r24 = SUB32(ctx->r14, ctx->r13);
    // 0x800E0740: add         $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x800E0744: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800E0748: sub         $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x800E074C: mtc1        $t0, $f2
    ctx->f2.u32l = ctx->r8;
    // 0x800E0750: sll         $t0, $t4, 1
    ctx->r8 = S32(ctx->r12 << 1);
    // 0x800E0754: add         $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x800E0758: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800E075C: sub         $t0, $t0, $t5
    ctx->r8 = SUB32(ctx->r8, ctx->r13);
    // 0x800E0760: sub         $t0, $t0, $t7
    ctx->r8 = SUB32(ctx->r8, ctx->r15);
    // 0x800E0764: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800E0768: sub         $t0, $t6, $t4
    ctx->r8 = SUB32(ctx->r14, ctx->r12);
    // 0x800E076C: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x800E0770: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800E0774: sll         $t0, $t5, 1
    ctx->r8 = S32(ctx->r13 << 1);
    // 0x800E0778: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x800E077C: lui         $at, 0x3C00
    ctx->r1 = S32(0X3C00 << 16);
    // 0x800E0780: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800E0784: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800E0788: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800E078C: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800E0790: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800E0794: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800E0798: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x800E079C: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800E07A0: add.s       $f0, $f2, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x800E07A4: mul.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800E07A8: b           L_800E07E0
    // 0x800E07AC: nop

        goto L_800E07E0;
    // 0x800E07AC: nop

    // 0x800E07B0: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
L_800E07B4:
    // 0x800E07B4: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800E07B8: lui         $at, 0x3C80
    ctx->r1 = S32(0X3C80 << 16);
    // 0x800E07BC: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800E07C0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800E07C4: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800E07C8: mul.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800E07CC: nop

    // 0x800E07D0: mul.s       $f6, $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800E07D4: sub.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800E07D8: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800E07DC: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
L_800E07E0:
    // 0x800E07E0: beql        $s7, $zero, L_800E0824
    if (ctx->r23 == 0) {
        // 0x800E07E4: lw          $s0, 0x0($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X0);
            goto L_800E0824;
    }
    goto skip_12;
    // 0x800E07E4: lw          $s0, 0x0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X0);
    skip_12:
    // 0x800E07E8: lui         $t0, 0x3B36
    ctx->r8 = S32(0X3B36 << 16);
    // 0x800E07EC: ori         $t0, $t0, 0xB61
    ctx->r8 = ctx->r8 | 0XB61;
    // 0x800E07F0: mtc1        $t0, $f2
    ctx->f2.u32l = ctx->r8;
    // 0x800E07F4: abs.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = fabsf(ctx->f0.fl);
    // 0x800E07F8: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x800E07FC: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800E0800: lui         $t0, 0x43B4
    ctx->r8 = S32(0X43B4 << 16);
    // 0x800E0804: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800E0808: trunc.w.s   $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x800E080C: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800E0810: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800E0814: bc1t        L_800E0820
    if (c1cs) {
        // 0x800E0818: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800E0820;
    }
    // 0x800E0818: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800E081C: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
L_800E0820:
    // 0x800E0820: lw          $s0, 0x0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X0);
L_800E0824:
    // 0x800E0824: lw          $s1, 0x4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4);
    // 0x800E0828: lw          $s2, 0x8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X8);
    // 0x800E082C: lw          $s3, 0xC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XC);
    // 0x800E0830: lw          $s4, 0x10($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X10);
    // 0x800E0834: lw          $s5, 0x14($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X14);
    // 0x800E0838: lw          $s6, 0x18($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X18);
    // 0x800E083C: lw          $s7, 0x1C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X1C);
    // 0x800E0840: lw          $fp, 0x20($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X20);
    // 0x800E0844: jr          $ra
    // 0x800E0848: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800E0848: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80800E60_bsvan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E60: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800E64: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800E68: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800E6C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800E70: jal         0x8009E6EC
    // 0x80800E74: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x80800E74: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800E78: addiu       $t6, $v0, -0x1F
    ctx->r14 = ADD32(ctx->r2, -0X1F);
    // 0x80800E7C: sltiu       $at, $t6, 0x34
    ctx->r1 = ctx->r14 < 0X34 ? 1 : 0;
    // 0x80800E80: beq         $at, $zero, L_80800EE4
    if (ctx->r1 == 0) {
        // 0x80800E84: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800EE4;
    }
    // 0x80800E84: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800E88: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(427, 0X1A84) << 16);
    // 0x80800E8C: addu        $at, $at, $t6
    gpr jr_addend_80800E94 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800E90: lw          $t6, 0x1A84($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(427, 0X1A84));
    // 0x80800E94: jr          $t6
    // 0x80800E98: nop

    switch (jr_addend_80800E94 >> 2) {
        case 0: goto L_80800EF4; break;
        case 1: goto L_80800EF4; break;
        case 2: goto L_80800EF4; break;
        case 3: goto L_80800EE4; break;
        case 4: goto L_80800EE4; break;
        case 5: goto L_80800EE4; break;
        case 6: goto L_80800EE4; break;
        case 7: goto L_80800EE4; break;
        case 8: goto L_80800EE4; break;
        case 9: goto L_80800EE4; break;
        case 10: goto L_80800EE4; break;
        case 11: goto L_80800EE4; break;
        case 12: goto L_80800EE4; break;
        case 13: goto L_80800EE4; break;
        case 14: goto L_80800EE4; break;
        case 15: goto L_80800EF4; break;
        case 16: goto L_80800EE4; break;
        case 17: goto L_80800EE4; break;
        case 18: goto L_80800EE4; break;
        case 19: goto L_80800EE4; break;
        case 20: goto L_80800EE4; break;
        case 21: goto L_80800EE4; break;
        case 22: goto L_80800EE4; break;
        case 23: goto L_80800EE4; break;
        case 24: goto L_80800EE4; break;
        case 25: goto L_80800EE4; break;
        case 26: goto L_80800EE4; break;
        case 27: goto L_80800EE4; break;
        case 28: goto L_80800EE4; break;
        case 29: goto L_80800EE4; break;
        case 30: goto L_80800EE4; break;
        case 31: goto L_80800EE4; break;
        case 32: goto L_80800EE4; break;
        case 33: goto L_80800EE4; break;
        case 34: goto L_80800EE4; break;
        case 35: goto L_80800EE4; break;
        case 36: goto L_80800EE4; break;
        case 37: goto L_80800EE4; break;
        case 38: goto L_80800EE4; break;
        case 39: goto L_80800E9C; break;
        case 40: goto L_80800EE4; break;
        case 41: goto L_80800EE4; break;
        case 42: goto L_80800EE4; break;
        case 43: goto L_80800EE4; break;
        case 44: goto L_80800EE4; break;
        case 45: goto L_80800EE4; break;
        case 46: goto L_80800EE4; break;
        case 47: goto L_80800EF4; break;
        case 48: goto L_80800EE4; break;
        case 49: goto L_80800EE4; break;
        case 50: goto L_80800EF4; break;
        case 51: goto L_80800EF4; break;
        default: switch_error(__func__, 0x80800E94, 0x80801A84);
    }
    // 0x80800E98: nop

L_80800E9C:
    // 0x80800E9C: jal         0x80099A4C
    // 0x80800EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099A4C(rdram, ctx);
        goto after_1;
    // 0x80800EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800EA4: lw          $t7, 0x188($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X188);
    // 0x80800EA8: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x80800EAC: lw          $v1, 0x188($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X188);
    // 0x80800EB0: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80800EB4: jal         0x80087270
    // 0x80800EB8: addiu       $a1, $v1, 0x4
    ctx->r5 = ADD32(ctx->r3, 0X4);
    _chfaircoinbox_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80800EB8: addiu       $a1, $v1, 0x4
    ctx->r5 = ADD32(ctx->r3, 0X4);
    after_2:
    // 0x80800EBC: lw          $t8, 0x188($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X188);
    // 0x80800EC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EC4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800EC8: jal         0x8009E830
    // 0x80800ECC: sw          $v0, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r2;
    func_8009E830(rdram, ctx);
        goto after_3;
    // 0x80800ECC: sw          $v0, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r2;
    after_3:
    // 0x80800ED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800ED4: jal         0x8009E5C8
    // 0x80800ED8: addiu       $a1, $zero, 0x121
    ctx->r5 = ADD32(0, 0X121);
    bs_setState(rdram, ctx);
        goto after_4;
    // 0x80800ED8: addiu       $a1, $zero, 0x121
    ctx->r5 = ADD32(0, 0X121);
    after_4:
    // 0x80800EDC: b           L_80800EF8
    // 0x80800EE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800EF8;
    // 0x80800EE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800EE4:
    // 0x80800EE4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80800EE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EEC: jalr        $t9
    // 0x80800EF0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x80800EF0: nop

    after_5:
L_80800EF4:
    // 0x80800EF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800EF8:
    // 0x80800EF8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800EFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800F00: jr          $ra
    // 0x80800F04: nop

    return;
    // 0x80800F04: nop

;}
RECOMP_FUNC void _chstoneballcoach_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086A88: syscall     411
    recomp_syscall_handler(rdram, ctx, 0x80086A88);
    return;
    // 0x80086A8C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80801B00_chevilspirit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B00: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x80801B04: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80801B08: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80801B0C: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80801B10: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80801B14: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80801B18: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80801B1C: sw          $a2, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r6;
    // 0x80801B20: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80801B24: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80801B28: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80801B2C: lhu         $s0, 0x12($t6)
    ctx->r16 = MEM_HU(ctx->r14, 0X12);
    // 0x80801B30: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80801B34: srl         $t7, $s0, 1
    ctx->r15 = S32(U32(ctx->r16) >> 1);
    // 0x80801B38: jal         0x8001210C
    // 0x80801B3C: andi        $s0, $t7, 0x3
    ctx->r16 = ctx->r15 & 0X3;
    func_8001210C(rdram, ctx);
        goto after_0;
    // 0x80801B3C: andi        $s0, $t7, 0x3
    ctx->r16 = ctx->r15 & 0X3;
    after_0:
    // 0x80801B40: bne         $v0, $s0, L_80801BE4
    if (ctx->r2 != ctx->r16) {
        // 0x80801B44: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80801BE4;
    }
    // 0x80801B44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801B48: addiu       $t9, $s2, 0x30
    ctx->r25 = ADD32(ctx->r18, 0X30);
    // 0x80801B4C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80801B50: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80801B54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80801B58: jal         0x80089FA8
    // 0x80801B5C: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    _subaddievolume_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80801B5C: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    after_1:
    // 0x80801B60: blez        $v0, L_80801BE4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80801B64: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80801BE4;
    }
    // 0x80801B64: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80801B68: jal         0x800B53A4
    // 0x80801B6C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B53A4(rdram, ctx);
        goto after_2;
    // 0x80801B6C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80801B70: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80801B74: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801B78: jal         0x800BA3FC
    // 0x80801B7C: lw          $a1, 0x108($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X108);
    func_800BA3FC(rdram, ctx);
        goto after_3;
    // 0x80801B7C: lw          $a1, 0x108($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X108);
    after_3:
    // 0x80801B80: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801B84: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80801B88: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(924, 0X22F4) << 16);
    // 0x80801B8C: addiu       $t0, $t0, 0x22F4
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(924, 0X22F4));
    // 0x80801B90: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80801B94: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80801B98: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801B9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801BA0: jal         0x800BABB8
    // 0x80801BA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_4;
    // 0x80801BA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80801BA8: blez        $s3, L_80801BE4
    if (SIGNED(ctx->r19) <= 0) {
        // 0x80801BAC: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80801BE4;
    }
    // 0x80801BAC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801BB0: addiu       $s1, $sp, 0x4C
    ctx->r17 = ADD32(ctx->r29, 0X4C);
L_80801BB4:
    // 0x80801BB4: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80801BB8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801BBC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80801BC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801BC4: jal         0x800BABB8
    // 0x80801BC8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800BABB8(rdram, ctx);
        goto after_5;
    // 0x80801BC8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x80801BCC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801BD0: jal         0x800BA22C
    // 0x80801BD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_6;
    // 0x80801BD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80801BD8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80801BDC: bne         $s0, $s3, L_80801BB4
    if (ctx->r16 != ctx->r19) {
        // 0x80801BE0: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80801BB4;
    }
    // 0x80801BE0: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
L_80801BE4:
    // 0x80801BE4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80801BE8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80801BEC: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80801BF0: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80801BF4: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80801BF8: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80801BFC: jr          $ra
    // 0x80801C00: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x80801C00: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
;}
RECOMP_FUNC void _subaddiejoy_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089BE8: syscall     805
    recomp_syscall_handler(rdram, ctx, 0x80089BE8);
    return;
    // 0x80089BEC: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_808005B8_bsride(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005C0: jal         0x8080008C
    // 0x808005C4: nop

    func_8080008C_bsride(rdram, ctx);
        goto after_0;
    // 0x808005C4: nop

    after_0:
    // 0x808005C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808005D0: jr          $ra
    // 0x808005D4: nop

    return;
    // 0x808005D4: nop

;}
RECOMP_FUNC void _babee_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084570: syscall     114
    recomp_syscall_handler(rdram, ctx, 0x80084570);
    return;
    // 0x80084574: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void _glzone_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088770: syscall     703
    recomp_syscall_handler(rdram, ctx, 0x80088770);
    return;
    // 0x80088774: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800CE4_gcnewpause(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    if (tooie_pause_settings_select(rdram, ctx)) return;
    // 0x80800CE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800CE8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800CEC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800CF0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800CF4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800CF8: lb          $t6, 0xD($a0)
    ctx->r14 = MEM_B(ctx->r4, 0XD);
    // 0x80800CFC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2658, 0X2074) << 16);
    // 0x80800D00: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x80800D04: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80800D08: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80800D0C: lw          $v0, 0x2074($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(2658, 0X2074));
    // 0x80800D10: subu        $t9, $t9, $a2
    ctx->r25 = SUB32(ctx->r25, ctx->r6);
    // 0x80800D14: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80800D18: addu        $v1, $v0, $t9
    ctx->r3 = ADD32(ctx->r2, ctx->r25);
    // 0x80800D1C: lbu         $t0, 0x3($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X3);
    // 0x80800D20: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800D24: sltiu       $at, $t0, 0x5
    ctx->r1 = ctx->r8 < 0X5 ? 1 : 0;
    // 0x80800D28: beq         $at, $zero, L_80800DC4
    if (ctx->r1 == 0) {
        // 0x80800D2C: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_80800DC4;
    }
    // 0x80800D2C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80800D30: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2658, 0X1FCC) << 16);
    // 0x80800D34: addu        $at, $at, $t0
    gpr jr_addend_80800D3C = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80800D38: lw          $t0, 0x1FCC($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2658, 0X1FCC));
    // 0x80800D3C: jr          $t0
    // 0x80800D40: nop

    switch (jr_addend_80800D3C >> 2) {
        case 0: goto L_80800D44; break;
        case 1: goto L_80800D50; break;
        case 2: goto L_80800D90; break;
        case 3: goto L_80800DA4; break;
        case 4: goto L_80800DB8; break;
        default: switch_error(__func__, 0x80800D3C, 0x80801FCC);
    }
    // 0x80800D40: nop

L_80800D44:
    // 0x80800D44: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80800D48: b           L_80800DC4
    // 0x80800D4C: sb          $t1, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r9;
        goto L_80800DC4;
    // 0x80800D4C: sb          $t1, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r9;
L_80800D50:
    // 0x80800D50: lbu         $v0, 0x4($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X4);
    // 0x80800D54: slti        $at, $v0, 0xE
    ctx->r1 = SIGNED(ctx->r2) < 0XE ? 1 : 0;
    // 0x80800D58: beq         $at, $zero, L_80800D68
    if (ctx->r1 == 0) {
        // 0x80800D5C: nop
    
            goto L_80800D68;
    }
    // 0x80800D5C: nop

    // 0x80800D60: b           L_80800D74
    // 0x80800D64: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_80800D74;
    // 0x80800D64: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80800D68:
    // 0x80800D68: jal         0x808011BC
    // 0x80800D6C: nop

    func_808011BC_gcnewpause(rdram, ctx);
        goto after_0;
    // 0x80800D6C: nop

    after_0:
    // 0x80800D70: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80800D74:
    // 0x80800D74: jal         0x808017C8
    // 0x80800D78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808017C8_gcnewpause(rdram, ctx);
        goto after_1;
    // 0x80800D78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800D7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D80: jal         0x80800534
    // 0x80800D84: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800534_gcnewpause(rdram, ctx);
        goto after_2;
    // 0x80800D84: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x80800D88: b           L_80800DC8
    // 0x80800D8C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
        goto L_80800DC8;
    // 0x80800D8C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
L_80800D90:
    // 0x80800D90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D94: jal         0x80800534
    // 0x80800D98: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800534_gcnewpause(rdram, ctx);
        goto after_3;
    // 0x80800D98: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_3:
    // 0x80800D9C: b           L_80800DC8
    // 0x80800DA0: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
        goto L_80800DC8;
    // 0x80800DA0: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
L_80800DA4:
    // 0x80800DA4: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80800DA8: jal         0x80088188
    // 0x80800DAC: sb          $t2, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r10;
    _gcfrontend_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x80800DAC: sb          $t2, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r10;
    after_4:
    // 0x80800DB0: b           L_80800DC8
    // 0x80800DB4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
        goto L_80800DC8;
    // 0x80800DB4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
L_80800DB8:
    // 0x80800DB8: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80800DBC: jal         0x80088190
    // 0x80800DC0: sb          $t3, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r11;
    _gcfrontend_entrypoint_12(rdram, ctx);
        goto after_5;
    // 0x80800DC0: sb          $t3, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r11;
    after_5:
L_80800DC4:
    // 0x80800DC4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
L_80800DC8:
    // 0x80800DC8: sb          $t4, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r12;
    // 0x80800DCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800DD0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800DD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800DD8: jr          $ra
    // 0x80800DDC: nop

    return;
    // 0x80800DDC: nop

;}
RECOMP_FUNC void func_8009E958(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E958: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009E95C: jr          $ra
    // 0x8009E960: lbu         $v0, 0x704C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X704C);
    return;
    // 0x8009E960: lbu         $v0, 0x704C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X704C);
;}
RECOMP_FUNC void _bawandglow_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800853B0: syscall     160
    recomp_syscall_handler(rdram, ctx, 0x800853B0);
    return;
    // 0x800853B4: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void func_80100074(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100074: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80100078: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010007C: jal         0x800FFECC
    // 0x80100080: nop

    func_800FFECC(rdram, ctx);
        goto after_0;
    // 0x80100080: nop

    after_0:
    // 0x80100084: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80100088: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010008C: jr          $ra
    // 0x80100090: nop

    return;
    // 0x80100090: nop

;}
RECOMP_FUNC void func_800D3E6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3E6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D3E70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D3E74: jal         0x800D3E14
    // 0x800D3E78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D3E14(rdram, ctx);
        goto after_0;
    // 0x800D3E78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800D3E7C: beq         $v0, $zero, L_800D3E8C
    if (ctx->r2 == 0) {
        // 0x800D3E80: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_800D3E8C;
    }
    // 0x800D3E80: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800D3E84: b           L_800D3EB8
    // 0x800D3E88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D3EB8;
    // 0x800D3E88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D3E8C:
    // 0x800D3E8C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800D3E90: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800D3E94: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x800D3E98: lhu         $v0, -0x4A48($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X4A48);
    // 0x800D3E9C: beql        $v0, $zero, L_800D3EB8
    if (ctx->r2 == 0) {
        // 0x800D3EA0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800D3EB8;
    }
    goto skip_0;
    // 0x800D3EA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x800D3EA4: jal         0x800DA298
    // 0x800D3EA8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x800D3EA8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800D3EAC: b           L_800D3EBC
    // 0x800D3EB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800D3EBC;
    // 0x800D3EB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D3EB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D3EB8:
    // 0x800D3EB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D3EBC:
    // 0x800D3EBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D3EC0: jr          $ra
    // 0x800D3EC4: nop

    return;
    // 0x800D3EC4: nop

;}
RECOMP_FUNC void _babackpack_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084530: syscall     113
    recomp_syscall_handler(rdram, ctx, 0x80084530);
    return;
    // 0x80084534: xori        $t0, $zero, 0x24
    ctx->r8 = 0 ^ 0X24;
;}
RECOMP_FUNC void func_80800000_chjellycastle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800008: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080000C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800010: jal         0x800878B0
    // 0x80800014: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    _plsu_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800014: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x80800018: bne         $v0, $zero, L_8080005C
    if (ctx->r2 != 0) {
        // 0x8080001C: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_8080005C;
    }
    // 0x8080001C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800020: jal         0x800D90A4
    // 0x80800024: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_1;
    // 0x80800024: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_1:
    // 0x80800028: beql        $v0, $zero, L_80800060
    if (ctx->r2 == 0) {
        // 0x8080002C: lw          $t9, 0x24($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X24);
            goto L_80800060;
    }
    goto skip_0;
    // 0x8080002C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800030: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x80800034: lui         $a0, 0x599C
    ctx->r4 = S32(0X599C << 16);
    // 0x80800038: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x8080003C: bltzl       $t8, L_80800060
    if (SIGNED(ctx->r24) < 0) {
        // 0x80800040: lw          $t9, 0x24($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X24);
            goto L_80800060;
    }
    goto skip_1;
    // 0x80800040: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80800044: jal         0x800C3F48
    // 0x80800048: ori         $a0, $a0, 0x5699
    ctx->r4 = ctx->r4 | 0X5699;
    func_800C3F48(rdram, ctx);
        goto after_2;
    // 0x80800048: ori         $a0, $a0, 0x5699
    ctx->r4 = ctx->r4 | 0X5699;
    after_2:
    // 0x8080004C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800050: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800054: nop

    // 0x80800058: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_8080005C:
    // 0x8080005C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
L_80800060:
    // 0x80800060: lbu         $t4, 0x65($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X65);
    // 0x80800064: sltiu       $t1, $t9, 0x1
    ctx->r9 = ctx->r25 < 0X1 ? 1 : 0;
    // 0x80800068: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x8080006C: andi        $t3, $t2, 0x10
    ctx->r11 = ctx->r10 & 0X10;
    // 0x80800070: andi        $t5, $t4, 0xFFEF
    ctx->r13 = ctx->r12 & 0XFFEF;
    // 0x80800074: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x80800078: sb          $t6, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r14;
    // 0x8080007C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800080: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800084: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800088: jr          $ra
    // 0x8080008C: nop

    return;
    // 0x8080008C: nop

;}
RECOMP_FUNC void _baattach_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084460: syscall     111
    recomp_syscall_handler(rdram, ctx, 0x80084460);
    return;
    // 0x80084464: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80800998_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800998: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080099C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009A0: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808009A4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(804, 0X7DE8) << 16);
    // 0x808009A8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808009AC: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808009B0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x808009B4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x808009B8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808009BC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x808009C0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808009C4: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x808009C8: lw          $v0, 0x7DE8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(804, 0X7DE8));
    // 0x808009CC: beql        $v0, $zero, L_808009E0
    if (ctx->r2 == 0) {
        // 0x808009D0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808009E0;
    }
    goto skip_0;
    // 0x808009D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808009D4: jalr        $v0
    // 0x808009D8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x808009D8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x808009DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808009E0:
    // 0x808009E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808009E4: jr          $ra
    // 0x808009E8: nop

    return;
    // 0x808009E8: nop

;}
RECOMP_FUNC void dbskeleton_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: jr          $ra
    // 0x8080000C: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    return;
    // 0x8080000C: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
;}
RECOMP_FUNC void bafly_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CAC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800CB0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800CB4: jal         0x80084C90
    // 0x80800CB8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _bafpctrl_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800CB8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800CBC: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80800CC0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800CC4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800CC8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(528, 0XDAC) << 16);
    // 0x80800CCC: lwc1        $f14, 0xDAC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(528, 0XDAC));
    // 0x80800CD0: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80800CD4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800CD8: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80800CDC: jal         0x800F10B4
    // 0x80800CE0: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x80800CE0: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x80800CE4: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80800CE8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800CEC: lui         $a2, 0x3F99
    ctx->r6 = S32(0X3F99 << 16);
    // 0x80800CF0: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800CF4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80800CF8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800CFC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800D00: jal         0x8009BFE4
    // 0x80800D04: nop

    func_8009BFE4(rdram, ctx);
        goto after_2;
    // 0x80800D04: nop

    after_2:
    // 0x80800D08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800D10: jr          $ra
    // 0x80800D14: nop

    return;
    // 0x80800D14: nop

;}
RECOMP_FUNC void bsstonehead_entrypoint_31(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801274: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801278: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(376, 0X16A0) << 16);
    // 0x8080127C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801280: jr          $ra
    // 0x80801284: lw          $v0, 0x16A0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(376, 0X16A0));
    return;
    // 0x80801284: lw          $v0, 0x16A0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(376, 0X16A0));
;}
RECOMP_FUNC void func_800C5464(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5464: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C5468: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x800C546C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C5470: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800C5474: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800C5478: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x800C547C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800C5480: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x800C5484: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800C5488: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800C548C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800C5490: addiu       $s1, $zero, 0x5
    ctx->r17 = ADD32(0, 0X5);
    // 0x800C5494: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
L_800C5498:
    // 0x800C5498: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x800C549C: jal         0x800C54CC
    // 0x800C54A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C54CC(rdram, ctx);
        goto after_0;
    // 0x800C54A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800C54A4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800C54A8: bnel        $s0, $s1, L_800C5498
    if (ctx->r16 != ctx->r17) {
        // 0x800C54AC: mfc1        $a1, $f20
        ctx->r5 = (int32_t)ctx->f20.u32l;
            goto L_800C5498;
    }
    goto skip_0;
    // 0x800C54AC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    skip_0:
    // 0x800C54B0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800C54B4: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800C54B8: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x800C54BC: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x800C54C0: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800C54C4: jr          $ra
    // 0x800C54C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800C54C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80801158_chalienkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801158: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x8080115C: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x80801160: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80801164: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x80801168: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x8080116C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801170: sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // 0x80801174: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // 0x80801178: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x8080117C: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x80801180: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x80801184: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x80801188: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x8080118C: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x80801190: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x80801194: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80801198: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x8080119C: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x808011A0: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x808011A4: jal         0x80100094
    // 0x808011A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808011A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808011AC: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x808011B0: jal         0x800D9078
    // 0x808011B4: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_1;
    // 0x808011B4: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_1:
    // 0x808011B8: addiu       $fp, $sp, 0xC4
    ctx->r30 = ADD32(ctx->r29, 0XC4);
    // 0x808011BC: sw          $v0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r2;
    // 0x808011C0: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    // 0x808011C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011C8: jal         0x8008A0D0
    // 0x808011CC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x808011CC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x808011D0: bne         $v0, $zero, L_808011E0
    if (ctx->r2 != 0) {
        // 0x808011D4: or          $a0, $fp, $zero
        ctx->r4 = ctx->r30 | 0;
            goto L_808011E0;
    }
    // 0x808011D4: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x808011D8: jal         0x800EE7F8
    // 0x808011DC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x808011DC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_3:
L_808011E0:
    // 0x808011E0: jal         0x800D8FF8
    // 0x808011E4: nop

    func_800D8FF8(rdram, ctx);
        goto after_4;
    // 0x808011E4: nop

    after_4:
    // 0x808011E8: swc1        $f0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f0.u32l;
    // 0x808011EC: jal         0x800B53A4
    // 0x808011F0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800B53A4(rdram, ctx);
        goto after_5;
    // 0x808011F0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_5:
    // 0x808011F4: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x808011F8: jal         0x80103EF4
    // 0x808011FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EF4(rdram, ctx);
        goto after_6;
    // 0x808011FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80801200: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80801204: jal         0x80103EAC
    // 0x80801208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EAC(rdram, ctx);
        goto after_7;
    // 0x80801208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080120C: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x80801210: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801214: addiu       $s6, $sp, 0x90
    ctx->r22 = ADD32(ctx->r29, 0X90);
    // 0x80801218: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8080121C: mul.s       $f26, $f0, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80801220: jal         0x800EE7F8
    // 0x80801224: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_8;
    // 0x80801224: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    after_8:
    // 0x80801228: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8080122C: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80801230: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80801234: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801238: lwc1        $f8, 0x94($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8080123C: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80801240: mul.s       $f22, $f6, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f22.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80801244: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80801248: mfc1        $a2, $f28
    ctx->r6 = (int32_t)ctx->f28.u32l;
    // 0x8080124C: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    // 0x80801250: add.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f22.fl;
    // 0x80801254: swc1        $f10, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f10.u32l;
    // 0x80801258: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8080125C: jal         0x800F12D4
    // 0x80801260: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    func_800F12D4(rdram, ctx);
        goto after_9;
    // 0x80801260: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_9:
    // 0x80801264: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80801268: mfc1        $a2, $f28
    ctx->r6 = (int32_t)ctx->f28.u32l;
    // 0x8080126C: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80801270: mov.s       $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.fl = ctx->f0.fl;
    // 0x80801274: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80801278: jal         0x800F12D4
    // 0x8080127C: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    func_800F12D4(rdram, ctx);
        goto after_10;
    // 0x8080127C: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    after_10:
    // 0x80801280: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80801284: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801288: swc1        $f0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f0.u32l;
    // 0x8080128C: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80801290: mul.s       $f18, $f16, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f26.fl);
    // 0x80801294: mfc1        $a2, $f28
    ctx->r6 = (int32_t)ctx->f28.u32l;
    // 0x80801298: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x8080129C: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    // 0x808012A0: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x808012A4: jal         0x800F12D4
    // 0x808012A8: nop

    func_800F12D4(rdram, ctx);
        goto after_11;
    // 0x808012A8: nop

    after_11:
    // 0x808012AC: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    // 0x808012B0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808012B4: jal         0x800BA3FC
    // 0x808012B8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800BA3FC(rdram, ctx);
        goto after_12;
    // 0x808012B8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_12:
    // 0x808012BC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808012C0: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x808012C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808012C8: mov.s       $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    ctx->f20.fl = ctx->f24.fl;
    // 0x808012CC: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x808012D0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x808012D4: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(1324, 0X223C) << 16);
    // 0x808012D8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x808012DC: addiu       $s3, $s3, 0x223C
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(1324, 0X223C));
    // 0x808012E0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x808012E4: addiu       $s7, $zero, 0x4
    ctx->r23 = ADD32(0, 0X4);
    // 0x808012E8: addiu       $s1, $sp, 0xB8
    ctx->r17 = ADD32(ctx->r29, 0XB8);
    // 0x808012EC: addiu       $s0, $sp, 0xAC
    ctx->r16 = ADD32(ctx->r29, 0XAC);
L_808012F0:
    // 0x808012F0: lwc1        $f4, 0x1C($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X1C);
    // 0x808012F4: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x808012F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012FC: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x80801300: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80801304: jal         0x800EEB9C
    // 0x80801308: nop

    func_800EEB9C(rdram, ctx);
        goto after_13;
    // 0x80801308: nop

    after_13:
    // 0x8080130C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801310: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x80801314: jal         0x800EE780
    // 0x80801318: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800EE780(rdram, ctx);
        goto after_14;
    // 0x80801318: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_14:
    // 0x8080131C: lwc1        $f8, 0x24($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X24);
    // 0x80801320: jal         0x80013970
    // 0x80801324: add.s       $f12, $f8, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f20.fl;
    func_80013970(rdram, ctx);
        goto after_15;
    // 0x80801324: add.s       $f12, $f8, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f20.fl;
    after_15:
    // 0x80801328: mul.s       $f16, $f22, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x8080132C: lwc1        $f10, 0xBC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80801330: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80801334: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80801338: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8080133C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80801340: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80801344: add.s       $f18, $f30, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f30.fl + ctx->f16.fl;
    // 0x80801348: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8080134C: jal         0x800BABB8
    // 0x80801350: swc1        $f4, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f4.u32l;
    func_800BABB8(rdram, ctx);
        goto after_16;
    // 0x80801350: swc1        $f4, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f4.u32l;
    after_16:
    // 0x80801354: lwc1        $f6, 0x20($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X20);
    // 0x80801358: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x8080135C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801360: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x80801364: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80801368: jal         0x800EEB9C
    // 0x8080136C: nop

    func_800EEB9C(rdram, ctx);
        goto after_17;
    // 0x8080136C: nop

    after_17:
    // 0x80801370: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801374: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x80801378: jal         0x800EE780
    // 0x8080137C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800EE780(rdram, ctx);
        goto after_18;
    // 0x8080137C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_18:
    // 0x80801380: lwc1        $f16, 0x28($s4)
    ctx->f16.u32l = MEM_W(ctx->r20, 0X28);
    // 0x80801384: jal         0x80013970
    // 0x80801388: add.s       $f12, $f16, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f20.fl;
    func_80013970(rdram, ctx);
        goto after_19;
    // 0x80801388: add.s       $f12, $f16, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f20.fl;
    after_19:
    // 0x8080138C: mul.s       $f18, $f22, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x80801390: lwc1        $f10, 0xA0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80801394: lwc1        $f6, 0xBC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80801398: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x8080139C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808013A0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808013A4: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x808013A8: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x808013AC: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x808013B0: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x808013B4: jal         0x800BABB8
    // 0x808013B8: swc1        $f8, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f8.u32l;
    func_800BABB8(rdram, ctx);
        goto after_20;
    // 0x808013B8: swc1        $f8, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f8.u32l;
    after_20:
    // 0x808013BC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x808013C0: bne         $s2, $s7, L_808012F0
    if (ctx->r18 != ctx->r23) {
        // 0x808013C4: add.s       $f20, $f20, $f28
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f28.fl;
            goto L_808012F0;
    }
    // 0x808013C4: add.s       $f20, $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f28.fl;
    // 0x808013C8: lui         $at, 0x43BE
    ctx->r1 = S32(0X43BE << 16);
    // 0x808013CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808013D0: lwc1        $f16, 0x9C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x808013D4: lwc1        $f18, 0x1C($s4)
    ctx->f18.u32l = MEM_W(ctx->r20, 0X1C);
    // 0x808013D8: mul.s       $f20, $f16, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x808013DC: jal         0x800136E4
    // 0x808013E0: sub.s       $f12, $f18, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f20.fl;
    func_800136E4(rdram, ctx);
        goto after_21;
    // 0x808013E0: sub.s       $f12, $f18, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f20.fl;
    after_21:
    // 0x808013E4: lwc1        $f6, 0x20($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X20);
    // 0x808013E8: swc1        $f0, 0x1C($s4)
    MEM_W(0X1C, ctx->r20) = ctx->f0.u32l;
    // 0x808013EC: jal         0x800136E4
    // 0x808013F0: add.s       $f12, $f6, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f20.fl;
    func_800136E4(rdram, ctx);
        goto after_22;
    // 0x808013F0: add.s       $f12, $f6, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f20.fl;
    after_22:
    // 0x808013F4: swc1        $f0, 0x20($s4)
    MEM_W(0X20, ctx->r20) = ctx->f0.u32l;
    // 0x808013F8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808013FC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801400: lwc1        $f4, 0x9C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80801404: lwc1        $f10, 0x24($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X24);
    // 0x80801408: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8080140C: mul.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80801410: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801414: addiu       $a2, $zero, 0x1F4
    ctx->r6 = ADD32(0, 0X1F4);
    // 0x80801418: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x8080141C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80801420: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80801424: lwc1        $f10, 0x28($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X28);
    // 0x80801428: swc1        $f18, 0x24($s4)
    MEM_W(0X24, ctx->r20) = ctx->f18.u32l;
    // 0x8080142C: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80801430: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80801434: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80801438: swc1        $f16, 0x28($s4)
    MEM_W(0X28, ctx->r20) = ctx->f16.u32l;
    // 0x8080143C: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
    // 0x80801440: beq         $t6, $zero, L_8080145C
    if (ctx->r14 == 0) {
        // 0x80801444: nop
    
            goto L_8080145C;
    }
    // 0x80801444: nop

    // 0x80801448: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x8080144C: jal         0x800FCAE0
    // 0x80801450: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800FCAE0(rdram, ctx);
        goto after_23;
    // 0x80801450: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_23:
    // 0x80801454: b           L_80801468
    // 0x80801458: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
        goto L_80801468;
    // 0x80801458: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
L_8080145C:
    // 0x8080145C: jal         0x800FCAE0
    // 0x80801460: addiu       $a2, $zero, 0x1F4
    ctx->r6 = ADD32(0, 0X1F4);
    func_800FCAE0(rdram, ctx);
        goto after_24;
    // 0x80801460: addiu       $a2, $zero, 0x1F4
    ctx->r6 = ADD32(0, 0X1F4);
    after_24:
    // 0x80801464: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
L_80801468:
    // 0x80801468: lw          $v0, 0xD0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD0);
    // 0x8080146C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80801470: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80801474: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80801478: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x8080147C: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x80801480: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x80801484: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x80801488: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x8080148C: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x80801490: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x80801494: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x80801498: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x8080149C: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x808014A0: lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X6C);
    // 0x808014A4: lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X70);
    // 0x808014A8: jr          $ra
    // 0x808014AC: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x808014AC: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
;}
RECOMP_FUNC void _gcdialogcamera_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088078: syscall     669
    recomp_syscall_handler(rdram, ctx, 0x80088078);
    return;
    // 0x8008807C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808002A4_gsattract(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x808002A8: addiu       $v1, $v1, 0x5470
    ctx->r3 = ADD32(ctx->r3, 0X5470);
    // 0x808002AC: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x808002B0: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2882, 0X494) << 16);
    // 0x808002B4: sb          $a0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r4;
    // 0x808002B8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x808002BC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x808002C0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808002C4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x808002C8: lw          $t8, 0x494($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(2882, 0X494));
    // 0x808002CC: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x808002D0: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x808002D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002D8: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x808002DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002E0: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x808002E4: lb          $t0, 0x2($v0)
    ctx->r8 = MEM_B(ctx->r2, 0X2);
    // 0x808002E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808002EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808002F0: bgezl       $t0, L_8080030C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x808002F4: lbu         $a0, 0x4($v0)
        ctx->r4 = MEM_BU(ctx->r2, 0X4);
            goto L_8080030C;
    }
    goto skip_0;
    // 0x808002F4: lbu         $a0, 0x4($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X4);
    skip_0:
    // 0x808002F8: jal         0x800A791C
    // 0x808002FC: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    func_800A791C(rdram, ctx);
        goto after_0;
    // 0x808002FC: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    after_0:
    // 0x80800300: b           L_8080032C
    // 0x80800304: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080032C;
    // 0x80800304: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800308: lbu         $a0, 0x4($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X4);
L_8080030C:
    // 0x8080030C: jal         0x800D3A14
    // 0x80800310: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800D3A14(rdram, ctx);
        goto after_1;
    // 0x80800310: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800314: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80800318: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8080031C: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80800320: jal         0x800A9BA0
    // 0x80800324: lb          $a2, 0x2($v0)
    ctx->r6 = MEM_B(ctx->r2, 0X2);
    func_800A9BA0(rdram, ctx);
        goto after_2;
    // 0x80800324: lb          $a2, 0x2($v0)
    ctx->r6 = MEM_B(ctx->r2, 0X2);
    after_2:
    // 0x80800328: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080032C:
    // 0x8080032C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800330: jr          $ra
    // 0x80800334: nop

    return;
    // 0x80800334: nop

;}
RECOMP_FUNC void anseq_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080024C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800250: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80800254: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80800258: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8080025C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80800260: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80800264: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80800268: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080026C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800270: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80800274: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800278: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8080027C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800280: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80800284: jal         0x80800134
    // 0x80800288: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    func_80800134_anseq(rdram, ctx);
        goto after_0;
    // 0x80800288: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_0:
    // 0x8080028C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800290: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800294: jr          $ra
    // 0x80800298: nop

    return;
    // 0x80800298: nop

;}
RECOMP_FUNC void mlwave_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800230: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800234: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800238: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8080023C: lwc1        $f2, 0x18($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80800240: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800244: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    // 0x80800248: jal         0x808001A8
    // 0x8080024C: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    mlwave_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x8080024C: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x80800250: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800254: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800258: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8080025C: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80800260: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800268: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8080026C: nop

    // 0x80800270: bc1fl       L_80800300
    if (!c1cs) {
        // 0x80800274: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_80800300;
    }
    goto skip_0;
    // 0x80800274: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_0:
    // 0x80800278: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8080027C: nop

    // 0x80800280: bc1fl       L_808002C4
    if (!c1cs) {
        // 0x80800284: c.le.s      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
            goto L_808002C4;
    }
    goto skip_1;
    // 0x80800284: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
    skip_1:
    // 0x80800288: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
    // 0x8080028C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800290: bc1f        L_8080029C
    if (!c1cs) {
        // 0x80800294: nop
    
            goto L_8080029C;
    }
    // 0x80800294: nop

    // 0x80800298: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080029C:
    // 0x8080029C: beq         $v0, $zero, L_808002B8
    if (ctx->r2 == 0) {
        // 0x808002A0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_808002B8;
    }
    // 0x808002A0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808002A4: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x808002A8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808002AC: bc1f        L_808002B8
    if (!c1cs) {
        // 0x808002B0: nop
    
            goto L_808002B8;
    }
    // 0x808002B0: nop

    // 0x808002B4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_808002B8:
    // 0x808002B8: b           L_8080037C
    // 0x808002BC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8080037C;
    // 0x808002BC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x808002C0: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
L_808002C4:
    // 0x808002C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808002C8: bc1f        L_808002D4
    if (!c1cs) {
        // 0x808002CC: nop
    
            goto L_808002D4;
    }
    // 0x808002CC: nop

    // 0x808002D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002D4:
    // 0x808002D4: bne         $v0, $zero, L_808002F0
    if (ctx->r2 != 0) {
        // 0x808002D8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_808002F0;
    }
    // 0x808002D8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808002DC: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x808002E0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808002E4: bc1fl       L_808002F4
    if (!c1cs) {
        // 0x808002E8: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_808002F4;
    }
    goto skip_2;
    // 0x808002E8: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    skip_2:
    // 0x808002EC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_808002F0:
    // 0x808002F0: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_808002F4:
    // 0x808002F4: b           L_8080037C
    // 0x808002F8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8080037C;
    // 0x808002F8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x808002FC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_80800300:
    // 0x80800300: nop

    // 0x80800304: bc1fl       L_80800348
    if (!c1cs) {
        // 0x80800308: c.le.s      $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
            goto L_80800348;
    }
    goto skip_3;
    // 0x80800308: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    skip_3:
    // 0x8080030C: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x80800310: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800314: bc1f        L_80800320
    if (!c1cs) {
        // 0x80800318: nop
    
            goto L_80800320;
    }
    // 0x80800318: nop

    // 0x8080031C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800320:
    // 0x80800320: beq         $v0, $zero, L_8080033C
    if (ctx->r2 == 0) {
        // 0x80800324: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8080033C;
    }
    // 0x80800324: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800328: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8080032C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800330: bc1f        L_8080033C
    if (!c1cs) {
        // 0x80800334: nop
    
            goto L_8080033C;
    }
    // 0x80800334: nop

    // 0x80800338: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8080033C:
    // 0x8080033C: b           L_80800378
    // 0x80800340: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
        goto L_80800378;
    // 0x80800340: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80800344: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
L_80800348:
    // 0x80800348: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080034C: bc1f        L_80800358
    if (!c1cs) {
        // 0x80800350: nop
    
            goto L_80800358;
    }
    // 0x80800350: nop

    // 0x80800354: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800358:
    // 0x80800358: bne         $v0, $zero, L_80800374
    if (ctx->r2 != 0) {
        // 0x8080035C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800374;
    }
    // 0x8080035C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800360: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80800364: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800368: bc1fl       L_80800378
    if (!c1cs) {
        // 0x8080036C: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_80800378;
    }
    goto skip_4;
    // 0x8080036C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    skip_4:
    // 0x80800370: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80800374:
    // 0x80800374: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_80800378:
    // 0x80800378: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8080037C:
    // 0x8080037C: jr          $ra
    // 0x80800380: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800380: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_808025D4_chfactoryrobot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808025D4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808025D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808025DC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808025E0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808025E4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808025E8: jal         0x80100094
    // 0x808025EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808025EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808025F0: lbu         $t6, 0x12($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X12);
    // 0x808025F4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808025F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808025FC: beql        $t6, $zero, L_80802670
    if (ctx->r14 == 0) {
        // 0x80802600: lhu         $a2, 0x76($s1)
        ctx->r6 = MEM_HU(ctx->r17, 0X76);
            goto L_80802670;
    }
    goto skip_0;
    // 0x80802600: lhu         $a2, 0x76($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X76);
    skip_0:
    // 0x80802604: jal         0x8008A4B0
    // 0x80802608: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80802608: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8080260C: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x80802610: sb          $t7, 0x13($s0)
    MEM_B(0X13, ctx->r16) = ctx->r15;
    // 0x80802614: jal         0x800DA298
    // 0x80802618: addiu       $a0, $zero, 0x1BB
    ctx->r4 = ADD32(0, 0X1BB);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80802618: addiu       $a0, $zero, 0x1BB
    ctx->r4 = ADD32(0, 0X1BB);
    after_2:
    // 0x8080261C: beq         $v0, $zero, L_8080262C
    if (ctx->r2 == 0) {
        // 0x80802620: addiu       $a1, $zero, 0x4
        ctx->r5 = ADD32(0, 0X4);
            goto L_8080262C;
    }
    // 0x80802620: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80802624: b           L_8080262C
    // 0x80802628: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
        goto L_8080262C;
    // 0x80802628: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
L_8080262C:
    // 0x8080262C: jal         0x80101FDC
    // 0x80802630: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x80802630: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80802634: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80802638: jal         0x800EE7F8
    // 0x8080263C: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x8080263C: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    after_4:
    // 0x80802640: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80802644: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80802648: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8080264C: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    // 0x80802650: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80802654: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80802658: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x8080265C: jal         0x800D1254
    // 0x80802660: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    func_800D1254(rdram, ctx);
        goto after_5;
    // 0x80802660: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x80802664: b           L_808026A4
    // 0x80802668: lwc1        $f10, 0x48($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X48);
        goto L_808026A4;
    // 0x80802668: lwc1        $f10, 0x48($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X48);
    // 0x8080266C: lhu         $a2, 0x76($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X76);
L_80802670:
    // 0x80802670: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802674: addiu       $a1, $zero, 0x3BD
    ctx->r5 = ADD32(0, 0X3BD);
    // 0x80802678: srl         $t8, $a2, 7
    ctx->r24 = S32(U32(ctx->r6) >> 7);
    // 0x8080267C: jal         0x80089C70
    // 0x80802680: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    _subaddiefind_entrypoint_10(rdram, ctx);
        goto after_6;
    // 0x80802680: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    after_6:
    // 0x80802684: bne         $v0, $zero, L_808026A0
    if (ctx->r2 != 0) {
        // 0x80802688: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808026A0;
    }
    // 0x80802688: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080268C: jal         0x80101FDC
    // 0x80802690: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_7;
    // 0x80802690: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
    // 0x80802694: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802698: jal         0x80103110
    // 0x8080269C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_8;
    // 0x8080269C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
L_808026A0:
    // 0x808026A0: lwc1        $f10, 0x48($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X48);
L_808026A4:
    // 0x808026A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808026A8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x808026AC: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x808026B0: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x808026B4: jal         0x800F0D90
    // 0x808026B8: nop

    func_800F0D90(rdram, ctx);
        goto after_9;
    // 0x808026B8: nop

    after_9:
    // 0x808026BC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x808026C0: andi        $t1, $v0, 0xFF
    ctx->r9 = ctx->r2 & 0XFF;
    // 0x808026C4: sb          $v0, 0x11($s0)
    MEM_B(0X11, ctx->r16) = ctx->r2;
    // 0x808026C8: sb          $zero, 0x10($s0)
    MEM_B(0X10, ctx->r16) = 0;
    // 0x808026CC: sb          $t0, 0x14($s0)
    MEM_B(0X14, ctx->r16) = ctx->r8;
    // 0x808026D0: blez        $t1, L_808026F8
    if (SIGNED(ctx->r9) <= 0) {
        // 0x808026D4: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_808026F8;
    }
    // 0x808026D4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808026D8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x808026DC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_808026E0:
    // 0x808026E0: lbu         $t2, 0x11($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X11);
    // 0x808026E4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x808026E8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808026EC: slt         $at, $v1, $t2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x808026F0: bnel        $at, $zero, L_808026E0
    if (ctx->r1 != 0) {
        // 0x808026F4: sw          $zero, 0x0($v0)
        MEM_W(0X0, ctx->r2) = 0;
            goto L_808026E0;
    }
    goto skip_1;
    // 0x808026F4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    skip_1:
L_808026F8:
    // 0x808026F8: lbu         $t3, 0x12($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X12);
    // 0x808026FC: beql        $t3, $zero, L_80802744
    if (ctx->r11 == 0) {
        // 0x80802700: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802744;
    }
    goto skip_2;
    // 0x80802700: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80802704: jal         0x800DA298
    // 0x80802708: addiu       $a0, $zero, 0x6A3
    ctx->r4 = ADD32(0, 0X6A3);
    func_800DA298(rdram, ctx);
        goto after_10;
    // 0x80802708: addiu       $a0, $zero, 0x6A3
    ctx->r4 = ADD32(0, 0X6A3);
    after_10:
    // 0x8080270C: bnel        $v0, $zero, L_80802744
    if (ctx->r2 != 0) {
        // 0x80802710: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802744;
    }
    goto skip_3;
    // 0x80802710: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80802714: jal         0x800EA090
    // 0x80802718: nop

    func_800EA090(rdram, ctx);
        goto after_11;
    // 0x80802718: nop

    after_11:
    // 0x8080271C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80802720: bne         $v0, $at, L_80802740
    if (ctx->r2 != ctx->r1) {
        // 0x80802724: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80802740;
    }
    // 0x80802724: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80802728: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8080272C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80802730: jal         0x80085708
    // 0x80802734: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    _capod_entrypoint_13(rdram, ctx);
        goto after_12;
    // 0x80802734: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_12:
    // 0x80802738: jal         0x800DA544
    // 0x8080273C: addiu       $a0, $zero, 0x6A3
    ctx->r4 = ADD32(0, 0X6A3);
    func_800DA544(rdram, ctx);
        goto after_13;
    // 0x8080273C: addiu       $a0, $zero, 0x6A3
    ctx->r4 = ADD32(0, 0X6A3);
    after_13:
L_80802740:
    // 0x80802740: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802744:
    // 0x80802744: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80802748: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080274C: jr          $ra
    // 0x80802750: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80802750: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80802754: nop

    // 0x80802758: nop

    // 0x8080275C: nop

;}
RECOMP_FUNC void _plcamera_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087908: syscall     639
    recomp_syscall_handler(rdram, ctx, 0x80087908);
    return;
    // 0x8008790C: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void bsdronesuckunder_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000F0: jal         0x8009E6EC
    // 0x808000F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x808000F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000F8: addiu       $at, $zero, 0x26
    ctx->r1 = ADD32(0, 0X26);
    // 0x808000FC: beq         $v0, $at, L_80800120
    if (ctx->r2 == ctx->r1) {
        // 0x80800100: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800120;
    }
    // 0x80800100: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800104: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x80800108: beq         $v0, $at, L_80800120
    if (ctx->r2 == ctx->r1) {
        // 0x8080010C: addiu       $at, $zero, 0x52
        ctx->r1 = ADD32(0, 0X52);
            goto L_80800120;
    }
    // 0x8080010C: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x80800110: beq         $v0, $at, L_80800120
    if (ctx->r2 == ctx->r1) {
        // 0x80800114: addiu       $at, $zero, 0x6A
        ctx->r1 = ADD32(0, 0X6A);
            goto L_80800120;
    }
    // 0x80800114: addiu       $at, $zero, 0x6A
    ctx->r1 = ADD32(0, 0X6A);
    // 0x80800118: bne         $v0, $at, L_80800130
    if (ctx->r2 != ctx->r1) {
        // 0x8080011C: nop
    
            goto L_80800130;
    }
    // 0x8080011C: nop

L_80800120:
    // 0x80800120: jal         0x80099B94
    // 0x80800124: nop

    func_80099B94(rdram, ctx);
        goto after_1;
    // 0x80800124: nop

    after_1:
    // 0x80800128: b           L_8080013C
    // 0x8080012C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080013C;
    // 0x8080012C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800130:
    // 0x80800130: jal         0x80099AA8
    // 0x80800134: nop

    func_80099AA8(rdram, ctx);
        goto after_2;
    // 0x80800134: nop

    after_2:
    // 0x80800138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080013C:
    // 0x8080013C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800140: jr          $ra
    // 0x80800144: nop

    return;
    // 0x80800144: nop

;}
RECOMP_FUNC void _chbigfoot_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086338: syscall     309
    recomp_syscall_handler(rdram, ctx, 0x80086338);
    return;
    // 0x8008633C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808012C4_bsbabykaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808012C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808012CC: jal         0x80091E6C
    // 0x808012D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80091E6C(rdram, ctx);
        goto after_0;
    // 0x808012D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808012D4: jal         0x808004B8
    // 0x808012D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bsbabykaz_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808012D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808012DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808012E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808012E4: jr          $ra
    // 0x808012E8: nop

    return;
    // 0x808012E8: nop

;}
