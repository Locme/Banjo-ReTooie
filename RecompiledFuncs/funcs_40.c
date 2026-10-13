#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800F15C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F15C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800F15C8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800F15CC: beq         $a1, $zero, L_800F15F0
    if (ctx->r5 == 0) {
        // 0x800F15D0: andi        $t6, $a1, 0x1
        ctx->r14 = ctx->r5 & 0X1;
            goto L_800F15F0;
    }
L_800F15D0:
    // 0x800F15D0: andi        $t6, $a1, 0x1
    ctx->r14 = ctx->r5 & 0X1;
    // 0x800F15D4: beq         $t6, $zero, L_800F15E4
    if (ctx->r14 == 0) {
        // 0x800F15D8: sra         $t7, $a1, 1
        ctx->r15 = S32(SIGNED(ctx->r5) >> 1);
            goto L_800F15E4;
    }
    // 0x800F15D8: sra         $t7, $a1, 1
    ctx->r15 = S32(SIGNED(ctx->r5) >> 1);
    // 0x800F15DC: mul.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x800F15E0: nop

L_800F15E4:
    // 0x800F15E4: mul.s       $f12, $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800F15E8: bne         $t7, $zero, L_800F15D0
    if (ctx->r15 != 0) {
        // 0x800F15EC: or          $a1, $t7, $zero
        ctx->r5 = ctx->r15 | 0;
            goto L_800F15D0;
    }
    // 0x800F15EC: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
L_800F15F0:
    // 0x800F15F0: jr          $ra
    // 0x800F15F4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x800F15F4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void chbonfirecavern_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1108, 0X200) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x200
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1108, 0X200));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x200
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1108, 0X200));
;}
RECOMP_FUNC void func_80800558_chfactorybattery(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800558: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080055C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800560: jal         0x80800678
    // 0x80800564: nop

    func_80800678_chfactorybattery(rdram, ctx);
        goto after_0;
    // 0x80800564: nop

    after_0:
    // 0x80800568: jal         0x800DA298
    // 0x8080056C: addiu       $a0, $v0, 0x1B1
    ctx->r4 = ADD32(ctx->r2, 0X1B1);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x8080056C: addiu       $a0, $v0, 0x1B1
    ctx->r4 = ADD32(ctx->r2, 0X1B1);
    after_1:
    // 0x80800570: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800574: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800578: jr          $ra
    // 0x8080057C: nop

    return;
    // 0x8080057C: nop

;}
RECOMP_FUNC void func_80800000_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x8009EF1C
    // 0x8080000C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    bastick_getZonePosition(rdram, ctx);
        goto after_0;
    // 0x8080000C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800010: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80800014: jal         0x8009EF10
    // 0x80800018: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bastick_getZone(rdram, ctx);
        goto after_1;
    // 0x80800018: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8080001C: bne         $v0, $zero, L_80800038
    if (ctx->r2 != 0) {
        // 0x80800020: lwc1        $f12, 0x1C($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_80800038;
    }
    // 0x80800020: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800024: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800028: jal         0x8009B9B0
    // 0x8080002C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x8080002C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800030: b           L_80800058
    // 0x80800034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800058;
    // 0x80800034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800038:
    // 0x80800038: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8080003C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800040: jal         0x800F1214
    // 0x80800044: lui         $a2, 0x4461
    ctx->r6 = S32(0X4461 << 16);
    func_800F1214(rdram, ctx);
        goto after_3;
    // 0x80800044: lui         $a2, 0x4461
    ctx->r6 = S32(0X4461 << 16);
    after_3:
    // 0x80800048: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080004C: jal         0x8009B9B0
    // 0x80800050: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x80800050: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80800054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800058:
    // 0x80800058: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080005C: jr          $ra
    // 0x80800060: nop

    return;
    // 0x80800060: nop

;}
RECOMP_FUNC void _bsdronefalldie_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083098: syscall     41
    recomp_syscall_handler(rdram, ctx, 0x80083098);
    return;
    // 0x8008309C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800E1540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E1540: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E1544: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800E1548: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E154C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800E1550: addiu       $a1, $a1, -0x3070
    ctx->r5 = ADD32(ctx->r5, -0X3070);
    // 0x800E1554: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800E1558: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800E155C:
    // 0x800E155C: lbu         $t6, 0x74($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X74);
    // 0x800E1560: beql        $v0, $t6, L_800E157C
    if (ctx->r2 == ctx->r14) {
        // 0x800E1564: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_800E157C;
    }
    goto skip_0;
    // 0x800E1564: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    skip_0:
    // 0x800E1568: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800E156C: slti        $at, $v1, 0xA
    ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x800E1570: bne         $at, $zero, L_800E155C
    if (ctx->r1 != 0) {
        // 0x800E1574: addiu       $a1, $a1, 0x7C
        ctx->r5 = ADD32(ctx->r5, 0X7C);
            goto L_800E155C;
    }
    // 0x800E1574: addiu       $a1, $a1, 0x7C
    ctx->r5 = ADD32(ctx->r5, 0X7C);
    // 0x800E1578: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
L_800E157C:
    // 0x800E157C: bne         $v1, $at, L_800E15A8
    if (ctx->r3 != ctx->r1) {
        // 0x800E1580: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800E15A8;
    }
    // 0x800E1580: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800E1584: jal         0x800DC128
    // 0x800E1588: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_800DC128(rdram, ctx);
        goto after_0;
    // 0x800E1588: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_0:
    // 0x800E158C: sll         $t7, $v0, 5
    ctx->r15 = S32(ctx->r2 << 5);
    // 0x800E1590: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x800E1594: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800E1598: addiu       $t8, $t8, -0x3070
    ctx->r24 = ADD32(ctx->r24, -0X3070);
    // 0x800E159C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800E15A0: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x800E15A4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800E15A8:
    // 0x800E15A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E15AC: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x800E15B0: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800E15B4: sb          $t0, 0x74($a1)
    MEM_B(0X74, ctx->r5) = ctx->r8;
    // 0x800E15B8: sb          $zero, 0x77($a1)
    MEM_B(0X77, ctx->r5) = 0;
    // 0x800E15BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E15C0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800E15C4: jr          $ra
    // 0x800E15C8: sb          $t9, 0x75($a1)
    MEM_B(0X75, ctx->r5) = ctx->r25;
    return;
    // 0x800E15C8: sb          $t9, 0x75($a1)
    MEM_B(0X75, ctx->r5) = ctx->r25;
;}
RECOMP_FUNC void _bsbabykaz_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082818: syscall     14
    recomp_syscall_handler(rdram, ctx, 0x80082818);
    return;
    // 0x8008281C: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void _chgoldsnakehead_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085968: syscall     183
    recomp_syscall_handler(rdram, ctx, 0x80085968);
    return;
    // 0x8008596C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _chcamwaypoint_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085B00: syscall     195
    recomp_syscall_handler(rdram, ctx, 0x80085B00);
    return;
    // 0x80085B04: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800420_bstaxi(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800420: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800424: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800428: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080042C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800430: jal         0x8009C128
    // 0x80800434: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x80800434: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80800438: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8080043C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800440: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800448: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8080044C: jal         0x80084768
    // 0x80800450: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    _bapackctrl_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800450: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80800454: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080045C: jal         0x80084780
    // 0x80800460: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _bapackctrl_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80800460: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800464: lui         $a2, 0x3FE6
    ctx->r6 = S32(0X3FE6 << 16);
    // 0x80800468: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x8080046C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800470: addiu       $a1, $zero, 0x5C2
    ctx->r5 = ADD32(0, 0X5C2);
    // 0x80800474: jal         0x8009DB04
    // 0x80800478: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    func_8009DB04(rdram, ctx);
        goto after_3;
    // 0x80800478: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    after_3:
    // 0x8080047C: jal         0x8009C984
    // 0x80800480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_4;
    // 0x80800480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800484: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800488: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080048C: jal         0x800CB598
    // 0x80800490: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800CB598(rdram, ctx);
        goto after_5;
    // 0x80800490: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_5:
    // 0x80800494: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800498: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080049C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808004A0: jr          $ra
    // 0x808004A4: nop

    return;
    // 0x808004A4: nop

;}
RECOMP_FUNC void _baboost_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084588: syscall     115
    recomp_syscall_handler(rdram, ctx, 0x80084588);
    return;
    // 0x8008458C: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void func_808004C4_chnastycavemen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004C4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808004C8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808004CC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x808004D0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x808004D4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808004D8: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808004DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808004E0: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808004E4: slti        $at, $t7, 0x5
    ctx->r1 = SIGNED(ctx->r15) < 0X5 ? 1 : 0;
    // 0x808004E8: bnel        $at, $zero, L_80800668
    if (ctx->r1 != 0) {
        // 0x808004EC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800668;
    }
    goto skip_0;
    // 0x808004EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x808004F0: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x808004F4: lh          $t9, 0x10($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X10);
    // 0x808004F8: beql        $t9, $zero, L_80800668
    if (ctx->r25 == 0) {
        // 0x808004FC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800668;
    }
    goto skip_1;
    // 0x808004FC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x80800500: jal         0x80100094
    // 0x80800504: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800504: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800508: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8080050C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800510: jal         0x8010262C
    // 0x80800514: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_8010262C(rdram, ctx);
        goto after_1;
    // 0x80800514: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_1:
    // 0x80800518: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8080051C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800520: addiu       $a1, $s2, 0x18
    ctx->r5 = ADD32(ctx->r18, 0X18);
    // 0x80800524: jal         0x800EFB24
    // 0x80800528: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    func_800EFB24(rdram, ctx);
        goto after_2;
    // 0x80800528: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_2:
    // 0x8080052C: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80800530: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800534: jal         0x800EF334
    // 0x80800538: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    func_800EF334(rdram, ctx);
        goto after_3;
    // 0x80800538: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_3:
    // 0x8080053C: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800540: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800544: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800548: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8080054C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800550: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80800554: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x80800558: jal         0x800E0C20
    // 0x8080055C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800E0C20(rdram, ctx);
        goto after_4;
    // 0x8080055C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x80800560: lwc1        $f12, 0x24($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X24);
    // 0x80800564: jal         0x800F1DCC
    // 0x80800568: lwc1        $f14, 0x44($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X44);
    func_800F1DCC(rdram, ctx);
        goto after_5;
    // 0x80800568: lwc1        $f14, 0x44($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X44);
    after_5:
    // 0x8080056C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80800570: lwc1        $f14, 0x48($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800574: jal         0x800F1DCC
    // 0x80800578: lwc1        $f12, 0x28($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X28);
    func_800F1DCC(rdram, ctx);
        goto after_6;
    // 0x80800578: lwc1        $f12, 0x28($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X28);
    after_6:
    // 0x8080057C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80800580: lwc1        $f14, 0x4C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80800584: jal         0x800F1DCC
    // 0x80800588: lwc1        $f12, 0x2C($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X2C);
    func_800F1DCC(rdram, ctx);
        goto after_7;
    // 0x80800588: lwc1        $f12, 0x2C($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X2C);
    after_7:
    // 0x8080058C: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800590: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800594: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800598: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080059C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x808005A0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x808005A4: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x808005A8: jal         0x800E0AFC
    // 0x808005AC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_8;
    // 0x808005AC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_8:
    // 0x808005B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(760, 0X1074) << 16);
    // 0x808005B4: lwc1        $f8, 0x1074($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(760, 0X1074));
    // 0x808005B8: lui         $at, 0xC0E4
    ctx->r1 = S32(0XC0E4 << 16);
    // 0x808005BC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808005C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808005C4: addiu       $a1, $zero, 0x56
    ctx->r5 = ADD32(0, 0X56);
    // 0x808005C8: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    // 0x808005CC: lui         $a3, 0xBFD4
    ctx->r7 = S32(0XBFD4 << 16);
    // 0x808005D0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x808005D4: jal         0x800E0C20
    // 0x808005D8: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_800E0C20(rdram, ctx);
        goto after_9;
    // 0x808005D8: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_9:
    // 0x808005DC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(760, 0X1078) << 16);
    // 0x808005E0: lwc1        $f16, 0x1078($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(760, 0X1078));
    // 0x808005E4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x808005E8: lui         $a3, 0x4129
    ctx->r7 = S32(0X4129 << 16);
    // 0x808005EC: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x808005F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808005F4: addiu       $a1, $zero, 0x56
    ctx->r5 = ADD32(0, 0X56);
    // 0x808005F8: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    // 0x808005FC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80800600: jal         0x800E0AFC
    // 0x80800604: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_10;
    // 0x80800604: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_10:
    // 0x80800608: lui         $at, 0xC15F
    ctx->r1 = S32(0XC15F << 16);
    // 0x8080060C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800610: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(760, 0X107C) << 16);
    // 0x80800614: lwc1        $f6, 0x107C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(760, 0X107C));
    // 0x80800618: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080061C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    // 0x80800620: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    // 0x80800624: lui         $a3, 0xC07A
    ctx->r7 = S32(0XC07A << 16);
    // 0x80800628: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8080062C: jal         0x800E0C20
    // 0x80800630: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800E0C20(rdram, ctx);
        goto after_11;
    // 0x80800630: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_11:
    // 0x80800634: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(760, 0X1080) << 16);
    // 0x80800638: lwc1        $f8, 0x1080($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(760, 0X1080));
    // 0x8080063C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(760, 0X1084) << 16);
    // 0x80800640: lwc1        $f10, 0x1084($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(760, 0X1084));
    // 0x80800644: lui         $a3, 0xC2B6
    ctx->r7 = S32(0XC2B6 << 16);
    // 0x80800648: ori         $a3, $a3, 0x6800
    ctx->r7 = ctx->r7 | 0X6800;
    // 0x8080064C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800650: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    // 0x80800654: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    // 0x80800658: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8080065C: jal         0x800E0AFC
    // 0x80800660: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_12;
    // 0x80800660: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_12:
    // 0x80800664: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800668:
    // 0x80800668: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080066C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80800670: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80800674: jr          $ra
    // 0x80800678: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80800678: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void _fxsparkle_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800888D8: syscall     709
    recomp_syscall_handler(rdram, ctx, 0x800888D8);
    return;
    // 0x800888DC: xori        $t0, $zero, 0xC
    ctx->r8 = 0 ^ 0XC;
;}
RECOMP_FUNC void gcnewoption_entrypoint_35(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802AD8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802ADC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802AE0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80802AE4: sh          $a2, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r6;
    // 0x80802AE8: sh          $a3, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r7;
    // 0x80802AEC: jal         0x80101074
    // 0x80802AF0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80101074(rdram, ctx);
        goto after_0;
    // 0x80802AF0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80802AF4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80802AF8: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80802AFC: jal         0x8010114C
    // 0x80802B00: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_8010114C(rdram, ctx);
        goto after_1;
    // 0x80802B00: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80802B04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802B08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802B0C: jr          $ra
    // 0x80802B10: nop

    return;
    // 0x80802B10: nop

;}
RECOMP_FUNC void func_800CEF00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CEF00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CEF04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CEF08: jal         0x800CF6D0
    // 0x800CEF0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800CF6D0(rdram, ctx);
        goto after_0;
    // 0x800CEF0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800CEF10: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800CEF14: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800CEF18: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CEF1C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800CEF20: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800CEF24: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800CEF28: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800CEF2C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800CEF30: lwc1        $f8, -0x5580($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X5580);
    // 0x800CEF34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CEF38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CEF3C: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800CEF40: jr          $ra
    // 0x800CEF44: nop

    return;
    // 0x800CEF44: nop

;}
RECOMP_FUNC void func_8009D088(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D088: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009D08C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009D090: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009D094: lw          $t6, 0xFC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XFC);
    // 0x8009D098: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8009D09C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8009D0A0: sltiu       $at, $t7, 0xA
    ctx->r1 = ctx->r15 < 0XA ? 1 : 0;
    // 0x8009D0A4: beq         $at, $zero, L_8009D2C4
    if (ctx->r1 == 0) {
        // 0x8009D0A8: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8009D2C4;
    }
    // 0x8009D0A8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8009D0AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D0B0: addu        $at, $at, $t7
    gpr jr_addend_8009D0B8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8009D0B4: lw          $t7, 0x5354($at)
    ctx->r15 = ADD32(ctx->r1, 0X5354);
    // 0x8009D0B8: jr          $t7
    // 0x8009D0BC: nop

    switch (jr_addend_8009D0B8 >> 2) {
        case 0: goto L_8009D2C4; break;
        case 1: goto L_8009D0C0; break;
        case 2: goto L_8009D2C4; break;
        case 3: goto L_8009D158; break;
        case 4: goto L_8009D180; break;
        case 5: goto L_8009D104; break;
        case 6: goto L_8009D168; break;
        case 7: goto L_8009D1D8; break;
        case 8: goto L_8009D25C; break;
        case 9: goto L_8009D2BC; break;
        default: switch_error(__func__, 0x8009D0B8, 0x80125354);
    }
    // 0x8009D0BC: nop

L_8009D0C0:
    // 0x8009D0C0: jal         0x8009EF04
    // 0x8009D0C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_distance(rdram, ctx);
        goto after_0;
    // 0x8009D0C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8009D0C8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8009D0CC: nop

    // 0x8009D0D0: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x8009D0D4: nop

    // 0x8009D0D8: bc1t        L_8009D0F4
    if (c1cs) {
        // 0x8009D0DC: nop
    
            goto L_8009D0F4;
    }
    // 0x8009D0DC: nop

    // 0x8009D0E0: jal         0x8009EEB8
    // 0x8009D0E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_1;
    // 0x8009D0E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8009D0E8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8009D0EC: jal         0x8009C914
    // 0x8009D0F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_2;
    // 0x8009D0F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_8009D0F4:
    // 0x8009D0F4: jal         0x8009C88C
    // 0x8009D0F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_update(rdram, ctx);
        goto after_3;
    // 0x8009D0F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8009D0FC: b           L_8009D2C8
    // 0x8009D100: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8009D2C8;
    // 0x8009D100: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009D104:
    // 0x8009D104: jal         0x8009EF04
    // 0x8009D108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_distance(rdram, ctx);
        goto after_4;
    // 0x8009D108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8009D10C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8009D110: nop

    // 0x8009D114: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x8009D118: nop

    // 0x8009D11C: bc1t        L_8009D148
    if (c1cs) {
        // 0x8009D120: nop
    
            goto L_8009D148;
    }
    // 0x8009D120: nop

    // 0x8009D124: jal         0x8009EEB8
    // 0x8009D128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_5;
    // 0x8009D128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8009D12C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8009D130: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009D134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009D138: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x8009D13C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8009D140: jal         0x8009C914
    // 0x8009D144: nop

    yaw_setIdeal(rdram, ctx);
        goto after_6;
    // 0x8009D144: nop

    after_6:
L_8009D148:
    // 0x8009D148: jal         0x8009C88C
    // 0x8009D14C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_update(rdram, ctx);
        goto after_7;
    // 0x8009D14C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8009D150: b           L_8009D2C8
    // 0x8009D154: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8009D2C8;
    // 0x8009D154: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009D158:
    // 0x8009D158: jal         0x8009C88C
    // 0x8009D15C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_update(rdram, ctx);
        goto after_8;
    // 0x8009D15C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8009D160: b           L_8009D2C8
    // 0x8009D164: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8009D2C8;
    // 0x8009D164: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009D168:
    // 0x8009D168: jal         0x8009CFE8
    // 0x8009D16C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009CFE8(rdram, ctx);
        goto after_9;
    // 0x8009D16C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8009D170: jal         0x8009C88C
    // 0x8009D174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_update(rdram, ctx);
        goto after_10;
    // 0x8009D174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8009D178: b           L_8009D2C8
    // 0x8009D17C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8009D2C8;
    // 0x8009D17C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009D180:
    // 0x8009D180: jal         0x8009EF04
    // 0x8009D184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_distance(rdram, ctx);
        goto after_11;
    // 0x8009D184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8009D188: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8009D18C: nop

    // 0x8009D190: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x8009D194: nop

    // 0x8009D198: bc1t        L_8009D1C8
    if (c1cs) {
        // 0x8009D19C: nop
    
            goto L_8009D1C8;
    }
    // 0x8009D19C: nop

    // 0x8009D1A0: jal         0x8009EEB8
    // 0x8009D1A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_12;
    // 0x8009D1A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8009D1A8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8009D1AC: jal         0x8009C914
    // 0x8009D1B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_13;
    // 0x8009D1B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8009D1B4: jal         0x8009C990
    // 0x8009D1B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_14;
    // 0x8009D1B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x8009D1BC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8009D1C0: jal         0x8009C944
    // 0x8009D1C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_set(rdram, ctx);
        goto after_15;
    // 0x8009D1C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
L_8009D1C8:
    // 0x8009D1C8: jal         0x8009C88C
    // 0x8009D1CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_update(rdram, ctx);
        goto after_16;
    // 0x8009D1CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x8009D1D0: b           L_8009D2C8
    // 0x8009D1D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8009D2C8;
    // 0x8009D1D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009D1D8:
    // 0x8009D1D8: jal         0x8009EF04
    // 0x8009D1DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_distance(rdram, ctx);
        goto after_17;
    // 0x8009D1DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x8009D1E0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8009D1E4: nop

    // 0x8009D1E8: c.eq.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl == ctx->f18.fl;
    // 0x8009D1EC: nop

    // 0x8009D1F0: bc1t        L_8009D24C
    if (c1cs) {
        // 0x8009D1F4: nop
    
            goto L_8009D24C;
    }
    // 0x8009D1F4: nop

    // 0x8009D1F8: jal         0x8009EEB8
    // 0x8009D1FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_18;
    // 0x8009D1FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x8009D200: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8009D204: jal         0x8009C990
    // 0x8009D208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_19;
    // 0x8009D208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x8009D20C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8009D210: jal         0x800F1DCC
    // 0x8009D214: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    func_800F1DCC(rdram, ctx);
        goto after_20;
    // 0x8009D214: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    after_20:
    // 0x8009D218: jal         0x800F2100
    // 0x8009D21C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_21;
    // 0x8009D21C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_21:
    // 0x8009D220: lw          $t8, 0xFC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XFC);
    // 0x8009D224: lwc1        $f4, 0x4($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8009D228: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x8009D22C: nop

    // 0x8009D230: bc1f        L_8009D24C
    if (!c1cs) {
        // 0x8009D234: nop
    
            goto L_8009D24C;
    }
    // 0x8009D234: nop

    // 0x8009D238: jal         0x8009EEB8
    // 0x8009D23C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_22;
    // 0x8009D23C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x8009D240: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8009D244: jal         0x8009C914
    // 0x8009D248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_23;
    // 0x8009D248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
L_8009D24C:
    // 0x8009D24C: jal         0x8009C88C
    // 0x8009D250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_update(rdram, ctx);
        goto after_24;
    // 0x8009D250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x8009D254: b           L_8009D2C8
    // 0x8009D258: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8009D2C8;
    // 0x8009D258: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009D25C:
    // 0x8009D25C: jal         0x8009EF04
    // 0x8009D260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_distance(rdram, ctx);
        goto after_25;
    // 0x8009D260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x8009D264: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8009D268: nop

    // 0x8009D26C: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x8009D270: nop

    // 0x8009D274: bc1t        L_8009D298
    if (c1cs) {
        // 0x8009D278: nop
    
            goto L_8009D298;
    }
    // 0x8009D278: nop

    // 0x8009D27C: jal         0x8009EEB8
    // 0x8009D280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_26;
    // 0x8009D280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x8009D284: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8009D288: jal         0x8009C914
    // 0x8009D28C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_27;
    // 0x8009D28C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x8009D290: b           L_8009D2AC
    // 0x8009D294: nop

        goto L_8009D2AC;
    // 0x8009D294: nop

L_8009D298:
    // 0x8009D298: jal         0x8009C984
    // 0x8009D29C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_28;
    // 0x8009D29C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x8009D2A0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8009D2A4: jal         0x8009C914
    // 0x8009D2A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_29;
    // 0x8009D2A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
L_8009D2AC:
    // 0x8009D2AC: jal         0x8009C88C
    // 0x8009D2B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_update(rdram, ctx);
        goto after_30;
    // 0x8009D2B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x8009D2B4: b           L_8009D2C8
    // 0x8009D2B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8009D2C8;
    // 0x8009D2B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009D2BC:
    // 0x8009D2BC: jal         0x8009C88C
    // 0x8009D2C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_update(rdram, ctx);
        goto after_31;
    // 0x8009D2C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
L_8009D2C4:
    // 0x8009D2C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009D2C8:
    // 0x8009D2C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009D2CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8009D2D0: jr          $ra
    // 0x8009D2D4: nop

    return;
    // 0x8009D2D4: nop

;}
RECOMP_FUNC void bstaxi_entrypoint_34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801D20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801D24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801D28: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80801D2C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80801D30: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80801D34: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801D38: jal         0x8009D3A8
    // 0x80801D3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_0;
    // 0x80801D3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801D40: jal         0x8009EF10
    // 0x80801D44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bastick_getZone(rdram, ctx);
        goto after_1;
    // 0x80801D44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80801D48: blez        $v0, L_80801D54
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80801D4C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80801D54;
    }
    // 0x80801D4C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801D50: addiu       $s0, $zero, 0x123
    ctx->r16 = ADD32(0, 0X123);
L_80801D54:
    // 0x80801D54: jal         0x80800064
    // 0x80801D58: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80800064_bstaxi(rdram, ctx);
        goto after_2;
    // 0x80801D58: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x80801D5C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80801D60: jal         0x8008E148
    // 0x80801D64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8008E148(rdram, ctx);
        goto after_3;
    // 0x80801D64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80801D68: beq         $v0, $zero, L_80801D74
    if (ctx->r2 == 0) {
        // 0x80801D6C: nop
    
            goto L_80801D74;
    }
    // 0x80801D6C: nop

    // 0x80801D70: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80801D74:
    // 0x80801D74: jal         0x8008E260
    // 0x80801D78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8008E260(rdram, ctx);
        goto after_4;
    // 0x80801D78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80801D7C: beq         $v0, $zero, L_80801D88
    if (ctx->r2 == 0) {
        // 0x80801D80: nop
    
            goto L_80801D88;
    }
    // 0x80801D80: nop

    // 0x80801D84: addiu       $s0, $zero, 0x3D
    ctx->r16 = ADD32(0, 0X3D);
L_80801D88:
    // 0x80801D88: jal         0x8008E35C
    // 0x80801D8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    player_inWater(rdram, ctx);
        goto after_5;
    // 0x80801D8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80801D90: beq         $v0, $zero, L_80801D9C
    if (ctx->r2 == 0) {
        // 0x80801D94: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80801D9C;
    }
    // 0x80801D94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801D98: addiu       $s0, $zero, 0x4C
    ctx->r16 = ADD32(0, 0X4C);
L_80801D9C:
    // 0x80801D9C: jal         0x800A02DC
    // 0x80801DA0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800A02DC(rdram, ctx);
        goto after_6;
    // 0x80801DA0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x80801DA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801DA8: jal         0x8009E5C8
    // 0x80801DAC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_7;
    // 0x80801DAC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x80801DB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801DB4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801DB8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801DBC: jr          $ra
    // 0x80801DC0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80801DC0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _chstoneballcontrol_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086A70: syscall     409
    recomp_syscall_handler(rdram, ctx, 0x80086A70);
    return;
    // 0x80086A74: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_808088D0_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808088D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808088D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808088D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808088DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808088E0: jal         0x8008D04C
    // 0x808088E4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    func_8008D04C(rdram, ctx);
        goto after_0;
    // 0x808088E4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x808088E8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x808088EC: jal         0x80808E78
    // 0x808088F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80808E78_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x808088F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808088F4: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    // 0x808088F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808088FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80808900: beq         $v0, $at, L_80808924
    if (ctx->r2 == ctx->r1) {
        // 0x80808904: lui         $a1, 0x3E91
        ctx->r5 = S32(0X3E91 << 16);
            goto L_80808924;
    }
    // 0x80808904: lui         $a1, 0x3E91
    ctx->r5 = S32(0X3E91 << 16);
    // 0x80808908: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080890C: beq         $v0, $at, L_80808944
    if (ctx->r2 == ctx->r1) {
        // 0x80808910: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80808944;
    }
    // 0x80808910: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80808914: beq         $v0, $at, L_80808980
    if (ctx->r2 == ctx->r1) {
        // 0x80808918: nop
    
            goto L_80808980;
    }
    // 0x80808918: nop

    // 0x8080891C: b           L_80808994
    // 0x80808920: nop

        goto L_80808994;
    // 0x80808920: nop

L_80808924:
    // 0x80808924: jal         0x8008B348
    // 0x80808928: ori         $a1, $a1, 0xEB85
    ctx->r5 = ctx->r5 | 0XEB85;
    anctrl_isAt(rdram, ctx);
        goto after_2;
    // 0x80808928: ori         $a1, $a1, 0xEB85
    ctx->r5 = ctx->r5 | 0XEB85;
    after_2:
    // 0x8080892C: beq         $v0, $zero, L_80808994
    if (ctx->r2 == 0) {
        // 0x80808930: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80808994;
    }
    // 0x80808930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808934: jal         0x808086B0
    // 0x80808938: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808086B0_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x80808938: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x8080893C: b           L_80808994
    // 0x80808940: nop

        goto L_80808994;
    // 0x80808940: nop

L_80808944:
    // 0x80808944: jal         0x8009C984
    // 0x80808948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_4;
    // 0x80808948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080894C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80808950: jal         0x8009B9C0
    // 0x80808954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_5;
    // 0x80808954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80808958: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x8080895C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80808960: jal         0x8008B348
    // 0x80808964: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_6;
    // 0x80808964: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x80808968: beq         $v0, $zero, L_80808994
    if (ctx->r2 == 0) {
        // 0x8080896C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80808994;
    }
    // 0x8080896C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808970: jal         0x808086B0
    // 0x80808974: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808086B0_bsfirstp(rdram, ctx);
        goto after_7;
    // 0x80808974: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
    // 0x80808978: b           L_80808994
    // 0x8080897C: nop

        goto L_80808994;
    // 0x8080897C: nop

L_80808980:
    // 0x80808980: jal         0x8008B324
    // 0x80808984: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isStopped(rdram, ctx);
        goto after_8;
    // 0x80808984: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_8:
    // 0x80808988: beq         $v0, $zero, L_80808994
    if (ctx->r2 == 0) {
        // 0x8080898C: addiu       $t6, $zero, 0xCA
        ctx->r14 = ADD32(0, 0XCA);
            goto L_80808994;
    }
    // 0x8080898C: addiu       $t6, $zero, 0xCA
    ctx->r14 = ADD32(0, 0XCA);
    // 0x80808990: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80808994:
    // 0x80808994: jal         0x8008B2B4
    // 0x80808998: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_getAnimTimer(rdram, ctx);
        goto after_9;
    // 0x80808998: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_9:
    // 0x8080899C: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA58C) << 16);
    // 0x808089A0: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x808089A4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808089A8: lwc1        $f14, -0x5A74($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA58C));
    // 0x808089AC: jal         0x800F0D50
    // 0x808089B0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800F0D50(rdram, ctx);
        goto after_10;
    // 0x808089B0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_10:
    // 0x808089B4: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA590) << 16);
    // 0x808089B8: lwc1        $f4, -0x5A70($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA590));
    // 0x808089BC: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA594) << 16);
    // 0x808089C0: lwc1        $f8, -0x5A6C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA594));
    // 0x808089C4: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x808089C8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808089CC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808089D0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x808089D4: nop

    // 0x808089D8: mul.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x808089DC: jal         0x80013970
    // 0x808089E0: nop

    func_80013970(rdram, ctx);
        goto after_11;
    // 0x808089E0: nop

    after_11:
    // 0x808089E4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808089E8: jal         0x80803B58
    // 0x808089EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803B58_bsfirstp(rdram, ctx);
        goto after_12;
    // 0x808089EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808089F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808089F4: jal         0x8009E5C8
    // 0x808089F8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_13;
    // 0x808089F8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_13:
    // 0x808089FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80808A00: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80808A04: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80808A08: jr          $ra
    // 0x80808A0C: nop

    return;
    // 0x80808A0C: nop

;}
RECOMP_FUNC void func_800F3B90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F3B90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F3B94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F3B98: jal         0x800F3B3C
    // 0x800F3B9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800F3B3C(rdram, ctx);
        goto after_0;
    // 0x800F3B9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800F3BA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F3BA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F3BA8: jr          $ra
    // 0x800F3BAC: nop

    return;
    // 0x800F3BAC: nop

;}
RECOMP_FUNC void bsstonehead_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800460: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800464: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800468: jal         0x80800194
    // 0x8080046C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800194_bsstonehead(rdram, ctx);
        goto after_0;
    // 0x8080046C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800470: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800474: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800478: jr          $ra
    // 0x8080047C: nop

    return;
    // 0x8080047C: nop

;}
RECOMP_FUNC void func_800BF774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF774: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800BF778: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800BF77C: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800BF780: addiu       $s2, $s2, -0x7A50
    ctx->r18 = ADD32(ctx->r18, -0X7A50);
    // 0x800BF784: lw          $t6, 0x88($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X88);
    // 0x800BF788: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800BF78C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800BF790: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800BF794: blez        $t6, L_800BF7C8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800BF798: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_800BF7C8;
    }
    // 0x800BF798: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800BF79C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800BF7A0: addiu       $s1, $s1, -0x7A4C
    ctx->r17 = ADD32(ctx->r17, -0X7A4C);
    // 0x800BF7A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800BF7A8:
    // 0x800BF7A8: jal         0x800DF744
    // 0x800BF7AC: lw          $a1, 0x88($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X88);
    func_800DF744(rdram, ctx);
        goto after_0;
    // 0x800BF7AC: lw          $a1, 0x88($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X88);
    after_0:
    // 0x800BF7B0: lw          $t7, 0x88($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X88);
    // 0x800BF7B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800BF7B8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800BF7BC: slt         $at, $t7, $s0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800BF7C0: beql        $at, $zero, L_800BF7A8
    if (ctx->r1 == 0) {
        // 0x800BF7C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800BF7A8;
    }
    goto skip_0;
    // 0x800BF7C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
L_800BF7C8:
    // 0x800BF7C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800BF7CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800BF7D0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800BF7D4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800BF7D8: jr          $ra
    // 0x800BF7DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800BF7DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _bssub_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083D50: syscall     93
    recomp_syscall_handler(rdram, ctx, 0x80083D50);
    return;
    // 0x80083D54: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800828_chcablespark(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800828: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080082C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800830: lhu         $v0, 0x76($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X76);
    // 0x80800834: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800838: srl         $t6, $v0, 7
    ctx->r14 = S32(U32(ctx->r2) >> 7);
    // 0x8080083C: addiu       $v0, $t6, -0x32
    ctx->r2 = ADD32(ctx->r14, -0X32);
    // 0x80800840: beq         $v0, $at, L_80800860
    if (ctx->r2 == ctx->r1) {
        // 0x80800844: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800860;
    }
    // 0x80800844: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800848: beq         $v0, $at, L_80800878
    if (ctx->r2 == ctx->r1) {
        // 0x8080084C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800878;
    }
    // 0x8080084C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800850: beq         $v0, $at, L_80800890
    if (ctx->r2 == ctx->r1) {
        // 0x80800854: nop
    
            goto L_80800890;
    }
    // 0x80800854: nop

    // 0x80800858: b           L_808008AC
    // 0x8080085C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808008AC;
    // 0x8080085C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800860:
    // 0x80800860: jal         0x800DA298
    // 0x80800864: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800864: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    after_0:
    // 0x80800868: bnel        $v0, $zero, L_808008AC
    if (ctx->r2 != 0) {
        // 0x8080086C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808008AC;
    }
    goto skip_0;
    // 0x8080086C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800870: b           L_808008AC
    // 0x80800874: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808008AC;
    // 0x80800874: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800878:
    // 0x80800878: jal         0x800DA298
    // 0x8080087C: addiu       $a0, $zero, 0xEC
    ctx->r4 = ADD32(0, 0XEC);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x8080087C: addiu       $a0, $zero, 0xEC
    ctx->r4 = ADD32(0, 0XEC);
    after_1:
    // 0x80800880: bnel        $v0, $zero, L_808008AC
    if (ctx->r2 != 0) {
        // 0x80800884: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808008AC;
    }
    goto skip_1;
    // 0x80800884: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x80800888: b           L_808008AC
    // 0x8080088C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808008AC;
    // 0x8080088C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800890:
    // 0x80800890: jal         0x800DA298
    // 0x80800894: addiu       $a0, $zero, 0x18C
    ctx->r4 = ADD32(0, 0X18C);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800894: addiu       $a0, $zero, 0x18C
    ctx->r4 = ADD32(0, 0X18C);
    after_2:
    // 0x80800898: bnel        $v0, $zero, L_808008AC
    if (ctx->r2 != 0) {
        // 0x8080089C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808008AC;
    }
    goto skip_2;
    // 0x8080089C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x808008A0: b           L_808008AC
    // 0x808008A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808008AC;
    // 0x808008A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808008A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808008AC:
    // 0x808008AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008B4: jr          $ra
    // 0x808008B8: nop

    return;
    // 0x808008B8: nop

;}
RECOMP_FUNC void func_800EA614(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA614: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800EA618: addiu       $v0, $v0, 0x2DD0
    ctx->r2 = ADD32(ctx->r2, 0X2DD0);
    // 0x800EA61C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800EA620: jr          $ra
    // 0x800EA624: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    return;
    // 0x800EA624: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
;}
RECOMP_FUNC void func_800FCED0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FCED0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FCED4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FCED8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800FCEDC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800FCEE0: jal         0x800FB5F8
    // 0x800FCEE4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_800FB5F8(rdram, ctx);
        goto after_0;
    // 0x800FCEE4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x800FCEE8: beq         $v0, $zero, L_800FCF3C
    if (ctx->r2 == 0) {
        // 0x800FCEEC: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_800FCF3C;
    }
    // 0x800FCEEC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800FCEF0: addiu       $t6, $t6, 0x57D0
    ctx->r14 = ADD32(ctx->r14, 0X57D0);
    // 0x800FCEF4: subu        $a3, $v0, $t6
    ctx->r7 = SUB32(ctx->r2, ctx->r14);
    // 0x800FCEF8: addiu       $at, $zero, 0x50
    ctx->r1 = ADD32(0, 0X50);
    // 0x800FCEFC: div         $zero, $a3, $at
    lo = S32(S64(S32(ctx->r7)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r7)) % S64(S32(ctx->r1)));
    // 0x800FCF00: mflo        $a3
    ctx->r7 = lo;
    // 0x800FCF04: andi        $a0, $a3, 0xFF
    ctx->r4 = ctx->r7 & 0XFF;
    // 0x800FCF08: jal         0x80017108
    // 0x800FCF0C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80017108(rdram, ctx);
        goto after_1;
    // 0x800FCF0C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x800FCF10: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800FCF14: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800FCF18: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800FCF1C: beq         $v0, $t8, L_800FCF2C
    if (ctx->r2 == ctx->r24) {
        // 0x800FCF20: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_800FCF2C;
    }
    // 0x800FCF20: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800FCF24: b           L_800FCF40
    // 0x800FCF28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FCF40;
    // 0x800FCF28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FCF2C:
    // 0x800FCF2C: jal         0x80017D74
    // 0x800FCF30: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    func_80017D74(rdram, ctx);
        goto after_2;
    // 0x800FCF30: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x800FCF34: b           L_800FCF44
    // 0x800FCF38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800FCF44;
    // 0x800FCF38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800FCF3C:
    // 0x800FCF3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FCF40:
    // 0x800FCF40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800FCF44:
    // 0x800FCF44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800FCF48: jr          $ra
    // 0x800FCF4C: nop

    return;
    // 0x800FCF4C: nop

;}
RECOMP_FUNC void func_80800BF4_chcoderoombits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BF4: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80800BF8: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80800BFC: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80800C00: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800C04: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x80800C08: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x80800C0C: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x80800C10: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x80800C14: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80800C18: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80800C1C: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80800C20: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x80800C24: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80800C28: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80800C2C: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80800C30: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800C34: jal         0x80100094
    // 0x80800C38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800C38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800C3C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800C40: lw          $fp, 0x0($s0)
    ctx->r30 = MEM_W(ctx->r16, 0X0);
    // 0x80800C44: jal         0x800BEA88
    // 0x80800C48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BEA88(rdram, ctx);
        goto after_1;
    // 0x80800C48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x80800C4C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1172, 0X1154) << 16);
    // 0x80800C50: lwc1        $f26, 0x1154($at)
    ctx->f26.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1172, 0X1154));
    // 0x80800C54: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1172, 0X1158) << 16);
    // 0x80800C58: lwc1        $f24, 0x1158($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1172, 0X1158));
    // 0x80800C5C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800C60: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x80800C64: lui         $s6, 0x8008
    ctx->r22 = S32(0X8008 << 16);
    // 0x80800C68: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800C6C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800C70: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800C74: addiu       $s6, $s6, 0x62A0
    ctx->r22 = ADD32(ctx->r22, 0X62A0);
    // 0x80800C78: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
    // 0x80800C7C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800C80: addiu       $s7, $zero, 0x1A
    ctx->r23 = ADD32(0, 0X1A);
    // 0x80800C84: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
    // 0x80800C88: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_80800C8C:
    // 0x80800C8C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80800C90: beq         $v0, $zero, L_80800CB8
    if (ctx->r2 == 0) {
        // 0x80800C94: nop
    
            goto L_80800CB8;
    }
    // 0x80800C94: nop

    // 0x80800C98: beql        $v0, $s4, L_80800CC4
    if (ctx->r2 == ctx->r20) {
        // 0x80800C9C: mfc1        $a1, $f26
        ctx->r5 = (int32_t)ctx->f26.u32l;
            goto L_80800CC4;
    }
    goto skip_0;
    // 0x80800C9C: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    skip_0:
    // 0x80800CA0: beq         $v0, $s2, L_80800CF4
    if (ctx->r2 == ctx->r18) {
        // 0x80800CA4: nop
    
            goto L_80800CF4;
    }
    // 0x80800CA4: nop

    // 0x80800CA8: beql        $v0, $s5, L_80800D00
    if (ctx->r2 == ctx->r21) {
        // 0x80800CAC: mfc1        $a1, $f24
        ctx->r5 = (int32_t)ctx->f24.u32l;
            goto L_80800D00;
    }
    goto skip_1;
    // 0x80800CAC: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    skip_1:
    // 0x80800CB0: b           L_80800D2C
    // 0x80800CB4: nop

        goto L_80800D2C;
    // 0x80800CB4: nop

L_80800CB8:
    // 0x80800CB8: b           L_80800D2C
    // 0x80800CBC: swc1        $f20, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f20.u32l;
        goto L_80800D2C;
    // 0x80800CBC: swc1        $f20, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f20.u32l;
    // 0x80800CC0: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
L_80800CC4:
    // 0x80800CC4: jal         0x800D91EC
    // 0x80800CC8: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    func_800D91EC(rdram, ctx);
        goto after_2;
    // 0x80800CC8: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    after_2:
    // 0x80800CCC: beq         $v0, $zero, L_80800CD8
    if (ctx->r2 == 0) {
        // 0x80800CD0: mov.s       $f14, $f20
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
            goto L_80800CD8;
    }
    // 0x80800CD0: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x80800CD4: sw          $s2, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r18;
L_80800CD8:
    // 0x80800CD8: lwc1        $f12, 0x20($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80800CDC: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x80800CE0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800CE4: jal         0x800F10B4
    // 0x80800CE8: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x80800CE8: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_3:
    // 0x80800CEC: b           L_80800D2C
    // 0x80800CF0: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
        goto L_80800D2C;
    // 0x80800CF0: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
L_80800CF4:
    // 0x80800CF4: b           L_80800D2C
    // 0x80800CF8: swc1        $f22, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f22.u32l;
        goto L_80800D2C;
    // 0x80800CF8: swc1        $f22, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f22.u32l;
    // 0x80800CFC: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
L_80800D00:
    // 0x80800D00: jal         0x800D91EC
    // 0x80800D04: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    func_800D91EC(rdram, ctx);
        goto after_4;
    // 0x80800D04: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    after_4:
    // 0x80800D08: beq         $v0, $zero, L_80800D14
    if (ctx->r2 == 0) {
        // 0x80800D0C: mov.s       $f14, $f20
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
            goto L_80800D14;
    }
    // 0x80800D0C: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x80800D10: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
L_80800D14:
    // 0x80800D14: lwc1        $f12, 0x20($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80800D18: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80800D1C: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80800D20: jal         0x800F10B4
    // 0x80800D24: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    func_800F10B4(rdram, ctx);
        goto after_5;
    // 0x80800D24: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_5:
    // 0x80800D28: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
L_80800D2C:
    // 0x80800D2C: beq         $s3, $zero, L_80800D44
    if (ctx->r19 == 0) {
        // 0x80800D30: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80800D44;
    }
    // 0x80800D30: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800D34: addiu       $a1, $s1, 0x1
    ctx->r5 = ADD32(ctx->r17, 0X1);
    // 0x80800D38: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80800D3C: jal         0x80088660
    // 0x80800D40: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    _glid_entrypoint_0(rdram, ctx);
        goto after_6;
    // 0x80800D40: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_6:
L_80800D44:
    // 0x80800D44: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800D48: bne         $s1, $s7, L_80800C8C
    if (ctx->r17 != ctx->r23) {
        // 0x80800D4C: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_80800C8C;
    }
    // 0x80800D4C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80800D50: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80800D54: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80800D58: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80800D5C: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80800D60: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80800D64: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80800D68: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x80800D6C: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x80800D70: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x80800D74: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x80800D78: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x80800D7C: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x80800D80: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x80800D84: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x80800D88: jr          $ra
    // 0x80800D8C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80800D8C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void bsdie_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808003B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808003B8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808003BC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808003C0: jal         0x8008CABC
    // 0x808003C4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808003C4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x808003C8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808003CC: jal         0x8008AF24
    // 0x808003D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x808003D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808003D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003D8: jal         0x8008B1A0
    // 0x808003DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_2;
    // 0x808003DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808003E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003E4: jal         0x8008AED4
    // 0x808003E8: addiu       $a1, $zero, 0xD8
    ctx->r5 = ADD32(0, 0XD8);
    anctrl_setIndex(rdram, ctx);
        goto after_3;
    // 0x808003E8: addiu       $a1, $zero, 0xD8
    ctx->r5 = ADD32(0, 0XD8);
    after_3:
    // 0x808003EC: lui         $a2, 0x3DBE
    ctx->r6 = S32(0X3DBE << 16);
    // 0x808003F0: ori         $a2, $a2, 0xDFA4
    ctx->r6 = ctx->r6 | 0XDFA4;
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003F8: jal         0x8008B1D4
    // 0x808003FC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_4;
    // 0x808003FC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x80800400: lui         $a1, 0x4096
    ctx->r5 = S32(0X4096 << 16);
    // 0x80800404: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80800408: jal         0x8008B1BC
    // 0x8080040C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_5;
    // 0x8080040C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800414: jal         0x8008B134
    // 0x80800418: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_6;
    // 0x80800418: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x8080041C: jal         0x8008B064
    // 0x80800420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_7;
    // 0x80800420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800424: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80800428: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080042C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800430: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800434: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800438: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080043C: swc1        $f0, 0x16C($s1)
    MEM_W(0X16C, ctx->r17) = ctx->f0.u32l;
    // 0x80800440: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800444: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800448: lui         $a2, 0x43FF
    ctx->r6 = S32(0X43FF << 16);
    // 0x8080044C: lui         $a3, 0xC4AF
    ctx->r7 = S32(0XC4AF << 16);
    // 0x80800450: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80800454: jal         0x80085220
    // 0x80800458: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    _basudie_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x80800458: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_8:
    // 0x8080045C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800460: jal         0x800A0CF4
    // 0x80800464: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_9;
    // 0x80800464: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80800468: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080046C: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x80800470: jal         0x8009BFE4
    // 0x80800474: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    func_8009BFE4(rdram, ctx);
        goto after_10;
    // 0x80800474: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_10:
    // 0x80800478: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080047C: jal         0x8009D820
    // 0x80800480: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8009D820(rdram, ctx);
        goto after_11;
    // 0x80800480: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_11:
    // 0x80800484: sw          $zero, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = 0;
    // 0x80800488: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080048C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800490: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800494: jr          $ra
    // 0x80800498: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800498: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80800568_chmrsboggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800568: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080056C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800570: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(888, 0XB30) << 16);
    // 0x80800574: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(888, 0XA20) << 16);
    // 0x80800578: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x8080057C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800580: addiu       $a3, $a3, 0xA20
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(888, 0XA20));
    // 0x80800584: addiu       $a2, $a2, 0xB30
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(888, 0XB30));
    // 0x80800588: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080058C: jal         0x8008A1F0
    // 0x80800590: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x80800590: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80800594: beq         $v0, $zero, L_808005C8
    if (ctx->r2 == 0) {
        // 0x80800598: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_808005C8;
    }
    // 0x80800598: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8080059C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(888, 0XA20) << 16);
    // 0x808005A0: addiu       $a2, $a2, 0xA20
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(888, 0XA20));
    // 0x808005A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808005A8: jal         0x8008A1F8
    // 0x808005AC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    _subaddiedialog_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x808005AC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_1:
    // 0x808005B0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808005B4: beq         $v0, $at, L_808005C8
    if (ctx->r2 == ctx->r1) {
        // 0x808005B8: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808005C8;
    }
    // 0x808005B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808005BC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808005C0: jal         0x808007CC
    // 0x808005C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_808007CC_chmrsboggy(rdram, ctx);
        goto after_2;
    // 0x808005C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
L_808005C8:
    // 0x808005C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808005CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808005D0: jr          $ra
    // 0x808005D4: nop

    return;
    // 0x808005D4: nop

;}
RECOMP_FUNC void func_80801848_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801848: jr          $ra
    // 0x8080184C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8080184C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80000450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000450: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80000454: lui         $t7, 0x8001
    ctx->r15 = S32(0X8001 << 16);
    // 0x80000458: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000045C: lui         $t6, 0x8020
    ctx->r14 = S32(0X8020 << 16);
    // 0x80000460: addiu       $t7, $t7, 0x2030
    ctx->r15 = ADD32(ctx->r15, 0X2030);
    // 0x80000464: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80000468: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8000046C: jal         0x800016F0
    // 0x80000470: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    boot_osInitialize(rdram, ctx);
        goto after_0;
    // 0x80000470: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_0:
    // 0x80000474: lui         $v0, 0x1E3
    ctx->r2 = S32(0X1E3 << 16);
    // 0x80000478: lui         $t8, 0x1E4
    ctx->r24 = S32(0X1E4 << 16);
    // 0x8000047C: addiu       $a1, $v0, -0x64A0
    ctx->r5 = ADD32(ctx->r2, -0X64A0);
    // 0x80000480: addiu       $t8, $t8, 0x2550
    ctx->r24 = ADD32(ctx->r24, 0X2550);
    // 0x80000484: subu        $a3, $t8, $a1
    ctx->r7 = SUB32(ctx->r24, ctx->r5);
    // 0x80000488: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000048C: jal         0x80001A40
    // 0x80000490: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    boot___osPiRawStartDma(rdram, ctx);
        goto after_1;
    // 0x80000490: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80000494: jal         0x80001B10
    // 0x80000498: nop

    boot_osPiGetStatus(rdram, ctx);
        goto after_2;
    // 0x80000498: nop

    after_2:
    // 0x8000049C: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x800004A0: beq         $t9, $zero, L_800004BC
    if (ctx->r25 == 0) {
        // 0x800004A4: nop
    
            goto L_800004BC;
    }
    // 0x800004A4: nop

L_800004A8:
    // 0x800004A8: jal         0x80001B10
    // 0x800004AC: nop

    boot_osPiGetStatus(rdram, ctx);
        goto after_3;
    // 0x800004AC: nop

    after_3:
    // 0x800004B0: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x800004B4: bne         $t0, $zero, L_800004A8
    if (ctx->r8 != 0) {
        // 0x800004B8: nop
    
            goto L_800004A8;
    }
    // 0x800004B8: nop

L_800004BC:
    // 0x800004BC: jal         0x80000540
    // 0x800004C0: nop

    func_80000540(rdram, ctx);
        goto after_4;
    // 0x800004C0: nop

    after_4:
    // 0x800004C4: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800004C8: jal         0x80000560
    // 0x800004CC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    func_80000560(rdram, ctx);
        goto after_5;
    // 0x800004CC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_5:
    // 0x800004D0: jal         0x800005EC
    // 0x800004D4: nop

    func_800005EC(rdram, ctx);
        goto after_6;
    // 0x800004D4: nop

    after_6:
    // 0x800004D8: lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // 0x800004DC: jal         0x8000060C
    // 0x800004E0: sw          $v0, 0x2000($at)
    MEM_W(0X2000, ctx->r1) = ctx->r2;
    func_8000060C(rdram, ctx);
        goto after_7;
    // 0x800004E0: sw          $v0, 0x2000($at)
    MEM_W(0X2000, ctx->r1) = ctx->r2;
    after_7:
    // 0x800004E4: lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // 0x800004E8: sw          $v0, 0x2004($at)
    MEM_W(0X2004, ctx->r1) = ctx->r2;
    // 0x800004EC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800004F0: jal         0x80000560
    // 0x800004F4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    func_80000560(rdram, ctx);
        goto after_8;
    // 0x800004F4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_8:
    // 0x800004F8: jal         0x800005EC
    // 0x800004FC: nop

    func_800005EC(rdram, ctx);
        goto after_9;
    // 0x800004FC: nop

    after_9:
    // 0x80000500: lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // 0x80000504: jal         0x8000060C
    // 0x80000508: sw          $v0, 0x2008($at)
    MEM_W(0X2008, ctx->r1) = ctx->r2;
    func_8000060C(rdram, ctx);
        goto after_10;
    // 0x80000508: sw          $v0, 0x2008($at)
    MEM_W(0X2008, ctx->r1) = ctx->r2;
    after_10:
    // 0x8000050C: lui         $at, 0x8001
    ctx->r1 = S32(0X8001 << 16);
    // 0x80000510: jal         0x80000670
    // 0x80000514: sw          $v0, 0x200C($at)
    MEM_W(0X200C, ctx->r1) = ctx->r2;
    func_80000670(rdram, ctx);
        goto after_11;
    // 0x80000514: sw          $v0, 0x200C($at)
    MEM_W(0X200C, ctx->r1) = ctx->r2;
    after_11:
    // 0x80000518: lui         $t9, 0x8001
    ctx->r25 = S32(0X8001 << 16);
    // 0x8000051C: addiu       $t9, $t9, 0x2030
    ctx->r25 = ADD32(ctx->r25, 0X2030);
    // 0x80000520: jalr        $t9
    // 0x80000524: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_12;
    // 0x80000524: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_12:
    // 0x80000528: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000052C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80000530: jr          $ra
    // 0x80000534: nop

    return;
    // 0x80000534: nop

;}
RECOMP_FUNC void ncpoducam_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800060: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800064: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800068: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080006C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800070: jal         0x8001B668
    // 0x80800074: addiu       $a1, $zero, 0x68
    ctx->r5 = ADD32(0, 0X68);
    func_8001B668(rdram, ctx);
        goto after_0;
    // 0x80800074: addiu       $a1, $zero, 0x68
    ctx->r5 = ADD32(0, 0X68);
    after_0:
    // 0x80800078: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x8080007C: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80800080: sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    // 0x80800084: jal         0x808000F0
    // 0x80800088: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    ncpoducam_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800088: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_1:
    // 0x8080008C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800090: sw          $zero, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = 0;
    // 0x80800094: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x80800098: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x8080009C: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x808000A0: jal         0x800EFD24
    // 0x808000A4: addiu       $a0, $v0, 0x3C
    ctx->r4 = ADD32(ctx->r2, 0X3C);
    func_800EFD24(rdram, ctx);
        goto after_2;
    // 0x808000A4: addiu       $a0, $v0, 0x3C
    ctx->r4 = ADD32(ctx->r2, 0X3C);
    after_2:
    // 0x808000A8: jal         0x800EFD24
    // 0x808000AC: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    func_800EFD24(rdram, ctx);
        goto after_3;
    // 0x808000AC: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x808000B0: jal         0x800EFD24
    // 0x808000B4: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    func_800EFD24(rdram, ctx);
        goto after_4;
    // 0x808000B4: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    after_4:
    // 0x808000B8: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x808000BC: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x808000C0: sh          $zero, 0x48($s0)
    MEM_H(0X48, ctx->r16) = 0;
    // 0x808000C4: sw          $zero, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = 0;
    // 0x808000C8: sh          $t7, 0x58($s0)
    MEM_H(0X58, ctx->r16) = ctx->r15;
    // 0x808000CC: sb          $t8, 0x60($s0)
    MEM_B(0X60, ctx->r16) = ctx->r24;
    // 0x808000D0: jal         0x800E6A00
    // 0x808000D4: sb          $zero, 0x62($s0)
    MEM_B(0X62, ctx->r16) = 0;
    func_800E6A00(rdram, ctx);
        goto after_5;
    // 0x808000D4: sb          $zero, 0x62($s0)
    MEM_B(0X62, ctx->r16) = 0;
    after_5:
    // 0x808000D8: sb          $v0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r2;
    // 0x808000DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000E4: lh          $v0, 0x26($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X26);
    // 0x808000E8: jr          $ra
    // 0x808000EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808000EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_808005EC_cheggproximity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808005F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808005FC: jal         0x80100094
    // 0x80800600: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800600: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800604: lw          $t6, 0xA4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XA4);
    // 0x80800608: bnel        $t6, $zero, L_80800644
    if (ctx->r14 != 0) {
        // 0x8080060C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800644;
    }
    goto skip_0;
    // 0x8080060C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800610: jal         0x80800874
    // 0x80800614: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800874_cheggproximity(rdram, ctx);
        goto after_1;
    // 0x80800614: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800618: jal         0x80800BF4
    // 0x8080061C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800BF4_cheggproximity(rdram, ctx);
        goto after_2;
    // 0x8080061C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800620: bne         $v0, $zero, L_80800640
    if (ctx->r2 != 0) {
        // 0x80800624: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_80800640;
    }
    // 0x80800624: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800628: jal         0x800D9078
    // 0x8080062C: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    func_800D9078(rdram, ctx);
        goto after_3;
    // 0x8080062C: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    after_3:
    // 0x80800630: beq         $v0, $zero, L_80800640
    if (ctx->r2 == 0) {
        // 0x80800634: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800640;
    }
    // 0x80800634: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800638: jal         0x80800718
    // 0x8080063C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800718_cheggproximity(rdram, ctx);
        goto after_4;
    // 0x8080063C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_4:
L_80800640:
    // 0x80800640: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800644:
    // 0x80800644: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800648: jr          $ra
    // 0x8080064C: nop

    return;
    // 0x8080064C: nop

;}
RECOMP_FUNC void func_80800024_chhellterskelter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800028: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080002C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800030: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800034: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800038: jal         0x80088278
    // 0x8080003C: addiu       $a0, $zero, 0x154
    ctx->r4 = ADD32(0, 0X154);
    _gccubesearch_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x8080003C: addiu       $a0, $zero, 0x154
    ctx->r4 = ADD32(0, 0X154);
    after_0:
    // 0x80800040: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800044: addiu       $a0, $zero, 0x320
    ctx->r4 = ADD32(0, 0X320);
    // 0x80800048: jal         0x80088278
    // 0x8080004C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _gccubesearch_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x8080004C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80800050: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800054: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80800058: jal         0x800EE88C
    // 0x8080005C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800EE88C(rdram, ctx);
        goto after_2;
    // 0x8080005C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80800060: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x80800064: jal         0x800EE88C
    // 0x80800068: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800EE88C(rdram, ctx);
        goto after_3;
    // 0x80800068: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x8080006C: jal         0x800DA298
    // 0x80800070: addiu       $a0, $zero, 0xA4B
    ctx->r4 = ADD32(0, 0XA4B);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80800070: addiu       $a0, $zero, 0xA4B
    ctx->r4 = ADD32(0, 0XA4B);
    after_4:
    // 0x80800074: beql        $v0, $zero, L_80800098
    if (ctx->r2 == 0) {
        // 0x80800078: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800098;
    }
    goto skip_0;
    // 0x80800078: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080007C: lbu         $t6, 0x65($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X65);
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800084: addiu       $a1, $zero, 0x210
    ctx->r5 = ADD32(0, 0X210);
    // 0x80800088: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x8080008C: jal         0x80108B04
    // 0x80800090: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
    func_80108B04(rdram, ctx);
        goto after_5;
    // 0x80800090: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
    after_5:
    // 0x80800094: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800098:
    // 0x80800098: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080009C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000A0: jr          $ra
    // 0x808000A4: nop

    return;
    // 0x808000A4: nop

;}
RECOMP_FUNC void func_808048F8_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808048F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808048FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80804900: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80804904: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
    // 0x80804908: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8080490C: slti        $at, $t6, -0x1
    ctx->r1 = SIGNED(ctx->r14) < -0X1 ? 1 : 0;
    // 0x80804910: beql        $at, $zero, L_8080493C
    if (ctx->r1 == 0) {
        // 0x80804914: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080493C;
    }
    goto skip_0;
    // 0x80804914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80804918: lw          $a0, 0x30($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30);
    // 0x8080491C: jal         0x80802C48
    // 0x80804920: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80802C48_chgameselect(rdram, ctx);
        goto after_0;
    // 0x80804920: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80804924: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80804928: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8080492C: sw          $zero, 0x18($a2)
    MEM_W(0X18, ctx->r6) = 0;
    // 0x80804930: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80804934: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80804938: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080493C:
    // 0x8080493C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80804940: jr          $ra
    // 0x80804944: nop

    return;
    // 0x80804944: nop

;}
RECOMP_FUNC void _chintrotext_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800861A8: syscall     285
    recomp_syscall_handler(rdram, ctx, 0x800861A8);
    return;
    // 0x800861AC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void bastatetimerlist_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800917D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800917D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800917DC: jal         0x800F424C
    // 0x800917E0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800F424C(rdram, ctx);
        goto after_0;
    // 0x800917E0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x800917E4: sltiu       $a1, $v0, 0x1
    ctx->r5 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800917E8: jal         0x800D8FF8
    // 0x800917EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x800917EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x800917F0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800917F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800917F8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800917FC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80091800: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    // 0x80091804: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
L_80091808:
    // 0x80091808: addu        $v0, $t6, $v1
    ctx->r2 = ADD32(ctx->r14, ctx->r3);
    // 0x8009180C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80091810: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80091814: lw          $t7, 0x3C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X3C);
    // 0x80091818: addu        $v0, $t7, $v1
    ctx->r2 = ADD32(ctx->r15, ctx->r3);
    // 0x8009181C: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80091820: c.eq.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl == ctx->f2.fl;
    // 0x80091824: nop

    // 0x80091828: bc1tl       L_80091878
    if (c1cs) {
        // 0x8009182C: lwc1        $f10, 0xC($v0)
        ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
            goto L_80091878;
    }
    goto skip_0;
    // 0x8009182C: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    skip_0:
    // 0x80091830: lbu         $t8, 0x8($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X8);
    // 0x80091834: beql        $t8, $zero, L_80091848
    if (ctx->r24 == 0) {
        // 0x80091838: sub.s       $f6, $f2, $f0
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_80091848;
    }
    goto skip_1;
    // 0x80091838: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
    skip_1:
    // 0x8009183C: bnel        $a1, $zero, L_80091878
    if (ctx->r5 != 0) {
        // 0x80091840: lwc1        $f10, 0xC($v0)
        ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
            goto L_80091878;
    }
    goto skip_2;
    // 0x80091840: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    skip_2:
    // 0x80091844: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
L_80091848:
    // 0x80091848: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x8009184C: lw          $t9, 0x3C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X3C);
    // 0x80091850: addu        $v0, $t9, $v1
    ctx->r2 = ADD32(ctx->r25, ctx->r3);
    // 0x80091854: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80091858: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x8009185C: nop

    // 0x80091860: bc1fl       L_80091878
    if (!c1cs) {
        // 0x80091864: lwc1        $f10, 0xC($v0)
        ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
            goto L_80091878;
    }
    goto skip_3;
    // 0x80091864: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    skip_3:
    // 0x80091868: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
    // 0x8009186C: lw          $t0, 0x3C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X3C);
    // 0x80091870: addu        $v0, $t0, $v1
    ctx->r2 = ADD32(ctx->r8, ctx->r3);
    // 0x80091874: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
L_80091878:
    // 0x80091878: swc1        $f10, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f10.u32l;
    // 0x8009187C: lw          $t1, 0x3C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X3C);
    // 0x80091880: addu        $v0, $t1, $v1
    ctx->r2 = ADD32(ctx->r9, ctx->r3);
    // 0x80091884: lwc1        $f2, 0xC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80091888: c.eq.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl == ctx->f2.fl;
    // 0x8009188C: nop

    // 0x80091890: bc1tl       L_800918D8
    if (c1cs) {
        // 0x80091894: addiu       $v1, $v1, 0x18
        ctx->r3 = ADD32(ctx->r3, 0X18);
            goto L_800918D8;
    }
    goto skip_4;
    // 0x80091894: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    skip_4:
    // 0x80091898: lbu         $t2, 0x14($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X14);
    // 0x8009189C: beql        $t2, $zero, L_800918B0
    if (ctx->r10 == 0) {
        // 0x800918A0: sub.s       $f16, $f2, $f0
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_800918B0;
    }
    goto skip_5;
    // 0x800918A0: sub.s       $f16, $f2, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f0.fl;
    skip_5:
    // 0x800918A4: bnel        $a1, $zero, L_800918D8
    if (ctx->r5 != 0) {
        // 0x800918A8: addiu       $v1, $v1, 0x18
        ctx->r3 = ADD32(ctx->r3, 0X18);
            goto L_800918D8;
    }
    goto skip_6;
    // 0x800918A8: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    skip_6:
    // 0x800918AC: sub.s       $f16, $f2, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f0.fl;
L_800918B0:
    // 0x800918B0: swc1        $f16, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f16.u32l;
    // 0x800918B4: lw          $t3, 0x3C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X3C);
    // 0x800918B8: addu        $v0, $t3, $v1
    ctx->r2 = ADD32(ctx->r11, ctx->r3);
    // 0x800918BC: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800918C0: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x800918C4: nop

    // 0x800918C8: bc1fl       L_800918D8
    if (!c1cs) {
        // 0x800918CC: addiu       $v1, $v1, 0x18
        ctx->r3 = ADD32(ctx->r3, 0X18);
            goto L_800918D8;
    }
    goto skip_7;
    // 0x800918CC: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    skip_7:
    // 0x800918D0: swc1        $f12, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f12.u32l;
    // 0x800918D4: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
L_800918D8:
    // 0x800918D8: bnel        $v1, $a2, L_80091808
    if (ctx->r3 != ctx->r6) {
        // 0x800918DC: lw          $t6, 0x3C($a0)
        ctx->r14 = MEM_W(ctx->r4, 0X3C);
            goto L_80091808;
    }
    goto skip_8;
    // 0x800918DC: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    skip_8:
    // 0x800918E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800918E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800918E8: jr          $ra
    // 0x800918EC: nop

    return;
    // 0x800918EC: nop

;}
RECOMP_FUNC void func_80800120_bsbtrot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800120: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800124: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800128: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080012C: jal         0x80091A58
    // 0x80800130: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_0;
    // 0x80800130: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_0:
    // 0x80800134: beql        $v0, $zero, L_80800158
    if (ctx->r2 == 0) {
        // 0x80800138: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800158;
    }
    goto skip_0;
    // 0x80800138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080013C: jal         0x8008E39C
    // 0x80800140: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008E39C(rdram, ctx);
        goto after_1;
    // 0x80800140: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800144: beq         $v0, $zero, L_80800154
    if (ctx->r2 == 0) {
        // 0x80800148: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800154;
    }
    // 0x80800148: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080014C: jal         0x80085008
    // 0x80800150: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _bashoes_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x80800150: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
L_80800154:
    // 0x80800154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800158:
    // 0x80800158: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080015C: jr          $ra
    // 0x80800160: nop

    return;
    // 0x80800160: nop

;}
RECOMP_FUNC void func_8010DCB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010DCB4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8010DCB8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010DCBC: jal         0x80104148
    // 0x8010DCC0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_80104148(rdram, ctx);
        goto after_0;
    // 0x8010DCC0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8010DCC4: lbu         $v1, 0x4($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X4);
    // 0x8010DCC8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8010DCCC: blez        $v1, L_8010DD0C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8010DCD0: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_8010DD0C;
    }
    // 0x8010DCD0: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8010DCD4: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8010DCD8: bne         $t7, $zero, L_8010DD0C
    if (ctx->r15 != 0) {
        // 0x8010DCDC: sb          $t6, 0x4($v0)
        MEM_B(0X4, ctx->r2) = ctx->r14;
            goto L_8010DD0C;
    }
    // 0x8010DCDC: sb          $t6, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r14;
    // 0x8010DCE0: jal         0x801042D8
    // 0x8010DCE4: addiu       $a0, $v0, 0x2
    ctx->r4 = ADD32(ctx->r2, 0X2);
    func_801042D8(rdram, ctx);
        goto after_1;
    // 0x8010DCE4: addiu       $a0, $v0, 0x2
    ctx->r4 = ADD32(ctx->r2, 0X2);
    after_1:
    // 0x8010DCE8: jal         0x800ADFE0
    // 0x8010DCEC: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    func_800ADFE0(rdram, ctx);
        goto after_2;
    // 0x8010DCEC: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    after_2:
    // 0x8010DCF0: lh          $a0, 0x8($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X8);
    // 0x8010DCF4: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x8010DCF8: beql        $a0, $zero, L_8010DD10
    if (ctx->r4 == 0) {
        // 0x8010DCFC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8010DD10;
    }
    goto skip_0;
    // 0x8010DCFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8010DD00: jal         0x80100E18
    // 0x8010DD04: nop

    func_80100E18(rdram, ctx);
        goto after_3;
    // 0x8010DD04: nop

    after_3:
    // 0x8010DD08: sh          $zero, 0x8($s0)
    MEM_H(0X8, ctx->r16) = 0;
L_8010DD0C:
    // 0x8010DD0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8010DD10:
    // 0x8010DD10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8010DD14: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8010DD18: jr          $ra
    // 0x8010DD1C: nop

    return;
    // 0x8010DD1C: nop

;}
RECOMP_FUNC void bstnt_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080149C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808014A0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(404, 0X256C) << 16);
    // 0x808014A4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808014A8: jr          $ra
    // 0x808014AC: lw          $v0, 0x256C($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(404, 0X256C));
    return;
    // 0x808014AC: lw          $v0, 0x256C($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(404, 0X256C));
;}
RECOMP_FUNC void func_800C8F64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8F64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C8F68: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800C8F6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C8F70: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C8F74: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C8F78: lw          $a0, -0x5500($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5500);
    // 0x800C8F7C: jal         0x800B28CC
    // 0x800C8F80: addiu       $a1, $a2, -0x1
    ctx->r5 = ADD32(ctx->r6, -0X1);
    vector_at(rdram, ctx);
        goto after_0;
    // 0x800C8F80: addiu       $a1, $a2, -0x1
    ctx->r5 = ADD32(ctx->r6, -0X1);
    after_0:
    // 0x800C8F84: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800C8F88: lbu         $t6, 0x15($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X15);
    // 0x800C8F8C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C8F90: beql        $v1, $t6, L_800C8FA4
    if (ctx->r3 == ctx->r14) {
        // 0x800C8F94: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C8FA4;
    }
    goto skip_0;
    // 0x800C8F94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C8F98: sb          $v1, 0x15($v0)
    MEM_B(0X15, ctx->r2) = ctx->r3;
    // 0x800C8F9C: sb          $t7, 0x16($v0)
    MEM_B(0X16, ctx->r2) = ctx->r15;
    // 0x800C8FA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C8FA4:
    // 0x800C8FA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C8FA8: jr          $ra
    // 0x800C8FAC: nop

    return;
    // 0x800C8FAC: nop

;}
RECOMP_FUNC void func_8080189C_chtrashcangame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080189C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808018A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808018A4: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x808018A8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x808018AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808018B0: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x808018B4: beql        $t7, $zero, L_808018D8
    if (ctx->r15 == 0) {
        // 0x808018B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808018D8;
    }
    goto skip_0;
    // 0x808018B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808018BC: jal         0x800856B8
    // 0x808018C0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    _capod_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808018C0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x808018C4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x808018C8: lhu         $t8, 0x76($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X76);
    // 0x808018CC: andi        $t9, $t8, 0x7F
    ctx->r25 = ctx->r24 & 0X7F;
    // 0x808018D0: sh          $t9, 0x76($a1)
    MEM_H(0X76, ctx->r5) = ctx->r25;
    // 0x808018D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808018D8:
    // 0x808018D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808018DC: jr          $ra
    // 0x808018E0: nop

    return;
    // 0x808018E0: nop

;}
RECOMP_FUNC void func_8080097C_choildrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080097C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800980: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800984: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800988: jal         0x800D90A4
    // 0x8080098C: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_0;
    // 0x8080098C: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_0:
    // 0x80800990: beq         $v0, $zero, L_808009E8
    if (ctx->r2 == 0) {
        // 0x80800994: lw          $a1, 0x28($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X28);
            goto L_808009E8;
    }
    // 0x80800994: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800998: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8080099C: jal         0x800EE7F8
    // 0x808009A0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x808009A0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_1:
    // 0x808009A4: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x808009A8: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    // 0x808009AC: lui         $a2, 0xC348
    ctx->r6 = S32(0XC348 << 16);
    // 0x808009B0: jal         0x800C6920
    // 0x808009B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800C6920(rdram, ctx);
        goto after_2;
    // 0x808009B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x808009B8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808009BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808009C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808009C4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x808009C8: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x808009CC: jal         0x8080086C
    // 0x808009D0: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    choildrill_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x808009D0: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x808009D4: jal         0x800DC0C0
    // 0x808009D8: nop

    func_800DC0C0(rdram, ctx);
        goto after_4;
    // 0x808009D8: nop

    after_4:
    // 0x808009DC: add.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x808009E0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x808009E4: swc1        $f8, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f8.u32l;
L_808009E8:
    // 0x808009E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808009EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808009F0: jr          $ra
    // 0x808009F4: nop

    return;
    // 0x808009F4: nop

;}
RECOMP_FUNC void func_8009E71C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E71C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009E720: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009E724: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8009E728: lw          $t6, 0x120($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X120);
    // 0x8009E72C: jal         0x8009CBDC
    // 0x8009E730: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    func_8009CBDC(rdram, ctx);
        goto after_0;
    // 0x8009E730: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    after_0:
    // 0x8009E734: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8009E738: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009E73C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009E740: xor         $v0, $v0, $t7
    ctx->r2 = ctx->r2 ^ ctx->r15;
    // 0x8009E744: jr          $ra
    // 0x8009E748: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    return;
    // 0x8009E748: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void func_80800E30_chstonepillar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800E34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E38: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800E3C: jal         0x80100094
    // 0x80800E40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800E40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800E44: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800E48: jal         0x80800DD8
    // 0x80800E4C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800DD8_chstonepillar(rdram, ctx);
        goto after_1;
    // 0x80800E4C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800E50: bne         $v0, $zero, L_80800E80
    if (ctx->r2 != 0) {
        // 0x80800E54: nop
    
            goto L_80800E80;
    }
    // 0x80800E54: nop

    // 0x80800E58: jal         0x800DA524
    // 0x80800E5C: addiu       $a0, $zero, 0x9D5
    ctx->r4 = ADD32(0, 0X9D5);
    func_800DA524(rdram, ctx);
        goto after_2;
    // 0x80800E5C: addiu       $a0, $zero, 0x9D5
    ctx->r4 = ADD32(0, 0X9D5);
    after_2:
    // 0x80800E60: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E64: addiu       $a0, $zero, 0x9CD
    ctx->r4 = ADD32(0, 0X9CD);
    // 0x80800E68: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800E6C: lh          $a1, 0x2C($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X2C);
    // 0x80800E70: jal         0x800DA7A8
    // 0x80800E74: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    func_800DA7A8(rdram, ctx);
        goto after_3;
    // 0x80800E74: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    after_3:
    // 0x80800E78: b           L_80800ED4
    // 0x80800E7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800ED4;
    // 0x80800E7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800E80:
    // 0x80800E80: jal         0x800F54E4
    // 0x80800E84: nop

    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x80800E84: nop

    after_4:
    // 0x80800E88: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800E8C: jal         0x800F7F98
    // 0x80800E90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F7F98(rdram, ctx);
        goto after_5;
    // 0x80800E90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80800E94: jal         0x800F54E4
    // 0x80800E98: nop

    func_800F54E4(rdram, ctx);
        goto after_6;
    // 0x80800E98: nop

    after_6:
    // 0x80800E9C: jal         0x800F6CC8
    // 0x80800EA0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6CC8(rdram, ctx);
        goto after_7;
    // 0x80800EA0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x80800EA4: bnel        $v0, $zero, L_80800ED4
    if (ctx->r2 != 0) {
        // 0x80800EA8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800ED4;
    }
    goto skip_0;
    // 0x80800EA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800EAC: jal         0x800DA544
    // 0x80800EB0: addiu       $a0, $zero, 0x9D5
    ctx->r4 = ADD32(0, 0X9D5);
    func_800DA544(rdram, ctx);
        goto after_8;
    // 0x80800EB0: addiu       $a0, $zero, 0x9D5
    ctx->r4 = ADD32(0, 0X9D5);
    after_8:
    // 0x80800EB4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80800EB8: lh          $a0, 0x2C($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X2C);
    // 0x80800EBC: jal         0x800DA544
    // 0x80800EC0: addiu       $a0, $a0, 0x65C
    ctx->r4 = ADD32(ctx->r4, 0X65C);
    func_800DA544(rdram, ctx);
        goto after_9;
    // 0x80800EC0: addiu       $a0, $a0, 0x65C
    ctx->r4 = ADD32(ctx->r4, 0X65C);
    after_9:
    // 0x80800EC4: addiu       $a0, $zero, 0xB9
    ctx->r4 = ADD32(0, 0XB9);
    // 0x80800EC8: jal         0x800887D8
    // 0x80800ECC: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_10;
    // 0x80800ECC: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_10:
    // 0x80800ED0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800ED4:
    // 0x80800ED4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800ED8: jr          $ra
    // 0x80800EDC: nop

    return;
    // 0x80800EDC: nop

;}
RECOMP_FUNC void func_800BE4C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE4C4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BE4C8: addiu       $v1, $v1, -0x7BF0
    ctx->r3 = ADD32(ctx->r3, -0X7BF0);
    // 0x800BE4CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800BE4D0: lw          $t6, 0x24($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X24);
    // 0x800BE4D4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800BE4D8: lw          $s0, 0x0($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X0);
    // 0x800BE4DC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800BE4E0: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800BE4E4: addu        $s1, $t7, $s0
    ctx->r17 = ADD32(ctx->r15, ctx->r16);
    // 0x800BE4E8: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x800BE4EC: beq         $at, $zero, L_800BE50C
    if (ctx->r1 == 0) {
        // 0x800BE4F0: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_800BE50C;
    }
    // 0x800BE4F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
L_800BE4F4:
    // 0x800BE4F4: jal         0x800E9CF4
    // 0x800BE4F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E9CF4(rdram, ctx);
        goto after_0;
    // 0x800BE4F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800BE4FC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800BE500: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x800BE504: bne         $at, $zero, L_800BE4F4
    if (ctx->r1 != 0) {
        // 0x800BE508: nop
    
            goto L_800BE4F4;
    }
    // 0x800BE508: nop

L_800BE50C:
    // 0x800BE50C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BE510: jal         0x800E9CF4
    // 0x800BE514: addiu       $a0, $a0, -0x7BBC
    ctx->r4 = ADD32(ctx->r4, -0X7BBC);
    func_800E9CF4(rdram, ctx);
        goto after_1;
    // 0x800BE514: addiu       $a0, $a0, -0x7BBC
    ctx->r4 = ADD32(ctx->r4, -0X7BBC);
    after_1:
    // 0x800BE518: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800BE51C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800BE520: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800BE524: jr          $ra
    // 0x800BE528: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800BE528: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8008F938(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F938: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008F93C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008F940: jal         0x800F54E4
    // 0x8008F944: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8008F944: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008F948: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008F94C: jal         0x800F4A00
    // 0x8008F950: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800F4A00(rdram, ctx);
        goto after_1;
    // 0x8008F950: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8008F954: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008F958: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008F95C: jr          $ra
    // 0x8008F960: nop

    return;
    // 0x8008F960: nop

;}
RECOMP_FUNC void func_808017A0_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808017A0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808017A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808017A8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808017AC: lui         $a1, 0x38D1
    ctx->r5 = S32(0X38D1 << 16);
    // 0x808017B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808017B4: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x808017B8: jal         0x8008CB10
    // 0x808017BC: ori         $a1, $a1, 0xB717
    ctx->r5 = ctx->r5 | 0XB717;
    baanim_isAt(rdram, ctx);
        goto after_0;
    // 0x808017BC: ori         $a1, $a1, 0xB717
    ctx->r5 = ctx->r5 | 0XB717;
    after_0:
    // 0x808017C0: beq         $v0, $zero, L_808017DC
    if (ctx->r2 == 0) {
        // 0x808017C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808017DC;
    }
    // 0x808017C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017C8: lui         $a2, 0x3F8C
    ctx->r6 = S32(0X3F8C << 16);
    // 0x808017CC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808017D0: addiu       $a1, $zero, 0x5E7
    ctx->r5 = ADD32(0, 0X5E7);
    // 0x808017D4: jal         0x8009DB04
    // 0x808017D8: addiu       $a3, $zero, 0x4E20
    ctx->r7 = ADD32(0, 0X4E20);
    func_8009DB04(rdram, ctx);
        goto after_1;
    // 0x808017D8: addiu       $a3, $zero, 0x4E20
    ctx->r7 = ADD32(0, 0X4E20);
    after_1:
L_808017DC:
    // 0x808017DC: lui         $a1, 0x3DD7
    ctx->r5 = S32(0X3DD7 << 16);
    // 0x808017E0: ori         $a1, $a1, 0x7319
    ctx->r5 = ctx->r5 | 0X7319;
    // 0x808017E4: jal         0x8008CB10
    // 0x808017E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_2;
    // 0x808017E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808017EC: beq         $v0, $zero, L_80801808
    if (ctx->r2 == 0) {
        // 0x808017F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801808;
    }
    // 0x808017F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017F4: lui         $a2, 0x3F8C
    ctx->r6 = S32(0X3F8C << 16);
    // 0x808017F8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808017FC: addiu       $a1, $zero, 0x519
    ctx->r5 = ADD32(0, 0X519);
    // 0x80801800: jal         0x8009DB04
    // 0x80801804: addiu       $a3, $zero, 0x4E20
    ctx->r7 = ADD32(0, 0X4E20);
    func_8009DB04(rdram, ctx);
        goto after_3;
    // 0x80801804: addiu       $a3, $zero, 0x4E20
    ctx->r7 = ADD32(0, 0X4E20);
    after_3:
L_80801808:
    // 0x80801808: lui         $a1, 0x3E8C
    ctx->r5 = S32(0X3E8C << 16);
    // 0x8080180C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80801810: jal         0x8008CB10
    // 0x80801814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_4;
    // 0x80801814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801818: beq         $v0, $zero, L_80801834
    if (ctx->r2 == 0) {
        // 0x8080181C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801834;
    }
    // 0x8080181C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801820: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x80801824: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80801828: addiu       $a1, $zero, 0x5E7
    ctx->r5 = ADD32(0, 0X5E7);
    // 0x8080182C: jal         0x8009DB04
    // 0x80801830: addiu       $a3, $zero, 0x4E20
    ctx->r7 = ADD32(0, 0X4E20);
    func_8009DB04(rdram, ctx);
        goto after_5;
    // 0x80801830: addiu       $a3, $zero, 0x4E20
    ctx->r7 = ADD32(0, 0X4E20);
    after_5:
L_80801834:
    // 0x80801834: lui         $a1, 0x3F5B
    ctx->r5 = S32(0X3F5B << 16);
    // 0x80801838: ori         $a1, $a1, 0x7176
    ctx->r5 = ctx->r5 | 0X7176;
    // 0x8080183C: jal         0x8008CB10
    // 0x80801840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_6;
    // 0x80801840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80801844: beq         $v0, $zero, L_80801860
    if (ctx->r2 == 0) {
        // 0x80801848: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801860;
    }
    // 0x80801848: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080184C: lui         $a2, 0x3F8C
    ctx->r6 = S32(0X3F8C << 16);
    // 0x80801850: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80801854: addiu       $a1, $zero, 0x5E7
    ctx->r5 = ADD32(0, 0X5E7);
    // 0x80801858: jal         0x8009DB04
    // 0x8080185C: addiu       $a3, $zero, 0x4E20
    ctx->r7 = ADD32(0, 0X4E20);
    func_8009DB04(rdram, ctx);
        goto after_7;
    // 0x8080185C: addiu       $a3, $zero, 0x4E20
    ctx->r7 = ADD32(0, 0X4E20);
    after_7:
L_80801860:
    // 0x80801860: lui         $a1, 0x3F6E
    ctx->r5 = S32(0X3F6E << 16);
    // 0x80801864: ori         $a1, $a1, 0x147B
    ctx->r5 = ctx->r5 | 0X147B;
    // 0x80801868: jal         0x8008CB10
    // 0x8080186C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_8;
    // 0x8080186C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80801870: beq         $v0, $zero, L_8080188C
    if (ctx->r2 == 0) {
        // 0x80801874: addiu       $a1, $zero, 0x5E7
        ctx->r5 = ADD32(0, 0X5E7);
            goto L_8080188C;
    }
    // 0x80801874: addiu       $a1, $zero, 0x5E7
    ctx->r5 = ADD32(0, 0X5E7);
    // 0x80801878: lui         $a2, 0x3F59
    ctx->r6 = S32(0X3F59 << 16);
    // 0x8080187C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80801880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801884: jal         0x8009DB04
    // 0x80801888: addiu       $a3, $zero, 0x4E20
    ctx->r7 = ADD32(0, 0X4E20);
    func_8009DB04(rdram, ctx);
        goto after_9;
    // 0x80801888: addiu       $a3, $zero, 0x4E20
    ctx->r7 = ADD32(0, 0X4E20);
    after_9:
L_8080188C:
    // 0x8080188C: lw          $t6, 0x15C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X15C);
    // 0x80801890: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80801894: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x80801898: beq         $at, $zero, L_80801ADC
    if (ctx->r1 == 0) {
        // 0x8080189C: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80801ADC;
    }
    // 0x8080189C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808018A0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(443, 0X1D20) << 16);
    // 0x808018A4: addu        $at, $at, $t7
    gpr jr_addend_808018AC = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808018A8: lw          $t7, 0x1D20($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(443, 0X1D20));
    // 0x808018AC: jr          $t7
    // 0x808018B0: nop

    switch (jr_addend_808018AC >> 2) {
        case 0: goto L_808018B4; break;
        case 1: goto L_808018DC; break;
        case 2: goto L_80801950; break;
        case 3: goto L_80801A58; break;
        case 4: goto L_80801AC8; break;
        default: switch_error(__func__, 0x808018AC, 0x80801D20);
    }
    // 0x808018B0: nop

L_808018B4:
    // 0x808018B4: lui         $a1, 0x3D8F
    ctx->r5 = S32(0X3D8F << 16);
    // 0x808018B8: ori         $a1, $a1, 0x5C29
    ctx->r5 = ctx->r5 | 0X5C29;
    // 0x808018BC: jal         0x8008CB10
    // 0x808018C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_10;
    // 0x808018C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808018C4: beq         $v0, $zero, L_80801ADC
    if (ctx->r2 == 0) {
        // 0x808018C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801ADC;
    }
    // 0x808018C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808018CC: jal         0x808015EC
    // 0x808018D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808015EC_bswasher(rdram, ctx);
        goto after_11;
    // 0x808018D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_11:
    // 0x808018D4: b           L_80801AE0
    // 0x808018D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801AE0;
    // 0x808018D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808018DC:
    // 0x808018DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808018E0: jal         0x80085408
    // 0x808018E4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    _bawasher_entrypoint_3(rdram, ctx);
        goto after_12;
    // 0x808018E4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_12:
    // 0x808018E8: jal         0x8008CAC8
    // 0x808018EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getTimer(rdram, ctx);
        goto after_13;
    // 0x808018EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808018F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(443, 0X1D34) << 16);
    // 0x808018F4: lwc1        $f14, 0x1D34($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(443, 0X1D34));
    // 0x808018F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808018FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801900: lui         $a2, 0x3DF5
    ctx->r6 = S32(0X3DF5 << 16);
    // 0x80801904: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x80801908: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8080190C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80801910: jal         0x800F10B4
    // 0x80801914: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_14;
    // 0x80801914: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_14:
    // 0x80801918: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080191C: lw          $a0, 0x160($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X160);
    // 0x80801920: jal         0x80087320
    // 0x80801924: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    _chfactoryworkerdirty_entrypoint_2(rdram, ctx);
        goto after_15;
    // 0x80801924: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_15:
    // 0x80801928: lui         $a1, 0x3DF5
    ctx->r5 = S32(0X3DF5 << 16);
    // 0x8080192C: ori         $a1, $a1, 0xC28F
    ctx->r5 = ctx->r5 | 0XC28F;
    // 0x80801930: jal         0x8008CB10
    // 0x80801934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_16;
    // 0x80801934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80801938: beq         $v0, $zero, L_80801ADC
    if (ctx->r2 == 0) {
        // 0x8080193C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801ADC;
    }
    // 0x8080193C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801940: jal         0x808015EC
    // 0x80801944: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808015EC_bswasher(rdram, ctx);
        goto after_17;
    // 0x80801944: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_17:
    // 0x80801948: b           L_80801AE0
    // 0x8080194C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801AE0;
    // 0x8080194C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801950:
    // 0x80801950: lui         $a1, 0x3E96
    ctx->r5 = S32(0X3E96 << 16);
    // 0x80801954: ori         $a1, $a1, 0xFD22
    ctx->r5 = ctx->r5 | 0XFD22;
    // 0x80801958: jal         0x8008CB10
    // 0x8080195C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_18;
    // 0x8080195C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80801960: beq         $v0, $zero, L_8080197C
    if (ctx->r2 == 0) {
        // 0x80801964: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080197C;
    }
    // 0x80801964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801968: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(443, 0X1EB0) << 16);
    // 0x8080196C: addiu       $a2, $a2, 0x1EB0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(443, 0X1EB0));
    // 0x80801970: jal         0x8009D454
    // 0x80801974: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D454(rdram, ctx);
        goto after_19;
    // 0x80801974: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_19:
    // 0x80801978: sb          $v0, 0x164($s0)
    MEM_B(0X164, ctx->r16) = ctx->r2;
L_8080197C:
    // 0x8080197C: jal         0x8008CAC8
    // 0x80801980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getTimer(rdram, ctx);
        goto after_20;
    // 0x80801980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80801984: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(443, 0X1D38) << 16);
    // 0x80801988: lwc1        $f2, 0x1D38($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(443, 0X1D38));
    // 0x8080198C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80801990: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(443, 0X1D40) << 16);
    // 0x80801994: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80801998: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8080199C: bc1f        L_808019CC
    if (!c1cs) {
        // 0x808019A0: nop
    
            goto L_808019CC;
    }
    // 0x808019A0: nop

    // 0x808019A4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(443, 0X1D3C) << 16);
    // 0x808019A8: lwc1        $f14, 0x1D3C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(443, 0X1D3C));
    // 0x808019AC: lui         $at, 0x44AF
    ctx->r1 = S32(0X44AF << 16);
    // 0x808019B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808019B4: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x808019B8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x808019BC: jal         0x800F10B4
    // 0x808019C0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_21;
    // 0x808019C0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_21:
    // 0x808019C4: b           L_808019E8
    // 0x808019C8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
        goto L_808019E8;
    // 0x808019C8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_808019CC:
    // 0x808019CC: lwc1        $f14, 0x1D40($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(443, 0X1D40));
    // 0x808019D0: lui         $at, 0x44AF
    ctx->r1 = S32(0X44AF << 16);
    // 0x808019D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808019D8: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x808019DC: jal         0x800F10B4
    // 0x808019E0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_22;
    // 0x808019E0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_22:
    // 0x808019E4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_808019E8:
    // 0x808019E8: lw          $a0, 0x160($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X160);
    // 0x808019EC: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x808019F0: jal         0x80087328
    // 0x808019F4: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    _chfactoryworkerdirty_entrypoint_3(rdram, ctx);
        goto after_23;
    // 0x808019F4: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    after_23:
    // 0x808019F8: lbu         $t8, 0x164($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X164);
    // 0x808019FC: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80801A00: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    // 0x80801A04: beq         $t8, $zero, L_80801A30
    if (ctx->r24 == 0) {
        // 0x80801A08: lui         $a3, 0x3F4C
        ctx->r7 = S32(0X3F4C << 16);
            goto L_80801A30;
    }
    // 0x80801A08: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x80801A0C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(443, 0X1D44) << 16);
    // 0x80801A10: lwc1        $f10, 0x1D44($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(443, 0X1D44));
    // 0x80801A14: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80801A18: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80801A1C: jal         0x800F10B4
    // 0x80801A20: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_24;
    // 0x80801A20: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_24:
    // 0x80801A24: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80801A28: jal         0x800C31DC
    // 0x80801A2C: lbu         $a0, 0x164($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X164);
    func_800C31DC(rdram, ctx);
        goto after_25;
    // 0x80801A2C: lbu         $a0, 0x164($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X164);
    after_25:
L_80801A30:
    // 0x80801A30: lui         $a1, 0x3F63
    ctx->r5 = S32(0X3F63 << 16);
    // 0x80801A34: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80801A38: jal         0x8008CB10
    // 0x80801A3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_26;
    // 0x80801A3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80801A40: beq         $v0, $zero, L_80801ADC
    if (ctx->r2 == 0) {
        // 0x80801A44: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801ADC;
    }
    // 0x80801A44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A48: jal         0x808015EC
    // 0x80801A4C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808015EC_bswasher(rdram, ctx);
        goto after_27;
    // 0x80801A4C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_27:
    // 0x80801A50: b           L_80801AE0
    // 0x80801A54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801AE0;
    // 0x80801A54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801A58:
    // 0x80801A58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A5C: jal         0x80085408
    // 0x80801A60: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    _bawasher_entrypoint_3(rdram, ctx);
        goto after_28;
    // 0x80801A60: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_28:
    // 0x80801A64: jal         0x8008CAC8
    // 0x80801A68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getTimer(rdram, ctx);
        goto after_29;
    // 0x80801A68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x80801A6C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80801A70: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(443, 0X1D48) << 16);
    // 0x80801A74: lui         $a2, 0x3F70
    ctx->r6 = S32(0X3F70 << 16);
    // 0x80801A78: ori         $a2, $a2, 0xA3D7
    ctx->r6 = ctx->r6 | 0XA3D7;
    // 0x80801A7C: lwc1        $f14, 0x1D48($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(443, 0X1D48));
    // 0x80801A80: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80801A84: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80801A88: jal         0x800F10B4
    // 0x80801A8C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F10B4(rdram, ctx);
        goto after_30;
    // 0x80801A8C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_30:
    // 0x80801A90: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80801A94: lw          $a0, 0x160($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X160);
    // 0x80801A98: jal         0x80087320
    // 0x80801A9C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    _chfactoryworkerdirty_entrypoint_2(rdram, ctx);
        goto after_31;
    // 0x80801A9C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_31:
    // 0x80801AA0: lui         $a1, 0x3F70
    ctx->r5 = S32(0X3F70 << 16);
    // 0x80801AA4: ori         $a1, $a1, 0xA3D7
    ctx->r5 = ctx->r5 | 0XA3D7;
    // 0x80801AA8: jal         0x8008CB10
    // 0x80801AAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_32;
    // 0x80801AAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x80801AB0: beq         $v0, $zero, L_80801ADC
    if (ctx->r2 == 0) {
        // 0x80801AB4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801ADC;
    }
    // 0x80801AB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801AB8: jal         0x808015EC
    // 0x80801ABC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808015EC_bswasher(rdram, ctx);
        goto after_33;
    // 0x80801ABC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_33:
    // 0x80801AC0: b           L_80801AE0
    // 0x80801AC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801AE0;
    // 0x80801AC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801AC8:
    // 0x80801AC8: jal         0x8008CAEC
    // 0x80801ACC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_34;
    // 0x80801ACC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x80801AD0: beq         $v0, $zero, L_80801ADC
    if (ctx->r2 == 0) {
        // 0x80801AD4: addiu       $t9, $zero, 0x32
        ctx->r25 = ADD32(0, 0X32);
            goto L_80801ADC;
    }
    // 0x80801AD4: addiu       $t9, $zero, 0x32
    ctx->r25 = ADD32(0, 0X32);
    // 0x80801AD8: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
L_80801ADC:
    // 0x80801ADC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801AE0:
    // 0x80801AE0: jal         0x8009E5C8
    // 0x80801AE4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    bs_setState(rdram, ctx);
        goto after_35;
    // 0x80801AE4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_35:
    // 0x80801AE8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801AEC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801AF0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80801AF4: jr          $ra
    // 0x80801AF8: nop

    return;
    // 0x80801AF8: nop

;}
RECOMP_FUNC void func_80801CD0_sucoasterfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801CD0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80801CD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801CD8: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80801CDC: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80801CE0: jal         0x80100094
    // 0x80801CE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801CE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801CE8: lbu         $a0, 0x11($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X11);
    // 0x80801CEC: srl         $t6, $a0, 4
    ctx->r14 = S32(U32(ctx->r4) >> 4);
    // 0x80801CF0: jal         0x8008A270
    // 0x80801CF4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    _sucoasterflydata_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80801CF4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_1:
    // 0x80801CF8: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x80801CFC: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80801D00: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80801D04: sll         $t7, $v1, 3
    ctx->r15 = S32(ctx->r3 << 3);
    // 0x80801D08: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80801D0C: lh          $t9, 0x4($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X4);
    // 0x80801D10: beql        $t9, $zero, L_80801DC4
    if (ctx->r25 == 0) {
        // 0x80801D14: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801DC4;
    }
    goto skip_0;
    // 0x80801D14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801D18: jal         0x8010D640
    // 0x80801D1C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    func_8010D640(rdram, ctx);
        goto after_2;
    // 0x80801D1C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    after_2:
    // 0x80801D20: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80801D24: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80801D28: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80801D2C: jal         0x800EEB40
    // 0x80801D30: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_800EEB40(rdram, ctx);
        goto after_3;
    // 0x80801D30: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_3:
    // 0x80801D34: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3210, 0X2270) << 16);
    // 0x80801D38: lwc1        $f4, 0x2270($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3210, 0X2270));
    // 0x80801D3C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3210, 0X2274) << 16);
    // 0x80801D40: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80801D44: nop

    // 0x80801D48: bc1tl       L_80801DC4
    if (c1cs) {
        // 0x80801D4C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801DC4;
    }
    goto skip_1;
    // 0x80801D4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80801D50: lwc1        $f12, 0x2274($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3210, 0X2274));
    // 0x80801D54: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3210, 0X2278) << 16);
    // 0x80801D58: jal         0x800DC178
    // 0x80801D5C: lwc1        $f14, 0x2278($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3210, 0X2278));
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x80801D5C: lwc1        $f14, 0x2278($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3210, 0X2278));
    after_4:
    // 0x80801D60: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80801D64: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80801D68: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x80801D6C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801D70: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x80801D74: lh          $t2, 0x8($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X8);
    // 0x80801D78: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80801D7C: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80801D80: nop

    // 0x80801D84: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80801D88: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80801D8C: jal         0x800C4B64
    // 0x80801D90: add.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f16.fl;
    func_800C4B64(rdram, ctx);
        goto after_5;
    // 0x80801D90: add.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f16.fl;
    after_5:
    // 0x80801D94: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80801D98: jal         0x800C4B7C
    // 0x80801D9C: lh          $a0, 0x4($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X4);
    func_800C4B7C(rdram, ctx);
        goto after_6;
    // 0x80801D9C: lh          $a0, 0x4($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X4);
    after_6:
    // 0x80801DA0: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80801DA4: jal         0x800C4B70
    // 0x80801DA8: lh          $a0, 0x6($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X6);
    func_800C4B70(rdram, ctx);
        goto after_7;
    // 0x80801DA8: lh          $a0, 0x6($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X6);
    after_7:
    // 0x80801DAC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(3210, 0X22BC) << 16);
    // 0x80801DB0: addiu       $a2, $a2, 0x22BC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(3210, 0X22BC));
    // 0x80801DB4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80801DB8: jal         0x80089D18
    // 0x80801DBC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x80801DBC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_8:
    // 0x80801DC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801DC4:
    // 0x80801DC4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80801DC8: jr          $ra
    // 0x80801DCC: nop

    return;
    // 0x80801DCC: nop

;}
RECOMP_FUNC void func_808003A8_bsbwhirl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808003AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003B0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808003B4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808003B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003BC: jal         0x8009EF10
    // 0x808003C0: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    bastick_getZone(rdram, ctx);
        goto after_0;
    // 0x808003C0: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    after_0:
    // 0x808003C4: blez        $v0, L_808003D0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808003C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003D0;
    }
    // 0x808003C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003CC: addiu       $s1, $zero, 0x1C
    ctx->r17 = ADD32(0, 0X1C);
L_808003D0:
    // 0x808003D0: jal         0x80091A30
    // 0x808003D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_released(rdram, ctx);
        goto after_1;
    // 0x808003D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808003D8: beq         $v0, $zero, L_808003E4
    if (ctx->r2 == 0) {
        // 0x808003DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003E4;
    }
    // 0x808003DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003E0: addiu       $s1, $zero, 0x1E
    ctx->r17 = ADD32(0, 0X1E);
L_808003E4:
    // 0x808003E4: jal         0x80091A58
    // 0x808003E8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_2;
    // 0x808003E8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_2:
    // 0x808003EC: beq         $v0, $zero, L_80800408
    if (ctx->r2 == 0) {
        // 0x808003F0: nop
    
            goto L_80800408;
    }
    // 0x808003F0: nop

    // 0x808003F4: jal         0x8008E078
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_3;
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808003FC: beq         $v0, $zero, L_80800408
    if (ctx->r2 == 0) {
        // 0x80800400: nop
    
            goto L_80800408;
    }
    // 0x80800400: nop

    // 0x80800404: addiu       $s1, $zero, 0x1D
    ctx->r17 = ADD32(0, 0X1D);
L_80800408:
    // 0x80800408: jal         0x8008E35C
    // 0x8080040C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_4;
    // 0x8080040C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800410: beq         $v0, $zero, L_8080041C
    if (ctx->r2 == 0) {
        // 0x80800414: lw          $s0, 0x14($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X14);
            goto L_8080041C;
    }
    // 0x80800414: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800418: addiu       $s1, $zero, 0x2D
    ctx->r17 = ADD32(0, 0X2D);
L_8080041C:
    // 0x8080041C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800420: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80800424: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800428: jr          $ra
    // 0x8080042C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8080042C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
