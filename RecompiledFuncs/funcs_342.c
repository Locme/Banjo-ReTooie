#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_808002C4_chchuffycont(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808002C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808002CC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808002D0: jal         0x80800A7C
    // 0x808002D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800A7C_chchuffycont(rdram, ctx);
        goto after_0;
    // 0x808002D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808002D8: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x808002DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808002E0: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808002E4: beq         $t6, $at, L_80800304
    if (ctx->r14 == ctx->r1) {
        // 0x808002E8: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80800304;
    }
    // 0x808002E8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808002EC: beq         $t6, $at, L_808003FC
    if (ctx->r14 == ctx->r1) {
        // 0x808002F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003FC;
    }
    // 0x808002F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002F4: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x808002F8: sll         $t7, $v0, 12
    ctx->r15 = S32(ctx->r2 << 12);
    // 0x808002FC: b           L_80800418
    // 0x80800300: srl         $v0, $t7, 31
    ctx->r2 = S32(U32(ctx->r15) >> 31);
        goto L_80800418;
    // 0x80800300: srl         $v0, $t7, 31
    ctx->r2 = S32(U32(ctx->r15) >> 31);
L_80800304:
    // 0x80800304: jal         0x800DA298
    // 0x80800308: addiu       $a0, $zero, 0x66D
    ctx->r4 = ADD32(0, 0X66D);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800308: addiu       $a0, $zero, 0x66D
    ctx->r4 = ADD32(0, 0X66D);
    after_1:
    // 0x8080030C: bnel        $v0, $zero, L_80800358
    if (ctx->r2 != 0) {
        // 0x80800310: lw          $t0, 0x64($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X64);
            goto L_80800358;
    }
    goto skip_0;
    // 0x80800310: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
    skip_0:
    // 0x80800314: jal         0x800DA298
    // 0x80800318: addiu       $a0, $zero, 0x86
    ctx->r4 = ADD32(0, 0X86);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800318: addiu       $a0, $zero, 0x86
    ctx->r4 = ADD32(0, 0X86);
    after_2:
    // 0x8080031C: bne         $v0, $zero, L_80800354
    if (ctx->r2 != 0) {
        // 0x80800320: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80800354;
    }
    // 0x80800320: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800324: jal         0x8010CAC0
    // 0x80800328: addiu       $a1, $zero, 0xFA
    ctx->r5 = ADD32(0, 0XFA);
    func_8010CAC0(rdram, ctx);
        goto after_3;
    // 0x80800328: addiu       $a1, $zero, 0xFA
    ctx->r5 = ADD32(0, 0XFA);
    after_3:
    // 0x8080032C: beq         $v0, $zero, L_80800354
    if (ctx->r2 == 0) {
        // 0x80800330: addiu       $a1, $zero, 0xFAC
        ctx->r5 = ADD32(0, 0XFAC);
            goto L_80800354;
    }
    // 0x80800330: addiu       $a1, $zero, 0xFAC
    ctx->r5 = ADD32(0, 0XFAC);
    // 0x80800334: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800338: addiu       $t9, $zero, 0x42
    ctx->r25 = ADD32(0, 0X42);
    // 0x8080033C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800340: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800344: jal         0x8008A208
    // 0x80800348: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x80800348: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x8080034C: jal         0x800DA544
    // 0x80800350: addiu       $a0, $zero, 0x66D
    ctx->r4 = ADD32(0, 0X66D);
    func_800DA544(rdram, ctx);
        goto after_5;
    // 0x80800350: addiu       $a0, $zero, 0x66D
    ctx->r4 = ADD32(0, 0X66D);
    after_5:
L_80800354:
    // 0x80800354: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
L_80800358:
    // 0x80800358: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8080035C: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x80800360: sll         $t2, $t0, 12
    ctx->r10 = S32(ctx->r8 << 12);
    // 0x80800364: bgezl       $t2, L_808003F0
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80800368: lw          $v0, 0x64($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X64);
            goto L_808003F0;
    }
    goto skip_1;
    // 0x80800368: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    skip_1:
    // 0x8080036C: jal         0x8008A1D0
    // 0x80800370: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _subaddiedialog_entrypoint_4(rdram, ctx);
        goto after_6;
    // 0x80800370: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80800374: beql        $v0, $zero, L_808003F0
    if (ctx->r2 == 0) {
        // 0x80800378: lw          $v0, 0x64($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X64);
            goto L_808003F0;
    }
    goto skip_2;
    // 0x80800378: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    skip_2:
    // 0x8080037C: jal         0x800DA298
    // 0x80800380: addiu       $a0, $zero, 0x86
    ctx->r4 = ADD32(0, 0X86);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x80800380: addiu       $a0, $zero, 0x86
    ctx->r4 = ADD32(0, 0X86);
    after_7:
    // 0x80800384: bne         $v0, $zero, L_808003AC
    if (ctx->r2 != 0) {
        // 0x80800388: nop
    
            goto L_808003AC;
    }
    // 0x80800388: nop

    // 0x8080038C: lbu         $t3, 0x74($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X74);
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800394: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800398: andi        $t4, $t3, 0xFFBF
    ctx->r12 = ctx->r11 & 0XFFBF;
    // 0x8080039C: jal         0x80800000
    // 0x808003A0: sb          $t4, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r12;
    func_80800000_chchuffycont(rdram, ctx);
        goto after_8;
    // 0x808003A0: sb          $t4, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r12;
    after_8:
    // 0x808003A4: b           L_808003F0
    // 0x808003A8: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
        goto L_808003F0;
    // 0x808003A8: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
L_808003AC:
    // 0x808003AC: jal         0x8080070C
    // 0x808003B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080070C_chchuffycont(rdram, ctx);
        goto after_9;
    // 0x808003B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808003B4: bgtz        $v0, L_808003E4
    if (SIGNED(ctx->r2) > 0) {
        // 0x808003B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003E4;
    }
    // 0x808003B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003BC: lbu         $t5, 0x74($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X74);
    // 0x808003C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003C4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808003C8: andi        $t6, $t5, 0xFFBF
    ctx->r14 = ctx->r13 & 0XFFBF;
    // 0x808003CC: jal         0x80800000
    // 0x808003D0: sb          $t6, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r14;
    func_80800000_chchuffycont(rdram, ctx);
        goto after_10;
    // 0x808003D0: sb          $t6, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r14;
    after_10:
    // 0x808003D4: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x808003D8: sll         $t7, $v0, 12
    ctx->r15 = S32(ctx->r2 << 12);
    // 0x808003DC: b           L_80800418
    // 0x808003E0: srl         $v0, $t7, 31
    ctx->r2 = S32(U32(ctx->r15) >> 31);
        goto L_80800418;
    // 0x808003E0: srl         $v0, $t7, 31
    ctx->r2 = S32(U32(ctx->r15) >> 31);
L_808003E4:
    // 0x808003E4: jal         0x80800000
    // 0x808003E8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800000_chchuffycont(rdram, ctx);
        goto after_11;
    // 0x808003E8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_11:
    // 0x808003EC: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
L_808003F0:
    // 0x808003F0: sll         $t9, $v0, 12
    ctx->r25 = S32(ctx->r2 << 12);
    // 0x808003F4: b           L_80800418
    // 0x808003F8: srl         $v0, $t9, 31
    ctx->r2 = S32(U32(ctx->r25) >> 31);
        goto L_80800418;
    // 0x808003F8: srl         $v0, $t9, 31
    ctx->r2 = S32(U32(ctx->r25) >> 31);
L_808003FC:
    // 0x808003FC: jal         0x80100094
    // 0x80800400: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_12;
    // 0x80800400: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80800404: jal         0x80087C98
    // 0x80800408: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _gcnewoption_entrypoint_0(rdram, ctx);
        goto after_13;
    // 0x80800408: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_13:
    // 0x8080040C: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x80800410: sll         $t1, $v0, 12
    ctx->r9 = S32(ctx->r2 << 12);
    // 0x80800414: srl         $v0, $t1, 31
    ctx->r2 = S32(U32(ctx->r9) >> 31);
L_80800418:
    // 0x80800418: beql        $v0, $zero, L_80800430
    if (ctx->r2 == 0) {
        // 0x8080041C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800430;
    }
    goto skip_3;
    // 0x8080041C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x80800420: lbu         $t3, 0x65($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X65);
    // 0x80800424: andi        $t4, $t3, 0xFFF7
    ctx->r12 = ctx->r11 & 0XFFF7;
    // 0x80800428: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
    // 0x8080042C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800430:
    // 0x80800430: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800434: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800438: jr          $ra
    // 0x8080043C: nop

    return;
    // 0x8080043C: nop

;}
RECOMP_FUNC void sulights_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800590: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800594: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800598: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080059C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808005A0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808005A4: jal         0x800C883C
    // 0x808005A8: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    func_800C883C(rdram, ctx);
        goto after_0;
    // 0x808005A8: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x808005AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808005B0: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x808005B4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x808005B8: jal         0x808004EC
    // 0x808005BC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    sulights_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x808005BC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x808005C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808005C8: jr          $ra
    // 0x808005CC: nop

    return;
    // 0x808005CC: nop

;}
RECOMP_FUNC void func_80800124_glglobaldata(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800124: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80800128: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8080012C: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x80800130: sb          $t6, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r14;
    // 0x80800134: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80800138: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8080013C: jr          $ra
    // 0x80800140: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    return;
    // 0x80800140: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
;}
RECOMP_FUNC void func_800F2FD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2FD0: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800F2FD4: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800F2FD8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800F2FDC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800F2FE0: bgez        $t6, L_800F2FF4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800F2FE4: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800F2FF4;
    }
    // 0x800F2FE4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F2FE8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800F2FEC: nop

    // 0x800F2FF0: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800F2FF4:
    // 0x800F2FF4: mul.s       $f10, $f6, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800F2FF8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800F2FFC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800F3000: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800F3004: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800F3008: nop

    // 0x800F300C: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800F3010: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800F3014: nop

    // 0x800F3018: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800F301C: beql        $t8, $zero, L_800F306C
    if (ctx->r24 == 0) {
        // 0x800F3020: mfc1        $t8, $f16
        ctx->r24 = (int32_t)ctx->f16.u32l;
            goto L_800F306C;
    }
    goto skip_0;
    // 0x800F3020: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    skip_0:
    // 0x800F3024: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800F3028: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800F302C: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800F3030: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800F3034: nop

    // 0x800F3038: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800F303C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800F3040: nop

    // 0x800F3044: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800F3048: bne         $t8, $zero, L_800F3060
    if (ctx->r24 != 0) {
        // 0x800F304C: nop
    
            goto L_800F3060;
    }
    // 0x800F304C: nop

    // 0x800F3050: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x800F3054: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800F3058: b           L_800F3078
    // 0x800F305C: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_800F3078;
    // 0x800F305C: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_800F3060:
    // 0x800F3060: b           L_800F3078
    // 0x800F3064: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_800F3078;
    // 0x800F3064: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800F3068: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
L_800F306C:
    // 0x800F306C: nop

    // 0x800F3070: bltz        $t8, L_800F3060
    if (SIGNED(ctx->r24) < 0) {
        // 0x800F3074: nop
    
            goto L_800F3060;
    }
    // 0x800F3074: nop

L_800F3078:
    // 0x800F3078: sb          $t8, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r24;
    // 0x800F307C: lbu         $t9, 0x1($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X1);
    // 0x800F3080: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800F3084: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800F3088: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x800F308C: bgez        $t9, L_800F30A0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800F3090: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800F30A0;
    }
    // 0x800F3090: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800F3094: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800F3098: nop

    // 0x800F309C: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_800F30A0:
    // 0x800F30A0: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800F30A4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800F30A8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800F30AC: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800F30B0: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800F30B4: nop

    // 0x800F30B8: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800F30BC: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800F30C0: nop

    // 0x800F30C4: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x800F30C8: beql        $t1, $zero, L_800F3118
    if (ctx->r9 == 0) {
        // 0x800F30CC: mfc1        $t1, $f10
        ctx->r9 = (int32_t)ctx->f10.u32l;
            goto L_800F3118;
    }
    goto skip_1;
    // 0x800F30CC: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    skip_1:
    // 0x800F30D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800F30D4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800F30D8: sub.s       $f10, $f6, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800F30DC: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800F30E0: nop

    // 0x800F30E4: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800F30E8: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800F30EC: nop

    // 0x800F30F0: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x800F30F4: bne         $t1, $zero, L_800F310C
    if (ctx->r9 != 0) {
        // 0x800F30F8: nop
    
            goto L_800F310C;
    }
    // 0x800F30F8: nop

    // 0x800F30FC: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x800F3100: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800F3104: b           L_800F3124
    // 0x800F3108: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_800F3124;
    // 0x800F3108: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_800F310C:
    // 0x800F310C: b           L_800F3124
    // 0x800F3110: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_800F3124;
    // 0x800F3110: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800F3114: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
L_800F3118:
    // 0x800F3118: nop

    // 0x800F311C: bltz        $t1, L_800F310C
    if (SIGNED(ctx->r9) < 0) {
        // 0x800F3120: nop
    
            goto L_800F310C;
    }
    // 0x800F3120: nop

L_800F3124:
    // 0x800F3124: sb          $t1, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r9;
    // 0x800F3128: lbu         $t2, 0x2($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X2);
    // 0x800F312C: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800F3130: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800F3134: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x800F3138: bgez        $t2, L_800F314C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800F313C: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800F314C;
    }
    // 0x800F313C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800F3140: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800F3144: nop

    // 0x800F3148: add.s       $f18, $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f8.fl;
L_800F314C:
    // 0x800F314C: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800F3150: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800F3154: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800F3158: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800F315C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800F3160: nop

    // 0x800F3164: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800F3168: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800F316C: nop

    // 0x800F3170: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x800F3174: beql        $t4, $zero, L_800F31C4
    if (ctx->r12 == 0) {
        // 0x800F3178: mfc1        $t4, $f6
        ctx->r12 = (int32_t)ctx->f6.u32l;
            goto L_800F31C4;
    }
    goto skip_2;
    // 0x800F3178: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    skip_2:
    // 0x800F317C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800F3180: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800F3184: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800F3188: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800F318C: nop

    // 0x800F3190: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800F3194: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800F3198: nop

    // 0x800F319C: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x800F31A0: bne         $t4, $zero, L_800F31B8
    if (ctx->r12 != 0) {
        // 0x800F31A4: nop
    
            goto L_800F31B8;
    }
    // 0x800F31A4: nop

    // 0x800F31A8: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x800F31AC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800F31B0: b           L_800F31D0
    // 0x800F31B4: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_800F31D0;
    // 0x800F31B4: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_800F31B8:
    // 0x800F31B8: b           L_800F31D0
    // 0x800F31BC: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_800F31D0;
    // 0x800F31BC: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800F31C0: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
L_800F31C4:
    // 0x800F31C4: nop

    // 0x800F31C8: bltz        $t4, L_800F31B8
    if (SIGNED(ctx->r12) < 0) {
        // 0x800F31CC: nop
    
            goto L_800F31B8;
    }
    // 0x800F31CC: nop

L_800F31D0:
    // 0x800F31D0: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800F31D4: jr          $ra
    // 0x800F31D8: sb          $t4, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r12;
    return;
    // 0x800F31D8: sb          $t4, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r12;
;}
RECOMP_FUNC void func_8001334C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001334C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80013350: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80013354: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80013358: addiu       $s0, $s0, -0x3390
    ctx->r16 = ADD32(ctx->r16, -0X3390);
    // 0x8001335C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80013360: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80013364: blezl       $t6, L_80013384
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80013368: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80013384;
    }
    goto skip_0;
    // 0x80013368: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_8001336C:
    // 0x8001336C: jal         0x800132BC
    // 0x80013370: nop

    func_800132BC(rdram, ctx);
        goto after_0;
    // 0x80013370: nop

    after_0:
    // 0x80013374: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80013378: bgtz        $t7, L_8001336C
    if (SIGNED(ctx->r15) > 0) {
        // 0x8001337C: nop
    
            goto L_8001336C;
    }
    // 0x8001337C: nop

    // 0x80013380: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80013384:
    // 0x80013384: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80013388: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001338C: jr          $ra
    // 0x80013390: nop

    return;
    // 0x80013390: nop

    // 0x80013394: nop

    // 0x80013398: nop

    // 0x8001339C: nop

;}
RECOMP_FUNC void subaddielink_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800100: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800104: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800108: jal         0x80800044
    // 0x8080010C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    subaddielink_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x8080010C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800110: bne         $v0, $zero, L_80800120
    if (ctx->r2 != 0) {
        // 0x80800114: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_80800120;
    }
    // 0x80800114: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800118: b           L_80800128
    // 0x8080011C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800128;
    // 0x8080011C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800120:
    // 0x80800120: jal         0x80106790
    // 0x80800124: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80800124: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_1:
L_80800128:
    // 0x80800128: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080012C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800130: jr          $ra
    // 0x80800134: nop

    return;
    // 0x80800134: nop

;}
RECOMP_FUNC void func_800B2890(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2890: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B2894: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B2898: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800B289C: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x800B28A0: jal         0x8001B798
    // 0x800B28A4: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    func_8001B798(rdram, ctx);
        goto after_0;
    // 0x800B28A4: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    after_0:
    // 0x800B28A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B28AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B28B0: jr          $ra
    // 0x800B28B4: nop

    return;
    // 0x800B28B4: nop

;}
RECOMP_FUNC void func_800CA794(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA794: jr          $ra
    // 0x800CA798: lwc1        $f0, 0xE4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XE4);
    return;
    // 0x800CA798: lwc1        $f0, 0xE4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XE4);
;}
RECOMP_FUNC void func_80800E88_chterryegg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E88: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800E8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800E90: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800E94: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800E98: jal         0x80100120
    // 0x80800E9C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    func_80100120(rdram, ctx);
        goto after_0;
    // 0x80800E9C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EA4: jal         0x80801188
    // 0x80800EA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801188_chterryegg(rdram, ctx);
        goto after_1;
    // 0x80800EA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800EAC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800EB0: jal         0x80800CF4
    // 0x80800EB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800CF4_chterryegg(rdram, ctx);
        goto after_2;
    // 0x80800EB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800EB8: jal         0x800CB3E0
    // 0x80800EBC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    func_800CB3E0(rdram, ctx);
        goto after_3;
    // 0x80800EBC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_3:
    // 0x80800EC0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800EC4: beq         $v0, $at, L_80800EF4
    if (ctx->r2 == ctx->r1) {
        // 0x80800EC8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800EF4;
    }
    // 0x80800EC8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800ECC: beq         $v0, $at, L_80800F7C
    if (ctx->r2 == ctx->r1) {
        // 0x80800ED0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800F7C;
    }
    // 0x80800ED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800ED4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800ED8: beq         $v0, $at, L_80800F90
    if (ctx->r2 == ctx->r1) {
        // 0x80800EDC: lw          $a0, 0x3C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X3C);
            goto L_80800F90;
    }
    // 0x80800EDC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800EE0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800EE4: beq         $v0, $at, L_80800FBC
    if (ctx->r2 == ctx->r1) {
        // 0x80800EE8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FBC;
    }
    // 0x80800EE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EEC: b           L_80800FD0
    // 0x80800EF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800FD0;
    // 0x80800EF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800EF4:
    // 0x80800EF4: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    // 0x80800EF8: srl         $t6, $a0, 7
    ctx->r14 = S32(U32(ctx->r4) >> 7);
    // 0x80800EFC: jal         0x800DA298
    // 0x80800F00: addiu       $a0, $t6, 0x143
    ctx->r4 = ADD32(ctx->r14, 0X143);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80800F00: addiu       $a0, $t6, 0x143
    ctx->r4 = ADD32(ctx->r14, 0X143);
    after_4:
    // 0x80800F04: bnel        $v0, $zero, L_80800F1C
    if (ctx->r2 != 0) {
        // 0x80800F08: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800F1C;
    }
    goto skip_0;
    // 0x80800F08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800F0C: jal         0x80801138
    // 0x80800F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801138_chterryegg(rdram, ctx);
        goto after_5;
    // 0x80800F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800F14: beq         $v0, $zero, L_80800F34
    if (ctx->r2 == 0) {
        // 0x80800F18: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800F34;
    }
    // 0x80800F18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800F1C:
    // 0x80800F1C: jal         0x80102424
    // 0x80800F20: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x80800F20: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_6:
    // 0x80800F24: jal         0x8010A590
    // 0x80800F28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_7;
    // 0x80800F28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800F2C: b           L_80800FD0
    // 0x80800F30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800FD0;
    // 0x80800F30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800F34:
    // 0x80800F34: jal         0x80800C08
    // 0x80800F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800C08_chterryegg(rdram, ctx);
        goto after_8;
    // 0x80800F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800F3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F40: jal         0x80102424
    // 0x80800F44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_9;
    // 0x80800F44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80800F48: jal         0x8010A570
    // 0x80800F4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_10;
    // 0x80800F4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800F50: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x80800F54: lbu         $t3, 0x75($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X75);
    // 0x80800F58: andi        $t8, $t7, 0xFFFE
    ctx->r24 = ctx->r15 & 0XFFFE;
    // 0x80800F5C: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    // 0x80800F60: lhu         $t0, 0x64($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X64);
    // 0x80800F64: andi        $t4, $t3, 0xFFEF
    ctx->r12 = ctx->r11 & 0XFFEF;
    // 0x80800F68: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x80800F6C: andi        $t2, $t1, 0x10
    ctx->r10 = ctx->r9 & 0X10;
    // 0x80800F70: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x80800F74: b           L_80800FCC
    // 0x80800F78: sb          $t5, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r13;
        goto L_80800FCC;
    // 0x80800F78: sb          $t5, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r13;
L_80800F7C:
    // 0x80800F7C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80800F80: jal         0x8008A548
    // 0x80800F84: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    _subaddietaxi_entrypoint_10(rdram, ctx);
        goto after_11;
    // 0x80800F84: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_11:
    // 0x80800F88: b           L_80800FD0
    // 0x80800F8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800FD0;
    // 0x80800F8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800F90:
    // 0x80800F90: jal         0x80800D88
    // 0x80800F94: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_80800D88_chterryegg(rdram, ctx);
        goto after_12;
    // 0x80800F94: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_12:
    // 0x80800F98: jal         0x8010A570
    // 0x80800F9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_13;
    // 0x80800F9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800FA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FA4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80800FA8: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x80800FAC: jal         0x8008A4F8
    // 0x80800FB0: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    _subaddietaxi_entrypoint_0(rdram, ctx);
        goto after_14;
    // 0x80800FB0: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    after_14:
    // 0x80800FB4: b           L_80800FD0
    // 0x80800FB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800FD0;
    // 0x80800FB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800FBC:
    // 0x80800FBC: jal         0x80102424
    // 0x80800FC0: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80102424(rdram, ctx);
        goto after_15;
    // 0x80800FC0: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_15:
    // 0x80800FC4: jal         0x8010A570
    // 0x80800FC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_16;
    // 0x80800FC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
L_80800FCC:
    // 0x80800FCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800FD0:
    // 0x80800FD0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800FD4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800FD8: jr          $ra
    // 0x80800FDC: nop

    return;
    // 0x80800FDC: nop

;}
RECOMP_FUNC void func_800E7EC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E7EC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E7EC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E7EC8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800E7ECC: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800E7ED0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800E7ED4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800E7ED8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800E7EDC: jal         0x800E7DAC
    // 0x800E7EE0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    func_800E7DAC(rdram, ctx);
        goto after_0;
    // 0x800E7EE0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    after_0:
    // 0x800E7EE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E7EE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E7EEC: jr          $ra
    // 0x800E7EF0: nop

    return;
    // 0x800E7EF0: nop

;}
RECOMP_FUNC void func_800DDD14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DDD14: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800DDD18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800DDD1C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800DDD20: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800DDD24: lh          $t6, 0x14($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X14);
    // 0x800DDD28: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800DDD2C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x800DDD30: beql        $t6, $zero, L_800DDDB4
    if (ctx->r14 == 0) {
        // 0x800DDD34: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800DDDB4;
    }
    goto skip_0;
    // 0x800DDD34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800DDD38: jal         0x800EE88C
    // 0x800DDD3C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    func_800EE88C(rdram, ctx);
        goto after_0;
    // 0x800DDD3C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_0:
    // 0x800DDD40: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800DDD44: jal         0x800EE88C
    // 0x800DDD48: addiu       $a1, $s0, 0xE
    ctx->r5 = ADD32(ctx->r16, 0XE);
    func_800EE88C(rdram, ctx);
        goto after_1;
    // 0x800DDD48: addiu       $a1, $s0, 0xE
    ctx->r5 = ADD32(ctx->r16, 0XE);
    after_1:
    // 0x800DDD4C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800DDD50: lw          $a1, -0x36B8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X36B8);
    // 0x800DDD54: jal         0x800EF334
    // 0x800DDD58: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800EF334(rdram, ctx);
        goto after_2;
    // 0x800DDD58: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_2:
    // 0x800DDD5C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800DDD60: lw          $a1, -0x36B8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X36B8);
    // 0x800DDD64: jal         0x800EF334
    // 0x800DDD68: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_800EF334(rdram, ctx);
        goto after_3;
    // 0x800DDD68: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_3:
    // 0x800DDD6C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800DDD70: lw          $a1, -0x36B4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X36B4);
    // 0x800DDD74: jal         0x800EF04C
    // 0x800DDD78: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800EF04C(rdram, ctx);
        goto after_4;
    // 0x800DDD78: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_4:
    // 0x800DDD7C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800DDD80: lw          $a1, -0x36B4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X36B4);
    // 0x800DDD84: jal         0x800EF04C
    // 0x800DDD88: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_800EF04C(rdram, ctx);
        goto after_5;
    // 0x800DDD88: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_5:
    // 0x800DDD8C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x800DDD90: jal         0x800E3D0C
    // 0x800DDD94: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800E3D0C(rdram, ctx);
        goto after_6;
    // 0x800DDD94: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_6:
    // 0x800DDD98: beql        $v0, $zero, L_800DDDB4
    if (ctx->r2 == 0) {
        // 0x800DDD9C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800DDDB4;
    }
    goto skip_1;
    // 0x800DDD9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x800DDDA0: lh          $t7, 0x14($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X14);
    // 0x800DDDA4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800DDDA8: jal         0x800DE2A4
    // 0x800DDDAC: addu        $a1, $s0, $t7
    ctx->r5 = ADD32(ctx->r16, ctx->r15);
    func_800DE2A4(rdram, ctx);
        goto after_7;
    // 0x800DDDAC: addu        $a1, $s0, $t7
    ctx->r5 = ADD32(ctx->r16, ctx->r15);
    after_7:
    // 0x800DDDB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800DDDB4:
    // 0x800DDDB4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800DDDB8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800DDDBC: jr          $ra
    // 0x800DDDC0: nop

    return;
    // 0x800DDDC0: nop

;}
RECOMP_FUNC void func_808004E0_bsbansnooze(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808004E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808004E8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808004EC: jal         0x80800098
    // 0x808004F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800098_bsbansnooze(rdram, ctx);
        goto after_0;
    // 0x808004F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808004F4: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x808004F8: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x808004FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800500: jal         0x8008CB3C
    // 0x80800504: addiu       $a1, $zero, 0x278
    ctx->r5 = ADD32(0, 0X278);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x80800504: addiu       $a1, $zero, 0x278
    ctx->r5 = ADD32(0, 0X278);
    after_1:
    // 0x80800508: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x8080050C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800514: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800518: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8080051C: jal         0x8009FFD8
    // 0x80800520: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80800520: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_2:
    // 0x80800524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800528: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x8080052C: jal         0x8009C99C
    // 0x80800530: lui         $a2, 0x4060
    ctx->r6 = S32(0X4060 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_3;
    // 0x80800530: lui         $a2, 0x4060
    ctx->r6 = S32(0X4060 << 16);
    after_3:
    // 0x80800534: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80800538: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8080053C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800540: jal         0x8008C9BC
    // 0x80800544: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    baanim_setDurationRange(rdram, ctx);
        goto after_4;
    // 0x80800544: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    after_4:
    // 0x80800548: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(49, 0XA30) << 16);
    // 0x8080054C: lwc1        $f0, 0xA30($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(49, 0XA30));
    // 0x80800550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800554: lui         $a1, 0x4248
    ctx->r5 = S32(0X4248 << 16);
    // 0x80800558: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8080055C: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    // 0x80800560: jal         0x8008C9F0
    // 0x80800564: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_5;
    // 0x80800564: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x80800568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080056C: jal         0x8008CA30
    // 0x80800570: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8008CA30(rdram, ctx);
        goto after_6;
    // 0x80800570: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_6:
    // 0x80800574: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800578: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080057C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800580: jr          $ra
    // 0x80800584: nop

    return;
    // 0x80800584: nop

;}
RECOMP_FUNC void func_800BCC28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BCC28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BCC2C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800BCC30: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800BCC34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800BCC38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BCC3C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BCC40: jal         0x800F23D0
    // 0x800BCC44: addiu       $a0, $a0, -0x7D0C
    ctx->r4 = ADD32(ctx->r4, -0X7D0C);
    func_800F23D0(rdram, ctx);
        goto after_0;
    // 0x800BCC44: addiu       $a0, $a0, -0x7D0C
    ctx->r4 = ADD32(ctx->r4, -0X7D0C);
    after_0:
    // 0x800BCC48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BCC4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BCC50: jr          $ra
    // 0x800BCC54: nop

    return;
    // 0x800BCC54: nop

;}
RECOMP_FUNC void func_808000A8_chfactorylobbydoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000B0: jal         0x808000D0
    // 0x808000B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808000D0_chfactorylobbydoor(rdram, ctx);
        goto after_0;
    // 0x808000B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000B8: jal         0x80086240
    // 0x808000BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _chdoor_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808000BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808000C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000C8: jr          $ra
    // 0x808000CC: nop

    return;
    // 0x808000CC: nop

;}
RECOMP_FUNC void func_80800000_chjadesnake(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: jal         0x8010A85C
    // 0x80800010: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010A85C(rdram, ctx);
        goto after_0;
    // 0x80800010: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80800014: jal         0x80088848
    // 0x80800018: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x80800018: nop

    after_1:
    // 0x8080001C: beq         $v0, $zero, L_80800038
    if (ctx->r2 == 0) {
        // 0x80800020: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800038;
    }
    // 0x80800020: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800024: jal         0x80102424
    // 0x80800028: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x80800028: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_2:
    // 0x8080002C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800030: jal         0x8010A85C
    // 0x80800034: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8010A85C(rdram, ctx);
        goto after_3;
    // 0x80800034: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
L_80800038:
    // 0x80800038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080003C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800040: jr          $ra
    // 0x80800044: nop

    return;
    // 0x80800044: nop

;}
RECOMP_FUNC void func_8080267C_chinflatableboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080267C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80802680: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802684: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80802688: jal         0x80104248
    // 0x8080268C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80104248(rdram, ctx);
        goto after_0;
    // 0x8080268C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80802690: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80802694: lhu         $t6, 0x64($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X64);
    // 0x80802698: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8080269C: beql        $t7, $zero, L_8080271C
    if (ctx->r15 == 0) {
        // 0x808026A0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080271C;
    }
    goto skip_0;
    // 0x808026A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808026A4: jal         0x801039E4
    // 0x808026A8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_801039E4(rdram, ctx);
        goto after_1;
    // 0x808026A8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x808026AC: jal         0x800B27E0
    // 0x808026B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B27E0(rdram, ctx);
        goto after_2;
    // 0x808026B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x808026B4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808026B8: jal         0x8008B304
    // 0x808026BC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_8008B304(rdram, ctx);
        goto after_3;
    // 0x808026BC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x808026C0: jal         0x8008AEDC
    // 0x808026C4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_8008AEDC(rdram, ctx);
        goto after_4;
    // 0x808026C4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_4:
    // 0x808026C8: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x808026CC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808026D0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x808026D4: jal         0x8008C200
    // 0x808026D8: lh          $a0, 0x10($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X10);
    func_8008C200(rdram, ctx);
        goto after_5;
    // 0x808026D8: lh          $a0, 0x10($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X10);
    after_5:
    // 0x808026DC: jal         0x8008AEDC
    // 0x808026E0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_8008AEDC(rdram, ctx);
        goto after_6;
    // 0x808026E0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_6:
    // 0x808026E4: jal         0x8008C27C
    // 0x808026E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8008C27C(rdram, ctx);
        goto after_7;
    // 0x808026E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x808026EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808026F0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808026F4: jal         0x800DFBE0
    // 0x808026F8: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    func_800DFBE0(rdram, ctx);
        goto after_8;
    // 0x808026F8: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_8:
    // 0x808026FC: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80802700: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80802704: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x80802708: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8080270C: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x80802710: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    // 0x80802714: swc1        $f8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f8.u32l;
    // 0x80802718: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080271C:
    // 0x8080271C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802720: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80802724: jr          $ra
    // 0x80802728: nop

    return;
    // 0x80802728: nop

;}
RECOMP_FUNC void func_808000A4_bskazshoessuckspline(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000B0: jal         0x8009E710
    // 0x808000B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bs_getPreviousState(rdram, ctx);
        goto after_0;
    // 0x808000B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808000B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000BC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808000C0: jal         0x8009CA70
    // 0x808000C4: addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
    func_8009CA70(rdram, ctx);
        goto after_1;
    // 0x808000C4: addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
    after_1:
    // 0x808000C8: bnel        $v0, $zero, L_80800100
    if (ctx->r2 != 0) {
        // 0x808000CC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800100;
    }
    goto skip_0;
    // 0x808000CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808000D0: jal         0x80085098
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bashoessuck_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000DC: jal         0x80092880
    // 0x808000E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80092880(rdram, ctx);
        goto after_3;
    // 0x808000E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E8: jal         0x800A2018
    // 0x808000EC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800A2018(rdram, ctx);
        goto after_4;
    // 0x808000EC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F4: jal         0x800A4DA4
    // 0x808000F8: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    func_800A4DA4(rdram, ctx);
        goto after_5;
    // 0x808000F8: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    after_5:
    // 0x808000FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800100:
    // 0x80800100: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800104: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800108: jr          $ra
    // 0x8080010C: nop

    return;
    // 0x8080010C: nop

;}
RECOMP_FUNC void func_8080000C_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800018: jal         0x80100094
    // 0x8080001C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080001C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800020: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800024: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80800028: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8080002C: jal         0x80106790
    // 0x80800030: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80800030: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_1:
    // 0x80800034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800038: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080003C: jr          $ra
    // 0x80800040: nop

    return;
    // 0x80800040: nop

;}
RECOMP_FUNC void _vpscroll_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089090: syscall     759
    recomp_syscall_handler(rdram, ctx, 0x80089090);
    return;
    // 0x80089094: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800D1864(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1864: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D1868: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D186C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800D1870: jal         0x800D16C4
    // 0x800D1874: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_800D16C4(rdram, ctx);
        goto after_0;
    // 0x800D1874: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x800D1878: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D187C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800D1880: jal         0x800D16CC
    // 0x800D1884: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800D16CC(rdram, ctx);
        goto after_1;
    // 0x800D1884: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x800D1888: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800D188C: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800D1890: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800D1894: beq         $t6, $zero, L_800D18E8
    if (ctx->r14 == 0) {
        // 0x800D1898: sll         $v0, $a3, 2
        ctx->r2 = S32(ctx->r7 << 2);
            goto L_800D18E8;
    }
    // 0x800D1898: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x800D189C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800D18A0: lw          $t8, -0x4DB0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4DB0);
    // 0x800D18A4: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x800D18A8: sll         $t2, $v0, 1
    ctx->r10 = S32(ctx->r2 << 1);
    // 0x800D18AC: sll         $t9, $a3, 1
    ctx->r25 = S32(ctx->r7 << 1);
    // 0x800D18B0: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x800D18B4: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800D18B8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800D18BC: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800D18C0: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x800D18C4: lh          $t3, 0x1A04($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X1A04);
    // 0x800D18C8: addiu       $t7, $t7, -0x50B0
    ctx->r15 = ADD32(ctx->r15, -0X50B0);
    // 0x800D18CC: addu        $v1, $v0, $t7
    ctx->r3 = ADD32(ctx->r2, ctx->r15);
    // 0x800D18D0: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x800D18D4: lh          $a2, 0x2($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X2);
    // 0x800D18D8: jal         0x800D2498
    // 0x800D18DC: xor         $a1, $t3, $t1
    ctx->r5 = ctx->r11 ^ ctx->r9;
    func_800D2498(rdram, ctx);
        goto after_2;
    // 0x800D18DC: xor         $a1, $t3, $t1
    ctx->r5 = ctx->r11 ^ ctx->r9;
    after_2:
    // 0x800D18E0: b           L_800D1920
    // 0x800D18E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800D1920;
    // 0x800D18E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D18E8:
    // 0x800D18E8: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800D18EC: lw          $t4, -0x4DB0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4DB0);
    // 0x800D18F0: sll         $t5, $a3, 1
    ctx->r13 = S32(ctx->r7 << 1);
    // 0x800D18F4: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x800D18F8: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x800D18FC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800D1900: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800D1904: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x800D1908: lh          $t9, 0x1A04($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X1A04);
    // 0x800D190C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800D1910: lh          $a0, -0x50B0($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X50B0);
    // 0x800D1914: jal         0x800D2770
    // 0x800D1918: xor         $a1, $t9, $t7
    ctx->r5 = ctx->r25 ^ ctx->r15;
    func_800D2770(rdram, ctx);
        goto after_3;
    // 0x800D1918: xor         $a1, $t9, $t7
    ctx->r5 = ctx->r25 ^ ctx->r15;
    after_3:
    // 0x800D191C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D1920:
    // 0x800D1920: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D1924: jr          $ra
    // 0x800D1928: nop

    return;
    // 0x800D1928: nop

;}
RECOMP_FUNC void func_8009BB18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BB18: lw          $t6, 0xC8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC8);
    // 0x8009BB1C: jr          $ra
    // 0x8009BB20: lwc1        $f0, 0x40($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X40);
    return;
    // 0x8009BB20: lwc1        $f0, 0x40($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X40);
;}
RECOMP_FUNC void func_80800000_gldbDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80800010: jal         0x80016928
    // 0x80800014: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    func_80016928(rdram, ctx);
        goto after_0;
    // 0x80800014: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800018: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8080001C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800020: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800024: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800028: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
L_8080002C:
    // 0x8080002C: srav        $t6, $a1, $v1
    ctx->r14 = S32(SIGNED(ctx->r5) >> (ctx->r3 & 31));
    // 0x80800030: subu        $t7, $a2, $v1
    ctx->r15 = SUB32(ctx->r6, ctx->r3);
    // 0x80800034: sllv        $t8, $a1, $t7
    ctx->r24 = S32(ctx->r5 << (ctx->r15 & 31));
    // 0x80800038: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8080003C: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80800040: slti        $at, $v1, 0xE
    ctx->r1 = SIGNED(ctx->r3) < 0XE ? 1 : 0;
    // 0x80800044: andi        $t0, $t9, 0xFF00
    ctx->r8 = ctx->r25 & 0XFF00;
    // 0x80800048: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8080004C: sb          $t9, -0x2($a0)
    MEM_B(-0X2, ctx->r4) = ctx->r25;
    // 0x80800050: bne         $at, $zero, L_8080002C
    if (ctx->r1 != 0) {
        // 0x80800054: sb          $t0, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = ctx->r8;
            goto L_8080002C;
    }
    // 0x80800054: sb          $t0, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r8;
    // 0x80800058: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8080005C: sb          $zero, 0x42($sp)
    MEM_B(0X42, ctx->r29) = 0;
    // 0x80800060: sb          $t1, 0x43($sp)
    MEM_B(0X43, ctx->r29) = ctx->r9;
    // 0x80800064: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800068: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
L_8080006C:
    // 0x8080006C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800070: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x80800074: sb          $zero, 0x2($v0)
    MEM_B(0X2, ctx->r2) = 0;
    // 0x80800078: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
    // 0x8080007C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800080: bne         $v1, $a2, L_8080006C
    if (ctx->r3 != ctx->r6) {
        // 0x80800084: sb          $zero, -0x4($v0)
        MEM_B(-0X4, ctx->r2) = 0;
            goto L_8080006C;
    }
    // 0x80800084: sb          $zero, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = 0;
    // 0x80800088: jal         0x80016934
    // 0x8080008C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_80016934(rdram, ctx);
        goto after_1;
    // 0x8080008C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_1:
    // 0x80800090: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800094: jal         0x8001E048
    // 0x80800098: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    cic_send_challenge(rdram, ctx);
        goto after_2;
    // 0x80800098: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8080009C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000A4: jal         0x8002E1F0
    // 0x808000A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x808000A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x808000AC: jal         0x8001E11C
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    cic_read_response(rdram, ctx);
        goto after_4;
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000BC: jal         0x8002E1F0
    // 0x808000C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x808000C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x808000C4: jal         0x8001E170
    // 0x808000C8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_8001E170(rdram, ctx);
        goto after_6;
    // 0x808000C8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_6:
    // 0x808000CC: jal         0x80016934
    // 0x808000D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80016934(rdram, ctx);
        goto after_7;
    // 0x808000D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x808000D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000DC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808000E0: jr          $ra
    // 0x808000E4: nop

    return;
    // 0x808000E4: nop

;}
RECOMP_FUNC void func_800BDCB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BDCB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BDCBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BDCC0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BDCC4: jal         0x80087C50
    // 0x800BDCC8: addiu       $a0, $a0, -0x7BF0
    ctx->r4 = ADD32(ctx->r4, -0X7BF0);
    _gccubeDll_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x800BDCC8: addiu       $a0, $a0, -0x7BF0
    ctx->r4 = ADD32(ctx->r4, -0X7BF0);
    after_0:
    // 0x800BDCCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BDCD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BDCD4: jr          $ra
    // 0x800BDCD8: nop

    return;
    // 0x800BDCD8: nop

;}
RECOMP_FUNC void func_808007A0_bsmum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007A0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808007A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808007A8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808007AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808007B0: jal         0x8008CABC
    // 0x808007B4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808007B4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808007B8: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x808007BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808007C0: sltiu       $at, $v1, 0x5
    ctx->r1 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x808007C4: beq         $at, $zero, L_8080096C
    if (ctx->r1 == 0) {
        // 0x808007C8: sw          $v1, 0x15C($s0)
        MEM_W(0X15C, ctx->r16) = ctx->r3;
            goto L_8080096C;
    }
    // 0x808007C8: sw          $v1, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r3;
    // 0x808007CC: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x808007D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(308, 0X1128) << 16);
    // 0x808007D4: addu        $at, $at, $t6
    gpr jr_addend_808007DC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808007D8: lw          $t6, 0x1128($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(308, 0X1128));
    // 0x808007DC: jr          $t6
    // 0x808007E0: nop

    switch (jr_addend_808007DC >> 2) {
        case 0: goto L_80800964; break;
        case 1: goto L_808007E4; break;
        case 2: goto L_80800910; break;
        case 3: goto L_8080092C; break;
        case 4: goto L_80800948; break;
        default: switch_error(__func__, 0x808007DC, 0x80801128);
    }
    // 0x808007E0: nop

L_808007E4:
    // 0x808007E4: jal         0x8008AF24
    // 0x808007E8: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x808007E8: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    after_1:
    // 0x808007EC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808007F0: jal         0x8008AED4
    // 0x808007F4: addiu       $a1, $zero, 0xBD
    ctx->r5 = ADD32(0, 0XBD);
    anctrl_setIndex(rdram, ctx);
        goto after_2;
    // 0x808007F4: addiu       $a1, $zero, 0xBD
    ctx->r5 = ADD32(0, 0XBD);
    after_2:
    // 0x808007F8: lui         $a1, 0x3F99
    ctx->r5 = S32(0X3F99 << 16);
    // 0x808007FC: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800800: jal         0x8008B1BC
    // 0x80800804: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_setDuration(rdram, ctx);
        goto after_3;
    // 0x80800804: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x80800808: lui         $a1, 0x3E09
    ctx->r5 = S32(0X3E09 << 16);
    // 0x8080080C: ori         $a1, $a1, 0x374C
    ctx->r5 = ctx->r5 | 0X374C;
    // 0x80800810: jal         0x8008B1C8
    // 0x80800814: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_8008B1C8(rdram, ctx);
        goto after_4;
    // 0x80800814: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_4:
    // 0x80800818: lui         $a1, 0x3E13
    ctx->r5 = S32(0X3E13 << 16);
    // 0x8080081C: ori         $a1, $a1, 0x74BC
    ctx->r5 = ctx->r5 | 0X74BC;
    // 0x80800820: jal         0x8008B24C
    // 0x80800824: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_setStart(rdram, ctx);
        goto after_5;
    // 0x80800824: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_5:
    // 0x80800828: lui         $a2, 0x3F11
    ctx->r6 = S32(0X3F11 << 16);
    // 0x8080082C: ori         $a2, $a2, 0xEB85
    ctx->r6 = ctx->r6 | 0XEB85;
    // 0x80800830: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800834: jal         0x8008B1D4
    // 0x80800838: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_6;
    // 0x80800838: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
    // 0x8080083C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800840: jal         0x8008B134
    // 0x80800844: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_7;
    // 0x80800844: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80800848: jal         0x8008B064
    // 0x8080084C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_start(rdram, ctx);
        goto after_8;
    // 0x8080084C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_8:
    // 0x80800850: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x80800854: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800858: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080085C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800860: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800864: jal         0x8009FFD8
    // 0x80800868: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_9;
    // 0x80800868: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_9:
    // 0x8080086C: jal         0x8009EF04
    // 0x80800870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_distance(rdram, ctx);
        goto after_10;
    // 0x80800870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800874: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800878: nop

    // 0x8080087C: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80800880: nop

    // 0x80800884: bc1t        L_808008A0
    if (c1cs) {
        // 0x80800888: nop
    
            goto L_808008A0;
    }
    // 0x80800888: nop

    // 0x8080088C: jal         0x8009EEB8
    // 0x80800890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_11;
    // 0x80800890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800894: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800898: jal         0x8009C914
    // 0x8080089C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_12;
    // 0x8080089C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
L_808008A0:
    // 0x808008A0: jal         0x8009C990
    // 0x808008A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_13;
    // 0x808008A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808008A8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808008AC: jal         0x8009B9C0
    // 0x808008B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_14;
    // 0x808008B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808008B4: jal         0x80800E64
    // 0x808008B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bsmum_entrypoint_13(rdram, ctx);
        goto after_15;
    // 0x808008B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808008BC: jal         0x8009C990
    // 0x808008C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_16;
    // 0x808008C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808008C4: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x808008C8: jal         0x8009BB00
    // 0x808008CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_17;
    // 0x808008CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x808008D0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808008D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008D8: jal         0x8009BA68
    // 0x808008DC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_18;
    // 0x808008DC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_18:
    // 0x808008E0: lui         $a1, 0x4431
    ctx->r5 = S32(0X4431 << 16);
    // 0x808008E4: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x808008E8: jal         0x8009BA58
    // 0x808008EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_19;
    // 0x808008EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x808008F0: lui         $a1, 0xC4A8
    ctx->r5 = S32(0XC4A8 << 16);
    // 0x808008F4: ori         $a1, $a1, 0xC000
    ctx->r5 = ctx->r5 | 0XC000;
    // 0x808008F8: jal         0x8009BCB4
    // 0x808008FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_gravity(rdram, ctx);
        goto after_20;
    // 0x808008FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80800900: jal         0x80800000
    // 0x80800904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsmum(rdram, ctx);
        goto after_21;
    // 0x80800904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800908: b           L_80800970
    // 0x8080090C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800970;
    // 0x8080090C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800910:
    // 0x80800910: lui         $a1, 0x3F1B
    ctx->r5 = S32(0X3F1B << 16);
    // 0x80800914: ori         $a1, $a1, 0x3D08
    ctx->r5 = ctx->r5 | 0X3D08;
    // 0x80800918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080091C: jal         0x8008CF1C
    // 0x80800920: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_22;
    // 0x80800920: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    after_22:
    // 0x80800924: b           L_80800970
    // 0x80800928: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800970;
    // 0x80800928: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080092C:
    // 0x8080092C: lui         $a2, 0x3FA6
    ctx->r6 = S32(0X3FA6 << 16);
    // 0x80800930: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800938: jal         0x8008CF1C
    // 0x8080093C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_23;
    // 0x8080093C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_23:
    // 0x80800940: b           L_80800970
    // 0x80800944: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800970;
    // 0x80800944: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800948:
    // 0x80800948: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x8080094C: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800954: jal         0x8008CF1C
    // 0x80800958: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_24;
    // 0x80800958: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_24:
    // 0x8080095C: b           L_80800970
    // 0x80800960: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800970;
    // 0x80800960: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800964:
    // 0x80800964: jal         0x8009BC6C
    // 0x80800968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_25;
    // 0x80800968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
L_8080096C:
    // 0x8080096C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800970:
    // 0x80800970: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800974: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800978: jr          $ra
    // 0x8080097C: nop

    return;
    // 0x8080097C: nop

;}
RECOMP_FUNC void _bskazshoessuckspline_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800835F8: syscall     68
    recomp_syscall_handler(rdram, ctx, 0x800835F8);
    return;
    // 0x800835FC: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_800BC3F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BC3F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BC3F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BC3F8: jal         0x8001BAFC
    // 0x800BC3FC: nop

    defrag(rdram, ctx);
        goto after_0;
    // 0x800BC3FC: nop

    after_0:
    // 0x800BC400: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BC404: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BC408: jr          $ra
    // 0x800BC40C: nop

    return;
    // 0x800BC40C: nop

;}
RECOMP_FUNC void ncbatarget_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800078: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080007C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800080: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800084: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800088: lui         $a1, 0x44FA
    ctx->r5 = S32(0X44FA << 16);
    // 0x8080008C: lui         $a2, 0x457A
    ctx->r6 = S32(0X457A << 16);
    // 0x80800090: jal         0x801120CC
    // 0x80800094: lui         $a3, 0xC57A
    ctx->r7 = S32(0XC57A << 16);
    func_801120CC(rdram, ctx);
        goto after_0;
    // 0x80800094: lui         $a3, 0xC57A
    ctx->r7 = S32(0XC57A << 16);
    after_0:
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080009C: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    // 0x808000A0: jal         0x80111B8C
    // 0x808000A4: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    func_80111B8C(rdram, ctx);
        goto after_1;
    // 0x808000A4: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    after_1:
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000AC: jal         0x801124D0
    // 0x808000B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_801124D0(rdram, ctx);
        goto after_2;
    // 0x808000B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B8: jal         0x80115858
    // 0x808000BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80115858(rdram, ctx);
        goto after_3;
    // 0x808000BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C4: jal         0x80115870
    // 0x808000C8: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    func_80115870(rdram, ctx);
        goto after_4;
    // 0x808000C8: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    after_4:
    // 0x808000CC: jal         0x800EFD24
    // 0x808000D0: lw          $a0, 0x58($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X58);
    func_800EFD24(rdram, ctx);
        goto after_5;
    // 0x808000D0: lw          $a0, 0x58($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X58);
    after_5:
    // 0x808000D4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808000D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808000DC: lw          $t6, 0x58($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X58);
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000E8: jal         0x8011607C
    // 0x808000EC: swc1        $f4, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f4.u32l;
    func_8011607C(rdram, ctx);
        goto after_6;
    // 0x808000EC: swc1        $f4, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f4.u32l;
    after_6:
    // 0x808000F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000FC: jr          $ra
    // 0x80800100: nop

    return;
    // 0x80800100: nop

;}
RECOMP_FUNC void func_8080363C_chjiggygamenew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080363C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803640: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803644: jal         0x80106790
    // 0x80803648: nop

    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80803648: nop

    after_0:
    // 0x8080364C: lhu         $v0, 0x72($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X72);
    // 0x80803650: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803654: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803658: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x8080365C: xori        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 ^ 0X1;
    // 0x80803660: jr          $ra
    // 0x80803664: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
    return;
    // 0x80803664: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void bsrest_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800864: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800868: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080086C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800870: beq         $a1, $zero, L_808008A0
    if (ctx->r5 == 0) {
        // 0x80800874: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_808008A0;
    }
    // 0x80800874: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800878: jal         0x80800188
    // 0x8080087C: nop

    bsrest_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x8080087C: nop

    after_0:
    // 0x80800880: jal         0x800846B8
    // 0x80800884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badata_entrypoint_15(rdram, ctx);
        goto after_1;
    // 0x80800884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800888: beq         $v0, $zero, L_808008B4
    if (ctx->r2 == 0) {
        // 0x8080088C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008B4;
    }
    // 0x8080088C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800890: jal         0x8009D3A8
    // 0x80800894: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_2;
    // 0x80800894: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800898: b           L_808008B4
    // 0x8080089C: nop

        goto L_808008B4;
    // 0x8080089C: nop

L_808008A0:
    // 0x808008A0: jal         0x800A4CA8
    // 0x808008A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_3;
    // 0x808008A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808008A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808008AC: jal         0x801160DC
    // 0x808008B0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_801160DC(rdram, ctx);
        goto after_4;
    // 0x808008B0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
L_808008B4:
    // 0x808008B4: jal         0x808000E4
    // 0x808008B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    static_344_808000E4(rdram, ctx);
        goto after_5;
    // 0x808008B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808008BC: jal         0x8009CC68
    // 0x808008C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009CC68(rdram, ctx);
        goto after_6;
    // 0x808008C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808008C4: bne         $v0, $zero, L_808008D4
    if (ctx->r2 != 0) {
        // 0x808008C8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808008D4;
    }
    // 0x808008C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808008CC: b           L_808008D8
    // 0x808008D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808008D8;
    // 0x808008D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808008D4:
    // 0x808008D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808008D8:
    // 0x808008D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808008DC: jr          $ra
    // 0x808008E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808008E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800A3970(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3970: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A3974: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A3978: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800A397C: lw          $v0, 0xA0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XA0);
    // 0x800A3980: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800A3984: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800A3988: lwc1        $f6, 0x40($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X40);
    // 0x800A398C: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800A3990: nop

    // 0x800A3994: bc1tl       L_800A39A8
    if (c1cs) {
        // 0x800A3998: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_800A39A8;
    }
    goto skip_0;
    // 0x800A3998: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_0:
    // 0x800A399C: b           L_800A3A70
    // 0x800A39A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A3A70;
    // 0x800A39A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A39A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_800A39A8:
    // 0x800A39A8: nop

    // 0x800A39AC: swc1        $f8, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f8.u32l;
    // 0x800A39B0: jal         0x800A3274
    // 0x800A39B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800A3274(rdram, ctx);
        goto after_0;
    // 0x800A39B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A39B8: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x800A39BC: bne         $v0, $at, L_800A39D4
    if (ctx->r2 != ctx->r1) {
        // 0x800A39C0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_800A39D4;
    }
    // 0x800A39C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800A39C4: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    // 0x800A39C8: jal         0x8009E7C8
    // 0x800A39CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009E7C8(rdram, ctx);
        goto after_1;
    // 0x800A39CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x800A39D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_800A39D4:
    // 0x800A39D4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800A39D8: beq         $a1, $zero, L_800A39F0
    if (ctx->r5 == 0) {
        // 0x800A39DC: nop
    
            goto L_800A39F0;
    }
    // 0x800A39DC: nop

    // 0x800A39E0: jal         0x800A392C
    // 0x800A39E4: nop

    func_800A392C(rdram, ctx);
        goto after_2;
    // 0x800A39E4: nop

    after_2:
    // 0x800A39E8: b           L_800A3A74
    // 0x800A39EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A3A74;
    // 0x800A39EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A39F0:
    // 0x800A39F0: jal         0x800A3274
    // 0x800A39F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800A3274(rdram, ctx);
        goto after_3;
    // 0x800A39F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_3:
    // 0x800A39F8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800A39FC: beq         $v0, $at, L_800A3A28
    if (ctx->r2 == ctx->r1) {
        // 0x800A3A00: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_800A3A28;
    }
    // 0x800A3A00: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800A3A04: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800A3A08: beq         $v0, $at, L_800A3A38
    if (ctx->r2 == ctx->r1) {
        // 0x800A3A0C: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_800A3A38;
    }
    // 0x800A3A0C: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x800A3A10: beq         $v0, $at, L_800A3A48
    if (ctx->r2 == ctx->r1) {
        // 0x800A3A14: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_800A3A48;
    }
    // 0x800A3A14: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x800A3A18: beq         $v0, $at, L_800A3A58
    if (ctx->r2 == ctx->r1) {
        // 0x800A3A1C: nop
    
            goto L_800A3A58;
    }
    // 0x800A3A1C: nop

    // 0x800A3A20: b           L_800A3A68
    // 0x800A3A24: nop

        goto L_800A3A68;
    // 0x800A3A24: nop

L_800A3A28:
    // 0x800A3A28: jal         0x800A392C
    // 0x800A3A2C: addiu       $a1, $zero, 0x1212
    ctx->r5 = ADD32(0, 0X1212);
    func_800A392C(rdram, ctx);
        goto after_4;
    // 0x800A3A2C: addiu       $a1, $zero, 0x1212
    ctx->r5 = ADD32(0, 0X1212);
    after_4:
    // 0x800A3A30: b           L_800A3A74
    // 0x800A3A34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A3A74;
    // 0x800A3A34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A3A38:
    // 0x800A3A38: jal         0x800A392C
    // 0x800A3A3C: addiu       $a1, $zero, 0x1213
    ctx->r5 = ADD32(0, 0X1213);
    func_800A392C(rdram, ctx);
        goto after_5;
    // 0x800A3A3C: addiu       $a1, $zero, 0x1213
    ctx->r5 = ADD32(0, 0X1213);
    after_5:
    // 0x800A3A40: b           L_800A3A74
    // 0x800A3A44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A3A74;
    // 0x800A3A44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A3A48:
    // 0x800A3A48: jal         0x800A392C
    // 0x800A3A4C: addiu       $a1, $zero, 0x1214
    ctx->r5 = ADD32(0, 0X1214);
    func_800A392C(rdram, ctx);
        goto after_6;
    // 0x800A3A4C: addiu       $a1, $zero, 0x1214
    ctx->r5 = ADD32(0, 0X1214);
    after_6:
    // 0x800A3A50: b           L_800A3A74
    // 0x800A3A54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A3A74;
    // 0x800A3A54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A3A58:
    // 0x800A3A58: jal         0x800A392C
    // 0x800A3A5C: addiu       $a1, $zero, 0x1216
    ctx->r5 = ADD32(0, 0X1216);
    func_800A392C(rdram, ctx);
        goto after_7;
    // 0x800A3A5C: addiu       $a1, $zero, 0x1216
    ctx->r5 = ADD32(0, 0X1216);
    after_7:
    // 0x800A3A60: b           L_800A3A74
    // 0x800A3A64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A3A74;
    // 0x800A3A64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A3A68:
    // 0x800A3A68: jal         0x800A392C
    // 0x800A3A6C: addiu       $a1, $zero, 0x1217
    ctx->r5 = ADD32(0, 0X1217);
    func_800A392C(rdram, ctx);
        goto after_8;
    // 0x800A3A6C: addiu       $a1, $zero, 0x1217
    ctx->r5 = ADD32(0, 0X1217);
    after_8:
L_800A3A70:
    // 0x800A3A70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A3A74:
    // 0x800A3A74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A3A78: jr          $ra
    // 0x800A3A7C: nop

    return;
    // 0x800A3A7C: nop

;}
RECOMP_FUNC void _idflash_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088D40: syscall     737
    recomp_syscall_handler(rdram, ctx, 0x80088D40);
    return;
    // 0x80088D44: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80801574_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801574: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801578: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080157C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801580: jal         0x8080000C
    // 0x80801584: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8080000C_bstrexlarge(rdram, ctx);
        goto after_0;
    // 0x80801584: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801588: jal         0x8080081C
    // 0x8080158C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bstrexlarge_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x8080158C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801590: jal         0x808004B4
    // 0x80801594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808004B4_bstrexlarge(rdram, ctx);
        goto after_2;
    // 0x80801594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801598: lui         $a1, 0x3F11
    ctx->r5 = S32(0X3F11 << 16);
    // 0x8080159C: ori         $a1, $a1, 0xF8A1
    ctx->r5 = ctx->r5 | 0XF8A1;
    // 0x808015A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015A4: jal         0x800A2D2C
    // 0x808015A8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800A2D2C(rdram, ctx);
        goto after_3;
    // 0x808015A8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_3:
    // 0x808015AC: lui         $a1, 0x3D8F
    ctx->r5 = S32(0X3D8F << 16);
    // 0x808015B0: ori         $a1, $a1, 0xC505
    ctx->r5 = ctx->r5 | 0XC505;
    // 0x808015B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015B8: jal         0x800A2D2C
    // 0x808015BC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800A2D2C(rdram, ctx);
        goto after_4;
    // 0x808015BC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_4:
    // 0x808015C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808015C8: jal         0x808002E0
    // 0x808015CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_808002E0_bstrexlarge(rdram, ctx);
        goto after_5;
    // 0x808015CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x808015D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015D4: jal         0x8009E5C8
    // 0x808015D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_6;
    // 0x808015D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x808015DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808015E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808015E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808015E8: jr          $ra
    // 0x808015EC: nop

    return;
    // 0x808015EC: nop

;}
RECOMP_FUNC void func_80801640_gcmapsects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801640: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80801644: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80801648: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8080164C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80801650: addiu       $s2, $sp, 0x30
    ctx->r18 = ADD32(ctx->r29, 0X30);
    // 0x80801654: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801658: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080165C: jal         0x800E3980
    // 0x80801660: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800E3980(rdram, ctx);
        goto after_0;
    // 0x80801660: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x80801664: lbu         $t6, 0x80($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X80);
    // 0x80801668: bnel        $t6, $zero, L_808016AC
    if (ctx->r14 != 0) {
        // 0x8080166C: lbu         $v0, 0x77($s1)
        ctx->r2 = MEM_BU(ctx->r17, 0X77);
            goto L_808016AC;
    }
    goto skip_0;
    // 0x8080166C: lbu         $v0, 0x77($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X77);
    skip_0:
    // 0x80801670: lbu         $t7, 0x77($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X77);
    // 0x80801674: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801678: blez        $t7, L_8080170C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8080167C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8080170C;
    }
    // 0x8080167C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80801680:
    // 0x80801680: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80801684: jal         0x80800DC8
    // 0x80801688: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_80800DC8_gcmapsects(rdram, ctx);
        goto after_1;
    // 0x80801688: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_1:
    // 0x8080168C: lbu         $t8, 0x77($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X77);
    // 0x80801690: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80801694: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80801698: bnel        $at, $zero, L_80801680
    if (ctx->r1 != 0) {
        // 0x8080169C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80801680;
    }
    goto skip_1;
    // 0x8080169C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_1:
    // 0x808016A0: b           L_80801710
    // 0x808016A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801710;
    // 0x808016A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808016A8: lbu         $v0, 0x77($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X77);
L_808016AC:
    // 0x808016AC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808016B0: blez        $v0, L_808016E8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808016B4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808016E8;
    }
    // 0x808016B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_808016B8:
    // 0x808016B8: jal         0x80801174
    // 0x808016BC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80801174_gcmapsects(rdram, ctx);
        goto after_2;
    // 0x808016BC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x808016C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808016C4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808016C8: jal         0x80801320
    // 0x808016CC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_80801320_gcmapsects(rdram, ctx);
        goto after_3;
    // 0x808016CC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_3:
    // 0x808016D0: lbu         $v0, 0x77($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X77);
    // 0x808016D4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808016D8: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808016DC: bnel        $at, $zero, L_808016B8
    if (ctx->r1 != 0) {
        // 0x808016E0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808016B8;
    }
    goto skip_2;
    // 0x808016E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_2:
    // 0x808016E4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_808016E8:
    // 0x808016E8: blez        $v0, L_8080170C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808016EC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8080170C;
    }
    // 0x808016EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_808016F0:
    // 0x808016F0: jal         0x808013C0
    // 0x808016F4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_808013C0_gcmapsects(rdram, ctx);
        goto after_4;
    // 0x808016F4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x808016F8: lbu         $t9, 0x77($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X77);
    // 0x808016FC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80801700: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80801704: bnel        $at, $zero, L_808016F0
    if (ctx->r1 != 0) {
        // 0x80801708: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808016F0;
    }
    goto skip_3;
    // 0x80801708: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_3:
L_8080170C:
    // 0x8080170C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801710:
    // 0x80801710: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801714: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80801718: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8080171C: jr          $ra
    // 0x80801720: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80801720: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void heap_realloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B208: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001B20C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001B210: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8001B214: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001B218: lw          $t6, -0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, -0XC);
    // 0x8001B21C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8001B220: subu        $t7, $t6, $a0
    ctx->r15 = SUB32(ctx->r14, ctx->r4);
    // 0x8001B224: sltu        $at, $t7, $a1
    ctx->r1 = ctx->r15 < ctx->r5 ? 1 : 0;
    // 0x8001B228: bnel        $at, $zero, L_8001B244
    if (ctx->r1 != 0) {
        // 0x8001B22C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8001B244;
    }
    goto skip_0;
    // 0x8001B22C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x8001B230: jal         0x8001B1C8
    // 0x8001B234: addiu       $a0, $a0, -0x10
    ctx->r4 = ADD32(ctx->r4, -0X10);
    heap_resize_block(rdram, ctx);
        goto after_0;
    // 0x8001B234: addiu       $a0, $a0, -0x10
    ctx->r4 = ADD32(ctx->r4, -0X10);
    after_0:
    // 0x8001B238: b           L_8001B374
    // 0x8001B23C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
        goto L_8001B374;
    // 0x8001B23C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x8001B240: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8001B244:
    // 0x8001B244: jal         0x8001B864
    // 0x8001B248: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    func_8001B864(rdram, ctx);
        goto after_1;
    // 0x8001B248: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_1:
    // 0x8001B24C: addiu       $a2, $s1, -0x10
    ctx->r6 = ADD32(ctx->r17, -0X10);
    // 0x8001B250: lw          $v0, 0x4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X4);
    // 0x8001B254: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8001B258: lbu         $t8, 0xF($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XF);
    // 0x8001B25C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8001B260: srl         $t9, $t8, 6
    ctx->r25 = S32(U32(ctx->r24) >> 6);
    // 0x8001B264: bnel        $t9, $zero, L_8001B2E4
    if (ctx->r25 != 0) {
        // 0x8001B268: sw          $a1, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r5;
            goto L_8001B2E4;
    }
    goto skip_1;
    // 0x8001B268: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    skip_1:
    // 0x8001B26C: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x8001B270: subu        $t1, $t0, $a2
    ctx->r9 = SUB32(ctx->r8, ctx->r6);
    // 0x8001B274: addiu       $t2, $t1, -0x10
    ctx->r10 = ADD32(ctx->r9, -0X10);
    // 0x8001B278: sltu        $at, $t2, $a1
    ctx->r1 = ctx->r10 < ctx->r5 ? 1 : 0;
    // 0x8001B27C: bnel        $at, $zero, L_8001B2E4
    if (ctx->r1 != 0) {
        // 0x8001B280: sw          $a1, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r5;
            goto L_8001B2E4;
    }
    goto skip_2;
    // 0x8001B280: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    skip_2:
    // 0x8001B284: lw          $t3, 0x10($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X10);
    // 0x8001B288: lw          $t4, 0x14($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X14);
    // 0x8001B28C: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8001B290: addiu       $v1, $v1, -0x8B0
    ctx->r3 = ADD32(ctx->r3, -0X8B0);
    // 0x8001B294: sw          $t3, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r11;
    // 0x8001B298: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x8001B29C: lw          $t5, 0x14($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X14);
    // 0x8001B2A0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8001B2A4: sw          $t5, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r13;
    // 0x8001B2A8: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x8001B2AC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8001B2B0: subu        $t9, $t8, $v0
    ctx->r25 = SUB32(ctx->r24, ctx->r2);
    // 0x8001B2B4: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8001B2B8: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8001B2BC: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x8001B2C0: sw          $t1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r9;
    // 0x8001B2C4: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x8001B2C8: jal         0x8001B1C8
    // 0x8001B2CC: sw          $a2, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r6;
    heap_resize_block(rdram, ctx);
        goto after_2;
    // 0x8001B2CC: sw          $a2, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r6;
    after_2:
    // 0x8001B2D0: jal         0x8001B864
    // 0x8001B2D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8001B864(rdram, ctx);
        goto after_3;
    // 0x8001B2D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x8001B2D8: b           L_8001B374
    // 0x8001B2DC: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
        goto L_8001B374;
    // 0x8001B2DC: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x8001B2E0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
L_8001B2E4:
    // 0x8001B2E4: jal         0x8001ACCC
    // 0x8001B2E8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    heap_alloc(rdram, ctx);
        goto after_4;
    // 0x8001B2E8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_4:
    // 0x8001B2EC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8001B2F0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8001B2F4: bne         $v0, $zero, L_8001B304
    if (ctx->r2 != 0) {
        // 0x8001B2F8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8001B304;
    }
    // 0x8001B2F8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8001B2FC: b           L_8001B374
    // 0x8001B300: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001B374;
    // 0x8001B300: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001B304:
    // 0x8001B304: lw          $t3, 0xC($a2)
    ctx->r11 = MEM_W(ctx->r6, 0XC);
    // 0x8001B308: lbu         $t7, -0x1($s0)
    ctx->r15 = MEM_BU(ctx->r16, -0X1);
    // 0x8001B30C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8001B310: sll         $t4, $t3, 28
    ctx->r12 = S32(ctx->r11 << 28);
    // 0x8001B314: srl         $t5, $t4, 31
    ctx->r13 = S32(U32(ctx->r12) >> 31);
    // 0x8001B318: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x8001B31C: andi        $t8, $t6, 0x8
    ctx->r24 = ctx->r14 & 0X8;
    // 0x8001B320: andi        $t9, $t7, 0xFFF7
    ctx->r25 = ctx->r15 & 0XFFF7;
    // 0x8001B324: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x8001B328: sb          $t6, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r14;
    // 0x8001B32C: lw          $t1, 0xC($a2)
    ctx->r9 = MEM_W(ctx->r6, 0XC);
    // 0x8001B330: andi        $t7, $t6, 0xFB
    ctx->r15 = ctx->r14 & 0XFB;
    // 0x8001B334: sll         $t2, $t1, 29
    ctx->r10 = S32(ctx->r9 << 29);
    // 0x8001B338: srl         $t3, $t2, 31
    ctx->r11 = S32(U32(ctx->r10) >> 31);
    // 0x8001B33C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8001B340: andi        $t5, $t4, 0x4
    ctx->r13 = ctx->r12 & 0X4;
    // 0x8001B344: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x8001B348: jal         0x8001BD30
    // 0x8001B34C: sb          $t8, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r24;
    func_8001BD30(rdram, ctx);
        goto after_5;
    // 0x8001B34C: sb          $t8, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r24;
    after_5:
    // 0x8001B350: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001B354: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8001B358: jal         0x80019E70
    // 0x8001B35C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    aligned8_memcpy(rdram, ctx);
        goto after_6;
    // 0x8001B35C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_6:
    // 0x8001B360: jal         0x8001B084
    // 0x8001B364: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    heap_free(rdram, ctx);
        goto after_7;
    // 0x8001B364: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x8001B368: jal         0x8001B864
    // 0x8001B36C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8001B864(rdram, ctx);
        goto after_8;
    // 0x8001B36C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x8001B370: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8001B374:
    // 0x8001B374: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001B378: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001B37C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8001B380: jr          $ra
    // 0x8001B384: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8001B384: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void scinfobar_entrypoint_24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_hud_element_begin(rdram, ctx);
    // 0x80800764: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800768: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8080076C: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80800770: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80800774: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800778: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8080077C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800780: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800784: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x80800788: jal         0x808006EC
    // 0x8080078C: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    func_808006EC_scinfobar(rdram, ctx);
        goto after_0;
    // 0x8080078C: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    after_0:
    // 0x80800790: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x80800794: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80800798: beql        $t6, $at, L_808007DC
    if (ctx->r14 == ctx->r1) {
        // 0x8080079C: lbu         $v0, 0x2($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X2);
            goto L_808007DC;
    }
    goto skip_0;
    // 0x8080079C: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    skip_0:
    // 0x808007A0: lw          $t7, 0x1C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1C);
    // 0x808007A4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(3338, 0XD54) << 16);
    // 0x808007A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808007AC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x808007B0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x808007B4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808007B8: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x808007BC: lw          $v0, 0xD54($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(3338, 0XD54));
    // 0x808007C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808007C4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x808007C8: beql        $v0, $zero, L_808007DC
    if (ctx->r2 == 0) {
        // 0x808007CC: lbu         $v0, 0x2($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X2);
            goto L_808007DC;
    }
    goto skip_1;
    // 0x808007CC: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    skip_1:
    // 0x808007D0: jalr        $v0
    // 0x808007D4: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x808007D4: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_1:
    // 0x808007D8: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
L_808007DC:
    // 0x808007DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808007E0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x808007E4: beq         $v0, $zero, L_80800878
    if (ctx->r2 == 0) {
        // 0x808007E8: addiu       $t5, $zero, 0xFF
        ctx->r13 = ADD32(0, 0XFF);
            goto L_80800878;
    }
    // 0x808007E8: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x808007EC: lbu         $t9, 0x0($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X0);
    // 0x808007F0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808007F4: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x808007F8: bne         $t9, $v0, L_80800878
    if (ctx->r25 != ctx->r2) {
        // 0x808007FC: or          $a3, $s3, $zero
        ctx->r7 = ctx->r19 | 0;
            goto L_80800878;
    }
    // 0x808007FC: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x80800800: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80800804: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800808: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x8080080C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80800810: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800814: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800818: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8080081C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800820: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80800824: bnel        $v1, $at, L_80800834
    if (ctx->r3 != ctx->r1) {
        // 0x80800828: lh          $a1, 0x4($s0)
        ctx->r5 = MEM_H(ctx->r16, 0X4);
            goto L_80800834;
    }
    goto skip_2;
    // 0x80800828: lh          $a1, 0x4($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4);
    skip_2:
    // 0x8080082C: subu        $v0, $t1, $v0
    ctx->r2 = SUB32(ctx->r9, ctx->r2);
    // 0x80800830: lh          $a1, 0x4($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4);
L_80800834:
    // 0x80800834: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80800838: lbu         $t2, 0x32($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X32);
    // 0x8080083C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800840: jal         0x80800608
    // 0x80800844: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    func_80800608_scinfobar(rdram, ctx);
        goto after_2;
    // 0x80800844: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_2:
    // 0x80800848: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x8080084C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80800850: lh          $a1, 0x6($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X6);
    // 0x80800854: subu        $t4, $t3, $v0
    ctx->r12 = SUB32(ctx->r11, ctx->r2);
    // 0x80800858: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8080085C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80800860: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800864: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80800868: jal         0x80800608
    // 0x8080086C: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    func_80800608_scinfobar(rdram, ctx);
        goto after_3;
    // 0x8080086C: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_3:
    // 0x80800870: b           L_80800894
    // 0x80800874: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800894;
    // 0x80800874: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800878:
    // 0x80800878: lh          $a1, 0x4($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4);
    // 0x8080087C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80800880: lbu         $t6, 0x32($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X32);
    // 0x80800884: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x80800888: jal         0x80800608
    // 0x8080088C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    func_80800608_scinfobar(rdram, ctx);
        goto after_4;
    // 0x8080088C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_4:
    // 0x80800890: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800894:
    // 0x80800894: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    tooie_hud_element_end(rdram, ctx);
    // 0x80800898: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8080089C: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x808008A0: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x808008A4: jr          $ra
    // 0x808008A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x808008A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808008AC: nop

;}
RECOMP_FUNC void func_808049A8_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808049A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808049AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808049B0: jal         0x80100094
    // 0x808049B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808049B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808049B8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808049BC: jal         0x80089D48
    // 0x808049C0: lbu         $a0, 0x1A($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X1A);
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808049C0: lbu         $a0, 0x1A($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X1A);
    after_1:
    // 0x808049C4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x808049C8: sb          $v0, 0x1A($t6)
    MEM_B(0X1A, ctx->r14) = ctx->r2;
    // 0x808049CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808049D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808049D4: jr          $ra
    // 0x808049D8: nop

    return;
    // 0x808049D8: nop

;}
RECOMP_FUNC void func_8010518C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010518C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105190: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80105194: jal         0x80104544
    // 0x80105198: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80104544(rdram, ctx);
        goto after_0;
    // 0x80105198: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8010519C: bne         $v0, $zero, L_801051AC
    if (ctx->r2 != 0) {
        // 0x801051A0: nop
    
            goto L_801051AC;
    }
    // 0x801051A0: nop

    // 0x801051A4: b           L_801051B8
    // 0x801051A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801051B8;
    // 0x801051A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801051AC:
    // 0x801051AC: jal         0x801043D8
    // 0x801051B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_801043D8(rdram, ctx);
        goto after_1;
    // 0x801051B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801051B4: lw          $v0, 0x24($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X24);
L_801051B8:
    // 0x801051B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801051BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801051C0: jr          $ra
    // 0x801051C4: nop

    return;
    // 0x801051C4: nop

;}
RECOMP_FUNC void func_8010D930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010D930: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8010D934: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010D938: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010D93C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8010D940: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8010D944: jal         0x8010DA70
    // 0x8010D948: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8010DA70(rdram, ctx);
        goto after_0;
    // 0x8010D948: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8010D94C: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8010D950: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8010D954: bne         $t6, $zero, L_8010D96C
    if (ctx->r14 != 0) {
        // 0x8010D958: nop
    
            goto L_8010D96C;
    }
    // 0x8010D958: nop

    // 0x8010D95C: jal         0x800C2E04
    // 0x8010D960: nop

    func_800C2E04(rdram, ctx);
        goto after_1;
    // 0x8010D960: nop

    after_1:
    // 0x8010D964: b           L_8010D974
    // 0x8010D968: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
        goto L_8010D974;
    // 0x8010D968: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
L_8010D96C:
    // 0x8010D96C: jal         0x800C2E40
    // 0x8010D970: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    func_800C2E40(rdram, ctx);
        goto after_2;
    // 0x8010D970: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    after_2:
L_8010D974:
    // 0x8010D974: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8010D978: lui         $a2, 0x453B
    ctx->r6 = S32(0X453B << 16);
    // 0x8010D97C: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x8010D980: beq         $t7, $zero, L_8010D990
    if (ctx->r15 == 0) {
        // 0x8010D984: lui         $a1, 0x4348
        ctx->r5 = S32(0X4348 << 16);
            goto L_8010D990;
    }
    // 0x8010D984: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    // 0x8010D988: jal         0x800C3584
    // 0x8010D98C: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    func_800C3584(rdram, ctx);
        goto after_3;
    // 0x8010D98C: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    after_3:
L_8010D990:
    // 0x8010D990: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x8010D994: jal         0x800C330C
    // 0x8010D998: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800C330C(rdram, ctx);
        goto after_4;
    // 0x8010D998: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x8010D99C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8010D9A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8010D9A4: bltz        $v0, L_8010D9E4
    if (SIGNED(ctx->r2) < 0) {
        // 0x8010D9A8: nop
    
            goto L_8010D9E4;
    }
    // 0x8010D9A8: nop

    // 0x8010D9AC: beq         $v0, $zero, L_8010D9D4
    if (ctx->r2 == 0) {
        // 0x8010D9B0: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_8010D9D4;
    }
    // 0x8010D9B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8010D9B4: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x8010D9B8: jal         0x800C3418
    // 0x8010D9BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C3418(rdram, ctx);
        goto after_5;
    // 0x8010D9BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x8010D9C0: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x8010D9C4: jal         0x800C32C4
    // 0x8010D9C8: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_800C32C4(rdram, ctx);
        goto after_6;
    // 0x8010D9C8: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_6:
    // 0x8010D9CC: b           L_8010D9F0
    // 0x8010D9D0: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
        goto L_8010D9F0;
    // 0x8010D9D0: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
L_8010D9D4:
    // 0x8010D9D4: jal         0x800C3418
    // 0x8010D9D8: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    func_800C3418(rdram, ctx);
        goto after_7;
    // 0x8010D9D8: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    after_7:
    // 0x8010D9DC: b           L_8010D9F0
    // 0x8010D9E0: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
        goto L_8010D9F0;
    // 0x8010D9E0: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
L_8010D9E4:
    // 0x8010D9E4: jal         0x800C3418
    // 0x8010D9E8: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    func_800C3418(rdram, ctx);
        goto after_8;
    // 0x8010D9E8: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    after_8:
    // 0x8010D9EC: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
L_8010D9F0:
    // 0x8010D9F0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8010D9F4: jal         0x800C4350
    // 0x8010D9F8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_800C4350(rdram, ctx);
        goto after_9;
    // 0x8010D9F8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_9:
    // 0x8010D9FC: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x8010DA00: jal         0x800C3B8C
    // 0x8010DA04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C3B8C(rdram, ctx);
        goto after_10;
    // 0x8010DA04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x8010DA08: jal         0x800C3BDC
    // 0x8010DA0C: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    func_800C3BDC(rdram, ctx);
        goto after_11;
    // 0x8010DA0C: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    after_11:
    // 0x8010DA10: jal         0x8001211C
    // 0x8010DA14: nop

    func_8001211C(rdram, ctx);
        goto after_12;
    // 0x8010DA14: nop

    after_12:
    // 0x8010DA18: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x8010DA1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010DA20: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8010DA24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8010DA28: jr          $ra
    // 0x8010DA2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8010DA2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_8080012C_chfactoryworkerwear(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080012C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800130: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800134: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800138: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8080013C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800140: jal         0x80100094
    // 0x80800144: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800144: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800148: lhu         $v1, 0x72($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X72);
    // 0x8080014C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800150: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800154: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x80800158: beq         $t6, $at, L_8080024C
    if (ctx->r14 == ctx->r1) {
        // 0x8080015C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080024C;
    }
    // 0x8080015C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800160: beq         $t6, $at, L_80800184
    if (ctx->r14 == ctx->r1) {
        // 0x80800164: addiu       $a0, $s1, 0x4
        ctx->r4 = ADD32(ctx->r17, 0X4);
            goto L_80800184;
    }
    // 0x80800164: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    // 0x80800168: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080016C: beq         $t6, $at, L_808001B0
    if (ctx->r14 == ctx->r1) {
        // 0x80800170: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808001B0;
    }
    // 0x80800170: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800174: beq         $t6, $at, L_808001D0
    if (ctx->r14 == ctx->r1) {
        // 0x80800178: addiu       $a0, $s1, 0x4
        ctx->r4 = ADD32(ctx->r17, 0X4);
            goto L_808001D0;
    }
    // 0x80800178: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    // 0x8080017C: b           L_80800250
    // 0x80800180: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800250;
    // 0x80800180: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800184:
    // 0x80800184: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800188: addiu       $a2, $s0, 0x10
    ctx->r6 = ADD32(ctx->r16, 0X10);
    // 0x8080018C: jal         0x800EFE50
    // 0x80800190: lw          $a3, 0x1C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X1C);
    func_800EFE50(rdram, ctx);
        goto after_1;
    // 0x80800190: lw          $a3, 0x1C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X1C);
    after_1:
    // 0x80800194: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x80800198: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8080019C: lwc1        $f12, 0x1C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x808001A0: jal         0x800F1214
    // 0x808001A4: lwc1        $f14, 0x0($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X0);
    func_800F1214(rdram, ctx);
        goto after_2;
    // 0x808001A4: lwc1        $f14, 0x0($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X0);
    after_2:
    // 0x808001A8: b           L_8080024C
    // 0x808001AC: swc1        $f0, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f0.u32l;
        goto L_8080024C;
    // 0x808001AC: swc1        $f0, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f0.u32l;
L_808001B0:
    // 0x808001B0: jal         0x800D8FF8
    // 0x808001B4: nop

    func_800D8FF8(rdram, ctx);
        goto after_3;
    // 0x808001B4: nop

    after_3:
    // 0x808001B8: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x808001BC: lwc1        $f4, 0x4C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4C);
    // 0x808001C0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x808001C4: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x808001C8: b           L_8080024C
    // 0x808001CC: swc1        $f10, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->f10.u32l;
        goto L_8080024C;
    // 0x808001CC: swc1        $f10, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->f10.u32l;
L_808001D0:
    // 0x808001D0: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2172, 0X480) << 16);
    // 0x808001D4: addiu       $t7, $t7, 0x480
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2172, 0X480));
    // 0x808001D8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808001DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808001E0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808001E4: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x808001E8: jal         0x800BBCB8
    // 0x808001EC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800BBCB8(rdram, ctx);
        goto after_4;
    // 0x808001EC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_4:
    // 0x808001F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808001F4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808001F8: addiu       $a2, $s0, 0x10
    ctx->r6 = ADD32(ctx->r16, 0X10);
    // 0x808001FC: jal         0x800EFE50
    // 0x80800200: lw          $a3, 0x1C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X1C);
    func_800EFE50(rdram, ctx);
        goto after_5;
    // 0x80800200: lw          $a3, 0x1C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X1C);
    after_5:
    // 0x80800204: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800208: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080020C: lwc1        $f16, 0x1C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80800210: mul.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80800214: jal         0x80013970
    // 0x80800218: nop

    func_80013970(rdram, ctx);
        goto after_6;
    // 0x80800218: nop

    after_6:
    // 0x8080021C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800220: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800224: lwc1        $f6, 0x8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80800228: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x8080022C: mul.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800230: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800234: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80800238: swc1        $f10, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f10.u32l;
    // 0x8080023C: lwc1        $f14, 0x0($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800240: jal         0x800F1214
    // 0x80800244: lwc1        $f12, 0x1C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X1C);
    func_800F1214(rdram, ctx);
        goto after_7;
    // 0x80800244: lwc1        $f12, 0x1C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X1C);
    after_7:
    // 0x80800248: swc1        $f0, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f0.u32l;
L_8080024C:
    // 0x8080024C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800250:
    // 0x80800250: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800254: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800258: jr          $ra
    // 0x8080025C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8080025C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80800E98_bskaztorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E98: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800E9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800EA0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800EA4: jal         0x800878A0
    // 0x80800EA8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    _plsu_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800EA8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x80800EAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800EB0: jal         0x800F5A00
    // 0x80800EB4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800F5A00(rdram, ctx);
        goto after_1;
    // 0x80800EB4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x80800EB8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800EBC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800EC0: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800EC4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800EC8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80800ECC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800ED0: jal         0x80084E18
    // 0x80800ED4: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    _bamovegoto_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x80800ED4: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x80800ED8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800EDC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800EE0: jr          $ra
    // 0x80800EE4: nop

    return;
    // 0x80800EE4: nop

;}
RECOMP_FUNC void func_80801018_chwarppad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801018: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080101C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801020: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80801024: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80801028: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080102C: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x80801030: bgezl       $t8, L_8080105C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80801034: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080105C;
    }
    goto skip_0;
    // 0x80801034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801038: jal         0x800856B8
    // 0x8080103C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    _capod_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x8080103C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80801040: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801044: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801048: lbu         $t9, 0x65($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X65);
    // 0x8080104C: andi        $t0, $t9, 0xFFEF
    ctx->r8 = ctx->r25 & 0XFFEF;
    // 0x80801050: jal         0x8008A4B0
    // 0x80801054: sb          $t0, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r8;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80801054: sb          $t0, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r8;
    after_1:
    // 0x80801058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080105C:
    // 0x8080105C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801060: jr          $ra
    // 0x80801064: nop

    return;
    // 0x80801064: nop

;}
RECOMP_FUNC void _bsbanshack_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082718: syscall     8
    recomp_syscall_handler(rdram, ctx, 0x80082718);
    return;
    // 0x8008271C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800EFE50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EFE50: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x800EFE54: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800EFE58: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800EFE5C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x800EFE60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EFE64: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x800EFE68: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800EFE6C: lwc1        $f14, 0x0($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800EFE70: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800EFE74: sub.s       $f14, $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f18.fl;
    // 0x800EFE78: mul.s       $f16, $f14, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x800EFE7C: beql        $v0, $a0, L_800EFEB8
    if (ctx->r2 == ctx->r4) {
        // 0x800EFE80: add.s       $f14, $f16, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
            goto L_800EFEB8;
    }
    goto skip_0;
    // 0x800EFE80: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    skip_0:
    // 0x800EFE84: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
L_800EFE88:
    // 0x800EFE88: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800EFE8C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800EFE90: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800EFE94: swc1        $f14, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f14.u32l;
    // 0x800EFE98: lwc1        $f18, 0x4($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X4);
    // 0x800EFE9C: lwc1        $f14, 0x0($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800EFEA0: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x800EFEA4: sub.s       $f14, $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f18.fl;
    // 0x800EFEA8: mul.s       $f16, $f14, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x800EFEAC: bnel        $v0, $a0, L_800EFE88
    if (ctx->r2 != ctx->r4) {
        // 0x800EFEB0: add.s       $f14, $f16, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
            goto L_800EFE88;
    }
    goto skip_1;
    // 0x800EFEB0: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    skip_1:
    // 0x800EFEB4: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
L_800EFEB8:
    // 0x800EFEB8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800EFEBC: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800EFEC0: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x800EFEC4: swc1        $f14, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f14.u32l;
    // 0x800EFEC8: jr          $ra
    // 0x800EFECC: nop

    return;
    // 0x800EFECC: nop

;}
RECOMP_FUNC void _chlightdemon_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085D50: syscall     235
    recomp_syscall_handler(rdram, ctx, 0x80085D50);
    return;
    // 0x80085D54: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _gccubesearch_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800882B0: syscall     678
    recomp_syscall_handler(rdram, ctx, 0x800882B0);
    return;
    // 0x800882B4: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_800EFA4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EFA4C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800EFA50: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800EFA54: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800EFA58: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x800EFA5C: swc1        $f14, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f14.u32l;
    // 0x800EFA60: lwc1        $f4, 0xC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800EFA64: jr          $ra
    // 0x800EFA68: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x800EFA68: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_80800948_chdippy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800948: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080094C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800950: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800954: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80800958: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x8080095C: jal         0x8008A0E8
    // 0x80800960: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _subaddieskeleton_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800960: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_0:
    // 0x80800964: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1284, 0X1480) << 16);
    // 0x80800968: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x8080096C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800970: addiu       $a2, $a2, 0x1480
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1284, 0X1480));
    // 0x80800974: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800978: jal         0x80089D20
    // 0x8080097C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x8080097C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x80800980: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800984: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800988: jr          $ra
    // 0x8080098C: nop

    return;
    // 0x8080098C: nop

;}
RECOMP_FUNC void _fxdialog_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088B40: syscall     725
    recomp_syscall_handler(rdram, ctx, 0x80088B40);
    return;
    // 0x80088B44: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80801A30_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801A34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801A38: jal         0x808002D4
    // 0x80801A3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808002D4_bsbansack(rdram, ctx);
        goto after_0;
    // 0x80801A3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801A40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801A44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801A48: sb          $zero, 0x15D($a0)
    MEM_B(0X15D, ctx->r4) = 0;
    // 0x80801A4C: jal         0x80801680
    // 0x80801A50: sb          $zero, 0x15C($a0)
    MEM_B(0X15C, ctx->r4) = 0;
    func_80801680_bsbansack(rdram, ctx);
        goto after_1;
    // 0x80801A50: sb          $zero, 0x15C($a0)
    MEM_B(0X15C, ctx->r4) = 0;
    after_1:
    // 0x80801A54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801A58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801A5C: jr          $ra
    // 0x80801A60: nop

    return;
    // 0x80801A60: nop

;}
RECOMP_FUNC void bsstonehead_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808009E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808009F0: jal         0x808008CC
    // 0x808009F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808008CC_bsstonehead(rdram, ctx);
        goto after_0;
    // 0x808009F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808009F8: jal         0x80800000
    // 0x808009FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800000_bsstonehead(rdram, ctx);
        goto after_1;
    // 0x808009FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800A00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A08: jr          $ra
    // 0x80800A0C: nop

    return;
    // 0x80800A0C: nop

;}
