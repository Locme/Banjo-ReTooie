#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _chcollballcontrol_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086EB0: syscall     467
    recomp_syscall_handler(rdram, ctx, 0x80086EB0);
    return;
    // 0x80086EB4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _bsbwhirl_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082D90: syscall     30
    recomp_syscall_handler(rdram, ctx, 0x80082D90);
    return;
    // 0x80082D94: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void chlagoonufoint_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800720: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(748, 0X19C0) << 16);
    // 0x80800724: jr          $ra
    // 0x80800728: addiu       $v0, $v0, 0x19C0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(748, 0X19C0));
    return;
    // 0x80800728: addiu       $v0, $v0, 0x19C0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(748, 0X19C0));
;}
RECOMP_FUNC void bsbkflamethrower_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800274: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800278: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080027C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800280: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800284: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80800288: jal         0x80085300
    // 0x8080028C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_get(rdram, ctx);
        goto after_0;
    // 0x8080028C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800290: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800298: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x8080029C: nop

    // 0x808002A0: bc1tl       L_808002C0
    if (c1cs) {
        // 0x808002A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002C0;
    }
    goto skip_0;
    // 0x808002A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808002A8: jal         0x80091A58
    // 0x808002AC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_1;
    // 0x808002AC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_1:
    // 0x808002B0: beq         $v0, $zero, L_808002BC
    if (ctx->r2 == 0) {
        // 0x808002B4: addiu       $t6, $zero, 0x189
        ctx->r14 = ADD32(0, 0X189);
            goto L_808002BC;
    }
    // 0x808002B4: addiu       $t6, $zero, 0x189
    ctx->r14 = ADD32(0, 0X189);
    // 0x808002B8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_808002BC:
    // 0x808002BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808002C0:
    // 0x808002C0: jal         0x800852F0
    // 0x808002C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_2;
    // 0x808002C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808002C8: lw          $v1, 0x15C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X15C);
    // 0x808002CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002D4: beq         $v1, $at, L_80800308
    if (ctx->r3 == ctx->r1) {
        // 0x808002D8: lui         $a1, 0x3E61
        ctx->r5 = S32(0X3E61 << 16);
            goto L_80800308;
    }
    // 0x808002D8: lui         $a1, 0x3E61
    ctx->r5 = S32(0X3E61 << 16);
    // 0x808002DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808002E0: beq         $v1, $at, L_80800350
    if (ctx->r3 == ctx->r1) {
        // 0x808002E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800350;
    }
    // 0x808002E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808002EC: beq         $v1, $at, L_8080038C
    if (ctx->r3 == ctx->r1) {
        // 0x808002F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080038C;
    }
    // 0x808002F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002F4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808002F8: beq         $v1, $at, L_808003AC
    if (ctx->r3 == ctx->r1) {
        // 0x808002FC: nop
    
            goto L_808003AC;
    }
    // 0x808002FC: nop

    // 0x80800300: b           L_808003F0
    // 0x80800304: nop

        goto L_808003F0;
    // 0x80800304: nop

L_80800308:
    // 0x80800308: jal         0x8008CB10
    // 0x8080030C: ori         $a1, $a1, 0x47AE
    ctx->r5 = ctx->r5 | 0X47AE;
    baanim_isAt(rdram, ctx);
        goto after_3;
    // 0x8080030C: ori         $a1, $a1, 0x47AE
    ctx->r5 = ctx->r5 | 0X47AE;
    after_3:
    // 0x80800310: beq         $v0, $zero, L_80800328
    if (ctx->r2 == 0) {
        // 0x80800314: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800328;
    }
    // 0x80800314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800318: addiu       $a1, $zero, 0x459F
    ctx->r5 = ADD32(0, 0X459F);
    // 0x8080031C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800320: jal         0x8009DF18
    // 0x80800324: addiu       $a3, $zero, 0x6590
    ctx->r7 = ADD32(0, 0X6590);
    func_8009DF18(rdram, ctx);
        goto after_4;
    // 0x80800324: addiu       $a3, $zero, 0x6590
    ctx->r7 = ADD32(0, 0X6590);
    after_4:
L_80800328:
    // 0x80800328: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x8080032C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800330: jal         0x8008CB10
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_5;
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800338: beq         $v0, $zero, L_808003F0
    if (ctx->r2 == 0) {
        // 0x8080033C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003F0;
    }
    // 0x8080033C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800340: jal         0x80800094
    // 0x80800344: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800094_bsbkflamethrower(rdram, ctx);
        goto after_6;
    // 0x80800344: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x80800348: b           L_808003F0
    // 0x8080034C: nop

        goto L_808003F0;
    // 0x8080034C: nop

L_80800350:
    // 0x80800350: jal         0x800852F0
    // 0x80800354: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _batimer_decrement(rdram, ctx);
        goto after_7;
    // 0x80800354: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x80800358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080035C: jal         0x80085330
    // 0x80800360: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _batimer_isZero(rdram, ctx);
        goto after_8;
    // 0x80800360: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x80800364: beq         $v0, $zero, L_808003F0
    if (ctx->r2 == 0) {
        // 0x80800368: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003F0;
    }
    // 0x80800368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080036C: jal         0x80091A30
    // 0x80800370: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_released(rdram, ctx);
        goto after_9;
    // 0x80800370: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_9:
    // 0x80800374: beq         $v0, $zero, L_808003F0
    if (ctx->r2 == 0) {
        // 0x80800378: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003F0;
    }
    // 0x80800378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080037C: jal         0x80800094
    // 0x80800380: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800094_bsbkflamethrower(rdram, ctx);
        goto after_10;
    // 0x80800380: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_10:
    // 0x80800384: b           L_808003F0
    // 0x80800388: nop

        goto L_808003F0;
    // 0x80800388: nop

L_8080038C:
    // 0x8080038C: jal         0x800852F0
    // 0x80800390: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _batimer_decrement(rdram, ctx);
        goto after_11;
    // 0x80800390: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80800394: beq         $v0, $zero, L_808003F0
    if (ctx->r2 == 0) {
        // 0x80800398: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003F0;
    }
    // 0x80800398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080039C: jal         0x80800094
    // 0x808003A0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800094_bsbkflamethrower(rdram, ctx);
        goto after_12;
    // 0x808003A0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_12:
    // 0x808003A4: b           L_808003F0
    // 0x808003A8: nop

        goto L_808003F0;
    // 0x808003A8: nop

L_808003AC:
    // 0x808003AC: jal         0x8008CAEC
    // 0x808003B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_13;
    // 0x808003B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808003B4: beq         $v0, $zero, L_808003C0
    if (ctx->r2 == 0) {
        // 0x808003B8: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_808003C0;
    }
    // 0x808003B8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808003BC: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_808003C0:
    // 0x808003C0: jal         0x8008CAC8
    // 0x808003C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getTimer(rdram, ctx);
        goto after_14;
    // 0x808003C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808003C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(100, 0X448) << 16);
    // 0x808003CC: lwc1        $f6, 0x448($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(100, 0X448));
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003D4: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x808003D8: nop

    // 0x808003DC: bc1f        L_808003F0
    if (!c1cs) {
        // 0x808003E0: nop
    
            goto L_808003F0;
    }
    // 0x808003E0: nop

    // 0x808003E4: jal         0x80083B68
    // 0x808003E8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _bsstand_entrypoint_8(rdram, ctx);
        goto after_15;
    // 0x808003E8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_15:
    // 0x808003EC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_808003F0:
    // 0x808003F0: jal         0x80084BC0
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baflamethrower_entrypoint_5(rdram, ctx);
        goto after_16;
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003FC: jal         0x8009E5C8
    // 0x80800400: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_17;
    // 0x80800400: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_17:
    // 0x80800404: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800408: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080040C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800410: jr          $ra
    // 0x80800414: nop

    return;
    // 0x80800414: nop

;}
RECOMP_FUNC void _gctransitionDll_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800881D0: syscall     674
    recomp_syscall_handler(rdram, ctx, 0x800881D0);
    return;
    // 0x800881D4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void chstarspinnerctrl_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(960, 0X92C) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x92C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(960, 0X92C));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x92C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(960, 0X92C));
;}
RECOMP_FUNC void func_80804E1C_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804E1C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80804E20: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80804E24: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80804E28: jal         0x800D8FF8
    // 0x80804E2C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80804E2C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80804E30: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80804E34: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80804E38: beql        $a0, $zero, L_80804FAC
    if (ctx->r4 == 0) {
        // 0x80804E3C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80804FAC;
    }
    goto skip_0;
    // 0x80804E3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80804E40: jal         0x80106790
    // 0x80804E44: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80804E44: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x80804E48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80804E4C: jal         0x80100094
    // 0x80804E50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80804E50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80804E54: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x80804E58: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80804E5C: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80804E60: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x80804E64: beq         $t6, $a0, L_80804E90
    if (ctx->r14 == ctx->r4) {
        // 0x80804E68: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80804E90;
    }
    // 0x80804E68: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80804E6C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80804E70: beq         $t6, $at, L_80804EB0
    if (ctx->r14 == ctx->r1) {
        // 0x80804E74: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_80804EB0;
    }
    // 0x80804E74: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80804E78: beq         $t6, $a0, L_80804F1C
    if (ctx->r14 == ctx->r4) {
        // 0x80804E7C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80804F1C;
    }
    // 0x80804E7C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80804E80: beql        $t6, $at, L_80804F40
    if (ctx->r14 == ctx->r1) {
        // 0x80804E84: lui         $at, 0xC348
        ctx->r1 = S32(0XC348 << 16);
            goto L_80804F40;
    }
    goto skip_1;
    // 0x80804E84: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    skip_1:
    // 0x80804E88: b           L_80804FAC
    // 0x80804E8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80804FAC;
    // 0x80804E8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80804E90:
    // 0x80804E90: lbu         $t7, 0x58($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X58);
    // 0x80804E94: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80804E98: bnel        $a0, $t7, L_80804FAC
    if (ctx->r4 != ctx->r15) {
        // 0x80804E9C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80804FAC;
    }
    goto skip_2;
    // 0x80804E9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80804EA0: jal         0x80804DB8
    // 0x80804EA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80804DB8_chdragonbrothers(rdram, ctx);
        goto after_3;
    // 0x80804EA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80804EA8: b           L_80804FAC
    // 0x80804EAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80804FAC;
    // 0x80804EAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80804EB0:
    // 0x80804EB0: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
    // 0x80804EB4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80804EB8: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80804EBC: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80804EC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804EC4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80804EC8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80804ECC: bc1f        L_80804F08
    if (!c1cs) {
        // 0x80804ED0: nop
    
            goto L_80804F08;
    }
    // 0x80804ED0: nop

    // 0x80804ED4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80804ED8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1852, 0X5A50) << 16);
    // 0x80804EDC: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1852, 0X53A0) << 16);
    // 0x80804EE0: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80804EE4: addiu       $a3, $a3, 0x53A0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1852, 0X53A0));
    // 0x80804EE8: addiu       $a1, $a1, 0x5A50
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1852, 0X5A50));
    // 0x80804EEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804EF0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80804EF4: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80804EF8: jal         0x80089D50
    // 0x80804EFC: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x80804EFC: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    after_4:
    // 0x80804F00: b           L_80804FAC
    // 0x80804F04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80804FAC;
    // 0x80804F04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80804F08:
    // 0x80804F08: jal         0x80804DB8
    // 0x80804F0C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80804DB8_chdragonbrothers(rdram, ctx);
        goto after_5;
    // 0x80804F0C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_5:
    // 0x80804F10: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80804F14: b           L_80804FA8
    // 0x80804F18: sb          $zero, 0x58($a2)
    MEM_B(0X58, ctx->r6) = 0;
        goto L_80804FA8;
    // 0x80804F18: sb          $zero, 0x58($a2)
    MEM_B(0X58, ctx->r6) = 0;
L_80804F1C:
    // 0x80804F1C: lbu         $t8, 0x58($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X58);
    // 0x80804F20: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80804F24: bnel        $a0, $t8, L_80804FAC
    if (ctx->r4 != ctx->r24) {
        // 0x80804F28: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80804FAC;
    }
    goto skip_3;
    // 0x80804F28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80804F2C: jal         0x80804DB8
    // 0x80804F30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80804DB8_chdragonbrothers(rdram, ctx);
        goto after_6;
    // 0x80804F30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80804F34: b           L_80804FAC
    // 0x80804F38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80804FAC;
    // 0x80804F38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80804F3C: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
L_80804F40:
    // 0x80804F40: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80804F44: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80804F48: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80804F4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804F50: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80804F54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80804F58: bc1f        L_80804F94
    if (!c1cs) {
        // 0x80804F5C: nop
    
            goto L_80804F94;
    }
    // 0x80804F5C: nop

    // 0x80804F60: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80804F64: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1852, 0X5A50) << 16);
    // 0x80804F68: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1852, 0X53A0) << 16);
    // 0x80804F6C: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80804F70: addiu       $a3, $a3, 0x53A0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1852, 0X53A0));
    // 0x80804F74: addiu       $a1, $a1, 0x5A50
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1852, 0X5A50));
    // 0x80804F78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804F7C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80804F80: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80804F84: jal         0x80089D50
    // 0x80804F88: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x80804F88: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    after_7:
    // 0x80804F8C: b           L_80804FAC
    // 0x80804F90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80804FAC;
    // 0x80804F90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80804F94:
    // 0x80804F94: jal         0x80804DB8
    // 0x80804F98: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80804DB8_chdragonbrothers(rdram, ctx);
        goto after_8;
    // 0x80804F98: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_8:
    // 0x80804F9C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80804FA0: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80804FA4: sb          $t9, 0x58($a2)
    MEM_B(0X58, ctx->r6) = ctx->r25;
L_80804FA8:
    // 0x80804FA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80804FAC:
    // 0x80804FAC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80804FB0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80804FB4: jr          $ra
    // 0x80804FB8: nop

    return;
    // 0x80804FB8: nop

;}
RECOMP_FUNC void bssilowait_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800128: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080012C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(352, 0X140) << 16);
    // 0x80800130: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800134: jr          $ra
    // 0x80800138: lw          $v0, 0x140($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(352, 0X140));
    return;
    // 0x80800138: lw          $v0, 0x140($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(352, 0X140));
    // 0x8080013C: nop

;}
RECOMP_FUNC void badrone_entrypoint_32(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005EC: lw          $t6, 0x54($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X54);
    // 0x808005F0: sb          $zero, 0x1($t6)
    MEM_B(0X1, ctx->r14) = 0;
    // 0x808005F4: lw          $v0, 0x54($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X54);
    // 0x808005F8: lbu         $t7, 0x1($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X1);
    // 0x808005FC: jr          $ra
    // 0x80800600: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x80800600: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void func_80800164_bsbtrot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800164: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800168: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080016C: jal         0x8008DE24
    // 0x80800170: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8008DE24(rdram, ctx);
        goto after_0;
    // 0x80800170: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800174: beq         $v0, $zero, L_8080018C
    if (ctx->r2 == 0) {
        // 0x80800178: lui         $at, 0x442F
        ctx->r1 = S32(0X442F << 16);
            goto L_8080018C;
    }
    // 0x80800178: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x8080017C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80800180: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800184: b           L_808001AC
    // 0x80800188: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808001AC;
    // 0x80800188: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080018C:
    // 0x8080018C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800190: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800194: lui         $a2, 0x447A
    ctx->r6 = S32(0X447A << 16);
    // 0x80800198: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080019C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808001A0: jal         0x80800070
    // 0x808001A4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80800070_bsbtrot(rdram, ctx);
        goto after_1;
    // 0x808001A4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x808001A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001AC:
    // 0x808001AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001B0: jr          $ra
    // 0x808001B4: nop

    return;
    // 0x808001B4: nop

;}
RECOMP_FUNC void func_800FA130(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FA130: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800FA134: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800FA138: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800FA13C: addiu       $t7, $t7, 0x3880
    ctx->r15 = ADD32(ctx->r15, 0X3880);
    // 0x800FA140: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800FA144: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800FA148: lbu         $t8, 0xC($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0XC);
    // 0x800FA14C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FA150: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FA154: beql        $a1, $t8, L_800FA234
    if (ctx->r5 == ctx->r24) {
        // 0x800FA158: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800FA234;
    }
    goto skip_0;
    // 0x800FA158: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800FA15C: beq         $a1, $zero, L_800FA214
    if (ctx->r5 == 0) {
        // 0x800FA160: sb          $a1, 0xC($v1)
        MEM_B(0XC, ctx->r3) = ctx->r5;
            goto L_800FA214;
    }
    // 0x800FA160: sb          $a1, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r5;
    // 0x800FA164: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800FA168: beq         $a1, $at, L_800FA188
    if (ctx->r5 == ctx->r1) {
        // 0x800FA16C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800FA188;
    }
    // 0x800FA16C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800FA170: beq         $a1, $at, L_800FA1B4
    if (ctx->r5 == ctx->r1) {
        // 0x800FA174: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800FA1B4;
    }
    // 0x800FA174: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800FA178: beql        $a1, $at, L_800FA204
    if (ctx->r5 == ctx->r1) {
        // 0x800FA17C: lw          $a0, 0x18($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X18);
            goto L_800FA204;
    }
    goto skip_1;
    // 0x800FA17C: lw          $a0, 0x18($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X18);
    skip_1:
    // 0x800FA180: b           L_800FA234
    // 0x800FA184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800FA234;
    // 0x800FA184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800FA188:
    // 0x800FA188: lw          $t9, 0x18($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X18);
    // 0x800FA18C: bnel        $t9, $zero, L_800FA234
    if (ctx->r25 != 0) {
        // 0x800FA190: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800FA234;
    }
    goto skip_2;
    // 0x800FA190: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800FA194: lb          $a0, 0xE($v1)
    ctx->r4 = MEM_B(ctx->r3, 0XE);
    // 0x800FA198: lbu         $a1, 0x5($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X5);
    // 0x800FA19C: lbu         $a2, 0x12($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X12);
    // 0x800FA1A0: jal         0x8008A580
    // 0x800FA1A4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    _scinfobar_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x800FA1A4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x800FA1A8: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800FA1AC: b           L_800FA230
    // 0x800FA1B0: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
        goto L_800FA230;
    // 0x800FA1B0: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
L_800FA1B4:
    // 0x800FA1B4: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x800FA1B8: lh          $t0, 0x6($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X6);
    // 0x800FA1BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800FA1C0: bnel        $t0, $v0, L_800FA1DC
    if (ctx->r8 != ctx->r2) {
        // 0x800FA1C4: lh          $t3, 0x2($v1)
        ctx->r11 = MEM_H(ctx->r3, 0X2);
            goto L_800FA1DC;
    }
    goto skip_3;
    // 0x800FA1C4: lh          $t3, 0x2($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X2);
    skip_3:
    // 0x800FA1C8: lh          $t1, 0x8($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X8);
    // 0x800FA1CC: lh          $t2, 0x2($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X2);
    // 0x800FA1D0: beql        $t1, $t2, L_800FA1E8
    if (ctx->r9 == ctx->r10) {
        // 0x800FA1D4: lbu         $t4, 0x11($v1)
        ctx->r12 = MEM_BU(ctx->r3, 0X11);
            goto L_800FA1E8;
    }
    goto skip_4;
    // 0x800FA1D4: lbu         $t4, 0x11($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X11);
    skip_4:
    // 0x800FA1D8: lh          $t3, 0x2($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X2);
L_800FA1DC:
    // 0x800FA1DC: sh          $v0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r2;
    // 0x800FA1E0: sh          $t3, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r11;
    // 0x800FA1E4: lbu         $t4, 0x11($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X11);
L_800FA1E8:
    // 0x800FA1E8: bnel        $t4, $zero, L_800FA234
    if (ctx->r12 != 0) {
        // 0x800FA1EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800FA234;
    }
    goto skip_5;
    // 0x800FA1EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x800FA1F0: jal         0x8008A5B0
    // 0x800FA1F4: lw          $a0, 0x18($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X18);
    _scinfobar_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x800FA1F4: lw          $a0, 0x18($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X18);
    after_1:
    // 0x800FA1F8: b           L_800FA234
    // 0x800FA1FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800FA234;
    // 0x800FA1FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FA200: lw          $a0, 0x18($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X18);
L_800FA204:
    // 0x800FA204: jal         0x8008A5B0
    // 0x800FA208: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _scinfobar_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x800FA208: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x800FA20C: b           L_800FA234
    // 0x800FA210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800FA234;
    // 0x800FA210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800FA214:
    // 0x800FA214: lw          $a0, 0x18($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X18);
    // 0x800FA218: beql        $a0, $zero, L_800FA234
    if (ctx->r4 == 0) {
        // 0x800FA21C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800FA234;
    }
    goto skip_6;
    // 0x800FA21C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x800FA220: jal         0x8008A588
    // 0x800FA224: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    _scinfobar_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x800FA224: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_3:
    // 0x800FA228: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800FA22C: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
L_800FA230:
    // 0x800FA230: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800FA234:
    // 0x800FA234: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800FA238: jr          $ra
    // 0x800FA23C: nop

    return;
    // 0x800FA23C: nop

;}
RECOMP_FUNC void gctransitionDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800324: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80800328: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080032C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800330: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x80800334: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80800338: lbu         $t8, 0x1C($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X1C);
    // 0x8080033C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800340: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80800344: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800348: beq         $t8, $at, L_8080086C
    if (ctx->r24 == ctx->r1) {
        // 0x8080034C: sw          $t7, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->r15;
            goto L_8080086C;
    }
    // 0x8080034C: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x80800350: jal         0x800E41CC
    // 0x80800354: nop

    func_800E41CC(rdram, ctx);
        goto after_0;
    // 0x80800354: nop

    after_0:
    // 0x80800358: lw          $t9, 0x2C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X2C);
    // 0x8080035C: beql        $t9, $zero, L_8080038C
    if (ctx->r25 == 0) {
        // 0x80800360: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8080038C;
    }
    goto skip_0;
    // 0x80800360: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x80800364: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800368: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x8080036C: lui         $a3, 0x43AF
    ctx->r7 = S32(0X43AF << 16);
    // 0x80800370: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800374: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800378: jal         0x800EFA4C
    // 0x8080037C: nop

    func_800EFA4C(rdram, ctx);
        goto after_1;
    // 0x8080037C: nop

    after_1:
    // 0x80800380: b           L_808003A4
    // 0x80800384: nop

        goto L_808003A4;
    // 0x80800384: nop

    // 0x80800388: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_8080038C:
    // 0x8080038C: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x80800390: lui         $a3, 0x4396
    ctx->r7 = S32(0X4396 << 16);
    // 0x80800394: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800398: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080039C: jal         0x800EFA4C
    // 0x808003A0: nop

    func_800EFA4C(rdram, ctx);
        goto after_2;
    // 0x808003A0: nop

    after_2:
L_808003A4:
    // 0x808003A4: jal         0x800EFD24
    // 0x808003A8: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    func_800EFD24(rdram, ctx);
        goto after_3;
    // 0x808003A8: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    after_3:
    // 0x808003AC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2654, 0X10E4) << 16);
    // 0x808003B0: lwc1        $f12, 0x10E4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2654, 0X10E4));
    // 0x808003B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2654, 0X10E8) << 16);
    // 0x808003B8: jal         0x800E3C8C
    // 0x808003BC: lwc1        $f14, 0x10E8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2654, 0X10E8));
    func_800E3C8C(rdram, ctx);
        goto after_4;
    // 0x808003BC: lwc1        $f14, 0x10E8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2654, 0X10E8));
    after_4:
    // 0x808003C0: jal         0x800E3BAC
    // 0x808003C4: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    func_800E3BAC(rdram, ctx);
        goto after_5;
    // 0x808003C4: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    after_5:
    // 0x808003C8: jal         0x800E3C30
    // 0x808003CC: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    func_800E3C30(rdram, ctx);
        goto after_6;
    // 0x808003CC: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    after_6:
    // 0x808003D0: jal         0x800E3CE8
    // 0x808003D4: nop

    func_800E3CE8(rdram, ctx);
        goto after_7;
    // 0x808003D4: nop

    after_7:
    // 0x808003D8: jal         0x800E44FC
    // 0x808003DC: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    func_800E44FC(rdram, ctx);
        goto after_8;
    // 0x808003DC: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    after_8:
    // 0x808003E0: jal         0x800EFD24
    // 0x808003E4: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    func_800EFD24(rdram, ctx);
        goto after_9;
    // 0x808003E4: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_9:
    // 0x808003E8: lw          $t0, 0x2C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X2C);
    // 0x808003EC: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    // 0x808003F0: lui         $t2, 0xE300
    ctx->r10 = S32(0XE300 << 16);
    // 0x808003F4: beq         $t0, $zero, L_8080044C
    if (ctx->r8 == 0) {
        // 0x808003F8: nop
    
            goto L_8080044C;
    }
    // 0x808003F8: nop

    // 0x808003FC: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80800400: ori         $t2, $t2, 0x1201
    ctx->r10 = ctx->r10 | 0X1201;
    // 0x80800404: lui         $t4, 0xE300
    ctx->r12 = S32(0XE300 << 16);
    // 0x80800408: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8080040C: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x80800410: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80800414: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80800418: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8080041C: ori         $t4, $t4, 0x1801
    ctx->r12 = ctx->r12 | 0X1801;
    // 0x80800420: addiu       $t5, $zero, 0xC0
    ctx->r13 = ADD32(0, 0XC0);
    // 0x80800424: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80800428: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x8080042C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80800430: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80800434: jal         0x8008B304
    // 0x80800438: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    func_8008B304(rdram, ctx);
        goto after_10;
    // 0x80800438: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    after_10:
    // 0x8080043C: jal         0x8008B4D4
    // 0x80800440: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    func_8008B4D4(rdram, ctx);
        goto after_11;
    // 0x80800440: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    after_11:
    // 0x80800444: jal         0x800DF41C
    // 0x80800448: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF41C(rdram, ctx);
        goto after_12;
    // 0x80800448: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_12:
L_8080044C:
    // 0x8080044C: jal         0x800DF830
    // 0x80800450: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DF830(rdram, ctx);
        goto after_13;
    // 0x80800450: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
    // 0x80800454: lbu         $v0, 0x1C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1C);
    // 0x80800458: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080045C: beq         $v0, $at, L_8080046C
    if (ctx->r2 == ctx->r1) {
        // 0x80800460: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_8080046C;
    }
    // 0x80800460: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800464: bnel        $v0, $at, L_808004EC
    if (ctx->r2 != ctx->r1) {
        // 0x80800468: lwc1        $f4, 0x28($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
            goto L_808004EC;
    }
    goto skip_1;
    // 0x80800468: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    skip_1:
L_8080046C:
    // 0x8080046C: jal         0x800D674C
    // 0x80800470: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    func_800D674C(rdram, ctx);
        goto after_14;
    // 0x80800470: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    after_14:
    // 0x80800474: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80800478: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x8080047C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800480: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800484: jal         0x800DE448
    // 0x80800488: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800DE448(rdram, ctx);
        goto after_15;
    // 0x80800488: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_15:
    // 0x8080048C: lw          $t6, 0x2C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2C);
    // 0x80800490: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x80800494: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x80800498: beq         $t6, $zero, L_808004D8
    if (ctx->r14 == 0) {
        // 0x8080049C: nop
    
            goto L_808004D8;
    }
    // 0x8080049C: nop

    // 0x808004A0: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x808004A4: ori         $t8, $t8, 0x1201
    ctx->r24 = ctx->r24 | 0X1201;
    // 0x808004A8: addiu       $t9, $zero, 0x2000
    ctx->r25 = ADD32(0, 0X2000);
    // 0x808004AC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x808004B0: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x808004B4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x808004B8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x808004BC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x808004C0: lui         $t1, 0xE300
    ctx->r9 = S32(0XE300 << 16);
    // 0x808004C4: ori         $t1, $t1, 0x1801
    ctx->r9 = ctx->r9 | 0X1801;
    // 0x808004C8: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x808004CC: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x808004D0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x808004D4: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
L_808004D8:
    // 0x808004D8: jal         0x800E4208
    // 0x808004DC: nop

    func_800E4208(rdram, ctx);
        goto after_16;
    // 0x808004DC: nop

    after_16:
    // 0x808004E0: b           L_80800870
    // 0x808004E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800870;
    // 0x808004E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808004E8: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
L_808004EC:
    // 0x808004EC: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x808004F0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808004F4: bne         $v0, $at, L_808005AC
    if (ctx->r2 != ctx->r1) {
        // 0x808004F8: div.s       $f12, $f4, $f6
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
            goto L_808005AC;
    }
    // 0x808004F8: div.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808004FC: lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X8);
    // 0x80800500: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80800504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800508: beq         $v0, $at, L_80800550
    if (ctx->r2 == ctx->r1) {
        // 0x8080050C: addiu       $at, $zero, 0x16
        ctx->r1 = ADD32(0, 0X16);
            goto L_80800550;
    }
    // 0x8080050C: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x80800510: beq         $v0, $at, L_8080055C
    if (ctx->r2 == ctx->r1) {
        // 0x80800514: addiu       $at, $zero, 0x18
        ctx->r1 = ADD32(0, 0X18);
            goto L_8080055C;
    }
    // 0x80800514: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x80800518: beq         $v0, $at, L_8080055C
    if (ctx->r2 == ctx->r1) {
        // 0x8080051C: lui         $at, 0x42B4
        ctx->r1 = S32(0X42B4 << 16);
            goto L_8080055C;
    }
    // 0x8080051C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800520: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800524: lwc1        $f8, 0x24($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800528: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2654, 0XC80) << 16);
    // 0x8080052C: mul.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80800530: lwc1        $f10, 0xC80($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2654, 0XC80));
    // 0x80800534: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80800538: swc1        $f18, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f18.u32l;
    // 0x8080053C: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80800540: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80800544: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80800548: b           L_8080057C
    // 0x8080054C: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
        goto L_8080057C;
    // 0x8080054C: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
L_80800550:
    // 0x80800550: lwc1        $f16, 0x18($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80800554: b           L_8080057C
    // 0x80800558: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
        goto L_8080057C;
    // 0x80800558: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
L_8080055C:
    // 0x8080055C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80800560: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2654, 0XC84) << 16);
    // 0x80800564: lwc1        $f10, 0xC84($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2654, 0XC84));
    // 0x80800568: swc1        $f18, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f18.u32l;
    // 0x8080056C: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80800570: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80800574: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80800578: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
L_8080057C:
    // 0x8080057C: jal         0x80800098
    // 0x80800580: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_80800098_gctransitionDll(rdram, ctx);
        goto after_17;
    // 0x80800580: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_17:
    // 0x80800584: jal         0x800D674C
    // 0x80800588: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    func_800D674C(rdram, ctx);
        goto after_18;
    // 0x80800588: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    after_18:
    // 0x8080058C: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80800590: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x80800594: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x80800598: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8080059C: jal         0x800DE448
    // 0x808005A0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800DE448(rdram, ctx);
        goto after_19;
    // 0x808005A0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_19:
    // 0x808005A4: b           L_80800838
    // 0x808005A8: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
        goto L_80800838;
    // 0x808005A8: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
L_808005AC:
    // 0x808005AC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x808005B0: bnel        $v0, $at, L_808006F0
    if (ctx->r2 != ctx->r1) {
        // 0x808005B4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808006F0;
    }
    goto skip_2;
    // 0x808005B4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_2:
    // 0x808005B8: lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X8);
    // 0x808005BC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x808005C0: beq         $v0, $at, L_80800628
    if (ctx->r2 == ctx->r1) {
        // 0x808005C4: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_80800628;
    }
    // 0x808005C4: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x808005C8: beq         $v0, $at, L_8080061C
    if (ctx->r2 == ctx->r1) {
        // 0x808005CC: addiu       $at, $zero, 0x17
        ctx->r1 = ADD32(0, 0X17);
            goto L_8080061C;
    }
    // 0x808005CC: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x808005D0: beq         $v0, $at, L_8080065C
    if (ctx->r2 == ctx->r1) {
        // 0x808005D4: addiu       $at, $zero, 0x19
        ctx->r1 = ADD32(0, 0X19);
            goto L_8080065C;
    }
    // 0x808005D4: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x808005D8: beq         $v0, $at, L_8080065C
    if (ctx->r2 == ctx->r1) {
        // 0x808005DC: lui         $at, 0x42B4
        ctx->r1 = S32(0X42B4 << 16);
            goto L_8080065C;
    }
    // 0x808005DC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808005E0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808005E4: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808005E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808005EC: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x808005F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808005F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2654, 0XC88) << 16);
    // 0x808005F8: sub.s       $f8, $f10, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x808005FC: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80800600: lwc1        $f4, 0xC88($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2654, 0XC88));
    // 0x80800604: swc1        $f6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
    // 0x80800608: lwc1        $f18, 0x18($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8080060C: mul.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80800610: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80800614: b           L_80800688
    // 0x80800618: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
        goto L_80800688;
    // 0x80800618: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
L_8080061C:
    // 0x8080061C: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80800620: b           L_80800688
    // 0x80800624: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
        goto L_80800688;
    // 0x80800624: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
L_80800628:
    // 0x80800628: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8080062C: jal         0x800F1480
    // 0x80800630: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    func_800F1480(rdram, ctx);
        goto after_20;
    // 0x80800630: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    after_20:
    // 0x80800634: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800638: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080063C: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80800640: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2654, 0XC8C) << 16);
    // 0x80800644: sub.s       $f16, $f18, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x80800648: lwc1        $f10, 0xC8C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2654, 0XC8C));
    // 0x8080064C: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80800650: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80800654: b           L_80800688
    // 0x80800658: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
        goto L_80800688;
    // 0x80800658: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
L_8080065C:
    // 0x8080065C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800660: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80800664: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800668: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2654, 0XC90) << 16);
    // 0x8080066C: swc1        $f18, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f18.u32l;
    // 0x80800670: sub.s       $f4, $f16, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x80800674: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80800678: lwc1        $f8, 0xC90($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2654, 0XC90));
    // 0x8080067C: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800680: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80800684: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
L_80800688:
    // 0x80800688: lw          $t2, 0x30($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X30);
    // 0x8080068C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800690: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
    // 0x80800694: beq         $at, $zero, L_808006AC
    if (ctx->r1 == 0) {
        // 0x80800698: nop
    
            goto L_808006AC;
    }
    // 0x80800698: nop

    // 0x8080069C: lbu         $t3, 0x8($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X8);
    // 0x808006A0: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x808006A4: beq         $t3, $at, L_808006DC
    if (ctx->r11 == ctx->r1) {
        // 0x808006A8: nop
    
            goto L_808006DC;
    }
    // 0x808006A8: nop

L_808006AC:
    // 0x808006AC: jal         0x80800098
    // 0x808006B0: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_80800098_gctransitionDll(rdram, ctx);
        goto after_21;
    // 0x808006B0: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_21:
    // 0x808006B4: jal         0x800D674C
    // 0x808006B8: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    func_800D674C(rdram, ctx);
        goto after_22;
    // 0x808006B8: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    after_22:
    // 0x808006BC: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x808006C0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x808006C4: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x808006C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808006CC: jal         0x800DE448
    // 0x808006D0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800DE448(rdram, ctx);
        goto after_23;
    // 0x808006D0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_23:
    // 0x808006D4: b           L_80800838
    // 0x808006D8: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
        goto L_80800838;
    // 0x808006D8: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
L_808006DC:
    // 0x808006DC: jal         0x800DE318
    // 0x808006E0: nop

    func_800DE318(rdram, ctx);
        goto after_24;
    // 0x808006E0: nop

    after_24:
    // 0x808006E4: b           L_80800838
    // 0x808006E8: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
        goto L_80800838;
    // 0x808006E8: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
    // 0x808006EC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_808006F0:
    // 0x808006F0: bne         $v0, $at, L_8080073C
    if (ctx->r2 != ctx->r1) {
        // 0x808006F4: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_8080073C;
    }
    // 0x808006F4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808006F8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808006FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800700: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800704: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80800708: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080070C: sub.s       $f4, $f16, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x80800710: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2654, 0X10D8) << 16);
    // 0x80800714: addiu       $a2, $a2, 0x10D8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2654, 0X10D8));
    // 0x80800718: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x8080071C: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800720: add.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80800724: trunc.w.s   $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800728: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8080072C: jal         0x800B99CC
    // 0x80800730: nop

    func_800B99CC(rdram, ctx);
        goto after_25;
    // 0x80800730: nop

    after_25:
    // 0x80800734: b           L_80800838
    // 0x80800738: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
        goto L_80800838;
    // 0x80800738: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
L_8080073C:
    // 0x8080073C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800740: bne         $v0, $at, L_80800780
    if (ctx->r2 != ctx->r1) {
        // 0x80800744: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80800780;
    }
    // 0x80800744: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800748: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080074C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80800750: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800754: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2654, 0X10D8) << 16);
    // 0x80800758: addiu       $a2, $a2, 0x10D8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2654, 0X10D8));
    // 0x8080075C: mul.s       $f4, $f12, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x80800760: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x80800764: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80800768: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8080076C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800770: jal         0x800B99CC
    // 0x80800774: nop

    func_800B99CC(rdram, ctx);
        goto after_26;
    // 0x80800774: nop

    after_26:
    // 0x80800778: b           L_80800838
    // 0x8080077C: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
        goto L_80800838;
    // 0x8080077C: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
L_80800780:
    // 0x80800780: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800784: bne         $v0, $at, L_808007F8
    if (ctx->r2 != ctx->r1) {
        // 0x80800788: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_808007F8;
    }
    // 0x80800788: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080078C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800790: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800794: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x80800798: nop

    // 0x8080079C: bc1fl       L_808007B4
    if (!c1cs) {
        // 0x808007A0: sub.s       $f18, $f12, $f0
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f0.fl;
            goto L_808007B4;
    }
    goto skip_3;
    // 0x808007A0: sub.s       $f18, $f12, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f0.fl;
    skip_3:
    // 0x808007A4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808007A8: b           L_808007C8
    // 0x808007AC: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
        goto L_808007C8;
    // 0x808007AC: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x808007B0: sub.s       $f18, $f12, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f0.fl;
L_808007B4:
    // 0x808007B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808007B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808007BC: div.s       $f16, $f18, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x808007C0: sub.s       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x808007C4: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
L_808007C8:
    // 0x808007C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808007CC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2654, 0X10CC) << 16);
    // 0x808007D0: addiu       $a2, $a2, 0x10CC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2654, 0X10CC));
    // 0x808007D4: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x808007D8: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x808007DC: add.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x808007E0: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x808007E4: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x808007E8: jal         0x800B99CC
    // 0x808007EC: nop

    func_800B99CC(rdram, ctx);
        goto after_27;
    // 0x808007EC: nop

    after_27:
    // 0x808007F0: b           L_80800838
    // 0x808007F4: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
        goto L_80800838;
    // 0x808007F4: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
L_808007F8:
    // 0x808007F8: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x808007FC: bne         $v0, $at, L_80800834
    if (ctx->r2 != ctx->r1) {
        // 0x80800800: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80800834;
    }
    // 0x80800800: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800804: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800808: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8080080C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800810: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2654, 0X10CC) << 16);
    // 0x80800814: addiu       $a2, $a2, 0x10CC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2654, 0X10CC));
    // 0x80800818: mul.s       $f16, $f12, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x8080081C: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x80800820: add.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x80800824: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800828: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8080082C: jal         0x800B99CC
    // 0x80800830: nop

    func_800B99CC(rdram, ctx);
        goto after_28;
    // 0x80800830: nop

    after_28:
L_80800834:
    // 0x80800834: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
L_80800838:
    // 0x80800838: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x8080083C: lui         $t0, 0xE300
    ctx->r8 = S32(0XE300 << 16);
    // 0x80800840: beq         $t8, $zero, L_80800864
    if (ctx->r24 == 0) {
        // 0x80800844: nop
    
            goto L_80800864;
    }
    // 0x80800844: nop

    // 0x80800848: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8080084C: ori         $t0, $t0, 0x1201
    ctx->r8 = ctx->r8 | 0X1201;
    // 0x80800850: addiu       $t1, $zero, 0x2000
    ctx->r9 = ADD32(0, 0X2000);
    // 0x80800854: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80800858: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8080085C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80800860: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
L_80800864:
    // 0x80800864: jal         0x800E4208
    // 0x80800868: nop

    func_800E4208(rdram, ctx);
        goto after_29;
    // 0x80800868: nop

    after_29:
L_8080086C:
    // 0x8080086C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800870:
    // 0x80800870: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800874: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x80800878: jr          $ra
    // 0x8080087C: nop

    return;
    // 0x8080087C: nop

;}
RECOMP_FUNC void func_8080000C_chtemplelobbydoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800014: jal         0x800EA090
    // 0x80800018: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800EA090(rdram, ctx);
        goto after_0;
    // 0x80800018: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080001C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800020: bnel        $v0, $at, L_80800068
    if (ctx->r2 != ctx->r1) {
        // 0x80800024: addiu       $t9, $zero, 0x8
        ctx->r25 = ADD32(0, 0X8);
            goto L_80800068;
    }
    goto skip_0;
    // 0x80800024: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    skip_0:
    // 0x80800028: jal         0x800D035C
    // 0x8080002C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800D035C(rdram, ctx);
        goto after_1;
    // 0x8080002C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_1:
    // 0x80800030: slti        $t6, $v0, 0x14
    ctx->r14 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x80800034: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80800038: jal         0x800F5410
    // 0x8080003C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800F5410(rdram, ctx);
        goto after_2;
    // 0x8080003C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80800040: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80800044: xori        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 ^ 0X1;
    // 0x80800048: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080004C: bne         $t7, $zero, L_8080005C
    if (ctx->r15 != 0) {
        // 0x80800050: nop
    
            goto L_8080005C;
    }
    // 0x80800050: nop

    // 0x80800054: beql        $t8, $zero, L_80800068
    if (ctx->r24 == 0) {
        // 0x80800058: addiu       $t9, $zero, 0x8
        ctx->r25 = ADD32(0, 0X8);
            goto L_80800068;
    }
    goto skip_1;
    // 0x80800058: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    skip_1:
L_8080005C:
    // 0x8080005C: jal         0x80101FDC
    // 0x80800060: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x80800060: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800064: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
L_80800068:
    // 0x80800068: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8080006C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80800070: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800074: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800078: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8080007C: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x80800080: jal         0x80086898
    // 0x80800084: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80800084: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    after_4:
    // 0x80800088: beq         $v0, $zero, L_808000A4
    if (ctx->r2 == 0) {
        // 0x8080008C: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_808000A4;
    }
    // 0x8080008C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800090: jal         0x800868A8
    // 0x80800094: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_5;
    // 0x80800094: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    after_5:
    // 0x80800098: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080009C: jal         0x800868C0
    // 0x808000A0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x808000A0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_6:
L_808000A4:
    // 0x808000A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000AC: jr          $ra
    // 0x808000B0: nop

    return;
    // 0x808000B0: nop

;}
RECOMP_FUNC void func_80111094(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80111094: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80111098: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8011109C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801110A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801110A4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x801110A8: addiu       $a1, $a3, 0x74
    ctx->r5 = ADD32(ctx->r7, 0X74);
    // 0x801110AC: jal         0x800EE780
    // 0x801110B0: addiu       $a2, $a3, 0x8C
    ctx->r6 = ADD32(ctx->r7, 0X8C);
    func_800EE780(rdram, ctx);
        goto after_0;
    // 0x801110B0: addiu       $a2, $a3, 0x8C
    ctx->r6 = ADD32(ctx->r7, 0X8C);
    after_0:
    // 0x801110B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801110B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801110BC: jr          $ra
    // 0x801110C0: nop

    return;
    // 0x801110C0: nop

;}
RECOMP_FUNC void func_808000CC_bsstonehead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000D8: jal         0x8009EF1C
    // 0x808000DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bastick_getZonePosition(rdram, ctx);
        goto after_0;
    // 0x808000DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808000E0: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x808000E4: jal         0x80084440
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baattach_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808000EC: beq         $v0, $zero, L_80800100
    if (ctx->r2 == 0) {
        // 0x808000F0: lui         $at, 0x437A
        ctx->r1 = S32(0X437A << 16);
            goto L_80800100;
    }
    // 0x808000F0: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x808000F4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808000F8: b           L_8080013C
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080013C;
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800100:
    // 0x80800100: jal         0x8008DE24
    // 0x80800104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DE24(rdram, ctx);
        goto after_2;
    // 0x80800104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800108: beql        $v0, $zero, L_80800130
    if (ctx->r2 == 0) {
        // 0x8080010C: lui         $at, 0x43C8
        ctx->r1 = S32(0X43C8 << 16);
            goto L_80800130;
    }
    goto skip_0;
    // 0x8080010C: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    skip_0:
    // 0x80800110: jal         0x8008E078
    // 0x80800114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_3;
    // 0x80800114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800118: beq         $v0, $zero, L_8080012C
    if (ctx->r2 == 0) {
        // 0x8080011C: lui         $at, 0x42A0
        ctx->r1 = S32(0X42A0 << 16);
            goto L_8080012C;
    }
    // 0x8080011C: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80800120: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800124: b           L_8080013C
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080013C;
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080012C:
    // 0x8080012C: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
L_80800130:
    // 0x80800130: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800134: nop

    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080013C:
    // 0x8080013C: jal         0x8009EF10
    // 0x80800140: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    bastick_getZone(rdram, ctx);
        goto after_4;
    // 0x80800140: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x80800144: bne         $v0, $zero, L_80800160
    if (ctx->r2 != 0) {
        // 0x80800148: lwc1        $f0, 0x20($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
            goto L_80800160;
    }
    // 0x80800148: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8080014C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800150: jal         0x8009B9B0
    // 0x80800154: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_5;
    // 0x80800154: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_5:
    // 0x80800158: b           L_80800184
    // 0x8080015C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800184;
    // 0x8080015C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800160:
    // 0x80800160: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800164: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800168: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080016C: jal         0x800F1214
    // 0x80800170: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    func_800F1214(rdram, ctx);
        goto after_6;
    // 0x80800170: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x80800174: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800178: jal         0x8009B9B0
    // 0x8080017C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_7;
    // 0x8080017C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800180: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800184:
    // 0x80800184: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800188: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080018C: jr          $ra
    // 0x80800190: nop

    return;
    // 0x80800190: nop

;}
RECOMP_FUNC void func_800D5E74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5E74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D5E78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D5E7C: jal         0x800D55DC
    // 0x800D5E80: nop

    func_800D55DC(rdram, ctx);
        goto after_0;
    // 0x800D5E80: nop

    after_0:
    // 0x800D5E84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D5E88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D5E8C: jr          $ra
    // 0x800D5E90: nop

    return;
    // 0x800D5E90: nop

;}
RECOMP_FUNC void func_8080158C_chsabreman(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080158C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801590: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801594: lui         $a1, 0x3EE6
    ctx->r5 = S32(0X3EE6 << 16);
    // 0x80801598: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080159C: jal         0x80102FDC
    // 0x808015A0: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    func_80102FDC(rdram, ctx);
        goto after_0;
    // 0x808015A0: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    after_0:
    // 0x808015A4: addiu       $a0, $zero, 0x1CA
    ctx->r4 = ADD32(0, 0X1CA);
    // 0x808015A8: jal         0x800DA564
    // 0x808015AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DA564(rdram, ctx);
        goto after_1;
    // 0x808015AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x808015B0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808015B4: beql        $v0, $at, L_808015C8
    if (ctx->r2 == ctx->r1) {
        // 0x808015B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808015C8;
    }
    goto skip_0;
    // 0x808015B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808015BC: jal         0x800FFAB0
    // 0x808015C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x808015C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808015C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808015C8:
    // 0x808015C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808015CC: jr          $ra
    // 0x808015D0: nop

    return;
    // 0x808015D0: nop

;}
RECOMP_FUNC void bainput_should_beak_barge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097A50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80097A54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80097A58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80097A5C: jal         0x80091A58
    // 0x80097A60: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_0;
    // 0x80097A60: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_0:
    // 0x80097A64: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x80097A68: beq         $t6, $zero, L_80097A80
    if (ctx->r14 == 0) {
        // 0x80097A6C: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80097A80;
    }
    // 0x80097A6C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80097A70: jal         0x8008D0A0
    // 0x80097A74: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008D0A0(rdram, ctx);
        goto after_1;
    // 0x80097A74: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80097A78: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x80097A7C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80097A80:
    // 0x80097A80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80097A84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80097A88: jr          $ra
    // 0x80097A8C: nop

    return;
    // 0x80097A8C: nop

;}
RECOMP_FUNC void func_808000F4_bamovespline(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800100: beq         $a1, $at, L_8080012C
    if (ctx->r5 == ctx->r1) {
        // 0x80800104: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_8080012C;
    }
    // 0x80800104: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800108: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080010C: beq         $a1, $at, L_80800168
    if (ctx->r5 == ctx->r1) {
        // 0x80800110: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800168;
    }
    // 0x80800110: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800114: beq         $a1, $at, L_8080014C
    if (ctx->r5 == ctx->r1) {
        // 0x80800118: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8080014C;
    }
    // 0x80800118: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080011C: beql        $a1, $at, L_8080016C
    if (ctx->r5 == ctx->r1) {
        // 0x80800120: lw          $t9, 0xC8($a0)
        ctx->r25 = MEM_W(ctx->r4, 0XC8);
            goto L_8080016C;
    }
    goto skip_0;
    // 0x80800120: lw          $t9, 0xC8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC8);
    skip_0:
    // 0x80800124: b           L_8080016C
    // 0x80800128: lw          $t9, 0xC8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC8);
        goto L_8080016C;
    // 0x80800128: lw          $t9, 0xC8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC8);
L_8080012C:
    // 0x8080012C: lw          $t6, 0xC8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC8);
    // 0x80800130: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800134: sb          $zero, 0x91($t6)
    MEM_B(0X91, ctx->r14) = 0;
    // 0x80800138: lw          $t7, 0xC8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC8);
    // 0x8080013C: sb          $zero, 0x92($t7)
    MEM_B(0X92, ctx->r15) = 0;
    // 0x80800140: lw          $t8, 0xC8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC8);
    // 0x80800144: b           L_80800168
    // 0x80800148: swc1        $f4, 0xA8($t8)
    MEM_W(0XA8, ctx->r24) = ctx->f4.u32l;
        goto L_80800168;
    // 0x80800148: swc1        $f4, 0xA8($t8)
    MEM_W(0XA8, ctx->r24) = ctx->f4.u32l;
L_8080014C:
    // 0x8080014C: lw          $a1, 0xC8($a0)
    ctx->r5 = MEM_W(ctx->r4, 0XC8);
    // 0x80800150: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x80800154: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800158: jal         0x8009C128
    // 0x8080015C: addiu       $a1, $a1, 0x9C
    ctx->r5 = ADD32(ctx->r5, 0X9C);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x8080015C: addiu       $a1, $a1, 0x9C
    ctx->r5 = ADD32(ctx->r5, 0X9C);
    after_0:
    // 0x80800160: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800164: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
L_80800168:
    // 0x80800168: lw          $t9, 0xC8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC8);
L_8080016C:
    // 0x8080016C: sb          $a2, 0x90($t9)
    MEM_B(0X90, ctx->r25) = ctx->r6;
    // 0x80800170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800174: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800178: jr          $ra
    // 0x8080017C: nop

    return;
    // 0x8080017C: nop

;}
RECOMP_FUNC void fxleaves_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002B0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808002B4: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x808002B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002BC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808002C0: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x808002C4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808002C8: jal         0x800B28C4
    // 0x808002CC: lw          $a0, 0x1C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1C);
    vector_begin(rdram, ctx);
        goto after_0;
    // 0x808002CC: lw          $a0, 0x1C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1C);
    after_0:
    // 0x808002D0: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x808002D4: jal         0x800B296C
    // 0x808002D8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    vector_end(rdram, ctx);
        goto after_1;
    // 0x808002D8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_1:
    // 0x808002DC: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x808002E0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808002E4: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x808002E8: beq         $at, $zero, L_80800338
    if (ctx->r1 == 0) {
        // 0x808002EC: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80800338;
    }
    // 0x808002EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808002F0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x808002F4: nop

L_808002F8:
    // 0x808002F8: jal         0x800DF830
    // 0x808002FC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800DF830(rdram, ctx);
        goto after_2;
    // 0x808002FC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x80800300: jal         0x800D674C
    // 0x80800304: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800D674C(rdram, ctx);
        goto after_3;
    // 0x80800304: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x80800308: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8080030C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800310: addiu       $a1, $s0, 0x1C
    ctx->r5 = ADD32(ctx->r16, 0X1C);
    // 0x80800314: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800318: jal         0x800DE448
    // 0x8080031C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800DE448(rdram, ctx);
        goto after_4;
    // 0x8080031C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_4:
    // 0x80800320: jal         0x800DF350
    // 0x80800324: nop

    func_800DF350(rdram, ctx);
        goto after_5;
    // 0x80800324: nop

    after_5:
    // 0x80800328: addiu       $s0, $s0, 0x38
    ctx->r16 = ADD32(ctx->r16, 0X38);
    // 0x8080032C: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x80800330: bne         $at, $zero, L_808002F8
    if (ctx->r1 != 0) {
        // 0x80800334: sb          $v0, -0x4($s0)
        MEM_B(-0X4, ctx->r16) = ctx->r2;
            goto L_808002F8;
    }
    // 0x80800334: sb          $v0, -0x4($s0)
    MEM_B(-0X4, ctx->r16) = ctx->r2;
L_80800338:
    // 0x80800338: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8080033C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800340: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80800344: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80800348: jr          $ra
    // 0x8080034C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8080034C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void gcnewoption_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080078C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800790: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800794: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80800798: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x8080079C: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x808007A0: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x808007A4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808007A8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808007AC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x808007B0: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x808007B4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808007B8: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x808007BC: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x808007C0: bne         $at, $zero, L_808009B8
    if (ctx->r1 != 0) {
        // 0x808007C4: slti        $at, $v0, 0xC
        ctx->r1 = SIGNED(ctx->r2) < 0XC ? 1 : 0;
            goto L_808009B8;
    }
    // 0x808007C4: slti        $at, $v0, 0xC
    ctx->r1 = SIGNED(ctx->r2) < 0XC ? 1 : 0;
    // 0x808007C8: beql        $at, $zero, L_808009BC
    if (ctx->r1 == 0) {
        // 0x808007CC: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_808009BC;
    }
    goto skip_0;
    // 0x808007CC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x808007D0: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x808007D4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x808007D8: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x808007DC: blez        $t6, L_808009A4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x808007E0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808009A4;
    }
L_808007E0:
    // 0x808007E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808007E4: jal         0x80800000
    // 0x808007E8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_80800000_gcnewoption(rdram, ctx);
        goto after_0;
    // 0x808007E8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_0:
    // 0x808007EC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x808007F0: lw          $a0, 0x3C($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X3C);
    // 0x808007F4: jal         0x80087AF0
    // 0x808007F8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    _gczoombox_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x808007F8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_1:
    // 0x808007FC: sll         $t7, $s2, 2
    ctx->r15 = S32(ctx->r18 << 2);
    // 0x80800800: addu        $s0, $s1, $t7
    ctx->r16 = ADD32(ctx->r17, ctx->r15);
    // 0x80800804: lwc1        $f0, 0x80($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X80);
    // 0x80800808: lwc1        $f2, 0x14($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8080080C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80800810: nop

    // 0x80800814: bc1fl       L_808008CC
    if (!c1cs) {
        // 0x80800818: lh          $v0, 0x2($s1)
        ctx->r2 = MEM_H(ctx->r17, 0X2);
            goto L_808008CC;
    }
    goto skip_1;
    // 0x80800818: lh          $v0, 0x2($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X2);
    skip_1:
    // 0x8080081C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800820: jal         0x80087BC8
    // 0x80800824: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    _gczoombox_entrypoint_29(rdram, ctx);
        goto after_2;
    // 0x80800824: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_2:
    // 0x80800828: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8080082C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80800830: jal         0x80087BC0
    // 0x80800834: lh          $a1, 0x34($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X34);
    _gczoombox_entrypoint_28(rdram, ctx);
        goto after_3;
    // 0x80800834: lh          $a1, 0x34($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X34);
    after_3:
    // 0x80800838: lh          $t8, 0x2($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X2);
    // 0x8080083C: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80800840: lh          $t9, 0x256($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X256);
    // 0x80800844: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80800848: lwc1        $f16, 0x80($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X80);
    // 0x8080084C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80800850: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800854: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80800858: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8080085C: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800860: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80800864: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80800868: trunc.w.s   $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8080086C: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80800870: jal         0x80087C10
    // 0x80800874: nop

    _gczoombox_entrypoint_38(rdram, ctx);
        goto after_4;
    // 0x80800874: nop

    after_4:
    // 0x80800878: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x8080087C: jal         0x80087AF0
    // 0x80800880: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    _gczoombox_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x80800880: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_5:
    // 0x80800884: lh          $t1, 0x256($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X256);
    // 0x80800888: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x8080088C: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80800890: nop

    // 0x80800894: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800898: add.s       $f18, $f6, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x8080089C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x808008A0: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x808008A4: jal         0x80087C10
    // 0x808008A8: nop

    _gczoombox_entrypoint_38(rdram, ctx);
        goto after_6;
    // 0x808008A8: nop

    after_6:
    // 0x808008AC: sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18 << 16);
    // 0x808008B0: sra         $t3, $a1, 16
    ctx->r11 = S32(SIGNED(ctx->r5) >> 16);
    // 0x808008B4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x808008B8: jal         0x80087BC0
    // 0x808008BC: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    _gczoombox_entrypoint_28(rdram, ctx);
        goto after_7;
    // 0x808008BC: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_7:
    // 0x808008C0: lwc1        $f0, 0x80($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X80);
    // 0x808008C4: lwc1        $f2, 0x14($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X14);
    // 0x808008C8: lh          $v0, 0x2($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X2);
L_808008CC:
    // 0x808008CC: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x808008D0: nop

    // 0x808008D4: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x808008D8: mul.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x808008DC: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x808008E0: nop

    // 0x808008E4: bc1fl       L_80800998
    if (!c1cs) {
        // 0x808008E8: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_80800998;
    }
    goto skip_2;
    // 0x808008E8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_2:
    // 0x808008EC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x808008F0: jal         0x80087BC8
    // 0x808008F4: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    _gczoombox_entrypoint_29(rdram, ctx);
        goto after_8;
    // 0x808008F4: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_8:
    // 0x808008F8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x808008FC: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80800900: jal         0x80087BC0
    // 0x80800904: lh          $a1, 0x34($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X34);
    _gczoombox_entrypoint_28(rdram, ctx);
        goto after_9;
    // 0x80800904: lh          $a1, 0x34($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X34);
    after_9:
    // 0x80800908: lh          $t4, 0x2($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X2);
    // 0x8080090C: lwc1        $f6, 0x14($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80800910: lh          $t5, 0x256($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X256);
    // 0x80800914: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80800918: lwc1        $f16, 0x80($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X80);
    // 0x8080091C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80800920: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800924: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x80800928: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8080092C: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800930: sub.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x80800934: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80800938: trunc.w.s   $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8080093C: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80800940: jal         0x80087C10
    // 0x80800944: nop

    _gczoombox_entrypoint_38(rdram, ctx);
        goto after_10;
    // 0x80800944: nop

    after_10:
    // 0x80800948: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x8080094C: jal         0x80087AF0
    // 0x80800950: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    _gczoombox_entrypoint_2(rdram, ctx);
        goto after_11;
    // 0x80800950: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_11:
    // 0x80800954: lh          $t7, 0x256($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X256);
    // 0x80800958: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x8080095C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80800960: nop

    // 0x80800964: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800968: add.s       $f10, $f18, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x8080096C: trunc.w.s   $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80800970: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800974: jal         0x80087C10
    // 0x80800978: nop

    _gczoombox_entrypoint_38(rdram, ctx);
        goto after_12;
    // 0x80800978: nop

    after_12:
    // 0x8080097C: sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18 << 16);
    // 0x80800980: sra         $t9, $a1, 16
    ctx->r25 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80800984: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x80800988: jal         0x80087BC0
    // 0x8080098C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    _gczoombox_entrypoint_28(rdram, ctx);
        goto after_13;
    // 0x8080098C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_13:
    // 0x80800990: lh          $v0, 0x2($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X2);
    // 0x80800994: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80800998:
    // 0x80800998: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8080099C: bne         $at, $zero, L_808007E0
    if (ctx->r1 != 0) {
        // 0x808009A0: addiu       $s4, $s4, 0x4
        ctx->r20 = ADD32(ctx->r20, 0X4);
            goto L_808007E0;
    }
    // 0x808009A0: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
L_808009A4:
    // 0x808009A4: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x808009A8: beql        $a0, $zero, L_808009BC
    if (ctx->r4 == 0) {
        // 0x808009AC: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_808009BC;
    }
    goto skip_3;
    // 0x808009AC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_3:
    // 0x808009B0: jal         0x80087AF0
    // 0x808009B4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    _gczoombox_entrypoint_2(rdram, ctx);
        goto after_14;
    // 0x808009B4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_14:
L_808009B8:
    // 0x808009B8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_808009BC:
    // 0x808009BC: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x808009C0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808009C4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808009C8: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x808009CC: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x808009D0: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x808009D4: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x808009D8: jr          $ra
    // 0x808009DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x808009DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void bsow_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800130: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800134: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(336, 0X150) << 16);
    // 0x80800138: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080013C: jr          $ra
    // 0x80800140: lw          $v0, 0x150($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(336, 0X150));
    return;
    // 0x80800140: lw          $v0, 0x150($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(336, 0X150));
;}
RECOMP_FUNC void bafly_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800218: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8080021C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800220: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800224: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800228: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8080022C: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80800230: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80800234: jal         0x8009BFCC
    // 0x80800238: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    func_8009BFCC(rdram, ctx);
        goto after_0;
    // 0x80800238: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8080023C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800244: jal         0x8009BCB4
    // 0x80800248: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    baphysics_set_gravity(rdram, ctx);
        goto after_1;
    // 0x80800248: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    after_1:
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800250: jal         0x808001FC
    // 0x80800254: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    bafly_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x80800254: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080025C: jal         0x80095738
    // 0x80800260: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    baflag_isTrue(rdram, ctx);
        goto after_3;
    // 0x80800260: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_3:
    // 0x80800264: beq         $v0, $zero, L_80800290
    if (ctx->r2 == 0) {
        // 0x80800268: lwc1        $f0, 0x58($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
            goto L_80800290;
    }
    // 0x80800268: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800270: jal         0x8009BCC4
    // 0x80800274: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_terminal_velocity(rdram, ctx);
        goto after_4;
    // 0x80800274: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x80800278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080027C: jal         0x8009BA9C
    // 0x80800280: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009BA9C(rdram, ctx);
        goto after_5;
    // 0x80800280: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80800284: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800288: b           L_808003F0
    // 0x8080028C: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
        goto L_808003F0;
    // 0x8080028C: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
L_80800290:
    // 0x80800290: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    // 0x80800294: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x80800298: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8080029C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x808002A0: bc1fl       L_80800364
    if (!c1cs) {
        // 0x808002A4: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_80800364;
    }
    goto skip_0;
    // 0x808002A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_0:
    // 0x808002A8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x808002AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808002B0: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x808002B4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808002B8: sub.s       $f14, $f0, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x808002BC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x808002C0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x808002C4: jal         0x800F10B4
    // 0x808002C8: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    func_800F10B4(rdram, ctx);
        goto after_6;
    // 0x808002C8: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    after_6:
    // 0x808002CC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808002D0: jal         0x8009BCC4
    // 0x808002D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_terminal_velocity(rdram, ctx);
        goto after_7;
    // 0x808002D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808002D8: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x808002DC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x808002E0: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808002E4: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x808002E8: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    // 0x808002EC: jal         0x800F10B4
    // 0x808002F0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_8;
    // 0x808002F0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_8:
    // 0x808002F4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808002F8: jal         0x8009BCB4
    // 0x808002FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_gravity(rdram, ctx);
        goto after_9;
    // 0x808002FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800300: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800304: lwc1        $f0, 0x5C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80800308: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080030C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80800310: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800314: div.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800318: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8080031C: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x80800320: jal         0x800F10B4
    // 0x80800324: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F10B4(rdram, ctx);
        goto after_10;
    // 0x80800324: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_10:
    // 0x80800328: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(528, 0XD90) << 16);
    // 0x8080032C: lwc1        $f4, 0xD90($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(528, 0XD90));
    // 0x80800330: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80800334: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80800338: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8080033C: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x80800340: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800344: jal         0x800F10B4
    // 0x80800348: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_11;
    // 0x80800348: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_11:
    // 0x8080034C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800350: jal         0x808001FC
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bafly_entrypoint_6(rdram, ctx);
        goto after_12;
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800358: b           L_808003F4
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808003F4;
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800360: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_80800364:
    // 0x80800364: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80800368: lui         $a3, 0xC3C7
    ctx->r7 = S32(0XC3C7 << 16);
    // 0x8080036C: add.s       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f6.fl;
    // 0x80800370: ori         $a3, $a3, 0xFEB8
    ctx->r7 = ctx->r7 | 0XFEB8;
    // 0x80800374: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80800378: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8080037C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80800380: jal         0x800F10B4
    // 0x80800384: nop

    func_800F10B4(rdram, ctx);
        goto after_13;
    // 0x80800384: nop

    after_13:
    // 0x80800388: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080038C: jal         0x8009BCC4
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_terminal_velocity(rdram, ctx);
        goto after_14;
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800394: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80800398: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8080039C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808003A0: lwc1        $f18, 0x5C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x808003A4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x808003A8: add.s       $f2, $f14, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x808003AC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x808003B0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x808003B4: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x808003B8: jal         0x800F10B4
    // 0x808003BC: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    func_800F10B4(rdram, ctx);
        goto after_15;
    // 0x808003BC: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    after_15:
    // 0x808003C0: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808003C4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808003C8: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x808003CC: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x808003D0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x808003D4: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    // 0x808003D8: lui         $a3, 0xBE80
    ctx->r7 = S32(0XBE80 << 16);
    // 0x808003DC: jal         0x800F10B4
    // 0x808003E0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_16;
    // 0x808003E0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_16:
    // 0x808003E4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808003E8: jal         0x808001FC
    // 0x808003EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bafly_entrypoint_6(rdram, ctx);
        goto after_17;
    // 0x808003EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
L_808003F0:
    // 0x808003F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808003F4:
    // 0x808003F4: jal         0x80096394
    // 0x808003F8: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_80096394(rdram, ctx);
        goto after_18;
    // 0x808003F8: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_18:
    // 0x808003FC: jal         0x8009650C
    // 0x80800400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009650C(rdram, ctx);
        goto after_19;
    // 0x80800400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800404: beq         $v0, $zero, L_80800430
    if (ctx->r2 == 0) {
        // 0x80800408: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_80800430;
    }
    // 0x80800408: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8080040C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800410: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800414: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80800418: nop

    // 0x8080041C: bc1f        L_80800430
    if (!c1cs) {
        // 0x80800420: nop
    
            goto L_80800430;
    }
    // 0x80800420: nop

    // 0x80800424: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800428: nop

    // 0x8080042C: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
L_80800430:
    // 0x80800430: jal         0x8009C984
    // 0x80800434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_20;
    // 0x80800434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80800438: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080043C: jal         0x8009B9C0
    // 0x80800440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_21;
    // 0x80800440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800448: jal         0x8009B9B0
    // 0x8080044C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_22;
    // 0x8080044C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_22:
    // 0x80800450: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800454: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80800458: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8080045C: jr          $ra
    // 0x80800460: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80800460: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void _bskazpaddle_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083548: syscall     65
    recomp_syscall_handler(rdram, ctx, 0x80083548);
    return;
    // 0x8008354C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _bsblongleg_entrypoint_31(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082AC0: syscall     24
    recomp_syscall_handler(rdram, ctx, 0x80082AC0);
    return;
    // 0x80082AC4: addi        $t0, $zero, 0x7C
    ctx->r8 = ADD32(0, 0X7C);
;}
RECOMP_FUNC void chtalontorpedoboulder_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1436, 0X2B4) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x2B4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1436, 0X2B4));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x2B4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1436, 0X2B4));
;}
RECOMP_FUNC void func_8080032C_bsdronegoto(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080032C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800330: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800334: jal         0x800961A0
    // 0x80800338: lw          $a1, 0x198($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X198);
    func_800961A0(rdram, ctx);
        goto after_0;
    // 0x80800338: lw          $a1, 0x198($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X198);
    after_0:
    // 0x8080033C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800340: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800344: jr          $ra
    // 0x80800348: nop

    return;
    // 0x80800348: nop

;}
RECOMP_FUNC void glsplinefind_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8080000C: jal         0x80088288
    // 0x80800010: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    _gccubesearch_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800010: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80800014: bne         $v0, $zero, L_80800024
    if (ctx->r2 != 0) {
        // 0x80800018: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_80800024;
    }
    // 0x80800018: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8080001C: b           L_80800034
    // 0x80800020: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80800034;
    // 0x80800020: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80800024:
    // 0x80800024: jal         0x800EE84C
    // 0x80800028: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800EE84C(rdram, ctx);
        goto after_1;
    // 0x80800028: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x8080002C: jal         0x8080007C
    // 0x80800030: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    glsplinefind_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800030: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_2:
L_80800034:
    // 0x80800034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800038: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080003C: jr          $ra
    // 0x80800040: nop

    return;
    // 0x80800040: nop

;}
RECOMP_FUNC void func_800CC5E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC5E8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800CC5EC: jr          $ra
    // 0x800CC5F0: lw          $v0, -0x5180($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5180);
    return;
    // 0x800CC5F0: lw          $v0, -0x5180($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5180);
;}
RECOMP_FUNC void _badeathmatch_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085528: syscall     165
    recomp_syscall_handler(rdram, ctx, 0x80085528);
    return;
    // 0x8008552C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_800A0C38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A0C38: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x800A0C3C: jr          $ra
    // 0x800A0C40: lwc1        $f0, 0x4($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X4);
    return;
    // 0x800A0C40: lwc1        $f0, 0x4($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X4);
;}
RECOMP_FUNC void sueggmisc_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800164: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800168: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080016C: jal         0x800DA544
    // 0x80800170: addiu       $a0, $zero, 0xA31
    ctx->r4 = ADD32(0, 0XA31);
    func_800DA544(rdram, ctx);
        goto after_0;
    // 0x80800170: addiu       $a0, $zero, 0xA31
    ctx->r4 = ADD32(0, 0XA31);
    after_0:
    // 0x80800174: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800178: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080017C: jr          $ra
    // 0x80800180: nop

    return;
    // 0x80800180: nop

    // 0x80800184: nop

    // 0x80800188: nop

    // 0x8080018C: nop

;}
RECOMP_FUNC void func_80800244_chfloorbubbles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800244: jr          $ra
    // 0x80800248: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800248: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80800A18_bsblongleg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A18: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800A1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A20: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800A24: jal         0x8008CABC
    // 0x80800A28: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800A28: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800A2C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800A30: jal         0x8008AF24
    // 0x80800A34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x80800A34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800A38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A3C: jal         0x8008B1A0
    // 0x80800A40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_2;
    // 0x80800A40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800A44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A48: jal         0x8008AED4
    // 0x80800A4C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    anctrl_setIndex(rdram, ctx);
        goto after_3;
    // 0x80800A4C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_3:
    // 0x80800A50: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800A54: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800A58: jal         0x8008B1BC
    // 0x80800A5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_4;
    // 0x80800A5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A64: jal         0x8008B134
    // 0x80800A68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_5;
    // 0x80800A68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800A6C: jal         0x8008B064
    // 0x80800A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_6;
    // 0x80800A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800A74: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80800A78: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800A7C: sw          $t6, 0x15C($t7)
    MEM_W(0X15C, ctx->r15) = ctx->r14;
    // 0x80800A80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A84: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800A88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800A8C: jr          $ra
    // 0x80800A90: nop

    return;
    // 0x80800A90: nop

;}
RECOMP_FUNC void func_800DA524(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DA524: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DA528: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DA52C: jal         0x800DA3B8
    // 0x800DA530: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DA3B8(rdram, ctx);
        goto after_0;
    // 0x800DA530: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800DA534: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DA538: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DA53C: jr          $ra
    // 0x800DA540: nop

    return;
    // 0x800DA540: nop

;}
RECOMP_FUNC void sucoasterdata_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C0: sltiu       $at, $a0, 0x9
    ctx->r1 = ctx->r4 < 0X9 ? 1 : 0;
    // 0x808000C4: beq         $at, $zero, L_8080012C
    if (ctx->r1 == 0) {
        // 0x808000C8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8080012C;
    }
    // 0x808000C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808000CC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808000D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3282, 0X330) << 16);
    // 0x808000D4: addu        $at, $at, $t6
    gpr jr_addend_808000DC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808000D8: lw          $t6, 0x330($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(3282, 0X330));
    // 0x808000DC: jr          $t6
    // 0x808000E0: nop

    switch (jr_addend_808000DC >> 2) {
        case 0: goto L_808000E4; break;
        case 1: goto L_808000EC; break;
        case 2: goto L_808000F4; break;
        case 3: goto L_808000FC; break;
        case 4: goto L_80800104; break;
        case 5: goto L_8080010C; break;
        case 6: goto L_80800114; break;
        case 7: goto L_8080011C; break;
        case 8: goto L_80800124; break;
        default: switch_error(__func__, 0x808000DC, 0x80800330);
    }
    // 0x808000E0: nop

L_808000E4:
    // 0x808000E4: jr          $ra
    // 0x808000E8: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    return;
    // 0x808000E8: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
L_808000EC:
    // 0x808000EC: jr          $ra
    // 0x808000F0: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    return;
    // 0x808000F0: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
L_808000F4:
    // 0x808000F4: jr          $ra
    // 0x808000F8: addiu       $v0, $zero, 0x5A
    ctx->r2 = ADD32(0, 0X5A);
    return;
    // 0x808000F8: addiu       $v0, $zero, 0x5A
    ctx->r2 = ADD32(0, 0X5A);
L_808000FC:
    // 0x808000FC: jr          $ra
    // 0x80800100: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    return;
    // 0x80800100: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
L_80800104:
    // 0x80800104: jr          $ra
    // 0x80800108: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
    return;
    // 0x80800108: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
L_8080010C:
    // 0x8080010C: jr          $ra
    // 0x80800110: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    return;
    // 0x80800110: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
L_80800114:
    // 0x80800114: jr          $ra
    // 0x80800118: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    return;
    // 0x80800118: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
L_8080011C:
    // 0x8080011C: jr          $ra
    // 0x80800120: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    return;
    // 0x80800120: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
L_80800124:
    // 0x80800124: jr          $ra
    // 0x80800128: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    return;
    // 0x80800128: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
L_8080012C:
    // 0x8080012C: jr          $ra
    // 0x80800130: nop

    return;
    // 0x80800130: nop

;}
RECOMP_FUNC void func_800964DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800964DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800964E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800964E4: lw          $t6, 0x94($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X94);
    // 0x800964E8: jal         0x800C67D8
    // 0x800964EC: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800C67D8(rdram, ctx);
        goto after_0;
    // 0x800964EC: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x800964F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800964F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800964F8: jr          $ra
    // 0x800964FC: nop

    return;
    // 0x800964FC: nop

;}
RECOMP_FUNC void _basnowball_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085110: syscall     151
    recomp_syscall_handler(rdram, ctx, 0x80085110);
    return;
    // 0x80085114: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void _bashoes_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085010: syscall     148
    recomp_syscall_handler(rdram, ctx, 0x80085010);
    return;
    // 0x80085014: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void _basub_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800851B0: syscall     154
    recomp_syscall_handler(rdram, ctx, 0x800851B0);
    return;
    // 0x800851B4: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void _chappearfx_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800862E0: syscall     303
    recomp_syscall_handler(rdram, ctx, 0x800862E0);
    return;
    // 0x800862E4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800024_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: lw          $v0, 0x168($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X168);
    // 0x80800028: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8080002C: jr          $ra
    // 0x80800030: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    return;
    // 0x80800030: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
;}
RECOMP_FUNC void func_80800018_chfireicestorm(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8080001C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800020: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800024: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800028: jal         0x800DA524
    // 0x8080002C: addiu       $a0, $zero, 0x9FB
    ctx->r4 = ADD32(0, 0X9FB);
    func_800DA524(rdram, ctx);
        goto after_0;
    // 0x8080002C: addiu       $a0, $zero, 0x9FB
    ctx->r4 = ADD32(0, 0X9FB);
    after_0:
    // 0x80800030: lhu         $t6, 0x76($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X76);
    // 0x80800034: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80800038: addiu       $t5, $zero, 0x1D5
    ctx->r13 = ADD32(0, 0X1D5);
    // 0x8080003C: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800040: beq         $t7, $at, L_80800058
    if (ctx->r15 == ctx->r1) {
        // 0x80800044: addiu       $t6, $zero, 0x1D6
        ctx->r14 = ADD32(0, 0X1D6);
            goto L_80800058;
    }
    // 0x80800044: addiu       $t6, $zero, 0x1D6
    ctx->r14 = ADD32(0, 0X1D6);
    // 0x80800048: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x8080004C: ori         $t0, $t9, 0x10
    ctx->r8 = ctx->r25 | 0X10;
    // 0x80800050: b           L_80800064
    // 0x80800054: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
        goto L_80800064;
    // 0x80800054: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
L_80800058:
    // 0x80800058: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    // 0x8080005C: andi        $t2, $t1, 0xFFEF
    ctx->r10 = ctx->r9 & 0XFFEF;
    // 0x80800060: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
L_80800064:
    // 0x80800064: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x80800068: addiu       $t8, $zero, 0x43F
    ctx->r24 = ADD32(0, 0X43F);
    // 0x8080006C: addiu       $t7, $zero, 0x43E
    ctx->r15 = ADD32(0, 0X43E);
    // 0x80800070: sll         $t3, $v0, 11
    ctx->r11 = S32(ctx->r2 << 11);
    // 0x80800074: srl         $v0, $t3, 31
    ctx->r2 = S32(U32(ctx->r11) >> 31);
    // 0x80800078: beql        $v0, $zero, L_8080008C
    if (ctx->r2 == 0) {
        // 0x8080007C: sw          $t6, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r14;
            goto L_8080008C;
    }
    goto skip_0;
    // 0x8080007C: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    skip_0:
    // 0x80800080: b           L_8080008C
    // 0x80800084: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
        goto L_8080008C;
    // 0x80800084: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x80800088: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
L_8080008C:
    // 0x8080008C: beql        $v0, $zero, L_808000A0
    if (ctx->r2 == 0) {
        // 0x80800090: sw          $t8, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r24;
            goto L_808000A0;
    }
    goto skip_1;
    // 0x80800090: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    skip_1:
    // 0x80800094: b           L_808000A0
    // 0x80800098: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
        goto L_808000A0;
    // 0x80800098: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x8080009C: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
L_808000A0:
    // 0x808000A0: jal         0x800A9C98
    // 0x808000A4: nop

    func_800A9C98(rdram, ctx);
        goto after_1;
    // 0x808000A4: nop

    after_1:
    // 0x808000A8: beq         $v0, $zero, L_808000C0
    if (ctx->r2 == 0) {
        // 0x808000AC: nop
    
            goto L_808000C0;
    }
    // 0x808000AC: nop

    // 0x808000B0: jal         0x800DA524
    // 0x808000B4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_800DA524(rdram, ctx);
        goto after_2;
    // 0x808000B4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_2:
    // 0x808000B8: jal         0x800DA544
    // 0x808000BC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x808000BC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_3:
L_808000C0:
    // 0x808000C0: jal         0x800DA298
    // 0x808000C4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x808000C4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_4:
    // 0x808000C8: beq         $v0, $zero, L_808000E0
    if (ctx->r2 == 0) {
        // 0x808000CC: nop
    
            goto L_808000E0;
    }
    // 0x808000CC: nop

    // 0x808000D0: jal         0x800FFAB0
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_5;
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808000D8: b           L_808001BC
    // 0x808000DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808001BC;
    // 0x808000DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000E0:
    // 0x808000E0: jal         0x800A9C98
    // 0x808000E4: nop

    func_800A9C98(rdram, ctx);
        goto after_6;
    // 0x808000E4: nop

    after_6:
    // 0x808000E8: beq         $v0, $zero, L_80800100
    if (ctx->r2 == 0) {
        // 0x808000EC: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_80800100;
    }
    // 0x808000EC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x808000F0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808000F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808000F8: b           L_8080010C
    // 0x808000FC: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_8080010C;
    // 0x808000FC: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_80800100:
    // 0x80800100: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800104: nop

    // 0x80800108: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_8080010C:
    // 0x8080010C: jal         0x800DA298
    // 0x80800110: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x80800110: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_7:
    // 0x80800114: beq         $v0, $zero, L_80800124
    if (ctx->r2 == 0) {
        // 0x80800118: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800124;
    }
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080011C: jal         0x80800558
    // 0x80800120: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800558_chfireicestorm(rdram, ctx);
        goto after_8;
    // 0x80800120: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_8:
L_80800124:
    // 0x80800124: jal         0x800DA298
    // 0x80800128: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    func_800DA298(rdram, ctx);
        goto after_9;
    // 0x80800128: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    after_9:
    // 0x8080012C: sltu        $a0, $zero, $v0
    ctx->r4 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800130: bne         $a0, $zero, L_80800148
    if (ctx->r4 != 0) {
        // 0x80800134: addiu       $a1, $zero, 0x320
        ctx->r5 = ADD32(0, 0X320);
            goto L_80800148;
    }
    // 0x80800134: addiu       $a1, $zero, 0x320
    ctx->r5 = ADD32(0, 0X320);
    // 0x80800138: lw          $a0, 0x64($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X64);
    // 0x8080013C: sll         $t9, $a0, 11
    ctx->r25 = S32(ctx->r4 << 11);
    // 0x80800140: srl         $t0, $t9, 31
    ctx->r8 = S32(U32(ctx->r25) >> 31);
    // 0x80800144: sltu        $a0, $zero, $t0
    ctx->r4 = 0 < ctx->r8 ? 1 : 0;
L_80800148:
    // 0x80800148: lbu         $t5, 0x65($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X65);
    // 0x8080014C: sll         $t3, $a0, 3
    ctx->r11 = S32(ctx->r4 << 3);
    // 0x80800150: andi        $t4, $t3, 0x8
    ctx->r12 = ctx->r11 & 0X8;
    // 0x80800154: andi        $t6, $t5, 0xFFF7
    ctx->r14 = ctx->r13 & 0XFFF7;
    // 0x80800158: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x8080015C: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
    // 0x80800160: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800168: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    // 0x8080016C: sll         $t0, $t8, 12
    ctx->r8 = S32(ctx->r24 << 12);
    // 0x80800170: bltz        $t0, L_808001B8
    if (SIGNED(ctx->r8) < 0) {
        // 0x80800174: addiu       $a3, $sp, 0x38
        ctx->r7 = ADD32(ctx->r29, 0X38);
            goto L_808001B8;
    }
    // 0x80800174: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    // 0x80800178: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8080017C: jal         0x8008A0C8
    // 0x80800180: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    _subaddiemarker_entrypoint_1(rdram, ctx);
        goto after_10;
    // 0x80800180: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_10:
    // 0x80800184: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80800188: jal         0x800EE7F8
    // 0x8080018C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800EE7F8(rdram, ctx);
        goto after_11;
    // 0x8080018C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_11:
    // 0x80800190: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80800194: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080019C: addiu       $a1, $zero, 0x320
    ctx->r5 = ADD32(0, 0X320);
    // 0x808001A0: addiu       $a2, $zero, 0x33
    ctx->r6 = ADD32(0, 0X33);
    // 0x808001A4: jal         0x8008A0C8
    // 0x808001A8: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    _subaddiemarker_entrypoint_1(rdram, ctx);
        goto after_12;
    // 0x808001A8: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    after_12:
    // 0x808001AC: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x808001B0: jal         0x800EE7F8
    // 0x808001B4: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800EE7F8(rdram, ctx);
        goto after_13;
    // 0x808001B4: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_13:
L_808001B8:
    // 0x808001B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001BC:
    // 0x808001BC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808001C0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x808001C4: jr          $ra
    // 0x808001C8: nop

    return;
    // 0x808001C8: nop

;}
RECOMP_FUNC void _ncbadie_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089290: syscall     769
    recomp_syscall_handler(rdram, ctx, 0x80089290);
    return;
    // 0x80089294: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_808004F0_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x808004FC: jal         0x808017D0
    // 0x80800500: sh          $zero, 0x75C8($at)
    MEM_H(0X75C8, ctx->r1) = 0;
    func_808017D0_chflysaucer(rdram, ctx);
        goto after_0;
    // 0x80800500: sh          $zero, 0x75C8($at)
    MEM_H(0X75C8, ctx->r1) = 0;
    after_0:
    // 0x80800504: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800508: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080050C: jr          $ra
    // 0x80800510: nop

    return;
    // 0x80800510: nop

;}
RECOMP_FUNC void chusefeather_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800314: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(720, 0X364) << 16);
    // 0x80800318: jr          $ra
    // 0x8080031C: addiu       $v0, $v0, 0x364
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(720, 0X364));
    return;
    // 0x8080031C: addiu       $v0, $v0, 0x364
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(720, 0X364));
;}
RECOMP_FUNC void idwave_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800270: jr          $ra
    // 0x80800274: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800274: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8009CAF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CAF8: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8009CAFC: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x8009CB00: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8009CB04: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8009CB08: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8009CB0C: lw          $v0, 0x7F38($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7F38);
    // 0x8009CB10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009CB14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009CB18: beq         $v0, $zero, L_8009CB30
    if (ctx->r2 == 0) {
        // 0x8009CB1C: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8009CB30;
    }
    // 0x8009CB1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009CB20: jalr        $v0
    // 0x8009CB24: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8009CB24: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8009CB28: b           L_8009CB38
    // 0x8009CB2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8009CB38;
    // 0x8009CB2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8009CB30:
    // 0x8009CB30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8009CB34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8009CB38:
    // 0x8009CB38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009CB3C: jr          $ra
    // 0x8009CB40: nop

    return;
    // 0x8009CB40: nop

;}
RECOMP_FUNC void func_8009C128(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C128: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009C12C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8009C130: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009C134: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8009C138: jal         0x800EE7F8
    // 0x8009C13C: lw          $a1, 0xE4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XE4);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8009C13C: lw          $a1, 0xE4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XE4);
    after_0:
    // 0x8009C140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009C144: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009C148: jr          $ra
    // 0x8009C14C: nop

    return;
    // 0x8009C14C: nop

;}
RECOMP_FUNC void mlspline_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009AC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808009B0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x808009B4: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x808009B8: addiu       $t7, $a1, -0x1
    ctx->r15 = ADD32(ctx->r5, -0X1);
    // 0x808009BC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808009C0: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x808009C4: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x808009C8: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x808009CC: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x808009D0: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x808009D4: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x808009D8: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x808009DC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808009E0: jal         0x800F0D50
    // 0x808009E4: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    func_800F0D50(rdram, ctx);
        goto after_0;
    // 0x808009E4: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    after_0:
    // 0x808009E8: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x808009EC: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x808009F0: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x808009F4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x808009F8: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x808009FC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800A00: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800A04: mul.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800A08: trunc.w.s   $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80800A0C: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80800A10: nop

    // 0x80800A14: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80800A18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800A1C: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80800A20: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800A24: bne         $v0, $zero, L_80800AE0
    if (ctx->r2 != 0) {
        // 0x80800A28: sub.s       $f20, $f2, $f4
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f2.fl - ctx->f4.fl;
            goto L_80800AE0;
    }
    // 0x80800A28: sub.s       $f20, $f2, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x80800A2C: beq         $at, $zero, L_80800DB8
    if (ctx->r1 == 0) {
        // 0x80800A30: sll         $a1, $a0, 2
        ctx->r5 = S32(ctx->r4 << 2);
            goto L_80800DB8;
    }
    // 0x80800A30: sll         $a1, $a0, 2
    ctx->r5 = S32(ctx->r4 << 2);
    // 0x80800A34: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800A38: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80800A3C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800A40: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80800A44: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800A48: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800A4C: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x80800A50: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800A54: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800A58: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800A5C: addu        $v1, $a2, $a1
    ctx->r3 = ADD32(ctx->r6, ctx->r5);
    // 0x80800A60: addu        $v0, $a3, $a1
    ctx->r2 = ADD32(ctx->r7, ctx->r5);
L_80800A64:
    // 0x80800A64: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80800A68: lwc1        $f12, 0xC($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80800A6C: lwc1        $f0, 0x18($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80800A70: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80800A74: sub.s       $f6, $f2, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80800A78: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x80800A7C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800A80: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80800A84: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80800A88: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800A8C: mul.s       $f4, $f22, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f10.fl);
    // 0x80800A90: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80800A94: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80800A98: nop

    // 0x80800A9C: mul.s       $f8, $f24, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f24.fl, ctx->f12.fl);
    // 0x80800AA0: sub.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80800AA4: mul.s       $f6, $f26, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f26.fl, ctx->f2.fl);
    // 0x80800AA8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800AAC: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80800AB0: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80800AB4: lwc1        $f6, -0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80800AB8: sub.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80800ABC: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80800AC0: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
    // 0x80800AC4: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80800AC8: lwc1        $f8, -0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80800ACC: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80800AD0: bne         $at, $zero, L_80800A64
    if (ctx->r1 != 0) {
        // 0x80800AD4: swc1        $f10, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
            goto L_80800A64;
    }
    // 0x80800AD4: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
    // 0x80800AD8: b           L_80800DBC
    // 0x80800ADC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80800DBC;
    // 0x80800ADC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80800AE0:
    // 0x80800AE0: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    // 0x80800AE4: multu       $a0, $a1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800AE8: addiu       $t2, $a0, 0x2
    ctx->r10 = ADD32(ctx->r4, 0X2);
    // 0x80800AEC: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x80800AF0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800AF4: addiu       $t3, $a0, 0x3
    ctx->r11 = ADD32(ctx->r4, 0X3);
    // 0x80800AF8: mflo        $t0
    ctx->r8 = lo;
    // 0x80800AFC: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80800B00: bne         $v1, $t2, L_80800B6C
    if (ctx->r3 != ctx->r10) {
        // 0x80800B04: addu        $a2, $a2, $t1
        ctx->r6 = ADD32(ctx->r6, ctx->r9);
            goto L_80800B6C;
    }
    // 0x80800B04: addu        $a2, $a2, $t1
    ctx->r6 = ADD32(ctx->r6, ctx->r9);
    // 0x80800B08: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800B0C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800B10: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x80800B14: lwc1        $f26, 0x0($v1)
    ctx->f26.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80800B18: lwc1        $f24, 0xC($v1)
    ctx->f24.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80800B1C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80800B20: sub.s       $f26, $f24, $f26
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f26.fl = ctx->f24.fl - ctx->f26.fl;
    // 0x80800B24: mul.s       $f28, $f26, $f16
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f28.fl = MUL_S(ctx->f26.fl, ctx->f16.fl);
    // 0x80800B28: beql        $a0, $a1, L_80800B5C
    if (ctx->r4 == ctx->r5) {
        // 0x80800B2C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80800B5C;
    }
    goto skip_0;
    // 0x80800B2C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_0:
    // 0x80800B30: swc1        $f28, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f28.u32l;
L_80800B34:
    // 0x80800B34: lwc1        $f26, 0x4($v1)
    ctx->f26.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80800B38: lwc1        $f24, 0x10($v1)
    ctx->f24.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80800B3C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80800B40: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800B44: sub.s       $f26, $f24, $f26
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f26.fl = ctx->f24.fl - ctx->f26.fl;
    // 0x80800B48: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800B4C: mul.s       $f28, $f26, $f16
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f28.fl = MUL_S(ctx->f26.fl, ctx->f16.fl);
    // 0x80800B50: bnel        $a0, $a1, L_80800B34
    if (ctx->r4 != ctx->r5) {
        // 0x80800B54: swc1        $f28, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f28.u32l;
            goto L_80800B34;
    }
    goto skip_1;
    // 0x80800B54: swc1        $f28, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f28.u32l;
    skip_1:
    // 0x80800B58: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80800B5C:
    // 0x80800B5C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800B60: swc1        $f28, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f28.u32l;
    // 0x80800B64: b           L_80800DBC
    // 0x80800B68: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80800DBC;
    // 0x80800B68: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80800B6C:
    // 0x80800B6C: bne         $v1, $t3, L_80800C90
    if (ctx->r3 != ctx->r11) {
        // 0x80800B70: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800C90;
    }
    // 0x80800B70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800B74: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800B78: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80800B7C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800B80: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80800B84: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800B88: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800B8C: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x80800B90: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800B94: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800B98: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800B9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800BA0: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x80800BA4: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x80800BA8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80800BAC: lwc1        $f24, 0x0($v1)
    ctx->f24.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80800BB0: lwc1        $f12, 0xC($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80800BB4: beq         $a0, $a1, L_80800C30
    if (ctx->r4 == ctx->r5) {
        // 0x80800BB8: lwc1        $f14, 0x18($v1)
        ctx->f14.u32l = MEM_W(ctx->r3, 0X18);
            goto L_80800C30;
    }
    // 0x80800BB8: lwc1        $f14, 0x18($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X18);
L_80800BBC:
    // 0x80800BBC: sub.s       $f10, $f14, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f24.fl;
    // 0x80800BC0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80800BC4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800BC8: sub.s       $f8, $f12, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x80800BCC: mul.s       $f6, $f22, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f10.fl);
    // 0x80800BD0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800BD4: mul.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80800BD8: add.s       $f4, $f24, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f24.fl + ctx->f24.fl;
    // 0x80800BDC: mul.s       $f2, $f28, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f28.fl, ctx->f12.fl);
    // 0x80800BE0: nop

    // 0x80800BE4: mul.s       $f0, $f26, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f26.fl, ctx->f14.fl);
    // 0x80800BE8: add.s       $f6, $f8, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80800BEC: sub.s       $f2, $f4, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x80800BF0: mul.s       $f6, $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80800BF4: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80800BF8: add.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80800BFC: mul.s       $f10, $f16, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80800C00: swc1        $f0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80800C04: lwc1        $f0, -0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80800C08: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80800C0C: swc1        $f0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80800C10: lwc1        $f0, -0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80800C14: add.s       $f10, $f0, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80800C18: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
    // 0x80800C1C: lwc1        $f24, 0x0($v1)
    ctx->f24.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80800C20: lwc1        $f12, 0xC($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80800C24: lwc1        $f14, 0x18($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80800C28: bne         $a0, $a1, L_80800BBC
    if (ctx->r4 != ctx->r5) {
        // 0x80800C2C: nop
    
            goto L_80800BBC;
    }
    // 0x80800C2C: nop

L_80800C30:
    // 0x80800C30: sub.s       $f10, $f14, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f24.fl;
    // 0x80800C34: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800C38: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800C3C: sub.s       $f8, $f12, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x80800C40: mul.s       $f6, $f22, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f10.fl);
    // 0x80800C44: add.s       $f4, $f24, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f24.fl + ctx->f24.fl;
    // 0x80800C48: mul.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80800C4C: add.s       $f6, $f8, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80800C50: mul.s       $f2, $f28, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f28.fl, ctx->f12.fl);
    // 0x80800C54: sub.s       $f2, $f4, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x80800C58: mul.s       $f0, $f26, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f26.fl, ctx->f14.fl);
    // 0x80800C5C: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80800C60: mul.s       $f6, $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80800C64: add.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80800C68: mul.s       $f10, $f16, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80800C6C: swc1        $f0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80800C70: lwc1        $f0, -0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80800C74: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80800C78: swc1        $f0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80800C7C: lwc1        $f0, -0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80800C80: add.s       $f10, $f0, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80800C84: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
    // 0x80800C88: b           L_80800DBC
    // 0x80800C8C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80800DBC;
    // 0x80800C8C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80800C90:
    // 0x80800C90: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800C94: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80800C98: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800C9C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80800CA0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800CA4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800CA8: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x80800CAC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800CB0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800CB4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800CB8: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x80800CBC: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x80800CC0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80800CC4: lwc1        $f14, 0x0($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80800CC8: beq         $a0, $a1, L_80800D50
    if (ctx->r4 == ctx->r5) {
        // 0x80800CCC: lwc1        $f26, 0x24($v1)
        ctx->f26.u32l = MEM_W(ctx->r3, 0X24);
            goto L_80800D50;
    }
    // 0x80800CCC: lwc1        $f26, 0x24($v1)
    ctx->f26.u32l = MEM_W(ctx->r3, 0X24);
L_80800CD0:
    // 0x80800CD0: sub.s       $f12, $f26, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f26.fl - ctx->f14.fl;
    // 0x80800CD4: lwc1        $f10, 0xC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80800CD8: lwc1        $f8, 0x18($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80800CDC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80800CE0: mul.s       $f12, $f22, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f22.fl, ctx->f12.fl);
    // 0x80800CE4: sub.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80800CE8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800CEC: mul.s       $f10, $f28, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f28.fl, ctx->f10.fl);
    // 0x80800CF0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800CF4: mul.s       $f6, $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80800CF8: add.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f14.fl;
    // 0x80800CFC: mul.s       $f2, $f24, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f24.fl, ctx->f8.fl);
    // 0x80800D00: add.s       $f12, $f6, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x80800D04: sub.s       $f10, $f4, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80800D08: mul.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x80800D0C: add.s       $f2, $f10, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x80800D10: sub.s       $f2, $f2, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f26.fl;
    // 0x80800D14: add.s       $f2, $f12, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x80800D18: sub.s       $f8, $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x80800D1C: swc1        $f2, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
    // 0x80800D20: lwc1        $f2, -0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80800D24: mul.s       $f8, $f16, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x80800D28: nop

    // 0x80800D2C: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x80800D30: swc1        $f2, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
    // 0x80800D34: lwc1        $f2, -0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80800D38: add.s       $f8, $f2, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x80800D3C: swc1        $f8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80800D40: lwc1        $f14, 0x0($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80800D44: lwc1        $f26, 0x24($v1)
    ctx->f26.u32l = MEM_W(ctx->r3, 0X24);
    // 0x80800D48: bne         $a0, $a1, L_80800CD0
    if (ctx->r4 != ctx->r5) {
        // 0x80800D4C: nop
    
            goto L_80800CD0;
    }
    // 0x80800D4C: nop

L_80800D50:
    // 0x80800D50: sub.s       $f12, $f26, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f26.fl - ctx->f14.fl;
    // 0x80800D54: lwc1        $f10, 0xC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80800D58: lwc1        $f8, 0x18($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80800D5C: add.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f14.fl;
    // 0x80800D60: mul.s       $f12, $f22, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f22.fl, ctx->f12.fl);
    // 0x80800D64: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800D68: sub.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80800D6C: mul.s       $f10, $f28, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f28.fl, ctx->f10.fl);
    // 0x80800D70: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800D74: mul.s       $f6, $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80800D78: sub.s       $f10, $f4, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80800D7C: mul.s       $f2, $f24, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f24.fl, ctx->f8.fl);
    // 0x80800D80: add.s       $f12, $f6, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x80800D84: sub.s       $f8, $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x80800D88: mul.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x80800D8C: add.s       $f2, $f10, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x80800D90: mul.s       $f8, $f16, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x80800D94: sub.s       $f2, $f2, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f26.fl;
    // 0x80800D98: add.s       $f2, $f12, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x80800D9C: swc1        $f2, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
    // 0x80800DA0: lwc1        $f2, -0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80800DA4: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x80800DA8: swc1        $f2, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
    // 0x80800DAC: lwc1        $f2, -0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80800DB0: add.s       $f8, $f2, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x80800DB4: swc1        $f8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
L_80800DB8:
    // 0x80800DB8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80800DBC:
    // 0x80800DBC: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800DC0: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80800DC4: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80800DC8: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x80800DCC: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x80800DD0: jr          $ra
    // 0x80800DD4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80800DD4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
