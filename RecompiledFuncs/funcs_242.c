#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800C68D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C68D4: jr          $ra
    // 0x800C68D8: sb          $a1, 0x95($a0)
    MEM_B(0X95, ctx->r4) = ctx->r5;
    return;
    // 0x800C68D8: sb          $a1, 0x95($a0)
    MEM_B(0X95, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void func_80800024_chhoopswoop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800028: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080002C: jal         0x800F54E4
    // 0x80800030: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800030: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800034: jal         0x800F53D0
    // 0x80800038: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F53D0(rdram, ctx);
        goto after_1;
    // 0x80800038: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8080003C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800040: jal         0x800946C4
    // 0x80800044: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800946C4(rdram, ctx);
        goto after_2;
    // 0x80800044: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800048: jal         0x800DA524
    // 0x8080004C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA524(rdram, ctx);
        goto after_3;
    // 0x8080004C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80800050: jal         0x800DA524
    // 0x80800054: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800DA524(rdram, ctx);
        goto after_4;
    // 0x80800054: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_4:
    // 0x80800058: jal         0x800DA524
    // 0x8080005C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800DA524(rdram, ctx);
        goto after_5;
    // 0x8080005C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_5:
    // 0x80800060: jal         0x800DA524
    // 0x80800064: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DA524(rdram, ctx);
        goto after_6;
    // 0x80800064: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x80800068: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080006C: lhu         $t6, 0x6E($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X6E);
    // 0x80800070: andi        $t7, $t6, 0xFE00
    ctx->r15 = ctx->r14 & 0XFE00;
    // 0x80800074: jal         0x80800094
    // 0x80800078: sh          $t7, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r15;
    func_80800094_chhoopswoop(rdram, ctx);
        goto after_7;
    // 0x80800078: sh          $t7, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r15;
    after_7:
    // 0x8080007C: jal         0x8008A2F8
    // 0x80800080: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _susubgame_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x80800080: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x80800084: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800088: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080008C: jr          $ra
    // 0x80800090: nop

    return;
    // 0x80800090: nop

;}
RECOMP_FUNC void func_800CA440(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA440: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800CA444: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800CA448: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CA44C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800CA450: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800CA454: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800CA458: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800CA45C: jal         0x800CA5F8
    // 0x800CA460: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800CA5F8(rdram, ctx);
        goto after_0;
    // 0x800CA460: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x800CA464: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800CA468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CA46C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800CA470: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800CA474: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800CA478: jal         0x800CA688
    // 0x800CA47C: nop

    func_800CA688(rdram, ctx);
        goto after_1;
    // 0x800CA47C: nop

    after_1:
    // 0x800CA480: lui         $a2, 0x461C
    ctx->r6 = S32(0X461C << 16);
    // 0x800CA484: ori         $a2, $a2, 0x4000
    ctx->r6 = ctx->r6 | 0X4000;
    // 0x800CA488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CA48C: jal         0x800CA6C0
    // 0x800CA490: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_800CA6C0(rdram, ctx);
        goto after_2;
    // 0x800CA490: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_2:
    // 0x800CA494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CA498: jal         0x800CA6F0
    // 0x800CA49C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_800CA6F0(rdram, ctx);
        goto after_3;
    // 0x800CA49C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_3:
    // 0x800CA4A0: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x800CA4A4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800CA4A8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800CA4AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800CA4B0: swc1        $f0, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->f0.u32l;
    // 0x800CA4B4: mul.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800CA4B8: jal         0x800139F8
    // 0x800CA4BC: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    func_800139F8(rdram, ctx);
        goto after_4;
    // 0x800CA4BC: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    after_4:
    // 0x800CA4C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800CA4C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800CA4C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CA4CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CA4D0: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800CA4D4: swc1        $f8, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->f8.u32l;
    // 0x800CA4D8: lwc1        $f10, 0x5970($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5970);
    // 0x800CA4DC: swc1        $f10, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f10.u32l;
    // 0x800CA4E0: jal         0x800CA218
    // 0x800CA4E4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800CA218(rdram, ctx);
        goto after_5;
    // 0x800CA4E4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x800CA4E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CA4EC: jal         0x800CA2A8
    // 0x800CA4F0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800CA2A8(rdram, ctx);
        goto after_6;
    // 0x800CA4F0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x800CA4F4: jal         0x800CAF34
    // 0x800CA4F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800CAF34(rdram, ctx);
        goto after_7;
    // 0x800CA4F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x800CA4FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CA500: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800CA504: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800CA508: jr          $ra
    // 0x800CA50C: nop

    return;
    // 0x800CA50C: nop

;}
RECOMP_FUNC void chpawnbroker_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1012, 0X1060) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0x1060
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1012, 0X1060));
    return;
    // 0x80800020: addiu       $v0, $v0, 0x1060
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1012, 0X1060));
;}
RECOMP_FUNC void func_80800FA0_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800FA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800FA8: jal         0x800845D0
    // 0x80800FAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _babounce_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800FAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800FB0: jal         0x8080064C
    // 0x80800FB4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bstrexlarge_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800FB4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800FB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800FBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800FC0: jr          $ra
    // 0x80800FC4: nop

    return;
    // 0x80800FC4: nop

;}
RECOMP_FUNC void func_808004CC_chstarspinnerctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808004D0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808004D4: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x808004D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808004DC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808004E0: bne         $a1, $at, L_80800538
    if (ctx->r5 != ctx->r1) {
        // 0x808004E4: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_80800538;
    }
    // 0x808004E4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808004E8: jal         0x8010A570
    // 0x808004EC: nop

    func_8010A570(rdram, ctx);
        goto after_0;
    // 0x808004EC: nop

    after_0:
    // 0x808004F0: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x808004F4: addiu       $a0, $zero, 0x679
    ctx->r4 = ADD32(0, 0X679);
    // 0x808004F8: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x808004FC: jal         0x800DA544
    // 0x80800500: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x80800500: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    after_1:
    // 0x80800504: jal         0x80800554
    // 0x80800508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800554_chstarspinnerctrl(rdram, ctx);
        goto after_2;
    // 0x80800508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080050C: jal         0x800FC660
    // 0x80800510: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC660(rdram, ctx);
        goto after_3;
    // 0x80800510: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_3:
    // 0x80800514: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800518: addiu       $t9, $zero, 0x22
    ctx->r25 = ADD32(0, 0X22);
    // 0x8080051C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800520: addiu       $a1, $zero, 0x10F4
    ctx->r5 = ADD32(0, 0X10F4);
    // 0x80800524: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800528: jal         0x8008A208
    // 0x8080052C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x8080052C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_4:
    // 0x80800530: b           L_80800540
    // 0x80800534: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800540;
    // 0x80800534: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800538:
    // 0x80800538: b           L_80800540
    // 0x8080053C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800540;
    // 0x8080053C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800540:
    // 0x80800540: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800544: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800548: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080054C: jr          $ra
    // 0x80800550: nop

    return;
    // 0x80800550: nop

;}
RECOMP_FUNC void _chquiz_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800877E8: syscall     629
    recomp_syscall_handler(rdram, ctx, 0x800877E8);
    return;
    // 0x800877EC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800978_chfiregen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800978: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080097C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800980: lw          $t6, 0x24($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X24);
    // 0x80800984: addiu       $at, $zero, 0x26D
    ctx->r1 = ADD32(0, 0X26D);
    // 0x80800988: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8080098C: srl         $t7, $t6, 22
    ctx->r15 = S32(U32(ctx->r14) >> 22);
    // 0x80800990: bnel        $t7, $at, L_80800A6C
    if (ctx->r15 != ctx->r1) {
        // 0x80800994: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800A6C;
    }
    goto skip_0;
    // 0x80800994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800998: lwc1        $f0, 0x2C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x8080099C: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808009A0: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x808009A4: nop

    // 0x808009A8: bnel        $v0, $zero, L_808009D0
    if (ctx->r2 != 0) {
        // 0x808009AC: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_808009D0;
    }
    goto skip_1;
    // 0x808009AC: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    skip_1:
    // 0x808009B0: lwc1        $f0, 0x2C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x808009B4: lhu         $t9, 0x6E($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X6E);
    // 0x808009B8: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808009BC: andi        $t0, $t9, 0xFE00
    ctx->r8 = ctx->r25 & 0XFE00;
    // 0x808009C0: sh          $t0, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r8;
    // 0x808009C4: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x808009C8: nop

    // 0x808009CC: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
L_808009D0:
    // 0x808009D0: beql        $at, $zero, L_80800A08
    if (ctx->r1 == 0) {
        // 0x808009D4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800A08;
    }
    goto skip_2;
    // 0x808009D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_2:
    // 0x808009D8: lhu         $t2, 0x76($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0X76);
    // 0x808009DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808009E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808009E4: srl         $t3, $t2, 7
    ctx->r11 = S32(U32(ctx->r10) >> 7);
    // 0x808009E8: addiu       $t4, $t3, -0x32
    ctx->r12 = ADD32(ctx->r11, -0X32);
    // 0x808009EC: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x808009F0: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x808009F4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808009F8: swc1        $f10, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->f10.u32l;
    // 0x808009FC: b           L_80800A68
    // 0x80800A00: swc1        $f18, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->f18.u32l;
        goto L_80800A68;
    // 0x80800A00: swc1        $f18, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->f18.u32l;
    // 0x80800A04: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80800A08:
    // 0x80800A08: bne         $v0, $at, L_80800A68
    if (ctx->r2 != ctx->r1) {
        // 0x80800A0C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80800A68;
    }
    // 0x80800A0C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800A10: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800A14: lw          $t5, 0x6C($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X6C);
    // 0x80800A18: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x80800A1C: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80800A20: andi        $t6, $t5, 0x1FF
    ctx->r14 = ctx->r13 & 0X1FF;
    // 0x80800A24: sltiu       $at, $t6, 0x28
    ctx->r1 = ctx->r14 < 0X28 ? 1 : 0;
    // 0x80800A28: beq         $at, $zero, L_80800A68
    if (ctx->r1 == 0) {
        // 0x80800A2C: swc1        $f6, 0x2C($a2)
        MEM_W(0X2C, ctx->r6) = ctx->f6.u32l;
            goto L_80800A68;
    }
    // 0x80800A2C: swc1        $f6, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->f6.u32l;
    // 0x80800A30: addiu       $a1, $zero, 0x7FBC
    ctx->r5 = ADD32(0, 0X7FBC);
    // 0x80800A34: jal         0x800FC63C
    // 0x80800A38: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800FC63C(rdram, ctx);
        goto after_0;
    // 0x80800A38: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800A3C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800A40: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800A44: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800A48: lhu         $t7, 0x76($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X76);
    // 0x80800A4C: srl         $t8, $t7, 7
    ctx->r24 = S32(U32(ctx->r15) >> 7);
    // 0x80800A50: addiu       $t9, $t8, -0x32
    ctx->r25 = ADD32(ctx->r24, -0X32);
    // 0x80800A54: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80800A58: nop

    // 0x80800A5C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800A60: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800A64: swc1        $f18, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->f18.u32l;
L_80800A68:
    // 0x80800A68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800A6C:
    // 0x80800A6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A70: jr          $ra
    // 0x80800A74: nop

    return;
    // 0x80800A74: nop

;}
RECOMP_FUNC void func_8080011C_subaddierouteDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080011C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800120: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800124: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80800128: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080012C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800130: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80800134: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80800138: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8080013C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80800140: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800144: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800148: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8080014C: jal         0x800CC5F4
    // 0x80800150: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    func_800CC5F4(rdram, ctx);
        goto after_0;
    // 0x80800150: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    after_0:
    // 0x80800154: sll         $fp, $v0, 1
    ctx->r30 = S32(ctx->r2 << 1);
    // 0x80800158: addiu       $fp, $fp, 0x3
    ctx->r30 = ADD32(ctx->r30, 0X3);
    // 0x8080015C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80800160: and         $t6, $fp, $at
    ctx->r14 = ctx->r30 & ctx->r1;
    // 0x80800164: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80800168: or          $fp, $t6, $zero
    ctx->r30 = ctx->r14 | 0;
    // 0x8080016C: blez        $v0, L_80800218
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800170: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_80800218;
    }
    // 0x80800170: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80800174: or          $s7, $s0, $zero
    ctx->r23 = ctx->r16 | 0;
L_80800178:
    // 0x80800178: sh          $fp, 0x0($s7)
    MEM_H(0X0, ctx->r23) = ctx->r30;
    // 0x8080017C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80800180: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800184: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80800188: jal         0x800CC63C
    // 0x8080018C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    func_800CC63C(rdram, ctx);
        goto after_1;
    // 0x8080018C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_1:
    // 0x80800190: blez        $s5, L_808001F8
    if (SIGNED(ctx->r21) <= 0) {
        // 0x80800194: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_808001F8;
    }
    // 0x80800194: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_80800198:
    // 0x80800198: beq         $s4, $s0, L_808001EC
    if (ctx->r20 == ctx->r16) {
        // 0x8080019C: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_808001EC;
    }
    // 0x8080019C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x808001A0: jal         0x800CC63C
    // 0x808001A4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800CC63C(rdram, ctx);
        goto after_2;
    // 0x808001A4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x808001A8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808001AC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808001B0: jal         0x800EFC7C
    // 0x808001B4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800EFC7C(rdram, ctx);
        goto after_3;
    // 0x808001B4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x808001B8: lh          $t7, 0xC($s2)
    ctx->r15 = MEM_H(ctx->r18, 0XC);
    // 0x808001BC: lh          $t8, 0xC($s1)
    ctx->r24 = MEM_H(ctx->r17, 0XC);
    // 0x808001C0: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x808001C4: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808001C8: mflo        $t9
    ctx->r25 = lo;
    // 0x808001CC: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x808001D0: nop

    // 0x808001D4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808001D8: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x808001DC: nop

    // 0x808001E0: bc1fl       L_808001F0
    if (!c1cs) {
        // 0x808001E4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_808001F0;
    }
    goto skip_0;
    // 0x808001E4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x808001E8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_808001EC:
    // 0x808001EC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_808001F0:
    // 0x808001F0: bne         $s0, $s5, L_80800198
    if (ctx->r16 != ctx->r21) {
        // 0x808001F4: nop
    
            goto L_80800198;
    }
    // 0x808001F4: nop

L_808001F8:
    // 0x808001F8: addiu       $t0, $s3, 0x3
    ctx->r8 = ADD32(ctx->r19, 0X3);
    // 0x808001FC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80800200: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80800204: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x80800208: slt         $at, $s4, $s5
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x8080020C: addiu       $s7, $s7, 0x2
    ctx->r23 = ADD32(ctx->r23, 0X2);
    // 0x80800210: bne         $at, $zero, L_80800178
    if (ctx->r1 != 0) {
        // 0x80800214: addu        $fp, $fp, $t1
        ctx->r30 = ADD32(ctx->r30, ctx->r9);
            goto L_80800178;
    }
    // 0x80800214: addu        $fp, $fp, $t1
    ctx->r30 = ADD32(ctx->r30, ctx->r9);
L_80800218:
    // 0x80800218: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8080021C: or          $v0, $fp, $zero
    ctx->r2 = ctx->r30 | 0;
    // 0x80800220: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80800224: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800228: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8080022C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800230: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80800234: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800238: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8080023C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80800240: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80800244: jr          $ra
    // 0x80800248: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80800248: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void chlaundry_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2140, 0X400) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x400
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2140, 0X400));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x400
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2140, 0X400));
;}
RECOMP_FUNC void func_808000E4_chtemplelobbydoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000F0: jal         0x800C6E38
    // 0x808000F4: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    func_800C6E38(rdram, ctx);
        goto after_0;
    // 0x808000F4: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_0:
    // 0x808000F8: beq         $v0, $zero, L_80800114
    if (ctx->r2 == 0) {
        // 0x808000FC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800114;
    }
    // 0x808000FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800100: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2192, 0X3EC) << 16);
    // 0x80800104: addiu       $t6, $zero, 0xF39
    ctx->r14 = ADD32(0, 0XF39);
    // 0x80800108: addiu       $t7, $zero, 0xF39
    ctx->r15 = ADD32(0, 0XF39);
    // 0x8080010C: sh          $t6, 0x3EC($at)
    MEM_H((int16_t)RELOC_LO16(2192, 0X3EC), ctx->r1) = ctx->r14;
    // 0x80800110: sh          $t7, 0x3EE($at)
    MEM_H((int16_t)RELOC_LO16(2192, 0X3EE), ctx->r1) = ctx->r15;
L_80800114:
    // 0x80800114: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2192, 0X3E8) << 16);
    // 0x80800118: addiu       $a2, $a2, 0x3E8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2192, 0X3E8));
    // 0x8080011C: jal         0x8008A1E8
    // 0x80800120: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddiedialog_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x80800120: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x80800124: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800128: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080012C: jr          $ra
    // 0x80800130: nop

    return;
    // 0x80800130: nop

;}
RECOMP_FUNC void bsrest_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800718: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080071C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800720: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800724: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800728: jal         0x8009CC68
    // 0x8080072C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    func_8009CC68(rdram, ctx);
        goto after_0;
    // 0x8080072C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800730: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800734: beq         $v0, $at, L_8080075C
    if (ctx->r2 == ctx->r1) {
        // 0x80800738: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080075C;
    }
    // 0x80800738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080073C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800740: beq         $v0, $at, L_80800784
    if (ctx->r2 == ctx->r1) {
        // 0x80800744: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800784;
    }
    // 0x80800744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800748: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080074C: beq         $v0, $at, L_80800770
    if (ctx->r2 == ctx->r1) {
        // 0x80800750: addiu       $a1, $sp, 0x28
        ctx->r5 = ADD32(ctx->r29, 0X28);
            goto L_80800770;
    }
    // 0x80800750: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80800754: b           L_80800788
    // 0x80800758: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
        goto L_80800788;
    // 0x80800758: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
L_8080075C:
    // 0x8080075C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80800760: jal         0x80084688
    // 0x80800764: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    _badata_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80800764: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_1:
    // 0x80800768: b           L_80800794
    // 0x8080076C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
        goto L_80800794;
    // 0x8080076C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
L_80800770:
    // 0x80800770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800774: jal         0x80084690
    // 0x80800778: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    _badata_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x80800778: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_2:
    // 0x8080077C: b           L_80800794
    // 0x80800780: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
        goto L_80800794;
    // 0x80800780: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
L_80800784:
    // 0x80800784: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
L_80800788:
    // 0x80800788: jal         0x80084698
    // 0x8080078C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    _badata_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x8080078C: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x80800790: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
L_80800794:
    // 0x80800794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800798: beql        $a1, $zero, L_808007AC
    if (ctx->r5 == 0) {
        // 0x8080079C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007AC;
    }
    goto skip_0;
    // 0x8080079C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808007A0: jal         0x8008CB3C
    // 0x808007A4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_4;
    // 0x808007A4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x808007A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808007AC:
    // 0x808007AC: jal         0x808007E8
    // 0x808007B0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    bsrest_entrypoint_17(rdram, ctx);
        goto after_5;
    // 0x808007B0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_5:
    // 0x808007B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808007B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808007BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808007C0: jr          $ra
    // 0x808007C4: nop

    return;
    // 0x808007C4: nop

;}
RECOMP_FUNC void func_80800110_chegggolden(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800110: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800114: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800118: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080011C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800120: jal         0x80100094
    // 0x80800124: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800124: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800128: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8080012C: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x80800130: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800134: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x80800138: beq         $t6, $at, L_80800150
    if (ctx->r14 == ctx->r1) {
        // 0x8080013C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800150;
    }
    // 0x8080013C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800140: beq         $t6, $at, L_808001B0
    if (ctx->r14 == ctx->r1) {
        // 0x80800144: nop
    
            goto L_808001B0;
    }
    // 0x80800144: nop

    // 0x80800148: b           L_80800264
    // 0x8080014C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
        goto L_80800264;
    // 0x8080014C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_80800150:
    // 0x80800150: jal         0x8008A3B8
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800158: bnel        $v0, $zero, L_80800264
    if (ctx->r2 != 0) {
        // 0x8080015C: lw          $t7, 0x2C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X2C);
            goto L_80800264;
    }
    goto skip_0;
    // 0x8080015C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80800160: jal         0x800EEEA8
    // 0x80800164: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800EEEA8(rdram, ctx);
        goto after_2;
    // 0x80800164: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_2:
    // 0x80800168: beq         $v0, $zero, L_80800180
    if (ctx->r2 == 0) {
        // 0x8080016C: lw          $t7, 0x2C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X2C);
            goto L_80800180;
    }
    // 0x8080016C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80800170: lbu         $t9, 0x39($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X39);
    // 0x80800174: ori         $t0, $t9, 0x80
    ctx->r8 = ctx->r25 | 0X80;
    // 0x80800178: b           L_80800260
    // 0x8080017C: sb          $t0, 0x39($t7)
    MEM_B(0X39, ctx->r15) = ctx->r8;
        goto L_80800260;
    // 0x8080017C: sb          $t0, 0x39($t7)
    MEM_B(0X39, ctx->r15) = ctx->r8;
L_80800180:
    // 0x80800180: jal         0x80800000
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_chegggolden(rdram, ctx);
        goto after_3;
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800188: jal         0x8008A3F8
    // 0x8080018C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_16(rdram, ctx);
        goto after_4;
    // 0x8080018C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800190: jal         0x8008A3E8
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_14(rdram, ctx);
        goto after_5;
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800198: beq         $v0, $zero, L_80800260
    if (ctx->r2 == 0) {
        // 0x8080019C: lw          $t1, 0x2C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X2C);
            goto L_80800260;
    }
    // 0x8080019C: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x808001A0: lbu         $t3, 0x39($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X39);
    // 0x808001A4: ori         $t4, $t3, 0x80
    ctx->r12 = ctx->r11 | 0X80;
    // 0x808001A8: b           L_80800260
    // 0x808001AC: sb          $t4, 0x39($t1)
    MEM_B(0X39, ctx->r9) = ctx->r12;
        goto L_80800260;
    // 0x808001AC: sb          $t4, 0x39($t1)
    MEM_B(0X39, ctx->r9) = ctx->r12;
L_808001B0:
    // 0x808001B0: jal         0x8008A3B8
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808001B8: bne         $v0, $zero, L_80800260
    if (ctx->r2 != 0) {
        // 0x808001BC: lw          $t5, 0x2C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X2C);
            goto L_80800260;
    }
    // 0x808001BC: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x808001C0: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x808001C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808001C8: lwc1        $f12, 0x30($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0X30);
    // 0x808001CC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808001D0: lui         $a2, 0x3E09
    ctx->r6 = S32(0X3E09 << 16);
    // 0x808001D4: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x808001D8: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808001DC: ori         $a2, $a2, 0x374C
    ctx->r6 = ctx->r6 | 0X374C;
    // 0x808001E0: jal         0x800F10B4
    // 0x808001E4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_7;
    // 0x808001E4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_7:
    // 0x808001E8: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x808001EC: jal         0x8008A450
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sueggmove_entrypoint_3(rdram, ctx);
        goto after_8;
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808001F4: beq         $v0, $zero, L_80800210
    if (ctx->r2 == 0) {
        // 0x808001F8: lui         $a0, 0x7FEB
        ctx->r4 = S32(0X7FEB << 16);
            goto L_80800210;
    }
    // 0x808001F8: lui         $a0, 0x7FEB
    ctx->r4 = S32(0X7FEB << 16);
    // 0x808001FC: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80800200: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x80800204: ori         $a0, $a0, 0xBC18
    ctx->r4 = ctx->r4 | 0XBC18;
    // 0x80800208: jal         0x800C4140
    // 0x8080020C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C4140(rdram, ctx);
        goto after_9;
    // 0x8080020C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_9:
L_80800210:
    // 0x80800210: jal         0x8008A3E0
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_13(rdram, ctx);
        goto after_10;
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800218: beq         $v0, $zero, L_80800230
    if (ctx->r2 == 0) {
        // 0x8080021C: lw          $t6, 0x2C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X2C);
            goto L_80800230;
    }
    // 0x8080021C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80800220: lbu         $t9, 0x39($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X39);
    // 0x80800224: ori         $t0, $t9, 0x80
    ctx->r8 = ctx->r25 | 0X80;
    // 0x80800228: b           L_80800260
    // 0x8080022C: sb          $t0, 0x39($t6)
    MEM_B(0X39, ctx->r14) = ctx->r8;
        goto L_80800260;
    // 0x8080022C: sb          $t0, 0x39($t6)
    MEM_B(0X39, ctx->r14) = ctx->r8;
L_80800230:
    // 0x80800230: jal         0x8008A3D8
    // 0x80800234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_12(rdram, ctx);
        goto after_11;
    // 0x80800234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800238: beq         $v0, $zero, L_80800250
    if (ctx->r2 == 0) {
        // 0x8080023C: nop
    
            goto L_80800250;
    }
    // 0x8080023C: nop

    // 0x80800240: jal         0x8008A348
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sueggmisc_entrypoint_1(rdram, ctx);
        goto after_12;
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800248: b           L_80800264
    // 0x8080024C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
        goto L_80800264;
    // 0x8080024C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_80800250:
    // 0x80800250: jal         0x80800000
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_chegggolden(rdram, ctx);
        goto after_13;
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800258: jal         0x8008A3F8
    // 0x8080025C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_16(rdram, ctx);
        goto after_14;
    // 0x8080025C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
L_80800260:
    // 0x80800260: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_80800264:
    // 0x80800264: lb          $t3, 0x39($t7)
    ctx->r11 = MEM_B(ctx->r15, 0X39);
    // 0x80800268: bgezl       $t3, L_8080027C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8080026C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080027C;
    }
    goto skip_1;
    // 0x8080026C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80800270: jal         0x8008A390
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_3(rdram, ctx);
        goto after_15;
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800278: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080027C:
    // 0x8080027C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800280: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800284: jr          $ra
    // 0x80800288: nop

    return;
    // 0x80800288: nop

;}
RECOMP_FUNC void _subaddiefade_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089CA8: syscall     808
    recomp_syscall_handler(rdram, ctx, 0x80089CA8);
    return;
    // 0x80089CAC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800F70_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800F74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F78: jal         0x80082FF0
    // 0x80800F7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsdrone_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800F7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800F80: jal         0x808008D8
    // 0x80800F84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808008D8_bssub(rdram, ctx);
        goto after_1;
    // 0x80800F84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800F88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800F8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F90: jr          $ra
    // 0x80800F94: nop

    return;
    // 0x80800F94: nop

;}
RECOMP_FUNC void func_800EEC30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EEC30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EEC34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EEC38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800EEC3C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800EEC40: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800EEC44: jal         0x800EFD24
    // 0x800EEC48: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x800EEC48: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x800EEC4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800EEC50: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800EEC54: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800EEC58: jal         0x800EF214
    // 0x800EEC5C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    func_800EF214(rdram, ctx);
        goto after_1;
    // 0x800EEC5C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x800EEC60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EEC64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EEC68: jr          $ra
    // 0x800EEC6C: nop

    return;
    // 0x800EEC6C: nop

;}
RECOMP_FUNC void func_80800D7C_chwaspnestgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D7C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800D80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D84: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80800D88: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80800D8C: jal         0x80100094
    // 0x80800D90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800D90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800D94: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80800D98: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80800D9C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80800DA0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80800DA4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800DA8: addu        $a1, $v0, $t7
    ctx->r5 = ADD32(ctx->r2, ctx->r15);
    // 0x80800DAC: jal         0x800EE7F8
    // 0x80800DB0: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800DB0: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    after_1:
    // 0x80800DB4: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80800DB8: jal         0x800EE7F8
    // 0x80800DBC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800DBC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x80800DC0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800DC4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80800DC8: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x80800DCC: jal         0x80800AF8
    // 0x80800DD0: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    func_80800AF8_chwaspnestgame(rdram, ctx);
        goto after_3;
    // 0x80800DD0: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    after_3:
    // 0x80800DD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800DD8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800DDC: jr          $ra
    // 0x80800DE0: nop

    return;
    // 0x80800DE0: nop

;}
RECOMP_FUNC void func_800F1E6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F1E6C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800F1E70: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800F1E74: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800F1E78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F1E7C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800F1E80: jal         0x800EFB24
    // 0x800F1E84: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800EFB24(rdram, ctx);
        goto after_0;
    // 0x800F1E84: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x800F1E88: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800F1E8C: jal         0x800F1EA4
    // 0x800F1E90: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800F1EA4(rdram, ctx);
        goto after_1;
    // 0x800F1E90: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x800F1E94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F1E98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800F1E9C: jr          $ra
    // 0x800F1EA0: nop

    return;
    // 0x800F1EA0: nop

;}
RECOMP_FUNC void func_80800000_chmole_witchy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1680, 0XC0) << 16);
    // 0x8080000C: jal         0x800899E8
    // 0x80800010: addiu       $a3, $a3, 0xC0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1680, 0XC0));
    _sumole_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800010: addiu       $a3, $a3, 0xC0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1680, 0XC0));
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
RECOMP_FUNC void func_80801744_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801744: lbu         $v0, 0x79($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X79);
    // 0x80801748: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080174C: srl         $t6, $v0, 4
    ctx->r14 = S32(U32(ctx->r2) >> 4);
    // 0x80801750: beql        $t6, $zero, L_8080177C
    if (ctx->r14 == 0) {
        // 0x80801754: lw          $v0, 0x6C($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X6C);
            goto L_8080177C;
    }
    goto skip_0;
    // 0x80801754: lw          $v0, 0x6C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X6C);
    skip_0:
    // 0x80801758: beq         $t6, $at, L_80801778
    if (ctx->r14 == ctx->r1) {
        // 0x8080175C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80801778;
    }
    // 0x8080175C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801760: beq         $t6, $at, L_80801778
    if (ctx->r14 == ctx->r1) {
        // 0x80801764: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80801778;
    }
    // 0x80801764: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801768: beql        $t6, $at, L_808017C8
    if (ctx->r14 == ctx->r1) {
        // 0x8080176C: lbu         $t6, 0x64($a1)
        ctx->r14 = MEM_BU(ctx->r5, 0X64);
            goto L_808017C8;
    }
    goto skip_1;
    // 0x8080176C: lbu         $t6, 0x64($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X64);
    skip_1:
    // 0x80801770: jr          $ra
    // 0x80801774: nop

    return;
    // 0x80801774: nop

L_80801778:
    // 0x80801778: lw          $v0, 0x6C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X6C);
L_8080177C:
    // 0x8080177C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801780: andi        $t7, $v0, 0x1FF
    ctx->r15 = ctx->r2 & 0X1FF;
    // 0x80801784: beql        $t7, $zero, L_808017A0
    if (ctx->r15 == 0) {
        // 0x80801788: lbu         $t9, 0x64($a1)
        ctx->r25 = MEM_BU(ctx->r5, 0X64);
            goto L_808017A0;
    }
    goto skip_2;
    // 0x80801788: lbu         $t9, 0x64($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X64);
    skip_2:
    // 0x8080178C: beql        $t7, $at, L_808017B8
    if (ctx->r15 == ctx->r1) {
        // 0x80801790: lbu         $t4, 0x64($a1)
        ctx->r12 = MEM_BU(ctx->r5, 0X64);
            goto L_808017B8;
    }
    goto skip_3;
    // 0x80801790: lbu         $t4, 0x64($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X64);
    skip_3:
    // 0x80801794: jr          $ra
    // 0x80801798: nop

    return;
    // 0x80801798: nop

    // 0x8080179C: lbu         $t9, 0x64($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X64);
L_808017A0:
    // 0x808017A0: ori         $t1, $t9, 0x20
    ctx->r9 = ctx->r25 | 0X20;
    // 0x808017A4: sb          $t1, 0x64($a1)
    MEM_B(0X64, ctx->r5) = ctx->r9;
    // 0x808017A8: andi        $t2, $t1, 0xE7
    ctx->r10 = ctx->r9 & 0XE7;
    // 0x808017AC: jr          $ra
    // 0x808017B0: sb          $t2, 0x64($a1)
    MEM_B(0X64, ctx->r5) = ctx->r10;
    return;
    // 0x808017B0: sb          $t2, 0x64($a1)
    MEM_B(0X64, ctx->r5) = ctx->r10;
    // 0x808017B4: lbu         $t4, 0x64($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X64);
L_808017B8:
    // 0x808017B8: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x808017BC: jr          $ra
    // 0x808017C0: sb          $t5, 0x64($a1)
    MEM_B(0X64, ctx->r5) = ctx->r13;
    return;
    // 0x808017C0: sb          $t5, 0x64($a1)
    MEM_B(0X64, ctx->r5) = ctx->r13;
    // 0x808017C4: lbu         $t6, 0x64($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X64);
L_808017C8:
    // 0x808017C8: lw          $t0, 0x6C($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X6C);
    // 0x808017CC: andi        $t3, $t6, 0xFFDF
    ctx->r11 = ctx->r14 & 0XFFDF;
    // 0x808017D0: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x808017D4: andi        $t2, $t1, 0x18
    ctx->r10 = ctx->r9 & 0X18;
    // 0x808017D8: andi        $t4, $t3, 0xE7
    ctx->r12 = ctx->r11 & 0XE7;
    // 0x808017DC: sb          $t3, 0x64($a1)
    MEM_B(0X64, ctx->r5) = ctx->r11;
    // 0x808017E0: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x808017E4: sb          $t5, 0x64($a1)
    MEM_B(0X64, ctx->r5) = ctx->r13;
    // 0x808017E8: jr          $ra
    // 0x808017EC: nop

    return;
    // 0x808017EC: nop

;}
RECOMP_FUNC void func_80027220(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027220: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80027224: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80027228: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8002722C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80027230: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80027234: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80027238: lw          $t6, 0x11F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11F4);
    // 0x8002723C: lh          $t8, 0x1A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X1A);
    // 0x80027240: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80027244: lw          $t7, 0x34($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X34);
    // 0x80027248: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8002724C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80027250: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80027254: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    // 0x80027258: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    // 0x8002725C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80027260: jal         0x80028DF0
    // 0x80027264: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    func_80028DF0(rdram, ctx);
        goto after_0;
    // 0x80027264: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    after_0:
    // 0x80027268: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x8002726C: lw          $t0, 0x11F4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X11F4);
    // 0x80027270: lh          $t2, 0x1A($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X1A);
    // 0x80027274: lw          $t1, 0x34($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X34);
    // 0x80027278: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8002727C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80027280: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80027284: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80027288: b           L_80027298
    // 0x8002728C: lw          $v0, 0x24($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X24);
        goto L_80027298;
    // 0x8002728C: lw          $v0, 0x24($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X24);
    // 0x80027290: b           L_80027298
    // 0x80027294: nop

        goto L_80027298;
    // 0x80027294: nop

L_80027298:
    // 0x80027298: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002729C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800272A0: jr          $ra
    // 0x800272A4: nop

    return;
    // 0x800272A4: nop

    // 0x800272A8: nop

    // 0x800272AC: nop

;}
RECOMP_FUNC void func_80101D7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101D7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80101D80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80101D84: jal         0x80104248
    // 0x80101D88: nop

    func_80104248(rdram, ctx);
        goto after_0;
    // 0x80101D88: nop

    after_0:
    // 0x80101D8C: beq         $v0, $zero, L_80101D9C
    if (ctx->r2 == 0) {
        // 0x80101D90: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80101D9C;
    }
    // 0x80101D90: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80101D94: jal         0x8008B134
    // 0x80101D98: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_1;
    // 0x80101D98: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
L_80101D9C:
    // 0x80101D9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80101DA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80101DA4: jr          $ra
    // 0x80101DA8: nop

    return;
    // 0x80101DA8: nop

;}
RECOMP_FUNC void sucoaster_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801F70: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801F74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801F78: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801F7C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801F80: jal         0x80100094
    // 0x80801F84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801F84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801F88: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80801F8C: jal         0x801072A8
    // 0x80801F90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801072A8(rdram, ctx);
        goto after_1;
    // 0x80801F90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801F94: beql        $v0, $zero, L_80801FB0
    if (ctx->r2 == 0) {
        // 0x80801F98: lw          $t6, 0x24($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X24);
            goto L_80801FB0;
    }
    goto skip_0;
    // 0x80801F98: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80801F9C: jal         0x801072E4
    // 0x80801FA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801072E4(rdram, ctx);
        goto after_2;
    // 0x80801FA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801FA4: beql        $v0, $zero, L_8080201C
    if (ctx->r2 == 0) {
        // 0x80801FA8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080201C;
    }
    goto skip_1;
    // 0x80801FA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80801FAC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
L_80801FB0:
    // 0x80801FB0: lw          $a0, 0x18($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X18);
    // 0x80801FB4: srl         $t7, $a0, 28
    ctx->r15 = S32(U32(ctx->r4) >> 28);
    // 0x80801FB8: jal         0x8008A240
    // 0x80801FBC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    _sucoasterdata_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80801FBC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_3:
    // 0x80801FC0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80801FC4: lh          $t0, 0x54($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X54);
    // 0x80801FC8: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x80801FCC: lh          $t9, 0xC($t8)
    ctx->r25 = MEM_H(ctx->r24, 0XC);
    // 0x80801FD0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801FD4: lh          $t1, 0x56($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X56);
    // 0x80801FD8: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80801FDC: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x80801FE0: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x80801FE4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80801FE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801FEC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801FF0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80801FF4: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80801FF8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80801FFC: mul.s       $f2, $f16, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80802000: nop

    // 0x80802004: mul.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80802008: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8080200C: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x80802010: jal         0x8010D6E0
    // 0x80802014: nop

    func_8010D6E0(rdram, ctx);
        goto after_4;
    // 0x80802014: nop

    after_4:
    // 0x80802018: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080201C:
    // 0x8080201C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802020: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80802024: jr          $ra
    // 0x80802028: nop

    return;
    // 0x80802028: nop

;}
RECOMP_FUNC void func_80000560(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000560: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80000564: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80000568: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000056C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80000570: lw          $a1, 0x0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X0);
    // 0x80000574: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80000578: lui         $a2, 0x8001
    ctx->r6 = S32(0X8001 << 16);
    // 0x8000057C: addiu       $a2, $a2, -0x1800
    ctx->r6 = ADD32(ctx->r6, -0X1800);
    // 0x80000580: jal         0x800006D4
    // 0x80000584: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_800006D4(rdram, ctx);
        goto after_0;
    // 0x80000584: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80000588: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8000058C: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80000590: addiu       $a1, $a1, 0x64F0
    ctx->r5 = ADD32(ctx->r5, 0X64F0);
    // 0x80000594: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80000598: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x8000059C: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x800005A0: addu        $t9, $t7, $v0
    ctx->r25 = ADD32(ctx->r15, ctx->r2);
    // 0x800005A4: andi        $t0, $t9, 0xF
    ctx->r8 = ctx->r25 & 0XF;
    // 0x800005A8: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x800005AC: beq         $t0, $zero, L_800005C4
    if (ctx->r8 == 0) {
        // 0x800005B0: sw          $t9, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r25;
            goto L_800005C4;
    }
    // 0x800005B0: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800005B4: and         $t1, $t9, $at
    ctx->r9 = ctx->r25 & ctx->r1;
    // 0x800005B8: addiu       $t2, $t1, 0x10
    ctx->r10 = ADD32(ctx->r9, 0X10);
    // 0x800005BC: b           L_800005C8
    // 0x800005C0: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
        goto L_800005C8;
    // 0x800005C0: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
L_800005C4:
    // 0x800005C4: sw          $v1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r3;
L_800005C8:
    // 0x800005C8: jal         0x800016BC
    // 0x800005CC: nop

    func_800016BC(rdram, ctx);
        goto after_1;
    // 0x800005CC: nop

    after_1:
    // 0x800005D0: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x800005D4: sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
    // 0x800005D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800005DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800005E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800005E4: jr          $ra
    // 0x800005E8: nop

    return;
    // 0x800005E8: nop

;}
RECOMP_FUNC void _basub_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800851F8: syscall     154
    recomp_syscall_handler(rdram, ctx, 0x800851F8);
    return;
    // 0x800851FC: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void _chlavaentrancebridgeswitch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087080: syscall     504
    recomp_syscall_handler(rdram, ctx, 0x80087080);
    return;
    // 0x80087084: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800016BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800016BC: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800016C0: addiu       $v0, $v0, 0x6F48
    ctx->r2 = ADD32(ctx->r2, 0X6F48);
    // 0x800016C4: jr          $ra
    // 0x800016C8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    return;
    // 0x800016C8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
;}
RECOMP_FUNC void subaddieDll_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808001E0: lw          $t6, 0x24($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X24);
    // 0x808001E4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808001E8: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x808001EC: srl         $t7, $t6, 22
    ctx->r15 = S32(U32(ctx->r14) >> 22);
    // 0x808001F0: beql        $t7, $zero, L_80800204
    if (ctx->r15 == 0) {
        // 0x808001F4: lhu         $a0, 0x1A($a2)
        ctx->r4 = MEM_HU(ctx->r6, 0X1A);
            goto L_80800204;
    }
    goto skip_0;
    // 0x808001F4: lhu         $a0, 0x1A($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X1A);
    skip_0:
    // 0x808001F8: b           L_80800250
    // 0x808001FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800250;
    // 0x808001FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800200: lhu         $a0, 0x1A($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X1A);
L_80800204:
    // 0x80800204: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    // 0x80800208: srl         $t8, $a0, 5
    ctx->r24 = S32(U32(ctx->r4) >> 5);
    // 0x8080020C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80800210: jal         0x800F52B8
    // 0x80800214: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    func_800F52B8(rdram, ctx);
        goto after_0;
    // 0x80800214: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    after_0:
    // 0x80800218: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8080021C: beq         $v0, $at, L_8080022C
    if (ctx->r2 == ctx->r1) {
        // 0x80800220: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8080022C;
    }
    // 0x80800220: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800224: b           L_80800250
    // 0x80800228: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800250;
    // 0x80800228: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080022C:
    // 0x8080022C: jal         0x800F55D0
    // 0x80800230: nop

    func_800F55D0(rdram, ctx);
        goto after_1;
    // 0x80800230: nop

    after_1:
    // 0x80800234: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80800238: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8080023C: beql        $v0, $t1, L_80800250
    if (ctx->r2 == ctx->r9) {
        // 0x80800240: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800250;
    }
    goto skip_1;
    // 0x80800240: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x80800244: b           L_80800250
    // 0x80800248: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800250;
    // 0x80800248: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080024C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800250:
    // 0x80800250: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800254: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800258: jr          $ra
    // 0x8080025C: nop

    return;
    // 0x8080025C: nop

;}
RECOMP_FUNC void func_8080021C_babackpack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080021C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800220: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800224: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x80800228: lbu         $v1, 0x8($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X8);
    // 0x8080022C: beq         $v1, $zero, L_8080024C
    if (ctx->r3 == 0) {
        // 0x80800230: sll         $a0, $v1, 16
        ctx->r4 = S32(ctx->r3 << 16);
            goto L_8080024C;
    }
    // 0x80800230: sll         $a0, $v1, 16
    ctx->r4 = S32(ctx->r3 << 16);
    // 0x80800234: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80800238: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8080023C: jal         0x80100A74
    // 0x80800240: lbu         $a1, 0x9($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X9);
    func_80100A74(rdram, ctx);
        goto after_0;
    // 0x80800240: lbu         $a1, 0x9($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X9);
    after_0:
    // 0x80800244: b           L_80800250
    // 0x80800248: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80800250;
    // 0x80800248: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8080024C:
    // 0x8080024C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80800250:
    // 0x80800250: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800254: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800258: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8080025C: jr          $ra
    // 0x80800260: nop

    return;
    // 0x80800260: nop

;}
RECOMP_FUNC void func_80802550_sucoaster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802550: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802554: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802558: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080255C: jal         0x8080202C
    // 0x80802560: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8080202C_sucoaster(rdram, ctx);
        goto after_0;
    // 0x80802560: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80802564: beq         $v0, $zero, L_80802580
    if (ctx->r2 == 0) {
        // 0x80802568: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80802580;
    }
    // 0x80802568: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080256C: jal         0x80802594
    // 0x80802570: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80802594_sucoaster(rdram, ctx);
        goto after_1;
    // 0x80802570: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80802574: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80802578: b           L_80802584
    // 0x8080257C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
        goto L_80802584;
    // 0x8080257C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_80802580:
    // 0x80802580: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802584:
    // 0x80802584: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802588: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080258C: jr          $ra
    // 0x80802590: nop

    return;
    // 0x80802590: nop

;}
RECOMP_FUNC void func_808042D8_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808042D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808042DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808042E0: jal         0x80100094
    // 0x808042E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808042E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808042E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808042EC: lbu         $v0, 0x8($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X8);
    // 0x808042F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808042F4: jr          $ra
    // 0x808042F8: nop

    return;
    // 0x808042F8: nop

;}
RECOMP_FUNC void func_800D154C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D154C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D1550: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D1554: jal         0x8001210C
    // 0x800D1558: addiu       $a0, $zero, 0x3FF
    ctx->r4 = ADD32(0, 0X3FF);
    func_8001210C(rdram, ctx);
        goto after_0;
    // 0x800D1558: addiu       $a0, $zero, 0x3FF
    ctx->r4 = ADD32(0, 0X3FF);
    after_0:
    // 0x800D155C: addiu       $at, $zero, 0x1FF
    ctx->r1 = ADD32(0, 0X1FF);
    // 0x800D1560: bne         $v0, $at, L_800D15BC
    if (ctx->r2 != ctx->r1) {
        // 0x800D1564: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_800D15BC;
    }
    // 0x800D1564: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800D1568: addiu       $v1, $v1, -0x4DB0
    ctx->r3 = ADD32(ctx->r3, -0X4DB0);
    // 0x800D156C: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x800D1570: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800D1574: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800D1578: addiu       $a1, $t7, 0x1
    ctx->r5 = ADD32(ctx->r15, 0X1);
    // 0x800D157C: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x800D1580: bne         $a1, $at, L_800D1590
    if (ctx->r5 != ctx->r1) {
        // 0x800D1584: sw          $t6, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r14;
            goto L_800D1590;
    }
    // 0x800D1584: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800D1588: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800D158C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800D1590:
    // 0x800D1590: jal         0x8001ACEC
    // 0x800D1594: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    heap_alloc_sided(rdram, ctx);
        goto after_1;
    // 0x800D1594: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_1:
    // 0x800D1598: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800D159C: addiu       $v1, $v1, -0x4DB0
    ctx->r3 = ADD32(ctx->r3, -0X4DB0);
    // 0x800D15A0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800D15A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D15A8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800D15AC: jal         0x8001BBA0
    // 0x800D15B0: addiu       $a2, $zero, 0x2A
    ctx->r6 = ADD32(0, 0X2A);
    rare_memcpy(rdram, ctx);
        goto after_2;
    // 0x800D15B0: addiu       $a2, $zero, 0x2A
    ctx->r6 = ADD32(0, 0X2A);
    after_2:
    // 0x800D15B4: jal         0x8001B084
    // 0x800D15B8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    heap_free(rdram, ctx);
        goto after_3;
    // 0x800D15B8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
L_800D15BC:
    // 0x800D15BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D15C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D15C4: jr          $ra
    // 0x800D15C8: nop

    return;
    // 0x800D15C8: nop

;}
RECOMP_FUNC void _bsride_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800839F8: syscall     85
    recomp_syscall_handler(rdram, ctx, 0x800839F8);
    return;
    // 0x800839FC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80801B7C_chmonsterinterior(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801B7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801B80: beq         $a0, $zero, L_80801BA4
    if (ctx->r4 == 0) {
        // 0x80801B84: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80801BA4;
    }
    // 0x80801B84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801B88: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801B8C: beq         $a0, $at, L_80801BC4
    if (ctx->r4 == ctx->r1) {
        // 0x80801B90: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80801BC4;
    }
    // 0x80801B90: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801B94: beql        $a0, $at, L_80801BE8
    if (ctx->r4 == ctx->r1) {
        // 0x80801B98: lui         $at, 0x4060
        ctx->r1 = S32(0X4060 << 16);
            goto L_80801BE8;
    }
    goto skip_0;
    // 0x80801B98: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    skip_0:
    // 0x80801B9C: b           L_80801C04
    // 0x80801BA0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
        goto L_80801C04;
    // 0x80801BA0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
L_80801BA4:
    // 0x80801BA4: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80801BA8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801BAC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80801BB0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801BB4: jal         0x800DC178
    // 0x80801BB8: nop

    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x80801BB8: nop

    after_0:
    // 0x80801BBC: b           L_80801C10
    // 0x80801BC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801C10;
    // 0x80801BC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801BC4:
    // 0x80801BC4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80801BC8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801BCC: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x80801BD0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801BD4: jal         0x800DC178
    // 0x80801BD8: nop

    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80801BD8: nop

    after_1:
    // 0x80801BDC: b           L_80801C10
    // 0x80801BE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801C10;
    // 0x80801BE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801BE4: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
L_80801BE8:
    // 0x80801BE8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801BEC: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x80801BF0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801BF4: jal         0x800DC178
    // 0x80801BF8: nop

    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80801BF8: nop

    after_2:
    // 0x80801BFC: b           L_80801C10
    // 0x80801C00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801C10;
    // 0x80801C00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801C04:
    // 0x80801C04: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80801C08: nop

    // 0x80801C0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801C10:
    // 0x80801C10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801C14: jr          $ra
    // 0x80801C18: nop

    return;
    // 0x80801C18: nop

;}
RECOMP_FUNC void func_80800000_chterryteeth(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: jal         0x8008A738
    // 0x80800010: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    _sujiggy_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80800010: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x80800014: beq         $v0, $zero, L_80800034
    if (ctx->r2 == 0) {
        // 0x80800018: nop
    
            goto L_80800034;
    }
    // 0x80800018: nop

    // 0x8080001C: jal         0x800DA544
    // 0x80800020: addiu       $a0, $zero, 0x396
    ctx->r4 = ADD32(0, 0X396);
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x80800020: addiu       $a0, $zero, 0x396
    ctx->r4 = ADD32(0, 0X396);
    after_1:
    // 0x80800024: jal         0x800FFAB0
    // 0x80800028: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x80800028: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8080002C: b           L_80800060
    // 0x80800030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800060;
    // 0x80800030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800034:
    // 0x80800034: jal         0x800D3E40
    // 0x80800038: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_800D3E40(rdram, ctx);
        goto after_3;
    // 0x80800038: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_3:
    // 0x8080003C: beql        $v0, $zero, L_80800060
    if (ctx->r2 == 0) {
        // 0x80800040: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800060;
    }
    goto skip_0;
    // 0x80800040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800044: jal         0x80088840
    // 0x80800048: addiu       $a0, $zero, 0x7E
    ctx->r4 = ADD32(0, 0X7E);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_4;
    // 0x80800048: addiu       $a0, $zero, 0x7E
    ctx->r4 = ADD32(0, 0X7E);
    after_4:
    // 0x8080004C: bnel        $v0, $zero, L_80800060
    if (ctx->r2 != 0) {
        // 0x80800050: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800060;
    }
    goto skip_1;
    // 0x80800050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800054: jal         0x800FFAB0
    // 0x80800058: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_5;
    // 0x80800058: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_5:
    // 0x8080005C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800060:
    // 0x80800060: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800064: jr          $ra
    // 0x80800068: nop

    return;
    // 0x80800068: nop

;}
RECOMP_FUNC void func_80092EBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092EBC: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x80092EC0: jr          $ra
    // 0x80092EC4: sb          $a1, 0x14($t6)
    MEM_B(0X14, ctx->r14) = ctx->r5;
    return;
    // 0x80092EC4: sb          $a1, 0x14($t6)
    MEM_B(0X14, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_800C7A68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7A68: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800C7A6C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800C7A70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C7A74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7A78: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x800C7A7C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C7A80: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C7A84: bc1fl       L_800C7A98
    if (!c1cs) {
        // 0x800C7A88: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_800C7A98;
    }
    goto skip_0;
    // 0x800C7A88: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x800C7A8C: b           L_800C7AB0
    // 0x800C7A90: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
        goto L_800C7AB0;
    // 0x800C7A90: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x800C7A94: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_800C7A98:
    // 0x800C7A98: nop

    // 0x800C7A9C: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800C7AA0: nop

    // 0x800C7AA4: bc1fl       L_800C7AB4
    if (!c1cs) {
        // 0x800C7AA8: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_800C7AB4;
    }
    goto skip_1;
    // 0x800C7AA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    skip_1:
    // 0x800C7AAC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_800C7AB0:
    // 0x800C7AB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
L_800C7AB4:
    // 0x800C7AB4: jal         0x800C79EC
    // 0x800C7AB8: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_800C79EC(rdram, ctx);
        goto after_0;
    // 0x800C7AB8: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x800C7ABC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800C7AC0: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800C7AC4: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800C7AC8: lbu         $a1, 0x2($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X2);
    // 0x800C7ACC: jalr        $v0
    // 0x800C7AD0: addiu       $a2, $a0, 0x14
    ctx->r6 = ADD32(ctx->r4, 0X14);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x800C7AD0: addiu       $a2, $a0, 0x14
    ctx->r6 = ADD32(ctx->r4, 0X14);
    after_1:
    // 0x800C7AD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C7AD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C7ADC: jr          $ra
    // 0x800C7AE0: nop

    return;
    // 0x800C7AE0: nop

;}
RECOMP_FUNC void func_80803588_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803588: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080358C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80803590: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80803594: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80803598: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080359C: beq         $a1, $at, L_808036E0
    if (ctx->r5 == ctx->r1) {
        // 0x808035A0: sw          $a0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r4;
            goto L_808036E0;
    }
    // 0x808035A0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x808035A4: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808035A8: beq         $a1, $at, L_808035C0
    if (ctx->r5 == ctx->r1) {
        // 0x808035AC: addiu       $at, $zero, 0x99
        ctx->r1 = ADD32(0, 0X99);
            goto L_808035C0;
    }
    // 0x808035AC: addiu       $at, $zero, 0x99
    ctx->r1 = ADD32(0, 0X99);
    // 0x808035B0: beql        $a1, $at, L_80803628
    if (ctx->r5 == ctx->r1) {
        // 0x808035B4: lhu         $t1, 0x76($a2)
        ctx->r9 = MEM_HU(ctx->r6, 0X76);
            goto L_80803628;
    }
    goto skip_0;
    // 0x808035B4: lhu         $t1, 0x76($a2)
    ctx->r9 = MEM_HU(ctx->r6, 0X76);
    skip_0:
    // 0x808035B8: b           L_80803900
    // 0x808035BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80803900;
    // 0x808035BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808035C0:
    // 0x808035C0: lhu         $a0, 0x76($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X76);
    // 0x808035C4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x808035C8: srl         $t6, $a0, 7
    ctx->r14 = S32(U32(ctx->r4) >> 7);
    // 0x808035CC: jal         0x8080008C
    // 0x808035D0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_8080008C_chquiz(rdram, ctx);
        goto after_0;
    // 0x808035D0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x808035D4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808035D8: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    // 0x808035DC: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x808035E0: jal         0x80103140
    // 0x808035E4: lhu         $a2, 0x16($t7)
    ctx->r6 = MEM_HU(ctx->r15, 0X16);
    func_80103140(rdram, ctx);
        goto after_1;
    // 0x808035E4: lhu         $a2, 0x16($t7)
    ctx->r6 = MEM_HU(ctx->r15, 0X16);
    after_1:
    // 0x808035E8: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x808035EC: lhu         $a0, 0x76($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X76);
    // 0x808035F0: srl         $t9, $a0, 7
    ctx->r25 = S32(U32(ctx->r4) >> 7);
    // 0x808035F4: jal         0x808000A8
    // 0x808035F8: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_808000A8_chquiz(rdram, ctx);
        goto after_2;
    // 0x808035F8: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_2:
    // 0x808035FC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80803600: jal         0x80102FDC
    // 0x80803604: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80102FDC(rdram, ctx);
        goto after_3;
    // 0x80803604: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_3:
    // 0x80803608: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8080360C: lhu         $a1, 0x72($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X72);
    // 0x80803610: srl         $t0, $a1, 10
    ctx->r8 = S32(U32(ctx->r5) >> 10);
    // 0x80803614: jal         0x80102424
    // 0x80803618: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    func_80102424(rdram, ctx);
        goto after_4;
    // 0x80803618: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    after_4:
    // 0x8080361C: b           L_80803900
    // 0x80803620: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803900;
    // 0x80803620: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80803624: lhu         $t1, 0x76($a2)
    ctx->r9 = MEM_HU(ctx->r6, 0X76);
L_80803628:
    // 0x80803628: srl         $t2, $t1, 7
    ctx->r10 = S32(U32(ctx->r9) >> 7);
    // 0x8080362C: sltiu       $at, $t2, 0x7
    ctx->r1 = ctx->r10 < 0X7 ? 1 : 0;
    // 0x80803630: beq         $at, $zero, L_808036D8
    if (ctx->r1 == 0) {
        // 0x80803634: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_808036D8;
    }
    // 0x80803634: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80803638: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X677C) << 16);
    // 0x8080363C: addu        $at, $at, $t2
    gpr jr_addend_80803644 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80803640: lw          $t2, 0x677C($at)
    ctx->r10 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2484, 0X677C));
    // 0x80803644: jr          $t2
    // 0x80803648: nop

    switch (jr_addend_80803644 >> 2) {
        case 0: goto L_80803660; break;
        case 1: goto L_8080364C; break;
        case 2: goto L_80803674; break;
        case 3: goto L_80803688; break;
        case 4: goto L_8080369C; break;
        case 5: goto L_808036B0; break;
        case 6: goto L_808036C4; break;
        default: switch_error(__func__, 0x80803644, 0x8080677C);
    }
    // 0x80803648: nop

L_8080364C:
    // 0x8080364C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2484, 0X737C) << 16);
    // 0x80803650: jal         0x80101074
    // 0x80803654: addiu       $a0, $a0, 0x737C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2484, 0X737C));
    func_80101074(rdram, ctx);
        goto after_5;
    // 0x80803654: addiu       $a0, $a0, 0x737C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2484, 0X737C));
    after_5:
    // 0x80803658: b           L_80803900
    // 0x8080365C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803900;
    // 0x8080365C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803660:
    // 0x80803660: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2484, 0X73A4) << 16);
    // 0x80803664: jal         0x80101074
    // 0x80803668: addiu       $a0, $a0, 0x73A4
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2484, 0X73A4));
    func_80101074(rdram, ctx);
        goto after_6;
    // 0x80803668: addiu       $a0, $a0, 0x73A4
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2484, 0X73A4));
    after_6:
    // 0x8080366C: b           L_80803900
    // 0x80803670: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803900;
    // 0x80803670: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803674:
    // 0x80803674: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2484, 0X73CC) << 16);
    // 0x80803678: jal         0x80101074
    // 0x8080367C: addiu       $a0, $a0, 0x73CC
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2484, 0X73CC));
    func_80101074(rdram, ctx);
        goto after_7;
    // 0x8080367C: addiu       $a0, $a0, 0x73CC
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2484, 0X73CC));
    after_7:
    // 0x80803680: b           L_80803900
    // 0x80803684: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803900;
    // 0x80803684: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803688:
    // 0x80803688: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2484, 0X73CC) << 16);
    // 0x8080368C: jal         0x80101074
    // 0x80803690: addiu       $a0, $a0, 0x73CC
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2484, 0X73CC));
    func_80101074(rdram, ctx);
        goto after_8;
    // 0x80803690: addiu       $a0, $a0, 0x73CC
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2484, 0X73CC));
    after_8:
    // 0x80803694: b           L_80803900
    // 0x80803698: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803900;
    // 0x80803698: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080369C:
    // 0x8080369C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2484, 0X741C) << 16);
    // 0x808036A0: jal         0x80101074
    // 0x808036A4: addiu       $a0, $a0, 0x741C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2484, 0X741C));
    func_80101074(rdram, ctx);
        goto after_9;
    // 0x808036A4: addiu       $a0, $a0, 0x741C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2484, 0X741C));
    after_9:
    // 0x808036A8: b           L_80803900
    // 0x808036AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803900;
    // 0x808036AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808036B0:
    // 0x808036B0: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2484, 0X73CC) << 16);
    // 0x808036B4: jal         0x80101074
    // 0x808036B8: addiu       $a0, $a0, 0x73CC
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2484, 0X73CC));
    func_80101074(rdram, ctx);
        goto after_10;
    // 0x808036B8: addiu       $a0, $a0, 0x73CC
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2484, 0X73CC));
    after_10:
    // 0x808036BC: b           L_80803900
    // 0x808036C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803900;
    // 0x808036C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808036C4:
    // 0x808036C4: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2484, 0X7444) << 16);
    // 0x808036C8: jal         0x80101074
    // 0x808036CC: addiu       $a0, $a0, 0x7444
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2484, 0X7444));
    func_80101074(rdram, ctx);
        goto after_11;
    // 0x808036CC: addiu       $a0, $a0, 0x7444
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2484, 0X7444));
    after_11:
    // 0x808036D0: b           L_80803900
    // 0x808036D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803900;
    // 0x808036D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808036D8:
    // 0x808036D8: b           L_80803900
    // 0x808036DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80803900;
    // 0x808036DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808036E0:
    // 0x808036E0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808036E4: jal         0x801015D0
    // 0x808036E8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    func_801015D0(rdram, ctx);
        goto after_12;
    // 0x808036E8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_12:
    // 0x808036EC: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x808036F0: lhu         $t3, 0x76($a2)
    ctx->r11 = MEM_HU(ctx->r6, 0X76);
    // 0x808036F4: srl         $t4, $t3, 7
    ctx->r12 = S32(U32(ctx->r11) >> 7);
    // 0x808036F8: sltiu       $at, $t4, 0x7
    ctx->r1 = ctx->r12 < 0X7 ? 1 : 0;
    // 0x808036FC: beq         $at, $zero, L_808037A0
    if (ctx->r1 == 0) {
        // 0x80803700: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_808037A0;
    }
    // 0x80803700: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80803704: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X6798) << 16);
    // 0x80803708: addu        $at, $at, $t4
    gpr jr_addend_80803710 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8080370C: lw          $t4, 0x6798($at)
    ctx->r12 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2484, 0X6798));
    // 0x80803710: jr          $t4
    // 0x80803714: nop

    switch (jr_addend_80803710 >> 2) {
        case 0: goto L_8080372C; break;
        case 1: goto L_80803718; break;
        case 2: goto L_80803740; break;
        case 3: goto L_80803754; break;
        case 4: goto L_80803768; break;
        case 5: goto L_8080377C; break;
        case 6: goto L_80803790; break;
        default: switch_error(__func__, 0x80803710, 0x80806798);
    }
    // 0x80803714: nop

L_80803718:
    // 0x80803718: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8080371C: jal         0x800DF744
    // 0x80803720: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DF744(rdram, ctx);
        goto after_13;
    // 0x80803720: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_13:
    // 0x80803724: b           L_808037A0
    // 0x80803728: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
        goto L_808037A0;
    // 0x80803728: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
L_8080372C:
    // 0x8080372C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80803730: jal         0x800DF744
    // 0x80803734: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_14;
    // 0x80803734: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x80803738: b           L_808037A0
    // 0x8080373C: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
        goto L_808037A0;
    // 0x8080373C: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
L_80803740:
    // 0x80803740: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80803744: jal         0x800DF744
    // 0x80803748: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DF744(rdram, ctx);
        goto after_15;
    // 0x80803748: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_15:
    // 0x8080374C: b           L_808037A0
    // 0x80803750: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
        goto L_808037A0;
    // 0x80803750: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
L_80803754:
    // 0x80803754: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80803758: jal         0x800DF744
    // 0x8080375C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_16;
    // 0x8080375C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x80803760: b           L_808037A0
    // 0x80803764: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
        goto L_808037A0;
    // 0x80803764: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
L_80803768:
    // 0x80803768: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8080376C: jal         0x800DF744
    // 0x80803770: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DF744(rdram, ctx);
        goto after_17;
    // 0x80803770: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_17:
    // 0x80803774: b           L_808037A0
    // 0x80803778: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
        goto L_808037A0;
    // 0x80803778: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
L_8080377C:
    // 0x8080377C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80803780: jal         0x800DF744
    // 0x80803784: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DF744(rdram, ctx);
        goto after_18;
    // 0x80803784: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_18:
    // 0x80803788: b           L_808037A0
    // 0x8080378C: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
        goto L_808037A0;
    // 0x8080378C: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
L_80803790:
    // 0x80803790: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80803794: jal         0x800DF744
    // 0x80803798: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800DF744(rdram, ctx);
        goto after_19;
    // 0x80803798: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_19:
    // 0x8080379C: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
L_808037A0:
    // 0x808037A0: lhu         $a1, 0x72($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X72);
    // 0x808037A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808037A8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x808037AC: srl         $t5, $a1, 10
    ctx->r13 = S32(U32(ctx->r5) >> 10);
    // 0x808037B0: beq         $t5, $at, L_808037DC
    if (ctx->r13 == ctx->r1) {
        // 0x808037B4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808037DC;
    }
    // 0x808037B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808037B8: beq         $t5, $at, L_808037EC
    if (ctx->r13 == ctx->r1) {
        // 0x808037BC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808037EC;
    }
    // 0x808037BC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808037C0: beq         $t5, $at, L_8080383C
    if (ctx->r13 == ctx->r1) {
        // 0x808037C4: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_8080383C;
    }
    // 0x808037C4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x808037C8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808037CC: beq         $t5, $at, L_8080384C
    if (ctx->r13 == ctx->r1) {
        // 0x808037D0: nop
    
            goto L_8080384C;
    }
    // 0x808037D0: nop

    // 0x808037D4: b           L_80803900
    // 0x808037D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803900;
    // 0x808037D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808037DC:
    // 0x808037DC: jal         0x800DF744
    // 0x808037E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_20;
    // 0x808037E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
    // 0x808037E4: b           L_80803900
    // 0x808037E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803900;
    // 0x808037E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808037EC:
    // 0x808037EC: jal         0x80101F24
    // 0x808037F0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80101F24(rdram, ctx);
        goto after_21;
    // 0x808037F0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_21:
    // 0x808037F4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x808037F8: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x808037FC: lhu         $a0, 0x76($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X76);
    // 0x80803800: srl         $t7, $a0, 7
    ctx->r15 = S32(U32(ctx->r4) >> 7);
    // 0x80803804: jal         0x808000E0
    // 0x80803808: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_808000E0_chquiz(rdram, ctx);
        goto after_22;
    // 0x80803808: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_22:
    // 0x8080380C: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80803810: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80803814: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80803818: nop

    // 0x8080381C: bc1f        L_8080382C
    if (!c1cs) {
        // 0x80803820: nop
    
            goto L_8080382C;
    }
    // 0x80803820: nop

    // 0x80803824: b           L_8080382C
    // 0x80803828: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
        goto L_8080382C;
    // 0x80803828: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_8080382C:
    // 0x8080382C: jal         0x800DF744
    // 0x80803830: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800DF744(rdram, ctx);
        goto after_23;
    // 0x80803830: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_23:
    // 0x80803834: b           L_80803900
    // 0x80803838: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803900;
    // 0x80803838: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080383C:
    // 0x8080383C: jal         0x800DF744
    // 0x80803840: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DF744(rdram, ctx);
        goto after_24;
    // 0x80803840: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_24:
    // 0x80803844: b           L_80803900
    // 0x80803848: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803900;
    // 0x80803848: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080384C:
    // 0x8080384C: jal         0x80106790
    // 0x80803850: lw          $a0, 0x3C($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X3C);
    func_80106790(rdram, ctx);
        goto after_25;
    // 0x80803850: lw          $a0, 0x3C($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X3C);
    after_25:
    // 0x80803854: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80803858: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080385C: jal         0x800DF744
    // 0x80803860: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_800DF744(rdram, ctx);
        goto after_26;
    // 0x80803860: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_26:
    // 0x80803864: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80803868: beq         $a2, $zero, L_80803880
    if (ctx->r6 == 0) {
        // 0x8080386C: nop
    
            goto L_80803880;
    }
    // 0x8080386C: nop

    // 0x80803870: jal         0x80101F24
    // 0x80803874: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80101F24(rdram, ctx);
        goto after_27;
    // 0x80803874: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_27:
    // 0x80803878: b           L_80803888
    // 0x8080387C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
        goto L_80803888;
    // 0x8080387C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
L_80803880:
    // 0x80803880: b           L_80803900
    // 0x80803884: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803900;
    // 0x80803884: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803888:
    // 0x80803888: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080388C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80803890: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X67B4) << 16);
    // 0x80803894: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x80803898: nop

    // 0x8080389C: bc1f        L_808038F8
    if (!c1cs) {
        // 0x808038A0: nop
    
            goto L_808038F8;
    }
    // 0x808038A0: nop

    // 0x808038A4: lwc1        $f2, 0x67B4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2484, 0X67B4));
    // 0x808038A8: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808038AC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x808038B0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x808038B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X67BC) << 16);
    // 0x808038B8: bc1f        L_808038DC
    if (!c1cs) {
        // 0x808038BC: nop
    
            goto L_808038DC;
    }
    // 0x808038BC: nop

    // 0x808038C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X67B8) << 16);
    // 0x808038C4: lwc1        $f6, 0x67B8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2484, 0X67B8));
    // 0x808038C8: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x808038CC: jal         0x800F10B4
    // 0x808038D0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_28;
    // 0x808038D0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_28:
    // 0x808038D4: b           L_808038E4
    // 0x808038D8: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
        goto L_808038E4;
    // 0x808038D8: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
L_808038DC:
    // 0x808038DC: lwc1        $f8, 0x67BC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2484, 0X67BC));
    // 0x808038E0: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
L_808038E4:
    // 0x808038E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808038E8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808038EC: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808038F0: jal         0x800DF500
    // 0x808038F4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_800DF500(rdram, ctx);
        goto after_29;
    // 0x808038F4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_29:
L_808038F8:
    // 0x808038F8: b           L_80803900
    // 0x808038FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803900;
    // 0x808038FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803900:
    // 0x80803900: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80803904: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80803908: jr          $ra
    // 0x8080390C: nop

    return;
    // 0x8080390C: nop

;}
RECOMP_FUNC void func_808007F8_chhumba(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808007FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800800: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800804: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800808: lw          $a0, 0x6C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C);
    // 0x8080080C: andi        $t6, $a0, 0x1FF
    ctx->r14 = ctx->r4 & 0X1FF;
    // 0x80800810: jal         0x800DA544
    // 0x80800814: addiu       $a0, $t6, 0xD5
    ctx->r4 = ADD32(ctx->r14, 0XD5);
    func_800DA544(rdram, ctx);
        goto after_0;
    // 0x80800814: addiu       $a0, $t6, 0xD5
    ctx->r4 = ADD32(ctx->r14, 0XD5);
    after_0:
    // 0x80800818: lw          $t7, 0x74($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X74);
    // 0x8080081C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80800820: bgez        $t9, L_80800844
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800824: nop
    
            goto L_80800844;
    }
    // 0x80800824: nop

    // 0x80800828: jal         0x808007EC
    // 0x8080082C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808007EC_chhumba(rdram, ctx);
        goto after_1;
    // 0x8080082C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800830: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    // 0x80800834: jal         0x800D175C
    // 0x80800838: negu        $a1, $v0
    ctx->r5 = SUB32(0, ctx->r2);
    func_800D175C(rdram, ctx);
        goto after_2;
    // 0x80800838: negu        $a1, $v0
    ctx->r5 = SUB32(0, ctx->r2);
    after_2:
    // 0x8080083C: b           L_8080085C
    // 0x80800840: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
        goto L_8080085C;
    // 0x80800840: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
L_80800844:
    // 0x80800844: jal         0x808007EC
    // 0x80800848: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808007EC_chhumba(rdram, ctx);
        goto after_3;
    // 0x80800848: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080084C: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    // 0x80800850: jal         0x800D175C
    // 0x80800854: negu        $a1, $v0
    ctx->r5 = SUB32(0, ctx->r2);
    func_800D175C(rdram, ctx);
        goto after_4;
    // 0x80800854: negu        $a1, $v0
    ctx->r5 = SUB32(0, ctx->r2);
    after_4:
    // 0x80800858: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
L_8080085C:
    // 0x8080085C: ori         $t2, $t1, 0x10
    ctx->r10 = ctx->r9 | 0X10;
    // 0x80800860: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
    // 0x80800864: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800868: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080086C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800870: jr          $ra
    // 0x80800874: nop

    return;
    // 0x80800874: nop

;}
RECOMP_FUNC void _chfactorymaindoor_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087570: syscall     588
    recomp_syscall_handler(rdram, ctx, 0x80087570);
    return;
    // 0x80087574: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800D4584(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4584: addiu       $sp, $sp, -0x400
    ctx->r29 = ADD32(ctx->r29, -0X400);
    // 0x800D4588: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x800D458C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800D4590: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x800D4594: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x800D4598: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x800D459C: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x800D45A0: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x800D45A4: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x800D45A8: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x800D45AC: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x800D45B0: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x800D45B4: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x800D45B8: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x800D45BC: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x800D45C0: sw          $a1, 0x404($sp)
    MEM_W(0X404, ctx->r29) = ctx->r5;
    // 0x800D45C4: sw          $a2, 0x408($sp)
    MEM_W(0X408, ctx->r29) = ctx->r6;
    // 0x800D45C8: sw          $a3, 0x40C($sp)
    MEM_W(0X40C, ctx->r29) = ctx->r7;
    // 0x800D45CC: jal         0x800DA298
    // 0x800D45D0: addiu       $a0, $zero, 0x664
    ctx->r4 = ADD32(0, 0X664);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x800D45D0: addiu       $a0, $zero, 0x664
    ctx->r4 = ADD32(0, 0X664);
    after_0:
    // 0x800D45D4: bne         $v0, $zero, L_800D4D20
    if (ctx->r2 != 0) {
        // 0x800D45D8: lw          $a0, 0x404($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X404);
            goto L_800D4D20;
    }
    // 0x800D45D8: lw          $a0, 0x404($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X404);
    // 0x800D45DC: lw          $v0, 0x14($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X14);
    // 0x800D45E0: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x800D45E4: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x800D45E8: lw          $a2, 0x8($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X8);
    // 0x800D45EC: lw          $a3, 0x4($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X4);
    // 0x800D45F0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800D45F4: or          $v1, $v0, $at
    ctx->r3 = ctx->r2 | ctx->r1;
    // 0x800D45F8: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x800D45FC: sw          $v1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r3;
    // 0x800D4600: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800D4604: jal         0x800FAE44
    // 0x800D4608: addiu       $a1, $sp, 0x3E4
    ctx->r5 = ADD32(ctx->r29, 0X3E4);
    func_800FAE44(rdram, ctx);
        goto after_1;
    // 0x800D4608: addiu       $a1, $sp, 0x3E4
    ctx->r5 = ADD32(ctx->r29, 0X3E4);
    after_1:
    // 0x800D460C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D4610: addiu       $t7, $sp, 0x118
    ctx->r15 = ADD32(ctx->r29, 0X118);
    // 0x800D4614: addiu       $t8, $sp, 0x10C
    ctx->r24 = ADD32(ctx->r29, 0X10C);
    // 0x800D4618: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800D461C: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x800D4620: sw          $t8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r24;
    // 0x800D4624: sw          $t7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r15;
    // 0x800D4628: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x800D462C: addiu       $s0, $sp, 0xE4
    ctx->r16 = ADD32(ctx->r29, 0XE4);
    // 0x800D4630: addiu       $s6, $sp, 0xF0
    ctx->r22 = ADD32(ctx->r29, 0XF0);
    // 0x800D4634: addiu       $s4, $sp, 0x100
    ctx->r20 = ADD32(ctx->r29, 0X100);
    // 0x800D4638: addiu       $fp, $sp, 0x8C
    ctx->r30 = ADD32(ctx->r29, 0X8C);
    // 0x800D463C: addiu       $s5, $sp, 0x3D4
    ctx->r21 = ADD32(ctx->r29, 0X3D4);
L_800D4640:
    // 0x800D4640: beq         $s7, $zero, L_800D4650
    if (ctx->r23 == 0) {
        // 0x800D4644: sw          $s0, 0xDC($sp)
        MEM_W(0XDC, ctx->r29) = ctx->r16;
            goto L_800D4650;
    }
    // 0x800D4644: sw          $s0, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r16;
    // 0x800D4648: b           L_800D4654
    // 0x800D464C: addiu       $s2, $s0, -0x90
    ctx->r18 = ADD32(ctx->r16, -0X90);
        goto L_800D4654;
    // 0x800D464C: addiu       $s2, $s0, -0x90
    ctx->r18 = ADD32(ctx->r16, -0X90);
L_800D4650:
    // 0x800D4650: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_800D4654:
    // 0x800D4654: beq         $s7, $zero, L_800D467C
    if (ctx->r23 == 0) {
        // 0x800D4658: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800D467C;
    }
    // 0x800D4658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D465C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D4660: jal         0x800EE7F8
    // 0x800D4664: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x800D4664: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
    // 0x800D4668: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800D466C: jal         0x800EE7F8
    // 0x800D4670: addiu       $a1, $s2, 0xC
    ctx->r5 = ADD32(ctx->r18, 0XC);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x800D4670: addiu       $a1, $s2, 0xC
    ctx->r5 = ADD32(ctx->r18, 0XC);
    after_3:
    // 0x800D4674: b           L_800D4694
    // 0x800D4678: addiu       $a0, $sp, 0x3B8
    ctx->r4 = ADD32(ctx->r29, 0X3B8);
        goto L_800D4694;
    // 0x800D4678: addiu       $a0, $sp, 0x3B8
    ctx->r4 = ADD32(ctx->r29, 0X3B8);
L_800D467C:
    // 0x800D467C: jal         0x800EE7F8
    // 0x800D4680: lw          $a1, 0x408($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X408);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x800D4680: lw          $a1, 0x408($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X408);
    after_4:
    // 0x800D4684: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800D4688: jal         0x800EE7F8
    // 0x800D468C: lw          $a1, 0x404($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X404);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x800D468C: lw          $a1, 0x404($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X404);
    after_5:
    // 0x800D4690: addiu       $a0, $sp, 0x3B8
    ctx->r4 = ADD32(ctx->r29, 0X3B8);
L_800D4694:
    // 0x800D4694: jal         0x800EE7F8
    // 0x800D4698: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x800D4698: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x800D469C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800D46A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800D46A4: jal         0x800EFB24
    // 0x800D46A8: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    func_800EFB24(rdram, ctx);
        goto after_7;
    // 0x800D46A8: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_7:
    // 0x800D46AC: lwc1        $f2, 0x3D4($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3D4);
    // 0x800D46B0: lwc1        $f12, 0x3D8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3D8);
    // 0x800D46B4: lwc1        $f0, 0x3DC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3DC);
    // 0x800D46B8: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800D46BC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800D46C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D46C4: mul.s       $f8, $f12, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800D46C8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800D46CC: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800D46D0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D46D4: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800D46D8: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x800D46DC: nop

    // 0x800D46E0: bc1fl       L_800D4828
    if (!c1cs) {
        // 0x800D46E4: sw          $zero, 0x40($s0)
        MEM_W(0X40, ctx->r16) = 0;
            goto L_800D4828;
    }
    goto skip_0;
    // 0x800D46E4: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
    skip_0:
    // 0x800D46E8: lwc1        $f6, 0x8($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X8);
    // 0x800D46EC: lwc1        $f20, 0x4($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800D46F0: addiu       $s1, $s0, 0x44
    ctx->r17 = ADD32(ctx->r16, 0X44);
    // 0x800D46F4: sub.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f22.fl;
    // 0x800D46F8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x800D46FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800D4700: lw          $a3, 0x84($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X84);
    // 0x800D4704: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800D4708: lwc1        $f16, 0x4($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X4);
    // 0x800D470C: jal         0x800FABF4
    // 0x800D4710: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_800FABF4(rdram, ctx);
        goto after_8;
    // 0x800D4710: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_8:
    // 0x800D4714: beq         $v0, $zero, L_800D4774
    if (ctx->r2 == 0) {
        // 0x800D4718: sw          $v0, 0x40($s0)
        MEM_W(0X40, ctx->r16) = ctx->r2;
            goto L_800D4774;
    }
    // 0x800D4718: sw          $v0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r2;
    // 0x800D471C: jal         0x800EF2A0
    // 0x800D4720: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800EF2A0(rdram, ctx);
        goto after_9;
    // 0x800D4720: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_9:
    // 0x800D4724: lwc1        $f10, 0x3D4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3D4);
    // 0x800D4728: lwc1        $f4, 0x44($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X44);
    // 0x800D472C: lwc1        $f6, 0x3D8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3D8);
    // 0x800D4730: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x800D4734: mul.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800D4738: lwc1        $f4, 0x4C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x800D473C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D4740: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800D4744: lwc1        $f6, 0x3DC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3DC);
    // 0x800D4748: addiu       $a1, $sp, 0x3B8
    ctx->r5 = ADD32(ctx->r29, 0X3B8);
    // 0x800D474C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800D4750: add.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800D4754: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800D4758: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800D475C: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x800D4760: nop

    // 0x800D4764: bc1fl       L_800D4778
    if (!c1cs) {
        // 0x800D4768: lw          $t9, 0x40($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X40);
            goto L_800D4778;
    }
    goto skip_1;
    // 0x800D4768: lw          $t9, 0x40($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X40);
    skip_1:
    // 0x800D476C: jal         0x800EE7F8
    // 0x800D4770: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
    func_800EE7F8(rdram, ctx);
        goto after_10;
    // 0x800D4770: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
    after_10:
L_800D4774:
    // 0x800D4774: lw          $t9, 0x40($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X40);
L_800D4778:
    // 0x800D4778: beql        $t9, $zero, L_800D482C
    if (ctx->r25 == 0) {
        // 0x800D477C: lw          $t0, 0x0($s3)
        ctx->r8 = MEM_W(ctx->r19, 0X0);
            goto L_800D482C;
    }
    goto skip_2;
    // 0x800D477C: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    skip_2:
    // 0x800D4780: lwc1        $f0, 0x48($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X48);
    // 0x800D4784: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800D4788: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D478C: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x800D4790: nop

    // 0x800D4794: bc1fl       L_800D482C
    if (!c1cs) {
        // 0x800D4798: lw          $t0, 0x0($s3)
        ctx->r8 = MEM_W(ctx->r19, 0X0);
            goto L_800D482C;
    }
    goto skip_3;
    // 0x800D4798: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    skip_3:
    // 0x800D479C: lwc1        $f4, 0x5B28($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5B28);
    // 0x800D47A0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800D47A4: nop

    // 0x800D47A8: bc1fl       L_800D482C
    if (!c1cs) {
        // 0x800D47AC: lw          $t0, 0x0($s3)
        ctx->r8 = MEM_W(ctx->r19, 0X0);
            goto L_800D482C;
    }
    goto skip_4;
    // 0x800D47AC: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    skip_4:
    // 0x800D47B0: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x800D47B4: beq         $a0, $zero, L_800D481C
    if (ctx->r4 == 0) {
        // 0x800D47B8: nop
    
            goto L_800D481C;
    }
    // 0x800D47B8: nop

    // 0x800D47BC: jal         0x800C673C
    // 0x800D47C0: nop

    func_800C673C(rdram, ctx);
        goto after_11;
    // 0x800D47C0: nop

    after_11:
    // 0x800D47C4: sub.s       $f6, $f0, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x800D47C8: swc1        $f6, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f6.u32l;
    // 0x800D47CC: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800D47D0: jal         0x800F2100
    // 0x800D47D4: sub.s       $f12, $f20, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f20.fl - ctx->f8.fl;
    mlAbsF(rdram, ctx);
        goto after_12;
    // 0x800D47D4: sub.s       $f12, $f20, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f20.fl - ctx->f8.fl;
    after_12:
    // 0x800D47D8: lwc1        $f10, 0xD8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800D47DC: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x800D47E0: nop

    // 0x800D47E4: bc1f        L_800D481C
    if (!c1cs) {
        // 0x800D47E8: nop
    
            goto L_800D481C;
    }
    // 0x800D47E8: nop

    // 0x800D47EC: lwc1        $f18, 0x8($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X8);
    // 0x800D47F0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800D47F4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800D47F8: sub.s       $f16, $f18, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f22.fl;
    // 0x800D47FC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x800D4800: lw          $a3, 0x84($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X84);
    // 0x800D4804: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x800D4808: lwc1        $f4, 0x4($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X4);
    // 0x800D480C: jal         0x800FABF4
    // 0x800D4810: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_800FABF4(rdram, ctx);
        goto after_13;
    // 0x800D4810: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_13:
    // 0x800D4814: sw          $v0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r2;
    // 0x800D4818: lwc1        $f20, 0x4($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0X4);
L_800D481C:
    // 0x800D481C: b           L_800D4828
    // 0x800D4820: swc1        $f20, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f20.u32l;
        goto L_800D4828;
    // 0x800D4820: swc1        $f20, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f20.u32l;
    // 0x800D4824: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
L_800D4828:
    // 0x800D4828: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
L_800D482C:
    // 0x800D482C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800D4830: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800D4834: beql        $t0, $zero, L_800D4848
    if (ctx->r8 == 0) {
        // 0x800D4838: lbu         $t1, 0x56($s3)
        ctx->r9 = MEM_BU(ctx->r19, 0X56);
            goto L_800D4848;
    }
    goto skip_5;
    // 0x800D4838: lbu         $t1, 0x56($s3)
    ctx->r9 = MEM_BU(ctx->r19, 0X56);
    skip_5:
    // 0x800D483C: jal         0x800D4400
    // 0x800D4840: lw          $a2, 0x40C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40C);
    func_800D4400(rdram, ctx);
        goto after_14;
    // 0x800D4840: lw          $a2, 0x40C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40C);
    after_14:
    // 0x800D4844: lbu         $t1, 0x56($s3)
    ctx->r9 = MEM_BU(ctx->r19, 0X56);
L_800D4848:
    // 0x800D4848: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800D484C: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800D4850: sw          $t1, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->r9;
    // 0x800D4854: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
    // 0x800D4858: lwc1        $f10, 0x4($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X4);
    // 0x800D485C: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800D4860: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800D4864: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800D4868: swc1        $f16, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f16.u32l;
    // 0x800D486C: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
    // 0x800D4870: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800D4874: swc1        $f18, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f18.u32l;
    // 0x800D4878: lwc1        $f8, 0x4($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X4);
    // 0x800D487C: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800D4880: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x800D4884: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D4888: swc1        $f18, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f18.u32l;
    // 0x800D488C: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x800D4890: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
    // 0x800D4894: lw          $t3, 0x84($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X84);
    // 0x800D4898: lw          $a2, 0x8($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X8);
    // 0x800D489C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800D48A0: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x800D48A4: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x800D48A8: jal         0x800C6B78
    // 0x800D48AC: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    func_800C6B78(rdram, ctx);
        goto after_15;
    // 0x800D48AC: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_15:
    // 0x800D48B0: beq         $v0, $zero, L_800D4CB4
    if (ctx->r2 == 0) {
        // 0x800D48B4: sw          $v0, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->r2;
            goto L_800D4CB4;
    }
    // 0x800D48B4: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x800D48B8: addiu       $a0, $s3, 0x20
    ctx->r4 = ADD32(ctx->r19, 0X20);
    // 0x800D48BC: jal         0x800D4564
    // 0x800D48C0: addiu       $s1, $s3, 0x44
    ctx->r17 = ADD32(ctx->r19, 0X44);
    func_800D4564(rdram, ctx);
        goto after_16;
    // 0x800D48C0: addiu       $s1, $s3, 0x44
    ctx->r17 = ADD32(ctx->r19, 0X44);
    after_16:
    // 0x800D48C4: lbu         $t4, 0x55($s3)
    ctx->r12 = MEM_BU(ctx->r19, 0X55);
    // 0x800D48C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D48CC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800D48D0: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800D48D4: sb          $t5, 0x55($s3)
    MEM_B(0X55, ctx->r19) = ctx->r13;
    // 0x800D48D8: lw          $t6, 0x18($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18);
    // 0x800D48DC: jal         0x800EE7F8
    // 0x800D48E0: sw          $t6, 0x1C($s3)
    MEM_W(0X1C, ctx->r19) = ctx->r14;
    func_800EE7F8(rdram, ctx);
        goto after_17;
    // 0x800D48E0: sw          $t6, 0x1C($s3)
    MEM_W(0X1C, ctx->r19) = ctx->r14;
    after_17:
    // 0x800D48E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800D48E8: bne         $s7, $at, L_800D492C
    if (ctx->r23 != ctx->r1) {
        // 0x800D48EC: lw          $t7, 0xFC($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XFC);
            goto L_800D492C;
    }
    // 0x800D48EC: lw          $t7, 0xFC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XFC);
    // 0x800D48F0: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    // 0x800D48F4: bnel        $a1, $t7, L_800D4930
    if (ctx->r5 != ctx->r15) {
        // 0x800D48F8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800D4930;
    }
    goto skip_6;
    // 0x800D48F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_6:
    // 0x800D48FC: lw          $t8, 0x18($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X18);
    // 0x800D4900: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800D4904: addiu       $a2, $s2, 0x1C
    ctx->r6 = ADD32(ctx->r18, 0X1C);
    // 0x800D4908: beql        $t8, $a1, L_800D4930
    if (ctx->r24 == ctx->r5) {
        // 0x800D490C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800D4930;
    }
    goto skip_7;
    // 0x800D490C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_7:
    // 0x800D4910: jal         0x800EE780
    // 0x800D4914: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800EE780(rdram, ctx);
        goto after_18;
    // 0x800D4914: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_18:
    // 0x800D4918: jal         0x800EF2A0
    // 0x800D491C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800EF2A0(rdram, ctx);
        goto after_19;
    // 0x800D491C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_19:
    // 0x800D4920: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800D4924: jal         0x800EE7F8
    // 0x800D4928: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_20;
    // 0x800D4928: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_20:
L_800D492C:
    // 0x800D492C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_800D4930:
    // 0x800D4930: bne         $s7, $at, L_800D4A20
    if (ctx->r23 != ctx->r1) {
        // 0x800D4934: lw          $t9, 0xFC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XFC);
            goto L_800D4A20;
    }
    // 0x800D4934: lw          $t9, 0xFC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XFC);
    // 0x800D4938: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    // 0x800D493C: bnel        $a1, $t9, L_800D4A24
    if (ctx->r5 != ctx->r25) {
        // 0x800D4940: lw          $t6, 0x8C($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X8C);
            goto L_800D4A24;
    }
    goto skip_8;
    // 0x800D4940: lw          $t6, 0x8C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8C);
    skip_8:
    // 0x800D4944: lw          $t0, 0x18($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X18);
    // 0x800D4948: addiu       $s1, $s0, 0x68
    ctx->r17 = ADD32(ctx->r16, 0X68);
    // 0x800D494C: bnel        $t0, $a1, L_800D4A24
    if (ctx->r8 != ctx->r5) {
        // 0x800D4950: lw          $t6, 0x8C($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X8C);
            goto L_800D4A24;
    }
    goto skip_9;
    // 0x800D4950: lw          $t6, 0x8C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8C);
    skip_9:
    // 0x800D4954: jal         0x800D4534
    // 0x800D4958: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D4534(rdram, ctx);
        goto after_21;
    // 0x800D4958: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_21:
    // 0x800D495C: beq         $v0, $zero, L_800D4A20
    if (ctx->r2 == 0) {
        // 0x800D4960: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_800D4A20;
    }
    // 0x800D4960: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800D4964: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D4968: jal         0x800F0524
    // 0x800D496C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800F0524(rdram, ctx);
        goto after_22;
    // 0x800D496C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_22:
    // 0x800D4970: addiu       $a0, $sp, 0x3F4
    ctx->r4 = ADD32(ctx->r29, 0X3F4);
    // 0x800D4974: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800D4978: jal         0x800EFB24
    // 0x800D497C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_800EFB24(rdram, ctx);
        goto after_23;
    // 0x800D497C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_23:
    // 0x800D4980: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D4984: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D4988: lwc1        $f16, 0x8($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X8);
    // 0x800D498C: addiu       $a0, $sp, 0x3F4
    ctx->r4 = ADD32(ctx->r29, 0X3F4);
    // 0x800D4990: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800D4994: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800D4998: jal         0x800EF368
    // 0x800D499C: nop

    func_800EF368(rdram, ctx);
        goto after_24;
    // 0x800D499C: nop

    after_24:
    // 0x800D49A0: lwc1        $f8, 0x3D4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3D4);
    // 0x800D49A4: lwc1        $f10, 0x3F4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3F4);
    // 0x800D49A8: lwc1        $f16, 0x3D8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3D8);
    // 0x800D49AC: lwc1        $f4, 0x3F8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3F8);
    // 0x800D49B0: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800D49B4: lwc1        $f10, 0x3FC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3FC);
    // 0x800D49B8: lwc1        $f8, 0x3DC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3DC);
    // 0x800D49BC: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800D49C0: swc1        $f18, 0x3D4($sp)
    MEM_W(0X3D4, ctx->r29) = ctx->f18.u32l;
    // 0x800D49C4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800D49C8: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800D49CC: swc1        $f6, 0x3D8($sp)
    MEM_W(0X3D8, ctx->r29) = ctx->f6.u32l;
    // 0x800D49D0: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x800D49D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D49D8: swc1        $f18, 0x3DC($sp)
    MEM_W(0X3DC, ctx->r29) = ctx->f18.u32l;
    // 0x800D49DC: lw          $t1, 0x18($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X18);
    // 0x800D49E0: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x800D49E4: sll         $t3, $t2, 15
    ctx->r11 = S32(ctx->r10 << 15);
    // 0x800D49E8: bltz        $t3, L_800D4A18
    if (SIGNED(ctx->r11) < 0) {
        // 0x800D49EC: nop
    
            goto L_800D4A18;
    }
    // 0x800D49EC: nop

    // 0x800D49F0: lw          $t5, 0x84($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X84);
    // 0x800D49F4: lw          $a2, 0x4($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X4);
    // 0x800D49F8: lw          $a3, 0x8($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X8);
    // 0x800D49FC: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800D4A00: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x800D4A04: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800D4A08: jal         0x800FB434
    // 0x800D4A0C: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    func_800FB434(rdram, ctx);
        goto after_25;
    // 0x800D4A0C: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    after_25:
    // 0x800D4A10: b           L_800D4A20
    // 0x800D4A14: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
        goto L_800D4A20;
    // 0x800D4A14: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
L_800D4A18:
    // 0x800D4A18: jal         0x800EE7F8
    // 0x800D4A1C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_26;
    // 0x800D4A1C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_26:
L_800D4A20:
    // 0x800D4A20: lw          $t6, 0x8C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8C);
L_800D4A24:
    // 0x800D4A24: bne         $t6, $zero, L_800D4B04
    if (ctx->r14 != 0) {
        // 0x800D4A28: nop
    
            goto L_800D4B04;
    }
    // 0x800D4A28: nop

    // 0x800D4A2C: lw          $t7, 0x18($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X18);
    // 0x800D4A30: lw          $t8, 0x40C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40C);
    // 0x800D4A34: beq         $t7, $zero, L_800D4B04
    if (ctx->r15 == 0) {
        // 0x800D4A38: nop
    
            goto L_800D4B04;
    }
    // 0x800D4A38: nop

    // 0x800D4A3C: lwc1        $f16, 0x4($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X4);
    // 0x800D4A40: c.lt.s      $f16, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f16.fl < ctx->f24.fl;
    // 0x800D4A44: nop

    // 0x800D4A48: bc1f        L_800D4B04
    if (!c1cs) {
        // 0x800D4A4C: nop
    
            goto L_800D4B04;
    }
    // 0x800D4A4C: nop

    // 0x800D4A50: jal         0x800F2100
    // 0x800D4A54: lwc1        $f12, 0x20($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X20);
    mlAbsF(rdram, ctx);
        goto after_27;
    // 0x800D4A54: lwc1        $f12, 0x20($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X20);
    after_27:
    // 0x800D4A58: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D4A5C: lwc1        $f4, 0x5B2C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5B2C);
    // 0x800D4A60: addiu       $s1, $s0, 0x68
    ctx->r17 = ADD32(ctx->r16, 0X68);
    // 0x800D4A64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D4A68: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800D4A6C: nop

    // 0x800D4A70: bc1f        L_800D4B04
    if (!c1cs) {
        // 0x800D4A74: nop
    
            goto L_800D4B04;
    }
    // 0x800D4A74: nop

    // 0x800D4A78: jal         0x800D4534
    // 0x800D4A7C: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    func_800D4534(rdram, ctx);
        goto after_28;
    // 0x800D4A7C: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    after_28:
    // 0x800D4A80: beq         $v0, $zero, L_800D4B04
    if (ctx->r2 == 0) {
        // 0x800D4A84: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_800D4B04;
    }
    // 0x800D4A84: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800D4A88: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D4A8C: jal         0x800F0524
    // 0x800D4A90: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800F0524(rdram, ctx);
        goto after_29;
    // 0x800D4A90: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_29:
    // 0x800D4A94: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800D4A98: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800D4A9C: lwc1        $f6, 0x8($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X8);
    // 0x800D4AA0: addiu       $a0, $sp, 0x3F4
    ctx->r4 = ADD32(ctx->r29, 0X3F4);
    // 0x800D4AA4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800D4AA8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D4AAC: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800D4AB0: jal         0x800EFA20
    // 0x800D4AB4: nop

    func_800EFA20(rdram, ctx);
        goto after_30;
    // 0x800D4AB4: nop

    after_30:
    // 0x800D4AB8: addiu       $a0, $sp, 0x3C8
    ctx->r4 = ADD32(ctx->r29, 0X3C8);
    // 0x800D4ABC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800D4AC0: jal         0x800EE780
    // 0x800D4AC4: addiu       $a2, $sp, 0x3F4
    ctx->r6 = ADD32(ctx->r29, 0X3F4);
    func_800EE780(rdram, ctx);
        goto after_31;
    // 0x800D4AC4: addiu       $a2, $sp, 0x3F4
    ctx->r6 = ADD32(ctx->r29, 0X3F4);
    after_31:
    // 0x800D4AC8: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
    // 0x800D4ACC: lw          $a2, 0x4($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X4);
    // 0x800D4AD0: lw          $a3, 0x8($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X8);
    // 0x800D4AD4: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x800D4AD8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800D4ADC: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x800D4AE0: addiu       $a0, $sp, 0x3C8
    ctx->r4 = ADD32(ctx->r29, 0X3C8);
    // 0x800D4AE4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800D4AE8: jal         0x800FB434
    // 0x800D4AEC: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    func_800FB434(rdram, ctx);
        goto after_32;
    // 0x800D4AEC: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_32:
    // 0x800D4AF0: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x800D4AF4: lwc1        $f18, 0x3D4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3D4);
    // 0x800D4AF8: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    // 0x800D4AFC: lwc1        $f16, 0x3DC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3DC);
    // 0x800D4B00: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
L_800D4B04:
    // 0x800D4B04: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D4B08: lwc1        $f4, 0x5B30($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5B30);
    // 0x800D4B0C: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800D4B10: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800D4B14: nop

    // 0x800D4B18: bc1fl       L_800D4C60
    if (!c1cs) {
        // 0x800D4B1C: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_800D4C60;
    }
    goto skip_10;
    // 0x800D4B1C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_10:
    // 0x800D4B20: lwc1        $f8, 0x4($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X4);
    // 0x800D4B24: lwc1        $f10, 0x8($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X8);
    // 0x800D4B28: addiu       $s1, $s0, 0x68
    ctx->r17 = ADD32(ctx->r16, 0X68);
    // 0x800D4B2C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D4B30: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x800D4B34: nop

    // 0x800D4B38: bc1tl       L_800D4C60
    if (c1cs) {
        // 0x800D4B3C: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_800D4C60;
    }
    goto skip_11;
    // 0x800D4B3C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_11:
    // 0x800D4B40: jal         0x800D4534
    // 0x800D4B44: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    func_800D4534(rdram, ctx);
        goto after_33;
    // 0x800D4B44: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    after_33:
    // 0x800D4B48: beq         $v0, $zero, L_800D4C5C
    if (ctx->r2 == 0) {
        // 0x800D4B4C: addiu       $s2, $zero, 0x1
        ctx->r18 = ADD32(0, 0X1);
            goto L_800D4C5C;
    }
    // 0x800D4B4C: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800D4B50: addiu       $a0, $sp, 0xC8
    ctx->r4 = ADD32(ctx->r29, 0XC8);
    // 0x800D4B54: jal         0x800EE7F8
    // 0x800D4B58: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_34;
    // 0x800D4B58: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_34:
    // 0x800D4B5C: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x800D4B60: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x800D4B64: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x800D4B68: jal         0x800EFA4C
    // 0x800D4B6C: addiu       $a0, $sp, 0xBC
    ctx->r4 = ADD32(ctx->r29, 0XBC);
    func_800EFA4C(rdram, ctx);
        goto after_35;
    // 0x800D4B6C: addiu       $a0, $sp, 0xBC
    ctx->r4 = ADD32(ctx->r29, 0XBC);
    after_35:
    // 0x800D4B70: addiu       $a0, $sp, 0xC8
    ctx->r4 = ADD32(ctx->r29, 0XC8);
    // 0x800D4B74: addiu       $a1, $sp, 0xBC
    ctx->r5 = ADD32(ctx->r29, 0XBC);
    // 0x800D4B78: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x800D4B7C: jal         0x800F0CB4
    // 0x800D4B80: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    func_800F0CB4(rdram, ctx);
        goto after_36;
    // 0x800D4B80: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_36:
    // 0x800D4B84: beq         $v0, $zero, L_800D4BB4
    if (ctx->r2 == 0) {
        // 0x800D4B88: lwc1        $f16, 0xCC($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0XCC);
            goto L_800D4BB4;
    }
    // 0x800D4B88: lwc1        $f16, 0xCC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800D4B8C: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800D4B90: jal         0x800F2100
    // 0x800D4B94: sub.s       $f12, $f18, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f16.fl;
    mlAbsF(rdram, ctx);
        goto after_37;
    // 0x800D4B94: sub.s       $f12, $f18, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f16.fl;
    after_37:
    // 0x800D4B98: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D4B9C: lwc1        $f4, 0x5B34($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5B34);
    // 0x800D4BA0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800D4BA4: nop

    // 0x800D4BA8: bc1f        L_800D4BB4
    if (!c1cs) {
        // 0x800D4BAC: nop
    
            goto L_800D4BB4;
    }
    // 0x800D4BAC: nop

    // 0x800D4BB0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_800D4BB4:
    // 0x800D4BB4: beq         $s2, $zero, L_800D4C5C
    if (ctx->r18 == 0) {
        // 0x800D4BB8: addiu       $a0, $sp, 0xA4
        ctx->r4 = ADD32(ctx->r29, 0XA4);
            goto L_800D4C5C;
    }
    // 0x800D4BB8: addiu       $a0, $sp, 0xA4
    ctx->r4 = ADD32(ctx->r29, 0XA4);
    // 0x800D4BBC: jal         0x800EE7F8
    // 0x800D4BC0: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_38;
    // 0x800D4BC0: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_38:
    // 0x800D4BC4: addiu       $a0, $sp, 0x98
    ctx->r4 = ADD32(ctx->r29, 0X98);
    // 0x800D4BC8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D4BCC: jal         0x800F0410
    // 0x800D4BD0: lw          $a2, 0x70($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X70);
    func_800F0410(rdram, ctx);
        goto after_39;
    // 0x800D4BD0: lw          $a2, 0x70($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X70);
    after_39:
    // 0x800D4BD4: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800D4BD8: addiu       $a1, $sp, 0xA4
    ctx->r5 = ADD32(ctx->r29, 0XA4);
    // 0x800D4BDC: jal         0x800EFB24
    // 0x800D4BE0: addiu       $a2, $sp, 0x98
    ctx->r6 = ADD32(ctx->r29, 0X98);
    func_800EFB24(rdram, ctx);
        goto after_40;
    // 0x800D4BE0: addiu       $a2, $sp, 0x98
    ctx->r6 = ADD32(ctx->r29, 0X98);
    after_40:
    // 0x800D4BE4: swc1        $f24, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f24.u32l;
    // 0x800D4BE8: jal         0x800EF2A0
    // 0x800D4BEC: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    func_800EF2A0(rdram, ctx);
        goto after_41;
    // 0x800D4BEC: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_41:
    // 0x800D4BF0: jal         0x800EEF24
    // 0x800D4BF4: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    func_800EEF24(rdram, ctx);
        goto after_42;
    // 0x800D4BF4: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_42:
    // 0x800D4BF8: beq         $v0, $zero, L_800D4C5C
    if (ctx->r2 == 0) {
        // 0x800D4BFC: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_800D4C5C;
    }
    // 0x800D4BFC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800D4C00: jal         0x800EE7F8
    // 0x800D4C04: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_43;
    // 0x800D4C04: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    after_43:
    // 0x800D4C08: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800D4C0C: jal         0x800EE7F8
    // 0x800D4C10: lw          $a1, 0x404($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X404);
    func_800EE7F8(rdram, ctx);
        goto after_44;
    // 0x800D4C10: lw          $a1, 0x404($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X404);
    after_44:
    // 0x800D4C14: addiu       $t1, $s7, 0x1
    ctx->r9 = ADD32(ctx->r23, 0X1);
    // 0x800D4C18: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x800D4C1C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800D4C20: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800D4C24: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800D4C28: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x800D4C2C: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800D4C30: nop

    // 0x800D4C34: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800D4C38: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800D4C3C: jal         0x800EF368
    // 0x800D4C40: nop

    func_800EF368(rdram, ctx);
        goto after_45;
    // 0x800D4C40: nop

    after_45:
    // 0x800D4C44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D4C48: jal         0x800EF04C
    // 0x800D4C4C: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    func_800EF04C(rdram, ctx);
        goto after_46;
    // 0x800D4C4C: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    after_46:
    // 0x800D4C50: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x800D4C54: jal         0x800EF04C
    // 0x800D4C58: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    func_800EF04C(rdram, ctx);
        goto after_47;
    // 0x800D4C58: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    after_47:
L_800D4C5C:
    // 0x800D4C5C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_800D4C60:
    // 0x800D4C60: jal         0x800EEF24
    // 0x800D4C64: addiu       $s1, $s7, 0x1
    ctx->r17 = ADD32(ctx->r23, 0X1);
    func_800EEF24(rdram, ctx);
        goto after_48;
    // 0x800D4C64: addiu       $s1, $s7, 0x1
    ctx->r17 = ADD32(ctx->r23, 0X1);
    after_48:
    // 0x800D4C68: beq         $v0, $zero, L_800D4C84
    if (ctx->r2 == 0) {
        // 0x800D4C6C: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_800D4C84;
    }
    // 0x800D4C6C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800D4C70: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800D4C74: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    // 0x800D4C78: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800D4C7C: jal         0x800FAF78
    // 0x800D4C80: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    func_800FAF78(rdram, ctx);
        goto after_49;
    // 0x800D4C80: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_49:
L_800D4C84:
    // 0x800D4C84: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x800D4C88: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x800D4C8C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800D4C90: addiu       $t3, $t2, 0x90
    ctx->r11 = ADD32(ctx->r10, 0X90);
    // 0x800D4C94: addiu       $t5, $t4, 0x90
    ctx->r13 = ADD32(ctx->r12, 0X90);
    // 0x800D4C98: sw          $t5, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r13;
    // 0x800D4C9C: sw          $t3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r11;
    // 0x800D4CA0: or          $s7, $s1, $zero
    ctx->r23 = ctx->r17 | 0;
    // 0x800D4CA4: addiu       $s0, $s0, 0x90
    ctx->r16 = ADD32(ctx->r16, 0X90);
    // 0x800D4CA8: addiu       $s6, $s6, 0x90
    ctx->r22 = ADD32(ctx->r22, 0X90);
    // 0x800D4CAC: bne         $s1, $at, L_800D4640
    if (ctx->r17 != ctx->r1) {
        // 0x800D4CB0: addiu       $s4, $s4, 0x90
        ctx->r20 = ADD32(ctx->r20, 0X90);
            goto L_800D4640;
    }
    // 0x800D4CB0: addiu       $s4, $s4, 0x90
    ctx->r20 = ADD32(ctx->r20, 0X90);
L_800D4CB4:
    // 0x800D4CB4: addiu       $t6, $sp, 0x3D0
    ctx->r14 = ADD32(ctx->r29, 0X3D0);
    // 0x800D4CB8: bne         $s4, $t6, L_800D4D00
    if (ctx->r20 != ctx->r14) {
        // 0x800D4CBC: addiu       $t1, $sp, 0x3D0
        ctx->r9 = ADD32(ctx->r29, 0X3D0);
            goto L_800D4D00;
    }
    // 0x800D4CBC: addiu       $t1, $sp, 0x3D0
    ctx->r9 = ADD32(ctx->r29, 0X3D0);
    // 0x800D4CC0: lbu         $t7, 0x56($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X56);
    // 0x800D4CC4: bne         $t7, $zero, L_800D4D00
    if (ctx->r15 != 0) {
        // 0x800D4CC8: nop
    
            goto L_800D4D00;
    }
    // 0x800D4CC8: nop

    // 0x800D4CCC: lw          $t8, 0x1C($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X1C);
    // 0x800D4CD0: lw          $a0, 0x408($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X408);
    // 0x800D4CD4: lw          $t9, 0x404($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X404);
    // 0x800D4CD8: beq         $t8, $zero, L_800D4D00
    if (ctx->r24 == 0) {
        // 0x800D4CDC: nop
    
            goto L_800D4D00;
    }
    // 0x800D4CDC: nop

    // 0x800D4CE0: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800D4CE4: lwc1        $f4, 0x4($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X4);
    // 0x800D4CE8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800D4CEC: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x800D4CF0: nop

    // 0x800D4CF4: bc1f        L_800D4D00
    if (!c1cs) {
        // 0x800D4CF8: nop
    
            goto L_800D4D00;
    }
    // 0x800D4CF8: nop

    // 0x800D4CFC: sb          $t0, 0x54($s3)
    MEM_B(0X54, ctx->r19) = ctx->r8;
L_800D4D00:
    // 0x800D4D00: bne         $s4, $t1, L_800D4D18
    if (ctx->r20 != ctx->r9) {
        // 0x800D4D04: lw          $a0, 0x408($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X408);
            goto L_800D4D18;
    }
    // 0x800D4D04: lw          $a0, 0x408($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X408);
    // 0x800D4D08: jal         0x800EE7F8
    // 0x800D4D0C: addiu       $a1, $sp, 0x3E4
    ctx->r5 = ADD32(ctx->r29, 0X3E4);
    func_800EE7F8(rdram, ctx);
        goto after_50;
    // 0x800D4D0C: addiu       $a1, $sp, 0x3E4
    ctx->r5 = ADD32(ctx->r29, 0X3E4);
    after_50:
    // 0x800D4D10: b           L_800D4D24
    // 0x800D4D14: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
        goto L_800D4D24;
    // 0x800D4D14: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_800D4D18:
    // 0x800D4D18: jal         0x800EE7F8
    // 0x800D4D1C: lw          $a1, 0xDC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XDC);
    func_800EE7F8(rdram, ctx);
        goto after_51;
    // 0x800D4D1C: lw          $a1, 0xDC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XDC);
    after_51:
L_800D4D20:
    // 0x800D4D20: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_800D4D24:
    // 0x800D4D24: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x800D4D28: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x800D4D2C: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x800D4D30: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x800D4D34: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x800D4D38: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x800D4D3C: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800D4D40: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x800D4D44: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x800D4D48: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x800D4D4C: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x800D4D50: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x800D4D54: jr          $ra
    // 0x800D4D58: addiu       $sp, $sp, 0x400
    ctx->r29 = ADD32(ctx->r29, 0X400);
    return;
    // 0x800D4D58: addiu       $sp, $sp, 0x400
    ctx->r29 = ADD32(ctx->r29, 0X400);
;}
RECOMP_FUNC void _bswalk_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084238: syscall     107
    recomp_syscall_handler(rdram, ctx, 0x80084238);
    return;
    // 0x8008423C: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void bsdronexform_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B9C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800BA0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800BA4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800BA8: lw          $t6, 0x18C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18C);
    // 0x80800BAC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800BB0: lbu         $t7, 0x1C($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X1C);
    // 0x80800BB4: beq         $t7, $zero, L_80800BC4
    if (ctx->r15 == 0) {
        // 0x80800BB8: nop
    
            goto L_80800BC4;
    }
    // 0x80800BB8: nop

    // 0x80800BBC: jal         0x8080051C
    // 0x80800BC0: nop

    func_8080051C_bsdronexform(rdram, ctx);
        goto after_0;
    // 0x80800BC0: nop

    after_0:
L_80800BC4:
    // 0x80800BC4: jal         0x80800724
    // 0x80800BC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800724_bsdronexform(rdram, ctx);
        goto after_1;
    // 0x80800BC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800BCC: lw          $t8, 0x18C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X18C);
    // 0x80800BD0: lbu         $t9, 0x32($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X32);
    // 0x80800BD4: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80800BD8: sltiu       $at, $t0, 0x9
    ctx->r1 = ctx->r8 < 0X9 ? 1 : 0;
    // 0x80800BDC: beq         $at, $zero, L_80801154
    if (ctx->r1 == 0) {
        // 0x80800BE0: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_80801154;
    }
    // 0x80800BE0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80800BE4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(208, 0X11A8) << 16);
    // 0x80800BE8: addu        $at, $at, $t0
    gpr jr_addend_80800BF0 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80800BEC: lw          $t0, 0x11A8($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(208, 0X11A8));
    // 0x80800BF0: jr          $t0
    // 0x80800BF4: nop

    switch (jr_addend_80800BF0 >> 2) {
        case 0: goto L_80800BF8; break;
        case 1: goto L_80800E00; break;
        case 2: goto L_80800E60; break;
        case 3: goto L_80800EC4; break;
        case 4: goto L_80800F28; break;
        case 5: goto L_80800F4C; break;
        case 6: goto L_80800F70; break;
        case 7: goto L_80800FD4; break;
        case 8: goto L_808010E8; break;
        default: switch_error(__func__, 0x80800BF0, 0x808011A8);
    }
    // 0x80800BF4: nop

L_80800BF8:
    // 0x80800BF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BFC: jal         0x800852F0
    // 0x80800C00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_2;
    // 0x80800C00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800C04: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800C08: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800C0C: lui         $a2, 0x4033
    ctx->r6 = S32(0X4033 << 16);
    // 0x80800C10: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800C14: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800C18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800C20: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800C24: jal         0x80800B5C
    // 0x80800C28: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80800B5C_bsdronexform(rdram, ctx);
        goto after_3;
    // 0x80800C28: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80800C2C: lw          $t1, 0x18C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X18C);
    // 0x80800C30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C34: lwc1        $f6, 0x2C($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X2C);
    // 0x80800C38: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80800C3C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800C40: jal         0x8009C118
    // 0x80800C44: nop

    func_8009C118(rdram, ctx);
        goto after_4;
    // 0x80800C44: nop

    after_4:
    // 0x80800C48: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800C4C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800C50: lui         $a2, 0x4033
    ctx->r6 = S32(0X4033 << 16);
    // 0x80800C54: lui         $a3, 0x3E8F
    ctx->r7 = S32(0X3E8F << 16);
    // 0x80800C58: ori         $a3, $a3, 0x5C29
    ctx->r7 = ctx->r7 | 0X5C29;
    // 0x80800C5C: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800C60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800C68: jal         0x80800B5C
    // 0x80800C6C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_80800B5C_bsdronexform(rdram, ctx);
        goto after_5;
    // 0x80800C6C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x80800C70: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800C74: jal         0x808003BC
    // 0x80800C78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808003BC_bsdronexform(rdram, ctx);
        goto after_6;
    // 0x80800C78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800C7C: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x80800C80: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800C84: lui         $a2, 0x4033
    ctx->r6 = S32(0X4033 << 16);
    // 0x80800C88: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800C8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800C94: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    // 0x80800C98: jal         0x80800B5C
    // 0x80800C9C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_80800B5C_bsdronexform(rdram, ctx);
        goto after_7;
    // 0x80800C9C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_7:
    // 0x80800CA0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800CA4: jal         0x808003CC
    // 0x80800CA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808003CC_bsdronexform(rdram, ctx);
        goto after_8;
    // 0x80800CA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800CAC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(208, 0X11CC) << 16);
    // 0x80800CB0: lwc1        $f18, 0x11CC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(208, 0X11CC));
    // 0x80800CB4: lui         $a2, 0x4033
    ctx->r6 = S32(0X4033 << 16);
    // 0x80800CB8: lui         $a3, 0x3D23
    ctx->r7 = S32(0X3D23 << 16);
    // 0x80800CBC: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x80800CC0: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800CCC: jal         0x80800B5C
    // 0x80800CD0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_80800B5C_bsdronexform(rdram, ctx);
        goto after_9;
    // 0x80800CD0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_9:
    // 0x80800CD4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800CD8: jal         0x808003DC
    // 0x80800CDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808003DC_bsdronexform(rdram, ctx);
        goto after_10;
    // 0x80800CDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800CE0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(208, 0X11D0) << 16);
    // 0x80800CE4: lwc1        $f4, 0x11D0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(208, 0X11D0));
    // 0x80800CE8: lui         $a2, 0x4033
    ctx->r6 = S32(0X4033 << 16);
    // 0x80800CEC: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800CF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800CF8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800CFC: jal         0x80800B5C
    // 0x80800D00: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80800B5C_bsdronexform(rdram, ctx);
        goto after_11;
    // 0x80800D00: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_11:
    // 0x80800D04: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800D08: jal         0x80800714
    // 0x80800D0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800714_bsdronexform(rdram, ctx);
        goto after_12;
    // 0x80800D0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800D10: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(208, 0X11D4) << 16);
    // 0x80800D14: lwc1        $f6, 0x11D4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(208, 0X11D4));
    // 0x80800D18: lui         $a2, 0x4033
    ctx->r6 = S32(0X4033 << 16);
    // 0x80800D1C: lui         $a3, 0x3D4C
    ctx->r7 = S32(0X3D4C << 16);
    // 0x80800D20: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800D24: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800D28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800D30: jal         0x80800B5C
    // 0x80800D34: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_80800B5C_bsdronexform(rdram, ctx);
        goto after_13;
    // 0x80800D34: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_13:
    // 0x80800D38: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800D3C: jal         0x80800704
    // 0x80800D40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800704_bsdronexform(rdram, ctx);
        goto after_14;
    // 0x80800D40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800D44: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800D48: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800D4C: lui         $a2, 0x4033
    ctx->r6 = S32(0X4033 << 16);
    // 0x80800D50: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800D54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800D5C: lui         $a3, 0x437F
    ctx->r7 = S32(0X437F << 16);
    // 0x80800D60: jal         0x80800B5C
    // 0x80800D64: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_80800B5C_bsdronexform(rdram, ctx);
        goto after_15;
    // 0x80800D64: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_15:
    // 0x80800D68: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80800D6C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800D70: lui         $a2, 0x4033
    ctx->r6 = S32(0X4033 << 16);
    // 0x80800D74: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800D78: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80800D7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800D84: lui         $a3, 0x437F
    ctx->r7 = S32(0X437F << 16);
    // 0x80800D88: jal         0x80800B5C
    // 0x80800D8C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_80800B5C_bsdronexform(rdram, ctx);
        goto after_16;
    // 0x80800D8C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_16:
    // 0x80800D90: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80800D94: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800D98: lui         $a2, 0x4033
    ctx->r6 = S32(0X4033 << 16);
    // 0x80800D9C: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800DA0: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800DA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800DAC: lui         $a3, 0x437F
    ctx->r7 = S32(0X437F << 16);
    // 0x80800DB0: jal         0x80800B5C
    // 0x80800DB4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_80800B5C_bsdronexform(rdram, ctx);
        goto after_17;
    // 0x80800DB4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_17:
    // 0x80800DB8: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800DBC: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800DC0: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800DC4: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80800DC8: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80800DCC: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80800DD0: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x80800DD4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800DD8: jal         0x800C59F0
    // 0x80800DDC: nop

    func_800C59F0(rdram, ctx);
        goto after_18;
    // 0x80800DDC: nop

    after_18:
    // 0x80800DE0: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80800DE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DE8: beql        $t5, $zero, L_80801158
    if (ctx->r13 == 0) {
        // 0x80800DEC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80801158;
    }
    goto skip_0;
    // 0x80800DEC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800DF0: jal         0x80800758
    // 0x80800DF4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800758_bsdronexform(rdram, ctx);
        goto after_19;
    // 0x80800DF4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_19:
    // 0x80800DF8: b           L_80801158
    // 0x80800DFC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801158;
    // 0x80800DFC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800E00:
    // 0x80800E00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E04: jal         0x800852F0
    // 0x80800E08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_20;
    // 0x80800E08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_20:
    // 0x80800E0C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(208, 0X11D8) << 16);
    // 0x80800E10: lwc1        $f16, 0x11D8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(208, 0X11D8));
    // 0x80800E14: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x80800E18: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800E1C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800E20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800E28: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x80800E2C: jal         0x80800B5C
    // 0x80800E30: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_80800B5C_bsdronexform(rdram, ctx);
        goto after_21;
    // 0x80800E30: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_21:
    // 0x80800E34: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800E38: jal         0x80800704
    // 0x80800E3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800704_bsdronexform(rdram, ctx);
        goto after_22;
    // 0x80800E3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80800E40: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80800E44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E48: beql        $t6, $zero, L_80801158
    if (ctx->r14 == 0) {
        // 0x80800E4C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80801158;
    }
    goto skip_1;
    // 0x80800E4C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80800E50: jal         0x80800758
    // 0x80800E54: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800758_bsdronexform(rdram, ctx);
        goto after_23;
    // 0x80800E54: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_23:
    // 0x80800E58: b           L_80801158
    // 0x80800E5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801158;
    // 0x80800E5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800E60:
    // 0x80800E60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E64: jal         0x800852F0
    // 0x80800E68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_24;
    // 0x80800E68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_24:
    // 0x80800E6C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(208, 0X11DC) << 16);
    // 0x80800E70: lwc1        $f18, 0x11DC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(208, 0X11DC));
    // 0x80800E74: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x80800E78: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x80800E7C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800E80: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800E84: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800E88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800E90: jal         0x80800B5C
    // 0x80800E94: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_80800B5C_bsdronexform(rdram, ctx);
        goto after_25;
    // 0x80800E94: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_25:
    // 0x80800E98: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800E9C: jal         0x80800714
    // 0x80800EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800714_bsdronexform(rdram, ctx);
        goto after_26;
    // 0x80800EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80800EA4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80800EA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EAC: beql        $t7, $zero, L_80801158
    if (ctx->r15 == 0) {
        // 0x80800EB0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80801158;
    }
    goto skip_2;
    // 0x80800EB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80800EB4: jal         0x80800758
    // 0x80800EB8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800758_bsdronexform(rdram, ctx);
        goto after_27;
    // 0x80800EB8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_27:
    // 0x80800EBC: b           L_80801158
    // 0x80800EC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801158;
    // 0x80800EC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800EC4:
    // 0x80800EC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EC8: jal         0x800852F0
    // 0x80800ECC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_28;
    // 0x80800ECC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_28:
    // 0x80800ED0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(208, 0X11E0) << 16);
    // 0x80800ED4: lwc1        $f4, 0x11E0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(208, 0X11E0));
    // 0x80800ED8: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80800EDC: lui         $a3, 0x3F99
    ctx->r7 = S32(0X3F99 << 16);
    // 0x80800EE0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800EE4: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80800EE8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800EEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800EF4: jal         0x80800B5C
    // 0x80800EF8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80800B5C_bsdronexform(rdram, ctx);
        goto after_29;
    // 0x80800EF8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_29:
    // 0x80800EFC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800F00: jal         0x80800714
    // 0x80800F04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800714_bsdronexform(rdram, ctx);
        goto after_30;
    // 0x80800F04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x80800F08: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80800F0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F10: beql        $t8, $zero, L_80801158
    if (ctx->r24 == 0) {
        // 0x80800F14: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80801158;
    }
    goto skip_3;
    // 0x80800F14: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x80800F18: jal         0x80800758
    // 0x80800F1C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800758_bsdronexform(rdram, ctx);
        goto after_31;
    // 0x80800F1C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_31:
    // 0x80800F20: b           L_80801158
    // 0x80800F24: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801158;
    // 0x80800F24: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800F28:
    // 0x80800F28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F2C: jal         0x800852F0
    // 0x80800F30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_32;
    // 0x80800F30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_32:
    // 0x80800F34: beq         $v0, $zero, L_80801154
    if (ctx->r2 == 0) {
        // 0x80800F38: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801154;
    }
    // 0x80800F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F3C: jal         0x80800758
    // 0x80800F40: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800758_bsdronexform(rdram, ctx);
        goto after_33;
    // 0x80800F40: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_33:
    // 0x80800F44: b           L_80801158
    // 0x80800F48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801158;
    // 0x80800F48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800F4C:
    // 0x80800F4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F50: jal         0x800852F0
    // 0x80800F54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_34;
    // 0x80800F54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_34:
    // 0x80800F58: beq         $v0, $zero, L_80801154
    if (ctx->r2 == 0) {
        // 0x80800F5C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801154;
    }
    // 0x80800F5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F60: jal         0x80800758
    // 0x80800F64: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800758_bsdronexform(rdram, ctx);
        goto after_35;
    // 0x80800F64: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_35:
    // 0x80800F68: b           L_80801158
    // 0x80800F6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801158;
    // 0x80800F6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800F70:
    // 0x80800F70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F74: jal         0x800852F0
    // 0x80800F78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_36;
    // 0x80800F78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_36:
    // 0x80800F7C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800F80: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800F84: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80800F88: lui         $a3, 0x3DB8
    ctx->r7 = S32(0X3DB8 << 16);
    // 0x80800F8C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800F90: ori         $a3, $a3, 0x51EC
    ctx->r7 = ctx->r7 | 0X51EC;
    // 0x80800F94: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800F98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800FA0: jal         0x80800B5C
    // 0x80800FA4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_80800B5C_bsdronexform(rdram, ctx);
        goto after_37;
    // 0x80800FA4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_37:
    // 0x80800FA8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800FAC: jal         0x80800714
    // 0x80800FB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800714_bsdronexform(rdram, ctx);
        goto after_38;
    // 0x80800FB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_38:
    // 0x80800FB4: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80800FB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FBC: beql        $t9, $zero, L_80801158
    if (ctx->r25 == 0) {
        // 0x80800FC0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80801158;
    }
    goto skip_4;
    // 0x80800FC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x80800FC4: jal         0x80800758
    // 0x80800FC8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80800758_bsdronexform(rdram, ctx);
        goto after_39;
    // 0x80800FC8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_39:
    // 0x80800FCC: b           L_80801158
    // 0x80800FD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801158;
    // 0x80800FD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800FD4:
    // 0x80800FD4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(208, 0X11E4) << 16);
    // 0x80800FD8: lwc1        $f8, 0x11E4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(208, 0X11E4));
    // 0x80800FDC: lui         $a3, 0x3EB3
    ctx->r7 = S32(0X3EB3 << 16);
    // 0x80800FE0: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x80800FE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800FEC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800FF0: jal         0x80800B5C
    // 0x80800FF4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_80800B5C_bsdronexform(rdram, ctx);
        goto after_40;
    // 0x80800FF4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_40:
    // 0x80800FF8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800FFC: jal         0x808003DC
    // 0x80801000: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808003DC_bsdronexform(rdram, ctx);
        goto after_41;
    // 0x80801000: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_41:
    // 0x80801004: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(208, 0X11E8) << 16);
    // 0x80801008: lwc1        $f10, 0x11E8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(208, 0X11E8));
    // 0x8080100C: lui         $a3, 0x3F19
    ctx->r7 = S32(0X3F19 << 16);
    // 0x80801010: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80801014: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801018: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080101C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801020: jal         0x80800B5C
    // 0x80801024: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_80800B5C_bsdronexform(rdram, ctx);
        goto after_42;
    // 0x80801024: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_42:
    // 0x80801028: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080102C: jal         0x80800704
    // 0x80801030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800704_bsdronexform(rdram, ctx);
        goto after_43;
    // 0x80801030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_43:
    // 0x80801034: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80801038: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080103C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801040: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801044: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801048: lui         $a3, 0x4348
    ctx->r7 = S32(0X4348 << 16);
    // 0x8080104C: jal         0x80800B5C
    // 0x80801050: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_80800B5C_bsdronexform(rdram, ctx);
        goto after_44;
    // 0x80801050: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_44:
    // 0x80801054: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80801058: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080105C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80801060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801064: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801068: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080106C: lui         $a3, 0x42A0
    ctx->r7 = S32(0X42A0 << 16);
    // 0x80801070: jal         0x80800B5C
    // 0x80801074: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_80800B5C_bsdronexform(rdram, ctx);
        goto after_45;
    // 0x80801074: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_45:
    // 0x80801078: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8080107C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801080: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80801084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801088: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080108C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801090: lui         $a3, 0x42A0
    ctx->r7 = S32(0X42A0 << 16);
    // 0x80801094: jal         0x80800B5C
    // 0x80801098: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80800B5C_bsdronexform(rdram, ctx);
        goto after_46;
    // 0x80801098: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_46:
    // 0x8080109C: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808010A0: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808010A4: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808010A8: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x808010AC: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x808010B0: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x808010B4: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x808010B8: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x808010BC: jal         0x800C59F0
    // 0x808010C0: nop

    func_800C59F0(rdram, ctx);
        goto after_47;
    // 0x808010C0: nop

    after_47:
    // 0x808010C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010C8: jal         0x800852F0
    // 0x808010CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_48;
    // 0x808010CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_48:
    // 0x808010D0: beq         $v0, $zero, L_80801154
    if (ctx->r2 == 0) {
        // 0x808010D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801154;
    }
    // 0x808010D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010D8: jal         0x80800758
    // 0x808010DC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80800758_bsdronexform(rdram, ctx);
        goto after_49;
    // 0x808010DC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_49:
    // 0x808010E0: b           L_80801158
    // 0x808010E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801158;
    // 0x808010E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808010E8:
    // 0x808010E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010EC: jal         0x800852F0
    // 0x808010F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_50;
    // 0x808010F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_50:
    // 0x808010F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808010F8: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x808010FC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80801100: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80801104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801108: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080110C: lui         $a3, 0x42B4
    ctx->r7 = S32(0X42B4 << 16);
    // 0x80801110: jal         0x80800B5C
    // 0x80801114: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80800B5C_bsdronexform(rdram, ctx);
        goto after_51;
    // 0x80801114: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_51:
    // 0x80801118: lw          $t3, 0x18C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X18C);
    // 0x8080111C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801120: lwc1        $f6, 0x2C($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X2C);
    // 0x80801124: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80801128: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8080112C: jal         0x8009C118
    // 0x80801130: nop

    func_8009C118(rdram, ctx);
        goto after_52;
    // 0x80801130: nop

    after_52:
    // 0x80801134: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80801138: beql        $t4, $zero, L_80801158
    if (ctx->r12 == 0) {
        // 0x8080113C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80801158;
    }
    goto skip_5;
    // 0x8080113C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x80801140: jal         0x80084750
    // 0x80801144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badata_entrypoint_34(rdram, ctx);
        goto after_53;
    // 0x80801144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_53:
    // 0x80801148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080114C: jal         0x8009E5C8
    // 0x80801150: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_54;
    // 0x80801150: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_54:
L_80801154:
    // 0x80801154: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801158:
    // 0x80801158: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080115C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80801160: jr          $ra
    // 0x80801164: nop

    return;
    // 0x80801164: nop

    // 0x80801168: nop

    // 0x8080116C: nop

;}
RECOMP_FUNC void func_80022D1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022D1C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80022D20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80022D24: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80022D28: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80022D2C: lw          $t7, 0x18($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X18);
    // 0x80022D30: bne         $t7, $zero, L_80022D40
    if (ctx->r15 != 0) {
        // 0x80022D34: nop
    
            goto L_80022D40;
    }
    // 0x80022D34: nop

    // 0x80022D38: b           L_80022E10
    // 0x80022D3C: nop

        goto L_80022E10;
    // 0x80022D3C: nop

L_80022D40:
    // 0x80022D40: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80022D44: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80022D48: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80022D4C: jal         0x80025084
    // 0x80022D50: lw          $a0, 0x18($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X18);
    func_80025084(rdram, ctx);
        goto after_0;
    // 0x80022D50: lw          $a0, 0x18($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X18);
    after_0:
    // 0x80022D54: lh          $t9, 0x18($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X18);
    // 0x80022D58: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80022D5C: sltiu       $at, $t0, 0x14
    ctx->r1 = ctx->r8 < 0X14 ? 1 : 0;
    // 0x80022D60: beq         $at, $zero, L_80022E00
    if (ctx->r1 == 0) {
        // 0x80022D64: nop
    
            goto L_80022E00;
    }
    // 0x80022D64: nop

    // 0x80022D68: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80022D6C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80022D70: addu        $at, $at, $t0
    gpr jr_addend_80022D78 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80022D74: lw          $t0, 0x1A08($at)
    ctx->r8 = ADD32(ctx->r1, 0X1A08);
    // 0x80022D78: jr          $t0
    // 0x80022D7C: nop

    switch (jr_addend_80022D78 >> 2) {
        case 0: goto L_80022D80; break;
        case 1: goto L_80022E00; break;
        case 2: goto L_80022D9C; break;
        case 3: goto L_80022DB8; break;
        case 4: goto L_80022E00; break;
        case 5: goto L_80022E00; break;
        case 6: goto L_80022E00; break;
        case 7: goto L_80022E00; break;
        case 8: goto L_80022E00; break;
        case 9: goto L_80022E00; break;
        case 10: goto L_80022E00; break;
        case 11: goto L_80022E00; break;
        case 12: goto L_80022E00; break;
        case 13: goto L_80022E00; break;
        case 14: goto L_80022E00; break;
        case 15: goto L_80022E00; break;
        case 16: goto L_80022E00; break;
        case 17: goto L_80022DF0; break;
        case 18: goto L_80022DF0; break;
        case 19: goto L_80022DF0; break;
        default: switch_error(__func__, 0x80022D78, 0x80041A08);
    }
    // 0x80022D7C: nop

L_80022D80:
    // 0x80022D80: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80022D84: jal         0x80023008
    // 0x80022D88: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    func_80023008(rdram, ctx);
        goto after_1;
    // 0x80022D88: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x80022D8C: jal         0x80024DD8
    // 0x80022D90: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80024DD8(rdram, ctx);
        goto after_2;
    // 0x80022D90: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80022D94: b           L_80022E08
    // 0x80022D98: nop

        goto L_80022E08;
    // 0x80022D98: nop

L_80022D9C:
    // 0x80022D9C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80022DA0: jal         0x80024A5C
    // 0x80022DA4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    func_80024A5C(rdram, ctx);
        goto after_3;
    // 0x80022DA4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_3:
    // 0x80022DA8: jal         0x80024DD8
    // 0x80022DAC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80024DD8(rdram, ctx);
        goto after_4;
    // 0x80022DAC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x80022DB0: b           L_80022E08
    // 0x80022DB4: nop

        goto L_80022E08;
    // 0x80022DB4: nop

L_80022DB8:
    // 0x80022DB8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80022DBC: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80022DC0: sw          $t1, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->r9;
    // 0x80022DC4: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x80022DC8: sh          $t3, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r11;
    // 0x80022DCC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80022DD0: lui         $a2, 0x7FFF
    ctx->r6 = S32(0X7FFF << 16);
    // 0x80022DD4: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x80022DD8: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80022DDC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80022DE0: jal         0x80026500
    // 0x80022DE4: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    func_80026500(rdram, ctx);
        goto after_5;
    // 0x80022DE4: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_5:
    // 0x80022DE8: b           L_80022E08
    // 0x80022DEC: nop

        goto L_80022E08;
    // 0x80022DEC: nop

L_80022DF0:
    // 0x80022DF0: jal         0x80024DD8
    // 0x80022DF4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80024DD8(rdram, ctx);
        goto after_6;
    // 0x80022DF4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_6:
    // 0x80022DF8: b           L_80022E08
    // 0x80022DFC: nop

        goto L_80022E08;
    // 0x80022DFC: nop

L_80022E00:
    // 0x80022E00: b           L_80022E08
    // 0x80022E04: nop

        goto L_80022E08;
    // 0x80022E04: nop

L_80022E08:
    // 0x80022E08: b           L_80022E10
    // 0x80022E0C: nop

        goto L_80022E10;
    // 0x80022E0C: nop

L_80022E10:
    // 0x80022E10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80022E14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80022E18: jr          $ra
    // 0x80022E1C: nop

    return;
    // 0x80022E1C: nop

;}
RECOMP_FUNC void func_808001FC_chrainripples(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001FC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800200: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80800204: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80800208: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080020C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800210: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80800214: jal         0x800EE7F8
    // 0x80800218: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800218: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080021C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800220: jal         0x800EE7F8
    // 0x80800224: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800224: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x80800228: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8080022C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800230: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800234: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800238: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8080023C: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80800240: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80800244: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x80800248: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8080024C: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x80800250: addiu       $a3, $zero, 0x1F00
    ctx->r7 = ADD32(0, 0X1F00);
    // 0x80800254: jal         0x800BEF00
    // 0x80800258: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    func_800BEF00(rdram, ctx);
        goto after_2;
    // 0x80800258: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x8080025C: beq         $v0, $zero, L_8080026C
    if (ctx->r2 == 0) {
        // 0x80800260: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080026C;
    }
    // 0x80800260: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800264: b           L_80800274
    // 0x80800268: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
        goto L_80800274;
    // 0x80800268: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
L_8080026C:
    // 0x8080026C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80800270: lwc1        $f0, 0x8($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X8);
L_80800274:
    // 0x80800274: jr          $ra
    // 0x80800278: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80800278: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8080027C: nop

;}
RECOMP_FUNC void func_80800260_chhoneycarrier(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800260: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80800264: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80800268: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x8080026C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800270: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x80800274: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x80800278: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x8080027C: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x80800280: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x80800284: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80800288: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8080028C: jal         0x800D8FF8
    // 0x80800290: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800290: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    after_0:
    // 0x80800294: lwc1        $f6, 0x58($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X58);
    // 0x80800298: lwc1        $f4, 0x48($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X48);
    // 0x8080029C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808002A0: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x808002A4: swc1        $f10, 0x48($s2)
    MEM_W(0X48, ctx->r18) = ctx->f10.u32l;
    // 0x808002A8: jal         0x800136E4
    // 0x808002AC: lwc1        $f12, 0x48($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X48);
    func_800136E4(rdram, ctx);
        goto after_1;
    // 0x808002AC: lwc1        $f12, 0x48($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X48);
    after_1:
    // 0x808002B0: lw          $t6, 0x7C($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X7C);
    // 0x808002B4: swc1        $f0, 0x48($s2)
    MEM_W(0X48, ctx->r18) = ctx->f0.u32l;
    // 0x808002B8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808002BC: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x808002C0: bgez        $t8, L_80800344
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808002C4: lui         $at, 0x4270
        ctx->r1 = S32(0X4270 << 16);
            goto L_80800344;
    }
    // 0x808002C4: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x808002C8: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x808002CC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1724, 0X3D0) << 16);
    // 0x808002D0: lwc1        $f26, 0x3D0($at)
    ctx->f26.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1724, 0X3D0));
    // 0x808002D4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x808002D8: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x808002DC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x808002E0: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x808002E4: addiu       $s0, $sp, 0x58
    ctx->r16 = ADD32(ctx->r29, 0X58);
L_808002E8:
    // 0x808002E8: jal         0x800DC298
    // 0x808002EC: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    func_800DC298(rdram, ctx);
        goto after_2;
    // 0x808002EC: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    after_2:
    // 0x808002F0: beq         $v0, $zero, L_80800338
    if (ctx->r2 == 0) {
        // 0x808002F4: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800338;
    }
    // 0x808002F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808002F8: jal         0x80103DFC
    // 0x808002FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80103DFC(rdram, ctx);
        goto after_3;
    // 0x808002FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x80800300: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x80800304: jal         0x800DC178
    // 0x80800308: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x80800308: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    after_4:
    // 0x8080030C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800310: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x80800314: jal         0x800DC178
    // 0x80800318: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    func_800DC178(rdram, ctx);
        goto after_5;
    // 0x80800318: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    after_5:
    // 0x8080031C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800320: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800324: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x80800328: jal         0x800EF214
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EF214(rdram, ctx);
        goto after_6;
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800330: jal         0x80088AA8
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _fxtwinkle_entrypoint_0(rdram, ctx);
        goto after_7;
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
L_80800338:
    // 0x80800338: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8080033C: bne         $s1, $s3, L_808002E8
    if (ctx->r17 != ctx->r19) {
        // 0x80800340: nop
    
            goto L_808002E8;
    }
    // 0x80800340: nop

L_80800344:
    // 0x80800344: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800348: jal         0x80103110
    // 0x8080034C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_8;
    // 0x8080034C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80800350: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80800354: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800358: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8080035C: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80800360: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x80800364: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x80800368: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x8080036C: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x80800370: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x80800374: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x80800378: jr          $ra
    // 0x8080037C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8080037C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80800160_chbigterrysbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800160: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800164: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800168: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x8080016C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800170: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80800174: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800178: bnel        $t7, $at, L_8080019C
    if (ctx->r15 != ctx->r1) {
        // 0x8080017C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080019C;
    }
    goto skip_0;
    // 0x8080017C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800180: jal         0x8008A4C0
    // 0x80800184: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _subaddieDll_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x80800184: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800188: beq         $v0, $zero, L_80800198
    if (ctx->r2 == 0) {
        // 0x8080018C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800198;
    }
    // 0x8080018C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800190: jal         0x8080022C
    // 0x80800194: nop

    func_8080022C_chbigterrysbits(rdram, ctx);
        goto after_1;
    // 0x80800194: nop

    after_1:
L_80800198:
    // 0x80800198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080019C:
    // 0x8080019C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001A0: jr          $ra
    // 0x808001A4: nop

    return;
    // 0x808001A4: nop

;}
RECOMP_FUNC void _chfirefx_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086140: syscall     281
    recomp_syscall_handler(rdram, ctx, 0x80086140);
    return;
    // 0x80086144: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800E9D90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9D90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E9D94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E9D98: jal         0x800E9D68
    // 0x800E9D9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800E9D68(rdram, ctx);
        goto after_0;
    // 0x800E9D9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800E9DA0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800E9DA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E9DA8: lh          $t7, 0x2($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X2);
    // 0x800E9DAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E9DB0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800E9DB4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800E9DB8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800E9DBC: jr          $ra
    // 0x800E9DC0: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    return;
    // 0x800E9DC0: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
;}
RECOMP_FUNC void func_8080016C_bskaztorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080016C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800170: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800174: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800178: jal         0x8009EF28
    // 0x8080017C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bastick_getX(rdram, ctx);
        goto after_0;
    // 0x8080017C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800180: jal         0x800D8FF8
    // 0x80800184: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80800184: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80800188: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8080018C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800190: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80800194: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800198: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8080019C: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808001A0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808001A4: lui         $a3, 0xC234
    ctx->r7 = S32(0XC234 << 16);
    // 0x808001A8: jal         0x800F10B4
    // 0x808001AC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x808001AC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x808001B0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808001B4: jal         0x8009C4CC
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baroll_setIdeal(rdram, ctx);
        goto after_3;
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808001BC: jal         0x8008E35C
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_4;
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808001C4: beq         $v0, $zero, L_808001DC
    if (ctx->r2 == 0) {
        // 0x808001C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001DC;
    }
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001CC: lui         $at, 0x4382
    ctx->r1 = S32(0X4382 << 16);
    // 0x808001D0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808001D4: b           L_808001E8
    // 0x808001D8: nop

        goto L_808001E8;
    // 0x808001D8: nop

L_808001DC:
    // 0x808001DC: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x808001E0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808001E4: nop

L_808001E8:
    // 0x808001E8: jal         0x8009C990
    // 0x808001EC: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    yaw_getIdeal(rdram, ctx);
        goto after_5;
    // 0x808001EC: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    after_5:
    // 0x808001F0: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808001F4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x808001F8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808001FC: neg.s       $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = -ctx->f2.fl;
    // 0x80800200: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80800204: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80800208: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8080020C: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800210: jal         0x800F10B4
    // 0x80800214: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_800F10B4(rdram, ctx);
        goto after_6;
    // 0x80800214: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_6:
    // 0x80800218: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8080021C: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800224: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800228: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8080022C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800230: jal         0x8009C914
    // 0x80800234: nop

    yaw_setIdeal(rdram, ctx);
        goto after_7;
    // 0x80800234: nop

    after_7:
    // 0x80800238: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080023C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800240: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800244: jr          $ra
    // 0x80800248: nop

    return;
    // 0x80800248: nop

;}
