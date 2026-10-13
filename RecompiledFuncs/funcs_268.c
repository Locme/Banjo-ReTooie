#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_808003C4_chsquits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003C4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x808003C8: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x808003CC: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x808003D0: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x808003D4: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x808003D8: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x808003DC: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x808003E0: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x808003E4: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x808003E8: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x808003EC: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x808003F0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808003F4: lw          $t6, 0x28($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X28);
    // 0x808003F8: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1456, 0X694) << 16);
    // 0x808003FC: addiu       $t8, $t8, 0x694
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1456, 0X694));
    // 0x80800400: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80800404: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80800408: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8080040C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80800410: addu        $s5, $t7, $t8
    ctx->r21 = ADD32(ctx->r15, ctx->r24);
    // 0x80800414: lwc1        $f24, 0x2C($a0)
    ctx->f24.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x80800418: lw          $a1, 0x8($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X8);
    // 0x8080041C: jal         0x800D91EC
    // 0x80800420: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    func_800D91EC(rdram, ctx);
        goto after_0;
    // 0x80800420: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    after_0:
    // 0x80800424: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x80800428: lw          $t9, 0x4($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X4);
    // 0x8080042C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80800430: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80800434: blez        $t9, L_808004C0
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80800438: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1456, 0X5A4) << 16);
            goto L_808004C0;
    }
    // 0x80800438: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1456, 0X5A4) << 16);
    // 0x8080043C: lwc1        $f22, 0x5A4($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1456, 0X5A4));
    // 0x80800440: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1456, 0X5A8) << 16);
    // 0x80800444: lui         $s6, 0x8080
    ctx->r22 = S32(RELOC_HI16(1456, 0X720) << 16);
    // 0x80800448: addiu       $s6, $s6, 0x720
    ctx->r22 = ADD32(ctx->r22, (int16_t)RELOC_LO16(1456, 0X720));
    // 0x8080044C: lwc1        $f20, 0x5A8($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1456, 0X5A8));
    // 0x80800450: lw          $t0, 0x0($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X0);
L_80800454:
    // 0x80800454: lwc1        $f12, 0x2C($s4)
    ctx->f12.u32l = MEM_W(ctx->r20, 0X2C);
    // 0x80800458: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    // 0x8080045C: addu        $s0, $t0, $s3
    ctx->r16 = ADD32(ctx->r8, ctx->r19);
    // 0x80800460: jal         0x80800528
    // 0x80800464: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    func_80800528_chsquits(rdram, ctx);
        goto after_1;
    // 0x80800464: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    after_1:
    // 0x80800468: beq         $v0, $zero, L_808004A8
    if (ctx->r2 == 0) {
        // 0x8080046C: addiu       $s1, $s4, 0x4
        ctx->r17 = ADD32(ctx->r20, 0X4);
            goto L_808004A8;
    }
    // 0x8080046C: addiu       $s1, $s4, 0x4
    ctx->r17 = ADD32(ctx->r20, 0X4);
    // 0x80800470: jal         0x800C4B7C
    // 0x80800474: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    func_800C4B7C(rdram, ctx);
        goto after_2;
    // 0x80800474: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    after_2:
    // 0x80800478: jal         0x800C4B70
    // 0x8080047C: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    func_800C4B70(rdram, ctx);
        goto after_3;
    // 0x8080047C: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    after_3:
    // 0x80800480: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80800484: jal         0x800DC178
    // 0x80800488: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x80800488: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_4:
    // 0x8080048C: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800490: jal         0x800C4B64
    // 0x80800494: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    func_800C4B64(rdram, ctx);
        goto after_5;
    // 0x80800494: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    after_5:
    // 0x80800498: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8080049C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808004A0: jal         0x80089D18
    // 0x808004A4: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x808004A4: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_6:
L_808004A8:
    // 0x808004A8: lw          $t1, 0x4($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X4);
    // 0x808004AC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x808004B0: addiu       $s3, $s3, 0xC
    ctx->r19 = ADD32(ctx->r19, 0XC);
    // 0x808004B4: slt         $at, $s2, $t1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x808004B8: bnel        $at, $zero, L_80800454
    if (ctx->r1 != 0) {
        // 0x808004BC: lw          $t0, 0x0($s5)
        ctx->r8 = MEM_W(ctx->r21, 0X0);
            goto L_80800454;
    }
    goto skip_0;
    // 0x808004BC: lw          $t0, 0x0($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X0);
    skip_0:
L_808004C0:
    // 0x808004C0: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x808004C4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808004C8: beql        $t2, $zero, L_808004F8
    if (ctx->r10 == 0) {
        // 0x808004CC: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_808004F8;
    }
    goto skip_1;
    // 0x808004CC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_1:
    // 0x808004D0: lhu         $t3, 0x6E($s4)
    ctx->r11 = MEM_HU(ctx->r20, 0X6E);
    // 0x808004D4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808004D8: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x808004DC: andi        $t4, $t3, 0xFE00
    ctx->r12 = ctx->r11 & 0XFE00;
    // 0x808004E0: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x808004E4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808004E8: jal         0x800DC178
    // 0x808004EC: sh          $t5, 0x6E($s4)
    MEM_H(0X6E, ctx->r20) = ctx->r13;
    func_800DC178(rdram, ctx);
        goto after_7;
    // 0x808004EC: sh          $t5, 0x6E($s4)
    MEM_H(0X6E, ctx->r20) = ctx->r13;
    after_7:
    // 0x808004F0: swc1        $f0, 0x2C($s4)
    MEM_W(0X2C, ctx->r20) = ctx->f0.u32l;
    // 0x808004F4: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_808004F8:
    // 0x808004F8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808004FC: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800500: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80800504: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80800508: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8080050C: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80800510: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80800514: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80800518: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8080051C: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80800520: jr          $ra
    // 0x80800524: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80800524: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void susplinet_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080013C: lh          $t6, 0x30($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X30);
    // 0x80800140: lh          $t7, 0x4E($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X4E);
    // 0x80800144: lwc1        $f4, 0x44($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X44);
    // 0x80800148: addu        $v1, $a0, $t6
    ctx->r3 = ADD32(ctx->r4, ctx->r14);
    // 0x8080014C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80800150: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x80800154: lh          $t0, -0x2($t9)
    ctx->r8 = MEM_H(ctx->r25, -0X2);
    // 0x80800158: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080015C: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x80800160: nop

    // 0x80800164: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800168: c.le.s      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.fl <= ctx->f4.fl;
    // 0x8080016C: nop

    // 0x80800170: bc1f        L_8080017C
    if (!c1cs) {
        // 0x80800174: nop
    
            goto L_8080017C;
    }
    // 0x80800174: nop

    // 0x80800178: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080017C:
    // 0x8080017C: jr          $ra
    // 0x80800180: nop

    return;
    // 0x80800180: nop

;}
RECOMP_FUNC void _gsmaker_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082570: syscall     2
    recomp_syscall_handler(rdram, ctx, 0x80082570);
    return;
    // 0x80082574: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_808006E8_chfactoryroofbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006F0: jal         0x80085808
    // 0x808006F4: addiu       $a1, $zero, 0xA08
    ctx->r5 = ADD32(0, 0XA08);
    _chswitch_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x808006F4: addiu       $a1, $zero, 0xA08
    ctx->r5 = ADD32(0, 0XA08);
    after_0:
    // 0x808006F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800700: jr          $ra
    // 0x80800704: nop

    return;
    // 0x80800704: nop

;}
RECOMP_FUNC void func_80800250_gcmapsects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800250: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800254: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800258: sll         $s0, $a1, 2
    ctx->r16 = S32(ctx->r5 << 2);
    // 0x8080025C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800260: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800264: subu        $s0, $s0, $a1
    ctx->r16 = SUB32(ctx->r16, ctx->r5);
    // 0x80800268: lw          $t6, 0x68($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X68);
    // 0x8080026C: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x80800270: subu        $s0, $s0, $a1
    ctx->r16 = SUB32(ctx->r16, ctx->r5);
    // 0x80800274: sll         $s0, $s0, 3
    ctx->r16 = S32(ctx->r16 << 3);
    // 0x80800278: addu        $v1, $t6, $s0
    ctx->r3 = ADD32(ctx->r14, ctx->r16);
    // 0x8080027C: lw          $t7, 0x44($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X44);
    // 0x80800280: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800284: bnel        $t7, $zero, L_808002EC
    if (ctx->r15 != 0) {
        // 0x80800288: lw          $t3, 0x48($v1)
        ctx->r11 = MEM_W(ctx->r3, 0X48);
            goto L_808002EC;
    }
    goto skip_0;
    // 0x80800288: lw          $t3, 0x48($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X48);
    skip_0:
    // 0x8080028C: lhu         $v0, 0x40($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X40);
    // 0x80800290: beql        $v0, $zero, L_808002EC
    if (ctx->r2 == 0) {
        // 0x80800294: lw          $t3, 0x48($v1)
        ctx->r11 = MEM_W(ctx->r3, 0X48);
            goto L_808002EC;
    }
    goto skip_1;
    // 0x80800294: lw          $t3, 0x48($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X48);
    skip_1:
    // 0x80800298: jal         0x800D674C
    // 0x8080029C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800D674C(rdram, ctx);
        goto after_0;
    // 0x8080029C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_0:
    // 0x808002A0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808002A4: jal         0x800B27FC
    // 0x808002A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B27FC(rdram, ctx);
        goto after_1;
    // 0x808002A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808002AC: beql        $v0, $zero, L_808002D4
    if (ctx->r2 == 0) {
        // 0x808002B0: lw          $t0, 0x68($s1)
        ctx->r8 = MEM_W(ctx->r17, 0X68);
            goto L_808002D4;
    }
    goto skip_2;
    // 0x808002B0: lw          $t0, 0x68($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X68);
    skip_2:
    // 0x808002B4: jal         0x800B27FC
    // 0x808002B8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800B27FC(rdram, ctx);
        goto after_2;
    // 0x808002B8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x808002BC: jal         0x80087A30
    // 0x808002C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _dbtex_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x808002C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x808002C4: lw          $t8, 0x68($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X68);
    // 0x808002C8: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x808002CC: sw          $v0, 0x44($t9)
    MEM_W(0X44, ctx->r25) = ctx->r2;
    // 0x808002D0: lw          $t0, 0x68($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X68);
L_808002D4:
    // 0x808002D4: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x808002D8: jal         0x800D6CEC
    // 0x808002DC: lhu         $a0, 0x40($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X40);
    func_800D6CEC(rdram, ctx);
        goto after_4;
    // 0x808002DC: lhu         $a0, 0x40($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X40);
    after_4:
    // 0x808002E0: lw          $t2, 0x68($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X68);
    // 0x808002E4: addu        $v1, $t2, $s0
    ctx->r3 = ADD32(ctx->r10, ctx->r16);
    // 0x808002E8: lw          $t3, 0x48($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X48);
L_808002EC:
    // 0x808002EC: bnel        $t3, $zero, L_8080034C
    if (ctx->r11 != 0) {
        // 0x808002F0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080034C;
    }
    goto skip_3;
    // 0x808002F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x808002F4: lhu         $v0, 0x42($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X42);
    // 0x808002F8: beql        $v0, $zero, L_8080034C
    if (ctx->r2 == 0) {
        // 0x808002FC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080034C;
    }
    goto skip_4;
    // 0x808002FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80800300: jal         0x800D674C
    // 0x80800304: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800D674C(rdram, ctx);
        goto after_5;
    // 0x80800304: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x80800308: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080030C: jal         0x800B27FC
    // 0x80800310: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B27FC(rdram, ctx);
        goto after_6;
    // 0x80800310: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x80800314: beql        $v0, $zero, L_8080033C
    if (ctx->r2 == 0) {
        // 0x80800318: lw          $t6, 0x68($s1)
        ctx->r14 = MEM_W(ctx->r17, 0X68);
            goto L_8080033C;
    }
    goto skip_5;
    // 0x80800318: lw          $t6, 0x68($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X68);
    skip_5:
    // 0x8080031C: jal         0x800B27FC
    // 0x80800320: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800B27FC(rdram, ctx);
        goto after_7;
    // 0x80800320: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_7:
    // 0x80800324: jal         0x80087A30
    // 0x80800328: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _dbtex_entrypoint_0(rdram, ctx);
        goto after_8;
    // 0x80800328: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x8080032C: lw          $t4, 0x68($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X68);
    // 0x80800330: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x80800334: sw          $v0, 0x48($t5)
    MEM_W(0X48, ctx->r13) = ctx->r2;
    // 0x80800338: lw          $t6, 0x68($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X68);
L_8080033C:
    // 0x8080033C: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x80800340: jal         0x800D6CEC
    // 0x80800344: lhu         $a0, 0x42($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X42);
    func_800D6CEC(rdram, ctx);
        goto after_9;
    // 0x80800344: lhu         $a0, 0x42($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X42);
    after_9:
    // 0x80800348: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080034C:
    // 0x8080034C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800350: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800354: jr          $ra
    // 0x80800358: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800358: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void subaddiebounce_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808000D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000E0: jal         0x800D8FF8
    // 0x808000E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808000E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808000E8: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x808000EC: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808000F0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x808000F4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x808000F8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808000FC: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    // 0x80800100: bc1tl       L_80800128
    if (c1cs) {
        // 0x80800104: mfc1        $a2, $f2
        ctx->r6 = (int32_t)ctx->f2.u32l;
            goto L_80800128;
    }
    goto skip_0;
    // 0x80800104: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    skip_0:
    // 0x80800108: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8080010C: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800110: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800114: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80800118: nop

    // 0x8080011C: bc1f        L_808001A0
    if (!c1cs) {
        // 0x80800120: nop
    
            goto L_808001A0;
    }
    // 0x80800120: nop

    // 0x80800124: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
L_80800128:
    // 0x80800128: jal         0x800EFA20
    // 0x8080012C: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    func_800EFA20(rdram, ctx);
        goto after_1;
    // 0x8080012C: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x80800130: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800134: jal         0x800EF04C
    // 0x80800138: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800EF04C(rdram, ctx);
        goto after_2;
    // 0x80800138: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x8080013C: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80800140: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800144: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x80800148: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8080014C: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80800150: nop

    // 0x80800154: bc1fl       L_80800188
    if (!c1cs) {
        // 0x80800158: lwc1        $f8, 0x34($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X34);
            goto L_80800188;
    }
    goto skip_1;
    // 0x80800158: lwc1        $f8, 0x34($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X34);
    skip_1:
    // 0x8080015C: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800160: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800164: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800168: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x8080016C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80800170: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800174: swc1        $f2, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f2.u32l;
    // 0x80800178: swc1        $f2, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f2.u32l;
    // 0x8080017C: b           L_808001A0
    // 0x80800180: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
        goto L_808001A0;
    // 0x80800180: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    // 0x80800184: lwc1        $f8, 0x34($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X34);
L_80800188:
    // 0x80800188: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8080018C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800190: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800194: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80800198: b           L_808001A0
    // 0x8080019C: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
        goto L_808001A0;
    // 0x8080019C: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
L_808001A0:
    // 0x808001A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808001AC: jr          $ra
    // 0x808001B0: nop

    return;
    // 0x808001B0: nop

;}
RECOMP_FUNC void func_808010B0_chterryegg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808010B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808010B8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1112, 0X1450) << 16);
    // 0x808010BC: addiu       $a2, $a2, 0x1450
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1112, 0X1450));
    // 0x808010C0: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x808010C4: jal         0x80089D20
    // 0x808010C8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808010C8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_0:
    // 0x808010CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808010D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808010D4: jr          $ra
    // 0x808010D8: nop

    return;
    // 0x808010D8: nop

;}
RECOMP_FUNC void func_80110D58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110D58: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80110D5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80110D60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80110D64: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80110D68: jal         0x801125D8
    // 0x80110D6C: nop

    func_801125D8(rdram, ctx);
        goto after_0;
    // 0x80110D6C: nop

    after_0:
    // 0x80110D70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80110D74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80110D78: jr          $ra
    // 0x80110D7C: nop

    return;
    // 0x80110D7C: nop

;}
RECOMP_FUNC void func_80800704_chphlegm(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800704: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800708: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080070C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800710: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800714: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800718: jal         0x800DF744
    // 0x8080071C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800DF744(rdram, ctx);
        goto after_0;
    // 0x8080071C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x80800720: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80800724: jal         0x800DF744
    // 0x80800728: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_1;
    // 0x80800728: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8080072C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800730: jal         0x80101870
    // 0x80800734: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80101870(rdram, ctx);
        goto after_2;
    // 0x80800734: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800738: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080073C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800740: jr          $ra
    // 0x80800744: nop

    return;
    // 0x80800744: nop

;}
RECOMP_FUNC void bsbtrot_entrypoint_29(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801F40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801F44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801F48: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801F4C: jal         0x80800538
    // 0x80801F50: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800538_bsbtrot(rdram, ctx);
        goto after_0;
    // 0x80801F50: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801F54: jal         0x800839D8
    // 0x80801F58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsrest_entrypoint_18(rdram, ctx);
        goto after_1;
    // 0x80801F58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801F5C: jal         0x8008E430
    // 0x80801F60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E430(rdram, ctx);
        goto after_2;
    // 0x80801F60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801F64: beq         $v0, $zero, L_80801F84
    if (ctx->r2 == 0) {
        // 0x80801F68: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801F84;
    }
    // 0x80801F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801F6C: lui         $a2, 0x3FA6
    ctx->r6 = S32(0X3FA6 << 16);
    // 0x80801F70: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80801F74: jal         0x8008CB3C
    // 0x80801F78: addiu       $a1, $zero, 0x29B
    ctx->r5 = ADD32(0, 0X29B);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_3;
    // 0x80801F78: addiu       $a1, $zero, 0x29B
    ctx->r5 = ADD32(0, 0X29B);
    after_3:
    // 0x80801F7C: b           L_80801FC4
    // 0x80801F80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801FC4;
    // 0x80801F80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801F84:
    // 0x80801F84: jal         0x8008E40C
    // 0x80801F88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E40C(rdram, ctx);
        goto after_4;
    // 0x80801F88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801F8C: beq         $v0, $zero, L_80801FB0
    if (ctx->r2 == 0) {
        // 0x80801F90: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801FB0;
    }
    // 0x80801F90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801F94: lui         $a2, 0x3FA6
    ctx->r6 = S32(0X3FA6 << 16);
    // 0x80801F98: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80801F9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801FA0: jal         0x8008CB3C
    // 0x80801FA4: addiu       $a1, $zero, 0x86
    ctx->r5 = ADD32(0, 0X86);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_5;
    // 0x80801FA4: addiu       $a1, $zero, 0x86
    ctx->r5 = ADD32(0, 0X86);
    after_5:
    // 0x80801FA8: b           L_80801FC4
    // 0x80801FAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801FC4;
    // 0x80801FAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801FB0:
    // 0x80801FB0: lui         $a2, 0x3F99
    ctx->r6 = S32(0X3F99 << 16);
    // 0x80801FB4: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80801FB8: jal         0x8008CB3C
    // 0x80801FBC: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_6;
    // 0x80801FBC: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    after_6:
    // 0x80801FC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801FC4:
    // 0x80801FC4: jal         0x800931AC
    // 0x80801FC8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800931AC(rdram, ctx);
        goto after_7;
    // 0x80801FC8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x80801FCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801FD0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801FD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801FD8: jr          $ra
    // 0x80801FDC: nop

    return;
    // 0x80801FDC: nop

;}
RECOMP_FUNC void func_808003D4_chtoothyfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808003D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808003DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003E0: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x808003E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808003E8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x808003EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808003F0: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_808003F4:
    // 0x808003F4: lbu         $t6, 0x34($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X34);
    // 0x808003F8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x808003FC: bne         $t6, $zero, L_80800408
    if (ctx->r14 != 0) {
        // 0x80800400: nop
    
            goto L_80800408;
    }
    // 0x80800400: nop

    // 0x80800404: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80800408:
    // 0x80800408: bne         $v0, $a0, L_808003F4
    if (ctx->r2 != ctx->r4) {
        // 0x8080040C: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_808003F4;
    }
    // 0x8080040C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800410: lbu         $t7, 0x3E($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X3E);
    // 0x80800414: beql        $a2, $t7, L_80800464
    if (ctx->r6 == ctx->r15) {
        // 0x80800418: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800464;
    }
    goto skip_0;
    // 0x80800418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080041C: beq         $a2, $zero, L_80800444
    if (ctx->r6 == 0) {
        // 0x80800420: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800444;
    }
    // 0x80800420: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800424: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800428: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080042C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80800430: jal         0x808000E8
    // 0x80800434: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_808000E8_chtoothyfish(rdram, ctx);
        goto after_0;
    // 0x80800434: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800438: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8080043C: b           L_8080045C
    // 0x80800440: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
        goto L_8080045C;
    // 0x80800440: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
L_80800444:
    // 0x80800444: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800448: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8080044C: jal         0x808000E8
    // 0x80800450: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_808000E8_chtoothyfish(rdram, ctx);
        goto after_1;
    // 0x80800450: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_1:
    // 0x80800454: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800458: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
L_8080045C:
    // 0x8080045C: sb          $a2, 0x3E($a3)
    MEM_B(0X3E, ctx->r7) = ctx->r6;
    // 0x80800460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800464:
    // 0x80800464: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800468: jr          $ra
    // 0x8080046C: nop

    return;
    // 0x8080046C: nop

;}
RECOMP_FUNC void _bskazstill_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083618: syscall     70
    recomp_syscall_handler(rdram, ctx, 0x80083618);
    return;
    // 0x8008361C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80095C94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095C94: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80095C98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80095C9C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80095CA0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80095CA4: lw          $t7, 0x94($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X94);
    // 0x80095CA8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80095CAC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80095CB0: sb          $t6, 0xA4($t7)
    MEM_B(0XA4, ctx->r15) = ctx->r14;
    // 0x80095CB4: lw          $t8, 0x94($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X94);
    // 0x80095CB8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80095CBC: jal         0x80091E80
    // 0x80095CC0: sw          $zero, 0x50($t8)
    MEM_W(0X50, ctx->r24) = 0;
    func_80091E80(rdram, ctx);
        goto after_0;
    // 0x80095CC0: sw          $zero, 0x50($t8)
    MEM_W(0X50, ctx->r24) = 0;
    after_0:
    // 0x80095CC4: beql        $v0, $zero, L_80096190
    if (ctx->r2 == 0) {
        // 0x80095CC8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80096190;
    }
    goto skip_0;
    // 0x80095CC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80095CCC: jal         0x8008E454
    // 0x80095CD0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8008E454(rdram, ctx);
        goto after_1;
    // 0x80095CD0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80095CD4: beq         $v0, $zero, L_8009618C
    if (ctx->r2 == 0) {
        // 0x80095CD8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8009618C;
    }
    // 0x80095CD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80095CDC: jal         0x8009C128
    // 0x80095CE0: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    func_8009C128(rdram, ctx);
        goto after_2;
    // 0x80095CE0: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    after_2:
    // 0x80095CE4: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x80095CE8: jal         0x800BEAAC
    // 0x80095CEC: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800BEAAC(rdram, ctx);
        goto after_3;
    // 0x80095CEC: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_3:
    // 0x80095CF0: beql        $v0, $zero, L_80095D18
    if (ctx->r2 == 0) {
        // 0x80095CF4: lw          $t0, 0x94($s1)
        ctx->r8 = MEM_W(ctx->r17, 0X94);
            goto L_80095D18;
    }
    goto skip_1;
    // 0x80095CF4: lw          $t0, 0x94($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X94);
    skip_1:
    // 0x80095CF8: lw          $t9, 0x94($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X94);
    // 0x80095CFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80095D00: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80095D04: jal         0x800C68E8
    // 0x80095D08: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    func_800C68E8(rdram, ctx);
        goto after_4;
    // 0x80095D08: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_4:
    // 0x80095D0C: b           L_80095D2C
    // 0x80095D10: lw          $t1, 0x94($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X94);
        goto L_80095D2C;
    // 0x80095D10: lw          $t1, 0x94($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X94);
    // 0x80095D14: lw          $t0, 0x94($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X94);
L_80095D18:
    // 0x80095D18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80095D1C: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80095D20: jal         0x800C68E8
    // 0x80095D24: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    func_800C68E8(rdram, ctx);
        goto after_5;
    // 0x80095D24: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    after_5:
    // 0x80095D28: lw          $t1, 0x94($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X94);
L_80095D2C:
    // 0x80095D2C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80095D30: sb          $zero, 0xA1($t1)
    MEM_B(0XA1, ctx->r9) = 0;
    // 0x80095D34: lw          $t2, 0x94($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X94);
    // 0x80095D38: sb          $zero, 0x54($t2)
    MEM_B(0X54, ctx->r10) = 0;
    // 0x80095D3C: lw          $t3, 0x94($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X94);
    // 0x80095D40: sb          $zero, 0x55($t3)
    MEM_B(0X55, ctx->r11) = 0;
    // 0x80095D44: lw          $t4, 0x94($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X94);
    // 0x80095D48: sw          $zero, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = 0;
    // 0x80095D4C: lw          $s0, 0x94($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X94);
    // 0x80095D50: lbu         $t5, 0x56($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X56);
    // 0x80095D54: sb          $t5, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r13;
    // 0x80095D58: jal         0x800CB840
    // 0x80095D5C: lw          $a1, 0x184($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X184);
    func_800CB840(rdram, ctx);
        goto after_6;
    // 0x80095D5C: lw          $a1, 0x184($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X184);
    after_6:
    // 0x80095D60: lw          $s0, 0x94($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X94);
    // 0x80095D64: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80095D68: lwc1        $f12, 0x64($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X64);
    // 0x80095D6C: jal         0x80095C34
    // 0x80095D70: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    func_80095C34(rdram, ctx);
        goto after_7;
    // 0x80095D70: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    after_7:
    // 0x80095D74: lw          $t6, 0x94($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X94);
    // 0x80095D78: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80095D7C: swc1        $f0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f0.u32l;
    // 0x80095D80: lw          $s0, 0x94($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X94);
    // 0x80095D84: lwc1        $f12, 0x68($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X68);
    // 0x80095D88: jal         0x80095C34
    // 0x80095D8C: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    func_80095C34(rdram, ctx);
        goto after_8;
    // 0x80095D8C: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    after_8:
    // 0x80095D90: lw          $t7, 0x94($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X94);
    // 0x80095D94: swc1        $f0, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f0.u32l;
    // 0x80095D98: lw          $s0, 0x94($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X94);
    // 0x80095D9C: lw          $t8, 0x9C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X9C);
    // 0x80095DA0: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80095DA4: sltiu       $at, $t9, 0xA
    ctx->r1 = ctx->r25 < 0XA ? 1 : 0;
    // 0x80095DA8: beq         $at, $zero, L_80095F4C
    if (ctx->r1 == 0) {
        // 0x80095DAC: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80095F4C;
    }
    // 0x80095DAC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80095DB0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80095DB4: addu        $at, $at, $t9
    gpr jr_addend_80095DBC = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80095DB8: lw          $t9, 0x4DC0($at)
    ctx->r25 = ADD32(ctx->r1, 0X4DC0);
    // 0x80095DBC: jr          $t9
    // 0x80095DC0: nop

    switch (jr_addend_80095DBC >> 2) {
        case 0: goto L_80095DC4; break;
        case 1: goto L_80095F34; break;
        case 2: goto L_80095DC4; break;
        case 3: goto L_80095DC4; break;
        case 4: goto L_80095EA0; break;
        case 5: goto L_80095F34; break;
        case 6: goto L_80095F08; break;
        case 7: goto L_80095F18; break;
        case 8: goto L_80095DC4; break;
        case 9: goto L_80095F28; break;
        default: switch_error(__func__, 0x80095DBC, 0x80124DC0);
    }
    // 0x80095DC0: nop

L_80095DC4:
    // 0x80095DC4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80095DC8: jal         0x8009C128
    // 0x80095DCC: addiu       $a1, $s0, 0x78
    ctx->r5 = ADD32(ctx->r16, 0X78);
    func_8009C128(rdram, ctx);
        goto after_9;
    // 0x80095DCC: addiu       $a1, $s0, 0x78
    ctx->r5 = ADD32(ctx->r16, 0X78);
    after_9:
    // 0x80095DD0: lw          $a1, 0x94($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X94);
    // 0x80095DD4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80095DD8: jal         0x8009C15C
    // 0x80095DDC: addiu       $a1, $a1, 0x84
    ctx->r5 = ADD32(ctx->r5, 0X84);
    func_8009C15C(rdram, ctx);
        goto after_10;
    // 0x80095DDC: addiu       $a1, $a1, 0x84
    ctx->r5 = ADD32(ctx->r5, 0X84);
    after_10:
    // 0x80095DE0: lw          $s0, 0x94($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X94);
    // 0x80095DE4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80095DE8: lw          $t0, 0x9C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X9C);
    // 0x80095DEC: bnel        $t0, $at, L_80095E60
    if (ctx->r8 != ctx->r1) {
        // 0x80095DF0: lw          $s0, 0x94($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X94);
            goto L_80095E60;
    }
    goto skip_2;
    // 0x80095DF0: lw          $s0, 0x94($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X94);
    skip_2:
    // 0x80095DF4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80095DF8: jal         0x800C670C
    // 0x80095DFC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_800C670C(rdram, ctx);
        goto after_11;
    // 0x80095DFC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_11:
    // 0x80095E00: beq         $v0, $zero, L_80095E5C
    if (ctx->r2 == 0) {
        // 0x80095E04: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80095E5C;
    }
    // 0x80095E04: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80095E08: jal         0x800C67D8
    // 0x80095E0C: nop

    func_800C67D8(rdram, ctx);
        goto after_12;
    // 0x80095E0C: nop

    after_12:
    // 0x80095E10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80095E14: jal         0x800A0E58
    // 0x80095E18: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    func_800A0E58(rdram, ctx);
        goto after_13;
    // 0x80095E18: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_13:
    // 0x80095E1C: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80095E20: lw          $s0, 0x94($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X94);
    // 0x80095E24: sub.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80095E28: lwc1        $f6, 0x7C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80095E2C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80095E30: nop

    // 0x80095E34: bc1fl       L_80095E60
    if (!c1cs) {
        // 0x80095E38: lw          $s0, 0x94($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X94);
            goto L_80095E60;
    }
    goto skip_3;
    // 0x80095E38: lw          $s0, 0x94($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X94);
    skip_3:
    // 0x80095E3C: sub.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80095E40: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80095E44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80095E48: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80095E4C: swc1        $f8, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f8.u32l;
    // 0x80095E50: lw          $t2, 0x94($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X94);
    // 0x80095E54: jal         0x8009BA58
    // 0x80095E58: sb          $t1, 0xA1($t2)
    MEM_B(0XA1, ctx->r10) = ctx->r9;
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_14;
    // 0x80095E58: sb          $t1, 0xA1($t2)
    MEM_B(0XA1, ctx->r10) = ctx->r9;
    after_14:
L_80095E5C:
    // 0x80095E5C: lw          $s0, 0x94($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X94);
L_80095E60:
    // 0x80095E60: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x80095E64: addiu       $a1, $s0, 0x78
    ctx->r5 = ADD32(ctx->r16, 0X78);
    // 0x80095E68: jal         0x800EFB24
    // 0x80095E6C: addiu       $a2, $s0, 0x84
    ctx->r6 = ADD32(ctx->r16, 0X84);
    func_800EFB24(rdram, ctx);
        goto after_15;
    // 0x80095E6C: addiu       $a2, $s0, 0x84
    ctx->r6 = ADD32(ctx->r16, 0X84);
    after_15:
    // 0x80095E70: lw          $s0, 0x94($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X94);
    // 0x80095E74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80095E78: addiu       $a1, $s0, 0x84
    ctx->r5 = ADD32(ctx->r16, 0X84);
    // 0x80095E7C: addiu       $a2, $s0, 0x78
    ctx->r6 = ADD32(ctx->r16, 0X78);
    // 0x80095E80: jal         0x800D4584
    // 0x80095E84: addiu       $a3, $s0, 0x58
    ctx->r7 = ADD32(ctx->r16, 0X58);
    func_800D4584(rdram, ctx);
        goto after_16;
    // 0x80095E84: addiu       $a3, $s0, 0x58
    ctx->r7 = ADD32(ctx->r16, 0X58);
    after_16:
    // 0x80095E88: lw          $a1, 0x94($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X94);
    // 0x80095E8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80095E90: jal         0x8009C0F8
    // 0x80095E94: addiu       $a1, $a1, 0x78
    ctx->r5 = ADD32(ctx->r5, 0X78);
    func_8009C0F8(rdram, ctx);
        goto after_17;
    // 0x80095E94: addiu       $a1, $a1, 0x78
    ctx->r5 = ADD32(ctx->r5, 0X78);
    after_17:
    // 0x80095E98: b           L_80095F4C
    // 0x80095E9C: lw          $s0, 0x94($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X94);
        goto L_80095F4C;
    // 0x80095E9C: lw          $s0, 0x94($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X94);
L_80095EA0:
    // 0x80095EA0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80095EA4: jal         0x8009C128
    // 0x80095EA8: addiu       $a1, $s0, 0x78
    ctx->r5 = ADD32(ctx->r16, 0X78);
    func_8009C128(rdram, ctx);
        goto after_18;
    // 0x80095EA8: addiu       $a1, $s0, 0x78
    ctx->r5 = ADD32(ctx->r16, 0X78);
    after_18:
    // 0x80095EAC: lw          $a1, 0x94($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X94);
    // 0x80095EB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80095EB4: jal         0x8009C15C
    // 0x80095EB8: addiu       $a1, $a1, 0x84
    ctx->r5 = ADD32(ctx->r5, 0X84);
    func_8009C15C(rdram, ctx);
        goto after_19;
    // 0x80095EB8: addiu       $a1, $a1, 0x84
    ctx->r5 = ADD32(ctx->r5, 0X84);
    after_19:
    // 0x80095EBC: lw          $s0, 0x94($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X94);
    // 0x80095EC0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x80095EC4: addiu       $a1, $s0, 0x78
    ctx->r5 = ADD32(ctx->r16, 0X78);
    // 0x80095EC8: jal         0x800EFB24
    // 0x80095ECC: addiu       $a2, $s0, 0x84
    ctx->r6 = ADD32(ctx->r16, 0X84);
    func_800EFB24(rdram, ctx);
        goto after_20;
    // 0x80095ECC: addiu       $a2, $s0, 0x84
    ctx->r6 = ADD32(ctx->r16, 0X84);
    after_20:
    // 0x80095ED0: lw          $s0, 0x94($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X94);
    // 0x80095ED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80095ED8: addiu       $a1, $s0, 0x84
    ctx->r5 = ADD32(ctx->r16, 0X84);
    // 0x80095EDC: addiu       $a2, $s0, 0x78
    ctx->r6 = ADD32(ctx->r16, 0X78);
    // 0x80095EE0: jal         0x800D4584
    // 0x80095EE4: addiu       $a3, $s0, 0x58
    ctx->r7 = ADD32(ctx->r16, 0X58);
    func_800D4584(rdram, ctx);
        goto after_21;
    // 0x80095EE4: addiu       $a3, $s0, 0x58
    ctx->r7 = ADD32(ctx->r16, 0X58);
    after_21:
    // 0x80095EE8: jal         0x80095798
    // 0x80095EEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80095798(rdram, ctx);
        goto after_22;
    // 0x80095EEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_22:
    // 0x80095EF0: lw          $a1, 0x94($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X94);
    // 0x80095EF4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80095EF8: jal         0x8009C0F8
    // 0x80095EFC: addiu       $a1, $a1, 0x78
    ctx->r5 = ADD32(ctx->r5, 0X78);
    func_8009C0F8(rdram, ctx);
        goto after_23;
    // 0x80095EFC: addiu       $a1, $a1, 0x78
    ctx->r5 = ADD32(ctx->r5, 0X78);
    after_23:
    // 0x80095F00: b           L_80095F4C
    // 0x80095F04: lw          $s0, 0x94($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X94);
        goto L_80095F4C;
    // 0x80095F04: lw          $s0, 0x94($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X94);
L_80095F08:
    // 0x80095F08: jal         0x800978A4
    // 0x80095F0C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800978A4(rdram, ctx);
        goto after_24;
    // 0x80095F0C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_24:
    // 0x80095F10: b           L_80095F4C
    // 0x80095F14: lw          $s0, 0x94($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X94);
        goto L_80095F4C;
    // 0x80095F14: lw          $s0, 0x94($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X94);
L_80095F18:
    // 0x80095F18: jal         0x80096768
    // 0x80095F1C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80096768(rdram, ctx);
        goto after_25;
    // 0x80095F1C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_25:
    // 0x80095F20: b           L_80095F4C
    // 0x80095F24: lw          $s0, 0x94($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X94);
        goto L_80095F4C;
    // 0x80095F24: lw          $s0, 0x94($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X94);
L_80095F28:
    // 0x80095F28: jal         0x80084D68
    // 0x80095F2C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    _bahitspline_entrypoint_2(rdram, ctx);
        goto after_26;
    // 0x80095F2C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_26:
    // 0x80095F30: lw          $s0, 0x94($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X94);
L_80095F34:
    // 0x80095F34: sb          $zero, 0x54($s0)
    MEM_B(0X54, ctx->r16) = 0;
    // 0x80095F38: lw          $t3, 0x94($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X94);
    // 0x80095F3C: sb          $zero, 0x55($t3)
    MEM_B(0X55, ctx->r11) = 0;
    // 0x80095F40: lw          $t4, 0x94($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X94);
    // 0x80095F44: sb          $zero, 0x56($t4)
    MEM_B(0X56, ctx->r12) = 0;
    // 0x80095F48: lw          $s0, 0x94($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X94);
L_80095F4C:
    // 0x80095F4C: jal         0x800C670C
    // 0x80095F50: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800C670C(rdram, ctx);
        goto after_27;
    // 0x80095F50: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_27:
    // 0x80095F54: beq         $v0, $zero, L_80095F8C
    if (ctx->r2 == 0) {
        // 0x80095F58: nop
    
            goto L_80095F8C;
    }
    // 0x80095F58: nop

    // 0x80095F5C: lw          $t5, 0x94($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X94);
    // 0x80095F60: jal         0x800C67D8
    // 0x80095F64: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    func_800C67D8(rdram, ctx);
        goto after_28;
    // 0x80095F64: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    after_28:
    // 0x80095F68: lw          $s0, 0x94($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X94);
    // 0x80095F6C: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x80095F70: lwc1        $f10, 0x7C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80095F74: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80095F78: nop

    // 0x80095F7C: bc1fl       L_80095F8C
    if (!c1cs) {
        // 0x80095F80: sb          $t6, 0xA0($s0)
        MEM_B(0XA0, ctx->r16) = ctx->r14;
            goto L_80095F8C;
    }
    goto skip_4;
    // 0x80095F80: sb          $t6, 0xA0($s0)
    MEM_B(0XA0, ctx->r16) = ctx->r14;
    skip_4:
    // 0x80095F84: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80095F88: sb          $t6, 0xA0($s0)
    MEM_B(0XA0, ctx->r16) = ctx->r14;
L_80095F8C:
    // 0x80095F8C: jal         0x80096530
    // 0x80095F90: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80096530(rdram, ctx);
        goto after_29;
    // 0x80095F90: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_29:
    // 0x80095F94: beql        $v0, $zero, L_80095FAC
    if (ctx->r2 == 0) {
        // 0x80095F98: lw          $s0, 0x94($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X94);
            goto L_80095FAC;
    }
    goto skip_5;
    // 0x80095F98: lw          $s0, 0x94($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X94);
    skip_5:
    // 0x80095F9C: lw          $t8, 0x94($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X94);
    // 0x80095FA0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80095FA4: sb          $t7, 0x56($t8)
    MEM_B(0X56, ctx->r24) = ctx->r15;
    // 0x80095FA8: lw          $s0, 0x94($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X94);
L_80095FAC:
    // 0x80095FAC: lbu         $t9, 0xA0($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XA0);
    // 0x80095FB0: beql        $t9, $zero, L_8009603C
    if (ctx->r25 == 0) {
        // 0x80095FB4: lbu         $t2, 0x56($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0X56);
            goto L_8009603C;
    }
    goto skip_6;
    // 0x80095FB4: lbu         $t2, 0x56($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X56);
    skip_6:
    // 0x80095FB8: jal         0x800C67D8
    // 0x80095FBC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800C67D8(rdram, ctx);
        goto after_30;
    // 0x80095FBC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_30:
    // 0x80095FC0: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80095FC4: jal         0x800A0E58
    // 0x80095FC8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800A0E58(rdram, ctx);
        goto after_31;
    // 0x80095FC8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_31:
    // 0x80095FCC: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80095FD0: lw          $s0, 0x94($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X94);
    // 0x80095FD4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80095FD8: sub.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x80095FDC: lwc1        $f16, 0x7C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80095FE0: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x80095FE4: nop

    // 0x80095FE8: bc1fl       L_8009603C
    if (!c1cs) {
        // 0x80095FEC: lbu         $t2, 0x56($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0X56);
            goto L_8009603C;
    }
    goto skip_7;
    // 0x80095FEC: lbu         $t2, 0x56($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X56);
    skip_7:
    // 0x80095FF0: jal         0x80096254
    // 0x80095FF4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80096254(rdram, ctx);
        goto after_32;
    // 0x80095FF4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_32:
    // 0x80095FF8: lw          $t0, 0x94($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X94);
    // 0x80095FFC: lbu         $t1, 0x56($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X56);
    // 0x80096000: beq         $t1, $zero, L_80096030
    if (ctx->r9 == 0) {
        // 0x80096004: nop
    
            goto L_80096030;
    }
    // 0x80096004: nop

    // 0x80096008: jal         0x8009BB50
    // 0x8009600C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_33;
    // 0x8009600C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_33:
    // 0x80096010: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80096014: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80096018: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8009601C: nop

    // 0x80096020: bc1f        L_80096030
    if (!c1cs) {
        // 0x80096024: nop
    
            goto L_80096030;
    }
    // 0x80096024: nop

    // 0x80096028: jal         0x8009BA58
    // 0x8009602C: lui         $a1, 0xBF80
    ctx->r5 = S32(0XBF80 << 16);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_34;
    // 0x8009602C: lui         $a1, 0xBF80
    ctx->r5 = S32(0XBF80 << 16);
    after_34:
L_80096030:
    // 0x80096030: b           L_800960A0
    // 0x80096034: lw          $s0, 0x94($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X94);
        goto L_800960A0;
    // 0x80096034: lw          $s0, 0x94($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X94);
    // 0x80096038: lbu         $t2, 0x56($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X56);
L_8009603C:
    // 0x8009603C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80096040: beq         $t2, $zero, L_80096094
    if (ctx->r10 == 0) {
        // 0x80096044: nop
    
            goto L_80096094;
    }
    // 0x80096044: nop

    // 0x80096048: jal         0x80096260
    // 0x8009604C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80096260(rdram, ctx);
        goto after_35;
    // 0x8009604C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_35:
    // 0x80096050: jal         0x8009BB50
    // 0x80096054: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_36;
    // 0x80096054: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_36:
    // 0x80096058: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8009605C: nop

    // 0x80096060: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80096064: nop

    // 0x80096068: bc1f        L_8009608C
    if (!c1cs) {
        // 0x8009606C: nop
    
            goto L_8009608C;
    }
    // 0x8009606C: nop

    // 0x80096070: jal         0x80096628
    // 0x80096074: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80096628(rdram, ctx);
        goto after_37;
    // 0x80096074: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_37:
    // 0x80096078: andi        $t3, $v0, 0x8000
    ctx->r11 = ctx->r2 & 0X8000;
    // 0x8009607C: bne         $t3, $zero, L_8009608C
    if (ctx->r11 != 0) {
        // 0x80096080: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8009608C;
    }
    // 0x80096080: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80096084: jal         0x8009BA58
    // 0x80096088: lui         $a1, 0xBF80
    ctx->r5 = S32(0XBF80 << 16);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_38;
    // 0x80096088: lui         $a1, 0xBF80
    ctx->r5 = S32(0XBF80 << 16);
    after_38:
L_8009608C:
    // 0x8009608C: b           L_800960A0
    // 0x80096090: lw          $s0, 0x94($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X94);
        goto L_800960A0;
    // 0x80096090: lw          $s0, 0x94($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X94);
L_80096094:
    // 0x80096094: jal         0x80096254
    // 0x80096098: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80096254(rdram, ctx);
        goto after_39;
    // 0x80096098: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_39:
    // 0x8009609C: lw          $s0, 0x94($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X94);
L_800960A0:
    // 0x800960A0: lbu         $t4, 0xA2($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0XA2);
    // 0x800960A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800960A8: beq         $t4, $zero, L_800960B8
    if (ctx->r12 == 0) {
        // 0x800960AC: nop
    
            goto L_800960B8;
    }
    // 0x800960AC: nop

    // 0x800960B0: jal         0x8009C0F8
    // 0x800960B4: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    func_8009C0F8(rdram, ctx);
        goto after_40;
    // 0x800960B4: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    after_40:
L_800960B8:
    // 0x800960B8: jal         0x800CB870
    // 0x800960BC: nop

    func_800CB870(rdram, ctx);
        goto after_41;
    // 0x800960BC: nop

    after_41:
    // 0x800960C0: lw          $s0, 0x94($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X94);
    // 0x800960C4: lbu         $t5, 0x54($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X54);
    // 0x800960C8: beql        $t5, $zero, L_800960F0
    if (ctx->r13 == 0) {
        // 0x800960CC: sb          $zero, 0xA3($s0)
        MEM_B(0XA3, ctx->r16) = 0;
            goto L_800960F0;
    }
    goto skip_8;
    // 0x800960CC: sb          $zero, 0xA3($s0)
    MEM_B(0XA3, ctx->r16) = 0;
    skip_8:
    // 0x800960D0: lbu         $a0, 0xA3($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XA3);
    // 0x800960D4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800960D8: jal         0x800F1418
    // 0x800960DC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    func_800F1418(rdram, ctx);
        goto after_42;
    // 0x800960DC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    after_42:
    // 0x800960E0: lw          $t6, 0x94($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X94);
    // 0x800960E4: b           L_800960F0
    // 0x800960E8: sb          $v0, 0xA3($t6)
    MEM_B(0XA3, ctx->r14) = ctx->r2;
        goto L_800960F0;
    // 0x800960E8: sb          $v0, 0xA3($t6)
    MEM_B(0XA3, ctx->r14) = ctx->r2;
    // 0x800960EC: sb          $zero, 0xA3($s0)
    MEM_B(0XA3, ctx->r16) = 0;
L_800960F0:
    // 0x800960F0: addiu       $s0, $sp, 0x44
    ctx->r16 = ADD32(ctx->r29, 0X44);
    // 0x800960F4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800960F8: jal         0x8009C15C
    // 0x800960FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8009C15C(rdram, ctx);
        goto after_43;
    // 0x800960FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_43:
    // 0x80096100: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80096104: jal         0x8009C128
    // 0x80096108: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    func_8009C128(rdram, ctx);
        goto after_44;
    // 0x80096108: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_44:
    // 0x8009610C: lw          $a0, 0x94($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X94);
    // 0x80096110: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x80096114: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80096118: jal         0x800EFB24
    // 0x8009611C: addiu       $a0, $a0, 0x90
    ctx->r4 = ADD32(ctx->r4, 0X90);
    func_800EFB24(rdram, ctx);
        goto after_45;
    // 0x8009611C: addiu       $a0, $a0, 0x90
    ctx->r4 = ADD32(ctx->r4, 0X90);
    after_45:
    // 0x80096120: lw          $s0, 0x94($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X94);
    // 0x80096124: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x80096128: beql        $a1, $zero, L_80096148
    if (ctx->r5 == 0) {
        // 0x8009612C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80096148;
    }
    goto skip_9;
    // 0x8009612C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_9:
    // 0x80096130: jal         0x800FB508
    // 0x80096134: addiu       $a0, $s0, 0x6C
    ctx->r4 = ADD32(ctx->r16, 0X6C);
    func_800FB508(rdram, ctx);
        goto after_46;
    // 0x80096134: addiu       $a0, $s0, 0x6C
    ctx->r4 = ADD32(ctx->r16, 0X6C);
    after_46:
    // 0x80096138: lw          $s0, 0x94($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X94);
    // 0x8009613C: addiu       $t7, $s0, 0x6C
    ctx->r15 = ADD32(ctx->r16, 0X6C);
    // 0x80096140: sw          $t7, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r15;
    // 0x80096144: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80096148:
    // 0x80096148: jal         0x80095774
    // 0x8009614C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    baflag_clear(rdram, ctx);
        goto after_47;
    // 0x8009614C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_47:
    // 0x80096150: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80096154: jal         0x80095774
    // 0x80096158: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    baflag_clear(rdram, ctx);
        goto after_48;
    // 0x80096158: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_48:
    // 0x8009615C: lw          $t8, 0x94($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X94);
    // 0x80096160: lw          $t9, 0x50($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X50);
    // 0x80096164: beql        $t9, $zero, L_80096190
    if (ctx->r25 == 0) {
        // 0x80096168: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80096190;
    }
    goto skip_10;
    // 0x80096168: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_10:
    // 0x8009616C: jal         0x8008E078
    // 0x80096170: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    player_isStable(rdram, ctx);
        goto after_49;
    // 0x80096170: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_49:
    // 0x80096174: beq         $v0, $zero, L_8009618C
    if (ctx->r2 == 0) {
        // 0x80096178: addiu       $a1, $zero, 0x91
        ctx->r5 = ADD32(0, 0X91);
            goto L_8009618C;
    }
    // 0x80096178: addiu       $a1, $zero, 0x91
    ctx->r5 = ADD32(0, 0X91);
    // 0x8009617C: lw          $t0, 0x94($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X94);
    // 0x80096180: lw          $a2, 0x184($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X184);
    // 0x80096184: jal         0x8010114C
    // 0x80096188: lw          $a0, 0x50($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X50);
    func_8010114C(rdram, ctx);
        goto after_50;
    // 0x80096188: lw          $a0, 0x50($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X50);
    after_50:
L_8009618C:
    // 0x8009618C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80096190:
    // 0x80096190: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80096194: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80096198: jr          $ra
    // 0x8009619C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8009619C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_8080000C_chweldarbossfireball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800010: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800014: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800018: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080001C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800020: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800024: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800028: jal         0x800DC178
    // 0x8080002C: sw          $zero, 0x34($a0)
    MEM_W(0X34, ctx->r4) = 0;
    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x8080002C: sw          $zero, 0x34($a0)
    MEM_W(0X34, ctx->r4) = 0;
    after_0:
    // 0x80800030: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x80800034: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800038: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1376, 0X458) << 16);
    // 0x8080003C: addiu       $a2, $a2, 0x458
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1376, 0X458));
    // 0x80800040: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800044: jal         0x80089D18
    // 0x80800048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080004C: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x80800050: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80800054: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800058: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8080005C: jal         0x800EFB24
    // 0x80800060: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_800EFB24(rdram, ctx);
        goto after_2;
    // 0x80800060: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x80800064: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800068: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8080006C: jal         0x800F18FC
    // 0x80800070: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    func_800F18FC(rdram, ctx);
        goto after_3;
    // 0x80800070: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_3:
    // 0x80800074: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800078: lui         $a1, 0x44E1
    ctx->r5 = S32(0X44E1 << 16);
    // 0x8080007C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80800080: swc1        $f6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f6.u32l;
    // 0x80800084: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800088: swc1        $f8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f8.u32l;
    // 0x8080008C: jal         0x800EF368
    // 0x80800090: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800EF368(rdram, ctx);
        goto after_4;
    // 0x80800090: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x80800094: jal         0x800C8A98
    // 0x80800098: nop

    func_800C8A98(rdram, ctx);
        goto after_5;
    // 0x80800098: nop

    after_5:
    // 0x8080009C: sw          $v0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r2;
    // 0x808000A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000A4: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x808000A8: jal         0x800C8E54
    // 0x808000AC: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    func_800C8E54(rdram, ctx);
        goto after_6;
    // 0x808000AC: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    after_6:
    // 0x808000B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808000BC: jr          $ra
    // 0x808000C0: nop

    return;
    // 0x808000C0: nop

;}
RECOMP_FUNC void _chprisonbits_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087000: syscall     491
    recomp_syscall_handler(rdram, ctx, 0x80087000);
    return;
    // 0x80087004: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _bsbabykaz_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800827F0: syscall     14
    recomp_syscall_handler(rdram, ctx, 0x800827F0);
    return;
    // 0x800827F4: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void chjinjo_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080010C: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x80800110: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1672, 0X1368) << 16);
    // 0x80800114: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800118: jr          $ra
    // 0x8080011C: lh          $v0, 0x1368($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(1672, 0X1368));
    return;
    // 0x8080011C: lh          $v0, 0x1368($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(1672, 0X1368));
;}
RECOMP_FUNC void func_8009CAAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CAAC: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8009CAB0: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x8009CAB4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8009CAB8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8009CABC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8009CAC0: lw          $v0, 0x7F38($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7F38);
    // 0x8009CAC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009CAC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009CACC: beq         $v0, $zero, L_8009CAE4
    if (ctx->r2 == 0) {
        // 0x8009CAD0: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8009CAE4;
    }
    // 0x8009CAD0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009CAD4: jalr        $v0
    // 0x8009CAD8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8009CAD8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8009CADC: b           L_8009CAEC
    // 0x8009CAE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8009CAEC;
    // 0x8009CAE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8009CAE4:
    // 0x8009CAE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8009CAE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8009CAEC:
    // 0x8009CAEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009CAF0: jr          $ra
    // 0x8009CAF4: nop

    return;
    // 0x8009CAF4: nop

;}
RECOMP_FUNC void bababykaz_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800050: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800054: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800058: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8080005C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x80800060: jal         0x800EA068
    // 0x80800064: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    func_800EA068(rdram, ctx);
        goto after_0;
    // 0x80800064: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_0:
    // 0x80800068: bne         $v0, $zero, L_80800088
    if (ctx->r2 != 0) {
        // 0x8080006C: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_80800088;
    }
    // 0x8080006C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800070: jal         0x8009EA14
    // 0x80800074: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_8009EA14(rdram, ctx);
        goto after_1;
    // 0x80800074: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x80800078: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8080007C: lw          $t6, 0x10($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X10);
    // 0x80800080: b           L_80800094
    // 0x80800084: swc1        $f0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f0.u32l;
        goto L_80800094;
    // 0x80800084: swc1        $f0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f0.u32l;
L_80800088:
    // 0x80800088: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080008C: lw          $t7, 0x10($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X10);
    // 0x80800090: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
L_80800094:
    // 0x80800094: lw          $t8, 0x10($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X10);
    // 0x80800098: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
    // 0x8080009C: lw          $t9, 0x10($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X10);
    // 0x808000A0: sb          $zero, 0x1($t9)
    MEM_B(0X1, ctx->r25) = 0;
    // 0x808000A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000AC: jr          $ra
    // 0x808000B0: nop

    return;
    // 0x808000B0: nop

;}
RECOMP_FUNC void chklungo_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1240, 0X3B6C) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x3B6C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1240, 0X3B6C));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x3B6C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1240, 0X3B6C));
;}
RECOMP_FUNC void func_800CA098(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA098: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800CA09C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800CA0A0: jr          $ra
    // 0x800CA0A4: swc1        $f4, -0x549C($at)
    MEM_W(-0X549C, ctx->r1) = ctx->f4.u32l;
    return;
    // 0x800CA0A4: swc1        $f4, -0x549C($at)
    MEM_W(-0X549C, ctx->r1) = ctx->f4.u32l;
;}
RECOMP_FUNC void bschokedie_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080000C: lui         $a2, 0x4086
    ctx->r6 = S32(0X4086 << 16);
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800014: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800018: jal         0x8008CCBC
    // 0x8080001C: addiu       $a1, $zero, 0xF0
    ctx->r5 = ADD32(0, 0XF0);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_0;
    // 0x8080001C: addiu       $a1, $zero, 0xF0
    ctx->r5 = ADD32(0, 0XF0);
    after_0:
    // 0x80800020: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80800024: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080002C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800030: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800034: jal         0x8009FFD8
    // 0x80800038: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x80800038: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_1:
    // 0x8080003C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800040: jal         0x8009BA9C
    // 0x80800044: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009BA9C(rdram, ctx);
        goto after_2;
    // 0x80800044: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080004C: jal         0x8009B9B0
    // 0x80800050: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_3;
    // 0x80800050: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800058: jal         0x800A4DFC
    // 0x8080005C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_800A4DFC(rdram, ctx);
        goto after_4;
    // 0x8080005C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_4:
    // 0x80800060: jal         0x800A4CA8
    // 0x80800064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_5;
    // 0x80800064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800068: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080006C: jal         0x80089288
    // 0x80800070: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    _ncbadie_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x80800070: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    after_6:
    // 0x80800074: jal         0x800A0180
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A0180(rdram, ctx);
        goto after_7;
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080007C: lui         $a2, 0x4073
    ctx->r6 = S32(0X4073 << 16);
    // 0x80800080: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800088: jal         0x80085338
    // 0x8080008C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_set(rdram, ctx);
        goto after_8;
    // 0x8080008C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80800090: jal         0x8008E944
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E944(rdram, ctx);
        goto after_9;
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800098: jal         0x80090A0C
    // 0x8080009C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80090A0C(rdram, ctx);
        goto after_10;
    // 0x8080009C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808000A0: jal         0x80085208
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basudie_entrypoint_1(rdram, ctx);
        goto after_11;
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808000A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808000AC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808000B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000B4: jr          $ra
    // 0x808000B8: nop

    return;
    // 0x808000B8: nop

;}
RECOMP_FUNC void func_80800600_bsbeefly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800600: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800604: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800608: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080060C: jal         0x80082838
    // 0x80800610: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _bsbee_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800610: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800614: jal         0x8009E710
    // 0x80800618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getPreviousState(rdram, ctx);
        goto after_1;
    // 0x80800618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080061C: lui         $a2, 0x3EC2
    ctx->r6 = S32(0X3EC2 << 16);
    // 0x80800620: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800624: ori         $a2, $a2, 0x8F5C
    ctx->r6 = ctx->r6 | 0X8F5C;
    // 0x80800628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080062C: jal         0x8008CB3C
    // 0x80800630: addiu       $a1, $zero, 0x1DC
    ctx->r5 = ADD32(0, 0X1DC);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_2;
    // 0x80800630: addiu       $a1, $zero, 0x1DC
    ctx->r5 = ADD32(0, 0X1DC);
    after_2:
    // 0x80800634: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80800638: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080063C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800640: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800644: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800648: jal         0x8009FFD8
    // 0x8080064C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_3;
    // 0x8080064C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_3:
    // 0x80800650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800654: jal         0x80095738
    // 0x80800658: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    baflag_isTrue(rdram, ctx);
        goto after_4;
    // 0x80800658: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_4:
    // 0x8080065C: beq         $v0, $zero, L_80800678
    if (ctx->r2 == 0) {
        // 0x80800660: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800678;
    }
    // 0x80800660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800668: jal         0x8009B9B0
    // 0x8080066C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_5;
    // 0x8080066C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_5:
    // 0x80800670: b           L_80800680
    // 0x80800674: nop

        goto L_80800680;
    // 0x80800674: nop

L_80800678:
    // 0x80800678: jal         0x8009B9B0
    // 0x8080067C: lui         $a1, 0x4416
    ctx->r5 = S32(0X4416 << 16);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_6;
    // 0x8080067C: lui         $a1, 0x4416
    ctx->r5 = S32(0X4416 << 16);
    after_6:
L_80800680:
    // 0x80800680: jal         0x8009C990
    // 0x80800684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_7;
    // 0x80800684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800688: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8080068C: jal         0x8009BB00
    // 0x80800690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_8;
    // 0x80800690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800694: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080069C: jal         0x8009BA68
    // 0x808006A0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_9;
    // 0x808006A0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_9:
    // 0x808006A4: jal         0x8009C990
    // 0x808006A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_10;
    // 0x808006A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808006AC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808006B0: jal         0x8009B9C0
    // 0x808006B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_11;
    // 0x808006B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808006B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006BC: jal         0x800A4DA4
    // 0x808006C0: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    func_800A4DA4(rdram, ctx);
        goto after_12;
    // 0x808006C0: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_12:
    // 0x808006C4: jal         0x8080039C
    // 0x808006C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080039C_bsbeefly(rdram, ctx);
        goto after_13;
    // 0x808006C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808006CC: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x808006D0: addiu       $at, $zero, 0x8B
    ctx->r1 = ADD32(0, 0X8B);
    // 0x808006D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006D8: beq         $t7, $at, L_808006F0
    if (ctx->r15 == ctx->r1) {
        // 0x808006DC: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_808006F0;
    }
    // 0x808006DC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808006E0: jal         0x80084598
    // 0x808006E4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    _baboost_entrypoint_2(rdram, ctx);
        goto after_14;
    // 0x808006E4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_14:
    // 0x808006E8: b           L_808006F4
    // 0x808006EC: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
        goto L_808006F4;
    // 0x808006EC: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
L_808006F0:
    // 0x808006F0: sw          $t8, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r24;
L_808006F4:
    // 0x808006F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808006F8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808006FC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800700: jr          $ra
    // 0x80800704: nop

    return;
    // 0x80800704: nop

;}
RECOMP_FUNC void func_808014B0_chalienkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808014B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808014B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808014B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808014BC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808014C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808014C4: jal         0x80100094
    // 0x808014C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808014C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808014CC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808014D0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808014D4: jal         0x800EE7F8
    // 0x808014D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x808014D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x808014DC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x808014E0: lbu         $t8, 0x77($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X77);
    // 0x808014E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014E8: lwc1        $f4, 0x10($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X10);
    // 0x808014EC: ori         $t9, $t8, 0x20
    ctx->r25 = ctx->r24 | 0X20;
    // 0x808014F0: sb          $t9, 0x77($s0)
    MEM_B(0X77, ctx->r16) = ctx->r25;
    // 0x808014F4: jal         0x80103014
    // 0x808014F8: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    func_80103014(rdram, ctx);
        goto after_2;
    // 0x808014F8: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x808014FC: jal         0x80104E78
    // 0x80801500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104E78(rdram, ctx);
        goto after_3;
    // 0x80801500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801504: jal         0x800DA544
    // 0x80801508: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800DA544(rdram, ctx);
        goto after_4;
    // 0x80801508: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x8080150C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801510: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801514: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801518: jr          $ra
    // 0x8080151C: nop

    return;
    // 0x8080151C: nop

;}
RECOMP_FUNC void ncbasuck_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F4: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x808000F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800100: jal         0x80800094
    // 0x80800104: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800094_ncbasuck(rdram, ctx);
        goto after_0;
    // 0x80800104: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800108: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080010C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800110: jal         0x80800020
    // 0x80800114: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    func_80800020_ncbasuck(rdram, ctx);
        goto after_1;
    // 0x80800114: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    after_1:
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080011C: jal         0x801107F0
    // 0x80800120: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_801107F0(rdram, ctx);
        goto after_2;
    // 0x80800120: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_2:
    // 0x80800124: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80800128: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x8080012C: jal         0x800EFB24
    // 0x80800130: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    func_800EFB24(rdram, ctx);
        goto after_3;
    // 0x80800130: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    after_3:
    // 0x80800134: jal         0x800EEF94
    // 0x80800138: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    func_800EEF94(rdram, ctx);
        goto after_4;
    // 0x80800138: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_4:
    // 0x8080013C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80800140: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80800144: jal         0x800F1A88
    // 0x80800148: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800F1A88(rdram, ctx);
        goto after_5;
    // 0x80800148: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_5:
    // 0x8080014C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80800150: bne         $t6, $zero, L_80800164
    if (ctx->r14 != 0) {
        // 0x80800154: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800164;
    }
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800158: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080015C: jal         0x80113978
    // 0x80800160: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80113978(rdram, ctx);
        goto after_6;
    // 0x80800160: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
L_80800164:
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800168: jal         0x80115358
    // 0x8080016C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80115358(rdram, ctx);
        goto after_7;
    // 0x8080016C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_7:
    // 0x80800170: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800178: jal         0x80115750
    // 0x8080017C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80115750(rdram, ctx);
        goto after_8;
    // 0x8080017C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_8:
    // 0x80800180: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800188: jal         0x80112C3C
    // 0x8080018C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80112C3C(rdram, ctx);
        goto after_9;
    // 0x8080018C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_9:
    // 0x80800190: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800198: lui         $a1, 0xC270
    ctx->r5 = S32(0XC270 << 16);
    // 0x8080019C: jal         0x80115828
    // 0x808001A0: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    func_80115828(rdram, ctx);
        goto after_10;
    // 0x808001A0: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    after_10:
    // 0x808001A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A8: jal         0x80115750
    // 0x808001AC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80115750(rdram, ctx);
        goto after_11;
    // 0x808001AC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_11:
    // 0x808001B0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x808001B4: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x808001B8: beql        $t7, $zero, L_80800204
    if (ctx->r15 == 0) {
        // 0x808001BC: addiu       $a0, $sp, 0x50
        ctx->r4 = ADD32(ctx->r29, 0X50);
            goto L_80800204;
    }
    goto skip_0;
    // 0x808001BC: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    skip_0:
    // 0x808001C0: jal         0x808000C4
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000C4_ncbasuck(rdram, ctx);
        goto after_12;
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808001C8: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x808001CC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808001D8: sub.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x808001DC: add.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x808001E0: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x808001E4: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x808001E8: jal         0x80112D08
    // 0x808001EC: nop

    func_80112D08(rdram, ctx);
        goto after_13;
    // 0x808001EC: nop

    after_13:
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F4: jal         0x80112C3C
    // 0x808001F8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80112C3C(rdram, ctx);
        goto after_14;
    // 0x808001F8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_14:
    // 0x808001FC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80800200: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
L_80800204:
    // 0x80800204: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800208: jal         0x800EEBF0
    // 0x8080020C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    func_800EEBF0(rdram, ctx);
        goto after_15;
    // 0x8080020C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    after_15:
    // 0x80800210: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80800214: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x80800218: jal         0x800EE780
    // 0x8080021C: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    func_800EE780(rdram, ctx);
        goto after_16;
    // 0x8080021C: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    after_16:
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800224: jal         0x80111CC8
    // 0x80800228: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_80111CC8(rdram, ctx);
        goto after_17;
    // 0x80800228: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_17:
    // 0x8080022C: beql        $v0, $zero, L_80800270
    if (ctx->r2 == 0) {
        // 0x80800230: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800270;
    }
    goto skip_1;
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80800234: jal         0x801138A0
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801138A0(rdram, ctx);
        goto after_18;
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x8080023C: bne         $v0, $zero, L_80800254
    if (ctx->r2 != 0) {
        // 0x80800240: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800254;
    }
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800244: jal         0x80115580
    // 0x80800248: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    func_80115580(rdram, ctx);
        goto after_19;
    // 0x80800248: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    after_19:
    // 0x8080024C: beql        $v0, $zero, L_80800270
    if (ctx->r2 == 0) {
        // 0x80800250: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800270;
    }
    goto skip_2;
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
L_80800254:
    // 0x80800254: jal         0x801138F4
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801138F4(rdram, ctx);
        goto after_20;
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x8080025C: beql        $v0, $zero, L_80800270
    if (ctx->r2 == 0) {
        // 0x80800260: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800270;
    }
    goto skip_3;
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x80800264: jal         0x80110F44
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80110F44(rdram, ctx);
        goto after_21;
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800270:
    // 0x80800270: jal         0x80800000
    // 0x80800274: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    func_80800000_ncbasuck(rdram, ctx);
        goto after_22;
    // 0x80800274: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    after_22:
    // 0x80800278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080027C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80800280: jal         0x80110A68
    // 0x80800284: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    func_80110A68(rdram, ctx);
        goto after_23;
    // 0x80800284: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    after_23:
    // 0x80800288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080028C: jal         0x80110790
    // 0x80800290: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_80110790(rdram, ctx);
        goto after_24;
    // 0x80800290: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_24:
    // 0x80800294: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800298: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080029C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x808002A0: jr          $ra
    // 0x808002A4: nop

    return;
    // 0x808002A4: nop

    // 0x808002A8: nop

    // 0x808002AC: nop

;}
RECOMP_FUNC void bashoes_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080050C: lw          $t6, 0x10C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10C);
    // 0x80800510: jr          $ra
    // 0x80800514: sw          $a1, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r5;
    return;
    // 0x80800514: sw          $a1, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_80800000_chsparkle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8080000C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800010: jal         0x800DC128
    // 0x80800014: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800DC128(rdram, ctx);
        goto after_0;
    // 0x80800014: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_0:
    // 0x80800018: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8080001C: jal         0x800B53A4
    // 0x80800020: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800B53A4(rdram, ctx);
        goto after_1;
    // 0x80800020: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80800024: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80800028: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2100, 0X120) << 16);
    // 0x8080002C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800030: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80800034: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x80800038: lh          $a1, 0x120($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(2100, 0X120));
    // 0x8080003C: jal         0x800BA3FC
    // 0x80800040: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800BA3FC(rdram, ctx);
        goto after_2;
    // 0x80800040: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800044: jal         0x800E3980
    // 0x80800048: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    func_800E3980(rdram, ctx);
        goto after_3;
    // 0x80800048: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    after_3:
    // 0x8080004C: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x80800050: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80800054: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80800058: jal         0x800EE7F8
    // 0x8080005C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x8080005C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_4:
    // 0x80800060: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800064: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800068: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8080006C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800070: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x80800074: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800078: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x8080007C: jal         0x800F18FC
    // 0x80800080: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    func_800F18FC(rdram, ctx);
        goto after_5;
    // 0x80800080: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x80800084: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x80800088: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080008C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800090: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800094: jal         0x800DC178
    // 0x80800098: nop

    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x80800098: nop

    after_6:
    // 0x8080009C: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808000A0: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x808000A4: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    // 0x808000A8: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x808000AC: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x808000B0: jal         0x800EEB9C
    // 0x808000B4: nop

    func_800EEB9C(rdram, ctx);
        goto after_7;
    // 0x808000B4: nop

    after_7:
    // 0x808000B8: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x808000BC: jal         0x800EF04C
    // 0x808000C0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800EF04C(rdram, ctx);
        goto after_8;
    // 0x808000C0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_8:
    // 0x808000C4: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x808000C8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808000CC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x808000D0: jal         0x800DC178
    // 0x808000D4: nop

    func_800DC178(rdram, ctx);
        goto after_9;
    // 0x808000D4: nop

    after_9:
    // 0x808000D8: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x808000DC: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2100, 0X12C) << 16);
    // 0x808000E0: addiu       $t8, $t8, 0x12C
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(2100, 0X12C));
    // 0x808000E4: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x808000E8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808000EC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808000F0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x808000F4: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x808000F8: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x808000FC: jal         0x800BABB8
    // 0x80800100: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_10;
    // 0x80800100: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_10:
    // 0x80800104: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800108: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8080010C: jr          $ra
    // 0x80800110: nop

    return;
    // 0x80800110: nop

;}
RECOMP_FUNC void _bashoes_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085078: syscall     148
    recomp_syscall_handler(rdram, ctx, 0x80085078);
    return;
    // 0x8008507C: addi        $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
;}
RECOMP_FUNC void bapreload_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001C8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808001CC: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(572, 0X2A2) << 16);
    // 0x808001D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001D4: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x808001D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001DC: lh          $v1, 0x2A2($v1)
    ctx->r3 = MEM_H(ctx->r3, (int16_t)RELOC_LO16(572, 0X2A2));
    // 0x808001E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808001E4: beq         $a0, $at, L_80800218
    if (ctx->r4 == ctx->r1) {
        // 0x808001E8: sw          $zero, 0x0($a1)
        MEM_W(0X0, ctx->r5) = 0;
            goto L_80800218;
    }
    // 0x808001E8: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x808001EC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x808001F0: beq         $a0, $at, L_80800218
    if (ctx->r4 == ctx->r1) {
        // 0x808001F4: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80800218;
    }
    // 0x808001F4: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x808001F8: bnel        $a0, $at, L_8080023C
    if (ctx->r4 != ctx->r1) {
        // 0x808001FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080023C;
    }
    goto skip_0;
    // 0x808001FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800200: jal         0x8009EA2C
    // 0x80800204: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8009EA2C(rdram, ctx);
        goto after_0;
    // 0x80800204: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80800208: beq         $v0, $zero, L_80800238
    if (ctx->r2 == 0) {
        // 0x8080020C: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80800238;
    }
    // 0x8080020C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800210: b           L_80800238
    // 0x80800214: addiu       $v1, $zero, 0x62E
    ctx->r3 = ADD32(0, 0X62E);
        goto L_80800238;
    // 0x80800214: addiu       $v1, $zero, 0x62E
    ctx->r3 = ADD32(0, 0X62E);
L_80800218:
    // 0x80800218: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8080021C: jal         0x8009EA2C
    // 0x80800220: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_8009EA2C(rdram, ctx);
        goto after_1;
    // 0x80800220: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_1:
    // 0x80800224: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800228: beq         $v0, $zero, L_80800238
    if (ctx->r2 == 0) {
        // 0x8080022C: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_80800238;
    }
    // 0x8080022C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800230: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800234: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
L_80800238:
    // 0x80800238: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080023C:
    // 0x8080023C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800240: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800244: jr          $ra
    // 0x80800248: nop

    return;
    // 0x80800248: nop

    // 0x8080024C: nop

;}
RECOMP_FUNC void _sukickball_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089B30: syscall     802
    recomp_syscall_handler(rdram, ctx, 0x80089B30);
    return;
    // 0x80089B34: addi        $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
;}
RECOMP_FUNC void func_80801450_gcboundDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801450: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801454: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801458: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080145C: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x80801460: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80801464: lw          $a1, 0x14($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X14);
    // 0x80801468: lw          $a0, 0x10($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X10);
    // 0x8080146C: jal         0x80801370
    // 0x80801470: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80801370_gcboundDll(rdram, ctx);
        goto after_0;
    // 0x80801470: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x80801474: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801478: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080147C: jr          $ra
    // 0x80801480: nop

    return;
    // 0x80801480: nop

;}
RECOMP_FUNC void _chtrashcompactor_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800861E0: syscall     288
    recomp_syscall_handler(rdram, ctx, 0x800861E0);
    return;
    // 0x800861E4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808032CC_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808032CC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808032D0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808032D4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808032D8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808032DC: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x808032E0: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x808032E4: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x808032E8: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x808032EC: jal         0x80106790
    // 0x808032F0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808032F0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x808032F4: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x808032F8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x808032FC: addiu       $a2, $a2, 0x7DB0
    ctx->r6 = ADD32(ctx->r6, 0X7DB0);
    // 0x80803300: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803304: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80803308: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8080330C: jal         0x80087CB8
    // 0x80803310: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    _gcnewoption_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80803310: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_1:
    // 0x80803314: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803318: jal         0x80100094
    // 0x8080331C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x8080331C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80803320: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80803324: jal         0x80087DB8
    // 0x80803328: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _gcnewoption_entrypoint_36(rdram, ctx);
        goto after_3;
    // 0x80803328: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x8080332C: bgtzl       $s0, L_8080333C
    if (SIGNED(ctx->r16) > 0) {
        // 0x80803330: lw          $v0, 0x2C($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X2C);
            goto L_8080333C;
    }
    goto skip_0;
    // 0x80803330: lw          $v0, 0x2C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X2C);
    skip_0:
    // 0x80803334: addiu       $s0, $zero, 0x5
    ctx->r16 = ADD32(0, 0X5);
    // 0x80803338: lw          $v0, 0x2C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X2C);
L_8080333C:
    // 0x8080333C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80803340: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80803344: beq         $at, $zero, L_80803354
    if (ctx->r1 == 0) {
        // 0x80803348: nop
    
            goto L_80803354;
    }
    // 0x80803348: nop

    // 0x8080334C: b           L_80803354
    // 0x80803350: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_80803354;
    // 0x80803350: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80803354:
    // 0x80803354: jal         0x80087CD8
    // 0x80803358: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    _gcnewoption_entrypoint_8(rdram, ctx);
        goto after_4;
    // 0x80803358: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_4:
    // 0x8080335C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80803360: jal         0x80087CE0
    // 0x80803364: lw          $a1, 0x2C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X2C);
    _gcnewoption_entrypoint_9(rdram, ctx);
        goto after_5;
    // 0x80803364: lw          $a1, 0x2C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X2C);
    after_5:
    // 0x80803368: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8080336C: jal         0x80087CE8
    // 0x80803370: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _gcnewoption_entrypoint_10(rdram, ctx);
        goto after_6;
    // 0x80803370: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x80803374: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80803378: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080337C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803380: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80803384: jal         0x80100094
    // 0x80803388: sw          $t6, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->r14;
    func_80100094(rdram, ctx);
        goto after_7;
    // 0x80803388: sw          $t6, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->r14;
    after_7:
    // 0x8080338C: lw          $t7, 0x2C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X2C);
    // 0x80803390: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80803394: blez        $t7, L_808033C0
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80803398: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_808033C0;
    }
    // 0x80803398: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_8080339C:
    // 0x8080339C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808033A0: jal         0x80087D90
    // 0x808033A4: lh          $a2, 0x4($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X4);
    _gcnewoption_entrypoint_31(rdram, ctx);
        goto after_8;
    // 0x808033A4: lh          $a2, 0x4($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X4);
    after_8:
    // 0x808033A8: lw          $t8, 0x2C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X2C);
    // 0x808033AC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808033B0: addiu       $s1, $s1, 0x6
    ctx->r17 = ADD32(ctx->r17, 0X6);
    // 0x808033B4: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x808033B8: bnel        $at, $zero, L_8080339C
    if (ctx->r1 != 0) {
        // 0x808033BC: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8080339C;
    }
    goto skip_1;
    // 0x808033BC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_1:
L_808033C0:
    // 0x808033C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(804, 0X7CCC) << 16);
    // 0x808033C4: lwc1        $f4, 0x7CCC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(804, 0X7CCC));
    // 0x808033C8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808033CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808033D0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808033D4: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    // 0x808033D8: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    // 0x808033DC: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x808033E0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x808033E4: jal         0x80087DD8
    // 0x808033E8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    _gcnewoption_entrypoint_40(rdram, ctx);
        goto after_9;
    // 0x808033E8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_9:
    // 0x808033EC: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x808033F0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808033F4: jal         0x80087DE8
    // 0x808033F8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    _gcnewoption_entrypoint_42(rdram, ctx);
        goto after_10;
    // 0x808033F8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_10:
    // 0x808033FC: jal         0x80087CF0
    // 0x80803400: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    _gcnewoption_entrypoint_11(rdram, ctx);
        goto after_11;
    // 0x80803400: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_11:
    // 0x80803404: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80803408: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8080340C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80803410: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80803414: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80803418: jr          $ra
    // 0x8080341C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8080341C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _chfactorycrusher_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086210: syscall     290
    recomp_syscall_handler(rdram, ctx, 0x80086210);
    return;
    // 0x80086214: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80092018(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092018: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8009201C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80092020: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80092024: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80092028: lw          $s0, 0x50($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X50);
    // 0x8009202C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80092030: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80092034: lbu         $t6, 0xC4($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XC4);
    // 0x80092038: beql        $t6, $zero, L_8009204C
    if (ctx->r14 == 0) {
        // 0x8009203C: lwc1        $f0, 0x28($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X28);
            goto L_8009204C;
    }
    goto skip_0;
    // 0x8009203C: lwc1        $f0, 0x28($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X28);
    skip_0:
    // 0x80092040: b           L_8009204C
    // 0x80092044: lwc1        $f0, 0xC8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC8);
        goto L_8009204C;
    // 0x80092044: lwc1        $f0, 0xC8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x80092048: lwc1        $f0, 0x28($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X28);
L_8009204C:
    // 0x8009204C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80092050: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    // 0x80092054: jal         0x800EFA4C
    // 0x80092058: lw          $a3, 0x24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X24);
    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x80092058: lw          $a3, 0x24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X24);
    after_0:
    // 0x8009205C: lw          $s0, 0x50($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X50);
    // 0x80092060: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80092064: addiu       $a1, $s0, 0x2C
    ctx->r5 = ADD32(ctx->r16, 0X2C);
    // 0x80092068: jal         0x800EE780
    // 0x8009206C: addiu       $a2, $s0, 0x44
    ctx->r6 = ADD32(ctx->r16, 0X44);
    func_800EE780(rdram, ctx);
        goto after_1;
    // 0x8009206C: addiu       $a2, $s0, 0x44
    ctx->r6 = ADD32(ctx->r16, 0X44);
    after_1:
    // 0x80092070: jal         0x80019CD4
    // 0x80092074: nop

    func_80019CD4(rdram, ctx);
        goto after_2;
    // 0x80092074: nop

    after_2:
    // 0x80092078: lw          $s0, 0x50($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X50);
    // 0x8009207C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80092080: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // 0x80092084: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    // 0x80092088: jal         0x80019750
    // 0x8009208C: lw          $a2, 0x1C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C);
    func_80019750(rdram, ctx);
        goto after_3;
    // 0x8009208C: lw          $a2, 0x1C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C);
    after_3:
    // 0x80092090: lw          $s0, 0x50($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X50);
    // 0x80092094: lbu         $t7, 0xC4($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XC4);
    // 0x80092098: beq         $t7, $zero, L_800920AC
    if (ctx->r15 == 0) {
        // 0x8009209C: nop
    
            goto L_800920AC;
    }
    // 0x8009209C: nop

    // 0x800920A0: jal         0x80018F50
    // 0x800920A4: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    mlMtxRotPitch(rdram, ctx);
        goto after_4;
    // 0x800920A4: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    after_4:
    // 0x800920A8: lw          $s0, 0x50($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X50);
L_800920AC:
    // 0x800920AC: jal         0x80018AD0
    // 0x800920B0: addiu       $a0, $s0, 0xCC
    ctx->r4 = ADD32(ctx->r16, 0XCC);
    mlMtxGet(rdram, ctx);
        goto after_5;
    // 0x800920B0: addiu       $a0, $s0, 0xCC
    ctx->r4 = ADD32(ctx->r16, 0XCC);
    after_5:
    // 0x800920B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800920B8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800920BC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800920C0: jr          $ra
    // 0x800920C4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800920C4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8080183C_chfactoryrobot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080183C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801840: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801844: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80801848: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080184C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80801850: jal         0x80100094
    // 0x80801854: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801854: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801858: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1140, 0X2ACC) << 16);
    // 0x8080185C: addiu       $t7, $t7, 0x2ACC
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1140, 0X2ACC));
    // 0x80801860: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80801864: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x80801868: addiu       $t6, $sp, 0x2C
    ctx->r14 = ADD32(ctx->r29, 0X2C);
    // 0x8080186C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80801870: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80801874: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801878: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080187C: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80801880: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
L_80801884:
    // 0x80801884: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80801888: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8080188C: bne         $v1, $a1, L_80801884
    if (ctx->r3 != ctx->r5) {
        // 0x80801890: sb          $zero, 0x7($a0)
        MEM_B(0X7, ctx->r4) = 0;
            goto L_80801884;
    }
    // 0x80801890: sb          $zero, 0x7($a0)
    MEM_B(0X7, ctx->r4) = 0;
    // 0x80801894: jal         0x80802398
    // 0x80801898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802398_chfactoryrobot(rdram, ctx);
        goto after_1;
    // 0x80801898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080189C: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808018A0: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808018A4: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808018A8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808018AC: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x808018B0: lwc1        $f16, 0x38($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808018B4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x808018B8: jal         0x800C8A98
    // 0x808018BC: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    func_800C8A98(rdram, ctx);
        goto after_2;
    // 0x808018BC: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x808018C0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1140, 0X2890) << 16);
    // 0x808018C4: sw          $v0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r2;
    // 0x808018C8: addiu       $a1, $a1, 0x2890
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1140, 0X2890));
    // 0x808018CC: jal         0x800C8E84
    // 0x808018D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800C8E84(rdram, ctx);
        goto after_3;
    // 0x808018D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x808018D4: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x808018D8: jal         0x800C8CB8
    // 0x808018DC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C8CB8(rdram, ctx);
        goto after_4;
    // 0x808018DC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_4:
    // 0x808018E0: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x808018E4: jal         0x800C8F64
    // 0x808018E8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800C8F64(rdram, ctx);
        goto after_5;
    // 0x808018E8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x808018EC: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x808018F0: jal         0x800C8D4C
    // 0x808018F4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800C8D4C(rdram, ctx);
        goto after_6;
    // 0x808018F4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_6:
    // 0x808018F8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808018FC: lwc1        $f6, 0x20($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80801900: lw          $a0, 0x14($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14);
    // 0x80801904: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801908: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8080190C: nop

    // 0x80801910: bc1f        L_8080191C
    if (!c1cs) {
        // 0x80801914: nop
    
            goto L_8080191C;
    }
    // 0x80801914: nop

    // 0x80801918: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8080191C:
    // 0x8080191C: jal         0x800C8FE0
    // 0x80801920: nop

    func_800C8FE0(rdram, ctx);
        goto after_7;
    // 0x80801920: nop

    after_7:
    // 0x80801924: lhu         $t1, 0x72($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X72);
    // 0x80801928: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080192C: srl         $t2, $t1, 10
    ctx->r10 = S32(U32(ctx->r9) >> 10);
    // 0x80801930: beql        $t2, $at, L_80801944
    if (ctx->r10 == ctx->r1) {
        // 0x80801934: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801944;
    }
    goto skip_0;
    // 0x80801934: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80801938: jal         0x80089F60
    // 0x8080193C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_1(rdram, ctx);
        goto after_8;
    // 0x8080193C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80801940: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801944:
    // 0x80801944: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801948: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080194C: jr          $ra
    // 0x80801950: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80801950: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80800CC0_chquicksandbaddy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800CC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800CCC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800CD0: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x80800CD4: lui         $a2, 0xC3FA
    ctx->r6 = S32(0XC3FA << 16);
    // 0x80800CD8: jal         0x800C6920
    // 0x80800CDC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800C6920(rdram, ctx);
        goto after_0;
    // 0x80800CDC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80800CE0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800CE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800CE8: lwc1        $f4, 0x54($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X54);
    // 0x80800CEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800CF0: add.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80800CF4: jr          $ra
    // 0x80800CF8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x80800CF8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void boot_huft_build(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000E1C: beq         $a1, $zero, L_80001298
    if (ctx->r5 == 0) {
        // 0x80000E20: mtc1        $s0, $f2
        ctx->f2.u32l = ctx->r16;
            goto L_80001298;
    }
    // 0x80000E20: mtc1        $s0, $f2
    ctx->f2.u32l = ctx->r16;
    // 0x80000E24: mtc1        $s1, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r17;
    // 0x80000E28: mtc1        $s2, $f4
    ctx->f4.u32l = ctx->r18;
    // 0x80000E2C: mtc1        $s3, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r19;
    // 0x80000E30: mtc1        $s4, $f6
    ctx->f6.u32l = ctx->r20;
    // 0x80000E34: mtc1        $s5, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r21;
    // 0x80000E38: mtc1        $s6, $f8
    ctx->f8.u32l = ctx->r22;
    // 0x80000E3C: mtc1        $s7, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r23;
    // 0x80000E40: mtc1        $fp, $f10
    ctx->f10.u32l = ctx->r30;
    // 0x80000E44: mtc1        $gp, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r28;
    // 0x80000E48: mfc1        $s3, $f19
    ctx->r19 = (int32_t)ctx->f_odd[(19 - 1) * 2];
    // 0x80000E4C: sd          $zero, 0x0($sp)
    SD(0, 0X0, ctx->r29);
    // 0x80000E50: sd          $zero, 0x8($sp)
    SD(0, 0X8, ctx->r29);
    // 0x80000E54: sd          $zero, 0x10($sp)
    SD(0, 0X10, ctx->r29);
    // 0x80000E58: sd          $zero, 0x18($sp)
    SD(0, 0X18, ctx->r29);
    // 0x80000E5C: sd          $zero, 0x20($sp)
    SD(0, 0X20, ctx->r29);
    // 0x80000E60: sd          $zero, 0x28($sp)
    SD(0, 0X28, ctx->r29);
    // 0x80000E64: sd          $zero, 0x30($sp)
    SD(0, 0X30, ctx->r29);
    // 0x80000E68: sd          $zero, 0x38($sp)
    SD(0, 0X38, ctx->r29);
    // 0x80000E6C: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x80000E70: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x80000E74: or          $t1, $a1, $zero
    ctx->r9 = ctx->r5 | 0;
L_80000E78:
    // 0x80000E78: lw          $s7, 0x0($t0)
    ctx->r23 = MEM_W(ctx->r8, 0X0);
    // 0x80000E7C: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80000E80: sll         $s7, $s7, 2
    ctx->r23 = S32(ctx->r23 << 2);
    // 0x80000E84: addu        $s7, $s7, $sp
    ctx->r23 = ADD32(ctx->r23, ctx->r29);
    // 0x80000E88: lw          $at, 0x0($s7)
    ctx->r1 = MEM_W(ctx->r23, 0X0);
    // 0x80000E8C: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x80000E90: addiu       $at, $at, 0x1
    ctx->r1 = ADD32(ctx->r1, 0X1);
    // 0x80000E94: bne         $t1, $zero, L_80000E78
    if (ctx->r9 != 0) {
        // 0x80000E98: sw          $at, 0x0($s7)
        MEM_W(0X0, ctx->r23) = ctx->r1;
            goto L_80000E78;
    }
    // 0x80000E98: sw          $at, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r1;
    // 0x80000E9C: lw          $s7, 0x0($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X0);
    // 0x80000EA0: beq         $s7, $a1, L_800012A0
    if (ctx->r23 == ctx->r5) {
        // 0x80000EA4: lw          $t2, 0x0($t9)
        ctx->r10 = MEM_W(ctx->r25, 0X0);
            goto L_800012A0;
    }
    // 0x80000EA4: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x80000EA8: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80000EAC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80000EB0: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
L_80000EB4:
    // 0x80000EB4: addu        $s7, $t3, $sp
    ctx->r23 = ADD32(ctx->r11, ctx->r29);
    // 0x80000EB8: lw          $s7, 0x0($s7)
    ctx->r23 = MEM_W(ctx->r23, 0X0);
    // 0x80000EBC: bne         $s7, $zero, L_80000ECC
    if (ctx->r23 != 0) {
        // 0x80000EC0: nop
    
            goto L_80000ECC;
    }
    // 0x80000EC0: nop

    // 0x80000EC4: bne         $t3, $at, L_80000EB4
    if (ctx->r11 != ctx->r1) {
        // 0x80000EC8: addiu       $t3, $t3, 0x4
        ctx->r11 = ADD32(ctx->r11, 0X4);
            goto L_80000EB4;
    }
    // 0x80000EC8: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
L_80000ECC:
    // 0x80000ECC: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80000ED0: beq         $at, $zero, L_80000EDC
    if (ctx->r1 == 0) {
        // 0x80000ED4: or          $t4, $t3, $zero
        ctx->r12 = ctx->r11 | 0;
            goto L_80000EDC;
    }
    // 0x80000ED4: or          $t4, $t3, $zero
    ctx->r12 = ctx->r11 | 0;
    // 0x80000ED8: or          $t2, $t3, $zero
    ctx->r10 = ctx->r11 | 0;
L_80000EDC:
    // 0x80000EDC: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
L_80000EE0:
    // 0x80000EE0: addu        $s7, $t1, $sp
    ctx->r23 = ADD32(ctx->r9, ctx->r29);
    // 0x80000EE4: lw          $s7, 0x0($s7)
    ctx->r23 = MEM_W(ctx->r23, 0X0);
    // 0x80000EE8: bne         $s7, $zero, L_80000EFC
    if (ctx->r23 != 0) {
        // 0x80000EEC: nop
    
            goto L_80000EFC;
    }
    // 0x80000EEC: nop

    // 0x80000EF0: addiu       $t1, $t1, -0x4
    ctx->r9 = ADD32(ctx->r9, -0X4);
    // 0x80000EF4: bne         $t1, $zero, L_80000EE0
    if (ctx->r9 != 0) {
        // 0x80000EF8: nop
    
            goto L_80000EE0;
    }
    // 0x80000EF8: nop

L_80000EFC:
    // 0x80000EFC: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80000F00: beq         $at, $zero, L_80000F0C
    if (ctx->r1 == 0) {
        // 0x80000F04: or          $t5, $t1, $zero
        ctx->r13 = ctx->r9 | 0;
            goto L_80000F0C;
    }
    // 0x80000F04: or          $t5, $t1, $zero
    ctx->r13 = ctx->r9 | 0;
    // 0x80000F08: or          $t2, $t1, $zero
    ctx->r10 = ctx->r9 | 0;
L_80000F0C:
    // 0x80000F0C: srl         $t2, $t2, 2
    ctx->r10 = S32(U32(ctx->r10) >> 2);
    // 0x80000F10: sw          $t2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r10;
    // 0x80000F14: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80000F18: srl         $s7, $t3, 2
    ctx->r23 = S32(U32(ctx->r11) >> 2);
    // 0x80000F1C: slt         $at, $t3, $t1
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80000F20: beq         $at, $zero, L_80000F44
    if (ctx->r1 == 0) {
        // 0x80000F24: sllv        $t9, $t9, $s7
        ctx->r25 = S32(ctx->r25 << (ctx->r23 & 31));
            goto L_80000F44;
    }
    // 0x80000F24: sllv        $t9, $t9, $s7
    ctx->r25 = S32(ctx->r25 << (ctx->r23 & 31));
L_80000F28:
    // 0x80000F28: addu        $s7, $t3, $sp
    ctx->r23 = ADD32(ctx->r11, ctx->r29);
    // 0x80000F2C: lw          $s7, 0x0($s7)
    ctx->r23 = MEM_W(ctx->r23, 0X0);
    // 0x80000F30: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // 0x80000F34: subu        $t9, $t9, $s7
    ctx->r25 = SUB32(ctx->r25, ctx->r23);
    // 0x80000F38: slt         $at, $t3, $t1
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80000F3C: bne         $at, $zero, L_80000F28
    if (ctx->r1 != 0) {
        // 0x80000F40: sll         $t9, $t9, 1
        ctx->r25 = S32(ctx->r25 << 1);
            goto L_80000F28;
    }
    // 0x80000F40: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
L_80000F44:
    // 0x80000F44: addu        $s7, $t1, $sp
    ctx->r23 = ADD32(ctx->r9, ctx->r29);
    // 0x80000F48: lw          $at, 0x0($s7)
    ctx->r1 = MEM_W(ctx->r23, 0X0);
    // 0x80000F4C: sw          $t9, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r25;
    // 0x80000F50: subu        $t9, $t9, $at
    ctx->r25 = SUB32(ctx->r25, ctx->r1);
    // 0x80000F54: sw          $zero, 0x508($sp)
    MEM_W(0X508, ctx->r29) = 0;
    // 0x80000F58: addiu       $t3, $zero, 0x0
    ctx->r11 = ADD32(0, 0X0);
    // 0x80000F5C: addiu       $t0, $sp, 0x4
    ctx->r8 = ADD32(ctx->r29, 0X4);
    // 0x80000F60: addiu       $t1, $t1, -0x4
    ctx->r9 = ADD32(ctx->r9, -0X4);
    // 0x80000F64: beq         $t1, $zero, L_80000F88
    if (ctx->r9 == 0) {
        // 0x80000F68: addiu       $t6, $sp, 0x50C
        ctx->r14 = ADD32(ctx->r29, 0X50C);
            goto L_80000F88;
    }
    // 0x80000F68: addiu       $t6, $sp, 0x50C
    ctx->r14 = ADD32(ctx->r29, 0X50C);
L_80000F6C:
    // 0x80000F6C: lw          $s7, 0x0($t0)
    ctx->r23 = MEM_W(ctx->r8, 0X0);
    // 0x80000F70: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80000F74: addu        $t3, $t3, $s7
    ctx->r11 = ADD32(ctx->r11, ctx->r23);
    // 0x80000F78: sw          $t3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r11;
    // 0x80000F7C: addiu       $t1, $t1, -0x4
    ctx->r9 = ADD32(ctx->r9, -0X4);
    // 0x80000F80: bne         $t1, $zero, L_80000F6C
    if (ctx->r9 != 0) {
        // 0x80000F84: addiu       $t6, $t6, 0x4
        ctx->r14 = ADD32(ctx->r14, 0X4);
            goto L_80000F6C;
    }
    // 0x80000F84: addiu       $t6, $t6, 0x4
    ctx->r14 = ADD32(ctx->r14, 0X4);
L_80000F88:
    // 0x80000F88: srl         $t5, $t5, 2
    ctx->r13 = S32(U32(ctx->r13) >> 2);
    // 0x80000F8C: srl         $t4, $t4, 2
    ctx->r12 = S32(U32(ctx->r12) >> 2);
    // 0x80000F90: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x80000F94: addiu       $t1, $zero, 0x0
    ctx->r9 = ADD32(0, 0X0);
    // 0x80000F98: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
L_80000F9C:
    // 0x80000F9C: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80000FA0: beq         $t3, $zero, L_80000FC4
    if (ctx->r11 == 0) {
        // 0x80000FA4: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_80000FC4;
    }
    // 0x80000FA4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80000FA8: addu        $t3, $t3, $sp
    ctx->r11 = ADD32(ctx->r11, ctx->r29);
    // 0x80000FAC: lw          $s7, 0x504($t3)
    ctx->r23 = MEM_W(ctx->r11, 0X504);
    // 0x80000FB0: sll         $fp, $s7, 2
    ctx->r30 = S32(ctx->r23 << 2);
    // 0x80000FB4: addiu       $at, $s7, 0x1
    ctx->r1 = ADD32(ctx->r23, 0X1);
    // 0x80000FB8: sw          $at, 0x504($t3)
    MEM_W(0X504, ctx->r11) = ctx->r1;
    // 0x80000FBC: addu        $fp, $fp, $sp
    ctx->r30 = ADD32(ctx->r30, ctx->r29);
    // 0x80000FC0: sw          $t1, 0x84($fp)
    MEM_W(0X84, ctx->r30) = ctx->r9;
L_80000FC4:
    // 0x80000FC4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80000FC8: slt         $at, $t1, $a1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80000FCC: bnel        $at, $zero, L_80000F9C
    if (ctx->r1 != 0) {
        // 0x80000FD0: lw          $t3, 0x0($t0)
        ctx->r11 = MEM_W(ctx->r8, 0X0);
            goto L_80000F9C;
    }
    goto skip_0;
    // 0x80000FD0: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    skip_0:
    // 0x80000FD4: sw          $zero, 0x504($sp)
    MEM_W(0X504, ctx->r29) = 0;
    // 0x80000FD8: addiu       $t1, $zero, 0x0
    ctx->r9 = ADD32(0, 0X0);
    // 0x80000FDC: addiu       $t0, $sp, 0x84
    ctx->r8 = ADD32(ctx->r29, 0X84);
    // 0x80000FE0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80000FE4: negu        $s1, $t2
    ctx->r17 = SUB32(0, ctx->r10);
    // 0x80000FE8: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80000FEC: j           L_80001224
    // 0x80000FF0: addiu       $s0, $zero, 0x0
    ctx->r16 = ADD32(0, 0X0);
        goto L_80001224;
    // 0x80000FF0: addiu       $s0, $zero, 0x0
    ctx->r16 = ADD32(0, 0X0);
    // 0x80000FF4: addu        $s1, $s1, $t2
    ctx->r17 = ADD32(ctx->r17, ctx->r10);
L_80000FF8:
    // 0x80000FF8: subu        $s0, $t5, $s1
    ctx->r16 = SUB32(ctx->r13, ctx->r17);
    // 0x80000FFC: slt         $at, $t2, $s0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80001000: beq         $at, $zero, L_8000100C
    if (ctx->r1 == 0) {
        // 0x80001004: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8000100C;
    }
    // 0x80001004: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80001008: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
L_8000100C:
    // 0x8000100C: subu        $t3, $t4, $s1
    ctx->r11 = SUB32(ctx->r12, ctx->r17);
    // 0x80001010: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80001014: sllv        $s2, $s2, $t3
    ctx->r18 = S32(ctx->r18 << (ctx->r11 & 31));
    // 0x80001018: addiu       $s7, $a0, 0x1
    ctx->r23 = ADD32(ctx->r4, 0X1);
    // 0x8000101C: slt         $at, $s7, $s2
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80001020: beq         $at, $zero, L_8000106C
    if (ctx->r1 == 0) {
        // 0x80001024: nop
    
            goto L_8000106C;
    }
    // 0x80001024: nop

    // 0x80001028: subu        $s2, $s2, $s7
    ctx->r18 = SUB32(ctx->r18, ctx->r23);
    // 0x8000102C: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x80001030: addu        $t6, $t6, $sp
    ctx->r14 = ADD32(ctx->r14, ctx->r29);
    // 0x80001034: addiu       $t6, $t6, 0x0
    ctx->r14 = ADD32(ctx->r14, 0X0);
    // 0x80001038: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x8000103C: slt         $at, $t3, $s0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80001040: beq         $at, $zero, L_8000106C
    if (ctx->r1 == 0) {
        // 0x80001044: nop
    
            goto L_8000106C;
    }
    // 0x80001044: nop

L_80001048:
    // 0x80001048: lw          $s7, 0x4($t6)
    ctx->r23 = MEM_W(ctx->r14, 0X4);
    // 0x8000104C: sll         $s2, $s2, 1
    ctx->r18 = S32(ctx->r18 << 1);
    // 0x80001050: slt         $at, $s7, $s2
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80001054: beq         $at, $zero, L_8000106C
    if (ctx->r1 == 0) {
        // 0x80001058: addiu       $t6, $t6, 0x4
        ctx->r14 = ADD32(ctx->r14, 0X4);
            goto L_8000106C;
    }
    // 0x80001058: addiu       $t6, $t6, 0x4
    ctx->r14 = ADD32(ctx->r14, 0X4);
    // 0x8000105C: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x80001060: slt         $at, $t3, $s0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80001064: bne         $at, $zero, L_80001048
    if (ctx->r1 != 0) {
        // 0x80001068: subu        $s2, $s2, $s7
        ctx->r18 = SUB32(ctx->r18, ctx->r23);
            goto L_80001048;
    }
    // 0x80001068: subu        $s2, $s2, $s7
    ctx->r18 = SUB32(ctx->r18, ctx->r23);
L_8000106C:
    // 0x8000106C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80001070: sllv        $s0, $s0, $t3
    ctx->r16 = S32(ctx->r16 << (ctx->r11 & 31));
    // 0x80001074: sll         $t6, $s3, 2
    ctx->r14 = S32(ctx->r19 << 2);
    // 0x80001078: addu        $t6, $t6, $s6
    ctx->r14 = ADD32(ctx->r14, ctx->r22);
    // 0x8000107C: addiu       $s7, $s3, 0x1
    ctx->r23 = ADD32(ctx->r19, 0X1);
    // 0x80001080: sh          $s7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r23;
    // 0x80001084: addiu       $t8, $t6, 0x2
    ctx->r24 = ADD32(ctx->r14, 0X2);
    // 0x80001088: sh          $zero, 0x0($t8)
    MEM_H(0X0, ctx->r24) = 0;
    // 0x8000108C: addiu       $t6, $t6, 0x4
    ctx->r14 = ADD32(ctx->r14, 0X4);
    // 0x80001090: sll         $s7, $v0, 2
    ctx->r23 = S32(ctx->r2 << 2);
    // 0x80001094: addu        $s7, $s7, $sp
    ctx->r23 = ADD32(ctx->r23, ctx->r29);
    // 0x80001098: beq         $v0, $zero, L_800010E4
    if (ctx->r2 == 0) {
        // 0x8000109C: sw          $t6, 0x44($s7)
        MEM_W(0X44, ctx->r23) = ctx->r14;
            goto L_800010E4;
    }
    // 0x8000109C: sw          $t6, 0x44($s7)
    MEM_W(0X44, ctx->r23) = ctx->r14;
    // 0x800010A0: sll         $s7, $v0, 2
    ctx->r23 = S32(ctx->r2 << 2);
    // 0x800010A4: addu        $s7, $s7, $sp
    ctx->r23 = ADD32(ctx->r23, ctx->r29);
    // 0x800010A8: sw          $t1, 0x504($s7)
    MEM_W(0X504, ctx->r23) = ctx->r9;
    // 0x800010AC: or          $s5, $t2, $zero
    ctx->r21 = ctx->r10 | 0;
    // 0x800010B0: addiu       $s4, $t3, 0x10
    ctx->r20 = ADD32(ctx->r11, 0X10);
    // 0x800010B4: addiu       $gp, $s3, 0x1
    ctx->r28 = ADD32(ctx->r19, 0X1);
    // 0x800010B8: subu        $t3, $s1, $t2
    ctx->r11 = SUB32(ctx->r17, ctx->r10);
    // 0x800010BC: srlv        $t3, $t1, $t3
    ctx->r11 = S32(U32(ctx->r9) >> (ctx->r11 & 31));
    // 0x800010C0: addiu       $s7, $v0, -0x1
    ctx->r23 = ADD32(ctx->r2, -0X1);
    // 0x800010C4: sll         $s7, $s7, 2
    ctx->r23 = S32(ctx->r23 << 2);
    // 0x800010C8: addu        $s7, $s7, $sp
    ctx->r23 = ADD32(ctx->r23, ctx->r29);
    // 0x800010CC: lw          $s7, 0x44($s7)
    ctx->r23 = MEM_W(ctx->r23, 0X44);
    // 0x800010D0: sll         $at, $t3, 2
    ctx->r1 = S32(ctx->r11 << 2);
    // 0x800010D4: addu        $s7, $s7, $at
    ctx->r23 = ADD32(ctx->r23, ctx->r1);
    // 0x800010D8: sb          $s4, 0x0($s7)
    MEM_B(0X0, ctx->r23) = ctx->r20;
    // 0x800010DC: sb          $s5, 0x1($s7)
    MEM_B(0X1, ctx->r23) = ctx->r21;
    // 0x800010E0: sh          $gp, 0x2($s7)
    MEM_H(0X2, ctx->r23) = ctx->r28;
L_800010E4:
    // 0x800010E4: addu        $s3, $s3, $s0
    ctx->r19 = ADD32(ctx->r19, ctx->r16);
    // 0x800010E8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_800010EC:
    // 0x800010EC: addu        $s7, $s1, $t2
    ctx->r23 = ADD32(ctx->r17, ctx->r10);
L_800010F0:
    // 0x800010F0: slt         $at, $s7, $t4
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800010F4: bnel        $at, $zero, L_80000FF8
    if (ctx->r1 != 0) {
        // 0x800010F8: addu        $s1, $s1, $t2
        ctx->r17 = ADD32(ctx->r17, ctx->r10);
            goto L_80000FF8;
    }
    goto skip_1;
    // 0x800010F8: addu        $s1, $s1, $t2
    ctx->r17 = ADD32(ctx->r17, ctx->r10);
    skip_1:
    // 0x800010FC: subu        $s5, $t4, $s1
    ctx->r21 = SUB32(ctx->r12, ctx->r17);
    // 0x80001100: sll         $s7, $a1, 2
    ctx->r23 = S32(ctx->r5 << 2);
    // 0x80001104: addu        $s7, $s7, $sp
    ctx->r23 = ADD32(ctx->r23, ctx->r29);
    // 0x80001108: addiu       $s7, $s7, 0x84
    ctx->r23 = ADD32(ctx->r23, 0X84);
    // 0x8000110C: slt         $at, $t0, $s7
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r23) ? 1 : 0;
    // 0x80001110: bne         $at, $zero, L_80001120
    if (ctx->r1 != 0) {
        // 0x80001114: addiu       $s4, $zero, 0x63
        ctx->r20 = ADD32(0, 0X63);
            goto L_80001120;
    }
    // 0x80001114: addiu       $s4, $zero, 0x63
    ctx->r20 = ADD32(0, 0X63);
    // 0x80001118: j           L_8000116C
    // 0x8000111C: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
        goto L_8000116C;
    // 0x8000111C: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_80001120:
    // 0x80001120: lw          $s7, 0x0($t0)
    ctx->r23 = MEM_W(ctx->r8, 0X0);
    // 0x80001124: slt         $at, $s7, $a2
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80001128: beq         $at, $zero, L_8000114C
    if (ctx->r1 == 0) {
        // 0x8000112C: nop
    
            goto L_8000114C;
    }
    // 0x8000112C: nop

    // 0x80001130: or          $gp, $s7, $zero
    ctx->r28 = ctx->r23 | 0;
    // 0x80001134: slti        $at, $s7, 0x100
    ctx->r1 = SIGNED(ctx->r23) < 0X100 ? 1 : 0;
    // 0x80001138: bnel        $at, $zero, L_80001144
    if (ctx->r1 != 0) {
        // 0x8000113C: addiu       $s4, $zero, 0x10
        ctx->r20 = ADD32(0, 0X10);
            goto L_80001144;
    }
    goto skip_2;
    // 0x8000113C: addiu       $s4, $zero, 0x10
    ctx->r20 = ADD32(0, 0X10);
    skip_2:
    // 0x80001140: addiu       $s4, $zero, 0xF
    ctx->r20 = ADD32(0, 0XF);
L_80001144:
    // 0x80001144: j           L_80001168
    // 0x80001148: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
        goto L_80001168;
    // 0x80001148: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
L_8000114C:
    // 0x8000114C: subu        $s7, $s7, $a2
    ctx->r23 = SUB32(ctx->r23, ctx->r6);
    // 0x80001150: addu        $s4, $s7, $t7
    ctx->r20 = ADD32(ctx->r23, ctx->r15);
    // 0x80001154: lbu         $s4, 0x0($s4)
    ctx->r20 = MEM_BU(ctx->r20, 0X0);
    // 0x80001158: sll         $s7, $s7, 1
    ctx->r23 = S32(ctx->r23 << 1);
    // 0x8000115C: addu        $s7, $s7, $a3
    ctx->r23 = ADD32(ctx->r23, ctx->r7);
    // 0x80001160: lhu         $gp, 0x0($s7)
    ctx->r28 = MEM_HU(ctx->r23, 0X0);
    // 0x80001164: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
L_80001168:
    // 0x80001168: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8000116C:
    // 0x8000116C: subu        $s7, $t4, $s1
    ctx->r23 = SUB32(ctx->r12, ctx->r17);
    // 0x80001170: sllv        $s2, $s2, $s7
    ctx->r18 = S32(ctx->r18 << (ctx->r23 & 31));
    // 0x80001174: srlv        $t3, $t1, $s1
    ctx->r11 = S32(U32(ctx->r9) >> (ctx->r17 & 31));
    // 0x80001178: slt         $at, $t3, $s0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8000117C: beq         $at, $zero, L_800011C0
    if (ctx->r1 == 0) {
        // 0x80001180: sll         $s7, $s4, 24
        ctx->r23 = S32(ctx->r20 << 24);
            goto L_800011C0;
    }
    // 0x80001180: sll         $s7, $s4, 24
    ctx->r23 = S32(ctx->r20 << 24);
    // 0x80001184: andi        $s5, $s5, 0xFF
    ctx->r21 = ctx->r21 & 0XFF;
    // 0x80001188: sll         $s5, $s5, 16
    ctx->r21 = S32(ctx->r21 << 16);
    // 0x8000118C: or          $s7, $s7, $s5
    ctx->r23 = ctx->r23 | ctx->r21;
    // 0x80001190: andi        $s5, $gp, 0xFFFF
    ctx->r21 = ctx->r28 & 0XFFFF;
    // 0x80001194: or          $s5, $s5, $s7
    ctx->r21 = ctx->r21 | ctx->r23;
    // 0x80001198: sll         $s2, $s2, 2
    ctx->r18 = S32(ctx->r18 << 2);
    // 0x8000119C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800011A0: addu        $t3, $t3, $t6
    ctx->r11 = ADD32(ctx->r11, ctx->r14);
    // 0x800011A4: sll         $s7, $s0, 2
    ctx->r23 = S32(ctx->r16 << 2);
    // 0x800011A8: addu        $s7, $s7, $t6
    ctx->r23 = ADD32(ctx->r23, ctx->r14);
    // 0x800011AC: sw          $s5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r21;
L_800011B0:
    // 0x800011B0: addu        $t3, $t3, $s2
    ctx->r11 = ADD32(ctx->r11, ctx->r18);
    // 0x800011B4: slt         $at, $t3, $s7
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r23) ? 1 : 0;
    // 0x800011B8: bnel        $at, $zero, L_800011B0
    if (ctx->r1 != 0) {
        // 0x800011BC: sw          $s5, 0x0($t3)
        MEM_W(0X0, ctx->r11) = ctx->r21;
            goto L_800011B0;
    }
    goto skip_3;
    // 0x800011BC: sw          $s5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r21;
    skip_3:
L_800011C0:
    // 0x800011C0: addiu       $s7, $t4, -0x1
    ctx->r23 = ADD32(ctx->r12, -0X1);
    // 0x800011C4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800011C8: sllv        $t3, $t3, $s7
    ctx->r11 = S32(ctx->r11 << (ctx->r23 & 31));
    // 0x800011CC: and         $s7, $t1, $t3
    ctx->r23 = ctx->r9 & ctx->r11;
    // 0x800011D0: beq         $s7, $zero, L_800011E8
    if (ctx->r23 == 0) {
        // 0x800011D4: xor         $t1, $t1, $t3
        ctx->r9 = ctx->r9 ^ ctx->r11;
            goto L_800011E8;
    }
    // 0x800011D4: xor         $t1, $t1, $t3
    ctx->r9 = ctx->r9 ^ ctx->r11;
L_800011D8:
    // 0x800011D8: srl         $t3, $t3, 1
    ctx->r11 = S32(U32(ctx->r11) >> 1);
    // 0x800011DC: and         $s7, $t1, $t3
    ctx->r23 = ctx->r9 & ctx->r11;
    // 0x800011E0: bne         $s7, $zero, L_800011D8
    if (ctx->r23 != 0) {
        // 0x800011E4: xor         $t1, $t1, $t3
        ctx->r9 = ctx->r9 ^ ctx->r11;
            goto L_800011D8;
    }
    // 0x800011E4: xor         $t1, $t1, $t3
    ctx->r9 = ctx->r9 ^ ctx->r11;
L_800011E8:
    // 0x800011E8: j           L_800011F8
    // 0x800011EC: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
        goto L_800011F8;
    // 0x800011EC: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x800011F0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_800011F4:
    // 0x800011F4: subu        $s1, $s1, $t2
    ctx->r17 = SUB32(ctx->r17, ctx->r10);
L_800011F8:
    // 0x800011F8: sllv        $s7, $fp, $s1
    ctx->r23 = S32(ctx->r30 << (ctx->r17 & 31));
    // 0x800011FC: addiu       $s7, $s7, -0x1
    ctx->r23 = ADD32(ctx->r23, -0X1);
    // 0x80001200: sll         $at, $v0, 2
    ctx->r1 = S32(ctx->r2 << 2);
    // 0x80001204: addu        $at, $at, $sp
    ctx->r1 = ADD32(ctx->r1, ctx->r29);
    // 0x80001208: lw          $at, 0x504($at)
    ctx->r1 = MEM_W(ctx->r1, 0X504);
    // 0x8000120C: and         $s7, $s7, $t1
    ctx->r23 = ctx->r23 & ctx->r9;
    // 0x80001210: bnel        $s7, $at, L_800011F4
    if (ctx->r23 != ctx->r1) {
        // 0x80001214: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_800011F4;
    }
    goto skip_4;
    // 0x80001214: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    skip_4:
    // 0x80001218: bne         $a0, $zero, L_800010EC
    if (ctx->r4 != 0) {
        // 0x8000121C: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_800010EC;
    }
    // 0x8000121C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
L_80001220:
    // 0x80001220: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
L_80001224:
    // 0x80001224: slt         $at, $t5, $t4
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80001228: bne         $at, $zero, L_80001248
    if (ctx->r1 != 0) {
        // 0x8000122C: sll         $a0, $t4, 2
        ctx->r4 = S32(ctx->r12 << 2);
            goto L_80001248;
    }
    // 0x8000122C: sll         $a0, $t4, 2
    ctx->r4 = S32(ctx->r12 << 2);
    // 0x80001230: addu        $a0, $a0, $sp
    ctx->r4 = ADD32(ctx->r4, ctx->r29);
    // 0x80001234: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80001238: beq         $a0, $zero, L_80001220
    if (ctx->r4 == 0) {
        // 0x8000123C: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_80001220;
    }
    // 0x8000123C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80001240: j           L_800010F0
    // 0x80001244: addu        $s7, $s1, $t2
    ctx->r23 = ADD32(ctx->r17, ctx->r10);
        goto L_800010F0;
    // 0x80001244: addu        $s7, $s1, $t2
    ctx->r23 = ADD32(ctx->r17, ctx->r10);
L_80001248:
    // 0x80001248: bnel        $t9, $zero, L_80001254
    if (ctx->r25 != 0) {
        // 0x8000124C: addiu       $s7, $zero, 0x1
        ctx->r23 = ADD32(0, 0X1);
            goto L_80001254;
    }
    goto skip_5;
    // 0x8000124C: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    skip_5:
    // 0x80001250: addiu       $s7, $zero, 0x0
    ctx->r23 = ADD32(0, 0X0);
L_80001254:
    // 0x80001254: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80001258: bnel        $t5, $at, L_80001264
    if (ctx->r13 != ctx->r1) {
        // 0x8000125C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80001264;
    }
    goto skip_6;
    // 0x8000125C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_6:
    // 0x80001260: addiu       $at, $zero, 0x0
    ctx->r1 = ADD32(0, 0X0);
L_80001264:
    // 0x80001264: and         $v0, $s7, $at
    ctx->r2 = ctx->r23 & ctx->r1;
    // 0x80001268: mtc1        $s3, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r19;
L_8000126C:
    // 0x8000126C: mfc1        $s0, $f2
    ctx->r16 = (int32_t)ctx->f2.u32l;
    // 0x80001270: mfc1        $s1, $f3
    ctx->r17 = (int32_t)ctx->f_odd[(3 - 1) * 2];
    // 0x80001274: mfc1        $s2, $f4
    ctx->r18 = (int32_t)ctx->f4.u32l;
    // 0x80001278: mfc1        $s3, $f5
    ctx->r19 = (int32_t)ctx->f_odd[(5 - 1) * 2];
    // 0x8000127C: mfc1        $s4, $f6
    ctx->r20 = (int32_t)ctx->f6.u32l;
    // 0x80001280: mfc1        $s5, $f7
    ctx->r21 = (int32_t)ctx->f_odd[(7 - 1) * 2];
    // 0x80001284: mfc1        $s6, $f8
    ctx->r22 = (int32_t)ctx->f8.u32l;
    // 0x80001288: mfc1        $s7, $f9
    ctx->r23 = (int32_t)ctx->f_odd[(9 - 1) * 2];
    // 0x8000128C: mfc1        $fp, $f10
    ctx->r30 = (int32_t)ctx->f10.u32l;
    // 0x80001290: jr          $ra
    // 0x80001294: mfc1        $gp, $f11
    ctx->r28 = (int32_t)ctx->f_odd[(11 - 1) * 2];
    return;
    // 0x80001294: mfc1        $gp, $f11
    ctx->r28 = (int32_t)ctx->f_odd[(11 - 1) * 2];
L_80001298:
    // 0x80001298: jr          $ra
    // 0x8000129C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8000129C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800012A0:
    // 0x800012A0: sh          $zero, 0x0($t8)
    MEM_H(0X0, ctx->r24) = 0;
    // 0x800012A4: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x800012A8: j           L_8000126C
    // 0x800012AC: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
        goto L_8000126C;
    // 0x800012AC: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800608_chnicecavemenguard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800608: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080060C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800610: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800614: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800618: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8080061C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800620: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800624: lbu         $t6, 0x5F($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X5F);
    // 0x80800628: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8080062C: addiu       $a1, $s4, 0x4
    ctx->r5 = ADD32(ctx->r20, 0X4);
    // 0x80800630: bne         $t6, $zero, L_80800648
    if (ctx->r14 != 0) {
        // 0x80800634: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800648;
    }
    // 0x80800634: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800638: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1272, 0X9DC) << 16);
    // 0x8080063C: jal         0x800C4350
    // 0x80800640: addiu       $a2, $a2, 0x9DC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1272, 0X9DC));
    func_800C4350(rdram, ctx);
        goto after_0;
    // 0x80800640: addiu       $a2, $a2, 0x9DC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1272, 0X9DC));
    after_0:
    // 0x80800644: sb          $v0, 0x5F($s4)
    MEM_B(0X5F, ctx->r20) = ctx->r2;
L_80800648:
    // 0x80800648: addiu       $t7, $s4, 0x4
    ctx->r15 = ADD32(ctx->r20, 0X4);
    // 0x8080064C: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(1272, 0X9AC) << 16);
    // 0x80800650: addiu       $s1, $s1, 0x9AC
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(1272, 0X9AC));
    // 0x80800654: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x80800658: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080065C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80800660: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
L_80800664:
    // 0x80800664: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800668: jal         0x80101E14
    // 0x8080066C: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    func_80101E14(rdram, ctx);
        goto after_1;
    // 0x8080066C: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    after_1:
    // 0x80800670: beq         $v0, $zero, L_808006E8
    if (ctx->r2 == 0) {
        // 0x80800674: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_808006E8;
    }
    // 0x80800674: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80800678: sll         $s1, $s0, 1
    ctx->r17 = S32(ctx->r16 << 1);
    // 0x8080067C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1272, 0X9CC) << 16);
    // 0x80800680: addu        $a1, $a1, $s1
    ctx->r5 = ADD32(ctx->r5, ctx->r17);
    // 0x80800684: lh          $a1, 0x9CC($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1272, 0X9CC));
    // 0x80800688: jal         0x800C301C
    // 0x8080068C: lbu         $a0, 0x5F($s4)
    ctx->r4 = MEM_BU(ctx->r20, 0X5F);
    func_800C301C(rdram, ctx);
        goto after_2;
    // 0x8080068C: lbu         $a0, 0x5F($s4)
    ctx->r4 = MEM_BU(ctx->r20, 0X5F);
    after_2:
    // 0x80800690: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1272, 0X8AC) << 16);
    // 0x80800694: lwc1        $f12, 0x8AC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1272, 0X8AC));
    // 0x80800698: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1272, 0X8B0) << 16);
    // 0x8080069C: jal         0x800DC178
    // 0x808006A0: lwc1        $f14, 0x8B0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1272, 0X8B0));
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x808006A0: lwc1        $f14, 0x8B0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1272, 0X8B0));
    after_3:
    // 0x808006A4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1272, 0X9BC) << 16);
    // 0x808006A8: addu        $at, $at, $s2
    ctx->r1 = ADD32(ctx->r1, ctx->r18);
    // 0x808006AC: lwc1        $f4, 0x9BC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1272, 0X9BC));
    // 0x808006B0: lbu         $a0, 0x5F($s4)
    ctx->r4 = MEM_BU(ctx->r20, 0X5F);
    // 0x808006B4: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x808006B8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808006BC: jal         0x800C31DC
    // 0x808006C0: nop

    func_800C31DC(rdram, ctx);
        goto after_4;
    // 0x808006C0: nop

    after_4:
    // 0x808006C4: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1272, 0X9D4) << 16);
    // 0x808006C8: addu        $a1, $a1, $s1
    ctx->r5 = ADD32(ctx->r5, ctx->r17);
    // 0x808006CC: lh          $a1, 0x9D4($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1272, 0X9D4));
    // 0x808006D0: jal         0x800C3058
    // 0x808006D4: lbu         $a0, 0x5F($s4)
    ctx->r4 = MEM_BU(ctx->r20, 0X5F);
    func_800C3058(rdram, ctx);
        goto after_5;
    // 0x808006D4: lbu         $a0, 0x5F($s4)
    ctx->r4 = MEM_BU(ctx->r20, 0X5F);
    after_5:
    // 0x808006D8: jal         0x800C3BDC
    // 0x808006DC: lbu         $a0, 0x5F($s4)
    ctx->r4 = MEM_BU(ctx->r20, 0X5F);
    func_800C3BDC(rdram, ctx);
        goto after_6;
    // 0x808006DC: lbu         $a0, 0x5F($s4)
    ctx->r4 = MEM_BU(ctx->r20, 0X5F);
    after_6:
    // 0x808006E0: b           L_808006F4
    // 0x808006E4: nop

        goto L_808006F4;
    // 0x808006E4: nop

L_808006E8:
    // 0x808006E8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808006EC: bne         $s0, $s3, L_80800664
    if (ctx->r16 != ctx->r19) {
        // 0x808006F0: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80800664;
    }
    // 0x808006F0: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_808006F4:
    // 0x808006F4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1272, 0X990) << 16);
    // 0x808006F8: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1272, 0X99C) << 16);
    // 0x808006FC: addiu       $a3, $a3, 0x99C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1272, 0X99C));
    // 0x80800700: addiu       $a2, $a2, 0x990
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1272, 0X990));
    // 0x80800704: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800708: jal         0x80089D28
    // 0x8080070C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x8080070C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_7:
    // 0x80800710: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800714: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800718: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8080071C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800720: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80800724: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800728: jr          $ra
    // 0x8080072C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8080072C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void _idglow_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088CF0: syscall     734
    recomp_syscall_handler(rdram, ctx, 0x80088CF0);
    return;
    // 0x80088CF4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_808025EC_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808025EC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x808025F0: bne         $a1, $at, L_80802610
    if (ctx->r5 != ctx->r1) {
        // 0x808025F4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80802610;
    }
    // 0x808025F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808025F8: lbu         $t9, 0x79($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X79);
    // 0x808025FC: sll         $t8, $a2, 4
    ctx->r24 = S32(ctx->r6 << 4);
    // 0x80802600: andi        $t0, $t9, 0xFF0F
    ctx->r8 = ctx->r25 & 0XFF0F;
    // 0x80802604: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80802608: b           L_80802618
    // 0x8080260C: sb          $t1, 0x79($a0)
    MEM_B(0X79, ctx->r4) = ctx->r9;
        goto L_80802618;
    // 0x8080260C: sb          $t1, 0x79($a0)
    MEM_B(0X79, ctx->r4) = ctx->r9;
L_80802610:
    // 0x80802610: jr          $ra
    // 0x80802614: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80802614: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80802618:
    // 0x80802618: jr          $ra
    // 0x8080261C: nop

    return;
    // 0x8080261C: nop

;}
RECOMP_FUNC void func_808023B4_ncpoddialog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808023B4: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x808023B8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808023BC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808023C0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808023C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808023C8: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x808023CC: lbu         $t6, 0x214($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X214);
    // 0x808023D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808023D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808023D8: bne         $v0, $t6, L_808023E4
    if (ctx->r2 != ctx->r14) {
        // 0x808023DC: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_808023E4;
    }
    // 0x808023DC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808023E0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_808023E4:
    // 0x808023E4: lbu         $t7, 0x211($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X211);
    // 0x808023E8: sltiu       $at, $t7, 0xA
    ctx->r1 = ctx->r15 < 0XA ? 1 : 0;
    // 0x808023EC: beq         $at, $zero, L_80802654
    if (ctx->r1 == 0) {
        // 0x808023F0: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80802654;
    }
    // 0x808023F0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808023F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3094, 0X2A10) << 16);
    // 0x808023F8: addu        $at, $at, $t7
    gpr jr_addend_80802400 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808023FC: lw          $t7, 0x2A10($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(3094, 0X2A10));
    // 0x80802400: jr          $t7
    // 0x80802404: nop

    switch (jr_addend_80802400 >> 2) {
        case 0: goto L_80802408; break;
        case 1: goto L_80802408; break;
        case 2: goto L_80802484; break;
        case 3: goto L_808024F4; break;
        case 4: goto L_80802450; break;
        case 5: goto L_808024BC; break;
        case 6: goto L_808024A0; break;
        case 7: goto L_80802654; break;
        case 8: goto L_8080252C; break;
        case 9: goto L_808025F0; break;
        default: switch_error(__func__, 0x80802400, 0x80802A10);
    }
    // 0x80802404: nop

L_80802408:
    // 0x80802408: addiu       $s1, $s0, 0xC4
    ctx->r17 = ADD32(ctx->r16, 0XC4);
    // 0x8080240C: addiu       $a1, $s0, 0x158
    ctx->r5 = ADD32(ctx->r16, 0X158);
    // 0x80802410: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80802414: jal         0x800EE7F8
    // 0x80802418: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80802418: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x8080241C: lwc1        $f4, 0x164($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X164);
    // 0x80802420: addiu       $s2, $s0, 0x148
    ctx->r18 = ADD32(ctx->r16, 0X148);
    // 0x80802424: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802428: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8080242C: lw          $a2, 0x168($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X168);
    // 0x80802430: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80802434: jal         0x800EEC30
    // 0x80802438: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    func_800EEC30(rdram, ctx);
        goto after_1;
    // 0x80802438: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    after_1:
    // 0x8080243C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802440: jal         0x800EF04C
    // 0x80802444: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800EF04C(rdram, ctx);
        goto after_2;
    // 0x80802444: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x80802448: b           L_80802660
    // 0x8080244C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80802660;
    // 0x8080244C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80802450:
    // 0x80802450: beq         $a3, $zero, L_80802460
    if (ctx->r7 == 0) {
        // 0x80802454: addiu       $v0, $zero, 0x5A
        ctx->r2 = ADD32(0, 0X5A);
            goto L_80802460;
    }
    // 0x80802454: addiu       $v0, $zero, 0x5A
    ctx->r2 = ADD32(0, 0X5A);
    // 0x80802458: b           L_80802460
    // 0x8080245C: addiu       $v0, $zero, -0x5A
    ctx->r2 = ADD32(0, -0X5A);
        goto L_80802460;
    // 0x8080245C: addiu       $v0, $zero, -0x5A
    ctx->r2 = ADD32(0, -0X5A);
L_80802460:
    // 0x80802460: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80802464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802468: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8080246C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80802470: jal         0x80801F88
    // 0x80802474: nop

    func_80801F88_ncpoddialog(rdram, ctx);
        goto after_3;
    // 0x80802474: nop

    after_3:
    // 0x80802478: addiu       $s1, $s0, 0xC4
    ctx->r17 = ADD32(ctx->r16, 0XC4);
    // 0x8080247C: b           L_8080265C
    // 0x80802480: addiu       $s2, $s0, 0x148
    ctx->r18 = ADD32(ctx->r16, 0X148);
        goto L_8080265C;
    // 0x80802480: addiu       $s2, $s0, 0x148
    ctx->r18 = ADD32(ctx->r16, 0X148);
L_80802484:
    // 0x80802484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802488: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080248C: jal         0x80801E78
    // 0x80802490: subu        $a2, $v0, $a3
    ctx->r6 = SUB32(ctx->r2, ctx->r7);
    func_80801E78_ncpoddialog(rdram, ctx);
        goto after_4;
    // 0x80802490: subu        $a2, $v0, $a3
    ctx->r6 = SUB32(ctx->r2, ctx->r7);
    after_4:
    // 0x80802494: addiu       $s1, $s0, 0xC4
    ctx->r17 = ADD32(ctx->r16, 0XC4);
    // 0x80802498: b           L_8080265C
    // 0x8080249C: addiu       $s2, $s0, 0x148
    ctx->r18 = ADD32(ctx->r16, 0X148);
        goto L_8080265C;
    // 0x8080249C: addiu       $s2, $s0, 0x148
    ctx->r18 = ADD32(ctx->r16, 0X148);
L_808024A0:
    // 0x808024A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808024A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808024A8: jal         0x80801E78
    // 0x808024AC: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    func_80801E78_ncpoddialog(rdram, ctx);
        goto after_5;
    // 0x808024AC: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_5:
    // 0x808024B0: addiu       $s1, $s0, 0xC4
    ctx->r17 = ADD32(ctx->r16, 0XC4);
    // 0x808024B4: b           L_8080265C
    // 0x808024B8: addiu       $s2, $s0, 0x148
    ctx->r18 = ADD32(ctx->r16, 0X148);
        goto L_8080265C;
    // 0x808024B8: addiu       $s2, $s0, 0x148
    ctx->r18 = ADD32(ctx->r16, 0X148);
L_808024BC:
    // 0x808024BC: beq         $a3, $zero, L_808024CC
    if (ctx->r7 == 0) {
        // 0x808024C0: addiu       $v0, $zero, -0xA
        ctx->r2 = ADD32(0, -0XA);
            goto L_808024CC;
    }
    // 0x808024C0: addiu       $v0, $zero, -0xA
    ctx->r2 = ADD32(0, -0XA);
    // 0x808024C4: b           L_808024CC
    // 0x808024C8: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
        goto L_808024CC;
    // 0x808024C8: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_808024CC:
    // 0x808024CC: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x808024D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808024D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808024D8: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808024DC: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x808024E0: jal         0x80801DB8
    // 0x808024E4: nop

    func_80801DB8_ncpoddialog(rdram, ctx);
        goto after_6;
    // 0x808024E4: nop

    after_6:
    // 0x808024E8: addiu       $s1, $s0, 0xC4
    ctx->r17 = ADD32(ctx->r16, 0XC4);
    // 0x808024EC: b           L_8080265C
    // 0x808024F0: addiu       $s2, $s0, 0x148
    ctx->r18 = ADD32(ctx->r16, 0X148);
        goto L_8080265C;
    // 0x808024F0: addiu       $s2, $s0, 0x148
    ctx->r18 = ADD32(ctx->r16, 0X148);
L_808024F4:
    // 0x808024F4: beq         $a3, $zero, L_80802504
    if (ctx->r7 == 0) {
        // 0x808024F8: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_80802504;
    }
    // 0x808024F8: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x808024FC: b           L_80802504
    // 0x80802500: addiu       $v0, $zero, -0xA
    ctx->r2 = ADD32(0, -0XA);
        goto L_80802504;
    // 0x80802500: addiu       $v0, $zero, -0xA
    ctx->r2 = ADD32(0, -0XA);
L_80802504:
    // 0x80802504: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x80802508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080250C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80802510: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80802514: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80802518: jal         0x80801DB8
    // 0x8080251C: nop

    func_80801DB8_ncpoddialog(rdram, ctx);
        goto after_7;
    // 0x8080251C: nop

    after_7:
    // 0x80802520: addiu       $s1, $s0, 0xC4
    ctx->r17 = ADD32(ctx->r16, 0XC4);
    // 0x80802524: b           L_8080265C
    // 0x80802528: addiu       $s2, $s0, 0x148
    ctx->r18 = ADD32(ctx->r16, 0X148);
        goto L_8080265C;
    // 0x80802528: addiu       $s2, $s0, 0x148
    ctx->r18 = ADD32(ctx->r16, 0X148);
L_8080252C:
    // 0x8080252C: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x80802530: jal         0x800EE7F8
    // 0x80802534: addiu       $a1, $s0, 0x158
    ctx->r5 = ADD32(ctx->r16, 0X158);
    func_800EE7F8(rdram, ctx);
        goto after_8;
    // 0x80802534: addiu       $a1, $s0, 0x158
    ctx->r5 = ADD32(ctx->r16, 0X158);
    after_8:
    // 0x80802538: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x8080253C: jal         0x800EE7F8
    // 0x80802540: addiu       $a1, $s0, 0x164
    ctx->r5 = ADD32(ctx->r16, 0X164);
    func_800EE7F8(rdram, ctx);
        goto after_9;
    // 0x80802540: addiu       $a1, $s0, 0x164
    ctx->r5 = ADD32(ctx->r16, 0X164);
    after_9:
    // 0x80802544: addiu       $s1, $sp, 0x50
    ctx->r17 = ADD32(ctx->r29, 0X50);
    // 0x80802548: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8080254C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802550: jal         0x80800000
    // 0x80802554: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800000_ncpoddialog(rdram, ctx);
        goto after_10;
    // 0x80802554: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x80802558: addiu       $s2, $s0, 0x148
    ctx->r18 = ADD32(ctx->r16, 0X148);
    // 0x8080255C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80802560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802564: jal         0x80800000
    // 0x80802568: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800000_ncpoddialog(rdram, ctx);
        goto after_11;
    // 0x80802568: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x8080256C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802570: jal         0x800EF04C
    // 0x80802574: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EF04C(rdram, ctx);
        goto after_12;
    // 0x80802574: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_12:
    // 0x80802578: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080257C: jal         0x800EF334
    // 0x80802580: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_800EF334(rdram, ctx);
        goto after_13;
    // 0x80802580: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_13:
    // 0x80802584: addiu       $s1, $s0, 0xC4
    ctx->r17 = ADD32(ctx->r16, 0XC4);
    // 0x80802588: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080258C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80802590: jal         0x800EFB24
    // 0x80802594: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    func_800EFB24(rdram, ctx);
        goto after_14;
    // 0x80802594: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    after_14:
    // 0x80802598: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080259C: jal         0x800EF368
    // 0x808025A0: lui         $a1, 0x437A
    ctx->r5 = S32(0X437A << 16);
    func_800EF368(rdram, ctx);
        goto after_15;
    // 0x808025A0: lui         $a1, 0x437A
    ctx->r5 = S32(0X437A << 16);
    after_15:
    // 0x808025A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808025A8: jal         0x800EF04C
    // 0x808025AC: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    func_800EF04C(rdram, ctx);
        goto after_16;
    // 0x808025AC: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    after_16:
    // 0x808025B0: lwc1        $f18, 0xD0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x808025B4: addiu       $a0, $s0, 0x188
    ctx->r4 = ADD32(ctx->r16, 0X188);
    // 0x808025B8: lw          $a2, 0xD4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XD4);
    // 0x808025BC: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x808025C0: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x808025C4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x808025C8: jal         0x800EEC30
    // 0x808025CC: lui         $a3, 0xC348
    ctx->r7 = S32(0XC348 << 16);
    func_800EEC30(rdram, ctx);
        goto after_17;
    // 0x808025CC: lui         $a3, 0xC348
    ctx->r7 = S32(0XC348 << 16);
    after_17:
    // 0x808025D0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808025D4: jal         0x800EF04C
    // 0x808025D8: addiu       $a1, $s0, 0x58
    ctx->r5 = ADD32(ctx->r16, 0X58);
    func_800EF04C(rdram, ctx);
        goto after_18;
    // 0x808025D8: addiu       $a1, $s0, 0x58
    ctx->r5 = ADD32(ctx->r16, 0X58);
    after_18:
    // 0x808025DC: addiu       $a0, $s0, 0x200
    ctx->r4 = ADD32(ctx->r16, 0X200);
    // 0x808025E0: jal         0x800EE7F8
    // 0x808025E4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800EE7F8(rdram, ctx);
        goto after_19;
    // 0x808025E4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_19:
    // 0x808025E8: b           L_80802660
    // 0x808025EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80802660;
    // 0x808025EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808025F0:
    // 0x808025F0: addiu       $s1, $sp, 0x44
    ctx->r17 = ADD32(ctx->r29, 0X44);
    // 0x808025F4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x808025F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808025FC: jal         0x80800000
    // 0x80802600: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800000_ncpoddialog(rdram, ctx);
        goto after_20;
    // 0x80802600: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_20:
    // 0x80802604: addiu       $s2, $s0, 0x148
    ctx->r18 = ADD32(ctx->r16, 0X148);
    // 0x80802608: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8080260C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802610: jal         0x80800000
    // 0x80802614: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800000_ncpoddialog(rdram, ctx);
        goto after_21;
    // 0x80802614: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_21:
    // 0x80802618: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080261C: jal         0x800EF04C
    // 0x80802620: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EF04C(rdram, ctx);
        goto after_22;
    // 0x80802620: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_22:
    // 0x80802624: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802628: jal         0x800EF334
    // 0x8080262C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_800EF334(rdram, ctx);
        goto after_23;
    // 0x8080262C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_23:
    // 0x80802630: jal         0x800A5800
    // 0x80802634: lbu         $a0, 0x218($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X218);
    func_800A5800(rdram, ctx);
        goto after_24;
    // 0x80802634: lbu         $a0, 0x218($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X218);
    after_24:
    // 0x80802638: addiu       $s1, $s0, 0xC4
    ctx->r17 = ADD32(ctx->r16, 0XC4);
    // 0x8080263C: jal         0x80085580
    // 0x80802640: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    _cadbfunc_entrypoint_0(rdram, ctx);
        goto after_25;
    // 0x80802640: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_25:
    // 0x80802644: jal         0x80085590
    // 0x80802648: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    _cadbfunc_entrypoint_2(rdram, ctx);
        goto after_26;
    // 0x80802648: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_26:
    // 0x8080264C: b           L_80802660
    // 0x80802650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80802660;
    // 0x80802650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80802654:
    // 0x80802654: addiu       $s1, $s0, 0xC4
    ctx->r17 = ADD32(ctx->r16, 0XC4);
    // 0x80802658: addiu       $s2, $s0, 0x148
    ctx->r18 = ADD32(ctx->r16, 0X148);
L_8080265C:
    // 0x8080265C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80802660:
    // 0x80802660: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80802664: jal         0x8080230C
    // 0x80802668: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_8080230C_ncpoddialog(rdram, ctx);
        goto after_27;
    // 0x80802668: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_27:
    // 0x8080266C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80802670: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802674: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80802678: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8080267C: jr          $ra
    // 0x80802680: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80802680: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_800C1104(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1104: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C1108: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C110C: jal         0x800F5310
    // 0x800C1110: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_800F5310(rdram, ctx);
        goto after_0;
    // 0x800C1110: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x800C1114: beq         $v0, $zero, L_800C11CC
    if (ctx->r2 == 0) {
        // 0x800C1118: nop
    
            goto L_800C11CC;
    }
    // 0x800C1118: nop

    // 0x800C111C: jal         0x800EA068
    // 0x800C1120: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    func_800EA068(rdram, ctx);
        goto after_1;
    // 0x800C1120: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_1:
    // 0x800C1124: beq         $v0, $zero, L_800C115C
    if (ctx->r2 == 0) {
        // 0x800C1128: addiu       $a0, $sp, 0x24
        ctx->r4 = ADD32(ctx->r29, 0X24);
            goto L_800C115C;
    }
    // 0x800C1128: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x800C112C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x800C1130: jal         0x80087898
    // 0x800C1134: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    _plsu_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x800C1134: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x800C1138: jal         0x800F5D18
    // 0x800C113C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5D18(rdram, ctx);
        goto after_3;
    // 0x800C113C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x800C1140: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C1144: bne         $v0, $at, L_800C1154
    if (ctx->r2 != ctx->r1) {
        // 0x800C1148: nop
    
            goto L_800C1154;
    }
    // 0x800C1148: nop

    // 0x800C114C: b           L_800C11E8
    // 0x800C1150: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800C11E8;
    // 0x800C1150: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800C1154:
    // 0x800C1154: b           L_800C11E8
    // 0x800C1158: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C11E8;
    // 0x800C1158: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C115C:
    // 0x800C115C: jal         0x80087898
    // 0x800C1160: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    _plsu_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x800C1160: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_4:
    // 0x800C1164: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800C1168: jal         0x800F5EF8
    // 0x800C116C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5EF8(rdram, ctx);
        goto after_5;
    // 0x800C116C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x800C1170: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800C1174: jal         0x8010FFA8
    // 0x800C1178: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8010FFA8(rdram, ctx);
        goto after_6;
    // 0x800C1178: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x800C117C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C1180: bne         $v0, $at, L_800C11AC
    if (ctx->r2 != ctx->r1) {
        // 0x800C1184: nop
    
            goto L_800C11AC;
    }
    // 0x800C1184: nop

    // 0x800C1188: jal         0x800F5D18
    // 0x800C118C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800F5D18(rdram, ctx);
        goto after_7;
    // 0x800C118C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_7:
    // 0x800C1190: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C1194: bne         $v0, $at, L_800C11A4
    if (ctx->r2 != ctx->r1) {
        // 0x800C1198: nop
    
            goto L_800C11A4;
    }
    // 0x800C1198: nop

    // 0x800C119C: b           L_800C11E8
    // 0x800C11A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800C11E8;
    // 0x800C11A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800C11A4:
    // 0x800C11A4: b           L_800C11E8
    // 0x800C11A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C11E8;
    // 0x800C11A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C11AC:
    // 0x800C11AC: jal         0x8010FFD8
    // 0x800C11B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8010FFD8(rdram, ctx);
        goto after_8;
    // 0x800C11B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_8:
    // 0x800C11B4: beq         $v0, $zero, L_800C11C4
    if (ctx->r2 == 0) {
        // 0x800C11B8: nop
    
            goto L_800C11C4;
    }
    // 0x800C11B8: nop

    // 0x800C11BC: b           L_800C11E8
    // 0x800C11C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800C11E8;
    // 0x800C11C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800C11C4:
    // 0x800C11C4: b           L_800C11E8
    // 0x800C11C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C11E8;
    // 0x800C11C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C11CC:
    // 0x800C11CC: jal         0x800A5490
    // 0x800C11D0: nop

    func_800A5490(rdram, ctx);
        goto after_9;
    // 0x800C11D0: nop

    after_9:
    // 0x800C11D4: beql        $v0, $zero, L_800C11E8
    if (ctx->r2 == 0) {
        // 0x800C11D8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800C11E8;
    }
    goto skip_0;
    // 0x800C11D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x800C11DC: b           L_800C11E8
    // 0x800C11E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800C11E8;
    // 0x800C11E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C11E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C11E8:
    // 0x800C11E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C11EC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800C11F0: jr          $ra
    // 0x800C11F4: nop

    return;
    // 0x800C11F4: nop

;}
RECOMP_FUNC void func_80800014_chappearfx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800014: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800018: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8080001C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800020: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800024: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80800028: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8080002C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800030: jal         0x80100094
    // 0x80800034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800038: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8080003C: jal         0x8001210C
    // 0x80800040: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001210C(rdram, ctx);
        goto after_1;
    // 0x80800040: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80800044: bnel        $v0, $zero, L_80800058
    if (ctx->r2 != 0) {
        // 0x80800048: lhu         $v0, 0x72($s1)
        ctx->r2 = MEM_HU(ctx->r17, 0X72);
            goto L_80800058;
    }
    goto skip_0;
    // 0x80800048: lhu         $v0, 0x72($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X72);
    skip_0:
    // 0x8080004C: jal         0x80800554
    // 0x80800050: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800554_chappearfx(rdram, ctx);
        goto after_2;
    // 0x80800050: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80800054: lhu         $v0, 0x72($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X72);
L_80800058:
    // 0x80800058: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080005C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800060: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800064: beq         $t6, $at, L_80800080
    if (ctx->r14 == ctx->r1) {
        // 0x80800068: addiu       $a0, $zero, 0x1C
        ctx->r4 = ADD32(0, 0X1C);
            goto L_80800080;
    }
    // 0x80800068: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x8080006C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800070: beq         $t6, $at, L_808000B8
    if (ctx->r14 == ctx->r1) {
        // 0x80800074: nop
    
            goto L_808000B8;
    }
    // 0x80800074: nop

    // 0x80800078: b           L_808001B8
    // 0x8080007C: lhu         $t1, 0x4($s2)
    ctx->r9 = MEM_HU(ctx->r18, 0X4);
        goto L_808001B8;
    // 0x8080007C: lhu         $t1, 0x4($s2)
    ctx->r9 = MEM_HU(ctx->r18, 0X4);
L_80800080:
    // 0x80800080: sb          $t7, 0xD($s2)
    MEM_B(0XD, ctx->r18) = ctx->r15;
    // 0x80800084: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80800088: jal         0x800FCAE0
    // 0x8080008C: addiu       $a2, $zero, 0x1F4
    ctx->r6 = ADD32(0, 0X1F4);
    func_800FCAE0(rdram, ctx);
        goto after_3;
    // 0x8080008C: addiu       $a2, $zero, 0x1F4
    ctx->r6 = ADD32(0, 0X1F4);
    after_3:
    // 0x80800090: jal         0x800D9078
    // 0x80800094: addiu       $a0, $s1, 0x58
    ctx->r4 = ADD32(ctx->r17, 0X58);
    func_800D9078(rdram, ctx);
        goto after_4;
    // 0x80800094: addiu       $a0, $s1, 0x58
    ctx->r4 = ADD32(ctx->r17, 0X58);
    after_4:
    // 0x80800098: beq         $v0, $zero, L_808001B4
    if (ctx->r2 == 0) {
        // 0x8080009C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808001B4;
    }
    // 0x8080009C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808000A0: jal         0x80101FDC
    // 0x808000A4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_5;
    // 0x808000A4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x808000A8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1188, 0X950) << 16);
    // 0x808000AC: lwc1        $f4, 0x950($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1188, 0X950));
    // 0x808000B0: b           L_808001B4
    // 0x808000B4: swc1        $f4, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f4.u32l;
        goto L_808001B4;
    // 0x808000B4: swc1        $f4, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f4.u32l;
L_808000B8:
    // 0x808000B8: jal         0x800D9078
    // 0x808000BC: addiu       $a0, $s1, 0x58
    ctx->r4 = ADD32(ctx->r17, 0X58);
    func_800D9078(rdram, ctx);
        goto after_6;
    // 0x808000BC: addiu       $a0, $s1, 0x58
    ctx->r4 = ADD32(ctx->r17, 0X58);
    after_6:
    // 0x808000C0: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x808000C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808000C8: lwc1        $f12, 0x58($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X58);
    // 0x808000CC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808000D0: lui         $a2, 0x3F99
    ctx->r6 = S32(0X3F99 << 16);
    // 0x808000D4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808000D8: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x808000DC: lui         $a3, 0x4180
    ctx->r7 = S32(0X4180 << 16);
    // 0x808000E0: jal         0x800F10B4
    // 0x808000E4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_7;
    // 0x808000E4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_7:
    // 0x808000E8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x808000EC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x808000F0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x808000F4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808000F8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x808000FC: cvt.w.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80800100: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x80800104: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80800108: addiu       $a2, $zero, 0x1F4
    ctx->r6 = ADD32(0, 0X1F4);
    // 0x8080010C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80800110: nop

    // 0x80800114: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80800118: beql        $t9, $zero, L_80800168
    if (ctx->r25 == 0) {
        // 0x8080011C: mfc1        $t9, $f8
        ctx->r25 = (int32_t)ctx->f8.u32l;
            goto L_80800168;
    }
    goto skip_1;
    // 0x8080011C: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    skip_1:
    // 0x80800120: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800124: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80800128: sub.s       $f8, $f0, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8080012C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80800130: nop

    // 0x80800134: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80800138: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8080013C: nop

    // 0x80800140: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80800144: bne         $t9, $zero, L_8080015C
    if (ctx->r25 != 0) {
        // 0x80800148: nop
    
            goto L_8080015C;
    }
    // 0x80800148: nop

    // 0x8080014C: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x80800150: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800154: b           L_80800174
    // 0x80800158: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_80800174;
    // 0x80800158: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_8080015C:
    // 0x8080015C: b           L_80800174
    // 0x80800160: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_80800174;
    // 0x80800160: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80800164: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
L_80800168:
    // 0x80800168: nop

    // 0x8080016C: bltz        $t9, L_8080015C
    if (SIGNED(ctx->r25) < 0) {
        // 0x80800170: nop
    
            goto L_8080015C;
    }
    // 0x80800170: nop

L_80800174:
    // 0x80800174: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80800178: beq         $s0, $zero, L_808001AC
    if (ctx->r16 == 0) {
        // 0x8080017C: sb          $t9, 0xC($s2)
        MEM_B(0XC, ctx->r18) = ctx->r25;
            goto L_808001AC;
    }
    // 0x8080017C: sb          $t9, 0xC($s2)
    MEM_B(0XC, ctx->r18) = ctx->r25;
    // 0x80800180: sb          $zero, 0xD($s2)
    MEM_B(0XD, ctx->r18) = 0;
    // 0x80800184: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x80800188: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080018C: jal         0x800FCAE0
    // 0x80800190: addiu       $a2, $zero, 0x1F4
    ctx->r6 = ADD32(0, 0X1F4);
    func_800FCAE0(rdram, ctx);
        goto after_8;
    // 0x80800190: addiu       $a2, $zero, 0x1F4
    ctx->r6 = ADD32(0, 0X1F4);
    after_8:
    // 0x80800194: jal         0x800FCA90
    // 0x80800198: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    func_800FCA90(rdram, ctx);
        goto after_9;
    // 0x80800198: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_9:
    // 0x8080019C: jal         0x800FFAB0
    // 0x808001A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_10;
    // 0x808001A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x808001A4: b           L_808001B8
    // 0x808001A8: lhu         $t1, 0x4($s2)
    ctx->r9 = MEM_HU(ctx->r18, 0X4);
        goto L_808001B8;
    // 0x808001A8: lhu         $t1, 0x4($s2)
    ctx->r9 = MEM_HU(ctx->r18, 0X4);
L_808001AC:
    // 0x808001AC: jal         0x800FCAE0
    // 0x808001B0: sb          $t0, 0xD($s2)
    MEM_B(0XD, ctx->r18) = ctx->r8;
    func_800FCAE0(rdram, ctx);
        goto after_11;
    // 0x808001B0: sb          $t0, 0xD($s2)
    MEM_B(0XD, ctx->r18) = ctx->r8;
    after_11:
L_808001B4:
    // 0x808001B4: lhu         $t1, 0x4($s2)
    ctx->r9 = MEM_HU(ctx->r18, 0X4);
L_808001B8:
    // 0x808001B8: addiu       $s0, $s2, 0x14
    ctx->r16 = ADD32(ctx->r18, 0X14);
    // 0x808001BC: andi        $t2, $t1, 0x8
    ctx->r10 = ctx->r9 & 0X8;
    // 0x808001C0: beq         $t2, $zero, L_808001EC
    if (ctx->r10 == 0) {
        // 0x808001C4: nop
    
            goto L_808001EC;
    }
    // 0x808001C4: nop

    // 0x808001C8: jal         0x8008A030
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddielink_entrypoint_2(rdram, ctx);
        goto after_12;
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808001D0: beq         $v0, $zero, L_808001EC
    if (ctx->r2 == 0) {
        // 0x808001D4: nop
    
            goto L_808001EC;
    }
    // 0x808001D4: nop

    // 0x808001D8: jal         0x8008A040
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_13;
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808001E0: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    // 0x808001E4: jal         0x800EE7F8
    // 0x808001E8: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_14;
    // 0x808001E8: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    after_14:
L_808001EC:
    // 0x808001EC: jal         0x800D8FF8
    // 0x808001F0: nop

    func_800D8FF8(rdram, ctx);
        goto after_15;
    // 0x808001F0: nop

    after_15:
    // 0x808001F4: lh          $t3, 0x0($s2)
    ctx->r11 = MEM_H(ctx->r18, 0X0);
    // 0x808001F8: addiu       $s3, $s2, 0x1C
    ctx->r19 = ADD32(ctx->r18, 0X1C);
    // 0x808001FC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80800200: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
    // 0x80800204: blez        $t3, L_80800300
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80800208: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800300;
    }
    // 0x80800208: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080020C: lh          $t5, 0x2($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X2);
L_80800210:
    // 0x80800210: lh          $t4, 0x8($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X8);
    // 0x80800214: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x80800218: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x8080021C: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x80800220: lh          $t8, 0x6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X6);
    // 0x80800224: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800228: lh          $t2, 0xA($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XA);
    // 0x8080022C: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80800230: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800234: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80800238: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8080023C: add.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x80800240: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80800244: nop

    // 0x80800248: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8080024C: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80800250: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800254: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80800258: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x8080025C: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80800260: nop

    // 0x80800264: sh          $t7, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r15;
    // 0x80800268: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8080026C: lh          $t3, 0x8($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X8);
    // 0x80800270: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800274: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80800278: mul.s       $f8, $f2, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8080027C: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x80800280: nop

    // 0x80800284: sh          $t1, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r9;
    // 0x80800288: add.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x8080028C: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x80800290: lh          $t4, 0x8($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X8);
    // 0x80800294: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80800298: bnel        $at, $zero, L_808002EC
    if (ctx->r1 != 0) {
        // 0x8080029C: lh          $s1, 0x0($s2)
        ctx->r17 = MEM_H(ctx->r18, 0X0);
            goto L_808002EC;
    }
    goto skip_2;
    // 0x8080029C: lh          $s1, 0x0($s2)
    ctx->r17 = MEM_H(ctx->r18, 0X0);
    skip_2:
    // 0x808002A0: lh          $t5, 0x0($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X0);
    // 0x808002A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A8: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x808002AC: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x808002B0: sh          $t6, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r14;
    // 0x808002B4: lh          $s1, 0x0($s2)
    ctx->r17 = MEM_H(ctx->r18, 0X0);
    // 0x808002B8: blez        $s1, L_808002F4
    if (SIGNED(ctx->r17) <= 0) {
        // 0x808002BC: sll         $t7, $s1, 2
        ctx->r15 = S32(ctx->r17 << 2);
            goto L_808002F4;
    }
    // 0x808002BC: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x808002C0: addu        $t7, $t7, $s1
    ctx->r15 = ADD32(ctx->r15, ctx->r17);
    // 0x808002C4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808002C8: addu        $a1, $t7, $s3
    ctx->r5 = ADD32(ctx->r15, ctx->r19);
    // 0x808002CC: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x808002D0: jal         0x8001BBA0
    // 0x808002D4: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    rare_memcpy(rdram, ctx);
        goto after_16;
    // 0x808002D4: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    after_16:
    // 0x808002D8: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x808002DC: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808002E0: b           L_808002F4
    // 0x808002E4: lh          $s1, 0x0($s2)
    ctx->r17 = MEM_H(ctx->r18, 0X0);
        goto L_808002F4;
    // 0x808002E4: lh          $s1, 0x0($s2)
    ctx->r17 = MEM_H(ctx->r18, 0X0);
    // 0x808002E8: lh          $s1, 0x0($s2)
    ctx->r17 = MEM_H(ctx->r18, 0X0);
L_808002EC:
    // 0x808002EC: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x808002F0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_808002F4:
    // 0x808002F4: slt         $at, $v0, $s1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x808002F8: bnel        $at, $zero, L_80800210
    if (ctx->r1 != 0) {
        // 0x808002FC: lh          $t5, 0x2($s0)
        ctx->r13 = MEM_H(ctx->r16, 0X2);
            goto L_80800210;
    }
    goto skip_3;
    // 0x808002FC: lh          $t5, 0x2($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X2);
    skip_3:
L_80800300:
    // 0x80800300: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800304: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800308: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8080030C: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80800310: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80800314: jr          $ra
    // 0x80800318: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80800318: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void ch1pfreeze_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2224, 0X420) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x420
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2224, 0X420));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x420
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2224, 0X420));
;}
RECOMP_FUNC void _vplight_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088FF8: syscall     755
    recomp_syscall_handler(rdram, ctx, 0x80088FF8);
    return;
    // 0x80088FFC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800A794C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A794C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A7950: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A7954: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A7958: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800A795C: jal         0x800FE8EC
    // 0x800A7960: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800FE8EC(rdram, ctx);
        goto after_0;
    // 0x800A7960: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800A7964: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800A7968: jal         0x800A7A18
    // 0x800A796C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800A7A18(rdram, ctx);
        goto after_1;
    // 0x800A796C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800A7970: jal         0x800A7A90
    // 0x800A7974: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800A7A90(rdram, ctx);
        goto after_2;
    // 0x800A7974: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x800A7978: jal         0x800A7B18
    // 0x800A797C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800A7B18(rdram, ctx);
        goto after_3;
    // 0x800A797C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x800A7980: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A7984: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A7988: jr          $ra
    // 0x800A798C: nop

    return;
    // 0x800A798C: nop

;}
RECOMP_FUNC void func_80109F40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109F40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80109F44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80109F48: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80109F4C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80109F50: jal         0x8010114C
    // 0x80109F54: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    func_8010114C(rdram, ctx);
        goto after_0;
    // 0x80109F54: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_0:
    // 0x80109F58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80109F5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80109F60: jr          $ra
    // 0x80109F64: nop

    return;
    // 0x80109F64: nop

;}
RECOMP_FUNC void func_80808A24_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80808A24: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80808A28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80808A2C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80808A30: lw          $t6, 0x188($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X188);
    // 0x80808A34: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80808A38: jal         0x80807BB8
    // 0x80808A3C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_80807BB8_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80808A3C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80808A40: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80808A44: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80808A48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808A4C: jal         0x80808DB0
    // 0x80808A50: sw          $t7, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r15;
    func_80808DB0_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80808A50: sw          $t7, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r15;
    after_1:
    // 0x80808A54: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
    // 0x80808A58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808A5C: jal         0x80808CAC
    // 0x80808A60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80808CAC_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80808A60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80808A64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80808A68: jal         0x80800858
    // 0x80808A6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800858_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x80808A6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80808A70: jal         0x80808D80
    // 0x80808A74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80808D80_bsfirstp(rdram, ctx);
        goto after_4;
    // 0x80808A74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80808A78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80808A7C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80808A80: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80808A84: jr          $ra
    // 0x80808A88: nop

    return;
    // 0x80808A88: nop

;}
RECOMP_FUNC void _chlinkpipefan_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087420: syscall     570
    recomp_syscall_handler(rdram, ctx, 0x80087420);
    return;
    // 0x80087424: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
