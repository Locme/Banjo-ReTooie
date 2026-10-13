#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void susplinet_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080044C: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x80800450: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800454: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800458: trunc.w.s   $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    ctx->f4.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x8080045C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800460: lh          $t6, 0x30($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X30);
    // 0x80800464: lh          $t7, 0x32($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X32);
    // 0x80800468: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8080046C: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80800470: addu        $a3, $a0, $t6
    ctx->r7 = ADD32(ctx->r4, ctx->r14);
    // 0x80800474: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x80800478: sll         $t3, $a1, 16
    ctx->r11 = S32(ctx->r5 << 16);
    // 0x8080047C: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80800480: sra         $a1, $t3, 16
    ctx->r5 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80800484: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80800488: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8080048C: jal         0x80800384
    // 0x80800490: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    func_80800384_susplinet(rdram, ctx);
        goto after_0;
    // 0x80800490: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x80800494: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80800498: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x8080049C: sll         $a1, $v1, 16
    ctx->r5 = S32(ctx->r3 << 16);
    // 0x808004A0: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x808004A4: lh          $t9, 0x4E($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X4E);
    // 0x808004A8: addiu       $a0, $t6, 0x1
    ctx->r4 = ADD32(ctx->r14, 0X1);
    // 0x808004AC: sll         $t0, $a0, 16
    ctx->r8 = S32(ctx->r4 << 16);
    // 0x808004B0: sll         $t1, $v1, 16
    ctx->r9 = S32(ctx->r3 << 16);
    // 0x808004B4: sll         $t2, $a0, 16
    ctx->r10 = S32(ctx->r4 << 16);
    // 0x808004B8: sra         $t8, $t0, 16
    ctx->r24 = S32(SIGNED(ctx->r8) >> 16);
    // 0x808004BC: sra         $t5, $t1, 16
    ctx->r13 = S32(SIGNED(ctx->r9) >> 16);
    // 0x808004C0: sra         $t7, $t2, 16
    ctx->r15 = S32(SIGNED(ctx->r10) >> 16);
    // 0x808004C4: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x808004C8: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x808004CC: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808004D0: or          $t1, $t5, $zero
    ctx->r9 = ctx->r13 | 0;
    // 0x808004D4: or          $t2, $t7, $zero
    ctx->r10 = ctx->r15 | 0;
    // 0x808004D8: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x808004DC: bne         $at, $zero, L_808004F8
    if (ctx->r1 != 0) {
        // 0x808004E0: or          $t0, $t8, $zero
        ctx->r8 = ctx->r24 | 0;
            goto L_808004F8;
    }
    // 0x808004E0: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x808004E4: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x808004E8: jal         0x808002AC
    // 0x808004EC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    susplinet_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x808004EC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x808004F0: b           L_80800614
    // 0x808004F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800614;
    // 0x808004F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808004F8:
    // 0x808004F8: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x808004FC: sll         $t4, $t0, 1
    ctx->r12 = S32(ctx->r8 << 1);
    // 0x80800500: addu        $t5, $a3, $t4
    ctx->r13 = ADD32(ctx->r7, ctx->r12);
    // 0x80800504: addu        $t3, $a3, $v0
    ctx->r11 = ADD32(ctx->r7, ctx->r2);
    // 0x80800508: lh          $v1, 0x0($t3)
    ctx->r3 = MEM_H(ctx->r11, 0X0);
    // 0x8080050C: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x80800510: beql        $v1, $t6, L_80800530
    if (ctx->r3 == ctx->r14) {
        // 0x80800514: mtc1        $v1, $f6
        ctx->f6.u32l = ctx->r3;
            goto L_80800530;
    }
    goto skip_0;
    // 0x80800514: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    skip_0:
    // 0x80800518: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8080051C: jal         0x808002AC
    // 0x80800520: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    susplinet_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x80800520: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x80800524: b           L_80800614
    // 0x80800528: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800614;
    // 0x80800528: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080052C: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
L_80800530:
    // 0x80800530: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80800534: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800538: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x8080053C: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x80800540: nop

    // 0x80800544: bc1fl       L_80800564
    if (!c1cs) {
        // 0x80800548: lh          $t9, 0x0($t8)
        ctx->r25 = MEM_H(ctx->r24, 0X0);
            goto L_80800564;
    }
    goto skip_1;
    // 0x80800548: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    skip_1:
    // 0x8080054C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80800550: jal         0x808002AC
    // 0x80800554: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    susplinet_entrypoint_10(rdram, ctx);
        goto after_3;
    // 0x80800554: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
    // 0x80800558: b           L_80800614
    // 0x8080055C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800614;
    // 0x8080055C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800560: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
L_80800564:
    // 0x80800564: addiu       $a0, $zero, 0x644
    ctx->r4 = ADD32(0, 0X644);
    // 0x80800568: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080056C: andi        $t3, $t9, 0x1
    ctx->r11 = ctx->r25 & 0X1;
    // 0x80800570: beql        $t3, $zero, L_80800608
    if (ctx->r11 == 0) {
        // 0x80800574: mfc1        $a1, $f12
        ctx->r5 = (int32_t)ctx->f12.u32l;
            goto L_80800608;
    }
    goto skip_2;
    // 0x80800574: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    skip_2:
    // 0x80800578: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080057C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80800580: sh          $t1, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r9;
    // 0x80800584: jal         0x800DA9E4
    // 0x80800588: sh          $t2, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r10;
    func_800DA9E4(rdram, ctx);
        goto after_4;
    // 0x80800588: sh          $t2, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r10;
    after_4:
    // 0x8080058C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80800590: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80800594: lh          $t1, 0x1C($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X1C);
    // 0x80800598: bne         $v0, $zero, L_808005D0
    if (ctx->r2 != 0) {
        // 0x8080059C: lh          $t2, 0x1A($sp)
        ctx->r10 = MEM_H(ctx->r29, 0X1A);
            goto L_808005D0;
    }
    // 0x8080059C: lh          $t2, 0x1A($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X1A);
    // 0x808005A0: sll         $t4, $t1, 1
    ctx->r12 = S32(ctx->r9 << 1);
    // 0x808005A4: addu        $t5, $a3, $t4
    ctx->r13 = ADD32(ctx->r7, ctx->r12);
    // 0x808005A8: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x808005AC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808005B0: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x808005B4: nop

    // 0x808005B8: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808005BC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x808005C0: jal         0x808002AC
    // 0x808005C4: nop

    susplinet_entrypoint_10(rdram, ctx);
        goto after_5;
    // 0x808005C4: nop

    after_5:
    // 0x808005C8: b           L_80800614
    // 0x808005CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800614;
    // 0x808005CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808005D0:
    // 0x808005D0: sll         $t7, $t2, 1
    ctx->r15 = S32(ctx->r10 << 1);
    // 0x808005D4: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x808005D8: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x808005DC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808005E0: addiu       $t3, $t9, 0x1
    ctx->r11 = ADD32(ctx->r25, 0X1);
    // 0x808005E4: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x808005E8: nop

    // 0x808005EC: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808005F0: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x808005F4: jal         0x808002AC
    // 0x808005F8: nop

    susplinet_entrypoint_10(rdram, ctx);
        goto after_6;
    // 0x808005F8: nop

    after_6:
    // 0x808005FC: b           L_80800614
    // 0x80800600: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800614;
    // 0x80800600: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800604: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
L_80800608:
    // 0x80800608: jal         0x808002AC
    // 0x8080060C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    susplinet_entrypoint_10(rdram, ctx);
        goto after_7;
    // 0x8080060C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_7:
    // 0x80800610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800614:
    // 0x80800614: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800618: jr          $ra
    // 0x8080061C: nop

    return;
    // 0x8080061C: nop

;}
RECOMP_FUNC void _subaddiedialog_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A1B0: syscall     830
    recomp_syscall_handler(rdram, ctx, 0x8008A1B0);
    return;
    // 0x8008A1B4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808009C4_chburgerstand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009C4: jr          $ra
    // 0x808009C8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x808009C8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void ncbafixpos_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800034: jr          $ra
    // 0x80800038: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800038: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800BDBC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BDBC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BDBC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BDBCC: jal         0x800BD97C
    // 0x800BDBD0: nop

    func_800BD97C(rdram, ctx);
        goto after_0;
    // 0x800BDBD0: nop

    after_0:
    // 0x800BDBD4: jal         0x800BDB9C
    // 0x800BDBD8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800BDB9C(rdram, ctx);
        goto after_1;
    // 0x800BDBD8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800BDBDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BDBE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BDBE4: jr          $ra
    // 0x800BDBE8: nop

    return;
    // 0x800BDBE8: nop

;}
RECOMP_FUNC void func_80800518_chprisonbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800518: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8080051C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800520: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800524: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800528: jal         0x80100094
    // 0x8080052C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080052C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800530: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80800534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800538: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x8080053C: jal         0x8010C820
    // 0x80800540: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    func_8010C820(rdram, ctx);
        goto after_1;
    // 0x80800540: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    after_1:
    // 0x80800544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800548: jal         0x80100094
    // 0x8080054C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x8080054C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800550: beq         $v0, $zero, L_80800570
    if (ctx->r2 == 0) {
        // 0x80800554: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80800570;
    }
    // 0x80800554: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800558: jal         0x80100094
    // 0x8080055C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x8080055C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800560: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800564: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800568: jal         0x800897D8
    // 0x8080056C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_4;
    // 0x8080056C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
L_80800570:
    // 0x80800570: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800574: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800578: addiu       $t8, $t7, -0x2
    ctx->r24 = ADD32(ctx->r15, -0X2);
    // 0x8080057C: sltiu       $at, $t8, 0x9
    ctx->r1 = ctx->r24 < 0X9 ? 1 : 0;
    // 0x80800580: beq         $at, $zero, L_808008F8
    if (ctx->r1 == 0) {
        // 0x80800584: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808008F8;
    }
    // 0x80800584: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800588: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1932, 0XEF0) << 16);
    // 0x8080058C: addu        $at, $at, $t8
    gpr jr_addend_80800594 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800590: lw          $t8, 0xEF0($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1932, 0XEF0));
    // 0x80800594: jr          $t8
    // 0x80800598: nop

    switch (jr_addend_80800594 >> 2) {
        case 0: goto L_80800604; break;
        case 1: goto L_8080059C; break;
        case 2: goto L_80800830; break;
        case 3: goto L_80800728; break;
        case 4: goto L_80800748; break;
        case 5: goto L_80800760; break;
        case 6: goto L_80800850; break;
        case 7: goto L_808008F8; break;
        case 8: goto L_808008F8; break;
        default: switch_error(__func__, 0x80800594, 0x80800EF0);
    }
    // 0x80800598: nop

L_8080059C:
    // 0x8080059C: jal         0x80800BB4
    // 0x808005A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800BB4_chprisonbits(rdram, ctx);
        goto after_5;
    // 0x808005A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808005A4: bnel        $v0, $zero, L_808008FC
    if (ctx->r2 != 0) {
        // 0x808005A8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808008FC;
    }
    goto skip_0;
    // 0x808005A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808005AC: jal         0x80800C84
    // 0x808005B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800C84_chprisonbits(rdram, ctx);
        goto after_6;
    // 0x808005B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808005B4: bnel        $v0, $zero, L_808008FC
    if (ctx->r2 != 0) {
        // 0x808005B8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808008FC;
    }
    goto skip_1;
    // 0x808005B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x808005BC: jal         0x80800DFC
    // 0x808005C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800DFC_chprisonbits(rdram, ctx);
        goto after_7;
    // 0x808005C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808005C4: beq         $v0, $zero, L_808005DC
    if (ctx->r2 == 0) {
        // 0x808005C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005DC;
    }
    // 0x808005C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808005D0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808005D4: b           L_808005E8
    // 0x808005D8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
        goto L_808005E8;
    // 0x808005D8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
L_808005DC:
    // 0x808005DC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1932, 0XF14) << 16);
    // 0x808005E0: lwc1        $f0, 0xF14($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1932, 0XF14));
    // 0x808005E4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
L_808005E8:
    // 0x808005E8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x808005EC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808005F0: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    // 0x808005F4: jal         0x80102128
    // 0x808005F8: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    func_80102128(rdram, ctx);
        goto after_8;
    // 0x808005F8: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    after_8:
    // 0x808005FC: b           L_808008FC
    // 0x80800600: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808008FC;
    // 0x80800600: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800604:
    // 0x80800604: jal         0x80800DFC
    // 0x80800608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800DFC_chprisonbits(rdram, ctx);
        goto after_9;
    // 0x80800608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080060C: beq         $v0, $zero, L_80800664
    if (ctx->r2 == 0) {
        // 0x80800610: lui         $at, 0x43E1
        ctx->r1 = S32(0X43E1 << 16);
            goto L_80800664;
    }
    // 0x80800610: lui         $at, 0x43E1
    ctx->r1 = S32(0X43E1 << 16);
    // 0x80800614: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800618: jal         0x800D8FF8
    // 0x8080061C: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_10;
    // 0x8080061C: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    after_10:
    // 0x80800620: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x80800624: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080062C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80800630: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800634: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800638: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8080063C: jal         0x8010CE70
    // 0x80800640: nop

    func_8010CE70(rdram, ctx);
        goto after_11;
    // 0x80800640: nop

    after_11:
    // 0x80800644: lui         $a1, 0x30
    ctx->r5 = S32(0X30 << 16);
    // 0x80800648: ori         $a1, $a1, 0x105
    ctx->r5 = ctx->r5 | 0X105;
    // 0x8080064C: jal         0x8010B990
    // 0x80800650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010B990(rdram, ctx);
        goto after_12;
    // 0x80800650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800654: jal         0x80800BB4
    // 0x80800658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800BB4_chprisonbits(rdram, ctx);
        goto after_13;
    // 0x80800658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8080065C: b           L_808008FC
    // 0x80800660: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808008FC;
    // 0x80800660: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800664:
    // 0x80800664: jal         0x80800BB4
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800BB4_chprisonbits(rdram, ctx);
        goto after_14;
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x8080066C: bne         $v0, $zero, L_808006A0
    if (ctx->r2 != 0) {
        // 0x80800670: nop
    
            goto L_808006A0;
    }
    // 0x80800670: nop

    // 0x80800674: jal         0x80800C84
    // 0x80800678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800C84_chprisonbits(rdram, ctx);
        goto after_15;
    // 0x80800678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x8080067C: bne         $v0, $zero, L_808006A0
    if (ctx->r2 != 0) {
        // 0x80800680: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006A0;
    }
    // 0x80800680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800684: lui         $a3, 0x3E99
    ctx->r7 = S32(0X3E99 << 16);
    // 0x80800688: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8080068C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800690: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80800694: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    // 0x80800698: jal         0x80102128
    // 0x8080069C: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    func_80102128(rdram, ctx);
        goto after_16;
    // 0x8080069C: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_16:
L_808006A0:
    // 0x808006A0: jal         0x800D8FF8
    // 0x808006A4: nop

    func_800D8FF8(rdram, ctx);
        goto after_17;
    // 0x808006A4: nop

    after_17:
    // 0x808006A8: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x808006AC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808006B0: lui         $t3, 0x30
    ctx->r11 = S32(0X30 << 16);
    // 0x808006B4: ori         $t3, $t3, 0x105
    ctx->r11 = ctx->r11 | 0X105;
    // 0x808006B8: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x808006BC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x808006C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006C4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x808006C8: lui         $a2, 0x43D2
    ctx->r6 = S32(0X43D2 << 16);
    // 0x808006CC: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x808006D0: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x808006D4: jal         0x8010BF4C
    // 0x808006D8: nop

    func_8010BF4C(rdram, ctx);
        goto after_18;
    // 0x808006D8: nop

    after_18:
    // 0x808006DC: andi        $t4, $v0, 0x24
    ctx->r12 = ctx->r2 & 0X24;
    // 0x808006E0: beq         $t4, $zero, L_80800700
    if (ctx->r12 == 0) {
        // 0x808006E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800700;
    }
    // 0x808006E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006E8: jal         0x80102CF4
    // 0x808006EC: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    func_80102CF4(rdram, ctx);
        goto after_19;
    // 0x808006EC: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    after_19:
    // 0x808006F0: beql        $v0, $zero, L_80800704
    if (ctx->r2 == 0) {
        // 0x808006F4: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80800704;
    }
    goto skip_2;
    // 0x808006F4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    skip_2:
    // 0x808006F8: jal         0x80800DAC
    // 0x808006FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800DAC_chprisonbits(rdram, ctx);
        goto after_20;
    // 0x808006FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
L_80800700:
    // 0x80800700: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
L_80800704:
    // 0x80800704: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x80800708: jal         0x800F0064
    // 0x8080070C: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    func_800F0064(rdram, ctx);
        goto after_21;
    // 0x8080070C: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    after_21:
    // 0x80800710: beql        $v0, $zero, L_808008FC
    if (ctx->r2 == 0) {
        // 0x80800714: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808008FC;
    }
    goto skip_3;
    // 0x80800714: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x80800718: jal         0x80800DAC
    // 0x8080071C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800DAC_chprisonbits(rdram, ctx);
        goto after_22;
    // 0x8080071C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80800720: b           L_808008FC
    // 0x80800724: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808008FC;
    // 0x80800724: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800728:
    // 0x80800728: jal         0x80800C84
    // 0x8080072C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800C84_chprisonbits(rdram, ctx);
        goto after_23;
    // 0x8080072C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80800730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800734: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800738: jal         0x8010CE70
    // 0x8080073C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_8010CE70(rdram, ctx);
        goto after_24;
    // 0x8080073C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_24:
    // 0x80800740: b           L_808008FC
    // 0x80800744: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808008FC;
    // 0x80800744: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800748:
    // 0x80800748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080074C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80800750: jal         0x8010CE70
    // 0x80800754: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    func_8010CE70(rdram, ctx);
        goto after_25;
    // 0x80800754: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_25:
    // 0x80800758: b           L_808008FC
    // 0x8080075C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808008FC;
    // 0x8080075C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800760:
    // 0x80800760: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x80800764: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800768: jal         0x800D8FF8
    // 0x8080076C: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_26;
    // 0x8080076C: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    after_26:
    // 0x80800770: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x80800774: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800778: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8080077C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800780: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800784: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x80800788: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8080078C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80800790: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800794: jal         0x80102844
    // 0x80800798: nop

    func_80102844(rdram, ctx);
        goto after_27;
    // 0x80800798: nop

    after_27:
    // 0x8080079C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007A0: jal         0x8010B990
    // 0x808007A4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_8010B990(rdram, ctx);
        goto after_28;
    // 0x808007A4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_28:
    // 0x808007A8: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x808007AC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808007B0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808007B4: jal         0x800F0064
    // 0x808007B8: lui         $a1, 0x42F0
    ctx->r5 = S32(0X42F0 << 16);
    func_800F0064(rdram, ctx);
        goto after_29;
    // 0x808007B8: lui         $a1, 0x42F0
    ctx->r5 = S32(0X42F0 << 16);
    after_29:
    // 0x808007BC: beql        $v0, $zero, L_808008FC
    if (ctx->r2 == 0) {
        // 0x808007C0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808008FC;
    }
    goto skip_4;
    // 0x808007C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x808007C4: jal         0x80085750
    // 0x808007C8: nop

    _capod_entrypoint_22(rdram, ctx);
        goto after_30;
    // 0x808007C8: nop

    after_30:
    // 0x808007CC: jal         0x800F54E4
    // 0x808007D0: nop

    func_800F54E4(rdram, ctx);
        goto after_31;
    // 0x808007D0: nop

    after_31:
    // 0x808007D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808007D8: jal         0x800F7F98
    // 0x808007DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F7F98(rdram, ctx);
        goto after_32;
    // 0x808007DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_32:
    // 0x808007E0: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x808007E4: addiu       $t5, $zero, 0x2000
    ctx->r13 = ADD32(0, 0X2000);
    // 0x808007E8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x808007EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007F0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x808007F4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808007F8: jal         0x8008A2C8
    // 0x808007FC: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_33;
    // 0x808007FC: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_33:
    // 0x80800800: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800804: addiu       $t6, $zero, 0x32
    ctx->r14 = ADD32(0, 0X32);
    // 0x80800808: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080080C: addiu       $a1, $zero, 0xF18
    ctx->r5 = ADD32(0, 0XF18);
    // 0x80800810: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800814: jal         0x8008A208
    // 0x80800818: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_34;
    // 0x80800818: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    after_34:
    // 0x8080081C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800820: jal         0x80102424
    // 0x80800824: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_35;
    // 0x80800824: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_35:
    // 0x80800828: b           L_808008FC
    // 0x8080082C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808008FC;
    // 0x8080082C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800830:
    // 0x80800830: jal         0x80800C18
    // 0x80800834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800C18_chprisonbits(rdram, ctx);
        goto after_36;
    // 0x80800834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x80800838: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080083C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80800840: jal         0x8010CE70
    // 0x80800844: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    func_8010CE70(rdram, ctx);
        goto after_37;
    // 0x80800844: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_37:
    // 0x80800848: b           L_808008FC
    // 0x8080084C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808008FC;
    // 0x8080084C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800850:
    // 0x80800850: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x80800854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800858: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    // 0x8080085C: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x80800860: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800864: jal         0x80102844
    // 0x80800868: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    func_80102844(rdram, ctx);
        goto after_38;
    // 0x80800868: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_38:
    // 0x8080086C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800870: jal         0x80102CF4
    // 0x80800874: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    func_80102CF4(rdram, ctx);
        goto after_39;
    // 0x80800874: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    after_39:
    // 0x80800878: beql        $v0, $zero, L_808008FC
    if (ctx->r2 == 0) {
        // 0x8080087C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808008FC;
    }
    goto skip_5;
    // 0x8080087C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x80800880: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x80800884: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80800888: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080088C: lwc1        $f16, 0x10($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80800890: addiu       $t7, $zero, 0x1005
    ctx->r15 = ADD32(0, 0X1005);
    // 0x80800894: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800898: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    // 0x8080089C: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808008A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008A4: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x808008A8: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    // 0x808008AC: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x808008B0: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x808008B4: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x808008B8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808008BC: jal         0x8010BF4C
    // 0x808008C0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8010BF4C(rdram, ctx);
        goto after_40;
    // 0x808008C0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_40:
    // 0x808008C4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808008C8: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x808008CC: jal         0x800F0064
    // 0x808008D0: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    func_800F0064(rdram, ctx);
        goto after_41;
    // 0x808008D0: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_41:
    // 0x808008D4: beql        $v0, $zero, L_808008FC
    if (ctx->r2 == 0) {
        // 0x808008D8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808008FC;
    }
    goto skip_6;
    // 0x808008D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_6:
    // 0x808008DC: jal         0x80088488
    // 0x808008E0: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    _glsplinefind_entrypoint_1(rdram, ctx);
        goto after_42;
    // 0x808008E0: addiu       $a0, $zero, 0x127
    ctx->r4 = ADD32(0, 0X127);
    after_42:
    // 0x808008E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808008EC: lw          $a2, 0x24($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X24);
    // 0x808008F0: jal         0x801058C4
    // 0x808008F4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_801058C4(rdram, ctx);
        goto after_43;
    // 0x808008F4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_43:
L_808008F8:
    // 0x808008F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808008FC:
    // 0x808008FC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800900: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800904: jr          $ra
    // 0x80800908: nop

    return;
    // 0x80800908: nop

;}
RECOMP_FUNC void func_8009D3D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D3D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009D3DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009D3E0: jal         0x8009E674
    // 0x8009D3E4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E674(rdram, ctx);
        goto after_0;
    // 0x8009D3E4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x8009D3E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009D3EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009D3F0: jr          $ra
    // 0x8009D3F4: nop

    return;
    // 0x8009D3F4: nop

;}
RECOMP_FUNC void func_808007E4_chseaweedbaddy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808007F0: lw          $t6, 0x78($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X78);
    // 0x808007F4: sll         $t8, $t6, 29
    ctx->r24 = S32(ctx->r14 << 29);
    // 0x808007F8: bltzl       $t8, L_80800820
    if (SIGNED(ctx->r24) < 0) {
        // 0x808007FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800820;
    }
    goto skip_0;
    // 0x808007FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800800: lhu         $t9, 0x72($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X72);
    // 0x80800804: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800808: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x8080080C: beql        $t0, $at, L_80800820
    if (ctx->r8 == ctx->r1) {
        // 0x80800810: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800820;
    }
    goto skip_1;
    // 0x80800810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800814: jal         0x80800710
    // 0x80800818: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800710_chseaweedbaddy(rdram, ctx);
        goto after_0;
    // 0x80800818: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x8080081C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800820:
    // 0x80800820: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800824: jr          $ra
    // 0x80800828: nop

    return;
    // 0x80800828: nop

;}
RECOMP_FUNC void suquiz_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800494: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80800498: lw          $t6, 0x7614($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7614);
    // 0x8080049C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004A4: beql        $t6, $zero, L_808004CC
    if (ctx->r14 == 0) {
        // 0x808004A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808004CC;
    }
    goto skip_0;
    // 0x808004A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808004AC: jal         0x800DA524
    // 0x808004B0: addiu       $a0, $zero, 0x6B6
    ctx->r4 = ADD32(0, 0X6B6);
    func_800DA524(rdram, ctx);
        goto after_0;
    // 0x808004B0: addiu       $a0, $zero, 0x6B6
    ctx->r4 = ADD32(0, 0X6B6);
    after_0:
    // 0x808004B4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x808004B8: jal         0x8001B084
    // 0x808004BC: lw          $a0, 0x7614($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7614);
    heap_free(rdram, ctx);
        goto after_1;
    // 0x808004BC: lw          $a0, 0x7614($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7614);
    after_1:
    // 0x808004C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x808004C4: sw          $zero, 0x7614($at)
    MEM_W(0X7614, ctx->r1) = 0;
    // 0x808004C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808004CC:
    // 0x808004CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004D0: jr          $ra
    // 0x808004D4: nop

    return;
    // 0x808004D4: nop

;}
RECOMP_FUNC void func_800F9F90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9F90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F9F94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F9F98: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800F9F9C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800F9FA0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800F9FA4: lw          $t7, 0x2C($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X2C);
    // 0x800F9FA8: addiu       $s0, $a0, 0x8
    ctx->r16 = ADD32(ctx->r4, 0X8);
    // 0x800F9FAC: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800F9FB0: addu        $s1, $t8, $a0
    ctx->r17 = ADD32(ctx->r24, ctx->r4);
    // 0x800F9FB4: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x800F9FB8: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x800F9FBC: beq         $at, $zero, L_800F9FEC
    if (ctx->r1 == 0) {
        // 0x800F9FC0: nop
    
            goto L_800F9FEC;
    }
    // 0x800F9FC0: nop

    // 0x800F9FC4: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
L_800F9FC8:
    // 0x800F9FC8: beql        $a0, $zero, L_800F9FE0
    if (ctx->r4 == 0) {
        // 0x800F9FCC: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_800F9FE0;
    }
    goto skip_0;
    // 0x800F9FCC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    skip_0:
    // 0x800F9FD0: jal         0x8001BAFC
    // 0x800F9FD4: nop

    defrag(rdram, ctx);
        goto after_0;
    // 0x800F9FD4: nop

    after_0:
    // 0x800F9FD8: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x800F9FDC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_800F9FE0:
    // 0x800F9FE0: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x800F9FE4: bnel        $at, $zero, L_800F9FC8
    if (ctx->r1 != 0) {
        // 0x800F9FE8: lw          $a0, 0x4($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X4);
            goto L_800F9FC8;
    }
    goto skip_1;
    // 0x800F9FE8: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    skip_1:
L_800F9FEC:
    // 0x800F9FEC: jal         0x8001BAFC
    // 0x800F9FF0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    defrag(rdram, ctx);
        goto after_1;
    // 0x800F9FF0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x800F9FF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F9FF8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800F9FFC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800FA000: jr          $ra
    // 0x800FA004: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800FA004: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800FA008: nop

    // 0x800FA00C: nop

;}
RECOMP_FUNC void _gccollectDll_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088050: syscall     666
    recomp_syscall_handler(rdram, ctx, 0x80088050);
    return;
    // 0x80088054: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_80800388_chnicecavemenguard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800388: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080038C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800390: jal         0x8080080C
    // 0x80800394: nop

    func_8080080C_chnicecavemenguard(rdram, ctx);
        goto after_0;
    // 0x80800394: nop

    after_0:
    // 0x80800398: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080039C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003A0: jr          $ra
    // 0x808003A4: nop

    return;
    // 0x808003A4: nop

;}
RECOMP_FUNC void func_80800DA4_chmusicmenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DA4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800DA8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800DAC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800DB0: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800DB4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800DB8: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800DBC: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800DC0: sltiu       $at, $t8, 0x7
    ctx->r1 = ctx->r24 < 0X7 ? 1 : 0;
    // 0x80800DC4: beq         $at, $zero, L_80800F3C
    if (ctx->r1 == 0) {
        // 0x80800DC8: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800F3C;
    }
    // 0x80800DC8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800DCC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1824, 0X1284) << 16);
    // 0x80800DD0: addu        $at, $at, $t8
    gpr jr_addend_80800DD8 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800DD4: lw          $t8, 0x1284($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1824, 0X1284));
    // 0x80800DD8: jr          $t8
    // 0x80800DDC: nop

    switch (jr_addend_80800DD8 >> 2) {
        case 0: goto L_80800E80; break;
        case 1: goto L_80800E3C; break;
        case 2: goto L_80800EEC; break;
        case 3: goto L_80800DE0; break;
        case 4: goto L_80800F3C; break;
        case 5: goto L_80800F3C; break;
        case 6: goto L_80800F00; break;
        default: switch_error(__func__, 0x80800DD8, 0x80801284);
    }
    // 0x80800DDC: nop

L_80800DE0:
    // 0x80800DE0: jal         0x8010C500
    // 0x80800DE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C500(rdram, ctx);
        goto after_0;
    // 0x80800DE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800DE8: beql        $v0, $zero, L_80800F40
    if (ctx->r2 == 0) {
        // 0x80800DEC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800F40;
    }
    goto skip_0;
    // 0x80800DEC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800DF0: jal         0x800DA298
    // 0x80800DF4: addiu       $a0, $zero, 0x3E1
    ctx->r4 = ADD32(0, 0X3E1);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800DF4: addiu       $a0, $zero, 0x3E1
    ctx->r4 = ADD32(0, 0X3E1);
    after_1:
    // 0x80800DF8: bne         $v0, $zero, L_80800E1C
    if (ctx->r2 != 0) {
        // 0x80800DFC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800E1C;
    }
    // 0x80800DFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800E00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E04: jal         0x80800930
    // 0x80800E08: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800930_chmusicmenu(rdram, ctx);
        goto after_2;
    // 0x80800E08: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_2:
    // 0x80800E0C: jal         0x800DA544
    // 0x80800E10: addiu       $a0, $zero, 0x3E1
    ctx->r4 = ADD32(0, 0X3E1);
    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x80800E10: addiu       $a0, $zero, 0x3E1
    ctx->r4 = ADD32(0, 0X3E1);
    after_3:
    // 0x80800E14: b           L_80800F40
    // 0x80800E18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800F40;
    // 0x80800E18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800E1C:
    // 0x80800E1C: jal         0x80016B30
    // 0x80800E20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80016B30(rdram, ctx);
        goto after_4;
    // 0x80800E20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800E24: beq         $v0, $zero, L_80800F3C
    if (ctx->r2 == 0) {
        // 0x80800E28: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800F3C;
    }
    // 0x80800E28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E2C: jal         0x80800930
    // 0x80800E30: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800930_chmusicmenu(rdram, ctx);
        goto after_5;
    // 0x80800E30: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_5:
    // 0x80800E34: b           L_80800F40
    // 0x80800E38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800F40;
    // 0x80800E38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800E3C:
    // 0x80800E3C: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
    // 0x80800E40: sll         $t1, $t9, 12
    ctx->r9 = S32(ctx->r25 << 12);
    // 0x80800E44: bgezl       $t1, L_80800E84
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80800E48: lhu         $v0, 0x76($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X76);
            goto L_80800E84;
    }
    goto skip_1;
    // 0x80800E48: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
    skip_1:
    // 0x80800E4C: jal         0x800D90A4
    // 0x80800E50: addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    func_800D90A4(rdram, ctx);
        goto after_6;
    // 0x80800E50: addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    after_6:
    // 0x80800E54: beql        $v0, $zero, L_80800E84
    if (ctx->r2 == 0) {
        // 0x80800E58: lhu         $v0, 0x76($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X76);
            goto L_80800E84;
    }
    goto skip_2;
    // 0x80800E58: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
    skip_2:
    // 0x80800E5C: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
    // 0x80800E60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E64: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800E68: srl         $t2, $a1, 7
    ctx->r10 = S32(U32(ctx->r5) >> 7);
    // 0x80800E6C: jal         0x80800560
    // 0x80800E70: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    func_80800560_chmusicmenu(rdram, ctx);
        goto after_7;
    // 0x80800E70: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    after_7:
    // 0x80800E74: lbu         $t3, 0x65($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X65);
    // 0x80800E78: andi        $t4, $t3, 0xFFF7
    ctx->r12 = ctx->r11 & 0XFFF7;
    // 0x80800E7C: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
L_80800E80:
    // 0x80800E80: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
L_80800E84:
    // 0x80800E84: srl         $t5, $v0, 7
    ctx->r13 = S32(U32(ctx->r2) >> 7);
    // 0x80800E88: beql        $t5, $zero, L_80800ED4
    if (ctx->r13 == 0) {
        // 0x80800E8C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800ED4;
    }
    goto skip_3;
    // 0x80800E8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x80800E90: jal         0x800FCCD4
    // 0x80800E94: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    func_800FCCD4(rdram, ctx);
        goto after_8;
    // 0x80800E94: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_8:
    // 0x80800E98: beq         $v0, $zero, L_80800EB8
    if (ctx->r2 == 0) {
        // 0x80800E9C: nop
    
            goto L_80800EB8;
    }
    // 0x80800E9C: nop

    // 0x80800EA0: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x80800EA4: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80800EA8: bltz        $t8, L_80800EB8
    if (SIGNED(ctx->r24) < 0) {
        // 0x80800EAC: nop
    
            goto L_80800EB8;
    }
    // 0x80800EAC: nop

    // 0x80800EB0: jal         0x80800400
    // 0x80800EB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800400_chmusicmenu(rdram, ctx);
        goto after_9;
    // 0x80800EB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
L_80800EB8:
    // 0x80800EB8: jal         0x800D90A4
    // 0x80800EBC: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_10;
    // 0x80800EBC: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_10:
    // 0x80800EC0: beql        $v0, $zero, L_80800ED4
    if (ctx->r2 == 0) {
        // 0x80800EC4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800ED4;
    }
    goto skip_4;
    // 0x80800EC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_4:
    // 0x80800EC8: jal         0x80800000
    // 0x80800ECC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_chmusicmenu(rdram, ctx);
        goto after_11;
    // 0x80800ECC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800ED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800ED4:
    // 0x80800ED4: jal         0x80100094
    // 0x80800ED8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_12;
    // 0x80800ED8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80800EDC: jal         0x80087C98
    // 0x80800EE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _gcnewoption_entrypoint_0(rdram, ctx);
        goto after_13;
    // 0x80800EE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_13:
    // 0x80800EE4: b           L_80800F40
    // 0x80800EE8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800F40;
    // 0x80800EE8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800EEC:
    // 0x80800EEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EF0: jal         0x80800930
    // 0x80800EF4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800930_chmusicmenu(rdram, ctx);
        goto after_14;
    // 0x80800EF4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_14:
    // 0x80800EF8: b           L_80800F40
    // 0x80800EFC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800F40;
    // 0x80800EFC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800F00:
    // 0x80800F00: jal         0x8010C500
    // 0x80800F04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C500(rdram, ctx);
        goto after_15;
    // 0x80800F04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800F08: beq         $v0, $zero, L_80800F3C
    if (ctx->r2 == 0) {
        // 0x80800F0C: addiu       $a1, $zero, 0x1048
        ctx->r5 = ADD32(0, 0X1048);
            goto L_80800F3C;
    }
    // 0x80800F0C: addiu       $a1, $zero, 0x1048
    ctx->r5 = ADD32(0, 0X1048);
    // 0x80800F10: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800F14: addiu       $t9, $zero, 0x6F
    ctx->r25 = ADD32(0, 0X6F);
    // 0x80800F18: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800F1C: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x80800F20: jal         0x8008A208
    // 0x80800F24: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_16;
    // 0x80800F24: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_16:
    // 0x80800F28: jal         0x800DA544
    // 0x80800F2C: addiu       $a0, $zero, 0x344
    ctx->r4 = ADD32(0, 0X344);
    func_800DA544(rdram, ctx);
        goto after_17;
    // 0x80800F2C: addiu       $a0, $zero, 0x344
    ctx->r4 = ADD32(0, 0X344);
    after_17:
    // 0x80800F30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F34: jal         0x80800930
    // 0x80800F38: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800930_chmusicmenu(rdram, ctx);
        goto after_18;
    // 0x80800F38: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_18:
L_80800F3C:
    // 0x80800F3C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800F40:
    // 0x80800F40: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800F44: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800F48: jr          $ra
    // 0x80800F4C: nop

    return;
    // 0x80800F4C: nop

;}
RECOMP_FUNC void func_800F86C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F86C4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F86C8: addiu       $v0, $v0, 0x5490
    ctx->r2 = ADD32(ctx->r2, 0X5490);
    // 0x800F86CC: sh          $a0, 0x50($v0)
    MEM_H(0X50, ctx->r2) = ctx->r4;
    // 0x800F86D0: jr          $ra
    // 0x800F86D4: sh          $a1, 0x52($v0)
    MEM_H(0X52, ctx->r2) = ctx->r5;
    return;
    // 0x800F86D4: sh          $a1, 0x52($v0)
    MEM_H(0X52, ctx->r2) = ctx->r5;
;}
RECOMP_FUNC void func_80091EF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091EF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80091EF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80091EF8: jal         0x80091FE4
    // 0x80091EFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80091FE4(rdram, ctx);
        goto after_0;
    // 0x80091EFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80091F00: beq         $v0, $zero, L_80091F18
    if (ctx->r2 == 0) {
        // 0x80091F04: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80091F18;
    }
    // 0x80091F04: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80091F08: jal         0x80091F74
    // 0x80091F0C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80091F74(rdram, ctx);
        goto after_1;
    // 0x80091F0C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x80091F10: b           L_80091F24
    // 0x80091F14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80091F24;
    // 0x80091F14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80091F18:
    // 0x80091F18: jal         0x80091F74
    // 0x80091F1C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80091F74(rdram, ctx);
        goto after_2;
    // 0x80091F1C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80091F20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80091F24:
    // 0x80091F24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80091F28: jr          $ra
    // 0x80091F2C: nop

    return;
    // 0x80091F2C: nop

;}
RECOMP_FUNC void func_800A69F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A69F0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800A69F4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800A69F8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800A69FC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800A6A00: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800A6A04: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A6A08: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800A6A0C: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x800A6A10: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x800A6A14: jal         0x800EE7F8
    // 0x800A6A18: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800A6A18: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    after_0:
    // 0x800A6A1C: lwc1        $f0, 0x24($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X24);
    // 0x800A6A20: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800A6A24: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x800A6A28: jal         0x800F2100
    // 0x800A6A2C: sub.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_1;
    // 0x800A6A2C: sub.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f0.fl;
    after_1:
    // 0x800A6A30: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A6A34: lwc1        $f6, 0x55DC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X55DC);
    // 0x800A6A38: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800A6A3C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800A6A40: nop

    // 0x800A6A44: bc1t        L_800A6A68
    if (c1cs) {
        // 0x800A6A48: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_800A6A68;
    }
    // 0x800A6A48: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A6A4C: lwc1        $f8, 0x55E0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X55E0);
    // 0x800A6A50: lwc1        $f10, 0x4($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X4);
    // 0x800A6A54: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x800A6A58: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800A6A5C: nop

    // 0x800A6A60: bc1f        L_800A6AA8
    if (!c1cs) {
        // 0x800A6A64: nop
    
            goto L_800A6AA8;
    }
    // 0x800A6A64: nop

L_800A6A68:
    // 0x800A6A68: lhu         $a0, 0x76($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X76);
    // 0x800A6A6C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800A6A70: srl         $t7, $a0, 7
    ctx->r15 = S32(U32(ctx->r4) >> 7);
    // 0x800A6A74: jal         0x800F5680
    // 0x800A6A78: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_800F5680(rdram, ctx);
        goto after_2;
    // 0x800A6A78: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_2:
    // 0x800A6A7C: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800A6A80: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A6A84: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800A6A88: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x800A6A8C: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x800A6A90: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x800A6A94: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x800A6A98: jal         0x800A6250
    // 0x800A6A9C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_800A6250(rdram, ctx);
        goto after_3;
    // 0x800A6A9C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_3:
    // 0x800A6AA0: b           L_800A6B04
    // 0x800A6AA4: lbu         $t1, 0x7E($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X7E);
        goto L_800A6B04;
    // 0x800A6AA4: lbu         $t1, 0x7E($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X7E);
L_800A6AA8:
    // 0x800A6AA8: jal         0x800EE7F8
    // 0x800A6AAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x800A6AAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x800A6AB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A6AB4: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x800A6AB8: jal         0x800EF174
    // 0x800A6ABC: lui         $a2, 0xC4FA
    ctx->r6 = S32(0XC4FA << 16);
    func_800EF174(rdram, ctx);
        goto after_5;
    // 0x800A6ABC: lui         $a2, 0xC4FA
    ctx->r6 = S32(0XC4FA << 16);
    after_5:
    // 0x800A6AC0: lui         $a3, 0x2
    ctx->r7 = S32(0X2 << 16);
    // 0x800A6AC4: ori         $a3, $a3, 0x20
    ctx->r7 = ctx->r7 | 0X20;
    // 0x800A6AC8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x800A6ACC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800A6AD0: jal         0x800C6A7C
    // 0x800A6AD4: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    func_800C6A7C(rdram, ctx);
        goto after_6;
    // 0x800A6AD4: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_6:
    // 0x800A6AD8: bne         $v0, $zero, L_800A6AE8
    if (ctx->r2 != 0) {
        // 0x800A6ADC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800A6AE8;
    }
    // 0x800A6ADC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A6AE0: b           L_800A6B10
    // 0x800A6AE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800A6B10;
    // 0x800A6AE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800A6AE8:
    // 0x800A6AE8: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x800A6AEC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800A6AF0: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x800A6AF4: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x800A6AF8: jal         0x800A6250
    // 0x800A6AFC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_800A6250(rdram, ctx);
        goto after_7;
    // 0x800A6AFC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_7:
    // 0x800A6B00: lbu         $t1, 0x7E($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X7E);
L_800A6B04:
    // 0x800A6B04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800A6B08: ori         $t2, $t1, 0x10
    ctx->r10 = ctx->r9 | 0X10;
    // 0x800A6B0C: sb          $t2, 0x7E($s1)
    MEM_B(0X7E, ctx->r17) = ctx->r10;
L_800A6B10:
    // 0x800A6B10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A6B14: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800A6B18: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800A6B1C: jr          $ra
    // 0x800A6B20: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800A6B20: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_808006C0_chwarppad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006C0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x808006C4: lbu         $a2, 0x762C($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X762C);
    // 0x808006C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808006CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808006D4: jal         0x8008FD48
    // 0x808006D8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_8008FD48(rdram, ctx);
        goto after_0;
    // 0x808006D8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x808006DC: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(780, 0X10A0) << 16);
    // 0x808006E0: addiu       $a3, $a3, 0x10A0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(780, 0X10A0));
    // 0x808006E4: lbu         $t6, 0x2($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X2);
    // 0x808006E8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808006EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808006F0: beq         $t6, $zero, L_80800734
    if (ctx->r14 == 0) {
        // 0x808006F4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800734;
    }
    // 0x808006F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006F8: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(780, 0X10A0) << 16);
    // 0x808006FC: addiu       $v1, $t7, 0x10A0
    ctx->r3 = ADD32(ctx->r15, (int16_t)RELOC_LO16(780, 0X10A0));
    // 0x80800700: lbu         $a0, 0x2($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X2);
L_80800704:
    // 0x80800704: bnel        $a2, $a0, L_80800724
    if (ctx->r6 != ctx->r4) {
        // 0x80800708: lbu         $a0, 0x6($v1)
        ctx->r4 = MEM_BU(ctx->r3, 0X6);
            goto L_80800724;
    }
    goto skip_0;
    // 0x80800708: lbu         $a0, 0x6($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X6);
    skip_0:
    // 0x8080070C: lbu         $t8, 0x3($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X3);
    // 0x80800710: bnel        $v0, $t8, L_80800724
    if (ctx->r2 != ctx->r24) {
        // 0x80800714: lbu         $a0, 0x6($v1)
        ctx->r4 = MEM_BU(ctx->r3, 0X6);
            goto L_80800724;
    }
    goto skip_1;
    // 0x80800714: lbu         $a0, 0x6($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X6);
    skip_1:
    // 0x80800718: b           L_80800740
    // 0x8080071C: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
        goto L_80800740;
    // 0x8080071C: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x80800720: lbu         $a0, 0x6($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X6);
L_80800724:
    // 0x80800724: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80800728: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8080072C: bne         $a0, $zero, L_80800704
    if (ctx->r4 != 0) {
        // 0x80800730: nop
    
            goto L_80800704;
    }
    // 0x80800730: nop

L_80800734:
    // 0x80800734: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80800738: addu        $t0, $a3, $t9
    ctx->r8 = ADD32(ctx->r7, ctx->r25);
    // 0x8080073C: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
L_80800740:
    // 0x80800740: jr          $ra
    // 0x80800744: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800744: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _subaddietaxi_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A578: syscall     844
    recomp_syscall_handler(rdram, ctx, 0x8008A578);
    return;
    // 0x8008A57C: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void boot___osEPiRawWriteIo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void _chspiralgrill_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086840: syscall     387
    recomp_syscall_handler(rdram, ctx, 0x80086840);
    return;
    // 0x80086844: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void suexpressmorph_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080008C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800090: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800094: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800098: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8080009C: jal         0x80800000
    // 0x808000A0: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    func_80800000_suexpressmorph(rdram, ctx);
        goto after_0;
    // 0x808000A0: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    after_0:
    // 0x808000A4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808000A8: bne         $v0, $at, L_808000B8
    if (ctx->r2 != ctx->r1) {
        // 0x808000AC: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_808000B8;
    }
    // 0x808000AC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808000B0: b           L_808000DC
    // 0x808000B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808000DC;
    // 0x808000B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000B8:
    // 0x808000B8: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x808000BC: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x808000C0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808000C4: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3170, 0X1327) << 16);
    // 0x808000C8: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x808000CC: lbu         $a0, 0x1327($a0)
    ctx->r4 = MEM_BU(ctx->r4, (int16_t)RELOC_LO16(3170, 0X1327));
    // 0x808000D0: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x808000D4: addiu       $v1, $t9, 0x8
    ctx->r3 = ADD32(ctx->r25, 0X8);
    // 0x808000D8: addu        $v0, $v1, $t9
    ctx->r2 = ADD32(ctx->r3, ctx->r25);
L_808000DC:
    // 0x808000DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000E4: jr          $ra
    // 0x808000E8: nop

    return;
    // 0x808000E8: nop

;}
RECOMP_FUNC void bsbansack_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801CA0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801CA4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(41, 0X1E90) << 16);
    // 0x80801CA8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801CAC: jr          $ra
    // 0x80801CB0: lw          $v0, 0x1E90($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(41, 0X1E90));
    return;
    // 0x80801CB0: lw          $v0, 0x1E90($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(41, 0X1E90));
;}
RECOMP_FUNC void capod_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000FC: jal         0x8008FFE8
    // 0x80800100: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8008FFE8(rdram, ctx);
        goto after_0;
    // 0x80800100: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800104: beq         $v0, $zero, L_8080011C
    if (ctx->r2 == 0) {
        // 0x80800108: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8080011C;
    }
    // 0x80800108: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080010C: jal         0x80089548
    // 0x80800110: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    _ncpod_entrypoint_17(rdram, ctx);
        goto after_1;
    // 0x80800110: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800114: b           L_80800124
    // 0x80800118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800124;
    // 0x80800118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080011C:
    // 0x8080011C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800124:
    // 0x80800124: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800128: jr          $ra
    // 0x8080012C: nop

    return;
    // 0x8080012C: nop

;}
RECOMP_FUNC void _idglowa_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088DA0: syscall     739
    recomp_syscall_handler(rdram, ctx, 0x80088DA0);
    return;
    // 0x80088DA4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_808008B8_chcheato(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008B8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808008BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808008C0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808008C4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808008C8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x808008CC: jal         0x80087D20
    // 0x808008D0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    _gcnewoption_entrypoint_17(rdram, ctx);
        goto after_0;
    // 0x808008D0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    after_0:
    // 0x808008D4: beq         $v0, $zero, L_80800928
    if (ctx->r2 == 0) {
        // 0x808008D8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800928;
    }
    // 0x808008D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808008DC: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(868, 0XF20) << 16);
    // 0x808008E0: addiu       $t6, $t6, 0xF20
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(868, 0XF20));
    // 0x808008E4: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x808008E8: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x808008EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808008F0: sw          $at, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r1;
    // 0x808008F4: lhu         $at, 0x4($t6)
    ctx->r1 = MEM_HU(ctx->r14, 0X4);
    // 0x808008F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808008FC: jal         0x80087D00
    // 0x80800900: sh          $at, 0x4($a2)
    MEM_H(0X4, ctx->r6) = ctx->r1;
    _gcnewoption_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x80800900: sh          $at, 0x4($a2)
    MEM_H(0X4, ctx->r6) = ctx->r1;
    after_1:
    // 0x80800904: sll         $a2, $s0, 1
    ctx->r6 = S32(ctx->r16 << 1);
    // 0x80800908: addiu       $a2, $a2, 0x3
    ctx->r6 = ADD32(ctx->r6, 0X3);
    // 0x8080090C: sll         $t9, $a2, 16
    ctx->r25 = S32(ctx->r6 << 16);
    // 0x80800910: sra         $a2, $t9, 16
    ctx->r6 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80800914: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800918: jal         0x80087CF8
    // 0x8080091C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x8080091C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x80800920: b           L_8080097C
    // 0x80800924: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080097C;
    // 0x80800924: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800928:
    // 0x80800928: jal         0x80087D30
    // 0x8080092C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _gcnewoption_entrypoint_19(rdram, ctx);
        goto after_3;
    // 0x8080092C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x80800930: beq         $v0, $zero, L_80800978
    if (ctx->r2 == 0) {
        // 0x80800934: lui         $t1, 0x8080
        ctx->r9 = S32(RELOC_HI16(868, 0XF28) << 16);
            goto L_80800978;
    }
    // 0x80800934: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(868, 0XF28) << 16);
    // 0x80800938: addiu       $t1, $t1, 0xF28
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(868, 0XF28));
    // 0x8080093C: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x80800940: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x80800944: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800948: sw          $at, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r1;
    // 0x8080094C: lhu         $at, 0x4($t1)
    ctx->r1 = MEM_HU(ctx->r9, 0X4);
    // 0x80800950: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800954: jal         0x80087D00
    // 0x80800958: sh          $at, 0x4($a2)
    MEM_H(0X4, ctx->r6) = ctx->r1;
    _gcnewoption_entrypoint_13(rdram, ctx);
        goto after_4;
    // 0x80800958: sh          $at, 0x4($a2)
    MEM_H(0X4, ctx->r6) = ctx->r1;
    after_4:
    // 0x8080095C: sll         $a2, $s0, 1
    ctx->r6 = S32(ctx->r16 << 1);
    // 0x80800960: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80800964: sll         $t4, $a2, 16
    ctx->r12 = S32(ctx->r6 << 16);
    // 0x80800968: sra         $a2, $t4, 16
    ctx->r6 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8080096C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800970: jal         0x80087CF8
    // 0x80800974: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_5;
    // 0x80800974: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
L_80800978:
    // 0x80800978: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080097C:
    // 0x8080097C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800980: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800984: jr          $ra
    // 0x80800988: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800988: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80801A10_chwaspnestgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801A14: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801A18: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801A1C: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80801A20: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801A24: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80801A28: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80801A2C: sltiu       $at, $t8, 0x6
    ctx->r1 = ctx->r24 < 0X6 ? 1 : 0;
    // 0x80801A30: beq         $at, $zero, L_80801B88
    if (ctx->r1 == 0) {
        // 0x80801A34: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80801B88;
    }
    // 0x80801A34: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80801A38: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(776, 0X1F0C) << 16);
    // 0x80801A3C: addu        $at, $at, $t8
    gpr jr_addend_80801A44 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80801A40: lw          $t8, 0x1F0C($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(776, 0X1F0C));
    // 0x80801A44: jr          $t8
    // 0x80801A48: nop

    switch (jr_addend_80801A44 >> 2) {
        case 0: goto L_80801A4C; break;
        case 1: goto L_80801A78; break;
        case 2: goto L_80801B10; break;
        case 3: goto L_80801B40; break;
        case 4: goto L_80801AD8; break;
        case 5: goto L_80801B60; break;
        default: switch_error(__func__, 0x80801A44, 0x80801F0C);
    }
    // 0x80801A48: nop

L_80801A4C:
    // 0x80801A4C: jal         0x80801D28
    // 0x80801A50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801D28_chwaspnestgame(rdram, ctx);
        goto after_0;
    // 0x80801A50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80801A54: jal         0x808012D0
    // 0x80801A58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808012D0_chwaspnestgame(rdram, ctx);
        goto after_1;
    // 0x80801A58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801A5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A60: lui         $a1, 0x4248
    ctx->r5 = S32(0X4248 << 16);
    // 0x80801A64: lui         $a2, 0x4370
    ctx->r6 = S32(0X4370 << 16);
    // 0x80801A68: jal         0x80801880
    // 0x80801A6C: lui         $a3, 0x433E
    ctx->r7 = S32(0X433E << 16);
    func_80801880_chwaspnestgame(rdram, ctx);
        goto after_2;
    // 0x80801A6C: lui         $a3, 0x433E
    ctx->r7 = S32(0X433E << 16);
    after_2:
    // 0x80801A70: b           L_80801B8C
    // 0x80801A74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801B8C;
    // 0x80801A74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801A78:
    // 0x80801A78: jal         0x80801D28
    // 0x80801A7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801D28_chwaspnestgame(rdram, ctx);
        goto after_3;
    // 0x80801A7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801A80: jal         0x80801CE4
    // 0x80801A84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801CE4_chwaspnestgame(rdram, ctx);
        goto after_4;
    // 0x80801A84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801A88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A8C: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x80801A90: jal         0x80801590
    // 0x80801A94: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    func_80801590_chwaspnestgame(rdram, ctx);
        goto after_5;
    // 0x80801A94: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    after_5:
    // 0x80801A98: beql        $v0, $zero, L_80801B8C
    if (ctx->r2 == 0) {
        // 0x80801A9C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801B8C;
    }
    goto skip_0;
    // 0x80801A9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80801AA0: jal         0x800DA298
    // 0x80801AA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x80801AA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x80801AA8: bne         $v0, $zero, L_80801AC8
    if (ctx->r2 != 0) {
        // 0x80801AAC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801AC8;
    }
    // 0x80801AAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801AB0: jal         0x8080129C
    // 0x80801AB4: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_8080129C_chwaspnestgame(rdram, ctx);
        goto after_7;
    // 0x80801AB4: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_7:
    // 0x80801AB8: jal         0x800FFA88
    // 0x80801ABC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_8;
    // 0x80801ABC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_8:
    // 0x80801AC0: b           L_80801B8C
    // 0x80801AC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801B8C;
    // 0x80801AC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801AC8:
    // 0x80801AC8: jal         0x80801364
    // 0x80801ACC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801364_chwaspnestgame(rdram, ctx);
        goto after_9;
    // 0x80801ACC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80801AD0: b           L_80801B8C
    // 0x80801AD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801B8C;
    // 0x80801AD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801AD8:
    // 0x80801AD8: jal         0x80801D28
    // 0x80801ADC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801D28_chwaspnestgame(rdram, ctx);
        goto after_10;
    // 0x80801ADC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80801AE0: jal         0x80801CE4
    // 0x80801AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801CE4_chwaspnestgame(rdram, ctx);
        goto after_11;
    // 0x80801AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80801AE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801AEC: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    // 0x80801AF0: jal         0x80801590
    // 0x80801AF4: lui         $a2, 0x44FA
    ctx->r6 = S32(0X44FA << 16);
    func_80801590_chwaspnestgame(rdram, ctx);
        goto after_12;
    // 0x80801AF4: lui         $a2, 0x44FA
    ctx->r6 = S32(0X44FA << 16);
    after_12:
    // 0x80801AF8: beql        $v0, $zero, L_80801B8C
    if (ctx->r2 == 0) {
        // 0x80801AFC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801B8C;
    }
    goto skip_1;
    // 0x80801AFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80801B00: jal         0x800FFA88
    // 0x80801B04: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_13;
    // 0x80801B04: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_13:
    // 0x80801B08: b           L_80801B8C
    // 0x80801B0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801B8C;
    // 0x80801B0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801B10:
    // 0x80801B10: jal         0x808012C8
    // 0x80801B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808012C8_chwaspnestgame(rdram, ctx);
        goto after_14;
    // 0x80801B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80801B18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801B1C: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x80801B20: jal         0x808017DC
    // 0x80801B24: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_808017DC_chwaspnestgame(rdram, ctx);
        goto after_15;
    // 0x80801B24: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_15:
    // 0x80801B28: beq         $v0, $zero, L_80801B88
    if (ctx->r2 == 0) {
        // 0x80801B2C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801B88;
    }
    // 0x80801B2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801B30: jal         0x80801364
    // 0x80801B34: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80801364_chwaspnestgame(rdram, ctx);
        goto after_16;
    // 0x80801B34: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_16:
    // 0x80801B38: b           L_80801B8C
    // 0x80801B3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801B8C;
    // 0x80801B3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801B40:
    // 0x80801B40: jal         0x80101DDC
    // 0x80801B44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_17;
    // 0x80801B44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80801B48: beq         $v0, $zero, L_80801B88
    if (ctx->r2 == 0) {
        // 0x80801B4C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801B88;
    }
    // 0x80801B4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801B50: jal         0x80801364
    // 0x80801B54: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80801364_chwaspnestgame(rdram, ctx);
        goto after_18;
    // 0x80801B54: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_18:
    // 0x80801B58: b           L_80801B8C
    // 0x80801B5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801B8C;
    // 0x80801B5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801B60:
    // 0x80801B60: jal         0x80801D28
    // 0x80801B64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801D28_chwaspnestgame(rdram, ctx);
        goto after_19;
    // 0x80801B64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80801B68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801B6C: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x80801B70: jal         0x808017DC
    // 0x80801B74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_808017DC_chwaspnestgame(rdram, ctx);
        goto after_20;
    // 0x80801B74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_20:
    // 0x80801B78: beq         $v0, $zero, L_80801B88
    if (ctx->r2 == 0) {
        // 0x80801B7C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801B88;
    }
    // 0x80801B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801B80: jal         0x80801364
    // 0x80801B84: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80801364_chwaspnestgame(rdram, ctx);
        goto after_21;
    // 0x80801B84: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_21:
L_80801B88:
    // 0x80801B88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801B8C:
    // 0x80801B8C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801B90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801B94: jr          $ra
    // 0x80801B98: nop

    return;
    // 0x80801B98: nop

;}
RECOMP_FUNC void _suquiz_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A828: syscall     853
    recomp_syscall_handler(rdram, ctx, 0x8008A828);
    return;
    // 0x8008A82C: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void func_800EA148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA148: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EA14C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800EA150: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EA154: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800EA158: jal         0x80088B70
    // 0x800EA15C: addiu       $a0, $a0, 0x2DC0
    ctx->r4 = ADD32(ctx->r4, 0X2DC0);
    _gsworldDll_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x800EA15C: addiu       $a0, $a0, 0x2DC0
    ctx->r4 = ADD32(ctx->r4, 0X2DC0);
    after_0:
    // 0x800EA160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EA164: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EA168: jr          $ra
    // 0x800EA16C: nop

    return;
    // 0x800EA16C: nop

;}
RECOMP_FUNC void _gcnewoption_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087D40: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087D40);
    return;
    // 0x80087D44: addi        $t0, $zero, 0x54
    ctx->r8 = ADD32(0, 0X54);
;}
RECOMP_FUNC void _cheggsplode_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087340: syscall     552
    recomp_syscall_handler(rdram, ctx, 0x80087340);
    return;
    // 0x80087344: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800714_bsdronexform(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800714: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80800718: lw          $t6, 0x18C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18C);
    // 0x8080071C: jr          $ra
    // 0x80800720: swc1        $f12, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x80800720: swc1        $f12, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void chdeflect_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080007C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2500, 0X90) << 16);
    // 0x80800080: jr          $ra
    // 0x80800084: addiu       $v0, $v0, 0x90
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2500, 0X90));
    return;
    // 0x80800084: addiu       $v0, $v0, 0x90
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2500, 0X90));
    // 0x80800088: nop

    // 0x8080008C: nop

;}
RECOMP_FUNC void _chswitch_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085838: syscall     176
    recomp_syscall_handler(rdram, ctx, 0x80085838);
    return;
    // 0x8008583C: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void _chwandglow_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800872F8: syscall     549
    recomp_syscall_handler(rdram, ctx, 0x800872F8);
    return;
    // 0x800872FC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800D2F20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2F20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D2F24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D2F28: jal         0x800BDC5C
    // 0x800D2F2C: nop

    func_800BDC5C(rdram, ctx);
        goto after_0;
    // 0x800D2F2C: nop

    after_0:
    // 0x800D2F30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D2F34: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800D2F38: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800D2F3C: jr          $ra
    // 0x800D2F40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800D2F40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _bsbtrot_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082C48: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082C48);
    return;
    // 0x80082C4C: addi        $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
;}
RECOMP_FUNC void _gspropsDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088B80: syscall     727
    recomp_syscall_handler(rdram, ctx, 0x80088B80);
    return;
    // 0x80088B84: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8009CF04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CF04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009CF08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009CF0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009CF10: lw          $a3, 0xF0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0XF0);
    // 0x8009CF14: lbu         $v0, 0x80($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X80);
    // 0x8009CF18: beq         $v0, $zero, L_8009CF78
    if (ctx->r2 == 0) {
        // 0x8009CF1C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8009CF78;
    }
    // 0x8009CF1C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8009CF20: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x8009CF24: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x8009CF28: blez        $v0, L_8009CF60
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8009CF2C: lbu         $a2, -0x10($t8)
        ctx->r6 = MEM_BU(ctx->r24, -0X10);
            goto L_8009CF60;
    }
    // 0x8009CF2C: lbu         $a2, -0x10($t8)
    ctx->r6 = MEM_BU(ctx->r24, -0X10);
    // 0x8009CF30: sll         $a0, $a1, 4
    ctx->r4 = S32(ctx->r5 << 4);
    // 0x8009CF34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8009CF38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8009CF3C: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
L_8009CF40:
    // 0x8009CF40: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x8009CF44: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8009CF48: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8009CF4C: bne         $a1, $t9, L_8009CF58
    if (ctx->r5 != ctx->r25) {
        // 0x8009CF50: nop
    
            goto L_8009CF58;
    }
    // 0x8009CF50: nop

    // 0x8009CF54: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
L_8009CF58:
    // 0x8009CF58: bne         $at, $zero, L_8009CF40
    if (ctx->r1 != 0) {
        // 0x8009CF5C: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_8009CF40;
    }
    // 0x8009CF5C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_8009CF60:
    // 0x8009CF60: lbu         $t0, 0x81($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0X81);
    // 0x8009CF64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8009CF68: beql        $a2, $t0, L_8009CF7C
    if (ctx->r6 == ctx->r8) {
        // 0x8009CF6C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8009CF7C;
    }
    goto skip_0;
    // 0x8009CF6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8009CF70: jal         0x8009CDE0
    // 0x8009CF74: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_8009CDE0(rdram, ctx);
        goto after_0;
    // 0x8009CF74: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
L_8009CF78:
    // 0x8009CF78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8009CF7C:
    // 0x8009CF7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009CF80: jr          $ra
    // 0x8009CF84: nop

    return;
    // 0x8009CF84: nop

    // 0x8009CF88: nop

    // 0x8009CF8C: nop

;}
RECOMP_FUNC void fxdialog_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800030: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x80800034: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x80800038: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2858, 0X290) << 16);
    // 0x8080003C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800040: addiu       $v0, $v0, 0x290
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2858, 0X290));
    // 0x80800044: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800048: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8080004C: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x80800050: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800054: sw          $t7, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r15;
    // 0x80800058: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x8080005C: jr          $ra
    // 0x80800060: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    return;
    // 0x80800060: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
;}
RECOMP_FUNC void chballoonbomb_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(836, 0X4B0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x4B0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(836, 0X4B0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x4B0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(836, 0X4B0));
;}
RECOMP_FUNC void _idbounce_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088CC0: syscall     733
    recomp_syscall_handler(rdram, ctx, 0x80088CC0);
    return;
    // 0x80088CC4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void subaddieaudioloop_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800060: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800064: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800068: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080006C: jal         0x8080008C
    // 0x80800070: lbu         $a0, 0x5F($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X5F);
    subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800070: lbu         $a0, 0x5F($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X5F);
    after_0:
    // 0x80800074: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800078: sb          $v0, 0x5F($t7)
    MEM_B(0X5F, ctx->r15) = ctx->r2;
    // 0x8080007C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800080: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800084: jr          $ra
    // 0x80800088: nop

    return;
    // 0x80800088: nop

;}
RECOMP_FUNC void func_800A8240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8240: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A8244: jr          $ra
    // 0x800A8248: sh          $zero, 0x7636($at)
    MEM_H(0X7636, ctx->r1) = 0;
    return;
    // 0x800A8248: sh          $zero, 0x7636($at)
    MEM_H(0X7636, ctx->r1) = 0;
;}
RECOMP_FUNC void func_808036EC_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808036EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808036F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808036F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808036F8: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808036FC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80803700: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80803704: bnel        $t7, $at, L_8080371C
    if (ctx->r15 != ctx->r1) {
        // 0x80803708: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_8080371C;
    }
    goto skip_0;
    // 0x80803708: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080370C: jal         0x8010A570
    // 0x80803710: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8010A570(rdram, ctx);
        goto after_0;
    // 0x80803710: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80803714: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80803718: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
L_8080371C:
    // 0x8080371C: jal         0x80102424
    // 0x80803720: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80803720: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80803724: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80803728: lhu         $t8, 0x72($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X72);
    // 0x8080372C: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x80803730: addiu       $t0, $t9, -0x2
    ctx->r8 = ADD32(ctx->r25, -0X2);
    // 0x80803734: sltiu       $at, $t0, 0x8
    ctx->r1 = ctx->r8 < 0X8 ? 1 : 0;
    // 0x80803738: beq         $at, $zero, L_808037A0
    if (ctx->r1 == 0) {
        // 0x8080373C: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_808037A0;
    }
    // 0x8080373C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80803740: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X5300) << 16);
    // 0x80803744: addu        $at, $at, $t0
    gpr jr_addend_8080374C = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80803748: lw          $t0, 0x5300($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1852, 0X5300));
    // 0x8080374C: jr          $t0
    // 0x80803750: nop

    switch (jr_addend_8080374C >> 2) {
        case 0: goto L_80803754; break;
        case 1: goto L_808037A0; break;
        case 2: goto L_80803764; break;
        case 3: goto L_80803774; break;
        case 4: goto L_808037A0; break;
        case 5: goto L_808037A0; break;
        case 6: goto L_80803780; break;
        case 7: goto L_80803790; break;
        default: switch_error(__func__, 0x8080374C, 0x80805300);
    }
    // 0x80803750: nop

L_80803754:
    // 0x80803754: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80803758: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080375C: b           L_808037A0
    // 0x80803760: swc1        $f4, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f4.u32l;
        goto L_808037A0;
    // 0x80803760: swc1        $f4, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f4.u32l;
L_80803764:
    // 0x80803764: jal         0x8010A590
    // 0x80803768: nop

    func_8010A590(rdram, ctx);
        goto after_2;
    // 0x80803768: nop

    after_2:
    // 0x8080376C: b           L_808037A4
    // 0x80803770: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808037A4;
    // 0x80803770: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80803774:
    // 0x80803774: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80803778: b           L_808037A0
    // 0x8080377C: swc1        $f6, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f6.u32l;
        goto L_808037A0;
    // 0x8080377C: swc1        $f6, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f6.u32l;
L_80803780:
    // 0x80803780: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80803784: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80803788: b           L_808037A0
    // 0x8080378C: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
        goto L_808037A0;
    // 0x8080378C: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
L_80803790:
    // 0x80803790: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80803794: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80803798: nop

    // 0x8080379C: swc1        $f10, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f10.u32l;
L_808037A0:
    // 0x808037A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808037A4:
    // 0x808037A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808037A8: jr          $ra
    // 0x808037AC: nop

    return;
    // 0x808037AC: nop

;}
RECOMP_FUNC void suquiz_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007CC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x808007D0: jal         0x800EE7F8
    // 0x808007D4: lw          $a1, 0x7614($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7614);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808007D4: lw          $a1, 0x7614($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7614);
    after_0:
    // 0x808007D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007E0: jr          $ra
    // 0x808007E4: nop

    return;
    // 0x808007E4: nop

;}
RECOMP_FUNC void func_80800F38_chcrusherboulder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F38: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800F3C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1640, 0X13E0) << 16);
    // 0x80800F40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800F44: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800F48: addiu       $t7, $t7, 0x13E0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1640, 0X13E0));
    // 0x80800F4C: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80800F50: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
    // 0x80800F54: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x80800F58: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80800F5C: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80800F60: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800F64: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x80800F68: jal         0x8001211C
    // 0x80800F6C: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    func_8001211C(rdram, ctx);
        goto after_0;
    // 0x80800F6C: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    after_0:
    // 0x80800F70: andi        $t1, $v0, 0x3
    ctx->r9 = ctx->r2 & 0X3;
    // 0x80800F74: bne         $t1, $zero, L_80801038
    if (ctx->r9 != 0) {
        // 0x80800F78: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1640, 0X1320) << 16);
            goto L_80801038;
    }
    // 0x80800F78: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1640, 0X1320) << 16);
    // 0x80800F7C: lwc1        $f4, 0x34($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800F80: lwc1        $f6, 0x1320($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1640, 0X1320));
    // 0x80800F84: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800F88: jal         0x800DC0C0
    // 0x80800F8C: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    func_800DC0C0(rdram, ctx);
        goto after_1;
    // 0x80800F8C: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80800F90: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1640, 0X1324) << 16);
    // 0x80800F94: lwc1        $f10, 0x1324($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1640, 0X1324));
    // 0x80800F98: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800F9C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80800FA0: nop

    // 0x80800FA4: bc1fl       L_80800FB8
    if (!c1cs) {
        // 0x80800FA8: lui         $at, 0x41C8
        ctx->r1 = S32(0X41C8 << 16);
            goto L_80800FB8;
    }
    goto skip_0;
    // 0x80800FA8: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    skip_0:
    // 0x80800FAC: jal         0x80801064
    // 0x80800FB0: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80801064_chcrusherboulder(rdram, ctx);
        goto after_2;
    // 0x80800FB0: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x80800FB4: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
L_80800FB8:
    // 0x80800FB8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800FBC: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800FC0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80800FC4: jal         0x800DC0C0
    // 0x80800FC8: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    func_800DC0C0(rdram, ctx);
        goto after_3;
    // 0x80800FC8: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80800FCC: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800FD0: jal         0x80801128
    // 0x80800FD4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80801128_chcrusherboulder(rdram, ctx);
        goto after_4;
    // 0x80800FD4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_4:
    // 0x80800FD8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1640, 0X1328) << 16);
    // 0x80800FDC: lwc1        $f6, 0x1328($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1640, 0X1328));
    // 0x80800FE0: lwc1        $f8, 0x34($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800FE4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80800FE8: jal         0x800DC0C0
    // 0x80800FEC: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    func_800DC0C0(rdram, ctx);
        goto after_5;
    // 0x80800FEC: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x80800FF0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1640, 0X132C) << 16);
    // 0x80800FF4: lwc1        $f16, 0x132C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1640, 0X132C));
    // 0x80800FF8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800FFC: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80801000: nop

    // 0x80801004: bc1fl       L_80801018
    if (!c1cs) {
        // 0x80801008: lui         $at, 0x41C8
        ctx->r1 = S32(0X41C8 << 16);
            goto L_80801018;
    }
    goto skip_1;
    // 0x80801008: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    skip_1:
    // 0x8080100C: jal         0x80801064
    // 0x80801010: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80801064_chcrusherboulder(rdram, ctx);
        goto after_6;
    // 0x80801010: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_6:
    // 0x80801014: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
L_80801018:
    // 0x80801018: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080101C: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80801020: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80801024: jal         0x800DC0C0
    // 0x80801028: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    func_800DC0C0(rdram, ctx);
        goto after_7;
    // 0x80801028: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    after_7:
    // 0x8080102C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80801030: jal         0x80801128
    // 0x80801034: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80801128_chcrusherboulder(rdram, ctx);
        goto after_8;
    // 0x80801034: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_8:
L_80801038:
    // 0x80801038: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1640, 0X13EC) << 16);
    // 0x8080103C: addiu       $a3, $a3, 0x13EC
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1640, 0X13EC));
    // 0x80801040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801044: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801048: jal         0x80089D50
    // 0x8080104C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_9;
    // 0x8080104C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x80801050: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801054: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801058: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080105C: jr          $ra
    // 0x80801060: nop

    return;
    // 0x80801060: nop

;}
RECOMP_FUNC void gcfrontend_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800188: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080018C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80800190: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800194: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2650, 0XD81) << 16);
    // 0x80800198: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080019C: jr          $ra
    // 0x808001A0: lbu         $v0, 0xD81($v0)
    ctx->r2 = MEM_BU(ctx->r2, (int16_t)RELOC_LO16(2650, 0XD81));
    return;
    // 0x808001A0: lbu         $v0, 0xD81($v0)
    ctx->r2 = MEM_BU(ctx->r2, (int16_t)RELOC_LO16(2650, 0XD81));
;}
RECOMP_FUNC void _sumultiscore_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089968: syscall     799
    recomp_syscall_handler(rdram, ctx, 0x80089968);
    return;
    // 0x8008996C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80801844_chfactoryempspell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801844: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80801848: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x8080184C: sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // 0x80801850: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x80801854: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // 0x80801858: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x8080185C: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x80801860: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x80801864: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x80801868: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x8080186C: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x80801870: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x80801874: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x80801878: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x8080187C: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80801880: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80801884: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80801888: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8080188C: jal         0x80100094
    // 0x80801890: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801890: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80801894: lui         $at, 0x44AF
    ctx->r1 = S32(0X44AF << 16);
    // 0x80801898: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x8080189C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x808018A0: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x808018A4: lui         $at, 0x4561
    ctx->r1 = S32(0X4561 << 16);
    // 0x808018A8: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x808018AC: lui         $at, 0xC516
    ctx->r1 = S32(0XC516 << 16);
    // 0x808018B0: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x808018B4: lui         $at, 0x457A
    ctx->r1 = S32(0X457A << 16);
    // 0x808018B8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x808018BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808018C0: lui         $s7, 0x8080
    ctx->r23 = S32(RELOC_HI16(2304, 0X2328) << 16);
    // 0x808018C4: lui         $s6, 0x8080
    ctx->r22 = S32(RELOC_HI16(2304, 0X23B4) << 16);
    // 0x808018C8: lui         $s5, 0x8080
    ctx->r21 = S32(RELOC_HI16(2304, 0X2390) << 16);
    // 0x808018CC: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2304, 0X239C) << 16);
    // 0x808018D0: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(2304, 0X23A8) << 16);
    // 0x808018D4: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2304, 0X2384) << 16);
    // 0x808018D8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x808018DC: addiu       $s1, $s1, 0x2384
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2304, 0X2384));
    // 0x808018E0: addiu       $s3, $s3, 0x23A8
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(2304, 0X23A8));
    // 0x808018E4: addiu       $s4, $s4, 0x239C
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2304, 0X239C));
    // 0x808018E8: addiu       $s5, $s5, 0x2390
    ctx->r21 = ADD32(ctx->r21, (int16_t)RELOC_LO16(2304, 0X2390));
    // 0x808018EC: addiu       $s6, $s6, 0x23B4
    ctx->r22 = ADD32(ctx->r22, (int16_t)RELOC_LO16(2304, 0X23B4));
    // 0x808018F0: addiu       $s7, $s7, 0x2328
    ctx->r23 = ADD32(ctx->r23, (int16_t)RELOC_LO16(2304, 0X2328));
    // 0x808018F4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x808018F8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_808018FC:
    // 0x808018FC: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x80801900: lbu         $t0, 0x10($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X10);
    // 0x80801904: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80801908: srl         $t6, $v0, 25
    ctx->r14 = S32(U32(ctx->r2) >> 25);
    // 0x8080190C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80801910: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x80801914: andi        $t1, $t0, 0xFF01
    ctx->r9 = ctx->r8 & 0XFF01;
    // 0x80801918: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x8080191C: sltiu       $v1, $t6, 0x1
    ctx->r3 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80801920: beq         $v1, $zero, L_80801A18
    if (ctx->r3 == 0) {
        // 0x80801924: sb          $t2, 0x10($s0)
        MEM_B(0X10, ctx->r16) = ctx->r10;
            goto L_80801A18;
    }
    // 0x80801924: sb          $t2, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r10;
    // 0x80801928: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080192C: jal         0x800DC128
    // 0x80801930: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_800DC128(rdram, ctx);
        goto after_1;
    // 0x80801930: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_1:
    // 0x80801934: lhu         $t5, 0x10($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X10);
    // 0x80801938: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x8080193C: andi        $t4, $t3, 0x1FC
    ctx->r12 = ctx->r11 & 0X1FC;
    // 0x80801940: andi        $t6, $t5, 0xFE03
    ctx->r14 = ctx->r13 & 0XFE03;
    // 0x80801944: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x80801948: sh          $t7, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r15;
    // 0x8080194C: lbu         $t9, 0x10($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X10);
    // 0x80801950: sll         $t0, $v0, 1
    ctx->r8 = S32(ctx->r2 << 1);
    // 0x80801954: lbu         $a0, 0x8($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X8);
    // 0x80801958: andi        $t1, $t9, 0xFF01
    ctx->r9 = ctx->r25 & 0XFF01;
    // 0x8080195C: or          $t2, $t0, $t1
    ctx->r10 = ctx->r8 | ctx->r9;
    // 0x80801960: jal         0x80089D48
    // 0x80801964: sb          $t2, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r10;
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80801964: sb          $t2, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r10;
    after_2:
    // 0x80801968: sb          $v0, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r2;
    // 0x8080196C: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    // 0x80801970: jal         0x800DC178
    // 0x80801974: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x80801974: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    after_3:
    // 0x80801978: swc1        $f0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f0.u32l;
    // 0x8080197C: swc1        $f0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f0.u32l;
    // 0x80801980: swc1        $f0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f0.u32l;
    // 0x80801984: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
    // 0x80801988: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x8080198C: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    // 0x80801990: jal         0x800DC178
    // 0x80801994: mov.s       $f14, $f30
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    ctx->f14.fl = ctx->f30.fl;
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x80801994: mov.s       $f14, $f30
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    ctx->f14.fl = ctx->f30.fl;
    after_4:
    // 0x80801998: swc1        $f0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f0.u32l;
    // 0x8080199C: swc1        $f0, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->f0.u32l;
    // 0x808019A0: swc1        $f0, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->f0.u32l;
    // 0x808019A4: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    // 0x808019A8: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x808019AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808019B0: jal         0x800DC128
    // 0x808019B4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DC128(rdram, ctx);
        goto after_5;
    // 0x808019B4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x808019B8: lbu         $t6, 0x11($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X11);
    // 0x808019BC: sll         $t5, $v0, 1
    ctx->r13 = S32(ctx->r2 << 1);
    // 0x808019C0: andi        $t4, $t5, 0x2
    ctx->r12 = ctx->r13 & 0X2;
    // 0x808019C4: andi        $t7, $t6, 0xFFFD
    ctx->r15 = ctx->r14 & 0XFFFD;
    // 0x808019C8: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x808019CC: sb          $t8, 0x11($s0)
    MEM_B(0X11, ctx->r16) = ctx->r24;
    // 0x808019D0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x808019D4: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    // 0x808019D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808019DC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x808019E0: jal         0x800BBCB8
    // 0x808019E4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_800BBCB8(rdram, ctx);
        goto after_6;
    // 0x808019E4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_6:
    // 0x808019E8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x808019EC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808019F0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x808019F4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x808019F8: jal         0x800BBCB8
    // 0x808019FC: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    func_800BBCB8(rdram, ctx);
        goto after_7;
    // 0x808019FC: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    after_7:
    // 0x80801A00: swc1        $f22, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f22.u32l;
    // 0x80801A04: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x80801A08: jal         0x800C8CB8
    // 0x80801A0C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800C8CB8(rdram, ctx);
        goto after_8;
    // 0x80801A0C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_8:
    // 0x80801A10: b           L_80801A60
    // 0x80801A14: addiu       $s2, $s2, 0x14
    ctx->r18 = ADD32(ctx->r18, 0X14);
        goto L_80801A60;
    // 0x80801A14: addiu       $s2, $s2, 0x14
    ctx->r18 = ADD32(ctx->r18, 0X14);
L_80801A18:
    // 0x80801A18: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80801A1C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80801A20: jal         0x800EFA4C
    // 0x80801A24: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    func_800EFA4C(rdram, ctx);
        goto after_9;
    // 0x80801A24: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    after_9:
    // 0x80801A28: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x80801A2C: jal         0x800C8CB8
    // 0x80801A30: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_800C8CB8(rdram, ctx);
        goto after_10;
    // 0x80801A30: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_10:
    // 0x80801A34: lw          $t9, 0x70($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X70);
    // 0x80801A38: lbu         $a0, 0x8($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X8);
    // 0x80801A3C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2304, 0X2374) << 16);
    // 0x80801A40: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x80801A44: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80801A48: addiu       $a3, $a3, 0x2374
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2304, 0X2374));
    // 0x80801A4C: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80801A50: jal         0x80089D68
    // 0x80801A54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_7(rdram, ctx);
        goto after_11;
    // 0x80801A54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x80801A58: sb          $v0, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r2;
    // 0x80801A5C: addiu       $s2, $s2, 0x14
    ctx->r18 = ADD32(ctx->r18, 0X14);
L_80801A60:
    // 0x80801A60: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x80801A64: bne         $s2, $at, L_808018FC
    if (ctx->r18 != ctx->r1) {
        // 0x80801A68: addiu       $s0, $s0, 0x14
        ctx->r16 = ADD32(ctx->r16, 0X14);
            goto L_808018FC;
    }
    // 0x80801A68: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x80801A6C: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x80801A70: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80801A74: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80801A78: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80801A7C: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80801A80: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x80801A84: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x80801A88: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x80801A8C: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x80801A90: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x80801A94: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x80801A98: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x80801A9C: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x80801AA0: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x80801AA4: lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X6C);
    // 0x80801AA8: lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X70);
    // 0x80801AAC: jr          $ra
    // 0x80801AB0: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80801AB0: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_80801258_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801258: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080125C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801260: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80801264: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80801268: jal         0x8009C128
    // 0x8080126C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x8080126C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80801270: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80801274: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80801278: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8080127C: jal         0x801013A8
    // 0x80801280: lw          $a2, 0x184($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X184);
    func_801013A8(rdram, ctx);
        goto after_1;
    // 0x80801280: lw          $a2, 0x184($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X184);
    after_1:
    // 0x80801284: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801288: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080128C: jr          $ra
    // 0x80801290: nop

    return;
    // 0x80801290: nop

;}
