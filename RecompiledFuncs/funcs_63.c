#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _chdragonbrothers_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086EE8: syscall     470
    recomp_syscall_handler(rdram, ctx, 0x80086EE8);
    return;
    // 0x80086EEC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void bsdronefalldie_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800208: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080020C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800210: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800214: lw          $v0, 0x190($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X190);
    // 0x80800218: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080021C: beq         $v0, $at, L_80800234
    if (ctx->r2 == ctx->r1) {
        // 0x80800220: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800234;
    }
    // 0x80800220: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800224: beql        $v0, $at, L_80800258
    if (ctx->r2 == ctx->r1) {
        // 0x80800228: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800258;
    }
    goto skip_0;
    // 0x80800228: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080022C: b           L_80800258
    // 0x80800230: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800258;
    // 0x80800230: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800234:
    // 0x80800234: jal         0x800846C0
    // 0x80800238: nop

    _badata_entrypoint_16(rdram, ctx);
        goto after_0;
    // 0x80800238: nop

    after_0:
    // 0x8080023C: jal         0x800FCCD4
    // 0x80800240: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800FCCD4(rdram, ctx);
        goto after_1;
    // 0x80800240: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800244: bne         $v0, $zero, L_80800254
    if (ctx->r2 != 0) {
        // 0x80800248: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800254;
    }
    // 0x80800248: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080024C: jal         0x80800000
    // 0x80800250: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800000_bsdronefalldie(rdram, ctx);
        goto after_2;
    // 0x80800250: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
L_80800254:
    // 0x80800254: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800258:
    // 0x80800258: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080025C: jr          $ra
    // 0x80800260: nop

    return;
    // 0x80800260: nop

    // 0x80800264: nop

    // 0x80800268: nop

    // 0x8080026C: nop

;}
RECOMP_FUNC void func_80800254_chfantasyonion(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "func_80800254_chfantasyonion");
    // 0x80800254: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80800258: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080025C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800260: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800264: jal         0x800878B0
    // 0x80800268: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    _plsu_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800268: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x8080026C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800270: beq         $v0, $at, L_80800344
    if (ctx->r2 == ctx->r1) {
        // 0x80800274: sw          $v0, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r2;
            goto L_80800344;
    }
    // 0x80800274: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x80800278: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8080027C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800280: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800284: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80800288: nop

    // 0x8080028C: bc1f        L_808002E0
    if (!c1cs) {
        // 0x80800290: nop
    
            goto L_808002E0;
    }
    // 0x80800290: nop

    // 0x80800294: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80800298: lwc1        $f10, 0x30($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X30);
    // 0x8080029C: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x808002A0: nop

    // 0x808002A4: bc1f        L_808002E0
    if (!c1cs) {
        // 0x808002A8: nop
    
            goto L_808002E0;
    }
    // 0x808002A8: nop

    // 0x808002AC: jal         0x80015184
    // 0x808002B0: nop

    func_80015184(rdram, ctx);
        goto after_1;
    // 0x808002B0: nop

    after_1:
    // 0x808002B4: lbu         $t9, 0x79($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X79);
    // 0x808002B8: sll         $t8, $v0, 4
    ctx->r24 = S32(ctx->r2 << 4);
    // 0x808002BC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x808002C0: andi        $t0, $t9, 0xFF0F
    ctx->r8 = ctx->r25 & 0XFF0F;
    // 0x808002C4: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x808002C8: jal         0x80015178
    // 0x808002CC: sb          $t1, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r9;
    func_80015178(rdram, ctx);
        goto after_2;
    // 0x808002CC: sb          $t1, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r9;
    after_2:
    // 0x808002D0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x808002D4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808002D8: nop

    // 0x808002DC: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
L_808002E0:
    // 0x808002E0: jal         0x800F5C94
    // 0x808002E4: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    func_800F5C94(rdram, ctx);
        goto after_3;
    // 0x808002E4: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    after_3:
    // 0x808002E8: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x808002EC: beq         $v0, $at, L_80800308
    if (ctx->r2 == ctx->r1) {
        // 0x808002F0: lw          $a0, 0x6C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X6C);
            goto L_80800308;
    }
    // 0x808002F0: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x808002F4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808002F8: jal         0x800F79DC
    // 0x808002FC: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    func_800F79DC(rdram, ctx);
        goto after_4;
    // 0x808002FC: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    after_4:
    // 0x80800300: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80800304: sw          $t2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r10;
L_80800308:
    // 0x80800308: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x8080030C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800310: beql        $t3, $at, L_80800374
    if (ctx->r11 == ctx->r1) {
        // 0x80800314: lhu         $v0, 0x72($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X72);
            goto L_80800374;
    }
    goto skip_0;
    // 0x80800314: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    skip_0:
    // 0x80800318: jal         0x800F54E4
    // 0x8080031C: nop

    func_800F54E4(rdram, ctx);
        goto after_5;
    // 0x8080031C: nop

    after_5:
    // 0x80800320: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800324: jal         0x800F5A00
    // 0x80800328: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    func_800F5A00(rdram, ctx);
        goto after_6;
    // 0x80800328: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    after_6:
    // 0x8080032C: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80800330: jal         0x800EF3DC
    // 0x80800334: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EF3DC(rdram, ctx);
        goto after_7;
    // 0x80800334: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_7:
    // 0x80800338: lwc1        $f18, 0x48($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8080033C: b           L_80800370
    // 0x80800340: swc1        $f18, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f18.u32l;
        goto L_80800370;
    // 0x80800340: swc1        $f18, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f18.u32l;
L_80800344:
    // 0x80800344: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80800348: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080034C: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800350: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80800354: nop

    // 0x80800358: bc1tl       L_80800374
    if (c1cs) {
        // 0x8080035C: lhu         $v0, 0x72($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X72);
            goto L_80800374;
    }
    goto skip_1;
    // 0x8080035C: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    skip_1:
    // 0x80800360: lbu         $a0, 0x79($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X79);
    // 0x80800364: srl         $t4, $a0, 4
    ctx->r12 = S32(U32(ctx->r4) >> 4);
    // 0x80800368: jal         0x80015178
    // 0x8080036C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    func_80015178(rdram, ctx);
        goto after_8;
    // 0x8080036C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_8:
L_80800370:
    // 0x80800370: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
L_80800374:
    // 0x80800374: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800378: srl         $t5, $v0, 10
    ctx->r13 = S32(U32(ctx->r2) >> 10);
    // 0x8080037C: beq         $t5, $at, L_808004F4
    if (ctx->r13 == ctx->r1) {
        // 0x80800380: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808004F4;
    }
    // 0x80800380: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800384: bne         $t5, $at, L_808004F4
    if (ctx->r13 != ctx->r1) {
        // 0x80800388: addiu       $a0, $sp, 0x4C
        ctx->r4 = ADD32(ctx->r29, 0X4C);
            goto L_808004F4;
    }
    // 0x80800388: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x8080038C: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x80800390: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800394: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800398: sll         $t7, $t6, 11
    ctx->r15 = S32(ctx->r14 << 11);
    // 0x8080039C: srl         $t9, $t7, 31
    ctx->r25 = S32(U32(ctx->r15) >> 31);
    // 0x808003A0: jal         0x800EE7F8
    // 0x808003A4: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
    func_800EE7F8(rdram, ctx);
        goto after_9;
    // 0x808003A4: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
    after_9:
    // 0x808003A8: jal         0x800D90A4
    // 0x808003AC: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    func_800D90A4(rdram, ctx);
        goto after_10;
    // 0x808003AC: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    after_10:
    // 0x808003B0: beq         $v0, $zero, L_8080040C
    if (ctx->r2 == 0) {
        // 0x808003B4: lui         $a3, 0x3F80
        ctx->r7 = S32(0X3F80 << 16);
            goto L_8080040C;
    }
    // 0x808003B4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x808003B8: lw          $v1, 0x64($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X64);
    // 0x808003BC: sll         $t0, $v1, 12
    ctx->r8 = S32(ctx->r3 << 12);
    // 0x808003C0: bltz        $t0, L_808003E8
    if (SIGNED(ctx->r8) < 0) {
        // 0x808003C4: sll         $v0, $v1, 11
        ctx->r2 = S32(ctx->r3 << 11);
            goto L_808003E8;
    }
    // 0x808003C4: sll         $v0, $v1, 11
    ctx->r2 = S32(ctx->r3 << 11);
    // 0x808003C8: lbu         $t6, 0x65($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X65);
    // 0x808003CC: srl         $t1, $v0, 31
    ctx->r9 = S32(U32(ctx->r2) >> 31);
    // 0x808003D0: sltiu       $t3, $t1, 0x1
    ctx->r11 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x808003D4: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x808003D8: andi        $t5, $t4, 0x10
    ctx->r13 = ctx->r12 & 0X10;
    // 0x808003DC: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x808003E0: or          $t9, $t5, $t7
    ctx->r25 = ctx->r13 | ctx->r15;
    // 0x808003E4: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
L_808003E8:
    // 0x808003E8: lhu         $t8, 0x76($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X76);
    // 0x808003EC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x808003F0: srl         $t0, $t8, 7
    ctx->r8 = S32(U32(ctx->r24) >> 7);
    // 0x808003F4: div         $zero, $t0, $at
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r1)));
    // 0x808003F8: mflo        $t1
    ctx->r9 = lo;
    // 0x808003FC: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80800400: nop

    // 0x80800404: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800408: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
L_8080040C:
    // 0x8080040C: lhu         $t2, 0x76($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X76);
    // 0x80800410: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80800414: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x80800418: srl         $t3, $t2, 7
    ctx->r11 = S32(U32(ctx->r10) >> 7);
    // 0x8080041C: div         $zero, $t3, $at
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r1)));
    // 0x80800420: mflo        $t4
    ctx->r12 = lo;
    // 0x80800424: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x80800428: sll         $t7, $t6, 11
    ctx->r15 = S32(ctx->r14 << 11);
    // 0x8080042C: bgez        $t7, L_8080045C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80800430: cvt.s.w     $f0, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8080045C;
    }
    // 0x80800430: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800434: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800438: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080043C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800440: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800444: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800448: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x8080044C: jal         0x800F10B4
    // 0x80800450: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F10B4(rdram, ctx);
        goto after_11;
    // 0x80800450: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_11:
    // 0x80800454: b           L_80800478
    // 0x80800458: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_80800478;
    // 0x80800458: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8080045C:
    // 0x8080045C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800460: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800464: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800468: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080046C: jal         0x800F10B4
    // 0x80800470: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_12;
    // 0x80800470: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_12:
    // 0x80800474: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80800478:
    // 0x80800478: lwc1        $f6, 0x34($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8080047C: swc1        $f2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f2.u32l;
    // 0x80800480: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80800484: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80800488: jal         0x800D7520
    // 0x8080048C: nop

    func_800D7520(rdram, ctx);
        goto after_13;
    // 0x8080048C: nop

    after_13:
    // 0x80800490: lwc1        $f2, 0x58($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80800494: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800498: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8080049C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x808004A0: jal         0x800C7A68
    // 0x808004A4: nop

    func_800C7A68(rdram, ctx);
        goto after_14;
    // 0x808004A4: nop

    after_14:
    // 0x808004A8: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x808004AC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808004B0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808004B4: beq         $t8, $zero, L_808004CC
    if (ctx->r24 == 0) {
        // 0x808004B8: nop
    
            goto L_808004CC;
    }
    // 0x808004B8: nop

    // 0x808004BC: jal         0x800F1DF4
    // 0x808004C0: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    func_800F1DF4(rdram, ctx);
        goto after_15;
    // 0x808004C0: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_15:
    // 0x808004C4: b           L_808004D8
    // 0x808004C8: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
        goto L_808004D8;
    // 0x808004C8: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
L_808004CC:
    // 0x808004CC: jal         0x800F1DF4
    // 0x808004D0: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_800F1DF4(rdram, ctx);
        goto after_16;
    // 0x808004D0: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_16:
    // 0x808004D4: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
L_808004D8:
    // 0x808004D8: lui         $a1, 0x3D4C
    ctx->r5 = S32(0X3D4C << 16);
    // 0x808004DC: lui         $a2, 0x3C23
    ctx->r6 = S32(0X3C23 << 16);
    // 0x808004E0: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x808004E4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808004E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004EC: jal         0x80102BAC
    // 0x808004F0: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    func_80102BAC(rdram, ctx);
        goto after_17;
    // 0x808004F0: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    after_17:
L_808004F4:
    // 0x808004F4: jal         0x800D90A4
    // 0x808004F8: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    func_800D90A4(rdram, ctx);
        goto after_18;
    // 0x808004F8: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    after_18:
    // 0x808004FC: bne         $v0, $zero, L_8080055C
    if (ctx->r2 != 0) {
        // 0x80800500: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_8080055C;
    }
    // 0x80800500: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800504: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800508: lwc1        $f12, 0x30($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X30);
    // 0x8080050C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800510: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800514: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800518: jal         0x800F10B4
    // 0x8080051C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F10B4(rdram, ctx);
        goto after_19;
    // 0x8080051C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_19:
    // 0x80800520: lui         $at, 0x4507
    ctx->r1 = S32(0X4507 << 16);
    // 0x80800524: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800528: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x8080052C: mul.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800530: jal         0x80013970
    // 0x80800534: nop

    func_80013970(rdram, ctx);
        goto after_20;
    // 0x80800534: nop

    after_20:
    // 0x80800538: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8080053C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800540: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800544: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800548: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8080054C: nop

    // 0x80800550: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800554: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80800558: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
L_8080055C:
    // 0x8080055C: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x80800560: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800564: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80800568: beql        $t0, $at, L_808005F4
    if (ctx->r8 == ctx->r1) {
        // 0x8080056C: lw          $t2, 0x6C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X6C);
            goto L_808005F4;
    }
    goto skip_2;
    // 0x8080056C: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    skip_2:
    // 0x80800570: lwc1        $f18, 0x48($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800574: addiu       $t1, $s0, 0x4
    ctx->r9 = ADD32(ctx->r16, 0X4);
    // 0x80800578: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x8080057C: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80800580: jal         0x800F54E4
    // 0x80800584: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    func_800F54E4(rdram, ctx);
        goto after_21;
    // 0x80800584: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    after_21:
    // 0x80800588: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080058C: jal         0x800F5B38
    // 0x80800590: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800F5B38(rdram, ctx);
        goto after_22;
    // 0x80800590: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_22:
    // 0x80800594: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800598: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8080059C: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x808005A0: jal         0x800F54E4
    // 0x808005A4: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    func_800F54E4(rdram, ctx);
        goto after_23;
    // 0x808005A4: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    after_23:
    // 0x808005A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808005AC: jal         0x800F832C
    // 0x808005B0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800F832C(rdram, ctx);
        goto after_24;
    // 0x808005B0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_24:
    // 0x808005B4: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x808005B8: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x808005BC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x808005C0: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x808005C4: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x808005C8: jal         0x800EF934
    // 0x808005CC: nop

    func_800EF934(rdram, ctx);
        goto after_25;
    // 0x808005CC: nop

    after_25:
    // 0x808005D0: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x808005D4: jal         0x800EF04C
    // 0x808005D8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800EF04C(rdram, ctx);
        goto after_26;
    // 0x808005D8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_26:
    // 0x808005DC: jal         0x800F54E4
    // 0x808005E0: nop

    func_800F54E4(rdram, ctx);
        goto after_27;
    // 0x808005E0: nop

    after_27:
    // 0x808005E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808005E8: jal         0x800F8418
    // 0x808005EC: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    func_800F8418(rdram, ctx);
        goto after_28;
    // 0x808005EC: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    after_28:
    // 0x808005F0: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
L_808005F4:
    // 0x808005F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005F8: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x808005FC: nop

    // 0x80800600: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800604: jal         0x80800000
    // 0x80800608: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    func_80800000_chfantasyonion(rdram, ctx);
        goto after_29;
    // 0x80800608: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    after_29:
    // 0x8080060C: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x80800610: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800614: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800618: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x8080061C: jr          $ra
    // 0x80800620: nop

    return;
    // 0x80800620: nop

;}
RECOMP_FUNC void func_808002CC_bsdronexform(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808002D8: lw          $t7, 0x18C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X18C);
    // 0x808002DC: jal         0x800B5450
    // 0x808002E0: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    func_800B5450(rdram, ctx);
        goto after_0;
    // 0x808002E0: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    after_0:
    // 0x808002E4: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x808002E8: lw          $t9, 0x18C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X18C);
    // 0x808002EC: jal         0x800B5450
    // 0x808002F0: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    func_800B5450(rdram, ctx);
        goto after_1;
    // 0x808002F0: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_1:
    // 0x808002F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002FC: jr          $ra
    // 0x80800300: nop

    return;
    // 0x80800300: nop

;}
RECOMP_FUNC void func_800DC958(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DC958: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800DC95C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800DC960: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800DC964: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800DC968: lbu         $t6, 0x21($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X21);
    // 0x800DC96C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800DC970: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DC974: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x800DC978: beq         $t7, $zero, L_800DC99C
    if (ctx->r15 == 0) {
        // 0x800DC97C: nop
    
            goto L_800DC99C;
    }
    // 0x800DC97C: nop

    // 0x800DC980: lw          $a0, -0x3698($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3698);
    // 0x800DC984: jal         0x800ADE2C
    // 0x800DC988: lb          $a1, 0x20($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X20);
    func_800ADE2C(rdram, ctx);
        goto after_0;
    // 0x800DC988: lb          $a1, 0x20($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X20);
    after_0:
    // 0x800DC98C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DC990: addiu       $a0, $a0, -0x31A8
    ctx->r4 = ADD32(ctx->r4, -0X31A8);
    // 0x800DC994: jal         0x80019AA0
    // 0x800DC998: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80019AA0(rdram, ctx);
        goto after_1;
    // 0x800DC998: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
L_800DC99C:
    // 0x800DC99C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DC9A0: addiu       $a0, $a0, -0x3120
    ctx->r4 = ADD32(ctx->r4, -0X3120);
    // 0x800DC9A4: jal         0x800193C4
    // 0x800DC9A8: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    func_800193C4(rdram, ctx);
        goto after_2;
    // 0x800DC9A8: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    after_2:
    // 0x800DC9AC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DC9B0: addiu       $a0, $a0, -0x3110
    ctx->r4 = ADD32(ctx->r4, -0X3110);
    // 0x800DC9B4: jal         0x800193C4
    // 0x800DC9B8: addiu       $a1, $s0, 0x14
    ctx->r5 = ADD32(ctx->r16, 0X14);
    func_800193C4(rdram, ctx);
        goto after_3;
    // 0x800DC9B8: addiu       $a1, $s0, 0x14
    ctx->r5 = ADD32(ctx->r16, 0X14);
    after_3:
    // 0x800DC9BC: lbu         $t8, 0x21($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X21);
    // 0x800DC9C0: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x800DC9C4: beq         $t9, $zero, L_800DC9D4
    if (ctx->r25 == 0) {
        // 0x800DC9C8: nop
    
            goto L_800DC9D4;
    }
    // 0x800DC9C8: nop

    // 0x800DC9CC: jal         0x80018DAC
    // 0x800DC9D0: nop

    mlMtxPop(rdram, ctx);
        goto after_4;
    // 0x800DC9D0: nop

    after_4:
L_800DC9D4:
    // 0x800DC9D4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DC9D8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800DC9DC: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800DC9E0: addiu       $a2, $a2, -0x3120
    ctx->r6 = ADD32(ctx->r6, -0X3120);
    // 0x800DC9E4: addiu       $a1, $a1, -0x3110
    ctx->r5 = ADD32(ctx->r5, -0X3110);
    // 0x800DC9E8: jal         0x800EFB24
    // 0x800DC9EC: addiu       $a0, $a0, -0x3130
    ctx->r4 = ADD32(ctx->r4, -0X3130);
    func_800EFB24(rdram, ctx);
        goto after_5;
    // 0x800DC9EC: addiu       $a0, $a0, -0x3130
    ctx->r4 = ADD32(ctx->r4, -0X3130);
    after_5:
    // 0x800DC9F0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DC9F4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800DC9F8: addiu       $a1, $a1, -0x3168
    ctx->r5 = ADD32(ctx->r5, -0X3168);
    // 0x800DC9FC: jal         0x800EF3DC
    // 0x800DCA00: addiu       $a0, $a0, -0x3120
    ctx->r4 = ADD32(ctx->r4, -0X3120);
    func_800EF3DC(rdram, ctx);
        goto after_6;
    // 0x800DCA00: addiu       $a0, $a0, -0x3120
    ctx->r4 = ADD32(ctx->r4, -0X3120);
    after_6:
    // 0x800DCA04: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800DCA08: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800DCA0C: addiu       $v1, $v1, -0x3120
    ctx->r3 = ADD32(ctx->r3, -0X3120);
    // 0x800DCA10: addiu       $v0, $v0, -0x3130
    ctx->r2 = ADD32(ctx->r2, -0X3130);
    // 0x800DCA14: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800DCA18: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800DCA1C: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800DCA20: lwc1        $f16, 0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800DCA24: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800DCA28: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800DCA2C: lbu         $t0, 0x21($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X21);
    // 0x800DCA30: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800DCA34: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800DCA38: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x800DCA3C: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800DCA40: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800DCA44: add.s       $f0, $f16, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800DCA48: beq         $t1, $zero, L_800DCAC0
    if (ctx->r9 == 0) {
        // 0x800DCA4C: neg.s       $f0, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
            goto L_800DCAC0;
    }
    // 0x800DCA4C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800DCA50: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800DCA54: nop

    // 0x800DCA58: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800DCA5C: nop

    // 0x800DCA60: bc1fl       L_800DCA90
    if (!c1cs) {
        // 0x800DCA64: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_800DCA90;
    }
    goto skip_0;
    // 0x800DCA64: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_0:
    // 0x800DCA68: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800DCA6C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DCA70: beq         $v0, $zero, L_800DCA8C
    if (ctx->r2 == 0) {
        // 0x800DCA74: addu        $a1, $s0, $v0
        ctx->r5 = ADD32(ctx->r16, ctx->r2);
            goto L_800DCA8C;
    }
    // 0x800DCA74: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    // 0x800DCA78: swc1        $f0, -0x3138($at)
    MEM_W(-0X3138, ctx->r1) = ctx->f0.u32l;
    // 0x800DCA7C: jal         0x800DE2A4
    // 0x800DCA80: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800DE2A4(rdram, ctx);
        goto after_7;
    // 0x800DCA80: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_7:
    // 0x800DCA84: b           L_800DCB48
    // 0x800DCA88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800DCB48;
    // 0x800DCA88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800DCA8C:
    // 0x800DCA8C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_800DCA90:
    // 0x800DCA90: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DCA94: swc1        $f0, -0x3138($at)
    MEM_W(-0X3138, ctx->r1) = ctx->f0.u32l;
    // 0x800DCA98: bc1fl       L_800DCB48
    if (!c1cs) {
        // 0x800DCA9C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800DCB48;
    }
    goto skip_1;
    // 0x800DCA9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x800DCAA0: lh          $v0, 0x22($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X22);
    // 0x800DCAA4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800DCAA8: beql        $v0, $zero, L_800DCB48
    if (ctx->r2 == 0) {
        // 0x800DCAAC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800DCB48;
    }
    goto skip_2;
    // 0x800DCAAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x800DCAB0: jal         0x800DE2A4
    // 0x800DCAB4: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    func_800DE2A4(rdram, ctx);
        goto after_8;
    // 0x800DCAB4: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    after_8:
    // 0x800DCAB8: b           L_800DCB48
    // 0x800DCABC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800DCB48;
    // 0x800DCABC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800DCAC0:
    // 0x800DCAC0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800DCAC4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DCAC8: swc1        $f0, -0x3138($at)
    MEM_W(-0X3138, ctx->r1) = ctx->f0.u32l;
    // 0x800DCACC: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800DCAD0: nop

    // 0x800DCAD4: bc1fl       L_800DCB18
    if (!c1cs) {
        // 0x800DCAD8: lw          $v0, 0x24($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X24);
            goto L_800DCB18;
    }
    goto skip_3;
    // 0x800DCAD8: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    skip_3:
    // 0x800DCADC: lh          $v0, 0x22($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X22);
    // 0x800DCAE0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800DCAE4: beql        $v0, $zero, L_800DCAF8
    if (ctx->r2 == 0) {
        // 0x800DCAE8: lw          $v0, 0x24($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X24);
            goto L_800DCAF8;
    }
    goto skip_4;
    // 0x800DCAE8: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    skip_4:
    // 0x800DCAEC: jal         0x800DE2A4
    // 0x800DCAF0: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    func_800DE2A4(rdram, ctx);
        goto after_9;
    // 0x800DCAF0: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    after_9:
    // 0x800DCAF4: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
L_800DCAF8:
    // 0x800DCAF8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800DCAFC: beql        $v0, $zero, L_800DCB48
    if (ctx->r2 == 0) {
        // 0x800DCB00: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800DCB48;
    }
    goto skip_5;
    // 0x800DCB00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x800DCB04: jal         0x800DE2A4
    // 0x800DCB08: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    func_800DE2A4(rdram, ctx);
        goto after_10;
    // 0x800DCB08: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    after_10:
    // 0x800DCB0C: b           L_800DCB48
    // 0x800DCB10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800DCB48;
    // 0x800DCB10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800DCB14: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
L_800DCB18:
    // 0x800DCB18: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800DCB1C: beql        $v0, $zero, L_800DCB30
    if (ctx->r2 == 0) {
        // 0x800DCB20: lh          $v0, 0x22($s0)
        ctx->r2 = MEM_H(ctx->r16, 0X22);
            goto L_800DCB30;
    }
    goto skip_6;
    // 0x800DCB20: lh          $v0, 0x22($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X22);
    skip_6:
    // 0x800DCB24: jal         0x800DE2A4
    // 0x800DCB28: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    func_800DE2A4(rdram, ctx);
        goto after_11;
    // 0x800DCB28: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    after_11:
    // 0x800DCB2C: lh          $v0, 0x22($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X22);
L_800DCB30:
    // 0x800DCB30: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800DCB34: beql        $v0, $zero, L_800DCB48
    if (ctx->r2 == 0) {
        // 0x800DCB38: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800DCB48;
    }
    goto skip_7;
    // 0x800DCB38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x800DCB3C: jal         0x800DE2A4
    // 0x800DCB40: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    func_800DE2A4(rdram, ctx);
        goto after_12;
    // 0x800DCB40: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    after_12:
    // 0x800DCB44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800DCB48:
    // 0x800DCB48: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800DCB4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800DCB50: jr          $ra
    // 0x800DCB54: nop

    return;
    // 0x800DCB54: nop

;}
RECOMP_FUNC void func_808000B8_chboggyboy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x808000BC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808000C0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808000C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000C8: jal         0x80100094
    // 0x808000CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808000CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808000D0: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x808000D4: jal         0x800D90A4
    // 0x808000D8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_1;
    // 0x808000D8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_1:
    // 0x808000DC: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E4: jal         0x80100094
    // 0x808000E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x808000E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x808000EC: beq         $v0, $zero, L_8080010C
    if (ctx->r2 == 0) {
        // 0x808000F0: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8080010C;
    }
    // 0x808000F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000F4: jal         0x80100094
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808000FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800100: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800104: jal         0x800897D8
    // 0x80800108: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_4;
    // 0x80800108: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
L_8080010C:
    // 0x8080010C: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800110: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800114: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800118: sltiu       $at, $t8, 0xE
    ctx->r1 = ctx->r24 < 0XE ? 1 : 0;
    // 0x8080011C: beq         $at, $zero, L_808004BC
    if (ctx->r1 == 0) {
        // 0x80800120: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808004BC;
    }
    // 0x80800120: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800124: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1532, 0XB10) << 16);
    // 0x80800128: addu        $at, $at, $t8
    gpr jr_addend_80800130 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8080012C: lw          $t8, 0xB10($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1532, 0XB10));
    // 0x80800130: jr          $t8
    // 0x80800134: nop

    switch (jr_addend_80800130 >> 2) {
        case 0: goto L_80800138; break;
        case 1: goto L_80800258; break;
        case 2: goto L_808001DC; break;
        case 3: goto L_808001C4; break;
        case 4: goto L_8080039C; break;
        case 5: goto L_808003F8; break;
        case 6: goto L_808004BC; break;
        case 7: goto L_808004BC; break;
        case 8: goto L_808004BC; break;
        case 9: goto L_808004BC; break;
        case 10: goto L_808004BC; break;
        case 11: goto L_808004BC; break;
        case 12: goto L_808004BC; break;
        case 13: goto L_80800480; break;
        default: switch_error(__func__, 0x80800130, 0x80800B10);
    }
    // 0x80800134: nop

L_80800138:
    // 0x80800138: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1532, 0XD00) << 16);
    // 0x8080013C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1532, 0XC00) << 16);
    // 0x80800140: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80800144: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800148: addiu       $a3, $a3, 0xC00
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1532, 0XC00));
    // 0x8080014C: addiu       $a2, $a2, 0xD00
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1532, 0XD00));
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800154: jal         0x8008A1F0
    // 0x80800158: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_5;
    // 0x80800158: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_5:
    // 0x8080015C: bne         $v0, $zero, L_808001BC
    if (ctx->r2 != 0) {
        // 0x80800160: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(1532, 0XD00) << 16);
            goto L_808001BC;
    }
    // 0x80800160: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1532, 0XD00) << 16);
    // 0x80800164: jal         0x800DA298
    // 0x80800168: lhu         $a0, 0xD00($a0)
    ctx->r4 = MEM_HU(ctx->r4, (int16_t)RELOC_LO16(1532, 0XD00));
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x80800168: lhu         $a0, 0xD00($a0)
    ctx->r4 = MEM_HU(ctx->r4, (int16_t)RELOC_LO16(1532, 0XD00));
    after_6:
    // 0x8080016C: beq         $v0, $zero, L_808001BC
    if (ctx->r2 == 0) {
        // 0x80800170: lw          $t0, 0x58($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X58);
            goto L_808001BC;
    }
    // 0x80800170: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80800174: beq         $t0, $zero, L_808001BC
    if (ctx->r8 == 0) {
        // 0x80800178: lui         $at, 0x42B4
        ctx->r1 = S32(0X42B4 << 16);
            goto L_808001BC;
    }
    // 0x80800178: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8080017C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800180: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x80800184: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800188: jal         0x800DC178
    // 0x8080018C: nop

    func_800DC178(rdram, ctx);
        goto after_7;
    // 0x8080018C: nop

    after_7:
    // 0x80800190: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800198: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8080019C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808001A0: jal         0x80102924
    // 0x808001A4: nop

    func_80102924(rdram, ctx);
        goto after_8;
    // 0x808001A4: nop

    after_8:
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001AC: jal         0x80102424
    // 0x808001B0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_9;
    // 0x808001B0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_9:
    // 0x808001B4: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x808001B8: sh          $zero, 0x14($v0)
    MEM_H(0X14, ctx->r2) = 0;
L_808001BC:
    // 0x808001BC: b           L_808004C0
    // 0x808001C0: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
        goto L_808004C0;
    // 0x808001C0: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
L_808001C4:
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x808001CC: jal         0x8010CE70
    // 0x808001D0: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    func_8010CE70(rdram, ctx);
        goto after_10;
    // 0x808001D0: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_10:
    // 0x808001D4: b           L_808004C0
    // 0x808001D8: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
        goto L_808004C0;
    // 0x808001D8: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
L_808001DC:
    // 0x808001DC: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x808001E0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E8: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    // 0x808001EC: jal         0x80102BF8
    // 0x808001F0: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    func_80102BF8(rdram, ctx);
        goto after_11;
    // 0x808001F0: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    after_11:
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F8: jal         0x80102CF4
    // 0x808001FC: lui         $a1, 0x4170
    ctx->r5 = S32(0X4170 << 16);
    func_80102CF4(rdram, ctx);
        goto after_12;
    // 0x808001FC: lui         $a1, 0x4170
    ctx->r5 = S32(0X4170 << 16);
    after_12:
    // 0x80800200: beq         $v0, $zero, L_8080022C
    if (ctx->r2 == 0) {
        // 0x80800204: lui         $at, 0x4100
        ctx->r1 = S32(0X4100 << 16);
            goto L_8080022C;
    }
    // 0x80800204: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80800208: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080020C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80800210: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800214: jal         0x800DC178
    // 0x80800218: nop

    func_800DC178(rdram, ctx);
        goto after_13;
    // 0x80800218: nop

    after_13:
    // 0x8080021C: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800224: jal         0x80102424
    // 0x80800228: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_14;
    // 0x80800228: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_14:
L_8080022C:
    // 0x8080022C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1532, 0XD00) << 16);
    // 0x80800230: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1532, 0XC00) << 16);
    // 0x80800234: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80800238: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8080023C: addiu       $a3, $a3, 0xC00
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1532, 0XC00));
    // 0x80800240: addiu       $a2, $a2, 0xD00
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1532, 0XD00));
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800248: jal         0x8008A1F0
    // 0x8080024C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_15;
    // 0x8080024C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_15:
    // 0x80800250: b           L_808004C0
    // 0x80800254: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
        goto L_808004C0;
    // 0x80800254: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
L_80800258:
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080025C: jal         0x80105230
    // 0x80800260: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80105230(rdram, ctx);
        goto after_16;
    // 0x80800260: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x80800264: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1532, 0XD00) << 16);
    // 0x80800268: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1532, 0XC00) << 16);
    // 0x8080026C: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80800270: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800274: addiu       $a3, $a3, 0xC00
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1532, 0XC00));
    // 0x80800278: addiu       $a2, $a2, 0xD00
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1532, 0XD00));
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800280: jal         0x8008A1F0
    // 0x80800284: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_17;
    // 0x80800284: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_17:
    // 0x80800288: bne         $v0, $zero, L_808004BC
    if (ctx->r2 != 0) {
        // 0x8080028C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004BC;
    }
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800290: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x80800294: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1532, 0XB48) << 16);
    // 0x80800298: lwc1        $f8, 0xB48($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1532, 0XB48));
    // 0x8080029C: lh          $a2, 0x14($t3)
    ctx->r6 = MEM_H(ctx->r11, 0X14);
    // 0x808002A0: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x808002A4: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x808002A8: addiu       $a1, $t3, 0x8
    ctx->r5 = ADD32(ctx->r11, 0X8);
    // 0x808002AC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808002B0: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x808002B4: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x808002B8: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x808002BC: jal         0x80089F88
    // 0x808002C0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    _subaddierouteDll_entrypoint_6(rdram, ctx);
        goto after_18;
    // 0x808002C0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_18:
    // 0x808002C4: jal         0x80089F78
    // 0x808002C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_19;
    // 0x808002C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x808002CC: beq         $v0, $zero, L_80800304
    if (ctx->r2 == 0) {
        // 0x808002D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800304;
    }
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002D4: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x808002D8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808002DC: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x808002E0: lw          $a3, 0x54($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X54);
    // 0x808002E4: addiu       $t6, $zero, 0x4000
    ctx->r14 = ADD32(0, 0X4000);
    // 0x808002E8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x808002EC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x808002F0: jal         0x80089F90
    // 0x808002F4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    _subaddierouteDll_entrypoint_7(rdram, ctx);
        goto after_20;
    // 0x808002F4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_20:
    // 0x808002F8: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x808002FC: lhu         $t8, 0xE($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0XE);
    // 0x80800300: sh          $t8, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r24;
L_80800304:
    // 0x80800304: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80800308: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8080030C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800310: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    // 0x80800314: jal         0x80102BF8
    // 0x80800318: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    func_80102BF8(rdram, ctx);
        goto after_21;
    // 0x80800318: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    after_21:
    // 0x8080031C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800320: jal         0x8010B990
    // 0x80800324: addiu       $a1, $zero, 0x1305
    ctx->r5 = ADD32(0, 0X1305);
    func_8010B990(rdram, ctx);
        goto after_22;
    // 0x80800324: addiu       $a1, $zero, 0x1305
    ctx->r5 = ADD32(0, 0X1305);
    after_22:
    // 0x80800328: andi        $t9, $v0, 0x4
    ctx->r25 = ctx->r2 & 0X4;
    // 0x8080032C: beq         $t9, $zero, L_8080036C
    if (ctx->r25 == 0) {
        // 0x80800330: lw          $t1, 0x58($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X58);
            goto L_8080036C;
    }
    // 0x80800330: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x80800334: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800338: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080033C: lwc1        $f16, 0x48($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800344: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80800348: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8080034C: jal         0x80102924
    // 0x80800350: nop

    func_80102924(rdram, ctx);
        goto after_23;
    // 0x80800350: nop

    after_23:
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800358: jal         0x80102424
    // 0x8080035C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_24;
    // 0x8080035C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_24:
    // 0x80800360: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x80800364: b           L_808004BC
    // 0x80800368: sh          $zero, 0x14($t0)
    MEM_H(0X14, ctx->r8) = 0;
        goto L_808004BC;
    // 0x80800368: sh          $zero, 0x14($t0)
    MEM_H(0X14, ctx->r8) = 0;
L_8080036C:
    // 0x8080036C: beq         $t1, $zero, L_808004BC
    if (ctx->r9 == 0) {
        // 0x80800370: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004BC;
    }
    // 0x80800370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800374: jal         0x80102424
    // 0x80800378: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_25;
    // 0x80800378: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_25:
    // 0x8080037C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800380: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800384: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80800388: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080038C: jal         0x800DC178
    // 0x80800390: nop

    func_800DC178(rdram, ctx);
        goto after_26;
    // 0x80800390: nop

    after_26:
    // 0x80800394: b           L_808004BC
    // 0x80800398: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
        goto L_808004BC;
    // 0x80800398: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_8080039C:
    // 0x8080039C: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x808003A0: jal         0x800EE88C
    // 0x808003A4: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    func_800EE88C(rdram, ctx);
        goto after_27;
    // 0x808003A4: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    after_27:
    // 0x808003A8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808003AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808003B0: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x808003B4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808003B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003BC: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x808003C0: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    // 0x808003C4: jal         0x801028C4
    // 0x808003C8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_801028C4(rdram, ctx);
        goto after_28;
    // 0x808003C8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_28:
    // 0x808003CC: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x808003D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808003D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003D8: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x808003DC: nop

    // 0x808003E0: bc1fl       L_808004C0
    if (!c1cs) {
        // 0x808003E4: lw          $v0, 0x5C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X5C);
            goto L_808004C0;
    }
    goto skip_0;
    // 0x808003E4: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    skip_0:
    // 0x808003E8: jal         0x80102424
    // 0x808003EC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_29;
    // 0x808003EC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_29:
    // 0x808003F0: b           L_808004C0
    // 0x808003F4: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
        goto L_808004C0;
    // 0x808003F4: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
L_808003F8:
    // 0x808003F8: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x808003FC: jal         0x800EE88C
    // 0x80800400: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    func_800EE88C(rdram, ctx);
        goto after_30;
    // 0x80800400: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    after_30:
    // 0x80800404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800408: jal         0x80102D78
    // 0x8080040C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_80102D78(rdram, ctx);
        goto after_31;
    // 0x8080040C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_31:
    // 0x80800410: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80800414: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800418: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8080041C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800420: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    // 0x80800424: jal         0x80102BF8
    // 0x80800428: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    func_80102BF8(rdram, ctx);
        goto after_32;
    // 0x80800428: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    after_32:
    // 0x8080042C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800430: jal         0x8010B990
    // 0x80800434: addiu       $a1, $zero, 0x1005
    ctx->r5 = ADD32(0, 0X1005);
    func_8010B990(rdram, ctx);
        goto after_33;
    // 0x80800434: addiu       $a1, $zero, 0x1005
    ctx->r5 = ADD32(0, 0X1005);
    after_33:
    // 0x80800438: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8080043C: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x80800440: jal         0x800F0064
    // 0x80800444: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    func_800F0064(rdram, ctx);
        goto after_34;
    // 0x80800444: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_34:
    // 0x80800448: beq         $v0, $zero, L_808004BC
    if (ctx->r2 == 0) {
        // 0x8080044C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004BC;
    }
    // 0x8080044C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800450: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x80800454: lw          $a2, 0x24($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X24);
    // 0x80800458: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8080045C: jal         0x801058C4
    // 0x80800460: lh          $a1, 0x6($t2)
    ctx->r5 = MEM_H(ctx->r10, 0X6);
    func_801058C4(rdram, ctx);
        goto after_35;
    // 0x80800460: lh          $a1, 0x6($t2)
    ctx->r5 = MEM_H(ctx->r10, 0X6);
    after_35:
    // 0x80800464: jal         0x80105BAC
    // 0x80800468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105BAC(rdram, ctx);
        goto after_36;
    // 0x80800468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x8080046C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800470: jal         0x80102424
    // 0x80800474: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80102424(rdram, ctx);
        goto after_37;
    // 0x80800474: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_37:
    // 0x80800478: b           L_808004C0
    // 0x8080047C: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
        goto L_808004C0;
    // 0x8080047C: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
L_80800480:
    // 0x80800480: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x80800484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800488: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8080048C: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    // 0x80800490: jal         0x8008A050
    // 0x80800494: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    _subaddiefx_entrypoint_0(rdram, ctx);
        goto after_38;
    // 0x80800494: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    after_38:
    // 0x80800498: jal         0x80101DDC
    // 0x8080049C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_39;
    // 0x8080049C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_39:
    // 0x808004A0: beq         $v0, $zero, L_808004BC
    if (ctx->r2 == 0) {
        // 0x808004A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004BC;
    }
    // 0x808004A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004A8: jal         0x8008A058
    // 0x808004AC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    _subaddiefx_entrypoint_1(rdram, ctx);
        goto after_40;
    // 0x808004AC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_40:
    // 0x808004B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004B4: jal         0x80102424
    // 0x808004B8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_41;
    // 0x808004B8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_41:
L_808004BC:
    // 0x808004BC: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
L_808004C0:
    // 0x808004C0: addiu       $t3, $s0, 0x4
    ctx->r11 = ADD32(ctx->r16, 0X4);
    // 0x808004C4: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x808004C8: lw          $t4, 0x14($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X14);
    // 0x808004CC: sll         $t6, $t4, 17
    ctx->r14 = S32(ctx->r12 << 17);
    // 0x808004D0: bgezl       $t6, L_8080051C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x808004D4: lh          $t7, 0x16($v0)
        ctx->r15 = MEM_H(ctx->r2, 0X16);
            goto L_8080051C;
    }
    goto skip_1;
    // 0x808004D4: lh          $t7, 0x16($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X16);
    skip_1:
    // 0x808004D8: jal         0x801022E4
    // 0x808004DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801022E4(rdram, ctx);
        goto after_42;
    // 0x808004DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
    // 0x808004E0: addiu       $at, $zero, 0x243
    ctx->r1 = ADD32(0, 0X243);
    // 0x808004E4: bne         $v0, $at, L_80800548
    if (ctx->r2 != ctx->r1) {
        // 0x808004E8: lw          $a0, 0x5C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X5C);
            goto L_80800548;
    }
    // 0x808004E8: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x808004EC: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x808004F0: jal         0x800D9154
    // 0x808004F4: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    func_800D9154(rdram, ctx);
        goto after_43;
    // 0x808004F4: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_43:
    // 0x808004F8: beq         $v0, $zero, L_80800548
    if (ctx->r2 == 0) {
        // 0x808004FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800548;
    }
    // 0x808004FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800500: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1532, 0XC24) << 16);
    // 0x80800504: addiu       $a2, $a2, 0xC24
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1532, 0XC24));
    // 0x80800508: jal         0x80089D18
    // 0x8080050C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_44;
    // 0x8080050C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_44:
    // 0x80800510: b           L_8080054C
    // 0x80800514: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
        goto L_8080054C;
    // 0x80800514: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800518: lh          $t7, 0x16($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X16);
L_8080051C:
    // 0x8080051C: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
    // 0x80800520: bgezl       $t7, L_8080054C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80800524: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_8080054C;
    }
    goto skip_2;
    // 0x80800524: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    skip_2:
    // 0x80800528: jal         0x800D9154
    // 0x8080052C: lui         $a1, 0x4020
    ctx->r5 = S32(0X4020 << 16);
    func_800D9154(rdram, ctx);
        goto after_45;
    // 0x8080052C: lui         $a1, 0x4020
    ctx->r5 = S32(0X4020 << 16);
    after_45:
    // 0x80800530: beq         $v0, $zero, L_80800548
    if (ctx->r2 == 0) {
        // 0x80800534: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800548;
    }
    // 0x80800534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800538: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1532, 0XC18) << 16);
    // 0x8080053C: addiu       $a2, $a2, 0xC18
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1532, 0XC18));
    // 0x80800540: jal         0x80089D18
    // 0x80800544: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_46;
    // 0x80800544: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_46:
L_80800548:
    // 0x80800548: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
L_8080054C:
    // 0x8080054C: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x80800550: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    // 0x80800554: jal         0x80089F18
    // 0x80800558: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    _sudeflect_entrypoint_0(rdram, ctx);
        goto after_47;
    // 0x80800558: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_47:
    // 0x8080055C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800560: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800564: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80800568: jr          $ra
    // 0x8080056C: nop

    return;
    // 0x8080056C: nop

;}
RECOMP_FUNC void func_808000D4_chicestationbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808000D8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000DC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000E0: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x808000E4: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x808000E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000EC: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x808000F0: bne         $t7, $at, L_80800108
    if (ctx->r15 != ctx->r1) {
        // 0x808000F4: lwc1        $f0, 0x48($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X48);
            goto L_80800108;
    }
    // 0x808000F4: lwc1        $f0, 0x48($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X48);
    // 0x808000F8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808000FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800100: nop

    // 0x80800104: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
L_80800108:
    // 0x80800108: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8080010C: jal         0x800EFD24
    // 0x80800110: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x80800110: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80800114: jal         0x80103014
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103014(rdram, ctx);
        goto after_1;
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080011C: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800120: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x80800124: addiu       $t9, $zero, 0x1CF
    ctx->r25 = ADD32(0, 0X1CF);
    // 0x80800128: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080012C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80800130: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800138: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8080013C: jal         0x80086898
    // 0x80800140: lui         $a3, 0x4416
    ctx->r7 = S32(0X4416 << 16);
    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800140: lui         $a3, 0x4416
    ctx->r7 = S32(0X4416 << 16);
    after_2:
    // 0x80800144: beq         $v0, $zero, L_808001A4
    if (ctx->r2 == 0) {
        // 0x80800148: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001A4;
    }
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080014C: jal         0x800868A8
    // 0x80800150: lui         $a1, 0x4060
    ctx->r5 = S32(0X4060 << 16);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_3;
    // 0x80800150: lui         $a1, 0x4060
    ctx->r5 = S32(0X4060 << 16);
    after_3:
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800158: jal         0x800868B0
    // 0x8080015C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    _chdoormake_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x8080015C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_4:
    // 0x80800160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800168: jal         0x800868E0
    // 0x8080016C: addiu       $a2, $zero, 0x48
    ctx->r6 = ADD32(0, 0X48);
    _chdoormake_entrypoint_12(rdram, ctx);
        goto after_5;
    // 0x8080016C: addiu       $a2, $zero, 0x48
    ctx->r6 = ADD32(0, 0X48);
    after_5:
    // 0x80800170: lhu         $t0, 0x76($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X76);
    // 0x80800174: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080017C: srl         $t1, $t0, 7
    ctx->r9 = S32(U32(ctx->r8) >> 7);
    // 0x80800180: bne         $t1, $at, L_808001A4
    if (ctx->r9 != ctx->r1) {
        // 0x80800184: nop
    
            goto L_808001A4;
    }
    // 0x80800184: nop

    // 0x80800188: jal         0x800868C0
    // 0x8080018C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x8080018C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_6:
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800194: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800198: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080019C: jal         0x800868C8
    // 0x808001A0: addiu       $a3, $zero, 0x900
    ctx->r7 = ADD32(0, 0X900);
    _chdoormake_entrypoint_9(rdram, ctx);
        goto after_7;
    // 0x808001A0: addiu       $a3, $zero, 0x900
    ctx->r7 = ADD32(0, 0X900);
    after_7:
L_808001A4:
    // 0x808001A4: jal         0x800DA298
    // 0x808001A8: addiu       $a0, $zero, 0x1CF
    ctx->r4 = ADD32(0, 0X1CF);
    func_800DA298(rdram, ctx);
        goto after_8;
    // 0x808001A8: addiu       $a0, $zero, 0x1CF
    ctx->r4 = ADD32(0, 0X1CF);
    after_8:
    // 0x808001AC: beql        $v0, $zero, L_808001D0
    if (ctx->r2 == 0) {
        // 0x808001B0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808001D0;
    }
    goto skip_0;
    // 0x808001B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808001B4: jal         0x80088840
    // 0x808001B8: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_9;
    // 0x808001B8: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    after_9:
    // 0x808001BC: bnel        $v0, $zero, L_808001D0
    if (ctx->r2 != 0) {
        // 0x808001C0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808001D0;
    }
    goto skip_1;
    // 0x808001C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x808001C4: jal         0x800FFAB0
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_10;
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808001CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001D0:
    // 0x808001D0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808001D4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808001D8: jr          $ra
    // 0x808001DC: nop

    return;
    // 0x808001DC: nop

;}
RECOMP_FUNC void _chbanjocurrent_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085AE8: syscall     192
    recomp_syscall_handler(rdram, ctx, 0x80085AE8);
    return;
    // 0x80085AEC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void baanim_setDurationRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C9BC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8008C9C0: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8008C9C4: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8008C9C8: swc1        $f12, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f12.u32l;
    // 0x8008C9CC: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x8008C9D0: jr          $ra
    // 0x8008C9D4: swc1        $f14, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f14.u32l;
    return;
    // 0x8008C9D4: swc1        $f14, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f14.u32l;
;}
RECOMP_FUNC void chbilldrillplate_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1192, 0X1124) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x1124
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1192, 0X1124));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x1124
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1192, 0X1124));
;}
RECOMP_FUNC void bskazstilt_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808005D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808005DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808005E0: addiu       $a1, $zero, 0x280
    ctx->r5 = ADD32(0, 0X280);
    // 0x808005E4: jal         0x8008CB3C
    // 0x808005E8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_0;
    // 0x808005E8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_0:
    // 0x808005EC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x808005F0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808005F4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808005F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808005FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800600: jal         0x8009FFD8
    // 0x80800604: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x80800604: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x80800608: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(292, 0X11F0) << 16);
    // 0x8080060C: lwc1        $f4, 0x11F0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(292, 0X11F0));
    // 0x80800610: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800614: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    // 0x80800618: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    // 0x8080061C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800620: jal         0x8008C9F0
    // 0x80800624: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_2;
    // 0x80800624: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80800628: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080062C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800630: jr          $ra
    // 0x80800634: nop

    return;
    // 0x80800634: nop

;}
RECOMP_FUNC void bamovegoto_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800168: lw          $t6, 0xC8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC8);
    // 0x8080016C: lbu         $v0, 0x54($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X54);
    // 0x80800170: xori        $t7, $v0, 0x6
    ctx->r15 = ctx->r2 ^ 0X6;
    // 0x80800174: jr          $ra
    // 0x80800178: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
    return;
    // 0x80800178: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void chweldarbossfusebox_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1380, 0X700) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0x700
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1380, 0X700));
    return;
    // 0x80800020: addiu       $v0, $v0, 0x700
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1380, 0X700));
;}
RECOMP_FUNC void _chtemplebossdoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087360: syscall     554
    recomp_syscall_handler(rdram, ctx, 0x80087360);
    return;
    // 0x80087364: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8009EADC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EADC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009EAE0: jr          $ra
    // 0x8009EAE4: sw          $a0, 0x7080($at)
    MEM_W(0X7080, ctx->r1) = ctx->r4;
    return;
    // 0x8009EAE4: sw          $a0, 0x7080($at)
    MEM_W(0X7080, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_808008D4_bskaztorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008D4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808008D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808008DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808008E0: jal         0x8009E6EC
    // 0x808008E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x808008E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808008E8: slti        $at, $v0, 0x52
    ctx->r1 = SIGNED(ctx->r2) < 0X52 ? 1 : 0;
    // 0x808008EC: bne         $at, $zero, L_8080091C
    if (ctx->r1 != 0) {
        // 0x808008F0: addiu       $t6, $v0, -0x1F
        ctx->r14 = ADD32(ctx->r2, -0X1F);
            goto L_8080091C;
    }
    // 0x808008F0: addiu       $t6, $v0, -0x1F
    ctx->r14 = ADD32(ctx->r2, -0X1F);
    // 0x808008F4: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x808008F8: beq         $v0, $at, L_808009EC
    if (ctx->r2 == ctx->r1) {
        // 0x808008FC: addiu       $at, $zero, 0x6F
        ctx->r1 = ADD32(0, 0X6F);
            goto L_808009EC;
    }
    // 0x808008FC: addiu       $at, $zero, 0x6F
    ctx->r1 = ADD32(0, 0X6F);
    // 0x80800900: beq         $v0, $at, L_808009C8
    if (ctx->r2 == ctx->r1) {
        // 0x80800904: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009C8;
    }
    // 0x80800904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800908: addiu       $at, $zero, 0x88
    ctx->r1 = ADD32(0, 0X88);
    // 0x8080090C: beq         $v0, $at, L_80800A00
    if (ctx->r2 == ctx->r1) {
        // 0x80800910: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80800A00;
    }
    // 0x80800910: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800914: b           L_80800A18
    // 0x80800918: nop

        goto L_80800A18;
    // 0x80800918: nop

L_8080091C:
    // 0x8080091C: slti        $at, $v0, 0x4F
    ctx->r1 = SIGNED(ctx->r2) < 0X4F ? 1 : 0;
    // 0x80800920: bne         $at, $zero, L_80800940
    if (ctx->r1 != 0) {
        // 0x80800924: addiu       $at, $zero, 0x50
        ctx->r1 = ADD32(0, 0X50);
            goto L_80800940;
    }
    // 0x80800924: addiu       $at, $zero, 0x50
    ctx->r1 = ADD32(0, 0X50);
    // 0x80800928: beq         $v0, $at, L_8080097C
    if (ctx->r2 == ctx->r1) {
        // 0x8080092C: addiu       $at, $zero, 0x51
        ctx->r1 = ADD32(0, 0X51);
            goto L_8080097C;
    }
    // 0x8080092C: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x80800930: beql        $v0, $at, L_808009F0
    if (ctx->r2 == ctx->r1) {
        // 0x80800934: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009F0;
    }
    goto skip_0;
    // 0x80800934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800938: b           L_80800A18
    // 0x8080093C: nop

        goto L_80800A18;
    // 0x8080093C: nop

L_80800940:
    // 0x80800940: slti        $at, $v0, 0x2F
    ctx->r1 = SIGNED(ctx->r2) < 0X2F ? 1 : 0;
    // 0x80800944: bne         $at, $zero, L_8080095C
    if (ctx->r1 != 0) {
        // 0x80800948: addiu       $at, $zero, 0x4E
        ctx->r1 = ADD32(0, 0X4E);
            goto L_8080095C;
    }
    // 0x80800948: addiu       $at, $zero, 0x4E
    ctx->r1 = ADD32(0, 0X4E);
    // 0x8080094C: beql        $v0, $at, L_808009F0
    if (ctx->r2 == ctx->r1) {
        // 0x80800950: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009F0;
    }
    goto skip_1;
    // 0x80800950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80800954: b           L_80800A18
    // 0x80800958: nop

        goto L_80800A18;
    // 0x80800958: nop

L_8080095C:
    // 0x8080095C: sltiu       $at, $t6, 0x10
    ctx->r1 = ctx->r14 < 0X10 ? 1 : 0;
    // 0x80800960: beq         $at, $zero, L_80800A18
    if (ctx->r1 == 0) {
        // 0x80800964: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800A18;
    }
    // 0x80800964: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800968: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(296, 0X16AC) << 16);
    // 0x8080096C: addu        $at, $at, $t6
    gpr jr_addend_80800974 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800970: lw          $t6, 0x16AC($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(296, 0X16AC));
    // 0x80800974: jr          $t6
    // 0x80800978: nop

    switch (jr_addend_80800974 >> 2) {
        case 0: goto L_808009EC; break;
        case 1: goto L_808009EC; break;
        case 2: goto L_808009D8; break;
        case 3: goto L_80800A18; break;
        case 4: goto L_80800A18; break;
        case 5: goto L_808009EC; break;
        case 6: goto L_80800A18; break;
        case 7: goto L_80800A18; break;
        case 8: goto L_80800A18; break;
        case 9: goto L_80800A18; break;
        case 10: goto L_80800A18; break;
        case 11: goto L_80800A18; break;
        case 12: goto L_80800A18; break;
        case 13: goto L_80800A18; break;
        case 14: goto L_808009EC; break;
        case 15: goto L_808009EC; break;
        default: switch_error(__func__, 0x80800974, 0x808016AC);
    }
    // 0x80800978: nop

L_8080097C:
    // 0x8080097C: jal         0x800878A0
    // 0x80800980: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    _plsu_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800980: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_1:
    // 0x80800984: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800988: jal         0x800F7B9C
    // 0x8080098C: addiu       $a1, $zero, 0x71
    ctx->r5 = ADD32(0, 0X71);
    func_800F7B9C(rdram, ctx);
        goto after_2;
    // 0x8080098C: addiu       $a1, $zero, 0x71
    ctx->r5 = ADD32(0, 0X71);
    after_2:
    // 0x80800990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800994: jal         0x80099A7C
    // 0x80800998: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_80099A7C(rdram, ctx);
        goto after_3;
    // 0x80800998: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_3:
    // 0x8080099C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009A0: jal         0x800F452C
    // 0x808009A4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800F452C(rdram, ctx);
        goto after_4;
    // 0x808009A4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_4:
    // 0x808009A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009AC: jal         0x8009E5C8
    // 0x808009B0: addiu       $a1, $zero, 0x158
    ctx->r5 = ADD32(0, 0X158);
    bs_setState(rdram, ctx);
        goto after_5;
    // 0x808009B0: addiu       $a1, $zero, 0x158
    ctx->r5 = ADD32(0, 0X158);
    after_5:
    // 0x808009B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009B8: jal         0x8009E830
    // 0x808009BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_6;
    // 0x808009BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x808009C0: b           L_80800A24
    // 0x808009C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800A24;
    // 0x808009C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808009C8:
    // 0x808009C8: jal         0x8009E830
    // 0x808009CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009E830(rdram, ctx);
        goto after_7;
    // 0x808009CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x808009D0: b           L_80800A24
    // 0x808009D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800A24;
    // 0x808009D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808009D8:
    // 0x808009D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009DC: jal         0x8080088C
    // 0x808009E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8080088C_bskaztorpedo(rdram, ctx);
        goto after_8;
    // 0x808009E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x808009E4: b           L_80800A24
    // 0x808009E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800A24;
    // 0x808009E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808009EC:
    // 0x808009EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808009F0:
    // 0x808009F0: jal         0x8080088C
    // 0x808009F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8080088C_bskaztorpedo(rdram, ctx);
        goto after_9;
    // 0x808009F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x808009F8: b           L_80800A24
    // 0x808009FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800A24;
    // 0x808009FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800A00:
    // 0x80800A00: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
    // 0x80800A04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A08: jal         0x8009E830
    // 0x80800A0C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_10;
    // 0x80800A0C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_10:
    // 0x80800A10: b           L_80800A24
    // 0x80800A14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800A24;
    // 0x80800A14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800A18:
    // 0x80800A18: jal         0x80099B94
    // 0x80800A1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099B94(rdram, ctx);
        goto after_11;
    // 0x80800A1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800A20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800A24:
    // 0x80800A24: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800A28: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800A2C: jr          $ra
    // 0x80800A30: nop

    return;
    // 0x80800A30: nop

;}
RECOMP_FUNC void _bamovespline_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084EB8: syscall     140
    recomp_syscall_handler(rdram, ctx, 0x80084EB8);
    return;
    // 0x80084EBC: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void chflamer_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808006A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006AC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808006B0: jal         0x80106790
    // 0x808006B4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808006B4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808006B8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808006BC: lw          $t6, 0x64($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X64);
    // 0x808006C0: addiu       $a0, $zero, 0x3A2
    ctx->r4 = ADD32(0, 0X3A2);
    // 0x808006C4: sll         $t8, $t6, 14
    ctx->r24 = S32(ctx->r14 << 14);
    // 0x808006C8: bltzl       $t8, L_8080072C
    if (SIGNED(ctx->r24) < 0) {
        // 0x808006CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080072C;
    }
    goto skip_0;
    // 0x808006CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808006D0: jal         0x801084B0
    // 0x808006D4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_801084B0(rdram, ctx);
        goto after_1;
    // 0x808006D4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x808006D8: beq         $v0, $zero, L_80800728
    if (ctx->r2 == 0) {
        // 0x808006DC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800728;
    }
    // 0x808006DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808006E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808006E4: jal         0x80100094
    // 0x808006E8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x808006E8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x808006EC: addiu       $a0, $v0, 0x1B4
    ctx->r4 = ADD32(ctx->r2, 0X1B4);
    // 0x808006F0: jal         0x8008A028
    // 0x808006F4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _subaddielink_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x808006F4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x808006F8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808006FC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800700: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80800704: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800708: jal         0x800DC178
    // 0x8080070C: nop

    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x8080070C: nop

    after_4:
    // 0x80800710: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800714: lbu         $t9, 0x72($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X72);
    // 0x80800718: swc1        $f0, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->f0.u32l;
    // 0x8080071C: andi        $t0, $t9, 0xFF03
    ctx->r8 = ctx->r25 & 0XFF03;
    // 0x80800720: ori         $t1, $t0, 0x4
    ctx->r9 = ctx->r8 | 0X4;
    // 0x80800724: sb          $t1, 0x72($a2)
    MEM_B(0X72, ctx->r6) = ctx->r9;
L_80800728:
    // 0x80800728: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080072C:
    // 0x8080072C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800730: jr          $ra
    // 0x80800734: nop

    return;
    // 0x80800734: nop

;}
RECOMP_FUNC void func_80806408_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806408: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080640C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80806410: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80806414: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80806418: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8080641C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80806420: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80806424: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80806428: jal         0x80088150
    // 0x8080642C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    _gcfrontend_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x8080642C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x80806430: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80806434: jal         0x80088158
    // 0x80806438: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    _gcfrontend_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80806438: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_1:
    // 0x8080643C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80806440: lw          $a0, 0x30($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X30);
    // 0x80806444: jal         0x808031F4
    // 0x80806448: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_808031F4_chgameselect(rdram, ctx);
        goto after_2;
    // 0x80806448: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_2:
    // 0x8080644C: blez        $s3, L_808064A0
    if (SIGNED(ctx->r19) <= 0) {
        // 0x80806450: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_808064A0;
    }
    // 0x80806450: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80806454: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
L_80806458:
    // 0x80806458: jal         0x80088148
    // 0x8080645C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcfrontend_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x8080645C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80806460: beql        $v0, $zero, L_80806498
    if (ctx->r2 == 0) {
        // 0x80806464: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80806498;
    }
    goto skip_0;
    // 0x80806464: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x80806468: jal         0x800AA274
    // 0x8080646C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800AA274(rdram, ctx);
        goto after_4;
    // 0x8080646C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80806470: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80806474: jal         0x800881A0
    // 0x80806478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcfrontend_entrypoint_14(rdram, ctx);
        goto after_5;
    // 0x80806478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080647C: lw          $a0, 0x30($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X30);
    // 0x80806480: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80806484: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80806488: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8080648C: jal         0x80803248
    // 0x80806490: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    func_80803248_chgameselect(rdram, ctx);
        goto after_6;
    // 0x80806490: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_6:
    // 0x80806494: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80806498:
    // 0x80806498: bne         $s1, $s3, L_80806458
    if (ctx->r17 != ctx->r19) {
        // 0x8080649C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80806458;
    }
    // 0x8080649C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_808064A0:
    // 0x808064A0: lw          $a0, 0x30($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X30);
    // 0x808064A4: addiu       $a1, $zero, 0x18E4
    ctx->r5 = ADD32(0, 0X18E4);
    // 0x808064A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808064AC: jal         0x808032CC
    // 0x808064B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_808032CC_chgameselect(rdram, ctx);
        goto after_7;
    // 0x808064B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
    // 0x808064B4: lw          $a0, 0x2C($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X2C);
    // 0x808064B8: jal         0x808026C8
    // 0x808064BC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808026C8_chgameselect(rdram, ctx);
        goto after_8;
    // 0x808064BC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_8:
    // 0x808064C0: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x808064C4: sw          $t6, 0x18($s4)
    MEM_W(0X18, ctx->r20) = ctx->r14;
    // 0x808064C8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x808064CC: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x808064D0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x808064D4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x808064D8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x808064DC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808064E0: jr          $ra
    // 0x808064E4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x808064E4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80801C50_chfactoryrobot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801C54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801C58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801C5C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1140, 0X2AD4) << 16);
    // 0x80801C60: jal         0x80101074
    // 0x80801C64: addiu       $a0, $a0, 0x2AD4
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1140, 0X2AD4));
    func_80101074(rdram, ctx);
        goto after_0;
    // 0x80801C64: addiu       $a0, $a0, 0x2AD4
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1140, 0X2AD4));
    after_0:
    // 0x80801C68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801C6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801C70: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80801C74: jr          $ra
    // 0x80801C78: nop

    return;
    // 0x80801C78: nop

;}
RECOMP_FUNC void bsstonehead_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808010A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808010A8: jal         0x80800000
    // 0x808010AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800000_bsstonehead(rdram, ctx);
        goto after_0;
    // 0x808010AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808010B0: jal         0x80090A2C
    // 0x808010B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80090A2C(rdram, ctx);
        goto after_1;
    // 0x808010B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808010B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808010BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808010C0: jr          $ra
    // 0x808010C4: nop

    return;
    // 0x808010C4: nop

;}
RECOMP_FUNC void func_808011DC_chpotogoldgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808011E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808011E4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x808011E8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x808011EC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808011F0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808011F4: jal         0x80100094
    // 0x808011F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808011F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808011FC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80801200: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80801204: addiu       $s2, $v0, 0xC
    ctx->r18 = ADD32(ctx->r2, 0XC);
    // 0x80801208: addiu       $s3, $zero, 0xF0
    ctx->r19 = ADD32(0, 0XF0);
L_8080120C:
    // 0x8080120C: sb          $zero, 0x14($s0)
    MEM_B(0X14, ctx->r16) = 0;
    // 0x80801210: jal         0x8008A020
    // 0x80801214: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    _subaddielink_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80801214: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x80801218: addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
    // 0x8080121C: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x80801220: bne         $s1, $s3, L_8080120C
    if (ctx->r17 != ctx->r19) {
        // 0x80801224: addiu       $s2, $s2, 0x18
        ctx->r18 = ADD32(ctx->r18, 0X18);
            goto L_8080120C;
    }
    // 0x80801224: addiu       $s2, $s2, 0x18
    ctx->r18 = ADD32(ctx->r18, 0X18);
    // 0x80801228: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080122C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801230: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801234: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80801238: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8080123C: jr          $ra
    // 0x80801240: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80801240: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _bapreload_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084F40: syscall     143
    recomp_syscall_handler(rdram, ctx, 0x80084F40);
    return;
    // 0x80084F44: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8008160C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008160C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80081610: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80081614: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80081618: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8008161C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80081620: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80081624: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80081628: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8008162C: jal         0x800A9F30
    // 0x80081630: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_800A9F30(rdram, ctx);
        goto after_0;
    // 0x80081630: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x80081634: lui         $s5, 0x8011
    ctx->r21 = S32(0X8011 << 16);
    // 0x80081638: addiu       $s5, $s5, 0x7C60
    ctx->r21 = ADD32(ctx->r21, 0X7C60);
    // 0x8008163C: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
    // 0x80081640: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80081644: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80081648: blez        $t6, L_80081700
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8008164C: lui         $s1, 0x8012
        ctx->r17 = S32(0X8012 << 16);
            goto L_80081700;
    }
    // 0x8008164C: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80081650: addiu       $s1, $s1, 0x6738
    ctx->r17 = ADD32(ctx->r17, 0X6738);
    // 0x80081654: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
L_80081658:
    // 0x80081658: bne         $s4, $s2, L_8008169C
    if (ctx->r20 != ctx->r18) {
        // 0x8008165C: lw          $a0, 0x0($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X0);
            goto L_8008169C;
    }
    // 0x8008165C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80081660: lh          $t7, 0x32($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X32);
    // 0x80081664: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x80081668: bnel        $at, $zero, L_800816EC
    if (ctx->r1 != 0) {
        // 0x8008166C: lw          $t2, 0x0($s5)
        ctx->r10 = MEM_W(ctx->r21, 0X0);
            goto L_800816EC;
    }
    goto skip_0;
    // 0x8008166C: lw          $t2, 0x0($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X0);
    skip_0:
    // 0x80081670: lbu         $t8, 0xF($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XF);
    // 0x80081674: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x80081678: beql        $t9, $zero, L_800816EC
    if (ctx->r25 == 0) {
        // 0x8008167C: lw          $t2, 0x0($s5)
        ctx->r10 = MEM_W(ctx->r21, 0X0);
            goto L_800816EC;
    }
    goto skip_1;
    // 0x8008167C: lw          $t2, 0x0($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X0);
    skip_1:
    // 0x80081680: jal         0x800819E4
    // 0x80081684: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ovl_unload(rdram, ctx);
        goto after_1;
    // 0x80081684: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80081688: beql        $v0, $zero, L_800816EC
    if (ctx->r2 == 0) {
        // 0x8008168C: lw          $t2, 0x0($s5)
        ctx->r10 = MEM_W(ctx->r21, 0X0);
            goto L_800816EC;
    }
    goto skip_2;
    // 0x8008168C: lw          $t2, 0x0($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X0);
    skip_2:
    // 0x80081690: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80081694: b           L_800816E8
    // 0x80081698: addiu       $s1, $s1, -0x4
    ctx->r17 = ADD32(ctx->r17, -0X4);
        goto L_800816E8;
    // 0x80081698: addiu       $s1, $s1, -0x4
    ctx->r17 = ADD32(ctx->r17, -0X4);
L_8008169C:
    // 0x8008169C: lh          $t0, 0x32($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X32);
    // 0x800816A0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800816A4: sh          $t1, 0x32($a0)
    MEM_H(0X32, ctx->r4) = ctx->r9;
    // 0x800816A8: lh          $v0, 0x32($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X32);
    // 0x800816AC: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x800816B0: bnel        $at, $zero, L_800816EC
    if (ctx->r1 != 0) {
        // 0x800816B4: lw          $t2, 0x0($s5)
        ctx->r10 = MEM_W(ctx->r21, 0X0);
            goto L_800816EC;
    }
    goto skip_3;
    // 0x800816B4: lw          $t2, 0x0($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X0);
    skip_3:
    // 0x800816B8: bne         $s3, $zero, L_800816C4
    if (ctx->r19 != 0) {
        // 0x800816BC: slti        $at, $v0, 0x6
        ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
            goto L_800816C4;
    }
    // 0x800816BC: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x800816C0: beq         $at, $zero, L_800816D0
    if (ctx->r1 == 0) {
        // 0x800816C4: slti        $at, $v0, 0x1F
        ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
            goto L_800816D0;
    }
L_800816C4:
    // 0x800816C4: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x800816C8: bnel        $at, $zero, L_800816EC
    if (ctx->r1 != 0) {
        // 0x800816CC: lw          $t2, 0x0($s5)
        ctx->r10 = MEM_W(ctx->r21, 0X0);
            goto L_800816EC;
    }
    goto skip_4;
    // 0x800816CC: lw          $t2, 0x0($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X0);
    skip_4:
L_800816D0:
    // 0x800816D0: jal         0x800819E4
    // 0x800816D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ovl_unload(rdram, ctx);
        goto after_2;
    // 0x800816D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x800816D8: beql        $v0, $zero, L_800816EC
    if (ctx->r2 == 0) {
        // 0x800816DC: lw          $t2, 0x0($s5)
        ctx->r10 = MEM_W(ctx->r21, 0X0);
            goto L_800816EC;
    }
    goto skip_5;
    // 0x800816DC: lw          $t2, 0x0($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X0);
    skip_5:
    // 0x800816E0: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800816E4: addiu       $s1, $s1, -0x4
    ctx->r17 = ADD32(ctx->r17, -0X4);
L_800816E8:
    // 0x800816E8: lw          $t2, 0x0($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X0);
L_800816EC:
    // 0x800816EC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800816F0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800816F4: slt         $at, $s0, $t2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800816F8: bne         $at, $zero, L_80081658
    if (ctx->r1 != 0) {
        // 0x800816FC: nop
    
            goto L_80081658;
    }
    // 0x800816FC: nop

L_80081700:
    // 0x80081700: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80081704: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80081708: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8008170C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80081710: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80081714: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80081718: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8008171C: jr          $ra
    // 0x80081720: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80081720: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ncbaswim_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
;}
RECOMP_FUNC void chhagstraindoorswitch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080006C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1976, 0X80) << 16);
    // 0x80800070: jr          $ra
    // 0x80800074: addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1976, 0X80));
    return;
    // 0x80800074: addiu       $v0, $v0, 0x80
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1976, 0X80));
    // 0x80800078: nop

    // 0x8080007C: nop

;}
RECOMP_FUNC void gczoombox_entrypoint_27(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803664: beq         $a0, $zero, L_80803684
    if (ctx->r4 == 0) {
        // 0x80803668: nop
    
            goto L_80803684;
    }
    // 0x80803668: nop

    // 0x8080366C: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x80803670: sb          $t6, 0x1B4($a0)
    MEM_B(0X1B4, ctx->r4) = ctx->r14;
    // 0x80803674: lh          $t7, 0x2($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X2);
    // 0x80803678: sb          $t7, 0x1B5($a0)
    MEM_B(0X1B5, ctx->r4) = ctx->r15;
    // 0x8080367C: lh          $t8, 0x4($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X4);
    // 0x80803680: sb          $t8, 0x1B6($a0)
    MEM_B(0X1B6, ctx->r4) = ctx->r24;
L_80803684:
    // 0x80803684: jr          $ra
    // 0x80803688: nop

    return;
    // 0x80803688: nop

;}
RECOMP_FUNC void func_80800FA0_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FA0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800FA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800FA8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800FAC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800FB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800FB4: jal         0x80100094
    // 0x80800FB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800FB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800FBC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800FC0: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x80800FC4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800FC8: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x80800FCC: beq         $t6, $at, L_80800FEC
    if (ctx->r14 == ctx->r1) {
        // 0x80800FD0: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80800FEC;
    }
    // 0x80800FD0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800FD4: beq         $t6, $at, L_80801014
    if (ctx->r14 == ctx->r1) {
        // 0x80800FD8: addiu       $at, $zero, 0x17
        ctx->r1 = ADD32(0, 0X17);
            goto L_80801014;
    }
    // 0x80800FD8: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x80800FDC: beq         $t6, $at, L_80801004
    if (ctx->r14 == ctx->r1) {
        // 0x80800FE0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801004;
    }
    // 0x80800FE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FE4: b           L_80801018
    // 0x80800FE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801018;
    // 0x80800FE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800FEC:
    // 0x80800FEC: jal         0x800F54E4
    // 0x80800FF0: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80800FF0: nop

    after_1:
    // 0x80800FF4: jal         0x800F4CC0
    // 0x80800FF8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F4CC0(rdram, ctx);
        goto after_2;
    // 0x80800FF8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800FFC: b           L_80801018
    // 0x80801000: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801018;
    // 0x80801000: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801004:
    // 0x80801004: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80801008: addiu       $a1, $zero, 0x67C
    ctx->r5 = ADD32(0, 0X67C);
    // 0x8080100C: jal         0x80103140
    // 0x80801010: lhu         $a2, 0x16($t7)
    ctx->r6 = MEM_HU(ctx->r15, 0X16);
    func_80103140(rdram, ctx);
        goto after_3;
    // 0x80801010: lhu         $a2, 0x16($t7)
    ctx->r6 = MEM_HU(ctx->r15, 0X16);
    after_3:
L_80801014:
    // 0x80801014: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801018:
    // 0x80801018: jal         0x80102424
    // 0x8080101C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80102424(rdram, ctx);
        goto after_4;
    // 0x8080101C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x80801020: lhu         $t8, 0x72($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X72);
    // 0x80801024: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x80801028: addiu       $t0, $t9, -0x3
    ctx->r8 = ADD32(ctx->r25, -0X3);
    // 0x8080102C: sltiu       $at, $t0, 0xD
    ctx->r1 = ctx->r8 < 0XD ? 1 : 0;
    // 0x80801030: beq         $at, $zero, L_808010BC
    if (ctx->r1 == 0) {
        // 0x80801034: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_808010BC;
    }
    // 0x80801034: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80801038: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X442C) << 16);
    // 0x8080103C: addu        $at, $at, $t0
    gpr jr_addend_80801044 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80801040: lw          $t0, 0x442C($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1632, 0X442C));
    // 0x80801044: jr          $t0
    // 0x80801048: nop

    switch (jr_addend_80801044 >> 2) {
        case 0: goto L_8080104C; break;
        case 1: goto L_8080105C; break;
        case 2: goto L_80801090; break;
        case 3: goto L_808010BC; break;
        case 4: goto L_808010B0; break;
        case 5: goto L_808010BC; break;
        case 6: goto L_808010BC; break;
        case 7: goto L_808010BC; break;
        case 8: goto L_808010BC; break;
        case 9: goto L_808010BC; break;
        case 10: goto L_808010BC; break;
        case 11: goto L_808010BC; break;
        case 12: goto L_808010BC; break;
        default: switch_error(__func__, 0x80801044, 0x8080442C);
    }
    // 0x80801048: nop

L_8080104C:
    // 0x8080104C: jal         0x800903D0
    // 0x80801050: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    func_800903D0(rdram, ctx);
        goto after_5;
    // 0x80801050: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_5:
    // 0x80801054: b           L_808010BC
    // 0x80801058: nop

        goto L_808010BC;
    // 0x80801058: nop

L_8080105C:
    // 0x8080105C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80801060: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80801064: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x80801068: sb          $t1, 0x8FA($t2)
    MEM_B(0X8FA, ctx->r10) = ctx->r9;
    // 0x8080106C: jal         0x800904F4
    // 0x80801070: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_800904F4(rdram, ctx);
        goto after_6;
    // 0x80801070: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_6:
    // 0x80801074: jal         0x800F54E4
    // 0x80801078: nop

    func_800F54E4(rdram, ctx);
        goto after_7;
    // 0x80801078: nop

    after_7:
    // 0x8080107C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801080: jal         0x800F4CEC
    // 0x80801084: addiu       $a1, $zero, 0x3B
    ctx->r5 = ADD32(0, 0X3B);
    func_800F4CEC(rdram, ctx);
        goto after_8;
    // 0x80801084: addiu       $a1, $zero, 0x3B
    ctx->r5 = ADD32(0, 0X3B);
    after_8:
    // 0x80801088: b           L_808010BC
    // 0x8080108C: nop

        goto L_808010BC;
    // 0x8080108C: nop

L_80801090:
    // 0x80801090: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80801094: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80801098: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x8080109C: sb          $t3, 0x8FA($t4)
    MEM_B(0X8FA, ctx->r12) = ctx->r11;
    // 0x808010A0: jal         0x800904F4
    // 0x808010A4: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_800904F4(rdram, ctx);
        goto after_9;
    // 0x808010A4: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_9:
    // 0x808010A8: b           L_808010BC
    // 0x808010AC: nop

        goto L_808010BC;
    // 0x808010AC: nop

L_808010B0:
    // 0x808010B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010B4: jal         0x80800EE4
    // 0x808010B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800EE4_chhandcart(rdram, ctx);
        goto after_10;
    // 0x808010B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
L_808010BC:
    // 0x808010BC: jal         0x80800F4C
    // 0x808010C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800F4C_chhandcart(rdram, ctx);
        goto after_11;
    // 0x808010C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808010C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808010C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808010CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808010D0: jr          $ra
    // 0x808010D4: nop

    return;
    // 0x808010D4: nop

;}
RECOMP_FUNC void _chlightfader_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800863E8: syscall     321
    recomp_syscall_handler(rdram, ctx, 0x800863E8);
    return;
    // 0x800863EC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808000EC_bsmumstill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000EC: lw          $v1, 0x160($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X160);
    // 0x808000F0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(328, 0X400) << 16);
    // 0x808000F4: sltiu       $at, $v1, 0x2
    ctx->r1 = ctx->r3 < 0X2 ? 1 : 0;
    // 0x808000F8: bnel        $at, $zero, L_8080010C
    if (ctx->r1 != 0) {
        // 0x808000FC: addu        $a1, $a1, $v1
        ctx->r5 = ADD32(ctx->r5, ctx->r3);
            goto L_8080010C;
    }
    goto skip_0;
    // 0x808000FC: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    skip_0:
    // 0x80800100: sw          $zero, 0x160($a0)
    MEM_W(0X160, ctx->r4) = 0;
    // 0x80800104: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800108: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
L_8080010C:
    // 0x8080010C: lbu         $v0, 0x400($a1)
    ctx->r2 = MEM_BU(ctx->r5, (int16_t)RELOC_LO16(328, 0X400));
    // 0x80800110: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x80800114: jr          $ra
    // 0x80800118: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
    return;
    // 0x80800118: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_80801DB0_chhumba(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801DB0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801DB4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801DB8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801DBC: lbu         $t6, 0x74($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X74);
    // 0x80801DC0: addiu       $t8, $a1, -0x11A4
    ctx->r24 = ADD32(ctx->r5, -0X11A4);
    // 0x80801DC4: sltiu       $at, $t8, 0x1C
    ctx->r1 = ctx->r24 < 0X1C ? 1 : 0;
    // 0x80801DC8: andi        $t7, $t6, 0xFFBF
    ctx->r15 = ctx->r14 & 0XFFBF;
    // 0x80801DCC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801DD0: sb          $t7, 0x74($a0)
    MEM_B(0X74, ctx->r4) = ctx->r15;
    // 0x80801DD4: beq         $at, $zero, L_80801F60
    if (ctx->r1 == 0) {
        // 0x80801DD8: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_80801F60;
    }
    // 0x80801DD8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80801DDC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80801DE0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1688, 0X2518) << 16);
    // 0x80801DE4: addu        $at, $at, $t8
    gpr jr_addend_80801DEC = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80801DE8: lw          $t8, 0x2518($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1688, 0X2518));
    // 0x80801DEC: jr          $t8
    // 0x80801DF0: nop

    switch (jr_addend_80801DEC >> 2) {
        case 0: goto L_80801E04; break;
        case 1: goto L_80801E18; break;
        case 2: goto L_80801E18; break;
        case 3: goto L_80801E18; break;
        case 4: goto L_80801E18; break;
        case 5: goto L_80801E18; break;
        case 6: goto L_80801E18; break;
        case 7: goto L_80801E18; break;
        case 8: goto L_80801E18; break;
        case 9: goto L_80801E18; break;
        case 10: goto L_80801E18; break;
        case 11: goto L_80801DF4; break;
        case 12: goto L_80801E68; break;
        case 13: goto L_80801EC4; break;
        case 14: goto L_80801E9C; break;
        case 15: goto L_80801F04; break;
        case 16: goto L_80801F3C; break;
        case 17: goto L_80801F20; break;
        case 18: goto L_80801F4C; break;
        case 19: goto L_80801E18; break;
        case 20: goto L_80801F60; break;
        case 21: goto L_80801F60; break;
        case 22: goto L_80801F60; break;
        case 23: goto L_80801F60; break;
        case 24: goto L_80801F60; break;
        case 25: goto L_80801E04; break;
        case 26: goto L_80801E68; break;
        case 27: goto L_80801F04; break;
        default: switch_error(__func__, 0x80801DEC, 0x80802518);
    }
    // 0x80801DF0: nop

L_80801DF4:
    // 0x80801DF4: jal         0x808001E4
    // 0x80801DF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001E4_chhumba(rdram, ctx);
        goto after_0;
    // 0x80801DF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80801DFC: b           L_80801F64
    // 0x80801E00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801F64;
    // 0x80801E00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801E04:
    // 0x80801E04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E08: jal         0x80800E44
    // 0x80801E0C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800E44_chhumba(rdram, ctx);
        goto after_1;
    // 0x80801E0C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x80801E10: b           L_80801F64
    // 0x80801E14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801F64;
    // 0x80801E14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801E18:
    // 0x80801E18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E1C: jal         0x80800D2C
    // 0x80801E20: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80800D2C_chhumba(rdram, ctx);
        goto after_2;
    // 0x80801E20: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_2:
    // 0x80801E24: bnel        $v0, $zero, L_80801E4C
    if (ctx->r2 != 0) {
        // 0x80801E28: lw          $t9, 0x24($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X24);
            goto L_80801E4C;
    }
    goto skip_0;
    // 0x80801E28: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80801E2C: jal         0x800C0850
    // 0x80801E30: nop

    func_800C0850(rdram, ctx);
        goto after_3;
    // 0x80801E30: nop

    after_3:
    // 0x80801E34: jal         0x808001E4
    // 0x80801E38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001E4_chhumba(rdram, ctx);
        goto after_4;
    // 0x80801E38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801E3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E40: jal         0x80800E44
    // 0x80801E44: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80800E44_chhumba(rdram, ctx);
        goto after_5;
    // 0x80801E44: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_5:
    // 0x80801E48: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
L_80801E4C:
    // 0x80801E4C: addiu       $at, $zero, 0x11B7
    ctx->r1 = ADD32(0, 0X11B7);
    // 0x80801E50: bnel        $t9, $at, L_80801F64
    if (ctx->r25 != ctx->r1) {
        // 0x80801E54: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801F64;
    }
    goto skip_1;
    // 0x80801E54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80801E58: jal         0x80090708
    // 0x80801E5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_6;
    // 0x80801E5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x80801E60: b           L_80801F64
    // 0x80801E64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801F64;
    // 0x80801E64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801E68:
    // 0x80801E68: beq         $a2, $zero, L_80801E88
    if (ctx->r6 == 0) {
        // 0x80801E6C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801E88;
    }
    // 0x80801E6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E74: addiu       $a1, $zero, 0x11B1
    ctx->r5 = ADD32(0, 0X11B1);
    // 0x80801E78: jal         0x80800338
    // 0x80801E7C: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_80800338_chhumba(rdram, ctx);
        goto after_7;
    // 0x80801E7C: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_7:
    // 0x80801E80: b           L_80801F64
    // 0x80801E84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801F64;
    // 0x80801E84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801E88:
    // 0x80801E88: addiu       $a1, $zero, 0x11B2
    ctx->r5 = ADD32(0, 0X11B2);
    // 0x80801E8C: jal         0x80800338
    // 0x80801E90: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_80800338_chhumba(rdram, ctx);
        goto after_8;
    // 0x80801E90: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_8:
    // 0x80801E94: b           L_80801F64
    // 0x80801E98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801F64;
    // 0x80801E98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801E9C:
    // 0x80801E9C: jal         0x808001E4
    // 0x80801EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001E4_chhumba(rdram, ctx);
        goto after_9;
    // 0x80801EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80801EA4: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80801EA8: jal         0x800EE7F8
    // 0x80801EAC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_10;
    // 0x80801EAC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_10:
    // 0x80801EB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801EB4: jal         0x80800E44
    // 0x80801EB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800E44_chhumba(rdram, ctx);
        goto after_11;
    // 0x80801EB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80801EBC: b           L_80801F64
    // 0x80801EC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801F64;
    // 0x80801EC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801EC4:
    // 0x80801EC4: jal         0x80800C20
    // 0x80801EC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800C20_chhumba(rdram, ctx);
        goto after_12;
    // 0x80801EC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80801ECC: beql        $v0, $zero, L_80801EE0
    if (ctx->r2 == 0) {
        // 0x80801ED0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801EE0;
    }
    goto skip_2;
    // 0x80801ED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80801ED4: jal         0x808001E4
    // 0x80801ED8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001E4_chhumba(rdram, ctx);
        goto after_13;
    // 0x80801ED8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80801EDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801EE0:
    // 0x80801EE0: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x80801EE4: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x80801EE8: jal         0x808000D4
    // 0x80801EEC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_808000D4_chhumba(rdram, ctx);
        goto after_14;
    // 0x80801EEC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_14:
    // 0x80801EF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801EF4: jal         0x80800E44
    // 0x80801EF8: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    func_80800E44_chhumba(rdram, ctx);
        goto after_15;
    // 0x80801EF8: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_15:
    // 0x80801EFC: b           L_80801F64
    // 0x80801F00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801F64;
    // 0x80801F00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801F04:
    // 0x80801F04: jal         0x808001E4
    // 0x80801F08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001E4_chhumba(rdram, ctx);
        goto after_16;
    // 0x80801F08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80801F0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801F10: jal         0x80800E44
    // 0x80801F14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800E44_chhumba(rdram, ctx);
        goto after_17;
    // 0x80801F14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x80801F18: b           L_80801F64
    // 0x80801F1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801F64;
    // 0x80801F1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801F20:
    // 0x80801F20: jal         0x808001E4
    // 0x80801F24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001E4_chhumba(rdram, ctx);
        goto after_18;
    // 0x80801F24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80801F28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801F2C: jal         0x80800E44
    // 0x80801F30: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80800E44_chhumba(rdram, ctx);
        goto after_19;
    // 0x80801F30: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_19:
    // 0x80801F34: b           L_80801F64
    // 0x80801F38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801F64;
    // 0x80801F38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801F3C:
    // 0x80801F3C: jal         0x808001E4
    // 0x80801F40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001E4_chhumba(rdram, ctx);
        goto after_20;
    // 0x80801F40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80801F44: b           L_80801F64
    // 0x80801F48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801F64;
    // 0x80801F48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801F4C:
    // 0x80801F4C: jal         0x808001E4
    // 0x80801F50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001E4_chhumba(rdram, ctx);
        goto after_21;
    // 0x80801F50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80801F54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801F58: jal         0x80800E44
    // 0x80801F5C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800E44_chhumba(rdram, ctx);
        goto after_22;
    // 0x80801F5C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_22:
L_80801F60:
    // 0x80801F60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801F64:
    // 0x80801F64: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801F68: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801F6C: jr          $ra
    // 0x80801F70: nop

    return;
    // 0x80801F70: nop

;}
RECOMP_FUNC void func_80801508_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801508: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080150C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801510: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1564, 0X3730) << 16);
    // 0x80801514: lwc1        $f6, 0x3730($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1564, 0X3730));
    // 0x80801518: lwc1        $f4, 0x24($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8080151C: lwc1        $f14, 0x44($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X44);
    // 0x80801520: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    tooie_frame_factor(rdram, &ctx->f6.fl, 0);
    // 0x80801524: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80801528: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
    // 0x8080152C: jal         0x800F1DCC
    // 0x80801530: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F1DCC(rdram, ctx);
        goto after_0;
    // 0x80801530: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801534: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1564, 0X3734) << 16);
    // 0x80801538: lwc1        $f16, 0x3734($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1564, 0X3734));
    // 0x8080153C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801540: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    tooie_frame_factor(rdram, &ctx->f16.fl, 1);
    // 0x80801544: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80801548: lwc1        $f10, 0x44($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X44);
    // 0x8080154C: lwc1        $f14, 0x4C($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x80801550: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80801554: jal         0x800F1DCC
    // 0x80801558: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
    func_800F1DCC(rdram, ctx);
        goto after_1;
    // 0x80801558: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
    after_1:
    // 0x8080155C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1564, 0X3738) << 16);
    // 0x80801560: lwc1        $f8, 0x3738($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1564, 0X3738));
    // 0x80801564: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    tooie_frame_factor(rdram, &ctx->f8.fl, 1);
    // 0x80801568: mul.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8080156C: lwc1        $f6, 0x4C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x80801570: add.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80801574: swc1        $f10, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f10.u32l;
    // 0x80801578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080157C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801580: jr          $ra
    // 0x80801584: nop

    return;
    // 0x80801584: nop

;}
RECOMP_FUNC void func_80800D1C_chfriesstand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D20: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800D24: bne         $a1, $at, L_80800D54
    if (ctx->r5 != ctx->r1) {
        // 0x80800D28: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80800D54;
    }
    // 0x80800D28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D2C: addiu       $a0, $zero, 0x331
    ctx->r4 = ADD32(0, 0X331);
    // 0x80800D30: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800D34: jal         0x80101180
    // 0x80800D38: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_0;
    // 0x80800D38: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80800D3C: addiu       $a0, $zero, 0x32D
    ctx->r4 = ADD32(0, 0X32D);
    // 0x80800D40: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80800D44: jal         0x80101180
    // 0x80800D48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_1;
    // 0x80800D48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80800D4C: b           L_80800D64
    // 0x80800D50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800D64;
    // 0x80800D50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D54:
    // 0x80800D54: jal         0x80085820
    // 0x80800D58: nop

    _chswitch_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x80800D58: nop

    after_2:
    // 0x80800D5C: b           L_80800D68
    // 0x80800D60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800D68;
    // 0x80800D60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800D64:
    // 0x80800D64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800D68:
    // 0x80800D68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D6C: jr          $ra
    // 0x80800D70: nop

    return;
    // 0x80800D70: nop

    // 0x80800D74: nop

    // 0x80800D78: nop

    // 0x80800D7C: nop

;}
RECOMP_FUNC void func_800F6590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F6590: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F6594: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F6598: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F659C: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F65A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F65A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F65A8: jal         0x8009E6F8
    // 0x800F65AC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    bs_getCurrentState(rdram, ctx);
        goto after_0;
    // 0x800F65AC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F65B0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F65B4: jal         0x8009CBDC
    // 0x800F65B8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8009CBDC(rdram, ctx);
        goto after_1;
    // 0x800F65B8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x800F65BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F65C0: xori        $t7, $v0, 0xA
    ctx->r15 = ctx->r2 ^ 0XA;
    // 0x800F65C4: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800F65C8: jr          $ra
    // 0x800F65CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800F65CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void bscarry_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004EC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808004F0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(132, 0X7C0) << 16);
    // 0x808004F4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808004F8: jr          $ra
    // 0x808004FC: lw          $v0, 0x7C0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(132, 0X7C0));
    return;
    // 0x808004FC: lw          $v0, 0x7C0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(132, 0X7C0));
;}
RECOMP_FUNC void func_80800348_choctopus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800348: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080034C: slti        $at, $a1, 0x41
    ctx->r1 = SIGNED(ctx->r5) < 0X41 ? 1 : 0;
    // 0x80800350: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800354: bne         $at, $zero, L_80800370
    if (ctx->r1 != 0) {
        // 0x80800358: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800370;
    }
    // 0x80800358: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080035C: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800360: beq         $a1, $at, L_808003F8
    if (ctx->r5 == ctx->r1) {
        // 0x80800364: nop
    
            goto L_808003F8;
    }
    // 0x80800364: nop

    // 0x80800368: b           L_80800418
    // 0x8080036C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800418;
    // 0x8080036C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800370:
    // 0x80800370: addiu       $t6, $a1, -0x1C
    ctx->r14 = ADD32(ctx->r5, -0X1C);
    // 0x80800374: sltiu       $at, $t6, 0x25
    ctx->r1 = ctx->r14 < 0X25 ? 1 : 0;
    // 0x80800378: beq         $at, $zero, L_8080040C
    if (ctx->r1 == 0) {
        // 0x8080037C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8080040C;
    }
    // 0x8080037C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800380: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1028, 0X824) << 16);
    // 0x80800384: addu        $at, $at, $t6
    gpr jr_addend_8080038C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800388: lw          $t6, 0x824($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1028, 0X824));
    // 0x8080038C: jr          $t6
    // 0x80800390: nop

    switch (jr_addend_8080038C >> 2) {
        case 0: goto L_808003D4; break;
        case 1: goto L_8080040C; break;
        case 2: goto L_8080040C; break;
        case 3: goto L_808003A4; break;
        case 4: goto L_8080040C; break;
        case 5: goto L_8080040C; break;
        case 6: goto L_8080040C; break;
        case 7: goto L_8080040C; break;
        case 8: goto L_8080040C; break;
        case 9: goto L_8080040C; break;
        case 10: goto L_8080040C; break;
        case 11: goto L_8080040C; break;
        case 12: goto L_8080040C; break;
        case 13: goto L_808003B4; break;
        case 14: goto L_808003C4; break;
        case 15: goto L_8080040C; break;
        case 16: goto L_8080040C; break;
        case 17: goto L_8080040C; break;
        case 18: goto L_8080040C; break;
        case 19: goto L_8080040C; break;
        case 20: goto L_8080040C; break;
        case 21: goto L_8080040C; break;
        case 22: goto L_8080040C; break;
        case 23: goto L_8080040C; break;
        case 24: goto L_8080040C; break;
        case 25: goto L_8080040C; break;
        case 26: goto L_8080040C; break;
        case 27: goto L_8080040C; break;
        case 28: goto L_8080040C; break;
        case 29: goto L_8080040C; break;
        case 30: goto L_8080040C; break;
        case 31: goto L_8080040C; break;
        case 32: goto L_8080040C; break;
        case 33: goto L_8080040C; break;
        case 34: goto L_8080040C; break;
        case 35: goto L_8080040C; break;
        case 36: goto L_80800394; break;
        default: switch_error(__func__, 0x8080038C, 0x80800824);
    }
    // 0x80800390: nop

L_80800394:
    // 0x80800394: jal         0x80800428
    // 0x80800398: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_80800428_choctopus(rdram, ctx);
        goto after_0;
    // 0x80800398: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x8080039C: b           L_80800418
    // 0x808003A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800418;
    // 0x808003A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003A4:
    // 0x808003A4: jal         0x80800230
    // 0x808003A8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_80800230_choctopus(rdram, ctx);
        goto after_1;
    // 0x808003A8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808003AC: b           L_80800418
    // 0x808003B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800418;
    // 0x808003B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003B4:
    // 0x808003B4: jal         0x80800790
    // 0x808003B8: nop

    func_80800790_choctopus(rdram, ctx);
        goto after_2;
    // 0x808003B8: nop

    after_2:
    // 0x808003BC: b           L_80800418
    // 0x808003C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800418;
    // 0x808003C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003C4:
    // 0x808003C4: jal         0x808007E4
    // 0x808003C8: nop

    func_808007E4_choctopus(rdram, ctx);
        goto after_3;
    // 0x808003C8: nop

    after_3:
    // 0x808003CC: b           L_80800418
    // 0x808003D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800418;
    // 0x808003D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003D4:
    // 0x808003D4: lhu         $t7, 0x72($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X72);
    // 0x808003D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808003DC: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x808003E0: bne         $t8, $at, L_808003F0
    if (ctx->r24 != ctx->r1) {
        // 0x808003E4: nop
    
            goto L_808003F0;
    }
    // 0x808003E4: nop

    // 0x808003E8: b           L_80800418
    // 0x808003EC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80800418;
    // 0x808003EC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_808003F0:
    // 0x808003F0: b           L_80800418
    // 0x808003F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800418;
    // 0x808003F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003F8:
    // 0x808003F8: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x808003FC: jal         0x80089FF0
    // 0x80800400: addiu       $a1, $a1, 0x5F40
    ctx->r5 = ADD32(ctx->r5, 0X5F40);
    _subaddiecustomhits_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x80800400: addiu       $a1, $a1, 0x5F40
    ctx->r5 = ADD32(ctx->r5, 0X5F40);
    after_4:
    // 0x80800404: b           L_80800418
    // 0x80800408: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800418;
    // 0x80800408: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080040C:
    // 0x8080040C: b           L_80800418
    // 0x80800410: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800418;
    // 0x80800410: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800414: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800418:
    // 0x80800418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080041C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800420: jr          $ra
    // 0x80800424: nop

    return;
    // 0x80800424: nop

;}
RECOMP_FUNC void _chbaddieDll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085930: syscall     181
    recomp_syscall_handler(rdram, ctx, 0x80085930);
    return;
    // 0x80085934: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800458_chbosskogsdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800458: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080045C: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x80800460: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800464: bne         $a1, $at, L_808004D4
    if (ctx->r5 != ctx->r1) {
        // 0x80800468: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_808004D4;
    }
    // 0x80800468: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080046C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800470: bne         $a2, $at, L_808004CC
    if (ctx->r6 != ctx->r1) {
        // 0x80800474: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_808004CC;
    }
    // 0x80800474: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800478: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x8080047C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800480: jal         0x80085708
    // 0x80800484: addiu       $a3, $zero, 0x930
    ctx->r7 = ADD32(0, 0X930);
    _capod_entrypoint_13(rdram, ctx);
        goto after_0;
    // 0x80800484: addiu       $a3, $zero, 0x930
    ctx->r7 = ADD32(0, 0X930);
    after_0:
    // 0x80800488: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080048C: jal         0x80101FDC
    // 0x80800490: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x80800490: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80800494: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800498: lui         $a1, 0xC5E9
    ctx->r5 = S32(0XC5E9 << 16);
    // 0x8080049C: lui         $a2, 0x4516
    ctx->r6 = S32(0X4516 << 16);
    // 0x808004A0: ori         $a2, $a2, 0x5000
    ctx->r6 = ctx->r6 | 0X5000;
    // 0x808004A4: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x808004A8: lui         $a3, 0xC49B
    ctx->r7 = S32(0XC49B << 16);
    // 0x808004AC: jal         0x800EFA4C
    // 0x808004B0: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800EFA4C(rdram, ctx);
        goto after_2;
    // 0x808004B0: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_2:
    // 0x808004B4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808004B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808004BC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x808004C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808004C4: b           L_808004D8
    // 0x808004C8: swc1        $f4, 0x2C($t7)
    MEM_W(0X2C, ctx->r15) = ctx->f4.u32l;
        goto L_808004D8;
    // 0x808004C8: swc1        $f4, 0x2C($t7)
    MEM_W(0X2C, ctx->r15) = ctx->f4.u32l;
L_808004CC:
    // 0x808004CC: b           L_808004D8
    // 0x808004D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808004D8;
    // 0x808004D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808004D4:
    // 0x808004D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808004D8:
    // 0x808004D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004E0: jr          $ra
    // 0x808004E4: nop

    return;
    // 0x808004E4: nop

;}
RECOMP_FUNC void gccollectDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080008C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800090: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800094: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800098: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8080009C: jal         0x800D0820
    // 0x808000A0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_800D0820(rdram, ctx);
        goto after_0;
    // 0x808000A0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x808000A4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808000A8: jal         0x800D0894
    // 0x808000AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D0894(rdram, ctx);
        goto after_1;
    // 0x808000AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x808000B0: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808000B4: beq         $at, $zero, L_80800108
    if (ctx->r1 == 0) {
        // 0x808000B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800108;
    }
    // 0x808000B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808000BC:
    // 0x808000BC: jal         0x800D0A80
    // 0x808000C0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800D0A80(rdram, ctx);
        goto after_2;
    // 0x808000C0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x808000C4: beq         $v0, $zero, L_808000D4
    if (ctx->r2 == 0) {
        // 0x808000C8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808000D4;
    }
    // 0x808000C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000CC: jal         0x800DA524
    // 0x808000D0: nop

    func_800DA524(rdram, ctx);
        goto after_3;
    // 0x808000D0: nop

    after_3:
L_808000D4:
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D8: jal         0x800D0908
    // 0x808000DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800D0908(rdram, ctx);
        goto after_4;
    // 0x808000DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x808000E0: beq         $v0, $zero, L_808000F0
    if (ctx->r2 == 0) {
        // 0x808000E4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808000F0;
    }
    // 0x808000E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000E8: jal         0x800DA524
    // 0x808000EC: nop

    func_800DA524(rdram, ctx);
        goto after_5;
    // 0x808000EC: nop

    after_5:
L_808000F0:
    // 0x808000F0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808000F4: jal         0x800D0894
    // 0x808000F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D0894(rdram, ctx);
        goto after_6;
    // 0x808000F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x808000FC: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800100: bnel        $at, $zero, L_808000BC
    if (ctx->r1 != 0) {
        // 0x80800104: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000BC;
    }
    goto skip_0;
    // 0x80800104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
L_80800108:
    // 0x80800108: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080010C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800110: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800114: jr          $ra
    // 0x80800118: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800118: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80020E6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020E6C: jr          $ra
    // 0x80020E70: nop

    return;
    // 0x80020E70: nop

;}
RECOMP_FUNC void func_80800634_chkingjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800634: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80800638: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080063C: slti        $at, $a1, 0x58
    ctx->r1 = SIGNED(ctx->r5) < 0X58 ? 1 : 0;
    // 0x80800640: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800644: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800648: bne         $at, $zero, L_80800664
    if (ctx->r1 != 0) {
        // 0x8080064C: sw          $a2, 0x78($sp)
        MEM_W(0X78, ctx->r29) = ctx->r6;
            goto L_80800664;
    }
    // 0x8080064C: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x80800650: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800654: beq         $a1, $at, L_808006DC
    if (ctx->r5 == ctx->r1) {
        // 0x80800658: addiu       $a0, $zero, 0x147
        ctx->r4 = ADD32(0, 0X147);
            goto L_808006DC;
    }
    // 0x80800658: addiu       $a0, $zero, 0x147
    ctx->r4 = ADD32(0, 0X147);
    // 0x8080065C: b           L_808009BC
    // 0x80800660: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808009BC;
    // 0x80800660: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800664:
    // 0x80800664: addiu       $t6, $a1, -0xB
    ctx->r14 = ADD32(ctx->r5, -0XB);
    // 0x80800668: sltiu       $at, $t6, 0x4D
    ctx->r1 = ctx->r14 < 0X4D ? 1 : 0;
    // 0x8080066C: beq         $at, $zero, L_808009B0
    if (ctx->r1 == 0) {
        // 0x80800670: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_808009B0;
    }
    // 0x80800670: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800674: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1296, 0XFF0) << 16);
    // 0x80800678: addu        $at, $at, $t6
    gpr jr_addend_80800680 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8080067C: lw          $t6, 0xFF0($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1296, 0XFF0));
    // 0x80800680: jr          $t6
    // 0x80800684: nop

    switch (jr_addend_80800680 >> 2) {
        case 0: goto L_808008F4; break;
        case 1: goto L_808009B0; break;
        case 2: goto L_808009B0; break;
        case 3: goto L_808009B0; break;
        case 4: goto L_808009B0; break;
        case 5: goto L_808009B0; break;
        case 6: goto L_808009B0; break;
        case 7: goto L_808009B0; break;
        case 8: goto L_808009B0; break;
        case 9: goto L_808009B0; break;
        case 10: goto L_808009B0; break;
        case 11: goto L_808009B0; break;
        case 12: goto L_808009B0; break;
        case 13: goto L_808009B0; break;
        case 14: goto L_808009B0; break;
        case 15: goto L_808009B0; break;
        case 16: goto L_808009B0; break;
        case 17: goto L_808009B0; break;
        case 18: goto L_808009B0; break;
        case 19: goto L_808009B0; break;
        case 20: goto L_80800994; break;
        case 21: goto L_808009B0; break;
        case 22: goto L_808009B0; break;
        case 23: goto L_808009B0; break;
        case 24: goto L_808009B0; break;
        case 25: goto L_808009B0; break;
        case 26: goto L_808009B0; break;
        case 27: goto L_808009B0; break;
        case 28: goto L_808009B0; break;
        case 29: goto L_808009B0; break;
        case 30: goto L_808009B0; break;
        case 31: goto L_808009B0; break;
        case 32: goto L_808009B0; break;
        case 33: goto L_808009B0; break;
        case 34: goto L_808009B0; break;
        case 35: goto L_80800688; break;
        case 36: goto L_808009B0; break;
        case 37: goto L_808009B0; break;
        case 38: goto L_808009B0; break;
        case 39: goto L_8080093C; break;
        case 40: goto L_808009B0; break;
        case 41: goto L_808009B0; break;
        case 42: goto L_808009B0; break;
        case 43: goto L_808009B0; break;
        case 44: goto L_808009B0; break;
        case 45: goto L_808009B0; break;
        case 46: goto L_808009B0; break;
        case 47: goto L_808009B0; break;
        case 48: goto L_808009B0; break;
        case 49: goto L_808009B0; break;
        case 50: goto L_808009B0; break;
        case 51: goto L_808009B0; break;
        case 52: goto L_808006A4; break;
        case 53: goto L_808009B0; break;
        case 54: goto L_808009B0; break;
        case 55: goto L_808009B0; break;
        case 56: goto L_808009B0; break;
        case 57: goto L_808009B0; break;
        case 58: goto L_808009B0; break;
        case 59: goto L_808009B0; break;
        case 60: goto L_808009B0; break;
        case 61: goto L_808009B0; break;
        case 62: goto L_808009B0; break;
        case 63: goto L_808009B0; break;
        case 64: goto L_808009B0; break;
        case 65: goto L_808009B0; break;
        case 66: goto L_808009B0; break;
        case 67: goto L_808009B0; break;
        case 68: goto L_808009B0; break;
        case 69: goto L_808009B0; break;
        case 70: goto L_808009B0; break;
        case 71: goto L_808006CC; break;
        case 72: goto L_808009B0; break;
        case 73: goto L_808009B0; break;
        case 74: goto L_808009B0; break;
        case 75: goto L_808009B0; break;
        case 76: goto L_808008C8; break;
        default: switch_error(__func__, 0x80800680, 0x80800FF0);
    }
    // 0x80800684: nop

L_80800688:
    // 0x80800688: addiu       $v0, $sp, 0x78
    ctx->r2 = ADD32(ctx->r29, 0X78);
    // 0x8080068C: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80800690: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x80800694: jal         0x808009FC
    // 0x80800698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808009FC_chkingjinjo(rdram, ctx);
        goto after_0;
    // 0x80800698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8080069C: b           L_808009BC
    // 0x808006A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808009BC;
    // 0x808006A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006A4:
    // 0x808006A4: lhu         $t7, 0x72($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X72);
    // 0x808006A8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x808006AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006B0: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x808006B4: beql        $t8, $at, L_808009BC
    if (ctx->r24 == ctx->r1) {
        // 0x808006B8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808009BC;
    }
    goto skip_0;
    // 0x808006B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x808006BC: jal         0x80102424
    // 0x808006C0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x808006C0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_1:
    // 0x808006C4: b           L_808009BC
    // 0x808006C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808009BC;
    // 0x808006C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006CC:
    // 0x808006CC: jal         0x80800B28
    // 0x808006D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800B28_chkingjinjo(rdram, ctx);
        goto after_2;
    // 0x808006D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808006D4: b           L_808009BC
    // 0x808006D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808009BC;
    // 0x808006D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006DC:
    // 0x808006DC: jal         0x80089C30
    // 0x808006E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x808006E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808006E4: beql        $v0, $zero, L_808006FC
    if (ctx->r2 == 0) {
        // 0x808006E8: sw          $zero, 0x3C($s0)
        MEM_W(0X3C, ctx->r16) = 0;
            goto L_808006FC;
    }
    goto skip_1;
    // 0x808006E8: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    skip_1:
    // 0x808006EC: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x808006F0: b           L_808006FC
    // 0x808006F4: sw          $t9, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r25;
        goto L_808006FC;
    // 0x808006F4: sw          $t9, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r25;
    // 0x808006F8: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
L_808006FC:
    // 0x808006FC: jal         0x800DA298
    // 0x80800700: addiu       $a0, $zero, 0x360
    ctx->r4 = ADD32(0, 0X360);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80800700: addiu       $a0, $zero, 0x360
    ctx->r4 = ADD32(0, 0X360);
    after_4:
    // 0x80800704: beq         $v0, $zero, L_8080072C
    if (ctx->r2 == 0) {
        // 0x80800708: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080072C;
    }
    // 0x80800708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080070C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80800710: addiu       $a1, $zero, 0x897
    ctx->r5 = ADD32(0, 0X897);
    // 0x80800714: jal         0x801032B0
    // 0x80800718: lhu         $a2, 0x16($t0)
    ctx->r6 = MEM_HU(ctx->r8, 0X16);
    func_801032B0(rdram, ctx);
        goto after_5;
    // 0x80800718: lhu         $a2, 0x16($t0)
    ctx->r6 = MEM_HU(ctx->r8, 0X16);
    after_5:
    // 0x8080071C: jal         0x80089F60
    // 0x80800720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_1(rdram, ctx);
        goto after_6;
    // 0x80800720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800724: b           L_808007F0
    // 0x80800728: lhu         $t3, 0x72($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X72);
        goto L_808007F0;
    // 0x80800728: lhu         $t3, 0x72($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X72);
L_8080072C:
    // 0x8080072C: jal         0x800DA298
    // 0x80800730: addiu       $a0, $zero, 0x1A5
    ctx->r4 = ADD32(0, 0X1A5);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x80800730: addiu       $a0, $zero, 0x1A5
    ctx->r4 = ADD32(0, 0X1A5);
    after_7:
    // 0x80800734: bnel        $v0, $zero, L_808007DC
    if (ctx->r2 != 0) {
        // 0x80800738: lw          $t2, 0x0($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X0);
            goto L_808007DC;
    }
    goto skip_2;
    // 0x80800738: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x8080073C: jal         0x800DA298
    // 0x80800740: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    func_800DA298(rdram, ctx);
        goto after_8;
    // 0x80800740: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    after_8:
    // 0x80800744: bnel        $v0, $zero, L_808007DC
    if (ctx->r2 != 0) {
        // 0x80800748: lw          $t2, 0x0($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X0);
            goto L_808007DC;
    }
    goto skip_3;
    // 0x80800748: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    skip_3:
    // 0x8080074C: jal         0x80088848
    // 0x80800750: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_9;
    // 0x80800750: nop

    after_9:
    // 0x80800754: bnel        $v0, $zero, L_808007DC
    if (ctx->r2 != 0) {
        // 0x80800758: lw          $t2, 0x0($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X0);
            goto L_808007DC;
    }
    goto skip_4;
    // 0x80800758: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    skip_4:
    // 0x8080075C: jal         0x800F54E4
    // 0x80800760: nop

    func_800F54E4(rdram, ctx);
        goto after_10;
    // 0x80800760: nop

    after_10:
    // 0x80800764: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80800768: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x8080076C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800774: addiu       $a1, $zero, 0x154
    ctx->r5 = ADD32(0, 0X154);
    // 0x80800778: addiu       $a2, $zero, 0x33
    ctx->r6 = ADD32(0, 0X33);
    // 0x8080077C: jal         0x8008A0C8
    // 0x80800780: addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    _subaddiemarker_entrypoint_1(rdram, ctx);
        goto after_11;
    // 0x80800780: addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    after_11:
    // 0x80800784: jal         0x800F497C
    // 0x80800788: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    func_800F497C(rdram, ctx);
        goto after_12;
    // 0x80800788: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_12:
    // 0x8080078C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80800790: jal         0x800F49A8
    // 0x80800794: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F49A8(rdram, ctx);
        goto after_13;
    // 0x80800794: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x80800798: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8080079C: addiu       $a1, $a1, -0x2A24
    ctx->r5 = ADD32(ctx->r5, -0X2A24);
    // 0x808007A0: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x808007A4: jal         0x800F49D4
    // 0x808007A8: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    func_800F49D4(rdram, ctx);
        goto after_14;
    // 0x808007A8: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    after_14:
    // 0x808007AC: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x808007B0: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x808007B4: jal         0x800F4A58
    // 0x808007B8: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    func_800F4A58(rdram, ctx);
        goto after_15;
    // 0x808007B8: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    after_15:
    // 0x808007BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007C0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808007C4: jal         0x80800CFC
    // 0x808007C8: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_80800CFC_chkingjinjo(rdram, ctx);
        goto after_16;
    // 0x808007C8: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_16:
    // 0x808007CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007D0: jal         0x80102424
    // 0x808007D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_17;
    // 0x808007D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x808007D8: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
L_808007DC:
    // 0x808007DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007E0: addiu       $a1, $zero, 0x896
    ctx->r5 = ADD32(0, 0X896);
    // 0x808007E4: jal         0x801032B0
    // 0x808007E8: lhu         $a2, 0x16($t2)
    ctx->r6 = MEM_HU(ctx->r10, 0X16);
    func_801032B0(rdram, ctx);
        goto after_18;
    // 0x808007E8: lhu         $a2, 0x16($t2)
    ctx->r6 = MEM_HU(ctx->r10, 0X16);
    after_18:
    // 0x808007EC: lhu         $t3, 0x72($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X72);
L_808007F0:
    // 0x808007F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808007F4: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x808007F8: srl         $t4, $t3, 10
    ctx->r12 = S32(U32(ctx->r11) >> 10);
    // 0x808007FC: bne         $t4, $at, L_80800870
    if (ctx->r12 != ctx->r1) {
        // 0x80800800: addiu       $t5, $t5, -0x2A24
        ctx->r13 = ADD32(ctx->r13, -0X2A24);
            goto L_80800870;
    }
    // 0x80800800: addiu       $t5, $t5, -0x2A24
    ctx->r13 = ADD32(ctx->r13, -0X2A24);
    // 0x80800804: jal         0x800F54E4
    // 0x80800808: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    func_800F54E4(rdram, ctx);
        goto after_19;
    // 0x80800808: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    after_19:
    // 0x8080080C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800810: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800814: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080081C: addiu       $a1, $zero, 0x154
    ctx->r5 = ADD32(0, 0X154);
    // 0x80800820: addiu       $a2, $zero, 0x34
    ctx->r6 = ADD32(0, 0X34);
    // 0x80800824: jal         0x8008A0C8
    // 0x80800828: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    _subaddiemarker_entrypoint_1(rdram, ctx);
        goto after_20;
    // 0x80800828: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    after_20:
    // 0x8080082C: jal         0x800F497C
    // 0x80800830: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800F497C(rdram, ctx);
        goto after_21;
    // 0x80800830: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_21:
    // 0x80800834: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800838: jal         0x800F49A8
    // 0x8080083C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F49A8(rdram, ctx);
        goto after_22;
    // 0x8080083C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_22:
    // 0x80800840: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800844: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800848: jal         0x800F49D4
    // 0x8080084C: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    func_800F49D4(rdram, ctx);
        goto after_23;
    // 0x8080084C: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    after_23:
    // 0x80800850: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800854: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80800858: jal         0x800F4A58
    // 0x8080085C: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    func_800F4A58(rdram, ctx);
        goto after_24;
    // 0x8080085C: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    after_24:
    // 0x80800860: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800864: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    // 0x80800868: jal         0x80800CFC
    // 0x8080086C: addiu       $a2, $zero, 0x2020
    ctx->r6 = ADD32(0, 0X2020);
    func_80800CFC_chkingjinjo(rdram, ctx);
        goto after_25;
    // 0x8080086C: addiu       $a2, $zero, 0x2020
    ctx->r6 = ADD32(0, 0X2020);
    after_25:
L_80800870:
    // 0x80800870: jal         0x800DA298
    // 0x80800874: addiu       $a0, $zero, 0x360
    ctx->r4 = ADD32(0, 0X360);
    func_800DA298(rdram, ctx);
        goto after_26;
    // 0x80800874: addiu       $a0, $zero, 0x360
    ctx->r4 = ADD32(0, 0X360);
    after_26:
    // 0x80800878: beq         $v0, $zero, L_80800888
    if (ctx->r2 == 0) {
        // 0x8080087C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800888;
    }
    // 0x8080087C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800880: b           L_8080088C
    // 0x80800884: addiu       $v0, $zero, 0xA5
    ctx->r2 = ADD32(0, 0XA5);
        goto L_8080088C;
    // 0x80800884: addiu       $v0, $zero, 0xA5
    ctx->r2 = ADD32(0, 0XA5);
L_80800888:
    // 0x80800888: addiu       $v0, $zero, 0xAE
    ctx->r2 = ADD32(0, 0XAE);
L_8080088C:
    // 0x8080088C: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x80800890: sra         $t7, $a2, 16
    ctx->r15 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80800894: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x80800898: jal         0x800897C0
    // 0x8080089C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_27;
    // 0x8080089C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_27:
    // 0x808008A0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808008A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808008A8: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x808008AC: jal         0x800897E8
    // 0x808008B0: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_28;
    // 0x808008B0: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    after_28:
    // 0x808008B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008B8: jal         0x80089810
    // 0x808008BC: addiu       $a1, $zero, 0x5DC
    ctx->r5 = ADD32(0, 0X5DC);
    _suexpression_entrypoint_17(rdram, ctx);
        goto after_29;
    // 0x808008BC: addiu       $a1, $zero, 0x5DC
    ctx->r5 = ADD32(0, 0X5DC);
    after_29:
    // 0x808008C0: b           L_808009BC
    // 0x808008C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808009BC;
    // 0x808008C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808008C8:
    // 0x808008C8: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    // 0x808008CC: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x808008D0: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x808008D4: andi        $t8, $a1, 0xFFFF
    ctx->r24 = ctx->r5 & 0XFFFF;
    // 0x808008D8: and         $t9, $a2, $at
    ctx->r25 = ctx->r6 & ctx->r1;
    // 0x808008DC: srl         $a2, $t9, 16
    ctx->r6 = S32(U32(ctx->r25) >> 16);
    // 0x808008E0: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x808008E4: jal         0x80800BBC
    // 0x808008E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800BBC_chkingjinjo(rdram, ctx);
        goto after_30;
    // 0x808008E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x808008EC: b           L_808009C0
    // 0x808008F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808009C0;
    // 0x808008F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808008F4:
    // 0x808008F4: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x808008F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808008FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800900: bne         $t1, $at, L_80800934
    if (ctx->r9 != ctx->r1) {
        // 0x80800904: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_80800934;
    }
    // 0x80800904: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800908: jal         0x80800C60
    // 0x8080090C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800C60_chkingjinjo(rdram, ctx);
        goto after_31;
    // 0x8080090C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_31:
    // 0x80800910: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800914: addiu       $t2, $zero, 0xAE
    ctx->r10 = ADD32(0, 0XAE);
    // 0x80800918: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8080091C: addiu       $a1, $zero, 0x1535
    ctx->r5 = ADD32(0, 0X1535);
    // 0x80800920: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80800924: jal         0x8008A208
    // 0x80800928: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_32;
    // 0x80800928: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_32:
    // 0x8080092C: b           L_808009BC
    // 0x80800930: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_808009BC;
    // 0x80800930: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800934:
    // 0x80800934: b           L_808009BC
    // 0x80800938: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_808009BC;
    // 0x80800938: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8080093C:
    // 0x8080093C: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80800940: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800944: addiu       $a1, $zero, 0x14FD
    ctx->r5 = ADD32(0, 0X14FD);
    // 0x80800948: srl         $t3, $v0, 10
    ctx->r11 = S32(U32(ctx->r2) >> 10);
    // 0x8080094C: beq         $t3, $at, L_80800968
    if (ctx->r11 == ctx->r1) {
        // 0x80800950: addiu       $a2, $zero, 0xE
        ctx->r6 = ADD32(0, 0XE);
            goto L_80800968;
    }
    // 0x80800950: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800954: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800958: beq         $t3, $at, L_80800984
    if (ctx->r11 == ctx->r1) {
        // 0x8080095C: addiu       $a0, $zero, 0x142
        ctx->r4 = ADD32(0, 0X142);
            goto L_80800984;
    }
    // 0x8080095C: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    // 0x80800960: b           L_808009BC
    // 0x80800964: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808009BC;
    // 0x80800964: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800968:
    // 0x80800968: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080096C: addiu       $t4, $zero, 0xAE
    ctx->r12 = ADD32(0, 0XAE);
    // 0x80800970: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80800974: jal         0x8008A208
    // 0x80800978: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_33;
    // 0x80800978: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_33:
    // 0x8080097C: b           L_808009BC
    // 0x80800980: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808009BC;
    // 0x80800980: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800984:
    // 0x80800984: jal         0x80087A58
    // 0x80800988: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_34;
    // 0x80800988: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_34:
    // 0x8080098C: b           L_808009BC
    // 0x80800990: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808009BC;
    // 0x80800990: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800994:
    // 0x80800994: jal         0x801015D0
    // 0x80800998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801015D0(rdram, ctx);
        goto after_35;
    // 0x80800998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_35:
    // 0x8080099C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x808009A0: jal         0x800DF744
    // 0x808009A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_36;
    // 0x808009A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_36:
    // 0x808009A8: b           L_808009BC
    // 0x808009AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808009BC;
    // 0x808009AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808009B0:
    // 0x808009B0: b           L_808009BC
    // 0x808009B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808009BC;
    // 0x808009B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808009B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808009BC:
    // 0x808009BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808009C0:
    // 0x808009C0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808009C4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x808009C8: jr          $ra
    // 0x808009CC: nop

    return;
    // 0x808009CC: nop

;}
RECOMP_FUNC void func_80801050_chterryegg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801050: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801054: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801058: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1112, 0X1424) << 16);
    // 0x8080105C: lui         $a3, 0x3F4F
    ctx->r7 = S32(0X3F4F << 16);
    // 0x80801060: ori         $a3, $a3, 0x5C29
    ctx->r7 = ctx->r7 | 0X5C29;
    // 0x80801064: addiu       $a2, $a2, 0x1424
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1112, 0X1424));
    // 0x80801068: jal         0x80089D20
    // 0x8080106C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x8080106C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80801070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801074: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801078: jr          $ra
    // 0x8080107C: nop

    return;
    // 0x8080107C: nop

;}
RECOMP_FUNC void func_80117824(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80117824: addiu       $sp, $sp, -0x530
    ctx->r29 = ADD32(ctx->r29, -0X530);
    // 0x80117828: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8011782C: addi        $t3, $sp, 0x44
    ctx->r11 = ADD32(ctx->r29, 0X44);
    // 0x80117830: addiu       $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
    // 0x80117834: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
L_80117838:
    // 0x80117838: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8011783C: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x80117840: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x80117844: sw          $t1, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r9;
    // 0x80117848: sw          $t1, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r9;
    // 0x8011784C: bne         $t0, $zero, L_80117838
    if (ctx->r8 != 0) {
        // 0x80117850: addiu       $t3, $t3, 0x10
        ctx->r11 = ADD32(ctx->r11, 0X10);
            goto L_80117838;
    }
    // 0x80117850: addiu       $t3, $t3, 0x10
    ctx->r11 = ADD32(ctx->r11, 0X10);
    // 0x80117854: addiu       $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
    // 0x80117858: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
L_8011785C:
    // 0x8011785C: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x80117860: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x80117864: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x80117868: sw          $t1, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r9;
    // 0x8011786C: sw          $t1, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r9;
    // 0x80117870: bne         $t0, $zero, L_8011785C
    if (ctx->r8 != 0) {
        // 0x80117874: addiu       $t3, $t3, 0x10
        ctx->r11 = ADD32(ctx->r11, 0X10);
            goto L_8011785C;
    }
    // 0x80117874: addiu       $t3, $t3, 0x10
    ctx->r11 = ADD32(ctx->r11, 0X10);
    // 0x80117878: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x8011787C: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
L_80117880:
    // 0x80117880: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x80117884: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x80117888: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x8011788C: sw          $t1, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r9;
    // 0x80117890: sw          $t1, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r9;
    // 0x80117894: bne         $t0, $zero, L_80117880
    if (ctx->r8 != 0) {
        // 0x80117898: addiu       $t3, $t3, 0x10
        ctx->r11 = ADD32(ctx->r11, 0X10);
            goto L_80117880;
    }
    // 0x80117898: addiu       $t3, $t3, 0x10
    ctx->r11 = ADD32(ctx->r11, 0X10);
    // 0x8011789C: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x801178A0: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x801178A4: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x801178A8: sw          $t1, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r9;
    // 0x801178AC: sw          $t1, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r9;
    // 0x801178B0: sw          $t1, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->r9;
    // 0x801178B4: sw          $t1, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->r9;
    // 0x801178B8: sw          $t1, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->r9;
    // 0x801178BC: sw          $t1, 0x1C($t3)
    MEM_W(0X1C, ctx->r11) = ctx->r9;
    // 0x801178C0: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x801178C4: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x801178C8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x801178CC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x801178D0: addiu       $v0, $v0, 0x6692
    ctx->r2 = ADD32(ctx->r2, 0X6692);
    // 0x801178D4: addi        $v1, $sp, 0x20
    ctx->r3 = ADD32(ctx->r29, 0X20);
    // 0x801178D8: addi        $t0, $sp, 0x24
    ctx->r8 = ADD32(ctx->r29, 0X24);
    // 0x801178DC: addi        $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x801178E0: addiu       $a1, $zero, 0x120
    ctx->r5 = ADD32(0, 0X120);
    // 0x801178E4: addiu       $a2, $zero, 0x101
    ctx->r6 = ADD32(0, 0X101);
    // 0x801178E8: addiu       $a3, $a3, 0x6654
    ctx->r7 = ADD32(ctx->r7, 0X6654);
    // 0x801178EC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x801178F0: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x801178F4: jal         0x80116914
    // 0x801178F8: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    func_80116914(rdram, ctx);
        goto after_0;
    // 0x801178F8: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_0:
    // 0x801178FC: addi        $t3, $sp, 0x44
    ctx->r11 = ADD32(ctx->r29, 0X44);
    // 0x80117900: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x80117904: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
L_80117908:
    // 0x80117908: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8011790C: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x80117910: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x80117914: sw          $t1, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r9;
    // 0x80117918: bne         $t0, $zero, L_80117908
    if (ctx->r8 != 0) {
        // 0x8011791C: addiu       $t3, $t3, 0xC
        ctx->r11 = ADD32(ctx->r11, 0XC);
            goto L_80117908;
    }
    // 0x8011791C: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
    // 0x80117920: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80117924: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80117928: addiu       $v0, $v0, 0x66EE
    ctx->r2 = ADD32(ctx->r2, 0X66EE);
    // 0x8011792C: addi        $v1, $sp, 0x28
    ctx->r3 = ADD32(ctx->r29, 0X28);
    // 0x80117930: addi        $t0, $sp, 0x2C
    ctx->r8 = ADD32(ctx->r29, 0X2C);
    // 0x80117934: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x80117938: addi        $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8011793C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x80117940: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80117944: addiu       $a3, $a3, 0x66B2
    ctx->r7 = ADD32(ctx->r7, 0X66B2);
    // 0x80117948: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8011794C: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x80117950: jal         0x80116914
    // 0x80117954: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    func_80116914(rdram, ctx);
        goto after_1;
    // 0x80117954: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_1:
    // 0x80117958: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8011795C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80117960: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80117964: jal         0x80117A08
    // 0x80117968: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    func_80117A08(rdram, ctx);
        goto after_2;
    // 0x80117968: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x8011796C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80117970: addiu       $sp, $sp, 0x530
    ctx->r29 = ADD32(ctx->r29, 0X530);
    // 0x80117974: jr          $ra
    // 0x80117978: nop

    return;
    // 0x80117978: nop

;}
RECOMP_FUNC void _badata_entrypoint_33(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084748: syscall     118
    recomp_syscall_handler(rdram, ctx, 0x80084748);
    return;
    // 0x8008474C: addi        $t0, $zero, 0x84
    ctx->r8 = ADD32(0, 0X84);
;}
RECOMP_FUNC void func_800B60C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B60C0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800B60C4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800B60C8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800B60CC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800B60D0: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x800B60D4: addiu       $s0, $s0, -0x7E80
    ctx->r16 = ADD32(ctx->r16, -0X7E80);
    // 0x800B60D8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B60DC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800B60E0: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800B60E4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800B60E8: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x800B60EC: jal         0x800D674C
    // 0x800B60F0: lh          $a0, 0x28($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X28);
    func_800D674C(rdram, ctx);
        goto after_0;
    // 0x800B60F0: lh          $a0, 0x28($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X28);
    after_0:
    // 0x800B60F4: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x800B60F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800B60FC: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x800B6100: jal         0x800AF5B0
    // 0x800B6104: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    func_800AF5B0(rdram, ctx);
        goto after_1;
    // 0x800B6104: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_1:
    // 0x800B6108: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x800B610C: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x800B6110: lbu         $t9, 0x1F($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1F);
    // 0x800B6114: bgez        $v0, L_800B6124
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800B6118: sra         $t6, $v0, 2
        ctx->r14 = S32(SIGNED(ctx->r2) >> 2);
            goto L_800B6124;
    }
    // 0x800B6118: sra         $t6, $v0, 2
    ctx->r14 = S32(SIGNED(ctx->r2) >> 2);
    // 0x800B611C: addiu       $at, $v0, 0x3
    ctx->r1 = ADD32(ctx->r2, 0X3);
    // 0x800B6120: sra         $t6, $at, 2
    ctx->r14 = S32(SIGNED(ctx->r1) >> 2);
L_800B6124:
    // 0x800B6124: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800B6128: bgez        $t7, L_800B6138
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800B612C: sra         $t8, $t7, 2
        ctx->r24 = S32(SIGNED(ctx->r15) >> 2);
            goto L_800B6138;
    }
    // 0x800B612C: sra         $t8, $t7, 2
    ctx->r24 = S32(SIGNED(ctx->r15) >> 2);
    // 0x800B6130: addiu       $at, $t7, 0x3
    ctx->r1 = ADD32(ctx->r15, 0X3);
    // 0x800B6134: sra         $t8, $at, 2
    ctx->r24 = S32(SIGNED(ctx->r1) >> 2);
L_800B6138:
    // 0x800B6138: bne         $t9, $zero, L_800B6170
    if (ctx->r25 != 0) {
        // 0x800B613C: sw          $t8, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r24;
            goto L_800B6170;
    }
    // 0x800B613C: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x800B6140: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800B6144: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800B6148: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B614C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B6150: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800B6154: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800B6158: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800B615C: nop

    // 0x800B6160: mul.s       $f18, $f10, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800B6164: sub.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x800B6168: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
    // 0x800B616C: sb          $t0, 0x1F($s0)
    MEM_B(0X1F, ctx->r16) = ctx->r8;
L_800B6170:
    // 0x800B6170: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x800B6174: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x800B6178: lbu         $t2, 0x1E($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X1E);
    // 0x800B617C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B6180: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800B6184: lwc1        $f2, 0x0($t1)
    ctx->f2.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800B6188: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800B618C: beq         $t2, $zero, L_800B61E0
    if (ctx->r10 == 0) {
        // 0x800B6190: swc1        $f10, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
            goto L_800B61E0;
    }
    // 0x800B6190: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x800B6194: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800B6198: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B619C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800B61A0: swc1        $f2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
    // 0x800B61A4: jal         0x800DC178
    // 0x800B61A8: swc1        $f16, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f16.u32l;
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x800B61A8: swc1        $f16, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x800B61AC: mul.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800B61B0: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800B61B4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800B61B8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800B61BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B61C0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800B61C4: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800B61C8: jal         0x800DC178
    // 0x800B61CC: swc1        $f16, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f16.u32l;
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x800B61CC: swc1        $f16, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x800B61D0: mul.s       $f18, $f0, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800B61D4: lwc1        $f2, 0x50($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800B61D8: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800B61DC: add.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f18.fl;
L_800B61E0:
    // 0x800B61E0: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x800B61E4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800B61E8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800B61EC: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800B61F0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800B61F4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B61F8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800B61FC: lbu         $a0, 0x27($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X27);
    // 0x800B6200: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800B6204: nop

    // 0x800B6208: mul.s       $f18, $f4, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800B620C: sub.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x800B6210: mul.s       $f6, $f16, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800B6214: nop

    // 0x800B6218: mul.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800B621C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800B6220: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800B6224: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x800B6228: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x800B622C: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x800B6230: jal         0x800E257C
    // 0x800B6234: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    func_800E257C(rdram, ctx);
        goto after_4;
    // 0x800B6234: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    after_4:
    // 0x800B6238: lbu         $a0, 0x24($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X24);
    // 0x800B623C: lbu         $a1, 0x25($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X25);
    // 0x800B6240: jal         0x800E24F8
    // 0x800B6244: lbu         $a2, 0x26($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X26);
    func_800E24F8(rdram, ctx);
        goto after_5;
    // 0x800B6244: lbu         $a2, 0x26($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X26);
    after_5:
    // 0x800B6248: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800B624C: jal         0x800E2568
    // 0x800B6250: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    func_800E2568(rdram, ctx);
        goto after_6;
    // 0x800B6250: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_6:
    // 0x800B6254: jal         0x800E253C
    // 0x800B6258: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_800E253C(rdram, ctx);
        goto after_7;
    // 0x800B6258: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_7:
    // 0x800B625C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800B6260: jal         0x800E7988
    // 0x800B6264: lui         $a1, 0x8
    ctx->r5 = S32(0X8 << 16);
    func_800E7988(rdram, ctx);
        goto after_8;
    // 0x800B6264: lui         $a1, 0x8
    ctx->r5 = S32(0X8 << 16);
    after_8:
    // 0x800B6268: lh          $a2, 0x2A($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X2A);
    // 0x800B626C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800B6270: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800B6274: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    // 0x800B6278: jal         0x800E2E48
    // 0x800B627C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    func_800E2E48(rdram, ctx);
        goto after_9;
    // 0x800B627C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    after_9:
    // 0x800B6280: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800B6284: lwc1        $f18, 0x0($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800B6288: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800B628C: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800B6290: swc1        $f10, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f10.u32l;
    // 0x800B6294: jal         0x800E7A2C
    // 0x800B6298: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_800E7A2C(rdram, ctx);
        goto after_10;
    // 0x800B6298: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_10:
    // 0x800B629C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800B62A0: jal         0x800E7988
    // 0x800B62A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800E7988(rdram, ctx);
        goto after_11;
    // 0x800B62A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x800B62A8: sh          $zero, 0x2A($s0)
    MEM_H(0X2A, ctx->r16) = 0;
    // 0x800B62AC: lh          $t8, 0x2A($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2A);
    // 0x800B62B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800B62B4: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800B62B8: sh          $t8, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r24;
    // 0x800B62BC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800B62C0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800B62C4: jr          $ra
    // 0x800B62C8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800B62C8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80101038(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101038: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010103C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80101040: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80101044: jal         0x800EE7F8
    // 0x80101048: addiu       $a1, $a1, 0x5A70
    ctx->r5 = ADD32(ctx->r5, 0X5A70);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80101048: addiu       $a1, $a1, 0x5A70
    ctx->r5 = ADD32(ctx->r5, 0X5A70);
    after_0:
    // 0x8010104C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80101050: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80101054: jr          $ra
    // 0x80101058: nop

    return;
    // 0x80101058: nop

;}
RECOMP_FUNC void func_8010B330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010B330: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8010B334: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010B338: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010B33C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8010B340: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8010B344: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8010B348: jal         0x8010C460
    // 0x8010B34C: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    func_8010C460(rdram, ctx);
        goto after_0;
    // 0x8010B34C: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    after_0:
    // 0x8010B350: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8010B354: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8010B358: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8010B35C: jal         0x800EE7F8
    // 0x8010B360: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x8010B360: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_1:
    // 0x8010B364: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8010B368: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8010B36C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8010B370: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8010B374: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8010B378: jal         0x800EE7F8
    // 0x8010B37C: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x8010B37C: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x8010B380: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8010B384: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8010B388: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8010B38C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8010B390: addiu       $a2, $a2, 0x6F40
    ctx->r6 = ADD32(ctx->r6, 0X6F40);
    // 0x8010B394: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8010B398: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x8010B39C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8010B3A0: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x8010B3A4: jal         0x800C6A7C
    // 0x8010B3A8: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    func_800C6A7C(rdram, ctx);
        goto after_3;
    // 0x8010B3A8: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    after_3:
    // 0x8010B3AC: beql        $v0, $zero, L_8010B3FC
    if (ctx->r2 == 0) {
        // 0x8010B3B0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8010B3FC;
    }
    goto skip_0;
    // 0x8010B3B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8010B3B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8010B3B8: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8010B3BC: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    // 0x8010B3C0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8010B3C4: jal         0x800EE7F8
    // 0x8010B3C8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x8010B3C8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x8010B3CC: lh          $t6, 0x8E($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X8E);
    // 0x8010B3D0: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8010B3D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010B3D8: beq         $t6, $zero, L_8010B3F0
    if (ctx->r14 == 0) {
        // 0x8010B3DC: lui         $a1, 0x8013
        ctx->r5 = S32(0X8013 << 16);
            goto L_8010B3F0;
    }
    // 0x8010B3DC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8010B3E0: addiu       $a1, $a1, 0x6F40
    ctx->r5 = ADD32(ctx->r5, 0X6F40);
    // 0x8010B3E4: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x8010B3E8: jal         0x801045AC
    // 0x8010B3EC: lw          $a3, 0x8($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X8);
    func_801045AC(rdram, ctx);
        goto after_5;
    // 0x8010B3EC: lw          $a3, 0x8($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X8);
    after_5:
L_8010B3F0:
    // 0x8010B3F0: b           L_8010B3FC
    // 0x8010B3F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8010B3FC;
    // 0x8010B3F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8010B3F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010B3FC:
    // 0x8010B3FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010B400: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8010B404: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8010B408: jr          $ra
    // 0x8010B40C: nop

    return;
    // 0x8010B40C: nop

;}
RECOMP_FUNC void _fxrain_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088908: syscall     710
    recomp_syscall_handler(rdram, ctx, 0x80088908);
    return;
    // 0x8008890C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void suspline_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080075C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800760: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800764: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800768: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3202, 0XEB4) << 16);
    // 0x8080076C: lwc1        $f4, 0xEB4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3202, 0XEB4));
    // 0x80800770: lwc1        $f0, 0x58($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X58);
    // 0x80800774: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80800778: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080077C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800780: nop

    // 0x80800784: bc1fl       L_80800848
    if (!c1cs) {
        // 0x80800788: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800848;
    }
    goto skip_0;
    // 0x80800788: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8080078C: lbu         $t6, 0x8A($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X8A);
    // 0x80800790: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80800794: bnel        $t7, $zero, L_80800848
    if (ctx->r15 != 0) {
        // 0x80800798: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800848;
    }
    goto skip_1;
    // 0x80800798: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8080079C: lh          $t8, 0x7A($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X7A);
    // 0x808007A0: lui         $t2, 0x8009
    ctx->r10 = S32(0X8009 << 16);
    // 0x808007A4: addiu       $t2, $t2, -0x6EE8
    ctx->r10 = ADD32(ctx->r10, -0X6EE8);
    // 0x808007A8: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x808007AC: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x808007B0: lh          $t1, 0x68($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X68);
    // 0x808007B4: addu        $a1, $t1, $a0
    ctx->r5 = ADD32(ctx->r9, ctx->r4);
    // 0x808007B8: lh          $a0, 0x78($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X78);
    // 0x808007BC: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x808007C0: bne         $at, $zero, L_808007E8
    if (ctx->r1 != 0) {
        // 0x808007C4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_808007E8;
    }
    // 0x808007C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808007C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808007CC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808007D0: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x808007D4: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x808007D8: jal         0x80089140
    // 0x808007DC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    _mlspline_entrypoint_13(rdram, ctx);
        goto after_0;
    // 0x808007DC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x808007E0: b           L_80800844
    // 0x808007E4: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
        goto L_80800844;
    // 0x808007E4: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_808007E8:
    // 0x808007E8: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x808007EC: bne         $at, $zero, L_80800820
    if (ctx->r1 != 0) {
        // 0x808007F0: lui         $t4, 0x8009
        ctx->r12 = S32(0X8009 << 16);
            goto L_80800820;
    }
    // 0x808007F0: lui         $t4, 0x8009
    ctx->r12 = S32(0X8009 << 16);
    // 0x808007F4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808007F8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808007FC: lui         $t3, 0x8009
    ctx->r11 = S32(0X8009 << 16);
    // 0x80800800: addiu       $t3, $t3, -0x6EF0
    ctx->r11 = ADD32(ctx->r11, -0X6EF0);
    // 0x80800804: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800808: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x8080080C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80800810: jal         0x80089140
    // 0x80800814: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    _mlspline_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x80800814: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80800818: b           L_80800844
    // 0x8080081C: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
        goto L_80800844;
    // 0x8080081C: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_80800820:
    // 0x80800820: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800824: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800828: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080082C: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x80800830: addiu       $t4, $t4, -0x6EF8
    ctx->r12 = ADD32(ctx->r12, -0X6EF8);
    // 0x80800834: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80800838: jal         0x80089140
    // 0x8080083C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    _mlspline_entrypoint_13(rdram, ctx);
        goto after_2;
    // 0x8080083C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x80800840: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_80800844:
    // 0x80800844: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800848:
    // 0x80800848: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080084C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800850: jr          $ra
    // 0x80800854: nop

    return;
    // 0x80800854: nop

;}
RECOMP_FUNC void func_800F6478(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F6478: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F647C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F6480: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F6484: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F6488: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F648C: jal         0x800F424C
    // 0x800F6490: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_800F424C(rdram, ctx);
        goto after_0;
    // 0x800F6490: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F6494: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F6498: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F649C: jr          $ra
    // 0x800F64A0: nop

    return;
    // 0x800F64A0: nop

;}
