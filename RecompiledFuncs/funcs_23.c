#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_8010FE00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010FE00: xori        $t6, $a2, 0x2
    ctx->r14 = ctx->r6 ^ 0X2;
    // 0x8010FE04: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8010FE08: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8010FE0C: jr          $ra
    // 0x8010FE10: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    return;
    // 0x8010FE10: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void _sumultiscore_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089980: syscall     799
    recomp_syscall_handler(rdram, ctx, 0x80089980);
    return;
    // 0x80089984: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800F5F24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5F24: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5F28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F5F2C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5F30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5F34: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5F38: jal         0x8009C984
    // 0x800F5F3C: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    yaw_get(rdram, ctx);
        goto after_0;
    // 0x800F5F3C: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F5F40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5F44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F5F48: jr          $ra
    // 0x800F5F4C: nop

    return;
    // 0x800F5F4C: nop

;}
RECOMP_FUNC void _subaddieaudioloop_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089D68: syscall     810
    recomp_syscall_handler(rdram, ctx, 0x80089D68);
    return;
    // 0x80089D6C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void _gspropsDll_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088B98: syscall     727
    recomp_syscall_handler(rdram, ctx, 0x80088B98);
    return;
    // 0x80088B9C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _suquiz_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A7F8: syscall     853
    recomp_syscall_handler(rdram, ctx, 0x8008A7F8);
    return;
    // 0x8008A7FC: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void _idbounce_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088CA8: syscall     733
    recomp_syscall_handler(rdram, ctx, 0x80088CA8);
    return;
    // 0x80088CAC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800538_chconga(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800538: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080053C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800540: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800544: jal         0x800DA298
    // 0x80800548: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800548: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    after_0:
    // 0x8080054C: beq         $v0, $zero, L_80800584
    if (ctx->r2 == 0) {
        // 0x80800550: nop
    
            goto L_80800584;
    }
    // 0x80800550: nop

    // 0x80800554: jal         0x800F54E4
    // 0x80800558: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80800558: nop

    after_1:
    // 0x8080055C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800560: jal         0x800F64A4
    // 0x80800564: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F64A4(rdram, ctx);
        goto after_2;
    // 0x80800564: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800568: beq         $v0, $zero, L_80800584
    if (ctx->r2 == 0) {
        // 0x8080056C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800584;
    }
    // 0x8080056C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800570: jal         0x808004BC
    // 0x80800574: addiu       $a1, $zero, 0x1101
    ctx->r5 = ADD32(0, 0X1101);
    func_808004BC_chconga(rdram, ctx);
        goto after_3;
    // 0x80800574: addiu       $a1, $zero, 0x1101
    ctx->r5 = ADD32(0, 0X1101);
    after_3:
    // 0x80800578: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(948, 0X6FE) << 16);
    // 0x8080057C: b           L_808005DC
    // 0x80800580: sh          $v0, 0x6FE($at)
    MEM_H((int16_t)RELOC_LO16(948, 0X6FE), ctx->r1) = ctx->r2;
        goto L_808005DC;
    // 0x80800580: sh          $v0, 0x6FE($at)
    MEM_H((int16_t)RELOC_LO16(948, 0X6FE), ctx->r1) = ctx->r2;
L_80800584:
    // 0x80800584: jal         0x800D1A04
    // 0x80800588: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    func_800D1A04(rdram, ctx);
        goto after_4;
    // 0x80800588: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    after_4:
    // 0x8080058C: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80800590: bne         $at, $zero, L_808005A8
    if (ctx->r1 != 0) {
        // 0x80800594: addiu       $t7, $zero, 0x10B0
        ctx->r15 = ADD32(0, 0X10B0);
            goto L_808005A8;
    }
    // 0x80800594: addiu       $t7, $zero, 0x10B0
    ctx->r15 = ADD32(0, 0X10B0);
    // 0x80800598: addiu       $t6, $zero, 0x10B1
    ctx->r14 = ADD32(0, 0X10B1);
    // 0x8080059C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(948, 0X6FC) << 16);
    // 0x808005A0: b           L_808005B0
    // 0x808005A4: sh          $t6, 0x6FC($at)
    MEM_H((int16_t)RELOC_LO16(948, 0X6FC), ctx->r1) = ctx->r14;
        goto L_808005B0;
    // 0x808005A4: sh          $t6, 0x6FC($at)
    MEM_H((int16_t)RELOC_LO16(948, 0X6FC), ctx->r1) = ctx->r14;
L_808005A8:
    // 0x808005A8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(948, 0X6FC) << 16);
    // 0x808005AC: sh          $t7, 0x6FC($at)
    MEM_H((int16_t)RELOC_LO16(948, 0X6FC), ctx->r1) = ctx->r15;
L_808005B0:
    // 0x808005B0: jal         0x800D1A04
    // 0x808005B4: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    func_800D1A04(rdram, ctx);
        goto after_5;
    // 0x808005B4: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    after_5:
    // 0x808005B8: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x808005BC: bne         $at, $zero, L_808005D4
    if (ctx->r1 != 0) {
        // 0x808005C0: addiu       $t9, $zero, 0x10B2
        ctx->r25 = ADD32(0, 0X10B2);
            goto L_808005D4;
    }
    // 0x808005C0: addiu       $t9, $zero, 0x10B2
    ctx->r25 = ADD32(0, 0X10B2);
    // 0x808005C4: addiu       $t8, $zero, 0x10B3
    ctx->r24 = ADD32(0, 0X10B3);
    // 0x808005C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(948, 0X6FE) << 16);
    // 0x808005CC: b           L_808005DC
    // 0x808005D0: sh          $t8, 0x6FE($at)
    MEM_H((int16_t)RELOC_LO16(948, 0X6FE), ctx->r1) = ctx->r24;
        goto L_808005DC;
    // 0x808005D0: sh          $t8, 0x6FE($at)
    MEM_H((int16_t)RELOC_LO16(948, 0X6FE), ctx->r1) = ctx->r24;
L_808005D4:
    // 0x808005D4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(948, 0X6FE) << 16);
    // 0x808005D8: sh          $t9, 0x6FE($at)
    MEM_H((int16_t)RELOC_LO16(948, 0X6FE), ctx->r1) = ctx->r25;
L_808005DC:
    // 0x808005DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808005E0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(948, 0X6F8) << 16);
    // 0x808005E4: addiu       $a2, $a2, 0x6F8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(948, 0X6F8));
    // 0x808005E8: jal         0x8008A1E8
    // 0x808005EC: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddiedialog_entrypoint_7(rdram, ctx);
        goto after_6;
    // 0x808005EC: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_6:
    // 0x808005F0: addiu       $at, $zero, 0x1101
    ctx->r1 = ADD32(0, 0X1101);
    // 0x808005F4: bne         $v0, $at, L_80800608
    if (ctx->r2 != ctx->r1) {
        // 0x808005F8: addiu       $a0, $zero, 0x46E
        ctx->r4 = ADD32(0, 0X46E);
            goto L_80800608;
    }
    // 0x808005F8: addiu       $a0, $zero, 0x46E
    ctx->r4 = ADD32(0, 0X46E);
    // 0x808005FC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800600: jal         0x80101180
    // 0x80800604: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_7;
    // 0x80800604: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
L_80800608:
    // 0x80800608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080060C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800610: jr          $ra
    // 0x80800614: nop

    return;
    // 0x80800614: nop

;}
RECOMP_FUNC void subaddieaudioloop_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800108: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080010C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800110: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800114: beq         $a2, $zero, L_80800184
    if (ctx->r6 == 0) {
        // 0x80800118: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_80800184;
    }
    // 0x80800118: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8080011C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80800120: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800124: jal         0x8010D640
    // 0x80800128: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    func_8010D640(rdram, ctx);
        goto after_0;
    // 0x80800128: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_0:
    // 0x8080012C: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80800130: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800134: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80800138: bne         $a3, $at, L_80800144
    if (ctx->r7 != ctx->r1) {
        // 0x8080013C: addiu       $a0, $sp, 0x1C
        ctx->r4 = ADD32(ctx->r29, 0X1C);
            goto L_80800144;
    }
    // 0x8080013C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80800140: addiu       $a3, $zero, 0xBB8
    ctx->r7 = ADD32(0, 0XBB8);
L_80800144:
    // 0x80800144: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800148: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8080014C: jal         0x800EEB40
    // 0x80800150: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    func_800EEB40(rdram, ctx);
        goto after_1;
    // 0x80800150: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_1:
    // 0x80800154: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80800158: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8080015C: multu       $a3, $a3
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800160: mflo        $t6
    ctx->r14 = lo;
    // 0x80800164: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80800168: nop

    // 0x8080016C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800170: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80800174: nop

    // 0x80800178: bc1fl       L_80800188
    if (!c1cs) {
        // 0x8080017C: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800188;
    }
    goto skip_0;
    // 0x8080017C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_0:
    // 0x80800180: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80800184:
    // 0x80800184: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_80800188:
    // 0x80800188: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8080018C: jal         0x808000C4
    // 0x80800190: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80800190: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x80800194: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800198: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080019C: jr          $ra
    // 0x808001A0: nop

    return;
    // 0x808001A0: nop

;}
RECOMP_FUNC void _bsbtrot_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082C30: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082C30);
    return;
    // 0x80082C34: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void func_801078DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801078DC: addiu       $sp, $sp, -0x180
    ctx->r29 = ADD32(ctx->r29, -0X180);
    // 0x801078E0: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x801078E4: sw          $s7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r23;
    // 0x801078E8: sw          $s6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r22;
    // 0x801078EC: sw          $s5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r21;
    // 0x801078F0: sw          $s4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r20;
    // 0x801078F4: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x801078F8: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x801078FC: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x80107900: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x80107904: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80107908: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8010790C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80107910: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x80107914: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80107918: addiu       $t7, $sp, 0x74
    ctx->r15 = ADD32(ctx->r29, 0X74);
    // 0x8010791C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80107920: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80107924: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    // 0x80107928: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8010792C: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    // 0x80107930: jal         0x80089FA8
    // 0x80107934: sw          $t6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r14;
    _subaddievolume_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80107934: sw          $t6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r14;
    after_0:
    // 0x80107938: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x8010793C: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x80107940: blez        $v0, L_8010798C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80107944: sh          $t8, 0x0($s0)
        MEM_H(0X0, ctx->r16) = ctx->r24;
            goto L_8010798C;
    }
    // 0x80107944: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
    // 0x80107948: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    // 0x8010794C: jal         0x80103F38
    // 0x80107950: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80103F38(rdram, ctx);
        goto after_1;
    // 0x80107950: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80107954: jal         0x800B5BE4
    // 0x80107958: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    func_800B5BE4(rdram, ctx);
        goto after_2;
    // 0x80107958: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_2:
    // 0x8010795C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80107960: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80107964: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80107968: addiu       $t9, $t9, 0x4508
    ctx->r25 = ADD32(ctx->r25, 0X4508);
    // 0x8010796C: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80107970: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x80107974: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80107978: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8010797C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80107980: jal         0x800BABB8
    // 0x80107984: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_3;
    // 0x80107984: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80107988: sw          $s7, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r23;
L_8010798C:
    // 0x8010798C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80107990: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80107994: addiu       $s4, $sp, 0x84
    ctx->r20 = ADD32(ctx->r29, 0X84);
    // 0x80107998: lw          $s7, 0x78($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X78);
    // 0x8010799C: blez        $s6, L_80107A40
    if (SIGNED(ctx->r22) <= 0) {
        // 0x801079A0: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80107A40;
    }
    // 0x801079A0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801079A4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x801079A8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801079AC: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x801079B0: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x801079B4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801079B8: addiu       $s5, $s5, 0x4538
    ctx->r21 = ADD32(ctx->r21, 0X4538);
    // 0x801079BC: addiu       $s0, $sp, 0x90
    ctx->r16 = ADD32(ctx->r29, 0X90);
    // 0x801079C0: addiu       $s3, $sp, 0x5C
    ctx->r19 = ADD32(ctx->r29, 0X5C);
    // 0x801079C4: addiu       $s1, $sp, 0x68
    ctx->r17 = ADD32(ctx->r29, 0X68);
L_801079C8:
    // 0x801079C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801079CC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801079D0: jal         0x800EFB24
    // 0x801079D4: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_800EFB24(rdram, ctx);
        goto after_4;
    // 0x801079D4: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_4:
    // 0x801079D8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801079DC: jal         0x800EF368
    // 0x801079E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800EF368(rdram, ctx);
        goto after_5;
    // 0x801079E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x801079E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801079E8: jal         0x800EF04C
    // 0x801079EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EF04C(rdram, ctx);
        goto after_6;
    // 0x801079EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x801079F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801079F4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x801079F8: jal         0x800EFB24
    // 0x801079FC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800EFB24(rdram, ctx);
        goto after_7;
    // 0x801079FC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_7:
    // 0x80107A00: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80107A04: jal         0x800EF334
    // 0x80107A08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800EF334(rdram, ctx);
        goto after_8;
    // 0x80107A08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x80107A0C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80107A10: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80107A14: jal         0x800EE780
    // 0x80107A18: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800EE780(rdram, ctx);
        goto after_9;
    // 0x80107A18: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_9:
    // 0x80107A1C: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80107A20: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80107A24: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80107A28: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80107A2C: jal         0x800BABB8
    // 0x80107A30: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    func_800BABB8(rdram, ctx);
        goto after_10;
    // 0x80107A30: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    after_10:
    // 0x80107A34: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80107A38: bne         $s2, $s6, L_801079C8
    if (ctx->r18 != ctx->r22) {
        // 0x80107A3C: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_801079C8;
    }
    // 0x80107A3C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_80107A40:
    // 0x80107A40: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80107A44: slti        $v0, $s6, 0x0
    ctx->r2 = SIGNED(ctx->r22) < 0X0 ? 1 : 0;
    // 0x80107A48: lw          $s6, 0x4C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X4C);
    // 0x80107A4C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80107A50: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80107A54: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80107A58: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x80107A5C: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x80107A60: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x80107A64: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x80107A68: lw          $s4, 0x44($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X44);
    // 0x80107A6C: lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X48);
    // 0x80107A70: lw          $s7, 0x50($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X50);
    // 0x80107A74: addiu       $sp, $sp, 0x180
    ctx->r29 = ADD32(ctx->r29, 0X180);
    // 0x80107A78: jr          $ra
    // 0x80107A7C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    return;
    // 0x80107A7C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
;}
RECOMP_FUNC void func_800D8674(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8674: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800D8678: addiu       $a1, $a1, -0x4190
    ctx->r5 = ADD32(ctx->r5, -0X4190);
    // 0x800D867C: lw          $a0, 0x1A4($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X1A4);
    // 0x800D8680: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D8684: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D8688: beql        $a0, $zero, L_800D86A8
    if (ctx->r4 == 0) {
        // 0x800D868C: lw          $v1, 0x188($a1)
        ctx->r3 = MEM_W(ctx->r5, 0X188);
            goto L_800D86A8;
    }
    goto skip_0;
    // 0x800D868C: lw          $v1, 0x188($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X188);
    skip_0:
    // 0x800D8690: jal         0x8001BAFC
    // 0x800D8694: nop

    defrag(rdram, ctx);
        goto after_0;
    // 0x800D8694: nop

    after_0:
    // 0x800D8698: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800D869C: addiu       $a1, $a1, -0x4190
    ctx->r5 = ADD32(ctx->r5, -0X4190);
    // 0x800D86A0: sw          $v0, 0x1A4($a1)
    MEM_W(0X1A4, ctx->r5) = ctx->r2;
    // 0x800D86A4: lw          $v1, 0x188($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X188);
L_800D86A8:
    // 0x800D86A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D86AC: blez        $v1, L_800D86C0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800D86B0: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800D86C0;
    }
    // 0x800D86B0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800D86B4:
    // 0x800D86B4: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800D86B8: bnel        $at, $zero, L_800D86B4
    if (ctx->r1 != 0) {
        // 0x800D86BC: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800D86B4;
    }
    goto skip_1;
    // 0x800D86BC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_1:
L_800D86C0:
    // 0x800D86C0: lw          $a0, 0x19C($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X19C);
    // 0x800D86C4: beql        $a0, $zero, L_800D86E4
    if (ctx->r4 == 0) {
        // 0x800D86C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D86E4;
    }
    goto skip_2;
    // 0x800D86C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800D86CC: jal         0x8001BAFC
    // 0x800D86D0: nop

    defrag(rdram, ctx);
        goto after_1;
    // 0x800D86D0: nop

    after_1:
    // 0x800D86D4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800D86D8: addiu       $a1, $a1, -0x4190
    ctx->r5 = ADD32(ctx->r5, -0X4190);
    // 0x800D86DC: sw          $v0, 0x19C($a1)
    MEM_W(0X19C, ctx->r5) = ctx->r2;
    // 0x800D86E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D86E4:
    // 0x800D86E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D86E8: jr          $ra
    // 0x800D86EC: nop

    return;
    // 0x800D86EC: nop

;}
RECOMP_FUNC void func_808006A4_chchuffycont(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006A4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808006A8: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x808006AC: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1704, 0XB20) << 16);
    // 0x808006B0: addiu       $t7, $t7, 0xB20
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1704, 0XB20));
    // 0x808006B4: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x808006B8: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x808006BC: lh          $a1, 0x6($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X6);
    // 0x808006C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808006C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006C8: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x808006CC: beq         $v0, $zero, L_808006EC
    if (ctx->r2 == 0) {
        // 0x808006D0: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_808006EC;
    }
    // 0x808006D0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x808006D4: jal         0x800DA298
    // 0x808006D8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808006D8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x808006DC: sltu        $t8, $zero, $v0
    ctx->r24 = 0 < ctx->r2 ? 1 : 0;
    // 0x808006E0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x808006E4: beq         $t8, $zero, L_808006FC
    if (ctx->r24 == 0) {
        // 0x808006E8: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_808006FC;
    }
    // 0x808006E8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_808006EC:
    // 0x808006EC: jal         0x800DA298
    // 0x808006F0: lh          $a0, 0x2($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x808006F0: lh          $a0, 0x2($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2);
    after_1:
    // 0x808006F4: sltiu       $t9, $v0, 0x1
    ctx->r25 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x808006F8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_808006FC:
    // 0x808006FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800700: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800704: jr          $ra
    // 0x80800708: nop

    return;
    // 0x80800708: nop

;}
RECOMP_FUNC void suquiz_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080070C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800710: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800714: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800718: jal         0x800DA298
    // 0x8080071C: addiu       $a0, $zero, 0x6B6
    ctx->r4 = ADD32(0, 0X6B6);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x8080071C: addiu       $a0, $zero, 0x6B6
    ctx->r4 = ADD32(0, 0X6B6);
    after_0:
    // 0x80800720: beq         $v0, $zero, L_80800740
    if (ctx->r2 == 0) {
        // 0x80800724: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800740;
    }
    // 0x80800724: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800728: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8080072C: lw          $t6, 0x7614($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7614);
    // 0x80800730: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800734: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80800738: b           L_80800744
    // 0x8080073C: lb          $v0, 0x2A($t8)
    ctx->r2 = MEM_B(ctx->r24, 0X2A);
        goto L_80800744;
    // 0x8080073C: lb          $v0, 0x2A($t8)
    ctx->r2 = MEM_B(ctx->r24, 0X2A);
L_80800740:
    // 0x80800740: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800744:
    // 0x80800744: jr          $ra
    // 0x80800748: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800748: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void bs_getPreviousState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E710: lw          $t6, 0x120($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X120);
    // 0x8009E714: jr          $ra
    // 0x8009E718: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    return;
    // 0x8009E718: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
;}
RECOMP_FUNC void idflame_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001D8: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x808001DC: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x808001E0: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x808001E4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x808001E8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x808001EC: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x808001F0: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x808001F4: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x808001F8: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x808001FC: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80800200: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80800204: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80800208: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8080020C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800210: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    // 0x80800214: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800218: jal         0x80088890
    // 0x8080021C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    _glidmake_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x8080021C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x80800220: mtc1        $s0, $f6
    ctx->f6.u32l = ctx->r16;
    // 0x80800224: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800228: sw          $v0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r2;
    // 0x8080022C: cvt.s.w     $f30, $f6
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 6);
    ctx->f30.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800230: swc1        $f4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f4.u32l;
    // 0x80800234: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800238: addiu       $a2, $sp, 0x8C
    ctx->r6 = ADD32(ctx->r29, 0X8C);
    // 0x8080023C: addiu       $a3, $sp, 0x84
    ctx->r7 = ADD32(ctx->r29, 0X84);
    // 0x80800240: swc1        $f30, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f30.u32l;
    // 0x80800244: jal         0x80088888
    // 0x80800248: lw          $a1, 0xB4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB4);
    _glidmake_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800248: lw          $a1, 0xB4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB4);
    after_1:
    // 0x8080024C: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x80800250: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x80800254: jal         0x8001ACCC
    // 0x80800258: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    heap_alloc(rdram, ctx);
        goto after_2;
    // 0x80800258: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_2:
    // 0x8080025C: lw          $t7, 0xA0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA0);
    // 0x80800260: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2930, 0X560) << 16);
    // 0x80800264: addiu       $t0, $t0, 0x560
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(2930, 0X560));
    // 0x80800268: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8080026C: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x80800270: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80800274: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x80800278: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    // 0x8080027C: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    // 0x80800280: addiu       $a2, $a2, -0x71D8
    ctx->r6 = ADD32(ctx->r6, -0X71D8);
    // 0x80800284: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800288: lw          $a1, 0xB4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB4);
    // 0x8080028C: jal         0x80088670
    // 0x80800290: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    _glid_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800290: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_3:
    // 0x80800294: lh          $t1, 0x84($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X84);
    // 0x80800298: lh          $t2, 0x8C($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X8C);
    // 0x8080029C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2930, 0X550) << 16);
    // 0x808002A0: lwc1        $f16, 0x550($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2930, 0X550));
    // 0x808002A4: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x808002A8: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x808002AC: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2930, 0X560) << 16);
    // 0x808002B0: addiu       $t0, $t0, 0x560
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(2930, 0X560));
    // 0x808002B4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x808002B8: sb          $zero, 0xA($s2)
    MEM_B(0XA, ctx->r18) = 0;
    // 0x808002BC: lw          $s0, 0x0($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X0);
    // 0x808002C0: lw          $a1, 0x4($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X4);
    // 0x808002C4: addiu       $v0, $s0, 0x2
    ctx->r2 = ADD32(ctx->r16, 0X2);
    // 0x808002C8: mul.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x808002CC: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x808002D0: beq         $at, $zero, L_8080033C
    if (ctx->r1 == 0) {
        // 0x808002D4: nop
    
            goto L_8080033C;
    }
    // 0x808002D4: nop

    // 0x808002D8: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
L_808002DC:
    // 0x808002DC: lh          $t4, -0x2($v0)
    ctx->r12 = MEM_H(ctx->r2, -0X2);
    // 0x808002E0: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x808002E4: subu        $t5, $v1, $t4
    ctx->r13 = SUB32(ctx->r3, ctx->r12);
    // 0x808002E8: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x808002EC: nop

    // 0x808002F0: cvt.s.w     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
    // 0x808002F4: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x808002F8: nop

    // 0x808002FC: bc1tl       L_80800330
    if (c1cs) {
        // 0x80800300: sltu        $at, $v0, $a1
        ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
            goto L_80800330;
    }
    goto skip_0;
    // 0x80800300: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    skip_0:
    // 0x80800304: lbu         $a0, 0xA($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0XA);
    // 0x80800308: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x8080030C: beq         $at, $zero, L_8080032C
    if (ctx->r1 == 0) {
        // 0x80800310: sll         $t6, $a0, 1
        ctx->r14 = S32(ctx->r4 << 1);
            goto L_8080032C;
    }
    // 0x80800310: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x80800314: addu        $t7, $s2, $t6
    ctx->r15 = ADD32(ctx->r18, ctx->r14);
    // 0x80800318: sh          $v1, 0xC($t7)
    MEM_H(0XC, ctx->r15) = ctx->r3;
    // 0x8080031C: lbu         $t8, 0xA($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0XA);
    // 0x80800320: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80800324: sb          $t9, 0xA($s2)
    MEM_B(0XA, ctx->r18) = ctx->r25;
    // 0x80800328: lw          $a1, 0x4($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X4);
L_8080032C:
    // 0x8080032C: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
L_80800330:
    // 0x80800330: bnel        $at, $zero, L_808002DC
    if (ctx->r1 != 0) {
        // 0x80800334: lh          $v1, 0x0($v0)
        ctx->r3 = MEM_H(ctx->r2, 0X0);
            goto L_808002DC;
    }
    goto skip_1;
    // 0x80800334: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
    skip_1:
    // 0x80800338: lw          $s0, 0x0($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X0);
L_8080033C:
    // 0x8080033C: jal         0x8001B084
    // 0x80800340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    heap_free(rdram, ctx);
        goto after_4;
    // 0x80800340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800344: lh          $t6, 0x84($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X84);
    // 0x80800348: lh          $t7, 0x8C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X8C);
    // 0x8080034C: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2930, 0X560) << 16);
    // 0x80800350: addiu       $t0, $t0, 0x560
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(2930, 0X560));
    // 0x80800354: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80800358: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8080035C: lh          $t3, 0x86($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X86);
    // 0x80800360: lh          $t4, 0x8E($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X8E);
    // 0x80800364: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800368: sw          $zero, 0x8($t0)
    MEM_W(0X8, ctx->r8) = 0;
    // 0x8080036C: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x80800370: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x80800374: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2930, 0X554) << 16);
    // 0x80800378: lwc1        $f10, 0x554($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2930, 0X554));
    // 0x8080037C: lbu         $t9, 0xA($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0XA);
    // 0x80800380: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x80800384: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80800388: mul.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8080038C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800390: bltz        $t9, L_80800438
    if (SIGNED(ctx->r25) < 0) {
        // 0x80800394: cvt.s.w     $f14, $f4
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80800438;
    }
    // 0x80800394: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800398: mul.s       $f16, $f30, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f30.fl, ctx->f14.fl);
    // 0x8080039C: lui         $at, 0x3D00
    ctx->r1 = S32(0X3D00 << 16);
    // 0x808003A0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808003A4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808003A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808003AC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808003B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808003B4: mul.s       $f20, $f16, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x808003B8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808003BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808003C0: mul.s       $f22, $f14, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x808003C4: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
    // 0x808003C8: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x808003CC: mul.s       $f26, $f0, $f6
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f26.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808003D0: swc1        $f14, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f14.u32l;
    // 0x808003D4: add.s       $f24, $f0, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x808003D8: mul.s       $f28, $f20, $f8
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f28.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x808003DC: nop

    // 0x808003E0: lwc1        $f14, 0x9C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X9C);
L_808003E4:
    // 0x808003E4: swc1        $f30, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f30.u32l;
    // 0x808003E8: jal         0x800DC264
    // 0x808003EC: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    func_800DC264(rdram, ctx);
        goto after_5;
    // 0x808003EC: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_5:
    // 0x808003F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2930, 0X558) << 16);
    // 0x808003F4: lwc1        $f10, 0x558($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2930, 0X558));
    // 0x808003F8: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    // 0x808003FC: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x80800400: div.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80800404: jal         0x800DC264
    // 0x80800408: swc1        $f16, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f16.u32l;
    func_800DC264(rdram, ctx);
        goto after_6;
    // 0x80800408: swc1        $f16, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f16.u32l;
    after_6:
    // 0x8080040C: swc1        $f0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f0.u32l;
    // 0x80800410: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    // 0x80800414: jal         0x800DC264
    // 0x80800418: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    func_800DC264(rdram, ctx);
        goto after_7;
    // 0x80800418: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    after_7:
    // 0x8080041C: swc1        $f0, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f0.u32l;
    // 0x80800420: lbu         $t1, 0xA($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0XA);
    // 0x80800424: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800428: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8080042C: slt         $at, $t1, $s1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80800430: beql        $at, $zero, L_808003E4
    if (ctx->r1 == 0) {
        // 0x80800434: lwc1        $f14, 0x9C($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X9C);
            goto L_808003E4;
    }
    goto skip_2;
    // 0x80800434: lwc1        $f14, 0x9C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X9C);
    skip_2:
L_80800438:
    // 0x80800438: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8080043C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800440: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800444: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80800448: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8080044C: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80800450: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80800454: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80800458: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x8080045C: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80800460: jr          $ra
    // 0x80800464: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x80800464: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void baeggfire_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800654: lw          $t7, 0x6C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X6C);
    // 0x80800658: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080065C: jr          $ra
    // 0x80800660: sw          $t6, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r14;
    return;
    // 0x80800660: sw          $t6, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r14;
;}
RECOMP_FUNC void gcnewoption_entrypoint_29(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801700: lbu         $t9, 0x1D($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1D);
    // 0x80801704: sll         $t7, $a1, 3
    ctx->r15 = S32(ctx->r5 << 3);
    // 0x80801708: andi        $t8, $t7, 0x8
    ctx->r24 = ctx->r15 & 0X8;
    // 0x8080170C: andi        $t0, $t9, 0xFFF7
    ctx->r8 = ctx->r25 & 0XFFF7;
    // 0x80801710: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80801714: jr          $ra
    // 0x80801718: sb          $t1, 0x1D($a0)
    MEM_B(0X1D, ctx->r4) = ctx->r9;
    return;
    // 0x80801718: sb          $t1, 0x1D($a0)
    MEM_B(0X1D, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void _badrone_entrypoint_24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800848A8: syscall     122
    recomp_syscall_handler(rdram, ctx, 0x800848A8);
    return;
    // 0x800848AC: addi        $t0, $zero, 0x60
    ctx->r8 = ADD32(0, 0X60);
;}
RECOMP_FUNC void chdinofamilysick_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2408, 0XE60) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xE60
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2408, 0XE60));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xE60
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2408, 0XE60));
;}
RECOMP_FUNC void func_800193C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800193C4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800193C8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800193CC: addiu       $a0, $a0, -0x4350
    ctx->r4 = ADD32(ctx->r4, -0X4350);
    // 0x800193D0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800193D4: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x800193D8: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800193DC: addiu       $a3, $a3, -0x4
    ctx->r7 = ADD32(ctx->r7, -0X4);
    // 0x800193E0: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800193E4: beq         $v1, $a3, L_80019438
    if (ctx->r3 == ctx->r7) {
        // 0x800193E8: addu        $v0, $t6, $v1
        ctx->r2 = ADD32(ctx->r14, ctx->r3);
            goto L_80019438;
    }
    // 0x800193E8: addu        $v0, $t6, $v1
    ctx->r2 = ADD32(ctx->r14, ctx->r3);
L_800193EC:
    // 0x800193EC: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800193F0: lwc1        $f14, 0x4($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800193F4: lwc1        $f12, 0x10($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800193F8: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800193FC: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80019400: lwc1        $f8, 0x20($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80019404: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80019408: lwc1        $f14, 0x30($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X30);
    // 0x8001940C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80019410: mul.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80019414: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80019418: add.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x8001941C: add.s       $f8, $f12, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f8.fl;
    // 0x80019420: add.s       $f8, $f14, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x80019424: swc1        $f8, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->f8.u32l;
    // 0x80019428: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8001942C: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80019430: bne         $v1, $a3, L_800193EC
    if (ctx->r3 != ctx->r7) {
        // 0x80019434: addu        $v0, $t6, $v1
        ctx->r2 = ADD32(ctx->r14, ctx->r3);
            goto L_800193EC;
    }
    // 0x80019434: addu        $v0, $t6, $v1
    ctx->r2 = ADD32(ctx->r14, ctx->r3);
L_80019438:
    // 0x80019438: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001943C: lwc1        $f14, 0x4($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80019440: lwc1        $f12, 0x10($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80019444: mul.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80019448: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8001944C: lwc1        $f8, 0x20($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80019450: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80019454: lwc1        $f14, 0x30($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80019458: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8001945C: mul.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80019460: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80019464: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80019468: add.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x8001946C: add.s       $f8, $f12, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f8.fl;
    // 0x80019470: add.s       $f8, $f14, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x80019474: swc1        $f8, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->f8.u32l;
    // 0x80019478: jr          $ra
    // 0x8001947C: nop

    return;
    // 0x8001947C: nop

;}
RECOMP_FUNC void func_800AA274(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA274: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AA278: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AA27C: jal         0x800A9F80
    // 0x800AA280: nop

    func_800A9F80(rdram, ctx);
        goto after_0;
    // 0x800AA280: nop

    after_0:
    // 0x800AA284: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AA288: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AA28C: jr          $ra
    // 0x800AA290: nop

    return;
    // 0x800AA290: nop

    // 0x800AA294: nop

    // 0x800AA298: nop

    // 0x800AA29C: nop

;}
RECOMP_FUNC void bssub_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FF0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800FF4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(380, 0X18A0) << 16);
    // 0x80800FF8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800FFC: jr          $ra
    // 0x80801000: lw          $v0, 0x18A0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(380, 0X18A0));
    return;
    // 0x80801000: lw          $v0, 0x18A0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(380, 0X18A0));
;}
RECOMP_FUNC void func_800F5A58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5A58: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5A5C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800F5A60: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5A64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5A68: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800F5A6C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5A70: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F5A74: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x800F5A78: jal         0x800F3BB0
    // 0x800F5A7C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800F3BB0(rdram, ctx);
        goto after_0;
    // 0x800F5A7C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x800F5A80: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800F5A84: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800F5A88: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800F5A8C: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800F5A90: nop

    // 0x800F5A94: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800F5A98: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F5A9C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800F5AA0: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x800F5AA4: nop

    // 0x800F5AA8: sw          $t0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r8;
    // 0x800F5AAC: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800F5AB0: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800F5AB4: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x800F5AB8: nop

    // 0x800F5ABC: sw          $t2, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r10;
    // 0x800F5AC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5AC4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800F5AC8: jr          $ra
    // 0x800F5ACC: nop

    return;
    // 0x800F5ACC: nop

;}
RECOMP_FUNC void _chjiggygamenew_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085B30: syscall     197
    recomp_syscall_handler(rdram, ctx, 0x80085B30);
    return;
    // 0x80085B34: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_8010FAE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010FAE4: jr          $ra
    // 0x8010FAE8: lh          $v0, 0x16($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X16);
    return;
    // 0x8010FAE8: lh          $v0, 0x16($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X16);
;}
RECOMP_FUNC void func_80801080_bsbeemain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801080: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801084: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801088: jal         0x80082838
    // 0x8080108C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsbee_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080108C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801090: jal         0x800839C8
    // 0x80801094: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsrest_entrypoint_16(rdram, ctx);
        goto after_1;
    // 0x80801094: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080109C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808010A0: jr          $ra
    // 0x808010A4: nop

    return;
    // 0x808010A4: nop

;}
RECOMP_FUNC void func_80800294_baalarm(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800294: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800298: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080029C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808002A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808002A4: jal         0x800C39A0
    // 0x808002A8: lbu         $a0, 0x1B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1B);
    func_800C39A0(rdram, ctx);
        goto after_0;
    // 0x808002A8: lbu         $a0, 0x1B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1B);
    after_0:
    // 0x808002AC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x808002B0: beql        $v0, $t6, L_808002D0
    if (ctx->r2 == ctx->r14) {
        // 0x808002B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808002D0;
    }
    goto skip_0;
    // 0x808002B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808002B8: jal         0x800C3CE8
    // 0x808002BC: lbu         $a0, 0x1B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1B);
    func_800C3CE8(rdram, ctx);
        goto after_1;
    // 0x808002BC: lbu         $a0, 0x1B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1B);
    after_1:
    // 0x808002C0: lbu         $a0, 0x1B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1B);
    // 0x808002C4: jal         0x800C330C
    // 0x808002C8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800C330C(rdram, ctx);
        goto after_2;
    // 0x808002C8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x808002CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002D0:
    // 0x808002D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002D4: jr          $ra
    // 0x808002D8: nop

    return;
    // 0x808002D8: nop

;}
RECOMP_FUNC void func_80800B40_chdumbwaiterlift(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B48: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80800B4C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800B50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800B54: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x80800B58: bgezl       $t8, L_80800B88
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800B5C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800B88;
    }
    goto skip_0;
    // 0x80800B5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800B60: jal         0x800856B8
    // 0x80800B64: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    _capod_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800B64: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800B68: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800B6C: jal         0x8008A4B0
    // 0x80800B70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800B70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800B74: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800B78: lbu         $t9, 0x65($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X65);
    // 0x80800B7C: andi        $t0, $t9, 0xFFEF
    ctx->r8 = ctx->r25 & 0XFFEF;
    // 0x80800B80: sb          $t0, 0x65($a2)
    MEM_B(0X65, ctx->r6) = ctx->r8;
    // 0x80800B84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800B88:
    // 0x80800B88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B8C: jr          $ra
    // 0x80800B90: nop

    return;
    // 0x80800B90: nop

    // 0x80800B94: nop

    // 0x80800B98: nop

    // 0x80800B9C: nop

;}
RECOMP_FUNC void func_80800000_chcauldronenergybars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080000C: lhu         $t7, 0x76($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X76);
    // 0x80800010: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80800014: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x80800018: srl         $t8, $t7, 7
    ctx->r24 = S32(U32(ctx->r15) >> 7);
    // 0x8080001C: bne         $t8, $at, L_80800038
    if (ctx->r24 != ctx->r1) {
        // 0x80800020: addiu       $a1, $zero, 0x39B
        ctx->r5 = ADD32(0, 0X39B);
            goto L_80800038;
    }
    // 0x80800020: addiu       $a1, $zero, 0x39B
    ctx->r5 = ADD32(0, 0X39B);
    // 0x80800024: addiu       $t9, $zero, 0x82
    ctx->r25 = ADD32(0, 0X82);
    // 0x80800028: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8080002C: addiu       $a1, $zero, 0x39A
    ctx->r5 = ADD32(0, 0X39A);
    // 0x80800030: b           L_80800040
    // 0x80800034: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
        goto L_80800040;
    // 0x80800034: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
L_80800038:
    // 0x80800038: addiu       $t0, $zero, 0x83
    ctx->r8 = ADD32(0, 0X83);
    // 0x8080003C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
L_80800040:
    // 0x80800040: jal         0x8008A738
    // 0x80800044: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    _sujiggy_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80800044: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800048: beq         $v0, $zero, L_80800060
    if (ctx->r2 == 0) {
        // 0x8080004C: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80800060;
    }
    // 0x8080004C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800050: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800054: jal         0x800DA544
    // 0x80800058: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x80800058: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x8080005C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
L_80800060:
    // 0x80800060: jal         0x800DA298
    // 0x80800064: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800064: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x80800068: beq         $v0, $zero, L_80800080
    if (ctx->r2 == 0) {
        // 0x8080006C: nop
    
            goto L_80800080;
    }
    // 0x8080006C: nop

    // 0x80800070: jal         0x800FFAB0
    // 0x80800074: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800FFAB0(rdram, ctx);
        goto after_3;
    // 0x80800074: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80800078: b           L_808000AC
    // 0x8080007C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808000AC;
    // 0x8080007C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800080:
    // 0x80800080: jal         0x800D3E40
    // 0x80800084: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_800D3E40(rdram, ctx);
        goto after_4;
    // 0x80800084: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_4:
    // 0x80800088: beql        $v0, $zero, L_808000AC
    if (ctx->r2 == 0) {
        // 0x8080008C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808000AC;
    }
    goto skip_0;
    // 0x8080008C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800090: jal         0x80088840
    // 0x80800094: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_5;
    // 0x80800094: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_5:
    // 0x80800098: bnel        $v0, $zero, L_808000AC
    if (ctx->r2 != 0) {
        // 0x8080009C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808000AC;
    }
    goto skip_1;
    // 0x8080009C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808000A0: jal         0x800FFAB0
    // 0x808000A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800FFAB0(rdram, ctx);
        goto after_6;
    // 0x808000A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x808000A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000AC:
    // 0x808000AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000B0: jr          $ra
    // 0x808000B4: nop

    return;
    // 0x808000B4: nop

;}
RECOMP_FUNC void gcfrontend_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080034C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800350: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800354: jal         0x80800450
    // 0x80800358: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800450_gcfrontend(rdram, ctx);
        goto after_0;
    // 0x80800358: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080035C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80800360: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80800364: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2650, 0XD80) << 16);
    // 0x80800368: addiu       $t7, $t7, 0xD80
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2650, 0XD80));
    // 0x8080036C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800370: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80800374: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    // 0x80800378: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8080037C: lbu         $t1, 0x0($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X0);
    // 0x80800380: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80800384: jal         0x800DA544
    // 0x80800388: subu        $a0, $t0, $t1
    ctx->r4 = SUB32(ctx->r8, ctx->r9);
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x80800388: subu        $a0, $t0, $t1
    ctx->r4 = SUB32(ctx->r8, ctx->r9);
    after_1:
    // 0x8080038C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800390: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800394: jr          $ra
    // 0x80800398: nop

    return;
    // 0x80800398: nop

;}
RECOMP_FUNC void func_80802A2C_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802A2C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80802A30: slti        $at, $a1, 0x3
    ctx->r1 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
    // 0x80802A34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802A38: bne         $at, $zero, L_80802A90
    if (ctx->r1 != 0) {
        // 0x80802A3C: sw          $a0, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r4;
            goto L_80802A90;
    }
    // 0x80802A3C: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80802A40: slti        $at, $a1, 0x3E
    ctx->r1 = SIGNED(ctx->r5) < 0X3E ? 1 : 0;
    // 0x80802A44: bne         $at, $zero, L_80802A70
    if (ctx->r1 != 0) {
        // 0x80802A48: addiu       $t7, $a1, -0x1F
        ctx->r15 = ADD32(ctx->r5, -0X1F);
            goto L_80802A70;
    }
    // 0x80802A48: addiu       $t7, $a1, -0x1F
    ctx->r15 = ADD32(ctx->r5, -0X1F);
    // 0x80802A4C: addiu       $t6, $a1, -0x82
    ctx->r14 = ADD32(ctx->r5, -0X82);
    // 0x80802A50: sltiu       $at, $t6, 0x18
    ctx->r1 = ctx->r14 < 0X18 ? 1 : 0;
    // 0x80802A54: beq         $at, $zero, L_80803300
    if (ctx->r1 == 0) {
        // 0x80802A58: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80803300;
    }
    // 0x80802A58: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80802A5C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X6640) << 16);
    // 0x80802A60: addu        $at, $at, $t6
    gpr jr_addend_80802A68 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80802A64: lw          $t6, 0x6640($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2484, 0X6640));
    // 0x80802A68: jr          $t6
    // 0x80802A6C: nop

    switch (jr_addend_80802A68 >> 2) {
        case 0: goto L_80802C68; break;
        case 1: goto L_80802C7C; break;
        case 2: goto L_80802CA4; break;
        case 3: goto L_80802CCC; break;
        case 4: goto L_80802CF4; break;
        case 5: goto L_80802D24; break;
        case 6: goto L_80802DAC; break;
        case 7: goto L_80802DD8; break;
        case 8: goto L_80802E34; break;
        case 9: goto L_80802E5C; break;
        case 10: goto L_80803300; break;
        case 11: goto L_80803300; break;
        case 12: goto L_80803300; break;
        case 13: goto L_80803300; break;
        case 14: goto L_80803300; break;
        case 15: goto L_80803300; break;
        case 16: goto L_80803300; break;
        case 17: goto L_80803300; break;
        case 18: goto L_80803300; break;
        case 19: goto L_80802C58; break;
        case 20: goto L_80803300; break;
        case 21: goto L_80802EF4; break;
        case 22: goto L_80803300; break;
        case 23: goto L_80802C34; break;
        default: switch_error(__func__, 0x80802A68, 0x80806640);
    }
    // 0x80802A6C: nop

L_80802A70:
    // 0x80802A70: sltiu       $at, $t7, 0x1F
    ctx->r1 = ctx->r15 < 0X1F ? 1 : 0;
    // 0x80802A74: beq         $at, $zero, L_80803300
    if (ctx->r1 == 0) {
        // 0x80802A78: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80803300;
    }
    // 0x80802A78: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80802A7C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X66A0) << 16);
    // 0x80802A80: addu        $at, $at, $t7
    gpr jr_addend_80802A88 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80802A84: lw          $t7, 0x66A0($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2484, 0X66A0));
    // 0x80802A88: jr          $t7
    // 0x80802A8C: nop

    switch (jr_addend_80802A88 >> 2) {
        case 0: goto L_80802F40; break;
        case 1: goto L_80803300; break;
        case 2: goto L_80803300; break;
        case 3: goto L_80803300; break;
        case 4: goto L_80803300; break;
        case 5: goto L_80803300; break;
        case 6: goto L_80803300; break;
        case 7: goto L_80803300; break;
        case 8: goto L_80803300; break;
        case 9: goto L_80803300; break;
        case 10: goto L_80803180; break;
        case 11: goto L_808032B8; break;
        case 12: goto L_80803300; break;
        case 13: goto L_80803300; break;
        case 14: goto L_80803300; break;
        case 15: goto L_80803300; break;
        case 16: goto L_80803300; break;
        case 17: goto L_80803300; break;
        case 18: goto L_80803300; break;
        case 19: goto L_80803300; break;
        case 20: goto L_80803300; break;
        case 21: goto L_80803300; break;
        case 22: goto L_80803300; break;
        case 23: goto L_80803300; break;
        case 24: goto L_80803300; break;
        case 25: goto L_80803300; break;
        case 26: goto L_80803300; break;
        case 27: goto L_80803300; break;
        case 28: goto L_80802E84; break;
        case 29: goto L_80803300; break;
        case 30: goto L_80802AB0; break;
        default: switch_error(__func__, 0x80802A88, 0x808066A0);
    }
    // 0x80802A8C: nop

L_80802A90:
    // 0x80802A90: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80802A94: beq         $a1, $at, L_80802E98
    if (ctx->r5 == ctx->r1) {
        // 0x80802A98: lw          $t1, 0x58($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X58);
            goto L_80802E98;
    }
    // 0x80802A98: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x80802A9C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80802AA0: beq         $a1, $v0, L_80802ED4
    if (ctx->r5 == ctx->r2) {
        // 0x80802AA4: lw          $t0, 0x58($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X58);
            goto L_80802ED4;
    }
    // 0x80802AA4: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80802AA8: b           L_80803304
    // 0x80802AAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80803304;
    // 0x80802AAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80802AB0:
    // 0x80802AB0: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x80802AB4: addiu       $a0, $zero, 0x52C
    ctx->r4 = ADD32(0, 0X52C);
    // 0x80802AB8: lhu         $a1, 0x76($t8)
    ctx->r5 = MEM_HU(ctx->r24, 0X76);
    // 0x80802ABC: srl         $t9, $a1, 7
    ctx->r25 = S32(U32(ctx->r5) >> 7);
    // 0x80802AC0: jal         0x80089C78
    // 0x80802AC4: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    _subaddiefind_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x80802AC4: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_0:
    // 0x80802AC8: bne         $v0, $zero, L_80802B70
    if (ctx->r2 != 0) {
        // 0x80802ACC: sw          $v0, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r2;
            goto L_80802B70;
    }
    // 0x80802ACC: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x80802AD0: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80802AD4: addiu       $a0, $zero, 0x52C
    ctx->r4 = ADD32(0, 0X52C);
    // 0x80802AD8: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    // 0x80802ADC: lwc1        $f4, 0x48($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X48);
    // 0x80802AE0: addiu       $a1, $t0, 0x4
    ctx->r5 = ADD32(ctx->r8, 0X4);
    // 0x80802AE4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80802AE8: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80802AEC: jal         0x80108528
    // 0x80802AF0: nop

    func_80108528(rdram, ctx);
        goto after_1;
    // 0x80802AF0: nop

    after_1:
    // 0x80802AF4: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x80802AF8: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x80802AFC: addiu       $a0, $v0, 0x28
    ctx->r4 = ADD32(ctx->r2, 0X28);
    // 0x80802B00: lw          $a3, 0xC($t2)
    ctx->r7 = MEM_W(ctx->r10, 0XC);
    // 0x80802B04: lw          $a2, 0x8($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X8);
    // 0x80802B08: jal         0x800EFA4C
    // 0x80802B0C: lw          $a1, 0x4($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X4);
    func_800EFA4C(rdram, ctx);
        goto after_2;
    // 0x80802B0C: lw          $a1, 0x4($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X4);
    after_2:
    // 0x80802B10: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x80802B14: lui         $at, 0xC2A0
    ctx->r1 = S32(0XC2A0 << 16);
    // 0x80802B18: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80802B1C: lwc1        $f8, 0x8($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X8);
    // 0x80802B20: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80802B24: lw          $a1, 0x4($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X4);
    // 0x80802B28: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80802B2C: lw          $a3, 0xC($t3)
    ctx->r7 = MEM_W(ctx->r11, 0XC);
    // 0x80802B30: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80802B34: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80802B38: jal         0x800EFA4C
    // 0x80802B3C: nop

    func_800EFA4C(rdram, ctx);
        goto after_3;
    // 0x80802B3C: nop

    after_3:
    // 0x80802B40: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80802B44: jal         0x8010A800
    // 0x80802B48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8010A800(rdram, ctx);
        goto after_4;
    // 0x80802B48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80802B4C: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x80802B50: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    // 0x80802B54: lhu         $t5, 0x76($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X76);
    // 0x80802B58: lhu         $t9, 0x76($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X76);
    // 0x80802B5C: srl         $t6, $t5, 7
    ctx->r14 = S32(U32(ctx->r13) >> 7);
    // 0x80802B60: sll         $t8, $t6, 7
    ctx->r24 = S32(ctx->r14 << 7);
    // 0x80802B64: andi        $t0, $t9, 0x7F
    ctx->r8 = ctx->r25 & 0X7F;
    // 0x80802B68: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80802B6C: sh          $t1, 0x76($v0)
    MEM_H(0X76, ctx->r2) = ctx->r9;
L_80802B70:
    // 0x80802B70: jal         0x800D3948
    // 0x80802B74: nop

    func_800D3948(rdram, ctx);
        goto after_5;
    // 0x80802B74: nop

    after_5:
    // 0x80802B78: beq         $v0, $zero, L_80802B88
    if (ctx->r2 == 0) {
        // 0x80802B7C: nop
    
            goto L_80802B88;
    }
    // 0x80802B7C: nop

    // 0x80802B80: b           L_80802BC8
    // 0x80802B84: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80802BC8;
    // 0x80802B84: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80802B88:
    // 0x80802B88: jal         0x800D395C
    // 0x80802B8C: nop

    func_800D395C(rdram, ctx);
        goto after_6;
    // 0x80802B8C: nop

    after_6:
    // 0x80802B90: bnel        $v0, $zero, L_80802BB4
    if (ctx->r2 != 0) {
        // 0x80802B94: lw          $t2, 0x58($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X58);
            goto L_80802BB4;
    }
    goto skip_0;
    // 0x80802B94: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    skip_0:
    // 0x80802B98: jal         0x800DA298
    // 0x80802B9C: addiu       $a0, $zero, 0x441
    ctx->r4 = ADD32(0, 0X441);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x80802B9C: addiu       $a0, $zero, 0x441
    ctx->r4 = ADD32(0, 0X441);
    after_7:
    // 0x80802BA0: beql        $v0, $zero, L_80802BB4
    if (ctx->r2 == 0) {
        // 0x80802BA4: lw          $t2, 0x58($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X58);
            goto L_80802BB4;
    }
    goto skip_1;
    // 0x80802BA4: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    skip_1:
    // 0x80802BA8: b           L_80802BC8
    // 0x80802BAC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80802BC8;
    // 0x80802BAC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80802BB0: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
L_80802BB4:
    // 0x80802BB4: lhu         $a0, 0x76($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X76);
    // 0x80802BB8: srl         $t3, $a0, 7
    ctx->r11 = S32(U32(ctx->r4) >> 7);
    // 0x80802BBC: jal         0x8008A800
    // 0x80802BC0: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    _suquiz_entrypoint_9(rdram, ctx);
        goto after_8;
    // 0x80802BC0: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_8:
    // 0x80802BC4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80802BC8:
    // 0x80802BC8: beq         $v1, $zero, L_80802BEC
    if (ctx->r3 == 0) {
        // 0x80802BCC: lw          $t4, 0x58($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X58);
            goto L_80802BEC;
    }
    // 0x80802BCC: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x80802BD0: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80802BD4: jal         0x80102424
    // 0x80802BD8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_9;
    // 0x80802BD8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_9:
    // 0x80802BDC: jal         0x800FFAB0
    // 0x80802BE0: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_800FFAB0(rdram, ctx);
        goto after_10;
    // 0x80802BE0: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_10:
    // 0x80802BE4: b           L_80803304
    // 0x80802BE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803304;
    // 0x80802BE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802BEC:
    // 0x80802BEC: lwc1        $f18, 0x48($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X48);
    // 0x80802BF0: addiu       $a0, $zero, 0x52B
    ctx->r4 = ADD32(0, 0X52B);
    // 0x80802BF4: addiu       $a1, $t4, 0x4
    ctx->r5 = ADD32(ctx->r12, 0X4);
    // 0x80802BF8: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80802BFC: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    // 0x80802C00: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80802C04: jal         0x80108528
    // 0x80802C08: nop

    func_80108528(rdram, ctx);
        goto after_11;
    // 0x80802C08: nop

    after_11:
    // 0x80802C0C: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80802C10: lhu         $t1, 0x76($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X76);
    // 0x80802C14: lhu         $t7, 0x76($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X76);
    // 0x80802C18: andi        $t2, $t1, 0x7F
    ctx->r10 = ctx->r9 & 0X7F;
    // 0x80802C1C: srl         $t9, $t7, 7
    ctx->r25 = S32(U32(ctx->r15) >> 7);
    // 0x80802C20: sll         $t0, $t9, 7
    ctx->r8 = S32(ctx->r25 << 7);
    // 0x80802C24: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x80802C28: sh          $t3, 0x76($v0)
    MEM_H(0X76, ctx->r2) = ctx->r11;
    // 0x80802C2C: b           L_80803304
    // 0x80802C30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803304;
    // 0x80802C30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802C34:
    // 0x80802C34: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x80802C38: lhu         $a0, 0x76($t4)
    ctx->r4 = MEM_HU(ctx->r12, 0X76);
    // 0x80802C3C: srl         $t5, $a0, 7
    ctx->r13 = S32(U32(ctx->r4) >> 7);
    // 0x80802C40: jal         0x808000C4
    // 0x80802C44: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    func_808000C4_chquiz(rdram, ctx);
        goto after_12;
    // 0x80802C44: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_12:
    // 0x80802C48: jal         0x80101074
    // 0x80802C4C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80101074(rdram, ctx);
        goto after_13;
    // 0x80802C4C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_13:
    // 0x80802C50: b           L_80803304
    // 0x80802C54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803304;
    // 0x80802C54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802C58:
    // 0x80802C58: jal         0x80802250
    // 0x80802C5C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_80802250_chquiz(rdram, ctx);
        goto after_14;
    // 0x80802C5C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_14:
    // 0x80802C60: b           L_80803304
    // 0x80802C64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803304;
    // 0x80802C64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802C68:
    // 0x80802C68: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80802C6C: jal         0x80802434
    // 0x80802C70: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80802434_chquiz(rdram, ctx);
        goto after_15;
    // 0x80802C70: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_15:
    // 0x80802C74: b           L_80803304
    // 0x80802C78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803304;
    // 0x80802C78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802C7C:
    // 0x80802C7C: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80802C80: lhu         $t7, 0x76($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X76);
    // 0x80802C84: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80802C88: srl         $t9, $t7, 7
    ctx->r25 = S32(U32(ctx->r15) >> 7);
    // 0x80802C8C: beq         $a2, $t9, L_80802C9C
    if (ctx->r6 == ctx->r25) {
        // 0x80802C90: nop
    
            goto L_80802C9C;
    }
    // 0x80802C90: nop

    // 0x80802C94: jal         0x80802434
    // 0x80802C98: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80802434_chquiz(rdram, ctx);
        goto after_16;
    // 0x80802C98: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_16:
L_80802C9C:
    // 0x80802C9C: b           L_80803304
    // 0x80802CA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803304;
    // 0x80802CA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802CA4:
    // 0x80802CA4: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x80802CA8: lhu         $t1, 0x76($t8)
    ctx->r9 = MEM_HU(ctx->r24, 0X76);
    // 0x80802CAC: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80802CB0: srl         $t0, $t1, 7
    ctx->r8 = S32(U32(ctx->r9) >> 7);
    // 0x80802CB4: bne         $a2, $t0, L_80802CC4
    if (ctx->r6 != ctx->r8) {
        // 0x80802CB8: nop
    
            goto L_80802CC4;
    }
    // 0x80802CB8: nop

    // 0x80802CBC: jal         0x80802434
    // 0x80802CC0: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80802434_chquiz(rdram, ctx);
        goto after_17;
    // 0x80802CC0: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_17:
L_80802CC4:
    // 0x80802CC4: b           L_80803304
    // 0x80802CC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803304;
    // 0x80802CC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802CCC:
    // 0x80802CCC: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x80802CD0: lhu         $t3, 0x76($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X76);
    // 0x80802CD4: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x80802CD8: srl         $t4, $t3, 7
    ctx->r12 = S32(U32(ctx->r11) >> 7);
    // 0x80802CDC: bne         $a2, $t4, L_80802CEC
    if (ctx->r6 != ctx->r12) {
        // 0x80802CE0: nop
    
            goto L_80802CEC;
    }
    // 0x80802CE0: nop

    // 0x80802CE4: jal         0x80802434
    // 0x80802CE8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80802434_chquiz(rdram, ctx);
        goto after_18;
    // 0x80802CE8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_18:
L_80802CEC:
    // 0x80802CEC: b           L_80803304
    // 0x80802CF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803304;
    // 0x80802CF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802CF4:
    // 0x80802CF4: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x80802CF8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80802CFC: lhu         $v0, 0x72($t5)
    ctx->r2 = MEM_HU(ctx->r13, 0X72);
    // 0x80802D00: srl         $t7, $v0, 10
    ctx->r15 = S32(U32(ctx->r2) >> 10);
    // 0x80802D04: beq         $t7, $at, L_80802D1C
    if (ctx->r15 == ctx->r1) {
        // 0x80802D08: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_80802D1C;
    }
    // 0x80802D08: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80802D0C: beq         $t7, $at, L_80802D1C
    if (ctx->r15 == ctx->r1) {
        // 0x80802D10: or          $a0, $t5, $zero
        ctx->r4 = ctx->r13 | 0;
            goto L_80802D1C;
    }
    // 0x80802D10: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x80802D14: jal         0x80802434
    // 0x80802D18: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80802434_chquiz(rdram, ctx);
        goto after_19;
    // 0x80802D18: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_19:
L_80802D1C:
    // 0x80802D1C: b           L_80803304
    // 0x80802D20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803304;
    // 0x80802D20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802D24:
    // 0x80802D24: jal         0x800D3948
    // 0x80802D28: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    func_800D3948(rdram, ctx);
        goto after_20;
    // 0x80802D28: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    after_20:
    // 0x80802D2C: beq         $v0, $zero, L_80802D70
    if (ctx->r2 == 0) {
        // 0x80802D30: lw          $a2, 0x60($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X60);
            goto L_80802D70;
    }
    // 0x80802D30: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x80802D34: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80802D38: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x80802D3C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80802D40: lhu         $t6, 0x76($t9)
    ctx->r14 = MEM_HU(ctx->r25, 0X76);
    // 0x80802D44: srl         $t1, $t6, 7
    ctx->r9 = S32(U32(ctx->r14) >> 7);
    // 0x80802D48: bne         $a2, $t1, L_80802D60
    if (ctx->r6 != ctx->r9) {
        // 0x80802D4C: nop
    
            goto L_80802D60;
    }
    // 0x80802D4C: nop

    // 0x80802D50: jal         0x80802434
    // 0x80802D54: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_80802434_chquiz(rdram, ctx);
        goto after_21;
    // 0x80802D54: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_21:
    // 0x80802D58: b           L_80803304
    // 0x80802D5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803304;
    // 0x80802D5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802D60:
    // 0x80802D60: jal         0x80802434
    // 0x80802D64: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80802434_chquiz(rdram, ctx);
        goto after_22;
    // 0x80802D64: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_22:
    // 0x80802D68: b           L_80803304
    // 0x80802D6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803304;
    // 0x80802D6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802D70:
    // 0x80802D70: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80802D74: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80802D78: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80802D7C: lhu         $t8, 0x76($t0)
    ctx->r24 = MEM_HU(ctx->r8, 0X76);
    // 0x80802D80: srl         $t3, $t8, 7
    ctx->r11 = S32(U32(ctx->r24) >> 7);
    // 0x80802D84: bne         $a2, $t3, L_80802D9C
    if (ctx->r6 != ctx->r11) {
        // 0x80802D88: nop
    
            goto L_80802D9C;
    }
    // 0x80802D88: nop

    // 0x80802D8C: jal         0x80802434
    // 0x80802D90: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_80802434_chquiz(rdram, ctx);
        goto after_23;
    // 0x80802D90: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_23:
    // 0x80802D94: b           L_80803304
    // 0x80802D98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803304;
    // 0x80802D98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802D9C:
    // 0x80802D9C: jal         0x80802434
    // 0x80802DA0: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_80802434_chquiz(rdram, ctx);
        goto after_24;
    // 0x80802DA0: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_24:
    // 0x80802DA4: b           L_80803304
    // 0x80802DA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803304;
    // 0x80802DA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802DAC:
    // 0x80802DAC: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x80802DB0: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80802DB4: lhu         $t2, 0x72($t4)
    ctx->r10 = MEM_HU(ctx->r12, 0X72);
    // 0x80802DB8: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x80802DBC: srl         $t7, $t2, 10
    ctx->r15 = S32(U32(ctx->r10) >> 10);
    // 0x80802DC0: bne         $t7, $at, L_80802DD0
    if (ctx->r15 != ctx->r1) {
        // 0x80802DC4: nop
    
            goto L_80802DD0;
    }
    // 0x80802DC4: nop

    // 0x80802DC8: jal         0x80802434
    // 0x80802DCC: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_80802434_chquiz(rdram, ctx);
        goto after_25;
    // 0x80802DCC: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_25:
L_80802DD0:
    // 0x80802DD0: b           L_80803304
    // 0x80802DD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803304;
    // 0x80802DD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802DD8:
    // 0x80802DD8: jal         0x8008A7E8
    // 0x80802DDC: nop

    _suquiz_entrypoint_6(rdram, ctx);
        goto after_26;
    // 0x80802DDC: nop

    after_26:
    // 0x80802DE0: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x80802DE4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80802DE8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80802DEC: lhu         $t6, 0x76($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X76);
    // 0x80802DF0: srl         $t1, $t6, 7
    ctx->r9 = S32(U32(ctx->r14) >> 7);
    // 0x80802DF4: bne         $v0, $t1, L_80802E24
    if (ctx->r2 != ctx->r9) {
        // 0x80802DF8: nop
    
            goto L_80802E24;
    }
    // 0x80802DF8: nop

    // 0x80802DFC: jal         0x80802434
    // 0x80802E00: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    func_80802434_chquiz(rdram, ctx);
        goto after_27;
    // 0x80802E00: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_27:
    // 0x80802E04: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80802E08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80802E0C: lhu         $a0, 0x76($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X76);
    // 0x80802E10: srl         $t8, $a0, 7
    ctx->r24 = S32(U32(ctx->r4) >> 7);
    // 0x80802E14: jal         0x80803368
    // 0x80802E18: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_80803368_chquiz(rdram, ctx);
        goto after_28;
    // 0x80802E18: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_28:
    // 0x80802E1C: b           L_80803304
    // 0x80802E20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803304;
    // 0x80802E20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802E24:
    // 0x80802E24: jal         0x80802434
    // 0x80802E28: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80802434_chquiz(rdram, ctx);
        goto after_29;
    // 0x80802E28: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_29:
    // 0x80802E2C: b           L_80803304
    // 0x80802E30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803304;
    // 0x80802E30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802E34:
    // 0x80802E34: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x80802E38: lhu         $t0, 0x76($t3)
    ctx->r8 = MEM_HU(ctx->r11, 0X76);
    // 0x80802E3C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x80802E40: srl         $t2, $t0, 7
    ctx->r10 = S32(U32(ctx->r8) >> 7);
    // 0x80802E44: bne         $a2, $t2, L_80802E54
    if (ctx->r6 != ctx->r10) {
        // 0x80802E48: nop
    
            goto L_80802E54;
    }
    // 0x80802E48: nop

    // 0x80802E4C: jal         0x80802434
    // 0x80802E50: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80802434_chquiz(rdram, ctx);
        goto after_30;
    // 0x80802E50: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_30:
L_80802E54:
    // 0x80802E54: b           L_80803304
    // 0x80802E58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803304;
    // 0x80802E58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802E5C:
    // 0x80802E5C: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x80802E60: lhu         $t4, 0x76($t7)
    ctx->r12 = MEM_HU(ctx->r15, 0X76);
    // 0x80802E64: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80802E68: srl         $t6, $t4, 7
    ctx->r14 = S32(U32(ctx->r12) >> 7);
    // 0x80802E6C: bne         $a2, $t6, L_80802E7C
    if (ctx->r6 != ctx->r14) {
        // 0x80802E70: nop
    
            goto L_80802E7C;
    }
    // 0x80802E70: nop

    // 0x80802E74: jal         0x80802434
    // 0x80802E78: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80802434_chquiz(rdram, ctx);
        goto after_31;
    // 0x80802E78: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_31:
L_80802E7C:
    // 0x80802E7C: b           L_80803304
    // 0x80802E80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803304;
    // 0x80802E80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802E84:
    // 0x80802E84: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80802E88: jal         0x80802434
    // 0x80802E8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80802434_chquiz(rdram, ctx);
        goto after_32;
    // 0x80802E8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_32:
    // 0x80802E90: b           L_80803304
    // 0x80802E94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803304;
    // 0x80802E94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802E98:
    // 0x80802E98: lhu         $a0, 0x76($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X76);
    // 0x80802E9C: srl         $t5, $a0, 7
    ctx->r13 = S32(U32(ctx->r4) >> 7);
    // 0x80802EA0: jal         0x8008A810
    // 0x80802EA4: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    _suquiz_entrypoint_11(rdram, ctx);
        goto after_33;
    // 0x80802EA4: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_33:
    // 0x80802EA8: beq         $v0, $zero, L_80802EB8
    if (ctx->r2 == 0) {
        // 0x80802EAC: lw          $t9, 0x58($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X58);
            goto L_80802EB8;
    }
    // 0x80802EAC: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80802EB0: b           L_80803304
    // 0x80802EB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80803304;
    // 0x80802EB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80802EB8:
    // 0x80802EB8: lhu         $a0, 0x76($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X76);
    // 0x80802EBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80802EC0: srl         $t8, $a0, 7
    ctx->r24 = S32(U32(ctx->r4) >> 7);
    // 0x80802EC4: jal         0x8008A860
    // 0x80802EC8: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    _suquiz_entrypoint_21(rdram, ctx);
        goto after_34;
    // 0x80802EC8: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_34:
    // 0x80802ECC: b           L_80803304
    // 0x80802ED0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803304;
    // 0x80802ED0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802ED4:
    // 0x80802ED4: lhu         $a0, 0x76($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X76);
    // 0x80802ED8: srl         $t2, $a0, 7
    ctx->r10 = S32(U32(ctx->r4) >> 7);
    // 0x80802EDC: beq         $v0, $t2, L_80802EEC
    if (ctx->r2 == ctx->r10) {
        // 0x80802EE0: or          $a0, $t2, $zero
        ctx->r4 = ctx->r10 | 0;
            goto L_80802EEC;
    }
    // 0x80802EE0: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x80802EE4: jal         0x8008A860
    // 0x80802EE8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    _suquiz_entrypoint_21(rdram, ctx);
        goto after_35;
    // 0x80802EE8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_35:
L_80802EEC:
    // 0x80802EEC: b           L_80803304
    // 0x80802EF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803304;
    // 0x80802EF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802EF4:
    // 0x80802EF4: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x80802EF8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80802EFC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80802F00: lwc1        $f8, 0x38($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X38);
    // 0x80802F04: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80802F08: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80802F0C: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80802F10: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80802F14: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80802F18: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80802F1C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80802F20: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80802F24: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80802F28: jal         0x800EFA4C
    // 0x80802F2C: nop

    func_800EFA4C(rdram, ctx);
        goto after_36;
    // 0x80802F2C: nop

    after_36:
    // 0x80802F30: jal         0x80101010
    // 0x80802F34: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    func_80101010(rdram, ctx);
        goto after_37;
    // 0x80802F34: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    after_37:
    // 0x80802F38: b           L_80803304
    // 0x80802F3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803304;
    // 0x80802F3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802F40:
    // 0x80802F40: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80802F44: jal         0x80100094
    // 0x80802F48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_38;
    // 0x80802F48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_38:
    // 0x80802F4C: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80802F50: jal         0x801015D0
    // 0x80802F54: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_801015D0(rdram, ctx);
        goto after_39;
    // 0x80802F54: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_39:
    // 0x80802F58: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x80802F5C: lhu         $t6, 0x76($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0X76);
    // 0x80802F60: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80802F64: sltiu       $at, $t7, 0x7
    ctx->r1 = ctx->r15 < 0X7 ? 1 : 0;
    // 0x80802F68: beq         $at, $zero, L_80803084
    if (ctx->r1 == 0) {
        // 0x80802F6C: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80803084;
    }
    // 0x80802F6C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80802F70: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X671C) << 16);
    // 0x80802F74: addu        $at, $at, $t7
    gpr jr_addend_80802F7C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80802F78: lw          $t7, 0x671C($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2484, 0X671C));
    // 0x80802F7C: jr          $t7
    // 0x80802F80: nop

    switch (jr_addend_80802F7C >> 2) {
        case 0: goto L_80802FBC; break;
        case 1: goto L_80803084; break;
        case 2: goto L_80802F84; break;
        case 3: goto L_80802FD0; break;
        case 4: goto L_80802FF0; break;
        case 5: goto L_80803040; break;
        case 6: goto L_8080306C; break;
        default: switch_error(__func__, 0x80802F7C, 0x8080671C);
    }
    // 0x80802F80: nop

L_80802F84:
    // 0x80802F84: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80802F88: jal         0x800DF744
    // 0x80802F8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_40;
    // 0x80802F8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_40:
    // 0x80802F90: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80802F94: jal         0x800DF744
    // 0x80802F98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_41;
    // 0x80802F98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_41:
    // 0x80802F9C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x80802FA0: jal         0x800DF744
    // 0x80802FA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_42;
    // 0x80802FA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_42:
    // 0x80802FA8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x80802FAC: jal         0x800DF744
    // 0x80802FB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_43;
    // 0x80802FB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_43:
    // 0x80802FB4: b           L_80803088
    // 0x80802FB8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80803088;
    // 0x80802FB8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80802FBC:
    // 0x80802FBC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80802FC0: jal         0x800DF744
    // 0x80802FC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_44;
    // 0x80802FC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_44:
    // 0x80802FC8: b           L_80803088
    // 0x80802FCC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80803088;
    // 0x80802FCC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80802FD0:
    // 0x80802FD0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80802FD4: jal         0x800DF744
    // 0x80802FD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_45;
    // 0x80802FD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_45:
    // 0x80802FDC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80802FE0: jal         0x800DF744
    // 0x80802FE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_46;
    // 0x80802FE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_46:
    // 0x80802FE8: b           L_80803088
    // 0x80802FEC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80803088;
    // 0x80802FEC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80802FF0:
    // 0x80802FF0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80802FF4: jal         0x800DF744
    // 0x80802FF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_47;
    // 0x80802FF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_47:
    // 0x80802FFC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80803000: jal         0x800DF744
    // 0x80803004: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_48;
    // 0x80803004: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_48:
    // 0x80803008: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8080300C: jal         0x800DF744
    // 0x80803010: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_49;
    // 0x80803010: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_49:
    // 0x80803014: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80803018: jal         0x800DF744
    // 0x8080301C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_50;
    // 0x8080301C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_50:
    // 0x80803020: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80803024: jal         0x800DF744
    // 0x80803028: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_51;
    // 0x80803028: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_51:
    // 0x8080302C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80803030: jal         0x800DF744
    // 0x80803034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_52;
    // 0x80803034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_52:
    // 0x80803038: b           L_80803088
    // 0x8080303C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80803088;
    // 0x8080303C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80803040:
    // 0x80803040: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80803044: jal         0x800DF744
    // 0x80803048: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_53;
    // 0x80803048: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_53:
    // 0x8080304C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x80803050: jal         0x800DF744
    // 0x80803054: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_54;
    // 0x80803054: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_54:
    // 0x80803058: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x8080305C: jal         0x800DF744
    // 0x80803060: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_55;
    // 0x80803060: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_55:
    // 0x80803064: b           L_80803088
    // 0x80803068: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80803088;
    // 0x80803068: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8080306C:
    // 0x8080306C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80803070: jal         0x800DF744
    // 0x80803074: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_56;
    // 0x80803074: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_56:
    // 0x80803078: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8080307C: jal         0x800DF744
    // 0x80803080: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_57;
    // 0x80803080: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_57:
L_80803084:
    // 0x80803084: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80803088:
    // 0x80803088: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
L_8080308C:
    // 0x8080308C: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x80803090: beql        $a0, $zero, L_808030BC
    if (ctx->r4 == 0) {
        // 0x80803094: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_808030BC;
    }
    goto skip_2;
    // 0x80803094: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    skip_2:
    // 0x80803098: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8080309C: jal         0x800857B8
    // 0x808030A0: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    _chblink_entrypoint_2(rdram, ctx);
        goto after_58;
    // 0x808030A0: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_58:
    // 0x808030A4: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x808030A8: jal         0x800857C8
    // 0x808030AC: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    _chblink_entrypoint_4(rdram, ctx);
        goto after_59;
    // 0x808030AC: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    after_59:
    // 0x808030B0: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x808030B4: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x808030B8: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
L_808030BC:
    // 0x808030BC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808030C0: bne         $v1, $at, L_8080308C
    if (ctx->r3 != ctx->r1) {
        // 0x808030C4: addiu       $v0, $v0, 0x2
        ctx->r2 = ADD32(ctx->r2, 0X2);
            goto L_8080308C;
    }
    // 0x808030C4: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x808030C8: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x808030CC: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x808030D0: lhu         $t5, 0x72($t1)
    ctx->r13 = MEM_HU(ctx->r9, 0X72);
    // 0x808030D4: srl         $t9, $t5, 10
    ctx->r25 = S32(U32(ctx->r13) >> 10);
    // 0x808030D8: bne         $t9, $at, L_80803178
    if (ctx->r25 != ctx->r1) {
        // 0x808030DC: nop
    
            goto L_80803178;
    }
    // 0x808030DC: nop

    // 0x808030E0: jal         0x80106790
    // 0x808030E4: lw          $a0, 0x3C($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X3C);
    func_80106790(rdram, ctx);
        goto after_60;
    // 0x808030E4: lw          $a0, 0x3C($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X3C);
    after_60:
    // 0x808030E8: beq         $v0, $zero, L_80803100
    if (ctx->r2 == 0) {
        // 0x808030EC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80803100;
    }
    // 0x808030EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808030F0: jal         0x80101F24
    // 0x808030F4: nop

    func_80101F24(rdram, ctx);
        goto after_61;
    // 0x808030F4: nop

    after_61:
    // 0x808030F8: b           L_80803108
    // 0x808030FC: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
        goto L_80803108;
    // 0x808030FC: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
L_80803100:
    // 0x80803100: b           L_80803304
    // 0x80803104: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803304;
    // 0x80803104: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803108:
    // 0x80803108: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080310C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80803110: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X6738) << 16);
    // 0x80803114: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x80803118: nop

    // 0x8080311C: bc1f        L_80803178
    if (!c1cs) {
        // 0x80803120: nop
    
            goto L_80803178;
    }
    // 0x80803120: nop

    // 0x80803124: lwc1        $f2, 0x6738($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2484, 0X6738));
    // 0x80803128: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8080312C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80803130: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80803134: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X6740) << 16);
    // 0x80803138: bc1f        L_8080315C
    if (!c1cs) {
        // 0x8080313C: nop
    
            goto L_8080315C;
    }
    // 0x8080313C: nop

    // 0x80803140: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X673C) << 16);
    // 0x80803144: lwc1        $f4, 0x673C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2484, 0X673C));
    // 0x80803148: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8080314C: jal         0x800F10B4
    // 0x80803150: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_62;
    // 0x80803150: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_62:
    // 0x80803154: b           L_80803164
    // 0x80803158: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
        goto L_80803164;
    // 0x80803158: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
L_8080315C:
    // 0x8080315C: lwc1        $f6, 0x6740($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2484, 0X6740));
    // 0x80803160: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
L_80803164:
    // 0x80803164: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80803168: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080316C: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80803170: jal         0x800DF500
    // 0x80803174: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_800DF500(rdram, ctx);
        goto after_63;
    // 0x80803174: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_63:
L_80803178:
    // 0x80803178: b           L_80803304
    // 0x8080317C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803304;
    // 0x8080317C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803180:
    // 0x80803180: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x80803184: lhu         $t0, 0x76($t8)
    ctx->r8 = MEM_HU(ctx->r24, 0X76);
    // 0x80803188: srl         $t2, $t0, 7
    ctx->r10 = S32(U32(ctx->r8) >> 7);
    // 0x8080318C: sltiu       $at, $t2, 0x7
    ctx->r1 = ctx->r10 < 0X7 ? 1 : 0;
    // 0x80803190: beq         $at, $zero, L_808032B0
    if (ctx->r1 == 0) {
        // 0x80803194: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_808032B0;
    }
    // 0x80803194: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80803198: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X6744) << 16);
    // 0x8080319C: addu        $at, $at, $t2
    gpr jr_addend_808031A4 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x808031A0: lw          $t2, 0x6744($at)
    ctx->r10 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2484, 0X6744));
    // 0x808031A4: jr          $t2
    // 0x808031A8: nop

    switch (jr_addend_808031A4 >> 2) {
        case 0: goto L_808031AC; break;
        case 1: goto L_808031E0; break;
        case 2: goto L_808032B0; break;
        case 3: goto L_80803214; break;
        case 4: goto L_80803248; break;
        case 5: goto L_808032B0; break;
        case 6: goto L_8080327C; break;
        default: switch_error(__func__, 0x808031A4, 0x80806744);
    }
    // 0x808031A8: nop

L_808031AC:
    // 0x808031AC: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x808031B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808031B4: jal         0x800897C0
    // 0x808031B8: addiu       $a2, $zero, 0x7D
    ctx->r6 = ADD32(0, 0X7D);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_64;
    // 0x808031B8: addiu       $a2, $zero, 0x7D
    ctx->r6 = ADD32(0, 0X7D);
    after_64:
    // 0x808031BC: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x808031C0: jal         0x80100094
    // 0x808031C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_65;
    // 0x808031C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_65:
    // 0x808031C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808031CC: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x808031D0: jal         0x800897E8
    // 0x808031D4: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_66;
    // 0x808031D4: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    after_66:
    // 0x808031D8: b           L_80803304
    // 0x808031DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803304;
    // 0x808031DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808031E0:
    // 0x808031E0: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x808031E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808031E8: jal         0x800897C0
    // 0x808031EC: addiu       $a2, $zero, 0x7E
    ctx->r6 = ADD32(0, 0X7E);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_67;
    // 0x808031EC: addiu       $a2, $zero, 0x7E
    ctx->r6 = ADD32(0, 0X7E);
    after_67:
    // 0x808031F0: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x808031F4: jal         0x80100094
    // 0x808031F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_68;
    // 0x808031F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_68:
    // 0x808031FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803200: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x80803204: jal         0x800897E8
    // 0x80803208: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_69;
    // 0x80803208: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    after_69:
    // 0x8080320C: b           L_80803304
    // 0x80803210: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803304;
    // 0x80803210: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803214:
    // 0x80803214: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80803218: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080321C: jal         0x800897C0
    // 0x80803220: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_70;
    // 0x80803220: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_70:
    // 0x80803224: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80803228: jal         0x80100094
    // 0x8080322C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_71;
    // 0x8080322C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_71:
    // 0x80803230: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803234: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x80803238: jal         0x800897E8
    // 0x8080323C: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_72;
    // 0x8080323C: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    after_72:
    // 0x80803240: b           L_80803304
    // 0x80803244: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803304;
    // 0x80803244: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803248:
    // 0x80803248: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8080324C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80803250: jal         0x800897C0
    // 0x80803254: addiu       $a2, $zero, 0x6F
    ctx->r6 = ADD32(0, 0X6F);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_73;
    // 0x80803254: addiu       $a2, $zero, 0x6F
    ctx->r6 = ADD32(0, 0X6F);
    after_73:
    // 0x80803258: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8080325C: jal         0x80100094
    // 0x80803260: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_74;
    // 0x80803260: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_74:
    // 0x80803264: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803268: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x8080326C: jal         0x800897E8
    // 0x80803270: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_75;
    // 0x80803270: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    after_75:
    // 0x80803274: b           L_80803304
    // 0x80803278: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803304;
    // 0x80803278: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080327C:
    // 0x8080327C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80803280: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80803284: jal         0x800897C0
    // 0x80803288: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_76;
    // 0x80803288: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_76:
    // 0x8080328C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80803290: jal         0x80100094
    // 0x80803294: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_77;
    // 0x80803294: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_77:
    // 0x80803298: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080329C: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x808032A0: jal         0x800897E8
    // 0x808032A4: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_78;
    // 0x808032A4: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    after_78:
    // 0x808032A8: b           L_80803304
    // 0x808032AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803304;
    // 0x808032AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808032B0:
    // 0x808032B0: b           L_80803304
    // 0x808032B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80803304;
    // 0x808032B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808032B8:
    // 0x808032B8: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x808032BC: lhu         $t4, 0x76($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X76);
    // 0x808032C0: srl         $t6, $t4, 7
    ctx->r14 = S32(U32(ctx->r12) >> 7);
    // 0x808032C4: sltiu       $at, $t6, 0x7
    ctx->r1 = ctx->r14 < 0X7 ? 1 : 0;
    // 0x808032C8: beq         $at, $zero, L_808032F8
    if (ctx->r1 == 0) {
        // 0x808032CC: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_808032F8;
    }
    // 0x808032CC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808032D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X6760) << 16);
    // 0x808032D4: addu        $at, $at, $t6
    gpr jr_addend_808032DC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808032D8: lw          $t6, 0x6760($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2484, 0X6760));
    // 0x808032DC: jr          $t6
    // 0x808032E0: nop

    switch (jr_addend_808032DC >> 2) {
        case 0: goto L_808032E4; break;
        case 1: goto L_808032E4; break;
        case 2: goto L_808032F8; break;
        case 3: goto L_808032E4; break;
        case 4: goto L_808032E4; break;
        case 5: goto L_808032F8; break;
        case 6: goto L_808032E4; break;
        default: switch_error(__func__, 0x808032DC, 0x80806760);
    }
    // 0x808032E0: nop

L_808032E4:
    // 0x808032E4: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x808032E8: jal         0x800897C8
    // 0x808032EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_79;
    // 0x808032EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_79:
    // 0x808032F0: b           L_80803304
    // 0x808032F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803304;
    // 0x808032F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808032F8:
    // 0x808032F8: b           L_80803304
    // 0x808032FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80803304;
    // 0x808032FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80803300:
    // 0x80803300: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80803304:
    // 0x80803304: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80803308: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8080330C: jr          $ra
    // 0x80803310: nop

    return;
    // 0x80803310: nop

;}
RECOMP_FUNC void func_8080000C_chbonfirecavern(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800014: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x80800018: lw          $a1, 0x38($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X38);
    // 0x8080001C: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    // 0x80800020: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800024: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80800028: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x8080002C: bgez        $t7, L_80800044
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80800030: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80800044;
    }
    // 0x80800030: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800034: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800038: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080003C: nop

    // 0x80800040: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_80800044:
    // 0x80800044: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80800048: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8080004C: jal         0x80086140
    // 0x80800050: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _chfirefx_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800050: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800054: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800058: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    // 0x8080005C: jal         0x80086160
    // 0x80800060: addiu       $a2, $zero, 0xFA0
    ctx->r6 = ADD32(0, 0XFA0);
    _chfirefx_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800060: addiu       $a2, $zero, 0xFA0
    ctx->r6 = ADD32(0, 0XFA0);
    after_1:
    // 0x80800064: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800068: jal         0x80102FDC
    // 0x8080006C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80102FDC(rdram, ctx);
        goto after_2;
    // 0x8080006C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_2:
    // 0x80800070: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800074: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800078: jr          $ra
    // 0x8080007C: nop

    return;
    // 0x8080007C: nop

;}
RECOMP_FUNC void func_80800224_chfactorymagnet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "func_80800224_chfactorymagnet");
    // 0x80800224: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800228: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080022C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800230: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800234: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800238: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x8080023C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800240: sltiu       $at, $t8, 0x11
    ctx->r1 = ctx->r24 < 0X11 ? 1 : 0;
    // 0x80800244: beq         $at, $zero, L_808007EC
    if (ctx->r1 == 0) {
        // 0x80800248: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808007EC;
    }
    // 0x80800248: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8080024C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2284, 0X2860) << 16);
    // 0x80800250: addu        $at, $at, $t8
    gpr jr_addend_80800258 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800254: lw          $t8, 0x2860($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2284, 0X2860));
    // 0x80800258: jr          $t8
    // 0x8080025C: nop

    switch (jr_addend_80800258 >> 2) {
        case 0: goto L_80800260; break;
        case 1: goto L_80800284; break;
        case 2: goto L_808002C0; break;
        case 3: goto L_80800310; break;
        case 4: goto L_808003C4; break;
        case 5: goto L_80800420; break;
        case 6: goto L_80800464; break;
        case 7: goto L_80800484; break;
        case 8: goto L_808004C8; break;
        case 9: goto L_808007EC; break;
        case 10: goto L_80800518; break;
        case 11: goto L_80800598; break;
        case 12: goto L_8080062C; break;
        case 13: goto L_80800678; break;
        case 14: goto L_8080070C; break;
        case 15: goto L_8080072C; break;
        case 16: goto L_808007AC; break;
        default: switch_error(__func__, 0x80800258, 0x80802860);
    }
    // 0x8080025C: nop

L_80800260:
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800264: jal         0x808012E4
    // 0x80800268: lw          $a1, 0x2C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X2C);
    func_808012E4_chfactorymagnet(rdram, ctx);
        goto after_0;
    // 0x80800268: lw          $a1, 0x2C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X2C);
    after_0:
    // 0x8080026C: beq         $v0, $zero, L_808007EC
    if (ctx->r2 == 0) {
        // 0x80800270: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007EC;
    }
    // 0x80800270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800274: jal         0x80800898
    // 0x80800278: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800898_chfactorymagnet(rdram, ctx);
        goto after_1;
    // 0x80800278: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x8080027C: b           L_808007F0
    // 0x80800280: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
        goto L_808007F0;
    // 0x80800280: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
L_80800284:
    // 0x80800284: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x80800288: jal         0x800D91EC
    // 0x8080028C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_800D91EC(rdram, ctx);
        goto after_2;
    // 0x8080028C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_2:
    // 0x80800290: beql        $v0, $zero, L_808007F0
    if (ctx->r2 == 0) {
        // 0x80800294: lwc1        $f18, 0x34($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
            goto L_808007F0;
    }
    goto skip_0;
    // 0x80800294: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
    skip_0:
    // 0x80800298: jal         0x800DA298
    // 0x8080029C: addiu       $a0, $zero, 0x19E
    ctx->r4 = ADD32(0, 0X19E);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x8080029C: addiu       $a0, $zero, 0x19E
    ctx->r4 = ADD32(0, 0X19E);
    after_3:
    // 0x808002A0: beq         $v0, $zero, L_808002B0
    if (ctx->r2 == 0) {
        // 0x808002A4: addiu       $a1, $zero, 0x4
        ctx->r5 = ADD32(0, 0X4);
            goto L_808002B0;
    }
    // 0x808002A4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808002A8: b           L_808002B0
    // 0x808002AC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
        goto L_808002B0;
    // 0x808002AC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_808002B0:
    // 0x808002B0: jal         0x80800898
    // 0x808002B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800898_chfactorymagnet(rdram, ctx);
        goto after_4;
    // 0x808002B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808002B8: b           L_808007F0
    // 0x808002BC: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
        goto L_808007F0;
    // 0x808002BC: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
L_808002C0:
    // 0x808002C0: jal         0x8080083C
    // 0x808002C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080083C_chfactorymagnet(rdram, ctx);
        goto after_5;
    // 0x808002C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808002C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002CC: jal         0x808012E4
    // 0x808002D0: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    func_808012E4_chfactorymagnet(rdram, ctx);
        goto after_6;
    // 0x808002D0: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    after_6:
    // 0x808002D4: beq         $v0, $zero, L_808002F0
    if (ctx->r2 == 0) {
        // 0x808002D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002F0;
    }
    // 0x808002D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E0: jal         0x80800898
    // 0x808002E4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800898_chfactorymagnet(rdram, ctx);
        goto after_7;
    // 0x808002E4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_7:
    // 0x808002E8: b           L_808007F0
    // 0x808002EC: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
        goto L_808007F0;
    // 0x808002EC: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
L_808002F0:
    // 0x808002F0: jal         0x808012E4
    // 0x808002F4: lw          $a1, 0x2C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X2C);
    func_808012E4_chfactorymagnet(rdram, ctx);
        goto after_8;
    // 0x808002F4: lw          $a1, 0x2C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X2C);
    after_8:
    // 0x808002F8: bne         $v0, $zero, L_808007EC
    if (ctx->r2 != 0) {
        // 0x808002FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007EC;
    }
    // 0x808002FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800300: jal         0x80800898
    // 0x80800304: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800898_chfactorymagnet(rdram, ctx);
        goto after_9;
    // 0x80800304: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_9:
    // 0x80800308: b           L_808007F0
    // 0x8080030C: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
        goto L_808007F0;
    // 0x8080030C: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
L_80800310:
    // 0x80800310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800314: jal         0x808012E4
    // 0x80800318: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    func_808012E4_chfactorymagnet(rdram, ctx);
        goto after_10;
    // 0x80800318: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    after_10:
    // 0x8080031C: beq         $v0, $zero, L_808003AC
    if (ctx->r2 == 0) {
        // 0x80800320: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003AC;
    }
    // 0x80800320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800324: jal         0x800F54E4
    // 0x80800328: nop

    func_800F54E4(rdram, ctx);
        goto after_11;
    // 0x80800328: nop

    after_11:
    // 0x8080032C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800330: jal         0x800F5A00
    // 0x80800334: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_800F5A00(rdram, ctx);
        goto after_12;
    // 0x80800334: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_12:
    // 0x80800338: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x8080033C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800340: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80800344: jal         0x800EFB24
    // 0x80800348: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_800EFB24(rdram, ctx);
        goto after_13;
    // 0x80800348: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_13:
    // 0x8080034C: jal         0x800D90A4
    // 0x80800350: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    func_800D90A4(rdram, ctx);
        goto after_14;
    // 0x80800350: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    after_14:
    // 0x80800354: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800358: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080035C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800360: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800364: lwc1        $f12, 0x18($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80800368: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8080036C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800370: jal         0x800F10B4
    // 0x80800374: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_15;
    // 0x80800374: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_15:
    // 0x80800378: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080037C: jal         0x800EF334
    // 0x80800380: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    func_800EF334(rdram, ctx);
        goto after_16;
    // 0x80800380: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_16:
    // 0x80800384: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80800388: jal         0x800EF04C
    // 0x8080038C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800EF04C(rdram, ctx);
        goto after_17;
    // 0x8080038C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_17:
    // 0x80800390: jal         0x800F54E4
    // 0x80800394: nop

    func_800F54E4(rdram, ctx);
        goto after_18;
    // 0x80800394: nop

    after_18:
    // 0x80800398: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080039C: jal         0x800F8418
    // 0x808003A0: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_800F8418(rdram, ctx);
        goto after_19;
    // 0x808003A0: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_19:
    // 0x808003A4: b           L_808003B4
    // 0x808003A8: nop

        goto L_808003B4;
    // 0x808003A8: nop

L_808003AC:
    // 0x808003AC: jal         0x80800898
    // 0x808003B0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800898_chfactorymagnet(rdram, ctx);
        goto after_20;
    // 0x808003B0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_20:
L_808003B4:
    // 0x808003B4: jal         0x8080083C
    // 0x808003B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080083C_chfactorymagnet(rdram, ctx);
        goto after_21;
    // 0x808003B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x808003BC: b           L_808007F0
    // 0x808003C0: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
        goto L_808007F0;
    // 0x808003C0: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
L_808003C4:
    // 0x808003C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003C8: jal         0x808012E4
    // 0x808003CC: lw          $a1, 0x2C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X2C);
    func_808012E4_chfactorymagnet(rdram, ctx);
        goto after_22;
    // 0x808003CC: lw          $a1, 0x2C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X2C);
    after_22:
    // 0x808003D0: beq         $v0, $zero, L_808003E8
    if (ctx->r2 == 0) {
        // 0x808003D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003E8;
    }
    // 0x808003D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003D8: jal         0x80800898
    // 0x808003DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800898_chfactorymagnet(rdram, ctx);
        goto after_23;
    // 0x808003DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_23:
    // 0x808003E0: b           L_808007F0
    // 0x808003E4: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
        goto L_808007F0;
    // 0x808003E4: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
L_808003E8:
    // 0x808003E8: lw          $t9, 0x6C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X6C);
    // 0x808003EC: lhu         $t2, 0x6E($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X6E);
    // 0x808003F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003F4: addiu       $a1, $t9, -0x1
    ctx->r5 = ADD32(ctx->r25, -0X1);
    // 0x808003F8: andi        $t0, $a1, 0x1FF
    ctx->r8 = ctx->r5 & 0X1FF;
    // 0x808003FC: andi        $t1, $t0, 0x1FF
    ctx->r9 = ctx->r8 & 0X1FF;
    // 0x80800400: andi        $t3, $t2, 0xFE00
    ctx->r11 = ctx->r10 & 0XFE00;
    // 0x80800404: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x80800408: bne         $t0, $zero, L_808007EC
    if (ctx->r8 != 0) {
        // 0x8080040C: sh          $t4, 0x6E($s0)
        MEM_H(0X6E, ctx->r16) = ctx->r12;
            goto L_808007EC;
    }
    // 0x8080040C: sh          $t4, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r12;
    // 0x80800410: jal         0x80800898
    // 0x80800414: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800898_chfactorymagnet(rdram, ctx);
        goto after_24;
    // 0x80800414: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_24:
    // 0x80800418: b           L_808007F0
    // 0x8080041C: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
        goto L_808007F0;
    // 0x8080041C: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
L_80800420:
    // 0x80800420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800424: jal         0x808012E4
    // 0x80800428: lw          $a1, 0x2C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X2C);
    func_808012E4_chfactorymagnet(rdram, ctx);
        goto after_25;
    // 0x80800428: lw          $a1, 0x2C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X2C);
    after_25:
    // 0x8080042C: beq         $v0, $zero, L_80800444
    if (ctx->r2 == 0) {
        // 0x80800430: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800444;
    }
    // 0x80800430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800434: jal         0x80800898
    // 0x80800438: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800898_chfactorymagnet(rdram, ctx);
        goto after_26;
    // 0x80800438: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_26:
    // 0x8080043C: b           L_808007F0
    // 0x80800440: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
        goto L_808007F0;
    // 0x80800440: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
L_80800444:
    // 0x80800444: jal         0x800D90A4
    // 0x80800448: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_27;
    // 0x80800448: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_27:
    // 0x8080044C: beq         $v0, $zero, L_808007EC
    if (ctx->r2 == 0) {
        // 0x80800450: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007EC;
    }
    // 0x80800450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800454: jal         0x80800898
    // 0x80800458: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800898_chfactorymagnet(rdram, ctx);
        goto after_28;
    // 0x80800458: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_28:
    // 0x8080045C: b           L_808007F0
    // 0x80800460: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
        goto L_808007F0;
    // 0x80800460: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
L_80800464:
    // 0x80800464: jal         0x800DA298
    // 0x80800468: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    func_800DA298(rdram, ctx);
        goto after_29;
    // 0x80800468: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    after_29:
    // 0x8080046C: beq         $v0, $zero, L_808007EC
    if (ctx->r2 == 0) {
        // 0x80800470: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007EC;
    }
    // 0x80800470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800474: jal         0x80800898
    // 0x80800478: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80800898_chfactorymagnet(rdram, ctx);
        goto after_30;
    // 0x80800478: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_30:
    // 0x8080047C: b           L_808007F0
    // 0x80800480: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
        goto L_808007F0;
    // 0x80800480: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
L_80800484:
    // 0x80800484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800488: jal         0x80100094
    // 0x8080048C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_31;
    // 0x8080048C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_31:
    // 0x80800490: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80800494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800498: jal         0x80801460
    // 0x8080049C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80801460_chfactorymagnet(rdram, ctx);
        goto after_32;
    // 0x8080049C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_32:
    // 0x808004A0: jal         0x800898B0
    // 0x808004A4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    _sumumbofx_entrypoint_14(rdram, ctx);
        goto after_33;
    // 0x808004A4: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_33:
    // 0x808004A8: jal         0x80089918
    // 0x808004AC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    _sumumbofx_entrypoint_27(rdram, ctx);
        goto after_34;
    // 0x808004AC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_34:
    // 0x808004B0: beq         $v0, $zero, L_808007EC
    if (ctx->r2 == 0) {
        // 0x808004B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007EC;
    }
    // 0x808004B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004B8: jal         0x80800898
    // 0x808004BC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80800898_chfactorymagnet(rdram, ctx);
        goto after_35;
    // 0x808004BC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_35:
    // 0x808004C0: b           L_808007F0
    // 0x808004C4: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
        goto L_808007F0;
    // 0x808004C4: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
L_808004C8:
    // 0x808004C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004CC: jal         0x80100094
    // 0x808004D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_36;
    // 0x808004D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_36:
    // 0x808004D4: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x808004D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004DC: jal         0x80801460
    // 0x808004E0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80801460_chfactorymagnet(rdram, ctx);
        goto after_37;
    // 0x808004E0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_37:
    // 0x808004E4: jal         0x800898B0
    // 0x808004E8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    _sumumbofx_entrypoint_14(rdram, ctx);
        goto after_38;
    // 0x808004E8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_38:
    // 0x808004EC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808004F0: jal         0x80089868
    // 0x808004F4: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    _sumumbofx_entrypoint_5(rdram, ctx);
        goto after_39;
    // 0x808004F4: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_39:
    // 0x808004F8: jal         0x80089918
    // 0x808004FC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    _sumumbofx_entrypoint_27(rdram, ctx);
        goto after_40;
    // 0x808004FC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_40:
    // 0x80800500: beq         $v0, $zero, L_808007EC
    if (ctx->r2 == 0) {
        // 0x80800504: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007EC;
    }
    // 0x80800504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800508: jal         0x80800898
    // 0x8080050C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80800898_chfactorymagnet(rdram, ctx);
        goto after_41;
    // 0x8080050C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_41:
    // 0x80800510: b           L_808007F0
    // 0x80800514: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
        goto L_808007F0;
    // 0x80800514: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
L_80800518:
    // 0x80800518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080051C: jal         0x80100094
    // 0x80800520: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_42;
    // 0x80800520: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_42:
    // 0x80800524: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080052C: jal         0x80801460
    // 0x80800530: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80801460_chfactorymagnet(rdram, ctx);
        goto after_43;
    // 0x80800530: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_43:
    // 0x80800534: jal         0x800898B0
    // 0x80800538: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    _sumumbofx_entrypoint_14(rdram, ctx);
        goto after_44;
    // 0x80800538: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_44:
    // 0x8080053C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x80800540: jal         0x800D91EC
    // 0x80800544: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_800D91EC(rdram, ctx);
        goto after_45;
    // 0x80800544: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_45:
    // 0x80800548: jal         0x80089918
    // 0x8080054C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    _sumumbofx_entrypoint_27(rdram, ctx);
        goto after_46;
    // 0x8080054C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_46:
    // 0x80800550: beql        $v0, $zero, L_808007F0
    if (ctx->r2 == 0) {
        // 0x80800554: lwc1        $f18, 0x34($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
            goto L_808007F0;
    }
    goto skip_1;
    // 0x80800554: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
    skip_1:
    // 0x80800558: jal         0x800DA544
    // 0x8080055C: addiu       $a0, $zero, 0x9DF
    ctx->r4 = ADD32(0, 0X9DF);
    func_800DA544(rdram, ctx);
        goto after_47;
    // 0x8080055C: addiu       $a0, $zero, 0x9DF
    ctx->r4 = ADD32(0, 0X9DF);
    after_47:
    // 0x80800560: jal         0x80086B58
    // 0x80800564: nop

    _chmrtannoy_entrypoint_0(rdram, ctx);
        goto after_48;
    // 0x80800564: nop

    after_48:
    // 0x80800568: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080056C: addiu       $t5, $zero, 0xA3
    ctx->r13 = ADD32(0, 0XA3);
    // 0x80800570: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80800574: addiu       $a1, $zero, 0x1337
    ctx->r5 = ADD32(0, 0X1337);
    // 0x80800578: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8080057C: jal         0x8008A208
    // 0x80800580: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_49;
    // 0x80800580: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_49:
    // 0x80800584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800588: jal         0x80800898
    // 0x8080058C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80800898_chfactorymagnet(rdram, ctx);
        goto after_50;
    // 0x8080058C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_50:
    // 0x80800590: b           L_808007F0
    // 0x80800594: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
        goto L_808007F0;
    // 0x80800594: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
L_80800598:
    // 0x80800598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080059C: jal         0x80100094
    // 0x808005A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_51;
    // 0x808005A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_51:
    // 0x808005A4: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x808005A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005AC: jal         0x80801460
    // 0x808005B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80801460_chfactorymagnet(rdram, ctx);
        goto after_52;
    // 0x808005B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_52:
    // 0x808005B4: jal         0x800898B0
    // 0x808005B8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    _sumumbofx_entrypoint_14(rdram, ctx);
        goto after_53;
    // 0x808005B8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_53:
    // 0x808005BC: jal         0x80801368
    // 0x808005C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801368_chfactorymagnet(rdram, ctx);
        goto after_54;
    // 0x808005C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_54:
    // 0x808005C4: jal         0x800DA298
    // 0x808005C8: addiu       $a0, $zero, 0x1B8
    ctx->r4 = ADD32(0, 0X1B8);
    func_800DA298(rdram, ctx);
        goto after_55;
    // 0x808005C8: addiu       $a0, $zero, 0x1B8
    ctx->r4 = ADD32(0, 0X1B8);
    after_55:
    // 0x808005CC: bnel        $v0, $zero, L_8080061C
    if (ctx->r2 != 0) {
        // 0x808005D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080061C;
    }
    goto skip_2;
    // 0x808005D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x808005D4: jal         0x800DA298
    // 0x808005D8: addiu       $a0, $zero, 0xA06
    ctx->r4 = ADD32(0, 0XA06);
    func_800DA298(rdram, ctx);
        goto after_56;
    // 0x808005D8: addiu       $a0, $zero, 0xA06
    ctx->r4 = ADD32(0, 0XA06);
    after_56:
    // 0x808005DC: beql        $v0, $zero, L_8080061C
    if (ctx->r2 == 0) {
        // 0x808005E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080061C;
    }
    goto skip_3;
    // 0x808005E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x808005E4: jal         0x800CEAA8
    // 0x808005E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CEAA8(rdram, ctx);
        goto after_57;
    // 0x808005E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_57:
    // 0x808005EC: beql        $v0, $zero, L_808007F0
    if (ctx->r2 == 0) {
        // 0x808005F0: lwc1        $f18, 0x34($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
            goto L_808007F0;
    }
    goto skip_4;
    // 0x808005F0: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
    skip_4:
    // 0x808005F4: jal         0x800CEA84
    // 0x808005F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CEA84(rdram, ctx);
        goto after_58;
    // 0x808005F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_58:
    // 0x808005FC: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80800600: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800604: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800608: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8080060C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80800610: nop

    // 0x80800614: bc1f        L_808007EC
    if (!c1cs) {
        // 0x80800618: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007EC;
    }
    // 0x80800618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080061C:
    // 0x8080061C: jal         0x80800898
    // 0x80800620: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_80800898_chfactorymagnet(rdram, ctx);
        goto after_59;
    // 0x80800620: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_59:
    // 0x80800624: b           L_808007F0
    // 0x80800628: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
        goto L_808007F0;
    // 0x80800628: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
L_8080062C:
    // 0x8080062C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800630: jal         0x80100094
    // 0x80800634: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_60;
    // 0x80800634: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_60:
    // 0x80800638: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8080063C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800640: jal         0x80801460
    // 0x80800644: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80801460_chfactorymagnet(rdram, ctx);
        goto after_61;
    // 0x80800644: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_61:
    // 0x80800648: jal         0x800898B0
    // 0x8080064C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    _sumumbofx_entrypoint_14(rdram, ctx);
        goto after_62;
    // 0x8080064C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_62:
    // 0x80800650: jal         0x80801368
    // 0x80800654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801368_chfactorymagnet(rdram, ctx);
        goto after_63;
    // 0x80800654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_63:
    // 0x80800658: jal         0x80089918
    // 0x8080065C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    _sumumbofx_entrypoint_27(rdram, ctx);
        goto after_64;
    // 0x8080065C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_64:
    // 0x80800660: beq         $v0, $zero, L_808007EC
    if (ctx->r2 == 0) {
        // 0x80800664: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007EC;
    }
    // 0x80800664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800668: jal         0x80800898
    // 0x8080066C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_80800898_chfactorymagnet(rdram, ctx);
        goto after_65;
    // 0x8080066C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_65:
    // 0x80800670: b           L_808007F0
    // 0x80800674: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
        goto L_808007F0;
    // 0x80800674: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
L_80800678:
    // 0x80800678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080067C: jal         0x808012E4
    // 0x80800680: lw          $a1, 0x2C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X2C);
    func_808012E4_chfactorymagnet(rdram, ctx);
        goto after_66;
    // 0x80800680: lw          $a1, 0x2C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X2C);
    after_66:
    // 0x80800684: beq         $v0, $zero, L_808006C0
    if (ctx->r2 == 0) {
        // 0x80800688: nop
    
            goto L_808006C0;
    }
    // 0x80800688: nop

    // 0x8080068C: jal         0x800DA298
    // 0x80800690: addiu       $a0, $zero, 0x1B8
    ctx->r4 = ADD32(0, 0X1B8);
    func_800DA298(rdram, ctx);
        goto after_67;
    // 0x80800690: addiu       $a0, $zero, 0x1B8
    ctx->r4 = ADD32(0, 0X1B8);
    after_67:
    // 0x80800694: bne         $v0, $zero, L_808006C0
    if (ctx->r2 != 0) {
        // 0x80800698: nop
    
            goto L_808006C0;
    }
    // 0x80800698: nop

    // 0x8080069C: jal         0x800DA524
    // 0x808006A0: addiu       $a0, $zero, 0xA06
    ctx->r4 = ADD32(0, 0XA06);
    func_800DA524(rdram, ctx);
        goto after_68;
    // 0x808006A0: addiu       $a0, $zero, 0xA06
    ctx->r4 = ADD32(0, 0XA06);
    after_68:
    // 0x808006A4: jal         0x800DA524
    // 0x808006A8: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    func_800DA524(rdram, ctx);
        goto after_69;
    // 0x808006A8: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    after_69:
    // 0x808006AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006B0: jal         0x80800898
    // 0x808006B4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800898_chfactorymagnet(rdram, ctx);
        goto after_70;
    // 0x808006B4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_70:
    // 0x808006B8: b           L_808007F0
    // 0x808006BC: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
        goto L_808007F0;
    // 0x808006BC: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
L_808006C0:
    // 0x808006C0: jal         0x800D8FF8
    // 0x808006C4: nop

    func_800D8FF8(rdram, ctx);
        goto after_71;
    // 0x808006C4: nop

    after_71:
    // 0x808006C8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808006CC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808006D0: lwc1        $f16, 0x58($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808006D4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808006D8: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x808006DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006E0: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x808006E4: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    // 0x808006E8: lwc1        $f10, 0x58($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808006EC: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x808006F0: nop

    // 0x808006F4: bc1fl       L_808007F0
    if (!c1cs) {
        // 0x808006F8: lwc1        $f18, 0x34($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
            goto L_808007F0;
    }
    goto skip_5;
    // 0x808006F8: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
    skip_5:
    // 0x808006FC: jal         0x80800898
    // 0x80800700: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_80800898_chfactorymagnet(rdram, ctx);
        goto after_72;
    // 0x80800700: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_72:
    // 0x80800704: b           L_808007F0
    // 0x80800708: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
        goto L_808007F0;
    // 0x80800708: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
L_8080070C:
    // 0x8080070C: jal         0x800D90A4
    // 0x80800710: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    func_800D90A4(rdram, ctx);
        goto after_73;
    // 0x80800710: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    after_73:
    // 0x80800714: beq         $v0, $zero, L_808007EC
    if (ctx->r2 == 0) {
        // 0x80800718: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007EC;
    }
    // 0x80800718: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080071C: jal         0x80800898
    // 0x80800720: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80800898_chfactorymagnet(rdram, ctx);
        goto after_74;
    // 0x80800720: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_74:
    // 0x80800724: b           L_808007F0
    // 0x80800728: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
        goto L_808007F0;
    // 0x80800728: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
L_8080072C:
    // 0x8080072C: jal         0x800CEAA8
    // 0x80800730: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CEAA8(rdram, ctx);
        goto after_75;
    // 0x80800730: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_75:
    // 0x80800734: beq         $v0, $zero, L_80800744
    if (ctx->r2 == 0) {
        // 0x80800738: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800744;
    }
    // 0x80800738: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080073C: jal         0x800CE88C
    // 0x80800740: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CE88C(rdram, ctx);
        goto after_76;
    // 0x80800740: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_76:
L_80800744:
    // 0x80800744: jal         0x800DA298
    // 0x80800748: addiu       $a0, $zero, 0x1B8
    ctx->r4 = ADD32(0, 0X1B8);
    func_800DA298(rdram, ctx);
        goto after_77;
    // 0x80800748: addiu       $a0, $zero, 0x1B8
    ctx->r4 = ADD32(0, 0X1B8);
    after_77:
    // 0x8080074C: beq         $v0, $zero, L_80800778
    if (ctx->r2 == 0) {
        // 0x80800750: addiu       $a0, $s0, 0x58
        ctx->r4 = ADD32(ctx->r16, 0X58);
            goto L_80800778;
    }
    // 0x80800750: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x80800754: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x80800758: jal         0x800D91EC
    // 0x8080075C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_800D91EC(rdram, ctx);
        goto after_78;
    // 0x8080075C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_78:
    // 0x80800760: beq         $v0, $zero, L_80800794
    if (ctx->r2 == 0) {
        // 0x80800764: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800794;
    }
    // 0x80800764: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800768: jal         0x80800898
    // 0x8080076C: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    func_80800898_chfactorymagnet(rdram, ctx);
        goto after_79;
    // 0x8080076C: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_79:
    // 0x80800770: b           L_80800794
    // 0x80800774: nop

        goto L_80800794;
    // 0x80800774: nop

L_80800778:
    // 0x80800778: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x8080077C: jal         0x800D91EC
    // 0x80800780: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    func_800D91EC(rdram, ctx);
        goto after_80;
    // 0x80800780: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_80:
    // 0x80800784: beq         $v0, $zero, L_80800794
    if (ctx->r2 == 0) {
        // 0x80800788: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800794;
    }
    // 0x80800788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080078C: jal         0x80800898
    // 0x80800790: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800898_chfactorymagnet(rdram, ctx);
        goto after_81;
    // 0x80800790: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_81:
L_80800794:
    // 0x80800794: jal         0x800DA524
    // 0x80800798: addiu       $a0, $zero, 0xA06
    ctx->r4 = ADD32(0, 0XA06);
    func_800DA524(rdram, ctx);
        goto after_82;
    // 0x80800798: addiu       $a0, $zero, 0xA06
    ctx->r4 = ADD32(0, 0XA06);
    after_82:
    // 0x8080079C: jal         0x800DA524
    // 0x808007A0: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    func_800DA524(rdram, ctx);
        goto after_83;
    // 0x808007A0: addiu       $a0, $zero, 0x9DE
    ctx->r4 = ADD32(0, 0X9DE);
    after_83:
    // 0x808007A4: b           L_808007F0
    // 0x808007A8: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
        goto L_808007F0;
    // 0x808007A8: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
L_808007AC:
    // 0x808007AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007B0: jal         0x80103110
    // 0x808007B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_84;
    // 0x808007B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_84:
    // 0x808007B8: jal         0x800D90A4
    // 0x808007BC: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    func_800D90A4(rdram, ctx);
        goto after_85;
    // 0x808007BC: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    after_85:
    // 0x808007C0: beq         $v0, $zero, L_808007EC
    if (ctx->r2 == 0) {
        // 0x808007C4: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_808007EC;
    }
    // 0x808007C4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808007C8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808007CC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x808007D0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808007D4: jal         0x800DC178
    // 0x808007D8: nop

    func_800DC178(rdram, ctx);
        goto after_86;
    // 0x808007D8: nop

    after_86:
    // 0x808007DC: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x808007E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007E4: jal         0x80108B04
    // 0x808007E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80108B04(rdram, ctx);
        goto after_87;
    // 0x808007E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_87:
L_808007EC:
    // 0x808007EC: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
L_808007F0:
    // 0x808007F0: lwc1        $f16, 0x58($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808007F4: c.eq.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl == ctx->f16.fl;
    // 0x808007F8: nop

    // 0x808007FC: bc1t        L_80800818
    if (c1cs) {
        // 0x80800800: nop
    
            goto L_80800818;
    }
    // 0x80800800: nop

    // 0x80800804: lw          $t6, 0x3C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X3C);
    // 0x80800808: beq         $t6, $zero, L_80800818
    if (ctx->r14 == 0) {
        // 0x8080080C: nop
    
            goto L_80800818;
    }
    // 0x8080080C: nop

    // 0x80800810: jal         0x80800FE8
    // 0x80800814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800FE8_chfactorymagnet(rdram, ctx);
        goto after_88;
    // 0x80800814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_88:
L_80800818:
    // 0x80800818: jal         0x80801B74
    // 0x8080081C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801B74_chfactorymagnet(rdram, ctx);
        goto after_89;
    // 0x8080081C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_89:
    // 0x80800820: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800824: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    // 0x80800828: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080082C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800830: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80800834: jr          $ra
    // 0x80800838: nop

    return;
    // 0x80800838: nop

;}
RECOMP_FUNC void freelist_next(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3044: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800B3048: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B304C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B3050: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800B3054: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800B3058: lw          $s0, 0x0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X0);
    // 0x800B305C: lh          $t7, 0x4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X4);
    // 0x800B3060: addiu       $t2, $s0, 0x4
    ctx->r10 = ADD32(ctx->r16, 0X4);
    // 0x800B3064: bnel        $t7, $zero, L_800B3184
    if (ctx->r15 != 0) {
        // 0x800B3068: lh          $a0, 0x0($t2)
        ctx->r4 = MEM_H(ctx->r10, 0X0);
            goto L_800B3184;
    }
    goto skip_0;
    // 0x800B3068: lh          $a0, 0x0($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X0);
    skip_0:
    // 0x800B306C: lh          $t0, 0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X2);
    // 0x800B3070: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x800B3074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B3078: addiu       $a2, $t0, 0xA
    ctx->r6 = ADD32(ctx->r8, 0XA);
    // 0x800B307C: multu       $t8, $a2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B3080: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800B3084: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x800B3088: mflo        $a1
    ctx->r5 = lo;
    // 0x800B308C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800B3090: jal         0x8001B208
    // 0x800B3094: nop

    heap_realloc(rdram, ctx);
        goto after_0;
    // 0x800B3094: nop

    after_0:
    // 0x800B3098: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800B309C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800B30A0: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x800B30A4: sh          $a2, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r6;
    // 0x800B30A8: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800B30AC: addiu       $a3, $a2, -0x1
    ctx->r7 = ADD32(ctx->r6, -0X1);
    // 0x800B30B0: subu        $t1, $a3, $t0
    ctx->r9 = SUB32(ctx->r7, ctx->r8);
    // 0x800B30B4: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x800B30B8: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x800B30BC: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800B30C0: andi        $t5, $t1, 0x3
    ctx->r13 = ctx->r9 & 0X3;
    // 0x800B30C4: multu       $a3, $t3
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B30C8: slt         $at, $a3, $t0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B30CC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B30D0: or          $t2, $a1, $zero
    ctx->r10 = ctx->r5 | 0;
    // 0x800B30D4: negu        $t1, $t5
    ctx->r9 = SUB32(0, ctx->r13);
    // 0x800B30D8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800B30DC: mflo        $t4
    ctx->r12 = lo;
    // 0x800B30E0: addu        $v1, $v0, $t4
    ctx->r3 = ADD32(ctx->r2, ctx->r12);
    // 0x800B30E4: bne         $at, $zero, L_800B3180
    if (ctx->r1 != 0) {
        // 0x800B30E8: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800B3180;
    }
    // 0x800B30E8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800B30EC: beq         $t1, $zero, L_800B3118
    if (ctx->r9 == 0) {
        // 0x800B30F0: addu        $a2, $t1, $a3
        ctx->r6 = ADD32(ctx->r9, ctx->r7);
            goto L_800B3118;
    }
    // 0x800B30F0: addu        $a2, $t1, $a3
    ctx->r6 = ADD32(ctx->r9, ctx->r7);
L_800B30F4:
    // 0x800B30F4: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x800B30F8: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
    // 0x800B30FC: sh          $a0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r4;
    // 0x800B3100: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x800B3104: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800B3108: bne         $a2, $a0, L_800B30F4
    if (ctx->r6 != ctx->r4) {
        // 0x800B310C: subu        $v1, $v1, $t7
        ctx->r3 = SUB32(ctx->r3, ctx->r15);
            goto L_800B30F4;
    }
    // 0x800B310C: subu        $v1, $v1, $t7
    ctx->r3 = SUB32(ctx->r3, ctx->r15);
    // 0x800B3110: addiu       $t8, $a0, 0x1
    ctx->r24 = ADD32(ctx->r4, 0X1);
    // 0x800B3114: beq         $t8, $t0, L_800B3180
    if (ctx->r24 == ctx->r8) {
        // 0x800B3118: addiu       $a2, $t0, -0x1
        ctx->r6 = ADD32(ctx->r8, -0X1);
            goto L_800B3180;
    }
L_800B3118:
    // 0x800B3118: addiu       $a2, $t0, -0x1
    ctx->r6 = ADD32(ctx->r8, -0X1);
L_800B311C:
    // 0x800B311C: lh          $t9, 0x0($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X0);
    // 0x800B3120: addiu       $t5, $a0, -0x1
    ctx->r13 = ADD32(ctx->r4, -0X1);
    // 0x800B3124: addiu       $t8, $a0, -0x2
    ctx->r24 = ADD32(ctx->r4, -0X2);
    // 0x800B3128: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
    // 0x800B312C: sh          $a0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r4;
    // 0x800B3130: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x800B3134: lh          $t4, 0x0($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X0);
    // 0x800B3138: subu        $v1, $v1, $t3
    ctx->r3 = SUB32(ctx->r3, ctx->r11);
    // 0x800B313C: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
    // 0x800B3140: sh          $t5, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r13;
    // 0x800B3144: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x800B3148: lh          $t7, 0x0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X0);
    // 0x800B314C: addiu       $t4, $a0, -0x3
    ctx->r12 = ADD32(ctx->r4, -0X3);
    // 0x800B3150: subu        $v1, $v1, $t6
    ctx->r3 = SUB32(ctx->r3, ctx->r14);
    // 0x800B3154: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
    // 0x800B3158: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x800B315C: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x800B3160: lh          $t3, 0x0($a1)
    ctx->r11 = MEM_H(ctx->r5, 0X0);
    // 0x800B3164: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x800B3168: subu        $v1, $v1, $t9
    ctx->r3 = SUB32(ctx->r3, ctx->r25);
    // 0x800B316C: sh          $t3, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r11;
    // 0x800B3170: sh          $t4, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r12;
    // 0x800B3174: lh          $t5, 0x0($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X0);
    // 0x800B3178: bne         $a0, $a2, L_800B311C
    if (ctx->r4 != ctx->r6) {
        // 0x800B317C: subu        $v1, $v1, $t5
        ctx->r3 = SUB32(ctx->r3, ctx->r13);
            goto L_800B311C;
    }
    // 0x800B317C: subu        $v1, $v1, $t5
    ctx->r3 = SUB32(ctx->r3, ctx->r13);
L_800B3180:
    // 0x800B3180: lh          $a0, 0x0($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X0);
L_800B3184:
    // 0x800B3184: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x800B3188: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x800B318C: multu       $a0, $t6
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B3190: sw          $a0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r4;
    // 0x800B3194: mflo        $t7
    ctx->r15 = lo;
    // 0x800B3198: addu        $v0, $t2, $t7
    ctx->r2 = ADD32(ctx->r10, ctx->r15);
    // 0x800B319C: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x800B31A0: sh          $t9, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r25;
    // 0x800B31A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B31A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B31AC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800B31B0: jr          $ra
    // 0x800B31B4: nop

    return;
    // 0x800B31B4: nop

;}
RECOMP_FUNC void _bsbtrot_entrypoint_51(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082D58: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082D58);
    return;
    // 0x80082D5C: addi        $t0, $zero, 0xCC
    ctx->r8 = ADD32(0, 0XCC);
;}
RECOMP_FUNC void chmrsboggyhome_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1400, 0X1F0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x1F0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1400, 0X1F0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x1F0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1400, 0X1F0));
;}
RECOMP_FUNC void func_80800A6C_chnests(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A6C: jr          $ra
    // 0x80800A70: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800A70: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80800000_chbeanstalkseed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: lhu         $a0, 0x76($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X76);
    // 0x80800010: srl         $t7, $a0, 7
    ctx->r15 = S32(U32(ctx->r4) >> 7);
    // 0x80800014: jal         0x800DA298
    // 0x80800018: addiu       $a0, $t7, 0x33D
    ctx->r4 = ADD32(ctx->r15, 0X33D);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800018: addiu       $a0, $t7, 0x33D
    ctx->r4 = ADD32(ctx->r15, 0X33D);
    after_0:
    // 0x8080001C: beq         $v0, $zero, L_8080002C
    if (ctx->r2 == 0) {
        // 0x80800020: lw          $t8, 0x18($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X18);
            goto L_8080002C;
    }
    // 0x80800020: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80800024: jal         0x800FFA88
    // 0x80800028: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_1;
    // 0x80800028: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
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
RECOMP_FUNC void func_8010C4AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010C4AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010C4B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010C4B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8010C4B8: jal         0x800D3E40
    // 0x8010C4BC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800D3E40(rdram, ctx);
        goto after_0;
    // 0x8010C4BC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_0:
    // 0x8010C4C0: beq         $v0, $zero, L_8010C4E0
    if (ctx->r2 == 0) {
        // 0x8010C4C4: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_8010C4E0;
    }
    // 0x8010C4C4: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8010C4C8: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8010C4CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8010C4D0: lwc1        $f4, 0x24($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X24);
    // 0x8010C4D4: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8010C4D8: b           L_8010C4E8
    // 0x8010C4DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8010C4E8;
    // 0x8010C4DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010C4E0:
    // 0x8010C4E0: lwc1        $f0, 0x24($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X24);
    // 0x8010C4E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010C4E8:
    // 0x8010C4E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010C4EC: jr          $ra
    // 0x8010C4F0: nop

    return;
    // 0x8010C4F0: nop

    // 0x8010C4F4: nop

    // 0x8010C4F8: nop

    // 0x8010C4FC: nop

;}
RECOMP_FUNC void func_800A3538(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3538: lw          $t6, 0xA0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA0);
    // 0x800A353C: jr          $ra
    // 0x800A3540: sb          $a1, 0x28($t6)
    MEM_B(0X28, ctx->r14) = ctx->r5;
    return;
    // 0x800A3540: sb          $a1, 0x28($t6)
    MEM_B(0X28, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_80800388_cothemedll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800388: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080038C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800390: jal         0x800EA05C
    // 0x80800394: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800394: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800398: slti        $at, $v0, 0xCA
    ctx->r1 = SIGNED(ctx->r2) < 0XCA ? 1 : 0;
    // 0x8080039C: bne         $at, $zero, L_808003C8
    if (ctx->r1 != 0) {
        // 0x808003A0: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_808003C8;
    }
    // 0x808003A0: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x808003A4: addiu       $t6, $v0, -0x127
    ctx->r14 = ADD32(ctx->r2, -0X127);
    // 0x808003A8: sltiu       $at, $t6, 0xA
    ctx->r1 = ctx->r14 < 0XA ? 1 : 0;
    // 0x808003AC: beq         $at, $zero, L_8080044C
    if (ctx->r1 == 0) {
        // 0x808003B0: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8080044C;
    }
    // 0x808003B0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808003B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2508, 0X650) << 16);
    // 0x808003B8: addu        $at, $at, $t6
    gpr jr_addend_808003C0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808003BC: lw          $t6, 0x650($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2508, 0X650));
    // 0x808003C0: jr          $t6
    // 0x808003C4: nop

    switch (jr_addend_808003C0 >> 2) {
        case 0: goto L_80800420; break;
        case 1: goto L_8080044C; break;
        case 2: goto L_8080044C; break;
        case 3: goto L_8080044C; break;
        case 4: goto L_8080044C; break;
        case 5: goto L_8080044C; break;
        case 6: goto L_80800420; break;
        case 7: goto L_80800420; break;
        case 8: goto L_80800420; break;
        case 9: goto L_80800420; break;
        default: switch_error(__func__, 0x808003C0, 0x80800650);
    }
    // 0x808003C4: nop

L_808003C8:
    // 0x808003C8: addiu       $t7, $v0, -0xB8
    ctx->r15 = ADD32(ctx->r2, -0XB8);
    // 0x808003CC: sltiu       $at, $t7, 0x12
    ctx->r1 = ctx->r15 < 0X12 ? 1 : 0;
    // 0x808003D0: beq         $at, $zero, L_8080044C
    if (ctx->r1 == 0) {
        // 0x808003D4: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8080044C;
    }
    // 0x808003D4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808003D8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2508, 0X678) << 16);
    // 0x808003DC: addu        $at, $at, $t7
    gpr jr_addend_808003E4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808003E0: lw          $t7, 0x678($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2508, 0X678));
    // 0x808003E4: jr          $t7
    // 0x808003E8: nop

    switch (jr_addend_808003E4 >> 2) {
        case 0: goto L_808003EC; break;
        case 1: goto L_8080044C; break;
        case 2: goto L_8080044C; break;
        case 3: goto L_808003EC; break;
        case 4: goto L_8080044C; break;
        case 5: goto L_8080044C; break;
        case 6: goto L_8080044C; break;
        case 7: goto L_8080044C; break;
        case 8: goto L_8080044C; break;
        case 9: goto L_8080044C; break;
        case 10: goto L_8080044C; break;
        case 11: goto L_8080044C; break;
        case 12: goto L_8080044C; break;
        case 13: goto L_8080044C; break;
        case 14: goto L_808003EC; break;
        case 15: goto L_8080044C; break;
        case 16: goto L_808003EC; break;
        case 17: goto L_808003EC; break;
        default: switch_error(__func__, 0x808003E4, 0x80800678);
    }
    // 0x808003E8: nop

L_808003EC:
    // 0x808003EC: addiu       $t8, $v1, -0xB8
    ctx->r24 = ADD32(ctx->r3, -0XB8);
    // 0x808003F0: sltiu       $at, $t8, 0x12
    ctx->r1 = ctx->r24 < 0X12 ? 1 : 0;
    // 0x808003F4: beq         $at, $zero, L_8080044C
    if (ctx->r1 == 0) {
        // 0x808003F8: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_8080044C;
    }
    // 0x808003F8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808003FC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2508, 0X6C0) << 16);
    // 0x80800400: addu        $at, $at, $t8
    gpr jr_addend_80800408 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800404: lw          $t8, 0x6C0($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2508, 0X6C0));
    // 0x80800408: jr          $t8
    // 0x8080040C: nop

    switch (jr_addend_80800408 >> 2) {
        case 0: goto L_80800410; break;
        case 1: goto L_8080044C; break;
        case 2: goto L_8080044C; break;
        case 3: goto L_80800410; break;
        case 4: goto L_8080044C; break;
        case 5: goto L_8080044C; break;
        case 6: goto L_8080044C; break;
        case 7: goto L_8080044C; break;
        case 8: goto L_8080044C; break;
        case 9: goto L_8080044C; break;
        case 10: goto L_8080044C; break;
        case 11: goto L_8080044C; break;
        case 12: goto L_8080044C; break;
        case 13: goto L_8080044C; break;
        case 14: goto L_80800410; break;
        case 15: goto L_8080044C; break;
        case 16: goto L_80800410; break;
        case 17: goto L_80800410; break;
        default: switch_error(__func__, 0x80800408, 0x808006C0);
    }
    // 0x8080040C: nop

L_80800410:
    // 0x80800410: jal         0x800FE870
    // 0x80800414: nop

    func_800FE870(rdram, ctx);
        goto after_1;
    // 0x80800414: nop

    after_1:
    // 0x80800418: b           L_80800450
    // 0x8080041C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800450;
    // 0x8080041C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800420:
    // 0x80800420: addiu       $t9, $v1, -0x127
    ctx->r25 = ADD32(ctx->r3, -0X127);
    // 0x80800424: sltiu       $at, $t9, 0xA
    ctx->r1 = ctx->r25 < 0XA ? 1 : 0;
    // 0x80800428: beq         $at, $zero, L_8080044C
    if (ctx->r1 == 0) {
        // 0x8080042C: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_8080044C;
    }
    // 0x8080042C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80800430: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2508, 0X708) << 16);
    // 0x80800434: addu        $at, $at, $t9
    gpr jr_addend_8080043C = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80800438: lw          $t9, 0x708($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2508, 0X708));
    // 0x8080043C: jr          $t9
    // 0x80800440: nop

    switch (jr_addend_8080043C >> 2) {
        case 0: goto L_80800444; break;
        case 1: goto L_8080044C; break;
        case 2: goto L_8080044C; break;
        case 3: goto L_8080044C; break;
        case 4: goto L_8080044C; break;
        case 5: goto L_8080044C; break;
        case 6: goto L_80800444; break;
        case 7: goto L_80800444; break;
        case 8: goto L_80800444; break;
        case 9: goto L_80800444; break;
        default: switch_error(__func__, 0x8080043C, 0x80800708);
    }
    // 0x80800440: nop

L_80800444:
    // 0x80800444: jal         0x800FE870
    // 0x80800448: nop

    func_800FE870(rdram, ctx);
        goto after_2;
    // 0x80800448: nop

    after_2:
L_8080044C:
    // 0x8080044C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800450:
    // 0x80800450: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800454: jr          $ra
    // 0x80800458: nop

    return;
    // 0x80800458: nop

;}
RECOMP_FUNC void func_808002E4_chjigsawbitcont(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x808002E8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808002EC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x808002F0: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x808002F4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x808002F8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808002FC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800300: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800304: jal         0x80100094
    // 0x80800308: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800308: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080030C: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x80800310: lhu         $v1, 0x76($s4)
    ctx->r3 = MEM_HU(ctx->r20, 0X76);
    // 0x80800314: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1644, 0X9A8) << 16);
    // 0x80800318: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080031C: srl         $t6, $v1, 7
    ctx->r14 = S32(U32(ctx->r3) >> 7);
    // 0x80800320: addiu       $t8, $t6, -0x32
    ctx->r24 = ADD32(ctx->r14, -0X32);
    // 0x80800324: sll         $t0, $t8, 7
    ctx->r8 = S32(ctx->r24 << 7);
    // 0x80800328: andi        $t1, $v1, 0x7F
    ctx->r9 = ctx->r3 & 0X7F;
    // 0x8080032C: or          $t2, $t0, $t1
    ctx->r10 = ctx->r8 | ctx->r9;
    // 0x80800330: andi        $a2, $t2, 0xFFFF
    ctx->r6 = ctx->r10 & 0XFFFF;
    // 0x80800334: srl         $t3, $a2, 7
    ctx->r11 = S32(U32(ctx->r6) >> 7);
    // 0x80800338: sh          $t2, 0x76($s4)
    MEM_H(0X76, ctx->r20) = ctx->r10;
    // 0x8080033C: beq         $t3, $zero, L_80800354
    if (ctx->r11 == 0) {
        // 0x80800340: or          $a2, $t3, $zero
        ctx->r6 = ctx->r11 | 0;
            goto L_80800354;
    }
    // 0x80800340: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x80800344: jal         0x800FFAB0
    // 0x80800348: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x80800348: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_1:
    // 0x8080034C: b           L_808003F0
    // 0x80800350: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808003F0;
    // 0x80800350: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800354:
    // 0x80800354: sll         $t4, $a2, 4
    ctx->r12 = S32(ctx->r6 << 4);
    // 0x80800358: addu        $a0, $a0, $t4
    ctx->r4 = ADD32(ctx->r4, ctx->r12);
    // 0x8080035C: jal         0x800D0B68
    // 0x80800360: lh          $a0, 0x9A8($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(1644, 0X9A8));
    func_800D0B68(rdram, ctx);
        goto after_2;
    // 0x80800360: lh          $a0, 0x9A8($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(1644, 0X9A8));
    after_2:
    // 0x80800364: beq         $v0, $zero, L_8080037C
    if (ctx->r2 == 0) {
        // 0x80800368: lw          $t5, 0x48($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X48);
            goto L_8080037C;
    }
    // 0x80800368: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x8080036C: jal         0x800FFAB0
    // 0x80800370: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_3;
    // 0x80800370: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_3:
    // 0x80800374: b           L_808003F0
    // 0x80800378: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808003F0;
    // 0x80800378: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8080037C:
    // 0x8080037C: sh          $zero, 0x24($t5)
    MEM_H(0X24, ctx->r13) = 0;
    // 0x80800380: addiu       $a0, $zero, 0x312
    ctx->r4 = ADD32(0, 0X312);
    // 0x80800384: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80800388: jal         0x800882C0
    // 0x8080038C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    _gccubesearch_entrypoint_9(rdram, ctx);
        goto after_4;
    // 0x8080038C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_4:
    // 0x80800390: blez        $v0, L_808003C0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800394: lw          $s1, 0x48($sp)
        ctx->r17 = MEM_W(ctx->r29, 0X48);
            goto L_808003C0;
    }
    // 0x80800394: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x80800398: addiu       $s0, $sp, 0x4C
    ctx->r16 = ADD32(ctx->r29, 0X4C);
    // 0x8080039C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x808003A0: addu        $s3, $t7, $s0
    ctx->r19 = ADD32(ctx->r15, ctx->r16);
L_808003A4:
    // 0x808003A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808003A8: jal         0x800EE88C
    // 0x808003AC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_800EE88C(rdram, ctx);
        goto after_5;
    // 0x808003AC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_5:
    // 0x808003B0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x808003B4: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x808003B8: bne         $at, $zero, L_808003A4
    if (ctx->r1 != 0) {
        // 0x808003BC: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_808003A4;
    }
    // 0x808003BC: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
L_808003C0:
    // 0x808003C0: lhu         $t8, 0x76($s4)
    ctx->r24 = MEM_HU(ctx->r20, 0X76);
    // 0x808003C4: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1644, 0X9B4) << 16);
    // 0x808003C8: srl         $t9, $t8, 7
    ctx->r25 = S32(U32(ctx->r24) >> 7);
    // 0x808003CC: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x808003D0: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x808003D4: jal         0x800DA298
    // 0x808003D8: lh          $a0, 0x9B4($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(1644, 0X9B4));
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x808003D8: lh          $a0, 0x9B4($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(1644, 0X9B4));
    after_6:
    // 0x808003DC: beq         $v0, $zero, L_808003EC
    if (ctx->r2 == 0) {
        // 0x808003E0: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_808003EC;
    }
    // 0x808003E0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808003E4: jal         0x80108B04
    // 0x808003E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80108B04(rdram, ctx);
        goto after_7;
    // 0x808003E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
L_808003EC:
    // 0x808003EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808003F0:
    // 0x808003F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003F4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808003F8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808003FC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80800400: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800404: jr          $ra
    // 0x80800408: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80800408: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_800DC1AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DC1AC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800DC1B0: addiu       $v0, $v0, -0x380C
    ctx->r2 = ADD32(ctx->r2, -0X380C);
    // 0x800DC1B4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800DC1B8: lui         $at, 0x19
    ctx->r1 = S32(0X19 << 16);
    // 0x800DC1BC: ori         $at, $at, 0x660D
    ctx->r1 = ctx->r1 | 0X660D;
    // 0x800DC1C0: multu       $t6, $at
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r1)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800DC1C4: lui         $at, 0x3C6E
    ctx->r1 = S32(0X3C6E << 16);
    // 0x800DC1C8: ori         $at, $at, 0xF35F
    ctx->r1 = ctx->r1 | 0XF35F;
    // 0x800DC1CC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800DC1D0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800DC1D4: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800DC1D8: mflo        $t7
    ctx->r15 = lo;
    // 0x800DC1DC: addu        $t8, $t7, $at
    ctx->r24 = ADD32(ctx->r15, ctx->r1);
    // 0x800DC1E0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800DC1E4: lw          $t9, -0x465C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X465C);
    // 0x800DC1E8: lw          $t2, -0x4660($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4660);
    // 0x800DC1EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800DC1F0: and         $t1, $t9, $t8
    ctx->r9 = ctx->r25 & ctx->r24;
    // 0x800DC1F4: or          $t3, $t1, $t2
    ctx->r11 = ctx->r9 | ctx->r10;
    // 0x800DC1F8: sw          $t3, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r11;
    // 0x800DC1FC: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800DC200: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800DC204: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x800DC208: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800DC20C: jr          $ra
    // 0x800DC210: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x800DC210: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void func_80800000_chintrocam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x800EA05C
    // 0x8080000C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x8080000C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800010: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80800014: andi        $t7, $v0, 0x1FF
    ctx->r15 = ctx->r2 & 0X1FF;
    // 0x80800018: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080001C: lwc1        $f4, 0x48($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X48);
    // 0x80800020: lhu         $t8, 0x6E($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X6E);
    // 0x80800024: addiu       $a3, $zero, 0x6822
    ctx->r7 = ADD32(0, 0X6822);
    // 0x80800028: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8080002C: andi        $t9, $t8, 0xFE00
    ctx->r25 = ctx->r24 & 0XFE00;
    // 0x80800030: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x80800034: sh          $t0, 0x6E($v1)
    MEM_H(0X6E, ctx->r3) = ctx->r8;
    // 0x80800038: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8080003C: jal         0x80085708
    // 0x80800040: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x80800040: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    after_1:
    // 0x80800044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800048: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080004C: jr          $ra
    // 0x80800050: nop

    return;
    // 0x80800050: nop

;}
RECOMP_FUNC void _bafpctrl_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084CD8: syscall     133
    recomp_syscall_handler(rdram, ctx, 0x80084CD8);
    return;
    // 0x80084CDC: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void _mlspline_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800890E0: syscall     762
    recomp_syscall_handler(rdram, ctx, 0x800890E0);
    return;
    // 0x800890E4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800183D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800183D4: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x800183D8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800183DC: lui         $at, 0x4900
    ctx->r1 = S32(0X4900 << 16);
    // 0x800183E0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800183E4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800183E8: or          $t7, $a2, $zero
    ctx->r15 = ctx->r6 | 0;
    // 0x800183EC: or          $t8, $a3, $zero
    ctx->r24 = ctx->r7 | 0;
    // 0x800183F0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800183F4: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800183F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800183FC: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80018400: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80018404: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80018408: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8001840C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80018410: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80018414: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80018418: div.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8001841C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80018420: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80018424: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80018428: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8001842C: jal         0x800187B4
    // 0x80018430: nop

    func_800187B4(rdram, ctx);
        goto after_0;
    // 0x80018430: nop

    after_0:
    // 0x80018434: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80018438: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001843C: jr          $ra
    // 0x80018440: nop

    return;
    // 0x80018440: nop

;}
RECOMP_FUNC void func_800A8BD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8BD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A8BD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A8BDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A8BE0: bltz        $a1, L_800A8BF8
    if (SIGNED(ctx->r5) < 0) {
        // 0x800A8BE4: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_800A8BF8;
    }
    // 0x800A8BE4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800A8BE8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A8BEC: addiu       $v0, $v0, 0x7670
    ctx->r2 = ADD32(ctx->r2, 0X7670);
    // 0x800A8BF0: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x800A8BF4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_800A8BF8:
    // 0x800A8BF8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A8BFC: addiu       $v0, $v0, 0x7670
    ctx->r2 = ADD32(ctx->r2, 0X7670);
    // 0x800A8C00: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x800A8C04: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x800A8C08: bltzl       $a0, L_800A8C48
    if (SIGNED(ctx->r4) < 0) {
        // 0x800A8C0C: addiu       $t0, $a0, 0x1
        ctx->r8 = ADD32(ctx->r4, 0X1);
            goto L_800A8C48;
    }
    goto skip_0;
    // 0x800A8C0C: addiu       $t0, $a0, 0x1
    ctx->r8 = ADD32(ctx->r4, 0X1);
    skip_0:
    // 0x800A8C10: multu       $a0, $a2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A8C14: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A8C18: addiu       $v1, $v1, 0x7688
    ctx->r3 = ADD32(ctx->r3, 0X7688);
    // 0x800A8C1C: mflo        $t7
    ctx->r15 = lo;
    // 0x800A8C20: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x800A8C24: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x800A8C28: beql        $t9, $zero, L_800A8C48
    if (ctx->r25 == 0) {
        // 0x800A8C2C: addiu       $t0, $a0, 0x1
        ctx->r8 = ADD32(ctx->r4, 0X1);
            goto L_800A8C48;
    }
    goto skip_1;
    // 0x800A8C2C: addiu       $t0, $a0, 0x1
    ctx->r8 = ADD32(ctx->r4, 0X1);
    skip_1:
    // 0x800A8C30: jal         0x800C5668
    // 0x800A8C34: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800C5668(rdram, ctx);
        goto after_0;
    // 0x800A8C34: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x800A8C38: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A8C3C: addiu       $v0, $v0, 0x7670
    ctx->r2 = ADD32(ctx->r2, 0X7670);
    // 0x800A8C40: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x800A8C44: addiu       $t0, $a0, 0x1
    ctx->r8 = ADD32(ctx->r4, 0X1);
L_800A8C48:
    // 0x800A8C48: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A8C4C: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x800A8C50: addiu       $v1, $v1, 0x7688
    ctx->r3 = ADD32(ctx->r3, 0X7688);
    // 0x800A8C54: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x800A8C58: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800A8C5C: beq         $at, $zero, L_800A8C90
    if (ctx->r1 == 0) {
        // 0x800A8C60: or          $a0, $t0, $zero
        ctx->r4 = ctx->r8 | 0;
            goto L_800A8C90;
    }
    // 0x800A8C60: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_800A8C64:
    // 0x800A8C64: multu       $a0, $a2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A8C68: addiu       $t4, $a0, 0x1
    ctx->r12 = ADD32(ctx->r4, 0X1);
    // 0x800A8C6C: slti        $at, $t4, 0x4
    ctx->r1 = SIGNED(ctx->r12) < 0X4 ? 1 : 0;
    // 0x800A8C70: mflo        $t1
    ctx->r9 = lo;
    // 0x800A8C74: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x800A8C78: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800A8C7C: bnel        $t3, $zero, L_800A8C94
    if (ctx->r11 != 0) {
        // 0x800A8C80: slti        $at, $a0, 0x4
        ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
            goto L_800A8C94;
    }
    goto skip_2;
    // 0x800A8C80: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    skip_2:
    // 0x800A8C84: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800A8C88: bne         $at, $zero, L_800A8C64
    if (ctx->r1 != 0) {
        // 0x800A8C8C: or          $a0, $t4, $zero
        ctx->r4 = ctx->r12 | 0;
            goto L_800A8C64;
    }
    // 0x800A8C8C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
L_800A8C90:
    // 0x800A8C90: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
L_800A8C94:
    // 0x800A8C94: bne         $at, $zero, L_800A8CA4
    if (ctx->r1 != 0) {
        // 0x800A8C98: nop
    
            goto L_800A8CA4;
    }
    // 0x800A8C98: nop

    // 0x800A8C9C: b           L_800A8CBC
    // 0x800A8CA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A8CBC;
    // 0x800A8CA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800A8CA4:
    // 0x800A8CA4: jal         0x800A89BC
    // 0x800A8CA8: nop

    func_800A89BC(rdram, ctx);
        goto after_1;
    // 0x800A8CA8: nop

    after_1:
    // 0x800A8CAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800A8CB0: jal         0x800A8B24
    // 0x800A8CB4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800A8B24(rdram, ctx);
        goto after_2;
    // 0x800A8CB4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x800A8CB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800A8CBC:
    // 0x800A8CBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A8CC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A8CC4: jr          $ra
    // 0x800A8CC8: nop

    return;
    // 0x800A8CC8: nop

;}
RECOMP_FUNC void func_800E7EF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E7EF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E7EF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E7EFC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800E7F00: lui         $t7, 0xE900
    ctx->r15 = S32(0XE900 << 16);
    // 0x800E7F04: lui         $t9, 0xDF00
    ctx->r25 = S32(0XDF00 << 16);
    // 0x800E7F08: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800E7F0C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800E7F10: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800E7F14: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800E7F18: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800E7F1C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800E7F20: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800E7F24: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800E7F28: jal         0x800A9800
    // 0x800E7F2C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    func_800A9800(rdram, ctx);
        goto after_0;
    // 0x800E7F2C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    after_0:
    // 0x800E7F30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E7F34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E7F38: jr          $ra
    // 0x800E7F3C: nop

    return;
    // 0x800E7F3C: nop

;}
