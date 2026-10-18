#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _sucoasterdata_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A238: syscall     831
    recomp_syscall_handler(rdram, ctx, 0x8008A238);
    return;
    // 0x8008A23C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808003B4_chphlegm(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003B4: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x808003B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808003C0: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x808003C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808003C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003CC: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808003D0: beq         $t6, $at, L_808003E8
    if (ctx->r14 == ctx->r1) {
        // 0x808003D4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808003E8;
    }
    // 0x808003D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808003D8: beq         $t6, $at, L_80800414
    if (ctx->r14 == ctx->r1) {
        // 0x808003DC: nop
    
            goto L_80800414;
    }
    // 0x808003DC: nop

    // 0x808003E0: b           L_808005D4
    // 0x808003E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808005D4;
    // 0x808003E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808003E8:
    // 0x808003E8: jal         0x80101DDC
    // 0x808003EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_0;
    // 0x808003EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x808003F0: beql        $v0, $zero, L_808005D4
    if (ctx->r2 == 0) {
        // 0x808003F4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808005D4;
    }
    goto skip_0;
    // 0x808003F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808003F8: jal         0x8010A590
    // 0x808003FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_1;
    // 0x808003FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800404: jal         0x80102424
    // 0x80800408: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x80800408: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x8080040C: b           L_808005D4
    // 0x80800410: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808005D4;
    // 0x80800410: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800414:
    // 0x80800414: jal         0x8010D248
    // 0x80800418: nop

    func_8010D248(rdram, ctx);
        goto after_3;
    // 0x80800418: nop

    after_3:
    // 0x8080041C: beql        $v0, $zero, L_808005D4
    if (ctx->r2 == 0) {
        // 0x80800420: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808005D4;
    }
    goto skip_1;
    // 0x80800420: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800424: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080042C: addiu       $a1, $s0, 0x54
    ctx->r5 = ADD32(ctx->r16, 0X54);
    // 0x80800430: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80800434: bgez        $t9, L_8080044C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800438: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8080044C;
    }
    // 0x80800438: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080043C: jal         0x80089BF0
    // 0x80800440: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    _subaddiejoy_entrypoint_9(rdram, ctx);
        goto after_4;
    // 0x80800440: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_4:
    // 0x80800444: b           L_80800460
    // 0x80800448: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
        goto L_80800460;
    // 0x80800448: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
L_8080044C:
    // 0x8080044C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800454: jal         0x8010CD28
    // 0x80800458: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    func_8010CD28(rdram, ctx);
        goto after_5;
    // 0x80800458: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x8080045C: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
L_80800460:
    // 0x80800460: lui         $a1, 0x3E19
    ctx->r5 = S32(0X3E19 << 16);
    // 0x80800464: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080046C: lui         $a2, 0x42F0
    ctx->r6 = S32(0X42F0 << 16);
    // 0x80800470: jal         0x80102BF8
    // 0x80800474: lui         $a3, 0x43B4
    ctx->r7 = S32(0X43B4 << 16);
    func_80102BF8(rdram, ctx);
        goto after_6;
    // 0x80800474: lui         $a3, 0x43B4
    ctx->r7 = S32(0X43B4 << 16);
    after_6:
    // 0x80800478: jal         0x800DA298
    // 0x8080047C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x8080047C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x80800480: beql        $v0, $zero, L_808005D4
    if (ctx->r2 == 0) {
        // 0x80800484: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808005D4;
    }
    goto skip_2;
    // 0x80800484: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80800488: jal         0x800D90A4
    // 0x8080048C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_8;
    // 0x8080048C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_8:
    // 0x80800490: beq         $v0, $zero, L_808005D0
    if (ctx->r2 == 0) {
        // 0x80800494: addiu       $a0, $zero, 0x399
        ctx->r4 = ADD32(0, 0X399);
            goto L_808005D0;
    }
    // 0x80800494: addiu       $a0, $zero, 0x399
    ctx->r4 = ADD32(0, 0X399);
    // 0x80800498: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x8080049C: jal         0x80089C40
    // 0x808004A0: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    _subaddiefind_entrypoint_4(rdram, ctx);
        goto after_9;
    // 0x808004A0: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_9:
    // 0x808004A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808004A8: blez        $v0, L_808004E4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808004AC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_808004E4;
    }
    // 0x808004AC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808004B0: addiu       $v0, $sp, 0x48
    ctx->r2 = ADD32(ctx->r29, 0X48);
    // 0x808004B4: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x808004B8: addu        $a1, $t1, $v0
    ctx->r5 = ADD32(ctx->r9, ctx->r2);
    // 0x808004BC: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
L_808004C0:
    // 0x808004C0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808004C4: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x808004C8: lw          $t3, 0x64($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X64);
    // 0x808004CC: sll         $t5, $t3, 1
    ctx->r13 = S32(ctx->r11 << 1);
    // 0x808004D0: bltz        $t5, L_808004DC
    if (SIGNED(ctx->r13) < 0) {
        // 0x808004D4: nop
    
            goto L_808004DC;
    }
    // 0x808004D4: nop

    // 0x808004D8: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
L_808004DC:
    // 0x808004DC: bnel        $at, $zero, L_808004C0
    if (ctx->r1 != 0) {
        // 0x808004E0: lw          $t2, 0x0($v0)
        ctx->r10 = MEM_W(ctx->r2, 0X0);
            goto L_808004C0;
    }
    goto skip_3;
    // 0x808004E0: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    skip_3:
L_808004E4:
    // 0x808004E4: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x808004E8: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x808004EC: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x808004F0: bltz        $t8, L_80800510
    if (SIGNED(ctx->r24) < 0) {
        // 0x808004F4: nop
    
            goto L_80800510;
    }
    // 0x808004F4: nop

    // 0x808004F8: bne         $at, $zero, L_80800510
    if (ctx->r1 != 0) {
        // 0x808004FC: nop
    
            goto L_80800510;
    }
    // 0x808004FC: nop

    // 0x80800500: jal         0x80089F00
    // 0x80800504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suchase_entrypoint_1(rdram, ctx);
        goto after_10;
    // 0x80800504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800508: beql        $v0, $zero, L_808005D4
    if (ctx->r2 == 0) {
        // 0x8080050C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808005D4;
    }
    goto skip_4;
    // 0x8080050C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
L_80800510:
    // 0x80800510: jal         0x800D8FF8
    // 0x80800514: nop

    func_800D8FF8(rdram, ctx);
        goto after_11;
    // 0x80800514: nop

    after_11:
    // 0x80800518: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8080051C: jal         0x80101F24
    // 0x80800520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_12;
    // 0x80800520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800524: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1064, 0XC30) << 16);
    // 0x80800528: addiu       $a1, $a1, 0xC30
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1064, 0XC30));
    // 0x8080052C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800530: jal         0x800F3780
    // 0x80800534: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800F3780(rdram, ctx);
        goto after_13;
    // 0x80800534: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_13:
    // 0x80800538: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8080053C: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800540: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800544: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800548: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8080054C: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80800550: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    // 0x80800554: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80800558: nop

    // 0x8080055C: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80800560: jal         0x800EE7F8
    // 0x80800564: swc1        $f4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f4.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_14;
    // 0x80800564: swc1        $f4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f4.u32l;
    after_14:
    // 0x80800568: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    // 0x8080056C: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80800570: jal         0x800EF1B8
    // 0x80800574: lw          $a2, 0x70($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X70);
    func_800EF1B8(rdram, ctx);
        goto after_15;
    // 0x80800574: lw          $a2, 0x70($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X70);
    after_15:
    // 0x80800578: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8080057C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800580: lwc1        $f6, 0x84($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80800584: addiu       $a0, $sp, 0x8C
    ctx->r4 = ADD32(ctx->r29, 0X8C);
    // 0x80800588: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    // 0x8080058C: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80800590: jal         0x800EE7F8
    // 0x80800594: swc1        $f16, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f16.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_16;
    // 0x80800594: swc1        $f16, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f16.u32l;
    after_16:
    // 0x80800598: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8080059C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808005A0: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808005A4: addiu       $a0, $sp, 0x8C
    ctx->r4 = ADD32(ctx->r29, 0X8C);
    // 0x808005A8: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    // 0x808005AC: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x808005B0: addiu       $a2, $sp, 0x74
    ctx->r6 = ADD32(ctx->r29, 0X74);
    // 0x808005B4: swc1        $f4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f4.u32l;
    // 0x808005B8: jal         0x800C6A7C
    // 0x808005BC: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    func_800C6A7C(rdram, ctx);
        goto after_17;
    // 0x808005BC: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    after_17:
    // 0x808005C0: beq         $v0, $zero, L_808005D0
    if (ctx->r2 == 0) {
        // 0x808005C4: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_808005D0;
    }
    // 0x808005C4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808005C8: jal         0x800EE7F8
    // 0x808005CC: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    func_800EE7F8(rdram, ctx);
        goto after_18;
    // 0x808005CC: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    after_18:
L_808005D0:
    // 0x808005D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808005D4:
    // 0x808005D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808005D8: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    // 0x808005DC: jr          $ra
    // 0x808005E0: nop

    return;
    // 0x808005E0: nop

;}
RECOMP_FUNC void func_808052A4_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808052A4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808052A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808052AC: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x808052B0: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x808052B4: div.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808052B8: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x808052BC: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x808052C0: jr          $ra
    // 0x808052C4: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    return;
    // 0x808052C4: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
;}
RECOMP_FUNC void chtrashcompactor_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1128, 0X9A8) << 16);
    // 0x80800028: jr          $ra
    // 0x8080002C: addiu       $v0, $v0, 0x9A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1128, 0X9A8));
    return;
    // 0x8080002C: addiu       $v0, $v0, 0x9A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1128, 0X9A8));
;}
RECOMP_FUNC void func_800F0D90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0D90: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800F0D94: beql        $at, $zero, L_800F0DA8
    if (ctx->r1 == 0) {
        // 0x800F0D98: slt         $at, $a2, $a0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_800F0DA8;
    }
    goto skip_0;
    // 0x800F0D98: slt         $at, $a2, $a0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    skip_0:
    // 0x800F0D9C: jr          $ra
    // 0x800F0DA0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x800F0DA0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800F0DA4: slt         $at, $a2, $a0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
L_800F0DA8:
    // 0x800F0DA8: beq         $at, $zero, L_800F0DB8
    if (ctx->r1 == 0) {
        // 0x800F0DAC: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_800F0DB8;
    }
    // 0x800F0DAC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800F0DB0: jr          $ra
    // 0x800F0DB4: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    return;
    // 0x800F0DB4: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_800F0DB8:
    // 0x800F0DB8: jr          $ra
    // 0x800F0DBC: nop

    return;
    // 0x800F0DBC: nop

;}
RECOMP_FUNC void func_80801314_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801314: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801318: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080131C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801320: jal         0x800845C8
    // 0x80801324: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _babounce_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80801324: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80801328: beq         $v0, $zero, L_80801338
    if (ctx->r2 == 0) {
        // 0x8080132C: nop
    
            goto L_80801338;
    }
    // 0x8080132C: nop

    // 0x80801330: jal         0x80800000
    // 0x80801334: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800000_bswasher(rdram, ctx);
        goto after_1;
    // 0x80801334: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
L_80801338:
    // 0x80801338: jal         0x80084600
    // 0x8080133C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _babounce_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x8080133C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80801340: beq         $v0, $zero, L_8080134C
    if (ctx->r2 == 0) {
        // 0x80801344: addiu       $t6, $zero, 0x32
        ctx->r14 = ADD32(0, 0X32);
            goto L_8080134C;
    }
    // 0x80801344: addiu       $t6, $zero, 0x32
    ctx->r14 = ADD32(0, 0X32);
    // 0x80801348: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_8080134C:
    // 0x8080134C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801350: jal         0x8009E5C8
    // 0x80801354: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_3;
    // 0x80801354: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80801358: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080135C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801360: jr          $ra
    // 0x80801364: nop

    return;
    // 0x80801364: nop

;}
RECOMP_FUNC void func_80803B54_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803B54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80803B58: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80803B5C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80803B60: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x80803B64: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80803B68: addiu       $t7, $zero, 0x4D
    ctx->r15 = ADD32(0, 0X4D);
    // 0x80803B6C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80803B70: jal         0x8008A208
    // 0x80803B74: addiu       $a3, $t6, 0x4
    ctx->r7 = ADD32(ctx->r14, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x80803B74: addiu       $a3, $t6, 0x4
    ctx->r7 = ADD32(ctx->r14, 0X4);
    after_0:
    // 0x80803B78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80803B7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80803B80: jr          $ra
    // 0x80803B84: nop

    return;
    // 0x80803B84: nop

;}
RECOMP_FUNC void cadbfunc_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808009A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009A8: jal         0x80800960
    // 0x808009AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800960_cadbfunc(rdram, ctx);
        goto after_0;
    // 0x808009AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808009B0: bne         $v0, $zero, L_808009C0
    if (ctx->r2 != 0) {
        // 0x808009B4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_808009C0;
    }
    // 0x808009B4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808009B8: b           L_808009D0
    // 0x808009BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808009D0;
    // 0x808009BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808009C0:
    // 0x808009C0: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x808009C4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808009C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808009CC: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
L_808009D0:
    // 0x808009D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808009D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808009D8: jr          $ra
    // 0x808009DC: nop

    return;
    // 0x808009DC: nop

;}
RECOMP_FUNC void func_80800830_chbouncycastle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800830: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800834: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800838: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080083C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800840: bne         $a1, $at, L_808008D8
    if (ctx->r5 != ctx->r1) {
        // 0x80800844: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_808008D8;
    }
    // 0x80800844: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800848: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8080084C: addiu       $a0, $zero, 0x3C7
    ctx->r4 = ADD32(0, 0X3C7);
    // 0x80800850: addiu       $v1, $zero, 0xB
    ctx->r3 = ADD32(0, 0XB);
    // 0x80800854: lw          $v0, 0x6C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X6C);
    // 0x80800858: sll         $t7, $v0, 11
    ctx->r15 = S32(ctx->r2 << 11);
    // 0x8080085C: srl         $v0, $t7, 20
    ctx->r2 = S32(U32(ctx->r15) >> 20);
    // 0x80800860: bne         $a0, $v0, L_80800870
    if (ctx->r4 != ctx->r2) {
        // 0x80800864: nop
    
            goto L_80800870;
    }
    // 0x80800864: nop

    // 0x80800868: b           L_80800870
    // 0x8080086C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80800870;
    // 0x8080086C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80800870:
    // 0x80800870: bnel        $a0, $v0, L_80800884
    if (ctx->r4 != ctx->r2) {
        // 0x80800874: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80800884;
    }
    goto skip_0;
    // 0x80800874: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    skip_0:
    // 0x80800878: b           L_80800884
    // 0x8080087C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
        goto L_80800884;
    // 0x8080087C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800880: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80800884:
    // 0x80800884: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80800888: jal         0x8010D278
    // 0x8080088C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8010D278(rdram, ctx);
        goto after_0;
    // 0x8080088C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800890: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800894: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800898: bne         $v0, $v1, L_808008C8
    if (ctx->r2 != ctx->r3) {
        // 0x8080089C: nop
    
            goto L_808008C8;
    }
    // 0x8080089C: nop

    // 0x808008A0: jal         0x800BF744
    // 0x808008A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800BF744(rdram, ctx);
        goto after_1;
    // 0x808008A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808008A8: jal         0x8010A624
    // 0x808008AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8010A624(rdram, ctx);
        goto after_2;
    // 0x808008AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808008B0: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x808008B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808008B8: lbu         $t0, 0x65($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X65);
    // 0x808008BC: andi        $t1, $t0, 0xFFFE
    ctx->r9 = ctx->r8 & 0XFFFE;
    // 0x808008C0: b           L_808008DC
    // 0x808008C4: sb          $t1, 0x65($t9)
    MEM_B(0X65, ctx->r25) = ctx->r9;
        goto L_808008DC;
    // 0x808008C4: sb          $t1, 0x65($t9)
    MEM_B(0X65, ctx->r25) = ctx->r9;
L_808008C8:
    // 0x808008C8: jal         0x800BF744
    // 0x808008CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BF744(rdram, ctx);
        goto after_3;
    // 0x808008CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808008D0: b           L_808008DC
    // 0x808008D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808008DC;
    // 0x808008D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808008D8:
    // 0x808008D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808008DC:
    // 0x808008DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808008E4: jr          $ra
    // 0x808008E8: nop

    return;
    // 0x808008E8: nop

    // 0x808008EC: nop

;}
RECOMP_FUNC void _scinfobar_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A5A0: syscall     845
    recomp_syscall_handler(rdram, ctx, 0x8008A5A0);
    return;
    // 0x8008A5A4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_808003D8_chgruntyfireball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003D8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808003DC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808003E0: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1488, 0X588) << 16);
    // 0x808003E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808003E8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x808003EC: addiu       $t6, $t6, 0x588
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1488, 0X588));
    // 0x808003F0: addiu       $s0, $a0, 0x4
    ctx->r16 = ADD32(ctx->r4, 0X4);
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808003FC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800400: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800404: jal         0x800BBCB8
    // 0x80800408: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x80800408: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x8080040C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80800410: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800414: jal         0x800EE7F8
    // 0x80800418: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800418: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    after_1:
    // 0x8080041C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800420: jal         0x800EF368
    // 0x80800424: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    func_800EF368(rdram, ctx);
        goto after_2;
    // 0x80800424: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    after_2:
    // 0x80800428: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8080042C: jal         0x800EF334
    // 0x80800430: lui         $a1, 0xBF80
    ctx->r5 = S32(0XBF80 << 16);
    func_800EF334(rdram, ctx);
        goto after_3;
    // 0x80800430: lui         $a1, 0xBF80
    ctx->r5 = S32(0XBF80 << 16);
    after_3:
    // 0x80800434: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800438: jal         0x800EF04C
    // 0x8080043C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EF04C(rdram, ctx);
        goto after_4;
    // 0x8080043C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x80800440: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1488, 0X554) << 16);
    // 0x80800444: addiu       $t7, $t7, 0x554
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1488, 0X554));
    // 0x80800448: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x8080044C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800450: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800454: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800458: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080045C: jal         0x800BBCB8
    // 0x80800460: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_5;
    // 0x80800460: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x80800464: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800468: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080046C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800470: jr          $ra
    // 0x80800474: nop

    return;
    // 0x80800474: nop

    // 0x80800478: nop

    // 0x8080047C: nop

;}
RECOMP_FUNC void func_80103014(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103014: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103018: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8010301C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80103020: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x80103024: addiu       $a2, $a3, 0x44
    ctx->r6 = ADD32(ctx->r7, 0X44);
    // 0x80103028: jal         0x800EC124
    // 0x8010302C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EC124(rdram, ctx);
        goto after_0;
    // 0x8010302C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80103030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80103034: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80103038: jr          $ra
    // 0x8010303C: nop

    return;
    // 0x8010303C: nop

;}
RECOMP_FUNC void func_8002A940(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A940: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8002A944: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8002A948: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8002A94C: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8002A950: lw          $t6, 0x11F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11F4);
    // 0x8002A954: lw          $t7, 0x30($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X30);
    // 0x8002A958: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8002A95C: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8002A960: lui         $t0, 0x8002
    ctx->r8 = S32(0X8002 << 16);
    // 0x8002A964: addiu       $t0, $t0, 0x72B0
    ctx->r8 = ADD32(ctx->r8, 0X72B0);
    // 0x8002A968: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8002A96C: bne         $t9, $t0, L_8002A9A0
    if (ctx->r25 != ctx->r8) {
        // 0x8002A970: nop
    
            goto L_8002A9A0;
    }
    // 0x8002A970: nop

    // 0x8002A974: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x8002A978: lw          $t1, 0x11F4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X11F4);
    // 0x8002A97C: sll         $t3, $a0, 3
    ctx->r11 = S32(ctx->r4 << 3);
    // 0x8002A980: addu        $t3, $t3, $a0
    ctx->r11 = ADD32(ctx->r11, ctx->r4);
    // 0x8002A984: lw          $t2, 0x34($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X34);
    // 0x8002A988: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8002A98C: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8002A990: b           L_8002A9B0
    // 0x8002A994: lw          $v0, 0x20($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X20);
        goto L_8002A9B0;
    // 0x8002A994: lw          $v0, 0x20($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X20);
    // 0x8002A998: b           L_8002A9A8
    // 0x8002A99C: nop

        goto L_8002A9A8;
    // 0x8002A99C: nop

L_8002A9A0:
    // 0x8002A9A0: b           L_8002A9B0
    // 0x8002A9A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8002A9B0;
    // 0x8002A9A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002A9A8:
    // 0x8002A9A8: b           L_8002A9B0
    // 0x8002A9AC: nop

        goto L_8002A9B0;
    // 0x8002A9AC: nop

L_8002A9B0:
    // 0x8002A9B0: jr          $ra
    // 0x8002A9B4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8002A9B4: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void _chstarspinnerctrl_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085E20: syscall     245
    recomp_syscall_handler(rdram, ctx, 0x80085E20);
    return;
    // 0x80085E24: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _bsbwhirl_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082E30: syscall     30
    recomp_syscall_handler(rdram, ctx, 0x80082E30);
    return;
    // 0x80082E34: addi        $t0, $zero, 0x58
    ctx->r8 = ADD32(0, 0X58);
;}
RECOMP_FUNC void func_80026188(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026188: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002618C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80026190: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80026194: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80026198: addiu       $t6, $zero, 0xFC
    ctx->r14 = ADD32(0, 0XFC);
    // 0x8002619C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800261A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800261A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800261A8: addiu       $a2, $zero, 0xB0
    ctx->r6 = ADD32(0, 0XB0);
    // 0x800261AC: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x800261B0: jal         0x8002ACE0
    // 0x800261B4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8002ACE0(rdram, ctx);
        goto after_0;
    // 0x800261B4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_0:
    // 0x800261B8: b           L_800261C0
    // 0x800261BC: nop

        goto L_800261C0;
    // 0x800261BC: nop

L_800261C0:
    // 0x800261C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800261C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800261C8: jr          $ra
    // 0x800261CC: nop

    return;
    // 0x800261CC: nop

;}
RECOMP_FUNC void func_808021C8_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808021C8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808021CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808021D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808021D4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x808021D8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808021DC: jal         0x80088368
    // 0x808021E0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x808021E0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x808021E4: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808021E8: beql        $at, $zero, L_80802240
    if (ctx->r1 == 0) {
        // 0x808021EC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802240;
    }
    goto skip_0;
    // 0x808021EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808021F0: jal         0x800F6438
    // 0x808021F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6438(rdram, ctx);
        goto after_1;
    // 0x808021F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808021F8: beq         $v0, $zero, L_8080223C
    if (ctx->r2 == 0) {
        // 0x808021FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080223C;
    }
    // 0x808021FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802200: jal         0x800F8294
    // 0x80802204: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    func_800F8294(rdram, ctx);
        goto after_2;
    // 0x80802204: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x80802208: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8080220C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80802210: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80802214: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80802218: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8080221C: jal         0x800EFA4C
    // 0x80802220: lw          $a2, 0x48($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X48);
    func_800EFA4C(rdram, ctx);
        goto after_3;
    // 0x80802220: lw          $a2, 0x48($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X48);
    after_3:
    // 0x80802224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802228: jal         0x800F832C
    // 0x8080222C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800F832C(rdram, ctx);
        goto after_4;
    // 0x8080222C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x80802230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802234: jal         0x800F4CEC
    // 0x80802238: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F4CEC(rdram, ctx);
        goto after_5;
    // 0x80802238: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
L_8080223C:
    // 0x8080223C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802240:
    // 0x80802240: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802244: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80802248: jr          $ra
    // 0x8080224C: nop

    return;
    // 0x8080224C: nop

;}
RECOMP_FUNC void func_80800000_bskazwingwhack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800004: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8080000C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800010: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80800014: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80800018: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8080001C: jal         0x800B5BE4
    // 0x80800020: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800B5BE4(rdram, ctx);
        goto after_0;
    // 0x80800020: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x80800024: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800028: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8080002C: jal         0x8009C128
    // 0x80800030: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_8009C128(rdram, ctx);
        goto after_1;
    // 0x80800030: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_1:
    // 0x80800034: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800038: jal         0x800F1DF4
    // 0x8080003C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_800F1DF4(rdram, ctx);
        goto after_2;
    // 0x8080003C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_2:
    // 0x80800040: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800044: jal         0x800136E4
    // 0x80800048: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    func_800136E4(rdram, ctx);
        goto after_3;
    // 0x80800048: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    after_3:
    // 0x8080004C: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80800050: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800058: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080005C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800060: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80800064: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80800068: sll         $t7, $a2, 16
    ctx->r15 = S32(ctx->r6 << 16);
    // 0x8080006C: sra         $a2, $t7, 16
    ctx->r6 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80800070: sll         $t0, $a3, 16
    ctx->r8 = S32(ctx->r7 << 16);
    // 0x80800074: jal         0x800BA77C
    // 0x80800078: sra         $a3, $t0, 16
    ctx->r7 = S32(SIGNED(ctx->r8) >> 16);
    func_800BA77C(rdram, ctx);
        goto after_4;
    // 0x80800078: sra         $a3, $t0, 16
    ctx->r7 = S32(SIGNED(ctx->r8) >> 16);
    after_4:
    // 0x8080007C: jal         0x8009EA2C
    // 0x80800080: nop

    func_8009EA2C(rdram, ctx);
        goto after_5;
    // 0x80800080: nop

    after_5:
    // 0x80800084: beq         $v0, $zero, L_808000A0
    if (ctx->r2 == 0) {
        // 0x80800088: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000A0;
    }
    // 0x80800088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080008C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800090: jal         0x800BA670
    // 0x80800094: addiu       $a1, $zero, 0x619
    ctx->r5 = ADD32(0, 0X619);
    func_800BA670(rdram, ctx);
        goto after_6;
    // 0x80800094: addiu       $a1, $zero, 0x619
    ctx->r5 = ADD32(0, 0X619);
    after_6:
    // 0x80800098: b           L_808000A8
    // 0x8080009C: nop

        goto L_808000A8;
    // 0x8080009C: nop

L_808000A0:
    // 0x808000A0: jal         0x800BA670
    // 0x808000A4: addiu       $a1, $zero, 0x618
    ctx->r5 = ADD32(0, 0X618);
    func_800BA670(rdram, ctx);
        goto after_7;
    // 0x808000A4: addiu       $a1, $zero, 0x618
    ctx->r5 = ADD32(0, 0X618);
    after_7:
L_808000A8:
    // 0x808000A8: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(300, 0XA80) << 16);
    // 0x808000AC: addiu       $t2, $t2, 0xA80
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(300, 0XA80));
    // 0x808000B0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x808000BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808000C0: jal         0x800BABB8
    // 0x808000C4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_8;
    // 0x808000C4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_8:
    // 0x808000C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808000CC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808000D0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808000D4: jr          $ra
    // 0x808000D8: nop

    return;
    // 0x808000D8: nop

;}
RECOMP_FUNC void _chfactorytrashbelt_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087590: syscall     590
    recomp_syscall_handler(rdram, ctx, 0x80087590);
    return;
    // 0x80087594: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _subaddiedialog_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A1B8: syscall     830
    recomp_syscall_handler(rdram, ctx, 0x8008A1B8);
    return;
    // 0x8008A1BC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80801BB0_chfactoryrobot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801BB0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801BB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801BB8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801BBC: jal         0x80100094
    // 0x80801BC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801BC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801BC4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80801BC8: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80801BCC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801BD0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801BD4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80801BD8: nop

    // 0x80801BDC: bc1fl       L_80801BF0
    if (!c1cs) {
        // 0x80801BE0: lw          $t6, 0x64($a0)
        ctx->r14 = MEM_W(ctx->r4, 0X64);
            goto L_80801BF0;
    }
    goto skip_0;
    // 0x80801BE0: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    skip_0:
    // 0x80801BE4: b           L_80801C40
    // 0x80801BE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801C40;
    // 0x80801BE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80801BEC: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
L_80801BF0:
    // 0x80801BF0: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80801BF4: bgezl       $t8, L_80801C40
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80801BF8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80801C40;
    }
    goto skip_1;
    // 0x80801BF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80801BFC: jal         0x80089BD8
    // 0x80801C00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddiejoy_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80801C00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80801C04: beq         $v0, $zero, L_80801C3C
    if (ctx->r2 == 0) {
        // 0x80801C08: lw          $t9, 0x1C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X1C);
            goto L_80801C3C;
    }
    // 0x80801C08: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80801C0C: lw          $a0, 0x14($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X14);
    // 0x80801C10: jal         0x800C8FE0
    // 0x80801C14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C8FE0(rdram, ctx);
        goto after_2;
    // 0x80801C14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80801C18: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1140, 0X27D4) << 16);
    // 0x80801C1C: lwc1        $f12, 0x27D4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1140, 0X27D4));
    // 0x80801C20: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1140, 0X27D8) << 16);
    // 0x80801C24: jal         0x800DC178
    // 0x80801C28: lwc1        $f14, 0x27D8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1140, 0X27D8));
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x80801C28: lwc1        $f14, 0x27D8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1140, 0X27D8));
    after_3:
    // 0x80801C2C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80801C30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80801C34: b           L_80801C40
    // 0x80801C38: swc1        $f0, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f0.u32l;
        goto L_80801C40;
    // 0x80801C38: swc1        $f0, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f0.u32l;
L_80801C3C:
    // 0x80801C3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801C40:
    // 0x80801C40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801C44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801C48: jr          $ra
    // 0x80801C4C: nop

    return;
    // 0x80801C4C: nop

;}
RECOMP_FUNC void func_800958A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800958A4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800958A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800958AC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800958B0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800958B4: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800958B8: jal         0x8009C128
    // 0x800958BC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x800958BC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x800958C0: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800958C4: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800958C8: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800958CC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800958D0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800958D4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800958D8: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x800958DC: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x800958E0: lw          $t7, 0x94($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X94);
    // 0x800958E4: jal         0x800C6C94
    // 0x800958E8: lw          $a3, 0x14($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X14);
    func_800C6C94(rdram, ctx);
        goto after_1;
    // 0x800958E8: lw          $a3, 0x14($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X14);
    after_1:
    // 0x800958EC: beq         $v0, $zero, L_800958FC
    if (ctx->r2 == 0) {
        // 0x800958F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800958FC;
    }
    // 0x800958F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800958F4: b           L_80095900
    // 0x800958F8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80095900;
    // 0x800958F8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800958FC:
    // 0x800958FC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80095900:
    // 0x80095900: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80095904: jr          $ra
    // 0x80095908: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80095908: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_808009CC_chlakemonster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808009D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009D4: jal         0x800F54E4
    // 0x808009D8: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x808009D8: nop

    after_0:
    // 0x808009DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808009E0: addiu       $a1, $zero, 0x95
    ctx->r5 = ADD32(0, 0X95);
    // 0x808009E4: addiu       $a2, $zero, 0x116
    ctx->r6 = ADD32(0, 0X116);
    // 0x808009E8: jal         0x800F7C9C
    // 0x808009EC: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    func_800F7C9C(rdram, ctx);
        goto after_1;
    // 0x808009EC: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_1:
    // 0x808009F0: addiu       $a0, $zero, 0x123
    ctx->r4 = ADD32(0, 0X123);
    // 0x808009F4: jal         0x80087A58
    // 0x808009F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x808009F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x808009FC: jal         0x800DA544
    // 0x80800A00: addiu       $a0, $zero, 0x6E8
    ctx->r4 = ADD32(0, 0X6E8);
    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x80800A00: addiu       $a0, $zero, 0x6E8
    ctx->r4 = ADD32(0, 0X6E8);
    after_3:
    // 0x80800A04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A0C: jr          $ra
    // 0x80800A10: nop

    return;
    // 0x80800A10: nop

;}
RECOMP_FUNC void gldbstring_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: jal         0x800D674C
    // 0x80800010: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800D674C(rdram, ctx);
        goto after_0;
    // 0x80800010: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800014: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80800018: jal         0x800D70D0
    // 0x8080001C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800D70D0(rdram, ctx);
        goto after_1;
    // 0x8080001C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80800020: jal         0x800D71F4
    // 0x80800024: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800D71F4(rdram, ctx);
        goto after_2;
    // 0x80800024: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80800028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080002C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80800030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800034: jr          $ra
    // 0x80800038: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    return;
    // 0x80800038: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
;}
RECOMP_FUNC void func_80800018_chmrsicecube(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080001C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800020: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800024: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800028: jal         0x80100094
    // 0x8080002C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080002C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800030: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800038: jal         0x8010A800
    // 0x8080003C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8010A800(rdram, ctx);
        goto after_1;
    // 0x8080003C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800040: jal         0x8008A020
    // 0x80800044: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    _subaddielink_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80800044: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80800048: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
    // 0x8080004C: srl         $t6, $v0, 7
    ctx->r14 = S32(U32(ctx->r2) >> 7);
    // 0x80800050: addiu       $v0, $t6, -0x32
    ctx->r2 = ADD32(ctx->r14, -0X32);
    // 0x80800054: bne         $v0, $zero, L_808000A8
    if (ctx->r2 != 0) {
        // 0x80800058: sw          $v0, 0x28($s0)
        MEM_W(0X28, ctx->r16) = ctx->r2;
            goto L_808000A8;
    }
    // 0x80800058: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    // 0x8080005C: jal         0x800DA298
    // 0x80800060: addiu       $a0, $zero, 0x1C5
    ctx->r4 = ADD32(0, 0X1C5);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80800060: addiu       $a0, $zero, 0x1C5
    ctx->r4 = ADD32(0, 0X1C5);
    after_3:
    // 0x80800064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800068: jal         0x8010A5B0
    // 0x8080006C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8010A5B0(rdram, ctx);
        goto after_4;
    // 0x8080006C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80800070: jal         0x80088848
    // 0x80800074: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_5;
    // 0x80800074: nop

    after_5:
    // 0x80800078: beq         $v0, $zero, L_80800090
    if (ctx->r2 == 0) {
        // 0x8080007C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800090;
    }
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800080: jal         0x80102424
    // 0x80800084: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x80800084: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_6:
    // 0x80800088: b           L_808000AC
    // 0x8080008C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000AC;
    // 0x8080008C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800090:
    // 0x80800090: jal         0x800DA298
    // 0x80800094: addiu       $a0, $zero, 0x378
    ctx->r4 = ADD32(0, 0X378);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x80800094: addiu       $a0, $zero, 0x378
    ctx->r4 = ADD32(0, 0X378);
    after_7:
    // 0x80800098: beql        $v0, $zero, L_808000AC
    if (ctx->r2 == 0) {
        // 0x8080009C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808000AC;
    }
    goto skip_0;
    // 0x8080009C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808000A0: jal         0x800FFAB0
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_8;
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_808000A8:
    // 0x808000A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000AC:
    // 0x808000AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000B4: jr          $ra
    // 0x808000B8: nop

    return;
    // 0x808000B8: nop

;}
RECOMP_FUNC void func_8080071C_chintrochar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080071C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80800720: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800724: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800728: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080072C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800730: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80800734: jal         0x80100094
    // 0x80800738: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800738: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x8080073C: jal         0x80082660
    // 0x80800740: lh          $a0, 0xC0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0XC0);
    _anseq_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80800740: lh          $a0, 0xC0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0XC0);
    after_1:
    // 0x80800744: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x80800748: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8080074C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800750: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80800754: jal         0x80082618
    // 0x80800758: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
    _anseq_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80800758: sw          $t7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r15;
    after_2:
    // 0x8080075C: slti        $at, $s0, 0x1EA
    ctx->r1 = SIGNED(ctx->r16) < 0X1EA ? 1 : 0;
    // 0x80800760: bne         $at, $zero, L_80800828
    if (ctx->r1 != 0) {
        // 0x80800764: slti        $at, $s0, 0x426
        ctx->r1 = SIGNED(ctx->r16) < 0X426 ? 1 : 0;
            goto L_80800828;
    }
    // 0x80800764: slti        $at, $s0, 0x426
    ctx->r1 = SIGNED(ctx->r16) < 0X426 ? 1 : 0;
    // 0x80800768: bne         $at, $zero, L_808007BC
    if (ctx->r1 != 0) {
        // 0x8080076C: slti        $at, $s0, 0x4B1
        ctx->r1 = SIGNED(ctx->r16) < 0X4B1 ? 1 : 0;
            goto L_808007BC;
    }
    // 0x8080076C: slti        $at, $s0, 0x4B1
    ctx->r1 = SIGNED(ctx->r16) < 0X4B1 ? 1 : 0;
    // 0x80800770: bne         $at, $zero, L_8080079C
    if (ctx->r1 != 0) {
        // 0x80800774: addiu       $t9, $s0, -0x445
        ctx->r25 = ADD32(ctx->r16, -0X445);
            goto L_8080079C;
    }
    // 0x80800774: addiu       $t9, $s0, -0x445
    ctx->r25 = ADD32(ctx->r16, -0X445);
    // 0x80800778: addiu       $t8, $s0, -0x4DB
    ctx->r24 = ADD32(ctx->r16, -0X4DB);
    // 0x8080077C: sltiu       $at, $t8, 0x67
    ctx->r1 = ctx->r24 < 0X67 ? 1 : 0;
    // 0x80800780: beq         $at, $zero, L_80803374
    if (ctx->r1 == 0) {
        // 0x80800784: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80803374;
    }
    // 0x80800784: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800788: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1732, 0X4370) << 16);
    // 0x8080078C: addu        $at, $at, $t8
    gpr jr_addend_80800794 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800790: lw          $t8, 0x4370($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1732, 0X4370));
    // 0x80800794: jr          $t8
    // 0x80800798: nop

    switch (jr_addend_80800794 >> 2) {
        case 0: goto L_80803374; break;
        case 1: goto L_80802F24; break;
        case 2: goto L_80803374; break;
        case 3: goto L_80803374; break;
        case 4: goto L_80803374; break;
        case 5: goto L_80803374; break;
        case 6: goto L_80803374; break;
        case 7: goto L_80803374; break;
        case 8: goto L_80803374; break;
        case 9: goto L_80803374; break;
        case 10: goto L_80803374; break;
        case 11: goto L_80803374; break;
        case 12: goto L_80803374; break;
        case 13: goto L_80803374; break;
        case 14: goto L_80803374; break;
        case 15: goto L_80803374; break;
        case 16: goto L_80803374; break;
        case 17: goto L_80802F84; break;
        case 18: goto L_8080300C; break;
        case 19: goto L_80803374; break;
        case 20: goto L_80803374; break;
        case 21: goto L_80803374; break;
        case 22: goto L_80802504; break;
        case 23: goto L_80800A8C; break;
        case 24: goto L_80803374; break;
        case 25: goto L_80800B64; break;
        case 26: goto L_80803374; break;
        case 27: goto L_80803374; break;
        case 28: goto L_80803374; break;
        case 29: goto L_80803374; break;
        case 30: goto L_80803374; break;
        case 31: goto L_80803374; break;
        case 32: goto L_80803374; break;
        case 33: goto L_808029CC; break;
        case 34: goto L_80803374; break;
        case 35: goto L_80802A00; break;
        case 36: goto L_80803374; break;
        case 37: goto L_80802A34; break;
        case 38: goto L_808026D0; break;
        case 39: goto L_80803040; break;
        case 40: goto L_80803374; break;
        case 41: goto L_80803374; break;
        case 42: goto L_80803374; break;
        case 43: goto L_80803374; break;
        case 44: goto L_80803374; break;
        case 45: goto L_80803374; break;
        case 46: goto L_80803374; break;
        case 47: goto L_808031D8; break;
        case 48: goto L_80803374; break;
        case 49: goto L_80803374; break;
        case 50: goto L_80803374; break;
        case 51: goto L_80802454; break;
        case 52: goto L_80803374; break;
        case 53: goto L_80803374; break;
        case 54: goto L_808018EC; break;
        case 55: goto L_80801920; break;
        case 56: goto L_80801804; break;
        case 57: goto L_80803374; break;
        case 58: goto L_80803374; break;
        case 59: goto L_80803374; break;
        case 60: goto L_80803374; break;
        case 61: goto L_80803374; break;
        case 62: goto L_80801864; break;
        case 63: goto L_80803374; break;
        case 64: goto L_80803374; break;
        case 65: goto L_80803374; break;
        case 66: goto L_80803374; break;
        case 67: goto L_80803374; break;
        case 68: goto L_80801554; break;
        case 69: goto L_80803374; break;
        case 70: goto L_80800F5C; break;
        case 71: goto L_80803374; break;
        case 72: goto L_80802EF0; break;
        case 73: goto L_80803374; break;
        case 74: goto L_80803374; break;
        case 75: goto L_80803374; break;
        case 76: goto L_80803374; break;
        case 77: goto L_80803374; break;
        case 78: goto L_80803374; break;
        case 79: goto L_80803374; break;
        case 80: goto L_80803374; break;
        case 81: goto L_80803374; break;
        case 82: goto L_80803374; break;
        case 83: goto L_80803374; break;
        case 84: goto L_80803374; break;
        case 85: goto L_80803374; break;
        case 86: goto L_80803374; break;
        case 87: goto L_80803374; break;
        case 88: goto L_808030A0; break;
        case 89: goto L_80803374; break;
        case 90: goto L_80803178; break;
        case 91: goto L_8080100C; break;
        case 92: goto L_80803374; break;
        case 93: goto L_80802BC0; break;
        case 94: goto L_80803374; break;
        case 95: goto L_80803374; break;
        case 96: goto L_80803260; break;
        case 97: goto L_80803374; break;
        case 98: goto L_80803374; break;
        case 99: goto L_80803374; break;
        case 100: goto L_80803374; break;
        case 101: goto L_808032C0; break;
        case 102: goto L_808032F4; break;
        default: switch_error(__func__, 0x80800794, 0x80804370);
    }
    // 0x80800798: nop

L_8080079C:
    // 0x8080079C: sltiu       $at, $t9, 0x6C
    ctx->r1 = ctx->r25 < 0X6C ? 1 : 0;
    // 0x808007A0: beq         $at, $zero, L_80803374
    if (ctx->r1 == 0) {
        // 0x808007A4: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80803374;
    }
    // 0x808007A4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x808007A8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1732, 0X450C) << 16);
    // 0x808007AC: addu        $at, $at, $t9
    gpr jr_addend_808007B4 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x808007B0: lw          $t9, 0x450C($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1732, 0X450C));
    // 0x808007B4: jr          $t9
    // 0x808007B8: nop

    switch (jr_addend_808007B4 >> 2) {
        case 0: goto L_80803374; break;
        case 1: goto L_80802710; break;
        case 2: goto L_80801FD4; break;
        case 3: goto L_80803374; break;
        case 4: goto L_80803374; break;
        case 5: goto L_80803374; break;
        case 6: goto L_80803374; break;
        case 7: goto L_808009A4; break;
        case 8: goto L_80803374; break;
        case 9: goto L_80803374; break;
        case 10: goto L_80802770; break;
        case 11: goto L_808027B4; break;
        case 12: goto L_8080286C; break;
        case 13: goto L_80803374; break;
        case 14: goto L_80803374; break;
        case 15: goto L_80803374; break;
        case 16: goto L_80800A04; break;
        case 17: goto L_80803374; break;
        case 18: goto L_80802244; break;
        case 19: goto L_80803374; break;
        case 20: goto L_80803374; break;
        case 21: goto L_808022F4; break;
        case 22: goto L_80802618; break;
        case 23: goto L_80802648; break;
        case 24: goto L_80803374; break;
        case 25: goto L_808023A4; break;
        case 26: goto L_80802B14; break;
        case 27: goto L_80802B60; break;
        case 28: goto L_80803374; break;
        case 29: goto L_808012BC; break;
        case 30: goto L_80800DA0; break;
        case 31: goto L_80803374; break;
        case 32: goto L_80801308; break;
        case 33: goto L_80800DD4; break;
        case 34: goto L_80801360; break;
        case 35: goto L_808013E8; break;
        case 36: goto L_80803374; break;
        case 37: goto L_80801498; break;
        case 38: goto L_80801744; break;
        case 39: goto L_8080179C; break;
        case 40: goto L_80803374; break;
        case 41: goto L_808017D0; break;
        case 42: goto L_80803374; break;
        case 43: goto L_80801520; break;
        case 44: goto L_80803374; break;
        case 45: goto L_80803374; break;
        case 46: goto L_80803374; break;
        case 47: goto L_80800C20; break;
        case 48: goto L_80803374; break;
        case 49: goto L_80803374; break;
        case 50: goto L_80803374; break;
        case 51: goto L_80803374; break;
        case 52: goto L_80803374; break;
        case 53: goto L_80803374; break;
        case 54: goto L_80803374; break;
        case 55: goto L_80803374; break;
        case 56: goto L_80803374; break;
        case 57: goto L_80803374; break;
        case 58: goto L_80803374; break;
        case 59: goto L_80803374; break;
        case 60: goto L_80803374; break;
        case 61: goto L_80803374; break;
        case 62: goto L_80803374; break;
        case 63: goto L_80803374; break;
        case 64: goto L_80803374; break;
        case 65: goto L_80803374; break;
        case 66: goto L_80803374; break;
        case 67: goto L_80803374; break;
        case 68: goto L_80803374; break;
        case 69: goto L_80803374; break;
        case 70: goto L_80803374; break;
        case 71: goto L_80800E84; break;
        case 72: goto L_80803374; break;
        case 73: goto L_80803374; break;
        case 74: goto L_80803374; break;
        case 75: goto L_80803374; break;
        case 76: goto L_80803374; break;
        case 77: goto L_8080291C; break;
        case 78: goto L_80803374; break;
        case 79: goto L_80803374; break;
        case 80: goto L_80803374; break;
        case 81: goto L_80803374; break;
        case 82: goto L_80803374; break;
        case 83: goto L_80803374; break;
        case 84: goto L_80803374; break;
        case 85: goto L_80803374; break;
        case 86: goto L_80803374; break;
        case 87: goto L_80803374; break;
        case 88: goto L_80803374; break;
        case 89: goto L_80803374; break;
        case 90: goto L_80803374; break;
        case 91: goto L_80803374; break;
        case 92: goto L_80803374; break;
        case 93: goto L_80803374; break;
        case 94: goto L_80803374; break;
        case 95: goto L_80803374; break;
        case 96: goto L_80803374; break;
        case 97: goto L_80803374; break;
        case 98: goto L_80803374; break;
        case 99: goto L_80803374; break;
        case 100: goto L_80803374; break;
        case 101: goto L_80803374; break;
        case 102: goto L_80803374; break;
        case 103: goto L_80803374; break;
        case 104: goto L_80803374; break;
        case 105: goto L_80803374; break;
        case 106: goto L_80803374; break;
        case 107: goto L_808019F8; break;
        default: switch_error(__func__, 0x808007B4, 0x8080450C);
    }
    // 0x808007B8: nop

L_808007BC:
    // 0x808007BC: slti        $at, $s0, 0x3AC
    ctx->r1 = SIGNED(ctx->r16) < 0X3AC ? 1 : 0;
    // 0x808007C0: bne         $at, $zero, L_808007E8
    if (ctx->r1 != 0) {
        // 0x808007C4: addiu       $t0, $s0, -0x408
        ctx->r8 = ADD32(ctx->r16, -0X408);
            goto L_808007E8;
    }
    // 0x808007C4: addiu       $t0, $s0, -0x408
    ctx->r8 = ADD32(ctx->r16, -0X408);
    // 0x808007C8: sltiu       $at, $t0, 0x1E
    ctx->r1 = ctx->r8 < 0X1E ? 1 : 0;
    // 0x808007CC: beq         $at, $zero, L_80803374
    if (ctx->r1 == 0) {
        // 0x808007D0: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_80803374;
    }
    // 0x808007D0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x808007D4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1732, 0X46BC) << 16);
    // 0x808007D8: addu        $at, $at, $t0
    gpr jr_addend_808007E0 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x808007DC: lw          $t0, 0x46BC($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1732, 0X46BC));
    // 0x808007E0: jr          $t0
    // 0x808007E4: nop

    switch (jr_addend_808007E0 >> 2) {
        case 0: goto L_80803374; break;
        case 1: goto L_80803374; break;
        case 2: goto L_80803374; break;
        case 3: goto L_80803374; break;
        case 4: goto L_80800C78; break;
        case 5: goto L_80800CD8; break;
        case 6: goto L_80803374; break;
        case 7: goto L_80801EC4; break;
        case 8: goto L_80801CFC; break;
        case 9: goto L_80801F74; break;
        case 10: goto L_80803374; break;
        case 11: goto L_80803374; break;
        case 12: goto L_80802080; break;
        case 13: goto L_808020CC; break;
        case 14: goto L_80803374; break;
        case 15: goto L_80802118; break;
        case 16: goto L_80802178; break;
        case 17: goto L_80803374; break;
        case 18: goto L_80802538; break;
        case 19: goto L_80803374; break;
        case 20: goto L_808021AC; break;
        case 21: goto L_80803374; break;
        case 22: goto L_80802584; break;
        case 23: goto L_80803374; break;
        case 24: goto L_808025E4; break;
        case 25: goto L_808021E0; break;
        case 26: goto L_80800BEC; break;
        case 27: goto L_80803374; break;
        case 28: goto L_80803374; break;
        case 29: goto L_80802210; break;
        default: switch_error(__func__, 0x808007E0, 0x808046BC);
    }
    // 0x808007E4: nop

L_808007E8:
    // 0x808007E8: slti        $at, $s0, 0x265
    ctx->r1 = SIGNED(ctx->r16) < 0X265 ? 1 : 0;
    // 0x808007EC: bne         $at, $zero, L_80800814
    if (ctx->r1 != 0) {
        // 0x808007F0: addiu       $t1, $s0, -0x39B
        ctx->r9 = ADD32(ctx->r16, -0X39B);
            goto L_80800814;
    }
    // 0x808007F0: addiu       $t1, $s0, -0x39B
    ctx->r9 = ADD32(ctx->r16, -0X39B);
    // 0x808007F4: sltiu       $at, $t1, 0x11
    ctx->r1 = ctx->r9 < 0X11 ? 1 : 0;
    // 0x808007F8: beq         $at, $zero, L_80803374
    if (ctx->r1 == 0) {
        // 0x808007FC: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_80803374;
    }
    // 0x808007FC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80800800: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1732, 0X4734) << 16);
    // 0x80800804: addu        $at, $at, $t1
    gpr jr_addend_8080080C = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80800808: lw          $t1, 0x4734($at)
    ctx->r9 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1732, 0X4734));
    // 0x8080080C: jr          $t1
    // 0x80800810: nop

    switch (jr_addend_8080080C >> 2) {
        case 0: goto L_80800870; break;
        case 1: goto L_808008FC; break;
        case 2: goto L_80803374; break;
        case 3: goto L_80803374; break;
        case 4: goto L_80803374; break;
        case 5: goto L_80803374; break;
        case 6: goto L_80803374; break;
        case 7: goto L_80803374; break;
        case 8: goto L_80803374; break;
        case 9: goto L_80803374; break;
        case 10: goto L_80803374; break;
        case 11: goto L_80803374; break;
        case 12: goto L_80803374; break;
        case 13: goto L_80803374; break;
        case 14: goto L_80803374; break;
        case 15: goto L_80803374; break;
        case 16: goto L_80801A44; break;
        default: switch_error(__func__, 0x8080080C, 0x80804734);
    }
    // 0x80800810: nop

L_80800814:
    // 0x80800814: addiu       $at, $zero, 0x264
    ctx->r1 = ADD32(0, 0X264);
    // 0x80800818: beq         $s0, $at, L_8080095C
    if (ctx->r16 == ctx->r1) {
        // 0x8080081C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8080095C;
    }
    // 0x8080081C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800820: b           L_80803378
    // 0x80800824: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80800824: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800828:
    // 0x80800828: addiu       $at, $zero, 0xB3
    ctx->r1 = ADD32(0, 0XB3);
    // 0x8080082C: beq         $s0, $at, L_80803374
    if (ctx->r16 == ctx->r1) {
        // 0x80800830: addiu       $at, $zero, 0xB4
        ctx->r1 = ADD32(0, 0XB4);
            goto L_80803374;
    }
    // 0x80800830: addiu       $at, $zero, 0xB4
    ctx->r1 = ADD32(0, 0XB4);
    // 0x80800834: beq         $s0, $at, L_80801274
    if (ctx->r16 == ctx->r1) {
        // 0x80800838: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80801274;
    }
    // 0x80800838: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080083C: addiu       $at, $zero, 0x190
    ctx->r1 = ADD32(0, 0X190);
    // 0x80800840: beq         $s0, $at, L_80802A74
    if (ctx->r16 == ctx->r1) {
        // 0x80800844: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80802A74;
    }
    // 0x80800844: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800848: addiu       $at, $zero, 0x1E6
    ctx->r1 = ADD32(0, 0X1E6);
    // 0x8080084C: beq         $s0, $at, L_80802AA4
    if (ctx->r16 == ctx->r1) {
        // 0x80800850: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80802AA4;
    }
    // 0x80800850: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800854: addiu       $at, $zero, 0x1E7
    ctx->r1 = ADD32(0, 0X1E7);
    // 0x80800858: beq         $s0, $at, L_80803374
    if (ctx->r16 == ctx->r1) {
        // 0x8080085C: addiu       $at, $zero, 0x1E9
        ctx->r1 = ADD32(0, 0X1E9);
            goto L_80803374;
    }
    // 0x8080085C: addiu       $at, $zero, 0x1E9
    ctx->r1 = ADD32(0, 0X1E9);
    // 0x80800860: beq         $s0, $at, L_80802AE4
    if (ctx->r16 == ctx->r1) {
        // 0x80800864: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80802AE4;
    }
    // 0x80800864: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800868: b           L_80803378
    // 0x8080086C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x8080086C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800870:
    // 0x80800870: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1732, 0X5270) << 16);
    // 0x80800874: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80800878: addiu       $s0, $s0, -0x7090
    ctx->r16 = ADD32(ctx->r16, -0X7090);
    // 0x8080087C: addiu       $v0, $v0, 0x5270
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1732, 0X5270));
    // 0x80800880: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80800884:
    // 0x80800884: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800888: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8080088C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x80800890: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800894: jal         0x80082628
    // 0x80800898: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800898: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_3:
    // 0x8080089C: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x808008A0: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(1732, 0X527C) << 16);
    // 0x808008A4: addiu       $t2, $t2, 0x527C
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(1732, 0X527C));
    // 0x808008A8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808008AC: bnel        $v0, $t2, L_80800884
    if (ctx->r2 != ctx->r10) {
        // 0x808008B0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800884;
    }
    goto skip_0;
    // 0x808008B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x808008B4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1732, 0X527C) << 16);
    // 0x808008B8: addiu       $v0, $v0, 0x527C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1732, 0X527C));
    // 0x808008BC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_808008C0:
    // 0x808008C0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x808008C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808008C8: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808008CC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808008D0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x808008D4: jal         0x80082628
    // 0x808008D8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x808008D8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_4:
    // 0x808008DC: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x808008E0: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(1732, 0X5288) << 16);
    // 0x808008E4: addiu       $t4, $t4, 0x5288
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(1732, 0X5288));
    // 0x808008E8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808008EC: bnel        $v0, $t4, L_808008C0
    if (ctx->r2 != ctx->r12) {
        // 0x808008F0: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_808008C0;
    }
    goto skip_1;
    // 0x808008F0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    skip_1:
    // 0x808008F4: b           L_80803378
    // 0x808008F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x808008F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808008FC:
    // 0x808008FC: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80800900: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x80800904: lui         $a1, 0x3E96
    ctx->r5 = S32(0X3E96 << 16);
    // 0x80800908: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x8080090C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80800910: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80800914: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80800918: ori         $a1, $a1, 0xA162
    ctx->r5 = ctx->r5 | 0XA162;
    // 0x8080091C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800920: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800924: jal         0x80082630
    // 0x80800928: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x80800928: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_5:
    // 0x8080092C: lui         $a1, 0x3F67
    ctx->r5 = S32(0X3F67 << 16);
    // 0x80800930: addiu       $t7, $zero, 0x7
    ctx->r15 = ADD32(0, 0X7);
    // 0x80800934: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80800938: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8080093C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800940: ori         $a1, $a1, 0xC1BE
    ctx->r5 = ctx->r5 | 0XC1BE;
    // 0x80800944: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800948: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8080094C: jal         0x80082630
    // 0x80800950: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x80800950: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_6:
    // 0x80800954: b           L_80803378
    // 0x80800958: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80800958: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080095C:
    // 0x8080095C: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80800960: addiu       $s0, $s0, -0x7090
    ctx->r16 = ADD32(ctx->r16, -0X7090);
    // 0x80800964: lui         $a1, 0x3CF1
    ctx->r5 = S32(0X3CF1 << 16);
    // 0x80800968: ori         $a1, $a1, 0xA9FC
    ctx->r5 = ctx->r5 | 0XA9FC;
    // 0x8080096C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800970: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x80800974: jal         0x80082628
    // 0x80800978: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_7;
    // 0x80800978: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_7:
    // 0x8080097C: lui         $a1, 0x3F05
    ctx->r5 = S32(0X3F05 << 16);
    // 0x80800980: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80800984: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800988: ori         $a1, $a1, 0x182B
    ctx->r5 = ctx->r5 | 0X182B;
    // 0x8080098C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800990: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800994: jal         0x80082628
    // 0x80800998: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x80800998: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_8:
    // 0x8080099C: b           L_80803378
    // 0x808009A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x808009A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808009A4:
    // 0x808009A4: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x808009A8: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x808009AC: lui         $a1, 0x3F0A
    ctx->r5 = S32(0X3F0A << 16);
    // 0x808009B0: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x808009B4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x808009B8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x808009BC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x808009C0: ori         $a1, $a1, 0xE148
    ctx->r5 = ctx->r5 | 0XE148;
    // 0x808009C4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808009C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808009CC: jal         0x80082630
    // 0x808009D0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_9;
    // 0x808009D0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_9:
    // 0x808009D4: lui         $a1, 0x3F20
    ctx->r5 = S32(0X3F20 << 16);
    // 0x808009D8: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x808009DC: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x808009E0: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x808009E4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808009E8: ori         $a1, $a1, 0x1A37
    ctx->r5 = ctx->r5 | 0X1A37;
    // 0x808009EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808009F0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808009F4: jal         0x80082630
    // 0x808009F8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_10;
    // 0x808009F8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_10:
    // 0x808009FC: b           L_80803378
    // 0x80800A00: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80800A00: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800A04:
    // 0x80800A04: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80800A08: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x80800A0C: lui         $a1, 0x3DDC
    ctx->r5 = S32(0X3DDC << 16);
    // 0x80800A10: addiu       $t4, $zero, 0xB
    ctx->r12 = ADD32(0, 0XB);
    // 0x80800A14: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80800A18: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80800A1C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80800A20: ori         $a1, $a1, 0xC63F
    ctx->r5 = ctx->r5 | 0XC63F;
    // 0x80800A24: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800A28: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800A2C: jal         0x80082630
    // 0x80800A30: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_11;
    // 0x80800A30: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_11:
    // 0x80800A34: lui         $a1, 0x3E87
    ctx->r5 = S32(0X3E87 << 16);
    // 0x80800A38: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80800A3C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80800A40: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80800A44: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800A48: ori         $a1, $a1, 0x5254
    ctx->r5 = ctx->r5 | 0X5254;
    // 0x80800A4C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800A50: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800A54: jal         0x80082630
    // 0x80800A58: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_12;
    // 0x80800A58: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_12:
    // 0x80800A5C: lui         $a1, 0x3E96
    ctx->r5 = S32(0X3E96 << 16);
    // 0x80800A60: addiu       $t8, $zero, 0xD
    ctx->r24 = ADD32(0, 0XD);
    // 0x80800A64: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80800A68: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80800A6C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800A70: ori         $a1, $a1, 0x872B
    ctx->r5 = ctx->r5 | 0X872B;
    // 0x80800A74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800A78: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800A7C: jal         0x80082630
    // 0x80800A80: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_13;
    // 0x80800A80: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_13:
    // 0x80800A84: b           L_80803378
    // 0x80800A88: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80800A88: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800A8C:
    // 0x80800A8C: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80800A90: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x80800A94: lui         $a1, 0x3DC3
    ctx->r5 = S32(0X3DC3 << 16);
    // 0x80800A98: addiu       $t0, $zero, 0x88
    ctx->r8 = ADD32(0, 0X88);
    // 0x80800A9C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80800AA0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80800AA4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800AA8: ori         $a1, $a1, 0xFE5D
    ctx->r5 = ctx->r5 | 0XFE5D;
    // 0x80800AAC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800AB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800AB4: jal         0x80082630
    // 0x80800AB8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_14;
    // 0x80800AB8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_14:
    // 0x80800ABC: lui         $a1, 0x3E1A
    ctx->r5 = S32(0X3E1A << 16);
    // 0x80800AC0: addiu       $t2, $zero, 0x88
    ctx->r10 = ADD32(0, 0X88);
    // 0x80800AC4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80800AC8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80800ACC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800AD0: ori         $a1, $a1, 0xEE63
    ctx->r5 = ctx->r5 | 0XEE63;
    // 0x80800AD4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800AD8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800ADC: jal         0x80082630
    // 0x80800AE0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_15;
    // 0x80800AE0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_15:
    // 0x80800AE4: lui         $a1, 0x3E64
    ctx->r5 = S32(0X3E64 << 16);
    // 0x80800AE8: addiu       $t4, $zero, 0x88
    ctx->r12 = ADD32(0, 0X88);
    // 0x80800AEC: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80800AF0: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80800AF4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80800AF8: ori         $a1, $a1, 0xC2F8
    ctx->r5 = ctx->r5 | 0XC2F8;
    // 0x80800AFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800B00: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800B04: jal         0x80082630
    // 0x80800B08: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_16;
    // 0x80800B08: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_16:
    // 0x80800B0C: lui         $a1, 0x3E9C
    ctx->r5 = S32(0X3E9C << 16);
    // 0x80800B10: addiu       $t6, $zero, 0x89
    ctx->r14 = ADD32(0, 0X89);
    // 0x80800B14: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80800B18: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80800B1C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800B20: ori         $a1, $a1, 0xEBF
    ctx->r5 = ctx->r5 | 0XEBF;
    // 0x80800B24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800B28: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800B2C: jal         0x80082630
    // 0x80800B30: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_17;
    // 0x80800B30: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_17:
    // 0x80800B34: lui         $a1, 0x3EBE
    ctx->r5 = S32(0X3EBE << 16);
    // 0x80800B38: addiu       $t8, $zero, 0x89
    ctx->r24 = ADD32(0, 0X89);
    // 0x80800B3C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80800B40: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80800B44: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800B48: ori         $a1, $a1, 0x353F
    ctx->r5 = ctx->r5 | 0X353F;
    // 0x80800B4C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800B50: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800B54: jal         0x80082630
    // 0x80800B58: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_18;
    // 0x80800B58: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_18:
    // 0x80800B5C: b           L_80803378
    // 0x80800B60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80800B60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800B64:
    // 0x80800B64: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80800B68: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x80800B6C: lui         $a1, 0x3E01
    ctx->r5 = S32(0X3E01 << 16);
    // 0x80800B70: addiu       $t0, $zero, 0x8A
    ctx->r8 = ADD32(0, 0X8A);
    // 0x80800B74: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80800B78: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80800B7C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800B80: ori         $a1, $a1, 0xD7DC
    ctx->r5 = ctx->r5 | 0XD7DC;
    // 0x80800B84: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800B88: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800B8C: jal         0x80082630
    // 0x80800B90: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_19;
    // 0x80800B90: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_19:
    // 0x80800B94: lui         $a1, 0x3F5A
    ctx->r5 = S32(0X3F5A << 16);
    // 0x80800B98: addiu       $t2, $zero, 0x8B
    ctx->r10 = ADD32(0, 0X8B);
    // 0x80800B9C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80800BA0: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80800BA4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800BA8: ori         $a1, $a1, 0xE148
    ctx->r5 = ctx->r5 | 0XE148;
    // 0x80800BAC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800BB0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800BB4: jal         0x80082630
    // 0x80800BB8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_20;
    // 0x80800BB8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_20:
    // 0x80800BBC: lui         $a1, 0x3F6A
    ctx->r5 = S32(0X3F6A << 16);
    // 0x80800BC0: addiu       $t4, $zero, 0x8C
    ctx->r12 = ADD32(0, 0X8C);
    // 0x80800BC4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80800BC8: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80800BCC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80800BD0: ori         $a1, $a1, 0xF4F1
    ctx->r5 = ctx->r5 | 0XF4F1;
    // 0x80800BD4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800BD8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800BDC: jal         0x80082630
    // 0x80800BE0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_21;
    // 0x80800BE0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_21:
    // 0x80800BE4: b           L_80803378
    // 0x80800BE8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80800BE8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800BEC:
    // 0x80800BEC: lui         $a1, 0x3F4E
    ctx->r5 = S32(0X3F4E << 16);
    // 0x80800BF0: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80800BF4: addiu       $t6, $zero, 0x77
    ctx->r14 = ADD32(0, 0X77);
    // 0x80800BF8: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80800BFC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80800C00: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800C04: addiu       $a2, $a2, -0x7068
    ctx->r6 = ADD32(ctx->r6, -0X7068);
    // 0x80800C08: ori         $a1, $a1, 0x1B09
    ctx->r5 = ctx->r5 | 0X1B09;
    // 0x80800C0C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800C10: jal         0x80082630
    // 0x80800C14: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_22;
    // 0x80800C14: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_22:
    // 0x80800C18: b           L_80803378
    // 0x80800C1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80800C1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800C20:
    // 0x80800C20: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80800C24: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1732, 0X5288) << 16);
    // 0x80800C28: addiu       $v0, $v0, 0x5288
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1732, 0X5288));
    // 0x80800C2C: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x80800C30: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
L_80800C34:
    // 0x80800C34: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80800C38: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80800C3C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800C40: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800C44: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800C48: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800C4C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x80800C50: jal         0x80082630
    // 0x80800C54: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_23;
    // 0x80800C54: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_23:
    // 0x80800C58: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80800C5C: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(1732, 0X52A4) << 16);
    // 0x80800C60: addiu       $t0, $t0, 0x52A4
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(1732, 0X52A4));
    // 0x80800C64: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800C68: bnel        $v0, $t0, L_80800C34
    if (ctx->r2 != ctx->r8) {
        // 0x80800C6C: addiu       $t8, $zero, 0x64
        ctx->r24 = ADD32(0, 0X64);
            goto L_80800C34;
    }
    goto skip_2;
    // 0x80800C6C: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    skip_2:
    // 0x80800C70: b           L_80803378
    // 0x80800C74: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80800C74: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800C78:
    // 0x80800C78: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80800C7C: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x80800C80: lui         $a1, 0x3F08
    ctx->r5 = S32(0X3F08 << 16);
    // 0x80800C84: addiu       $t1, $zero, 0xE
    ctx->r9 = ADD32(0, 0XE);
    // 0x80800C88: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80800C8C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80800C90: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800C94: ori         $a1, $a1, 0x16F0
    ctx->r5 = ctx->r5 | 0X16F0;
    // 0x80800C98: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800C9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800CA0: jal         0x80082630
    // 0x80800CA4: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_24;
    // 0x80800CA4: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_24:
    // 0x80800CA8: lui         $a1, 0x3CA3
    ctx->r5 = S32(0X3CA3 << 16);
    // 0x80800CAC: addiu       $t3, $zero, 0xF
    ctx->r11 = ADD32(0, 0XF);
    // 0x80800CB0: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80800CB4: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80800CB8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80800CBC: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80800CC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800CC4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800CC8: jal         0x80082630
    // 0x80800CCC: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_25;
    // 0x80800CCC: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_25:
    // 0x80800CD0: b           L_80803378
    // 0x80800CD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80800CD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800CD8:
    // 0x80800CD8: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80800CDC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1732, 0X52A4) << 16);
    // 0x80800CE0: addiu       $v0, $v0, 0x52A4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1732, 0X52A4));
    // 0x80800CE4: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x80800CE8: addiu       $t5, $zero, 0xE
    ctx->r13 = ADD32(0, 0XE);
L_80800CEC:
    // 0x80800CEC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80800CF0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80800CF4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80800CF8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800CFC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800D00: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800D04: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x80800D08: jal         0x80082630
    // 0x80800D0C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_26;
    // 0x80800D0C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_26:
    // 0x80800D10: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80800D14: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1732, 0X52AC) << 16);
    // 0x80800D18: addiu       $t7, $t7, 0x52AC
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1732, 0X52AC));
    // 0x80800D1C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800D20: bnel        $v0, $t7, L_80800CEC
    if (ctx->r2 != ctx->r15) {
        // 0x80800D24: addiu       $t5, $zero, 0xE
        ctx->r13 = ADD32(0, 0XE);
            goto L_80800CEC;
    }
    goto skip_3;
    // 0x80800D24: addiu       $t5, $zero, 0xE
    ctx->r13 = ADD32(0, 0XE);
    skip_3:
    // 0x80800D28: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1732, 0X52AC) << 16);
    // 0x80800D2C: addiu       $v0, $v0, 0x52AC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1732, 0X52AC));
    // 0x80800D30: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
L_80800D34:
    // 0x80800D34: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80800D38: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80800D3C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800D40: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800D44: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80800D48: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800D4C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x80800D50: jal         0x80082630
    // 0x80800D54: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_27;
    // 0x80800D54: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_27:
    // 0x80800D58: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80800D5C: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(1732, 0X52B4) << 16);
    // 0x80800D60: addiu       $t0, $t0, 0x52B4
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(1732, 0X52B4));
    // 0x80800D64: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800D68: bnel        $v0, $t0, L_80800D34
    if (ctx->r2 != ctx->r8) {
        // 0x80800D6C: addiu       $t8, $zero, 0xF
        ctx->r24 = ADD32(0, 0XF);
            goto L_80800D34;
    }
    goto skip_4;
    // 0x80800D6C: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    skip_4:
    // 0x80800D70: lui         $a1, 0x3E2E
    ctx->r5 = S32(0X3E2E << 16);
    // 0x80800D74: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x80800D78: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80800D7C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80800D80: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800D84: ori         $a1, $a1, 0x147B
    ctx->r5 = ctx->r5 | 0X147B;
    // 0x80800D88: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800D8C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800D90: jal         0x80082630
    // 0x80800D94: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_28;
    // 0x80800D94: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_28:
    // 0x80800D98: b           L_80803378
    // 0x80800D9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80800D9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800DA0:
    // 0x80800DA0: lui         $a1, 0x3F12
    ctx->r5 = S32(0X3F12 << 16);
    // 0x80800DA4: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80800DA8: addiu       $t3, $zero, 0x11
    ctx->r11 = ADD32(0, 0X11);
    // 0x80800DAC: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80800DB0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80800DB4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80800DB8: addiu       $a2, $a2, -0x7068
    ctx->r6 = ADD32(ctx->r6, -0X7068);
    // 0x80800DBC: ori         $a1, $a1, 0x1FF3
    ctx->r5 = ctx->r5 | 0X1FF3;
    // 0x80800DC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800DC4: jal         0x80082630
    // 0x80800DC8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_29;
    // 0x80800DC8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_29:
    // 0x80800DCC: b           L_80803378
    // 0x80800DD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80800DD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800DD4:
    // 0x80800DD4: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80800DD8: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x80800DDC: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80800DE0: addiu       $t5, $zero, 0x13
    ctx->r13 = ADD32(0, 0X13);
    // 0x80800DE4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80800DE8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80800DEC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80800DF0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800DF4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800DF8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800DFC: jal         0x80082630
    // 0x80800E00: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_30;
    // 0x80800E00: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_30:
    // 0x80800E04: lui         $a1, 0x3F09
    ctx->r5 = S32(0X3F09 << 16);
    // 0x80800E08: addiu       $t7, $zero, 0xB0
    ctx->r15 = ADD32(0, 0XB0);
    // 0x80800E0C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80800E10: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80800E14: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800E18: ori         $a1, $a1, 0x374C
    ctx->r5 = ctx->r5 | 0X374C;
    // 0x80800E1C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800E20: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800E24: jal         0x80082630
    // 0x80800E28: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_31;
    // 0x80800E28: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_31:
    // 0x80800E2C: lui         $a1, 0x3F12
    ctx->r5 = S32(0X3F12 << 16);
    // 0x80800E30: addiu       $t9, $zero, 0xB1
    ctx->r25 = ADD32(0, 0XB1);
    // 0x80800E34: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80800E38: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80800E3C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800E40: ori         $a1, $a1, 0x9C78
    ctx->r5 = ctx->r5 | 0X9C78;
    // 0x80800E44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800E48: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800E4C: jal         0x80082630
    // 0x80800E50: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_32;
    // 0x80800E50: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_32:
    // 0x80800E54: lui         $a1, 0x3F1B
    ctx->r5 = S32(0X3F1B << 16);
    // 0x80800E58: addiu       $t1, $zero, 0xB2
    ctx->r9 = ADD32(0, 0XB2);
    // 0x80800E5C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80800E60: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80800E64: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800E68: ori         $a1, $a1, 0xF488
    ctx->r5 = ctx->r5 | 0XF488;
    // 0x80800E6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800E70: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800E74: jal         0x80082630
    // 0x80800E78: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_33;
    // 0x80800E78: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_33:
    // 0x80800E7C: b           L_80803378
    // 0x80800E80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80800E80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800E84:
    // 0x80800E84: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80800E88: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x80800E8C: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    // 0x80800E90: addiu       $t3, $zero, 0x78
    ctx->r11 = ADD32(0, 0X78);
    // 0x80800E94: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80800E98: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80800E9C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80800EA0: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80800EA4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800EA8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800EAC: jal         0x80082630
    // 0x80800EB0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_34;
    // 0x80800EB0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_34:
    // 0x80800EB4: lui         $a1, 0x3F14
    ctx->r5 = S32(0X3F14 << 16);
    // 0x80800EB8: addiu       $t5, $zero, 0x67
    ctx->r13 = ADD32(0, 0X67);
    // 0x80800EBC: addiu       $t6, $zero, -0x2
    ctx->r14 = ADD32(0, -0X2);
    // 0x80800EC0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80800EC4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80800EC8: ori         $a1, $a1, 0x7AE1
    ctx->r5 = ctx->r5 | 0X7AE1;
    // 0x80800ECC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800ED0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800ED4: jal         0x80082630
    // 0x80800ED8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_35;
    // 0x80800ED8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_35:
    // 0x80800EDC: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x80800EE0: addiu       $t7, $zero, 0xB0
    ctx->r15 = ADD32(0, 0XB0);
    // 0x80800EE4: addiu       $t8, $zero, -0x2
    ctx->r24 = ADD32(0, -0X2);
    // 0x80800EE8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80800EEC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800EF0: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80800EF4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800EF8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800EFC: jal         0x80082630
    // 0x80800F00: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_36;
    // 0x80800F00: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_36:
    // 0x80800F04: lui         $a1, 0x3F3A
    ctx->r5 = S32(0X3F3A << 16);
    // 0x80800F08: addiu       $t9, $zero, 0xB1
    ctx->r25 = ADD32(0, 0XB1);
    // 0x80800F0C: addiu       $t0, $zero, -0x2
    ctx->r8 = ADD32(0, -0X2);
    // 0x80800F10: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80800F14: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800F18: ori         $a1, $a1, 0xE148
    ctx->r5 = ctx->r5 | 0XE148;
    // 0x80800F1C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800F20: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800F24: jal         0x80082630
    // 0x80800F28: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_37;
    // 0x80800F28: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_37:
    // 0x80800F2C: lui         $a1, 0x3F42
    ctx->r5 = S32(0X3F42 << 16);
    // 0x80800F30: addiu       $t1, $zero, 0xB2
    ctx->r9 = ADD32(0, 0XB2);
    // 0x80800F34: addiu       $t2, $zero, -0x2
    ctx->r10 = ADD32(0, -0X2);
    // 0x80800F38: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80800F3C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800F40: ori         $a1, $a1, 0x8F5C
    ctx->r5 = ctx->r5 | 0X8F5C;
    // 0x80800F44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800F48: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800F4C: jal         0x80082630
    // 0x80800F50: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_38;
    // 0x80800F50: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_38:
    // 0x80800F54: b           L_80803378
    // 0x80800F58: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80800F58: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800F5C:
    // 0x80800F5C: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80800F60: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x80800F64: lui         $a1, 0x3E63
    ctx->r5 = S32(0X3E63 << 16);
    // 0x80800F68: addiu       $t3, $zero, 0xAE
    ctx->r11 = ADD32(0, 0XAE);
    // 0x80800F6C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80800F70: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80800F74: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80800F78: ori         $a1, $a1, 0x1F8A
    ctx->r5 = ctx->r5 | 0X1F8A;
    // 0x80800F7C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800F80: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800F84: jal         0x80082630
    // 0x80800F88: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_39;
    // 0x80800F88: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_39:
    // 0x80800F8C: lui         $a1, 0x3EB6
    ctx->r5 = S32(0X3EB6 << 16);
    // 0x80800F90: addiu       $t5, $zero, 0x7D
    ctx->r13 = ADD32(0, 0X7D);
    // 0x80800F94: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80800F98: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80800F9C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80800FA0: ori         $a1, $a1, 0x7A10
    ctx->r5 = ctx->r5 | 0X7A10;
    // 0x80800FA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800FA8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800FAC: jal         0x80082630
    // 0x80800FB0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_40;
    // 0x80800FB0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_40:
    // 0x80800FB4: lui         $a1, 0x3EE6
    ctx->r5 = S32(0X3EE6 << 16);
    // 0x80800FB8: addiu       $t7, $zero, 0xAF
    ctx->r15 = ADD32(0, 0XAF);
    // 0x80800FBC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80800FC0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80800FC4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800FC8: ori         $a1, $a1, 0xC227
    ctx->r5 = ctx->r5 | 0XC227;
    // 0x80800FCC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800FD0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800FD4: jal         0x80082630
    // 0x80800FD8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_41;
    // 0x80800FD8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_41:
    // 0x80800FDC: lui         $a1, 0x3F34
    ctx->r5 = S32(0X3F34 << 16);
    // 0x80800FE0: addiu       $t9, $zero, 0x7E
    ctx->r25 = ADD32(0, 0X7E);
    // 0x80800FE4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80800FE8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80800FEC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800FF0: ori         $a1, $a1, 0x9518
    ctx->r5 = ctx->r5 | 0X9518;
    // 0x80800FF4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800FF8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800FFC: jal         0x80082630
    // 0x80801000: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_42;
    // 0x80801000: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_42:
    // 0x80801004: b           L_80803378
    // 0x80801008: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80801008: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080100C:
    // 0x8080100C: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80801010: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x80801014: lui         $a1, 0x3D40
    ctx->r5 = S32(0X3D40 << 16);
    // 0x80801018: addiu       $t1, $zero, 0x9F
    ctx->r9 = ADD32(0, 0X9F);
    // 0x8080101C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80801020: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80801024: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80801028: ori         $a1, $a1, 0x1A37
    ctx->r5 = ctx->r5 | 0X1A37;
    // 0x8080102C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801030: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801034: jal         0x80082630
    // 0x80801038: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_43;
    // 0x80801038: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_43:
    // 0x8080103C: lui         $a1, 0x3DD3
    ctx->r5 = S32(0X3DD3 << 16);
    // 0x80801040: addiu       $t3, $zero, 0xA0
    ctx->r11 = ADD32(0, 0XA0);
    // 0x80801044: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80801048: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8080104C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80801050: ori         $a1, $a1, 0xC361
    ctx->r5 = ctx->r5 | 0XC361;
    // 0x80801054: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801058: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8080105C: jal         0x80082630
    // 0x80801060: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_44;
    // 0x80801060: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_44:
    // 0x80801064: lui         $a1, 0x3DDB
    ctx->r5 = S32(0X3DDB << 16);
    // 0x80801068: addiu       $t5, $zero, 0x9C
    ctx->r13 = ADD32(0, 0X9C);
    // 0x8080106C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80801070: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80801074: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80801078: ori         $a1, $a1, 0xF488
    ctx->r5 = ctx->r5 | 0XF488;
    // 0x8080107C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801080: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801084: jal         0x80082630
    // 0x80801088: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_45;
    // 0x80801088: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_45:
    // 0x8080108C: lui         $a1, 0x3E50
    ctx->r5 = S32(0X3E50 << 16);
    // 0x80801090: addiu       $t7, $zero, 0xA0
    ctx->r15 = ADD32(0, 0XA0);
    // 0x80801094: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80801098: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8080109C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808010A0: ori         $a1, $a1, 0xCB29
    ctx->r5 = ctx->r5 | 0XCB29;
    // 0x808010A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808010A8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808010AC: jal         0x80082630
    // 0x808010B0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_46;
    // 0x808010B0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_46:
    // 0x808010B4: lui         $a1, 0x3E54
    ctx->r5 = S32(0X3E54 << 16);
    // 0x808010B8: addiu       $t9, $zero, 0x9D
    ctx->r25 = ADD32(0, 0X9D);
    // 0x808010BC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x808010C0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x808010C4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808010C8: ori         $a1, $a1, 0xE3BD
    ctx->r5 = ctx->r5 | 0XE3BD;
    // 0x808010CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808010D0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808010D4: jal         0x80082630
    // 0x808010D8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_47;
    // 0x808010D8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_47:
    // 0x808010DC: lui         $a1, 0x3E9F
    ctx->r5 = S32(0X3E9F << 16);
    // 0x808010E0: addiu       $t1, $zero, 0xA0
    ctx->r9 = ADD32(0, 0XA0);
    // 0x808010E4: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x808010E8: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x808010EC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808010F0: ori         $a1, $a1, 0x8A09
    ctx->r5 = ctx->r5 | 0X8A09;
    // 0x808010F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808010F8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808010FC: jal         0x80082630
    // 0x80801100: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_48;
    // 0x80801100: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_48:
    // 0x80801104: lui         $a1, 0x3EA1
    ctx->r5 = S32(0X3EA1 << 16);
    // 0x80801108: addiu       $t3, $zero, 0x9E
    ctx->r11 = ADD32(0, 0X9E);
    // 0x8080110C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80801110: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80801114: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80801118: ori         $a1, $a1, 0x9653
    ctx->r5 = ctx->r5 | 0X9653;
    // 0x8080111C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801120: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801124: jal         0x80082630
    // 0x80801128: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_49;
    // 0x80801128: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_49:
    // 0x8080112C: lui         $a1, 0x3EE1
    ctx->r5 = S32(0X3EE1 << 16);
    // 0x80801130: addiu       $t5, $zero, 0xA1
    ctx->r13 = ADD32(0, 0XA1);
    // 0x80801134: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80801138: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8080113C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80801140: ori         $a1, $a1, 0xCAC1
    ctx->r5 = ctx->r5 | 0XCAC1;
    // 0x80801144: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801148: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8080114C: jal         0x80082630
    // 0x80801150: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_50;
    // 0x80801150: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_50:
    // 0x80801154: lui         $a1, 0x3EE3
    ctx->r5 = S32(0X3EE3 << 16);
    // 0x80801158: addiu       $t7, $zero, 0x9C
    ctx->r15 = ADD32(0, 0X9C);
    // 0x8080115C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80801160: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80801164: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80801168: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x8080116C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801170: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801174: jal         0x80082630
    // 0x80801178: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_51;
    // 0x80801178: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_51:
    // 0x8080117C: lui         $a1, 0x3F1C
    ctx->r5 = S32(0X3F1C << 16);
    // 0x80801180: addiu       $t9, $zero, 0xA1
    ctx->r25 = ADD32(0, 0XA1);
    // 0x80801184: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80801188: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8080118C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80801190: ori         $a1, $a1, 0xEBF
    ctx->r5 = ctx->r5 | 0XEBF;
    // 0x80801194: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801198: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8080119C: jal         0x80082630
    // 0x808011A0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_52;
    // 0x808011A0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_52:
    // 0x808011A4: lui         $a1, 0x3F1D
    ctx->r5 = S32(0X3F1D << 16);
    // 0x808011A8: addiu       $t1, $zero, 0x9D
    ctx->r9 = ADD32(0, 0X9D);
    // 0x808011AC: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x808011B0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x808011B4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808011B8: ori         $a1, $a1, 0x14E4
    ctx->r5 = ctx->r5 | 0X14E4;
    // 0x808011BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808011C0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808011C4: jal         0x80082630
    // 0x808011C8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_53;
    // 0x808011C8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_53:
    // 0x808011CC: lui         $a1, 0x3F42
    ctx->r5 = S32(0X3F42 << 16);
    // 0x808011D0: addiu       $t3, $zero, 0xA1
    ctx->r11 = ADD32(0, 0XA1);
    // 0x808011D4: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x808011D8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x808011DC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x808011E0: ori         $a1, $a1, 0xB6AE
    ctx->r5 = ctx->r5 | 0XB6AE;
    // 0x808011E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808011E8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808011EC: jal         0x80082630
    // 0x808011F0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_54;
    // 0x808011F0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_54:
    // 0x808011F4: lui         $a1, 0x3F43
    ctx->r5 = S32(0X3F43 << 16);
    // 0x808011F8: addiu       $t5, $zero, 0x9E
    ctx->r13 = ADD32(0, 0X9E);
    // 0x808011FC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80801200: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80801204: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80801208: ori         $a1, $a1, 0xBCD3
    ctx->r5 = ctx->r5 | 0XBCD3;
    // 0x8080120C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801210: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801214: jal         0x80082630
    // 0x80801218: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_55;
    // 0x80801218: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_55:
    // 0x8080121C: lui         $a1, 0x3F67
    ctx->r5 = S32(0X3F67 << 16);
    // 0x80801220: addiu       $t7, $zero, 0xA2
    ctx->r15 = ADD32(0, 0XA2);
    // 0x80801224: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80801228: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8080122C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80801230: ori         $a1, $a1, 0xCED9
    ctx->r5 = ctx->r5 | 0XCED9;
    // 0x80801234: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801238: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8080123C: jal         0x80082630
    // 0x80801240: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_56;
    // 0x80801240: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_56:
    // 0x80801244: lui         $a1, 0x3F68
    ctx->r5 = S32(0X3F68 << 16);
    // 0x80801248: addiu       $t9, $zero, 0x83
    ctx->r25 = ADD32(0, 0X83);
    // 0x8080124C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80801250: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80801254: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80801258: ori         $a1, $a1, 0xD4FE
    ctx->r5 = ctx->r5 | 0XD4FE;
    // 0x8080125C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801260: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801264: jal         0x80082630
    // 0x80801268: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_57;
    // 0x80801268: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_57:
    // 0x8080126C: b           L_80803378
    // 0x80801270: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80801270: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801274:
    // 0x80801274: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80801278: addiu       $s0, $s0, -0x7090
    ctx->r16 = ADD32(ctx->r16, -0X7090);
    // 0x8080127C: lui         $a1, 0x3E67
    ctx->r5 = S32(0X3E67 << 16);
    // 0x80801280: ori         $a1, $a1, 0xA0F9
    ctx->r5 = ctx->r5 | 0XA0F9;
    // 0x80801284: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801288: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x8080128C: jal         0x80082628
    // 0x80801290: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_58;
    // 0x80801290: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_58:
    // 0x80801294: lui         $a1, 0x3F37
    ctx->r5 = S32(0X3F37 << 16);
    // 0x80801298: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8080129C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808012A0: ori         $a1, $a1, 0x6C8B
    ctx->r5 = ctx->r5 | 0X6C8B;
    // 0x808012A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808012A8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808012AC: jal         0x80082628
    // 0x808012B0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_2(rdram, ctx);
        goto after_59;
    // 0x808012B0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_59:
    // 0x808012B4: b           L_80803378
    // 0x808012B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x808012B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808012BC:
    // 0x808012BC: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x808012C0: addiu       $s0, $s0, -0x7090
    ctx->r16 = ADD32(ctx->r16, -0X7090);
    // 0x808012C4: lui         $a1, 0x3E67
    ctx->r5 = S32(0X3E67 << 16);
    // 0x808012C8: ori         $a1, $a1, 0xA0F9
    ctx->r5 = ctx->r5 | 0XA0F9;
    // 0x808012CC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808012D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808012D4: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x808012D8: jal         0x80082628
    // 0x808012DC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_60;
    // 0x808012DC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_60:
    // 0x808012E0: lui         $a1, 0x3F37
    ctx->r5 = S32(0X3F37 << 16);
    // 0x808012E4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x808012E8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808012EC: ori         $a1, $a1, 0x6C8B
    ctx->r5 = ctx->r5 | 0X6C8B;
    // 0x808012F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808012F4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808012F8: jal         0x80082628
    // 0x808012FC: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_2(rdram, ctx);
        goto after_61;
    // 0x808012FC: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_61:
    // 0x80801300: b           L_80803378
    // 0x80801304: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80801304: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801308:
    // 0x80801308: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x8080130C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1732, 0X52B4) << 16);
    // 0x80801310: addiu       $v0, $v0, 0x52B4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1732, 0X52B4));
    // 0x80801314: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x80801318: addiu       $t3, $zero, 0x17
    ctx->r11 = ADD32(0, 0X17);
L_8080131C:
    // 0x8080131C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80801320: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80801324: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80801328: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080132C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80801330: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801334: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x80801338: jal         0x80082630
    // 0x8080133C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_62;
    // 0x8080133C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_62:
    // 0x80801340: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80801344: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(1732, 0X52C0) << 16);
    // 0x80801348: addiu       $t5, $t5, 0x52C0
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(1732, 0X52C0));
    // 0x8080134C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80801350: bnel        $v0, $t5, L_8080131C
    if (ctx->r2 != ctx->r13) {
        // 0x80801354: addiu       $t3, $zero, 0x17
        ctx->r11 = ADD32(0, 0X17);
            goto L_8080131C;
    }
    goto skip_5;
    // 0x80801354: addiu       $t3, $zero, 0x17
    ctx->r11 = ADD32(0, 0X17);
    skip_5:
    // 0x80801358: b           L_80803378
    // 0x8080135C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x8080135C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801360:
    // 0x80801360: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80801364: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x80801368: lui         $a1, 0x3D2D
    ctx->r5 = S32(0X3D2D << 16);
    // 0x8080136C: addiu       $t6, $zero, 0x18
    ctx->r14 = ADD32(0, 0X18);
    // 0x80801370: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80801374: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80801378: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080137C: ori         $a1, $a1, 0x42C4
    ctx->r5 = ctx->r5 | 0X42C4;
    // 0x80801380: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801384: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801388: jal         0x80082630
    // 0x8080138C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_63;
    // 0x8080138C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_63:
    // 0x80801390: lui         $a1, 0x3E32
    ctx->r5 = S32(0X3E32 << 16);
    // 0x80801394: addiu       $t8, $zero, 0x19
    ctx->r24 = ADD32(0, 0X19);
    // 0x80801398: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8080139C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x808013A0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808013A4: ori         $a1, $a1, 0x2D0E
    ctx->r5 = ctx->r5 | 0X2D0E;
    // 0x808013A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808013AC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808013B0: jal         0x80082630
    // 0x808013B4: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_64;
    // 0x808013B4: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_64:
    // 0x808013B8: lui         $a1, 0x3E6A
    ctx->r5 = S32(0X3E6A << 16);
    // 0x808013BC: addiu       $t0, $zero, 0x19
    ctx->r8 = ADD32(0, 0X19);
    // 0x808013C0: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x808013C4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x808013C8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x808013CC: ori         $a1, $a1, 0xB368
    ctx->r5 = ctx->r5 | 0XB368;
    // 0x808013D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808013D4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808013D8: jal         0x80082630
    // 0x808013DC: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_65;
    // 0x808013DC: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_65:
    // 0x808013E0: b           L_80803378
    // 0x808013E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x808013E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808013E8:
    // 0x808013E8: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x808013EC: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x808013F0: lui         $a1, 0x3F2D
    ctx->r5 = S32(0X3F2D << 16);
    // 0x808013F4: addiu       $t2, $zero, 0x1A
    ctx->r10 = ADD32(0, 0X1A);
    // 0x808013F8: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x808013FC: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80801400: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80801404: ori         $a1, $a1, 0xBF48
    ctx->r5 = ctx->r5 | 0XBF48;
    // 0x80801408: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8080140C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801410: jal         0x80082630
    // 0x80801414: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_66;
    // 0x80801414: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_66:
    // 0x80801418: lui         $a1, 0x3F76
    ctx->r5 = S32(0X3F76 << 16);
    // 0x8080141C: addiu       $t4, $zero, 0x1B
    ctx->r12 = ADD32(0, 0X1B);
    // 0x80801420: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80801424: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80801428: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8080142C: ori         $a1, $a1, 0x1134
    ctx->r5 = ctx->r5 | 0X1134;
    // 0x80801430: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801434: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801438: jal         0x80082630
    // 0x8080143C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_67;
    // 0x8080143C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_67:
    // 0x80801440: lui         $a1, 0x3F77
    ctx->r5 = S32(0X3F77 << 16);
    // 0x80801444: addiu       $t6, $zero, 0x19
    ctx->r14 = ADD32(0, 0X19);
    // 0x80801448: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8080144C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80801450: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801454: ori         $a1, $a1, 0x8034
    ctx->r5 = ctx->r5 | 0X8034;
    // 0x80801458: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080145C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801460: jal         0x80082630
    // 0x80801464: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_68;
    // 0x80801464: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_68:
    // 0x80801468: lui         $a1, 0x3F7A
    ctx->r5 = S32(0X3F7A << 16);
    // 0x8080146C: addiu       $t8, $zero, 0x1C
    ctx->r24 = ADD32(0, 0X1C);
    // 0x80801470: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80801474: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80801478: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8080147C: ori         $a1, $a1, 0xE148
    ctx->r5 = ctx->r5 | 0XE148;
    // 0x80801480: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801484: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801488: jal         0x80082630
    // 0x8080148C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_69;
    // 0x8080148C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_69:
    // 0x80801490: b           L_80803378
    // 0x80801494: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80801494: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801498:
    // 0x80801498: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x8080149C: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x808014A0: lui         $a1, 0x3DDF
    ctx->r5 = S32(0X3DDF << 16);
    // 0x808014A4: addiu       $t0, $zero, 0x1D
    ctx->r8 = ADD32(0, 0X1D);
    // 0x808014A8: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x808014AC: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x808014B0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x808014B4: ori         $a1, $a1, 0x3B64
    ctx->r5 = ctx->r5 | 0X3B64;
    // 0x808014B8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808014BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808014C0: jal         0x80082630
    // 0x808014C4: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_70;
    // 0x808014C4: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_70:
    // 0x808014C8: lui         $a1, 0x3E84
    ctx->r5 = S32(0X3E84 << 16);
    // 0x808014CC: addiu       $t2, $zero, 0x19
    ctx->r10 = ADD32(0, 0X19);
    // 0x808014D0: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x808014D4: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x808014D8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808014DC: ori         $a1, $a1, 0xF766
    ctx->r5 = ctx->r5 | 0XF766;
    // 0x808014E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808014E4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808014E8: jal         0x80082630
    // 0x808014EC: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_71;
    // 0x808014EC: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_71:
    // 0x808014F0: lui         $a1, 0x3E69
    ctx->r5 = S32(0X3E69 << 16);
    // 0x808014F4: addiu       $t4, $zero, 0x19
    ctx->r12 = ADD32(0, 0X19);
    // 0x808014F8: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x808014FC: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80801500: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80801504: ori         $a1, $a1, 0x8890
    ctx->r5 = ctx->r5 | 0X8890;
    // 0x80801508: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080150C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801510: jal         0x80082630
    // 0x80801514: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_72;
    // 0x80801514: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_72:
    // 0x80801518: b           L_80803378
    // 0x8080151C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x8080151C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801520:
    // 0x80801520: lui         $a1, 0x3EEB
    ctx->r5 = S32(0X3EEB << 16);
    // 0x80801524: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80801528: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x8080152C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80801530: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80801534: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801538: addiu       $a2, $a2, -0x7068
    ctx->r6 = ADD32(ctx->r6, -0X7068);
    // 0x8080153C: ori         $a1, $a1, 0x1C43
    ctx->r5 = ctx->r5 | 0X1C43;
    // 0x80801540: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801544: jal         0x80082630
    // 0x80801548: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_73;
    // 0x80801548: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_73:
    // 0x8080154C: b           L_80803378
    // 0x80801550: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80801550: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801554:
    // 0x80801554: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80801558: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x8080155C: lui         $a1, 0x3D70
    ctx->r5 = S32(0X3D70 << 16);
    // 0x80801560: addiu       $t8, $zero, 0x90
    ctx->r24 = ADD32(0, 0X90);
    // 0x80801564: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80801568: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8080156C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80801570: ori         $a1, $a1, 0xD845
    ctx->r5 = ctx->r5 | 0XD845;
    // 0x80801574: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801578: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080157C: jal         0x80082630
    // 0x80801580: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_74;
    // 0x80801580: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_74:
    // 0x80801584: lui         $a1, 0x3D81
    ctx->r5 = S32(0X3D81 << 16);
    // 0x80801588: addiu       $t0, $zero, 0x9C
    ctx->r8 = ADD32(0, 0X9C);
    // 0x8080158C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80801590: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80801594: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80801598: ori         $a1, $a1, 0x625
    ctx->r5 = ctx->r5 | 0X625;
    // 0x8080159C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808015A0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808015A4: jal         0x80082630
    // 0x808015A8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_75;
    // 0x808015A8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_75:
    // 0x808015AC: lui         $a1, 0x3E61
    ctx->r5 = S32(0X3E61 << 16);
    // 0x808015B0: addiu       $t2, $zero, 0x90
    ctx->r10 = ADD32(0, 0X90);
    // 0x808015B4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x808015B8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x808015BC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808015C0: ori         $a1, $a1, 0xFF2E
    ctx->r5 = ctx->r5 | 0XFF2E;
    // 0x808015C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808015C8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808015CC: jal         0x80082630
    // 0x808015D0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_76;
    // 0x808015D0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_76:
    // 0x808015D4: lui         $a1, 0x3E67
    ctx->r5 = S32(0X3E67 << 16);
    // 0x808015D8: addiu       $t4, $zero, 0x9E
    ctx->r12 = ADD32(0, 0X9E);
    // 0x808015DC: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x808015E0: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x808015E4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x808015E8: ori         $a1, $a1, 0x6C8B
    ctx->r5 = ctx->r5 | 0X6C8B;
    // 0x808015EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808015F0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808015F4: jal         0x80082630
    // 0x808015F8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_77;
    // 0x808015F8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_77:
    // 0x808015FC: lui         $a1, 0x3EC5
    ctx->r5 = S32(0X3EC5 << 16);
    // 0x80801600: addiu       $t6, $zero, 0x90
    ctx->r14 = ADD32(0, 0X90);
    // 0x80801604: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80801608: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8080160C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801610: ori         $a1, $a1, 0x481
    ctx->r5 = ctx->r5 | 0X481;
    // 0x80801614: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801618: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8080161C: jal         0x80082630
    // 0x80801620: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_78;
    // 0x80801620: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_78:
    // 0x80801624: lui         $a1, 0x3EC7
    ctx->r5 = S32(0X3EC7 << 16);
    // 0x80801628: addiu       $t8, $zero, 0x9D
    ctx->r24 = ADD32(0, 0X9D);
    // 0x8080162C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80801630: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80801634: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80801638: ori         $a1, $a1, 0x2B02
    ctx->r5 = ctx->r5 | 0X2B02;
    // 0x8080163C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801640: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801644: jal         0x80082630
    // 0x80801648: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_79;
    // 0x80801648: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_79:
    // 0x8080164C: lui         $a1, 0x3F0B
    ctx->r5 = S32(0X3F0B << 16);
    // 0x80801650: addiu       $t0, $zero, 0x90
    ctx->r8 = ADD32(0, 0X90);
    // 0x80801654: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80801658: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8080165C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80801660: ori         $a1, $a1, 0x645A
    ctx->r5 = ctx->r5 | 0X645A;
    // 0x80801664: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801668: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8080166C: jal         0x80082630
    // 0x80801670: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_80;
    // 0x80801670: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_80:
    // 0x80801674: lui         $a1, 0x3F0C
    ctx->r5 = S32(0X3F0C << 16);
    // 0x80801678: addiu       $t2, $zero, 0x9C
    ctx->r10 = ADD32(0, 0X9C);
    // 0x8080167C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80801680: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80801684: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80801688: ori         $a1, $a1, 0xAC08
    ctx->r5 = ctx->r5 | 0XAC08;
    // 0x8080168C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801690: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801694: jal         0x80082630
    // 0x80801698: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_81;
    // 0x80801698: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_81:
    // 0x8080169C: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x808016A0: addiu       $t4, $zero, 0x90
    ctx->r12 = ADD32(0, 0X90);
    // 0x808016A4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x808016A8: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x808016AC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x808016B0: ori         $a1, $a1, 0x6113
    ctx->r5 = ctx->r5 | 0X6113;
    // 0x808016B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808016B8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808016BC: jal         0x80082630
    // 0x808016C0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_82;
    // 0x808016C0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_82:
    // 0x808016C4: lui         $a1, 0x3F34
    ctx->r5 = S32(0X3F34 << 16);
    // 0x808016C8: addiu       $t6, $zero, 0x9D
    ctx->r14 = ADD32(0, 0X9D);
    // 0x808016CC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x808016D0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x808016D4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808016D8: ori         $a1, $a1, 0xB5DD
    ctx->r5 = ctx->r5 | 0XB5DD;
    // 0x808016DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808016E0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808016E4: jal         0x80082630
    // 0x808016E8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_83;
    // 0x808016E8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_83:
    // 0x808016EC: lui         $a1, 0x3F62
    ctx->r5 = S32(0X3F62 << 16);
    // 0x808016F0: addiu       $t8, $zero, 0x91
    ctx->r24 = ADD32(0, 0X91);
    // 0x808016F4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x808016F8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x808016FC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80801700: ori         $a1, $a1, 0xFEC5
    ctx->r5 = ctx->r5 | 0XFEC5;
    // 0x80801704: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801708: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8080170C: jal         0x80082630
    // 0x80801710: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_84;
    // 0x80801710: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_84:
    // 0x80801714: lui         $a1, 0x3F64
    ctx->r5 = S32(0X3F64 << 16);
    // 0x80801718: addiu       $t0, $zero, 0x83
    ctx->r8 = ADD32(0, 0X83);
    // 0x8080171C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80801720: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80801724: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80801728: ori         $a1, $a1, 0x4EA
    ctx->r5 = ctx->r5 | 0X4EA;
    // 0x8080172C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801730: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801734: jal         0x80082630
    // 0x80801738: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_85;
    // 0x80801738: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_85:
    // 0x8080173C: b           L_80803378
    // 0x80801740: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80801740: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801744:
    // 0x80801744: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80801748: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1732, 0X52C0) << 16);
    // 0x8080174C: addiu       $v0, $v0, 0x52C0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1732, 0X52C0));
    // 0x80801750: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x80801754: addiu       $t2, $zero, 0x1F
    ctx->r10 = ADD32(0, 0X1F);
L_80801758:
    // 0x80801758: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8080175C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80801760: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80801764: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801768: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8080176C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801770: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x80801774: jal         0x80082630
    // 0x80801778: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    _anseq_entrypoint_3(rdram, ctx);
        goto after_86;
    // 0x80801778: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_86:
    // 0x8080177C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80801780: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(1732, 0X52D8) << 16);
    // 0x80801784: addiu       $t4, $t4, 0x52D8
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(1732, 0X52D8));
    // 0x80801788: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8080178C: bnel        $v0, $t4, L_80801758
    if (ctx->r2 != ctx->r12) {
        // 0x80801790: addiu       $t2, $zero, 0x1F
        ctx->r10 = ADD32(0, 0X1F);
            goto L_80801758;
    }
    goto skip_6;
    // 0x80801790: addiu       $t2, $zero, 0x1F
    ctx->r10 = ADD32(0, 0X1F);
    skip_6:
    // 0x80801794: b           L_80803378
    // 0x80801798: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80801798: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080179C:
    // 0x8080179C: lui         $a1, 0x3D1D
    ctx->r5 = S32(0X3D1D << 16);
    // 0x808017A0: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x808017A4: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x808017A8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x808017AC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x808017B0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x808017B4: addiu       $a2, $a2, -0x7068
    ctx->r6 = ADD32(ctx->r6, -0X7068);
    // 0x808017B8: ori         $a1, $a1, 0x4952
    ctx->r5 = ctx->r5 | 0X4952;
    // 0x808017BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808017C0: jal         0x80082630
    // 0x808017C4: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_87;
    // 0x808017C4: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_87:
    // 0x808017C8: b           L_80803378
    // 0x808017CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x808017CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808017D0:
    // 0x808017D0: lui         $a1, 0x3F4D
    ctx->r5 = S32(0X3F4D << 16);
    // 0x808017D4: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x808017D8: addiu       $t7, $zero, 0x21
    ctx->r15 = ADD32(0, 0X21);
    // 0x808017DC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x808017E0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x808017E4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808017E8: addiu       $a2, $a2, -0x7068
    ctx->r6 = ADD32(ctx->r6, -0X7068);
    // 0x808017EC: ori         $a1, $a1, 0xC5D6
    ctx->r5 = ctx->r5 | 0XC5D6;
    // 0x808017F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808017F4: jal         0x80082630
    // 0x808017F8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_88;
    // 0x808017F8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_88:
    // 0x808017FC: b           L_80803378
    // 0x80801800: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80801800: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801804:
    // 0x80801804: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80801808: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x8080180C: lui         $a1, 0x3E5B
    ctx->r5 = S32(0X3E5B << 16);
    // 0x80801810: addiu       $t9, $zero, 0x93
    ctx->r25 = ADD32(0, 0X93);
    // 0x80801814: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80801818: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8080181C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80801820: ori         $a1, $a1, 0xDA51
    ctx->r5 = ctx->r5 | 0XDA51;
    // 0x80801824: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801828: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080182C: jal         0x80082630
    // 0x80801830: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_89;
    // 0x80801830: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_89:
    // 0x80801834: lui         $a1, 0x3F57
    ctx->r5 = S32(0X3F57 << 16);
    // 0x80801838: addiu       $t1, $zero, 0x94
    ctx->r9 = ADD32(0, 0X94);
    // 0x8080183C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80801840: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80801844: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80801848: ori         $a1, $a1, 0xE282
    ctx->r5 = ctx->r5 | 0XE282;
    // 0x8080184C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801850: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801854: jal         0x80082630
    // 0x80801858: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_90;
    // 0x80801858: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_90:
    // 0x8080185C: b           L_80803378
    // 0x80801860: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80801860: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801864:
    // 0x80801864: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80801868: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x8080186C: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x80801870: addiu       $t3, $zero, 0xA6
    ctx->r11 = ADD32(0, 0XA6);
    // 0x80801874: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80801878: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8080187C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80801880: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80801884: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801888: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080188C: jal         0x80082630
    // 0x80801890: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_91;
    // 0x80801890: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_91:
    // 0x80801894: lui         $a1, 0x3F6A
    ctx->r5 = S32(0X3F6A << 16);
    // 0x80801898: addiu       $t5, $zero, 0x97
    ctx->r13 = ADD32(0, 0X97);
    // 0x8080189C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x808018A0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x808018A4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x808018A8: ori         $a1, $a1, 0x4A8C
    ctx->r5 = ctx->r5 | 0X4A8C;
    // 0x808018AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808018B0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808018B4: jal         0x80082630
    // 0x808018B8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_92;
    // 0x808018B8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_92:
    // 0x808018BC: lui         $a1, 0x3F6A
    ctx->r5 = S32(0X3F6A << 16);
    // 0x808018C0: addiu       $t7, $zero, 0xAA
    ctx->r15 = ADD32(0, 0XAA);
    // 0x808018C4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x808018C8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x808018CC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808018D0: ori         $a1, $a1, 0x4A8C
    ctx->r5 = ctx->r5 | 0X4A8C;
    // 0x808018D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808018D8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808018DC: jal         0x80082630
    // 0x808018E0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_93;
    // 0x808018E0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_93:
    // 0x808018E4: b           L_80803378
    // 0x808018E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x808018E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808018EC:
    // 0x808018EC: lui         $a1, 0x3F2B
    ctx->r5 = S32(0X3F2B << 16);
    // 0x808018F0: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x808018F4: addiu       $t9, $zero, 0x98
    ctx->r25 = ADD32(0, 0X98);
    // 0x808018F8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x808018FC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80801900: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80801904: addiu       $a2, $a2, -0x7068
    ctx->r6 = ADD32(ctx->r6, -0X7068);
    // 0x80801908: ori         $a1, $a1, 0x295F
    ctx->r5 = ctx->r5 | 0X295F;
    // 0x8080190C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801910: jal         0x80082630
    // 0x80801914: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_94;
    // 0x80801914: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_94:
    // 0x80801918: b           L_80803378
    // 0x8080191C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x8080191C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801920:
    // 0x80801920: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80801924: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x80801928: lui         $a1, 0x3F50
    ctx->r5 = S32(0X3F50 << 16);
    // 0x8080192C: addiu       $t1, $zero, 0x99
    ctx->r9 = ADD32(0, 0X99);
    // 0x80801930: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80801934: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80801938: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8080193C: ori         $a1, $a1, 0xFF97
    ctx->r5 = ctx->r5 | 0XFF97;
    // 0x80801940: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801944: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801948: jal         0x80082630
    // 0x8080194C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_95;
    // 0x8080194C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_95:
    // 0x80801950: lui         $a1, 0x3F67
    ctx->r5 = S32(0X3F67 << 16);
    // 0x80801954: addiu       $t3, $zero, 0x99
    ctx->r11 = ADD32(0, 0X99);
    // 0x80801958: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8080195C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80801960: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80801964: ori         $a1, $a1, 0xE910
    ctx->r5 = ctx->r5 | 0XE910;
    // 0x80801968: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080196C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801970: jal         0x80082630
    // 0x80801974: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_96;
    // 0x80801974: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_96:
    // 0x80801978: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x8080197C: addiu       $t5, $zero, 0x99
    ctx->r13 = ADD32(0, 0X99);
    // 0x80801980: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80801984: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80801988: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8080198C: ori         $a1, $a1, 0x4880
    ctx->r5 = ctx->r5 | 0X4880;
    // 0x80801990: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801994: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801998: jal         0x80082630
    // 0x8080199C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_97;
    // 0x8080199C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_97:
    // 0x808019A0: lui         $a1, 0x3E17
    ctx->r5 = S32(0X3E17 << 16);
    // 0x808019A4: addiu       $t7, $zero, 0x99
    ctx->r15 = ADD32(0, 0X99);
    // 0x808019A8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x808019AC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x808019B0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808019B4: ori         $a1, $a1, 0xDBF5
    ctx->r5 = ctx->r5 | 0XDBF5;
    // 0x808019B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808019BC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808019C0: jal         0x80082630
    // 0x808019C4: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_98;
    // 0x808019C4: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_98:
    // 0x808019C8: lui         $a1, 0x3E82
    ctx->r5 = S32(0X3E82 << 16);
    // 0x808019CC: addiu       $t9, $zero, 0x99
    ctx->r25 = ADD32(0, 0X99);
    // 0x808019D0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x808019D4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x808019D8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808019DC: ori         $a1, $a1, 0x339C
    ctx->r5 = ctx->r5 | 0X339C;
    // 0x808019E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808019E4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808019E8: jal         0x80082630
    // 0x808019EC: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_99;
    // 0x808019EC: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_99:
    // 0x808019F0: b           L_80803378
    // 0x808019F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x808019F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808019F8:
    // 0x808019F8: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x808019FC: addiu       $s0, $s0, -0x7090
    ctx->r16 = ADD32(ctx->r16, -0X7090);
    // 0x80801A00: lui         $a1, 0x3D63
    ctx->r5 = S32(0X3D63 << 16);
    // 0x80801A04: ori         $a1, $a1, 0xBCD3
    ctx->r5 = ctx->r5 | 0XBCD3;
    // 0x80801A08: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801A0C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801A10: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x80801A14: jal         0x80082628
    // 0x80801A18: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_100;
    // 0x80801A18: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_100:
    // 0x80801A1C: lui         $a1, 0x3F0F
    ctx->r5 = S32(0X3F0F << 16);
    // 0x80801A20: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80801A24: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80801A28: ori         $a1, $a1, 0x34D7
    ctx->r5 = ctx->r5 | 0X34D7;
    // 0x80801A2C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801A30: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801A34: jal         0x80082628
    // 0x80801A38: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_2(rdram, ctx);
        goto after_101;
    // 0x80801A38: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_101:
    // 0x80801A3C: b           L_80803378
    // 0x80801A40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80801A40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801A44:
    // 0x80801A44: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80801A48: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x80801A4C: lui         $a1, 0x3E06
    ctx->r5 = S32(0X3E06 << 16);
    // 0x80801A50: addiu       $t2, $zero, 0x22
    ctx->r10 = ADD32(0, 0X22);
    // 0x80801A54: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80801A58: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80801A5C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80801A60: ori         $a1, $a1, 0x594B
    ctx->r5 = ctx->r5 | 0X594B;
    // 0x80801A64: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801A68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801A6C: jal         0x80082630
    // 0x80801A70: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_102;
    // 0x80801A70: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_102:
    // 0x80801A74: lui         $a1, 0x3E24
    ctx->r5 = S32(0X3E24 << 16);
    // 0x80801A78: addiu       $t4, $zero, 0x22
    ctx->r12 = ADD32(0, 0X22);
    // 0x80801A7C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80801A80: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80801A84: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80801A88: ori         $a1, $a1, 0xB78
    ctx->r5 = ctx->r5 | 0XB78;
    // 0x80801A8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801A90: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801A94: jal         0x80082630
    // 0x80801A98: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_103;
    // 0x80801A98: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_103:
    // 0x80801A9C: lui         $a1, 0x3E5E
    ctx->r5 = S32(0X3E5E << 16);
    // 0x80801AA0: addiu       $t6, $zero, 0x22
    ctx->r14 = ADD32(0, 0X22);
    // 0x80801AA4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80801AA8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80801AAC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801AB0: ori         $a1, $a1, 0x69AD
    ctx->r5 = ctx->r5 | 0X69AD;
    // 0x80801AB4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801AB8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801ABC: jal         0x80082630
    // 0x80801AC0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_104;
    // 0x80801AC0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_104:
    // 0x80801AC4: lui         $a1, 0x3E6C
    ctx->r5 = S32(0X3E6C << 16);
    // 0x80801AC8: addiu       $t8, $zero, 0x5B
    ctx->r24 = ADD32(0, 0X5B);
    // 0x80801ACC: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80801AD0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80801AD4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80801AD8: ori         $a1, $a1, 0x2268
    ctx->r5 = ctx->r5 | 0X2268;
    // 0x80801ADC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801AE0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801AE4: jal         0x80082630
    // 0x80801AE8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_105;
    // 0x80801AE8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_105:
    // 0x80801AEC: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    // 0x80801AF0: addiu       $t0, $zero, 0x22
    ctx->r8 = ADD32(0, 0X22);
    // 0x80801AF4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80801AF8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80801AFC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80801B00: ori         $a1, $a1, 0x9D49
    ctx->r5 = ctx->r5 | 0X9D49;
    // 0x80801B04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801B08: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801B0C: jal         0x80082630
    // 0x80801B10: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_106;
    // 0x80801B10: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_106:
    // 0x80801B14: lui         $a1, 0x3E83
    ctx->r5 = S32(0X3E83 << 16);
    // 0x80801B18: addiu       $t2, $zero, 0x22
    ctx->r10 = ADD32(0, 0X22);
    // 0x80801B1C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80801B20: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80801B24: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80801B28: ori         $a1, $a1, 0xFE5D
    ctx->r5 = ctx->r5 | 0XFE5D;
    // 0x80801B2C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801B30: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801B34: jal         0x80082630
    // 0x80801B38: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_107;
    // 0x80801B38: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_107:
    // 0x80801B3C: lui         $a1, 0x3E8B
    ctx->r5 = S32(0X3E8B << 16);
    // 0x80801B40: addiu       $t4, $zero, 0x5B
    ctx->r12 = ADD32(0, 0X5B);
    // 0x80801B44: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80801B48: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80801B4C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80801B50: ori         $a1, $a1, 0x851F
    ctx->r5 = ctx->r5 | 0X851F;
    // 0x80801B54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801B58: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801B5C: jal         0x80082630
    // 0x80801B60: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_108;
    // 0x80801B60: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_108:
    // 0x80801B64: lui         $a1, 0x3E90
    ctx->r5 = S32(0X3E90 << 16);
    // 0x80801B68: addiu       $t6, $zero, 0x22
    ctx->r14 = ADD32(0, 0X22);
    // 0x80801B6C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80801B70: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80801B74: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801B78: ori         $a1, $a1, 0xBE0E
    ctx->r5 = ctx->r5 | 0XBE0E;
    // 0x80801B7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801B80: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801B84: jal         0x80082630
    // 0x80801B88: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_109;
    // 0x80801B88: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_109:
    // 0x80801B8C: lui         $a1, 0x3E95
    ctx->r5 = S32(0X3E95 << 16);
    // 0x80801B90: addiu       $t8, $zero, 0x22
    ctx->r24 = ADD32(0, 0X22);
    // 0x80801B94: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80801B98: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80801B9C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80801BA0: ori         $a1, $a1, 0x2546
    ctx->r5 = ctx->r5 | 0X2546;
    // 0x80801BA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801BA8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801BAC: jal         0x80082630
    // 0x80801BB0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_110;
    // 0x80801BB0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_110:
    // 0x80801BB4: lui         $a1, 0x3E96
    ctx->r5 = S32(0X3E96 << 16);
    // 0x80801BB8: addiu       $t0, $zero, 0x22
    ctx->r8 = ADD32(0, 0X22);
    // 0x80801BBC: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80801BC0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80801BC4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80801BC8: ori         $a1, $a1, 0xF007
    ctx->r5 = ctx->r5 | 0XF007;
    // 0x80801BCC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801BD0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801BD4: jal         0x80082630
    // 0x80801BD8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_111;
    // 0x80801BD8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_111:
    // 0x80801BDC: lui         $a1, 0x3E9F
    ctx->r5 = S32(0X3E9F << 16);
    // 0x80801BE0: addiu       $t2, $zero, 0x5B
    ctx->r10 = ADD32(0, 0X5B);
    // 0x80801BE4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80801BE8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80801BEC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80801BF0: ori         $a1, $a1, 0x2E49
    ctx->r5 = ctx->r5 | 0X2E49;
    // 0x80801BF4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801BF8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801BFC: jal         0x80082630
    // 0x80801C00: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_112;
    // 0x80801C00: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_112:
    // 0x80801C04: lui         $a1, 0x3EA2
    ctx->r5 = S32(0X3EA2 << 16);
    // 0x80801C08: addiu       $t4, $zero, 0x22
    ctx->r12 = ADD32(0, 0X22);
    // 0x80801C0C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80801C10: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80801C14: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80801C18: ori         $a1, $a1, 0x9C78
    ctx->r5 = ctx->r5 | 0X9C78;
    // 0x80801C1C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801C20: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801C24: jal         0x80082630
    // 0x80801C28: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_113;
    // 0x80801C28: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_113:
    // 0x80801C2C: lui         $a1, 0x3EAF
    ctx->r5 = S32(0X3EAF << 16);
    // 0x80801C30: addiu       $t6, $zero, 0x22
    ctx->r14 = ADD32(0, 0X22);
    // 0x80801C34: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80801C38: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80801C3C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801C40: ori         $a1, $a1, 0xC505
    ctx->r5 = ctx->r5 | 0XC505;
    // 0x80801C44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801C48: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801C4C: jal         0x80082630
    // 0x80801C50: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_114;
    // 0x80801C50: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_114:
    // 0x80801C54: lui         $a1, 0x3EB5
    ctx->r5 = S32(0X3EB5 << 16);
    // 0x80801C58: addiu       $t8, $zero, 0x22
    ctx->r24 = ADD32(0, 0X22);
    // 0x80801C5C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80801C60: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80801C64: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80801C68: ori         $a1, $a1, 0x3261
    ctx->r5 = ctx->r5 | 0X3261;
    // 0x80801C6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801C70: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801C74: jal         0x80082630
    // 0x80801C78: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_115;
    // 0x80801C78: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_115:
    // 0x80801C7C: lui         $a1, 0x3EC1
    ctx->r5 = S32(0X3EC1 << 16);
    // 0x80801C80: addiu       $t0, $zero, 0x5B
    ctx->r8 = ADD32(0, 0X5B);
    // 0x80801C84: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80801C88: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80801C8C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80801C90: ori         $a1, $a1, 0x8937
    ctx->r5 = ctx->r5 | 0X8937;
    // 0x80801C94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801C98: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801C9C: jal         0x80082630
    // 0x80801CA0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_116;
    // 0x80801CA0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_116:
    // 0x80801CA4: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x80801CA8: addiu       $t2, $zero, 0x22
    ctx->r10 = ADD32(0, 0X22);
    // 0x80801CAC: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80801CB0: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80801CB4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80801CB8: ori         $a1, $a1, 0xF41F
    ctx->r5 = ctx->r5 | 0XF41F;
    // 0x80801CBC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801CC0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801CC4: jal         0x80082630
    // 0x80801CC8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_117;
    // 0x80801CC8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_117:
    // 0x80801CCC: lui         $a1, 0x3ED4
    ctx->r5 = S32(0X3ED4 << 16);
    // 0x80801CD0: addiu       $t4, $zero, 0x22
    ctx->r12 = ADD32(0, 0X22);
    // 0x80801CD4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80801CD8: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80801CDC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80801CE0: ori         $a1, $a1, 0xAF4F
    ctx->r5 = ctx->r5 | 0XAF4F;
    // 0x80801CE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801CE8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801CEC: jal         0x80082630
    // 0x80801CF0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_118;
    // 0x80801CF0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_118:
    // 0x80801CF4: b           L_80803378
    // 0x80801CF8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80801CF8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801CFC:
    // 0x80801CFC: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80801D00: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x80801D04: lui         $a1, 0x3E7B
    ctx->r5 = S32(0X3E7B << 16);
    // 0x80801D08: addiu       $t6, $zero, 0x22
    ctx->r14 = ADD32(0, 0X22);
    // 0x80801D0C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80801D10: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80801D14: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801D18: ori         $a1, $a1, 0x7E91
    ctx->r5 = ctx->r5 | 0X7E91;
    // 0x80801D1C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801D20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801D24: jal         0x80082630
    // 0x80801D28: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_119;
    // 0x80801D28: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_119:
    // 0x80801D2C: lui         $a1, 0x3E85
    ctx->r5 = S32(0X3E85 << 16);
    // 0x80801D30: addiu       $t8, $zero, 0x22
    ctx->r24 = ADD32(0, 0X22);
    // 0x80801D34: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80801D38: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80801D3C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80801D40: ori         $a1, $a1, 0xC91D
    ctx->r5 = ctx->r5 | 0XC91D;
    // 0x80801D44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801D48: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801D4C: jal         0x80082630
    // 0x80801D50: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_120;
    // 0x80801D50: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_120:
    // 0x80801D54: lui         $a1, 0x3E88
    ctx->r5 = S32(0X3E88 << 16);
    // 0x80801D58: addiu       $t0, $zero, 0x22
    ctx->r8 = ADD32(0, 0X22);
    // 0x80801D5C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80801D60: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80801D64: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80801D68: ori         $a1, $a1, 0x6595
    ctx->r5 = ctx->r5 | 0X6595;
    // 0x80801D6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801D70: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801D74: jal         0x80082630
    // 0x80801D78: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_121;
    // 0x80801D78: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_121:
    // 0x80801D7C: lui         $a1, 0x3E8E
    ctx->r5 = S32(0X3E8E << 16);
    // 0x80801D80: addiu       $t2, $zero, 0x5B
    ctx->r10 = ADD32(0, 0X5B);
    // 0x80801D84: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80801D88: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80801D8C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80801D90: ori         $a1, $a1, 0x2EB2
    ctx->r5 = ctx->r5 | 0X2EB2;
    // 0x80801D94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801D98: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801D9C: jal         0x80082630
    // 0x80801DA0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_122;
    // 0x80801DA0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_122:
    // 0x80801DA4: lui         $a1, 0x3E93
    ctx->r5 = S32(0X3E93 << 16);
    // 0x80801DA8: addiu       $t4, $zero, 0x22
    ctx->r12 = ADD32(0, 0X22);
    // 0x80801DAC: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80801DB0: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80801DB4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80801DB8: ori         $a1, $a1, 0x9C0F
    ctx->r5 = ctx->r5 | 0X9C0F;
    // 0x80801DBC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801DC0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801DC4: jal         0x80082630
    // 0x80801DC8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_123;
    // 0x80801DC8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_123:
    // 0x80801DCC: lui         $a1, 0x3E97
    ctx->r5 = S32(0X3E97 << 16);
    // 0x80801DD0: addiu       $t6, $zero, 0x22
    ctx->r14 = ADD32(0, 0X22);
    // 0x80801DD4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80801DD8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80801DDC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801DE0: ori         $a1, $a1, 0xCED9
    ctx->r5 = ctx->r5 | 0XCED9;
    // 0x80801DE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801DE8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801DEC: jal         0x80082630
    // 0x80801DF0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_124;
    // 0x80801DF0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_124:
    // 0x80801DF4: lui         $a1, 0x3EA0
    ctx->r5 = S32(0X3EA0 << 16);
    // 0x80801DF8: addiu       $t8, $zero, 0x5B
    ctx->r24 = ADD32(0, 0X5B);
    // 0x80801DFC: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80801E00: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80801E04: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80801E08: ori         $a1, $a1, 0xD1B7
    ctx->r5 = ctx->r5 | 0XD1B7;
    // 0x80801E0C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801E10: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801E14: jal         0x80082630
    // 0x80801E18: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_125;
    // 0x80801E18: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_125:
    // 0x80801E1C: lui         $a1, 0x3EB2
    ctx->r5 = S32(0X3EB2 << 16);
    // 0x80801E20: addiu       $t0, $zero, 0x22
    ctx->r8 = ADD32(0, 0X22);
    // 0x80801E24: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80801E28: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80801E2C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80801E30: ori         $a1, $a1, 0x2D0E
    ctx->r5 = ctx->r5 | 0X2D0E;
    // 0x80801E34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801E38: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801E3C: jal         0x80082630
    // 0x80801E40: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_126;
    // 0x80801E40: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_126:
    // 0x80801E44: lui         $a1, 0x3EBB
    ctx->r5 = S32(0X3EBB << 16);
    // 0x80801E48: addiu       $t2, $zero, 0x5B
    ctx->r10 = ADD32(0, 0X5B);
    // 0x80801E4C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80801E50: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80801E54: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80801E58: ori         $a1, $a1, 0xCD36
    ctx->r5 = ctx->r5 | 0XCD36;
    // 0x80801E5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801E60: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801E64: jal         0x80082630
    // 0x80801E68: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_127;
    // 0x80801E68: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_127:
    // 0x80801E6C: lui         $a1, 0x3EC8
    ctx->r5 = S32(0X3EC8 << 16);
    // 0x80801E70: addiu       $t4, $zero, 0x22
    ctx->r12 = ADD32(0, 0X22);
    // 0x80801E74: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80801E78: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80801E7C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80801E80: ori         $a1, $a1, 0x16F0
    ctx->r5 = ctx->r5 | 0X16F0;
    // 0x80801E84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801E88: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801E8C: jal         0x80082630
    // 0x80801E90: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_128;
    // 0x80801E90: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_128:
    // 0x80801E94: lui         $a1, 0x3ECF
    ctx->r5 = S32(0X3ECF << 16);
    // 0x80801E98: addiu       $t6, $zero, 0x22
    ctx->r14 = ADD32(0, 0X22);
    // 0x80801E9C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80801EA0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80801EA4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801EA8: ori         $a1, $a1, 0x7660
    ctx->r5 = ctx->r5 | 0X7660;
    // 0x80801EAC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801EB0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801EB4: jal         0x80082630
    // 0x80801EB8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_129;
    // 0x80801EB8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_129:
    // 0x80801EBC: b           L_80803378
    // 0x80801EC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80801EC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801EC4:
    // 0x80801EC4: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80801EC8: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x80801ECC: lui         $a1, 0x3F22
    ctx->r5 = S32(0X3F22 << 16);
    // 0x80801ED0: addiu       $t8, $zero, 0x27
    ctx->r24 = ADD32(0, 0X27);
    // 0x80801ED4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80801ED8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80801EDC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80801EE0: ori         $a1, $a1, 0x12D7
    ctx->r5 = ctx->r5 | 0X12D7;
    // 0x80801EE4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801EE8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801EEC: jal         0x80082630
    // 0x80801EF0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_130;
    // 0x80801EF0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_130:
    // 0x80801EF4: lui         $a1, 0x3F2E
    ctx->r5 = S32(0X3F2E << 16);
    // 0x80801EF8: addiu       $t0, $zero, 0x27
    ctx->r8 = ADD32(0, 0X27);
    // 0x80801EFC: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80801F00: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80801F04: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80801F08: ori         $a1, $a1, 0x8A72
    ctx->r5 = ctx->r5 | 0X8A72;
    // 0x80801F0C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801F10: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801F14: jal         0x80082630
    // 0x80801F18: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_131;
    // 0x80801F18: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_131:
    // 0x80801F1C: lui         $a1, 0x3F38
    ctx->r5 = S32(0X3F38 << 16);
    // 0x80801F20: addiu       $t2, $zero, 0x27
    ctx->r10 = ADD32(0, 0X27);
    // 0x80801F24: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80801F28: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80801F2C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80801F30: ori         $a1, $a1, 0xC155
    ctx->r5 = ctx->r5 | 0XC155;
    // 0x80801F34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801F38: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801F3C: jal         0x80082630
    // 0x80801F40: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_132;
    // 0x80801F40: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_132:
    // 0x80801F44: lui         $a1, 0x3F38
    ctx->r5 = S32(0X3F38 << 16);
    // 0x80801F48: addiu       $t4, $zero, 0x27
    ctx->r12 = ADD32(0, 0X27);
    // 0x80801F4C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80801F50: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80801F54: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80801F58: ori         $a1, $a1, 0xC155
    ctx->r5 = ctx->r5 | 0XC155;
    // 0x80801F5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801F60: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801F64: jal         0x80082630
    // 0x80801F68: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_133;
    // 0x80801F68: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_133:
    // 0x80801F6C: b           L_80803378
    // 0x80801F70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80801F70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801F74:
    // 0x80801F74: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80801F78: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x80801F7C: lui         $a1, 0x3F32
    ctx->r5 = S32(0X3F32 << 16);
    // 0x80801F80: addiu       $t6, $zero, 0x29
    ctx->r14 = ADD32(0, 0X29);
    // 0x80801F84: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80801F88: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80801F8C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801F90: ori         $a1, $a1, 0x40B8
    ctx->r5 = ctx->r5 | 0X40B8;
    // 0x80801F94: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801F98: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801F9C: jal         0x80082630
    // 0x80801FA0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_134;
    // 0x80801FA0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_134:
    // 0x80801FA4: lui         $a1, 0x3F7D
    ctx->r5 = S32(0X3F7D << 16);
    // 0x80801FA8: addiu       $t8, $zero, 0x2B
    ctx->r24 = ADD32(0, 0X2B);
    // 0x80801FAC: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80801FB0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80801FB4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80801FB8: ori         $a1, $a1, 0x70A4
    ctx->r5 = ctx->r5 | 0X70A4;
    // 0x80801FBC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801FC0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801FC4: jal         0x80082630
    // 0x80801FC8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_135;
    // 0x80801FC8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_135:
    // 0x80801FCC: b           L_80803378
    // 0x80801FD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80801FD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801FD4:
    // 0x80801FD4: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80801FD8: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x80801FDC: addiu       $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
    // 0x80801FE0: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80801FE4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80801FE8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80801FEC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801FF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801FF4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80801FF8: jal         0x80082630
    // 0x80801FFC: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_136;
    // 0x80801FFC: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_136:
    // 0x80802000: lui         $a1, 0x3EB3
    ctx->r5 = S32(0X3EB3 << 16);
    // 0x80802004: addiu       $t2, $zero, 0x2D
    ctx->r10 = ADD32(0, 0X2D);
    // 0x80802008: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8080200C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80802010: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80802014: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80802018: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080201C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802020: jal         0x80082630
    // 0x80802024: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_137;
    // 0x80802024: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_137:
    // 0x80802028: lui         $a1, 0x3EDF
    ctx->r5 = S32(0X3EDF << 16);
    // 0x8080202C: addiu       $t4, $zero, 0x2E
    ctx->r12 = ADD32(0, 0X2E);
    // 0x80802030: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80802034: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80802038: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8080203C: ori         $a1, $a1, 0x62B7
    ctx->r5 = ctx->r5 | 0X62B7;
    // 0x80802040: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802044: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802048: jal         0x80082630
    // 0x8080204C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_138;
    // 0x8080204C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_138:
    // 0x80802050: lui         $a1, 0x3F4A
    ctx->r5 = S32(0X3F4A << 16);
    // 0x80802054: addiu       $t6, $zero, 0x30
    ctx->r14 = ADD32(0, 0X30);
    // 0x80802058: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8080205C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80802060: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80802064: ori         $a1, $a1, 0x8C15
    ctx->r5 = ctx->r5 | 0X8C15;
    // 0x80802068: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080206C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802070: jal         0x80082630
    // 0x80802074: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_139;
    // 0x80802074: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_139:
    // 0x80802078: b           L_80803378
    // 0x8080207C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x8080207C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80802080:
    // 0x80802080: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80802084: addiu       $s0, $s0, -0x7090
    ctx->r16 = ADD32(ctx->r16, -0X7090);
    // 0x80802088: lui         $a1, 0x3F1D
    ctx->r5 = S32(0X3F1D << 16);
    // 0x8080208C: ori         $a1, $a1, 0xFA44
    ctx->r5 = ctx->r5 | 0XFA44;
    // 0x80802090: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802094: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802098: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x8080209C: jal         0x80082628
    // 0x808020A0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_140;
    // 0x808020A0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_140:
    // 0x808020A4: lui         $a1, 0x3D77
    ctx->r5 = S32(0X3D77 << 16);
    // 0x808020A8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808020AC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808020B0: ori         $a1, $a1, 0x65FE
    ctx->r5 = ctx->r5 | 0X65FE;
    // 0x808020B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808020B8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808020BC: jal         0x80082628
    // 0x808020C0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_2(rdram, ctx);
        goto after_141;
    // 0x808020C0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_141:
    // 0x808020C4: b           L_80803378
    // 0x808020C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x808020C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808020CC:
    // 0x808020CC: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x808020D0: addiu       $s0, $s0, -0x7090
    ctx->r16 = ADD32(ctx->r16, -0X7090);
    // 0x808020D4: lui         $a1, 0x3F1D
    ctx->r5 = S32(0X3F1D << 16);
    // 0x808020D8: ori         $a1, $a1, 0xFA44
    ctx->r5 = ctx->r5 | 0XFA44;
    // 0x808020DC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808020E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808020E4: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x808020E8: jal         0x80082628
    // 0x808020EC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_142;
    // 0x808020EC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_142:
    // 0x808020F0: lui         $a1, 0x3D77
    ctx->r5 = S32(0X3D77 << 16);
    // 0x808020F4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x808020F8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808020FC: ori         $a1, $a1, 0x65FE
    ctx->r5 = ctx->r5 | 0X65FE;
    // 0x80802100: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802104: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802108: jal         0x80082628
    // 0x8080210C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_2(rdram, ctx);
        goto after_143;
    // 0x8080210C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_143:
    // 0x80802110: b           L_80803378
    // 0x80802114: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80802114: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80802118:
    // 0x80802118: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x8080211C: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x80802120: lui         $a1, 0x3E71
    ctx->r5 = S32(0X3E71 << 16);
    // 0x80802124: addiu       $t0, $zero, 0x35
    ctx->r8 = ADD32(0, 0X35);
    // 0x80802128: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8080212C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80802130: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80802134: ori         $a1, $a1, 0xF8A1
    ctx->r5 = ctx->r5 | 0XF8A1;
    // 0x80802138: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8080213C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802140: jal         0x80082630
    // 0x80802144: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_144;
    // 0x80802144: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_144:
    // 0x80802148: lui         $a1, 0x3E71
    ctx->r5 = S32(0X3E71 << 16);
    // 0x8080214C: addiu       $t2, $zero, 0x5C
    ctx->r10 = ADD32(0, 0X5C);
    // 0x80802150: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80802154: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80802158: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8080215C: ori         $a1, $a1, 0xF8A1
    ctx->r5 = ctx->r5 | 0XF8A1;
    // 0x80802160: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802164: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802168: jal         0x80082630
    // 0x8080216C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_145;
    // 0x8080216C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_145:
    // 0x80802170: b           L_80803378
    // 0x80802174: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80802174: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80802178:
    // 0x80802178: lui         $a1, 0x3F3C
    ctx->r5 = S32(0X3F3C << 16);
    // 0x8080217C: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80802180: addiu       $t4, $zero, 0x36
    ctx->r12 = ADD32(0, 0X36);
    // 0x80802184: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80802188: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8080218C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80802190: addiu       $a2, $a2, -0x7068
    ctx->r6 = ADD32(ctx->r6, -0X7068);
    // 0x80802194: ori         $a1, $a1, 0xEBF
    ctx->r5 = ctx->r5 | 0XEBF;
    // 0x80802198: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080219C: jal         0x80082630
    // 0x808021A0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_146;
    // 0x808021A0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_146:
    // 0x808021A4: b           L_80803378
    // 0x808021A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x808021A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808021AC:
    // 0x808021AC: lui         $a1, 0x3F26
    ctx->r5 = S32(0X3F26 << 16);
    // 0x808021B0: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x808021B4: addiu       $t6, $zero, 0x37
    ctx->r14 = ADD32(0, 0X37);
    // 0x808021B8: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x808021BC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x808021C0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808021C4: addiu       $a2, $a2, -0x7068
    ctx->r6 = ADD32(ctx->r6, -0X7068);
    // 0x808021C8: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x808021CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808021D0: jal         0x80082630
    // 0x808021D4: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_147;
    // 0x808021D4: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_147:
    // 0x808021D8: b           L_80803378
    // 0x808021DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x808021DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808021E0:
    // 0x808021E0: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x808021E4: addiu       $t8, $zero, 0x38
    ctx->r24 = ADD32(0, 0X38);
    // 0x808021E8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x808021EC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x808021F0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808021F4: addiu       $a2, $a2, -0x7068
    ctx->r6 = ADD32(ctx->r6, -0X7068);
    // 0x808021F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808021FC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80802200: jal         0x80082630
    // 0x80802204: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_148;
    // 0x80802204: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_148:
    // 0x80802208: b           L_80803378
    // 0x8080220C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x8080220C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80802210:
    // 0x80802210: lui         $a1, 0x3DC7
    ctx->r5 = S32(0X3DC7 << 16);
    // 0x80802214: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80802218: addiu       $t0, $zero, 0x39
    ctx->r8 = ADD32(0, 0X39);
    // 0x8080221C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80802220: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80802224: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80802228: addiu       $a2, $a2, -0x7068
    ctx->r6 = ADD32(ctx->r6, -0X7068);
    // 0x8080222C: ori         $a1, $a1, 0xE282
    ctx->r5 = ctx->r5 | 0XE282;
    // 0x80802230: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802234: jal         0x80082630
    // 0x80802238: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_149;
    // 0x80802238: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_149:
    // 0x8080223C: b           L_80803378
    // 0x80802240: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80802240: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80802244:
    // 0x80802244: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80802248: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x8080224C: lui         $a1, 0x3F0D
    ctx->r5 = S32(0X3F0D << 16);
    // 0x80802250: addiu       $t2, $zero, 0x3A
    ctx->r10 = ADD32(0, 0X3A);
    // 0x80802254: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80802258: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8080225C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80802260: ori         $a1, $a1, 0x42C4
    ctx->r5 = ctx->r5 | 0X42C4;
    // 0x80802264: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802268: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080226C: jal         0x80082630
    // 0x80802270: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_150;
    // 0x80802270: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_150:
    // 0x80802274: lui         $a1, 0x3F20
    ctx->r5 = S32(0X3F20 << 16);
    // 0x80802278: addiu       $t4, $zero, 0x3A
    ctx->r12 = ADD32(0, 0X3A);
    // 0x8080227C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80802280: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80802284: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80802288: ori         $a1, $a1, 0xF909
    ctx->r5 = ctx->r5 | 0XF909;
    // 0x8080228C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802290: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802294: jal         0x80082630
    // 0x80802298: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_151;
    // 0x80802298: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_151:
    // 0x8080229C: lui         $a1, 0x3F35
    ctx->r5 = S32(0X3F35 << 16);
    // 0x808022A0: addiu       $t6, $zero, 0x3A
    ctx->r14 = ADD32(0, 0X3A);
    // 0x808022A4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x808022A8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x808022AC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808022B0: ori         $a1, $a1, 0x6D5D
    ctx->r5 = ctx->r5 | 0X6D5D;
    // 0x808022B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808022B8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808022BC: jal         0x80082630
    // 0x808022C0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_152;
    // 0x808022C0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_152:
    // 0x808022C4: lui         $a1, 0x3F6A
    ctx->r5 = S32(0X3F6A << 16);
    // 0x808022C8: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x808022CC: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x808022D0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x808022D4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808022D8: ori         $a1, $a1, 0x29C7
    ctx->r5 = ctx->r5 | 0X29C7;
    // 0x808022DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808022E0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808022E4: jal         0x80082630
    // 0x808022E8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_153;
    // 0x808022E8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_153:
    // 0x808022EC: b           L_80803378
    // 0x808022F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x808022F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808022F4:
    // 0x808022F4: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x808022F8: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x808022FC: lui         $a1, 0x3EB8
    ctx->r5 = S32(0X3EB8 << 16);
    // 0x80802300: addiu       $t0, $zero, 0x3B
    ctx->r8 = ADD32(0, 0X3B);
    // 0x80802304: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80802308: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8080230C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80802310: ori         $a1, $a1, 0xADAC
    ctx->r5 = ctx->r5 | 0XADAC;
    // 0x80802314: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802318: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080231C: jal         0x80082630
    // 0x80802320: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_154;
    // 0x80802320: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_154:
    // 0x80802324: lui         $a1, 0x3F2F
    ctx->r5 = S32(0X3F2F << 16);
    // 0x80802328: addiu       $t2, $zero, 0x3D
    ctx->r10 = ADD32(0, 0X3D);
    // 0x8080232C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80802330: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80802334: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80802338: ori         $a1, $a1, 0x6FD2
    ctx->r5 = ctx->r5 | 0X6FD2;
    // 0x8080233C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802340: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802344: jal         0x80082630
    // 0x80802348: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_155;
    // 0x80802348: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_155:
    // 0x8080234C: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    // 0x80802350: addiu       $t4, $zero, 0x3D
    ctx->r12 = ADD32(0, 0X3D);
    // 0x80802354: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80802358: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8080235C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80802360: ori         $a1, $a1, 0x13A9
    ctx->r5 = ctx->r5 | 0X13A9;
    // 0x80802364: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802368: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8080236C: jal         0x80082630
    // 0x80802370: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_156;
    // 0x80802370: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_156:
    // 0x80802374: lui         $a1, 0x3F4E
    ctx->r5 = S32(0X3F4E << 16);
    // 0x80802378: addiu       $t6, $zero, 0x3D
    ctx->r14 = ADD32(0, 0X3D);
    // 0x8080237C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80802380: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80802384: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80802388: ori         $a1, $a1, 0x147B
    ctx->r5 = ctx->r5 | 0X147B;
    // 0x8080238C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802390: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802394: jal         0x80082630
    // 0x80802398: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_157;
    // 0x80802398: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_157:
    // 0x8080239C: b           L_80803378
    // 0x808023A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x808023A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808023A4:
    // 0x808023A4: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x808023A8: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x808023AC: lui         $a1, 0x3EB8
    ctx->r5 = S32(0X3EB8 << 16);
    // 0x808023B0: addiu       $t8, $zero, 0x3B
    ctx->r24 = ADD32(0, 0X3B);
    // 0x808023B4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x808023B8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x808023BC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808023C0: ori         $a1, $a1, 0xADAC
    ctx->r5 = ctx->r5 | 0XADAC;
    // 0x808023C4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808023C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808023CC: jal         0x80082630
    // 0x808023D0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_158;
    // 0x808023D0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_158:
    // 0x808023D4: lui         $a1, 0x3F2F
    ctx->r5 = S32(0X3F2F << 16);
    // 0x808023D8: addiu       $t0, $zero, 0x3D
    ctx->r8 = ADD32(0, 0X3D);
    // 0x808023DC: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x808023E0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x808023E4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x808023E8: ori         $a1, $a1, 0x6FD2
    ctx->r5 = ctx->r5 | 0X6FD2;
    // 0x808023EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808023F0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808023F4: jal         0x80082630
    // 0x808023F8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_159;
    // 0x808023F8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_159:
    // 0x808023FC: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    // 0x80802400: addiu       $t2, $zero, 0x3D
    ctx->r10 = ADD32(0, 0X3D);
    // 0x80802404: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80802408: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8080240C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80802410: ori         $a1, $a1, 0x13A9
    ctx->r5 = ctx->r5 | 0X13A9;
    // 0x80802414: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802418: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8080241C: jal         0x80082630
    // 0x80802420: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_160;
    // 0x80802420: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_160:
    // 0x80802424: lui         $a1, 0x3F4E
    ctx->r5 = S32(0X3F4E << 16);
    // 0x80802428: addiu       $t4, $zero, 0x3D
    ctx->r12 = ADD32(0, 0X3D);
    // 0x8080242C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80802430: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80802434: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80802438: ori         $a1, $a1, 0x147B
    ctx->r5 = ctx->r5 | 0X147B;
    // 0x8080243C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802440: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802444: jal         0x80082630
    // 0x80802448: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_161;
    // 0x80802448: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_161:
    // 0x8080244C: b           L_80803378
    // 0x80802450: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80802450: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80802454:
    // 0x80802454: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80802458: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x8080245C: lui         $a1, 0x3EB8
    ctx->r5 = S32(0X3EB8 << 16);
    // 0x80802460: addiu       $t6, $zero, 0x3B
    ctx->r14 = ADD32(0, 0X3B);
    // 0x80802464: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80802468: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8080246C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80802470: ori         $a1, $a1, 0xADAC
    ctx->r5 = ctx->r5 | 0XADAC;
    // 0x80802474: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802478: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080247C: jal         0x80082630
    // 0x80802480: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_162;
    // 0x80802480: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_162:
    // 0x80802484: lui         $a1, 0x3F2F
    ctx->r5 = S32(0X3F2F << 16);
    // 0x80802488: addiu       $t8, $zero, 0x3D
    ctx->r24 = ADD32(0, 0X3D);
    // 0x8080248C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80802490: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80802494: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80802498: ori         $a1, $a1, 0x6FD2
    ctx->r5 = ctx->r5 | 0X6FD2;
    // 0x8080249C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808024A0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808024A4: jal         0x80082630
    // 0x808024A8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_163;
    // 0x808024A8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_163:
    // 0x808024AC: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    // 0x808024B0: addiu       $t0, $zero, 0x3D
    ctx->r8 = ADD32(0, 0X3D);
    // 0x808024B4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x808024B8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x808024BC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x808024C0: ori         $a1, $a1, 0x13A9
    ctx->r5 = ctx->r5 | 0X13A9;
    // 0x808024C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808024C8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808024CC: jal         0x80082630
    // 0x808024D0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_164;
    // 0x808024D0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_164:
    // 0x808024D4: lui         $a1, 0x3F4E
    ctx->r5 = S32(0X3F4E << 16);
    // 0x808024D8: addiu       $t2, $zero, 0x3D
    ctx->r10 = ADD32(0, 0X3D);
    // 0x808024DC: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x808024E0: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x808024E4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808024E8: ori         $a1, $a1, 0x147B
    ctx->r5 = ctx->r5 | 0X147B;
    // 0x808024EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808024F0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808024F4: jal         0x80082630
    // 0x808024F8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_165;
    // 0x808024F8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_165:
    // 0x808024FC: b           L_80803378
    // 0x80802500: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80802500: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80802504:
    // 0x80802504: lui         $a1, 0x3E76
    ctx->r5 = S32(0X3E76 << 16);
    // 0x80802508: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8080250C: addiu       $t4, $zero, 0x82
    ctx->r12 = ADD32(0, 0X82);
    // 0x80802510: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80802514: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80802518: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8080251C: addiu       $a2, $a2, -0x7068
    ctx->r6 = ADD32(ctx->r6, -0X7068);
    // 0x80802520: ori         $a1, $a1, 0x2B6B
    ctx->r5 = ctx->r5 | 0X2B6B;
    // 0x80802524: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802528: jal         0x80082630
    // 0x8080252C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_166;
    // 0x8080252C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_166:
    // 0x80802530: b           L_80803378
    // 0x80802534: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80802534: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80802538:
    // 0x80802538: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x8080253C: addiu       $s0, $s0, -0x7090
    ctx->r16 = ADD32(ctx->r16, -0X7090);
    // 0x80802540: lui         $a1, 0x3EFB
    ctx->r5 = S32(0X3EFB << 16);
    // 0x80802544: ori         $a1, $a1, 0xC01A
    ctx->r5 = ctx->r5 | 0XC01A;
    // 0x80802548: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8080254C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802550: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x80802554: jal         0x80082628
    // 0x80802558: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_167;
    // 0x80802558: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_167:
    // 0x8080255C: lui         $a1, 0x3F7B
    ctx->r5 = S32(0X3F7B << 16);
    // 0x80802560: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80802564: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80802568: ori         $a1, $a1, 0x7803
    ctx->r5 = ctx->r5 | 0X7803;
    // 0x8080256C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802570: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802574: jal         0x80082628
    // 0x80802578: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_2(rdram, ctx);
        goto after_168;
    // 0x80802578: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_168:
    // 0x8080257C: b           L_80803378
    // 0x80802580: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80802580: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80802584:
    // 0x80802584: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80802588: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x8080258C: lui         $a1, 0x3D32
    ctx->r5 = S32(0X3D32 << 16);
    // 0x80802590: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x80802594: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80802598: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8080259C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808025A0: ori         $a1, $a1, 0x2D0E
    ctx->r5 = ctx->r5 | 0X2D0E;
    // 0x808025A4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808025A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808025AC: jal         0x80082630
    // 0x808025B0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_169;
    // 0x808025B0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_169:
    // 0x808025B4: lui         $a1, 0x3EBF
    ctx->r5 = S32(0X3EBF << 16);
    // 0x808025B8: addiu       $t9, $zero, 0x41
    ctx->r25 = ADD32(0, 0X41);
    // 0x808025BC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x808025C0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x808025C4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808025C8: ori         $a1, $a1, 0xE5C9
    ctx->r5 = ctx->r5 | 0XE5C9;
    // 0x808025CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808025D0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808025D4: jal         0x80082630
    // 0x808025D8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_170;
    // 0x808025D8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_170:
    // 0x808025DC: b           L_80803378
    // 0x808025E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x808025E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808025E4:
    // 0x808025E4: lui         $a1, 0x3DE3
    ctx->r5 = S32(0X3DE3 << 16);
    // 0x808025E8: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x808025EC: addiu       $t1, $zero, 0x42
    ctx->r9 = ADD32(0, 0X42);
    // 0x808025F0: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x808025F4: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x808025F8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808025FC: addiu       $a2, $a2, -0x7068
    ctx->r6 = ADD32(ctx->r6, -0X7068);
    // 0x80802600: ori         $a1, $a1, 0xBCD3
    ctx->r5 = ctx->r5 | 0XBCD3;
    // 0x80802604: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802608: jal         0x80082630
    // 0x8080260C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_171;
    // 0x8080260C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_171:
    // 0x80802610: b           L_80803378
    // 0x80802614: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80802614: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80802618:
    // 0x80802618: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8080261C: addiu       $t3, $zero, 0x45
    ctx->r11 = ADD32(0, 0X45);
    // 0x80802620: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80802624: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80802628: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8080262C: addiu       $a2, $a2, -0x7068
    ctx->r6 = ADD32(ctx->r6, -0X7068);
    // 0x80802630: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802634: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80802638: jal         0x80082630
    // 0x8080263C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_172;
    // 0x8080263C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_172:
    // 0x80802640: b           L_80803378
    // 0x80802644: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80802644: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80802648:
    // 0x80802648: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x8080264C: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x80802650: lui         $a1, 0x3EAF
    ctx->r5 = S32(0X3EAF << 16);
    // 0x80802654: addiu       $t5, $zero, 0x46
    ctx->r13 = ADD32(0, 0X46);
    // 0x80802658: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8080265C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80802660: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80802664: ori         $a1, $a1, 0x41F2
    ctx->r5 = ctx->r5 | 0X41F2;
    // 0x80802668: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8080266C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802670: jal         0x80082630
    // 0x80802674: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_173;
    // 0x80802674: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_173:
    // 0x80802678: lui         $a1, 0x3F21
    ctx->r5 = S32(0X3F21 << 16);
    // 0x8080267C: addiu       $t7, $zero, 0x47
    ctx->r15 = ADD32(0, 0X47);
    // 0x80802680: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80802684: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80802688: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8080268C: ori         $a1, $a1, 0xB08A
    ctx->r5 = ctx->r5 | 0XB08A;
    // 0x80802690: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802694: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802698: jal         0x80082630
    // 0x8080269C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_174;
    // 0x8080269C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_174:
    // 0x808026A0: lui         $a1, 0x3F6B
    ctx->r5 = S32(0X3F6B << 16);
    // 0x808026A4: addiu       $t9, $zero, 0x47
    ctx->r25 = ADD32(0, 0X47);
    // 0x808026A8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x808026AC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x808026B0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808026B4: ori         $a1, $a1, 0x645A
    ctx->r5 = ctx->r5 | 0X645A;
    // 0x808026B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808026BC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808026C0: jal         0x80082630
    // 0x808026C4: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_175;
    // 0x808026C4: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_175:
    // 0x808026C8: b           L_80803378
    // 0x808026CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x808026CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808026D0:
    // 0x808026D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808026D4: jal         0x80082650
    // 0x808026D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _anseq_entrypoint_7(rdram, ctx);
        goto after_176;
    // 0x808026D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_176:
    // 0x808026DC: lui         $a1, 0x3F3F
    ctx->r5 = S32(0X3F3F << 16);
    // 0x808026E0: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x808026E4: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x808026E8: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x808026EC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x808026F0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808026F4: addiu       $a2, $a2, -0x7068
    ctx->r6 = ADD32(ctx->r6, -0X7068);
    // 0x808026F8: ori         $a1, $a1, 0x4F0E
    ctx->r5 = ctx->r5 | 0X4F0E;
    // 0x808026FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802700: jal         0x80082630
    // 0x80802704: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_177;
    // 0x80802704: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_177:
    // 0x80802708: b           L_80803378
    // 0x8080270C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x8080270C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80802710:
    // 0x80802710: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80802714: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x80802718: lui         $a1, 0x3EA3
    ctx->r5 = S32(0X3EA3 << 16);
    // 0x8080271C: addiu       $t3, $zero, 0x48
    ctx->r11 = ADD32(0, 0X48);
    // 0x80802720: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80802724: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80802728: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8080272C: ori         $a1, $a1, 0xE426
    ctx->r5 = ctx->r5 | 0XE426;
    // 0x80802730: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802734: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802738: jal         0x80082630
    // 0x8080273C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_178;
    // 0x8080273C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_178:
    // 0x80802740: lui         $a1, 0x3F29
    ctx->r5 = S32(0X3F29 << 16);
    // 0x80802744: addiu       $t5, $zero, 0x48
    ctx->r13 = ADD32(0, 0X48);
    // 0x80802748: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8080274C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80802750: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80802754: ori         $a1, $a1, 0x374C
    ctx->r5 = ctx->r5 | 0X374C;
    // 0x80802758: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080275C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802760: jal         0x80082630
    // 0x80802764: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_179;
    // 0x80802764: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_179:
    // 0x80802768: b           L_80803378
    // 0x8080276C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x8080276C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80802770:
    // 0x80802770: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80802774: addiu       $s0, $s0, -0x7090
    ctx->r16 = ADD32(ctx->r16, -0X7090);
    // 0x80802778: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8080277C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802780: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80802784: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x80802788: jal         0x80082628
    // 0x8080278C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_180;
    // 0x8080278C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_180:
    // 0x80802790: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80802794: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80802798: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080279C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x808027A0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808027A4: jal         0x80082628
    // 0x808027A8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_2(rdram, ctx);
        goto after_181;
    // 0x808027A8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_181:
    // 0x808027AC: b           L_80803378
    // 0x808027B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x808027B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808027B4:
    // 0x808027B4: lui         $a1, 0x3F3B
    ctx->r5 = S32(0X3F3B << 16);
    // 0x808027B8: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x808027BC: addiu       $t8, $zero, 0x4C
    ctx->r24 = ADD32(0, 0X4C);
    // 0x808027C0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x808027C4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x808027C8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808027CC: addiu       $a2, $a2, -0x7068
    ctx->r6 = ADD32(ctx->r6, -0X7068);
    // 0x808027D0: ori         $a1, $a1, 0x7E91
    ctx->r5 = ctx->r5 | 0X7E91;
    // 0x808027D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808027D8: jal         0x80082630
    // 0x808027DC: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_182;
    // 0x808027DC: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_182:
    // 0x808027E0: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x808027E4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1732, 0X52D8) << 16);
    // 0x808027E8: addiu       $v0, $v0, 0x52D8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1732, 0X52D8));
    // 0x808027EC: addiu       $s0, $s0, -0x7090
    ctx->r16 = ADD32(ctx->r16, -0X7090);
    // 0x808027F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_808027F4:
    // 0x808027F4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808027F8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808027FC: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x80802800: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80802804: jal         0x80082628
    // 0x80802808: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_183;
    // 0x80802808: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_183:
    // 0x8080280C: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80802810: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(1732, 0X52E8) << 16);
    // 0x80802814: addiu       $t0, $t0, 0x52E8
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(1732, 0X52E8));
    // 0x80802818: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8080281C: bnel        $v0, $t0, L_808027F4
    if (ctx->r2 != ctx->r8) {
        // 0x80802820: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808027F4;
    }
    goto skip_7;
    // 0x80802820: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_7:
    // 0x80802824: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1732, 0X52E8) << 16);
    // 0x80802828: addiu       $v0, $v0, 0x52E8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1732, 0X52E8));
    // 0x8080282C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80802830:
    // 0x80802830: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80802834: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802838: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8080283C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802840: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x80802844: jal         0x80082628
    // 0x80802848: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_184;
    // 0x80802848: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_184:
    // 0x8080284C: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80802850: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(1732, 0X52F8) << 16);
    // 0x80802854: addiu       $t2, $t2, 0x52F8
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(1732, 0X52F8));
    // 0x80802858: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8080285C: bnel        $v0, $t2, L_80802830
    if (ctx->r2 != ctx->r10) {
        // 0x80802860: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_80802830;
    }
    goto skip_8;
    // 0x80802860: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    skip_8:
    // 0x80802864: b           L_80803378
    // 0x80802868: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80802868: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080286C:
    // 0x8080286C: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80802870: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x80802874: lui         $a1, 0x3D10
    ctx->r5 = S32(0X3D10 << 16);
    // 0x80802878: addiu       $t3, $zero, 0x4D
    ctx->r11 = ADD32(0, 0X4D);
    // 0x8080287C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80802880: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80802884: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80802888: ori         $a1, $a1, 0x2DE0
    ctx->r5 = ctx->r5 | 0X2DE0;
    // 0x8080288C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802890: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802894: jal         0x80082630
    // 0x80802898: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_185;
    // 0x80802898: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_185:
    // 0x8080289C: lui         $a1, 0x3D7F
    ctx->r5 = S32(0X3D7F << 16);
    // 0x808028A0: addiu       $t5, $zero, 0x4E
    ctx->r13 = ADD32(0, 0X4E);
    // 0x808028A4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x808028A8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x808028AC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x808028B0: ori         $a1, $a1, 0x2E49
    ctx->r5 = ctx->r5 | 0X2E49;
    // 0x808028B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808028B8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808028BC: jal         0x80082630
    // 0x808028C0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_186;
    // 0x808028C0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_186:
    // 0x808028C4: lui         $a1, 0x3D7F
    ctx->r5 = S32(0X3D7F << 16);
    // 0x808028C8: addiu       $t7, $zero, 0x4F
    ctx->r15 = ADD32(0, 0X4F);
    // 0x808028CC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x808028D0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x808028D4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808028D8: ori         $a1, $a1, 0x2E49
    ctx->r5 = ctx->r5 | 0X2E49;
    // 0x808028DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808028E0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808028E4: jal         0x80082630
    // 0x808028E8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_187;
    // 0x808028E8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_187:
    // 0x808028EC: lui         $a1, 0x3EE1
    ctx->r5 = S32(0X3EE1 << 16);
    // 0x808028F0: addiu       $t9, $zero, 0x52
    ctx->r25 = ADD32(0, 0X52);
    // 0x808028F4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x808028F8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x808028FC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80802900: ori         $a1, $a1, 0xB08A
    ctx->r5 = ctx->r5 | 0XB08A;
    // 0x80802904: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802908: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8080290C: jal         0x80082630
    // 0x80802910: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_188;
    // 0x80802910: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_188:
    // 0x80802914: b           L_80803378
    // 0x80802918: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80802918: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080291C:
    // 0x8080291C: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80802920: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x80802924: lui         $a1, 0x3F1E
    ctx->r5 = S32(0X3F1E << 16);
    // 0x80802928: addiu       $t1, $zero, 0x53
    ctx->r9 = ADD32(0, 0X53);
    // 0x8080292C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80802930: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80802934: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80802938: ori         $a1, $a1, 0xDFA4
    ctx->r5 = ctx->r5 | 0XDFA4;
    // 0x8080293C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802940: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802944: jal         0x80082630
    // 0x80802948: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_189;
    // 0x80802948: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_189:
    // 0x8080294C: lui         $a1, 0x3F2F
    ctx->r5 = S32(0X3F2F << 16);
    // 0x80802950: addiu       $t3, $zero, 0x53
    ctx->r11 = ADD32(0, 0X53);
    // 0x80802954: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80802958: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8080295C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80802960: ori         $a1, $a1, 0xA440
    ctx->r5 = ctx->r5 | 0XA440;
    // 0x80802964: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802968: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8080296C: jal         0x80082630
    // 0x80802970: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_190;
    // 0x80802970: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_190:
    // 0x80802974: lui         $a1, 0x3F43
    ctx->r5 = S32(0X3F43 << 16);
    // 0x80802978: addiu       $t5, $zero, 0x53
    ctx->r13 = ADD32(0, 0X53);
    // 0x8080297C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80802980: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80802984: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80802988: ori         $a1, $a1, 0x5A86
    ctx->r5 = ctx->r5 | 0X5A86;
    // 0x8080298C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802990: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802994: jal         0x80082630
    // 0x80802998: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_191;
    // 0x80802998: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_191:
    // 0x8080299C: lui         $a1, 0x3F6E
    ctx->r5 = S32(0X3F6E << 16);
    // 0x808029A0: addiu       $t7, $zero, 0x55
    ctx->r15 = ADD32(0, 0X55);
    // 0x808029A4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x808029A8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x808029AC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808029B0: ori         $a1, $a1, 0xA4A9
    ctx->r5 = ctx->r5 | 0XA4A9;
    // 0x808029B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808029B8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808029BC: jal         0x80082630
    // 0x808029C0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_192;
    // 0x808029C0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_192:
    // 0x808029C4: b           L_80803378
    // 0x808029C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x808029C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808029CC:
    // 0x808029CC: lui         $a1, 0x3E9C
    ctx->r5 = S32(0X3E9C << 16);
    // 0x808029D0: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x808029D4: addiu       $t9, $zero, 0x79
    ctx->r25 = ADD32(0, 0X79);
    // 0x808029D8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x808029DC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x808029E0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808029E4: addiu       $a2, $a2, -0x7068
    ctx->r6 = ADD32(ctx->r6, -0X7068);
    // 0x808029E8: ori         $a1, $a1, 0xE076
    ctx->r5 = ctx->r5 | 0XE076;
    // 0x808029EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808029F0: jal         0x80082630
    // 0x808029F4: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_193;
    // 0x808029F4: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_193:
    // 0x808029F8: b           L_80803378
    // 0x808029FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x808029FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80802A00:
    // 0x80802A00: lui         $a1, 0x3E6D
    ctx->r5 = S32(0X3E6D << 16);
    // 0x80802A04: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80802A08: addiu       $t1, $zero, 0x7A
    ctx->r9 = ADD32(0, 0X7A);
    // 0x80802A0C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80802A10: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80802A14: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80802A18: addiu       $a2, $a2, -0x7068
    ctx->r6 = ADD32(ctx->r6, -0X7068);
    // 0x80802A1C: ori         $a1, $a1, 0x7732
    ctx->r5 = ctx->r5 | 0X7732;
    // 0x80802A20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802A24: jal         0x80082630
    // 0x80802A28: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_194;
    // 0x80802A28: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_194:
    // 0x80802A2C: b           L_80803378
    // 0x80802A30: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80802A30: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80802A34:
    // 0x80802A34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802A38: jal         0x80082650
    // 0x80802A3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _anseq_entrypoint_7(rdram, ctx);
        goto after_195;
    // 0x80802A3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_195:
    // 0x80802A40: lui         $a1, 0x3EB0
    ctx->r5 = S32(0X3EB0 << 16);
    // 0x80802A44: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80802A48: addiu       $t3, $zero, 0x7B
    ctx->r11 = ADD32(0, 0X7B);
    // 0x80802A4C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80802A50: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80802A54: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80802A58: addiu       $a2, $a2, -0x7068
    ctx->r6 = ADD32(ctx->r6, -0X7068);
    // 0x80802A5C: ori         $a1, $a1, 0xF27C
    ctx->r5 = ctx->r5 | 0XF27C;
    // 0x80802A60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802A64: jal         0x80082630
    // 0x80802A68: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_196;
    // 0x80802A68: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_196:
    // 0x80802A6C: b           L_80803378
    // 0x80802A70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80802A70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80802A74:
    // 0x80802A74: lui         $a1, 0x3F0C
    ctx->r5 = S32(0X3F0C << 16);
    // 0x80802A78: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80802A7C: addiu       $t5, $zero, 0x66
    ctx->r13 = ADD32(0, 0X66);
    // 0x80802A80: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80802A84: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80802A88: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80802A8C: addiu       $a2, $a2, -0x7068
    ctx->r6 = ADD32(ctx->r6, -0X7068);
    // 0x80802A90: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80802A94: jal         0x80082630
    // 0x80802A98: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_197;
    // 0x80802A98: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_197:
    // 0x80802A9C: b           L_80803378
    // 0x80802AA0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80802AA0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80802AA4:
    // 0x80802AA4: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80802AA8: addiu       $s0, $s0, -0x7090
    ctx->r16 = ADD32(ctx->r16, -0X7090);
    // 0x80802AAC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802AB0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80802AB4: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x80802AB8: jal         0x80082628
    // 0x80802ABC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_198;
    // 0x80802ABC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_198:
    // 0x80802AC0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80802AC4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80802AC8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802ACC: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80802AD0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802AD4: jal         0x80082628
    // 0x80802AD8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_2(rdram, ctx);
        goto after_199;
    // 0x80802AD8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_199:
    // 0x80802ADC: b           L_80803378
    // 0x80802AE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80802AE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80802AE4:
    // 0x80802AE4: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80802AE8: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80802AEC: addiu       $t8, $zero, 0x65
    ctx->r24 = ADD32(0, 0X65);
    // 0x80802AF0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80802AF4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80802AF8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80802AFC: addiu       $a2, $a2, -0x7068
    ctx->r6 = ADD32(ctx->r6, -0X7068);
    // 0x80802B00: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80802B04: jal         0x80082630
    // 0x80802B08: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_200;
    // 0x80802B08: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_200:
    // 0x80802B0C: b           L_80803378
    // 0x80802B10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80802B10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80802B14:
    // 0x80802B14: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80802B18: addiu       $s0, $s0, -0x7090
    ctx->r16 = ADD32(ctx->r16, -0X7090);
    // 0x80802B1C: lui         $a1, 0x3ECD
    ctx->r5 = S32(0X3ECD << 16);
    // 0x80802B20: ori         $a1, $a1, 0x4FDF
    ctx->r5 = ctx->r5 | 0X4FDF;
    // 0x80802B24: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802B28: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802B2C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x80802B30: jal         0x80082628
    // 0x80802B34: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _anseq_entrypoint_2(rdram, ctx);
        goto after_201;
    // 0x80802B34: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_201:
    // 0x80802B38: lui         $a1, 0x3F65
    ctx->r5 = S32(0X3F65 << 16);
    // 0x80802B3C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80802B40: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80802B44: ori         $a1, $a1, 0xD639
    ctx->r5 = ctx->r5 | 0XD639;
    // 0x80802B48: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802B4C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802B50: jal         0x80082628
    // 0x80802B54: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_2(rdram, ctx);
        goto after_202;
    // 0x80802B54: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_202:
    // 0x80802B58: b           L_80803378
    // 0x80802B5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80802B5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80802B60:
    // 0x80802B60: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80802B64: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x80802B68: lui         $a1, 0x3F48
    ctx->r5 = S32(0X3F48 << 16);
    // 0x80802B6C: addiu       $t1, $zero, 0x59
    ctx->r9 = ADD32(0, 0X59);
    // 0x80802B70: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80802B74: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80802B78: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80802B7C: ori         $a1, $a1, 0xA71E
    ctx->r5 = ctx->r5 | 0XA71E;
    // 0x80802B80: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802B84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802B88: jal         0x80082630
    // 0x80802B8C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_203;
    // 0x80802B8C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_203:
    // 0x80802B90: lui         $a1, 0x3F5C
    ctx->r5 = S32(0X3F5C << 16);
    // 0x80802B94: addiu       $t3, $zero, 0x5A
    ctx->r11 = ADD32(0, 0X5A);
    // 0x80802B98: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80802B9C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80802BA0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80802BA4: ori         $a1, $a1, 0xD35B
    ctx->r5 = ctx->r5 | 0XD35B;
    // 0x80802BA8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802BAC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802BB0: jal         0x80082630
    // 0x80802BB4: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_204;
    // 0x80802BB4: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_204:
    // 0x80802BB8: b           L_80803378
    // 0x80802BBC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80802BBC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80802BC0:
    // 0x80802BC0: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80802BC4: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x80802BC8: lui         $a1, 0x3D68
    ctx->r5 = S32(0X3D68 << 16);
    // 0x80802BCC: addiu       $t5, $zero, 0xA7
    ctx->r13 = ADD32(0, 0XA7);
    // 0x80802BD0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80802BD4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80802BD8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80802BDC: ori         $a1, $a1, 0x3E42
    ctx->r5 = ctx->r5 | 0X3E42;
    // 0x80802BE0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802BE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802BE8: jal         0x80082630
    // 0x80802BEC: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_205;
    // 0x80802BEC: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_205:
    // 0x80802BF0: lui         $a1, 0x3D68
    ctx->r5 = S32(0X3D68 << 16);
    // 0x80802BF4: addiu       $t7, $zero, 0x9D
    ctx->r15 = ADD32(0, 0X9D);
    // 0x80802BF8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80802BFC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80802C00: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80802C04: ori         $a1, $a1, 0x3E42
    ctx->r5 = ctx->r5 | 0X3E42;
    // 0x80802C08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802C0C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802C10: jal         0x80082630
    // 0x80802C14: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_206;
    // 0x80802C14: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_206:
    // 0x80802C18: lui         $a1, 0x3E7B
    ctx->r5 = S32(0X3E7B << 16);
    // 0x80802C1C: addiu       $t9, $zero, 0xA8
    ctx->r25 = ADD32(0, 0XA8);
    // 0x80802C20: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80802C24: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80802C28: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80802C2C: ori         $a1, $a1, 0xB2FF
    ctx->r5 = ctx->r5 | 0XB2FF;
    // 0x80802C30: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802C34: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802C38: jal         0x80082630
    // 0x80802C3C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_207;
    // 0x80802C3C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_207:
    // 0x80802C40: lui         $a1, 0x3E7B
    ctx->r5 = S32(0X3E7B << 16);
    // 0x80802C44: addiu       $t1, $zero, 0xA0
    ctx->r9 = ADD32(0, 0XA0);
    // 0x80802C48: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80802C4C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80802C50: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80802C54: ori         $a1, $a1, 0xB2FF
    ctx->r5 = ctx->r5 | 0XB2FF;
    // 0x80802C58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802C5C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802C60: jal         0x80082630
    // 0x80802C64: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_208;
    // 0x80802C64: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_208:
    // 0x80802C68: lui         $a1, 0x3E7B
    ctx->r5 = S32(0X3E7B << 16);
    // 0x80802C6C: addiu       $t3, $zero, 0x9C
    ctx->r11 = ADD32(0, 0X9C);
    // 0x80802C70: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80802C74: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80802C78: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80802C7C: ori         $a1, $a1, 0xB2FF
    ctx->r5 = ctx->r5 | 0XB2FF;
    // 0x80802C80: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802C84: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802C88: jal         0x80082630
    // 0x80802C8C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_209;
    // 0x80802C8C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_209:
    // 0x80802C90: lui         $a1, 0x3EB0
    ctx->r5 = S32(0X3EB0 << 16);
    // 0x80802C94: addiu       $t5, $zero, 0xA8
    ctx->r13 = ADD32(0, 0XA8);
    // 0x80802C98: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80802C9C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80802CA0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80802CA4: ori         $a1, $a1, 0x6F69
    ctx->r5 = ctx->r5 | 0X6F69;
    // 0x80802CA8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802CAC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802CB0: jal         0x80082630
    // 0x80802CB4: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_210;
    // 0x80802CB4: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_210:
    // 0x80802CB8: lui         $a1, 0x3EB0
    ctx->r5 = S32(0X3EB0 << 16);
    // 0x80802CBC: addiu       $t7, $zero, 0x9E
    ctx->r15 = ADD32(0, 0X9E);
    // 0x80802CC0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80802CC4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80802CC8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80802CCC: ori         $a1, $a1, 0x6F69
    ctx->r5 = ctx->r5 | 0X6F69;
    // 0x80802CD0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802CD4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802CD8: jal         0x80082630
    // 0x80802CDC: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_211;
    // 0x80802CDC: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_211:
    // 0x80802CE0: lui         $a1, 0x3EB0
    ctx->r5 = S32(0X3EB0 << 16);
    // 0x80802CE4: addiu       $t9, $zero, 0xA0
    ctx->r25 = ADD32(0, 0XA0);
    // 0x80802CE8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80802CEC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80802CF0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80802CF4: ori         $a1, $a1, 0x6F69
    ctx->r5 = ctx->r5 | 0X6F69;
    // 0x80802CF8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802CFC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802D00: jal         0x80082630
    // 0x80802D04: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_212;
    // 0x80802D04: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_212:
    // 0x80802D08: lui         $a1, 0x3EEE
    ctx->r5 = S32(0X3EEE << 16);
    // 0x80802D0C: addiu       $t1, $zero, 0xA8
    ctx->r9 = ADD32(0, 0XA8);
    // 0x80802D10: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80802D14: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80802D18: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80802D1C: ori         $a1, $a1, 0x48E9
    ctx->r5 = ctx->r5 | 0X48E9;
    // 0x80802D20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802D24: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802D28: jal         0x80082630
    // 0x80802D2C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_213;
    // 0x80802D2C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_213:
    // 0x80802D30: lui         $a1, 0x3EEE
    ctx->r5 = S32(0X3EEE << 16);
    // 0x80802D34: addiu       $t3, $zero, 0x9C
    ctx->r11 = ADD32(0, 0X9C);
    // 0x80802D38: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80802D3C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80802D40: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80802D44: ori         $a1, $a1, 0x48E9
    ctx->r5 = ctx->r5 | 0X48E9;
    // 0x80802D48: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802D4C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802D50: jal         0x80082630
    // 0x80802D54: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_214;
    // 0x80802D54: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_214:
    // 0x80802D58: lui         $a1, 0x3EEE
    ctx->r5 = S32(0X3EEE << 16);
    // 0x80802D5C: addiu       $t5, $zero, 0xA0
    ctx->r13 = ADD32(0, 0XA0);
    // 0x80802D60: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80802D64: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80802D68: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80802D6C: ori         $a1, $a1, 0x48E9
    ctx->r5 = ctx->r5 | 0X48E9;
    // 0x80802D70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802D74: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802D78: jal         0x80082630
    // 0x80802D7C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_215;
    // 0x80802D7C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_215:
    // 0x80802D80: lui         $a1, 0x3F15
    ctx->r5 = S32(0X3F15 << 16);
    // 0x80802D84: addiu       $t7, $zero, 0xA8
    ctx->r15 = ADD32(0, 0XA8);
    // 0x80802D88: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80802D8C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80802D90: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80802D94: ori         $a1, $a1, 0xB574
    ctx->r5 = ctx->r5 | 0XB574;
    // 0x80802D98: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802D9C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802DA0: jal         0x80082630
    // 0x80802DA4: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_216;
    // 0x80802DA4: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_216:
    // 0x80802DA8: lui         $a1, 0x3F15
    ctx->r5 = S32(0X3F15 << 16);
    // 0x80802DAC: addiu       $t9, $zero, 0x9D
    ctx->r25 = ADD32(0, 0X9D);
    // 0x80802DB0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80802DB4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80802DB8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80802DBC: ori         $a1, $a1, 0xB574
    ctx->r5 = ctx->r5 | 0XB574;
    // 0x80802DC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802DC4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802DC8: jal         0x80082630
    // 0x80802DCC: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_217;
    // 0x80802DCC: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_217:
    // 0x80802DD0: lui         $a1, 0x3F15
    ctx->r5 = S32(0X3F15 << 16);
    // 0x80802DD4: addiu       $t1, $zero, 0xA0
    ctx->r9 = ADD32(0, 0XA0);
    // 0x80802DD8: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80802DDC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80802DE0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80802DE4: ori         $a1, $a1, 0xB574
    ctx->r5 = ctx->r5 | 0XB574;
    // 0x80802DE8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802DEC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802DF0: jal         0x80082630
    // 0x80802DF4: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_218;
    // 0x80802DF4: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_218:
    // 0x80802DF8: lui         $a1, 0x3F2D
    ctx->r5 = S32(0X3F2D << 16);
    // 0x80802DFC: addiu       $t3, $zero, 0xA8
    ctx->r11 = ADD32(0, 0XA8);
    // 0x80802E00: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80802E04: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80802E08: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80802E0C: ori         $a1, $a1, 0x13B
    ctx->r5 = ctx->r5 | 0X13B;
    // 0x80802E10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802E14: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802E18: jal         0x80082630
    // 0x80802E1C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_219;
    // 0x80802E1C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_219:
    // 0x80802E20: lui         $a1, 0x3F2D
    ctx->r5 = S32(0X3F2D << 16);
    // 0x80802E24: addiu       $t5, $zero, 0x9E
    ctx->r13 = ADD32(0, 0X9E);
    // 0x80802E28: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80802E2C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80802E30: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80802E34: ori         $a1, $a1, 0x13B
    ctx->r5 = ctx->r5 | 0X13B;
    // 0x80802E38: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802E3C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802E40: jal         0x80082630
    // 0x80802E44: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_220;
    // 0x80802E44: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_220:
    // 0x80802E48: lui         $a1, 0x3F2D
    ctx->r5 = S32(0X3F2D << 16);
    // 0x80802E4C: addiu       $t7, $zero, 0xA0
    ctx->r15 = ADD32(0, 0XA0);
    // 0x80802E50: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80802E54: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80802E58: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80802E5C: ori         $a1, $a1, 0x13B
    ctx->r5 = ctx->r5 | 0X13B;
    // 0x80802E60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802E64: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802E68: jal         0x80082630
    // 0x80802E6C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_221;
    // 0x80802E6C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_221:
    // 0x80802E70: lui         $a1, 0x3F53
    ctx->r5 = S32(0X3F53 << 16);
    // 0x80802E74: addiu       $t9, $zero, 0xA9
    ctx->r25 = ADD32(0, 0XA9);
    // 0x80802E78: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80802E7C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80802E80: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80802E84: ori         $a1, $a1, 0xBE1
    ctx->r5 = ctx->r5 | 0XBE1;
    // 0x80802E88: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802E8C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802E90: jal         0x80082630
    // 0x80802E94: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_222;
    // 0x80802E94: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_222:
    // 0x80802E98: lui         $a1, 0x3F53
    ctx->r5 = S32(0X3F53 << 16);
    // 0x80802E9C: addiu       $t1, $zero, 0x9C
    ctx->r9 = ADD32(0, 0X9C);
    // 0x80802EA0: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80802EA4: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80802EA8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80802EAC: ori         $a1, $a1, 0xBE1
    ctx->r5 = ctx->r5 | 0XBE1;
    // 0x80802EB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802EB4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802EB8: jal         0x80082630
    // 0x80802EBC: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_223;
    // 0x80802EBC: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_223:
    // 0x80802EC0: lui         $a1, 0x3F53
    ctx->r5 = S32(0X3F53 << 16);
    // 0x80802EC4: addiu       $t3, $zero, 0xA2
    ctx->r11 = ADD32(0, 0XA2);
    // 0x80802EC8: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80802ECC: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80802ED0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80802ED4: ori         $a1, $a1, 0xBE1
    ctx->r5 = ctx->r5 | 0XBE1;
    // 0x80802ED8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802EDC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802EE0: jal         0x80082630
    // 0x80802EE4: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_224;
    // 0x80802EE4: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_224:
    // 0x80802EE8: b           L_80803378
    // 0x80802EEC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80802EEC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80802EF0:
    // 0x80802EF0: lui         $a1, 0x3F0B
    ctx->r5 = S32(0X3F0B << 16);
    // 0x80802EF4: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80802EF8: addiu       $t5, $zero, 0x78
    ctx->r13 = ADD32(0, 0X78);
    // 0x80802EFC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80802F00: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80802F04: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80802F08: addiu       $a2, $a2, -0x7068
    ctx->r6 = ADD32(ctx->r6, -0X7068);
    // 0x80802F0C: ori         $a1, $a1, 0x7E91
    ctx->r5 = ctx->r5 | 0X7E91;
    // 0x80802F10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802F14: jal         0x80082630
    // 0x80802F18: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_225;
    // 0x80802F18: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_225:
    // 0x80802F1C: b           L_80803378
    // 0x80802F20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80802F20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80802F24:
    // 0x80802F24: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80802F28: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x80802F2C: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    // 0x80802F30: addiu       $t7, $zero, 0xA2
    ctx->r15 = ADD32(0, 0XA2);
    // 0x80802F34: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80802F38: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80802F3C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80802F40: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80802F44: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802F48: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802F4C: jal         0x80082630
    // 0x80802F50: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_226;
    // 0x80802F50: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_226:
    // 0x80802F54: lui         $a1, 0x3E9E
    ctx->r5 = S32(0X3E9E << 16);
    // 0x80802F58: addiu       $t9, $zero, 0x83
    ctx->r25 = ADD32(0, 0X83);
    // 0x80802F5C: addiu       $t0, $zero, -0x2
    ctx->r8 = ADD32(0, -0X2);
    // 0x80802F60: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80802F64: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80802F68: ori         $a1, $a1, 0xB852
    ctx->r5 = ctx->r5 | 0XB852;
    // 0x80802F6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802F70: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802F74: jal         0x80082630
    // 0x80802F78: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_227;
    // 0x80802F78: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_227:
    // 0x80802F7C: b           L_80803378
    // 0x80802F80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80802F80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80802F84:
    // 0x80802F84: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80802F88: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x80802F8C: lui         $a1, 0x3D3C
    ctx->r5 = S32(0X3D3C << 16);
    // 0x80802F90: addiu       $t1, $zero, 0x84
    ctx->r9 = ADD32(0, 0X84);
    // 0x80802F94: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80802F98: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80802F9C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80802FA0: ori         $a1, $a1, 0x1A3
    ctx->r5 = ctx->r5 | 0X1A3;
    // 0x80802FA4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802FA8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802FAC: jal         0x80082630
    // 0x80802FB0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_228;
    // 0x80802FB0: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_228:
    // 0x80802FB4: lui         $a1, 0x3F4F
    ctx->r5 = S32(0X3F4F << 16);
    // 0x80802FB8: addiu       $t3, $zero, 0x85
    ctx->r11 = ADD32(0, 0X85);
    // 0x80802FBC: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80802FC0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80802FC4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80802FC8: ori         $a1, $a1, 0xD8AE
    ctx->r5 = ctx->r5 | 0XD8AE;
    // 0x80802FCC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802FD0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802FD4: jal         0x80082630
    // 0x80802FD8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_229;
    // 0x80802FD8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_229:
    // 0x80802FDC: lui         $a1, 0x3F5D
    ctx->r5 = S32(0X3F5D << 16);
    // 0x80802FE0: addiu       $t5, $zero, 0x85
    ctx->r13 = ADD32(0, 0X85);
    // 0x80802FE4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80802FE8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80802FEC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80802FF0: ori         $a1, $a1, 0xB8BB
    ctx->r5 = ctx->r5 | 0XB8BB;
    // 0x80802FF4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80802FF8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80802FFC: jal         0x80082630
    // 0x80803000: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_230;
    // 0x80803000: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_230:
    // 0x80803004: b           L_80803378
    // 0x80803008: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80803008: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080300C:
    // 0x8080300C: lui         $a1, 0x3F36
    ctx->r5 = S32(0X3F36 << 16);
    // 0x80803010: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x80803014: addiu       $t7, $zero, 0x86
    ctx->r15 = ADD32(0, 0X86);
    // 0x80803018: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8080301C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80803020: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80803024: addiu       $a2, $a2, -0x7068
    ctx->r6 = ADD32(ctx->r6, -0X7068);
    // 0x80803028: ori         $a1, $a1, 0x1E4F
    ctx->r5 = ctx->r5 | 0X1E4F;
    // 0x8080302C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80803030: jal         0x80082630
    // 0x80803034: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_231;
    // 0x80803034: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_231:
    // 0x80803038: b           L_80803378
    // 0x8080303C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x8080303C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80803040:
    // 0x80803040: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80803044: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x80803048: lui         $a1, 0x3E5E
    ctx->r5 = S32(0X3E5E << 16);
    // 0x8080304C: addiu       $t9, $zero, 0x8D
    ctx->r25 = ADD32(0, 0X8D);
    // 0x80803050: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80803054: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80803058: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8080305C: ori         $a1, $a1, 0x1B09
    ctx->r5 = ctx->r5 | 0X1B09;
    // 0x80803060: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80803064: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80803068: jal         0x80082630
    // 0x8080306C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_232;
    // 0x8080306C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_232:
    // 0x80803070: lui         $a1, 0x3F0E
    ctx->r5 = S32(0X3F0E << 16);
    // 0x80803074: addiu       $t1, $zero, 0x8F
    ctx->r9 = ADD32(0, 0X8F);
    // 0x80803078: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8080307C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80803080: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80803084: ori         $a1, $a1, 0x75F
    ctx->r5 = ctx->r5 | 0X75F;
    // 0x80803088: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080308C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80803090: jal         0x80082630
    // 0x80803094: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_233;
    // 0x80803094: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_233:
    // 0x80803098: b           L_80803378
    // 0x8080309C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x8080309C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808030A0:
    // 0x808030A0: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x808030A4: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x808030A8: lui         $a1, 0x3D7E
    ctx->r5 = S32(0X3D7E << 16);
    // 0x808030AC: addiu       $t3, $zero, 0xA3
    ctx->r11 = ADD32(0, 0XA3);
    // 0x808030B0: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x808030B4: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x808030B8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x808030BC: ori         $a1, $a1, 0x5C92
    ctx->r5 = ctx->r5 | 0X5C92;
    // 0x808030C0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808030C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808030C8: jal         0x80082630
    // 0x808030CC: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_234;
    // 0x808030CC: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_234:
    // 0x808030D0: lui         $a1, 0x3E20
    ctx->r5 = S32(0X3E20 << 16);
    // 0x808030D4: addiu       $t5, $zero, 0xA4
    ctx->r13 = ADD32(0, 0XA4);
    // 0x808030D8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x808030DC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x808030E0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x808030E4: ori         $a1, $a1, 0xAA65
    ctx->r5 = ctx->r5 | 0XAA65;
    // 0x808030E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808030EC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808030F0: jal         0x80082630
    // 0x808030F4: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_235;
    // 0x808030F4: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_235:
    // 0x808030F8: lui         $a1, 0x3F0E
    ctx->r5 = S32(0X3F0E << 16);
    // 0x808030FC: addiu       $t7, $zero, 0xA4
    ctx->r15 = ADD32(0, 0XA4);
    // 0x80803100: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80803104: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80803108: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8080310C: ori         $a1, $a1, 0xD2
    ctx->r5 = ctx->r5 | 0XD2;
    // 0x80803110: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80803114: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80803118: jal         0x80082630
    // 0x8080311C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_236;
    // 0x8080311C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_236:
    // 0x80803120: lui         $a1, 0x3F68
    ctx->r5 = S32(0X3F68 << 16);
    // 0x80803124: addiu       $t9, $zero, 0xA5
    ctx->r25 = ADD32(0, 0XA5);
    // 0x80803128: addiu       $t0, $zero, -0x4
    ctx->r8 = ADD32(0, -0X4);
    // 0x8080312C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80803130: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80803134: ori         $a1, $a1, 0xF5C3
    ctx->r5 = ctx->r5 | 0XF5C3;
    // 0x80803138: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080313C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80803140: jal         0x80082630
    // 0x80803144: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_237;
    // 0x80803144: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_237:
    // 0x80803148: lui         $a1, 0x3F68
    ctx->r5 = S32(0X3F68 << 16);
    // 0x8080314C: addiu       $t1, $zero, 0xAB
    ctx->r9 = ADD32(0, 0XAB);
    // 0x80803150: addiu       $t2, $zero, -0x4
    ctx->r10 = ADD32(0, -0X4);
    // 0x80803154: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80803158: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8080315C: ori         $a1, $a1, 0xF5C3
    ctx->r5 = ctx->r5 | 0XF5C3;
    // 0x80803160: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80803164: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80803168: jal         0x80082630
    // 0x8080316C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_238;
    // 0x8080316C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_238:
    // 0x80803170: b           L_80803378
    // 0x80803174: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x80803174: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80803178:
    // 0x80803178: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x8080317C: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x80803180: lui         $a1, 0x3F26
    ctx->r5 = S32(0X3F26 << 16);
    // 0x80803184: addiu       $t3, $zero, 0xA5
    ctx->r11 = ADD32(0, 0XA5);
    // 0x80803188: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8080318C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80803190: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80803194: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80803198: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8080319C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808031A0: jal         0x80082630
    // 0x808031A4: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_239;
    // 0x808031A4: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_239:
    // 0x808031A8: lui         $a1, 0x3F26
    ctx->r5 = S32(0X3F26 << 16);
    // 0x808031AC: addiu       $t5, $zero, 0xAB
    ctx->r13 = ADD32(0, 0XAB);
    // 0x808031B0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x808031B4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x808031B8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x808031BC: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x808031C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808031C4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808031C8: jal         0x80082630
    // 0x808031CC: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_240;
    // 0x808031CC: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_240:
    // 0x808031D0: b           L_80803378
    // 0x808031D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x808031D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808031D8:
    // 0x808031D8: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x808031DC: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x808031E0: lui         $a1, 0x3DD6
    ctx->r5 = S32(0X3DD6 << 16);
    // 0x808031E4: addiu       $t7, $zero, 0x9B
    ctx->r15 = ADD32(0, 0X9B);
    // 0x808031E8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x808031EC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x808031F0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808031F4: ori         $a1, $a1, 0xD5D0
    ctx->r5 = ctx->r5 | 0XD5D0;
    // 0x808031F8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808031FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80803200: jal         0x80082630
    // 0x80803204: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_241;
    // 0x80803204: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_241:
    // 0x80803208: lui         $a1, 0x3E8D
    ctx->r5 = S32(0X3E8D << 16);
    // 0x8080320C: addiu       $t9, $zero, 0x9B
    ctx->r25 = ADD32(0, 0X9B);
    // 0x80803210: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80803214: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80803218: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8080321C: ori         $a1, $a1, 0x9E84
    ctx->r5 = ctx->r5 | 0X9E84;
    // 0x80803220: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80803224: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80803228: jal         0x80082630
    // 0x8080322C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_242;
    // 0x8080322C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_242:
    // 0x80803230: lui         $a1, 0x3EE6
    ctx->r5 = S32(0X3EE6 << 16);
    // 0x80803234: addiu       $t1, $zero, 0x9B
    ctx->r9 = ADD32(0, 0X9B);
    // 0x80803238: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8080323C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80803240: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80803244: ori         $a1, $a1, 0x31F9
    ctx->r5 = ctx->r5 | 0X31F9;
    // 0x80803248: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080324C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80803250: jal         0x80082630
    // 0x80803254: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_243;
    // 0x80803254: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_243:
    // 0x80803258: b           L_80803378
    // 0x8080325C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x8080325C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80803260:
    // 0x80803260: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x80803264: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x80803268: lui         $a1, 0x3E32
    ctx->r5 = S32(0X3E32 << 16);
    // 0x8080326C: addiu       $t3, $zero, 0xAC
    ctx->r11 = ADD32(0, 0XAC);
    // 0x80803270: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80803274: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80803278: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8080327C: ori         $a1, $a1, 0x95EA
    ctx->r5 = ctx->r5 | 0X95EA;
    // 0x80803280: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80803284: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80803288: jal         0x80082630
    // 0x8080328C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_244;
    // 0x8080328C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_244:
    // 0x80803290: lui         $a1, 0x3F1C
    ctx->r5 = S32(0X3F1C << 16);
    // 0x80803294: addiu       $t5, $zero, 0xAC
    ctx->r13 = ADD32(0, 0XAC);
    // 0x80803298: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8080329C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x808032A0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x808032A4: ori         $a1, $a1, 0x56D6
    ctx->r5 = ctx->r5 | 0X56D6;
    // 0x808032A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808032AC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808032B0: jal         0x80082630
    // 0x808032B4: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_245;
    // 0x808032B4: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_245:
    // 0x808032B8: b           L_80803378
    // 0x808032BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x808032BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808032C0:
    // 0x808032C0: lui         $a1, 0x3F28
    ctx->r5 = S32(0X3F28 << 16);
    // 0x808032C4: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x808032C8: addiu       $t7, $zero, 0xB3
    ctx->r15 = ADD32(0, 0XB3);
    // 0x808032CC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x808032D0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x808032D4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808032D8: addiu       $a2, $a2, -0x7068
    ctx->r6 = ADD32(ctx->r6, -0X7068);
    // 0x808032DC: ori         $a1, $a1, 0xF5C3
    ctx->r5 = ctx->r5 | 0XF5C3;
    // 0x808032E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808032E4: jal         0x80082630
    // 0x808032E8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_246;
    // 0x808032E8: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_246:
    // 0x808032EC: b           L_80803378
    // 0x808032F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80803378;
    // 0x808032F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808032F4:
    // 0x808032F4: lui         $s0, 0x8009
    ctx->r16 = S32(0X8009 << 16);
    // 0x808032F8: addiu       $s0, $s0, -0x7068
    ctx->r16 = ADD32(ctx->r16, -0X7068);
    // 0x808032FC: lui         $a1, 0x3E02
    ctx->r5 = S32(0X3E02 << 16);
    // 0x80803300: addiu       $t9, $zero, 0xB4
    ctx->r25 = ADD32(0, 0XB4);
    // 0x80803304: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80803308: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8080330C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80803310: ori         $a1, $a1, 0x5AEE
    ctx->r5 = ctx->r5 | 0X5AEE;
    // 0x80803314: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80803318: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080331C: jal         0x80082630
    // 0x80803320: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_247;
    // 0x80803320: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_247:
    // 0x80803324: lui         $a1, 0x3E4D
    ctx->r5 = S32(0X3E4D << 16);
    // 0x80803328: addiu       $t1, $zero, 0xB4
    ctx->r9 = ADD32(0, 0XB4);
    // 0x8080332C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80803330: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80803334: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80803338: ori         $a1, $a1, 0x9E84
    ctx->r5 = ctx->r5 | 0X9E84;
    // 0x8080333C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80803340: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80803344: jal         0x80082630
    // 0x80803348: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_248;
    // 0x80803348: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_248:
    // 0x8080334C: lui         $a1, 0x3E79
    ctx->r5 = S32(0X3E79 << 16);
    // 0x80803350: addiu       $t3, $zero, 0xB4
    ctx->r11 = ADD32(0, 0XB4);
    // 0x80803354: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80803358: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8080335C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80803360: ori         $a1, $a1, 0xA6B5
    ctx->r5 = ctx->r5 | 0XA6B5;
    // 0x80803364: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80803368: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8080336C: jal         0x80082630
    // 0x80803370: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    _anseq_entrypoint_3(rdram, ctx);
        goto after_249;
    // 0x80803370: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    after_249:
L_80803374:
    // 0x80803374: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80803378:
    // 0x80803378: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8080337C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80803380: jr          $ra
    // 0x80803384: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80803384: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_8080100C_chskeletonexplode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080100C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801010: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80801014: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801018: bne         $a1, $at, L_80801030
    if (ctx->r5 != ctx->r1) {
        // 0x8080101C: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80801030;
    }
    // 0x8080101C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80801020: jal         0x80800E88
    // 0x80801024: nop

    func_80800E88_chskeletonexplode(rdram, ctx);
        goto after_0;
    // 0x80801024: nop

    after_0:
    // 0x80801028: b           L_80801038
    // 0x8080102C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801038;
    // 0x8080102C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801030:
    // 0x80801030: b           L_80801038
    // 0x80801034: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801038;
    // 0x80801034: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801038:
    // 0x80801038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080103C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801040: jr          $ra
    // 0x80801044: nop

    return;
    // 0x80801044: nop

;}
RECOMP_FUNC void bakey_getControllerIndex(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800918F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800918FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80091900: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x80091904: jal         0x800BCCF4
    // 0x80091908: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800BCCF4(rdram, ctx);
        goto after_0;
    // 0x80091908: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x8009190C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80091910: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80091914: jr          $ra
    // 0x80091918: nop

    return;
    // 0x80091918: nop

;}
RECOMP_FUNC void _bstaxi_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083E10: syscall     96
    recomp_syscall_handler(rdram, ctx, 0x80083E10);
    return;
    // 0x80083E14: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_8080047C_chjiggytemple(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080047C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800480: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800484: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x80800488: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(784, 0X9BC) << 16);
    // 0x8080048C: addiu       $a3, $a3, 0x9BC
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(784, 0X9BC));
    // 0x80800490: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800494: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800498: jal         0x80089D50
    // 0x8080049C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x8080049C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x808004A0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x808004A4: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(784, 0X9D0) << 16);
    // 0x808004A8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808004AC: lbu         $a0, 0x24($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X24);
    // 0x808004B0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808004B4: addiu       $a3, $a3, 0x9D0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(784, 0X9D0));
    // 0x808004B8: jal         0x80089D68
    // 0x808004BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x808004BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x808004C0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x808004C4: sb          $v0, 0x24($t7)
    MEM_B(0X24, ctx->r15) = ctx->r2;
    // 0x808004C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808004CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808004D0: jr          $ra
    // 0x808004D4: nop

    return;
    // 0x808004D4: nop

;}
RECOMP_FUNC void _gccollectDll_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088048: syscall     666
    recomp_syscall_handler(rdram, ctx, 0x80088048);
    return;
    // 0x8008804C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void subaddieaudioloop_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800034: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800038: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080003C: lbu         $a2, 0x5F($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X5F);
    // 0x80800040: beql        $a2, $zero, L_80800054
    if (ctx->r6 == 0) {
        // 0x80800044: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800054;
    }
    goto skip_0;
    // 0x80800044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800048: jal         0x800C3058
    // 0x8080004C: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    func_800C3058(rdram, ctx);
        goto after_0;
    // 0x8080004C: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    after_0:
    // 0x80800050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800054:
    // 0x80800054: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800058: jr          $ra
    // 0x8080005C: nop

    return;
    // 0x8080005C: nop

;}
RECOMP_FUNC void func_808022CC_chaliendad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808022CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808022D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808022D4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808022D8: jal         0x80100094
    // 0x808022DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808022DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808022E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808022E4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x808022E8: jal         0x80102424
    // 0x808022EC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x808022EC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808022F0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808022F4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808022F8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808022FC: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80802300: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80802304: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80802308: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8080230C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80802310: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    // 0x80802314: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80802318: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x8080231C: swc1        $f6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f6.u32l;
    // 0x80802320: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802324: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802328: jr          $ra
    // 0x8080232C: nop

    return;
    // 0x8080232C: nop

;}
RECOMP_FUNC void func_80090840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090840: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80090844: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090848: jal         0x800F54E4
    // 0x8009084C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8009084C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80090850: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80090854: jal         0x800F8804
    // 0x80090858: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800F8804(rdram, ctx);
        goto after_1;
    // 0x80090858: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8009085C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80090860: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80090864: jr          $ra
    // 0x80090868: nop

    return;
    // 0x80090868: nop

;}
RECOMP_FUNC void suquiz_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006C8: beq         $a0, $zero, L_808006EC
    if (ctx->r4 == 0) {
        // 0x808006CC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_808006EC;
    }
    // 0x808006CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808006D4: bne         $a0, $at, L_808006FC
    if (ctx->r4 != ctx->r1) {
        // 0x808006D8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808006FC;
    }
    // 0x808006D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808006DC: jal         0x800DA298
    // 0x808006E0: addiu       $a0, $zero, 0x582
    ctx->r4 = ADD32(0, 0X582);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808006E0: addiu       $a0, $zero, 0x582
    ctx->r4 = ADD32(0, 0X582);
    after_0:
    // 0x808006E4: b           L_80800700
    // 0x808006E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800700;
    // 0x808006E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808006EC:
    // 0x808006EC: jal         0x800DA298
    // 0x808006F0: addiu       $a0, $zero, 0x583
    ctx->r4 = ADD32(0, 0X583);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x808006F0: addiu       $a0, $zero, 0x583
    ctx->r4 = ADD32(0, 0X583);
    after_1:
    // 0x808006F4: b           L_80800700
    // 0x808006F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800700;
    // 0x808006F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808006FC:
    // 0x808006FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800700:
    // 0x80800700: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800704: jr          $ra
    // 0x80800708: nop

    return;
    // 0x80800708: nop

;}
RECOMP_FUNC void func_80800384_susplinet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800384: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80800388: lh          $t8, 0x30($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X30);
    // 0x8080038C: lh          $v1, 0x4C($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X4C);
    // 0x80800390: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80800394: addu        $v0, $a0, $t8
    ctx->r2 = ADD32(ctx->r4, ctx->r24);
    // 0x80800398: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x8080039C: addu        $a2, $v0, $t9
    ctx->r6 = ADD32(ctx->r2, ctx->r25);
    // 0x808003A0: lh          $t0, 0x0($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X0);
    // 0x808003A4: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x808003A8: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x808003AC: beql        $at, $zero, L_808003F0
    if (ctx->r1 == 0) {
        // 0x808003B0: lh          $t5, 0x2($a2)
        ctx->r13 = MEM_H(ctx->r6, 0X2);
            goto L_808003F0;
    }
    goto skip_0;
    // 0x808003B0: lh          $t5, 0x2($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X2);
    skip_0:
    // 0x808003B4: blezl       $v1, L_808003F0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x808003B8: lh          $t5, 0x2($a2)
        ctx->r13 = MEM_H(ctx->r6, 0X2);
            goto L_808003F0;
    }
    goto skip_1;
    // 0x808003B8: lh          $t5, 0x2($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X2);
    skip_1:
    // 0x808003BC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
L_808003C0:
    // 0x808003C0: sll         $t1, $v1, 16
    ctx->r9 = S32(ctx->r3 << 16);
    // 0x808003C4: sra         $t2, $t1, 16
    ctx->r10 = S32(SIGNED(ctx->r9) >> 16);
    // 0x808003C8: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x808003CC: addu        $a2, $v0, $t3
    ctx->r6 = ADD32(ctx->r2, ctx->r11);
    // 0x808003D0: lh          $t4, 0x0($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X0);
    // 0x808003D4: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
    // 0x808003D8: slt         $at, $a1, $t4
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x808003DC: beql        $at, $zero, L_808003F0
    if (ctx->r1 == 0) {
        // 0x808003E0: lh          $t5, 0x2($a2)
        ctx->r13 = MEM_H(ctx->r6, 0X2);
            goto L_808003F0;
    }
    goto skip_2;
    // 0x808003E0: lh          $t5, 0x2($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X2);
    skip_2:
    // 0x808003E4: bgtzl       $t2, L_808003C0
    if (SIGNED(ctx->r10) > 0) {
        // 0x808003E8: addiu       $v1, $v1, -0x1
        ctx->r3 = ADD32(ctx->r3, -0X1);
            goto L_808003C0;
    }
    goto skip_3;
    // 0x808003E8: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    skip_3:
    // 0x808003EC: lh          $t5, 0x2($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X2);
L_808003F0:
    // 0x808003F0: slt         $at, $t5, $a1
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x808003F4: beql        $at, $zero, L_80800444
    if (ctx->r1 == 0) {
        // 0x808003F8: sh          $v1, 0x4C($a0)
        MEM_H(0X4C, ctx->r4) = ctx->r3;
            goto L_80800444;
    }
    goto skip_4;
    // 0x808003F8: sh          $v1, 0x4C($a0)
    MEM_H(0X4C, ctx->r4) = ctx->r3;
    skip_4:
    // 0x808003FC: lh          $a2, 0x4E($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X4E);
    // 0x80800400: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80800404: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80800408: beql        $at, $zero, L_80800444
    if (ctx->r1 == 0) {
        // 0x8080040C: sh          $v1, 0x4C($a0)
        MEM_H(0X4C, ctx->r4) = ctx->r3;
            goto L_80800444;
    }
    goto skip_5;
    // 0x8080040C: sh          $v1, 0x4C($a0)
    MEM_H(0X4C, ctx->r4) = ctx->r3;
    skip_5:
    // 0x80800410: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80800414:
    // 0x80800414: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x80800418: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8080041C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80800420: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80800424: lh          $t0, 0x2($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X2);
    // 0x80800428: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x8080042C: slt         $at, $t0, $a1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80800430: beq         $at, $zero, L_80800440
    if (ctx->r1 == 0) {
        // 0x80800434: slt         $at, $t7, $a2
        ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_80800440;
    }
    // 0x80800434: slt         $at, $t7, $a2
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80800438: bnel        $at, $zero, L_80800414
    if (ctx->r1 != 0) {
        // 0x8080043C: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80800414;
    }
    goto skip_6;
    // 0x8080043C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_6:
L_80800440:
    // 0x80800440: sh          $v1, 0x4C($a0)
    MEM_H(0X4C, ctx->r4) = ctx->r3;
L_80800444:
    // 0x80800444: jr          $ra
    // 0x80800448: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80800448: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80021884(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021884: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80021888: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002188C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80021890: jal         0x80020E74
    // 0x80021894: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80020E74(rdram, ctx);
        goto after_0;
    // 0x80021894: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x80021898: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8002189C: lw          $a1, 0x11F4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X11F4);
    // 0x800218A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800218A4: jal         0x80020E40
    // 0x800218A8: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    func_80020E40(rdram, ctx);
        goto after_1;
    // 0x800218A8: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    after_1:
    // 0x800218AC: b           L_800218B4
    // 0x800218B0: nop

        goto L_800218B4;
    // 0x800218B0: nop

L_800218B4:
    // 0x800218B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800218B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800218BC: jr          $ra
    // 0x800218C0: nop

    return;
    // 0x800218C0: nop

;}
RECOMP_FUNC void func_8080092C_chnewmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080092C: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80800930: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1584, 0X1AD4) << 16);
    // 0x80800934: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800938: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x8080093C: addiu       $t7, $t7, 0x1AD4
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1584, 0X1AD4));
    // 0x80800940: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80800944: addiu       $t6, $sp, 0x6C
    ctx->r14 = ADD32(ctx->r29, 0X6C);
    // 0x80800948: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x8080094C: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80800950: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80800954: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x80800958: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080095C: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80800960: jal         0x80100094
    // 0x80800964: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800964: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    after_0:
    // 0x80800968: jal         0x800C0638
    // 0x8080096C: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    func_800C0638(rdram, ctx);
        goto after_1;
    // 0x8080096C: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800970: beq         $v0, $zero, L_8080098C
    if (ctx->r2 == 0) {
        // 0x80800974: lw          $t2, 0x78($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X78);
            goto L_8080098C;
    }
    // 0x80800974: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x80800978: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8080097C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800980: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x80800984: b           L_808009BC
    // 0x80800988: swc1        $f4, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->f4.u32l;
        goto L_808009BC;
    // 0x80800988: swc1        $f4, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->f4.u32l;
L_8080098C:
    // 0x8080098C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800990: lwc1        $f8, 0x24($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X24);
    // 0x80800994: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80800998: nop

    // 0x8080099C: bc1f        L_808009BC
    if (!c1cs) {
        // 0x808009A0: nop
    
            goto L_808009BC;
    }
    // 0x808009A0: nop

    // 0x808009A4: jal         0x800D8FF8
    // 0x808009A8: nop

    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x808009A8: nop

    after_2:
    // 0x808009AC: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x808009B0: lwc1        $f10, 0x24($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X24);
    // 0x808009B4: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x808009B8: swc1        $f16, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->f16.u32l;
L_808009BC:
    // 0x808009BC: jal         0x8080011C
    // 0x808009C0: nop

    func_8080011C_chnewmumbo(rdram, ctx);
        goto after_3;
    // 0x808009C0: nop

    after_3:
    // 0x808009C4: jal         0x800DA298
    // 0x808009C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x808009C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x808009CC: bne         $v0, $zero, L_808009F4
    if (ctx->r2 != 0) {
        // 0x808009D0: lw          $t4, 0x78($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X78);
            goto L_808009F4;
    }
    // 0x808009D0: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
    // 0x808009D4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x808009D8: lwc1        $f4, 0x24($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X24);
    // 0x808009DC: c.le.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl <= ctx->f18.fl;
    // 0x808009E0: nop

    // 0x808009E4: bc1f        L_808009F4
    if (!c1cs) {
        // 0x808009E8: nop
    
            goto L_808009F4;
    }
    // 0x808009E8: nop

    // 0x808009EC: jal         0x800D1824
    // 0x808009F0: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    func_800D1824(rdram, ctx);
        goto after_5;
    // 0x808009F0: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    after_5:
L_808009F4:
    // 0x808009F4: jal         0x8010D278
    // 0x808009F8: nop

    func_8010D278(rdram, ctx);
        goto after_6;
    // 0x808009F8: nop

    after_6:
    // 0x808009FC: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80800A00: bnel        $v0, $at, L_80800A38
    if (ctx->r2 != ctx->r1) {
        // 0x80800A04: lw          $t5, 0x5C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X5C);
            goto L_80800A38;
    }
    goto skip_0;
    // 0x80800A04: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    skip_0:
    // 0x80800A08: jal         0x8010D254
    // 0x80800A0C: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    func_8010D254(rdram, ctx);
        goto after_7;
    // 0x80800A0C: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_7:
    // 0x80800A10: jal         0x800878A0
    // 0x80800A14: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _plsu_entrypoint_1(rdram, ctx);
        goto after_8;
    // 0x80800A14: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
    // 0x80800A18: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x80800A1C: jal         0x800F6D24
    // 0x80800A20: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6D24(rdram, ctx);
        goto after_9;
    // 0x80800A20: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_9:
    // 0x80800A24: beq         $v0, $zero, L_80800A34
    if (ctx->r2 == 0) {
        // 0x80800A28: lw          $a0, 0x58($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X58);
            goto L_80800A34;
    }
    // 0x80800A28: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80800A2C: jal         0x800F8804
    // 0x80800A30: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_800F8804(rdram, ctx);
        goto after_10;
    // 0x80800A30: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_10:
L_80800A34:
    // 0x80800A34: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
L_80800A38:
    // 0x80800A38: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x80800A3C: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80800A40: lbu         $t9, 0x0($t5)
    ctx->r25 = MEM_BU(ctx->r13, 0X0);
    // 0x80800A44: bne         $t9, $zero, L_80800A88
    if (ctx->r25 != 0) {
        // 0x80800A48: nop
    
            goto L_80800A88;
    }
    // 0x80800A48: nop

    // 0x80800A4C: lwc1        $f0, 0x38($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X38);
    // 0x80800A50: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800A54: lui         $at, 0xC296
    ctx->r1 = S32(0XC296 << 16);
    // 0x80800A58: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800A5C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800A60: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800A64: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800A68: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800A6C: addiu       $a0, $t8, 0x4
    ctx->r4 = ADD32(ctx->r24, 0X4);
    // 0x80800A70: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80800A74: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800A78: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80800A7C: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80800A80: jal         0x8008FB10
    // 0x80800A84: nop

    func_8008FB10(rdram, ctx);
        goto after_11;
    // 0x80800A84: nop

    after_11:
L_80800A88:
    // 0x80800A88: jal         0x8010D254
    // 0x80800A8C: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    func_8010D254(rdram, ctx);
        goto after_12;
    // 0x80800A8C: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    after_12:
    // 0x80800A90: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80800A94: jal         0x80100094
    // 0x80800A98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_13;
    // 0x80800A98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x80800A9C: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x80800AA0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800AA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800AA8: jal         0x800897D8
    // 0x80800AAC: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_14;
    // 0x80800AAC: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    after_14:
    // 0x80800AB0: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x80800AB4: lhu         $t0, 0x72($t7)
    ctx->r8 = MEM_HU(ctx->r15, 0X72);
    // 0x80800AB8: srl         $t1, $t0, 10
    ctx->r9 = S32(U32(ctx->r8) >> 10);
    // 0x80800ABC: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80800AC0: sltiu       $at, $t2, 0x13
    ctx->r1 = ctx->r10 < 0X13 ? 1 : 0;
    // 0x80800AC4: beq         $at, $zero, L_808014EC
    if (ctx->r1 == 0) {
        // 0x80800AC8: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_808014EC;
    }
    // 0x80800AC8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80800ACC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1584, 0X18CC) << 16);
    // 0x80800AD0: addu        $at, $at, $t2
    gpr jr_addend_80800AD8 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80800AD4: lw          $t2, 0x18CC($at)
    ctx->r10 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1584, 0X18CC));
    // 0x80800AD8: jr          $t2
    // 0x80800ADC: nop

    switch (jr_addend_80800AD8 >> 2) {
        case 0: goto L_80800BC8; break;
        case 1: goto L_80800C9C; break;
        case 2: goto L_808014EC; break;
        case 3: goto L_808014EC; break;
        case 4: goto L_80800CFC; break;
        case 5: goto L_80800D24; break;
        case 6: goto L_80800F1C; break;
        case 7: goto L_80800F44; break;
        case 8: goto L_80801368; break;
        case 9: goto L_808013E8; break;
        case 10: goto L_8080140C; break;
        case 11: goto L_808014EC; break;
        case 12: goto L_808010A0; break;
        case 13: goto L_80801280; break;
        case 14: goto L_808012B0; break;
        case 15: goto L_80801330; break;
        case 16: goto L_80801130; break;
        case 17: goto L_80801208; break;
        case 18: goto L_80800AE0; break;
        default: switch_error(__func__, 0x80800AD8, 0x808018CC);
    }
    // 0x80800ADC: nop

L_80800AE0:
    // 0x80800AE0: jal         0x8008FD70
    // 0x80800AE4: nop

    func_8008FD70(rdram, ctx);
        goto after_15;
    // 0x80800AE4: nop

    after_15:
    // 0x80800AE8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800AEC: beq         $v0, $at, L_80800B14
    if (ctx->r2 == ctx->r1) {
        // 0x80800AF0: lw          $t3, 0x78($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X78);
            goto L_80800B14;
    }
    // 0x80800AF0: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80800AF4: addiu       $at, $zero, 0x200
    ctx->r1 = ADD32(0, 0X200);
    // 0x80800AF8: beq         $v0, $at, L_80800B64
    if (ctx->r2 == ctx->r1) {
        // 0x80800AFC: lw          $t7, 0x78($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X78);
            goto L_80800B64;
    }
    // 0x80800AFC: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x80800B00: addiu       $at, $zero, 0x400
    ctx->r1 = ADD32(0, 0X400);
    // 0x80800B04: beql        $v0, $at, L_80800B68
    if (ctx->r2 == ctx->r1) {
        // 0x80800B08: lw          $t0, 0x74($t7)
        ctx->r8 = MEM_W(ctx->r15, 0X74);
            goto L_80800B68;
    }
    goto skip_1;
    // 0x80800B08: lw          $t0, 0x74($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X74);
    skip_1:
    // 0x80800B0C: b           L_808014F0
    // 0x80800B10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808014F0;
    // 0x80800B10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800B14:
    // 0x80800B14: lw          $t4, 0x74($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X74);
    // 0x80800B18: sll         $t9, $t4, 1
    ctx->r25 = S32(ctx->r12 << 1);
    // 0x80800B1C: bltzl       $t9, L_808014F0
    if (SIGNED(ctx->r25) < 0) {
        // 0x80800B20: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808014F0;
    }
    goto skip_2;
    // 0x80800B20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80800B24: lwc1        $f6, 0x48($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X48);
    // 0x80800B28: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80800B2C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800B30: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80800B34: addiu       $a0, $t3, 0x4
    ctx->r4 = ADD32(ctx->r11, 0X4);
    // 0x80800B38: addiu       $a2, $zero, 0x2EE
    ctx->r6 = ADD32(0, 0X2EE);
    // 0x80800B3C: addiu       $a3, $zero, 0x5A
    ctx->r7 = ADD32(0, 0X5A);
    // 0x80800B40: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800B44: jal         0x8008A1E0
    // 0x80800B48: nop

    _subaddiedialog_entrypoint_6(rdram, ctx);
        goto after_16;
    // 0x80800B48: nop

    after_16:
    // 0x80800B4C: beq         $v0, $zero, L_808014EC
    if (ctx->r2 == 0) {
        // 0x80800B50: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_808014EC;
    }
    // 0x80800B50: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80800B54: jal         0x80800264
    // 0x80800B58: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800264_chnewmumbo(rdram, ctx);
        goto after_17;
    // 0x80800B58: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_17:
    // 0x80800B5C: b           L_808014F0
    // 0x80800B60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808014F0;
    // 0x80800B60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800B64:
    // 0x80800B64: lw          $t0, 0x74($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X74);
L_80800B68:
    // 0x80800B68: sll         $t2, $t0, 1
    ctx->r10 = S32(ctx->r8 << 1);
    // 0x80800B6C: bltzl       $t2, L_808014F0
    if (SIGNED(ctx->r10) < 0) {
        // 0x80800B70: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808014F0;
    }
    goto skip_3;
    // 0x80800B70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80800B74: lwc1        $f10, 0x48($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X48);
    // 0x80800B78: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x80800B7C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80800B80: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80800B84: addiu       $a0, $t7, 0x4
    ctx->r4 = ADD32(ctx->r15, 0X4);
    // 0x80800B88: addiu       $a2, $zero, 0x2EE
    ctx->r6 = ADD32(0, 0X2EE);
    // 0x80800B8C: addiu       $a3, $zero, 0x5A
    ctx->r7 = ADD32(0, 0X5A);
    // 0x80800B90: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80800B94: jal         0x8008A1E0
    // 0x80800B98: nop

    _subaddiedialog_entrypoint_6(rdram, ctx);
        goto after_18;
    // 0x80800B98: nop

    after_18:
    // 0x80800B9C: beq         $v0, $zero, L_808014EC
    if (ctx->r2 == 0) {
        // 0x80800BA0: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_808014EC;
    }
    // 0x80800BA0: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80800BA4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800BA8: jal         0x80800000
    // 0x80800BAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800000_chnewmumbo(rdram, ctx);
        goto after_19;
    // 0x80800BAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_19:
    // 0x80800BB0: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80800BB4: addiu       $a1, $zero, 0x11EB
    ctx->r5 = ADD32(0, 0X11EB);
    // 0x80800BB8: jal         0x808000DC
    // 0x80800BBC: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_808000DC_chnewmumbo(rdram, ctx);
        goto after_20;
    // 0x80800BBC: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_20:
    // 0x80800BC0: b           L_808014F0
    // 0x80800BC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808014F0;
    // 0x80800BC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800BC8:
    // 0x80800BC8: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x80800BCC: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800BD0: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800BD4: lbu         $t3, 0x77($t9)
    ctx->r11 = MEM_BU(ctx->r25, 0X77);
    // 0x80800BD8: andi        $t8, $t3, 0xFFF0
    ctx->r24 = ctx->r11 & 0XFFF0;
    // 0x80800BDC: ori         $t6, $t8, 0x2
    ctx->r14 = ctx->r24 | 0X2;
    // 0x80800BE0: sb          $t6, 0x77($t9)
    MEM_B(0X77, ctx->r25) = ctx->r14;
    // 0x80800BE4: jal         0x80101E14
    // 0x80800BE8: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    func_80101E14(rdram, ctx);
        goto after_21;
    // 0x80800BE8: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    after_21:
    // 0x80800BEC: beq         $v0, $zero, L_80800C10
    if (ctx->r2 == 0) {
        // 0x80800BF0: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_80800C10;
    }
    // 0x80800BF0: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80800BF4: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80800BF8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1584, 0X1990) << 16);
    // 0x80800BFC: addiu       $a2, $a2, 0x1990
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1584, 0X1990));
    // 0x80800C00: jal         0x80089D18
    // 0x80800C04: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_22;
    // 0x80800C04: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_22:
    // 0x80800C08: b           L_80800C34
    // 0x80800C0C: nop

        goto L_80800C34;
    // 0x80800C0C: nop

L_80800C10:
    // 0x80800C10: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x80800C14: jal         0x80101E14
    // 0x80800C18: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    func_80101E14(rdram, ctx);
        goto after_23;
    // 0x80800C18: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    after_23:
    // 0x80800C1C: beq         $v0, $zero, L_80800C34
    if (ctx->r2 == 0) {
        // 0x80800C20: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_80800C34;
    }
    // 0x80800C20: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80800C24: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1584, 0X199C) << 16);
    // 0x80800C28: addiu       $a2, $a2, 0x199C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1584, 0X199C));
    // 0x80800C2C: jal         0x80089D18
    // 0x80800C30: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_24;
    // 0x80800C30: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_24:
L_80800C34:
    // 0x80800C34: jal         0x8008FD70
    // 0x80800C38: nop

    func_8008FD70(rdram, ctx);
        goto after_25;
    // 0x80800C38: nop

    after_25:
    // 0x80800C3C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800C40: beq         $v0, $at, L_80800C5C
    if (ctx->r2 == ctx->r1) {
        // 0x80800C44: lw          $t0, 0x78($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X78);
            goto L_80800C5C;
    }
    // 0x80800C44: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x80800C48: addiu       $at, $zero, 0x200
    ctx->r1 = ADD32(0, 0X200);
    // 0x80800C4C: beq         $v0, $at, L_80800C5C
    if (ctx->r2 == ctx->r1) {
        // 0x80800C50: addiu       $at, $zero, 0x400
        ctx->r1 = ADD32(0, 0X400);
            goto L_80800C5C;
    }
    // 0x80800C50: addiu       $at, $zero, 0x400
    ctx->r1 = ADD32(0, 0X400);
    // 0x80800C54: bnel        $v0, $at, L_808014F0
    if (ctx->r2 != ctx->r1) {
        // 0x80800C58: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808014F0;
    }
    goto skip_4;
    // 0x80800C58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
L_80800C5C:
    // 0x80800C5C: lwc1        $f18, 0x48($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X48);
    // 0x80800C60: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x80800C64: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800C68: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80800C6C: addiu       $a0, $t0, 0x4
    ctx->r4 = ADD32(ctx->r8, 0X4);
    // 0x80800C70: addiu       $a2, $zero, 0x1F4
    ctx->r6 = ADD32(0, 0X1F4);
    // 0x80800C74: addiu       $a3, $zero, 0x5A
    ctx->r7 = ADD32(0, 0X5A);
    // 0x80800C78: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80800C7C: jal         0x8008A1C8
    // 0x80800C80: nop

    _subaddiedialog_entrypoint_3(rdram, ctx);
        goto after_26;
    // 0x80800C80: nop

    after_26:
    // 0x80800C84: beq         $v0, $zero, L_808014EC
    if (ctx->r2 == 0) {
        // 0x80800C88: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_808014EC;
    }
    // 0x80800C88: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80800C8C: jal         0x80800264
    // 0x80800C90: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800264_chnewmumbo(rdram, ctx);
        goto after_27;
    // 0x80800C90: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_27:
    // 0x80800C94: b           L_808014F0
    // 0x80800C98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808014F0;
    // 0x80800C98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800C9C:
    // 0x80800C9C: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800CA0: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80800CA4: jal         0x80101E14
    // 0x80800CA8: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    func_80101E14(rdram, ctx);
        goto after_28;
    // 0x80800CA8: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    after_28:
    // 0x80800CAC: beq         $v0, $zero, L_80800CD0
    if (ctx->r2 == 0) {
        // 0x80800CB0: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_80800CD0;
    }
    // 0x80800CB0: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80800CB4: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80800CB8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1584, 0X1990) << 16);
    // 0x80800CBC: addiu       $a2, $a2, 0x1990
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1584, 0X1990));
    // 0x80800CC0: jal         0x80089D18
    // 0x80800CC4: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_29;
    // 0x80800CC4: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_29:
    // 0x80800CC8: b           L_808014F0
    // 0x80800CCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808014F0;
    // 0x80800CCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800CD0:
    // 0x80800CD0: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x80800CD4: jal         0x80101E14
    // 0x80800CD8: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    func_80101E14(rdram, ctx);
        goto after_30;
    // 0x80800CD8: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    after_30:
    // 0x80800CDC: beq         $v0, $zero, L_808014EC
    if (ctx->r2 == 0) {
        // 0x80800CE0: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_808014EC;
    }
    // 0x80800CE0: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80800CE4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1584, 0X199C) << 16);
    // 0x80800CE8: addiu       $a2, $a2, 0x199C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1584, 0X199C));
    // 0x80800CEC: jal         0x80089D18
    // 0x80800CF0: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_31;
    // 0x80800CF0: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_31:
    // 0x80800CF4: b           L_808014F0
    // 0x80800CF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808014F0;
    // 0x80800CF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800CFC:
    // 0x80800CFC: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x80800D00: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80800D04: jal         0x80101E14
    // 0x80800D08: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    func_80101E14(rdram, ctx);
        goto after_32;
    // 0x80800D08: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    after_32:
    // 0x80800D0C: beq         $v0, $zero, L_808014EC
    if (ctx->r2 == 0) {
        // 0x80800D10: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_808014EC;
    }
    // 0x80800D10: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80800D14: jal         0x80800264
    // 0x80800D18: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800264_chnewmumbo(rdram, ctx);
        goto after_33;
    // 0x80800D18: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_33:
    // 0x80800D1C: b           L_808014F0
    // 0x80800D20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808014F0;
    // 0x80800D20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800D24:
    // 0x80800D24: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80800D28: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80800D2C: jal         0x80101E14
    // 0x80800D30: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    func_80101E14(rdram, ctx);
        goto after_34;
    // 0x80800D30: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_34:
    // 0x80800D34: beq         $v0, $zero, L_80800D4C
    if (ctx->r2 == 0) {
        // 0x80800D38: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_80800D4C;
    }
    // 0x80800D38: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80800D3C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1584, 0X19A8) << 16);
    // 0x80800D40: addiu       $a2, $a2, 0x19A8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1584, 0X19A8));
    // 0x80800D44: jal         0x80089D18
    // 0x80800D48: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_35;
    // 0x80800D48: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_35:
L_80800D4C:
    // 0x80800D4C: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x80800D50: lw          $v0, 0x6C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X6C);
    // 0x80800D54: andi        $t4, $v0, 0x1FF
    ctx->r12 = ctx->r2 & 0X1FF;
    // 0x80800D58: sltiu       $at, $t4, 0x64
    ctx->r1 = ctx->r12 < 0X64 ? 1 : 0;
    // 0x80800D5C: beq         $at, $zero, L_80800E10
    if (ctx->r1 == 0) {
        // 0x80800D60: nop
    
            goto L_80800E10;
    }
    // 0x80800D60: nop

    // 0x80800D64: lhu         $t8, 0x6E($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X6E);
    // 0x80800D68: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80800D6C: andi        $t3, $t5, 0x1FF
    ctx->r11 = ctx->r13 & 0X1FF;
    // 0x80800D70: andi        $t6, $t8, 0xFE00
    ctx->r14 = ctx->r24 & 0XFE00;
    // 0x80800D74: or          $t9, $t3, $t6
    ctx->r25 = ctx->r11 | ctx->r14;
    // 0x80800D78: sh          $t9, 0x6E($t7)
    MEM_H(0X6E, ctx->r15) = ctx->r25;
    // 0x80800D7C: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x80800D80: lw          $v0, 0x6C($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X6C);
    // 0x80800D84: andi        $t1, $v0, 0x1FF
    ctx->r9 = ctx->r2 & 0X1FF;
    // 0x80800D88: sltiu       $at, $t1, 0x14
    ctx->r1 = ctx->r9 < 0X14 ? 1 : 0;
    // 0x80800D8C: beq         $at, $zero, L_80800DA8
    if (ctx->r1 == 0) {
        // 0x80800D90: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_80800DA8;
    }
    // 0x80800D90: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80800D94: lbu         $t2, 0x7A($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X7A);
    // 0x80800D98: andi        $t4, $t2, 0xFFF1
    ctx->r12 = ctx->r10 & 0XFFF1;
    // 0x80800D9C: ori         $t5, $t4, 0x6
    ctx->r13 = ctx->r12 | 0X6;
    // 0x80800DA0: b           L_80800E88
    // 0x80800DA4: sb          $t5, 0x7A($t0)
    MEM_B(0X7A, ctx->r8) = ctx->r13;
        goto L_80800E88;
    // 0x80800DA4: sb          $t5, 0x7A($t0)
    MEM_B(0X7A, ctx->r8) = ctx->r13;
L_80800DA8:
    // 0x80800DA8: sltiu       $at, $v0, 0x28
    ctx->r1 = ctx->r2 < 0X28 ? 1 : 0;
    // 0x80800DAC: beq         $at, $zero, L_80800DC8
    if (ctx->r1 == 0) {
        // 0x80800DB0: lw          $t8, 0x78($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X78);
            goto L_80800DC8;
    }
    // 0x80800DB0: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x80800DB4: lbu         $t3, 0x7A($t8)
    ctx->r11 = MEM_BU(ctx->r24, 0X7A);
    // 0x80800DB8: andi        $t6, $t3, 0xFFF1
    ctx->r14 = ctx->r11 & 0XFFF1;
    // 0x80800DBC: ori         $t9, $t6, 0x4
    ctx->r25 = ctx->r14 | 0X4;
    // 0x80800DC0: b           L_80800E88
    // 0x80800DC4: sb          $t9, 0x7A($t8)
    MEM_B(0X7A, ctx->r24) = ctx->r25;
        goto L_80800E88;
    // 0x80800DC4: sb          $t9, 0x7A($t8)
    MEM_B(0X7A, ctx->r24) = ctx->r25;
L_80800DC8:
    // 0x80800DC8: sltiu       $at, $v0, 0x3C
    ctx->r1 = ctx->r2 < 0X3C ? 1 : 0;
    // 0x80800DCC: beq         $at, $zero, L_80800DEC
    if (ctx->r1 == 0) {
        // 0x80800DD0: lw          $t5, 0x78($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X78);
            goto L_80800DEC;
    }
    // 0x80800DD0: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x80800DD4: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x80800DD8: lbu         $t1, 0x7A($t7)
    ctx->r9 = MEM_BU(ctx->r15, 0X7A);
    // 0x80800DDC: andi        $t2, $t1, 0xFFF1
    ctx->r10 = ctx->r9 & 0XFFF1;
    // 0x80800DE0: ori         $t4, $t2, 0x2
    ctx->r12 = ctx->r10 | 0X2;
    // 0x80800DE4: b           L_80800E88
    // 0x80800DE8: sb          $t4, 0x7A($t7)
    MEM_B(0X7A, ctx->r15) = ctx->r12;
        goto L_80800E88;
    // 0x80800DE8: sb          $t4, 0x7A($t7)
    MEM_B(0X7A, ctx->r15) = ctx->r12;
L_80800DEC:
    // 0x80800DEC: lbu         $t0, 0x7A($t5)
    ctx->r8 = MEM_BU(ctx->r13, 0X7A);
    // 0x80800DF0: andi        $t3, $t0, 0xFFF1
    ctx->r11 = ctx->r8 & 0XFFF1;
    // 0x80800DF4: sb          $t3, 0x7A($t5)
    MEM_B(0X7A, ctx->r13) = ctx->r11;
    // 0x80800DF8: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x80800DFC: lbu         $t9, 0x7A($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X7A);
    // 0x80800E00: andi        $t8, $t9, 0xFFCF
    ctx->r24 = ctx->r25 & 0XFFCF;
    // 0x80800E04: ori         $t1, $t8, 0x10
    ctx->r9 = ctx->r24 | 0X10;
    // 0x80800E08: b           L_80800E88
    // 0x80800E0C: sb          $t1, 0x7A($t6)
    MEM_B(0X7A, ctx->r14) = ctx->r9;
        goto L_80800E88;
    // 0x80800E0C: sb          $t1, 0x7A($t6)
    MEM_B(0X7A, ctx->r14) = ctx->r9;
L_80800E10:
    // 0x80800E10: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1584, 0X1918) << 16);
    // 0x80800E14: jal         0x800DC298
    // 0x80800E18: lwc1        $f12, 0x1918($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1584, 0X1918));
    func_800DC298(rdram, ctx);
        goto after_36;
    // 0x80800E18: lwc1        $f12, 0x1918($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1584, 0X1918));
    after_36:
    // 0x80800E1C: beq         $v0, $zero, L_80800E50
    if (ctx->r2 == 0) {
        // 0x80800E20: lw          $t2, 0x78($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X78);
            goto L_80800E50;
    }
    // 0x80800E20: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x80800E24: lw          $t4, 0x78($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X78);
    // 0x80800E28: sll         $t7, $t4, 20
    ctx->r15 = S32(ctx->r12 << 20);
    // 0x80800E2C: srl         $t0, $t7, 29
    ctx->r8 = S32(U32(ctx->r15) >> 29);
    // 0x80800E30: slti        $at, $t0, 0x3
    ctx->r1 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
    // 0x80800E34: beq         $at, $zero, L_80800E50
    if (ctx->r1 == 0) {
        // 0x80800E38: nop
    
            goto L_80800E50;
    }
    // 0x80800E38: nop

    // 0x80800E3C: lbu         $t3, 0x7A($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X7A);
    // 0x80800E40: andi        $t5, $t3, 0xFFCF
    ctx->r13 = ctx->r11 & 0XFFCF;
    // 0x80800E44: ori         $t9, $t5, 0x10
    ctx->r25 = ctx->r13 | 0X10;
    // 0x80800E48: b           L_80800E88
    // 0x80800E4C: sb          $t9, 0x7A($t2)
    MEM_B(0X7A, ctx->r10) = ctx->r25;
        goto L_80800E88;
    // 0x80800E4C: sb          $t9, 0x7A($t2)
    MEM_B(0X7A, ctx->r10) = ctx->r25;
L_80800E50:
    // 0x80800E50: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1584, 0X191C) << 16);
    // 0x80800E54: jal         0x800DC298
    // 0x80800E58: lwc1        $f12, 0x191C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1584, 0X191C));
    func_800DC298(rdram, ctx);
        goto after_37;
    // 0x80800E58: lwc1        $f12, 0x191C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1584, 0X191C));
    after_37:
    // 0x80800E5C: beq         $v0, $zero, L_80800E88
    if (ctx->r2 == 0) {
        // 0x80800E60: lw          $t8, 0x78($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X78);
            goto L_80800E88;
    }
    // 0x80800E60: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x80800E64: lw          $t1, 0x78($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X78);
    // 0x80800E68: sll         $t6, $t1, 20
    ctx->r14 = S32(ctx->r9 << 20);
    // 0x80800E6C: srl         $t4, $t6, 29
    ctx->r12 = S32(U32(ctx->r14) >> 29);
    // 0x80800E70: blezl       $t4, L_80800E8C
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80800E74: lui         $a1, 0x3F7F
        ctx->r5 = S32(0X3F7F << 16);
            goto L_80800E8C;
    }
    goto skip_5;
    // 0x80800E74: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    skip_5:
    // 0x80800E78: lbu         $t7, 0x7A($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X7A);
    // 0x80800E7C: andi        $t0, $t7, 0xFFCF
    ctx->r8 = ctx->r15 & 0XFFCF;
    // 0x80800E80: ori         $t3, $t0, 0x20
    ctx->r11 = ctx->r8 | 0X20;
    // 0x80800E84: sb          $t3, 0x7A($t8)
    MEM_B(0X7A, ctx->r24) = ctx->r11;
L_80800E88:
    // 0x80800E88: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
L_80800E8C:
    // 0x80800E8C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80800E90: jal         0x80101E14
    // 0x80800E94: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    func_80101E14(rdram, ctx);
        goto after_38;
    // 0x80800E94: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    after_38:
    // 0x80800E98: beql        $v0, $zero, L_808014F0
    if (ctx->r2 == 0) {
        // 0x80800E9C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808014F0;
    }
    goto skip_6;
    // 0x80800E9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x80800EA0: jal         0x8008FD70
    // 0x80800EA4: nop

    func_8008FD70(rdram, ctx);
        goto after_39;
    // 0x80800EA4: nop

    after_39:
    // 0x80800EA8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800EAC: beq         $v0, $at, L_80800ED0
    if (ctx->r2 == ctx->r1) {
        // 0x80800EB0: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_80800ED0;
    }
    // 0x80800EB0: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80800EB4: addiu       $at, $zero, 0x200
    ctx->r1 = ADD32(0, 0X200);
    // 0x80800EB8: beq         $v0, $at, L_80800EE0
    if (ctx->r2 == ctx->r1) {
        // 0x80800EBC: addiu       $at, $zero, 0x400
        ctx->r1 = ADD32(0, 0X400);
            goto L_80800EE0;
    }
    // 0x80800EBC: addiu       $at, $zero, 0x400
    ctx->r1 = ADD32(0, 0X400);
    // 0x80800EC0: beq         $v0, $at, L_80800EE0
    if (ctx->r2 == ctx->r1) {
        // 0x80800EC4: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_80800EE0;
    }
    // 0x80800EC4: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80800EC8: b           L_80800F0C
    // 0x80800ECC: nop

        goto L_80800F0C;
    // 0x80800ECC: nop

L_80800ED0:
    // 0x80800ED0: jal         0x80800264
    // 0x80800ED4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800264_chnewmumbo(rdram, ctx);
        goto after_40;
    // 0x80800ED4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_40:
    // 0x80800ED8: b           L_808014F0
    // 0x80800EDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808014F0;
    // 0x80800EDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800EE0:
    // 0x80800EE0: jal         0x808007B0
    // 0x80800EE4: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    func_808007B0_chnewmumbo(rdram, ctx);
        goto after_41;
    // 0x80800EE4: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    after_41:
    // 0x80800EE8: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80800EEC: addiu       $a1, $zero, 0x11EB
    ctx->r5 = ADD32(0, 0X11EB);
    // 0x80800EF0: jal         0x808000DC
    // 0x80800EF4: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_808000DC_chnewmumbo(rdram, ctx);
        goto after_42;
    // 0x80800EF4: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_42:
    // 0x80800EF8: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80800EFC: jal         0x80800264
    // 0x80800F00: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80800264_chnewmumbo(rdram, ctx);
        goto after_43;
    // 0x80800F00: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_43:
    // 0x80800F04: b           L_808014F0
    // 0x80800F08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808014F0;
    // 0x80800F08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800F0C:
    // 0x80800F0C: jal         0x80800264
    // 0x80800F10: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80800264_chnewmumbo(rdram, ctx);
        goto after_44;
    // 0x80800F10: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_44:
    // 0x80800F14: b           L_808014F0
    // 0x80800F18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808014F0;
    // 0x80800F18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800F1C:
    // 0x80800F1C: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x80800F20: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80800F24: jal         0x80101E14
    // 0x80800F28: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    func_80101E14(rdram, ctx);
        goto after_45;
    // 0x80800F28: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    after_45:
    // 0x80800F2C: beq         $v0, $zero, L_808014EC
    if (ctx->r2 == 0) {
        // 0x80800F30: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_808014EC;
    }
    // 0x80800F30: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80800F34: jal         0x80800264
    // 0x80800F38: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80800264_chnewmumbo(rdram, ctx);
        goto after_46;
    // 0x80800F38: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_46:
    // 0x80800F3C: b           L_808014F0
    // 0x80800F40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808014F0;
    // 0x80800F40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800F44:
    // 0x80800F44: jal         0x8080011C
    // 0x80800F48: nop

    func_8080011C_chnewmumbo(rdram, ctx);
        goto after_47;
    // 0x80800F48: nop

    after_47:
    // 0x80800F4C: jal         0x800DA298
    // 0x80800F50: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DA298(rdram, ctx);
        goto after_48;
    // 0x80800F50: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_48:
    // 0x80800F54: bne         $v0, $zero, L_808014EC
    if (ctx->r2 != 0) {
        // 0x80800F58: lw          $t5, 0x5C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X5C);
            goto L_808014EC;
    }
    // 0x80800F58: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x80800F5C: lbu         $t9, 0x3($t5)
    ctx->r25 = MEM_BU(ctx->r13, 0X3);
    // 0x80800F60: sltiu       $at, $t9, 0x5
    ctx->r1 = ctx->r25 < 0X5 ? 1 : 0;
    // 0x80800F64: beq         $at, $zero, L_808014EC
    if (ctx->r1 == 0) {
        // 0x80800F68: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_808014EC;
    }
    // 0x80800F68: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80800F6C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1584, 0X1920) << 16);
    // 0x80800F70: addu        $at, $at, $t9
    gpr jr_addend_80800F78 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80800F74: lw          $t9, 0x1920($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1584, 0X1920));
    // 0x80800F78: jr          $t9
    // 0x80800F7C: nop

    switch (jr_addend_80800F78 >> 2) {
        case 0: goto L_808014EC; break;
        case 1: goto L_80800F80; break;
        case 2: goto L_80800FA0; break;
        case 3: goto L_80801024; break;
        case 4: goto L_80801088; break;
        default: switch_error(__func__, 0x80800F78, 0x80801920);
    }
    // 0x80800F7C: nop

L_80800F80:
    // 0x80800F80: jal         0x808007B0
    // 0x80800F84: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    func_808007B0_chnewmumbo(rdram, ctx);
        goto after_49;
    // 0x80800F84: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    after_49:
    // 0x80800F88: jal         0x80090658
    // 0x80800F8C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80090658(rdram, ctx);
        goto after_50;
    // 0x80800F8C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_50:
    // 0x80800F90: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80800F94: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80800F98: b           L_808014EC
    // 0x80800F9C: sb          $t2, 0x3($t1)
    MEM_B(0X3, ctx->r9) = ctx->r10;
        goto L_808014EC;
    // 0x80800F9C: sb          $t2, 0x3($t1)
    MEM_B(0X3, ctx->r9) = ctx->r10;
L_80800FA0:
    // 0x80800FA0: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x80800FA4: lui         $a1, 0x443B
    ctx->r5 = S32(0X443B << 16);
    // 0x80800FA8: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x80800FAC: lw          $t4, 0x7C($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X7C);
    // 0x80800FB0: addiu       $a2, $zero, 0x29F
    ctx->r6 = ADD32(0, 0X29F);
    // 0x80800FB4: addiu       $a0, $t6, 0x4
    ctx->r4 = ADD32(ctx->r14, 0X4);
    // 0x80800FB8: sll         $t0, $t4, 19
    ctx->r8 = S32(ctx->r12 << 19);
    // 0x80800FBC: bgezl       $t0, L_808014F0
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80800FC0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808014F0;
    }
    goto skip_7;
    // 0x80800FC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x80800FC4: jal         0x800902E4
    // 0x80800FC8: addiu       $a3, $sp, 0x78
    ctx->r7 = ADD32(ctx->r29, 0X78);
    func_800902E4(rdram, ctx);
        goto after_51;
    // 0x80800FC8: addiu       $a3, $sp, 0x78
    ctx->r7 = ADD32(ctx->r29, 0X78);
    after_51:
    // 0x80800FCC: beql        $v0, $zero, L_808014F0
    if (ctx->r2 == 0) {
        // 0x80800FD0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808014F0;
    }
    goto skip_8;
    // 0x80800FD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_8:
    // 0x80800FD4: jal         0x8008FE14
    // 0x80800FD8: nop

    func_8008FE14(rdram, ctx);
        goto after_52;
    // 0x80800FD8: nop

    after_52:
    // 0x80800FDC: addiu       $at, $zero, 0x29F
    ctx->r1 = ADD32(0, 0X29F);
    // 0x80800FE0: bnel        $v0, $at, L_808014F0
    if (ctx->r2 != ctx->r1) {
        // 0x80800FE4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808014F0;
    }
    goto skip_9;
    // 0x80800FE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_9:
    // 0x80800FE8: jal         0x80090818
    // 0x80800FEC: nop

    func_80090818(rdram, ctx);
        goto after_53;
    // 0x80800FEC: nop

    after_53:
    // 0x80800FF0: beql        $v0, $zero, L_808014F0
    if (ctx->r2 == 0) {
        // 0x80800FF4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808014F0;
    }
    goto skip_10;
    // 0x80800FF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_10:
    // 0x80800FF8: jal         0x8008FDEC
    // 0x80800FFC: nop

    func_8008FDEC(rdram, ctx);
        goto after_54;
    // 0x80800FFC: nop

    after_54:
    // 0x80801000: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80801004: sw          $v0, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->r2;
    // 0x80801008: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x8080100C: jal         0x80090768
    // 0x80801010: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_80090768(rdram, ctx);
        goto after_55;
    // 0x80801010: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_55:
    // 0x80801014: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x80801018: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8080101C: b           L_808014EC
    // 0x80801020: sb          $t8, 0x3($t5)
    MEM_B(0X3, ctx->r13) = ctx->r24;
        goto L_808014EC;
    // 0x80801020: sb          $t8, 0x3($t5)
    MEM_B(0X3, ctx->r13) = ctx->r24;
L_80801024:
    // 0x80801024: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x80801028: jal         0x80106790
    // 0x8080102C: lw          $a0, 0x3C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X3C);
    func_80106790(rdram, ctx);
        goto after_56;
    // 0x8080102C: lw          $a0, 0x3C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X3C);
    after_56:
    // 0x80801030: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x80801034: addiu       $a0, $v0, 0x18
    ctx->r4 = ADD32(ctx->r2, 0X18);
    // 0x80801038: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8080103C: jal         0x800EE7F8
    // 0x80801040: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_57;
    // 0x80801040: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_57:
    // 0x80801044: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x80801048: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8080104C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801050: lbu         $t1, 0x74($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X74);
    // 0x80801054: lbu         $t0, 0x65($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X65);
    // 0x80801058: ori         $t4, $t1, 0x40
    ctx->r12 = ctx->r9 | 0X40;
    // 0x8080105C: ori         $t6, $t0, 0x8
    ctx->r14 = ctx->r8 | 0X8;
    // 0x80801060: sb          $t4, 0x74($v1)
    MEM_B(0X74, ctx->r3) = ctx->r12;
    // 0x80801064: sb          $t6, 0x65($v1)
    MEM_B(0X65, ctx->r3) = ctx->r14;
    // 0x80801068: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x8080106C: sb          $t3, 0x3($t8)
    MEM_B(0X3, ctx->r24) = ctx->r11;
    // 0x80801070: jal         0x8080073C
    // 0x80801074: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    func_8080073C_chnewmumbo(rdram, ctx);
        goto after_58;
    // 0x80801074: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    after_58:
    // 0x80801078: jal         0x80090658
    // 0x8080107C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090658(rdram, ctx);
        goto after_59;
    // 0x8080107C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_59:
    // 0x80801080: b           L_808014F0
    // 0x80801084: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808014F0;
    // 0x80801084: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801088:
    // 0x80801088: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x8080108C: jal         0x80800264
    // 0x80801090: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_80800264_chnewmumbo(rdram, ctx);
        goto after_60;
    // 0x80801090: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_60:
    // 0x80801094: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x80801098: b           L_808014EC
    // 0x8080109C: sb          $zero, 0x3($t5)
    MEM_B(0X3, ctx->r13) = 0;
        goto L_808014EC;
    // 0x8080109C: sb          $zero, 0x3($t5)
    MEM_B(0X3, ctx->r13) = 0;
L_808010A0:
    // 0x808010A0: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x808010A4: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x808010A8: jal         0x80101E14
    // 0x808010AC: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    func_80101E14(rdram, ctx);
        goto after_61;
    // 0x808010AC: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    after_61:
    // 0x808010B0: beq         $v0, $zero, L_808010D0
    if (ctx->r2 == 0) {
        // 0x808010B4: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_808010D0;
    }
    // 0x808010B4: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x808010B8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1584, 0X19C0) << 16);
    // 0x808010BC: addiu       $a2, $a2, 0x19C0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1584, 0X19C0));
    // 0x808010C0: jal         0x80089D18
    // 0x808010C4: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_62;
    // 0x808010C4: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_62:
    // 0x808010C8: jal         0x80086C90
    // 0x808010CC: nop

    _chjujubagfx_entrypoint_2(rdram, ctx);
        goto after_63;
    // 0x808010CC: nop

    after_63:
L_808010D0:
    // 0x808010D0: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x808010D4: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    // 0x808010D8: jal         0x80101E14
    // 0x808010DC: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    func_80101E14(rdram, ctx);
        goto after_64;
    // 0x808010DC: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    after_64:
    // 0x808010E0: beql        $v0, $zero, L_808014F0
    if (ctx->r2 == 0) {
        // 0x808010E4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808014F0;
    }
    goto skip_11;
    // 0x808010E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_11:
    // 0x808010E8: jal         0x800FC6B0
    // 0x808010EC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_800FC6B0(rdram, ctx);
        goto after_65;
    // 0x808010EC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_65:
    // 0x808010F0: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x808010F4: jal         0x80800264
    // 0x808010F8: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    func_80800264_chnewmumbo(rdram, ctx);
        goto after_66;
    // 0x808010F8: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_66:
    // 0x808010FC: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80801100: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80801104: jal         0x80800000
    // 0x80801108: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800000_chnewmumbo(rdram, ctx);
        goto after_67;
    // 0x80801108: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_67:
    // 0x8080110C: jal         0x8080011C
    // 0x80801110: nop

    func_8080011C_chnewmumbo(rdram, ctx);
        goto after_68;
    // 0x80801110: nop

    after_68:
    // 0x80801114: jal         0x800DA544
    // 0x80801118: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DA544(rdram, ctx);
        goto after_69;
    // 0x80801118: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_69:
    // 0x8080111C: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    // 0x80801120: jal         0x800D175C
    // 0x80801124: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_800D175C(rdram, ctx);
        goto after_70;
    // 0x80801124: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_70:
    // 0x80801128: b           L_808014F0
    // 0x8080112C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808014F0;
    // 0x8080112C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801130:
    // 0x80801130: lui         $a1, 0x3D4C
    ctx->r5 = S32(0X3D4C << 16);
    // 0x80801134: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80801138: jal         0x80101E14
    // 0x8080113C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    func_80101E14(rdram, ctx);
        goto after_71;
    // 0x8080113C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    after_71:
    // 0x80801140: beq         $v0, $zero, L_80801158
    if (ctx->r2 == 0) {
        // 0x80801144: nop
    
            goto L_80801158;
    }
    // 0x80801144: nop

    // 0x80801148: jal         0x800DA544
    // 0x8080114C: addiu       $a0, $zero, 0x9F3
    ctx->r4 = ADD32(0, 0X9F3);
    func_800DA544(rdram, ctx);
        goto after_72;
    // 0x8080114C: addiu       $a0, $zero, 0x9F3
    ctx->r4 = ADD32(0, 0X9F3);
    after_72:
    // 0x80801150: b           L_808014F0
    // 0x80801154: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808014F0;
    // 0x80801154: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801158:
    // 0x80801158: jal         0x80101DDC
    // 0x8080115C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    func_80101DDC(rdram, ctx);
        goto after_73;
    // 0x8080115C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    after_73:
    // 0x80801160: beq         $v0, $zero, L_8080117C
    if (ctx->r2 == 0) {
        // 0x80801164: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_8080117C;
    }
    // 0x80801164: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80801168: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x8080116C: jal         0x80800264
    // 0x80801170: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    func_80800264_chnewmumbo(rdram, ctx);
        goto after_74;
    // 0x80801170: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_74:
    // 0x80801174: b           L_808014F0
    // 0x80801178: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808014F0;
    // 0x80801178: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080117C:
    // 0x8080117C: lui         $a1, 0x3F5E
    ctx->r5 = S32(0X3F5E << 16);
    // 0x80801180: jal         0x80101E14
    // 0x80801184: ori         $a1, $a1, 0xB852
    ctx->r5 = ctx->r5 | 0XB852;
    func_80101E14(rdram, ctx);
        goto after_75;
    // 0x80801184: ori         $a1, $a1, 0xB852
    ctx->r5 = ctx->r5 | 0XB852;
    after_75:
    // 0x80801188: beq         $v0, $zero, L_808011AC
    if (ctx->r2 == 0) {
        // 0x8080118C: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_808011AC;
    }
    // 0x8080118C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80801190: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80801194: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1584, 0X19B4) << 16);
    // 0x80801198: addiu       $a2, $a2, 0x19B4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1584, 0X19B4));
    // 0x8080119C: jal         0x80089D18
    // 0x808011A0: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_76;
    // 0x808011A0: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_76:
    // 0x808011A4: b           L_808014F0
    // 0x808011A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808014F0;
    // 0x808011A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808011AC:
    // 0x808011AC: lui         $a1, 0x3F42
    ctx->r5 = S32(0X3F42 << 16);
    // 0x808011B0: jal         0x80101E14
    // 0x808011B4: ori         $a1, $a1, 0x8F5C
    ctx->r5 = ctx->r5 | 0X8F5C;
    func_80101E14(rdram, ctx);
        goto after_77;
    // 0x808011B4: ori         $a1, $a1, 0x8F5C
    ctx->r5 = ctx->r5 | 0X8F5C;
    after_77:
    // 0x808011B8: beq         $v0, $zero, L_808011DC
    if (ctx->r2 == 0) {
        // 0x808011BC: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_808011DC;
    }
    // 0x808011BC: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x808011C0: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x808011C4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1584, 0X19C8) << 16);
    // 0x808011C8: addiu       $a2, $a2, 0x19C8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1584, 0X19C8));
    // 0x808011CC: jal         0x80089D18
    // 0x808011D0: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_78;
    // 0x808011D0: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_78:
    // 0x808011D4: b           L_808014F0
    // 0x808011D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808014F0;
    // 0x808011D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808011DC:
    // 0x808011DC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1584, 0X1AE0) << 16);
    // 0x808011E0: jal         0x80101E4C
    // 0x808011E4: addiu       $a1, $a1, 0x1AE0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1584, 0X1AE0));
    func_80101E4C(rdram, ctx);
        goto after_79;
    // 0x808011E4: addiu       $a1, $a1, 0x1AE0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1584, 0X1AE0));
    after_79:
    // 0x808011E8: beq         $v0, $zero, L_808014EC
    if (ctx->r2 == 0) {
        // 0x808011EC: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_808014EC;
    }
    // 0x808011EC: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x808011F0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1584, 0X19D4) << 16);
    // 0x808011F4: addiu       $a2, $a2, 0x19D4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1584, 0X19D4));
    // 0x808011F8: jal         0x80089D18
    // 0x808011FC: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_80;
    // 0x808011FC: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_80:
    // 0x80801200: b           L_808014F0
    // 0x80801204: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808014F0;
    // 0x80801204: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801208:
    // 0x80801208: lui         $a1, 0x3F4A
    ctx->r5 = S32(0X3F4A << 16);
    // 0x8080120C: ori         $a1, $a1, 0x3D71
    ctx->r5 = ctx->r5 | 0X3D71;
    // 0x80801210: jal         0x80101E14
    // 0x80801214: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    func_80101E14(rdram, ctx);
        goto after_81;
    // 0x80801214: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    after_81:
    // 0x80801218: beq         $v0, $zero, L_80801230
    if (ctx->r2 == 0) {
        // 0x8080121C: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_80801230;
    }
    // 0x8080121C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80801220: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x80801224: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80801228: b           L_808014EC
    // 0x8080122C: sb          $t9, 0x2($t2)
    MEM_B(0X2, ctx->r10) = ctx->r25;
        goto L_808014EC;
    // 0x8080122C: sb          $t9, 0x2($t2)
    MEM_B(0X2, ctx->r10) = ctx->r25;
L_80801230:
    // 0x80801230: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x80801234: jal         0x80101E14
    // 0x80801238: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    func_80101E14(rdram, ctx);
        goto after_82;
    // 0x80801238: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    after_82:
    // 0x8080123C: beq         $v0, $zero, L_80801254
    if (ctx->r2 == 0) {
        // 0x80801240: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_80801254;
    }
    // 0x80801240: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80801244: jal         0x80800878
    // 0x80801248: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    func_80800878_chnewmumbo(rdram, ctx);
        goto after_83;
    // 0x80801248: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    after_83:
    // 0x8080124C: b           L_808014F0
    // 0x80801250: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808014F0;
    // 0x80801250: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801254:
    // 0x80801254: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1584, 0X1AF0) << 16);
    // 0x80801258: jal         0x80101E4C
    // 0x8080125C: addiu       $a1, $a1, 0x1AF0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1584, 0X1AF0));
    func_80101E4C(rdram, ctx);
        goto after_84;
    // 0x8080125C: addiu       $a1, $a1, 0x1AF0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1584, 0X1AF0));
    after_84:
    // 0x80801260: beq         $v0, $zero, L_808014EC
    if (ctx->r2 == 0) {
        // 0x80801264: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_808014EC;
    }
    // 0x80801264: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80801268: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1584, 0X19E4) << 16);
    // 0x8080126C: addiu       $a2, $a2, 0x19E4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1584, 0X19E4));
    // 0x80801270: jal         0x80089D18
    // 0x80801274: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_85;
    // 0x80801274: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_85:
    // 0x80801278: b           L_808014F0
    // 0x8080127C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808014F0;
    // 0x8080127C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801280:
    // 0x80801280: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80801284: addiu       $a1, $zero, 0x1C2
    ctx->r5 = ADD32(0, 0X1C2);
    // 0x80801288: addiu       $a2, $zero, 0x1F4
    ctx->r6 = ADD32(0, 0X1F4);
    // 0x8080128C: addiu       $a3, $zero, 0x96
    ctx->r7 = ADD32(0, 0X96);
    // 0x80801290: jal         0x8010C9FC
    // 0x80801294: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_8010C9FC(rdram, ctx);
        goto after_86;
    // 0x80801294: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_86:
    // 0x80801298: bne         $v0, $zero, L_808014EC
    if (ctx->r2 != 0) {
        // 0x8080129C: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_808014EC;
    }
    // 0x8080129C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x808012A0: jal         0x80800264
    // 0x808012A4: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_80800264_chnewmumbo(rdram, ctx);
        goto after_87;
    // 0x808012A4: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_87:
    // 0x808012A8: b           L_808014F0
    // 0x808012AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808014F0;
    // 0x808012AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808012B0:
    // 0x808012B0: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1584, 0X1AFC) << 16);
    // 0x808012B4: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1584, 0X1B08) << 16);
    // 0x808012B8: addiu       $a1, $a1, 0x1B08
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1584, 0X1B08));
    // 0x808012BC: addiu       $a0, $a0, 0x1AFC
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1584, 0X1AFC));
    // 0x808012C0: jal         0x800EFED0
    // 0x808012C4: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    func_800EFED0(rdram, ctx);
        goto after_88;
    // 0x808012C4: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    after_88:
    // 0x808012C8: beql        $v0, $zero, L_808014F0
    if (ctx->r2 == 0) {
        // 0x808012CC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808014F0;
    }
    goto skip_12;
    // 0x808012CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_12:
    // 0x808012D0: jal         0x80090248
    // 0x808012D4: nop

    func_80090248(rdram, ctx);
        goto after_89;
    // 0x808012D4: nop

    after_89:
    // 0x808012D8: beql        $v0, $zero, L_808014F0
    if (ctx->r2 == 0) {
        // 0x808012DC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808014F0;
    }
    goto skip_13;
    // 0x808012DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_13:
    // 0x808012E0: jal         0x8010D254
    // 0x808012E4: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    func_8010D254(rdram, ctx);
        goto after_90;
    // 0x808012E4: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_90:
    // 0x808012E8: jal         0x800878A0
    // 0x808012EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _plsu_entrypoint_1(rdram, ctx);
        goto after_91;
    // 0x808012EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_91:
    // 0x808012F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808012F4: jal         0x800F7B9C
    // 0x808012F8: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    func_800F7B9C(rdram, ctx);
        goto after_92;
    // 0x808012F8: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    after_92:
    // 0x808012FC: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80801300: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80801304: sb          $zero, 0x0($t1)
    MEM_B(0X0, ctx->r9) = 0;
    // 0x80801308: jal         0x80800264
    // 0x8080130C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    func_80800264_chnewmumbo(rdram, ctx);
        goto after_93;
    // 0x8080130C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    after_93:
    // 0x80801310: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80801314: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80801318: jal         0x800EE7F8
    // 0x8080131C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_94;
    // 0x8080131C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_94:
    // 0x80801320: jal         0x808007B0
    // 0x80801324: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    func_808007B0_chnewmumbo(rdram, ctx);
        goto after_95;
    // 0x80801324: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    after_95:
    // 0x80801328: b           L_808014F0
    // 0x8080132C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808014F0;
    // 0x8080132C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801330:
    // 0x80801330: jal         0x80090010
    // 0x80801334: nop

    func_80090010(rdram, ctx);
        goto after_96;
    // 0x80801334: nop

    after_96:
    // 0x80801338: jal         0x80013728
    // 0x8080133C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80013728(rdram, ctx);
        goto after_97;
    // 0x8080133C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_97:
    // 0x80801340: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
    // 0x80801344: jal         0x8008FEF0
    // 0x80801348: swc1        $f0, 0x48($t4)
    MEM_W(0X48, ctx->r12) = ctx->f0.u32l;
    func_8008FEF0(rdram, ctx);
        goto after_98;
    // 0x80801348: swc1        $f0, 0x48($t4)
    MEM_W(0X48, ctx->r12) = ctx->f0.u32l;
    after_98:
    // 0x8080134C: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x80801350: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80801354: swc1        $f0, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f0.u32l;
    // 0x80801358: jal         0x80800264
    // 0x8080135C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    func_80800264_chnewmumbo(rdram, ctx);
        goto after_99;
    // 0x8080135C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    after_99:
    // 0x80801360: b           L_808014F0
    // 0x80801364: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808014F0;
    // 0x80801364: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801368:
    // 0x80801368: jal         0x80800898
    // 0x8080136C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    func_80800898_chnewmumbo(rdram, ctx);
        goto after_100;
    // 0x8080136C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    after_100:
    // 0x80801370: lui         $a1, 0x3E57
    ctx->r5 = S32(0X3E57 << 16);
    // 0x80801374: ori         $a1, $a1, 0xA3D
    ctx->r5 = ctx->r5 | 0XA3D;
    // 0x80801378: jal         0x80101E14
    // 0x8080137C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    func_80101E14(rdram, ctx);
        goto after_101;
    // 0x8080137C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    after_101:
    // 0x80801380: beq         $v0, $zero, L_80801390
    if (ctx->r2 == 0) {
        // 0x80801384: lui         $a1, 0x3F54
        ctx->r5 = S32(0X3F54 << 16);
            goto L_80801390;
    }
    // 0x80801384: lui         $a1, 0x3F54
    ctx->r5 = S32(0X3F54 << 16);
    // 0x80801388: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8080138C: sb          $zero, 0x2($t0)
    MEM_B(0X2, ctx->r8) = 0;
L_80801390:
    // 0x80801390: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80801394: jal         0x80101E14
    // 0x80801398: ori         $a1, $a1, 0x7AE1
    ctx->r5 = ctx->r5 | 0X7AE1;
    func_80101E14(rdram, ctx);
        goto after_102;
    // 0x80801398: ori         $a1, $a1, 0x7AE1
    ctx->r5 = ctx->r5 | 0X7AE1;
    after_102:
    // 0x8080139C: beq         $v0, $zero, L_808013AC
    if (ctx->r2 == 0) {
        // 0x808013A0: lw          $t3, 0x5C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X5C);
            goto L_808013AC;
    }
    // 0x808013A0: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x808013A4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808013A8: sb          $t6, 0x1($t3)
    MEM_B(0X1, ctx->r11) = ctx->r14;
L_808013AC:
    // 0x808013AC: jal         0x80101DDC
    // 0x808013B0: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    func_80101DDC(rdram, ctx);
        goto after_103;
    // 0x808013B0: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    after_103:
    // 0x808013B4: beq         $v0, $zero, L_808014EC
    if (ctx->r2 == 0) {
        // 0x808013B8: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_808014EC;
    }
    // 0x808013B8: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x808013BC: jal         0x80800264
    // 0x808013C0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80800264_chnewmumbo(rdram, ctx);
        goto after_104;
    // 0x808013C0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_104:
    // 0x808013C4: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x808013C8: jal         0x80100094
    // 0x808013CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_105;
    // 0x808013CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_105:
    // 0x808013D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808013D4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x808013D8: jal         0x800897E8
    // 0x808013DC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_106;
    // 0x808013DC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_106:
    // 0x808013E0: b           L_808014F0
    // 0x808013E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808014F0;
    // 0x808013E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808013E8:
    // 0x808013E8: jal         0x8010D254
    // 0x808013EC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_8010D254(rdram, ctx);
        goto after_107;
    // 0x808013EC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_107:
    // 0x808013F0: jal         0x80800898
    // 0x808013F4: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    func_80800898_chnewmumbo(rdram, ctx);
        goto after_108;
    // 0x808013F4: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    after_108:
    // 0x808013F8: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x808013FC: jal         0x80800264
    // 0x80801400: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80800264_chnewmumbo(rdram, ctx);
        goto after_109;
    // 0x80801400: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_109:
    // 0x80801404: b           L_808014F0
    // 0x80801408: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808014F0;
    // 0x80801408: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080140C:
    // 0x8080140C: jal         0x8008FD70
    // 0x80801410: nop

    func_8008FD70(rdram, ctx);
        goto after_110;
    // 0x80801410: nop

    after_110:
    // 0x80801414: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801418: beq         $v0, $at, L_80801440
    if (ctx->r2 == ctx->r1) {
        // 0x8080141C: lw          $t8, 0x78($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X78);
            goto L_80801440;
    }
    // 0x8080141C: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x80801420: addiu       $at, $zero, 0x200
    ctx->r1 = ADD32(0, 0X200);
    // 0x80801424: beq         $v0, $at, L_80801490
    if (ctx->r2 == ctx->r1) {
        // 0x80801428: lw          $t7, 0x78($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X78);
            goto L_80801490;
    }
    // 0x80801428: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x8080142C: addiu       $at, $zero, 0x400
    ctx->r1 = ADD32(0, 0X400);
    // 0x80801430: beql        $v0, $at, L_80801494
    if (ctx->r2 == ctx->r1) {
        // 0x80801434: lw          $t0, 0x74($t7)
        ctx->r8 = MEM_W(ctx->r15, 0X74);
            goto L_80801494;
    }
    goto skip_14;
    // 0x80801434: lw          $t0, 0x74($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X74);
    skip_14:
    // 0x80801438: b           L_808014F0
    // 0x8080143C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808014F0;
    // 0x8080143C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801440:
    // 0x80801440: lw          $t5, 0x74($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X74);
    // 0x80801444: sll         $t2, $t5, 1
    ctx->r10 = S32(ctx->r13 << 1);
    // 0x80801448: bltzl       $t2, L_808014F0
    if (SIGNED(ctx->r10) < 0) {
        // 0x8080144C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808014F0;
    }
    goto skip_15;
    // 0x8080144C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_15:
    // 0x80801450: lwc1        $f6, 0x48($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X48);
    // 0x80801454: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x80801458: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8080145C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80801460: addiu       $a0, $t8, 0x4
    ctx->r4 = ADD32(ctx->r24, 0X4);
    // 0x80801464: addiu       $a2, $zero, 0x2EE
    ctx->r6 = ADD32(0, 0X2EE);
    // 0x80801468: addiu       $a3, $zero, 0x5A
    ctx->r7 = ADD32(0, 0X5A);
    // 0x8080146C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80801470: jal         0x8008A1E0
    // 0x80801474: nop

    _subaddiedialog_entrypoint_6(rdram, ctx);
        goto after_111;
    // 0x80801474: nop

    after_111:
    // 0x80801478: beq         $v0, $zero, L_808014EC
    if (ctx->r2 == 0) {
        // 0x8080147C: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_808014EC;
    }
    // 0x8080147C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80801480: jal         0x80800264
    // 0x80801484: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800264_chnewmumbo(rdram, ctx);
        goto after_112;
    // 0x80801484: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_112:
    // 0x80801488: b           L_808014F0
    // 0x8080148C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808014F0;
    // 0x8080148C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801490:
    // 0x80801490: lw          $t0, 0x74($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X74);
L_80801494:
    // 0x80801494: sll         $t3, $t0, 1
    ctx->r11 = S32(ctx->r8 << 1);
    // 0x80801498: bltzl       $t3, L_808014F0
    if (SIGNED(ctx->r11) < 0) {
        // 0x8080149C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808014F0;
    }
    goto skip_16;
    // 0x8080149C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_16:
    // 0x808014A0: lwc1        $f10, 0x48($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X48);
    // 0x808014A4: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x808014A8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808014AC: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x808014B0: addiu       $a0, $t7, 0x4
    ctx->r4 = ADD32(ctx->r15, 0X4);
    // 0x808014B4: addiu       $a2, $zero, 0x2EE
    ctx->r6 = ADD32(0, 0X2EE);
    // 0x808014B8: addiu       $a3, $zero, 0x5A
    ctx->r7 = ADD32(0, 0X5A);
    // 0x808014BC: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x808014C0: jal         0x8008A1E0
    // 0x808014C4: nop

    _subaddiedialog_entrypoint_6(rdram, ctx);
        goto after_113;
    // 0x808014C4: nop

    after_113:
    // 0x808014C8: beq         $v0, $zero, L_808014EC
    if (ctx->r2 == 0) {
        // 0x808014CC: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_808014EC;
    }
    // 0x808014CC: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x808014D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808014D4: jal         0x80800000
    // 0x808014D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800000_chnewmumbo(rdram, ctx);
        goto after_114;
    // 0x808014D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_114:
    // 0x808014DC: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x808014E0: addiu       $a1, $zero, 0x11EB
    ctx->r5 = ADD32(0, 0X11EB);
    // 0x808014E4: jal         0x808000DC
    // 0x808014E8: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_808000DC_chnewmumbo(rdram, ctx);
        goto after_115;
    // 0x808014E8: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_115:
L_808014EC:
    // 0x808014EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808014F0:
    // 0x808014F0: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x808014F4: jr          $ra
    // 0x808014F8: nop

    return;
    // 0x808014F8: nop

;}
RECOMP_FUNC void func_80800BA0_bskaztorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800BA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BA8: lui         $a1, 0x3F71
    ctx->r5 = S32(0X3F71 << 16);
    // 0x80800BAC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800BB0: ori         $a1, $a1, 0x4120
    ctx->r5 = ctx->r5 | 0X4120;
    // 0x80800BB4: jal         0x8008CB10
    // 0x80800BB8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    baanim_isAt(rdram, ctx);
        goto after_0;
    // 0x80800BB8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80800BBC: beq         $v0, $zero, L_80800BC8
    if (ctx->r2 == 0) {
        // 0x80800BC0: lw          $a2, 0x1C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X1C);
            goto L_80800BC8;
    }
    // 0x80800BC0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80800BC4: addiu       $a2, $zero, 0x154
    ctx->r6 = ADD32(0, 0X154);
L_80800BC8:
    // 0x80800BC8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800BCC: jal         0x8009E5C8
    // 0x80800BD0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    bs_setState(rdram, ctx);
        goto after_1;
    // 0x80800BD0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_1:
    // 0x80800BD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800BD8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800BDC: jr          $ra
    // 0x80800BE0: nop

    return;
    // 0x80800BE0: nop

;}
RECOMP_FUNC void func_808001A4_chcaveofhorrorsdoors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001A4: lhu         $v0, 0x76($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X76);
    // 0x808001A8: srl         $t6, $v0, 7
    ctx->r14 = S32(U32(ctx->r2) >> 7);
    // 0x808001AC: jr          $ra
    // 0x808001B0: addiu       $v0, $t6, 0x65
    ctx->r2 = ADD32(ctx->r14, 0X65);
    return;
    // 0x808001B0: addiu       $v0, $t6, 0x65
    ctx->r2 = ADD32(ctx->r14, 0X65);
    // 0x808001B4: nop

    // 0x808001B8: nop

    // 0x808001BC: nop

;}
RECOMP_FUNC void func_80800000_chsecreteggs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8080000C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800010: jal         0x800B53A4
    // 0x80800014: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    func_800B53A4(rdram, ctx);
        goto after_0;
    // 0x80800014: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_0:
    // 0x80800018: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8080001C: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2472, 0X4A8) << 16);
    // 0x80800020: addiu       $t6, $t6, 0x4A8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2472, 0X4A8));
    // 0x80800024: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80800028: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080002C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800030: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800034: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800038: jal         0x800BABB8
    // 0x8080003C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_1;
    // 0x8080003C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80800040: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80800044: addiu       $at, $zero, 0x974
    ctx->r1 = ADD32(0, 0X974);
    // 0x80800048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080004C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80800050: lhu         $v1, 0x14($t8)
    ctx->r3 = MEM_HU(ctx->r24, 0X14);
    // 0x80800054: beq         $v1, $at, L_80800078
    if (ctx->r3 == ctx->r1) {
        // 0x80800058: addiu       $at, $zero, 0x975
        ctx->r1 = ADD32(0, 0X975);
            goto L_80800078;
    }
    // 0x80800058: addiu       $at, $zero, 0x975
    ctx->r1 = ADD32(0, 0X975);
    // 0x8080005C: beq         $v1, $at, L_80800088
    if (ctx->r3 == ctx->r1) {
        // 0x80800060: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800088;
    }
    // 0x80800060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800064: addiu       $at, $zero, 0x976
    ctx->r1 = ADD32(0, 0X976);
    // 0x80800068: beq         $v1, $at, L_80800098
    if (ctx->r3 == ctx->r1) {
        // 0x8080006C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800098;
    }
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800070: b           L_808000A4
    // 0x80800074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808000A4;
    // 0x80800074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800078:
    // 0x80800078: jal         0x800BA3FC
    // 0x8080007C: addiu       $a1, $zero, 0x9DF
    ctx->r5 = ADD32(0, 0X9DF);
    func_800BA3FC(rdram, ctx);
        goto after_2;
    // 0x8080007C: addiu       $a1, $zero, 0x9DF
    ctx->r5 = ADD32(0, 0X9DF);
    after_2:
    // 0x80800080: b           L_808000A4
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808000A4;
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800088:
    // 0x80800088: jal         0x800BA3FC
    // 0x8080008C: addiu       $a1, $zero, 0x9E0
    ctx->r5 = ADD32(0, 0X9E0);
    func_800BA3FC(rdram, ctx);
        goto after_3;
    // 0x8080008C: addiu       $a1, $zero, 0x9E0
    ctx->r5 = ADD32(0, 0X9E0);
    after_3:
    // 0x80800090: b           L_808000A4
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808000A4;
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800098:
    // 0x80800098: jal         0x800BA3FC
    // 0x8080009C: addiu       $a1, $zero, 0x9E2
    ctx->r5 = ADD32(0, 0X9E2);
    func_800BA3FC(rdram, ctx);
        goto after_4;
    // 0x8080009C: addiu       $a1, $zero, 0x9E2
    ctx->r5 = ADD32(0, 0X9E2);
    after_4:
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808000A4:
    // 0x808000A4: jal         0x800BA22C
    // 0x808000A8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_800BA22C(rdram, ctx);
        goto after_5;
    // 0x808000A8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_5:
    // 0x808000AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808000B0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808000B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000B8: jr          $ra
    // 0x808000BC: nop

    return;
    // 0x808000BC: nop

;}
RECOMP_FUNC void func_80801B7C_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B7C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801B80: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80801B84: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80801B88: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80801B8C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801B90: lui         $s2, 0x1
    ctx->r18 = S32(0X1 << 16);
    // 0x80801B94: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80801B98: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80801B9C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80801BA0: ori         $s2, $s2, 0x86A0
    ctx->r18 = ctx->r18 | 0X86A0;
    // 0x80801BA4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801BA8: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x80801BAC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80801BB0:
    // 0x80801BB0: jal         0x80801784
    // 0x80801BB4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80801784_chquiz(rdram, ctx);
        goto after_0;
    // 0x80801BB4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80801BB8: slt         $at, $v0, $s2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80801BBC: beq         $at, $zero, L_80801BD8
    if (ctx->r1 == 0) {
        // 0x80801BC0: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80801BD8;
    }
    // 0x80801BC0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80801BC4: jal         0x8008A800
    // 0x80801BC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suquiz_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80801BC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801BCC: bnel        $v0, $zero, L_80801BDC
    if (ctx->r2 != 0) {
        // 0x80801BD0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80801BDC;
    }
    goto skip_0;
    // 0x80801BD0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80801BD4: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
L_80801BD8:
    // 0x80801BD8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80801BDC:
    // 0x80801BDC: bnel        $s0, $s4, L_80801BB0
    if (ctx->r16 != ctx->r20) {
        // 0x80801BE0: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80801BB0;
    }
    goto skip_1;
    // 0x80801BE0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_1:
    // 0x80801BE4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80801BE8: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x80801BEC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80801BF0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801BF4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80801BF8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80801BFC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80801C00: jr          $ra
    // 0x80801C04: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80801C04: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ncpod_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D08: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800D0C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800D10: jal         0x800895D0
    // 0x80800D14: lh          $a0, 0x0($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X0);
    _ncpoddialog_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800D14: lh          $a0, 0x0($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X0);
    after_0:
    // 0x80800D18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800D1C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D20: jal         0x800895F8
    // 0x80800D24: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _ncpoddialog_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80800D24: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800D28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D30: jr          $ra
    // 0x80800D34: nop

    return;
    // 0x80800D34: nop

;}
RECOMP_FUNC void _suexpression_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800897E0: syscall     795
    recomp_syscall_handler(rdram, ctx, 0x800897E0);
    return;
    // 0x800897E4: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_80800AEC_sucoasterhit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AEC: addiu       $sp, $sp, -0x150
    ctx->r29 = ADD32(ctx->r29, -0X150);
    // 0x80800AF0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800AF4: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x80800AF8: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x80800AFC: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80800B00: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80800B04: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80800B08: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80800B0C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800B10: lbu         $t6, 0x14($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X14);
    // 0x80800B14: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800B18: addiu       $t7, $sp, 0x44
    ctx->r15 = ADD32(ctx->r29, 0X44);
    // 0x80800B1C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800B20: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800B24: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x80800B28: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800B2C: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80800B30: jal         0x80089FA8
    // 0x80800B34: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    _subaddievolume_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800B34: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    after_0:
    // 0x80800B38: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80800B3C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800B40: blez        $v0, L_80800B8C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800B44: sb          $t8, 0x14($s0)
        MEM_B(0X14, ctx->r16) = ctx->r24;
            goto L_80800B8C;
    }
    // 0x80800B44: sb          $t8, 0x14($s0)
    MEM_B(0X14, ctx->r16) = ctx->r24;
    // 0x80800B48: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x80800B4C: jal         0x80103F38
    // 0x80800B50: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80103F38(rdram, ctx);
        goto after_1;
    // 0x80800B50: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80800B54: jal         0x800B5BE4
    // 0x80800B58: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    func_800B5BE4(rdram, ctx);
        goto after_2;
    // 0x80800B58: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    after_2:
    // 0x80800B5C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800B60: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800B64: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(3302, 0XCE8) << 16);
    // 0x80800B68: addiu       $t9, $t9, 0xCE8
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(3302, 0XCE8));
    // 0x80800B6C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800B70: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80800B74: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800B78: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800B7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800B80: jal         0x800BABB8
    // 0x80800B84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_3;
    // 0x80800B84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80800B88: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
L_80800B8C:
    // 0x80800B8C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800B90: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800B94: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80800B98: addiu       $s5, $sp, 0x54
    ctx->r21 = ADD32(ctx->r29, 0X54);
    // 0x80800B9C: blez        $s3, L_80800BD4
    if (SIGNED(ctx->r19) <= 0) {
        // 0x80800BA0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80800BD4;
    }
    // 0x80800BA0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800BA4: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(3302, 0XD14) << 16);
    // 0x80800BA8: addiu       $s2, $s2, 0xD14
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(3302, 0XD14));
    // 0x80800BAC: addiu       $s1, $sp, 0x60
    ctx->r17 = ADD32(ctx->r29, 0X60);
L_80800BB0:
    // 0x80800BB0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800BB4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800BB8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800BBC: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80800BC0: jal         0x800BABB8
    // 0x80800BC4: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    func_800BABB8(rdram, ctx);
        goto after_4;
    // 0x80800BC4: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_4:
    // 0x80800BC8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800BCC: bne         $s0, $s3, L_80800BB0
    if (ctx->r16 != ctx->r19) {
        // 0x80800BD0: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80800BB0;
    }
    // 0x80800BD0: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
L_80800BD4:
    // 0x80800BD4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80800BD8: slti        $v0, $s3, 0x0
    ctx->r2 = SIGNED(ctx->r19) < 0X0 ? 1 : 0;
    // 0x80800BDC: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80800BE0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800BE4: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80800BE8: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80800BEC: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80800BF0: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x80800BF4: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x80800BF8: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
    // 0x80800BFC: jr          $ra
    // 0x80800C00: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    return;
    // 0x80800C00: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
;}
RECOMP_FUNC void bsbansack_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801D98: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801D9C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(41, 0X1EA0) << 16);
    // 0x80801DA0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801DA4: jr          $ra
    // 0x80801DA8: lw          $v0, 0x1EA0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(41, 0X1EA0));
    return;
    // 0x80801DA8: lw          $v0, 0x1EA0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(41, 0X1EA0));
    // 0x80801DAC: nop

;}
RECOMP_FUNC void capod_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    if (tooie_test_room_quiet()) { ctx->r2 = 0; return; }
    // 0x80800130: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800134: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800138: jal         0x8008FFE8
    // 0x8080013C: nop

    func_8008FFE8(rdram, ctx);
        goto after_0;
    // 0x8080013C: nop

    after_0:
    // 0x80800140: beq         $v0, $zero, L_80800158
    if (ctx->r2 == 0) {
        // 0x80800144: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800158;
    }
    // 0x80800144: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800148: jal         0x80089550
    // 0x8080014C: nop

    _ncpod_entrypoint_18(rdram, ctx);
        goto after_1;
    // 0x8080014C: nop

    after_1:
    // 0x80800150: b           L_80800160
    // 0x80800154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800160;
    // 0x80800154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800158:
    // 0x80800158: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8080015C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800160:
    // 0x80800160: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800164: jr          $ra
    // 0x80800168: nop

    return;
    // 0x80800168: nop

;}
RECOMP_FUNC void chtemplelobbydoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2192, 0X3A0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x3A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2192, 0X3A0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x3A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2192, 0X3A0));
;}
RECOMP_FUNC void func_8080248C_chdinoboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080248C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802490: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802494: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80802498: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080249C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808024A0: jal         0x80100094
    // 0x808024A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808024A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808024A8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808024AC: lbu         $t6, 0x12B($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X12B);
    // 0x808024B0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x808024B4: beql        $t6, $zero, L_808024D4
    if (ctx->r14 == 0) {
        // 0x808024B8: lw          $t8, 0x20($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X20);
            goto L_808024D4;
    }
    goto skip_0;
    // 0x808024B8: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x808024BC: jal         0x80085710
    // 0x808024C0: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    _capod_entrypoint_14(rdram, ctx);
        goto after_1;
    // 0x808024C0: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_1:
    // 0x808024C4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x808024C8: ori         $t7, $a3, 0x2000
    ctx->r15 = ctx->r7 | 0X2000;
    // 0x808024CC: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x808024D0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
L_808024D4:
    // 0x808024D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808024D8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x808024DC: jal         0x80085708
    // 0x808024E0: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_2;
    // 0x808024E0: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    after_2:
    // 0x808024E4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x808024E8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x808024EC: sb          $t9, 0x12B($t0)
    MEM_B(0X12B, ctx->r8) = ctx->r25;
    // 0x808024F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808024F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808024F8: jr          $ra
    // 0x808024FC: nop

    return;
    // 0x808024FC: nop

;}
RECOMP_FUNC void subaddiefind_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800314: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800318: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080031C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800320: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800324: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800328: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8080032C: jal         0x8010682C
    // 0x80800330: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_8010682C(rdram, ctx);
        goto after_0;
    // 0x80800330: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800334: beq         $v0, $zero, L_80800378
    if (ctx->r2 == 0) {
        // 0x80800338: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800378;
    }
    // 0x80800338: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8080033C:
    // 0x8080033C: lw          $t6, 0x6C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X6C);
    // 0x80800340: sll         $t7, $t6, 11
    ctx->r15 = S32(ctx->r14 << 11);
    // 0x80800344: srl         $t8, $t7, 20
    ctx->r24 = S32(U32(ctx->r15) >> 20);
    // 0x80800348: bne         $s1, $t8, L_80800368
    if (ctx->r17 != ctx->r24) {
        // 0x8080034C: nop
    
            goto L_80800368;
    }
    // 0x8080034C: nop

    // 0x80800350: lw          $t9, 0x64($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X64);
    // 0x80800354: sll         $t1, $t9, 14
    ctx->r9 = S32(ctx->r25 << 14);
    // 0x80800358: bltz        $t1, L_80800368
    if (SIGNED(ctx->r9) < 0) {
        // 0x8080035C: nop
    
            goto L_80800368;
    }
    // 0x8080035C: nop

    // 0x80800360: b           L_8080037C
    // 0x80800364: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8080037C;
    // 0x80800364: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80800368:
    // 0x80800368: jal         0x8010682C
    // 0x8080036C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010682C(rdram, ctx);
        goto after_1;
    // 0x8080036C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800370: bne         $v0, $zero, L_8080033C
    if (ctx->r2 != 0) {
        // 0x80800374: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8080033C;
    }
    // 0x80800374: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80800378:
    // 0x80800378: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080037C:
    // 0x8080037C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800380: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800384: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800388: jr          $ra
    // 0x8080038C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8080038C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
