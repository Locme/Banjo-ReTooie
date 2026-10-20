#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_808004A4_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "func_808004A4_chdragonbrothers");
    // 0x808004A4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808004A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808004AC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x808004B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808004B4: jal         0x80100094
    // 0x808004B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808004B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808004BC: beq         $s0, $zero, L_8080051C
    if (ctx->r16 == 0) {
        // 0x808004C0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8080051C;
    }
    // 0x808004C0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808004C4: lw          $a0, 0x20($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X20);
    // 0x808004C8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808004CC: jal         0x800F5A2C
    // 0x808004D0: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    func_800F5A2C(rdram, ctx);
        goto after_1;
    // 0x808004D0: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_1:
    // 0x808004D4: addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
    // 0x808004D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004DC: jal         0x800EE7F8
    // 0x808004E0: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x808004E0: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_2:
    // 0x808004E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004E8: jal         0x800EF334
    // 0x808004EC: lui         $a1, 0x3FA0
    ctx->r5 = S32(0X3FA0 << 16);
    func_800EF334(rdram, ctx);
        goto after_3;
    // 0x808004EC: lui         $a1, 0x3FA0
    ctx->r5 = S32(0X3FA0 << 16);
    after_3:
    // 0x808004F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X4FEC) << 16);
    // 0x808004F4: lwc1        $f6, 0x4FEC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1852, 0X4FEC));
    // 0x808004F8: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808004FC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800500: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80800504: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800508: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8080050C: jal         0x800A516C
    // 0x80800510: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    func_800A516C(rdram, ctx);
        goto after_4;
    // 0x80800510: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x80800514: b           L_80800568
    // 0x80800518: nop

        goto L_80800568;
    // 0x80800518: nop

L_8080051C:
    // 0x8080051C: addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
    // 0x80800520: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800524: jal         0x800F5A00
    // 0x80800528: lw          $a0, 0x20($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X20);
    func_800F5A00(rdram, ctx);
        goto after_5;
    // 0x80800528: lw          $a0, 0x20($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X20);
    after_5:
    // 0x8080052C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800530: jal         0x800F1EA4
    // 0x80800534: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_800F1EA4(rdram, ctx);
        goto after_6;
    // 0x80800534: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_6:
    // 0x80800538: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8080053C: lui         $a3, 0x458C
    ctx->r7 = S32(0X458C << 16);
    // 0x80800540: ori         $a3, $a3, 0xA000
    ctx->r7 = ctx->r7 | 0XA000;
    // 0x80800544: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080054C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80800550: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80800554: jal         0x800EEC30
    // 0x80800558: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_800EEC30(rdram, ctx);
        goto after_7;
    // 0x80800558: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x8080055C: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800560: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x80800564: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
L_80800568:
    // 0x80800568: jal         0x800A5240
    // 0x8080056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A5240(rdram, ctx);
        goto after_8;
    // 0x8080056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800570: jal         0x800A526C
    // 0x80800574: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_800A526C(rdram, ctx);
        goto after_9;
    // 0x80800574: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_9:
    // 0x80800578: jal         0x800A51C0
    // 0x8080057C: nop

    func_800A51C0(rdram, ctx);
        goto after_10;
    // 0x8080057C: nop

    after_10:
    // 0x80800580: jal         0x800A5240
    // 0x80800584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A5240(rdram, ctx);
        goto after_11;
    // 0x80800584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800588: jal         0x800A526C
    // 0x8080058C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_800A526C(rdram, ctx);
        goto after_12;
    // 0x8080058C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_12:
    // 0x80800590: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800594: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800598: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8080059C: jr          $ra
    // 0x808005A0: nop

    return;
    // 0x808005A0: nop

;}
RECOMP_FUNC void susplinet_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800254: jr          $ra
    // 0x80800258: lbu         $v0, 0x53($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X53);
    return;
    // 0x80800258: lbu         $v0, 0x53($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X53);
;}
RECOMP_FUNC void func_80801160_sumultiscore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801160: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801164: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80801168: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8080116C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80801170: lbu         $t6, 0x1($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X1);
    // 0x80801174: lb          $t8, 0xC($a1)
    ctx->r24 = MEM_B(ctx->r5, 0XC);
    // 0x80801178: lb          $t0, 0xD($a1)
    ctx->r8 = MEM_B(ctx->r5, 0XD);
    // 0x8080117C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80801180: addu        $v0, $a0, $t7
    ctx->r2 = ADD32(ctx->r4, ctx->r15);
    // 0x80801184: lhu         $t9, 0x0($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X0);
    // 0x80801188: lhu         $t1, 0x2($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X2);
    // 0x8080118C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80801190: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x80801194: jal         0x80088B38
    // 0x80801198: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    _fxdialog_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80801198: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_0:
    // 0x8080119C: jal         0x80088B40
    // 0x808011A0: lwc1        $f12, 0x10($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X10);
    _fxdialog_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x808011A0: lwc1        $f12, 0x10($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X10);
    after_1:
    // 0x808011A4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808011A8: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x808011AC: lbu         $a2, 0x4($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X4);
    // 0x808011B0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x808011B4: lbu         $t2, 0x5($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X5);
    // 0x808011B8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808011BC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x808011C0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808011C4: jal         0x80088B50
    // 0x808011C8: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    _fxdialog_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x808011C8: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_2:
    // 0x808011CC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808011D0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808011D4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808011D8: jr          $ra
    // 0x808011DC: nop

    return;
    // 0x808011DC: nop

;}
RECOMP_FUNC void func_80110848(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110848: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8011084C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80110850: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80110854: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80110858: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8011085C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80110860: jal         0x800EE7F8
    // 0x80110864: addiu       $a1, $a1, 0x74
    ctx->r5 = ADD32(ctx->r5, 0X74);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80110864: addiu       $a1, $a1, 0x74
    ctx->r5 = ADD32(ctx->r5, 0X74);
    after_0:
    // 0x80110868: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8011086C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80110870: jal         0x800EE7F8
    // 0x80110874: addiu       $a1, $a1, 0x80
    ctx->r5 = ADD32(ctx->r5, 0X80);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80110874: addiu       $a1, $a1, 0x80
    ctx->r5 = ADD32(ctx->r5, 0X80);
    after_1:
    // 0x80110878: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8011087C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80110880: jr          $ra
    // 0x80110884: nop

    return;
    // 0x80110884: nop

;}
RECOMP_FUNC void func_80800EBC_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800EC0: beq         $a1, $zero, L_80800EDC
    if (ctx->r5 == 0) {
        // 0x80800EC4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80800EDC;
    }
    // 0x80800EC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800EC8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800ECC: beql        $a1, $at, L_80800EF0
    if (ctx->r5 == ctx->r1) {
        // 0x80800ED0: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_80800EF0;
    }
    goto skip_0;
    // 0x80800ED0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    skip_0:
    // 0x80800ED4: b           L_80800F18
    // 0x80800ED8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800F18;
    // 0x80800ED8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800EDC:
    // 0x80800EDC: jal         0x800F82D4
    // 0x80800EE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_0;
    // 0x80800EE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800EE4: b           L_80800F18
    // 0x80800EE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800F18;
    // 0x80800EE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800EEC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_80800EF0:
    // 0x80800EF0: jal         0x800F82D4
    // 0x80800EF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F82D4(rdram, ctx);
        goto after_1;
    // 0x80800EF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80800EF8: jal         0x800F53D0
    // 0x80800EFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800F53D0(rdram, ctx);
        goto after_2;
    // 0x80800EFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800F00: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800F04: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800F08: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800F0C: jal         0x80084468
    // 0x80800F10: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _baattach_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x80800F10: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x80800F14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800F18:
    // 0x80800F18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F1C: jr          $ra
    // 0x80800F20: nop

    return;
    // 0x80800F20: nop

;}
RECOMP_FUNC void func_808010A0_chjollyroger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010A0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808010A4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808010A8: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x808010AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808010B0: beq         $a1, $at, L_808010D4
    if (ctx->r5 == ctx->r1) {
        // 0x808010B4: sw          $ra, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r31;
            goto L_808010D4;
    }
    // 0x808010B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808010B8: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x808010BC: bne         $a1, $at, L_8080116C
    if (ctx->r5 != ctx->r1) {
        // 0x808010C0: nop
    
            goto L_8080116C;
    }
    // 0x808010C0: nop

    // 0x808010C4: jal         0x80801194
    // 0x808010C8: nop

    func_80801194_chjollyroger(rdram, ctx);
        goto after_0;
    // 0x808010C8: nop

    after_0:
    // 0x808010CC: b           L_80801180
    // 0x808010D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801180;
    // 0x808010D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808010D4:
    // 0x808010D4: addiu       $a0, $zero, 0x360
    ctx->r4 = ADD32(0, 0X360);
    // 0x808010D8: jal         0x80089C30
    // 0x808010DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x808010DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808010E0: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x808010E4: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808010E8: jal         0x800EE7F8
    // 0x808010EC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x808010EC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_2:
    // 0x808010F0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808010F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808010F8: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808010FC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80801100: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    // 0x80801104: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80801108: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8080110C: jal         0x800EF1B8
    // 0x80801110: nop

    func_800EF1B8(rdram, ctx);
        goto after_3;
    // 0x80801110: nop

    after_3:
    // 0x80801114: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80801118: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080111C: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80801120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801124: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80801128: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8080112C: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    // 0x80801130: jal         0x80086670
    // 0x80801134: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80801134: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x80801138: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8080113C: addiu       $t6, $zero, 0x55
    ctx->r14 = ADD32(0, 0X55);
    // 0x80801140: addiu       $a1, $zero, 0x1044
    ctx->r5 = ADD32(0, 0X1044);
    // 0x80801144: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80801148: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080114C: addiu       $a2, $zero, 0x4C
    ctx->r6 = ADD32(0, 0X4C);
    // 0x80801150: jal         0x8008A208
    // 0x80801154: addiu       $a3, $v0, 0x4
    ctx->r7 = ADD32(ctx->r2, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x80801154: addiu       $a3, $v0, 0x4
    ctx->r7 = ADD32(ctx->r2, 0X4);
    after_5:
    // 0x80801158: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8080115C: jal         0x80102424
    // 0x80801160: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x80801160: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x80801164: b           L_80801180
    // 0x80801168: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801180;
    // 0x80801168: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080116C:
    // 0x8080116C: jal         0x80086248
    // 0x80801170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chdoor_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x80801170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80801174: b           L_80801184
    // 0x80801178: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801184;
    // 0x80801178: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080117C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801180:
    // 0x80801180: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801184:
    // 0x80801184: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801188: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8080118C: jr          $ra
    // 0x80801190: nop

    return;
    // 0x80801190: nop

;}
RECOMP_FUNC void func_80800620_chfriesstand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800620: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800624: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800628: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080062C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800630: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800634: addiu       $s1, $s0, 0x4
    ctx->r17 = ADD32(ctx->r16, 0X4);
    // 0x80800638: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(940, 0X102C) << 16);
    // 0x8080063C: lui         $a3, 0x3DA3
    ctx->r7 = S32(0X3DA3 << 16);
    // 0x80800640: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x80800644: addiu       $a2, $a2, 0x102C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(940, 0X102C));
    // 0x80800648: jal         0x80089D20
    // 0x8080064C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x8080064C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x80800650: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(940, 0X1038) << 16);
    // 0x80800654: lui         $a3, 0x3E6B
    ctx->r7 = S32(0X3E6B << 16);
    // 0x80800658: ori         $a3, $a3, 0x851F
    ctx->r7 = ctx->r7 | 0X851F;
    // 0x8080065C: addiu       $a2, $a2, 0x1038
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(940, 0X1038));
    // 0x80800660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800664: jal         0x80089D20
    // 0x80800668: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800668: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x8080066C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(940, 0X1044) << 16);
    // 0x80800670: lui         $a3, 0x3EAE
    ctx->r7 = S32(0X3EAE << 16);
    // 0x80800674: ori         $a3, $a3, 0x147B
    ctx->r7 = ctx->r7 | 0X147B;
    // 0x80800678: addiu       $a2, $a2, 0x1044
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(940, 0X1044));
    // 0x8080067C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800680: jal         0x80089D20
    // 0x80800684: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800684: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x80800688: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(940, 0X1050) << 16);
    // 0x8080068C: lui         $a3, 0x3ED7
    ctx->r7 = S32(0X3ED7 << 16);
    // 0x80800690: ori         $a3, $a3, 0xA3D
    ctx->r7 = ctx->r7 | 0XA3D;
    // 0x80800694: addiu       $a2, $a2, 0x1050
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(940, 0X1050));
    // 0x80800698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080069C: jal         0x80089D20
    // 0x808006A0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x808006A0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x808006A4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(940, 0X101C) << 16);
    // 0x808006A8: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(940, 0X105C) << 16);
    // 0x808006AC: addiu       $a3, $a3, 0x105C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(940, 0X105C));
    // 0x808006B0: addiu       $a2, $a2, 0x101C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(940, 0X101C));
    // 0x808006B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006B8: jal         0x80089D28
    // 0x808006BC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x808006BC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x808006C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808006C4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808006C8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808006CC: jr          $ra
    // 0x808006D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808006D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8001D450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D450: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x8001D454: andi        $t7, $t6, 0xF800
    ctx->r15 = ctx->r14 & 0XF800;
    // 0x8001D458: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x8001D45C: andi        $t1, $v1, 0x7C0
    ctx->r9 = ctx->r3 & 0X7C0;
    // 0x8001D460: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8001D464: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8001D468: bgez        $t7, L_8001D478
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8001D46C: sra         $t8, $t7, 1
        ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
            goto L_8001D478;
    }
    // 0x8001D46C: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8001D470: addiu       $at, $t7, 0x1
    ctx->r1 = ADD32(ctx->r15, 0X1);
    // 0x8001D474: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_8001D478:
    // 0x8001D478: andi        $t9, $t8, 0xF800
    ctx->r25 = ctx->r24 & 0XF800;
    // 0x8001D47C: or          $t0, $t9, $zero
    ctx->r8 = ctx->r25 | 0;
    // 0x8001D480: bgez        $t1, L_8001D490
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8001D484: sra         $t2, $t1, 1
        ctx->r10 = S32(SIGNED(ctx->r9) >> 1);
            goto L_8001D490;
    }
    // 0x8001D484: sra         $t2, $t1, 1
    ctx->r10 = S32(SIGNED(ctx->r9) >> 1);
    // 0x8001D488: addiu       $at, $t1, 0x1
    ctx->r1 = ADD32(ctx->r9, 0X1);
    // 0x8001D48C: sra         $t2, $at, 1
    ctx->r10 = S32(SIGNED(ctx->r1) >> 1);
L_8001D490:
    // 0x8001D490: andi        $t3, $t2, 0x7C0
    ctx->r11 = ctx->r10 & 0X7C0;
    // 0x8001D494: andi        $t6, $v1, 0x3E
    ctx->r14 = ctx->r3 & 0X3E;
    // 0x8001D498: or          $t4, $t3, $zero
    ctx->r12 = ctx->r11 | 0;
    // 0x8001D49C: or          $t5, $t0, $t4
    ctx->r13 = ctx->r8 | ctx->r12;
    // 0x8001D4A0: bgez        $t6, L_8001D4B0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8001D4A4: sra         $t7, $t6, 1
        ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
            goto L_8001D4B0;
    }
    // 0x8001D4A4: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8001D4A8: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x8001D4AC: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_8001D4B0:
    // 0x8001D4B0: andi        $t9, $t7, 0x3E
    ctx->r25 = ctx->r15 & 0X3E;
    // 0x8001D4B4: or          $v0, $t5, $t9
    ctx->r2 = ctx->r13 | ctx->r25;
    // 0x8001D4B8: ori         $t1, $v0, 0x1
    ctx->r9 = ctx->r2 | 0X1;
    // 0x8001D4BC: jr          $ra
    // 0x8001D4C0: andi        $v0, $t1, 0xFFFF
    ctx->r2 = ctx->r9 & 0XFFFF;
    return;
    // 0x8001D4C0: andi        $v0, $t1, 0xFFFF
    ctx->r2 = ctx->r9 & 0XFFFF;
;}
RECOMP_FUNC void _gsmaker_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082590: syscall     2
    recomp_syscall_handler(rdram, ctx, 0x80082590);
    return;
    // 0x80082594: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_80800070_gcnewoption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800070: lh          $t6, 0x8($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X8);
    // 0x80800074: jr          $ra
    // 0x80800078: addu        $v0, $t6, $a1
    ctx->r2 = ADD32(ctx->r14, ctx->r5);
    return;
    // 0x80800078: addu        $v0, $t6, $a1
    ctx->r2 = ADD32(ctx->r14, ctx->r5);
;}
RECOMP_FUNC void func_80800068_chjiggypost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800068: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080006C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800070: jal         0x800C0638
    // 0x80800074: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800C0638(rdram, ctx);
        goto after_0;
    // 0x80800074: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800078: bnel        $v0, $zero, L_808000F0
    if (ctx->r2 != 0) {
        // 0x8080007C: lw          $t9, 0x28($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X28);
            goto L_808000F0;
    }
    goto skip_0;
    // 0x8080007C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    skip_0:
    // 0x80800080: jal         0x800D035C
    // 0x80800084: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800D035C(rdram, ctx);
        goto after_1;
    // 0x80800084: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80800088: addiu       $a0, $zero, 0x10E
    ctx->r4 = ADD32(0, 0X10E);
    // 0x8080008C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800090: jal         0x800D2498
    // 0x80800094: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D2498(rdram, ctx);
        goto after_2;
    // 0x80800094: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80800098: jal         0x8008A698
    // 0x8080009C: nop

    _sujiggy_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x8080009C: nop

    after_3:
    // 0x808000A0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x808000A4: lhu         $a0, 0x76($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X76);
    // 0x808000A8: srl         $t7, $a0, 7
    ctx->r15 = S32(U32(ctx->r4) >> 7);
    // 0x808000AC: addiu       $a0, $t7, -0x33
    ctx->r4 = ADD32(ctx->r15, -0X33);
    // 0x808000B0: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808000B4: bnel        $at, $zero, L_808000F0
    if (ctx->r1 != 0) {
        // 0x808000B8: lw          $t9, 0x28($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X28);
            goto L_808000F0;
    }
    goto skip_1;
    // 0x808000B8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    skip_1:
    // 0x808000BC: jal         0x8008A6A8
    // 0x808000C0: nop

    _sujiggy_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x808000C0: nop

    after_4:
    // 0x808000C4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808000C8: jal         0x800D035C
    // 0x808000CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800D035C(rdram, ctx);
        goto after_5;
    // 0x808000CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x808000D0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x808000D4: addiu       $a0, $zero, 0x106
    ctx->r4 = ADD32(0, 0X106);
    // 0x808000D8: subu        $a1, $t8, $v0
    ctx->r5 = SUB32(ctx->r24, ctx->r2);
    // 0x808000DC: blezl       $a1, L_808000F0
    if (SIGNED(ctx->r5) <= 0) {
        // 0x808000E0: lw          $t9, 0x28($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X28);
            goto L_808000F0;
    }
    goto skip_2;
    // 0x808000E0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    skip_2:
    // 0x808000E4: jal         0x800D2498
    // 0x808000E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D2498(rdram, ctx);
        goto after_6;
    // 0x808000E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x808000EC: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
L_808000F0:
    // 0x808000F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000F4: lhu         $t0, 0x72($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X72);
    // 0x808000F8: srl         $t1, $t0, 10
    ctx->r9 = S32(U32(ctx->r8) >> 10);
    // 0x808000FC: bnel        $t1, $at, L_808001B8
    if (ctx->r9 != ctx->r1) {
        // 0x80800100: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808001B8;
    }
    goto skip_3;
    // 0x80800100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x80800104: jal         0x800DA298
    // 0x80800108: addiu       $a0, $zero, 0x4E8
    ctx->r4 = ADD32(0, 0X4E8);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x80800108: addiu       $a0, $zero, 0x4E8
    ctx->r4 = ADD32(0, 0X4E8);
    after_7:
    // 0x8080010C: bne         $v0, $zero, L_80800128
    if (ctx->r2 != 0) {
        // 0x80800110: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800128;
    }
    // 0x80800110: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800114: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800118: jal         0x80800014
    // 0x8080011C: addiu       $a1, $zero, 0x1512
    ctx->r5 = ADD32(0, 0X1512);
    func_80800014_chjiggypost(rdram, ctx);
        goto after_8;
    // 0x8080011C: addiu       $a1, $zero, 0x1512
    ctx->r5 = ADD32(0, 0X1512);
    after_8:
    // 0x80800120: b           L_808001B8
    // 0x80800124: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808001B8;
    // 0x80800124: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800128:
    // 0x80800128: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8080012C: addiu       $a1, $zero, 0xFA
    ctx->r5 = ADD32(0, 0XFA);
    // 0x80800130: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    // 0x80800134: jal         0x8008A1D8
    // 0x80800138: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_5(rdram, ctx);
        goto after_9;
    // 0x80800138: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_9:
    // 0x8080013C: beql        $v0, $zero, L_808001B8
    if (ctx->r2 == 0) {
        // 0x80800140: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808001B8;
    }
    goto skip_4;
    // 0x80800140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x80800144: jal         0x8008A698
    // 0x80800148: nop

    _sujiggy_entrypoint_0(rdram, ctx);
        goto after_10;
    // 0x80800148: nop

    after_10:
    // 0x8080014C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80800150: lhu         $t3, 0x76($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X76);
    // 0x80800154: srl         $t4, $t3, 7
    ctx->r12 = S32(U32(ctx->r11) >> 7);
    // 0x80800158: addiu       $t5, $t4, -0x33
    ctx->r13 = ADD32(ctx->r12, -0X33);
    // 0x8080015C: slt         $at, $t5, $v0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800160: beq         $at, $zero, L_80800170
    if (ctx->r1 == 0) {
        // 0x80800164: nop
    
            goto L_80800170;
    }
    // 0x80800164: nop

    // 0x80800168: b           L_808001AC
    // 0x8080016C: addiu       $a1, $zero, 0x1517
    ctx->r5 = ADD32(0, 0X1517);
        goto L_808001AC;
    // 0x8080016C: addiu       $a1, $zero, 0x1517
    ctx->r5 = ADD32(0, 0X1517);
L_80800170:
    // 0x80800170: jal         0x800D3E40
    // 0x80800174: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_800D3E40(rdram, ctx);
        goto after_11;
    // 0x80800174: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_11:
    // 0x80800178: beq         $v0, $zero, L_80800188
    if (ctx->r2 == 0) {
        // 0x8080017C: lw          $t6, 0x28($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X28);
            goto L_80800188;
    }
    // 0x8080017C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800180: b           L_808001AC
    // 0x80800184: addiu       $a1, $zero, 0x155A
    ctx->r5 = ADD32(0, 0X155A);
        goto L_808001AC;
    // 0x80800184: addiu       $a1, $zero, 0x155A
    ctx->r5 = ADD32(0, 0X155A);
L_80800188:
    // 0x80800188: lhu         $a0, 0x76($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X76);
    // 0x8080018C: srl         $t7, $a0, 7
    ctx->r15 = S32(U32(ctx->r4) >> 7);
    // 0x80800190: jal         0x8008A6A8
    // 0x80800194: addiu       $a0, $t7, -0x33
    ctx->r4 = ADD32(ctx->r15, -0X33);
    _sujiggy_entrypoint_2(rdram, ctx);
        goto after_12;
    // 0x80800194: addiu       $a0, $t7, -0x33
    ctx->r4 = ADD32(ctx->r15, -0X33);
    after_12:
    // 0x80800198: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080019C: bne         $v0, $at, L_808001AC
    if (ctx->r2 != ctx->r1) {
        // 0x808001A0: addiu       $a1, $zero, 0x1514
        ctx->r5 = ADD32(0, 0X1514);
            goto L_808001AC;
    }
    // 0x808001A0: addiu       $a1, $zero, 0x1514
    ctx->r5 = ADD32(0, 0X1514);
    // 0x808001A4: b           L_808001AC
    // 0x808001A8: addiu       $a1, $zero, 0x1513
    ctx->r5 = ADD32(0, 0X1513);
        goto L_808001AC;
    // 0x808001A8: addiu       $a1, $zero, 0x1513
    ctx->r5 = ADD32(0, 0X1513);
L_808001AC:
    // 0x808001AC: jal         0x80800014
    // 0x808001B0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80800014_chjiggypost(rdram, ctx);
        goto after_13;
    // 0x808001B0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_13:
    // 0x808001B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001B8:
    // 0x808001B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808001BC: jr          $ra
    // 0x808001C0: nop

    return;
    // 0x808001C0: nop

;}
RECOMP_FUNC void func_80800000_scradar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8080000C: lh          $t6, 0x4($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X4);
    // 0x80800010: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80800014: lh          $t9, 0x6($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X6);
    // 0x80800018: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8080001C: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x80800020: addiu       $t2, $zero, -0x4
    ctx->r10 = ADD32(0, -0X4);
    // 0x80800024: and         $v1, $t8, $t2
    ctx->r3 = ctx->r24 & ctx->r10;
    // 0x80800028: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8080002C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80800030: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x80800034: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80800038: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8080003C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80800040: lbu         $t6, 0xC($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0XC);
    // 0x80800044: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800048: and         $t0, $t7, $t2
    ctx->r8 = ctx->r15 & ctx->r10;
    // 0x8080004C: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x80800050: beq         $at, $zero, L_8080073C
    if (ctx->r1 == 0) {
        // 0x80800054: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8080073C;
    }
    // 0x80800054: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800058: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3126, 0XE10) << 16);
    // 0x8080005C: addu        $at, $at, $t6
    gpr jr_addend_80800064 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800060: lw          $t6, 0xE10($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(3126, 0XE10));
    // 0x80800064: jr          $t6
    // 0x80800068: nop

    switch (jr_addend_80800064 >> 2) {
        case 0: goto L_8080006C; break;
        case 1: goto L_80800178; break;
        case 2: goto L_8080032C; break;
        case 3: goto L_808005E0; break;
        case 4: goto L_80800488; break;
        default: switch_error(__func__, 0x80800064, 0x80800E10);
    }
    // 0x80800068: nop

L_8080006C:
    // 0x8080006C: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80800070: lui         $t8, 0xF800
    ctx->r24 = S32(0XF800 << 16);
    // 0x80800074: addiu       $t9, $zero, -0x80
    ctx->r25 = ADD32(0, -0X80);
    // 0x80800078: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8080007C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80800080: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80800084: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80800088: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8080008C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80800090: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80800094: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x80800098: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8080009C: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x808000A0: addiu       $t7, $t0, 0x4
    ctx->r15 = ADD32(ctx->r8, 0X4);
    // 0x808000A4: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x808000A8: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x808000AC: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x808000B0: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x808000B4: addiu       $t7, $v1, -0x4
    ctx->r15 = ADD32(ctx->r3, -0X4);
    // 0x808000B8: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x808000BC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x808000C0: andi        $t9, $t0, 0xFFF
    ctx->r25 = ctx->r8 & 0XFFF;
    // 0x808000C4: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x808000C8: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x808000CC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x808000D0: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x808000D4: lui         $t4, 0xE100
    ctx->r12 = S32(0XE100 << 16);
    // 0x808000D8: lui         $ra, 0x100
    ctx->r31 = S32(0X100 << 16);
    // 0x808000DC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x808000E0: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x808000E4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x808000E8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x808000EC: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x808000F0: ori         $ra, $ra, 0x100
    ctx->r31 = ctx->r31 | 0X100;
    // 0x808000F4: lui         $t5, 0xF100
    ctx->r13 = S32(0XF100 << 16);
    // 0x808000F8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x808000FC: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80800100: sw          $ra, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r31;
    // 0x80800104: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80800108: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8080010C: addiu       $t7, $v1, 0x4
    ctx->r15 = ADD32(ctx->r3, 0X4);
    // 0x80800110: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x80800114: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80800118: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8080011C: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x80800120: addiu       $t7, $t0, 0x8
    ctx->r15 = ADD32(ctx->r8, 0X8);
    // 0x80800124: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x80800128: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8080012C: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x80800130: addiu       $t6, $t0, -0x4
    ctx->r14 = ADD32(ctx->r8, -0X4);
    // 0x80800134: andi        $t7, $v1, 0xFFF
    ctx->r15 = ctx->r3 & 0XFFF;
    // 0x80800138: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8080013C: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x80800140: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x80800144: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x80800148: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8080014C: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80800150: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80800154: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x80800158: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8080015C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80800160: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80800164: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80800168: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8080016C: sw          $ra, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r31;
    // 0x80800170: b           L_8080073C
    // 0x80800174: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
        goto L_8080073C;
    // 0x80800174: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_80800178:
    // 0x80800178: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8080017C: lbu         $t3, 0xB($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0XB);
    // 0x80800180: lui         $t7, 0xF800
    ctx->r15 = S32(0XF800 << 16);
    // 0x80800184: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80800188: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x8080018C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80800190: lbu         $t6, 0xA($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0XA);
    // 0x80800194: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80800198: lui         $t4, 0xE100
    ctx->r12 = S32(0XE100 << 16);
    // 0x8080019C: sra         $t9, $t6, 2
    ctx->r25 = S32(SIGNED(ctx->r14) >> 2);
    // 0x808001A0: lbu         $t6, 0x8($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X8);
    // 0x808001A4: andi        $t8, $t9, 0xFF
    ctx->r24 = ctx->r25 & 0XFF;
    // 0x808001A8: sll         $t7, $t8, 8
    ctx->r15 = S32(ctx->r24 << 8);
    // 0x808001AC: sra         $t8, $t6, 2
    ctx->r24 = S32(SIGNED(ctx->r14) >> 2);
    // 0x808001B0: sll         $t6, $t8, 24
    ctx->r14 = S32(ctx->r24 << 24);
    // 0x808001B4: lbu         $t8, 0x9($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X9);
    // 0x808001B8: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x808001BC: lui         $ra, 0x100
    ctx->r31 = S32(0X100 << 16);
    // 0x808001C0: sra         $t7, $t8, 2
    ctx->r15 = S32(SIGNED(ctx->r24) >> 2);
    // 0x808001C4: andi        $t6, $t7, 0xFF
    ctx->r14 = ctx->r15 & 0XFF;
    // 0x808001C8: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x808001CC: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x808001D0: sra         $t9, $t3, 2
    ctx->r25 = S32(SIGNED(ctx->r11) >> 2);
    // 0x808001D4: sra         $t6, $t3, 1
    ctx->r14 = S32(SIGNED(ctx->r11) >> 1);
    // 0x808001D8: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x808001DC: andi        $t6, $t8, 0xFF
    ctx->r14 = ctx->r24 & 0XFF;
    // 0x808001E0: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x808001E4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x808001E8: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x808001EC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x808001F0: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x808001F4: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x808001F8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x808001FC: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80800200: addiu       $t7, $t0, 0x8
    ctx->r15 = ADD32(ctx->r8, 0X8);
    // 0x80800204: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x80800208: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x8080020C: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x80800210: addiu       $t7, $v1, -0x8
    ctx->r15 = ADD32(ctx->r3, -0X8);
    // 0x80800214: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80800218: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8080021C: addiu       $t9, $t0, -0x8
    ctx->r25 = ADD32(ctx->r8, -0X8);
    // 0x80800220: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x80800224: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x80800228: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x8080022C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80800230: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80800234: ori         $ra, $ra, 0x100
    ctx->r31 = ctx->r31 | 0X100;
    // 0x80800238: lui         $t5, 0xF100
    ctx->r13 = S32(0XF100 << 16);
    // 0x8080023C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80800240: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x80800244: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80800248: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8080024C: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80800250: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80800254: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80800258: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x8080025C: sw          $ra, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r31;
    // 0x80800260: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80800264: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80800268: lui         $t6, 0xF800
    ctx->r14 = S32(0XF800 << 16);
    // 0x8080026C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80800270: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80800274: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80800278: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8080027C: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80800280: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80800284: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x80800288: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8080028C: lbu         $t8, 0xA($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0XA);
    // 0x80800290: lbu         $t7, 0x8($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X8);
    // 0x80800294: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x80800298: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x8080029C: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x808002A0: lbu         $t9, 0x9($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X9);
    // 0x808002A4: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x808002A8: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x808002AC: andi        $t9, $t3, 0xFF
    ctx->r25 = ctx->r11 & 0XFF;
    // 0x808002B0: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x808002B4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x808002B8: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x808002BC: addiu       $t7, $v1, 0x4
    ctx->r15 = ADD32(ctx->r3, 0X4);
    // 0x808002C0: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x808002C4: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x808002C8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x808002CC: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x808002D0: addiu       $t7, $t0, 0x4
    ctx->r15 = ADD32(ctx->r8, 0X4);
    // 0x808002D4: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x808002D8: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x808002DC: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x808002E0: addiu       $t7, $v1, -0x4
    ctx->r15 = ADD32(ctx->r3, -0X4);
    // 0x808002E4: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x808002E8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x808002EC: addiu       $t6, $t0, -0x4
    ctx->r14 = ADD32(ctx->r8, -0X4);
    // 0x808002F0: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x808002F4: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x808002F8: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x808002FC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80800300: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80800304: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80800308: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x8080030C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80800310: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80800314: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80800318: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8080031C: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x80800320: sw          $ra, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r31;
    // 0x80800324: b           L_8080073C
    // 0x80800328: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
        goto L_8080073C;
    // 0x80800328: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_8080032C:
    // 0x8080032C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80800330: sw          $v1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r3;
    // 0x80800334: sw          $a2, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r6;
    // 0x80800338: sw          $a3, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r7;
    // 0x8080033C: jal         0x8001210C
    // 0x80800340: sw          $t0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r8;
    func_8001210C(rdram, ctx);
        goto after_0;
    // 0x80800340: sw          $t0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r8;
    after_0:
    // 0x80800344: lw          $v1, 0xAC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XAC);
    // 0x80800348: lw          $a2, 0xB8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB8);
    // 0x8080034C: lw          $a3, 0xB0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB0);
    // 0x80800350: beq         $v0, $zero, L_8080073C
    if (ctx->r2 == 0) {
        // 0x80800354: lw          $t0, 0xA8($sp)
        ctx->r8 = MEM_W(ctx->r29, 0XA8);
            goto L_8080073C;
    }
    // 0x80800354: lw          $t0, 0xA8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA8);
    // 0x80800358: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8080035C: lui         $t8, 0xF800
    ctx->r24 = S32(0XF800 << 16);
    // 0x80800360: lui         $t2, 0xE400
    ctx->r10 = S32(0XE400 << 16);
    // 0x80800364: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80800368: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8080036C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80800370: lbu         $t9, 0xA($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0XA);
    // 0x80800374: lbu         $t6, 0x8($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X8);
    // 0x80800378: lui         $t4, 0xE100
    ctx->r12 = S32(0XE100 << 16);
    // 0x8080037C: sll         $t7, $t9, 8
    ctx->r15 = S32(ctx->r25 << 8);
    // 0x80800380: sll         $t9, $t6, 24
    ctx->r25 = S32(ctx->r14 << 24);
    // 0x80800384: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x80800388: lbu         $t7, 0x9($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X9);
    // 0x8080038C: lui         $ra, 0x100
    ctx->r31 = S32(0X100 << 16);
    // 0x80800390: ori         $ra, $ra, 0x100
    ctx->r31 = ctx->r31 | 0X100;
    // 0x80800394: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x80800398: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x8080039C: lbu         $t8, 0xB($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0XB);
    // 0x808003A0: lui         $t5, 0xF100
    ctx->r13 = S32(0XF100 << 16);
    // 0x808003A4: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x808003A8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x808003AC: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x808003B0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x808003B4: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x808003B8: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x808003BC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x808003C0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x808003C4: addiu       $t6, $t0, 0x4
    ctx->r14 = ADD32(ctx->r8, 0X4);
    // 0x808003C8: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x808003CC: or          $t7, $t9, $t2
    ctx->r15 = ctx->r25 | ctx->r10;
    // 0x808003D0: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x808003D4: addiu       $t6, $v1, -0x4
    ctx->r14 = ADD32(ctx->r3, -0X4);
    // 0x808003D8: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x808003DC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x808003E0: andi        $t9, $t0, 0xFFF
    ctx->r25 = ctx->r8 & 0XFFF;
    // 0x808003E4: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x808003E8: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x808003EC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x808003F0: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x808003F4: addiu       $t6, $v1, 0x4
    ctx->r14 = ADD32(ctx->r3, 0X4);
    // 0x808003F8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x808003FC: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80800400: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80800404: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80800408: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8080040C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80800410: addiu       $t6, $t0, 0x8
    ctx->r14 = ADD32(ctx->r8, 0X8);
    // 0x80800414: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80800418: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x8080041C: sw          $ra, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r31;
    // 0x80800420: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80800424: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80800428: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x8080042C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80800430: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80800434: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x80800438: or          $t9, $t8, $t2
    ctx->r25 = ctx->r24 | ctx->r10;
    // 0x8080043C: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x80800440: addiu       $t7, $t0, -0x4
    ctx->r15 = ADD32(ctx->r8, -0X4);
    // 0x80800444: andi        $t6, $v1, 0xFFF
    ctx->r14 = ctx->r3 & 0XFFF;
    // 0x80800448: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8080044C: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80800450: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x80800454: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x80800458: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8080045C: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80800460: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80800464: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80800468: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8080046C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80800470: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80800474: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80800478: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x8080047C: sw          $ra, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r31;
    // 0x80800480: b           L_8080073C
    // 0x80800484: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
        goto L_8080073C;
    // 0x80800484: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_80800488:
    // 0x80800488: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8080048C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800490: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80800494: lui         $t9, 0xF800
    ctx->r25 = S32(0XF800 << 16);
    // 0x80800498: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x8080049C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808004A0: lui         $t4, 0xE100
    ctx->r12 = S32(0XE100 << 16);
    // 0x808004A4: lui         $ra, 0x100
    ctx->r31 = S32(0X100 << 16);
    // 0x808004A8: ori         $ra, $ra, 0x100
    ctx->r31 = ctx->r31 | 0X100;
    // 0x808004AC: lui         $t5, 0xF100
    ctx->r13 = S32(0XF100 << 16);
    // 0x808004B0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808004B4: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x808004B8: nop

    // 0x808004BC: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x808004C0: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x808004C4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x808004C8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x808004CC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x808004D0: lbu         $t8, 0xB($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0XB);
    // 0x808004D4: sra         $t6, $t8, 1
    ctx->r14 = S32(SIGNED(ctx->r24) >> 1);
    // 0x808004D8: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x808004DC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x808004E0: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x808004E4: addiu       $t8, $v1, 0x6
    ctx->r24 = ADD32(ctx->r3, 0X6);
    // 0x808004E8: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x808004EC: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x808004F0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x808004F4: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x808004F8: addiu       $t8, $t0, 0xE
    ctx->r24 = ADD32(ctx->r8, 0XE);
    // 0x808004FC: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x80800500: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x80800504: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x80800508: addiu       $t8, $v1, -0x6
    ctx->r24 = ADD32(ctx->r3, -0X6);
    // 0x8080050C: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80800510: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80800514: addiu       $t7, $t0, -0xE
    ctx->r15 = ADD32(ctx->r8, -0XE);
    // 0x80800518: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8080051C: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x80800520: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80800524: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80800528: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8080052C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80800530: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80800534: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80800538: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8080053C: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80800540: addiu       $t7, $v1, 0xA
    ctx->r15 = ADD32(ctx->r3, 0XA);
    // 0x80800544: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80800548: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x8080054C: sw          $ra, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r31;
    // 0x80800550: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80800554: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80800558: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8080055C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80800560: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80800564: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80800568: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x8080056C: addu        $t1, $t0, $t9
    ctx->r9 = ADD32(ctx->r8, ctx->r25);
    // 0x80800570: addiu       $t7, $t1, 0x6
    ctx->r15 = ADD32(ctx->r9, 0X6);
    // 0x80800574: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x80800578: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8080057C: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x80800580: addiu       $t7, $v1, -0xA
    ctx->r15 = ADD32(ctx->r3, -0XA);
    // 0x80800584: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x80800588: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8080058C: addiu       $t8, $t1, -0x6
    ctx->r24 = ADD32(ctx->r9, -0X6);
    // 0x80800590: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x80800594: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x80800598: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x8080059C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x808005A0: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x808005A4: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x808005A8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x808005AC: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x808005B0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x808005B4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x808005B8: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x808005BC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x808005C0: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x808005C4: sw          $ra, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r31;
    // 0x808005C8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x808005CC: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x808005D0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x808005D4: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x808005D8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x808005DC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_808005E0:
    // 0x808005E0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x808005E4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808005E8: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x808005EC: lui         $t9, 0xF800
    ctx->r25 = S32(0XF800 << 16);
    // 0x808005F0: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x808005F4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x808005F8: addiu       $t2, $v1, 0x6
    ctx->r10 = ADD32(ctx->r3, 0X6);
    // 0x808005FC: lui         $t4, 0xE100
    ctx->r12 = S32(0XE100 << 16);
    // 0x80800600: lui         $ra, 0x100
    ctx->r31 = S32(0X100 << 16);
    // 0x80800604: ori         $ra, $ra, 0x100
    ctx->r31 = ctx->r31 | 0X100;
    // 0x80800608: lui         $t5, 0xF100
    ctx->r13 = S32(0XF100 << 16);
    // 0x8080060C: addiu       $t3, $v1, -0x6
    ctx->r11 = ADD32(ctx->r3, -0X6);
    // 0x80800610: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800614: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x80800618: nop

    // 0x8080061C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80800620: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80800624: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80800628: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8080062C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80800630: lbu         $t6, 0xA($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0XA);
    // 0x80800634: lbu         $t8, 0x8($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X8);
    // 0x80800638: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x8080063C: sll         $t6, $t8, 24
    ctx->r14 = S32(ctx->r24 << 24);
    // 0x80800640: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x80800644: lbu         $t7, 0x9($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X9);
    // 0x80800648: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x8080064C: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x80800650: lbu         $t9, 0xB($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0XB);
    // 0x80800654: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x80800658: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8080065C: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80800660: addiu       $t8, $v1, 0x2
    ctx->r24 = ADD32(ctx->r3, 0X2);
    // 0x80800664: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80800668: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x8080066C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80800670: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80800674: addiu       $t8, $t0, 0xA
    ctx->r24 = ADD32(ctx->r8, 0XA);
    // 0x80800678: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8080067C: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80800680: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x80800684: addiu       $t8, $v1, -0x2
    ctx->r24 = ADD32(ctx->r3, -0X2);
    // 0x80800688: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x8080068C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80800690: addiu       $t6, $t0, -0xA
    ctx->r14 = ADD32(ctx->r8, -0XA);
    // 0x80800694: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x80800698: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x8080069C: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x808006A0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x808006A4: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x808006A8: andi        $t6, $t2, 0xFFF
    ctx->r14 = ctx->r10 & 0XFFF;
    // 0x808006AC: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x808006B0: or          $t2, $t9, $at
    ctx->r10 = ctx->r25 | ctx->r1;
    // 0x808006B4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x808006B8: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x808006BC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x808006C0: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x808006C4: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x808006C8: andi        $t7, $t3, 0xFFF
    ctx->r15 = ctx->r11 & 0XFFF;
    // 0x808006CC: sll         $t3, $t7, 12
    ctx->r11 = S32(ctx->r15 << 12);
    // 0x808006D0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x808006D4: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x808006D8: sw          $ra, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r31;
    // 0x808006DC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x808006E0: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x808006E4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x808006E8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x808006EC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808006F0: addu        $a1, $t0, $t6
    ctx->r5 = ADD32(ctx->r8, ctx->r14);
    // 0x808006F4: addiu       $t9, $a1, 0x2
    ctx->r25 = ADD32(ctx->r5, 0X2);
    // 0x808006F8: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x808006FC: addiu       $t6, $a1, -0x2
    ctx->r14 = ADD32(ctx->r5, -0X2);
    // 0x80800700: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x80800704: or          $t7, $t2, $t8
    ctx->r15 = ctx->r10 | ctx->r24;
    // 0x80800708: or          $t8, $t3, $t9
    ctx->r24 = ctx->r11 | ctx->r25;
    // 0x8080070C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80800710: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80800714: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80800718: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8080071C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80800720: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80800724: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80800728: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8080072C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80800730: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x80800734: sw          $ra, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r31;
    // 0x80800738: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_8080073C:
    // 0x8080073C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800740: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    // 0x80800744: jr          $ra
    // 0x80800748: nop

    return;
    // 0x80800748: nop

;}
RECOMP_FUNC void _bskazstill_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083638: syscall     70
    recomp_syscall_handler(rdram, ctx, 0x80083638);
    return;
    // 0x8008363C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_80101808(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_actor_draw_begin(rdram, ctx); tooie_actor_draw_reach(rdram, ctx);
    // 0x80101808: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8010180C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80101810: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80101814: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80101818: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8010181C: jal         0x800DF47C
    // 0x80101820: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800DF47C(rdram, ctx);
        goto after_0;
    // 0x80101820: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80101824: jal         0x801027F4
    // 0x80101828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801027F4(rdram, ctx);
        goto after_1;
    // 0x80101828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8010182C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80101830: jal         0x801018D8
    // 0x80101834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801018D8(rdram, ctx);
        goto after_2;
    // 0x80101834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80101838: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8010183C: jal         0x8010347C
    // 0x80101840: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_8010347C(rdram, ctx);
        goto after_3;
    // 0x80101840: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x80101844: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x80101848: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8010184C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80101850: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80101854: jal         0x800DE448
    // 0x80101858: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    func_800DE448(rdram, ctx);
        goto after_4;
    // 0x80101858: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_4:
    tooie_actor_shadow(rdram, ctx);
    // 0x8010185C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80101860: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80101864: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80101868: jr          $ra
    // 0x8010186C: nop

    return;
    // 0x8010186C: nop

;}
RECOMP_FUNC void _chnests_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085A70: syscall     191
    recomp_syscall_handler(rdram, ctx, 0x80085A70);
    return;
    // 0x80085A74: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800228_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800228: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080022C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800230: jal         0x8008D04C
    // 0x80800234: nop

    func_8008D04C(rdram, ctx);
        goto after_0;
    // 0x80800234: nop

    after_0:
    // 0x80800238: jal         0x8008B284
    // 0x8080023C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_getPlaybackType(rdram, ctx);
        goto after_1;
    // 0x8080023C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800240: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800244: bne         $v0, $at, L_80800254
    if (ctx->r2 != ctx->r1) {
        // 0x80800248: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800254;
    }
    // 0x80800248: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080024C: b           L_80800258
    // 0x80800250: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80800258;
    // 0x80800250: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80800254:
    // 0x80800254: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80800258:
    // 0x80800258: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8080025C: jr          $ra
    // 0x80800260: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800260: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_808026C8_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808026C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808026CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808026D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808026D4: jal         0x80106790
    // 0x808026D8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808026D8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x808026DC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x808026E0: lw          $t6, 0x1C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1C);
    // 0x808026E4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808026E8: beql        $v1, $t6, L_80802720
    if (ctx->r3 == ctx->r14) {
        // 0x808026EC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802720;
    }
    goto skip_0;
    // 0x808026EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808026F0: sw          $v1, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r3;
    // 0x808026F4: jal         0x80087BE0
    // 0x808026F8: lw          $a0, 0x28($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X28);
    _gczoombox_entrypoint_32(rdram, ctx);
        goto after_1;
    // 0x808026F8: lw          $a0, 0x28($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X28);
    after_1:
    // 0x808026FC: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x80802700: jal         0x80088720
    // 0x80802704: lh          $a1, 0x1E($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1E);
    _gldbstring_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80802704: lh          $a1, 0x1E($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1E);
    after_2:
    // 0x80802708: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x8080270C: jal         0x80087B20
    // 0x80802710: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _gczoombox_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x80802710: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80802714: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80802718: sw          $t7, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r15;
    // 0x8080271C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802720:
    // 0x80802720: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802724: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802728: jr          $ra
    // 0x8080272C: nop

    return;
    // 0x8080272C: nop

;}
RECOMP_FUNC void func_800D16CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D16CC: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x800D16D0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800D16D4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800D16D8: lh          $v1, -0x50AE($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X50AE);
    // 0x800D16DC: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800D16E0: sll         $t2, $v0, 1
    ctx->r10 = S32(ctx->r2 << 1);
    // 0x800D16E4: bne         $v1, $at, L_800D1718
    if (ctx->r3 != ctx->r1) {
        // 0x800D16E8: lui         $t3, 0x800D
        ctx->r11 = S32(0X800D << 16);
            goto L_800D1718;
    }
    // 0x800D16E8: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x800D16EC: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x800D16F0: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800D16F4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800D16F8: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800D16FC: lw          $t9, -0x4DB0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4DB0);
    // 0x800D1700: lh          $t7, 0x1A04($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X1A04);
    // 0x800D1704: sll         $t0, $a0, 1
    ctx->r8 = S32(ctx->r4 << 1);
    // 0x800D1708: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800D170C: xori        $t8, $t7, 0x3E7
    ctx->r24 = ctx->r15 ^ 0X3E7;
    // 0x800D1710: jr          $ra
    // 0x800D1714: sh          $t8, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r24;
    return;
    // 0x800D1714: sh          $t8, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r24;
L_800D1718:
    // 0x800D1718: bgez        $a1, L_800D1724
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800D171C: addu        $t3, $t3, $t2
        ctx->r11 = ADD32(ctx->r11, ctx->r10);
            goto L_800D1724;
    }
    // 0x800D171C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800D1720: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800D1724:
    // 0x800D1724: bltz        $v1, L_800D173C
    if (SIGNED(ctx->r3) < 0) {
        // 0x800D1728: lui         $t5, 0x8013
        ctx->r13 = S32(0X8013 << 16);
            goto L_800D173C;
    }
    // 0x800D1728: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800D172C: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800D1730: beq         $at, $zero, L_800D173C
    if (ctx->r1 == 0) {
        // 0x800D1734: nop
    
            goto L_800D173C;
    }
    // 0x800D1734: nop

    // 0x800D1738: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_800D173C:
    // 0x800D173C: lh          $t3, 0x1A04($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X1A04);
    // 0x800D1740: lw          $t5, -0x4DB0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4DB0);
    // 0x800D1744: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x800D1748: xor         $t4, $t3, $a1
    ctx->r12 = ctx->r11 ^ ctx->r5;
    // 0x800D174C: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800D1750: sh          $t4, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r12;
    // 0x800D1754: jr          $ra
    // 0x800D1758: nop

    return;
    // 0x800D1758: nop

;}
RECOMP_FUNC void func_800A3354(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3354: lw          $t6, 0xA0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA0);
    // 0x800A3358: jr          $ra
    // 0x800A335C: lbu         $v0, 0x54($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X54);
    return;
    // 0x800A335C: lbu         $v0, 0x54($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X54);
;}
RECOMP_FUNC void func_80013544(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013544: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80013548: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001354C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80013550: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80013554: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80013558: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001355C: lui         $s1, 0x8007
    ctx->r17 = S32(0X8007 << 16);
    // 0x80013560: lui         $s2, 0x8007
    ctx->r18 = S32(0X8007 << 16);
    // 0x80013564: lui         $s3, 0x8007
    ctx->r19 = S32(0X8007 << 16);
    // 0x80013568: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8001356C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80013570: addiu       $s3, $s3, 0x69E0
    ctx->r19 = ADD32(ctx->r19, 0X69E0);
    // 0x80013574: addiu       $s2, $s2, 0x73E0
    ctx->r18 = ADD32(ctx->r18, 0X73E0);
    // 0x80013578: addiu       $s1, $s1, 0x6A00
    ctx->r17 = ADD32(ctx->r17, 0X6A00);
    // 0x8001357C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80013580: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80013584: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80013588:
    // 0x80013588: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001358C: jal         0x8002E1F0
    // 0x80013590: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80013590: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_0:
    // 0x80013594: lw          $t6, 0x8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X8);
    // 0x80013598: sw          $s4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r20;
    // 0x8001359C: bnel        $t6, $zero, L_800135CC
    if (ctx->r14 != 0) {
        // 0x800135A0: sw          $zero, 0x0($s2)
        MEM_W(0X0, ctx->r18) = 0;
            goto L_800135CC;
    }
    goto skip_0;
    // 0x800135A0: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    skip_0:
L_800135A4:
    // 0x800135A4: jal         0x800A7FD4
    // 0x800135A8: nop

    func_800A7FD4(rdram, ctx);
        goto after_1;
    // 0x800135A8: nop

    after_1:
    // 0x800135AC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800135B0: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x800135B4: beql        $at, $zero, L_800135CC
    if (ctx->r1 == 0) {
        // 0x800135B8: sw          $zero, 0x0($s2)
        MEM_W(0X0, ctx->r18) = 0;
            goto L_800135CC;
    }
    goto skip_1;
    // 0x800135B8: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    skip_1:
    // 0x800135BC: lw          $t7, 0x8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X8);
    // 0x800135C0: beq         $t7, $zero, L_800135A4
    if (ctx->r15 == 0) {
        // 0x800135C4: nop
    
            goto L_800135A4;
    }
    // 0x800135C4: nop

    // 0x800135C8: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
L_800135CC:
    // 0x800135CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800135D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800135D4: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800135D8: jal         0x8002E1F0
    // 0x800135DC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800135DC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_2:
    // 0x800135E0: b           L_80013588
    // 0x800135E4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
        goto L_80013588;
    // 0x800135E4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800135E8: nop

    // 0x800135EC: nop

    // 0x800135F0: nop

    // 0x800135F4: nop

    // 0x800135F8: nop

    // 0x800135FC: nop

    // 0x80013600: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80013604: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80013608: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001360C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80013610: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80013614: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80013618: jr          $ra
    // 0x8001361C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8001361C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _chwaterfallgrill_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087020: syscall     493
    recomp_syscall_handler(rdram, ctx, 0x80087020);
    return;
    // 0x80087024: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void bababykaz_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800130: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800134: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800138: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080013C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800140: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800144: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800148: lw          $t7, 0x10($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X10);
    // 0x8080014C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800150: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80800154: lwc1        $f12, 0x4($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X4);
    // 0x80800158: jal         0x800F10B4
    // 0x8080015C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F10B4(rdram, ctx);
        goto after_0;
    // 0x8080015C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80800160: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800164: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800168: jal         0x80085338
    // 0x8080016C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    _batimer_set(rdram, ctx);
        goto after_1;
    // 0x8080016C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_1:
    // 0x80800170: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800174: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800178: jr          $ra
    // 0x8080017C: nop

    return;
    // 0x8080017C: nop

;}
RECOMP_FUNC void func_800BE7F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE7F8: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x800BE7FC: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x800BE800: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BE804: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800BE808: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x800BE80C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800BE810: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800BE814: addiu       $t7, $t7, -0x7A50
    ctx->r15 = ADD32(ctx->r15, -0X7A50);
    // 0x800BE818: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800BE81C: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x800BE820: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x800BE824: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800BE828: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800BE82C: beql        $t8, $zero, L_800BE9A0
    if (ctx->r24 == 0) {
        // 0x800BE830: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800BE9A0;
    }
    goto skip_0;
    // 0x800BE830: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800BE834: lbu         $t9, 0x2B($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X2B);
    // 0x800BE838: beql        $t9, $zero, L_800BE9A0
    if (ctx->r25 == 0) {
        // 0x800BE83C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800BE9A0;
    }
    goto skip_1;
    // 0x800BE83C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x800BE840: jal         0x800BF774
    // 0x800BE844: nop

    func_800BF774(rdram, ctx);
        goto after_0;
    // 0x800BE844: nop

    after_0:
    // 0x800BE848: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BE84C: jal         0x800DF738
    // 0x800BE850: lw          $a0, -0x78D8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78D8);
    func_800DF738(rdram, ctx);
        goto after_1;
    // 0x800BE850: lw          $a0, -0x78D8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78D8);
    after_1:
    // 0x800BE854: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800BE858: addiu       $t0, $t0, -0x7A50
    ctx->r8 = ADD32(ctx->r8, -0X7A50);
    // 0x800BE85C: bne         $s0, $t0, L_800BE86C
    if (ctx->r16 != ctx->r8) {
        // 0x800BE860: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800BE86C;
    }
    // 0x800BE860: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BE864: jal         0x800DF83C
    // 0x800BE868: lw          $a0, -0x78D4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78D4);
    func_800DF83C(rdram, ctx);
        goto after_2;
    // 0x800BE868: lw          $a0, -0x78D4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X78D4);
    after_2:
L_800BE86C:
    // 0x800BE86C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800BE870: addiu       $t1, $t1, -0x7A50
    ctx->r9 = ADD32(ctx->r9, -0X7A50);
    // 0x800BE874: beql        $s0, $t1, L_800BE888
    if (ctx->r16 == ctx->r9) {
        // 0x800BE878: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_800BE888;
    }
    goto skip_2;
    // 0x800BE878: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    skip_2:
    // 0x800BE87C: b           L_800BE888
    // 0x800BE880: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
        goto L_800BE888;
    // 0x800BE880: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800BE884: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800BE888:
    // 0x800BE888: jal         0x800DF830
    // 0x800BE88C: nop

    func_800DF830(rdram, ctx);
        goto after_3;
    // 0x800BE88C: nop

    after_3:
    // 0x800BE890: lbu         $a0, 0x28($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X28);
    // 0x800BE894: beq         $a0, $zero, L_800BE8A4
    if (ctx->r4 == 0) {
        // 0x800BE898: nop
    
            goto L_800BE8A4;
    }
    // 0x800BE898: nop

    // 0x800BE89C: jal         0x800DF7E8
    // 0x800BE8A0: nop

    func_800DF7E8(rdram, ctx);
        goto after_4;
    // 0x800BE8A0: nop

    after_4:
L_800BE8A4:
    // 0x800BE8A4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BE8A8: addiu       $v0, $v0, -0x7A50
    ctx->r2 = ADD32(ctx->r2, -0X7A50);
    // 0x800BE8AC: lbu         $a0, 0x85($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X85);
    // 0x800BE8B0: lbu         $a1, 0x86($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X86);
    // 0x800BE8B4: lbu         $a2, 0x87($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X87);
    // 0x800BE8B8: jal         0x800DF5D8
    // 0x800BE8BC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800DF5D8(rdram, ctx);
        goto after_5;
    // 0x800BE8BC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_5:
    // 0x800BE8C0: jal         0x800DF7DC
    // 0x800BE8C4: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    func_800DF7DC(rdram, ctx);
        goto after_6;
    // 0x800BE8C4: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    after_6:
    // 0x800BE8C8: lbu         $t2, 0x29($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X29);
    // 0x800BE8CC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800BE8D0: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x800BE8D4: jal         0x800DF818
    // 0x800BE8D8: lw          $a0, 0x10($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X10);
    func_800DF818(rdram, ctx);
        goto after_7;
    // 0x800BE8D8: lw          $a0, 0x10($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X10);
    after_7:
    // 0x800BE8DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800BE8E0: jal         0x800DF428
    // 0x800BE8E4: lwc1        $f12, 0x57B0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X57B0);
    func_800DF428(rdram, ctx);
        goto after_8;
    // 0x800BE8E4: lwc1        $f12, 0x57B0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X57B0);
    after_8:
    // 0x800BE8E8: jal         0x800DF440
    // 0x800BE8EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DF440(rdram, ctx);
        goto after_9;
    // 0x800BE8EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x800BE8F0: jal         0x800DF4B0
    // 0x800BE8F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DF4B0(rdram, ctx);
        goto after_10;
    // 0x800BE8F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_10:
    // 0x800BE8F8: lw          $t5, 0xC($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XC);
    // 0x800BE8FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800BE900: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800BE904: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800BE908: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800BE90C: jal         0x800DE448
    // 0x800BE910: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_800DE448(rdram, ctx);
        goto after_11;
    // 0x800BE910: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_11:
    // 0x800BE914: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x800BE918: beql        $a0, $zero, L_800BE93C
    if (ctx->r4 == 0) {
        // 0x800BE91C: lw          $t9, 0x14($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X14);
            goto L_800BE93C;
    }
    goto skip_3;
    // 0x800BE91C: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    skip_3:
    // 0x800BE920: lbu         $t6, 0x29($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X29);
    // 0x800BE924: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    // 0x800BE928: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800BE92C: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x800BE930: jal         0x800890C8
    // 0x800BE934: lw          $a2, 0x10($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X10);
    _vpmodule_entrypoint_3(rdram, ctx);
        goto after_12;
    // 0x800BE934: lw          $a2, 0x10($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X10);
    after_12:
    // 0x800BE938: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
L_800BE93C:
    // 0x800BE93C: beql        $t9, $zero, L_800BE9A0
    if (ctx->r25 == 0) {
        // 0x800BE940: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800BE9A0;
    }
    goto skip_4;
    // 0x800BE940: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x800BE944: jal         0x800EA340
    // 0x800BE948: nop

    func_800EA340(rdram, ctx);
        goto after_13;
    // 0x800BE948: nop

    after_13:
    // 0x800BE94C: beql        $v0, $zero, L_800BE9A0
    if (ctx->r2 == 0) {
        // 0x800BE950: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800BE9A0;
    }
    goto skip_5;
    // 0x800BE950: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x800BE954: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800BE958: beql        $a0, $zero, L_800BE97C
    if (ctx->r4 == 0) {
        // 0x800BE95C: lbu         $t3, 0x29($s0)
        ctx->r11 = MEM_BU(ctx->r16, 0X29);
            goto L_800BE97C;
    }
    goto skip_6;
    // 0x800BE95C: lbu         $t3, 0x29($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X29);
    skip_6:
    // 0x800BE960: lbu         $t0, 0x29($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X29);
    // 0x800BE964: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800BE968: addu        $t2, $s0, $t1
    ctx->r10 = ADD32(ctx->r16, ctx->r9);
    // 0x800BE96C: jal         0x80088690
    // 0x800BE970: lw          $a1, 0x10($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X10);
    _glid_entrypoint_6(rdram, ctx);
        goto after_14;
    // 0x800BE970: lw          $a1, 0x10($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X10);
    after_14:
    // 0x800BE974: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800BE978: lbu         $t3, 0x29($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X29);
L_800BE97C:
    // 0x800BE97C: xori        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 ^ 0X1;
    // 0x800BE980: beq         $a0, $zero, L_800BE99C
    if (ctx->r4 == 0) {
        // 0x800BE984: sb          $t4, 0x29($s0)
        MEM_B(0X29, ctx->r16) = ctx->r12;
            goto L_800BE99C;
    }
    // 0x800BE984: sb          $t4, 0x29($s0)
    MEM_B(0X29, ctx->r16) = ctx->r12;
    // 0x800BE988: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800BE98C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800BE990: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x800BE994: jal         0x80088688
    // 0x800BE998: lw          $a1, 0x10($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X10);
    _glid_entrypoint_5(rdram, ctx);
        goto after_15;
    // 0x800BE998: lw          $a1, 0x10($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X10);
    after_15:
L_800BE99C:
    // 0x800BE99C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800BE9A0:
    // 0x800BE9A0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800BE9A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800BE9A8: jr          $ra
    // 0x800BE9AC: nop

    return;
    // 0x800BE9AC: nop

;}
RECOMP_FUNC void _chweldarbossfusebox_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086638: syscall     351
    recomp_syscall_handler(rdram, ctx, 0x80086638);
    return;
    // 0x8008663C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void heap_setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A8B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001A8B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001A8BC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001A8C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001A8C4: jal         0x8001E830
    // 0x8001A8C8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    func_8001E830(rdram, ctx);
        goto after_0;
    // 0x8001A8C8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    after_0:
    // 0x8001A8CC: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x8001A8D0: addiu       $v1, $v1, -0x4100
    ctx->r3 = ADD32(ctx->r3, -0X4100);
    // 0x8001A8D4: beq         $s0, $zero, L_8001A8F8
    if (ctx->r16 == 0) {
        // 0x8001A8D8: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_8001A8F8;
    }
    // 0x8001A8D8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8001A8DC: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x8001A8E0: addiu       $s1, $s1, -0x1670
    ctx->r17 = ADD32(ctx->r17, -0X1670);
    // 0x8001A8E4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8001A8E8: jal         0x8002D6E0
    // 0x8001A8EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _bzero(rdram, ctx);
        goto after_1;
    // 0x8001A8EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8001A8F0: jal         0x8002D780
    // 0x8001A8F4: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_2;
    // 0x8001A8F4: nop

    after_2:
L_8001A8F8:
    // 0x8001A8F8: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x8001A8FC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001A900: addiu       $s1, $s1, -0x1670
    ctx->r17 = ADD32(ctx->r17, -0X1670);
    // 0x8001A904: sw          $zero, -0x8B0($at)
    MEM_W(-0X8B0, ctx->r1) = 0;
    // 0x8001A908: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8001A90C: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x8001A910: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8001A914: addiu       $t7, $s0, 0x20
    ctx->r15 = ADD32(ctx->r16, 0X20);
    // 0x8001A918: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x8001A91C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8001A920: lbu         $t8, 0xF($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XF);
    // 0x8001A924: andi        $t9, $t8, 0xFF3F
    ctx->r25 = ctx->r24 & 0XFF3F;
    // 0x8001A928: ori         $t0, $t9, 0x80
    ctx->r8 = ctx->r25 | 0X80;
    // 0x8001A92C: sb          $t0, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r8;
    // 0x8001A930: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8001A934: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x8001A938: srl         $t1, $v0, 8
    ctx->r9 = S32(U32(ctx->r2) >> 8);
    // 0x8001A93C: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x8001A940: xor         $t3, $t2, $v0
    ctx->r11 = ctx->r10 ^ ctx->r2;
    // 0x8001A944: sw          $t3, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r11;
    // 0x8001A948: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8001A94C: sw          $zero, 0x10($t4)
    MEM_W(0X10, ctx->r12) = 0;
    // 0x8001A950: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8001A954: addiu       $t5, $s0, 0x20
    ctx->r13 = ADD32(ctx->r16, 0X20);
    // 0x8001A958: sw          $t5, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r13;
    // 0x8001A95C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8001A960: lbu         $t6, 0xF($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XF);
    // 0x8001A964: andi        $t7, $t6, 0xFFF7
    ctx->r15 = ctx->r14 & 0XFFF7;
    // 0x8001A968: sb          $t7, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r15;
    // 0x8001A96C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8001A970: lbu         $t8, 0xF($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XF);
    // 0x8001A974: andi        $t9, $t8, 0xFFFB
    ctx->r25 = ctx->r24 & 0XFFFB;
    // 0x8001A978: sb          $t9, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r25;
    // 0x8001A97C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8001A980: jal         0x8001B3E8
    // 0x8001A984: sw          $s0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r16;
    heap_bytes_allocated(rdram, ctx);
        goto after_3;
    // 0x8001A984: sw          $s0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r16;
    after_3:
    // 0x8001A988: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8001A98C: addu        $t0, $v0, $s0
    ctx->r8 = ADD32(ctx->r2, ctx->r16);
    // 0x8001A990: addiu       $t1, $t0, -0x20
    ctx->r9 = ADD32(ctx->r8, -0X20);
    // 0x8001A994: sw          $t1, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r9;
    // 0x8001A998: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8001A99C: lbu         $t2, 0x2F($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X2F);
    // 0x8001A9A0: andi        $t3, $t2, 0xFF3F
    ctx->r11 = ctx->r10 & 0XFF3F;
    // 0x8001A9A4: sb          $t3, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r11;
    // 0x8001A9A8: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8001A9AC: lw          $v1, 0x2C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X2C);
    // 0x8001A9B0: srl         $t4, $v1, 8
    ctx->r12 = S32(U32(ctx->r3) >> 8);
    // 0x8001A9B4: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x8001A9B8: xor         $t6, $t5, $v1
    ctx->r14 = ctx->r13 ^ ctx->r3;
    // 0x8001A9BC: sw          $t6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r14;
    // 0x8001A9C0: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8001A9C4: jal         0x8001B3E8
    // 0x8001A9C8: sw          $s0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r16;
    heap_bytes_allocated(rdram, ctx);
        goto after_4;
    // 0x8001A9C8: sw          $s0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r16;
    after_4:
    // 0x8001A9CC: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8001A9D0: addu        $t7, $v0, $s0
    ctx->r15 = ADD32(ctx->r2, ctx->r16);
    // 0x8001A9D4: addiu       $t8, $t7, -0x20
    ctx->r24 = ADD32(ctx->r15, -0X20);
    // 0x8001A9D8: sw          $t8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r24;
    // 0x8001A9DC: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8001A9E0: lbu         $t9, 0x2F($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X2F);
    // 0x8001A9E4: andi        $t0, $t9, 0xFFF7
    ctx->r8 = ctx->r25 & 0XFFF7;
    // 0x8001A9E8: sb          $t0, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r8;
    // 0x8001A9EC: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8001A9F0: lbu         $t1, 0x2F($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X2F);
    // 0x8001A9F4: andi        $t2, $t1, 0xFFFB
    ctx->r10 = ctx->r9 & 0XFFFB;
    // 0x8001A9F8: jal         0x8001B3E8
    // 0x8001A9FC: sb          $t2, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r10;
    heap_bytes_allocated(rdram, ctx);
        goto after_5;
    // 0x8001A9FC: sb          $t2, 0x2F($s0)
    MEM_B(0X2F, ctx->r16) = ctx->r10;
    after_5:
    // 0x8001AA00: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8001AA04: addiu       $t3, $s0, 0x20
    ctx->r11 = ADD32(ctx->r16, 0X20);
    // 0x8001AA08: addu        $t4, $s0, $v0
    ctx->r12 = ADD32(ctx->r16, ctx->r2);
    // 0x8001AA0C: jal         0x8001B3E8
    // 0x8001AA10: sw          $t3, -0x20($t4)
    MEM_W(-0X20, ctx->r12) = ctx->r11;
    heap_bytes_allocated(rdram, ctx);
        goto after_6;
    // 0x8001AA10: sw          $t3, -0x20($t4)
    MEM_W(-0X20, ctx->r12) = ctx->r11;
    after_6:
    // 0x8001AA14: jal         0x8001B3E8
    // 0x8001AA18: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    heap_bytes_allocated(rdram, ctx);
        goto after_7;
    // 0x8001AA18: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_7:
    // 0x8001AA1C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8001AA20: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8001AA24: addu        $t5, $v0, $s0
    ctx->r13 = ADD32(ctx->r2, ctx->r16);
    // 0x8001AA28: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x8001AA2C: jal         0x8001B3E8
    // 0x8001AA30: sw          $t5, -0x1C($t7)
    MEM_W(-0X1C, ctx->r15) = ctx->r13;
    heap_bytes_allocated(rdram, ctx);
        goto after_8;
    // 0x8001AA30: sw          $t5, -0x1C($t7)
    MEM_W(-0X1C, ctx->r15) = ctx->r13;
    after_8:
    // 0x8001AA34: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8001AA38: addu        $s0, $t8, $v0
    ctx->r16 = ADD32(ctx->r24, ctx->r2);
    // 0x8001AA3C: lbu         $t9, -0x11($s0)
    ctx->r25 = MEM_BU(ctx->r16, -0X11);
    // 0x8001AA40: andi        $t0, $t9, 0xFF3F
    ctx->r8 = ctx->r25 & 0XFF3F;
    // 0x8001AA44: ori         $t1, $t0, 0x80
    ctx->r9 = ctx->r8 | 0X80;
    // 0x8001AA48: jal         0x8001B3E8
    // 0x8001AA4C: sb          $t1, -0x11($s0)
    MEM_B(-0X11, ctx->r16) = ctx->r9;
    heap_bytes_allocated(rdram, ctx);
        goto after_9;
    // 0x8001AA4C: sb          $t1, -0x11($s0)
    MEM_B(-0X11, ctx->r16) = ctx->r9;
    after_9:
    // 0x8001AA50: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x8001AA54: addu        $s0, $t2, $v0
    ctx->r16 = ADD32(ctx->r10, ctx->r2);
    // 0x8001AA58: lw          $v1, -0x14($s0)
    ctx->r3 = MEM_W(ctx->r16, -0X14);
    // 0x8001AA5C: srl         $t3, $v1, 8
    ctx->r11 = S32(U32(ctx->r3) >> 8);
    // 0x8001AA60: sll         $t4, $t3, 8
    ctx->r12 = S32(ctx->r11 << 8);
    // 0x8001AA64: xor         $t6, $t4, $v1
    ctx->r14 = ctx->r12 ^ ctx->r3;
    // 0x8001AA68: jal         0x8001B3E8
    // 0x8001AA6C: sw          $t6, -0x14($s0)
    MEM_W(-0X14, ctx->r16) = ctx->r14;
    heap_bytes_allocated(rdram, ctx);
        goto after_10;
    // 0x8001AA6C: sw          $t6, -0x14($s0)
    MEM_W(-0X14, ctx->r16) = ctx->r14;
    after_10:
    // 0x8001AA70: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8001AA74: addiu       $t5, $s0, 0x20
    ctx->r13 = ADD32(ctx->r16, 0X20);
    // 0x8001AA78: addu        $t7, $s0, $v0
    ctx->r15 = ADD32(ctx->r16, ctx->r2);
    // 0x8001AA7C: jal         0x8001B3E8
    // 0x8001AA80: sw          $t5, -0x10($t7)
    MEM_W(-0X10, ctx->r15) = ctx->r13;
    heap_bytes_allocated(rdram, ctx);
        goto after_11;
    // 0x8001AA80: sw          $t5, -0x10($t7)
    MEM_W(-0X10, ctx->r15) = ctx->r13;
    after_11:
    // 0x8001AA84: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8001AA88: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8001AA8C: jal         0x8001B3E8
    // 0x8001AA90: sw          $zero, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = 0;
    heap_bytes_allocated(rdram, ctx);
        goto after_12;
    // 0x8001AA90: sw          $zero, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = 0;
    after_12:
    // 0x8001AA94: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x8001AA98: addu        $s0, $t0, $v0
    ctx->r16 = ADD32(ctx->r8, ctx->r2);
    // 0x8001AA9C: lbu         $t1, -0x11($s0)
    ctx->r9 = MEM_BU(ctx->r16, -0X11);
    // 0x8001AAA0: andi        $t2, $t1, 0xFFF7
    ctx->r10 = ctx->r9 & 0XFFF7;
    // 0x8001AAA4: jal         0x8001B3E8
    // 0x8001AAA8: sb          $t2, -0x11($s0)
    MEM_B(-0X11, ctx->r16) = ctx->r10;
    heap_bytes_allocated(rdram, ctx);
        goto after_13;
    // 0x8001AAA8: sb          $t2, -0x11($s0)
    MEM_B(-0X11, ctx->r16) = ctx->r10;
    after_13:
    // 0x8001AAAC: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x8001AAB0: addu        $s0, $t3, $v0
    ctx->r16 = ADD32(ctx->r11, ctx->r2);
    // 0x8001AAB4: lbu         $t4, -0x11($s0)
    ctx->r12 = MEM_BU(ctx->r16, -0X11);
    // 0x8001AAB8: andi        $t6, $t4, 0xFFFB
    ctx->r14 = ctx->r12 & 0XFFFB;
    // 0x8001AABC: jal         0x8001B4B0
    // 0x8001AAC0: sb          $t6, -0x11($s0)
    MEM_B(-0X11, ctx->r16) = ctx->r14;
    func_8001B4B0(rdram, ctx);
        goto after_14;
    // 0x8001AAC0: sb          $t6, -0x11($s0)
    MEM_B(-0X11, ctx->r16) = ctx->r14;
    after_14:
    // 0x8001AAC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AAC8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001AACC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8001AAD0: jr          $ra
    // 0x8001AAD4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8001AAD4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void bawandglow_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080008C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800090: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800094: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800098: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080009C: lw          $a1, 0x148($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X148);
    // 0x808000A0: lw          $a2, 0xC($a1)
    ctx->r6 = MEM_W(ctx->r5, 0XC);
    // 0x808000A4: beql        $a2, $zero, L_808000C0
    if (ctx->r6 == 0) {
        // 0x808000A8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808000C0;
    }
    goto skip_0;
    // 0x808000A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x808000AC: jal         0x8008F880
    // 0x808000B0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_8008F880(rdram, ctx);
        goto after_0;
    // 0x808000B0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x808000B4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x808000B8: lw          $a1, 0x148($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X148);
    // 0x808000BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_808000C0:
    // 0x808000C0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x808000C4: jal         0x8008EEC4
    // 0x808000C8: addiu       $a3, $zero, 0x27D
    ctx->r7 = ADD32(0, 0X27D);
    func_8008EEC4(rdram, ctx);
        goto after_1;
    // 0x808000C8: addiu       $a3, $zero, 0x27D
    ctx->r7 = ADD32(0, 0X27D);
    after_1:
    // 0x808000CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000D4: jr          $ra
    // 0x808000D8: nop

    return;
    // 0x808000D8: nop

;}
RECOMP_FUNC void chjinjo_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800BE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800BEC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800BF0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800BF4: addiu       $a1, $zero, 0x84
    ctx->r5 = ADD32(0, 0X84);
    // 0x80800BF8: jal         0x800887D8
    // 0x80800BFC: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x80800BFC: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    after_0:
    // 0x80800C00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C08: jr          $ra
    // 0x80800C0C: nop

    return;
    // 0x80800C0C: nop

;}
RECOMP_FUNC void func_8008DC90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DC90: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8008DC94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008DC98: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8008DC9C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8008DCA0: jal         0x8009C128
    // 0x8008DCA4: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x8008DCA4: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x8008DCA8: jal         0x8008FF40
    // 0x8008DCAC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_8008FF40(rdram, ctx);
        goto after_1;
    // 0x8008DCAC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_1:
    // 0x8008DCB0: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8008DCB4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8008DCB8: jal         0x800F18FC
    // 0x8008DCBC: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    func_800F18FC(rdram, ctx);
        goto after_2;
    // 0x8008DCBC: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_2:
    // 0x8008DCC0: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8008DCC4: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8008DCC8: jal         0x800F20BC
    // 0x8008DCCC: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    func_800F20BC(rdram, ctx);
        goto after_3;
    // 0x8008DCCC: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_3:
    // 0x8008DCD0: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008DCD4: beq         $t6, $zero, L_8008DCF4
    if (ctx->r14 == 0) {
        // 0x8008DCD8: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8008DCF4;
    }
    // 0x8008DCD8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8008DCDC: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8008DCE0: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8008DCE4: jal         0x800F20BC
    // 0x8008DCE8: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    func_800F20BC(rdram, ctx);
        goto after_4;
    // 0x8008DCE8: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_4:
    // 0x8008DCEC: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008DCF0: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8008DCF4:
    // 0x8008DCF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008DCF8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8008DCFC: jr          $ra
    // 0x8008DD00: nop

    return;
    // 0x8008DD00: nop

;}
RECOMP_FUNC void func_8080066C_chballoonburst(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080066C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800670: addiu       $at, $zero, 0x10BE
    ctx->r1 = ADD32(0, 0X10BE);
    // 0x80800674: beq         $a1, $at, L_808006A0
    if (ctx->r5 == ctx->r1) {
        // 0x80800678: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_808006A0;
    }
    // 0x80800678: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080067C: addiu       $at, $zero, 0x10C0
    ctx->r1 = ADD32(0, 0X10C0);
    // 0x80800680: beq         $a1, $at, L_808006BC
    if (ctx->r5 == ctx->r1) {
        // 0x80800684: addiu       $at, $zero, 0x10F9
        ctx->r1 = ADD32(0, 0X10F9);
            goto L_808006BC;
    }
    // 0x80800684: addiu       $at, $zero, 0x10F9
    ctx->r1 = ADD32(0, 0X10F9);
    // 0x80800688: beq         $a1, $at, L_808006BC
    if (ctx->r5 == ctx->r1) {
        // 0x8080068C: addiu       $at, $zero, 0x1118
        ctx->r1 = ADD32(0, 0X1118);
            goto L_808006BC;
    }
    // 0x8080068C: addiu       $at, $zero, 0x1118
    ctx->r1 = ADD32(0, 0X1118);
    // 0x80800690: beq         $a1, $at, L_808006CC
    if (ctx->r5 == ctx->r1) {
        // 0x80800694: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808006CC;
    }
    // 0x80800694: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800698: b           L_808006F4
    // 0x8080069C: nop

        goto L_808006F4;
    // 0x8080069C: nop

L_808006A0:
    // 0x808006A0: bne         $a2, $zero, L_808006B4
    if (ctx->r6 != 0) {
        // 0x808006A4: addiu       $v1, $zero, 0x32
        ctx->r3 = ADD32(0, 0X32);
            goto L_808006B4;
    }
    // 0x808006A4: addiu       $v1, $zero, 0x32
    ctx->r3 = ADD32(0, 0X32);
    // 0x808006A8: lhu         $v1, 0x76($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X76);
    // 0x808006AC: b           L_808006F4
    // 0x808006B0: srl         $v0, $v1, 7
    ctx->r2 = S32(U32(ctx->r3) >> 7);
        goto L_808006F4;
    // 0x808006B0: srl         $v0, $v1, 7
    ctx->r2 = S32(U32(ctx->r3) >> 7);
L_808006B4:
    // 0x808006B4: b           L_808006F4
    // 0x808006B8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_808006F4;
    // 0x808006B8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_808006BC:
    // 0x808006BC: jal         0x800D211C
    // 0x808006C0: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    func_800D211C(rdram, ctx);
        goto after_0;
    // 0x808006C0: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    after_0:
    // 0x808006C4: b           L_808006F8
    // 0x808006C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808006F8;
    // 0x808006C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808006CC:
    // 0x808006CC: bne         $a2, $zero, L_808006E0
    if (ctx->r6 != 0) {
        // 0x808006D0: nop
    
            goto L_808006E0;
    }
    // 0x808006D0: nop

    // 0x808006D4: lhu         $v1, 0x76($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X76);
    // 0x808006D8: b           L_808006F4
    // 0x808006DC: srl         $v0, $v1, 7
    ctx->r2 = S32(U32(ctx->r3) >> 7);
        goto L_808006F4;
    // 0x808006DC: srl         $v0, $v1, 7
    ctx->r2 = S32(U32(ctx->r3) >> 7);
L_808006E0:
    // 0x808006E0: jal         0x800D211C
    // 0x808006E4: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    func_800D211C(rdram, ctx);
        goto after_1;
    // 0x808006E4: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    after_1:
    // 0x808006E8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808006EC: b           L_808006F4
    // 0x808006F0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_808006F4;
    // 0x808006F0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_808006F4:
    // 0x808006F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808006F8:
    // 0x808006F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808006FC: jr          $ra
    // 0x80800700: nop

    return;
    // 0x80800700: nop

;}
RECOMP_FUNC void func_808093A4_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808093A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808093A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808093AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808093B0: lw          $t6, 0x188($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X188);
    // 0x808093B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808093B8: jal         0x80807D48
    // 0x808093BC: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_80807D48_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x808093BC: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x808093C0: jal         0x80808E78
    // 0x808093C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80808E78_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x808093C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808093C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808093CC: jal         0x8080633C
    // 0x808093D0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8080633C_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x808093D0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_2:
    // 0x808093D4: jal         0x808094A4
    // 0x808093D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808094A4_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x808093D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808093DC: bne         $v0, $zero, L_80809464
    if (ctx->r2 != 0) {
        // 0x808093E0: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_80809464;
    }
    // 0x808093E0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x808093E4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x808093E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808093EC: jal         0x80809540
    // 0x808093F0: lbu         $a1, 0x218($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X218);
    func_80809540_bsfirstp(rdram, ctx);
        goto after_4;
    // 0x808093F0: lbu         $a1, 0x218($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X218);
    after_4:
    // 0x808093F4: beq         $v0, $zero, L_8080941C
    if (ctx->r2 == 0) {
        // 0x808093F8: addiu       $t8, $zero, 0xCA
        ctx->r24 = ADD32(0, 0XCA);
            goto L_8080941C;
    }
    // 0x808093F8: addiu       $t8, $zero, 0xCA
    ctx->r24 = ADD32(0, 0XCA);
    // 0x808093FC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80809400: beq         $v0, $v1, L_80809424
    if (ctx->r2 == ctx->r3) {
        // 0x80809404: lw          $t9, 0x24($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X24);
            goto L_80809424;
    }
    // 0x80809404: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80809408: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8080940C: beq         $v0, $v1, L_80809444
    if (ctx->r2 == ctx->r3) {
        // 0x80809410: lw          $t1, 0x24($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X24);
            goto L_80809444;
    }
    // 0x80809410: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80809414: b           L_8080945C
    // 0x80809418: nop

        goto L_8080945C;
    // 0x80809418: nop

L_8080941C:
    // 0x8080941C: b           L_8080945C
    // 0x80809420: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
        goto L_8080945C;
    // 0x80809420: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
L_80809424:
    // 0x80809424: lbu         $t0, 0x218($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X218);
    // 0x80809428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080942C: beq         $v1, $t0, L_8080945C
    if (ctx->r3 == ctx->r8) {
        // 0x80809430: nop
    
            goto L_8080945C;
    }
    // 0x80809430: nop

    // 0x80809434: jal         0x80809684
    // 0x80809438: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80809684_bsfirstp(rdram, ctx);
        goto after_5;
    // 0x80809438: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x8080943C: b           L_8080945C
    // 0x80809440: nop

        goto L_8080945C;
    // 0x80809440: nop

L_80809444:
    // 0x80809444: lbu         $t2, 0x218($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X218);
    // 0x80809448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080944C: beq         $v1, $t2, L_8080945C
    if (ctx->r3 == ctx->r10) {
        // 0x80809450: nop
    
            goto L_8080945C;
    }
    // 0x80809450: nop

    // 0x80809454: jal         0x80809684
    // 0x80809458: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80809684_bsfirstp(rdram, ctx);
        goto after_6;
    // 0x80809458: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
L_8080945C:
    // 0x8080945C: jal         0x80809740
    // 0x80809460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80809740_bsfirstp(rdram, ctx);
        goto after_7;
    // 0x80809460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
L_80809464:
    // 0x80809464: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80809468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080946C: beql        $t3, $zero, L_80809480
    if (ctx->r11 == 0) {
        // 0x80809470: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80809480;
    }
    goto skip_0;
    // 0x80809470: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80809474: jal         0x8009E5C8
    // 0x80809478: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    bs_setState(rdram, ctx);
        goto after_8;
    // 0x80809478: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_8:
    // 0x8080947C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80809480:
    // 0x80809480: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80809484: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80809488: jr          $ra
    // 0x8080948C: nop

    return;
    // 0x8080948C: nop

;}
RECOMP_FUNC void func_800A7A6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7A6C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A7A70: addiu       $v0, $v0, 0x7630
    ctx->r2 = ADD32(ctx->r2, 0X7630);
    // 0x800A7A74: lbu         $t6, 0x18($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X18);
    // 0x800A7A78: sb          $zero, 0x16($v0)
    MEM_B(0X16, ctx->r2) = 0;
    // 0x800A7A7C: sh          $a0, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r4;
    // 0x800A7A80: sb          $a1, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r5;
    // 0x800A7A84: sb          $zero, 0x18($v0)
    MEM_B(0X18, ctx->r2) = 0;
    // 0x800A7A88: jr          $ra
    // 0x800A7A8C: sb          $t6, 0x15($v0)
    MEM_B(0X15, ctx->r2) = ctx->r14;
    return;
    // 0x800A7A8C: sb          $t6, 0x15($v0)
    MEM_B(0X15, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_80094430(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094430: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80094434: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80094438: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8009443C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80094440: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80094444: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80094448: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8009444C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80094450: bc1t        L_80094468
    if (c1cs) {
        // 0x80094454: nop
    
            goto L_80094468;
    }
    // 0x80094454: nop

    // 0x80094458: jal         0x800946C4
    // 0x8009445C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800946C4(rdram, ctx);
        goto after_0;
    // 0x8009445C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80094460: b           L_80094474
    // 0x80094464: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
        goto L_80094474;
    // 0x80094464: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_80094468:
    // 0x80094468: jal         0x80094370
    // 0x8009446C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80094370(rdram, ctx);
        goto after_1;
    // 0x8009446C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80094470: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_80094474:
    // 0x80094474: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80094478: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8009447C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80094480: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80094484: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80094488: bc1f        L_800944B4
    if (!c1cs) {
        // 0x8009448C: nop
    
            goto L_800944B4;
    }
    // 0x8009448C: nop

    // 0x80094490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80094494: jal         0x800947EC
    // 0x80094498: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_800947EC(rdram, ctx);
        goto after_2;
    // 0x80094498: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x8009449C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800944A0: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x800944A4: jal         0x80085338
    // 0x800944A8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    _batimer_set(rdram, ctx);
        goto after_3;
    // 0x800944A8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x800944AC: b           L_800944D0
    // 0x800944B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800944D0;
    // 0x800944B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800944B4:
    // 0x800944B4: jal         0x800947EC
    // 0x800944B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800947EC(rdram, ctx);
        goto after_4;
    // 0x800944B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x800944BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800944C0: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x800944C4: jal         0x80085338
    // 0x800944C8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    _batimer_set(rdram, ctx);
        goto after_5;
    // 0x800944C8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_5:
    // 0x800944CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800944D0:
    // 0x800944D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800944D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800944D8: jr          $ra
    // 0x800944DC: nop

    return;
    // 0x800944DC: nop

;}
RECOMP_FUNC void func_800BFC74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BFC74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BFC78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BFC7C: jal         0x800D62E4
    // 0x800BFC80: nop

    func_800D62E4(rdram, ctx);
        goto after_0;
    // 0x800BFC80: nop

    after_0:
    // 0x800BFC84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BFC88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BFC8C: jr          $ra
    // 0x800BFC90: nop

    return;
    // 0x800BFC90: nop

;}
RECOMP_FUNC void func_80801D30_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801D30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801D34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801D38: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x80801D3C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80801D40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801D44: sw          $t6, 0xA8($v0)
    MEM_W(0XA8, ctx->r2) = ctx->r14;
    // 0x80801D48: sw          $zero, 0xB0($v0)
    MEM_W(0XB0, ctx->r2) = 0;
    // 0x80801D4C: jal         0x80084AE8
    // 0x80801D50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _baeggcursor_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x80801D50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801D54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801D58: jal         0x80802438
    // 0x80801D5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80802438_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80801D5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80801D60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801D64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801D68: jr          $ra
    // 0x80801D6C: nop

    return;
    // 0x80801D6C: nop

;}
RECOMP_FUNC void func_800BF704(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF704: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BF708: jr          $ra
    // 0x800BF70C: addiu       $v0, $v0, -0x7A50
    ctx->r2 = ADD32(ctx->r2, -0X7A50);
    return;
    // 0x800BF70C: addiu       $v0, $v0, -0x7A50
    ctx->r2 = ADD32(ctx->r2, -0X7A50);
;}
RECOMP_FUNC void func_8008C0AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C0AC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8008C0B0: jr          $ra
    // 0x8008C0B4: sb          $t6, 0x1B($a0)
    MEM_B(0X1B, ctx->r4) = ctx->r14;
    return;
    // 0x8008C0B4: sb          $t6, 0x1B($a0)
    MEM_B(0X1B, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void bashoes_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002BC: jal         0x80800384
    // 0x808002C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bashoes_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x808002C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808002C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002CC: jr          $ra
    // 0x808002D0: nop

    return;
    // 0x808002D0: nop

;}
RECOMP_FUNC void func_80800000_chdinofamilysmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: jal         0x80088848
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800014: beq         $v0, $zero, L_8080002C
    if (ctx->r2 == 0) {
        // 0x80800018: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080002C;
    }
    // 0x80800018: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080001C: jal         0x808008B4
    // 0x80800020: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_808008B4_chdinofamilysmall(rdram, ctx);
        goto after_1;
    // 0x80800020: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_1:
    // 0x80800024: b           L_8080005C
    // 0x80800028: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
        goto L_8080005C;
    // 0x80800028: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8080002C:
    // 0x8080002C: jal         0x800DA298
    // 0x80800030: addiu       $a0, $zero, 0x15F
    ctx->r4 = ADD32(0, 0X15F);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800030: addiu       $a0, $zero, 0x15F
    ctx->r4 = ADD32(0, 0X15F);
    after_2:
    // 0x80800034: bne         $v0, $zero, L_80800050
    if (ctx->r2 != 0) {
        // 0x80800038: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800050;
    }
    // 0x80800038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080003C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800040: jal         0x808008B4
    // 0x80800044: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808008B4_chdinofamilysmall(rdram, ctx);
        goto after_3;
    // 0x80800044: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800048: b           L_8080005C
    // 0x8080004C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
        goto L_8080005C;
    // 0x8080004C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80800050:
    // 0x80800050: jal         0x808008B4
    // 0x80800054: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_808008B4_chdinofamilysmall(rdram, ctx);
        goto after_4;
    // 0x80800054: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_4:
    // 0x80800058: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8080005C:
    // 0x8080005C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800060: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800064: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x80800068: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080006C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800070: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800074: jal         0x800EFA4C
    // 0x80800078: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    func_800EFA4C(rdram, ctx);
        goto after_5;
    // 0x80800078: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    after_5:
    // 0x8080007C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800080: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800084: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800088: jr          $ra
    // 0x8080008C: nop

    return;
    // 0x8080008C: nop

;}
RECOMP_FUNC void func_800E2DF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E2DF0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E2DF4: addiu       $v0, $v0, -0x2B90
    ctx->r2 = ADD32(ctx->r2, -0X2B90);
    // 0x800E2DF8: lbu         $t6, 0x23($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X23);
    // 0x800E2DFC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E2E00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E2E04: beq         $t6, $zero, L_800E2E34
    if (ctx->r14 == 0) {
        // 0x800E2E08: lwc1        $f2, 0x2C($v0)
        ctx->f2.u32l = MEM_W(ctx->r2, 0X2C);
            goto L_800E2E34;
    }
    // 0x800E2E08: lwc1        $f2, 0x2C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x800E2E0C: jal         0x800A89F8
    // 0x800E2E10: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    func_800A89F8(rdram, ctx);
        goto after_0;
    // 0x800E2E10: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x800E2E14: jal         0x800A8AF0
    // 0x800E2E18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800A8AF0(rdram, ctx);
        goto after_1;
    // 0x800E2E18: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800E2E1C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800E2E20: lwc1        $f4, 0x5D98($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5D98);
    // 0x800E2E24: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800E2E28: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800E2E2C: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800E2E30: nop

L_800E2E34:
    // 0x800E2E34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E2E38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800E2E3C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x800E2E40: jr          $ra
    // 0x800E2E44: nop

    return;
    // 0x800E2E44: nop

;}
RECOMP_FUNC void func_80800018_chmermaidstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080001C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800020: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800024: jal         0x80089F48
    // 0x80800028: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _subaddiesect_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800028: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080002C: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x80800030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800034: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800038: jal         0x80089F50
    // 0x8080003C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _subaddiesect_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x8080003C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80800040: addiu       $a0, $zero, 0x6B1
    ctx->r4 = ADD32(0, 0X6B1);
    // 0x80800044: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800048: jal         0x800DA7A8
    // 0x8080004C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800DA7A8(rdram, ctx);
        goto after_2;
    // 0x8080004C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_2:
    // 0x80800050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800054: jal         0x80109EEC
    // 0x80800058: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_80109EEC(rdram, ctx);
        goto after_3;
    // 0x80800058: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_3:
    // 0x8080005C: jal         0x800DA298
    // 0x80800060: addiu       $a0, $zero, 0x18D
    ctx->r4 = ADD32(0, 0X18D);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80800060: addiu       $a0, $zero, 0x18D
    ctx->r4 = ADD32(0, 0X18D);
    after_4:
    // 0x80800064: beql        $v0, $zero, L_80800084
    if (ctx->r2 == 0) {
        // 0x80800068: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800084;
    }
    goto skip_0;
    // 0x80800068: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080006C: jal         0x8010A570
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_5;
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800078: jal         0x80101FDC
    // 0x8080007C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_6;
    // 0x8080007C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x80800080: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800084:
    // 0x80800084: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800088: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080008C: jr          $ra
    // 0x80800090: nop

    return;
    // 0x80800090: nop

;}
RECOMP_FUNC void func_80800590_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800590: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800594: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800598: jal         0x80085230
    // 0x8080059C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _basudie_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x8080059C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808005A0: jal         0x808000F0
    // 0x808005A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808000F0_bswasher(rdram, ctx);
        goto after_1;
    // 0x808005A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808005A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808005B0: jr          $ra
    // 0x808005B4: nop

    return;
    // 0x808005B4: nop

;}
RECOMP_FUNC void func_808030EC_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808030EC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808030F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808030F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808030F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808030FC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80803100: beq         $a3, $zero, L_80803124
    if (ctx->r7 == 0) {
        // 0x80803104: sw          $a2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r6;
            goto L_80803124;
    }
    // 0x80803104: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80803108: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080310C: beq         $a3, $at, L_80803198
    if (ctx->r7 == ctx->r1) {
        // 0x80803110: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80803198;
    }
    // 0x80803110: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80803114: beq         $a3, $at, L_80803138
    if (ctx->r7 == ctx->r1) {
        // 0x80803118: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_80803138;
    }
    // 0x80803118: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8080311C: b           L_808031E4
    // 0x80803120: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808031E4;
    // 0x80803120: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803124:
    // 0x80803124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803128: jal         0x80803048
    // 0x8080312C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80803048_chgameselect(rdram, ctx);
        goto after_0;
    // 0x8080312C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_0:
    // 0x80803130: b           L_808031E4
    // 0x80803134: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808031E4;
    // 0x80803134: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803138:
    // 0x80803138: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8080313C: jal         0x80087D30
    // 0x80803140: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    _gcnewoption_entrypoint_19(rdram, ctx);
        goto after_1;
    // 0x80803140: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_1:
    // 0x80803144: beq         $v0, $zero, L_80803198
    if (ctx->r2 == 0) {
        // 0x80803148: lw          $a3, 0x3C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X3C);
            goto L_80803198;
    }
    // 0x80803148: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8080314C: jal         0x80803C60
    // 0x80803150: nop

    func_80803C60_chgameselect(rdram, ctx);
        goto after_2;
    // 0x80803150: nop

    after_2:
    // 0x80803154: jal         0x80106790
    // 0x80803158: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_3;
    // 0x80803158: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_3:
    // 0x8080315C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80803160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803164: jal         0x80100094
    // 0x80803168: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x80803168: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x8080316C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80803170: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80803174: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80803178: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8080317C: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80803180: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80803184: lb          $a1, 0x2($t9)
    ctx->r5 = MEM_B(ctx->r25, 0X2);
    // 0x80803188: jal         0x808026C8
    // 0x8080318C: lw          $a0, 0x2C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X2C);
    func_808026C8_chgameselect(rdram, ctx);
        goto after_5;
    // 0x8080318C: lw          $a0, 0x2C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X2C);
    after_5:
    // 0x80803190: b           L_808031E4
    // 0x80803194: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808031E4;
    // 0x80803194: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803198:
    // 0x80803198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080319C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808031A0: jal         0x80100094
    // 0x808031A4: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    func_80100094(rdram, ctx);
        goto after_6;
    // 0x808031A4: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_6:
    // 0x808031A8: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x808031AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808031B0: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x808031B4: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x808031B8: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x808031BC: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x808031C0: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x808031C4: jal         0x80802FE4
    // 0x808031C8: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    func_80802FE4_chgameselect(rdram, ctx);
        goto after_7;
    // 0x808031C8: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    after_7:
    // 0x808031CC: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x808031D0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x808031D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808031D8: jal         0x80800AEC
    // 0x808031DC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_80800AEC_chgameselect(rdram, ctx);
        goto after_8;
    // 0x808031DC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_8:
    // 0x808031E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808031E4:
    // 0x808031E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808031E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808031EC: jr          $ra
    // 0x808031F0: nop

    return;
    // 0x808031F0: nop

;}
RECOMP_FUNC void _gczoomboxdata_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088428: syscall     682
    recomp_syscall_handler(rdram, ctx, 0x80088428);
    return;
    // 0x8008842C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void idglowa_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800168: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080016C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800170: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800174: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800178: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080017C: jal         0x800D8FF8
    // 0x80800180: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800180: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800184: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80800188: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080018C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x80800190: bnel        $t6, $at, L_80800210
    if (ctx->r14 != ctx->r1) {
        // 0x80800194: lw          $t7, 0x0($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X0);
            goto L_80800210;
    }
    goto skip_0;
    // 0x80800194: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x80800198: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8080019C: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x808001A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808001A4: mul.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x808001A8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808001AC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808001B0: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x808001B4: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x808001B8: c.le.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl <= ctx->f12.fl;
    // 0x808001BC: nop

    // 0x808001C0: bc1fl       L_808001DC
    if (!c1cs) {
        // 0x808001C4: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_808001DC;
    }
    goto skip_1;
    // 0x808001C4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_1:
    // 0x808001C8: neg.s       $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = -ctx->f2.fl;
    // 0x808001CC: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x808001D0: b           L_8080020C
    // 0x808001D4: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
        goto L_8080020C;
    // 0x808001D4: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x808001D8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_808001DC:
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808001E4: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x808001E8: nop

    // 0x808001EC: bc1fl       L_80800210
    if (!c1cs) {
        // 0x808001F0: lw          $t7, 0x0($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X0);
            goto L_80800210;
    }
    goto skip_2;
    // 0x808001F0: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x808001F4: neg.s       $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = -ctx->f2.fl;
    // 0x808001F8: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x808001FC: jal         0x808000E8
    // 0x80800200: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    func_808000E8_idglowa(rdram, ctx);
        goto after_1;
    // 0x80800200: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    after_1:
    // 0x80800204: b           L_80800254
    // 0x80800208: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800254;
    // 0x80800208: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080020C:
    // 0x8080020C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
L_80800210:
    // 0x80800210: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800214: bne         $t7, $at, L_80800238
    if (ctx->r15 != ctx->r1) {
        // 0x80800218: nop
    
            goto L_80800238;
    }
    // 0x80800218: nop

    // 0x8080021C: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x80800220: jal         0x800F1574
    // 0x80800224: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    func_800F1574(rdram, ctx);
        goto after_2;
    // 0x80800224: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    after_2:
    // 0x80800228: beq         $v0, $zero, L_80800238
    if (ctx->r2 == 0) {
        // 0x8080022C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800238;
    }
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800230: jal         0x808000E8
    // 0x80800234: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808000E8_idglowa(rdram, ctx);
        goto after_3;
    // 0x80800234: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
L_80800238:
    // 0x80800238: lui         $a2, 0x8009
    ctx->r6 = S32(0X8009 << 16);
    // 0x8080023C: addiu       $a2, $a2, -0x7280
    ctx->r6 = ADD32(ctx->r6, -0X7280);
    // 0x80800240: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800244: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800248: jal         0x80088660
    // 0x8080024C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    _glid_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x8080024C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_4:
    // 0x80800250: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800254:
    // 0x80800254: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800258: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080025C: jr          $ra
    // 0x80800260: nop

    return;
    // 0x80800260: nop

    // 0x80800264: nop

    // 0x80800268: nop

    // 0x8080026C: nop

;}
RECOMP_FUNC void func_80801EE8_chtrashcangame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801EE8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801EEC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80801EF0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801EF4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80801EF8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80801EFC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80801F00: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801F04: beq         $a1, $at, L_80801F2C
    if (ctx->r5 == ctx->r1) {
        // 0x80801F08: sw          $a1, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r5;
            goto L_80801F2C;
    }
    // 0x80801F08: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80801F0C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801F10: beq         $a1, $at, L_80801F58
    if (ctx->r5 == ctx->r1) {
        // 0x80801F14: addiu       $t8, $zero, 0xA
        ctx->r24 = ADD32(0, 0XA);
            goto L_80801F58;
    }
    // 0x80801F14: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80801F18: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801F1C: beq         $a1, $at, L_80801FDC
    if (ctx->r5 == ctx->r1) {
        // 0x80801F20: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80801FDC;
    }
    // 0x80801F20: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80801F24: b           L_808020B8
    // 0x80801F28: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_808020B8;
    // 0x80801F28: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80801F2C:
    // 0x80801F2C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80801F30: addiu       $t7, $zero, 0x6A
    ctx->r15 = ADD32(0, 0X6A);
    // 0x80801F34: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80801F38: addiu       $a1, $zero, 0x13ED
    ctx->r5 = ADD32(0, 0X13ED);
    // 0x80801F3C: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x80801F40: jal         0x8008A208
    // 0x80801F44: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x80801F44: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80801F48: jal         0x80800000
    // 0x80801F4C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800000_chtrashcangame(rdram, ctx);
        goto after_1;
    // 0x80801F4C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80801F50: b           L_808020B8
    // 0x80801F54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_808020B8;
    // 0x80801F54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80801F58:
    // 0x80801F58: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2F9C) << 16);
    // 0x80801F5C: lwc1        $f4, 0x2F9C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2F9C));
    // 0x80801F60: sw          $zero, 0x50($s1)
    MEM_W(0X50, ctx->r17) = 0;
    // 0x80801F64: sw          $t8, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r24;
    // 0x80801F68: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801F6C: jal         0x80088368
    // 0x80801F70: swc1        $f4, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f4.u32l;
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x80801F70: swc1        $f4, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f4.u32l;
    after_2:
    // 0x80801F74: blez        $v0, L_80801FA8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80801F78: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80801FA8;
    }
    // 0x80801F78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80801F7C:
    // 0x80801F7C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80801F80: jal         0x80800098
    // 0x80801F84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80800098_chtrashcangame(rdram, ctx);
        goto after_3;
    // 0x80801F84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80801F88: addiu       $a0, $s0, 0xC3
    ctx->r4 = ADD32(ctx->r16, 0XC3);
    // 0x80801F8C: jal         0x800D2748
    // 0x80801F90: addiu       $a1, $s0, 0x5F
    ctx->r5 = ADD32(ctx->r16, 0X5F);
    func_800D2748(rdram, ctx);
        goto after_4;
    // 0x80801F90: addiu       $a1, $s0, 0x5F
    ctx->r5 = ADD32(ctx->r16, 0X5F);
    after_4:
    // 0x80801F94: jal         0x80088368
    // 0x80801F98: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x80801F98: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_5:
    // 0x80801F9C: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80801FA0: bnel        $at, $zero, L_80801F7C
    if (ctx->r1 != 0) {
        // 0x80801FA4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80801F7C;
    }
    goto skip_0;
    // 0x80801FA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
L_80801FA8:
    // 0x80801FA8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801FAC: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x80801FB0: jal         0x800CE8D8
    // 0x80801FB4: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    func_800CE8D8(rdram, ctx);
        goto after_6;
    // 0x80801FB4: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    after_6:
    // 0x80801FB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801FBC: jal         0x800CE88C
    // 0x80801FC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800CE88C(rdram, ctx);
        goto after_7;
    // 0x80801FC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80801FC4: jal         0x8008A098
    // 0x80801FC8: nop

    _subaddiemulti_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x80801FC8: nop

    after_8:
    // 0x80801FCC: jal         0x800FDC28
    // 0x80801FD0: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_800FDC28(rdram, ctx);
        goto after_9;
    // 0x80801FD0: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_9:
    // 0x80801FD4: b           L_808020B8
    // 0x80801FD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_808020B8;
    // 0x80801FD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80801FDC:
    // 0x80801FDC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801FE0: jal         0x80800014
    // 0x80801FE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800014_chtrashcangame(rdram, ctx);
        goto after_10;
    // 0x80801FE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x80801FE8: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
    // 0x80801FEC: sw          $zero, 0x20($s1)
    MEM_W(0X20, ctx->r17) = 0;
    // 0x80801FF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801FF4: jal         0x800AA20C
    // 0x80801FF8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800AA20C(rdram, ctx);
        goto after_11;
    // 0x80801FF8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_11:
    // 0x80801FFC: jal         0x800FC660
    // 0x80802000: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_800FC660(rdram, ctx);
        goto after_12;
    // 0x80802000: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_12:
    // 0x80802004: jal         0x80088368
    // 0x80802008: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_13;
    // 0x80802008: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    after_13:
    // 0x8080200C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80802010: bne         $at, $zero, L_80802068
    if (ctx->r1 != 0) {
        // 0x80802014: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80802068;
    }
    // 0x80802014: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80802018:
    // 0x80802018: jal         0x80800014
    // 0x8080201C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80800014_chtrashcangame(rdram, ctx);
        goto after_14;
    // 0x8080201C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_14:
    // 0x80802020: lw          $v1, 0x1C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X1C);
    // 0x80802024: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80802028: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8080202C: beq         $at, $zero, L_80802040
    if (ctx->r1 == 0) {
        // 0x80802030: nop
    
            goto L_80802040;
    }
    // 0x80802030: nop

    // 0x80802034: sw          $v0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r2;
    // 0x80802038: b           L_8080204C
    // 0x8080203C: sw          $s0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r16;
        goto L_8080204C;
    // 0x8080203C: sw          $s0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r16;
L_80802040:
    // 0x80802040: bne         $v0, $v1, L_8080204C
    if (ctx->r2 != ctx->r3) {
        // 0x80802044: nop
    
            goto L_8080204C;
    }
    // 0x80802044: nop

    // 0x80802048: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8080204C:
    // 0x8080204C: jal         0x800AA20C
    // 0x80802050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800AA20C(rdram, ctx);
        goto after_15;
    // 0x80802050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80802054: jal         0x80088368
    // 0x80802058: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_16;
    // 0x80802058: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_16:
    // 0x8080205C: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80802060: bnel        $at, $zero, L_80802018
    if (ctx->r1 != 0) {
        // 0x80802064: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80802018;
    }
    goto skip_1;
    // 0x80802064: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_1:
L_80802068:
    // 0x80802068: beq         $s2, $zero, L_80802094
    if (ctx->r18 == 0) {
        // 0x8080206C: addiu       $a1, $zero, 0x13DE
        ctx->r5 = ADD32(0, 0X13DE);
            goto L_80802094;
    }
    // 0x8080206C: addiu       $a1, $zero, 0x13DE
    ctx->r5 = ADD32(0, 0X13DE);
    // 0x80802070: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80802074: addiu       $t9, $zero, 0x6A
    ctx->r25 = ADD32(0, 0X6A);
    // 0x80802078: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8080207C: addiu       $a1, $zero, 0x13DF
    ctx->r5 = ADD32(0, 0X13DF);
    // 0x80802080: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80802084: jal         0x8008A208
    // 0x80802088: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_17;
    // 0x80802088: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_17:
    // 0x8080208C: b           L_808020AC
    // 0x80802090: nop

        goto L_808020AC;
    // 0x80802090: nop

L_80802094:
    // 0x80802094: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80802098: addiu       $t0, $zero, 0x6A
    ctx->r8 = ADD32(0, 0X6A);
    // 0x8080209C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x808020A0: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x808020A4: jal         0x8008A208
    // 0x808020A8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_18;
    // 0x808020A8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_18:
L_808020AC:
    // 0x808020AC: jal         0x8008A088
    // 0x808020B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _subaddiemulti_entrypoint_0(rdram, ctx);
        goto after_19;
    // 0x808020B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_19:
    // 0x808020B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_808020B8:
    // 0x808020B8: jal         0x80101FDC
    // 0x808020BC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80101FDC(rdram, ctx);
        goto after_20;
    // 0x808020BC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_20:
    // 0x808020C0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808020C4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808020C8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x808020CC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x808020D0: jr          $ra
    // 0x808020D4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808020D4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80022ECC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022ECC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80022ED0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80022ED4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80022ED8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80022EDC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80022EE0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80022EE4: lbu         $t8, 0x37($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X37);
    // 0x80022EE8: lw          $t7, 0x60($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X60);
    // 0x80022EEC: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80022EF0: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80022EF4: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80022EF8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80022EFC: lb          $t1, 0x12($t0)
    ctx->r9 = MEM_B(ctx->r8, 0X12);
    // 0x80022F00: addiu       $t2, $t1, -0x40
    ctx->r10 = ADD32(ctx->r9, -0X40);
    // 0x80022F04: sb          $t2, 0x29($sp)
    MEM_B(0X29, ctx->r29) = ctx->r10;
    // 0x80022F08: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80022F0C: lbu         $t5, 0x37($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X37);
    // 0x80022F10: lw          $t4, 0x60($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X60);
    // 0x80022F14: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x80022F18: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80022F1C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80022F20: addu        $t8, $t4, $t6
    ctx->r24 = ADD32(ctx->r12, ctx->r14);
    // 0x80022F24: lwc1        $f4, 0x14($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X14);
    // 0x80022F28: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x80022F2C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80022F30: lw          $t9, 0x64($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X64);
    // 0x80022F34: beq         $t9, $zero, L_80022FEC
    if (ctx->r25 == 0) {
        // 0x80022F38: sw          $t9, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r25;
            goto L_80022FEC;
    }
    // 0x80022F38: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_80022F3C:
    // 0x80022F3C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80022F40: lbu         $t2, 0x37($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X37);
    // 0x80022F44: lbu         $t1, 0x35($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X35);
    // 0x80022F48: bne         $t1, $t2, L_80022FDC
    if (ctx->r9 != ctx->r10) {
        // 0x80022F4C: nop
    
            goto L_80022FDC;
    }
    // 0x80022F4C: nop

    // 0x80022F50: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80022F54: lbu         $t4, 0x37($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X37);
    // 0x80022F58: lw          $t5, 0x60($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X60);
    // 0x80022F5C: sll         $t6, $t4, 3
    ctx->r14 = S32(ctx->r12 << 3);
    // 0x80022F60: subu        $t6, $t6, $t4
    ctx->r14 = SUB32(ctx->r14, ctx->r12);
    // 0x80022F64: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80022F68: addu        $t8, $t5, $t6
    ctx->r24 = ADD32(ctx->r13, ctx->r14);
    // 0x80022F6C: lbu         $t7, 0x11($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X11);
    // 0x80022F70: sh          $t7, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r15;
    // 0x80022F74: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80022F78: lh          $a1, 0x2A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2A);
    // 0x80022F7C: jal         0x8002A890
    // 0x80022F80: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_8002A890(rdram, ctx);
        goto after_0;
    // 0x80022F80: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80022F84: lh          $t9, 0x2A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X2A);
    // 0x80022F88: beq         $t9, $zero, L_80022FDC
    if (ctx->r25 == 0) {
        // 0x80022F8C: nop
    
            goto L_80022FDC;
    }
    // 0x80022F8C: nop

    // 0x80022F90: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80022F94: lb          $t5, 0x29($sp)
    ctx->r13 = MEM_B(ctx->r29, 0X29);
    // 0x80022F98: lw          $t2, 0x20($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X20);
    // 0x80022F9C: lbu         $t1, 0x36($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X36);
    // 0x80022FA0: lbu         $t3, 0x14($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X14);
    // 0x80022FA4: subu        $t4, $t1, $t3
    ctx->r12 = SUB32(ctx->r9, ctx->r11);
    // 0x80022FA8: jal         0x80028B74
    // 0x80022FAC: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    func_80028B74(rdram, ctx);
        goto after_1;
    // 0x80022FAC: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    after_1:
    // 0x80022FB0: lui         $at, 0x43DC
    ctx->r1 = S32(0X43DC << 16);
    // 0x80022FB4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80022FB8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80022FBC: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80022FC0: mul.s       $f8, $f20, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x80022FC4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80022FC8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80022FCC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80022FD0: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80022FD4: jal         0x8002A7E0
    // 0x80022FD8: nop

    func_8002A7E0(rdram, ctx);
        goto after_2;
    // 0x80022FD8: nop

    after_2:
L_80022FDC:
    // 0x80022FDC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80022FE0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80022FE4: bne         $t8, $zero, L_80022F3C
    if (ctx->r24 != 0) {
        // 0x80022FE8: sw          $t8, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r24;
            goto L_80022F3C;
    }
    // 0x80022FE8: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
L_80022FEC:
    // 0x80022FEC: b           L_80022FF4
    // 0x80022FF0: nop

        goto L_80022FF4;
    // 0x80022FF0: nop

L_80022FF4:
    // 0x80022FF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80022FF8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80022FFC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80023000: jr          $ra
    // 0x80023004: nop

    return;
    // 0x80023004: nop

;}
RECOMP_FUNC void func_808003AC_chboilerid(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003B0: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808003B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003B8: bne         $a1, $at, L_808003D8
    if (ctx->r5 != ctx->r1) {
        // 0x808003BC: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_808003D8;
    }
    // 0x808003BC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808003C0: jal         0x80100094
    // 0x808003C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808003C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808003C8: jal         0x8008A038
    // 0x808003CC: addiu       $a0, $v0, 0x60
    ctx->r4 = ADD32(ctx->r2, 0X60);
    _subaddielink_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808003CC: addiu       $a0, $v0, 0x60
    ctx->r4 = ADD32(ctx->r2, 0X60);
    after_1:
    // 0x808003D0: b           L_808003DC
    // 0x808003D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003DC;
    // 0x808003D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003D8:
    // 0x808003D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808003DC:
    // 0x808003DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003E4: jr          $ra
    // 0x808003E8: nop

    return;
    // 0x808003E8: nop

;}
RECOMP_FUNC void bsbanshack_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BDC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800BE0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(45, 0XD00) << 16);
    // 0x80800BE4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800BE8: jr          $ra
    // 0x80800BEC: lw          $v0, 0xD00($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(45, 0XD00));
    return;
    // 0x80800BEC: lw          $v0, 0xD00($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(45, 0XD00));
;}
RECOMP_FUNC void vpscroll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808000F8: jal         0x800D8FF8
    // 0x808000FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808000FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800100: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800104: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80800108: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080010C: lwc1        $f4, 0x8($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80800110: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80800114: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800118: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8080011C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800120: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80800124: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80800128: swc1        $f18, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
    // 0x8080012C: lwc1        $f2, 0x0($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80800130: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80800134: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x80800138: nop

    // 0x8080013C: slti        $at, $v1, 0x2001
    ctx->r1 = SIGNED(ctx->r3) < 0X2001 ? 1 : 0;
    // 0x80800140: bne         $at, $zero, L_80800168
    if (ctx->r1 != 0) {
        // 0x80800144: lui         $at, 0x4600
        ctx->r1 = S32(0X4600 << 16);
            goto L_80800168;
    }
    // 0x80800144: lui         $at, 0x4600
    ctx->r1 = S32(0X4600 << 16);
    // 0x80800148: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080014C: nop

    // 0x80800150: sub.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x80800154: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
    // 0x80800158: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8080015C: trunc.w.s   $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800160: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x80800164: nop

L_80800168:
    // 0x80800168: lw          $t9, 0xC($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XC);
    // 0x8080016C: sh          $v1, 0x4($a2)
    MEM_H(0X4, ctx->r6) = ctx->r3;
    // 0x80800170: lw          $t8, 0x1C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1C);
    // 0x80800174: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800178: blez        $t9, L_808001B4
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8080017C: addu        $a3, $a0, $t8
        ctx->r7 = ADD32(ctx->r4, ctx->r24);
            goto L_808001B4;
    }
    // 0x8080017C: addu        $a3, $a0, $t8
    ctx->r7 = ADD32(ctx->r4, ctx->r24);
    // 0x80800180: addiu       $v1, $a2, 0x10
    ctx->r3 = ADD32(ctx->r6, 0X10);
    // 0x80800184: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80800188: lh          $t0, 0x0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X0);
L_8080018C:
    // 0x8080018C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80800190: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80800194: multu       $t0, $a0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800198: mflo        $t1
    ctx->r9 = lo;
    // 0x8080019C: addu        $t2, $a3, $t1
    ctx->r10 = ADD32(ctx->r7, ctx->r9);
    // 0x808001A0: sb          $a1, 0x3($t2)
    MEM_B(0X3, ctx->r10) = ctx->r5;
    // 0x808001A4: lw          $t3, 0xC($a2)
    ctx->r11 = MEM_W(ctx->r6, 0XC);
    // 0x808001A8: slt         $at, $v0, $t3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x808001AC: bnel        $at, $zero, L_8080018C
    if (ctx->r1 != 0) {
        // 0x808001B0: lh          $t0, 0x0($v1)
        ctx->r8 = MEM_H(ctx->r3, 0X0);
            goto L_8080018C;
    }
    goto skip_0;
    // 0x808001B0: lh          $t0, 0x0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X0);
    skip_0:
L_808001B4:
    // 0x808001B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001BC: jr          $ra
    // 0x808001C0: nop

    return;
    // 0x808001C0: nop

;}
RECOMP_FUNC void _basub_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800851E0: syscall     154
    recomp_syscall_handler(rdram, ctx, 0x800851E0);
    return;
    // 0x800851E4: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
